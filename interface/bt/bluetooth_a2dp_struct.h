/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

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
 *   bluetooth_a2dp_struct.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defines SAP for MTK Bluetooth.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BLUETOOTH_A2DP_STRUCT_H_
#define __BLUETOOTH_A2DP_STRUCT_H_

#include "bt_types.h"
#include "bluetooth_struct.h"

#ifdef BTMTK_ON_MAUI
#include "l1audio.h"
#endif

//#define MAX_NUM_REMOTE_SEIDS        (4)
#define MAX_NUM_REMOTE_CAPABILITIES (4)
#define MAX_NUM_A2DP_CODEC_ELEMS    (8)

#define MAX_NUM_LOCAL_SEIDS         (1)
#define MAX_NUM_LOCAL_CAPABILITIES  (2)

/* media_type */
#define BT_A2DP_MEDIA_AUDIO 		(0)
#define BT_A2DP_MEDIA_VIDEO 		(1)
#define BT_A2DP_MEDIA_MULTIMEDIA 	(2)
#define BT_A2DP_MEDIA_UNKNOWN 	    (0xff)

/* sep_type */
#define BT_A2DP_SOURCE              (0)
#define BT_A2DP_SINK 		        (1)

/* codec_type */
#define BT_A2DP_SBC 		        (1)
#define BT_A2DP_MP3 		        (2)
#define BT_A2DP_AAC 		        (3)
#define BT_A2DP_ATRAC 		        (4)
#define BT_A2DP_NON_A2DP            (5)


#define BT_A2DP_APPI_COMMAND_NONE                       (0)
#define BT_A2DP_APPI_COMMAND_DISCONNECT                 (1)
#define BT_A2DP_APPI_COMMAND_CONNECTED                  (3)
#define BT_A2DP_APPI_COMMAND_START                      (4)
#define BT_A2DP_APPI_COMMAND_STOP                       (5)
#define BT_A2DP_APPI_COMMAND_PAUSE                      (6)
#define BT_A2DP_APPI_COMMAND_RESUME                     (7)
//#define BT_A2DP_APPI_COMMAND_DISCOVERY                  (8)
//#define BT_A2DP_APPI_COMMAND_GETCAPABILITY              (9)
//#define BT_A2DP_APPI_COMMAND_SETCONFIG                  (10)
#define BT_A2DP_APPI_COMMAND_OPEN                       (11)
#define BT_A2DP_APPI_COMMAND_RECONFIG                   (12)
#define BT_A2DP_APPI_COMMAND_DEACTIVATED                (13)
#define BT_A2DP_APPI_COMMAND_CLOSE                      (14)
#define BT_A2DP_APPI_COMMAND_FM_STOP                    (15)
#define BT_A2DP_APPI_COMMAND_FM_START                   (16)
#define BT_A2DP_APPI_COMMAND_FM_SUSPEND                 (17)


// the max device number that can be connected at the same time
#define MAX_A2DP_DEV_NUM            (BT_PROFILES_LINK_NUM)


//taicong
#define MAX_A2DP_SOURCE_DEV_NUM			(1)
#define MAX_A2DP_SRC_SEP_NUM            3// 1*(sbc+mp3+aac)
#define MAX_A2DP_SINK_DEV_NUM			(2)
#define MAX_A2DP_SINK_SEP_NUM           6// 2*(sbc+mp3+aac)
#define MAX_A2DP_SEP_NUM            (MAX_A2DP_SRC_SEP_NUM + MAX_A2DP_SINK_SEP_NUM)

#define MAX_DEV_NAME_LEN            (59)

#define UNKNOWN_STREAM_HANDLE       (0xFF)
#define UNKNOWN_DEV_INDEX           (0xFF)

/*---------------------------------------------------------------------------
 * A2dpCodec structure
 *
 * Used to describe the codec type and elements.
 */
typedef struct _A2dpCodec
{
    U8 codecType;   /* The type of codec */
    U8 elemLen;                 /* Length of the codec elements */
    U8 elements[10];               /* Codec Elements */
} A2dpCodec;



typedef struct
{
    U32 lap;
    U8  uap;
    U16 nap; // non-significant 32..47
} bt_device_addr_struct;

typedef struct
{
    BOOL in_use;
    U8 seid;
    U8 media_type;
    U8 sep_type;
} bt_sep_info_struct;

#ifdef BTMTK_ON_LINUX
#ifndef __BT_A2DP_CODEC_TYPES__
// --- audio codec type ---
typedef struct
{
    U8 min_bit_pool;
    U8 max_bit_pool;
    U8 block_len; // b0: 16, b1: 12, b2: 8, b3: 4
    U8 subband_num; // b0: 8, b1: 4
    U8 alloc_method; // b0: loudness, b1: SNR
    U8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 16000
    U8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
} bt_a2dp_sbc_codec_cap_struct;

