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
 * SndrecMsg.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h" 

#if defined(__MMI_SOUND_RECORDER__)

#include "mdi_datatype.h"
#include "Mdi_audio.h"
#include "aud_defs.h"
#include "UcmSrvGprot.h"
#include "L1audio.h"
#ifdef __MMI_FTE_SUPPORT__
#include "gui_touch_feedback.h"
#endif

#include "SndrecDef.h"
#include "SndrecProt.h"
#ifdef __CTM_SUPPORT__
#include "CallSetSrvGprot.h"
#endif 

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#include "Drm_def.h"
#define DRM_NOT_PERMIT_TO_PLAY   9999
#define DRM_NOT_PERMIT_TO_APPEND 10000
#endif /* __DRM_SUPPORT__ */ 

#include "MMIDataType.h"
#include "AlertScreen.h"
#include "mmi_rp_app_soundrecorder_def.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "stack_config.h"
#include "gui.h"
#include "FileMgrResDef.h"
#include "mmi_frm_input_gprot.h"

#include "GpioSrvGProt.h"
#include "gui_data_types.h"
#include "device.h"
#include "fs_func.h"
#include "SoundRecSrvGProt.h"

/* For DCM */
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "mmi_ap_dcm_config.h"
#endif

#ifndef __MMI_SNDREC_SKIN__
static void mmi_sndrec_init_ticks(void);
#endif
#ifdef __MMI_SNDREC_SKIN__
static U64 mmi_sndrec_get_remain_time(void);
#endif

/****************************************************************************
* Global Variable
*****************************************************************************/
#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata = "DYNAMIC_CODE_SNDREC_RODATA",code = "DYNAMIC_CODE_SNDREC_ROCODE"
#endif

extern mmi_sndrec_cntx g_sndrec_cntx;

U32 g_total_time = 0;
#if defined(__MMI_OP02_LEMEI__)
U32 g_oth_app_remaining_time;
U32 g_oth_app_size_limit;
U32 g_oth_app_time_limit;
MMI_BOOL g_sndrec_show_app_recording_time_left = MMI_FALSE;
MMI_BOOL g_sndrec_disable_recording_pause = MMI_TRUE;
#endif

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
void (*play_end_cb) (MDI_RESULT result);
extern void (*mmi_sndrec_sms_record_callback) (BOOL result, U16 *filepath);
extern U32 g_size_limit;
extern U32 g_time_limit;
MMI_BOOL g_sndrec_suspend = MMI_FALSE;

/****************************************************************************
* Function Body
*****************************************************************************/

#define __SNDREC_MSG_REC__

#if defined(__MMI_OP02_LEMEI__)
void mmi_sndrec_set_app_record_time_limit(U32 time_limit)
{
    g_time_limit = time_limit;   
    g_oth_app_time_limit = time_limit;      
}

void mmi_sndrec_set_app_record_size_limit(U32 size_limit)
{
    g_oth_app_size_limit = size_limit;
    g_size_limit = size_limit;
}


void mmi_sndrec_enable_app_recording_time_left(void)
{
     g_sndrec_show_app_recording_time_left = MMI_TRUE;
}

void mmi_sndrec_disable_app_recording_time_left(void)
{
    g_sndrec_show_app_recording_time_left = MMI_FALSE;
}    


MMI_BOOL mmi_sndrec_query_is_record_pause_enabled(void) 
{
    return g_sndrec_disable_recording_pause; 
}

void mmi_sndrec_enable_record_pause(void) 
{
     g_sndrec_disable_recording_pause = MMI_TRUE; 
}

void mmi_sndrec_disable_record_pause(void) 
{
     g_sndrec_disable_recording_pause = MMI_FALSE; 
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_record_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [IN]        
 *  format      [IN]        
 *  quality     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sndrec_send_record_req(U16 *file, U8 format, U8 quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL speech_on = mdi_audio_is_speech_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_SEND_REC_REQ, format, quality);

    return mmi_sndrec_send_record_limit_req(
            file,
            format,
            quality,
            g_size_limit,
            (g_time_limit - (g_total_time / 1000)),
            0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_record_limit_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file            [IN]        
 *  format          [IN]        
 *  quality         [IN]        
 *  size_limit      [IN]        
 *  time_limit      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sndrec_send_record_limit_req(U16 *file, U8 format, U8 quality, U32 size_limit, U32 time_limit, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    BOOL speech_on = mdi_audio_is_speech_mode();

    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];
    mdi_audio_rec_param_struct rec_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!flag)
    {
        mmi_sndrec_get_full_file_name(file_path_name,file);
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)file_path_name, (CHAR*)file, MMI_SNDREC_FULL_NAME_LEN);
    }
    
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 && speech_on == FALSE)
    {
        mmi_popup_display_simple_ext(
            STR_ID_SNDREC_SPEECH_OFF,
            MMI_EVENT_WARNING,
            GRP_ID_ROOT,
            NULL);
        return MMI_FALSE;
    }
#ifdef __DRM_SUPPORT__
    {
        FS_HANDLE handle;
        BOOL is_permitted = FALSE;

        if ((handle = DRM_open_file((PU16) file_path_name, FS_READ_ONLY, DRM_PERMISSION_NONE)) >= FS_NO_ERROR)
        {
            if (DRM_get_object_method(handle, NULL) == DRM_METHOD_NONE)
            {
                is_permitted = TRUE;
            }
            DRM_close_file(handle);
        }
        else if (handle < -1)   /* file open error. but not DRM related problem */
        {
            is_permitted = TRUE;
        }

        if (!is_permitted)
        {
            mdi_audio_stop_all();
            mmi_sndrec_error_hdlr(DRM_NOT_PERMIT_TO_APPEND, MMI_TRUE);
            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
            return MMI_FALSE;
        }
    }
