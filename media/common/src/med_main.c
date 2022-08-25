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
 *   med_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of media task.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/

/* system includes */

#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

/* global includes */
#include "l1audio.h"
#include "nvram_struct.h"
#include "audio_nvram_def.h"

/* local include */
#include "med_global.h"
#include "med_mem.h"
#include "med_struct.h"
#include "med_context.h"
#include "med_utility.h"

#include "aud_main.h"
#include "med_main.h"

#ifdef __MED_VCALL_MOD__
#include "vcall.h"
#include "vt_med_enum.h"
#include "vt_med_struct.h"
#include "vcall_api.h"
#endif

#ifdef __MED_RTP_MOD__
#include "rtp.h"
#endif

#ifdef __MED_STREAM_MOD__
#include "stream_api.h"
#endif

#ifdef __MED_CAM_MOD__
#include "cam_main.h"
#endif 
#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)
#include "vid_main.h"
#endif 
#ifdef __MED_WEBCAM_MOD__
#include "webcam_main.h"
#endif 
#if defined (__MED_TVO_MOD__)
#include "tvo_main.h"
#endif 
#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__)
#include "mtv_main.h"
#endif
#ifdef __MED_BITSTREAM_MOD__
#include "bitstream_main.h"
#endif
#ifdef __GAIN_TABLE_SUPPORT__
#include "gain_table.h"
#endif
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
#include "speech_mode_table.h"
#endif

#if defined(__MTK_INTERNAL__)
#if defined(__MTK_TARGET__) && defined(__RF_DESENSE_TEST__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#if (defined(__RESOURCE_MANAGER__) && defined(__MTK_TARGET__))
#include "rm.h"
#endif //__RESOURCE_MANAGER__

#include "med_mem.h"
#include "kal_general_types.h"
#include "nvram_editor_data_item.h"
#include "kal_public_api.h"
#include "aud_common_config.h"
#include "stack_config.h"
#include "task_main_func.h"
#include "stack_ltlcom.h"
#include "kal_active_module.h"
#include "hisr_config.h"

/* global variables */
med_context_struct med_context;
med_context_struct *med_context_p = &med_context;

#ifdef __MTK_TARGET__
    #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
        #pragma arm section zidata = "DYNAMICCACHEABLEZI_NC_MMIPOOL"
        __align(4)     kal_uint8 med_ext_mem[MED_EXT_MEM_SIZE];
        __align(4)     kal_uint8 med_aud_mem[MED_AUD_MEM_SIZE];
        #pragma arm section zidata
    #else
        #pragma arm section zidata = "LARGEPOOL_ZI"
        __align(4)     kal_uint8 med_ext_mem[MED_EXT_MEM_SIZE];
        __align(4)     kal_uint8 med_aud_mem[MED_AUD_MEM_SIZE];
        #pragma arm section zidata
    #endif

    #ifdef __VIDEO_STANDALONE_MEMORY__
        #pragma arm section zidata = "VIDEOPOOL_C"
        __align(4)     kal_uint8 med_vid_mem[MED_VID_MEM_SIZE];
        #pragma arm section zidata
    #endif

#else
    kal_uint8 med_ext_mem[MED_EXT_MEM_SIZE];
    kal_uint8 med_aud_mem[MED_AUD_MEM_SIZE];
    #ifdef __VIDEO_STANDALONE_MEMORY__
    kal_uint8 med_vid_mem[MED_VID_MEM_SIZE];
    #endif
#endif

/*==== FUNCTIONS ===========*/
extern void med_timer_expiry_hdlr(ilm_struct *ilm_ptr);

/* mbbms */
#ifdef __CMMB_CAS_MBBMS_SUPPORT__
extern kal_bool mbbms_main(ilm_struct *ilm_ptr);
extern kal_bool mbbms_timer_expiry_hdlr(ilm_struct *ilm_ptr);
#endif /* __CMMB_CAS_MBBMS_SUPPORT__ */

