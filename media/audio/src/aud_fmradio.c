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
 * aud_fmradio.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes FM Radio service functions
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
//#include "resource_audio.h"
//#include "fat_fs.h"
//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
//#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "aud_bt_hfp.h"
#include "med_utility.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "string.h"
#include "fmr_common_api.h"
#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif

#ifdef __FM_RADIO_RDS_SUPPORT__
#include "fmr_rds_api.h"
#endif 

#include "fmr_config_customize.h"


/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/
#ifdef __MED_FMR_MOD__
#define FM_RADIO_INPUT_LEVEL_THRESHOLD 5 /* No used. The threshold will be determined by FMR module. */
#endif 

#define _AUD_MODULE_FMR_TRACE(x, y, z)   AUD_MODULE_FM_RADIO_TRACE(x, y, z, __LINE__)

#ifdef __FM_RADIO_HW_SEARCH__
typedef struct
{
    kal_bool is_step_up;
    kal_bool is_preset;
    kal_uint16 seek_space;
} aud_fmr_hw_search_struct;
#endif /* __FM_RADIO_HW_SEARCH__ */

#ifdef __FM_RADIO_RDS_SUPPORT__
typedef struct
{
    kal_bool allow_switch;
    kal_uint8 state;	
    kal_uint16 freq;
    kal_uint16 data[FM_RDS_MAX_DATA_BUFF_SIZE];
    kal_uint16 rds_log;
    kal_uint16 *RT_Data;
    kal_uint16 *PS_Data;
    kal_uint16 *AF_Data;
    kal_uint16 *TP_Data;
} aud_fmr_rds_context_struct;
#endif /* __FM_RADIO_RDS_SUPPORT__ */

/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
//extern kal_uint8 current_playing_fmradio_volume_level;
extern kal_uint8 current_playing_melody_volume_level;   /* defined in aud_melody.c */

#if defined(TV_OUT_SUPPORT)
extern kal_bool audio_tv_cable_in;
extern kal_bool audio_tv_loud_speaker;
#endif /* TV_OUT_SUPPORT */

#ifdef __FM_RADIO_HW_SCAN__
static kal_uint8 *g_scan_table;
static kal_bool aud_fmr_scan_confirm = KAL_FALSE;
#endif /* __FM_RADIO_HW_SCAN__ */

#ifdef __FM_RADIO_HW_SEARCH__
static kal_bool aud_fmr_seek_confirm = KAL_FALSE;
static kal_uint8 seek_counter;
static aud_fmr_hw_search_struct aud_fmr_search; /* Can be moved to dynamic memory */
#endif /* __FM_RADIO_HW_SEARCH__ */

#ifdef __FM_RADIO_RDS_SUPPORT__
static aud_fmr_rds_context_struct g_fmr_rds_cntxt;
static kal_bool g_resend_log;
#endif /* __FM_RADIO_RDS_SUPPORT__ */

#if defined(__FM_RADIO_HW_SCAN__) || defined(__FM_RADIO_RDS_SUPPORT__)
const kal_uint16 bit_map_masks[16] = 
    {
        0x0001, 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040, 0x0080,
        0x0100, 0x0200, 0x0400, 0x0800, 0x1000, 0x2000, 0x4000, 0x8000
    };
#endif /* __FM_RADIO_HW_SCAN__ || __FM_RADIO_RDS_SUPPORT__ */

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 
#ifdef __FM_RADIO_RDS_SUPPORT__
static void aud_fmr_rds_enable(void);
static void aud_fmr_rds_disable(void);
#endif /* __FM_RADIO_RDS_SUPPORT__ */

/*-----------------------------------------------------------------------------
                    function implementation
 ----------------------------------------------------------------------------*/ 
/*****************************************************************************
 * FUNCTION
 *  aud_fmr_power_on_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_power_on_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_power_on_req_struct *msg_p = (media_fmr_power_on_req_struct*) ilm_ptr->local_para_ptr;

#ifndef __GAIN_TABLE_SUPPORT__
    kal_uint8 volume_type = aud_context_p->audio_mode;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Set output path */
    aud_get_active_device_path_by_mode(msg_p->output_path, aud_fmr_set_output_device);

#ifndef __GAIN_TABLE_SUPPORT__
    /* Set output volume, App must call set volume function before turn on FM Radio */
    /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
    if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
        aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
    {
        volume_type = VOL_NORMAL;
    }
#if defined(TV_OUT_SUPPORT)
    /* TV out is on, and audio output to TV only */
    else if (audio_tv_cable_in  &&
            !audio_tv_loud_speaker &&
            aud_context_p->melody_output_device != AUDIO_DEVICE_SPEAKER_BOTH)
    {
        volume_type = VOL_TV_OUT;
    }
