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
*  DCDGprot.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   DCD exported interface header file
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*==============================================================================*/

#ifndef _DCD_GPROT_H
#define _DCD_GPROT_H
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#ifndef _CUSTOM_EVENTS_NOTIFY_H
#include "custom_events_notify.h"
#endif
#include "DCDAgentInterface.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"

/***************************************************************************** 
 * Define 
 *****************************************************************************/
#define MMI_DCD_MAX_CHANNEL_COUNT        15 	/* channel count */
#define MMI_DCD_CHANNEL_TITLE_LEN        ((64+7+1)*2) /* channel tilte length, 7 for number, 1 for null terminal */
#define MMI_DCD_CHANNEL_LIST_BUF_SIZE    ((MMI_DCD_MAX_CHANNEL_COUNT)*((MMI_DCD_CHANNEL_TITLE_LEN)+sizeof(void*)))
#define MMI_DCD_MAX_CHANNEL_TITLE_LEN    ((64 + 1)*ENCODING_LENGTH)

#define MMI_DCD_MAX_STORY_COUNT          10
#define MMI_DCD_MAX_STORY_TITLE_LEN      ((64 + 1)*ENCODING_LENGTH)/* story tilte length, 1 for null terminal */
#define MMI_DCD_STORY_LIST_BUF_SIZE      (MMI_DCD_MAX_STORY_COUNT*(MMI_DCD_MAX_STORY_TITLE_LEN + sizeof(void*)))

/* error result code */
#define MMI_DCD_ERR_IS_SYNCING           (-800)

typedef void (*dcd_sync_callback)(MMI_BOOL success);

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern kal_uint32 mmi_dcd_mem_initialize(void);
extern kal_uint32 mmi_dcd_mem_finalize(void);
extern kal_uint32 mmi_dcd_get_acct_id(void);

//extern void mmi_dcd_initialize(void);
extern void mmi_dcd_finalize(void);

extern HDCD_Agent mmi_dcd_get_agent_handle(void);
extern MMI_BOOL mmi_dcd_is_switch_on(void);
extern MMI_BOOL mmi_dcd_is_idle_on(void); 
extern void mmi_dcd_line_taken(void);
extern void mmi_dcd_line_given(void);

extern MMI_BOOL mmi_dcd_get_normal_entry(void);
extern void mmi_dcd_set_normal_entry(MMI_BOOL normal);
extern MMI_BOOL mmi_dcd_get_normal_exit(void);
extern void mmi_dcd_set_normal_exit(MMI_BOOL normal);

extern void mmi_dcd_idle_prev_channel(void);
extern void mmi_dcd_idle_next_channel(void);
extern void mmi_dcd_idle_prev_entry(void);
extern void mmi_dcd_idle_next_entry(void);
extern void mmi_dcd_idle_to_story_viewer(void);
extern void mmi_dcd_pre_entry_story_viewer(S32 mode);

extern void mmi_dcd_switch(BOOL on);
extern void mmi_dcd_receive_da_file(
                S32 session_id,
                S32 mime_type,
                S32 mime_subtype,
                S32 action,
                PU16 filepath,
                PS8 url,
                PS8 mime_type_string);
extern void mmi_dcd_viewer_go_to(void);

extern void mmi_dcd_entry_idlescreen(void);
extern void mmi_dcd_exit_idlescreen(void);
extern void mmi_dcd_entry_channel_list_screen(void);
extern void mmi_dcd_entry_chan_from_mobile_service(void);
extern void mmi_dcd_entry_main_option(void);
extern MMI_BOOL mmi_dcd_is_syncing(void);
extern void mmi_dcd_running_conflict_prompt(void);
extern MMI_STR_ID mmi_dcd_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type);

#endif/*__MMI_OP01_DCD__*/
#endif/*_DCD_GPROT_H*/