typedef struct
{
    U8 layer; // b0: layerIII, b1: layerII, b0: layerI
    BOOL CRC;
    U8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
    BOOL MPF; // is support MPF-2
    U8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 24000, b4: 22050, b5: 16000
    BOOL VBR; // is support VBR
    U16 bit_rate; // bit-rate index in ISO 11172-3 , b0:0000 ~ b14: 1110
} bt_a2dp_mp3_codec_cap_struct; /* all MPEG-1,2 Audio */

typedef struct
{
    U8 object_type; // b4: M4-scalable, b5: M4-LTP, b6: M4-LC, b7: M2-LC
    U16 sample_rate; // b0~b11: 96000,88200,64000,48000,44100,32000,24000,22050,16000,12000,11025,8000
    U8 channels; // b0: 2, b1: 1
    BOOL VBR; // is supported VBR
    U32 bit_rate; // constant/peak bits per second in 23 bit UiMsbf, 0:unknown
} bt_a2dp_aac_codec_cap_struct; /* all MPEG-2,4 AAC */

typedef struct
{
    U8 version; // 1:ATRAC, 2:ATRAC2, 3:ATRAC3
    U8 channel_mode; // b0: joint stereo, b1: dual, b2: single
    U8 sample_rate; // b0: 48000, b1: 44100
    BOOL VBR; // is supported VBR
    U32 bit_rate; // bit-rate index in ATRAC, b0: 0x0012 ~ b18: 0x0000
    U16 max_sul; // sound unit length in 16 bits UiMsbf
} bt_a2dp_atrac_codec_cap_struct; /* all ATRAC family */
typedef union
{
	U8 aptx_cap;
}vendor_codec_cap_union;
typedef struct
{
	U16 id;
	vendor_codec_cap_union cap;
}vendor_codec_struct;
typedef struct
{
	U32 vendor_id;  
	vendor_codec_struct vendor_codec;
} bt_a2dp_vendor_codec_cap_struct; /* vendor specific codec */


typedef struct{
    U32(*GetPayload)(U8 *, U32, U32 *);
    void (*GetPayloadDone)(void);
    void (*QueryPayloadSize)(U32 *, U32 *);
    U32(*AdjustBitRateFromQos)(U8);  // return adjusted bit rate
    U32(*SetBitRate)(U32);  // return adjusted bit rate
    U8 state;
} A2DP_codec_struct;
// --- audio codec type ---

typedef union
{
    bt_a2dp_sbc_codec_cap_struct sbc;
    bt_a2dp_mp3_codec_cap_struct mp3;
    bt_a2dp_aac_codec_cap_struct aac;
    bt_a2dp_atrac_codec_cap_struct atrac;
    bt_a2dp_vendor_codec_cap_struct vend;
} bt_a2dp_audio_codec_cap_struct;


typedef struct
{
    U8 codec_type; // SBC, MP3
    bt_a2dp_audio_codec_cap_struct codec_cap;
} bt_a2dp_audio_cap_struct;
#endif /* __BT_A2DP_CODEC_TYPES__ */
#endif /* BTMTK_ON_LINUX */

//taicong
typedef struct
{
    LOCAL_PARA_HDR
} bt_a2dp_start_codec_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8        result; /* 0: success, otherwise fail */
} bt_a2dp_start_codec_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_a2dp_stop_codec_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8        result; /* 0: success, otherwise fail */
} bt_a2dp_stop_codec_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_codec_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    U16 result;
} bt_a2dp_stream_codec_start_cnf_struct;
typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_sink_codec_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    U16 result;
} bt_a2dp_sink_codec_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 src_sep_num;
    U8 sink_sep_num;
    bt_a2dp_audio_cap_struct local_src_sep[MAX_A2DP_SRC_SEP_NUM];
    bt_a2dp_audio_cap_struct local_sink_sep[MAX_A2DP_SINK_SEP_NUM];
} bt_a2dp_activate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_a2dp_deactivate_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    bt_addr_struct device_addr;
    U8 local_role;
} bt_a2dp_signal_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_addr_struct device_addr;
    U8 accept;
} bt_a2dp_signal_connect_res_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
} bt_a2dp_signal_disconnect_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U8 command;
    U8 size;
    U8 data[6];
#ifdef BTMTK_ON_LINUX
    U8 req_fm_a2dp_data;
#endif
} bt_a2dp_appi_bt_command_struct;

