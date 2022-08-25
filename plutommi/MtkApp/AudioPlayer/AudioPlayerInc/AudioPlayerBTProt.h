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

#ifndef _AUDIO_PLAYER_BT_PROT_H
#define _AUDIO_PLAYER_BT_PROT_H

#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
#include "AudioPlayerBTNowPlaying.h"

/***************************************************************************** 
* External Function
*****************************************************************************/
/* interface from AudioPlayerBTSrc.c */
extern void mmi_bt_music_set_launch_point(MMI_BOOL lp);
extern MMI_BOOL mmi_bt_music_is_playing(void);
extern void mmi_bt_music_bt_link_lsk_hdlr(void);
extern void mmi_bt_music_A2DP_cb(srv_bt_cm_bt_addr *address, kal_int32 result);
#ifdef __MMI_BT_AVRCP_V13__
extern void mmi_bt_music_avrcp_cb(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_event_enum event_id, srv_avrcp_result_union result);
#endif /*__MMI_BT_AVRCP_V13__*/
extern void mmi_bt_music_read_volume(U8 *val);
extern void mmi_bt_music_write_volume(U8 val);
extern void mmi_bt_music_set_elapsed_ms(U32 val);
extern U32 mmi_bt_music_get_elapsed_ms(void);
extern void mmi_bt_music_set_duration(U32 val);
extern U32 mmi_bt_music_get_duration(void);
extern mmi_audply_dev_list_cntx_struct *mmi_bt_music_get_dev_list_cntx(void);
extern void mmi_bt_music_device_list_entry(void);
extern void mmi_bt_music_progressbar_forward_stop(void);
extern void mmi_bt_music_send_ct_avrcp_command(S32 cmd);
extern void mmi_bt_music_send_tg_avrcp_command(S32 cmd);
extern void mmi_bt_music_inc_vol(void);
extern void mmi_bt_music_dec_vol(void);

#endif /* defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__) */

#endif /* _AUDIO_PLAYER_BT_PROT_H */ 

