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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BTMMIA2DPScr.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements the A2DP setting screen related fucntions
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "MMI_include.h"
#include "MMI_features.h"
#if defined(__MMI_A2DP_SUPPORT__)

/***************************************************************************** 
* Included files
*****************************************************************************/
//#include "med_struct.h"

/* a2dp header files */
//#include "bt_a2dp_struct.h"
//#include "bt_a2dp.h"

#include "BTMMIScrGprots.h"

#include "BtcmSrvGprot.h"
#include "BtcmCuiGprot.h"
//#include "BTMMIA2DP.h"
#ifdef __MMI_AVRCP_SUPPORT__
//#include "BTMMIAVRCPGProt.h"
#endif
// mtk solution only

//#include "mdi_datatype.h"
//#include "mdi_audio.h"
//#include "bttypes.h"

//#include "BTMMISCOPathGprots.h"

#include "av_bt.h"
#include "mmi_rp_app_a2dp_def.h"

#ifdef __MMI_AUDIO_PLAYER__
#include "AudioPlayerProt.h"
#elif defined(__MMI_MEDIA_PLAYER__)
#include "MediaplayerGprot.h"
#endif

#ifdef __MMI_FM_VIA_A2DP__
#include "FMRadioProt.h"
#endif 

#include "Nvram_common_defs.h"
//#include "ConnectivityResDef.h"  /* for STR_BT_PROHIBIT_BY_SIMAP used by sap. */
//#include "MobileTVPlayerGProt.h"
//#include "CommonScreens.h"

#include "conversions.h"

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
//#include "BTMMIAVRCPGProt.h"
#endif

#include "InlineCuiGProt.h"

#ifdef __A8BOX_SUPPORT__
#include "elf_audio.h"
#endif /* __A8BOX_SUPPORT__ */

#include "ModeSwitchSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "BTMMIA2DPScr.h"
#include "A2dpSrvGprot.h"
#include "bluetooth_a2dp_struct.h"
#include "gui_data_types.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_nvram_gprot.h"
#include "string.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "gui_typedef.h"
#include "Unicodexdcl.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "BtAudioSrvGProt.h"

mmi_a2dp_bt_ctx_struct a2dp_ctx;
U8 selected_bt_a2dp_output = 0;     /* 0: off, 1: on */
UI_character_type a2dp_settings_headset_name[SRV_BT_CM_BD_FNAME_LEN];
srv_bt_cm_bt_addr* a2dp_settings_selected_headset_temp_p;
srv_bt_cm_bt_addr a2dp_settings_selected_headset_temp;
static a2dp_dev_info_struct a2dp_dev_info;

#ifdef __MMI_AUDIO_PLAYER__
extern MMI_BOOL settings_done_back_to_main;
#endif

#ifndef __MMI_A2DP_HIDE_BT_SETTINGS__
extern void mmi_a2dp_write_bt_settings(void);
#endif

#ifndef __MMI_A2DP_HIDE_BT_SETTINGS__

#define MMI_A2DP_SETTINGS_OUTPUT_CAPTION    (CUI_INLINE_ITEM_ID_BASE)
#define MMI_A2DP_SETTINGS_OUTPUT            (CUI_INLINE_ITEM_ID_BASE + 1)
#define MMI_A2DP_SETTINGS_HEADSET_CAPTION   (CUI_INLINE_ITEM_ID_BASE + 2)
#define MMI_A2DP_SETTINGS_HEADSET           (CUI_INLINE_ITEM_ID_BASE + 3)

/* output caption */
static const cui_inline_item_display_only_struct g_a2dp_settings_output_caption =
{
    STR_ID_A2DP_SETTINGS_OUTPUT
};


/* output */
static const U16 g_a2dp_settings_output_str[] = 
{
    STR_GLOBAL_OFF,
    STR_GLOBAL_ON
};

static const cui_inline_item_select_struct g_a2dp_settings_output = 
{
    2, 0, (U16 *)g_a2dp_settings_output_str
};

/* headset caption */
static const cui_inline_item_display_only_struct g_a2dp_settings_headset_caption =
{
    STR_ID_A2DP_SETTINGS_BT_HEADSET
};

/* headset */
static const cui_inline_item_display_only_struct g_a2dp_settings_headset =
{
    STR_GLOBAL_NONE
};

