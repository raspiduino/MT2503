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
*  BTMusicNoLCDProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   BT Music NoLCD Header File
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __BT_MUSIC_NOLCD_H__
#define __BT_MUSIC_NOLCD_H__

#include "MMI_features.h"

#ifdef __MMI_BT_MUSIC_NOLCD__
#include "BtcmSrvGprot.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "gui_data_types.h"

/* The minimum volume of 16 level volume + mute level (mute) */
#define MDI_BT_MUSIC_NOLCD_VOL_MUTE_MIN (0)
/* The maximum volume of 16 level volume + mute level (mute) */
#define MDI_BT_MUSIC_NOLCD_VOL_MUTE_MAX (16)

#define MDI_BT_MUSIC_NOLCD_DEFAULT_VOL (12)

typedef struct
{
    mmi_id group_id;
    MMI_BOOL is_mute;  //whether current is mute
    MMI_BOOL is_playing;  //whether bt music is playing or not
    MMI_BOOL is_interrupted;  //whether bt music is interrupted or not
    MMI_BOOL is_karaoke_enable;  //whether bt music enable karaoke or not
    MMI_BOOL is_original_enable;  //whether bt music enable karaoke original or not
    MMI_BOOL karaoke_timer_enable;  //whether karaoke timer enable or not
    U8 volume;  //BT Music's volume
	srv_bt_cm_bt_addr * bt_address; //Current A2DP address
} mmi_bt_music_nolcd_context_struct;

extern kal_bool g_is_wait_for_notify;
extern kal_bool g_delay_open_sink_codec;

#endif  //__MMI_BT_MUSIC_NOLCD__
#endif  //__BT_MUSIC_NOLCD_H__