#endif /* __DRM_SUPPORT__ */ 
    if(MEDIA_FORMAT_NONE == (MDI_FORMAT_ENUM)format)
    {
        mdi_audio_get_record_param(mmi_sndrec_get_rec_type(), (MDI_AUDIO_REC_QUALITY_ENUM)quality, &rec_param);
    }
    else
    {
        rec_param.format = (MDI_FORMAT_ENUM)format;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_SEND_REC_LIMIT_REQ, rec_param.format, quality);

    /* just before record, check if record begin in call or not */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        g_sndrec_cntx.record.isIncall = MMI_TRUE;
    }
    else
    {
        g_sndrec_cntx.record.isIncall = MMI_FALSE;
    }
    MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.isIncall);
#ifdef __CTM_SUPPORT__
    if (srv_callset_ctm_get_mode() == MMI_TRUE && g_sndrec_cntx.record.isIncall)
    {

        mmi_popup_display_simple_ext(
            STR_ID_SNDREC_NOT_ALLOWED_IN_CTM_CALL,
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);

        return MMI_FALSE;
    }
#endif /* __CTM_SUPPORT__ */ 

    /* suspend background play before */
    mmi_sndrec_bgsound_suspend();
#ifdef __MMI_FTE_SUPPORT__
    if(gui_touch_feedback_get_tone_state() == MMI_TRUE)
    {
        gui_touch_feedback_disable_tone();
    }
    if(gui_touch_feedback_get_vibrate_state() == MMI_TRUE)
    {
        gui_touch_feedback_disable_vibrate();
    }
#endif

    /* Wrap the checking of remain size with __MMI_SNDREC_SKIN__ macro for SLIM */
#ifdef __MMI_SNDREC_SKIN__
    if (mmi_sndrec_get_remain_time() == 0)
    {
        result = MDI_AUDIO_DISC_FULL;
    }
    else
#endif
    {
        result = mdi_audio_start_record_with_limit(
            file_path_name,
            (U8)rec_param.format,
            MDI_AUDIO_REC_QUALITY_AUTO,
            (mdi_ext_callback)mmi_sndrec_record_cb_hdlr,
            NULL,
            size_limit,
            time_limit);
    }
    if (MDI_AUDIO_SUCCESS == result)
    {
        g_sndrec_cntx.record.state = MMI_SNDREC_REC_STATE;
        mmi_sndrec_init_time();
        MMI_SNDREC_MSG_TRACE(result);
        mmi_frm_start_scenario(MMI_SCENARIO_ID_SND_REC);
        return MMI_TRUE;
    }
    else
    {
    #ifdef __MMI_FTE_SUPPORT__
        gui_touch_feedback_enable_tone();
        gui_touch_feedback_enable_vibrate();	
    #endif
        MMI_SNDREC_ERR_TRACE(result);
        mmi_sndrec_error_hdlr(result, MMI_TRUE);
        g_sndrec_cntx.record.isIncall = MMI_FALSE;
        mmi_sndrec_is_file_exist();
        g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_record_cb_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_record_cb_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_REC_CALLBACK, g_sndrec_cntx.record.state, result);
#ifdef __MMI_SNDREC_SKIN__
    gui_cancel_timer(mmi_sndrec_update_time_text);