#ifdef __AUDIO_DC_CALIBRATION_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  med_dc_calibration_write_nvram
 * DESCRIPTION
 *  This function is to write dc calibraion nvram data
 * PARAMETERS
 *  msg_name      [IN]		msg ID
 * RETURNS
 *  void
 *****************************************************************************/
void med_dc_calibration_write_nvram(kal_uint32 func_arg1, void *func_arg2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_msg_to_nvram(MSG_ID_NVRAM_WRITE_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, (kal_uint16 *)func_arg2, NVRAM_EF_AUDIO_DC_CALIBRATION_SIZE);
}

/*****************************************************************************
 * FUNCTION
 *  med_dc_calibration_callback
 * DESCRIPTION
 *  This function will be called when DC calibration is done,
 *  It is in Audio task, need to write NVRAM in MED task
 * PARAMETERS
 *  pdc_offset      [IN]		Calibration offset      
 * RETURNS
 *  void
 *****************************************************************************/
void med_dc_calibration_callback(kal_uint16 *pdc_offset)
{  
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   aud_send_in_proc_call_req(MOD_L1SP, med_dc_calibration_write_nvram, NULL, (void *)pdc_offset);
}
#endif /*__AUDIO_DC_CALIBRATION_SUPPORT__*/

#ifdef __VOICE_CHANGER_SUPPORT__
void med_voice_changer_write_nvram(SPH_VOICE_CHANGER_MODE mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_msg_to_nvram(MSG_ID_NVRAM_WRITE_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, (void *)(&mode), NVRAM_EF_AUDIO_VOICE_CHANGER_SIZE);
}
#endif


#ifdef __VIBRATION_SPEAKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  med_vib_calibration_write_nvram
 * DESCRIPTION
 *  This function is to write vib calibraion nvram data
 * PARAMETERS
 *  msg_name      [IN]		msg ID
 * RETURNS
 *  void
 *****************************************************************************/
void med_vib_calibration_write_nvram(kal_uint32 func_arg1, void *func_arg2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_send_msg_to_nvram(MSG_ID_NVRAM_WRITE_REQ, NVRAM_EF_AUDIO_VIBR_LID, (void *)func_arg2, NVRAM_EF_AUDIO_VIBR_SIZE);
}

/*****************************************************************************
 * FUNCTION
 *  med_vib_calibration_callback
 * DESCRIPTION
 *  This function will be called when VIB calibration is done,
 *  It is in Audio task, need to write NVRAM in MED task
 * PARAMETERS
 *  pdc_offset      [IN]		Calibration offset      
 * RETURNS
 *  void
 *****************************************************************************/
