/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Audio Function (Function Library Provided to Audio Testing functionality)
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * FT task programming rules
 * 1. DO NOT wrap anything with SWITCHABLE feature option
 * 2. DO NOT wrap function call with compile option (wrap inside the handler)
 * 3. DO NOT wrap any chip option
 * 4. DO NOT extern symbol reference (ask the API provider to create interface definition header file)
 * 5. Try NOT TO reference upper layer
 * 6. Always follow the Allman indentation rules (NO tab is allowed, use 4 white-spaces)
 *************************************************************************/


#if (!defined(__SMART_PHONE_MODEM__))
/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "stack_common.h"
#include "app_ltlcom.h"
/*************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_audio.h"
#include "ft_mem.h"
/*************************************************************************
 * Custom header
 *************************************************************************/
#include "meta_customize.h"
/*************************************************************************
 * HAL header
 *************************************************************************/
#include "drv_comm.h"
#include "l1audio.h"
/*************************************************************************
 * HAL header (project specific)
 *************************************************************************/
#if defined(__SPEECH_MODE_TABLE_SUPPORT__)
#include "speech_mode_table.h"
#endif // #if defined(__SPEECH_MODE_TABLE_SUPPORT__)
#if defined(__GAIN_TABLE_SUPPORT__)
#include "gain_table.h"
#endif // #if defined(__GAIN_TABLE_SUPPORT__)
#include "med_aud_hal_struct.h"
/*************************************************************************
 * NVRAM header
 *************************************************************************/
#include "nvram_interface.h"          /* For NVRAM read API definition  */
#include "nvram_editor_data_item.h"   /* For Audio NVRAM structre definition */
/**
 * mutex for recording
 */
kal_mutexid g_rec_mutex = 0;
/***********************
 * wave streaming play
 **********************/
kal_uint16   b_ft_buf_borr_from_med = 0;      // identify the buffer where we allocate from, useful when we release the buffer
kal_uint32   u4_ft_buf_size_alloc = 0;             // the buffer size we allocate for this time: at least 2K bytes
kal_uint8    *p_ft_audio_pcm_buffer = NULL; // the buffer pointer
kal_bool     b_buf_full_first_time = KAL_FALSE;
kal_uint32   u4_ft_valid_buf_len = 0;   // valid when  p_ft_audio_pcm_buffer != NULL
kal_uint8    u1_ft_cur_playing_state = 0;         // 0: not start, 1: playing, 2: finish playing
static kal_bool   b_ft_IsStereo = KAL_FALSE;
static kal_char   i1_ft_BitPerSample = 16;
static kal_uint16 u2_ft_SampleFreq = 8000;
static kal_bool FtAssertionCheckStatement;
#if !defined(MED_NOT_PRESENT)
static kal_uint8  global_output_path = (kal_uint8)AUDIO_DEVICE_LOUDSPEAKER;
#else // #if !defined(MED_NOT_PRESENT)
static kal_uint8  global_output_path = 0;
#endif // #if defined(MED_NOT_PRESENT)
#define      FT_AUD_PLAY_WAVE_NOT_START     0
#define      FT_AUD_PLAY_WAVE_PLAYING       1
#define      FT_AUD_PLAY_WAVE_FINISH        2
#define      FT_AUD_PLAY_WAVE_STOP          3
/*******************************************************************************
 * FUNCTION
 *   FT_InitL4AUD
 *
 * DESCRIPTION
 *   startup L4AUD and set default output device and volume.
 *
 * CALLS
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   g_rec_mutex
 *******************************************************************************/
// Dual-Mic. NR
void FT_InitL4AUD(void)
{
    extern kal_mutexid g_rec_mutex;
    // Dual-Mic. NR
    /* Create mutex if required */
    if (g_rec_mutex == 0)
    {
        g_rec_mutex = kal_create_mutex("ft_record_mutex");
    }
    // MED start up request
#if !defined(MED_NOT_PRESENT)
    {
        // allocate message
        ilm_struct* ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(med_startup_req_struct));
        // FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr)
        FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MED_STARTUP_REQ, ilm_ptr);
    }
#endif // #if defined(MED_NOT_PRESENT)
}
void FtSendAudioAck(kal_uint8 status, kal_uint32 op_code)
{
    ilm_struct* ilm_ptr;
    ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->header.ft_msg_id = FT_L4AUD_CNF_ID;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->l4aud_op = (FT_L4AUD_OP)op_code;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->status = status;
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
}
/*************************************************************
 *                       FT task audio op                    *
 ************************************************************/
#ifndef MED_NOT_PRESENT
kal_uint32 ft_current_med_message_id;
void ft_l4aud_op_audio_play_by_name(const FT_L4AUD_REQ  *l4aud_req, const char *filepath)
{
    ilm_struct      *ilm_ptr;
    // allocate message
    ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_play_by_file_req_struct));
    ((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->volume = ft_gl_l4aud_current_volume;
    ((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->start_offset = 0;
    ((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->end_offset = 0;
    // convert play filepath from char to WCHAR
    kal_wsprintf(((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->file_name, "%s", filepath);
    // set play_style
    ((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->play_style = l4aud_req->req.play.play_style;
    ((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->cache_p = 0;
    ((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->identifier = 0;
    ((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->src_id = 0;
    /**
     * the output_path parameter is used to determine the output deivce for MED playback
     * however, the output_path will be filtered by the current audio mode
     * The correct playback flow for META tool is to
     * 1. set audio mode
     * 2. set output device (output path)
     * 3. play file by name
     */
    ((media_aud_play_by_file_req_struct *)ilm_ptr->local_para_ptr)->output_path = global_output_path;
    FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_PLAY_BY_FILE_REQ, ilm_ptr);
}

void ft_l4aud_op_audio_demo_imy(const FT_L4AUD_REQ  *l4aud_req, kal_char *data, kal_uint16 data_len)
{
    ilm_struct      *ilm_ptr;
    media_aud_play_by_string_req_struct *msg_p;
    // allocate message
    ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_play_by_string_req_struct));
    msg_p = (media_aud_play_by_string_req_struct *)ilm_ptr->local_para_ptr;
    // set default value
    msg_p->src_id = 0;
    msg_p->format = MEDIA_FORMAT_IMELODY;
    msg_p->volume = ft_gl_l4aud_current_volume;
    msg_p->output_path = AUDIO_DEVICE_LOUDSPEAKER;
    msg_p->identifier = 0;
    msg_p->blocking = 0;
    msg_p->start_offset = 0;
    msg_p->end_offset = 0;
    // set iMelody data
    msg_p->melody = (const kal_uint8 *)data;
    // set iMelody length
    msg_p->len = data_len;
    // set play_style
    msg_p->play_style = l4aud_req->req.play.play_style;
    // FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr)
    FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_PLAY_BY_STRING_REQ, ilm_ptr);
}

void ft_l4aud_op_audio_stop(const FT_L4AUD_REQ* l4aud_req)
{
    ilm_struct      *ilm_ptr;
    // allocate message
    ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_stop_req_struct));
    ((media_aud_stop_req_struct *)ilm_ptr->local_para_ptr)->src_id = 0;
    // FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr)
    FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_STOP_REQ, ilm_ptr);
}
void ft_l4aud_op_set_volume(const FT_L4AUD_REQ  *l4aud_req)
{
    ilm_struct      *ilm_ptr;
    unsigned char   volume;
    // allocate message
    ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_set_volume_req_struct));
    // set volume_type to VOL_TYPE_MEDIA. ( audio_type is typing error, wait for AUD author to correct it. )
    ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->audio_type = VOL_TYPE_MEDIA;
    // set apply to kal_true (MUST!!!)
    ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->apply = KAL_TRUE;    
    // check volume range
    if( 6 >= l4aud_req->req.set_volume.volume )
    {
        volume = l4aud_req->req.set_volume.volume;
    }
    else
    {
        volume = 6;
    }
    // save current volume
    ft_gl_l4aud_current_volume = volume;
    // set volume by user request volume level
    ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->volume = volume;
    // set aux_volume by user request volume level
    ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->aux_volume = volume;
    // set mode to 0, don't care
    ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->mode = 0;
    // set blocking to kal_false, don't care
    ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->blocking = KAL_FALSE;     
    FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_SET_VOLUME_REQ, ilm_ptr);
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}
void ft_l4aud_op_set_mode(const FT_L4AUD_REQ  *l4aud_req)
{
    ilm_struct      *ilm_ptr;
    ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_set_audio_mode_req_struct));
    // set src_id
    ((media_aud_set_audio_mode_req_struct *)ilm_ptr->local_para_ptr)->src_id = 0;
    // set mode
    ((media_aud_set_audio_mode_req_struct *)ilm_ptr->local_para_ptr)->mode = l4aud_req->req.set_mode.modeflag;
    // FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr)
    FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_SET_AUDIO_MODE_REQ, ilm_ptr);
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}
void FT_L4Audio_MedConfirm(ilm_struct* ptrMsg)
{
    FT_L4AUD_CNF*   real_cnf = NULL;
    FT_L4AUD_OP     l4aud_op = FT_L4AUD_OP_END;
    ilm_struct*     ilm_ptr  = NULL;
    kal_uint8       result   = 0xFF;
    if( NULL != ft_gl_l4aud_peer_buf )
    {
        free_peer_buff(ft_gl_l4aud_peer_buf);
        ft_gl_l4aud_peer_buf = NULL;
    }
    /* MED START UP related cases (START) */
    if(ptrMsg->msg_id == MSG_ID_MED_STARTUP_CNF)
    {
        // set output device
        {
            // allocate message
            ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_set_device_req_struct));
            // set audio_type to melody
            ((media_aud_set_device_req_struct *)ilm_ptr->local_para_ptr)->audio_type = AUD_TYPE_MELODY;
            // set output device to loud speaker
            ((media_aud_set_device_req_struct *)ilm_ptr->local_para_ptr)->device = L1SP_LOUD_SPEAKER;
            FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_SET_DEVICE_REQ, ilm_ptr);
        }
        return;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_SET_DEVICE_CNF)
    {
        // set volume
        {
            // allocate message
            ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_set_volume_req_struct));
            // set volume_type to VOL_TYPE_MEDIA. ( audio_type is typing error, wait for AUD author to correct it. )
            ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->audio_type = VOL_TYPE_MEDIA;
            // set current volume to mid level
            ft_gl_l4aud_current_volume = 3;
            // set volume
            ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->volume = ft_gl_l4aud_current_volume;
            // set aux_volume
            ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->aux_volume = ft_gl_l4aud_current_volume;
            // set mode to 0, don't care
            ((media_aud_set_volume_req_struct *)ilm_ptr->local_para_ptr)->mode = 0;
            FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_SET_VOLUME_REQ, ilm_ptr);
        }
        return;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_SET_VOLUME_CNF)
    {
        return;
    }
    /* MED START UP related cases (END) */
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_PLAY_BY_STRING_CNF)
    {
        media_aud_play_by_string_cnf_struct* cnf = (media_aud_play_by_string_cnf_struct*) ptrMsg->local_para_ptr;
        ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
        ft_gl_token = ft_gl_l4aud_token;
        l4aud_op = FT_L4AUD_OP_AUDIO_DEMO_IMY;
        result = cnf->result;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_PLAY_FINISH_IND)
    {
        media_aud_play_finish_ind_struct* cnf = (media_aud_play_finish_ind_struct*) ptrMsg->local_para_ptr;
        ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
        ft_gl_token = ft_gl_l4aud_ind_token;
        l4aud_op = FT_L4AUD_OP_AUDIO_PLAY_OVER_IND;
        result = cnf->result;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_STOP_CNF)
    {
        media_aud_stop_cnf_struct* cnf = (media_aud_stop_cnf_struct*) ptrMsg->local_para_ptr;
        ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
        ft_gl_token = ft_gl_l4aud_token;
        l4aud_op = FT_L4AUD_OP_AUDIO_STOP;
        result = cnf->result;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_PLAY_BY_FILE_CNF)
    {
        media_aud_play_by_file_cnf_struct* cnf = (media_aud_play_by_file_cnf_struct*) ptrMsg->local_para_ptr;
        ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
        ft_gl_token = ft_gl_l4aud_token;
        l4aud_op = FT_L4AUD_OP_AUDIO_PLAY_BY_NAME;
        result = cnf->result;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_CNF)
    {
        kal_uint16 i;
        media_aud_get_audio_profile_cnf_struct* cnf = (media_aud_get_audio_profile_cnf_struct *) ptrMsg->local_para_ptr;
        ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
        ft_gl_token = ft_gl_l4aud_ind_token;
        l4aud_op    = FT_L4AUD_OP_GET_PROFILE_SETTINGS_BY_MODE;
        real_cnf    = (FT_L4AUD_CNF*) ilm_ptr->local_para_ptr;
        real_cnf->status = (cnf->result == KAL_TRUE)? FT_CNF_OK : FT_CNF_FAIL;
        real_cnf->cnf.get_profile_cnf.mode = cnf->audio_profile.mode;
        real_cnf->cnf.get_profile_cnf.sidetone = cnf->audio_profile.sidetone;
        real_cnf->cnf.get_profile_cnf.max_melody_volume_gain = cnf->audio_profile.max_melody_volume_gain;
        real_cnf->cnf.get_profile_cnf.melody_volume_gain_step = cnf->audio_profile.melody_volume_gain_step;
        for(i=0;i<7;i++)
        {
            real_cnf->cnf.get_profile_cnf.melody[i] = cnf->audio_profile.melody[i];
            real_cnf->cnf.get_profile_cnf.sound[i] = cnf->audio_profile.sound[i];
            real_cnf->cnf.get_profile_cnf.keytone[i] = cnf->audio_profile.keytone[i];
            real_cnf->cnf.get_profile_cnf.speech[i] = cnf->audio_profile.speech[i];
            real_cnf->cnf.get_profile_cnf.mic[i] = cnf->audio_profile.mic[i];
            real_cnf->cnf.get_profile_cnf.tv_out_volume_gain[i] = cnf->audio_profile.tv_out_volume_gain[i];
        }
        result = (cnf->result == KAL_TRUE) ? FT_CNF_OK : FT_CNF_FAIL;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_CNF)
    {
        media_aud_set_audio_param_cnf_struct* cnf =(media_aud_set_audio_param_cnf_struct*) ptrMsg->local_para_ptr;
        ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
        ft_gl_token = ft_gl_l4aud_ind_token;
        l4aud_op    = FT_L4AUD_OP_SET_PROFILE_SETTINGS_BY_MODE;
        result      = (cnf->result == KAL_TRUE) ? FT_CNF_OK : FT_CNF_FAIL;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_CNF)
    {
        media_aud_get_audio_param_cnf_struct* cnf = (media_aud_get_audio_param_cnf_struct*) ptrMsg->local_para_ptr;
        ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
        ft_gl_token = ft_gl_l4aud_ind_token;
        l4aud_op    = FT_L4AUD_OP_GET_PARAM_SETTINGS_0809;
        real_cnf = (FT_L4AUD_CNF*) ilm_ptr->local_para_ptr;
        real_cnf->header.ft_msg_id = FT_L4AUD_CNF_ID;
        real_cnf->status = (cnf->result == KAL_TRUE)? FT_CNF_OK : FT_CNF_FAIL;
        real_cnf->l4aud_op = FT_L4AUD_OP_GET_PARAM_SETTINGS_0809;
        kal_mem_cpy(&(real_cnf->cnf.get_param_cnf_0809), &(cnf->audio_param),sizeof(ft_l4aud_get_param_cnf_0809));
        result = (cnf->result == KAL_TRUE) ? FT_CNF_OK : FT_CNF_FAIL;
    }
    else if(ptrMsg->msg_id == MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_CNF)
    {
        media_aud_set_audio_param_cnf_struct* cnf =(media_aud_set_audio_param_cnf_struct*) ptrMsg->local_para_ptr;
        ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
        ft_gl_token = ft_gl_l4aud_ind_token;
        l4aud_op    = FT_L4AUD_OP_SET_PARAM_SETTINGS_0809;
        result      = (cnf->result == KAL_TRUE) ? FT_CNF_OK : FT_CNF_FAIL;
    }
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->header.ft_msg_id = FT_L4AUD_CNF_ID;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->l4aud_op = l4aud_op;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->status = result;
    /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
}
void ft_l4aud_op_get_profile_by_mode(const FT_L4AUD_REQ  *l4aud_req)
{
    ilm_struct      *ilm_ptr;
    // allocate message
    ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_get_audio_profile_req_struct));
    ((media_aud_get_audio_profile_req_struct *)ilm_ptr->local_para_ptr)->src_id = 0;
    ((media_aud_get_audio_profile_req_struct *)ilm_ptr->local_para_ptr)->mode = l4aud_req->req.get_profile_by_mode.m_ucMode;
    FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_REQ, ilm_ptr);
}
void ft_l4aud_op_set_profile_by_mode(const FT_L4AUD_REQ  *l4aud_req)
{
    ilm_struct      *ilm_ptr;
    kal_uint8 i;
    media_aud_set_audio_profile_req_struct *real_req ;
    // allocate message
    ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_set_audio_profile_req_struct));
    real_req = (media_aud_set_audio_profile_req_struct*) ilm_ptr->local_para_ptr;
    real_req->src_id = 0;
    real_req->update_nvram = KAL_FALSE; // only update L1audio settings, don't update to NVRAM.
    //kal_mem_cpy(&(real_req->audio_profile), &(l4aud_req->req.set_profile_by_mode),sizeof(audio_profile_struct));
    real_req->audio_profile.mode = l4aud_req->req.set_profile_by_mode.mode;
    real_req->audio_profile.sidetone = l4aud_req->req.set_profile_by_mode.sidetone;
    real_req->audio_profile.max_melody_volume_gain = l4aud_req->req.set_profile_by_mode.max_melody_volume_gain;
    real_req->audio_profile.melody_volume_gain_step = l4aud_req->req.set_profile_by_mode.melody_volume_gain_step;
    for(i=0;i<7;i++)
    {
        real_req->audio_profile.melody[i] = l4aud_req->req.set_profile_by_mode.melody[i];
        real_req->audio_profile.sound[i] = l4aud_req->req.set_profile_by_mode.sound[i];
        real_req->audio_profile.keytone[i] = l4aud_req->req.set_profile_by_mode.keytone[i];
        real_req->audio_profile.speech[i] = l4aud_req->req.set_profile_by_mode.speech[i];
        real_req->audio_profile.mic[i] = l4aud_req->req.set_profile_by_mode.mic[i];
        real_req->audio_profile.tv_out_volume_gain[i] = l4aud_req->req.set_profile_by_mode.tv_out_volume_gain[i];
    }
    FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_REQ, ilm_ptr);
}
void ft_l4aud_op_get_param_0809(const FT_L4AUD_REQ  *l4aud_req)
{
    ilm_struct      *ilm_ptr;
    // send message to MED task
    ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_get_audio_param_req_struct));
    ((media_aud_get_audio_param_req_struct *)ilm_ptr->local_para_ptr)->src_id = 0;
    FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_REQ, ilm_ptr);
}