#endif /* TV_OUT_SUPPORT */

    aud_fmr_set_volume_by_mode(volume_type, current_playing_melody_volume_level);
    //aud_fmr_set_volume_by_mode(volume_type, current_playing_fmradio_volume_level);

#endif /* __GAIN_TABLE_SUPPORT__ */

#if defined(__MED_BT_A2DP_MOD__) && defined(__FMRADIO_I2S_SUPPORT__)
    aud_bt_a2dp_open_codec(MEDIA_FORMAT_UNKNOWN);
#endif

    FMR_PowerOn();

#ifdef __MED_BT_FM_VIA_SCO__
    /* Update BT SCO mode */
    aud_bt_hfp_set_sco_mode(AUD_BT_HFP_MODE_FM_VIA_BT_SCO);
#endif /*__MED_BT_FM_VIA_SCO__*/

#endif /* __MED_FMR_MOD__ */

    aud_set_event(AUD_EVT_FMR_ON);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_power_off_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_power_off_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FM_RADIO_RDS_SUPPORT__
    g_fmr_rds_cntxt.allow_switch = KAL_FALSE;
#endif

    FMR_PowerOff();

#ifdef __MED_BT_FM_VIA_SCO__
    /* Reset BT SCO mode */
    aud_bt_hfp_reset_sco_mode(AUD_BT_HFP_MODE_FM_VIA_BT_SCO);
#endif /*__MED_BT_FM_VIA_SCO__*/

#endif /* __MED_FMR_MOD__ */

    aud_set_event(AUD_EVT_FMR_OFF);
}