void med_vib_calibration_callback(void *cali_data)
{  
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   aud_send_in_proc_call_req(MOD_L1SP, med_vib_calibration_write_nvram, NULL, (void *)cali_data);
}
#endif /*__VIBRATION_SPEAKER_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  med_nvram_read_data_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle nvram read data confirm.
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_nvram_read_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_cnf_struct *parm_ptr = NULL;
    kal_uint16 pdu_len;
    kal_uint8 *pdu_ptr;
    audio_param_struct *nvram_param_p;
    kal_uint16 *pdc_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MED_FUNC_ENTRY(MED_NVRAM_READ_DATA_CNF_HDLR) */

    parm_ptr = (nvram_read_cnf_struct*) local_para_ptr;
    pdu_ptr = get_pdu_ptr(peer_buff_ptr, &pdu_len);
    switch (parm_ptr->file_idx)
    {
        case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
            if (parm_ptr->length != sizeof(custom_acoustic_struct))
            {
                /* error reading length */
                ASSERT(0);
                return;
            }
            kal_mem_cpy(
                &(aud_context_p->acoustic_data),
                (custom_acoustic_struct*) pdu_ptr,
                sizeof(custom_acoustic_struct));

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__AUDIO_COMPENSATION_SW_VERSION__) 
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_SWFIR_LID, 0, 0);
            #elif defined(__GAIN_TABLE_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_GAIN_TABLE_LID, 0, 0);
            #elif defined(__SPEECH_MODE_TABLE_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_SPEECH_MODE_TABLE_LID, 0, 0);
            #elif defined(__AMRWB_LINK_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID, 0, 0);
            #elif defined(__DUAL_MIC_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID, 0, 0);
            #elif defined(__BES_LOUDNESS_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BESLOUDNESS_LID, 0, 0);
            #elif defined(__BES_EQ_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID, 0, 0);
			#elif defined(__VIBRATION_SPEAKER_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VIBR_LID, 0, 0);    
            #elif defined(__HD_RECORD__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif

            }
            break;

    #ifdef __AUDIO_COMPENSATION_SW_VERSION__ 
        case NVRAM_EF_AUDIO_SWFIR_LID:
            ASSERT(parm_ptr->length == sizeof(nvram_ef_audio_swfir_struct));
            Media_SetAudioCompensation_SWFIR(pdu_ptr, parm_ptr->length);
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__GAIN_TABLE_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_GAIN_TABLE_LID, 0, 0);
            #elif defined(__SPEECH_MODE_TABLE_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_SPEECH_MODE_TABLE_LID, 0, 0);
            #elif defined(__AMRWB_LINK_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID, 0, 0);
            #elif defined(__DUAL_MIC_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID, 0, 0);
            #elif defined(__BES_LOUDNESS_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BESLOUDNESS_LID, 0, 0);
            #elif defined(__BES_EQ_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID, 0, 0);
			#elif defined(__VIBRATION_SPEAKER_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VIBR_LID, 0, 0);    
            #elif defined(__HD_RECORD__)
                 aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                 aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ,  NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0 , 0);
			#else
                 aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif

            }
            break;
    #endif /* __AUDIO_COMPENSATION_SW_VERSION__ */
    
    #ifdef __GAIN_TABLE_SUPPORT__
        case NVRAM_EF_AUDIO_GAIN_TABLE_LID:
            if (parm_ptr->length != sizeof(nvram_gain_table_struct))
            {
                /* error reading length */
                ASSERT(0);
                return;
            }
            kal_mem_cpy(
                gain_table_nvram,
                (nvram_gain_table_struct*) pdu_ptr,
                sizeof(nvram_gain_table_struct));

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__SPEECH_MODE_TABLE_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_SPEECH_MODE_TABLE_LID, 0, 0);
            #elif defined(__AMRWB_LINK_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID, 0, 0);
            #elif defined(__DUAL_MIC_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID, 0, 0);
            #elif defined(__BES_LOUDNESS_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BESLOUDNESS_LID, 0, 0);
            #elif defined(__BES_EQ_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID, 0, 0);
			#elif defined(__VIBRATION_SPEAKER_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VIBR_LID, 0, 0);    
            #elif defined(__HD_RECORD__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif

            }
            break;
    #endif /* __GAIN_TABLE_SUPPORT__ */

    #ifdef __SPEECH_MODE_TABLE_SUPPORT__        
        case NVRAM_EF_AUDIO_SPEECH_MODE_TABLE_LID:
            kal_mem_cpy(
                speech_mode_table_nvram,
                (nvram_speech_mode_table_struct*) pdu_ptr,
                sizeof(nvram_speech_mode_table_struct));
            
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__AMRWB_LINK_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID, 0, 0);
            #elif defined( __DUAL_MIC_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID, 0, 0);
            #elif defined(__BES_LOUDNESS_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BESLOUDNESS_LID, 0, 0);
            #elif defined(__BES_EQ_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID, 0, 0);
			#elif defined(__VIBRATION_SPEAKER_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VIBR_LID, 0, 0);    
            #elif defined(__HD_RECORD__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
    #endif /* __SPEECH_MODE_TABLE_SUPPORT__ */
    
    #ifdef __AMRWB_LINK_SUPPORT__
        case NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID:
            ASSERT(parm_ptr->length == sizeof(audio_wb_speech_fir_struct));

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR,(kal_uint8*) pdu_ptr, parm_ptr->length);

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID, 0, 0);
            }
            break;

        case NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID:
            ASSERT(parm_ptr->length == sizeof(audio_wb_speech_fir_struct));

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR,(kal_uint8*) pdu_ptr, parm_ptr->length);

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID, 0, 0);
            }
            break;

         case NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID:
            ASSERT(parm_ptr->length == sizeof(audio_wb_speech_mode_struct));

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM,(kal_uint8*) pdu_ptr, parm_ptr->length);

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__DUAL_MIC_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID, 0, 0);
            #elif defined(__BES_LOUDNESS_SUPPORT__ )
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BESLOUDNESS_LID, 0, 0);
            #elif defined(__BES_EQ_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID, 0, 0);
			#elif defined(__VIBRATION_SPEAKER_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VIBR_LID, 0, 0);    
            #elif defined(__HD_RECORD__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
    #endif /* __AMRWB_LINK_SUPPORT__ */

    #ifdef __DUAL_MIC_SUPPORT__
         case NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID:
         {
             audio_dual_mic_param_struct* dm_param_p;
             
             ASSERT(parm_ptr->length == sizeof(audio_dual_mic_param_struct));
             dm_param_p = (audio_dual_mic_param_struct*)pdu_ptr;

             L1SP_SetDMNRPara((kal_int16 *)(&dm_param_p->nb_param));
        #ifdef __AMRWB_LINK_SUPPORT__
             L1SP_SetWbDMNRPara((kal_int16 *)(&dm_param_p->wb_param));
        #endif

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__BES_LOUDNESS_SUPPORT__ )
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BESLOUDNESS_LID, 0, 0);
            #elif defined(__BES_EQ_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID, 0, 0);
			#elif defined(__VIBRATION_SPEAKER_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VIBR_LID, 0, 0);    
            #elif defined(__HD_RECORD__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
         }
    #endif

    #ifdef __BES_LOUDNESS_SUPPORT__ 
        case NVRAM_EF_AUDIO_BESLOUDNESS_LID:
            ASSERT(parm_ptr->length == sizeof(nvram_ef_audio_besloudness_struct));
            Media_SetBesLoudnessCustomCoeff_v3(pdu_ptr, parm_ptr->length);
            
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__BES_EQ_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID, 0, 0);
			#elif defined(__VIBRATION_SPEAKER_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VIBR_LID, 0, 0);    
            #elif defined(__HD_RECORD__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
    #endif /* __BES_LOUDNESS_SUPPORT__ */

    #ifdef __BES_EQ_SUPPORT__
        case NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_LID:
        {
            ASSERT(parm_ptr->length == sizeof(nvram_ef_audio_bes_eq_flexible_struct));

            Media_SetBesEQInitParam(pdu_ptr, parm_ptr->length);
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__HD_RECORD__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
			#elif defined(__VIBRATION_SPEAKER_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VIBR_LID, 0, 0);    
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
        }
    #endif /* __BES_EQ_SUPPORT__ */
	
	#ifdef __VIBRATION_SPEAKER_SUPPORT__
        case NVRAM_EF_AUDIO_VIBR_LID:
        {
            ASSERT(parm_ptr->length == sizeof(nvram_ef_audio_vibr_struct));

            Media_SetVibrInitParam(pdu_ptr, parm_ptr->length);
            Media_VIB_Calibration_Write(med_vib_calibration_callback);
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #if defined(__HD_RECORD__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_HD_RECORD_LID, 0, 0);
            #elif defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
        }
    #endif /* __VIBRATION_SPEAKER_SUPPORT__ */

    #ifdef __HD_RECORD__
        case NVRAM_EF_AUDIO_HD_RECORD_LID:
        {
            ASSERT(parm_ptr->length == sizeof(nvram_ef_audio_hd_record_struct));

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_HD_RECORD,(kal_uint8*) pdu_ptr, parm_ptr->length);

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
            #ifdef __AUDIO_DC_CALIBRATION_SUPPORT__ 
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_DC_CALIBRATION_LID, 0, 0);
            #elif defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
			#elif defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            #endif
            }
            break;
        }
    #endif /* __HD_RECORD__ */

    #ifdef __AUDIO_DC_CALIBRATION_SUPPORT__
        case NVRAM_EF_AUDIO_DC_CALIBRATION_LID:
            ASSERT(parm_ptr->length == sizeof(nvram_ef_audio_dc_calibration_struct));
            pdc_offset = (kal_uint16*)pdu_ptr; /* Get dc-offset */
            /* Start DC calibration */
            /* register null to inform this is new procedure for hal sake*/
            AFE_DC_Calibration_Register_Callback(NULL);
            AFE_DC_Calibration(pdc_offset, med_dc_calibration_callback);
            
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                #if defined(__VOICE_CHANGER_SUPPORT__)
			    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_VOICE_CHANGER_LID, 0, 0);
				#elif defined(__AUDIO_AT_CMD__)
					aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			    #else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
				#endif
            }
            break;
    #endif
	
	#ifdef __VOICE_CHANGER_SUPPORT__
        case NVRAM_EF_AUDIO_VOICE_CHANGER_LID:
			{
			nvram_ef_audio_voice_changer_struct *voice_changer_struct;
            ASSERT(parm_ptr->length == sizeof(nvram_ef_audio_voice_changer_struct));
			voice_changer_struct = (nvram_ef_audio_voice_changer_struct *)pdu_ptr;
			
            L1SP_SetVoiceChangerMode(voice_changer_struct->mode);
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
			#if defined(__AUDIO_AT_CMD__)
				aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID, 0, 0);
			#else
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
			#endif
            }
            break;
        	}
    #endif
	#ifdef __AUDIO_AT_CMD__
        case NVRAM_EF_AUDIO_AT_SPEECH_INFO_LID:
			{
			nvram_ef_audio_at_speech_info_struct *at_speech_info;
			AFE_PCMIF_STRUCT_T pcmcfg;
            ASSERT(parm_ptr->length == sizeof(nvram_ef_audio_at_speech_info_struct));
			at_speech_info = (nvram_ef_audio_at_speech_info_struct *)pdu_ptr;
			pcmcfg.VBTON=KAL_FALSE;
			pcmcfg.VBTSYNC=at_speech_info->sync_type;
			pcmcfg.PCM_CK_MODE=at_speech_info->bclk;
			pcmcfg.LPK_U2D=at_speech_info->lpk;
			L1SP_SetECOn(at_speech_info->AEC_state);
			L1SP_SetNROn(at_speech_info->ULNR_state,at_speech_info->DLNR_state);
			AFE_SetPCMBitClk(&pcmcfg);
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
            }
            break;
        	}
    #endif

        case NVRAM_EF_AUDIO_PARAM_LID:

            /*set to L1SP directly*/
            L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_PARAM,(kal_uint8*) pdu_ptr, parm_ptr->length);

            nvram_param_p = (audio_param_struct*)pdu_ptr;

            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM)
            {
                /* Other param will be set once when bootup, no need to keep in global context */
                aud_set_audio_param_to_driver(nvram_param_p);

            #if defined(ISP_SUPPORT) && defined(__MTK_TARGET__)
                cam_send_nvram_startup_req();
            #else /* ISP_SUPPORT */ 
                aud_send_startup_cnf(MED_RES_OK);
                med_context_p->nvram_state = MED_POWERON_READING_NVRAM_FINISH;
            #endif /* ISP_SUPPORT */ 
            }
            else if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
            {
                aud_get_audio_param_from_nvram_rsp((void*)nvram_param_p);
            }
            else
            {
                ASSERT(0);
            }
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_nvram_write_data_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle nvram write data confirm.
 * PARAMETERS
 *  local_para_ptr      [?]     
 *  peer_buff_ptr       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_nvram_write_data_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *parm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parm_ptr = (nvram_write_cnf_struct*) local_para_ptr;

    /* MED_FUNC_ENTRY(MED_NVRAM_WRITE_DATA_CNF_HDLR) */

    switch (parm_ptr->file_idx)
    {
        case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
            if (!aud_context_p->no_cnf)
            {
                aud_send_set_audio_profile_cnf(MED_RES_OK);
            }
            aud_context_p->no_cnf = KAL_FALSE;
            break;
        case NVRAM_EF_AUDIO_PARAM_LID:
            aud_send_set_audio_param_cnf(MED_RES_OK);
            break;
    #ifdef __AMRWB_LINK_SUPPORT__
        case NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID:
            aud_send_set_audio_wb_input_fir_cnf(MED_RES_OK);
            break;
        case NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID:
            aud_send_set_audio_wb_output_fir_cnf(MED_RES_OK);
            break;
        case NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID:
            aud_send_set_audio_wb_mode_cnf(MED_RES_OK);
            break;
    #endif
        default:
            break;
    }

}

