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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   CtmProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Cellular Text telephone Modem
 *  Internal prototypes
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CTM_SUPPORT__

#ifndef CTM_PROT_H
#define CTM_PROT_H

#include "CtmSrvGProt.h"

#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "mmi_frm_scenario_gprot.h"


#define MMI_CTM_MAX_DATA_COUNT          64
#define MMI_CTM_MAX_DATA_BUFFER_LEN     ((MMI_CTM_MAX_DATA_COUNT+1)<<1)
#define MMI_CTM_MAX_EDITOR_COUNT        20
#define MMI_CTM_MAX_EDITOR_BUFFER_LEN   ((MMI_CTM_MAX_EDITOR_COUNT+1)<<1)

typedef enum
{
    MMI_CTM_STATE_IDLE,
    MMI_CTM_STATE_CONNECTING,
    MMI_CTM_STATE_CONNECTED,
    MMI_CTM_STATE_UNKNOWN
} mmi_ctm_state_enum;



typedef struct
{
    mmi_ctm_state_enum state;
    U16 remote_len;
    U16 local_len;
    U16 pending_len;
    U16 sent_len;
    MMI_ID grp_id;
    MMI_ID conn_confirm_id;
    U8 remote_buffer[MMI_CTM_MAX_DATA_BUFFER_LEN];
    U8 local_buffer[MMI_CTM_MAX_DATA_BUFFER_LEN];    
    U8 editor_buffer[MMI_CTM_MAX_EDITOR_BUFFER_LEN];
    U8 pending_buffer[MMI_CTM_MAX_EDITOR_BUFFER_LEN];
} mmi_ctm_cntxt_struct;

extern mmi_ctm_cntxt_struct *ctm_p;


extern void mmi_ctm_entry_connect_animation(void);
extern void mmi_ctm_entry_editor(void);
extern void mmi_ctm_edit_done(void);
extern void mmi_ctm_entry_talking(void);
extern void mmi_ctm_drop(void);
extern U32 mmi_ctm_ind_close(void);
extern void mmi_ctm_rsp_connect(void *info);
extern void mmi_ctm_cntxt_reset_buffer(void);
extern U32 mmi_ctm_ind_connect(void);
extern MMI_BOOL mmi_ctm_entry_talking_cb(mmi_scenario_id scen_id, void *arg);
extern void mmi_ctm_req_send_text(void);
extern void mmi_ctm_rsp_send_text(void *info);
extern U32 mmi_ctm_ind_receive_text(srv_ctm_receive_text_ind_struct *ind);
extern void mmi_ctm_ind_tty_dev_status(MMI_BOOL is_plug_in);


#endif /* CTM_PROT_H */ 

#endif /* __CTM_SUPPORT__ */
