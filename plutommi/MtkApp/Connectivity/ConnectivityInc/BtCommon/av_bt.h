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
 * av_bt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file shows the prototypes of av app using Bluetooth A2DP
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __AV_APP_H__
#define __AV_APP_H__

#include "BtcmSrvGprot.h"
//#include "BTMMIA2DPScr.h"
#include "A2dpSrvGProt.h"

#include "kal_general_types.h"

typedef void(*AV_BT_CALLBACK)(srv_bt_cm_bt_addr *address, kal_int32 result);

typedef enum
{
    AV_BT_CALLBACK_EVENT_OPEN_OK = SRV_A2DP_CALLBACK_EVENT_OPEN_OK,
    AV_BT_CALLBACK_EVENT_OPEN_FAILED = SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED,
    AV_BT_CALLBACK_EVENT_OPEN_STOPPED = SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED,
    AV_BT_CALLBACK_EVENT_OPEN_CANCELED = SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED,
    AV_BT_CALLBACK_EVENT_STREAM_SUSPEND_IND = SRV_A2DP_CALLBACK_EVENT_STREAM_PAUSE_IND,
    AV_BT_CALLBACK_EVENT_STREAM_START_IND = SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND,
    AV_BT_CALLBACK_EVENT_STREAM_PAUSE_IND = SRV_A2DP_CALLBACK_EVENT_STREAM_PAUSE_IND,
    AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND = SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND,
    AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND = SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND,
    AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND = SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND,
    AV_BT_CALLBACK_EVENT_INQUIRY_START_IND = SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND,
    AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND = SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND,
    AV_BT_CALLBACK_EVENT_OPEN_SCO = SRV_A2DP_CALLBACK_EVENT_OPEN_SCO,
    AV_BT_CALLBACK_EVENT_SECURITY_BLOCK = SRV_A2DP_CALLBACK_EVENT_SECURITY_BLOCK
} av_bt_callback_event_enum;

/* level 1 */
extern void av_bt_init(void);
extern void av_bt_set_default_callback(AV_BT_CALLBACK handler);
extern kal_bool av_bt_is_inquiry(void);
extern kal_bool av_bt_is_codec_open(void);
extern kal_bool av_bt_is_streaming(void);
extern kal_bool av_bt_is_mp3_cfg(void);
extern kal_int32 av_bt_open_ex(srv_bt_cm_bt_addr *bt_dev, kal_uint16 sample_rate, kal_uint8 stereo, AV_BT_CALLBACK callback, kal_bool immediate_callback);
extern kal_int32 av_bt_open(srv_bt_cm_bt_addr *bt_dev, kal_wchar* filename, AV_BT_CALLBACK callback, kal_bool sbc_only, kal_bool immediate_callback);
extern void av_bt_close(kal_bool notify_opener);
extern void av_bt_open_codec(kal_bool immediate);
extern void av_bt_close_codec(void);
extern void av_bt_pause(void);
extern void av_bt_inquiry_start_callback(void);
extern void av_bt_inquiry_stop_callback(void);
#endif /* __AV_APP_H__ */
