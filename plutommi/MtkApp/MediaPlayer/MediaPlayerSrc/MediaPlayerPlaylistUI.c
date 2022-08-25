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
*  MediaPlayerPlayListUI.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player play list UI
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"
//#include "MMI_include.h"

#if defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__)
#define MEDPLY_FTE_DEBUG

#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "kal_public_api.h"

#include "gdi_features.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "gui.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "wgui_include.h"
#include "wgui_categories.h"
#include "wgui_touch_screen.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_util.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_search.h"
#include "wgui_inputs.h"
#include "wgui_categories_list.h"
#include "gui_effect_oem.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "mdi_video.h"
#include "meta_tag_api.h"
#include "SoundEffect.h"    

#include "mmi_rp_file_type_def.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_rp_app_filemanager_def.h"
#include "mmi_rp_app_uiframework_def.h" 
#include "CommonScreensResDef.h"
#include "string.h"
#include "mmi_frm_events_gprot.h"
//#include "stdlib.h"
//#include "time.h"
#include "app_str.h"
#include "Conversions.h"
//#include "CommonScreens.h"
//#include "FileMgrGProt.h"
//#include "FilemgrResDef.h"
#include "FileMgrSrvGProt.h"
#include "PhoneSetupGprots.h"
#include "ImeGprot.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "mmi_frm_scenario_gprot.h"
#include "fs_type.h"
#include "fs_func.h"
#include "DebugInitDef_Int.h"
#include "AlertScreen.h"
#include "custom_events_notify.h"
#include "lcd_sw_inc.h"
#include "FileMgrType.h"
#include "menucuigprot.h"
#include "CustMenuRes.h"
#include "drm_def.h"
#include "app_mem.h"
#include "fs_errcode.h"

#include "UcmSrvGprot.h"

#include "Drm_gprot.h"
//#ifdef __MMI_RMGR__
//#include "RightsMgrGprot.h"
//#endif

#include "FilemgrCuiGprot.h"
#include "inlinecuigprot.h"

#ifdef MOTION_SENSOR_SUPPORT
#include "SensorSrvGport.h"
#endif

#include "FSEditorCuiGprot.h"

#include "PlstSrvGprot.h"
//#include "MediaAppGProt.h"
//#include "MediaPlayerResDef.h"
#include "MediaPlayerProt.h"
#include "MediaPlayerGProt.h"
//#include "MediaPlayerSettings.h"
#include "MediaPlayerPlayList.h"
//#include "MediaPlayerplaylistkuro.h"
#include "MediaPlayerPlayListUI.h"
#include "MediaPlayerEnumDef.h"
#include "mmi_rp_app_medply_def.h"
#include "MMI_media_app_trc.h"   
#include "kurotypedef.h"
#include "kuroapi.h"    
#include "kurodatatype.h"

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
#include "UCMGProt.h"
#endif

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif



/* allocate static memory for When Cube is enable*/
#if defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)
    extern U8 g_medply_mem_pool[];
#endif

//#include "vadp_v2p_image_flow.h"
static S32 (*medply_list_extapp_cb)(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2);
static void (*medply_listui_cancel_cb)(void);

static mmi_medply_listui_context_struct g_plst_cntx;
mmi_medply_listui_context_struct* g_listui_cntx_p = &g_plst_cntx;

static U16 g_listui_title_l1[MEDPLY_MAX_FILE_LEN];
static U16 g_listui_title_l2[MEDPLY_MAX_FILE_LEN];
static U16 g_listui_item_buff[MEDPLY_MAX_FILE_LEN];
static U8* g_listui_item_image;


#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
U16 g_prefix_search_buffer[MAX_SUBMENU_CHARACTERS]; 
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/

static MMI_BOOL g_mmi_medply_listui_clear_plst_flag = MMI_FALSE;

#define MMI_MEDPLY_LISTUI_HAS_SRV_CREATE  0x00000001
#define MMI_MEDPLY_LISTUI_HAS_SRV_OPEN    0x00000002
#define MMI_MEDPLY_LISTUI_HAS_SRV_CONFIG  0x00000004
#define MMI_MEDPLY_LISTUI_HAS_SRV_OPEN_CB 0x00000008


#define MEDPLY_MAX_ITEM_LEN     (MAX_SUBMENU_CHARACTERS + 1)

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
#endif /* DAF_DECODE */ 
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
#ifdef __MMI_PURE_AUDIO__
    {MEDPLY_FORMAT_3GPA, L"3GP"},
    {MEDPLY_FORMAT_MP4A, L"MP4"},
    {MEDPLY_FORMAT_3G2A, L"3G2"},
    {MEDPLY_FORMAT_3GA,  L"3GA"},
#endif
#ifdef __APE_DECODE__
    {MEDPLY_FORMAT_APE,  L"APE"},
#endif
#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    {MEDPLY_FORMAT_OGG, L"OGG"},
#endif
#if defined(__FLAC_DECODE__ )
    {MEDPLY_FORMAT_FLAC, L"FLAC"},
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
#ifdef __MKV_FILE_FORMAT_SUPPORT__
    {MEDPLY_FORMAT_MKV, L"MKV"},
    {MEDPLY_FORMAT_WEBM, L"WEBM"},
#ifdef __VIDEO_3D_SIDE_BY_SIDE__
    {MEDPLY_FORMAT_MK3D, L"MK3D"},
#endif
#endif
#ifdef __MOT_SUPPORT__
    {MEDPLY_FORMAT_MOT, L"MOT"},
#endif
#ifdef __KMV_SUPPORT__
    {MEDPLY_FORMAT_KMV, L"KMV"},
    {MEDPLY_FORMAT_QKMV, L"QKMV"},
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
    {MEDPLY_FORMAT_FLAC, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"FLAC"},
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
    {MEDPLY_FORMAT_MKV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MKV"},
    {MEDPLY_FORMAT_WEBM, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"WEBM"},
    {MEDPLY_FORMAT_MK3D, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MK3D"},
    {MEDPLY_FORMAT_MOT, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MOT"},
    {MEDPLY_FORMAT_KMV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"KMV"},
    {MEDPLY_FORMAT_QKMV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"QKMV"},
/* streaming */
    {MEDPLY_FORMAT_RTSP, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"RTSP"},
    {MEDPLY_FORMAT_SDP, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"SDP"},
    {MEDPLY_FORMAT_RAM, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"RAM"},

    {KURO_FORMAT_KUR, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"kur"},

    {MEDPLY_FORMAT_NONE, MEDPLY_TYPE_TOTAL, 0, IMG_ID_MEDPLY_FILE_UNKNOWN_ICON, L"\0"}
};

#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
/**************************Inline CUI struct***********************************/
/* details edit */
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_title = 
{
    STR_ID_MEDPLY_PLST_DETAILS_TITLE
};
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_artist = 
{
    STR_ID_MEDPLY_PLST_DETAILS_ARTIST
};
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_album = 
{
    STR_ID_MEDPLY_PLST_DETAILS_ALBUM
};
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_genre = 
{
    STR_ID_MEDPLY_PLST_DETAILS_GENRE
};
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_author = 
{
    STR_ID_MEDPLY_PLST_DETAILS_AUTHOR
};
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_description = 
{
    STR_ID_MEDPLY_PLST_DETAILS_DESCRIPTION
};
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_tracknum = 
{
    STR_ID_MEDPLY_PLST_DETAILS_TRACK_NUM
};
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_year = 
{
    STR_ID_MEDPLY_PLST_DETAILS_YEAR
};
static const cui_inline_item_caption_struct mmi_medply_listui_inline_caption_rate = 
{
    STR_ID_MEDPLY_PLST_DETAILS_USER_RATING
};


static const cui_inline_set_item_struct mmi_medply_listui_inline_details_item[] = 
{
    {MEDPLY_DETAILS_META_TITLE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_title},
    {MEDPLY_DETAILS_META_TITLE_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_ARTIST_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_artist},
    {MEDPLY_DETAILS_META_ARTIST_DISPLAY,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_ALBUM_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_album},
    {MEDPLY_DETAILS_META_ALBUM_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_GENRE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_genre},
    {MEDPLY_DETAILS_META_GENRE_DISPLAY,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_AUTHOR_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_author},
    {MEDPLY_DETAILS_META_AUTHOR_DISPLAY,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_DESCRIPTION_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_description},
    {MEDPLY_DETAILS_META_DESCRIPTION_DISPLAY,   CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_TRACK_NUM_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_tracknum},
    {MEDPLY_DETAILS_META_TRACK_NUM_DISPLAY,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_YEAR_CAPTION,          CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_year},
    {MEDPLY_DETAILS_META_YEAR_DISPLAY,          CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
    {MEDPLY_DETAILS_META_USER_RATING_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,       0,      (void*)&mmi_medply_listui_inline_caption_rate},
    {MEDPLY_DETAILS_META_USER_RATING_DISPLAY,   CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  0,      NULL},
};


static cui_inline_item_softkey_struct mmi_medply_listui_inline_details_softkey = 
{
    {
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},                     /*MMI_LEFT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},                      /*MMI_RIGHT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}                      /*MMI_CENTER_SOFTKEY*/
    }
};


static const cui_inline_struct mmi_medply_listui_inline_details_screen = 
{
    MEDPLY_DETAILS_META_INLINE_ITEM_NUM,
    STR_GLOBAL_DETAILS,
    0,
    CUI_INLINE_SCREEN_LOOP, 
    &mmi_medply_listui_inline_details_softkey, 
    mmi_medply_listui_inline_details_item 
};
#endif /* __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__ */

#define LISTUI_DISABLE_DYNAMIC_LIST_CACHE do{                                       \
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DISABLE_DATA_CACHE);   \
        MMI_fixed_list_menu.flags |= UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA;       \
        } while(0)
        
#define LISTUI_ENABLE_DYNAMIC_LIST_CACHE do{                                        \
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENABLE_DATA_CACHE);    \
        MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA;      \
        } while(0)

#define __LISTUI_STATIC_FUNC_DEF_BEGIN
/*plst server wrapper*/
static S32 mmi_medply_listui_prepare_all_songs(
                    U32 srv_hdlr, S32 list_type, mmi_medply_listui_view_stack_struct *view_stack_p);
static S32 mmi_medply_listui_prepare_all_videos(
                    U32 srv_hdlr, S32 list_type, mmi_medply_listui_view_stack_struct *view_stack_p);
static S32 mmi_medply_listui_prepare_all_artists(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p);
static S32 mmi_medply_listui_prepare_all_albums(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p);
static S32 mmi_medply_listui_prepare_all_genres(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p);
static S32 mmi_medply_listui_prepare_all_plsts(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p);
static S32 mmi_medply_listui_prepare_artist_albums(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p,U32 id);
static S32 mmi_medply_listui_prepare_songs(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p,S32 index);
static S32 mmi_medply_listui_prepare_songs_by_id(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p,U32 id);
static S32 mmi_medply_listui_prepare_addto_plst(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p);
static S32 mmi_medply_listui_prepare_curr_plst(U32 srv_hdlr, S32 list_type,
                mmi_medply_listui_view_stack_struct *view_stack_p);
#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
static S32 mmi_medply_listui_prepare_image_flow(U32 srv_hdlr, S32 list_type,
                mmi_medply_listui_view_stack_struct *view_stack_p);
#endif
static S32 mmi_medply_listui_push_view_stack(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *stack_des_p, 
                    srv_plst_list_view_struct    *set_src_p);
static S32 mmi_medply_listui_pop_view_stack(
                    U32 srv_hdlr, mmi_medply_listui_view_stack_struct *stack_des_p);
static S32 mmi_medply_listui_get_curr_list_count(U32 srv_hdlr, U32* total_number);
static S32 mmi_medply_listui_get_list_title(U32 srv_hdlr, S32 index, UI_string_type buff);
static S32 mmi_medply_listui_get_list_title_item(U32 srv_hdlr, S32 index, UI_string_type buff);
static S32 mmi_medply_listui_get_plst_title(U32 srv_hdlr, S32 index, UI_string_type buff);
static S32 mmi_medply_listui_get_plst_title_item(U32 srv_hdlr, S32 index, UI_string_type buff);
static S32 mmi_medply_listui_get_path(U32 srv_hdlr, U32 index, U16* path);
static S32 mmi_medply_listui_get_playing_file_details(
                    U32 srv_hdlr, srv_plst_media_details_struct *details);
static S32 mmi_medply_listui_get_audio_format(U32 srv_hdlr, S32 index, U16* format);
static S32 mmi_medply_listui_get_video_format(U32 srv_hdlr, S32 index, U16* format);
static S32 mmi_medply_listui_listsrv_callback(
                    void* user_data, srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2);
static mmi_ret mmi_medply_plst_event_callback_hdlr(mmi_event_struct *event);


/*init/update*/
static MMI_BOOL g_is_auto;
static S32  mmi_medply_listui_module_init_internal(void);
static void mmi_medply_listui_module_deinit_internal(void);
static void mmi_medply_listui_library_config(void);
static void mmi_medply_listui_library_open_new_ask(void);
static void mmi_medply_listui_library_open_new(void);
static void mmi_medply_listui_exit_open_wait_screen(void);
static mmi_ret mmi_medply_listui_open_fail_proc(mmi_event_struct *param);
static void mmi_medply_listui_entry_open_wait_screen(void);
static mmi_ret mmi_medply_listui_opening_delete_callback(mmi_event_struct *param);
static void mmi_medply_listui_library_open_new_cb(void);
static S32  mmi_medply_listui_library_reopen(MMI_BOOL is_auto);
static void mmi_medply_listui_exit_refresh_lib(void);
static void mmi_medply_listui_refresh_lib_cancel(void);
static void mmi_medply_listui_entry_report(U32 data);
static mmi_ret mmi_medply_listui_report_popup_proc(mmi_event_struct *param);
static void mmi_medply_listui_reset_lib(void);
static void mmi_medply_listui_add_from_folder(MMI_BOOL isAudio);
static void mmi_medply_listui_add_from_folder_begin(UI_string_type path);
static void mmi_medply_listui_add_from_folder_exit(void);
static void mmi_medlpy_listui_add_from_folder_hdlr(cui_file_selector_result_event_struct *file_select);

/*show list*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_medply_listui_type_list_tap_callback(mmi_tap_type_enum tap_type,S32 index);
static void mmi_medply_listui_song_list_tap_callback(mmi_tap_type_enum tap_type,S32 index);
static void mmi_medply_listui_plst_list_tap_callback(mmi_tap_type_enum tap_type,S32 index);
static void mmi_medply_listui_search_list_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif

static void mmi_medply_listui_type_open_list(void);
static void mmi_medply_listui_entry_artist_album_list(void);
static void mmi_medply_listui_entry_category_song_list(void);
static void mmi_medply_listui_entry_plst_song_list(void);
static void mmi_medply_listui_show_common_list_scr(
                UI_string_type title, S32 total, S32 highlight, MMI_BOOL lsk_flag);
static void mmi_medply_listui_artist_album_highlight_hdlr(S32 index);
static void mmi_medply_listui_common_highlight_hdlr(S32 index);
pBOOL mmi_medply_listui_get_common_list_item(
                S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
S32 mmi_medply_listui_get_common_list_hint(
                S32 item_index, UI_string_type *hint_array);
static void mmi_medply_listui_entry_song_list_option(void);
static void mmi_medply_listui_entry_plst_list_option(void);
static void mmi_medply_listui_entry_type_list_option(void);
static mmi_ret mmi_medply_listui_delete_callback(mmi_event_struct *param);
static void mmi_medply_listui_card_plug_in_hdlr(void);

/*common operation*/
static void mmi_medply_listui_type_play(void);
static void mmi_medply_listui_file_play(void);
static void mmi_medply_listui_common_begin_play(void);
static void mmi_medply_listui_common_delete_req(void);
static void mmi_medply_listui_common_delete(void);
static void mmi_medply_listui_common_delete_stop(void);
static void mmi_medply_listui_common_remove_req(void);
static void mmi_medply_listui_common_remove(void);
static void mmi_medply_listui_common_remove_stop(void);

/*addto plst*/
static void mmi_medply_listui_addto_plst(void);
static void mmi_medply_listui_entry_addto_list(void);
static void mmi_medply_listui_exit_addto_list(void);
static void mmi_medply_listui_addto_plst_done(void);
static void mmi_medply_listui_addto_plst_cancel(void);
static void mmi_medply_listui_show_addto_plst_scr(UI_string_type title, S32 total, S32 highlight);

static void mmi_medply_listui_clear_plst(void);

/*plst operation*/
static void mmi_medply_listui_plst_open(void);
static void mmi_medply_listui_plst_play(void);
static void mmi_medply_listui_plst_create(void);
static MMI_BOOL mmi_medply_listui_plst_create_done(void);
static void mmi_medply_listui_plst_delete_req(void);
static void mmi_medply_listui_plst_delete(void);
static void mmi_medply_listui_plst_delete_stop(void);
static void mmi_medply_listui_plst_rename(void);
static MMI_BOOL mmi_medply_listui_plst_rename_done(void);

/*multi select*/
static void mmi_medply_listui_multiset_highlight_hdlr(S32 index);
static void mmi_medply_listui_multi_select_begin(void);
static void mmi_medply_listui_multi_select_end(void);
static void mmi_medply_listui_entry_multisel_list(void);
mmi_ret mmi_medply_listui_multisel_delete_callback(mmi_event_struct *param);
static void mmi_medply_listui_entry_multisel_option(void);
static void mmi_medply_listui_multi_add_begin(void);
static void mmi_medply_listui_multi_add_end(void);
static void mmi_medply_listui_entry_multiadd_list(void);
mmi_ret mmi_medply_listui_multiadd_delete_callback(mmi_event_struct *param);
static void mmi_medply_listui_multi_add_done(void);
static void mmi_medply_listui_multi_add_cancel(void);
static void mmi_medply_listui_entry_multiadd_option(void);
static void mmi_medply_listui_multi_select_mark_all(void);
static void mmi_medply_listui_multi_select_unmark_all(void);
static void mmi_medply_listui_show_check_list_scr(S32 total, S32 highlight);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_medply_listui_multisel_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif
static void mmi_medply_listui_checklist_change_state(void);
static S32 mmi_medply_listui_checklist_get_state(S32 item_index, PU8 *checkbox_image);
static S32 mmi_medply_listui_checklist_set_state(S32 item_index);
static void mmi_medply_listui_multisel_delete_req(void);
static void mmi_medply_listui_multisel_remove_req(void);

/*organize*/
static void mmi_medply_listui_plst_organize_req(void);
static void mmi_medply_listui_plst_organize_begin(void);
static void mmi_medply_listui_plst_organize_end(void);
static void mmi_medply_listui_plst_organize_error_quit(S32 err);
static void mmi_medply_listui_entry_organzie_list(void);
mmi_ret mmi_medply_listui_organize_delete_callback(mmi_event_struct *param);
/*static void mmi_medply_listui_organize_list_tap_callback(mmi_tap_type_enum tap_type,S32 index);*/
static void mmi_medply_listui_show_organize_scr(
                S32 total, S32 highlight,MMI_BOOL is_hold, MMI_BOOL is_changed);
pBOOL mmi_medply_listui_get_organize_list_item
                (S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 mmi_medply_listui_get_orgnz_list_title(U32 srv_hdlr, S32 index, UI_string_type buff);
static void mmi_medply_listui_organize_list_goto_prev_item(void);
static void mmi_medply_listui_organize_list_goto_next_item(void);
static void mmi_medply_listui_organize_set_move(void);
static void mmi_medply_listui_organize_get_move(void);
static void mmi_medply_listui_organize_cancel_move(void);
static U32  mmi_medply_listui_organize_disable_shortcut_callback(void);
static void mmi_medply_listui_organize_hilite_hdlr(S32 index);

#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
/*search*/
static void mmi_medply_listui_prefix_search_begin(void);
static void mmi_medply_listui_prefix_search_end(void);
static void mmi_medply_listui_show_prefix_srch_scr(void);
static void mmi_medply_listui_entry_prefix_search(void);
static pBOOL mmi_medply_listui_prefix_search_get_item(
                S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 mmi_medply_listui_do_prefix_search(U8* str);
mmi_ret mmi_medply_listui_search_delete_callback(mmi_event_struct *param);
static void mmi_medply_listui_entry_search_option(void);
static void mmi_medply_listui_entry_song_list_search_option(void);
static void mmi_medply_listui_entry_type_list_search_option(void);

#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/

/* details */
static void mmi_medply_listui_entry_preview_details(void);
static void mmi_medply_listui_entry_details(void);
static void mmi_medply_listui_get_details_extern(
                    UI_string_type path, mmi_medply_listui_details_view_struct* view_data_p);
static void mmi_medply_listui_details_prepare_display(void);
static void mmi_medply_listui_show_preview_details_scr(
                    const mmi_medply_listui_details_view_struct* view_data_p);
static void mmi_medply_listui_show_preview_video_details_scr(
                    const mmi_medply_listui_details_view_struct* view_data_p);
static void mmi_medply_listui_details_highlight_hdlr(S32 index);
static void mmi_medply_listui_details_preview_delete_hdlr(void);
mmi_ret mmi_medply_listui_details_delete_callback(mmi_event_struct *param);

/*edit details*/
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
static void mmi_medply_listui_edit_details(void);
static void mmi_medply_listui_entry_edit_details(void);
static void mmi_medply_listui_details_set_value(MMI_ID inline_id);
static void mmi_medply_listui_exit_edit_details(void);
static void mmi_medply_listui_entry_details_edit_item(void);
static void mmi_medply_listui_entry_details_edit_rating(void);
static void mmi_medply_listui_show_edit_rating_scr(U8 index);
static void mmi_medply_listui_set_rating_highlight_hdlr(S32 index);
static void mmi_medply_listui_set_rating_done(void);
static void mmi_medply_listui_details_save_confirm(void);
static void mmi_medply_listui_details_edit_save(void);
static void mmi_medply_listui_details_edit_resaved(void);
static void mmi_medply_listui_details_make_date_string(
                UI_string_type out_string, srv_plst_time_struct time);
static MMI_BOOL mmi_medply_details_numeric_done_func(void);
static MMI_BOOL mmi_medply_details_text_done_func(void);
static S32 mmi_medply_details_check_modification(void);
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
    
/*editor*/
static void mmi_medply_listui_entry_editor(void);
static MMI_BOOL mmi_medply_listui_editor_check_valid(void);

/*util*/
static S32 mmi_medply_listui_util_set_cache_mem(U32 mem_size);
static S32 mmi_medply_listui_util_clear_cache_mem(void);
static void mmi_medply_listui_popup_error(S32 error_code);
static void mmi_medply_listui_popup_error_with_cb(S32 error_code, mmi_proc_func cb);
static void mmi_medply_listui_popup_done(void);
static void mmi_medply_listui_popup_by_strid(U16 strid, mmi_event_notify_enum type);
static void mmi_medply_listui_show_wait_scr(void);
static void mmi_medply_listui_entry_wait_scr(void);
static mmi_ret mmi_medply_listui_wait_scr_delete_callback(mmi_event_struct *param);
static S32 mmi_medply_listui_util_delete_upto(mmi_id scrn_id);
static void mmi_medply_listui_util_clear_scrn(mmi_id scrn_id);
static U16 mmi_medply_util_is_service_support_format(const UI_string_type ext, MMI_BOOL is_video);
static U16 mmi_medply_util_is_service_support_format_ex(const UI_string_type ext, MMI_BOOL is_video);

/*static void mmi_medply_listui_get_date_time_string(UI_string_type out_string, 
                                                   const srv_plst_time_struct* time_p);*/
static void mmi_medply_listui_get_rating_string(UI_string_type out_str, U8 user_rating);
static void mmi_medply_plst_clear_context_variables(void);
static void mmi_medply_listui_currplay_highlight_hdlr(S32 index);
static void mmi_medply_listui_show_curr_list_scr(UI_string_type title, S32 total, S32 highlight);
static S32 mmi_medply_plstui_fmgr_delete_hdlr(U32 para);
static S32 mmi_medply_plstui_msdc_plug_in_hdlr(U32 drv);
static S32 mmi_medply_plstui_msdc_plug_out_hdlr(U32 drv);
static void mmi_medply_plstui_entry_unmount_hdlr(U32 drv);

#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
extern U8 g_skin_custom_path[];
static void  mmi_medply_listui_entry_image_flow(void);
static void mmi_medply_listui_edit_elbum(void);
static void mmi_medply_listui_edit_album_hdlr(cui_file_selector_result_event_struct *file_select);
static MMI_BOOL mmi_medply_listui_cover_select_callback(void);
static MMI_BOOL mmi_medply_listui_cover_check_valid(void);
static void mmi_medply_listui_enter_cover_preview(void);
static void mmi_medply_listui_select_cover_done(void);
static void mmi_medply_listui_select_cover_back(void);
static void mmi_medply_listui_cover_preview_callback(S32 result);
static void mmi_medply_listui_exit_edit_elbum(void);
#endif /*__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__*/


#define __LISTUI_PLSTSRV_WRAPPER
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_songs
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_all_songs(
                    U32 srv_hdlr, S32 list_type, mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }

    temp_view_set.view_type = SRV_PLST_VIEW_AUDIO;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;
    temp_view_set.id = 0;
    temp_view_set.is_id_used = MMI_FALSE;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type,view_stack_p, &temp_view_set);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_songs
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
 static S32 mmi_medply_listui_prepare_all_videos(
                    U32 srv_hdlr, S32 list_type, mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }

    temp_view_set.view_type = SRV_PLST_VIEW_VIDEO;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;
    temp_view_set.id = 0;
    temp_view_set.is_id_used = MMI_FALSE;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type,view_stack_p, &temp_view_set);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_artists
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_all_artists(U32 srv_hdlr, S32 list_type,
                            mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }
    temp_view_set.view_type = SRV_PLST_VIEW_ARTIST;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;
    temp_view_set.id = 0;
    temp_view_set.is_id_used = MMI_FALSE;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_albums
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_all_albums(U32 srv_hdlr, S32 list_type,
                            mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }

    temp_view_set.view_type = SRV_PLST_VIEW_ALBUM;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;
    temp_view_set.id = 0;
    temp_view_set.is_id_used = MMI_FALSE;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_genres
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_all_genres(U32 srv_hdlr, S32 list_type,
                mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }
    temp_view_set.view_type = SRV_PLST_VIEW_GENRE;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;
    temp_view_set.id = 0;
    temp_view_set.is_id_used = MMI_FALSE;
    
    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_plsts
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_all_plsts(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }

    temp_view_set.view_type = SRV_PLST_VIEW_PLST;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;
    temp_view_set.id = 0;
    temp_view_set.is_id_used = MMI_FALSE;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_albums
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_artist_albums(U32 srv_hdlr, S32 list_type,
                mmi_medply_listui_view_stack_struct *view_stack_p,U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        return SRV_PLST_OK;
    }
    
    temp_view_set.view_type = SRV_PLST_VIEW_ALBUM;
    temp_view_set.index = 0;
    temp_view_set.id = id;
    temp_view_set.is_id_used = MMI_TRUE;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_album_songs
 * DESCRIPTION
 *  Artist->album->songs.
 *  Album->songs.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_songs(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }

    temp_view_set.view_type = SRV_PLST_VIEW_MEDIA;
    temp_view_set.index = index;
    temp_view_set.is_id_used = MMI_FALSE;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_album_songs
 * DESCRIPTION
 *  Artist->album->songs.
 *  Album->songs.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_songs_by_id(U32 srv_hdlr, S32 list_type,
                    mmi_medply_listui_view_stack_struct *view_stack_p,U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }

    temp_view_set.view_type = SRV_PLST_VIEW_MEDIA;
    temp_view_set.index = 0;
    temp_view_set.id = id;
    temp_view_set.is_id_used = MMI_TRUE;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_albums
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_addto_plst(U32 srv_hdlr, S32 list_type,
                mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }
    
    temp_view_set.view_type = SRV_PLST_VIEW_PLST_ADDTO;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_albums
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_curr_plst(U32 srv_hdlr, S32 list_type,
                mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        //TODO: Add log, that has in all songs list now.
        return SRV_PLST_OK;
    }
    
    temp_view_set.view_type = SRV_PLST_VIEW_PLST_ACTIVE;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}