/*
typedef struct
{
	LOCAL_PARA_HDR
	U16 connect_id;
} bt_a2dp_sep_discover_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	U16 connect_id;
	U16 result;
	U8 sep_num;
	bt_sep_info_struct sep_list[MAX_NUM_LOCAL_SEIDS];
} bt_a2dp_sep_discover_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	U16 connect_id;
	U8 acp_seid;
} bt_a2dp_capabilities_get_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	U16 connect_id;
	U16 result;
	bt_a2dp_audio_cap_struct codec_list;
} bt_a2dp_capabilities_get_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	U16 connect_id;
	U8 acp_seid;
	U8 int_seid;
	bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_config_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	U16 result;
	U8 stream_handle;
} bt_a2dp_stream_config_res_struct;
*/
typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_reconfig_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
} bt_a2dp_stream_reconfig_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_addr_struct device_addr;
    U8 local_role;
} bt_a2dp_stream_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 accept;
    U8 stream_handle;
} bt_a2dp_stream_open_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
} bt_a2dp_stream_start_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
} bt_a2dp_stream_pause_res_struct;

#ifdef BTMTK_ON_LINUX
typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    //	U8 data[MAX_ILM_BUFFER_SIZE-10];  //-10 for other data (for example stream_handler)
    U16 len;
    U32 sample_count;
    U8 data[800];  //-10 for other data (for example stream_handler)
} bt_a2dp_stream_data_send_req_struct;
#else
typedef struct
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    LOCAL_PARA_HDR
    U8 stream_handle;
    void *codec;
} bt_a2dp_stream_data_send_req_struct;
#endif

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
} bt_a2dp_stream_close_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_abort_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
} bt_a2dp_activate_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
} bt_a2dp_deactivate_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
    U16 result;
    bt_addr_struct device_addr;
} bt_a2dp_signal_connect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_addr_struct device_addr;
    U8 device_name_size;
    U8 device_name[60];
} bt_a2dp_signal_connect_ind_struct;



typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
    U16 result;
} bt_a2dp_signal_disconnect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
} bt_a2dp_signal_disconnect_ind_struct;
/*
typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
    U16 result;
    U8 sep_num;
    bt_sep_info_struct sep_list[MAX_NUM_REMOTE_SEIDS];
} bt_a2dp_sep_discover_cnf_struct;
*/
typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
} bt_a2dp_sep_discover_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
    U16 result;
    U8 audio_cap_size;
    bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_capabilities_get_result_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
    U16 result;
} bt_a2dp_capabilities_get_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
    U8 acp_seid;
} bt_a2dp_capabilities_get_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
    U16 result;
    U8 stream_handle;
} bt_a2dp_stream_config_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 connect_id;
    U8 acp_seid;
    U8 int_seid;
    U8 stream_handle;
    bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_config_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
    U16 prefer_size;
    bt_a2dp_audio_cap_struct current_config;
} bt_a2dp_stream_reconfig_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_reconfig_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
    bt_addr_struct device_addr;
    U8 device_name[60];
    U8 device_name_len;
    bt_a2dp_audio_cap_struct current_config;
} bt_a2dp_stream_open_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    U8 local_role;
    bt_addr_struct device_addr;
    U8 device_name_len;
    U8 device_name[60];
    bt_a2dp_audio_cap_struct current_config;
} bt_a2dp_stream_open_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
    U16 prefer_size;
    bt_a2dp_audio_cap_struct current_config;
} bt_a2dp_stream_start_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    U16 prefer_size;
    bt_a2dp_audio_cap_struct current_config;
} bt_a2dp_stream_start_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
} bt_a2dp_stream_pause_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_pause_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 result;
    U8 stream_handle;
} bt_a2dp_stream_close_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_close_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_abort_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_abort_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    U8 qos;
} bt_a2dp_stream_qos_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
} bt_a2dp_stream_data_out_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_data_config_change_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_a2dp_stream_data_config_get_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_data_config_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    I8 result;
    U16 prefer_size;
    bt_a2dp_audio_cap_struct current_config;
} bt_a2dp_stream_data_start_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U16 prefer_size;
    bt_a2dp_audio_cap_struct current_config;
} bt_a2dp_stream_data_start_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    I8 result;
} bt_a2dp_stream_data_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_a2dp_stream_data_disc_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
} bt_a2dp_stream_data_disconnecting_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 accept;
    U8 stream_handle;
} bt_a2dp_connect_accept_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    U8 seq_no;
} bt_media_a2dp_codec_open_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U8 stream_handle;
    U8 seq_no;
} bt_media_a2dp_codec_close_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    //void*                 pContext;
    void*                 req_context;
} bt_a2dp_header_struct;

#ifdef BTMTK_ON_MAUI
typedef enum
{
    BT_A2DP_DIALER_1,//dialer 1
    BT_A2DP_DIALER_2,//dialer 2
    BT_A2DP_DIALER_MAX
} BT_A2DP_DIALER_INDEX_ENUM;

