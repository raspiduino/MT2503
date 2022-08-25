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
 *  SDKMMApp.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access multimedia application related functions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SDKMMAPP_H_
#define _SDKMMAPP_H_

#include "MMI_features.h"

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/****************************************************************************
 * AudioPlayerProt.h
 ****************************************************************************/
/* single play */
#ifndef __MMI_MEDIA_PLAYER_AUDIO__
//#include "AudioPlayerProt.h"

extern void mmi_audply_single_play(UI_string_type filefullname, void (*exit_callback_func) (void),U16 title_icon);
#endif /* __MMI_MEDIA_PLAYER_AUDIO__ */


/****************************************************************************
 * CamcorderGprot.h
 ****************************************************************************/
#ifndef __COSMOS_MMI_PAKAGE__
#ifdef __MMI_CAMERA__
#include "CameraCuiGprot.h"

extern void cui_camera_struct_init(p_cui_camera_run_struct p_args);
extern mmi_id cui_camera_create(mmi_id parent_gid);
extern void cui_camera_run(mmi_id cui_gid, p_cui_camera_run_struct p_args);
extern mmi_id cui_camera_ex_create(mmi_id parent_gid, mmi_proc_func parent_group_proc);
extern void cui_camera_ex_run(mmi_id parent_gid, mmi_id cui_gid, p_cui_camera_run_struct p_args);
extern void cui_camera_close(mmi_id cui_gid);
extern MMI_BOOL cui_camera_check_and_display_popup(void);
#endif /* __MMI_CAMCORDER__ */
#endif






/****************************************************************************
 * VdoPlyGProt.h
 ****************************************************************************/
#ifdef __MMI_VIDEO_PLAYER__
#include "VdoPlyGProt.h"

/* play video from other app */
extern void mmi_vdoply_entry_player_screen_from_file(PS8 filename, BOOL is_short);
extern void mmi_vdoply_entry_player_screen_from_id(U16 video_id, U16 video_name_id);
/* streaming */
extern void mmi_vdoply_entry_player_screen_from_rtsp_link(PS8 rtsp_url);
extern void mmi_vdoply_entry_player_screen_from_sdp_file(PS8 sdp_filename, BOOL is_short);
extern void mmi_vdoply_entry_player_screen_from_ram_file(PS8 ram_filename, BOOL is_short);
/* link from wap */
extern void mmi_vdoply_send_rtsp_url_req(PS8 rtsp_url);
#endif /* __MMI_VIDEO_PLAYER__ */


/****************************************************************************
 * VdoRecGProt.h
 ****************************************************************************/
#ifndef __COSMOS_MMI_PAKAGE__
#ifdef __MMI_VIDEO_RECORDER__
#include "VdoRecCuiGprot.h"

extern void cui_vdorec_struct_init(p_cui_vdorec_run_struct p_args);
extern mmi_id cui_vdorec_create(mmi_id parent_gid);
extern void cui_vdorec_run(mmi_id cui_gid, p_cui_vdorec_run_struct p_args);
extern U32 cui_vdorec_get_min_size(void);
extern void cui_vdorec_close(mmi_id cui_gid);
extern mmi_id cui_vodrec_ex_create(mmi_id parent_gid, mmi_proc_func parent_group_proc);
extern void cui_vdorec_ex_run(mmi_id parent_gid, mmi_id cui_gid, p_cui_vdorec_run_struct p_args);
extern MMI_BOOL cui_vdorec_check_and_display_popup(void);
#endif /* __MMI_VIDEO_RECORDER__ */
#endif

#endif /* _SDKMMAPP_H_ */ 