#ifdef __FM_RADIO_RDS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_callback
 * DESCRIPTION
 *  Event handler for RDS events
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_fmr_rds_callback(RdsEvent event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_rds_callback_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_fmr_rds_callback_ind_struct*) 
                construct_local_para(sizeof(media_fmr_rds_callback_ind_struct), TD_CTRL);

    ind_p->event = event;   
    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_FMR_RDS_CALLBACK_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_poll_rds_event_rds_hdlr
 * DESCRIPTION
 *  Event handler for RDS events
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_rds_poll_rds_event_rds_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (counter = 0; counter < 16; counter++)
    {
        if (g_fmr_rds_cntxt.rds_log & bit_map_masks[counter])
        {
            g_fmr_rds_cntxt.rds_log = g_fmr_rds_cntxt.rds_log & (~bit_map_masks[counter]);
            aud_fmr_rds_callback((RdsEvent)bit_map_masks[counter]);
            g_resend_log = KAL_TRUE;
            aud_set_result_and_event((kal_int32)MED_RES_OK,AUD_EVT_WAIT);
            return;
        }
    }

    aud_set_result_and_event((kal_int32)MED_RES_FAIL,AUD_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_callback_ind_hdlr
 * DESCRIPTION
 *  Event handler for RDS events
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_rds_callback_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *rds_data_buf = (kal_uint16 *)g_fmr_rds_cntxt.data;
    kal_uint8 rds_data_len = 0; /* 2Bytes per unit */
    RdsFlag flag = 0;
    media_fmr_rds_callback_ind_struct *msg_p = (media_fmr_rds_callback_ind_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(rds_data_buf, 0, sizeof(kal_uint16) * FM_RDS_MAX_DATA_BUFF_SIZE);
    
#ifdef __MTK_TARGET__
    switch(msg_p->event)
    {
        case RDS_EVENT_FLAGS:
            FMR_RDS_GetStatus(&flag, rds_data_buf);
            break;
        case RDS_EVENT_PI_CODE:
            FMR_RDS_GetInfo(RDS_CMD_PI_CODE, rds_data_buf, &rds_data_len);
            break;
        case RDS_EVENT_PTY_CODE:
            FMR_RDS_GetInfo(RDS_CMD_PTY_CODE, rds_data_buf, &rds_data_len);
            break;
        case RDS_EVENT_PROGRAMNAME:
            if (g_fmr_rds_cntxt.PS_Data)
            {
                FMR_RDS_GetInfo(RDS_CMD_PROGRAMNAME, g_fmr_rds_cntxt.PS_Data, &rds_data_len);
				g_fmr_rds_cntxt.PS_Data[rds_data_len] = '\0';
                memcpy(rds_data_buf, g_fmr_rds_cntxt.PS_Data, sizeof(kal_uint16) * rds_data_len);
            }
            else
            {
                FMR_RDS_GetInfo(RDS_CMD_PROGRAMNAME, rds_data_buf, &rds_data_len);
                rds_data_buf[rds_data_len] = '\0';
            }
            break;
        case RDS_EVENT_UTCDATETIME:
            FMR_RDS_GetInfo(RDS_CMD_UTCDATETIME, rds_data_buf, &rds_data_len);			
            break;
        case RDS_EVENT_LOCDATETIME:
            FMR_RDS_GetInfo(RDS_CMD_LOCDATETIME, rds_data_buf, &rds_data_len);			
            break;
        case RDS_EVENT_LAST_RADIOTEXT:
            if (g_fmr_rds_cntxt.RT_Data)
            {
                FMR_RDS_GetInfo(RDS_CMD_LAST_RADIOTEXT, g_fmr_rds_cntxt.RT_Data, &rds_data_len);
                
				if (rds_data_len > FM_RDS_MAX_DATA_BUFF_SIZE)
				{
					ASSERT(0);
				}
                
				g_fmr_rds_cntxt.RT_Data[rds_data_len] = '\0';
                memcpy(rds_data_buf, g_fmr_rds_cntxt.RT_Data, sizeof(kal_uint16) * rds_data_len);
            }
            else
            {
                FMR_RDS_GetInfo(RDS_CMD_LAST_RADIOTEXT, rds_data_buf, &rds_data_len);
                
                if (rds_data_len > FM_RDS_MAX_DATA_BUFF_SIZE)
				{
					ASSERT(0);
				}
                
                rds_data_buf[rds_data_len] = '\0';
            }
            break;
        case RDS_EVENT_AF:
            if (g_fmr_rds_cntxt.AF_Data)
            {
                FMR_RDS_GetInfo(RDS_CMD_AF, g_fmr_rds_cntxt.AF_Data, &rds_data_len);
            }
            else
            {
                FMR_RDS_GetInfo(RDS_CMD_AF, rds_data_buf, &rds_data_len);
            }
            break;
        case RDS_EVENT_AF_LIST:
            FMR_RDS_GetInfo(RDS_CMD_AF_LIST, rds_data_buf, &rds_data_len);
            break;
        case RDS_EVENT_AFON_LIST:
            FMR_RDS_GetInfo(RDS_CMD_AF_LIST, rds_data_buf, &rds_data_len);			
            break;
        case RDS_EVENT_TAON:
            if (g_fmr_rds_cntxt.TP_Data)
            {
                FMR_RDS_GetInfo(RDS_CMD_TAON, g_fmr_rds_cntxt.TP_Data, &rds_data_len);
            }
            else
            {
                FMR_RDS_GetInfo(RDS_CMD_TAON, rds_data_buf, &rds_data_len);
            }
            g_fmr_rds_cntxt.state = RDS_STATE_SWITCHED;
            g_fmr_rds_cntxt.allow_switch = KAL_TRUE;
            break;
        case RDS_EVENT_TAON_OFF:
            if (g_fmr_rds_cntxt.state == RDS_STATE_SWITCHED && g_fmr_rds_cntxt.allow_switch)
            {
                FMR_RDS_GetInfo(RDS_CMD_TAON_OFF, rds_data_buf, &rds_data_len);
            }
            else
            {
                //TODO: add trace here should not happen
                return;
            }
            break;
        case RDS_EVENT_RDS:
            break;
        case RDS_EVENT_NO_RDS:
            break;
        case RDS_EVENT_RDS_TIMER:
		    FMR_RDS_BlerCheck(NULL);
            break;
        default:
            break;
	
    }
    
#else /* __MTK_TARGET__ */    
    msg_p->event = RDS_EVENT_PROGRAMNAME;
    if (g_fmr_rds_cntxt.freq == 9350)
    {
        memcpy(g_fmr_rds_cntxt.data, L"RDSData", 16);
    }
    else
    {
        g_fmr_rds_cntxt.data[0] = 0;
    }   
    flag = 0;
#endif /* __MTK_TARGET__ */

    if (!g_resend_log && (msg_p->event != RDS_EVENT_RDS && msg_p->event != RDS_EVENT_NO_RDS))
    {
        g_fmr_rds_cntxt.rds_log = g_fmr_rds_cntxt.rds_log | msg_p->event;
        g_resend_log = KAL_FALSE;
    }

    _AUD_MODULE_FMR_TRACE(msg_p->event, flag, rds_data_len);
    
    aud_fmr_rds_send_event_ind(msg_p->event, flag, rds_data_buf, rds_data_len, g_fmr_rds_cntxt.freq);
}
#endif /* __FM_RADIO_RDS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_output_path_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_output_path_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_output_path_req_struct *msg_p = (media_fmr_set_output_path_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_get_active_device_path_by_mode(msg_p->output_path, aud_fmr_set_output_device);
#endif /* __MED_FMR_MOD__ */

    aud_set_event(AUD_EVT_FMR_SET);
}
 