void med_mpl_async_callback_req_hdlr(ilm_struct *ilm_ptr)
{
    media_mpl_async_callback_req_struct* req = (media_mpl_async_callback_req_struct*)ilm_ptr->local_para_ptr;

    /* invoke the callback directly */
    req->callback(req->param);
}

/*****************************************************************************
 * FUNCTION
 *  med_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of media task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    med_context_p->event_scheduler_ptr = evshed_create("MED base timer", MOD_MED, 0, 0 );

#ifdef __MED_CAM_MOD__
    cam_startup_hdlr(ilm_ptr);
#endif 
#ifdef __MED_IMG_MOD__
    img_startup_hdlr(ilm_ptr);
#endif 
#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)
    vid_startup_hdlr(ilm_ptr);
#endif 
#ifdef __MED_WEBCAM_MOD__
    webcam_startup_hdlr(ilm_ptr);
#endif 
#if defined (__MED_TVO_MOD__)
    tvo_startup_hdlr(ilm_ptr);
#endif 

    aud_startup_hdlr(ilm_ptr);

    /* start to read nvram data for media task */
    aud_startup_read_nvram_data();

}


/*****************************************************************************
 * FUNCTION
 *  med_main
 * DESCRIPTION
 *  This function is main message dispatching function of media task.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr->msg_id == MSG_ID_TIMER_EXPIRY)
    {
        med_timer_expiry_hdlr(ilm_ptr);
#if defined(__MED_MTV_MOD__)
        mtv_process_time_out((stack_timer_struct*)ilm_ptr->local_para_ptr);
#endif /* __MED_MTV_MOD__  */