#endif 
    #ifdef __MMI_FTE_SUPPORT__
    gui_touch_feedback_enable_tone();
    gui_touch_feedback_enable_vibrate();
    #endif	
    
    if (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE)
    {

        mmi_sndrec_increase_rectime();
        g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
        switch (result)
        {
            case MDI_AUDIO_TERMINATED:
                /* g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE; */
            #ifndef __MMI_SNDREC_SLIM__
                if (g_sndrec_cntx.record.isappend)
                {
                    mmi_sndrec_append_stop_hdlr();
                }
                else
            #endif
                {
                    mmi_sndrec_record_stop_hdlr();
                }
                
		#ifdef __MMI_FTE_SUPPORT__
		gui_touch_feedback_enable_tone();
		#endif		
                
                break;
            case MDI_AUDIO_SUCCESS:
                mmi_popup_display_simple_ext(
                    STR_ID_SNDREC_SMS_RECORD_TIMEOUT,
                    MMI_EVENT_FAILURE,
                    GRP_ID_SNDREC_MAIN,
                    NULL);
                break;
                
            case MDI_AUDIO_DISC_FULL:
                if ( 
                   #ifndef __MMI_SNDREC_SLIM__
                       !g_sndrec_cntx.record.isappend && 
                   #endif
                       mmi_sndrec_is_file_exist())
                {
                    /* If disc and record stop, should add last record time */
                    /*  mmi_sndrec_increase_rectime(); */
                #ifdef __MMI_SNDREC_SKIN__
                    g_sndrec_cntx.record.rectime = g_total_time;
                    g_sndrec_cntx.record.remindsize = 0;
                #endif /* __MMI_SNDREC_SKIN__ */ 
                    MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.rectime);
                    mmi_popup_display_simple_ext(
                        STR_ID_SNDREC_DISC_FULL,
                        MMI_EVENT_FAILURE,
                        GRP_ID_SNDREC_MAIN,
                        NULL);

                    break;
                }
                else
                {
                    if (mmi_sndrec_is_file_exist())
                    {
                        mmi_sndrec_increase_rectime();
                    }
                    /* do not break! and go to default */
                #ifndef __MMI_SNDREC_SLIM__
                    g_sndrec_cntx.record.isappend = MMI_FALSE;
                #endif
                }
            default:
                mmi_sndrec_error_hdlr(result, MMI_TRUE);
                break;
        }
    }
    else
    {
        mmi_sndrec_cb_for_other_app(MMI_TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_stop_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  isrecord        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_send_stop_req(MMI_BOOL isrecord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_STOP_REQ, g_sndrec_cntx.record.state, isrecord);

    if (isrecord)
    {
    #ifdef __MMI_SNDREC_SKIN__
        if (g_sndrec_cntx.record.is_timer_on)
        {
            MMI_SNDREC_MSG_TRACE(1);
            g_sndrec_cntx.record.is_timer_on = MMI_FALSE;
            gui_cancel_timer(mmi_sndrec_get_drive_size);
        }
    #else /* __MMI_SNDREC_SKIN__ */ 
        mmi_sndrec_update_rec_ticks();
    #endif /* __MMI_SNDREC_SKIN__ */ 
        mdi_audio_stop_record();
	#ifdef __MMI_FTE_SUPPORT__	
	gui_touch_feedback_enable_vibrate();	
	#endif	
    }
    else
    {
        mdi_audio_stop_file();
    }
    g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
    
   #ifdef __MMI_FTE_SUPPORT__	
   gui_touch_feedback_enable_tone();	
   #endif	
    MMI_SNDREC_MSG_TRACE(2);
}

#define __SNDREC_MSG_PAUSE__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_pause_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  endstate        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sndrec_send_pause_req(U16 endstate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    MMI_BOOL ret = MMI_FALSE;
    MMI_BOOL isRecord = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PAUSE_REQ, g_sndrec_cntx.record.state, endstate);

    #if defined(__MMI_OP02_LEMEI__)
    if(mmi_sndrec_query_is_record_pause_enabled() == MMI_FALSE)
    {
        return MMI_FALSE;
    }
    #endif 

    if (g_sndrec_cntx.record.state != MMI_SNDREC_IDLE_STATE)
    {
        /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
        #ifdef __MMI_SNDREC_SKIN__
        if ((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE) ||
            (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) ||
            (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_STATE) ||
            (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_PAUSE_STATE))
        {
            isRecord = MMI_FALSE;
        }
        #endif

        result = mdi_audio_pause(mmi_sndrec_pause_cb_hdlr, NULL);

        if (MDI_AUDIO_SUCCESS == result)
        {
            g_sndrec_cntx.record.state = endstate;
            #ifdef __MMI_FTE_SUPPORT__
            gui_touch_feedback_enable_tone();
            gui_touch_feedback_enable_vibrate();
            #endif			
            ret = MMI_TRUE;
             ClearKeyEvents();
        }
        else if (result == MDI_AUDIO_UNSUPPORTED_OPERATION)
        {
            mmi_sndrec_error_hdlr(MDI_AUDIO_UNSUPPORTED_TYPE, isRecord);
            ret = MMI_FALSE;
        }
        else
        {
            MMI_SNDREC_MSG_TRACE(result);
            
         #ifdef __MMI_FTE_SUPPORT__
            gui_touch_feedback_enable_tone();
         #endif  
            
            ret = MMI_FALSE;
            if (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE && result == MDI_AUDIO_FAIL)
            {

                result = MDI_AUDIO_DISC_FULL;
            }

            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
        
            if ((g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE) && 
            #ifndef __MMI_SNDREC_SLIM__
                (!g_sndrec_cntx.record.isappend) && 
            #endif
                (mmi_sndrec_is_file_exist()))
            {
                mmi_sndrec_record_stop_hdlr();
            }
            else
            {
                /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
                #ifdef __MMI_SNDREC_SKIN__
                if ((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE) ||
                    (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_STATE))
                {
                    result = MDI_AUDIO_END_OF_FILE;
                    ret = MMI_TRUE;
                }
                #endif
                mmi_sndrec_error_hdlr(result, isRecord);
            }
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_pause_cb_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_pause_cb_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL isRecord = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PAUSE_CALLBACK, g_sndrec_cntx.record.state, result);

#ifdef __MMI_SNDREC_SKIN__
    gui_cancel_timer(mmi_sndrec_update_time_text);
#endif 
	#ifdef __MMI_FTE_SUPPORT__
	gui_touch_feedback_enable_tone();
	gui_touch_feedback_enable_vibrate();
	#endif	
    /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
    #ifdef __MMI_SNDREC_SKIN__
    if ((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_PAUSE_STATE))
    {
        isRecord = MMI_FALSE;
    }
    #endif

    if (result == MDI_AUDIO_TERMINATED)
    {
        if ((g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE) ||
            (g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE))
        {

            mmi_sndrec_increase_rectime();
            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
        #ifndef __MMI_SNDREC_SLIM__
            MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.isappend);
            if (g_sndrec_cntx.record.isappend)
            {
                mmi_sndrec_append_stop_hdlr();
            }
            else
        #endif
            {
                mmi_sndrec_record_stop_hdlr();
            }
        }
        /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
        #ifdef __MMI_SNDREC_SKIN__
        else if ((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_PAUSE_STATE))
        {
            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
            play_end_cb(result);
        }
        #endif
    }
    else
    {
        if (g_sndrec_cntx.record.state != MMI_SNDREC_IDLE_STATE)
        {
            isRecord = (MMI_BOOL)((g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE) ||
                             (g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE));

            MMI_SNDREC_MSG_TRACE(isRecord);

            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
            if (isRecord && result == MDI_AUDIO_FAIL)
            {
                result = MDI_AUDIO_DISC_FULL;
            }
            if (isRecord && 
            #ifndef __MMI_SNDREC_SLIM__
                !g_sndrec_cntx.record.isappend && 
            #endif
                mmi_sndrec_is_file_exist())
            {
                mmi_sndrec_record_stop_hdlr();
            }
            else
            {
                mmi_sndrec_error_hdlr(result, isRecord);
            }
        }
    }
}