#ifdef INTERNAL_ANTENNAL_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_freq_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_antenna_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_antenna_req_struct *msg_p = (media_fmr_set_antenna_req_struct*) ilm_ptr->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMR_SetAntennaType(msg_p->is_short_antenna);
#endif /* __MED_FMR_MOD__ */

    aud_set_event(AUD_EVT_FMR_SET);
}
#endif/* #ifdef INTERNAL_ANTENNAL_SUPPORT*/

/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_freq_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_freq_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_freq_req_struct *msg_p = (media_fmr_set_freq_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Temporarily disable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_disable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */

    FMR_SetFreq(msg_p->freq);

#ifdef __FM_RADIO_RDS_SUPPORT__
	g_fmr_rds_cntxt.freq = msg_p->freq;

    /* Re-enable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_enable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */

#endif /* __MED_FMR_MOD__ */

    aud_set_event(AUD_EVT_FMR_SET);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_mute_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_mute_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_mute_req_struct *msg_p = (media_fmr_mute_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->audio_mute = (kal_bool)msg_p->mute;

    FMR_Mute(msg_p->mute);

#if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
    BT_MuteSpeaker((kal_bool)msg_p->mute);
#endif

#endif /* __MED_FMR_MOD__ */

    aud_set_event(AUD_EVT_FMR_MUTE);
}

#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  aud_fmr_seek_callback_ind_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_seek_callback_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    FMR_PollHWSearch(NULL);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_seek_process_callback_ind_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_seek_process_callback_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_fmr_seek_callback_ind_struct *msg_p = (media_fmr_seek_callback_ind_struct*) ilm_ptr->local_para_ptr;

    aud_send_fmr_seek_result_ind(msg_p->stop_freq, msg_p->signal_level, msg_p->is_valid);
    aud_fmr_seek_confirm = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_seek_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_seek_callback(kal_int16 freq, kal_uint8 signal_level, kal_bool is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_seek_callback_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (media_fmr_seek_callback_ind_struct*) 
                construct_local_para(sizeof(media_fmr_seek_callback_ind_struct), TD_CTRL);

    ind_p->stop_freq = freq;
    ind_p->signal_level = signal_level;
    ind_p->is_valid = is_valid;

    if (freq == 0)
    {
        aud_send_fmr_seek_continue(MOD_MED, ind_p);
    }
    else
    {
        if (is_valid)
        {
        #ifdef __FM_RADIO_RDS_SUPPORT__
            /* Re-enable RDS */
            if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
            {
                aud_fmr_rds_enable();
            }
        #endif /* __FM_RADIO_RDS_SUPPORT__ */
        
            aud_send_ilm(MOD_MED, MSG_ID_MEDIA_FMR_SEEK_CALLBACK_IND, ind_p, NULL);
        }
        else
        {
            if (seek_counter < 2 && !aud_fmr_search.is_preset)
            {
                if (freq == FM_RADIO_MIN_FREQ && !aud_fmr_search.is_step_up)
                {
                    freq = FM_RADIO_MAX_FREQ;
                }
                else if (freq == FM_RADIO_MAX_FREQ && aud_fmr_search.is_step_up)
                {
                    freq = FM_RADIO_MIN_FREQ;
                }
                seek_counter++;
            #ifdef __MTK_TARGET__
                FMR_HWSearch(aud_fmr_seek_callback,
                    freq,
                    aud_fmr_search.is_step_up,
                    aud_fmr_search.seek_space,
                    aud_fmr_search.is_preset);
            #if !defined(FM_INTERFACE_HCI)
                aud_send_ilm(MOD_FMR, MSG_ID_FMR_HWSEARCH_IND, NULL, NULL);
            #endif /* FM_INTERFACE_HCI */
            #endif /* __MTK_TARGET__ */

                /* Remember to free local para to avoid leakage */
                free_local_para((local_para_struct*)ind_p);
            }
            else
            {
            #ifdef __FM_RADIO_RDS_SUPPORT__
                /* Re-enable RDS */
                if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
                {
                    aud_fmr_rds_enable();
                }
            #endif /* __FM_RADIO_RDS_SUPPORT__ */
            
                aud_send_ilm(MOD_MED, MSG_ID_MEDIA_FMR_SEEK_CALLBACK_IND, ind_p, NULL);
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_seek_start_req_hdlr
 * DESCRIPTION
 *  start fm radio hardware auto search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_seek_start_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MED_FMR_MOD__
    media_fmr_seek_start_req_struct *msg_p = (media_fmr_seek_start_req_struct*) ilm_ptr->local_para_ptr;
    kal_int16 seek_space = 1; /* 0:200KHz, 1:100KHz */

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    if(msg_p->space == 200)
    {
        seek_space = 0;
    }
    aud_fmr_search.is_step_up = msg_p->is_step_up;
    aud_fmr_search.seek_space = seek_space;
    aud_fmr_search.is_preset = msg_p->is_preset;
    seek_counter = 0;

#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Temporarily disable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_disable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */

#ifdef __MTK_TARGET__
    ret = FMR_HWSearch(aud_fmr_seek_callback, (kal_int16)msg_p->start_freq, msg_p->is_step_up, seek_space, msg_p->is_preset);
#if !defined(FM_INTERFACE_HCI)
    if (ret)
    {
        aud_send_ilm(MOD_FMR, MSG_ID_FMR_HWSEARCH_IND, NULL, NULL);
    }
#endif /* FM_INTERFACE_HCI */

#else /* MoDIS */
    if(msg_p->is_step_up)
    {
        if(msg_p->is_preset && ((msg_p->start_freq + 6) > FM_RADIO_MAX_FREQ))
        {
            aud_fmr_seek_callback(FM_RADIO_MAX_FREQ, 1, KAL_FALSE);
        }
        else
        {
            aud_fmr_seek_callback((kal_int16)((msg_p->start_freq + 6) > FM_RADIO_MAX_FREQ ? FM_RADIO_MIN_FREQ : msg_p->start_freq + 6), 1, KAL_TRUE);
        }
    }
    else
    {
        aud_fmr_seek_callback((kal_int16)((msg_p->start_freq - 10) < FM_RADIO_MIN_FREQ ? FM_RADIO_MAX_FREQ : msg_p->start_freq - 10), 1, KAL_TRUE);
    }
#endif /* __MTK_TARGET__ */

    aud_fmr_seek_confirm = KAL_FALSE;

#endif /* __MED_FMR_MOD__ */
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_seek_abort_req_hdlr
 * DESCRIPTION
 *  abort FM hardware auto search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_seek_abort_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_FMR_MOD__) && defined(__MTK_TARGET__)
    if (!aud_fmr_seek_confirm)
    {
        FMR_HWSearchForceStop();
    }

#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Re-enable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_enable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */

#endif /* __MED_FMR_MOD__ && __MTK_TARGET__ */
}

#else /* FM_RADIO_HW_SEARCH */

/*****************************************************************************
 * FUNCTION
 *  aud_fmr_check_is_valid_stop_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_check_is_valid_stop_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_check_is_valid_stop_req_struct *msg_p =
        (media_fmr_check_is_valid_stop_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Temporarily disable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_disable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */

    result = FMR_ValidStop(msg_p->freq, (signed char)FM_RADIO_INPUT_LEVEL_THRESHOLD, msg_p->is_step_up);

#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Re-enable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_enable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */

    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_send_fmr_check_is_valid_stop_cnf(result);
    
#else /* __MED_FMR_MOD__ */

    aud_send_fmr_check_is_valid_stop_cnf(1);

#endif /* __MED_FMR_MOD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_get_signal_level_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_get_signal_level_req_hdlr(ilm_struct *ilm_ptr)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_get_signal_level_req_struct *msg_p = (media_fmr_get_signal_level_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Temporarily disable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_disable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */

    if (FMR_ValidStop(msg_p->freq, (signed char)FM_RADIO_INPUT_LEVEL_THRESHOLD, msg_p->is_step_up))
    {
        result = FMR_GetSignalLevel(msg_p->freq) + 1;
        MED_ASSERT(result != 0);    /* when it's 0, that means the result is overflow */
    }
    else
    {
        result = 0;
    }

#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Re-enable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_enable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */
    
    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    aud_send_fmr_get_signal_level_cnf(result);
    
#else /* __MED_FMR_MOD__ */

    aud_send_fmr_get_signal_level_cnf(5);

#endif /* __MED_FMR_MOD__ */
}
#endif /* __FM_RADIO_HW_SEARCH__ */


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_output_volume
 * DESCRIPTION
 *  This function sets the volume of FMR.
 * PARAMETERS
 *  volume                  [IN]     Analog gain.
 *  digital_gain_index      [IN]     Digital gain.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_output_volume(kal_uint8 volume, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_FMR, volume, digital_gain_index);
    FMR_SetOutputVolume(volume, digital_gain_index);

    if (volume == 0)
    {
        aud_audio_mute_digital_gain(KAL_TRUE, AUD_DIGITAL_GAIN_AUDIO);
    }
    else
    {
        aud_audio_mute_digital_gain(KAL_FALSE, AUD_DIGITAL_GAIN_AUDIO);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_volume_by_mode
 * DESCRIPTION
 *  This function sets the volume of FMR for a given audio mode.
 * PARAMETERS
 *  mode      [IN]      Audio mode.
 *  level     [IN]      Volume level.
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_volume_by_mode(kal_uint8 mode, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 new_level;
    kal_uint8 analog_gain;
#ifndef __FMRADIO_I2S_SUPPORT__
    kal_uint8 volume_level = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    _AUD_MODULE_FMR_TRACE(mode, level, -1);

    /* If the second bit(from MSB) is set, the level 0 means mute. */
    if (AUD_VOL_IS_MUTE(level))
    {
        aud_fmr_set_output_volume(0, 0);
        return;
    }

    if (AUD_VOL_IS_MUTE_AT_LEVEL_0(level))
    {
        new_level = AUD_VOL_GET_VOLUME_LEVEL(level) - 1;
    }
    else
    {
        new_level = AUD_VOL_GET_VOLUME_LEVEL(level);
    }

    /* 7 level volume (MSB bit is not set) */
    if (AUD_VOL_IS_7_LEVEL_VOLUME(level))
    {
#if defined(TV_OUT_SUPPORT)
        if (mode == VOL_TV_OUT)
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_TVO, new_level);
        }
        else
#endif /* TV_OUT_SUPPORT */
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_FMR, new_level);
        }

        aud_fmr_set_output_volume(analog_gain, 0);

    #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
        BT_SetLevelVolume(new_level+1,7);
    #endif


    }
    /* 16 level volume */
    else
    {
#ifdef __16_LEVEL_AUDIO_VOLUME__

        /* Un-mute digital gain in case it is turn off by set mute function */
        aud_audio_mute_digital_gain(KAL_FALSE, AUD_DIGITAL_GAIN_AUDIO);

    #if defined(__FMRADIO_I2S_SUPPORT__)
        /* Use level volume adjustment */
        if (new_level < aud_context_p->melody_max_volume_level)
        {
             Media_SetLevelVolume(aud_context_p->acoustic_data.max_melody_volume_gain[mode],
                aud_context_p->acoustic_data.melody_volume_gain_step[mode],
                aud_context_p->melody_max_volume_level - 1 - new_level);
            #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
                BT_SetLevelVolume(new_level+1,aud_context_p->melody_max_volume_level);
            #endif
        }
    #else
        /* Remapping to 7-level volume */
        switch (new_level)
        {
            case 0:
                volume_level = 0;
                break;
            case 1: case 2: case 3:
                volume_level = 1;
                break;
            case 4: case 5: case 6:
                volume_level = 2;
                break;
            case 7: case 8: case 9:
                volume_level = 3;
                break;
            case 10: case 11: case 12:
                volume_level = 4;
                break;
            case 13: case 14:            
                volume_level = 5;
                break;
            case 15:
                volume_level = 6;
                break;
            default:
                ASSERT(0);
        }

    #if defined(TV_OUT_SUPPORT)
        if (mode == VOL_TV_OUT)
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_TVO, volume_level);
        }
        else
    #endif /* TV_OUT_SUPPORT */
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_FMR, volume_level);
        }
    
        aud_fmr_set_output_volume(analog_gain, 0);

    #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
        BT_SetLevelVolume(volume_level,7);
    #endif
        
    #endif /* __FMRADIO_I2S_SUPPORT__ */