#ifdef __CMMB_CAS_MBBMS_SUPPORT__
        mbbms_timer_expiry_hdlr(ilm_ptr);
#endif
    }
    else if (ilm_ptr->msg_id == MSG_ID_MED_STARTUP_REQ)
    {
        med_startup_hdlr(ilm_ptr);
    }
#ifdef TST_HANDLER
    else if (ilm_ptr->msg_id == MSG_ID_TST_INJECT_STRING)
    {
        aud_tst_handler(ilm_ptr);
    }
#endif /* TST_HANDLER */ 
#ifdef __MED_CAM_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_CAM_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_CAM_CODE_END)
    {
        cam_main(ilm_ptr);
    }
    else if(ilm_ptr->msg_id == MSG_ID_CAL_STARTUP_CNF)
    {
        cam_main(ilm_ptr);
    }
#endif /* __MED_CAM_MOD__ */ 
#ifdef __MED_IMG_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_IMG_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_IMG_CODE_END)
    {
        img_main(ilm_ptr);
    }
#endif /* __MED_IMG_MOD__ */ 
#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)
    else if (ilm_ptr->msg_id >= MSG_ID_MED_VID_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_VID_CODE_END)
    {
        vid_main(ilm_ptr);
    }
    else if (ilm_ptr->msg_id >= MSG_ID_MED_V_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_VISUAL_END)
    {
        vid_main(ilm_ptr);
    }