#define __SNDREC_MSG_RESUME__

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_resume_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  endstate        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sndrec_send_resume_req(U16 endstate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    BOOL speech_on = mdi_audio_is_speech_mode();
    MMI_BOOL ret = MMI_FALSE;
    MMI_BOOL isRecord = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_RESUME_REQ, g_sndrec_cntx.record.state, endstate);

#ifdef __MTK_TARGET__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 && speech_on == FALSE &&
        MMI_SNDREC_REC_STATE == endstate)
    {

        mmi_popup_display_simple_ext(
            STR_ID_SNDREC_SPEECH_OFF,
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);

        return MMI_FALSE;
    }
#endif /* __MTK_TARGET__ */ 

    /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
    #ifdef __MMI_SNDREC_SKIN__
    if ((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_PAUSE_STATE))
    {
        isRecord = MMI_FALSE;
    }
    #endif

#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if (g_sndrec_cntx.record.state != MMI_SNDREC_IDLE_STATE)
#endif
    {
    #ifdef __MMI_FTE_SUPPORT__	
		if(gui_touch_feedback_get_tone_state() == MMI_TRUE)
		{
          gui_touch_feedback_disable_tone();	
		}
		if(gui_touch_feedback_get_vibrate_state() == MMI_TRUE)
		{
          gui_touch_feedback_disable_vibrate();		
		}
 	#endif
    
        result = mdi_audio_resume(mmi_sndrec_resume_cb_hdlr, NULL);
        MMI_SNDREC_MSG_TRACE(result);
        if (result == MDI_AUDIO_SUCCESS)
        {
            g_sndrec_cntx.record.state = endstate;
            ret = MMI_TRUE;
            /* clear key events to prevent external queue overflow */
        		ClearKeyEvents();
        }
        else if (result == MDI_AUDIO_UNSUPPORTED_OPERATION)
        {
            mmi_sndrec_error_hdlr(MDI_AUDIO_UNSUPPORTED_TYPE, isRecord);
	    #ifdef __MMI_FTE_SUPPORT__	
            gui_touch_feedback_enable_tone();	
 	     #endif		
            ret = MMI_FALSE;
        }
        else
        {
            if ((g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE) && 
            #ifndef __MMI_SNDREC_SLIM__
                (!g_sndrec_cntx.record.isappend) && 
            #endif
                mmi_sndrec_is_file_exist())
            {
            	g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
                mmi_sndrec_record_stop_hdlr();
            }
            else
            {
            		if(result ==MDI_AUDIO_END_OF_FILE )
            		{
            			if(play_end_cb)
            			{
            				play_end_cb(result);
            			}
            		}
            		else
            		{
            			mmi_sndrec_error_hdlr(result, isRecord);
            		}
        			g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE; 
              }
              #ifdef __MMI_FTE_SUPPORT__	
                  gui_touch_feedback_enable_tone();		
              #endif		
        }

    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_resume_cb_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_resume_cb_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL isRecord = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_RESUME_CALLBACK, g_sndrec_cntx.record.state, result);
#ifdef __MMI_SNDREC_SKIN__
    gui_cancel_timer(mmi_sndrec_update_time_text);