#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_all_albums
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_prepare_image_flow(U32 srv_hdlr, S32 list_type,
                mmi_medply_listui_view_stack_struct *view_stack_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    temp_view_set;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_type == view_stack_p->list_type[view_stack_p->curr_ptr])
    {
        return SRV_PLST_OK;
    }
    
    temp_view_set.view_type = SRV_PLST_VIEW_IMAGE_FLOW;
    temp_view_set.index = SRV_PLST_VIEW_ROOT;

    return mmi_medply_listui_push_view_stack(srv_hdlr, list_type, view_stack_p, &temp_view_set);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_push_view_stack
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_push_view_stack(U32 srv_hdlr, S32 list_type,
                                mmi_medply_listui_view_stack_struct *stack_des_p, 
                                srv_plst_list_view_struct    *set_src_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    *set_des_p;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stack_des_p->curr_ptr++;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PUSH_VIEW_STACK,
                     list_type, stack_des_p->curr_ptr);
    /* push view stack */
    set_des_p = &(stack_des_p->view_set[stack_des_p->curr_ptr]);
    memcpy(set_des_p, set_src_p, sizeof(srv_plst_list_view_struct));
    stack_des_p->list_type[stack_des_p->curr_ptr] = list_type;
    
    ret = srv_plst_list_entry(srv_hdlr, set_des_p);
    if (ret < SRV_PLST_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLSTUI_PUSH_VIEW_STACK_FAIL, ret);
        /*srv_plst_list_exit(srv_hdlr);*/
        mmi_medply_listui_pop_view_stack(srv_hdlr, stack_des_p);
    }
    else if(ret == SRV_PLST_ASYNC)
    {
        MMI_ASSERT(0); /* this CMD should not be a non-blocking function*/
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_pop_view_stack
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_pop_view_stack(U32 srv_hdlr, mmi_medply_listui_view_stack_struct *stack_des_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_struct    *view_set_p;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_POP_VIEW_STACK, stack_des_p->curr_ptr);
    MMI_ASSERT(stack_des_p != NULL);
    if (stack_des_p->curr_ptr < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_POP_VIEW_STACK_POP_AGAIN, 
                         stack_des_p->curr_ptr);    
        return 0;
    }
    
    view_set_p = &(stack_des_p->view_set[stack_des_p->curr_ptr]);
    view_set_p->view_type = SRV_PLST_VIEW_DUMMY;
    view_set_p->index = -1;
    stack_des_p->list_type[stack_des_p->curr_ptr] = LIST_TYPE_NONE;
    stack_des_p->curr_ptr--;
    ret = srv_plst_list_exit(srv_hdlr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_POP_VIEW_STACK_RET, ret);
    MMI_ASSERT(stack_des_p->curr_ptr >= -1);   
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_curr_list_total
 * DESCRIPTION
 *  Get current list total number.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_get_curr_list_count(U32 srv_hdlr, U32* total_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ret = srv_plst_list_get_item_count(srv_hdlr, total_number);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_list_title
 * DESCRIPTION
 *  Get current list total number.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_get_list_title(U32 srv_hdlr, S32 index, UI_string_type buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct temp_info;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_info.index = index;
    temp_info.buff_size = MEDPLY_MAX_FILE_LEN - 1;
    temp_info.string_ptr = (U32)buff;
    ret = srv_plst_list_get_item_display(srv_hdlr, &temp_info);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_list_title_item
 * DESCRIPTION
 *  Get current list total number.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_get_list_title_item(U32 srv_hdlr, S32 index, UI_string_type buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct temp_info;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_info.index = index;
    temp_info.buff_size = MEDPLY_MAX_ITEM_LEN - 1;
    temp_info.string_ptr = (U32)buff;
    ret = srv_plst_list_get_item_display(srv_hdlr, &temp_info);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_plst_title
 * DESCRIPTION
 *  Get current list total number.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_get_plst_title(U32 srv_hdlr, S32 index, UI_string_type buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct temp_info;
    U32 default_type;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_info.index = index;
    temp_info.buff_size = MEDPLY_MAX_FILE_LEN - 1;
    temp_info.string_ptr = (U32)buff;
    ret = srv_plst_list_get_item_display(srv_hdlr, &temp_info);
    if (ret < SRV_PLST_OK)
    {
        return ret;
    }

    if (buff[0] == 0)
    {   
        /*get default playlist type*/
        ret = srv_plst_default_playlist_get_type(g_listui_cntx_p->srv_cntx.srv_hdlr,index, &default_type);
        switch(default_type)
        {
        case SRV_PLST_DEF_ALL_KURO_LIST:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_ALL_KURO_SONGS), MEDPLY_MAX_FILE_LEN - 1);
            break;
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
        case SRV_PLST_DEF_MY_FAVOURITE:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_MY_FAVOURITE), MEDPLY_MAX_FILE_LEN - 1);
            break;
        case SRV_PLST_DEF_RECENTLY_PLST:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_RECENTLY), MEDPLY_MAX_FILE_LEN - 1);
            break;
        case SRV_PLST_DEF_MOST_PLST:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_MOST), MEDPLY_MAX_FILE_LEN - 1);
            break;
        case SRV_PLST_DEF_ON_THE_FLY:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_ON_THE_FLY), MEDPLY_MAX_FILE_LEN - 1);
            break;
    #endif /* #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__ */
        default:
            break;
        }
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_plst_title_item
 * DESCRIPTION
 *  Get current list total number.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_get_plst_title_item(U32 srv_hdlr, S32 index, UI_string_type buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct temp_info;
    U32 default_type;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_info.index = index;
    temp_info.buff_size = MEDPLY_MAX_ITEM_LEN - 1;
    temp_info.string_ptr = (U32)buff;
    ret = srv_plst_list_get_item_display(srv_hdlr, &temp_info);
    if (ret < SRV_PLST_OK)
    {
        return ret;
    }

    if (buff[0] == 0)
    {   
        /*get default playlist type*/
        ret = srv_plst_default_playlist_get_type(g_listui_cntx_p->srv_cntx.srv_hdlr,index, &default_type);
        switch(default_type)
        {
        case SRV_PLST_DEF_ALL_KURO_LIST:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_ALL_KURO_SONGS), MEDPLY_MAX_ITEM_LEN - 1);
            break;
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
        case SRV_PLST_DEF_MY_FAVOURITE:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_MY_FAVOURITE), MEDPLY_MAX_ITEM_LEN - 1);
            break;
        case SRV_PLST_DEF_RECENTLY_PLST:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_RECENTLY), MEDPLY_MAX_ITEM_LEN - 1);
            break;
        case SRV_PLST_DEF_MOST_PLST:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_MOST), MEDPLY_MAX_ITEM_LEN - 1);
            break;
        case SRV_PLST_DEF_ON_THE_FLY:
            mmi_ucs2ncpy((CHAR*)buff, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_ON_THE_FLY), MEDPLY_MAX_ITEM_LEN - 1);
            break;
    #endif /* __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__ */
        default:
            break;
        }
    }
    
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_listui_get_path
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL 
*****************************************************************************/
static S32 mmi_medply_listui_get_path(U32 srv_hdlr, U32 index, U16* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct info;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info.buff_size = MEDPLY_MAX_PATH_LEN;
    info.index = index;
    info.string_ptr = (U32)path;
    
    ret = srv_plst_media_get_path(srv_hdlr, &info);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prepare_details
 * DESCRIPTION
 *  If has in all songs list, do nothing.
 *  If do not in all songs list, entry list service all songs list
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_get_playing_file_details(U32 srv_hdlr, srv_plst_media_details_struct *details)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 media_id;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*check current list is media file list*/
    ret = srv_plst_plst_item_get_active_media_info_curr(srv_hdlr, &media_id, &g_listui_cntx_p->playing.pick_index, NULL);
    if (ret < SRV_PLST_OK)
    {
         //TODO: add error logs
    }
    else
    {
        ret = srv_plst_media_get_details(srv_hdlr, media_id, details);
        if (SRV_PLST_OK == ret)
        {
            if (details->user_rating > 5)
            {
                 details->user_rating = 0;   
            }
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_audio_format
 * DESCRIPTION
 *  Get current list total number.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_get_audio_format(U32 srv_hdlr, S32 index, U16* format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 path[MEDPLY_MAX_PATH_LEN];
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *format = MEDPLY_FORMAT_NONE;
    
    ret = mmi_medply_listui_get_path(srv_hdlr, index, path);

    if (ret >= SRV_PLST_OK)
    {
        *format = mmi_medply_util_is_service_support_format(path, MMI_FALSE);
    }   

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_AUDIO_FORMAT,
                     *format, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_video_format
 * DESCRIPTION
 *  Get current list total number.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_get_video_format(U32 srv_hdlr, S32 index, U16* format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 path[MEDPLY_MAX_PATH_LEN];
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *format = MEDPLY_FORMAT_NONE;
    
    ret = mmi_medply_listui_get_path(srv_hdlr, index, path);

    if (ret >= SRV_PLST_OK)
    {
        *format = mmi_medply_util_is_service_support_format(path, MMI_TRUE);
    }   

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_VIDEO_FORMAT,
                    *format, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_listsrv_callback
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_listsrv_callback(void* user_data, srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_LISTSRV_CALLBACK,
                     cb_event, result, ca_para_2);
    
    if (NULL != medply_list_extapp_cb)
    {
        if(medply_list_extapp_cb(cb_event, result, ca_para_2))
        {
            return MMI_TRUE;
        }        
    }

    switch (cb_event)
    {
    case SRV_PLST_CB_EVT_OPEN:  /*List operation*/
        medply_listui_cancel_cb = NULL;
        g_listui_cntx_p->srv_cntx.state_flag |= MMI_MEDPLY_LISTUI_HAS_SRV_OPEN_CB;
        if (result >= SRV_PLST_OK)
        {
            mmi_medply_listui_library_open_new_cb();
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE, SCR_ID_MEDPLY_LISTUI_OPENING);

        }
        else
        {
            mmi_medply_listui_popup_error_with_cb(result, mmi_medply_listui_open_fail_proc);
        }
        g_listui_cntx_p->srv_cntx.state_flag &= ~MMI_MEDPLY_LISTUI_HAS_SRV_OPEN_CB;
        break;
        
    case SRV_PLST_CB_EVT_UPDATE:  /*List operation*/
        medply_listui_cancel_cb = NULL;
        g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_REFRESH;
        if (result >= SRV_PLST_OK)
        {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
	        if (mmi_frm_group_is_present(GRP_ID_MEDPLY_FTE))
            {
                if(!mmi_medply_listui_is_main_menu_grp_created())
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_MAIN_MENU);
                    mmi_medply_entry_main_menu_scr();
                }
            }

#else
/* under construction !*/
#endif
        }
        else
        {
            mmi_medply_listui_popup_error(result);            
        }
        if(mmi_frm_group_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU))
        {
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
        }
        else
        {
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE, SCR_ID_MEDPLY_LISTUI_WAITING);
        }
        break;
        
    case SRV_PLST_CB_EVT_DELETE_LIST:  /*List operation*/
        medply_listui_cancel_cb = NULL;
        if (result >= SRV_PLST_OK)
        {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
        }
        else
        {
            mmi_medply_listui_popup_error(result);
            
        }
        if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL)
        {
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL);    
        }
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
        if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
        {
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
        }   
    #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/

        if(g_mmi_medply_listui_clear_plst_flag == MMI_TRUE)
        {
            srv_plst_list_multi_select_mark_end(g_listui_cntx_p->srv_cntx.srv_hdlr);
            g_mmi_medply_listui_clear_plst_flag = MMI_FALSE;
        }
        /* Close processing screen */
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);

        /* MAUI_02175118 check if need delete some screen or clear gui buffer*/
        if (0 == ca_para_2)
        {
            if (LIST_TYPE_CATEGORY_SONG_LIST == g_listui_cntx_p->list_info.list_type)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_CHECK);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_GENRES);
            }
            else if (LIST_TYPE_ARTIST_ALBUM_LIST == g_listui_cntx_p->list_info.list_type)
            {
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS);
            }
        }
        g_listui_cntx_p->list_info.launch_scr_id = 0;
        break;
        
    case SRV_PLST_CB_EVT_ADD_TO_PLST:  /*List operation*/
        medply_listui_cancel_cb = NULL;
        if (result >= SRV_PLST_OK)
        {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
        }
        else
        {
            mmi_medply_listui_popup_error(result);
        }

        if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL)
        {
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL);    
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTIADD);    
        }
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
        if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
        {
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
        }   
    #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
        /* Close add to and processing screen */
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS);
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
        break;
        
    case SRV_PLST_CB_EVT_DELETE_FROM_FMGR: /*System notiry*/
        ret = mmi_medply_plstui_fmgr_delete_hdlr(ca_para_2);
        return ret;
        
    case SRV_PLST_CB_EVT_ACTIVE_LIST_INVALID:  /*Service notiry, do not clear cancel func ptr*/
        /*must set media_type before stop, other wise cause bug*/
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        mmi_medply_plst_clear_context_variables();
        break;
        
    case SRV_PLST_CB_EVT_DELETE_ACTIVE_MEDIA:   /*Service notiry, do not clear cancel func ptr*/
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
        mmi_medply_listui_popup_by_strid(STR_ID_MEDPLY_PLST_CANNOT_DELETE_ACTIVE, MMI_EVENT_FAILURE);        
        return MMI_FALSE;        
    
    case SRV_PLST_CB_EVT_MSDC_PLUG_IN: /*System notiry*/
        if (SRV_FMGR_CARD_DRV != ca_para_2)
        {
            /*if not card plugin, only check if need re-apply file*/
            mmi_medply_plstui_msdc_plug_in_hdlr(ca_para_2);
            break;
        }
        /* following treat only for SD card plug in */
        if (NULL != medply_listui_cancel_cb)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EXCUTE_CANCEL_FIRST);
            medply_listui_cancel_cb();
            medply_listui_cancel_cb = NULL;
        }

        if(mmi_medply_listui_is_main_menu_grp_created())
        {
            ret = mmi_medply_listui_library_reopen(MMI_TRUE);
            mmi_medply_listui_card_plug_in_hdlr();
            if (ret >= 0)
            {
                /*If open success, check if need re-apply file*/
                mmi_medply_plstui_msdc_plug_in_hdlr(ca_para_2);
            }            
        }
        else
        {
            ret = mmi_medply_listui_library_reopen(MMI_FALSE);
            if (ret < 0)
            {
                mmi_medply_listui_popup_error(ret);
                mmi_medply_listui_module_deinit_internal();    
            }
        }
    #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
        mmi_medply_listui_exit_edit_elbum();
    #endif /*#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__*/
        break;
        
    case SRV_PLST_CB_EVT_MSDC_PLUG_OUT:
        if (SRV_FMGR_CARD_DRV == ca_para_2)
        {
            if (NULL != medply_listui_cancel_cb)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EXCUTE_CANCEL_FIRST, __LINE__);
                medply_listui_cancel_cb();
                medply_listui_cancel_cb = NULL;
            }
            mmi_medply_listui_module_deinit_internal();
        }
        else
        {
            mmi_medply_plstui_msdc_plug_out_hdlr(ca_para_2);
        }
        break;

    case SRV_PLST_CB_EVT_MSDC_ENTRY_UNMOUNT: /*System notiry*/
        if (SRV_FMGR_CARD_DRV == ca_para_2)
        {
            if (NULL != medply_listui_cancel_cb)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EXCUTE_CANCEL_FIRST, __LINE__);
                medply_listui_cancel_cb();
                medply_listui_cancel_cb = NULL;
            }
            mmi_medply_listui_module_deinit_internal();
        }
        else
        {
            mmi_medply_plstui_entry_unmount_hdlr(ca_para_2);
        }
        break;

    case SRV_PLST_CB_EVT_USB_PLUG_IN:   /*System notiry*/
        if (NULL != medply_listui_cancel_cb)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EXCUTE_CANCEL_FIRST, __LINE__);
            medply_listui_cancel_cb();
            medply_listui_cancel_cb = NULL;
        }
        mmi_medply_listui_module_deinit_internal();
        break;

    case SRV_PLST_CB_EVT_PRE_FORMAT:    /*System notiry*/
        mmi_medply_listui_module_deinit_internal();
        break;
        
    case SRV_PLST_CB_EVT_MSDC_EXIT_UNMOUNT:
    case SRV_PLST_CB_EVT_USB_PLUG_OUT:
    default:
        break;
    }
    return MMI_TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_event_callback_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_plst_event_callback_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EVENT_CALLBACK_HDLR);
    mmi_medply_display_popup_for_all_file_fail();
    return 0;
}


#define __LISTUI_INIT_UPDATE
/*****************************************************************************
* FUNCTION
*  mmi_medply_listui_module_init_internal
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL 
*****************************************************************************/
static S32 mmi_medply_listui_module_init_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_create_struct create_struct;
    UI_character_type      path[MEDPLY_MAX_PATH_LEN];
    void* adm_service_p = NULL;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_listui_cntx_p, 0, sizeof(mmi_medply_listui_context_struct));
    
    /*allocate memory*/
    MMI_ASSERT(g_medply.medply_adm_id_p != NULL);
    adm_service_p = kal_adm_alloc(g_medply.medply_adm_id_p,MEDPLY_PLST_DB_APP_MEM_SIZE);
    MMI_ASSERT(adm_service_p != NULL);
    g_listui_cntx_p->srv_cntx.mem_ptr = kal_adm_create(adm_service_p, MEDPLY_PLST_DB_APP_MEM_SIZE, NULL, KAL_FALSE);
    ASSERT(g_listui_cntx_p->srv_cntx.mem_ptr != NULL);

    /*prepare context*/
    ASSERT(MEDPLY_PLST_DB_APP_MEM_SIZE >= SRV_PLST_MIN_MEM_SIZE);
    g_listui_cntx_p->srv_cntx.mem_size = SRV_PLST_MIN_MEM_SIZE;    
    g_listui_cntx_p->srv_cntx.srv_hdlr = 0;
    g_listui_cntx_p->srv_cntx.max_item_support = -1;
    g_listui_cntx_p->srv_cntx.user_date = NULL;
    g_listui_cntx_p->view_stack.curr_ptr = -1; 
    g_listui_cntx_p->list_info.flag = 0;
#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
    g_listui_cntx_p->tilt_handle = -1;
#endif

    medply_listui_cancel_cb = NULL;

    /*initial create structure*/
    create_struct.max_item_support = g_listui_cntx_p->srv_cntx.max_item_support;
    create_struct.mem_ptr = g_listui_cntx_p->srv_cntx.mem_ptr;
    create_struct.mem_size = g_listui_cntx_p->srv_cntx.mem_size;
    create_struct.db_mem_size = SRV_PLST_MIN_MEM_SQLITE;

    kal_wsprintf(path, "%w", MMI_MEDPLY_LISTUI_FILENAME);
        
    g_listui_cntx_p->srv_cntx.srv_hdlr = 
        srv_plst_create(&ret, g_listui_cntx_p->srv_cntx.user_date, mmi_medply_listui_listsrv_callback, &create_struct);
    if (g_listui_cntx_p->srv_cntx.srv_hdlr != NULL)
    {
        ASSERT(ret >= SRV_PLST_OK);
        g_listui_cntx_p->srv_cntx.state_flag |= MMI_MEDPLY_LISTUI_HAS_SRV_CREATE;
        mmi_medply_listui_library_config();
    }
    else
    {
        mmi_medply_listui_popup_error(ret);
        return ret;
    }

    ret = srv_plst_library_open(g_listui_cntx_p->srv_cntx.srv_hdlr, path, SRV_PLST_OPEN_ONLY);
    if (ret >= SRV_PLST_ASYNC)
    {
        ASSERT(0);
    }
    else if (ret < SRV_PLST_OK)
    {
        //mmi_medply_listui_library_open_fail(ret);
    }
    else /*Open library successed*/
    {
        g_listui_cntx_p->srv_cntx.state_flag |= MMI_MEDPLY_LISTUI_HAS_SRV_OPEN;
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_module_deinit_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
static void mmi_medply_listui_module_deinit_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_MODULE_DEINIT_INTERNAL);
    
    mmi_medply_del_all_app_screen();
    mmi_frm_group_close(GRP_ID_MEDPLY_FTE);

    mmi_meply_plst_reset_all();
    mmi_medply_plst_module_deinit();
    mmi_medply_stop_playing();
    mmi_medply_asm_delete();
    mmi_medply_plst_clear_context_variables();
}


extern S32 mmi_medply_plst_init_for_extapp(void);
/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_init_for_extapp
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL 
*****************************************************************************/
extern S32 mmi_medply_plst_init_for_extapp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_create_struct create_struct;
    UI_character_type      path[MEDPLY_MAX_PATH_LEN];
    void* adm_service_p = NULL;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_listui_cntx_p, 0, sizeof(mmi_medply_listui_context_struct));
    
    /*allocate memory*/
    MMI_ASSERT(g_medply.medply_adm_id_p != NULL);
    adm_service_p = kal_adm_alloc(g_medply.medply_adm_id_p,MEDPLY_PLST_DB_APP_MEM_SIZE);
    MMI_ASSERT(adm_service_p != NULL);
    g_listui_cntx_p->srv_cntx.mem_ptr = kal_adm_create(adm_service_p, MEDPLY_PLST_DB_APP_MEM_SIZE, NULL, KAL_FALSE);
    ASSERT(g_listui_cntx_p->srv_cntx.mem_ptr != NULL);

    /*prepare context*/
    ASSERT(MEDPLY_PLST_DB_APP_MEM_SIZE >= SRV_PLST_MIN_MEM_SIZE);
    g_listui_cntx_p->srv_cntx.mem_size = SRV_PLST_MIN_MEM_SIZE;
    g_listui_cntx_p->srv_cntx.srv_hdlr = 0;
    g_listui_cntx_p->srv_cntx.max_item_support = -1;
    g_listui_cntx_p->srv_cntx.user_date = NULL;
    g_listui_cntx_p->view_stack.curr_ptr = -1; 
    g_listui_cntx_p->list_info.flag = 0;
#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
        g_listui_cntx_p->tilt_handle = -1;
#endif

    /*initial create structure*/
    create_struct.max_item_support = g_listui_cntx_p->srv_cntx.max_item_support;
    create_struct.mem_ptr = g_listui_cntx_p->srv_cntx.mem_ptr;
    create_struct.mem_size = g_listui_cntx_p->srv_cntx.mem_size;
    create_struct.db_mem_size = SRV_PLST_MIN_MEM_SQLITE;

    kal_wsprintf(path, "%w", MMI_MEDPLY_LISTUI_FILENAME);
        
    g_listui_cntx_p->srv_cntx.srv_hdlr = 
        srv_plst_create(&ret, g_listui_cntx_p->srv_cntx.user_date, mmi_medply_listui_listsrv_callback, &create_struct);
    if (g_listui_cntx_p->srv_cntx.srv_hdlr != NULL)
    {
        ASSERT(ret >= SRV_PLST_OK);
        g_listui_cntx_p->srv_cntx.state_flag |= MMI_MEDPLY_LISTUI_HAS_SRV_CREATE;
        mmi_medply_listui_library_config();
    }
    else
    {
        /*should not popup error*/
        /*mmi_medply_listui_popup_error(ret);*/
        return ret;
    }

    ret = srv_plst_library_open(g_listui_cntx_p->srv_cntx.srv_hdlr, path, SRV_PLST_OPEN_ONLY);
    if (ret >= SRV_PLST_ASYNC)
    {
        ASSERT(0);
    }
    else if (ret < SRV_PLST_OK)
    {
        return ret;
    }
    else /*Open library successed*/
    {
        g_listui_cntx_p->srv_cntx.state_flag |= MMI_MEDPLY_LISTUI_HAS_SRV_OPEN;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_library_config
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
extern MMI_BOOL mmi_medply_listui_allow_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_listui_cntx_p->srv_cntx.state_flag & MMI_MEDPLY_LISTUI_HAS_SRV_OPEN)
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
 *  mmi_medply_listui_library_config
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_library_config(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  shuffle;
    U8  repeat;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->srv_cntx.def_list_set = 0
                        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
                          | SRV_PLST_DEF_RECENTLY_PLST
                          | SRV_PLST_DEF_MY_FAVOURITE  
                          | SRV_PLST_DEF_MOST_PLST 
                          //| SRV_PLST_DEF_ON_THE_FLY;
                        #endif /* __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__ */
                          ;
    srv_plst_default_playlist_configure(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                        g_listui_cntx_p->srv_cntx.def_list_set);

    srv_plst_config_set_plst_order(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                   SRV_PLST_PLST_DEFAULT_SHOW_FIRST);

    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_SHUFFULE, 
                                       (void*)&shuffle);
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_REPEAT, 
                                   (void*)&repeat);
    srv_plst_config_shuffle(g_listui_cntx_p->srv_cntx.srv_hdlr, (srv_plst_shuffle_enum)shuffle);
    srv_plst_config_repeat(g_listui_cntx_p->srv_cntx.srv_hdlr, (srv_plst_repeat_enum)repeat);
    // set not store automatic
    srv_plst_config_info(g_listui_cntx_p->srv_cntx.srv_hdlr, SRV_PLST_CONFIG_PLAY_INFO, SRV_PLST_PLAY_INFO_STORE_MANUAL);
    
    g_listui_cntx_p->srv_cntx.state_flag |= MMI_MEDPLY_LISTUI_HAS_SRV_CONFIG;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_library_open_fail
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
extern void mmi_medply_listui_library_open_fail(S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error = SRV_PLST_RET_ERR_DB_NOT_FOUND;
    switch (error)
    {
    case SRV_PLST_RET_ERR_DB_CRASH:
        /*DB broken , need create a new one*/
        mmi_medply_listui_library_open_new_ask();
        break;
    case SRV_PLST_RET_ERR_DB_NOT_FOUND:
        /*No DB, need create a new one*/
        g_is_auto = MMI_TRUE;
        mmi_medply_listui_library_open_new();
        break;
    default:
        mmi_medply_listui_popup_error(error);
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_library_open_new_ask_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_library_open_new_ask_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                g_is_auto = MMI_TRUE;
                mmi_medply_listui_library_open_new();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_library_open_new_ask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_library_open_new_ask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_MEDPLY_FTE;
    confirm_arg.callback = mmi_medply_listui_library_open_new_ask_cnf_callback;

    mmi_confirm_display((WCHAR*)L"Database has crashed, Create new ?",
                        MMI_EVENT_QUERY,
                        &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_library_open_new
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_library_open_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type   path[MEDPLY_MAX_PATH_LEN];
    MMI_BOOL entry_ret;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_LIBRARY_OPEN_NEW, g_is_auto);

    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE, SCR_ID_MEDPLY_LISTUI_OPENING, 
                                   mmi_medply_listui_exit_open_wait_screen,
                                   mmi_medply_listui_library_open_new, MMI_FRM_UNKNOW_SCRN);
 
    if (!entry_ret)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_LIBRARY_OPEN_NEW_FAIL, g_is_auto);
        return;
    }

    mmi_medply_listui_entry_open_wait_screen();

    g_listui_cntx_p->srv_cntx.state_flag &= ~MMI_MEDPLY_LISTUI_HAS_SRV_OPEN;
    kal_wsprintf(path, "%w", MMI_MEDPLY_LISTUI_FILENAME);
    if(g_is_auto)
    {
        ret = srv_plst_library_open(g_listui_cntx_p->srv_cntx.srv_hdlr, path, SRV_PLST_OPEN_AUTO);
    }
    else
    {
        ret = srv_plst_library_open(g_listui_cntx_p->srv_cntx.srv_hdlr, path, SRV_PLST_OPEN_NEW);
    }
    ASSERT(ret >= SRV_PLST_ASYNC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_exit_open_wait_screen
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_exit_open_wait_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_listui_cntx_p->srv_cntx.state_flag & MMI_MEDPLY_LISTUI_HAS_SRV_OPEN_CB))
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE, SCR_ID_MEDPLY_LISTUI_OPENING);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_open_fail_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_medply_listui_open_fail_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_LIBRARY_OPEN_FAIL_PROC);
    switch(param->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            mmi_medply_listui_module_deinit_internal();
            break;
        }
        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_open_wait_screen
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_open_wait_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_OPEN_WAIT_SCREEN);

    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE, 
                                SCR_ID_MEDPLY_LISTUI_OPENING, 
                                mmi_medply_listui_opening_delete_callback);
    
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        0,
        0,
        (PU8)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        guiBuffer);   

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_delete_callback
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_opening_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_OPEN_DELETE_CALLBACK);
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        if (!(g_listui_cntx_p->srv_cntx.state_flag & MMI_MEDPLY_LISTUI_HAS_SRV_OPEN))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_HAVENOT_OPEN);
            srv_plst_library_stop_open(g_listui_cntx_p->srv_cntx.srv_hdlr);
            mmi_medply_listui_module_deinit_internal();
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_library_open_new_cb
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_library_open_new_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->srv_cntx.state_flag |= MMI_MEDPLY_LISTUI_HAS_SRV_OPEN;
    mmi_medply_listui_entry_refresh_lib();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_library_reopen
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_library_reopen(MMI_BOOL is_auto)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type      path[MEDPLY_MAX_PATH_LEN];
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SRV_LIBRARY_OPEN, is_auto);
    kal_wsprintf(path, "%w", MMI_MEDPLY_LISTUI_FILENAME);

    g_is_auto = is_auto;
    
    ret = srv_plst_library_open(g_listui_cntx_p->srv_cntx.srv_hdlr, path, SRV_PLST_OPEN_AFTER_MEDIA_CHANGE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SRV_OPEN_TYPE3, ret);
    if (ret < SRV_PLST_OK)
    {
        if (g_is_auto)
        {
            mmi_medply_listui_library_open_new();
        }        
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_refresh_lib
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_listui_entry_refresh_lib(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_REFRESH_LIB);
    
    /*make sure library has opened before update*/
    ASSERT(g_listui_cntx_p->srv_cntx.state_flag & MMI_MEDPLY_LISTUI_HAS_SRV_OPEN);

    /* Enter refresh screen from main menu */
    if(mmi_frm_group_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU))
    {
        group_id = GRP_ID_MEDPLY_FTE_SUB_MENU;
    }
    else
    {
        group_id = GRP_ID_MEDPLY_FTE;
    }

    //null entry modify
    entry_ret = mmi_frm_scrn_enter(group_id,
                                   SCR_ID_MEDPLY_LISTUI_WAITING,
                                   mmi_medply_listui_exit_refresh_lib,
                                   mmi_medply_listui_entry_refresh_lib,
                                   MMI_FRM_FG_ONLY_SCRN);

    if (!entry_ret)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_REFRESH_LIB_FAIL, entry_ret);
        return;
    }

    mmi_medply_listui_util_set_cache_mem(LCD_WIDTH * LCD_HEIGHT * 2);
    ret = srv_plst_library_update(g_listui_cntx_p->srv_cntx.srv_hdlr);

    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_util_clear_cache_mem();
        mmi_medply_listui_popup_error(ret);
    }
    else if (ret >= SRV_PLST_ASYNC)
    {
        g_listui_cntx_p->list_info.flag |= MMI_MEDPLY_LISTUI_IS_REFRESH;
        mmi_medply_listui_show_wait_scr();
        SetRightSoftkeyFunction(mmi_medply_listui_refresh_lib_cancel, KEY_EVENT_UP);
    }
    else
    {
        ASSERT(0);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_exit_refresh_lib
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_exit_refresh_lib(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_interrupt = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_REFRESH)
    {
        srv_plst_library_stop_udpate(g_listui_cntx_p->srv_cntx.srv_hdlr);
        g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_REFRESH;
        is_interrupt = MMI_TRUE;
    }
    mmi_medply_listui_util_clear_cache_mem();

    if (is_interrupt)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EXIT_REFRESH_LIB);
        if (!mmi_medply_listui_is_goback_inendkey())
        {
            if(!mmi_medply_listui_is_main_menu_grp_created())
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_MAIN_MENU);
                mmi_medply_entry_main_menu_scr();
            }
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_refresh_lib_cancel
 * DESCRIPTION
 *
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_refresh_lib_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_REFRESH_LIB_CANCEL);
    
    if (!(g_listui_cntx_p->list_info.flag&MMI_MEDPLY_LISTUI_IS_REFRESH))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFRESH_LIB_FAIL);
        return;
    }
    
    ret = srv_plst_library_stop_udpate(g_listui_cntx_p->srv_cntx.srv_hdlr);
    g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_REFRESH;
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        if(mmi_frm_group_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU))
        {
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
        }
        else
        {
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE, SCR_ID_MEDPLY_LISTUI_WAITING);
        }
    }
    else
    {
        if(!mmi_medply_listui_is_main_menu_grp_created())
        {
            mmi_medply_entry_main_menu_scr();
        }
        else
        {
            mmi_frm_scrn_close_active_id();
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_report
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_report(U32 data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_popup_property_init(&popup_arg);
    popup_arg.parent_id = GRP_ID_MEDPLY_FTE;
    popup_arg.callback = mmi_medply_listui_report_popup_proc;

    mmi_popup_display((WCHAR*)get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, &popup_arg);
    mmi_frm_ui_force_update_now();
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_send_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_medply_listui_report_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_REPORT_POPUP_PROC);
    switch(param->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_FTE))
            {
                if(!mmi_medply_listui_is_main_menu_grp_created())
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_MAIN_MENU);
                    mmi_medply_entry_main_menu_scr();
                }
            }
            break;
        }
        default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_delete_req_cnf_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_reset_lib_req_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_medply_listui_reset_lib();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_reset_lib_req
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_reset_lib_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Display confirm */
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_MEDPLY_FTE_SUB_MENU;
    confirm_arg.callback = mmi_medply_listui_reset_lib_req_cnf_callback;

    mmi_confirm_display((WCHAR*)get_string(STR_ID_MEDPLY_RESET_CONFIRM),
                        MMI_EVENT_QUERY,
                        &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_reset_lib
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_listui_reset_lib(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_RESET_LIB);

    /* Stop current playing */ 
    g_medply.media_type = MEDPLY_TYPE_NONE;
    mmi_medply_stop_playing();        
    mmi_medply_plst_clear_context_variables();

    /*close lib*/
    ret = srv_plst_library_close(g_listui_cntx_p->srv_cntx.srv_hdlr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SRV_LIBRARY_CLOSE, ret);

    /*Open new*/
    g_is_auto = MMI_FALSE;
    mmi_medply_listui_library_open_new();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_add_from_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_add_from_folder(MMI_BOOL isAudio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->list_info.launch_scr_id = g_listui_cntx_p->list_info.list_scr_id;
    
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    if (isAudio)
    {
        FMGR_FILTER_SET_AUDIO(&filter);
        #ifdef __VM_CODEC_SUPPORT__
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
        #endif
        #if defined(__VORBIS_DECODE__) && defined(__VORBIS_DECODE_SLIM__)
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_OGG);
        #endif
    }
    else
    {
        FMGR_FILTER_SET_VIDEO(&filter);
    #ifdef __MMI_VIDEO_STREAM__
        FMGR_FILTER_SET_STREAM(&filter);
    #endif
    }    
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif

    g_listui_cntx_p->list_info.child_id = cui_file_selector_create(
                                                GRP_ID_MEDPLY_FTE_SUB_MENU,
                                                (WCHAR*) L"root",
                                                &filter,
                                                CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
                                                CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);

    if (g_listui_cntx_p->list_info.child_id > 0)
    {
        /*cui_file_selector_set_title(g_listui_cntx_p->list_info.child_id, 0, IMG_ID_MEDPLY_ICON);*/    
        cui_file_selector_set_userdata(g_listui_cntx_p->list_info.child_id, (U32) LISTUI_FMGR_ADD_FILES);        
        cui_file_selector_run(g_listui_cntx_p->list_info.child_id);
    }
    else
    {   
        mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_NOT_AVAILABLE),
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        mmi_frm_ui_force_update_now();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_add_from_folder_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_add_from_folder_begin(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;    
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_listui_cntx_p->srv_cntx.state_flag & MMI_MEDPLY_LISTUI_HAS_SRV_OPEN);

    //null entry modify
    entry_ret = mmi_frm_scrn_enter(
                            GRP_ID_MEDPLY_FTE_SUB_MENU, 
                            SCR_ID_MEDPLY_LISTUI_WAITING,  
                            mmi_medply_listui_add_from_folder_exit, 
                            (FuncPtr)mmi_medply_listui_add_from_folder_begin, MMI_FRM_FG_ONLY_SCRN);

    if (!entry_ret)
    {
        return;
    }

    mmi_medply_listui_util_set_cache_mem(LCD_WIDTH * LCD_HEIGHT * 2);
    ret = srv_plst_library_add(g_listui_cntx_p->srv_cntx.srv_hdlr, path);

    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_util_clear_cache_mem();
        mmi_medply_listui_popup_error(ret);
    }
    else if (ret >= SRV_PLST_ASYNC)
    {
        g_listui_cntx_p->list_info.flag |= MMI_MEDPLY_LISTUI_IS_REFRESH;
        mmi_medply_listui_show_wait_scr();
        SetRightSoftkeyFunction(mmi_medply_listui_refresh_lib_cancel, KEY_EVENT_UP);
    }
    else
    {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
    }

    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, g_listui_cntx_p->list_info.launch_scr_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_add_from_folder_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_add_from_folder_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_REFRESH)
    {
        srv_plst_library_stop_add(g_listui_cntx_p->srv_cntx.srv_hdlr);
        g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_REFRESH;
    }
    mmi_medply_listui_util_clear_cache_mem();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medlpy_listui_add_from_folder_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medlpy_listui_add_from_folder_hdlr(cui_file_selector_result_event_struct *file_select)
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
                                g_listui_cntx_p->list_info.child_id,
                                NULL,
                                (WCHAR *) temp_path,
                                (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
        
        
        mmi_medply_listui_add_from_folder_begin(temp_path);
        cui_file_selector_close(file_select->sender_id);
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
        g_listui_cntx_p->list_info.child_id = 0;
    }
    else
    {
        mmi_popup_display_simple((WCHAR*)GetString(srv_fmgr_fs_error_get_string(file_select->result)),
                                 (mmi_event_notify_enum) srv_fmgr_fs_error_get_popup_type(file_select->result),
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);

        cui_file_selector_close(file_select->sender_id);
        g_listui_cntx_p->list_info.child_id = 0;
        mmi_frm_ui_force_update_now();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medlpy_listui_fmgr_res_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_medlpy_listui_fmgr_res_handle(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(cui_file_selector_get_userdata(file_select->sender_id))
    {
    case LISTUI_FMGR_ADD_FILES:
        mmi_medlpy_listui_add_from_folder_hdlr(file_select);
        break;
#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
    case LISTUI_FMGR_EDIT_ALBUM:
        mmi_medply_listui_edit_album_hdlr(file_select);
        break;
#endif /* __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__ */
    default:
        break;    
    }
}

#define __LISTUI_SHOW_LIST
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_type_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
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

    mmi_medply_listui_type_open_list();
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_song_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
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

    //11/22
    if ((LIST_TYPE_PLST_SONG_LIST == g_listui_cntx_p->list_info.list_type) &&
        mmi_medply_shell_is_registered() &&
        (SRV_PLST_DEF_RECENTLY_PLST == g_listui_cntx_p->list_info.def_list_type ||
         SRV_PLST_DEF_MOST_PLST == g_listui_cntx_p->list_info.def_list_type))
    {
        mmi_medply_listui_entry_song_list_option();
    }
    else
    {
        mmi_medply_listui_file_play();
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_plst_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
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

    mmi_medply_listui_plst_open();
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_search_list_tap_callback(mmi_tap_type_enum tap_type,S32 index)
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

    switch(g_listui_cntx_p->list_info.list_type)
    {
    case LIST_TYPE_ALL_SONG_LIST:
    case LIST_TYPE_ALL_VIDEO_LIST:
    case LIST_TYPE_CATEGORY_SONG_LIST:
        mmi_medply_listui_file_play();
        break;
    case LIST_TYPE_PLST_SONG_LIST:
        //11/22
        if (mmi_medply_shell_is_registered() &&
           (SRV_PLST_DEF_RECENTLY_PLST == g_listui_cntx_p->list_info.def_list_type ||
            SRV_PLST_DEF_MOST_PLST == g_listui_cntx_p->list_info.def_list_type))
        {
            mmi_medply_listui_entry_search_option();
        }
        else
        {
            mmi_medply_listui_file_play();
        }
        break;

    case LIST_TYPE_ARTIST_LIST:
    case LIST_TYPE_ALBUM_LIST:
    case LIST_TYPE_GENRE_LIST:
    case LIST_TYPE_ARTIST_ALBUM_LIST:
        mmi_medply_listui_type_open_list();
        break;

    default:
        break;
    }
    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_list_disable_scrollbar
 * DESCRIPTION
 * .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static U32 mmi_medply_listui_common_list_disable_scrollbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    flag |= WGUI_LIST_MENU_DISABLE_SCROLLBAR_DRAG;
    
    return flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_all_song_list
 * DESCRIPTION
 * .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_entry_all_song_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_listui_prepare_all_songs(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                              LIST_TYPE_ALL_SONG_LIST,
                                              &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                &g_listui_cntx_p->list_info.total);
    
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_SONGS, NULL, 
                                   mmi_medply_listui_entry_all_song_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }
    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ALL_SONGS != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_ALL_SONG_LIST;  
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ALL_SONGS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_ALL_SONGS), 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                SCR_ID_MEDPLY_LISTUI_ALL_SONGS, 
                                mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }
    else if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_NEED_RESET_HL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_RESET_HIGHLIGHT);
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_SONGS);
        g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_NEED_RESET_HL;
    }
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total,
                                           g_listui_cntx_p->list_info.highlight,
                                           MMI_TRUE);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_song_list_tap_callback);
#endif

    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
	if(g_listui_cntx_p->list_info.total == 0)
	{
	    SetCenterSoftkeyFunction(mmi_medply_listui_entry_song_list_option, KEY_EVENT_UP);
            SetKeyHandler(mmi_medply_listui_entry_song_list_option, KEY_ENTER, KEY_EVENT_UP);
	}
	else
	{
	    SetCenterSoftkeyFunction(mmi_medply_listui_file_play, KEY_EVENT_UP);
            SetKeyHandler(mmi_medply_listui_file_play, KEY_ENTER, KEY_EVENT_UP);
	}        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

    SetLeftSoftkeyFunction(mmi_medply_listui_entry_song_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_all_video_list
 * DESCRIPTION
 *  apply picked file, fill global context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_entry_all_video_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_listui_prepare_all_videos(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                               LIST_TYPE_ALL_VIDEO_LIST,
                                               &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                &g_listui_cntx_p->list_info.total);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS, NULL, 
                                   mmi_medply_listui_entry_all_video_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }

    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_ALL_VIDEO_LIST;  
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_ALL_VIDEOS), 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS, 
                                mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }
    else if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_NEED_RESET_HL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_RESET_HIGHLIGHT);
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS);
        g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_NEED_RESET_HL;
    }
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total,
                                           g_listui_cntx_p->list_info.highlight,
                                           MMI_TRUE);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_song_list_tap_callback);
