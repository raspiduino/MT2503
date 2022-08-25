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
 *   bitstream_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function prototypes of bitstream APIs.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef _BITSTREAM_API_H
#define _BITSTREAM_API_H

#include "kal_general_types.h"
#include "stack_config.h"
#include "med_struct.h"
    
/*----------------------------------------------------------------*/
/* Defines                                                        */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Enums                                                          */
/*----------------------------------------------------------------*/

/* Get type of bitstream recorder */
typedef enum
{ 
    BITSTREAM_RECORD_GET_LENGTH, /* Get the length of recorded data (U16*) */
    BITSTREAM_RECORD_GET_DATA,   /* Get recorded data (U16*) */
    BITSTREAM_RECORD_GET_STRENGTH, /* Get recorded strength (U32*) */

    BITSTREAM_RECORD_GET_LAST_ENTRY
} bitstream_record_get_type_enum;

/* Set type of bitstream recorder */
typedef enum
{ 
    BITSTREAM_RECORD_SET_PAUSE,  /* Pause bitstream record */
    BITSTREAM_RECORD_SET_RESUME, /* Resume bitstream record */
    BITSTREAM_RECORD_SET_CB_THRESHOLD, /* Callback threshold */

    BITSTREAM_RECORD_SET_LAST_ENTRY
} bitstream_record_set_type_enum;

/*----------------------------------------------------------------*/
/* Structs                                                        */
/*----------------------------------------------------------------*/

typedef struct
{
    kal_uint8 codec_type;
    /* parameters below are only for pcm type*/
    kal_bool isStereo; /* KAL_FALSE: mono, KAL_TRUE: stereo*/
    kal_int8 bitPerSample; /* 8 or 16, commonly use 16 bits*/
    kal_uint16 sampleFreq; /* 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000*/
}
bitstream_audio_open_param_struct;


/*----------------------------------------------------------------*/
/* Function Definitions                                           */
/*----------------------------------------------------------------*/
/* common */
extern void bitstream_send_msg(module_type src_id, module_type dst_id, kal_uint16 msg_id, void *local_param_ptr);

/* audio */
extern kal_int32 media_bitstream_audio_open_handle(module_type src_mod_id, kal_int32 *handle, bitstream_audio_open_param_struct *open_param);
extern kal_int32 media_bitstream_audio_close(module_type src_mod_id, kal_int32 handle);
extern kal_int32 media_bitstream_audio_get_buffer_status(module_type src_mod_id, kal_int32 handle, kal_uint32 *total_size, kal_uint32 *free_size);
extern kal_int32 media_bitstream_audio_put_data(module_type src_mod_id, kal_int32 handle, kal_uint8 *app_buf, kal_uint32 app_buf_size, kal_uint32 *used_size);
extern kal_int32 media_bitstream_audio_put_frame(module_type src_mod_id, kal_int32 handle, kal_uint8 *app_buf, kal_uint32 app_buf_size, kal_uint64 timestamp);
extern kal_int32 media_bitstream_audio_start(module_type src_mod_id, kal_int32 handle, kal_uint32 start_time, kal_uint8 audio_path, kal_uint8 volume);
extern kal_int32 media_bitstream_audio_stop(module_type src_mod_id, kal_int32 handle);
extern kal_int32 media_bitstream_audio_finished(module_type src_mod_id, kal_int32 handle);
extern kal_int32 media_bitstream_audio_get_play_time(module_type src_mod_id, kal_int32 handle, kal_uint32 *play_time);

/* record */
extern kal_int32 media_bitstream_record_open(kal_uint8 codec_type, kal_uint8 quality, kal_int32 *handle_p);
extern kal_int32 media_bitstream_record_close(kal_int32 handle);
extern kal_int32 media_bitstream_record_start(kal_int32 handle);
extern kal_int32 media_bitstream_record_stop(kal_int32 handle);
extern kal_int32 media_bitstream_record_set(kal_int32 handle, kal_uint8 set_type, void* data_p, kal_uint16 data_len);
extern kal_int32 media_bitstream_record_get(kal_int32 handle, kal_uint8 get_type, void* data_p, kal_uint16* data_len_p);


/*----------------------------------------------------------------*/
/* Global variable                                                */
/*----------------------------------------------------------------*/

#endif /* _BITSTREAM_API_H */ 



