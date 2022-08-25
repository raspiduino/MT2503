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
 *   npplg_struct.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   This file includes the structures exported by NPAPI Plug-in.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef NPPLG_STRUCT_H
#define NPPLG_STRUCT_H

#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"
#include "gdi_include.h"


/************************************************************
 * Define
 ************************************************************/

/* Maximum filepatch length */
#ifndef SRV_FMGR_PATH_MAX_LEN
#define NPPLG_MAX_FILEPATH_LEN 260  /* SRV_FMGR_PATH_MAX_LEN + 1 */
#else
#define NPPLG_MAX_FILEPATH_LEN (SRV_FMGR_PATH_MAX_LEN + 1)
#endif

/* Maximum title length */
#define NPPLG_MAX_TITLE_LEN 101


/************************************************************
 * Typedef
 ************************************************************/

/* Which player plug-in should launch */
typedef enum
{
  NPPLG_AV_PLAYER_TYPE_AUDIO = 0,
  NPPLG_AV_PLAYER_TYPE_VIDEO,
  NPPLG_AV_PLAYER_TYPE_STREAM
} npplg_av_player_type_enum;

/* Which action plug-in should do when plug-in handle MSG_ID_NPPLG_AV_NOTIFY_MMI_IND */
typedef enum
{
  NPPLG_AV_ACTION_SET_VOLUME            = 0x01,
  NPPLG_AV_ACTION_SET_MUTE              = 0X02,
  NPPLG_AV_ACTION_TURN_ON_BACKLIGHT     = 0X04,
  NPPLG_AV_ACTION_TURN_OFF_BACKLIGHT    = 0X08,
  NPPLG_AV_ACTION_OPEN_AUDIO            = 0X10,
  NPPLG_AV_ACTION_SEND_PLAY_IND         = 0X20,
  NPPLG_AV_ACTION_TERMINATE_BGPLAY      = 0X40,
  NPPLG_AV_ACTION_TOTAL                 = 0X80
} npplg_av_action_enum;


/************************************************************
 * Structure
 ************************************************************/

/* The structure for MSG_ID_NPPLG_AV_LAUNCH_MEDIA_PLAYER_IND */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_wchar   filepath[NPPLG_MAX_FILEPATH_LEN];
  kal_wchar   title[NPPLG_MAX_TITLE_LEN];
  kal_uint8   player_type;
  kal_uint8   app_id;       /* Used to know which application wants to launch media player or music player */
  kal_bool    rtsp;
} npplg_av_launch_media_player_ind_struct;

/* The structure for MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_REQ */
typedef struct
{
  kal_uint8   ref_count;  /* Reference count */
  kal_uint16  msg_len;    /* Message length */
  kal_bool    suspend_bgplay;
} npplg_av_suspend_background_play_req_struct;

/* The structure for MSG_ID_NPPLG_AV_SUSPEND_BACKGROUND_PLAY_RSP */
typedef struct
{
  kal_uint8   ref_count;  /* Reference count */
  kal_uint16  msg_len;    /* Message length */
  kal_int32   result;
  kal_uint8   app_id;
} npplg_av_suspend_background_play_rsp_struct;

/* The structure for MSG_ID_NPPLG_AV_RESUME_BACKGROUND_PLAY_IND */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint8   obj_type;     /* Object type */
  kal_bool    resume_bgplay;
} npplg_av_resume_background_play_ind_struct;

/* The structure for MSG_ID_NPPLG_AV_AUDIO_PLAY_RES */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint32  mma_handle;
  kal_uint32  session_id;
  kal_int32   result;
} npplg_av_audio_play_res_struct;

/* The structure for MSG_ID_NPPLG_AV_MMI_RESUME_IND */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint32  instance_id;
  kal_uint8   app_id;
  kal_uint8   state;
} npplg_av_mmi_resume_ind_struct;

/* The structure for MSG_ID_NPPLG_AV_AUTO_PLAY_AUDIO_IND */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint8   app_id;
  kal_bool    notify_app;
} npplg_av_auto_play_audio_ind_struct;

/* The structure for MSG_ID_NPPLG_AV_RESET_IND */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint32  instance_id;
  kal_uint8   app_id;
} npplg_av_reset_ind_struct;

/* The structure for MSG_ID_NPPLG_AV_NOTIFY_MMI_IND */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint32  instance_id;
  kal_uint8   app_id;
  kal_uint8   action;       /* npplg_av_action_enum */
} npplg_av_notify_mmi_ind_struct;

/* The structure for MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_REQ */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  module_type src_mod;
  kal_uint32  instance_id;
  kal_int32   x;
  kal_int32   y;
  kal_int32   w;
  kal_int32   h;
  gdi_color   transparent_color;
  kal_uint8   app_id;
} npplg_av_create_vdo_layer_req_struct;

/* The structure for MSG_ID_NPPLG_AV_CREATE_VDO_LAYER_RSP */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint32  instance_id;
  kal_int32   result;
  gdi_handle  layer_handle;
  kal_uint32  blt_layer_flag;
  kal_uint32  hw_layer_flag;
  kal_uint8   app_id;
} npplg_av_create_vdo_layer_rsp_struct;

/* The structure for MSG_ID_NPPLG_AV_FREE_VDO_LAYER_IND */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint32  instance_id;
  kal_uint8   app_id;
} npplg_av_free_vdo_layer_ind_struct;

/* The structure for MSG_ID_NPPLG_AV_UPDATE_VDO_LAYER_IND */
typedef struct
{
  kal_uint8   ref_count;    /* Reference count */
  kal_uint16  msg_len;      /* Message length */
  kal_uint32  instance_id;
  kal_int32   x;
  kal_int32   y;
  kal_int32   w;
  kal_int32   h;
  gdi_color   transparent_color;
  kal_uint8   app_id;
} npplg_av_update_vdo_layer_ind_struct;

#endif /* NPPLG_STRUCT_H */