#endif
    
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        if(g_listui_cntx_p->list_info.total == 0)
	{
	    SetCenterSoftkeyFunction(mmi_medply_listui_entry_song_list_option, KEY_EVENT_UP);
            SetKeyHandler(mmi_medply_listui_entry_song_list_option, KEY_ENTER, KEY_EVENT_UP);
	}
	else
	{
	    SetCenterSoftkeyFunction(mmi_medply_listui_file_play, KEY_EVENT_UP);
            SetKeyHandler(mmi_medply_listui_file_play, KEY_ENTER, KEY_EVENT_UP);
	}        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    SetLeftSoftkeyFunction(mmi_medply_listui_entry_song_list_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

//Astro
static MMI_BOOL mmi_medply_input_url_done(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_input_url
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_listui_entry_input_url(void)
{
    memset(&g_listui_cntx_p->editor_cntx, 0, sizeof(mmi_medply_listui_editor_cntx_struct));
    g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_NEW_URL;
    g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_URL_LEN;
    g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_INPUT_URL;
    g_listui_cntx_p->editor_cntx.original_string_p = NULL;
    g_listui_cntx_p->editor_cntx.done_func = mmi_medply_input_url_done;
    mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                 (CHAR*)L"rtsp://", MMI_MEDPLY_MAX_URL_LEN);
    mmi_medply_listui_entry_editor();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_input_url_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_input_url_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2nicmp((CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer, (CHAR*)L"RTSP://", 7))
    {
        /* rtsp url. */
        /* TODO: call play rtsp API here, and entry player screen*/
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        mmi_medply_single_play_stream_from_rtsp_link(g_listui_cntx_p->editor_cntx.editor_buffer);
    #endif
        return MMI_TRUE;
    }

    /* invalid url. */
    mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_INVALID_URL), MMI_EVENT_ERROR, GRP_ID_MEDPLY_FTE, NULL);
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_artist_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_entry_artist_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_listui_prepare_all_artists(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                LIST_TYPE_ARTIST_LIST,
                                                &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                &g_listui_cntx_p->list_info.total);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    } 
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS, NULL, 
                                   mmi_medply_listui_entry_artist_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }

    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_ARTIST_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_ARTISTS), 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS, mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total,
                                           g_listui_cntx_p->list_info.highlight,
                                           MMI_FALSE);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_type_list_tap_callback);
#endif
    if (g_listui_cntx_p->list_info.total > 0)
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_entry_type_list_option, KEY_EVENT_UP);
    }

    if (g_listui_cntx_p->list_info.total > 0 && mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        SetCenterSoftkeyFunction(mmi_medply_listui_type_open_list, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_listui_type_open_list, KEY_ENTER, KEY_EVENT_UP);      
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_album_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_reg_motion(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
    srv_sensor_motion_direct_cfg_struct sensitive;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
    if (g_listui_cntx_p->tilt_handle < 0)
    {
        sensitive.angle_threshold = 30;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_START_LISTEN);
	//modify for sensor split
	/*
        g_listui_cntx_p->tilt_handle = mdi_motion_start_listen_tilt(
                                                MDI_MOTION_SENSITIVE_NORMAL, 
                                                MDI_MOTION_TILT_EVENT_AXIS, 
                                                mmi_medply_listui_tilt_hdlr, NULL);*/
	g_listui_cntx_p->tilt_handle = srv_sensor_start_listen
	      (SRV_SENSOR_MOTION_DIRECT, &sensitive, mmi_medply_listui_tilt_hdlr, NULL);
        g_listui_cntx_p->tilt_state = LISTUI_TILT_STATE_INIT;
    }    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_album_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_dereg_motion(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
    if(g_listui_cntx_p->tilt_handle >= 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_STOP_LISTEN);
        srv_sensor_stop_listen(g_listui_cntx_p->tilt_handle);
        g_listui_cntx_p->tilt_handle = -1 ;
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_album_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_entry_album_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_listui_prepare_all_albums(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                               LIST_TYPE_ALBUM_LIST,
                                               &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                &g_listui_cntx_p->list_info.total);

    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    } 
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS, NULL, 
                                   mmi_medply_listui_entry_album_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }

    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_ALBUM_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_ALBUMS), 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS, 
                                mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }

    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total,
                                           g_listui_cntx_p->list_info.highlight,
                                           MMI_FALSE);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_type_list_tap_callback);
#endif
    if (g_listui_cntx_p->list_info.total > 0)
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_entry_type_list_option, KEY_EVENT_UP);
    }

    if (g_listui_cntx_p->list_info.total > 0 && mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        SetCenterSoftkeyFunction(mmi_medply_listui_type_open_list, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_listui_type_open_list, KEY_ENTER, KEY_EVENT_UP);      
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_genre_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_entry_genre_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_listui_prepare_all_genres(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                               LIST_TYPE_GENRE_LIST,
                                               &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                &g_listui_cntx_p->list_info.total);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    } 
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_GENRES, NULL, 
                                   mmi_medply_listui_entry_genre_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }

    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ALL_GENRES != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_GENRE_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ALL_GENRES;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_GENRES), 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_GENRES, mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total,
                                           g_listui_cntx_p->list_info.highlight,
                                           MMI_FALSE);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_type_list_tap_callback);
#endif
    if (g_listui_cntx_p->list_info.total > 0)
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_entry_type_list_option, KEY_EVENT_UP);
    }

    if (g_listui_cntx_p->list_info.total > 0 && mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        SetCenterSoftkeyFunction(mmi_medply_listui_type_open_list, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_listui_type_open_list, KEY_ENTER, KEY_EVENT_UP);      
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_plst_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_entry_plst_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_listui_prepare_all_plsts(g_listui_cntx_p->srv_cntx.srv_hdlr, LIST_TYPE_PLST_LIST,&g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                &g_listui_cntx_p->list_info.total);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_PLSTS, NULL, 
                                   mmi_medply_listui_entry_plst_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }
    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ALL_PLSTS!= g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_PLST_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ALL_PLSTS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_PLAYLISTS), 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_PLSTS, mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }

    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total,
                                           g_listui_cntx_p->list_info.highlight,
                                           MMI_TRUE);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_plst_list_tap_callback);
#endif
    SetLeftSoftkeyFunction(mmi_medply_listui_entry_plst_list_option, KEY_EVENT_UP);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
	if(g_listui_cntx_p->list_info.total == 0)
	{
            SetCenterSoftkeyFunction(mmi_medply_listui_entry_plst_list_option, KEY_EVENT_UP);
            SetKeyHandler(mmi_medply_listui_entry_plst_list_option, KEY_ENTER, KEY_EVENT_UP);
	}
	else
	{
	    SetCenterSoftkeyFunction(mmi_medply_listui_plst_open, KEY_EVENT_UP);
            SetKeyHandler(mmi_medply_listui_plst_open, KEY_ENTER, KEY_EVENT_UP);
	}        
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_type_open_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_type_open_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (LIST_TYPE_ARTIST_LIST == g_listui_cntx_p->list_info.list_type)
    {
        /*prepare artist name for title*/
        mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                         g_listui_cntx_p->list_info.highlight,
                                         g_listui_title_l1);    
        /*entry artist-> album list*/
        g_listui_cntx_p->list_info.artist_idx = g_listui_cntx_p->list_info.highlight;
        srv_plst_media_get_id(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                              g_listui_cntx_p->list_info.artist_idx,
                              &g_listui_cntx_p->list_info.artist_id);
        mmi_medply_listui_entry_artist_album_list();
    }
    else
    {
        if (LIST_TYPE_ARTIST_ALBUM_LIST == g_listui_cntx_p->list_info.list_type)
        {
            if ((0 == g_listui_cntx_p->list_info.highlight) &&
                (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)))
            {
                mmi_ucs2ncpy((CHAR*) g_listui_title_l2, 
                             (const CHAR*)g_listui_title_l1, 
                             MEDPLY_MAX_FILE_LEN - 1);

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_TYPE_OPEN_LIST);
                mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                     &g_listui_cntx_p->view_stack);
                g_listui_cntx_p->list_info.highlight = g_listui_cntx_p->list_info.artist_idx;
            }
            else
            {
                /* In search list, no need to higlight - 1 */
                if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
                {
                    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                     g_listui_cntx_p->list_info.highlight,
                                                     g_listui_title_l2);
                }
                else
                {
				    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                     g_listui_cntx_p->list_info.highlight - 1,
                                                     g_listui_title_l2);
                }
            }            
        }
        else
        {
            mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                         g_listui_cntx_p->list_info.highlight,
                                         g_listui_title_l2);
        }        
        mmi_medply_listui_entry_category_song_list();
    }
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
    }
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_artist_album_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_artist_album_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ret = mmi_medply_listui_prepare_artist_albums(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                  LIST_TYPE_ARTIST_ALBUM_LIST,
                                                  &g_listui_cntx_p->view_stack,
                                                  g_listui_cntx_p->list_info.artist_id);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                &g_listui_cntx_p->list_info.total);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS, NULL, 
                                   mmi_medply_listui_entry_artist_album_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }

    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_ARTIST_ALBUM_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)g_listui_title_l1, 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS, mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_artist_album_highlight_hdlr);

    if (g_listui_cntx_p->list_info.total > 0)
    {
        
        mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                               g_listui_cntx_p->list_info.total + 1,
                                               g_listui_cntx_p->list_info.highlight,
                                               MMI_FALSE);
    }
    else
    {
        mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                               0,
                                               g_listui_cntx_p->list_info.highlight,
                                               MMI_FALSE);
    }
    

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_type_list_tap_callback);
#endif
    if (g_listui_cntx_p->list_info.total > 0)
    {
		if (0 == g_listui_cntx_p->list_info.highlight)
        {
		    SetLeftSoftkeyFunction(mmi_medply_listui_type_open_list, KEY_EVENT_UP);
		}
		else
		{
            SetLeftSoftkeyFunction(mmi_medply_listui_entry_type_list_option, KEY_EVENT_UP);
		}        
    }    
    if (g_listui_cntx_p->list_info.total > 0 && mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
	SetCenterSoftkeyFunction(mmi_medply_listui_type_open_list, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_listui_type_open_list, KEY_ENTER, KEY_EVENT_UP);     
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_album_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_category_song_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 index = g_listui_cntx_p->list_info.highlight;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (LIST_TYPE_ARTIST_ALBUM_LIST == 
        g_listui_cntx_p->view_stack.list_type[g_listui_cntx_p->view_stack.curr_ptr])
    {
        /* In search list, don't need to do index - 1 for "All songs"*/
        if (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_CATEGORY_SONG_LIST);
            index--;
        }
    }
    if (LIST_TYPE_ARTIST_LIST == 
		g_listui_cntx_p->view_stack.list_type[g_listui_cntx_p->view_stack.curr_ptr])
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREPARE_SONGS_BY_ID);
	    ret = mmi_medply_listui_prepare_songs_by_id(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                              LIST_TYPE_CATEGORY_SONG_LIST,
                                              &g_listui_cntx_p->view_stack,
                                              g_listui_cntx_p->list_info.artist_id);
	}
    else
    {
        ret = mmi_medply_listui_prepare_songs(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                              LIST_TYPE_CATEGORY_SONG_LIST,
                                              &g_listui_cntx_p->view_stack,
                                              index);
    }
    
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                &g_listui_cntx_p->list_info.total);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS, NULL, 
                                   mmi_medply_listui_entry_category_song_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }
    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_SONGS != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_CATEGORY_SONG_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_SONGS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)g_listui_title_l2, 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS, mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }
    else if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_NEED_RESET_HL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_RESET_HIGHLIGHT);
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS);
        g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_NEED_RESET_HL;
    }
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total,
                                           g_listui_cntx_p->list_info.highlight,
                                           MMI_FALSE);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_song_list_tap_callback);
#endif
    if (g_listui_cntx_p->list_info.total > 0)
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_entry_song_list_option, KEY_EVENT_UP);
    }
    if (g_listui_cntx_p->list_info.total > 0 && mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
	SetCenterSoftkeyFunction(mmi_medply_listui_file_play, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_listui_file_play, KEY_ENTER, KEY_EVENT_UP);      
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_plst_song_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_plst_song_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret, lsk_flag;
    MMI_BOOL is_default = MMI_FALSE;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*check if entry kuro list*/
    if (SRV_PLST_DEF_ALL_KURO_LIST == g_listui_cntx_p->list_info.def_list_type ||
        SRV_PLST_DEF_RECENTLY_PLST == g_listui_cntx_p->list_info.def_list_type ||
        SRV_PLST_DEF_MOST_PLST == g_listui_cntx_p->list_info.def_list_type     ||
        SRV_PLST_DEF_ON_THE_FLY == g_listui_cntx_p->list_info.def_list_type)
    {
        is_default = MMI_TRUE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_PLST_SONG_LIST, 
                         g_listui_cntx_p->list_info.def_list_type);
    }
    
    ret = mmi_medply_listui_prepare_songs(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                          LIST_TYPE_PLST_SONG_LIST,
                                          &g_listui_cntx_p->view_stack,
                                          g_listui_cntx_p->list_info.highlight);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                &g_listui_cntx_p->list_info.total);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS, NULL, 
                                   mmi_medply_listui_entry_plst_song_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }
    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_SONGS != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_PLST_SONG_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_SONGS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)g_listui_title_l2, 
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS, mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }
    else if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_NEED_RESET_HL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_RESET_HIGHLIGHT);
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS);
        g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_NEED_RESET_HL;
    }
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    lsk_flag = is_default ? MMI_FALSE : MMI_TRUE; 
    
    mmi_medply_listui_show_common_list_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total,
                                           g_listui_cntx_p->list_info.highlight,
                                           lsk_flag);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_medply_listui_song_list_tap_callback);
#endif
    if ((!is_default) || (g_listui_cntx_p->list_info.total > 0))
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_entry_song_list_option, KEY_EVENT_UP);
    }       
    if (g_listui_cntx_p->list_info.total > 0 && mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        SetCenterSoftkeyFunction(mmi_medply_listui_file_play, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_listui_file_play, KEY_ENTER, KEY_EVENT_UP);      
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    else if(g_listui_cntx_p->list_info.total == 0 && mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        SetCenterSoftkeyFunction(mmi_medply_listui_multi_add_begin, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_listui_multi_add_begin, KEY_ENTER, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    else
    {
        /* There could be playlist with songs or with 0 songs no other case */
        MMI_ASSERT(0);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_song_list_scr
 * DESCRIPTION
 *  Show file list screen(all songs/videos, artist/album/gen view).
 *  LSK:option. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_common_list_scr(UI_string_type title, S32 total, S32 highlight, MMI_BOOL lsk_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8*  guiBuffer;
    U16  str_lsk;
    U16  img_lsk;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    
    if (total == 0)
    {
        if (lsk_flag)
        {
            str_lsk = STR_GLOBAL_OPTIONS;
            img_lsk = IMG_GLOBAL_OPTIONS;
        }
        else
        {
            str_lsk = 0;
            img_lsk = 0;
        }
        
        ShowCategory353Screen(
            (U8*)title,
            GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
            str_lsk,
            img_lsk,
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
        wgui_cat_register_get_flags_callback(mmi_medply_listui_common_list_disable_scrollbar);   
        ShowCategory183Screen(
            title, 
            get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
            get_string(STR_GLOBAL_OPTIONS),
            get_image(IMG_GLOBAL_OPTIONS),              
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK), 
            total,
            mmi_medply_listui_get_common_list_item,
            mmi_medply_listui_get_common_list_hint,
            highlight,
            MMI_FALSE,
            NULL,
            guiBuffer);
        wgui_title_set_shortcut_count(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_highlight_hdlr
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_common_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->list_info.highlight = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_artist_album_highlight_hdlr
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_artist_album_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
        SetLeftSoftkeyFunction(mmi_medply_listui_type_open_list, KEY_EVENT_UP);
	if (mmi_frm_kbd_is_key_supported(KEY_CSK))
        {
		SetCenterSoftkeyFunction(mmi_medply_listui_type_open_list, KEY_EVENT_UP);
                SetKeyHandler(mmi_medply_listui_type_open_list, KEY_ENTER, KEY_EVENT_UP);
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_medply_listui_entry_type_list_option, KEY_EVENT_UP);
	if (mmi_frm_kbd_is_key_supported(KEY_CSK))
        {
	    SetCenterSoftkeyFunction(mmi_medply_listui_type_open_list, KEY_EVENT_UP);
            SetKeyHandler(mmi_medply_listui_type_open_list, KEY_ENTER, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
    }
    g_listui_cntx_p->list_info.highlight = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_curr_item_title
 * DESCRIPTION
 *  Dynamic list call back to get item title.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
pBOOL mmi_medply_listui_get_common_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U16 img_id;
    U16 format;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_listui_cntx_p->list_info.list_type)
    {
    case LIST_TYPE_ALL_SONG_LIST:
    case LIST_TYPE_PLST_SONG_LIST:
    case LIST_TYPE_CATEGORY_SONG_LIST:
        ret = mmi_medply_listui_get_list_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr,item_index,str_buff);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
            break;
        }
        ret = mmi_medply_listui_get_audio_format(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                 item_index, &format);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_FORMAT, ret);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
            break;
        }
        img_id = mmi_medply_util_get_file_icon(format);
        *img_buff_p = (PU8)GetImage(img_id);
        break;
        
    case LIST_TYPE_ALL_VIDEO_LIST:
        ret = mmi_medply_listui_get_list_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr,item_index,str_buff);
        if (ret < SRV_PLST_OK)
        {
           MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
           break;
        }
        ret = mmi_medply_listui_get_video_format(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                 item_index, &format);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_FORMAT, ret);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
            break;
        }
        img_id = mmi_medply_util_get_file_icon(format);
        *img_buff_p = (PU8)GetImage(img_id);
        break;

    case LIST_TYPE_ACTIVE_LIST:
        ret = mmi_medply_listui_get_list_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr,item_index,str_buff);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
           break;
        }
        /*check current list is video or audio*/
        if (mmi_medply_plst_is_video_list())
        {
            ret = mmi_medply_listui_get_video_format(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                    item_index, &format);
        }
        else
        {
            ret = mmi_medply_listui_get_audio_format(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                    item_index, &format);
        }
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_FORMAT, ret);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
            break;
        }
        img_id = mmi_medply_util_get_file_icon(format);
        *img_buff_p = (PU8)GetImage(img_id);
        break;
        
    case LIST_TYPE_ARTIST_LIST:
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_PLST_DETAILS_ARTIST);
        ret = mmi_medply_listui_get_list_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr, item_index,str_buff);
        if (ret < SRV_PLST_OK)
        {
           MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
           mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
           break;
        }        
        break;
        
    case LIST_TYPE_ARTIST_ALBUM_LIST:
        /*index will add 1 for the first item is 'ALL'*/
        if (0 == item_index)
        {
            mmi_ucs2ncpy((CHAR*)str_buff,(CHAR*)GetString(STR_ID_MEDPLY_ALL_SONGS), MEDPLY_MAX_ITEM_LEN - 1);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FTE_ALL_SONGS);
            
        }
        else
        {
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_PLST_DETAILS_ALBUM);
            item_index--;
            ret = mmi_medply_listui_get_list_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr, item_index,str_buff);
            if (ret < SRV_PLST_OK)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
                mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
                break;
            }
        }       
        break;
        
    case LIST_TYPE_ALBUM_LIST:
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_PLST_DETAILS_ALBUM);
        ret = mmi_medply_listui_get_list_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr, item_index,str_buff);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            break;
        }        
        break;
        
    case LIST_TYPE_GENRE_LIST:
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_PLST_DETAILS_GENRE);
        ret = mmi_medply_listui_get_list_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr, item_index,str_buff);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            break;
        }        
        break;
        
    case LIST_TYPE_PLST_LIST:
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_ICON);
        ret = mmi_medply_listui_get_plst_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr, item_index,str_buff);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            break;
        }
        break;
        
    case LIST_TYPE_ADDTO_PLST_LIST:
        if (0 == item_index)
        {
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_CREATE_ICON);
            mmi_ucs2ncpy((CHAR*)str_buff, (const CHAR*)GetString(STR_ID_MEDPLY_LISTMGR_OPT_NEW), MEDPLY_MAX_ITEM_LEN - 1);
        }
        else
        {
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_ICON);
            ret = mmi_medply_listui_get_plst_title_item(g_listui_cntx_p->srv_cntx.srv_hdlr, item_index - 1,str_buff);
            if (ret < SRV_PLST_OK)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_COMMON_LIST_ITEM_TITLE, ret);
                mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
                break;
            }
        }
        break;
        
    default:
        ASSERT(0); /*not support list type*/
        break;        
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_curr_item_title
 * DESCRIPTION
 *  Dynamic list call back to get item title.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_listui_get_common_list_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_listui_cntx_p->list_info.list_type)
    {
    case LIST_TYPE_ALL_SONG_LIST:
        ret = 0;
        break;
    case LIST_TYPE_ARTIST_LIST:
    case LIST_TYPE_ALBUM_LIST:
    case LIST_TYPE_GENRE_LIST:
    case LIST_TYPE_PLST_LIST:
        ret = 0;
        break;
    default:
        ret = 0; /*not support list type*/
        break;        
    }

    return ret;
}


// TODO: This API shall move to file manager
static mmi_ret fmgr_forward_sub_option_handler(cui_menu_event_struct *evt, U16 link_menu_id, const WCHAR* filepath, MMI_BOOL is_send)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 sub_parent;
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret = MMI_RET_ERR;
    switch(evt->evt_id)
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        if(GetChildMenuIDIndexByParentMenuID_Ext(evt->parent_menu_id, link_menu_id) >= 0)
        {
            /* check */
            if(is_send)
                g_listui_cntx_p->list_info.fwd_id = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR*)filepath);
            else
                g_listui_cntx_p->list_info.fwd_id  = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR*)filepath);

            if(g_listui_cntx_p->list_info.fwd_id  <= 0)
                cui_menu_set_item_hidden(evt->sender_id, link_menu_id, MMI_TRUE);
            else
            {
                cui_menu_set_item_hidden(evt->sender_id, link_menu_id, MMI_FALSE);
                cui_menu_set_non_leaf_item(evt->sender_id, link_menu_id, MMI_TRUE);
            }
            ret = MMI_RET_OK;
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        if(is_send)
            g_listui_cntx_p->list_info.fwd_id  = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR*)filepath);
        else
            g_listui_cntx_p->list_info.fwd_id  = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR*)filepath);
        if(g_listui_cntx_p->list_info.fwd_id  <= 0)
            break;
            
        if(link_menu_id == evt->highlighted_menu_id)
        {
            cui_menu_set_new_list_parent_id(evt->sender_id, (U16)g_listui_cntx_p->list_info.fwd_id);
            ret = MMI_RET_OK;
        }
        else if(g_listui_cntx_p->list_info.fwd_id  == evt->parent_menu_id)
        {
            srv_fmgr_types_launch_option(filepath, evt->highlighted_menu_id);
        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
            if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
            {
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
            }
        #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
            ret = MMI_RET_OK;
        }
        break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_song_list_option_cui_proc
 * DESCRIPTION
 *  Menu CUI callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_song_list_option_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            /* Unhide all menu first */
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLAY, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_SEND, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_ADD, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DELETE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_USE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_MARKSVR, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DETAILS, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_FALSE);
        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_SEARCH_PREFIX, MMI_FALSE);
        #endif

        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_CLEAR_PLST, MMI_TRUE);

        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__    
            if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_MARKSVR, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_SEARCH_PREFIX, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_ADD, MMI_TRUE);
            }
        #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/

            /*check list number*/
            if (0 == g_listui_cntx_p->list_info.total)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DETAILS, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_MARKSVR, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_SEND, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_USE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DELETE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST, MMI_TRUE);
            #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_SEARCH_PREFIX, MMI_TRUE);
            #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
            }
            else if(1 == g_listui_cntx_p->list_info.total)
            {
                //cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_MARKSVR, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_TRUE);
            }

            if (g_listui_cntx_p->list_info.total > 0)
            {
                /* get current file path */
                mmi_medply_listui_get_path(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                           g_listui_cntx_p->list_info.highlight, 
                                           g_listui_cntx_p->list_info.curr_hilite_path);


                fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_SEND, g_listui_cntx_p->list_info.curr_hilite_path, MMI_TRUE);
                fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_USE, g_listui_cntx_p->list_info.curr_hilite_path, MMI_FALSE);
            }

            /*check list type*/
            switch(g_listui_cntx_p->list_info.list_type)
            {
            case LIST_TYPE_PLST_SONG_LIST:
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DELETE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_CLEAR_PLST, MMI_FALSE);
                if (SRV_PLST_DEF_RECENTLY_PLST == g_listui_cntx_p->list_info.def_list_type ||
                    SRV_PLST_DEF_MOST_PLST == g_listui_cntx_p->list_info.def_list_type)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_ADD, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_MARKSVR, MMI_TRUE);
                    //11/22
                    if (mmi_medply_shell_is_registered())
                    {
                        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLAY, MMI_TRUE);
                    }                
                }
                else if (SRV_PLST_DEF_ALL_KURO_LIST == g_listui_cntx_p->list_info.def_list_type)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_ADD, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_MARKSVR, MMI_TRUE);
                }
                break;
            case LIST_TYPE_CATEGORY_SONG_LIST:
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_ADD, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER, MMI_TRUE);
                break;
            case LIST_TYPE_ALL_SONG_LIST:
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_ADD, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER, MMI_TRUE);
                break;
            case LIST_TYPE_ALL_VIDEO_LIST:
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_ADD, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER, MMI_TRUE);
                break;
            case LIST_TYPE_ARTIST_LIST:
            case LIST_TYPE_ALBUM_LIST:
            case LIST_TYPE_GENRE_LIST:
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_ADD, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                break;
            default:
                /*Do not support other type*/
                ASSERT(0);
                break;
            }

            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_FILE_PLAY:
                    mmi_medply_listui_file_play();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_SEND:
                    fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_SEND, g_listui_cntx_p->list_info.curr_hilite_path, MMI_TRUE);
                //#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
                    //if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
                    //{
                    //    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
                    //}
                //#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_PLST_ADD:
                    mmi_medply_listui_multi_add_begin();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_AUDIO_ADDFRM_FOLDER:
                    mmi_medply_listui_add_from_folder(MMI_TRUE);
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_VIDEO_ADDFRM_FOLDER:
                    mmi_medply_listui_add_from_folder(MMI_FALSE);
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_DELETE:
                    mmi_medply_listui_common_delete_req();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE:
                    mmi_medply_listui_common_remove_req();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_USE:
                    fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_USE, g_listui_cntx_p->list_info.curr_hilite_path, MMI_FALSE);
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST:
                    mmi_medply_listui_addto_plst();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_CLEAR_PLST:
                    mmi_medply_listui_clear_plst();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_MARKSVR:
                    mmi_medply_listui_multi_select_begin();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_DETAILS:
                    mmi_medply_listui_entry_details();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_PLST_OGNZ:
                    mmi_medply_listui_plst_organize_req();
                    break;
            #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
                case MENU_ID_MEDPLY_FTE_FILE_SEARCH_PREFIX:
                    mmi_medply_listui_prefix_search_begin();
                    break;
            #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
                default:
                    fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_SEND, g_listui_cntx_p->list_info.curr_hilite_path, MMI_TRUE);
                    fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_USE, g_listui_cntx_p->list_info.curr_hilite_path, MMI_FALSE);
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /* Close CUI */
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_all_songs
 * DESCRIPTION
 *  apply picked file, fill global context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_song_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_MEDPLY_FTE_FILE_LIST_OPTION,
                               MMI_TRUE,
                               (void*)MEDPLY_MENU_CUI_FILE_LIST_OPT);
    cui_menu_run(menu_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_type_list_option_cui_proc
 * DESCRIPTION
 *  Menu CUI callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_type_list_option_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            /* config option items*/
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_OPEN, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_PLAY, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_DELETE, MMI_FALSE);
        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_SEARCH_PREFIX, MMI_FALSE);
        #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/

        #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_IMAGE_FLOW, MMI_FALSE);
        #else
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_IMAGE_FLOW, MMI_TRUE);
        #endif

        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
            if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_SEARCH_PREFIX, MMI_TRUE);
            }
        #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
    
            /*check list number*/
            if (0 == g_listui_cntx_p->list_info.total)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_OPEN, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_DELETE, MMI_TRUE);
            #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_SEARCH_PREFIX, MMI_TRUE);
            #endif
            #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_IMAGE_FLOW, MMI_TRUE);
            #endif
            }

            /* check list type*/
            /*only show cover flow and edit album image option in all albums list*/
            if (LIST_TYPE_ALBUM_LIST != g_listui_cntx_p->list_info.list_type)
            {
            #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_IMAGE_FLOW, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM, MMI_TRUE);
            #endif
            }

            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_TYPE_OPEN:
                    mmi_medply_listui_type_open_list();
                    break;
                case MENU_ID_MEDPLY_FTE_TYPE_PLAY:
                    mmi_medply_listui_type_play();
                    break;
                case MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST:
                    mmi_medply_listui_addto_plst();
                    break;
                case MENU_ID_MEDPLY_FTE_TYPE_DELETE:
                    mmi_medply_listui_common_delete_req();
                    break;
            #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
                case MENU_ID_MEDPLY_FTE_TYPE_SEARCH_PREFIX:
                    mmi_medply_listui_prefix_search_begin();
                    break;
            #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
            #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
                case MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM:
                    mmi_medply_listui_edit_elbum();
                    break;
                case MENU_ID_MEDPLY_FTE_TYPE_IMAGE_FLOW:
                    mmi_medply_listui_entry_image_flow();
                    break;
            #endif /* __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__ */
                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /* Close CUI */
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_album_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_type_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_MEDPLY_FTE_TYPE_LIST_OPTION,
                               MMI_FALSE,
                               (void*)MEDPLY_MENU_CUI_TYPE_LIST_OPT);
    cui_menu_run(menu_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_list_option_cui_proc
 * DESCRIPTION
 *  Menu CUI callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_plst_list_option_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 type;
    U32 temp_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            /* Unhide all first */
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_OPEN, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_PLAY, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_CREATE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_DELETE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_RENAME, MMI_FALSE);

            ret = srv_plst_list_get_hint_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                               g_listui_cntx_p->list_info.highlight,
                                               &temp_count);
            if((ret == SRV_PLST_OK) && !temp_count)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_PLAY, MMI_TRUE);
            }

            if (0 == g_listui_cntx_p->list_info.total)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_OPEN, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_DELETE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_RENAME, MMI_TRUE);
            }
	    else
	    {
		//bql: MAUI_02986060
                ret = srv_plst_default_playlist_get_type(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                     g_listui_cntx_p->list_info.highlight, 
                                                     &type);
                if (g_listui_cntx_p->srv_cntx.def_list_set & type)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_DELETE, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_RENAME, MMI_TRUE);
                }
	    
                //11/22
                if (mmi_medply_shell_is_registered())
                {
                    if ((SRV_PLST_DEF_RECENTLY_PLST == type) ||
                        (SRV_PLST_DEF_MOST_PLST == type))
                    {
                        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_PLST_PLAY, MMI_TRUE);
                    }
                }
	    }
            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_PLST_OPEN:
                    mmi_medply_listui_plst_open();
                    break;
                case MENU_ID_MEDPLY_FTE_PLST_PLAY:
                    mmi_medply_listui_plst_play();
                    break;
                case MENU_ID_MEDPLY_FTE_PLST_CREATE:
                    mmi_medply_listui_plst_create();
                    break;
                case MENU_ID_MEDPLY_FTE_PLST_DELETE:
                    mmi_medply_listui_plst_delete_req();
                    break;
                case MENU_ID_MEDPLY_FTE_PLST_RENAME:
                    mmi_medply_listui_plst_rename();
                    break;
                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /* Close CUI */
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_plst_list_option
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void  mmi_medply_listui_entry_plst_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_MEDPLY_FTE_PLST_OPTION,
                               MMI_FALSE,
                               (void*)MEDPLY_MENU_CUI_PLST_LIST_OPT);
    cui_menu_run(menu_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_delete_callback
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        if (NULL != g_listui_cntx_p->srv_cntx.srv_hdlr)
        {
            mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);    
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DELETE_CALLBACK_ERROR);
        }        
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_card_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_card_plug_in_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check organize */
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_FTE_ORGANIZE))
    {
        mmi_frm_group_close(GRP_ID_MEDPLY_FTE_ORGANIZE);
    }

    /* check and close CUI */
    if (0 != g_listui_cntx_p->editor_cntx.gid)
    {
        cui_fseditor_close(g_listui_cntx_p->editor_cntx.gid);
        g_listui_cntx_p->editor_cntx.gid = 0;
    }

    if (0 != g_listui_cntx_p->details_info.inline_gid)
    {
        cui_inline_close(g_listui_cntx_p->details_info.inline_gid);
    }
    
    /*if(mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE, SCR_ID_MEDPLY_FWD, MMI_FRM_NODE_ALL_FLAG))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, "[PLSTUI]Delete USE&FWD screen.");
        mmi_frm_scrn_multiple_close(GRP_ID_MEDPLY_FTE, scr_id, MMI_TRUE, 0, 
                                    g_listui_cntx_p->list_info.list_scr_id, MMI_FALSE);
    }*/

    /* check multisel */
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL, MMI_FRM_NODE_ALL_FLAG) ||
        mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTIADD, MMI_FRM_NODE_ALL_FLAG))
    {
        scr_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                              SCR_ID_INVALID,
                                              MMI_FRM_NODE_AT_LATEST_FLAG);
        mmi_frm_scrn_multiple_close(GRP_ID_MEDPLY_FTE_SUB_MENU, scr_id, MMI_TRUE, 0, 
                                    g_listui_cntx_p->list_info.launch_scr_id, MMI_FALSE);
    }    

    /* check search */
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        scr_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                              SCR_ID_INVALID,
                                              MMI_FRM_NODE_AT_LATEST_FLAG);
        mmi_frm_scrn_multiple_close(GRP_ID_MEDPLY_FTE_SUB_MENU, scr_id, MMI_TRUE, 0, 
                                    g_listui_cntx_p->list_info.search_scr_id, MMI_FALSE);
    }

    /* check details */
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_DETAILS, MMI_FRM_NODE_ALL_FLAG))
    {
        scr_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                              SCR_ID_INVALID,
                                              MMI_FRM_NODE_AT_LATEST_FLAG);
        mmi_frm_scrn_multiple_close(GRP_ID_MEDPLY_FTE_SUB_MENU, scr_id, MMI_TRUE, 0, 
                                    g_listui_cntx_p->list_info.list_scr_id, MMI_FALSE);
    }

    /* check add to plst*/
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS, MMI_FRM_NODE_ALL_FLAG))
    {
        scr_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                              SCR_ID_INVALID,
                                              MMI_FRM_NODE_AT_LATEST_FLAG);
        mmi_frm_scrn_multiple_close(GRP_ID_MEDPLY_FTE_SUB_MENU, scr_id, MMI_TRUE, 0, 
                                    g_listui_cntx_p->list_info.launch_scr_id, MMI_FALSE);
    }

    //goback to first stack
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_SONGS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_SONGS);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_GENRES, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_GENRES);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_PLSTS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_PLSTS);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS);
    }
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_SONGS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_SONGS);
    }
}



