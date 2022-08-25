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
*  MediaPlayerPlayList.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player play list module
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#include "MMI_include.h"
#include "MMI_features.h"

#if (defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__))

#undef PERFORMANCE_MONITOR				
/*#define MEDPLY_DB_MEMORY_MONITOR*/

#include "GlobalResDef.h"
#include "stdlib.h"
//#include "time.h"
#include "app_str.h"
#include "gui_data_types.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Conversions.h"
//#include "CommonScreens.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "sqlite3.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "meta_tag_api.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "ImeGprot.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "fs_type.h"
#include "fs_func.h"
#include "l1audio.h"
#include "sqlite3ex.h"
#include "fs_errcode.h"
#include "app_datetime.h"
#include "sqlite3kal.h"
#include "stdio.h"
#include "stack_config.h"
#include "AlertScreen.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "gui_typedef.h"
#include "GlobalConstants.h"
#include "CommonScreensResDef.h"
#include "CustDataRes.h"
#include "wgui_categories_list.h"
#include "drm_def.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_rp_app_uiframework_def.h"
#include "mmi_rp_app_filemanager_def.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "NotificationGprot.h"
#include "mdi_video.h"

//#include "gpioinc.h"
#include "PhoneSetupGprots.h"
//#include "SimDetectionGprot.h"

#include "FileMgrSrvGProt.h"
//#include "FileMgr.h"
#include "FileMgrType.h"
//#include "FileMgrGProt.h"
//#include "FilemgrResDef.h"

#include "ProfilesSrvGprot.h"
#include "Drm_gprot.h"
#include "usbsrvgprot.h"
#include "BootupSrvGprot.h"
#include "NwUsabSrvGprot.h"
/* cui prot */
#include "FilemgrCuiGprot.h"
#include "menucuigprot.h"
#include "fseditorcuigprot.h"
#include "inlinecuigprot.h"

#ifdef __MMI_RMGR__
#include "RightsMgrGprot.h"
#endif

#ifdef __OTG_ENABLE__
#include "usb_host_ms_if.h"
#endif 

#include "mmi_rp_app_medply_def.h"
//#include "MediaPlayerResDef.h"
#include "MediaPlayerProt.h"
#include "MediaPlayerGProt.h"
//#include "MediaPlayerSettings.h"
#include "MediaPlayerPlayList.h"
#include "MediaPlayerEnumDef.h"

#ifdef __MMI_BACKGROUND_CALL__
#include "UcmSrvGprot.h"
#endif
/*
**  table for all supports format.
*/

const mmi_medply_support_format_struct support_format_table[] = 
{
    /* format, type, build cache, image id, extended name */
    {MEDPLY_FORMAT_NONE, L"\0"},
#ifdef DAF_DECODE    
    {MEDPLY_FORMAT_DAF, L"MP3"},
#ifdef MUSICAM_DECODE
    {MEDPLY_FORMAT_MUSICAN, L"MP2"},
#endif
#endif
#ifdef __RM_DEC_SUPPORT__
    {MEDPLY_FORMAT_RA, L"RA"},
#endif /* __RM_DEC_SUPPORT__ */ 
    {MEDPLY_FORMAT_AMR, L"AMR"},
#ifdef AAC_DECODE
    {MEDPLY_FORMAT_AAC, L"AAC"},
#endif
#ifdef AMRWB_DECODE
    {MEDPLY_FORMAT_AWB, L"AWB"},
#endif
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    {MEDPLY_FORMAT_ODF, L"ODF"},
#endif
    {MEDPLY_FORMAT_WAV, L"WAV"},
    {MEDPLY_FORMAT_MID, L"MID"},
    {MEDPLY_FORMAT_MIDI, L"MIDI"},
    {MEDPLY_FORMAT_IMY, L"IMY"},
#ifdef AIFF_DECODE
    {MEDPLY_FORMAT_AIFF, L"AIFF"},
    {MEDPLY_FORMAT_AIF, L"AIF"},
    {MEDPLY_FORMAT_AIFC, L"AIFC"},
#endif
#ifdef AU_DECODE
    {MEDPLY_FORMAT_AU, L"AU"},
#endif
#ifdef SND_DECODE
    {MEDPLY_FORMAT_SND, L"SND"},
#endif
#ifdef YAMAHA_MA3
    {MEDPLY_FORMAT_MMF, L"MMF"},
#endif
#ifdef WMA_DECODE
    {MEDPLY_FORMAT_WMA, L"WMA"},
#endif
#ifdef M4A_DECODE
    {MEDPLY_FORMAT_M4A, L"M4A"},
#endif
#if (!defined(MP4_DECODE) && defined(__MMI_PURE_AUDIO__)) 
    {MEDPLY_FORMAT_3GPA, L"3GP"},
    {MEDPLY_FORMAT_MP4A, L"MP4"},
    {MEDPLY_FORMAT_3G2A, L"3G2"},
#endif
#ifdef __MMI_PURE_AUDIO__
    {MEDPLY_FORMAT_3GA, L"3GA"},
#endif
#ifdef __APE_DECODE__
    {MEDPLY_FORMAT_APE,  L"APE"},
#endif
#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    {MEDPLY_FORMAT_OGG, L"OGG"},
#endif
/*video*/
#ifdef MP4_DECODE
    {MEDPLY_FORMAT_3GP, L"3GP"},
    {MEDPLY_FORMAT_MP4, L"MP4"},
    {MEDPLY_FORMAT_MPG, L"MPG"},
    {MEDPLY_FORMAT_3G2, L"3G2"},
#endif
#ifdef __RM_DEC_SUPPORT__
    {MEDPLY_FORMAT_RV, L"RV"},
    {MEDPLY_FORMAT_RM, L"RM"},
    {MEDPLY_FORMAT_RMVB, L"RMVB"},
#endif  /* __RM_DEC_SUPPORT__ */ 
#ifdef MJPG_DECODE
    {MEDPLY_FORMAT_AVI, L"AVI"},
#endif
#ifdef __FLV_FILE_FORMAT_SUPPORT__
    {MEDPLY_FORMAT_FLV, L"FLV"},
    {MEDPLY_FORMAT_F4V, L"F4V"},
#endif
#ifdef __MMI_VIDEO_STREAM__
    {MEDPLY_FORMAT_RTSP, L"RTSP"},
    {MEDPLY_FORMAT_SDP, L"SDP"},
    {MEDPLY_FORMAT_RAM, L"RAM"},
#endif
    {MEDPLY_FORMAT_TOTAL, L"\0"}
};


const mmi_medply_fileinfo_struct media_file_info_table[] = 
{
    /* format, type, build cache, image id, extended name */
    {MEDPLY_FORMAT_NONE, MEDPLY_TYPE_NONE, 0, IMG_ID_MEDPLY_FILE_UNKNOWN_ICON, L"\0"},
/* audio */
    {MEDPLY_FORMAT_DAF, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MP3"},
    {MEDPLY_FORMAT_MUSICAN, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MP2"},
    {MEDPLY_FORMAT_RA, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"RA"},
    {MEDPLY_FORMAT_AMR, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AMR"},
    {MEDPLY_FORMAT_AAC, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AAC"},
    {MEDPLY_FORMAT_AWB, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AWB"},
    {MEDPLY_FORMAT_BSAC, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"BSAC"},
    {MEDPLY_FORMAT_ODF, MEDPLY_TYPE_AUDIO, 1, 
#ifdef __DRM_V02__
    IMG_ID_MEDPLY_FILE_AUD_ICON,
#else
    IMG_ID_MEDPLY_FILE_UNKNOWN_ICON,
#endif
    L"ODF"},
    {MEDPLY_FORMAT_WAV, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"WAV"},
    {MEDPLY_FORMAT_MID, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MID"},
    {MEDPLY_FORMAT_MIDI, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MIDI"},
    {MEDPLY_FORMAT_IMY, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"IMY"},
    {MEDPLY_FORMAT_AIFF, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AIFF"},
    {MEDPLY_FORMAT_AIF, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AIF"},
    {MEDPLY_FORMAT_AIFC, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AIFC"},
    {MEDPLY_FORMAT_AU, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AU"},
    {MEDPLY_FORMAT_SND, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"SND"},
    {MEDPLY_FORMAT_MMF, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MMF"},
    {MEDPLY_FORMAT_WMA, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"WMA"},
    {MEDPLY_FORMAT_M4A, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"M4A"},
    {MEDPLY_FORMAT_3GPA, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"3GP"},
    {MEDPLY_FORMAT_MP4A, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MP4"},
    {MEDPLY_FORMAT_3G2A, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"3G2"},
    {MEDPLY_FORMAT_3GA, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"3GA"},
    {MEDPLY_FORMAT_APE, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"APE"},
    {MEDPLY_FORMAT_OGG, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"OGG"},
/* video */
    {MEDPLY_FORMAT_3GP, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"3GP"},
    {MEDPLY_FORMAT_MP4, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MP4"},
    {MEDPLY_FORMAT_MPG, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MPG"},
    {MEDPLY_FORMAT_3G2, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"3G2"},
    {MEDPLY_FORMAT_RV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"RV"},
    {MEDPLY_FORMAT_RM, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"RM"},
    {MEDPLY_FORMAT_RMVB, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"RMVB"},
    {MEDPLY_FORMAT_AVI, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"AVI"},
    {MEDPLY_FORMAT_FLV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"FLV"},
    {MEDPLY_FORMAT_F4V, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"F4V"},
/* streaming */
    {MEDPLY_FORMAT_RTSP, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"RTSP"},
    {MEDPLY_FORMAT_SDP, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"SDP"},
    {MEDPLY_FORMAT_RAM, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"RAM"},
    {MEDPLY_FORMAT_NONE, MEDPLY_TYPE_TOTAL, 0, IMG_ID_MEDPLY_FILE_UNKNOWN_ICON, L"\0"}
};

/**************************Inline CUI struct***********************************/
/* details edit */
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_title = 
{
    STR_ID_MEDPLY_PLST_DETAILS_TITLE
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_artist = 
{
    STR_ID_MEDPLY_PLST_DETAILS_ARTIST
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_album = 
{
    STR_ID_MEDPLY_PLST_DETAILS_ALBUM
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_genre = 
{
    STR_ID_MEDPLY_PLST_DETAILS_GENRE
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_author = 
{
    STR_ID_MEDPLY_PLST_DETAILS_AUTHOR
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_description = 
{
    STR_ID_MEDPLY_PLST_DETAILS_DESCRIPTION
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_tracknum = 
{
    STR_ID_MEDPLY_PLST_DETAILS_TRACK_NUM
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_year = 
{
    STR_ID_MEDPLY_PLST_DETAILS_YEAR
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_rate = 
{
    STR_ID_MEDPLY_PLST_DETAILS_USER_RATING
};


static const cui_inline_set_item_struct mmi_medply_plstui_inline_details_item[] = 
{
    {MEDPLY_DETAILS_META_TITLE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_title},
    {MEDPLY_DETAILS_META_TITLE_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_ARTIST_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_artist},
    {MEDPLY_DETAILS_META_ARTIST_DISPLAY,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_ALBUM_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_album},
    {MEDPLY_DETAILS_META_ALBUM_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_GENRE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_genre},
    {MEDPLY_DETAILS_META_GENRE_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_AUTHOR_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_author},
    {MEDPLY_DETAILS_META_AUTHOR_DISPLAY,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_DESCRIPTION_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_description},
    {MEDPLY_DETAILS_META_DESCRIPTION_DISPLAY,   CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_TRACK_NUM_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_tracknum},
    {MEDPLY_DETAILS_META_TRACK_NUM_DISPLAY,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_YEAR_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_year},
    {MEDPLY_DETAILS_META_YEAR_DISPLAY,          CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_USER_RATING_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_rate},
    {MEDPLY_DETAILS_META_USER_RATING_DISPLAY,   CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
};


static cui_inline_item_softkey_struct mmi_medply_plstui_inline_details_softkey = 
{
    {
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},                     /*MMI_LEFT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},                      /*MMI_RIGHT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}                      /*MMI_CENTER_SOFTKEY*/
    }
};


static const cui_inline_struct mmi_medply_plstui_inline_details_screen = 
{
    MEDPLY_DETAILS_META_INLINE_ITEM_NUM,
    STR_GLOBAL_DETAILS,
    0,
    CUI_INLINE_SCREEN_LOOP, 
    &mmi_medply_plstui_inline_details_softkey, 
    mmi_medply_plstui_inline_details_item 
};

/* search */
static const cui_inline_set_item_struct mmi_medply_plstui_inline_search_item[] = 
{
    {MEDPLY_SEARCH_TITLE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_title},
    {MEDPLY_SEARCH_TITLE_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_SEARCH_ARTIST_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_artist},
    {MEDPLY_SEARCH_ARTIST_DISPLAY,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_SEARCH_ALBUM_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_album},
    {MEDPLY_SEARCH_ALBUM_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_SEARCH_GENRE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_plst_inline_caption_genre},
    {MEDPLY_SEARCH_GENRE_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
};

static cui_inline_item_softkey_struct mmi_medply_plstui_inline_search_softkey = 
{
    {
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},                     /*MMI_LEFT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},                      /*MMI_RIGHT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}                      /*MMI_CENTER_SOFTKEY*/
    }
};

static const cui_inline_struct mmi_medply_plstui_inline_search_screen = 
{
    MEDPLY_SEARCH_INLINE_ITEM_NUM,
    STR_GLOBAL_SEARCH,
    0,
    CUI_INLINE_SCREEN_LOOP, 
    &mmi_medply_plstui_inline_search_softkey, 
    mmi_medply_plstui_inline_search_item 
};

/*
**	global context
*/
static mmi_medply_plst_cntx_struct plst_cntx;
static mmi_medply_plst_cntx_struct* plst_cntx_p = &plst_cntx;
static U16 playlistui_fwd_option_menu_id = 0;
static U16 g_medply_plst_is_current_list = 0;
extern MMI_ID g_gid_medply;

#ifdef PERFORMANCE_MONITOR
U32 __time1 = 0; 
U32 __time2 = 0;
S32 __ret = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_get_current_time
 * DESCRIPTION	
 *  get current ticks and turn it to ms.
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_medply_get_current_time(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint32 ticks = 0;
    kal_uint32 time = 0;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_get_time(&ticks);
    time = kal_ticks_to_milli_secs(ticks);
    return time;
}
#endif	/* PERFORMANCE_MONITOR */

#ifdef MEDPLY_DB_MEMORY_MONITOR
/*
**	memory trace. 
*/
#define MEM_TRC_ALLOCATE(addr, size, line)	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, addr, size, line)
#define MEM_TRC_FREE(addr, line)			MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_ASM_FREE, addr, line)
#else
#define MEM_TRC_ALLOCATE(addr, size, line)	
#define MEM_TRC_FREE(addr, line)			
#endif	/* MEDPLY_DB_MEMORY_MONITOR */


/* 
**	error code transform
*/
#define META_ERROR(x)			(x*(-1) + (-220))
#define DB_ERROR(x)				__db_set_err_code(x,__LINE__)
#define DB_CHK(x) do{\
    if (__db_check_error(x))\
    {\
        return 0;\
    }\
}while(0)


/*****************************************************************************
 * FUNCTION
 *  __db_check_error
 * DESCRIPTION	
 *  internal function for check sqlite return value.
 * PARAMETERS
 *  x		[IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL __db_check_error(int x)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ret = (x != SQLITE_OK && (x & 0xFF) < 100);
    if (ret) 
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_CHK_ERROR, x);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  __db_set_err_code
 * DESCRIPTION	
 *  internal function to transform sqlite error code.
 * PARAMETERS
 *  x		[IN]
 *  line	[IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 __db_set_err_code(S32 in_err, S32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (in_err != SQLITE_OK && in_err < SQLITE_ROW)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_DB_ERROR, in_err, line);
        return ((-1) * (in_err + 240));
    }
    else if (in_err == SQLITE_ROW)
    {
        return MEDPLY_PLST_GOT_DATA;
    }
    else
    {
        return MEDPLY_PLST_NO_ERROR;
    }
}


extern kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length);

/*
**  static function prototype.
*/
static U16 mmi_medply_util_is_target_support_format(const UI_string_type ext);
static void mmi_medply_util_get_filename(UI_string_type out_filename_no_ext, const UI_string_type in_path);
static void mmi_medply_util_hide_ext_name(CHAR *file_name);
static void mmi_medply_plstui_addto_entry(U16 initiate_scr_id);
static void mmi_medply_plst_clear_context_variables(void);
static void mmi_medply_plstdb_generate_entry_layer(void);
static S32 mmi_medply_plstdb_generate_init(U16 initiate_grp_id, U16 initiate_scr_id, U8 run_type);
static void mmi_medply_plstdb_generate_start(void);
static void mmi_medply_plstdb_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf);
static void mmi_medply_plstdb_generate_internal(void);
static void mmi_medply_plstdb_generate_deinit(void);
static void mmi_medply_plstdb_generate_wait_screen_entry(void);
static void mmi_medply_plstdb_generate_error_hdlr(void);
static S32 mmi_medply_util_create_file_dir(UI_string_type filepath);
static void mmi_medply_util_entry_wait_scr(void);
static MMI_BOOL mmi_medply_util_check_free_space(CHAR drv_letter, U32 req_size);
static U8 mmi_medply_plst_util_drv_letter(void);
static void mmi_medply_plst_util_get_drv_status(void);
static void mmi_medply_search_entry_scr(void);
static mmi_ret mmi_medply_plstui_proc(mmi_event_struct *evt);
static void mmi_medply_plstui_listmgr_opt_config(cui_menu_event_struct *menu_evt);
static void mmi_medply_plstui_playlist_opt_config(cui_menu_event_struct *menu_evt);
static void mmi_medply_plstui_listmgr_opt_load(void);
static void mmi_medply_plstui_listmgr_opt_create_part_1(void);
static void mmi_medply_plstui_listmgr_opt_delete_part_1(void);
static void mmi_medply_plstui_listmgr_opt_rename_part_1(void);
static void mmi_medply_plstui_common_opt_initiate_play(void);
static void mmi_medply_plstui_common_opt_details(void);
static void mmi_medply_plstui_allmedia_opt_update_part_1(void);
static void mmi_medply_plstui_allmedia_opt_add_part1(void);
static void mmi_medply_plstui_playlist_opt_add(void);
static void mmi_medply_plstui_playlist_opt_remove_part_1(void);
static void mmi_medply_plstui_playlist_opt_clear_part_1(void);
static void mmi_medply_plstui_playlist_opt_organize(void);
static void mmi_medply_plstui_common_opt_addto(void);
static void mmi_medply_plstui_common_opt_intro(void);
static void mmi_medply_plstui_allmedia_opt_search(void);
static void mmi_medply_plst_post_event_to_main(mmi_medply_event_enum event_id, void *user_data);
static void mmi_medlpy_plstui_allmedia_opt_add_selector_handle(cui_file_selector_result_event_struct *file_select);
static void mmi_medply_plstui_multiselect_opt_add_marked(void);
static void mmi_medply_plstui_multiselect_opt_mark_all(void);
static void mmi_medply_plstui_multiselect_opt_unmark_all(void);
static void mmi_medply_plstui_multiselect_opt_config(cui_menu_event_struct *menu_evt);
static void mmi_medply_details_edit_function(void);
static void mmi_medply_details_entry_set_rate_scr(void);
static void mmi_medply_details_edit_exit(void);
static void mmi_medply_details_edit_resaved(void);
static void mmi_medply_details_edit_save(void);
static void mmi_medply_details_save_confirm(void);
static mmi_ret mmi_medply_plstdb_generate_del_layer_callback(mmi_event_struct* evt);
static void mmi_medply_plstui_organize_save(void);
static void mmi_medply_plstui_organize_resaved(void);
static void mmi_medply_search_edit_function(void);
static void mmi_medply_search_action(void);
static void mmi_medply_search_reset(void);
static void mmi_medply_search_exit(void);
static void mmi_medply_search_result_opt_preview(void);
static void mmi_medply_search_result_opt_config(cui_menu_event_struct *menu_evt);
static void mmi_medply_plstui_bmk_opt_save_ram_part1(void);
static void mmi_medply_plstui_bmk_opt_preview(void);
static void mmi_medply_plstui_bmk_opt_delete_part1(void);
static void mmi_medply_plstui_bmk_opt_clear_part1(void);
static void mmi_medply_plstui_bmk_opt_new_part1(void);
static void mmi_medply_plstui_bmk_opt_config(cui_menu_event_struct *menu_evt);
static MMI_BOOL mmi_medply_plst_is_scrn_present(MMI_ID parent_id, MMI_ID scrn_id);
#ifdef __MMI_FTE_SUPPORT__ 
static void mmi_medply_plstui_tap_callback(mmi_tap_type_enum tap_type,S32 index);
static void mmi_medply_plstui_listmgr_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_string_convert
 * DESCRIPTION	
 *  convert string which got from meta parser.
 * PARAMETERS
 *  in_string       [IN]
 *  in_string_size  [IN]
 *  out_string      [OUT]
 *  out_buff_size   [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_util_string_convert(CHAR* in_string, S32 in_string_size, CHAR* out_string, S32 out_buff_size, U8 meta_encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 out_string_len = 0;
    CHAR meta_data_buff[MEDPLY_MAX_PATH_SIZE];
    mmi_chset_enum encoding_type = MMI_CHSET_UCS2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(meta_data_buff, 0, sizeof(meta_data_buff));

    kal_mem_cpy(meta_data_buff, in_string, in_string_size);

    if (meta_encoding != META_TAG_TEXT_ENCODING_UCS2)
    {
        encoding_type = mmi_chset_guess(
							meta_data_buff,
							in_string_size,
							0,
							CHSET_GUESS_ALL);
									
       	out_string_len = mmi_chset_convert(
				            encoding_type,
				            MMI_CHSET_UCS2,
				            (char*)meta_data_buff,
				            (char*)out_string,
				            out_buff_size);

        return out_string_len;
    }
    else
    {
        mmi_ucs2ncpy(out_string, meta_data_buff, (in_string_size>>1));
        return in_string_size;
    }
}

/*
**	code
*/
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_create_list_cache
 * DESCRIPTION	
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plstui_create_list_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
	S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_CREATE_LIST_CACHE);
	for (i = 0; i < MEDPLY_MAX_LIST_CACHE; i++)
    {
		if (plst_cntx_p->ui_cntx.list_stack[i] == NULL)
        {
			break;
        }
    }

    //check range
	MMI_ASSERT(i < MEDPLY_MAX_LIST_CACHE);
    
	plst_cntx_p->ui_cntx.list_stack[i] = 
        kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_plstui_list_cache_struct));
    if (plst_cntx_p->ui_cntx.list_stack[i] == NULL)
    {
		ret = MEDPLY_PLST_ERR_META_NO_MEMORY;
    }
    else
    {
		MEM_TRC_ALLOCATE(plst_cntx_p->ui_cntx.list_stack[i], sizeof(mmi_medply_plstui_list_cache_struct), __LINE__);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_CREATE_LIST_CACHE_OK, i);
        memset(plst_cntx_p->ui_cntx.list_stack[i], 0, sizeof(mmi_medply_plstui_list_cache_struct));
        ret = i;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_destory_list_cache
 * DESCRIPTION	
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plstui_destory_list_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
	S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DESTORY_LIST_CACHE);
	for (i = (MEDPLY_MAX_LIST_CACHE - 1); i > 0; i--)
    {
		if (plst_cntx_p->ui_cntx.list_stack[i] != NULL)
        {
			break;
        }
    }
    
    //check range
	MMI_ASSERT(i < MEDPLY_MAX_LIST_CACHE);
    
	kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.list_stack[i]);
    MEM_TRC_FREE(plst_cntx_p->ui_cntx.list_stack[i], __LINE__);
    plst_cntx_p->ui_cntx.list_stack[i] = NULL;
    ret = i;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_get_curr_list_cache
 * DESCRIPTION	
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_medply_plstui_list_cache_struct*
 *****************************************************************************/
static mmi_medply_plstui_list_cache_struct* mmi_medply_plstui_get_curr_list_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = MEDPLY_MAX_LIST_CACHE; i > 0; i--)
    {
		if (plst_cntx_p->ui_cntx.list_stack[i - 1] != NULL)
        {
			return plst_cntx_p->ui_cntx.list_stack[i - 1];
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_get_curr_list_cache_index
 * DESCRIPTION	
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_medply_plstui_get_curr_list_cache_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = MEDPLY_MAX_LIST_CACHE; i > 0; i--)
    {
		if (plst_cntx_p->ui_cntx.list_stack[i - 1] != NULL)
        {
			break;
        }
    }

    return ((i > 0) ? (i - 1) : 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_clear_list_cache
 * DESCRIPTION	
 *  clear appointed list screen's cache
 * PARAMETERS
 *  list_scr_id		[IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_plstui_clear_list_cache(U16 list_scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL clear_successful = MMI_FALSE;
    U8 i = 0;
    U8 m = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = MEDPLY_MAX_LIST_CACHE; i > 0; i--)
    {
		if (plst_cntx_p->ui_cntx.list_stack[i - 1] != NULL)
        {
			if (plst_cntx_p->ui_cntx.list_stack[i - 1]->list_scr_id == list_scr_id)
            {
				plst_cntx_p->ui_cntx.list_stack[i - 1]->hint_cache.hint_buff[0] = 0;
                plst_cntx_p->ui_cntx.list_stack[i - 1]->hint_cache.hint_idx = -1;
                plst_cntx_p->ui_cntx.list_stack[i - 1]->head = -1;
                plst_cntx_p->ui_cntx.list_stack[i - 1]->tail = -1;

                for (m = 0; m < MMI_MEDPLY_LIST_BUFF_SIZE; m++)
                {
                	plst_cntx_p->ui_cntx.list_stack[i - 1]->db_cache[m].format = 0;
					plst_cntx_p->ui_cntx.list_stack[i - 1]->db_cache[m].media_id = 0;
                    plst_cntx_p->ui_cntx.list_stack[i - 1]->db_cache[m].reserved = 0;
                    plst_cntx_p->ui_cntx.list_stack[i - 1]->db_cache[m].title[0] = 0;
                }
                clear_successful = MMI_TRUE;
            }
        }
    }

    return clear_successful;
}


#define ____BITSET
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bitset_check_match
 * DESCRIPTION	
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bitset_check_match(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_medply_db_bitset_struct new_bitset;
    S32 bitset_total = plst_cntx_p->list_cntx.playing.bitset.size * 8;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plst_cntx_p->list_cntx.playing.total > bitset_total)
    {
		/* bitset is not match with list now. */
        new_bitset.size = plst_cntx_p->list_cntx.playing.bitset.size + MMI_MEDPLY_BITSET_BLOCK_SIZE;
        new_bitset.data = kal_adm_alloc(g_medply.adm_id_p, new_bitset.size);
        MMI_ASSERT(new_bitset.data != NULL);
        MEM_TRC_ALLOCATE(new_bitset.data, new_bitset.size, __LINE__);

		memset(new_bitset.data, 0, new_bitset.size);
        /* copy old bitset. */
        memcpy(new_bitset.data, 
        		plst_cntx_p->list_cntx.playing.bitset.data, 
        		plst_cntx_p->list_cntx.playing.bitset.size);

        /* free old bitset. */
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->list_cntx.playing.bitset.data);
		MEM_TRC_FREE(plst_cntx_p->list_cntx.playing.bitset.data, __LINE__);
        plst_cntx_p->list_cntx.playing.bitset.data = NULL;
        /* update bitset context. */
        plst_cntx_p->list_cntx.playing.bitset.size = new_bitset.size;
        plst_cntx_p->list_cntx.playing.bitset.data = new_bitset.data;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bitset_clear
 * DESCRIPTION	
 *  clear bitset as given index.
 * PARAMETERS
 *  idx			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bitset_clear(U32 idx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_medply_bitset_check_match();

    ClrBitSet(idx, plst_cntx_p->list_cntx.playing.bitset.data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bitset_set
 * DESCRIPTION	
 *  
 * PARAMETERS
 *  idx			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bitset_set(U32 idx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_medply_bitset_check_match();

    SetBitSet(idx, plst_cntx_p->list_cntx.playing.bitset.data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bitset_check
 * DESCRIPTION	
 *  
 * PARAMETERS
 *  idx			[IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_bitset_check(U32 idx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_medply_bitset_check_match();
    return IsBitSetOn(idx, plst_cntx_p->list_cntx.playing.bitset.data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bitset_exchange
 * DESCRIPTION
 *  
 * PARAMETERS
 *  old_index		[IN]
 *	new_index		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bitset_exchange(U16 old_index, U16 new_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL old_set = MMI_FALSE;
    MMI_BOOL new_set = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (mmi_medply_bitset_check(old_index))
    {
        mmi_medply_bitset_clear(old_index);
        old_set = MMI_TRUE;
    }

    if (mmi_medply_bitset_check(new_index))
    {
        mmi_medply_bitset_clear(new_index);
        new_set = MMI_TRUE;
    }

    if (old_set)
    {
        mmi_medply_bitset_set(new_index);
    }

    if (new_set)
    {
        mmi_medply_bitset_set(old_index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bitset_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx				[IN]
 *	total			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bitset_sort(U16 idx, U16 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 move_times = (total - 1 - idx);
	U16 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < move_times; i++)
    {
		mmi_medply_bitset_exchange((idx + i), (idx + i + 1));
    }
}


#define ____EDITOR_CODE


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_editor_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_editor_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id = 0;
    U32 input_type = 0;
    S32 limit = 0;
    MMI_ID parent_id = GRP_ID_INVALID;
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_EDITOR_ENTRY);

    parent_id = plst_cntx_p->ui_cntx.editor_cntx.parent_id;
    limit = plst_cntx_p->ui_cntx.editor_cntx.limit;
    title_id = plst_cntx_p->ui_cntx.editor_cntx.editor_title_id;

    if (parent_id != GRP_ID_INVALID)
    {
        mmi_frm_group_create(parent_id, SCR_ID_MEDPLY_PLST_EDITOR, mmi_medply_plstui_proc, (void*)NULL); 
    }
    else
    {
        mmi_frm_group_create(g_gid_medply, SCR_ID_MEDPLY_PLST_EDITOR, mmi_medply_plstui_proc, (void*)NULL); 
    }
    mmi_frm_group_enter(SCR_ID_MEDPLY_PLST_EDITOR, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    switch (plst_cntx_p->ui_cntx.editor_cntx.editor_type)
    {
        case MMI_MEDPLY_EDITOR_NEW:
        case MMI_MEDPLY_EDITOR_SAVE_RAM:
        case MMI_MEDPLY_EDITOR_RENAME:
        {
            cui_gid = cui_filename_editor_create(SCR_ID_MEDPLY_PLST_EDITOR, 
                plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
                sizeof(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer), 
                limit, NULL, NULL);
            if (cui_gid != GRP_ID_INVALID)
            {
                cui_filename_editor_set_parent_data(cui_gid, plst_cntx_p->ui_cntx.editor_cntx.editor_type);
                cui_filename_editor_set_title(cui_gid, title_id, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
                cui_filename_editor_run(cui_gid);
            }
            else
            {   
                mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
            }
            return;
        }
        case MMI_MEDPLY_EDITOR_EDIT_URL:
        case MMI_MEDPLY_EDITOR_NEW_URL:
            input_type = IMM_INPUT_TYPE_URL;
            break;
        case MMI_MEDPLY_EDITOR_EDIT_META_TEXT:
            input_type = IMM_INPUT_TYPE_SENTENCE;
            break;
        case MMI_MEDPLY_EDITOR_EDIT_META_NUMERIC:
            input_type = IMM_INPUT_TYPE_NUMERIC;
            break;
        default:
            return;
            
    }
    
    cui_gid = cui_fseditor_create(SCR_ID_MEDPLY_PLST_EDITOR);
    if (cui_gid != GRP_ID_INVALID)
    {
        cui_fseditor_set_text(cui_gid,
            plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
            sizeof(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer),
            limit);
        cui_fseditor_set_title(cui_gid,title_id,GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
        cui_fseditor_set_input_method(cui_gid,input_type,NULL,0);
        cui_fseditor_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_editor_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  editor_type			[IN]
 *	limit				[IN]
 *	editor_title_id		[IN]
 *	original_string_p	[IN]
 *	done_func			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void	mmi_medply_editor_create(
                        U16 parent_id,
						U8 editor_type,
					    U16 limit, 
					    U16 editor_title_id,
					    UI_string_type original_string_p,
					    UI_string_type initial_value,
					    FuncPtr done_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_EDITOR_CREATE, editor_type);

    memset(&(plst_cntx_p->ui_cntx.editor_cntx), 0, sizeof(mmi_medply_editor_cntx_struct));
    
    plst_cntx_p->ui_cntx.editor_cntx.parent_id = parent_id;
    plst_cntx_p->ui_cntx.editor_cntx.editor_type = editor_type;
    plst_cntx_p->ui_cntx.editor_cntx.limit = limit;
    plst_cntx_p->ui_cntx.editor_cntx.editor_title_id = editor_title_id;
    plst_cntx_p->ui_cntx.editor_cntx.original_string_p = original_string_p;
    plst_cntx_p->ui_cntx.editor_cntx.done_func = done_func;
	if (initial_value != NULL)
    {
		mmi_ucs2ncpy((CHAR *)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
            		 (const CHAR *)initial_value, MMI_MEDPLY_MAX_EDITOR_LEN);
    }
    mmi_medply_editor_entry_scr();
}


#define SEND_AND_USE

/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_option_send
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plst_option_send(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menu_id = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    menu_id = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR *) list_p->add_ons.opt_data.curr_hilite_path);
    if (menu_id > 0)
    {
        playlistui_fwd_option_menu_id = menu_id;
        cui_menu_set_new_list_parent_id(menu_evt->sender_id, playlistui_fwd_option_menu_id);
    }
    else
    {
        cui_menu_close(menu_evt->sender_id);
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_option_use
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plst_option_use(cui_menu_event_struct* menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menu_id = 0;
	mmi_medply_plstui_list_cache_struct *list_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    menu_id = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR *)list_p->add_ons.opt_data.curr_hilite_path);
	if (menu_id > 0)
	{
	    playlistui_fwd_option_menu_id = menu_id;
        cui_menu_set_new_list_parent_id(menu_evt->sender_id, playlistui_fwd_option_menu_id);
	}
	else
	{
        cui_menu_close(menu_evt->sender_id);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_fwd_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_fwd_select(U16 current_menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_medply_plstui_list_cache_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    srv_fmgr_types_launch_option((WCHAR *)list_p->add_ons.opt_data.curr_hilite_path, current_menu_item_id);
    
}


#define __NVRAM
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_save_last_list_id
 * DESCRIPTION
 *  save last list id to NVRAM.
 * PARAMETERS
 *  list_id			[IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_save_last_list(U32 list_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
 
	U64 last_list_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_id > 0)
    {
    	last_list_id = list_id;
    }
    else
    {
		last_list_id = 0;
    }
    if (0 > WriteValue(NVRAM_MEDPLY_LAST_PLAYLIST_ID, &last_list_id, DS_DOUBLE, &error))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_last_list_id
 * DESCRIPTION
 *  get last list id from NVRAM.
 * PARAMETERS
 *  out_list_id		[OUT]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_get_last_list(U32 *out_list_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;  
    U64 last_list_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ReadValue(NVRAM_MEDPLY_LAST_PLAYLIST_ID, &last_list_id, DS_DOUBLE, &error) < 0)
    {
    	*out_list_id = 0;
        return MMI_FALSE;
    }
    else
    {
		*out_list_id = (U32)((last_list_id<<32)>>32);
        return MMI_TRUE; 
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_save_last_list_index
 * DESCRIPTION
 *  save the index of last list to NVRAM.
 * PARAMETERS
 *  index		[IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_save_last_list_index(S32 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
	U16 last_list_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index > 0)
    {
    	last_list_index = (U16)index;
    }
    else
    {
		last_list_index = 0;
    }
    if (0 > WriteValue(NVRAM_MEDPLY_LAST_PLAYLIST_INDEX, &last_list_index, DS_SHORT, &error))
    {
		return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_last_list_index
 * DESCRIPTION
 *  get the index of last list from NVRAM.
 * PARAMETERS
 *  out_index		[OUT]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_get_last_list_index(S32 *out_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 last_list_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 > ReadValue(NVRAM_MEDPLY_LAST_PLAYLIST_INDEX, &last_list_index, DS_SHORT, &error))
    {
		*out_index = 0;
        return MMI_FALSE;
    }
    else
    {
		*out_index = last_list_index;
        return MMI_TRUE;
    } 
}


#define __META_PARSER
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_filename_as_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_path             [IN]        
 *	out_title			[OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_plst_get_filename_as_title
            (const UI_string_type in_path, UI_string_type out_title, U16 title_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    CHAR * filename_ptr = NULL;
    CHAR * ext = NULL;
    FS_HANDLE fd = -1;
    FS_DOSDirEntry file_info;
    UI_character_type title_buff[MEDPLY_MAX_PATH_LEN];
    MMI_BOOL is_short = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_path == NULL)
    {
		*out_title = 0;
    }
    else
    {
		filename_ptr = mmi_ucs2rchr((const CHAR *)in_path, (U16)(L'\\'));
        if (filename_ptr == NULL)
	    {
	        *out_title = 0;
	    }
	    else
	    {
            /* check short name. */
			fd = FS_FindFirst(in_path, 0, 0, &file_info, title_buff, MEDPLY_MAX_PATH_LEN * ENCODING_LENGTH);
			if (fd < 0)
	        {
	            mmi_ucs2ncpy((CHAR *)out_title, (const CHAR *)(filename_ptr + 2), title_len - 1);
				/* cut off extension name. */
				ext = mmi_ucs2rchr((const CHAR *)out_title, (U16)L'.');
				if (ext != NULL)
				{
					*(ext + 1) = 0;
					*ext = 0;
				}
	        }
	        else
	        {
				is_short = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;
                FS_FindClose(fd);
                if (is_short)
		        {
			        mmi_chset_mixed_text_to_ucs2_str(
			            (U8*)title_buff,
			            (MEDPLY_MAX_FILE_LEN - 1) * ENCODING_LENGTH,
			            (U8*)(filename_ptr + 2),
			            PhnsetGetDefEncodingType());
		        }
		        else
		        {
		        	mmi_ucs2ncpy((CHAR *)title_buff, (const CHAR *)(filename_ptr + 2), MEDPLY_MAX_FILE_LEN - 1);
		    	}
		        /*if (is_short)
		        {
		            fd = FS_Open(in_path, FS_READ_ONLY);
                    if (fd >= FS_NO_ERROR)
                    {
                        FS_MakeFileName(fd, FS_LONGNAME_ATTR, title_buff, MEDPLY_MAX_PATH_LEN);
					    FS_Close(fd);
                    }
                }*/
				/* cut off extension name. */
				ext = mmi_ucs2rchr((const CHAR *)title_buff, (U16)L'.');
				if (ext != NULL)
				{
					*(ext + 1) = 0;
					*ext = 0;
    			}

				len = mmi_ucs2strlen((const CHAR *)title_buff);
                if (len > (title_len - 1))
                {
                    mmi_ucs2ncpy((CHAR*)out_title, (const CHAR*)title_buff, title_len - 1);
                }
                else
                {
                    mmi_ucs2ncpy((CHAR*)out_title, (const CHAR*)title_buff, title_len - 1);
                }
	        }
	    }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_artwork_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_path             [IN]        
 *	out_data			[OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_get_artwork_details
            (const UI_string_type in_path, mmi_medply_details_artwork_struct *out_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    meta_tag_img_info_struct* image_info_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	meta_parser_buffer = kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
	if (meta_parser_buffer == NULL)
	{
	    ret = MEDPLY_PLST_ERR_NO_MEMORY;
	}
    else
    {
		MEM_TRC_ALLOCATE(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);

        meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);
	
	    if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
	    {
	        /* meta parser error. */
            kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
            MEM_TRC_FREE(meta_parser_buffer, __LINE__);
	        meta_parser_buffer = NULL;
	        ret = META_ERROR(meta_parser_ret);
	    }
	    else
        {
		    do
		    {
		        meta_return_value = meta_parse_file(meta_parser_hdlr, in_path);

		        if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
			    {
			        /* meta parser error. */
	                ret = META_ERROR(meta_return_value);
                    break;
			    }

			    meta_return_value = meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p);
			    if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
				{
				    /* meta parser error. */
	                ret = META_ERROR(meta_return_value);
				}
                else
                {
    				out_data->mime_type = image_info_p->mime_type;
    				out_data->size = image_info_p->data_size;
                }
		    } while (0);
            meta_parser_release(meta_parser_hdlr);
            kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
            MEM_TRC_FREE(meta_parser_buffer, __LINE__);
	        meta_parser_buffer = NULL;
		}            
    }
    return ret;
}          
		

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_meta_from_file
 * DESCRIPTION
 *  get meta data from meta parser.
 * PARAMETERS
 *  file_path       [IN]        
 *	details			[OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plst_get_meta_from_file(
 			UI_string_type file_path, mmi_medply_db_media_meta_struct* details)
{   
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    meta_tag_music_info_struct* music_info_p = NULL;
    meta_tag_sync_lyc_info_struct* lrc_info_p = NULL;
    meta_tag_img_info_struct* image_info_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef PERFORMANCE_MONITOR
    __time1 = mmi_medply_get_current_time();
#endif
/* allocate memory for meta parser. */
    meta_parser_buffer = (PU8)kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
    if (meta_parser_buffer == NULL)
    {
        /* get memory failed! */
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
    else
    {
    	MEM_TRC_ALLOCATE(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);

	/* create meta parser. */    
	    meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

	    if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)	// fill meta data if create meta parser failed.
	    {
            details->artist[0] = 0;
		    details->author[0] = 0;
		    details->album[0] = 0;
            mmi_medply_plst_get_filename_as_title(file_path, details->title, MMI_MEDPLY_MAX_TITLE_LEN);
		    details->copyrights[0] = 0;
		    details->genre[0] = 0;
		    details->description[0] = 0;
		    details->year = -1;
		    details->track_num = -1;
		    details->artwork_type = -1;
		    details->lyrics_type = -1;
            
	        ret = META_ERROR(meta_parser_ret);
	    }
	    else
        {
		/* parse file. */
		    meta_return_value = meta_parse_file_with_encoding_type(
		    							meta_parser_hdlr,
		    							(kal_uint16*)file_path,
		    							META_TAG_TEXT_ENCODING_UNKNOWN);

		    if (meta_return_value != 0)	// fill meta data if meta parser pasre file failed.
			{
		    	details->artist[0] = 0;
		    	details->author[0] = 0;
		    	details->album[0] = 0;
                mmi_medply_plst_get_filename_as_title(file_path, details->title, MMI_MEDPLY_MAX_TITLE_LEN);
		    	details->copyrights[0] = 0;
		    	details->genre[0] = 0;
		    	details->description[0] = 0;
		    	details->year = -1;
		        details->track_num = -1;
		    	details->artwork_type = -1;
		    	details->lyrics_type = -1;
		        
			    ret = META_ERROR(meta_return_value);
		    }
		    else
		    {              
		    	ret = 0;
				meta_return_value = meta_get_music_info(meta_parser_hdlr, &music_info_p);	/* get "music info" struct. */
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    if (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size > 0)
		            {
		                mmi_medply_util_string_convert(
                                (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data,
                                music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size,
                                (CHAR*)details->artist,
                                (S32)(MMI_MEDPLY_MAX_ARTISRT_LEN * ENCODING_LENGTH),
								music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_encoding);
		            }
                    else
		            {
					    details->artist[0] = 0;
		            }
		        
		            if (music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size > 0)
		            {
		                mmi_medply_util_string_convert(
                                (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data,
                                music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size,
                                (CHAR*)details->author,
                                (S32)(MMI_MEDPLY_MAX_AUTHOR_LEN * ENCODING_LENGTH),
                                music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_encoding);
		            }
		            else
		            {
					    details->author[0] = 0;
		            }

		            if (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size > 0)
		            {
		                mmi_medply_util_string_convert(
                                (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data,
                                music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size,
                                (CHAR*)details->album,
                                (S32)(MMI_MEDPLY_MAX_ALBUM_LEN * ENCODING_LENGTH),
                                music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_encoding);
		            }
		            else
		            {
					    details->album[0] = 0;
		            }

		            if (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size > 0)
		            {
		                mmi_medply_util_string_convert(
                                (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_TITLE].data,
                                music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size,
                                (CHAR*)details->title,
                                (S32)(MMI_MEDPLY_MAX_TITLE_LEN * ENCODING_LENGTH),
                                music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_encoding);
		            }
		            else
		            {
    	                mmi_medply_plst_get_filename_as_title(file_path, details->title, MMI_MEDPLY_MAX_TITLE_LEN);
		            }

		            if (music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size > 0)
		            {
		                mmi_medply_util_string_convert(
                                (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data,
                                music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size,
                                (CHAR*)details->copyrights,
                                (S32)(MMI_MEDPLY_MAX_COPYRIGHTS_LEN * ENCODING_LENGTH),
                                music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_encoding);
		            }
		            else
		            {
					    details->copyrights[0] = 0;
		            }

		            if (music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size > 0)
		            {
		                mmi_medply_util_string_convert(
                                (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_GENRE].data,
                                music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size,
                                (CHAR*)details->genre,
                                (S32)(MMI_MEDPLY_MAX_GENRE_LEN * ENCODING_LENGTH),
                                music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_encoding);
		            }
		            else
		            {
					    details->genre[0] = 0;
		            }

		            if (music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size > 0)
		            {
		                mmi_medply_util_string_convert(
                                (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data,
                                music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size,
                                (CHAR*)details->description,
                                (S32)(MMI_MEDPLY_MAX_DESCRIPTION_LEN * ENCODING_LENGTH),
                                music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_encoding);
		            }
		            else
		            {
					    details->description[0] = 0;
		            }
		            if (music_info_p->year <= 9999 && music_info_p->year >= 0)
                    {      
		                details->year = music_info_p->year;
                    }
                    else
                    {
                        details->year = -1;
                    }

                    if (music_info_p->track_number > 0 && music_info_p->track_number <= 9999)
		            {
		                details->track_num = music_info_p->track_number;
                    }
                    else
                    {
                        details->track_num = -1;
                    }
                }
                else
                {
                    details->artist[0] = 0;
		    	    details->author[0] = 0;
		    	    details->album[0] = 0;
                    mmi_medply_plst_get_filename_as_title(file_path, details->title, MMI_MEDPLY_MAX_TITLE_LEN);
		    	    details->copyrights[0] = 0;
		    	    details->genre[0] = 0;
		    	    details->description[0] = 0;
		    	    details->year = -1;
		            details->track_num = -1;
                }
                
			    /* get artwork type. get "artwork info" struct.*/
                meta_return_value = meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p);
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    if (image_info_p->data_size > 0)
		            {    
		        	    details->artwork_type = (CHAR)image_info_p->mime_type;
				    }
		            else
		            {
					    details->artwork_type = -1;
		            }
                }
                else
                {
                    details->artwork_type = -1;
                }
				
			    /* get lyrics type.get "lyrics info" struct.  */
                meta_return_value = meta_get_sync_lyrics_info(meta_parser_hdlr, &lrc_info_p);
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    if (lrc_info_p->data_size > 0)
		            {
		        	    details->lyrics_type = (CHAR)lrc_info_p->lyc_type;
		            }
		            else
		            {
					    details->lyrics_type = -1;
		            }
                }
                else
                {
                    details->lyrics_type = -1;
                }
		    }
		    meta_parser_release(meta_parser_hdlr);
        }
	    kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
	    MEM_TRC_FREE(meta_parser_buffer, __LINE__);
	    meta_parser_buffer = NULL;
    }
#ifdef PERFORMANCE_MONITOR
    __time2 = mmi_medply_get_current_time();
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_PARSE_META_COST, (__time2 - __time1));
#endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_base_info
 * DESCRIPTION
 *  get base info of a media file.
 * PARAMETERS
 *  file_path       	[IN]        
 *	base_info			[OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_get_base_info(UI_string_type file_path, 
										mmi_medply_db_media_base_struct* base_info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
	UI_character_type tmp_path[MEDPLY_MAX_PATH_LEN];
    U32 path_crc = 0;
    U32 len = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef PERFORMANCE_MONITOR
    __time1 = mmi_medply_get_current_time();
#endif
	mmi_ucs2ncpy((CHAR*)base_info->path, (const CHAR*)file_path, MEDPLY_MAX_PATH_LEN - 1);
    
/* get local driver letter. */    
	for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
    {
		if (plst_cntx_p->drv_list[i].is_active)
        {
			if (plst_cntx_p->drv_list[i].drv_letter == (CHAR)(base_info->path[0]))
            {
				base_info->local = i;
                base_info->serial_num = plst_cntx_p->drv_list[i].serial_number;
                break;
            }
        }
    }
    
/* get file format. */    
    base_info->format = mmi_medply_util_is_target_support_format(file_path);
	
/* calculate hash */
	mmi_ucs2ncpy((CHAR*)tmp_path, (const CHAR*)file_path, MEDPLY_MAX_PATH_LEN - 1);
    mmi_ucs2lwr((CHAR*)tmp_path);

    /* calculate CRC */
	len = mmi_ucs2strlen((const CHAR*)tmp_path);
	len <<= 1;
	path_crc = med_crc_calculate((kal_uint8* const)tmp_path, len);
        
    base_info->path_hash = path_crc;
#ifdef PERFORMANCE_MONITOR
    __time2 = mmi_medply_get_current_time();
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_PARSE_BASE_COST, (__time2 - __time1));
#endif
}


#define __SQLITE3_WARP_
/*
**  warp all sqlite3 API used by media player. 
**  add trace/log and enhance error handling.
*/
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_enable
* DESCRIPTION
*  warp "sqlite3_enter_instance()"
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
static void mmi_medply_db_sqlite3_enable(S32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(plst_cntx_p->db_cntx.sqlite_buf != NULL);
    MMI_ASSERT(plst_cntx_p->db_cntx.enable_count == MMI_FALSE);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_ENABLE, line);
    sqlite3_enter_instance(&(plst_cntx_p->db_cntx.sqlite_instance));
    plst_cntx_p->db_cntx.enable_count = MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_disable
* DESCRIPTION
*  warp "sqlite3_exit_instance()"
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
static void mmi_medply_db_sqlite3_disable(S32 line)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(plst_cntx_p->db_cntx.sqlite_buf != NULL);
    MMI_ASSERT(plst_cntx_p->db_cntx.enable_count == MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_DISABLE, line);
    sqlite3_exit_instance(&(plst_cntx_p->db_cntx.sqlite_instance));
    plst_cntx_p->db_cntx.enable_count = MMI_FALSE;
}
#define DB_ENABLE       mmi_medply_db_sqlite3_enable(__LINE__)
#define DB_DISABLE      mmi_medply_db_sqlite3_disable(__LINE__)


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_init_instance
* DESCRIPTION
*  warp "sqlite3_init_instance()"
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
static void mmi_medply_db_sqlite3_init_instance(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_INIT_INSTANCE);
    MMI_ASSERT(g_medply.adm_id_p != NULL);
    plst_cntx_p->db_cntx.sqlite_buf = kal_adm_alloc(g_medply.adm_id_p, MEDPLY_PLST_DB_APP_MEM_SIZE);
    MMI_ASSERT(plst_cntx_p->db_cntx.sqlite_buf);
	MEM_TRC_ALLOCATE(plst_cntx_p->db_cntx.sqlite_buf, MEDPLY_PLST_DB_APP_MEM_SIZE, __LINE__);
    
    sqlite3_init_instance(&(plst_cntx_p->db_cntx.sqlite_instance), plst_cntx_p->db_cntx.sqlite_buf, MEDPLY_PLST_DB_APP_MEM_SIZE, 0);
    /* set instance initialized flag. */
    plst_cntx_p->db_cntx.instance_initialized = MMI_TRUE;
    plst_cntx_p->db_cntx.enable_count = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_free_instance
* DESCRIPTION
*  warp "sqlite3_free_instance()"
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
static void mmi_medply_db_sqlite3_free_instance(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_FREE_INSTANCE);
	MMI_ASSERT(plst_cntx_p->db_cntx.instance_initialized == MMI_TRUE);

    sqlite3_free_instance(&(plst_cntx_p->db_cntx.sqlite_instance));
    kal_adm_free(g_medply.adm_id_p, plst_cntx_p->db_cntx.sqlite_buf);
    MEM_TRC_FREE(plst_cntx_p->db_cntx.sqlite_buf, __LINE__);
    plst_cntx_p->db_cntx.sqlite_buf = NULL;
    plst_cntx_p->db_cntx.instance_initialized = MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_free_memory
* DESCRIPTION
*  warp "sqlite3_release_memory()"
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
static void mmi_medply_db_sqlite3_free_memory(S32 line)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U64 before = 0;
    U64 after = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	before = sqlite3_memory_used();
    sqlite3_release_memory(MEDPLY_PLST_DB_APP_MEM_SIZE);
	after = sqlite3_memory_used();
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_RELEASE_MEM, before, after, line);
}
#define DB_MEM_RELEASE		mmi_medply_db_sqlite3_free_memory(__LINE__)


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_exec
* DESCRIPTION
*  wrap sqlite3_exec().
* PARAMETERS
*  command      [IN]    SQL command
*  callback     [?]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_sqlite3_exec(const CHAR* command, sqlite3_callback callback, S32 line)
{ 
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    CHAR* error_msg = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_EXECUTE, command, line);
    
    ret = sqlite3_exec(plst_cntx_p->db_cntx.db, command, callback, 0, &error_msg);
    if (ret != SQLITE_OK)
    {
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_EXECUTE_FAIL, error_msg);
        sqlite3_free(error_msg);
    }
    return DB_ERROR(ret);
}
#define DB_EXECUTE(x, y) 	mmi_medply_db_sqlite3_exec(x, y, __LINE__)

#define DB_BEGIN_TRANSACTION	\
do{\
	if(plst_cntx_p->db_cntx.in_transaction == MMI_FALSE)\
	{\
    	DB_EXECUTE("BEGIN TRANSACTION", NULL);\
		plst_cntx_p->db_cntx.in_transaction = MMI_TRUE;\
	}\
	else \
    {\
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_TRANSACTION_BEGIN);\
    	MMI_ASSERT(0);\
   	}\
}while(0)

#define DB_END_TRANSACTION	\
do{\
	if(plst_cntx_p->db_cntx.in_transaction == MMI_TRUE)\
    {\
    	DB_EXECUTE("END TRANSACTION", NULL);\
    	plst_cntx_p->db_cntx.in_transaction = MMI_FALSE;\
   	}\
	else \
    {\
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_TRANSACTION_END);\
    	MMI_ASSERT(0);\
   	}\
}while(0)

#define DB_COMMIT_TRANSACTION	\
do{\
	if(plst_cntx_p->db_cntx.in_transaction == MMI_TRUE)\
    {\
    	DB_EXECUTE("COMMIT TRANSACTION", NULL);\
    	plst_cntx_p->db_cntx.in_transaction = MMI_FALSE;\
	}\
    else \
    {\
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_TRANSACTION_COMMIT);\
    	MMI_ASSERT(0);\
   	}\
}while(0)

#define DB_ROLLBACK_TRANSACTION	\
do{\
	if(plst_cntx_p->db_cntx.in_transaction == MMI_TRUE)\
    {\
    	DB_EXECUTE("ROLLBACK TRANSACTION", NULL);\
    	plst_cntx_p->db_cntx.in_transaction = MMI_FALSE;\
	}\
    else \
    {\
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_TRANSACTION_ROLLBACK);\
    	MMI_ASSERT(0);\
   	}\
}while(0)


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_prepare
* DESCRIPTION
*  wrap sqlite3_prepare().
* PARAMETERS
*  command      [IN]    SQL command
*  stmt         [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_sqlite3_prepare(CHAR* command, sqlite3_stmt** stmt, S32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_PREPARE, command, line);
    ret = sqlite3_prepare_v2(plst_cntx_p->db_cntx.db, command, -1, stmt, NULL);
    return DB_ERROR(ret); 
}
#define DB_PREPARE(x, y)    mmi_medply_db_sqlite3_prepare(x, y, __LINE__)


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_open
* DESCRIPTION
*  wrap sqlite3_open16().
* PARAMETERS
*  path           [IN] 
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_sqlite3_open(UI_string_type path)
{ 
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_OPEN);
    /* open db. */
    ret = sqlite3_open16(path, &(plst_cntx_p->db_cntx.db));
    if (ret == SQLITE_OK)
    {
        plst_cntx_p->db_cntx.db_opend = MMI_TRUE;
    }
    return DB_ERROR(ret);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_close
* DESCRIPTION
*  wrap sqlite3_close().
* PARAMETERS
*  void
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_sqlite3_close(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_CLOSE);

    ret = sqlite3_close(plst_cntx_p->db_cntx.db);

    if  (ret == SQLITE_OK)
    {
        plst_cntx_p->db_cntx.db_opend = MMI_FALSE;
    }
    return DB_ERROR(ret);   
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_step
* DESCRIPTION
*  wrap sqlite3_step().
* PARAMETERS
*  stmt_p       [?]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_sqlite3_step(sqlite3_stmt* stmt_p, S32 line)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_STEP, line);
    ret = sqlite3_step(stmt_p);

    return DB_ERROR(ret);
}

#define DB_STEP(x)		mmi_medply_db_sqlite3_step(x, __LINE__)

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_finalize
* DESCRIPTION
*  wrap sqlite3_finalize().
* PARAMETERS
*  stmt_p       [?]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_sqlite3_finalize(sqlite3_stmt* stmt_p, S32 line)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_FINALIZE, line);
    ret = sqlite3_finalize(stmt_p);
    return DB_ERROR(ret);
}

#define DB_FINALIZE(x)		mmi_medply_db_sqlite3_finalize(x, __LINE__)


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_sqlite3_reset
* DESCRIPTION
*  wrap sqlite3_reset().
* PARAMETERS
*  stmt_p       [?]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_sqlite3_reset(sqlite3_stmt* stmt_p)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_RESET);
    ret = sqlite3_reset(stmt_p);
    return DB_ERROR(ret);
}

#define DB_RESET(x)		mmi_medply_db_sqlite3_reset(x)


/******************************************************************************/
/* db warp code body end. */

#define __DB_OPERATION
/*****************************************************************************
* FUNCTION
*  mmi_mdeply_db_set_pragma
* DESCRIPTION
*  set pragma after db file create.
* PARAMETERS
*  void
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_mdeply_db_set_pragma(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DB_ENABLE;
    ret = DB_EXECUTE("PRAGMA auto_vacuum = 2;", NULL);

	//default page size = 512 bytes.
	ret = DB_EXECUTE("PRAGMA incremental_vacuum(10);", NULL);

	ret = DB_EXECUTE("PRAGMA case_sensitive_like = 0;", NULL);

	ret = DB_EXECUTE("PRAGMA synchronous = 1;", NULL);
    
	// this setting will cost more memory for greater performance.
	//ret = DB_EXECUTE("PRAGMA temp_store = 2;", NULL);
	DB_MEM_RELEASE;
    DB_DISABLE;
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_open
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_open(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!plst_cntx_p->db_cntx.db_opend)
    {
        if (plst_cntx_p->db_cntx.db_path[0] == 0)
        {
            kal_wsprintf(plst_cntx_p->db_cntx.db_path, "%c:\\%w\\%w%w%w",
                		MMI_MEDPLY_DB_DEFAULT_DRV,
            			MMI_MEDPLY_DB_DEFAULT_FOLDER,
            			MMI_MEDPLY_DB_FILENAME,
            			MMI_MEDPLY_DB_VERSION,
            			MMI_MEDPLY_DB_EXTENSION);
        }
		ret = FS_GetAttributes(plst_cntx_p->db_cntx.db_path);
        if (ret < 0)
        {
            return ret;
        }

        if (ret & FS_ATTR_READ_ONLY)
        {
			FS_SetAttributes(plst_cntx_p->db_cntx.db_path, (U8)(ret & ~(FS_ATTR_READ_ONLY)));
        }
        
        DB_ENABLE;
        ret = mmi_medply_db_sqlite3_open(plst_cntx_p->db_cntx.db_path);
        if (ret == 0)
        {
            plst_cntx_p->db_cntx.db_opend = MMI_TRUE;
        }
        DB_DISABLE;
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_create
* DESCRIPTION
*  
* PARAMETERS
*  db_path			[IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_create(UI_string_type db_path)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
	S32 fs_ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* create file. */
	fs_ret = FS_Open(db_path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN | FS_READ_WRITE);
	if (fs_ret >= FS_NO_ERROR)
	{
	    FS_Close(fs_ret);
	    DB_ENABLE;
        ret = mmi_medply_db_sqlite3_open(db_path);
        if (ret == 0)
        {
            plst_cntx_p->db_cntx.db_opend = MMI_TRUE;
        }
        DB_DISABLE;
	}
	else
	{
	    ret = fs_ret;
	}
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_CREATE_DB, ret);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_close
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
static void mmi_medply_db_close(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_CLOSE_DB);
    DB_ENABLE;
    if (plst_cntx_p->db_cntx.db_opend)
    {
        mmi_medply_db_sqlite3_close();
        plst_cntx_p->db_cntx.db_opend = MMI_FALSE;
    }
    DB_DISABLE;
}

#define __DB_UTIL__
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_util_get_current_data_time
* DESCRIPTION
*  generate id for db.
* PARAMETERS
*  new_time         [OUT]
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_db_util_get_current_data_time(mmi_medply_time_record_struct* new_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_date_time(&time);

    new_time->year = time.nYear;
    new_time->month = time.nMonth;
    new_time->day = time.nDay;
    new_time->hour = time.nHour;
    new_time->min = time.nMin;
}


#define __DB_LISTMGR
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_listmgr_query_total
* DESCRIPTION
*  query number of playlist in media library.
* PARAMETERS
*  out_total		[OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_listmgr_query_total(U32 *out_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = DB_PREPARE("SELECT COUNT(*) FROM plst", &stmt);

    if (ret == 0)
    {
        ret = DB_STEP(stmt);
        if (MEDPLY_PLST_GOT_DATA == ret)
        {
            *out_total = sqlite3_column_kal_int32(stmt, 0);
        }
        else
        {
            *out_total = 0;
        }
    }

    if (stmt != NULL)
    {
    	DB_FINALIZE(stmt);
        stmt = NULL;
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_listmgr_query_list_ext
* DESCRIPTION
*  get plst id table
* PARAMETERS
*  table		[OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_listmgr_query_list_ext(mmi_medply_db_tbl_struct* table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
	U32 total = 0;
    U32 count = 0;
    U32 plst_id = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	total = table->size / sizeof(U32);

    ret = DB_PREPARE("SELECT id FROM plst ORDER BY name", &stmt_p);
    if (ret == 0)
    {
        while (count < total && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
            plst_id = sqlite3_column_kal_uint32(stmt_p, 0);
            
            if (plst_id > MMI_MEDPLY_DB_LST_ON_THE_FLY_ID)
            {
                table->data[count + 1] = plst_id;
                count++;
            }
        }
        table->data[total - 1] = MMI_MEDPLY_DB_LST_FAVOURITE_ID;
        if (count == total)
        {
            ret = 0;
        }
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    } 
    
    return ret;
}




/*****************************************************************************
* FUNCTION
*  mmi_medply_db_listmgr_query_listmgr_list
* DESCRIPTION
*  
* PARAMETERS
*  table	[OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_listmgr_query_list(mmi_medply_db_tbl_struct* table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 count = 0;
    U32 total = 0;
    U32 plst_id = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    **  there are 7 default playlists.
    **  need ignore them if filter flag = 0.
    */
	total = table->size / sizeof(U32);
    
    ret = DB_PREPARE("SELECT id FROM plst ORDER BY name", &stmt_p);
    if (ret == 0)
    {
        while (count < total && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
            plst_id = sqlite3_column_kal_uint32(stmt_p, 0);
            
            if (plst_id > MMI_MEDPLY_DB_LST_ON_THE_FLY_ID)
            {
                table->data[count] = plst_id;
                count++;
            }
        }

        table->data[total - 4] = MMI_MEDPLY_DB_LST_FAVOURITE_ID;
        table->data[total - 3] = MMI_MEDPLY_DB_LST_RECENT_ID;
        table->data[total - 2] = MMI_MEDPLY_DB_LST_MOST_PLAYED_ID;
        table->data[total - 1] = MMI_MEDPLY_DB_LST_ON_THE_FLY_ID;

        if (count == total)
        {
            ret = 0;
        }
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_listmgr_query_max_id
* DESCRIPTION
*  
* PARAMETERS
*  max_id			[OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_listmgr_query_max_id(U32 *max_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT MAX(id) FROM plst", &stmt_p);
    if (ret == 0)
    {      
        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            *max_id = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
            *max_id = 0;
        }        
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret; 
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_listmgr_query_exist_by_id
* DESCRIPTION
*  
* PARAMETERS
*  plst_id                   [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_listmgr_query_exist_by_id(U32 plst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT name FROM plst WHERE id = ?", &stmt_p);

    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, plst_id));

        ret = DB_STEP(stmt_p);
    }  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_listmgr_query_exist_by_name
* DESCRIPTION
*
* PARAMETERS
*  in_path           [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_listmgr_query_exist_by_name(UI_string_type in_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT id FROM plst WHERE name = ?", &stmt_p);
      
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 1, in_string));

        ret = DB_STEP(stmt_p);
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
	return ret;
}


#define __DB_PLAYLIST
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_playlist_create
* DESCRIPTION
*  create a playlist with given name.
* PARAMETERS
*  id			[IN]
*  name         [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_create(U32 id, UI_string_type name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("INSERT INTO plst(id, name) values(?, ?)", &stmt_p);
    if (ret == 0)
    {
	    DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));
		if (name != NULL)
		{
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 2, name));
		}
	    ret = DB_STEP(stmt_p);
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;   
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_total
* DESCRIPTION
*  
* PARAMETERS
*  plst_id                   [IN]
*  out_total				 [OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_query_total(U32 plst_id, U32 *out_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT COUNT(*) FROM plst_item WHERE plst_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, plst_id));
        
        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            *out_total = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
            *out_total = 0;
        }        
    }

    if (stmt_p != NULL)
    {
        DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret; 
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_title
* DESCRIPTION
*  
* PARAMETERS
*  plst_id                   [IN]
*  out_string                [OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_query_title(U32 plst_id, UI_string_type out_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT name FROM plst WHERE id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, plst_id));
        
        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            mmi_ucs2ncpy((CHAR*)out_string, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, 0), MEDPLY_MAX_FILE_LEN - 1);
        }
        else
        {
            /* return error code. */
            *out_string = 0;
        }        
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret; 
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_rename
* DESCRIPTION
*  rename a playlist.
* PARAMETERS
*  id                [IN]
*  name              [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_rename(U32 id, UI_string_type new_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = DB_PREPARE("UPDATE plst SET name = ? WHERE id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 1, new_name));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, id));
        
        ret = DB_STEP(stmt_p);
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;   
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_clear
* DESCRIPTION
*  delete a playlist.
* PARAMETERS
*  id                [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_clear(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    ret = DB_PREPARE("DELETE FROM plst_item WHERE plst_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));

        ret = DB_STEP(stmt_p);
    }
    
    if (stmt_p != NULL)
    {
        DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;   
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_clear_sub
* DESCRIPTION
*  delete a playlist.
* PARAMETERS
*  id                [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_clear_sub(U32 id, U64 rowid_begin, U64 rowid_end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    ret = DB_PREPARE("DELETE FROM plst_item WHERE ROWID BETWEEN ? AND ? AND plst_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint64(stmt_p, 1, rowid_begin));
        DB_CHK(sqlite3_bind_kal_uint64(stmt_p, 2, rowid_end));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 3, id)); /*playlist id*/

        ret = DB_STEP(stmt_p);
    }
    
    if (stmt_p != NULL)
    {
        DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;   
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_rowid
* DESCRIPTION
*  delete a playlist.
* PARAMETERS
*  id                [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_query_max_rowid(U64 in_rowid, U32 limit, U64* out_rowid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    ret = DB_PREPARE("SELECT ROWID FROM plst_item WHERE ROWID >= ? LIMIT ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, in_rowid));        
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, limit));

        while (MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
            *out_rowid = sqlite3_column_kal_uint64(stmt_p, 0);
        }
    }
    
    if (stmt_p != NULL)
    {
        DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;   
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_delete
* DESCRIPTION
*  delete a playlist.
* PARAMETERS
*  id                [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_delete(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mmi_medply_db_plst_clear(id);

    if (ret >= 0)
    {
        ret = DB_PREPARE("DELETE FROM plst WHERE id = ?", &stmt_p);
        if (ret == 0)
        {
            DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));
            ret = DB_STEP(stmt_p);
        }

        if (stmt_p != NULL)
        {
            DB_FINALIZE(stmt_p);
            stmt_p = NULL;
        }
    }

    return ret;   
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_list_table
* DESCRIPTION
*  
* PARAMETERS
*  list_id          [IN]
*  table            [OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_plst_query_list_table(U32 list_id, mmi_medply_db_tbl_struct* table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U16 count = 0;
    U32 total = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    total = table->size / sizeof(U32);

    ret = DB_PREPARE("SELECT media_id FROM plst_item WHERE plst_id = ? ORDER BY idx", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, list_id));
        while (count < total && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
            table->data[count] = sqlite3_column_kal_uint32(stmt_p, 0);
            count++;
        }

        if (count == total)
        {
            ret = 0;
        }
    }
    
    if (stmt_p != NULL)
    {
        DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_total
* DESCRIPTION
*  
* PARAMETERS
*  plst_id                   [IN]
*  out_total				 [OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_amf_query_total(U32 *out_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
#if defined(__CHECK_DRIVER_STATUE__)
    U8 i = 0;
#endif
    CHAR cmd[512];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_medply_plst_util_get_drv_status();

	/* compose SQL command. */
	sprintf(cmd, "SELECT COUNT(*) FROM media");

#ifdef __CHECK_DRIVER_STATUE__
    strcat(cmd, " WHERE ");                
    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
    {
		if (plst_cntx_p->drv_list[i].is_active)
        {
            if (i > 0)
            {
                strcat(cmd, " OR ");
            }
            strcat(cmd, "(media.serial_num = ? AND media.local = ?)");
        }
    }
#endif

	ret = DB_PREPARE(cmd, &stmt_p);
    
    if (ret == 0)
    {
    #ifdef __CHECK_DRIVER_STATUE__
	    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
	    {        
			if (plst_cntx_p->drv_list[i].is_active)
	        {
				DB_CHK(sqlite3_bind_kal_uint32(stmt_p, (2 * i + 1), plst_cntx_p->drv_list[i].serial_number));
				DB_CHK(sqlite3_bind_kal_uint32(stmt_p, (2 * i + 2), i));
	        }
	    }
    #endif
        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            *out_total = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
            *out_total = 0;
        }    
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_list_table
* DESCRIPTION
*  
* PARAMETERS
*  list_id			[IN]
*  table			[OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_amf_query_list_table(U32 sorting_type, mmi_medply_db_tbl_struct* table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U16 count = 0;
    U32 total = 0;
    sqlite3_stmt* stmt_p = NULL;
#if defined(__CHECK_DRIVER_STATUE__)
    U8 i = 0;    
#endif
    CHAR cmd[512];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	total = table->size / sizeof(U32);

	/* need update driver state. */
	//mmi_medply_plst_util_get_drv_status();	
	//should not upodate driver info again, in order to sync result with "get total"

	/* compose SQL command. */
    sprintf(cmd, "SELECT media_id FROM media NATURAL LEFT JOIN media_meta");

#ifdef __CHECK_DRIVER_STATUE__
    strcat(cmd, " WHERE ");                
    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
    {
		if (plst_cntx_p->drv_list[i].is_active)
        {
            if (i > 0)
            {
                strcat(cmd, " OR ");
            }
            strcat(cmd, "(media.serial_num = ? AND media.local = ?)");
        }
    }
#endif
#ifdef __DB_SORTING_SUPPORT__
	if (sorting_type & DB_SORT_BY_ARTIST)
	{
		strcat(cmd, " ORDER BY media_meta.artist, media_meta.title");
	}
	else if (sorting_type & DB_SORT_BY_ALBUM)
	{
		strcat(cmd, " ORDER BY media_meta.album, media_meta.title");
	}
    else if (sorting_type & DB_SORT_BY_GENRE)
	{
		strcat(cmd, " ORDER BY media_meta.genre, media_meta.title");
	}
    else	// basic sorting type.
    {
		strcat(cmd, " ORDER BY media_meta.title");		
    }
#endif    
	ret = DB_PREPARE(cmd, &stmt_p);
    
    if (ret == 0)
    {
    #ifdef __CHECK_DRIVER_STATUE__    
	    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
	    {        
			if (plst_cntx_p->drv_list[i].is_active)
	        {
				DB_CHK(sqlite3_bind_kal_uint32(stmt_p, (2 * i + 1), plst_cntx_p->drv_list[i].serial_number));
				DB_CHK(sqlite3_bind_kal_uint32(stmt_p, (2 * i + 2), i));
	        }
	    }
    #endif
        while (count < total && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
            table->data[count] = sqlite3_column_kal_uint32(stmt_p, 0);
            count++;
        }
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_most_played_list
* DESCRIPTION
*  
* PARAMETERS
*  tbl                [OUT]
*  out_total		  [OUT]	
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_query_most_played_list(mmi_medply_db_tbl_struct* tbl, U32 *out_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 count = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*out_total = 0;

    ret = DB_PREPARE("SELECT media_id FROM media_ext WHERE play_count > 0 ORDER BY play_count DESC", &stmt_p);
    if (ret == 0)
    {      
        while (count < MEDPLY_MAX_MOST_PLAYED_ITEM && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
		{
			tbl->data[count] = sqlite3_column_kal_uint32(stmt_p, 0);
			count++;
		}
       	*out_total = count;
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret; 
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_recent_played_list
* DESCRIPTION
*  
* PARAMETERS
*  tbl                [OUT]
*  out_total		  [OUT]	
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_query_recent_played_list(mmi_medply_db_tbl_struct* tbl, U32 *out_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 count = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT media_id FROM plst_item WHERE plst_id = ? ORDER BY idx DESC", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, MMI_MEDPLY_DB_LST_RECENT_ID));
        while (count < MEDPLY_MAX_RECENT_PLAYED_ITEM && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
            tbl->data[count] = sqlite3_column_kal_uint32(stmt_p, 0);
            count++;
        }

        if (count == MEDPLY_MAX_RECENT_PLAYED_ITEM)
        {
            ret = 0;
        }
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    *out_total = count;
    return ret;
}


#define __DB_ITEM           
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_item_check_exist
* DESCRIPTION
*  add a record to current playlist in tail.
* PARAMETERS
*  media_id     [IN]
*  plst_id  [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_item_check_exist(U32 media_id, U32 plst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ret = DB_PREPARE("SELECT media_id, plst_id FROM plst_item WHERE media_id = ? AND plst_id = ?", &stmt_p);

    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));

        ret = DB_STEP(stmt_p);
    }  
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_item_set_index
* DESCRIPTION
*  set index of current item.
* PARAMETERS
*  new_index        [IN]
*  media_id         [IN]
*  playlist_id      [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_item_set_index(U32 new_index, U32 plst_id, U32 media_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("UPDATE plst_item SET idx = ? WHERE plst_id = ? and media_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, new_index));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 3, media_id));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));
        
        ret = DB_STEP(stmt_p);
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret; 
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_item_remove
* DESCRIPTION
*  remove record from current playlist as index.
* PARAMETERS
*  index            [IN]
*  playlist_id      [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_item_remove(U32 media_id, U32 plst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = DB_PREPARE("DELETE FROM plst_item WHERE media_id = ? AND plst_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));
       
        ret = DB_STEP(stmt_p);
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;

}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_item_add
* DESCRIPTION
*  add a record to current playlist in tail.
* PARAMETERS
*  media_id     [IN]
*  playlist_id  [IN]
*  idx          [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_item_add(U32 media_id, U32 plst_id, U32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT idx FROM plst_item WHERE media_id = ? AND plst_id = ?", &stmt_p);

    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));

        ret = DB_STEP(stmt_p);
    }  
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    if (ret == 0)
    {
	    ret = DB_PREPARE("INSERT INTO plst_item(media_id, plst_id, idx) values(?, ?, ?)", &stmt_p);

	    if (ret == 0)
	    {
	        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
	        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));
			DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 3, idx));

	        ret = DB_STEP(stmt_p);
	    }  

        if (stmt_p != NULL)
        {
        	DB_FINALIZE(stmt_p);
            stmt_p = NULL;
        }
    }
    else
    {
		ret = MEDPLY_PLST_ERR_ITEM_EXISTS;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_item_append
* DESCRIPTION
*  add a record to current playlist in tail.
* PARAMETERS
*  media_id     [IN]
*  playlist_id  [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_item_append(U32 media_id, U32 plst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 total = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_db_item_check_exist(media_id, plst_id);
    
    if (ret == 0)
    {
        ret = mmi_medply_db_plst_query_total(plst_id, &total);
        if (ret >= 0)
        {
    	    ret = DB_PREPARE("INSERT INTO plst_item(media_id, plst_id, idx) values(?, ?, ?)", &stmt_p);

    	    if (ret == 0)
    	    {
    	        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
    	        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));
    			DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 3, total));

    	        ret = DB_STEP(stmt_p);
    	    }  

            if (stmt_p != NULL)
            {
            	DB_FINALIZE(stmt_p);
                stmt_p = NULL;
            }
        }
    }
    else
    {
		ret = MEDPLY_PLST_ERR_ITEM_EXISTS;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_item_query_id
* DESCRIPTION
*  query the media id of the current index item in playlist.
* PARAMETERS
*  index        [IN]
*  playlist_id  [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_item_query_id(U32 index, U32 plst_id, U32 *media_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = DB_PREPARE("SELECT media_id FROM plst_item WHERE idx = ? AND plst_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, index));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));

        ret = DB_STEP(stmt_p);
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            *media_id = sqlite3_column_kal_uint32(stmt_p, 0); 
        }
        else
        {
            *media_id = 0;
        }
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_item_query_id_ext
* DESCRIPTION
* 
* PARAMETERS
*  index        [IN]
*  plst_id  	[IN]
*  media_id		[OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_item_query_id_ext(U32 index, U32 plst_id, U32 *media_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 count = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT media_id FROM plst_item WHERE plst_id = ? ORDER BY idx", &stmt_p);
    if (ret == 0)
    {
    	*media_id = 0;
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, plst_id));
        while (MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
        	if (count == index)
            {
            	*media_id = sqlite3_column_kal_uint32(stmt_p, 0);
                break;
            }
            count++;
        }
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_item_query_index
* DESCRIPTION
* 
* PARAMETERS
*  index        [OUT]
*  plst_id  	[IN]
*  media_id		[IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_item_query_index(U32 *index, U32 plst_id, U32 media_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = DB_PREPARE("SELECT idx FROM plst_item WHERE media_id = ? AND plst_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));

        ret = DB_STEP(stmt_p);
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            *index = sqlite3_column_kal_uint32(stmt_p, 0); 
        }
        else
        {
            *index = 0;
        }
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}


#define __DB_MEDIA_
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_query_max_id
* DESCRIPTION
*  
* PARAMETERS
*  max_id                [OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_query_max_id(U32 *max_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = DB_PREPARE("SELECT MAX(media_id) FROM media", &stmt_p);
    if (ret == 0)
    {      
        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            *max_id = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
            *max_id = 0;
        }        
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
    return ret; 
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_query_path
* DESCRIPTION
*  
* PARAMETERS
*  id                [IN]
*  out_path		  	 [OUT]	
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_query_path(U32 id, UI_string_type out_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 len = 0;
	sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ret = DB_PREPARE("SELECT path FROM media WHERE media_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));
        
        ret = DB_STEP(stmt_p); 

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			len = sqlite3_column_bytes16(stmt_p, 0);
            if (len > 0)
            {
	            len >>= 1;
	            if (len < MEDPLY_MAX_PATH_LEN)
	            {
	            	mmi_ucs2ncpy((CHAR*)out_path, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, 0), MEDPLY_MAX_PATH_LEN - 1);
					ret = 0;
	            }
	            else
	            {
					*out_path = 0;
	                ret = MEDPLY_PLST_ERR_OVER_LIMIT;
	            }
            }
            else
			{
				*out_path = 0;
            }
        }
        else
        {
			*out_path = 0;
            ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
        }
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}   
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_query_total
* DESCRIPTION
*  
* PARAMETERS
*  total			[OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_media_query_total(U32 *total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

	ret = DB_PREPARE("SELECT COUNT(*) FROM media", &stmt_p);
    if (ret == 0)
    {
    	ret = DB_STEP(stmt_p);
        if (MEDPLY_PLST_GOT_DATA == ret)
        {
            *total = sqlite3_column_kal_int32(stmt_p, 0);
        }
        else
        {
			*total = 0;
        }
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
    return ret;
}



/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_query_artist
* DESCRIPTION
*  
* PARAMETERS
*  id                [IN]
*  out_artist		  	 [OUT]	
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_query_artist(U32 id, UI_string_type out_artist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 len = 0;
	sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ret = DB_PREPARE("SELECT artist FROM media_meta WHERE media_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));
        
        ret = DB_STEP(stmt_p); 

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			len = sqlite3_column_bytes16(stmt_p, 0);
            if (len > 0)
            {
	            len >>= 1;
	            if (len < MMI_MEDPLY_MAX_ARTISRT_LEN)
	            {
	            	mmi_ucs2ncpy((CHAR*)out_artist, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, 0), MMI_MEDPLY_MAX_ARTISRT_LEN - 1);
					ret = 0;
	            }
	            else
	            {
					*out_artist = 0;
	                ret = MEDPLY_PLST_ERR_OVER_LIMIT;
	            }
            }
            else
			{
				*out_artist = 0;
            }
        }
        else
        {
			*out_artist = 0;
            ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
        }
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}   
    
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_query_list_info
* DESCRIPTION
*  
* PARAMETERS
*  id				[IN]
*  out_data			[OUT]			
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_query_list_info(U32 id, mmi_medply_plstui_db_cache_item_struct* out_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	UI_character_type file_path[MEDPLY_MAX_PATH_LEN];
    sqlite3_stmt* stmt = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ret = DB_PREPARE("SELECT format, path FROM media WHERE media_id = ?", &stmt);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt, 1, id));   
        ret = DB_STEP(stmt);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
        	S32 len = sqlite3_column_bytes16(stmt, 1);

            out_data->media_id = id;
		    out_data->format = sqlite3_column_kal_uint16(stmt, 0);

	        len >>= 1;
			if (len <= MEDPLY_MAX_PATH_LEN)
	        {
	        	mmi_ucs2ncpy((CHAR*)file_path, (const CHAR*)sqlite3_column_kal_wstr(stmt, 1), MEDPLY_MAX_PATH_LEN - 1);
			    mmi_medply_util_extract_filename(out_data->title, file_path);
                mmi_medply_util_hide_ext_name((CHAR*) out_data->title);
				ret = 0;
	        }
            else
	        {
	            ret = MEDPLY_PLST_ERR_OVER_LIMIT;
	        }
        }
        else
        {
			ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
        }
    }
    
    if (stmt != NULL)
	{
		DB_FINALIZE(stmt);
        stmt = NULL;
	}	

    if (ret < 0)
    {
		return ret;
    }
    
    ret = DB_PREPARE("SELECT title FROM media_meta WHERE media_id = ?", &stmt);

	if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt, 1, id));   
        ret = DB_STEP(stmt);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			S32 len = sqlite3_column_bytes16(stmt, 0);
            if (len > 0)
            {
	            len >>= 1;
	            if (len > MEDPLY_MAX_FILE_LEN - 1)
	            {
					mmi_ucs2ncpy((CHAR*)out_data->title, (const CHAR*)sqlite3_column_kal_wstr(stmt, 0), ((MEDPLY_MAX_FILE_LEN - 1)));
					ret = 0;
	            }
	            else
	            {
	        		mmi_ucs2ncpy((CHAR*)out_data->title, (const CHAR*)sqlite3_column_kal_wstr(stmt, 0), MEDPLY_MAX_FILE_LEN - 1);
					ret = 0;
	            }
            }
        }
    }

    if (stmt != NULL)
	{
		DB_FINALIZE(stmt);
        stmt = NULL;
	}

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_query_is_exist_ext
* DESCRIPTION
*
* PARAMETERS
*  hash           [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_media_query_is_exist_ext(U32 hash)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 id = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    ret = DB_PREPARE("SELECT media_id FROM media WHERE path_hash = ?", &stmt_p);
      
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, hash));

        ret = DB_STEP(stmt_p);

         
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            id = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
            id = 0;
        }
    }
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
	return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_query_full_meta
* DESCRIPTION
*  
* PARAMETERS
*  id			[IN]
*  out_data		[OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_query_full_meta(U32 id, mmi_medply_db_media_struct* out_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    ret = DB_PREPARE("SELECT * FROM media WHERE media_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));  

        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
        	do
            {
	        	S32 len = 0;
	            out_data->id = sqlite3_column_kal_uint32(stmt_p, i);
				i++;

				out_data->path_hash = sqlite3_column_kal_uint32(stmt_p, i);
                i++;

	            out_data->local = sqlite3_column_kal_uint8(stmt_p, i);
				i++;

	            out_data->serial_num = sqlite3_column_kal_uint32(stmt_p, i);
				i++;

                len = sqlite3_column_bytes16(stmt_p, i);
                if (len > 0)
                {
	                len >>= 1;
		            if (len > MEDPLY_MAX_PATH_LEN)
		            {
						ret = MEDPLY_PLST_ERR_OVER_LIMIT;
	                    break;
		            }
	                else
	                {
						mmi_ucs2ncpy((CHAR*)out_data->path, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, i), MEDPLY_MAX_PATH_LEN - 1);
						i++;
	                }
                }
                else
                {
					out_data->path[0] = 0;
                    i++;
                }
                
                out_data->format = sqlite3_column_kal_uint16(stmt_p, i);
				i++;
            } while (0);	
        }
        else
        {
			ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
        }
    }

    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}   

    if (ret < 0)
    {
		return ret;
    }
    
	ret = DB_PREPARE("SELECT * FROM media_ext WHERE media_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));  

        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
        	i = 1;
        	do
            {
	    		out_data->play_count = sqlite3_column_kal_uint16(stmt_p, i);
				i++;

                out_data->volume = sqlite3_column_kal_int16(stmt_p, i);
				i++;

                out_data->user_rating = sqlite3_column_kal_uint8(stmt_p, i);	    
				i++;
	            {
	                U32 blob_size = 0;

	                blob_size = sqlite3_column_bytes(stmt_p, i);

	                if (blob_size != sizeof(mmi_medply_time_record_struct))
	                {
						ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                        break;
                    }
	                memcpy(&(out_data->last_played), sqlite3_column_blob(stmt_p, i), sizeof(mmi_medply_time_record_struct));
					i++;
                }

	            {
	                U32 blob_size = 0;

	                blob_size = sqlite3_column_bytes(stmt_p, i);

	                if (blob_size != sizeof(mmi_medply_time_record_struct))
	                {
	                	ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                        break;
                    }
	                memcpy(&(out_data->last_modified), sqlite3_column_blob(stmt_p, i), sizeof(mmi_medply_time_record_struct));
					i++;
                }
                ret = 0;
			} while (0);                   
		}
        else
        {
			ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
        }
    }

    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}   
    
    if (ret < 0)
    {
		return ret;
    } 	   

	ret = DB_PREPARE("SELECT * FROM media_meta WHERE media_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));  

        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
        	i = 1;
        	do
            {
				S32 len = sqlite3_column_bytes16(stmt_p, i);

                len >>= 1;
	            if (len > MMI_MEDPLY_MAX_TITLE_LEN)
	            {
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                    break;
	            }
                else
                {
                	if (len > 0)
                    {
						mmi_ucs2ncpy((CHAR*)out_data->title, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, i), MMI_MEDPLY_MAX_TITLE_LEN - 1);
					}
                    else
                    {
                    	out_data->title[0] = 0;
                    }
                    i++;
                }

                len = sqlite3_column_bytes16(stmt_p, i);
                len >>= 1;
	            if (len > MMI_MEDPLY_MAX_ARTISRT_LEN)
	            {
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                    break;
	            }
                else
                {
                	if (len > 0)
                    {
						mmi_ucs2ncpy((CHAR*)out_data->artist, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, i), MMI_MEDPLY_MAX_ARTISRT_LEN -1 );
					}
                    else
                    {
						out_data->artist[0] = 0;
                    }
                    i++;
                }

                len = sqlite3_column_bytes16(stmt_p, i);
                len >>= 1;
	            if (len > MMI_MEDPLY_MAX_ALBUM_LEN)
	            {
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                    break;
	            }
                else
                {
                	if (len > 0)
                    {
						mmi_ucs2ncpy((CHAR*)out_data->album, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, i), MMI_MEDPLY_MAX_ALBUM_LEN - 1);
					}
                    else
                    {
						out_data->album[0] = 0;
                    }
                    i++;
                }

                len = sqlite3_column_bytes16(stmt_p, i);
                len >>= 1;
	            if (len > MMI_MEDPLY_MAX_GENRE_LEN)
	            {
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                    break;
	            }
                else
                {
                	if (len > 0)
                    {
						mmi_ucs2ncpy((CHAR*)out_data->genre, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, i), MMI_MEDPLY_MAX_GENRE_LEN - 1);
					}
                    else
                    {
						out_data->genre[0] = 0;
                    }
                    i++;
                }

                len = sqlite3_column_bytes16(stmt_p, i);
                len >>= 1;
	            if (len > MMI_MEDPLY_MAX_COPYRIGHTS_LEN)
	            {
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                    break;
	            }
                else
                {
                	if (len > 0)
                    {
						mmi_ucs2ncpy((CHAR*)out_data->copyrights, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, i), MMI_MEDPLY_MAX_COPYRIGHTS_LEN - 1);
					}
                    else
                    {
                    	out_data->copyrights[0] = 0;
                    }
                    i++;
                }

                len = sqlite3_column_bytes16(stmt_p, i);
                len >>= 1;
	            if (len > MMI_MEDPLY_MAX_DESCRIPTION_LEN)
	            {
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                    break;
	            }
                else
                {
                	if (len > 0)
                    {
						mmi_ucs2ncpy((CHAR*)out_data->description, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, i), MMI_MEDPLY_MAX_DESCRIPTION_LEN - 1);
					}
                    else
                    {
						out_data->description[0] = 0;
                    }
                    i++;
                }
	            

                len = sqlite3_column_bytes16(stmt_p, i);
                len >>= 1;
	            if (len > MMI_MEDPLY_MAX_AUTHOR_LEN)
	            {
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                    break;
	            }
                else
                {
                	if (len > 0)
                    {
						mmi_ucs2ncpy((CHAR*)out_data->author, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, i), MMI_MEDPLY_MAX_AUTHOR_LEN - 1);
					}
                    else
                    {
						out_data->author[0] = 0;
                   	}
                    i++;
                }
	            
	            out_data->year = sqlite3_column_kal_int16(stmt_p, i);
				i++;
	
                out_data->track_num = sqlite3_column_kal_int16(stmt_p, i);
				i++;

                out_data->lyrics_type = sqlite3_column_kal_int8(stmt_p, i);
				i++;
                
                out_data->artwork_type = sqlite3_column_kal_int8(stmt_p, i);
				i++;
                ret = 0;
			} while (0);                   
		}
        else
        {
			ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
        }
    }

    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}   
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_query_meta_for_display
* DESCRIPTION
*  
* PARAMETERS
*  id			[IN]
*  out_data		[OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_query_meta_for_display(U32 id, mmi_medply_details_for_display_struct* out_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	UI_character_type file_path[MEDPLY_MAX_PATH_LEN];
    sqlite3_stmt* stmt = NULL;
    U8 artwork_type = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    memset(out_data, 0, sizeof(mmi_medply_details_for_display_struct));
    
    ret = DB_PREPARE("SELECT path FROM media WHERE media_id = ?", &stmt);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt, 1, id));   
        ret = DB_STEP(stmt);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
        	S32 len = sqlite3_column_bytes16(stmt, 0);

	        len >>= 1;
			if (len <= MEDPLY_MAX_PATH_LEN)
	        {
	        	mmi_ucs2ncpy((CHAR*)file_path, (const CHAR*)sqlite3_column_kal_wstr(stmt, 0), MEDPLY_MAX_PATH_LEN - 1);
				ret = 0;
	        }
            else
	        {
	            ret = MEDPLY_PLST_ERR_OVER_LIMIT;
                goto query_meta_for_display_error_handling;
	        }
        }
        else
        {
			ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
            goto query_meta_for_display_error_handling;
        }
    }
    
    if (stmt != NULL)
	{
		DB_FINALIZE(stmt);
        stmt = NULL;
	}	
  
    ret = DB_PREPARE("SELECT title, artist, album, artwork_type FROM media_meta WHERE media_id = ?", &stmt);

	if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt, 1, id));   
        ret = DB_STEP(stmt);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			S32 len = sqlite3_column_bytes16(stmt, 0);
            if (len > 0)
            {
	        	mmi_ucs2ncpy((CHAR*)out_data->title, (const CHAR*)sqlite3_column_kal_wstr(stmt, 0), MMI_MEDPLY_MAX_TITLE_LEN - 1);
				ret = 0;
            }
            else
            {
                out_data->title[0] = 0;
            }

            len = sqlite3_column_bytes16(stmt, 1);
            if (len > 0)
            {
	            mmi_ucs2ncpy((CHAR*)out_data->artist, (const CHAR*)sqlite3_column_kal_wstr(stmt, 1), MMI_MEDPLY_MAX_ARTISRT_LEN - 1);
				ret = 0;
            }
            else
            {
                out_data->artist[0] = 0;
            }
            len = sqlite3_column_bytes16(stmt, 2);
            if (len > 0)
            {
	        	mmi_ucs2ncpy((CHAR*)out_data->album, (const CHAR*)sqlite3_column_kal_wstr(stmt, 2), MMI_MEDPLY_MAX_ALBUM_LEN - 1);
				ret = 0;
            }
            else
            {
                out_data->album[0] = 0;
            }

            artwork_type = sqlite3_column_kal_uint8(stmt, 3);
        }
    }

    if (stmt != NULL)
	{
		DB_FINALIZE(stmt);
        stmt = NULL;
	}
    
    ret = DB_PREPARE("SELECT user_rating FROM media_ext WHERE media_id = ?", &stmt);

	if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt, 1, id));   
        ret = DB_STEP(stmt);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			out_data->user_rating = sqlite3_column_kal_uint8(stmt, 0);
        }
        else
        {
            out_data->user_rating = 0;
        }
    }

    if (stmt != NULL)
	{
		DB_FINALIZE(stmt);
        stmt = NULL;
	}

    /* get artwork details. */
    ret = mmi_medply_plst_get_artwork_details(file_path, &(out_data->artwork));

    return ret;
query_meta_for_display_error_handling:
    if (stmt != NULL)
	{
		DB_FINALIZE(stmt);
        stmt = NULL;
	}	
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_add_internal
* DESCRIPTION
*  
* PARAMETERS
*  media_id			[IN]
*  media_item       [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_media_add_internal(
										U32 media_id, 
										mmi_medply_db_media_base_struct* base,
										mmi_medply_db_media_meta_struct* meta)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    mmi_medply_time_record_struct current_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    base->id = media_id;
    /*
		CREATE TABLE media_ext(	
			media_id			INTEGER     PRIMARY KEY,
            play_count          INTEGER     DEFAULT 0,
            volume              INTEGER     DEFAULT 0,
            user_rating         INTEGER     DEFAULT 0,
            played         		BLOB        NOT NULL,
            modified       		BLOB        NOT NULL
			)
    */
	ret = DB_PREPARE("INSERT INTO media_ext(\
media_id, play_count, volume, user_rating, played, modified)\
values(?, 0, 0, 0, ?, ?)", &stmt_p);
	if (ret >= 0)
    {
		DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
        memset(&current_time, 0, sizeof(mmi_medply_time_record_struct));
	    DB_CHK(sqlite3_bind_blob(stmt_p, 2, &current_time, sizeof(mmi_medply_time_record_struct), SQLITE_STATIC));
	    mmi_medply_db_util_get_current_data_time(&current_time);
        DB_CHK(sqlite3_bind_blob(stmt_p, 3, &current_time, sizeof(mmi_medply_time_record_struct), SQLITE_STATIC));
		ret = DB_STEP(stmt_p);
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}

	if (ret < 0)
    {
		return ret;
    }
    /*
			CREATE TABLE media_meta(
                media_id			INTEGER		PRIMARY KEY,
                title               TEXT        NOT NULL,
                artist				TEXT,
                album				TEXT,
                genre               TEXT,
                copyrights          TEXT,
                description         TEXT,
                author              TEXT,
                year                INTEGER,
                track_num           INTEGER,
				artwork_type        INTEGER     DEFAULT 0,
				lyrics_type			INTEGER     DEFAULT 0
				)
    */

    if (meta != NULL)
    {
		ret = DB_PREPARE("INSERT INTO media_meta(\
media_id, title, artist, album, genre, copyrights, description, author, \
year, track_num, artwork_type, lyrics_type)\
values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, 0)", &stmt_p);
		if (ret >= 0)
	    {
			DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
		    DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 2, meta->title));
		    DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 3, meta->artist));
		    DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 4, meta->album));
            DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 5, meta->genre));
            DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 6, meta->copyrights));
            DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 7, meta->description));
            DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 8, meta->author));
		    DB_CHK(sqlite3_bind_kal_int16(stmt_p, 9, meta->year));
		    DB_CHK(sqlite3_bind_kal_int16(stmt_p, 10, meta->track_num));
			DB_CHK(sqlite3_bind_kal_uint8(stmt_p, 11, meta->artwork_type));

            ret = DB_STEP(stmt_p);
	    }

        if (stmt_p != NULL)
		{
			DB_FINALIZE(stmt_p);
	        stmt_p = NULL;
		}
        if (ret < 0)
	    {
			return ret;
	    }
	}

    
    /*
    CREATE TABLE media(
        media_id			INTEGER     PRIMARY KEY,
        path_hash           INTEGER     NOT NULL,
        local				INTEGER		NOT NULL,
        serial_num			INTEGER		NOT NULL,
        path                TEXT        NOT NULL,
        format              INTEGER     NOT NULL
        )
    */
	ret = DB_PREPARE("INSERT INTO media(\
media_id, path_hash, local, serial_num, path, format)\
values(?, ?, ?, ?, ?, ?)", &stmt_p);
	if (ret == 0)
	{
		DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, base->path_hash));
        DB_CHK(sqlite3_bind_kal_uint8(stmt_p, 3, base->local));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 4, base->serial_num));
	    DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 5, base->path));
	    DB_CHK(sqlite3_bind_kal_uint16(stmt_p, 6, base->format));
       
	    ret = DB_STEP(stmt_p);
    }

    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_add
* DESCRIPTION
*  
* PARAMETERS
*  base     	[IN]
*  meta			[IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_media_add(mmi_medply_db_media_base_struct* base,
								   mmi_medply_db_media_meta_struct* meta)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
    U32 media_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = mmi_medply_db_media_query_max_id(&media_id);
    if (ret >= 0)
    {
		media_id++;
        return mmi_medply_db_media_add_internal(media_id, base, meta);
    }
    else
    {
		return ret;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_delete_base
* DESCRIPTION
*  
* PARAMETERS
*  media_id       [IN]
* RETURNS
*  S32 
*****************************************************************************/ 
static S32 mmi_medply_db_media_delete_base(U32 media_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("DELETE FROM media WHERE media_id = ?", &stmt_p);
    if (ret == 0)
    {
    	DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
    
    	ret = DB_STEP(stmt_p);
	}

    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}

    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_delete_meta
* DESCRIPTION
*  
* PARAMETERS
*  media_id       [IN]
* RETURNS
*  S32 
*****************************************************************************/ 
static S32 mmi_medply_db_media_delete_meta(U32 media_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("DELETE FROM media_meta WHERE media_id = ?", &stmt_p);
    if (ret == 0)
    {
    	DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
    
    	ret = DB_STEP(stmt_p);
	}

    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_delete_ext
* DESCRIPTION
*  
* PARAMETERS
*  media_id       [IN]
* RETURNS
*  S32 
*****************************************************************************/ 
static S32 mmi_medply_db_media_delete_ext(U32 media_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("DELETE FROM media_ext WHERE media_id = ?", &stmt_p);
    if (ret == 0)
    {
    	DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
    
    	ret = DB_STEP(stmt_p);
	}

    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
    return ret; 
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_delete
* DESCRIPTION
*  
* PARAMETERS
*  media_id       [IN]
* RETURNS
*  S32 
*****************************************************************************/ 
static S32 mmi_medply_db_media_delete(U32 media_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	ret = mmi_medply_db_media_delete_base(media_id);
	if (ret < 0)
    {
		return ret;
    }
    
    ret = mmi_medply_db_media_delete_meta(media_id);
    if (ret < 0)
    {
		return ret;
    }

    ret = mmi_medply_db_media_delete_ext(media_id);
	if (ret < 0)
    {
		return ret;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_update_meta
* DESCRIPTION
*  
* PARAMETERS
*  id			[IN]
*  flag			[IN]
*  new_data		[IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_update_meta(U32 id, U32 flag, mmi_medply_db_media_struct* new_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    CHAR cmd[256];
	U8 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	sprintf(cmd, "UPDATE media_meta SET");
    
    if (flag & MEDPLY_DB_UPDATE_TITLE)
    {
      	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " title = ?");
        count++;
    }
    
    if (flag & MEDPLY_DB_UPDATE_ARTIST)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " artist = ?");
        count++;
    }

    if (flag & MEDPLY_DB_UPDATE_ALBUM)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " album = ?");
        count++;
    }
    
    if (flag & MEDPLY_DB_UPDATE_GENRE)
    {
        if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " genre = ?");
        count++;
    }

    if (flag & MEDPLY_DB_UPDATE_DESCRIPTION)
    {
        if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " description = ?");
        count++;
    }

    if (flag & MEDPLY_DB_UPDATE_AUTHOR)
    {
         if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " author = ?");
        count++;
    }
    if (flag & MEDPLY_DB_UPDATE_YEAR)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " year = ?");
        count++;
    }
    if (flag & MEDPLY_DB_UPDATE_TRACKNUM)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " track_num = ?");
        count++;
    }                

    if (flag & MEDPLY_DB_UPDATE_LYRICS)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " lyrics_type = ?");
        count++;
    }

    if (flag & MEDPLY_DB_UPDATE_ARTWORK)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " artwork_type = ?");
        count++;
    }
        
    strcat(cmd, " WHERE media_id = ?");
            
    ret = DB_PREPARE(cmd, &stmt_p);
    if (ret ==0)
	{
		U8 i = 1;
		if (flag & MEDPLY_DB_UPDATE_TITLE)
        {
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, i, new_data->title));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_ARTIST)
        {
           	DB_CHK(sqlite3_bind_kal_wstr(stmt_p, i, new_data->artist));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_ALBUM)
        {
           	DB_CHK(sqlite3_bind_kal_wstr(stmt_p, i, new_data->album));
            i++;
        }     
		if (flag & MEDPLY_DB_UPDATE_GENRE)
        {
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, i, new_data->genre));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_DESCRIPTION)
        {
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, i, new_data->description));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_AUTHOR)
        {
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, i, new_data->author));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_YEAR)
        {
			DB_CHK(sqlite3_bind_kal_int16(stmt_p, i, new_data->year));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_TRACKNUM)
        {
			DB_CHK(sqlite3_bind_kal_int16(stmt_p, i, new_data->track_num));
            i++;
        }
		if (flag & MEDPLY_DB_UPDATE_LYRICS)
        {
			DB_CHK(sqlite3_bind_kal_int8(stmt_p, i, new_data->lyrics_type));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_ARTWORK)
        {
           	DB_CHK(sqlite3_bind_kal_int8(stmt_p, i, new_data->artwork_type));
            i++;
        }
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, i, id));
		MMI_ASSERT(i == (count + 1));
        ret = DB_STEP(stmt_p);
	}
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}	    

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_update_ext
* DESCRIPTION
*  
* PARAMETERS
*  id			[IN]
*  flag			[IN]
*  new_data		[IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_update_ext(U32 id, U32 flag, mmi_medply_db_media_struct* new_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    CHAR cmd[256];
	U8 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	sprintf(cmd, "UPDATE media_ext SET");                

    if (flag & MEDPLY_DB_UPDATE_COUNT)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " play_count = ?");
        count++;
    }

    if (flag & MEDPLY_DB_UPDATE_VOL)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " volume = ?");
        count++;
    }

    if (flag & MEDPLY_DB_UPDATE_RATING)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " user_rating = ?");
        count++;
    }
    if (flag & MEDPLY_DB_UPDATE_PLAYED)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " played = ?");
        count++;
    }
    if (flag & MEDPLY_DB_UPDATE_MODIFIED)
    {
    	if (count)
        {
			strcat(cmd, ",");
        }
		strcat(cmd, " modified = ?");
        count++;
    }

    strcat(cmd, " WHERE media_id = ?");
            
    ret = DB_PREPARE(cmd, &stmt_p);
    if (ret ==0)
	{
		U8 i = 1;
        if (flag & MEDPLY_DB_UPDATE_COUNT)
        {
			DB_CHK(sqlite3_bind_kal_uint16(stmt_p, i, new_data->play_count));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_VOL)
        {
			DB_CHK(sqlite3_bind_kal_int16(stmt_p, i, new_data->volume));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_RATING)
        {
			DB_CHK(sqlite3_bind_kal_uint8(stmt_p, i, new_data->user_rating));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_PLAYED)
        {
        	DB_CHK(sqlite3_bind_blob(stmt_p, i, &(new_data->last_played), sizeof(mmi_medply_time_record_struct), SQLITE_STATIC));
            i++;
        }
        if (flag & MEDPLY_DB_UPDATE_MODIFIED)
        {    
        	mmi_medply_time_record_struct new_time;
    		mmi_medply_db_util_get_current_data_time(&new_time);
	    	DB_CHK(sqlite3_bind_blob(stmt_p, i, &new_time, sizeof(mmi_medply_time_record_struct), SQLITE_STATIC));
            memcpy(&(new_data->last_modified), &new_time, sizeof(mmi_medply_time_record_struct));
            i++;
        }

        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, i, id));
		MMI_ASSERT(i == (count + 1));
        ret = DB_STEP(stmt_p);
	}
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}	    

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_modify
* DESCRIPTION
*  delete old node and insert a new one.
* PARAMETERS
*  id				[IN]
*  update_flag		[IN]
*  new_data			[IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_modify(U32 id, U32 update_flag, mmi_medply_db_media_struct* new_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (update_flag & MEDPLY_DB_UPDATE_TITLE ||
        update_flag & MEDPLY_DB_UPDATE_ARTIST ||
        update_flag & MEDPLY_DB_UPDATE_ALBUM ||
        update_flag & MEDPLY_DB_UPDATE_GENRE ||
        update_flag & MEDPLY_DB_UPDATE_DESCRIPTION ||
        update_flag & MEDPLY_DB_UPDATE_AUTHOR ||
        update_flag & MEDPLY_DB_UPDATE_YEAR ||
        update_flag & MEDPLY_DB_UPDATE_TRACKNUM ||
        update_flag & MEDPLY_DB_UPDATE_LYRICS ||
        update_flag & MEDPLY_DB_UPDATE_ARTWORK)
    {
		ret = mmi_medply_db_media_update_meta(id, update_flag, new_data);

        if (ret < 0)
        {
			return ret;
        }
    }

    if (update_flag & MEDPLY_DB_UPDATE_COUNT || 
        update_flag & MEDPLY_DB_UPDATE_VOL ||
        update_flag & MEDPLY_DB_UPDATE_RATING ||
        update_flag & MEDPLY_DB_UPDATE_PLAYED ||
        update_flag & MEDPLY_DB_UPDATE_MODIFIED)
    {
		ret = mmi_medply_db_media_update_ext(id, update_flag, new_data);

        if (ret < 0)
        {
			return ret;
        }
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_update_time
* DESCRIPTION
*  
* PARAMETERS
*  type				[IN]
*  id				[IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_update_time(U8 type, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_time_record_struct new_time;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_db_util_get_current_data_time(&new_time);
    
    if (type == 1)
    {
        ret = DB_PREPARE("UPDATE media_ext SET modified =? WHERE media_id = ?", &stmt_p);
    }
    else
    {
        ret = DB_PREPARE("UPDATE media_ext SET played = ? WHERE media_id = ?", &stmt_p);
    }
    
    if (ret >= 0)
    {
	    DB_CHK(sqlite3_bind_blob(stmt_p, 1, &new_time, sizeof(mmi_medply_time_record_struct), SQLITE_STATIC));
	    DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, id));
	    
	    ret = DB_STEP(stmt_p);
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    return ret; 
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_media_increase_count
* DESCRIPTION
*  
* PARAMETERS
*  id			[IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_increase_count(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U16 play_count = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT play_count FROM media_ext WHERE media_id = ?", &stmt_p);
    if (ret >= 0)
    {    
	    DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));
	    
	    DB_STEP(stmt_p); 
	    play_count = sqlite3_column_kal_uint16(stmt_p, 0);

	    if (stmt_p != NULL)
		{
			DB_FINALIZE(stmt_p);
            stmt_p = NULL;
		}	   
	    
	    ret = DB_PREPARE("UPDATE media_ext SET play_count = ? WHERE media_id = ?", &stmt_p);
	    if (ret == SQLITE_OK)
	    {
	        mmi_medply_db_sqlite3_reset(stmt_p);
	        DB_CHK(sqlite3_bind_kal_uint16(stmt_p, 1, (play_count + 1)));
	        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, id));
	        DB_STEP(stmt_p);
	    }
	    if (stmt_p != NULL)
		{
			DB_FINALIZE(stmt_p);
            stmt_p = NULL;
		}
    }

    return ret; 
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_recent_played_list
* DESCRIPTION
*  
* PARAMETERS
*  tbl                [OUT]
*  out_total		  [OUT]	
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_plst_add_to_recent(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0;
	U32 total = 0;
    S32 ret = 0;
    U32 id_table[20];
    U16 play_count = 0;
    mmi_medply_time_record_struct new_time;
    sqlite3_stmt* stmt_p = NULL;
    MMI_BOOL exist = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
// update play count and played time.
    mmi_medply_db_util_get_current_data_time(&new_time);
    
    ret = DB_PREPARE("SELECT play_count FROM media_ext WHERE media_id = ?", &stmt_p);
    if (ret >= 0)
    {    
	    DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, id));
	    
	    DB_STEP(stmt_p); 
	    play_count = sqlite3_column_kal_uint16(stmt_p, 0);

	    if (stmt_p != NULL)
		{
			DB_FINALIZE(stmt_p);
            stmt_p = NULL;
		}
	    
	    ret = DB_PREPARE("UPDATE media_ext SET play_count = ?, played = ? WHERE media_id = ?", &stmt_p);
	    if (ret == SQLITE_OK)
	    {
	        mmi_medply_db_sqlite3_reset(stmt_p);
	        DB_CHK(sqlite3_bind_kal_uint16(stmt_p, 1, (play_count + 1)));
            DB_CHK(sqlite3_bind_blob(stmt_p, 2, &new_time, sizeof(mmi_medply_time_record_struct), SQLITE_STATIC));
	        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 3, id));
	        DB_STEP(stmt_p);
	    }
	    if (stmt_p != NULL)
		{
			DB_FINALIZE(stmt_p);
            stmt_p = NULL;
		}
    }
// add to recently list
    if (ret >= 0)
    {
        ret = DB_PREPARE("SELECT media_id FROM plst_item WHERE plst_id = ? ORDER BY idx", &stmt_p);
	    if (ret == 0)
	    {
	        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, MMI_MEDPLY_DB_LST_RECENT_ID));
	        while (total < MEDPLY_MAX_RECENT_PLAYED_ITEM && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
	        {
	            id_table[total] = sqlite3_column_kal_uint32(stmt_p, 0);
	            total++;
	        }
	    }
	    if (stmt_p != NULL)
		{
			DB_FINALIZE(stmt_p);
            stmt_p = NULL;
		}
        if (ret >= 0)
        {
        // remove old record
			for (i = 0; i < total; i++)
            {
				if (id_table[i] == id)
                {
					exist = MMI_TRUE;
                    break;
                }
            }

            if (exist)
            {
            	U16 m = 0;
                U32 tmp = 0;
                U32 list_id = MMI_MEDPLY_DB_LST_RECENT_ID;
				// just resort
				for (m = i; m < (total - 1); m++)
                {
					tmp = id_table[m];
                    id_table[m] = id_table[m + 1];
                    id_table[m + 1] = tmp;
                }
                             	
				ret = mmi_medply_db_plst_clear(MMI_MEDPLY_DB_LST_RECENT_ID);
                if (ret >= 0)
                {
	                for (i = 0; i < total; i++)
	                {
						ret = mmi_medply_db_item_add(id_table[i], list_id, i);
						if (ret < 0)
				        {
							break;
			            }
	                }
                }
            }
            else
            {
				if (total == MEDPLY_MAX_RECENT_PLAYED_ITEM)
                {
                	U32 list_id = MMI_MEDPLY_DB_LST_RECENT_ID;
					// need remove oldest one, then add new id.
					ret = mmi_medply_db_plst_clear(MMI_MEDPLY_DB_LST_RECENT_ID);
                    if (ret >= 0)
                    {
	                    for (i = 0; i < total; i++)
	                    {
							ret = mmi_medply_db_item_add(id_table[i], list_id, i);
							if (ret < 0)
				            {
								break;
			                }
	                    }
                    }
                }
                else
                {
					// add directly
					ret = mmi_medply_db_item_add(id, MMI_MEDPLY_DB_LST_RECENT_ID, total);
                }
            }
        }
    }

    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_plst_query_recent_played_list
* DESCRIPTION
*  
* PARAMETERS
*  tbl                [OUT]
*  out_total		  [OUT]	
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_media_query_path_by_plst_idx(U32 plst_id, U32 plst_idx, UI_string_type out_path)
{
	U32 media_id = 0;
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;

    ret = DB_PREPARE("SELECT media_id FROM plst_item WHERE idx = ? AND plst_id = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, plst_idx));
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 2, plst_id));

        ret = DB_STEP(stmt_p);
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            media_id = sqlite3_column_kal_uint32(stmt_p, 0); 
        }
        else
        {
            media_id = 0;
            *out_path = 0;
            ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
        }
    }
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    if (ret == MEDPLY_PLST_GOT_DATA)
    {
	    S32 len = 0;
	    
	    ret = DB_PREPARE("SELECT path FROM media WHERE media_id = ?", &stmt_p);
	    if (ret == 0)
	    {
	        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, media_id));
	        
	        ret = DB_STEP(stmt_p); 

	        if (ret == MEDPLY_PLST_GOT_DATA)
	        {
				len = sqlite3_column_bytes16(stmt_p, 0);
	            len >>= 1;
	            if (len < MEDPLY_MAX_PATH_LEN)
	            {
	            	mmi_ucs2ncpy((CHAR*)out_path, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, 0), MEDPLY_MAX_PATH_LEN - 1);
					ret = 0;
	            }
	            else
	            {
					*out_path = 0;
	                ret = MEDPLY_PLST_ERR_OVER_LIMIT;//error
	            }
	        }
	        else
	        {
				*out_path = 0;
	            ret = MEDPLY_PLST_ERR_CAN_NOT_FIND;
	        }
	    }
        if (stmt_p != NULL)
		{
			DB_FINALIZE(stmt_p);
            stmt_p = NULL;
		}
    }

    return ret;
}



/*****************************************************************************
* FUNCTION
*  mmi_medply_db_amf_query_search_part1
* DESCRIPTION
*  
* PARAMETERS
*  search_cntx			[IN/OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_amf_query_search_part1(mmi_medply_db_search_struct* search_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    U8 i = 0;
    U8 input_para_count = 1;	//sqlite3 bind parameter counter begin from 1
	CHAR cmd[512];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CHECK_DRIVER_STATUE__    
	/* need update driver state. */
	mmi_medply_plst_util_get_drv_status();
#endif
	sprintf(cmd, "SELECT COUNT(*) FROM media NATURAL LEFT JOIN media_meta WHERE ");
#ifdef __CHECK_DRIVER_STATUE__    
    strcat(cmd, "(");
    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
    {
		if (plst_cntx_p->drv_list[i].is_active)
        {
            if (i > 0)
            {
                strcat(cmd, " OR");
            }
            strcat(cmd, " (media.serial_num = ? AND media.local = ?)");
        }
    }
    strcat(cmd, ") AND ");
#endif   
	strcat(cmd, "(");
    i = 0;
	if (search_cntx->s_title[0] != 0)
	{
        if (i > 0)
        {
            strcat(cmd, " AND ");
        }
		strcat(cmd, "media_meta.title LIKE ?");
        i++;
	}

    if (search_cntx->s_artist[0] != 0)
	{
        if (i > 0)
        {
            strcat(cmd, " AND ");
        }
		strcat(cmd, "media_meta.artist LIKE ?");
        i++;
	}

    if (search_cntx->s_album[0] != 0)
	{
        if (i > 0)
        {
            strcat(cmd, " AND ");
        }
		strcat(cmd, "media_meta.album LIKE ?");
        i++;
	}
    
    if (search_cntx->s_genre[0] != 0)
    {
        if (i > 0)
        {
            strcat(cmd, " AND ");
        }
		strcat(cmd, "media_meta.genre LIKE ?");	
        i++;
    }
    strcat(cmd, ")");
	ret = DB_PREPARE(cmd, &stmt_p);
    
    if (ret == 0)
    {
    #ifdef __CHECK_DRIVER_STATUE__
	    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
	    {        
			if (plst_cntx_p->drv_list[i].is_active)
	        {
				DB_CHK(sqlite3_bind_kal_uint32(stmt_p, (2 * i + 1), plst_cntx_p->drv_list[i].serial_number));
                input_para_count++;
				DB_CHK(sqlite3_bind_kal_uint32(stmt_p, (2 * i + 2), i));
                input_para_count++;
	        }
	    }
    #endif
	    if (search_cntx->s_title[0] != 0)
		{
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, input_para_count, search_cntx->s_title));
            input_para_count++;
		}

	    if (search_cntx->s_artist[0] != 0)
		{
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, input_para_count, search_cntx->s_artist));
            input_para_count++;
		}

	    if (search_cntx->s_album[0] != 0)
		{
            DB_CHK(sqlite3_bind_kal_wstr(stmt_p, input_para_count, search_cntx->s_album));
            input_para_count++;
		}
	    
	    if (search_cntx->s_genre[0] != 0)
	    {
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, input_para_count, search_cntx->s_genre));
            input_para_count++;
	    }

        ret = DB_STEP(stmt_p);

        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            search_cntx->result_total = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
            search_cntx->result_total = 0;
        }    
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_amf_query_search_part2
* DESCRIPTION
*  
* PARAMETERS
*  search_cntx			[IN/OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_amf_query_search_part2(mmi_medply_db_tbl_struct* tbl, mmi_medply_db_search_struct* search_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 count = 0;
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    U8 i = 0;
    U8 input_para_count = 1;	//sqlite3 bind parameter counter begin from 1
	CHAR cmd[512];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(search_cntx != NULL);
	MMI_ASSERT(search_cntx->result_total > 0);
    MMI_ASSERT(tbl->data != NULL);
    MMI_ASSERT(tbl->size == search_cntx->result_total * sizeof(U32));
    

	/* compose SQL command. */
	sprintf(cmd, "SELECT media_id FROM media NATURAL LEFT JOIN media_meta WHERE ");                
#ifdef __CHECK_DRIVER_STATUE__
    strcat(cmd, "(");
    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
    {
		if (plst_cntx_p->drv_list[i].is_active)
        {
            if (i > 0)
            {
                strcat(cmd, " OR");
            }
            strcat(cmd, " (media.serial_num = ? AND media.local = ?)");
        }
    }
    strcat(cmd, ") AND ");
#endif    
	strcat(cmd, "(");
    i = 0;
    if (search_cntx->s_title[0] != 0)
    {
        if (i > 0)
        {
            strcat(cmd, " AND ");
        }
        strcat(cmd, "media_meta.title LIKE ?");
        i++;
    }
    
    if (search_cntx->s_artist[0] != 0)
    {
        if (i > 0)
        {
            strcat(cmd, " AND ");
        }
        strcat(cmd, "media_meta.artist LIKE ?");
        i++;
    }
    
    if (search_cntx->s_album[0] != 0)
    {
        if (i > 0)
        {
            strcat(cmd, " AND ");
        }
        strcat(cmd, "media_meta.album LIKE ?");
        i++;
    }
    
    if (search_cntx->s_genre[0] != 0)
    {
        if (i > 0)
        {
            strcat(cmd, " AND ");
        }
        strcat(cmd, "media_meta.genre LIKE ?");	
        i++;
    }
    strcat(cmd, ")");
    
	strcat(cmd, " ORDER BY media_meta.title");		

	ret = DB_PREPARE(cmd, &stmt_p);
    
    if (ret == 0)
    {
    #ifdef __CHECK_DRIVER_STATUE__
	    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
	    {        
			if (plst_cntx_p->drv_list[i].is_active)
	        {
				DB_CHK(sqlite3_bind_kal_uint32(stmt_p, (2 * i + 1), plst_cntx_p->drv_list[i].serial_number));
                input_para_count++;
				DB_CHK(sqlite3_bind_kal_uint32(stmt_p, (2 * i + 2), i));
                input_para_count++;
	        }
	    }
	#endif
        if (search_cntx->s_title[0] != 0)
		{
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, input_para_count, search_cntx->s_title));
            input_para_count++;
		}

	    if (search_cntx->s_artist[0] != 0)
		{
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, input_para_count, search_cntx->s_artist));
            input_para_count++;
		}

	    if (search_cntx->s_album[0] != 0)
		{
            DB_CHK(sqlite3_bind_kal_wstr(stmt_p, input_para_count, search_cntx->s_album));
            input_para_count++;
		}
	    
	    if (search_cntx->s_genre[0] != 0)
	    {
			DB_CHK(sqlite3_bind_kal_wstr(stmt_p, input_para_count, search_cntx->s_genre));
            input_para_count++;
	    }

        while (count < search_cntx->result_total && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
            tbl->data[count] = sqlite3_column_kal_uint32(stmt_p, 0);
            count++;
        }
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}

#ifdef __MMI_MEDIA_PLAYER_STREAM__
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_bmk_add
* DESCRIPTION
*  
* PARAMETERS
*  in_data                [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_bmk_add(mmi_medply_db_bookmark_item_struct* in_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
	/*
			CREATE TABLE bookmark(	
				url_hash			INTEGER     PRIMARY KEY,
				url					TEXT		NOT NULL,
				title				TEXT		NOT NULL,
				type				INTEGER		NOT NULL
				)
    */	
	ret = DB_PREPARE("INSERT INTO bookmark(\
url_hash, url, title, type) values(?, ?, ?, ?)", &stmt_p);
	if (ret >= 0)
    {
		DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, in_data->url_hash));
        DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 2, in_data->url));
		DB_CHK(sqlite3_bind_kal_wstr(stmt_p, 3, in_data->title));
		DB_CHK(sqlite3_bind_kal_uint16(stmt_p, 4, in_data->type));		
		ret = DB_STEP(stmt_p);
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_bmk_query_url
* DESCRIPTION
*  
* PARAMETERS
*  out_data                [OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_bmk_query_url(U32 url_hash, UI_string_type out_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	S32 len = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
	ret = DB_PREPARE("SELECT url FROM bookmark WHERE url_hash = ?", &stmt_p);
	if (ret >= 0)
    {
		DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, url_hash));
        ret = DB_STEP(stmt_p);
		if (ret == MEDPLY_PLST_GOT_DATA)
		{			
			len = sqlite3_column_bytes16(stmt_p, 0);
            if (len > 0)
            {
				len >>= 1;
				if (len < MMI_MEDPLY_MAX_URL_LEN)
				{
					mmi_ucs2ncpy((CHAR*)out_url, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, 0), MMI_MEDPLY_MAX_URL_LEN - 1);
					ret = 0;
				}
				else
				{
					out_url[0] = 0;
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
				}
            }
            else
			{
				out_url[0] = 0;
            }
		}
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_bmk_query
* DESCRIPTION
*  
* PARAMETERS
*  out_data                [OUT]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_bmk_query_info(U32 url_hash, mmi_medply_plstui_db_cache_item_struct* out_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	S32 len = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
	ret = DB_PREPARE("SELECT title, type FROM bookmark WHERE url_hash = ?", &stmt_p);
	if (ret >= 0)
    {
		DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, url_hash));
        ret = DB_STEP(stmt_p);
		if (ret == MEDPLY_PLST_GOT_DATA)
		{			
			len = sqlite3_column_bytes16(stmt_p, 0);
            if (len > 0)
            {
				len >>= 1;
				if (len < MEDPLY_MAX_FILE_LEN)
				{
					mmi_ucs2ncpy((CHAR*)out_data->title, (const CHAR*)sqlite3_column_kal_wstr(stmt_p, 0), MEDPLY_MAX_FILE_LEN - 1);
					ret = 0;
				}
				else
				{
					out_data->title[0] = 0;
					ret = MEDPLY_PLST_ERR_OVER_LIMIT;
				}
            }
            else
			{
				out_data->title[0] = 0;
            }
			out_data->format = sqlite3_column_kal_uint16(stmt_p, 1);
            out_data->media_id = url_hash;
		}
    }
    
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_bmk_query_list
* DESCRIPTION
*  
* PARAMETERS
*  table	[OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_bmk_query_list(mmi_medply_db_tbl_struct* table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 count = 0;
    U32 total = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	total = table->size / sizeof(U32);
    ret = DB_PREPARE("SELECT url_hash FROM bookmark ORDER BY title", &stmt_p);
    if (ret == 0)
    {
        while (count < total && MEDPLY_PLST_GOT_DATA == (ret = DB_STEP(stmt_p)))
        {
            table->data[count] = sqlite3_column_kal_uint32(stmt_p, 0);
            count++;
        }

        if (count == total)
        {
            ret = 0;
        }
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_bmk_add
* DESCRIPTION
*  
* PARAMETERS
*  in_url                [IN]
*  in_title 		  	 [IN]	
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_bmk_get_total(S32 *out_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT COUNT(*) FROM bookmark", &stmt);
	
    if (ret == 0)
    {
        ret = DB_STEP(stmt);
        if (MEDPLY_PLST_GOT_DATA == ret)
        {
            *out_total = sqlite3_column_kal_int32(stmt, 0);
        }
        else
        {
            *out_total = 0;
        }
    }
	
    if (stmt != NULL)
    {
		DB_FINALIZE(stmt);
        stmt = NULL;
    }
    
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_bmk_remove
* DESCRIPTION
*  
* PARAMETERS
*  url_hash            [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_bmk_remove(U32 url_hash)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = DB_PREPARE("DELETE FROM bookmark WHERE url_hash = ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, url_hash));
               
        ret = DB_STEP(stmt_p);
    }

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;

}



/*****************************************************************************
* FUNCTION
*  mmi_medply_db_bmk_query_is_exist
* DESCRIPTION
*
* PARAMETERS
*  hash           [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_bmk_query_is_exist(U32 hash)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U16 type = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    ret = DB_PREPARE("SELECT type FROM bookmark WHERE url_hash = ?", &stmt_p);
      
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, hash));

        ret = DB_STEP(stmt_p);

         
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
            type = sqlite3_column_kal_uint16(stmt_p, 0);
        }
        else
        {
            type = 0;
        }
    }
    if (stmt_p != NULL)
	{
		DB_FINALIZE(stmt_p);
        stmt_p = NULL;
	}
    
	return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_bmk_clear
* DESCRIPTION
*  delete a playlist.
* PARAMETERS
*  id                [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_bmk_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 url_hash = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    ret = DB_PREPARE("DELETE FROM bookmark WHERE url_hash <> ?", &stmt_p);
    if (ret == 0)
    {
        DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, url_hash));

        ret = DB_STEP(stmt_p);
    }
    
    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }
    
    return ret;   
}

#endif  /* __MMI_MEDIA_PLAYER_STREAM__ */
#define __DB_BASE

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_set_target_info
* DESCRIPTION
*  
* PARAMETERS
*  in_data          [IN]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_set_target_info(mmi_medply_target_info_struct* in_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("INSERT INTO target_info(item, value) values(1, ?)", &stmt_p);

	if (ret == 0)
	{
	    DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, in_data->version));
	    ret = DB_STEP(stmt_p);
	}  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }

    ret = DB_PREPARE("INSERT INTO target_info(item, value) values(2, ?)", &stmt_p);

	if (ret == 0)
	{
	    DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, in_data->default_drv_serial_num));
	    ret = DB_STEP(stmt_p);
	}  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }

    ret = DB_PREPARE("INSERT INTO target_info(item, value) values(3, ?)", &stmt_p);

	if (ret == 0)
	{
	    DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, in_data->imei));
	    ret = DB_STEP(stmt_p);
	}  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }

    ret = DB_PREPARE("INSERT INTO target_info(item, value) values(4, ?)", &stmt_p);

	if (ret == 0)
	{
	    DB_CHK(sqlite3_bind_kal_uint32(stmt_p, 1, in_data->chip_id));
	    ret = DB_STEP(stmt_p);
	}  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }

    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_db_get_target_info
* DESCRIPTION
*  
* PARAMETERS
*  out_data          [OUT]
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_get_target_info(mmi_medply_target_info_struct* out_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    sqlite3_stmt* stmt_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = DB_PREPARE("SELECT value FROM target_info WHERE item = 1", &stmt_p);

	if (ret == 0)
	{
	    ret = DB_STEP(stmt_p);
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			out_data->version = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
			out_data->version = 0;
        }
	}  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }

    ret = DB_PREPARE("SELECT value FROM target_info WHERE item = 2", &stmt_p);

	if (ret == 0)
	{
	    ret = DB_STEP(stmt_p);
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			out_data->default_drv_serial_num = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
			out_data->default_drv_serial_num = 0;
        }
	}  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }

    ret = DB_PREPARE("SELECT value FROM target_info WHERE item = 3", &stmt_p);

	if (ret == 0)
	{
	    ret = DB_STEP(stmt_p);
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			out_data->imei = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
			out_data->imei = 0;
        }
	}  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }

    ret = DB_PREPARE("SELECT value FROM target_info WHERE item = 4", &stmt_p);

	if (ret == 0)
	{
	    ret = DB_STEP(stmt_p);
        if (ret == MEDPLY_PLST_GOT_DATA)
        {
			out_data->chip_id = sqlite3_column_kal_uint32(stmt_p, 0);
        }
        else
        {
			out_data->chip_id = 0;
        }
	}  

    if (stmt_p != NULL)
    {
    	DB_FINALIZE(stmt_p);
        stmt_p = NULL;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_create_default
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_create_default(void)
{
    S32 ret = 0;
    
    do 
    {
        /* create all media list */
        ret = mmi_medply_db_plst_create(MMI_MEDPLY_DB_LST_ALL_MEDIA_ID, NULL);
        if (ret != 0)
        {
            break;
        }
        
        /* create recent list */
        ret = mmi_medply_db_plst_create(MMI_MEDPLY_DB_LST_RECENT_ID, NULL);
        if (ret != 0)
        {
            break;
        }
        
        /* create bookmark list */
        ret = mmi_medply_db_plst_create(MMI_MEDPLY_DB_LST_BOOKMARK_ID, NULL);
        if (ret != 0)
        {
            break;
        }

        /* create favourites list */
        ret = mmi_medply_db_plst_create(MMI_MEDPLY_DB_LST_FAVOURITE_ID, NULL);
        if (ret != 0)
        {
            break;
        }

        /* create most played list */
        ret = mmi_medply_db_plst_create(MMI_MEDPLY_DB_LST_MOST_PLAYED_ID, NULL);
        if (ret != 0)
        {
            break;
        }

        /* create search result list */
        ret = mmi_medply_db_plst_create(MMI_MEDPLY_DB_LST_SEARCH_RESULT_ID, NULL);
        if (ret != 0)
        {
            break;
        }

        /* create on the fly list */
        ret = mmi_medply_db_plst_create(MMI_MEDPLY_DB_LST_ON_THE_FLY_ID, NULL);
        if (ret < 0)
        {
            break;
        }

        /* create dummuy list, its name is "Playlist" */
        ret = mmi_medply_db_plst_create(MMI_MEDPLY_DB_LST_DUMMEY_ID, NULL);
        if (ret != 0)
        {
            break;
        }
 
    } while (0);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_create_tables
* DESCRIPTION
*  craete all tables in db file.
* PARAMETERS
*  void
* RETURNS
*  S32 
*****************************************************************************/
static S32 mmi_medply_db_create_tables(void)
{
    S32 ret = 0;
    U8 i = 0;
    CHAR db_command[512];
   
    /* create tables. */
    for (i = 0; i < MMI_MEDPLY_DB_TABLE_ENUM_END; i++)
    {
        switch (i)
        {
            case MMI_MEDPLY_DB_TABLE_TARGET_INFO:
                /*
                        CREATE TABLE target_info(
                            item      INTEGER     PRIMARY KEY,
                            value     TEXT)
                */
                sprintf(db_command, "CREATE TABLE target_info(item INTEGER PRIMARY KEY, value TEXT)");
                break;
            case MMI_MEDPLY_DB_TABLE_PLAYLIST:
                /*
                        CREATE TABLE plst(
                            id      INTEGER     PRIMARY KEY,
                            name    TEXT)
                */
                sprintf(db_command, "CREATE TABLE plst(id INTEGER PRIMARY KEY, name TEXT)");
                break;
            case MMI_MEDPLY_DB_TABLE_PLAYLIST_ITEM:
                /*
                        CREATE TABLE plst_item(
                            media_id    INTEGER,
                            plst_id		INTEGER,
                            idx			INTEGER		NOT NULL,
                            PRIMARY KEY (media_id, plst_id))
                */
                sprintf(db_command, "CREATE TABLE plst_item(\
media_id INTEGER, plst_id INTEGER, idx INTEGER NOT NULL, \
PRIMARY KEY (media_id, plst_id))");
                break;
			case MMI_MEDPLY_DB_TABLE_MEDIA:
                /*
                        CREATE TABLE media(
                            media_id            INTEGER     PRIMARY KEY,
                            path_hash           INTEGER     NOT NULL,
                            local				INTEGER		NOT NULL,
                            serial_num			INTEGER		NOT NULL,
                            path                TEXT        NOT NULL,
                            format              INTEGER     NOT NULL
							)
                */
                sprintf(db_command, "CREATE TABLE media(\
media_id INTEGER PRIMARY KEY, path_hash INTEGER NOT NULL, local INTEGER NOT NULL, \
serial_num INTEGER NOT NULL, path TEXT NOT NULL, format INTEGER NOT NULL)");
				break;
            case MMI_MEDPLY_DB_TABLE_MEDIA_META:
                /*
						CREATE TABLE media_meta(
                            media_id			INTEGER		PRIMARY KEY,
                            title               TEXT        NOT NULL,
                            artist				TEXT,
                            album				TEXT,
                            genre               TEXT,
                            copyrights          TEXT,
                            description         TEXT,
                            author              TEXT,
                            year                INTEGER,
                            track_num           INTEGER,
							artwork_type        INTEGER     DEFAULT 0,
							lyrics_type         INTEGER     DEFAULT 0
							)
                */
                sprintf(db_command, "CREATE TABLE media_meta(\
media_id INTEGER PRIMARY KEY, title TEXT NOT NULL, artist TEXT, \
album TEXT, genre TEXT, copyrights TEXT, description TEXT, \
author TEXT, year INTEGER, track_num INTEGER, \
artwork_type INTEGER DEFAULT 0, lyrics_type INTEGER DEFAULT 0)");
                break;
            case MMI_MEDPLY_DB_TABLE_MEDIA_EXT:
                /*
						CREATE TABLE media_ext(	
							media_id			INTEGER     PRIMARY KEY,
							play_count          INTEGER     DEFAULT 0,
							volume              INTEGER     DEFAULT 0,
							user_rating         INTEGER     DEFAULT 0,
							played         		BLOB        NOT NULL,
							modified       		BLOB        NOT NULL
							)
                */
                sprintf(db_command, "CREATE TABLE media_ext(\
media_id INTEGER PRIMARY KEY, play_count INTEGER DEFAULT 0, \
volume INTEGER DEFAULT 0, user_rating INTEGER DEFAULT 0, \
played BLOB NOT NULL, modified BLOB NOT NULL)");
                break;
			case MMI_MEDPLY_DB_TABLE_URL:
				/*
						CREATE TABLE bookmark(	
							url_hash			INTEGER     PRIMARY KEY,
							url					TEXT		NOT NULL,
							title				TEXT		NOT NULL,
							type				INTEGER		NOT NULL
							)
                */
                sprintf(db_command, "CREATE TABLE bookmark(\
url_hash INTEGER PRIMARY KEY, url TEXT NOT NULL, \
title TEXT NOT NULL, type INTEGER NOT NULL)");
                break;
            default:
                MMI_ASSERT(i < MMI_MEDPLY_DB_TABLE_ENUM_END);
        }        
        
        ret = DB_EXECUTE(db_command, NULL);

        if (ret < 0)
        {
            break;           
        }
    }

    return ret;
}


#define ___DB_DISPATCH
/*****************************************************************************
* FUNCTION
*  mmi_medply_db_action_single
* DESCRIPTION
*  do block database operation.
* PARAMETERS
*  action		[IN]
*  in_para1		[?]
*  in_para2		[?]
*  in_para3		[?]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_action_single(U16 action, void* in_para1, void* in_para2, void* in_para3)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    MMI_BOOL set_transaction = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (action)
    {
        case MEDPLY_DB_ACT_CREATE_TABLE:
        case MEDPLY_DB_ACT_CREATE_DEFAULT:
        case MEDPLY_DB_ACT_SET_TARGET_INFO:    
        case MEDPLY_DB_ACT_MODIFY_PLST_CREATE:
        case MEDPLY_DB_ACT_MODIFY_PLST_RENAME:
        case MEDPLY_DB_ACT_MODIFY_PLST_CLEAR:
        case MEDPLY_DB_ACT_MODIFY_PLST_DELETE:
        case MEDPLY_DB_ACT_MODIFY_ITEM_ADD:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_DELETE:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_MODIFY:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_UPDATE_TIME:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_INCREACE_COUNT:
        case MEDPLY_DB_ACT_MODIFY_ITEM_REMOVE:
        case MEDPLY_DB_ACT_MODIFY_ADD_TO_RECENT:
        case MEDPLY_DB_ACT_MODIFY_BMK_ADD:
        case MEDPLY_DB_ACT_MODIFY_BMK_REMOVE:
        case MEDPLY_DB_ACT_MODIFY_BMK_CLEAR:
        case MEDPLY_DB_ACT_MODIFY_ITEM_APPEND:
            goto __block_modify;
            break;
        case MEDPLY_DB_ACT_GET_TARGET_INFO:    
        case MEDPLY_DB_ACT_QUERY_TOTAL_OF_LIST:
        case MEDPLY_DB_ACT_QUERY_MAX_LIST_ID:
        case MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_TITLE:
        case MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_ID:
        case MEDPLY_DB_ACT_QUERY_LISTMGR_TBL:
        case MEDPLY_DB_ACT_QUERY_LISTMGR_TBL_EXT:
        case MEDPLY_DB_ACT_QUERY_PLST_TOTAL:
        case MEDPLY_DB_ACT_QUERY_PLST_MAX_ROWID:
        case MEDPLY_DB_ACT_QUERY_PLST_TITLE:
        case MEDPLY_DB_ACT_QUERY_PLST_TBL:
        case MEDPLY_DB_ACT_QUERY_ALL_MEDIA_FILE_TBL:
        case MEDPLY_DB_ACT_QUERY_ALL_MEDIA_FILE_TOTAL: 
        case MEDPLY_DB_ACT_QUERY_ITEM_EXIST:
        case MEDPLY_DB_ACT_QUERY_ITEM_ID:
        case MEDPLY_DB_ACT_QUERY_ITEM_ID_EXT:
        case MEDPLY_DB_ACT_QUERY_ITEM_IDX:
        case MEDPLY_DB_ACT_QUERY_MEDIA_MAX_ID:
        case MEDPLY_DB_ACT_QUERY_MEDIA_PATH:
        case MEDPLY_DB_ACT_QUERY_MEDIA_TOTAL:
        case MEDPLY_DB_ACT_QUERY_MEDIA_ARTIST_NAME:    
        case MEDPLY_DB_ACT_QUERY_MEDIA_BASIC_INFO:
        case MEDPLY_DB_ACT_QUERY_MEDIA_LIST_INFO:
        case MEDPLY_DB_ACT_QUERY_MEDIA_FULL_INFO:
        case MEDPLY_DB_ACT_QUERY_MEDIA_DISPLAY_INFO:
        case MEDPLY_DB_ACT_QUERY_PATH_BY_PLST_IDX:
        case MEDPLY_DB_ACT_QUERY_PLST_RECENT_TBL:
        case MEDPLY_DB_ACT_QUERY_PLST_MOST_TBL:

        case MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART1:	//new    
        case MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART2:	//new 
        case MEDPLY_DB_ACT_QUERY_BMK_INFO:
        case MEDPLY_DB_ACT_QUERY_BMK_URL:
        case MEDPLY_DB_ACT_QUERY_BMK_TOTAL:
        case MEDPLY_DB_ACT_QUERY_BMK_LIST:    
        case MEDPLY_DB_ACT_QUERY_BMK_EXIST:
            goto __block_query;
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_EXIST_EXT:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_ADD:           
        case MEDPLY_DB_ACT_MODIFY_ITEM_ADD_EXT:
        case MEDPLY_DB_ACT_MODIFY_ITEM_SET_IDX:
        case MEDPLY_DB_ACT_MODIFY_PLST_CLEAR_SUB:
            goto __TEST;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
    MMI_ASSERT(0);
__TEST:
    DB_ENABLE;
    //DB_MEM_RELEASE;
    switch (action)
    {
        case MEDPLY_DB_ACT_QUERY_MEDIA_EXIST_EXT:
            ret = mmi_medply_db_media_query_is_exist_ext(*((U32*)in_para1));
            break;    
        case MEDPLY_DB_ACT_MODIFY_MEDIA_ADD:
            ret = mmi_medply_db_media_add((mmi_medply_db_media_base_struct*)in_para1,
                                          (mmi_medply_db_media_meta_struct*)in_para2);
            break;            
        case MEDPLY_DB_ACT_MODIFY_ITEM_ADD_EXT:
            ret = mmi_medply_db_item_add(*((U32*)in_para1), *((U32*)in_para2), *((U32*)in_para3));
            break;
        case MEDPLY_DB_ACT_MODIFY_ITEM_SET_IDX:
            ret = mmi_medply_db_item_set_index(*((U32*)in_para1), *((U32*)in_para2), *((U32*)in_para3));
            break;
        case MEDPLY_DB_ACT_MODIFY_PLST_CLEAR_SUB:
            ret = mmi_medply_db_plst_clear_sub(*((U32*)in_para1), *((U64*)in_para2), *((U64*)in_para3));
            break;
        default:
            MMI_ASSERT(0);
            break;
            
    }
    DB_DISABLE;
    return ret;
    
/* block modify action. */    
__block_modify:
    DB_ENABLE;
    DB_MEM_RELEASE;
    /* reject other modify when a tranaction in running. */
    if (plst_cntx_p->db_cntx.in_transaction)
    {
        ret = MEDPLY_PLST_ERR_DB_IN_TRANSACTION;
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_ACTION_RESULT, ret);
        return ret;
    }
    
    DB_BEGIN_TRANSACTION;
    switch (action)
    {
        case MEDPLY_DB_ACT_CREATE_TABLE:
            ret = mmi_medply_db_create_tables();
            break;
        case MEDPLY_DB_ACT_CREATE_DEFAULT:
            ret = mmi_medply_db_create_default();
            break;
        case MEDPLY_DB_ACT_SET_TARGET_INFO:
            ret = mmi_medply_db_set_target_info((mmi_medply_target_info_struct*)in_para1);
            break;
        case MEDPLY_DB_ACT_MODIFY_PLST_CREATE:
            ret = mmi_medply_db_plst_create(*((U32*)in_para1), (UI_string_type)in_para2);
            break;
        case MEDPLY_DB_ACT_MODIFY_PLST_RENAME:
            ret = mmi_medply_db_plst_rename(*((U32*)in_para1), (UI_string_type)in_para2);
            break;
        case MEDPLY_DB_ACT_MODIFY_PLST_CLEAR:
            ret = mmi_medply_db_plst_clear(*((U32*)in_para1));            
            break;
        case MEDPLY_DB_ACT_MODIFY_PLST_DELETE:
            ret = mmi_medply_db_plst_delete(*((U32*)in_para1));
            break;
        case MEDPLY_DB_ACT_MODIFY_ITEM_ADD:
            ret = mmi_medply_db_item_add(*((U32*)in_para1), *((U32*)in_para2), *((U32*)in_para3));
            break;
        case MEDPLY_DB_ACT_MODIFY_ITEM_SET_IDX:
            ret = mmi_medply_db_item_set_index(*((U32*)in_para1), *((U32*)in_para2), *((U32*)in_para3));
            break;
        case MEDPLY_DB_ACT_MODIFY_MEDIA_ADD:
            ret = mmi_medply_db_media_add((mmi_medply_db_media_base_struct*)in_para1,
                                          (mmi_medply_db_media_meta_struct*)in_para2);
            break;
        case MEDPLY_DB_ACT_MODIFY_MEDIA_DELETE:
            ret = mmi_medply_db_media_delete(*((U32*)in_para1));
            break;
        case MEDPLY_DB_ACT_MODIFY_MEDIA_MODIFY:
            ret = mmi_medply_db_media_modify(*((U32*)in_para1), *((U32*)in_para2), (mmi_medply_db_media_struct*)in_para3);
            break;
        case MEDPLY_DB_ACT_MODIFY_MEDIA_UPDATE_TIME:
            ret = mmi_medply_db_media_update_time(*((U8*)in_para1), *((U32*)in_para2));
            break;
        case MEDPLY_DB_ACT_MODIFY_MEDIA_INCREACE_COUNT:
            ret = mmi_medply_db_media_increase_count(*((U32*)in_para1));
            break;
        case MEDPLY_DB_ACT_MODIFY_ADD_TO_RECENT:
            ret = mmi_medply_db_plst_add_to_recent(*((U32*)in_para1));
            break;
        case MEDPLY_DB_ACT_MODIFY_ITEM_REMOVE:
            ret = mmi_medply_db_item_remove(*((U32*)in_para1), *((U32*)in_para2));
            break;
        case MEDPLY_DB_ACT_MODIFY_BMK_ADD:
        #ifdef __MMI_MEDIA_PLAYER_STREAM__    
            ret = mmi_medply_db_bmk_add((mmi_medply_db_bookmark_item_struct*)in_para1);
        #endif
            break;
        case MEDPLY_DB_ACT_MODIFY_BMK_REMOVE:
        #ifdef __MMI_MEDIA_PLAYER_STREAM__    
            ret = mmi_medply_db_bmk_remove(*((U32*)in_para1));
        #endif
            break;
        case MEDPLY_DB_ACT_MODIFY_BMK_CLEAR:
        #ifdef __MMI_MEDIA_PLAYER_STREAM__    
            ret = mmi_medply_db_bmk_clear();
        #endif
            break;
        case MEDPLY_DB_ACT_MODIFY_ITEM_APPEND:
            ret = mmi_medply_db_item_append(*((U32*)in_para1), *((U32*)in_para2));
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    if (ret < 0)
    {
        DB_ROLLBACK_TRANSACTION;
    }
    else
    {
        U32 file_size = 0;
        S32 fs_ret = FS_NO_ERROR;
        FS_DOSDirEntry file_info;
        UI_character_type filename[MEDPLY_MAX_FILE_LEN];
        UI_character_type journal_path[MEDPLY_MAX_PATH_LEN];
        kal_wsprintf(journal_path, "%c:\\%w\\%w%w%w%w", 
                        MMI_MEDPLY_DB_DEFAULT_DRV,
                        MMI_MEDPLY_DB_DEFAULT_FOLDER,
                        MMI_MEDPLY_DB_FILENAME,
                        MMI_MEDPLY_DB_VERSION,
                        MMI_MEDPLY_DB_EXTENSION,
                        MMI_MEDPLY_DB_JOURNAL_POSTFIX);
        fs_ret = FS_FindFirst(journal_path, 0, 0, &file_info, filename, (MEDPLY_MAX_FILE_LEN - 1) * ENCODING_LENGTH);

        if (fs_ret >= FS_NO_ERROR)
        {
            file_size = file_info.FileSize;
            FS_FindClose(fs_ret);
            if (!mmi_medply_util_check_free_space(MMI_MEDPLY_DB_DEFAULT_DRV, file_size))
            {
                ret = MEDPLY_PLST_ERR_SQLITE_FULL;	
            }
        }
        /*if (!mmi_medply_util_check_free_space(MMI_MEDPLY_DB_DEFAULT_DRV, MEDPLY_DB_DEFALUT_PAGE_SIZE))
        {
            ret = MEDPLY_PLST_ERR_SQLITE_FULL;	
        }*/
        DB_COMMIT_TRANSACTION;
    }
    DB_DISABLE;
    return ret;

/* block query action. */      
__block_query:
    DB_ENABLE;
    DB_MEM_RELEASE;
    if (!plst_cntx_p->db_cntx.in_transaction)
    {
        DB_BEGIN_TRANSACTION;
        set_transaction = MMI_TRUE;
    }
    
    switch (action)
    {
        case MEDPLY_DB_ACT_GET_TARGET_INFO:
            ret = mmi_medply_db_get_target_info((mmi_medply_target_info_struct*)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_TOTAL_OF_LIST:
            ret = mmi_medply_db_listmgr_query_total((U32*)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_MAX_LIST_ID:
            ret = mmi_medply_db_listmgr_query_max_id((U32*)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_TITLE:
            ret = mmi_medply_db_listmgr_query_exist_by_name((UI_string_type)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_ID:
            ret = mmi_medply_db_listmgr_query_exist_by_id(*((U32*)in_para1));
            break;
        case MEDPLY_DB_ACT_QUERY_LISTMGR_TBL:
            ret = mmi_medply_db_listmgr_query_list_ext((mmi_medply_db_tbl_struct*)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_LISTMGR_TBL_EXT:
            ret = mmi_medply_db_listmgr_query_list((mmi_medply_db_tbl_struct*)in_para1);
            break;    
        case MEDPLY_DB_ACT_QUERY_PLST_MAX_ROWID:
            ret = mmi_medply_db_plst_query_max_rowid(*((U64*)in_para1), *((U32*) in_para2), (U64*) in_para3);
            break;
        case MEDPLY_DB_ACT_QUERY_PLST_TOTAL:
            ret = mmi_medply_db_plst_query_total(*((U32*)in_para1), (U32*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_PLST_TITLE:
            ret = mmi_medply_db_plst_query_title(*((U32*)in_para1), (UI_string_type)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_ALL_MEDIA_FILE_TBL:
            ret = mmi_medply_db_amf_query_list_table(*((U32*)in_para1), (mmi_medply_db_tbl_struct*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_ALL_MEDIA_FILE_TOTAL: 
            ret = mmi_medply_db_amf_query_total((U32*)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_PLST_TBL:
            ret = mmi_medply_db_plst_query_list_table(*((U32*)in_para1), (mmi_medply_db_tbl_struct*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_PLST_MOST_TBL:
            ret = mmi_medply_db_plst_query_most_played_list((mmi_medply_db_tbl_struct*)in_para1, (U32*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_PLST_RECENT_TBL:
            ret = mmi_medply_db_plst_query_recent_played_list((mmi_medply_db_tbl_struct*)in_para1, (U32*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_ITEM_EXIST:
            ret = mmi_medply_db_item_check_exist(*((U32*)in_para1), *((U32*)in_para2));
            break;
        case MEDPLY_DB_ACT_QUERY_ITEM_ID:
            ret = mmi_medply_db_item_query_id(*((U32*)in_para1), *((U32*)in_para2), (U32*)in_para3);
            break;
        case MEDPLY_DB_ACT_QUERY_ITEM_ID_EXT:
            ret = mmi_medply_db_item_query_id_ext(*((U32*)in_para1), *((U32*)in_para2), (U32*)in_para3);
            break;
        case MEDPLY_DB_ACT_QUERY_ITEM_IDX:
            ret = mmi_medply_db_item_query_index((U32*)in_para1, *((U32*)in_para2), *((U32*)in_para3));
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_MAX_ID:
            ret = mmi_medply_db_media_query_max_id((U32*)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_PATH:
            ret = mmi_medply_db_media_query_path(*((U32*)in_para1), (UI_string_type)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_TOTAL:
            ret = mmi_medply_db_media_query_total((U32*)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_ARTIST_NAME: 
            ret = mmi_medply_db_media_query_artist(*((U32*)in_para1), (UI_string_type)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_BASIC_INFO:
        case MEDPLY_DB_ACT_QUERY_MEDIA_LIST_INFO:
            ret = mmi_medply_db_media_query_list_info(*((U32*)in_para1), (mmi_medply_plstui_db_cache_item_struct*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_EXIST_EXT:
            ret = mmi_medply_db_media_query_is_exist_ext(*((U32*)in_para1));
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_FULL_INFO:
            ret = mmi_medply_db_media_query_full_meta(*((U32*)in_para1), (mmi_medply_db_media_struct*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_MEDIA_DISPLAY_INFO:
            ret = mmi_medply_db_media_query_meta_for_display(*((U32*)in_para1), (mmi_medply_details_for_display_struct*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_PATH_BY_PLST_IDX:
            ret = mmi_medply_db_media_query_path_by_plst_idx(*((U32*)in_para1), *((U32*)in_para2), (UI_string_type)in_para3);
            break;

        case MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART1:	//new
            ret = mmi_medply_db_amf_query_search_part1((mmi_medply_db_search_struct*)in_para1);
            break;
        case MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART2:	//new 
            ret = mmi_medply_db_amf_query_search_part2((mmi_medply_db_tbl_struct*)in_para1, (mmi_medply_db_search_struct*)in_para2);
            break;
        case MEDPLY_DB_ACT_QUERY_BMK_URL:
        #ifdef __MMI_MEDIA_PLAYER_STREAM__    
            ret = mmi_medply_db_bmk_query_url(*((U32*)in_para1), (UI_string_type)in_para2);
        #endif
            break;
        case MEDPLY_DB_ACT_QUERY_BMK_INFO:
        #ifdef __MMI_MEDIA_PLAYER_STREAM__    
            ret = mmi_medply_db_bmk_query_info(*((U32*)in_para1), (mmi_medply_plstui_db_cache_item_struct*)in_para2);
        #endif
            break;
        case MEDPLY_DB_ACT_QUERY_BMK_TOTAL:
        #ifdef __MMI_MEDIA_PLAYER_STREAM__    
            ret = mmi_medply_db_bmk_get_total(((S32*)in_para1));
        #endif
            break;
        case MEDPLY_DB_ACT_QUERY_BMK_LIST:    
        #ifdef __MMI_MEDIA_PLAYER_STREAM__    
            ret = mmi_medply_db_bmk_query_list((mmi_medply_db_tbl_struct*)in_para1);
        #endif
            break;
        case MEDPLY_DB_ACT_QUERY_BMK_EXIST:    
        #ifdef __MMI_MEDIA_PLAYER_STREAM__    
            ret = mmi_medply_db_bmk_query_is_exist(*((U32*)in_para1));
        #endif
            break;
        
        default:
            MMI_ASSERT(0);
            break;
    }

    if (set_transaction)
    {
        DB_END_TRANSACTION;
    }
    DB_DISABLE;
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_action
* DESCRIPTION
*  warp all database operation.
* PARAMETERS
*  action		[IN]
*  in_para1		[?]
*  in_para2		[?]
*  in_para3		[?]
*  line			[IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_action(U16 action, void* in_para1, void* in_para2, void* in_para3, S32 line)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 cost = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef PERFORMANCE_MONITOR
    __time1 = mmi_medply_get_current_time();
#endif
    switch (action)
    {
        case MEDPLY_DB_ACT_CREATE_TABLE:
        case MEDPLY_DB_ACT_CREATE_DEFAULT:
        case MEDPLY_DB_ACT_SET_TARGET_INFO:
        case MEDPLY_DB_ACT_GET_TARGET_INFO:    
        /* list manager */    
        case MEDPLY_DB_ACT_QUERY_TOTAL_OF_LIST:
        case MEDPLY_DB_ACT_QUERY_MAX_LIST_ID:
        case MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_TITLE:
        case MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_ID:
        case MEDPLY_DB_ACT_QUERY_LISTMGR_TBL:
        case MEDPLY_DB_ACT_QUERY_LISTMGR_TBL_EXT:
        /* playlist */    
        case MEDPLY_DB_ACT_MODIFY_PLST_CREATE:
        case MEDPLY_DB_ACT_MODIFY_PLST_RENAME:
        case MEDPLY_DB_ACT_MODIFY_PLST_CLEAR:
        case MEDPLY_DB_ACT_MODIFY_PLST_CLEAR_SUB:
        case MEDPLY_DB_ACT_MODIFY_PLST_DELETE:
        case MEDPLY_DB_ACT_QUERY_PLST_MAX_ROWID:
        case MEDPLY_DB_ACT_QUERY_PLST_TOTAL:
        case MEDPLY_DB_ACT_QUERY_PLST_TITLE:
        case MEDPLY_DB_ACT_QUERY_PLST_TBL:
            
        case MEDPLY_DB_ACT_QUERY_ALL_MEDIA_FILE_TBL:
        case MEDPLY_DB_ACT_QUERY_ALL_MEDIA_FILE_TOTAL: 
            
        case MEDPLY_DB_ACT_QUERY_PLST_MOST_TBL:
        case MEDPLY_DB_ACT_QUERY_PLST_RECENT_TBL:
        /* playlist item */
        case MEDPLY_DB_ACT_QUERY_ITEM_EXIST:
        case MEDPLY_DB_ACT_QUERY_ITEM_ID:
        case MEDPLY_DB_ACT_QUERY_ITEM_ID_EXT:
        case MEDPLY_DB_ACT_QUERY_ITEM_IDX:
        case MEDPLY_DB_ACT_MODIFY_ITEM_ADD:
        case MEDPLY_DB_ACT_MODIFY_ITEM_ADD_EXT:
        case MEDPLY_DB_ACT_MODIFY_ITEM_SET_IDX:
        case MEDPLY_DB_ACT_MODIFY_ITEM_REMOVE: 
        /* media file */
        case MEDPLY_DB_ACT_QUERY_MEDIA_MAX_ID:
        case MEDPLY_DB_ACT_QUERY_MEDIA_PATH:
        case MEDPLY_DB_ACT_QUERY_MEDIA_TOTAL:
        case MEDPLY_DB_ACT_QUERY_MEDIA_BASIC_INFO:
        case MEDPLY_DB_ACT_QUERY_MEDIA_LIST_INFO:
        case MEDPLY_DB_ACT_QUERY_MEDIA_EXIST_EXT:
        case MEDPLY_DB_ACT_QUERY_MEDIA_FULL_INFO:
        case MEDPLY_DB_ACT_QUERY_MEDIA_DISPLAY_INFO:
        case MEDPLY_DB_ACT_QUERY_MEDIA_ARTIST_NAME:  
        case MEDPLY_DB_ACT_MODIFY_MEDIA_ADD:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_DELETE:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_MODIFY:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_UPDATE_TIME:
        case MEDPLY_DB_ACT_MODIFY_MEDIA_INCREACE_COUNT:
        case MEDPLY_DB_ACT_MODIFY_ADD_TO_RECENT:
        case MEDPLY_DB_ACT_QUERY_PATH_BY_PLST_IDX:

        case MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART1:  //new
        case MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART2:  //new 
        case MEDPLY_DB_ACT_MODIFY_BMK_ADD:
        case MEDPLY_DB_ACT_MODIFY_BMK_REMOVE:
        case MEDPLY_DB_ACT_QUERY_BMK_TOTAL:
        case MEDPLY_DB_ACT_QUERY_BMK_LIST:
        case MEDPLY_DB_ACT_QUERY_BMK_INFO:           //new
        case MEDPLY_DB_ACT_QUERY_BMK_URL:
        case MEDPLY_DB_ACT_QUERY_BMK_EXIST:
        case MEDPLY_DB_ACT_MODIFY_BMK_CLEAR:
        case MEDPLY_DB_ACT_MODIFY_ITEM_APPEND:
            ret = mmi_medply_db_action_single(action, in_para1, in_para2, in_para3);
            break;
        default :
            MMI_ASSERT(action < MEDPLY_DB_ACT_END);
            break;
    }
#ifdef PERFORMANCE_MONITOR    
    __time2 = mmi_medply_get_current_time();
    cost = (__time2 - __time1);
#endif
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_ACTION_RESULT, action, ret, cost, line);

    return ret;
}

#define DB_ACTION0(c)           mmi_medply_db_action(c, NULL, NULL, NULL, __LINE__);
#define DB_ACTION1(c, x)        mmi_medply_db_action(c, x, NULL, NULL, __LINE__);
#define DB_ACTION2(c, x, y)     mmi_medply_db_action(c, x, y, NULL, __LINE__);
#define DB_ACTION3(c, x, y, z)  mmi_medply_db_action(c, x, y, z, __LINE__);

#define __DB_INIT__
extern kal_bool nvram_get_imei_value(kal_uint8 length, kal_uint8 *imei_buf, kal_uint16 rec_index);
/*****************************************************************************
* FUNCTION
*  mmi_medply_util_get_imei
* DESCRIPTION
*  get current target's imei
* PARAMETERS
*  void
* RETURNS
*  U32
*****************************************************************************/
static U32 mmi_medply_util_get_imei(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type imei_ucs2_buffer[16];
    U8 imei_buf[8];
    CHAR imei_ascii_buffer[8 * 2];

    S32 i;
    S32 len;
    U16 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_get_imei_value(8, imei_buf, 1);
    for (i = 0; i < 8; i++)
    {
        imei_ascii_buffer[i * 2] = 0x30 + (imei_buf[i] & 0x0F);
        imei_ascii_buffer[(i * 2) + 1] = 0x30 + (imei_buf[i] >> 4);
    }
    /* add terminated character. */
    imei_ascii_buffer[(i * 2) - 1] = 0;

    len = strlen((CHAR*)imei_ascii_buffer);

    ASSERT(len == 15);  /* imei is 15 bits. */

    ret = mmi_asc_n_to_ucs2((CHAR*)imei_ucs2_buffer, (CHAR*)imei_ascii_buffer, (U32)len);

    ASSERT(ret == (len * 2));
    /* add terminated character. */
    imei_ucs2_buffer[len] = 0; 

    return (U32)app_ucs2_wtoi(imei_ucs2_buffer);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_get_default_drv_serial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_medply_util_get_default_drv_serial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    UI_character_type drv_path[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    return 1234567890;
#endif
    if (FS_GetDevStatus(MMI_MEDPLY_DB_DEFAULT_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
        kal_wsprintf(drv_path, "%c:\\", MMI_MEDPLY_DB_DEFAULT_DRV);
        FS_GetDiskInfo(drv_path, &disk_info, FS_DI_BASIC_INFO);
        return disk_info.SerialNumber;
    }
    else
    {
        return 0;
    }
}

#include "SST_secure.h"
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_get_chip_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 mmi_medply_util_get_chip_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char buffer[16];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    return 1010101010;
#else
    if (SST_Get_ChipRID(buffer, 128))
    {
        return (U32)atoi(buffer);
    }
    else
    {
        return 1234567890;        
    }
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_util_get_target_info
* DESCRIPTION
*  
* PARAMETERS
*  out_data         [OUT]
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_util_get_target_info(mmi_medply_target_info_struct* out_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    out_data->version = MMI_MEDPLY_DB_VERSION_NUM;
	out_data->imei = mmi_medply_util_get_imei();
    out_data->default_drv_serial_num = mmi_medply_util_get_default_drv_serial();
    out_data->chip_id = mmi_medply_util_get_chip_id();
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_util_check_target_info
* DESCRIPTION
*  
* PARAMETERS
*  in_data         [IN]
* RETURNS
*  MMI_BOOL
*****************************************************************************/
static MMI_BOOL mmi_medply_util_check_target_info(mmi_medply_target_info_struct* in_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_data->version != MMI_MEDPLY_DB_VERSION_NUM)
        return MMI_FALSE;
	if (in_data->imei != mmi_medply_util_get_imei())
        return MMI_FALSE;
    if (in_data->default_drv_serial_num != mmi_medply_util_get_default_drv_serial())
        return MMI_FALSE;
    if (in_data->chip_id != mmi_medply_util_get_chip_id())
        return MMI_FALSE;
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_module_init_internal
* DESCRIPTION
*  check default fodler, create/open databse.
* PARAMETERS
*  void
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_plst_module_init_internal(MMI_BOOL del_old_file)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 fs_ret = FS_NO_ERROR;
    mmi_medply_target_info_struct target_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_INIT, plst_cntx_p->db_cntx.instance_initialized, plst_cntx_p->db_cntx.db_opend);

	if (!plst_cntx_p->list_module_ready)
	{
	  	memset(&plst_cntx, 0, sizeof(mmi_medply_plst_cntx_struct));
        mmi_medply_plst_util_drv_letter();
	}

    if (!plst_cntx_p->db_cntx.instance_initialized)
    {
        mmi_medply_db_sqlite3_init_instance();
    }

    if (!plst_cntx_p->db_cntx.db_opend)
    {
    	mmi_medply_util_entry_wait_scr();
        // check default folder.
        kal_wsprintf(plst_cntx_p->db_cntx.db_path, "%c:\\%w", 
        				MMI_MEDPLY_DB_DEFAULT_DRV, 
        				MMI_MEDPLY_DB_DEFAULT_FOLDER);

        fs_ret = FS_Open(plst_cntx_p->db_cntx.db_path, FS_READ_ONLY | FS_OPEN_DIR);

        if (fs_ret < 0)
        {
            fs_ret = FS_CreateDir(plst_cntx_p->db_cntx.db_path);
            if (fs_ret >= 0)
            {
                FS_SetAttributes(plst_cntx_p->db_cntx.db_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            }
            else
            {
                ret = fs_ret;
                goto plst_module_init_err_hdlr;
            }
        }
        else
        {
            FS_Close(fs_ret);
            FS_SetAttributes(plst_cntx_p->db_cntx.db_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            fs_ret = 0;
        }
		// compose database file path
        mmi_ucs2cat((CHAR*)plst_cntx_p->db_cntx.db_path, (const CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)plst_cntx_p->db_cntx.db_path, (const CHAR*)MMI_MEDPLY_DB_FILENAME);
        mmi_ucs2cat((CHAR*)plst_cntx_p->db_cntx.db_path, (const CHAR*)MMI_MEDPLY_DB_VERSION);
        mmi_ucs2cat((CHAR*)plst_cntx_p->db_cntx.db_path, (const CHAR*)MMI_MEDPLY_DB_EXTENSION);

        /* check exist */
        fs_ret = FS_GetAttributes(plst_cntx_p->db_cntx.db_path);

		if (fs_ret >= 0 && del_old_file)
        {
			/* remove read only attribute. */
            if (fs_ret & FS_ATTR_READ_ONLY)
            {
                fs_ret ^= FS_ATTR_READ_ONLY;
                FS_SetAttributes(plst_cntx_p->db_cntx.db_path, (BYTE)fs_ret);
            }
        	
            /* delete old database file. */
            fs_ret = FS_Delete(plst_cntx_p->db_cntx.db_path);

            /* set fs_ret to negative in order to trigger create new database file. */
            fs_ret = FS_FILE_NOT_FOUND;
        }

        if (fs_ret < FS_NO_ERROR)
        {        
            /* check disk space. */
			if (!mmi_medply_util_check_free_space(MMI_MEDPLY_DB_DEFAULT_DRV, MMI_MEDPLY_DB_MIN_DISK_SPACE))
            {
                ret = MEDPLY_PLST_ERR_NO_SPACE;
                goto plst_module_init_err_hdlr;
            }
            mmi_medply_util_get_target_info(&target_info);
            /* create file and open. */
            ret = mmi_medply_db_create(plst_cntx_p->db_cntx.db_path);
            if (ret != 0)
            {
                goto plst_module_init_err_hdlr;
            }

            /* config pragma */
			ret = mmi_mdeply_db_set_pragma();
            if (ret != 0)
            {
                goto plst_module_init_err_hdlr;
            }

            ret = DB_ACTION0(MEDPLY_DB_ACT_CREATE_TABLE);
            if (ret != 0)
            {
                goto plst_module_init_err_hdlr;
            }
            
            ret = DB_ACTION0(MEDPLY_DB_ACT_CREATE_DEFAULT);
            if (ret != 0)
            {
                goto plst_module_init_err_hdlr;
            }

            ret = DB_ACTION1(MEDPLY_DB_ACT_SET_TARGET_INFO, &target_info);
            if (ret != 0)
            {
                goto plst_module_init_err_hdlr;
            }
        }
        else
        {
        	fs_ret ^= FS_ATTR_READ_ONLY;
        	FS_SetAttributes(plst_cntx_p->db_cntx.db_path, (BYTE)fs_ret);
            /* check disk space. */
			if (!mmi_medply_util_check_free_space(MMI_MEDPLY_DB_DEFAULT_DRV, MMI_MEDPLY_DB_MIN_DISK_SPACE))
            {
                ret = MEDPLY_PLST_ERR_NO_SPACE;
                goto plst_module_init_err_hdlr;
            }
          
            ret = mmi_medply_db_open();

            if (ret != 0)
            {
				MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_OPEN_DB, ret);
                goto plst_module_init_err_hdlr;
            }

            /* config pragma */
			ret = mmi_mdeply_db_set_pragma();
            if (ret != 0)
            {
                goto plst_module_init_err_hdlr;
            }

            /* check database whether corrupted. */
            ret = DB_ACTION1(MEDPLY_DB_ACT_GET_TARGET_INFO, &target_info);
            if (ret < 0)
            {
				ret = MEDPLY_PLST_ERR_SQLITE_CORRUPT;
                goto plst_module_init_err_hdlr;
            }
            /* compare target info. */
            if (!mmi_medply_util_check_target_info(&target_info))
            {
                /* compare failed!!! */
                ret = MEDPLY_PLST_ERR_SQLITE_FORMAT;
                goto plst_module_init_err_hdlr;
            }
        }
    }

    //mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
    return ret;

plst_module_init_err_hdlr:
    
    if (plst_cntx_p->db_cntx.db_opend)
    {
        DB_ENABLE;
        mmi_medply_db_sqlite3_close();
        DB_DISABLE;
    }
    mmi_medply_db_sqlite3_free_instance();
    //mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_module_corrupt_quit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_module_corrupt_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(g_gid_medply);
    mmi_medply_asm_delete();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_module_corrupt_quit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_module_corrupt_delete_hdlr(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            kal_prompt_trace(MOD_MMI_MEDIA_APP,"[MEDPLY][LISTUI]mmi_medply_plst_module_corrupt_delete_hdlr.");
            if (plst_cntx_p->db_cntx.sqlite_buf == NULL)
            {
                mmi_medply_asm_delete();
            }
            break;
        }
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_module_corrupt_rebuild
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_module_corrupt_rebuild(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_plst_module_init_internal(MMI_TRUE);
	mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_NOTIFY_SCREEN);
    if (ret < 0)
    {    	
		mmi_medply_plst_popup_simple(ret);
        mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
        plst_cntx_p->list_module_ready = MMI_FALSE;
        mmi_medply_asm_delete();
    }
	else
    {
    	plst_cntx_p->list_module_ready = MMI_TRUE;
    	mmi_medply_plst_load_last();
		mmi_medply_entry_main_menu();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_module_corrupt_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_module_corrupt_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_MODULE_REBUILD, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_MODULE_REBUILD, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_medply_plst_confirm(
        GRP_ID_MEDPLY_PLST_MODULE_REBUILD,
        (WCHAR *)get_string(STR_ID_MEDPLY_PLST_NOTIFY_ASKREBUILD),
        MEDPLY_PLST_MODULE_REBUILD_CONFIRM,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_module_init
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL 
*****************************************************************************/
S32 mmi_medply_plst_module_init(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_plst_module_init_internal(MMI_FALSE);

    if (ret < 0)
    {    	
	    plst_cntx_p->list_module_ready = MMI_FALSE;
	    return ret;
    }
    else
    {
        plst_cntx_p->list_module_ready = MMI_TRUE;
        return 0;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_module_deinit
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL 
*****************************************************************************/
void mmi_medply_plst_module_deinit(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	S16 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_DEINIT);
    if (plst_cntx_p->list_module_ready)
    {       
    	/* generate cntx */
		mmi_medply_plstdb_generate_deinit();
        
        /* list cntx */
		if (IsMyTimerExist(MEDPLY_WAIT_NEXT_TIMER))
	    {
			StopTimer(MEDPLY_WAIT_NEXT_TIMER);
	    }

		if (plst_cntx_p->list_cntx.playing.bitset.data != NULL)
        {
     		kal_adm_free(g_medply.adm_id_p, plst_cntx_p->list_cntx.playing.bitset.data);
            MEM_TRC_FREE(plst_cntx_p->list_cntx.playing.bitset.data, __LINE__);
            plst_cntx_p->list_cntx.playing.bitset.data = NULL;   	
        }
        
		/* ui cntx */
		for (i = (MEDPLY_MAX_LIST_CACHE - 1); i >= 0; i--)
        {
			if (plst_cntx_p->ui_cntx.list_stack[i] != NULL)
            {
				kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.list_stack[i]);
                MEM_TRC_FREE(plst_cntx_p->ui_cntx.list_stack[i], __LINE__);
                plst_cntx_p->ui_cntx.list_stack[i] = NULL;
            }
        }
		if (IsMyTimerExist(MEDPLY_STATE_MACHINE_TIMER))
	    {
			StopTimer(MEDPLY_STATE_MACHINE_TIMER);
	    }
        if (IsMyTimerExist(MEDPLY_GENERATE_TIMER))
	    {
			StopTimer(MEDPLY_GENERATE_TIMER);
	    }
      	/* db cntx */
        if (plst_cntx_p->db_cntx.db_opend)
	    {
	        //rollback current transaction.
			if (plst_cntx_p->db_cntx.in_transaction)
	        {
	        	if (!plst_cntx_p->db_cntx.enable_count)
	            {    
	        		DB_ENABLE;
	            }
				DB_ROLLBACK_TRANSACTION;

	        }
			//disable if db is enable.
	        if (plst_cntx_p->db_cntx.enable_count)
	        { 
	        	DB_DISABLE;
	        }
            //close db 
			mmi_medply_db_close();

	        // set "read only" attribute for database file.
	        ret = FS_GetAttributes(plst_cntx_p->db_cntx.db_path);

			if (ret >= 0)
            {
	        	ret |= FS_ATTR_READ_ONLY;

	        	FS_SetAttributes(plst_cntx_p->db_cntx.db_path, (BYTE)ret);
	    	}
        }
		//free memory
	    if (plst_cntx_p->db_cntx.instance_initialized)
	    {
			mmi_medply_db_sqlite3_free_instance();
	    }
        //clear list module context
        memset(&plst_cntx, 0, sizeof(mmi_medply_plst_cntx_struct));
        plst_cntx_p->list_module_ready = MMI_FALSE;
	}
    mmi_medply_plst_clear_context_variables();
}

#define __DB_OP__
/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_allmedia_append
* DESCRIPTION
*  get target's meta data, check whether it is in db. 
*  compare and update if it is exist. append in otherwise.
* PARAMETERS
*  path                 [IN]
*  is_short             [IN]
*  target_list_id       [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_append_record(UI_string_type path, MMI_BOOL is_short, U32 target_list_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_db_media_meta_struct* meta_data = NULL;
    mmi_medply_db_media_base_struct* base_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	base_info = (mmi_medply_db_media_base_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_db_media_base_struct));
    if (base_info == NULL)
    {
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
    else
    {
        MEM_TRC_ALLOCATE(base_info, sizeof(mmi_medply_db_media_base_struct), __LINE__);
	    memset(base_info, 0, sizeof(mmi_medply_db_media_base_struct));

		mmi_medply_plst_get_base_info(path, base_info);
    }
    
#ifdef PARSE_FILE_IN_GENERATE	
	if (ret >= 0)
    {
	    meta_data = (mmi_medply_db_media_meta_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_db_media_meta_struct));
	    if (meta_data == NULL)
	    {
	        ret = MEDPLY_PLST_ERR_NO_MEMORY;
	    }
	    else
	    {
		    MEM_TRC_ALLOCATE(meta_data, sizeof(mmi_medply_db_media_meta_struct), __LINE__);
		    memset(meta_data, 0, sizeof(mmi_medply_db_media_meta_struct));

	        ret = mmi_medply_plst_get_meta_from_file(path, meta_data);
		}
    }
#endif	/* PARSE_FILE_IN_GENERATE */

    if (ret != MEDPLY_PLST_ERR_NO_MEMORY)    
    {
        ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_MEDIA_EXIST_EXT, &(base_info->path_hash));

        if (MEDPLY_PLST_GOT_DATA != ret)
    	{
    	    ret = DB_ACTION2(MEDPLY_DB_ACT_MODIFY_MEDIA_ADD, base_info, meta_data);  
    		
    	    if (ret >= 0)
    	    {
    	    	ret = DB_ACTION2(MEDPLY_DB_ACT_MODIFY_ITEM_APPEND, 
                    					   &(base_info->id), 
                    					   &(target_list_id));
    	    }
    	}
        else
        {
    		ret = MEDPLY_PLST_ERR_ITEM_EXISTS;
        }
    }
    
#ifdef PARSE_FILE_IN_GENERATE
	if (meta_data != NULL)
    {
	    kal_adm_free(g_medply.adm_id_p, meta_data);
	    MEM_TRC_FREE(meta_data, __LINE__);
	    meta_data = NULL;
    }
#endif	/* PARSE_FILE_IN_GENERATE */
	if (base_info != NULL)
    {
	    kal_adm_free(g_medply.adm_id_p, base_info);
	    MEM_TRC_FREE(base_info, __LINE__);
	    base_info = NULL;
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_db_append_record_ext
* DESCRIPTION
*  get target's meta data, check whether it is in db. 
*  compare and update if it is exist. append in otherwise.
* PARAMETERS
*  path                 [IN]
*  is_short             [IN]
*  target_list_id       [IN]
*  insert_idx           [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_db_append_record_ext(UI_string_type path, MMI_BOOL is_short, U32 target_list_id, U32 insert_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_db_media_meta_struct* meta_data = NULL;
    mmi_medply_db_media_base_struct* base_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	base_info = (mmi_medply_db_media_base_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_db_media_base_struct));
    if (base_info == NULL)
    {
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
    else
    {
        MEM_TRC_ALLOCATE(base_info, sizeof(mmi_medply_db_media_base_struct), __LINE__);
	    memset(base_info, 0, sizeof(mmi_medply_db_media_base_struct));

		mmi_medply_plst_get_base_info(path, base_info);
    }
    
#ifdef PARSE_FILE_IN_GENERATE	
	if (ret >= 0)
    {
	    meta_data = (mmi_medply_db_media_meta_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_db_media_meta_struct));
	    if (meta_data == NULL)
	    {
	        ret = MEDPLY_PLST_ERR_NO_MEMORY;
	    }
	    else
	    {
		    MEM_TRC_ALLOCATE(meta_data, sizeof(mmi_medply_db_media_meta_struct), __LINE__);
		    memset(meta_data, 0, sizeof(mmi_medply_db_media_meta_struct));

	        ret = mmi_medply_plst_get_meta_from_file(path, meta_data);
		}
    }
#endif	/* PARSE_FILE_IN_GENERATE */

    if (ret != MEDPLY_PLST_ERR_NO_MEMORY)    
    {
        ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_MEDIA_EXIST_EXT, &(base_info->path_hash));

        if (MEDPLY_PLST_GOT_DATA != ret)
    	{
    	    ret = DB_ACTION2(MEDPLY_DB_ACT_MODIFY_MEDIA_ADD, base_info, meta_data);  
    		
    	    if (ret >= 0)
    	    {
    	    	ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_ITEM_ADD_EXT, 
                    					   &(base_info->id), 
                    					   &(target_list_id),
                    					   &(insert_idx));
    	    }
    	}
        else
        {
    		ret = MEDPLY_PLST_ERR_ITEM_EXISTS;
        }
    }
    
#ifdef PARSE_FILE_IN_GENERATE
	if (meta_data != NULL)
    {
	    kal_adm_free(g_medply.adm_id_p, meta_data);
	    MEM_TRC_FREE(meta_data, __LINE__);
	    meta_data = NULL;
    }
#endif	/* PARSE_FILE_IN_GENERATE */
	if (base_info != NULL)
    {
	    kal_adm_free(g_medply.adm_id_p, base_info);
	    MEM_TRC_FREE(base_info, __LINE__);
	    base_info = NULL;
    }
    return ret;
}
#define ___PROC

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_cui_hdlr_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plstui_cui_hdlr_menu(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 999, __LINE__);
            /*
            
            cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
            #endif
            cui_menu_set_currlist_left_softkey(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OK));
            */
            if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_LISTMGR_OPT)
            {
                mmi_medply_plstui_listmgr_opt_config(menu_evt);
                break;
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_LIST_OPT)
            {
                mmi_medply_plstui_playlist_opt_config(menu_evt);
                break;
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_MULTI_SELECT_MENU)
            {
                mmi_medply_plstui_multiselect_opt_config(menu_evt);
                break;
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_SEARCH_OPT)
            {
                mmi_medply_search_result_opt_config(menu_evt);
                break;
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_BOOKMARK_OPT)
            {
                mmi_medply_plstui_bmk_opt_config(menu_evt);
                break;
            }
            
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_LISTMGR_OPT)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 999, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_PLST_LISTMGR_OPT_LOAD:
                        mmi_medply_plstui_listmgr_opt_load();
                        break;
                    case MENU_ID_MEDPLY_PLST_LISTMGR_OPT_NEW:
                        mmi_medply_plstui_listmgr_opt_create_part_1();
                        break;
                    case MENU_ID_MEDPLY_PLST_LISTMGR_OPT_DELETE:
                        mmi_medply_plstui_listmgr_opt_delete_part_1();
                        break;
                    case MENU_ID_MEDPLY_PLST_LISTMGR_OPT_RENAME:
                        mmi_medply_plstui_listmgr_opt_rename_part_1();
                        break;
                }
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_LIST_OPT)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 999, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_PLAY:
                        mmi_medply_plstui_common_opt_initiate_play();
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_DETAILS:
                        mmi_medply_plstui_common_opt_details();
                        break;
                    case MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_UPDATE:
                        mmi_medply_plstui_allmedia_opt_update_part_1();
                        break;
                    case MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_ADD:
                        mmi_medply_plstui_allmedia_opt_add_part1();
                        break;
                    case MENU_ID_MEDPLY_PLST_LIST_OPT_ADD:
                        mmi_medply_plstui_playlist_opt_add();
                        break;
                    case MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE:
                        mmi_medply_plstui_playlist_opt_remove_part_1();
                        break;
                    case MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR:
                        mmi_medply_plstui_playlist_opt_clear_part_1();
                        break;
                    case MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST:
                        mmi_medply_plstui_playlist_opt_organize();
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_ADD_TO:
                        mmi_medply_plstui_common_opt_addto();
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND:
                        mmi_medply_plst_option_send(menu_evt);
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_USE:
                        mmi_medply_plst_option_use(menu_evt);
                        break;
                #ifdef __MMI_RMGR__
                    case MENU_ID_FMGR_GEN_OPTION_MORE_RITS:
                    {
                        FuncPtr menu_hdlr;
                        menu_hdlr = mmi_medply_util_get_menu_handler(menu_evt->highlighted_menu_id);
                        menu_hdlr();
                        mmi_rmgr_reset_ro_bound_path(NULL);
                        break;
                    }
                #endif
                #ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_INTRO:
                        mmi_medply_plstui_common_opt_intro();
                        break;
                #endif
                    case MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_SEARCH:
                        mmi_medply_plstui_allmedia_opt_search();
                        break;
                }
            }
            else if (menu_evt->parent_menu_id == playlistui_fwd_option_menu_id)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 999, __LINE__);
                mmi_medply_plst_fwd_select((U16)menu_evt->highlighted_menu_id);
                break;
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_MULTI_SELECT_MENU)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 999, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_MULTI_SELECT_ADD_MARKED:
                        mmi_medply_plstui_multiselect_opt_add_marked();
                        break;
                    case MENU_ID_MEDPLY_MULTI_SELECT_MARK_ALL:
                        mmi_medply_plstui_multiselect_opt_mark_all();
                        break;
                    case MENU_ID_MEDPLY_MULTI_SELECT_UNMARK_ALL:
                        mmi_medply_plstui_multiselect_opt_unmark_all();
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_SORT_BY:
                        /*not support*/
                        break;
                }

            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_SEARCH_OPT)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 999, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_PLST_SEARCH_OPT_PREVIEW:
                        mmi_medply_search_result_opt_preview();
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_DETAILS:
                        mmi_medply_plstui_common_opt_details();
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_ADD_TO:
                        mmi_medply_plstui_common_opt_addto();
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND:
                        mmi_medply_plst_option_send(menu_evt);
                        break;
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_USE:
                        mmi_medply_plst_option_use(menu_evt);
                        break;
                        
                #ifdef __MMI_RMGR__
                    case MENU_ID_FMGR_GEN_OPTION_MORE_RITS:
                    {
                        FuncPtr menu_hdlr;
                        menu_hdlr = mmi_medply_util_get_menu_handler(MENU_ID_FMGR_GEN_OPTION_MORE_RITS);
                        menu_hdlr();
                        mmi_rmgr_reset_ro_bound_path(NULL);
                        break;
                    }
                #endif
                #ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
                    case MENU_ID_MEDPLY_PLST_COMMON_OPT_INTRO:
                        mmi_medply_plstui_common_opt_intro();
                        break;
                #endif
                }
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_BOOKMARK_OPT)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, 999, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_PREVIEW:
                        mmi_medply_plstui_bmk_opt_preview();
                        break;
                    case MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_NEW:
                        mmi_medply_plstui_bmk_opt_new_part1();
                        break;
                    case MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_EDIT:
                        /* do not support */
                        break;
                    case MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_SAVE_RAM:
                        mmi_medply_plstui_bmk_opt_save_ram_part1();
                        break;
                    case MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETE:
                        mmi_medply_plstui_bmk_opt_delete_part1();
                        break;
                    case MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETEALL:
                        mmi_medply_plstui_bmk_opt_clear_part1();
                        break;
                }
            }

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_WANING,evt->evt_id ,menu_evt->parent_menu_id,menu_evt->highlighted_menu_id, __LINE__);
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            mmi_medply_plstui_list_cache_struct *list_p = mmi_medply_plstui_get_curr_list_cache();
            MMI_ASSERT(list_p != NULL);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_CLOSE,menu_evt->sender_id ,__LINE__);
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        
    }    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_cui_hdlr_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plstui_cui_hdlr_editor(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
/**********************Fs editor CUI event*************************/
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct *)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_EDITOR_CUI_SUBMIT,editor_evt->sender_id ,__LINE__);
            cui_fseditor_get_text(editor_evt->sender_id, (WCHAR*)&plst_cntx_p->ui_cntx.editor_cntx.editor_buffer[0], sizeof(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer));
            plst_cntx_p->ui_cntx.editor_cntx.done_func();
            cui_fseditor_close(editor_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct *)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_EDITOR_CUI_ABORT,editor_evt->sender_id ,__LINE__);
            cui_fseditor_close(editor_evt->sender_id);
            break;
        }
/**********************File name editor CUI event*************************/
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            cui_filename_editor_result_event_struct *editor_ret = (cui_filename_editor_result_event_struct *) evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_EDITOR_CUI_RESULT,editor_ret->sender_id ,editor_ret->result, __LINE__);
            if (editor_ret->result > 0)/*user complete*/
            {
                //U16 parent_data = cui_filename_editor_get_parent_data (editor_ret->sender_id);
                
                plst_cntx_p->ui_cntx.editor_cntx.done_func();
                cui_filename_editor_close(editor_ret->sender_id);
            }
            else if (editor_ret->result == 0)/*user cancel*/
            {
                cui_filename_editor_close(editor_ret->sender_id);
            }
            else/*editor_ret->result < 0 error happens*/
            {
                mmi_medply_plst_popup_simple_with_string(get_string(srv_fmgr_fs_error_get_string(editor_ret->result)), srv_fmgr_fs_error_get_popup_type(editor_ret->result));
            }
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_cui_hdlr_inline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plstui_cui_hdlr_inline(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
            
            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_DETAILS_EDIT))
            {
                switch(inline_evt->event_type)
                {
                    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                    {
                        U16 index = (U16)((inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE) - 1)/2;
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_NOTIFY,inline_evt->sender_id ,inline_evt->event_type ,__LINE__);
                        
                        plst_cntx_p->ui_cntx.details_cntx.edit_index = index;
                        plst_cntx_p->ui_cntx.details_cntx.highlighted_item = index;
                
                        break;
                    }
                    case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_NOTIFY,inline_evt->sender_id ,inline_evt->event_type ,__LINE__);
                
                        break;
                    }
                    default:
                        break;
                }
            }
            else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_SEARCH))
            {
                switch(inline_evt->event_type)
                {
                    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                    {
                        U16 index = (U16)((inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE) - 1)/2;
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_NOTIFY,inline_evt->sender_id ,inline_evt->event_type ,__LINE__);
                        
                        plst_cntx_p->search_cntx.edit_index = (U16)index;
                        plst_cntx_p->search_cntx.highlighted_item = (U16)index;
                
                        break;
                    }
                    case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_NOTIFY,inline_evt->sender_id ,inline_evt->event_type ,__LINE__);
                
                        break;
                    }
                    default:
                        break;
                }
            }
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct *)evt;

            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_DETAILS_EDIT))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ACTIVE,inline_evt->sender_id ,__LINE__);
                if (plst_cntx_p->ui_cntx.details_cntx.modify_flag != 0)
                {
                    cui_inline_set_screen_attributes(inline_evt->sender_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
                } 
            }
            else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_SEARCH))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ACTIVE,inline_evt->sender_id ,__LINE__);
                if (plst_cntx_p->search_cntx.s_title[0] != 0 ||
                    plst_cntx_p->search_cntx.s_artist[0] != 0 ||
                    plst_cntx_p->search_cntx.s_album[0] != 0 ||
                    plst_cntx_p->search_cntx.s_genre[0] != 0)
                {
                    cui_inline_set_screen_attributes(inline_evt->sender_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
                }
                else
                {
                    cui_inline_set_screen_attributes(inline_evt->sender_id, CUI_INLINE_RESET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
                }
            }
            break;
        }
        case EVT_ID_CUI_INLINE_CSK_PRESS: //only enabled when disable done
        {
            break;
        }
        case EVT_ID_CUI_INLINE_SET_KEY:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            U32 item = inline_evt->item_id;
            
            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_DETAILS_EDIT))
            {
                switch(item)
                {
                    case MEDPLY_DETAILS_META_USER_RATING_DISPLAY:
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SET_KEY,inline_evt->sender_id ,item ,__LINE__);
                        cui_inline_set_softkey_text(
                            inline_evt->sender_id, 
                            item, 
                            MMI_LEFT_SOFTKEY, 
                            STR_GLOBAL_EDIT);
                        SetLeftSoftkeyFunction(mmi_medply_details_entry_set_rate_scr, KEY_EVENT_UP);
                        cui_inline_set_softkey_icon(
                            inline_evt->sender_id, 
                            item, 
                            MMI_CENTER_SOFTKEY, 
                            IMG_GLOBAL_COMMON_CSK);
                        
                        SetCenterSoftkeyFunction(mmi_medply_details_entry_set_rate_scr, KEY_EVENT_UP);
                        break;
                    }
                    default:
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SET_KEY,inline_evt->sender_id ,item ,__LINE__);
                        cui_inline_set_softkey_text(
                            inline_evt->sender_id, 
                            item, 
                            MMI_LEFT_SOFTKEY, 
                            STR_GLOBAL_EDIT);
                        SetLeftSoftkeyFunction(mmi_medply_details_edit_function, KEY_EVENT_UP);
                        cui_inline_set_softkey_icon(
                            inline_evt->sender_id, 
                            item, 
                            MMI_CENTER_SOFTKEY, 
                            IMG_GLOBAL_COMMON_CSK);
                        
                        SetCenterSoftkeyFunction(mmi_medply_details_edit_function, KEY_EVENT_UP);
                        break;
                    }
                }

            }
            else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_SEARCH))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SET_KEY,inline_evt->sender_id ,item ,__LINE__);
                cui_inline_set_softkey_text(
                    inline_evt->sender_id, 
                    item, 
                    MMI_LEFT_SOFTKEY, 
                    STR_GLOBAL_EDIT);
                SetLeftSoftkeyFunction(mmi_medply_search_edit_function, KEY_EVENT_UP);
                cui_inline_set_softkey_icon(
                    inline_evt->sender_id, 
                    item, 
                    MMI_CENTER_SOFTKEY, 
                    IMG_GLOBAL_COMMON_CSK);
                
                SetCenterSoftkeyFunction(mmi_medply_search_edit_function, KEY_EVENT_UP);
            }
            
            break;
        }

        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_DETAILS_EDIT))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SUBMIT,inline_evt->sender_id ,__LINE__);
                mmi_medply_details_save_confirm();
            }
            else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_SEARCH))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SUBMIT,inline_evt->sender_id ,__LINE__);
                mmi_medply_search_action();
            }

            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*)evt;
            
            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_DETAILS_EDIT))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ABORT,inline_evt->sender_id ,__LINE__);
                cui_inline_close(inline_evt->sender_id);
                mmi_medply_details_edit_exit();
            }
            else if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_SEARCH))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ABORT,inline_evt->sender_id ,__LINE__);
                cui_inline_close(inline_evt->sender_id);
            }
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_cui_hdlr_fmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plstui_cui_hdlr_fmgr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_evt = (cui_file_selector_result_event_struct*)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_SELECTOR_CUI_RESULT,sel_evt->sender_id ,sel_evt->result, __LINE__);
            mmi_medlpy_plstui_allmedia_opt_add_selector_handle(sel_evt);
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_cui_hdlr_alert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plstui_cui_hdlr_alert(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *confirm = (mmi_alert_result_evt_struct *)evt;

            switch (confirm->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                case MMI_POPUP_INTERRUPT_EXIT:
                    break;
                case MMI_ALERT_CNFM_OK:  
                case MMI_ALERT_CNFM_YES:         
                {
                    switch ((S32)confirm->user_tag)
                    {
                        case MEDPLY_PLST_DETAILS_EDIT_CONFIRM:
                        {
                            mmi_medply_details_edit_save();
                            mmi_frm_group_close(GRP_ID_MEDPLY_PLST_DETAILS_EDIT);
                            break;
                        }
                        case MEDPLY_PLST_ORGANIZE_SAVE_CONFIRM:
                        {
                            mmi_medply_plstui_organize_save();
                            break;
                        }
                        case MEDPLY_PLST_SEARCH_RESULT_CONFIRM:
                        {
                            mmi_medply_search_reset();
                            break;
                        }
                        case MEDPLY_PLST_MODULE_REBUILD_CONFIRM:
                        {
                            mmi_medply_plst_module_corrupt_rebuild();
                            //mmi_alert_dismiss(confirm->alert_id);
                            break;
                        }
                        default:
                        {
                            ((FuncPtr)confirm->user_tag)();
                            break;
                        }
                    }
                    break;
                }
                case MMI_ALERT_CNFM_NO:         
                case MMI_ALERT_CNFM_CANCEL:      
                {
                    switch ((S32)confirm->user_tag)
                    {
                        case MEDPLY_PLST_DETAILS_EDIT_CONFIRM:
                        {
                            mmi_medply_details_edit_resaved();
                            mmi_frm_group_close(GRP_ID_MEDPLY_PLST_DETAILS_EDIT);
                            break;
                        }
                        case MEDPLY_PLST_ORGANIZE_SAVE_CONFIRM:
                        {
                            mmi_medply_plstui_organize_resaved();
                            break;
                        }
                        case MEDPLY_PLST_SEARCH_RESULT_CONFIRM:
                        {
                            mmi_medply_search_exit();
                            break;
                        }
                        case MEDPLY_PLST_MODULE_REBUILD_CONFIRM:
                        {
                            mmi_medply_plst_module_corrupt_quit();
                            break;
                        }
                        default:
                        {
                            //mmi_alert_dismiss(confirm->alert_id);
                            break;
                        }
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
    }    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plstui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
/*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            return mmi_medply_plstui_cui_hdlr_menu(evt);

/**********************Editor CUI event*************************/
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
            return mmi_medply_plstui_cui_hdlr_editor(evt);
            
/**********************Inline CUI event*************************/
        case EVT_ID_CUI_INLINE_NOTIFY:
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SET_KEY:
            return mmi_medply_plstui_cui_hdlr_inline(evt);
            
/**********************File selector CUI event*************************/
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
            return mmi_medply_plstui_cui_hdlr_fmgr(evt);
            
/**********************Alert CUI event*************************/
        case EVT_ID_ALERT_QUIT:
            return mmi_medply_plstui_cui_hdlr_alert(evt);
            
        default:
            break;
    }
    
    return MMI_RET_OK;
}


#define ___DETAILS
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_make_date_time_string
 * DESCRIPTION
 *  make date and time to a string as current format which set in phone settings.
 * PARAMETERS
 *  out_string		[OUT]
 *	time			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_make_date_time_string(UI_string_type out_string, mmi_medply_time_record_struct time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type seperator = 0;
    UI_character_type time_string[20];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* date */
    switch (PhnsetGetDateSeperatorFormat())
    {
        case 0:
            seperator = L'.';
            break;

        case 1:
            seperator = L':';
            break;

        case 2:
            seperator = L'/';
            break;

        case 3:
            seperator = L'-';
            break;

        default:
            seperator = L'.';
            break;
    }

    switch (PhnsetGetDateFormat())  /* Get the current format of date */
    {
        case 0: /* day, month, year */
            kal_wsprintf(out_string, "%02d%c%02d%c%02d", time.day, seperator, time.month, seperator, time.year);
            break;

        case 1:
            kal_wsprintf(out_string, "%02d%c%02d%c%02d", time.month, seperator, time.day, seperator, time.year);
            break;

        case 2:
            kal_wsprintf(out_string, "%02d%c%02d%c%02d", time.year, seperator, time.month, seperator, time.day);
            break;
    }
    /* time */
	if (PhnsetGetTimeFormat())
    {
        kal_wsprintf(time_string, "%02d:%02d", time.hour, time.min);
    }
    else
    {
        if (time.hour == 12)
        {
            kal_wsprintf(time_string, "%02d:%02d PM", time.hour, time.min);
        }
        else if (time.hour == 0)
        {
            kal_wsprintf(time_string, "%02d:%02d AM", 12, time.min);
        }
        else if (time.hour > 12)
        {
            kal_wsprintf(time_string, "%02d:%02d PM", time.hour - 12, time.min);
        }
        else
        {
            kal_wsprintf(time_string, "%02d:%02d AM", time.hour, time.min);
        }
    }

    /* compose */
    mmi_ucs2cat((CHAR*)out_string, (const CHAR*)L" ");
    mmi_ucs2cat((CHAR*)out_string, (const CHAR*)time_string);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_set_rate_scr_highlight_hdlr
 * DESCRIPTION
 *  highlight handler.
 * PARAMETERS
 *  index 		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_set_rate_scr_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plst_cntx_p->ui_cntx.details_cntx.set_rate_scr_higlight_index = (U8)index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_set_rate_scr_done
 * DESCRIPTION
 *  done function of set rate screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_set_rate_scr_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 rating_string_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_MEDPLY_PLST_SET_RATE)
    {
		plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_RATING;
		switch (plst_cntx_p->ui_cntx.details_cntx.set_rate_scr_higlight_index)
		{
		case 0:
			rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_0;
			break;
		case 1:
			rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_1_EXT;
			break;
		case 2:
			rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_2_EXT;
			break;
		case 3:
			rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_3_EXT;
			break;
		case 4:
			rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_4_EXT;
			break;
		case 5:
			rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_5_EXT;
			break;
		default:
			MMI_ASSERT(plst_cntx_p->ui_cntx.details_cntx.set_rate_scr_higlight_index <= 5);
		}
		mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, (const CHAR*)GetString(rating_string_id), MMI_MEDPLY_MAX_USER_RATING_LEN - 1);		
		mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_entry_set_rate_scr
 * DESCRIPTION
 *  screen to set rating.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_entry_set_rate_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    U8  nNumofItems = 6;
    U16 nStrItemLists[6] = 
        {     
        	STR_ID_MEDPLY_PLST_DETAILS_STAR_0,
        	STR_ID_MEDPLY_PLST_DETAILS_STAR_1_EXT,
		    STR_ID_MEDPLY_PLST_DETAILS_STAR_2_EXT,
		    STR_ID_MEDPLY_PLST_DETAILS_STAR_3_EXT,
		    STR_ID_MEDPLY_PLST_DETAILS_STAR_4_EXT,
		    STR_ID_MEDPLY_PLST_DETAILS_STAR_5_EXT
		};
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_DETAILS_EDIT, GRP_ID_MEDPLY_PLST_SET_RATE, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_SET_RATE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_PLST_SET_RATE, 
        SCR_ID_MEDPLY_PLST_SET_RATE, 
        NULL, 
        mmi_medply_details_entry_set_rate_scr, 
        MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_SET_RATE, SCR_ID_MEDPLY_PLST_SET_RATE);
	if (guiBuffer == NULL)
	{
		U16 rating = 0;
		if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
			(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_0)))
		{
			rating = 0;
		}
		else
		{
			if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_1_EXT)))
			{
				rating = 1;
			}
			else if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_2_EXT)))
			{
				rating = 2;
			}
			else if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_3_EXT)))
			{
				rating = 3;
			}
			else if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_4_EXT)))
			{
				rating = 4;
			}
			else if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_5_EXT)))
			{
				rating = 5;
			}
			else
			{
				MMI_ASSERT(0);
			}
		}
		plst_cntx_p->ui_cntx.details_cntx.set_rate_scr_higlight_index = rating;
	}
    RegisterHighlightHandler(mmi_medply_details_set_rate_scr_highlight_hdlr);
    
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory11Screen(
        STR_ID_MEDPLY_PLST_SET_RATING,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItems,
        nStrItemLists,
        (U16)plst_cntx_p->ui_cntx.details_cntx.set_rate_scr_higlight_index,
        guiBuffer);
    
    SetCenterSoftkeyFunction(mmi_medply_details_set_rate_scr_done, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_medply_details_set_rate_scr_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_edit_resaved
 * DESCRIPTION
 *  resaved from backup data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_edit_resaved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(plst_cntx_p->ui_cntx.details_cntx.preview_data_p, 
    	   plst_cntx_p->ui_cntx.details_cntx.preview_backup_p, 
    	   sizeof(mmi_medply_details_preview_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_edit_save
 * DESCRIPTION
 *  save modified details.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_edit_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rating = 0;
	S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     

	if (!(plst_cntx_p->ui_cntx.details_cntx.modify_flag & MEDPLY_DB_UPDATE_MODIFIED))
    {
		plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_MODIFIED;
    }

	if (plst_cntx_p->ui_cntx.details_cntx.modify_flag & MEDPLY_DB_UPDATE_RATING)
    {
		if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
			(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_0)))
		{
			rating = 0;
		}
		else
		{
			if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_1_EXT)))
			{
				rating = 1;
			}
			else if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_2_EXT)))
			{
				rating = 2;
			}
			else if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_3_EXT)))
			{
				rating = 3;
			}
			else if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_4_EXT)))
			{
				rating = 4;
			}
			else if (!mmi_ucs2icmp((const CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, 
				(const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_5_EXT)))
			{
				rating = 5;
			}
			else
			{
				MMI_ASSERT(0);
			}
		}
		plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->user_rating = rating;
    }
   
    ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_MEDIA_MODIFY,
    				&(plst_cntx_p->ui_cntx.details_cntx.media_id), 
        			&(plst_cntx_p->ui_cntx.details_cntx.modify_flag), 
        			(void*)(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p));

    if (ret != 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
		/* update last modified time. */
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_modified[0] = 0;
        mmi_medply_details_make_date_time_string(
                plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_modified, 
                plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->last_modified);
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);

        /* update idle string if edited now playing file's details. */
        if (plst_cntx_p->ui_cntx.details_cntx.media_id == plst_cntx_p->list_cntx.playing.id)
        {
			mmi_medply_util_fill_idle_display_str();
        }
		if (plst_cntx_p->ui_cntx.details_cntx.initiate_scr_id != SCR_ID_MEDPLY_PLST_PLAYLIST)
		{
            mmi_medply_plstui_clear_list_cache(SCR_ID_MEDPLY_PLST_PLAYLIST);
		}
        mmi_medply_plstui_clear_list_cache(plst_cntx_p->ui_cntx.details_cntx.initiate_scr_id);
    }	
}
 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_save_confirm
 * DESCRIPTION
 *  ask user whether want to save.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID parent_gid = GRP_ID_ROOT;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_PLAYLIST))
    {
        parent_gid = GRP_ID_MEDPLY_PLST_PLAYLIST; 
    }
    else if (mmi_frm_group_is_present(g_gid_medply))
    {
        parent_gid = g_gid_medply; 
    }

    mmi_frm_group_create(parent_gid, GRP_ID_MEDPLY_PLST_DETAILS_SAVE_CONFIRM, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_DETAILS_SAVE_CONFIRM, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_medply_plst_confirm(
        GRP_ID_MEDPLY_PLST_DETAILS_SAVE_CONFIRM,
        (WCHAR *)get_string(STR_GLOBAL_SAVE_ASK),
        MEDPLY_PLST_DETAILS_EDIT_CONFIRM,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_check_modification
 * DESCRIPTION
 *  check which column has been modified
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_details_check_modification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MEDPLY_PLST_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_ucs2ncmp((const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.original_string_p,
        			 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
        			 plst_cntx_p->ui_cntx.editor_cntx.limit))
	{
		switch (plst_cntx_p->ui_cntx.details_cntx.edit_index)
	    {
			case MEDPLY_DETAILS_META_TITLE:
                plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_TITLE;
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->title,
                    		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                    		 plst_cntx_p->ui_cntx.editor_cntx.limit);
                break;
	   		case MEDPLY_DETAILS_META_ARTIST:
                plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_ARTIST;
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->artist,
                    		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                    		 plst_cntx_p->ui_cntx.editor_cntx.limit);
                break;
	    	case MEDPLY_DETAILS_META_ALBUM:
                plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_ALBUM;
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->album,
                     		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                     		 plst_cntx_p->ui_cntx.editor_cntx.limit);
                break;
		    case MEDPLY_DETAILS_META_GENRE:
                plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_GENRE;
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->genre,
                    		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                    		 plst_cntx_p->ui_cntx.editor_cntx.limit);
                break;
		    case MEDPLY_DETAILS_META_AUTHOR:
                plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_AUTHOR;
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->author,
                    		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                    		 plst_cntx_p->ui_cntx.editor_cntx.limit);
                break;
		    case MEDPLY_DETAILS_META_DESCRIPTION: 
                plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_DESCRIPTION;
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->description,
                    		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                    		 plst_cntx_p->ui_cntx.editor_cntx.limit);
                break;
		    case MEDPLY_DETAILS_META_TRACK_NUM:
                {
                    if (mmi_ucs2strlen((const CHAR*) plst_cntx_p->ui_cntx.editor_cntx.editor_buffer) > 0)
                    {   
                        S16 new_track_num = 0;
                        new_track_num = (S16)app_ucs2_wtoi(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
                    
                        if (new_track_num > 0)
                        {
                            plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_TRACKNUM;
                            plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->track_num = new_track_num;
                            app_ucs2_itow(new_track_num, plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 10);
                        }
                        else
                        {
                            /* invalid input. */
                            ret = MEDPLY_PLST_ERR_INVALID_INPUT;
                        }
                    }
                    else
                    {
                        plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_TRACKNUM;
                        plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->track_num = -1;
                    }
                    
                }
                break;
		    case MEDPLY_DETAILS_META_YEAR:
                {
                    if (mmi_ucs2strlen((const CHAR*) plst_cntx_p->ui_cntx.editor_cntx.editor_buffer) > 0)
                    {                    
                        S16 new_year = 0;
                        new_year = (S16)app_ucs2_wtoi(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);

                        if (new_year >= 0)
                        {
                            plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_YEAR;
                            plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->year = new_year;
                            app_ucs2_itow(new_year, plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 10);
                        }
                        else
                        {
                            /* invalid inupt. */
                            ret = MEDPLY_PLST_ERR_INVALID_INPUT;
                        }
                    }
                    else
                    {
                        plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_YEAR;
                        plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->year = -1;
                    }
                }
                break;
		    /*case MEDPLY_DETAILS_META_USER_RATING:
                plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_RATING;
                break;*/
		    /*case MEDPLY_DETAILS_META_VOLUME:
                plst_cntx_p->ui_cntx.details_cntx.modify_flag |= MEDPLY_DB_UPDATE_VOL;
                break;*/
	        default:
	            break;
	    }
        if (!(ret < MEDPLY_PLST_NO_ERROR))
        {
            /* copy new string back. */
            mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.original_string_p, 
            			 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
            			 plst_cntx_p->ui_cntx.editor_cntx.limit);
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_numeric_done_func
 * DESCRIPTION
 *  done function for edit numeric column.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_numeric_done_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MEDPLY_PLST_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_details_check_modification();

    if (ret == MEDPLY_PLST_NO_ERROR)
    {
	    mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_medply_plst_popup_simple(ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_text_done_func
 * DESCRIPTION
 *  done function for edit text column.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_text_done_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_medply_details_check_modification();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_edit_function
 * DESCRIPTION
 *  edit function for edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_edit_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 limit = 0;
    U16 editor_title_id = 0;
    U8  editor_type = 0;

    UI_string_type original_string_p = NULL;
    UI_string_type initial_value = NULL;
	FuncPtr done_func = NULL;
    U16 parent_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = GRP_ID_MEDPLY_PLST_DETAILS_EDIT;
	switch (plst_cntx_p->ui_cntx.details_cntx.edit_index)
	{
		case MEDPLY_DETAILS_META_TITLE:
	        limit = MMI_MEDPLY_MAX_TITLE_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_TITLE;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->ui_cntx.details_cntx.preview_data_p->title;
	        break;
		case MEDPLY_DETAILS_META_ARTIST:
	        limit = MMI_MEDPLY_MAX_ARTISRT_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_ARTIST;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->ui_cntx.details_cntx.preview_data_p->artist;
	        break;
		case MEDPLY_DETAILS_META_ALBUM:
	        limit = MMI_MEDPLY_MAX_ALBUM_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_ALBUM;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->ui_cntx.details_cntx.preview_data_p->album;
	        break;
	    case MEDPLY_DETAILS_META_GENRE:
	        limit = MMI_MEDPLY_MAX_GENRE_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_GENRE;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->ui_cntx.details_cntx.preview_data_p->genre;
	        break;
	    case MEDPLY_DETAILS_META_AUTHOR:
	        limit = MMI_MEDPLY_MAX_AUTHOR_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_AUTHOR;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->ui_cntx.details_cntx.preview_data_p->author;
	        break;
	    case MEDPLY_DETAILS_META_DESCRIPTION:
	        limit = MMI_MEDPLY_MAX_DESCRIPTION_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_DESCRIPTION;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->ui_cntx.details_cntx.preview_data_p->description;
	        break;
	        
	    case MEDPLY_DETAILS_META_TRACK_NUM:
	        limit = MMI_MEDPLY_MAX_TRACKNUM_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_TRACK_NUM;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_NUMERIC;
            original_string_p = plst_cntx_p->ui_cntx.details_cntx.preview_data_p->track_num;
	        break;
	    case MEDPLY_DETAILS_META_YEAR:
	        limit = MMI_MEDPLY_MAX_YEAR_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_YEAR;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_NUMERIC;
            original_string_p = plst_cntx_p->ui_cntx.details_cntx.preview_data_p->year;
	        break;
	    /*case MEDPLY_DETAILS_META_VOLUME: 
	        limit = 5 - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_VOLUME;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_NUMERIC;
	        break;*/
	    default:
			MMI_ASSERT(0);
	}

	if (limit > MMI_MEDPLY_MAX_EDITOR_LEN)
	{
		limit = MMI_MEDPLY_MAX_EDITOR_LEN - 1;
	}

	if (editor_type > 0)
	{	
		initial_value = original_string_p;
	}
    if (editor_type == MMI_MEDPLY_EDITOR_EDIT_META_TEXT)
    {
		done_func = mmi_medply_details_text_done_func;
	}
    else
    {
    	done_func = mmi_medply_details_numeric_done_func;
	}
    mmi_medply_editor_create(
                parent_id,
    			editor_type,
    			limit,
    			editor_title_id,
    			original_string_p,
    			initial_value,
    			done_func);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_edit_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_medply_details_edit_exit(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    plst_cntx_p->ui_cntx.details_cntx.highlighted_item = 0;
    plst_cntx_p->ui_cntx.details_cntx.edit_index = 0;
    plst_cntx_p->ui_cntx.details_cntx.modify_flag = 0;
    
    if (plst_cntx_p->ui_cntx.details_cntx.preview_backup_p)
    {
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.details_cntx.preview_backup_p);
        MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.preview_backup_p, __LINE__);
        plst_cntx_p->ui_cntx.details_cntx.preview_backup_p = NULL;
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_edit_delete_hdlr
 * DESCRIPTION
 *  edit screen delete callback handler.
 * PARAMETERS
 *  in_param		[IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_medply_details_edit_delete_hdlr(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            plst_cntx_p->ui_cntx.details_cntx.highlighted_item = 0;
            plst_cntx_p->ui_cntx.details_cntx.edit_index = 0;
            plst_cntx_p->ui_cntx.details_cntx.modify_flag = 0;
            
            if (plst_cntx_p->ui_cntx.details_cntx.preview_backup_p)
            {
                kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.details_cntx.preview_backup_p);
                MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.preview_backup_p, __LINE__);
                plst_cntx_p->ui_cntx.details_cntx.preview_backup_p = NULL;
            }   
            break;
        }
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_set_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_set_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[MEDPLY_PLST_INLINE_ITEM_NUM];
    U16 item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/***********************************set string******************************************/
    /* title. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_TITLE_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->title);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;
    
    /* artist. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_ARTIST_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->artist);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* album. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_ALBUM_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->album);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* genre */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_GENRE_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->genre);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* author. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_AUTHOR_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->author);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* description. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_DESCRIPTION_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->description);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* track number. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_TRACK_NUM_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->track_num);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* year. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_YEAR_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->year);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* rate. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_USER_RATING_DISPLAY, 
        plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;
    
    /***********************************set icon******************************************/
    cui_inline_set_icon_list(inline_id, &item_icons[0]);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_entry_edit_scr
 * DESCRIPTION
 *  prepare memory and data for edit screen.
 * PARAMETERS
 *  void	
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_entry_edit_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* init details variables. */
    plst_cntx_p->ui_cntx.details_cntx.highlighted_item = 0;
    plst_cntx_p->ui_cntx.details_cntx.edit_index = 0;
    plst_cntx_p->ui_cntx.details_cntx.modify_flag = 0;

	/* prepare memory to backup all data before edit. */
    plst_cntx_p->ui_cntx.details_cntx.preview_backup_p = 
    	kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_details_preview_struct));
    if (plst_cntx_p->ui_cntx.details_cntx.preview_backup_p == NULL)
    {
    	mmi_medply_plst_popup_simple(MEDPLY_PLST_ERR_NO_MEMORY);
		return;
    }
    else
    {
		MEM_TRC_ALLOCATE(plst_cntx_p->ui_cntx.details_cntx.preview_backup_p, 
            			 sizeof(mmi_medply_details_preview_struct), __LINE__);
		memcpy(plst_cntx_p->ui_cntx.details_cntx.preview_backup_p, 
            	plst_cntx_p->ui_cntx.details_cntx.preview_data_p, 
            	sizeof(mmi_medply_details_preview_struct));
        plst_cntx_p->ui_cntx.details_cntx.set_rate_scr_higlight_index = 
            		plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->user_rating;
    }

    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_PLAYLIST))
    {
        mmi_frm_group_create(GRP_ID_MEDPLY_PLST_PLAYLIST, GRP_ID_MEDPLY_PLST_DETAILS_EDIT, mmi_medply_plstui_proc, (void*)NULL); 
    }
    else if (mmi_frm_group_is_present(g_gid_medply))
    {
        mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_DETAILS_EDIT, mmi_medply_plstui_proc, (void*)NULL); 
    }
    else
    {
        MMI_ASSERT(0);
    }
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_DETAILS_EDIT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = cui_inline_create(GRP_ID_MEDPLY_PLST_DETAILS_EDIT, &mmi_medply_plstui_inline_details_screen);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_inline_set_title_icon(cui_gid, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
        mmi_medply_details_set_value(cui_gid);
        cui_inline_run(cui_gid);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_DETAILS_PREVIEW, SCR_ID_MEDPLY_PLST_DETAILS_PREVIEW);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }

    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_reset_cntx
 * DESCRIPTION
 *  destory details context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_reset_cntx(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p)
    {
	    kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p);
	    MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p, __LINE__);
	    plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p = NULL;
	}	
	if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p)
    {
	    kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.details_cntx.preview_data_p);
	    MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.preview_data_p, __LINE__);
	    plst_cntx_p->ui_cntx.details_cntx.preview_data_p = NULL;
   	}
    memset(&(plst_cntx_p->ui_cntx.details_cntx), 0, sizeof(mmi_medply_details_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_preview_delete_hdlr
 * DESCRIPTION
 *  preview screen delete callback fucntion. free all asm memory and destory context.
 * PARAMETERS
 *  in_param       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_medply_details_preview_delete_hdlr(mmi_event_struct* evt)
{  
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            if (plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p)
            {
                kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p);
                MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p, __LINE__);
                plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p = NULL;
            }   
            
            if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p)
            {
                kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.details_cntx.preview_data_p);
                MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.preview_data_p, __LINE__);
                plst_cntx_p->ui_cntx.details_cntx.preview_data_p = NULL;
            }
            
            mmi_medply_details_reset_cntx();    
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_highlight_hdlr
 * DESCRIPTION
 *  change title as highlight text
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8)GetString(plst_cntx_p->ui_cntx.details_cntx.preview_title_id[index]));
    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_entry_preview_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void	
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_entry_preview_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 item_count = 0;
#ifdef DETAILS_SUPPORT_EDIT
    U16 lsk_str_id = STR_GLOBAL_EDIT;
#else
    U16 lsk_str_id = 0;
#endif /* DETAILS_SUPPORT_EDIT */

    CHAR *fields[MEDPLY_DETAIL_TOTAL];
    U16 item_icons[MEDPLY_DETAIL_TOTAL];
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_PLST_DETAILS_PREVIEW, SCR_ID_MEDPLY_PLST_DETAILS_PREVIEW, NULL, mmi_medply_details_entry_preview_ex, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_DETAILS_PREVIEW, SCR_ID_MEDPLY_PLST_DETAILS_PREVIEW);
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_PLST_DETAILS_PREVIEW,SCR_ID_MEDPLY_PLST_DETAILS_PREVIEW, mmi_medply_details_preview_delete_hdlr);

    RegisterHighlightHandler(mmi_medply_details_highlight_hdlr);

    /* filename. */           
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->filename[0] != 0)
    {
        fields[item_count] = (CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->filename;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_GLOBAL_FILENAME;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_FILENAME;
#endif
    }

    /* title. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->title[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->title;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_TITLE;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_TITLE;
#endif
    }

    /* artist. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->artist[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->artist;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_ARTIST;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_ARTIST;
#endif
    }

    /* album. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->album[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->album;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_ALBUM;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_ALBUM;
#endif
    }

    /* author. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->author[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->author;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_AUTHOR;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_AUTHOR;
#endif
    }

    /* genre */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->genre[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->genre;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_GENRE;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_GENRE;
#endif
    }

    /* copyrights. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->copyrights[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->copyrights;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS;
#endif
    }
    
    /* description. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->description[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->description;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_DESCRIPTION;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_DESCRIPTION;
#endif
    }

    /* year. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->year[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->year;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_YEAR;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_YEAR;
#endif
    }

    /* track number. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->track_num[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->track_num;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_TRACK_NUM;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_TRACK_NUM;
#endif
    }
    
    /* duration */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->duration[0] != 0)
    {    
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->duration;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_DURATION;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_DURATION;

#endif
    }

    /* size */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->size[0] != 0)
    {
        fields[item_count] = (CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->size;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_SIZE;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_SIZE;
#endif
    }
    
    /* quality */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->quality[0] != 0)
    {
        fields[item_count] = (CHAR*) plst_cntx_p->ui_cntx.details_cntx.preview_data_p->quality;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_QUALITY;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_QUALITY;
#endif
    }

    /* channel */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->channel_num[0] != 0)
    {
        fields[item_count] = (CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->channel_num;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_CHANNEL;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_CHANNEL;
#endif
    }

    /* play count. */   
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->play_count[0] != 0)
    {
        fields[item_count] = (CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->play_count;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_PLAY_COUNT;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_PLAY_COUNT;
#endif
    }
    
    /* user rating. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating[0] != 0)
    {
        fields[item_count] = (CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_USER_RATING;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_USER_RATING;
#endif
    }
    
    /* last played. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_played[0] != 0)
    {
        fields[item_count] = (CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_played;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_LAST_PLAYED;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_LAST_PLAYED;
#endif
    }
    
    /* last modified. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_modified[0] != 0)
    {
        fields[item_count] = (CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_modified;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_LAST_MODIFIED;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_LAST_MODIFIED;
#endif
    }

    
    /* local. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->local[0] != 0)
    {
        fields[item_count] = (CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->local;
        plst_cntx_p->ui_cntx.details_cntx.preview_title_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_LOCAL;
#ifdef __MMI_SLIM_IMG_RES__
        item_icons[item_count] = IMG_GLOBAL_L1 + item_count;
        item_count++;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_LOCAL;
#endif
    }

#ifdef DETAILS_SUPPORT_EDIT
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif    

    ShowCategory84Screen(
        STR_GLOBAL_DETAILS,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),    /* title text and icon */
        lsk_str_id,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        item_count,
        (U8 **) fields,
        item_icons,
        0,
        0,
        guiBuffer);
#ifdef DETAILS_SUPPORT_EDIT
    SetCenterSoftkeyFunction(mmi_medply_details_entry_edit_scr, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_medply_details_entry_edit_scr, KEY_EVENT_UP);
#endif    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);


}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_entry_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void	
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_details_entry_preview(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_PREVIEW);

    if (parent_id == GRP_ID_INVALID)
    {
        parent_id = GRP_ID_ROOT;
    }

    mmi_frm_group_create(parent_id, GRP_ID_MEDPLY_PLST_DETAILS_PREVIEW, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_DETAILS_PREVIEW, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_medply_details_entry_preview_ex();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_fill_common_info
 * DESCRIPTION
 *  get common info from file system, filemgr and MDI.
 * PARAMETERS
 *  media_path	
 * RETURNS
 *  S32		should handle this value if return error!!! 
 *****************************************************************************/
static S32 mmi_medply_details_fill_common_info(UI_string_type in_media_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	FS_HANDLE handle = -1;
    U32 duration = 0;
    U32 file_size = 0;
    CHAR* filename_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MAUI_01764564, driver name,file name and duration maybe valid even DRM open file */

    /* fill "local". */
    srv_fmgr_drv_get_name((U8)(in_media_path[0]), (WCHAR*)((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->local), MEDPLY_MAX_FILE_LEN - 1);
    
    /* fill "filename". */
    filename_p = mmi_ucs2rchr((const CHAR*)in_media_path, (U16)L'\\');
    
    if (filename_p != NULL)
    {
        filename_p += 2;
        mmi_medply_util_extract_filename(plst_cntx_p->ui_cntx.details_cntx.preview_data_p->filename, in_media_path);
        srv_fmgr_path_hide_extension((WCHAR*)((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->filename));
    }
    
    /* fill "duration" if it is empty. */
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p->duration[0] == 0)
    {
        mdi_audio_get_duration(in_media_path, &duration);
        if (duration)
        {
            duration += 500;
            duration /= 1000;
            if (duration < 3600)
            {
                U16 min = duration / 60;
                U16 sec = duration % 60;
                
                kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->duration, "%02d:%02d", min, sec);
            }
            else
            {
                U16 hour = duration / 3600;
                U16 min = (duration - hour * 3600) / 60;
                U16 sec = (duration - hour * 3600) % 60;
                
                kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->duration, "%d:%02d:%02d", hour, min, sec);
            }
        }
    }

    /* get file size. */
    handle = DRM_open_file((PU16)in_media_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
    
    if (handle < 0)
    {
        ret = handle;
    }
    else
    {
        DRM_file_size(handle, &file_size);
        DRM_close_file(handle);

        /* fill "size". */
        if (file_size >= 1024*1024)
	    {
	        file_size = file_size/1024 ;
	        kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->size, "%d.%dM", file_size / 1024, (file_size % 1024) / 103);
	    }
	    else if (file_size >= 1024)
	    {
	        kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->size, "%d.%dK", file_size / 1024, (file_size % 1024) / 103);
	    }
	    else
	    {
	        kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->size, "%dB", file_size);
	    }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_fill_audio_info
 * DESCRIPTION
 *  get audio info from meta parser.
 * PARAMETERS
 *  media_path	
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_details_fill_audio_info(UI_string_type in_media_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;

    meta_tag_audio_info_struct* audio_info_p = NULL;
    MMI_BOOL audio_info_ready = MMI_FALSE;
    MMI_BOOL parser_ready = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get audio info from meta parser. */
    meta_parser_buffer = (PU8)kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
	if (meta_parser_buffer == NULL)
	{
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_NO_MEMORY, __LINE__);
		ret = MEDPLY_PLST_ERR_NO_MEMORY;
	}
    else
    {
		MEM_TRC_ALLOCATE(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);

        /* create meta parser. */
		meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);
	    if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
	    {
	    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_PREPARE_META, meta_parser_ret, __LINE__);
	    	ret = META_ERROR(meta_parser_ret);
	    }
        else
        {
        	parser_ready = MMI_TRUE;
			meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)in_media_path);
			if (meta_return_value != 0)
            {
		        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_PREPARE_META, meta_return_value, __LINE__);
                ret = META_ERROR(meta_return_value);
            }
            else
            {
				meta_return_value = meta_get_audio_info(meta_parser_hdlr, &audio_info_p);
                if (meta_return_value != 0)
                {
		          	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_PREPARE_META, meta_return_value, __LINE__);
	                ret = META_ERROR(meta_return_value);
                }
                else
                {
                	audio_info_ready = MMI_TRUE;
                }
			}
		}

        if (audio_info_ready)
        {
		    if (audio_info_p->channel_number != 0)
			{
			    if (audio_info_p->channel_number == 1)
			    {
			    	mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->channel_num,
                                 (const CHAR*)GetString(STR_ID_MEDPLY_PLST_DETAILS_MONO), 20 - 1);
			    }
			    else
			    {
			    	mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->channel_num,
                        		 (const CHAR*)GetString(STR_ID_MEDPLY_PLST_DETAILS_STEREO), 20 - 1);
			    }
			}
            
			if (audio_info_p->bits_rate > 0 || audio_info_p->sample_rate > 0)
			{
			    UI_character_type temp[30];
			    U16 bitrate_fraction_1, bitrate_fraction_2, bitrate_fraction_3;
			    U16 samplerate_fraction_1, samplerate_fraction_2, samplerate_fraction_3;
			    
			    if (audio_info_p->bits_rate > 0)
			    {
			        bitrate_fraction_1 = audio_info_p->bits_rate / 100;
			        bitrate_fraction_1 = bitrate_fraction_1 - (bitrate_fraction_1 / 10) * 10;
			        bitrate_fraction_2 = audio_info_p->bits_rate / 10;
			        bitrate_fraction_2 = bitrate_fraction_2 - (bitrate_fraction_2 / 10) * 10;
			        bitrate_fraction_3 = audio_info_p->bits_rate - (audio_info_p->bits_rate / 10) * 10 ;
			        if (bitrate_fraction_3)
			        {
			            kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->quality, "%d.%d%d%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1, bitrate_fraction_2, bitrate_fraction_3);
			        }
			        else if (bitrate_fraction_2)
			        {
			            kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->quality, "%d.%d%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1, bitrate_fraction_2);
			        }
			        else if (bitrate_fraction_1)
			        {
			            kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->quality, "%d.%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1);
			        }
			        else
			        {
			            kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->quality, "%dkbps", audio_info_p->bits_rate / 1000);
			        }
			        
			        if (audio_info_p->sample_rate > 0)
			        {
			            mmi_ucs2ncat((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->quality, (const CHAR*)L" / ", 3);
			        }
			    }
			    
			    if (audio_info_p->sample_rate > 0)
			    {
			        samplerate_fraction_1 = audio_info_p->sample_rate / 100;
			        samplerate_fraction_1 = samplerate_fraction_1 - (samplerate_fraction_1 / 10) * 10;
			        samplerate_fraction_2 = audio_info_p->sample_rate / 10;
			        samplerate_fraction_2 = samplerate_fraction_2 - (samplerate_fraction_2 / 10) * 10;
			        samplerate_fraction_3 = audio_info_p->sample_rate - (audio_info_p->sample_rate / 10) * 10 ;

			        if (samplerate_fraction_3)
			        {
			            kal_wsprintf((kal_wchar*) temp, "%d.%d%d%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1, samplerate_fraction_2, samplerate_fraction_3);
			        }
			        else if (samplerate_fraction_2)
			        {
			            kal_wsprintf((kal_wchar*) temp, "%d.%d%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1, samplerate_fraction_2);
			        }
			        else if (samplerate_fraction_1)
			        {
			            kal_wsprintf((kal_wchar*) temp, "%d.%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1);
			        }
			        else
			        {
			            kal_wsprintf((kal_wchar*) temp, "%dkHz", audio_info_p->sample_rate / 1000);
			        }
			        mmi_ucs2ncat((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->quality, (const CHAR*)temp, mmi_ucs2strlen((const CHAR*)temp));
			    }
			}

			if (audio_info_p->duration)
			{
			    if (audio_info_p->duration < 3600)
			    {
			        U16 min = audio_info_p->duration / 60;
			        U16 sec = audio_info_p->duration % 60;
			        
			        kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->duration, "%02d:%02d", min, sec);
			    }
			    else
			    {
			        U16 hour = audio_info_p->duration / 3600;
			        U16 min = (audio_info_p->duration - hour * 3600) / 60;
			        U16 sec = (audio_info_p->duration - hour * 3600) % 60;
			        
			        kal_wsprintf((kal_wchar*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->duration, "%d:%02d:%02d", hour, min, sec);
			    }
			}
        }

        if (parser_ready)
        {
            meta_parser_release(meta_parser_hdlr);
        }

	    kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
		MEM_TRC_FREE(meta_parser_buffer, __LINE__);
		meta_parser_buffer = NULL;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_details_prepare_data
 * DESCRIPTION
 *  get data from meta parser/database.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_details_prepare_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	MMI_BOOL raw_buffer_ready = MMI_FALSE;
   	MMI_BOOL preview_buffer_ready = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_PREPARE_DATA);

    /* prepare memory for raw data. */
    plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p = kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_db_media_struct));
    if (plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p== NULL)
    {
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_NO_MEMORY, __LINE__);
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
	else
   	{
   		MEM_TRC_ALLOCATE(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p, sizeof(mmi_medply_db_media_struct), __LINE__);
		raw_buffer_ready = MMI_TRUE;
		memset(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p, 0, sizeof(mmi_medply_db_media_struct));
    }

    /* prepare memory for details data. */
    plst_cntx_p->ui_cntx.details_cntx.preview_data_p = kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_details_preview_struct));
    if (plst_cntx_p->ui_cntx.details_cntx.preview_data_p == NULL)
    {
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_NO_MEMORY, __LINE__);
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
	else
   	{
   		MEM_TRC_ALLOCATE(plst_cntx_p->ui_cntx.details_cntx.preview_data_p, sizeof(mmi_medply_details_preview_struct), __LINE__);
		preview_buffer_ready = MMI_TRUE;
		memset(plst_cntx_p->ui_cntx.details_cntx.preview_data_p, 0, sizeof(mmi_medply_details_preview_struct));
    }

	if (raw_buffer_ready && preview_buffer_ready)
    {
    	/* get details data from database. */
	    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_FULL_INFO, &(plst_cntx_p->ui_cntx.details_cntx.media_id), (void*)(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p));

        if (ret >= 0)
        {
            mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->title, (const CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->title, MMI_MEDPLY_MAX_TITLE_LEN); 
            mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->album, (const CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->album, MMI_MEDPLY_MAX_ALBUM_LEN);
            mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->artist, (const CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->artist, MMI_MEDPLY_MAX_ARTISRT_LEN);
            mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->genre, (const CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->genre, MMI_MEDPLY_MAX_GENRE_LEN);
            mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->author, (const CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->author, MMI_MEDPLY_MAX_AUTHOR_LEN);
            mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->description, (const CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->description, MMI_MEDPLY_MAX_DESCRIPTION_LEN);
            mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->copyrights, (const CHAR*)plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->copyrights, MMI_MEDPLY_MAX_COPYRIGHTS_LEN);
			if (plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->year >= 0)
	        {
	        	kal_wsprintf(plst_cntx_p->ui_cntx.details_cntx.preview_data_p->year, "%d", plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->year);
	        }
	        else
	        {
				plst_cntx_p->ui_cntx.details_cntx.preview_data_p->year[0] = 0;
	        }

			if (plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->track_num > 0)
	        {
	        	kal_wsprintf(plst_cntx_p->ui_cntx.details_cntx.preview_data_p->track_num, "%d", plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->track_num);
            }
	        else
	        {
				plst_cntx_p->ui_cntx.details_cntx.preview_data_p->track_num[0] = 0;
	        }
	        kal_wsprintf(plst_cntx_p->ui_cntx.details_cntx.preview_data_p->play_count, "%d", plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->play_count);

            mmi_medply_details_make_date_time_string(
                plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_modified, 
                plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->last_modified);

	        if (plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->play_count == 0)
	        {
				mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_played, 
	                		  (const CHAR*)GetString(STR_ID_MEDPLY_PLST_DETAILS_NEVER_PLAYED), MMI_MEDPLY_MAX_TIME_LEN);
	        }
	        else
	        {
	            mmi_medply_details_make_date_time_string(
	                plst_cntx_p->ui_cntx.details_cntx.preview_data_p->last_played, 
	                plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->last_played);
			}
            
	        //kal_wsprintf(plst_cntx_p->ui_cntx.details_cntx.preview_data_p->volume, "%d db", plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->volume);

			{
				U16 rating_string_id = 0;
				switch (plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->user_rating)
				{
				case 0:
					rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_0;
					break;
				case 1:
					rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_1_EXT;
					break;
				case 2:
					rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_2_EXT;
					break;
				case 3:
					rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_3_EXT;
					break;
				case 4:
					rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_4_EXT;
					break;
				case 5:
					rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_5_EXT;
					break;
				default:
					MMI_ASSERT(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->user_rating <= 5);
				}
				mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.details_cntx.preview_data_p->user_rating, (const CHAR*)GetString(rating_string_id), MMI_MEDPLY_MAX_USER_RATING_LEN - 1);
			}

            /* fill audio info. */
            ret = mmi_medply_details_fill_audio_info(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->path);
            if (ret != MEDPLY_PLST_ERR_NO_MEMORY)
            {    
                /* ignore all error except no memory here. */
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_PREPARE_AUDIO, ret, __LINE__);
                ret = mmi_medply_details_fill_common_info(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p->path);
				if (ret < 0)
                {
	                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_PREPARE_COMMON, ret, __LINE__);
                    ret = 0;
                }
            }
        }
    }

    if (ret < 0)
    {
		if (raw_buffer_ready)
        {
			kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p);
            MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p, __LINE__);
            plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p = NULL;
        }

        if (preview_buffer_ready)
        {
			kal_adm_free(g_medply.adm_id_p, plst_cntx_p->ui_cntx.details_cntx.preview_data_p);
            MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.preview_data_p, __LINE__);
            plst_cntx_p->ui_cntx.details_cntx.preview_data_p = NULL;
        }
    }

	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_details_internal
 * DESCRIPTION
 *  details screen enter for list option.
 *	display the highlighted file's details.
 *  and just print log and display pop up if this string is an invalid path.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_entry_details_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_ENTER_INTERNAL);
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    memset(&(plst_cntx_p->ui_cntx.details_cntx), 0, sizeof(mmi_medply_details_cntx_struct));
    
    plst_cntx_p->ui_cntx.details_cntx.media_id = list_p->add_ons.opt_data.curr_hilite_id;


    ret = mmi_medply_details_prepare_data();
    if (ret < 0)
    {
		mmi_medply_details_reset_cntx();
		mmi_medply_plst_popup_simple(ret);
    }
    else    
    {
		mmi_medply_details_entry_preview(GRP_ID_MEDPLY_PLST_PLAYLIST);
        mmi_frm_get_active_scrn_id(&plst_cntx_p->ui_cntx.details_cntx.initiate_grp_id, &plst_cntx_p->ui_cntx.details_cntx.initiate_scr_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_details
 * DESCRIPTION
 *  details screen enter for main screen.
 *	just display the current playing/loading file's details.
 *	this function will get current file's path from "g_medply.filefullpath".
 *  and just print log and display pop up if this string is an invalid path.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_entry_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    UI_string_type loading_path = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_ENTER_EXTERNAL);
    
	loading_path = g_medply.filefullpath;

    if (loading_path == NULL)
    {
		MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_INVALID_PATH);
		return;
    }
       
	plst_cntx_p->ui_cntx.details_cntx.media_id = plst_cntx_p->list_cntx.playing.id;


    ret = mmi_medply_details_prepare_data();
    if (ret < 0)
    {
    	mmi_medply_details_reset_cntx();
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
		mmi_medply_details_entry_preview(g_gid_medply);
        mmi_frm_get_active_scrn_id(&plst_cntx_p->ui_cntx.details_cntx.initiate_grp_id, &plst_cntx_p->ui_cntx.details_cntx.initiate_scr_id);
    }
}


#define __PLAYING_CNTX
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_playing_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_playing_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_DEINIT_PLAYING);
	if (IsMyTimerExist(MEDPLY_WAIT_NEXT_TIMER))
    {
		StopTimer(MEDPLY_WAIT_NEXT_TIMER);
    }
   
    if (plst_cntx_p->list_cntx.playing.bitset.data)
    {
		kal_adm_free(g_medply.adm_id_p, plst_cntx_p->list_cntx.playing.bitset.data);
        MEM_TRC_FREE(plst_cntx_p->list_cntx.playing.bitset.data, __LINE__);
        plst_cntx_p->list_cntx.playing.bitset.data = NULL;
	}
    memset(&(plst_cntx_p->list_cntx.playing), 0, sizeof(mmi_medply_plst_playing_cntx_struct));
    plst_cntx_p->list_cntx.playing.loaded = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_playing_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_playing_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
	plst_cntx_p->list_cntx.playing.plst_id = list_p->plstid;

	plst_cntx_p->list_cntx.playing.total = list_p->total;

	if (list_p->total <= (MMI_MEDPLY_BITSET_BLOCK_SIZE * 8))
    {
    	size = MMI_MEDPLY_BITSET_BLOCK_SIZE;
    }
    else
    {
		size = MMI_MEDPLY_BITSET_BLOCK_SIZE * (list_p->total / (MMI_MEDPLY_BITSET_BLOCK_SIZE * 8));

        if ((list_p->total % (MMI_MEDPLY_BITSET_BLOCK_SIZE * 8)) > 0)
        {
			size += MMI_MEDPLY_BITSET_BLOCK_SIZE;
        }
    }

	plst_cntx_p->list_cntx.playing.bitset.data = kal_adm_alloc(g_medply.adm_id_p, size);
    if (plst_cntx_p->list_cntx.playing.bitset.data == NULL)
	{
	    return MEDPLY_PLST_ERR_NO_MEMORY;
	}
    else
    {
    	MEM_TRC_ALLOCATE(plst_cntx_p->list_cntx.playing.bitset.data, size, __LINE__);
		memset(plst_cntx_p->list_cntx.playing.bitset.data, 0, size);
        plst_cntx_p->list_cntx.playing.bitset.size = size;
    }
    mmi_ucs2ncpy((CHAR*)plst_cntx_p->list_cntx.playing.title, (const CHAR*)list_p->title, MEDPLY_MAX_FILE_LEN - 1);
    mmi_medply_plst_set_start(-1);
    plst_cntx_p->list_cntx.playing.loaded = MMI_TRUE;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_playing_load
 * DESCRIPTION
 *  load a playlist to nowplaying context.
 * PARAMETERS
 *  plst_id		[IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_playing_load(U32 plst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MEDPLY_PLST_NO_ERROR;
	U32 total = 0;
    U32 size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	plst_cntx_p->list_cntx.playing.plst_id = plst_id;

    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TOTAL, &plst_id, &total);    

    if (ret >= 0)
    {
    	plst_cntx_p->list_cntx.playing.total = total;
		if (plst_id <= MMI_MEDPLY_DB_LST_ON_THE_FLY_ID)
		{
			U16 title_id = 0;
			switch (plst_id)
		    {
				case MMI_MEDPLY_DB_LST_ALL_MEDIA_ID:
					title_id = STR_ID_MEDPLY_ALL_MEDIA;
		            break;
		        case MMI_MEDPLY_DB_LST_RECENT_ID:
		            title_id = STR_ID_MEDPLY_PLST_RECENTLY;
		            break;
		        case MMI_MEDPLY_DB_LST_BOOKMARK_ID:
		            title_id = STR_ID_MEDPLY_BOOKMARK;
		            break;
		        case MMI_MEDPLY_DB_LST_FAVOURITE_ID:
		            title_id = STR_ID_MEDPLY_PLST_MY_FAVOURITE;
		            break;
		        case MMI_MEDPLY_DB_LST_MOST_PLAYED_ID:
		            title_id = STR_ID_MEDPLY_PLST_MOST;
		            break;
		        case MMI_MEDPLY_DB_LST_ON_THE_FLY_ID:
		            title_id = STR_ID_MEDPLY_PLST_ON_THE_FLY;
		            break;
		        case MMI_MEDPLY_DB_LST_DUMMEY_ID:
		            title_id = STR_ID_MEDPLY_PLST_TITLE;
		            break;
		    }
			mmi_ucs2ncpy((CHAR*)plst_cntx_p->list_cntx.playing.title, (const CHAR*)GetString(title_id), MEDPLY_MAX_FILE_LEN - 1);
		}
		else
        {
        	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TITLE, &plst_id, plst_cntx_p->list_cntx.playing.title);      
        }
		if (total > 0)
        {
            size = (plst_cntx_p->list_cntx.playing.total / 8);

			if ((plst_cntx_p->list_cntx.playing.total % 8) > 0)
			{
				size++;
			}
		    plst_cntx_p->list_cntx.playing.bitset.data = kal_adm_alloc(g_medply.adm_id_p, size);
			if (plst_cntx_p->list_cntx.playing.bitset.data == NULL)
			{
			    ret = MEDPLY_PLST_ERR_NO_MEMORY;
		        memset(&(plst_cntx_p->list_cntx.playing), 0, sizeof(mmi_medply_plst_playing_cntx_struct));
			}
			else
			{
				MEM_TRC_ALLOCATE(plst_cntx_p->list_cntx.playing.bitset.data, size, __LINE__);
		        plst_cntx_p->list_cntx.playing.bitset.size = size;
				memset(plst_cntx_p->list_cntx.playing.bitset.data, 0, size);
			}
        }
        else
        {
			ret = MEDPLY_PLST_ERR_DB_EMPTY;
        }
    }
    if (ret >= 0)
    {
		plst_cntx_p->list_cntx.playing.loaded = MMI_TRUE;
    }
    return ret;
}


#define __PLST_OPT_DATA
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_reset_opt_data
 * DESCRIPTION
 *  reset list ui cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_reset_opt_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    memset(&(list_p->add_ons.opt_data), 0, sizeof(mmi_medply_plstui_opt_data_struct));
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_opt_hilite_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  index				[IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_opt_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    list_p->add_ons.opt_data.opt_hilite_index = index;
    
    ExecuteCurrHiliteHandler_Ext(index);
}

#define __PLST_UI_CACHE
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_reset_cache
 * DESCRIPTION
 *  reset list ui cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_reset_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    /* reset hint cache. */
	list_p->hint_cache.hint_idx = -1;
    list_p->hint_cache.hint_buff[0] = 0;
    
    list_p->total = 0;
    list_p->highlight = 0;
    list_p->head = 0;
    list_p->tail = 0;
    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		list_p->db_cache[i].format = 0;
        list_p->db_cache[i].media_id = 0;
        list_p->db_cache[i].reserved = 0;
        list_p->db_cache[i].title[0] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_common_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_common_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
	list_p->highlight = index;
}


#define ___MULTI_SELECT
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_opt_mark_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_opt_mark_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 size = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  
	size = (list_p->add_ons.multiselect.total / 8);

    if ((list_p->add_ons.multiselect.total % 8) > 0)
    {
    	size++;
    }
    memset(list_p->add_ons.multiselect.bitset.data, 0xff, size);
    list_p->add_ons.multiselect.selected = list_p->add_ons.multiselect.total;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_opt_unmark_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_opt_unmark_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    U32 size = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);   
	size = (list_p->add_ons.multiselect.total / 8);

    if ((list_p->add_ons.multiselect.total % 8) > 0)
    {
    	size++;
    }
    memset(list_p->add_ons.multiselect.bitset.data, 0, size);
    list_p->add_ons.multiselect.selected = 0;
    mmi_frm_scrn_close_active_id();
}


static mmi_medply_db_add_marked_struct add_marked;
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_opt_add_marked_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_opt_add_marked_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    S32 ret = 0;
    U8 i = 0;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() != SCR_ID_MEDPLY_PLST_WAIT_SCREEN)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_IN_SLEEP);
        /* Sleep if the waitting screen has been in history. */
        StartTimer(MEDPLY_GENERATE_TIMER, 500, mmi_medply_plstui_multiselect_opt_add_marked_internal);
        return;
    }
    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }

    while (add_marked.count < (add_marked.id_tbl->size / sizeof(U32)))
    {
        if (IsBitSetOn(add_marked.count, list_p->add_ons.multiselect.bitset.data))
        {
            add_marked.commit_count++;
            ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_ITEM_ADD_EXT, &(add_marked.id_tbl->data[add_marked.count]), &(add_marked.list_id), &add_marked.cur_index);

            if (ret >= 0)
            {
                add_marked.cur_index++;
                add_marked.count++;
                add_marked.done_count++;
                i++;
            }
            else
            {
                add_marked.error = ret;
                break;
            }

            /*commit to release sqlite memory*/
            if (add_marked.commit_count >= 200)
            {
                DB_ENABLE;
                DB_COMMIT_TRANSACTION;
                DB_BEGIN_TRANSACTION;
                DB_DISABLE;
                add_marked.commit_count = 0;
            }

            if (i == MMI_MEDPLY_MAX_PICK_PER_SLICE)
            {
                StartTimer(MEDPLY_STATE_MACHINE_TIMER, 50, mmi_medply_plstui_multiselect_opt_add_marked_internal);
                return;
            }
        }
        else
        {
            add_marked.count++;
        }
    }

    if (ret < 0)
    {
        DB_ENABLE;
        DB_ROLLBACK_TRANSACTION;
        DB_DISABLE;
        if (mdi_audio_is_background_play_suspended())
        {
            mdi_audio_resume_background_play();
        }
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        DB_ENABLE;
        DB_COMMIT_TRANSACTION;
        DB_DISABLE;
        if (mdi_audio_is_background_play_suspended())
        {
            mdi_audio_resume_background_play();
        }
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
        mmi_medply_plst_clear_gui_buffer(list_p->add_ons.multiselect.target_grp_id, list_p->add_ons.multiselect.target_scr_id);
    }
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_MULTI_SELECT, SCR_ID_MEDPLY_PLST_MULTI_SELECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_add_marked_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_add_marked_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  
    
    StopTimer(MEDPLY_STATE_MACHINE_TIMER);
    StopTimer(MEDPLY_GENERATE_TIMER);
    DB_ENABLE;
    DB_ROLLBACK_TRANSACTION;
    DB_DISABLE;
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }
    mmi_medply_plst_clear_gui_buffer(list_p->add_ons.multiselect.target_grp_id, list_p->add_ons.multiselect.target_scr_id);
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_wait_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_multiselect_wait_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_WAIT_SCREEN, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_PLST_WAIT_SCREEN, 
        SCR_ID_MEDPLY_PLST_WAIT_SCREEN, 
        NULL, 
        mmi_medply_plstdb_multiselect_wait_screen_entry, 
        MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }    
//#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
//    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
//#endif
    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(mmi_medply_plstui_multiselect_add_marked_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_opt_add_marked
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_opt_add_marked(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    S32 ret = 0;
    U32 total;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  

    memset(&add_marked, 0, sizeof(mmi_medply_db_add_marked_struct));

    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TOTAL, &(list_p->add_ons.multiselect.target_id), &total);

    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        add_marked.list_id = list_p->add_ons.multiselect.target_id;

        add_marked.cur_index = total;
        add_marked.error = 0;
        add_marked.total = list_p->add_ons.multiselect.total;
        add_marked.count = 0;
        add_marked.done_count = 0;
        add_marked.commit_count = 0;
        add_marked.id_tbl = &(list_p->id_table);
        
        if (mmi_medply_is_play_activated())
        {
            mdi_audio_suspend_background_play();
        }

        mmi_medply_plstdb_multiselect_wait_screen_entry();
        DB_ENABLE;
        DB_BEGIN_TRANSACTION;
        DB_DISABLE;

        StartTimer(MEDPLY_STATE_MACHINE_TIMER, 10, mmi_medply_plstui_multiselect_opt_add_marked_internal);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_opt_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_opt_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MULTI_SELECT_ADD_MARKED, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MULTI_SELECT_MARK_ALL, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MULTI_SELECT_UNMARK_ALL, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SORT_BY, MMI_TRUE);

    if (list_p->total)
    {
        if (list_p->add_ons.multiselect.selected > 0)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MULTI_SELECT_ADD_MARKED, MMI_FALSE);
        }

        if (list_p->total != list_p->add_ons.multiselect.selected)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MULTI_SELECT_MARK_ALL, MMI_FALSE);
        }
        if (list_p->add_ons.multiselect.selected)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MULTI_SELECT_UNMARK_ALL, MMI_FALSE);
        }
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_entry_opt_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_entry_opt_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_MULTISELECT_OPT);
    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_MULTI_SELECT, GRP_ID_MEDPLY_PLST_MULTI_SELECT_OPT, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_MULTI_SELECT_OPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create( GRP_ID_MEDPLY_PLST_MULTI_SELECT_OPT,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_OPTION,
                            MENU_ID_MEDPLY_MULTI_SELECT_MENU,
                            MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_get_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index			[IN]      
 *  checkbox_image		[?]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plstui_multiselect_get_state(S32 item_index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    *checkbox_image = (IsBitSetOn(item_index, list_p->add_ons.multiselect.bitset.data)) ? (PU8)GetImage(CHECKBOX_ON_IMAGE_ID) : (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_set_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index			[IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_multiselect_set_state(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    if (IsBitSetOn(item_index, list_p->add_ons.multiselect.bitset.data))
    {
		ClrBitSet(item_index, list_p->add_ons.multiselect.bitset.data);
        list_p->add_ons.multiselect.selected--;
    }
    else
    {	
		SetBitSet(item_index, list_p->add_ons.multiselect.bitset.data);
        list_p->add_ons.multiselect.selected++;
    }
	
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_scr_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    if (mmi_medply_plstui_multiselect_set_state(list_p->highlight) == MMI_TRUE)
    {
        RedrawCategoryFunction();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_multiselect_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 total = 0;
    S32 ret = 0;
    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    
	list_p->plstid = MMI_MEDPLY_DB_LST_ALL_MEDIA_ID;
	/* get title. */
    mmi_ucs2ncpy((CHAR*)list_p->title, (const CHAR*)GetString(STR_GLOBAL_SELECT), MEDPLY_MAX_FILE_LEN - 1);

    /* reset hint cache. */
	list_p->hint_cache.hint_idx = -1;
    list_p->hint_cache.hint_buff[0] = 0;

    /* get list data. */	
	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TOTAL, &(list_p->plstid), &total);
	if (ret >= 0)
	{	    
	    list_p->total = total;

	    if (list_p->total)
	    {
	    	MMI_ASSERT(list_p->id_table.data == NULL);
	        list_p->id_table.pattern = 0xFEFEFEFE;
	        list_p->id_table.size = sizeof(U32) * list_p->total;
		    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

	        if (list_p->id_table.data == NULL)
	        {
	            ret = MEDPLY_PLST_ERR_NO_MEMORY;
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);
	        }
	        else
	        {
	        	MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
				ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TBL, 
									&(list_p->plstid), &(list_p->id_table));
	            if (ret < 0)
	            {
	                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
	                list_p->id_table.data = NULL;
                    list_p->id_table.size = 0;
	            }
                else
				{	
					U32 size = 0;

					/* initialize multi_data. */
					list_p->add_ons.multiselect.total = list_p->total;
				    list_p->add_ons.multiselect.selected = 0;
					size = (list_p->add_ons.multiselect.total / 8);

				    if ((list_p->add_ons.multiselect.total % 8) > 0)
				    {
				    	size++;
				    }
				    list_p->add_ons.multiselect.bitset.size = size;
				    list_p->add_ons.multiselect.bitset.data = kal_adm_alloc(g_medply.adm_id_p, size);
				    if (list_p->add_ons.multiselect.bitset.data == NULL)
				    {
				        kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
				        MEM_TRC_FREE(list_p->id_table.data, __LINE__);
				        list_p->id_table.data = NULL;
						list_p->id_table.size = 0;
                        ret = MEDPLY_PLST_ERR_NO_MEMORY;
                        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);
				    }
				    else
				    {
				    	MEM_TRC_ALLOCATE(list_p->add_ons.multiselect.bitset.data, size, __LINE__);
						memset(list_p->add_ons.multiselect.bitset.data, 0, size);
				    }
				}
	        }
        }
	}
	
    return ret;
}



/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_multiselect_del_scr_callback
* DESCRIPTION
*  
* PARAMETERS
*  in_param		[IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_medply_plstui_multiselect_del_scr_callback(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_medply_plstui_list_cache_struct *list_p = NULL;

            list_p = mmi_medply_plstui_get_curr_list_cache();
            MMI_ASSERT(list_p != NULL); 
            
            if (list_p->id_table.data != NULL)
            {
                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
                list_p->id_table.data = NULL;
            }
            
            
            mmi_medply_plstui_destory_list_cache();
            break;
        }
    }
    return MMI_RET_OK;
}

static pBOOL mmi_medply_plstui_playlist_get_item
        (S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 mmi_medply_plstui_playlist_get_hint
        (S32 item_index, UI_string_type *hint_array);

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_multiselect_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_multiselect_entry_scr(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U8 *guiBuffer = NULL;
    PU8 titleHintString = NULL;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_MULTISELECT);
    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 

    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_PLAYLIST, GRP_ID_MEDPLY_PLST_MULTI_SELECT, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_MULTI_SELECT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_PLST_MULTI_SELECT, SCR_ID_MEDPLY_PLST_MULTI_SELECT, NULL, mmi_medply_plstui_multiselect_entry_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_PLST_MULTI_SELECT, SCR_ID_MEDPLY_PLST_MULTI_SELECT, 
                                mmi_medply_plstui_multiselect_del_scr_callback);

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_MULTI_SELECT, SCR_ID_MEDPLY_PLST_MULTI_SELECT);

    if (!guiBuffer)
    {
        mmi_medply_plstui_reset_cache();
        ret = mmi_medply_plstui_multiselect_prepare();
        
        if (ret < 0)
        {
			mmi_medply_plst_popup_simple(ret);	
            mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_MULTI_SELECT, SCR_ID_MEDPLY_PLST_MULTI_SELECT);
            return;
        }
    }
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_plstui_common_highlight_hdlr);
#ifndef __MMI_TOUCH_SCREEN__
    titleHintString = (U8*) GetString(STR_ID_MEDPLY_PLST_NOTIFY_PRESS_STAR);
#else /* def __MMI_TOUCH_SCREEN__ */
    titleHintString = (U8*) GetString(STR_ID_MEDPLY_PLST_NOTIFY_TOUCH_BOX);
#endif /* def __MMI_TOUCH_SCREEN__ */

	if (list_p->total)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    
    ShowCategory384Screen(
        list_p->title,
        get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),
        (list_p->total > 0 ? STR_GLOBAL_OPTIONS : 0),
        (list_p->total > 0 ? IMG_GLOBAL_OPTIONS : 0),
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        titleHintString,
        list_p->total,
        mmi_medply_plstui_playlist_get_item,
        mmi_medply_plstui_playlist_get_hint,
        mmi_medply_plstui_multiselect_get_state,
	    mmi_medply_plstui_multiselect_set_state,
	    list_p->highlight,
	    guiBuffer);
	if (list_p->total)
    {
	    SetLeftSoftkeyFunction(mmi_medply_plstui_multiselect_entry_opt_scr, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_medply_plstui_multiselect_check, KEY_EVENT_UP);
    }
    
    SetKeyHandler(mmi_medply_plstui_multiselect_check, KEY_STAR, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_multiselect_entry
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_multiselect_entry(U32 target_list_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0; 

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ret = mmi_medply_plstui_create_list_cache();
    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        list_p = mmi_medply_plstui_get_curr_list_cache();
        MMI_ASSERT(list_p != NULL);
        list_p->add_ons.multiselect.target_id = target_list_id;
        list_p->add_ons.multiselect.target_grp_id = GRP_ID_MEDPLY_PLST_PLAYLIST;
        list_p->add_ons.multiselect.target_scr_id = SCR_ID_MEDPLY_PLST_PLAYLIST;
        mmi_medply_plstui_multiselect_entry_scr();
    }
}

#define ___ORGANIZE_LIST_SCR
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_exchange
 * DESCRIPTION
 *  
 * PARAMETERS
 *  direction		[IN]
 *  times			[IN]
 *  begin			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_exchange(S16 direction, U32 times, U32 begin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i = 0;
    U32 temp = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    if (direction < 0)
    {
	    for (i = 0; i < times; i++)
		{
			temp = list_p->id_table.data[begin - i];
		    list_p->id_table.data[begin - i] = 
                	list_p->id_table.data[begin - i - 1];
		    list_p->id_table.data[begin - i - 1] = temp;
		}
    }
    else if (direction > 0)
    {
	    for (i = 0; i < times; i++)
	    {
			temp = list_p->id_table.data[begin + i];
	        list_p->id_table.data[begin + i] = 
                	list_p->id_table.data[begin + i + 1];
	        list_p->id_table.data[begin + i + 1] = temp;
	    }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_list_goto_prev_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_list_goto_prev_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	S32 index = 0;
    U32 move_times = 0;
    U32 begin = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    if (list_p->highlight <= 0)
    {
		index =	list_p->total - 1;
	}
    else
    {
		index = list_p->highlight - 1;
    }
    
	if (list_p->add_ons.organize.hold)
	{
		if (list_p->highlight <= 0)
	    {
			move_times = list_p->total - 1;
            begin = 0;
            mmi_medply_plstui_organize_exchange(1, move_times, begin);
		}
	    else
	    {
            move_times = 1;
            begin = list_p->highlight;
            mmi_medply_plstui_organize_exchange(-1, move_times, begin);
	    }
	}
    dynamic_list_goto_item(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_list_goto_next_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	S32 index = 0;
    U32 move_times = 0;
    U32 begin = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    if (list_p->highlight == list_p->total - 1)
    {
		index =	0;
	}
    else
    {
		index = list_p->highlight + 1;
    }

	if (list_p->add_ons.organize.hold)
	{
        if (list_p->highlight == list_p->total - 1)
	    {
			move_times = list_p->total - 1;
            begin = list_p->highlight;
            mmi_medply_plstui_organize_exchange(-1, move_times, begin);
		}
	    else
	    {
            move_times = 1;
            begin = list_p->highlight;
            mmi_medply_plstui_organize_exchange(1, move_times, begin);
	    }
  	}
    dynamic_list_goto_item(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_save_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_save_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    S32 ret = 0;
	U8 i = 0;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
	if (mmi_frm_scrn_get_active_id() != SCR_ID_MEDPLY_PLST_WAIT_SCREEN)
    {
		MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_IN_SLEEP);
		/* Sleep if the waitting screen has been in history. */
        StartTimer(MEDPLY_GENERATE_TIMER, 500, mmi_medply_plstui_organize_save_internal);
        return;
    }

    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  
    
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
	}

	while (list_p->add_ons.organize.save_count < list_p->total)
    {
        ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_ITEM_SET_IDX, 
            			&(list_p->add_ons.organize.save_count), 
            			&(list_p->plstid), 
            			&(list_p->id_table.data[list_p->add_ons.organize.save_count]));
        if (ret < 0)
        {
			break;
        }
       	else
        {
			list_p->add_ons.organize.save_count++;
			i++;
        }

        if (i == MMI_MEDPLY_MAX_PICK_PER_SLICE)
        {
		    StartTimer(MEDPLY_STATE_MACHINE_TIMER, 50, mmi_medply_plstui_organize_save_internal);
			return;
        }
    }

    if (ret < 0)
    {
        DB_ENABLE;
        DB_ROLLBACK_TRANSACTION;
        DB_DISABLE;
        if (mdi_audio_is_background_play_suspended())
        {
            mdi_audio_resume_background_play();
        }
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        DB_ENABLE;
        DB_COMMIT_TRANSACTION;
        DB_DISABLE;
        if (mdi_audio_is_background_play_suspended())
        {
            mdi_audio_resume_background_play();
        }
        if (list_p->plstid == plst_cntx_p->list_cntx.playing.plst_id)
        {
            U32 new_index = 0;
            ret = DB_ACTION3(MEDPLY_DB_ACT_QUERY_ITEM_IDX, &new_index, &(list_p->plstid), &(plst_cntx_p->list_cntx.playing.id));
            if (ret < 0)
            {
                plst_cntx_p->list_cntx.playing.pick_index = -1;
            }
            else
            {
                plst_cntx_p->list_cntx.playing.pick_index = new_index;
            }
            /* reset bitset. */
            mmi_medply_plst_set_start(plst_cntx_p->list_cntx.playing.pick_index);
        }
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_PLAYLIST);
    }
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_ORGANIZE, SCR_ID_MEDPLY_PLST_ORGANIZE);
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_save_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_save_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  
    
	StopTimer(MEDPLY_STATE_MACHINE_TIMER);
	StopTimer(MEDPLY_GENERATE_TIMER);
    DB_ENABLE;
    DB_ROLLBACK_TRANSACTION;
    DB_DISABLE;
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }    
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
    mmi_frm_scrn_close(list_p->initiate_grp_id, list_p->initiate_scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_wait_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_wait_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_WAIT_SCREEN, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_PLST_WAIT_SCREEN, 
        SCR_ID_MEDPLY_PLST_WAIT_SCREEN, 
        NULL, 
        mmi_medply_plstui_organize_wait_screen_entry, 
        MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }    
//#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
//    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
//#endif
    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(mmi_medply_plstui_organize_save_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
	
	list_p->add_ons.organize.save_count = 0;
	if (mmi_medply_is_play_activated())
    {
		mdi_audio_suspend_background_play();
    }
    DB_ENABLE;
    DB_BEGIN_TRANSACTION;
    DB_DISABLE;
	mmi_medply_plstui_organize_wait_screen_entry();
    StartTimer(MEDPLY_STATE_MACHINE_TIMER, 50, mmi_medply_plstui_organize_save_internal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_resaved
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_resaved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_ORGANIZE, SCR_ID_MEDPLY_PLST_ORGANIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_save_ask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_save_ask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_medply_plst_confirm(GRP_ID_MEDPLY_PLST_PLAYLIST,
        (WCHAR *)get_string(STR_GLOBAL_SAVE_ASK),
        MEDPLY_PLST_ORGANIZE_SAVE_CONFIRM,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}

static void mmi_medply_plstui_organize_get_move(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_set_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_set_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
	if (list_p->add_ons.organize.hold)
	{
	    memcpy((list_p->add_ons.organize.backup_table.data),
               (list_p->id_table.data),
               list_p->id_table.size);
		list_p->add_ons.organize.list_changed = MMI_TRUE;
		list_p->add_ons.organize.hold = MMI_FALSE;
		list_p->add_ons.organize.hold_id = 0;
		ChangeLeftSoftkey(STR_ID_MEDPLY_PLST_MOVE, 0);
    	SetLeftSoftkeyFunction(mmi_medply_plstui_organize_get_move, KEY_EVENT_UP);
		ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
    	SetRightSoftkeyFunction(mmi_medply_plstui_organize_save_ask, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_medply_plstui_organize_get_move, KEY_EVENT_UP);
    }
    else
    {
		MMI_ASSERT(list_p->add_ons.organize.hold == MMI_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_cancel_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_cancel_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    U8 *guiBuffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
	if (list_p->add_ons.organize.hold)
	{
		list_p->add_ons.organize.hold = MMI_FALSE;
        list_p->add_ons.organize.hold_id = 0;

        memcpy((list_p->id_table.data),
               (list_p->add_ons.organize.backup_table.data),
               list_p->id_table.size);
        //mmi_frm_scrn_enter(g_gid_medply, GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_UNKNOW_SCRN);
        //null entry modify
        mmi_frm_display_dummy_screen_ex(g_gid_medply, GLOBAL_SCR_DUMMY);
        if (mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_PLST_ORGANIZE, SCR_ID_MEDPLY_PLST_ORGANIZE))
	    {

            guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_ORGANIZE, SCR_ID_MEDPLY_PLST_ORGANIZE);
            if (guiBuffer)
            {
                list_menu_category_history *hist = (list_menu_category_history*)guiBuffer;
	            hist->highlighted_item = 0; 
            }
	    }   
		mmi_frm_scrn_close(g_gid_medply, GLOBAL_SCR_DUMMY);

        ChangeLeftSoftkey(STR_ID_MEDPLY_PLST_MOVE, 0);
    	SetLeftSoftkeyFunction(mmi_medply_plstui_organize_get_move, KEY_EVENT_UP);
        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_medply_plstui_organize_get_move, KEY_EVENT_UP);
        if (list_p->add_ons.organize.list_changed)
        {
			ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
    		SetRightSoftkeyFunction(mmi_medply_plstui_organize_save_ask, KEY_EVENT_UP);
        }
        else
        {
			ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    		SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        }
    }
    else
    {
		MMI_ASSERT(list_p->add_ons.organize.hold == MMI_TRUE);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_get_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_get_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
	/* set hold flag */
    list_p->add_ons.organize.hold = MMI_TRUE;
	list_p->add_ons.organize.hold_id = list_p->id_table.data[list_p->highlight];
	/* change soft key */
	ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_CANCEL, 0);
	SetLeftSoftkeyFunction(mmi_medply_plstui_organize_set_move, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_medply_plstui_organize_cancel_move, KEY_EVENT_UP);
    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_medply_plstui_organize_set_move, KEY_EVENT_UP);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_scr_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index      	[IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_organize_scr_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    list_p->add_ons.organize.last_hilite = list_p->add_ons.organize.hilite;
    list_p->add_ons.organize.hilite = index;
    list_p->highlight = index;
#ifdef __MMI_TOUCH_SCREEN__ 
    //wgui_register_list_item_selected_callback(mmi_medply_plst_organioze_list_touch); 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_scr_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_medply_plstui_organize_scr_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_id = 0;
    S32 ret = 0;

	U8 i = 0;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    mmi_medply_plstui_db_cache_item_struct item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
	current_id = list_p->id_table.data[item_idx];
	/* check the request item whether in cache. */
    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == current_id &&
            list_p->db_cache[i].title[0] != 0)
        {
			mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)list_p->db_cache[i].title, MEDPLY_MAX_FILE_LEN -1);
			*img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(list_p->db_cache[i].format));
            return MMI_TRUE;
        }
    }

	/* out of cache. */
    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_LIST_INFO, 
            			&(list_p->id_table.data[item_idx]), &item);
    if (ret < 0)
    {
	    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_LOAD_CACHE_FAIL, ret, __LINE__);
        mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)GetString(STR_GLOBAL_LOADING), MEDPLY_MAX_FILE_LEN -1);
	    *img_buff_p = NULL;
	    return MMI_TRUE;
    }

	/* update cache. */
	for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == 0 &&
            list_p->db_cache[i].title[0] == 0)
        {
			/* get an empty cache item. */
            break;
        }
    }

	if (i < MMI_MEDPLY_LIST_BUFF_SIZE)
    {
		/* cache is not full. just need update tail. */
        memcpy(&(list_p->db_cache[i]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
		list_p->tail = i;
    }
    else
    {
		/* cache is full, need replace the oldest one. */
 		memcpy(&(list_p->db_cache[list_p->head]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
       	if (list_p->head == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
	    {
			list_p->head = 0;
	    }
	    else
	    {
	    	list_p->head++;
	    }
		if (list_p->tail == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
		{
			list_p->tail = 0;
		}
		else
		{
			list_p->tail++;
		}
    }
    
    mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)item.title, MEDPLY_MAX_FILE_LEN -1);

    *img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(item.format));
	
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_organize_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_organize_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 total = 0;
    S32 ret = 0;
    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    

	
	mmi_ucs2ncpy((CHAR*)list_p->title, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_ORGANIZE_LIST), MEDPLY_MAX_FILE_LEN - 1);

	/* reset hint cache. */
	list_p->hint_cache.hint_idx = -1;
    list_p->hint_cache.hint_buff[0] = 0;

	/* reset organize data. */
    list_p->add_ons.organize.hilite = -1;
    list_p->add_ons.organize.hold = MMI_FALSE;
    list_p->add_ons.organize.hold_hilite = -1;
    list_p->add_ons.organize.last_hilite = -1;
    list_p->add_ons.organize.list_changed = MMI_FALSE;

	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TOTAL, &(list_p->plstid), &total);
	if (ret >= 0)
	{	    
	    list_p->total = total;

	    if (list_p->total)
	    {
	    	if (list_p->id_table.data != NULL)
	        {
			 	kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
			 	MEM_TRC_FREE(list_p->id_table, __LINE__);
			 	list_p->id_table.data = NULL;
			    list_p->id_table.size = 0;
	        }
	    	MMI_ASSERT(list_p->id_table.data == NULL);
	        list_p->id_table.pattern = 0xFEFEFEFE;
	        list_p->id_table.size = sizeof(U32) * list_p->total;
		    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

	        if (list_p->id_table.data == NULL)
	        {
	            ret = MEDPLY_PLST_ERR_NO_MEMORY;
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);

	        }
	        else
	        {
	        	MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
				ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TBL, 
									&(list_p->plstid), &(list_p->id_table));
	            if (ret < 0)
	            {
	                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
	                list_p->id_table.data = NULL;
                    list_p->id_table.size = 0;
	            }
	        }

			/* save backup_table */
            if (list_p->add_ons.organize.backup_table.data != NULL)
	        {
			 	kal_adm_free(g_medply.adm_id_p, list_p->add_ons.organize.backup_table.data);
			 	MEM_TRC_FREE(list_p->add_ons.organize.backup_table.data, __LINE__);
			 	list_p->add_ons.organize.backup_table.data = NULL;
			    list_p->add_ons.organize.backup_table.size = 0;
	        }
            MMI_ASSERT(list_p->add_ons.organize.backup_table.data == NULL);
	        list_p->add_ons.organize.backup_table.pattern = 0xFEFEFEFE;
	        list_p->add_ons.organize.backup_table.size = sizeof(U32) * list_p->total;
		    list_p->add_ons.organize.backup_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->add_ons.organize.backup_table.size);

	        if (list_p->id_table.data == NULL)
	        {
	            ret = MEDPLY_PLST_ERR_NO_MEMORY;
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);
                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	            MEM_TRC_FREE(list_p->id_table.data, __LINE__);
	            list_p->id_table.data = NULL;
                list_p->id_table.size = 0;
	        }
	        else
	        {
	        	MEM_TRC_ALLOCATE(list_p->add_ons.organize.backup_table.data, list_p->add_ons.organize.backup_table.size, __LINE__);
				memcpy((list_p->add_ons.organize.backup_table.data), 
                       (list_p->id_table.data), 
                       list_p->add_ons.organize.backup_table.size);
	        }
        }
	}
	
    
    return ret;
}



/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_organize_del_scr_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  in_param		[IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_medply_plstui_organize_del_scr_hdlr(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_medply_plstui_list_cache_struct *list_p = NULL;

            list_p = mmi_medply_plstui_get_curr_list_cache();
            MMI_ASSERT(list_p != NULL);
            
            if (list_p->add_ons.organize.backup_table.data)
            {
                kal_adm_free(g_medply.adm_id_p, list_p->add_ons.organize.backup_table.data);
                MEM_TRC_FREE(list_p->add_ons.organize.backup_table.data, __LINE__);
                list_p->add_ons.organize.backup_table.data = NULL;
                list_p->add_ons.organize.backup_table.size = 0;
            }
            
            if (list_p->id_table.data)
            {
                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
                list_p->id_table.data = NULL;
            }   
            
            mmi_medply_plstui_destory_list_cache();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_organize_disable_shortcut_callback
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U32 mmi_medply_plstui_organize_disable_shortcut_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    flag |= WGUI_LIST_MENU_DISABLE_SHORTCUT;
    
	return flag;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_organize_entry_scr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_organize_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U16 LSK_string = 0;
    U16 RSK_string = 0;
    U8 *guiBuffer = NULL;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_PLAYLIST, GRP_ID_MEDPLY_PLST_ORGANIZE, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_ORGANIZE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_PLST_ORGANIZE, SCR_ID_MEDPLY_PLST_ORGANIZE, NULL, mmi_medply_plstui_organize_entry_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    

    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_PLST_ORGANIZE, SCR_ID_MEDPLY_PLST_ORGANIZE, mmi_medply_plstui_organize_del_scr_hdlr);
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_ORGANIZE, SCR_ID_MEDPLY_PLST_ORGANIZE);

    if (!guiBuffer)
    {
        ret = mmi_medply_plstui_organize_prepare();
        list_p->list_scr_id = SCR_ID_MEDPLY_PLST_ORGANIZE;
        list_p->initiate_grp_id = GRP_ID_MEDPLY_PLST_ORGANIZE;
        list_p->initiate_scr_id = SCR_ID_MEDPLY_PLST_PLAYLIST;
        if (ret < 0)
        {
			mmi_medply_plst_popup_simple(ret);
            mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_ORGANIZE, SCR_ID_MEDPLY_PLST_ORGANIZE);
            return;
        }
    }    
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_plstui_organize_scr_hilite_hdlr);
    
    wgui_cat_register_get_flags_callback(mmi_medply_plstui_organize_disable_shortcut_callback);

	if (list_p->add_ons.organize.hold)
    {
		LSK_string = STR_GLOBAL_OK;
        RSK_string = STR_GLOBAL_CANCEL;
    }
    else
    {
		LSK_string = STR_ID_MEDPLY_PLST_MOVE;

        if (list_p->add_ons.organize.list_changed)
        {
			RSK_string = STR_GLOBAL_DONE;
        }
        else
        {
			RSK_string = STR_GLOBAL_BACK;
        }
    }

    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory183Screen(
        get_string(STR_ID_MEDPLY_PLST_ORGANIZE_LIST), 
        get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
        get_string(LSK_string),
        0,              
		get_string(RSK_string),
    	0, 
        list_p->total,
        mmi_medply_plstui_organize_scr_get_item,
        NULL,
        list_p->highlight,
        MMI_TRUE,
        NULL,
        guiBuffer);

    /* register LSK, RSK hanlders */
    SetKeyHandler(mmi_medply_plstui_organize_list_goto_prev_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_medply_plstui_organize_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_plstui_organize_list_goto_prev_item, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_medply_plstui_organize_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	if (list_p->add_ons.organize.hold)
    {
		SetLeftSoftkeyFunction(mmi_medply_plstui_organize_set_move, KEY_EVENT_UP);
	    SetRightSoftkeyFunction(mmi_medply_plstui_organize_cancel_move, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_medply_plstui_organize_set_move, KEY_EVENT_UP);
    }
    else
    {
		SetLeftSoftkeyFunction(mmi_medply_plstui_organize_get_move, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_medply_plstui_organize_get_move, KEY_EVENT_UP);
        if (list_p->add_ons.organize.list_changed)
        {
			SetRightSoftkeyFunction(mmi_medply_plstui_organize_save_ask, KEY_EVENT_UP);
        }
        else
        {
			SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        }
    }

    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_organize_entry
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_organize_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0; 
    mmi_medply_plstui_list_cache_struct *list_p = NULL;    
	mmi_medply_plstui_list_cache_struct *raw_list_p = NULL; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    raw_list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(raw_list_p != NULL);
    
	ret = mmi_medply_plstui_create_list_cache();
	if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        list_p = mmi_medply_plstui_get_curr_list_cache();
    	MMI_ASSERT(list_p != NULL); 
        list_p->plstid = raw_list_p->plstid;
		mmi_medply_plstui_organize_entry_scr();
    }
}


#define ___PLAYLIST
static mmi_medply_db_list_clear_struct clear_list;

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generic_exit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_generic_exit_screen(MMI_ID parent_id, U16 scrnID, mmi_proc_func entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct node_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_node_info_init(&node_info);
    node_info.id = (MMI_ID)scrnID;
    node_info.entry_proc = entryFuncPtr;
    mmi_frm_scrn_insert(parent_id, 
        mmi_frm_scrn_get_active_id(), 
        &node_info, 
        MMI_FRM_NODE_BEFORE_FLAG);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_allmedia_opt_search
 * DESCRIPTION
 *  function to initiate search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_allmedia_opt_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 

	memset(&(plst_cntx_p->search_cntx), 0, sizeof(mmi_medply_db_search_struct));
    plst_cntx_p->search_cntx.initiate_grp_id = list_p->list_grp_id;
    plst_cntx_p->search_cntx.initiate_scr_id = list_p->list_scr_id;
	if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
   	{
    	mmi_medply_search_entry_scr();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_allmedia_append
* DESCRIPTION
*  get target's meta data, check whether it is in db. 
*  compare and update if it is exist. append in otherwise.
* PARAMETERS
*  path         [IN]
*  is_short     [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_plstui_allmedia_append_add2db(
								mmi_medply_db_media_base_struct* base,
								mmi_medply_db_media_meta_struct* meta)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_MEDIA_EXIST_EXT, &(base->path_hash));

    if (MEDPLY_PLST_GOT_DATA != ret)
	{
	    ret = DB_ACTION2(MEDPLY_DB_ACT_MODIFY_MEDIA_ADD, base, meta);  
		
	    if (ret >= 0)
	    {
	    	ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_ITEM_ADD_EXT, 
                					   &(base->id), 
                					   &(list_p->plstid), 
                					   &(list_p->total));
            if (ret >= 0)
            {
            	list_p->total++;
            }
	    }
	}
    else
    {
		ret = MEDPLY_PLST_ERR_ITEM_EXISTS;
    }
	
	return ret;    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_allmedia_append
* DESCRIPTION
*  get target's meta data, check whether it is in db. 
*  compare and update if it is exist. append in otherwise.
* PARAMETERS
*  path         [IN]
*  is_short     [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_plstui_allmedia_append(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_db_media_meta_struct* meta_data = NULL;
    mmi_medply_db_media_base_struct* base_info = NULL;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
	base_info = (mmi_medply_db_media_base_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_db_media_base_struct));
    if (base_info == NULL)
    {
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
    else
    {
        MEM_TRC_ALLOCATE(base_info, sizeof(mmi_medply_db_media_base_struct), __LINE__);
	    memset(base_info, 0, sizeof(mmi_medply_db_media_base_struct));

		mmi_medply_plst_get_base_info(path, base_info);
    }
    
#ifdef PARSE_FILE_IN_GENERATE	
	if (ret >= 0)
    {
	    meta_data = (mmi_medply_db_media_meta_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_db_media_meta_struct));
	    if (meta_data == NULL)
	    {
	        ret = MEDPLY_PLST_ERR_NO_MEMORY;
	    }
	    else
	    {
		    MEM_TRC_ALLOCATE(meta_data, sizeof(mmi_medply_db_media_meta_struct), __LINE__);
		    memset(meta_data, 0, sizeof(mmi_medply_db_media_meta_struct));

	        ret = mmi_medply_plst_get_meta_from_file(path, meta_data);
		}
    }
#endif	/* PARSE_FILE_IN_GENERATE */

	//if (ret >= 0)
    if (ret != MEDPLY_PLST_ERR_NO_MEMORY)    
    {
    	ret = mmi_medply_plstui_allmedia_append_add2db(base_info, meta_data);
    }
    
#ifdef PARSE_FILE_IN_GENERATE
	if (meta_data != NULL)
    {
	    kal_adm_free(g_medply.adm_id_p, meta_data);
	    MEM_TRC_FREE(meta_data, __LINE__);
	    meta_data = NULL;
    }
#endif	/* PARSE_FILE_IN_GENERATE */
	if (base_info != NULL)
    {
	    kal_adm_free(g_medply.adm_id_p, base_info);
	    MEM_TRC_FREE(base_info, __LINE__);
	    base_info = NULL;
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_allmedia_opt_add_part2
 * DESCRIPTION
 *  get path from file browser, and add file/folder to list.
 * PARAMETERS
 *  path        [IN]
 *  is_short    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_allmedia_opt_add_part2(UI_string_type path, int is_short)
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
    MMI_ASSERT(plst_cntx_p->generate_cntx_p != NULL);
    if (path == NULL)
    {
		//GoBackToHistory(plst_cntx_p->generate_cntx_p->initiate_scr_id);
		mmi_frm_scrn_close(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER);
        return;
    }

/* check the target whether is a multi_part ODF file. */ 
#ifdef __DRM_V02__
    if (NULL != (ext = mmi_ucs2rchr((const CHAR*)path, (U16)L'.')))
    {
        if (!mmi_ucs2nicmp((const CHAR*)ext, 
                (const CHAR*)L".odf", (U32)mmi_ucs2strlen((const CHAR*)ext)))
        {
            if (DRM_is_archive(0, (PU16)path))
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


/* check the target whether is a folder. */
    last_backlash = mmi_ucs2rchr((const CHAR*)path, (U16)L'\\');


    if (2 > mmi_ucs2strlen((const CHAR*)last_backlash) || is_multi_part_odf)
    {
        /* 
        ** the backlash is the last character of this path. 
        ** so this is a folder path.
        */

    	if (mmi_medply_is_play_activated())
        {
			mdi_audio_suspend_background_play();
        }
        DB_ENABLE;
        DB_BEGIN_TRANSACTION;
        DB_DISABLE;
        mmi_medply_plstdb_generate_from_folder(path, is_multi_part_odf);
    }
    else
    {
        /* it is a file. append to playlist directly. */
        if (mmi_medply_is_play_activated())
        {
			mdi_audio_suspend_background_play();
        }
        DB_ENABLE;
        DB_BEGIN_TRANSACTION;
        DB_DISABLE;
        ret = mmi_medply_plstui_allmedia_append(path, is_short);
        if (ret >= FS_NO_ERROR)
        {
        	DB_ENABLE;
	        DB_COMMIT_TRANSACTION;
	        DB_DISABLE;
            if (mdi_audio_is_background_play_suspended())
            {
                mdi_audio_resume_background_play();
    		}
            mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
            mmi_medply_plst_clear_gui_buffer(plst_cntx_p->generate_cntx_p->initiate_grp_id, plst_cntx_p->generate_cntx_p->initiate_scr_id);
            mmi_frm_scrn_close(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER);
        }
        else
        {
        	DB_ENABLE;
		    DB_ROLLBACK_TRANSACTION;
		    DB_DISABLE;
            if (mdi_audio_is_background_play_suspended())
            {
                mdi_audio_resume_background_play();
    		}        	
            mmi_medply_plst_popup_simple(ret);
            mmi_frm_scrn_close(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_allmedia_opt_add_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_allmedia_opt_add_part1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    ret = mmi_medply_plstdb_generate_init(GRP_ID_MEDPLY_PLST_PLAYLIST, list_p->list_scr_id, MMI_MEDPLY_GENERATE_ADD);

    if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
        
    }
    else
    {
        //mmi_medply_plstdb_generate_entry_layer();
        
        /* call file manager API to select media file or folder.*/  
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
        FMGR_FILTER_SET_AUDIO(&filter);
        FMGR_FILTER_SET_VIDEO(&filter);
    #ifdef __MMI_VIDEO_STREAM__
        FMGR_FILTER_SET_STREAM(&filter);
    #endif
    #ifdef __VM_CODEC_SUPPORT__
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
    #endif
#ifdef __DRM_V02__
        FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif
         
        cui_gid = cui_file_selector_create(
                                        GRP_ID_MEDPLY_PLST_PLAYLIST,
                                        (WCHAR*) L"root",
                                        &filter,
                                        CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
                                        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);
        
        if (cui_gid > GRP_ID_INVALID)
        {
            cui_file_selector_set_title(cui_gid, 0, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
            cui_file_selector_run(cui_gid);
            
            mmi_medply_plst_generic_exit_screen(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER, (mmi_proc_func)mmi_medply_plstdb_generate_entry_layer);
            mmi_frm_scrn_set_leave_proc(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER, mmi_medply_plstdb_generate_del_layer_callback);
        }
        else
        {   
            mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medlpy_plstui_allmedia_opt_add_selector_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medlpy_plstui_allmedia_opt_add_selector_handle(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_path[MEDPLY_MAX_PATH_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_select->result > 0)
    {
        cui_file_selector_get_selected_filepath(
                                file_select->sender_id,
                                NULL,
                                (WCHAR *) temp_path,
                                (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
        
        mmi_medply_plstui_allmedia_opt_add_part2(temp_path, MMI_FALSE);
    }
    else if (file_select->result == 0)
    {
    }
    else
    {
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
    cui_file_selector_close(file_select->sender_id);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_allmedia_opt_update_part_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_allmedia_opt_update_part_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    mmi_medply_plst_util_get_drv_status();
   
    ret = mmi_medply_plstdb_generate_init(GRP_ID_MEDPLY_PLST_PLAYLIST, list_p->list_scr_id, MMI_MEDPLY_GENERATE_UPDATE_ALL_DRV);

    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        if (mmi_medply_is_play_activated())
        {
            mdi_audio_suspend_background_play();
        }
        DB_ENABLE;
        DB_BEGIN_TRANSACTION;
        DB_DISABLE;
        mmi_medply_plst_generic_exit_screen(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER, (mmi_proc_func)mmi_medply_plstdb_generate_entry_layer);
        mmi_frm_scrn_set_leave_proc(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER, mmi_medply_plstdb_generate_del_layer_callback);
        mmi_medply_plstdb_generate_start();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_allmedia_opt_update_part_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_allmedia_opt_update_part_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_medply_plst_confirm_simple(GRP_ID_MEDPLY_PLST_PLAYLIST,
        (WCHAR *)get_string(STR_ID_MEDPLY_PLST_NOTIFY_BEFORE_UPDATE),
        mmi_medply_plstui_allmedia_opt_update_part_2,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_common_opt_intro
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_common_opt_intro(void)
{
#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);   

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif
    
	plst_cntx_p->list_cntx.intro.begin_idx = list_p->highlight;
    plst_cntx_p->list_cntx.intro.count = 0;
    plst_cntx_p->list_cntx.intro.plst_id = list_p->plstid;
    plst_cntx_p->list_cntx.intro.total = list_p->total;

    plst_cntx_p->list_cntx.intro.pick_idx = list_p->highlight;

	mmi_medply_single_intro_play();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_common_opt_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_common_opt_details(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_entry_details_internal();
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_common_opt_addto
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_common_opt_addto(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    mmi_medply_plstui_addto_entry(list_p->list_scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_common_opt_initiate_play_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_common_opt_initiate_play_internal(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  

    
    if (plst_cntx_p->list_cntx.playing.loaded)
    {
        if (plst_cntx_p->list_cntx.playing.plst_id!= list_p->plstid_original)
        {
			/*
            **	destory current "playing"
            */
            mmi_medply_playing_deinit();
            /*
            **	need replace "playing" info. 
            */
			mmi_medply_playing_init();
            mmi_medply_plst_save_last_list(list_p->plstid);
		}
		
        /*
		**	set selected item index and id.
		*/
        plst_cntx_p->list_cntx.playing.pick_index = list_p->highlight;
		
        /*
        **	check "main screen"
        */
	    if (!mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN))
        {
        	/* initiate play. */
            mmi_medply_play_from_play_list();
			/* delete option screen. */
			mmi_frm_group_close(GRP_ID_MEDPLY_PLST_PLAYLIST);
            mmi_frm_group_close(GRP_ID_MEDPLY_PLST_LISTMGR);
        }
        else
        {
        	mmi_frm_scrn_close(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN);
        	mmi_medply_play_from_play_list();
            /* initiate play from now playling list. */
			mmi_frm_group_close(GRP_ID_MEDPLY_PLST_PLAYLIST);
            mmi_frm_group_close(GRP_ID_MEDPLY_PLST_LISTMGR);
        }
    }
    else
    {
        /*
        **	need replace "playing" info. 
        */
		mmi_medply_playing_init();
		mmi_medply_plst_save_last_list(list_p->plstid);
		/*
		**	set selected item index and id.
		*/
        plst_cntx_p->list_cntx.playing.pick_index = list_p->highlight;

		/* initiate play. */
        mmi_medply_play_from_play_list();
		/* delete option screen. */
        mmi_frm_group_close(GRP_ID_MEDPLY_PLST_PLAYLIST);
        mmi_frm_group_close(GRP_ID_MEDPLY_PLST_LISTMGR);
    }
    /* reset highlight in main list screen. */
    mmi_medply_plst_post_event_to_main(EVT_ID_MEDPLY_RESET_MAINMENU, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_common_opt_initiate_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_common_opt_initiate_play(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);   

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif
    
    mmi_medply_plstui_reset_opt_data();
    list_p->add_ons.opt_data.curr_hilite_id = list_p->id_table.data[list_p->highlight];
    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_PATH, &(list_p->add_ons.opt_data.curr_hilite_id), list_p->add_ons.opt_data.curr_hilite_path);

	if (list_p->plstid == MMI_MEDPLY_DB_LST_RECENT_ID ||
        list_p->plstid == MMI_MEDPLY_DB_LST_MOST_PLAYED_ID) /* need mapping to dummy list. */
    {
    	U8 i = 0;
		U32 dummy_id = MMI_MEDPLY_DB_LST_DUMMEY_ID;
		ret = DB_ACTION1(MEDPLY_DB_ACT_MODIFY_PLST_CLEAR, &dummy_id);
        if (ret < 0)
        {
        	mmi_medply_plst_popup_simple(ret);
        }
        else
        {
        	/* max media number is 20, can do mapping blocking. */
            DB_ENABLE;
            DB_BEGIN_TRANSACTION;
            DB_DISABLE;
	        for (i = 0; i < list_p->total; i++)
	        {
				ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_ITEM_ADD_EXT, &(list_p->id_table.data[i]), &dummy_id, &i);
				if (ret < 0)
	            {
					break;
                }
	        }
            DB_ENABLE;
            if (ret < 0)
            {
				DB_ROLLBACK_TRANSACTION;
            }
            else
            {
				DB_COMMIT_TRANSACTION;
            }
            DB_DISABLE;
            if (ret < 0)
            {
                mmi_medply_plst_popup_simple(ret);
            }
            else
            {
	            /* reload dummy list to replace recently played/most played. */
		        list_p->plstid = MMI_MEDPLY_DB_LST_DUMMEY_ID;
		        mmi_ucs2ncpy((CHAR*)list_p->title, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_TITLE), MEDPLY_MAX_FILE_LEN - 1);
				mmi_medply_plstui_common_opt_initiate_play_internal();
            }
        }
    }
    else
    {
		mmi_medply_plstui_common_opt_initiate_play_internal();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_organize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_organize(void)
{   	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_medply_plstui_organize_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_add(void)
{   	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 total = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_MEDIA_TOTAL, &total);

	if (ret > 0 && total > 0)
    {
		mmi_medply_plstui_multiselect_entry(list_p->plstid);
    }
    else if (total == 0)
    {
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE);
    }
    else
    {
		mmi_medply_plst_popup_simple(ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_remove_part_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_remove_part_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    S32 next_pick_idx = 0;
    MMI_BOOL remove_playing = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    ret = DB_ACTION2(MEDPLY_DB_ACT_MODIFY_ITEM_REMOVE, &(list_p->add_ons.opt_data.curr_hilite_id), &(list_p->plstid));

    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        if (list_p->plstid == plst_cntx_p->list_cntx.playing.plst_id)
        {
            if (plst_cntx_p->list_cntx.playing.pick_index == list_p->highlight)/* remove now playing file. */
            {
                /* stop now playing. */
                //need set media type to NONE, to avoid states not change to IDLE.
                g_medply.media_type = MEDPLY_TYPE_NONE;
                mmi_medply_stop_playing();
                remove_playing = MMI_TRUE;
            }
			else 
            {
                next_pick_idx = plst_cntx_p->list_cntx.playing.pick_index;
                if (plst_cntx_p->list_cntx.playing.pick_index == plst_cntx_p->list_cntx.playing.total - 1)  //current highlighted last one, need decrease one with change of total.
                {
                    next_pick_idx--;
                }
                else if (plst_cntx_p->list_cntx.playing.pick_index > list_p->highlight) // the removed item behind playing item, pick index need decrease.
                {
                    next_pick_idx--;
                }
            }

	        if (mmi_medply_bitset_check(list_p->highlight)) // if the removed item had played, need clear its bitset, and decrease. 
            {
                plst_cntx_p->list_cntx.playing.pick_count--;
                /* clear bitset. */
                mmi_medply_bitset_clear(list_p->highlight);
	        }

            /* re-sort bitset. */
            mmi_medply_bitset_sort(list_p->highlight, 
                                        plst_cntx_p->list_cntx.playing.total);

            if (remove_playing && !mmi_medply_plst_curr_is_empty())
            {
                mmi_medply_plst_set_pick_index(next_pick_idx);
                mmi_medply_plst_apply_picked_file();
            }
            else if (mmi_medply_plst_curr_is_empty())
            {
                mmi_medply_plst_clear_context_variables();
            }
            else
            {
                plst_cntx_p->list_cntx.playing.pick_index = next_pick_idx;
            }
        }
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_REMOVED), MMI_EVENT_SUCCESS);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_PLAYLIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_remove_part_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_remove_part_1(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_medply_plst_confirm_simple(GRP_ID_MEDPLY_PLST_PLAYLIST,
        (WCHAR *)get_string(STR_ID_MEDPLY_PLST_NOTIFY_REMOVE_ASK),
        mmi_medply_plstui_playlist_opt_remove_part_2,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_clear_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_clear_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  
    
    StopTimer(MEDPLY_STATE_MACHINE_TIMER);
    StopTimer(MEDPLY_GENERATE_TIMER);
    DB_ENABLE;
    DB_ROLLBACK_TRANSACTION;
    DB_DISABLE;
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
    clear_list.rowid_begin = clear_list.rowid_end = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_remove_part_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_clear_internal(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    U32 limit = 50;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_frm_scrn_get_active_id() != SCR_ID_MEDPLY_PLST_WAIT_SCREEN)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_IN_SLEEP);
        /* Sleep if the waitting screen has been in history. */
        StartTimer(MEDPLY_GENERATE_TIMER, 500, mmi_medply_plstui_playlist_opt_clear_internal);
        return;
    }

    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    ret = DB_ACTION3(MEDPLY_DB_ACT_QUERY_PLST_MAX_ROWID, &clear_list.rowid_begin, &limit, &clear_list.rowid_end);
    if (ret >= 0)
    {
        if (clear_list.rowid_end > clear_list.rowid_begin)
        {
            ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_PLST_CLEAR_SUB, 
                         &list_p->plstid, 
                         &clear_list.rowid_begin, 
                         &clear_list.rowid_end);
            if (ret >= 0)
            {
                clear_list.rowid_begin = clear_list.rowid_end;
                StartTimer(MEDPLY_STATE_MACHINE_TIMER, 50, mmi_medply_plstui_playlist_opt_clear_internal);
                return;
            }            
        }
    }

    if (ret < 0)
    {
        DB_ENABLE;
        DB_ROLLBACK_TRANSACTION;
        DB_DISABLE;
        if (mdi_audio_is_background_play_suspended())
        {
            mdi_audio_resume_background_play();
        }
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        DB_ENABLE;
        DB_COMMIT_TRANSACTION;
        DB_DISABLE;
        if (mdi_audio_is_background_play_suspended())
        {
            mdi_audio_resume_background_play();
        }
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_PLAYLIST);
    } 
    clear_list.rowid_begin = clear_list.rowid_end = 0;
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_clear_wait_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_clear_wait_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_WAIT_SCREEN, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_PLST_WAIT_SCREEN, 
        SCR_ID_MEDPLY_PLST_WAIT_SCREEN, 
        NULL, 
        mmi_medply_plstui_playlist_clear_wait_screen_entry, 
        MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }    
//#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
//    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
//#endif
    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(mmi_medply_plstui_playlist_opt_clear_cancel, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_clear_part_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_clear_part_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    clear_list.rowid_begin = 0;
    clear_list.rowid_end = 0;
    
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }    
    
    DB_ENABLE;
    DB_BEGIN_TRANSACTION;
    DB_DISABLE;
    mmi_medply_plstui_playlist_clear_wait_screen_entry();
    StartTimer(MEDPLY_STATE_MACHINE_TIMER, 50, mmi_medply_plstui_playlist_opt_clear_internal); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_clear_part_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_clear_part_1(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type str[MEDPLY_MAX_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) str, (CHAR*) GetString(STR_ID_MEDPLY_PLST_CLEAR_LIST));
    mmi_ucs2cat((CHAR*) str, (CHAR*) GetString(STR_ID_FMGR_QUESTION_MARK));
    
    mmi_medply_plst_confirm_simple(GRP_ID_MEDPLY_PLST_PLAYLIST,
        (WCHAR *)str,
        mmi_medply_plstui_playlist_opt_clear_part_2,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_PLST_OPT);
    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    mmi_medply_plstui_reset_opt_data();
// hide not support menu items.
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SORT_BY, MMI_TRUE);
// unhide support menu items.
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_PLAY, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_DETAILS, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_ADD_TO, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_USE, MMI_FALSE);
#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_INTRO, MMI_FALSE);
#endif
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ADD, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST, MMI_FALSE);
    
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_UPDATE, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_ADD, MMI_FALSE);
#ifdef __MMI_RMGR__
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMGR_GEN_OPTION_MORE_RITS, MMI_FALSE);
#endif
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_SEARCH, MMI_FALSE);

    // all media files
    if (list_p->plstid == MMI_MEDPLY_DB_LST_ALL_MEDIA_ID)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ADD, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST, MMI_TRUE);
    }
    else    // other list
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_SEARCH, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_UPDATE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_ADD, MMI_TRUE);

        if (list_p->plstid != MMI_MEDPLY_DB_LST_ON_THE_FLY_ID &&
            list_p->plstid != MMI_MEDPLY_DB_LST_RECENT_ID &&
            list_p->plstid != MMI_MEDPLY_DB_LST_MOST_PLAYED_ID &&
            list_p->plstid != MMI_MEDPLY_DB_LST_DUMMEY_ID &&
            list_p->plstid != MMI_MEDPLY_DB_LST_BOOKMARK_ID)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ADD, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ADD, MMI_TRUE);
        }
    }
    
    if (list_p->total)
    {
        // fill opt data
        list_p->add_ons.opt_data.curr_hilite_id = list_p->id_table.data[list_p->highlight];
        ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_PATH, &(list_p->add_ons.opt_data.curr_hilite_id), list_p->add_ons.opt_data.curr_hilite_path);

        if (list_p->plstid == MMI_MEDPLY_DB_LST_RECENT_ID)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ADD, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE, MMI_TRUE);
        }
        else if (list_p->plstid == MMI_MEDPLY_DB_LST_MOST_PLAYED_ID)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ADD, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR, MMI_TRUE);
        }
        else
        {
            if (list_p->total == 1)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR, MMI_TRUE);
            }
            else
            {
                if (plst_cntx_p->list_cntx.playing.plst_id == list_p->plstid)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR, MMI_TRUE);
                }
            }

            if (plst_cntx_p->list_cntx.playing.id == list_p->add_ons.opt_data.curr_hilite_id &&
                plst_cntx_p->list_cntx.playing.plst_id == list_p->plstid)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE, MMI_TRUE);
            }
        }
        

        if (0 < srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR *)list_p->add_ons.opt_data.curr_hilite_path))
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND, MMI_FALSE);
        }
        else
        {
           cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND, MMI_TRUE);
        }

        if (0 < srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR *)list_p->add_ons.opt_data.curr_hilite_path))
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_USE, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_USE, MMI_TRUE);
        }

#ifdef __MMI_RMGR__
        //@TODO:
        if(!DRM_rights_extendable((kal_wchar*)list_p->add_ons.opt_data.curr_hilite_path) ||
           !srv_nw_usab_is_any_network_available() ||
           srv_mode_switch_is_network_service_available())
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMGR_GEN_OPTION_MORE_RITS, MMI_TRUE);
            //list_p->add_ons.opt_data.is_show_rit = MMI_FALSE;
        }
        else
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMGR_GEN_OPTION_MORE_RITS, MMI_FALSE);
            mmi_rmgr_set_ro_bound_path(list_p->add_ons.opt_data.curr_hilite_path);
            //list_p->add_ons.opt_data.is_show_rit  = MMI_TRUE;
        }
#endif
    }
    else
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_ALL_MEDIA_OPT_SEARCH, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_PLAY, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_DETAILS, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_ADD_TO, MMI_TRUE);
#ifdef __MMI_RMGR__
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMGR_GEN_OPTION_MORE_RITS, MMI_TRUE);
#endif
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_USE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_REMOVE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_CLEAR, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LIST_OPT_ORGANIZE_LIST, MMI_TRUE);
#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_INTRO, MMI_TRUE);
#endif
    }

    
    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND, MMI_TRUE);
    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_USE, MMI_TRUE);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_opt_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_LISTMGR_OPT);
    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_PLAYLIST, GRP_ID_MEDPLY_PLST_PLAYLIST_OPT, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_PLAYLIST_OPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create( GRP_ID_MEDPLY_PLST_PLAYLIST_OPT,
                        	CUI_MENU_SRC_TYPE_RESOURCE,
                        	CUI_MENU_TYPE_OPTION,
                        	MENU_ID_MEDPLY_PLST_LIST_OPT,
                        	MMI_TRUE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_get_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_playlist_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 cur_id = 0;
	UI_character_type artist[MMI_MEDPLY_MAX_ARTISRT_LEN];
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    cur_id = list_p->id_table.data[item_index];

	if (cur_id == 0)
    {
		return 0;
    }

    if (list_p->hint_cache.hint_idx != item_index)
    {
		// because the hint buffer limit, just display artist. 
	    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_ARTIST_NAME, &cur_id, artist);

	    if (ret >= 0)
	    {
			if (artist[0] != 0)
	        {
				S32 len = mmi_ucs2strlen((const CHAR*)artist);

	            if (len > MAX_SUBMENU_CHARACTERS)
	            {
					mmi_ucs2ncpy((CHAR*)*hint_array, (const CHAR*)artist, MAX_SUBMENU_CHARACTERS);
	            }
	            else
	            {
					mmi_ucs2ncpy((CHAR*)*hint_array, (const CHAR*)artist, MAX_SUBMENU_CHARACTERS);
	            }
				list_p->hint_cache.hint_idx = item_index;
                mmi_ucs2ncpy((CHAR*)list_p->hint_cache.hint_buff, (const CHAR*)*hint_array, MAX_SUBMENU_CHARACTERS);

	            return 1;
	        }
            else
            {
                list_p->hint_cache.hint_idx = item_index;
                list_p->hint_cache.hint_buff[0] = 0;
            }
	    }
    }
    else
    {
    	if (list_p->hint_cache.hint_buff[0] != 0)
        {
			mmi_ucs2ncpy((CHAR*)*hint_array, (const CHAR*)list_p->hint_cache.hint_buff, MAX_SUBMENU_CHARACTERS);
			return 1;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_medply_plstui_playlist_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_id = 0;
    S32 ret = 0;

	U8 i = 0;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    mmi_medply_plstui_db_cache_item_struct item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
	current_id = list_p->id_table.data[item_idx];
	/* check the request item whether in cache. */
    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == current_id &&
            list_p->db_cache[i].title[0] != 0)
        {
			mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)list_p->db_cache[i].title, MEDPLY_MAX_FILE_LEN -1);
			*img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(list_p->db_cache[i].format));
            return MMI_TRUE;
        }
    }

	/* out of cache. */
    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_LIST_INFO, 
            			&(list_p->id_table.data[item_idx]), &item);
    if (ret < 0)
    {
	    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_LOAD_CACHE_FAIL, ret, __LINE__);
        mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)GetString(STR_GLOBAL_LOADING), MEDPLY_MAX_FILE_LEN -1);
	    *img_buff_p = NULL;
	    return MMI_TRUE;
    }

	/* update cache. */
	for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == 0 &&
            list_p->db_cache[i].title[0] == 0)
        {
			/* get an empty cache item. */
            break;
        }
    }

	if (i < MMI_MEDPLY_LIST_BUFF_SIZE)
    {
		/* cache is not full. just need update tail. */
        memcpy(&(list_p->db_cache[i]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
		list_p->tail = i;
    }
    else
    {
		/* cache is full, need replace the oldest one. */
 		memcpy(&(list_p->db_cache[list_p->head]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
       	if (list_p->head == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
	    {
			list_p->head = 0;
	    }
	    else
	    {
	    	list_p->head++;
	    }
		if (list_p->tail == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
		{
			list_p->tail = 0;
		}
		else
		{
			list_p->tail++;
		}
    }
    
    mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)item.title, MEDPLY_MAX_FILE_LEN -1);

    *img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(item.format));
	
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_playlist_prepare(U32 plstid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 total = 0;
    S32 ret = 0;
	U16 title_id = 0;
    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    
	list_p->plstid = plstid;
    list_p->plstid_original = plstid;
	/* get title. */
	if (plstid <= MMI_MEDPLY_DB_LST_ON_THE_FLY_ID)
	{
		switch (plstid)
	    {
			case MMI_MEDPLY_DB_LST_ALL_MEDIA_ID:
				title_id = STR_ID_MEDPLY_ALL_MEDIA;
	            break;
	        case MMI_MEDPLY_DB_LST_RECENT_ID:
	            title_id = STR_ID_MEDPLY_PLST_RECENTLY;
	            break;
	        case MMI_MEDPLY_DB_LST_BOOKMARK_ID:
	            title_id = STR_ID_MEDPLY_BOOKMARK;
	            break;
	        case MMI_MEDPLY_DB_LST_FAVOURITE_ID:
	            title_id = STR_ID_MEDPLY_PLST_MY_FAVOURITE;
	            break;
	        case MMI_MEDPLY_DB_LST_MOST_PLAYED_ID:
	            title_id = STR_ID_MEDPLY_PLST_MOST;
	            break;
	        case MMI_MEDPLY_DB_LST_ON_THE_FLY_ID:
	            title_id = STR_ID_MEDPLY_PLST_ON_THE_FLY;
	            break;
	        case MMI_MEDPLY_DB_LST_DUMMEY_ID:
	            title_id = STR_ID_MEDPLY_PLST_TITLE;
	            break;
	    }
		mmi_ucs2ncpy((CHAR*)list_p->title, (const CHAR*)GetString(title_id), MEDPLY_MAX_FILE_LEN - 1);
	}
	else
	{
		ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TITLE, 
            						&plstid, list_p->title);
	    if (ret < 0)
	    {
	        return ret;
	    }
	}
	/* reset hint cache. */
	list_p->hint_cache.hint_idx = -1;
    list_p->hint_cache.hint_buff[0] = 0;

    /* get list data. */
	if (plstid == MMI_MEDPLY_DB_LST_MOST_PLAYED_ID)
	{
		/* mapping to dummy list */
        if (list_p->id_table.data != NULL)
        {
		 	kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
		 	MEM_TRC_FREE(list_p->id_table, __LINE__);
		 	list_p->id_table.data = NULL;
		    list_p->id_table.size = 0;
        }
		MMI_ASSERT(list_p->id_table.data == NULL);
        list_p->id_table.pattern = 0xFEFEFEFE;
        list_p->id_table.size = sizeof(U32) * MEDPLY_MAX_MOST_PLAYED_ITEM;
	    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

	    if (list_p->id_table.data == NULL)
	    {
	        ret = MEDPLY_PLST_ERR_NO_MEMORY;
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);
	    }
	    else
	    {
	    	MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
			ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_MOST_TBL, 
										&(list_p->id_table), &total);
	        if (ret < 0)
		    {
		    	kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	            MEM_TRC_FREE(list_p->id_table.data, __LINE__);
	            list_p->id_table.data = NULL;
                list_p->id_table.size = 0;
		    }
	        else if (!total)
	        {
				kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	            MEM_TRC_FREE(list_p->id_table.data, __LINE__);
	            list_p->id_table.data = NULL;
			}
            else
            {
	        	list_p->total = total;
            }
	    }
	}
	else if (plstid == MMI_MEDPLY_DB_LST_RECENT_ID)
	{
		/* mapping to dummy list */
        if (list_p->id_table.data != NULL)
        {
		 	kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
		 	MEM_TRC_FREE(list_p->id_table, __LINE__);
		 	list_p->id_table.data = NULL;
		    list_p->id_table.size = 0;
        }
		MMI_ASSERT(list_p->id_table.data == NULL);
        list_p->id_table.pattern = 0xFEFEFEFE;
        list_p->id_table.size = sizeof(U32) * MEDPLY_MAX_MOST_PLAYED_ITEM;
	    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

	    if (list_p->id_table.data == NULL)
	    {
	       ret = MEDPLY_PLST_ERR_NO_MEMORY;
           MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);
	    }
	    else
	    {
	    	MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
			ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_RECENT_TBL, 
										&(list_p->id_table), &total);
	        if (ret < 0)
		    {
		    	kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	            MEM_TRC_FREE(list_p->id_table.data, __LINE__);
	            list_p->id_table.data = NULL;
                list_p->id_table.size = 0;
		    }
	        else if (!total)
	        {
				kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	            MEM_TRC_FREE(list_p->id_table.data, __LINE__);
	            list_p->id_table.data = NULL;
                list_p->id_table.size = 0;
	        }
            else
            {
	        	list_p->total = total;
            }
	    }
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
    #endif
	else
	{
		ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TOTAL, &plstid, &total);
	    if (ret >= 0)
	    {	    
		    list_p->total = total;

		    if (list_p->total)
		    {
		    	if (list_p->id_table.data != NULL)
		        {
				 	kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
				 	MEM_TRC_FREE(list_p->id_table, __LINE__);
				 	list_p->id_table.data = NULL;
				    list_p->id_table.size = 0;
		        }
		    	MMI_ASSERT(list_p->id_table.data == NULL);
		        list_p->id_table.pattern = 0xFEFEFEFE;
		        list_p->id_table.size = sizeof(U32) * list_p->total;
			    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

		        if (list_p->id_table.data == NULL)
		        {
		            ret = MEDPLY_PLST_ERR_NO_MEMORY;
                    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);

		        }
		        else
		        {
		        	MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
					ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TBL, 
										&plstid, &(list_p->id_table));
		            if (ret < 0)
		            {
		                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
		                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
		                list_p->id_table.data = NULL;
                        list_p->id_table.size = 0;
		            }
		        }
            }
	    }
	}
    
    return ret;
}



/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_playlist_del_scr_callback
* DESCRIPTION
*  
* PARAMETERS
*  in_param		[IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_medply_plstui_playlist_del_scr_callback(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_medply_plstui_list_cache_struct *list_p = NULL;

            list_p = mmi_medply_plstui_get_curr_list_cache();
            MMI_ASSERT(list_p != NULL); 
            
            if (list_p->id_table.data != NULL)
            {
                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
                list_p->id_table.data = NULL;
            }
            
            
            mmi_medply_plstui_destory_list_cache();
            break;
        }
    }
    return MMI_RET_OK;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_playlist_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 id = 0;
    S32 ret = 0;
    U8 *guiBuffer = NULL;
    U16 lsk_string = 0;
    U16 lsk_image = 0;
	MMI_BOOL no_lsk_hdlr = MMI_FALSE;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_PLST, list_p->plstid);

    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_PLAYLIST, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_PLAYLIST, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_PLAYLIST, NULL, mmi_medply_plstui_playlist_entry_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
	if (list_p->plstid == plst_cntx_p->list_cntx.playing.plst_id &&
        mdi_audio_is_background_play_suspended())
    {
		mdi_audio_resume_background_play();
    }
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_PLAYLIST, mmi_medply_plstui_playlist_del_scr_callback);

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_PLAYLIST);

    if (!guiBuffer)
    {
    	id = list_p->plstid;
    	mmi_medply_plstui_reset_cache();
        ret = mmi_medply_plstui_playlist_prepare(id);
        list_p->list_grp_id = GRP_ID_MEDPLY_PLST_PLAYLIST;
        list_p->list_scr_id = SCR_ID_MEDPLY_PLST_PLAYLIST;
        if (ret < 0)
        {
			mmi_medply_plst_popup_simple(ret);
            mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_PLAYLIST);
            if (g_medply_plst_is_current_list > 0)
            {
                g_medply_plst_is_current_list = 0;
            }
            return;
        }
        else
        {
        	/* update playing context */
			if (list_p->plstid == plst_cntx_p->list_cntx.playing.plst_id)
            {
				plst_cntx_p->list_cntx.playing.total = list_p->total;
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->list_cntx.playing.title,
                    		 (const CHAR*)list_p->title, MEDPLY_MAX_FILE_LEN - 1);
                if (g_medply_plst_is_current_list > 0)
                {
                    list_p->highlight = plst_cntx_p->list_cntx.playing.pick_index;
                    g_medply_plst_is_current_list = 0;
                }
            }
        }
    }    

    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_plstui_common_highlight_hdlr);

	if (list_p->total)
    {
		lsk_string = STR_GLOBAL_OPTIONS;
        lsk_image = IMG_GLOBAL_OPTIONS;
    }
    else
    {
		if (list_p->plstid <= MMI_MEDPLY_DB_LST_ON_THE_FLY_ID && 
            list_p->plstid != MMI_MEDPLY_DB_LST_ALL_MEDIA_ID)
	    {
			lsk_string = 0;
            lsk_image = 0;
            no_lsk_hdlr = MMI_TRUE;
	    }
	    else
	    {
			lsk_string = STR_GLOBAL_OPTIONS;
        	lsk_image = IMG_GLOBAL_OPTIONS;
	    }
    }
    
    
	if (list_p->total)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    else
    {
		if (list_p->plstid <= MMI_MEDPLY_DB_LST_ON_THE_FLY_ID && 
            list_p->plstid != MMI_MEDPLY_DB_LST_ALL_MEDIA_ID)
	    {
            EnableCenterSoftkey(0, 0);
	    }
	    else
	    {
            EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
	    }
    }
    
    if (list_p->total == 0)
    {
        ShowCategory353Screen(
            (PU8)list_p->title,
            GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
            lsk_string,
            lsk_image,
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
        memset(&(list_p->hint_cache), 0, sizeof(mmi_medply_plstui_hint_cache_struct));
        list_p->hint_cache.hint_idx = -1;
        ShowCategory183Screen(
            list_p->title, 
            get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
            get_string(lsk_string),
            get_image(lsk_image),              
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK), 
            list_p->total,
            mmi_medply_plstui_playlist_get_item,
            mmi_medply_plstui_playlist_get_hint,
            list_p->highlight,
            MMI_FALSE,
            NULL,
            guiBuffer);
    }

    /* register LSK, RSK hanlders */
	if (list_p->total)
    {
    #ifdef __MMI_FTE_SUPPORT__ 
        wgui_register_tap_callback(mmi_medply_plstui_tap_callback);
    #endif
        SetCenterSoftkeyFunction(mmi_medply_plstui_common_opt_initiate_play, KEY_EVENT_UP);
    }
    else
    {
		if (list_p->plstid <= MMI_MEDPLY_DB_LST_ON_THE_FLY_ID && 
            list_p->plstid != MMI_MEDPLY_DB_LST_ALL_MEDIA_ID)
	    {
            SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
	    }
	    else
	    {
            SetCenterSoftkeyFunction(mmi_medply_plstui_playlist_opt_entry_scr, KEY_EVENT_UP);
	    }
    }

    if (!no_lsk_hdlr)
    {
        SetLeftSoftkeyFunction(mmi_medply_plstui_playlist_opt_entry_scr, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_allmedia_entry
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_plstui_allmedia_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0; 
    mmi_medply_plstui_list_cache_struct *list_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_plstui_create_list_cache();
	if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        list_p = mmi_medply_plstui_get_curr_list_cache();
    	MMI_ASSERT(list_p != NULL); 
        list_p->plstid = MMI_MEDPLY_DB_LST_ALL_MEDIA_ID;
		mmi_medply_plstui_playlist_entry_scr();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_playlist_entry
* DESCRIPTION
*  
* PARAMETERS
*  plst_id		[IN]
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_playlist_entry(U32 plst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0; 
    mmi_medply_plstui_list_cache_struct *list_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_plstui_create_list_cache();
	if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        list_p = mmi_medply_plstui_get_curr_list_cache();
    	MMI_ASSERT(list_p != NULL); 
        list_p->plstid = plst_id;
		mmi_medply_plstui_playlist_entry_scr();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_nowplaying_entry
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_nowplaying_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0; 
    mmi_medply_plstui_list_cache_struct *list_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_plstui_create_list_cache();
	if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        list_p = mmi_medply_plstui_get_curr_list_cache();
    	MMI_ASSERT(list_p != NULL); 
        list_p->plstid = plst_cntx_p->list_cntx.playing.plst_id;
        g_medply_plst_is_current_list = 1;
        mmi_medply_plstui_playlist_entry_scr();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_entry_now_playing
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_plst_entry_now_playing(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_medply_plstui_nowplaying_entry();
}
#define __BOOKMARK
/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_bmk_create_ram_file
* DESCRIPTION
*  
* PARAMETERS
*  ram_path     [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_plstui_bmk_create_ram_file(UI_string_type ram_path)
{
#ifdef __MMI_MEDIA_PLAYER_STREAM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR url_buf[MEDPLY_MAX_PATH_LEN];
    U32 str_len = 0;
    U32 written = 0;
	S32 ret = 0;
    FS_HANDLE fs_hdlr = -1;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    ret = FS_Open(ram_path, FS_CREATE_ALWAYS);
    if (ret >= 0)
    {
        fs_hdlr = ret;
        //@TODO: bql: recheck if can be removed!!
        /*
        if (IsScreenPresent(SCR_ID_MEDPLY_SINGLE_MAIN))
        {
            mmi_ucs2_to_asc((CHAR*)url_buf, (CHAR*)g_single.url_path);
        }
        else
        */
        {
            mmi_ucs2_to_asc((CHAR*)url_buf, (CHAR*)list_p->add_ons.opt_data.curr_hilite_path);
        }
        str_len = strlen(url_buf) + 1; /* +1 for null terminate */

        ret = FS_Write(fs_hdlr, url_buf, str_len, &written);

        if (ret < 0)
        {           
            FS_Close(fs_hdlr);
            return ret;
        }
        else
        {
            /* url saved */
            FS_Close(fs_hdlr);
            return 0;
        }
    }
    else
    {         
        return ret;
    }
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_save_ram_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_save_ram_part2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ptr = NULL;
    S32 len = 0;
    S32 ret = 0;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    ptr = (CHAR*)srv_fmgr_path_skip_leading_space((WCHAR*)(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer));

    if (ptr != (CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer)
    {
        mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_INVALID_FILENAME), MMI_EVENT_ERROR);
        return;
    }
    
    len = mmi_ucs2strlen(ptr);

    if (len == 0)
    {
        mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME), MMI_EVENT_ERROR);
        return;
    }
    if (ptr[0] == '.' ||
        !srv_fmgr_path_is_filename_valid((const WCHAR*)(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer)))
    {
        mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_INVALID_FILENAME), MMI_EVENT_ERROR);
        return;
    }

    kal_wsprintf(path, "%c:\\%w", SRV_FMGR_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_VIDEO);
    ret = mmi_medply_util_create_file_dir(path);

    if (ret < 0)
    {
        //file system error
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        mmi_ucs2cat((CHAR*)path, (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
        mmi_ucs2cat((CHAR*)path, (const CHAR*)L".ram");

        ret = FS_Open(path, FS_READ_ONLY);

        if (ret < 0)
        {
            //Create file
            ret = mmi_medply_plstui_bmk_create_ram_file(path);
            if (ret < 0)
            {
                mmi_medply_plst_popup_simple(ret);
            }
            else
            {
                //add to database.
                ret = mmi_medply_db_append_record(path, MMI_FALSE, MMI_MEDPLY_DB_LST_ALL_MEDIA_ID);
                if (ret >= FS_NO_ERROR)
                {
                    mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
                }
                else
                {
                    mmi_medply_plst_popup_simple(ret);
                }
            }
        }
        else
        {
            FS_Close(ret);
            //file exist
            mmi_medply_plst_popup_simple(FS_FILE_EXISTS);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_save_ram_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_save_ram_part1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	mmi_medply_editor_create(
	                    GRP_ID_MEDPLY_PLST_BOOKMARK,
    					MMI_MEDPLY_EDITOR_SAVE_RAM,
    					MEDPLY_MAX_INPUT_FILE_LEN,
    					STR_GLOBAL_EDIT,
    					NULL,
    					NULL,
    					mmi_medply_plstui_bmk_opt_save_ram_part2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_preview
 * DESCRIPTION
 *  initiate play with single player.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type preview_path[MMI_MEDPLY_MAX_URL_LEN + 1];
    U32 preview_id = 0;
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

	preview_id = list_p->id_table.data[list_p->highlight];
	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_BMK_URL, &preview_id, preview_path);

	if (ret < 0)
	{
		mmi_medply_plst_popup_simple(ret);
	}
	else
	{
	#ifdef __MMI_MEDIA_PLAYER_STREAM__  
        mmi_medply_single_play_stream_from_rtsp_link(preview_path);
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_delete_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_delete_part2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    ret = DB_ACTION1(MEDPLY_DB_ACT_MODIFY_BMK_REMOVE, &(list_p->add_ons.opt_data.curr_hilite_id));
    
    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_BOOKMARK, SCR_ID_MEDPLY_PLST_BOOKMARK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_delete_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_delete_part1(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type str[MEDPLY_MAX_FILE_LEN + 25];
    U8 i = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);	
    
    memset(str, 0, sizeof(str));

    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
        if (list_p->db_cache[i].media_id == list_p->id_table.data[list_p->highlight])
        {
            break;
        }
    }
    MMI_ASSERT(i < MMI_MEDPLY_LIST_BUFF_SIZE);

	kal_wsprintf(str, "%w%w\n%w", 
		             get_string(STR_GLOBAL_DELETE), 
		             get_string(STR_ID_FMGR_QUESTION_MARK),
		             list_p->db_cache[i].title);
    
	MMI_ASSERT(mmi_ucs2strlen((const CHAR*)str) < MEDPLY_MAX_FILE_LEN + 25);

    mmi_medply_plst_confirm_simple(
        GRP_ID_MEDPLY_PLST_BOOKMARK,
        (WCHAR *)str,
        mmi_medply_plstui_bmk_opt_delete_part2,
        CNFM_TYPE_YESNO,
        MMI_TRUE,
        MMI_EVENT_QUERY);     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_clear_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_clear_part2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    mmi_medply_util_entry_wait_scr();
    ret = DB_ACTION0(MEDPLY_DB_ACT_MODIFY_BMK_CLEAR);
    
    if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
        mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
    }
    else
    {
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_BOOKMARK, SCR_ID_MEDPLY_PLST_BOOKMARK);
        mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_clear_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_clear_part1(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type str[MEDPLY_MAX_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) str, (CHAR*) GetString(STR_GLOBAL_DELETE_ALL));
    mmi_ucs2cat((CHAR*) str, (CHAR*) GetString(STR_ID_FMGR_QUESTION_MARK));

    mmi_medply_plst_confirm_simple(
        GRP_ID_MEDPLY_PLST_BOOKMARK,
        (WCHAR *)str,
        mmi_medply_plstui_bmk_opt_clear_part2,
        CNFM_TYPE_YESNO,
        MMI_TRUE,
        MMI_EVENT_QUERY);     

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_new_part3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url_p           [IN]
 *  name_p          [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plstui_bmk_opt_new_part3(CHAR* url_p, CHAR* name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* real_name_p = 0;
    S32 len = 0;
    S32 ret = 0;
    mmi_medply_db_bookmark_item_struct item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_ASSERT(url_p != NULL);
    MMI_ASSERT(name_p != NULL);  

    real_name_p = mmi_ucs2rchr((const CHAR*)name_p, (U16)'\\');
    if (real_name_p == NULL)
    {
        real_name_p = name_p;
    }
    else
    {
        real_name_p += 2;
    }
    mmi_ucs2ncpy((CHAR*)item.title, (const CHAR*)real_name_p, MEDPLY_MAX_FILE_LEN - 1);
    mmi_ucs2ncpy((CHAR*)item.url, (const CHAR*)url_p, MMI_MEDPLY_MAX_URL_LEN - 1);
    mmi_ucs2lwr((CHAR*)item.url);
	item.type = MEDPLY_FORMAT_RTSP;
    /* calculate CRC */
	len = mmi_ucs2strlen((const CHAR*)item.url);
	len <<= 1;
	item.url_hash = med_crc_calculate((kal_uint8* const)item.url, len);
    

    ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_BMK_EXIST, &item.url_hash);
    if (MEDPLY_PLST_GOT_DATA != ret)
	{
        ret = DB_ACTION1(MEDPLY_DB_ACT_MODIFY_BMK_ADD, &item);

        if (ret >= 0)
    	{      
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_BOOKMARK, SCR_ID_MEDPLY_PLST_BOOKMARK);
        }
    }
    else
    {
		ret = MEDPLY_PLST_ERR_ITEM_EXISTS;
    }
	
	return ret;    
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_bmk_opt_new_part2
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_bmk_opt_new_part2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (!mmi_ucs2nicmp((const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, (const CHAR*)L"RTSP://", 7))
    {
        /* rtsp url. */
        /* TODO: call play rtsp API here, and entry player screen. */
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        mmi_medply_single_play_stream_from_rtsp_link(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
    #endif
        /* delete: editor option, editor */
        //DeleteUptoScrID(SCR_ID_MEDPLY_PLST_BOOKMARK);              
        return;
    }
    /* invalid url. */
    mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_INVALID_URL), MMI_EVENT_ERROR);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_bmk_opt_new_part1
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_bmk_opt_new_part1(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_medply_editor_create(
	                    GRP_ID_MEDPLY_PLST_BOOKMARK,
    					MMI_MEDPLY_EDITOR_NEW_URL,
    					MMI_MEDPLY_MAX_URL_LEN,
    					STR_ID_MEDPLY_PLST_INPUT_URL,
    					NULL,
    					L"rtsp://",
    					mmi_medply_plstui_bmk_opt_new_part2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    mmi_medply_plstui_reset_opt_data();

    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_PREVIEW, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_EDIT, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETEALL, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_SAVE_RAM, MMI_TRUE);
    
    if (list_p->total)
    {
        // fill opt data
        list_p->add_ons.opt_data.curr_hilite_id = list_p->id_table.data[list_p->highlight];
        ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_BMK_URL, &(list_p->add_ons.opt_data.curr_hilite_id), list_p->add_ons.opt_data.curr_hilite_path);

        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_PREVIEW, MMI_FALSE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETE, MMI_FALSE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_SAVE_RAM, MMI_FALSE);
        
        if (list_p->total > 1)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_BOOKMARK_OPT_DELETEALL, MMI_FALSE);
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_opt_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_bmk_opt_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_BOOKMARK, GRP_ID_MEDPLY_PLST_BOOKMARK_OPT, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_BOOKMARK_OPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create( 
                            GRP_ID_MEDPLY_PLST_BOOKMARK_OPT,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_OPTION,
                            MENU_ID_MEDPLY_PLST_BOOKMARK_OPT,
                            MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_medply_plstui_bmk_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_id = 0;
    S32 ret = 0;
	
	U8 i = 0;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    mmi_medply_plstui_db_cache_item_struct item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
	current_id = list_p->id_table.data[item_idx];
	/* check the request item whether in cache. */
    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == current_id &&
            list_p->db_cache[i].title[0] != 0)
        {
			mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)list_p->db_cache[i].title, MEDPLY_MAX_FILE_LEN -1);
			*img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(list_p->db_cache[i].format));
            return MMI_TRUE;
        }
    }

	/* out of cache. */
    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_BMK_INFO, 
            			&(list_p->id_table.data[item_idx]), &item);
    if (ret < 0)
    {
	    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_LOAD_CACHE_FAIL, ret, __LINE__);
        mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)GetString(STR_GLOBAL_LOADING), MEDPLY_MAX_FILE_LEN -1);
	    *img_buff_p = NULL;
	    return MMI_TRUE;
    }

	/* update cache. */
	for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == 0 &&
            list_p->db_cache[i].title[0] == 0)
        {
			/* get an empty cache item. */
            break;
        }
    }

	if (i < MMI_MEDPLY_LIST_BUFF_SIZE)
    {
		/* cache is not full. just need update tail. */
        memcpy(&(list_p->db_cache[i]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
		list_p->tail = i;
    }
    else
    {
		/* cache is full, need replace the oldest one. */
 		memcpy(&(list_p->db_cache[list_p->head]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
       	if (list_p->head == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
	    {
			list_p->head = 0;
	    }
	    else
	    {
	    	list_p->head++;
	    }
		if (list_p->tail == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
		{
			list_p->tail = 0;
		}
		else
		{
			list_p->tail++;
		}
    }
    
    mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)item.title, MEDPLY_MAX_FILE_LEN -1);

    *img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(item.format));
	
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_bmk_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_bmk_prepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 total = 0;
    S32 ret = 0;
	    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    
	list_p->plstid = MMI_MEDPLY_DB_LST_BOOKMARK_ID;
    list_p->plstid_original = MMI_MEDPLY_DB_LST_BOOKMARK_ID;
	/* get title. */
	mmi_ucs2ncpy((CHAR*)list_p->title, (const CHAR*)GetString(STR_ID_MEDPLY_BOOKMARK), MEDPLY_MAX_FILE_LEN - 1);

    /* reset hint cache. */
	list_p->hint_cache.hint_idx = -1;
    list_p->hint_cache.hint_buff[0] = 0;

	ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_BMK_TOTAL, &total);
	if (ret >= 0)
	{	    
	    list_p->total = total;

	    if (list_p->total)
	    {
	    	if (list_p->id_table.data != NULL)
	        {
			 	kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
			 	MEM_TRC_FREE(list_p->id_table, __LINE__);
			 	list_p->id_table.data = NULL;
			    list_p->id_table.size = 0;
	        }
	    	MMI_ASSERT(list_p->id_table.data == NULL);
	        list_p->id_table.size = sizeof(U32) * list_p->total;
		    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

	        if (list_p->id_table.data == NULL)
	        {
	            ret = MEDPLY_PLST_ERR_NO_MEMORY;
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);

	        }
	        else
	        {
	        	MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
				ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_BMK_LIST, &(list_p->id_table));
	            if (ret < 0)
	            {
	                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
	                list_p->id_table.data = NULL;
                    list_p->id_table.size = 0;
	            }
	        }
        }
	}
	
    return ret;
}




/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_bmk_del_scr_callback
* DESCRIPTION
*  
* PARAMETERS
*  in_param		[IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_medply_plstui_bmk_del_scr_callback(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            list_p = mmi_medply_plstui_get_curr_list_cache();
            MMI_ASSERT(list_p != NULL); 
            
            if (list_p->id_table.data != NULL)
            {
                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
                list_p->id_table.data = NULL;
            }
            
            
            mmi_medply_plstui_destory_list_cache();
            break;
        }
    }
    return MMI_RET_OK;

}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_bmk_entry_scr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_bmk_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 id = 0;
    S32 ret = 0;
    U8 *guiBuffer = NULL;
    U16 lsk_string = 0;
    U16 lsk_image = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_BMK);
    
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_BOOKMARK, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_BOOKMARK, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_PLST_BOOKMARK, 
        SCR_ID_MEDPLY_PLST_BOOKMARK, 
        NULL, 
        mmi_medply_plstui_bmk_entry_scr, 
        MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    

    mmi_frm_scrn_set_leave_proc(
        GRP_ID_MEDPLY_PLST_BOOKMARK,
        SCR_ID_MEDPLY_PLST_BOOKMARK, 
        mmi_medply_plstui_bmk_del_scr_callback);
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_BOOKMARK, SCR_ID_MEDPLY_PLST_BOOKMARK);

    if (!guiBuffer)
    {
    	id = list_p->plstid;
    	mmi_medply_plstui_reset_cache();
        ret = mmi_medply_plstui_bmk_prepare();
        if (ret < 0)
        {
			mmi_medply_plst_popup_simple(ret);
            mmi_frm_group_close(GRP_ID_MEDPLY_PLST_BOOKMARK);
            return;
        }
    }    
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_plstui_common_highlight_hdlr);

	lsk_string = STR_GLOBAL_OPTIONS;
    lsk_image = IMG_GLOBAL_OPTIONS;
    
    if (list_p->total == 0)
    {
        
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
        ShowCategory353Screen(
            (PU8)list_p->title,
            GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
            lsk_string,
            lsk_image,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
        
        SetCenterSoftkeyFunction(mmi_medply_plstui_bmk_opt_entry_scr, KEY_EVENT_UP);
    }
    else
    {    
        
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ShowCategory183Screen(
	        list_p->title, 
	        get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
	        get_string(lsk_string),
	        get_image(lsk_image),              
	        get_string(STR_GLOBAL_BACK),
	        get_image(IMG_GLOBAL_BACK), 
	        list_p->total,
	        mmi_medply_plstui_bmk_get_item,
	        NULL,
	        list_p->highlight,
	        MMI_FALSE,
	        NULL,
	        guiBuffer);
        
        SetCenterSoftkeyFunction(mmi_medply_plstui_bmk_opt_preview, KEY_EVENT_UP);
	}

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_medply_plstui_bmk_opt_entry_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}




/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_entry_bookmark
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_plst_entry_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0; 
    mmi_medply_plstui_list_cache_struct *list_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_plstui_create_list_cache();
	if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        list_p = mmi_medply_plstui_get_curr_list_cache();
    	MMI_ASSERT(list_p != NULL); 
        list_p->plstid = MMI_MEDPLY_DB_LST_BOOKMARK_ID;
		mmi_medply_plstui_bmk_entry_scr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_history_insert_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url_p           [IN]
 *  name_p          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_history_insert_url(CHAR* url_p, CHAR* name_p, MMI_BOOL is_single)
{
    if (plst_cntx_p->list_module_ready)
    {
        if (mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_PLST_BOOKMARK, SCR_ID_MEDPLY_PLST_BOOKMARK) &&
            g_single.media_type == MEDPLY_TYPE_STREAM_RTSP)
        {
            mmi_medply_plstui_bmk_opt_new_part3(url_p, name_p);
        }
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_save_ram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_bmk_save_ram(void)
{
    mmi_medply_plstui_bmk_opt_save_ram_part1();
    return;
}

#define ___SEARCH
/*****************************************************************************
* FUNCTION
*  mmi_medply_search_clear_wildcard
* DESCRIPTION
*  clear wildcard charactor in buffer.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_search_clear_wildcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 len = 0;
    CHAR* text_p = NULL;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* clear wildcard in order to avoid the wildcard display in inline editor. */
    if (plst_cntx_p->search_cntx.s_title[0] != 0)
    {
    	mmi_ucs2cpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
            		 (const CHAR*)plst_cntx_p->search_cntx.s_title);
		text_p = (CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer;
		text_p += 2;
        len = mmi_ucs2strlen((const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
        mmi_ucs2ncpy((CHAR*)plst_cntx_p->search_cntx.s_title, 
                     (const CHAR*)text_p,
                     (U32)(len - 2));
    }

    if (plst_cntx_p->search_cntx.s_artist[0] != 0)
    {
    	mmi_ucs2cpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
            		 (const CHAR*)plst_cntx_p->search_cntx.s_artist);
        text_p = (CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer;
		text_p += 2;
        len = mmi_ucs2strlen((const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
        mmi_ucs2ncpy((CHAR*)plst_cntx_p->search_cntx.s_artist, 
                     (const CHAR*)text_p,
                     (U32)(len - 2));
    }

    if (plst_cntx_p->search_cntx.s_album[0] != 0)
    {
    	mmi_ucs2cpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
            		 (const CHAR*)plst_cntx_p->search_cntx.s_album);
        text_p = (CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer;
		text_p += 2;
        len = mmi_ucs2strlen((const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
        mmi_ucs2ncpy((CHAR*)plst_cntx_p->search_cntx.s_album, 
                     (const CHAR*)text_p,
                     (U32)(len - 2));
    }

    if (plst_cntx_p->search_cntx.s_genre[0] != 0)
    {
    	mmi_ucs2cpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
            		 (const CHAR*)plst_cntx_p->search_cntx.s_genre);
        text_p = (CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer;
		text_p += 2;
        len = mmi_ucs2strlen((const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
        mmi_ucs2ncpy((CHAR*)plst_cntx_p->search_cntx.s_genre, 
                     (const CHAR*)text_p,
                     (U32)(len - 2));
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_search_reset
* DESCRIPTION
*  reset search context
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_search_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 initiate_scr_id = 0;
	U16 initiate_grp_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    initiate_grp_id = plst_cntx_p->search_cntx.initiate_grp_id;
	initiate_scr_id = plst_cntx_p->search_cntx.initiate_scr_id;
    memset(&(plst_cntx_p->search_cntx), 0, sizeof(mmi_medply_db_search_struct));
    plst_cntx_p->search_cntx.initiate_grp_id = initiate_grp_id;
    plst_cntx_p->search_cntx.initiate_scr_id = initiate_scr_id;
    //mmi_frm_group_close(GRP_ID_MEDPLY_PLST_SEARCH);
    //mmi_medply_search_entry_scr();
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_search_exit
* DESCRIPTION
*  exit search function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_search_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_MEDPLY_PLST_SEARCH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_notify_scr
 * DESCRIPTION
 *  notify user no item found, ask whether need initiate a new search.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_notify_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer = NULL;
    MMI_BOOL play_tone = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_medply_plst_confirm(
        GRP_ID_MEDPLY_PLST_PLAYLIST,
        (WCHAR *)get_string(STR_ID_MEDPLY_PLST_NOTIFY_NOT_FOUND),
        MEDPLY_PLST_SEARCH_RESULT_CONFIRM,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_check_condition
 * DESCRIPTION
 *  check the condition user given before running search.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_search_check_condition(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (plst_cntx_p->search_cntx.s_title[0] == 0 &&
        plst_cntx_p->search_cntx.s_artist[0] == 0 &&
        plst_cntx_p->search_cntx.s_album[0] == 0 &&
        plst_cntx_p->search_cntx.s_genre[0] == 0)
    {
		return MMI_FALSE;
    }
    else
    {
    	//add wildcard for valid string.
        if (plst_cntx_p->search_cntx.s_title[0] != 0)
        {
        	mmi_ucs2cpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
                		 (const CHAR*)plst_cntx_p->search_cntx.s_title);
			kal_wsprintf(plst_cntx_p->search_cntx.s_title, "%c%w%c", '%', plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, '%');
        }

		if (plst_cntx_p->search_cntx.s_artist[0] != 0)
        {
        	mmi_ucs2cpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
                		 (const CHAR*)plst_cntx_p->search_cntx.s_artist);
			kal_wsprintf(plst_cntx_p->search_cntx.s_artist, "%c%w%c", '%', plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, '%');
        }

		if (plst_cntx_p->search_cntx.s_album[0] != 0)
        {
        	mmi_ucs2cpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
                		 (const CHAR*)plst_cntx_p->search_cntx.s_album);
			kal_wsprintf(plst_cntx_p->search_cntx.s_album, "%c%w%c", '%', plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, '%');
        }

        if (plst_cntx_p->search_cntx.s_genre[0] != 0)
        {
        	mmi_ucs2cpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
                		 (const CHAR*)plst_cntx_p->search_cntx.s_genre);
			kal_wsprintf(plst_cntx_p->search_cntx.s_genre, "%c%w%c", '%', plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, '%');
        }
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_result_opt_preview
 * DESCRIPTION
 *  initiate play with single player.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_result_opt_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_media_type_enum file_type = MEDPLY_TYPE_NONE;
    mmi_medply_media_format_enum file_format = MEDPLY_FORMAT_NONE;
    UI_character_type ext[MEDPLY_MAX_EXT_LEN];
    UI_character_type preview_path[MEDPLY_MAX_PATH_LEN];
    U32 preview_id = 0;
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    preview_id = list_p->id_table.data[list_p->highlight];
    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_PATH, &preview_id, preview_path);

    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        mmi_medply_util_extract_ext(preview_path, ext);
        file_format = mmi_medply_util_is_target_support_format(ext);
        file_type = media_file_info_table[file_format].file_type;

        if (file_type == MEDPLY_TYPE_AUDIO)
        {
            mmi_medply_single_play_audio(preview_path, NULL);
        }
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
        else if (file_type == MEDPLY_TYPE_VIDEO)
        {
            mmi_medply_single_play_video(preview_path, MMI_FALSE);
        }
#endif    
#ifdef __MMI_MEDIA_PLAYER_STREAM__
        else if (file_type == MEDPLY_TYPE_STREAM)
        {
            if (file_format == MEDPLY_FORMAT_RAM)
            {
                mmi_medply_single_play_stream_from_ram_file(preview_path, MMI_FALSE);
            }
            else if (file_format == MEDPLY_FORMAT_SDP)
            {
                mmi_medply_single_play_stream_from_sdp_file(preview_path, MMI_FALSE);
            }
        }
#endif
        else 
        {
            // TODO: handle other file types.
            return;
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_result_opt_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_result_opt_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    mmi_medply_plstui_reset_opt_data();
    // fill opt data
    list_p->add_ons.opt_data.curr_hilite_id = list_p->id_table.data[list_p->highlight];
    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_PATH, &(list_p->add_ons.opt_data.curr_hilite_id), list_p->add_ons.opt_data.curr_hilite_path);

    if (0 < srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR *)list_p->add_ons.opt_data.curr_hilite_path))
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND, MMI_TRUE);
    }
    
    if (0 < srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR *)list_p->add_ons.opt_data.curr_hilite_path))
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_USE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_USE, MMI_TRUE);
    }

#ifdef __MMI_RMGR__
    //@TODO:
    if(!DRM_rights_extendable((kal_wchar*)list_p->add_ons.opt_data.curr_hilite_path) ||
       !srv_nw_usab_is_any_network_available() ||
       srv_mode_switch_is_network_service_available())
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMGR_GEN_OPTION_MORE_RITS, MMI_TRUE);
        //list_p->add_ons.opt_data.is_show_rit  = MMI_FALSE;
    }
    else
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMGR_GEN_OPTION_MORE_RITS, MMI_FALSE);
        mmi_rmgr_set_ro_bound_path(list_p->add_ons.opt_data.curr_hilite_path);
        //list_p->add_ons.opt_data.is_show_rit  = MMI_TRUE;
    }
#endif

    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_SEND, MMI_TRUE);
    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_COMMON_OPT_USE, MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_result_opt_entry_scr
 * DESCRIPTION
 *  entry function of search result option screen
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_result_opt_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_PLST_OPT);
    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_PLAYLIST, GRP_ID_MEDPLY_PLST_SEARCH_RESULT_OPT, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_SEARCH_RESULT_OPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create( GRP_ID_MEDPLY_PLST_SEARCH_RESULT_OPT,
                        	CUI_MENU_SRC_TYPE_RESOURCE,
                        	CUI_MENU_TYPE_OPTION,
                        	MENU_ID_MEDPLY_PLST_SEARCH_OPT,
                        	MMI_TRUE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_entry_reslut_scr
 * DESCRIPTION
 *  entry function of search result screen.
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_entry_reslut_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    MMI_BOOL entry_ret;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_PLST_PLAYLIST, 
                                    SCR_ID_MEDPLY_PLST_SEARCH_RESULT, 
                                    NULL, 
                                    mmi_medply_search_entry_reslut_scr, 
                                    MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    

    list_p->list_grp_id = GRP_ID_MEDPLY_PLST_PLAYLIST;
    list_p->list_scr_id = SCR_ID_MEDPLY_PLST_SEARCH_RESULT;
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_SEARCH_RESULT, 
        						mmi_medply_plstui_playlist_del_scr_callback);
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_PLAYLIST, SCR_ID_MEDPLY_PLST_SEARCH_RESULT);
	if (NULL == guiBuffer)
		list_p->highlight = 0;
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_plstui_common_highlight_hdlr);
    
    MMI_ASSERT(list_p->total > 0);
 
    memset(&(list_p->hint_cache), 0, sizeof(mmi_medply_plstui_hint_cache_struct));
    list_p->hint_cache.hint_idx = -1;
    
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
	ShowCategory183Screen(
	    get_string(STR_ID_MEDPLY_PLST_SEARCH_RESULTS), 
	    get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
	    get_string(STR_GLOBAL_OPTIONS),
	    get_image(IMG_GLOBAL_OPTIONS),              
	    get_string(STR_GLOBAL_BACK),
	    get_image(IMG_GLOBAL_BACK), 
	    list_p->total,
	    mmi_medply_plstui_playlist_get_item,
	    mmi_medply_plstui_playlist_get_hint,
	    list_p->highlight,
	    MMI_FALSE,
	    NULL,
	    guiBuffer);
    
    /* register LSK, RSK hanlders */
	SetLeftSoftkeyFunction(mmi_medply_search_result_opt_entry_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_medply_search_result_opt_preview, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_action
 * DESCRIPTION
 *  do search action.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mmi_medply_search_check_condition())
    {
		mmi_medply_plst_popup_simple(MEDPLY_PLST_ERR_DB_NO_CONDITION);
    }
    else
    {
		ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART1, &(plst_cntx_p->search_cntx));

        if (ret < 0)
        {
            mmi_medply_search_clear_wildcard();
			mmi_medply_plst_popup_simple(ret);
        }
        else
        {
			if (plst_cntx_p->search_cntx.result_total == 0)
            {
                mmi_medply_search_clear_wildcard();
                mmi_medply_search_notify_scr();
            }
            else
            {
				ret = mmi_medply_plstui_create_list_cache();
				if (ret < 0)
			    {
					mmi_medply_plst_popup_simple(ret);
                    mmi_frm_group_close(GRP_ID_MEDPLY_PLST_SEARCH);
			        //DeleteUptoScrID(plst_cntx_p->search_cntx.initiate_scr_id);
			    }
			    else
			    {
			        list_p = mmi_medply_plstui_get_curr_list_cache();
			    	MMI_ASSERT(list_p != NULL); 
			        list_p->plstid = MMI_MEDPLY_DB_LST_SEARCH_RESULT_ID;
                    list_p->initiate_grp_id = plst_cntx_p->search_cntx.initiate_grp_id;
                    list_p->initiate_scr_id = plst_cntx_p->search_cntx.initiate_scr_id;
         			list_p->total = plst_cntx_p->search_cntx.result_total;

                    mmi_ucs2ncpy((CHAR*)list_p->title, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_SEARCH_RESULTS), MEDPLY_MAX_FILE_LEN - 1);

					/* reset hint cache. */
					list_p->hint_cache.hint_idx = -1;
    				list_p->hint_cache.hint_buff[0] = 0;
	
					MMI_ASSERT(list_p->id_table.data == NULL);
				    list_p->id_table.size = sizeof(U32) * list_p->total;
				    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

				    if (list_p->id_table.data == NULL)
				    {
				        ret = MEDPLY_PLST_ERR_NO_MEMORY;
			            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);
				    }
				    else
				    {
				    	MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
			            
						ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART2, 
											&(list_p->id_table), &(plst_cntx_p->search_cntx));
				        if (ret < 0)
				        {
				            kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
				            MEM_TRC_FREE(list_p->id_table.data, __LINE__);
				            list_p->id_table.data = NULL;
			                list_p->id_table.size = 0;
				        }
				    }

                    if (ret < 0)
        			{
						mmi_medply_plst_popup_simple(ret);
                        mmi_frm_group_close(GRP_ID_MEDPLY_PLST_SEARCH);
                        //GoBackToHistory(plst_cntx_p->search_cntx.initiate_scr_id);
            		}
                    else
                    {
			mmi_medply_search_entry_reslut_scr();
                        mmi_frm_group_close(GRP_ID_MEDPLY_PLST_SEARCH);
		                //DeleteScreenIfPresent(GRP_ID_MEDPLY_PLST_SEARCH);
                    }
			    }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_text_done_func
 * DESCRIPTION
 *  done function for edit text column.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_text_done_func(void)
{      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2ncmp((const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.original_string_p,
        			 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
        			 plst_cntx_p->ui_cntx.editor_cntx.limit))
	{
		switch (plst_cntx_p->search_cntx.edit_index)
	    {
			case MEDPLY_SEARCH_TITEL:
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->search_cntx.s_title,
                    		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                    		 plst_cntx_p->ui_cntx.editor_cntx.limit - 1);
                break;
	   		case MEDPLY_SEARCH_ARTIST:
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->search_cntx.s_artist,
                    		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                    		 plst_cntx_p->ui_cntx.editor_cntx.limit - 1);
                break;
	    	case MEDPLY_SEARCH_ALBUM:
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->search_cntx.s_album,
                     		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                     		 plst_cntx_p->ui_cntx.editor_cntx.limit - 1);
                break;
		    case MEDPLY_SEARCH_GENRE:
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->search_cntx.s_genre,
                    		 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer,
                    		 plst_cntx_p->ui_cntx.editor_cntx.limit - 1);
                break;
	        default:
	            break;
	    }
        /* copy new string back. */
        mmi_ucs2ncpy((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.original_string_p, 
        			 (const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, 
        			 plst_cntx_p->ui_cntx.editor_cntx.limit);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_edit_function
 * DESCRIPTION
 *  edit function for edit screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_edit_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 limit = 0;
    U16 editor_title_id = 0;
    U8  editor_type = 0;
    UI_string_type original_string_p = NULL;
    UI_string_type initial_value = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	switch (plst_cntx_p->search_cntx.edit_index)
	{
		case MEDPLY_SEARCH_TITEL:
	        limit = MMI_MEDPLY_MAX_TITLE_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_TITLE;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->search_cntx.s_title;
	        break;
		case MEDPLY_SEARCH_ARTIST:
	        limit = MMI_MEDPLY_MAX_ARTISRT_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_ARTIST;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->search_cntx.s_artist;
	        break;
		case MEDPLY_SEARCH_ALBUM:
	        limit = MMI_MEDPLY_MAX_ALBUM_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_ALBUM;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->search_cntx.s_album;
	        break;
	    case MEDPLY_SEARCH_GENRE:
	        limit = MMI_MEDPLY_MAX_GENRE_LEN - 1;
			editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_GENRE;
	        editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            original_string_p = plst_cntx_p->search_cntx.s_genre;
	        break;
	    default:
			MMI_ASSERT(0);
	}

	if (limit > MMI_MEDPLY_MAX_EDITOR_LEN)
	{
		limit = MMI_MEDPLY_MAX_EDITOR_LEN - 1;
	}

	if (editor_type > 0)
	{	
		initial_value = original_string_p;
	}

	if (limit > MMI_MEDPLY_MAX_EDITOR_LEN)
	{
		limit = MMI_MEDPLY_MAX_EDITOR_LEN - 1;
	}
    
    mmi_medply_editor_create(
                GRP_ID_MEDPLY_PLST_SEARCH,
    			editor_type,
    			limit,
    			editor_title_id,
    			original_string_p,
    			initial_value,
    			mmi_medply_search_text_done_func);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_set_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_set_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[MEDPLY_SEARCH_INLINE_ITEM_NUM];
    U16 item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/***********************************set string******************************************/
    /* title. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_TITLE_DISPLAY, 
        plst_cntx_p->search_cntx.s_title);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;
    
    /* artist. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_ARTIST_DISPLAY, 
        plst_cntx_p->search_cntx.s_artist);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* album. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_ALBUM_DISPLAY, 
        plst_cntx_p->search_cntx.s_album);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* genre */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_GENRE_DISPLAY, 
        plst_cntx_p->search_cntx.s_genre);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /***********************************set icon******************************************/
    cui_inline_set_icon_list(inline_id, &item_icons[0]);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_search_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_search_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_PLAYLIST, GRP_ID_MEDPLY_PLST_SEARCH, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_SEARCH, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = cui_inline_create(GRP_ID_MEDPLY_PLST_SEARCH, &mmi_medply_plstui_inline_search_screen);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_inline_set_title_icon(cui_gid, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
        mmi_medply_search_set_value(cui_gid);
        cui_inline_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }

}


#define ___LISTMGR
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_load(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 
    
    list_p->add_ons.opt_data.curr_hilite_id = list_p->id_table.data[list_p->highlight];
	mmi_medply_plstui_playlist_entry(list_p->add_ons.opt_data.curr_hilite_id);
    mmi_frm_group_close(GRP_ID_MEDPLY_PLST_LISTMGR_OPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_create_part_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_create_part_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ptr = NULL;
    S32 len = 0;
    S32 ret = 0;
	U32 plst_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    ptr = (CHAR*)srv_fmgr_path_skip_leading_space((WCHAR*)((CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer));

    if (ptr != (CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer)
    {
    	mmi_medply_plst_popup_simple_with_string(
            get_string(STR_GLOBAL_INVALID_FILENAME),
            MMI_EVENT_ERROR);
        return;
    }
    
    len = mmi_ucs2strlen(ptr);

    if (len == 0)
    {
    	mmi_medply_plst_popup_simple_with_string(
            get_string(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME),
            MMI_EVENT_ERROR);
	    return;
    }
    if (ptr[0] == '.' ||
        !srv_fmgr_path_is_filename_valid((const WCHAR*)(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer)))
    {
    	mmi_medply_plst_popup_simple_with_string(
            get_string(STR_GLOBAL_INVALID_FILENAME),
            MMI_EVENT_ERROR);
	    return;
    }
    /* check exist. */
    ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_TITLE, plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
    if (MEDPLY_PLST_GOT_DATA == ret)
    {
        mmi_medply_plst_popup_simple(MEDPLY_PLST_ERR_FILE_EXISTS);
    }
    else
    {
    	ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_MAX_LIST_ID, &plst_id);
        plst_id++;
    	ret = DB_ACTION2(MEDPLY_DB_ACT_MODIFY_PLST_CREATE, &plst_id, plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);

        if (ret != 0)
        {
			mmi_medply_plst_popup_simple(ret);
        }
        else
        {
            mmi_medply_plst_popup_simple_with_string(
                get_string(STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS);
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_ADDTO, SCR_ID_MEDPLY_PLST_ADDTO);
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_LISTMGR, SCR_ID_MEDPLY_PLST_LISTMGR);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_create_part_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_create_part_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_PLST_PLAYLIST))
    {
        grp_id = GRP_ID_MEDPLY_PLST_PLAYLIST;
    }
    else
    {
        grp_id = GRP_ID_MEDPLY_PLST_LISTMGR;
    }
    mmi_medply_editor_create(
                        grp_id,
     					MMI_MEDPLY_EDITOR_NEW,
    					MEDPLY_MAX_INPUT_FILE_LEN,
    					STR_ID_MEDPLY_LISTMGR_OPT_NEW,
    					NULL,
    					NULL,
    					mmi_medply_plstui_listmgr_opt_create_part_2);
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_rename_part_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_rename_part_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ptr = NULL;
    S32 len = 0;
    S32 ret = 0;
    U8 i = 0;
	UI_character_type old_name[MEDPLY_MAX_FILE_LEN];
    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    ptr = (CHAR*)srv_fmgr_path_skip_leading_space((WCHAR*)(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer));
    if (ptr != (CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer)
    {
    	mmi_medply_plst_popup_simple_with_string(
            get_string(STR_GLOBAL_INVALID_FILENAME),
            MMI_EVENT_ERROR);
        return;
    }
    len = mmi_ucs2strlen(ptr);

    if (len == 0)
    {
    	mmi_medply_plst_popup_simple_with_string(
            get_string(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME),
            MMI_EVENT_ERROR);
        return;
    }
    if (ptr[0] == '.' ||
        !srv_fmgr_path_is_filename_valid((const WCHAR*)(plst_cntx_p->ui_cntx.editor_cntx.editor_buffer)))
    {
    	mmi_medply_plst_popup_simple_with_string(
            get_string(STR_GLOBAL_INVALID_FILENAME),
            MMI_EVENT_ERROR);
        return;
    }

	/* check same name */
    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == list_p->add_ons.opt_data.curr_hilite_id &&
            list_p->db_cache[i].title[0] != 0)
        {
			mmi_ucs2ncpy((CHAR*)old_name, (const CHAR*)list_p->db_cache[i].title, MEDPLY_MAX_FILE_LEN -1);
			break;
        }
    }

	if (!mmi_ucs2ncmp((const CHAR*)plst_cntx_p->ui_cntx.editor_cntx.editor_buffer, (const CHAR*)old_name, MEDPLY_MAX_FILE_LEN - 1))
	{
        //GoBackToHistory(SCR_ID_MEDPLY_PLST_LISTMGR);
		return;
	}
    /* cehck exist */
	ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_TITLE, plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
    if (MEDPLY_PLST_GOT_DATA == ret)
    {
    	mmi_medply_plst_popup_simple(MEDPLY_PLST_ERR_FILE_EXISTS);
    }
    else
    {
		ret = DB_ACTION2(MEDPLY_DB_ACT_MODIFY_PLST_RENAME, &(list_p->add_ons.opt_data.curr_hilite_id), plst_cntx_p->ui_cntx.editor_cntx.editor_buffer);
        
        if (ret != 0)
        {
            mmi_medply_plst_popup_simple(ret);
        }
        else
        {
            mmi_medply_plst_popup_simple_with_string(
                get_string(STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS);
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_LISTMGR,SCR_ID_MEDPLY_PLST_LISTMGR);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_rename_part_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_rename_part_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    UI_character_type list_name[MEDPLY_MAX_FILE_LEN];
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 

    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TITLE, &(list_p->add_ons.opt_data.curr_hilite_id), list_name);

	if (ret >= 0)
   	{
        mmi_medply_editor_create(
                        GRP_ID_MEDPLY_PLST_LISTMGR,
    					MMI_MEDPLY_EDITOR_RENAME,
    					MEDPLY_MAX_INPUT_FILE_LEN,
    					STR_GLOBAL_RENAME,
    					NULL,
    					list_name,
    					mmi_medply_plstui_listmgr_opt_rename_part_2);
    }
    else
    {
		/* something wrong in get highlight playlist title. */
        mmi_medply_plst_popup_simple(ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_playlist_opt_clear_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_delete_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);  
    
    StopTimer(MEDPLY_STATE_MACHINE_TIMER);
    StopTimer(MEDPLY_GENERATE_TIMER);
    DB_ENABLE;
    DB_ROLLBACK_TRANSACTION;
    DB_DISABLE;
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }
    mmi_frm_group_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN);
    //GoBackToHistory(SCR_ID_MEDPLY_PLST_LISTMGR);
    clear_list.rowid_begin = clear_list.rowid_end = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_delete_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_delete_internal(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    U32 limit = 10;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (mmi_frm_scrn_get_active_id() != SCR_ID_MEDPLY_PLST_WAIT_SCREEN)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_IN_SLEEP);
        /* Sleep if the waitting screen has been in history. */
        StartTimer(MEDPLY_GENERATE_TIMER, 500, mmi_medply_plstui_listmgr_opt_delete_internal);
        return;
    }

    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    ret = DB_ACTION3(MEDPLY_DB_ACT_QUERY_PLST_MAX_ROWID, &clear_list.rowid_begin, &limit, &clear_list.rowid_end);
    if (ret >= 0)
    {
        if (clear_list.rowid_end > clear_list.rowid_begin)
        {
            ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_PLST_CLEAR_SUB, 
                         &list_p->plstid, 
                         &clear_list.rowid_begin, 
                         &clear_list.rowid_end);
            if (ret >= 0)
            {
                clear_list.rowid_begin = clear_list.rowid_end;
                StartTimer(MEDPLY_STATE_MACHINE_TIMER, 50, mmi_medply_plstui_listmgr_opt_delete_internal);
                return;
            }
        }
    }

    if (ret < 0)
    {
        DB_ENABLE;
        DB_ROLLBACK_TRANSACTION;
        DB_DISABLE;
        if (mdi_audio_is_background_play_suspended())
        {
            mdi_audio_resume_background_play();
        }
        mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        DB_ENABLE;
        DB_COMMIT_TRANSACTION;
        DB_DISABLE;
       
        ret = DB_ACTION1(MEDPLY_DB_ACT_MODIFY_PLST_DELETE, &(list_p->add_ons.opt_data.curr_hilite_id));
        if (ret < 0)
        {
            mmi_medply_plst_popup_simple(ret);
        }
        else
        {
            mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS);
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_PLST_LISTMGR, SCR_ID_MEDPLY_PLST_LISTMGR);
        }

        if (mdi_audio_is_background_play_suspended())
        {
            mdi_audio_resume_background_play();
        }
    }
    clear_list.rowid_begin = clear_list.rowid_end = 0;   
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_delete_wait_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_delete_wait_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_LISTMGR, GRP_ID_MEDPLY_PLST_WAIT_SCREEN, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_PLST_WAIT_SCREEN, 
        SCR_ID_MEDPLY_PLST_WAIT_SCREEN, 
        NULL, 
        mmi_medply_plstui_listmgr_opt_delete_wait_screen_entry, 
        MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }    

//#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
//    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
//#endif
    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(mmi_medply_plstui_listmgr_opt_delete_cancel, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_delete_part_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_delete_part_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    
    clear_list.rowid_begin = 0;
    clear_list.rowid_end = 0;
    
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }    
    
    DB_ENABLE;
    DB_BEGIN_TRANSACTION;
    DB_DISABLE;
    mmi_medply_plstui_listmgr_opt_delete_wait_screen_entry();
    StartTimer(MEDPLY_STATE_MACHINE_TIMER, 50, mmi_medply_plstui_listmgr_opt_delete_internal); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_delete_part_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_delete_part_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type str[MEDPLY_MAX_FILE_LEN + 25];
    UI_character_type title[MEDPLY_MAX_FILE_LEN];
    S32 ret = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);	
    
	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TITLE, &(list_p->add_ons.opt_data.curr_hilite_id), title);
    memset(str, 0, sizeof(str));

	kal_wsprintf(str, "%w%w\n%w", 
		             get_string(STR_GLOBAL_DELETE), 
		             get_string(STR_ID_FMGR_QUESTION_MARK),
		             title);
   
	MMI_ASSERT(mmi_ucs2strlen((const CHAR*)str) < MEDPLY_MAX_FILE_LEN + 25);

    mmi_medply_plst_confirm_simple(GRP_ID_MEDPLY_PLST_LISTMGR,
        (WCHAR *)str,
        mmi_medply_plstui_listmgr_opt_delete_part_2,
        CNFM_TYPE_YESNO,
        MMI_TRUE,
        MMI_EVENT_QUERY);     
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plstui_list_cache_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);	

    mmi_medply_plstui_reset_opt_data();
    
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LISTMGR_OPT_DELETE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LISTMGR_OPT_RENAME, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LISTMGR_OPT_LOAD, MMI_TRUE);

    if (list_p->total)
    {
    	/* fill opt data. */
        list_p->add_ons.opt_data.curr_hilite_id = list_p->id_table.data[list_p->highlight];

        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LISTMGR_OPT_LOAD, MMI_FALSE);

        /* highlight playlist is not default list, can rename and delete. */
        if (list_p->add_ons.opt_data.curr_hilite_id > MMI_MEDPLY_DB_LST_ON_THE_FLY_ID ||
            list_p->add_ons.opt_data.curr_hilite_id < MMI_MEDPLY_DB_LST_DUMMEY_ID)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LISTMGR_OPT_RENAME, MMI_FALSE);
            
            if (list_p->add_ons.opt_data.curr_hilite_id != plst_cntx_p->list_cntx.playing.plst_id)
            {
            	/* not allow delete the now playing list. */
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LISTMGR_OPT_DELETE, MMI_FALSE);
            }
        }

        if (plst_cntx_p->list_cntx.playing.plst_id == list_p->add_ons.opt_data.curr_hilite_id)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_LISTMGR_OPT_DELETE, MMI_TRUE);
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_opt_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_listmgr_opt_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_LISTMGR_OPT);
    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_LISTMGR, GRP_ID_MEDPLY_PLST_LISTMGR_OPT, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_LISTMGR_OPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create( GRP_ID_MEDPLY_PLST_LISTMGR_OPT,
                        	CUI_MENU_SRC_TYPE_RESOURCE,
                        	CUI_MENU_TYPE_OPTION,
                        	MENU_ID_MEDPLY_PLST_LISTMGR_OPT,
                        	MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }

}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_listmgr_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_medply_plstui_listmgr_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	U32 current_id = 0;
    S32 ret = 0;

	U8 i = 0;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    mmi_medply_plstui_db_cache_item_struct item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
	current_id = list_p->id_table.data[item_idx];
	/* check the request item whether in cache. */
    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == current_id &&
            list_p->db_cache[i].title[0] != 0)
        {
			mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)list_p->db_cache[i].title, MEDPLY_MAX_FILE_LEN -1);
			*img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_ICON);
            return MMI_TRUE;
        }
    }
	/* out of cache. */
    item.media_id = current_id;
    if (current_id <= MMI_MEDPLY_DB_LST_ON_THE_FLY_ID)
    {
		U16 title_id = 0;
		switch (item.media_id)
	    {
			case MMI_MEDPLY_DB_LST_ALL_MEDIA_ID:
				title_id = STR_ID_MEDPLY_ALL_MEDIA;
	            break;
	        case MMI_MEDPLY_DB_LST_RECENT_ID:
	            title_id = STR_ID_MEDPLY_PLST_RECENTLY;
	            break;
	        case MMI_MEDPLY_DB_LST_BOOKMARK_ID:
	            title_id = STR_ID_MEDPLY_BOOKMARK;
	            break;
	        case MMI_MEDPLY_DB_LST_FAVOURITE_ID:
	            title_id = STR_ID_MEDPLY_PLST_MY_FAVOURITE;
	            break;
	        case MMI_MEDPLY_DB_LST_MOST_PLAYED_ID:
	            title_id = STR_ID_MEDPLY_PLST_MOST;
	            break;
	        case MMI_MEDPLY_DB_LST_ON_THE_FLY_ID:
	            title_id = STR_ID_MEDPLY_PLST_ON_THE_FLY;
	            break;
	    }
		mmi_ucs2ncpy((CHAR*)item.title, (const CHAR*)GetString(title_id), MEDPLY_MAX_FILE_LEN - 1);
    }
    else
    {
    	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TITLE, 
            			&(item.media_id), item.title);
	    if (ret < 0)
	    {
		    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_LOAD_CACHE_FAIL, ret, __LINE__);
        	mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)GetString(STR_GLOBAL_LOADING), MEDPLY_MAX_FILE_LEN -1);
		    *img_buff_p = NULL;
		    return MMI_TRUE;
	    }
    }
	
	/* update cache. */
	for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == 0 &&
            list_p->db_cache[i].title[0] == 0)
        {
			/* get an empty cache item. */
            break;
        }
    }

	if (i < MMI_MEDPLY_LIST_BUFF_SIZE)
    {
		/* cache is not full. just need update tail. */
        memcpy(&(list_p->db_cache[i]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
		list_p->tail = i;
    }
    else
    {
		/* cache is full, need replace the oldest one. */
 		memcpy(&(list_p->db_cache[list_p->head]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
       	if (list_p->head == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
	    {
			list_p->head = 0;
	    }
	    else
	    {
	    	list_p->head++;
	    }
		if (list_p->tail == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
		{
			list_p->tail = 0;
		}
		else
		{
			list_p->tail++;
		}
    }

    
    mmi_ucs2ncpy((CHAR*)str_buff, 
        (const CHAR*)item.title,
        MAX_SUBMENU_CHARACTERS);

    *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_ICON);

    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_listmgr_prepare
* DESCRIPTION
*  prepare cache data for listmgr screen.
* PARAMETERS
*  void
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_plstui_listmgr_prepare(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	U32 total_plst = 0;
    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
    
    /* get title. */
	mmi_ucs2ncpy((CHAR*)list_p->title, (const CHAR*)GetString(STR_ID_MEDPLY_MY_PLAYLIST), MEDPLY_MAX_FILE_LEN - 1);

	/* get total. */
	ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_TOTAL_OF_LIST, &total_plst);
	if (ret < 0)
	{
	    return ret;
	}
	else
	{
	    list_p->total = total_plst;
	    list_p->total -= 4;	/* dummy, bookmark and all media files should not display in this list. */

		if (list_p->id_table.data != NULL)
        {
		 	kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
		 	MEM_TRC_FREE(list_p->id_table, __LINE__);
		 	list_p->id_table.data = NULL;
		    list_p->id_table.size = 0;
        }
        
        /* fill id table */
	    list_p->id_table.pattern = 0xFEFEFEFE;
	    list_p->id_table.size = sizeof(U32) * list_p->total;
	    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

	 	if (list_p->id_table.data == NULL)
	 	{
	 	    ret = MEDPLY_PLST_ERR_NO_MEMORY;
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);
	 	}
	 	else
	 	{
	 		MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
	 	    ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_LISTMGR_TBL_EXT, &(list_p->id_table));
	 
	 	    if (ret < 0)
	 	    {
	 	        kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	 	        MEM_TRC_FREE(list_p->id_table, __LINE__);
	 	        list_p->id_table.data = NULL;
	            list_p->id_table.size = 0;
	 	    }
	 	}
	}
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_listmgr_del_scr_callback
* DESCRIPTION
*  
* PARAMETERS
*  in_param		[IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_medply_plstui_listmgr_del_scr_callback(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_medply_plstui_list_cache_struct *list_p = NULL;

            list_p = mmi_medply_plstui_get_curr_list_cache();
            MMI_ASSERT(list_p != NULL); 
            
            if (list_p->id_table.data != NULL)
            {
                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
                list_p->id_table.data = NULL;
            }
            
            
            mmi_medply_plstui_destory_list_cache();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_listmgr_entry_scr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_listmgr_entry_scr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U8 *guiBuffer = NULL;
    MMI_BOOL entry_ret;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_LISTMGR);
    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL); 

    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_LISTMGR, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_LISTMGR, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_PLST_LISTMGR, SCR_ID_MEDPLY_PLST_LISTMGR, NULL, mmi_medply_plstui_listmgr_entry_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_PLST_LISTMGR, SCR_ID_MEDPLY_PLST_LISTMGR, mmi_medply_plstui_listmgr_del_scr_callback);

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_LISTMGR, SCR_ID_MEDPLY_PLST_LISTMGR);

    if (!guiBuffer)
    {	
    	mmi_medply_plstui_reset_cache();
        ret = mmi_medply_plstui_listmgr_prepare();
        list_p->list_scr_id = SCR_ID_MEDPLY_PLST_LISTMGR;

        if (ret < 0)
        {
			mmi_medply_plst_popup_simple(ret);
            mmi_frm_group_close(GRP_ID_MEDPLY_PLST_LISTMGR);
            return;
        }
    }
    
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_plstui_common_highlight_hdlr);


    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
	ShowCategory183Screen(
	    list_p->title, 
	    get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
	    get_string(STR_GLOBAL_OPTIONS),
	    get_image(IMG_GLOBAL_OPTIONS),             
	    get_string(STR_GLOBAL_BACK),
	    get_image(IMG_GLOBAL_BACK), 
	    list_p->total,
	    mmi_medply_plstui_listmgr_get_item,
	    NULL,
	    list_p->highlight,
	    MMI_FALSE,
	    NULL,
	    guiBuffer);
    
#ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_medply_plstui_listmgr_tap_callback);
#endif
        /* register LSK, RSK hanlders */
        SetLeftSoftkeyFunction(mmi_medply_plstui_listmgr_opt_entry_scr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_medply_plstui_listmgr_opt_load, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_listmgr_entry
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_medply_plstui_listmgr_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_plstui_create_list_cache();
	if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
		mmi_medply_plstui_listmgr_entry_scr();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_listmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_entry_listmgr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	mmi_medply_plstui_listmgr_entry();
}

#define __ADD_TO
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_add_to_scr_lsk
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_addto_scr_lsk(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 plst_id = 0;
    U32 media_id = 0;

    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    if (list_p->highlight > 0)
    {
        media_id = plst_cntx_p->ui_cntx.list_stack[mmi_medply_plstui_get_curr_list_cache_index() - 1]->add_ons.opt_data.curr_hilite_id;
        plst_id = list_p->id_table.data[list_p->highlight];

        ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_ITEM_EXIST, &media_id, &plst_id);
        if (MEDPLY_PLST_GOT_DATA == ret)
        {
            /* exist */
            mmi_medply_plst_popup_simple(MEDPLY_PLST_ERR_ITEM_EXISTS);
        }
        else
        {
            U32 total = 0;
            ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TOTAL, &plst_id, &total);
            ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_ITEM_ADD, &media_id, &plst_id, &total);
            if (ret != 0)
            {
                mmi_medply_plst_popup_simple(ret);
            }
            else
            {
                mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
            }
        }
        mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_ADDTO, SCR_ID_MEDPLY_PLST_ADDTO);
    }
    else
    {
        mmi_medply_plstui_listmgr_opt_create_part_1();
    }
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_addto_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_medply_plstui_addto_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	U32 current_id = 0;
    S32 ret = 0;

	U8 i = 0;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    mmi_medply_plstui_db_cache_item_struct item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);
	current_id = list_p->id_table.data[item_idx];
	/* check the request item whether in cache. */
    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == current_id &&
            list_p->db_cache[i].title[0] != 0)
        {
			if (item_idx == 0)
            {
                mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)GetString(STR_ID_MEDPLY_LISTMGR_OPT_NEW), MEDPLY_MAX_FILE_LEN - 1);
    			*img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_CREATE_ICON);
            }
            else
            {
            	mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)list_p->db_cache[i].title, MEDPLY_MAX_FILE_LEN -1);
            	*img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_ICON);
            }
            return MMI_TRUE;
        }
    }
	/* out of cache. */
    if (item_idx == 0)
    {
        item.media_id = 0;
        mmi_ucs2ncpy((CHAR*)item.title, (const CHAR*)GetString(STR_ID_MEDPLY_LISTMGR_OPT_NEW), MEDPLY_MAX_FILE_LEN - 1);
    }
    else
    {
    	item.media_id = current_id;
	    if (current_id <= MMI_MEDPLY_DB_LST_ON_THE_FLY_ID)
	    {
			U16 title_id = 0;
			switch (item.media_id)
		    {
				case MMI_MEDPLY_DB_LST_ALL_MEDIA_ID:
					title_id = STR_ID_MEDPLY_ALL_MEDIA;
		            break;
		        case MMI_MEDPLY_DB_LST_RECENT_ID:
		            title_id = STR_ID_MEDPLY_PLST_RECENTLY;
		            break;
		        case MMI_MEDPLY_DB_LST_BOOKMARK_ID:
		            title_id = STR_ID_MEDPLY_BOOKMARK;
		            break;
		        case MMI_MEDPLY_DB_LST_FAVOURITE_ID:
		            title_id = STR_ID_MEDPLY_PLST_MY_FAVOURITE;
		            break;
		        case MMI_MEDPLY_DB_LST_MOST_PLAYED_ID:
		            title_id = STR_ID_MEDPLY_PLST_MOST;
		            break;
		        case MMI_MEDPLY_DB_LST_ON_THE_FLY_ID:
		            title_id = STR_ID_MEDPLY_PLST_ON_THE_FLY;
		            break;
		    }
			mmi_ucs2ncpy((CHAR*)item.title, (const CHAR*)GetString(title_id), MEDPLY_MAX_FILE_LEN - 1);
	    }
	    else
	    {
	    	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TITLE, 
	            			&(item.media_id), item.title);
		    if (ret < 0)
		    {
			    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_LOAD_CACHE_FAIL, ret, __LINE__);
        		mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)GetString(STR_GLOBAL_LOADING), MEDPLY_MAX_FILE_LEN -1);
			    *img_buff_p = NULL;
			    return MMI_TRUE;
		    }
	    }
	}
	/* update cache. */
	for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
		if (list_p->db_cache[i].media_id == 0 &&
            list_p->db_cache[i].title[0] == 0)
        {
			/* get an empty cache item. */
            break;
        }
    }

	if (i < MMI_MEDPLY_LIST_BUFF_SIZE)
    {
		/* cache is not full. just need update tail. */
        memcpy(&(list_p->db_cache[i]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
		list_p->tail = i;
    }
    else
    {
		/* cache is full, need replace the oldest one. */
 		memcpy(&(list_p->db_cache[list_p->head]), &item, sizeof(mmi_medply_plstui_db_cache_item_struct));
       	if (list_p->head == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
	    {
			list_p->head = 0;
	    }
	    else
	    {
	    	list_p->head++;
	    }
		if (list_p->tail == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
		{
			list_p->tail = 0;
		}
		else
		{
			list_p->tail++;
		}
    }

    mmi_ucs2ncpy((CHAR*)str_buff, 
        (const CHAR*)item.title,
        MAX_SUBMENU_CHARACTERS);

    if (item_idx == 0)
    {
    	*img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_CREATE_ICON);
    }
    else
    {
    	*img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_ICON);
	}
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_addto_prepare
* DESCRIPTION
*  prepare cache data for listmgr screen.
* PARAMETERS
*  void
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_plstui_addto_prepare(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
	U32 total_plst = 0;
    
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);    

    list_p->list_scr_id = SCR_ID_MEDPLY_PLST_ADDTO;
    /* get title. */
	mmi_ucs2ncpy((CHAR*)list_p->title, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_ADD_TO), MEDPLY_MAX_FILE_LEN - 1);

	/* get total. */
	ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_TOTAL_OF_LIST, &total_plst);
	if (ret < 0)
	{
	    return ret;
	}
	else
	{
	    list_p->total = total_plst;
	    /*
	    **  only display one default playlist in this case.
	    */
	    list_p->total -= 7;
	    list_p->total++;	/* first create item. */
        
        /* fill id table */
	    list_p->id_table.pattern = 0xFEFEFEFE;
	    list_p->id_table.size = sizeof(U32) * list_p->total;
	    list_p->id_table.data = kal_adm_alloc(g_medply.adm_id_p, list_p->id_table.size);

	 	if (list_p->id_table.data == NULL)
	 	{
	 	    ret = MEDPLY_PLST_ERR_NO_MEMORY;
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_NO_MEMORY, __LINE__);
	 	}
	 	else
	 	{
	 		MEM_TRC_ALLOCATE(list_p->id_table.data, list_p->id_table.size, __LINE__);
	 		ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_LISTMGR_TBL, 
                        					   &(list_p->id_table));
	 	    if (ret < 0)
	 	    {
	 	        kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
	 	        MEM_TRC_FREE(list_p->id_table, __LINE__);
	 	        list_p->id_table.data = NULL;
	            list_p->id_table.size = 0;
	 	    }
	 	}
	}

    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_addto_del_scr_callback
* DESCRIPTION
*  
* PARAMETERS
*  in_param		[IN]
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_medply_plstui_addto_del_scr_callback(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_medply_plstui_list_cache_struct *list_p = NULL;

            list_p = mmi_medply_plstui_get_curr_list_cache();
            MMI_ASSERT(list_p != NULL); 
            
            if (list_p->id_table.data != NULL)
            {
                kal_adm_free(g_medply.adm_id_p, list_p->id_table.data);
                MEM_TRC_FREE(list_p->id_table.data, __LINE__);
                list_p->id_table.data = NULL;
            }
            
            
            mmi_medply_plstui_destory_list_cache();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_addto_exit_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_addto_exit_scr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	MMI_fixed_list_menu.flags |= UI_LIST_MENU_LOOP;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_addto_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_addto_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U8 *guiBuffer = NULL;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLSTUI_ENTRY_ADDTO);
    
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);     

    mmi_frm_group_create(GRP_ID_MEDPLY_PLST_PLAYLIST, GRP_ID_MEDPLY_PLST_ADDTO, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_ADDTO, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_PLST_ADDTO, 
                                    SCR_ID_MEDPLY_PLST_ADDTO, 
                                    mmi_medply_plstui_addto_exit_scr, 
                                    mmi_medply_plstui_addto_entry_scr, 
                                    MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_PLST_ADDTO, SCR_ID_MEDPLY_PLST_ADDTO, 
        						mmi_medply_plstui_addto_del_scr_callback);

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_PLST_ADDTO, SCR_ID_MEDPLY_PLST_ADDTO);

    if (!guiBuffer)
    {
        ret = mmi_medply_plstui_addto_prepare();
        
        if (ret < 0)
        {
			mmi_medply_plst_popup_simple(ret);
            mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_ADDTO, SCR_ID_MEDPLY_PLST_ADDTO);
            return;
        }
    }
	
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_plstui_common_highlight_hdlr);

    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

	ShowCategory183Screen(
	    list_p->title, 
	    get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
	    get_string(STR_GLOBAL_SELECT),
	    NULL,              
	    get_string(STR_GLOBAL_BACK),
	    get_image(IMG_GLOBAL_BACK), 
	    list_p->total,
	    mmi_medply_plstui_addto_get_item,
	    NULL,
	    list_p->highlight,
	    MMI_FALSE,
	    NULL,
	    guiBuffer);


    MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_LOOP;

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_medply_plstui_addto_scr_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_medply_plstui_addto_scr_lsk, KEY_EVENT_UP);

}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_addto_entry
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_addto_entry(U16 initiate_scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0; 
    mmi_medply_plstui_list_cache_struct *list_p = NULL;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_medply_plstui_create_list_cache();
	if (ret < 0)
    {
		mmi_medply_plst_popup_simple(ret);
    }
    else
    {
        list_p = mmi_medply_plstui_get_curr_list_cache();
    	MMI_ASSERT(list_p != NULL); 
        list_p->initiate_scr_id = initiate_scr_id;
		mmi_medply_plstui_addto_entry_scr();
    }
}


#define ___RECENT_PLAYED
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_add_to_recent_played
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_add_to_recent_played(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if (plst_cntx_p->db_cntx.db_opend && plst_cntx_p->db_cntx.instance_initialized)
    {
		ret = DB_ACTION1(MEDPLY_DB_ACT_MODIFY_ADD_TO_RECENT, &(plst_cntx_p->list_cntx.playing.id));
    }
    return ret;	
}


#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_single_apply_picked_file_internal
 * DESCRIPTION
 *  pick file path as pick index of intro play. 
 * PARAMETERS
 *  out_string       [OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_single_apply_picked_file_internal(UI_string_type out_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 picked_id =0;
	UI_character_type picked_path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    list_p = mmi_medply_plstui_get_curr_list_cache();
    MMI_ASSERT(list_p != NULL);

    /* get id from list id table. */
    MMI_ASSERT(list_p->id_table.data != NULL);
    picked_id = list_p->id_table.data[plst_cntx_p->list_cntx.intro.pick_idx];
    /* query path from database. */
    ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_PATH, &picked_id, picked_path);

    if (ret < 0)
    {
		*out_string = 0;
    }
    else
    {
		mmi_ucs2ncpy((CHAR*)out_string, (const CHAR*)picked_path, MEDPLY_MAX_PATH_LEN - 1);
    }

    return ret;
}
#endif	/* __MMI_MEDIA_PLAYER_INTRO_PLAY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_apply_picked_file_internal
 * DESCRIPTION
 *  pick file path as picked index.
 * PARAMETERS
 *  out_string       [OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_apply_picked_file_internal(UI_string_type out_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 picked_id = 0;
    S32 ret = 0;
	UI_character_type picked_path[MEDPLY_MAX_PATH_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!plst_cntx_p->list_cntx.playing.loaded)
    {
        *out_string = 0;
        return MEDPLY_PLST_ERR_NO_FILE_LOADED;
    }
    
    if (plst_cntx_p->list_cntx.playing.pick_index >= 0 &&
        plst_cntx_p->list_cntx.playing.pick_index < plst_cntx_p->list_cntx.playing.total)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_PRE_PICK, plst_cntx_p->list_cntx.playing.plst_id, plst_cntx_p->list_cntx.playing.pick_index);
        ret = DB_ACTION3(MEDPLY_DB_ACT_QUERY_ITEM_ID_EXT, &(plst_cntx_p->list_cntx.playing.pick_index), &(plst_cntx_p->list_cntx.playing.plst_id), &picked_id);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_POST_PICK, picked_id, ret);

        if (ret >= 0)
        {
            plst_cntx_p->list_cntx.playing.id = picked_id;
            /* query path from database. */
            ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_PATH, &picked_id, picked_path);

            if (ret < 0)
            {
                *out_string = 0;
            }
            else
            {
                mmi_ucs2ncpy((CHAR*)out_string, (const CHAR*)picked_path, MEDPLY_MAX_PATH_LEN - 1);
            }
        }
        else
        {
            *out_string = 0;
        }
        return ret;
    }
    else
    {
        // out of range
        *out_string = 0;
        return MEDPLY_PLST_ERR_OUT_OF_RANGE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_basic_data
 * DESCRIPTION
 *  get basic info.
 * PARAMETERS
 *  out_data       [OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_get_basic_data(mmi_medply_plstui_db_cache_item_struct *out_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_BASIC_INFO, &plst_cntx_p->list_cntx.playing.id, out_data);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_current_details_internal
 * DESCRIPTION
 *  get meta for display in main screen.
 * PARAMETERS
 *  details_data     [OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_get_current_details_internal(mmi_medply_details_for_display_struct* details_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_MEDIA_DISPLAY_INFO, &(plst_cntx_p->list_cntx.playing.id), details_data);

    return ret;
}


#define ____ADD_TO_ON_THE_FLY
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_add_to_on_the_fly_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_add_to_on_the_fly_list(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 id = MMI_MEDPLY_DB_LST_ON_THE_FLY_ID;
	U32 total = 0;
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_is_play_activated())
    {
        do 
        {
            ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_PLST_TOTAL, &id, &total);
            if (ret < 0)
            {
                break;
            }
            ret = DB_ACTION2(MEDPLY_DB_ACT_QUERY_ITEM_EXIST, &(plst_cntx_p->list_cntx.playing.id), &id);
            if (ret >= 0)
            {
                ret = DB_ACTION3(MEDPLY_DB_ACT_MODIFY_ITEM_ADD, &(plst_cntx_p->list_cntx.playing.id), &id, &total);
        }
        } while (0);
        return ret;
    }
    return ret;
}


#define _HIGHLIGHT_HANDLE
#ifdef __MMI_FTE_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_tap_callback(mmi_tap_type_enum tap_type,S32 index)
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

    mmi_medply_plstui_common_opt_initiate_play();
    
    return;
}
/*****************************************************************************
* FUNCTION
*  mmi_medply_plstui_listmgr_tap_callback
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_medply_plstui_listmgr_tap_callback(mmi_tap_type_enum tap_type,S32 index)
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

    mmi_medply_plstui_listmgr_opt_load();
    
    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_hilite_hdlr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_medply_plst_hilite_hdlr_init(void)
{

}


#define ____GENERATER
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_del_layer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param		[IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_medply_plstdb_generate_del_layer_callback(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
            break;
        case EVT_ID_SCRN_DELETE_REQ:
            break;
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_medply_plstdb_generate_deinit();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_playlist_option_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_entry_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_ENTRY_LAYER);
    entry_ret = mmi_frm_scrn_enter(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER, NULL, mmi_medply_plstdb_generate_entry_layer, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_init
 * DESCRIPTION
 *  init cntx of generate, allocate memory.
 * PARAMETERS
 *  initiate_scr_id     [IN]
 * RETURNS
 *  S32 
 *****************************************************************************/
static S32 mmi_medply_plstdb_generate_init(U16 initiate_grp_id, U16 initiate_scr_id, U8 run_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_INIT, initiate_scr_id, run_type);
    if (plst_cntx_p->generate_cntx_p == NULL)
    {
        plst_cntx_p->generate_cntx_p = 
            	(mmi_medply_generate_cntx_struct*)kal_adm_alloc(
            			g_medply.adm_id_p, sizeof(mmi_medply_generate_cntx_struct));
        if (plst_cntx_p->generate_cntx_p == NULL)
        {
            ret = MEDPLY_PLST_ERR_NO_MEMORY;
        }
        else
        {
        	MEM_TRC_ALLOCATE(plst_cntx_p->generate_cntx_p, sizeof(mmi_medply_generate_cntx_struct), __LINE__);
            memset(plst_cntx_p->generate_cntx_p, 0, sizeof(mmi_medply_generate_cntx_struct));
			/* set import settings to generate cntx. */
        	plst_cntx_p->generate_cntx_p->initiate_grp_id = initiate_grp_id;
        	plst_cntx_p->generate_cntx_p->initiate_scr_id = initiate_scr_id;
            plst_cntx_p->generate_cntx_p->run_type = run_type;
      		if (plst_cntx_p->generate_cntx_p->run_type == MMI_MEDPLY_GENERATE_ADD)
            {
				plst_cntx_p->generate_cntx_p->phase = MMI_MEDPLY_LIST_PHASE_SEARCH_FIRST;
            }
            else
            {
    			plst_cntx_p->generate_cntx_p->phase = MMI_MEDPLY_LIST_PHASE_SET_DRV;
            }
        }
    }
    else
    {
        MMI_ASSERT(plst_cntx_p->generate_cntx_p == NULL);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_deinit
 * DESCRIPTION
 *  deinit cntx of generate, free memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_deinit(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_DEINIT);
    
	if (plst_cntx_p->generate_cntx_p != NULL)
    {
        /* stop generate if it running. */
	    if (IsMyTimerExist(MEDPLY_GENERATE_TIMER))
		{
			StopTimer(MEDPLY_GENERATE_TIMER);
		}
	    
	    /* Rollback current transaction! */
		if (plst_cntx_p->db_cntx.in_transaction)
		{
			if (!plst_cntx_p->db_cntx.enable_count)
		    {    
				DB_ENABLE;
		    }
			DB_ROLLBACK_TRANSACTION;

		}
	    
		//disable if db is enable.
		if (plst_cntx_p->db_cntx.enable_count)
		{ 
			DB_DISABLE;
		}
        
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->generate_cntx_p);
        MEM_TRC_FREE(plst_cntx_p->generate_cntx_p, __LINE__);
        plst_cntx_p->generate_cntx_p = NULL;
    }

    if (mdi_audio_is_background_play_suspended())
    {
		mdi_audio_resume_background_play();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path			[IN]
 *	is_short		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstdb_generate_add(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

	plst_cntx_p->generate_cntx_p->found++;
    ret = mmi_medply_plstui_allmedia_append(path, is_short);

    if (ret != MEDPLY_PLST_ERR_NO_MEMORY &&
        ret != MEDPLY_PLST_ERR_NO_SPACE && 
        ret > MEDPLY_PLST_ERR_SQLITE_ERROR)
    {	
    	/* ignore except fatal error. */
        if (ret != MEDPLY_PLST_ERR_ITEM_EXISTS)
        {
        	plst_cntx_p->generate_cntx_p->appended++;
		}
        return MEDPLY_PLST_NO_ERROR;
    }
    else
    {
		return ret;
    }
}

#ifdef __DRM_V02__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_search_for_drm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_search_for_drm(UI_string_type odf_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_generate_cntx_struct* gen_p = plst_cntx_p->generate_cntx_p;
        /* for a short variable name. */
    drm_file_info_struct drm_file_info;
    FS_HANDLE multi_part_handle;
    UI_character_type content_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type temp_buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    S32 ret = MEDPLY_PLST_NO_ERROR;
    U16 file_format = MEDPLY_FORMAT_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gen_p->DRM_find_cntx = DRM_get_find_cntx();
    multi_part_handle = DRM_find_firstN(
                                gen_p->DRM_find_cntx,
                                (PU16)odf_path, 
                                0, 
                                0,
                                &drm_file_info,
                                content_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH,
                                0);
    if (multi_part_handle < FS_NO_ERROR)
    {
        /* because this memory will be free in DRM_find_firstN when DRM_find_firstN fail. */
        gen_p->DRM_find_cntx = NULL;
        gen_p->last_error_code = multi_part_handle;
        mmi_medply_plstdb_generate_error_hdlr();
        return;
    }
    else
    {
        do
        {
            mmi_medply_util_extract_ext(content_name, file_ext);
            file_format = mmi_medply_util_is_target_support_format(file_ext);
            if (file_format < MEDPLY_FORMAT_TOTAL && file_format != MEDPLY_FORMAT_NONE)
            {
                if (mmi_ucs2strlen((const CHAR*)odf_path) + mmi_ucs2strlen((const CHAR*)content_name) + 1 <= (SRV_FMGR_PATH_MAX_LEN+1))
                {
                    mmi_ucs2ncpy((CHAR*)temp_buffer, (const CHAR*)odf_path, (SRV_FMGR_PATH_MAX_LEN+1) - 1);
                    mmi_ucs2ncat((CHAR*)temp_buffer, (const CHAR*)L"\\", 1);
                    mmi_ucs2ncat((CHAR*)temp_buffer, (CHAR*)content_name, mmi_ucs2strlen((const CHAR*)content_name));

                    ret = mmi_medply_plstdb_generate_add(temp_buffer, MMI_FALSE);
                    if (ret < MEDPLY_PLST_NO_ERROR)
                    {
                        DRM_find_close(gen_p->DRM_find_cntx, multi_part_handle);
                        gen_p->DRM_find_cntx = NULL;
                        gen_p->last_error_code = ret;
                        mmi_medply_plstdb_generate_error_hdlr();
                        return;
                    }      

                }
            }
        } while (FS_NO_ERROR == DRM_find_nextN(
                                gen_p->DRM_find_cntx,
                                multi_part_handle, 
                                &drm_file_info,
                                content_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH,
                                1));
    }

    if (gen_p->DRM_find_cntx)
    {
        DRM_find_close(gen_p->DRM_find_cntx, multi_part_handle);
        gen_p->DRM_find_cntx = NULL;
    }

    gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
    StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_search_odf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_search_odf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plstdb_generate_search_for_drm(plst_cntx_p->generate_cntx_p->path_cache);
}
#endif  /* __DRM_V02__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_db_generate_set_drv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_set_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_generate_cntx_struct* gen_cntx = plst_cntx_p->generate_cntx_p;

    MMI_BOOL got_next = MMI_FALSE;
    U8 index = gen_cntx->drv_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gen_cntx->drv_idx < MMI_MEDPLY_DRV_TOTAL)
    {
        while (index < MMI_MEDPLY_DRV_TOTAL)
        {
            if (plst_cntx_p->drv_list[index].is_active)
            {
                kal_wsprintf(gen_cntx->path_cache, "%c:\\", plst_cntx_p->drv_list[index].drv_letter);
                index++;
                gen_cntx->drv_idx = index;
                gen_cntx->phase = MMI_MEDPLY_LIST_PHASE_SEARCH_FIRST;
                got_next = MMI_TRUE;
                break;
            }
            else
            {
                index++;
            }
        }

        if (!got_next)
        {
            gen_cntx->phase = MMI_MEDPLY_LIST_PHASE_FINISH;
        }
    }
    else
    {
        gen_cntx->phase = MMI_MEDPLY_LIST_PHASE_FINISH;
    }
    
    mmi_medply_plstdb_generate_internal();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_format = MEDPLY_FORMAT_NONE;
    FS_HANDLE ret = FS_NO_ERROR;
    U8 i = 0;
    FS_DOSDirEntry file_info;

    CHAR buf_file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH];

    UI_character_type file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    MMI_BOOL is_shortname = MMI_FALSE;
    mmi_medply_generate_cntx_struct* gen_p = plst_cntx_p->generate_cntx_p;
    
#ifdef __DRM_V02__
    UI_character_type odf_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type ext_in_odf[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    PU8 ext_name_p = NULL; 
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((CHAR*)file_path, (const CHAR*)gen_p->path_cache, (SRV_FMGR_PATH_MAX_LEN+1));
    mmi_ucs2ncat((CHAR*)file_path, (const CHAR*)L"*.*", 3);
        
    if (gen_p->phase == MMI_MEDPLY_LIST_PHASE_SEARCH_FIRST)
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
                SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                0,
                FS_FIND_DEFAULT);
        
        if (ret >= 0)
        {
            gen_p->search_handle = ret;
            gen_p->phase = MMI_MEDPLY_LIST_PHASE_SEARCH_NEXT;
            
            /* begin to cache sub-folder infomation. */
            if (gen_p->stack_index < MMI_MEDPLY_MAX_DEPTH_DIRECTORY)
            {
                gen_p->stack[gen_p->stack_index].level = gen_p->stack_index;
                gen_p->stack[gen_p->stack_index].total_sub_folder = 0;
                gen_p->stack[gen_p->stack_index].index = 0;
                gen_p->stack[gen_p->stack_index].fs_index = 0;    /* it is invalid when this value is 0 or 1. */
            }
            else
            {
                /* max level, do not save. */
                MMI_ASSERT(gen_p->stack_index < MMI_MEDPLY_MAX_DEPTH_DIRECTORY);
            }
        }
        else
        {
            if (gen_p->stack_index == 0)
            {
                if (ret == FS_NO_MORE_FILES)
                {
                    gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
                    StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
                }
                else
                {
                    gen_p->last_error_code = ret;
                    mmi_medply_plstdb_generate_error_hdlr();
                }
            }
            else
            {
                gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
                StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
            }
            return;
        }
    }
    else if (gen_p->phase == MMI_MEDPLY_LIST_PHASE_SEARCH_NEXT)
    {
        ret = FS_FindNextN(
                        gen_p->search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)buf_file_name,
                        SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
        if (ret < 0)
        {
            FS_FindClose(gen_p->search_handle);
            gen_p->search_handle = -1;
            if (ret == FS_NO_MORE_FILES)
            {
                if (!gen_p->stack[gen_p->stack_index].total_sub_folder)
                {
                    gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
                    StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
                }
                else
                {
                    if (gen_p->stack_index < MMI_MEDPLY_MAX_DEPTH_DIRECTORY)
                    {
                        gen_p->phase = MMI_MEDPLY_LIST_PHASE_FORWARDS;
                        StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
                    }
                    else
                    {
                        gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
                        StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
                    }
                }
            }
            else
            {
                if (gen_p->stack_index == 0)
                {
                    gen_p->last_error_code = ret;
                    mmi_medply_plstdb_generate_error_hdlr();
                }
                else
                {
                    gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
                    StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
                }
            }
            return;
        }
    }
    else
    {
        /* these codes should never be run. */
        MMI_ASSERT(gen_p->phase == MMI_MEDPLY_LIST_PHASE_SEARCH_NEXT ||
                   gen_p->phase == MMI_MEDPLY_LIST_PHASE_SEARCH_FIRST);
    }
    
    do
    {
        if ((file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
        {
            is_shortname = ((file_info.NTReserved & FS_SFN_MATCH) != 0);
            if (is_shortname)
            {
                U8 j = 0;
                for (j = 0; j < 3; j++)
                {
                    if (file_info.Extension[j] != ' ')
                    {
                        file_ext[j] = (UI_character_type) file_info.Extension[j];
                    }
                    else
                    {
                        break;
                    }
                }
                file_ext[j] = 0;
            }
            else
            {
                CHAR* ext = mmi_ucs2rchr((const CHAR*)buf_file_name, (U16)L'.');
                if (ext != NULL)
                {
                    ext += 2;
                    mmi_ucs2ncpy((CHAR*)file_ext, (const CHAR*)ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
                }
                else
                {
                    ext = NULL;
                    file_ext[0] = 0;
                }
            }
            file_format = mmi_medply_util_is_target_support_format(file_ext);
            if (file_format != MEDPLY_FORMAT_NONE && file_format < MEDPLY_FORMAT_TOTAL)
            {
            #ifdef __DRM_V02__
                if (!mmi_ucs2nicmp((const CHAR*)file_ext, (const CHAR*)L"odf", (U32)mmi_ucs2strlen((const CHAR*)file_ext)))
                {
                    mmi_ucs2ncpy((CHAR*)odf_path, (const CHAR*)gen_p->path_cache, (SRV_FMGR_PATH_MAX_LEN+1));
                    mmi_ucs2ncat((CHAR*)odf_path, (const CHAR*)buf_file_name, mmi_ucs2strlen((const CHAR*)buf_file_name));
                    
                    if (!DRM_is_archive(0, (PU16)odf_path))
                    {
                        ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)odf_path);
                        if (ext_name_p != NULL)
                        {
                            mmi_asc_n_to_ucs2((CHAR*)ext_in_odf, (CHAR*)ext_name_p, strlen((const char *)ext_name_p));
                        }
                        else
                        {
                            file_ext[0] = 0;
                        }
                    }
                    else
                    {
                        gen_p->phase = MMI_MEDPLY_LIST_PHASE_SEARCH_ODF;
                        StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
                        return;
                    }
                }
                else
            #endif  /* __DRM_V02__ */
                {
                    if (mmi_ucs2strlen((const CHAR*)gen_p->path_cache) + 
                        mmi_ucs2strlen((const CHAR*)buf_file_name) <= (SRV_FMGR_PATH_MAX_LEN+1))
                    {
                    	U32 path_len = 0;
                        U32 filename_len = 0;

						path_len = mmi_ucs2strlen((const CHAR*)gen_p->path_cache);
                        filename_len = mmi_ucs2strlen((const CHAR*)buf_file_name);

                        if (path_len + filename_len <= (SRV_FMGR_PATH_MAX_LEN+1))
                        {
	                        mmi_ucs2ncpy((CHAR*)file_path, (const CHAR*)gen_p->path_cache, (SRV_FMGR_PATH_MAX_LEN+1));
	                        mmi_ucs2ncat((CHAR*)file_path, (const CHAR*)buf_file_name, mmi_ucs2strlen((const CHAR*)buf_file_name));

	                        
	                        {
	                            MMI_BOOL is_short = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;
	                            /* add media file data to data file. */  
	                            ret = mmi_medply_plstdb_generate_add(file_path, is_short);
	                            
	                            if (ret < 0)
	                            {
	                                FS_FindClose(gen_p->search_handle);
	                                gen_p->search_handle = -1;
	                                gen_p->last_error_code = ret;
	                                mmi_medply_plstdb_generate_error_hdlr();
	                                return;
	                            }
	                        }
                        }
                        else
                        {
							/* too long path, skip it! */
                        }
                    }
                }
            }
            /* skip to answer other messages. */
            if ((++i) == MMI_MEDPLY_MAX_PICK_PER_SLICE)    
            {
                StartTimer(MEDPLY_GENERATE_TIMER, 50, mmi_medply_plstdb_generate_internal);
                return;
            }
        }
        else if (file_info.Attributes & FS_ATTR_DIR)
        {
            /* skip "dot" and "dot dot". */
            if (mmi_ucs2strlen((const CHAR*)buf_file_name) < 3)
            {
                if (mmi_ucs2cmp((const CHAR*)buf_file_name, (const CHAR*)L".") &&
                    mmi_ucs2cmp((const CHAR*)buf_file_name, (const CHAR*)L".."))
                {
                    gen_p->stack[gen_p->stack_index].total_sub_folder++;
                }
            }
            else
            {
                gen_p->stack[gen_p->stack_index].total_sub_folder++;
            }
            /* skip to answer other messages. */
            if ((++i) == MMI_MEDPLY_MAX_PICK_PER_SLICE * 2)    
            {
                StartTimer(MEDPLY_GENERATE_TIMER, 50, mmi_medply_plstdb_generate_internal);
                return;
            }
        }
        
        ret = FS_FindNextN(
                        gen_p->search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)buf_file_name,
                        SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
    } while (ret == FS_NO_ERROR);
    FS_FindClose(gen_p->search_handle);
    gen_p->search_handle = -1;
    if (gen_p->stack_index < MMI_MEDPLY_MAX_DEPTH_DIRECTORY)
    {
        gen_p->phase = MMI_MEDPLY_LIST_PHASE_FORWARDS;
    }
    else
    {
        gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
    }
    StartTimer(MEDPLY_GENERATE_TIMER, 50, mmi_medply_plstdb_generate_internal);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_forwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_forwards(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 return_value = 0;
    FS_DOSDirEntry file_info;
    CHAR buf_file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH];

    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    U16 counter = 0;
    mmi_medply_generate_cntx_struct* gen_p = plst_cntx_p->generate_cntx_p;
        /* for a short variable name. */
    U32 path_length = 0;
    U32 sub_folder_length = 0;
    U32 total_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(gen_p->stack_index < MMI_MEDPLY_MAX_DEPTH_DIRECTORY);
    if (!gen_p->stack[gen_p->stack_index].total_sub_folder)
    {
        /* no sub-folder, go backwards. */
        gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
        StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
        return;
    }
    else if (gen_p->stack[gen_p->stack_index].total_sub_folder == 
                                gen_p->stack[gen_p->stack_index].index)
    {
        gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
        StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
        return;
    }
    else    /* need forwards. */
    {
        mmi_ucs2ncpy((CHAR*)temp_path, (const CHAR*)gen_p->path_cache, (SRV_FMGR_PATH_MAX_LEN+1));
        mmi_ucs2ncat((CHAR*)temp_path, (const CHAR*)L"*.*", 3);

        file_handle = FS_FindFirstN(
                        (PU16)temp_path,
                        NULL,
                        0,
                        0,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16)buf_file_name,
                        SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                        gen_p->stack[gen_p->stack_index].fs_index,
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
                    
                    path_length = mmi_ucs2strlen((const CHAR*)gen_p->path_cache);
                    sub_folder_length = mmi_ucs2strlen((const CHAR*)buf_file_name);
                    total_length = 0;

                    total_length = path_length + sub_folder_length;
                    total_length++;
                    if (total_length > ((MEDPLY_MAX_PATH_LEN - 1) - 12))	/* 12 = length of "<file name>.<extension name>" */
                    //if (total_length > ((SRV_FMGR_PATH_MAX_LEN+1) - SRV_FMGR_PATH_MAX_FILE_NAME_LEN))
                    {
                        gen_p->stack[gen_p->stack_index].fs_index += counter;
                        gen_p->stack[gen_p->stack_index].index++;
                    }
                    else 
                    {
                        if ((gen_p->stack_index + 1) < MMI_MEDPLY_MAX_DEPTH_DIRECTORY)
                        {
                            /* compose next level path. */
                            mmi_ucs2cat((CHAR*)gen_p->path_cache, (const CHAR*)buf_file_name);
                            mmi_ucs2cat((CHAR*)gen_p->path_cache, (const CHAR*)L"\\");

                            /* save level node info. */
                            gen_p->stack[gen_p->stack_index].fs_index += counter;
                            gen_p->stack[gen_p->stack_index].index++;
                            /* entry next level. */
                            gen_p->stack_index++;
                            gen_p->phase = MMI_MEDPLY_LIST_PHASE_SEARCH_FIRST;
                            
                            StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
                            return;
                        }
                        else /* get max depth. */
                        {
                            /* to get next file, even have a sub-directory. */
                            gen_p->phase = MMI_MEDPLY_LIST_PHASE_SEARCH_NEXT;
                            StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
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
                                SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
                
            } while (return_value == FS_NO_ERROR);
            FS_FindClose(file_handle);
            /* no more sub-folder, backwards. */
            gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
            StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
            return;
        }
        else
        {
            if (gen_p->stack_index == 0)
            {
                if (file_handle == FS_NO_MORE_FILES)
                {
                    gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
                    StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
                }
                else
                {
                    gen_p->last_error_code = file_handle;
                    mmi_medply_plstdb_generate_error_hdlr();
                }
            }
            else
            {
                gen_p->phase = MMI_MEDPLY_LIST_PHASE_BACKWARDS;
                StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
            }
            return;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_backwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_backwards(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_generate_cntx_struct* gen_p = plst_cntx_p->generate_cntx_p;
        /* for a short variable name. */
    CHAR* last_backlash = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gen_p->stack_index > 0)
    {
        memset(&(gen_p->stack[gen_p->stack_index]), 0, 
                    sizeof(mmi_medply_plst_stack_node_struct));
        /* update path cache. */
        last_backlash = mmi_ucs2rchr((const CHAR*)gen_p->path_cache, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        
        if (gen_p->phase == MMI_MEDPLY_LIST_PHASE_BACKWARDS)
        {
            last_backlash = mmi_ucs2rchr((const CHAR*)gen_p->path_cache, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            
        }
        mmi_ucs2ncat((CHAR*)gen_p->path_cache, (const CHAR*)L"\\", 1);
        gen_p->stack_index--;

        gen_p->phase = MMI_MEDPLY_LIST_PHASE_FORWARDS;
        StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
    }
    else
    {
        if (gen_p->run_type == MMI_MEDPLY_GENERATE_ADD)
        {
            gen_p->phase = MMI_MEDPLY_LIST_PHASE_FINISH;
            StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
        }
        else if (gen_p->run_type == MMI_MEDPLY_GENERATE_UPDATE_ALL_DRV)
        {
            gen_p->phase = MMI_MEDPLY_LIST_PHASE_SET_DRV;
            StartTimer(MEDPLY_GENERATE_TIMER, 20, mmi_medply_plstdb_generate_internal);
        }
        else
        {
            MMI_ASSERT(gen_p->run_type < MMI_MEDPLY_GENERATE_TOTAL);
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_medply_generate_cntx_struct* gen_cntx = plst_cntx_p->generate_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_medply_plst_clear_gui_buffer(gen_cntx->initiate_grp_id, gen_cntx->initiate_scr_id);
    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
    mmi_frm_scrn_close(g_gid_medply, SCR_ID_MEDPLY_PLST_COMMON_NOTIFY_SCREEN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_report_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_report_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type success_msg[100];
	UI_string_type str_found, str_append;
	mmi_medply_generate_cntx_struct* gen_cntx = plst_cntx_p->generate_cntx_p;
    U8* gui_buffer = NULL;
    MMI_BOOL play_tone = MMI_FALSE;
    mmi_medply_plstui_list_cache_struct *list_p = NULL;
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*update now playing list*/
    list_p = mmi_medply_plstui_get_curr_list_cache();
    if (list_p->plstid == plst_cntx_p->list_cntx.playing.plst_id)
    {
        plst_cntx_p->list_cntx.playing.total = list_p->total;
        mmi_ucs2ncpy((CHAR*)plst_cntx_p->list_cntx.playing.title,
            (const CHAR*)list_p->title, MEDPLY_MAX_FILE_LEN - 1);
    }
    
    success_msg[0] = 0;

	if (gen_cntx->found != 1)
	{
		str_found = get_string(STR_ID_MEDPLY_PLST_FOUND);
	}
	else
	{
		str_found = get_string(STR_ID_MEDPLY_PLST_FOUND_ONE);
	}

	if (gen_cntx->appended != 1)
	{
		str_append = get_string(STR_ID_MEDPLY_PLST_APPENDED);
	}
	else
	{
		str_append = get_string(STR_ID_MEDPLY_PLST_APPENDED_ONE);
	}
 
	kal_wsprintf(success_msg, "%d%w\n%d%w", 
	             gen_cntx->found, str_found,  
                 gen_cntx->appended, str_append);

    entry_ret = mmi_frm_scrn_enter(g_gid_medply, SCR_ID_MEDPLY_PLST_COMMON_NOTIFY_SCREEN, NULL, mmi_medply_plstdb_generate_report_scr, MMI_FRM_UNKNOW_SCRN);
        
    if (!entry_ret)
    {
        return;
    }    

    gui_buffer = mmi_frm_scrn_get_gui_buf(g_gid_medply, SCR_ID_MEDPLY_PLST_COMMON_NOTIFY_SCREEN);

    if (gui_buffer == NULL)
    {
		play_tone = MMI_TRUE;
    }
	
    ShowCategory165Screen(
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        success_msg,
        mmi_get_event_based_image(MMI_EVENT_SUCCESS),
        NULL);
	
	if (play_tone)
    {
    	srv_prof_play_tone(SRV_PROF_TONE_WARNING, NULL);
    }
    
    SetRightSoftkeyFunction(mmi_medply_plstdb_generate_exit, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_generate_cntx_struct* gen_cntx = plst_cntx_p->generate_cntx_p;
    MMI_BOOL is_empty = MMI_FALSE;
    S32 ret = MEDPLY_PLST_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(gen_cntx->stack_index == 0);

    if (gen_cntx->search_handle)
    {
        FS_FindClose(gen_cntx->search_handle);
		gen_cntx->search_handle = -1;
    }

    if (!gen_cntx->found)
    {
        is_empty = MMI_TRUE;
    }
    else
    {
        mmi_medply_plst_clear_gui_buffer(gen_cntx->initiate_grp_id, gen_cntx->initiate_scr_id);
    }
      
    if (mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN))
    {
        mmi_medply_plst_clear_gui_buffer(gen_cntx->initiate_grp_id, gen_cntx->initiate_scr_id);
        mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
    }
    else
    {
    	
        if (is_empty && gen_cntx->run_type == MMI_MEDPLY_GENERATE_ADD)
        {
        	DB_ENABLE;
	        DB_END_TRANSACTION;
	        DB_DISABLE;
            if (mdi_audio_is_background_play_suspended())
            {
                mdi_audio_resume_background_play();
    		}
			mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE);
            if (gen_cntx->run_type == MMI_MEDPLY_GENERATE_ADD)
            {
                mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
            }
            else
            {
                //DeleteUptoScrID(gen_cntx->initiate_scr_id);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
            }
        }
        else
        {
			DB_ENABLE;
	        /*DB_COMMIT_TRANSACTION;*/
            if(plst_cntx_p->db_cntx.in_transaction == MMI_TRUE)
            {
    	        ret = DB_EXECUTE("COMMIT TRANSACTION", NULL);
    	        plst_cntx_p->db_cntx.in_transaction = MMI_FALSE;
	        }
            else
            {
    	        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DB_TRANSACTION_COMMIT);\
    	        MMI_ASSERT(0);
   	        }
	        DB_DISABLE;
            if (mdi_audio_is_background_play_suspended())
            {
                mdi_audio_resume_background_play();
    		}
            if (MEDPLY_PLST_NO_ERROR == ret)
            {
                mmi_medply_plstdb_generate_report_scr();
            }
            else
            {
                if (mmi_frm_scrn_get_active_id() == SCR_ID_MEDPLY_PLST_WAIT_SCREEN)
                {
    	            mmi_medply_plst_popup_simple(ret);
                    mmi_medply_plst_clear_gui_buffer(gen_cntx->initiate_grp_id, gen_cntx->initiate_scr_id);
                    mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
                } 
            }
            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_error_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_generate_cntx_struct* gen_cntx = plst_cntx_p->generate_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in special sqlite3 error case, 
       just like SQLITE_NOMEM, SQLITE_IOERR, SQLITE_INTERRUPT and SQLITE_FULL.
       Sqlite3 will forced to roll back the active transaction. 
       So this rollback action may be failed. */
    DB_ENABLE;
    DB_ROLLBACK_TRANSACTION;
    DB_DISABLE;
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }    
    if (gen_cntx->search_handle)
    {
        FS_FindClose(gen_cntx->search_handle);
		gen_cntx->search_handle = -1;
    }

    if (gen_cntx->appended)
    {
        mmi_medply_plst_clear_gui_buffer(gen_cntx->initiate_grp_id, gen_cntx->initiate_scr_id);

    }
      
    if (mmi_frm_scrn_get_active_id() == SCR_ID_MEDPLY_PLST_WAIT_SCREEN)
    {
        if (gen_cntx->last_error_code != 0)
        {
			mmi_medply_plst_popup_simple(gen_cntx->last_error_code);
            mmi_medply_plst_clear_gui_buffer(gen_cntx->initiate_grp_id, gen_cntx->initiate_scr_id);
            mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
        }
    }    
    else
    {
    	/* generate should be sleeping when wait screen in history!!! */
		MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
    }      
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_cancel_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_generate_cntx_struct* gen_cntx = plst_cntx_p->generate_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	DB_ENABLE;
    DB_ROLLBACK_TRANSACTION;
	DB_DISABLE;
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }    
    if (gen_cntx->search_handle)
    {
        FS_FindClose(gen_cntx->search_handle);
		gen_cntx->search_handle = -1;
    }

    if (gen_cntx->appended)
    {
        mmi_medply_plst_clear_gui_buffer(gen_cntx->initiate_grp_id, gen_cntx->initiate_scr_id);
    }
      
    if (mmi_frm_scrn_get_active_id() == SCR_ID_MEDPLY_PLST_WAIT_SCREEN)
    {
        mmi_medply_plst_clear_gui_buffer(gen_cntx->initiate_grp_id, gen_cntx->initiate_scr_id);
        mmi_frm_scrn_close_active_id();
		//GoBackToHistory(gen_cntx->initiate_scr_id);
    }
    else
    {
    	/* generate should be sleeping when wait screen in history!!! */

        /* when plug-in usb, the pop up of usb will be actived. */
		//MMI_ASSERT(mmi_frm_scrn_get_active_id() == SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
		mmi_frm_scrn_close(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, SCR_ID_MEDPLY_PLST_WAIT_SCREEN);
        mmi_frm_scrn_close(plst_cntx_p->generate_cntx_p->initiate_grp_id, SCR_ID_MEDPLY_PLST_GENERATE_LAYER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_cancel
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    StopTimer(MEDPLY_GENERATE_TIMER);
    plst_cntx_p->generate_cntx_p->phase = MMI_MEDPLY_LIST_PHASE_CANCEL;
    mmi_medply_plstdb_generate_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_from_folder
 * DESCRIPTION
 *  start generate list from folder.
 * PARAMETERS
 *  path                [IN]
 *  is_multi_part_odf   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_generate_cntx_struct* gen_p = plst_cntx_p->generate_cntx_p;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_ASSERT(gen_p != NULL);
    
    gen_p->appended = 0;
    gen_p->last_error_code = 0;
    gen_p->search_handle = -1;
    if (is_multi_part_odf)
    {
        gen_p->phase = MMI_MEDPLY_LIST_PHASE_SEARCH_ODF;
    }
    else
    {
        gen_p->phase = MMI_MEDPLY_LIST_PHASE_SEARCH_FIRST;
        gen_p->stack_index = 0;
        memset((gen_p->stack), 0, MMI_MEDPLY_MAX_DEPTH_DIRECTORY * sizeof(mmi_medply_plst_stack_node_struct));
    }
    
    mmi_ucs2ncpy((CHAR*)gen_p->path_cache, (const CHAR*)path, (SRV_FMGR_PATH_MAX_LEN+1));
    
    /* entry wait screen. */
    mmi_medply_plstdb_generate_wait_screen_entry();
    StartTimer(MEDPLY_GENERATE_TIMER, 50, mmi_medply_plstdb_generate_internal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }
    
	if (mmi_frm_scrn_get_active_id() != SCR_ID_MEDPLY_PLST_WAIT_SCREEN)
    {
		MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_IN_SLEEP);
		/* Sleep if the waitting screen has been in history. */
        StartTimer(MEDPLY_GENERATE_TIMER, 500, mmi_medply_plstdb_generate_internal);
        return;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_GEN_IN_PHASE, plst_cntx_p->generate_cntx_p->phase);    
    switch (plst_cntx_p->generate_cntx_p->phase)
    {
        case MMI_MEDPLY_LIST_PHASE_SET_DRV:
            MMI_ASSERT(plst_cntx_p->generate_cntx_p->run_type == MMI_MEDPLY_GENERATE_UPDATE_ALL_DRV);
            mmi_medply_plstdb_generate_set_drv();
            return;
        case MMI_MEDPLY_LIST_PHASE_SEARCH_FIRST:
            mmi_medply_plstdb_generate_search();
            return;
        case MMI_MEDPLY_LIST_PHASE_SEARCH_NEXT:
            mmi_medply_plstdb_generate_search();
            return;
        case MMI_MEDPLY_LIST_PHASE_FORWARDS:
            mmi_medply_plstdb_generate_forwards();
            return;
        case MMI_MEDPLY_LIST_PHASE_BACKWARDS:
            mmi_medply_plstdb_generate_backwards();
            return;
        case MMI_MEDPLY_LIST_PHASE_FINISH:
            mmi_medply_plstdb_generate_finish();
            return;
        case MMI_MEDPLY_LIST_PHASE_ERR_HDLR:
            mmi_medply_plstdb_generate_error_hdlr();
            return;
        case MMI_MEDPLY_LIST_PHASE_CANCEL:
            mmi_medply_plstdb_generate_cancel_hdlr();
            return;        
        case MMI_MEDPLY_LIST_PHASE_SEARCH_ODF:
        #ifdef __DRM_V02__
            mmi_medply_plstdb_generate_search_odf();
        #endif  /* __DRM_V02__ */
            return;
        default: 
            MMI_ASSERT(plst_cntx_p->generate_cntx_p->phase <= MMI_MEDPLY_LIST_PHASE_ERR_HDLR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_wait_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_wait_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_WAIT_SCREEN, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_WAIT_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_PLST_WAIT_SCREEN, 
        SCR_ID_MEDPLY_PLST_WAIT_SCREEN, 
        NULL, 
        mmi_medply_plstdb_generate_wait_screen_entry, 
        MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }    
//#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
//    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
//#endif
    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    if (mmi_medply_is_play_activated())
    {
        mdi_audio_suspend_background_play();
    }

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    SetRightSoftkeyFunction(mmi_medply_plstdb_generate_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstdb_generate_start
 * DESCRIPTION
 *  start generate.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstdb_generate_start(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_medply_plstdb_generate_wait_screen_entry();
	mmi_medply_plstdb_generate_internal();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_clear_context_variables
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_clear_context_variables(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_CLEAR_CONTEXT);
	g_medply.duration = 0;
    g_medply.filefullpath[0] = 0;
    g_medply.idle_string[0] = 0;
    g_medply.media_format = MEDPLY_FORMAT_NONE;
    g_medply.media_type = MEDPLY_TYPE_NONE;
    g_medply.seekable = MMI_FALSE;
    g_medply.need_to_build_cache = MMI_FALSE;
    g_medply.current_time = 0;
    g_medply.old_play_time = 0;
    g_medply.selected_button = MEDPLY_MAIN_DISABLED;
}

#define _________EVENT_HANDLER
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_msdc_entry_unmount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_msdc_entry_unmount(CHAR drv)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_msdc_exist_unmount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_msdc_exist_unmount(CHAR drv)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_msdc_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_num			[IN]
 *  drv_list		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[MEDPLY][PLST]mmi_medply_plst_msdc_plug_in_hdlr drv_num: %d, drv: %d", drv_num, *drv_list );
    for (i = 0; i < drv_num; i++)
    {
		if (drv_list[i] == (U8)g_medply.filefullpath[0])	
        {
			mmi_medply_plst_apply_picked_file();
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_usb_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_num			[IN]
 *  drv_list		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8  preview_file_drv_letter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[MEDPLY][PLST]mmi_medply_plst_msdc_plug_out_hdlr drv_num: %d, drv: %d" , drv_num, *drv_list);
    preview_file_drv_letter = mmi_medply_setting_get_preview_file_drv_letter();
    for (i = 0; i < drv_num; i++)
    {
        if (drv_list[i] == preview_file_drv_letter)
        {
            mmi_medply_setting_deinit_hdlr();
        }
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_usb_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
void mmi_medply_plst_usb_plug_in_hdlr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[MEDPLY][PLST]mmi_medply_plst_usb_plug_in_hdlr ");
	/*
	**	delete all screens.
	**	deinit playlist module.
	**	free ASM memory.
	*/
	/*
	for (i = NO_OF_SCR_MEDPLY-1 ; i >= SCR_ID_MEDPLY_MAIN_LIST ; i--)
    {
        DeleteScreenIfPresent(i);
    }
    */
    mmi_frm_group_close(g_gid_medply);
    mmi_medply_setting_deinit_hdlr();
    mmi_medply_plst_module_deinit();

	mmi_medply_asm_delete();
    mmi_medply_plst_clear_context_variables();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_usb_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
void mmi_medply_plst_usb_plug_out_hdlr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[MEDPLY][PLST]mmi_medply_plst_usb_plug_out_hdlr ");
	return;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_pre_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv		[IN]
 * RETURNS
 *  void
 *****************************************************************************/    
void mmi_medply_plst_pre_format_hdlr(CHAR drv)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[MEDPLY][PLST]mmi_medply_plst_pre_format_hdlr drv: %d", drv);
    if ((U8)drv == (U8)g_medply.filefullpath[0])
    {
        //need set media type to NONE, to avoid states not change to IDLE.
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
    }
    
	if ((U8)drv == MMI_MEDPLY_DB_DEFAULT_DRV)
    {
		U16 i = 0;
        //need set media type to NONE, to avoid states not change to IDLE.
        g_medply.media_type = MEDPLY_TYPE_NONE;
    	mmi_medply_stop_playing();
        StopTimer(MEDPLY_WAIT_NEXT_TIMER);
    	/* need exit app. */
	    /*
		**	delete all screens.
		**	deinit playlist module.
		**	free ASM memory.
		*/
        /*
        for (i = NO_OF_SCR_MEDPLY-1 ; i >= SCR_ID_MEDPLY_MAIN_LIST ; i--)
        {
            DeleteScreenIfPresent(i);
        }
        */
        mmi_frm_group_close(g_gid_medply);

	    mmi_medply_plst_module_deinit();

		mmi_medply_asm_delete();
        mmi_medply_plst_clear_context_variables();
        {
           	S16 error = 0;
            U64 last_list_id = 0;
        	WriteValue(NVRAM_MEDPLY_LAST_PLAYLIST_ID, &last_list_id, DS_DOUBLE, &error);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_check_file_is_playing
 * DESCRIPTION
 *  check before delete remove and delete all.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_check_file_is_playing(CHAR *path, MMI_BOOL is_folder,MMI_BOOL is_short, MMI_BOOL is_delete_all, const FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 fmgr_path_length = (U32)mmi_ucs2strlen(path);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply.state != MEDPLY_STATE_IDLE             && 
       g_medply.state != MEDPLY_STATE_AUDIO_READY      &&
       g_medply.state != MEDPLY_STATE_VIDEO_IDLE       &&
       g_medply.state != MEDPLY_STATE_PURE_AUDIO_READY &&
       g_medply.state != MEDPLY_STATE_STREAM_IDLE      &&
       g_medply.state < MEDPLY_STATE_TOTAL)
    {
        if(is_folder)
        {
            if(mmi_ucs2nicmp(path, (CHAR*)g_medply.filefullpath, fmgr_path_length) == 0)
            {
                if(is_delete_all)
                {
                    while(g_medply.filefullpath[fmgr_path_length] != 0 &&
                          g_medply.filefullpath[fmgr_path_length] != L'\\')
                    {
                        fmgr_path_length ++;
                    }
                    if (g_medply.filefullpath[fmgr_path_length] == 0)
                    {
                        CHAR* ext_ptr = mmi_ucs2rchr((const CHAR*)g_medply.filefullpath, (U16)L'.');
                        if (ext_ptr != NULL)
                        {
                            ext_ptr += 2;
                        }
                        else
                        {
                            return MMI_TRUE;
                        }
                       
                        if (!mmi_ucs2icmp((const CHAR*)ext_ptr, (const CHAR*)L"imy"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_IMY))
                            {
                                return MMI_TRUE;
                            }
                            //FMGR_FILTER_CLEAR(filter, FMGR_TYPE_IMY);
                        }
                        else if (!mmi_ucs2icmp((const CHAR*)ext_ptr, (const CHAR*)L"wav"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_WAV))
                            {
                                return MMI_TRUE;
                            }
                            //FMGR_FILTER_CLEAR(filter, FMGR_TYPE_WAV);
                        }
                        else if (!mmi_ucs2icmp((const CHAR*)ext_ptr, (const CHAR*)L"amr"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_AMR))
                            {
                                return MMI_TRUE;
                            }
                            //FMGR_FILTER_CLEAR(filter, FMGR_TYPE_AMR);
                        }
                        else if (!mmi_ucs2icmp((const CHAR*)ext_ptr, (const CHAR*)L"awb"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_AWB))
                            {
                                return MMI_TRUE;
                            }
                            //FMGR_FILTER_CLEAR(filter, FMGR_TYPE_AWB);
                        }
                        else if (FMGR_FILTER_IS_SET_AUDIO((FMGR_FILTER *)filter))
                        {
                            return MMI_TRUE;
                        }
                        return MMI_FALSE;
                    }                       
                }
                else if(*(U16*)(path+ fmgr_path_length * 2 - 2) == L'\\' || 
                        *(U16*)(path+ fmgr_path_length * 2) == 0)
                {
                    return MMI_TRUE;
                }
            }                       
        }
        else
        {
            if(mmi_ucs2nicmp(path, (CHAR*)g_medply.filefullpath, fmgr_path_length) == 0)
                return MMI_TRUE;
        }
    }
    return MMI_FALSE;

}


#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_notify_default_storage_change_pre_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_storage_letter		[IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_notify_default_storage_change_pre_check(CHAR new_storage_letter)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_notify_default_storage_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_storage_letter		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_notify_default_storage_change(CHAR new_storage_letter)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	return;
}
#endif	/* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_plst_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/

    switch(event->evt_id)
    {
#ifdef __MMI_USB_SPLIT_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            mmi_medply_plst_usb_plug_in_hdlr();
            break;
        }
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            mmi_medply_plst_usb_plug_out_hdlr();
            break;
        }
#endif /*__MMI_USB_SPLIT_SUPPORT__*/
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
        {
            srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage
                = (srv_fmgr_notification_set_def_storage_event_struct*)event;
            
            if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_QUERY) /* MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK */
            {
                return mmi_medply_plst_notify_default_storage_change_pre_check((CHAR)fmgr_storage->drv_letter);
            }
            else if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) /* MMI_FMGR_NOTIFY_SET_STORAGE */
            {
                mmi_medply_plst_notify_default_storage_change((CHAR)fmgr_storage->drv_letter);
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
                mmi_medply_plst_pre_format_hdlr((CHAR)fmgr_format->drv_letter);
            }
            break;
        }


        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT: /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_medply_plst_msdc_plug_out_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: /*MMI_FMGR_NOTIFY_DRV_POST_MOUNT*/
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_medply_plst_msdc_plug_in_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
        {
            srv_fmgr_notification_dev_soft_mount_event_struct *fmgr_mount
                = (srv_fmgr_notification_dev_soft_mount_event_struct*)event;
            
            if(fmgr_mount->mount == MMI_FALSE) /*MMI_FMGR_NOTIFY_ENTRY_UNMOUNT*/
            {
                mmi_medply_plst_msdc_entry_unmount((CHAR)fmgr_mount->drv_letter);
            }
            else /*MMI_FMGR_NOTIFY_EXIT_UNMOUNT*/
            {
                mmi_medply_plst_msdc_exist_unmount((CHAR)fmgr_mount->drv_letter);
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
                    if(mmi_medply_check_file_is_playing((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR), MMI_FALSE, MMI_FALSE, fmgr_act->filter))
                    {
                        return MMI_RET_ERR;
                    }
                }
                else if(fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL) /* MMI_FMGR_NOTIFY_PRE_DEL_ALL */
                {
                    if (!FMGR_FILTER_IS_SET_AUDIO((FMGR_FILTER *)fmgr_act->filter))
                    {
                        /* avoid: delete all image files. need not check*/
                        return MMI_RET_OK;
                    }
                    if(mmi_medply_check_file_is_playing((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR),MMI_FALSE, MMI_TRUE, fmgr_act->filter))
                    {
                        return MMI_RET_ERR;
                    }
                }
            }
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}


#define ____UTIL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_is_scrn_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_is_scrn_present(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_scrn_is_present(parent_id, scrn_id, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_get_menu_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
FuncPtr mmi_medply_util_get_menu_handler(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr old_hdlr, new_hdlr; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    new_hdlr = mmi_frm_get_hilite_hdlr(menu_id);
    if(new_hdlr)
    {
        old_hdlr = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        new_hdlr();
        new_hdlr = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        set_softkey_function(old_hdlr, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        if(new_hdlr == old_hdlr)
            new_hdlr = NULL;
    }
    return new_hdlr;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_create_file_dir
 * DESCRIPTION
 *  create file directory-resursivly
 * PARAMETERS
 *  filepath        [IN]        Filepath to be created
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_util_create_file_dir(UI_string_type filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type buf_createpath[MEDPLY_MAX_PATH_LEN];
    S32 fs_ret;
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open(filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);

        fs_ret = FS_GetAttributes(filepath);
        
        if (fs_ret & FS_ATTR_DIR)
        {
            /* folder already exist */
            return FS_NO_ERROR;   
        }
    }
    else if (file_handle != FS_FILE_NOT_FOUND &&
    	     file_handle != FS_PATH_NOT_FOUND)
    {
        return file_handle;
    }		
    		

    /* create directory if it is not there */
    str_len = mmi_ucs2strlen((const CHAR*)filepath);

    /* skip drive. "C:\" */
    for (i = 3; i < str_len; i++)
    {
        cmp_ret = mmi_ucs2ncmp((CHAR*)&filepath[i], (CHAR*) L"\\", 1);
        if (cmp_ret == 0)
        {
            /* create dir */
            mmi_ucs2ncpy((CHAR*)buf_createpath, (const CHAR*)filepath, i);
            buf_createpath[i] = 0;
            fs_ret = FS_CreateDir(buf_createpath);
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
 *  mmi_medply_util_entry_wait_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_util_entry_wait_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN, mmi_medply_plstui_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN, 
        SCR_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN, 
        NULL, 
        mmi_medply_util_entry_wait_scr, 
        MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }    

//#ifdef __MMI_LCM_PRIMITIVE_FLUSH__
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
//#endif
    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        0,
        0,
        (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_check_free_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_letter		[IN]
 *  req_size		[IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_util_check_free_space(CHAR drv_letter, U32 req_size)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    U32 disk_free_space;
    S32 fs_ret;
    UI_character_type path[10];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_clear_gui_buffer
 * DESCRIPTION
 *  clear appointed screen's gui buffer. this screen should be in history.
 * PARAMETERS
 *  scr_id		[IN]
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_medply_plst_clear_gui_buffer(U16 parent_id, U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    mmi_frm_scrn_clean_gui_buf(parent_id, (mmi_id)scr_id);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_util_drv_letter
 * DESCRIPTION
 *  return removable driver number.
 *  check phone memory, memory card, SIM+ and OTG.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_medply_plst_util_drv_letter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 drive; 
    U8 count = 0;
#if defined(__OTG_ENABLE__) || defined(__SIM_PLUS__)
    U8 i = 0;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)) >= 'A') && (drive <= 'Z'))
    {
        plst_cntx_p->drv_list[count].drv_letter = drive;
        count++;
    }
    
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        plst_cntx_p->drv_list[count].drv_letter = drive;
        count++;
    }

#ifdef __OTG_ENABLE__
    for (i = 0; i < 4; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_EXTERNAL, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            plst_cntx_p->drv_list[count].drv_letter = drive;
            count++;
        }
    }
    
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
    for (i = 0; i < USB_HOST_MS_SUPPORT_LUN; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_SIMPLUS, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            plst_cntx_p->drv_list[count].drv_letter = drive;
            count++;
        }
    }
#endif

#ifdef __MSDC2_SD_MMC__
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        plst_cntx_p->drv_list[count].drv_letter = drive;
        count++;
    }    
#endif

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_util_get_drv_status
 * DESCRIPTION
 *  update driver's status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_util_get_drv_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    FS_DiskInfo disk_info;
    UI_character_type drv_path[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
    {
        if (FS_GetDevStatus(plst_cntx_p->drv_list[i].drv_letter, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            plst_cntx_p->drv_list[i].is_active = MMI_TRUE;
            kal_wsprintf(drv_path, "%c:\\", plst_cntx_p->drv_list[i].drv_letter);
            FS_GetDiskInfo(drv_path, &disk_info, FS_DI_BASIC_INFO);
            plst_cntx_p->drv_list[i].serial_number = disk_info.SerialNumber;
        }
        else
        {
            plst_cntx_p->drv_list[i].is_active = MMI_FALSE;
            plst_cntx_p->drv_list[i].serial_number = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_is_target_support_format
 * DESCRIPTION
 *  check a file whether be supported.
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_medply_util_is_target_support_format(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S32 ext_len = 0;
    CHAR* dot = NULL;
    UI_character_type file_ext[MEDPLY_MAX_EXT_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((const CHAR*)ext)))
    {
        return MEDPLY_FORMAT_NONE;
    }
    /* skip ".". */
    dot = mmi_ucs2rchr((const CHAR*)ext, (U16)L'.');
    if (dot)
    {
        dot += 2;
    }
    else
    {
        dot = (CHAR*)ext;
    }
    mmi_ucs2ncpy((CHAR*)file_ext, (const CHAR*)dot, MEDPLY_MAX_EXT_LEN - 1);
    ext_len = mmi_ucs2strlen((const CHAR*)dot);
    
    for (i = 0; i < MEDPLY_FORMAT_TOTAL; i++)
    {
        if (ext_len == mmi_ucs2strlen((const CHAR*)support_format_table[i].ext_name))
        {
            if (!mmi_ucs2icmp((const CHAR*)file_ext, (const CHAR*)support_format_table[i].ext_name))
            {   
                return support_format_table[i].file_format;
            }
        }
    }

    return MEDPLY_FORMAT_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_is_support_format
 * DESCRIPTION
 *  check a file whether be supported.
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_medply_util_is_support_format(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S32 ext_len = 0;
    CHAR* dot = NULL;
    UI_character_type file_ext[MEDPLY_MAX_EXT_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((const CHAR*)ext)))
    {
        return MEDPLY_FORMAT_NONE;
    }
    /* skip ".". */
    dot = mmi_ucs2rchr((const CHAR*)ext, (U16)L'.');
    if (dot)
    {
        dot += 2;
    }
    else
    {
        dot = (CHAR*)ext;
    }
    mmi_ucs2ncpy((CHAR*)file_ext, (const CHAR*)dot, MEDPLY_MAX_EXT_LEN - 1);
    ext_len = mmi_ucs2strlen((const CHAR*)dot);
    
    for (i = 0; i < MEDPLY_FORMAT_TOTAL; i++)
    {
        if (ext_len == mmi_ucs2strlen((const CHAR*)media_file_info_table[i].ext_name))
        {
            if (!mmi_ucs2icmp((const CHAR*)file_ext, (const CHAR*)media_file_info_table[i].ext_name))
            {   
                return media_file_info_table[i].file_format;
            }
        }
    }

    return MEDPLY_FORMAT_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_get_file_icon
 * DESCRIPTION
 *  get icon for current file format.
 * PARAMETERS
 *  file_format        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_medply_util_get_file_icon(U16 file_format)
{
    if (file_format != MEDPLY_FORMAT_NONE && file_format < MEDPLY_FORMAT_TOTAL)
    {
        return media_file_info_table[file_format].image_id;
    }
    else if (file_format == MEDPLY_FORMAT_NONE)
    {
        return IMG_ID_MEDPLY_FILE_UNKNOWN_ICON;
    }
    else
    {
        return IMG_ID_MEDPLY_FILE_UNKNOWN_ICON;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_extract_ext
 * DESCRIPTION
 *  extract filename extension
 * PARAMETERS
 *  filename        [IN]        
 *  ext             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_util_extract_ext(const UI_string_type filename, UI_string_type ext)
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
        ext_ptr = mmi_ucs2rchr((const CHAR*)filename, (U16)L'.');

        if (ext_ptr == NULL)
        {
            *ext = 0;
        }
        else
        {
            ext_ptr += 2;
            mmi_ucs2ncpy((CHAR*)ext, (const CHAR*)ext_ptr, MEDPLY_MAX_EXT_LEN - 1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_split_filename_ext
 * DESCRIPTION
 *  split filename into two parts: name and extension
 * PARAMETERS
 *  filename                    [IN]        
 *  filename_without_ext        [IN]        
 *  ext                         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_util_split_filename_ext(const UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* dot = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
		*filename_without_ext = 0;
        *ext = 0;
   	}
    else
    {
	    mmi_ucs2ncpy((CHAR*)filename_without_ext, (const CHAR*)filename, MEDPLY_MAX_FILE_LEN - 1);
	    dot = mmi_ucs2rchr((const CHAR*)filename_without_ext, (U16)L'.');
	    if (dot == NULL)
	    {
	        *ext = 0;
	    }
	    else
	    {
	        mmi_ucs2ncpy((CHAR*)ext, (const CHAR*)(dot + 2), MEDPLY_MAX_EXT_LEN - 1);
	        *(dot + 1) = 0;
	        *dot = 0;
	    }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_extract_filename
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  filename            [IN]        
 *  fullfilename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_util_extract_filename(UI_string_type out_filename, const UI_string_type in_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* filename_ptr = NULL;
	FS_HANDLE fd = -1;
    FS_DOSDirEntry file_info;
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    MMI_BOOL is_short = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_path == NULL)
    {
		*out_filename = 0;
    }
    else
    {
		filename_ptr = mmi_ucs2rchr((const CHAR*)in_path, (U16)(L'\\'));
        if (filename_ptr == NULL)
	    {
	        *out_filename = 0;
	    }
	    else
	    {
			mmi_ucs2ncpy((CHAR*)out_filename, (const CHAR*)(filename_ptr + 2), MEDPLY_MAX_FILE_LEN - 1);
	    }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_get_filename
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  out_filename_no_ext    [OUT]        
 *  in_path                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_util_get_filename(UI_string_type out_filename, const UI_string_type in_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* filename_ptr = NULL;
    CHAR* ext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_path == NULL)
    {
		*out_filename = 0;
    }
    else
    {
		filename_ptr = mmi_ucs2rchr((const CHAR*)in_path, (U16)(L'\\'));
        if (filename_ptr == NULL)
	    {
	        *out_filename = 0;
	    }
	    else
	    {
            /* copy filename to filename buffer. */
            mmi_ucs2ncpy((CHAR*)out_filename, (const CHAR*)(filename_ptr + 2), MEDPLY_MAX_FILE_LEN - 1);
 
        	/* cut off extension name. */
			ext = mmi_ucs2rchr((const CHAR*)out_filename, (U16)L'.');
			if (ext != NULL)
			{
				*(ext + 1) = 0;
				*ext = 0;
			}
	    }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_hide_ext_name
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  out_filename_no_ext    [OUT]        
 *  in_path                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_util_hide_ext_name(CHAR *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *ext;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext = (CHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)(file_name));
    if(!ext)
    {
        return;
    }
    else
    {
        ext -= 2;
        ext[0] = ext[1] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_fill_idle_display_str
 * DESCRIPTION
 *  fill in the string shown in idle screen while playing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_util_fill_idle_display_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_details_for_display_struct   meta_info;
    S32 result;
	U32 artist_len = 0;
    U32 title_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_medply.idle_string[0]  = 0;
    
    meta_info.album[0]       = 0;
    meta_info.artist[0]      = 0;
    meta_info.title[0]       = 0;
    meta_info.user_rating    = 0;
    meta_info.artwork.mime_type  = META_TAG_IMG_TOTAL;
    meta_info.artwork.size   = 0;
    meta_info.lyrics.size    = 0;

    result = mmi_medply_plst_get_current_details(&meta_info);

    if (result >= MEDPLY_PLST_NO_ERROR)
    {
        artist_len = mmi_ucs2strlen((const CHAR*)meta_info.artist);
		title_len = mmi_ucs2strlen((const CHAR*)meta_info.title);

		if (artist_len == 0)
        {
			// just display title.
			if (title_len == 0)
	        {
	        	CHAR* dot = NULL;
	        	/* try to cut off filename as title. */
	            mmi_medply_util_extract_filename(meta_info.title, g_medply.filefullpath);
				/* cut off extended name. */
	            dot = mmi_ucs2rchr((const CHAR*)meta_info.title, (U16)L'.');
	            if (dot != NULL)	/* all supported media file should has an extended name! */
	            {
	            	*(dot + 1) = 0;
	            	*dot = 0;
	            }
				title_len = mmi_ucs2strlen((const CHAR*)meta_info.title);
	        }

            mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (const CHAR*)meta_info.title, (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        }
		else 
        {
        	if (title_len == 0)
	        {
	        	CHAR* dot = NULL;
	        	/* try to cut off filename as title. */
	            mmi_medply_util_extract_filename(meta_info.title, g_medply.filefullpath);
				/* cut off extended name. */
	            dot = mmi_ucs2rchr((const CHAR*)meta_info.title, (U16)L'.');
	            if (dot != NULL)	/* all supported media file should has an extended name! */
	            {
	            	*(dot + 1) = 0;
	            	*dot = 0;
	            }
				title_len = mmi_ucs2strlen((const CHAR*)meta_info.title);
	        }

	        if (artist_len + title_len <= (MMI_MEDPLY_MAX_ARTISRT_LEN - 1) + (MMI_MEDPLY_MAX_TITLE_LEN - 1))
	        {
	            mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (const CHAR*)meta_info.artist, (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
		        mmi_ucs2ncat((CHAR*)g_medply.idle_string, (const CHAR*)L" - ", 3);
                mmi_ucs2ncat((CHAR*)g_medply.idle_string, (const CHAR*)meta_info.title, title_len);
			}
	        else	// over limit, just display title
	        {
		        mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (const CHAR*)meta_info.title, (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
	        }
        }
    }
    else
    {
    	CHAR* dot = NULL;
        
    	g_medply.idle_string[0] = 0;
        
	    /* try to cut off filename as title. */
	    mmi_medply_util_extract_filename(meta_info.title, g_medply.filefullpath);
		/* cut off extended name. */
	    dot = mmi_ucs2rchr((const CHAR*)meta_info.title, (U16)L'.');
	    if (dot != NULL)	/* all supported media file should has an extended name! */
	    {
	    	*(dot + 1) = 0;
	    	*dot = 0;
	    }
        mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (const CHAR*)meta_info.title, ((MMI_MEDPLY_MAX_ARTISRT_LEN - 1) + (MMI_MEDPLY_MAX_TITLE_LEN - 1) + 3));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_determine_progress_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  duration [IN]    duration of current media file
 * RETURNS
 *  U32     progress speed in ms
 *****************************************************************************/
U32 mmi_medply_determine_progress_speed(U64 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 progress_speed = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (duration == 0)
    { 
        return 0;
        g_medply.seekable = MMI_FALSE;
    }
    else if (duration <= 300000) /*less than 5 mins*/
    {
        progress_speed = 1000;
    }
    else if (duration <= 600000) /*5 to 10 mins*/
    {
        progress_speed = 2000;
    }
    else
    {
        progress_speed = 4000;
    }
        
#if defined(MT6223P) || defined(MT6223)
    progress_speed = 1000;
#endif

    return progress_speed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_encoding_type_change_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_encoding_type_change_callback(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (plst_cntx_p->list_module_ready)
    {
	    mmi_medply_util_fill_idle_display_str();
	}      
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_error_string_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_medply_plst_get_error_string(S32 error_code, MMI_ID_TYPE *string_id, mmi_event_notify_enum *event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *string_id = 0;
    *event_id = MMI_EVENT_FAILURE;
    
    if (error_code > MEDPLY_PLST_ERR_INVALID_PARA)
    {
        /* handle file system error code. */
        *string_id = srv_fmgr_fs_error_get_string(error_code);

        /* handle special case. */
        switch (error_code)
        {
            case FS_NO_MORE_FILES:
                *string_id = STR_GLOBAL_EMPTY;
                *event_id = MMI_EVENT_FAILURE;
                break;
            default:
                break;
        }

        /* get image id and tone id */
        switch (*string_id)
        {
            case STR_GLOBAL_EMPTY:
                *event_id = MMI_EVENT_FAILURE;
                break;
            case STR_GLOBAL_DRM_PROHIBITED:
                *event_id = MMI_EVENT_ERROR;
                break;
            default:
                *event_id = MMI_EVENT_ERROR;
                break;        
        }
    }
#ifdef __DRM_SUPPORT__    
    else if (error_code < FS_MINIMUM_ERROR_CODE)  /* The max of File System error code */
    {
        *string_id = mmi_rmgr_get_err_string(error_code);
        *event_id = MMI_EVENT_ERROR;
    }
#endif
    else
    {
        switch (error_code)
        {
            /* warning */
            case MEDPLY_PLST_ERR_NO_SPACE:
            case MEDPLY_PLST_ERR_FILE_EXISTS:
                *event_id = MMI_EVENT_ERROR;
                break;
            default:
                *event_id = MMI_EVENT_FAILURE;
                break;        
        }
        /* get string id. */
        switch (error_code)
        {
            case MEDPLY_PLST_ERR_DB_ERROR:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_DB_ERROR;
                break;
            case MEDPLY_PLST_ERR_WRITE_FAILED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_WRITE_FAILED;
                break;
            case MEDPLY_PLST_ERR_READ_FAILED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_READ_FAILED;
                break;
            case MEDPLY_PLST_ERR_FILE_EXISTS:
                *string_id = STR_GLOBAL_FILE_ALREADY_EXISTS;
                *event_id = MMI_EVENT_ERROR;
                break;
            case MEDPLY_PLST_ERR_LIST_FULL:  
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_LIST_FULL;
                break;
            case MEDPLY_PLST_ERR_NOT_PLST:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_INVALID;
                break;
            case MEDPLY_PLST_ERR_WRONG_VER:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_WRONG_VERSION;
                *event_id = MMI_EVENT_ERROR;
                break;
            case MEDPLY_PLST_ERR_INVALID_PARA:
                *string_id = FMGR_FS_PARAM_ERROR_TEXT;
                break;
            case MEDPLY_PLST_ERR_INVALID_FILENAME:
                *string_id = STR_GLOBAL_INVALID_FILENAME;
                *event_id = MMI_EVENT_ERROR;
                break;
            case MEDPLY_PLST_ERR_EMPTY_FILENAME:
                *string_id = STR_GLOBAL_PLEASE_INPUT_THE_FILENAME;
                *event_id = MMI_EVENT_ERROR;
                break;
            case MEDPLY_PLST_ERR_CREATE_FAILED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_CREATE_FAILED;
                break;
            case MEDPLY_PLST_ERR_NO_SPACE:
                *string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
                break;
            case MEDPLY_PLST_ERR_NO_MEMORY:
                *string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
                break;
            case MEDPLY_PLST_ERR_LIST_DAMAGED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_DAMAGED;
                break;
            case MEDPLY_PLST_ERR_OPEN_FAILED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_OPEN_FAILED;
                break;
            case MEDPLY_PLST_ERR_MEAT_PARSER:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_PARSE_FILE_FAILED;
                break;
            case MEDPLY_PLST_ERR_ITEM_EXISTS:
                *string_id = STR_GLOBAL_FILE_ALREADY_EXISTS;
                *event_id = MMI_EVENT_ERROR;
                break;

            case MEDPLY_PLST_ERR_NO_FILE_LOADED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_INVALID_CURRENT_PLST;
                break;
            case MEDPLY_PLST_ERR_UNSUPPORT_FORMAT:
                *string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
                break;

            case MEDPLY_PLST_ERR_EMPTY_LIST:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_EMPTY_LIST;
                break;
            default:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_UNKNOWN_ERROR;
                break;        
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_confirm(MMI_ID parent_id, WCHAR* string, mmi_medply_playlist_alert_enum alert_type, mmi_confirm_type_enum type, MMI_BOOL no_csk_icon,  mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&property, type);
    property.parent_id = parent_id;
    property.user_tag = (void*)alert_type;
    if (no_csk_icon)
    {
        property.f_auto_map_empty_softkey = 0;
    }
    mmi_confirm_display(string, event_type, &property);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_confirm_simple
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_confirm_simple(MMI_ID parent_id, WCHAR* string, FuncPtr confirm_done, mmi_confirm_type_enum type, MMI_BOOL no_csk_icon,  mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&property, type);
    property.parent_id = parent_id;
    property.user_tag = (void*)confirm_done;
    if (no_csk_icon)
    {
        property.f_auto_map_empty_softkey = 0;
    }
    mmi_confirm_display(string, event_type, &property);
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_popup_with_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_popup_with_string(MMI_ID parent_gid, WCHAR* string, mmi_event_notify_enum event_id, mmi_proc_func callback, void* user_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(parent_gid))
    {
        grp_id = parent_gid;
    }
    else
    {
        grp_id = GRP_ID_ROOT;
    }

    
    if (callback)
    {
        mmi_popup_property_struct arg;   
        
        mmi_popup_property_init(&arg);              
        arg.callback = callback;       
        arg.user_tag = (void*)user_tag;          
        arg.parent_id = grp_id;   
        
        mmi_popup_display(                          
            string,                                
            event_id,                                   
            &arg);                                      
    }
    else
    {
        mmi_popup_display_simple(                   
            string,                                
            event_id,                                   
            grp_id,                                 
            user_tag);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_popup(MMI_ID parent_gid, S32 error_code, mmi_proc_func callback, void* user_tag, MMI_BOOL is_nmgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    mmi_event_notify_enum event_type = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_medply_plst_get_error_string(error_code, (MMI_ID_TYPE *)&string_id, &event_type);

    if (!is_nmgr)
    {
        mmi_medply_plst_popup_with_string(
            parent_gid, 
            (WCHAR *)get_string(string_id), 
            event_type, 
            callback, 
            user_tag);
    }
    else
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_PLAY_AUDIO, 
            event_type,
            (WCHAR *)get_string(string_id));
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_popup_simple_with_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_popup_simple_with_string(WCHAR* string, mmi_event_notify_enum event_id)
{
    mmi_medply_plst_popup_with_string(g_gid_medply, string, event_id, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_popup_simple
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_popup_simple(S32 error_code)
{
    mmi_medply_plst_popup(g_gid_medply, error_code, NULL, NULL, MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_code   [IN]
 *  callback     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_display_popup(S32 error_code, FuncPtr callback)
{

    mmi_medply_plst_popup(
        g_gid_medply, 
        error_code, 
        (mmi_proc_func)callback,
        NULL, 
        MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_post_event_to_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_post_event_to_main(mmi_medply_event_enum event_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    //mmi_group_node_struct node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_group_get_info(g_gid_medply, &node);
    
    MMI_FRM_INIT_EVENT(&evt, event_id);
    MMI_FRM_POST_EVENT(&evt, mmi_medply_event_proc, user_data);
}

#define __NEW_EXTERN_API
#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_single_apply_picked_file
 * DESCRIPTION
 *  apply picked file, set context for single player
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_single_apply_picked_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_format = 0;

    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_SINGLE_APPLY_BEGIN);
    
    ret = mmi_medply_plst_single_apply_picked_file_internal(g_single.filefullpath);
    if (ret < 0)
    {
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_SINGLE_APPLY_FAILED, ret);  
        g_single.media_type = MEDPLY_TYPE_NONE;
        g_single.seekable = MMI_FALSE;
        g_single.need_to_build_cache = MMI_FALSE;

        g_single.duration = 0;

    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        g_single.audio_build_cache_process = 0;
        g_single.audio_cached_duration = 0 ;
    #endif

        return ret;
    }
    else
    {   
        file_format = mmi_medply_util_is_target_support_format(g_single.filefullpath);
    #ifdef __MMI_VIDEO_STREAM__
        if (file_format == MEDPLY_FORMAT_RTSP)
        {
            g_single.media_type = MEDPLY_TYPE_STREAM_RTSP;
        }
        else if (file_format == MEDPLY_FORMAT_SDP)
        {
            g_single.media_type = MEDPLY_TYPE_STREAM_SDP;
        }
        else if (file_format == MEDPLY_FORMAT_RAM)
        {
            g_single.media_type = MEDPLY_TYPE_STREAM_RAM;
        }            
        else
    #endif
        {
            g_single.media_type = media_file_info_table[file_format].file_type;
        }
        g_single.need_to_build_cache = MMI_FALSE;
	
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
	    g_single.audio_build_cache_process = 0;
        g_single.audio_cached_duration = 0 ;
	#endif

    #if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)    
        g_single.track = MDI_VIDEO_TRACK_NONE;
    #endif

		if (g_single.media_type == MEDPLY_TYPE_AUDIO)
		{
		    if (mdi_audio_get_duration(g_single.filefullpath, (U32*)(&g_single.duration)) != MDI_AUDIO_SUCCESS)
		    {
		        g_single.duration = 0;
		    }
		}
        else if(g_single.media_type == MEDPLY_TYPE_VIDEO)
        {
            if (mdi_audio_get_mp4_duration(g_single.filefullpath, (U32*)(&g_single.duration)) != MDI_AUDIO_SUCCESS)
            {
                g_single.duration = 0;
            }
        }
		else
		{
			g_single.duration = 0;
		}
		g_single.seekable = MMI_FALSE;

        mmi_medply_main_screen_set_file_path(NULL,MMI_TRUE);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_single_do_pick
 * DESCRIPTION
 *  do pick, return next index.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_single_do_pick(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (plst_cntx_p->list_cntx.intro.pick_idx == (plst_cntx_p->list_cntx.intro.total - 1))
    {
        /* we reached the last song */
        return -1;
    }
    /* sequentially pick next item */
    plst_cntx_p->list_cntx.intro.pick_idx++;
    plst_cntx_p->list_cntx.intro.count++;    

    return plst_cntx_p->list_cntx.intro.pick_idx;
}
#endif	/* __MMI_MEDIA_PLAYER_INTRO_PLAY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_load_last
 * DESCRIPTION
 *  load last list which saved in NVRAM
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_load_last(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MEDPLY_PLST_NO_ERROR;
    S32 last_picked_index = 0;
    U32 last_list_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_clear_context_variables();

    ret = mmi_medply_plst_get_last_list(&last_list_id);

	if (ret < 0)
    {
		//got something wrong when read last list from NVRAM
		return ret;
    }
    else
    {
		// check the last list whether is valid.
		ret = DB_ACTION1(MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_ID, &last_list_id);
		if (MEDPLY_PLST_GOT_DATA == ret)
        {
            ret = mmi_medply_playing_load(last_list_id);
            if (ret < 0)
            {
            	// error when load to playing context, force to set last list invalid.
				mmi_medply_plst_save_last_list(0);
                return ret;
            }
            else
            {
				// load successful, reset playing context variables. 
				mmi_medply_plst_set_start(-1);
                // get last list index.
				if (mmi_medply_plst_get_last_list_index(&last_picked_index))
                {
					mmi_medply_plst_set_pick_index(last_picked_index);					
                }
                else
                {
					// get last list index failed. pick from header of list.
					mmi_medply_plst_set_pick_index(0);
                }

                // try to apply picked file
                if (0 > mmi_medply_plst_apply_picked_file())
			    {
					// apply failed. close playing.
					//mmi_medply_plst_playing_close();
					mmi_medply_playing_deinit();
                    // force to set last list invalid.
                    mmi_medply_plst_save_last_list(0);
                    return -1;
			    }
                else
                {
                	// apply successful, fill string which displays in idle screen.
					mmi_medply_util_fill_idle_display_str();
                    return 0;
                }
            }
        }
        else if (ret < 0)
        {
			// something error in query id.
			return ret;
        }
        else
        {
			// last list is not exist.
			return -1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_set_pick_index
 * DESCRIPTION
 *  set pick index
 * PARAMETERS
 *  index		[IN]       
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_set_pick_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_SET_PICK_IDX, index);
 
    plst_cntx_p->list_cntx.playing.pick_index = index;

    // check bistset table
    MMI_ASSERT(plst_cntx_p->list_cntx.playing.bitset.data != NULL);
    if (!mmi_medply_bitset_check(index))
    {
        mmi_medply_bitset_set(index);
        plst_cntx_p->list_cntx.playing.pick_count++;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_set_start
 * DESCRIPTION
 *  set the start of playing. reset bitset and counter
 * PARAMETERS
 *  index		[IN]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_set_start(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_SET_START, index);
    MMI_ASSERT(plst_cntx_p->list_cntx.playing.bitset.data != NULL);
    memset(plst_cntx_p->list_cntx.playing.bitset.data, 0, plst_cntx_p->list_cntx.playing.bitset.size);
    plst_cntx_p->list_cntx.playing.pick_index = index;
    plst_cntx_p->list_cntx.playing.pick_count = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_do_pick
 * DESCRIPTION
 *  pick file as setting value of repeat and shuffle.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_do_pick(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    S32 seek_count = 0;
    U8 repeat_mode = 0;
    U8 random_mode = 0;
    S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_plst_curr_is_empty())
    {
        return -1;
    }

    MMI_ASSERT(mmi_medply_settings_read_value(
                MMI_MEDPLY_SETTINGS_REPEAT, 
                &repeat_mode));

	if (repeat_mode == MMI_MEDPLY_REPEAT_ONE)
    {
    	/* pick count and bistset are useless in this time. */
		result = plst_cntx_p->list_cntx.playing.pick_index;
    }
    else
    {
	    MMI_ASSERT(mmi_medply_settings_read_value(
	                MMI_MEDPLY_SETTINGS_SHUFFULE, 
	                &random_mode));
		
		if (random_mode)
        {
			if (plst_cntx_p->list_cntx.playing.pick_count >= plst_cntx_p->list_cntx.playing.total)
            {
				/* reached end of list. */
                mmi_medply_plst_set_start(-1);	/* reset all context. */
                if (repeat_mode == MMI_MEDPLY_REPEAT_OFF)
                {
					mmi_medply_plst_set_pick_index(0);
					result = -1;	/* stop! */
                }
                else if (repeat_mode == MMI_MEDPLY_REPEAT_ALL)
                {
					/* need find an empty slot. */
                    i = (plst_cntx_p->list_cntx.playing.pick_index + (rand() % plst_cntx_p->list_cntx.playing.total) + 1) % plst_cntx_p->list_cntx.playing.total;
            
		            while (1)
		            {
		                i = (i + 1) % plst_cntx_p->list_cntx.playing.total;

		                if (mmi_medply_bitset_check(i))
		                {
		                    MMI_ASSERT(seek_count < plst_cntx_p->list_cntx.playing.total);
	                		seek_count++;
		                }
                        else
                        {
							break;
                        }
		            }
                    mmi_medply_plst_set_pick_index(i);
                    result = i;
                }
                else
                {
					MMI_ASSERT(repeat_mode != MMI_MEDPLY_REPEAT_ONE);
                }
            }
            else
            {
				/* need find an empty slot. */
                i = (plst_cntx_p->list_cntx.playing.pick_index + (rand() % plst_cntx_p->list_cntx.playing.total) + 1) % plst_cntx_p->list_cntx.playing.total;
            
		        while (1)
		        {
		            i = (i + 1) % plst_cntx_p->list_cntx.playing.total;

		            if (mmi_medply_bitset_check(i))
		            {
		                MMI_ASSERT(seek_count < plst_cntx_p->list_cntx.playing.total);
	            		seek_count++;
		            }
                    else
                    {
						break;
                    }
		        }
                
                mmi_medply_plst_set_pick_index(i);
				result = i;	/* begin from first one. */ 
            }
        }
        else
        {
        	/* "pick_count" is useless when random = OFF. */
			if (plst_cntx_p->list_cntx.playing.pick_index == plst_cntx_p->list_cntx.playing.total - 1)
            {
				/* reached end of list. */
                mmi_medply_plst_set_start(-1);	/* reset all context. */
                if (repeat_mode == MMI_MEDPLY_REPEAT_OFF)
                {
					mmi_medply_plst_set_pick_index(0);
                    result = -1;	/* stop! */
                }
                else if (repeat_mode == MMI_MEDPLY_REPEAT_ALL)
                {
                	mmi_medply_plst_set_pick_index(0);
					result = 0;	/* begin from first one. */ 
                }
                else
                {
					MMI_ASSERT(repeat_mode != MMI_MEDPLY_REPEAT_ONE);
                }
            }
            else
            {
            	plst_cntx_p->list_cntx.playing.pick_index++;
                mmi_medply_plst_set_pick_index(plst_cntx_p->list_cntx.playing.pick_index);
				result = plst_cntx_p->list_cntx.playing.pick_index;
            }
        }        
	}

	return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_pick_next
 * DESCRIPTION
 *  pick next one, as the setting of repeat and shuffle.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_pick_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    S32 seek_count = 0;
    U8 random_mode = 0;
    S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_plst_curr_is_empty())
    {
        return -1;
    }

    
	MMI_ASSERT(mmi_medply_settings_read_value(
	            MMI_MEDPLY_SETTINGS_SHUFFULE, 
	            &random_mode));
	if (random_mode)
    {
		if (plst_cntx_p->list_cntx.playing.pick_count >= plst_cntx_p->list_cntx.playing.total)
        {
			/* reached end of list. */
            mmi_medply_plst_set_start(-1);	/* reset all context. */
        }        
        
		/* need find an empty slot. */
        i = (plst_cntx_p->list_cntx.playing.pick_index + (rand() % plst_cntx_p->list_cntx.playing.total) + 1) % plst_cntx_p->list_cntx.playing.total;
        
		while (1)
		{
		    i = (i + 1) % plst_cntx_p->list_cntx.playing.total;

		    if (mmi_medply_bitset_check(i))
		    {
		        MMI_ASSERT(seek_count < plst_cntx_p->list_cntx.playing.total);
	    		seek_count++;
		    }
            else
            {
				break;
            }
		}
        mmi_medply_plst_set_pick_index(i);
		result = i;	/* begin from first one. */ 
        
    }
    else
    {
    	/* "pick_count" is useless when random = OFF. */
		if (plst_cntx_p->list_cntx.playing.pick_index == plst_cntx_p->list_cntx.playing.total - 1)
        {
			/* reached end of list. */
            mmi_medply_plst_set_start(-1);	/* reset all context. */
        }
        
        plst_cntx_p->list_cntx.playing.pick_index++;
		mmi_medply_plst_set_pick_index(plst_cntx_p->list_cntx.playing.pick_index);
		result = plst_cntx_p->list_cntx.playing.pick_index;
    }        
	
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_pick_prev
 * DESCRIPTION
 *  pick previous one. just decrease current picked index.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_pick_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plst_cntx_p->list_cntx.playing.total == 0)
    {
        return -1;
    }
    if (plst_cntx_p->list_cntx.playing.pick_index == 0)
    {
        index = plst_cntx_p->list_cntx.playing.total - 1;
    }
    else
    {
        index = plst_cntx_p->list_cntx.playing.pick_index - 1;
    }
    mmi_medply_plst_set_start(index);
    mmi_medply_plst_set_pick_index(index);
    
    return plst_cntx_p->list_cntx.playing.pick_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_apply_picked_file
 * DESCRIPTION
 *  apply picked file, fill global context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_apply_picked_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    U16 file_format = 0;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_APPLY_BEGIN);

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    g_medply.is_audio_seekable = MMI_TRUE;
#endif

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__)
    g_medply.vocal_removal = MMI_SETTINGS_VOCAL_REMOVAL_OFF;
#endif
#if defined(__MMI_AUDIO_PITCH_SHIFTING__)
    g_medply.pitch = MMI_SETTINGS_PITCH_SHIFTING_0;
#endif
    if (mmi_medply_plst_curr_is_empty())
    {
        g_medply.seekable = MMI_FALSE;
        g_medply.need_to_build_cache = MMI_FALSE;

    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        g_medply.audio_build_cache_process = 0;
        g_medply.audio_cached_duration = 0 ;
        /*refresh cache file*/
        mmi_medply_refresh_cache();
    #endif
        g_medply.selected_button = MEDPLY_MAIN_DISABLED;
        mmi_medply_main_screen_set_file_path(NULL, MMI_TRUE);

        return MEDPLY_PLST_ERR_EMPTY_LIST;
    }
    else if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
    {
        g_medply.selected_button = MEDPLY_MAIN_PLAY;
    }

	// get the file path corresponding picked index
	ret = mmi_medply_plst_apply_picked_file_internal(g_medply.filefullpath);

    if (ret < 0)
    {
    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_APPLY_FAILED, ret);
        /* reset playing list context. */
		mmi_medply_playing_deinit();			
		/* reset relative variables in media player context. */
        mmi_medply_clear_play_seconds();
		g_medply.media_format = MEDPLY_FORMAT_NONE;
		g_medply.media_type = MEDPLY_TYPE_NONE;

        g_medply.seekable = MMI_FALSE;
        g_medply.need_to_build_cache = MMI_FALSE;

        g_medply.duration = 0;

    #if defined(__MMI_MEDIA_PLAYER_VIDEO__) && defined(__MMI_A2DP_SUPPORT__)
        g_medply.bt_connect_fail = MMI_FALSE;
	#endif        

    #ifdef __MMI_AUDIO_VOCAL_REMOVAL__
        g_medply.vocal_removal_enabled = MMI_FALSE;
    #endif
        g_medply.filefullpath[0] = 0;
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        g_medply.audio_build_cache_process = 0;
        g_medply.audio_cached_duration = 0 ;
        /*refresh cache file*/
        mmi_medply_refresh_cache();
    #endif
        g_medply.selected_button = MEDPLY_MAIN_DISABLED;
        mmi_medply_main_screen_set_file_path(NULL, MMI_TRUE);
        
        // force to set last list invalid.
        mmi_medply_plst_save_last_list(0);
        return ret;
    }
    else
    {   
        // get basic data of picked file
    	mmi_medply_plstui_db_cache_item_struct basic;
    
    	ret = mmi_medply_plst_get_basic_data(&basic);
        if (ret >= 0)
        {
        	file_format = basic.format;
        }
        else
        {
        	file_format = mmi_medply_util_is_support_format(g_medply.filefullpath);
        }

        /* do more check with file path and media format. */
        if (file_format != mmi_medply_util_is_target_support_format(g_medply.filefullpath) ||
			file_format == MEDPLY_FORMAT_NONE)
        {
            /* media table error. */
            ret = MEDPLY_PLST_ERR_DB_ERROR;
           	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_APPLY_FAILED, ret);
			/* reset playing list context. */
			mmi_medply_playing_deinit();			
			/* reset relative variables in media player context. */
            mmi_medply_clear_play_seconds();
			g_medply.media_format = MEDPLY_FORMAT_NONE;
			g_medply.media_type = MEDPLY_TYPE_NONE;
            g_medply.seekable = MMI_FALSE;
            g_medply.need_to_build_cache = MMI_FALSE;

            g_medply.duration = 0;

        #if defined(__MMI_MEDIA_PLAYER_VIDEO__) && defined(__MMI_A2DP_SUPPORT__)
            g_medply.bt_connect_fail = MMI_FALSE;
    	#endif        

        #ifdef __MMI_AUDIO_VOCAL_REMOVAL__
            g_medply.vocal_removal_enabled = MMI_FALSE;
        #endif
            g_medply.filefullpath[0] = 0;
        #ifdef __MMI_MEDIA_PLAYER_AUDIO__
            g_medply.audio_build_cache_process = 0;
            g_medply.audio_cached_duration = 0 ;
            /*refresh cache file*/
            mmi_medply_refresh_cache();
        #endif
            g_medply.selected_button = MEDPLY_MAIN_DISABLED;
            mmi_medply_main_screen_set_file_path(NULL, MMI_TRUE);
            
            // force to set last list invalid.
            mmi_medply_plst_save_last_list(0);
            return ret;
        }
        
		// fill global context.
        g_medply.media_format = media_file_info_table[file_format].file_format;
        g_medply.media_type = media_file_info_table[file_format].file_type;
        g_medply.need_to_build_cache = (media_file_info_table[file_format].need_build_cache > 0 ? MMI_TRUE : MMI_FALSE);
        g_medply.build_cache_failed = MMI_FALSE;
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        g_medply.audio_build_cache_process = 0;
        g_medply.audio_cached_duration = 0 ;
        /*refresh cache file*/
        mmi_medply_refresh_cache();
    #endif


    #if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)    
        g_medply.track = MDI_VIDEO_TRACK_NONE;
    #endif            
		        
		if (g_medply.media_type == MEDPLY_TYPE_AUDIO)
		{
		    if (mdi_audio_get_duration(g_medply.filefullpath, (U32*)(&g_medply.duration)) != MDI_AUDIO_SUCCESS)
		    {
		        g_medply.duration = 0;
		    }
		}
        else if(g_medply.media_type == MEDPLY_TYPE_VIDEO)
        {
            if (mdi_audio_get_mp4_duration(g_medply.filefullpath, (U32*)(&g_medply.duration)) != MDI_AUDIO_SUCCESS)
            {
                g_medply.duration = 0;
            }
        }
		else
		{
			g_medply.duration = 0;
		}
        
		if (g_medply.duration == 0)
		{
			g_medply.seekable = MMI_FALSE;
		}
		else
		{
			g_medply.seekable = MMI_TRUE;
		}

		/* in case there is no right */
	#ifdef __DRM_SUPPORT__
		result = mmi_medply_drm_valide_right((PU16)g_medply.filefullpath);
		if(result ==2)
		{
		    g_medply.seekable = MMI_FALSE;
		}
		g_medply.DRM_consumed = MMI_FALSE;
	#endif

    #if defined(__MMI_MEDIA_PLAYER_AUDIO__)
        if(g_medply.media_type == MEDPLY_TYPE_AUDIO)
        {
            MMI_BOOL audio_seekable = MMI_TRUE;
            audio_seekable = mdi_audio_is_file_seekable(g_medply.filefullpath);
            if(!audio_seekable)
            {
                g_medply.is_audio_seekable = MMI_FALSE;
                g_medply.seekable = MMI_FALSE;
            }
        }
    #endif 
		
        g_medply.progress_speed = mmi_medply_determine_progress_speed(g_medply.duration);
		mmi_medply_plst_save_last_list_index(plst_cntx_p->list_cntx.playing.pick_index);
        mmi_medply_clear_play_seconds();
        mmi_medply_main_screen_set_file_path(NULL,MMI_TRUE);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_is_empty
 * DESCRIPTION
 *  check playing whether is empty
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_curr_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plst_cntx_p->list_cntx.playing.total > 0)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_is_valid
 * DESCRIPTION
 *  check plying context whether loaded
 * PARAMETERS
 *  void      
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_curr_is_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (plst_cntx_p->list_cntx.playing.loaded)
    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_get_curr_index
 * DESCRIPTION
 *  query the current picked index of playing.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_curr_get_curr_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mmi_medply_plst_curr_is_empty())
    {
		return -1;
    }
    
    return plst_cntx_p->list_cntx.playing.pick_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_get_total
 * DESCRIPTION
 *  query the total of playing list.
 * PARAMETERS
 *  void     
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_curr_get_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return plst_cntx_p->list_cntx.playing.total;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_current_details
 * DESCRIPTION
 *  get meta for display in main screen.
 * PARAMETERS
 *  details_data     [OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_get_current_details(mmi_medply_details_for_display_struct* details_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plst_cntx_p->list_module_ready)
    {
	    ret = mmi_medply_plst_get_current_details_internal(details_data);
	}
    else
    {
		ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_current_artwork
 * DESCRIPTION
 *  get current playing file's artwork.
 * PARAMETERS
 *  buffer 			[OUT]
 *  buffer_size 	[IN]
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_get_current_artwork(void* buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    meta_tag_img_info_struct* image_info_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    meta_parser_buffer = kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
	if (meta_parser_buffer == NULL)
	{
		MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_DETAILS_NO_MEMORY, __LINE__);
	    ret = MEDPLY_PLST_ERR_NO_MEMORY;
	}
    else
    {
		MEM_TRC_ALLOCATE(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);    
		meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

	    if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
	    {
			MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_META_CREATE_FAIL, meta_parser_ret, __LINE__);
	        ret = META_ERROR(meta_parser_ret);
	    }
		else
	    {
		    meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)g_medply.filefullpath);

		    if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
		    {
				MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_META_PARSE_FAIL, meta_return_value, __LINE__);
                ret = META_ERROR(meta_return_value);
		    }
			else
		    {
			    meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p);

			    if (buffer_size < image_info_p->data_size)
			    {
			        ret = MEDPLY_PLST_ERR_NO_MEMORY;
			    }
				else
			    {
					meta_return_value = meta_get_attach_cover_data(
			                            meta_parser_hdlr, (kal_uint8*)buffer, buffer_size);
			        if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
				    {
				    	MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_META_GET_COVER_FAIL, meta_return_value, __LINE__);
						ret = META_ERROR(meta_return_value);
				    }
			    }
			}
	        meta_parser_release(meta_parser_hdlr);
	    }

	    
		kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
		MEM_TRC_FREE(meta_parser_buffer, __LINE__);
		meta_parser_buffer = NULL;
    }
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_shuffle_change_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_value       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_shuffle_change_callback(U8 new_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 current_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plst_cntx_p->list_cntx.playing.loaded)
	{
		current_index = plst_cntx_p->list_cntx.playing.pick_index;
		if (new_value == 0)
		{
			mmi_medply_plst_set_start(-1);
			mmi_medply_plst_set_pick_index(current_index);
			plst_cntx_p->list_cntx.playing.pick_count = current_index + 1;
		}
		else if (new_value == 1)
		{	
			mmi_medply_plst_set_start(-1);
			mmi_medply_plst_set_pick_index(current_index);
		}
		else
		{
			MMI_ASSERT(new_value != 0 && new_value != 1);
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_increase_played_counter
 * DESCRIPTION
 *  increase played counter in play context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_increase_played_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	plst_cntx_p->list_cntx.playing.played_count++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_reset_played_counter
 * DESCRIPTION
 *  reset played counter in play context.
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_reset_played_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	plst_cntx_p->list_cntx.playing.played_count = 0;
}
void mmi_medply_plst_notify_file_not_available(mmi_medply_fail_play_enum type)
{
   /* dummy */
}/* added for eservice issue - 02017632 */


#endif  /* __MMI_MEDIA_PLAYER__ */