#endif /* defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__) */
#ifdef __MED_WEBCAM_MOD__
    else if ((ilm_ptr->msg_id >= MSG_ID_MED_WEBCAM_CODE_BEGIN &&
              ilm_ptr->msg_id <= MSG_ID_MED_WEBCAM_CODE_END) ||
             (ilm_ptr->msg_id >= MSG_ID_USB_MED_SET_CAMERA_ATTR_REQ && ilm_ptr->msg_id <= MSG_ID_USB_MED_STOP_CNF))
    {
        webcam_main(ilm_ptr);
    }
#endif /* __MED_WEBCAM_MOD__ */ 
#ifdef __MED_TVO_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_TVO_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_TVO_CODE_END)
    {
        tvo_main(ilm_ptr);
    }
#endif /* __MED_TVO_MOD__ */ 
    else if (ilm_ptr->msg_id == MSG_ID_NVRAM_READ_CNF)
    {
        med_nvram_read_data_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_NVRAM_WRITE_CNF)
    {
        med_nvram_write_data_cnf_hdlr(ilm_ptr->local_para_ptr, ilm_ptr->peer_buff_ptr);
    }
#ifdef __MED_CTM_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_CTM_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_CTM_CODE_END)
    {
        aud_ctm_main(ilm_ptr);
    }