typedef struct
{
	LOCAL_PARA_HDR
	U8 audio_sync_flag;//0: no need, 1: need add sync info
	BT_A2DP_DIALER_INDEX_ENUM dialer_index;
} bt_a2dp_audio_sync_set_struct;
#endif

typedef enum
{
    BT_A2DP_BAD_HEADER_FORMAT = 0x1,

    BT_A2DP_BAD_LENGTH = 0x11,
    BT_A2DP_BAD_ACP_SEID,
    BT_A2DP_SEP_IN_USE,
    BT_A2DP_SEP_NOT_IN_USE,
    BT_A2DP_BAD_SERV_CATEGORY = 0x17,
    BT_A2DP_BAD_PAYLOAD_FORMAT,
    BT_A2DP_NOT_SUPPORTED_COMMAND,
    BT_A2DP_INVALID_CAPABILITIES,

    BT_A2DP_BAD_RECOVERY_TYPE = 0x22,
    BT_A2DP_BAD_MEDIA_TRANSPORT_FORMAT,
    BT_A2DP_BAD_RECOVERY_FORMAT = 0x25,
    BT_A2DP_BAD_ROHC_FORMAT,
    BT_A2DP_BAD_CP_FORMAT,
    BT_A2DP_BAD_MULTIPLEXING_FORMAT,
    BT_A2DP_UNSUPPORTED_CONFIGURATION,

    BT_A2DP_BAD_STATE = 0x31,

    /* improper settings of Codec Specific Information Elements,
       used in SetConfiguration and Reconfigure */
    BT_A2DP_INVALID_CODEC_TYPE = 0xC1,
    BT_A2DP_NOT_SUPPORTED_CODEC_TYPE,
    BT_A2DP_INVALID_SAMPLING_FREQUENCY,
    BT_A2DP_NOT_SUPPORTED_SAMPLING_FREQUENCY,
    BT_A2DP_INVALID_CHANNEL_MODE,
    BT_A2DP_NOT_SUPPORTED_CHANNEL_MODE,
    BT_A2DP_INVALID_SUBBANDS,
    BT_A2DP_NOT_SUPPORTED_SUBBANDS,
    BT_A2DP_INVALID_ALLOCATION_METHOD,
    BT_A2DP_NOT_SUPPORTED_ALLOCATION_METHOD,
    BT_A2DP_INVALID_MINIMUM_BITPOOL_VALUE,
    BT_A2DP_NOT_SUPPORTED_MINIMUM_BITPOOL_VALUE,
    BT_A2DP_INVALID_MAXIMUM_BITPOOL_VALUE,
    BT_A2DP_NOT_SUPPORTED_MAXIMUM_BITPOOL_VALUE,
    BT_A2DP_INVALID_LAYER,
    BT_A2DP_NOT_SUPPORTED_LAYER,
    BT_A2DP_NOT_SUPPORTED_CRC,
    BT_A2DP_NOT_SUPPORTED_MPF,
    BT_A2DP_NOT_SUPPORTED_VBR,
    BT_A2DP_INVALID_BIT_RATE,
    BT_A2DP_NOT_SUPPORTED_BIT_RATE,
    BT_A2DP_INVALID_OBJECT_TYPE,
    BT_A2DP_NOT_SUPPORTED_OBJECT_TYPE,
    BT_A2DP_INVALID_CHANNELS,
    BT_A2DP_NOT_SUPPORTED_CHANNELS,
    BT_A2DP_INVALID_VERSION,
    BT_A2DP_NOT_SUPPORTED_VERSION,
    BT_A2DP_NOT_SUPPORTED_MAXIMUM_SUL,
    BT_A2DP_INVALID_BLOCK_LENGTH,

    BT_A2DP_INVALID_CP_TYPE = 0xE0,
    BT_A2DP_INVALID_CP_FORMAT,
    /* internal result */
    BT_A2DP_RESULT_OK = 0x0100,
    BT_A2DP_RESULT_TIMEOUT,
    BT_A2DP_RESULT_BAD_STATE,
    BT_A2DP_RESULT_FATAL_ERROR,
    BT_A2DP_RESULT_NO_CONNECTION,
    BT_A2DP_RESULT_SEP_IND_USE,
    BT_A2DP_RESULT_BAD_ACP_SEID,
    BT_A2DP_RESULT_PANIC
} BT_A2DP_RESULT_ENUM;

typedef enum
{
    BT_AUDIO_STREAM_RECONFIG_FAIL,
    BT_AUDIO_STREAM_START_FAIL,
    BT_AUDIO_STREAM_PAUSE_FAIL
} MED_BT_AUDIO_ERROR_CAUSE_ENUM;


#endif /* __BLUETOOTH_A2DP_STRUCT_H_ */