static const cui_inline_set_item_struct g_a2dp_settings_inline_item[4] =
{
    {MMI_A2DP_SETTINGS_OUTPUT_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION,     IMG_GLOBAL_L1,  (void*)&g_a2dp_settings_output_caption},
    {MMI_A2DP_SETTINGS_OUTPUT,     CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_a2dp_settings_output},
    {MMI_A2DP_SETTINGS_HEADSET_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION,     IMG_GLOBAL_L2,  (void*)&g_a2dp_settings_headset_caption},
    {MMI_A2DP_SETTINGS_HEADSET,    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,     0,  (void*)&g_a2dp_settings_headset}
};

static const cui_inline_struct g_a2dp_settings_inline_screen = 
{
    4,
    STR_ID_A2DP_BLUETOOTH_SETTINGS,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE,
    0,
    g_a2dp_settings_inline_item
};
#endif /*#ifndef __MMI_A2DP_HIDE_BT_SETTINGS__*/

#define __mmi_a2dp_apis__

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_is_output_to_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    returns if a2dp currently could and should be available
 *****************************************************************************/
MMI_BOOL mmi_a2dp_is_output_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_power_on = MMI_FALSE;
    MMI_BOOL in_flight_mode = MMI_FALSE;
    MMI_BOOL output_to_bt = MMI_FALSE;
	MMI_BOOL dev_cap=MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#if defined(__MMI_A2DP_SUPPORT__) && defined(__MMI_BT_DIALER_SUPPORT__)
    if(!srv_a2dp_is_output_to_bt())
    {
        return MMI_FALSE;
    }
#endif

    if(!mmi_bt_is_to_display_bt_menu())
    {
        return MMI_FALSE;
    }
    bt_power_on = mmi_bt_is_power_on(MMI_FALSE);
    if(bt_power_on==MMI_FALSE)
    {
    		return MMI_FALSE;
    }
    
#ifndef __MMI_BT_DIALER_SUPPORT__
	dev_cap = srv_bt_cm_check_dev_profile_support_status( 
				mmi_a2dp_get_bt_headset(),
				SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID );

	if(dev_cap==MMI_FALSE)
	{
		return MMI_FALSE;
	}
#endif

#ifdef __MMI_BT_IN_FLIGHT_MODE__
    in_flight_mode = MMI_FALSE;
#else
    in_flight_mode = !srv_mode_switch_is_network_service_available();
#endif

#ifndef __MMI_BT_SPEAKER_SUPPORT__
#ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
    output_to_bt = (srv_btaud_get_status(BTAUD_CHNL_ANY) >= BTAUD_ACTIVE) && srv_bt_cm_is_audio_path_to_headset();
#else
    output_to_bt = a2dp_ctx.a2dp_settings.bt_a2dp_output;    
#endif
#else
    output_to_bt = MMI_TRUE;
    a2dp_ctx.a2dp_settings.bt_a2dp_output = 1;
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_IS_OUTPUT_TO_BT,bt_power_on,in_flight_mode,output_to_bt);    

    return (MMI_BOOL)( bt_power_on && !in_flight_mode && output_to_bt);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_check_output_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    returns if a2dp currently could and should be available
 *****************************************************************************/
MMI_BOOL mmi_a2dp_check_output_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_power_on = MMI_FALSE;
    MMI_BOOL in_flight_mode = MMI_FALSE;
    MMI_BOOL output_to_bt = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_bt_is_to_display_bt_menu())
    {
        return MMI_FALSE;
    }

    bt_power_on = mmi_bt_is_power_on(MMI_FALSE);

#ifdef __MMI_BT_IN_FLIGHT_MODE__
    in_flight_mode = MMI_FALSE;
#else
    in_flight_mode = !srv_mode_switch_is_network_service_available();
#endif

#ifndef __MMI_BT_SPEAKER_SUPPORT__
#ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
    output_to_bt = srv_bt_cm_is_audio_path_to_headset();
#else
    output_to_bt = a2dp_ctx.a2dp_settings.bt_a2dp_output;    
#endif
#else
    output_to_bt = MMI_TRUE;
    a2dp_ctx.a2dp_settings.bt_a2dp_output = 1;
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_IS_OUTPUT_TO_BT,bt_power_on,in_flight_mode,output_to_bt);    

    return (MMI_BOOL)( bt_power_on && !in_flight_mode && output_to_bt);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_get_bt_headset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_bt_addr*  returns user chosen bt headset address
 *****************************************************************************/
