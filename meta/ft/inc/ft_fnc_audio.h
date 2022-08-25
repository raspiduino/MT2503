/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_audio.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Audio Function
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#ifndef _FT_FNC_AUDIO_H_
#define _FT_FNC_AUDIO_H_
#include "app_ltlcom.h"
/********************************
 * APIs for FT reference
 *******************************/
void FT_InitL4AUD(void);
kal_uint32 FT_AudioCheckFunctionSupported(kal_uint32 query_op_code);
kal_uint32 FT_AudioExCheckFunctionSupported(kal_uint32 query_op_code);
void FT_L4Audio_Operation(ilm_struct *ptrMsg);
void FT_L4AudioEx_Operation(ilm_struct *ptrMsg);
void FT_L4AudioOpSendConfirm(ilm_struct* ptrMsg);
void ft_audio_play_wave_event_callback(ilm_struct *ptrMsg);
void ft_free_pcm_buffer(void** p, kal_uint16 indicator);
void FT_L4Audio_MedConfirm(ilm_struct* ilm_ptr);
#endif // #ifndef _FT_FNC_AUDIO_H_
