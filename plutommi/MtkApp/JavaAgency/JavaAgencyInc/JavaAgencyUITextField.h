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
 *   JavaAgencyUITextField.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JAVA_AGENCY_TEXTFIELD_H__
#define __JAVA_AGENCY_TEXTFIELD_H__

#ifdef __J2ME__

typedef struct
{
    LOCAL_PARA_HDR kal_uint16 *text;
    kal_int32 max_size;
    kal_int32 constraints;
    kal_int32 vm_id;
    void (*callback) (kal_bool validate, kal_int32 vm_id);
} mmi_java_ui_textfield_show_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 max_size;
    kal_int32 vm_id;
    void (*callback) (kal_bool vaidate, kal_int32 vm_id);
} mmi_java_ui_textfield_show_rsp_struct;

typedef struct
{
    kal_uint16 * text;
    kal_int32 max_size;
    kal_int32 constraints;
    kal_int32 vm_id;

    void (*callback) (kal_bool validate, kal_int32 vm_id);
}mmi_java_ui_textfield_data_struct;

extern void mmi_java_ui_textfield_init(void);
extern void mmi_java_ui_textfield_show_req(void * msg_struct);
extern void mmi_java_ui_textfield_hide_req(void * msg_struct);
extern void mmi_java_ui_textfield_remove_screen(void);
extern void mmi_java_ui_textfield_close_phb_cui(void);
extern void mmi_java_ui_textfield_exit_screen(MMI_ID scrn_id);
#if  defined (__COSMOS_MMI_PACKAGE__)   && !defined (J2ME_SLIM_MEMORY_SUPPORT)
extern mmi_ret mmi_java_ui_textfield_set_number(mmi_event_struct *evt);
extern mmi_ret mmi_java_ui_textfield_set_number_prepare_proc(mmi_frm_asm_evt_struct *evt);
extern void mmi_java_ui_textfield_delete_phb_cui(void);
#endif


#endif /* __J2ME__ */
#endif /* __JAVA_AGENCY_TEXTFIELD_H__ */

