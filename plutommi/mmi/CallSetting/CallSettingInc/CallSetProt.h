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
 *  CallSetProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting application internal prototypes
 *
 * Author:
 * -------
 * 
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
 *============================================================================== 
 *******************************************************************************/
#ifndef CALLSET_PROT_H
#define CALLSET_PROT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/

#include "CallSetGprot.h"
#include "CallSetSrvGprot.h"

#include "SsSrvGprot.h"
#include "UcmSrvGprot.h" /* SRV_UCM_MAX_NUM_URI_LEN */

#ifdef __MMI_CM_WHITE_LIST__
#include "SettingDefs.h" /* MAX_SIM_SETTING_PASSWD_LEN */
#endif /* __MMI_CM_WHITE_LIST__ */

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "kal_non_specific_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_touch_screen.h"
#include "mmi_ap_dcm_config.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(CFG_MMI_CFU_SEPARATE_LINE) && ((CFG_MMI_CFU_SEPARATE_LINE == __ON__)||(CFG_MMI_CFU_SEPARATE_LINE == __AUTO__))
    #ifndef __MMI_CFU_SEPARATE_LINE__
    #define __MMI_CFU_SEPARATE_LINE__
    #endif
#endif

#define MMI_CALLSET_CTR_MAX_TIME_DIGIT 4

#ifdef __MMI_VIDEO_TELEPHONY__
    #define MMI_CALLSET_CF_ITEM_NUM   9
#else /* __MMI_VIDEO_TELEPHONY__ */
    #define MMI_CALLSET_CF_ITEM_NUM   5
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    #define MMI_CALLSET_CB_ITEM_NUM   10
#else /* __MMI_VIDEO_TELEPHONY__ */
    #define MMI_CALLSET_CB_ITEM_NUM   5
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    #define MMI_CALLSET_SS_ITEM_NUM   14
#else /* __MMI_VIDEO_TELEPHONY__ */
    #define MMI_CALLSET_SS_ITEM_NUM   10
#endif /* __MMI_VIDEO_TELEPHONY__ */

#if 0
#ifdef __OP01_FWPBW__
/* under construction !*/
/* under construction !*/
#endif /* __OP01_FWPBW__ */
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

typedef enum
{
    EVT_ID_CALLSET_UPDATE = CALLSET_BASE + 1,
    EVT_ID_CALLSET_POST_CLOSE,
    EVT_ID_CALLSET_TOTAL
} mmi_callset_evt_enum;


#ifdef __MMI_CH_QUICK_END__
typedef enum
{
    MMI_CALLSET_INLINE_QUICK_END_SEL_CAPTION = CALLSET_BASE + 1,
    MMI_CALLSET_INLINE_QUICK_END_SEL,
    MMI_CALLSET_INLINE_QUICK_END_TEXT_CAPTION,
    MMI_CALLSET_INLINE_QUICK_END_TEXTEDIT,
    MMI_CALLSET_INLINE_TOTAL
} mmi_callset_inline_item_enum;
#endif /* __MMI_CH_QUICK_END__ */

#ifdef __MMI_CALLSET_CALL_BARRING__
typedef enum
{
    MMI_CALLSET_CB_CANCELALL,
    MMI_CALLSET_CB_CHANGE_PWD,
    MMI_CALLSET_CB_TOTAL
} mmi_callset_cb_operation_enum;
#endif /* __MMI_CALLSET_CALL_BARRING__ */


typedef enum
{
#ifdef __MMI_CALLSET_LINE_SWITCHING__
    MMI_CALLSET_OP_LINE_SWITCH,
#endif /*__MMI_CALLSET_LINE_SWITCHING__*/
#ifdef __MMI_CALLSET_CUG__
    MMI_CALLSET_OP_CUG,
#endif /* __MMI_CALLSET_CUG__ */
#ifdef __MMI_CALLSET_CALLER_ID__
    MMI_CALLSET_OP_CID,
#endif /* __MMI_CALLSET_CALLER_ID__ */
    MMI_CALLSET_OP_START,
#ifdef __MMI_CALLSET_AUTO_REDIAL__
    MMI_CALLSET_OP_AUTOREDIAL,
#endif /*__MMI_CALLSET_AUTO_REDIAL__*/
#ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
    MMI_CALLSET_OP_CTD,
#endif /* __MMI_CALLSET_CTD_CONFIGURABLE__ */
#ifdef __MMI_UCM_REJECT_BY_SMS__
    MMI_CALLSET_OP_REJ_BY_SMS,
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#ifdef __MMI_CONNECT_NOTICE__
    MMI_CALLSET_OP_CONNECT_NOTICE,
#endif /* __MMI_CONNECT_NOTICE__ */
#if 0
#ifdef __OP01_FWPBW__
/* under construction !*/
#endif /* __OP01_FWPBW__ */
#endif
#ifdef __MMI_CH_QUICK_END__
    MMI_CALLSET_OP_CH_QUICK_END,
#endif /* __MMI_CH_QUICK_END__ */
#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
    MMI_CALLSET_OP_CTR,
#endif  /*__MMI_CALLSET_CALLTIME_REMINDER__ */  
#ifdef __MMI_CM_BLACK_LIST__
    MMI_CALLSET_OP_BL_FROM_LIST,
#ifdef __MMI_UCM_AUTO_REJECT_NO_CALL_ID__
    MMI_CALLSET_OP_BL_REJ_UNKNOWN_NUM,
#endif /* __MMI_UCM_AUTO_REJECT_NO_CALL_ID__ */
#endif /* __MMI_CM_BLACK_LIST__ */
#ifdef __MMI_CM_WHITE_LIST__
    MMI_CALLSET_OP_WL_FROM_LIST,
#endif /* __MMI_CM_WHITE_LIST__ */
#ifdef __CTM_SUPPORT__
    MMI_CALLSET_OP_CTM,
#endif /* __CTM_SUPPORT__ */
#ifdef __VOICE_CHANGER_SUPPORT__
    MMI_CALLSET_OP_MAGIC_VOICE,
#endif /* __VOICE_CHANGER_SUPPORT__ */

    MMI_CALLSET_OP_TOTAL
} mmi_callset_op_enum;


typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_callset_op_enum op;
} mmi_callset_evt_update_struct;


typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
} mmi_callset_evt_post_close_struct;


#ifdef __IP_NUMBER__
typedef struct
{
    srv_callset_ip_number_item_struct setting[SRV_CALLSET_MAX_IP_NUMBER];
} mmi_callset_ip_number_list_struct;
#endif /* __IP_NUMBER__ */


#ifdef __MMI_CALLSET_CUG__
typedef struct
{
    WCHAR item[SRV_CALLSET_CUG_MAX_GROUP_NUM][4 + SRV_CALLSET_CUG_MAX_NAME_LENGTH + 1];
} mmi_callset_cug_list_struct;
#endif /* __MMI_CALLSET_CUG__ */


#ifdef __MMI_CM_BLACK_LIST__
typedef struct
{
    WCHAR number[SRV_CALLSET_BLACKLIST_MAX_ITEM][SRV_UCM_MAX_NUM_URI_LEN + 1];
} mmi_callset_bl_num_list_struct;
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __MMI_CM_WHITE_LIST__
typedef struct
{
    WCHAR number[SRV_CALLSET_WHITELIST_MAX_ITEM][SRV_UCM_MAX_NUM_URI_LEN + 1];
} mmi_callset_wl_num_list_struct;
#endif /* __MMI_CM_WHITE_LIST__ */


typedef struct
{
    mmi_sim_enum sim;
#ifdef __MMI_CALLSET_CALL_BARRING__
    U8 cb_state;
#endif
    mmi_id cf_num_edit_gid;
    srv_ss_call_forward_req_struct cf_info;
#ifdef __MMI_CALLSET_CALL_BARRING__
    srv_ss_call_bar_req_struct cb_info; 
#endif
#ifdef __MMI_CALLSET_CUG__
    mmi_callset_cug_list_struct *cug_list;
    mmi_id cug_name_edit_gid;
    mmi_id cug_id_edit_gid;
    U8 cug_input;
    U8 cug_count;
    U8 cug_map[SRV_CALLSET_CUG_MAX_GROUP_NUM];
#endif /* __MMI_CALLSET_CUG__ */
} mmi_callset_sim_cntx_struct;


typedef struct
{
    mmi_sim_enum target_sim;
    mmi_callset_sim_cntx_struct sim1_cntx;
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_callset_sim_cntx_struct sim2_cntx;
#if (MMI_MAX_SIM_NUM>=3)
	mmi_callset_sim_cntx_struct sim3_cntx;
#if (MMI_MAX_SIM_NUM>=4)
	mmi_callset_sim_cntx_struct sim4_cntx;
#endif /* MMI_MAX_SIM_NUM>=4*/
#endif /* MMI_MAX_SIM_NUM>=3*/
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
    srv_callset_ctr_mode_enum ctr_mode_input;
    WCHAR ctr_time_input[MMI_CALLSET_CTR_MAX_TIME_DIGIT + 1];
#endif /*__MMI_CALLSET_CALLTIME_REMINDER__ */
#ifdef __IP_NUMBER__
    mmi_id ip_number_edit_gid;
    S32 ip_number_input;
#endif /* __IP_NUMBER__ */
#ifdef __MMI_FTE_SUPPORT__
    void (*tap_cb)(void);
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_CM_BLACK_LIST__
#ifdef __MMI_CM_BLACK_LIST_EXT__
    srv_callset_call_type_enum bl_call_type;
#endif /* __MMI_CM_BLACK_LIST_EXT__ */
    mmi_id blacklist_edit_gid;
    S32 blacklist_input;
    mmi_callset_bl_num_list_struct *bl_list;
#endif /* __MMI_CM_BLACK_LIST__ */
#ifdef __MMI_CM_WHITE_LIST__
#ifdef __MMI_CM_WHITE_LIST_EXT__
    srv_callset_call_type_enum wl_call_type;
#endif /* __MMI_CM_WHITE_LIST_EXT__ */
    mmi_id whitelist_edit_gid;
    S32 whitelist_input;
    mmi_callset_wl_num_list_struct *wl_list;
    WCHAR whitelist_num[SRV_UCM_MAX_NUM_URI_LEN + 1];
#endif /* __MMI_CM_WHITE_LIST__ */
#ifdef __MMI_CH_QUICK_END__
    mmi_id quick_end_edit_gid;
#endif /* __MMI_CH_QUICK_END__ */
    MMI_BOOL fs_edit_processing;

} mmi_callset_context_struct;


typedef struct
{
    srv_ss_act_enum op;
    U8 type;
    srv_ss_call_type_enum call_type;
    mmi_menu_id menu_id;
} mmi_callst_ss_operation_data_struct;


extern mmi_callset_context_struct *mmi_callset_p;
extern mmi_callset_sim_cntx_struct *mmi_callset_sim_p;


/***************************************************************************** 
 * Internal Function
 *****************************************************************************/

/* CallSetStructMgmt.c */
extern void mmi_callset_sim_cntx_set_ptr(mmi_sim_enum sim);
extern void mmi_callset_sim_cntx_reset_ptr(void);


#endif /* CALLSET_PROT_H */
