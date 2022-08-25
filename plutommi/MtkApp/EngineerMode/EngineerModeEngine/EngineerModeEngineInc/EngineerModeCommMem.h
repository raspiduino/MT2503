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
 *  EngineerModeCommMem.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode common memory header file.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_EM_COMM_MEM_H
#define _MMI_EM_COMM_MEM_H

    #include "MMIDataType.h"
    #include "kal_general_types.h"


typedef enum
{    
    MMI_EM_COMM_MEM_STATE_IDLE = 0,
    MMI_EM_COMM_MEM_STATE_INIT,
    MMI_EM_COMM_MEM_STATE_ALLOCING,
    MMI_EM_COMM_MEM_STATE_READY,
    MMI_EM_COMM_MEM_STATE_STOPPING,
    MMI_EM_COMM_MEM_MAX_ITEM
} mmi_em_comm_mem_state_enum;

/* EM ASM*/
#define MMI_EM_MALLOC(size)             mmi_em_comm_mem_alloc(size)
#define MMI_EM_FREE(p)                  mmi_em_comm_mem_free(p)
#define MMI_EM_REG_STOP_FUNC(func)      mmi_em_comm_mem_ap_reg_stop_hdlr(func) //mmi_em_comm_mem_insert_cb_head(func)
#define MMI_EM_UNREG_STOP_FUNC(func)    mmi_em_comm_mem_ap_unreg_stop_hdlr(func) //mmi_em_comm_mem_delete_cb(func)

/* Type of ASM callbacks*/
typedef void (*mmi_em_comm_mem_start_callback_func)(void);
typedef MMI_BOOL (*mmi_em_comm_mem_stop_callback_func)(void); 

void mmi_em_comm_mem_ap_register(void);

MMI_BOOL mmi_em_comm_mem_ap_init(mmi_em_comm_mem_start_callback_func ap_start_cb);
void mmi_em_comm_mem_ap_create_adm(void);
void mmi_em_comm_mem_ap_deinit(void);


void mmi_em_comm_mem_ap_reg_stop_hdlr(mmi_em_comm_mem_stop_callback_func ap_stop_cb);
void mmi_em_comm_mem_ap_unreg_stop_hdlr(mmi_em_comm_mem_stop_callback_func ap_stop_cb);

void mmi_em_comm_mem_ap_stop_finished(void);

void* mmi_em_comm_mem_alloc(U32 size);
void mmi_em_comm_mem_free(void *p);

void mmi_em_comm_mem_hold(void);
void mmi_em_comm_mem_stop_hold(void);


#endif /* _MMI_EM_COMM_MEM_H*/