#endif /* __MED_CTM_MOD__ */ 
#ifdef __MED_RTP_MOD__
    else if ((ilm_ptr->msg_id >= MSG_ID_MED_RTP_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_RTP_CODE_END) ||
             (ilm_ptr->msg_id == MSG_ID_APP_SOC_NOTIFY_IND) ||
             (ilm_ptr->msg_id == MSG_ID_APP_CBM_BEARER_INFO_IND))
    {
        rtp_main(ilm_ptr);
    }
#endif /* __MED_RTP_MOD__ */
#ifdef __MED_STREAM_MOD__
    else if ((ilm_ptr->msg_id >= MSG_ID_MED_STREAM_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_STREAM_CODE_END) ||
             (ilm_ptr->msg_id >= RTSP_MSG_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_RTSP_CODE_END) ||
             (ilm_ptr->msg_id >= MSG_ID_MEDIA_V_STREAM_REC_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_V_STREAM_REC_END))
    {
        stream_main(ilm_ptr);
    }
#endif /* __MED_STREAM_MOD__ */
#ifdef __MED_VCALL_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_VCALL_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_VCALL_CODE_END ||
             ilm_ptr->msg_id >= MSG_ID_VT_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_VT_CODE_TAIL ||
             ilm_ptr->msg_id >= MSG_ID_PS_PUBLIC_VT_MSG_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_PS_PUBLIC_VT_MSG_CODE_TAIL)
    {
        vcall_main(ilm_ptr);
    }
#endif /* __MED_VCALL_MOD__ */
#if defined(__MED_MTV_MOD__) || defined(__MED_ATV_MOD__)
    else if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_MTV_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_MTV_CODE_END) ||
             (ilm_ptr->msg_id >= MSG_ID_TDMB_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_TDMB_CODE_END) ||
             (ilm_ptr->msg_id >= MSG_ID_CMMB_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_CMMB_CODE_END) ||
             (ilm_ptr->msg_id >= MSG_ID_ATV_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_ATV_CODE_END))
    {
        mtv_main(ilm_ptr);
    }
#endif /* __MED_MTV_MOD__ || __MED_ATV_MOD__ */
#ifdef __CMMB_CAS_MBBMS_SUPPORT__
    else if(mbbms_main(ilm_ptr))
    {
        /* do nothing */
    }
#endif /* __CMMB_CAS_MBBMS_SUPPORT__ */
#ifdef __MED_BITSTREAM_MOD__
    else if (ilm_ptr->msg_id >= MSG_ID_MED_BITSTREAM_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MED_BITSTREAM_CODE_END)
    {
        bitstream_main(ilm_ptr);
    }