#else
        ASSERT(0);
#endif /* __16_LEVEL_AUDIO_VOLUME__ */
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_active_fmr_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_active_fmr_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* incoming call ring, alarm, message use the same volume */
    kal_uint8 gain_audio_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __GAIN_TABLE_SUPPORT__
    /* store playing melody volume level */
    current_playing_melody_volume_level = aud_get_volume_level(aud_context_p->audio_mode, AUD_VOLUME_FMR);
    /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
    if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
        aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
    {
        gain_audio_mode = VOL_NORMAL;
    }
    else
    {
        gain_audio_mode = aud_context_p->audio_mode;
    }

    aud_fmr_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);

#else /* #ifdef __GAIN_TABLE_SUPPORT__ */
    kal_uint64 volume;

    volume = aud_context_p->volume_tbl[AUD_VOLUME_FMR];
    aud_volume_set_fmr_volume(volume);
#endif /* __GAIN_TABLE_SUPPORT__ */

    /* disable audio mute when the volume is set again */
    aud_context_p->audio_mute = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_output_device(kal_uint8 device)
{
#ifdef __MED_FMR_MOD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_FMR, device);//, -1);
    FMR_SetOutputDevice(device);
#endif /* __MED_FMR_MOD__ */
}

/*****************************************************************************
 * FUNCTION
 *  aud_fmr_set_channel_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_set_channel_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_FMR_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_set_channel_req_struct *msg_p = (media_fmr_set_channel_req_struct*) ilm_ptr->local_para_ptr;
    kal_uint32 item_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(msg_p->is_mono)
    {
        item_value = 1;
    }

    FMR_Radio_EngineerMode(0,0,item_value); /*Turn on Mono*/