#endif 

    	#ifdef __MMI_FTE_SUPPORT__	
	if(gui_touch_feedback_get_tone_state() == MMI_TRUE)
	{
          gui_touch_feedback_disable_tone();	
	}
    if(gui_touch_feedback_get_vibrate_state() == MMI_TRUE)
	{
          gui_touch_feedback_disable_vibrate();		
	}	
 	#endif	
    /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
    #ifdef __MMI_SNDREC_SKIN__
    if ((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_STATE) ||
        (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_PAUSE_STATE))
    {
        isRecord = MMI_FALSE;
    }
    #endif

    if (result == MDI_AUDIO_TERMINATED)
    {
        if ((g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE) ||
            (g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE))
        {
            mmi_sndrec_increase_rectime();
            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
        #ifndef __MMI_SNDREC_SLIM__
            MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.isappend);
            if (g_sndrec_cntx.record.isappend)
            {
                mmi_sndrec_append_stop_hdlr();
            }
            else
        #endif
            {
                mmi_sndrec_record_stop_hdlr();
            }
        }
        /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
        #ifdef __MMI_SNDREC_SKIN__
        else if ((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_PAUSE_STATE))
        {
            MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.state);
            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
            play_end_cb(result);
        }
        #endif
        else
        {
            MMI_SNDREC_MSG_TRACE(11);
            mmi_sndrec_cb_for_other_app(MMI_TRUE);
        }
    }
    else if (result == MDI_AUDIO_SUCCESS)
    {
        g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
        mmi_popup_display_simple_ext(
            STR_ID_SNDREC_SMS_RECORD_TIMEOUT,
            MMI_EVENT_FAILURE,
            GRP_ID_ROOT,
            NULL);

    }
    else if (result == MDI_AUDIO_END_OF_FILE)
    {
        if ((g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE) ||
            (g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE))
        {
            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
            if ( 
            #ifndef __MMI_SNDREC_SLIM__
                !g_sndrec_cntx.record.isappend && 
            #endif
                mmi_sndrec_is_file_exist())
            {
                mmi_sndrec_record_stop_hdlr();
            }
            else
            {
                mmi_sndrec_error_hdlr(result, isRecord);
            }
        }
        /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
        #ifdef __MMI_SNDREC_SKIN__
        else if ((g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PLAY_PAUSE_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_STATE) ||
                 (g_sndrec_cntx.record.state == MMI_SNDREC_PREVIEW_PAUSE_STATE))
        {
            MMI_SNDREC_MSG_TRACE(12);
            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
            play_end_cb(result);
        }
        #endif
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }
    else
    {
        if (g_sndrec_cntx.record.state != MMI_SNDREC_IDLE_STATE)
        {
            isRecord = (MMI_BOOL)(g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE ||
                             g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE);

            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
            if (isRecord && result == MDI_AUDIO_FAIL)
            {
                result = MDI_AUDIO_DISC_FULL;
            }
            if (isRecord && 
            #ifndef __MMI_SNDREC_SLIM__
                !g_sndrec_cntx.record.isappend && 
            #endif
                mmi_sndrec_is_file_exist())
            {
                if (result == MDI_AUDIO_DISC_FULL)
                {
                    /* If disc and record stop, should add last record time */
                    /* mmi_sndrec_increase_rectime(); */
                #ifdef __MMI_SNDREC_SKIN__
                    g_sndrec_cntx.record.rectime = g_total_time;
                    g_sndrec_cntx.record.remindsize = 0;
                #endif /* __MMI_SNDREC_SKIN__ */ 
                    MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.rectime);
                    mmi_popup_display_simple_ext(
                        STR_ID_SNDREC_DISC_FULL,
                        MMI_EVENT_FAILURE,
                        GRP_ID_ROOT,
                        NULL);
                }
                else
                {
                    mmi_sndrec_error_hdlr(result, isRecord);
                }
            }
            else
            {
                MMI_SNDREC_MSG_TRACE(isRecord);
                if (isRecord && (result == MDI_AUDIO_DISC_FULL) && mmi_sndrec_is_file_exist())
                {
                    mmi_sndrec_increase_rectime();
                    /* g_sndrec_cntx.record.rectime += Media_GetRecordedTime(); */
                #ifndef __MMI_SNDREC_SLIM__
                    g_sndrec_cntx.record.isappend = MMI_FALSE;
                #endif
                }
                mmi_sndrec_error_hdlr(result, isRecord);
            }
        }
    }
}

#define __SNDREC_MSG_PLAY__

#ifdef __MMI_OP12_SNDREC_STYLE__


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_preview_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [IN]        
 *  end_cb      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_sndrec_send_preview_req(UI_string_type file, void (*end_cb) (MDI_RESULT result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    MMI_BOOL res = MMI_FALSE;
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name(file_path_name,file);
    
    /* suspend background play before */
   #ifdef __MMI_FTE_SUPPORT__	
   	if(gui_touch_feedback_get_tone_state() == MMI_TRUE)
	{
   gui_touch_feedback_disable_tone();	
	} 
    #if defined (__MMI_TOUCH_FEEDBACK_SUPPORT__)
/* under construction !*/
/* under construction !*/
   #endif		
   #endif		
   
    mmi_sndrec_bgsound_suspend();

    result = mdi_audio_play_file(file_path_name, DEVICE_AUDIO_PLAY_ONCE, NULL, mmi_sndrec_play_cb_hdlr, NULL);
    MMI_SNDREC_MSG_TRACE(result);
    if (result == MDI_AUDIO_SUCCESS)
    {
        g_sndrec_cntx.record.state = MMI_SNDREC_PREVIEW_STATE;
        play_end_cb = end_cb;
        res = MMI_TRUE;
    }
    else
    {
        #ifdef __MMI_FTE_SUPPORT__	
        gui_touch_feedback_enable_tone();	
        #endif	
        g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
        play_end_cb = NULL;
        mmi_sndrec_error_hdlr(result, MMI_FALSE);
    }

    return res;
}
#endif /* __MMI_OP12_SNDREC_STYLE__ */ 

#ifdef  __MMI_SNDREC_SKIN__  
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_send_play_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [IN]        
 *  end_cb      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sndrec_send_play_req(UI_string_type file, void (*end_cb) (MDI_RESULT result))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    MMI_BOOL res = MMI_FALSE;
    U16 file_path_name[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_SEND_PLAY_REQ);
    mmi_sndrec_get_full_file_name(file_path_name,file);

#ifdef __DRM_SUPPORT__
    {
        FS_HANDLE handle;
        BOOL is_permitted = FALSE;

        if ((handle = DRM_open_file((PU16) file_path_name, FS_READ_ONLY, DRM_PERMISSION_NONE)) >= FS_NO_ERROR)
        {
            is_permitted = TRUE;
            DRM_close_file(handle);
        }
        else if (handle < -1)   /* file open error, but not DRM related problem */
        {
            is_permitted = TRUE;
        }

        if (!is_permitted)
        {
            g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
            mmi_sndrec_error_hdlr(DRM_NOT_PERMIT_TO_PLAY, MMI_FALSE);
            mdi_audio_stop_all();
            return res;
        }
    }
#endif /* __DRM_SUPPORT__ */ 

    /* suspend background play before */
	#ifdef __MMI_FTE_SUPPORT__	
	if(gui_touch_feedback_get_tone_state() == MMI_TRUE)
	{
	gui_touch_feedback_disable_tone();
	} 
	/* sleep 200 ms */
	#if defined (__MMI_TOUCH_FEEDBACK_SUPPORT__)
/* under construction !*/
	#endif	

	#endif	

    mmi_sndrec_bgsound_suspend();
    result = mdi_audio_play_file(file_path_name, DEVICE_AUDIO_PLAY_ONCE, NULL, mmi_sndrec_play_cb_hdlr, NULL);
    MMI_SNDREC_MSG_TRACE(result);
    if (result == MDI_AUDIO_SUCCESS)
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(g_sndrec_cntx.record.volume));
        g_sndrec_cntx.record.state = MMI_SNDREC_PLAY_STATE;
        play_end_cb = end_cb;
        res = MMI_TRUE;
    }
    else
    {
        g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
        play_end_cb = NULL;
        if (result == MDI_AUDIO_END_OF_FILE)
        {
            mmi_popup_display_simple_ext(
                STR_ID_SNDREC_AUDIO_PLAY_FAIL,
                MMI_EVENT_FAILURE,
                GRP_ID_ROOT,
                NULL);

        }
        else
        {
            mmi_sndrec_error_hdlr(result, MMI_FALSE);
        }
	#ifdef __MMI_FTE_SUPPORT__	
	gui_touch_feedback_enable_tone();	
	#endif	
    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_play_cb_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_play_cb_hdlr(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_CALLBACK, g_sndrec_cntx.record.state, result);
#ifdef __MMI_SNDREC_SKIN__
    gui_cancel_timer(mmi_sndrec_update_time_text);
#endif 
	#ifdef __MMI_FTE_SUPPORT__	
	gui_touch_feedback_enable_tone();	
	#endif	
    g_sndrec_cntx.record.state = MMI_SNDREC_IDLE_STATE;
    //kal_prompt_trace(MOD_MMI, "[SNDREC]play call back, result: %d. state: %d", result, g_sndrec_cntx.record.state);
    play_end_cb(result);

}
#endif /* __MMI_SNDREC_SKIN__ */