#define __LISTUI_COMMON_OPERATION
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_play_begin
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_type_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index  = g_listui_cntx_p->list_info.highlight;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif

    /*play from the first one*/
    g_listui_cntx_p->playing.pick_index = 0;

    /*for artist-> album  index--, for 1st one is all*/
    if (LIST_TYPE_ARTIST_ALBUM_LIST == g_listui_cntx_p->list_info.list_type)
    {
         /* In search list, don't need to do index - 1 for "All songs"*/
        if (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_TYPE_PLAY);
            ASSERT(0 != g_listui_cntx_p->list_info.highlight);
            index--;
        }
    }
    ret = mmi_medply_plst_set_pick_index(index);
    if (ret >= SRV_PLST_OK)
    {
        mmi_medply_listui_common_begin_play();
    }
    else
    {
        mmi_medply_listui_popup_error(ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_file_play
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_file_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif

    /*play from the first one*/
    if(mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        g_listui_cntx_p->playing.pick_index = g_listui_cntx_p->playing.curr_sel_index;        
    }
    else
    {
        g_listui_cntx_p->playing.pick_index = g_listui_cntx_p->list_info.highlight;
    }      
    ret = mmi_medply_plst_set_pick_index(g_listui_cntx_p->playing.pick_index);
    if (ret >= SRV_PLST_OK)
    {
        mmi_medply_listui_common_begin_play();
    }
    else
    {
        mmi_medply_listui_popup_error(ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_begin_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_common_begin_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Callback to shell play function instead of media player */
    if(mmi_medply_shell_is_registered())
    {
        mmi_medply_shell_play_req();
        return;
    }

    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_MAIN_SCREEN, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_MAIN_SCREEN);
    }
    mmi_medply_play_from_play_list();

    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST);
    
    // TODO: Currently no multi-select to play and search feature, need to verify again when turn on
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL);    
    }
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
    }
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_delete_req_cnf_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_common_delete_req_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_medply_listui_common_delete();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_delete_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_common_delete_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str[MEDPLY_MAX_FILE_LEN + 25];
    U16 title[MEDPLY_MAX_FILE_LEN];
    S32 index = g_listui_cntx_p->list_info.highlight;
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*for artist-> album  index--, for 1st one is all*/
    if (LIST_TYPE_ARTIST_ALBUM_LIST == g_listui_cntx_p->list_info.list_type)
    {
        /* In search list, don't need to do index - 1 for "All songs"*/
        if (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_COMMON_DELETE_REQ);
            ASSERT(0 != g_listui_cntx_p->list_info.highlight);
            index--;
        }
    }

    memset(str, 0, sizeof(str));
    
    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                     index, title);

    /* ? will be displayed by popup framework at last */
    kal_wsprintf(str, "%w\n%w", 
                 get_string(STR_GLOBAL_DELETE),
                 title);

    /* Display confirm */
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_MEDPLY_FTE_SUB_MENU;
    confirm_arg.callback = mmi_medply_listui_common_delete_req_cnf_callback;
    confirm_arg.f_auto_map_empty_softkey = 0; /* Disable CSK for delete */
    /* To display ? by framework */
    confirm_arg.f_auto_question_mark = MMI_TRUE;

    mmi_confirm_display((WCHAR*)str,
                        MMI_EVENT_QUERY,
                        &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_common_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 index = g_listui_cntx_p->list_info.highlight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_COMMON_DELETE);
    g_listui_cntx_p->list_info.popup_strid = STR_GLOBAL_DELETED;

    /*set launch screen if not multi sel*/
    if (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_COMMON_DELETE_SET_LAUNCH_SCREEN,
                         g_listui_cntx_p->list_info.launch_scr_id);
        g_listui_cntx_p->list_info.launch_scr_id = g_listui_cntx_p->list_info.list_scr_id;
        g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_NEED_RESET_HL;
    }

    /*for artist-> album  index--, for 1st one is all*/
    if (LIST_TYPE_ARTIST_ALBUM_LIST == g_listui_cntx_p->list_info.list_type)
    {
        /* In search list, don't need to do index - 1 for "All songs"*/
        if (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_COMMON_DELETE_INDEX_ERROR);
            ASSERT(0 != g_listui_cntx_p->list_info.highlight);
            index--;
        }
    }
    
    ret = srv_plst_list_item_delete(g_listui_cntx_p->srv_cntx.srv_hdlr, index);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else if (SRV_PLST_OK == ret)
    {
        mmi_medply_listui_popup_by_strid(g_listui_cntx_p->list_info.popup_strid, MMI_EVENT_SUCCESS);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else/*ASYC*/
    {
        medply_listui_cancel_cb = mmi_medply_listui_common_delete_stop;
        mmi_medply_listui_entry_wait_scr();
    }

    /*Clear screen gui buffer*/
    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, g_listui_cntx_p->list_info.list_scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_delete_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_common_delete_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_plst_list_item_stop_delete(g_listui_cntx_p->srv_cntx.srv_hdlr, &num);
    medply_listui_cancel_cb = NULL;
    if (ret < SRV_PLST_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SHOULD_NEVER_HAPPEN);
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_COMMON_DELETE_STOP, num);
        if (0 == num)
        {
            /* MAUI_02179704 check if need delete some screen or clear gui buffer*/
            mmi_medply_listui_util_delete_upto(g_listui_cntx_p->list_info.launch_scr_id); 
            if (LIST_TYPE_CATEGORY_SONG_LIST == g_listui_cntx_p->list_info.list_type)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DELETE_SCREEN_FOR_CATEGORY_SONG);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_GENRES);
            }
            else if (LIST_TYPE_ARTIST_ALBUM_LIST == g_listui_cntx_p->list_info.list_type)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DELETE_SCREEN_FOR_ARTIST_ALBUM_SONG);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS);
            }
            mmi_frm_scrn_close_active_id();
        }
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }

    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL);
    }
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
    }
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_remove_req_cnf_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_common_remove_req_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_medply_listui_common_remove();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_remove_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_common_remove_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str[MEDPLY_MAX_FILE_LEN + 25];
    U16 title[MEDPLY_MAX_FILE_LEN];
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str, 0, sizeof(str));
    
    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                     g_listui_cntx_p->list_info.highlight, title);

    /* ? will be displayed by popup framework at last */
    kal_wsprintf(str, "%w\n%w", 
                 get_string(STR_GLOBAL_REMOVE), 
                 title);

    /* Display confirm */
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_MEDPLY_FTE_SUB_MENU;
    confirm_arg.callback = mmi_medply_listui_common_remove_req_cnf_callback;
    confirm_arg.f_auto_map_empty_softkey = 0; /* Disable CSK for delete */
    /* To display ? by framework */
    confirm_arg.f_auto_question_mark = MMI_TRUE;


    mmi_confirm_display((WCHAR*)str,
                        MMI_EVENT_QUERY,
                        &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_common_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_COMMON_REMOVE);
    g_listui_cntx_p->list_info.popup_strid = STR_GLOBAL_REMOVED;

    if(g_mmi_medply_listui_clear_plst_flag == MMI_TRUE)
    {
        ret = srv_plst_list_multi_select_mark_begin(g_listui_cntx_p->srv_cntx.srv_hdlr);
        if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_popup_error(ret);
            return;
        }

        ret = srv_plst_list_multi_select_mark_all(g_listui_cntx_p->srv_cntx.srv_hdlr, MMI_TRUE);
        if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_popup_error(ret);
            srv_plst_list_multi_select_mark_end(g_listui_cntx_p->srv_cntx.srv_hdlr);
            g_mmi_medply_listui_clear_plst_flag = MMI_FALSE;
            return;
        }
    }
    else
    {
        /*set lauch screen if not multi sel*/
        if (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_COMMON_REMOVE_SET_LAUNCH_SCR_ID,
                         g_listui_cntx_p->list_info.launch_scr_id);
            g_listui_cntx_p->list_info.launch_scr_id = g_listui_cntx_p->list_info.list_scr_id;
            g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_NEED_RESET_HL;
        }
    }
    
    ret = srv_plst_plst_item_remove(g_listui_cntx_p->srv_cntx.srv_hdlr, g_listui_cntx_p->list_info.highlight);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else if (SRV_PLST_OK == ret)
    {
        mmi_medply_listui_popup_by_strid(g_listui_cntx_p->list_info.popup_strid, MMI_EVENT_SUCCESS);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
        if(g_mmi_medply_listui_clear_plst_flag == MMI_TRUE)
        {
            srv_plst_list_multi_select_mark_end(g_listui_cntx_p->srv_cntx.srv_hdlr);
            g_mmi_medply_listui_clear_plst_flag = MMI_FALSE;
        }
    }
    else/*ASYC*/
    {
        medply_listui_cancel_cb = mmi_medply_listui_common_remove_stop;
        mmi_medply_listui_entry_wait_scr();
    }

    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, g_listui_cntx_p->list_info.list_scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_remove_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_common_remove_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_plst_plst_item_stop_remove(g_listui_cntx_p->srv_cntx.srv_hdlr, &num);
    medply_listui_cancel_cb = NULL;
    
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else
    {

        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }

    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL);
    }
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
    }
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
}


#define __LISTUI_ADDTO_PLST
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_addto_plst
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_addto_plst(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ADDTO_PLST);
    /*cache_file_idx is audio id be going to add to plyst*/
    g_listui_cntx_p->list_info.cache_file_idx = g_listui_cntx_p->list_info.highlight;
    if (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ADDTO_PLST_SET_LAUNCH_SCR_ID,
                         g_listui_cntx_p->list_info.launch_scr_id);
        g_listui_cntx_p->list_info.launch_scr_id = g_listui_cntx_p->list_info.list_scr_id;
    }
    mmi_medply_listui_entry_addto_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_addto_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_addto_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_listui_prepare_addto_plst(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                               LIST_TYPE_ADDTO_PLST_LIST,
                                               &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                &g_listui_cntx_p->list_info.total);
    
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }    
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS, NULL, 
                                   mmi_medply_listui_entry_addto_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }
    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS!= g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type_backup   = g_listui_cntx_p->list_info.list_type;
        g_listui_cntx_p->list_info.list_scr_id_backup = g_listui_cntx_p->list_info.list_scr_id;
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_ADDTO_PLST_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_PLAYLISTS), 
                     MEDPLY_MAX_FILE_LEN - 1);
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS, 
                                mmi_medply_listui_delete_callback);

    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);

    mmi_medply_listui_show_addto_plst_scr(g_listui_cntx_p->list_info.title, 
                                           g_listui_cntx_p->list_info.total + 1,
                                           g_listui_cntx_p->list_info.highlight);//@TODO: pass in parameter

            
    SetLeftSoftkeyFunction(mmi_medply_listui_addto_plst_done, KEY_EVENT_UP);
    if(mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
        SetCenterSoftkeyFunction(mmi_medply_listui_addto_plst_done, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    SetRightSoftkeyFunction(mmi_medply_listui_exit_addto_list, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_addto_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_exit_addto_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
    }
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_addto_plst_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_addto_plst_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 index = g_listui_cntx_p->list_info.cache_file_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (LIST_TYPE_ARTIST_ALBUM_LIST == 
        g_listui_cntx_p->view_stack.list_type[g_listui_cntx_p->view_stack.curr_ptr - 1])
    {
        /* In search list, don't need to do index - 1 for "All songs"*/
        if (!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ADDTO_PLST_DONE_INDEX_ERROR);
            index--;
        }
    }

    if (g_listui_cntx_p->list_info.highlight > 0)
    {
        ret = srv_plst_media_add_to_playlist(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                             index,
                                             g_listui_cntx_p->list_info.highlight - 1);
        if (SRV_PLST_ASYNC == ret)
        {
            medply_listui_cancel_cb = mmi_medply_listui_addto_plst_cancel;
            mmi_medply_listui_entry_wait_scr();
        }
        else if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_popup_error(ret);
            /* Close add screen */
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS);

            g_listui_cntx_p->list_info.launch_scr_id = 0;
        }
        else
        {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
            /* Close add screen */
            mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS);

            g_listui_cntx_p->list_info.launch_scr_id = 0;
        }
        g_listui_cntx_p->list_info.cache_file_idx = 0;
    }
    else
    {
        mmi_medply_listui_plst_create();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_addto_plst_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_addto_plst_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ret = srv_plst_media_stop_add_to_playlist(g_listui_cntx_p->srv_cntx.srv_hdlr);
    medply_listui_cancel_cb = NULL;
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else
    {
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    
    /* Close add to and processing screen */
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_MULTISEL)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL);
    }
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
    }
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS);
    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_addto_plst_scr
 * DESCRIPTION
 *  Show addto playlist ui.
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_addto_plst_scr(UI_string_type title, S32 total, S32 highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8*  guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    wgui_cat_register_get_flags_callback(mmi_medply_listui_common_list_disable_scrollbar);
    ShowCategory183Screen(
        title, 
        get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
        get_string(STR_GLOBAL_OK),
        get_image(STR_GLOBAL_OK),              
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK), 
        total,
        mmi_medply_listui_get_common_list_item,
        NULL,
        highlight,
        MMI_FALSE,
        NULL,
        guiBuffer);
    wgui_title_set_shortcut_count(0);
}

#define __LISTUI_CLEAR_PLST
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_addto_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_clear_plst(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_medply_listui_clear_plst_flag = MMI_TRUE;
    mmi_medply_listui_common_remove();
}


#define __LISTUI_PLST_OPRATION
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //@TODO: add log
    g_listui_cntx_p->list_info.cache_plst_idx = g_listui_cntx_p->list_info.highlight;
    mmi_medply_listui_get_plst_title(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                     g_listui_cntx_p->list_info.highlight, 
                                     (U16*)g_listui_title_l2);

    srv_plst_default_playlist_get_type(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                       g_listui_cntx_p->list_info.highlight, 
                                       &g_listui_cntx_p->list_info.def_list_type);
    
    mmi_medply_listui_entry_plst_song_list();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif

    /*play from the first one*/
    g_listui_cntx_p->playing.pick_index = 0;
    ret = mmi_medply_plst_set_pick_index(g_listui_cntx_p->list_info.highlight);
    if (ret >= SRV_PLST_OK)
    {
        mmi_medply_listui_common_begin_play();
    }
    else
    {
        mmi_medply_listui_popup_error(ret);
    }      
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_listui_cntx_p->editor_cntx, 0, sizeof(mmi_medply_listui_editor_cntx_struct));

    g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_NEW;
    g_listui_cntx_p->editor_cntx.limit = MEDPLY_MAX_FILE_LEN - 1;
    g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_LISTMGR_OPT_NEW;
    g_listui_cntx_p->editor_cntx.original_string_p = NULL;
    g_listui_cntx_p->editor_cntx.done_func = mmi_medply_listui_plst_create_done;

    mmi_medply_listui_entry_editor();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_create_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL mmi_medply_listui_plst_create_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 plst_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_medply_listui_editor_check_valid())
    {
        //@TODO: add error log
        return MMI_FALSE;
    }

    /* Try to create plst. */
    ret = srv_plst_plst_create(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                               (U16*)g_listui_cntx_p->editor_cntx.editor_buffer, 
                               &plst_id);
    if (SRV_PLST_OK == ret)
    {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
    }
    else
    {
        mmi_medply_listui_popup_error(ret);
    }
 

    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_PLSTS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_PLSTS);
    }
    else if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ADDTO_PLSTS);
    }
    else
    {
        /*either create new or add to new plst, no other case*/
        ASSERT(0);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_delete_req_cnf_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_plst_delete_req_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_medply_listui_plst_delete();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_delete
 * DESCRIPTION
 *
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_delete_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str[MEDPLY_MAX_FILE_LEN + 25];
    U16 title[MEDPLY_MAX_FILE_LEN];
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str, 0, sizeof(str));
    
    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                     g_listui_cntx_p->list_info.highlight, title);

    /* ? will be dispalyed by framework at last */
    kal_wsprintf(str, "%w\n%w", 
                 get_string(STR_GLOBAL_DELETE), 
                 title);

    /* Display confirm */
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_MEDPLY_FTE_SUB_MENU;
    confirm_arg.callback = mmi_medply_listui_plst_delete_req_cnf_callback;
    confirm_arg.f_auto_map_empty_softkey = 0; /* Disable CSK for delete */
    /* To display ? by framework */
    confirm_arg.f_auto_question_mark = MMI_TRUE;


    mmi_confirm_display((WCHAR*)str,
                        MMI_EVENT_QUERY,
                        &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_delete
 * DESCRIPTION
 *
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PLST_DELETE);

    /*set lauch screen*/
    g_listui_cntx_p->list_info.launch_scr_id = g_listui_cntx_p->list_info.list_scr_id;
    g_listui_cntx_p->list_info.popup_strid = STR_GLOBAL_DELETED;
    
    ret = srv_plst_plst_delete(g_listui_cntx_p->srv_cntx.srv_hdlr, g_listui_cntx_p->list_info.highlight);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else if (SRV_PLST_OK == ret)
    {
        mmi_medply_listui_popup_by_strid(g_listui_cntx_p->list_info.popup_strid, MMI_EVENT_SUCCESS);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else/*ASYC*/
    {
        medply_listui_cancel_cb = mmi_medply_listui_plst_delete_stop;
        mmi_medply_listui_entry_wait_scr();
    }

    /*Clear screen gui buffer*/
    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, g_listui_cntx_p->list_info.list_scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_cancel_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_delete_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_plst_plst_stop_delete(g_listui_cntx_p->srv_cntx.srv_hdlr, &num);
    medply_listui_cancel_cb = NULL;
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else
    {
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }

    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title[MEDPLY_MAX_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_listui_cntx_p->editor_cntx, 0, sizeof(mmi_medply_listui_editor_cntx_struct));

    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                     g_listui_cntx_p->list_info.highlight, title);

    g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_RENAME;
    g_listui_cntx_p->editor_cntx.limit = MEDPLY_MAX_FILE_LEN - 1;
    g_listui_cntx_p->editor_cntx.editor_title_id = STR_GLOBAL_RENAME;
    g_listui_cntx_p->editor_cntx.original_string_p = NULL;
    g_listui_cntx_p->editor_cntx.done_func = mmi_medply_listui_plst_rename_done;
    if (title != NULL)
    {
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                     (CHAR*) title,
                     MMI_MEDPLY_MAX_EDITOR_LEN);
    } 

    mmi_medply_listui_entry_editor();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_create_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL mmi_medply_listui_plst_rename_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    UI_character_type old_name[MEDPLY_MAX_FILE_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_medply_listui_editor_check_valid())
    {
        //@TODO: add error log
        return MMI_FALSE;
    }
    
    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                     g_listui_cntx_p->list_info.highlight, old_name);
    
    /*Name not change, go back directly*/
    if (!mmi_ucs2ncmp((const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer, (const CHAR*)old_name, MEDPLY_MAX_FILE_LEN - 1))
    {
        return MMI_TRUE;
    }

    ret = srv_plst_plst_rename(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                               (U16*)g_listui_cntx_p->editor_cntx.editor_buffer, 
                               g_listui_cntx_p->list_info.highlight);
    if (SRV_PLST_OK == ret)
    {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
    }
    else if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
    }
    else
    {
        /*should not allowed to return other value*/
        ASSERT(0);
    }

    return MMI_TRUE;
}


#define __LISTUI_MULTI_SELECT_OPERATION
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_highlight_hdlr
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_multiset_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->list_info.highlight = index;
    g_listui_cntx_p->list_info.mark_highlight = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multi_select_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_multi_select_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*begin mark several session*/
    ret = srv_plst_list_multi_select_mark_begin(g_listui_cntx_p->srv_cntx.srv_hdlr);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    g_listui_cntx_p->list_info.launch_scr_id = g_listui_cntx_p->list_info.list_scr_id;
    g_listui_cntx_p->list_info.mark_ref = 0;
    g_listui_cntx_p->list_info.flag |= MMI_MEDPLY_LISTUI_IS_MULTISEL;
    g_listui_cntx_p->list_info.mark_highlight = g_listui_cntx_p->list_info.highlight;
    g_listui_cntx_p->list_info.flag |= MMI_MEDPLY_LISTUI_NEED_RESET_HL;
    
    mmi_medply_listui_entry_multisel_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multi_select_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_multi_select_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_listui_cntx_p->list_info.launch_scr_id = 0;
    g_listui_cntx_p->list_info.mark_ref = 0;
    g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_MULTISEL;
    ret = srv_plst_list_multi_select_mark_end(g_listui_cntx_p->srv_cntx.srv_hdlr);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
    }
    g_listui_cntx_p->list_info.highlight = g_listui_cntx_p->list_info.mark_highlight;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_multisel_list
 * DESCRIPTION
 *  t.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_multisel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    U8*      guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL, NULL, 
                                   mmi_medply_listui_entry_multisel_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTISEL, mmi_medply_listui_multisel_delete_callback);

    mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                          &g_listui_cntx_p->list_info.total);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = g_listui_cntx_p->list_info.mark_highlight;
    }
    else
    {
        // When will go to this part?
        /* if goback from addto plst list, restore list info*/
        if (LIST_TYPE_ADDTO_PLST_LIST == g_listui_cntx_p->list_info.list_type)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_RESTORE_LIST_INFO);
            g_listui_cntx_p->list_info.list_type   = g_listui_cntx_p->list_info.list_type_backup;
            g_listui_cntx_p->list_info.list_scr_id = g_listui_cntx_p->list_info.list_scr_id_backup;
            switch (g_listui_cntx_p->list_info.list_scr_id)
            {
            case SCR_ID_MEDPLY_LISTUI_ALL_SONGS:
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_ALL_SONGS), 
                     MEDPLY_MAX_FILE_LEN - 1);
                break;

            case SCR_ID_MEDPLY_LISTUI_ALL_VIDEOS:
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_ALL_VIDEOS), 
                     MEDPLY_MAX_FILE_LEN - 1);
                break;

            case SCR_ID_MEDPLY_LISTUI_SONGS:
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)g_listui_title_l2, 
                     MEDPLY_MAX_FILE_LEN - 1);
                break;
                
            default:
                break;
            }
        }        
    }
 
    mmi_medply_listui_show_check_list_scr(g_listui_cntx_p->list_info.total,
                                          g_listui_cntx_p->list_info.highlight);

    if (g_listui_cntx_p->list_info.total > 0)
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_entry_multisel_option, KEY_EVENT_UP); 
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_callback
 * DESCRIPTION
 *  apply picked file, fill global context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
mmi_ret mmi_medply_listui_multisel_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_medply_listui_multi_select_end();
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_option_cui_proc
 * DESCRIPTION
 *  Menu CUI callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_multisel_option_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:

            /* config option items*/
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_ADDTO_PLST, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_DELETE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_REMOVE, MMI_FALSE);
    #ifdef __MMI_MEDPLY_MULTISEL_PLAY_SUPPORT__
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_PLAY, MMI_FALSE);
    #endif /*__MMI_MEDPLY_MULTISEL_PLAY_SUPPORT__*/

            if (g_listui_cntx_p->list_info.mark_ref == 0)
            {        
            #ifdef __MMI_MEDPLY_MULTISEL_PLAY_SUPPORT__
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_PLAY, MMI_TRUE);
            #endif /*__MMI_MEDPLY_MULTISEL_PLAY_SUPPORT__*/
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_DELETE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_REMOVE, MMI_TRUE);
            }
            else if (g_listui_cntx_p->list_info.mark_ref == g_listui_cntx_p->list_info.total)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL, MMI_TRUE);
            }
            else
            {
                ASSERT(g_listui_cntx_p->list_info.mark_ref <= g_listui_cntx_p->list_info.total);
            }
        
            if (LIST_TYPE_PLST_SONG_LIST == g_listui_cntx_p->list_info.list_type)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_DELETE, MMI_TRUE);
            }
            else if (LIST_TYPE_ALL_VIDEO_LIST == g_listui_cntx_p->list_info.list_type)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_REMOVE, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_REMOVE, MMI_TRUE);
            }
            break;


        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL:
                    mmi_medply_listui_multi_select_mark_all();
                    break;
                case MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL:
                    mmi_medply_listui_multi_select_unmark_all();
                    break;
            #ifdef __MMI_MEDPLY_MULTISEL_PLAY_SUPPORT__
                case MENU_ID_MEDPLY_FTE_MULTISEL_PLAY:
                    mmi_medply_listui_type_play();
                    break;
            #endif /* __MMI_MEDPLY_MULTISEL_PLAY_SUPPORT__ */
                case MENU_ID_MEDPLY_FTE_MULTISEL_ADDTO_PLST:
                    mmi_medply_listui_addto_plst();
                    break;
                case MENU_ID_MEDPLY_FTE_MULTISEL_DELETE:
                    mmi_medply_listui_multisel_delete_req();
                    break;
                case MENU_ID_MEDPLY_FTE_MULTISEL_REMOVE:
                    mmi_medply_listui_multisel_remove_req();
                    break;
                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /* Close CUI */
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_multisel_option
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_multisel_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_MEDPLY_FTE_MULTISEL_LIST_OPTION,
                               MMI_FALSE,
                               (void*)MEDPLY_MENU_CUI_MULTISEL_LIST_OPTION);
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_file_add_from_allsongs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_multi_add_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*entry all songs list firstly*/
    ret = mmi_medply_listui_prepare_all_songs(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                              LIST_TYPE_ALL_SONG_LIST,
                                              &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }
    
    /*begin mark several session*/
    ret = srv_plst_list_multi_select_mark_begin(g_listui_cntx_p->srv_cntx.srv_hdlr);
    if (ret < SRV_PLST_OK)
    {
        /*multiselect begin fail, quit all songs list*/
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }

    g_listui_cntx_p->list_info.mark_ref = 0;
    g_listui_cntx_p->list_info.launch_scr_id = g_listui_cntx_p->list_info.list_scr_id;
    g_listui_cntx_p->list_info.flag |= MMI_MEDPLY_LISTUI_IS_MULTISEL;

    mmi_medply_listui_entry_multiadd_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multi_add_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_multi_add_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_listui_cntx_p->list_info.launch_scr_id = 0;
    g_listui_cntx_p->list_info.mark_ref = 0;
    g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_MULTISEL;
    ret = srv_plst_list_multi_select_mark_end(g_listui_cntx_p->srv_cntx.srv_hdlr);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
    }

    ret = mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_multiadd_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_multiadd_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    U8* guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr,&g_listui_cntx_p->list_info.total);
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTIADD, NULL, 
                                   mmi_medply_listui_entry_multiadd_list, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                SCR_ID_MEDPLY_LISTUI_MULTIADD,
                                mmi_medply_listui_multiadd_delete_callback);

    if (SCR_ID_MEDPLY_LISTUI_MULTIADD != g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_ALL_SONG_LIST;  
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_MULTIADD;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }    

    mmi_medply_listui_show_check_list_scr(g_listui_cntx_p->list_info.total, 0);

    if (g_listui_cntx_p->list_info.total > 0)
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_entry_multiadd_option, KEY_EVENT_UP);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_callback
 * DESCRIPTION
 *  apply picked file, fill global context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
