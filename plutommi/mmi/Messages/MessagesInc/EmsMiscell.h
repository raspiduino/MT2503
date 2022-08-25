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
 * EmsMiscell.H
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

   FILENAME : MessagesMiscell.h

   PURPOSE     : ---

   REMARKS     : ---

   AUTHOR      : Hiran and Magesh k

   DATE     : ---

**************************************************************/

#ifndef _PIXCOM_EMS_MISCELL_H
#define _PIXCOM_EMS_MISCELL_H
#include "MMI_features.h"

#ifdef __MMI_SMS_APP_EMS_SUPPORT__
#include "MMIDataType.h"
#include "MessagesExDcl.h"
#include "ems.h"

extern void mmi_ems_pre_entry_edit_object_name(void);
extern void mmi_ems_insert_object_error_hdlr(EMSTATUS emsObjectStatus);
extern void mmi_msg_entry_ems_picture(void);
extern void mmi_msg_entry_ems_my_picture(void);
extern void mmi_msg_entry_ems_predef_animation(void);
extern void mmi_msg_entry_ems_my_animation(void);
#ifdef __MMI_IMELODY_SUPPORT__
extern void mmi_msg_entry_ems_melody(void);
extern void mmi_msg_entry_ems_my_melody(void);
#endif /* __MMI_IMELODY_SUPPORT__ */ 
extern void mmi_msg_entry_ems_predef_sound(void);
extern void ExitEMSObjectList(void);
extern void ExitScrSaveObjectName(void);
extern void mmi_ems_entry_save_object_list(void);
extern void ExitScrSaveObjectList(void);
extern void PreviewEmsObjectIsDone(void);
extern S32 mmi_ems_create_ems_folder(void);
extern U8 EmsPictureNum(void);
extern void mmi_ems_set_group_id(MMI_ID group_id);
#ifdef __MMI_FILE_MANAGER__
extern void mmi_ems_fm_send_by_ems(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType);
#endif
#else  /* __MMI_SMS_APP_EMS_SUPPORT__ */
#ifdef __MMI_MESSAGES_EMS__
extern void PreviewEmsObjectIsDone(void);
#endif
#endif /* __MMI_SMS_APP_EMS_SUPPORT__ */


#endif /* _PIXCOM_EMS_MISCELL_H */ 

