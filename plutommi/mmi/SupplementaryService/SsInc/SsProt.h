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
 *  SSGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS application internal prototypes
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
#ifndef SS_PROT_H
#define SS_PROT_H


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#include "SsSrvGprot.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "NotificationGprot.h"
#include "l4c_common_enum.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"

#if (MMI_MAX_SIM_NUM >= 2)
#include "SimSelCuiGprot.h"
#endif /* (MMI_MAX_SIM_NUM >= 2) */

/****************************************************************************
* Define
*****************************************************************************/
#if defined(CFG_MMI_USSR_TIMER) && ((CFG_MMI_USSR_TIMER == __ON__)||(CFG_MMI_USSR_TIMER == __AUTO__))
    #ifndef __MMI_USSR_TIMER__
    #define __MMI_USSR_TIMER__
    #endif
#endif

#if defined(CFG_MMI_RECEIVE_USSD_TONE) && ((CFG_MMI_RECEIVE_USSD_TONE == __ON__)||(CFG_MMI_RECEIVE_USSD_TONE == __AUTO__))
    #ifndef __MMI_RECEIVE_USSD_TONE__
    #define __MMI_RECEIVE_USSD_TONE__
    #endif
#endif


/****************************************************************************
* Typedef                                                            
*****************************************************************************/

typedef enum
{
    EVT_ID_MMI_SS_ADJUST_GRP = SS_BASE + 1, 
    EVT_ID_MMI_SS_TOTAL /* max enum */
} mmi_ss_event_enum;


typedef struct
{
    MMI_BOOL proceeding; /* MMI_TRUE, normal screen flow */
    MMI_BOOL from_grp; /* from_id is a group id */
    mmi_id from_id;
} mmi_ss_scr_proceed_struct;


typedef struct
{
    MMI_BOOL deferring;
    mmi_noti_scrn_func_ptr defer_entry_func;
    void *defer_user_data;
} mmi_ss_scr_defer_struct;


typedef struct
{
    mmi_sim_enum sim;
    srv_ss_act_enum curr_op; /* to avoid multiple requesting screens and to check the pairwise of start/end notification */
    S32 ctd_call_num; /* number of active and held call */
    S32 hilight_idx;
    void *adj_grp_user_data; /* user data for adjusting group */
    mmi_ss_scr_proceed_struct scr_proceed;
    mmi_ss_scr_defer_struct scr_defer;
} mmi_ss_cntx_struct;


typedef struct
{
    WCHAR string[SRV_SS_MAX_LENGTH];
} mmi_ss_send_struct;


typedef struct 
{
    srv_ss_act_enum act_op; /* action operation code */
    void *req_info; /* request information which is casted according to act_op */
} mmi_ss_act_start_struct;

typedef struct 
{
    srv_ss_direction_enum direction; /* MO/MT */
    WCHAR display_buf[SRV_SS_MAX_LENGTH + 1];  /* ussd string in ucs2 */
    WCHAR reply_buf[SRV_SS_MAX_LENGTH + 1];
} mmi_ss_ussr_struct;


typedef struct 
{
    srv_ss_direction_enum direction; /* MO/MT */
    WCHAR display_buf[SRV_SS_MAX_LENGTH + 1];  /* ussd string in ucs2 */
} mmi_ss_ussn_struct;



typedef struct 
{
    mmi_sim_enum sim;
    void *data;
} mmi_ss_scrn_info_struct;


typedef struct 
{
    mmi_sim_enum sim;
} mmi_ss_grp_info_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER /* event parameter header */
    mmi_sim_enum sim;
} mmi_ss_adjust_grp_evt_struct;



extern mmi_ss_cntx_struct *mmi_ss_p;

/***************************************************************************** 
 * Internal Function
 *****************************************************************************/
/* SsStructMgmt.c */
extern void mmi_ss_cntx_set_ptr(mmi_sim_enum sim);
extern void mmi_ss_cntx_reset_ptr(void);
extern srv_ss_act_enum mmi_ss_cntx_get_curr_op(mmi_sim_enum sim);
extern void mmi_ss_cntx_set_curr_op(mmi_sim_enum sim, srv_ss_act_enum op);
extern S32 mmi_ss_cntx_get_connected_call_num(mmi_sim_enum sim);
extern void mmi_ss_cntx_set_connected_call_num(mmi_sim_enum sim, S32 ctd_call_num);
extern void mmi_ss_cntx_get_scr_proceed(mmi_sim_enum sim, mmi_ss_scr_proceed_struct *info);
extern void mmi_ss_cntx_set_scr_proceed(mmi_sim_enum sim, mmi_ss_scr_proceed_struct *info);
extern void mmi_ss_cntx_get_scr_defer(mmi_sim_enum sim, mmi_ss_scr_defer_struct *info);
extern void mmi_ss_cntx_set_scr_defer(mmi_sim_enum sim, mmi_ss_scr_defer_struct *info);
extern void *mmi_ss_cntx_get_adj_grp_user_data(mmi_sim_enum sim);
extern void mmi_ss_cntx_set_adj_grp_user_data(mmi_sim_enum sim, void *user_data);
extern void mmi_ss_set_hilight_idx(mmi_sim_enum sim, S32 idx);
extern S32 mmi_ss_get_hilight_idx(mmi_sim_enum sim);


#endif /* SS_PROT_H */ 