mmi_ret mmi_medply_listui_multiadd_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_medply_listui_multi_add_end();
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multi_add_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_multi_add_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_plst_media_add_to_playlist(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                -1, g_listui_cntx_p->list_info.cache_plst_idx);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
    }
    else if (SRV_PLST_OK == ret)
    {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif

    }
    else /*async*/
    {
        medply_listui_cancel_cb = mmi_medply_listui_multi_add_cancel;
        mmi_medply_listui_entry_wait_scr();
    }

    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, g_listui_cntx_p->list_info.launch_scr_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multi_add_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_multi_add_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_plst_media_stop_add_to_playlist(g_listui_cntx_p->srv_cntx.srv_hdlr);
    medply_listui_cancel_cb = NULL;
    
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else
    {
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }    
    
    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_MULTIADD);
    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_option_cui_proc
 * DESCRIPTION
 *  Menu CUI callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_multiadd_option_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:

            /* config option items*/
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_ADD_MARKED, MMI_FALSE);

            if (g_listui_cntx_p->list_info.mark_ref == 0)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_ADD_MARKED, MMI_TRUE);
            }
            else if (g_listui_cntx_p->list_info.mark_ref == g_listui_cntx_p->list_info.total)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL, MMI_TRUE);
            }
            else
            {
                ASSERT(g_listui_cntx_p->list_info.mark_ref <= g_listui_cntx_p->list_info.total);
            }
    
            break;


        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_MULTISEL_MARK_ALL:
                    mmi_medply_listui_multi_select_mark_all();
                    break;
                case MENU_ID_MEDPLY_FTE_MULTISEL_UNMARK_ALL:
                    mmi_medply_listui_multi_select_unmark_all();
                    break;

                case MENU_ID_MEDPLY_FTE_MULTISEL_ADD_MARKED:
                    mmi_medply_listui_multi_add_done();
                    break;

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /* Close CUI */
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_multiadd_option
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_multiadd_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_MEDPLY_FTE_MULTIADD_LIST_OPTION,
                               MMI_FALSE,
                               (void*)MEDPLY_MENU_CUI_MULTIADD_LIST_OPTION);
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multi_select_mark_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_multi_select_mark_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->list_info.mark_ref = g_listui_cntx_p->list_info.total;
    srv_plst_list_multi_select_mark_all(g_listui_cntx_p->srv_cntx.srv_hdlr, MMI_TRUE);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multi_select_unmark_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_multi_select_unmark_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->list_info.mark_ref = 0;
    srv_plst_list_multi_select_mark_all(g_listui_cntx_p->srv_cntx.srv_hdlr, MMI_FALSE);
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_multi_select_scr
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_check_list_scr(S32 total, S32 highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8*      guiBuffer;
    U8*      HintStr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();;

    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_multiset_highlight_hdlr);

    if (total == 0)
    {
        ShowCategory353Screen(
            (U8*)GetString(STR_GLOBAL_SELECT),
            GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
            0,
            0,
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
    
    #ifndef __MMI_TOUCH_SCREEN__
        HintStr = (U8*) GetString(STR_ID_MEDPLY_PLST_NOTIFY_PRESS_STAR);
    #else /* def __MMI_TOUCH_SCREEN__ */
        HintStr = (U8*)NULL; // GetString(STR_ID_MEDPLY_PLST_NOTIFY_TOUCH_BOX);
    #endif /* def __MMI_TOUCH_SCREEN__ */
        wgui_cat_register_get_flags_callback(mmi_medply_listui_common_list_disable_scrollbar);
        ShowCategory384Screen(
            (UI_string_type)GetString(STR_GLOBAL_SELECT),
            get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            HintStr,
            total,
            mmi_medply_listui_get_common_list_item,
            mmi_medply_listui_get_common_list_hint,
            mmi_medply_listui_checklist_get_state,
            mmi_medply_listui_checklist_set_state,
            highlight,
            guiBuffer);
        wgui_title_set_shortcut_count(0);

    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
    #endif /* __MMI_TOUCH_SCREEN__ */

	#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_medply_listui_multisel_tap_callback);
    #endif /* __MMI_FTE_SUPPORT__ */
    
        SetKeyHandler(mmi_medply_listui_checklist_change_state, KEY_ENTER, KEY_EVENT_DOWN);
    #ifndef __MMI_TOUCH_SCREEN__
        SetKeyHandler(mmi_medply_listui_checklist_change_state, KEY_STAR, KEY_EVENT_DOWN);
    #endif
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_multisel_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_checklist_change_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_checklist_change_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //TODO: Set command to change mark state
    if (mmi_medply_listui_checklist_set_state(g_listui_cntx_p->list_info.highlight) == MMI_TRUE)
    {
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_checklist_get_state
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_checklist_get_state(S32 item_index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_marked = MMI_FALSE;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //TODO: Set check box image
    ret = srv_plst_list_multi_select_get_mark(g_listui_cntx_p->srv_cntx.srv_hdlr,item_index, &is_marked);
    if (ret >= SRV_PLST_OK)
    {
        if (is_marked)
        {
            *checkbox_image = (PU8)GetImage(CHECKBOX_ON_IMAGE_ID);
        }
        else
        {
            *checkbox_image = (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID);
        }
        return MMI_TRUE;
    }
	else
	{
		*checkbox_image = (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID);
	}
    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_checklist_set_state
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_listui_checklist_set_state(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_BOOL is_marked;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //TODO: Set commond to list service to mark/unmark item
    ret = srv_plst_list_multi_select_get_mark(g_listui_cntx_p->srv_cntx.srv_hdlr, item_index, &is_marked);
    if (ret >= SRV_PLST_OK)
    {
        if (is_marked)
        {
            srv_plst_list_multi_select_set_mark(g_listui_cntx_p->srv_cntx.srv_hdlr,item_index, MMI_FALSE);
            g_listui_cntx_p->list_info.mark_ref--;
        }
        else
        {
            srv_plst_list_multi_select_set_mark(g_listui_cntx_p->srv_cntx.srv_hdlr,item_index, MMI_TRUE);
            g_listui_cntx_p->list_info.mark_ref++;
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_delete_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_multisel_delete_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str[MEDPLY_MAX_FILE_LEN + 25];
    U16 title[MEDPLY_MAX_FILE_LEN];
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str, 0, sizeof(str));
    
    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                     g_listui_cntx_p->list_info.highlight, title);

    kal_wsprintf(str, "%w%w", 
                 get_string(STR_GLOBAL_DELETE), 
                 get_string(STR_ID_FMGR_QUESTION_MARK));

    /* Display confirm */
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_MEDPLY_FTE_SUB_MENU;
    confirm_arg.callback = mmi_medply_listui_common_delete_req_cnf_callback;
    confirm_arg.f_auto_map_empty_softkey = 0; /* Disable CSK for delete */

    mmi_confirm_display((WCHAR*)str,
                        MMI_EVENT_QUERY,
                        &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_remove_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_multisel_remove_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str[MEDPLY_MAX_FILE_LEN + 25];
    U16 title[MEDPLY_MAX_FILE_LEN];
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(str, 0, sizeof(str));
    
    mmi_medply_listui_get_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                     g_listui_cntx_p->list_info.highlight, title);

    kal_wsprintf(str, "%w%w", 
                 get_string(STR_GLOBAL_REMOVE), 
                 get_string(STR_ID_FMGR_QUESTION_MARK));

    /* Display confirm */
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_MEDPLY_FTE_SUB_MENU;
    confirm_arg.callback = mmi_medply_listui_common_remove_req_cnf_callback;
    confirm_arg.f_auto_map_empty_softkey = 0; /* Disable CSK for delete */

    mmi_confirm_display((WCHAR*)str,
                        MMI_EVENT_QUERY,
                        &confirm_arg);
}


#define __LISTUI_ORGANIZE_OPERATION
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_details_save_confirm_cnf_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_plst_organize_req_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_medply_listui_plst_organize_begin();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_organize_req
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_organize_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_is_play_activated())
    {
        /* Display confirm */
        mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

        confirm_arg.parent_id = GRP_ID_MEDPLY_FTE_SUB_MENU;
        confirm_arg.callback = mmi_medply_listui_plst_organize_req_cnf_callback;

        mmi_confirm_display((WCHAR*)get_string(STR_ID_MEDPLY_PAUSE_CONFIRM),
                            MMI_EVENT_QUERY,
                            &confirm_arg);
    }
    else
    {
        mmi_medply_listui_plst_organize_begin();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_organize_proc
 * DESCRIPTION
 *  Screen group callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_plst_organize_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Screen group event */
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT: // framework de-init the group
            break;
        case EVT_ID_SCRN_INACTIVE:
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_organize_begin
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_organize_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*PLST Service limitation, must suspend play before organize*/
    mdi_audio_suspend_background_play();
    
    ret = srv_plst_plst_item_reorder_begin(g_listui_cntx_p->srv_cntx.srv_hdlr);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        mdi_audio_resume_background_play();
        return;
    }

    /* Enter submenu screen group */
    mmi_frm_group_create(GRP_ID_MEDPLY_FTE_SUB_MENU, GRP_ID_MEDPLY_FTE_ORGANIZE, mmi_medply_listui_plst_organize_proc, NULL);
    mmi_frm_group_enter(GRP_ID_MEDPLY_FTE_ORGANIZE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_listui_cntx_p->list_info.is_changed = MMI_FALSE;
    g_listui_cntx_p->list_info.is_hold = MMI_FALSE;
    g_listui_cntx_p->list_info.hold_id = 0;
    g_listui_cntx_p->list_info.flag |= MMI_MEDPLY_LISTUI_IS_ORGANIZE;
    g_listui_cntx_p->list_info.launch_scr_id = g_listui_cntx_p->list_info.list_scr_id;
    mmi_medply_listui_entry_organzie_list();

    /* 
     * MAUI_02181953, 
     * service always clear cache in srv_plst_plst_item_reorder_begin
     * so clear list scr gui buffer every time entry organize list.
     */
    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, g_listui_cntx_p->list_info.launch_scr_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_organize_end
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_organize_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_plst_plst_item_reorder_end(g_listui_cntx_p->srv_cntx.srv_hdlr);
    g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_ORGANIZE;
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    else
    {
        g_listui_cntx_p->list_info.launch_scr_id = 0;
    }
    
    mmi_frm_group_close(GRP_ID_MEDPLY_FTE_ORGANIZE);
    mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_plst_organize_begin
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_plst_organize_error_quit(S32 err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ORGANIZE_ERROR_QUIT);
    srv_plst_plst_item_reorder_action_set_result(g_listui_cntx_p->srv_cntx.srv_hdlr, MMI_FALSE);
    srv_plst_plst_item_reorder_end(g_listui_cntx_p->srv_cntx.srv_hdlr);
    g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_ORGANIZE;
    
    mmi_medply_listui_popup_error(err);
    mmi_frm_group_close(GRP_ID_MEDPLY_FTE_ORGANIZE);
    g_listui_cntx_p->list_info.launch_scr_id = 0;

    mdi_audio_resume_background_play();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_organzie_list
 * DESCRIPTION
 *  apply picked file, fill global context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_organzie_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    U8* guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*goon to use current list*/
    ASSERT (g_listui_cntx_p->list_info.total > 0);
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_ORGANIZE, SCR_ID_MEDPLY_LISTUI_ORGANIZE, NULL, 
                                   mmi_medply_listui_entry_organzie_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_ORGANIZE, 
                                SCR_ID_MEDPLY_LISTUI_ORGANIZE,
                                mmi_medply_listui_organize_delete_callback);
    
    mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                          &g_listui_cntx_p->list_info.total);
    
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->list_info.highlight = 0;
    }

    RegisterHighlightHandler(mmi_medply_listui_organize_hilite_hdlr);
    wgui_cat_register_get_flags_callback(mmi_medply_listui_organize_disable_shortcut_callback);
   
    mmi_medply_listui_show_organize_scr(g_listui_cntx_p->list_info.total, 
                                        g_listui_cntx_p->list_info.highlight,
                                        g_listui_cntx_p->list_info.is_hold,
                                        g_listui_cntx_p->list_info.is_changed);

/* MAUI_02261608
#ifdef __MMI_FTE_SUPPORT__
    wgui_register_tap_callback(mmi_medply_listui_organize_list_tap_callback);
#endif*/
    SetKeyHandler(mmi_medply_listui_organize_list_goto_prev_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_listui_organize_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_listui_organize_list_goto_prev_item, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_listui_organize_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_listui_organize_list_goto_prev_item, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_listui_organize_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_listui_organize_list_goto_prev_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_listui_organize_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
    if (g_listui_cntx_p->list_info.is_hold)
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_organize_set_move, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_medply_listui_organize_cancel_move, KEY_EVENT_UP);
    }
    else
    {
        /*LSK to mark a file as hold id*/
        SetLeftSoftkeyFunction(mmi_medply_listui_organize_get_move, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_medply_listui_plst_organize_end,  KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_organize_delete_callback
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
mmi_ret mmi_medply_listui_organize_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_ORGANIZE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DELETE_CALLBACK);
            srv_plst_plst_item_reorder_action_set_result(g_listui_cntx_p->srv_cntx.srv_hdlr, MMI_FALSE);
            mmi_medply_listui_plst_organize_end();
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_organize_scr
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_organize_scr(S32 total, S32 highlight,MMI_BOOL is_hold, MMI_BOOL is_changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL disable_cache;
    U16 LSK_string = 0;
    U16 RSK_string = 0;
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_FTE_ORGANIZE, SCR_ID_MEDPLY_LISTUI_ORGANIZE);
    
    wgui_cat_register_get_flags_callback(mmi_medply_listui_organize_disable_shortcut_callback);
    if (is_hold)
    {
        LSK_string    = STR_GLOBAL_OK;
        RSK_string    = STR_GLOBAL_CANCEL;
        disable_cache = MMI_TRUE;
    }
    else
    {
        LSK_string    = STR_ID_MEDPLY_PLST_MOVE;
        RSK_string    = STR_GLOBAL_BACK;
        disable_cache = MMI_FALSE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SHOW_ORGANIZE_SCR_DISABLE_CACHE, 
                     disable_cache);
    wgui_cat_register_get_flags_callback(mmi_medply_listui_common_list_disable_scrollbar);
    ShowCategory183Screen(
        get_string(STR_ID_MEDPLY_PLST_ORGANIZE_LIST), 
        get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
        get_string(LSK_string),
        0,              
        get_string(RSK_string),
        0, 
        total,
        mmi_medply_listui_get_organize_list_item,
        NULL,
        highlight,
        disable_cache,
        NULL,
        guiBuffer);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_organize_list_item
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
pBOOL mmi_medply_listui_get_organize_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U16 img_id;
    U16 format;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * MAUI_02186627, after order change 
     * do not update buffer immediately, if pen if down on the highlight item.
     */
    if (gui_screen_smooth_scrolling_by_pen())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GUI_SCREEN_SMOOTH_SCROLLING_BY_PEN,
                         item_index, g_listui_cntx_p->list_info.highlight, g_listui_cntx_p->list_info.is_changed);
        if ((item_index == g_listui_cntx_p->list_info.highlight) &&
            (MMI_TRUE == g_listui_cntx_p->list_info.is_changed))
        {
            g_listui_cntx_p->list_info.is_changed = MMI_FALSE;
            mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*)g_listui_item_buff, MEDPLY_MAX_ITEM_LEN - 1);
            *img_buff_p = g_listui_item_image;
            return MMI_TRUE;
        }
    }
    
    ret = mmi_medply_listui_get_orgnz_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr,item_index,str_buff);
    if (ret < SRV_PLST_OK)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_ORGANIZE_LIST_ITEM_TITLE, ret);
        mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
        return MMI_TRUE;
    }
    ret = mmi_medply_listui_get_audio_format(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                       item_index, &format);
    if (ret >= SRV_PLST_OK)
    {
        img_id = mmi_medply_util_get_file_icon(format);
        *img_buff_p = (PU8)GetImage(img_id);
    }
    else
    {
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_orgnz_list_title
 * DESCRIPTION
 *  Get current list total number.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_listui_get_orgnz_list_title(U32 srv_hdlr, S32 index, UI_string_type buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct temp_info;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_info.index = index;
    temp_info.buff_size = MEDPLY_MAX_ITEM_LEN - 1;
    temp_info.string_ptr = (U32)buff;
    ret = srv_plst_plst_item_reorder_get_display(srv_hdlr, &temp_info);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_organize_list_goto_prev_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_organize_list_goto_prev_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 end = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_listui_cntx_p->list_info.highlight <= 0)
    {
        end = g_listui_cntx_p->list_info.total - 1;
    }
    else
    {
        end = g_listui_cntx_p->list_info.highlight - 1;
    }
    
    if (g_listui_cntx_p->list_info.is_hold)
    {
        ret = srv_plst_plst_item_reorder_action(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                g_listui_cntx_p->list_info.hold_id,
                                                end);
        g_listui_cntx_p->list_info.hold_id = end;
        if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_plst_organize_error_quit(ret);
            return;
        }
    }
    else
    {
        //ASSERT(0);
    }
    dynamic_list_goto_item(end);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_organize_list_goto_next_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_organize_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 end = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_listui_cntx_p->list_info.highlight >= g_listui_cntx_p->list_info.total - 1)
    {
        end = 0;
    }
    else
    {
        end = g_listui_cntx_p->list_info.highlight + 1;
    }

    if (g_listui_cntx_p->list_info.is_hold)
    {
        ret = srv_plst_plst_item_reorder_action(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                g_listui_cntx_p->list_info.hold_id,
                                                end);
        g_listui_cntx_p->list_info.hold_id = end;
        if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_plst_organize_error_quit(ret);
            return;
        }
    }
    else
    {
        //ASSERT(0);
    }
    dynamic_list_goto_item(end);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_organize_set_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_organize_set_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_listui_cntx_p->list_info.is_hold)
    {
        ret = srv_plst_plst_item_reorder_action_set_result(g_listui_cntx_p->srv_cntx.srv_hdlr, MMI_TRUE);
        if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_plst_organize_error_quit(ret);
        }
        else
        {
            g_listui_cntx_p->list_info.is_hold = MMI_FALSE;
            g_listui_cntx_p->list_info.hold_id = 0;
            LISTUI_ENABLE_DYNAMIC_LIST_CACHE;
            ChangeLeftSoftkey(STR_ID_MEDPLY_PLST_MOVE, 0);
            SetLeftSoftkeyFunction(mmi_medply_listui_organize_get_move, KEY_EVENT_UP);
            ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
            SetRightSoftkeyFunction(mmi_medply_listui_plst_organize_end, KEY_EVENT_UP);
        }        
    }
    else
    {
        MMI_ASSERT(g_listui_cntx_p->list_info.is_hold == MMI_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_organize_get_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_organize_get_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /* set hold flag */
    g_listui_cntx_p->list_info.is_hold = MMI_TRUE;
    g_listui_cntx_p->list_info.hold_id = g_listui_cntx_p->list_info.highlight;
    LISTUI_DISABLE_DYNAMIC_LIST_CACHE;
    
    /* change soft key */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_CANCEL, 0);
    SetLeftSoftkeyFunction(mmi_medply_listui_organize_set_move, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_medply_listui_organize_cancel_move, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_organize_cancel_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_organize_cancel_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_listui_cntx_p->list_info.is_hold)
    {
        ret = srv_plst_plst_item_reorder_action_set_result(g_listui_cntx_p->srv_cntx.srv_hdlr, MMI_FALSE);
        g_listui_cntx_p->list_info.is_hold = MMI_FALSE;
        g_listui_cntx_p->list_info.hold_id= 0;
        if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_plst_organize_error_quit(ret);
            return;
        }

        ChangeLeftSoftkey(STR_ID_MEDPLY_PLST_MOVE, 0);
        SetLeftSoftkeyFunction(mmi_medply_listui_organize_get_move, KEY_EVENT_UP);
        ChangeRightSoftkey(STR_GLOBAL_BACK, 0);            
        SetRightSoftkeyFunction(mmi_medply_listui_plst_organize_end, KEY_EVENT_UP);

        /*MAUI_02083186, entry dummy to assurance the list will be update*/
        mmi_frm_display_dummy_screen_ex(GRP_ID_MEDPLY_FTE_ORGANIZE, GLOBAL_SCR_DUMMY);
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_ORGANIZE, SCR_ID_MEDPLY_LISTUI_ORGANIZE);
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        MMI_ASSERT(g_listui_cntx_p->list_info.is_hold == MMI_TRUE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_listui_organize_disable_shortcut_callback
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U32 mmi_medply_listui_organize_disable_shortcut_callback(void)
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
 *  mmi_medply_listui_organize_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index      	[IN]  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_organize_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U16 format, img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ORGANIZE_HILITE_HDLR, 
                     index, g_listui_cntx_p->list_info.is_hold);

    if (g_listui_cntx_p->list_info.is_hold)
    {
        if (g_listui_cntx_p->list_info.hold_id != index)
        {
            /* MAUI_02186627 begin, Save highlight item in temp buffer */
            ret = mmi_medply_listui_get_orgnz_list_title(g_listui_cntx_p->srv_cntx.srv_hdlr,index,g_listui_item_buff);
            if (ret < SRV_PLST_OK)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_ORGANIZE_LIST_ITEM_TITLE, ret);
                mmi_ucs2ncpy((CHAR*) g_listui_item_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
                g_listui_item_image = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
            }
            else
            {
                ret = mmi_medply_listui_get_audio_format(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                         index, &format);
                if (ret >= SRV_PLST_OK)
                {
                    img_id = mmi_medply_util_get_file_icon(format);
                    g_listui_item_image = (PU8)GetImage(img_id);
                }
                else
                {
                    g_listui_item_image = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
                }
            }
            /* MAUI_02186627 end */
            g_listui_cntx_p->list_info.is_changed = MMI_TRUE;
            ret = srv_plst_plst_item_reorder_action(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                    g_listui_cntx_p->list_info.hold_id,index);
            g_listui_cntx_p->list_info.hold_id = index;
            if (ret < SRV_PLST_OK)
            {
                mmi_medply_listui_plst_organize_error_quit(ret);
                return;
            }
        }        
    }

    g_listui_cntx_p->list_info.highlight = index;    
}

#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prefix_search_begin
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_prefix_search_begin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->list_info.flag |= MMI_MEDPLY_LISTUI_IS_SEARCH;
    g_listui_cntx_p->list_info.search_scr_id = g_listui_cntx_p->list_info.list_scr_id;
    memset(g_prefix_search_buffer, 0, MAX_SUBMENU_CHARACTERS);
    ret = srv_plst_list_prefix_search_begin(g_listui_cntx_p->srv_cntx.srv_hdlr);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }
    g_listui_cntx_p->list_info.total = 0;
    mmi_medply_listui_entry_prefix_search();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_prefix_search_end
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_prefix_search_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_plst_list_prefix_search_end(g_listui_cntx_p->srv_cntx.srv_hdlr);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
    }
    g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_SEARCH;
    g_listui_cntx_p->list_info.search_scr_id = 0;
}

static BOOL mmi_medply_listui_appl_present_function(S32 *max_number)
{
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_prefix_srch_scr
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_prefix_srch_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RegisterCat200SearchFunction(mmi_medply_listui_do_prefix_search);

    /*
    wgui_cat201_register_language_changed_indicator(mmi_medply_listui_is_lang_changed);
    */

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /*
    ShowCategory201Screen(
        STR_GLOBAL_SEARCH,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_listui_cntx_p->list_info.total,
        mmi_medply_listui_prefix_search_get_item,
        NULL,
        0,
        0,
        (U8*) g_prefix_search_buffer,
        MAX_SUBMENU_CHARACTERS,
        //IMM_INPUT_TYPE_USER_SPECIFIC,
        IMM_INPUT_TYPE_SENTENCE,
        guiBuffer,
        g_dictionary_input_mode_medply);
    */

    Register_appl_present_function(mmi_medply_listui_appl_present_function);

    wgui_cat_register_get_flags_callback(mmi_medply_listui_common_list_disable_scrollbar);
    ShowCategory200Screen(
        STR_GLOBAL_SEARCH,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_listui_cntx_p->list_info.total,
        mmi_medply_listui_prefix_search_get_item,
        NULL,
        0,
        0,
        (U8*) g_prefix_search_buffer,
        MAX_SUBMENU_CHARACTERS,
        guiBuffer);

    SetCategory200LeftSoftkeyFunction(mmi_medply_listui_entry_search_option, KEY_EVENT_UP);
    SetCategory200RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_prefix_search
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_prefix_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH, NULL, 
                                   mmi_medply_listui_entry_prefix_search, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH, mmi_medply_listui_search_delete_callback);
    RegisterHighlightHandler(mmi_medply_listui_common_highlight_hdlr);
    
    mmi_medply_listui_show_prefix_srch_scr();    

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_listui_search_list_tap_callback);
#endif
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_list_item_selected_callback_all(mmi_medply_listui_entry_search_option);
#endif    
    
    SetLeftSoftkeyFunction(mmi_medply_listui_entry_search_option, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_multiadd_option
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static pBOOL mmi_medply_listui_prefix_search_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct display;
    S32 ret;
    U16 img_id;
    U16 format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    display.buff_size = MEDPLY_MAX_ITEM_LEN - 1;
    display.index = item_index;
    display.string_ptr = (U32)str_buff;
    ret = srv_plst_list_prefix_search_get_display(g_listui_cntx_p->srv_cntx.srv_hdlr,&display);
    switch(g_listui_cntx_p->list_info.list_type)
    {
    case LIST_TYPE_PLST_LIST:
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_ICON);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFIX_SEARCH_GET_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            break;
        }
        break;
    case LIST_TYPE_ARTIST_ALBUM_LIST:
    case LIST_TYPE_ALBUM_LIST:
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_PLST_DETAILS_ALBUM);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFIX_SEARCH_GET_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            break;
        }
        break;
    case LIST_TYPE_ARTIST_LIST:
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_PLST_DETAILS_ARTIST);
        if (ret < SRV_PLST_OK)
        {
           MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFIX_SEARCH_GET_ITEM_TITLE, ret);
           mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
           break;
        }    
        break;
    case LIST_TYPE_GENRE_LIST:
        *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_PLST_DETAILS_GENRE);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFIX_SEARCH_GET_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            break;
        }     
        break;
    case LIST_TYPE_ALL_SONG_LIST:
    case LIST_TYPE_PLST_SONG_LIST:
    case LIST_TYPE_CATEGORY_SONG_LIST:
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFIX_SEARCH_GET_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
            break;
        }
        ret = mmi_medply_listui_get_audio_format(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                 item_index, &format);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFIX_SEARCH_GET_ITEM_FORMAT, ret);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
            break;
        }
        img_id = mmi_medply_util_get_file_icon(format);
        *img_buff_p = (PU8)GetImage(img_id);
        break;
        
    case LIST_TYPE_ALL_VIDEO_LIST:
        if (ret < SRV_PLST_OK)
        {
           MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFIX_SEARCH_GET_ITEM_TITLE, ret);
            mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) get_string(STR_GLOBAL_ERROR),MEDPLY_MAX_ITEM_LEN - 1);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
           break;
        }
        ret = mmi_medply_listui_get_video_format(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                 item_index, &format);
        if (ret < SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_PREFIX_SEARCH_GET_ITEM_FORMAT, ret);
            *img_buff_p = (PU8)GetImage(IMG_ID_MEDPLY_FILE_UNKNOWN_ICON);
            break;
        }
        img_id = mmi_medply_util_get_file_icon(format);
        *img_buff_p = (PU8)GetImage(img_id);
        break;
    default:
        ASSERT(0); /*not support list type*/
        break; 
    }
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_do_prefix_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_listui_do_prefix_search(U8* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if ((0 == str[0] && 0 == str[1]))
    {
        return 0;
    }*/
    ret = srv_plst_list_prefix_search_do_search(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                      (U32)str, &g_listui_cntx_p->list_info.total);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DO_PREFIX_SEARCH, 
                     ret, g_listui_cntx_p->list_info.total);
    return g_listui_cntx_p->list_info.total;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_search_delete_callback
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
mmi_ret mmi_medply_listui_search_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_medply_listui_prefix_search_end();
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_search_option
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_search_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_listui_cntx_p->list_info.list_type)
    {
    case LIST_TYPE_ALL_SONG_LIST:
    case LIST_TYPE_ALL_VIDEO_LIST:
    case LIST_TYPE_CATEGORY_SONG_LIST:
    case LIST_TYPE_PLST_SONG_LIST:
        mmi_medply_listui_entry_song_list_search_option();
        break;
    case LIST_TYPE_ARTIST_LIST:
    case LIST_TYPE_ALBUM_LIST:
    case LIST_TYPE_GENRE_LIST:
    case LIST_TYPE_ARTIST_ALBUM_LIST:
        mmi_medply_listui_entry_type_list_search_option();
        break;
    default:
        MMI_ASSERT(0);
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_song_list_search_option
 * DESCRIPTION
 *  apply picked file, fill global context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_song_list_search_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_MEDPLY_FTE_FILE_LIST_SEARCH_OPTION,
                               MMI_TRUE,
                               (void*)MEDPLY_MENU_CUI_FILE_LIST_SEARCH_OPT);
    cui_menu_run(menu_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_type_list_search_option
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_type_list_search_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_MEDPLY_FTE_TYPE_LIST_SEARCH_OPTION,
                               MMI_FALSE,
                               (void*)MEDPLY_MENU_CUI_TYPE_LIST_SEARCH_OPT);
    cui_menu_run(menu_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_song_list_search_option_cui_proc
 * DESCRIPTION
 *  Menu CUI callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_song_list_search_option_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLAY, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_SEND, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DELETE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_USE, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DETAILS, MMI_FALSE);

            /*check list number*/
            if (0 == g_listui_cntx_p->list_info.total)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DETAILS, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_SEND, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_USE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DELETE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
            }
            else
            {
                /* get current file path */
                mmi_medply_listui_get_path(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                           g_listui_cntx_p->list_info.highlight, 
                                           g_listui_cntx_p->list_info.curr_hilite_path);


                fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_SEND, g_listui_cntx_p->list_info.curr_hilite_path, MMI_TRUE);
                fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_USE, g_listui_cntx_p->list_info.curr_hilite_path, MMI_FALSE);
            }

            /*check list type*/
            switch(g_listui_cntx_p->list_info.list_type)
            {
            case LIST_TYPE_PLST_SONG_LIST:
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_DELETE, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST, MMI_TRUE);
                if (SRV_PLST_DEF_ALL_KURO_LIST == g_listui_cntx_p->list_info.def_list_type ||
                    SRV_PLST_DEF_RECENTLY_PLST == g_listui_cntx_p->list_info.def_list_type ||
                    SRV_PLST_DEF_MOST_PLST == g_listui_cntx_p->list_info.def_list_type)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                }
                
                //11/22
                if (mmi_medply_shell_is_registered())
                {
                    if ((SRV_PLST_DEF_RECENTLY_PLST == g_listui_cntx_p->list_info.def_list_type) ||
                        (SRV_PLST_DEF_MOST_PLST == g_listui_cntx_p->list_info.def_list_type))
                    {
                        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLAY, MMI_TRUE);
                    }
                }
                break;
            case LIST_TYPE_ALL_VIDEO_LIST:
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                break;
            case LIST_TYPE_CATEGORY_SONG_LIST:
            case LIST_TYPE_ALL_SONG_LIST:
            case LIST_TYPE_ARTIST_LIST:
            case LIST_TYPE_ALBUM_LIST:
            case LIST_TYPE_GENRE_LIST:
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE, MMI_TRUE);
                break;
            default:
                /*Do not support other type*/
                ASSERT(0);
                break;
            }

            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_FILE_PLAY:
                    mmi_medply_listui_file_play();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_SEND:
                    fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_SEND, g_listui_cntx_p->list_info.curr_hilite_path, MMI_TRUE);
                    //if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
                    //{
                    //    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
                    //}
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_DELETE:
                    mmi_medply_listui_common_delete_req();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_PLST_REMOVE:
                    mmi_medply_listui_common_remove_req();
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_USE:
                    fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_USE, g_listui_cntx_p->list_info.curr_hilite_path, MMI_FALSE);
                    break;
                case MENU_ID_MEDPLY_FTE_FILE_ADDTO_PLST:
                    mmi_medply_listui_addto_plst();
                    break;
                
                case MENU_ID_MEDPLY_FTE_FILE_DETAILS:
                    mmi_medply_listui_entry_details();
                    break;
                default:
                    fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_SEND, g_listui_cntx_p->list_info.curr_hilite_path, MMI_TRUE);
                    fmgr_forward_sub_option_handler(menu_evt, MENU_ID_MEDPLY_FTE_FILE_USE, g_listui_cntx_p->list_info.curr_hilite_path, MMI_FALSE);
                    //wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, GRP_ID_MEDPLY_FTE_SUB_MENU);
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /* Close CUI */
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    /* editor options */
    wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, GRP_ID_MEDPLY_FTE_SUB_MENU);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_type_list_search_option_cui_proc
 * DESCRIPTION
 *  Menu CUI callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_type_list_search_option_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            /* config option items*/
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_OPEN, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_PLAY, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST, MMI_FALSE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_DELETE, MMI_FALSE);
        #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM, MMI_FALSE);
        #else
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM, MMI_TRUE);
        #endif

            /*check list number*/
            if (0 == g_listui_cntx_p->list_info.total)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_OPEN, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_DELETE, MMI_TRUE);
            #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM, MMI_TRUE);
            #endif
            }

            /* check list type*/
            /*only show cover flow and edit album image option in all albums list*/
            if (LIST_TYPE_ALBUM_LIST != g_listui_cntx_p->list_info.list_type)
            {
            #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM, MMI_TRUE);
            #endif
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_TYPE_OPEN:
                    mmi_medply_listui_type_open_list();
                    break;
                case MENU_ID_MEDPLY_FTE_TYPE_PLAY:
                    mmi_medply_listui_type_play();
                    break;
                case MENU_ID_MEDPLY_FTE_TYPE_ADDTO_PLST:
                    mmi_medply_listui_addto_plst();
                    break;
                case MENU_ID_MEDPLY_FTE_TYPE_DELETE:
                    mmi_medply_listui_common_delete_req();
                    break;
            #ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
                case MENU_ID_MEDPLY_FTE_TYPE_EDIT_ALBUM:
                    mmi_medply_listui_edit_elbum();
                    break;
            #endif /* __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__ */
                default:
                    //wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, GRP_ID_MEDPLY_FTE_SUB_MENU);
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /* Close CUI */
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }
    
    /* editor options */
    wgui_inputs_options_menu_handler((mmi_event_struct*)menu_evt, GRP_ID_MEDPLY_FTE_SUB_MENU);

    return MMI_RET_OK;
}



#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/


