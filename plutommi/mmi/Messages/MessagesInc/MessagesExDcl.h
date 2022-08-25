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
 * MessagesExDcl.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : MessagesExDcl.h

   PURPOSE     : ---

   REMARKS     : ---

   AUTHOR      : Hiran and Magesh k

   DATE     : ---

**************************************************************/

#ifndef _PIXCOM_MESSAGES_EXTERN_DCL_H
#define _PIXCOM_MESSAGES_EXTERN_DCL_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

typedef enum
{
    MMI_SEND_ONLY,
    MMI_SEND_BY_NAME,
    MMI_SEND_TO_MANY,
    MMI_CALLER_GROUP_NAMES,
    MMI_CALLER_GROUP_DATA,
    MMI_VOICEMAIL_NUMBERS,
    MMI_SEND_SMS_FROM_PHB,      /* MTK 2004-02-03 Wilson. */
    MMI_SEND_VCARD_FROM_PHB,    /* MTK 2004-03-25 Wilson */
    MMI_SEND_CHAT,
    MMI_SAVE_CHAT,
    MMI_PHB_SMS_INTERFACE_NONE
} MMI_PHB_SMS_INTERFACE;

#if defined(__MMI_SMS_APP_EMS_SUPPORT__) || defined(__MMI_MESSAGE_SMS_HILITE_VIEWER__) || defined(__MMI_MESSAGE_SMS_USE_DETAIL__) || defined(__MMI_MESSAGES_EMS__)
typedef enum
{
    EMS_OBJECT_PICTURE_STATE = 1,
    EMS_OBJECT_MY_PICTURE_STATE,
    EMS_OBJECT_PREDEFINED_ANIMATION_STATE,
    EMS_OBJECT_MY_ANIMATION_STATE,
    EMS_OBJECT_MELODY_STATE,
    EMS_OBJECT_MY_MELODY_STATE,
    EMS_OBJECT_PREDEFINED_SOUND_STATE,
    EMS_OBJECT_MY_PICTURE_A_ANIMATION_DOWNLOAD_APP_STATE,
    EMS_OBJECT_MY_MELODY_DOWNLOAD_APP_STATE
} EMS_OBJECT_DISPLAY_STATE;
#endif /* __MMI_MESSAGES_EMS__ */ 


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#define MMI_SMS_ARCH_FOLDER_DRV SRV_FMGR_PUBLIC_DRV
#define MMI_SMS_ARCH_PATH      "\\SMSArch\\"  //before read/write arch file, need to "%s%lx.a", SMSARCH_FOLDER, fileid
#define MMI_SMS_ARCH_SYS_PATH  "\\@SMSArch\\" //to store idx file in sys drive
#define MMI_SMS_MAX_ARCH_PATH_LEN (18 + 6)  //18 for MMI_SMS_ARCH_PATH/MMI_SMS_ARCH_SYS_PATH,  6 for 001.a,...009.a, 00A.a, 00B.a...00F.a, 010.a.... idx.a
#define MMI_SMS_MAX_ARCH_BUF_SIZE (100+ MMI_SMS_MAX_MSG_SEG *160 * ENCODING_LENGTH)
#endif

extern void InitMessagesApp(void);
extern void InitMessageProtocolEventHandlers(void);

extern void DeInitMessagesApp(void);
extern U16 GetMessagesCurrScrnID(void);
extern void SetMessagesCurrScrnID(U16 scrnID);

extern void mmi_msg_set_phb_send_case(U8 PhbSmsInterfaceState);
extern void DialVoiceMail(void);

#if defined(__MMI_MESSAGES_EMS__)
extern void EnableDisableAudioPlayback(void);
extern void DisplayUserDefinedImageList(void);

#ifdef __MMI_FILE_MANAGER__
#define CATEGORY144_FMGR_PREVIEW    0x1000
extern void ShowCategory144Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 object_type,
                S32 n_items,
                U8 **object_titles,
                U16 *predefined_objects,
                MMI_BOOL is_short_name,
                U8 **userdefined_objects,
                S32 *index,
                U8 *history_buffer);
extern void mmi_ems_add_object_from_fm(void);
extern void mmi_ems_preview_object_from_fm(PU16 filePath, int is_short);
#endif /* __MMI_FILE_MANAGER__ */ 
#endif /* defined(__MMI_MESSAGES_EMS__) */ 
extern U8 mmi_msg_check_interrupt(void);

#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
extern U8 mmi_msg_need_new_msg_ind(void);
#endif
extern U8 mmi_msg_need_mem_exceed_ind(void);
extern U8 mmi_msg_need_waiting_ind(void);

extern void mmi_msg_init_msg_data(void);
extern void mmi_msg_deinit_msg_data(void);

extern void mmi_msg_entry_msg_waiting_ind(void);
extern void mmi_msg_get_deliver_report_status(U32 *status, U16 *imgID, U16 *strID);
extern U8 *mmi_msg_get_deliver_report_msg(void);
extern void mmi_msg_entry_mem_exceed_ind(void);
extern void mmi_msg_entry_class0_msg_ind(void);
extern void mmi_msg_entry_new_msg_ind(void);

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_msg_entry_new_sim_msg_ind(void);
extern U8 mmi_msg_need_new_sim_msg_ind(void);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#endif /* _PIXCOM_MESSAGES_EXTERN_DCL_H */ 