#endif /* __MED_FMR_MOD__ */

    aud_set_event(AUD_EVT_FMR_SET_CHANNEL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_is_power_on
 * DESCRIPTION
 *  check if FM radio is currently power on
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_fmr_is_power_on(void)
{
#if defined(__MED_FMR_MOD__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    return FMR_IsActive();
#else 
    return KAL_TRUE;
#endif /* __MTK_TARGET__ */

#else /* __MED_FMR_MOD__ */

    return KAL_FALSE;

#endif /* __MED_FMR_MOD__ */
}

#ifdef __FM_RADIO_RDS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_init 
 * DESCRIPTION
 *  initialize FM RDS context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_rds_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmr_rds_cntxt.state = RDS_STATE_DISABLE;
    g_fmr_rds_cntxt.allow_switch = KAL_TRUE;
    g_fmr_rds_cntxt.data[0] = '\0';
    g_fmr_rds_cntxt.rds_log = 0;
    g_fmr_rds_cntxt.RT_Data = NULL;
    g_fmr_rds_cntxt.PS_Data = NULL;
    g_fmr_rds_cntxt.AF_Data = NULL;
    g_fmr_rds_cntxt.TP_Data = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_enable
 * DESCRIPTION
 *  This function is to enable RDS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_fmr_rds_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    g_fmr_rds_cntxt.rds_log = 0;
    g_fmr_rds_cntxt.allow_switch = KAL_FALSE;
    
    FMR_RDS_OnOff(KAL_TRUE);
    FMR_RDS_Open(aud_fmr_rds_callback);
#else
	aud_fmr_rds_callback(8);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_disable
 * DESCRIPTION
 *  This function is to disable RDS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_fmr_rds_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    FMR_RDS_OnOff(KAL_FALSE);
#endif  
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_enable_req_hdlr
 * DESCRIPTION
 *  Enable FM RDS
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_rds_enable_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_rds_enable_req_struct *msg_p = (media_fmr_rds_enable_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!aud_fmr_is_power_on())
    {
        aud_set_result_and_event((kal_int32)MED_RES_FAIL,AUD_EVT_WAIT);
        return;
    }

    if (g_fmr_rds_cntxt.state == RDS_STATE_DISABLE)
    {
        aud_fmr_rds_enable();
        g_fmr_rds_cntxt.state = RDS_STATE_ENABLE;
    }
    if(msg_p->af)
    {
        FMR_RDS_EnableAF(KAL_TRUE);
    }
    else
    {
        FMR_RDS_EnableAF(KAL_FALSE);
    }

    if(msg_p->ta)
    {
        FMR_RDS_EnableTP(KAL_TRUE);
    }
    else
    {
        FMR_RDS_EnableTP(KAL_FALSE);
    }

    aud_set_event(AUD_EVT_WAIT);
}