#define __SNDREC_MSG_TIME__
/* Wrap the checking of remain size with __MMI_SNDREC_SKIN__ macro for SLIM */
#ifdef __MMI_SNDREC_SKIN__
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_remain_time
 * DESCRIPTION
 *  This function will return remain time (For checking before sending record request)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U64 mmi_sndrec_get_remain_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  quality;
    U64 remain_time, remain_size;
    S32 rate = 0;
    U8 drive[32];
    FS_DiskInfo diskinfo;
    S16 ret;

    mdi_audio_rec_param_struct rec_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Get the quality */
    if (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE ||
       g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE)
    {
        quality = g_sndrec_cntx.record.quality;
    }
    else
    {
        quality = g_sndrec_cntx.setting.quality;
    }

    /* Get record bit rate */
    mdi_audio_get_record_param((MDI_AUDIO_REC_MODE_ENUM)mmi_sndrec_get_rec_type(), (MDI_AUDIO_REC_QUALITY_ENUM)quality, &rec_param);
	rate = rec_param.byte_rate;

    /* Get disk size */
    kal_wsprintf((U16*) drive, "%c:\\", g_sndrec_cntx.setting.drive);
    ret = FS_GetDevStatus(g_sndrec_cntx.setting.drive, FS_FEATURE_STATE_ENUM);
    if (ret < FS_NO_ERROR)
    {
        remain_size = 0;
        MMI_SNDREC_ERR_TRACE(remain_size);
    }
    else
    {
        ret = FS_GetDiskInfo((U16*) drive, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if (ret >= FS_NO_ERROR)
        {
            remain_size =
                diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
            MMI_SNDREC_MSG_TRACE(remain_size);
        }
        else
        {
            remain_size = 0;
            MMI_SNDREC_ERR_TRACE(ret);
        }
    }

    /* Caculate remain time (in seconds) */
    remain_time = (U64) (remain_size / rate);

    return remain_time;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_init_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_init_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_INIT_TIME);

#ifdef __MMI_SNDREC_SKIN__
    g_sndrec_cntx.record.rectime = 0;
#else 
    mmi_sndrec_init_ticks();
#endif 
}

#ifdef __MMI_SNDREC_SKIN__


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_record_time_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_record_time_string(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  quality;
    U32 recordtime, remindtime;
    U64 real_remindtime;
    S32 rate = 0;
    mmi_sndrec_time_struct time1, time2;

    mdi_audio_rec_param_struct rec_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_SNDREC_REC_STATE == g_sndrec_cntx.record.state || MMI_SNDREC_REC_PAUSE_STATE == g_sndrec_cntx.record.state)
    {
        recordtime = mdi_audio_get_record_time();
    }
    else
    {
        recordtime = 0;
    }
   if (g_sndrec_cntx.record.state == MMI_SNDREC_REC_STATE ||
       g_sndrec_cntx.record.state == MMI_SNDREC_REC_PAUSE_STATE)
    {
        quality = g_sndrec_cntx.record.quality;
    }
    else
    {
        quality = g_sndrec_cntx.setting.quality;   
    }

#ifndef __MMI_SNDREC_SLIM__
    if(g_sndrec_cntx.record.isappend == MMI_TRUE)
        rate = mdi_audio_get_estimated_record_byte_rate((MDI_AUDIO_REC_MODE_ENUM)mmi_sndrec_get_rec_type(),mmi_sdnrec_append_mdi_format_enum(), (MDI_AUDIO_REC_QUALITY_ENUM)quality);	
    else