#define __LISTUI_DETAILS
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_entry_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8  file_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*get path*/
    ret = mmi_medply_listui_get_path(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                     g_listui_cntx_p->list_info.highlight, g_listui_cntx_p->details_info.path);

    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = srv_plst_media_get_id(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                g_listui_cntx_p->list_info.highlight, 
                                &g_listui_cntx_p->details_info.media_id);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    /*check is audio file or video file*/
    if (LIST_TYPE_ALL_VIDEO_LIST == g_listui_cntx_p->list_info.list_type)
    {
        g_listui_cntx_p->details_info.format = mmi_medply_util_is_service_support_format(g_listui_cntx_p->details_info.path, MMI_TRUE);
    }
    else
    {
        g_listui_cntx_p->details_info.format = mmi_medply_util_is_service_support_format(g_listui_cntx_p->details_info.path, MMI_FALSE);
    }
    file_type = media_file_info_table[g_listui_cntx_p->details_info.format].file_type;
    if (MEDPLY_TYPE_AUDIO == file_type)
    {
        g_listui_cntx_p->details_info.is_audio = 1;
    }
    else
    {
        g_listui_cntx_p->details_info.is_audio = 0;
    }

    /*allocate memory and get details*/
    g_listui_cntx_p->details_info.raw_p = kal_adm_alloc(g_medply.adm_id_p, sizeof(srv_plst_media_details_struct));

    if (g_listui_cntx_p->details_info.is_audio)
    {
        /*ret = mmi_medply_listui_get_details(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                    g_listui_cntx_p->list_info.highlight, g_listui_cntx_p->details_info.raw_p);*/
        ret = srv_plst_media_get_details(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                         g_listui_cntx_p->details_info.media_id, 
                                         g_listui_cntx_p->details_info.raw_p);
        if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_popup_error(ret);
            kal_adm_free(g_medply.adm_id_p, g_listui_cntx_p->details_info.raw_p);
            g_listui_cntx_p->details_info.raw_p = 0;
            memset(&(g_listui_cntx_p->details_info), 0, sizeof(mmi_medply_listui_details_info_struct));
            return;
        }
    }    

    /*prepare memory and view data*/
    g_listui_cntx_p->details_info.view_p = kal_adm_alloc(g_medply.adm_id_p,
                                                      sizeof(mmi_medply_listui_details_view_struct));

    memset(g_listui_cntx_p->details_info.view_p, 0, sizeof(mmi_medply_listui_details_view_struct));
    mmi_medply_listui_details_prepare_display();

    mmi_medply_listui_entry_preview_details();
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
    }
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_preview_details
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_entry_preview_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_DETAILS, NULL, 
                                   mmi_medply_listui_entry_preview_details, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                SCR_ID_MEDPLY_LISTUI_DETAILS, 
                                mmi_medply_listui_details_delete_callback);
   
    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_details_highlight_hdlr);

    if (g_listui_cntx_p->details_info.is_audio)
    {
        mmi_medply_listui_show_preview_details_scr(g_listui_cntx_p->details_info.view_p);
    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
        SetLeftSoftkeyFunction(mmi_medply_listui_edit_details, KEY_EVENT_UP);
    #endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/
    }
    else
    {
        mmi_medply_listui_show_preview_video_details_scr(g_listui_cntx_p->details_info.view_p);
    }

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medplay_listui_get_extern_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_get_details_extern(UI_string_type path, mmi_medply_listui_details_view_struct* view_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs;
    U32 duration = 0, size = 0;
    U16 hour= 0, min = 0, sec = 0;
    mdi_result result = MDI_AUDIO_SUCCESS;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    mdi_video_info_struct vdo_info;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* fill "local". */
    srv_fmgr_drv_get_name((U8)(path[0]), (WCHAR*)g_listui_cntx_p->details_info.view_p->local, MEDPLY_MAX_FILE_LEN - 1);

    /* get file size. */
    fs = DRM_open_file((PU16)path, FS_READ_ONLY, DRM_PERMISSION_NONE);    
    if (fs < 0)
    {
        return;
    }
    DRM_file_size(fs, &size);
    DRM_close_file(fs);

    /* fill "size". */
    if (size >= 1024*1024)
    {
        size = size/1024 ;
        kal_wsprintf((kal_wchar*)g_listui_cntx_p->details_info.view_p->size, 
                     "%d.%dM", size / 1024, (size % 1024) / 103);
    }
    else if (size >= 1024)
    {
        kal_wsprintf((kal_wchar*)g_listui_cntx_p->details_info.view_p->size, 
                     "%d.%dK", size / 1024, (size % 1024) / 103);
    }
    else
    {
        kal_wsprintf((kal_wchar*)g_listui_cntx_p->details_info.view_p->size, 
                     "%dB", size);
    }
   
    /* Hide duration for unsupport format */
    if ((g_listui_cntx_p->details_info.format > MEDPLY_FORMAT_NONE) &&
        (g_listui_cntx_p->details_info.format < MEDPLY_FORMAT_TOTAL))
    {
        if (0 == g_listui_cntx_p->details_info.view_p->duration[0])
        {
            /* fill "duration" if it is empty. */
            if (g_listui_cntx_p->details_info.is_audio)
            {
                mdi_audio_get_duration((void*)path, &duration);
            }
            else
            {
                result = mdi_audio_get_mp4_duration((void*)path, &duration);
            /* Use video API to get duration only when video is supported */
            #ifdef __MMI_VIDEO_PLAY_SUPPORT__
                if (result < 0)
                {
                    /* If fail to get duration from mdi_audio_get_mp4_duration open the clip and get the duration */
                    result = mdi_video_ply_open_clip_file(0, (CHAR*)path, &vdo_info);
                    if( result < 0)
                    {
                        /* some error in getting the duration, better set the duration to 0 */
                        duration = 0;
                    }
                    else
                    {
                        duration = vdo_info.total_time_duration;
                        mdi_video_ply_close_clip_file();
                    }
                }
            #endif
            }
            duration += 500;
            duration /= 1000;
            if (duration < 3600)
            {
                min = duration / 60;
                sec = duration % 60;
                kal_wsprintf((kal_wchar*)g_listui_cntx_p->details_info.view_p->duration, "%02d:%02d", min, sec);
            }
            else
            {
                hour = duration / 3600;
                min = (duration - hour * 3600) / 60;
                sec = (duration - hour * 3600) % 60;                
                kal_wsprintf((kal_wchar*)(kal_wchar*)g_listui_cntx_p->details_info.view_p->duration, 
                              "%d:%02d:%02d", hour, min, sec);
            }
            
        }
    }
    else
    {
        g_listui_cntx_p->details_info.view_p->duration[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_details_prepare_display
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_details_prepare_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_listui_details_view_struct *view_data_p;
    srv_plst_media_details_struct         *raw_data_p;
    CHAR* filename_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    view_data_p = g_listui_cntx_p->details_info.view_p;
    raw_data_p = g_listui_cntx_p->details_info.raw_p;
    
    mmi_medply_listui_get_details_extern(g_listui_cntx_p->details_info.path, view_data_p);

    if(g_listui_cntx_p->details_info.is_audio)
    {
        mmi_ucs2ncpy((CHAR*)view_data_p->title, (CHAR*)raw_data_p->title, MMI_MEDPLY_MAX_TITLE_LEN);
        mmi_ucs2ncpy((CHAR*)view_data_p->album, (CHAR*)raw_data_p->album, MMI_MEDPLY_MAX_ALBUM_LEN);
        mmi_ucs2ncpy((CHAR*)view_data_p->artist, (CHAR*)raw_data_p->artist, MMI_MEDPLY_MAX_ARTISRT_LEN);
        mmi_ucs2ncpy((CHAR*)view_data_p->author, (CHAR*)raw_data_p->author, MMI_MEDPLY_MAX_AUTHOR_LEN);
        mmi_ucs2ncpy((CHAR*)view_data_p->copyrights, (CHAR*)raw_data_p->copyrights , MMI_MEDPLY_MAX_COPYRIGHTS_LEN);
        mmi_ucs2ncpy((CHAR*)view_data_p->description, (CHAR*)raw_data_p->description, MMI_MEDPLY_MAX_DESCRIPTION_LEN);
        mmi_ucs2ncpy((CHAR*)view_data_p->filename, (CHAR*)raw_data_p->filename , MEDPLY_MAX_FILE_LEN - 1);
        mmi_ucs2ncpy((CHAR*)view_data_p->genre, (CHAR*)raw_data_p->genre, MMI_MEDPLY_MAX_GENRE_LEN);

        if (raw_data_p->year >= 0 && raw_data_p->year <= 9999)
        {
            kal_wsprintf(view_data_p->year, "%d", raw_data_p->year);
        }
        else
        {
            view_data_p->year[0] = 0;
        }
        if (raw_data_p->play_count <= 65535)
        {
            kal_wsprintf(view_data_p->play_count, "%d", raw_data_p->play_count);
        }
        else
        {
            view_data_p->play_count[0] = 0;
        }
        if (raw_data_p->track_num>= 0 && raw_data_p->track_num <= 9999)
        {
            kal_wsprintf(view_data_p->track_num, "%d", raw_data_p->track_num);
        }
        else
        {
            view_data_p->track_num[0] = 0;
        }

        {
            if (raw_data_p->user_rating > 5)
            {
                raw_data_p->user_rating = 5;
            }
            mmi_medply_listui_get_rating_string(view_data_p->user_rating, raw_data_p->user_rating);
        }        
        /*channel*/
        if (raw_data_p->channel_num != 0)
        {
            if (raw_data_p->channel_num == 1)
            {
                mmi_ucs2ncpy((CHAR*)view_data_p->channel_num,
                             (const CHAR*)GetString(STR_ID_MEDPLY_PLST_DETAILS_MONO), 20 - 1);
            }
            else
            {
                mmi_ucs2ncpy((CHAR*)view_data_p->channel_num,
                            (const CHAR*)GetString(STR_ID_MEDPLY_PLST_DETAILS_STEREO), 20 - 1);
            }
        }
        /*quality*/
        if (raw_data_p->bits_rate > 0 || raw_data_p->sample_rate > 0)
        {
            UI_character_type temp[30];
            U16 bitrate_fraction_1, bitrate_fraction_2, bitrate_fraction_3;
            U16 samplerate_fraction_1, samplerate_fraction_2, samplerate_fraction_3;

            if (raw_data_p->bits_rate > 0)
            {
                bitrate_fraction_1 = raw_data_p->bits_rate / 100;
                bitrate_fraction_1 = bitrate_fraction_1 - (bitrate_fraction_1 / 10) * 10;
                bitrate_fraction_2 = raw_data_p->bits_rate / 10;
                bitrate_fraction_2 = bitrate_fraction_2 - (bitrate_fraction_2 / 10) * 10;
                bitrate_fraction_3 = raw_data_p->bits_rate - (raw_data_p->bits_rate / 10) * 10 ;
                if (bitrate_fraction_3)
                {
                    kal_wsprintf((kal_wchar*)view_data_p->quality, "%d.%d%d%dkbps", raw_data_p->bits_rate / 1000, bitrate_fraction_1, bitrate_fraction_2, bitrate_fraction_3);
                }
                else if (bitrate_fraction_2)
                {
                    kal_wsprintf((kal_wchar*)view_data_p->quality, "%d.%d%dkbps", raw_data_p->bits_rate / 1000, bitrate_fraction_1, bitrate_fraction_2);
                }
                else if (bitrate_fraction_1)
                {
                    kal_wsprintf((kal_wchar*)view_data_p->quality, "%d.%dkbps", raw_data_p->bits_rate / 1000, bitrate_fraction_1);
                }
                else
                {
                    kal_wsprintf((kal_wchar*)view_data_p->quality, "%dkbps", raw_data_p->bits_rate / 1000);
                }

                if (raw_data_p->sample_rate > 0)
                {
                    mmi_ucs2ncat((CHAR*)view_data_p->quality, (const CHAR*)L" / ", 3);
                }
            }

            if (raw_data_p->sample_rate > 0)
            {
                samplerate_fraction_1 = raw_data_p->sample_rate / 100;
                samplerate_fraction_1 = samplerate_fraction_1 - (samplerate_fraction_1 / 10) * 10;
                samplerate_fraction_2 = raw_data_p->sample_rate / 10;
                samplerate_fraction_2 = samplerate_fraction_2 - (samplerate_fraction_2 / 10) * 10;
                samplerate_fraction_3 = raw_data_p->sample_rate - (raw_data_p->sample_rate / 10) * 10 ;

                if (samplerate_fraction_3)
                {
                    kal_wsprintf((kal_wchar*) temp, "%d.%d%d%dkHz", raw_data_p->sample_rate / 1000, samplerate_fraction_1, samplerate_fraction_2, samplerate_fraction_3);
                }
                else if (samplerate_fraction_2)
                {
                    kal_wsprintf((kal_wchar*) temp, "%d.%d%dkHz", raw_data_p->sample_rate / 1000, samplerate_fraction_1, samplerate_fraction_2);
                }
                else if (samplerate_fraction_1)
                {
                    kal_wsprintf((kal_wchar*) temp, "%d.%dkHz", raw_data_p->sample_rate / 1000, samplerate_fraction_1);
                }
                else
                {
                    kal_wsprintf((kal_wchar*) temp, "%dkHz", raw_data_p->sample_rate / 1000);
                }
                mmi_ucs2ncat((CHAR*)view_data_p->quality, (const CHAR*)temp, mmi_ucs2strlen((const CHAR*)temp));
            }
        }
    }
    else
    {
        
        srv_fmgr_drv_get_name((U8)(g_listui_cntx_p->details_info.path[0]), 
                                (WCHAR*)view_data_p->local, 
                                (MEDPLY_MAX_FILE_LEN - 1));
        /* fill "filename". */
        filename_p = mmi_ucs2rchr((const CHAR*)g_listui_cntx_p->details_info.path, (WCHAR)L'\\');

        if (filename_p != NULL)
        {
            /* No short name in file manager service */
            mmi_ucs2ncpy((CHAR*)view_data_p->filename, 
                         (const CHAR*)(filename_p+2), MEDPLY_MAX_FILE_LEN - 1);
            srv_fmgr_path_hide_extension((WCHAR*)view_data_p->filename);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_make_date_time_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_get_rating_string(UI_string_type out_str, U8 user_rating)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rating_string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (user_rating)
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
        rating_string_id = STR_ID_MEDPLY_PLST_DETAILS_STAR_0;
        //MMI_ASSERT(user_rating <= 5);
        break;
    }
    mmi_ucs2ncpy((CHAR*)out_str, (CHAR*)GetString(rating_string_id), MMI_MEDPLY_MAX_USER_RATING_LEN - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_preview_details_scr
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_preview_details_scr(const mmi_medply_listui_details_view_struct* view_data_p)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 item_count = 0;
    U16 lsk_str_id = 0;

    CHAR *fields[MEDPLY_DETAIL_TOTAL];
    U16 item_icons[MEDPLY_DETAIL_TOTAL];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* filename. */           
    if (view_data_p->filename[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->filename;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_GLOBAL_FILENAME;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_FILENAME;
    }
    /* title. */
    if (view_data_p->title[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->title;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_TITLE;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_TITLE;
    }
    /* artist. */
    if (view_data_p->artist[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->artist;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_ARTIST;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_ARTIST;
    }
    /* album. */
    if (view_data_p->album[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->album;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_ALBUM;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_ALBUM;
    }
    /* author. */
    if (view_data_p->author[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->author;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_AUTHOR;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_AUTHOR;
    }
    /* genre */
    if (view_data_p->genre[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->genre;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_GENRE;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_GENRE;
    }
    /* copyrights. */
    if (view_data_p->copyrights[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->copyrights;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS;
    }    
    /* description. */
    if (view_data_p->description[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->description;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_DESCRIPTION;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_DESCRIPTION;
    }
    /* year. */
    if (view_data_p->year[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->year;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_YEAR;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_YEAR;
    }
    /* track number. */
    if (view_data_p->track_num[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->track_num;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_TRACK_NUM;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_TRACK_NUM;
    }	
    /* duration */
    if (view_data_p->duration[0] != 0)
    {    
        fields[item_count] = (CHAR*)view_data_p->duration;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_DURATION;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_DURATION;        
    }
    /* size */
    if (view_data_p->size[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->size;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_SIZE;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_SIZE;
    }    
    /* quality */
    if (view_data_p->quality[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->quality;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_QUALITY;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_QUALITY;
    }
    /* channel */
    if (view_data_p->channel_num[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->channel_num;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_CHANNEL;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_CHANNEL;
    }

    /* user rating. */
    if (view_data_p->user_rating[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->user_rating;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_USER_RATING;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_USER_RATING;
    }

    /* local. */
    if (view_data_p->local[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->local;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_LOCAL;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_LOCAL;
    }

    #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
        lsk_str_id = STR_GLOBAL_EDIT,
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
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_preview_details_scr
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_preview_video_details_scr(const mmi_medply_listui_details_view_struct* view_data_p)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 item_count = 0;

    CHAR *fields[MEDPLY_DETAIL_TOTAL];
    U16 item_icons[MEDPLY_DETAIL_TOTAL];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    /* filename. */           
    if (view_data_p->filename[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->filename;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_GLOBAL_FILENAME;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_FILENAME;
    }
    /* duration */
    if (view_data_p->duration[0] != 0)
    {    
        fields[item_count] = (CHAR*)view_data_p->duration;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_DURATION;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_DURATION;        
    }
    /* size */
    if (view_data_p->size[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->size;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_SIZE;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_SIZE;
    }    
    /* local. */
    if (view_data_p->local[0] != 0)
    {
        fields[item_count] = (CHAR*)view_data_p->local;
        g_listui_cntx_p->details_info.details_item_id[item_count] = STR_ID_MEDPLY_PLST_DETAILS_LOCAL;
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_LOCAL;
    }
    ShowCategory84Screen(
        STR_GLOBAL_DETAILS,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),    /* title text and icon */
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        item_count,
        (U8 **) fields,
        item_icons,
        0,
        0,
        guiBuffer);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_details_highlight_hdlr
 * DESCRIPTION
 *  change title as highlight text
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_details_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeTitleString((PU8)GetString(g_listui_cntx_p->details_info.details_item_id[index]));
    draw_title();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_search_delete_callback
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
mmi_ret mmi_medply_listui_details_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_medply_listui_details_preview_delete_hdlr();
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_details_preview_delete_hdlr
 * DESCRIPTION
 *  preview screen delete callback fucntion. free all asm memory and destory context.
 * PARAMETERS
 *  in_param       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static void mmi_medply_listui_details_preview_delete_hdlr(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_listui_cntx_p->details_info.raw_p)
    {
        kal_adm_free(g_medply.adm_id_p, g_listui_cntx_p->details_info.raw_p);
        //MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.db_raw_data_p, __LINE__);
        g_listui_cntx_p->details_info.raw_p = NULL;
    }

    if (g_listui_cntx_p->details_info.view_p)
    {
        kal_adm_free(g_medply.adm_id_p, g_listui_cntx_p->details_info.view_p);
        //MEM_TRC_FREE(plst_cntx_p->ui_cntx.details_cntx.preview_data_p, __LINE__);
        g_listui_cntx_p->details_info.view_p = NULL;
    }

    memset(&(g_listui_cntx_p->details_info), 0, sizeof(mmi_medply_listui_details_info_struct));
    g_listui_cntx_p->details_info.rating_update_flag = 1;
}

#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__

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
mmi_ret mmi_medply_listui_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
   
    case EVT_ID_CUI_INLINE_NOTIFY:
    {
        cui_event_inline_notify_struct *inline_evt = (cui_event_inline_notify_struct *)evt;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_NOTIFY,inline_evt->sender_id ,inline_evt->event_type ,__LINE__);

        switch(inline_evt->event_type)
        {
        case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
            index = (U16)((inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE) - 1)/2;
            
            g_listui_cntx_p->details_info.edit_index = (U16)index;
            g_listui_cntx_p->details_info.highlighted_item = (U16)index;
            break;

        default:
            break;
        }
        break;
    }
    
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
    {
        cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct *)evt;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ACTIVE,inline_evt->sender_id ,__LINE__);
        
        if (g_listui_cntx_p->details_info.modify_flag != 0)
        {
            cui_inline_set_screen_attributes(inline_evt->sender_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
        } 
        break;
    }
    
    case EVT_ID_CUI_INLINE_CSK_PRESS: //only enabled when disable done
        break;
    
    case EVT_ID_CUI_INLINE_SET_KEY:
    {
        cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
        index = inline_evt->item_id;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SET_KEY,inline_evt->sender_id ,index ,__LINE__);

        switch(index)
        {
        case MEDPLY_DETAILS_META_USER_RATING_DISPLAY:
            cui_inline_set_softkey_text(
                            inline_evt->sender_id, 
                            index, 
                            MMI_LEFT_SOFTKEY, 
                            STR_GLOBAL_EDIT);
            wgui_inline_set_lsk_function(mmi_medply_listui_entry_details_edit_rating);
            cui_inline_set_softkey_icon(
                            inline_evt->sender_id, 
                            index, 
                            MMI_CENTER_SOFTKEY, 
                            IMG_GLOBAL_COMMON_CSK);                        
            SetCenterSoftkeyFunction(mmi_medply_listui_entry_details_edit_rating, KEY_EVENT_UP);
            break;
                   
        default:
            cui_inline_set_softkey_text(
                            inline_evt->sender_id, 
                            index, 
                            MMI_LEFT_SOFTKEY, 
                            STR_GLOBAL_EDIT);
            wgui_inline_set_lsk_function(mmi_medply_listui_entry_details_edit_item);
            cui_inline_set_softkey_icon(
                            inline_evt->sender_id, 
                            index, 
                            MMI_CENTER_SOFTKEY, 
                            IMG_GLOBAL_COMMON_CSK);
                        
            SetCenterSoftkeyFunction(mmi_medply_listui_entry_details_edit_item, KEY_EVENT_UP);
            break;                    
        }
        break;
    }    
        
    case EVT_ID_CUI_INLINE_SUBMIT:
    {
        cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_SUBMIT,inline_evt->sender_id ,__LINE__);
        //mmi_medply_details_save_confirm();
        mmi_medply_listui_details_save_confirm();
        break;
    }

    case EVT_ID_CUI_INLINE_ABORT:      
    {
        cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*)evt;           
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ABORT,inline_evt->sender_id ,__LINE__);
        cui_inline_close(inline_evt->sender_id);
        mmi_medply_listui_exit_edit_details();
        break;
    }

    case EVT_ID_CUI_INLINE_GROUP_DEINIT:
    {
        mmi_medply_listui_exit_edit_details();
        g_listui_cntx_p->details_info.inline_gid = 0;
        break;
    }
        
    }
    
    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_edit_details
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_edit_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init details variables. */
    g_listui_cntx_p->details_info.highlighted_item = 0;
    g_listui_cntx_p->details_info.edit_index = 0;
    g_listui_cntx_p->details_info.modify_flag = 0;

    /* prepare memory to backup all data before edit. */
    g_listui_cntx_p->details_info.backup_p = 
        kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_listui_details_view_struct));
    MMI_ASSERT(NULL != g_listui_cntx_p->details_info.backup_p);

    memcpy(g_listui_cntx_p->details_info.backup_p, 
           g_listui_cntx_p->details_info.view_p, 
           sizeof(mmi_medply_listui_details_view_struct));
    g_listui_cntx_p->details_info.rate_index = g_listui_cntx_p->details_info.raw_p->user_rating;
    
    mmi_medply_listui_entry_edit_details();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_edit_details
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_edit_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->details_info.inline_gid = cui_inline_create(GRP_ID_MEDPLY_FTE_SUB_MENU, &mmi_medply_listui_inline_details_screen);
    if (g_listui_cntx_p->details_info.inline_gid > GRP_ID_INVALID)
    {
        cui_inline_set_title_icon(g_listui_cntx_p->details_info.inline_gid, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
        mmi_medply_listui_details_set_value(g_listui_cntx_p->details_info.inline_gid);
        cui_inline_run(g_listui_cntx_p->details_info.inline_gid);
        mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_DETAILS);
    }
    else
    {   
        mmi_medply_listui_popup_by_strid(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_details_set_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_details_set_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[MEDPLY_PLST_INLINE_ITEM_NUM];
    U16 item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* title. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_TITLE_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->title);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;
    
    /* artist. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_ARTIST_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->artist);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* album. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_ALBUM_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->album);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* genre */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_GENRE_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->genre);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* author. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_AUTHOR_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->author);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* description. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_DESCRIPTION_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->description);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* track number. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_TRACK_NUM_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->track_num);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* year. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_YEAR_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->year);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;

    /* rate. */
    cui_inline_set_value(inline_id, 
        MEDPLY_DETAILS_META_USER_RATING_DISPLAY, 
        g_listui_cntx_p->details_info.view_p->user_rating);
    item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
    item_icons[item_count++] = 0;
    
    cui_inline_set_icon_list(inline_id, &item_icons[0]);    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_exit_edit_details
 * DESCRIPTION
 *  edit screen delete callback handler.
 * PARAMETERS
 *  in_param		[IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static void mmi_medply_listui_exit_edit_details(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init details variables. */
    g_listui_cntx_p->details_info.highlighted_item = 0;
    g_listui_cntx_p->details_info.edit_index = 0;
    g_listui_cntx_p->details_info.modify_flag = 0;
    
    if (g_listui_cntx_p->details_info.backup_p)
    {
        kal_adm_free(g_medply.adm_id_p, g_listui_cntx_p->details_info.backup_p);
        g_listui_cntx_p->details_info.backup_p = NULL;
    }
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
static void mmi_medply_listui_entry_details_edit_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type initial_value = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&(g_listui_cntx_p->editor_cntx), 0, sizeof(mmi_medply_listui_editor_cntx_struct));
    
    switch (g_listui_cntx_p->details_info.edit_index)
    {
        case MEDPLY_DETAILS_META_TITLE:
            g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_TITLE_LEN;
            g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_TITLE;
            g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            g_listui_cntx_p->editor_cntx.original_string_p = g_listui_cntx_p->details_info.view_p->title;
            break;
        case MEDPLY_DETAILS_META_ARTIST:
            g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_ARTISRT_LEN;
            g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_ARTIST;
            g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            g_listui_cntx_p->editor_cntx.original_string_p = g_listui_cntx_p->details_info.view_p->artist;
            break;
        case MEDPLY_DETAILS_META_ALBUM:
            g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_ALBUM_LEN;
            g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_ALBUM;
            g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            g_listui_cntx_p->editor_cntx.original_string_p = g_listui_cntx_p->details_info.view_p->album;
            break;
        case MEDPLY_DETAILS_META_GENRE:
            g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_GENRE_LEN;
            g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_GENRE;
            g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            g_listui_cntx_p->editor_cntx.original_string_p = g_listui_cntx_p->details_info.view_p->genre;
            break;
        case MEDPLY_DETAILS_META_AUTHOR:
            g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_AUTHOR_LEN;
            g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_AUTHOR;
            g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            g_listui_cntx_p->editor_cntx.original_string_p = g_listui_cntx_p->details_info.view_p->author;
            break;
        case MEDPLY_DETAILS_META_DESCRIPTION:
            g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_DESCRIPTION_LEN;
            g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_DESCRIPTION;
            g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_EDIT_META_TEXT;
            g_listui_cntx_p->editor_cntx.original_string_p = g_listui_cntx_p->details_info.view_p->description;
            break;       
        case MEDPLY_DETAILS_META_TRACK_NUM:
            g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_TRACKNUM_LEN - 1;
            g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_TRACK_NUM;
            g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_EDIT_META_NUMERIC;
            g_listui_cntx_p->editor_cntx.original_string_p = g_listui_cntx_p->details_info.view_p->track_num;
            break;
        case MEDPLY_DETAILS_META_YEAR:
            g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_YEAR_LEN - 1;
            g_listui_cntx_p->editor_cntx.editor_title_id = STR_ID_MEDPLY_PLST_DETAILS_YEAR;
            g_listui_cntx_p->editor_cntx.editor_type = MMI_MEDPLY_EDITOR_EDIT_META_NUMERIC;
            g_listui_cntx_p->editor_cntx.original_string_p = g_listui_cntx_p->details_info.view_p->year;
            break;
        default:
            MMI_ASSERT(0);
    }


    //g_listui_cntx_p->editor_cntx.original_string_p = (UI_string_type)wgui_inline_items[g_listui_cntx_p->details_info.highlighted_item].text_p;
    if (g_listui_cntx_p->editor_cntx.limit > MMI_MEDPLY_MAX_EDITOR_LEN)
    {
        g_listui_cntx_p->editor_cntx.limit = MMI_MEDPLY_MAX_EDITOR_LEN;
    }

    if (g_listui_cntx_p->editor_cntx.editor_type > 0)
    {
        initial_value = g_listui_cntx_p->editor_cntx.original_string_p;
    }
    if (g_listui_cntx_p->editor_cntx.editor_type == MMI_MEDPLY_EDITOR_EDIT_META_TEXT)
    {
        g_listui_cntx_p->editor_cntx.done_func = mmi_medply_details_text_done_func;
    }
    else
    {
        g_listui_cntx_p->editor_cntx.done_func = mmi_medply_details_numeric_done_func;
    }

    if (initial_value != NULL)
    {
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                     (const CHAR*)initial_value, MMI_MEDPLY_MAX_EDITOR_LEN);
    }
    mmi_medply_listui_entry_editor();
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
static void mmi_medply_listui_entry_details_edit_rating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    U16 rating = 0;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_DETAIL_SET_RATE, NULL, 
                                   mmi_medply_listui_entry_details_edit_rating, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
   
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (guiBuffer == NULL)
    {
        if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
            (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_0)))
        {
            rating = 0;
        }
        else
        {
            if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_1_EXT)))
            {
                rating = 1;
            }
            else if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_2_EXT)))
            {
                rating = 2;
            }
            else if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_3_EXT)))
            {
                rating = 3;
            }
            else if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_4_EXT)))
            {
                rating = 4;
            }
            else if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_5_EXT)))
            {
                rating = 5;
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
        g_listui_cntx_p->details_info.rate_index = rating;
    }
    
    mmi_medply_listui_show_edit_rating_scr(g_listui_cntx_p->details_info.rate_index);
        
    RegisterHighlightHandler(mmi_medply_listui_set_rating_highlight_hdlr);
    SetLeftSoftkeyFunction(mmi_medply_listui_set_rating_done, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_edit_rating_scr
 * DESCRIPTION
 *  Show common option screen. 
 *  LSK:OK. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_edit_rating_scr(U8 index)
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
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    
    ShowCategory11Screen(
        STR_ID_MEDPLY_PLST_SET_RATING,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItems,
        nStrItemLists,
        (U16)index,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
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
static void mmi_medply_listui_set_rating_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->details_info.rate_index = (U8)index;
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
static void mmi_medply_listui_set_rating_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rating_string_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_MEDPLY_LISTUI_DETAIL_SET_RATE)
    {
        g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_RATING;
        switch (g_listui_cntx_p->details_info.rate_index)
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
            MMI_ASSERT(g_listui_cntx_p->details_info.rate_index <= 5);
        }
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->details_info.view_p->user_rating,
                     (const CHAR*)GetString(rating_string_id), MMI_MEDPLY_MAX_USER_RATING_LEN - 1);        
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_details_save_confirm_cnf_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_medply_listui_details_save_confirm_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_medply_listui_details_edit_save();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_medply_listui_details_edit_resaved();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
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
static void mmi_medply_listui_details_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Display confirm */
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_MEDPLY_FTE;
    confirm_arg.callback = mmi_medply_listui_details_save_confirm_cnf_callback;

    mmi_confirm_display((WCHAR*)get_string(STR_GLOBAL_SAVE_ASK),
                        MMI_EVENT_QUERY,
                        &confirm_arg);
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
static void mmi_medply_listui_details_edit_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 modify_flag = g_listui_cntx_p->details_info.modify_flag;
    U8  rating = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modify_flag & MEDPLY_DB_UPDATE_RATING)
    {
        if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
            (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_0)))
        {
            rating = 0;
        }
        else
        {
            if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
            (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_1_EXT)))
            {
                rating = 1;
            }
            else if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_2_EXT)))
            {
                rating = 2;
            }
            else if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_3_EXT)))
            {
                rating = 3;
            }
            else if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_4_EXT)))
            {
                rating = 4;
            }
            else if (!mmi_ucs2icmp((const CHAR*)g_listui_cntx_p->details_info.view_p->user_rating, 
                (const CHAR*)get_string(STR_ID_MEDPLY_PLST_DETAILS_STAR_5_EXT)))
            {
                rating = 5;
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
        g_listui_cntx_p->details_info.raw_p->user_rating = rating;
    }
    ret = srv_plst_get_active_plst_item_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                              &g_listui_cntx_p->playing.total);
    ret = srv_plst_media_update_details(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                        g_listui_cntx_p->details_info.media_id,
                                        g_listui_cntx_p->details_info.raw_p);
   
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        cui_inline_close(g_listui_cntx_p->details_info.inline_gid);
    }
    else
    {
        /* update last modified time. */
        g_listui_cntx_p->details_info.view_p->last_modified[0] = 0;
        mmi_medply_listui_details_make_date_string(
                g_listui_cntx_p->details_info.view_p->last_modified, 
                g_listui_cntx_p->details_info.raw_p->last_modified);
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
        cui_inline_close(g_listui_cntx_p->details_info.inline_gid);

        /* Check if need stop playing */
        {
            U32 total;
            ret = srv_plst_get_active_plst_item_count(g_listui_cntx_p->srv_cntx.srv_hdlr, &total);
            if ((0 == total) ||
                ((g_listui_cntx_p->playing.total >= total + 1) &&
                (g_listui_cntx_p->details_info.media_id == g_listui_cntx_p->playing.id)))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_STOP_PLAYING, 
                                 total, g_listui_cntx_p->playing.id);
                g_listui_cntx_p->playing.total = total;
                g_medply.media_type = MEDPLY_TYPE_NONE;
                mmi_medply_stop_playing();
                mmi_medply_plst_clear_context_variables();
            }
        }

        /*delete screen if category modified*/
        if (modify_flag & MEDPLY_DB_UPDATE_ALBUM)
        {
            if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU,SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS, MMI_FRM_NODE_ALL_FLAG) ||
                mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU,SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS, MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_DETAILS);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS);
                if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS);
                }
                if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS);
                }
            }
        }
        if (modify_flag & MEDPLY_DB_UPDATE_ARTIST)
        {
            if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS, MMI_FRM_NODE_ALL_FLAG) ||
                mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS, MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_DETAILS);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS);
                if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS);
                }
            }
        }
        if (modify_flag & MEDPLY_DB_UPDATE_GENRE)
        {
            if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU,SCR_ID_MEDPLY_LISTUI_ALL_GENRES, MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_DETAILS);
                mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_SONGS);
                if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_GENRES, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_GENRES);
                }
            }
        }
        /* update idle string if edited now playing file's details. */
        if (g_listui_cntx_p->details_info.media_id == g_listui_cntx_p->playing.id)
        {
            mmi_medply_util_fill_idle_display_str();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_details_listui_edit_resaved
 * DESCRIPTION
 *  resaved from backup data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_details_edit_resaved(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_listui_cntx_p->details_info.view_p, 
           g_listui_cntx_p->details_info.backup_p, 
           sizeof(mmi_medply_listui_details_view_struct));
    cui_inline_close(g_listui_cntx_p->details_info.inline_gid);
}


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
static void mmi_medply_listui_details_make_date_string(UI_string_type out_string, srv_plst_time_struct time)
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
 *  mmi_medply_details_numeric_done_func
 * DESCRIPTION
 *  done function for edit numeric column.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_details_numeric_done_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MEDPLY_PLST_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_details_check_modification();

    if (ret < MEDPLY_PLST_NO_ERROR)
    {
        mmi_medply_plst_display_popup(ret, NULL);
        return MMI_FALSE;
    }
    return MMI_TRUE;
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
static MMI_BOOL mmi_medply_details_text_done_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MEDPLY_PLST_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_details_check_modification();

    if (ret < MEDPLY_PLST_NO_ERROR)
    {
        mmi_medply_plst_display_popup(ret, NULL);
        return MMI_FALSE;
    }
    return MMI_TRUE;
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
    if (mmi_ucs2ncmp((const CHAR*)g_listui_cntx_p->editor_cntx.original_string_p,
                     (const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer, 
                     g_listui_cntx_p->editor_cntx.limit))
    {
        switch (g_listui_cntx_p->details_info.edit_index)
        {
            case MEDPLY_DETAILS_META_TITLE:
                g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_TITLE;
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->details_info.raw_p->title,
                             (const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                             g_listui_cntx_p->editor_cntx.limit);
                break;
            case MEDPLY_DETAILS_META_ARTIST:
                g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_ARTIST;
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->details_info.raw_p->artist,
                             (const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                             g_listui_cntx_p->editor_cntx.limit);
                break;
            case MEDPLY_DETAILS_META_ALBUM:
                g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_ALBUM;
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->details_info.raw_p->album,
                             (const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                             g_listui_cntx_p->editor_cntx.limit);
                break;
            case MEDPLY_DETAILS_META_GENRE:
                g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_GENRE;
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->details_info.raw_p->genre,
                             (const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                             g_listui_cntx_p->editor_cntx.limit);
                break;
            case MEDPLY_DETAILS_META_AUTHOR:
                g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_AUTHOR;
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->details_info.raw_p->author,
                             (const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                             g_listui_cntx_p->editor_cntx.limit);
                break;
            case MEDPLY_DETAILS_META_DESCRIPTION: 
                g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_DESCRIPTION;
                mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->details_info.raw_p->description,
                             (const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer,
                             g_listui_cntx_p->editor_cntx.limit);
                break;
            case MEDPLY_DETAILS_META_TRACK_NUM:
                {
                    if (mmi_ucs2strlen((const CHAR*) g_listui_cntx_p->editor_cntx.editor_buffer) > 0)
                    {   
                        S16 new_track_num = 0;
                        new_track_num = (S16)app_ucs2_wtoi(g_listui_cntx_p->editor_cntx.editor_buffer);
                    
                        if (new_track_num > 0)
                        {
                            g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_TRACKNUM;
                            g_listui_cntx_p->details_info.raw_p->track_num = new_track_num;
                            app_ucs2_itow(new_track_num, g_listui_cntx_p->editor_cntx.editor_buffer, 10);
                        }
                        else
                        {
                            /* invalid input. */
                            ret = MEDPLY_PLST_ERR_INVALID_INPUT;
                        }
                    }
                    else
                    {
                        g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_TRACKNUM;
                        g_listui_cntx_p->details_info.raw_p->track_num = -1;
                    }
                    
                }
                break;
            case MEDPLY_DETAILS_META_YEAR:
                {
                    if (mmi_ucs2strlen((const CHAR*) g_listui_cntx_p->editor_cntx.editor_buffer) > 0)
                    {                    
                        S16 new_year = 0;
                        new_year = (S16)app_ucs2_wtoi(g_listui_cntx_p->editor_cntx.editor_buffer);

                        if (new_year >= 0)
                        {
                            g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_YEAR;
                            g_listui_cntx_p->details_info.raw_p->year = new_year;
                            app_ucs2_itow(new_year, g_listui_cntx_p->editor_cntx.editor_buffer, 10);
                        }
                        else
                        {
                            /* invalid inupt. */
                            ret = MEDPLY_PLST_ERR_INVALID_INPUT;
                        }
                    }
                    else
                    {
                        g_listui_cntx_p->details_info.modify_flag |= MEDPLY_DB_UPDATE_YEAR;
                        g_listui_cntx_p->details_info.raw_p->year = -1;
                    }
                }
                break;
            default:
                break;
        }
        /* copy new string back. */
        if (MEDPLY_PLST_ERR_INVALID_INPUT != ret)
        {
            mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->editor_cntx.original_string_p, 
                     (const CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer, 
                     g_listui_cntx_p->editor_cntx.limit);
        }        
    }

    return ret;
}
#endif /* __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__ */

#define __LISTUI_EDITOR
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_editor_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_listui_editor_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        /* Handler when user confirm input */
        cui_fseditor_get_text(editor_evt->sender_id, g_listui_cntx_p->editor_cntx.editor_buffer, (g_listui_cntx_p->editor_cntx.limit+1)*2);

        if (g_listui_cntx_p->editor_cntx.done_func != NULL)
        {
            if(!g_listui_cntx_p->editor_cntx.done_func())
            {
                break;
            }
        }

        cui_fseditor_close(editor_evt->sender_id);
        g_listui_cntx_p->editor_cntx.gid = 0;
        break;

    case EVT_ID_CUI_FSEDITOR_ABORT:
        /* Handler when user Cancel input */
        cui_fseditor_close(editor_evt->sender_id);
        g_listui_cntx_p->editor_cntx.gid = 0;
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 input_type = 0;
    mmi_id fseditor_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_listui_cntx_p->editor_cntx.editor_type)
    {
        case MMI_MEDPLY_EDITOR_NEW:
        case MMI_MEDPLY_EDITOR_SAVE_RAM:
            input_type = IMM_INPUT_TYPE_SENTENCE;
            break;
        case MMI_MEDPLY_EDITOR_EDIT_URL:
        case MMI_MEDPLY_EDITOR_NEW_URL:
            input_type = IMM_INPUT_TYPE_URL;
            break;
        case MMI_MEDPLY_EDITOR_RENAME:
            input_type = IMM_INPUT_TYPE_SENTENCE;
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


    if((fseditor_gid = cui_fseditor_create(GRP_ID_MEDPLY_FTE_SUB_MENU)) != NULL)
    {
        g_listui_cntx_p->editor_cntx.gid = fseditor_gid;
        cui_fseditor_set_title(fseditor_gid, g_listui_cntx_p->editor_cntx.editor_title_id, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
        cui_fseditor_set_text(fseditor_gid, g_listui_cntx_p->editor_cntx.editor_buffer, (g_listui_cntx_p->editor_cntx.limit+1)*2, g_listui_cntx_p->editor_cntx.limit);
        cui_fseditor_set_input_method(fseditor_gid, input_type, NULL, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);

        cui_fseditor_run(fseditor_gid);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_editor_check_valid
 * DESCRIPTION	
 *  close function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_listui_editor_check_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ptr = NULL;
    S32 len = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = (CHAR*)srv_fmgr_path_skip_leading_space((WCHAR*)g_listui_cntx_p->editor_cntx.editor_buffer);

    if (ptr != (CHAR*)g_listui_cntx_p->editor_cntx.editor_buffer)
    {
        mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_INVALID_FILENAME),
                                 MMI_EVENT_ERROR,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        mmi_frm_ui_force_update_now();
        return MMI_FALSE;
    }
    
    len = mmi_ucs2strlen(ptr);

    if (len == 0)
    {
        mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME),
                                 MMI_EVENT_ERROR,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        mmi_frm_ui_force_update_now();
        return MMI_FALSE;
    }
    if (ptr[0] == '.' ||
        !srv_fmgr_path_is_filename_valid((const WCHAR*)g_listui_cntx_p->editor_cntx.editor_buffer))
    {
        mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_INVALID_FILENAME),
                                 MMI_EVENT_ERROR,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        mmi_frm_ui_force_update_now();
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


#define __LISTUI_OTHER_HDLR
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_curr_plst_list
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
void mmi_medply_listui_entry_curr_plst_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    S32 ret;
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //TODO: prepare all song list 
    ret = mmi_medply_listui_prepare_curr_plst(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                              LIST_TYPE_ACTIVE_LIST,
                                              &g_listui_cntx_p->view_stack);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_popup_error(ret);
        return;
    }

    ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                &g_listui_cntx_p->playing.total);
    if (ret < SRV_PLST_OK)
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, &g_listui_cntx_p->view_stack);
        mmi_medply_listui_popup_error(ret);
        return;
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST, NULL, 
                                   mmi_medply_listui_entry_curr_plst_list, MMI_FRM_UNKNOW_SCRN);

    if (!entry_ret)
    {
        return;
    }
    
    /*current list cache need change, reload list info*/
    if (SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST!= g_listui_cntx_p->list_info.list_scr_id)
    {
        g_listui_cntx_p->list_info.list_type = LIST_TYPE_ACTIVE_LIST;
        g_listui_cntx_p->list_info.list_scr_id = SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST;
        mmi_ucs2ncpy((CHAR*)g_listui_cntx_p->list_info.title, 
                     (const CHAR*)GetString(STR_ID_MEDPLY_CUR_PLAYLIST),
                     MEDPLY_MAX_FILE_LEN - 1);
    }
    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST, 
                                mmi_medply_listui_delete_callback);

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (!guiBuffer)
    {
        g_listui_cntx_p->playing.curr_sel_index = 0;
    }

    /* register highligh handler */
    RegisterHighlightHandler(mmi_medply_listui_currplay_highlight_hdlr);

    mmi_medply_listui_show_curr_list_scr(g_listui_cntx_p->list_info.title, 
                                         g_listui_cntx_p->playing.total,
                                         g_listui_cntx_p->playing.curr_sel_index);