void ft_l4aud_op_set_param_0809(const FT_L4AUD_REQ  *l4aud_req)
{
    ilm_struct      *ilm_ptr;
    media_aud_set_audio_param_req_struct *real_req ;
    {
        // send message to MED task
        ilm_ptr = FT_ALLOC_OTHER_MSG(sizeof(media_aud_set_audio_param_req_struct));
        real_req = (media_aud_set_audio_param_req_struct*) ilm_ptr->local_para_ptr;
        real_req->src_id = 0;
        real_req->update_nvram = KAL_FALSE; // only update L1audio settings, don't update to NVRAM.
        kal_mem_cpy( &(real_req->audio_param), &(l4aud_req->req.set_param_0809), sizeof(audio_param_struct));
        FT_SEND_MSG(MOD_FT, MOD_MED, MED_SAP, MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_REQ, ilm_ptr);
    }
}
void FT_L4Audio_MedOperation(ilm_struct *ptrMsg)
{
    kal_char*           pdu_ptr;
    kal_uint8           err_code = FT_CNF_FAIL;
    kal_uint16          i;
    kal_uint16          pdu_length;
    FT_L4AUD_REQ*       l4aud_req=((FT_L4AUD_REQ *)ptrMsg->local_para_ptr);
    peer_buff_struct*   peer_buff_in=ptrMsg->peer_buff_ptr;
    switch(l4aud_req->l4aud_op)
    {
        case FT_L4AUD_OP_AUDIO_PLAY_BY_NAME:
        {
            if( NULL == peer_buff_in )
            {
                // peer_buf is NULL
                err_code = FT_L4AUD_ERR_PEER_BUF_ERROR;
                break;
            }
            pdu_ptr = get_pdu_ptr( peer_buff_in, &pdu_length );
            if( NULL==pdu_ptr || 0==pdu_length )
            {
                // pdu_ptr is NULL, or pdu_length is zero
                err_code = FT_L4AUD_ERR_PEER_BUF_ERROR;
                break;
            }
            if( FT_L4AUD_MAX_MELODY_FILE_NAME < pdu_length )
            {
                // filepath too long
                err_code = FT_L4AUD_ERR_FILEPATH_TOO_LONG;
                break;
            }
            for(i=0; i<pdu_length; i++)
            {
                if( '\0' == pdu_ptr[i] )
                {
                    break;
                }
            }
            if( i == pdu_length )
            {
                // filepath without terminated
                err_code = FT_L4AUD_ERR_FILEPATH_ERROR;
                break;
            }
            // store l4aud token id, because when play finish we will need this token to send back PC.
            ft_gl_l4aud_ind_token = l4aud_req->header.token;
            ft_l4aud_op_audio_play_by_name(l4aud_req, pdu_ptr);
            return;
        }
        case FT_L4AUD_OP_AUDIO_DEMO_IMY:
        {
            if( NULL == peer_buff_in )
            {
                // peer_buf is NULL
                err_code = FT_L4AUD_ERR_PEER_BUF_ERROR;
                break;
            }
            pdu_ptr = get_pdu_ptr( peer_buff_in, &pdu_length );
            if( NULL==pdu_ptr || 0==pdu_length )
            {
                // pdu_ptr is NULL, or pdu_length is zero
                err_code = FT_L4AUD_ERR_PEER_BUF_ERROR;
                break;
            }
            // check if previous peer buf is still in used
            if( NULL != ft_gl_l4aud_peer_buf )
            {
                err_code = FT_L4AUD_ERR_STILL_PLAYING;
                break;
            }
            // save the peer buf pointer, free it when receive play finish indication message
            ft_gl_l4aud_peer_buf = peer_buff_in;
            // store l4aud token id, because when play finish we will need this token to send back PC.
            ft_gl_l4aud_ind_token = l4aud_req->header.token;
            ft_l4aud_op_audio_demo_imy(l4aud_req, pdu_ptr, pdu_length);
            // directly pass peer buffer to L4AUD when play iMelody by buffer
            // set peer buf pointer to NULL to avoid thie buffer will be released by free_ilm()
            ptrMsg->peer_buff_ptr = NULL;
            return;
        }
        case FT_L4AUD_OP_AUDIO_STOP:
        {
            ft_l4aud_op_audio_stop(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_VOLUME:
        {
            ft_l4aud_op_set_volume(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_MODE:
        {
            ft_l4aud_op_set_mode(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_GET_PROFILE_SETTINGS_BY_MODE:
        {
            // store l4aud token id, because when play finish we will need this token to send back PC.
            ft_gl_l4aud_ind_token = l4aud_req->header.token;
            ft_l4aud_op_get_profile_by_mode(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_PROFILE_SETTINGS_BY_MODE:
        {
            ft_gl_l4aud_ind_token = l4aud_req->header.token;
            ft_l4aud_op_set_profile_by_mode(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_GET_PARAM_SETTINGS_0809:
        {
            ft_gl_l4aud_ind_token = l4aud_req->header.token;
            ft_l4aud_op_get_param_0809(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_PARAM_SETTINGS_0809:
        {
            ft_gl_l4aud_ind_token = l4aud_req->header.token;
            ft_l4aud_op_set_param_0809(l4aud_req);
            return;
        }
        default:
            break;	
    }
    FtSendAudioAck(err_code, l4aud_req->l4aud_op);
}
#else // #ifndef MED_NOT_PRESENT
void FT_L4Audio_MedConfirm(ilm_struct* ilm_ptr)
{
}
void FT_L4Audio_MedOperation(ilm_struct* ptrMsg)
{
}
#endif // #ifdef MED_NOT_PRESENT

static kal_uint8 ft_l4aud_op_set_echo(const FT_L4AUD_REQ  *l4aud_req)
{
    // use the same operation in engineer mode
    if(l4aud_req->req.set_echo.echoflag > 0)
    {
        L1SP_SetAfeLoopback(KAL_TRUE);
        L1SP_Speech_On(0);
        L1SP_MuteMicrophone(KAL_FALSE);
    }
    else
    {
        L1SP_SetAfeLoopback(KAL_FALSE);
        L1SP_Speech_Off();
        L1SP_MuteMicrophone(KAL_TRUE);
    }
    // send confirm to PC
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
    return 0;
}
/*****************************************************************************
 * FUNCTION
 *  ft_custom_em_set_gain
 * DESCRIPTION
 *
 * PARAMETERS
 *  type        [IN]
 *  gain        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void ft_custom_em_set_gain(kal_uint8 type, kal_uint8 gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case FT_L4AUD_VOL_TYPE_TONE:
            TONE_SetOutputVolume(gain, 0);
            break;
        case FT_L4AUD_VOL_TYPE_KT:
            KT_SetOutputVolume(gain, 0);
            break;
        case FT_L4AUD_VOL_TYPE_MIC:
            L1SP_SetMicrophoneVolume(gain);
            break;
        case FT_L4AUD_VOL_TYPE_SPH:
            L1SP_SetOutputVolume(gain, 0);
            break;
        case FT_L4AUD_VOL_TYPE_SID:
            L1SP_SetSidetoneVolume(gain);
            break;
        case FT_L4AUD_VOL_TYPE_MEDIA:
            Media_SetOutputVolume(gain, 0);
            break;
        default:
            break;
    }

}
static void ft_l4aud_op_set_gain(const FT_L4AUD_REQ  *l4aud_req)
{
    ft_custom_em_set_gain((kal_uint8)l4aud_req->req.set_gain.type, (kal_uint8)l4aud_req->req.set_gain.gain);
    // send confirm to PC
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}

//for AEC part, only support MT622X series
static void ToneLoopBackRec_cb( kal_uint8 buf[2000], kal_uint16 mode)
{
    ilm_struct       *ilm_ptr;
    ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->header.ft_msg_id = FT_L4AUD_CNF_ID;
    if(mode == 0) // normal mode
    {
        ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->l4aud_op = FT_L4AUD_OP_TONE_LOOP_BACK_REC_2K_NORMAL;
    }
    else // loud-speaker mode
    {
        ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->l4aud_op = FT_L4AUD_OP_TONE_LOOP_BACK_REC_2K;
    }
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->status = FT_CNF_OK;
    kal_mem_cpy(((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.tone_loopbackrec_cnf_2k.buffer, buf, 2000); // 500*4 = 2000 bytes
    free_ctrl_buffer(buf);
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
}

/**
 * @param mode 0: Normal Mode, 1: Loud Speaker Mode
 */
static void ft_l4aud_op_tone_loopbackrec(const FT_L4AUD_REQ *l4aud_req, kal_uint16 mode)
{
    ToneLBR_Para  tone;
    kal_uint32 *pToneBuf;
    pToneBuf = (kal_uint32*) get_ctrl_buffer(2000);  // since at most 2k bytes
    if(NULL == pToneBuf)
    {
        ASSERT(pToneBuf);
    }
    tone.pBuf=(kal_uint8 *)pToneBuf; //&g_toneLBR_Buf[0];
    tone.uSize = 2000;
    tone.bAnalogSpkGain=l4aud_req->req.tone_loopbackrec.spkgain;
    tone.uAnalogMicGain=l4aud_req->req.tone_loopbackrec.micgain;
    tone.uFreq=l4aud_req->req.tone_loopbackrec.fre;
    tone.uUL_DigGain=l4aud_req->req.tone_loopbackrec.ulgain;
    tone.uDL_DigGain=l4aud_req->req.tone_loopbackrec.dlgain;
    tone.uKT_AMP=l4aud_req->req.tone_loopbackrec.amp;//0x3FFF;
    tone.uMode = mode;
    ToneLoopBackRec(ToneLoopBackRec_cb,&tone);
}
static void ft_l4aud_op_set_loudspk_fir(const FT_L4AUD_REQ  *l4aud_req)
{
    L1SP_Write_Audio_Coefficients(l4aud_req->req.set_loudspk_fir_coeffs.in_fir_coeffs,l4aud_req->req.set_loudspk_fir_coeffs.out_fir_coeffs);
    // replace this API with HAL interface
    L1SP_SetFIR(KAL_TRUE);
    // send confirm to PC
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}

static void ft_l4aud_op_set_speech_common(FT_L4AUD_REQ  *l4aud_req)
{
    L1SP_LoadCommonSpeechPara(l4aud_req->req.set_speech_common.speech_common_para);
    // send confirm to PC
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}

static void ft_l4aud_op_set_loudspk_mode(FT_L4AUD_REQ  *l4aud_req)
{
    L1SP_UpdateSpeechPara(l4aud_req->req.set_loudSpk_mode.speech_loudspk_mode_para);
    // send confirm to PC
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}

static void ft_l4aud_op_set_melody_fir(const FT_L4AUD_REQ  *l4aud_req)
{
    Media_SetMelodyFilter( 25, l4aud_req->req.set_melody_fir_output_coeffs.Melody_FIR_Output_Coeff_32k_Tbl1);
    // send confirm to PC
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}

static void ft_l4aud_op_set_speech_common_and_mode( FT_L4AUD_REQ  *l4aud_req)
{
    L1SP_LoadCommonSpeechPara(l4aud_req->req.set_speech_common_and_mode.speech_common_para);
    L1SP_UpdateSpeechPara(l4aud_req->req.set_speech_common_and_mode.speech_loudspk_mode_para);
    L1SP_LoadSpeechPara();
    // send confirm to PC
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}

static void ft_l4aud_op_set_max_swing(const FT_L4AUD_REQ  *l4aud_req)
{
    Media_Control(MEDIA_CTRL_MAX_SWING, l4aud_req->req.set_playback_maximum_swing.Media_Playback_Maximum_Swing);
    // send confirm to PC
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}

/**
 *
 */
void ft_free_pcm_buffer(void **p, kal_uint16 indicator)
{
    // free the buffer we allocate
    if(*p != NULL)
    {
        if(indicator == 1) // free the buffer we borrow from MED task
        {
            FtFreeExtMemory(*p);
        }
        else // free the control buffer
        {
            free_ctrl_buffer(*p);
        }
        *p = NULL;
        u4_ft_valid_buf_len= 0;
    }
}
/**
 * allocate buffer for PCM
 */
static void ft_allocate_pcm_buffer(kal_bool allocate_from_med, void** buffer_ptr, kal_uint16 *indicator, kal_uint32 *valid_buf_len, kal_uint32 *buf_size, kal_uint32 prefered_size)
{
    kal_uint8* _ft_audio_pcm_buffer = NULL;
    *valid_buf_len = 0;
    if(allocate_from_med)
    {
        kal_uint32 med_size = 0;
        med_size = FtGetLeftExtMemory();
        if(med_size > prefered_size)
        {
            *buf_size = prefered_size;
        }
        _ft_audio_pcm_buffer = (kal_uint8*) FtAllocExtMemory(*buf_size);
        *indicator = 1;
    }
    else
    {
        if(prefered_size > 2048)
        {
            *buf_size = 2048;
        }
        else
        {
            *buf_size = prefered_size;
        }
        _ft_audio_pcm_buffer = (kal_uint8*) get_ctrl_buffer(*buf_size);  // since at most 2k bytes
        *indicator = 0;
    }
    *buffer_ptr = (void*)_ft_audio_pcm_buffer;
    ASSERT(*buffer_ptr);
}
/*
 * for play wave
 */
static void FT_Recv_Indication_From_l1Audio(MHdl *mhdl_handle, Media_Event event)
{
    if (event == MEDIA_END)
    {
        ilm_struct *audio_ilm;
        DRV_BuildPrimitive(audio_ilm,
                MOD_L1SP,
                MOD_FT,
                (msg_type)MEDIA_END,
                NULL);
        msg_send_ext_queue(audio_ilm);
    }
}

// 0: not playing, or play finished
// 1: pause
MHdl* pMhdlHandle = NULL;
/**
 * handler of audio play wave event
 */
void ft_audio_play_wave_event_callback(ilm_struct *ptrMsg)
{
    if(ptrMsg->msg_id == MEDIA_END)
    {
        if(pMhdlHandle != NULL)
        {
            pMhdlHandle->Stop(pMhdlHandle);
            pMhdlHandle->Close(pMhdlHandle);
            pMhdlHandle = NULL;
            // mark current state: finished playing
            u1_ft_cur_playing_state = FT_AUD_PLAY_WAVE_FINISH;
        }
    }
}
static kal_int8 ft_l4aud_op_play_wave_file(const FT_L4AUD_REQ  *l4aud_req)
{
#if defined(WAV_CODEC) && !defined(__L1_STANDALONE__)
    kal_uint8 *pBuf;
    kal_uint32 bufLen, fillLen=0;
    kal_int8 ret_code = 0;
    kal_uint16 fill_buf_len = 0;
    kal_uint8  wait_trial_times = 0;
    kal_uint8  i = 0;
    if(l4aud_req->req.play_wave_req.u4FrmIdx == 0)
    {
        // b_ft_fill_buf_now = KAL_TRUE; // can fill the buffer!
        u1_ft_cur_playing_state = FT_AUD_PLAY_WAVE_NOT_START;
        b_buf_full_first_time = KAL_FALSE;
        u4_ft_valid_buf_len = 0; // the first frame!
    }
    // check if need to stop (terminate by PC-side users)
    if(l4aud_req->req.play_wave_req.bStop && pMhdlHandle != NULL )
    {
        // stop current playing
        pMhdlHandle->DataFinished(pMhdlHandle);

        if(u1_ft_cur_playing_state == FT_AUD_PLAY_WAVE_PLAYING) // now is playing
        {
            // must wait for  the callback is invoked
            wait_trial_times = 10;
            goto wait_for_l1aduio_stop;
        }
        else
        {
            // Note: need to check with Eddy.Wu
            pMhdlHandle->Stop(pMhdlHandle);
            pMhdlHandle->Close(pMhdlHandle); // will set the handle to be KAL_FALSE
            pMhdlHandle = NULL;
            goto return_now;
        }
    }
    if(p_ft_audio_pcm_buffer == NULL)
    {
        ft_allocate_pcm_buffer(l4aud_req->req.play_wave_req.bBorrowMed, (void**)&p_ft_audio_pcm_buffer, &b_ft_buf_borr_from_med, &u4_ft_valid_buf_len, &u4_ft_buf_size_alloc,
                FtGetLeftExtMemory() / 2
                );
    }
    {
        if(pMhdlHandle == NULL)
        {
            Media_PCM_Stream_Param pcm_param;
            pcm_param.isStereo = l4aud_req->req.play_wave_req.bIsStereo;
            pcm_param.bitPerSample = l4aud_req->req.play_wave_req.i1BitPerSample;
            pcm_param.sampleFreq = l4aud_req->req.play_wave_req.u2SampleFreq;
            b_ft_IsStereo = l4aud_req->req.play_wave_req.bIsStereo;
            i1_ft_BitPerSample = l4aud_req->req.play_wave_req.i1BitPerSample;
            u2_ft_SampleFreq = l4aud_req->req.play_wave_req.u2SampleFreq;
            pcm_param.forceVoice = KAL_TRUE;
            pMhdlHandle = PCM_Strm_Open(FT_Recv_Indication_From_l1Audio, &pcm_param);
            pMhdlHandle->SetBuffer(pMhdlHandle, p_ft_audio_pcm_buffer, u4_ft_buf_size_alloc);
        }
        while(fill_buf_len < l4aud_req->req.play_wave_req.u4BufLen)
        {
            pMhdlHandle->GetWriteBuffer(pMhdlHandle,&pBuf, &bufLen);
            if(bufLen >= l4aud_req->req.play_wave_req.u4BufLen - fill_buf_len)
            {
                kal_mem_cpy(pBuf, l4aud_req->req.play_wave_req.buf+fill_buf_len, l4aud_req->req.play_wave_req.u4BufLen-fill_buf_len);
                fillLen = l4aud_req->req.play_wave_req.u4BufLen - fill_buf_len;
                fill_buf_len += fillLen; //(l4aud_req->req.play_wave_req.u4BufLen - fill_buf_len);
                //sleep_time = l4aud_req->req.play_wave_req.i1SleepTime;

                // it is a last frame
                if(l4aud_req->req.play_wave_req.bLastFrm)
                    b_buf_full_first_time = KAL_TRUE;
            }
            else if(bufLen > 0) // buffer space is not enough now
            {
                kal_mem_cpy(pBuf, l4aud_req->req.play_wave_req.buf + fill_buf_len, bufLen);
                fillLen = bufLen;//l4aud_req->req.play_wave_req.u4BufLen - bufLen;
                fill_buf_len += fillLen; //(l4aud_req->req.play_wave_req.u4BufLen - bufLen);
                //sleep_time = l4aud_req->req.play_wave_req.i1SleepTime;

                b_buf_full_first_time = KAL_TRUE;

            }
            if(bufLen == 0)
            {
                kal_sleep_task(1);
            }
            if(bufLen >0)
            {
                if(u4_ft_valid_buf_len <= u4_ft_buf_size_alloc)
                {
                    u4_ft_valid_buf_len += fillLen;
                }
                else
                {
                    u4_ft_valid_buf_len = 0;
                }
                pMhdlHandle->WriteDataDone(pMhdlHandle,fillLen);
                pMhdlHandle->waiting = KAL_FALSE;
            }
            if( b_buf_full_first_time && u1_ft_cur_playing_state == FT_AUD_PLAY_WAVE_NOT_START)
            {
                pMhdlHandle->Play(pMhdlHandle);
                u1_ft_cur_playing_state = FT_AUD_PLAY_WAVE_PLAYING;
                b_buf_full_first_time = KAL_FALSE;
            }
        }
        if(l4aud_req->req.play_wave_req.bLastFrm == KAL_TRUE)
        {
            pMhdlHandle->DataFinished(pMhdlHandle);
            if(u1_ft_cur_playing_state == FT_AUD_PLAY_WAVE_PLAYING) // now is playing
            {
                // must wait for  the callback is invoked
                wait_trial_times = 100;
                goto wait_for_l1aduio_stop;
            }

        }
    }

wait_for_l1aduio_stop:
    i = 0;
    while(i <= wait_trial_times)
    {
        if(u1_ft_cur_playing_state == FT_AUD_PLAY_WAVE_FINISH)
            break;
        kal_sleep_task(5);
        i++;
    }
return_now:
    return ret_code;
#else //  #if defined(WAV_CODEC) && !defined(__L1_STANDALONE__)
    return 0;
#endif // !(#if defined(WAV_CODEC) && !defined(__L1_STANDALONE__))
}
/**
 * set ac coefficicent
 * Note: the parameter MUST not be const
 */
static void ft_l4aud_op_set_ac_coef(FT_L4AUD_REQ *l4aud_req)
{
#if defined(AUDIO_COMPENSATION_ENABLE) && !defined(__SMART_PHONE_MODEM__)
    if(l4aud_req->req.set_ac_filter_req.u1_ac_mode == 0)
    {
        ACF_SetFilterCoeff(l4aud_req->req.set_ac_filter_req.i2_ac_coef, MEDIA_ACF_LoudSpeaker_mode);
    }
    else if(l4aud_req->req.set_ac_filter_req.u1_ac_mode == 1)
    {
        ACF_SetFilterCoeff(l4aud_req->req.set_ac_filter_req.i2_ac_coef, MEDIA_ACF_Earphone_mode);
    }
    else
    {
        ACF_SetFilterCoeff(l4aud_req->req.set_ac_filter_req.i2_ac_coef, MEDIA_ACF_LoudSpeaker_Ringtone_mode);
    }
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
#endif // #if defined(AUDIO_COMPENSATION_ENABLE) && !defined(__SMART_PHONE_MODEM__)
}
static void ft_l4aud_op_get_ac_coef_type(const FT_L4AUD_REQ  *l4aud_req)
{
#if defined(AUDIO_COMPENSATION_ENABLE) && !defined(__SMART_PHONE_MODEM__)
    ilm_struct     *ilm_ptr;
    kal_uint8      u1_filter_type = 0;
    MEDIA_ACF_Filter_Type e_type = ACF_GetFilterType();
    switch(e_type)
    {
        case MEDIA_ACF_DSP_FIR:
            u1_filter_type = FT_L4AUD_AC_FILTER_DSP_FIR;
            break;
        case MEDIA_ACF_HW_FIR:
            u1_filter_type = FT_L4AUD_AC_FILTER_HW_FIR;
            break;
        case MEDIA_ACF_DSP_IIR:
            u1_filter_type = FT_L4AUD_AC_FILTER_DSP_IIR;
            break;
        default:
            u1_filter_type = FT_L4AUD_AC_FILTER_UNKNOWN;
            break;
    }
    ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->header.ft_msg_id = FT_L4AUD_CNF_ID;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->l4aud_op = l4aud_req->l4aud_op;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->status = FT_CNF_OK;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.get_ac_filter_cnf.u1_filter_type = u1_filter_type;
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
#endif // #if defined(AUDIO_COMPENSATION_ENABLE) && !defined(__SMART_PHONE_MODEM__)
}
void ft_l4aud_op_play_wave_file_by_stream(const FT_L4AUD_REQ* l4aud_req)
{
    ilm_struct* ilm_ptr;
    kal_int8    ret_code = ft_l4aud_op_play_wave_file(l4aud_req);
    ilm_ptr = FT_ALLOC_MSG(sizeof(FT_L4AUD_CNF));
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->header.ft_msg_id = FT_L4AUD_CNF_ID;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->l4aud_op = l4aud_req->l4aud_op;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->status = ret_code;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.play_wave_cnf.u4TargetBufSize = u4_ft_buf_size_alloc;
    if(u1_ft_cur_playing_state == FT_AUD_PLAY_WAVE_PLAYING)
    {
        ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.play_wave_cnf.bStartPlay = KAL_TRUE;
    }
    else
    {
        ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.play_wave_cnf.bStartPlay = KAL_FALSE;
    }
    if(u1_ft_cur_playing_state == FT_AUD_PLAY_WAVE_FINISH)
    {
        ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.play_wave_cnf.bStopPlay = KAL_TRUE;
    }
    else
    {
        ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.play_wave_cnf.bStopPlay = KAL_FALSE;
    }
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.play_wave_cnf.u4FrmIdx =l4aud_req->req.play_wave_req.u4FrmIdx;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.play_wave_cnf.offset =l4aud_req->req.play_wave_req.offset;
    ((FT_L4AUD_CNF *)ilm_ptr->local_para_ptr)->cnf.play_wave_cnf.u4BytesSent =l4aud_req->req.play_wave_req.u4BytesSent;
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
}
void ft_l4aud_op_free_memory(const FT_L4AUD_REQ* l4aud_req)
{
    if(p_ft_audio_pcm_buffer)
    {
        ft_free_pcm_buffer((void**)&p_ft_audio_pcm_buffer, b_ft_buf_borr_from_med);
    }
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}
void ft_l4aud_op_play_cur_memory_content(const FT_L4AUD_REQ* l4aud_req)
{
#if defined(WAV_CODEC) && !defined(__L1_STANDALONE__)
    kal_uint8 err_code;
    if(u4_ft_valid_buf_len !=0 && pMhdlHandle == NULL && p_ft_audio_pcm_buffer != NULL)
    {
        Media_PCM_Stream_Param pcm_param;
        pcm_param.isStereo = b_ft_IsStereo;
        pcm_param.bitPerSample = i1_ft_BitPerSample;
        pcm_param.sampleFreq = u2_ft_SampleFreq;
        pcm_param.forceVoice = KAL_TRUE;
        //pMhdlHandle = PCM_Strm_Open(ft_audio_play_wave_event_callback, &pcm_param);
        pMhdlHandle = PCM_Strm_Open(FT_Recv_Indication_From_l1Audio, &pcm_param);
        pMhdlHandle->SetBuffer(pMhdlHandle, p_ft_audio_pcm_buffer, u4_ft_buf_size_alloc);
        pMhdlHandle->WriteDataDone(pMhdlHandle,u4_ft_valid_buf_len);
        pMhdlHandle->waiting = KAL_FALSE;
        pMhdlHandle->Play(pMhdlHandle);
        u1_ft_cur_playing_state = FT_AUD_PLAY_WAVE_PLAYING;
        pMhdlHandle->DataFinished(pMhdlHandle);
        err_code = FT_CNF_OK;
    }
    else
    {
        err_code = FT_CNF_FAIL;
    }
    FtSendAudioAck(err_code, l4aud_req->l4aud_op);
#endif // #if defined(WAV_CODEC) && !defined(__L1_STANDALONE__)
}
void ft_l4aud_op_stop_l1aud_playing(const FT_L4AUD_REQ* l4aud_req)
{
    // check if need to stop (terminate by PC-side users)
    if(pMhdlHandle != NULL )
    {
        // stop current playing
        if(u1_ft_cur_playing_state == FT_AUD_PLAY_WAVE_PLAYING) // now is playing
        {
            pMhdlHandle->Stop(pMhdlHandle);
            pMhdlHandle->Close(pMhdlHandle);
            pMhdlHandle = NULL;
            u1_ft_cur_playing_state = FT_AUD_PLAY_WAVE_STOP;
        }
    }
    FtSendAudioAck(FT_CNF_OK, l4aud_req->l4aud_op);
}
/**
 * L4Audio Command handler function
 * The function will send message at the end of the function
 * if the opcode handler sends the message by itself, the switch case must escape from this function
 */
void FT_L4Audio_Operation(ilm_struct *ptrMsg)
{
    /* local variable with initial value */
    kal_uint8           err_code = FT_L4AUD_ERR_OP_NOT_SUPPORT;
    FT_L4AUD_REQ*       l4aud_req=((FT_L4AUD_REQ *)ptrMsg->local_para_ptr);
    ft_gl_l4aud_token   = l4aud_req->header.token;
    switch(l4aud_req->l4aud_op)
    {
        /**********************************************************
         * Handlers that sends message by itself
         **********************************************************/
        case FT_L4AUD_OP_AUDIO_PLAY_BY_NAME:
        case FT_L4AUD_OP_AUDIO_DEMO_IMY:
        case FT_L4AUD_OP_AUDIO_STOP:
        case FT_L4AUD_OP_SET_VOLUME:
        case FT_L4AUD_OP_SET_MODE:
        case FT_L4AUD_OP_GET_PROFILE_SETTINGS_BY_MODE:
        case FT_L4AUD_OP_SET_PROFILE_SETTINGS_BY_MODE:
        case FT_L4AUD_OP_GET_PARAM_SETTINGS_0809:
        case FT_L4AUD_OP_SET_PARAM_SETTINGS_0809:
        {
#if !defined(MED_NOT_PRESENT)
            FT_L4Audio_MedOperation(ptrMsg);
#endif // #if !defined(MED_NOT_PRESENT)
            return;
        }
        case FT_L4AUD_OP_SET_ECHO:
        {
            ft_l4aud_op_set_echo(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_GAIN:
        {
            ft_l4aud_op_set_gain(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_TONE_LOOP_BACK_REC:
        {
            return;
        }
        case FT_L4AUD_OP_TONE_LOOP_BACK_REC_2K:
        {
            ft_l4aud_op_tone_loopbackrec(l4aud_req, 1);  // loud speaker mode
            return;
        }
        case FT_L4AUD_OP_TONE_LOOP_BACK_REC_2K_NORMAL:
        {
            ft_l4aud_op_tone_loopbackrec(l4aud_req, 0);  // normal mode
            return;
        }
        case FT_L4AUD_OP_SET_LOUDSPK_FIR_COEFFS:
        {
            ft_l4aud_op_set_loudspk_fir(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_SPEECH_COMMON:
        {
            ft_l4aud_op_set_speech_common(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_LOUDSPK_MODE:
        {
            ft_l4aud_op_set_loudspk_mode(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_PLAYBACK_MAX_SWING:
        {
            ft_l4aud_op_set_max_swing(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_MELODY_FIR:
        {
            ft_l4aud_op_set_melody_fir(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_SPEECH_COMMON_AND_MODE:
        {
            ft_l4aud_op_set_speech_common_and_mode(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_GET_AC_FILTER_TYPE:
        {
            ft_l4aud_op_get_ac_coef_type(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_SET_AC_FILTER_COEFF:
        {
            ft_l4aud_op_set_ac_coef(l4aud_req);
            return;
        }
#if defined(WAV_CODEC) && !defined(__L1_STANDALONE__)
        case FT_L4AUD_OP_PLAY_WAVE_FILE_BY_STREAM:
        {
            ft_l4aud_op_play_wave_file_by_stream(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_FREE_MEMORY:
        {
            ft_l4aud_op_free_memory(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_PLAY_CUR_MEMORY_CONTENT:
        {
            ft_l4aud_op_play_cur_memory_content(l4aud_req);
            return;
        }
        case FT_L4AUD_OP_STOP_L1AUD_PLAYING:
        {
            ft_l4aud_op_stop_l1aud_playing(l4aud_req);
            return;
        }
#endif // #if defined(WAV_CODEC) && !defined(__L1_STANDALONE__)
        /**********************************************************
         * Handlers that does not send message by itself
         **********************************************************/
        case FT_L4AUD_OP_SET_OUTPUT_DEV:
        case FT_L4AUD_OP_SET_OUTPUT_DEV_EX:
        case FT_L4AUD_OP_SET_OUTPUT_VOLUME:
        {
            if(FT_L4AUD_OP_SET_OUTPUT_DEV == l4aud_req->l4aud_op)
            {
                if(l4aud_req->req.u1_set_output_device == 0)
                {
                    Media_SetOutputDevice(L1SP_SPEAKER1);
#if !defined(MED_NOT_PRESENT)
                    /* update global_output_path for MED request purpose */
                    global_output_path = AUDIO_DEVICE_SPEAKER;
#endif // #if !defined(MED_NOT_PRESENT)
                }
                else if(l4aud_req->req.u1_set_output_device ==1)
                {
                    Media_SetOutputDevice(L1SP_SPEAKER2);
#if !defined(MED_NOT_PRESENT)
                    /* update global_output_path for MED request purpose */
                    global_output_path = AUDIO_DEVICE_SPEAKER2;
#endif // #if !defined(MED_NOT_PRESENT)
                }
                else
                {
                    Media_SetOutputDevice(L1SP_LOUD_SPEAKER);
#if !defined(MED_NOT_PRESENT)
                    /* update global_output_path for MED request purpose */
                    global_output_path = AUDIO_DEVICE_LOUDSPEAKER;
#endif // #if !defined(MED_NOT_PRESENT)
                }
                L1SP_Init_PCMPlayback(l4aud_req->req.u1_set_output_device, KAL_FALSE, 0);// KAL_FALSE: digital gain use default value in l1audio
            }
            else if(FT_L4AUD_OP_SET_OUTPUT_DEV_EX == l4aud_req->l4aud_op)
            {
                if(l4aud_req->req.set_output_dev_and_dg.u1_set_output_device == 0)
                {
                    Media_SetOutputDevice(L1SP_SPEAKER1);
#if !defined(MED_NOT_PRESENT)
                    /* update global_output_path for MED request purpose */
                    global_output_path = AUDIO_DEVICE_SPEAKER;
#endif // #if !defined(MED_NOT_PRESENT)
                }
                else if(l4aud_req->req.set_output_dev_and_dg.u1_set_output_device ==1)
                {
                    Media_SetOutputDevice(L1SP_SPEAKER2);
#if !defined(MED_NOT_PRESENT)
                    /* update global_output_path for MED request purpose */
                    global_output_path = AUDIO_DEVICE_SPEAKER2;
#endif // #if !defined(MED_NOT_PRESENT)
                }
                else
                {
                    Media_SetOutputDevice(L1SP_LOUD_SPEAKER);
#if !defined(MED_NOT_PRESENT)
                    /* update global_output_path for MED request purpose */
                    global_output_path = AUDIO_DEVICE_LOUDSPEAKER;
#endif // #if !defined(MED_NOT_PRESENT)
                }
                L1SP_Init_PCMPlayback(l4aud_req->req.set_output_dev_and_dg.u1_set_output_device, KAL_TRUE,
                        l4aud_req->req.set_output_dev_and_dg.u2_digital_gain);
            }
            else
            {
                Media_SetOutputVolume(l4aud_req->req.u1_set_output_vol, 0 );
            }
            err_code = FT_CNF_OK;
            break;
        }
        case FT_L4AUD_OP_PLAY_FREQ_VOL_TONE:
        {
            KT_SetOutputDevice( L1SP_LOUD_SPEAKER );
            KT_SetOutputVolume( l4aud_req->req.set_freq_vol_tone.m_ucVolume, 0 );
            KT_Play( l4aud_req->req.set_freq_vol_tone.m_u2Freq, l4aud_req->req.set_freq_vol_tone.m_u2Freq, 0 );
            L1SP_MuteMicrophone(KAL_FALSE);
            err_code = FT_CNF_OK;
            break;
        }
        case FT_L4AUD_OP_STOP_FREQ_VOL_TONE:
        {
            KT_Stop();
            L1SP_MuteMicrophone(KAL_TRUE);
            err_code = FT_CNF_OK;
            break;
        }
        case FT_L4AUD_OP_GET_GAIN_TYPE_SUPPORT:
        {
#ifdef __TC01_AUD_GAIN_TYPE_SUPPORT__
            err_code = FT_CNF_OK;
#else // #ifdef __TC01_AUD_GAIN_TYPE_SUPPORT__
            err_code = FT_CNF_FAIL;
#endif // #ifndef __TC01_AUD_GAIN_TYPE_SUPPORT__
            break;
        }
        default:
        {
            err_code = FT_L4AUD_ERR_OP_NOT_SUPPORT;  // not support
            break;
        }
    }
    // send confirm to PC
    FtSendAudioAck(err_code, l4aud_req->l4aud_op);
}
static kal_uint8  ft_l4audio_ex_sendcnf(FT_L4AUD_EX_CNF *ft_l4aud_ex_ret, peer_buff_struct *peer_buff)
{
    FT_L4AUD_EX_CNF     *l4aud_cnf;
    ilm_struct          *ilm_ptr;
    if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_L4AUD_EX_CNF))) )
    {
        return 1;
    }
    l4aud_cnf = (FT_L4AUD_EX_CNF *)ilm_ptr->local_para_ptr;
    // assign primitive id
    l4aud_cnf->header.ft_msg_id = FT_L4AUD_CNF_EX_ID;
    // assign return structure
    l4aud_cnf->l4aud_op = ft_l4aud_ex_ret->l4aud_op;
    // copy the result directly without checking its cmd type
    kal_mem_cpy(&(l4aud_cnf->cnf), &(ft_l4aud_ex_ret->cnf), sizeof(ft_l4aud_ex_confirm));
    l4aud_cnf->status = ft_l4aud_ex_ret->status;
    // assign peer buffer
    if( NULL != peer_buff )
    {
        ilm_ptr->peer_buff_ptr = peer_buff;
    }
    _FT_SendFtMsgByToken(MOD_FT,
            MOD_TST,
            FT_TST_SAP,
            MSG_ID_FT_TO_TST,
            ilm_ptr,
            ft_gl_l4aud_token);
    return 0;
}
/*************************************************************
 *                       FT task audio Ex op                 *
 ************************************************************/
static kal_uint8 ft_l4audio_ex_op_get_gain_table_info(kal_bool bGetBasic)
{
#if defined (__GAIN_TABLE_SUPPORT__)
    FT_L4AUD_EX_CNF       l4aud_cnf;
    kal_uint8 i, real_num;
    kal_uint16 accu_num;
    AFE_BUFFER_T afe_buf;
    ft_l4aud_ex_gain_table_info_T  gain_table_util;
    peer_buff_struct   *peer_buff_ret = NULL;
    kal_char    *pdu_ptr = NULL;
    kal_uint16  pdu_length = 0;
    kal_uint16  cur_pos = 0;
    kal_uint16  *cur_steps = NULL;
    const WCHAR      *wc_Cur_Title = NULL;
    kal_bool    bSendBufNow = KAL_FALSE;
    if(bGetBasic)
    {
        l4aud_cnf.l4aud_op = FT_L4AUD_EX_OP_GET_GAIN_TABLE_INFO;
    }
    else
    {
        l4aud_cnf.l4aud_op = FT_L4AUD_EX_OP_GET_GAIN_TABLE_STRING_INFO;
    }
    real_num = 0;
    accu_num = 0;
    cur_steps = (kal_uint16*) get_ctrl_buffer(custom_ft_get_aud_max_volume_type() * sizeof(kal_uint16));
    kal_mem_set(cur_steps, 0, custom_ft_get_aud_max_volume_type() * sizeof(kal_uint16));
    ASSERT(cur_steps);
    for(i=0; ;i++)
    {
        if(gain_table[i].volume_type == -1)
        {
            // the last frame
            break;
        }
        if(bGetBasic)
        {
            AFE_GetAllPathUsage(gain_table[i].volume_type,gain_table[i].path,
                    &afe_buf, &(gain_table_util.u2BufLevel), &(gain_table_util.b_digital_gain_support),
                    &(gain_table_util.u1ExtAmpType), &(gain_table_util.u2ExtAmpCtrlPointNum));
        }
        wc_Cur_Title = gain_table_get_title(gain_table[i].volume_type);
        // volume type
        if(gain_table[i].volume_type < custom_ft_get_aud_max_volume_type())
        {
            gain_table_util.u1VolType = gain_table[i].volume_type;
            gain_table_util.u2SIdx = cur_steps[gain_table[i].volume_type];
            cur_steps[gain_table[i].volume_type]+=gain_table[i].volume_step;
            gain_table_util.u2EIdx = cur_steps[gain_table[i].volume_type]-1;
        }
        else
        {
            ASSERT(gain_table[i].volume_type);
        }
        switch(gain_table[i].path)
        {
            /******************************************************************
             * This is ridiculous.
             * DO NOT remove these meaningless cases below.
             * Because the FT_L4AUD_PATH_UNKNOWN... may not the same with AUD deifnition
             *****************************************************************/
            case AUD_PATH_UNKNOWN:
                gain_table_util.u1PathType = FT_L4AUD_PATH_UNKNOWN;
                break;
            case AUD_PATH_RECEIVER:
                gain_table_util.u1PathType = FT_L4AUD_PATH_RECEIVER;
                break;
            case AUD_PATH_HEADSET:
                gain_table_util.u1PathType = FT_L4AUD_PATH_HEADSET;
                break;
            case AUD_PATH_SPEAKER:
                gain_table_util.u1PathType = FT_L4AUD_PATH_SPEAKER;
                break;
            case AUD_PATH_DUAL:
                gain_table_util.u1PathType = FT_L4AUD_PATH_DUAL;
                break;
            case  AUD_PATH_BT:
                gain_table_util.u1PathType = FT_L4AUD_PATH_BT;
                break;
            /******************************************************************
             * This is ridiculous, DO NOT remove these meaningless cases above
             *****************************************************************/
            default:
                // path
                gain_table_util.u1PathType = gain_table[i].path;
                break;
        }
        if(bGetBasic)
        {
            switch(gain_table[i].gain_type)
            {
                /******************************************************************
                 * This is ridiculous.
                 * DO NOT remove these meaningless cases below
                 * Because the FT_L4AUD_GAIN_TABLE_UNKNOWN... may not the same with AUD deifnition
                 *****************************************************************/
                case GAIN_TYPE_UNKNOWN:
                    gain_table_util.i1GainTableType = FT_L4AUD_GAIN_TABLE_UNKNOWN;
                    break;
                case GAIN_TYPE_PURE_GAIN:
                    gain_table_util.i1GainTableType = FT_L4AUD_GAIN_TABLE_PURE;
                    break;
                case GAIN_TYPE_RAW_DATA:
                    gain_table_util.i1GainTableType = FT_L4AUD_GAIN_TABLE_RAW;
                    break;
                case GAIN_TYPE_N_LEVEL:
                    gain_table_util.i1GainTableType = FT_L4AUD_GAIN_TABLE_N_LEVEL;
                    break;
                    /******************************************************************
                     * This is ridiculous, DO NOT remove these meaningless cases above
                     *****************************************************************/
                default:
                    gain_table_util.i1GainTableType = gain_table[i].gain_type;
                    break;
            }


            switch(afe_buf)
            {
                /******************************************************************
                 * This is ridiculous, DO NOT remove these meaningless cases below
                 * Because the FT_L4AUD_PGA_BUF_UNKNOWN...
                 * are different from the AFE_BUFFER_T enum deifnitions
                 *****************************************************************/
                case AFE_BUFFER_NONE:
                    gain_table_util.i1BufType = FT_L4AUD_PGA_BUF_UNKNOWN;
                    break;
                case AFE_BUFFER_AUDIO:
                    gain_table_util.i1BufType = FT_L4AUD_PGA_BUF_AUDIO;
                    break;
                case AFE_BUFFER_VOICE:
                    gain_table_util.i1BufType = FT_L4AUD_PGA_BUF_VOICE;
                    break;
                case AFE_BUFFER_MIC:
                    gain_table_util.i1BufType = FT_L4AUD_PGA_BUF_MIC;
                    break;
                /******************************************************************
                 * This is ridiculous, DO NOT remove these meaningless cases above
                 *****************************************************************/
                default:
                    gain_table_util.i1BufType = afe_buf;
                    break;
            }
        }
allocate_peer_buf:
        if(NULL == peer_buff_ret)  // allocate peer buffer
        {
            peer_buff_ret=construct_peer_buff(FT_L4AUD_GAIN_TABLE_FRAME_SIZE, 0, 0, TD_CTRL);
            if(NULL == peer_buff_ret)  return -1;
            cur_pos = 0;
            real_num = 0;
            bSendBufNow = KAL_FALSE;
            pdu_ptr = get_pdu_ptr( peer_buff_ret, &pdu_length );
            kal_mem_set(pdu_ptr, 0x0, FT_L4AUD_GAIN_TABLE_FRAME_SIZE); // clear the buffer
        }
        if(bGetBasic)
        {
            if( FT_L4AUD_GAIN_TABLE_FRAME_SIZE < (cur_pos+sizeof(ft_l4aud_ex_gain_table_info_T)))
                bSendBufNow = KAL_TRUE;
        }
        else
        {
            if( FT_L4AUD_GAIN_TABLE_FRAME_SIZE <
                    (cur_pos+(1+1+2+2+(kal_wstrlen(wc_Cur_Title)+1)*2+ (kal_wstrlen(gain_table[i].title)+1)*2)))
                bSendBufNow = KAL_TRUE;
        }
        if(bSendBufNow)
        {
            l4aud_cnf.cnf.m_rFrmInfo.m_u1LastFrm = 0;// set last_frame = 0
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.m_rFrmInfo.m_u1CarriedNum = real_num;
            l4aud_cnf.cnf.m_rFrmInfo.m_u2AccuNum = accu_num;
            // send confirm
            ft_l4audio_ex_sendcnf(&l4aud_cnf, peer_buff_ret);
            // sleep to wait for tst flush out data
            kal_sleep_task(50);
            // allocate peer buffer again
            peer_buff_ret = NULL;
            goto allocate_peer_buf;
        }
        pdu_ptr = get_pdu_ptr( peer_buff_ret, &pdu_length );
        if(bGetBasic)
        {
            kal_mem_cpy(pdu_ptr+cur_pos, &gain_table_util, sizeof(gain_table_util));
            cur_pos +=sizeof(gain_table_util);
        }
        else
        {
            kal_mem_cpy(pdu_ptr+cur_pos, &gain_table_util.u1VolType, 1);
            kal_mem_cpy(pdu_ptr+cur_pos+1, &gain_table_util.u1PathType, 1);
            kal_mem_cpy(pdu_ptr+cur_pos+2, &gain_table_util.u2SIdx, 2);
            kal_mem_cpy(pdu_ptr+cur_pos+4, &gain_table_util.u2EIdx, 2);
            kal_mem_cpy(pdu_ptr+cur_pos+6, (void *)wc_Cur_Title, (kal_wstrlen(wc_Cur_Title)+1)*2);
            kal_mem_cpy(pdu_ptr+cur_pos+6+(kal_wstrlen(wc_Cur_Title)+1)*2, (void *)(gain_table[i].title), (kal_wstrlen(gain_table[i].title)+1)*2);
            cur_pos+= (1+1+2+2+(kal_wstrlen(wc_Cur_Title)+1)*2+ (kal_wstrlen(gain_table[i].title)+1)*2);
        }
        real_num++;
        accu_num++;
    }
    free_ctrl_buffer(cur_steps);
    l4aud_cnf.cnf.m_rFrmInfo.m_u1LastFrm = 1;
    l4aud_cnf.status = FT_CNF_OK;
    l4aud_cnf.cnf.m_rFrmInfo.m_u1CarriedNum = real_num;
    l4aud_cnf.cnf.m_rFrmInfo.m_u2AccuNum = accu_num;
    ft_l4audio_ex_sendcnf(&l4aud_cnf, peer_buff_ret);
#endif // end of #if defined(__GAIN_TABLE_SUPPORT__)
    return 0;
}
void ft_l4aud_op_get_speech_mode_table_info(void)
{
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
    FT_L4AUD_EX_CNF l4aud_cnf;
    peer_buff_struct *peer_buff_ret = NULL;
    kal_char    *pdu_ptr = NULL;
    kal_uint16  pdu_length = 0, cur_pos = 0;
    const WCHAR      *wc_Cur_Title = NULL;
    kal_uint8 i;
    l4aud_cnf.l4aud_op = FT_L4AUD_EX_OP_GET_SPEECH_MODE_TABLE_INFO;
    l4aud_cnf.cnf.m_rSpModTblInfo.u1SpeechModeNum = custom_ft_get_audio_speech_mode_num();
    l4aud_cnf.cnf.m_rSpModTblInfo.u1SpeechModeParaMaxNum = custom_ft_get_audio_max_enhance_mode_para_num();
    // allocate peer buffer
    if(NULL == peer_buff_ret)
    {
        peer_buff_ret=construct_peer_buff(custom_ft_get_audio_total_title_length(), 0, 0, TD_CTRL);
        if(NULL == peer_buff_ret)
        {
            return;
        }
        pdu_ptr = get_pdu_ptr( peer_buff_ret, &pdu_length );
        kal_mem_set(pdu_ptr, 0x0, custom_ft_get_audio_total_title_length()); // clear the buffer
    }
    for(i =0; i < NUM_SPEECH_MODE; i++)
    {
        wc_Cur_Title = custom_ft_get_audio_speech_mode_title(i);
        kal_mem_cpy(pdu_ptr+cur_pos, (void *)wc_Cur_Title, (kal_wstrlen(wc_Cur_Title)+1)*2);
        cur_pos+= (kal_wstrlen(wc_Cur_Title)+1)*2;
    }
    l4aud_cnf.status = FT_CNF_OK;
    ft_l4audio_ex_sendcnf(&l4aud_cnf, peer_buff_ret);
#endif // __SPEECH_MODE_TABLE_SUPPORT__
}
/***********************************************************
 * Dual-Mic NR
 **********************************************************/
/***********************************************************
 * State variables and context handle for DMNR
 **********************************************************/
static FT_WAV_HEADER_T wav_hdr =
{
    { 'R', 'I', 'F', 'F' },
    0,
    { 'W', 'A', 'V', 'E' },
    { 'f', 'm', 't', (char)0x20 },
    16,
    1, // linear PCM
    1, // 2-CH
    8000,
    8000*2,
    2,
    16,
    { 'd', 'a', 't', 'a' },
    0
};
static FT_AUTO_RECORD_T auto_record;
static FT_AUTO_SPEAK_T auto_speak;
static struct
{
    kal_uint32           init_state;
    kal_uint32           stop_loopback;
    kal_bool             playfile_eof;
}echoLoopManager;
#define AUTOREC_MEDIA_BUF_SIZE          (4 * 20 * 1024)
#define AUTOSPK_MEDIA_BUF_SIZE          (20 * 1024)
#define EVENT_NONE                  0
#define EVENT_DATA_REQUEST          1
#define EVENT_DATA_NOTIFY           2
#define EVENT_STOP                  3
#define EVENT_END                   4
#define DIR_UL                      0
#define DIR_DL                      1
#define AUTO_SPK_IDLE1                  1
#define AUTO_SPK_IDLE2                  2
#define AUTO_SPK_START                  3
#define AUTO_SPK_STOP                   4
#define INIT_FILL_SILENCE  4
#define END_FILL_SILENCE   1
static kal_uint32 FT_PCM2WAY_UL_FRAME_SIZE = 640;
static kal_uint32 FT_PCM2WAY_DL_FRAME_SIZE = 160;
static kal_uint32 FT_PCM2WAY_FORMAT;
static kal_uint32 FT_PCM2WAY_TYPE;
static kal_int32 echoLoopStatusCode = 0;
static kal_uint8 originalSidetoneVolume = 0;
/**
 * start recording operation handler
 * @return status (-1: not enough free space, -2: Media_Record failed, -3: cascaded start, -4: context allocation failed
 */
static kal_int32 ft_l4aud_ex_op_start_recording(const kal_int8* filename, kal_uint32 requested_time, kal_uint32 fmt, kal_uint16 inputVolume)
{
    FT_DUALMIC_CONTROL_T param;
    param.echoloopParameters.format         = (fmt == 0) ? P2W_FORMAT_WB_CAL : P2W_FORMAT_CAL;
    param.echoloopParameters.playDrive      = L'Z';
    param.echoloopParameters.recordDrive    = L'Z';
    param.echoloopParameters.outputDevice   = L1SP_SPEAKER1;
    param.echoloopParameters.outputVolume   = 0;
    param.echoloopParameters.inputDevice    = FT_L1SP_MICROPHONE1;
    param.echoloopParameters.inputVolume    = inputVolume;
    param.echoloopParameters.sidetoneVolume = 0;
    param.recordingOnly                     = KAL_TRUE;
    param.fileName                          = filename;
    param.requestedTime                     = requested_time;
    // recording type
    param.pcm2wayType                       = P2W_APP_TYPE_REC_ONLY_CAL;
    return Custom_META_FtStartDualMicControl(&param);
}
/**
 * stop recording operation handler
 */
static kal_int32 ft_l4aud_ex_op_stop_recording(void)
{
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
    if(auto_record.sample_consume / FT_PCM2WAY_UL_FRAME_SIZE * 20 / sizeof(kal_uint16) < auto_speak.sample_elapsed / FT_PCM2WAY_UL_FRAME_SIZE * 20)
    {
        return Custom_META_FtStopDualMicEchoTest((void*)EVENT_STOP);
    }
    else
    {
        return 0;
    }
}
/**
 * query recording operation handler
 */
static void ft_l4aud_ex_op_query_recording(FT_L4AUD_EX_CNF *l4aud_ex_cnf)
{
    l4aud_ex_cnf->cnf.m_rQueryStatus.requested_time = auto_speak.sample_elapsed / FT_PCM2WAY_UL_FRAME_SIZE * 20;
    l4aud_ex_cnf->cnf.m_rQueryStatus.offset = auto_record.sample_consume / FT_PCM2WAY_UL_FRAME_SIZE * 20 / sizeof(kal_uint16);
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
}
META_ECHO_LOOP_HANDLE *FtEchoLoop_GetHandle ( kal_uint32 dir, kal_uint8 *buffer, kal_int32 buffer_size )
{
    META_ECHO_LOOP_HANDLE *handle;
    FtAssertionCheckStatement = ((dir==DIR_UL) || (dir==DIR_DL)) ? KAL_TRUE : KAL_FALSE ;
    ASSERT( FtAssertionCheckStatement );
    handle = (META_ECHO_LOOP_HANDLE *)get_ctrl_buffer( sizeof(META_ECHO_LOOP_HANDLE) );
    if( NULL==handle )
    {
        return NULL;
    }
    memset( handle, 0, sizeof(META_ECHO_LOOP_HANDLE) );
    handle->dir = dir;
    if( KAL_FALSE == FT_PCMRB_Init( &handle->rb, (kal_int16 *)buffer, buffer_size/sizeof(kal_int16) ) )
    {
        free_ctrl_buffer( handle );
        return NULL;
    }
    return handle;
}
/**
 * This function set parameters before Dual-Mic echo testing
 * refer to tone2.c Key1Event
 */
kal_int32 FtStartDualMicEchoTestPreSetting(const ft_l4aud_ex_echoloop_request_T *request )
{
    kal_uint8 device;
    kal_uint16 m_para_normal[16] = {96,  2269, 16388,    30, 57351,    31,   400,     0,
        80,  4325,    99,     0, 20552,    99,    13,  8192  };
    kal_mem_set(&auto_speak, 0, sizeof(auto_speak));
    kal_mem_set(&auto_record, 0, sizeof(auto_record));
    L1SP_Speech_Off();
    L1SP_SetMicrophoneVolume(request->inputVolume);
    L1SP_SetOutputVolume(request->outputVolume, 0);
    originalSidetoneVolume = L1SP_GetSidetoneVolume();
    L1SP_SetSidetoneVolume(request->sidetoneVolume);
    /**********************************************************
     * The L1SP is variable defined by in/out buffer/path in
     * custom/audio/audcoeff.c, the FT lib has to convert the
     * in/out between PC side and target side
     *********************************************************/
    /*********************************
     * DO NOT REMOVE the switch case
     ********************************/
    switch(request->outputDevice)
    {
        case FT_L1SP_SPEAKER1:
        {
            device = L1SP_SPEAKER1;
            break;
        }
        case FT_L1SP_SPEAKER2:
        {
            device = L1SP_SPEAKER2;
            break;
        }
        case FT_L1SP_LOUD_SPEAKER:
        {
            device = L1SP_LOUD_SPEAKER;
            break;
        }
        default:
        {
            device = L1SP_SPEAKER1;
            break;
        }
    }
    L1SP_SetOutputDevice(device);
    /*********************************
     * DO NOT REMOVE the switch case
     ********************************/
    switch(request->inputDevice)
    {
        case FT_L1SP_MICROPHONE1:
        {
            device = L1SP_MICROPHONE1;
            break;
        }
        case FT_L1SP_MICROPHONE2:
        {
            device = L1SP_MICROPHONE2;
            break;
        }
        default:
        {
            device = L1SP_MICROPHONE1;
            break;
        }
    }
    L1SP_SetInputSource(device);
    L1SP_SetSpeechMode(SPH_MODE_NORMAL, m_para_normal);
    return FT_ECHO_LOOP_NORMAL;
}
kal_int32 FtStartDualMicControl(const FT_DUALMIC_CONTROL_T* param)
{
    echoLoopStatusCode = Custom_META_FtStartDualMicEchoTestPreSetting( &(param->echoloopParameters) );
    if(FT_ECHO_LOOP_NORMAL != echoLoopStatusCode)
    {
        return echoLoopStatusCode;
    }
    FT_PCM2WAY_FORMAT = param->echoloopParameters.format;
    FT_PCM2WAY_TYPE   = param->pcm2wayType;
    PCM2WAY_QueryBufSize((P2W_Format)FT_PCM2WAY_FORMAT, &FT_PCM2WAY_UL_FRAME_SIZE, &FT_PCM2WAY_DL_FRAME_SIZE);
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
    /**********************************
     * Initialize parameters
     *********************************/
    echoLoopStatusCode = Custom_META_FtWriteInitParameter();
    if(FT_ECHO_LOOP_NORMAL != echoLoopStatusCode)
    {
        return echoLoopStatusCode;
    }
    /**********************************
     * Update DL context
     *********************************/
    if(param->recordingOnly == KAL_FALSE)
    {
        kal_wsprintf( auto_speak.filename, "%c:\\echo_play.wav", param->echoloopParameters.playDrive);
        echoLoopStatusCode = Custom_META_FtAutoSpeakOpenFile(&auto_speak);
        if( FT_ECHO_LOOP_NORMAL != echoLoopStatusCode )
        {
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
            return echoLoopStatusCode;
        }
        if(auto_speak.pAutoSpeakBuffer)
        {
            ft_free_pcm_buffer((void**)&(auto_speak.pAutoSpeakBuffer), auto_speak.indicator);
        }
        if(auto_speak.pAutoSpeakBuffer == NULL)
        {
            ft_allocate_pcm_buffer(KAL_TRUE, (void**)&(auto_speak.pAutoSpeakBuffer), &(auto_speak.indicator), &u4_ft_valid_buf_len, &u4_ft_buf_size_alloc, AUTOSPK_MEDIA_BUF_SIZE * sizeof(kal_int16));
        }
        auto_speak.echo_loop_handle = FtEchoLoop_GetHandle( DIR_DL, (kal_uint8 *)auto_speak.pAutoSpeakBuffer, AUTOSPK_MEDIA_BUF_SIZE*sizeof(kal_int16));
        auto_speak.echo_loop_handle->host_data = 0;
        auto_speak.echo_loop_handle->callback = Custom_META_FtAutoSpeakCallback;
        /*************************************
         * Note: Custom_META_FtAutoSpeakGetDataFromFileToRB
         * will update echoLoopStatusCode and
         * does not return value to fix to the
         * callback function prototype
         *************************************/
        Custom_META_FtAutoSpeakGetDataFromFileToRB(0,0);
        if(FT_ECHO_LOOP_NORMAL != echoLoopStatusCode)
        {
            return echoLoopStatusCode;
        }
    }
    else
    {
        auto_speak.sample_elapsed = param->requestedTime / 20 * FT_PCM2WAY_UL_FRAME_SIZE;
    }
    /**********************************
     * Update UL context
     *********************************/
    if(param->fileName)
    {
        kal_wsprintf( auto_record.filename, "%s", param->fileName);
    }
    else
    {
        kal_wsprintf( auto_record.filename, "%c:\\echo_record.out", param->echoloopParameters.recordDrive);
    }
    echoLoopStatusCode = Custom_META_FtAutoRecOpenFile(&auto_record);
    if( FT_ECHO_LOOP_NORMAL != echoLoopStatusCode )
    {
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
        return echoLoopStatusCode;
    }
    if(auto_record.pAutoRecBuffer)
    {
        ft_free_pcm_buffer((void**)&(auto_record.pAutoRecBuffer), auto_record.indicator);
    }
    if(auto_record.pAutoRecBuffer == NULL)
    {
        ft_allocate_pcm_buffer(KAL_TRUE, (void**)&(auto_record.pAutoRecBuffer), &(auto_record.indicator), &u4_ft_valid_buf_len, &u4_ft_buf_size_alloc, AUTOREC_MEDIA_BUF_SIZE * sizeof(kal_int16));
    }
    auto_record.echo_loop_handle = FtEchoLoop_GetHandle( DIR_UL, (kal_uint8 *)auto_record.pAutoRecBuffer, AUTOREC_MEDIA_BUF_SIZE*sizeof(kal_int16));
    auto_record.echo_loop_handle->callback = Custom_META_FtAutoRecCallback;
    auto_record.echo_loop_handle->host_data = 0;
    echoLoopStatusCode = Custom_META_FtGetPcm2WayBuffer(&auto_record, &auto_speak);
    if(FT_ECHO_LOOP_NORMAL != echoLoopStatusCode)
    {
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
        return echoLoopStatusCode;
    }
    PCM2Way_SetFormat(FT_PCM2WAY_FORMAT);
    /**********************************
     * Initiate echo loop HISR
     *********************************/
    /*
     * L1Audio_InProcCall actually calls MEDIA(audio) function to send ILM to MED
     * and execute the function in MED's context
     * caller: calls L1Audio_InProcCall (send ILM to MED)
     * MED receive ILM and then call the callback function
     */
    if(param->recordingOnly == KAL_TRUE)
    {
        PCM2WAY_Start( Custom_META_FtDualMicRecordingInHisr, FT_PCM2WAY_TYPE );
    }
    else
    {
        PCM2WAY_Start( Custom_META_FtDualMicEchoTestLoopbackInHisr, FT_PCM2WAY_TYPE );
    }
    return FT_ECHO_LOOP_NORMAL;
}
/**
 * This function start Dual-Mic echo testing (The very start of the echo loop testing)
 * This function will be executed in FT task's context
 * refer to bt_loopback.c BT_Loopback_Start
 */
kal_int32 FtStartDualMicEchoTest(ft_l4aud_ex_echoloop_request_T *request)
{
    FT_DUALMIC_CONTROL_T param;
    param.echoloopParameters = *request;
    param.recordingOnly      = KAL_FALSE;
    param.fileName           = NULL;
    param.requestedTime      = 0;
    // recording + playing type
    param.pcm2wayType        = P2W_APP_TYPE_REC_PLAY_CAL;
    return Custom_META_FtStartDualMicControl(&param);
}
/**
 * This function stop Dual-Mic echo testing
 * This function is called in MED task context
 * refer to bt_loopback.c BT_Loopback_Stop
 * This will be called directed by PC's request or Custom_META_FtAutoRecGetDataFromRBToFile
 */
kal_int32 FtStopDualMicEchoTest(void* event)
{
    /*********************************************
     * Note: FT task could be interrupted by HISR
     ********************************************/
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
    {
        if(event == (void*)EVENT_STOP)
        {
            /**********************************
             * Stop event triggered by user
             *********************************/
            PCM2WAY_Stop(FT_PCM2WAY_TYPE);
            while(auto_speak.waiting || auto_record.waiting)
            {
                kal_sleep_task(10);
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
            }
        }
        if(event == (void*)EVENT_END)
        {
            while(FT_PCMRB_GetDataCount( &auto_record.echo_loop_handle->rb ) > 0)
            {
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
                echoLoopManager.stop_loopback=0;
            }
        }
        /* restore PCM2WAY format */
        if(FT_PCM2WAY_FORMAT != P2W_FORMAT_NORMAL)
        {
            PCM2Way_SetFormat(P2W_FORMAT_NORMAL);
        }
        if(auto_record.echo_loop_handle)
        {
            free_ctrl_buffer( auto_record.echo_loop_handle );
        }
        if(auto_speak.echo_loop_handle)
        {
            free_ctrl_buffer( auto_speak.echo_loop_handle );
        }
        if(auto_record.pAutoRecBuffer)
        {
            ft_free_pcm_buffer((void **)&auto_record.pAutoRecBuffer, auto_record.indicator);
        }
        if(auto_speak.pAutoSpeakBuffer)
        {
            ft_free_pcm_buffer((void **)&auto_speak.pAutoSpeakBuffer, auto_speak.indicator);
        }
        auto_record.pAutoRecBuffer = NULL;
        auto_record.echo_loop_handle = NULL;
        auto_speak.pAutoSpeakBuffer = NULL;
        auto_speak.echo_loop_handle = NULL;
        Custom_META_FtFreePcm2WayBuffer(&auto_record, &auto_speak);
        if(auto_speak.fAutoSpeak)
        {
            FtAssertionCheckStatement = (FS_NO_ERROR == FS_Close( auto_speak.fAutoSpeak )) ? KAL_TRUE : KAL_FALSE ;
            ASSERT( FtAssertionCheckStatement );
            auto_speak.fAutoSpeak = NULL;
        }
        FtAssertionCheckStatement = (FS_NO_ERROR == FS_Close( auto_record.fAutoRec ) ) ? KAL_TRUE : KAL_FALSE ;
        ASSERT( FtAssertionCheckStatement );
        auto_record.fAutoRec = NULL;
    }
    L1SP_SetSidetoneVolume(originalSidetoneVolume);
    return FT_ECHO_LOOP_NORMAL;
}
/**
 * Query the echo loop progress and fill the confirm message
 */
void FtQueryDualMicEchoTest(FT_L4AUD_EX_CNF *l4aud_ex_cnf)
{
    l4aud_ex_cnf->cnf.m_rQueryEcholoopStatus.totalSamples = auto_speak.stWavHdr.data_size >> 1;
    l4aud_ex_cnf->cnf.m_rQueryEcholoopStatus.progress = l4aud_ex_cnf->cnf.m_rQueryEcholoopStatus.totalSamples - auto_speak.sample_elapsed;
    if(auto_speak.echo_loop_handle == NULL &&
            auto_speak.pAutoSpeakBuffer == NULL &&
            auto_record.echo_loop_handle == NULL &&
            auto_record.pAutoRecBuffer == NULL)
    {
        l4aud_ex_cnf->cnf.m_rQueryEcholoopStatus.stop = 1;
    }
    else
    {
        l4aud_ex_cnf->cnf.m_rQueryEcholoopStatus.stop = 0;
    }
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
}
/**
 * utility function to free pcm 2way buffer
 * refer to bt_loopback.c FreePcm2WayBuffer
 */
kal_int32 FtFreePcm2WayBuffer( FT_AUTO_RECORD_T* auto_record, FT_AUTO_SPEAK_T* auto_speak )
{
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
    if(auto_record->mic_buffer)
    {
        free_ctrl_buffer( auto_record->mic_buffer );
    }
    auto_record->mic_buffer = NULL;
    /* Note: the spk_buffer is split from mic_buffer: don't need to free it */
    auto_speak->spk_buffer = NULL;
    return FT_ECHO_LOOP_NORMAL;
}
/**
 * utility function to free pcm 2way buffer
 * refer to bt_loopback.c GetPcm2WayBuffer
 */
kal_int32 FtGetPcm2WayBuffer( FT_AUTO_RECORD_T* auto_record, FT_AUTO_SPEAK_T* auto_speak)
{
    kal_int16 *buffer = NULL;
    buffer = (kal_int16 *)get_ctrl_buffer((FT_PCM2WAY_DL_FRAME_SIZE + FT_PCM2WAY_UL_FRAME_SIZE)*sizeof(kal_int16));
    if(buffer)
    {
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
        kal_mem_set( buffer, 0, (FT_PCM2WAY_DL_FRAME_SIZE + FT_PCM2WAY_UL_FRAME_SIZE)*sizeof(kal_int16) );
        /*****************************
         * assign PCM2WAY buffer (UL)
         ****************************/
        auto_record->mic_buffer = buffer;
        /* shift buffer pointer by FT_PCM2WAY_UL_FRAME_SIZE to the heade of DL buffer */
        buffer += FT_PCM2WAY_UL_FRAME_SIZE;
        /*****************************
         * assign PCM2WAY buffer (DL)
         ****************************/
        auto_speak->spk_buffer = buffer;
    }
    else
    {
        return FT_ECHO_LOOP_ALLOCATE_2WAY_BUFFER_FAILED;
    }
    return FT_ECHO_LOOP_NORMAL;
}
/**
 * This function read the data from file and put it into ring buffer (RB)
 * This function is called in MED task context
 */
void FtAutoSpeakGetDataFromFileToRB(kal_uint32 arg1, void *arg2)
{
    kal_int16 *write_ptr;
    kal_int32 write_len;
    kal_uint32 count;
    FT_PCMRB *rb = NULL;
    rb = &auto_speak.echo_loop_handle->rb;
    write_len = FT_PCMRB_GetFreeSpace( rb );
    while( write_len > 0 )
    {
        FT_PCMRB_GetWriteBlock( rb, &write_ptr, &write_len );
        if( auto_speak.sample_elapsed == 0 )
        {
            break;
        }
        else
        {
            if( auto_speak.sample_elapsed < write_len )
            {
                /* The buffer can hold all of the sample */
                write_len = auto_speak.sample_elapsed;
            }
            FtAssertionCheckStatement = (FS_NO_ERROR == FS_Read( auto_speak.fAutoSpeak, (kal_uint8 *)write_ptr, write_len << 1, &count )) ?
                KAL_TRUE : KAL_FALSE ;
            ASSERT( FtAssertionCheckStatement );
            /* update elapsed value */
            auto_speak.sample_elapsed -= (count >> 1);
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
        }
        FT_PCMRB_ShiftWritePointer(rb, count >> 1);
        write_len -= ( count >> 1 );
        if (write_len == 0)
        {
            break;
        }
    }
    auto_speak.waiting = KAL_FALSE;
    if( auto_speak.sample_elapsed == 0 )
    {
        echoLoopManager.playfile_eof = KAL_TRUE;
    }
}
/**
 * This function read the data from  ring buffer (RB) and put it into file
 * This function is called in MED task context
 */
void FtAutoRecGetDataFromRBToFile( kal_uint32 arg1, void *arg2 )
{
    kal_int16 *read_ptr;
    kal_int32 read_len;
    kal_uint32 count;
    FT_PCMRB *rb = &auto_record.echo_loop_handle->rb;
    if(arg2 == (void *)EVENT_END)
    {
        PCM2WAY_Stop(FT_PCM2WAY_TYPE);
    }
    read_len = FT_PCMRB_GetDataCount( rb );
    while( read_len > 0 )
    {
        FT_PCMRB_GetReadBlock( rb , &read_ptr , &read_len );
        auto_record.sample_consume += read_len<<1;
        FtAssertionCheckStatement = (FS_NO_ERROR == FS_Write( auto_record.fAutoRec , (kal_uint8 *)read_ptr , read_len << 1, &count)) ?
            KAL_TRUE : KAL_FALSE ;
        ASSERT( FtAssertionCheckStatement );
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
        FT_PCMRB_ShiftReadPointer( rb , count >> 1 );
        read_len -= ( count >> 1 );
        if (read_len == 0)
        {
            break;
        }
    }
    auto_record.waiting = KAL_FALSE;
    if(arg2 == (void *)EVENT_END)
    {
        Custom_META_FtStopDualMicEchoTest((void *)EVENT_END);
    }
    echoLoopStatusCode = FT_ECHO_LOOP_NORMAL;
}
/**
 * Open the speaker source (called in task context)
 */
kal_int32 FtAutoSpeakOpenFile(FT_AUTO_SPEAK_T* auto_speak)
{
    kal_uint32 count;
    if( (auto_speak->fAutoSpeak = FS_Open( auto_speak->filename, FS_READ_ONLY )) < 0)
    {
        return FT_ECHO_LOOP_OPEN_SPEAK_FILE_FAILED;
    }
    FS_Read( auto_speak->fAutoSpeak, (kal_uint8 *)&(auto_speak->stWavHdr), sizeof(FT_WAV_HEADER_T), &count );
    if(
            (strncmp(auto_speak->stWavHdr.riff_chunk, "RIFF", 4) != 0) &&
            (strncmp(auto_speak->stWavHdr.riff_type, "WAVE",4) != 0 ) &&
            (strncmp(auto_speak->stWavHdr.data_chunk, "data",4) != 0 )
      )
    {
        FtAssertionCheckStatement = (FS_Seek( auto_speak->fAutoSpeak, 0, FS_FILE_BEGIN) >= 0) ? KAL_TRUE : KAL_FALSE;
        ASSERT( FtAssertionCheckStatement );
    }
    auto_speak->sample_elapsed = auto_speak->stWavHdr.data_size >> 1;
    return FT_ECHO_LOOP_NORMAL;
}
/**
 * Open the recorder sink (called in task context)
 */
kal_int32 FtAutoRecOpenFile(FT_AUTO_RECORD_T* auto_record)
{
    if( (auto_record->fAutoRec = FS_Open(auto_record->filename, FS_CREATE_ALWAYS )) < 0 )
    {
        return FT_ECHO_LOOP_OPEN_RECORD_FILE_FAILED;
    }
    return FT_ECHO_LOOP_NORMAL;
}
/**
 * Utility function to write recorder sink file header
 */
kal_int32 FtAutoRecWriteFileHeader(void)
{
    kal_uint32 count;
    if( auto_record.pAutoRecBuffer==NULL )
    {
        return FT_ECHO_LOOP_ALLOCATE_2WAY_BUFFER_FAILED;
    }
    wav_hdr.riff_size   = auto_record.sample_consume+36 ;
    wav_hdr.data_size   = auto_record.sample_consume  ;
    FtAssertionCheckStatement = (FS_Seek( auto_record.fAutoRec, 0, FS_FILE_BEGIN) >= 0) ? KAL_TRUE : KAL_FALSE ;
    ASSERT( FtAssertionCheckStatement );
    FtAssertionCheckStatement = (FS_NO_ERROR == FS_Write( auto_record.fAutoRec, (kal_uint8 *) (&wav_hdr), sizeof(wav_hdr), &count )) ?
        KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );
    return FT_ECHO_LOOP_NORMAL;

}
/**
 * Utility function to initiate parameters
 */
kal_int32 FtWriteInitParameter(void)
{
    echoLoopManager.init_state = 0;
    auto_record.waiting = KAL_FALSE;
    auto_speak.waiting = KAL_FALSE;
    echoLoopManager.playfile_eof = KAL_FALSE;
    echoLoopManager.stop_loopback = 0;
    auto_record.sample_consume = 0;
    wav_hdr.riff_size   = 0  ;
    wav_hdr.data_size   = 0  ;
    auto_speak.pAutoSpeakBuffer = NULL;
    auto_record.pAutoRecBuffer = NULL;
    return FT_ECHO_LOOP_NORMAL;
}
/**
 * This function Sends echo test start indication to PC side
 */
void FtSendDualMicEchoTestStarted(void)
{
    FT_L4AUD_EX_CNF       l4aud_cnf;
    l4aud_cnf.header.ft_msg_id = FT_L4AUD_CNF_EX_ID;
    l4aud_cnf.l4aud_op = FT_L4AUD_EX_OP_START_ECHO_LOOP;
    l4aud_cnf.cnf.m_StatusCode = echoLoopStatusCode;
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__)
    ft_l4audio_ex_sendcnf(&l4aud_cnf, NULL);
}
/**
 * FT task L4 Audio Ex operation type1 operation handler
 * (these operations return immediately)
 *
 * ======================== POLICY ========================
 * 1. !!!DO NOT wrap any SWITCHABLE feature option in this function!!!
 * ======================== POLICY ========================
 */
static void ft_l4audio_ex_operation_type1(ilm_struct *ptrMsg)
{
    /// pointer to the L4Audio Ex request message sturcture
    FT_L4AUD_EX_REQ       *l4aud_req=((FT_L4AUD_EX_REQ *)ptrMsg->local_para_ptr);
    /// the L4Audio Ex confirm message structure
    FT_L4AUD_EX_CNF       l4aud_cnf;
    /// pointer to the peer buffer structure for confirm message
    peer_buff_struct      *peer_buff_ret = NULL;
    void *                buffer;
    kal_uint16            bufferLength;
#if !defined(__SMART_PHONE_MODEM__)
    AFE_BUFFER_T      buf_type;
#endif // #if !defined(__SMART_PHONE_MODEM__
    l4aud_cnf.header.ft_msg_id = FT_L4AUD_CNF_EX_ID;
    l4aud_cnf.l4aud_op = l4aud_req->l4aud_op;
    memset(&l4aud_cnf.cnf,0x0,sizeof(l4aud_cnf.cnf));    
    switch(l4aud_req->l4aud_op)
    {
        case FT_L4AUD_EX_OP_GET_DL_CAPABILITY:
        {
            // allocate a control buffer
            ft_l4aud_ex_dl_cap_info_cnf_T  *pCnf = NULL;
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(ft_l4aud_ex_dl_cap_info_cnf_T), 0, 0, TD_CTRL)) )
            {
                pCnf = (ft_l4aud_ex_dl_cap_info_cnf_T*)get_pdu_ptr( peer_buff_ret, &bufferLength );
                // assign peer buffer
                peer_buff_ret->pdu_len = sizeof(ft_l4aud_ex_dl_cap_info_cnf_T);
            }
            if(pCnf != NULL)// get capability information
            {
#if !defined(__SMART_PHONE_MODEM__)
                AFE_GetPathUsage(L1SP_SPEECH,PHONE_MODE_HANDSET, &buf_type);
                if(buf_type == AFE_BUFFER_AUDIO)
                    pCnf->u4_dl_buf_type_by_mode[0] = 0;
                else if(buf_type == AFE_BUFFER_VOICE)
                    pCnf->u4_dl_buf_type_by_mode[0] = 1;
                else
                    pCnf->u4_dl_buf_type_by_mode[0] = 2; // unknown
                AFE_GetPathUsage(L1SP_SPEECH,PHONE_MODE_HEADSET, &buf_type);
                if(buf_type == AFE_BUFFER_AUDIO)
                    pCnf->u4_dl_buf_type_by_mode[1] = 0;
                else if(buf_type == AFE_BUFFER_VOICE)
                    pCnf->u4_dl_buf_type_by_mode[1] = 1;
                else
                    pCnf->u4_dl_buf_type_by_mode[1] = 2; // unknown


                AFE_GetPathUsage(L1SP_SPEECH,PHONE_MODE_HANDFREE, &buf_type);
                if(buf_type == AFE_BUFFER_AUDIO)
                    pCnf->u4_dl_buf_type_by_mode[2] = 0;
                else if(buf_type == AFE_BUFFER_VOICE)
                    pCnf->u4_dl_buf_type_by_mode[2] = 1;
                else
                    pCnf->u4_dl_buf_type_by_mode[2] = 2; // unknown

                AFE_GetPathUsage(L1SP_SPEECH, PHONE_MODE_BT_EARPHONE, &buf_type);
                if(buf_type == AFE_BUFFER_AUDIO)
                    pCnf->u4_dl_buf_type_by_mode[3] = 0;
                else if(buf_type == AFE_BUFFER_VOICE)
                    pCnf->u4_dl_buf_type_by_mode[3] = 1;
                else
                    pCnf->u4_dl_buf_type_by_mode[3] = 2; // unknown

                AFE_GetPGAGainInfo(AFE_BUFFER_AUDIO, &(pCnf->buf_info[0].i2MaxGain),
                        &(pCnf->buf_info[0].u2Step),
                        &(pCnf->buf_info[0].u2TotalLevel));
                AFE_GetPGAGainInfo(AFE_BUFFER_VOICE, &(pCnf->buf_info[1].i2MaxGain),
                        &(pCnf->buf_info[1].u2Step),
                        &(pCnf->buf_info[1].u2TotalLevel));
                pCnf->b_digital_gain_support = AFE_GetNVRAMDigitalGainSupport();
                l4aud_cnf.status = FT_CNF_OK;
#else // #if !defined(__SMART_PHONE_MODEM__)
                l4aud_cnf.status = FT_CNF_FAIL;
#endif // #if defined(__SMART_PHONE_MODEM__)
            }
            else
            {
                l4aud_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
        case FT_L4AUD_EX_OP_SET_ACF_IIR_EX:
        {
            buffer = get_pdu_ptr( ptrMsg->peer_buff_ptr, &bufferLength );
            ASSERT(bufferLength);
            if(custom_ftaudio_set_iir_coeff_v3(buffer, bufferLength))
            {
                l4aud_cnf.status = FT_CNF_OK;
            }
            else
            {
                l4aud_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
        case FT_L4AUD_EX_OP_SET_ACF_EX:
        {
#if defined(__AUDIO_COMPENSATION_SW_VERSION__)
            buffer = get_pdu_ptr( ptrMsg->peer_buff_ptr, &bufferLength );
            ASSERT(bufferLength);
            Media_SetAudioCompensation_SWFIR(buffer, bufferLength);
            l4aud_cnf.status = FT_CNF_OK;
#else // #if defined(__AUDIO_COMPENSATION_SW_VERSION__)
            l4aud_cnf.status = FT_CNF_FAIL;
#endif
            break;
        }
#ifdef __GAIN_TABLE_SUPPORT__
        case FT_L4AUD_EX_OP_GET_PGA_GAIN_MAP:
        {
            l4aud_cnf.status = FT_CNF_FAIL;
            if(l4aud_req->req.m_rPgaGainQuery.u2BufLevel==0)
            {
                break;
            }
            if(FT_L4AUD_PGA_BUF_AUDIO ==l4aud_req->req.m_rPgaGainQuery.i1BufType)
            {
                buf_type = AFE_BUFFER_AUDIO;
            }
            else if(FT_L4AUD_PGA_BUF_VOICE == l4aud_req->req.m_rPgaGainQuery.i1BufType)
            {
                buf_type = AFE_BUFFER_VOICE;
            }
            else if(FT_L4AUD_PGA_BUF_MIC ==  l4aud_req->req.m_rPgaGainQuery.i1BufType)
            {
                buf_type = AFE_BUFFER_MIC;
            }
            else //FT_L4AUD_PGA_BUF_UNKNOWN
            {
                buf_type = AFE_BUFFER_MIC;
            }
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(kal_int8)*(l4aud_req->req.m_rPgaGainQuery.u2BufLevel), 0, 0, TD_CTRL)) )
            {
                l4aud_cnf.status = FT_CNF_OK;
                buffer = get_pdu_ptr( peer_buff_ret, &bufferLength );
                // assign peer buffer
                peer_buff_ret->pdu_len = bufferLength;
                AFE_GetPGAGainMap(buf_type, l4aud_req->req.m_rPgaGainQuery.u2BufLevel, buffer);
            }
            break;
        }
        case FT_L4AUD_EX_OP_GET_EXT_PGA_GAIN_MAP:
        {
            l4aud_cnf.status = FT_CNF_FAIL;
            AFE_GetExtPGAInfo(l4aud_req->req.m_rExtAmpQuery.u1ExtDac,
                    l4aud_req->req.m_rExtAmpQuery.u2CtrlPoint,
                    &(l4aud_cnf.cnf.m_rExtAmpInfo.u1TotalLevel),
                    &(l4aud_cnf.cnf.m_rExtAmpInfo.u1BitNum));
            if(l4aud_cnf.cnf.m_rExtAmpInfo.u1TotalLevel ==0)
            {
                break;
            }
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(kal_int8)*(l4aud_cnf.cnf.m_rExtAmpInfo.u1TotalLevel), 0, 0, TD_CTRL)) )
            {
                l4aud_cnf.status = FT_CNF_OK;
                buffer = get_pdu_ptr( peer_buff_ret, &bufferLength );
                // assign peer buffer
                peer_buff_ret->pdu_len = bufferLength;
                AFE_GetExtPGAGainMap(l4aud_req->req.m_rExtAmpQuery.u1ExtDac,
                        l4aud_req->req.m_rExtAmpQuery.u2CtrlPoint,
                        l4aud_cnf.cnf.m_rExtAmpInfo.u1TotalLevel,
                        buffer);
            }
            break;
        }
#endif // end of #ifdef __GAIN_TABLE_SUPPORT__
#ifdef __SPEECH_MODE_TABLE_SUPPORT__
        case FT_L4AUD_EX_OP_GET_SPEECH_MODE_TABLE_INFO:
        {
            ft_l4aud_op_get_speech_mode_table_info();
            return;
        }
#endif // __SPEECH_MODE_TABLE_SUPPORT__
        case FT_L4AUD_EX_OP_START_RECORDING:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.m_StatusCode = ft_l4aud_ex_op_start_recording(
                    (ptrMsg->peer_buff_ptr) ? get_pdu_ptr( ptrMsg->peer_buff_ptr, &bufferLength) : NULL,
                    l4aud_req->req.m_rRecordingParam.requested_time,
                    l4aud_req->req.m_rRecordingParam.fmt,
                    l4aud_req->req.m_rRecordingParam.inputVolume);
            if( NULL != (peer_buff_ret=construct_peer_buff(kal_wstrlen(auto_record.filename)*2+sizeof(WCHAR), 0, 0, TD_CTRL)) )
            {
                buffer = get_pdu_ptr( peer_buff_ret, &bufferLength );
                peer_buff_ret->pdu_len = bufferLength;
                kal_wstrcpy((WCHAR*)buffer, auto_record.filename);
            }
            break;
        }
        case FT_L4AUD_EX_OP_STOP_RECORDING:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.m_StatusCode = ft_l4aud_ex_op_stop_recording();
            break;
        }
        case FT_L4AUD_EX_OP_QUERY_RECORDING:
        {
            l4aud_cnf.status = FT_CNF_OK;
            ft_l4aud_ex_op_query_recording(&l4aud_cnf);
            break;
        }
        case FT_L4AUD_EX_OP_START_ECHO_LOOP:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.m_StatusCode = Custom_META_FtStartDualMicEchoTest(&(l4aud_req->req.m_rEchoLoopParam));
            break;
        }
        case FT_L4AUD_EX_OP_STOP_ECHO_LOOP:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.m_StatusCode = Custom_META_FtStopDualMicEchoTest((void*)EVENT_STOP);
            break;
        }
        case FT_L4AUD_EX_OP_QUERY_ECHO_LOOP:
        {
            l4aud_cnf.status = FT_CNF_OK;
            Custom_META_FtQueryDualMicEchoTest(&l4aud_cnf);
            break;
        }
        case FT_L4AUD_EX_OP_QUERY_ECHO_LOOP_DATA_RATE:
        {
            PCM2WAY_QueryBufSize((P2W_Format)l4aud_req->req.pcm2WayFormat,
                    &(l4aud_cnf.cnf.m_rQueryEcholoopPcm2WayRate.recordingRate),
                    &(l4aud_cnf.cnf.m_rQueryEcholoopPcm2WayRate.playingRate));
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.m_rQueryEcholoopPcm2WayRate.playingRate =
                /* 20 ms per frame */l4aud_cnf.cnf.m_rQueryEcholoopPcm2WayRate.playingRate * 50 * sizeof(kal_int16);
            l4aud_cnf.cnf.m_rQueryEcholoopPcm2WayRate.recordingRate =
                /* 20 ms per frame */l4aud_cnf.cnf.m_rQueryEcholoopPcm2WayRate.recordingRate * 50 * sizeof(kal_int16);
            break;
        }
        case FT_L4AUD_EX_OP_QUERY_SPEECH_CAPABILITY:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.speechCapability = Media_GetSpeechFeatureCapability();
            break;
        }
#if defined(__HD_RECORD__)
        /* HD speech recording */
        case FT_L4AUD_EX_OP_SP_QUERY_PARAMS_OF_SPEECH_ENHANCEMENT_MODE:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.paramsOfSpeechEnhancement.numberOfSpeechEnhancementMode     = L1SP_GetNumOfAllEnhancementMode();
            l4aud_cnf.cnf.paramsOfSpeechEnhancement.bufferLengthOfEachModeName        = LEN_OF_ENHANCEMENT_MODE_NAME;
            l4aud_cnf.cnf.paramsOfSpeechEnhancement.numberOfSpeechEnhancementCategory = L1SP_GetNumOfAllEnhancementCategory();
            l4aud_cnf.cnf.paramsOfSpeechEnhancement.bufferLengthOfEachCategoryName    = LEN_OF_ENHANCEMENT_CATEGORY_NAME;
            break;
        }
        case FT_L4AUD_EX_OP_SP_QUERY_SPEECH_ENHANCEMENT_MODE_NAME:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.speechEnhancementModeNameHdr.numberOfSpeechEnhancementMode = L1SP_GetNumOfAllEnhancementMode();
            l4aud_cnf.cnf.speechEnhancementModeNameHdr.bufferLengthOfEachName        = LEN_OF_ENHANCEMENT_MODE_NAME;
            if( NULL != (peer_buff_ret=construct_peer_buff(L1SP_GetNumOfAllEnhancementMode() * LEN_OF_ENHANCEMENT_MODE_NAME, 0, 0, TD_RESET)) )
            {
                buffer = get_pdu_ptr( peer_buff_ret, &bufferLength );
                peer_buff_ret->pdu_len = bufferLength;
                L1SP_GetAllEnhancementModeName(L1SP_GetNumOfAllEnhancementMode() * LEN_OF_ENHANCEMENT_MODE_NAME, (kal_char*)buffer);
            }
            else
            {
                l4aud_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
        case FT_L4AUD_EX_OP_SP_QUERY_SPEECH_ENHANCEMENT_CATEGORY_NAME:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.speechEnahcnementCategoryNameHdr.numberOfSpeechEnhancementCategory = L1SP_GetNumOfAllEnhancementCategory();
            l4aud_cnf.cnf.speechEnahcnementCategoryNameHdr.bufferLengthOfEachName            = LEN_OF_ENHANCEMENT_CATEGORY_NAME;
            if( NULL != (peer_buff_ret=construct_peer_buff(L1SP_GetNumOfAllEnhancementCategory() * LEN_OF_ENHANCEMENT_CATEGORY_NAME, 0, 0, TD_RESET)) )
            {
                buffer = get_pdu_ptr( peer_buff_ret, &bufferLength );
                peer_buff_ret->pdu_len = bufferLength;
                L1SP_GetAllEnhancementCategoryName(L1SP_GetNumOfAllEnhancementCategory() * LEN_OF_ENHANCEMENT_CATEGORY_NAME, (kal_char*)buffer);
            }
            else
            {
                l4aud_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
        case FT_L4AUD_EX_OP_SP_QUERY_CATEGORY_OF_SPEECH_ENHANCEMENT_MODE:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.numberOfSpeechEnhancementMode = L1SP_GetNumOfAllEnhancementMode();
            if( NULL != (peer_buff_ret=construct_peer_buff(L1SP_GetNumOfAllEnhancementMode() * sizeof(kal_int16), 0, 0, TD_RESET)) )
            {
                buffer = get_pdu_ptr( peer_buff_ret, &bufferLength );
                peer_buff_ret->pdu_len = bufferLength;
                L1SP_GetAllEnhancementModeCategory(L1SP_GetNumOfAllEnhancementMode() * sizeof(kal_int16), (kal_int16*)buffer);
            }
            else
            {
                l4aud_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
        case FT_L4AUD_EX_OP_SP_QUERY_PARAMS_OF_SPEECH_FIR_MODE:
        {
            l4aud_cnf.status = FT_CNF_OK;        
            l4aud_cnf.cnf.paramsOfSpeechFir.numberOfAllFIRMode = L1SP_GetNumOfAllFir(l4aud_req->req.m_rQuerySpeechFirReq.isWideBand,l4aud_req->req.m_rQuerySpeechFirReq.isOutputFir);
            break;
        }        
#endif // #if defined(__HD_RECORD__)
#if defined(__BES_EQ_FLEXIBLE_SUPPORT__)
        case FT_L4AUD_EX_OP_AUDIO_QUERY_FLEXIBLE_EQ_BAND_NUM:
        {
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.numberOfFlexibleEqBands = Media_QueryBesEQMaxBandNum();
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
            break;
        }
        case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_MAGNITUDE:
        {
            l4aud_cnf.status = FT_CNF_OK;
            buffer = get_pdu_ptr( ptrMsg->peer_buff_ptr, &bufferLength );
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
            if(buffer)
            {
                AudioPP_Equalizer_SetMag_Flexible(buffer);
            }
            else
            {
                l4aud_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
        case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_INIT_PARAM:
        {
            l4aud_cnf.status = FT_CNF_OK;
            buffer = get_pdu_ptr( ptrMsg->peer_buff_ptr, &bufferLength );
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
            if(buffer)
            {
                Media_SetBesEQInitParam(buffer, bufferLength);
            }
            else
            {
                l4aud_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
        case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_ON_OFF:
        {
            l4aud_cnf.status = FT_CNF_OK;
            if(l4aud_req->req.flexibleEqOn == 1)
            {
                AudioPP_Equalizer_TurnOn();
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
            }
            else if(l4aud_req->req.flexibleEqOn == 0)
            {
                AudioPP_Equalizer_TurnOff();
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
            }
            else
            {
                l4aud_cnf.status = FT_CNF_FAIL;
            }
            break;
        }
#endif // #if defined(__BES_EQ_FLEXIBLE_SUPPORT__)
        case FT_L4AUD_EX_OP_AUDIO_QUERY_BESLOUDNESS_VERSION:
        {
#if defined(__BES_LOUDNESS_SUPPORT__)
            l4aud_cnf.status = FT_CNF_OK;
            l4aud_cnf.cnf.versionOfBesLoudness = Media_QueryBesLoudnessVersion();
#else
            l4aud_cnf.status = FT_CNF_FAIL;
#endif // #if defined(__BES_LOUDNESS_SUPPORT__)          
            break;
        }
        default:
        	  break;
    }
    ft_l4audio_ex_sendcnf(&l4aud_cnf, peer_buff_ret);
}
/**
 * FT task L4 Audio Ex operation dispatcher
 *
 * ======================== POLICY ========================
 * 1. !!!DO NOT wrap any compile option in this function!!!
 * ======================== POLICY ========================
 */
void FT_L4AudioEx_Operation(ilm_struct *ptrMsg)
{
    /// pointer to the L4Audio Ex request message sturcture
    FT_L4AUD_EX_REQ       *l4aud_req=((FT_L4AUD_EX_REQ *)ptrMsg->local_para_ptr);
    ft_gl_l4aud_token = l4aud_req->header.token;
    switch(l4aud_req->l4aud_op)
    {
        // type1: send confirm immediately.
        case FT_L4AUD_EX_OP_GET_DL_CAPABILITY:
        case FT_L4AUD_EX_OP_SET_ACF_IIR_EX:
        case FT_L4AUD_EX_OP_SET_ACF_EX:
        case FT_L4AUD_EX_OP_GET_PGA_GAIN_MAP:
        case FT_L4AUD_EX_OP_GET_EXT_PGA_GAIN_MAP:
        case FT_L4AUD_EX_OP_GET_SPEECH_MODE_TABLE_INFO:
        case FT_L4AUD_EX_OP_START_RECORDING:
        case FT_L4AUD_EX_OP_QUERY_RECORDING:
        case FT_L4AUD_EX_OP_STOP_RECORDING:
        case FT_L4AUD_EX_OP_START_ECHO_LOOP:
        case FT_L4AUD_EX_OP_STOP_ECHO_LOOP:
        case FT_L4AUD_EX_OP_QUERY_ECHO_LOOP:
        case FT_L4AUD_EX_OP_QUERY_ECHO_LOOP_DATA_RATE:
        case FT_L4AUD_EX_OP_QUERY_SPEECH_CAPABILITY:
        case FT_L4AUD_EX_OP_SP_QUERY_PARAMS_OF_SPEECH_ENHANCEMENT_MODE:
        case FT_L4AUD_EX_OP_SP_QUERY_SPEECH_ENHANCEMENT_MODE_NAME:
        case FT_L4AUD_EX_OP_SP_QUERY_SPEECH_ENHANCEMENT_CATEGORY_NAME:
        case FT_L4AUD_EX_OP_SP_QUERY_CATEGORY_OF_SPEECH_ENHANCEMENT_MODE:
        case FT_L4AUD_EX_OP_SP_QUERY_PARAMS_OF_SPEECH_FIR_MODE: 
        case FT_L4AUD_EX_OP_AUDIO_QUERY_FLEXIBLE_EQ_BAND_NUM:
        case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_MAGNITUDE:
        case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_INIT_PARAM:
        case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_ON_OFF:
        case FT_L4AUD_EX_OP_AUDIO_QUERY_BESLOUDNESS_VERSION:        	
        {
            ft_l4audio_ex_operation_type1(ptrMsg);
            break;
        }
        case FT_L4AUD_EX_OP_GET_GAIN_TABLE_INFO:
        {
            ft_l4audio_ex_op_get_gain_table_info(KAL_TRUE);
            return;
        }
        case FT_L4AUD_EX_OP_GET_GAIN_TABLE_STRING_INFO:
        {
            ft_l4audio_ex_op_get_gain_table_info(KAL_FALSE);
            return;
        }
        default: // do nothing, just let PC side get timeout operation!
            // store l4aud token id, because these commands of L4AUD command won't return immediately.
            //ft_gl_l4aud_token = l4aud_req->header.token;
            break;
    }
}
/*****************************************************
 * special code in secondary rom
 ****************************************************/
#pragma arm section code = "SECONDARY_ROCODE", rodata = "SECONDARY_RODATA"
/**
 * Run in HISR context
 */
void FtDualMicSpeakHandler( FT_AUTO_SPEAK_T* autoSpeak, kal_uint32 frameSize)
{
    memset( auto_speak.spk_buffer, 0, frameSize*sizeof(kal_int16) );
    {
        META_ECHO_LOOP_HANDLE *dl = autoSpeak->echo_loop_handle;
        if(dl)
        {
            /***********************************************************************
             * If the Ring buffer consists more than frameSize elements
             **********************************************************************/
            if( FT_PCMRB_GetDataCount( &dl->rb )>=frameSize )
            {
                FT_PCMRB_Read( &dl->rb , autoSpeak->spk_buffer , frameSize );
            }
            /***********************************************************************
             * Initiate producer request (ask task to read data from file and put to RB
             * task will be scheduled later
             **********************************************************************/
            if( dl->callback!=NULL )
            {
                /**************************************
                 * Call Custom_META_FtAutoSpeakCallback
                 *************************************/
                dl->callback( dl->host_data, EVENT_DATA_REQUEST );
            }
            /******************************************
             * initiate DSP request (put data to SPK)
             *****************************************/
            PCM2WAY_PutToSpk( (kal_uint16 *)autoSpeak->spk_buffer );
        }
        else
        {
            ASSERT(0);
        }
    }
}
/**
 * Run in HISR context
 */
void FtDualMicRecordHandler( FT_AUTO_RECORD_T* autoRecord, kal_uint32 frameSize)
{
    /*Regular recording*/
    memset( auto_record.mic_buffer, 0, frameSize*sizeof(kal_int16) );
    {
        META_ECHO_LOOP_HANDLE *ul = autoRecord->echo_loop_handle;
        if(ul)
        {
            /******************************************
             * initiate DSP request (Get data from MIC)
             *****************************************/
            PCM2WAY_GetFromMic( (kal_uint16 *)autoRecord->mic_buffer );
            /***********************************************************************
             * If the Ring buffer consists more than frameSize elements
             **********************************************************************/
            if( FT_PCMRB_GetFreeSpace( &ul->rb )>=frameSize )
            {
                FT_PCMRB_Write( &ul->rb , autoRecord->mic_buffer, frameSize );
            }
            /***********************************************************************
             * Initiate consumer request (ask task to read data from RB and put to file
             * task will be scheduled later
             **********************************************************************/
            if( ul->callback!=NULL )
            {
                /**************************************
                 * Call Custom_META_FtAutoRecCallback
                 *************************************/
                ul->callback( ul->host_data, EVENT_DATA_NOTIFY );
            }
        }
        else
        {
            ASSERT(0);
        }
    }
}
/**
 * This function used to handle event in HISR context (as a callback function called in HISR)
 * refer to bt_loopback.c bt_loopback_hisr
 */
void FtDualMicRecordingInHisr( void )
{
    /* Stop Recording */
    if(auto_record.sample_consume / FT_PCM2WAY_UL_FRAME_SIZE * 20 / sizeof(kal_uint16) >= auto_speak.sample_elapsed / FT_PCM2WAY_UL_FRAME_SIZE * 20)
    {
        if( auto_record.echo_loop_handle->callback!=NULL )
        {
            auto_record.echo_loop_handle->callback( auto_record.echo_loop_handle->host_data, EVENT_END);
            return;
        }
    }
    /*Regular recording*/
    Custom_META_FtDualMicRecordHandler(&auto_record, FT_PCM2WAY_UL_FRAME_SIZE);
}
/**
 * This function used to handle event in HISR context (as a callback function called in HISR)
 * refer to bt_loopback.c bt_loopback_hisr
 */
void FtDualMicEchoTestLoopbackInHisr( void )
{
    /*Initial Fill Silence */
    if(echoLoopManager.init_state < INIT_FILL_SILENCE )
    {
        memset( auto_speak.spk_buffer, 0, FT_PCM2WAY_DL_FRAME_SIZE*sizeof(kal_int16) );
        PCM2WAY_PutToSpk( (kal_uint16 *)auto_speak.spk_buffer );
        echoLoopManager.init_state++;
    }
    /*Stop Loopback*/
    if(echoLoopManager.playfile_eof == KAL_TRUE && echoLoopManager.stop_loopback == END_FILL_SILENCE)
    {
        if( auto_record.echo_loop_handle->callback!=NULL )
        {
            auto_record.echo_loop_handle->callback( auto_record.echo_loop_handle->host_data, EVENT_END);
            return;
        }
    }
    /*Finish Consuming all data in the RB of speak , then End Fill Silence*/
    if(echoLoopManager.stop_loopback < END_FILL_SILENCE &&
            FT_PCMRB_GetDataCount( &auto_speak.echo_loop_handle->rb )==0 &&
            echoLoopManager.playfile_eof == KAL_TRUE)
    {
        memset( auto_speak.spk_buffer, 0, FT_PCM2WAY_DL_FRAME_SIZE*sizeof(kal_int16) );
        PCM2WAY_PutToSpk( (kal_uint16 *)auto_speak.spk_buffer );
        echoLoopManager.stop_loopback ++;
    }
    /*Handle Play EOF , consume all data in the RB of speak*/
    if (echoLoopManager.playfile_eof == KAL_TRUE &&
            echoLoopManager.stop_loopback == 0 /*&& echoLoopManager.init_state == INIT_FILL_SILENCE*/)
    {
        if(FT_PCMRB_GetDataCount( &auto_speak.echo_loop_handle->rb )!=0)
        {
            memset( auto_speak.spk_buffer, 0, FT_PCM2WAY_DL_FRAME_SIZE*sizeof(kal_int16) );
            if(NULL!=auto_speak.echo_loop_handle)
            {
                META_ECHO_LOOP_HANDLE *dl = NULL;
                dl = auto_speak.echo_loop_handle;
                if( FT_PCMRB_GetDataCount( &dl->rb )>=FT_PCM2WAY_DL_FRAME_SIZE )
                {
                    FT_PCMRB_Read( &dl->rb , auto_speak.spk_buffer , FT_PCM2WAY_DL_FRAME_SIZE );
                }
                else
                {
                    kal_int32 read_len;
                    read_len =  FT_PCMRB_GetDataCount( &dl->rb );
                    FT_PCMRB_Read( &dl->rb , auto_speak.spk_buffer , read_len );
                    echoLoopManager.stop_loopback ++;
                }
                PCM2WAY_PutToSpk( (kal_uint16 *)auto_speak.spk_buffer );
            }
        }
    }
    /*Regular playing*/
    if (echoLoopManager.playfile_eof == KAL_FALSE && echoLoopManager.stop_loopback==0
            && echoLoopManager.init_state == INIT_FILL_SILENCE)
    {
        Custom_META_FtDualMicSpeakHandler(&auto_speak, FT_PCM2WAY_DL_FRAME_SIZE);
    }
    /*Regular recording*/
    if(echoLoopManager.init_state >= INIT_FILL_SILENCE)
    {
        Custom_META_FtDualMicRecordHandler(&auto_record, FT_PCM2WAY_UL_FRAME_SIZE);
    }
}

/*
 * Description
 * ---------
 *   The function initializes the ring buffer instance.
 *
 * Syntax
 * ---------
 *   bool FT_PCMRB_Init( FT_PCMRB *rb, int16 *buffer, int32 buffer_size )
 *
 * where
 *   rb   The ring buffer instance
 *   buffer        Address of the memory allocated for the ring buffer
 *   buffer_size   Size of the memory allocated for the ring buffer
 *
 * Return Value
 * ---------
 *   true
 *   false
 */
kal_bool FT_PCMRB_Init( FT_PCMRB *rb, int16 *buffer, int32 buffer_size )
{
    FtAssertionCheckStatement = (rb != NULL) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    memset( buffer, 0, buffer_size*sizeof(int16) );
    rb->buffer = buffer;
    rb->size = buffer_size;
    rb->read = 0;
    rb->write = 0;

    return KAL_TRUE;
}

/*
 * Description
 * ---------
 *   The function returns the available free space of the ring buffer instance.
 *
 * Syntax
 * ---------
 *   int32 FT_PCMRB_GetFreeSpace( FT_PCMRB *rb )
 *
 * where
 *   rb   The ring buffer instance
 *
 * Return Value
 * ---------
 *   the free space in words
 */
kal_int32 FT_PCMRB_GetFreeSpace( FT_PCMRB *rb )
{
    kal_int32 count;
    FtAssertionCheckStatement = (rb!=NULL) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    count = rb->read - rb->write - 1;
    if( 0>count )
        count += rb->size;
    return count;
}

/*
 * Description
 * ---------
 *   The function returns available data count of the ring buffer instance
 *
 * Syntax
 * ---------
 *   int32 FT_PCMRB_GetDataCount( FT_PCMRB *rb )
 *
 * where
 *   rb   The ring buffer instance
 *
 * Return Value
 * ---------
 *   the data count in words
 */
kal_int32 FT_PCMRB_GetDataCount( FT_PCMRB *rb )
{
    kal_int32 count;
    FtAssertionCheckStatement = (rb!=NULL) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    count = rb->write - rb->read;
    if( 0>count )
        count += rb->size;
    return count;
}

/*
 * Description
 * ---------
 *   The function copies data from a linear array to a ring buffer instance.
 *   The free space of the ring buffer instance shall be enough, or assertion will happen
 *
 * Syntax
 * ---------
 *   void FT_PCMRB_Write( FT_PCMRB *dest_rb, int16 *src_buffer, int32 size )
 *
 * where
 *   dest_rb   The ring buffer instance
 *   src_buffer        Address of the linear array
 *   size   Size of copy
 *
 * Return Value
 * ---------
 *   none
 */
void FT_PCMRB_Write( FT_PCMRB *dest_rb, kal_int16 *src_buffer, kal_int32 size )
{
    kal_int16 *write_ptr;
    kal_int32 write_cnt;
    FtAssertionCheckStatement = (dest_rb!=NULL) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );
    FtAssertionCheckStatement = (FT_PCMRB_GetFreeSpace( dest_rb )>=size) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    FT_PCMRB_GetWriteBlock( dest_rb, &write_ptr, &write_cnt );
    if( write_cnt>size ) write_cnt = size;

    if( src_buffer == (int16 *)NULL ) memset( write_ptr, 0, write_cnt*sizeof(int16) );
    else memcpy( write_ptr, src_buffer, write_cnt*sizeof(int16) );

    FT_PCMRB_ShiftWritePointer( dest_rb, write_cnt );
    size -= write_cnt;

    if( size>0 )
    {
        if( src_buffer != (int16 *)NULL ) src_buffer += write_cnt;

        FT_PCMRB_GetWriteBlock( dest_rb, &write_ptr, &write_cnt );
        if( write_cnt>size ) write_cnt = size;

        if( src_buffer == (int16 *)NULL ) memset( write_ptr, 0, write_cnt*sizeof(int16) );
        else memcpy( write_ptr, src_buffer, write_cnt*sizeof(int16) );

        FT_PCMRB_ShiftWritePointer( dest_rb, write_cnt );
    }
}

/*
 * Description
 * ---------
 *   The function copies data from a ring buffer instance to a linear array
 *   The data count of the ring buffer instance shall be enough, or assertion will happen
 *
 * Syntax
 * ---------
 *   void FT_PCMRB_Read( FT_PCMRB *src_rb, int16 *dest_buffer, int32 size )
 *
 * where
 *   src_rb   The ring buffer instance
 *   dest_buffer        Address of the linear array
 *   size   Size of copy
 *
 * Return Value
 * ---------
 *   none
 */
void FT_PCMRB_Read( FT_PCMRB *src_rb, kal_int16 *dest_buffer, kal_int32 size )
{
    kal_int16 *read_ptr;
    kal_int32 read_cnt;
    FtAssertionCheckStatement = (src_rb!=NULL) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );
    FtAssertionCheckStatement = (FT_PCMRB_GetDataCount( src_rb )>=size) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    FT_PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
    if( read_cnt>size ) read_cnt = size;
    memcpy( dest_buffer, read_ptr, read_cnt*sizeof(int16) );
    FT_PCMRB_ShiftReadPointer( src_rb, read_cnt );
    size -= read_cnt;

    if( size>0 )
    {
        dest_buffer += read_cnt;
        FT_PCMRB_GetReadBlock( src_rb, &read_ptr, &read_cnt );
        if( read_cnt>size ) read_cnt = size;
        memcpy( dest_buffer, read_ptr, read_cnt*sizeof(int16) );
        FT_PCMRB_ShiftReadPointer( src_rb, read_cnt );
    }
}

/*
 * Description
 * ---------
 *   The function returns the linear write block and its size of a ring buffer instance
 *
 * Syntax
 * ---------
 *   void FT_PCMRB_GetWriteBlock( FT_PCMRB *dest_rb, int16 **write_ptr, int32 *write_cnt )
 *
 * where
 *   dest_rb   The ring buffer instance
 *   write_ptr        Address of the memory to put the address of the linear write block
 *   write_cnt   Address of the memory to put the size of the linear write block
 *
 * Return Value
 * ---------
 *   none
 */
void FT_PCMRB_GetWriteBlock( FT_PCMRB *dest_rb, kal_int16 **write_ptr, kal_int32 *write_cnt )
{
    kal_int32 cnt;
    FtAssertionCheckStatement = ((dest_rb!=NULL) && (write_ptr!=NULL) && (write_cnt!=NULL)) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    if( dest_rb->read>dest_rb->write )
        cnt = dest_rb->read - dest_rb->write - 1;
    else if( dest_rb->read==0 )
        cnt = dest_rb->size - dest_rb->write - 1;
    else
        cnt = dest_rb->size - dest_rb->write;

    *write_cnt = cnt;
    *write_ptr = &dest_rb->buffer[dest_rb->write];
}

/*
 * Description
 * ---------
 *   The function returns the linear read block and its size of a ring buffer instance
 *
 * Syntax
 * ---------
 *   void FT_PCMRB_GetReadBlock( FT_PCMRB *src_rb, int16 **read_ptr, int32 *read_cnt )
 *
 * where
 *   src_rb   The ring buffer instance
 *   read_ptr        Address of the memory to put the address of the linear read block
 *   read_cnt   Address of the memory to put the size of the linear read block
 *
 * Return Value
 * ---------
 *   none
 */
void FT_PCMRB_GetReadBlock( FT_PCMRB *src_rb, kal_int16 **read_ptr, kal_int32 *read_cnt )
{
    kal_int32 cnt;
    FtAssertionCheckStatement = ((src_rb!=NULL) && (read_ptr!=NULL) && (read_cnt!=NULL)) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    if( src_rb->write>src_rb->read )
        cnt = src_rb->write - src_rb->read;
    else
        cnt = src_rb->size - src_rb->read;

    *read_cnt = cnt;
    *read_ptr = &src_rb->buffer[src_rb->read];
}

/*
 * Description
 * ---------
 *   The function shifts the write pointer of a ring buffer instance in circular way
 *   Use this with FT_PCMRB_GetWriteBlock
 *
 * Syntax
 * ---------
 *   void FT_PCMRB_ShiftWritePointer( FT_PCMRB *rb, int32 shamt )
 *
 * where
 *   rb   The ring buffer instance
 *   shamt        shift amount
 *
 * Return Value
 * ---------
 *   none
 */
void FT_PCMRB_ShiftWritePointer( FT_PCMRB *rb, kal_int32 shamt )
{
    FtAssertionCheckStatement = (rb!=NULL) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    rb->write += shamt;
    if( rb->write>=rb->size )
        rb->write -= rb->size;
}

/*
 * Description
 * ---------
 *   The function shifts the read pointer of a ring buffer instance in circular way
 *   Use this with FT_PCMRB_GetReadBlock
 *
 * Syntax
 * ---------
 *   void FT_PCMRB_ShiftReadPointer( FT_PCMRB *rb, int32 shamt )
 *
 * where
 *   rb   The ring buffer instance
 *   shamt        shift amount
 *
 * Return Value
 * ---------
 *   none
 */
void FT_PCMRB_ShiftReadPointer( FT_PCMRB *rb, kal_int32 shamt )
{
    FtAssertionCheckStatement = (rb!=NULL) ? KAL_TRUE : KAL_FALSE;
    ASSERT( FtAssertionCheckStatement );

    rb->read += shamt;
    if( rb->read>=rb->size )
        rb->read -= rb->size;
}
/**
 * This function acts as speak callback function (called in HISR context)
 * 1. HISR context only execute the InProcCall to sends message to MED
 * 2. MED received message, it will cal the registered callback function to
 * Get the buffer from file and then dump to RB
 */
void FtAutoSpeakCallback( void *host_data, META_ECHO_LOOP_EVENT event )
{
    if (auto_speak.waiting == KAL_TRUE)
    {
        return;
    }
    if( FT_PCMRB_GetFreeSpace( &auto_speak.echo_loop_handle->rb ) >= 1024 )
    {
        auto_speak.waiting = KAL_TRUE;
        ft_send_in_proc_call_req( Custom_META_FtAutoSpeakGetDataFromFileToRB, 0, 0);
    }
}
/**
 * This function used as record callback function (called in HISR context)
 * 1. HISR context only execute the InProcCall to sends message to MED
 * 2. MED received message, it will cal the registered callback function to
 * Get the buffer from RB and then dump to File
 */
void FtAutoRecCallback( void *host_data, META_ECHO_LOOP_EVENT event )
{
    if (auto_record.waiting == KAL_TRUE)
    {
        return;
    }
    if(event == EVENT_END)
    {
        auto_record.waiting = KAL_TRUE;
        ft_send_in_proc_call_req( Custom_META_FtAutoRecGetDataFromRBToFile, 0, (void *)event );
    }
    if( FT_PCMRB_GetDataCount( &auto_record.echo_loop_handle->rb ) >= 1024 )
    {
        auto_record.waiting = KAL_TRUE;
        ft_send_in_proc_call_req( Custom_META_FtAutoRecGetDataFromRBToFile, 0, 0 );
    }
}
#pragma arm section code, rodata
kal_uint32 FT_AudioCheckFunctionSupported(kal_uint32 query_op_code)
{
    kal_uint32 cnf_code;
    if( FT_L4AUD_OP_END > query_op_code )
    {
        switch(query_op_code)
        {
#ifndef MED_NOT_PRESENT
            // 20100105 phase out play audio by id
            case FT_L4AUD_OP_AUDIO_QUERY_ID:
            case FT_L4AUD_OP_AUDIO_PLAY:
                cnf_code = FT_CNF_FAIL;
                break;
            case FT_L4AUD_OP_GET_PROFILE_SETTINGS_BY_MODE:
            case FT_L4AUD_OP_SET_PROFILE_SETTINGS_BY_MODE:
            case FT_L4AUD_OP_GET_PARAM_SETTINGS_0809:
            case FT_L4AUD_OP_SET_PARAM_SETTINGS_0809:
            case FT_L4AUD_OP_SET_VOLUME:
            case FT_L4AUD_OP_AUDIO_PLAY_BY_NAME:
            case FT_L4AUD_OP_AUDIO_DEMO_IMY:
            case FT_L4AUD_OP_AUDIO_STOP:
            case FT_L4AUD_OP_SET_MODE:
                cnf_code = FT_CNF_OK;
                break;
#endif // #ifndef MED_NOT_PRESENT
            case FT_L4AUD_OP_SET_ECHO:
                cnf_code = FT_CNF_OK;
                break;
#ifndef __L1_STANDALONE__
            case FT_L4AUD_OP_SET_GAIN:
                cnf_code = FT_CNF_OK;
                break;
#endif
            case FT_L4AUD_OP_PLAY_FREQ_VOL_TONE:
            case FT_L4AUD_OP_STOP_FREQ_VOL_TONE:
                cnf_code = FT_CNF_OK;
                break;
            case FT_L4AUD_OP_TONE_LOOP_BACK_REC: // obsolete this function
                cnf_code = FT_CNF_FAIL;
                break;
            case FT_L4AUD_OP_TONE_LOOP_BACK_REC_2K:
            case FT_L4AUD_OP_TONE_LOOP_BACK_REC_2K_NORMAL:
                cnf_code = FT_CNF_OK;
                break;
            case FT_L4AUD_OP_SET_LOUDSPK_FIR_COEFFS:
            case FT_L4AUD_OP_SET_SPEECH_COMMON:
            case FT_L4AUD_OP_SET_LOUDSPK_MODE:
                cnf_code = FT_CNF_OK;
                break;
            case FT_L4AUD_OP_SET_PLAYBACK_MAX_SWING:
                cnf_code = FT_CNF_OK;
                break;
            case FT_L4AUD_OP_SET_MELODY_FIR:
            case FT_L4AUD_OP_SET_SPEECH_COMMON_AND_MODE:
                cnf_code = FT_CNF_OK;
                break;


            case FT_L4AUD_OP_SET_OUTPUT_DEV:
            case FT_L4AUD_OP_SET_OUTPUT_VOLUME:
            case FT_L4AUD_OP_SET_OUTPUT_DEV_EX:
                cnf_code = FT_CNF_OK;
                break;
#if defined(WAV_CODEC) && !defined(__L1_STANDALONE__)
            case FT_L4AUD_OP_PLAY_WAVE_FILE_BY_STREAM:
            case FT_L4AUD_OP_FREE_MEMORY:
            case FT_L4AUD_OP_PLAY_CUR_MEMORY_CONTENT:
            case FT_L4AUD_OP_STOP_L1AUD_PLAYING:
                cnf_code = FT_CNF_OK;
                break;

#endif // #if defined(WAV_CODEC) && !defined(__L1_STANDALONE__)
#if defined(AUDIO_COMPENSATION_ENABLE) && !defined(__SMART_PHONE_MODEM__)
            case FT_L4AUD_OP_GET_AC_FILTER_TYPE:
            case FT_L4AUD_OP_SET_AC_FILTER_COEFF:
                cnf_code = FT_CNF_OK;
                break;
#endif // #if defined(AUDIO_COMPENSATION_ENABLE) && !defined(__SMART_PHONE_MODEM__)
            case FT_L4AUD_OP_GET_GAIN_TYPE_SUPPORT:
                cnf_code = FT_CNF_OK;
                break;
            default:
                cnf_code = FT_CNF_FAIL;
                break;
        }
    }
    else
    {
        cnf_code = FT_CNF_FAIL;
    }
    return cnf_code;
}
kal_uint32 FT_AudioExCheckFunctionSupported(kal_uint32 query_op_code)
{
    kal_uint32 cnf_code;
    if( FT_L4AUD_EX_OP_END > query_op_code )
    {
        switch(query_op_code)
        {
            case FT_L4AUD_EX_OP_GET_DL_CAPABILITY:
            case FT_L4AUD_EX_OP_QUERY_SPEECH_CAPABILITY:
            {
#if !defined(__SMART_PHONE_MODEM__)
                cnf_code = FT_CNF_OK;
#else
                cnf_code = FT_CNF_FAIL;
#endif
                break;
            }
            //case FT_L4AUD_EX_OP_SET_ACF_IIR: (must phase-out)
            case FT_L4AUD_EX_OP_SET_ACF_IIR_EX:
            case FT_L4AUD_EX_OP_AUDIO_QUERY_BESLOUDNESS_VERSION:
            {
                if(custom_ft_audio_query_iir_support())
                    cnf_code = FT_CNF_OK;
                else
                    cnf_code = FT_CNF_FAIL;
                break;
            }
#if defined(__AUDIO_COMPENSATION_SW_VERSION__)
            case FT_L4AUD_EX_OP_SET_ACF_EX:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if defined(__AUDIO_COMPENSATION_SW_VERSION__)
#ifdef __GAIN_TABLE_SUPPORT__
            case FT_L4AUD_EX_OP_GET_GAIN_TABLE_INFO:
            case FT_L4AUD_EX_OP_GET_PGA_GAIN_MAP:
            case FT_L4AUD_EX_OP_GET_EXT_PGA_GAIN_MAP:
            case FT_L4AUD_EX_OP_GET_GAIN_TABLE_STRING_INFO:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // end if __GAIN_TABLE_SUPPORT__
            case FT_L4AUD_EX_OP_GET_SPEECH_MODE_TABLE_INFO:
            {
                if(custom_ft_get_speech_mode_table_support())
                    cnf_code = FT_CNF_OK;
                else
                    cnf_code = FT_CNF_FAIL;
            }
            break;
            case FT_L4AUD_EX_OP_START_RECORDING:
            case FT_L4AUD_EX_OP_STOP_RECORDING:
            case FT_L4AUD_EX_OP_QUERY_RECORDING:
            case FT_L4AUD_EX_OP_START_ECHO_LOOP:
            case FT_L4AUD_EX_OP_STOP_ECHO_LOOP:
            case FT_L4AUD_EX_OP_QUERY_ECHO_LOOP:
            case FT_L4AUD_EX_OP_QUERY_ECHO_LOOP_DATA_RATE:
            {
                if(Custom_META_DualMicSupported())
                {
                    cnf_code = FT_CNF_OK;
                }
                else
                {
#if defined(__HD_RECORD__)
                    cnf_code = FT_CNF_OK;
#else
                    cnf_code = FT_CNF_FAIL;
#endif // defined(__HD_RECORD__)
                }
                break;
            }
#if defined(__HD_RECORD__)
            case FT_L4AUD_EX_OP_SP_QUERY_PARAMS_OF_SPEECH_ENHANCEMENT_MODE:
            case FT_L4AUD_EX_OP_SP_QUERY_SPEECH_ENHANCEMENT_MODE_NAME:
            case FT_L4AUD_EX_OP_SP_QUERY_SPEECH_ENHANCEMENT_CATEGORY_NAME:
            case FT_L4AUD_EX_OP_SP_QUERY_CATEGORY_OF_SPEECH_ENHANCEMENT_MODE:
            case FT_L4AUD_EX_OP_SP_QUERY_PARAMS_OF_SPEECH_FIR_MODE:            
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if defined(__HD_RECORD__)
#if defined(__BES_EQ_FLEXIBLE_SUPPORT__)
            case FT_L4AUD_EX_OP_AUDIO_QUERY_FLEXIBLE_EQ_BAND_NUM:
            case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_MAGNITUDE:
            case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_INIT_PARAM:
            case FT_L4AUD_EX_OP_AUDIO_SET_FLEXIBLE_EQ_ON_OFF:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if defined(__BES_EQ_FLEXIBLE_SUPPORT__)
            default:
                cnf_code = FT_CNF_FAIL;
                break;
        }
    }
    else
    {
        cnf_code = FT_CNF_FAIL;
    }
    return cnf_code;
}
#else // #if (!defined(__SMART_PHONE_MODEM__))
/* Dummy function */
void FT_InitL4AUD(void)
{
}
#endif // #if defined(__SMART_PHONE_MODEM__)