#endif
    {
        /* Use the byte rate directly from rec_param and use MDI_AUDIO_REC_QUALITY_AUTO to sync with the actual byte rate while recording */
        mdi_audio_get_record_param((MDI_AUDIO_REC_MODE_ENUM)mmi_sndrec_get_rec_type(), (MDI_AUDIO_REC_QUALITY_ENUM)quality, &rec_param);
        //rate = mdi_audio_get_estimated_record_byte_rate((MDI_AUDIO_REC_MODE_ENUM)mmi_sndrec_get_rec_type(),rec_param.format, (MDI_AUDIO_REC_QUALITY_ENUM)quality);
        rate = rec_param.byte_rate;
    }

    MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.rectime);
    recordtime += g_sndrec_cntx.record.rectime;
    g_total_time = recordtime;

    if (!g_sndrec_cntx.record.is_timer_on)
    {
       #if defined(__MMI_OP02_LEMEI__)
        g_oth_app_time_limit = 0;
        if(g_size_limit > 0)
        {
           g_oth_app_time_limit = (U64) (g_size_limit / (rate));
        }
        #endif
        MMI_SNDREC_MSG_TRACE(recordtime);
        mmi_sndrec_get_drive_size();
        g_sndrec_cntx.record.is_timer_on = MMI_TRUE;
        gui_start_timer(5000, mmi_sndrec_get_drive_size);
    }

    real_remindtime = (U64) (g_sndrec_cntx.record.remindsize / rate);
    #if defined(__MMI_OP02_LEMEI__)
    /* Application's recording time left */
    if(g_sndrec_show_app_recording_time_left == MMI_TRUE && g_sndrec_cntx.record.isEntryFromOther == MMI_TRUE)
    {
        real_remindtime = g_oth_app_time_limit;
    }
    #endif
    MMI_SNDREC_MSG_TRACE(real_remindtime);

    /* check if more than 10000 hours left */
    remindtime =
        (real_remindtime >=
         MMI_SNDREC_HOURS_DISPLAY_LIMIT) ? MMI_SNDREC_HOURS_DISPLAY_LIMIT - 1 : (U32) real_remindtime;

    mmi_sndrec_transte_time(recordtime / 1000, &time1);
    mmi_sndrec_transte_time(remindtime, &time2);

    kal_wsprintf(
        string,
        "%02d:%02d:%02d / %02d:%02d:%02d",
        time1.hour,
        time1.minute,
        time1.second,
        time2.hour,
        time2.minute,
        time2.second);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_drive_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  string(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_drive_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 drive[32];
    S16 ret;
    FS_DiskInfo diskinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_OP02_LEMEI__)
    if(g_sndrec_show_app_recording_time_left == MMI_TRUE)
    {
        return;
    }
    #endif
    kal_wsprintf((U16*) drive, "%c:\\", g_sndrec_cntx.setting.drive);
    ret = FS_GetDevStatus(g_sndrec_cntx.setting.drive, FS_FEATURE_STATE_ENUM);
    if (ret < FS_NO_ERROR)
    {
        g_sndrec_cntx.record.remindsize = 0;
        MMI_SNDREC_ERR_TRACE(ret);
    }
    else
    {
        ret = FS_GetDiskInfo((U16*) drive, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        if (ret >= FS_NO_ERROR)
        {
            g_sndrec_cntx.record.remindsize =
                diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
            MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.remindsize);
        }
        else
        {
            g_sndrec_cntx.record.remindsize = 0;
            MMI_SNDREC_MSG_TRACE(ret);
        }
    }

    g_sndrec_cntx.record.is_timer_on = MMI_TRUE;
    gui_start_timer(5000, mmi_sndrec_get_drive_size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_play_time_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_get_play_time_string(UI_string_type string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 playtime;
    MDI_RESULT result;
    mmi_sndrec_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mdi_audio_get_progress_time(&playtime);
    if (MDI_AUDIO_SUCCESS == result)
    {
        mmi_sndrec_transte_time(playtime / 1000, &time);
        kal_wsprintf(string, "%02d:%02d:%02d", time.hour, time.minute, time.second);
    }
    else
    {
        time.hour = 0;
        time.minute = 0;
        time.second = 0;
        kal_wsprintf(string, "%02d:%02d:%02d", time.hour, time.minute, time.second);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_transte_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  second      [IN]        
 *  time        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_transte_time(U32 second, mmi_sndrec_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time->second = second % 60;
    second /= 60;
    time->minute = second % 60;
    second /= 60;
    time->hour = second;
}

#else /* __MMI_SNDREC_SKIN__ */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_get_ticks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_sndrec_get_ticks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_GET_TICKS, g_sndrec_cntx.record.state);

    /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
    #ifdef __MMI_SNDREC_SKIN__
    if (MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state ||
        MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state)
    {
        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.playtime);
        return g_sndrec_cntx.record.playtime + g_sndrec_cntx.record.lastplaytime;
    }
    else
    #endif
    {
        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.rectime);
        return g_sndrec_cntx.record.rectime + g_sndrec_cntx.record.lasttime;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_init_ticks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_init_ticks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_INIT_TICKS, g_sndrec_cntx.record.state);

    g_sndrec_cntx.record.playtime = 0;
    g_sndrec_cntx.record.lastplaytime = 0;
    g_sndrec_cntx.record.beginplaytime = 0;
    g_sndrec_cntx.record.rectime = 0;
    g_sndrec_cntx.record.lasttime = 0;
    g_sndrec_cntx.record.begintime = 0;

    g_sndrec_cntx.record.isStartTimer = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_start_ticks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_start_ticks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_START_TICKS, g_sndrec_cntx.record.state);

    /* Play, Play Pause, Preview, Preview states are not present in SLIM (Use Audio Player API) */
    #ifdef __MMI_SNDREC_SKIN__
    if (MMI_SNDREC_PLAY_STATE == g_sndrec_cntx.record.state ||
        MMI_SNDREC_PLAY_PAUSE_STATE == g_sndrec_cntx.record.state)
    {
        g_sndrec_cntx.record.playtime += g_sndrec_cntx.record.lastplaytime;
        g_sndrec_cntx.record.lastplaytime = 0;
        kal_get_time((kal_uint32*) & g_sndrec_cntx.record.beginplaytime);

        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.lastplaytime);
        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.playtime);
        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.beginplaytime);
    }
    else
    #endif
    {
        g_sndrec_cntx.record.rectime += g_sndrec_cntx.record.lasttime;
        g_sndrec_cntx.record.lasttime = 0;
        kal_get_time((kal_uint32*) & g_sndrec_cntx.record.begintime);

        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.lasttime);
        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.rectime);
        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.begintime);
    }
    g_sndrec_cntx.record.isStartTimer = MMI_TRUE;
}