srv_bt_cm_bt_addr *mmi_a2dp_get_bt_headset(void)
{
    a2dp_role_enum role = BT_A2DP_SINK;
    U8 Index;
    kal_bool bFound;

#ifdef __BT_SPEAKER_SUPPORT__
    bFound = srv_a2dp_quiry_by_role(BT_A2DP_SOURCE, &Index);
    if(bFound)
    {
        srv_a2dp_get_dev_info_by_index(&a2dp_dev_info, Index);

        MMI_TRACE(
            MMI_CONN_TRC_G7_BT,
            SRV_BT_CM_CHECK_DEV_PROFILE_SUPPORT_STATUS,
            a2dp_dev_info.address.lap,
            a2dp_dev_info.address.uap,
            a2dp_dev_info.address.nap,
            0,
            0);
        
        return &(a2dp_dev_info.address);
    }
    else
    {
        return NULL;
    }
#else
    #ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
        static btaud_device_info info;

        if (srv_btaud_get_active_device(BTAUD_CHNL_ANY, &info))
            return &info.addr;

        return NULL;

    #else
        if (a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid)
        {
            return &a2dp_ctx.a2dp_settings.bt_a2dp_addr;
        }
    	return NULL;
    #endif
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_bt_power_off_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_bt_power_off_callback(MMI_BOOL success)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_SETTING_POWER_OFF_CALLBACK,success);

    if (success)
    {
    #ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
        #ifdef __MMI_AUDIO_PLAYER__
            mmi_audply_turn_off_bt_output();
        #endif /*__MMI_AUDIO_PLAYER__*/
        #ifdef __MMI_MEDIA_PLAYER__
            mmi_medply_turn_off_bt_output();
        #endif
        #ifdef __A8BOX_SUPPORT__
            mmi_elf_audio_play_switch_off_bt_output();
        #endif /*__A8BOX_SUPPORT__*/
            av_bt_close_codec();
            av_bt_close(KAL_FALSE);
    #else
        if (a2dp_ctx.a2dp_settings.bt_a2dp_output)
        {
            a2dp_ctx.a2dp_settings.bt_a2dp_output = KAL_FALSE;
            mmi_a2dp_write_bt_settings();

            /* switch output: ON -> OFF */
        #ifdef __MMI_AUDIO_PLAYER__
            mmi_audply_switch_bt_output();
        #endif /*__MMI_AUDIO_PLAYER__*/
        #ifdef __MMI_MEDIA_PLAYER__
            mmi_medply_switch_bt_output();
        #endif
        #ifdef __MMI_FM_VIA_A2DP__
            mmi_fmrdo_switch_bt_output();
        #endif
        #ifdef __A8BOX_SUPPORT__
            mmi_elf_audio_play_switch_bt_output();
        #endif /*__A8BOX_SUPPORT__*/
            av_bt_close_codec();
            av_bt_close(KAL_FALSE);
        }
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_bt_delete_device_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bd_addr      [IN]    when it's NULL, means all devices
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_bt_delete_device_callback(srv_bt_cm_bt_addr* bd_addr)
{

#ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_AUDIO_PLAYER__
/* under construction !*/
        #endif /*__MMI_AUDIO_PLAYER__*/
        #ifdef __MMI_MEDIA_PLAYER__
/* under construction !*/
        #endif
        #ifdef __A8BOX_SUPPORT__
/* under construction !*/
        #endif /*__A8BOX_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else
    if (a2dp_ctx.a2dp_settings.bt_a2dp_output)
    {
        /* if it's delete all, or the target device bt addr is the same with ours, then turn it off */
        if (bd_addr == NULL || srv_a2dp_cmp_bt_addr(bd_addr, &a2dp_ctx.a2dp_settings.bt_a2dp_addr))
        {
            a2dp_ctx.a2dp_settings.bt_a2dp_output = KAL_FALSE;
            a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid = KAL_FALSE;
            mmi_a2dp_write_bt_settings();

            /* switch output: ON -> OFF */
        #ifdef __MMI_AUDIO_PLAYER__
            mmi_audply_switch_bt_output();
        #endif /*__MMI_AUDIO_PLAYER__*/
        #ifdef __MMI_MEDIA_PLAYER__
            mmi_medply_switch_bt_output();
        #endif
        #ifdef __MMI_FM_VIA_A2DP__
            mmi_fmrdo_switch_bt_output();
        #endif
        #ifdef __A8BOX_SUPPORT__
            mmi_elf_audio_play_switch_bt_output();
        #endif /* __A8BOX_SUPPORT__ */
        }
    }
    else if (a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid)
    {
        /* if it's delete all, or the target device bt addr is the same with ours, then set it invalid */
        if (bd_addr == NULL || srv_a2dp_cmp_bt_addr(bd_addr, &a2dp_ctx.a2dp_settings.bt_a2dp_addr))
        {
            a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid = KAL_FALSE;
            mmi_a2dp_write_bt_settings();
        }
    }
#endif

}

#ifndef __MMI_A2DP_HIDE_BT_SETTINGS__
/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_read_bt_settings
 * DESCRIPTION
 *  read bt settings for init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_read_bt_settings(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_A2DP_SETTINGS_LID, 1, (void*)&a2dp_ctx.a2dp_settings,
        sizeof(mmi_a2dp_bt_settings_struct), &error);
#else
    a2dp_ctx.a2dp_settings.bt_a2dp_output = MMI_FALSE;
    a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid = MMI_FALSE;
#endif /* __MTK_TARGET__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_write_bt_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_write_bt_settings(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_A2DP_SETTINGS_LID, 1, (void*)&a2dp_ctx.a2dp_settings,
        sizeof(mmi_a2dp_bt_settings_struct), &error);