/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_disable_req_hdlr
 * DESCRIPTION
 *  Disable FM RDS events
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_rds_disable_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_fmr_rds_disable();
    g_fmr_rds_cntxt.state = RDS_STATE_DISABLE;
    aud_set_event(AUD_EVT_WAIT);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_set_buffer
 * DESCRIPTION
 *  Need to resolve buffer handling conflict
 * PARAMETERS
 *  RT_Data     [IN]     
 *  PS_Data     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_rds_set_buffer(kal_uint16 *RT_Data, kal_uint16 *PS_Data, kal_uint16 *AF_Data, kal_uint16 *TP_Data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmr_rds_cntxt.PS_Data = (kal_uint16*)PS_Data;
    g_fmr_rds_cntxt.RT_Data = (kal_uint16*)RT_Data;
    g_fmr_rds_cntxt.AF_Data = (kal_uint16*)AF_Data;
    g_fmr_rds_cntxt.TP_Data = (kal_uint16*)TP_Data;
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_reset_buffer
 * DESCRIPTION
 *  Need to resolve buffer handling conflict
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_rds_reset_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmr_rds_cntxt.PS_Data = NULL;
    g_fmr_rds_cntxt.RT_Data = NULL;
    g_fmr_rds_cntxt.AF_Data = NULL;
    g_fmr_rds_cntxt.TP_Data = NULL;
}

