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
 *  CentralConfigAgentProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Centralised Configuration Agent Header File
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

#ifndef MMI_CCA_PROT_H
#define MMI_CCA_PROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Abbreviation                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "mmi_features.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"

#include "MMIDataType.h"
#include "DebugInitDef_Int.h"

#include "mmi_frm_queue_gprot.h"
#ifdef __MMI_NCENTER_SUPPORT__
#include "Vsrv_ncenter.h"
#endif
#include "CentralConfigAgentGProt.h"

#include "CcaSrvGprot.h"



/*----------------------------------------------------------------------------*/
/* Base type define                                                           */
/*----------------------------------------------------------------------------*/

#define MMI_CCA_TRC_INFO                            MMI_INET_TRC_G9_CCA
#define MMI_CCA_TRC_WARNING                         MMI_INET_TRC_G9_CCA
#define MMI_CCA_TRC_ERROR                           MMI_INET_TRC_G9_CCA


/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define MMI_CCA_ASSERT							    MMI_ASSERT

#define MMI_CCA_IDX2BIT(idx)                        (0x0001 << (idx))
#define MMI_CCA_CHECK_FLAG(flag, bit_mask)          (((flag) & (bit_mask)) > 0)
#define MMI_CCA_SET_FLAG(flag, bit_mask)            ((flag) |= (bit_mask))
#define MMI_CCA_CLEAR_FLAG(flag, bit_mask)          ((flag) &= ~(bit_mask))
#define MMI_CCA_CHECK_FLAG(flag, bit_mask)          (((flag) & (bit_mask)) > 0)

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
#define MMI_CCA_INST_MAX_NUM                        (1)

#define MMI_CCA_INST_FLAG_IS_MSG_FROM_BOX           (0X0001)


/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

typedef struct
{
    MMI_ID self_gid;
    U16 flags;
    U16 info_size;
    WCHAR *setting_info;
    WCHAR pin_code[SRV_CCA_MAX_PIN_CHARS + 1];
#ifdef __MMI_NCENTER_SUPPORT__
    vsrv_ngroup_handle ncenter_gid;
    vsrv_notification_handle ncenter_nid;
#endif
    NMGR_HANDLE hnmgr;
    SRV_CCA_HANDLE h_cca;
}mmi_cca_inst_struct;

typedef struct
{
    mmi_cca_inst_struct inst_tbl[MMI_CCA_INST_MAX_NUM];    
}mmi_cca_cntx_struct;

/*----------------------------------------------------------------------------*/
/* Callback                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Export API                                                                 */
/*----------------------------------------------------------------------------*/
extern mmi_cca_cntx_struct *mmi_cca_get_cntx(void);
extern mmi_cca_inst_struct *mmi_cca_get_inst(void);


/* UI */
extern void mmi_cca_ui_handle_memfull(void);
extern void mmi_cca_ui_show_popup(U16 strid, U8 type);
extern void mmi_cca_nmgr_notify(void);

extern void mmi_cca_free_setting_info(void);
extern void mmi_cca_ui_entry_summary_report(void);

extern void mmi_cca_notify_group_entered(void);


/* Temp external here */
extern void mmi_cca_show_invalid_popup(srv_cca_status_enum status);
extern void mmi_cca_show_new_setting_message(U16 sim_id);//.
extern void mmi_cca_ui_close_progressing(void);

extern void mmi_cca_ui_entry_auth_screen(void);//.

extern void mmi_cca_reset_pin_buffer(void);
extern void mmi_cca_auth_verify_pass(void);

extern MMI_ID_TYPE mmi_cca_get_app_names(U16 config_id, MMI_BOOL with_colon);



/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/

#endif /* MMI_CCA_PROT_H */ 