/*#ifdef __MMI_FTE_SUPPORT__
    wgui_register_tap_callback(mmi_medply_listui_plst_list_tap_callback);
#endif*/
    if (g_listui_cntx_p->playing.total > 0)
    {
        SetLeftSoftkeyFunction(mmi_medply_listui_file_play, KEY_EVENT_UP);
        if(mmi_frm_kbd_is_key_supported(KEY_CSK))
        {
            SetCenterSoftkeyFunction(mmi_medply_listui_file_play, KEY_EVENT_UP);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        }
    }    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_show_song_list_scr
 * DESCRIPTION
 *  Show file list screen(all songs/videos, artist/album/gen view).
 *  LSK:option. RSK: BACK
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_show_curr_list_scr(UI_string_type title, S32 total, S32 highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8*  guiBuffer;
    U16  LSK_string = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    
    if (total > 0)
    {
        LSK_string = STR_GLOBAL_OK;
    }
    
    wgui_cat_register_get_flags_callback(mmi_medply_listui_common_list_disable_scrollbar);
    ShowCategory183Screen(
        title, 
        get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
        get_string(LSK_string),
        0,              
        get_string(STR_GLOBAL_BACK),
        0, 
        total,
        mmi_medply_listui_get_common_list_item,
        mmi_medply_listui_get_common_list_hint,
        highlight,
        MMI_FALSE,
        NULL,
        guiBuffer);
    wgui_title_set_shortcut_count(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_common_highlight_hdlr
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_currplay_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_listui_cntx_p->playing.curr_sel_index = index;
}


#define __LISTUI_UTIL
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_util_set_cache_mem
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_listui_util_set_cache_mem(U32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_suspend_background_play();
    
    ASSERT(!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SET_CACHE));
    g_listui_cntx_p->srv_cntx.temp_mem_ptr = applib_mem_screen_alloc_framebuffer(mem_size);

    if (NULL != g_listui_cntx_p->srv_cntx.temp_mem_ptr)
    {
        ret = srv_plst_set_temp_memory(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                   (void**)&g_listui_cntx_p->srv_cntx.temp_mem_ptr,
                                   mem_size);
        if (ret >= SRV_PLST_OK)
        {
            g_listui_cntx_p->list_info.flag |= MMI_MEDPLY_LISTUI_IS_SET_CACHE;    
        }
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_goto_mainmenu_hilite_hdlr
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_listui_util_clear_cache_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!(g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SET_CACHE))
    {
        //@TODO: add log 
        return 0;
    }

    ret = srv_plst_clear_temp_memory(g_listui_cntx_p->srv_cntx.srv_hdlr);
    g_listui_cntx_p->list_info.flag &= ~MMI_MEDPLY_LISTUI_IS_SET_CACHE;
    if (ret < SRV_PLST_OK)
    {
        //@add error log
    }
    applib_mem_screen_free(g_listui_cntx_p->srv_cntx.temp_mem_ptr);
    g_listui_cntx_p->srv_cntx.temp_mem_ptr = NULL;

    mdi_audio_resume_background_play();

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_popup_error
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_popup_error(S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    mmi_event_notify_enum event_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_POPUP_ERROR, error_code);
    
    str_id = srv_plst_get_error_string(error_code, &event_type);

    if (GRP_ID_MEDPLY_FTE == mmi_frm_group_get_active_id() || 
        GRP_ID_MEDPLY_FTE_SUB_MENU == mmi_frm_group_get_active_id())
    {
        mmi_popup_display_simple((WCHAR*)get_string(str_id), event_type, GRP_ID_MEDPLY_FTE, NULL);
    }
    else
    {
        mmi_popup_display_simple((WCHAR*)get_string(str_id), event_type, GRP_ID_ROOT, NULL);
    }    
    mmi_frm_ui_force_update_now();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_popup_error_with_cb
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_popup_error_with_cb(S32 error_code, mmi_proc_func cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    mmi_event_notify_enum event_type;
    mmi_popup_property_struct popup_arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_POPUP_ERROR, error_code);
    
    str_id = srv_plst_get_error_string(error_code, &event_type);

    mmi_popup_property_init(&popup_arg);
    popup_arg.parent_id = GRP_ID_MEDPLY_FTE;
    popup_arg.callback = cb;

    mmi_popup_display((WCHAR*)get_string(str_id), event_type, &popup_arg);
    mmi_frm_ui_force_update_now();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_popup_done
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_popup_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_DONE),
                             MMI_EVENT_SUCCESS,
                             GRP_ID_MEDPLY_FTE,
                             NULL);
    mmi_frm_ui_force_update_now();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_popup_done
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_popup_by_strid(U16 strid, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple((WCHAR*)get_string(strid),
                             type, /*MMI_EVENT_SUCCESS,*/
                             GRP_ID_MEDPLY_FTE,
                             NULL);
    mmi_frm_ui_force_update_now();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_wait_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_show_wait_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        STR_GLOBAL_STOP,
        0,
        (PU8)GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        guiBuffer);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_wait_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_entry_wait_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING, NULL, 
                                   mmi_medply_listui_entry_wait_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_WAITING, mmi_medply_listui_wait_scr_delete_callback);
        
    mmi_medply_listui_show_wait_scr();
    if (medply_listui_cancel_cb != NULL)
    {
        SetRightSoftkeyFunction(medply_listui_cancel_cb, KEY_EVENT_UP);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_multisel_callback
 * DESCRIPTION
 *  apply picked file, fill global context.
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
mmi_ret mmi_medply_listui_wait_scr_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        if (medply_listui_cancel_cb != NULL)
        {
            medply_listui_cancel_cb();
        }
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_util_delete_upto
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_listui_util_delete_upto(mmi_id scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID res_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == scrn_id)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_UTIL_DELETE_UPTO_SRCID_ERROR);
        return -1;
    }

    if (GRP_ID_MEDPLY_FTE == mmi_frm_group_get_active_id())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_UTIL_DELETE_UPTO_ACTIVE_IS_MEDPLY);
        mmi_frm_scrn_multiple_close(GRP_ID_MEDPLY_FTE, mmi_frm_scrn_get_active_id(),
                                    MMI_FALSE, 0, scrn_id, MMI_FALSE);  
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_UTIL_DELETE_UPTO_ACTIVE_NOT_MEDPLY);
        res_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_MEDPLY_FTE, 
                                              SCR_ID_INVALID,
                                              MMI_FRM_NODE_AT_LATEST_FLAG);
        if (SCR_ID_INVALID != res_id)
        {
            mmi_frm_scrn_multiple_close(GRP_ID_MEDPLY_FTE, res_id,
                                        MMI_TRUE, 0, scrn_id, MMI_FALSE);   
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_UTIL_DELETE_UPTO_NOTHING_DELETE);
        }
    }      
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_util_clear_gui_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_util_clear_gui_buffer(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_UTIL_CLEAR_GUI_BUFFER, scr_id);
    
    if (0 == scr_id)
    {
        return;
    }
    
    mmi_medply_listui_util_clear_scrn((mmi_id)scr_id);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_util_clear_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_util_clear_scrn(mmi_id scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_clean_gui_buf(GRP_ID_MEDPLY_FTE, scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_get_file_icon
 * DESCRIPTION
 *  extract filename icon
 * PARAMETERS
 *  file_format        [IN]        
 * RETURNS
 *  return icon id
 *****************************************************************************/
U16 mmi_medply_util_get_file_icon(U16 file_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_format < MEDPLY_FORMAT_TOTAL && file_format != MEDPLY_FORMAT_NONE)
    {
        return media_file_info_table[file_format].image_id;
    }
    else
    {
        return IMG_ID_MEDPLY_FILE_UNKNOWN_ICON;
    }
}

 
#define __LISTUI_ADAPTION
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
    ret = mmi_medply_listui_module_init_internal();
    return ret;
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


/*****************************************************************************
 * FUNCTION
 *  mmi_meply_plst_reset_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern void mmi_meply_plst_reset_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_RESET_ALL);
    memset(&g_listui_cntx_p->view_stack, 0 , sizeof(mmi_medply_listui_view_stack_struct));
    memset(&g_listui_cntx_p->list_info, 0 , sizeof(mmi_medply_listui_list_info_struct));
    g_listui_cntx_p->view_stack.curr_ptr = -1;

    if (0 != g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        srv_plst_list_reset_all_list(g_listui_cntx_p->srv_cntx.srv_hdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_repeat_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_medply_settings_repeat_change(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(index == MMI_MEDPLY_SETTINGS_REPEAT_OFF )
    {
        srv_plst_config_repeat(g_listui_cntx_p->srv_cntx.srv_hdlr ,SRV_PLST_REPEAT_OFF);
    }
    else if(index == MMI_MEDPLY_SETTINGS_REPEAT_ONE)
    {
        srv_plst_config_repeat(g_listui_cntx_p->srv_cntx.srv_hdlr ,SRV_PLST_REPEAT_ONE);
    }
    else if(index == MMI_MEDPLY_SETTINGS_REPEAT_ALL)
    {
        srv_plst_config_repeat(g_listui_cntx_p->srv_cntx.srv_hdlr ,SRV_PLST_REPEAT_ALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_shuff_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_medply_settings_shuff_change(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(index == MMI_MEDPLY_SETTINGS_SHUFFLE_OFF)
    {
        srv_plst_config_shuffle(g_listui_cntx_p->srv_cntx.srv_hdlr ,SRV_PLST_SHUFFLE_OFF);
    }
    else if(index == MMI_MEDPLY_SETTINGS_SHUFFLE_ON)
    {
        srv_plst_config_shuffle(g_listui_cntx_p->srv_cntx.srv_hdlr ,SRV_PLST_SHUFFLE_ON);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_is_video_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_medply_plst_is_video_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SRV_IS_NULL, ret);
        return ret;
    }
    
    if (SRV_PLST_ACTIVE_LIST_TYPE_VIDEO == 
        srv_plst_get_active_list_media_type(g_listui_cntx_p->srv_cntx.srv_hdlr))
    {
        ret = MMI_TRUE;
    }
    else
    {
        ret = MMI_FALSE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_RET, ret);
    return ret;
}



#define __LISTUI_ADAPTION
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_error_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern void mmi_medply_plst_get_error_string(S32 error_code, MMI_ID_TYPE* str_id, mmi_event_notify_enum *event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_code)
    {
        case MEDPLY_PLST_ERR_EMPTY_LIST:
            *str_id = STR_ID_MEDPLY_PLST_NOTIFY_EMPTY_LIST;
            *event_type = MMI_EVENT_FAILURE;
            break;

        case MEDPLY_PLST_ERR_UNSUPPORT_FORMAT:
            *str_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
            *event_type = MMI_EVENT_FAILURE;
            break;
        default:
            *str_id = srv_plst_get_error_string(error_code, event_type);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
// TODO: change to NMGR?
void mmi_medply_plst_display_popup(S32 error_code, FuncPtr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    mmi_event_notify_enum event_type = MMI_EVENT_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DISPLAY_POPUP, error_code);
    switch (error_code)
    {
        case MEDPLY_PLST_ERR_EMPTY_LIST:
            str_id = STR_ID_MEDPLY_PLST_NOTIFY_EMPTY_LIST;
            break;

        case MEDPLY_PLST_ERR_UNSUPPORT_FORMAT:
            str_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
            break;

        case MEDPLY_PLST_ERR_INVALID_INPUT:
            str_id = STR_GLOBAL_INVALID_INPUT;
            break;

        default:
            str_id = srv_plst_get_error_string(error_code, &event_type);
            break;
    }

    if (GRP_ID_MEDPLY_FTE == mmi_frm_group_get_active_id())
    {
        mmi_popup_display_simple((WCHAR*)get_string(str_id), event_type, GRP_ID_MEDPLY_FTE, NULL);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DISPLAY_POPUP, 0);
        mmi_popup_display_simple((WCHAR*)get_string(str_id), event_type, GRP_ID_ROOT, NULL);
    }
    mmi_frm_ui_force_update_now();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_is_empty
 * DESCRIPTION
 *  
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
    S32 ret;
    U32 id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ret = srv_plst_plst_get_active_plst_id(g_listui_cntx_p->srv_cntx.srv_hdlr, &id);
    if (ret < SRV_PLST_OK || 0 == id)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_CURR_IS_EMPTY, MMI_TRUE);
        return MMI_TRUE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_CURR_IS_EMPTY, MMI_FALSE);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_post_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static mmi_ret mmi_medply_plst_post_action(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_MEDPLY_LIST_UI_STORE_ACTIVE)
    {
        srv_plst_plst_store_active_info(g_listui_cntx_p->srv_cntx.srv_hdlr);
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_post_store_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_medply_plst_post_store_active(U32 event_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, event_id);
    MMI_FRM_POST_EVENT(&evt, mmi_medply_plst_post_action, user_data);
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
    FS_HANDLE fs_hdl = FS_NO_ERROR;
    S32 ret = 0;
    U16 file_format = 0;    
    #ifdef __DRM_SUPPORT__
    U8  result;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_APPLY_BEGIN);

    /*set flag to get user rating from DB , but not temp value*/
    g_listui_cntx_p->details_info.rating_update_flag = 1;

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    g_medply.is_audio_seekable = MMI_TRUE;
#endif

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    mmi_medply_settings_subtitle_iso_shutdown();
#endif


#if defined(__MMI_AUDIO_VOCAL_REMOVAL__)
    g_medply.vocal_removal = MMI_SETTINGS_VOCAL_REMOVAL_OFF;
#endif
#if defined(__MMI_AUDIO_PITCH_SHIFTING__)
    g_medply.pitch = MMI_SETTINGS_PITCH_SHIFTING_0;
#endif
    if (mmi_medply_plst_curr_is_empty())
    {
        g_medply.media_format = MEDPLY_FORMAT_NONE;
        g_medply.media_type = MEDPLY_TYPE_NONE;
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

    if ((g_listui_cntx_p->playing.last_error < 0) &&
        (g_listui_cntx_p->playing.last_error != SRV_PLST_RET_EMPTY))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_APPLY_PICKED_FILE,
                         g_listui_cntx_p->playing.last_error);
        ret = g_listui_cntx_p->playing.last_error;
        g_listui_cntx_p->playing.last_error = 0;
        /* Indicates playlist service has an error, since we won't 
        * get any file name so better to reset context here as well */
        g_medply.media_format = MEDPLY_FORMAT_NONE;
        g_medply.media_type = MEDPLY_TYPE_NONE;
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
        return ret;
    }   

    ret = srv_plst_plst_item_get_active_media_info_curr(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                 &g_listui_cntx_p->playing.id,
                                                 &g_listui_cntx_p->playing.pick_index,                                                 
                                                 g_medply.filefullpath);
    
    if (ret < 0 || 0 == g_listui_cntx_p->playing.id)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_APPLY_FAILED, ret);

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
        
        return ret;
    }
    else
    {   
        mmi_medply_plst_post_store_active(EVT_ID_MEDPLY_LIST_UI_STORE_ACTIVE, NULL);
        
        if (mmi_medply_plst_is_video_list())
        {
            file_format = mmi_medply_util_is_service_support_format_ex(g_medply.filefullpath, MMI_TRUE);
        }
        else
        {
            file_format = mmi_medply_util_is_service_support_format_ex(g_medply.filefullpath, MMI_FALSE);
        }

        fs_hdl = DRM_open_file(g_medply.filefullpath, FS_READ_ONLY, DRM_PERMISSION_NONE);
        if(fs_hdl >= FS_NO_ERROR)
        {
            DRM_close_file(fs_hdl);
        }
        /* do more check with file path and media format. */
        if (file_format == MEDPLY_FORMAT_NONE || file_format >= MEDPLY_FORMAT_TOTAL)
        {
            /* media table error. */
            ret = MEDPLY_PLST_ERR_UNSUPPORT_FORMAT;
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_APPLY_FAILED, ret);
            /* reset playing list context. */
            //mmi_medply_playing_deinit();
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
            
            return ret;
        }

        /* check if is platform support format */
        if (mmi_medply_plst_is_video_list())
        {
            file_format = mmi_medply_util_is_service_support_format(g_medply.filefullpath, MMI_TRUE);
            g_medply.media_type = MEDPLY_TYPE_VIDEO;
        }
        else
        {
            file_format = mmi_medply_util_is_service_support_format(g_medply.filefullpath, MMI_FALSE);
            g_medply.media_type = MEDPLY_TYPE_AUDIO;
        }
        if ((file_format > MEDPLY_FORMAT_NONE) && (file_format < MEDPLY_FORMAT_TOTAL))
        {
            g_medply.media_type = (mmi_medply_media_type_enum)media_file_info_table[file_format].file_type;
        }
        g_medply.media_format = (mmi_medply_media_format_enum)media_file_info_table[file_format].file_format;
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

        g_medply.duration = 0;
        if (g_medply.media_type == MEDPLY_TYPE_AUDIO && fs_hdl >= 0)
        {
            if (mdi_audio_get_duration(g_medply.filefullpath, (U32*)(&g_medply.duration)) != MDI_AUDIO_SUCCESS)
            {
                g_medply.duration = 0;
            }
        }
        else if(g_medply.media_type == MEDPLY_TYPE_VIDEO && fs_hdl >= 0)
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
        if (fs_hdl >= FS_NO_ERROR)
        {
            result = mmi_medply_drm_valide_right((PU16)g_medply.filefullpath);
            if(result ==2)
            {
                g_medply.seekable = MMI_FALSE;
            }
            g_medply.DRM_consumed = MMI_FALSE;
        }
        else
        {
            g_medply.seekable = MMI_FALSE;
            g_medply.DRM_consumed = MMI_FALSE;
        }
    #endif

    #if defined(__MMI_MEDIA_PLAYER_AUDIO__)
        if (fs_hdl >= FS_NO_ERROR)
        {
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
        }
        else
        {
            g_medply.is_audio_seekable = MMI_FALSE;
            g_medply.seekable = MMI_FALSE;
        }
    #endif 

        g_medply.progress_speed = mmi_medply_determine_progress_speed(g_medply.duration);
        mmi_medply_clear_play_seconds();
        mmi_medply_main_screen_set_file_path(NULL,MMI_TRUE);

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_APPLY_SUCSESS,g_listui_cntx_p->playing.id ,__LINE__);
        return 0;
    }
}

//enhance
S32 mmi_medply_plst_add_to_recent_played(void)
{
    S32 ret = 0;
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    ret = srv_plst_media_update_playing_info(g_listui_cntx_p->srv_cntx.srv_hdlr);
#endif /* __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__ */
    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_load_last
* DESCRIPTION
*  
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
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_LOAD_LAST);

    g_listui_cntx_p->playing.failed_count  = 0;
    g_listui_cntx_p->playing.failed_nofile = 0;
    g_listui_cntx_p->playing.is_play_fail  = MMI_FALSE;
    
    mmi_medply_plst_clear_context_variables();

    if (NULL == g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SRV_NOT_READY);
        return 0;
    }

    if(!mmi_medply_plst_curr_is_valid())
    {
        return -1;
    }
    ret = srv_plst_plst_item_get_active_media_info_curr(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                 &g_listui_cntx_p->playing.id,
                                                 &g_listui_cntx_p->playing.pick_index,                                                 
                                                 g_medply.filefullpath);
    
    if ((ret >= SRV_PLST_OK) & (g_listui_cntx_p->playing.id > 0))
    {
        mmi_medply_plst_apply_picked_file();
    }
    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_set_pick_index
 * DESCRIPTION
 *  set pick index.
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
extern S32 mmi_medply_plst_set_pick_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_plst_list_set_as_active(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                      index);

    g_listui_cntx_p->playing.failed_count  = 0;
    g_listui_cntx_p->playing.failed_nofile = 0;
    g_listui_cntx_p->playing.is_play_fail  = MMI_FALSE;

    return ret;
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
        filename_ptr = mmi_ucs2rchr((const CHAR*)in_path, (WCHAR)(L'\\'));
        if (filename_ptr == NULL)
        {
            *out_filename = 0;
        }
        else
        {
            fd = FS_FindFirst(in_path, 0, 0, &file_info, filename, MEDPLY_MAX_FILE_LEN * ENCODING_LENGTH);

            if (fd < 0)
            {
                mmi_ucs2ncpy((CHAR*)out_filename, (const CHAR*)(filename_ptr + 2), MEDPLY_MAX_FILE_LEN - 1);
            }
            else
            {
                is_short = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;
                if (is_short)
                {
                    mmi_chset_mixed_text_to_ucs2_str(
                        (U8*)out_filename,
                        (MEDPLY_MAX_FILE_LEN - 1) * ENCODING_LENGTH,
                        (U8*)(filename_ptr + 2),
                        (mmi_chset_enum)PhnsetGetDefEncodingType());
                }
                else
                {
                    mmi_ucs2ncpy((CHAR*)out_filename, (const CHAR*)(filename_ptr + 2), MEDPLY_MAX_FILE_LEN - 1);
                }
                FS_FindClose(fd);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_mscr_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_fmgr_delete_hdlr(U32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_delete_file_from_fmgr_struct *del_info = (srv_plst_delete_file_from_fmgr_struct*)para;
    U32 fmgr_path_length = (U32)mmi_ucs2strlen((const CHAR*)del_info->path);
    MMI_BOOL is_allow_delete = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_medply.state == MEDPLY_STATE_IDLE ||
        g_medply.state == MEDPLY_STATE_AUDIO_READY ||
        g_medply.state == MEDPLY_STATE_VIDEO_IDLE ||
        g_medply.state == MEDPLY_STATE_PURE_AUDIO_READY ||
        g_medply.state == MEDPLY_STATE_STREAM_IDLE ||
        g_medply.state >= MEDPLY_STATE_TOTAL)
    {
        return MMI_TRUE;
    }

    /*delete file*/
    if (!del_info->is_folder)
    {
        if(mmi_ucs2nicmp((const CHAR*)del_info->path, (const CHAR*)g_medply.filefullpath, fmgr_path_length) == 0)
        {
            /*the deleted file is playing, not allow to delete*/
            is_allow_delete = MMI_FALSE;
        }
        return is_allow_delete;
    }

    /*delete folder*/
    if(mmi_ucs2nicmp((const CHAR*)del_info->path, (const CHAR*)g_medply.filefullpath, fmgr_path_length) != 0)
    {
        /*playing file is not under curent folder*/
        return MMI_TRUE;
            
    }
    if(del_info->is_delete_all)
    {
        while(g_medply.filefullpath[fmgr_path_length] != 0 &&
              g_medply.filefullpath[fmgr_path_length] != L'\\')
        {
            fmgr_path_length ++;
        }
        if (g_medply.filefullpath[fmgr_path_length] == 0)
        {
            CHAR* ext_ptr = mmi_ucs2rchr((const CHAR*)g_medply.filefullpath, (WCHAR)L'.');
            if (ext_ptr != NULL)
            {
                ext_ptr += 2;
            }
            else
            {
                /**/
                return MMI_FALSE;
            }
                           
            if (!mmi_ucs2icmp((const CHAR*)ext_ptr, (const CHAR*)L"imy"))
            {
                if (FMGR_FILTER_IS_SET(&(del_info->filter), FMGR_TYPE_IMY))
                {
                    is_allow_delete = MMI_FALSE;
                }
                FMGR_FILTER_CLEAR(&(del_info->filter), FMGR_TYPE_IMY);
            }
            else if (!mmi_ucs2icmp((const CHAR*)ext_ptr, (const CHAR*)L"wav"))
            {
                if (FMGR_FILTER_IS_SET(&(del_info->filter), FMGR_TYPE_WAV))
                {
                    is_allow_delete = MMI_FALSE;
                }
                FMGR_FILTER_CLEAR(&(del_info->filter), FMGR_TYPE_WAV);
            }
            else if (!mmi_ucs2icmp((const CHAR*)ext_ptr, (const CHAR*)L"amr"))
            {
                if (FMGR_FILTER_IS_SET(&(del_info->filter), FMGR_TYPE_AMR))
                {
                    is_allow_delete = MMI_FALSE;
                }
                FMGR_FILTER_CLEAR(&(del_info->filter), FMGR_TYPE_AMR);
            }
            else if (!mmi_ucs2icmp((const CHAR*)ext_ptr, (const CHAR*)L"awb"))
            {
                if (FMGR_FILTER_IS_SET(&(del_info->filter), FMGR_TYPE_AWB))
                {
                    is_allow_delete = MMI_FALSE;
                }
                FMGR_FILTER_CLEAR(&(del_info->filter), FMGR_TYPE_AWB);
            }
            else if (FMGR_FILTER_IS_SET_AUDIO(&(del_info->filter)))
            {
                is_allow_delete = MMI_FALSE;
            }
            return is_allow_delete;
        }                       
    }
    else if(*(U16*)(del_info->path+ fmgr_path_length * 2 - 2) == L'\\' || 
            *(U16*)(del_info->path+ fmgr_path_length * 2) == 0)
    {
        if (*(g_medply.filefullpath + fmgr_path_length) == '\\' ||
            *(g_medply.filefullpath + fmgr_path_length) == 0)
        {
            return MMI_FALSE;
        }
    }
                                     
    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_msdc_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_msdc_plug_in_hdlr(U32 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_MSDC_PLUG_IN_HDLR, 
                     drv, (U32)g_medply.filefullpath[0]);
    if (drv == (U32)g_medply.filefullpath[0])
    {        
        mmi_medply_plst_apply_picked_file();
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_msdc_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plstui_msdc_plug_out_hdlr(U32 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_MSDC_PLUG_OUT_HDLR, 
                     drv, (U32)g_medply.filefullpath[0]);
    if (drv == (U32)g_medply.filefullpath[0])
    {
        /* The now playing file has been removed. 
         ** Media player should reset some flag in order to insure the correct of main screen. */
        g_medply.seekable = MMI_FALSE;
        g_medply.need_to_build_cache = MMI_FALSE;
        g_medply.current_time = 0;
        g_medply.old_play_time = 0;
        g_medply.duration = 0;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plstui_msdc_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv             [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plstui_entry_unmount_hdlr(U32 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_UNMOUNT_HDLR, 
                     drv, (U32)g_medply.filefullpath[0]);
    if (drv == (U32)g_medply.filefullpath[0])
    {
        /*need set media type to NONE, to avoid states not change to IDLE.*/
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        mmi_medply_plst_clear_context_variables();
    }
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
#endif  /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */


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
        g_medply.seekable = MMI_FALSE;
        return 0;        
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
    dot = mmi_ucs2rchr((const CHAR*)ext, (WCHAR)L'.');
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
 *  mmi_medply_util_is_service_support_format
 * DESCRIPTION
 *  check a file whether be supported.
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_medply_util_is_service_support_format(const UI_string_type ext, MMI_BOOL is_video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type file_ext[MEDPLY_MAX_EXT_LEN];
    S32 ext_len = 0;
    CHAR* dot = NULL;
    U16 file_format = MEDPLY_FORMAT_NONE;
    U16 support_format = MEDPLY_FORMAT_NONE;
    U8  i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_IS_SERVICE_SUPPORT_FORMAT, is_video);

    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((const CHAR*)ext)))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_IS_SERVICE_SUPPORT_FORMAT, __LINE__);
        return MEDPLY_FORMAT_NONE;
    }
    /* skip ".". */
    dot = mmi_ucs2rchr((const CHAR*)ext, (WCHAR)L'.');
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

    /*check file format in list service*/
    for (i = 0; i < MEDPLY_FORMAT_TOTAL; i++)
    {
        if (ext_len == mmi_ucs2strlen((const CHAR*)media_file_info_table[i].ext_name) &&
            (!mmi_ucs2icmp((const CHAR*)file_ext, (const CHAR*)media_file_info_table[i].ext_name)))
        {
            if (!is_video)
            {
                /*check format tye in audio type*/
                if (MEDPLY_TYPE_AUDIO == media_file_info_table[i].file_type)
                {
                    file_format = media_file_info_table[i].file_format;
                    break;
                }
            }
            else
            {
                /*check format in video&stream type*/
                if (MEDPLY_TYPE_AUDIO != media_file_info_table[i].file_type)
                {
                    file_format = media_file_info_table[i].file_format;
                    break;
                }
            }                               
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_FILE_FORMAT, file_format);

    /*check if support by target*/
    if (MEDPLY_FORMAT_NONE != file_format)
    {
        for (i = 0; i < MEDPLY_FORMAT_TOTAL; i++)
        {
            if (file_format == support_format_table[i].file_format)
            {
                support_format = file_format;
            }
        }
    }
    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SUPPORT_FORMAT, support_format);

    return support_format;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_is_service_support_format
 * DESCRIPTION
 *  check a file whether be supported.
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_medply_util_is_service_support_format_ex(const UI_string_type ext, MMI_BOOL is_video)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type file_ext[MEDPLY_MAX_EXT_LEN];
    S32 ext_len = 0;
    CHAR* dot = NULL;
    U16 file_format = MEDPLY_FORMAT_NONE;
    U8  i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_IS_SERVICE_SUPPORT_FORMAT, is_video);

    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((const CHAR*)ext)))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_IS_SERVICE_SUPPORT_FORMAT, __LINE__);
        return MEDPLY_FORMAT_NONE;
    }
    /* skip ".". */
    dot = mmi_ucs2rchr((const CHAR*)ext, (WCHAR)L'.');
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

    /*check file format in list service*/
    for (i = 0; i < MEDPLY_FORMAT_TOTAL; i++)
    {
        if (ext_len == mmi_ucs2strlen((const CHAR*)media_file_info_table[i].ext_name) &&
            (!mmi_ucs2icmp((const CHAR*)file_ext, (const CHAR*)media_file_info_table[i].ext_name)))
        {
            if (!is_video)
            {
                /*check format tye in audio type*/
                if (MEDPLY_TYPE_AUDIO == media_file_info_table[i].file_type)
                {
                    file_format = media_file_info_table[i].file_format;
                    break;
                }
            }
            else
            {
                /*check format in video&stream type*/
                if (MEDPLY_TYPE_AUDIO != media_file_info_table[i].file_type)
                {
                    file_format = media_file_info_table[i].file_format;
                    break;
                }
            }                               
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_FILE_FORMAT, file_format);
    return file_format;
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
        ext_ptr = mmi_ucs2rchr((const CHAR*)filename, (WCHAR)L'.');

        if (ext_ptr == NULL)
        {
            *ext = 0;
        }
        else
        {
            ext_ptr += 2;
            mmi_ucs2ncpy((CHAR*)ext, (const CHAR*)ext_ptr, (MEDPLY_MAX_EXT_LEN - 1));
        }
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
    U32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_UTIL_FILL_IDEAL_DISPLAY_STR);
    
    g_medply.idle_string[0]  = 0;
    
    meta_info.album[0]       = 0;
    meta_info.artist[0]      = 0;
    meta_info.title[0]       = 0;
    meta_info.user_rating    = 0;
    meta_info.artwork.mime_type  = META_TAG_IMG_TOTAL;
    meta_info.artwork.size   = 0;
    meta_info.lyrics.size    = 0;

    if (mmi_medply_plst_is_video_list())
    {
        /*Do not get details from library for video list*/
        result = -1;
    }
    else
    {
        result = mmi_medply_plst_get_current_details(&meta_info);
    }    

    if (result >= SRV_PLST_OK)
    {
        length = mmi_ucs2strlen((const CHAR*)meta_info.artist);

        if (length != 0)
        {
            mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (const CHAR*)meta_info.artist, (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        }
        else
        {
            UI_character_type artist[MMI_MEDPLY_MAX_ARTISRT_LEN + 1];
            mmi_ucs2ncpy((CHAR*)artist, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_UNKNOWN_ARTIST), MMI_MEDPLY_MAX_ARTISRT_LEN);
            length = mmi_ucs2strlen((const CHAR*)artist);
            mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (const CHAR*)artist, (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        }

        mmi_ucs2ncat((CHAR*)g_medply.idle_string, (const CHAR*)L" - ", (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));

        length = mmi_ucs2strlen((const CHAR*)meta_info.title);

        if (length != 0)
        {
            mmi_ucs2ncat((CHAR*)g_medply.idle_string, (const CHAR*)meta_info.title, length);
        }
        else
        {
            CHAR* dot = NULL;
            UI_character_type filename[MEDPLY_MAX_FILE_LEN];
            /* try to cut off filename as title. */
            mmi_medply_util_extract_filename(filename, g_medply.filefullpath);
            /* cut off extended name. */
            dot = mmi_ucs2rchr((const CHAR*)filename, (WCHAR)L'.');
            if (dot != NULL)	/* all supported media file should has an extended name! */
            {
                *(dot + 1) = 0;
                *dot = 0;
            }
            length = mmi_ucs2strlen((const CHAR*)filename);
            mmi_ucs2ncat((CHAR *)g_medply.idle_string, (const CHAR*)filename, length);
        }
    }
    else
    {
        CHAR* dot = NULL;
        UI_character_type filename[MEDPLY_MAX_FILE_LEN];
        /* try to cut off filename as title. */
        mmi_medply_util_extract_filename(filename, g_medply.filefullpath);
        /* cut off extended name. */
        dot = mmi_ucs2rchr((const CHAR*)filename, (WCHAR)L'.');
        if (dot != NULL)	/* all supported media file should has an extended name! */
        {
            *(dot + 1) = 0;
            *dot = 0;
        }
        length = mmi_ucs2strlen((const CHAR *)filename);

        g_medply.idle_string[0] = 0;
        mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (const CHAR*)GetString(STR_ID_MEDPLY_PLST_UNKNOWN_ARTIST), (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        mmi_ucs2ncat((CHAR*)g_medply.idle_string, (const CHAR*)L" - ", (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        mmi_ucs2ncat((CHAR*)g_medply.idle_string, (const CHAR*)filename, length);
    } 
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
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENCODING_TYPE_CHANGE_CALLBACK);
    if (NULL != g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        mmi_medply_util_fill_idle_display_str();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_notify_file_not_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_notify_file_not_available(mmi_medply_fail_play_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_listui_cntx_p->playing.is_play_fail = MMI_TRUE;
    /* increase unplayed counter cause by all reason */
    g_listui_cntx_p->playing.failed_count++;
    if (MEDPLY_FAIL_PLAY_TYPE_FILE_ISSUE == type)
    {
        /* increase unplayed counter cause by open fail */
        g_listui_cntx_p->playing.failed_nofile++;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_NOTIFY_FILE_NOT_AVAILABLE,
                     type, g_listui_cntx_p->playing.failed_count, g_listui_cntx_p->playing.failed_nofile);
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_do_pick
 * DESCRIPTION
 *  do pick
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
    mmi_event_struct evt;
    S32 ret;
    U8  repeat_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*save user rating, before pick next file*/
    mmi_medply_plst_store_rating_flush();

    /* 
     * if do pick fail before, do not pick again, 
     * because control will call do pick twice if fail
     */
    if ((g_listui_cntx_p->playing.last_error < 0) && 
        (g_listui_cntx_p->playing.last_error != SRV_PLST_RET_EMPTY))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DO_PICK_ERROR, 
                         g_listui_cntx_p->playing.last_error);
        g_listui_cntx_p->playing.last_error = 0;
        return -1;
    }
    
	ret = srv_plst_get_active_plst_item_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                              &g_listui_cntx_p->playing.total);
    if (ret < 0 && ret != SRV_PLST_RET_EMPTY)
    {
        g_listui_cntx_p->playing.last_error = ret;
        return ret;
    } 
    
    ret = srv_plst_plst_item_get_active_media_info_auto(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                           &g_listui_cntx_p->playing.id, 
                                           &g_listui_cntx_p->playing.pick_index, 
                                           NULL);    
    if (ret < 0 && ret != SRV_PLST_RET_EMPTY)
    {
        g_listui_cntx_p->playing.last_error = ret;
        return ret;
    }   

    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_REPEAT,&repeat_mode);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_DO_PICK,
                     g_listui_cntx_p->playing.total, g_listui_cntx_p->playing.failed_count, 
                     g_listui_cntx_p->playing.failed_nofile, repeat_mode);
    
    switch(repeat_mode)
    {
    case MMI_MEDPLY_REPEAT_ONE: /*never return SRV_PLST_RET_EMPTY in this case*/
        if (MMI_TRUE == g_listui_cntx_p->playing.is_play_fail)
        {
            ret = SRV_PLST_RET_EMPTY;
            if (1 == g_listui_cntx_p->playing.failed_nofile)
            {
                MMI_FRM_INIT_EVENT(&evt, 0);
                MMI_FRM_POST_EVENT(&evt,mmi_medply_plst_event_callback_hdlr,NULL);
            }            
        }        
        g_listui_cntx_p->playing.failed_count  = 0;
        g_listui_cntx_p->playing.failed_nofile = 0;
        break;

    case MMI_MEDPLY_REPEAT_ALL:
        if (SRV_PLST_RET_EMPTY == ret)
        {
            if (g_listui_cntx_p->playing.failed_count >= g_listui_cntx_p->playing.total)
            {
                if (g_listui_cntx_p->playing.failed_nofile == g_listui_cntx_p->playing.failed_count)
                {
                    MMI_FRM_INIT_EVENT(&evt, 0);
                    MMI_FRM_POST_EVENT(&evt,mmi_medply_plst_event_callback_hdlr,NULL);
                    ret = SRV_PLST_RET_EMPTY;
                }                
            }
            else
            {
                ret = 0;
            }
            g_listui_cntx_p->playing.failed_count  = 0;
            g_listui_cntx_p->playing.failed_nofile = 0;
        }
        break;
        
    case MMI_MEDPLY_REPEAT_OFF:
        if (SRV_PLST_RET_EMPTY == ret)
        {
            if (g_listui_cntx_p->playing.failed_count >= g_listui_cntx_p->playing.total)
            {
                if (g_listui_cntx_p->playing.failed_nofile == g_listui_cntx_p->playing.failed_count)
                {
                    MMI_FRM_INIT_EVENT(&evt, 0);
                    MMI_FRM_POST_EVENT(&evt,mmi_medply_plst_event_callback_hdlr,NULL);
                }                
            }
            g_listui_cntx_p->playing.failed_count  = 0;
            g_listui_cntx_p->playing.failed_nofile = 0;
        }
        break;

    default:
        /* No default */
        ASSERT(0);
        break;        
    }
    g_listui_cntx_p->playing.is_play_fail = MMI_FALSE;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_pick_next
 * DESCRIPTION
 *  pick the next song from play list
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
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*save user rating, before pick next file*/
    mmi_medply_plst_store_rating_flush();
    
    ret = srv_plst_plst_item_get_active_media_info_manul_next(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                           &g_listui_cntx_p->playing.id, 
                                           &g_listui_cntx_p->playing.pick_index, 
                                           NULL);

    g_listui_cntx_p->playing.failed_count  = 0;
    g_listui_cntx_p->playing.failed_nofile = 0;
    g_listui_cntx_p->playing.is_play_fail  = MMI_FALSE;
    g_listui_cntx_p->playing.last_error    = ret;        
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_pick_prev
 * DESCRIPTION
 *  pick the previous song from play list
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
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*save user rating, before pick next file*/
    mmi_medply_plst_store_rating_flush();
    
    ret = srv_plst_plst_item_get_active_media_info_manul_prev(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                           &g_listui_cntx_p->playing.id, 
                                           &g_listui_cntx_p->playing.pick_index, 
                                           NULL);

    g_listui_cntx_p->playing.failed_count  = 0;
    g_listui_cntx_p->playing.failed_nofile = 0;
    g_listui_cntx_p->playing.is_play_fail  = MMI_FALSE;
    g_listui_cntx_p->playing.last_error    = ret;
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_is_valid
 * DESCRIPTION
 *  
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
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    ret = srv_plst_plst_get_active_plst_id(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                           &g_listui_cntx_p->playing.plst_id);

    if (SRV_PLST_OK == ret)
    {
        if(g_listui_cntx_p->playing.plst_id > 0)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
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
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_MODULE_DEINIT);

    if (NULL == g_listui_cntx_p->srv_cntx.mem_ptr)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_MODULE_DEINIT_ERROR);
        return;
    }

    srv_plst_library_close(g_listui_cntx_p->srv_cntx.srv_hdlr);
    srv_plst_destroy(g_listui_cntx_p->srv_cntx.srv_hdlr);
    
    kal_adm_delete(g_listui_cntx_p->srv_cntx.mem_ptr);

    mmi_medply_plst_clear_context_variables();
    memset(g_listui_cntx_p, 0, sizeof(mmi_medply_listui_context_struct));
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_hilite_hdlr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_medply_plst_hilite_hdlr_init(void)
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
 *  mmi_medply_plst_get_current_artwork
 * DESCRIPTION
 *  extract filename icon
 * PARAMETERS
 *  file_format        [IN]        
 * RETURNS
 *  return icon id
 *****************************************************************************/