#endif /*__MED_BITSTREAM_MOD__*/
#if (defined(__RESOURCE_MANAGER__) && defined(__MTK_TARGET__))
    else if (ilm_ptr->msg_id == MSG_ID_MEDIA_RM_TIMER_TIMEOUT)
    {
        RMTimerTimeout((void *)(ilm_ptr->local_para_ptr));
    }
#endif //__RESOURCE_MANAGER__
    else
    {
        aud_main(ilm_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_task_main
 * DESCRIPTION
 *  This function is main function of media task.
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void med_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        med_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }

}


#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

/*****************************************************************************
 * FUNCTION
 *  med_init
 * DESCRIPTION
 *  This function is used to init media task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    med_context_p->ext_mem_p = med_ext_mem;
    med_context_p->aud_mem_p = med_aud_mem;
#ifdef __VIDEO_STANDALONE_MEMORY__
    med_context_p->vid_mem_p = med_vid_mem;
#endif

    if (!aud_init())
    {
        return KAL_FALSE;
    }

#ifdef __MED_IMG_MOD__
    if (!img_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_IMG_MOD__ */ 
#ifdef __MED_CAM_MOD__
    if (!cam_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_CAM_MOD__ */ 
#if defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__)
    if (!vid_init())
    {
        return KAL_FALSE;
    }
#endif /* defined(__MED_VID_DEC_MOD__) || defined(__MED_VID_ENC_MOD__) */
#ifdef __MED_WEBCAM_MOD__
    if (!webcam_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_WEBCAM_MOD__ */ 
#if defined (__MED_TVO_MOD__)
    if (!tvo_init())
    {
        return KAL_FALSE;
    }
#endif /* defined (__MED_TVO_MOD__) */ 

    if (!med_utility_init())
    {
        return KAL_FALSE;
    }

#if defined(__MED_ATV_MOD__)
    /* atv need init by MED task */
    if (!mtv_init(task_indx))
    {
        return KAL_FALSE;
    }
#endif // #if defined(__MED_ATV_MOD__)

#ifdef __MED_RTP_MOD__
    if (!rtp_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_RTP_MOD__ */
#ifdef __MED_STREAM_MOD__
    if (!stream_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_STREAM_MOD__ */
#ifdef __STREAM_REC_MOD__
    if (!mtv_bes_init())
    {
        return KAL_FALSE;
    }        
#endif

#ifdef __MED_VCALL_MOD__
    if (!vcall_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_VCALL_MOD__ */
#ifdef __MED_BITSTREAM_MOD__
    if (!bitstream_init())
    {
        return KAL_FALSE;
    }
#endif /* __MED_BITSTREAM_MOD__ */

#if defined(__MTK_INTERNAL__)
#if defined(__MTK_TARGET__) && defined(__RF_DESENSE_TEST__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_TARGET__) && defined(__RF_DESENSE_TEST__) */
#endif /* __MTK_INTERNAL__ */

    return KAL_TRUE;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*****************************************************************************
 * FUNCTION
 *  med_reset
 * DESCRIPTION
 *  This function is used to reset media task.
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_reset(task_indx_type task_indx)
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
 *  med_create
 * DESCRIPTION
 *  This function is used to create media task configuration info.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool med_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct med_handler_info = 
    {
        med_task_main,  /* task entry function */
        med_init,       /* task initialization function */
        NULL,           /* task configuration function */
        med_reset,      /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & med_handler_info;

    return KAL_TRUE;
}
#if defined(__DIRECT_SENSOR_SUPPORT__)   
/*****************************************************************************
 * FUNCTION
 *  med_get_med_int_dcm_mem
 * DESCRIPTION
 *  print result to trace
 * PARAMETERS
 *  result        [IN]      result  
 * RETURNS
 *  void 
 *****************************************************************************/
void med_get_med_dcm_address(kal_uint32* address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    *address = (kal_uint32)med_dcm_int_mem;
}

#endif /* defined(__DIRECT_SENSOR_SUPPORT__)*/
#endif /* MED_NOT_PRESENT */ 

