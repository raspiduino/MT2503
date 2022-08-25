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
 *   mdi_audio.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements MDI audio funtions
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "MMI_features.h"

//#include "stdC.h"
//#include "mmi_platform.h"
//#include "mmi_frm_gprot.h"
#include "kal_trace.h"  /* Debug Info */
//#include "ProtocolEvents.h"
//#include "ProfileGProts.h"
#include "ProfilesSrvGprot.h"
//#include "BTMMISCOPathGprots.h"
#include "BthScoPathSrvGProt.h"
#include "stack_config.h"

//#include "GlobalDefs.h"
//#include "mdi_resdef.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "resource_audio.h"
#include "aud_defs.h"
#include "aud_build_cache.h"
#include "med_global.h"
#include "med_struct.h"
#include "med_v_struct.h"
#include "med_api.h"
#include "med_main.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "drm_errcode.h"
#include "kal_public_api.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "gui_data_types.h"
#include "app_ltlcom.h"
//#include "kal_active_module.h"
#include "mmiapi_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_ltlcom.h"
#include "stack_common.h"
#include "mmi_res_range_def.h"
#include "mmi_pluto_res_range_def.h"
#include "string.h"
#include "l1audio.h"
#include "ShutdownSrvGprot.h" /*For Shutdown event */
#include "SoundEffect.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_rp_srv_mdi_def.h"
#include "GlobalResDef.h"
#include "device.h"
#include "gpiosrvgprot.h"
#include "wgui_categories_util.h"
#include "BtAudioSrvGprot.h"


#if defined(__MMI_A2DP_SUPPORT__)
#include "av_bt.h"
#endif

#if defined(__MMI_BT_AUDIO_SUPPORT__) || defined(__BT_SPK_VOL_CONTROL__)
//#include "CallManagementGProt.h"
#include "BTMMIScrGProts.h"
#endif

#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#endif

#ifdef __MMI_UCM__
#include "UcmSrvGprot.h"
//#include "UCMGProt.h"
#endif

#if defined(__MMI_ATV_SUPPORT__)
#include "mdi_mtv.h"
#endif

#if defined(__RF_DESENSE_TEST__)
#include "rf_desense_test.h"
#endif

#ifdef __GAIN_TABLE_SUPPORT__
#include "gain_table.h"
#endif /* __GAIN_TABLE_SUPPORT__ */

#ifdef DIGIT_TONE_SUPPORT
#include "mmi_rp_srv_prof_def.h"
#endif


/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
/* Source ID */
#define SRC_LMMI                   (0)

/* Volume control */
#define CRESCENDO_TIMER_TIMEOUT    (1000)
#define CRESCENDO_VOLUME_MIN       (0)
#define CRESCENDO_VOLUME_MAX       (6)

/* Playback */
typedef enum
{
    MDI_AUDIO_CHECK_REASON_PLAYBACK,
    MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK,
    MDI_AUDIO_CHECK_REASON_SND_RECORD,
    MDI_AUDIO_CHECK_REASON_FM_RECORD,

    MDI_AUDIO_CHECK_REASON_LAST_ENTRY
} mdi_audio_check_reason_enum;

typedef struct
{
    U8 app[MDI_BACKGROUND_APP_TOTAL];
    mdi_bg_callback handler[MDI_BACKGROUND_APP_TOTAL];
    void* user_data[MDI_BACKGROUND_APP_TOTAL];
} mdi_audio_background_handler_struct;

/* BT */
#define MDI_AUD_MAX_BT_VOL_NUM     (5)
    
#ifdef __MMI_BT_AUDIO_SUPPORT__
typedef struct
{
    mdi_bt_callback open_hdlr;
    mdi_bt_callback close_hdlr;
    U8 state;
    MMI_BOOL pending_connect;
    U16 connect_id;
} mdi_audio_bt_cntx_struct;
#endif /* __MMI_BT_AUDIO_SUPPORT__ */

#ifdef __BT_SPK_VOL_CONTROL__
typedef struct
{
    U32 app_id;
    MMI_BOOL(*callback)(U8 volume, MMI_BOOL is_mute);
    U8 volume_lvl_type;
} mdi_audio_bt_vol_struct;
#endif /* __BT_SPK_VOL_CONTROL__ */ 

/* Speech */
#define MDI_AUD_MIC_IDX_CALL 3   /* Volume level index in call */
#define MDI_AUD_MIC_IDX_IDLE 4   /* Volume level index in idle mode */

typedef struct
{
    MDI_AUDIO_SPEECH_APP_ID_ENUM type_id;
} mdi_audio_speech_cntx_struct;

/* MMA */
#define MMA_NO_OF_PLAYER (MMA_MAX_NUM+1) /* Max MMA players + 1 single player */

typedef struct
{
    mdi_handle handle;
    mdi_mma_callback callback;
    void* user_data;
    MMI_BOOL async_mode;
    U8 state;
    U8 format;
    U8 player_id;  /* Increase for each open request */
    U8 seq_id;     /* Increase for each stop request */
    U8 is_valid;
}mdi_audio_mma_player_struct;

#ifdef __AUDIO_ULTRA_SLIM__
typedef struct
{
	mdi_handle handle;
	mma_player_struct mma_para;
}mdi_audio_mma_slim_struct;
#endif

/* DRM */
#ifdef __DRM_SUPPORT__
typedef enum
{
    MDI_AUD_DRM_CONSUME_NONE,
    MDI_AUD_DRM_CONSUME_TIME_ONLY,
    MDI_AUD_DRM_CONSUME_ALL
} mdi_audio_drm_consume_rule_enum;
#endif /*__DRM_SUPPORT__*/


/* TTS */
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
#define MDI_MAX_PLAY_TEXT_LEN 60

typedef enum
{
    MDI_AUDIO_PLAY_TEXT_IDLE_STATE,
    MDI_AUDIO_PLAY_TEXT_PLAY_STATE,
    MDI_AUDIO_PLAY_TEXT_WAIT_STATE
} mdi_audio_play_text_state_enum;

typedef struct
{
    U16 identifier;
    U16 words[MDI_MAX_PLAY_TEXT_LEN];
    S32 len;
    S32 cursor;
    S32 msecs;
    mdi_ext_callback handler;
    void* user_data;
    mdi_audio_play_text_state_enum state;   /* 0: idle, 1: playing, 2: waiting for time out to play */
    U8 volume;
    U8 path;
} mdi_audio_play_text_struct;

typedef struct {
    short start;
    short end;
} mdi_start_end_t;
#endif /* #if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
/* State control */
static U8 mdi_audio_state;
static U8 mdi_audio_mode;
static U8 identifier;
static U8 g_audio_mode = 0;

/* Mutex/Semaphore */
volatile S16 g_mdi_audio_mutex_cnt = 0;
volatile module_type g_mdi_audio_mutex_tid = MOD_NIL;
kal_semid g_mdi_audio_sem;

/* Speech */
static MMI_BOOL mdi_speech_session_on;
static MMI_BOOL mdi_speech_codec_on = KAL_FALSE; /* Check if GSM/WCDMA speech on */
static mdi_audio_speech_cntx_struct mdi_audio_speech_cntx;

/* Volume control */
static kal_uint8 g_crescendo_volume = CRESCENDO_VOLUME_MIN;  /* Current crescendo volume */
static kal_uint8 g_crescendo_bound = CRESCENDO_VOLUME_MAX;   /* Upper bound of crescendo volume */

#ifdef __GAIN_TABLE_SUPPORT__
static mdi_audio_media_source_enum g_media_source = MDI_AUDIO_MEDIA_SOURCE_UNKNOWN;
static mdi_audio_type_enum g_audio_type = MDI_AUDIO_TYPE_UNKNOWN;
static mdi_audio_type_enum g_playback_type = MDI_AUDIO_TYPE_UNKNOWN;
static audio_type_enum g_audio_path = AUDIO_DEVICE_SPEAKER2;
static kal_bool  g_is_audio_type_specified = KAL_FALSE;
static kal_bool  g_is_sco_on = KAL_FALSE;
static kal_bool  g_is_a2dp_on = KAL_FALSE;
static kal_bool  g_is_camcorder_on = KAL_FALSE;
static kal_bool  g_is_voice_record_on = KAL_FALSE;
static kal_bool  g_is_fm_on = KAL_FALSE;
static kal_bool  g_is_atv_on = KAL_FALSE;
static kal_bool  g_is_in_call = KAL_FALSE;
static kal_uint8 g_crnt_volume[AUD_MAX_VOLUME_TYPE] = {0};
#endif /* __GAIN_TABLE_SUPPORT__ */

/* Background/interrupt handler */
static MMI_BOOL backgroud_enabled;
static U8 g_mdi_aud_suspend_app[MDI_AUD_SUSPEND_BG_TOTAL/8+1];
static mdi_audio_background_handler_struct background_handler;
static mdi_ext_callback mdi_cb_handler = NULL;
static mdi_ext_callback pseudo_play_handler = NULL;
static mdi_ext_callback interrupt_cb_handler = NULL;
static mdi_ext_callback tmp_cb_handler = NULL;
static void* mdi_cb_data = NULL;
static void* interrupt_cb_data = NULL;
static void* pseudo_play_data = NULL;

/* BT */
#ifdef __BT_SPK_VOL_CONTROL__
static U8 g_mdi_aud_bt_vol_count;
static U8 g_mdi_aud_last_bt_vol; /* latest volume sync from bt */
static mdi_audio_bt_vol_struct g_mdi_aud_bt_vol[MDI_AUD_MAX_BT_VOL_NUM];
#endif /* __BT_SPK_VOL_CONTROL__ */ 

/* FMR */
#if defined(__RF_DESENSE_TEST__)
static MMI_BOOL g_mdi_fm_desense = FALSE;
#endif

#ifdef __MMI_FM_RADIO__
#ifdef __FM_RADIO_RDS_SUPPORT__
static MMI_BOOL g_rds_enabled;
static void* g_rds_user_data = NULL;
#endif

#ifndef __PLUTO_MMI_PACKAGE__
static U8 g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
static mdi_fmr_scan_hdlr_struct g_mdi_fmr_scan_hdlr;
static mdi_fmr_seek_hdlr_struct g_mdi_fmr_seek_hdlr;
#endif /*__PLUTO_MMI_PACKAGE__*/


#if defined(__FM_RADIO_HW_SCAN__) || defined(__FM_RADIO_HW_SEARCH__)
static U8 g_mdi_fmr_scan_table[MDI_FMR_BANDWIDTH];
#endif /* __FM_RADIO_HW_SCAN__ || __FM_RADIO_HW_SEARCH__ */

#if !defined(__FM_RADIO_HW_SEARCH__)
static U8 g_mdi_fmr_signal_level[MDI_FMR_BANDWIDTH];
static U16 g_mdi_fmr_scan_count;
#endif /* !__FM_RADIO_HW_SEARCH__ */
#endif /*__MMI_FM_RADIO__*/

/* MMA */
static mdi_audio_mma_player_struct mdi_audio_mma_player[MMA_NO_OF_PLAYER];
static U16 mdi_audio_mma_player_id = 0;

#ifdef __AUDIO_ULTRA_SLIM__
static mdi_handle mma_handle = 0x00001111;
static mdi_audio_mma_slim_struct mdi_audio_mma_slim_player;
#endif 

/* DRM */
#ifdef __DRM_SUPPORT__
static mdi_audio_drm_consume_rule_enum mdi_audio_drm_consume_rule;
static S32 mdi_audio_drm_id;
static S32 mdi_audio_drm_mma_idx = -1;
static FS_HANDLE mdi_audio_drm_mma_handle = -1;
#if defined(BGSND_ENABLE)
static S32 mdi_audio_drm_bgsnd_id;
#endif
#endif /*__DRM_SUPPORT__*/

/* Auto answer mechine */
#if defined(__KEY_TONE_DETECTION__)
static MMI_BOOL mdi_keytone_detect_on = MMI_FALSE;
#endif /* __KEY_TONE_DETECTION__ */

/* VRSD */
#ifdef VR_ENABLE
media_vr_rcg_result_ind_struct *mdi_audio_vr_rcg_result_msg = NULL;
media_vr_trn_result_ind_struct *mdi_audio_vr_trn_result_msg = NULL;
#endif /* VR_ENABLE */ 

/* VRSI */
#ifdef VRSI_ENABLE
static mdi_ext_callback vrsi_handler;
static void* vrsi_user_data;
static U32 g_mdi_vrsi_session;
#endif 

/* TTS */
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
mdi_audio_play_text_struct mdi_audio_play_text_context;
#endif /* #if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */

#if defined(SIMPLE_TTS)
const mdi_start_end_t g_mdi_TTS_UCS2_MSB_index[] = {
 { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { 0, 154 }, { 155, 289 }
, { 290, 392 }, { 393, 532 }, { 533, 664 }, { 665, 807 }, { 808, 963 }, { 964, 1090 }, { 1091, 1210 }, { 1211, 1321 }, { 1322, 1416 }, { 1417, 1535 }
, { 1536, 1608 }, { 1609, 1732 }, { 1733, 1850 }, { 1851, 1931 }, { 1932, 2055 }, { 2056, 2186 }, { 2187, 2317 }, { 2318, 2416 }, { 2417, 2562 }, { 2563, 2683 }
, { 2684, 2808 }, { 2809, 2921 }, { 2922, 3024 }, { 3025, 3144 }, { 3145, 3250 }, { 3251, 3336 }, { 3337, 3413 }, { 3414, 3515 }, { 3516, 3665 }, { 3666, 3793 }
, { 3794, 3906 }, { 3907, 4007 }, { 4008, 4103 }, { 4104, 4189 }, { 4190, 4293 }, { 4294, 4390 }, { 4391, 4480 }, { 4481, 4608 }, { 4609, 4736 }, { 4737, 4834 }
, { 4835, 4942 }, { 4943, 5034 }, { 5035, 5131 }, { 5132, 5241 }, { 5242, 5335 }, { 5336, 5444 }, { 5445, 5597 }, { 5598, 5729 }, { 5730, 5869 }, { 5870, 5987 }
, { 5988, 6129 }, { 6130, 6258 }, { 6259, 6356 }, { 6357, 6448 }, { 6449, 6548 }, { 6549, 6645 }, { 6646, 6746 }, { 6747, 6835 }, { 6836, 6957 }, { 6958, 7100 }
, { 7101, 7242 }, { 7243, 7385 }, { 7386, 7483 }, { 7484, 7626 }, { 7627, 7772 }, { 7773, 7891 }, { 7892, 7985 }, { 7986, 8070 }, { 8071, 8220 }, { 8221, 8395 }
, { 8396, 8540 }, { 8541, 8626 }, { 8627, 8752 }, { 8753, 8854 }, { 8855, 8971 }, { 8972, 9036 }, { 9037, 9142 }, { 9143, 9193 }, { 9194, 9317 }, { 9318, 9380 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }
, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 }, { -1, -1 } };

const unsigned char g_mdi_TTS_UCS2_LSB[] = {
  0x00, 0x01, 0x03, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D
, 0x0E, 0x10, 0x11, 0x13, 0x14, 0x15, 0x16, 0x18, 0x19, 0x1A
, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x22, 0x24, 0x25, 0x26, 0x27
, 0x28, 0x2A, 0x2B, 0x2C, 0x2D, 0x30, 0x32, 0x34, 0x36, 0x38
, 0x39, 0x3A, 0x3B, 0x3D, 0x3E, 0x3F, 0x43, 0x45, 0x47, 0x48
, 0x49, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x52, 0x53, 0x54
, 0x56, 0x58, 0x59, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x66
, 0x69, 0x70, 0x71, 0x73, 0x7E, 0x82, 0x86, 0x88, 0x89, 0x8B
, 0x8C, 0x8D, 0x8E, 0x8F, 0x91, 0x92, 0x93, 0x94, 0x95, 0x98
, 0x99, 0x9A, 0x9B, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA4, 0xA5
, 0xA6, 0xA7, 0xA8, 0xA9, 0xAB, 0xAC, 0xAD, 0xAE, 0xB2, 0xB3
, 0xB5, 0xBA, 0xBB, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5
, 0xC6, 0xC7, 0xC9, 0xCA, 0xCB, 0xCD, 0xCE, 0xD1, 0xD3, 0xD4
, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDD, 0xDE, 0xDF, 0xE1, 0xE3
, 0xE4, 0xE5, 0xE8, 0xEA, 0xEB, 0xEC, 0xF0, 0xF2, 0xF3, 0xF5
, 0xF6, 0xF7, 0xFB, 0xFD, 0xFF, 0x01, 0x09, 0x0A, 0x0B, 0x0D
, 0x0E, 0x0F, 0x10, 0x11, 0x15, 0x17, 0x18, 0x19, 0x1A, 0x1B
, 0x1E, 0x1F, 0x20, 0x22, 0x24, 0x25, 0x26, 0x27, 0x2A, 0x2B
, 0x2F, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3A, 0x3C, 0x3D, 0x43
, 0x46, 0x47, 0x48, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x53, 0x54
, 0x55, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F
, 0x60, 0x62, 0x63, 0x64, 0x65, 0x67, 0x69, 0x6C, 0x6F, 0x70
, 0x73, 0x74, 0x75, 0x76, 0x7A, 0x7B, 0x7C, 0x7E, 0x7F, 0x83
, 0x84, 0x86, 0x88, 0x89, 0x8B, 0x8D, 0x8F, 0x91, 0x94, 0x96
, 0x97, 0x9B, 0x9D, 0xA0, 0xA3, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9
, 0xAA, 0xAC, 0xAE, 0xAF, 0xB5, 0xB6, 0xB7, 0xBF, 0xC2, 0xC3
, 0xC4, 0xC5, 0xCA, 0xCE, 0xCF, 0xD0, 0xD1, 0xD7, 0xD8, 0xDA
, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE3, 0xE6, 0xE8, 0xE9
, 0xEA, 0xEC, 0xED, 0xEE, 0xEF, 0xF1, 0xF3, 0xF8, 0xFA, 0xFE
, 0x00, 0x06, 0x09, 0x0B, 0x0C, 0x0D, 0x0F, 0x11, 0x12, 0x14
, 0x16, 0x18, 0x19, 0x1A, 0x1C, 0x1F, 0x21, 0x23, 0x25, 0x26
, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x3A, 0x3C, 0x3E
, 0x43, 0x47, 0x48, 0x49, 0x4C, 0x4E, 0x4F, 0x55, 0x5A, 0x5C
, 0x65, 0x6C, 0x6D, 0x6F, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x7B
, 0x7D, 0x7E, 0x7F, 0x80, 0x85, 0x88, 0x8D, 0x91, 0x96, 0x98
, 0x99, 0x9A, 0xA2, 0xA3, 0xA5, 0xA7, 0xA8, 0xA9, 0xAC, 0xAD
, 0xAF, 0xB2, 0xB3, 0xB4, 0xB5, 0xB7, 0xBA, 0xBB, 0xBE, 0xC2
, 0xC5, 0xC7, 0xC9, 0xCA, 0xCE, 0xCF, 0xD1, 0xD5, 0xD6, 0xDA
, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEC, 0xED, 0xEE, 0xF1, 0xF3
, 0xF5, 0xF9, 0xFB, 0x00, 0x02, 0x04, 0x05, 0x06, 0x07, 0x08
, 0x09, 0x0B, 0x10, 0x12, 0x14, 0x15, 0x18, 0x1F, 0x21, 0x2A
, 0x32, 0x33, 0x37, 0x38, 0x3A, 0x3B, 0x3C, 0x3F, 0x40, 0x41
, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4D
, 0x51, 0x52, 0x54, 0x55, 0x56, 0x57, 0x59, 0x5A, 0x5B, 0x5C
, 0x5D, 0x5E, 0x61, 0x62, 0x63, 0x65, 0x67, 0x68, 0x69, 0x6B
, 0x6C, 0x6D, 0x6E, 0x70, 0x71, 0x73, 0x74, 0x75, 0x76, 0x77
, 0x78, 0x79, 0x7B, 0x7C, 0x7D, 0x80, 0x81, 0x82, 0x85, 0x87
, 0x88, 0x89, 0x8A, 0x8C, 0x8D, 0x91, 0x92, 0x95, 0x96, 0x97
, 0x99, 0x9B, 0x9C, 0xA0, 0xA2, 0xA4, 0xA5, 0xAA, 0xAB, 0xAC
, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB5, 0xB6, 0xB7, 0xBB, 0xBC
, 0xBD, 0xC0, 0xC4, 0xC6, 0xC7, 0xC8, 0xC9, 0xCB, 0xCC, 0xCD
, 0xCF, 0xD1, 0xDB, 0xDC, 0xDD, 0xE0, 0xE1, 0xE4, 0xEB, 0xED
, 0xEF, 0xF0, 0xF1, 0xF3, 0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFB
, 0xFC, 0xFD, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x06, 0x07, 0x08
, 0x0A, 0x0D, 0x0E, 0x11, 0x12, 0x16, 0x17, 0x18, 0x19, 0x1A
, 0x1B, 0x1D, 0x20, 0x24, 0x25, 0x28, 0x29, 0x2A, 0x2B, 0x2D
, 0x2E, 0x30, 0x33, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3D
, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x47, 0x4A, 0x4B, 0x4C
, 0x4D, 0x4E, 0x50, 0x51, 0x54, 0x56, 0x5B, 0x5C, 0x5D, 0x5E
, 0x61, 0x65, 0x67, 0x69, 0x6A, 0x6E, 0x6F, 0x72, 0x74, 0x75
, 0x77, 0x7D, 0x7F, 0x81, 0x82, 0x83, 0x87, 0x88, 0x89, 0x8A
, 0x8C, 0x8D, 0x90, 0x91, 0x93, 0x9B, 0x9D, 0x9E, 0x9F, 0xA0
, 0xA1, 0xA2, 0xA3, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xB1
, 0xB2, 0xB3, 0xBB, 0xBE, 0xBF, 0xC1, 0xC3, 0xC7, 0xC9, 0xCB
, 0xD0, 0xD2, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDB, 0xDD, 0xDE
, 0xDF, 0xE2, 0xE3, 0xE4, 0xE6, 0xF0, 0xF1, 0xF3, 0xF5, 0xF8
, 0xF9, 0xFA, 0xFB, 0xFE, 0xFF, 0x00, 0x05, 0x06, 0x08, 0x0D
, 0x0F, 0x10, 0x15, 0x16, 0x17, 0x19, 0x1A, 0x1D, 0x20, 0x21
, 0x23, 0x26, 0x2A, 0x2D, 0x2E, 0x2F, 0x31, 0x39, 0x3A, 0x3B
, 0x3E, 0x3F, 0x40, 0x41, 0x41, 0x43, 0x44, 0x45, 0x45, 0x47
, 0x48, 0x49, 0x4A, 0x4E, 0x4F, 0x51, 0x52, 0x53, 0x54, 0x55
, 0x56, 0x57, 0x5A, 0x5C, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63
, 0x64, 0x66, 0x67, 0x69, 0x6B, 0x6E, 0x6F, 0x70, 0x71, 0x73
, 0x74, 0x75, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7F, 0x82, 0x84
, 0x85, 0x86, 0x89, 0x8B, 0x8C, 0x8D, 0x95, 0x98, 0x99, 0x9A
, 0x9D, 0x9F, 0xA2, 0xA3, 0xA5, 0xA6, 0xA8, 0xA9, 0xAD, 0xAE
, 0xB2, 0xB4, 0xB6, 0xBB, 0xBF, 0xC1, 0xC2, 0xC3, 0xC8, 0xC9
, 0xCA, 0xCB, 0xCC, 0xCD, 0xD1, 0xD4, 0xD6, 0xD7, 0xD8, 0xD9
, 0xDB, 0xDF, 0xE0, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE8, 0xE9
, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0, 0xF1, 0xF2, 0xF3
, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFB, 0xFC, 0xFD, 0x01, 0x03
, 0x04, 0x06, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
, 0x10, 0x11, 0x12, 0x13, 0x15, 0x16, 0x17, 0x1B, 0x1D, 0x1E
, 0x1F, 0x20, 0x21, 0x23, 0x26, 0x27, 0x28, 0x29, 0x2B, 0x2C
, 0x2D, 0x2E, 0x2F, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x38
, 0x39, 0x3B, 0x3C, 0x3E, 0x40, 0x42, 0x43, 0x46, 0x48, 0x4A
, 0x4B, 0x4E, 0x50, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58
, 0x59, 0x5B, 0x5C, 0x62, 0x64, 0x66, 0x68, 0x71, 0x72, 0x73
, 0x75, 0x76, 0x77, 0x78, 0x7B, 0x7C, 0x7D, 0x80, 0x81, 0x82
, 0x84, 0x86, 0x8B, 0x8C, 0x8E, 0x8F, 0x90, 0x92, 0x94, 0x95
, 0x96, 0x99, 0x9A, 0x9B, 0x9D, 0xA3, 0xA4, 0xA6, 0xA7, 0xA8
, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAF, 0xB1, 0xB3, 0xB4, 0xB8
, 0xBB, 0xBC, 0xBD, 0xBF, 0xC0, 0xC1, 0xC2, 0xC4, 0xC6, 0xC7
, 0xC8, 0xC9, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3
, 0xD4, 0xD5, 0xD7, 0xD9, 0xDA, 0xDC, 0xDD, 0xDE, 0xDF, 0xE1
, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xED, 0xEE, 0xF2, 0xF3
, 0xFA, 0xFC, 0xFD, 0xFF, 0x01, 0x04, 0x06, 0x07, 0x09, 0x0F
, 0x10, 0x11, 0x14, 0x1B, 0x20, 0x22, 0x23, 0x24, 0x27, 0x2A
, 0x2C, 0x2E, 0x2F, 0x30, 0x31, 0x33, 0x37, 0x38, 0x3C, 0x3E
, 0x3F, 0x41, 0x43, 0x44, 0x46, 0x49, 0x4A, 0x4F, 0x50, 0x55
, 0x56, 0x57, 0x5C, 0x5E, 0x5F, 0x61, 0x63, 0x64, 0x65, 0x66
, 0x67, 0x6A, 0x6C, 0x6D, 0x6E, 0x75, 0x76, 0x77, 0x78, 0x7B
, 0x7C, 0x7E, 0x80, 0x81, 0x82, 0x83, 0x84, 0x87, 0x88, 0x89
, 0x8A, 0x8B, 0x8F, 0x91, 0x94, 0x98, 0x99, 0x9A, 0x9C, 0x9D
, 0x9F, 0xA7, 0xAA, 0xAB, 0xAC, 0xAE, 0xB1, 0xB2, 0xB3, 0xB5
, 0xB7, 0xB9, 0xBB, 0xBD, 0xBE, 0xC4, 0xC5, 0xC6, 0xC7, 0xC9
, 0xCC, 0xCD, 0xCE, 0xD1, 0xD2, 0xD3, 0xD4, 0xD6, 0xDA, 0xDC
, 0xDD, 0xDF, 0xE1, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9
, 0xEA, 0xEB, 0xEC, 0xEF, 0xF2, 0xF3, 0xF5, 0xF6, 0xF7, 0xFD
, 0xFE, 0x00, 0x01, 0x06, 0x08, 0x09, 0x0C, 0x0D, 0x0E, 0x0F
, 0x10, 0x14, 0x16, 0x17, 0x18, 0x1B, 0x1C, 0x1E, 0x1F, 0x23
, 0x24, 0x27, 0x29, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32
, 0x34, 0x35, 0x36, 0x38, 0x39, 0x3B, 0x3F, 0x41, 0x4C, 0x4D
, 0x4E, 0x53, 0x54, 0x57, 0x58, 0x59, 0x5C, 0x60, 0x62, 0x64
, 0x65, 0x66, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6F, 0x71, 0x72
, 0x74, 0x76, 0x78, 0x79, 0x7B, 0x7C, 0x80, 0x85, 0x86, 0x87
, 0x8C, 0x8E, 0x8F, 0x90, 0x93, 0x95, 0x99, 0xA3, 0xA5, 0xA6
, 0xA8, 0xAE, 0xAF, 0xB3, 0xB4, 0xB6, 0xB7, 0xBC, 0xC0, 0xC1
, 0xC2, 0xC5, 0xC8, 0xC9, 0xCA, 0xCC, 0xCD, 0xD1, 0xD4, 0xD7
, 0xDA, 0xDB, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE4, 0xEA
, 0xEB, 0xED, 0xF0, 0xF1, 0xF4, 0xF5, 0xF9, 0xFA, 0xFD, 0xFE
, 0xFF, 0x03, 0x04, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0D
, 0x12, 0x13, 0x16, 0x18, 0x1C, 0x1F, 0x23, 0x28, 0x29, 0x2A
, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x33, 0x39, 0x3A, 0x3B, 0x3E
, 0x40, 0x42, 0x47, 0x4A, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51
, 0x57, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x64
, 0x66, 0x68, 0x69, 0x6A, 0x6B, 0x6D, 0x6F, 0x73, 0x76, 0x77
, 0x7B, 0x7C, 0x82, 0x83, 0x84, 0x85, 0x86, 0x8B, 0x8C, 0x92
, 0x93, 0x9A, 0x9B, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA6, 0xA7
, 0xA9, 0xAB, 0xAD, 0xAE, 0xB2, 0xB4, 0xB8, 0xC2, 0xC3, 0xCB
, 0xCE, 0xCF, 0xD2, 0xD4, 0xD5, 0xD8, 0xD9, 0xDA, 0xDC, 0xDD
, 0xDF, 0xE0, 0xE1, 0xE4, 0xED, 0xEF, 0xF4, 0xF7, 0xF8, 0xF9
, 0xFA, 0xFD, 0x00, 0x02, 0x05, 0x06, 0x07, 0x09, 0x0A, 0x0B
, 0x0D, 0x11, 0x15, 0x19, 0x1D, 0x1E, 0x20, 0x21, 0x24, 0x2A
, 0x2F, 0x30, 0x31, 0x34, 0x35, 0x44, 0x4A, 0x4B, 0x4C, 0x4D
, 0x4F, 0x51, 0x52, 0x54, 0x57, 0x58, 0x5A, 0x5E, 0x62, 0x64
, 0x65, 0x6B, 0x6C, 0x6D, 0x71, 0x75, 0x79, 0x7D, 0x7E, 0x80
, 0x81, 0x83, 0x85, 0x89, 0x8A, 0x92, 0x93, 0x99, 0x9A, 0x9C
, 0x9E, 0x9F, 0xA6, 0xA8, 0xA9, 0xAE, 0xAF, 0xB3, 0xBB, 0xBC
, 0xBE, 0xC1, 0xC5, 0xC7, 0xCE, 0xD1, 0xD3, 0xD5, 0xD8, 0xD9
, 0xDA, 0xDE, 0xDF, 0xE2, 0xE4, 0xE9, 0xEB, 0xEC, 0xEE, 0xEF
, 0xF0, 0xF3, 0xF6, 0xF9, 0xFA, 0xFC, 0xFD, 0x02, 0x04, 0x06
, 0x07, 0x0D, 0x0F, 0x14, 0x15, 0x16, 0x19, 0x1A, 0x1C, 0x1F
, 0x20, 0x22, 0x24, 0x25, 0x27, 0x29, 0x2A, 0x2B, 0x2D, 0x2E
, 0x2F, 0x31, 0x34, 0x37, 0x38, 0x39, 0x3A, 0x3C, 0x3E, 0x40
, 0x41, 0x42, 0x44, 0x47, 0x48, 0x49, 0x4B, 0x4E, 0x4F, 0x50
, 0x51, 0x54, 0x55, 0x56, 0x57, 0x58, 0x5A, 0x60, 0x62, 0x65
, 0x67, 0x69, 0x6A, 0x6D, 0x6E, 0x73, 0x74, 0x76, 0x78, 0x79
, 0x7D, 0x81, 0x82, 0x83, 0x84, 0x86, 0x87, 0x88, 0x8A, 0x8D
, 0x92, 0x93, 0x96, 0x97, 0x99, 0x9D, 0x9E, 0xA3, 0xA4, 0xA5
, 0xA8, 0xA9, 0xAA, 0xAB, 0xAE, 0xAF, 0xB2, 0xB3, 0xB9, 0xBB
, 0xBE, 0xC5, 0xC6, 0xCA, 0xCB, 0xCD, 0xD0, 0xD1, 0xD2, 0xD3
, 0xD4, 0xD7, 0xD8, 0xDA, 0xDC, 0xDD, 0xE3, 0xE5, 0xE6, 0xE8
, 0xEA, 0xEC, 0xF5, 0xF9, 0xFB, 0xFF, 0x01, 0x03, 0x04, 0x05
, 0x06, 0x07, 0x08, 0x09, 0x0C, 0x11, 0x13, 0x18, 0x1B, 0x1C
, 0x1F, 0x20, 0x23, 0x25, 0x29, 0x31, 0x32, 0x34, 0x36, 0x3C
, 0x40, 0x41, 0x46, 0x49, 0x4A, 0x55, 0x5A, 0x62, 0x66, 0x67
, 0x6A, 0x6D, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x7F, 0x92, 0x9A
, 0x9B, 0xA7, 0xAA, 0xB2, 0xB3, 0xB5, 0xB8, 0xBC, 0xBD, 0xBE
, 0xC1, 0xC2, 0xC9, 0xCC, 0xD2, 0xD4, 0xD6, 0xD7, 0xD8, 0xDC
, 0xE0, 0xE1, 0xE3, 0xE6, 0xE9, 0xEB, 0xF1, 0xF5, 0xFB, 0x08
, 0x09, 0x0B, 0x0C, 0x16, 0x17, 0x19, 0x1D, 0x21, 0x24, 0x2A
, 0x30, 0x32, 0x34, 0x37, 0x38, 0x40, 0x43, 0x4C, 0x50, 0x51
, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C
, 0x5D, 0x5F, 0x62, 0x63, 0x64, 0x65, 0x66, 0x69, 0x6A, 0x6B
, 0x6C, 0x70, 0x71, 0x73, 0x75, 0x78, 0x7A, 0x7D, 0x7F, 0x80
, 0x81, 0x83, 0x84, 0x85, 0x87, 0x88, 0x89, 0x8B, 0x8C, 0x8F
, 0x93, 0x95, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E
, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xAA, 0xAB, 0xAE
, 0xB0, 0xB3, 0xB4, 0xB5, 0xB6, 0xB8, 0xB9, 0xBD, 0xBE, 0xBF
, 0xC2, 0xC4, 0xC5, 0xC6, 0xC7, 0xCC, 0xD0, 0xD1, 0xD2, 0xD3
, 0xDD, 0xDE, 0xDF, 0xE1, 0xE2, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8
, 0xE9, 0xEB, 0xEC, 0xEE, 0xF0, 0xF5, 0xF6, 0xF8, 0xF9, 0xFA
, 0xFB, 0xFC, 0xFF, 0x01, 0x04, 0x06, 0x07, 0x08, 0x09, 0x0A
, 0x0B, 0x0D, 0x0E, 0x0F, 0x11, 0x14, 0x15, 0x16, 0x18, 0x1A
, 0x1C, 0x1D, 0x22, 0x24, 0x25, 0x27, 0x2C, 0x31, 0x34, 0x37
, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41
, 0x42, 0x44, 0x45, 0x46, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D
, 0x4E, 0x4F, 0x50, 0x51, 0x55, 0x58, 0x59, 0x5C, 0x5D, 0x5E
, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x68, 0x6C, 0x6E
, 0x6F, 0x71, 0x79, 0x7A, 0x7F, 0x81, 0x82, 0x88, 0x8C, 0x8D
, 0x90, 0x91, 0x94, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C
, 0xA1, 0xA2, 0xA3, 0xA9, 0xAB, 0xAC, 0xAD, 0xB1, 0xB3, 0xB5
, 0xB7, 0xB8, 0xBD, 0xBF, 0xC1, 0xC4, 0xCB, 0xD2, 0xD9, 0xE1
, 0xE4, 0xE5, 0xE6, 0xE8, 0xEA, 0xED, 0xF0, 0xF4, 0xF6, 0xFB
, 0xFD, 0x01, 0x02, 0x03, 0x06, 0x07, 0x0D, 0x0E, 0x11, 0x14
, 0x16, 0x17, 0x19, 0x1B, 0x1E, 0x20, 0x22, 0x24, 0x26, 0x27
, 0x29, 0x2D, 0x2E, 0x34, 0x3D, 0x3E, 0x47, 0x4A, 0x4B, 0x4C
, 0x50, 0x58, 0x5B, 0x5D, 0x69, 0x6B, 0x6C, 0x6F, 0x74, 0x81
, 0x82, 0x84, 0x87, 0x94, 0x97, 0x99, 0x9D, 0xA0, 0xA7, 0xB7
, 0xB8, 0xBA, 0xBC, 0xBD, 0xC5, 0xC9, 0xCB, 0xCD, 0xD2, 0xD4
, 0xD6, 0xDB, 0xDD, 0xDE, 0xE1, 0xE2, 0xE5, 0xE6, 0xE7, 0xE8
, 0xE9, 0xEB, 0xEE, 0xEF, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF7
, 0xFD, 0xFE, 0x01, 0x02, 0x03, 0x05, 0x06, 0x08, 0x0C, 0x0F
, 0x10, 0x11, 0x14, 0x15, 0x16, 0x18, 0x19, 0x1A, 0x1B, 0x1C
, 0x1D, 0x1F, 0x25, 0x26, 0x27, 0x2B, 0x2D, 0x2E, 0x31, 0x33
, 0x36, 0x37, 0x38, 0x3B, 0x3C, 0x3D, 0x40, 0x42, 0x43, 0x44
, 0x45, 0x4C, 0x54, 0x55, 0x57, 0x58, 0x5B, 0x5E, 0x5F, 0x61
, 0x62, 0x63, 0x6B, 0x6C, 0x72, 0x73, 0x74, 0x76, 0x78, 0x79
, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x84, 0x86, 0x87
, 0x8A, 0x8B, 0x8F, 0x90, 0x91, 0x93, 0x94, 0x95, 0x96, 0x97
, 0x99, 0x9A, 0x9C, 0x9E, 0x9F, 0xA0, 0xA5, 0xA6, 0xA7, 0xAB
, 0xAD, 0xB3, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBE, 0xC1, 0xC2
, 0xC4, 0xC8, 0xC9, 0xCA, 0xD1, 0xD2, 0xD3, 0xD6, 0xDA, 0xDB
, 0xDD, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE8, 0xEA, 0xEC, 0xF3
, 0xF4, 0xF6, 0xF7, 0xFA, 0xFE, 0xFF, 0x00, 0x01, 0x02, 0x03
, 0x04, 0x08, 0x0A, 0x0B, 0x0F, 0x11, 0x12, 0x13, 0x14, 0x15
, 0x17, 0x18, 0x1B, 0x1F, 0x20, 0x22, 0x25, 0x26, 0x27, 0x29
, 0x2A, 0x2D, 0x2F, 0x31, 0x33, 0x35, 0x37, 0x39, 0x3A, 0x3C
, 0x40, 0x46, 0x48, 0x4A, 0x4C, 0x4E, 0x50, 0x52, 0x53, 0x55
, 0x56, 0x57, 0x58, 0x59, 0x5D, 0x61, 0x62, 0x64, 0x65, 0x66
, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x70, 0x71, 0x73, 0x77, 0x79
, 0x7B, 0x7C, 0x7F, 0x80, 0x81, 0x82, 0x84, 0x85, 0x87, 0x88
, 0x89, 0x8A, 0x8B, 0x8C, 0x90, 0x91, 0x92, 0x95, 0x97, 0x98
, 0x99, 0x9C, 0x9E, 0xA0, 0xA1, 0xA8, 0xA9, 0xAA, 0xAC, 0xAD
, 0xAE, 0xB5, 0xB7, 0xB9, 0xBC, 0xBD, 0xC3, 0xC4, 0xC5, 0xC6
, 0xC9, 0xCC, 0xCD, 0xCF, 0xD0, 0xD1, 0xD2, 0xD6, 0xD7, 0xD8
, 0xD9, 0xDD, 0xE0, 0xE1, 0xE4, 0xE7, 0xEA, 0xEB, 0xED, 0xEE
, 0xF1, 0xF5, 0xF8, 0xFB, 0xFD, 0xFE, 0xFF, 0x00, 0x01, 0x02
, 0x03, 0x04, 0x05, 0x06, 0x0A, 0x0D, 0x0E, 0x0F, 0x12, 0x14
, 0x15, 0x16, 0x19, 0x1B, 0x1C, 0x1D, 0x20, 0x21, 0x25, 0x26
, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2F, 0x35, 0x3B, 0x3C, 0x3F
, 0x41, 0x42, 0x43, 0x46, 0x4B, 0x4D, 0x50, 0x52, 0x55, 0x59
, 0x5A, 0x5D, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69
, 0x6A, 0x6B, 0x6C, 0x6D, 0x6F, 0x70, 0x73, 0x76, 0x78, 0x79
, 0x7A, 0x7B, 0x7C, 0x7D, 0x7F, 0x83, 0x84, 0x85, 0x89, 0x8C
, 0x8D, 0x92, 0x94, 0x96, 0x9A, 0x9B, 0x9D, 0x9F, 0xA0, 0xA3
, 0xA6, 0xA8, 0xAB, 0xAC, 0xAD, 0xAF, 0xB1, 0xB2, 0xB4, 0xB5
, 0xB6, 0xB8, 0xBB, 0xBC, 0xBD, 0xC5, 0xC6, 0xC7, 0xCA, 0xCB
, 0xD1, 0xD5, 0xD8, 0xDA, 0xDC, 0xDD, 0xDF, 0xE0, 0xE1, 0xE6
, 0xE7, 0xE8, 0xE9, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0, 0xF1
, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF9, 0xFA, 0xFB, 0x00, 0x01
, 0x06, 0x08, 0x09, 0x0D, 0x0E, 0x0F, 0x12, 0x15, 0x1A, 0x1B
, 0x1C, 0x1F, 0x20, 0x23, 0x24, 0x26, 0x27, 0x28, 0x2B, 0x34
, 0x37, 0x3E, 0x3F, 0x44, 0x47, 0x48, 0x4A, 0x4B, 0x4C, 0x4D
, 0x4E, 0x51, 0x55, 0x58, 0x5A, 0x5D, 0x5F, 0x62, 0x63, 0x67
, 0x68, 0x6A, 0x6B, 0x6E, 0x70, 0x73, 0x75, 0x76, 0x77, 0x7C
, 0x7E, 0x82, 0x8A, 0x8B, 0x8E, 0x90, 0x91, 0x92, 0x94, 0x9A
, 0x9D, 0xA4, 0xA7, 0xA8, 0xA9, 0xAB, 0xAC, 0xAE, 0xB2, 0xB6
, 0xB7, 0xBE, 0xC2, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD
, 0xD1, 0xD2, 0xD4, 0xDE, 0xDF, 0xE3, 0xE6, 0xE8, 0xF2, 0xF5
, 0xF6, 0xF7, 0xF8, 0xFA, 0xFC, 0xFE, 0xFF, 0x00, 0x06, 0x07
, 0x08, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12
, 0x14, 0x15, 0x16, 0x17, 0x18, 0x1A, 0x1B, 0x1F, 0x21, 0x22
, 0x24, 0x25, 0x27, 0x29, 0x2A, 0x2C, 0x2E, 0x30, 0x32, 0x33
, 0x34, 0x36, 0x37, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x43, 0x47
, 0x48, 0x49, 0x4B, 0x4C, 0x4D, 0x4E, 0x51, 0x52, 0x53, 0x54
, 0x58, 0x5B, 0x63, 0x66, 0x67, 0x69, 0x6A, 0x6B, 0x6C, 0x6D
, 0x6E, 0x6F, 0x70, 0x73, 0x76, 0x79, 0x7C, 0x7E, 0x7F, 0x80
, 0x84, 0x86, 0x89, 0x8A, 0x91, 0x92, 0x93, 0x95, 0x96, 0x97
, 0x98, 0x9A, 0x9B, 0x9F, 0xA0, 0xA1, 0xA2, 0xA4, 0xA5, 0xA8
, 0xAB, 0xAC, 0xB1, 0xB5, 0xB9, 0xBB, 0xBC, 0xBD, 0xBF, 0xC2
, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD
, 0xCE, 0xD0, 0xD2, 0xD3, 0xD4, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA
, 0xDB, 0xDC, 0xDF, 0xE2, 0xE3, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9
, 0xEC, 0xED, 0xEE, 0xEF, 0xF1, 0xF3, 0xF4, 0xF6, 0xF7, 0xFC
, 0xFD, 0xFE, 0xFF, 0x01, 0x02, 0x07, 0x08, 0x09, 0x0E, 0x11
, 0x16, 0x1A, 0x1B, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23
, 0x24, 0x25, 0x28, 0x2A, 0x2B, 0x2F, 0x32, 0x39, 0x3A, 0x3D
, 0x3E, 0x42, 0x43, 0x45, 0x46, 0x49, 0x4B, 0x4C, 0x4D, 0x4E
, 0x4F, 0x50, 0x55, 0x5E, 0x5F, 0x61, 0x62, 0x63, 0x67, 0x68
, 0x69, 0x6B, 0x6D, 0x6E, 0x71, 0x72, 0x76, 0x77, 0x7A, 0x7B
, 0x80, 0x82, 0x83, 0x84, 0x87, 0x88, 0x89, 0x8A, 0x8C, 0x8E
, 0x8F, 0x90, 0x92, 0x96, 0x98, 0x99, 0x9B, 0xA0, 0xA1, 0xA2
, 0xA3, 0xA5, 0xA7, 0xA8, 0xA9, 0xAA, 0xAC, 0xAD, 0xAE, 0xB0
, 0xB3, 0xB4, 0xB7, 0xB8, 0xBA, 0xBC, 0xBE, 0xC0, 0xC4, 0xC6
, 0xC9, 0xCD, 0xCE, 0xCF, 0xD0, 0xD2, 0xD6, 0xDA, 0xDB, 0xDE
, 0xE0, 0xE1, 0xE3, 0xE9, 0xEA, 0xED, 0xEE, 0xF2, 0xF4, 0xF6
, 0xF8, 0xF9, 0xFD, 0xFF, 0x00, 0x01, 0x02, 0x05, 0x06, 0x0B
, 0x0C, 0x0D, 0x0F, 0x10, 0x13, 0x14, 0x16, 0x17, 0x1B, 0x1C
, 0x1E, 0x20, 0x21, 0x26, 0x2A, 0x2C, 0x2D, 0x34, 0x35, 0x36
, 0x3A, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x44, 0x45, 0x46, 0x47
, 0x48, 0x4A, 0x51, 0x52, 0x54, 0x58, 0x5C, 0x5E, 0x5F, 0x67
, 0x69, 0x6D, 0x6F, 0x73, 0x76, 0x78, 0x79, 0x7A, 0x7B, 0x82
, 0x84, 0x85, 0x87, 0x88, 0x90, 0x91, 0x92, 0x93, 0x95, 0x96
, 0x98, 0x99, 0x9A, 0x9E, 0x9F, 0xA2, 0xA3, 0xA4, 0xA5, 0xA9
, 0xAB, 0xAC, 0xAD, 0xAE, 0xB0, 0xB2, 0xB3, 0xB5, 0xB7, 0xB8
, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC4
, 0xC5, 0xC7, 0xCA, 0xCB, 0xCD, 0xCE, 0xD0, 0xD2, 0xD4, 0xD7
, 0xD8, 0xDA, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6, 0xEC, 0xED, 0xEF
, 0xF0, 0xF1, 0xF2, 0xF4, 0xF7, 0xFA, 0xFB, 0xFC, 0xFE, 0x00
, 0x04, 0x06, 0x09, 0x0F, 0x12, 0x14, 0x16, 0x18, 0x19, 0x1B
, 0x1C, 0x1D, 0x22, 0x23, 0x24, 0x25, 0x2A, 0x2B, 0x2C, 0x2E
, 0x2F, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3B, 0x3E, 0x3F
, 0x45, 0x48, 0x49, 0x4C, 0x4F, 0x51, 0x54, 0x55, 0x56, 0x57
, 0x58, 0x59, 0x5B, 0x5D, 0x5E, 0x62, 0x63, 0x66, 0x6B, 0x6C
, 0x70, 0x72, 0x74, 0x75, 0x77, 0x78, 0x82, 0x83, 0x87, 0x8B
, 0x8C, 0x90, 0x91, 0x93, 0x95, 0x97, 0x99, 0x9B, 0x9C, 0x9F
, 0xA1, 0xA4, 0xA5, 0xA7, 0xA9, 0xAB, 0xAC, 0xAD, 0xAF, 0xB0
, 0xB7, 0xB9, 0xBC, 0xBD, 0xC1, 0xC3, 0xC4, 0xC5, 0xC6, 0xCB
, 0xCC, 0xCE, 0xCF, 0xD2, 0xD6, 0xD7, 0xE0, 0xE2, 0xE5, 0xE6
, 0xE7, 0xE8, 0xE9, 0xEC, 0xED, 0xEE, 0xEF, 0xF0, 0xF1, 0xF6
, 0xF7, 0xFA, 0x00, 0x02, 0x03, 0x06, 0x07, 0x0A, 0x0C, 0x0E
, 0x0F, 0x13, 0x14, 0x15, 0x19, 0x1D, 0x1F, 0x20, 0x24, 0x25
, 0x27, 0x28, 0x2D, 0x2F, 0x31, 0x34, 0x35, 0x36, 0x3C, 0x3E
, 0x41, 0x42, 0x43, 0x45, 0x49, 0x4B, 0x4C, 0x4F, 0x52, 0x53
, 0x54, 0x55, 0x56, 0x57, 0x5A, 0x5D, 0x5E, 0x5F, 0x61, 0x64
, 0x66, 0x68, 0x6E, 0x6F, 0x70, 0x74, 0x76, 0x77, 0x7A, 0x7E
, 0x82, 0x84, 0x87, 0x88, 0x89, 0x8C, 0x8D, 0x91, 0x96, 0x97
, 0x98, 0x9D, 0xA2, 0xA7, 0xA8, 0xAB, 0xAE, 0xB1, 0xB4, 0xB8
, 0xB9, 0xBE, 0xC4, 0xC6, 0xC7, 0xC9, 0xD6, 0xD9, 0xDB, 0xDC
, 0xDD, 0xE0, 0xE6, 0xE9, 0xEC, 0xF0, 0xF2, 0xF3, 0xF4, 0xF7
, 0xF8, 0xF9, 0xFC, 0xFE, 0xFF, 0x00, 0x03, 0x08, 0x09, 0x0A
, 0x0B, 0x0D, 0x10, 0x14, 0x15, 0x17, 0x1B, 0x1D, 0x1F, 0x26
, 0x27, 0x28, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x31, 0x34
, 0x35, 0x3A, 0x3D, 0x40, 0x42, 0x43, 0x46, 0x48, 0x49, 0x4C
, 0x4E, 0x4F, 0x50, 0x51, 0x53, 0x56, 0x57, 0x5C, 0x5E, 0x5F
, 0x60, 0x61, 0x65, 0x68, 0x69, 0x6A, 0x6D, 0x6F, 0x70, 0x71
, 0x72, 0x73, 0x75, 0x77, 0x7C, 0x7E, 0x7F, 0x81, 0x84, 0x87
, 0x89, 0x8B, 0x90, 0x93, 0x95, 0x97, 0x98, 0x9A, 0x9C, 0x9D
, 0x9E, 0xA2, 0xA3, 0xA5, 0xA7, 0xA8, 0xAA, 0xAB, 0xAD, 0xAF
, 0xB0, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xC1, 0xC3, 0xC4
, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD8, 0xD9, 0xDA, 0xDC
, 0xDD, 0xDE, 0xE0, 0xE2, 0xE5, 0xE9, 0xEC, 0xEF, 0xF0, 0xF1
, 0xF3, 0xF4, 0xF5, 0xFD, 0xFF, 0x00, 0x05, 0x07, 0x08, 0x09
, 0x0A, 0x0B, 0x0C, 0x0E, 0x0F, 0x11, 0x13, 0x16, 0x17, 0x18
, 0x1D, 0x21, 0x29, 0x2A, 0x32, 0x33, 0x37, 0x38, 0x39, 0x3C
, 0x3D, 0x3E, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x48
, 0x49, 0x4A, 0x4C, 0x4E, 0x50, 0x51, 0x53, 0x54, 0x55, 0x60
, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6B
, 0x74, 0x76, 0x77, 0x7F, 0x81, 0x82, 0x83, 0x85, 0x86, 0x8F
, 0x93, 0x94, 0x97, 0x9D, 0x9F, 0xA1, 0xA2, 0xA6, 0xA7, 0xA8
, 0xAD, 0xAF, 0xB0, 0xB1, 0xB3, 0xB5, 0xC0, 0xC2, 0xC4, 0xC9
, 0xCB, 0xCD, 0xD2, 0xD5, 0xD6, 0xD7, 0xD8, 0xDA, 0xDF, 0xE0
, 0xE3, 0xE7, 0xEE, 0xF0, 0xF1, 0xF2, 0xF5, 0xF9, 0xFA, 0xFB
, 0xFC, 0x01, 0x05, 0x0B, 0x0D, 0x0E, 0x0F, 0x10, 0x12, 0x1F
, 0x20, 0x24, 0x2D, 0x30, 0x34, 0x39, 0x3D, 0x3F, 0x42, 0x4A
, 0x53, 0x54, 0x57, 0x5A, 0x5B, 0x5D, 0x5E, 0x60, 0x63, 0x66
, 0x68, 0x6B, 0x6D, 0x6E, 0x71, 0x75, 0x77, 0x78, 0x79, 0x7C
, 0x80, 0x82, 0x84, 0x86, 0x87, 0x88, 0x89, 0x8D, 0x94, 0x95
, 0x98, 0x9B, 0x9C, 0xA3, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB
, 0xAD, 0xAE, 0xB1, 0xB4, 0xB7, 0xBB, 0xBF, 0xC1, 0xC3, 0xCA
, 0xCB, 0xCC, 0xCD, 0xCE, 0xD0, 0xD3, 0xD4, 0xDB, 0xDF, 0xE0
, 0xE7, 0xE8, 0xED, 0xF2, 0xF3, 0xFD, 0xFF, 0x01, 0x02, 0x05
, 0x0A, 0x11, 0x13, 0x17, 0x18, 0x19, 0x1E, 0x1F, 0x21, 0x23
, 0x28, 0x2A, 0x2F, 0x31, 0x35, 0x38, 0x39, 0x3A, 0x3D, 0x3E
, 0x44, 0x47, 0x48, 0x4B, 0x50, 0x58, 0x59, 0x5B, 0x5F, 0x61
, 0x62, 0x65, 0x6B, 0x71, 0x79, 0x7C, 0x7E, 0x80, 0x84, 0x89
, 0x8E, 0x90, 0x91, 0x94, 0x97, 0x9C, 0xA0, 0xA2, 0xA3, 0xA9
, 0xAB, 0xAC, 0xAE, 0xAF, 0xB3, 0xB8, 0xBB, 0xC2, 0xC3, 0xD3
, 0xDA, 0xDB, 0xDD, 0xDE, 0xDF, 0xE5, 0xE7, 0xE8, 0xEA, 0xEC
, 0xF3, 0xF8, 0xFA, 0xFB, 0x04, 0x0A, 0x0F, 0x10, 0x12, 0x16
, 0x1E, 0x20, 0x21, 0x22, 0x23, 0x24, 0x27, 0x32, 0x37, 0x39
, 0x3A, 0x3D, 0x3E, 0x43, 0x46, 0x47, 0x49, 0x4C, 0x4E, 0x50
, 0x59, 0x5C, 0x5F, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67
, 0x6A, 0x72, 0x77, 0x78, 0x79, 0x7B, 0x7C, 0x7F, 0x81, 0x82
, 0x83, 0x84, 0x86, 0x87, 0x89, 0x8A, 0x8B, 0x8D, 0x92, 0x93
, 0x96, 0x98, 0x9A, 0x9B, 0x9E, 0xA1, 0xA4, 0xAA, 0xAB, 0xAE
, 0xAF, 0xB2, 0xB3, 0xB4, 0xB5, 0xB7, 0xBA, 0xBC, 0xBF, 0xC0
, 0xC1, 0xC2, 0xC5, 0xC6, 0xCB, 0xCD, 0xCF, 0xD2, 0xD3, 0xD4
, 0xD5, 0xD6, 0xD7, 0xD9, 0xDA, 0xDB, 0xE1, 0xEA, 0xEB, 0xEC
, 0xEF, 0xF3, 0xF5, 0xF9, 0xFD, 0xFF, 0x05, 0x06, 0x07, 0x08
, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x13, 0x14, 0x15, 0x16, 0x18
, 0x19, 0x1A, 0x1B, 0x1F, 0x21, 0x22, 0x23, 0x24, 0x26, 0x27
, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2E, 0x2F, 0x30, 0x32, 0x33
, 0x34, 0x35, 0x38, 0x3D, 0x3E, 0x40, 0x41, 0x42, 0x46, 0x47
, 0x49, 0x4A, 0x4D, 0x4E, 0x50, 0x54, 0x55, 0x57, 0x59, 0x5B
, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x64, 0x68, 0x69, 0x6A
, 0x70, 0x72, 0x74, 0x76, 0x79, 0x7A, 0x7D, 0x7E, 0x81, 0x82
, 0x83, 0x85, 0x86, 0x88, 0x89, 0x8C, 0x8D, 0x8F, 0x90, 0x92
, 0x93, 0x94, 0x96, 0x98, 0x99, 0x9B, 0x9F, 0xA1, 0xA3, 0xA4
, 0xA5, 0xA6, 0xA7, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xB1
, 0xB2, 0xB3, 0xB8, 0xB9, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC1
, 0xC4, 0xC5, 0xC9, 0xCA, 0xCC, 0xD0, 0xD3, 0xD4, 0xD5, 0xD6
, 0xD7, 0xDB, 0xDC, 0xDE, 0xE0, 0xE1, 0xE2, 0xE3, 0xE5, 0xE8
, 0xEA, 0xEB, 0xEE, 0xEF, 0xF0, 0xF1, 0xF3, 0xF5, 0xF6, 0xF7
, 0xF8, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0x01, 0x04, 0x07, 0x0B
, 0x0C, 0x0E, 0x12, 0x17, 0x19, 0x1A, 0x1B, 0x1E, 0x25, 0x27
, 0x29, 0x2A, 0x2B, 0x2E, 0x31, 0x32, 0x33, 0x35, 0x36, 0x38
, 0x39, 0x3B, 0x3C, 0x3D, 0x3E, 0x41, 0x43, 0x45, 0x46, 0x47
, 0x48, 0x4A, 0x4B, 0x4D, 0x4E, 0x4F, 0x51, 0x52, 0x53, 0x54
, 0x59, 0x5A, 0x5C, 0x5E, 0x60, 0x63, 0x65, 0x66, 0x69, 0x6A
, 0x6C, 0x6E, 0x6F, 0x74, 0x77, 0x78, 0x79, 0x7C, 0x82, 0x85
, 0x87, 0x88, 0x89, 0x8A, 0x8C, 0x8E, 0x91, 0x93, 0x94, 0x95
, 0x9B, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA3, 0xA4, 0xA6, 0xA7
, 0xA8, 0xA9, 0xAA, 0xAB, 0xAE, 0xAF, 0xB2, 0xB5, 0xB8, 0xBC
, 0xBF, 0xC0, 0xC4, 0xC5, 0xC6, 0xC7, 0xCB, 0xCC, 0xD1, 0xD2
, 0xD6, 0xD8, 0xD9, 0xDA, 0xDD, 0xDE, 0xE0, 0xE1, 0xE4, 0xE6
, 0xE8, 0xEA, 0xEB, 0xEC, 0xEE, 0xF1, 0xF3, 0xF5, 0xF6, 0xF7
, 0xF9, 0xFA, 0xFB, 0xFC, 0x05, 0x0A, 0x0C, 0x0D, 0x0E, 0x10
, 0x11, 0x14, 0x16, 0x17, 0x19, 0x1A, 0x1B, 0x1D, 0x20, 0x21
, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29, 0x2B, 0x2C, 0x2D, 0x2F
, 0x32, 0x34, 0x38, 0x3A, 0x3E, 0x43, 0x44, 0x4A, 0x4D, 0x4E
, 0x53, 0x54, 0x56, 0x58, 0x5B, 0x5E, 0x5F, 0x63, 0x67, 0x69
, 0x6B, 0x6E, 0x6F, 0x72, 0x73, 0x7E, 0x7F, 0x83, 0x85, 0x86
, 0x89, 0x8F, 0x90, 0x96, 0x98, 0x9C, 0x9D, 0x9F, 0xA2, 0xA5
, 0xA7, 0xAA, 0xAB, 0xAF, 0xB1, 0xB2, 0xB4, 0xB6, 0xB7, 0xBA
, 0xBB, 0xBC, 0xBD, 0xC1, 0xC2, 0xC4, 0xC5, 0xC7, 0xCB, 0xCC
, 0xCE, 0xCF, 0xD1, 0xD3, 0xD4, 0xD5, 0xD7, 0xDA, 0xDE, 0xDF
, 0xE0, 0xE1, 0xE2, 0xE4, 0xE5, 0xE6, 0xE8, 0xE9, 0xEC, 0xEF
, 0xF2, 0xF4, 0xF7, 0xF8, 0xF9, 0xFE, 0xFF, 0x01, 0x02, 0x06
, 0x09, 0x0F, 0x13, 0x14, 0x15, 0x1A, 0x20, 0x22, 0x23, 0x24
, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2F, 0x31, 0x32, 0x33, 0x36
, 0x38, 0x3E, 0x3F, 0x41, 0x46, 0x47, 0x4B, 0x4D, 0x51, 0x54
, 0x58, 0x5B, 0x5C, 0x5E, 0x5F, 0x60, 0x62, 0x64, 0x66, 0x6D
, 0x6E, 0x6F, 0x70, 0x72, 0x74, 0x77, 0x78, 0x7A, 0x7C, 0x7F
, 0x80, 0x84, 0x86, 0x87, 0x88, 0x89, 0x8C, 0x8D, 0x8E, 0x97
, 0x9C, 0xA0, 0xA1, 0xA4, 0xA6, 0xA7, 0xA9, 0xAE, 0xB1, 0xB3
, 0xB4, 0xB6, 0xB9, 0xC0, 0xC1, 0xC2, 0xC3, 0xC9, 0xD1, 0xD2
, 0xD5, 0xD8, 0xDB, 0xDE, 0xDF, 0xE0, 0xE1, 0xE4, 0xE9, 0xEB
, 0xEC, 0xEE, 0xEF, 0xF0, 0xF1, 0xFA, 0xFC, 0xFE, 0x05, 0x06
, 0x09, 0x0B, 0x0F, 0x11, 0x15, 0x18, 0x1A, 0x1B, 0x1D, 0x1F
, 0x20, 0x23, 0x27, 0x28, 0x30, 0x32, 0x35, 0x39, 0x3E, 0x43
, 0x44, 0x4C, 0x4F, 0x51, 0x55, 0x58, 0x5D, 0x5E, 0x63, 0x64
, 0x6B, 0x6C, 0x6D, 0x6F, 0x70, 0x75, 0x76, 0x78, 0x7C, 0x7D
, 0x7E, 0x7F, 0x80, 0x85, 0x86, 0x89, 0x8A, 0x8E, 0x92, 0x94
, 0x95, 0x96, 0x99, 0x9C, 0x9D, 0xA4, 0xAB, 0xAC, 0xAD, 0xAE
, 0xAF, 0xB1, 0xB3, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD
, 0xC0, 0xC1, 0xC2, 0xC3, 0xC8, 0xCA, 0xCF, 0xD8, 0xD9, 0xDB
, 0xDF, 0xE4, 0xE6, 0xE7, 0xE8, 0xE9, 0xEB, 0xEC, 0xED, 0xEF
, 0xF4, 0xF7, 0xF9, 0xFD, 0x09, 0x0A, 0x10, 0x13, 0x15, 0x16
, 0x17, 0x18, 0x19, 0x1A, 0x1C, 0x21, 0x26, 0x2F, 0x30, 0x31
, 0x36, 0x45, 0x46, 0x49, 0x4A, 0x4C, 0x4E, 0x52, 0x56, 0x59
, 0x5C, 0x5E, 0x62, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6C
, 0x6E, 0x72, 0x73, 0x78, 0x7A, 0x7D, 0x84, 0x8A, 0x8F, 0x92
, 0x94, 0x97, 0x98, 0x99, 0x9F, 0xA0, 0xA8, 0xAC, 0xB1, 0xB3
, 0xB5, 0xB9, 0xBE, 0xC1, 0xC3, 0xC4, 0xC8, 0xC9, 0xCE, 0xD0
, 0xD2, 0xD4, 0xD5, 0xD9, 0xDC, 0xDF, 0xE0, 0xE5, 0xE6, 0xE7
, 0xEC, 0xED, 0xEE, 0xF4, 0xF8, 0xF9, 0xFB, 0xFC, 0xFE, 0xFF
, 0x06, 0x0D, 0x10, 0x1B, 0x1D, 0x28, 0x2A, 0x2C, 0x2D, 0x30
, 0x31, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3D, 0x3E
, 0x3F, 0x46, 0x47, 0x48, 0x4C, 0x4D, 0x52, 0x56, 0x58, 0x59
, 0x5B, 0x5D, 0x5F, 0x60, 0x61, 0x62, 0x66, 0x67, 0x69, 0x6E
, 0x6F, 0x72, 0x74, 0x75, 0x79, 0x7A, 0x7D, 0x7E, 0x7F, 0x80
, 0x81, 0x84, 0x8A, 0x8B, 0x8D, 0x8F, 0x92, 0x96, 0x9B, 0x9F
, 0xA2, 0xA7, 0xAC, 0xAD, 0xAF, 0xB0, 0xB4, 0xB6, 0xB7, 0xB8
, 0xB9, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC8, 0xCD, 0xCE, 0xD0
, 0xD2, 0xD7, 0xD9, 0xDE, 0xE0, 0xE1, 0xE8, 0xE9, 0xEC, 0xED
, 0xEE, 0xEF, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF7, 0xF8, 0xF9
, 0xFA, 0xFB, 0xFC, 0xFD, 0x01, 0x03, 0x0A, 0x0E, 0x13, 0x15
, 0x16, 0x17, 0x19, 0x1B, 0x1C, 0x1D, 0x1E, 0x21, 0x22, 0x25
, 0x29, 0x2A, 0x2B, 0x2C, 0x2E, 0x31, 0x34, 0x36, 0x37, 0x38
, 0x39, 0x3B, 0x3E, 0x3F, 0x44, 0x45, 0x4D, 0x4E, 0x50, 0x52
, 0x57, 0x60, 0x68, 0x6A, 0x6B, 0x6C, 0x6D, 0x6F, 0x70, 0x72
, 0x75, 0x77, 0x78, 0x7A, 0x7B, 0x7C, 0x7E, 0x80, 0x84, 0x86
, 0x87, 0x89, 0x8B, 0x8E, 0x91, 0x96, 0x9B, 0x9F, 0xA2, 0xA5
, 0xA8, 0xA9, 0xAB, 0xAE, 0xAF, 0xB0, 0xB2, 0xB3, 0xB7, 0xBA
, 0xBB, 0xC0, 0xC2, 0xC8, 0xC9, 0xCA, 0xCD, 0xCF, 0xD0, 0xD1
, 0xD9, 0xDE, 0xE0, 0xE5, 0xE7, 0xE9, 0xEA, 0xED, 0xEE, 0xF2
, 0xFE, 0x03, 0x05, 0x06, 0x09, 0x0A, 0x0D, 0x0F, 0x10, 0x1A
, 0x1B, 0x22, 0x25, 0x26, 0x28, 0x2A, 0x2C, 0x2E, 0x2F, 0x30
, 0x33, 0x34, 0x35, 0x36, 0x3A, 0x3C, 0x3F, 0x41, 0x4B, 0x55
, 0x57, 0x59, 0x5A, 0x5B, 0x5C, 0x5E, 0x5F, 0x63, 0x64, 0x69
, 0x6A, 0x6D, 0x6F, 0x70, 0x76, 0x77, 0x7E, 0x80, 0x81, 0x83
, 0x87, 0x89, 0x8B, 0x8E, 0x90, 0x98, 0x9C, 0x9E, 0x9F, 0xA3
, 0xA6, 0xA7, 0xA8, 0xA9, 0xB0, 0xBA, 0xBD, 0xBF, 0xCA, 0xCF
, 0xD2, 0xD4, 0xD6, 0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE3, 0xE4
, 0xE6, 0xE9, 0xEE, 0xEF, 0xF4, 0xF6, 0xF7, 0xFB, 0xFD, 0xFE
, 0xFF, 0x04, 0x0C, 0x0D, 0x0F, 0x11, 0x13, 0x15, 0x18, 0x19
, 0x1A, 0x1C, 0x1F, 0x22, 0x25, 0x26, 0x28, 0x29, 0x2B, 0x2C
, 0x2D, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x35, 0x37, 0x38, 0x3A
, 0x3B, 0x3D, 0x3E, 0x40, 0x45, 0x48, 0x4B, 0x4C, 0x4E, 0x4F
, 0x54, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x62, 0x65, 0x66, 0x6A
, 0x6B, 0x70, 0x72, 0x74, 0x76, 0x78, 0x79, 0x7F, 0x83, 0x86
, 0x87, 0x8A, 0x8B, 0x8F, 0x91, 0x92, 0x94, 0x96, 0x97, 0x99
, 0x9A, 0x9D, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xAB
, 0xAC, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB8
, 0xB9, 0xBC, 0xBD, 0xBE, 0xC2, 0xC3, 0xC4, 0xC5, 0xC7, 0xC8
, 0xC9, 0xCA, 0xCD, 0xD2, 0xD4, 0xD5, 0xD6, 0xD8, 0xD9, 0xDB
, 0xDE, 0xE0, 0xE2, 0xE3, 0xE4, 0xE6, 0xE7, 0xE8, 0xEA, 0xEB
, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF9, 0xFA, 0xFC, 0xFF, 0x00
, 0x01, 0x03, 0x05, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x10, 0x13
, 0x15, 0x17, 0x18, 0x19, 0x1B, 0x1E, 0x1F, 0x20, 0x21, 0x22
, 0x24, 0x25, 0x26, 0x27, 0x29, 0x2A, 0x2B, 0x2D, 0x30, 0x33
, 0x34, 0x35, 0x38, 0x3A, 0x3C, 0x3E, 0x3F, 0x40, 0x42, 0x43
, 0x46, 0x47, 0x49, 0x4C, 0x4D, 0x52, 0x54, 0x56, 0x58, 0x5C
, 0x5E, 0x5F, 0x61, 0x62, 0x63, 0x64, 0x65, 0x69, 0x6B, 0x6C
, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x78, 0x7B, 0x7C, 0x7D
, 0x7E, 0x82, 0x84, 0x86, 0x87, 0x88, 0x8B, 0x8E, 0x91, 0x93
, 0x96, 0x99, 0x9A, 0xA4, 0xAE, 0xB0, 0xB1, 0xB2, 0xB4, 0xB8
, 0xBA, 0xBF, 0xC2, 0xC3, 0xC5, 0xC6, 0xC8, 0xCA, 0xCD, 0xCE
, 0xCF, 0xD0, 0xD1, 0xD2, 0xD4, 0xD6, 0xD7, 0xD8, 0xDB, 0xDC
, 0xDE, 0xDF, 0xE1, 0xE3, 0xE4, 0xE5, 0xE7, 0xEA, 0xEE, 0xEF
, 0xF1, 0xF2, 0xF4, 0xF8, 0xF9, 0xFC, 0xFE, 0x01, 0x04, 0x07
, 0x08, 0x09, 0x0B, 0x0D, 0x19, 0x1A, 0x1F, 0x20, 0x22, 0x26
, 0x28, 0x29, 0x2D, 0x2F, 0x35, 0x36, 0x37, 0x38, 0x3A, 0x3C
, 0x3E, 0x40, 0x41, 0x43, 0x47, 0x4F, 0x50, 0x51, 0x5A, 0x5B
, 0x5C, 0x5E, 0x61, 0x62, 0x63, 0x65, 0x66, 0x68, 0x6A, 0x6B
, 0x6C, 0x79, 0x7D, 0x7E, 0x7F, 0x80, 0x84, 0x85, 0x87, 0x8B
, 0x8C, 0x8D, 0x8E, 0x91, 0x92, 0x9E, 0x9F, 0xA0, 0xA2, 0xA5
, 0xA7, 0xA9, 0xAA, 0xAC, 0xAD, 0xB0, 0xB3, 0xB5, 0xBB, 0xBC
, 0xBD, 0xBF, 0xC7, 0xCD, 0xD3, 0xD7, 0xDA, 0xDB, 0xDC, 0xE2
, 0xE3, 0xE5, 0xE7, 0xE9, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF3
, 0xF6, 0xF8, 0xFD, 0xFE, 0xFF, 0x00, 0x01, 0x02, 0x09, 0x0C
, 0x0D, 0x11, 0x12, 0x14, 0x16, 0x17, 0x18, 0x1A, 0x1C, 0x1D
, 0x1F, 0x20, 0x23, 0x25, 0x26, 0x27, 0x29, 0x2C, 0x2D, 0x30
, 0x32, 0x34, 0x35, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3E
, 0x40, 0x43, 0x45, 0x47, 0x4C, 0x4E, 0x50, 0x52, 0x55, 0x56
, 0x57, 0x5D, 0x64, 0x68, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F
, 0x77, 0x7C, 0x7F, 0x81, 0x87, 0x89, 0x8C, 0x8D, 0x8E, 0x91
, 0x93, 0x97, 0x98, 0x9A, 0x9B, 0x9C, 0x9F, 0xA1, 0xA3, 0xA5
, 0xA7, 0xA9, 0xAD, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB9, 0xBA
, 0xBC, 0xBE, 0xC1, 0xC5, 0xC9, 0xCA, 0xCB, 0xD0, 0xD4, 0xD5
, 0xD9, 0xDA, 0xE1, 0xE3, 0xE7, 0xE8, 0xEC, 0xEF, 0xF2, 0xF4
, 0xF7, 0xFA, 0xFD, 0x01, 0x05, 0x0E, 0x13, 0x19, 0x1E, 0x24
, 0x26, 0x2A, 0x2B, 0x2C, 0x31, 0x34, 0x3A, 0x3B, 0x3C, 0x3E
, 0x40, 0x41, 0x46, 0x47, 0x48, 0x49, 0x50, 0x53, 0x55, 0x56
, 0x57, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x62, 0x65
, 0x67, 0x68, 0x6D, 0x6F, 0x77, 0x78, 0x7A, 0x7F, 0x80, 0x81
, 0x84, 0x85, 0x8A, 0x8D, 0x8E, 0x8F, 0x9A, 0xA6, 0xA7, 0xAA
, 0xAE, 0xB0, 0xB1, 0xB3, 0xB9, 0xBA, 0xBB, 0xBD, 0xBE, 0xBF
, 0xC0, 0xC1, 0xC3, 0xC6, 0xC8, 0xC9, 0xCB, 0xCD, 0xD1, 0xD2
, 0xD5, 0xD8, 0xDF, 0xE3, 0xE4, 0xE6, 0xE7, 0xE9, 0xEB, 0xED
, 0xEF, 0xF0, 0xF8, 0xFB, 0xFD, 0x00, 0x02, 0x03, 0x05, 0x06
, 0x08, 0x0B, 0x0D, 0x0E, 0x14, 0x17, 0x1A, 0x1C, 0x1E, 0x1F
, 0x20, 0x23, 0x2E, 0x31, 0x33, 0x37, 0x39, 0x3B, 0x3C, 0x3D
, 0x3F, 0x40, 0x46, 0x4B, 0x4C, 0x4D, 0x4E, 0x51, 0x57, 0x60
, 0x61, 0x62, 0x69, 0x6B, 0x70, 0x74, 0x76, 0x77, 0x78, 0x79
, 0x7A, 0x7F, 0x80, 0x81, 0x83, 0x84, 0x86, 0x88, 0x8D, 0x91
, 0x92, 0x95, 0x96, 0x97, 0x98, 0x9C, 0x9D, 0x9F, 0xA0, 0xA5
, 0xA6, 0xA8, 0xA9, 0xAA, 0xAC, 0xAD, 0xAE, 0xAF, 0xB3, 0xB6
, 0xBA, 0xBF, 0xC4, 0xC5, 0xC7, 0xCA, 0xCB, 0xD6, 0xD9, 0xDE
, 0xDF, 0xE0, 0xE3, 0xE5, 0xE6, 0xED, 0xEF, 0xF6, 0xF9, 0xFA
, 0xFD, 0xFF, 0x03, 0x04, 0x06, 0x08, 0x0A, 0x0B, 0x0F, 0x11
, 0x14, 0x15, 0x19, 0x1B, 0x1E, 0x20, 0x24, 0x25, 0x26, 0x28
, 0x2A, 0x2B, 0x2C, 0x2E, 0x31, 0x33, 0x38, 0x3A, 0x3C, 0x3E
, 0x45, 0x46, 0x47, 0x49, 0x4B, 0x4C, 0x4D, 0x4F, 0x50, 0x51
, 0x52, 0x54, 0x56, 0x58, 0x5A, 0x5B, 0x5D, 0x60, 0x62, 0x67
, 0x6E, 0x71, 0x72, 0x75, 0x77, 0x79, 0x7B, 0x7E, 0x80, 0x84
, 0x85, 0x87, 0x8B, 0x8D, 0x8F, 0x90, 0x94, 0x95, 0x97, 0x9C
, 0x9D, 0xA0, 0xA1, 0xA2, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB
, 0xAC, 0xAD, 0xB1, 0xB4, 0xB8, 0xC0, 0xC1, 0xC4, 0xC6, 0xC7
, 0xC9, 0xCB, 0xCC, 0xD1, 0xD3, 0xD9, 0xDA, 0xDB, 0xDD, 0xE0
, 0xE1, 0xE4, 0xE5, 0xE6, 0xE9, 0xEA, 0xEE, 0xF1, 0xF3, 0xF7
, 0xFC, 0xFE, 0x00, 0x07, 0x0B, 0x0C, 0x0D, 0x0F, 0x11, 0x16
, 0x1E, 0x1F, 0x21, 0x23, 0x26, 0x27, 0x2A, 0x2B, 0x37, 0x38
, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x43, 0x4C, 0x4D, 0x50, 0x5C
, 0x5F, 0x60, 0x63, 0x64, 0x65, 0x69, 0x6A, 0x6C, 0x6E, 0x72
, 0x73, 0x74, 0x7B, 0x7C, 0x7D, 0x89, 0x91, 0x92, 0x95, 0x97
, 0x98, 0x9C, 0x9D, 0x9E, 0x9F, 0xA2, 0xA4, 0xA5, 0xAA, 0xAE
, 0xB1, 0xB2, 0xB3, 0xB5, 0xB9, 0xBC, 0xBD, 0xBE, 0xC1, 0xC5
, 0xC7, 0xC8, 0xCA, 0xCC, 0xCD, 0xCE, 0xD5, 0xD6, 0xD7, 0xD9
, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0, 0xE2, 0xE7, 0xE8, 0xEF, 0xF0
, 0xF2, 0xF4, 0xF6, 0xF8, 0xFB, 0xFE, 0x00, 0x02, 0x04, 0x05
, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0D, 0x10, 0x13, 0x14
, 0x15, 0x17, 0x19, 0x1A, 0x1B, 0x1C, 0x20, 0x21, 0x22, 0x27
, 0x2B, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x39, 0x3A, 0x3C
, 0x3F, 0x40, 0x42, 0x43, 0x44, 0x46, 0x4E, 0x50, 0x55, 0x5B
, 0x5E, 0x61, 0x62, 0x66, 0x68, 0x6E, 0x70, 0x71, 0x72, 0x73
, 0x77, 0x79, 0x81, 0x83, 0x86, 0x88, 0x8F, 0x91, 0x93, 0x9C
, 0x9E, 0xA0, 0xA2, 0xA3, 0xA6, 0xAC, 0xAD, 0xAE, 0xB0, 0xB1
, 0xB2, 0xB4, 0xB5, 0xB8, 0xB9, 0xBA, 0xBB, 0xBD, 0xBE, 0xBF
, 0xC4, 0xC7, 0xCA, 0xCB, 0xD2, 0xD7, 0xD8, 0xD9, 0xDA, 0xDD
, 0xDE, 0xE0, 0xE1, 0xE3, 0xE6, 0xE8, 0xE9, 0xEC, 0xEF, 0xF1
, 0xF2, 0xF4, 0xF6, 0xF9, 0xFB, 0x08, 0x09, 0x0A, 0x0B, 0x10
, 0x11, 0x1A, 0x1B, 0x1D, 0x1E, 0x1F, 0x23, 0x2B, 0x2D, 0x2E
, 0x2F, 0x31, 0x32, 0x34, 0x35, 0x36, 0x37, 0x39, 0x3B, 0x3D
, 0x3E, 0x3F, 0x41, 0x43, 0x45, 0x46, 0x47, 0x48, 0x52, 0x54
, 0x55, 0x59, 0x5A, 0x5E, 0x61, 0x62, 0x69, 0x6A, 0x6B, 0x6D
, 0x6F, 0x70, 0x73, 0x79, 0x7C, 0x7D, 0x7E, 0x82, 0x88, 0x8A
, 0x8C, 0x8D, 0x8F, 0x93, 0x94, 0x96, 0x98, 0x9B, 0x9C, 0x9F
, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9
, 0xAA, 0xAB, 0xAC, 0xAD, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB5
, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1
, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB
, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5
, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0
, 0xE1, 0xE2, 0xE3, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB
, 0xED, 0xEE, 0xEF, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6
, 0xF7, 0xF8, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0x00, 0x01
, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0B, 0x0C
, 0x0D, 0x0E, 0x0F, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17
, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1F, 0x20, 0x21, 0x22
, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C
, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36
, 0x38, 0x3A, 0x3D, 0x42, 0x44, 0x45, 0x48, 0x4C, 0x50, 0x51
, 0x54, 0x55, 0x57, 0x58, 0x5A, 0x5F, 0x61, 0x62, 0x68, 0x69
, 0x6A, 0x6E, 0x70, 0x71, 0x72, 0x74, 0x75, 0x77, 0x79, 0x7E
, 0x81, 0x85, 0x86, 0x88, 0x8A, 0x8B, 0x8C, 0x8E, 0x94, 0x9A
, 0x9D, 0x9E, 0x9F, 0xA1, 0xA4, 0xA5, 0xA7, 0xA8, 0xA9, 0xAF
, 0xB0, 0xB2, 0xB6, 0xB8, 0xB9, 0xBC, 0xBD, 0xBF, 0xC1, 0xC5
, 0xCA, 0xCC, 0xCE, 0xD2, 0xD4, 0xD5, 0xD8, 0xDF, 0xE0, 0xE1
, 0xE5, 0xE6, 0xE9, 0xEE, 0xF0, 0xF1, 0xF3, 0xF9, 0xFB, 0xFC
, 0x00, 0x01, 0x03, 0x04, 0x05, 0x06, 0x0B, 0x0C, 0x0D, 0x10
, 0x11, 0x12, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1C, 0x20
, 0x22, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2C, 0x31, 0x33
, 0x35, 0x36, 0x37, 0x38, 0x3B, 0x3D, 0x3F, 0x42, 0x43, 0x46
, 0x4A, 0x4B, 0x4C, 0x4D, 0x52, 0x54, 0x56, 0x58, 0x5A, 0x5E
, 0x69, 0x6A, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x75, 0x76, 0x77
, 0x79, 0x7D, 0x7E, 0x7F, 0x80, 0x83, 0x84, 0x85, 0x86, 0x87
, 0x89, 0x8B, 0x8C, 0x8F, 0x93, 0x96, 0x98, 0x9A, 0x9B, 0x9C
, 0x9D, 0x9F, 0xA0, 0xA1, 0xA2, 0xA4, 0xA5, 0xA9, 0xAA, 0xAB
, 0xAD, 0xAE, 0xAF, 0xB1, 0xB2, 0xB4, 0xB7, 0xBA, 0xBC, 0xBD
, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC6, 0xCC, 0xCD
, 0xCE, 0xD6, 0xD7, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xE1
, 0xE4, 0xE5, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEF
, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF6, 0xF8, 0xFA, 0xFC, 0xFD
, 0x02, 0x05, 0x06, 0x08, 0x09, 0x0A, 0x0D, 0x0E, 0x0F, 0x10
, 0x11, 0x12, 0x13, 0x14, 0x16, 0x18, 0x1A, 0x1B, 0x1E, 0x23
, 0x24, 0x29, 0x2B, 0x2C, 0x2F, 0x30, 0x31, 0x32, 0x36, 0x38
, 0x39, 0x3E, 0x46, 0x48, 0x4A, 0x4B, 0x4C, 0x4E, 0x50, 0x51
, 0x53, 0x54, 0x55, 0x59, 0x5A, 0x60, 0x61, 0x62, 0x65, 0x66
, 0x67, 0x69, 0x6B, 0x6D, 0x6E, 0x70, 0x71, 0x73, 0x74, 0x78
, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x82, 0x88
, 0x8A, 0x8F, 0x91, 0x98, 0x9A, 0x9B, 0x9C, 0x9D, 0xA0, 0xA3
, 0xA6, 0xA8, 0xA9, 0xAA, 0xB3, 0xBA, 0xBB, 0xBD, 0xBE, 0xBF
, 0xC0, 0xC1, 0xC2, 0xC3, 0xC6, 0xC9, 0xCA, 0xCC, 0xCD, 0xCF
, 0xD8, 0xDA, 0xDF, 0xE0, 0xE2, 0xE3, 0xE5, 0xE7, 0xE8, 0xEA
, 0xEC, 0xED, 0xF3, 0xF4, 0xFA, 0xFB, 0xFC, 0xFE, 0x00, 0x01
, 0x02, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0C, 0x0D
, 0x10, 0x12, 0x14, 0x16, 0x1B, 0x1C, 0x1E, 0x1F, 0x21, 0x22
, 0x23, 0x28, 0x2A, 0x2B, 0x2C, 0x2D, 0x2F, 0x30, 0x31, 0x33
, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3E, 0x44
, 0x47, 0x49, 0x4B, 0x4F, 0x58, 0x59, 0x5A, 0x5F, 0x64, 0x66
, 0x68, 0x6B, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x77
, 0x79, 0x7A, 0x7D, 0x7E, 0x7F, 0x82, 0x84, 0x88, 0x8A, 0x8B
, 0x8D, 0x8E, 0x8F, 0x91, 0x92, 0x97, 0x98, 0x99, 0x9C, 0x9D
, 0x9F, 0xA1, 0xA3, 0xA4, 0xA5, 0xA6, 0xA8, 0xA9, 0xAA, 0xAB
, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB3, 0xB4, 0xB7, 0xB8
, 0xB9, 0xBB, 0xBC, 0xBD, 0xBE, 0xC1, 0xC4, 0xC7, 0xC8, 0xCA
, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5
, 0xD7, 0xD8, 0xDB, 0xDC, 0xDE, 0xDF, 0xE0, 0xE1, 0xE3, 0xE4
, 0xE5, 0xE6, 0xE7, 0xEB, 0xEF, 0xF1, 0xF4, 0xF7, 0xF9, 0xFB
, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0C
, 0x0E, 0x0F, 0x11, 0x14, 0x15, 0x17, 0x1A, 0x1B, 0x1C, 0x27
, 0x28, 0x2B, 0x2C, 0x2D, 0x2F, 0x31, 0x32, 0x33, 0x34, 0x35
, 0x36, 0x38, 0x39, 0x3A, 0x3C, 0x40, 0x43, 0x46, 0x47, 0x49
, 0x4A, 0x4F, 0x50, 0x51, 0x52, 0x54, 0x5A, 0x5B, 0x5C, 0x5E
, 0x5F, 0x60, 0x61, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69
, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x77, 0x78, 0x7B, 0x7C
, 0x7D, 0x85, 0x86, 0x89, 0x8A, 0x8E, 0x92, 0x93, 0x96, 0x98
, 0x9B, 0x9C, 0x9E, 0xA0, 0xA2, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB
, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA
, 0xBC, 0xBD, 0xBF, 0xC0, 0xC1, 0xC5, 0xC7, 0xCA, 0xCC, 0xCF
, 0xD4, 0xD6, 0xD8, 0xDC, 0xDD, 0xDF, 0xE0, 0xE1, 0xE5, 0xE9
, 0xEA, 0xEF, 0xF0, 0xF1, 0xF2, 0xF4, 0xF8, 0xF9, 0xFD, 0x01
, 0x03, 0x04, 0x06, 0x07, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
, 0x11, 0x18, 0x1C, 0x1D, 0x24, 0x25, 0x26, 0x27, 0x28, 0x2C
, 0x31, 0x35, 0x38, 0x3C, 0x3D, 0x46, 0x49, 0x51, 0x52, 0x57
, 0x59, 0x5A, 0x5B, 0x5C, 0x61, 0x63, 0x66, 0x69, 0x6B, 0x6C
, 0x6D, 0x6F, 0x71, 0x73, 0x75, 0x76, 0x77, 0x78, 0x7A, 0x82
, 0x87, 0x88, 0x89, 0x8B, 0x8C, 0x8E, 0x90, 0x94, 0x97, 0x99
, 0x9C, 0x9E, 0xA1, 0xAF, 0xB2, 0xB4, 0xB8, 0xB9, 0xBA, 0xBC
, 0xBD, 0xBF, 0xC0, 0xC1, 0xC4, 0xC6, 0xC9, 0xCA, 0xCB, 0xCD
, 0xD0, 0xD1, 0xD3, 0xD6, 0xDD, 0xDF, 0xE0, 0xE3, 0xE5, 0xE6
, 0xEC, 0xEE, 0xEF, 0xF0, 0xFC, 0xFD, 0xFF, 0x06, 0x0C, 0x11
, 0x13, 0x14, 0x17, 0x1A, 0x1E, 0x1F, 0x21, 0x23, 0x25, 0x26
, 0x2B, 0x2C, 0x2D, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D
, 0x41, 0x43, 0x46, 0x48, 0x49, 0x4A, 0x4E, 0x53, 0x55, 0x56
, 0x58, 0x59, 0x5E, 0x62, 0x64, 0x68, 0x69, 0x6A, 0x6D, 0x72
, 0x74, 0x77, 0x79, 0x7A, 0x7B, 0x7E, 0x84, 0x85, 0x87, 0x88
, 0x8A, 0x8C, 0x8F, 0x91, 0x94, 0x9B, 0x9C, 0x9F, 0xA4, 0xA6
, 0xA8, 0xA9, 0xAA, 0xAE, 0xAF, 0xB0, 0xB7, 0xB9, 0xBA, 0xC1
, 0xC9, 0xCD, 0xCE, 0xCF, 0xD0, 0xD3, 0xD5, 0xDC, 0xDD, 0xE4
, 0xE5, 0xE9, 0xEA, 0xF6, 0xF7, 0xF9, 0xFA, 0xFB, 0xFF, 0x04
, 0x05, 0x06, 0x07, 0x0A, 0x0B, 0x11, 0x16, 0x17, 0x1A, 0x1E
, 0x22, 0x27, 0x29, 0x2D, 0x38, 0x3A, 0x3C, 0x3F, 0x4D, 0x4E
, 0x4F, 0x50, 0x51, 0x54, 0x55, 0x5A, 0x5B, 0x5C, 0x5E, 0x5F
, 0x62, 0x67, 0x6B, 0x6C, 0x6E, 0x71, 0x79, 0x7A, 0x7B, 0x7C
, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x8A, 0x8B, 0x8C, 0x8D
, 0x93, 0x95, 0x9C, 0x9D, 0xA3, 0xA4, 0xA7, 0xA8, 0xA9, 0xAA
, 0xAC, 0xAF, 0xB0, 0xB1, 0xB4, 0xB5, 0xB6, 0xBA, 0xC0, 0xC4
, 0xC6, 0xC7, 0xC9, 0xCA, 0xCB, 0xCE, 0xCF, 0xD0, 0xD1, 0xD4
, 0xD8, 0xD9, 0xDB, 0xDE, 0xDF, 0xE4, 0xE9, 0xED, 0xEE, 0xF0
, 0xF1, 0xF2, 0xF3, 0xF4, 0xF8, 0xF9, 0xFA, 0xFB, 0xFE, 0x00
, 0x02, 0x03, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0D, 0x12, 0x13
, 0x15, 0x17, 0x18, 0x1A, 0x1C, 0x1E, 0x21, 0x22, 0x23, 0x25
, 0x29, 0x2E, 0x31, 0x34, 0x37, 0x3B, 0x3E, 0x3F, 0x47, 0x48
, 0x49, 0x4C, 0x4E, 0x53, 0x55, 0x57, 0x59, 0x60, 0x63, 0x64
, 0x65, 0x66, 0x68, 0x6E, 0x70, 0x74, 0x76, 0x78, 0x7B, 0x7C
, 0x7D, 0x7E, 0x82, 0x83, 0x84, 0x85, 0x88, 0x8B, 0x8D, 0x93
, 0x97, 0x9E, 0x9F, 0xA2, 0xA8, 0xAB, 0xAC, 0xAD, 0xAF, 0xB3
, 0xB5, 0xBA, 0xBB, 0xBD, 0xC0, 0xC4, 0xC6, 0xC8, 0xCA, 0xCB
, 0xD1, 0xD2, 0xD3, 0xDB, 0xE0, 0xE3, 0xE5, 0xEA, 0xEC, 0xEE
, 0xEF, 0xF2, 0xF6, 0xF9, 0xFB, 0xFE, 0x03, 0x05, 0x06, 0x0A
, 0x0D, 0x10, 0x11, 0x13, 0x14, 0x15, 0x16, 0x1B, 0x1F, 0x21
, 0x22, 0x23, 0x31, 0x32, 0x36, 0x39, 0x3B, 0x3C, 0x40, 0x44
, 0x45, 0x4A, 0x4C, 0x4D, 0x53, 0x54, 0x57, 0x59, 0x5B, 0x5D
, 0x61, 0x62, 0x63, 0x64, 0x65, 0x68, 0x69, 0x6B, 0x6C, 0x6E
, 0x70, 0x72, 0x77, 0x79, 0x7D, 0x7E, 0x7F, 0x81, 0x82, 0x84
, 0x85, 0x88, 0x8B, 0x8D, 0x92, 0x96, 0x9C, 0x9E, 0xA2, 0xA4
, 0xAB, 0xAD, 0xB1, 0xB7, 0xBC, 0xC1, 0xC2, 0xC5, 0xC6, 0xC9
, 0xCA, 0xCE, 0xCF, 0xD2, 0xD4, 0xD5, 0xD8, 0xD9, 0xDC, 0xDD
, 0xDF, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE8, 0xEF, 0xF0, 0xF1
, 0xF3, 0xF4, 0xF8, 0xF9, 0xFC, 0xFD, 0xFE, 0x02, 0x07, 0x0A
, 0x10, 0x12, 0x13, 0x15, 0x19, 0x1A, 0x1B, 0x1F, 0x21, 0x25
, 0x2A, 0x2B, 0x30, 0x32, 0x33, 0x34, 0x36, 0x38, 0x3B, 0x3D
, 0x41, 0x44, 0x56, 0x5D, 0x5E, 0x5F, 0x60, 0x64, 0x66, 0x6A
, 0x6C, 0x6F, 0x72, 0x7B, 0x7F, 0x81, 0x83, 0x86, 0x8B, 0x8F
, 0x93, 0x96, 0x98, 0x9C, 0xA1, 0xA6, 0xAA, 0xAC, 0xAF, 0xB2
, 0xB7, 0xBA, 0xBD, 0xBF, 0xC0, 0xC1, 0xC2, 0xC4, 0xC5, 0xC6
, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCE, 0xCF, 0xD0, 0xD1
, 0xD2, 0xD4, 0xD6, 0xDA, 0xDC, 0xDE, 0xE3, 0xE5, 0xE6, 0xEB
, 0xEF, 0xF3, 0xF4, 0xF6, 0xF8, 0xFC, 0x00, 0x02, 0x03, 0x07
, 0x08, 0x0A, 0x0C, 0x0E, 0x0F, 0x10, 0x11, 0x13, 0x15, 0x16
, 0x17, 0x18, 0x1B, 0x1D, 0x1F, 0x22, 0x23, 0x25, 0x2A, 0x2D
, 0x31, 0x34, 0x36, 0x3A, 0x3B, 0x3C, 0x3E, 0x41, 0x46, 0x48
, 0x4E, 0x50, 0x52, 0x54, 0x55, 0x56, 0x58, 0x5B, 0x5E, 0x60
, 0x61, 0x62, 0x63, 0x66, 0x68, 0x69, 0x6B, 0x6C, 0x6D, 0x6E
, 0x70, 0x71, 0x72, 0x73, 0x75, 0x79, 0x7B, 0x7C, 0x7F, 0x84
, 0x85, 0x86, 0x87, 0x89, 0x8A, 0x8C, 0x8D, 0x91, 0x92, 0x93
, 0x95, 0x98, 0x9A, 0x9E, 0xA0, 0xA1, 0xA3, 0xA4, 0xA5, 0xA6
, 0xA7, 0xA8, 0xAA, 0xB0, 0xB2, 0xB6, 0xB9, 0xBC, 0xBF, 0xC2
, 0xC4, 0xC7, 0xC9, 0xCB, 0xCD, 0xCF, 0xD1, 0xD2, 0xD6, 0xD7
, 0xDB, 0xDC, 0xDE, 0xE2, 0xE4, 0xE6, 0xE7, 0xEB, 0xED, 0xEE
, 0xF1, 0xF3, 0xF6, 0xF7, 0xF8, 0xFA, 0xFC, 0xFE, 0x00, 0x01
, 0x02, 0x04, 0x05, 0x07, 0x0A, 0x0E, 0x10, 0x14, 0x16, 0x17
, 0x19, 0x1A, 0x1B, 0x1D, 0x20, 0x26, 0x28, 0x2B, 0x2C, 0x33
, 0x39, 0x3E, 0x41, 0x46, 0x49, 0x4E, 0x4F, 0x56, 0x58, 0x59
, 0x5A, 0x5C, 0x5F, 0x66, 0x6B, 0x6C, 0x6F, 0x70, 0x74, 0x77
, 0x7D, 0x80, 0x8A, 0x8E, 0x92, 0x93, 0x95, 0x96, 0x9A, 0x9C
, 0x9E, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8
, 0xA9, 0xAA, 0xAB, 0xAD, 0xAE, 0xAF, 0xB0, 0xB2, 0xB3, 0xB4
, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBC, 0xBD, 0xBE, 0xBF
, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC8, 0xC9, 0xCA
, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5
, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF
, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9
, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4
, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE
, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13
, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D
, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28
, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32
, 0x33, 0x34, 0x35, 0x36, 0x37, 0x3F, 0x41, 0x46, 0x47, 0x48
, 0x49, 0x4C, 0x4E, 0x50, 0x54, 0x55, 0x5A, 0x61, 0x62, 0x6A
, 0x6B, 0x6C, 0x6D, 0x73, 0x78, 0x79, 0x7A, 0x82, 0x85, 0x89
, 0x8A, 0x8C, 0x8D, 0x93, 0x94, 0x98, 0x9D, 0x9E, 0xA0, 0xA1
, 0xA2, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAF, 0xB0, 0xB2
, 0xB3, 0xB4, 0xB6, 0xB7, 0xB8, 0xBA, 0xBB, 0xBC, 0xBD, 0xBF
, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC7, 0xC8, 0xCA, 0xD1
, 0xD2, 0xD3, 0xD5, 0xDA, 0xDC, 0xDE, 0xE0, 0xE1, 0xE2, 0xE3
, 0xE4, 0xE6, 0xE7, 0xEA, 0xEC, 0xED, 0xF4, 0xF8, 0xFA, 0xFB
, 0xFC, 0xFD, 0xFE, 0x04, 0x05, 0x08, 0x0A, 0x0D, 0x0F, 0x10
, 0x13, 0x16, 0x17, 0x1B, 0x1D, 0x1E, 0x1F, 0x21, 0x22, 0x23
, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D
, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37
, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41
, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B
, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x53, 0x54, 0x55, 0x56, 0x58
, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x60, 0x61, 0x62, 0x63
, 0x64, 0x66, 0x67, 0x6B, 0x6D, 0x70, 0x73, 0x74, 0x75, 0x76
, 0x77, 0x81, 0x84, 0x85, 0x8A, 0x8B, 0x91, 0x94, 0x95, 0x99
, 0x9F, 0xA3, 0xA8, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB8, 0xBA
, 0xBC, 0xBE, 0xBF, 0xC3, 0xC4, 0xC6, 0xCB, 0xCC, 0xCE, 0xCF
, 0xD1, 0xD6, 0xD7, 0xDA, 0xDB, 0xDD, 0xDE, 0xDF, 0xE1, 0xE3
, 0xE4, 0xE6, 0xE8, 0xEA, 0xEB, 0xEC, 0xEF, 0xF3, 0xF5, 0xF7
, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0x05, 0x09, 0x0A, 0x0C
, 0x0F, 0x10, 0x14, 0x1D, 0x1E, 0x1F, 0x21, 0x22, 0x23, 0x29
, 0x2A, 0x2B, 0x2C, 0x2E, 0x2F, 0x31, 0x34, 0x35, 0x39, 0x3A
, 0x3D, 0x40, 0x41, 0x42, 0x44, 0x47, 0x48, 0x49, 0x4A, 0x4B
, 0x4C, 0x51, 0x52, 0x55, 0x59, 0x5F, 0x63, 0x64, 0x66, 0x69
, 0x6C, 0x6D, 0x6F, 0x70, 0x72, 0x74, 0x76, 0x7A, 0x7C, 0x7F
, 0x81, 0x82, 0x85, 0x87, 0x89, 0x8A, 0x8B, 0x8D, 0x8F, 0x90
, 0x91, 0x92, 0x93, 0x94, 0x9A, 0x9C, 0x9E, 0xA1, 0xA5, 0xA6
, 0xAA, 0xAB, 0xAC, 0xAF, 0xB2, 0xBA, 0xC0, 0xCA, 0xCB, 0xCC
, 0xCD, 0xCE, 0xCF, 0xD2, 0xD4, 0xDB, 0xDF, 0xEB, 0xF8, 0xF9
, 0xFA, 0xFB, 0xFC, 0xFE, 0x03, 0x05, 0x07, 0x09, 0x0A, 0x0B
, 0x12, 0x13, 0x14, 0x15, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x25
, 0x26, 0x29, 0x2A, 0x2F, 0x33, 0x38, 0x3B, 0x3E, 0x3F, 0x42
, 0x44, 0x45, 0x46, 0x49, 0x4D, 0x4E, 0x54, 0x5F, 0x61, 0x62
, 0x64, 0x66, 0x67, 0x68, 0x69, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F
, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79
, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x81, 0x82, 0x83, 0x84
, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8D, 0x8E, 0x8F
, 0x90, 0x91, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A
, 0x9B, 0x9C, 0x9E, 0x9F, 0xA3, 0xA6, 0xA8, 0xA9, 0xAB, 0xAD
, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB6, 0xB9, 0xBD, 0xBE, 0xC1
, 0xC2, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xCE, 0xD0, 0xD1, 0xD3
, 0xD4, 0xD5, 0xD8, 0xD9, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE2
, 0xE4, 0xE5, 0xE6, 0xE8, 0xE9, 0xEA, 0xEB, 0xED, 0xEE, 0xF0
, 0xF3, 0xF4, 0xF7, 0xF8, 0xF9, 0xFA, 0xFD, 0x00, 0x01, 0x02
, 0x03, 0x04, 0x05, 0x06, 0x09, 0x0A, 0x0B, 0x0D, 0x0F, 0x10
, 0x11, 0x12, 0x14, 0x15, 0x16, 0x17, 0x19, 0x1A, 0x1B, 0x1D
, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x26, 0x2D, 0x2E, 0x2F
, 0x31, 0x32, 0x35, 0x36, 0x38, 0x3B, 0x3C, 0x3E, 0x41, 0x42
, 0x44, 0x47, 0x4A, 0x4B, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52
, 0x53, 0x54, 0x55, 0x57, 0x58, 0x59, 0x5B, 0x5C, 0x5D, 0x5E
, 0x60, 0x62, 0x63, 0x65, 0x68, 0x69, 0x6D, 0x6E, 0x72, 0x74
, 0x75, 0x77, 0x78, 0x7A, 0x7C, 0x7D, 0x7F, 0x80, 0x81, 0x82
, 0x83, 0x84, 0x87, 0x88, 0x8A, 0x8B, 0x8F, 0x90, 0x91, 0x93
, 0x95, 0x97, 0x99, 0x9B, 0x9D, 0xA1, 0xA2, 0xA3, 0xA6, 0xAA
, 0xAC, 0xAE, 0xAF, 0xB0, 0xB1, 0xB3, 0xB4, 0xB5, 0xB6, 0xB8
, 0xB9, 0xBA, 0xBB, 0xBE, 0xC1, 0xC3, 0xC4, 0xC5, 0xC7, 0xCA
, 0xCE, 0xCF, 0xD0, 0xD1, 0xD3, 0xD7, 0xDB, 0xDC, 0xDD, 0xDF
, 0xE1, 0xE2, 0xE6, 0xE7, 0xE8, 0xEB, 0xED, 0xEF, 0xF4, 0xF5
, 0xF8, 0xFD, 0xFE, 0x02, 0x04, 0x06, 0x09, 0x12, 0x14, 0x16
, 0x17, 0x18, 0x19, 0x1E, 0x22, 0x23, 0x27, 0x2D, 0x2F, 0x30
, 0x31, 0x32, 0x34, 0x36, 0x39, 0x3A, 0x43, 0x46, 0x48, 0x49
, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x52, 0x57, 0x5A
, 0x5D, 0x5E, 0x61, 0x62, 0x63, 0x64, 0x65, 0x69, 0x6A, 0x6C
, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x74, 0x75, 0x76, 0x77, 0x78
, 0x79, 0x7D, 0x7E, 0x7F, 0x83, 0x85, 0x87, 0x89, 0x8B, 0x8C
, 0x8D, 0x90, 0x91, 0x92, 0x9A, 0x9B, 0x9C, 0x9E, 0xA2, 0xA3
, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB1, 0xB4, 0xB5, 0xBA
, 0xC0, 0xC1, 0xC3, 0xC5, 0xC6, 0xC7, 0xC9, 0xCA, 0xCB, 0xCC
, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD3, 0xD4, 0xD5, 0xD7, 0xD8
, 0xD9, 0xDC, 0xDD, 0xE3, 0xE4, 0xE6, 0xE7, 0xE9, 0xED, 0xF5
, 0xF7, 0xF9, 0x00, 0x01, 0x02, 0x04, 0x07, 0x09, 0x0D, 0x10
, 0x11, 0x14, 0x15, 0x1E, 0x23, 0x25, 0x26, 0x27, 0x2E, 0x30
, 0x33, 0x34, 0x37, 0x38, 0x39, 0x3A, 0x3D, 0x3E, 0x3F, 0x40
, 0x45, 0x48, 0x49, 0x4B, 0x4D, 0x51, 0x57, 0x5A, 0x5B, 0x5E
, 0x64, 0x66, 0x6C, 0x6D, 0x74, 0x78, 0x7A, 0x7B, 0x7C, 0x7F
, 0x80, 0x83, 0x85, 0x8E, 0x91, 0x93, 0x96, 0x98, 0x9A, 0x9C
, 0xA0, 0xA3, 0xA5, 0xA6, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAE
, 0xB2, 0xB3, 0xB7, 0xB9, 0xBB, 0xBC, 0xC1, 0xC3, 0xC5, 0xC7
, 0xC8, 0xCC, 0xCF, 0xD2, 0xDD, 0xDF, 0xE4, 0xE6, 0xE8, 0xEA
, 0xEE, 0xEF, 0xF0, 0xF1, 0xF8, 0xFC, 0x01, 0x04, 0x06, 0x08
, 0x10, 0x12, 0x15, 0x18, 0x19, 0x1A, 0x1B, 0x1F, 0x20, 0x21
, 0x22, 0x26, 0x28, 0x29, 0x2B, 0x2E, 0x2F, 0x33, 0x36, 0x38
, 0x3E, 0x46, 0x47, 0x4A, 0x4B, 0x4D, 0x54, 0x58, 0x5A, 0x5B
, 0x64, 0x65, 0x6A, 0x6C, 0x70, 0x75, 0x76, 0x7A, 0x7E, 0x82
, 0x8A, 0x8F, 0x94, 0x96, 0x97, 0x98, 0x9A, 0xA2, 0xA3, 0xA6
, 0xA7, 0xA8, 0xA9, 0xAA, 0xAC, 0xAE, 0xB0, 0xB3, 0xB5, 0xC3
, 0xC7, 0xC8, 0xCA, 0xCC, 0xCD, 0xD1, 0xD6, 0xD7, 0xD8, 0xDC
, 0xDD, 0xDE, 0xDF, 0xE1, 0xE2, 0xE4, 0xE8, 0xF5, 0xF7, 0xF9
, 0xFD, 0x03, 0x0B, 0x10, 0x12, 0x13, 0x14, 0x18, 0x19, 0x20
, 0x28, 0x2B, 0x2E, 0x32, 0x33, 0x35, 0x38, 0x3A, 0x3E, 0x3F
, 0x44, 0x4A, 0x4C, 0x51, 0x52, 0x60, 0x63, 0x64, 0x6A, 0x6B
, 0x6D, 0x70, 0x72, 0x77, 0x7C, 0x7D, 0x7E, 0x7F, 0x85, 0x86
, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90
, 0x92, 0x93, 0x94, 0x95, 0x97, 0x99, 0x9A, 0x9B, 0x9C, 0x9D
, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7
, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1
, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB
, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5
, 0xC6, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xD0, 0xD1
, 0xD2, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDB, 0xDC, 0xDD, 0xDE
, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE7, 0xE8, 0xE9
, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0, 0xF1, 0xF2, 0xF3
, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFC, 0xFD, 0xFE
, 0xFF, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12
, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1D
, 0x1E, 0x1F, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x28, 0x29
, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x34
, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3E, 0x3F
, 0x40, 0x41, 0x42, 0x44, 0x45, 0x46, 0x47, 0x49, 0x4A, 0x4C
, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x56, 0x57
, 0x58, 0x59, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x61, 0x62, 0x63
, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D
, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x76, 0x77, 0x7F, 0x80, 0x82
, 0x83, 0x86, 0x89, 0x8B, 0x8C, 0x8E, 0x8F, 0x91, 0x92, 0x93
, 0x94, 0x98, 0xA1, 0xA3, 0xA4, 0xA5, 0xA8, 0xA9, 0xAB, 0xAC
, 0xAD, 0xB1, 0xB6, 0xB9, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC3
, 0xC6, 0xC8, 0xCA, 0xCB, 0xCC, 0xD0, 0xD4, 0xD5, 0xD6, 0xDC
, 0xDE, 0xE1, 0xE2, 0xE5, 0xE8, 0xE9, 0xEA, 0xEB, 0xED, 0xEE
, 0xEF, 0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8
, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0x00, 0x01, 0x02, 0x03
, 0x04, 0x05, 0x06, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E
, 0x0F, 0x10, 0x11, 0x12, 0x14, 0x15, 0x16, 0x17, 0x19, 0x1A
, 0x1C, 0x1D, 0x1F, 0x21, 0x22, 0x2A, 0x2C, 0x2E, 0x31, 0x32
, 0x33, 0x34, 0x35, 0x36, 0x3B, 0x3C, 0x3D, 0x3F, 0x40, 0x42
, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4B, 0x4C, 0x4D, 0x50
, 0x54, 0x55, 0x58, 0x5B, 0x5D, 0x5E, 0x5F, 0x61, 0x62, 0x63
, 0x64, 0x67, 0x68, 0x69, 0x6A, 0x6C, 0x70, 0x72, 0x73, 0x74
, 0x75, 0x76, 0x77, 0x78, 0x7D, 0x84, 0x85, 0x86, 0x88, 0x89
, 0x8A, 0x8B, 0x8D, 0x8E, 0x8F, 0x90, 0x94, 0x95, 0x97, 0x98
, 0x99, 0x9B, 0x9C, 0xA7, 0xA8, 0xAA, 0xB0, 0xB1, 0xB3, 0xB4
, 0xB6, 0xB8, 0xB9, 0xBB, 0xBC, 0xBD, 0xBE, 0xC0, 0xC1, 0xC4
, 0xC5, 0xC6, 0xC7, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF
, 0xD2, 0xD5, 0xD6, 0xD9, 0xDB, 0xDC, 0xDE, 0xE0, 0xE2, 0xE3
, 0xE8, 0xE9, 0xEA, 0xEF, 0xF2, 0xF3, 0xF6, 0xF7, 0xF9, 0xFB
, 0xFE, 0x00, 0x01, 0x04, 0x06, 0x07, 0x08, 0x09, 0x0D, 0x0E
, 0x0F, 0x11, 0x13, 0x16, 0x1C, 0x1E, 0x24, 0x27, 0x2A, 0x2D
, 0x30, 0x32, 0x38, 0x39, 0x3D, 0x3E, 0x42, 0x44, 0x48, 0x52
, 0x53, 0x56, 0x59, 0x5A, 0x5B, 0x5C, 0x5E, 0x60, 0x61, 0x62
, 0x65, 0x66, 0x68, 0x69, 0x73, 0x74, 0x76, 0x7C, 0x85, 0x8B
, 0x8D, 0x8F, 0x91, 0x92, 0x94, 0x98, 0xA0, 0xA3, 0xA6, 0xAB
, 0xAD, 0xAF, 0xB2, 0xB4, 0xC1, 0xC3, 0xC6, 0xC9, 0xCB, 0xCC
, 0xD3, 0xD9, 0xDC, 0xDE, 0xE6, 0xE7, 0xE9, 0xEA, 0xEB, 0xEC
, 0xED, 0xF3, 0xF5, 0xF6, 0xF9, 0xFB, 0xFF, 0x01, 0x02, 0x03
, 0x05, 0x06, 0x07, 0x08, 0x0A, 0x0C, 0x0E, 0x0F, 0x10, 0x11
, 0x12, 0x13, 0x17, 0x18, 0x1C, 0x21, 0x24, 0x26, 0x2B, 0x2D
, 0x30, 0x37, 0x38, 0x39, 0x3B, 0x46, 0x4C, 0x4D, 0x4E, 0x4F
, 0x53, 0x58, 0x59, 0x5B, 0x5E, 0x62, 0x65, 0x67, 0x6B, 0x6F
, 0x70, 0x71, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A
, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81, 0x82, 0x83, 0x84
, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8C, 0x8D, 0x8F, 0x90
, 0x91, 0x93, 0x94, 0x96, 0x97, 0x98, 0x9A, 0x9B, 0x9C, 0x9D
, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8
, 0xAE, 0xAF, 0xB1, 0xB3, 0xB6, 0xBA, 0xBC, 0xC4, 0xC6, 0xCE
, 0xD1, 0xD2, 0xD3, 0xD5, 0xD8, 0xD9, 0xDA, 0xDB, 0xDE, 0xDF
, 0xE2, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xED, 0xEF, 0xF2, 0xF4
, 0xFC, 0xFD, 0xFE, 0x03, 0x05, 0x09, 0x0A, 0x0C, 0x0D, 0x10
, 0x11, 0x12, 0x13, 0x18, 0x1A, 0x1B, 0x1E, 0x21, 0x28, 0x2E
, 0x33, 0x35, 0x3C, 0x3D, 0x3E, 0x3F, 0x43, 0x45, 0x48, 0x49
, 0x4B, 0x4C, 0x51, 0x52, 0x54, 0x55, 0x57, 0x5C, 0x5E, 0x63
, 0x65, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F
, 0x70, 0x71, 0x72, 0x74, 0x75, 0x76, 0x77, 0x7A, 0x7C, 0x7D
, 0x7F, 0x80, 0x81, 0x84, 0x85, 0x86, 0x87, 0x88, 0x8A, 0x8B
, 0x8D, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97
, 0x98, 0x99, 0xA5, 0xA8, 0xAC, 0xAD, 0xAE, 0xB1, 0xB3, 0xB4
, 0xC1, 0xD0, 0xD1, 0xD2, 0xD4, 0xD5, 0xD8, 0xD9, 0xDB, 0xDD
, 0xDF, 0xE2, 0xED, 0xF1, 0xFF, 0x01, 0x05, 0x0D, 0x0E, 0x0F
, 0x16, 0x19, 0x2B, 0x2D, 0x2E, 0x30, 0x35, 0x36, 0x37, 0x38
, 0x3E, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x4A, 0x4D, 0x4F
, 0x55, 0x57, 0x5A, 0x5B, 0x5F, 0x62, 0x64, 0x65, 0x6A, 0x6C
, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x73, 0x74, 0x75, 0x76, 0x77
, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x80, 0x81
, 0x82, 0x84, 0x85, 0x86, 0x87, 0x88, 0x8A, 0x8B, 0x8C, 0x8F
, 0x90, 0x91, 0x92, 0x93, 0x96, 0x97, 0x98, 0x9A, 0x9B, 0x9C
, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA7
, 0xA8, 0xAF, 0xB0, 0xB1, 0xB6, 0xB7, 0xB8, 0xBA, 0xBC, 0xC0
, 0xC1, 0xC2, 0xC5, 0xCB, 0xCC, 0xCF, 0xD1, 0xD2, 0xD3, 0xD4
, 0xD5, 0xD6, 0xD8, 0xDF, 0xE1, 0xE6, 0xEB, 0xED, 0xEE, 0xEF
, 0xF9, 0xFB, 0x03, 0x06, 0x08, 0x0D, 0x0F, 0x13, 0x1A, 0x1F
, 0x22, 0x23, 0x25, 0x27, 0x28, 0x29, 0x2E, 0x2F, 0x31, 0x32
, 0x3B, 0x3C, 0x41, 0x42, 0x43, 0x44, 0x45, 0x47, 0x48, 0x49
, 0x4D, 0x4E, 0x4F, 0x51, 0x54, 0x58, 0x5A, 0x6F, 0x74, 0x77
, 0x90, 0x91, 0x92, 0x9A, 0x9E, 0xAA, 0xAB, 0xAD, 0xAE, 0xC0
, 0xC1, 0xC7, 0xC8, 0xC9, 0xCA, 0xD4, 0xD6, 0xDB, 0xE1, 0xE2
, 0xE4, 0xE7, 0xE8, 0xEA, 0xEB, 0xF0, 0xFD, 0x08, 0x09, 0x0D
, 0x12, 0x13, 0x23, 0x25, 0x28, 0x29, 0x2D, 0x31, 0x32, 0x33
, 0x37, 0x39, 0x3B, 0x3E, 0x48, 0x49, 0x52, 0x54, 0x56, 0x57
, 0x58, 0x5F, 0x67, 0x6D, 0x77, 0x78, 0x7A, 0x7C, 0x7F, 0x81
, 0x82, 0x85, 0x86, 0x87, 0x88, 0x8B, 0x8D, 0x8E, 0x90, 0x91
, 0x92, 0x94, 0x95, 0x9A, 0x9B, 0x9C, 0x9E, 0x9F, 0xA0, 0xA1
, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAB, 0xAD
, 0xAE, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8
, 0xBA, 0xBB, 0xBC, 0xBD, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xCA
, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD3, 0xD4, 0xD5, 0xD6
, 0xD7, 0xD8, 0xD9, 0xDC, 0xDD, 0xDE, 0xDF, 0xE2, 0xE5, 0xE9
, 0xF3, 0xF4, 0xF6, 0x03, 0x06, 0x07, 0x09, 0x12, 0x15, 0x1B
, 0x1D, 0x1F, 0x23, 0x26, 0x28, 0x2F, 0x30, 0x3B, 0x3F, 0x42
, 0x51, 0x52, 0x53, 0x5C, 0x5D, 0x60, 0x61, 0x6A, 0x6C, 0x6F
, 0x72, 0x87, 0x89, 0x98, 0x9A, 0xA9, 0xAF, 0xB4, 0xB8, 0xBB
, 0xBC, 0xC2, 0xD3, 0xD7, 0xD9, 0xDA, 0xE5, 0xE6, 0xEF, 0xF2
, 0xF3, 0xF8, 0xF9, 0xFA, 0x15, 0x1A, 0x1B, 0x1D, 0x1E, 0x1F
, 0x20, 0x21, 0x22, 0x23, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2B
, 0x2C, 0x2D, 0x2F, 0x31, 0x32, 0x33, 0x35, 0x36, 0x37, 0x38
, 0x39, 0x3A, 0x3D, 0x3E, 0x3F, 0x41, 0x42, 0x43, 0x44, 0x45
, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4E, 0x4F, 0x51
, 0x55, 0x57, 0x58, 0x5A, 0x5B, 0x5C, 0x5E, 0x63, 0x64, 0x66
, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x70, 0x71, 0x73
, 0x75, 0x79, 0x7A, 0x7C, 0x7D, 0x7E, 0x7F, 0x82, 0x87, 0x88
, 0x8B, 0x92, 0x93, 0x97, 0x9D, 0x9F, 0xA5, 0xA6, 0xA9, 0xB4
, 0xB5, 0xB8, 0xBB, 0xBC, 0xBD, 0xBE, 0xC3, 0xC4, 0xC9, 0xCC
, 0xCD, 0xCE, 0xCF, 0xD1, 0xD4, 0xD8, 0xDB, 0xDC, 0xDD, 0xDE
, 0xDF, 0xE0, 0xE2, 0xE5, 0xE7, 0xE8, 0xE9, 0xEA, 0xEF, 0xF2
, 0xF4, 0xF7, 0xF9, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0x07, 0x09
, 0x0B, 0x0D, 0x0E, 0x10, 0x13, 0x15, 0x17, 0x19, 0x20, 0x22
, 0x2C, 0x2F, 0x34, 0x37, 0x39, 0x3B, 0x3D, 0x3E, 0x44, 0x4A
, 0x4B, 0x4F, 0x50, 0x51, 0x52, 0x54, 0x59, 0x5C, 0x5F, 0x60
, 0x61, 0x63, 0x66, 0x67, 0x6A, 0x6C, 0x72, 0x77, 0x7F, 0x80
, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C
, 0x8D, 0x90, 0x94, 0x95, 0x99, 0x9A, 0x9B, 0x9C, 0x9F, 0xA0
, 0xA2 };

const unsigned short g_mdi_TTS_index_table[] = {
  1090,  217,  752,  997,  1163,  832,  854,  1026,  404,  73
,  1114,  290,  136,  1195,  771,  722,  876,  782,  62,  1089
,  165,  221,  901,  123,  220,  220,  534,  1075,  63,  837
,  884,  303,  1070,  1199,  1182,  273,  148,  541,  210,  995
,  190,  1005,  1191,  528,  439,  735,  638,  435,  984,  595
,  1093,  1178,  1016,  1153,  376,  254,  517,  740,  705,  767
,  324,  123,  1092,  616,  435,  754,  1088,  1021,  1031,  881
,  404,  583,  565,  819,  759,  565,  518,  1114,  1175,  876
,  252,  141,  1113,  491,  1123,  379,  753,  1018,  430,  308
,  308,  1073,  1039,  1073,  405,  1007,  999,  459,  418,  347
,  1093,  104,  366,  632,  1033,  429,  959,  535,  773,  66
,  1042,  808,  190,  1093,  866,  808,  517,  217,  1144,  427
,  748,  135,  1162,  426,  425,  812,  165,  566,  84,  1207
,  876,  923,  1163,  283,  1027,  962,  810,  758,  1093,  189
,  547,  1092,  827,  1091,  633,  601,  1080,  1184,  724,  1018
,  414,  411,  810,  272,  263,  754,  459,  1090,  405,  1018
,  407,  281,  254,  1051,  280,  1184,  1108,  402,  396,  1114
,  833,  1004,  146,  1071,  852,  106,  566,  121,  1004,  1192
,  66,  318,  659,  27,  545,  865,  903,  903,  408,  211
,  192,  1192,  73,  1005,  204,  1192,  1227,  1111,  945,  1160
,  360,  985,  861,  1113,  1093,  277,  1228,  315,  673,  962
,  658,  786,  1104,  990,  758,  450,  715,  515,  1079,  23
,  408,  252,  63,  405,  790,  951,  420,  1093,  875,  455
,  1179,  504,  128,  480,  528,  876,  1189,  1111,  629,  566
,  223,  312,  1090,  1025,  573,  420,  1172,  90,  767,  484
,  100,  678,  1018,  373,  773,  573,  438,  51,  1023,  169
,  244,  783,  448,  1217,  769,  528,  1106,  911,  281,  527
,  740,  33,  1113,  903,  1025,  1044,  1114,  135,  1076,  534
,  528,  901,  413,  1051,  282,  440,  700,  276,  8,  47
,  106,  534,  84,  303,  327,  37,  881,  599,  197,  446
,  1048,  935,  375,  1092,  946,  425,  109,  263,  471,  443
,  440,  761,  657,  566,  1204,  1013,  570,  1157,  1179,  777
,  1076,  410,  407,  1004,  826,  1002,  726,  1040,  1228,  959
,  414,  1210,  610,  1092,  90,  1172,  693,  965,  1133,  573
,  1005,  272,  107,  493,  283,  528,  30,  423,  84,  833
,  37,  1038,  408,  188,  935,  59,  140,  685,  172,  1104
,  1210,  16,  146,  1114,  1157,  852,  129,  845,  777,  554
,  427,  561,  758,  1027,  1197,  1034,  767,  749,  1020,  536
,  420,  436,  843,  272,  1030,  418,  414,  1199,  320,  912
,  415,  411,  725,  1091,  678,  1093,  193,  430,  1059,  484
,  413,  190,  59,  818,  135,  100,  427,  107,  520,  1108
,  139,  103,  528,  569,  685,  935,  1076,  250,  1019,  1124
,  1117,  1049,  130,  1166,  1049,  1027,  330,  466,  235,  610
,  235,  250,  972,  903,  1076,  1076,  874,  194,  758,  224
,  269,  592,  23,  429,  526,  820,  653,  790,  534,  17
,  312,  551,  1020,  506,  314,  327,  1045,  61,  753,  440
,  210,  1206,  1080,  412,  880,  407,  104,  962,  653,  630
,  294,  799,  90,  90,  1131,  1188,  594,  610,  741,  815
,  1041,  447,  678,  327,  1183,  1116,  620,  608,  534,  221
,  274,  61,  379,  130,  445,  490,  1088,  524,  223,  1029
,  539,  431,  752,  1203,  904,  1175,  533,  212,  545,  223
,  413,  166,  542,  542,  671,  406,  258,  276,  281,  741
,  452,  390,  452,  203,  849,  1049,  969,  13,  138,  404
,  195,  349,  1140,  196,  212,  90,  810,  269,  772,  1093
,  454,  139,  1008,  1046,  381,  1121,  539,  549,  1143,  294
,  152,  138,  849,  704,  56,  710,  528,  849,  56,  430
,  321,  198,  476,  1181,  885,  792,  844,  163,  466,  335
,  335,  452,  242,  407,  946,  430,  1143,  1035,  466,  502
,  759,  98,  322,  414,  943,  746,  294,  994,  65,  404
,  851,  65,  440,  872,  413,  322,  283,  300,  452,  152
,  104,  730,  420,  766,  445,  382,  440,  722,  549,  484
,  335,  414,  400,  407,  1093,  528,  792,  27,  312,  408
,  1019,  584,  539,  223,  1192,  682,  423,  786,  859,  528
,  428,  514,  487,  360,  876,  431,  66,  1106,  610,  1067
,  603,  517,  223,  1057,  1057,  454,  1019,  1067,  872,  514
,  633,  876,  404,  774,  420,  1040,  584,  1067,  528,  792
,  31,  857,  1123,  315,  1019,  1123,  31,  164,  1049,  749
,  710,  281,  47,  382,  36,  877,  785,  1126,  417,  487
,  1025,  334,  267,  334,  494,  396,  494,  724,  785,  1090
,  50,  659,  785,  874,  874,  758,  663,  829,  829,  869
,  1018,  396,  27,  381,  1040,  35,  1216,  1204,  1040,  190
,  584,  641,  66,  72,  51,  72,  1160,  450,  559,  1110
,  560,  323,  1015,  190,  1005,  1178,  593,  1097,  1002,  405
,  795,  564,  443,  1042,  1057,  427,  795,  777,  108,  246
,  958,  528,  528,  1070,  1077,  863,  90,  526,  863,  375
,  182,  1117,  1031,  1076,  445,  846,  139,  436,  1077,  901
,  528,  1076,  901,  788,  1030,  832,  80,  80,  1111,  95
,  405,  1110,  892,  259,  253,  881,  787,  880,  51,  1057
,  704,  908,  216,  165,  474,  319,  440,  547,  196,  475
,  1180,  421,  1166,  17,  217,  465,  927,  129,  875,  1111
,  744,  1089,  358,  901,  932,  517,  212,  404,  1115,  126
,  303,  1082,  360,  405,  214,  178,  962,  620,  375,  528
,  971,  1034,  1150,  1026,  573,  0,  581,  447,  543,  981
,  1095,  268,  47,  776,  279,  17,  236,  269,  349,  958
,  469,  897,  754,  1178,  1096,  1017,  1017,  112,  637,  1020
,  153,  1008,  374,  1017,  1070,  573,  246,  187,  123,  299
,  280,  128,  637,  576,  1093,  187,  693,  528,  38,  1117
,  338,  762,  1016,  651,  547,  1108,  1185,  321,  160,  1005
,  359,  647,  1024,  713,  865,  376,  622,  439,  291,  1126
,  239,  710,  1128,  360,  436,  1106,  283,  1188,  450,  318
,  449,  552,  221,  671,  901,  330,  1153,  1091,  540,  1206
,  616,  605,  1180,  1084,  404,  300,  1133,  464,  393,  1028
,  1051,  482,  1074,  1090,  3,  738,  867,  371,  239,  988
,  342,  1129,  701,  1033,  3,  306,  487,  1072,  183,  1035
,  48,  396,  381,  484,  241,  407,  678,  628,  1103,  1117
,  300,  691,  126,  859,  529,  636,  476,  1035,  1168,  1150
,  72,  366,  310,  302,  1077,  24,  921,  156,  6,  1020
,  934,  1228,  1017,  580,  514,  922,  1142,  388,  404,  275
,  378,  880,  1003,  885,  109,  528,  1102,  663,  846,  987
,  376,  1185,  467,  1205,  852,  541,  2,  1009,  174,  938
,  192,  192,  159,  1072,  754,  265,  1028,  723,  846,  503
,  1143,  695,  841,  1197,  669,  69,  219,  509,  1038,  129
,  944,  434,  449,  1105,  1005,  641,  851,  501,  422,  373
,  350,  216,  686,  1094,  1013,  147,  396,  388,  1022,  359
,  494,  1059,  835,  126,  767,  190,  526,  1082,  1150,  612
,  716,  492,  1115,  557,  478,  1,  1053,  765,  841,  912
,  6,  921,  579,  466,  183,  836,  117,  907,  1016,  876
,  301,  422,  1010,  903,  126,  356,  921,  408,  344,  922
,  774,  669,  359,  634,  208,  6,  961,  48,  14,  909
,  908,  205,  752,  932,  87,  408,  733,  554,  284,  319
,  1035,  693,  1143,  107,  1054,  581,  580,  522,  227,  42
,  1098,  608,  380,  1225,  718,  514,  1038,  404,  1191,  111
,  1221,  1035,  901,  282,  536,  1020,  362,  245,  92,  421
,  1086,  1054,  201,  748,  444,  774,  558,  184,  690,  428
,  678,  1120,  755,  246,  1142,  1090,  876,  6,  1064,  484
,  716,  285,  238,  193,  830,  722,  671,  818,  355,  361
,  407,  356,  946,  107,  74,  558,  669,  1035,  1077,  528
,  552,  1034,  403,  478,  1075,  1098,  801,  419,  1196,  669
,  1035,  104,  1093,  569,  644,  910,  1022,  1191,  643,  1003
,  783,  903,  413,  394,  1044,  1094,  640,  974,  982,  164
,  377,  1117,  497,  164,  1003,  566,  545,  320,  339,  970
,  1111,  750,  1114,  1117,  566,  789,  1114,  777,  339,  1003
,  1117,  1117,  970,  974,  386,  971,  872,  1131,  1003,  300
,  1016,  333,  724,  1091,  207,  1174,  490,  108,  753,  404
,  1180,  26,  447,  261,  41,  929,  455,  384,  1228,  469
,  484,  412,  930,  528,  20,  1019,  270,  1201,  742,  495
,  931,  985,  291,  741,  211,  657,  722,  16,  633,  463
,  206,  116,  154,  499,  553,  553,  559,  1046,  223,  520
,  288,  1083,  242,  1095,  254,  317,  1117,  216,  467,  853
,  246,  211,  1070,  480,  452,  648,  1119,  310,  3,  582
,  123,  849,  539,  750,  123,  874,  1067,  338,  1088,  663
,  1115,  73,  1019,  723,  189,  8,  1179,  1179,  1093,  714
,  404,  840,  476,  934,  412,  234,  427,  1115,  246,  719
,  972,  761,  242,  1094,  338,  216,  375,  33,  204,  454
,  1083,  1077,  34,  108,  229,  523,  484,  1099,  923,  123
,  452,  912,  874,  924,  970,  934,  1183,  830,  1019,  1067
,  301,  948,  1117,  1006,  511,  118,  761,  893,  882,  127
,  588,  431,  884,  1104,  211,  852,  633,  763,  533,  1201
,  1148,  1054,  258,  627,  236,  242,  242,  270,  763,  404
,  467,  48,  1104,  930,  1067,  361,  1070,  356,  520,  490
,  559,  384,  553,  528,  801,  20,  876,  808,  1199,  1199
,  869,  464,  377,  1090,  377,  496,  880,  221,  141,  274
,  37,  283,  1026,  492,  1020,  993,  912,  239,  1089,  317
,  317,  604,  1095,  402,  186,  947,  928,  280,  1082,  1078
,  352,  873,  966,  1091,  479,  408,  240,  489,  409,  589
,  530,  388,  1076,  753,  639,  276,  272,  492,  1214,  388
,  755,  39,  1093,  416,  940,  1138,  1020,  211,  860,  16
,  16,  530,  240,  876,  272,  687,  681,  638,  412,  923
,  357,  900,  818,  265,  1001,  1198,  283,  577,  810,  1075
,  230,  407,  1082,  428,  615,  1198,  674,  47,  1113,  986
,  262,  1018,  1115,  333,  656,  1186,  184,  638,  598,  752
,  772,  27,  632,  1207,  875,  849,  424,  318,  903,  1048
,  1004,  849,  736,  1083,  415,  881,  418,  515,  412,  1091
,  1179,  404,  715,  98,  1094,  1206,  1002,  989,  554,  1073
,  803,  418,  563,  740,  527,  921,  1004,  664,  1113,  637
,  441,  865,  207,  244,  610,  1113,  988,  1028,  787,  106
,  243,  554,  743,  996,  53,  423,  397,  48,  283,  431
,  506,  1073,  1098,  103,  867,  959,  1019,  1057,  596,  598
,  1117,  988,  15,  725,  1021,  1101,  126,  15,  577,  317
,  411,  839,  405,  1028,  6,  737,  731,  1115,  519,  1161
,  526,  205,  1074,  107,  654,  625,  763,  1018,  1028,  803
,  1020,  103,  418,  48,  851,  763,  666,  6,  577,  737
,  1098,  666,  1099,  577,  867,  892,  664,  563,  1207,  423
,  445,  471,  1125,  1206,  1208,  176,  919,  281,  37,  1206
,  1038,  604,  31,  407,  318,  681,  1064,  345,  563,  919
,  646,  882,  103,  1206,  280,  1064,  818,  669,  563,  33
,  671,  923,  334,  1155,  1114,  879,  7,  906,  995,  370
,  608,  195,  1209,  327,  1188,  219,  996,  1091,  33,  874
,  132,  867,  466,  1059,  876,  1111,  388,  1030,  312,  312
,  1130,  347,  1077,  1035,  408,  118,  814,  485,  59,  912
,  407,  407,  1095,  608,  475,  283,  598,  775,  349,  1115
,  775,  627,  96,  322,  775,  1019,  536,  874,  671,  1157
,  867,  1041,  485,  536,  386,  132,  33,  178,  235,  903
,  1068,  197,  880,  273,  863,  415,  415,  1195,  1005,  1223
,  1068,  235,  197,  1037,  858,  251,  286,  412,  118,  854
,  285,  107,  1109,  1109,  538,  1083,  287,  436,  291,  291
,  873,  1096,  128,  460,  657,  428,  1004,  667,  438,  725
,  93,  45,  437,  425,  785,  946,  425,  1016,  213,  873
,  875,  741,  404,  1042,  1159,  585,  243,  946,  268,  883
,  970,  573,  573,  1022,  93,  573,  440,  440,  883,  116
,  982,  849,  1093,  754,  1114,  918,  754,  1071,  405,  758
,  753,  91,  98,  785,  295,  1030,  16,  506,  197,  17
,  294,  465,  316,  1075,  1053,  410,  546,  189,  1121,  379
,  618,  9,  221,  491,  593,  1093,  1068,  223,  1181,  1025
,  421,  1175,  563,  244,  1115,  769,  273,  1030,  197,  448
,  1025,  455,  514,  504,  470,  131,  504,  753,  495,  172
,  1071,  295,  566,  445,  338,  221,  1175,  1036,  1074,  904
,  42,  1159,  320,  1002,  1130,  1084,  404,  872,  596,  761
,  506,  814,  1113,  555,  904,  1206,  1003,  180,  405,  555
,  1163,  1159,  785,  773,  514,  541,  203,  421,  1093,  1091
,  814,  546,  1114,  1121,  209,  103,  491,  1002,  563,  209
,  1075,  145,  145,  1185,  1068,  111,  312,  1227,  768,  440
,  313,  1016,  98,  783,  549,  406,  1092,  903,  17,  1034
,  1069,  426,  48,  876,  73,  889,  257,  873,  1020,  1003
,  1163,  935,  715,  697,  956,  530,  1181,  1187,  66,  1181
,  207,  1093,  889,  189,  1177,  873,  1021,  28,  135,  1163
,  189,  1003,  107,  1143,  339,  594,  1177,  608,  1003,  1015
,  281,  391,  588,  633,  339,  1143,  1163,  281,  1181,  257
,  1199,  48,  28,  198,  291,  741,  661,  63,  1048,  293
,  1082,  388,  1111,  1108,  406,  331,  724,  1198,  780,  48
,  150,  334,  1057,  559,  1018,  478,  1098,  206,  710,  211
,  615,  309,  282,  706,  268,  1032,  1051,  230,  1228,  478
,  959,  48,  7,  884,  457,  1104,  986,  1114,  90,  1031
,  436,  1026,  530,  510,  427,  14,  498,  538,  139,  103
,  901,  615,  108,  1018,  268,  331,  1042,  542,  559,  958
,  414,  1075,  959,  414,  679,  663,  451,  51,  1093,  755
,  679,  1093,  48,  1093,  876,  876,  876,  312,  214,  1096
,  281,  370,  127,  207,  1161,  937,  606,  1028,  377,  682
,  431,  607,  994,  826,  431,  1161,  763,  192,  763,  48
,  317,  58,  192,  763,  606,  994,  1068,  333,  193,  561
,  976,  396,  1181,  396,  1091,  832,  1046,  962,  1077,  1077
,  78,  52,  212,  59,  719,  1161,  1100,  129,  706,  1093
,  116,  47,  281,  1000,  1175,  168,  431,  189,  1069,  364
,  1079,  383,  574,  375,  1055,  431,  970,  504,  199,  700
,  1022,  107,  165,  504,  1115,  390,  283,  1068,  706,  1083
,  1002,  1175,  199,  116,  420,  393,  1043,  884,  48,  1093
,  196,  407,  809,  105,  931,  941,  941,  177,  1181,  1001
,  589,  949,  1182,  130,  1018,  1108,  904,  484,  51,  1181
,  118,  663,  676,  1043,  376,  453,  272,  383,  928,  905
,  1018,  694,  109,  152,  110,  1228,  1146,  1081,  683,  1175
,  697,  73,  379,  184,  530,  901,  189,  1091,  405,  718
,  1048,  1119,  657,  326,  281,  772,  141,  1210,  235,  1093
,  654,  1068,  876,  367,  532,  391,  471,  367,  884,  1081
,  396,  409,  393,  1208,  1057,  128,  1034,  688,  365,  248
,  466,  223,  948,  312,  1020,  757,  467,  246,  964,  1074
,  452,  90,  648,  1125,  1106,  496,  766,  1121,  1020,  946
,  351,  1093,  395,  37,  905,  789,  527,  1019,  1108,  388
,  1121,  670,  795,  1060,  758,  619,  267,  35,  174,  109
,  600,  407,  1048,  198,  752,  778,  135,  236,  429,  996
,  403,  946,  1000,  376,  1020,  108,  1003,  396,  246,  211
,  440,  82,  123,  37,  772,  81,  192,  329,  242,  648
,  1125,  1033,  1201,  216,  390,  806,  1045,  90,  768,  135
,  758,  1115,  1113,  619,  48,  1093,  453,  246,  1113,  6
,  772,  292,  1125,  525,  272,  494,  494,  795,  912,  152
,  452,  453,  1119,  528,  1094,  161,  761,  928,  389,  1125
,  868,  863,  633,  82,  81,  941,  964,  588,  329,  396
,  452,  694,  905,  574,  1005,  758,  1104,  780,  457,  752
,  1115,  1108,  37,  55,  1148,  530,  741,  494,  767,  192
,  235,  272,  130,  348,  755,  619,  430,  1018,  1030,  1093
,  141,  351,  222,  467,  1042,  1098,  16,  594,  1093,  542
,  600,  507,  542,  602,  235,  600,  686,  1074,  123,  603
,  507,  383,  1060,  105,  440,  1168,  1093,  532,  296,  1199
,  300,  1019,  412,  1054,  884,  814,  1023,  123,  1014,  425
,  412,  762,  403,  762,  1160,  752,  409,  406,  454,  405
,  290,  202,  765,  413,  423,  413,  561,  1160,  1023,  158
,  189,  379,  379,  379,  528,  262,  922,  50,  432,  851
,  379,  265,  879,  944,  77,  1150,  748,  17,  185,  811
,  984,  458,  475,  758,  1179,  498,  599,  839,  1079,  676
,  27,  115,  804,  25,  281,  722,  246,  1165,  123,  407
,  110,  1009,  445,  19,  1093,  881,  1193,  966,  225,  459
,  1168,  282,  709,  974,  473,  566,  764,  379,  34,  718
,  722,  927,  34,  206,  626,  117,  1070,  134,  619,  281
,  1191,  190,  99,  632,  660,  499,  282,  709,  27,  699
,  544,  325,  440,  987,  18,  984,  677,  437,  1204,  736
,  1164,  24,  658,  553,  413,  1104,  506,  671,  65,  1143
,  498,  876,  423,  1176,  313,  790,  890,  1126,  461,  736
,  1194,  874,  635,  127,  323,  1180,  772,  9,  481,  951
,  988,  1181,  563,  1013,  925,  1040,  647,  194,  420,  1175
,  406,  393,  3,  685,  182,  1174,  921,  1093,  960,  996
,  1025,  1018,  448,  963,  496,  1204,  568,  17,  351,  856
,  668,  441,  72,  513,  920,  413,  388,  197,  720,  862
,  539,  599,  23,  440,  4,  442,  154,  423,  637,  662
,  1027,  209,  839,  566,  239,  880,  214,  747,  1162,  406
,  937,  756,  700,  1089,  445,  1175,  323,  575,  78,  932
,  116,  422,  472,  977,  1076,  182,  437,  950,  759,  21
,  560,  339,  1181,  191,  102,  329,  1119,  413,  1113,  492
,  816,  1214,  1059,  613,  944,  95,  1090,  1079,  388,  8
,  1073,  1015,  143,  451,  434,  422,  393,  216,  1117,  1087
,  1150,  35,  507,  776,  102,  300,  555,  420,  317,  142
,  1159,  920,  66,  141,  179,  838,  1083,  197,  412,  907
,  298,  900,  836,  686,  934,  25,  183,  758,  1009,  764
,  1040,  96,  1153,  301,  1018,  249,  863,  881,  23,  1083
,  60,  929,  339,  63,  887,  1154,  329,  571,  554,  172
,  625,  1179,  1181,  473,  974,  624,  625,  1168,  102,  538
,  1098,  444,  735,  513,  122,  122,  828,  647,  901,  351
,  183,  1224,  662,  1199,  420,  191,  191,  116,  65,  536
,  282,  769,  65,  179,  1197,  748,  776,  662,  1040,  558
,  170,  925,  351,  769,  1193,  413,  292,  1106,  519,  560
,  851,  1143,  405,  195,  86,  778,  388,  774,  190,  724
,  68,  440,  908,  406,  1205,  1047,  74,  658,  403,  60
,  672,  300,  1179,  498,  423,  23,  908,  560,  804,  702
,  881,  662,  400,  553,  1134,  506,  1098,  801,  102,  170
,  1020,  863,  1134,  563,  929,  1220,  420,  445,  507,  645
,  1178,  748,  259,  878,  461,  1108,  289,  312,  264,  1177
,  320,  1038,  607,  205,  619,  436,  1114,  129,  14,  24
,  1057,  418,  531,  48,  108,  292,  834,  236,  420,  431
,  884,  766,  1176,  205,  280,  884,  532,  48,  1007,  1154
,  59,  267,  25,  506,  506,  226,  538,  377,  1040,  1172
,  1015,  426,  129,  282,  1159,  1205,  1159,  233,  901,  1043
,  233,  261,  1112,  873,  706,  1158,  592,  573,  715,  1060
,  429,  658,  1216,  549,  1092,  753,  1017,  407,  813,  192
,  436,  1180,  1141,  1068,  1057,  284,  500,  293,  351,  874
,  490,  1001,  1123,  11,  1144,  495,  869,  358,  106,  620
,  397,  1093,  1020,  1043,  930,  1134,  1045,  1101,  544,  155
,  598,  1226,  1164,  876,  1115,  593,  659,  108,  1188,  1029
,  111,  874,  392,  1059,  428,  428,  853,  1077,  848,  1037
,  1089,  1122,  393,  349,  996,  1188,  1020,  872,  70,  1019
,  396,  118,  750,  430,  1020,  778,  429,  334,  1181,  535
,  1135,  1059,  1025,  1122,  393,  492,  361,  883,  684,  9
,  1079,  620,  109,  6,  407,  1160,  633,  659,  34,  537
,  1027,  981,  1089,  528,  930,  1037,  6,  883,  1067,  1085
,  34,  490,  1020,  645,  848,  1120,  787,  1089,  311,  360
,  881,  87,  588,  93,  946,  1222,  396,  1121,  1110,  821
,  719,  281,  786,  900,  1174,  511,  1001,  111,  752,  602
,  552,  633,  1005,  627,  40,  1151,  1190,  884,  1189,  750
,  241,  404,  1052,  844,  1127,  790,  291,  95,  849,  1019
,  527,  1048,  77,  175,  857,  1163,  589,  230,  754,  884
,  296,  952,  504,  1079,  580,  614,  353,  35,  423,  221
,  298,  1084,  140,  696,  1192,  904,  26,  405,  317,  723
,  1000,  261,  1020,  1191,  1173,  541,  824,  596,  340,  1178
,  164,  881,  1141,  528,  413,  123,  762,  273,  1035,  476
,  741,  1180,  325,  1035,  411,  408,  316,  985,  545,  62
,  23,  630,  291,  752,  799,  816,  1170,  1025,  1111,  335
,  987,  1228,  671,  206,  96,  436,  413,  463,  639,  1192
,  550,  100,  1153,  122,  876,  1178,  1153,  52,  1160,  1181
,  552,  223,  559,  1121,  506,  884,  890,  752,  528,  1091
,  498,  1038,  1056,  1189,  461,  515,  1081,  360,  305,  301
,  1129,  563,  423,  367,  335,  938,  330,  1003,  490,  9
,  7,  443,  1204,  1181,  962,  835,  386,  438,  436,  1070
,  803,  1172,  195,  752,  767,  382,  335,  416,  1198,  921
,  281,  963,  445,  292,  533,  783,  960,  596,  28,  320
,  1207,  1178,  310,  952,  1035,  486,  856,  604,  1017,  526
,  921,  943,  1042,  496,  881,  260,  413,  545,  755,  609
,  753,  337,  30,  1209,  123,  1141,  405,  719,  223,  934
,  207,  1160,  842,  154,  523,  752,  463,  1166,  327,  269
,  270,  340,  1092,  533,  1179,  1200,  1070,  437,  418,  228
,  761,  569,  986,  1086,  233,  1172,  146,  155,  1150,  1079
,  273,  1039,  414,  140,  379,  532,  523,  641,  596,  1062
,  1172,  405,  1089,  140,  166,  405,  452,  782,  1099,  554
,  738,  290,  507,  1113,  120,  572,  439,  1042,  510,  814
,  440,  1172,  29,  1083,  293,  267,  1153,  759,  580,  920
,  1042,  814,  172,  549,  795,  925,  752,  298,  703,  900
,  317,  154,  762,  96,  383,  296,  297,  455,  59,  1189
,  761,  340,  752,  377,  416,  87,  427,  1198,  1121,  164
,  258,  533,  554,  138,  934,  52,  881,  1161,  625,  1081
,  1020,  367,  763,  1098,  767,  749,  884,  382,  1223,  1121
,  292,  766,  647,  767,  985,  438,  123,  445,  404,  1034
,  986,  1189,  367,  139,  560,  1117,  908,  930,  1021,  122
,  774,  1075,  519,  194,  68,  484,  778,  413,  763,  542
,  96,  602,  938,  927,  59,  671,  414,  1205,  335,  560
,  572,  423,  228,  1117,  528,  139,  1189,  559,  528,  120
,  552,  439,  545,  1098,  506,  790,  569,  528,  563,  507
,  545,  761,  163,  385,  1043,  1113,  692,  1115,  1020,  752
,  752,  773,  486,  846,  1043,  1039,  761,  300,  932,  692
,  863,  141,  1113,  385,  1180,  1177,  162,  73,  1018,  753
,  992,  918,  528,  333,  188,  902,  412,  627,  627,  168
,  1078,  949,  189,  852,  1069,  881,  81,  732,  1124,  532
,  1179,  81,  190,  405,  1124,  60,  852,  1093,  190,  532
,  60,  412,  881,  692,  233,  1094,  844,  464,  211,  395
,  395,  319,  1093,  692,  1017,  632,  597,  228,  1115,  47
,  48,  48,  723,  48,  103,  592,  1158,  631,  356,  783
,  931,  174,  832,  881,  414,  832,  108,  750,  562,  1158
,  569,  786,  876,  204,  618,  589,  755,  734,  638,  196
,  1027,  145,  269,  281,  221,  777,  755,  1094,  347,  1080
,  7,  1073,  466,  777,  1072,  192,  574,  778,  1122,  1122
,  895,  832,  1106,  983,  260,  958,  1178,  783,  170,  396
,  351,  98,  995,  260,  1020,  755,  851,  351,  1016,  1069
,  903,  819,  313,  415,  127,  1016,  933,  608,  319,  998
,  928,  405,  51,  1009,  1049,  445,  755,  270,  776,  1091
,  1015,  1117,  354,  867,  118,  238,  379,  752,  633,  627
,  925,  610,  130,  47,  844,  715,  315,  596,  273,  694
,  528,  566,  84,  1003,  379,  627,  598,  884,  439,  985
,  242,  360,  268,  1109,  1181,  1165,  318,  1158,  1075,  490
,  1042,  783,  790,  66,  608,  517,  370,  291,  255,  593
,  903,  260,  127,  673,  545,  712,  65,  755,  657,  1192
,  521,  1062,  704,  619,  928,  1078,  1106,  44,  1064,  552
,  559,  571,  1042,  742,  1143,  429,  423,  394,  1094,  1079
,  539,  407,  828,  1022,  1189,  417,  571,  223,  426,  1004
,  1042,  370,  1057,  938,  251,  1185,  820,  1068,  1049,  330
,  386,  401,  988,  757,  701,  549,  408,  760,  415,  418
,  1172,  1205,  90,  484,  407,  549,  398,  378,  678,  1068
,  1170,  448,  28,  1205,  1020,  388,  1093,  750,  358,  512
,  527,  281,  1017,  1115,  346,  428,  409,  597,  970,  669
,  429,  1035,  863,  662,  1106,  1028,  912,  441,  91,  946
,  937,  516,  504,  530,  1003,  1013,  388,  205,  825,  414
,  1163,  841,  281,  329,  891,  1071,  1089,  349,  360,  533
,  1204,  211,  1206,  1020,  1036,  753,  541,  935,  881,  752
,  649,  938,  165,  521,  266,  904,  725,  192,  1112,  293
,  431,  566,  1095,  174,  383,  865,  156,  1116,  504,  399
,  1074,  760,  947,  614,  777,  1116,  561,  1208,  228,  414
,  610,  1113,  867,  868,  388,  1191,  413,  1113,  786,  230
,  1150,  66,  1015,  1013,  1002,  1006,  1042,  90,  1005,  295
,  1062,  465,  1109,  614,  398,  701,  596,  166,  973,  610
,  717,  412,  377,  1031,  1160,  1172,  390,  619,  1106,  223
,  782,  1074,  933,  1117,  642,  994,  873,  494,  414,  1057
,  290,  934,  1117,  1203,  466,  548,  315,  620,  1093,  750
,  528,  1020,  1006,  912,  1172,  907,  1053,  814,  399,  659
,  923,  873,  820,  139,  705,  84,  617,  209,  1206,  205
,  1046,  282,  381,  1207,  937,  942,  48,  336,  1181,  1077
,  863,  587,  1099,  574,  508,  563,  59,  929,  379,  1181
,  868,  204,  560,  378,  376,  336,  587,  1113,  730,  752
,  561,  556,  526,  1076,  87,  694,  627,  351,  530,  507
,  1060,  1090,  588,  1208,  590,  571,  884,  1163,  1161,  388
,  414,  1081,  415,  1100,  1099,  1035,  532,  1003,  742,  423
,  702,  759,  759,  561,  1023,  1069,  390,  825,  537,  930
,  111,  1068,  494,  859,  1189,  47,  849,  103,  962,  1003
,  841,  123,  418,  516,  116,  292,  901,  884,  719,  414
,  506,  619,  1141,  1143,  1115,  527,  1064,  484,  211,  16
,  386,  103,  930,  404,  1205,  530,  678,  915,  505,  59
,  1021,  673,  602,  48,  406,  356,  818,  938,  403,  508
,  448,  749,  1205,  1003,  59,  414,  571,  574,  1099,  228
,  1042,  867,  549,  751,  59,  559,  351,  1099,  528,  1035
,  1099,  1042,  552,  505,  606,  532,  272,  1121,  506,  273
,  863,  329,  358,  828,  526,  929,  358,  20,  994,  563
,  402,  903,  617,  201,  393,  545,  1142,  435,  1205,  1129
,  1129,  83,  1079,  335,  1007,  559,  153,  1075,  112,  793
,  459,  238,  1181,  1004,  765,  1166,  1062,  440,  932,  712
,  433,  927,  62,  1192,  1153,  210,  1003,  874,  532,  129
,  376,  900,  508,  958,  539,  1081,  1016,  369,  516,  1190
,  1074,  461,  258,  856,  1089,  396,  936,  428,  807,  1020
,  777,  995,  718,  273,  1074,  351,  1019,  349,  388,  600
,  438,  937,  37,  270,  495,  1017,  418,  1204,  1077,  1077
,  798,  233,  1026,  532,  1059,  390,  412,  1004,  684,  1074
,  1115,  846,  781,  596,  388,  1057,  1166,  1002,  258,  1079
,  1191,  31,  377,  49,  980,  849,  1020,  1050,  1067,  1099
,  814,  765,  548,  1020,  882,  1093,  1125,  14,  807,  588
,  852,  1020,  129,  1089,  798,  1077,  201,  238,  536,  541
,  856,  258,  1077,  936,  600,  1099,  1115,  1142,  83,  918
,  395,  1190,  1042,  396,  818,  1029,  1067,  428,  938,  1085
,  34,  900,  559,  508,  445,  171,  1165,  696,  1175,  1117
,  6,  445,  283,  1087,  20,  215,  1087,  1083,  893,  251
,  703,  763,  729,  26,  700,  228,  216,  1110,  228,  1071
,  675,  739,  629,  923,  632,  514,  592,  633,  1019,  414
,  319,  869,  206,  758,  941,  1020,  758,  1018,  320,  1020
,  526,  404,  228,  440,  759,  726,  462,  571,  526,  417
,  228,  1020,  791,  259,  260,  783,  9,  1199,  331,  579
,  1109,  1199,  1124,  488,  676,  205,  37,  710,  1025,  377
,  268,  316,  437,  671,  364,  420,  814,  880,  228,  1025
,  873,  484,  1175,  1115,  919,  1113,  48,  443,  526,  1025
,  1095,  913,  510,  37,  528,  1029,  657,  539,  340,  606
,  106,  1090,  1175,  603,  76,  169,  860,  569,  377,  1004
,  1045,  1189,  591,  1005,  1030,  647,  373,  1109,  1109,  596
,  96,  919,  381,  1117,  1115,  873,  431,  416,  1161,  14
,  445,  536,  228,  484,  1029,  1042,  924,  1067,  671,  403
,  539,  331,  880,  925,  1030,  606,  385,  569,  1060,  1060
,  574,  1115,  999,  217,  404,  435,  579,  618,  269,  1121
,  445,  995,  596,  1004,  386,  1030,  545,  189,  211,  1022
,  65,  745,  463,  408,  618,  849,  1172,  445,  256,  552
,  313,  571,  1189,  251,  1083,  367,  333,  25,  715,  393
,  1030,  783,  510,  527,  549,  1071,  528,  531,  922,  437
,  117,  1205,  378,  753,  495,  753,  996,  165,  328,  1076
,  541,  774,  723,  698,  256,  781,  398,  594,  1004,  1025
,  1119,  648,  377,  1098,  1113,  824,  841,  922,  1083,  1099
,  579,  934,  510,  333,  1083,  6,  427,  173,  164,  526
,  1060,  530,  1161,  1098,  561,  541,  390,  749,  430,  404
,  6,  48,  83,  786,  386,  1009,  1022,  1060,  781,  552
,  1135,  1098,  1031,  1135,  321,  216,  379,  731,  27,  800
,  990,  758,  1012,  692,  545,  741,  161,  126,  195,  603
,  73,  1172,  692,  602,  44,  1149,  725,  1012,  291,  189
,  868,  948,  869,  104,  869,  910,  1107,  888,  282,  1106
,  43,  671,  948,  1109,  410,  865,  211,  641,  211,  217
,  382,  791,  1129,  48,  109,  260,  948,  425,  791,  1005
,  704,  549,  40,  1173,  1057,  632,  48,  575,  753,  257
,  382,  1093,  860,  135,  193,  404,  996,  404,  975,  415
,  135,  216,  724,  881,  1091,  64,  217,  422,  536,  300
,  436,  851,  689,  528,  1079,  120,  1109,  17,  425,  1093
,  528,  149,  273,  1192,  712,  723,  291,  463,  160,  191
,  1173,  942,  437,  405,  408,  1060,  1153,  63,  1177,  1104
,  431,  790,  1091,  1080,  1181,  363,  1072,  226,  431,  964
,  724,  913,  528,  1181,  180,  1019,  844,  514,  388,  1028
,  930,  268,  578,  541,  126,  48,  48,  320,  1004,  1112
,  174,  1190,  192,  1115,  373,  273,  502,  1079,  1114,  388
,  410,  1093,  556,  840,  129,  1093,  1006,  405,  149,  25
,  549,  180,  880,  689,  184,  57,  929,  52,  570,  134
,  1163,  1157,  794,  556,  627,  1096,  1100,  390,  536,  552
,  514,  1028,  192,  4,  25,  1115,  1093,  724,  528,  211
,  505,  57,  126,  1080,  1061,  423,  1175,  505,  209,  1029
,  1100,  1096,  786,  1104,  929,  209,  334,  201,  253,  22
,  23,  1142,  200,  422,  390,  333,  297,  420,  4,  358
,  996,  1020,  4,  743,  723,  712,  1188,  447,  175,  447
,  1188,  619,  1113,  35,  1182,  717,  1099,  1093,  360,  12
,  1159,  1075,  412,  360,  491,  290,  198,  703,  872,  198
,  1159,  602,  428,  412,  703,  329,  559,  195,  633,  217
,  1054,  589,  1179,  1031,  237,  704,  238,  871,  610,  614
,  190,  596,  456,  473,  1091,  871,  1172,  609,  1116,  1208
,  1152,  1062,  915,  605,  126,  490,  443,  629,  954,  1076
,  1184,  1171,  1175,  921,  207,  497,  505,  413,  1071,  429
,  1175,  505,  896,  915,  227,  725,  633,  659,  1093,  423
,  78,  229,  492,  297,  824,  594,  613,  136,  605,  117
,  463,  908,  1024,  620,  586,  586,  732,  122,  602,  734
,  767,  1191,  203,  898,  537,  456,  962,  541,  1158,  413
,  319,  786,  602,  445,  552,  141,  1191,  592,  426,  875
,  1092,  1178,  867,  439,  420,  180,  232,  5,  420,  874
,  404,  291,  1020,  258,  490,  195,  579,  844,  380,  755
,  455,  1073,  722,  1075,  1195,  114,  238,  1077,  273,  255
,  1152,  437,  985,  206,  1157,  1172,  281,  500,  49,  718
,  712,  745,  65,  865,  1127,  6,  528,  552,  962,  528
,  140,  1189,  333,  647,  303,  1046,  223,  1020,  900,  1025
,  766,  1035,  1025,  114,  1015,  549,  1101,  589,  795,  1077
,  413,  719,  470,  753,  219,  212,  561,  6,  918,  35
,  235,  996,  210,  37,  755,  119,  216,  1186,  423,  50
,  48,  900,  195,  721,  413,  207,  932,  96,  1062,  795
,  579,  662,  161,  30,  836,  520,  179,  703,  1168,  463
,  336,  1195,  456,  119,  755,  625,  780,  404,  786,  203
,  541,  390,  766,  418,  236,  140,  415,  6,  602,  75
,  490,  528,  528,  258,  552,  66,  876,  876,  527,  863
,  903,  753,  1027,  753,  753,  1180,  1111,  281,  608,  1217
,  1178,  1228,  785,  379,  1192,  866,  918,  161,  606,  1032
,  951,  733,  407,  1172,  197,  403,  753,  561,  62,  428
,  561,  103,  1023,  403,  1172,  281,  1205,  1115,  1022,  103
,  527,  658,  197,  800,  1114,  1113,  526,  774,  360,  969
,  1053,  901,  969,  292,  1027,  62,  782,  1184,  463,  614
,  47,  608,  1215,  627,  125,  774,  1078,  1181,  882,  1207
,  404,  122,  422,  1091,  396,  1020,  510,  280,  896,  573
,  292,  123,  856,  896,  809,  24,  1181,  523,  463,  62
,  135,  910,  1183,  122,  1008,  407,  1173,  198,  411,  404
,  298,  319,  633,  561,  910,  404,  1100,  841,  918,  678
,  841,  396,  1008,  403,  800,  1064,  434,  781,  1020,  781
,  470,  145,  1202,  969,  772,  1156,  50,  1084,  769,  1083
,  1181,  953,  421,  149,  433,  171,  1013,  476,  463,  491
,  226,  1097,  1013,  988,  1113,  440,  781,  1083,  1114,  440
,  491,  552,  171,  769,  226,  772,  528,  884,  1160,  431
,  431,  1161,  448,  962,  905,  423,  231,  431,  1190,  1190
,  1113,  291,  229,  404,  17,  405,  1166,  920,  379,  1038
,  47,  413,  869,  205,  126,  528,  952,  903,  281,  41
,  184,  1207,  207,  1143,  316,  408,  744,  412,  552,  49
,  1029,  47,  781,  202,  426,  790,  920,  254,  487,  1192
,  963,  184,  90,  475,  48,  847,  1175,  1123,  696,  413
,  876,  1037,  856,  1075,  484,  135,  296,  758,  413,  700
,  48,  303,  412,  318,  1175,  780,  66,  404,  914,  470
,  759,  154,  328,  1116,  1143,  772,  987,  569,  190,  1035
,  826,  414,  1031,  1172,  1192,  423,  390,  260,  1197,  726
,  1190,  772,  373,  494,  555,  297,  267,  826,  315,  1037
,  171,  229,  528,  48,  847,  127,  506,  526,  48,  719
,  224,  617,  1143,  169,  334,  912,  555,  561,  921,  233
,  190,  211,  413,  494,  201,  390,  1132,  1035,  1075,  68
,  758,  530,  73,  1188,  505,  506,  135,  405,  942,  987
,  505,  552,  506,  758,  1121,  49,  565,  526,  569,  1115
,  607,  205,  521,  1027,  1207,  271,  17,  528,  745,  167
,  1158,  954,  528,  1020,  912,  1206,  1121,  1185,  272,  533
,  533,  83,  429,  1121,  174,  541,  1211,  429,  833,  816
,  373,  1056,  377,  1132,  161,  526,  297,  934,  784,  86
,  606,  833,  272,  1139,  457,  625,  533,  417,  686,  974
,  528,  205,  954,  608,  1023,  434,  407,  1188,  1120,  370
,  1112,  360,  995,  810,  1008,  1007,  637,  676,  881,  156
,  722,  844,  1180,  405,  269,  1123,  912,  263,  922,  427
,  1207,  1151,  520,  1023,  281,  1042,  865,  859,  293,  281
,  189,  141,  1182,  1028,  1217,  27,  368,  423,  445,  937
,  420,  571,  1062,  304,  814,  1057,  216,  963,  901,  417
,  1179,  443,  29,  1035,  310,  944,  915,  496,  429,  1211
,  241,  574,  135,  791,  753,  880,  1003,  780,  996,  294
,  1000,  1201,  78,  566,  550,  754,  1160,  159,  545,  609
,  336,  1206,  427,  265,  1057,  1031,  412,  466,  1030,  755
,  233,  207,  618,  1117,  901,  49,  387,  610,  1004,  315
,  614,  532,  51,  944,  1181,  1099,  428,  1093,  1201,  1188
,  412,  937,  281,  1173,  298,  820,  1030,  274,  526,  921
,  1076,  1211,  519,  761,  588,  1179,  573,  732,  606,  1210
,  404,  849,  258,  42,  838,  629,  1109,  764,  1148,  1178
,  851,  257,  536,  805,  1053,  396,  870,  396,  1023,  413
,  386,  1141,  420,  1093,  407,  59,  760,  1219,  1040,  490
,  1057,  519,  103,  1098,  77,  1027,  1219,  198,  507,  420
,  434,  1112,  370,  1188,  1027,  300,  1120,  405,  995,  490
,  407,  810,  1004,  1123,  156,  722,  844,  294,  637,  1211
,  566,  269,  1180,  1007,  263,  676,  881,  1030,  293,  1042
,  281,  532,  1217,  865,  1023,  1178,  1182,  1188,  27,  281
,  141,  859,  1093,  429,  189,  29,  814,  423,  478,  805
,  353,  396,  304,  1062,  417,  571,  445,  420,  963,  310
,  1035,  443,  1053,  916,  937,  407,  944,  404,  1057,  545
,  1057,  754,  265,  159,  854,  336,  870,  1003,  609,  880
,  42,  135,  550,  791,  1209,  1160,  996,  574,  1201,  1206
,  466,  1031,  412,  610,  507,  944,  614,  404,  396,  901
,  241,  233,  51,  315,  1201,  387,  207,  573,  49,  618
,  1117,  428,  283,  820,  1173,  274,  298,  103,  526,  1093
,  412,  59,  732,  588,  519,  1098,  921,  629,  838,  1040
,  536,  851,  1148,  415,  760,  766,  386,  420,  1219,  279
,  294,  793,  65,  1098,  780,  1026,  930,  1098,  329,  1000
,  1000,  350,  569,  281,  254,  319,  294,  20,  1076,  1166
,  1222,  1181,  254,  507,  883,  723,  580,  20,  526,  1148
,  404,  569,  723,  404,  1079,  616,  762,  597,  297,  545
,  204,  1051,  764,  1030,  797,  469,  921,  1030,  1093,  423
,  933,  1020,  849,  519,  309,  105,  1114,  1093,  1010,  129
,  1093,  1093,  545,  1021,  1032,  1020,  769,  1155,  174,  267
,  1192,  413,  726,  360,  351,  14,  1093,  767,  257,  1093
,  1085,  515,  461,  594,  1169,  753,  216,  250,  886,  639
,  231,  520,  1207,  309,  113,  358,  1123,  696,  903,  400
,  516,  933,  693,  554,  680,  416,  707,  554,  627,  251
,  217,  1086,  183,  905,  128,  190,  310,  669,  190,  545
,  536,  552,  1179,  671,  338,  530,  872,  739,  440,  1007
,  494,  164,  530,  164,  14,  869,  905,  494,  669,  1179
,  671,  958,  552,  1115,  1115,  912,  1093,  912,  903,  1166
,  817,  521,  404,  89,  389,  1035,  1187,  230,  294,  814
,  291,  1015,  107,  319,  1178,  280,  266,  412,  262,  1202
,  637,  10,  467,  312,  1115,  1083,  760,  268,  430,  928
,  868,  1183,  1163,  1040,  868,  1005,  1188,  191,  37,  321
,  926,  708,  1172,  1228,  713,  410,  872,  1178,  31,  377
,  1097,  1054,  552,  223,  450,  559,  431,  681,  1074,  481
,  1091,  330,  346,  300,  223,  418,  1049,  9,  727,  655
,  1178,  1040,  174,  584,  584,  406,  484,  829,  1136,  753
,  648,  607,  678,  563,  66,  996,  420,  431,  181,  156
,  868,  1051,  984,  709,  749,  226,  984,  667,  569,  531
,  1163,  723,  949,  429,  502,  1089,  1074,  868,  282,  282
,  266,  762,  997,  1209,  219,  166,  569,  693,  1045,  648
,  884,  642,  1183,  246,  830,  1082,  414,  420,  1113,  107
,  283,  1030,  659,  610,  991,  942,  979,  706,  573,  301
,  66,  297,  60,  52,  280,  934,  625,  1020,  418,  1181
,  543,  719,  659,  144,  851,  1098,  849,  191,  484,  678
,  982,  530,  48,  1104,  1093,  531,  840,  319,  753,  60
,  502,  559,  1138,  563,  1126,  118,  1015,  1136,  541,  1208
,  669,  137,  1181,  1181,  927,  1172,  436,  1113,  1084,  1113
,  130,  1023,  436,  1113,  1114,  1045,  439,  436,  861,  863
,  876,  881,  949,  751,  147,  898,  1018,  1185,  146,  849
,  1092,  26,  353,  263,  25,  47,  1182,  414,  84,  1190
,  1143,  242,  66,  1028,  302,  146,  410,  559,  1020,  856
,  960,  1004,  603,  879,  907,  84,  87,  130,  1092,  414
,  602,  559,  307,  533,  412,  412,  841,  1077,  281,  1077
,  88,  1093,  418,  6,  638,  423,  995,  607,  758,  1115
,  857,  1049,  230,  754,  589,  1031,  48,  281,  1017,  1178
,  849,  761,  278,  473,  425,  559,  404,  774,  753,  1117
,  269,  17,  824,  1043,  407,  380,  261,  1019,  1180,  1123
,  774,  139,  594,  1071,  268,  164,  51,  1004,  528,  246
,  1030,  107,  84,  1192,  910,  1119,  799,  545,  926,  952
,  613,  779,  463,  633,  31,  316,  618,  1092,  787,  735
,  826,  477,  1192,  849,  40,  1098,  437,  291,  741,  281
,  1205,  594,  260,  770,  592,  592,  18,  1207,  627,  127
,  429,  552,  666,  1099,  781,  620,  1097,  308,  761,  413
,  161,  589,  96,  418,  281,  1189,  1206,  415,  394,  1094
,  96,  814,  818,  130,  962,  1068,  790,  429,  1048,  88
,  429,  809,  414,  944,  389,  528,  409,  803,  48,  767
,  396,  407,  195,  814,  397,  1046,  571,  1099,  759,  428
,  919,  1094,  583,  370,  1188,  1085,  360,  46,  205,  970
,  915,  528,  749,  528,  1198,  844,  439,  596,  429,  865
,  959,  1109,  328,  1110,  409,  1030,  533,  281,  244,  627
,  455,  504,  530,  874,  1013,  1027,  403,  1109,  1099,  1098
,  156,  590,  163,  996,  429,  412,  318,  438,  447,  360
,  281,  106,  904,  79,  18,  972,  65,  351,  1020,  749
,  195,  381,  318,  545,  265,  7,  1074,  1215,  881,  753
,  174,  938,  48,  107,  504,  752,  602,  741,  1004,  192
,  386,  639,  955,  569,  1099,  1099,  1099,  1035,  829,  997
,  1059,  1013,  1113,  246,  571,  33,  1089,  273,  370,  1192
,  1031,  810,  302,  756,  749,  222,  1004,  695,  377,  1138
,  408,  1085,  164,  1002,  492,  959,  397,  1022,  755,  207
,  104,  452,  494,  416,  554,  701,  907,  874,  512,  602
,  914,  528,  30,  483,  749,  900,  1175,  412,  405,  84
,  248,  355,  919,  1172,  1057,  1021,  814,  1011,  290,  873
,  820,  921,  37,  48,  506,  407,  526,  1115,  1099,  627
,  719,  530,  164,  1022,  537,  48,  1058,  545,  912,  617
,  588,  66,  1170,  1005,  554,  169,  79,  416,  164,  666
,  660,  881,  1097,  763,  224,  531,  543,  475,  5,  48
,  1068,  257,  104,  1069,  418,  823,  767,  1123,  1109,  786
,  803,  396,  1222,  494,  822,  445,  195,  1017,  1035,  753
,  1125,  1115,  1012,  405,  372,  520,  66,  355,  1002,  396
,  407,  1031,  1093,  415,  763,  1063,  48,  532,  1042,  414
,  369,  829,  1043,  908,  883,  1067,  818,  927,  407,  298
,  405,  506,  428,  85,  614,  1029,  693,  526,  1093,  942
,  1085,  257,  908,  528,  1189,  5,  543,  1141,  403,  753
,  367,  559,  910,  1125,  737,  625,  669,  68,  1029,  532
,  552,  786,  258,  506,  1160,  526,  606,  569,  378,  378
,  560,  689,  574,  759,  141,  1054,  1054,  560,  1113,  358
,  339,  491,  131,  783,  406,  873,  370,  395,  602,  303
,  915,  1024,  101,  874,  1092,  579,  1007,  824,  30,  723
,  1096,  81,  1071,  356,  312,  1141,  425,  281,  126,  225
,  1029,  782,  1109,  1153,  1111,  466,  348,  798,  1192,  318
,  785,  861,  545,  319,  192,  528,  122,  785,  629,  394
,  1079,  988,  1189,  498,  418,  343,  781,  1181,  586,  1168
,  409,  647,  901,  753,  1035,  1106,  409,  980,  244,  883
,  273,  868,  1029,  1168,  1017,  281,  526,  139,  1075,  959
,  980,  1013,  1178,  265,  608,  753,  502,  603,  762,  1020
,  952,  1115,  723,  1093,  790,  777,  340,  994,  1099,  338
,  103,  463,  1039,  1113,  874,  390,  49,  281,  1109,  1109
,  629,  1024,  873,  283,  492,  377,  216,  321,  642,  554
,  155,  814,  510,  706,  901,  1020,  1117,  907,  814,  774
,  934,  579,  620,  1099,  587,  876,  87,  126,  14,  934
,  730,  569,  554,  1182,  889,  1179,  578,  338,  592,  1020
,  1161,  590,  1034,  719,  703,  406,  390,  396,  103,  851
,  803,  131,  122,  1042,  1092,  103,  570,  1099,  101,  530
,  1039,  753,  814,  603,  356,  818,  403,  617,  502,  526
,  157,  528,  319,  441,  81,  230,  586,  786,  1066,  688
,  1044,  617,  1046,  1076,  884,  1028,  422,  1071,  1005,  130
,  367,  786,  1090,  1090,  72,  53,  97,  849,  120,  336
,  887,  637,  1182,  753,  810,  773,  426,  1117,  598,  15
,  666,  408,  189,  710,  931,  1053,  991,  336,  704,  594
,  37,  1021,  281,  756,  300,  77,  539,  1198,  193,  468
,  666,  123,  527,  747,  1093,  1115,  783,  797,  72,  1198
,  844,  527,  530,  531,  478,  413,  48,  135,  239,  53
,  855,  714,  570,  340,  1020,  1181,  437,  323,  283,  50
,  361,  31,  33,  1113,  37,  1191,  573,  923,  183,  820
,  980,  128,  758,  478,  530,  506,  1169,  573,  1042,  1005
,  764,  1031,  15,  532,  48,  426,  193,  506,  818,  991
,  23,  120,  1021,  704,  1020,  1085,  930,  283,  414,  333
,  608,  876,  1158,  954,  1021,  1113,  773,  407,  317,  428
,  788,  445,  507,  205,  327,  414,  327,  333,  608,  876
,  102,  507,  445,  407,  1021,  205,  1113,  317,  428,  788
,  420,  426,  445,  318,  1206,  852,  424,  312,  141,  912
,  1181,  377,  852,  1181,  141,  445,  1075,  219,  283,  369
,  407,  1069,  370,  939,  1054,  423,  1091,  1069,  851,  755
,  984,  407,  244,  1073,  906,  1043,  445,  650,  263,  863
,  1056,  912,  359,  1173,  1192,  1177,  1206,  319,  206,  528
,  440,  1153,  1091,  1166,  741,  48,  785,  1217,  161,  1106
,  1056,  1068,  1093,  876,  418,  873,  98,  317,  334,  790
,  423,  382,  288,  1032,  865,  1158,  246,  393,  323,  520
,  1189,  487,  479,  1115,  942,  1181,  810,  488,  1020,  876
,  192,  1111,  769,  1114,  123,  425,  1016,  1019,  299,  906
,  750,  396,  899,  864,  466,  918,  267,  1093,  952,  104
,  1202,  930,  1004,  779,  1175,  1212,  1205,  535,  567,  867
,  1113,  216,  727,  399,  246,  207,  1040,  414,  1115,  1206
,  396,  7,  118,  276,  1189,  1077,  1059,  686,  629,  1089
,  1005,  942,  1212,  413,  391,  606,  608,  689,  912,  30
,  758,  876,  416,  1042,  1083,  779,  625,  1168,  623,  692
,  427,  586,  381,  1020,  1177,  445,  404,  1147,  876,  767
,  930,  750,  1142,  430,  1158,  725,  1093,  1093,  760,  379
,  1115,  228,  51,  135,  103,  802,  506,  120,  1135,  194
,  1077,  1075,  407,  219,  283,  810,  404,  423,  372,  939
,  802,  851,  755,  1069,  1093,  1069,  407,  416,  396,  692
,  440,  1073,  650,  1056,  244,  567,  906,  275,  863,  263
,  445,  1177,  319,  359,  741,  1217,  874,  1153,  912,  1173
,  206,  1185,  161,  785,  1166,  1093,  1091,  487,  520,  876
,  323,  873,  423,  393,  123,  1189,  865,  382,  192,  317
,  790,  334,  1068,  1093,  1177,  288,  1032,  98,  399,  1056
,  425,  1016,  1114,  769,  1019,  299,  1111,  396,  488,  899
,  906,  247,  779,  1189,  1212,  686,  228,  1205,  267,  466
,  1004,  1113,  894,  867,  214,  104,  535,  1202,  918,  930
,  1093,  629,  118,  216,  391,  414,  1040,  1066,  1089,  1005
,  246,  1115,  1059,  103,  1206,  7,  1077,  207,  606,  728
,  625,  194,  912,  1042,  1083,  30,  876,  758,  608,  427
,  588,  1168,  413,  623,  930,  1147,  767,  506,  750,  445
,  1077,  760,  1158,  120,  319,  1020,  403,  226,  415,  754
,  128,  994,  884,  273,  1077,  875,  982,  1034,  388,  356
,  1115,  1189,  408,  59,  1181,  34,  100,  212,  1051,  360
,  627,  594,  526,  591,  723,  627,  37,  1172,  283,  77
,  314,  737,  403,  260,  929,  329,  1143,  1191,  876,  1206
,  252,  335,  50,  583,  189,  490,  268,  955,  1091,  594
,  361,  48,  561,  543,  396,  288,  1206,  410,  1145,  1174
,  860,  59,  783,  505,  903,  853,  714,  309,  1028,  584
,  414,  283,  932,  1179,  1163,  229,  505,  872,  1197,  283
,  317,  831,  1143,  1181,  1201,  1149,  1135,  851,  1099,  428
,  1136,  882,  1077,  293,  37,  1172,  283,  314,  77,  1143
,  1028,  24,  1163,  403,  1181,  260,  929,  737,  50,  317
,  1192,  329,  252,  414,  39,  876,  955,  335,  490,  189
,  594,  268,  361,  1091,  1145,  1181,  410,  396,  1206,  543
,  561,  1136,  1206,  288,  428,  783,  1174,  505,  860,  283
,  229,  404,  882,  853,  163,  309,  714,  191,  505,  1201
,  283,  1197,  831,  1143,  1077,  1135,  1149,  851,  1099,  293
,  129,  863,  642,  361,  1169,  1213,  434,  283,  1166,  292
,  754,  120,  437,  110,  1121,  785,  1206,  539,  292,  1166
,  936,  788,  785,  1134,  1134,  1216,  695,  34,  237,  280
,  413,  1180,  923,  1121,  765,  927,  18,  215,  985,  408
,  711,  1179,  280,  849,  67,  440,  528,  305,  404,  1029
,  418,  1189,  481,  335,  781,  493,  561,  954,  414,  766
,  48,  1027,  242,  404,  438,  407,  1064,  535,  1106,  135
,  925,  414,  158,  383,  440,  127,  790,  943,  66,  78
,  1209,  721,  1181,  210,  1179,  240,  1106,  1183,  144,  414
,  439,  216,  727,  816,  944,  413,  197,  179,  1020,  925
,  762,  669,  703,  48,  169,  404,  586,  1209,  44,  56
,  201,  94,  258,  139,  236,  169,  445,  766,  750,  170
,  1142,  925,  1190,  139,  237,  135,  404,  1121,  543,  539
,  1179,  528,  1179,  103,  1027,  1218,  1042,  669,  170,  1218
,  543,  865,  312,  785,  241,  935,  785,  437,  1073,  334
,  447,  1005,  1121,  1059,  810,  246,  821,  1173,  1186,  1180
,  1083,  463,  1093,  876,  421,  561,  790,  1131,  1181,  437
,  1168,  996,  282,  777,  535,  1206,  393,  1000,  159,  336
,  662,  37,  566,  405,  166,  881,  281,  1159,  1113,  319
,  1025,  1117,  561,  1196,  116,  421,  541,  369,  715,  528
,  559,  114,  1151,  334,  1059,  810,  1196,  246,  566,  821
,  369,  318,  463,  559,  1186,  1180,  1093,  376,  1173,  528
,  1083,  777,  876,  1130,  1181,  421,  790,  561,  421,  1168
,  282,  535,  662,  37,  393,  336,  1000,  159,  1206,  166
,  281,  405,  881,  715,  1117,  1025,  1159,  561,  1168,  541
,  1043,  318,  161,  48,  502,  27,  51,  51,  51,  161
,  51,  51,  118,  819,  678,  1213,  49,  536,  184,  758
,  1112,  755,  1069,  1091,  341,  584,  1099,  1125,  428,  1073
,  259,  1018,  345,  1170,  428,  1118,  1003,  530,  127,  952
,  1091,  433,  408,  189,  251,  205,  745,  216,  1143,  884
,  431,  394,  606,  44,  404,  638,  1200,  980,  906,  876
,  938,  706,  375,  659,  1061,  1069,  70,  1035,  968,  1190
,  783,  207,  970,  431,  946,  226,  1170,  961,  332,  876
,  124,  912,  1142,  796,  274,  530,  527,  388,  189,  561
,  1185,  428,  492,  1002,  1093,  569,  45,  1113,  238,  918
,  146,  1115,  1109,  1125,  51,  341,  246,  1025,  390,  783
,  198,  184,  1003,  1091,  317,  1083,  551,  1069,  925,  207
,  1118,  923,  760,  1083,  14,  876,  1139,  1167,  127,  541
,  1223,  758,  1061,  1091,  536,  440,  48,  1082,  584,  1042
,  918,  386,  251,  614,  49,  499,  569,  527,  1093,  203
,  1104,  349,  589,  781,  490,  261,  1046,  637,  28,  1040
,  1016,  1109,  349,  927,  782,  722,  62,  859,  37,  206
,  1212,  1089,  541,  1189,  1115,  360,  772,  1181,  1068,  418
,  510,  409,  484,  1177,  1125,  1020,  281,  299,  357,  409
,  448,  1100,  528,  1123,  73,  723,  338,  930,  117,  1109
,  190,  224,  1076,  246,  443,  1125,  1031,  1212,  1016,  1123
,  358,  1104,  47,  1095,  1074,  1161,  203,  1177,  851,  541
,  743,  190,  1089,  484,  1212,  490,  545,  273,  528,  1110
,  217,  783,  1205,  715,  1188,  1092,  291,  435,  1057,  269
,  1125,  928,  985,  1228,  348,  318,  910,  621,  516,  135
,  962,  1180,  1027,  417,  123,  970,  421,  596,  478,  913
,  521,  1077,  873,  665,  1074,  713,  156,  1222,  169,  495
,  944,  377,  1056,  1047,  606,  790,  136,  1125,  346,  934
,  514,  1090,  417,  71,  421,  1020,  745,  527,  440,  1067
,  665,  1044,  901,  1077,  51,  78,  1111,  876,  876,  527
,  1184,  1088,  535,  526,  426,  285,  1092,  537,  1164,  217
,  745,  282,  1172,  214,  849,  475,  148,  258,  294,  99
,  971,  687,  696,  261,  118,  967,  280,  637,  238,  759
,  26,  110,  676,  447,  290,  402,  928,  459,  657,  876
,  463,  545,  319,  18,  722,  1115,  73,  1111,  211,  410
,  440,  923,  1062,  34,  48,  66,  759,  593,  758,  1121
,  315,  1175,  633,  192,  414,  420,  251,  303,  62,  360
,  1095,  133,  962,  781,  1029,  790,  1189,  620,  1083,  1028
,  515,  818,  1090,  1094,  7,  220,  1110,  841,  462,  563
,  351,  824,  1035,  1053,  946,  182,  573,  510,  1043,  37
,  1019,  960,  409,  273,  575,  775,  139,  437,  244,  748
,  123,  299,  527,  941,  440,  294,  466,  561,  762,  443
,  1200,  0,  495,  154,  1206,  1175,  39,  930,  219,  753
,  759,  427,  592,  106,  1021,  320,  182,  603,  53,  504
,  1135,  599,  452,  532,  338,  230,  246,  1151,  1079,  233
,  96,  772,  629,  766,  386,  414,  901,  1169,  1182,  597
,  30,  549,  814,  922,  762,  301,  154,  1016,  1099,  549
,  452,  920,  844,  907,  358,  1174,  1093,  669,  408,  1216
,  1062,  532,  16,  627,  569,  205,  14,  469,  762,  933
,  588,  1104,  104,  431,  52,  556,  1135,  381,  749,  764
,  1053,  647,  933,  536,  514,  236,  930,  1182,  203,  750
,  268,  441,  530,  1205,  519,  956,  240,  193,  37,  1093
,  1192,  403,  59,  414,  414,  900,  52,  34,  559,  1043
,  506,  1085,  1031,  669,  569,  1218,  563,  1140,  426,  285
,  1092,  1172,  217,  1164,  742,  537,  971,  758,  148,  851
,  258,  214,  599,  687,  99,  290,  73,  928,  440,  238
,  110,  1182,  637,  37,  294,  26,  759,  1085,  773,  447
,  1016,  315,  459,  261,  402,  967,  676,  19,  1115,  759
,  1175,  759,  319,  65,  463,  744,  70,  66,  1121,  1218
,  633,  931,  410,  211,  1109,  956,  66,  545,  900,  758
,  593,  876,  1062,  923,  48,  657,  723,  240,  462,  515
,  251,  1110,  123,  409,  1087,  647,  193,  962,  573,  214
,  1094,  452,  1151,  1189,  1022,  960,  220,  381,  790,  844
,  342,  214,  303,  620,  1175,  841,  420,  1090,  104,  133
,  933,  8,  1095,  818,  1192,  514,  751,  504,  941,  532
,  469,  1035,  922,  527,  1149,  139,  338,  299,  244,  1053
,  182,  575,  273,  1043,  550,  451,  414,  824,  943,  510
,  774,  438,  0,  762,  1169,  686,  182,  592,  39,  199
,  466,  495,  1020,  320,  569,  154,  1200,  427,  1027,  442
,  400,  714,  930,  219,  414,  440,  603,  1206,  772,  452
,  762,  901,  246,  95,  766,  1182,  233,  907,  386,  3
,  230,  597,  556,  268,  596,  627,  1174,  301,  669,  441
,  669,  635,  549,  298,  30,  1093,  408,  59,  52,  934
,  588,  569,  1104,  431,  204,  1216,  1062,  930,  445,  538
,  749,  560,  236,  506,  750,  170,  762,  203,  403,  519
,  1205,  530,  1093,  97,  52,  1031,  107,  107,  599,  890
,  850,  1075,  48,  451,  459,  370,  825,  1028,  1028,  412
,  619,  1151,  360,  301,  301,  254,  333,  619,  496,  511
,  572,  1121,  106,  1074,  1075,  246,  397,  1115,  1007,  788
,  26,  1003,  498,  795,  506,  948,  360,  795,  151,  327
,  456,  104,  725,  925,  599,  890,  850,  1075,  48,  1009
,  151,  825,  1003,  1028,  370,  412,  619,  457,  600,  1151
,  649,  333,  1007,  925,  619,  572,  254,  301,  360,  496
,  434,  1121,  512,  1115,  1074,  106,  1023,  1007,  397,  1075
,  1074,  104,  506,  788,  498,  795,  360,  948,  795,  456
,  283,  1227,  235,  758,  1019,  26,  469,  821,  430,  262
,  1079,  1094,  1174,  422,  1217,  1228,  211,  0,  985,  742
,  283,  407,  561,  553,  118,  1046,  556,  627,  417,  1030
,  288,  850,  1046,  48,  850,  869,  1181,  225,  1119,  1174
,  139,  669,  1124,  1029,  714,  1212,  1094,  154,  118,  723
,  545,  938,  1030,  561,  1079,  944,  1113,  552,  1002,  669
,  235,  916,  390,  422,  916,  1096,  301,  1124,  1004,  6
,  1023,  407,  1163,  918,  916,  1029,  1021,  1096,  393,  553
,  528,  528,  1200,  1178,  920,  443,  641,  795,  1077,  1050
,  1072,  405,  320,  1181,  317,  448,  161,  1104,  437,  139
,  571,  212,  915,  892,  139,  1127,  404,  135,  526,  641
,  1114,  1113,  1065,  1007,  1123,  528,  545,  519,  32,  211
,  1019,  1054,  407,  1035,  959,  1174,  715,  596,  403,  846
,  265,  1158,  657,  541,  892,  1025,  551,  1019,  1095,  5
,  1030,  561,  20,  722,  407,  582,  528,  5,  545,  777
,  535,  431,  431,  431,  211,  431,  265,  462,  606,  611
,  1089,  610,  1089,  301,  428,  1063,  19,  184,  1078,  1040
,  7,  313,  184,  767,  586,  769,  437,  816,  782,  437
,  49,  412,  315,  37,  415,  184,  758,  412,  1003,  810
,  349,  1004,  937,  1125,  1003,  810,  349,  1004,  1125,  937
,  435,  1094,  1125,  857,  390,  1125,  1033,  1089,  218,  779
,  1034,  898,  348,  1054,  1057,  906,  753,  353,  1115,  995
,  25,  238,  744,  546,  301,  1040,  1091,  345,  282,  966
,  409,  351,  430,  978,  737,  463,  944,  244,  246,  1075
,  1195,  1119,  836,  209,  521,  586,  358,  320,  1160,  1029
,  737,  559,  669,  790,  1089,  218,  779,  348,  1034,  898
,  1054,  1054,  995,  320,  238,  753,  25,  906,  353,  1115
,  559,  546,  742,  430,  423,  409,  360,  1100,  463,  1091
,  737,  978,  351,  1100,  463,  944,  246,  1195,  1075,  244
,  669,  585,  209,  836,  358,  105,  818,  737,  790,  273
,  710,  829,  927,  321,  440,  1079,  907,  730,  52,  273
,  52,  829,  440,  907,  730,  52,  49,  265,  265,  874
,  404,  919,  1033,  238,  810,  1115,  129,  260,  1096,  1091
,  903,  33,  876,  420,  62,  1033,  1080,  251,  1077,  80
,  65,  652,  246,  1113,  1083,  398,  414,  1030,  328,  957
,  1046,  1005,  1023,  494,  551,  907,  625,  586,  1051,  427
,  494,  1197,  404,  803,  1104,  937,  1033,  1077,  103,  874
,  404,  934,  982,  1023,  810,  1115,  129,  260,  1096,  414
,  876,  33,  903,  1091,  251,  803,  1033,  420,  62,  65
,  246,  1113,  652,  398,  1030,  328,  95,  494,  907,  103
,  625,  549,  1051,  427,  586,  833,  1197,  644,  879,  492
,  339,  1031,  283,  1043,  579,  1115,  274,  985,  127,  1068
,  66,  1192,  681,  437,  1137,  411,  927,  283,  875,  985
,  903,  727,  347,  571,  448,  124,  1200,  466,  753,  753
,  1019,  729,  758,  1181,  549,  942,  1117,  1212,  838,  851
,  569,  627,  14,  80,  733,  164,  785,  381,  1035,  1160
,  418,  1077,  429,  1093,  1214,  572,  1031,  407,  526,  579
,  1115,  985,  1068,  127,  785,  66,  572,  1137,  875,  903
,  283,  437,  1212,  1192,  985,  681,  411,  1093,  189,  1035
,  580,  418,  381,  571,  347,  727,  526,  124,  1077,  448
,  753,  753,  466,  1200,  80,  729,  1181,  838,  1019,  16
,  549,  758,  851,  52,  569,  164,  104,  1188,  407,  1031
,  319,  10,  966,  425,  206,  476,  345,  373,  301,  48
,  463,  757,  554,  485,  60,  554,  228,  1136,  917,  945
,  60,  485,  297,  52,  495,  592,  952,  1206,  255,  798
,  1051,  407,  1209,  904,  790,  377,  434,  60,  1054,  386
,  60,  539,  226,  649,  372,  1023,  434,  109,  1115,  301
,  1115,  334,  492,  398,  18,  745,  598,  1076,  1035,  534
,  1000,  534,  1005,  126,  625,  1076,  1113,  560,  262,  1109
,  927,  34,  283,  423,  250,  1004,  418,  333,  1027,  336
,  310,  388,  135,  527,  844,  1206,  777,  212,  268,  657
,  495,  106,  429,  545,  1212,  661,  407,  216,  390,  782
,  283,  830,  874,  327,  925,  1083,  753,  530,  14,  517
,  952,  412,  586,  54,  1065,  55,  1223,  851,  335,  541
,  1068,  375,  527,  407,  246,  559,  526,  1113,  1109,  560
,  262,  20,  741,  661,  559,  283,  34,  375,  927,  333
,  423,  1004,  250,  407,  418,  1027,  1033,  1068,  310,  526
,  530,  412,  527,  874,  952,  336,  844,  388,  407,  777
,  545,  1212,  265,  495,  106,  320,  657,  661,  212,  429
,  873,  1206,  272,  216,  830,  246,  782,  283,  390,  49
,  838,  14,  753,  924,  327,  1083,  517,  54,  1065,  55
,  586,  619,  1104,  335,  851,  541,  1223,  527,  666,  434
,  276,  620,  1116,  445,  1174,  33,  1070,  545,  985,  1116
,  786,  126,  318,  1078,  1070,  250,  321,  370,  300,  1051
,  441,  1115,  66,  944,  244,  377,  1018,  7,  719,  35
,  795,  221,  156,  377,  246,  1019,  1098,  361,  826,  319
,  412,  1085,  1170,  692,  1181,  551,  901,  418,  536,  436
,  1028,  1115,  1098,  561,  559,  1098,  329,  526,  563,  666
,  434,  404,  1116,  620,  692,  1070,  33,  1174,  318,  221
,  559,  1070,  1078,  126,  786,  1116,  985,  901,  1181,  250
,  321,  1051,  300,  563,  370,  66,  526,  441,  377,  244
,  1115,  1028,  944,  1018,  795,  613,  7,  35,  719,  156
,  377,  246,  377,  161,  596,  1019,  1085,  412,  361,  1098
,  1170,  551,  536,  418,  436,  1115,  561,  1098,  379,  329
,  560,  1028,  180,  413,  1075,  180,  561,  406,  797,  1191
,  606,  753,  561,  528,  863,  541,  584,  584,  280,  785
,  611,  280,  578,  625,  595,  393,  390,  390,  370,  370
,  883,  526,  661,  362,  759,  627,  189,  141,  1110,  210
,  1090,  1025,  785,  778,  526,  194,  228,  82,  9,  82
,  596,  228,  1180,  281,  282,  619,  619,  1117,  14,  985
,  1117,  985,  218,  639,  319,  221,  938,  723,  883,  270
,  1111,  1017,  1076,  1020,  1076,  46,  783,  348,  1150,  753
,  1154,  404,  753,  404,  128,  120,  31,  1206,  439,  952
,  545,  138,  1095,  669,  159,  1114,  787,  1015,  128,  120
,  439,  545,  31,  952,  1206,  1095,  1114,  159,  787,  1015
,  552,  706,  312,  454,  552,  312,  454,  333,  333,  1121
,  360 };
#endif /* SIMPLE_TTS */

/* Background Sound */
#if defined(BGSND_ENABLE)
static U16 snd_audio_state = MDI_AUDIO_IDLE;
static mdi_ext_callback snd_crnt_handler = NULL;
static void* snd_user_data = NULL;
static U16 g_mdi_aud_bgsnd_identifier;
#endif /* defined(BGSND_ENABLE) */

/* Post-processing */
#if defined(__BES_TS_SUPPORT__)
static MMI_BOOL mdi_aud_stretch_on;
#endif

/* Audio clipper */
#ifdef __AUDIO_TRIM_SUPPORT__
static void mdi_audio_trim_interrupt(void);
mdi_aud_trim_callback g_trim_cb = NULL;
kal_uint32 g_trim_handle = 0;
void* g_trim_user_data = NULL;
#endif /* __AUDIO_TRIM_SUPPORT__ */

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 
/* Playback control */
static void(*updateDurHandler)(U32 duration);
void mdi_audio_play_string_cnf(void *inMsg);
void mdi_audio_play_finish_ind(void *inMsg);
void mdi_audio_play_finish_ind1(void *inMsg);
void mdi_audio_update_dur_ind(void *inMsg);
void mdi_audio_record_finish_ind(void *inMsg);
void mdi_audio_background_timeout_handler(void);
void mdi_audio_suspend_background_play_by_app_async_hdlr(void *msg);
void mdi_send_msg(module_type dest_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern kal_int16 med_get_media_type(kal_wchar *file_name);
extern void aud_send_stop_build_cache_req(module_type src_id);

extern kal_uint32 aud_rec_get_estimated_record_byte_rate(MDI_AUDIO_REC_MODE_ENUM mode, MDI_FORMAT_ENUM format, MDI_AUDIO_REC_QUALITY_ENUM quality);
extern void aud_rec_get_record_param(MDI_AUDIO_REC_MODE_ENUM mode,MDI_AUDIO_REC_QUALITY_ENUM quality , mdi_audio_rec_param_struct* param_p);
extern void aud_send_bt_audio_set_sco_mode_req(module_type src_mod_id, kal_uint8 mode);
extern void aud_send_mma_open_async_req(kal_int32 param_p);
extern void aud_send_mma_build_BLISRC_table(kal_bool turn_on);
extern void aud_send_fmr_seek_start_req(module_type src_mod_id, kal_uint16 start_freq, kal_bool is_step_up, kal_bool is_preset, kal_int16 space_value);


/* Volume control */
static void mdi_audio_stop_crescendo_timer(void);
static void mdi_audio_crescendo_timeout_hdlr(void);
static kal_uint64 mdi_audio_get_volume_per_play_style(kal_uint8 type, kal_uint8 volume, kal_uint8 play_style);
static kal_uint64 mdi_audio_get_volume_per_id(kal_uint8 audio_id, kal_uint8 volume, kal_uint8 play_style);

#ifdef __GAIN_TABLE_SUPPORT__
static void mdi_audio_state_change_ind_hdlr(void *inMsg);
static kal_uint8 mdi_audio_get_output_path_by_id(kal_uint8 audio_id, kal_uint8 path);
static kal_uint8 mdi_audio_get_media_source_by_type(kal_int16 type);
static void mdi_audio_update_speech_param(void);
#endif /* __GAIN_TABLE_SUPPORT__ */

/* BT */
#ifdef __MMI_BT_AUDIO_SUPPORT__
mdi_audio_bt_cntx_struct mdi_audio_bt_cntx;
extern void aud_send_bt_audio_open_req(
                module_type src_mod_id,
                kal_uint8 profile,
                kal_uint8 mode,
                kal_uint16 connect_id);
extern void aud_send_bt_audio_turn_on_req(module_type src_mod_id, kal_uint8 profile);
extern void srv_btsco_open_stream_callback(U8 profile, mdi_result result, U16 error_cause,U8 connect_id);
extern void srv_btsco_close_stream_callback(U8 profile, mdi_result result, U16 error_cause,U8 connect_id);
#endif /* __MMI_BT_AUDIO_SUPPORT__ */

/* FMR */
#ifdef FM_RADIO_RECORD
static void mdi_fmr_record_finish_ind(void *inMsg);
static void mdi_fmr_stop_record_remain_on(void);
#endif /* FM_RADIO_RECORD */

#ifdef __FM_RADIO_RDS_SUPPORT__
static void (*mdi_fmr_rds_callback)(mdi_rds_event_struct *buffer, void* user_data);
#endif /* __FM_RADIO_RDS_SUPPORT__*/

#ifdef __FM_RADIO_HW_SCAN__
static void (*mdi_fmr_hw_scan_result_hdlr) (void);
#endif /* __FM_RADIO_HW_SCAN__ */

#ifdef __FM_RADIO_HW_SEARCH__
static void (*mdi_fmr_seek_result_hdlr) (U16 stop_freq, U8 signal_level, MMI_BOOL is_valid);
#else
static void (*mdi_fmr_check_is_valid_stop_hdlr) (MMI_BOOL is_valid);
static void (*mdi_fmr_get_signal_level_hdlr) (U8 sig_lvl);
#endif /*__FM_RADIO_HW_SEARCH__*/

/* MMA */
static void mdi_audio_mma_close_all(void);

/* Seek */
static mdi_seek_callback g_seek_cb_fct = NULL;

/* Auto answer mechine */
#if defined(__KEY_TONE_DETECTION__)
static void (*mdi_keytone_detect_callback)(S16);
#endif /*__KEY_TONE_DETECTION__*/


/* VOIP */
extern kal_int8 voip_encoding_start(kal_int8 rtp_handle);
extern kal_int8 voip_encoding_stop(kal_int8 rtp_handle);
extern kal_int8 voip_decoding_start(kal_int8 rtp_handle);
extern kal_int8 voip_decoding_stop(kal_int8 rtp_handle);
extern kal_int8 rtp_send_dtmf_start(kal_int8 rtp_handle, kal_uint8 dtmf_code, kal_uint8 send_type);
extern kal_int8 rtp_send_dtmf_stop(kal_int8 rtp_handle);
extern kal_int8 voip_mixer_add(kal_int8 rtp_handle);
extern kal_int8 voip_mixer_remove(kal_int8 rtp_handle);

/* TTS */
mdi_result mdi_audio_play_current_word(void);
void mdi_audio_play_timeout_handler(void);

extern kal_bool notify_poweroff;

/*-----------------------------------------------------------------------------
                                     DRM
 ----------------------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_timeout_callback
 * DESCRIPTION
 *  This is the callback function when DRM timeout
 * PARAMETERS
 *  kal_int32 result    [IN]
 *  kal_uint32 id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_drm_timeout_callback(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_TIMEOUT_CALLBACK, result, id, mdi_audio_drm_id);

    if(id == mdi_audio_drm_id)
    {
        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            mdi_cb_handler = NULL;
            tmp_cb_handler(MDI_AUDIO_DRM_TIMEOUT, mdi_cb_data);
        }
        else /* Stop playing if app does not provide callback */
        {
            mdi_audio_stop_file();        
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_mma_timeout_callback
 * DESCRIPTION
 *  This is the callback function when DRM timeout
 * PARAMETERS
 *  kal_int32 result    [IN]
 *  kal_uint32 id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_drm_mma_timeout_callback(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_handle handle;
    void* user_data;
    mdi_mma_callback callback;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_TIMEOUT_CALLBACK, result, id, mdi_audio_drm_id);

    if (id == mdi_audio_drm_id)
    {
        if (mdi_audio_mma_player[mdi_audio_drm_mma_idx].callback)
        {
            handle    = mdi_audio_mma_player[mdi_audio_drm_mma_idx].handle;
            callback  = mdi_audio_mma_player[mdi_audio_drm_mma_idx].callback;
            user_data = mdi_audio_mma_player[mdi_audio_drm_mma_idx].user_data;
            
            mdi_audio_mma_stop(handle);
            mdi_audio_mma_close(handle);

            if (callback)
            {
                callback(handle, MDI_AUDIO_DRM_TIMEOUT, user_data);
            }
        }
    }
}


#if defined(BGSND_ENABLE)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_bgsnd_timeout_callback
 * DESCRIPTION
 *  This is the callback function when DRM timeout
 * PARAMETERS
 *  kal_int32 result    [IN]
 *  kal_uint32 id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_drm_bgsnd_timeout_callback(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_BGSND_TIMEOUT_CALLBACK, result, id, mdi_audio_drm_bgsnd_id);

    if(id == mdi_audio_drm_bgsnd_id)
    {
        if (snd_crnt_handler)
        {
            tmp_cb_handler = snd_crnt_handler;
            snd_crnt_handler = NULL;
            tmp_cb_handler(MDI_AUDIO_DRM_TIMEOUT, snd_user_data);
        }
        else /* Stop playing if app does not provide callback */
        {
            mdi_audio_snd_stop();        
        }
    }
}
#endif /*BGSND_ENABLE*/

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_do_validate_right_with_handle
 * DESCRIPTION
 *  This function is to process the valdation of DRM right with file handle
 * PARAMETERS
 *  FS_HANDLE   [IN]    file handle to be checked
 * RETURNS
 *  mdi_result
 *****************************************************************************/
static mdi_result mdi_audio_drm_do_validate_right_with_handle(FS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_DRM_PROHIBIT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Consume count and time */
    if(mdi_audio_drm_consume_rule == MDI_AUD_DRM_CONSUME_ALL)
    {
        if(DRM_validate_permission(handle, NULL, DRM_PERMISSION_PLAY))
        {
            result = MDI_AUDIO_SUCCESS;
        }
    }
    /* Consume time only */
    else if (mdi_audio_drm_consume_rule == MDI_AUD_DRM_CONSUME_TIME_ONLY)
    {
        if(DRM_validate_timed_permission(handle, DRM_PERMISSION_PLAY))
        {
            result = MDI_AUDIO_SUCCESS;
        }
    }
    else
    {
        result = MDI_AUDIO_SUCCESS;
    }

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_validate_right
 * DESCRIPTION
 *  This function is to valdate DRM right before play
 * PARAMETERS
 *  U16 filename    [IN]    file to be played
 * RETURNS
 *  mdi_result
 *****************************************************************************/
static mdi_result mdi_audio_drm_validate_right(U16* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    mdi_result result = MDI_AUDIO_DRM_PROHIBIT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_VALIDATE_RIGHT, mdi_audio_drm_consume_rule);

    if((handle = DRM_open_file((U16*)filename, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_PLAY)) >= FS_NO_ERROR)
    {
        if (DRM_get_object_method(handle, NULL) == DRM_METHOD_NONE)
        {
            DRM_close_file(handle);
            return MDI_AUDIO_SUCCESS;
        }
    
        /* Consume count and time */
        result = mdi_audio_drm_do_validate_right_with_handle(handle);

        DRM_close_file(handle);
        return result;
    }
    else if (handle == DRM_RESULT_NO_PERMISSION)
    {
        return MDI_AUDIO_DRM_PROHIBIT;
    }
    else   /* file open error, but not DRM related problem */
    {
        return MDI_AUDIO_OPEN_FILE_FAIL;
    }

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_consume_right
 * DESCRIPTION
 *  This function is to consume DRM right after play
 * PARAMETERS
 *  file_name       [IN]    File name to be played.
 *  drm_handle      [IN]    DRM handle. Will be used if file_name is NULL.
 *  drm_id          [OUT]   DRM id
 *  callback_func   [IN]    Callback function   
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_drm_consume_right(U16* file_name, FS_HANDLE drm_handle, S32* drm_id, void (*callback_func)(kal_int32 result, kal_int32 id))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle = drm_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_COSUME_RIGHT, mdi_audio_drm_consume_rule);

    *drm_id = -1;

    if(mdi_audio_drm_consume_rule != MDI_AUD_DRM_CONSUME_NONE)
    {
        /* Open DRM handle if the file name is given */
        if (file_name)
        {
            handle = DRM_open_file((U16*)file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_PLAY);
        }

        if (handle >= FS_NO_ERROR)
        {
            if (DRM_get_object_method(handle, NULL) != DRM_METHOD_NONE)
            {
                /* Consume count and time */
                if(mdi_audio_drm_consume_rule == MDI_AUD_DRM_CONSUME_ALL)
                {
                    *drm_id = DRM_consume_rights(handle, DRM_PERMISSION_PLAY, callback_func);
                }
                /* Consume time only */
                else if(mdi_audio_drm_consume_rule == MDI_AUD_DRM_CONSUME_TIME_ONLY)
                {
                    *drm_id = DRM_consume_timed_rights(handle, DRM_PERMISSION_PLAY, callback_func);
                }
            }

            /* Remember to close the DRM handle if consuming the DRM by using file name */
            if (file_name)
            {
                DRM_close_file(handle);
            }
        }
    }
    mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL; /* Clear this flag for each consume request */

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_COSUME_RIGHT_RESULT, handle, *drm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_disable_consume_count
 * DESCRIPTION
 *  This function is to disable DRM right consume when play file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_drm_disable_consume_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_DISABLE_CONSUME_COUNT);

    mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_TIME_ONLY;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_disable_consume_all
 * DESCRIPTION
 *  This function is to disable DRM right consume, including "Time" and "Count"
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_drm_disable_consume_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_DISABLE_CONSUME);

    mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_NONE;
}
#endif /* __DRM_SUPPORT__ */


/*-----------------------------------------------------------------------------
                                 Initialization
 ----------------------------------------------------------------------------*/

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
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */ 
/* under construction !*/
#if defined(__BES_TS_SUPPORT__)
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_init
 * DESCRIPTION
 *  This function will be called by bootup service in EVT_ID_SRV_BOOTUP_EARLY_INIT
 *  stage. We should initialize the mdi audio interface here.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_INIT);

#if defined(__J2ME__) || defined(__MMI_MEDIA_PLAYER__)
    /* Create Mutex */
    g_mdi_audio_sem = kal_create_sem("MDI AUDIO SEMAPHORE", 1);
#endif /* #if defined(__J2ME__) || defined(__MMI_MEDIA_PLAYER__) */

    /* stop all audio if someone still playing while re-init */
    if(!mdi_audio_is_idle())
    {
        mdi_audio_stop_all();
    }

    /* Init MDI variables : only init those who is not zero cause all context are zero initialized*/
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
    mdi_audio_play_text_context.cursor = -1;
#endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */ 



    /* Init background play */
    backgroud_enabled = MMI_TRUE;

    for (i = 0; i < MDI_BACKGROUND_APP_TOTAL; i++)
    {
        background_handler.app[i] = MDI_BACKGROUND_APP_TOTAL;
    }

    /* Init bluetooth profile */
#ifdef __MMI_BT_AUDIO_SUPPORT__
#if defined( __MMI_HFP_SUPPORT__ ) || defined(__MMI_HF_SUPPORT__)
      mdi_audio_bt_cntx.open_hdlr = srv_btsco_open_stream_callback;
      mdi_audio_bt_cntx.close_hdlr = srv_btsco_close_stream_callback;
#endif 
#endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

#ifdef __DRM_SUPPORT__
    mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL;
    mdi_audio_drm_id = -1;
#if defined(BGSND_ENABLE)
    mdi_audio_drm_bgsnd_id = -1;
#endif
#endif /*__DRM_SUPPORT__*/

    /* Update microphone volume */
    mdi_audio_set_mic_volume();
    
#ifdef __GAIN_TABLE_SUPPORT__
    /* Initialize gain table */
    gain_table_init();
    mdi_audio_update_speech_param();
#endif /* __GAIN_TABLE_SUPPORT__ */

    SetProtocolEventHandler(mdi_audio_suspend_background_play_by_app_async_hdlr, MSG_ID_MMI_MDI_SUSPEND_BACKGROUND_PLAY_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_init_event_hdlrs
 * DESCRIPTION
 *  This function will be called by bootup service in EVT_ID_SRV_BOOTUP_EARLY_INIT
 *  stage (later than the mdi_audio_init). We should set event handlers here. Note
 *  that we should set event handlers here because the framework will reset event
 *  handlers with it's inited.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_init_event_hdlrs(void)
{
#ifdef __MMI_BT_AUDIO_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mdi_audio_bt_close_stream_cnf, MSG_ID_MEDIA_BT_AUDIO_CLOSE_CNF);
    SetProtocolEventHandler(mdi_audio_bt_close_stream_ind, MSG_ID_MEDIA_BT_AUDIO_CLOSE_IND);
    SetProtocolEventHandler(mdi_audio_bt_open_stream_cnf, MSG_ID_MEDIA_BT_AUDIO_OPEN_CNF);
    SetProtocolEventHandler(mdi_audio_bt_open_stream_ind, MSG_ID_MEDIA_BT_AUDIO_OPEN_IND);

    SetProtocolEventHandler(mdi_audio_bt_open_stream_req, MSG_ID_MMI_MDI_BT_OPEN_STREAM_REQ);

#endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

#ifdef __GAIN_TABLE_SUPPORT__
    SetProtocolEventHandler(mdi_audio_state_change_ind_hdlr, MSG_ID_L4AUD_AUDIO_STATE_CHANGE_IND);
#endif /* __GAIN_TABLE_SUPPORT__ */
}


/*-----------------------------------------------------------------------------
                                 Utilities
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_mutex_lock(CHAR* file_p, U32 line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G10_MMI_PRINT,"[MDI][AUD] LOCK: cnt=[%d] [%s,%d]\n", g_mdi_audio_mutex_cnt, file_p, line_p);
    MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MDI_AUDIO_TRC_MUTEX_LOCK, g_mdi_audio_mutex_cnt, line_p);

    if (kal_get_active_module_id() != g_mdi_audio_mutex_tid)
    {
        kal_take_sem(g_mdi_audio_sem, KAL_INFINITE_WAIT);
        g_mdi_audio_mutex_tid = kal_get_active_module_id();
    }
    ++g_mdi_audio_mutex_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mutex_lock_no_wait
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mdi_audio_mutex_lock_no_wait(CHAR* file_p, U32 line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    //MMI_PRINT(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G10_MMI_PRINT,"[MDI][AUD] LOCK_NO_WAIT: cnt=[%d] [%s,%d]\n", g_mdi_audio_mutex_cnt, file_p, line_p);
    MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MDI_AUDIO_TRC_MUTEX_LOCK_NO_WAIT, g_mdi_audio_mutex_cnt, line_p);

    if (kal_get_active_module_id() != g_mdi_audio_mutex_tid)
    {
        if (kal_take_sem(g_mdi_audio_sem, KAL_NO_WAIT) == KAL_SEM_NOT_AVAILABLE)
        {       
            return MMI_FALSE;
        }
        g_mdi_audio_mutex_tid = kal_get_active_module_id();
       
    }
    ++g_mdi_audio_mutex_cnt;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_mutex_unlock(CHAR* file_p, U32 line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G10_MMI_PRINT,"[MDI][AUD] UNLOCK: cnt=[%d] [%s,%d]\n", g_mdi_audio_mutex_cnt, file_p, line_p);
    MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MDI_AUDIO_TRC_MUTEX_UNLOCK, g_mdi_audio_mutex_cnt, line_p);

    MDI_ASSERT(g_mdi_audio_mutex_tid == kal_get_active_module_id());

    --g_mdi_audio_mutex_cnt;

    if (g_mdi_audio_mutex_cnt == 0)
    {
        g_mdi_audio_mutex_tid = MOD_NIL;
        kal_give_sem(g_mdi_audio_sem);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_send_msg
 * DESCRIPTION
 *  This function is to send message from a given source module for the given
 *  destination module.
 * PARAMETERS
 *  dest_mod_id         [IN]    Destination module ID
 *  msg_id              [IN]    Message ID
 *  local_param_ptr     [IN]    Local parameter   
 *  peer_buf_ptr        [IN]    Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_send_msg(module_type dest_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    module_type src_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(src_id);
    
    ilm_ptr->src_mod_id = src_id;
    ilm_ptr->dest_mod_id = dest_mod_id;
    ilm_ptr->sap_id = (dest_mod_id == MOD_MED) ? MED_SAP : MMI_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_message_dispatcher()
 * DESCRIPTION
 *  Message dispatcher of MDI_AUDIO
 * PARAMETERS
 *  ilm_ptr             [IN]    ilm pointer
 * RETURNS
 *  MMI_BOOL: MDI_AUDIO consume the message or not 
 *****************************************************************************/
MMI_BOOL mdi_audio_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_p = ilm_ptr;
    MMI_BOOL handle_msg = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(ilm_p->msg_id)
    {
    	case MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND:
    	    mdi_audio_record_finish_ind((void*)ilm_p->local_para_ptr);
    		break;

        default:
            handle_msg = MMI_FALSE;
            break;
    }

    return handle_msg;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_cb_evt_hdlr
 * DESCRIPTION
 *  This function is to handle callback events from callback manager.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mdi_audio_cb_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (event->evt_id)
    {
        case EVT_ID_SRV_SHUTDOWN_DEINIT:
            mdi_audio_suspend_background_play();

            /* Switch path back to phone then before disconnect SCO*/
        #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
            /* Disconnect SCO if connect to A2DP */
            srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_MDI);
        #endif

            /* Notify L1audio that the MMI is going to be power-off */
            notify_poweroff=KAL_TRUE;
            break;

        case EVT_ID_SRV_SHUTDOWN_HANDLER_RESET:
            mdi_audio_init_event_hdlrs();
            break;

        case EVT_ID_GPIO_EARPHONE_PLUG_IN:
            mdi_fmr_set_antenna(MMI_FALSE);
            break;
            
        case EVT_ID_GPIO_EARPHONE_PLUG_OUT:
            mdi_fmr_set_antenna(MMI_TRUE);
            break;
            
        default:
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_audio_mode
 * DESCRIPTION
 *  This function is to set the audio mode (normal, headset, loudspk).
 * PARAMETERS
 *  mode        [IN]        
 *  U8(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_audio_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*MYQUEUE Message;*/
    mmi_eq_set_audio_mode_req_struct *myMsgPtr;

    mmi_evt_mdi_audio_mode_switch_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_audio_mode != mode)
    {
        /* Emit pre-mode switch to application */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_PRE_MODE_SWITCH);
        evt.pre_mode = g_audio_mode;
        evt.new_mode = mode;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    
        /* Post mode switched to application */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_MODE_SWITCHED);
        evt.pre_mode = g_audio_mode;
        evt.new_mode = mode;
        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }

    g_audio_mode = mode;

#ifdef __GAIN_TABLE_SUPPORT__
    /* Update speech parameters */
    mdi_audio_update_speech_param();
#endif /* __GAIN_TABLE_SUPPORT__ */

    myMsgPtr = (mmi_eq_set_audio_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_set_audio_mode_req_struct));
    myMsgPtr->mode = mode;  /* AUD_MODE_LOUDSPK, AUD_MODE_NORMAL, AUD_MODE_HEADSET  audio_mode_enum */
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ, (oslParaType*) myMsgPtr, NULL);

#ifdef __GAIN_TABLE_SUPPORT__
    /* Update volume for audio mode changed */
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_AUDIO_MODE_CHANGED, (void*)mode);
#endif /* __GAIN_TABLE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_audio_mode
 * DESCRIPTION
 *  This function is to get the audio mode (normal, headset, loudspk).
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mdi_audio_get_audio_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_audio_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_state
 * DESCRIPTION
 *  This function is to get the audio state.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_state
 *****************************************************************************/
mdi_state mdi_audio_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_state state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK; 
    state = mdi_audio_state;
    MDI_AUDIO_UNLOCK;
    return state;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_event
 * DESCRIPTION
 *  This function is to convert event to mdi result.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
static mdi_result mdi_audio_get_event(S32 med_result_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (med_result_in)
    {
        case MED_RES_OK: /*0*/
            result = MDI_AUDIO_SUCCESS;
            break;
        case MED_RES_DISC_FULL: /*3*/
            result = MDI_AUDIO_DISC_FULL;
            break;
        case MED_RES_END_OF_FILE: /*5*/
            result = MDI_AUDIO_END_OF_FILE;
            break;
        case MED_RES_TERMINATED: /*6*/
            result = MDI_AUDIO_TERMINATED;
            break;
    #ifndef __LOW_COST_SUPPORT_COMMON__
        case MED_RES_FAIL: /*1*/
            result = MDI_AUDIO_FAIL;
            break;
        case MED_RES_BUSY: /*2*/
            result = MDI_AUDIO_BUSY;
            break;
        case MED_RES_OPEN_FILE_FAIL: /*4*/
            result = MDI_AUDIO_OPEN_FILE_FAIL;
            break;
        case MED_RES_BAD_FORMAT: /*7*/
            result = MDI_AUDIO_BAD_FORMAT;
            break;
        case MED_RES_INVALID_FORMAT: /*8*/
            result = MDI_AUDIO_INVALID_FORMAT;
            break;
        case MED_RES_ERROR: /*9*/
            result = MDI_AUDIO_ERROR;
            break;
        case MED_RES_NO_DISC: /*10*/
            result = MDI_AUDIO_NO_DISC;
            break;
        case MED_RES_MEM_INSUFFICIENT: /*16*/
            result = MDI_AUDIO_MEM_INSUFFICIENT;
            break;
        case MED_RES_BUFFER_INSUFFICIENT: /*17*/
            result = MDI_AUDIO_BUFFER_INSUFFICIENT;
            break;
        case MED_RES_WRITE_PROTECTION: /*19*/
            result = MDI_AUDIO_WRITE_PROTECTION;
            break;
        case MED_RES_PARAM_ERROR: /*20*/
            result = MDI_AUDIO_PARAM_ERROR;
            break;
        case MED_RES_UNSUPPORTED_CHANNEL: /*21*/
            result = MDI_AUDIO_UNSUPPORTED_CHANNEL;
            break;
        case MED_RES_UNSUPPORTED_FREQ: /*22*/
            result = MDI_AUDIO_UNSUPPORTED_FREQ;
            break;
        case MED_RES_UNSUPPORTED_TYPE: /*23*/
            result = MDI_AUDIO_UNSUPPORTED_TYPE;
            break;
        case MED_RES_UNSUPPORTED_OPERATION: /*24*/
            result = MDI_AUDIO_UNSUPPORTED_OPERATION;
            break;
        case MED_RES_PARSER_ERROR: /*25*/
            result = MDI_AUDIO_PARSER_ERROR;
            break;
        case MED_RES_AUDIO_ERROR: /*27*/
            result = MDI_AUDIO_AUDIO_ERROR;
            break;
        case MED_RES_UNSUPPORTED_SPEED: /*66*/
            result = MDI_AUDIO_UNSUPPORTED_SPEED;
            break;
        case MED_RES_DECODER_NOT_SUPPORT: /*101*/
            result = MDI_AUDIO_DECODER_NOT_SUPPORT;
            break;
    #endif
        case MED_RES_MP4_NO_AUDIO_TRACK: /*32*/
            result = MDI_AUDIO_MP4_NO_AUDIO_TRACK;
            break;

        case MED_RES_AUD_DUR_UPDATED: /*117*/
            result = MDI_AUDIO_DUR_UPDATED;
            break;
        default:
            result = MDI_AUDIO_FAIL;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_error_info
 * DESCRIPTION
 *  Display center hint string
 * PARAMETERS
 * error_code   [INPUT] error code got from MDI APIs
 * popup_type   [OUTPUT] popup_type of this error_code 
 * RETURNS
 *  MMI_ID_TYPE string_id
 *****************************************************************************/
MMI_ID_TYPE mdi_audio_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;

    switch (error_code)
    {
    #ifndef __LOW_COST_SUPPORT_COMMON__
        // TODO: need to revise for detail
        case MDI_AUDIO_FAIL:
        case MDI_AUDIO_ERROR:
        case MDI_AUDIO_MEM_INSUFFICIENT:
            string_id = STR_ID_MDI_COMMON_PLAY_FAIL;
            break;
        case MDI_AUDIO_OPEN_FILE_FAIL:
            string_id = STR_ID_MDI_COMMON_OPEN_FAIL;
            break;
        // TODO: need to revise for detail
        case MDI_AUDIO_INVALID_FORMAT:
            string_id = STR_GLOBAL_INVALID_FORMAT;
            break;
        case MDI_AUDIO_BAD_FORMAT:
        case MDI_AUDIO_UNSUPPORTED_CHANNEL:
        case MDI_AUDIO_UNSUPPORTED_FREQ:
        case MDI_AUDIO_UNSUPPORTED_TYPE:
        case MDI_AUDIO_DECODER_NOT_SUPPORT:            
            string_id = STR_ID_MDI_COMMON_INVALID_FILE;
            break;
        case MDI_AUDIO_UNSUPPORTED_SPEED:
            string_id = STR_ID_MDI_AUDIO_UNSUPPORTED_SPEED;
            break;
    #endif
        case MDI_AUDIO_BUSY:
            string_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
            break;
        case MDI_AUDIO_MP4_NO_AUDIO_TRACK:
            string_id = STR_ID_MDI_AUDIO_NO_AUD_TRACK;
            break;
        case MDI_AUDIO_DISC_FULL:
            string_id = STR_GLOBAL_MEMORY_FULL;
            break;
        case MDI_AUDIO_DRM_PROHIBIT:
        case MDI_AUDIO_DRM_TIMEOUT:
            string_id = STR_GLOBAL_DRM_PROHIBITED;
            break;
        default:
            string_id = STR_ID_MDI_COMMON_PLAY_FAIL;
            break;
    }
    
    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_resource_available
 * DESCRIPTION
 *  This function is to check if the resource for a given play mode is available.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE    The resource of the play mode is available.
 *  FALSE   The resource of the play mode is being occupied.
 *****************************************************************************/
MMI_BOOL mdi_audio_is_resource_available(MDI_AUDIO_PLAY_MODE_ENUM play_mode, void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_resource_available = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (play_mode)
    {
        case MDI_AUDIO_PLAY_STRING:
        case MDI_AUDIO_PLAY_FILE:
            if ((pseudo_play_handler == NULL) && /* BT is not connecting */
                media_aud_check_is_resource_available(AUD_RESOURCE_PLAYER))
            {
                is_resource_available = KAL_TRUE;
            }
            break;
        case MDI_AUDIO_RECORD_FILE:
        case MDI_AUDIO_RECORD_VR_VOICE:
            is_resource_available = media_aud_check_is_resource_available(AUD_RESOURCE_SND_RECORD);
            break;
        case MDI_AUDIO_RECORD_FM_RADIO:
            is_resource_available = media_aud_check_is_resource_available(AUD_RESOURCE_FMR_RECORD);
            break;
        case MDI_AUDIO_PLAY_VIA_SCO:
            is_resource_available = media_aud_check_is_resource_available(AUD_RESOURCE_SCO);
            break;
        case MDI_AUDIO_PLAY_MMA:
            is_resource_available = media_aud_check_is_resource_available(AUD_RESOURCE_MMA);
            break;
        case MDI_AUDIO_PLAY_ID:
        default:
            is_resource_available = KAL_TRUE;
            break;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_RESOURCE_AVAILABLE, play_mode, is_resource_available);

    return is_resource_available;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_in_call
 * DESCRIPTION
 *  This function is to check if audio can play in call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mdi_audio_is_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;

    /* The audio can not play when in Active Call(check speech on) or Held Call.
       Not allow in held call is to make background call scenario the same as active call */
    if(mdi_speech_session_on
    #ifdef __MMI_UCM__    
       || (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    #endif
	#ifdef __MMI_HF_SUPPORT__
	   || srv_bt_dialer_is_in_call()
	#endif
       )
    {
        MDI_AUDIO_UNLOCK;    
        return MMI_TRUE;
    }
    
    MDI_AUDIO_UNLOCK;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_file_seekable
 * DESCRIPTION
 *  This function is to check if a file is seekable. Currently, AAC-ADIF and 
 *  MIDI files are not seekable.
 * PARAMETERS
 *  file_name       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_file_seekable(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)media_aud_check_is_file_seekable(MOD_MMI, file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_seekable
 * DESCRIPTION
 *  This function is to check if a aac file seekable. (AAC ADIF is not seekable)
 * PARAMETERS
 *  file_name       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_aac_file_seekable(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_audio_is_file_seekable(file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_file_pausable
 * DESCRIPTION
 *  This function is to check if a file is pausable. Currently, only AAC-ADIF
 *  does not support pause capabilit.
 * PARAMETERS
 *  file_name       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_file_pausable(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)media_aud_check_is_file_pausable(MOD_MMI, file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_background_play_suspended
 * DESCRIPTION
 *  This function is to check if background play suspended.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_background_play_suspended(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    MMI_BOOL is_suspend = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < (MDI_AUD_SUSPEND_BG_TOTAL/8+1) ; i++)
    {
        if(g_mdi_aud_suspend_app[i])
        {
            is_suspend = MMI_TRUE;
            break;
        }
    }
    
	is_suspend = (MMI_BOOL)(is_suspend || (!backgroud_enabled));

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_BGPLAY_SUSPEND, is_suspend, backgroud_enabled);
    MDI_AUDIO_UNLOCK;
    return is_suspend;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_idle
 * DESCRIPTION
 *  This function is to check if audio is in idle state.
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_idle = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if ((mdi_audio_state == MDI_AUDIO_IDLE) && mdi_audio_mma_is_idle())
    {
        is_idle = MMI_TRUE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_IDLE, mdi_audio_state);
    MDI_AUDIO_UNLOCK;
    return is_idle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_idle
 * DESCRIPTION
 *  This function is to check if audio is in idle state.
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_playing(U16 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_playing = MMI_FALSE;
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_PLAYING, mdi_audio_state, mdi_audio_mode);
    
    if (audio_mode == MDI_AUDIO_PLAY_ANY)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_mode == MDI_AUDIO_PLAY_IN_OTHER_TASK)
        {
            is_playing = MMI_TRUE;
        }
        else
        {
            /* Check if MMA is being played */
            for (i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
            {
                if (mdi_audio_mma_player[i].state == MDI_AUDIO_PLAY)
                { 
                    is_playing = MMI_TRUE;
                    break;
                }
            }
        }
    }
    else if (audio_mode == MDI_AUDIO_PLAY_MMA)
    {
        /* Check if MMA is being played */
        for (i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
        {
            if (mdi_audio_mma_player[i].state == MDI_AUDIO_PLAY)
            { 
                is_playing = MMI_TRUE;
                break;
            }
        }
    }
    else /* Check if the given audio mode is being played */
    {
        if ((mdi_audio_state == MDI_AUDIO_PLAY) && (mdi_audio_mode == audio_mode))
        {
            is_playing = MMI_TRUE;
        }
    }

    MDI_AUDIO_UNLOCK;
    return is_playing;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_recording
 * DESCRIPTION
 *  This function is to check if it's recording.
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_recording(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_recording = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_RECORDING, mdi_audio_state);
    
#ifndef __GAIN_TABLE_SUPPORT__
    if (mdi_audio_state == MDI_AUDIO_RECORD || mdi_audio_state == MDI_AUDIO_RECORD_PAUSED)
#else
    if (g_is_camcorder_on || g_is_voice_record_on)
#endif /* __GAIN_TABLE_SUPPORT__ */
    {
        is_recording = KAL_TRUE;
    }
    
    return is_recording;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_fm_on
 * DESCRIPTION
 *  This function is to check if FMR is being on.
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_fm_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO) ||
        ((mdi_audio_state == MDI_AUDIO_RECORD || mdi_audio_state == MDI_AUDIO_RECORD_PAUSED) && 
         (mdi_audio_mode == MDI_AUDIO_RECORD_FM_RADIO)))
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
 *  mdi_audio_is_speech_mode
 * DESCRIPTION
 *  This function is to check is in speech mode
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_speech_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_speech_on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    is_speech_on = mdi_speech_session_on;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_SPEECH_MODE, is_speech_on);
    MDI_AUDIO_UNLOCK;
    return is_speech_on;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_pure_audio
 * DESCRIPTION
 *  This function is to check if a file is pure audio file
 * PARAMETERS
 *  file_name       [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_pure_audio(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    result = media_aud_check_is_pure_audio(MOD_MMI, file_name);
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_PURE_AUDIO, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_duration_need_build_cache
 * DESCRIPTION
 *  This function is to check if we need to build cache to get precise duration
 * PARAMETERS
 * handler     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mdi_audio_is_duration_need_build_cache(void *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get media type from filename extension */
    type = med_get_media_type( filename );

    switch (type)
    {
    #ifdef AMR_DECODE
        case MED_TYPE_AMR:       /* AMR */
    #ifdef AMRWB_DECODE
        case MED_TYPE_AMR_WB:    /* AWB */
    #endif /* AMRWB_DECODE */
    #endif /* AMR_DECODE */
    
    #ifdef DAF_DECODE
        case MED_TYPE_DAF:       /* DAF */
    #ifdef MUSICAM_DECODE
        case MED_TYPE_MUSICAM:   /* MUSICAM */
    #endif /* MUSICAM_DECODE */
    #endif /* DAF_DECODE */
    
    #ifdef AAC_DECODE
        case MED_TYPE_AAC:       /* AAC */
    #ifdef BSAC_DECODE
/* under construction !*/
    #endif /* BSAC_DECODE */
    #endif /* AAC_DECODE */
    
    #ifdef WAV_CODEC
        case MED_TYPE_WAV:       /* WAV */
    #endif /* WAV_CODEC */
            return MMI_TRUE;
        default:
            return MMI_FALSE;
    }

}


/*-----------------------------------------------------------------------------
                                 Player
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_check_states_and_handlers
 * DESCRIPTION
 *  This function is to check states and handlers before play or record request is executed
 * PARAMETERS
 *  result_p        [?]     
 * RETURNS
 * BOOL
 *****************************************************************************/
static MMI_BOOL mdi_audio_check_states_and_handlers(mdi_result *result_p, mdi_audio_check_reason_enum reason)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;

    /* Check state */
    if (reason == MDI_AUDIO_CHECK_REASON_PLAYBACK ||
        reason == MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK)
    {
        if (mdi_audio_state == MDI_AUDIO_RECORD        ||
            mdi_audio_state == MDI_AUDIO_RECORD_PAUSED ||
            mdi_audio_state == MDI_AUDIO_VRSI_PROCESS  ||
            mdi_audio_is_in_call())
        {
            *result_p = MDI_AUDIO_BUSY;
            MDI_AUDIO_UNLOCK;
            return MMI_FALSE;
        }
    }
    else if (reason == MDI_AUDIO_CHECK_REASON_SND_RECORD)
    {
        if (mdi_audio_state == MDI_AUDIO_RECORD || 
            mdi_audio_state == MDI_AUDIO_RECORD_PAUSED)
        {
            *result_p = MDI_AUDIO_BUSY;
            MDI_AUDIO_UNLOCK;
            return MMI_FALSE;
        }
    }
    else if (reason == MDI_AUDIO_CHECK_REASON_FM_RECORD)
    {
        if (mdi_audio_state == MDI_AUDIO_RECORD || 
            mdi_audio_state == MDI_AUDIO_RECORD_PAUSED)
        {
            *result_p = MDI_AUDIO_BUSY;
            MDI_AUDIO_UNLOCK;
            return MMI_FALSE;
        }
    #ifdef __MMI_BT_AUDIO_SUPPORT__
    #ifdef __MMI_BT_FM_VIA_SCO__
        else if(mdi_audio_bt_cntx.state != MDI_AUDIO_BT_STATE_IDLE) /* Can not record while BT SCO is open */
        {
            *result_p = MDI_AUDIO_HFP_SCO_CONNECTED;
            MDI_AUDIO_UNLOCK;
            return MMI_FALSE;
        }
    #endif /* __MMI_BT_FM_VIA_SCO__ */
    #endif /* __MMI_BT_AUDIO_SUPPORT__ */
    #ifdef __MMI_FM_VIA_A2DP__
        else if(srv_a2dp_is_codec_open())
        {
            *result_p = MDI_AUDIO_A2DP_CONNECTED;
            MDI_AUDIO_UNLOCK;
            return MMI_FALSE;
        }
    #endif
    }

    /* Interrupt current handler */
    {
        /* Stop crescendo timer */
        mdi_audio_stop_crescendo_timer();
        
        /* Stop previous DRM file consume */
    #ifdef __DRM_SUPPORT__
        if(mdi_audio_drm_id >= 0)
        {
            DRM_stop_consume(mdi_audio_drm_id);
            mdi_audio_drm_id = -1;
        }
    #endif /*__DRM_SUPPORT__*/

    #ifdef __AUDIO_TRIM_SUPPORT__
        if (g_trim_cb)
        {
            mdi_audio_trim_interrupt();
        }
    #endif /* __AUDIO_TRIM_SUPPORT__ */
    
        /*
         * set pseudo play file callback to NULL before callback
         * bcoz we could set another callback during callback
         */
        if (pseudo_play_handler)
        {
            tmp_cb_handler = pseudo_play_handler;
            pseudo_play_handler = NULL;
            tmp_cb_handler(MDI_AUDIO_TERMINATED, pseudo_play_data);
        }
        
    	if (interrupt_cb_handler)
    	{
            tmp_cb_handler = interrupt_cb_handler;
            interrupt_cb_handler = NULL;
            tmp_cb_handler(MDI_AUDIO_TERMINATED, interrupt_cb_data);
        }

        if (mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED
    #if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
            || mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_WAIT_STATE
    #endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */
            )
        {
            if (reason == MDI_AUDIO_CHECK_REASON_FM_RECORD)
            {
                /* Don't interrupt FM radio */
                if (!(mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO))
                {
                    if (mdi_cb_handler)
                    {
                        tmp_cb_handler = mdi_cb_handler;
                        mdi_cb_handler = NULL;
                        tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
                    }
                }
            }
            else
            {
                if (mdi_cb_handler)
                {
                    tmp_cb_handler = mdi_cb_handler;
                    mdi_cb_handler = NULL;
                    tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
                }

                if (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO)
                {
                    mdi_fmr_power_off();
                }
            }
        }

        /* Close all the mma handlers */
        if (reason != MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK)
        {
            mdi_audio_mma_close_all();
        }
    }

    /* *result_p = MDI_AUDIO_SUCCESS; */
    MDI_AUDIO_UNLOCK;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_check_state
 * DESCRIPTION
 *  This function is to check state before play a file
 * PARAMETERS
 *  file_name       [?]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
static mdi_result mdi_audio_play_file_check_state(U16 *file_name, mdi_audio_check_reason_enum check_reason)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
#ifdef __DRM_SUPPORT__
    MMI_BOOL drm_fail_stop = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FILE_CHECK_STATE, mdi_audio_state);

#ifdef __DRM_SUPPORT__
    if (mdi_audio_state == MDI_AUDIO_PLAY
        || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
        || mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_WAIT_STATE
#endif 
       )
    {
        drm_fail_stop = MMI_TRUE;
    }
#endif

    if (!mdi_audio_check_states_and_handlers(&result, check_reason))
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL;
#endif
        MDI_AUDIO_UNLOCK;
        return result;
    }

#ifdef __DRM_SUPPORT__
    result = mdi_audio_drm_validate_right((U16*)file_name);

    if(result != MDI_AUDIO_SUCCESS)
    {
        mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL;
        if(drm_fail_stop)
        {
            mdi_audio_stop_all();
        }
        MDI_AUDIO_UNLOCK;
        return result;
    }
#endif /* #ifdef __DRM_SUPPORT__ */

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_id
 * DESCRIPTION
 *  This function is to play audio id.
 * PARAMETERS
 *  audio_id        [IN]
 *  play_style      [IN]             
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_id(U16 audio_id, U8 play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_ID, audio_id, mdi_audio_state);

    return mdi_audio_play_id_with_vol_path(
            audio_id,
            play_style,
            (U8)srv_prof_get_ring_vol(),
            MDI_DEVICE_SPEAKER2);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_id_with_vol_path
 * DESCRIPTION
 *  This function is to play audio id along with volume and output path.
 * PARAMETERS
 *  audio_id        [IN] 
 *  play_style      [IN]        
 *  volume          [IN]
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_id_with_vol_path(
            U16 audio_id,
            U8 play_style,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_id_struct id_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_ID_WITH_VOL_PATH, audio_id, mdi_audio_state);

    /* All sound shall go through bluetooth earphone. (Except keypad tone) */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
#ifndef __MMI_BT_SCO_KEY_TONE__
    if(audio_id > TONE_KEY_CLICK) /* Key tone does not go to BT headset */
#endif
    {
        srv_btsco_connect_audio_via_sco();
    }
#endif /*__MMI_BT_AUDIO_VIA_SCO__*/

#ifdef __GAIN_TABLE_SUPPORT__
    g_audio_path = mdi_audio_get_output_path_by_id(audio_id, path);

    id_param.audio_id = (U8) audio_id;
    id_param.play_style = play_style;
    id_param.volume = mdi_audio_get_volume_per_id(audio_id, volume, play_style);;
    id_param.output_path = g_audio_path;
    id_param.identifier = (U16) (identifier);
#else
    id_param.audio_id = (U8) audio_id;
    id_param.play_style = play_style;
    id_param.volume = mdi_audio_get_volume_per_id(audio_id, volume, play_style);;

#ifndef __OP01_FWPBW__
    id_param.output_path = path;
#else
    if(path != AUDIO_DEVICE_SPEAKER_BOTH && g_audio_mode == AUD_MODE_LOUDSPK)
    {
        id_param.output_path = AUDIO_DEVICE_LOUDSPEAKER;
    }
    else
    {
        id_param.output_path = path;        
    }
#endif

    id_param.identifier = (U16) (identifier);
#endif /* __GAIN_TABLE_SUPPORT__ */

    /* Play ID */
    media_aud_play_id(MOD_MMI, &id_param);
    
    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_hdlr
 * DESCRIPTION
 *  This function is a general handler to process play string request
 * PARAMETERS
 *  audio_data      [IN]    Audio data
 *  len             [IN]    The length of audio data
 *  format          [IN]    Content format
 *  start_offset    [IN]    Start time
 *  end_offset      [IN]    End time
 *  play_style      [IN]    Play style
 *  handler         [IN]    Callback handler
 *  user_data       [IN]    User data
 *  volume          [IN]    Audio volume
 *  path            [IN]    Audio path
 *  blocking        [IN]    Indicate if process the request in blocking way
 * RETURNS
 *  mdi_result
 *****************************************************************************/
static mdi_result mdi_audio_play_string_hdlr(
            void *audio_data,
            U32 len,
            U8 format,
            U32 start_offset,
            U32 end_offset,
            U8 play_style,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path,
            MMI_BOOL blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_string_struct string_param;
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING_PORTION_WITH_VOL_PATH, format, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_PLAYBACK))
    {
        MDI_AUDIO_UNLOCK;
        return check_result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

#ifdef __BT_SPK_VOL_CONTROL__
   mdi_audio_set_volume_to_bt(volume);
#endif
    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

#ifdef __GAIN_TABLE_SUPPORT__
    g_media_source = mdi_audio_get_media_source_by_type((kal_int16)format);
    g_audio_path = path;
    g_crnt_volume[AUD_VOLUME_MEDIA] = volume;
#endif /* __GAIN_TABLE_SUPPORT__ */

    string_param.data_p = (U8*) audio_data;
    string_param.len = len;
    string_param.format = format;
    string_param.play_style = play_style;
    string_param.volume = mdi_audio_get_volume_per_play_style(AUD_VOLUME_MEDIA, volume, play_style);
    string_param.output_path = path;
    string_param.identifier = (U16) identifier;
    string_param.blocking = blocking;
    string_param.start_offset = start_offset;
    string_param.end_offset = end_offset;
    
    if ((result = media_aud_play_string(MOD_MMI, &string_param)) == MED_RES_OK)
    {
        mdi_cb_handler = handler;
        mdi_cb_data = user_data;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_STRING;
        SetProtocolEventHandler(mdi_audio_play_finish_ind, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_cb_handler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string
 * DESCRIPTION
 *  This function is to play audio string.
 * PARAMETERS
 *  audio_data      [IN] 
 *  len             [IN]        
 *  format          [IN]        
 *  play_style      [IN]               
 *  handler         [IN]   
 *  user_data       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_string(
            void *audio_data,
            U32 len,
            U8 format,
            U8 play_style,
            mdi_ext_callback handler,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING, format, mdi_audio_state);

    return mdi_audio_play_string_hdlr(
                audio_data,
                len,
                format,
                0,
                0,
                play_style,
                handler,
                user_data,
                (U8)srv_prof_get_ring_vol(),
                MDI_DEVICE_SPEAKER2,
                MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_with_vol_path
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      [IN] 
 *  len             [IN]        
 *  format          [IN]        
 *  play_style      [IN]               
 *  handler         [IN]    
 *  user_data       [IN]
 *  volume          [IN]
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_string_with_vol_path(
            void *audio_data,
            U32 len,
            U8 format,
            U8 play_style,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING_WITH_VOL_PATH, format, mdi_audio_state);

    return mdi_audio_play_string_hdlr(
                audio_data,
                len,
                format,
                0,
                0,
                play_style,
                handler,
                user_data,
                volume,
                path,
                MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_with_vol_path_non_block
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      [IN]
 *  len             [IN]        
 *  format          [IN]        
 *  play_style      [IN]             
 *  handler         [IN]   
 *  user_data       [IN]
 *  volume          [IN]
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_string_with_vol_path_non_block(
            void *audio_data,
            U32 len,
            U8 format,
            U8 play_style,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING_PORTION_WITH_VOL_PATH_NON_BLOCK, format, mdi_audio_state);

    return mdi_audio_play_string_hdlr(
                audio_data,
                len,
                format,
                0,
                0,
                play_style,
                handler,
                user_data,
                volume,
                path,
                MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_portion_with_vol_path
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      [IN]
 *  len             [IN]        
 *  format          [IN]        
 *  play_style      [IN]              
 *  handler         [IN]   
 *  user_data       [IN]
 *  volume          [IN]
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_string_portion_with_vol_path(
            void *audio_data,
            U32 len,
            U8 format,
            U32 start_offset,
            U32 end_offset,
            U8 play_style,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING_PORTION_WITH_VOL_PATH, format, mdi_audio_state);

    return mdi_audio_play_string_hdlr(
                audio_data,
                len,
                format,
                start_offset,
                end_offset,
                play_style,
                handler,
                user_data,
                volume,
                path,
                MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file
 * DESCRIPTION
 *  This function is to play audio file.
 * PARAMETERS
 *  file_name       [?]
 *  play_style      [IN]        
 *  cache_p         [IN]         
 *  handler         [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_file(void *file_name, U8 play_style, void *cache_p, mdi_ext_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FILE, mdi_audio_state);

    return mdi_audio_play_file_portion_with_vol_path(
            file_name,
            0,
            0,
            play_style,
            cache_p,
            handler,
            user_data,
            (U8)srv_prof_get_ring_vol(),
            MDI_DEVICE_SPEAKER2);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_with_vol_path
 * DESCRIPTION
 *  This function is to play audio file along with volume and output path.
 * PARAMETERS
 *  file_name       [IN]
 *  play_style      [IN]        
 *  cache_p         [IN]         
 *  handler         [IN]   
 *  user_data       [IN]
 *  volume          [IN]
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_file_with_vol_path(
            void *file_name,
            U8 play_style,
            void *cache_p,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FILE_WITH_VOL_PATH, mdi_audio_state);

    return mdi_audio_play_file_portion_with_vol_path(
            file_name,
            0,
            0,
            play_style,
            cache_p,
            handler,
            user_data,
            volume,
            path);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_portion_with_vol_path
 * DESCRIPTION
 *  This function is to play audio file portion with volume and output path.
 * PARAMETERS
 *  file_name           [IN]
 *  start_offset        [IN]        
 *  end_offset          [IN]        
 *  play_style          [IN]        
 *  cache_p             [IN]         
 *  handler             [IN]
 *  volume              [IN]        
 *  path                [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_file_portion_with_vol_path(
            void *file_name,
            U32 start_offset,
            U32 end_offset,
            U8 play_style,
            void *cache_p,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_file_struct file_param;
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FILE_PORTION_WITH_VOL_PATH, mdi_audio_state, start_offset,end_offset,cache_p);

    check_result = mdi_audio_play_file_check_state((U16*)file_name, MDI_AUDIO_CHECK_REASON_PLAYBACK);
    if(check_result != MDI_AUDIO_SUCCESS)
    {
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return check_result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_set_volume_to_bt(volume);
#endif
    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

#ifdef __GAIN_TABLE_SUPPORT__
    g_media_source = mdi_audio_get_media_source_by_type(med_get_media_type(file_name));
    g_audio_path = path;
    g_crnt_volume[AUD_VOLUME_MEDIA] = volume;
#endif /* __GAIN_TABLE_SUPPORT__ */
    
    file_param.file_name_p = (UI_string_type) file_name;
    file_param.play_style = play_style;
    file_param.volume = mdi_audio_get_volume_per_play_style(AUD_VOLUME_MEDIA, volume, play_style);
    file_param.output_path = path;
    file_param.identifier = (U16) identifier;
    file_param.start_offset = start_offset;
    file_param.end_offset = end_offset;
    file_param.cache_p = cache_p;
    if ((result = media_aud_play_file(MOD_MMI, &file_param)) == MED_RES_OK)
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_right((U16*)file_name, 0, &mdi_audio_drm_id, mdi_audio_drm_timeout_callback);
#endif /*__DRM_SUPPORT__*/

        mdi_cb_handler = handler;
        mdi_cb_data = user_data;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FILE;
        SetProtocolEventHandler(mdi_audio_play_finish_ind1, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND);
        SetProtocolEventHandler(mdi_audio_update_dur_ind, MSG_ID_L4AUD_MEDIA_UPDATE_DUR_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL; /* Clear this flag for each consume request */
#endif /*__DRM_SUPPORT__*/

        mdi_cb_handler = NULL;
        updateDurHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_pause
 * DESCRIPTION
 *  This function is to pause audio play/record.
 * PARAMETERS
 *  handler             [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_pause(mdi_ext_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PAUSE, mdi_audio_state);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_reset_connection_timer();
#endif

    if ((result = media_aud_pause(kal_get_active_module_id(), SRC_LMMI)) == MED_RES_OK)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY)
        {
        #ifdef __DRM_SUPPORT__
            if(mdi_audio_drm_id >= 0)
            {
                DRM_pause_consume(mdi_audio_drm_id);
            }                
        #endif /*__DRM_SUPPORT__*/
            mdi_audio_state = MDI_AUDIO_PLAY_PAUSED;
        }
        else if(mdi_audio_state == MDI_AUDIO_RECORD)
        {
            mdi_audio_state = MDI_AUDIO_RECORD_PAUSED;
        }
        else
        {
            /* Do nothing */
        }
        mdi_cb_handler = handler;
        mdi_cb_data = user_data;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else if (result == MED_RES_UNSUPPORTED_OPERATION)
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_UNSUPPORTED_OPERATION;
    }
    else
    {
        mdi_cb_handler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume
 * DESCRIPTION
 *  This function is to resume audio play/record.
 * PARAMETERS
 *  handler             [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_resume(mdi_ext_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESUME, mdi_audio_state);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

    if ((result = media_aud_resume(kal_get_active_module_id(), SRC_LMMI)) == MED_RES_OK)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
        {
        #ifdef __DRM_SUPPORT__
            if(mdi_audio_drm_id >= 0)
            {
                DRM_resume_consume(mdi_audio_drm_id);
            }
        #endif /*__DRM_SUPPORT__*/
            mdi_audio_state = MDI_AUDIO_PLAY;
        }
        else if (mdi_audio_state == MDI_AUDIO_RECORD_PAUSED)
        {
            mdi_audio_state = MDI_AUDIO_RECORD;
        }
        else
        {
            /* Do nothing */
        }
        mdi_cb_handler = handler;
        mdi_cb_data = user_data;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        if(mdi_audio_state != MDI_AUDIO_PLAY && mdi_audio_state != MDI_AUDIO_RECORD)
        {
            mdi_cb_handler = NULL;
            mdi_audio_state = MDI_AUDIO_IDLE;
            mdi_audio_start_background_timer();
        }
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_id
 * DESCRIPTION
 *  This function is to stop audio id.
 * PARAMETERS
 *  audio_id        [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_id(U16 audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_ID, audio_id, mdi_audio_state, mdi_audio_mode);

    media_aud_stop_id(MOD_MMI, (U8) audio_id);

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_string
 * DESCRIPTION
 *  This function is to stop audio string.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_STRING, mdi_audio_state, mdi_audio_mode);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_reset_connection_timer();
#endif

    if (!((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
          && mdi_audio_mode == MDI_AUDIO_PLAY_STRING))
    {
    #if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
        if (mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_IDLE_STATE)
    #endif
        {
            MDI_AUDIO_UNLOCK;
            return MDI_AUDIO_SUCCESS;
        }
    }

    /* Stop crescendo timer */
    mdi_audio_stop_crescendo_timer();

    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND);
    media_aud_stop_string(MOD_MMI, SRC_LMMI);

    if (mdi_cb_handler)
    {
        tmp_cb_handler = mdi_cb_handler;
        mdi_cb_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
    }
    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_file
 * DESCRIPTION
 *  This function is to stop audio file.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_FILE, mdi_audio_state, mdi_audio_mode);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_reset_connection_timer();
#endif

    mdi_audio_stop_crescendo_timer();

#ifdef __DRM_SUPPORT__
    if(mdi_audio_drm_id >= 0)
    {
        DRM_stop_consume(mdi_audio_drm_id);
        mdi_audio_drm_id = -1;
    }
#endif /*__DRM_SUPPORT__*/

    /*
     * set pseudo play file callback to NULL before callback
     * bcoz we could set another callback during callback
     */
    if (pseudo_play_handler)
    {
        tmp_cb_handler = pseudo_play_handler;
        pseudo_play_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, pseudo_play_data);
    }

    if (!((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
          && mdi_audio_mode == MDI_AUDIO_PLAY_FILE))
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }

    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND);
    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_MEDIA_UPDATE_DUR_IND);
    media_aud_stop_file(MOD_MMI, SRC_LMMI);
	mdi_audio_state = MDI_AUDIO_IDLE;

    if (mdi_cb_handler)
    {
        tmp_cb_handler = mdi_cb_handler;
        mdi_cb_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
    }
    updateDurHandler = NULL;

    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_all
 * DESCRIPTION
 *  This function is to stop all audio id/string/file.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_ALL, mdi_audio_state, mdi_audio_mode);

    /* Stop crescendo timer */
    mdi_audio_stop_crescendo_timer();
#ifdef __MMI_HF_SUPPORT__
    srv_btsco_dialer_stop_single_sco();
#endif /* __MMI_HF_SUPPORT__ */
    
    /*
     * set pseudo play file callback to NULL before callback
     * bcoz we could set another callback during callback
     */
    if (pseudo_play_handler)
    {
        tmp_cb_handler = pseudo_play_handler;
        pseudo_play_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, pseudo_play_data);
    }
    if (interrupt_cb_handler)
    {
        tmp_cb_handler = interrupt_cb_handler;
        interrupt_cb_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, interrupt_cb_data);
    }
    
#ifdef __AUDIO_TRIM_SUPPORT__    
    if (g_trim_cb)
    {
        mdi_audio_trim_interrupt();
    }
#endif /* __AUDIO_TRIM_SUPPORT__ */
    
    // to avoid the case that play finish indication of previous request is treat as the one of current request
    //if (mdi_audio_state!=MDI_AUDIO_IDLE)
    {
        switch (mdi_audio_mode)
        {
            case MDI_AUDIO_PLAY_ID:
                mdi_audio_stop_id(0);
                break;
            case MDI_AUDIO_PLAY_STRING:
                mdi_audio_stop_string();
                break;
            case MDI_AUDIO_PLAY_FILE:
                mdi_audio_stop_file();
                break;
            case MDI_AUDIO_RECORD_FILE:
				#ifdef __MMI_HF_SUPPORT__
				if(!srv_bt_dialer_is_in_call())
				#endif
                    mdi_audio_stop_record();
                break;
            case MDI_AUDIO_PLAY_FM_RADIO:
            case MDI_AUDIO_RECORD_FM_RADIO:
                mdi_audio_stop_fmr();
                break;
        #ifdef VR_ENABLE
            case MDI_AUDIO_RECORD_VR_VOICE:
                if (mdi_audio_state == MDI_AUDIO_RECORD)
                {
                    mdi_audio_stop_vr_voice_record();
                }
                break;
        #endif /* VR_ENABLE */ 
        #ifdef VRSI_ENABLE
            case MDI_AUDIO_VRSI_PLAY_TTS:
            case MDI_AUDIO_VRSI_PLAY_TAG:
            case MDI_AUDIO_VRSI_RECORD:
                if (mdi_audio_state == MDI_AUDIO_VRSI_PROCESS)
                {
                    mdi_audio_vrsi_stop(g_mdi_vrsi_session);
                }
                break;
        #endif /* VRSI_ENABLE */ 
        #ifdef __GENERAL_TTS__
            case MDI_AUDIO_PLAY_TTS:
                mdi_audio_tts_stop();
                break;
        #endif /* __GENERAL_TTS__ */
        #if defined(__J2ME__)
            case MDI_AUDIO_PLAY_IN_OTHER_TASK:
                mdi_audio_terminate_use_by_other_task();
                break;
        #endif /* #if defined(__J2ME__)*/
            default:
                break;

        }

    }
    
    /* Close all the mma handlers */
    mdi_audio_mma_close_all();

    MDI_AUDIO_UNLOCK;    
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_store_file
 * DESCRIPTION
 *  This function is to store audio play state for restore it later
 * PARAMETERS
 *  audio_handle        [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_store_file(mdi_handle audio_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STORE_FILE, mdi_audio_state);

    /* Stop crescendo timer */
    mdi_audio_stop_crescendo_timer();
    
    if ((result = media_aud_store(MOD_MMI, SRC_LMMI)) == MED_RES_OK)
    {
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_restore_file_with_vol_path
 * DESCRIPTION
 *  This function is to restore audio file along with volume and output path.
 * PARAMETERS
 *  file_name       [IN]
 *  play_style      [IN]              
 *  handler         [IN]    
 *  user_data       [IN]
 *  volume          [IN]
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_restore_file_with_vol_path(
            void *file_name,
            U8 play_style,
            void *cache_p,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_file_struct file_param;
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESTORE_FILE_WITH_VOL_PATH, mdi_audio_state);

#ifdef __DRM_SUPPORT__
    /* Do not consume count in restore action */
    mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_TIME_ONLY;
#endif
    check_result = mdi_audio_play_file_check_state((U16*)file_name, MDI_AUDIO_CHECK_REASON_PLAYBACK);
    if(check_result != MDI_AUDIO_SUCCESS)
    {
        MDI_AUDIO_UNLOCK;    
        return check_result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_set_volume_to_bt(volume);
#endif
    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

#ifdef __GAIN_TABLE_SUPPORT__
    g_media_source = mdi_audio_get_media_source_by_type(med_get_media_type(file_name));
    g_audio_path = path;
    g_crnt_volume[AUD_VOLUME_MEDIA] = volume;
#endif /* __GAIN_TABLE_SUPPORT__ */

    file_param.file_name_p = (UI_string_type) file_name;
    file_param.play_style = play_style;
    file_param.volume = mdi_audio_get_volume_per_play_style(AUD_VOLUME_MEDIA, volume, play_style);
    file_param.output_path = path;
    file_param.identifier = (U16) identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    file_param.start_offset = file_param.end_offset = 0;
    file_param.cache_p = cache_p;
    if ((result = media_aud_restore(MOD_MMI, &file_param)) == MED_RES_OK)
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_right((U16*)file_name, 0, &mdi_audio_drm_id, mdi_audio_drm_timeout_callback);
#endif /*__DRM_SUPPORT__*/

        mdi_cb_handler = handler;
        mdi_cb_data = user_data;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FILE;
        SetProtocolEventHandler(mdi_audio_play_finish_ind1, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND);
        SetProtocolEventHandler(mdi_audio_update_dur_ind, MSG_ID_L4AUD_MEDIA_UPDATE_DUR_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL; /* Clear this flag for each consume request */
#endif /*__DRM_SUPPORT__*/

        mdi_cb_handler = NULL;
        updateDurHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_finish_ind
 * DESCRIPTION
 *  This function is to handle the play finish indication for id and string.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_play_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_play_finish_ind_struct *msg_p = (media_aud_play_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FINISH_IND, mdi_audio_state);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_reset_connection_timer();
#endif

    /* Stop crescendo timer */
    mdi_audio_stop_crescendo_timer();
    
    if ((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
        && msg_p->identifier == identifier)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            mdi_cb_handler = NULL;
            tmp_cb_handler(mdi_audio_get_event(msg_p->result), mdi_cb_data);        /* mdi_audio_play_text handler could set mdi_cb_handler to itself here */
        }
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_finish_ind1
 * DESCRIPTION
 *  This function is to handle the play finish indication for file.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_play_finish_ind1(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_play_finish_ind_struct *msg_p = (media_aud_play_finish_ind_struct*) inMsg;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FINISH_IND1, mdi_audio_state);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_reset_connection_timer();
#endif

    /* Stop crescendo timer */
    mdi_audio_stop_crescendo_timer();
    
#ifdef __DRM_SUPPORT__
    if(mdi_audio_drm_id >= 0)
    {
        DRM_stop_consume(mdi_audio_drm_id);
        mdi_audio_drm_id = -1;
    }
#endif /*__DRM_SUPPORT__*/

    if ((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
        && msg_p->identifier == identifier)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;        
        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            mdi_cb_handler = NULL;
            tmp_cb_handler(mdi_audio_get_event(msg_p->result), mdi_cb_data);
        }
        mdi_audio_start_background_timer();
        
        updateDurHandler = NULL;
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_regisiter_auto_update_duration_handler
 * DESCRIPTION
 *  This function is to regisiter auto update time duration
 * PARAMETERS
 * handler     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_regisiter_auto_update_duration_handler(void(*handler)(U32 duration))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    updateDurHandler = handler;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_update_dur_ind
 * DESCRIPTION
 *  This function is to handle the update duration indication.
 * PARAMETERS
 *  inMsg       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_update_dur_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_play_update_dur_ind_struct *msg_p = (l4aud_media_play_update_dur_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_UPDATE_DUR_IND, msg_p->duration,msg_p->identifier,identifier);
    if ( updateDurHandler != NULL && msg_p->identifier == identifier)
    {       
        updateDurHandler(msg_p->duration);
    }
}

#ifdef __VIBRATION_SPEAKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vib_spk_calibration
 * DESCRIPTION
 *  This function is to enabled vibration speaker current sensor 
 * PARAMETERS
 *  mdi_callback      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void mdi_audio_vib_spk_calibration(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_vib_spk_calibration(MOD_MMI);	
    SetProtocolEventHandler(handler, MSG_ID_L4AUD_VIB_SPK_CALIBRATION_IND);	
    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_vibrator_enabled
 * DESCRIPTION
 *  This function is to set vibrator enabled
 * PARAMETERS
 *  enable      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_set_vibrator_enabled(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_set_vibrator_enabled(MOD_MMI, (kal_uint8) enable);
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_progress_time
 * DESCRIPTION
 *  This function is to seek file playing offset when it's playing a file.
 * PARAMETERS
 *  progress        [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_set_progress_time(U32 progress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FILE)
    {
        result = media_aud_set_progress_time(MOD_MMI, progress);
    }
    else
    {
        result = MED_RES_FAIL;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SET_PROGRESS_TIME, result, progress);

    MDI_AUDIO_UNLOCK;
    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_duration
 * DESCRIPTION
 *  This function is to get the duration of a audio file.
 * PARAMETERS
 *  file_name       [IN]     NULL means using current play file handler to update time
 *                           (only for need build cache file type)
 *                           Otherwise, open file and call GetContentDescInfo
 *  time_p          [OUT]    (milliseconds)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_duration(void *file_name, U32 *time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = media_aud_get_duration(MOD_MMI, file_name, NULL, 0, 0, time_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_DURATION, result, *time_p);

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_mp4_duration
 * DESCRIPTION
 *  This function is to get the total duration of a mp4 file, it will return longer
 *  time in audio or video track.
 * PARAMETERS
 *  file_name       [IN]     NULL means using current play file handler to update time
 *                           (only for need build cache file type)
 *                           Otherwise, open file and call GetContentDescInfo
 *  time_p          [OUT]    (milliseconds)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_mp4_duration(void *file_name, U32 *time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = media_aud_get_mp4_duration(MOD_MMI, file_name, NULL, 0, 0, time_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_DURATION, result, *time_p);

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_duration_by_string
 * DESCRIPTION
 *  This function is to get the duration of a audio file.
 * PARAMETERS
 *  time_p          [OUT]    (milliseconds)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_duration_by_string(kal_uint8 *audio_data, U32 len, U8 format, U32 *time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = media_aud_get_duration(MOD_MMI, NULL, audio_data, len, format, time_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_DURATION_BY_STRING, result, *time_p);

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_progress_time
 * DESCRIPTION
 *  This function is to get the progress of file playing
 * PARAMETERS
 *  progress        [?]     
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_progress_time(U32 *progress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if ((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED) &&
        (mdi_audio_mode == MDI_AUDIO_PLAY_FILE || mdi_audio_mode == MDI_AUDIO_PLAY_STRING))
    {
        result = media_aud_get_progress_time(MOD_MMI, progress);
    }
    else
    {
        result = MED_RES_FAIL;
        *progress = 0;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_PROGRESS_TIME, result, *progress);

    MDI_AUDIO_UNLOCK;
    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_midi_size_limit
 * DESCRIPTION
 *
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mdi_audio_get_midi_size_limit(void)
{
#ifndef MED_NOT_PRESENT
    return AUD_MELODY_BUFFER_LEN;
#else
    return 500;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_size_limit
 * DESCRIPTION
 *
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mdi_audio_get_size_limit(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (type == MDI_FORMAT_SMF)
    {
#ifndef MED_NOT_PRESENT
    #ifdef MIDFILE_PLAY_SUPPORT
        return AUD_MIDI_FILE_SIZE;
    #else
        return AUD_MELODY_BUFFER_LEN;
    #endif /* MIDFILE_PLAY_SUPPORT */
#else
        return 500;
#endif /* MED_NOT_PRESENT */
    }
    else if (type == MDI_FORMAT_IMELODY)
    {
#ifndef MED_NOT_PRESENT
        return AUD_MELODY_BUFFER_LEN;
#else
        return 500;
#endif /* MED_NOT_PRESENT */
    }

    return 500;
}


/*-----------------------------------------------------------------------------
                                     Seek
 ----------------------------------------------------------------------------*/

#ifndef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_seek_callback
 * DESCRIPTION
 *  This function is the seek callback function which will be invoked directly
 *  by the MED task when the seeking is done/terminated. We have to do context
 *  switch to MMI task before calling back to the MMI.
 * PARAMETERS
 *  reason      : [IN] Seek done reason
 *  user_data   : [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_seek_callback_hdlr(void *msg_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_audio_seek_done_ind_struct *ind_p = (media_audio_seek_done_ind_struct*)msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Callback to the MMI */
    if (g_seek_cb_fct)
    {
        g_seek_cb_fct(ind_p->reason, ind_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_seek_callback
 * DESCRIPTION
 *  This function is the seek callback function which will be invoked directly
 *  by the MED task when the seeking is done/terminated. We have to do context
 *  switch to MMI task before calling back to the MMI.
 * PARAMETERS
 *  reason      : [IN] Seek done reason
 *  user_data   : [IN] User data
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_seek_callback(kal_uint8 reason, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_audio_seek_done_ind_struct *ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ind_p = (media_audio_seek_done_ind_struct*)
        construct_local_para(sizeof(media_audio_seek_done_ind_struct), TD_CTRL);
    ind_p->reason = reason;
    ind_p->user_data = user_data;
    
    mdi_send_msg(MOD_MMI, MSG_ID_MEDIA_AUDIO_SEEK_DONE_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_seek
 * DESCRIPTION
 *  This function is to seek to a given start time
 * PARAMETERS
 *  file_name   : [IN] File name
 *  cache_table : [IN] Cache table
 *  table_size  : [IN] Size of cache table
 *  start_time  : [IN] Start time
 *  cb_fct      : [IN] Callback function
 *  cb_data     : [IN] Client data which will be brought back in the callback
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_start_seek(void* file_name, void* cache_table, U32 table_size, U32 start_time, mdi_seek_callback cb_fct, void* cb_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    
#if !defined(MED_V_NOT_PRESENT)

    g_seek_cb_fct = cb_fct;

    SetProtocolEventHandler(mdi_audio_seek_callback_hdlr, MSG_ID_MEDIA_AUDIO_SEEK_DONE_IND);

    media_aud_start_seek(kal_get_active_module_id(),
                         file_name,
                         cache_table,
                         table_size,
                         start_time,
                         mdi_audio_seek_callback,
                         cb_data);
#else
    if (cb_fct)
    {
        cb_fct(AUD_SEEK_REASON_DONE, cb_data);
    }
#endif /* ! MED_V_NOT_PRESENT */

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_seek
 * DESCRIPTION
 *  This function is to stop the seeking process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_stop_seek(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    
#if defined(__MTK_TARGET__) && !defined(MED_V_NOT_PRESENT)
    g_seek_cb_fct = NULL;
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUDIO_SEEK_DONE_IND);
    media_aud_stop_seek(kal_get_active_module_id());
#endif /* __MTK_TARGET__ && ! MED_V_NOT_PRESENT */

    MDI_AUDIO_UNLOCK;
}
#endif /*__PLUTO_MMI_PACKAGE__*/

/*-----------------------------------------------------------------------------
                                  Build Cache
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_build_cache
 * DESCRIPTION
 *  This function is to start build cache
 * PARAMETERS
 *  filename        [IN]
 *  cache_p         [IN]
 *  cache_size      [IN]
 *  file_buf_p      [IN]
 *  file_buf_size   [IN]
 *  proc_buf_p      [IN]
 *  proc_buf_size   [IN]
 *  handler         [IN]    call back hanlder when build cache fail
 *  build_cache_progress    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_start_build_cache(
            kal_wchar *filename,
            U8 *cache_p, 
            U32 cache_size,
            U8 *file_buf_p,
            U32 file_buf_size,
            U8 *proc_buf_p,
            U32 proc_buf_size,
            void (*handler)(void*),
            U32 *build_cache_progress)
{
#ifndef MED_V_NOT_PRESENT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_audio_cache_req_struct *cache_parm = (media_visual_audio_cache_req_struct*)
           construct_local_para(sizeof(media_visual_audio_cache_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //MDI_ASSERT(file_buf_p!=NULL);
    //MDI_ASSERT(proc_buf_p!=NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_BUILD_CACHE);

    cache_parm->filename = filename;
    cache_parm->cache_p = cache_p;
    cache_parm->cache_size = cache_size ;
    cache_parm->file_buf_p = file_buf_p;
    cache_parm->file_buf_size = file_buf_size;
    cache_parm->proc_buf_p = proc_buf_p ;
    cache_parm->proc_buf_size = proc_buf_size;
    cache_parm->build_cache_progress = build_cache_progress ;

    media_aud_start_build_cache(MOD_MMI,cache_parm);
    SetProtocolEventHandler(handler, MSG_ID_MEDIA_AUDIO_BUILD_CACHE_FAIL_IND);
#endif
    return;
    
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_build_cache
 * DESCRIPTION
 *  This function is to stop build cache
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_stop_build_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_BUILD_CACHE);
    aud_send_stop_build_cache_req(MOD_MMI);
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_close_build_cache
 * DESCRIPTION
 *  This function is to close build cache
 * PARAMETERS
 *
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_close_build_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CLOSE_BUILD_CACHE);
    media_aud_close_build_cache(MOD_MMI);
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to reset build cache variables
 * PARAMETERS
 *
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_reset_build_cache_variables()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESET_BUILD_CACHE_VAR);
    media_aud_reset_build_cache_variables(MOD_MMI);
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_build_cache_get_cache_duration
 * DESCRIPTION
 *  This function is to get current cached duration
 * PARAMETERS
 * duration_p     [OUT]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_build_cache_get_cache_duration(kal_uint32 *duration_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    if(medv_audio_get_cache_duration(duration_p))
    {
        return MMI_TRUE;
    }
    else
#endif
    {
        return MMI_FALSE;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to get total duration from build cache
 * PARAMETERS
 * duration_p     [OUT]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_build_cache_get_total_duration(kal_uint32 *duration_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    if(medv_audio_get_total_duration(duration_p))
    {
        return MMI_TRUE;
    }
    else
#endif
    {
        return MMI_FALSE;
    }
    
}


/*-----------------------------------------------------------------------------
                                  Recorder
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_record_time
 * DESCRIPTION
 *  This function is to get current record time.
 * PARAMETERS
 *  void
 * RETURNS
 *  Total record time (in milliseconds)
 *****************************************************************************/
U32 mdi_audio_get_record_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(AUD_REC_ENABLE)
    return Media_GetRecordedTime();
#else
    return 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_record_intensity
 * DESCRIPTION
 *  This function is to get mic intensity when record.
 * PARAMETERS
 *  channel   :[IN]  first mic or second mic
 * RETURNS
 *  strength: 
 *****************************************************************************/

U32 mdi_audio_get_record_intensity(U32 channel)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U32 strength = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__AUD_REC_INTENSITY__)
	if(mdi_audio_state==MDI_AUDIO_RECORD)
	{
		media_get_record_intensity(channel,&strength);		
		return strength; 	
    }
	else 
	#endif
	{
		return 0;
	}	
	
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_record_intensity_max_min_value
 * DESCRIPTION
 *  This function is to get mic intensity when record.
 * PARAMETERS
 *  max_value   :[IN]  the point of max_value of mic
 *  min_value   :[IN]  the point of min_value of mic
 * RETURNS
 *  succes or fail: 
 *****************************************************************************/

void mdi_audio_get_record_intensity_limit(U32* max_value,U32* min_value)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if defined(__AUD_REC_INTENSITY__)
		media_get_record_intensity_limit(max_value,min_value);
	#else 
	    *max_value=0;
	    *min_value=0;
	#endif
 
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_estimated_record_byte_rate
 * DESCRIPTION
 *  This function is to estimate record byte rate for a given mode, format and quality.
 * PARAMETERS
 *  mode            : [IN] Record mode
 *  format          : [IN] Record format
 *  quality         : [IN] Record quality (MDI_AUDIO_REC_QUALITY_ENUM)
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 mdi_audio_get_estimated_record_byte_rate(
            MDI_AUDIO_REC_MODE_ENUM mode,
            MDI_FORMAT_ENUM format,
            MDI_AUDIO_REC_QUALITY_ENUM quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(AUD_REC_ENABLE)
    return aud_rec_get_estimated_record_byte_rate(mode, format, quality);
#else
    return 0;
#endif


}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_record_param
 * DESCRIPTION
 *  This function is to get record parameters for a given record profile.
 * PARAMETERS
 *  mode            : [IN] Record mode
 *  quality         : [IN] Record quality (MDI_AUDIO_REC_QUALITY_ENUM)
 *  param_p         : [OUT] Record parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_get_record_param(
            MDI_AUDIO_REC_MODE_ENUM mode,
            MDI_AUDIO_REC_QUALITY_ENUM quality,
            mdi_audio_rec_param_struct* param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(AUD_REC_ENABLE)
    aud_rec_get_record_param(mode, quality, param_p);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_record
 * DESCRIPTION
 *  This function is to start audio record.
 * PARAMETERS
 *  file_name       [IN]
 *  format          [IN]       
 *  quality         [IN]      
 *  handler         [IN]      
 *  user_data       [IN]
 * RETURNS
 *  mdi_handle
 *****************************************************************************/
mdi_result mdi_audio_start_record(void *file_name, U8 format, U8 quality, mdi_ext_callback handler, void *user_data)
{
    return mdi_audio_start_record_with_limit(file_name, format, quality, handler, user_data, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_record_with_limit
 * DESCRIPTION
 *  This function is to start audio record.
 * PARAMETERS
 *  file_name       [IN]
 *  format          [IN]           
 *  handler         [IN]        
 *  user_data       [IN]
 *  size_limit      [IN]        Max record size in byte.   0: Unlimited
 *  time_limit      [IN]        Max record time in second. 0: Unlimited
 * RETURNS
 *  mdi_handle
 *****************************************************************************/
mdi_result mdi_audio_start_record_with_limit(void *file_name, U8 format, U8 quality, mdi_ext_callback handler, void *user_data, U32 size_limit, U32 time_limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_RECORD_WITH_LIMIT, mdi_audio_state, size_limit, time_limit);

    if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_SND_RECORD))
    {
        MDI_AUDIO_UNLOCK;
        return check_result;
    }

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

    mdi_audio_stop_background_timer();

#ifdef __GAIN_TABLE_SUPPORT__
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_RECORD_STATE_CHANGED, (void*)TRUE);
#endif /* __GAIN_TABLE_SUPPORT__ */

    if ((result = media_aud_start_record(kal_get_active_module_id(), (kal_wchar*) file_name, format, quality, TRUE, 0, size_limit, time_limit)) == MED_RES_OK)
    {
        mdi_cb_handler = handler;
        mdi_cb_data = user_data;
        mdi_audio_state = MDI_AUDIO_RECORD;
        mdi_audio_mode = MDI_AUDIO_RECORD_FILE;
        SetProtocolEventHandler(mdi_audio_record_finish_ind, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_cb_handler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_record_finish_ind
 * DESCRIPTION
 *  This function is to handle audio record finish indication.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_record_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_finish_ind_struct *msg_p = (l4aud_media_record_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RECORD_FINISH_IND, mdi_audio_state);
    if (mdi_audio_state == MDI_AUDIO_RECORD ||
        mdi_audio_state == MDI_AUDIO_RECORD_PAUSED)
    {
    #ifdef __GAIN_TABLE_SUPPORT__
        mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_RECORD_STATE_CHANGED, (void*)FALSE);
    #endif /* __GAIN_TABLE_SUPPORT__ */
        
        mdi_audio_state = MDI_AUDIO_IDLE;
        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            mdi_cb_handler = NULL;
            tmp_cb_handler(mdi_audio_get_event(msg_p->result), mdi_cb_data);
        }
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_record
 * DESCRIPTION
 *  This function is to stop audio record.
 * PARAMETERS
 *  void
 *  void* inMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_RECORD, mdi_audio_state);

    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND);
    media_aud_stop_record(kal_get_active_module_id(), SRC_LMMI);

#ifdef __GAIN_TABLE_SUPPORT__
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_RECORD_STATE_CHANGED, (void*)FALSE);
#endif /* __GAIN_TABLE_SUPPORT__ */

    mdi_audio_state = MDI_AUDIO_IDLE;
    if (mdi_cb_handler)
    {
        tmp_cb_handler = mdi_cb_handler;
        mdi_cb_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
    }

    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}



/*-----------------------------------------------------------------------------
                              Interrupt Handler
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_register_interrupt_callback()
 * DESCRIPTION
 *  Register mdi audio interrupt callback. Application will receive callback
 *  when mdi audio recive a new play request or stop requst
 *
 *  !!!Be sure to clear this hanlder when not used. Only one instance currently
 *   
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_register_interrupt_callback(mdi_ext_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_REG_INT_CALLBACK, mdi_audio_state);

    /* Only allow one application in a time */
    MDI_ASSERT(interrupt_cb_handler == NULL);

    mdi_audio_stop_background_timer();
    interrupt_cb_handler = handler;
    interrupt_cb_data = user_data;

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_interrupt_callback()
 * DESCRIPTION
 *  clear interrupt callback handler
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mdi_audio_clear_interrupt_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CLEAR_INT_CALLBACK);

    interrupt_cb_handler = NULL;
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_pseudo_play_file_callback
 * DESCRIPTION
 *  This function is to set the interrupt handler such that it will be called back
 *  before a audio play file, stop file or record action take place
 * PARAMETERS
 *  callback      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_pseudo_play_file_callback(mdi_ext_callback callback, void *user_data)
{
    pseudo_play_handler = callback;
    pseudo_play_data = user_data;
}

#if (defined(__MMI_FTO_PIANO__) || defined(__J2ME__))
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_able_to_use_by_other_task()
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mdi_audio_is_able_to_use_by_other_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    if (!mdi_audio_is_in_call() &&
        (mdi_audio_is_idle() || (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_IN_OTHER_TASK)) &&
    #if defined(BGSND_ENABLE)
        mdi_audio_snd_is_idle() &&
    #endif
        mdi_audio_mma_is_idle())
    {
        MDI_AUDIO_UNLOCK;
        return MMI_TRUE;
    }

    MDI_AUDIO_UNLOCK;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_use_by_other_task()
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mdi_audio_start_use_by_other_task(mdi_ext_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_USE_BY_OTHER_TASK, mdi_audio_state);

    mdi_audio_stop_background_timer();

    mdi_audio_state = MDI_AUDIO_PLAY;
    mdi_audio_mode = MDI_AUDIO_PLAY_IN_OTHER_TASK;
    mdi_cb_handler = handler;
    mdi_cb_data = user_data;
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_use_by_other_task()
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mdi_audio_stop_use_by_other_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_USE_BY_OTHER_TASK);

    mdi_cb_handler = NULL;
    mdi_audio_state = MDI_AUDIO_IDLE;

    mdi_audio_start_background_timer();
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_terminate_use_by_other_task
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_terminate_use_by_other_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TERMINATE_USE_BY_OTHER_TASK);

    if (mdi_cb_handler)
    {
        tmp_cb_handler = mdi_cb_handler;
        mdi_cb_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
    }
    mdi_audio_state = MDI_AUDIO_IDLE;
    MDI_AUDIO_UNLOCK;
}
#endif /* #if __MMI_FTO_PIANO__ || __J2ME__ */

/*-----------------------------------------------------------------------------
                           Background Play Handler
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_background_timer
 * DESCRIPTION
 *  This function is to start timer for background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_start_background_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (!mdi_audio_is_background_play_suspended() && !mdi_audio_is_in_call())
    {
        StartTimer(TIMER_PROFILES_ALERT_PLAY, 3000, mdi_audio_background_timeout_handler);
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_background_timer
 * DESCRIPTION
 *  This function is to stop timer for background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_stop_background_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TIMER_PROFILES_ALERT_PLAY);
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_background_timeout_handler
 * DESCRIPTION
 *  This function is to handle background timeout.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_background_timeout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BG_TIMEOUT, mdi_audio_state, mdi_speech_session_on);

    if (mdi_audio_is_background_play_suspended() || (! mdi_audio_is_idle()) || mdi_audio_is_in_call())
    {
        MDI_AUDIO_UNLOCK;
        return;
    }

    /* Only callback the first background handler */
    if (background_handler.handler[0])
    {
        if (!background_handler.handler[0] (MDI_AUDIO_RESUME, background_handler.user_data[0]))
        {
            /* If application does not use background play, it shall deregister the handler */
            ASSERT(0);
        }
    }

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume_background_play
 * DESCRIPTION
 *  This function is to resume background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_resume_background_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESUME_BG_PLAY, mdi_audio_state);
    backgroud_enabled = MMI_TRUE;
    mdi_audio_start_background_timer();
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_terminate_background_play
 * DESCRIPTION
 *  This function is to terminate background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_terminate_background_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TERMINATE_BG_PLAY, mdi_audio_state);

    if(srv_ucm_query_call_count((SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE), SRV_UCM_CALL_TYPE_ALL, NULL) == 0 )
    {
        mdi_audio_stop_all();
    }

    /* clear all the background handlers */
    for (i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
    {
        if (background_handler.handler[i] != NULL)
        {
            background_handler.handler[i](MDI_AUDIO_TERMINATED, background_handler.user_data[i]);
        }

        background_handler.app[i] = MDI_BACKGROUND_APP_TOTAL;
        background_handler.handler[i] = NULL;
        background_handler.user_data[i] = NULL;
    }
    
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play
 * DESCRIPTION
 *  This function is to suspend background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_suspend_background_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SUSPEND_BG_PLAY, mdi_audio_state);
    backgroud_enabled = MMI_FALSE;

    if(srv_ucm_query_call_count((SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE), SRV_UCM_CALL_TYPE_ALL, NULL) == 0 )
    {
        mdi_audio_stop_all();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume_background_play
 * DESCRIPTION
 *  This function is to resume background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_APP app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESUME_BG_PLAY_APP, app_id);
    g_mdi_aud_suspend_app[app_id/8] &= ~(1 << (app_id%8));
    mdi_audio_start_background_timer();
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play_by_app
 * DESCRIPTION
 *  This function is to suspend background play by application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_APP app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MDI_AUD_SUSPEND_BG_APP selected_id = app_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SUSPEND_BG_PLAY_APP, app_id);

    /* Find a handle for the anonymous app */
    if (app_id == MDI_AUD_SUSPEND_BG_ANON_APP)
    {
        for (i = 0; i < MDI_MAX_ANON_APP_NUM; i ++)
        {
            if ((g_mdi_aud_suspend_app[(MDI_AUD_SUSPEND_BG_ANON_APP+i)/8] & (1 << ((MDI_AUD_SUSPEND_BG_ANON_APP+i)%8))) == 0)
            {
                selected_id = (MDI_AUD_SUSPEND_BG_APP)(MDI_AUD_SUSPEND_BG_ANON_APP + i);
                break;
            }
        }

        /* Assert there is handle available */
        MDI_ASSERT(i < MDI_MAX_ANON_APP_NUM);
    }
    
    g_mdi_aud_suspend_app[selected_id/8] |= (1 << (selected_id%8));

    if( (app_id == MDI_AUD_SUSPEND_BG_UCM) || (srv_ucm_query_call_count((SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE), SRV_UCM_CALL_TYPE_ALL, NULL) == 0 && app_id != MDI_AUD_SUSPEND_BG_UCM))
    {
        mdi_audio_stop_all();
    }

    MDI_AUDIO_UNLOCK;

    return selected_id;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play_by_app_async_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_suspend_background_play_by_app_async_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_AUD_SUSPEND_BG_APP app_id;
    mdi_ext_callback cb_hdlr;
    mmi_mdi_suspend_background_play_req_struct *msg_p = (mmi_mdi_suspend_background_play_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;

    app_id = (MDI_AUD_SUSPEND_BG_APP)msg_p->app_id;
    cb_hdlr = (mdi_ext_callback)msg_p->cb_hdlr;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SUSPEND_BG_PLAY_APP_ASYNC_CB, app_id, cb_hdlr);

    g_mdi_aud_suspend_app[app_id/8] |= (1 << (app_id%8));

    if( (app_id == MDI_AUD_SUSPEND_BG_UCM) || (srv_ucm_query_call_count((SRV_UCM_ACTIVE_STATE | SRV_UCM_HOLD_STATE), SRV_UCM_CALL_TYPE_ALL, NULL) == 0 && app_id != MDI_AUD_SUSPEND_BG_UCM))
    {
        mdi_audio_stop_all();
    }

    if(cb_hdlr != NULL)
    {
        cb_hdlr(MDI_AUDIO_SUCCESS, msg_p->user_data);
    }
    MDI_AUDIO_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play_by_app_async
 * DESCRIPTION
 *  This function is to suspend background play by application.
 *  It is called by non-MMI task, and will send a message to MMI task to suspend
 * PARAMETERS
 *  app_id      [IN] : Use MDI_AUD_SUSPEND_BF_ASYNC_APP
 *  cb_hdlr     [IN] : callback handler, will be called from MMI task
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_suspend_background_play_by_app_async(MDI_AUD_SUSPEND_BG_APP app_id, mdi_ext_callback cb_hdlr, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mdi_suspend_background_play_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SUSPEND_BG_PLAY_APP_ASYNC, app_id, cb_hdlr);

    msg_p = OslConstructDataPtr(sizeof(mmi_mdi_suspend_background_play_req_struct));
    msg_p->app_id = (kal_uint16)app_id;
    msg_p->cb_hdlr = (void*)cb_hdlr;
    msg_p->user_data = user_data;

    mdi_send_msg(MOD_MMI, MSG_ID_MMI_MDI_SUSPEND_BACKGROUND_PLAY_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_background_handler
 * DESCRIPTION
 *  This function is to set background play timeout handler.
 *  Besides POC, the latest register callback will be called first.
 *
 * PARAMETERS
 *  level       [IN]        mdi_bg_callback handler
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_set_background_handler(U8 app_level, mdi_bg_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    S16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SET_BACKGROUND_HANDLER, app_level);
    result = MDI_AUDIO_FAIL;

    {
        /* Set the latest callback to the top of callback stack */
        if (app_level < MDI_BACKGROUND_APP_TOTAL)
        {
            for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
            {
                /* Matched or the first empty item */
                if((background_handler.app[i] == app_level) || (background_handler.app[i] == MDI_BACKGROUND_APP_TOTAL))
                {
                    j = i;
                    while(j > 0)
                    {
                        background_handler.app[j] = background_handler.app[j-1];
                        background_handler.handler[j] = background_handler.handler[j-1];
                        background_handler.user_data[j] = background_handler.user_data[j-1];
                        j--;
                    }
                    background_handler.app[0] = app_level;
                    background_handler.handler[0] = handler;
                    background_handler.user_data[0] = user_data;
                    break;
                }
            }

            result = MDI_AUDIO_SUCCESS;
        }

        for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BACKGROUND_HANDLER, i, background_handler.app[i]);
        }
    }

    MDI_AUDIO_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_background_handler
 * DESCRIPTION
 *  This function is to reset background play timeout handler.
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_clear_background_handler(U8 app_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CLEAR_BACKGROUND_HANDLER, app_level);
    result = MDI_AUDIO_FAIL;

    {
        if (app_level < MDI_BACKGROUND_APP_TOTAL)
        {
            /* Find the callback function and move the next element forward */
            for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
            {
                if(background_handler.app[i] == app_level)
                {
                    j = i;
                    while(j < (MDI_BACKGROUND_APP_TOTAL - 1))
                    {
                        background_handler.app[j] = background_handler.app[j+1];
                        background_handler.handler[j] = background_handler.handler[j+1];
                        background_handler.user_data[j] = background_handler.user_data[j+1];
                        j++;
                    }

                    background_handler.app[j] = MDI_BACKGROUND_APP_TOTAL;
                    background_handler.handler[j] = NULL;
                    background_handler.user_data[j] = NULL;

                    mdi_audio_start_background_timer();
                    break;
                }
            }
            result = MDI_AUDIO_SUCCESS;
        }

        for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BACKGROUND_HANDLER, i, background_handler.app[i]);
        }
    }
    MDI_AUDIO_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_other_background_handler
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_clear_other_background_handler(U8 app_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Do nothing in multi-stack background */
#ifdef __MDI_AUDIO_MULTIPLE_LAYER_BACKGROUND_PLAY__
    return MDI_AUDIO_SUCCESS;
#else
    U16 i;

    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FINISH_BACKGROUND_PLAY, app_level);

    /* The request app must on the top level of stack */
    MDI_ASSERT(background_handler.app[0] == app_level);

    /* clear all application background play except request application itself and POC */
    for(i = 1 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
    {
        if(background_handler.handler[i] != NULL)
        {
            background_handler.handler[i](MDI_AUDIO_TERMINATED, background_handler.user_data[i]);
        }

        background_handler.app[i] = MDI_BACKGROUND_APP_TOTAL;
        background_handler.handler[i] = NULL;
        background_handler.user_data[i] = NULL;
    }
    mdi_audio_start_background_timer();
    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_finish_background_handler
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mdi_audio_get_background_callback_order(U8 app_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
    {
        if(background_handler.app[i] == app_level)
        {
            MDI_AUDIO_UNLOCK;
            return i;
        }
    }
    MDI_AUDIO_UNLOCK;
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_background_callback_register_app_num
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mdi_audio_get_background_callback_register_app_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j =0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
    {
        if(background_handler.app[i] < MDI_BACKGROUND_APP_TOTAL)
        {
            j++;
        }
    }
    MDI_AUDIO_UNLOCK;
    return j;
}


/*-----------------------------------------------------------------------------
                                     BT
 ----------------------------------------------------------------------------*/
#ifdef __MMI_BT_AUDIO_SUPPORT__

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
#endif //0

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_get_stream_status
 * DESCRIPTION
 *  This function is to get the bt stream state.
 * PARAMETERS
 *  profile     [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
U8 mdi_audio_bt_get_stream_status(U8 profile)
{
    return mdi_audio_bt_cntx.state;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_close_stream_ind
 * DESCRIPTION
 *  This function is to indicate bluetooth audio stream close.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_close_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_close_ind_struct *msg_p = (media_bt_audio_close_ind_struct*) msg;
    U16 result;
    mdi_bt_callback handler;
	U8 profile;
	U8 connect_id;
    U8 state;
    U8 mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = msg_p->cause;
	profile = msg_p->profile;
	connect_id = msg_p->connect_id;
    state = mdi_audio_bt_cntx.state;
    handler = mdi_audio_bt_cntx.close_hdlr;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_CLOSE_STREAM_IND, BT_HFP, state, result, handler);

    if (state == MDI_AUDIO_BT_STATE_OPEN || state == MDI_AUDIO_BT_STATE_WAIT_CLOSE)
    {
        mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_IDLE;

        /* execute pending connect req */
        if( mdi_audio_bt_cntx.pending_connect )
        {
            mdi_audio_bt_cntx.pending_connect = MMI_FALSE;
            mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_WAIT_OPEN;

            if(srv_btaud_get_device_class() == BTAUD_CARKIT)
            {
                mode = BT_HFP_CARKIT_MODE;
            }
            else
            {
                mode = BT_HFP_EARPHONE_MODE;
            }

            aud_send_bt_audio_open_req( MOD_MMI, BT_HFP, mode, 
                mdi_audio_bt_cntx.connect_id );
        }
        if (handler != NULL)
        {
            handler(profile, mdi_audio_get_event(result), 0,connect_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_close_stream_cnf
 * DESCRIPTION
 *  This function is to response bluetooth audio stream close.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_close_stream_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_close_cnf_struct *msg_p = (media_bt_audio_close_cnf_struct*) msg;
    U16 result;
    mdi_bt_callback handler;
    U8 state;
    U8 mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = msg_p->result;
    state = mdi_audio_bt_cntx.state;
    handler = mdi_audio_bt_cntx.close_hdlr;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_CLOSE_STREAM_CNF, BT_HFP, state, result, handler);

    if (state == MDI_AUDIO_BT_STATE_WAIT_CLOSE)
    {
        mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_IDLE;
        /* execute pending connect req */
        if( mdi_audio_bt_cntx.pending_connect)
        {
            mdi_audio_bt_cntx.pending_connect = MMI_FALSE;
            mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_WAIT_OPEN;

            if(srv_btaud_get_device_class() == BTAUD_CARKIT)
            {
                mode = BT_HFP_CARKIT_MODE;
            }
            else
            {
                mode = BT_HFP_EARPHONE_MODE;
            }
            aud_send_bt_audio_open_req( MOD_MMI, BT_HFP, mode, 
                mdi_audio_bt_cntx.connect_id );
        }

        if (handler != NULL)
        {
            handler(BT_HFP, mdi_audio_get_event(result), 0,0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_open_stream_ind
 * DESCRIPTION
 *  This function is to indicate bluetooth audio open.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_open_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_ind_struct *msg_p = (media_bt_audio_open_ind_struct*) msg;
	U8 profile;
	U8 connect_id;
    mdi_bt_callback handler;
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	profile = msg_p->profile;
	connect_id = msg_p->connect_id;
    state = mdi_audio_bt_cntx.state;
    handler = mdi_audio_bt_cntx.open_hdlr;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_OPEN_STREAM_IND, BT_HFP, state, handler);

    if (state == MDI_AUDIO_BT_STATE_IDLE || state == MDI_AUDIO_BT_STATE_WAIT_OPEN)
    {
        mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_OPEN;
        mdi_audio_bt_cntx.pending_connect = MMI_FALSE;
        if (handler != NULL)
        {
            handler(profile, MDI_AUDIO_SUCCESS, 0,connect_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_open_stream_cnf
 * DESCRIPTION
 *  This function is to indicate bluetooth audio stream close.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_open_stream_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_cnf_struct *msg_p = (media_bt_audio_open_cnf_struct*) msg;
    U16 result;
    mdi_bt_callback handler;
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = msg_p->result;
    state = mdi_audio_bt_cntx.state;
    handler = mdi_audio_bt_cntx.open_hdlr;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_OPEN_STREAM_CNF, BT_HFP, state, result, handler);

    if (state == MDI_AUDIO_BT_STATE_WAIT_OPEN)
    {
        if (result == MED_RES_OK)
        {
            mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_OPEN;
        }
        else
        {
            mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_IDLE;
        }
        if (handler != NULL)
        {
            handler(BT_HFP, mdi_audio_get_event(result), msg_p->error_cause,0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_open_stream_req
 * DESCRIPTION
 *  This function is to help other task to open stream
 * PARAMETERS
 *  msg     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_open_stream_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mdi_bt_open_stream_req_struct *msg_p = (mmi_mdi_bt_open_stream_req_struct*) msg;
    U8 state = mdi_audio_bt_cntx.state;
    U8 mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_OPEN_STREAM_REQ, msg_p->profile, state);

    if (state == MDI_AUDIO_BT_STATE_IDLE)
    {
        if(srv_btaud_get_device_class() == BTAUD_CARKIT)
        {
            mode = BT_HFP_CARKIT_MODE;
        }
        else
        {
            mode = BT_HFP_EARPHONE_MODE;
        }

        aud_send_bt_audio_open_req(MOD_MMI, msg_p->profile, mode, msg_p->connect_id);
        mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_WAIT_OPEN;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_open_stream
 * DESCRIPTION
 *  This function is to turn on bluetooth audio stream.
 * PARAMETERS
 *  profile         [IN]        
 *  connect_id      [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_bt_open_stream(U8 profile, U16 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = mdi_audio_bt_cntx.state;
    U8 mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_OPEN_STREAM, profile, state);

    if (state == MDI_AUDIO_BT_STATE_IDLE)
    {
        if(kal_get_active_module_id() != MOD_MMI)
        {
            mmi_mdi_bt_open_stream_req_struct *req = (mmi_mdi_bt_open_stream_req_struct *)construct_local_para(sizeof(mmi_mdi_bt_open_stream_req_struct), TD_CTRL);
            
            req->profile = profile;
            req->connect_id = connect_id;
            
            mdi_send_msg(MOD_MMI, MSG_ID_MMI_MDI_BT_OPEN_STREAM_REQ, req, NULL);
        }
        else
        {
            if(srv_btaud_get_device_class() == BTAUD_CARKIT)
            {
                mode = BT_HFP_CARKIT_MODE;
            }
            else
            {
                mode = BT_HFP_EARPHONE_MODE;
            }

            aud_send_bt_audio_open_req(MOD_MMI, profile, mode, connect_id);
            mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_WAIT_OPEN;
        }

        return MMI_TRUE;
    }
    else if( state == MDI_AUDIO_BT_STATE_WAIT_CLOSE )
    {
        /* postpond thie connect req to disconnect ind or cnf */
        mdi_audio_bt_cntx.pending_connect = MMI_TRUE;
        mdi_audio_bt_cntx.connect_id = connect_id;

        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_close_stream
 * DESCRIPTION
 *  This function is to turn off bluetooth audio stream.
 * PARAMETERS
 *  profile     [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_bt_close_stream(U8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = mdi_audio_bt_cntx.state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_CLOSE_STREAM, profile, state);


    /* clean up pending connect req */
    if( mdi_audio_bt_cntx.pending_connect )
    {
        mdi_audio_bt_cntx.pending_connect = MMI_FALSE;
        mdi_audio_bt_cntx.open_hdlr( profile, MDI_AUDIO_FAIL, 0,0);
    }

    if (state == MDI_AUDIO_BT_STATE_OPEN || state == MDI_AUDIO_BT_STATE_WAIT_OPEN)
    {
        /* Use blocking mode request function for HFP profile */
        /* To make sure MED will send message to BT before MMI continues */
        media_aud_bt_audio_close(profile);
        mdi_audio_bt_cntx.state = MDI_AUDIO_BT_STATE_WAIT_CLOSE;

        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_is_stream_open
 * DESCRIPTION
 *  This function is to check the state to know if bt audio is open.
 * PARAMETERS
 *  profile     [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_bt_is_stream_open(U8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = mdi_audio_bt_cntx.state;
	MMI_BOOL result = (MMI_BOOL)((state == MDI_AUDIO_BT_STATE_OPEN) || (state == MDI_AUDIO_BT_STATE_WAIT_CLOSE));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_IS_STREAM_OPEN, profile, state, result);

    return result;
}


/******************************************************************
* FUNCTION
*    mdi_audio_bt_hfp_turn_on
* DESCRIPTION
*    This function is to change audio path to SCO
* PARAMETERS
*    void
* RETURNS
*    void
* GLOBALS AFFECTED
*  
******************************************************************/
void mdi_audio_bt_hfp_turn_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = mdi_audio_bt_cntx.state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_HFP_TURN_ON, state);

    /* since this is to turn off SCO audio path, not to disconnect sco, so we check for positive result for mdi_audio_bt_is_stream_open */
    if(mdi_audio_bt_is_stream_open(BT_HFP))
    {
        aud_send_bt_audio_turn_on_req( MOD_MMI, BT_HFP );
    }
}


/******************************************************************
* FUNCTION
*    mdi_audio_bt_hfp_turn_off
* DESCRIPTION
*    This function is to change audio path to mobile device
* PARAMETERS
*    void
* RETURNS
*    void
* GLOBALS AFFECTED
*  
******************************************************************/
void mdi_audio_bt_hfp_turn_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = mdi_audio_bt_cntx.state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_HFP_TURN_OFF, state);

    if(mdi_audio_bt_is_stream_open(BT_HFP))
    {
        /* Use blocking mode request function for HFP profile */
        /* To make sure MED will send message to BT before MMI continues */    
        media_aud_bt_turn_off_audio(BT_HFP );
    }
}

//#ifdef __MED_BT_HFP_MOD__
/******************************************************************
* FUNCTION
*    mdi_audio_set_sco_mode
* DESCRIPTION
*    This function is to pre-set sco path mode so that we can ask to 
*    connect sco before playback action. ex: fm power on.
* PARAMETERS
*    void
* RETURNS
*    void
*  
******************************************************************/
void mdi_audio_set_sco_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_bt_audio_set_sco_mode_req(MOD_MMI, mode);

}
//#endif /* __MED_BT_HFP_MOD__ */

#endif /* __MMI_BT_AUDIO_SUPPORT__ */ 


void mdi_audio_enable_megaphone(kal_bool on)
{
    if(on)
    {
        #ifdef __MMI_BT_AUDIO_SUPPORT__
        srv_btsco_call_start_callback();
		#endif
		media_aud_enable_megaphone(KAL_TRUE);
	}
	else
	{
        #ifdef __MMI_BT_AUDIO_SUPPORT__
        srv_btsco_call_end_callback();
		#endif
		media_aud_enable_megaphone(KAL_FALSE);
	}
}


#ifdef __MMI_A2DP_SUPPORT__
/******************************************************************
* FUNCTION
*    mdi_audio_bt_is_a2dp_codec_open
* DESCRIPTION
*    This function is to check if a2dp is under streaming state or codec
*    is open. For performance tuning querying.
* PARAMETERS
*    void
* RETURNS
*    MMI_BOOL
* GLOBALS AFFECTED
*  
******************************************************************/
MMI_BOOL mdi_audio_bt_is_a2dp_codec_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_A2DP_SUPPORT__)
    result = srv_a2dp_is_codec_open();
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_IS_A2DP_CODEC_ON, result);
#endif

    return result ;
}
#endif /*__MMI_A2DP_SUPPORT__*/


/*-----------------------------------------------------------------------------
                                 BT Volume Sync
 ----------------------------------------------------------------------------*/
#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_register_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *   app_id:      can use APPLICATION_DEPLOY enum in MMIDataType.h
 *   volume_type: 16-level or 7-level volume
 *   callback:    return true if application is running
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_register_volume_sync_callback(U32 app_id, U8 volume_lvl_type, MMI_BOOL (*callback)(U8 volume, MMI_BOOL is_mute))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_REG_BT_VOL_SYNC_CALLBACK, app_id, volume_lvl_type, callback);

    /* Find match app_id or first empty slot */
    for(i = 0 ; i < MDI_AUD_MAX_BT_VOL_NUM ; i++)
    {
        /* Replace */
        if(g_mdi_aud_bt_vol[i].app_id == app_id)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, i, g_mdi_aud_bt_vol_count, -1, __LINE__);

            g_mdi_aud_bt_vol[i].callback = callback;
            g_mdi_aud_bt_vol[i].volume_lvl_type = volume_lvl_type;
            return;
        }

        /* Push to the stack */
        if((g_mdi_aud_bt_vol[i].app_id == 0) && (g_mdi_aud_bt_vol[i].callback == NULL))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, i, g_mdi_aud_bt_vol_count, -1, __LINE__);
            
            g_mdi_aud_bt_vol[i].app_id = app_id;
            g_mdi_aud_bt_vol[i].callback = callback;
            g_mdi_aud_bt_vol[i].volume_lvl_type = volume_lvl_type;

            g_mdi_aud_bt_vol_count++;
            return;
        }
    }

    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_clear_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *   app_id:      can use APPLICATION_DEPLOY enum in MMIDataType.h
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_clear_volume_sync_callback(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CLEAR_BT_VOL_SYNC_CALLBACK, app_id);

    for(i = 0 ; i < g_mdi_aud_bt_vol_count && i < MDI_AUD_MAX_BT_VOL_NUM; i++)
    {
        if(g_mdi_aud_bt_vol[i].app_id == app_id)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, i, g_mdi_aud_bt_vol_count, -1, __LINE__);

            j = i;
            if(i < (MDI_AUD_MAX_BT_VOL_NUM - 1))
            {
                while ((j < g_mdi_aud_bt_vol_count) && (j < (MDI_AUD_MAX_BT_VOL_NUM - 1)))
                {
                    g_mdi_aud_bt_vol[j].app_id = g_mdi_aud_bt_vol[j+1].app_id;
                    g_mdi_aud_bt_vol[j].callback = g_mdi_aud_bt_vol[j+1].callback;
                    g_mdi_aud_bt_vol[j].volume_lvl_type = g_mdi_aud_bt_vol[j+1].volume_lvl_type;
                    j++;
                }
            }
            g_mdi_aud_bt_vol[j].app_id = 0;
            g_mdi_aud_bt_vol[j].callback = NULL;
            g_mdi_aud_bt_vol[j].volume_lvl_type = 0;

            g_mdi_aud_bt_vol_count--;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_get_volume_level_from_type
 * DESCRIPTION
 *  7-Level <- 16 Level Mapping 
 *    0 <-    0
 *    1 <-    1   2   3
 *    2 <-    4   5   6
 *    3 <-    7   8   9
 *    4 <-   10  11  12
 *    5 <-   13  14
 *    6 <-   15
 * PARAMETERS
 *   bt_volume: bluetooth volume from 0 ~ 15
 * RETURNS
 *  void
 *****************************************************************************/
U8 mdi_audio_bt_get_volume_level_from_type(U8 bt_volume, U8 volume_lvl_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 app_volume = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 16 level */
    if(volume_lvl_type == MDI_AUD_VOL_LEVEL_EXTEND)
    {
        app_volume = bt_volume;
    }
    /* 16 level + mute */
    else if(volume_lvl_type == MDI_AUD_VOL_LEVEL_EXTEND_MUTE)
    {
        app_volume = bt_volume + 1;
    }
    else /* MDI_AUD_VOL_LEVEL_NORMAL || MDI_AUD_VOL_LEVEL_NORMAL_MUTE */
    {

        U8 volume_table[16] = {0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,6};
        ASSERT(bt_volume<16);
        app_volume = volume_table[bt_volume];

        if(volume_lvl_type == MDI_AUD_VOL_LEVEL_NORMAL_MUTE)
        {
            app_volume = app_volume + 1;
        }
    }

    return app_volume;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_sync_volume_from_bt
 * DESCRIPTION
 *
 * PARAMETERS
 *   bt_volume: bluetooth volume from 0 ~ 15
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_sync_volume_from_bt(U8 bt_volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 app_volume;
    U32 app_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SYNC_VOLUME_FROM_BT, bt_volume);

    g_mdi_aud_last_bt_vol = bt_volume;

    /* If in call, only sync volume to call application if call app register callback */
#ifdef __MMI_UCM__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        for(i = (g_mdi_aud_bt_vol_count - 1) ; i >= 0 ; i--)
        {
		#ifdef __COSMOS_MMI_PACKAGE__
            if(g_mdi_aud_bt_vol[i].app_id == VAPP_UCM)
        #else
          	if(g_mdi_aud_bt_vol[i].app_id == APP_UCM)
        #endif
            {
                app_volume = mdi_audio_bt_get_volume_level_from_type(bt_volume, g_mdi_aud_bt_vol[i].volume_lvl_type);

                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, i, g_mdi_aud_bt_vol[i].app_id, g_mdi_aud_bt_vol[i].volume_lvl_type, __LINE__);
                if (g_mdi_aud_bt_vol[i].callback != NULL)
                {
                    g_mdi_aud_bt_vol[i].callback(app_volume, MMI_FALSE);
                }
                return;
            }
        }
    }
#endif

    /* Callback background application first, only first item in stack would be possible playing */
    if (background_handler.handler[0])
    {
        switch (background_handler.app[0])
        {
        #ifdef __PLUTO_MMI_PACKAGE__
        #if defined(__MMI_FM_RADIO__)
            case MDI_BACKGROUND_APP_FMR:
                app_id = APP_FMRDO;
                break;
        #endif
        #ifdef __MMI_MEDIA_PLAYER__
            case MDI_BACKGROUND_APP_MEDPLY:
                app_id = APP_MEDPLY;
                break;
        #endif /*__MMI_MEDIA_PLAYER__*/
        #ifdef __MMI_AUDIO_PLAYER__
            case MDI_BACKGROUND_APP_AUDPLY:
                app_id = APP_AUDIOPLAYER;
                break;
        #endif /*__MMI_AUDIO_PLAYER__*/
        #endif /*__PLUTO_MMI_PACKAGE__*/

        #ifdef __J2ME__
            case MDI_BACKGROUND_APP_JAVA:
                app_id = APP_JAVA;
                break;
        #endif /* __J2ME__ */
            default:
                break;
        }

        for(i = (g_mdi_aud_bt_vol_count - 1) ; i >= 0 ; i--)
        {
            if((g_mdi_aud_bt_vol[i].app_id == app_id) && (g_mdi_aud_bt_vol[i].callback != NULL))
            {
                app_volume = mdi_audio_bt_get_volume_level_from_type(bt_volume, g_mdi_aud_bt_vol[i].volume_lvl_type);
                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, i, g_mdi_aud_bt_vol[i].app_id, g_mdi_aud_bt_vol[i].volume_lvl_type, __LINE__);

                if(g_mdi_aud_bt_vol[i].callback(app_volume, MMI_FALSE))
                {
                    return;
                }
                /* Just check the first found item */
                break; 
            }
        }
    }

    /* If no background application is running, then callback normal aplications */
    for(i = (g_mdi_aud_bt_vol_count - 1) ; i >= 0 ; i--)
    {
        if(g_mdi_aud_bt_vol[i].callback != NULL)
        {
            app_volume = mdi_audio_bt_get_volume_level_from_type(bt_volume, g_mdi_aud_bt_vol[i].volume_lvl_type);
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, i, app_volume, g_mdi_aud_bt_vol[i].volume_lvl_type, __LINE__);
            
            if(g_mdi_aud_bt_vol[i].callback(app_volume, MMI_FALSE))
            {
                return;
            }
        }
    }

    /* No application is running, always sync to user profile */
    app_volume = mdi_audio_bt_get_volume_level_from_type(bt_volume, MDI_AUD_VOL_LEVEL_NORMAL_MUTE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, app_volume, bt_volume, -1, __LINE__);
    srv_prof_handfree_volume_sync_hdlr(app_volume);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume_to_bt
 * DESCRIPTION
 *  
 *  7-Level -> 16 Level Mapping 
 *    0 ->    0
 *    1 ->    2
 *    2 ->    5
 *    3 ->    7
 *    4 ->   10
 *    5 ->   13
 *    6 ->   15
 *
 * PARAMETERS
 *   volume: 7-level or 16-level volume from application
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_volume_to_bt(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 volume_level, bt_volume = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SET_VOLUME_TO_BT, volume);

#ifdef __MMI_A2DP_SUPPORT__
    if(srv_a2dp_is_streaming())
    {
        return;
    }
#endif 

    /* Get actual volume level value */
    volume_level = MDI_AUD_VOL_GET_EX_LEVEL(volume);

    /* 7-Level volume + Level 0 is mute, do not set to bt for mute level */
    if(MDI_AUD_VOL_IS_MUTE_LEVEL(volume))
    {
        if(volume_level == 0)
        {
            return;
        }
        else
        {
            volume_level = volume_level - 1;
        }
    }

    /* 16-Level volume */
    if(MDI_AUD_VOL_IS_EX_LEVEL(volume))
    {
        bt_volume = volume_level;
    }
    /* 7-Level volume */
    else
    {
        /* Use previous bt 16-level volume to sync back to BT to resolve mapping problem */
        if(!MDI_AUD_VOL_IS_MUTE_LEVEL(volume) && (volume_level == mdi_audio_bt_get_volume_level_from_type(g_mdi_aud_last_bt_vol, MDI_AUD_VOL_LEVEL_NORMAL)))
        {
            bt_volume = g_mdi_aud_last_bt_vol;
        }
        else if(MDI_AUD_VOL_IS_MUTE_LEVEL(volume) && ( (volume_level+1) == mdi_audio_bt_get_volume_level_from_type(g_mdi_aud_last_bt_vol, MDI_AUD_VOL_LEVEL_NORMAL_MUTE)))
        {
            bt_volume = g_mdi_aud_last_bt_vol;
        }
        else
        {
            U8 volume_tbl[7] = {0,2,5,7,10,13,15};
            ASSERT(volume_level<7);
            bt_volume = volume_tbl[volume_level];

        }
    }

    srv_btaud_set_volume((U32)bt_volume);

}
#endif /*__BT_SPK_VOL_CONTROL__*/


/*-----------------------------------------------------------------------------
                                    MMA
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close_all
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_mma_close_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    mdi_handle handle;
    void* user_data;
    mdi_mma_callback callback;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if(mdi_audio_mma_player[i].handle != NULL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, i, mdi_audio_mma_player[i].handle, -1, __LINE__);

            /* Stop and close the MMA handler first to prevent client from using the closed MMA handler */
            handle    = mdi_audio_mma_player[i].handle;
            callback  = mdi_audio_mma_player[i].callback;
            user_data = mdi_audio_mma_player[i].user_data;
            
            mdi_audio_mma_stop(handle);
            mdi_audio_mma_close(handle);

            /* Notify client the MMA handler is terminated */
            if(callback)
            {
                callback(handle, MDI_AUDIO_TERMINATED, user_data);
            }
        }
        /* mmi is still waiting for aysnc open cnf but another play request (ex: play string) stop the mma open by close all */
        else if(mdi_audio_mma_player[i].is_valid == MMI_TRUE && mdi_audio_mma_player[i].callback != NULL)
        {
            mdi_audio_mma_player[i].callback(0,MDI_AUDIO_TERMINATED,mdi_audio_mma_player[i].user_data);
            memset(&mdi_audio_mma_player[i], 0, sizeof(mdi_audio_mma_player_struct));
        }
		
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_covert_data_format
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mdi_audio_mma_covert_data_format(U8 mdi_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 mma_format = MMA_TYPE_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mdi_format)
    {
        case MDI_FORMAT_SMF:
            mma_format = MMA_TYPE_MIDI;
            break;
        case MDI_FORMAT_WAV:
            mma_format = MMA_TYPE_WAV;
            break;
        case MDI_FORMAT_IMELODY:
            mma_format = MMA_TYPE_IMY;
            break;
        case MDI_FORMAT_AMR:
            mma_format = MMA_TYPE_AMR;
            break;
        case MDI_FORMAT_DAF:
            mma_format = MMA_TYPE_DAF;
            break;
        case MDI_FORMAT_MUSICAM:
            mma_format = MMA_TYPE_MUSICAM;
            break;
        case MDI_FORMAT_AAC:
            mma_format = MMA_TYPE_AAC;
            break;
        case MDI_FORMAT_AU:
            mma_format = MMA_TYPE_AU;
            break;
        case MDI_FORMAT_AMR_WB:
            mma_format = MMA_TYPE_AWB;
            break;
        case MDI_FORMAT_WMA:
            mma_format = MMA_TYPE_WMA;
            break;
        case MDI_FORMAT_M4A:
            mma_format = MMA_TYPE_M4A;
            break;
        case MDI_FORMAT_AIFF:
            mma_format = MMA_TYPE_AIFF;
            break; 
        case MDI_FORMAT_RA:
            mma_format = MMA_TYPE_RA;
            break;
        case MDI_FORMAT_RMVB:
            mma_format = MMA_TYPE_RMVB;
            break;
        case MDI_FORMAT_RM:
            mma_format = MMA_TYPE_RM;
            break;
        case MDI_FORMAT_RV:
            mma_format = MMA_TYPE_RV;
            break;
        case MDI_FORMAT_APE:
            mma_format = MMA_TYPE_APE;
            break;
        case MDI_FORMAT_MP4:
            mma_format = MMA_TYPE_MP4;
            break;
        case MDI_FORMAT_3GP:
            mma_format = MMA_TYPE_3GP;
            break;
        case MDI_FORMAT_FLV:
            mma_format = MMA_TYPE_FLV;
            break;
        case MDI_FORMAT_F4V:
            mma_format = MMA_TYPE_F4V;
            break;
        case MDI_FORMAT_F4A:
            mma_format = MMA_TYPE_F4A;
            break;
        case MDI_FORMAT_VORBIS:
            mma_format = MMA_TYPE_VORBIS;
            break;
        case MDI_FORMAT_FLAC:
            mma_format = MMA_TYPE_FLAC;
            break;

        default:
            mma_format = MMA_TYPE_UNKNOWN;
            break;
    }

    return mma_format;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_find_empty_slot
 * DESCRIPTION
 *  This function is used to find an empty slot for MMA player.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mdi_audio_mma_find_empty_slot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if(mdi_audio_mma_player[i].handle == 0 && mdi_audio_mma_player[i].callback == NULL)
        {
            return i;
        }
    }

    return -1;
}


#ifdef __MMI_BT_AUDIO_VIA_SCO__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_reset_sco_timer
 * DESCRIPTION
 *  This function is to reset the timer of SCO when there is no MMA player in
 *  play state.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_mma_reset_sco_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if (mdi_audio_mma_player[i].state == MDI_AUDIO_PLAY)
        {
            break;
        }
    }

    /* Reset SCO connection only if there is no MMA player in PLAY state */
    if (i == MMA_NO_OF_PLAYER)
    {
        srv_btsco_reset_connection_timer();
    }
}
#endif /* __MMI_BT_AUDIO_VIA_SCO__ */


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_find_player
 * DESCRIPTION
 *  This function is used to find an opeded MMA player.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mdi_audio_mma_find_player(mdi_handle handle, MMI_BOOL validate_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == 0)
    {
        return -1;
    }

    for (i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if ((mdi_audio_mma_player[i].handle == handle) &&
            ((!validate_handle) || (mdi_audio_mma_player[i].is_valid)))
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_med_direct_callback
 * DESCRIPTION
 *  This function is the callback function from MED. 
 *  It will send message from MED to MMI
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_mma_med_direct_callback(kal_int32 handle, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_callback_ind_struct *ind_p;
    S16 curr_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_MED_DIRECT_CALLBACK, handle, result);

    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);

    if(curr_player >= 0)
    {
        ind_p = (media_mma_callback_ind_struct*)
            construct_local_para(sizeof(media_mma_callback_ind_struct), TD_CTRL);
        ind_p->handle = handle;
        ind_p->result = result;
        ind_p->player_id = mdi_audio_mma_player[curr_player].player_id;
        ind_p->seq_id = mdi_audio_mma_player[curr_player].seq_id;

        if (result == MED_RES_TERMINATED) /* The handle is terminated by MED */
        {
            /* Invalidate the handle. This is to prevent MMI from using invalid handle */
            mdi_audio_mma_player[curr_player].is_valid = MMI_FALSE;
        }

        mdi_send_msg(MOD_MMI, MSG_ID_MEDIA_MMA_CALLBACK_IND, ind_p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_callback_hdlr
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_mma_callback_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_callback_ind_struct *msg_p = (media_mma_callback_ind_struct*) inMsg;
    S16 curr_player;
    void* user_data;
    mdi_mma_callback callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    /* The handle may be invalidated in the callback, but we still need to process the event and callback to app. */
    curr_player = mdi_audio_mma_find_player(msg_p->handle, MMI_FALSE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CALLBACK_HDLR, curr_player);

    if((curr_player >= 0) &&
       (msg_p->player_id == mdi_audio_mma_player[curr_player].player_id)&&
       (msg_p->seq_id == mdi_audio_mma_player[curr_player].seq_id))
    {
    #ifdef __DRM_SUPPORT__
        if ((msg_p->result != MED_RES_AUD_DUR_UPDATED) &&
            (mdi_audio_drm_mma_idx == curr_player) &&
            (mdi_audio_drm_id >= 0))
        {
            DRM_stop_consume(mdi_audio_drm_id);
            mdi_audio_drm_id = -1;
        }
    #endif /*__DRM_SUPPORT__*/

        callback  = mdi_audio_mma_player[curr_player].callback;
        user_data = mdi_audio_mma_player[curr_player].user_data;

        switch (mdi_audio_get_event(msg_p->result))
        {
            case MDI_AUDIO_END_OF_FILE:
            case MDI_AUDIO_ERROR:
            case MDI_AUDIO_DECODER_NOT_SUPPORT:
                if(mdi_audio_mma_find_player(msg_p->handle, MMI_TRUE) >= 0)
                {
                media_mma_aud_set_start_time(kal_get_active_module_id(), mdi_audio_mma_player[curr_player].handle, mdi_audio_mma_player[curr_player].format, 0);
                }
                mdi_audio_mma_player[curr_player].state = MDI_AUDIO_IDLE;
                if(mdi_audio_mma_is_idle())
                {
                    mdi_audio_start_background_timer();
                }
                break;
                
            case MDI_AUDIO_TERMINATED:  /* MMA handle was closed by MED */
            #ifdef __DRM_SUPPORT__
                if ((mdi_audio_drm_mma_idx == curr_player) &&
                    (mdi_audio_drm_mma_handle >= 0))
                {
                    DRM_close_file(mdi_audio_drm_mma_handle);
                    mdi_audio_drm_mma_handle = -1;
                    mdi_audio_drm_mma_idx = -1;
                }
            #endif /*__DRM_SUPPORT__*/
            
                memset(&mdi_audio_mma_player[curr_player], 0, sizeof(mdi_audio_mma_player_struct));

            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                mdi_audio_mma_reset_sco_timer();
            #endif
                break;
            
            case MDI_AUDIO_DUR_UPDATED: /* duration is updated */
                break;
                
            default:
                break;
        }

        if (callback)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CALLBACK_APP);
            callback(msg_p->handle, mdi_audio_get_event(msg_p->result), user_data);
        }
    }
    MDI_AUDIO_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle open cnf for async
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_mma_open_cnf_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_open_async_cnf_struct *msg_p = (media_mma_open_async_cnf_struct*) inMsg;
    S16 curr_player = -1;
    void* user_data;
    mdi_mma_callback callback;
    kal_int32 handle = NULL;
    kal_int32 result = MDI_AUDIO_SUCCESS;
    S16 i;
	U8 play_data;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;

	play_data = (U8)msg_p->user_data;
    for (i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if(mdi_audio_mma_player[i].player_id == (U8)(play_data))
        {
            curr_player = i;
            break;
        }
    }

    if(curr_player == -1)
   {
       MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CALLBACK_HDLR, curr_player);
       MDI_AUDIO_UNLOCK;
       return ;
   }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CALLBACK_HDLR, curr_player);

    callback  = mdi_audio_mma_player[curr_player].callback;
    user_data = mdi_audio_mma_player[curr_player].user_data;

    if(mdi_audio_get_event(msg_p->result) != MDI_AUDIO_SUCCESS)
    {
        memset(&mdi_audio_mma_player[curr_player], 0, sizeof(mdi_audio_mma_player_struct));
        result = MDI_AUDIO_OPEN_FILE_FAIL;
    }
    else
    {
        handle = msg_p->handle;
        mdi_audio_mma_player[curr_player].handle = handle;
    }

    if (callback)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CALLBACK_APP);
        callback(handle,result, user_data);
    }

    MDI_AUDIO_UNLOCK;
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
#endif //0

#ifdef __AUDIO_ULTRA_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open
 * DESCRIPTION
 *  This function is to open an MMA handle for a given file or string data.
 * PARAMETERS
 *  mma_open    : [IN]      Open struct
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_open(mdi_mma_open_struct* mma_open)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_player_struct param;
    mdi_result check_result;
    kal_int32 result, empty_player;
    mdi_handle handle = 0;
    S16 mma_type = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN);

    /* Validate state and call interrupt handler */
    if (mma_open->file_name != NULL) /* Play file */
    {
        check_result = mdi_audio_play_file_check_state((U16*)mma_open->file_name, MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK);
        
        if (check_result != MDI_AUDIO_SUCCESS)
        {
            MDI_AUDIO_UNLOCK;    
            return check_result;
        }
    }
    else /* Play string data */
    {
        if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK))
        {
            MDI_AUDIO_UNLOCK;    
            return check_result;
        }
        
        mma_type = mdi_audio_mma_covert_data_format(mma_open->mdi_format);
        
        if (mma_type < 0)
        {
            MDI_AUDIO_UNLOCK;
            return MDI_AUDIO_INVALID_FORMAT;
        }
    }
	
    mdi_audio_mma_slim_player.mma_para.app_id         = mma_open->app_id;
    mdi_audio_mma_slim_player.mma_para.handler        = mdi_audio_mma_med_direct_callback;
    mdi_audio_mma_slim_player.mma_para.media_type     = mma_open->mdi_format;//mma_type;
    mdi_audio_mma_slim_player.mma_para.data           = mma_open->data;
    mdi_audio_mma_slim_player.mma_para.size           = mma_open->data_len;
    mdi_audio_mma_slim_player.mma_para.file_path= (kal_wchar*)mma_open->file_name;
    mdi_audio_mma_slim_player.mma_para.repeats        = mma_open->repeats;
    mdi_audio_mma_slim_player.mma_para.progressive_dl = mma_open->is_pdl;
    mdi_audio_mma_slim_player.mma_para.output_path    = mma_open->output_path;
	mdi_audio_mma_slim_player.handle=mma_handle;
    *mma_open->handle_p = mma_handle;

    MDI_AUDIO_UNLOCK;
    
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_play
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_play(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;
	mma_player_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	para = mdi_audio_mma_slim_player.mma_para;
	if(para.file_path != NULL)
	{
		return mdi_audio_play_file_portion_with_vol_path(
					para.file_path,
					0,
					0,
					DEVICE_AUDIO_PLAY_ONCE, //need modify
					NULL,
					para.handler,
					NULL,
					MDI_AUD_VOL_3,
					para.output_path);

	}
	else
	{
    	return mdi_audio_play_string_hdlr(
                para.data,
                para.size,
                para.media_type,
                0,
                0,
                DEVICE_AUDIO_PLAY_ONCE,//need modify
                para.handler,
                NULL,
                MDI_AUD_VOL_3,
                para.output_path,
                MMI_TRUE);
	}
   
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_build_BLSI_table
 * DESCRIPTION
 *  This function is to zip / unzip BLSISRC talbe, this could speed up mixed 
 *  sampling rate audio playback.
 *  Turn on/off shall be called in pair
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mdi_audio_mma_build_BLSI_table(MMI_BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_param
 * DESCRIPTION
 *  This function is to set paramters to current handle after open success
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_set_param(mdi_handle handle, MDI_MMA_PARAM_ENUM param_type, void* param_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    return MDI_AUDIO_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pause
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_pause(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_audio_pause(mdi_audio_mma_slim_player.mma_para.handler,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_resume
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_resume(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    return mdi_audio_resume(mdi_audio_mma_slim_player.mma_para.handler,NULL);
       
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_stop
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_stop(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if(mdi_audio_mma_slim_player.mma_para.file_path!= NULL)
	{
		return mdi_audio_stop_string();
	}
	else
	{
		return mdi_audio_stop_file();
	}
      
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_close(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&mdi_audio_mma_slim_player, 0, sizeof(mdi_audio_mma_slim_struct));
    mdi_audio_mma_slim_player.handle = NULL;  
	return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_start_time
 * DESCRIPTION
 *  This function is to set start time
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_set_start_time(mdi_handle handle, U32 start_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_current_time
 * DESCRIPTION
 *  This function is to get current playing time
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_get_current_time(mdi_handle handle, U32 *current_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
	S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    return  mdi_audio_get_progress_time(current_time);

  
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_open
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mdi_audio_mma_is_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if(mdi_audio_mma_slim_player.handle == NULL)
      {
            MDI_AUDIO_UNLOCK;
            return KAL_FALSE;
      }
    else
    {
    	MDI_AUDIO_UNLOCK;
    	return KAL_TRUE;
    }
}

#else


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open
 * DESCRIPTION
 *  This function is to open an MMA handle for a given file or string data.
 * PARAMETERS
 *  mma_open    : [IN]      Open struct
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_open(mdi_mma_open_struct* mma_open)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_player_struct param;
    mdi_result check_result;
    kal_int32 result, empty_player;
    mdi_handle handle = 0;
    S16 mma_type = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN);

    /* Validate state and call interrupt handler */
    if (mma_open->file_name != NULL) /* Play file */
    {
        check_result = mdi_audio_play_file_check_state((U16*)mma_open->file_name, MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK);
        
        if (check_result != MDI_AUDIO_SUCCESS)
        {
            MDI_AUDIO_UNLOCK;    
            return check_result;
        }
    }
    else /* Play string data */
    {
        if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK))
        {
            MDI_AUDIO_UNLOCK;    
            return check_result;
        }
        
        mma_type = mdi_audio_mma_covert_data_format(mma_open->mdi_format);
        
        if (mma_type < 0)
        {
            MDI_AUDIO_UNLOCK;
            return MDI_AUDIO_INVALID_FORMAT;
        }
    }

    SetProtocolEventHandler(mdi_audio_mma_callback_hdlr, MSG_ID_MEDIA_MMA_CALLBACK_IND);

    param.app_id         = mma_open->app_id;
    param.handler        = mdi_audio_mma_med_direct_callback;
    param.media_type     = mma_type;
    param.data           = mma_open->data;
    param.size           = mma_open->data_len;
    param.file_path      = (kal_wchar*)mma_open->file_name;
    param.repeats        = mma_open->repeats;
    param.progressive_dl = mma_open->is_pdl;
    param.output_path    = mma_open->output_path;

    handle = media_mma_aud_open(kal_get_active_module_id(), &param, &result);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN_RESULT, result, handle);
    
    if (handle != 0)
    {
        /* Find an empty slot */
        empty_player = mdi_audio_mma_find_empty_slot();
        MDI_ASSERT(empty_player >= 0);

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, empty_player, -1, -1, __LINE__);

        mdi_audio_mma_player[empty_player].handle = handle;
        mdi_audio_mma_player[empty_player].callback = mma_open->callback;
        mdi_audio_mma_player[empty_player].user_data = mma_open->user_data;
        mdi_audio_mma_player[empty_player].state = MDI_AUDIO_IDLE;
        mdi_audio_mma_player[empty_player].format = mma_type;
        mdi_audio_mma_player[empty_player].player_id = mdi_audio_mma_player_id++;
        mdi_audio_mma_player[empty_player].seq_id = 0;
        mdi_audio_mma_player[empty_player].is_valid = KAL_TRUE;

    #ifdef __DRM_SUPPORT__
        /* Open a DRM handle */
        if (mma_open->file_name != NULL)
        {
            /* Close the opened DRM handle first */
            if (mdi_audio_drm_mma_handle >= 0)
            {
                DRM_close_file(mdi_audio_drm_mma_handle);
            }
            
            mdi_audio_drm_mma_handle = DRM_open_file((U16*)mma_open->file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_PLAY);
            mdi_audio_drm_mma_idx = empty_player;
        }
    #endif /* __DRM_SUPPORT__ */
    }
    
    *mma_open->handle_p = handle;

    MDI_AUDIO_UNLOCK;
    
    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_play
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_play(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_PLAY, handle, curr_player);

    if(curr_player >= 0)
    {
        /* All sound shall go through bluetooth earphone */
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        srv_btsco_connect_audio_via_sco();
    #endif

    #ifdef __GAIN_TABLE_SUPPORT__
        mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_MMA_PLAYBACK, (void*)mdi_audio_mma_player[curr_player].format);
    #endif /* __GAIN_TABLE_SUPPORT__ */

    #ifdef __DRM_SUPPORT__
        if ((mdi_audio_drm_mma_idx == curr_player) &&
            (mdi_audio_drm_mma_handle >= 0))
        {
            result = mdi_audio_drm_do_validate_right_with_handle(mdi_audio_drm_mma_handle);
            if(result != MDI_AUDIO_SUCCESS)
            {
            
                MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);
                MDI_AUDIO_UNLOCK;
                return result;
            }
        }
    #endif /*__DRM_SUPPORT__*/

        result = media_mma_aud_play(kal_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

        if(result == MED_RES_OK)
        {
        #ifdef __DRM_SUPPORT__
            if ((mdi_audio_drm_mma_idx == curr_player) &&
                (mdi_audio_drm_mma_handle >= 0))
            {
                mdi_audio_drm_consume_right(NULL, mdi_audio_drm_mma_handle, &mdi_audio_drm_id, mdi_audio_drm_mma_timeout_callback);
            }
        #endif /*__DRM_SUPPORT__*/
        
            mdi_audio_mma_player[curr_player].state = MDI_AUDIO_PLAY;
        }

        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_build_BLSI_table
 * DESCRIPTION
 *  This function is to zip / unzip BLSISRC talbe, this could speed up mixed 
 *  sampling rate audio playback.
 *  Turn on/off shall be called in pair
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mdi_audio_mma_build_BLSI_table(MMI_BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;

    aud_send_mma_build_BLISRC_table((kal_bool)turn_on);

    MDI_AUDIO_UNLOCK;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_param
 * DESCRIPTION
 *  This function is to set paramters to current handle after open success
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_set_param(mdi_handle handle, MDI_MMA_PARAM_ENUM param_type, void* param_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_SET_PARAM, handle, curr_player, param_type);

    if(curr_player < 0)
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_FAIL;
    }

    switch(param_type)
    {
        case MDI_MMA_PARAM_SET_ASYNC_MODE:
        {
            mdi_audio_mma_player[curr_player].async_mode = *((MMI_BOOL*)param_value);
            break;
        }

        default:
        {
            ASSERT(0);
        }
    }

    media_mma_aud_set_param(kal_get_active_module_id(), handle, param_type, param_value);

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;

}



/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pause
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_pause(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_PAUSE, handle, curr_player);

    if(curr_player >= 0)
    {
        result = media_mma_aud_pause(kal_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

        if(result == MED_RES_OK)
        {
        #ifdef __DRM_SUPPORT__
            if ((mdi_audio_drm_mma_idx == curr_player) &&
                (mdi_audio_drm_id >= 0))
            {
                DRM_pause_consume(mdi_audio_drm_id);
            }                
        #endif /*__DRM_SUPPORT__*/
        
            mdi_audio_mma_player[curr_player].state = MDI_AUDIO_PLAY_PAUSED;
        }

    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        mdi_audio_mma_reset_sco_timer();
    #endif
        
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_resume
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_resume(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_RESUME, handle, curr_player);

    if(curr_player >= 0)
    {
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        srv_btsco_connect_audio_via_sco();
    #endif

        result = media_mma_aud_resume(kal_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

        if(result == MED_RES_OK)
        {
        #ifdef __DRM_SUPPORT__
            if ((mdi_audio_drm_mma_idx == curr_player) &&
                (mdi_audio_drm_id >= 0))
            {
                DRM_resume_consume(mdi_audio_drm_id);
            }                
        #endif /*__DRM_SUPPORT__*/
        
            mdi_audio_mma_player[curr_player].state = MDI_AUDIO_PLAY;
        }

        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
    
    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_FAIL;    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_stop
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_stop(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_STOP, handle, curr_player);

    if(curr_player >= 0)
    {
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        mdi_audio_mma_reset_sco_timer();
    #endif

        result = media_mma_aud_stop(kal_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

    #ifdef __DRM_SUPPORT__
        if ((mdi_audio_drm_mma_idx == curr_player) &&
            (mdi_audio_drm_id >= 0))
        {
            DRM_stop_consume(mdi_audio_drm_id);
            mdi_audio_drm_id = -1;
        }
    #endif /*__DRM_SUPPORT__*/

        mdi_audio_mma_player[curr_player].state = MDI_AUDIO_IDLE;
        mdi_audio_mma_player[curr_player].seq_id++;

        /* Reset start time */
        media_mma_aud_set_start_time(kal_get_active_module_id(), mdi_audio_mma_player[curr_player].handle, mdi_audio_mma_player[curr_player].format, 0);

        /* Restart background timer if all the MMA players are in idle state */
        if (mdi_audio_mma_is_idle())
        {
            mdi_audio_start_background_timer();
        }
        
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
    
    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_FAIL;     
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_close(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CLOSE, handle, curr_player);

    if(curr_player >= 0)
    {
        /* Force stop the MMA player if it is not in idle state */
        if (mdi_audio_mma_player[curr_player].state != MDI_AUDIO_IDLE)
        {
            mdi_audio_mma_stop(handle);
        }

        result = media_mma_aud_close(kal_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

    #ifdef __DRM_SUPPORT__
        if ((mdi_audio_drm_mma_idx == curr_player) &&
            (mdi_audio_drm_mma_handle >= 0))
        {
            DRM_close_file(mdi_audio_drm_mma_handle);
            mdi_audio_drm_mma_handle = -1;
            mdi_audio_drm_mma_idx = -1;
        }
    #endif /*__DRM_SUPPORT__*/
    
        memset(&mdi_audio_mma_player[curr_player], 0, sizeof(mdi_audio_mma_player_struct));

        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_FAIL;      
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_start_time
 * DESCRIPTION
 *  This function is to set start time
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_set_start_time(mdi_handle handle, U32 start_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, handle, curr_player, start_time, __LINE__);

    if(curr_player >= 0)
    {
        result = media_mma_aud_set_start_time(kal_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format, (S32)start_time);
        return mdi_audio_get_event(result);
    }

    return MDI_AUDIO_FAIL;
}



/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_current_time
 * DESCRIPTION
 *  This function is to get current playing time
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_get_current_time(mdi_handle handle, U32 *current_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, handle, curr_player, -1, __LINE__);

    if(curr_player >= 0)
    {
        *current_time = (U32)media_mma_aud_get_current_time(kal_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
        return MDI_AUDIO_SUCCESS;
    }

    return MDI_AUDIO_FAIL;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_open
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mdi_audio_mma_is_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        // TODO: Add trace
        if(mdi_audio_mma_player[i].handle != NULL)
        {
            MDI_AUDIO_UNLOCK;
            return KAL_TRUE;
        }
    }

    MDI_AUDIO_UNLOCK;
    return KAL_FALSE;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_async
 * DESCRIPTION
 *  This function is to open an MMA handle with non-blocking method.
 * PARAMETERS
 *  mma_open    : [IN]      Open struct
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_open_async(mdi_mma_open_struct* mma_open)
{
    /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     mma_player_async_struct param;
     mdi_result check_result;
     kal_int32  empty_player;
     S16 mma_type = 0;
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     MDI_AUDIO_LOCK;
     MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN);
    
     /* Validate state and call interrupt handler */
     if (mma_open->file_name != NULL) /* Play file */
     {
         check_result = mdi_audio_play_file_check_state((U16*)mma_open->file_name, MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK);
         
         if (check_result != MDI_AUDIO_SUCCESS)
         {
             MDI_AUDIO_UNLOCK;    
             return check_result;
         }
     }
     else /* Play string data */
     {
         if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_MMA_PLAYBACK))
         {
             MDI_AUDIO_UNLOCK;    
             return check_result;
         }
         
         mma_type = mdi_audio_mma_covert_data_format(mma_open->mdi_format);
         
         if (mma_type < 0)
         {
             MDI_AUDIO_UNLOCK;
             return MDI_AUDIO_INVALID_FORMAT;
         }
     }

     empty_player = mdi_audio_mma_find_empty_slot();

     if(empty_player == -1)
     {
         MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_NO_HANDLE;
     }

     SetProtocolEventHandler(mdi_audio_mma_callback_hdlr, MSG_ID_MEDIA_MMA_CALLBACK_IND);
     SetProtocolEventHandler(mdi_audio_mma_open_cnf_hdlr, MSG_ID_MEDIA_MMA_AYNC_OPEN_CNF);
    
     param.app_id         = mma_open->app_id;
     param.handler        = mdi_audio_mma_med_direct_callback;
     param.media_type     = mma_type;
     param.data           = mma_open->data;
     param.size           = mma_open->data_len;
     param.file_path      = (kal_wchar*)mma_open->file_name;
     param.repeats        = mma_open->repeats;
     param.progressive_dl = mma_open->is_pdl;
     param.output_path    = mma_open->output_path;
     param.user_data      = (void*)(mdi_audio_mma_player_id); 

     aud_send_mma_open_async_req((kal_int32) &param);

     //handle = media_mma_aud_open(kal_get_active_module_id(), &param, &result);
      MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, empty_player, -1, -1, __LINE__);

     mdi_audio_mma_player[empty_player].callback = mma_open->callback;
     mdi_audio_mma_player[empty_player].user_data = mma_open->user_data;
     mdi_audio_mma_player[empty_player].state = MDI_AUDIO_IDLE;
     mdi_audio_mma_player[empty_player].format = mma_type;
     mdi_audio_mma_player[empty_player].player_id = mdi_audio_mma_player_id++;
     mdi_audio_mma_player[empty_player].seq_id = 0;
     mdi_audio_mma_player[empty_player].is_valid = KAL_TRUE;
     
#ifdef __DRM_SUPPORT__
     /* Open a DRM handle */
     if (mma_open->file_name != NULL)
     {
         /* Close the opened DRM handle first */
         if (mdi_audio_drm_mma_handle >= 0)
         {
             DRM_close_file(mdi_audio_drm_mma_handle);
         }
         
         mdi_audio_drm_mma_handle = DRM_open_file((U16*)mma_open->file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_PLAY);
         mdi_audio_drm_mma_idx = empty_player;
     }
 #endif /* __DRM_SUPPORT__ */
         
     MDI_AUDIO_UNLOCK;
     
     return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_file
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_handle mdi_audio_mma_open_file(U16 app_id, void *file_name, U8 repeats, MMI_BOOL is_pdl, mdi_mma_callback callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mma_open_struct mma_open;
    mdi_result result;
    mdi_handle handle = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_open.app_id      = app_id;
    mma_open.file_name   = file_name;
    mma_open.data        = NULL;
    mma_open.data_len    = 0;
    mma_open.mdi_format  = (U8)MDI_FORMAT_NONE;
    mma_open.repeats     = repeats;
    mma_open.is_pdl      = is_pdl;
    mma_open.output_path = MDI_DEVICE_SPEAKER;
    mma_open.callback    = callback;
    mma_open.user_data   = user_data;
    mma_open.handle_p    = &handle;

    result = mdi_audio_mma_open(&mma_open);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN_FILE, result, handle);
    
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_string
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_handle mdi_audio_mma_open_string(U16 app_id, void *audio_data, U32 len, U8 mdi_format, U8 repeats, mdi_mma_callback callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_mma_open_struct mma_open;
    mdi_result result;
    mdi_handle handle = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_open.app_id      = app_id;
    mma_open.file_name   = NULL;
    mma_open.data        = audio_data;
    mma_open.data_len    = len;
    mma_open.mdi_format  = mdi_format;
    mma_open.repeats     = repeats;
    mma_open.is_pdl      = MMI_FALSE;
    mma_open.output_path = MDI_DEVICE_SPEAKER;
    mma_open.callback    = callback;
    mma_open.user_data   = user_data;
    mma_open.handle_p    = &handle;

    result = mdi_audio_mma_open(&mma_open);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN_STRING, mdi_format, result, handle);

    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_cache_table
 * DESCRIPTION
 *  This function is to set cache table to driver for faster seek in VBR file
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_set_cache_table(mdi_handle handle, U8 *cache_tbl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = media_mma_set_cache_table(kal_get_active_module_id(), handle, cache_tbl);

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_idle
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mdi_audio_mma_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if(mdi_audio_mma_player[i].state != MDI_AUDIO_IDLE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_IS_IDLE, 0);
            MDI_AUDIO_UNLOCK;
            return KAL_FALSE;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_IS_IDLE, 1);
    MDI_AUDIO_UNLOCK;
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_estimated duration
 * DESCRIPTION
 *  This function is to get estimated duration.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_get_estimated_duration(mdi_handle handle, U32* duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, handle, curr_player, -1, __LINE__);

    if(curr_player >= 0)
    {
        *duration = (U32)media_mma_aud_get_duration(kal_get_active_module_id(), handle, (U8)MDI_FORMAT_NONE);
        return MDI_AUDIO_SUCCESS;
    }

    return MDI_AUDIO_FAIL;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_updated_duration
 * DESCRIPTION
 *  This function is to get updated duration.
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_get_updated_duration(mdi_handle handle, U32* duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_player = mdi_audio_mma_find_player(handle, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, handle, curr_player, -1, __LINE__);

    if(curr_player >= 0)
    {
        *duration = (U32)media_mma_aud_get_updated_duration(kal_get_active_module_id(), handle);
        return MDI_AUDIO_SUCCESS;
    }

    return MDI_AUDIO_FAIL;
}


mdi_result mdi_audio_mma_get_duration_by_handle(mdi_handle handle, U32* duration)
{
    return mdi_audio_mma_get_updated_duration(handle, duration);
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pdl_write_data_ind
 * DESCRIPTION
 *  This function is to inform MED if the PDL is download finish
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_pdl_write_data_ind(mdi_handle handle, MMI_BOOL is_finish)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* media type is not necessary here */
    result = media_mma_aud_pdl_write_data_ind(kal_get_active_module_id(), handle, 0, is_finish);

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pdl_get_buf_percent
 * DESCRIPTION
 *  This function is to get current pdl buffering status
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_pdl_get_buf_percent(mdi_handle handle, U32 cache_sec, U32* percent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_mma_aud_pdl_get_buf_percent(kal_get_active_module_id(), handle, cache_sec, percent);

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_audio_info
 * DESCRIPTION
 *  This function is to get audio info for a given file or stream buffer.
 * PARAMETERS
 *  file_name   : [IN] The file name to be parsed. NULL if using stream buffer.
 *  media_type  : [IN] Media type (MMA_TYPE_XXX) of the stream buffer. Don't care if using file.
 *  data        : [IN] Stream data. NULL if using file.
 *  data_len    : [IN] The length of stream data. 0 if using file.
 *  audio_info  : [OUT] Audio info
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_get_audio_info(kal_uint16 app_id, kal_wchar* file_name, kal_uint8 media_type, kal_uint8* data, kal_uint32 data_len, audInfoStruct *audio_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_mma_aud_get_audio_info(kal_get_active_module_id(), app_id, file_name, media_type, data, data_len, (void*)audio_info);

    return mdi_audio_get_event(result);
}


/*-----------------------------------------------------------------------------
                                     FMR
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_power_on_with_path
 * DESCRIPTION
 *  This function is to turn on FM radio with specific output path
 * PARAMETERS
 *  path        [IN]        
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_power_on_with_path(U8 path, mdi_ext_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO__

    MDI_AUDIO_LOCK;

    if (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO)
    {
        MDI_AUDIO_UNLOCK;
        return;
    }

    if ((! mdi_audio_is_idle()) 
     #ifdef __MMI_HF_SUPPORT__
      || (srv_btsco_is_sco_open() && srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
     #endif /* __MMI_HF_SUPPORT__ */
      || (interrupt_cb_handler != NULL))
    {
        mdi_audio_stop_all();
    }

#if defined(__MMI_ATV_SUPPORT__)
    mdi_mtv_pause_engine();
#endif

    mdi_audio_stop_background_timer();

    /* Change state before connect SCO (SCO will check if FM state on to connect)*/
    mdi_audio_state = MDI_AUDIO_PLAY;
    mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;

    /* Combinations to connect SCO */
#if defined(__MMI_BT_FM_VIA_SCO__)
    mdi_audio_set_sco_mode(MDI_AUD_BT_SCO_MODE_FM);
    srv_btsco_connect_audio_via_sco();
#elif defined(__MMI_BT_AUDIO_VIA_SCO__)
    srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
#endif

#if defined(__RF_DESENSE_TEST__)
    if (g_mdi_fm_desense)
    {
    #if defined(__FMRADIO_I2S_SUPPORT__)
        FM_I2S_Open();
    #endif /* __FMRADIO_I2S_SUPPORT__ */
    }
    else
#endif /* __RF_DESENSE_TEST__ */
    {
    #ifdef __GAIN_TABLE_SUPPORT__
        g_audio_path = path;
        mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_FM_STATE_CHANGED, (void*)TRUE);
    #endif /* __GAIN_TABLE_SUPPORT__ */
    
        media_aud_fmr_power_on(MOD_MMI, path);
    }

    mdi_cb_handler = handler;
    mdi_cb_data = user_data;

    /* Update antenna type */
#ifdef INTERNAL_ANTENNAL_SUPPORT
    if (srv_earphone_is_plug_in())
    {
        mdi_fmr_set_antenna(MMI_FALSE);
    }
    else
    {
        mdi_fmr_set_antenna(MMI_TRUE);
    }
#endif /* INTERNAL_ANTENNAL_SUPPORT */

    MDI_AUDIO_UNLOCK;
#endif /*__MMI_FM_RADIO__*/

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_fmr
 * DESCRIPTION
 *  This function is to stop FM radio playing/recording
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_fmr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO__
    MDI_AUDIO_LOCK;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_FMR, mdi_audio_state, mdi_audio_mode);

#ifdef __FM_RADIO_RDS_SUPPORT__
    if (g_rds_enabled)
    {
        mdi_fmr_rds_disable();
    }
#endif 
    if (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO)
    {
        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            mdi_cb_handler = NULL;
            tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
        }
        
        mdi_fmr_power_off();
    }
#ifdef FM_RADIO_RECORD
    /* Stop FM Record and Turn off FM Radio */
    else if ((mdi_audio_state == MDI_AUDIO_RECORD || mdi_audio_state == MDI_AUDIO_RECORD_PAUSED) &&
             mdi_audio_mode == MDI_AUDIO_RECORD_FM_RADIO)
    {
        mdi_fmr_stop_record_remain_on();  /* Stop before callback because need to handle record file in MMI */
        
        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            mdi_cb_handler = NULL;
            tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
        }
        
        mdi_fmr_power_off();
    }
#endif /* FM_RADIO_RECORD */

    MDI_AUDIO_UNLOCK;
#endif /*__MMI_FM_RADIO__*/

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_power_off
 * DESCRIPTION
 *  This function is to turn off FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO__
    MDI_AUDIO_LOCK;

    if (mdi_audio_state == MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;
        return;
    }

#ifdef FM_RADIO_RECORD
    /* Force stop record */
    if ((mdi_audio_state == MDI_AUDIO_RECORD || mdi_audio_state == MDI_AUDIO_RECORD_PAUSED) &&
        (mdi_audio_mode == MDI_AUDIO_RECORD_FM_RADIO))
    {
        mdi_fmr_stop_record_remain_on();
    }
#endif /* FM_RADIO_RECORD */

#ifndef __PLUTO_MMI_PACKAGE__
    /* Force stop scan/seek process */
    switch (g_mdi_fmr_state)
    {
        case MDI_FMR_STATE_SCAN:
            mdi_fmr_scan_abort();
            break;
        case MDI_FMR_STATE_SEEK:
            mdi_fmr_seek_abort();
            break;
        case MDI_FMR_STATE_IDLE:
        default:
            break;
    }
#endif /*__PLUTO_MMI_PACKAGE__*/

#if defined(__RF_DESENSE_TEST__)
    g_mdi_fm_desense = FALSE;
    
    kal_print_string_trace(MOD_MMI, TRACE_INFO, "RF Desense Mode = %d", rf_desense_get_curr_mode());
    
    if (rf_desense_get_curr_mode() == RF_DESENSE_MODE_FM_GSM_ON)
    {
        kal_prompt_trace(MOD_MMI, "GSM with FM ON");

        /* Mute FM */
        //mdi_audio_set_mute(AUD_VOLUME_FMR, TRUE);
        
    #if defined(__FMRADIO_I2S_SUPPORT__)
        /* Close I2S. It is required because of resource conflict. */
        FM_I2S_Close();
    #endif /* __FMRADIO_I2S_SUPPORT__ */
        
        g_mdi_fm_desense = TRUE;
    }
    else
#endif /* __RF_DESENSE_TEST__ */
    {
        media_aud_fmr_power_off(MOD_MMI);
        
    #ifdef __GAIN_TABLE_SUPPORT__
        mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_FM_STATE_CHANGED, (void*)FALSE);
    #endif /* __GAIN_TABLE_SUPPORT__ */
    }

    /* Combinations to connect SCO */
#if defined(__MMI_BT_FM_VIA_SCO__)
if(srv_earphone_is_plug_in())
	srv_btsco_disconnect_sco_req();
#elif defined(__MMI_BT_AUDIO_VIA_SCO__)
    srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
#endif  

    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_start_background_timer();
#if defined(__MMI_ATV_SUPPORT__)
    mdi_mtv_resume_engine();
#endif    

    MDI_AUDIO_UNLOCK;

#endif /*__MMI_FM_RADIO__*/

}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_output_path
 * DESCRIPTION
 *  This function is to set the output path of FM radio.
 * PARAMETERS
 *  path        [IN]             
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_set_output_path(U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_FM_RADIO__

#ifdef __GAIN_TABLE_SUPPORT__
    g_audio_path = path;
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_FM_STATE_CHANGED, (void*)g_is_fm_on);
#endif /* __GAIN_TABLE_SUPPORT__ */

    media_aud_fmr_set_output_path(MOD_MMI, path);

#endif /*__MMI_FM_RADIO__*/

}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_freq
 * DESCRIPTION
 *  This function is to set the frequency of FM radio.
 * PARAMETERS
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_set_freq(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO__

    if (mdi_audio_is_fm_on())
    {
        media_aud_fmr_set_freq(MOD_MMI, freq);
    }
#endif /*__MMI_FM_RADIO__*/

}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_antenna
 * DESCRIPTION
 *  This function is to set the antenna of FM radio.
 * PARAMETERS
 *  is_short_antenna  : [IN] Indicate if the short antenna should be used
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_set_antenna(MMI_BOOL is_short_antenna)
{
#ifdef __MMI_FM_RADIO__
#ifdef INTERNAL_ANTENNAL_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_is_fm_on())
    {
        media_audio_fmr_set_antenna(MOD_MMI, is_short_antenna);
    }
#endif/* #ifdef INTERNAL_ANTENNAL_SUPPORT*/
#endif /*__MMI_FM_RADIO__*/

}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_mute
 * DESCRIPTION
 *  This function is to mute the FM radio
 * PARAMETERS
 *  mute        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_mute(U8 mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO__
    if (mdi_audio_is_fm_on())
    {
        media_aud_fmr_mute(MOD_MMI, mute);
    }
#endif /*__MMI_FM_RADIO__*/

}

#ifdef __MMI_FM_RADIO__

#ifdef __MMI_FM_VIA_A2DP__

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_get_audio_info
 * DESCRIPTION
 *  to get the audio info of fmradio playback in this project
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_get_audio_info(mdi_fmr_audio_info_struct *audio_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    audio_info->sampleRate = (U16)Media_I2S_INPUT_MODE_SR;
    audio_info->stereo = MMI_TRUE;
}

#endif /* __MMI_FM_VIA_A2DP__ */

#ifdef __FM_RADIO_HW_SCAN__
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_hw_scan_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_hw_scan_result_ind(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void (*local_hw_scan_hdlr) (void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // StopTimer(TIMER_MMI_FMRDO_CHECK_HW_SCAN);
    if (mdi_fmr_hw_scan_result_hdlr != NULL)
    {
        local_hw_scan_hdlr = mdi_fmr_hw_scan_result_hdlr;
        mdi_fmr_hw_scan_result_hdlr = NULL;
        local_hw_scan_hdlr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_hw_scan_start
 * DESCRIPTION
 *   Start to seek
 * PARAMETERS
 *  start_freq       [IN]    start frequency
 *  is_step_up       [IN]    seek direction
 *  scan_table       [IN]    it will not wrap around if it is preset auto search
 *  space            [IN]    minimum space between two frequency. 200: 200KHz, 100: 100KHz
 *  callback_func    [IN]    callback function when found a valid freq or user abortion
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_hw_scan_start(U16 start_freq, MMI_BOOL is_step_up, U8 *scan_table, S16 space, void (*callback_func) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_fmr_hw_scan_result_hdlr = callback_func;
    SetProtocolEventHandler(mdi_fmr_hw_scan_result_ind, MSG_ID_MEDIA_FMR_HW_SCAN_FINISH_IND);
    media_aud_fmr_hw_scan(MOD_MMI, scan_table);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_hw_scan_abort
 * DESCRIPTION
 *  Abort hardware scanning. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_hw_scan_abort(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_fmr_hw_scan_abort(MOD_MMI);
    mdi_fmr_hw_scan_result_hdlr = NULL;
}

#ifndef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_hw_scan_callback
 * DESCRIPTION
 *  This function will be called when the HW scan process is done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_fmr_hw_scan_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Search all the frequency to find the first n channels */
    count = 0;
    
    for (i = 0; i < MDI_FMR_BANDWIDTH; i ++)
    {
        if (g_mdi_fmr_scan_table[i]) /* Valid channel */
        {
            g_mdi_fmr_scan_hdlr.channel_list[count++] = MDI_FMR_MIN_FREQ + i;

            /* Break if reach maximum number of channels */
            if (count == g_mdi_fmr_scan_hdlr.max_channel)
            {
                break;
            }
        }
    }
    
    /* Notify client the scan process is done */
    if (g_mdi_fmr_scan_hdlr.callback)
    {
        g_mdi_fmr_scan_hdlr.callback(MDI_FMR_CB_REASON_DONE, (void*)count, g_mdi_fmr_scan_hdlr.user_data);
    }

    /* Enter idle state */
    g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
}
#endif /* __PLUTO_MMI_PACKAGE__ */

#endif /* __FM_RADIO_HW_SCAN__ */ 


#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_freq_seek_result_ind(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_seek_result_ind_struct *msg_p = (media_fmr_seek_result_ind_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_fmr_seek_result_hdlr != NULL)
    {
        mdi_fmr_seek_result_hdlr(msg_p->stop_freq, msg_p->signal_level, msg_p->is_valid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_start
 * DESCRIPTION
 *   Start to seek
 * PARAMETERS
 *  start_freq      [IN]    start frequency
 *  is_step_up      [IN]    seek direction
 *  is_preset       [IN]    it will not wrap around if it is preset auto search
 *  space           [IN]    minimum space between two frequency. 200: 200KHz, 100: 100KHz
 *  callback_func   [IN]    callback function when found a valid freq or user abortion
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_freq_seek_start(U16 start_freq, MMI_BOOL is_step_up, MMI_BOOL is_preset, S16 space, void (*callback_func) (U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_fmr_seek_result_hdlr = callback_func;
    SetProtocolEventHandler(mdi_fmr_freq_seek_result_ind, MSG_ID_MEDIA_FMR_SEEK_RESULT_IND);
    aud_send_fmr_seek_start_req(MOD_MMI, start_freq, is_step_up, is_preset, space);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_abort
 * DESCRIPTION
 *  Abort seek. After abortion, it will call the callback function register 
 *  in mdi_fmr_freq_seek_start.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_freq_seek_abort(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_fmr_seek_abort(MOD_MMI);
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_FMR_SEEK_RESULT_IND);
    mdi_fmr_seek_result_hdlr = NULL;
}

#ifndef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_hw_search_done
 * DESCRIPTION
 *  This function notifies client when HW search process is done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_fmr_hw_search_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Find first n channels with valid stop frequency */
    count = 0;
    
    for (i = 0; i < MDI_FMR_BANDWIDTH; i ++)
    {
        if (g_mdi_fmr_scan_table[i] > 0) /* Valid stop frequency */
        {
            g_mdi_fmr_scan_hdlr.channel_list[count++] = MDI_FMR_MIN_FREQ + i;

            /* Break if reach maximum number of channels */
            if (count == g_mdi_fmr_scan_hdlr.max_channel)
            {
                break;
            }
        }
    }

    /* Notify client the scan process is done */
    if (g_mdi_fmr_scan_hdlr.callback)
    {
        g_mdi_fmr_scan_hdlr.callback(MDI_FMR_CB_REASON_DONE, (void*)count, g_mdi_fmr_scan_hdlr.user_data);
    }

    /* Enter idle state */
    g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_hw_search_callback
 * DESCRIPTION
 *  This function will be called in HW search processes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_fmr_hw_search_callback(U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (is_valid)
    {
        /* Mark scan table for the valid stop frequency */
        g_mdi_fmr_scan_table[stop_freq - MDI_FMR_MIN_FREQ] = 1;

        /* Continue to search next valid stop frequency */
        mdi_fmr_freq_seek_start(stop_freq + 1,
                                MMI_TRUE,
                                MMI_TRUE,
                                MDI_FMR_SEEK_SAPCE,
                                mdi_fmr_hw_search_callback);
    }
    else
    {
        mdi_fmr_hw_search_done();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_hw_seek_callback
 * DESCRIPTION
 *  This function will be called in HW seek is done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_fmr_hw_seek_callback(U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Notify client the seek is done */
    if (g_mdi_fmr_seek_hdlr.callback)
    {
        g_mdi_fmr_seek_hdlr.callback(MDI_FMR_CB_REASON_DONE,
                                     stop_freq,
                                     is_valid,
                                     g_mdi_fmr_seek_hdlr.user_data);
    }

    /* Enter idle state */
    g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
}
#endif /*__PLUTO_MMI_PACKAGE__*/


#else /* #if !defined(FM_RADIO_HW_SEARCH) */

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_check_is_valid_stop_cnf
 * DESCRIPTION
 *  This function is the callback function of check valid stop
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_check_is_valid_stop_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_check_is_valid_stop_cnf_struct *msg_p = (media_fmr_check_is_valid_stop_cnf_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_fmr_check_is_valid_stop_hdlr != NULL)
    {
        mdi_fmr_check_is_valid_stop_hdlr(msg_p->is_valid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_check_is_valid_stop
 * DESCRIPTION
 *  This function is to check if a frequency is valid stop
 * PARAMETERS
 *  freq                [IN]        
 *  is_step_up          [IN]        
 *  callback_func       [IN]        
 *  BOOL is_set_up,(?)
 *  void (*callback_func)(BOOL is_valid)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_check_is_valid_stop(U16 freq, MMI_BOOL is_step_up, void (*callback_func) (MMI_BOOL is_valid))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_fmr_check_is_valid_stop_hdlr = callback_func;
    SetProtocolEventHandler(mdi_fmr_check_is_valid_stop_cnf, MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_CNF);
    media_aud_fmr_check_is_valid_stop(MOD_MMI, freq, is_step_up);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_cancel_checking_is_valid_stop
 * DESCRIPTION
 *  This function is to cancel check valid stop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_cancel_checking_is_valid_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_CNF);
    mdi_fmr_check_is_valid_stop_hdlr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_get_signal_level_cnf
 * DESCRIPTION
 *  Thsi function is the callback function of get signal level
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_get_signal_level_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_get_signal_level_cnf_struct *msg_p = (media_fmr_get_signal_level_cnf_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_fmr_get_signal_level_hdlr != NULL)
    {
        mdi_fmr_get_signal_level_hdlr(msg_p->signal_level);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_get_signal_level
 * DESCRIPTION
 *  This function is to get the signal level of a frequency
 * PARAMETERS
 *  freq                [IN]        
 *  is_step_up          [IN]        
 *  callback_func       [IN]        
 *  void (*callback_func)(U8 sig_lvl)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_get_signal_level(U16 freq, MMI_BOOL is_step_up, void (*callback_func) (U8 sig_lvl))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_fmr_get_signal_level_hdlr = callback_func;
    SetProtocolEventHandler(mdi_fmr_get_signal_level_cnf, MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_CNF);
    media_aud_fmr_get_signal_level(MOD_MMI, freq, is_step_up);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_cancel_getting_signal_level
 * DESCRIPTION
 *  This fuction is to cancel get signal level request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_cancel_getting_signal_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_CNF);
    mdi_fmr_get_signal_level_hdlr = NULL;
}


#ifndef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_sw_scan_done
 * DESCRIPTION
 *  This function notifies client when SW scan process is done.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_fmr_sw_scan_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, count;
    S16 idx;
    U16 max_signal_level;
    U16 min_freq, temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Find channels with top-n signal level */
    count = 0;
    
    for (i = 0; i < g_mdi_fmr_scan_hdlr.max_channel; i++)
    {
        idx = -1;
        max_signal_level = 0;

        for (j = 0; j < MDI_FMR_BANDWIDTH; j ++)
        {
            if (g_mdi_fmr_signal_level[j] > 0) /* Valid signal level */
            {
                /* Find maximum signal level */
                if (g_mdi_fmr_signal_level[j] > max_signal_level)
                {
                    max_signal_level = g_mdi_fmr_signal_level[j];
                    idx = j;
                }
            }
        }

        if (idx >= 0) /* Find a channel with maximum signal level */
        {
            g_mdi_fmr_scan_hdlr.channel_list[count++] = (U16)(MDI_FMR_MIN_FREQ + idx);

            /* Break if reach maximum number of channels */
            if (count == g_mdi_fmr_scan_hdlr.max_channel)
            {
                break;
            }

            /* Reset the signal level */
            g_mdi_fmr_signal_level[idx] = 0;
        }
        else
        {
            break;
        }
    }
    
    if (g_mdi_fmr_scan_hdlr.sorting == MDI_FMR_SORTING_BY_FREQ)
    {
        /* Sorting scan result by frequency */
        for (i = 0; i < count - 1; i ++)
        {
            idx = -1;
            min_freq = g_mdi_fmr_scan_hdlr.channel_list[i];
                
            for (j = i+1; j < count; j ++)
            {
                if (g_mdi_fmr_scan_hdlr.channel_list[j] < min_freq)
                {
                    min_freq = g_mdi_fmr_scan_hdlr.channel_list[j];
                    idx = j;
                }
            }

            if (idx > 0)
            {
                temp = g_mdi_fmr_scan_hdlr.channel_list[i];
                g_mdi_fmr_scan_hdlr.channel_list[i] = g_mdi_fmr_scan_hdlr.channel_list[idx];
                g_mdi_fmr_scan_hdlr.channel_list[idx] = temp;
            }
        }
    }

    /* Notify client the scan process is done */
    if (g_mdi_fmr_scan_hdlr.callback)
    {
        g_mdi_fmr_scan_hdlr.callback(MDI_FMR_CB_REASON_DONE, (void*)count, g_mdi_fmr_scan_hdlr.user_data);
    }

    /* Enter idle state */
    g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_sw_scan_callback
 * DESCRIPTION
 *  This function will be called in SW scan processes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_fmr_sw_scan_callback(U8 signal_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Notify client with processing reason */
    if (g_mdi_fmr_scan_hdlr.callback)
    {
        g_mdi_fmr_scan_hdlr.callback(MDI_FMR_CB_REASON_PROCESS,
                                     (void*)(MDI_FMR_MIN_FREQ + g_mdi_fmr_scan_count),
                                     g_mdi_fmr_scan_hdlr.user_data);
    }

    /* Keep signal level */
    g_mdi_fmr_signal_level[g_mdi_fmr_scan_count ++] = signal_level;
    
    if (g_mdi_fmr_scan_count < MDI_FMR_BANDWIDTH)
    {
        /* Scan next frequency */
        mdi_fmr_get_signal_level((U16)(MDI_FMR_MIN_FREQ + g_mdi_fmr_scan_count),
                                 MMI_TRUE,
                                 mdi_fmr_sw_scan_callback);
    }
    else /* Scan complete */
    {
        /* Notify client with scan done */
        mdi_fmr_sw_scan_done();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_sw_seek_callback
 * DESCRIPTION
 *  This function will be called in SW seek processes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_fmr_sw_seek_callback(MMI_BOOL is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (is_valid)
    {
        /* Notify client the seek is done */
        if (g_mdi_fmr_seek_hdlr.callback)
        {
            g_mdi_fmr_seek_hdlr.callback(MDI_FMR_CB_REASON_DONE,
                                         (U16)g_mdi_fmr_seek_hdlr.start_freq,
                                         MMI_TRUE,
                                         g_mdi_fmr_seek_hdlr.user_data);
        }

        /* Enter idle state */
        g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
    }
    else
    {
        if (g_mdi_fmr_seek_hdlr.start_freq == g_mdi_fmr_seek_hdlr.stop_freq) /* End of seek */
        {
            /* Notify client there is no valid stop frequency found */
            if (g_mdi_fmr_seek_hdlr.callback)
            {
                g_mdi_fmr_seek_hdlr.callback(MDI_FMR_CB_REASON_DONE,
                                             (U16)g_mdi_fmr_seek_hdlr.start_freq,
                                             MMI_FALSE,
                                             g_mdi_fmr_seek_hdlr.user_data);
            }

            /* Enter idle state */
            g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
        }
        else
        {
            /* Notify client with processing reason */
            if (g_mdi_fmr_seek_hdlr.callback)
            {
                g_mdi_fmr_seek_hdlr.callback(MDI_FMR_CB_REASON_PROCESS,
                                             (U16)g_mdi_fmr_seek_hdlr.start_freq,
                                             MMI_FALSE,
                                             g_mdi_fmr_seek_hdlr.user_data);
            }

            /* Continue seek process */
            if (g_mdi_fmr_seek_hdlr.is_step_up)
            {
                if (g_mdi_fmr_seek_hdlr.start_freq == MDI_FMR_MAX_FREQ) /* Wrap around */
                {
                    g_mdi_fmr_seek_hdlr.start_freq = MDI_FMR_MIN_FREQ;
                }
                else
                {
                    g_mdi_fmr_seek_hdlr.start_freq ++;
                }
            }
            else
            {
                if (g_mdi_fmr_seek_hdlr.start_freq == MDI_FMR_MIN_FREQ) /* Wrap around */
                {
                    g_mdi_fmr_seek_hdlr.start_freq = MDI_FMR_MAX_FREQ;
                }
                else
                {
                    g_mdi_fmr_seek_hdlr.start_freq --;
                }
            }
            
            mdi_fmr_check_is_valid_stop(g_mdi_fmr_seek_hdlr.start_freq,
                                        g_mdi_fmr_seek_hdlr.is_step_up,
                                        mdi_fmr_sw_seek_callback);
        }
    }
}
#endif /*__PLUTO_MMI_PACKAGE__*/
#endif /* !__FM_RADIO_HW_SEARCH__ */

#ifndef __PLUTO_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_scan_start
 * DESCRIPTION
 *  This is a general function to perform a scan request, the MDI will use
 *  HW scan, HW search or SW scan per the capabilities of the platform.
 * PARAMETERS
 *  scan_req              : [IN]    Scan request
 * RETURNS
 *  MDI_AUDIO_SUCCESS     : Successful
 *  MDI_AUDIO_FAIL        : Failed for some reason
 *  MDI_AUDIO_BUSY        : The FMR is not in idle state
 *  MDI_AUDIO_PARAM_ERROR : Bad parameters
 *****************************************************************************/
S32 mdi_fmr_scan_start(mdi_fmr_scan_req_struct *scan_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check state */
    if (! mdi_audio_is_fm_on())
    {
        return MDI_AUDIO_FAIL;
    }

    if (g_mdi_fmr_state != MDI_FMR_STATE_IDLE)
    {
        return MDI_AUDIO_BUSY;
    }

    /* Check parameters */
    if (scan_req->max_channel == 0     ||
        scan_req->channel_list == NULL ||
        scan_req->callback == NULL)
    {
        return MDI_AUDIO_PARAM_ERROR;
    }

    /* Keep scan data */
    g_mdi_fmr_scan_hdlr.sorting      = scan_req->sorting;
    g_mdi_fmr_scan_hdlr.max_channel  = scan_req->max_channel;
    g_mdi_fmr_scan_hdlr.channel_list = scan_req->channel_list;
    g_mdi_fmr_scan_hdlr.callback     = scan_req->callback;
    g_mdi_fmr_scan_hdlr.user_data    = scan_req->user_data;

    /* Evaluate threshold */
    mdi_fmr_evaluate_threshold();
    
#if defined(__FM_RADIO_HW_SCAN__)
    /* Use HW scan */
    memset(g_mdi_fmr_scan_table,   0, sizeof(g_mdi_fmr_scan_table));

    mdi_fmr_hw_scan_start(MDI_FMR_MIN_FREQ,  /* don't care */
                          MMI_TRUE,          /* don't care */
                          g_mdi_fmr_scan_table,
                          MDI_FMR_SEEK_SAPCE,
                          mdi_fmr_hw_scan_callback);
    
#elif defined(__FM_RADIO_HW_SEARCH__)
    /* Use HW search to simulate the scan process */
    memset(g_mdi_fmr_scan_table,   0, sizeof(g_mdi_fmr_scan_table));

    mdi_fmr_freq_seek_start(MDI_FMR_MIN_FREQ,
                            MMI_TRUE,
                            MMI_TRUE,
                            MDI_FMR_SEEK_SAPCE,
                            mdi_fmr_hw_search_callback);
    
#else /* SW Scan */
    /* Use SW to simulate the scan process */
    memset(g_mdi_fmr_signal_level, 0, sizeof(g_mdi_fmr_signal_level));

    g_mdi_fmr_scan_count = 0;
    
    mdi_fmr_get_signal_level(MDI_FMR_MIN_FREQ,
                             MMI_TRUE,
                             mdi_fmr_sw_scan_callback);

#endif /* End of scan function */

    /* Enter scan state */
    g_mdi_fmr_state = MDI_FMR_STATE_SCAN;

    return MDI_AUDIO_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_scan_abort
 * DESCRIPTION
 *  This function is to abort a scan request.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_AUDIO_SUCCESS     : Successful
 *  MDI_AUDIO_FAIL        : Failed for some reason
 *****************************************************************************/
S32 mdi_fmr_scan_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mdi_fmr_state == MDI_FMR_STATE_SCAN)
    {
        /* Terminate scan process */
    #if defined(__FM_RADIO_HW_SCAN__)
        mdi_fmr_hw_scan_abort();
    #elif defined(__FM_RADIO_HW_SEARCH__)
        mdi_fmr_freq_seek_abort();
    #else /* SW scan */
        mdi_fmr_cancel_getting_signal_level();
    #endif /* __FM_RADIO_HW_SEARCH__ */

        /* Notify client the scan is aborted */
        if (g_mdi_fmr_scan_hdlr.callback)
        {
            g_mdi_fmr_scan_hdlr.callback(MDI_FMR_CB_REASON_ABORT, NULL, g_mdi_fmr_scan_hdlr.user_data);
        }

        /* Enter idle state */
        g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
    }

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_seek_start
 * DESCRIPTION
 *  This is a general function to perform seek request, the MDI will use HW
 *  search or SW search per the capabilities of the platform.
 * PARAMETERS
 *  seek_req              : [IN]    Seek request
 * RETURNS
 *  MDI_AUDIO_SUCCESS     : Successful
 *  MDI_AUDIO_FAIL        : Failed for some reason
 *  MDI_AUDIO_BUSY        : The FMR is not in idle state
 *  MDI_AUDIO_PARAM_ERROR : Bad parameters
 *****************************************************************************/
S32 mdi_fmr_seek_start(mdi_fmr_seek_req_struct *seek_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check state */
    if (! mdi_audio_is_fm_on())
    {
        return MDI_AUDIO_FAIL;
    }

    if (g_mdi_fmr_state != MDI_FMR_STATE_IDLE)
    {
        return MDI_AUDIO_BUSY;
    }

    /* Check parameters */
    if (seek_req->start_freq < MDI_FMR_MIN_FREQ ||
        seek_req->start_freq > MDI_FMR_MAX_FREQ ||
        seek_req->callback == NULL)
    {
        return MDI_AUDIO_PARAM_ERROR;
    }

    /* Keep scan data */
    g_mdi_fmr_seek_hdlr.callback  = seek_req->callback;
    g_mdi_fmr_seek_hdlr.user_data = seek_req->user_data;

    /* Evaluate threshold */
    mdi_fmr_evaluate_threshold();
    
#if defined(__FM_RADIO_HW_SEARCH__)
    /* Use HW search */
    mdi_fmr_freq_seek_start(seek_req->start_freq,
                            seek_req->is_step_up,
                            MMI_FALSE,
                            MDI_FMR_SEEK_SAPCE,
                            mdi_fmr_hw_seek_callback);

#else /* SW Search */
    /* Use SW to simulate the seek process */
    g_mdi_fmr_seek_hdlr.is_step_up = seek_req->is_step_up;

    /* Determine start/stop frequency */
    if (seek_req->is_step_up) /* Step up */
    {
        if (seek_req->start_freq == MDI_FMR_MAX_FREQ)
        {
            g_mdi_fmr_seek_hdlr.start_freq = MDI_FMR_MAX_FREQ;
        }
        else
        {
            g_mdi_fmr_seek_hdlr.start_freq = seek_req->start_freq + 1;
        }
        
        if (seek_req->start_freq == MDI_FMR_MIN_FREQ ||
            seek_req->stop_criteria == MDI_FMR_SEEK_STOP_AT_BOUNDARY)
        {
            g_mdi_fmr_seek_hdlr.stop_freq = MDI_FMR_MAX_FREQ;
        }
        else
        {
            g_mdi_fmr_seek_hdlr.stop_freq = seek_req->start_freq - 1;
        }
    }
    else /* Step down */
    {
        if (seek_req->start_freq == MDI_FMR_MIN_FREQ)
        {
            g_mdi_fmr_seek_hdlr.start_freq = MDI_FMR_MIN_FREQ;
        }
        else
        {
            g_mdi_fmr_seek_hdlr.start_freq = seek_req->start_freq - 1;
        }
        
        if (seek_req->start_freq == MDI_FMR_MAX_FREQ ||
            seek_req->stop_criteria == MDI_FMR_SEEK_STOP_AT_BOUNDARY)
        {
            g_mdi_fmr_seek_hdlr.stop_freq = MDI_FMR_MIN_FREQ;
        }
        else
        {
            g_mdi_fmr_seek_hdlr.stop_freq = seek_req->start_freq + 1;
        }
    }

    mdi_fmr_check_is_valid_stop(g_mdi_fmr_seek_hdlr.start_freq,
                                g_mdi_fmr_seek_hdlr.is_step_up,
                                mdi_fmr_sw_seek_callback);

#endif /* End of search function */

    /* Enter seek state */
    g_mdi_fmr_state = MDI_FMR_STATE_SEEK;

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_seek_abort
 * DESCRIPTION
 *  This function is to abort a seek request.
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_AUDIO_SUCCESS     : Successful
 *  MDI_AUDIO_FAIL        : Failed for some reason
 *****************************************************************************/
S32 mdi_fmr_seek_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_mdi_fmr_state == MDI_FMR_STATE_SEEK)
    {
        /* Terminate scan process */
    #if defined(__FM_RADIO_HW_SEARCH__)
        mdi_fmr_freq_seek_abort();
    #else /* SW scan */
        mdi_fmr_cancel_checking_is_valid_stop();
    #endif /* __FM_RADIO_HW_SEARCH__ */

        /* Notify client the seek is aborted */
        if (g_mdi_fmr_seek_hdlr.callback)
        {
            g_mdi_fmr_seek_hdlr.callback(MDI_FMR_CB_REASON_ABORT,
                                         g_mdi_fmr_seek_hdlr.start_freq,
                                         MMI_FALSE,
                                         g_mdi_fmr_seek_hdlr.user_data);
        }

        /* Enter idle state */
        g_mdi_fmr_state = MDI_FMR_STATE_IDLE;
    }

    return MDI_AUDIO_SUCCESS;
}

#endif /*__PLUTO_MMI_PACKAGE__*/
#endif /*__MMI_FM_RADIO__*/


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_evaluate_threshold
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_evaluate_threshold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_is_fm_on())
    {
        media_aud_fmr_evaluate_threshold(MOD_MMI);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_set_channel(MMI_BOOL is_mono)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_fmr_set_channel(MOD_MMI, is_mono);
}
/* FM Radio End */


/*-----------------------------------------------------------------------------
                                 FMR Record
 ----------------------------------------------------------------------------*/
#ifdef FM_RADIO_RECORD
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_start_record
 * DESCRIPTION
 *  This function is to start record for FM radio
 * PARAMETERS
 *  file_name       [?]         
 *  format          [IN]             
 *  handler         [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_fmr_start_record(void *file_name, U8 format, U8 quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_START_RECORD, mdi_audio_state, mdi_audio_mode);

    if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_FM_RECORD))
    {
        MDI_AUDIO_UNLOCK;
        return check_result;
    }

    /* Must turn on FM radio first */
    if (!(mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO))
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_FAIL;
    }

    mdi_audio_stop_background_timer();

    if ((result = media_aud_start_record(MOD_MMI, (kal_wchar*) file_name, format, quality, FALSE, MDI_INPUT_FMRR, 0, 0)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_RECORD;
        mdi_audio_mode = MDI_AUDIO_RECORD_FM_RADIO;
        SetProtocolEventHandler(mdi_fmr_record_finish_ind, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_record_finish_ind
 * DESCRIPTION
 *  This function is the callback function of finish FM radio record
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_fmr_record_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_finish_ind_struct *msg_p = (l4aud_media_record_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_RECORD_FINISH_IND, mdi_audio_state);
    if (mdi_audio_state == MDI_AUDIO_RECORD)
    {
        /* Go back to FM radio playing state */
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;

        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            // mdi_cb_handler=NULL; /* Clear at stop FM radio time.*/
            tmp_cb_handler(mdi_audio_get_event(msg_p->result), mdi_cb_data);
        }
        /* mdi_audio_start_background_timer(); */
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_stop_record
 * DESCRIPTION
 *  This function is to stop FM recording and call back to MMI.
 *  After calling this function, FM radio will still playing
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_fmr_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_FMR_RECORD_ONLY, mdi_audio_state);

    /* Need to chceck is recording before stop it ??? */
    mdi_fmr_stop_record_remain_on();

    if (mdi_cb_handler)
    {
        /* Still keep callback for playing */
        mdi_cb_handler(MDI_AUDIO_STOP_FM_RECORD, mdi_cb_data);
    }

    /* mdi_audio_start_background_timer(); */
    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_stop_record_only
 * DESCRIPTION
 *  This function is to stop FM recording but remain FM in power-on state
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result(?)
 *****************************************************************************/
static void mdi_fmr_stop_record_remain_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state == MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;    
        return;
    }

    /* Stop FM record */
    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND);
    media_aud_stop_record(MOD_MMI, SRC_LMMI);

    /* Remain in playing state */
    mdi_audio_state = MDI_AUDIO_PLAY;
    mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_pause_record
 * DESCRIPTION
 *  This function is to pause FM radio record
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_fmr_pause_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_PAUSE_RECORD, mdi_audio_state);

#if defined(__MTK_TARGET__)
    if ((result = media_aud_pause(MOD_MMI, SRC_LMMI)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_RECORD_PAUSED;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        /* mdi_cb_handler=NULL; */
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;
        /* mdi_audio_start_background_timer(); */
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
#else /* defined(__MTK_TARGET__) */ 
    result = MDI_AUDIO_SUCCESS;
    mdi_audio_state = MDI_AUDIO_RECORD_PAUSED;
    MDI_AUDIO_UNLOCK;
    return (mdi_result)result;
#endif /* defined(__MTK_TARGET__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_resume_record
 * DESCRIPTION
 *  This function is to resume FM radio record
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_fmr_resume_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_RESUME_RECORD, mdi_audio_state);

#if defined(__MTK_TARGET__)
    if ((result = media_aud_resume(MOD_MMI, SRC_LMMI)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_RECORD;
        mdi_audio_mode = MDI_AUDIO_RECORD_FM_RADIO;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;
        /* mdi_audio_start_background_timer(); */
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
#else /* defined(__MTK_TARGET__) */ 
    result = MDI_AUDIO_SUCCESS;
    mdi_audio_state = MDI_AUDIO_RECORD;
    mdi_audio_mode = MDI_AUDIO_RECORD_FM_RADIO;
    MDI_AUDIO_UNLOCK;
    return (mdi_result)result;
#endif /* defined(__MTK_TARGET__) */ 
}

#endif /* FM Record Enable */

/*-----------------------------------------------------------------------------
                                 FMR RDS
 ----------------------------------------------------------------------------*/
#ifdef __FM_RADIO_RDS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_fmr_rds_event_hdlr
 * DESCRIPTION
 *  Event indication handler for RDS event
 * PARAMETERS
 *  inMsg        [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_fmr_rds_event_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_rds_event_ind_struct *msg_p = (media_fmr_rds_event_ind_struct*)inMsg;
    mdi_rds_event_struct buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(buffer.data, msg_p->data, sizeof(U16) * FM_RDS_MAX_DATA_BUFF_SIZE);
    buffer.data_len = msg_p->data_len;
    buffer.event = msg_p->event;  
    buffer.freq = msg_p->frequency;
	
    switch (msg_p->event)
    {
    case MDI_RDS_EVENT_FLAGS:
        buffer.flag = msg_p->flag;
        break;
    default:
        buffer.flag = 0;
        break;
    }
    mdi_fmr_rds_callback(&buffer, g_rds_user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_enable
 * DESCRIPTION
 *  This function is to send RDS enable request
 * PARAMETERS
 *  callback      [IN]        
 *  af_enable     [IN]        
 *  tp_enable     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_fmr_rds_enable(void (*callback)(mdi_rds_event_struct* buffer, void* user_data), 
                         MMI_BOOL af_enable,
                         MMI_BOOL tp_enable,
                         void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_RDS_ENABLE, mdi_audio_state, mdi_audio_mode);

    if ((result = media_aud_fmr_rds_enable(MOD_MMI, af_enable, tp_enable)) == MED_RES_OK)
    {
        mdi_fmr_rds_callback = callback;
        g_rds_user_data = user_data;
        g_rds_enabled = MMI_TRUE;
        SetProtocolEventHandler(mdi_audio_fmr_rds_event_hdlr, MSG_ID_MEDIA_FMR_RDS_EVENT_IND);
    }

    return mdi_audio_get_event(result);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_af_tp_setting 
 * DESCRIPTION
 *  This function is to send RDS parameters update request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_fmr_rds_af_tp_setting(MMI_BOOL af_enable, MMI_BOOL tp_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_RDS_AF_TP_ENABLE, mdi_audio_state, mdi_audio_mode);

    if (!g_rds_enabled)
    {
        return MDI_AUDIO_FAIL;
    }
    if ((result = media_aud_fmr_rds_enable(MOD_MMI, af_enable, tp_enable)) == MED_RES_OK)
    {
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_disable
 * DESCRIPTION
 *  This function is to send RDS disable request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_rds_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_rds_enabled)
    {
        return;
    }
    media_aud_fmr_rds_disable(MOD_MMI);
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_FMR_RDS_EVENT_IND);

    /* Can be recording but not possible in current design */
    g_rds_enabled = MMI_FALSE;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_set_buffer
 * DESCRIPTION
 *  This function is to resolve buffer conflict in MED
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_rds_set_buffer(U16 *RT_Data, U16 *PS_Data, U16 *AF_Data, U16 *TP_Data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_fmr_rds_set_buffer(RT_Data, PS_Data, AF_Data, TP_Data);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_reset_buffer
 * DESCRIPTION
 *  This function is to resolve buffer conflict in MED
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_rds_reset_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_fmr_rds_reset_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_rds_poll_rds_event_rds
 * DESCRIPTION
 *  This function is to Poll for RDS log on getting RDS_EVENT_RDS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_fmr_rds_poll_rds_event_rds(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_rds_enabled)
    {
        return MDI_AUDIO_FAIL;
    }
    result = media_aud_fmr_rds_poll_rds_event_rds(MOD_MMI);

    return result;
}
#endif /* __FM_RADIO_RDS_SUPPORT__ */ 


/*-----------------------------------------------------------------------------
                                     VRSD
 ----------------------------------------------------------------------------*/
#ifdef VR_ENABLE
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_voice_tag
 * DESCRIPTION
 *  This function is to play vr voice tag
 * PARAMETERS
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_voice_tag(
            U8 mode,
            U8 lang,
            U8 group_id,
            U16 word_id,
            mdi_ext_callback handler,
            void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_VOICE_TAG, mode, lang, group_id, word_id, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_PLAYBACK))
    {
        MDI_AUDIO_UNLOCK;
        return check_result;
    }

    ++identifier;
    mdi_audio_stop_background_timer();

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

    if ((result = media_aud_vr_play_tag(MOD_MMI, mode, lang, group_id, word_id, identifier)) == MED_RES_OK)
    {
        mdi_cb_handler = handler;
        mdi_cb_data = user_data;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FILE;
        SetProtocolEventHandler(mdi_audio_play_finish_ind1, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_cb_handler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_rcg_result_ind
 * DESCRIPTION
 *  This function is to handle vr recognition result indication
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vr_rcg_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_rcg_result_ind_struct *msg_p = (media_vr_rcg_result_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VR_RCG_RESULT_IND, msg_p->result, mdi_audio_state);
    if (mdi_audio_state == MDI_AUDIO_RECORD)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            mdi_cb_handler = NULL;
            mdi_audio_vr_rcg_result_msg = msg_p;
            // TODO: Add MDI error type to mapping MED error, MMI should use MDI error value.
            tmp_cb_handler((mdi_result)msg_p->result, mdi_cb_data);
            mdi_audio_vr_rcg_result_msg = NULL;
        }
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_trn_result_ind
 * DESCRIPTION
 *  This function is to handle vr training result indication
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vr_trn_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_trn_result_ind_struct *msg_p = (media_vr_trn_result_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VR_TRN_RESULT_IND, msg_p->result, mdi_audio_state);
    if (mdi_audio_state == MDI_AUDIO_RECORD)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        if (mdi_cb_handler)
        {
            tmp_cb_handler = mdi_cb_handler;
            mdi_cb_handler = NULL;
            mdi_audio_vr_trn_result_msg = msg_p;
            // TODO: Add MDI error type to mapping MED error, MMI should use MDI error value.            
            tmp_cb_handler((mdi_result)msg_p->result, mdi_cb_data);
            mdi_audio_vr_trn_result_msg = NULL;
        }
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_rcg_session_id
 * DESCRIPTION
 *  This function is to get vr rcg session id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mdi_audio_vr_rcg_session_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_vr_rcg_result_msg != NULL)
    {
        return mdi_audio_vr_rcg_result_msg->session_id;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_trn_session_id
 * DESCRIPTION
 *  This function is to get vr trn session id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mdi_audio_vr_trn_session_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_vr_trn_result_msg != NULL)
    {
        return mdi_audio_vr_trn_result_msg->session_id;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_rcg_result_id_length
 * DESCRIPTION
 *  This function is to get vr rcg result id length
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mdi_audio_vr_rcg_result_id_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_vr_rcg_result_msg != NULL)
    {
        return mdi_audio_vr_rcg_result_msg->id_length;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_rcg_result_id_array
 * DESCRIPTION
 *  This function is to get vr rcg result id array
 * PARAMETERS
 *  void
 * RETURNS
 *  U16*
 *****************************************************************************/
U16 *mdi_audio_vr_rcg_result_id_array(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_vr_rcg_result_msg != NULL)
    {
        return mdi_audio_vr_rcg_result_msg->id_array;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_vr_voice_record
 * DESCRIPTION
 *  This function is to start vr voice record
 * PARAMETERS
 *  session_id      [IN]        
 *  seq_no          [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  U8 mode(?)
 *  U8 lang(?)
 *  U8 group_id(?)
 *  U16 word_id(?)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_start_vr_voice_record(U32 session_id, U8 seq_no, mdi_ext_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_VR_VOICE_RECORD, session_id, seq_no, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_PLAYBACK))
    {
        MDI_AUDIO_UNLOCK;    
        return check_result;
    }

    mdi_audio_stop_background_timer();

    if ((result = media_aud_vr_voice_in(MOD_MMI, session_id, seq_no)) == MED_RES_OK)
    {
        mdi_cb_handler = handler;
        mdi_cb_data = user_data;
        mdi_audio_state = MDI_AUDIO_RECORD;
        mdi_audio_mode = MDI_AUDIO_RECORD_VR_VOICE;
        SetProtocolEventHandler(mdi_audio_vr_rcg_result_ind, MSG_ID_MEDIA_VR_RCG_RESULT_IND);
        SetProtocolEventHandler(mdi_audio_vr_trn_result_ind, MSG_ID_MEDIA_VR_TRN_RESULT_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_cb_handler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_vr_voice_record
 * DESCRIPTION
 *  This function is to stop vr voice record.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_vr_voice_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_VR_VOICE_RECORD, mdi_audio_state);
    media_aud_vr_abort(MOD_MMI);

    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VR_RCG_RESULT_IND);
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VR_TRN_RESULT_IND);

    mdi_audio_state = MDI_AUDIO_IDLE;
    if (mdi_cb_handler)
    {
        tmp_cb_handler = mdi_cb_handler;
        mdi_cb_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
    }
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_abort
 * DESCRIPTION
 *  This function is to abort vr.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result(?)
 *****************************************************************************/
void mdi_audio_vr_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state == MDI_AUDIO_RECORD && mdi_audio_mode == MDI_AUDIO_RECORD_VR_VOICE)
    {
        mdi_audio_stop_vr_voice_record();
    }
    else
    {
        media_aud_vr_abort(MOD_MMI);
    }
    MDI_AUDIO_UNLOCK;
}
#endif /* VR_ENABLE */ 

/*-----------------------------------------------------------------------------
                                     VRSI
 ----------------------------------------------------------------------------*/
#ifdef VRSI_ENABLE
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_trn_prompt_req_hdlr
 * DESCRIPTION
 *  This function is to inform MMI to prompt user training stage.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_trn_prompt_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_trn_prompt_req_struct *msg_p = (media_vrsi_trn_prompt_req_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_TRN_PROMPT_REQ_HDLR, mdi_audio_state);

    switch (msg_p->pmp_mode)
    {
        case MED_VRSI_1ST_TRN_PROMPT:
            vrsi_handler(MED_VRSI_TRAIN_TAG_1ST_MPR, vrsi_user_data);
            break;
        case MED_VRSI_2ND_TRN_PROMPT:
            vrsi_handler(MED_VRSI_TRAIN_TAG_2ND_MPR, vrsi_user_data);
            break;
        case MED_VRSI_1ST_DGT_ADP_PROMPT:
        case MED_VRSI_2ND_DGT_ADP_PROMPT:
            vrsi_handler(MED_VRSI_DIGIT_ADAPT_MPR, vrsi_user_data);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_trn_result_ind
 * DESCRIPTION
 *  This function is to inform MMI train result.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_trn_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_trn_result_ind_struct *msg_p = (media_vrsi_trn_result_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_TRN_RESULT_IND, mdi_audio_state);

    if (msg_p->tag_id == 0)
    {
        vrsi_handler(MED_VRSI_DIGIT_ADAPT_OK, vrsi_user_data);
    }
    else
    {
        vrsi_handler(MED_VRSI_TRAIN_TAG_OK, vrsi_user_data);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_rcg_prompt_req_hdlr
 * DESCRIPTION
 *  This function is to inform MMI to prompt user recognition stage.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_rcg_prompt_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_rcg_prompt_req_struct *msg_p = (media_vrsi_rcg_prompt_req_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_RCG_PROMPT_REQ_HDLR, mdi_audio_state);

    switch (msg_p->pmp_mode)
    {
        case MED_VRSI_CMD_RCG_PROMPT:
            vrsi_handler(MED_VRSI_RECOG_MPR, vrsi_user_data);
            break;
        case MED_VRSI_DGT_RCG_PROMPT:
            vrsi_handler(MED_VRSI_DIGIT_RECOG_MPR, vrsi_user_data);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_rcg_result_ind
 * DESCRIPTION
 *  This function is to inform MMI recognition result.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_rcg_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_rcg_result_ind_struct *msg_p = (media_vrsi_rcg_result_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_RCG_RESULT_IND, mdi_audio_state);

    if (msg_p->res_type == 0)
    {
        vrsi_handler(MED_VRSI_DIGIT_RECOG_OK, vrsi_user_data);
    }
    else
    {
        vrsi_handler(MED_VRSI_RECOG_OK, vrsi_user_data);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_err_ind
 * DESCRIPTION
 *  This function is the error indication.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_err_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* media_vrsi_err_ind_struct* msg_p=(media_vrsi_err_ind_struct*)inMsg; */

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_ERR_IND, mdi_audio_state);

    vrsi_handler(MED_VRSI_ERROR, vrsi_user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_init
 * DESCRIPTION
 *  This function is to init vrsi engine.
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_vrsi_init(U16 app_id, mdi_ext_callback handler, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_INIT);

    if ((result = media_aud_vrsi_init(MOD_MMI, app_id)) == MED_RES_OK)
    {
        vrsi_handler = handler;
        vrsi_user_data = user_data;
        SetProtocolEventHandler(mdi_audio_vrsi_trn_prompt_req_hdlr, MSG_ID_MEDIA_VRSI_TRN_PROMPT_REQ);
        SetProtocolEventHandler(mdi_audio_vrsi_trn_result_ind, MSG_ID_MEDIA_VRSI_TRN_RESULT_IND);
        SetProtocolEventHandler(mdi_audio_vrsi_rcg_prompt_req_hdlr, MSG_ID_MEDIA_VRSI_RCG_PROMPT_REQ);
        SetProtocolEventHandler(mdi_audio_vrsi_rcg_result_ind, MSG_ID_MEDIA_VRSI_RCG_RESULT_IND);
        SetProtocolEventHandler(mdi_audio_vrsi_err_ind, MSG_ID_MEDIA_VRSI_ERR_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_new_session_id
 * DESCRIPTION
 *  This function is to get a new session id.
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mdi_audio_vrsi_new_session_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_mdi_vrsi_session = media_aud_vrsi_new_session_id();
    return g_mdi_vrsi_session;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_stop
 * DESCRIPTION
 *  This function is to stop a vrsi action.
 * PARAMETERS
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_stop(U32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_STOP, session_id, mdi_audio_state);
    media_aud_vrsi_abort(MOD_MMI, session_id);
    if (mdi_audio_state == MDI_AUDIO_VRSI_PROCESS)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_close
 * DESCRIPTION
 *  This function is to close vrsi engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_CLOSE, mdi_audio_state);
    media_aud_vrsi_close(MOD_MMI);
    if (mdi_audio_state == MDI_AUDIO_VRSI_PROCESS)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_play_tag_finish_ind
 * DESCRIPTION
 *  This function is the play tag finish indication.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_play_tag_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_play_tag_finish_ind_struct *msg_p = (media_vrsi_play_tag_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_PLAY_TAG_FINISH_IND, mdi_audio_state);
    if ((mdi_audio_state == MDI_AUDIO_VRSI_PROCESS && mdi_audio_mode == MDI_AUDIO_VRSI_PLAY_TAG)
        && msg_p->session_id == identifier)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        vrsi_handler(MED_VRSI_PLAY_TAG_OK, vrsi_user_data);
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_play_tag
 * DESCRIPTION
 *  This function is to play vrsi pre-record tag.
 * PARAMETERS
 *  session_id      [IN]        
 *  grammar         [?]         
 *  tag_id          [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_vrsi_play_tag(U32 session_id, U8 *grammar, U16 tag_id, U8 volume, U8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_PLAY_TAG, session_id, tag_id, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_PLAYBACK))
    {
        MDI_AUDIO_UNLOCK;    
        return check_result;
    }

    identifier = session_id;
    mdi_audio_stop_background_timer();

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_set_volume_to_bt(volume);
#endif

    if ((result = media_aud_vrsi_play_tag(MOD_MMI, session_id, grammar, tag_id, volume, output_path)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_VRSI_PROCESS;
        mdi_audio_mode = MDI_AUDIO_VRSI_PLAY_TAG;
        SetProtocolEventHandler(mdi_audio_vrsi_play_tag_finish_ind, MSG_ID_MEDIA_VRSI_PLAY_TAG_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        // TODO: Add MDI error type to mapping MED error, MMI should use MDI error value.
        return (mdi_result)result;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_play_tts_finish_ind
 * DESCRIPTION
 *  This function is the play TTS finish indication.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_play_tts_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_play_tts_finish_ind_struct *msg_p = (media_vrsi_play_tts_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_PLAY_TTS_FINISH_IND, mdi_audio_state);
    if ((mdi_audio_state == MDI_AUDIO_VRSI_PROCESS && mdi_audio_mode == MDI_AUDIO_VRSI_PLAY_TTS)
        && msg_p->session_id == identifier)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        vrsi_handler(MED_VRSI_TTS_OK, vrsi_user_data);
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_play_TTS
 * DESCRIPTION
 *  This function is to play vrsi TTS.
 * PARAMETERS
 *  session_id      [IN]        
 *  text            [?]         
 *  volume          [IN]        
 *  output_path     [IN]        
 *  lang            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_vrsi_play_TTS(U32 session_id, U16 *text, U8 volume, U8 output_path, U8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result check_result;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_PLAY_TTS, session_id, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_PLAYBACK))
    {
        MDI_AUDIO_UNLOCK;    
        return check_result;
    }

    identifier = session_id;
    mdi_audio_stop_background_timer();

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_set_volume_to_bt(volume);
#endif

    if ((result = media_aud_vrsi_play_TTS(MOD_MMI, session_id, text, volume, output_path, lang)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_VRSI_PROCESS;
        mdi_audio_mode = MDI_AUDIO_VRSI_PLAY_TTS;
        SetProtocolEventHandler(mdi_audio_vrsi_play_tts_finish_ind, MSG_ID_MEDIA_VRSI_PLAY_TTS_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_register_record
 * DESCRIPTION
 *  This function is to change vrsi state to record state.
 *  Note: the function is called by L1Audio task, shall modify it!!
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_register_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not add LOCK here or it will dead lock due to this function called by L1audio task */
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_REGISTER_RECORD, mdi_audio_state);
    mdi_audio_state = MDI_AUDIO_VRSI_PROCESS;
    mdi_audio_mode = MDI_AUDIO_VRSI_RECORD;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_unregister_record
 * DESCRIPTION
 *  This function is to change vrsi state to idle state.
 *  Note: the function is called by L1Audio task, shall modify it!!
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_unregister_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not add LOCK here or it will dead lock due to this function called by L1audio task */
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_UNREGISTER_RECORD, mdi_audio_state);
    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_mode = MDI_AUDIO_VRSI_RECORD;
}
#endif /* VRSI_ENABLE */ 


/*-----------------------------------------------------------------------------
                                     TTS
 ----------------------------------------------------------------------------*/
#if defined(SIMPLE_TTS)
/*****************************************************************************
 * FUNCTION
 *  BinarySearch
 * DESCRIPTION
 *  This function is to perform a binary search in a index sorted table
 * PARAMETERS
 *  key                 [IN]        
 *  lookup_table        [IN]        
 *  start               [IN]        
 *  end                 [IN]        
 * RETURNS
 *  short
 *****************************************************************************/
static short BinarySearch(const unsigned char key, const unsigned char *lookup_table, short start, short end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (start <= end)
    {
        short mid = (start + end) / 2;

        if (key > lookup_table[mid])
        {
            start = mid + 1;
        }
        else if (key < lookup_table[mid])
        {
            end = mid - 1;
        }
        else    /* key == target */
        {
            return mid;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  LookupTTS
 * DESCRIPTION
 *  This function is to lookup the sound index from TTS database
 * PARAMETERS
 *  ucs2        [IN]        
 * RETURNS
 *  short
 *****************************************************************************/
static short LookupTTS(unsigned short ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char key_MSB = (unsigned char)(ucs2 >> 8);
    unsigned char key_LSB;
    short start = g_mdi_TTS_UCS2_MSB_index[key_MSB].start;
    short end;
    short index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start < 0)  /* key MSB not found in index table */
    {
        return -1;
    }

    key_LSB = (unsigned char)(ucs2 & 0xff);
    end = g_mdi_TTS_UCS2_MSB_index[key_MSB].end;
    if ((index = BinarySearch(key_LSB, g_mdi_TTS_UCS2_LSB, start, end)) < 0)  /* key LSB not found */
    {
        return -1;
    }

    return g_mdi_TTS_index_table[index];
}
#endif /* defined(SIMPLE_TTS) */ 

#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_word_resource
 * DESCRIPTION
 *  This function is to get the associated audio resource with the given word, which is a UCS2 char
 * PARAMETERS
 *  U16     [IN]        Word
 * RETURNS
 *  audio_resource_struct*
 *****************************************************************************/
S32 mdi_audio_get_word_resource(U16 cursor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(DIGIT_TONE_SUPPORT)
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cursor >= L'0' && cursor <= L'9')
    {
        i = (S32) (cursor - L'0');
    }
    else if (cursor == L'*')
    {
        i = 10;
    }
    else if (cursor == L'#')
    {
        i = 11;
    }
    else if (cursor == L'+')
    {
        i = 12;
    }
    else
    {
        i = -1;
    }
    if (i >= 0)
    {
        srv_prof_keypad_tone_type_enum keypad_tone_type;
        U16 audio_id;

        if(srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_KEYPAD_TONE_TYPE, (void*)&keypad_tone_type) == SRV_PROF_RET_SUCCESS)
        {
            audio_id = srv_prof_get_special_key_tone_audio_id(keypad_tone_type, i);
            if(audio_id > 0)
            {
                return audio_id;
            }
        }

        return -1;
    }
    else
#endif /* defined(DIGIT_TONE_SUPPORT) */ 
    {
    #if defined(SIMPLE_TTS)
        S16 tts_index = LookupTTS(cursor);

        if (tts_index < 0)
        {
            return -1;
        }
        
        return (AUD_ID_SIMPLE_TTS_1 + tts_index);
    #else /* defined(SIMPLE_TTS) */ 
        return -1;
    #endif /* defined(SIMPLE_TTS) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_handle_play_text_internal_callback
 * DESCRIPTION
 *  This function handle the play text internal callback
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  mdi_result(?)
 *****************************************************************************/
void mdi_audio_handle_play_text_internal_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_play_text_context.state = MDI_AUDIO_PLAY_TEXT_IDLE_STATE;
    //StopTimer(MDI_AUDIO_PLAYER_TEXT_TIMER);
    gui_cancel_timer(mdi_audio_play_timeout_handler);
    tmp_cb_handler = mdi_audio_play_text_context.handler;
    if (tmp_cb_handler != NULL)
    {
        mdi_audio_play_text_context.handler = NULL;
        tmp_cb_handler(result, mdi_audio_play_text_context.user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_current_word
 * DESCRIPTION
 *  This function play the word indicated by cursor
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_current_word(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    S32 aud_res_id;
    U32 audio_len;
    U8 *audio_data;
    U8 audio_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_play_text_context.len <= 0)
    {
        result = MDI_AUDIO_FAIL;
    }
    else
    {
        do
        {
            aud_res_id = mdi_audio_get_word_resource(mdi_audio_play_text_context.words[++mdi_audio_play_text_context.cursor]);
        } while (aud_res_id < 0 && mdi_audio_play_text_context.cursor < mdi_audio_play_text_context.len - 1);

        if (aud_res_id < 0)
        {
            /* pretend it's playing */
            mdi_cb_handler = mdi_audio_play_text_event_handler; /* we hook up current handler to keep ourself being notified when other requests come */
            mdi_cb_data = NULL;
            mdi_audio_state = MDI_AUDIO_PLAY;
            mdi_audio_mode = MDI_AUDIO_PLAY_STRING;
            gui_start_timer(40, mdi_audio_play_timeout_handler);
            result = MDI_AUDIO_SUCCESS;
        }
        else
        {
            audio_data = get_audio((U16)aud_res_id, &audio_type, &audio_len);

            result = mdi_audio_play_string_with_vol_path(
                        (void*)audio_data,
                        audio_len,
                        (U8) audio_type,
                        DEVICE_AUDIO_PLAY_ONCE,
                        mdi_audio_play_text_event_handler,
                        NULL,
                        mdi_audio_play_text_context.volume,
                        mdi_audio_play_text_context.path);

            mdi_audio_play_text_context.identifier = identifier;
        }
    }
    if (result == MDI_AUDIO_SUCCESS)
    {
        mdi_audio_play_text_context.state = MDI_AUDIO_PLAY_TEXT_PLAY_STATE;
    }
    else
    {
        mdi_audio_handle_play_text_internal_callback(result);
    }

    MDI_AUDIO_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_timeout_handler
 * DESCRIPTION
 *  time expired event handler for a short period of time after finish playing a number or word
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_play_timeout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    mdi_cb_handler = NULL;  /* clear the hook up */
    if (mdi_audio_play_text_context.cursor < mdi_audio_play_text_context.len - 1)
    {
        mdi_audio_play_current_word();
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_play_text_event_handler(MDI_AUDIO_END_OF_FILE, NULL);
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_text_event_handler
 * DESCRIPTION
 *  This function is to handle events during playing text
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_play_text_event_handler(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_PLAY_STATE)
    {
        if (result == MDI_AUDIO_END_OF_FILE && mdi_audio_play_text_context.cursor < mdi_audio_play_text_context.len - 1)
        {
            /* need to play more words */
            mdi_audio_play_text_context.state = MDI_AUDIO_PLAY_TEXT_WAIT_STATE;
            mdi_cb_handler = mdi_audio_play_text_event_handler; /* we hook up current handler to keep ourself being notified when other requests come */
            mdi_cb_data = NULL;
            //StartTimer(MDI_AUDIO_PLAYER_TEXT_TIMER, mdi_audio_play_text_context.msecs, mdi_audio_play_timeout_handler);
        #ifdef __MMI_BTBOX_NOLCD__
            mdi_audio_play_timeout_handler();
        #else /* __MMI_BTBOX_NOLCD__ */
            gui_start_timer(mdi_audio_play_text_context.msecs, mdi_audio_play_timeout_handler);
        #endif /* __MMI_BTBOX_NOLCD__ */
        }
        else
        {
            mdi_audio_handle_play_text_internal_callback(result);
        }
    }
    else if (mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_WAIT_STATE)
    {
        mdi_audio_handle_play_text_internal_callback(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_text_with_vol_path
 * DESCRIPTION
 *  This function is to play text (number or words)
 * PARAMETERS
 *  words           [?]         
 *  len             [IN]        
 *  msecs           [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  volume          [IN]        
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_text_with_vol_path(
            U8 *words,
            S32 len,
            S32 msecs,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mdi_audio_check_states_and_handlers(&result, MDI_AUDIO_CHECK_REASON_PLAYBACK))
    {
        return result;
    }
    mdi_audio_play_text_context.cursor = -1;
    mdi_audio_play_text_context.len = len;
    mdi_audio_play_text_context.msecs = (msecs > 0) ? msecs : 10;
    /* to avoid 2 bytes alignment issue, copy text to the internal buffer, which is 2 bytes alignment */
    if (len > MDI_MAX_PLAY_TEXT_LEN)
    {
        len = MDI_MAX_PLAY_TEXT_LEN;
    }
    memcpy(mdi_audio_play_text_context.words, words, len << 1);
    mdi_audio_play_text_context.volume = volume;
    mdi_audio_play_text_context.path = path;
    result = mdi_audio_play_current_word();
    if (result == MDI_AUDIO_SUCCESS)
    {
        mdi_audio_play_text_context.handler = handler;
        mdi_audio_play_text_context.user_data = user_data;
    }
    return result;
}
#endif /* #if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */


#ifdef __GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_set_attr
 * DESCRIPTION
 *  This function is to set tts play attribute. 
 *  Note: This function need to call immediately before each play request.
 * PARAMETERS
 *  attr_id       [IN]  attribute id
 *  attr_value    [IN]  attribute value
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_set_attr(U32 attr_id, U32 attr_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_SET_ATTR, mdi_audio_state, attr_id, attr_value);

    result = media_aud_tts_set_attr_req(MOD_MMI, attr_id, attr_value);

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_play_update_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attr_id       [IN]  attribute id
 *  attr_value    [IN]  attribute value
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_tts_play_update_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //media_aud_tts_update_info_ind_struct *msg_p = (media_aud_tts_update_info_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_PLAY_UPDATE_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_play
 * DESCRIPTION
 *  This function is to request TTS string.
 * PARAMETERS
 *  tts_param       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_play(mdi_audio_tts_struct tts_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_tts_struct aud_tts;
    mdi_result check_result;
    S32 result;
#ifdef IFLY_TTS
    kal_wchar debug_print[22];
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_PLAY, mdi_audio_state);

    /* Print 20 characters for GIS debug in IFLY engine */
#ifdef IFLY_TTS
    kal_wstrncpy(debug_print, tts_param.text_string, 20);
    mmi_wprintf(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G10_MMI_PRINT, debug_print);
#endif

    if (!mdi_audio_check_states_and_handlers(&check_result, MDI_AUDIO_CHECK_REASON_PLAYBACK))
    {
        MDI_AUDIO_UNLOCK;    
        return check_result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

    aud_tts.text_string = tts_param.text_string;
    aud_tts.str_type = tts_param.str_type;
    aud_tts.lang = tts_param.lang;
    aud_tts.app_type = tts_param.app_type;
    aud_tts.gander = tts_param.gander;
    aud_tts.volume = tts_param.volume;
    aud_tts.path = tts_param.path;
    aud_tts.pitch = tts_param.pitch;
    aud_tts.speed = tts_param.speed;
    aud_tts.identifier = identifier;
    aud_tts.app_id = tts_param.app_id;
    
    if ((result = media_aud_tts_play_req(MOD_MMI, &aud_tts)) == MED_RES_OK)
    {
        mdi_cb_handler = tts_param.callback;
        mdi_cb_data = tts_param.user_data;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_TTS;
        SetProtocolEventHandler(mdi_audio_play_finish_ind1, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND);
        SetProtocolEventHandler(mdi_audio_tts_play_update_ind, MSG_ID_MEDIA_AUD_TTS_UPDATE_INFO_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_cb_handler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_stop
 * DESCRIPTION
 *  This function is to stop playing TTS string.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_STOP, mdi_audio_state, mdi_audio_mode);

    /*
     * set pseudo play file callback to NULL before callback
     * bcoz we could set another callback during callback
     */
    if (pseudo_play_handler)
    {
        tmp_cb_handler = pseudo_play_handler;
        pseudo_play_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, pseudo_play_data);
    }

    if (!((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
          && mdi_audio_mode == MDI_AUDIO_PLAY_TTS))
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }

    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_PLAY_FINISH_IND);
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_TTS_UPDATE_INFO_IND);
    media_aud_tts_stop_req(MOD_MMI);

    if (mdi_cb_handler)
    {
        tmp_cb_handler = mdi_cb_handler;
        mdi_cb_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, mdi_cb_data);
    }
    updateDurHandler = NULL;

    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_pause
 * DESCRIPTION
 *  This function is to pause playing TTS string.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_PAUSE, mdi_audio_state);

    if ((result = media_aud_tts_pause_req(MOD_MMI)) == MED_RES_OK)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY)
        {
            mdi_audio_state = MDI_AUDIO_PLAY_PAUSED;
        }
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_cb_handler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_resume
 * DESCRIPTION
 *  This function is to resume playing TTS string.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_RESUME, mdi_audio_state);

    if ((result = media_aud_tts_resume_req(MOD_MMI)) == MED_RES_OK)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
        {
            mdi_audio_state = MDI_AUDIO_PLAY;
        }
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_cb_handler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}
#endif /*__GENERAL_TTS__*/


/*-----------------------------------------------------------------------------
                             Background Sound
 ----------------------------------------------------------------------------*/
#if defined(BGSND_ENABLE)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_is_idle
 * DESCRIPTION
 *  This function is to check if the background sound playing
 * PARAMETERS
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_snd_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_idle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    is_idle = (snd_audio_state == MDI_AUDIO_IDLE);
    MDI_AUDIO_UNLOCK;
    return is_idle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_check_string_format
 * DESCRIPTION
 *  This function is to check if the audio string resource fit the background sound format
 * PARAMETERS
 *  audio_data      [?]         audio resource data pointer
 *  len             [IN]        audio resource data length
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_check_string_format(void *audio_data, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_snd_check_byte_stream_format(MOD_MMI, (kal_uint8*) audio_data, len);
    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_check_file_format
 * DESCRIPTION
 *  This function is to check if the external file fit the background sound format
 * PARAMETERS
 *  file_name       [?]     external file path
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_check_file_format(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 check_result;
#ifdef __DRM_SUPPORT__
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check DRM right */

    result = mdi_audio_drm_validate_right((U16*)file_name);

    if(result != MDI_AUDIO_SUCCESS)
    {
        return result;
    }
#endif /*__DRM_SUPPORT__*/

    check_result = media_aud_snd_check_file_format(MOD_MMI, (kal_wchar*) file_name);
    return mdi_audio_get_event(check_result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_play_string_with_vol_path
 * DESCRIPTION
 *  This function is to play audio string with volume and path
 * PARAMETERS
 *  audio_data      [?]         audio data pointer
 *  len             [IN]        audio data length
 *  repeat          [IN]        repeat times. (0: infinite)
 *  handle_p        [?]         reserved
 *  handler         [IN]        play finish callback function
 *  volume          [IN]        output volume
 *  path            [IN]        output path
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_play_string_with_vol_path(
            void *audio_data,
            U32 len,
            U16 repeat,
            mdi_ext_callback handler,
            void* user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_PLAY_STRING_WITH_VOL_PATH, snd_audio_state);

    if (snd_audio_state != MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BUSY;
    }

#ifdef __BT_SPK_VOL_CONTROL__
    /* The input volume if from 1 ~ 7, and shall only set in idle mode. */
    if(!mdi_audio_is_speech_mode())
    {
        mdi_audio_set_volume_to_bt(volume-1);
    }
#endif
    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

    g_mdi_aud_bgsnd_identifier++;
    if ((result = media_aud_snd_play_byte_stream(
                    MOD_MMI,
                    (kal_uint8*) audio_data,
                    len,
                    repeat,
                    MED_TYPE_WAV,
                    volume,
                    path,
                    g_mdi_aud_bgsnd_identifier)) == MED_RES_OK)
    {
        snd_crnt_handler = handler;
        snd_user_data = user_data;
        snd_audio_state = MDI_AUDIO_PLAY;
        SetProtocolEventHandler(mdi_audio_snd_play_finish_ind, MSG_ID_MEDIA_SND_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        snd_crnt_handler = NULL;
        snd_audio_state = MDI_AUDIO_IDLE;
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_play_string_with_vol_path_type
 * DESCRIPTION
 *  This function is to play audio string with volume and path
 * PARAMETERS
 *  audio_data      [?]         audio data pointer
 *  len             [IN]        audio data length
 *  repeat          [IN]        repeat times. (0: infinite)
 *  handle_p        [?]         reserved
 *  handler         [IN]        play finish callback function
 *  volume          [IN]        output volume
 *  path            [IN]        output path
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_play_string_with_vol_path_type(
            void *audio_data,
            U32 len,
            U16 repeat,
            U8 format,
            mdi_ext_callback handler,
            void* user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_PLAY_STRING_WITH_VOL_PATH, snd_audio_state);

    if (snd_audio_state != MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BUSY;
    }

#ifdef __BT_SPK_VOL_CONTROL__
    /* The input volume if from 1 ~ 7, and shall only set in idle mode. */
    if(!mdi_audio_is_speech_mode())
    {
        mdi_audio_set_volume_to_bt(volume-1);
    }
#endif
    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

    g_mdi_aud_bgsnd_identifier++;
    if ((result = media_aud_snd_play_byte_stream(
                    MOD_MMI,
                    (kal_uint8*) audio_data,
                    len,
                    repeat,
                    format,
                    volume,
                    path,
                    g_mdi_aud_bgsnd_identifier)) == MED_RES_OK)
    {
        snd_crnt_handler = handler;
        snd_user_data = user_data;
        snd_audio_state = MDI_AUDIO_PLAY;
        SetProtocolEventHandler(mdi_audio_snd_play_finish_ind, MSG_ID_MEDIA_SND_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        snd_crnt_handler = NULL;
        snd_audio_state = MDI_AUDIO_IDLE;
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_play_file_with_vol_path
 * DESCRIPTION
 *  This function is to play external file with volume and path
 * PARAMETERS
 *  file_name       [?]         external file
 *  repeat          [IN]        repeat times. (0: infinite)
 *  handle_p        [?]         reserved
 *  handler         [IN]        play finish callback function
 *  volume          [IN]        output volume
 *  path            [IN]        output path
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_play_file_with_vol_path(
            void *file_name,
            U16 repeat,
            mdi_ext_callback handler,
            void *user_data,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
#ifdef __DRM_SUPPORT__
    mdi_result drm_result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_PLAY_FILE_WITH_VOL_PATH, snd_audio_state);

    /* Check background sound state */
    if (snd_audio_state != MDI_AUDIO_IDLE)
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL;
#endif /*__DRM_SUPPORT__*/
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BUSY;
    }

    /* Check DRM right */
#ifdef __DRM_SUPPORT__
    drm_result = mdi_audio_drm_validate_right((U16*)file_name);

    if(drm_result != MDI_AUDIO_SUCCESS)
    {
        mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL;
        MDI_AUDIO_UNLOCK;
        return drm_result;
    }
#endif /*__DRM_SUPPORT__*/

#ifdef __BT_SPK_VOL_CONTROL__
    /* The input volume if from 1 ~ 7, and shall only set in idle mode. */
    if(!mdi_audio_is_speech_mode())
    {
        mdi_audio_set_volume_to_bt(volume-1);
    }
#endif
    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_connect_audio_via_sco();
#endif

    g_mdi_aud_bgsnd_identifier++;

    if ((result = media_aud_snd_play_file(MOD_MMI, (kal_wchar*) file_name, repeat, volume, path,g_mdi_aud_bgsnd_identifier)) == MED_RES_OK)
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_right((U16*)file_name, 0, &mdi_audio_drm_bgsnd_id, mdi_audio_drm_bgsnd_timeout_callback);
#endif /*__DRM_SUPPORT__*/
        snd_crnt_handler = handler;
        snd_user_data = user_data;
        snd_audio_state = MDI_AUDIO_PLAY;
        SetProtocolEventHandler(mdi_audio_snd_play_finish_ind, MSG_ID_MEDIA_SND_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_rule = MDI_AUD_DRM_CONSUME_ALL;
#endif /*__DRM_SUPPORT__*/
        snd_crnt_handler = NULL;
        snd_audio_state = MDI_AUDIO_IDLE;
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_play_finish_ind
 * DESCRIPTION
 *  This function is the callback funtion when play finish
 * PARAMETERS
 *  inMsg       [?]     result indication message
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_snd_play_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_play_finish_ind_struct *msg_p = (media_snd_play_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_PLAY_FINISH_IND, snd_audio_state, g_mdi_aud_bgsnd_identifier);

#ifdef __DRM_SUPPORT__
    if(mdi_audio_drm_bgsnd_id >= 0)
    {
        DRM_stop_consume(mdi_audio_drm_bgsnd_id);
        mdi_audio_drm_bgsnd_id = -1;
    }
#endif /*__DRM_SUPPORT__*/

    if ((snd_audio_state == MDI_AUDIO_PLAY) && (msg_p->identifier == g_mdi_aud_bgsnd_identifier))
    {
        snd_audio_state = MDI_AUDIO_IDLE;
        if (snd_crnt_handler)
        {
            tmp_cb_handler = snd_crnt_handler;
            snd_crnt_handler = NULL;
            tmp_cb_handler(mdi_audio_get_event(msg_p->result), snd_user_data);
        }
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_stop
 * DESCRIPTION
 *  This function is stop background sound play
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_STOP, snd_audio_state);

#ifdef __DRM_SUPPORT__
    if(mdi_audio_drm_bgsnd_id >= 0)
    {
        DRM_stop_consume(mdi_audio_drm_bgsnd_id);
        mdi_audio_drm_bgsnd_id = -1;
    }
#endif /*__DRM_SUPPORT__*/

    if (snd_audio_state == MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_SUCCESS;
    }

    ClearProtocolEventHandler(MSG_ID_MEDIA_SND_PLAY_FINISH_IND);
    media_aud_snd_stop_play(MOD_MMI);

    if (snd_crnt_handler)
    {
        tmp_cb_handler = snd_crnt_handler;
        snd_crnt_handler = NULL;
        tmp_cb_handler(MDI_AUDIO_TERMINATED, snd_user_data);
    }

    snd_audio_state = MDI_AUDIO_IDLE;

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_set_volume
 * DESCRIPTION
 *  This function is to change the volume of background play
 * PARAMETERS
 *  volume      [IN]        volume level (0~7, 0: mute)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_set_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (snd_audio_state != MDI_AUDIO_PLAY)
    {
        return MDI_AUDIO_FAIL;
    }

    /* Range is 0~7 */
    if (volume > 7)
    {
        volume = 7;
    }

    media_aud_snd_set_volume(MOD_MMI, volume);

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}

#endif /* defined(BGSND_ENABLE) */ 


/*-----------------------------------------------------------------------------
                                 Post-Processing
 ----------------------------------------------------------------------------*/
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_calc_spectrum
 * DESCRIPTION
 *  This function is to start to calculate the audio spectrum tops & vals.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_start_calc_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_CALC_SPECTRUM);

    aud_send_start_calc_spectrum_req();
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_calc_spectrum
 * DESCRIPTION
 *  This function is to stop calculating the audio spectrum tops & vals.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_calc_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_CALC_SPECTRUM);

    aud_send_stop_calc_spectrum_req();
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_spectrum
 * DESCRIPTION
 *  This function is to get the audio spectrum tops & vals.
 * PARAMETERS
 *  top_p       [?]     
 *  val_p       [?]     
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_spectrum(U8 *top_p, U8 *val_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = media_aud_get_spectrum(MOD_MMI, top_p, val_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_SPECTRUM_TOP, top_p[0], top_p[1], top_p[2], top_p[3], top_p[4], top_p[5], top_p[6], top_p[7], top_p[8], top_p[9], top_p[10], top_p[11], top_p[12], top_p[13], top_p[14], top_p[15]);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_SPECTRUM_VAL, val_p[0], val_p[1], val_p[2], val_p[3], val_p[4], val_p[5], val_p[6], val_p[7], val_p[8], val_p[9], val_p[10], val_p[11], val_p[12], val_p[13], val_p[14], val_p[15]);

    return mdi_audio_get_event(result);
}
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 


#if defined(__BES_TS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_check_string_format
 * DESCRIPTION
 *  This function is to check if the audio data spported in time stretch
 * PARAMETERS
 *  audio_data      [?]         audio data pointer
 *  len             [IN]        audio data length
 *  format          [IN]        audio data fomrat
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stretch_check_string_format(void *audio_data, U32 len, U16 format)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_stretch_check_stream_format(MOD_MMI, (kal_uint8*) audio_data, len, format);
    return mdi_audio_get_event((U8) result);

#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_check_file_format
 * DESCRIPTION
 *  This function is to check if the audio file spported in time stretch
 * PARAMETERS
 *  file_name       [?]     file name pointer
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stretch_check_file_format(void *file_name)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_stretch_check_file_format(MOD_MMI, (kal_wchar*) file_name);
    return mdi_audio_get_event((U8) result);

#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_set_speed
 * DESCRIPTION
 *  This function is to set audio time stretch speed
 * PARAMETERS
 *  speed       [IN]        Time stretch speed
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stretch_set_speed(U16 speed)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STRETCH_SET_SPEED, speed, mdi_aud_stretch_on);

    /* Set time stretch only when speed is not normal */
    if (speed != MDI_AUDIO_SPEED_NORMAL)
    {
        result = media_stretch_set_speed(MOD_MMI, speed);

        if (result == MED_RES_OK)
        {
            mdi_aud_stretch_on = TRUE;
        }
        else
        {
            mdi_aud_stretch_on = FALSE;
        }

        return mdi_audio_get_event(result);
    }
    else    /* Normal Speed */
    {
        mdi_audio_stretch_close();

        return MDI_AUDIO_SUCCESS;
    }

#else /* __MTK_TARGET__ */ 
    mdi_aud_stretch_on = TRUE;
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_close
 * DESCRIPTION
 *  This function is to close audio time stretch
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result(?)
 *****************************************************************************/
void mdi_audio_stretch_close(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_aud_stretch_on)
    {
        media_stretch_close(MOD_MMI);
    }
#endif /* __MTK_TARGET__ */ 

    mdi_aud_stretch_on = FALSE;
}
#endif /* #if defined(__BES_TS_SUPPORT__) */


#if defined(__BES_LIVE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_set_mode
 * DESCRIPTION
 *  This function is to set 3D coefficient
 * PARAMETERS
 *  coeff_table     [?]     3D coefficient table pointer
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_reverb_set_mode(U16 mode)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_reverb_set_mode(mode);
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_turn_on
 * DESCRIPTION
 *  This function is to turn on audio 3d effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_reverb_turn_on(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_reverb_turn_on_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_turn_off
 * DESCRIPTION
 *  This function is to turn off audio 3d effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_reverb_turn_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_reverb_turn_off_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */
}

#endif /* #if defined(__BES_LIVE_SUPPORT__) */ 

#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_surround_turn_on
 * DESCRIPTION
 *  This function is to turn on audio 3d effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_surround_turn_on(U8 mode)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_surround_turn_on_effect(mode);
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_surround_turn_off
 * DESCRIPTION
 *  This function is to turn off audio 3d effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_surround_turn_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_surround_turn_off_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}
#endif /*#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)*/


#if defined(__BES_EQ_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_set_magnitude
 * DESCRIPTION
 *  This function is to set equalizer magnitude
 * PARAMETERS
 *  magnitude     [?]     magnitude table pointer
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_eq_set_magnitude(S8 *magnitude)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_eq_set_magnitude((kal_int8*)magnitude);
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}

#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_transfer_magnitude
 * DESCRIPTION
 *  This function is to transfer equalizer magnitude between dirver's bands number,
 *  The size of the array shall be either NVRAM_EF_AUDIO_EQUALIZER_BAND_NUM or bar_num
    and mmi bar number
 * PARAMETERS
 *  magnitude_in     [IN]     magnitude table pointer for input
 *  magnitude_out    [OUT]    magnitude table pointer for output
 *  bar_num          [IN]     mmi bar number
 *  to_bar_num       [IN]     a boolean to indicate transfer to bar num or to band num
 *                            MMI_TRUE : to bar, 
 *                            MMI_FALSE: to band                            
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_eq_transfer_magnitude(S8 *magnitude_in, S8 *magnitude_out, U32 bar_num, MMI_BOOL to_bar_num)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(to_bar_num)
    {
        Media_Equalizer_TransformMag_ToBarNum((kal_int8*) magnitude_in, (kal_int8*) magnitude_out, (kal_uint32) bar_num);
    }
    else
    {
        Media_Equalizer_TransformMag_ToBandNum((kal_int8*) magnitude_in, (kal_int8*) magnitude_out, (kal_uint32) bar_num);
    }

    return MDI_AUDIO_SUCCESS;

#else /* __MTK_TARGET__ */ 
    memcpy(magnitude_out, magnitude_out, sizeof(U8)*bar_num);

    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}
#endif /*__MMI_EDITABLE_AUDIO_EQUALIZER__ */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_turn_on
 * DESCRIPTION
 *  This function is to turn on equalizer effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_eq_turn_on(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_eq_turn_on_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_turn_off
 * DESCRIPTION
 *  This function is to turn off equalizer effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_eq_turn_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_eq_turn_off_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}
#endif /* #if defined(__BES_EQ_SUPPORT__) */ 


#if defined(__BES_BASS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bass_enhance_turn_on
 * DESCRIPTION
 *  This function is to turn on bass enhancement effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_bass_enhance_turn_on(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_bass_enhance_turn_on_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bass_enhance_turn_off
 * DESCRIPTION
 *  This function is to turn off bass enhancement effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_bass_enhance_turn_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_bass_enhance_turn_off_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}
#endif /*#if defined(__BES_BASS_SUPPORT__)*/


#if defined(__BES_LOUDNESS_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_loudness_turn_on
 * DESCRIPTION
 *  This function is to turn on loudness sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_loudness_turn_on(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_loudness_turn_on_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_loudness_turn_off
 * DESCRIPTION
 *  This function is to turn off loudness sound effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_loudness_turn_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_loudness_turn_off_effect();
    return mdi_audio_get_event(result);
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}
#endif /*#if defined(__BES_LOUDNESS_SUPPORT__)*/


/*-----------------------------------------------------------------------------
                                   Speech
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_session_start
 * DESCRIPTION
 *  start speech session (for All apps)
 * PARAMETERS
 *  speech_type_id       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_ENUM speech_type_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_SESSION_START, speech_type_id);

    /* Avoid the same session start twice */
    MDI_ASSERT(mdi_audio_speech_cntx.type_id != speech_type_id);

    /* Stop GSM/WCDMA speech because it may still on after disconnect signal */
    if(mdi_speech_codec_on)
    {
        mdi_audio_speech_codec_stop();
    }

    /* Switch to new session */
    mdi_audio_speech_cntx.type_id = speech_type_id;
    mdi_speech_session_on = MMI_TRUE;

#ifdef __GAIN_TABLE_SUPPORT__
    g_is_in_call = KAL_TRUE;
#endif /* __GAIN_TABLE_SUPPORT__ */

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS; // media_aud_speech_session_start(MOD_MMI, app_id);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_session_stop
 * DESCRIPTION
 *  stop speech session (for All apps)
 * PARAMETERS
 *  speech_type_id       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_ENUM speech_type_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_SESSION_STOP, speech_type_id);

    if (mdi_audio_speech_cntx.type_id == speech_type_id)
    {
        /* Stop GSM/WCDMA speech because it may still on after disconnect signal */
        if(mdi_speech_codec_on)
        {
            mdi_audio_speech_codec_stop();
        }
    
        mdi_audio_speech_cntx.type_id = MDI_AUDIO_SPEECH_APP_ID_NONE;
        mdi_speech_session_on = MMI_FALSE;

    #ifdef __GAIN_TABLE_SUPPORT__
        g_is_in_call = KAL_FALSE;
    #endif /* __GAIN_TABLE_SUPPORT__ */

        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        ASSERT(0);
        MDI_AUDIO_UNLOCK;        
        return MDI_AUDIO_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_get_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
MDI_AUDIO_SPEECH_APP_ID_ENUM mdi_audio_speech_get_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_GET_APP_ID, mdi_audio_speech_cntx.type_id);

    return mdi_audio_speech_cntx.type_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_set_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_speech_set_app_id(MDI_AUDIO_SPEECH_APP_ID_ENUM speech_type_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_SET_APP_ID, mdi_audio_speech_cntx.type_id);

    mdi_audio_speech_cntx.type_id = speech_type_id;
}


/* for GSM & WCDMA apps */
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_codec_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_codec_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct evt;
    kal_uint8 rat_mode = 0;
#ifndef __GAIN_TABLE_SUPPORT__
    U8 speech_vol_level = MDI_AUD_VOL_GET_EX_LEVEL(srv_speech_get_mode_volume());
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_CODEC_START, mdi_speech_codec_on);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_GSM ||
                mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_WCDMA ||
                mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_3G324M);

    /* Pre-speech on callback to application */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    evt.session_id = mdi_audio_speech_cntx.type_id;
    evt.status = MDI_AUDIO_SPH_PRE_SPEECH_ON;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    mdi_speech_codec_on = MMI_TRUE;

#ifndef __GAIN_TABLE_SUPPORT__
    /* set volume to force mdi audio helps to sync volume to bt to pass PTS */
    srv_speech_save_mode_volume(MDI_AUD_VOL_MUTE(speech_vol_level));
    mdi_audio_set_mic_volume();
#else
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_SPEECH_STATE_CHANGED, (void*)KAL_TRUE);
#endif /* __GAIN_TABLE_SUPPORT__ */

    switch (mdi_audio_speech_cntx.type_id)
    {
        case MDI_AUDIO_SPEECH_APP_ID_GSM:
            rat_mode = 0;
            break;
        case MDI_AUDIO_SPEECH_APP_ID_WCDMA:
            rat_mode = 1;
            break;
        case MDI_AUDIO_SPEECH_APP_ID_3G324M:
            rat_mode = 2;
            break;
        default:
            ASSERT(0);
    }

    media_aud_speech_set_rat_mode(KAL_TRUE, rat_mode);

    /* Post-speech on callback to application */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    evt.session_id = mdi_audio_speech_cntx.type_id;
    evt.status = MDI_AUDIO_SPH_POST_SPEECH_ON;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_codec_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_codec_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct evt;
    kal_uint8 rat_mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_CODEC_STOP, mdi_speech_codec_on);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_GSM ||
                mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_WCDMA ||
                mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_3G324M);

    /* Stop keytone detection */
#if defined(__KEY_TONE_DETECTION__)
    if (mdi_keytone_detect_on)
    {
        mdi_audio_stop_keytone_detect();
    }
#endif /* __KEY_TONE_DETECTION__ */
    
    /* Pre-speech off callback to application */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    evt.session_id = mdi_audio_speech_cntx.type_id;
    evt.status = MDI_AUDIO_SPH_PRE_SPEECH_OFF;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    mdi_speech_codec_on = MMI_FALSE;

#ifndef __GAIN_TABLE_SUPPORT__
    mdi_audio_set_mic_volume();
#else
    mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_SPEECH_STATE_CHANGED, (void*)KAL_FALSE);
#endif /* __GAIN_TABLE_SUPPORT__ */

    switch (mdi_audio_speech_cntx.type_id)
    {
        case MDI_AUDIO_SPEECH_APP_ID_GSM:
            rat_mode = 0;
            break;
        case MDI_AUDIO_SPEECH_APP_ID_WCDMA:
            rat_mode = 1;
            break;
        case MDI_AUDIO_SPEECH_APP_ID_3G324M:
            rat_mode = 2;
            break;
        default:
            ASSERT(0);
    }

    media_aud_speech_set_rat_mode(KAL_FALSE, rat_mode);

    /* Post-speech off callback to application */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    evt.session_id = mdi_audio_speech_cntx.type_id;
    evt.status = MDI_AUDIO_SPH_POST_SPEECH_OFF;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_encode_start
 * DESCRIPTION
 *  start speech encode process (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_encode_start(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_ENCODE_START, rtp_handle);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    /* Pre-speech encode start callback to application */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    evt.session_id = mdi_audio_speech_cntx.type_id;
    evt.status = MDI_AUDIO_SPH_PRE_VOIP_ENCODE_START;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    if(voip_encoding_start(rtp_handle) == RTP_SUCCESS)
    {
        /* Post-speech encode start callback to application */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
        evt.session_id = mdi_audio_speech_cntx.type_id;
        evt.status = MDI_AUDIO_SPH_POST_VOIP_ENCODE_START;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return MDI_AUDIO_FAIL;
    }
#else
    return MDI_AUDIO_SUCCESS;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_encode_stop
 * DESCRIPTION
 *  stop speech encode process (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_encode_stop(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_ENCODE_STOP, rtp_handle);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    /* Pre-speech encode stop callback to application */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    evt.session_id = mdi_audio_speech_cntx.type_id;
    evt.status = MDI_AUDIO_SPH_PRE_VOIP_ENCODE_STOP;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    if(voip_encoding_stop(rtp_handle) == RTP_SUCCESS)
    {
        /* Post-speech encode stop callback to application */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
        evt.session_id = mdi_audio_speech_cntx.type_id;
        evt.status = MDI_AUDIO_SPH_POST_VOIP_ENCODE_STOP;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return MDI_AUDIO_FAIL;
    }
#else
    return MDI_AUDIO_SUCCESS;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_decode_start
 * DESCRIPTION
 *  start speech decode process (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_decode_start(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_DECODE_START, rtp_handle);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    /* Pre-speech decode start callback to application */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    evt.session_id = mdi_audio_speech_cntx.type_id;
    evt.status = MDI_AUDIO_SPH_PRE_VOIP_DECODE_START;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    if(voip_decoding_start(rtp_handle) == RTP_SUCCESS)
    {
        /* Post-speech decode start callback to application */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
        evt.session_id = mdi_audio_speech_cntx.type_id;
        evt.status = MDI_AUDIO_SPH_POST_VOIP_DECODE_START;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return MDI_AUDIO_FAIL;
    }
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_decode_stop
 * DESCRIPTION
 *  stop speech decode process (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_decode_stop(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_mdi_audio_speech_ind_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_DECODE_STOP, rtp_handle);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    /* Pre-speech decode stop callback to application */
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
    evt.session_id = mdi_audio_speech_cntx.type_id;
    evt.status = MDI_AUDIO_SPH_PRE_VOIP_DECODE_STOP;
    MMI_FRM_CB_EMIT_EVENT(&evt);

    if(voip_decoding_stop(rtp_handle) == RTP_SUCCESS)
    {
        /* Post-speech decode stop callback to application */
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND);
        evt.session_id = mdi_audio_speech_cntx.type_id;
        evt.status = MDI_AUDIO_SPH_POST_VOIP_DECODE_STOP;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return MDI_AUDIO_FAIL;
    }
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_mixer_add
 * DESCRIPTION
 *  add speech mixer (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_mixer_add(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_MIXER_ADD, rtp_handle);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    if(voip_mixer_add(rtp_handle) == RTP_SUCCESS)
    {
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return MDI_AUDIO_FAIL;
    }
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_mixer_remove
 * DESCRIPTION
 *  remove speech mixer (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_mixer_remove(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_MIXER_REMOVE, rtp_handle);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    if(voip_mixer_remove(rtp_handle) == RTP_SUCCESS)
    {
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return MDI_AUDIO_FAIL;
    }
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_dtmf_start
 * DESCRIPTION
 *  start speech DTMF tone (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 *  code             [IN]
 *  type             [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_dtmf_start(kal_int8 rtp_handle, kal_uint8 code, kal_uint8 type)
{
#if defined(__MED_RTP_MOD__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_DTMF_START, rtp_handle,code,type);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    if(rtp_send_dtmf_start(rtp_handle, code, type) == RTP_SUCCESS)
    {
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return MDI_AUDIO_FAIL;
    }
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_dtmf_stop
 * DESCRIPTION
 *  stop speech DTMF tone (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_dtmf_stop(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__) && defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_DTMF_STOP, rtp_handle);

    MDI_ASSERT( mdi_audio_speech_cntx.type_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );
    if(rtp_send_dtmf_stop(rtp_handle) == RTP_SUCCESS)
    {
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return MDI_AUDIO_FAIL;
    }
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*-----------------------------------------------------------------------------
                              Auto Answer Machine
 ----------------------------------------------------------------------------*/
#if defined(__KEY_TONE_DETECTION__)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_keytone_detect_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_keytone_detect_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_kt_detect_ind_struct *msg_p = (media_aud_kt_detect_ind_struct*) msg;
    
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_KEYTONE_DETECT_IND, mdi_keytone_detect_on, msg_p->key);

    if(mdi_keytone_detect_on)
    {
        mdi_keytone_detect_callback(msg_p->key);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_keytone_detect
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_start_keytone_detect(void (*callback)(S16 key_ascii) )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_KEYTONE_DETECT);

    /* Need to turn on in speech mode and can not use while recording */
    if(!mdi_audio_is_speech_mode() || (mdi_audio_state == MDI_AUDIO_RECORD)|| (mdi_audio_state == MDI_AUDIO_RECORD_PAUSED))
    {
        return MDI_AUDIO_FAIL;
    }

    if(media_aud_start_keytone_detect_req(MOD_MMI) == MDI_AUDIO_SUCCESS)
    {
        mdi_keytone_detect_on = MMI_TRUE;
        mdi_keytone_detect_callback = callback;
        SetProtocolEventHandler(mdi_audio_keytone_detect_ind, MSG_ID_MEDIA_AUD_KT_DETECT_IND);
        return MDI_AUDIO_SUCCESS;    
    }
    else
    {
        mdi_keytone_detect_on = MMI_FALSE;
        mdi_keytone_detect_callback = NULL;
        SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_KT_DETECT_IND);
        return MDI_AUDIO_FAIL;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_keytone_detect
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_stop_keytone_detect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_KEYTONE_DETECT);
    
    if (mdi_keytone_detect_on)
    {
        media_aud_stop_keytone_detect_req(MOD_MMI);
        mdi_keytone_detect_on = MMI_FALSE;
        mdi_keytone_detect_callback = NULL;
        SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_KT_DETECT_IND);
    }
}
#endif /*__KEY_TONE_DETECTION__*/

#ifdef __VOICE_CHANGER_SUPPORT__
kal_bool mdi_audio_set_voice_changer_mode(SPH_VOICE_CHANGER_MODE mode)
{
  kal_bool result = KAL_FALSE;
	result = media_aud_set_voice_changer_mode(mode);
	
	return result;
}
SPH_VOICE_CHANGER_MODE mdi_audio_get_voice_changer_mode(void)
{
    return L1SP_GetVoiceChangerMode();
}
#endif

#ifdef __LINE_IN_SUPPORT__
void mdi_audio_enable_bt_box_linein(kal_bool on)
{
  media_send_enable_bt_box_linein_req(on);
}

void mdi_audio_force_use_linein_mic(kal_bool force_use)
{
  media_send_force_use_linein_mic_req(force_use);
}
#endif

#ifdef __KARAOKE_SUPPORT__
static Media_Kara_opt_mode g_karaoke_mode = MEDIA_KARAPLAY_MIX_NONE;
Media_Kara_opt_mode mdi_audio_get_karaoke_mode()
{
    return g_karaoke_mode;
}

void mdi_audio_set_karaoke_mode(Media_Kara_opt_mode mode, void *file_name)
{
  if(mode == g_karaoke_mode)
  	  return;
  media_aud_set_karaoke_mode_req(mode,file_name);
  g_karaoke_mode = mode;
}

void mdi_audio_set_karaoke_channel(Media_KaraRec_Mix_CH channel)
{
  media_aud_set_karaoke_channel_req(channel);
}

void mdi_audio_set_karaoke_digitgain(kal_uint16 unum,kal_uint16 uden)
{
  media_aud_set_karaoke_digitgain_req(unum,uden);
}

#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
kal_int32 mdi_audio_karaoke_remix_turn_on(kal_wchar* filename, kal_uint32 msRecordStartTime, kal_uint32 msAudioSeekTime)
{
  return mdi_audio_get_event(media_aud_karaoke_remix_turn_on_req(filename,msRecordStartTime,msAudioSeekTime));
}

void mdi_audio_karaoke_remix_turn_off(void)
{
  media_aud_karaoke_remix_turn_off_req();
}

void mdi_audio_karaoke_set_remix_mode(Media_KaraRec_Mix_CH ch_mode)
{
  media_aud_karaoke_set_remix_mode_req(ch_mode);
}

void mdi_audio_karaoke_set_remix_audio_gain(kal_uint16 audio_gain)
{
  media_aud_karaoke_set_remix_audio_gain_req(audio_gain);
}

void mdi_audio_karaoke_set_remix_voice_gain(kal_uint16 voice_gain)
{
  media_aud_karaoke_set_remix_voice_gain_req(voice_gain);
}
#endif

#endif


/*-----------------------------------------------------------------------------
                                 Path Control
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_headset_mode_output_path
 * DESCRIPTION
 *  This function is to set headset mode output path.
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_headset_mode_output_path(unsigned char device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __AUDIO_ULTRA_SLIM__
		mdi_audio_mma_slim_player.mma_para.output_path = device;
	#endif
    media_aud_set_headset_mode_output_path(MOD_MMI, device);
}


/*-----------------------------------------------------------------------------
                                Volume Control
 ----------------------------------------------------------------------------*/
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_volume_per_play_style
 * DESCRIPTION
 *  This function is used to get the media volume per play style.
 * PARAMETERS
 *  type            [IN]        Volume type
 *  volume          [IN]        MDI volume
 *  play_style      [IN]        Play style
 * RETURNS
 *  Media volume.
 *****************************************************************************/
static kal_uint64 mdi_audio_get_volume_per_play_style(kal_uint8 type, kal_uint8 volume, kal_uint8 play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint64 volume_data = volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GAIN_TABLE_SUPPORT__

    /* Update audio type */
    if (MDI_AUD_VOL_IS_EX_LEVEL(volume)) /* n-level volume */
    {
        /* Update audio type as player */
        g_audio_type = MDI_AUDIO_TYPE_PLAYER;
    }
    else
    {
        /* Client doesn't specify audio type */
        if (! g_is_audio_type_specified)
        {
            g_audio_type = MDI_AUDIO_TYPE_UNKNOWN;
        }
    }

    /* The flag should be reset once a play request is triggered */
    g_is_audio_type_specified = KAL_FALSE;
    
#endif /* __GAIN_TABLE_SUPPORT__ */

    /* Get volume data */
    if (type == AUD_VOLUME_MEDIA) /* Media volume type */
    {
        /* Stop previous crescendo timer */
        mdi_audio_stop_crescendo_timer();
        
        /* Apply crescendo effect */
        if ((play_style == DEVICE_AUDIO_PLAY_CRESCENDO)  /* Increasing tone */
            && (!MDI_AUD_VOL_IS_EX_LEVEL(volume)))       /* Support crescendo for 7-level only */
        {
            /* Determine the upper bound of the crescendo volume */
            g_crescendo_bound = MDI_AUD_VOL_GET_EX_LEVEL(volume);

            if (MDI_AUD_VOL_IS_MUTE_LEVEL(volume)) /* Treat level 0 as mute */
            {
                if (g_crescendo_bound > 0)
                {
                    /* Decrease crescendo boundary because the level 0 is treated as mute */
                    g_crescendo_bound --;
                }
                else
                {
                    /* Directly return if mute at level 0 */
                #ifdef __GAIN_TABLE_SUPPORT__
                    return gain_table_get_volume(type, volume);
                #else
                    return volume_data;
                #endif /* __GAIN_TABLE_SUPPORT__ */
                }
            }

            if (g_crescendo_bound > CRESCENDO_VOLUME_MAX)
            {
                g_crescendo_bound = CRESCENDO_VOLUME_MAX;
            }

            /* Use mininum volume when just starting the play */
        #ifdef __GAIN_TABLE_SUPPORT__
            volume_data = gain_table_get_volume(AUD_VOLUME_MEDIA, CRESCENDO_VOLUME_MIN);
        #else
            volume_data = CRESCENDO_VOLUME_MIN;
        #endif /* __GAIN_TABLE_SUPPORT__ */

            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CRESCENDO_START, g_crescendo_volume, g_crescendo_bound);
            
            /* Start crescendo timer to update volume */
            StartTimer(MDI_AUDIO_CRESCENDO_TIMER, CRESCENDO_TIMER_TIMEOUT, mdi_audio_crescendo_timeout_hdlr);
        }
        else
        {
        #ifdef __GAIN_TABLE_SUPPORT__
            volume_data = gain_table_get_volume(AUD_VOLUME_MEDIA, volume);
        #endif /* __GAIN_TABLE_SUPPORT__ */
        } 
    }
    else /* Volume types other than Media */
    {
    #ifdef __GAIN_TABLE_SUPPORT__
        volume_data = gain_table_get_volume(type, volume);
    #endif /* __GAIN_TABLE_SUPPORT__ */
    }

#ifdef __GAIN_TABLE_SUPPORT__
    /* Update playback audio type. Note that the effect/alert/unknown tone is usually a short tone that
     * could possibly interrupt current audio playback at any time. To apply correct audio type after 
     * the interruption of effect tone, we should do the followings:
     *   1. Store playback audio type if it's not effect tone.
     *   2. Restore playback audio type after the effect tone is played.
     */
    switch (g_audio_type)
    {
        case MDI_AUDIO_TYPE_UNKNOWN:
        case MDI_AUDIO_TYPE_EFFECT:
        case MDI_AUDIO_TYPE_ALERT:
            /* Restore playback type for effect tones */
            g_audio_type = g_playback_type;
            break;
        default:
            /* Store playback audio type */
            g_playback_type = g_audio_type;
            break;
    }
#endif /* __GAIN_TABLE_SUPPORT__ */
    
    return volume_data;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_volume_per_id
 * DESCRIPTION
 *  This function is used to get the volume for a given ID.
 * PARAMETERS
 *  audio_id        [IN]        Audio id
 *  volume          [IN]        MDI volume
 *  play_style      [IN]        Play style
 * RETURNS
 *  Media volume.
 *****************************************************************************/
static kal_uint64 mdi_audio_get_volume_per_id(kal_uint8 audio_id, kal_uint8 volume, kal_uint8 play_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Determine volume type per ID */
    if (audio_id <= TONE_KEY_CLICK)
    {
        type = AUD_VOLUME_KEY;
    }
    else if ((audio_id > TONE_KEY_CLICK) && (audio_id <= MAX_TONE_ID))
    {
        type = AUD_VOLUME_CTN;
    }
    else
    {
        type = AUD_VOLUME_MEDIA;
    }

#ifdef __GAIN_TABLE_SUPPORT__
    g_crnt_volume[type] = volume;
#endif

    return mdi_audio_get_volume_per_play_style(type, volume, play_style);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_crescendo_timer
 * DESCRIPTION
 *  This function is used to stop crescendo timer because of interruptions.
 * PARAMETERS
 *  none
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_stop_crescendo_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CRESCENDO_STOP);
    
    StopTimer(MDI_AUDIO_CRESCENDO_TIMER);

    /* Reset crescendo variables */
    g_crescendo_volume = CRESCENDO_VOLUME_MIN;
    g_crescendo_bound  = CRESCENDO_VOLUME_MIN;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_crescendo_timeout_hdlr
 * DESCRIPTION
 *  This function is used to handler timeout of crescendo timer.
 * PARAMETERS
 *  none
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_crescendo_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CRESCENDO_TIMEOUT, g_crescendo_volume, g_crescendo_bound);
    
    if (g_crescendo_volume < g_crescendo_bound)
    {
        /* Increase crescendo volume */
        g_crescendo_volume ++;

        /* Update media volume */
        mdi_audio_set_volume(AUD_VOLUME_MEDIA, g_crescendo_volume);

        /* Start crescendo timer to update volume */
        StartTimer(MDI_AUDIO_CRESCENDO_TIMER, CRESCENDO_TIMER_TIMEOUT, mdi_audio_crescendo_timeout_hdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume
 * DESCRIPTION
 *  This function is to set the volume with the given type and volume.
 * PARAMETERS
 *  type        [IN]        
 *  volume      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_volume(U8 type, U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SET_VOLUME, type, volume);
    
    /* Set volume to BT earphone */
#ifdef __BT_SPK_VOL_CONTROL__

    /* If in call, only apply speech volume to BT */
    if(mdi_audio_is_in_call() && (MDI_VOLUME_SPH == type))
    {
        mdi_audio_set_volume_to_bt(volume);
    }

    /* If not in call, only apply audio and FM volume to BT */
    if(!mdi_audio_is_in_call() && 
       ((MDI_VOLUME_MEDIA == type) || (MDI_VOLUME_FMR == type) || (MDI_VOLUME_ATV == type)))
    {
        mdi_audio_set_volume_to_bt(volume);
    }
#endif /*__BT_SPK_VOL_CONTROL__*/
    
#ifdef __GAIN_TABLE_SUPPORT__
    /* Update current volume */
    g_crnt_volume[type] = volume;

    /* Update tone volume */
    if (type == AUD_VOLUME_SPH)
    {
        mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_SPEECH_VOLUME_CHANGED, (void*)volume);
    }
    else if (type == AUD_VOLUME_KEY)
    {
        mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_KEYPAD_VOLUME_CHANGED, (void*)volume);
    }
    
    media_aud_set_volume_ext(type, gain_table_get_volume(type, volume), MMI_TRUE, MMI_TRUE);
#else
    media_aud_set_volume_ext(type, volume, MMI_TRUE, MMI_TRUE);
#endif /* __GAIN_TABLE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_incr_volume
 * DESCRIPTION
 *  This function is used to increase the volume.
 * PARAMETERS
 *  volume      [IN] : Volume
 * RETURNS
 *  volume after increasing
 *****************************************************************************/
U8 mdi_audio_incr_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 volume_level;
    U8 volume_bound;
    U8 volume_incr;
    MMI_BOOL is_mute_at_level_0;
    MMI_BOOL is_ext_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    volume_level = MDI_AUD_VOL_GET_EX_LEVEL(volume);
    is_mute_at_level_0 = (MMI_BOOL)MDI_AUD_VOL_IS_MUTE_LEVEL(volume);
    is_ext_level = (MMI_BOOL)MDI_AUD_VOL_IS_EX_LEVEL(volume);

    /* Determine volume boundary */
    if (is_ext_level) /* n-level */
    {
        volume_bound = (is_mute_at_level_0) ? MDI_AUD_VOL_EX_MUTE_MAX : (MDI_AUD_VOL_EX_MUTE_MAX - 1);
    }
    else /* 7-level */
    {
        volume_bound = (is_mute_at_level_0) ? MDI_MAX_VOLUME_LEVEL : (MDI_MAX_VOLUME_LEVEL - 1);
    }

    /* Increase volume if not reach boundary yet */
    if (volume_level < volume_bound)
    {
        volume_incr = volume_level + 1;
    }
	else
	{
        volume_incr = volume_bound;
	}

    /* Update volume setting */
    if (is_mute_at_level_0)
    {
        volume_incr = MDI_AUD_VOL_MUTE(volume_incr);
    }

    if (is_ext_level)
    {
        volume_incr = MDI_AUD_VOL_EX_MUTE(volume_incr);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_INCR_VOLUME, volume, volume_incr);
    
    return volume_incr;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_decr_volume
 * DESCRIPTION
 *  This function is used to decrease the volume.
 * PARAMETERS
 *  volume      [IN] : Volume
 * RETURNS
 *  volume after decreasing
 *****************************************************************************/
U8 mdi_audio_decr_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 volume_level;
    U8 volume_decr;
    MMI_BOOL is_mute_at_level_0;
    MMI_BOOL is_ext_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    volume_level = MDI_AUD_VOL_GET_EX_LEVEL(volume);
    is_mute_at_level_0 = (MMI_BOOL)MDI_AUD_VOL_IS_MUTE_LEVEL(volume);
    is_ext_level = (MMI_BOOL)MDI_AUD_VOL_IS_EX_LEVEL(volume);

    /* Decrease volume if not reach 0 yet */
    if (volume_level > 0)
    {
        volume_decr = volume_level - 1;
    }
	else
	{
        volume_decr = 0;
	}

    /* Update volume setting */
    if (is_mute_at_level_0)
    {
        volume_decr = MDI_AUD_VOL_MUTE(volume_decr);
    }

    if (is_ext_level)
    {
        volume_decr = MDI_AUD_VOL_EX_MUTE(volume_decr);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DECR_VOLUME, volume, volume_decr);

    return volume_decr;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_mic_volume
 * DESCRIPTION
 *  This function is to set microphone volume level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_mic_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 volume_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    
    if (mdi_speech_codec_on)
    {
        volume_level = MDI_AUD_MIC_IDX_CALL;
    }
    else
    {
        volume_level = MDI_AUD_MIC_IDX_IDLE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, volume_level, -1, -1, __LINE__);

    mdi_audio_set_volume(MDI_VOLUME_MIC, volume_level);
    
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_dual_mic_nr
 * DESCRIPTION
 *  This function is to enable/disalbe NR for dual microphone.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_dual_mic_nr(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    
#ifdef __DUAL_MIC_SUPPORT__
    media_aud_mic_set_dual_nr(is_enable);
#endif /* __DUAL_MIC_SUPPORT__ */

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_mute
 * DESCRIPTION
 *  This function is to set mute on the given volume type.
 * PARAMETERS
 *  vol_type        [IN]        
 *  mute            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_mute(U8 vol_type, MMI_BOOL mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __BT_SPK_VOL_CONTROL__
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, vol_type, mute, -1, __LINE__);
    
    /* If in call, only apply speech volume to BT(mute is controlled by MED) */
    if(mdi_audio_is_in_call() && (vol_type != MDI_VOLUME_SPH))
    {
        return;
    }
#endif /*__BT_SPK_VOL_CONTROL__*/

    media_aud_set_mute(vol_type, mute);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_hw_mute
 * DESCRIPTION
 *  This function is to turn on/off hardware mute function in driver
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_set_hw_mute(MMI_BOOL set_mute)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(set_mute)
    {
        Media_EnableHardwareMuteSleep(KAL_TRUE);
    }
    else
    {
        Media_EnableHardwareMuteSleep(KAL_FALSE);
    }
#endif /* __MTK_TARGET__ */ 
}


/*-----------------------------------------------------------------------------
                                Gain Table
 ----------------------------------------------------------------------------*/
#ifdef __GAIN_TABLE_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mdi_audio_state_change_ind_hdlr
* DESCRIPTION
*  This functio is used to handle the state change indicator from the MED, 
*  including BT state is changed. The MDI will need to update gain setting if
*  requried.
* PARAMETERS
*  msg      [IN]        Message.
* RETURNS           
*  void
*****************************************************************************/
static void mdi_audio_state_change_ind_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_state_change_ind_struct *msg_p = (l4aud_audio_state_change_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STATE_CHANGE_IND, msg_p->reason, msg_p->data_p);

    switch (msg_p->reason)
    {
        case AUD_STATE_CHANGE_SCO_CONNECT:
            mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_SCO_CONNECT, NULL);
            break;
        case AUD_STATE_CHANGE_SCO_DISCONNECT:
            mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_SCO_DISCONNECT, NULL);
            break;
        case AUD_STATE_CHANGE_A2DP_CONNECT:
            mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_A2DP_CONNECT, NULL);
            break;
        case AUD_STATE_CHANGE_A2DP_DISCONNECT:
            mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_A2DP_DISCONNECT, NULL);
            break;
        case AUD_STATE_CHANGE_ATV_ON:
            mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_ATV_ON, NULL);
            break;
        case AUD_STATE_CHANGE_ATV_OFF:
            mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_ATV_OFF, NULL);
            break;
        case AUD_STATE_CHANGE_MMA_PLAYBACK_START:
            mdi_audio_update_volume(MDI_AUDIO_VOLUME_UPDATE_REASON_MMA_PLAYBACK, (void*)msg_p->data_p);
            break;
        case AUD_STATE_CHANGE_TV_OUT_PLUG_IN:
        case AUD_STATE_CHANGE_TV_OUT_PLUG_OUT:
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_output_path_by_id
 * DESCRIPTION
 *  This function is used to get the audio output path for a given audio ID.
 * PARAMETERS
 *  audio_id      [IN]      Audio ID.
 *  path          [IN]      Path parameter given by the MMI.
 * RETURNS
 *  Audio output path
 *****************************************************************************/
static kal_uint8 mdi_audio_get_output_path_by_id(kal_uint8 audio_id, kal_uint8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 output_path = path;
    kal_uint8 audio_mode = mdi_audio_get_audio_mode();
    kal_bool is_speech_on = mdi_audio_is_in_call();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If MMI specifies output path, we should just apply the path given by MMI. 
     * Note that the MDI_DEVICE_SPEAKER2 may have some confusion. Anyway, it means
     * the MMI doens't care about the output path. In this case, we should config
     * the path per id and audio mode. Note that we should overwrite the path setting
     * of the DTMF tones (<= MAX_TONE_ID).
     */
    if ((path != MDI_DEVICE_SPEAKER2) && (audio_id > MAX_TONE_ID))
    {
        return path;
    }
    
    /* if there is no change, it will use the default value at PS */
    /* specially for connect tone */
    if ((audio_id == TONE_CALL_CONNECT) || (audio_id == TONE_WARNING2) || (audio_id == TONE_ERROR2))
    {
        switch (audio_mode)
        {
            case AUD_MODE_NORMAL:
                output_path = AUDIO_DEVICE_SPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                output_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                output_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                output_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
        }
    }
    else if (audio_id <= TONE_NEGATIVE_ACK)
    {
        switch (audio_mode)
        {
            case AUD_MODE_NORMAL:
                output_path = AUDIO_DEVICE_SPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                output_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                output_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                output_path = AUDIO_DEVICE_SPEAKER;
                break;
        }
    }
    else if ((audio_id > TONE_NEGATIVE_ACK) && (audio_id <= MAX_TONE_ID))
    {
        switch (audio_mode)
        {
            case AUD_MODE_NORMAL:
                /* if speech on, tone shall output via speaker1 */
                if (is_speech_on)
                {
                    output_path = AUDIO_DEVICE_SPEAKER;
                }
                else
                {
                    output_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                break;
            case AUD_MODE_LOUDSPK:
                output_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                output_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                /* if speech on, tone shall output via speaker1 */
                if (is_speech_on)
                {
                    output_path = AUDIO_DEVICE_SPEAKER;
                }
                else
                {
                    output_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                break;
        }
    }
    else /* For other cases, it should be string playback */
    {
        switch (audio_mode)
        {
            case AUD_MODE_NORMAL:
                output_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                output_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                output_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                output_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
        }
    }

    return output_path;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_update_speech_param
 * DESCRIPTION
 *  This function is used to update speech mode/parameters.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_update_speech_param(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 speech_mode;
    kal_int16 fir_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Update speech mode */
#ifdef __BT_HFG_PROFILE__
    if (g_is_sco_on) /* SCO on */
    {
    #ifdef __BT_FM_VIA_SCO__
        if (g_is_fm_on)
        {
            speech_mode = SPH_MODE_LINEIN_VIA_BT_CORDLESS;
        }
        else
    #endif /* __BT_FM_VIA_SCO__ */
        {
            speech_mode = SPH_MODE_BT_EARPHONE;
        }
    }
    else
#endif /* __BT_HFG_PROFILE__ */
    {
        switch (g_audio_mode)
        {
            case AUD_MODE_NORMAL:
                speech_mode = SPH_MODE_NORMAL;
                break;
            case AUD_MODE_HEADSET:
                speech_mode = SPH_MODE_EARPHONE;
                break;
            case AUD_MODE_LOUDSPK:
                speech_mode = SPH_MODE_LOUDSPK;
                break;
            default:
                speech_mode = SPH_MODE_NORMAL;
                break;
        }
    }

    media_aud_speech_set_enhance_mode(speech_mode);

    /* Update speech FIR */
#ifdef __BT_HFG_PROFILE__
    if (g_is_sco_on)
    {
        fir_idx = 3;
    }
    else
#endif /* __BT_HFG_PROFILE__ */
    {
        switch (g_audio_mode)
        {
            case AUD_MODE_NORMAL:
                fir_idx = 0;
                break;
            case AUD_MODE_HEADSET:
                fir_idx = 1;
                break;
            case AUD_MODE_LOUDSPK:
                fir_idx = 2;
                break;
            default:
                fir_idx = 0;
                break;
        }
    }

    media_aud_speech_set_fir_coeff(fir_idx, fir_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_media_source_by_type
 * DESCRIPTION
 *  This function is used to get the type of media format for a given media type.
 * PARAMETERS
 *  type      [IN]    Media type
 * RETURNS
 *  Media format
 *****************************************************************************/
static kal_uint8 mdi_audio_get_media_source_by_type(kal_int16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 source = MDI_AUDIO_MEDIA_SOURCE_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MED_TYPE_SMF:
        case MED_TYPE_IMELODY:
            source = MDI_AUDIO_MEDIA_SOURCE_MIDI;
            break;
        case MED_TYPE_AMR:
        case MED_TYPE_WAV:
        case MED_TYPE_3GP:
            source = MDI_AUDIO_MEDIA_SOURCE_AMR;
            break;
        case MED_TYPE_DAF:
        default:
            source = MDI_AUDIO_MEDIA_SOURCE_MP3;
            break;
    }
        
    return source;    
}


/*****************************************************************************
* FUNCTION
*  mdi_audio_update_volume
* DESCRIPTION
*  This functio is used to update necessary volume settings when the state of
*  a given condition is changed.
* PARAMETERS
*  reason       [IN]            Update reason.
*  param_p      [IN]            Paramters.
* RETURNS           
*  MDI_AUDIO_SUCCESS            Successful.
*  Other values                 Failed.
*****************************************************************************/
void mdi_audio_update_volume(mdi_audio_volume_update_reason_enum reason, void* param_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 type;
    kal_int16 media_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_UPDATE_VOLUME, reason, (kal_uint32)param_p);

    MDI_AUDIO_LOCK;
    
    switch (reason)
    {
        case MDI_AUDIO_VOLUME_UPDATE_REASON_AUDIO_MODE_CHANGED:
        {
            /* Update all the volume types */
            media_aud_update_volume(AUD_VOLUME_CTN, gain_table_get_volume(AUD_VOLUME_CTN, g_crnt_volume[AUD_VOLUME_CTN]));
            media_aud_update_volume(AUD_VOLUME_KEY, gain_table_get_volume(AUD_VOLUME_KEY, g_crnt_volume[AUD_VOLUME_KEY]));
            media_aud_update_volume(AUD_VOLUME_MIC, gain_table_get_volume(AUD_VOLUME_MIC, g_crnt_volume[AUD_VOLUME_MIC]));
            media_aud_update_volume(AUD_VOLUME_SPH, gain_table_get_volume(AUD_VOLUME_SPH, g_crnt_volume[AUD_VOLUME_SPH]));
            media_aud_update_volume(AUD_VOLUME_SID, gain_table_get_volume(AUD_VOLUME_SID, g_crnt_volume[AUD_VOLUME_SID]));

        #ifdef TV_OUT_SUPPORT
            media_aud_update_volume(AUD_VOLUME_TVO, gain_table_get_volume(AUD_VOLUME_TVO, g_crnt_volume[AUD_VOLUME_TVO]));
        #endif /* TV_OUT_SUPPORT */
        
            if (g_is_fm_on)
            {
                media_aud_update_volume(AUD_VOLUME_FMR, gain_table_get_volume(AUD_VOLUME_FMR, g_crnt_volume[AUD_VOLUME_FMR]));
            }
        #ifdef __ATV_SUPPORT__
            else if (g_is_atv_on)
            {
                media_aud_update_volume(AUD_VOLUME_ATV, gain_table_get_volume(AUD_VOLUME_ATV, g_crnt_volume[AUD_VOLUME_ATV]));
            }
        #endif /* __ATV_SUPPORT__ */
            else
            {
                media_aud_update_volume(AUD_VOLUME_MEDIA, gain_table_get_volume(AUD_VOLUME_MEDIA, g_crnt_volume[AUD_VOLUME_MEDIA]));
            }
            
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_SPEECH_STATE_CHANGED:
        {
            /* Update microphone/speech */
            media_aud_update_volume(AUD_VOLUME_MIC, gain_table_get_volume(AUD_VOLUME_MIC, g_crnt_volume[AUD_VOLUME_MIC]));
            media_aud_update_volume(AUD_VOLUME_SPH, gain_table_get_volume(AUD_VOLUME_SPH, g_crnt_volume[AUD_VOLUME_SPH]));
            
            /* Update speech parameters */
            mdi_audio_update_speech_param();
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_SPEECH_VOLUME_CHANGED:
        {
            /* Update tone volume if speech is on */
            if (mdi_audio_is_speech_mode())
            {
                media_aud_update_volume(AUD_VOLUME_CTN, gain_table_get_volume(AUD_VOLUME_CTN, (kal_uint8)(kal_uint32)param_p));
            }
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_KEYPAD_VOLUME_CHANGED:
        {
            /* Update tone volume if speech is off */
            if (! mdi_audio_is_speech_mode())
            {
                media_aud_update_volume(AUD_VOLUME_CTN, gain_table_get_volume(AUD_VOLUME_CTN, (kal_uint8)(kal_uint32)param_p));
            }
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_SCO_CONNECT:
        {
            g_is_sco_on = KAL_TRUE;
            
            /* Update speech parameters */
            mdi_audio_update_speech_param();
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_SCO_DISCONNECT:
        {
            g_is_sco_on = KAL_FALSE;
            
            /* Update volume of microphone/speech */
            media_aud_update_volume(AUD_VOLUME_MIC, gain_table_get_volume(AUD_VOLUME_MIC, g_crnt_volume[AUD_VOLUME_MIC]));
            media_aud_update_volume(AUD_VOLUME_SPH, gain_table_get_volume(AUD_VOLUME_SPH, g_crnt_volume[AUD_VOLUME_SPH]));

            /* Update volume */
            if (g_is_fm_on)
            {
               media_aud_update_volume(AUD_VOLUME_FMR, gain_table_get_volume(AUD_VOLUME_FMR, g_crnt_volume[AUD_VOLUME_FMR]));
            }
        #ifdef __ATV_SUPPORT__
            else if (g_is_atv_on)
            {
                media_aud_update_volume(AUD_VOLUME_ATV, gain_table_get_volume(AUD_VOLUME_ATV, g_crnt_volume[AUD_VOLUME_ATV]));
            }
        #endif /* __ATV_SUPPORT__ */
            else
            {
                media_aud_update_volume(AUD_VOLUME_MEDIA, gain_table_get_volume(AUD_VOLUME_MEDIA, g_crnt_volume[AUD_VOLUME_MEDIA]));
            }

            /* Update speech parameters */
            mdi_audio_update_speech_param();
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_A2DP_CONNECT:
        {
            g_is_a2dp_on = KAL_TRUE;
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_A2DP_DISCONNECT:
        {
            g_is_a2dp_on = KAL_FALSE;
            
            /* Update volume */
            if (g_is_fm_on)
            {
               media_aud_update_volume(AUD_VOLUME_FMR, gain_table_get_volume(AUD_VOLUME_FMR, g_crnt_volume[AUD_VOLUME_FMR]));
            }
        #ifdef __ATV_SUPPORT__
            else if (g_is_atv_on)
            {
                media_aud_update_volume(AUD_VOLUME_ATV, gain_table_get_volume(AUD_VOLUME_ATV, g_crnt_volume[AUD_VOLUME_ATV]));
            }
        #endif /* __ATV_SUPPORT__ */
            else
            {
                media_aud_update_volume(AUD_VOLUME_MEDIA, gain_table_get_volume(AUD_VOLUME_MEDIA, g_crnt_volume[AUD_VOLUME_MEDIA]));
            }
            
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_ATV_ON:
        {
            g_is_atv_on = KAL_TRUE;
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_ATV_OFF:
        {
            g_is_atv_on = KAL_FALSE;
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_CAMCORDER_STATE_CHANGED:
        {
            g_is_camcorder_on = (kal_bool)(kal_uint32)param_p;
            
            /* Update volume of microphone */
            media_aud_update_volume(AUD_VOLUME_MIC, gain_table_get_volume(AUD_VOLUME_MIC, g_crnt_volume[AUD_VOLUME_MIC]));
            
            /* Update speech parameters */
            mdi_audio_update_speech_param();
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_FM_STATE_CHANGED:
        {
            g_is_fm_on = (kal_bool)(kal_uint32)param_p;

            /* Update volume of microphone/FMR */
            media_aud_update_volume(AUD_VOLUME_MIC, gain_table_get_volume(AUD_VOLUME_MIC, g_crnt_volume[AUD_VOLUME_MIC]));
            media_aud_update_volume(AUD_VOLUME_FMR, gain_table_get_volume(AUD_VOLUME_FMR, g_crnt_volume[AUD_VOLUME_FMR]));
    
            /* Update speech parameters */
            mdi_audio_update_speech_param();
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_RECORD_STATE_CHANGED:
        {
            g_is_voice_record_on = (kal_bool)(kal_uint32)param_p;

            if (! g_is_in_call)
            {
                /* Update volume of microphone */
                media_aud_update_volume(AUD_VOLUME_MIC, gain_table_get_volume(AUD_VOLUME_MIC, g_crnt_volume[AUD_VOLUME_MIC]));
                
                /* Update speech parameters */
                mdi_audio_update_speech_param();
            }
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_VIDEO_PLAYBACK:
        {
            g_media_source = mdi_audio_get_media_source_by_type((kal_uint8)(kal_uint32)param_p);
            g_audio_type = MDI_AUDIO_TYPE_PLAYER;
            g_playback_type = g_audio_type;

            /* Update volume of media */
            media_aud_update_volume(AUD_VOLUME_MEDIA, gain_table_get_volume(AUD_VOLUME_MEDIA, g_crnt_volume[AUD_VOLUME_MEDIA]));
            break;
        }
        case MDI_AUDIO_VOLUME_UPDATE_REASON_MMA_PLAYBACK:
        {
            /* Convert mma type to media type */
            media_type = med_get_media_type_from_mma_type((kal_uint8)(kal_uint32)param_p);
            g_media_source = mdi_audio_get_media_source_by_type(media_type);

            /* Update audio type */
            if (MDI_AUD_VOL_IS_EX_LEVEL(g_crnt_volume[AUD_VOLUME_MEDIA])) /* n-level volume */
            {
                /* Update audio type as player */
                g_audio_type = MDI_AUDIO_TYPE_PLAYER;
            }
            else
            {
                g_audio_type = MDI_AUDIO_TYPE_UNKNOWN;
            }
            g_playback_type = g_audio_type;
        
            /* Update volume of media */
            media_aud_update_volume(AUD_VOLUME_MEDIA, gain_table_get_volume(AUD_VOLUME_MEDIA, g_crnt_volume[AUD_VOLUME_MEDIA]));
            break;
        }
        default:
            break;
    }

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_info
 * DESCRIPTION
 *  This function is to used to get information in the MDI module. Note that
 *  This function may be invoked by using MED's thread context. We should not
 *  invoke MMI relative functions (include MDI) in this function.
 * PARAMETERS
 *  get_type        : [IN]      Specify the type to be got.
 *  data_p          : [OUT]     The data of the information.
 *  data_len        : [IN/OUT]  The length of the data buffer when input.
 *                              The length of the data that has been retrieved when output.
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_info(mdi_audio_get_info_enum get_type,
			                  void* data_p,
       	                      kal_uint16* data_len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = MDI_AUDIO_PARAM_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (get_type)
    {
        case MDI_AUDIO_GET_INFO_AUDIO_MODE:      /* Audio mode (kal_uint8*) */
            if (*data_len_p >= sizeof(kal_uint8))
            {
                *((kal_uint8*)data_p) = g_audio_mode;
                *data_len_p = sizeof(kal_uint8);

                result = MDI_AUDIO_SUCCESS;
            }
            break;
            
        case MDI_AUDIO_GET_INFO_AUDIO_PATH:      /* Output path (kal_uint8*) */
            if (*data_len_p >= sizeof(kal_uint8))
            {
                *((kal_uint8*)data_p) = g_audio_path;
                *data_len_p = sizeof(kal_uint8);

                result = MDI_AUDIO_SUCCESS;
            }
            break;
            
        case MDI_AUDIO_GET_INFO_AUDIO_TYPE:      /* Audio type (kal_uint8*) */
            if (*data_len_p >= sizeof(kal_uint8))
            {   
                *((kal_uint8*)data_p) = g_audio_type;
                *data_len_p = sizeof(kal_uint8);

                result = MDI_AUDIO_SUCCESS;
            }
            break;

        case MDI_AUDIO_GET_INFO_MEDIA_SOURCE:    /* Media source (kal_uint8*) */
            if (*data_len_p >= sizeof(kal_uint8))
            {   
                *((kal_uint8*)data_p) = g_media_source;
                *data_len_p = sizeof(kal_uint8);

                result = MDI_AUDIO_SUCCESS;
            }
            break;
            
        case MDI_AUDIO_GET_INFO_IS_IN_CALL:      /* Is in call? (kal_bool*) */
            if (*data_len_p >= sizeof(kal_bool))
            {   
                *((kal_bool*)data_p) = g_is_in_call;
                *data_len_p = sizeof(kal_bool);

                result = MDI_AUDIO_SUCCESS;
            }
            break;

        case MDI_AUDIO_GET_INFO_IS_BT_ON:        /* Is BT on? (kal_bool*) */
            if (*data_len_p >= sizeof(kal_bool))
            {   
                *((kal_bool*)data_p) = (g_is_sco_on || g_is_a2dp_on) ? KAL_TRUE : KAL_FALSE;
                *data_len_p = sizeof(kal_bool);

                result = MDI_AUDIO_SUCCESS;
            }
            break;

        case MDI_AUDIO_GET_INFO_IS_CAMCORDER_ON: /* Is camcorder on? (kal_bool*) */
            if (*data_len_p >= sizeof(kal_bool))
            {   
                *((kal_bool*)data_p) = g_is_camcorder_on;
                *data_len_p = sizeof(kal_bool);

                result = MDI_AUDIO_SUCCESS;
            }
            break;

        case MDI_AUDIO_GET_INFO_IS_FM_ON:        /* Is FM on? (kal_bool*) */
            if (*data_len_p >= sizeof(kal_bool))
            {   
                *((kal_bool*)data_p) = g_is_fm_on;
                *data_len_p = sizeof(kal_bool);

                result = MDI_AUDIO_SUCCESS;
            }
            break;
            
        default:
            result = MDI_AUDIO_UNSUPPORTED_OPERATION;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_audio_type
 * DESCRIPTION
 *  This function is used to update the audio type before issuing a play request
 *  to the MDI. The audio type will be reset to UNKNOWN when a new play request
 *  is arisen.
 * PARAMETERS
 *  audio_type       : [IN]   Audio type
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_set_audio_type(mdi_audio_type_enum audio_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SET_AUDIO_TYPE, audio_type);
    
    g_audio_type = audio_type;
    g_is_audio_type_specified = KAL_TRUE;
}
#endif /* __GAIN_TABLE_SUPPORT */


#ifdef __AUDIO_TRIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_result_hdlr
 * DESCRIPTION
 *  This function is to handle the trimming result
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_trim_result_hdlr(void *ind_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_trim_result_ind_struct *msg_p = (l4aud_trim_result_ind_struct*) ind_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_trim_cb)
    {
        g_trim_cb(msg_p->handle, mdi_audio_get_event(msg_p->result), g_trim_user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_interrupt
 * DESCRIPTION
 *  This function interrupts the trimming.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_trim_interrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TRIM_INTERRUPT, g_trim_handle);
    
    MDI_AUDIO_LOCK;
    
    if (g_trim_cb)
    {
        g_trim_cb(g_trim_handle, MDI_AUDIO_TERMINATED, g_trim_user_data);
        g_trim_cb = NULL;
    }
    
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_open
 * DESCRIPTION
 *  This function opens a trimming handler.
 * PARAMETERS
 *  file_name_in     [IN]       The source file of the trimming
 *  file_name_out    [IN]       The file to be trimmed to
 *  cb_hdlr          [IN]       Trim event handler
 *  user_data        [IN]       User data
 *  handle_p         [OUT]      Trim handle
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_trim_open(kal_wchar* file_name_in, kal_wchar* file_name_out, mdi_aud_trim_callback cb_hdlr, void* user_data, kal_uint32* handle_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TRIM_OPEN);
    
    MDI_AUDIO_LOCK;
    
    result = media_aud_trim_open(file_name_in, file_name_out, handle_p);

    if (result == MED_RES_OK)
    {
        SetProtocolEventHandler(mdi_audio_trim_result_hdlr, MSG_ID_L4AUD_TRIM_RESULT_IND);
        g_trim_cb = cb_hdlr;
        g_trim_user_data = user_data;
        g_trim_handle = *handle_p;
    }
    
    MDI_AUDIO_UNLOCK;

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_close
 * DESCRIPTION
 *  This function closes a trimming handler.
 * PARAMETERS
 *  handle         [IN]      Trim handle
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_trim_close(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TRIM_CLOSE, handle);
    
    MDI_AUDIO_LOCK;
    
    result = media_aud_trim_close(handle);
    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_TRIM_RESULT_IND);
    g_trim_cb = NULL;
    
    MDI_AUDIO_UNLOCK;

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_start
 * DESCRIPTION
 *  This function starts the trimming.
 * PARAMETERS
 *  handle         [IN]      Trim handle
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_trim_start(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TRIM_START, handle);
    
    MDI_AUDIO_LOCK;
    
    if (! mdi_audio_is_idle())
    {
        mdi_audio_stop_all();
    }
    
    result = media_aud_trim_start(handle);

    if (result == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_TRIM;
    }
    
    MDI_AUDIO_UNLOCK;

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_stop
 * DESCRIPTION
 *  This function stops the trimming.
 * PARAMETERS
 *  handle         [IN]      Trim handle
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_trim_stop(kal_uint32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TRIM_STOP, handle);
    
    MDI_AUDIO_LOCK;
    result = media_aud_trim_stop(handle);
    MDI_AUDIO_UNLOCK;

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_set_param
 * DESCRIPTION
 *  This function sets parameters of the trimming.
 * PARAMETERS
 *  handle          [IN]    Trim handle
 *  set_type        [IN]    The type to be set.
 *  data_p          [IN]    The data to be set.
 *  data_len        [IN]    The length of the data.
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_trim_set_param(kal_int32 handle, kal_uint8 set_type, void* data_p, kal_uint16 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TRIM_SET_PARAM, handle, set_type, (kal_uint32)data_p);
    
    MDI_AUDIO_LOCK;
    result = media_aud_trim_set_param(handle, set_type, data_p, data_len);
    MDI_AUDIO_UNLOCK;

    return mdi_audio_get_event(result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_trim_get_param
 * DESCRIPTION
 *  This function gets parameters of the trimming.
 * PARAMETERS
 *  handle          [IN]    Trim handle
 *  get_type        [IN]    The type to be get.
 *  data_p          [IN]    The data to be get.
 *  data_len        [IN]    The length of the data.
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_trim_get_param(kal_int32 handle, kal_uint8 get_type, void* data_p, kal_uint16* data_len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TRIM_GET_PARAM, handle, get_type, (kal_uint32)data_p);
    
    MDI_AUDIO_LOCK;
    result = media_aud_trim_get_param(handle, get_type, data_p, data_len_p);
    MDI_AUDIO_UNLOCK;

    return mdi_audio_get_event(result);
}
#endif /* __AUDIO_TRIM_SUPPORT__ */


#ifdef __BT_SPEAKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_bt_speaker_power_off
 * DESCRIPTION
 *  This function will be called in BT speaker Interrupt handler to reset MDI state & BG Timer.
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_bt_speaker_power_off(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mdi_audio_state = MDI_AUDIO_IDLE;
	mdi_audio_start_background_timer();
}

/*****************************************************************************
 * FUNCTION
 *  mdi_bt_speaker_power_on
 * DESCRIPTION
 *  This function will be called when resume BT speaker to set MDI state and stop BG timer.
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_bt_speaker_power_on(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mdi_audio_state = MDI_AUDIO_PLAY;
	mdi_audio_mode = MDI_AUDIO_PLAY_BT_MUSIC;
	mdi_audio_stop_background_timer();
}
#endif