#endif /* __FM_RADIO_RDS_SUPPORT__ */ 


#ifdef __FM_RADIO_HW_SCAN__
/*****************************************************************************
 * FUNCTION
 *  aud_fmr_hw_scan_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_hw_scan_callback(kal_int16 freq, kal_uint8 signal_level, kal_bool is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_hw_scan_result_struct *ind_p = (media_fmr_hw_scan_result_struct*)
        construct_local_para(sizeof(media_fmr_hw_scan_result_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p->stop_freq = freq;
    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_FMR_HW_SCAN_CALLBACK_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_hw_scan_callback_ind_hdlr
 * DESCRIPTION
 *  Send scan complete indication to HW
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_hw_scan_callback_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 bit_map_tbl[16], offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_scan_table)
    {
        return;
    }
#ifdef __MTK_TARGET__
    if (!FMR_GetScanTbl(bit_map_tbl))
    {
        return;
    }
#endif 
    /* offset max value: (MAX_FM_FREQ - MIN_FM_FREQ) * 100 / seek_step */
    for (offset = 0; offset < 206; offset++)
    {
        if (bit_map_tbl[offset / 16] & bit_map_masks[offset % 16])
        {
            /* Maybe signal level can be returned */
            g_scan_table[offset] = KAL_TRUE;

            _AUD_MODULE_FMR_TRACE(bit_map_tbl[offset / 16], bit_map_masks[offset % 16], offset);
        }
    }
    g_scan_table = NULL;
    aud_fmr_scan_confirm = KAL_TRUE;

#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Re-enable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_enable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */
    
    aud_send_ilm(MOD_MMI, MSG_ID_MEDIA_FMR_HW_SCAN_FINISH_IND, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_hw_scan_req_hdlr
 * DESCRIPTION
 *  Start HW Scan (MT6616)
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_hw_scan_req_hdlr(ilm_struct *ilm_ptr)
{
#if defined(__MED_FMR_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_hw_scan_req_struct *msg_p = (media_fmr_hw_scan_req_struct*) ilm_ptr->local_para_ptr;
    kal_int16 seek_space = 1; /* 0:200KHz, 1:100KHz */
    kal_bool ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    aud_context_p->src_mod = ilm_ptr->src_mod_id;
    g_scan_table = msg_p->scan_table;

#ifdef __MTK_TARGET__

#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Temporarily disable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_disable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */    

    ret = FMR_HWSearch(aud_fmr_hw_scan_callback, FM_RADIO_MIN_FREQ, KAL_TRUE, seek_space, KAL_TRUE);
#if !defined(FM_INTERFACE_HCI)
    if (ret)
    {
        aud_send_ilm(MOD_FMR, MSG_ID_FMR_HWSEARCH_IND, NULL, NULL);
    }
#endif /* FM_INTERFACE_HCI */

#else /* MoDIS */
    aud_send_ilm(MOD_MMI, MSG_ID_MEDIA_FMR_HW_SCAN_FINISH_IND, NULL, NULL);
#endif /* __MTK_TARGET__ */

    aud_fmr_scan_confirm = KAL_FALSE;
#endif /* __MED_FMR_MOD__ */
}


/*****************************************************************************
 * FUNCTION
 *  aud_fmr_rds_disable_req_hdlr
 * DESCRIPTION
 *  Disable FM RDS events
 * PARAMETERS
 *  ilm_ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_fmr_hw_scan_abort_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MED_FMR_MOD__) && defined(__MTK_TARGET__)
    g_scan_table = NULL;
    if (!aud_fmr_scan_confirm)
    {
        FMR_HWSearchForceStop();
    }

#ifdef __FM_RADIO_RDS_SUPPORT__
    /* Re-enable RDS */
    if (g_fmr_rds_cntxt.state != RDS_STATE_DISABLE)
    {
        aud_fmr_rds_enable();
    }
#endif /* __FM_RADIO_RDS_SUPPORT__ */

#endif /* __MED_FMR_MOD__ && __MTK_TARGET__ */
}
#endif /* __FM_RADIO_HW_SCAN__ */ 

#endif /* MED_NOT_PRESENT */ 

