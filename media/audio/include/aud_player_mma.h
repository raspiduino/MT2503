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
*  aud_player_mma.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   MMA Player definitions
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

 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/
#ifndef MED_NOT_PRESENT

#ifndef __MED_AUD_MMA_PLAYER__
#define __MED_AUD_MMA_PLAYER__

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/
#include "aud_player.h"
#include "kal_general_types.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
 ----------------------------------------------------------------------------*/
typedef struct
{
    kal_uint8 channel;        /* IN */
    kal_uint8* volume_p;      /* OUT */
} med_aud_player_mma_get_channel_volume_t;

typedef struct
{
    kal_uint8 channel;        /* IN */
    kal_int16* bank_p;        /* OUT */
    kal_int8* program_p;      /* OUT */
} med_aud_player_mma_get_program_t;

typedef struct
{
    kal_bool custom;          /* IN */
    const kal_int16** buf_p;  /* OUT */
    kal_int16* len_p;         /* OUT */
} med_aud_player_mma_get_bank_list_t;

typedef struct
{
    kal_int16 bank;           /* IN */
    const kal_int8** buf_p;   /* OUT */
    kal_int16 *len_p;         /* OUT */
} med_aud_player_mma_get_program_list_t;

typedef struct
{
    kal_int16 bank;           /* IN */
    kal_int8 program;         /* IN */
    const kal_uint8** name_p; /* OUT */
} med_aud_player_mma_get_program_name_t;

typedef struct
{
    kal_int16 bank;           /* IN */
    kal_int8 program;         /* IN */
    kal_int8 key;             /* IN */
    const kal_uint8** name_p; /* OUT */
} med_aud_player_mma_get_key_name_t;

typedef struct
{
    kal_uint8 channel;
    kal_uint8 level;
} med_aud_player_mma_set_channel_volume_t;

typedef struct
{
    kal_uint8* data_p;
    kal_int32 size;
    kal_int16 repeats;
} med_aud_player_mma_set_data_t;

typedef struct
{
    kal_uint8 channel;
    kal_uint8 bank;
    kal_uint8 program;
} med_aud_player_mma_set_program_t;

typedef struct
{
    kal_uint8* buf_p;
    kal_uint16 len;
} med_aud_player_mma_set_long_msg_t;

typedef struct
{
    kal_uint8 type;
    kal_uint8 data1;
    kal_uint8 data2;
} med_aud_player_mma_set_short_msg_t;

/* Get commands of MMA Player */
typedef enum
{
    
    MMA_PLAYER_GET_EXT_EVENT        /* JSmf: An extended event which includus several melody events (Media_Event*) */
        = AUD_PLAYER_CMD_OFFSET_MMA,
    MMA_PLAYER_GET_CHANNEL_VOLUME,  /* JMidi: Get channel volume (med_aud_player_mma_get_channel_volume_t*) */
    MMA_PLAYER_GET_PITCH,           /* JTone, JMidi: Get pitch (kal_int32*) */
    MMA_PLAYER_GET_RATE,            /* JTone, JMidi: Get rate (kal_int32*) */
    MMA_PLAYER_GET_TEMPO,           /* JMidi: Get tempo (kal_int32*) */
    MMA_PLAYER_GET_PROGRAM,         /* JMidi: Get program (med_aud_player_mma_get_program_t*) */
    MMA_PLAYER_GET_BANK_LIST,       /* JMidi: Get bank list (med_aud_player_mma_get_bank_list_t*) */
    MMA_PLAYER_GET_PROGRAM_LIST,    /* JMidi: Get program list (med_aud_player_mma_get_program_list_t*) */
    MMA_PLAYER_GET_PROGRAM_NAME,    /* JMidi: Get program name (med_aud_player_mma_get_program_name_t*) */
    MMA_PLAYER_GET_KEY_NAME,        /* JMidi: Get key name (med_aud_player_mma_get_key_name_t*) */
    MMA_PLAYER_GET_IS_BANK_SUPPORT, /* JMidi: Check if bank is supported (kal_bool*) */
    MMA_PLAYER_GET_IS_SP_MIDI,      /* JSmf: Check if it's a SP MIDI (kal_bool*) */
    
    MMA_PLAYER_GET_LAST_ENTRY
    
} med_aud_player_mma_get_t;

/* Set commands of MMA Player */
typedef enum
{ 
    MMA_PLAYER_SET_CHANNEL_VOLUME   /* JTone, JMidi: Set channel volume (med_aud_player_mma_set_channel_volume_t*) */       
        = AUD_PLAYER_CMD_OFFSET_MMA,
    MMA_PLAYER_SET_DATA,            /* JTone: Set data (med_aud_player_mma_set_data_t*) */
    MMA_PLAYER_SET_PITCH,           /* JTone, JMidi: Set pitch (kal_int32) */
    MMA_PLAYER_SET_PROGRAM,         /* JMidi: Set program (med_aud_player_mma_set_program_t*) */
    MMA_PLAYER_SET_RATE,            /* JTone, JMidi: Set rate (kal_int32) */
    MMA_PLAYER_SET_TEMPO,           /* JMidi: Set tempo (kal_int32) */
    MMA_PLAYER_SET_LONG_MSG,        /* JMidi: Set long message (med_aud_player_mma_set_long_msg_t*) */
    MMA_PLAYER_SET_SHORT_MSG,       /* JMidi: Set short message (med_aud_player_mma_set_short_msg_t*) */
    
    MMA_PLAYER_SET_LAST_ENTRY
    
} med_aud_player_mma_set_t;


#endif /* __MED_AUD_MMA_PLAYER__ */
#endif /* MED_NOT_PRESENT */