#endif /* __MTK_TARGET__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_bluetooth_settings_apply_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_a2dp_output      [IN]
 *  back_to_main        [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_a2dp_bluetooth_settings_apply_change(MMI_BOOL bt_a2dp_output, MMI_BOOL back_to_main)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_BOOL headset_changed = MMI_FALSE;
    MMI_BOOL output_changed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (a2dp_settings_selected_headset_temp_p != NULL && (!a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid
        || !srv_a2dp_cmp_bt_addr(a2dp_settings_selected_headset_temp_p, &a2dp_ctx.a2dp_settings.bt_a2dp_addr)))
    {
        /* a headset is selected from list and previous headset is invalid or bt addr are different */
        headset_changed = MMI_TRUE;
    }

    if (a2dp_ctx.a2dp_settings.bt_a2dp_output)
    {
        if (!bt_a2dp_output)
            output_changed = MMI_TRUE;
    }
    else
    {
        if (bt_a2dp_output)
            output_changed = MMI_TRUE;
    }

    /* update current setting values & write to NVRAM */
    a2dp_ctx.a2dp_settings.bt_a2dp_output = bt_a2dp_output;
    if (a2dp_settings_selected_headset_temp_p)
    {
        memcpy( &a2dp_ctx.a2dp_settings.bt_a2dp_addr, a2dp_settings_selected_headset_temp_p,
            sizeof(srv_bt_cm_bt_addr) );
        a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid = MMI_TRUE;
    }
    mmi_a2dp_write_bt_settings();

    /* apply output or headset change */
    if (output_changed)
    {
        /* switch output: OFF -> ON or ON -> OFF */
    #ifdef __MMI_AUDIO_PLAYER__
        mmi_audply_switch_bt_output();
    #endif /*__MMI_AUDIO_PLAYER__*/
    #ifdef __MMI_MEDIA_PLAYER__
        mmi_medply_switch_bt_output();
    #endif
    #ifdef __MMI_FM_VIA_A2DP__
        mmi_fmrdo_switch_bt_output();
    #endif
    #ifdef __A8BOX_SUPPORT__
        mmi_elf_audio_play_switch_bt_output();
    #endif /* __A8BOX_SUPPORT__ */
    }
    else if(bt_a2dp_output && headset_changed)
    {
        if(mmi_a2dp_is_output_to_bt())
        {
        /* output is ON and change headset */
        #ifdef __MMI_AUDIO_PLAYER__
            mmi_audply_sync_bt_output();
        #endif /*__MMI_AUDIO_PLAYER__*/
        #ifdef __MMI_MEDIA_PLAYER__
            mmi_medply_sync_bt_output();
        #endif
        #ifdef __MMI_FM_VIA_A2DP__
            mmi_fmrdo_sync_bt_output();
        #endif
        #ifdef __A8BOX_SUPPORT__
            mmi_elf_audio_sync_bt_output();
        #endif /* __A8BOX_SUPPORT__ */
        }
    }
    else if(bt_a2dp_output && !av_bt_is_codec_open())
    {
    #ifdef __MMI_AUDIO_PLAYER__
        mmi_audply_switch_bt_output();
    #endif /*__MMI_AUDIO_PLAYER__*/
    #ifdef __MMI_MEDIA_PLAYER__
        mmi_medply_switch_bt_output();
    #endif
    #ifdef __MMI_FM_VIA_A2DP__
        mmi_fmrdo_switch_bt_output();
    #endif
    #ifdef __A8BOX_SUPPORT__
        mmi_elf_audio_play_switch_bt_output();
    #endif /* __A8BOX_SUPPORT__ */
    }

{
    U16 str_id = 0;
    
#ifdef __MMI_AUDIO_PLAYER__
    str_id = mmi_audply_get_string_for_a2dp(bt_a2dp_output);
#elif defined(__MMI_MEDIA_PLAYER__)
    str_id = mmi_medply_settings_get_a2dp_popup_string(bt_a2dp_output);
#endif

    if(str_id != 0)
    {
        mmi_popup_display_simple((WCHAR *)GetString(str_id), MMI_EVENT_INFO, GRP_ID_A2DP_SETTINGS, (void*)MMI_TRUE);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_A2DP_SETTINGS);
    }

}
    return headset_changed || output_changed;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_check_set_default_earphone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_check_set_default_earphone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr* default_dev;
    MMI_BOOL bt_a2dp_output = (selected_bt_a2dp_output == 1);    
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CHECK_SET_DEFAULT_EARPHONE);

    if(a2dp_settings_selected_headset_temp_p == NULL && !a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid)
    {
        mmi_a2dp_bluetooth_settings_apply_change(bt_a2dp_output, MMI_FALSE);
        return;
    }


    if(!srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HS))
    {
        /*no default earphone, so set this earohone to default*/
        if(a2dp_settings_selected_headset_temp_p != NULL)
        {
            srv_bt_cm_set_default_dev(SRV_BT_CM_DEFAULT_DEV_TYPE_HS, a2dp_settings_selected_headset_temp_p);
        }
        else if(a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid)
        {
            srv_bt_cm_set_default_dev(SRV_BT_CM_DEFAULT_DEV_TYPE_HS, &a2dp_ctx.a2dp_settings.bt_a2dp_addr);
        }

        mmi_a2dp_bluetooth_settings_apply_change(bt_a2dp_output, MMI_FALSE);

        return;
    }

    default_dev = srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HS);

     /*check if a2dp earphone is the same as default earphone*/
    if(a2dp_settings_selected_headset_temp_p != NULL)
    {
        if(srv_a2dp_cmp_bt_addr(default_dev, a2dp_settings_selected_headset_temp_p))
        {
            mmi_a2dp_bluetooth_settings_apply_change(bt_a2dp_output, MMI_FALSE);
            return;
        }
    }
    else if(a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid)
    {
        if(srv_a2dp_cmp_bt_addr(default_dev, &a2dp_ctx.a2dp_settings.bt_a2dp_addr))
        {
            mmi_a2dp_bluetooth_settings_apply_change(bt_a2dp_output, MMI_FALSE);
            return;
        }
    }

    /*ask user if wish to set A2DP earphone to default earphone*/
    mmi_confirm_property_init(&arg,CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_A2DP_SETTINGS;
    
    a2dp_ctx.confirm_gid = mmi_confirm_display(
                                    (WCHAR *)GetString(STR_ID_A2DP_SETTINGS_SET_TO_DEFAULT_EARPHONE),
                                    MMI_EVENT_QUERY,
                                    &arg);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_set_default_earphone_reject
 * DESCRIPTION
 *  reject hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_set_default_earphone_reject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_a2dp_output = (selected_bt_a2dp_output == 1);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_SET_DEFAULT_EARPHONE_REJECT);

    mmi_a2dp_bluetooth_settings_apply_change(bt_a2dp_output, MMI_FALSE);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_set_default_earphone_accept
 * DESCRIPTION
 *  accept hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_set_default_earphone_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_a2dp_output = (selected_bt_a2dp_output == 1);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_SET_DEFAULT_EARPHONE_ACCEPT);

    /*set to default earphone*/
    if(a2dp_settings_selected_headset_temp_p != NULL)
    {
        srv_bt_cm_set_default_dev(SRV_BT_CM_DEFAULT_DEV_TYPE_HS, a2dp_settings_selected_headset_temp_p);
    }
    else if(a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid)
    {
        srv_bt_cm_set_default_dev(SRV_BT_CM_DEFAULT_DEV_TYPE_HS, &(a2dp_ctx.a2dp_settings.bt_a2dp_addr));
    }

    mmi_a2dp_bluetooth_settings_apply_change(bt_a2dp_output, MMI_FALSE);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_bt_power_on_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_bt_power_on_callback(MMI_BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cur_screen_group;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_SETTING_POWER_ON_CALLBACK,success);

    cur_screen_group = mmi_frm_group_get_active_id();

    if(cur_screen_group == GRP_ID_A2DP_SETTINGS)
    {
        if(success)
        {
            /* Remove default headset settting */
#ifdef __MMI_BT_DEFAULT_HEADSET__            
            mmi_a2dp_check_set_default_earphone();
#else
            mmi_a2dp_bluetooth_settings_apply_change(selected_bt_a2dp_output, MMI_FALSE);
#endif
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_bluetooth_settings_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_bluetooth_settings_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_close(GRP_ID_A2DP_SETTINGS);
    a2dp_ctx.inline_gid = GRP_ID_INVALID;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_bluetooth_settings_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_bluetooth_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_a2dp_output = (selected_bt_a2dp_output == 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_SETTING_DONE,selected_bt_a2dp_output,a2dp_settings_selected_headset_temp_p,a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid);

#ifdef __MMI_AUDIO_PLAYER__    
    settings_done_back_to_main = MMI_FALSE;
#endif

    if (bt_a2dp_output && a2dp_settings_selected_headset_temp_p == NULL
        && !a2dp_ctx.a2dp_settings.bt_a2dp_headset_valid)
    {
        mmi_popup_display_simple((WCHAR *)GetString(STR_ID_A2DP_SETTINGS_ERR_MUST_SELECT_HEADSET), MMI_EVENT_FAILURE, GRP_ID_A2DP_SETTINGS, (void*)MMI_FALSE);
    }
    else if (bt_a2dp_output)
    {
        /* when BT A2DP Output is ON and BT is not power on, 
         * check if it's not in flight mode then we power on BT 
         */
#ifndef __MMI_BT_IN_FLIGHT_MODE__
        if(!srv_mode_switch_is_network_service_available())
        {
            mmi_popup_display_simple((WCHAR *)GetString(STR_ID_A2DP_SETTINGS_ERR_FLIGHT_MODE), MMI_EVENT_FAILURE, GRP_ID_A2DP_SETTINGS, (void*)MMI_FALSE);
        }
        else 
#endif
        if(mmi_bt_is_power_on_with_power_on_confirm(MMI_FALSE,NULL))
        {
#ifdef __MMI_BT_DEFAULT_HEADSET__
            mmi_a2dp_check_set_default_earphone();
#else
            mmi_a2dp_bluetooth_settings_apply_change(selected_bt_a2dp_output, MMI_FALSE);
#endif
        }
        else
        {
            /*pop up power on confirm screen*/
            a2dp_ctx.power_on_gid = cui_bt_power_on_create(GRP_ID_A2DP_SETTINGS);

            if (a2dp_ctx.power_on_gid != GRP_ID_INVALID)
            {
                cui_bt_power_on_run(a2dp_ctx.power_on_gid);
            }
        }
    }
    else
    {
#ifdef __MMI_BT_DEFAULT_HEADSET__
        mmi_a2dp_check_set_default_earphone();
#else
        mmi_a2dp_bluetooth_settings_apply_change(selected_bt_a2dp_output, MMI_FALSE);
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_select_headset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_select_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    a2dp_ctx.select_device_gid = cui_bt_device_select_screen_create(GRP_ID_A2DP_SETTINGS);

    if (a2dp_ctx.select_device_gid != GRP_ID_INVALID)
    {
        cui_bt_device_select_screen_set_mask(
            a2dp_ctx.select_device_gid, 
            MMI_BT_RENDERING_MAJOR_SERVICE_MASK | 
            MMI_BT_AV_MAJOR_DEVICE_MASK,
            SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID
            );
        
        cui_bt_device_select_screen_run(a2dp_ctx.select_device_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_select_bt_a2dp_headset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_select_bt_a2dp_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MMI_BT_IN_FLIGHT_MODE__
    if(!srv_mode_switch_is_network_service_available())
    {
        mmi_popup_display_simple((WCHAR *)GetString(STR_ID_A2DP_SETTINGS_ERR_FLIGHT_MODE), MMI_EVENT_FAILURE, GRP_ID_A2DP_SETTINGS, (void*)MMI_FALSE);
    }
    else
#endif
    {
        mmi_a2dp_select_headset();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_screen_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 * mmi_event_struct*    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_a2dp_screen_group_proc(mmi_event_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    cui_event_bt_cm_device_select_result_struct *selete_device_evt;
    cui_event_bt_cm_power_on_result_struct *power_on_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    switch(event->evt_id)
    {
        /*Inline Cui*/
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)event;

            if(notify->sender_id == a2dp_ctx.inline_gid)
            {
                switch(notify->event_type)
                {
                    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
                    {
                        U16 rsk_id = STR_GLOBAL_DONE;
                        U16 lsk_id = STR_GLOBAL_OK;

                        if(notify->item_id == MMI_A2DP_SETTINGS_OUTPUT)
                        {
                            rsk_id = STR_GLOBAL_BACK;
                        }
                        else if(notify->item_id == MMI_A2DP_SETTINGS_HEADSET)
                        {
                            if (a2dp_settings_selected_headset_temp_p == NULL)
                            {
                                rsk_id = STR_GLOBAL_BACK;
                            }
                            
                            lsk_id = STR_GLOBAL_SELECT;
                        }

                        cui_inline_set_softkey_text(
                            a2dp_ctx.inline_gid,
                            notify->item_id,
                            MMI_LEFT_SOFTKEY,
                            lsk_id);

                        cui_inline_set_softkey_text(
                            a2dp_ctx.inline_gid,
                            notify->item_id,
                            MMI_RIGHT_SOFTKEY,
                            rsk_id);
                        
                        break;
                    }

                }
            }
            break;
        }

        /*RSK*/
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *submit = (cui_event_inline_submit_struct *)event;

            if(submit->sender_id == a2dp_ctx.inline_gid)
            {
                cui_inline_get_value(a2dp_ctx.inline_gid, MMI_A2DP_SETTINGS_OUTPUT, (void *)&selected_bt_a2dp_output);
                 
                /*OK*/
                if(submit->item_id == MMI_A2DP_SETTINGS_OUTPUT)
                {
                    mmi_a2dp_bluetooth_settings_done();
                }
                /*Select*/
                else if(submit->item_id == MMI_A2DP_SETTINGS_HEADSET)
                {
                    mmi_a2dp_select_bt_a2dp_headset();
                }
            }
            
            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *abort = (cui_event_inline_abort_struct*)event;

            if(abort->sender_id == a2dp_ctx.inline_gid)
            {
                cui_inline_get_value(a2dp_ctx.inline_gid, MMI_A2DP_SETTINGS_OUTPUT, (void *)&selected_bt_a2dp_output);

                /*Back*/
                if(abort->item_id == MMI_A2DP_SETTINGS_OUTPUT)
                {
                    mmi_a2dp_bluetooth_settings_back();
                }
                else if(abort->item_id == MMI_A2DP_SETTINGS_HEADSET)
                {
                    /*Done*/
                    if(a2dp_settings_selected_headset_temp_p != NULL)
                    {
                        mmi_a2dp_bluetooth_settings_done();   
                    }
                    /*Back*/
                    else
                    {
                        mmi_a2dp_bluetooth_settings_back();
                    }
                }
            }

            break;
        }

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            srv_bt_cm_bt_addr *selected_bth_dev;

            if(a2dp_settings_selected_headset_temp_p == NULL)
            {
                selected_bth_dev = mmi_a2dp_get_bt_headset();
                if (selected_bth_dev == NULL)
                {
                    mmi_ucs2cpy((CHAR*)a2dp_settings_headset_name, (const CHAR*)GetString(STR_GLOBAL_NONE));
                }
                else
                {
                    U8 name[SRV_BT_CM_BD_FNAME_LEN];
                    /*in case user modify device name in bt cm setting menu*/
                    srv_bt_cm_get_dev_name(
                        selected_bth_dev,
                        (U8) SRV_BT_CM_BD_FNAME_LEN,
                        name);

                    mmi_chset_utf8_to_ucs2_string(
                        (kal_uint8*) (a2dp_settings_headset_name),
                        SRV_BT_CM_BD_NAME_UCS2_LEN,
                        (kal_uint8*) name);

                }
            }
            else
            {
                /* back from history */
                U8 name[SRV_BT_CM_BD_FNAME_LEN];
                /*in case user modify device name in bt cm setting menu*/
                srv_bt_cm_get_dev_name(
                    a2dp_settings_selected_headset_temp_p,
                    (U8) SRV_BT_CM_BD_FNAME_LEN,
                    name);

                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) (a2dp_settings_headset_name),
                    SRV_BT_CM_BD_NAME_UCS2_LEN,
                    (kal_uint8*) name);
            }

        	cui_inline_set_item_displayonly(a2dp_ctx.inline_gid, MMI_A2DP_SETTINGS_HEADSET, a2dp_settings_headset_name, STR_GLOBAL_NONE);

            break;
        }

        /* BT Power On Cui */
        case EVT_ID_CUI_BT_CM_POWER_ON_RESULT:
        {
            MMI_BOOL success = MMI_FALSE;    

            power_on_evt = (cui_event_bt_cm_power_on_result_struct*)event;
            success = power_on_evt->result;

            cui_bt_power_on_close(a2dp_ctx.power_on_gid);
            a2dp_ctx.power_on_gid = GRP_ID_INVALID;

            mmi_a2dp_bt_power_on_callback(success);
            
            break;
        }

        /* BT Device Select Cui */
        case EVT_ID_CUI_BT_CM_DEVICE_SELECT:
        {
            
            selete_device_evt = (cui_event_bt_cm_device_select_result_struct*)event;

            if(selete_device_evt->result)
            {
                a2dp_settings_selected_headset_temp.lap = selete_device_evt->lap;
                a2dp_settings_selected_headset_temp.uap = selete_device_evt->uap;
                a2dp_settings_selected_headset_temp.nap = selete_device_evt->nap;

                a2dp_settings_selected_headset_temp_p = &a2dp_settings_selected_headset_temp;
            }            
            cui_bt_device_select_screen_close(a2dp_ctx.select_device_gid);
            a2dp_ctx.select_device_gid = GRP_ID_INVALID;
            
            break;
        }

        case EVT_ID_POPUP_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)event;

            switch(alert->result)
            {
                case MMI_ALERT_CNFM_YES:
                case MMI_ALERT_CNFM_OK:
                {
                    mmi_a2dp_set_default_earphone_accept();
                    mmi_alert_dismiss(a2dp_ctx.confirm_gid);
                    break;
                }

                case MMI_ALERT_CNFM_NO:
                case MMI_ALERT_CNFM_CANCEL:
                {
                    mmi_a2dp_set_default_earphone_reject();
                    mmi_alert_dismiss(a2dp_ctx.confirm_gid);
                    break;
                }

                default:
                {
                    if(alert->user_tag == (void*)MMI_TRUE)
                    {
                        mmi_frm_group_close(GRP_ID_A2DP_SETTINGS);
                    }
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

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_entry_bluetooth_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_entry_bluetooth_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_ENTRY_MAIN);

    /*delete the re-entry screen*/
    if(mmi_frm_group_is_present(GRP_ID_A2DP_SETTINGS))
    {
        mmi_frm_group_close(GRP_ID_A2DP_SETTINGS);
    }

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_A2DP_SETTINGS, mmi_a2dp_screen_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_A2DP_SETTINGS,0);

    /* init setting values */
    if (a2dp_ctx.a2dp_settings.bt_a2dp_output)
    {
        selected_bt_a2dp_output = 1;
    }
    else
    {
        selected_bt_a2dp_output = 0;
    }
    a2dp_settings_selected_headset_temp_p = NULL;
    memset(&a2dp_settings_selected_headset_temp, 0, sizeof(srv_bt_cm_bt_addr));

    a2dp_ctx.inline_gid = cui_inline_create(GRP_ID_A2DP_SETTINGS, &g_a2dp_settings_inline_screen);

    cui_inline_set_title_icon(a2dp_ctx.inline_gid, GetRootTitleIcon(MENU_CONN_BT_MAIN));

    cui_inline_set_value(a2dp_ctx.inline_gid, MMI_A2DP_SETTINGS_OUTPUT, (void*)selected_bt_a2dp_output);

    cui_inline_run(a2dp_ctx.inline_gid);
    
}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_bt_output_change_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on_off      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_bt_output_change_callback(MMI_BOOL on_off)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_SETTING_OUTPUT_CHANGE_CALLBACK,on_off);

    /* switch output: OFF -> ON or ON -> OFF */
    #ifdef __MMI_AUDIO_PLAYER__
        mmi_audply_switch_bt_output();
    #endif /*__MMI_AUDIO_PLAYER__*/
    #ifdef __MMI_MEDIA_PLAYER__
        mmi_medply_switch_bt_output();
    #endif
    #ifdef __MMI_FM_VIA_A2DP__
        mmi_fmrdo_switch_bt_output();
    #endif
    #ifdef __A8BOX_SUPPORT__
        mmi_elf_audio_play_switch_bt_output();
    #endif /* __A8BOX_SUPPORT__ */

}


#endif /* __MMI_A2DP_HIDE_BT_SETTINGS__ */
    
#endif /* __MMI_A2DP_SUPPORT__ */