#if 0 //def  __MMI_SNDREC_SKIN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SNDREC_SKIN__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_update_rec_ticks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_update_rec_ticks(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_UPDATE_TICKS, g_sndrec_cntx.record.state);

    if (g_sndrec_cntx.record.isStartTimer)
    {
        kal_get_time(&current_time);
        g_sndrec_cntx.record.isStartTimer = MMI_FALSE;

        g_sndrec_cntx.record.lasttime = current_time - g_sndrec_cntx.record.begintime;
        MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.lasttime);
    }
}

#endif /* __MMI_SNDREC_SKIN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_increase_rectime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sndrec_increase_rectime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_INCREASE_RECTIME, g_sndrec_cntx.record.state);

#ifdef __MMI_SNDREC_SKIN__
    g_sndrec_cntx.record.rectime += mdi_audio_get_record_time();
    MMI_SNDREC_MSG_TRACE(g_sndrec_cntx.record.rectime);
#endif /* __MMI_SNDREC_SKIN__ */ 

}

#define __SNDREC_MSG_OTHER__

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause           [IN]        
 *  isRecord        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_sndrec_error_hdlr(S32 cause, MMI_BOOL isRecord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID image_id = 0;
//    MMI_ID event = MMI_EVENT_DEFAULT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_SNDREC_MSG_TRACE(cause);
    switch (cause)
    {
        case MDI_AUDIO_SUCCESS:
            break;
    #ifdef __DRM_SUPPORT__
        case DRM_NOT_PERMIT_TO_PLAY:
        case DRM_NOT_PERMIT_TO_APPEND:
        case MDI_AUDIO_DRM_PROHIBIT:
            image_id = STR_GLOBAL_DRM_PROHIBITED;
            break;
    #endif /* __DRM_SUPPORT__ */ 
    
#if  0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else  /* __MMI_SNDREC_SKIN__ */
        case MDI_AUDIO_FAIL:
        case MDI_AUDIO_ERROR:
        case MDI_AUDIO_UNSUPPORTED_CHANNEL:		
            if (isRecord)
            {
                image_id = STR_ID_SNDREC_REC_ERROR;

            }
            else
            {
                image_id = STR_ID_SNDREC_AUDIO_PLAY_FAIL;

            }
            break;
        case MDI_AUDIO_BAD_FORMAT:
            image_id = STR_GLOBAL_INVALID_FORMAT;
            break;
        case MDI_AUDIO_UNSUPPORTED_TYPE:
            image_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
            break;
        case MDI_AUDIO_INVALID_FORMAT:
            image_id = STR_GLOBAL_INVALID_FORMAT;
            break;
        case MDI_AUDIO_BUSY:
            image_id = STR_GLOBAL_BUSY_TRY_LATER;
            break;
        case MDI_AUDIO_DISC_FULL:
        case MDI_AUDIO_NO_SPACE:
            // use file manager disk full string id for unified error message notification
            image_id = FMGR_FS_DISK_FULL_TEXT;
            break;
        case MDI_AUDIO_OPEN_FILE_FAIL:
            if (isRecord)
            {
                image_id = STR_ID_SNDREC_REC_ERROR;

            }
            else
            {

                image_id = STR_ID_SNDREC_AUDIO_PLAY_FAIL;

            }
            break;
        case MDI_AUDIO_NO_DISC:
            image_id = STR_GLOBAL_INSERT_MEMORY_CARD;
            break;
        case MDI_AUDIO_WRITE_PROTECTION:
            image_id = STR_ID_SNDREC_SYSTEM_ERROR;
            break;
        case MDI_AUDIO_DRM_TIMEOUT:
            image_id = STR_GLOBAL_DRM_PROHIBITED;
            break;
        case MDI_AUDIO_UNSUPPORTED_FREQ:
            image_id = STR_ID_SNDREC_SYSTEM_ERROR;
            break;
#endif  /* __MMI_SNDREC_SKIN__ */

        /*
        * should never return these error id, except bug in coding. So just for debug.
        */
        case MDI_AUDIO_END_OF_FILE:
            ClearKeyEvents();
            break;
        default:
            MMI_SNDREC_ERR_TRACE(cause);
            break;       
    }
    if (image_id)
    {
        mmi_popup_display_simple_ext(image_id, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
    return image_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_bgsound_suspend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_bgsound_suspend()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_SUSPEND_BGSND);

    if ((!mdi_audio_is_background_play_suspended()) &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0))
    {
        MMI_SNDREC_MSG_TRACE(1);
        mdi_audio_suspend_background_play();
        g_sndrec_suspend = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_bgsound_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_bgsound_resume()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_RESUME_BGSND);

    if (mdi_audio_is_background_play_suspended() &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0) && g_sndrec_suspend)
    {
        MMI_SNDREC_MSG_TRACE(1);
        mdi_audio_resume_background_play();
        g_sndrec_suspend = MMI_FALSE;
    }
}

#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata , code
#endif

#endif /* (defined(__MMI_SOUND_RECORDER__) ) */ 

