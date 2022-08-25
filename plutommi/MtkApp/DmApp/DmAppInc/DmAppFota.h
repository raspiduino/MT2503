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
 *  DmAppFota.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM application fota header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
#ifndef __DM_APP_FOTA_H__
#define __DM_APP_FOTA_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "DMTypeDef.h"
/****************************************************************************
 * Define
 ****************************************************************************/
#define MMI_DM_FOTA_UPDATE_DEFER_STR_LEN 32

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef struct
{
    S32 highlight_defer_time_index;
    S32 sel_defer_time;
} mmi_dm_fota_cntx;
/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void mmi_dm_fota_display_fota_update_result_via_nmgr(MMI_BOOL result);
extern MMI_BOOL mmi_dm_fota_display_fota_update_result(mmi_scenario_id scen_id, void *arg);
extern void mmi_dm_fota_display_update_cnf_via_nmgr(dm_ui_mode_enum ui_mode);
extern MMI_BOOL mmi_dm_fota_display_update_cnf_nmgr_hdlr(mmi_scenario_id scen_id, void *arg);
extern void mmi_dm_fota_display_update_cnf(void);
extern void mmi_dm_fota_update_cnf_lsk_hdlr(void);
extern void mmi_dm_fota_update_cnf_csk_hdlr(void);
extern void mmi_dm_fota_update_cnf_rsk_hdlr(void);
extern mmi_ret mmi_dm_fota_update_cnf_leave_proc(mmi_event_struct *evt);
extern void mmi_dm_fota_entry_update_defer(void);
extern void mmi_dm_fota_update_defer_lsk_hdlr(void);
extern void mmi_dm_fota_update_defer_csk_hdlr(void);
extern void mmi_dm_fota_update_defer_rsk_hdlr(void);
extern void mmi_dm_fota_update_defer_highlight_hdlr(S32 index);
extern void mmi_dm_fota_entry_reset_progress(void);

#endif /* __DM_APP_FOTA_H__ */