S32 mmi_medply_plst_get_current_artwork(void* buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct artwork_info;
    U32 media_id;
    S32 ret = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*get details structure*/ 
    ret = srv_plst_plst_item_get_active_media_info_curr(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                        &media_id, &g_listui_cntx_p->playing.pick_index, NULL);

    if (SRV_PLST_OK == ret)
    {
        artwork_info.index = media_id;
        artwork_info.buff_size = buffer_size;
        artwork_info.string_ptr= (U32)buffer;
        ret = srv_plst_list_get_artwork_by_media_id(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                    &artwork_info);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_current_artwork_ex
 * DESCRIPTION
 *  extract filename icon
 * PARAMETERS
 *  file_format        [IN]        
 * RETURNS
 *  return icon id
 *****************************************************************************/
S32 mmi_medply_plst_get_current_artwork_ex(void* buffer, U32* buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_get_display_struct artwork_info;
    U32 media_id;
    S32 ret = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*get details structure*/ 
    ret = srv_plst_plst_item_get_active_media_info_curr(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                        &media_id, &g_listui_cntx_p->playing.pick_index, NULL);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_ARTWORK_EX, media_id);

    if (SRV_PLST_OK == ret)
    {
        artwork_info.index = media_id;
        artwork_info.buff_size = *buffer_size;
        artwork_info.string_ptr= (U32)buffer;
        ret = srv_plst_list_get_artwork_by_media_id(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                    &artwork_info);
        *buffer_size = artwork_info.buff_size;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_ARTWORK_EX_RET,
                         ret, artwork_info.buff_size, artwork_info.index);
    }
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_current_details
 * DESCRIPTION
 *  extract filename icon
 * PARAMETERS
 *  file_format        [IN]        
 * RETURNS
 *  return icon id
 *****************************************************************************/
S32 mmi_medply_plst_get_current_details(mmi_medply_details_for_display_struct* details_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_media_details_struct* data_p = NULL;
    S32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    details_data->user_rating = 0;
    
    data_p = kal_adm_alloc(g_medply.adm_id_p, sizeof(srv_plst_media_details_struct));
    if (NULL != data_p)
    {
        /*get details structure*/ 
        ret = mmi_medply_listui_get_playing_file_details(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                        data_p);
        if (ret < SRV_PLST_OK)
        {
            kal_adm_free(g_medply.adm_id_p, data_p);
            return ret;
        }

        mmi_ucs2ncpy((CHAR*) details_data->title, (CHAR*) data_p->title, MMI_MEDPLY_MAX_TITLE_LEN);
        mmi_ucs2ncpy((CHAR*) details_data->artist,(CHAR*) data_p->artist, MMI_MEDPLY_MAX_ARTISRT_LEN);
        mmi_ucs2ncpy((CHAR*) details_data->album, (CHAR*) data_p->album, MMI_MEDPLY_MAX_ALBUM_LEN);
        details_data->user_rating = data_p->user_rating; 
        details_data->artwork.mime_type = META_TAG_IMG_JPG;
        
        kal_adm_free(g_medply.adm_id_p, data_p);
        if (g_listui_cntx_p->details_info.rating_update_flag)
        {            
            g_listui_cntx_p->details_info.rating_update_flag = 0;
            g_listui_cntx_p->details_info.temp_rating = details_data->user_rating;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_CURRENT_DETAILS_DB, 
                             details_data->user_rating);
        }
        else
        {
            /* Use temp value , that maybe already change by user */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_CURRENT_DETAILS_TEMP, 
                             details_data->user_rating);
            details_data->user_rating = g_listui_cntx_p->details_info.temp_rating;
        }        
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_store_rating
* DESCRIPTION
*  Store user rating. 
* PARAMETERS
*  x,y,w,h: region size       
* RETURNS
*  layer handle
 *****************************************************************************/
extern void mmi_medply_plst_store_rating(U8 rating)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_store_rating_smart(rating);
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_store_rating_smart
* DESCRIPTION
*  Store user rating. 
* PARAMETERS
*  x,y,w,h: region size       
* RETURNS
*  layer handle
 *****************************************************************************/
extern void mmi_medply_plst_store_rating_smart(U8 rating)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_STORE_RATING_SMART, rating);
    g_listui_cntx_p->details_info.modify_rate_by_mscr = MMI_TRUE;
    g_listui_cntx_p->details_info.temp_rating = rating;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_plst_store_rating_flush
* DESCRIPTION
*  Store user rating. 
* PARAMETERS
*  x,y,w,h: region size       
* RETURNS
*  layer handle
 *****************************************************************************/
extern void mmi_medply_plst_store_rating_flush(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 media_id;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_listui_cntx_p || (NULL != g_listui_cntx_p->details_info.raw_p))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_STORE_RATING_FLASH_NO_CONTEXT);
        return;
    }
    
    if (MMI_FALSE == g_listui_cntx_p->details_info.modify_rate_by_mscr)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_STORE_RATING_FLASH_DO_NOTHING);
        return;
    }
    //g_listui_cntx_p->details_info.modify_flag &= ~ MEDPLY_DB_UPDATE_RATING;
    g_listui_cntx_p->details_info.modify_rate_by_mscr = MMI_FALSE;
    
    if ((NULL == g_medply.adm_id_p) || (0 == g_listui_cntx_p->srv_cntx.srv_hdlr))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_STORE_RATING_FLASH_STATE_WRONG,
                         g_listui_cntx_p->srv_cntx.srv_hdlr, g_listui_cntx_p->srv_cntx.srv_hdlr);
        return;
    }
        
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_STORE_RATING_FLASH, 
                     g_listui_cntx_p->details_info.temp_rating);
    g_listui_cntx_p->details_info.raw_p = 
                    kal_adm_alloc(g_medply.adm_id_p, sizeof(srv_plst_media_details_struct));
    if (NULL != g_listui_cntx_p->details_info.raw_p)
    {
        /*get details structure*/ 
        ret = srv_plst_plst_item_get_active_media_info_curr(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                        &media_id, &g_listui_cntx_p->playing.pick_index, NULL);
        if (SRV_PLST_OK == ret)
        {
            ret = srv_plst_media_get_details(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                             media_id, 
                                             g_listui_cntx_p->details_info.raw_p);
            if (ret == SRV_PLST_OK)
            {
                g_listui_cntx_p->details_info.raw_p->user_rating = g_listui_cntx_p->details_info.temp_rating;
                g_listui_cntx_p->details_info.rating_update_flag = 1;
                ret = srv_plst_media_update_details(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                media_id,
                                                g_listui_cntx_p->details_info.raw_p);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_STORE_RATING_FLASH_RET, ret);
            }
        }
        kal_adm_free(g_medply.adm_id_p, g_listui_cntx_p->details_info.raw_p);
        g_listui_cntx_p->details_info.raw_p = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_get_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_curr_get_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_plst_get_active_plst_item_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                        &g_listui_cntx_p->playing.total);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_GET_TOTAL,g_listui_cntx_p->playing.total);
    
    return g_listui_cntx_p->playing.total;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_get_curr_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_curr_get_curr_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_listui_cntx_p->playing.pick_index;
}


#ifdef __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__
extern S32 vapp_image_flow_startup(U16 grp_id, U16 scr_id);
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_entry_image_flow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_listui_entry_image_flow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (LIST_TYPE_ALBUM_LIST == g_listui_cntx_p->view_stack.list_type[g_listui_cntx_p->view_stack.curr_ptr])
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_ENTRY_IMAGE_FLOW,
                         g_listui_cntx_p->list_info.highlight);
        g_listui_cntx_p->list_info.imgfl_index = g_listui_cntx_p->list_info.highlight;
    }


    vapp_image_flow_startup(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_IMAGE_FLOW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_exit_image_flow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
MMI_BOOL mmi_medply_listui_exit_image_flow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        return MMI_FALSE;
    }

    if (LIST_TYPE_ALBUM_LIST == g_listui_cntx_p->view_stack.list_type[g_listui_cntx_p->view_stack.curr_ptr])
    {
        g_listui_cntx_p->list_info.highlight = g_listui_cntx_p->list_info.imgfl_index;
        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS);
        if (guiBuffer)
        {
            list_menu_category_history *hist = (list_menu_category_history*)guiBuffer;
            hist->highlighted_item = g_listui_cntx_p->list_info.highlight;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EXIT_IMAGE_FLOW,
                         g_listui_cntx_p->list_info.highlight);
            return MMI_TRUE;
        }
    }
    else
    {
        mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                         &g_listui_cntx_p->view_stack);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_imgfl_delete_callback
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
mmi_ret mmi_medply_listui_imgfl_delete_callback(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:        
        if (LIST_TYPE_ALBUM_LIST == g_listui_cntx_p->view_stack.list_type[g_listui_cntx_p->view_stack.curr_ptr])
        {
            g_listui_cntx_p->list_info.highlight = g_listui_cntx_p->list_info.imgfl_index;
            guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS);
            if (guiBuffer)
            {
                list_menu_category_history *hist = (list_menu_category_history*)guiBuffer;
                hist->highlighted_item = g_listui_cntx_p->list_info.highlight;
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_IMGFL_DELETE_CALLBACK,
                             g_listui_cntx_p->list_info.highlight);
            }
        }
        else
        {
            mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                             &g_listui_cntx_p->view_stack);
        }               
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_current
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_listui_imgflow_listsrv_init(
            S32(*callback)(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        return MMI_FALSE;
    }

    if (!(g_listui_cntx_p->srv_cntx.state_flag & MMI_MEDPLY_LISTUI_HAS_SRV_OPEN))
    {
        return MMI_FALSE;
    }

    medply_list_extapp_cb = callback;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_current
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_listui_imgflow_listsrv_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        return MMI_FALSE;
    }

    if (!(g_listui_cntx_p->srv_cntx.state_flag & MMI_MEDPLY_LISTUI_HAS_SRV_OPEN))
    {
        return MMI_FALSE;
    }

    medply_list_extapp_cb = NULL;
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_current
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_listui_imgflow_get_count(U32* total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *total = 0;    
    if (NULL == g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        return -1;
    }
    return mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, total);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_song_title
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_listui_imgflow_get_item_name(srv_plst_list_get_display_struct* item_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ret = srv_plst_list_get_item_display(g_listui_cntx_p->srv_cntx.srv_hdlr, item_display); 

    return ret;
}


S32 mmi_medply_listui_imgflow_get_artist(srv_plst_list_get_display_struct* item_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_get_context_struct*   out_para_p;
    srv_plst_get_cntx_param_struct in_para;
    S32 ret;
    U32 media_id; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ret = srv_plst_media_get_id(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                item_display->index, &media_id);
    if (SRV_PLST_OK == ret)
    {
        in_para.id = media_id;
        in_para.get_type = SRV_PLST_CNTX_TYPE_ARTISTNAME;
        in_para.id_enum = SRV_PLST_TYPE_ID_ALBUM;
        out_para_p = (srv_plst_get_context_struct*)item_display->string_ptr;
        ret = srv_plst_list_get_context_by_id(g_listui_cntx_p->srv_cntx.srv_hdlr, &in_para, out_para_p);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_song_title
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_listui_imgflow_get_artwork_aync(srv_plst_list_get_display_struct* param_artwork)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        return -1;
    }
    ret = srv_plst_list_get_item_artwork_async(g_listui_cntx_p->srv_cntx.srv_hdlr, param_artwork);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_get_song_title
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_listui_imgflow_get_artwork_aync_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == g_listui_cntx_p->srv_cntx.srv_hdlr)
    {
        return -1;
    }
    return srv_plst_list_get_item_artwork_async_stop(g_listui_cntx_p->srv_cntx.srv_hdlr); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_if_get_focus_idx
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_listui_imgflow_get_focus_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_listui_cntx_p)
    {
        return g_listui_cntx_p->list_info.imgfl_index;
    } 
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_if_set_focus_idx
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_listui_imgflow_set_focus_idx(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != g_listui_cntx_p)
    {
        g_listui_cntx_p->list_info.imgfl_index = (S32)index;
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_if_set_focus_idx
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_listui_imgflow_play(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_IMAGEFLOW_PLAY_BEGIN);
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return MMI_FALSE;
    }
#endif

    /*play from the first one*/
    g_listui_cntx_p->playing.pick_index = 0;

    ret = mmi_medply_plst_set_pick_index(index);
    if (ret >= SRV_PLST_OK)
    {        
        mmi_medply_listui_common_begin_play();
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_IMAGEFLOW_PLAY_END);
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_IMAGE_FLOW);
        return MMI_TRUE;
    }
    else
    {
        mmi_medply_listui_popup_error(ret);
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_IMAGE_FLOW);
        return MMI_FALSE;
    }
}

#if (defined(MOTION_SENSOR_SUPPORT) && defined(__MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_tilt_hdlr
 * DESCRIPTION
 *  tilt motin handler
 * PARAMETERS
 *  dirsct  [IN]
 *  action  [IN]
 *  detail  [IN]
 *  user data [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_listui_tilt_hdlr(srv_sensor_type_enum sensor_type, void *sensor_data,
							void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL switch_by_motion;
    MMI_ID   active_scr_id;

    srv_sensor_motion_direct_enum direction;
    srv_sensor_motion_action_enum action;
    srv_sensor_motion_direct_struct *p_direct;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    p_direct = (srv_sensor_motion_direct_struct *)sensor_data;
    direction = p_direct->direct;
    action = p_direct->action;
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_MOTION_DIRECTION, 
                     direction, action, g_listui_cntx_p->tilt_state);
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_MOTIONSENSOR, (void*)&switch_by_motion);
    active_scr_id = mmi_frm_scrn_get_active_id();
    
    if(!switch_by_motion)
    {
        return;
    }
    /* motion senser init state */
    if (SRV_SENSOR_MOTION_ACTION_NULL == action)
    {
        if (LISTUI_TILT_STATE_INIT == g_listui_cntx_p->tilt_state)
        {
            switch(direction)
            {
                case SRV_SENSOR_MOTION_ANGLE_GX180:
                    g_listui_cntx_p->tilt_state = LISTUI_TILT_STATE_HORIZ;
                    break;
                case SRV_SENSOR_MOTION_ANGLE_GY180:
                    g_listui_cntx_p->tilt_state = LISTUI_TILT_STATE_VERTI;
                    break;
                default:
                    break;
            }
        }
        return;
    }
       
    switch(direction)
    {
    case SRV_SENSOR_MOTION_ANGLE_GX180:
        /*horizontal*/
        if (LISTUI_TILT_STATE_HORIZ != g_listui_cntx_p->tilt_state)
        {
            g_listui_cntx_p->tilt_state = LISTUI_TILT_STATE_HORIZ;
            if (mmi_medply_listui_check_motion_valid(active_scr_id))
            {
                mmi_medply_listui_entry_image_flow();
            }
        }        
        break;
     
    case SRV_SENSOR_MOTION_ANGLE_GY180:
        /*vertical*/
        if (LISTUI_TILT_STATE_VERTI != g_listui_cntx_p->tilt_state)
        {
            g_listui_cntx_p->tilt_state = LISTUI_TILT_STATE_VERTI;
            if (SCR_ID_MEDPLY_LISTUI_IMAGE_FLOW == active_scr_id)
            {
                mmi_frm_scrn_close_active_id();
            }
        }        
        break;
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_check_motion_valid
 * DESCRIPTION
 *  tilt motin handler
 * PARAMETERS
 *   
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_listui_check_motion_valid(MMI_ID scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 total;
    MMI_BOOL bRet = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(scr_id)
    {
    case SCR_ID_MEDPLY_LISTUI_ALL_SONGS:
    case SCR_ID_MEDPLY_LISTUI_ALL_ARTISTS:   
    case SCR_ID_MEDPLY_LISTUI_ALL_GENRES:
    case SCR_ID_MEDPLY_LISTUI_ALL_PLSTS:
    //case SCR_ID_MEDPLY_LISTUI_ACTIVE_LIST:
    case SCR_ID_MEDPLY_LISTUI_SONGS:
    case SCR_ID_MEDPLY_LISTUI_ARTIST_ALBUMS:
        ret = mmi_medply_listui_prepare_image_flow(g_listui_cntx_p->srv_cntx.srv_hdlr,
                                                   LIST_TYPE_IMAGE_FLOW,
                                                   &g_listui_cntx_p->view_stack);

        if (ret < SRV_PLST_OK)
        {
            mmi_medply_listui_popup_error(ret);
            return MMI_FALSE;
        }
        ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                    &total);
        if (total > 0)
        {
            g_listui_cntx_p->list_info.imgfl_index = 0;
            bRet = MMI_TRUE;
        }
        else
        {
            mmi_medply_listui_pop_view_stack(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                             &g_listui_cntx_p->view_stack);
            bRet = MMI_FALSE;
        }        
        break;
        
    case SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS:
        ret = mmi_medply_listui_get_curr_list_count(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                                    &total);
        if (total > 0)
        {
            bRet = MMI_TRUE;
        }
        else
        {
            bRet = MMI_FALSE;
        }  
        break;

    default:
        break;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_CHECK_MOTION_VALID, bRet);
    return bRet;
}

#endif /* MOTION_SENSOR_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_entry_skin_select_file
 * DESCRIPTION
 *  select skin file 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_edit_elbum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
#ifdef __GDI_MEMORY_PROFILE_2__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
#ifdef GDI_USING_PNG
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
#endif 
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    g_listui_cntx_p->list_info.child_id = cui_file_selector_create(
                                            GRP_ID_MEDPLY_FTE_SUB_MENU,
                                            (WCHAR*) L"root",
                                            &filter,
                                            CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                                            CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON);

    if (g_listui_cntx_p->list_info.child_id > 0)
    {
        cui_file_selector_set_userdata(g_listui_cntx_p->list_info.child_id, (U32) LISTUI_FMGR_EDIT_ALBUM);        
        cui_file_selector_run(g_listui_cntx_p->list_info.child_id);
    }
    else
    {   
        mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_NOT_AVAILABLE),
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        mmi_frm_ui_force_update_now();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_edit_album_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_edit_album_hdlr(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_select->result > 0)
    {
        g_skin_custom_path[0] = '\0';
        g_skin_custom_path[1] = '\0';
        cui_file_selector_get_selected_filepath(
                                g_listui_cntx_p->list_info.child_id,
                                NULL,
                                (WCHAR *) g_skin_custom_path,
                                SRV_FMGR_PATH_BUFFER_SIZE);
        
        mmi_medply_listui_cover_select_callback();
        /*
        if (mmi_medply_listui_cover_select_callback())
        {
            cui_file_selector_close(g_listui_cntx_p->list_info.child_id);
            g_listui_cntx_p->list_info.child_id = 0;
        }*/
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(g_listui_cntx_p->list_info.child_id);
        g_listui_cntx_p->list_info.child_id = 0;
    }
    else
    {
        mmi_popup_display_simple((WCHAR*)GetString(srv_fmgr_fs_error_get_string(file_select->result)),
                                 (mmi_event_notify_enum) srv_fmgr_fs_error_get_popup_type(file_select->result),
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);

        cui_file_selector_close(g_listui_cntx_p->list_info.child_id);
        g_listui_cntx_p->list_info.child_id = 0;
        mmi_frm_ui_force_update_now();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_cover_select_callback
 * DESCRIPTION
 *  callback after select file from fmgr
 * PARAMETERS
 *  filepath [IN]  file path of skin
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_listui_cover_select_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 strlen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlen = mmi_ucs2strlen((CHAR*)g_skin_custom_path);
    if (strlen > SRV_FMGR_PATH_MAX_LEN)
    {
        mmi_popup_display_simple((U16*)get_string(srv_fmgr_fs_error_get_string(FS_PATH_OVER_LEN_ERROR)),
                                 (mmi_event_notify_enum) srv_fmgr_fs_error_get_popup_type(FS_PATH_OVER_LEN_ERROR),
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        mmi_frm_ui_force_update_now();
        return MMI_FALSE;
    }
    
    ASSERT(g_skin_custom_path != NULL);
    if (mmi_medply_listui_cover_check_valid())
    {
        mmi_medply_listui_enter_cover_preview();
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_cover_check_valid
 * DESCRIPTION
 *  callback after select file from fmgr
 * PARAMETERS
 *  filepath [IN]  file path of skin
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_listui_cover_check_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE  hdl;
    GDI_RESULT res;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hdl = DRM_open_file((PU16)g_skin_custom_path, FS_READ_ONLY,DRM_PERMISSION_DISPLAY);
    if (hdl < FS_NO_ERROR)
    {
        mmi_popup_display_simple((U16*)get_string(srv_fmgr_fs_error_get_string(hdl)),
                                 (mmi_event_notify_enum) srv_fmgr_fs_error_get_popup_type(hdl),
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        return MMI_FALSE;
    }

#ifdef __DRM_SUPPORT__
    if (DRM_get_object_method(hdl, NULL) != DRM_METHOD_NONE)
    {
        mmi_popup_display_simple((U16*)get_string(STR_GLOBAL_DRM_PROHIBITED),
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        DRM_close_file(hdl);
        return MMI_FALSE;
    }
#endif
    DRM_close_file(hdl);

    res = gdi_image_get_dimension_file((CHAR*)g_skin_custom_path, &width, &height);
    if (res < 0)
    {
        mmi_popup_display_simple((U16*)get_string(STR_GLOBAL_UNSUPPORTED_FORMAT),
                                 MMI_EVENT_ERROR,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        return MMI_FALSE;
    }
    else if (((4 * width) < UI_device_width) || ((4 * height) < UI_device_height))
    {
        mmi_popup_display_simple((U16*)get_string(STR_ID_MEDPLY_ERROR_FILE_TOO_SMALL),
                                 MMI_EVENT_ERROR,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        return MMI_FALSE;
    }
    else if ((width > (2 * UI_device_width)) || (height > (2 * UI_device_height)))
    {
        mmi_popup_display_simple((U16*)get_string(STR_ID_MEDPLY_ERROR_FILE_TOO_LARGE),
                                 MMI_EVENT_ERROR,
                                 GRP_ID_MEDPLY_FTE,
                                 NULL);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_enter_cover_preview
 * DESCRIPTION
 *  callback after select file from fmgr
 * PARAMETERS
 *  filepath [IN]  file path of skin
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_enter_cover_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_COVER_PREVIEW, NULL, 
                                   mmi_medply_listui_enter_cover_preview, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    

    ShowCategory222Screen(
        STR_GLOBAL_PREVIEW,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_BLACK,
        (CHAR*) NULL,
        (CHAR*) g_skin_custom_path,
        FALSE,
        mmi_medply_listui_cover_preview_callback,
        GDI_IMAGE_SRC_FROM_FILE);

    SetLeftSoftkeyFunction(mmi_medply_listui_select_cover_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_medply_listui_select_cover_back, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_select_cover_done
 * DESCRIPTION
 *  select skin done
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_select_cover_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_listui_util_set_cache_mem(LCD_WIDTH * LCD_HEIGHT * 2);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SELECT_COVER_DONE, g_listui_cntx_p->list_info.highlight);
    ret = srv_plst_list_update_item_artwork(g_listui_cntx_p->srv_cntx.srv_hdlr, 
                                            (U32)g_listui_cntx_p->list_info.highlight, 
                                            (U16*) g_skin_custom_path);
    mmi_medply_listui_util_clear_cache_mem();
    if (SRV_PLST_OK == ret)
    {
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
    }
    else
    {
        mmi_medply_listui_popup_error(ret);
    }
    if (g_listui_cntx_p->list_info.child_id > 0)
    {
        cui_file_selector_close(g_listui_cntx_p->list_info.child_id);
        g_listui_cntx_p->list_info.child_id = 0;
    }
    mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_COVER_PREVIEW);
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if (g_listui_cntx_p->list_info.flag & MMI_MEDPLY_LISTUI_IS_SEARCH)
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_PREFIX_SEARCH);    
    }   
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_select_cover_back
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_select_cover_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_skin_preview_callback
 * DESCRIPTION
 *  preview skin callback
 * PARAMETERS
 *  result [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_cover_preview_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        ChangeLeftSoftkey(0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_settings_skin_preview_callback
 * DESCRIPTION
 *  preview skin callback
 * PARAMETERS
 *  result [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_listui_exit_edit_elbum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                                SCR_ID_MEDPLY_LISTUI_ALL_ALBUMS, 
                                MMI_FRM_NODE_ALL_FLAG))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EXIT_EDIT_ALBUM);
        mmi_frm_scrn_close(GRP_ID_MEDPLY_FTE_SUB_MENU, SCR_ID_MEDPLY_LISTUI_COVER_PREVIEW);
        if (g_listui_cntx_p->list_info.child_id > 0)
        {
            cui_file_selector_close(g_listui_cntx_p->list_info.child_id);
            g_listui_cntx_p->list_info.child_id = 0;
        }
    }
}


#endif /* __MMI_MEDIA_PLAYER_IMAGE_FLOW_SUPPORT__ */

#if defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_list_extapp_startup
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_list_extapp_startup(S32 *p_handle, 
                    S32(*callback)(srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    void* adm_p_plst = NULL;
    MMI_BOOL is_start_new;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_EXTAPP_STARTUP);

#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        /*should not popup*/
        return -1;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    if (g_medply.adm_id_p != NULL)
    {
        if (NULL != g_listui_cntx_p->srv_cntx.srv_hdlr)
        {
            ret = 0;
            is_start_new = MMI_FALSE;
        }
        else
        {
            ret = mmi_medply_plst_init_for_extapp();
            is_start_new = MMI_TRUE;
        }
    }
    else
    {
        is_start_new = MMI_TRUE;
        /* set App-based ASM. */
        g_medply.mem_pool_p = g_medply_mem_pool;
        if (g_medply.mem_pool_p != NULL)
        {
            if(g_medply.medply_adm_id_p == NULL)
            {
                g_medply.medply_adm_id_p = kal_adm_create(g_medply.mem_pool_p, MMI_MEDPLY_MEM_POOL_SIZE, NULL, KAL_FALSE);
                MMI_ASSERT(g_medply.medply_adm_id_p != NULL);
                /*adm_p_plst = kal_adm_alloc(g_medply.medply_adm_id_p,MEDPLY_PLST_APP_MEM_SIZE);*/
                adm_p_plst = kal_adm_alloc(g_medply.medply_adm_id_p,MEPDLY_PLST_COMMON_APP_MEM_SIZE);
                MMI_ASSERT(adm_p_plst != NULL);
            }
        }
    
        if (g_medply.adm_id_p == NULL)
        {
            /*g_medply.adm_id_p = kal_adm_create(adm_p_plst, MEDPLY_PLST_APP_MEM_SIZE, NULL, KAL_FALSE);*/
            g_medply.adm_id_p = kal_adm_create(adm_p_plst, MEPDLY_PLST_COMMON_APP_MEM_SIZE, NULL, KAL_FALSE);
            MMI_ASSERT(g_medply.adm_id_p != NULL);
            /* do initialization in this function, like module init or ASM allocate. */
            ret = mmi_medply_plst_init_for_extapp();            
        }
    }  
    if (ret >= 0)
    {
        *p_handle = g_listui_cntx_p->srv_cntx.srv_hdlr;
        medply_list_extapp_cb = callback;
        if (is_start_new)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_INIT_AND_RELOAD);
            mmi_medply_plst_load_last();
            if (g_medply.state == MEDPLY_STATE_IDLE)
            {
                switch(g_medply.media_type)
                {
                case MEDPLY_TYPE_AUDIO:
                    g_medply.state = MEDPLY_STATE_AUDIO_READY;
                    break;
                case MEDPLY_TYPE_VIDEO:
                    g_medply.state = MEDPLY_STATE_PURE_AUDIO_READY;
                    break;
                case MEDPLY_TYPE_STREAM:
                    g_medply.state = MEDPLY_STATE_STREAM_IDLE;
                    break;
                default:
                    break;
                }
            }
        }       
    }
    else
    {
        mmi_medply_plst_module_deinit();
        /* delete adm */
        if (g_medply.adm_id_p != NULL)
        {
            kal_adm_delete(g_medply.adm_id_p);
            g_medply.adm_id_p = NULL;
        }   

        if(g_medply.medply_adm_id_p != NULL)
        {
            kal_adm_delete(g_medply.medply_adm_id_p);
            g_medply.medply_adm_id_p = NULL;
        }
        g_medply.mem_pool_p = NULL;
        
        medply_list_extapp_cb = NULL;
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_list_extapp_logoff
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_list_extapp_logoff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    medply_list_extapp_cb = NULL;
}

#endif  /* defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__) */

mmi_id g_medply_listui_main_menu_grp_id;

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_set_main_menu_grp_id
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_listui_set_main_menu_cui_grp_id(mmi_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_medply_listui_main_menu_grp_id = menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_is_main_menu_grp_created
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_listui_is_main_menu_grp_created(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply_listui_main_menu_grp_id != GRP_ID_INVALID)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

static MMI_BOOL g_medply_listui_is_goback_inendkey;
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_set_goback_inendkey
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_listui_set_goback_inendkey(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_SET_GOBACK_INEDNKEY, flag);
    g_medply_listui_is_goback_inendkey = flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_listui_set_goback_inendkey
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_listui_is_goback_inendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLSTUI_IS_GOBACK_INENDKEY, g_medply_listui_is_goback_inendkey);
    return g_medply_listui_is_goback_inendkey;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_prepare_mediaplayer
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_prepare_mediaplayer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_medply_plst_load_last();
    if (g_medply.state == MEDPLY_STATE_IDLE)
    {
        switch(g_medply.media_type)
        {
        case MEDPLY_TYPE_AUDIO:
            g_medply.state = MEDPLY_STATE_AUDIO_READY;
            break;
        case MEDPLY_TYPE_VIDEO:
            g_medply.state = MEDPLY_STATE_PURE_AUDIO_READY;
            break;
        case MEDPLY_TYPE_STREAM:
            g_medply.state = MEDPLY_STATE_STREAM_IDLE;
            break;
        default:
            break;
        }
    }
}


#define __DO_NOTHING_BUT_DEF__
void mmi_medply_plst_entry_listmgr(void){}
void mmi_medply_plst_entry_bookmark(void){}
void mmi_medply_plst_entry_now_playing(){}
void mmi_medply_plst_entry_details(void){}
void mmi_medply_history_insert_url(CHAR* url_p, CHAR* name_p, MMI_BOOL is_single){}
S32 mmi_medply_plst_get_kurofile_path(UI_string_type filepath){return 0;}
void mmi_medply_shuffle_change_callback(U8 new_value){}
void mmi_medply_plst_set_start(S32 index){}
void mmi_medply_plst_pre_format_hdlr(CHAR drv){}
void mmi_medply_plst_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list){}
void mmi_medply_plst_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list){}
void mmi_medply_plst_usb_plug_in_hdlr(void){}
void mmi_medply_plst_usb_plug_out_hdlr(void){}
void mmi_medply_plst_msdc_entry_unmount(CHAR drv){}


#endif /*__MMI_MEDIA_PLAYER_PLST_DB_STYLE__*/

