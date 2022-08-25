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
 * CallLogSrvProt.h 
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_CALL_LOG_PROT_H
#define SRV_CALL_LOG_PROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Abbreviation                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"

#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "lcd_cqueue.h"
#include "app_ltlcom.h"

#include "Custom_CallLog.h"
#include "common_nvram_editor_data_item.h"

#include "l4c_aux_struct.h"

#include "MMIDataType.h"
#include "mmi_frm_utility_gprot.h"

#include "ProcedureGprot.h"
#include "ConnectManageGProt.h"

#include "PhbSrvGprot.h"
#include "CallLogSrvGprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvStore.h"



#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 


/*----------------------------------------------------------------------------*/
/* Internal compile Options                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Internal compile Option dependencies                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Internal configuration                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* TRACE group                                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Version                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
#define SRV_CLOG_NUM_ROUNDING(num, size)             (((num) + (size) - 1) / (size))
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
#define SRV_CLOG_IF_TRUE(x)                     (x != 0)
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
#define SRV_CLOG_HDL(inst)                      ((SRV_CLOG_HANDLE)(inst))
#define SRV_CLOG_INST(handle)                   ((srv_clog_inst_struct*)(handle))
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
#define SRV_CLOG_PHB_ID2IDX(phb_id)             (srv_phb_get_store_index_by_number_id(phb_id))
#define SRV_CLOG_IS_PHB_ID_VALID(phb_id)        (srv_phb_check_number_id(phb_id))
#define SRV_CLOG_IS_SAME_PHB_ID(p1, p2)         (!memcmp((const void*)(&(p1)),(const void*)(&(p2)), sizeof(SRV_PHB_ID)))
#define SRV_CLOG_SET_INVALID_PHB_ID(phb_id)     (srv_phb_set_invalid_number_id(&phb_id))

#define SRV_CLOG_SET_BIT(flag, bit)                     ((flag) |= (bit))
#define SRV_CLOG_CLEAR_BIT(flag, bit)                   ((flag) &= ~(bit))
#define SRV_CLOG_CHECK_BIT(flag, bit)                   (((flag) & (bit)) != 0)
#define SRV_CLOG_GET_BIT(flag, mask)                    ((flag) & (mask))
#define SRV_CLOG_CHECK_BIT_GRP(flag, mask, bit_grp)     (((flag) & (mask)) == (bit_grp))

#define SRV_CLOG_TRC_SIM_VAL(sim_id, value)             (SRV_CLOG_CHECK_BIT(MMI_SIM_ALL, (sim_id)) ? (value) : 0)

#define SRV_CLOG_IDX2BIT(idx)                           ((0x01) << (idx))
#define SRV_CLOG_BIT2IDX(bit, idx)                      (idx = srv_clog_ib_bit2idx(bit))

#define SRV_CLOG_PI_IDX2P(props, idx, idx_pos)   ((props) |= ((idx) << (idx_pos)))
#define SRV_CLOG_PI_P2IDX(props, bit_grp, idx_pos)      (((props) & (bit_grp)) >> (idx_pos))

#define SRV_CLOG_PI_P2BIT(props, bit_grp, idx_pos)                  \
                SRV_CLOG_IDX2BIT(SRV_CLOG_PI_P2IDX(props, bit_grp, idx_pos))

#define SRV_CLOG_PI_PP_CMP(props_1, props_2, bit_grp)               \
                (((props_1) & bit_grp) == ((props_2) & bit_grp))

#define SRV_CLOG_PI_IS_IDX_HIT(type, idx)                           \
                ((type) == 0 || (SRV_CLOG_CHECK_BIT((type), (SRV_CLOG_IDX2BIT(idx)))))

/* For duration, total time and unread time */
#define SRV_CLOG_GET_HI_VAL(full_val, hi_pos, hi_mask)              \
                (((full_val) >> (hi_pos)) & (hi_mask))

#define SRV_CLOG_MAKE_FULL_VAL(hi_val, hi_pos, low_val)             \
                (((hi_val) << (hi_pos)) | (low_val))

#define SRV_CLOG_PI_GET_VAL(props, bit_grp, bit_pos, low_val, hi_pos)           \
                (SRV_CLOG_MAKE_FULL_VAL((SRV_CLOG_PI_P2IDX(props, bit_grp, bit_pos)), hi_pos, low_val))

#define SRV_CLOG_PI_SET_VAL(props, bit_grp, bit_pos, full_val, hi_pos)         \
                (SRV_CLOG_PI_IDX2P(props, (SRV_CLOG_GET_HI_VAL(full_val, hi_pos, ((bit_grp) >> (bit_pos)))), bit_pos))

#define  SRV_CLOG_PI_GET_DUR(props, low_dur)                                    \
                ((U32)(SRV_CLOG_PI_GET_VAL(props, SRV_CLOG_LSP_DURATION, SRV_CLOG_LSP_DURATION_POS, low_dur, 16)))

#define SRV_CLOG_PI_SET_DUR(props, low_dur, full_dur)                                                                   \
                do {                                                                                                    \
                    SRV_CLOG_CLEAR_BIT(props, SRV_CLOG_LSP_DURATION);                                                   \
                    SRV_CLOG_PI_SET_VAL(props, SRV_CLOG_LSP_DURATION, SRV_CLOG_LSP_DURATION_POS, full_dur, 16);         \
                    low_dur = (U16)(full_dur & 0xFFFF);                                                                 \
                }while(0)

#define SRV_CLOG_PI_GET_TNUM(props, low_tt_num)                     \
                (SRV_CLOG_PI_GET_VAL(props, SRV_CLOG_LSP_TOTAL_NUM, SRV_CLOG_LSP_TOTAL_NUM_POS, low_tt_num, 8))

#define SRV_CLOG_PI_SET_TNUM(props, low_tt_num, full_tt_num)                                                            \
                do {                                                                                                    \
                    SRV_CLOG_CLEAR_BIT(props, SRV_CLOG_LSP_TOTAL_NUM);                                                  \
                    SRV_CLOG_PI_SET_VAL(props, SRV_CLOG_LSP_TOTAL_NUM, SRV_CLOG_LSP_TOTAL_NUM_POS, full_tt_num, 8);     \
                    low_tt_num = (U8)(full_tt_num & 0xFF);                                                              \
                }while (0)

#define SRV_CLOG_PI_GET_URNUM(props, low_ur_num)   \
                (SRV_CLOG_PI_GET_VAL(props, SRV_CLOG_LSP_UNREAD_NUM, SRV_CLOG_LSP_UNREAD_NUM_POS, low_ur_num, 8))

#define SRV_CLOG_PI_SET_URNUM(props, low_ur_num, full_ur_num)                                                           \
                do {                                                                                                    \
                    SRV_CLOG_CLEAR_BIT(props, SRV_CLOG_LSP_UNREAD_NUM);                                                 \
                    SRV_CLOG_PI_SET_VAL(props, SRV_CLOG_LSP_UNREAD_NUM, SRV_CLOG_LSP_UNREAD_NUM_POS, full_ur_num, 8);   \
                    low_ur_num = (U8)(full_ur_num & 0xFF);                                                              \
                    }while (0)

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

#define SRV_CLOG_SILOG_GET_TOTALNUM(si_log)                 ((si_log)->total_num)
#define SRV_CLOG_SILOG_SET_TOTALNUM(si_log, new_tt_num)     ((si_log)->total_num = (kal_uint8)new_tt_num)
#define SRV_CLOG_SILOG_GET_UNREADNUM(si_log)                ((si_log)->unread_num)
#define SRV_CLOG_SILOG_SET_UNREADNUM(si_log, new_ur_num)    ((si_log)->unread_num = (kal_uint8)new_ur_num)
#define SRV_CLOG_SILOG_GET_LOG_ID(si_log)                   ((si_log)->log_id)
#define SRV_CLOG_SILOG_SET_LOG_ID(si_log, new_id)           ((si_log)->log_id = (kal_uint16)new_id)
#define SRV_CLOG_SILOG_GET_TYPE_ID(si_log)                  ((si_log)->type_id)
#define SRV_CLOG_SILOG_CLEAR_TYPE_ID(si_log)                ((si_log)->type_id = 0)
#define SRV_CLOG_SILOG_GET_TIMESTAMP(si_log)                ((si_log)->timestamp)
#define SRV_CLOG_SILOG_GET_PHB_ID(si_log)                   ((si_log)->phb_id)
#define SRV_CLOG_SILOG_SET_PHB_ID(si_log, new_id)           ((si_log)->phb_id = new_id)
#define SRV_CLOG_SILOG_GET_PHB_IDX(si_log)                  (SRV_CLOG_PHB_ID2IDX(SRV_CLOG_SILOG_GET_PHB_ID(si_log)))

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

#define SRV_CLOG_SI_GET_LOG_ID(si_log)          ((si_log)->base_log.log_id)
#define SRV_CLOG_SI_SET_LOG_ID(si_log, new_id)  ((si_log)->base_log.log_id = new_id)
#define SRV_CLOG_SI_GET_P(si_log)               ((si_log)->base_log.props)
#define SRV_CLOG_SI_CLEAR_P(si_log)             ((si_log)->base_log.props = 0)
#define SRV_CLOG_SI_GET_I_IN_P(si_log)          (SRV_CLOG_GET_BIT(SRV_CLOG_SI_GET_P(si_log), SRV_CLOG_LSP_IDENTITY))
#define SRV_CLOG_SI_GET_PHB_ID(si_log)          ((si_log)->base_log.phb_id)
#define SRV_CLOG_SI_GET_PHB_IDX(si_log)         (SRV_CLOG_PHB_ID2IDX(SRV_CLOG_SI_GET_PHB_ID(si_log)))
#define SRV_CLOG_SI_GET_TNUM(si_log)            (srv_clog_si_get_log_total_num(si_log)) /* Not support now */
#define SRV_CLOG_SI_GET_URNUM(si_log)           (srv_clog_si_get_log_unread_num(si_log))
#define SRV_CLOG_SI_GET_CID(si_log)             (srv_clog_si_get_cid(si_log))
#define SRV_CLOG_SI_GET_NAME(si_log)            (srv_clog_si_get_name(si_log))

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

#define SRV_CLOG_IS_STR_EMPTY(str)              (!str || str[0] == '\0')
#define SRV_CLOG_SET_STR_EMPTY(str)             (str[0] = '\0')


/*----------------------------------------------------------------------------*/
/* typedef                                                                     */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

typedef nvram_ef_clog_call_log_struct   srv_clog_si_struct;          /* For common log, it's a special one  */

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

typedef srv_clog_st_base_log_struct             srv_clog_base_info_struct;     /* Base Header */
typedef srv_clog_st_log_cmn_head_struct         srv_clog_log_cmn_head_struct;  /* Common hader with name and cid */


/*FlowReserved
typedef srv_clog_st_sms_log_struct              srv_clog_sms_info_struct;
typedef srv_clog_st_nwpd_log_struct             srv_clog_nwpd_info_struct;
typedef srv_clog_st_log_union                   srv_clog_log_info_union;
*/

#if (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__))
typedef struct
{
    nvram_ef_clog_base_log_struct base_log;
    kal_uint8  cid[NVRAM_CLOG_CID_MAX_LEN + 1];
    kal_uint16 duration[SRV_CLOG_TIME_DETAIL_MAX_NUM];
    kal_uint8  total_num;
    kal_uint8  unread_num;
}srv_clog_log_info_struct;

typedef struct
{
    NVRAM_EF_CLOG_LOG_HEAD;
    kal_uint8  cid[NVRAM_CLOG_CID_MAX_LEN + 1];
    kal_uint16 duration[SRV_CLOG_TIME_DETAIL_MAX_NUM];
    kal_uint8  total_num;
    kal_uint8  unread_num;
}srv_clog_call_info_struct;

typedef srv_clog_log_info_struct                srv_clog_si_struct;          /* For common log, it's a special one  */

#else  /* (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__)) */

typedef srv_clog_st_log_struct                  srv_clog_log_info_struct;   /* For common log in memory level, it's same as the one storage level */
typedef srv_clog_log_info_struct                srv_clog_si_struct;         /* For sort info in sort info table, it's same as the one in memory level */
typedef srv_clog_st_call_log_struct             srv_clog_call_info_struct;  /* For call log only in memory level, it's same as the one in storage level */

#endif /* (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__)) */

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_SIM_ID_ALL                     ((mmi_sim_enum)(MMI_SIM_ALL))
#define SRV_CLOG_LT_ALL                         (SRV_CLOG_CLT_ALL | SRV_CLOG_SLT_ALL | SRV_CLOG_NWPDLT_ALL)
#define SRV_CLOG_ST_ALL                         (SRV_CLOG_CALL_TYPE_ALL)

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

/*---------------------- Type Static Property (TSP) ---------------------------*/
/* Call log type, allocate 4 bits */
#define SRV_CLOG_TSP_CLT_POS                    (4)
#define SRV_CLOG_TSP_CLT_GRP                    (0xF0)
#define SRV_CLOG_TSP_CLT_DIALED                 (0x10)  // 00 -> 0
#define SRV_CLOG_TSP_CLT_RECVED                 (0x20)  // 01 -> 1
#define SRV_CLOG_TSP_CLT_MISSED                 (0x40)  // 10 -> 2
#define SRV_CLOG_TSP_CLT_REJED                  (0x80)  // 11 -> 3 
#define SRV_CLOG_TSP_CLT_ALL                    (0xF0)  // 11 -> 3 

/* SIM id, allocate 2 bit to support Gemini, 4 SIM at most */
#define SRV_CLOG_TSP_SIM_ID_POS                 (2)
#define SRV_CLOG_TSP_SIM_ID_GRP                 (0x0C)
#define SRV_CLOG_TSP_SIM_ID_SIM1                (0x00)  // 00 -> 0
#define SRV_CLOG_TSP_SIM_ID_SIM2                (0x04)  // 01 -> 1
#define SRV_CLOG_TSP_SIM_ID_SIM3                (0x08)  // 10 -> 2
#define SRV_CLOG_TSP_SIM_ID_SIM4                (0x0C)  // 11 -> 3

/*---------------------- Type Dynamic Property (TDP) ---------------------------*/
#define SRV_CLOG_TDP_NEW_EVENT_POS              (1)
#define SRV_CLOG_TDP_NEW_EVENT_GRP              (0x02)
#define SRV_CLOG_TDP_NEW_EVENT                  (0x02)
#define SRV_CLOG_TDP_DELETED                    (0x01)

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*---------------------- Log Static Property (LSP) ---------------------------*/

/* Log category bit mask, allocate 3 bits for expanding in the future */
#define SRV_CLOG_LSP_CATE_POS                   (0)
#define SRV_CLOG_LSP_CATE                       (0x0007 << SRV_CLOG_LSP_CATE_POS)
#define SRV_CLOG_LSP_CATE_CALL                  (0x0000 << SRV_CLOG_LSP_CATE_POS)
#define SRV_CLOG_LSP_CATE_SMS                   (0x0001 << SRV_CLOG_LSP_CATE_POS)
#define SRV_CLOG_LSP_CATE_NWPD                  (0x0002 << SRV_CLOG_LSP_CATE_POS)

/* SIM id, allocate 3 bit to support Gemini+ now, 8 SIM at most */
#define SRV_CLOG_LSP_SIM_ID_POS                 (3)
#define SRV_CLOG_LSP_SIM_ID                     (0x0007 << SRV_CLOG_LSP_SIM_ID_POS)
#define SRV_CLOG_LSP_SIM_ID_SIM1                (0x0000 << SRV_CLOG_LSP_SIM_ID_POS)
#define SRV_CLOG_LSP_SIM_ID_SIM2                (0x0001 << SRV_CLOG_LSP_SIM_ID_POS)
#define SRV_CLOG_LSP_SIM_ID_SIM3                (0x0002 << SRV_CLOG_LSP_SIM_ID_POS)
#define SRV_CLOG_LSP_SIM_ID_SIM4                (0x0003 << SRV_CLOG_LSP_SIM_ID_POS)

/* Call log type, allocate 3 bits */
#define SRV_CLOG_LSP_LT_POS                     (3 + 3)

#define SRV_CLOG_LSP_CLT                        (0x0007 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_CLT_DIALED                 (0x0000 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_CLT_RECVED                 (0x0001 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_CLT_MISSED                 (0x0002 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_CLT_REJED                  (0x0003 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_SMS                        (0x0003 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_SMS_SENT                   (0x0001 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_SMS_RECV                   (0x0002 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_NWPD                       (0x0003 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_NWPD_SENT                  (0x0001 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_NWPD_RECV                  (0x0002 << SRV_CLOG_LSP_LT_POS)
#define SRV_CLOG_LSP_LT                         (SRV_CLOG_LSP_CLT | SRV_CLOG_LSP_SMS | SRV_CLOG_LSP_NWPD)

/* Call type, allocate 3 bits */
#define SRV_CLOG_LSP_ST_POS                     (3 + 3 + 3)
#define SRV_CLOG_LSP_ST                         (0x0007 << SRV_CLOG_LSP_ST_POS)
#define SRV_CLOG_LSP_CT                         (0x0007 << SRV_CLOG_LSP_ST_POS)
#define SRV_CLOG_LSP_CT_VOICE                   (0X0000 << SRV_CLOG_LSP_ST_POS)
#define SRV_CLOG_LSP_CT_VOIP                    (0X0001 << SRV_CLOG_LSP_ST_POS)
#define SRV_CLOG_LSP_CT_VIDEO                   (0X0002 << SRV_CLOG_LSP_ST_POS)

#define SRV_CLOG_LSP_IDENTITY                   (SRV_CLOG_LSP_CATE | SRV_CLOG_LSP_SIM_ID | SRV_CLOG_LSP_LT | SRV_CLOG_LSP_ST)

/* If cid is private number, allocate 1 bit */
#define SRV_CLOG_LSP_CID_POS                    (3 + 3 + 3 + 3)
#define SRV_CLOG_LSP_CID_IS_PRIVATE             (0x0001 << SRV_CLOG_LSP_CID_POS)

/* Extent total num */
#define SRV_CLOG_LSP_TOTAL_NUM_POS              (3 + 3 + 3 + 3 + 1)
#define SRV_CLOG_LSP_TOTAL_NUM                  (0x0001 << SRV_CLOG_LSP_TOTAL_NUM_POS)

/* Extent unread num */
#define SRV_CLOG_LSP_UNREAD_NUM_POS             (3 + 3 + 3 + 3 + 1 + 1)
#define SRV_CLOG_LSP_UNREAD_NUM                 (0x0001 << SRV_CLOG_LSP_UNREAD_NUM_POS)

/* Extent duration */
#define SRV_CLOG_LSP_DURATION_POS               (3 + 3 + 3 + 3 + 1 + 1 + 1)
#define SRV_CLOG_LSP_DURATION                   (0x0003 << SRV_CLOG_LSP_DURATION_POS)

/* If has phb_id, allocate 1 bit, if no, can use phb_id field to store other things */
#define SRV_CLOG_LSP_PHB_ID_POS                 (3 + 3 + 3 + 3 + 1 + 1 + 1 + 2)
#define SRV_CLOG_LSP_HAS_PHB_ID                 (0x0001 << SRV_CLOG_LSP_PHB_ID_POS)

/* Read status, if unread, can use read_num to store other things */
#define SRV_CLOG_LSP_NEW_EVENT_POS              (3 + 3 + 3 + 3 + 1 + 1 + 1 + 2 + 1)
#define SRV_CLOG_LSP_NEW_EVENT                  (0x0001 << SRV_CLOG_LSP_NEW_EVENT_POS)

/* Store ID, if save in phone storage or copy from SIM card */
#define SRV_CLOG_LSP_STORE_ID_POS               (3 + 3 + 3 + 3 + 1 + 1 + 1 + 2 + 1 + 1) //19
#define SRV_CLOG_LSP_STORE_ID_SIM               (0x0001 << SRV_CLOG_LSP_STORE_ID_POS)

/*---------------------- Log Dynamic Property (LDP) ---------------------------*/
#define SRV_CLOG_LDP_GRP_POS                    (24)
#define SRV_CLOG_LDP_GRP                        (0x0F << SRV_CLOG_LDP_GRP_POS)

#define SRV_CLOG_LDP_DIRTY_POS                  (SRV_CLOG_LDP_GRP_POS)
#define SRV_CLOG_LDP_DIRTY                      (0x0001 << SRV_CLOG_LDP_DIRTY_POS)

#define SRV_CLOG_LDP_DELETED_POS                (SRV_CLOG_LDP_GRP_POS + 1)
#define SRV_CLOG_LDP_DELETED                    (0x0001 << SRV_CLOG_LDP_DELETED_POS)

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/* For context, PHBx_READY is use indirectly in srv_clog_sim_phb_last_number_ready_ind_hdlr, 3 bits needs*/
#define SRV_CLOG_CNTX_FLAG_PHB_READY_POS        (0)
#define SRV_CLOG_GET_CNTX_SIM_PHB_READY(sim_id) ((sim_id) << SRV_CLOG_CNTX_FLAG_PHB_READY_POS)        
#define SRV_CLOG_CNTX_FLAG_PHB1_READY           (MMI_SIM1 << SRV_CLOG_CNTX_FLAG_PHB_READY_POS)
#define SRV_CLOG_CNTX_FLAG_PHB2_READY           (MMI_SIM2 << SRV_CLOG_CNTX_FLAG_PHB_READY_POS)
#define SRV_CLOG_CNTX_FLAG_PHB3_READY           (MMI_SIM3 << SRV_CLOG_CNTX_FLAG_PHB_READY_POS)
#define SRV_CLOG_CNTX_FLAG_PHB4_READY           (MMI_SIM4 << SRV_CLOG_CNTX_FLAG_PHB_READY_POS)
#define SRV_CLOG_CNTX_FLAG_PHB_READY_TOTAL      (MMI_SIM_ALL << SRV_CLOG_CNTX_FLAG_PHB_READY_POS)

#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
/* For instance */
#define SRV_CLOG_INST_FLAG_PRE_DEF              (0x0001)
#define SRV_CLOG_INST_FLAG_IN_USE               (0x0002)
#define SRV_CLOG_INST_FLAG_HIGH_PRIORITY        (0x0004)
#define SRV_CLOG_INST_FLAG_HAS_LOG_ID           (0x0008)
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/* For index table */
#define SRV_CLOG_IDX_INVALID_IDX                ((U16)(~0))

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/* List level */
typedef enum
{
    SRV_CLOG_LIST_LEVEL_DEFAULT = 0x00, /* Default value, discard it if act as a filter */
    SRV_CLOG_LIST_LEVEL_SORT = 0x01,    /* Merge and sort list level */
    SRV_CLOG_LIST_LEVEL_THREAD = 0x02,  /* Thread list level */
    SRV_CLOG_LIST_LEVEL_STORE = 0x04,   /* Storage list level */
    SRV_CLOG_LIST_LEVEL_MAX_ITEM        /* Max item */
} srv_clog_list_level_enum;

/* To indicate service state */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

typedef enum
{
    SRV_CLOG_STATE_INIT,
    SRV_CLOG_STATE_LOAD,
    SRV_CLOG_STATE_PARSE,
    SRV_CLOG_STATE_PHASE1_READY,
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
    SRV_CLOG_STATE_REVISE,
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
    SRV_CLOG_STATE_SIM_SYNC,
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */
    SRV_CLOG_STATE_READY,
    SRV_CLOG_STATE_ADD,
    SRV_CLOG_STATE_UPDATE,
    SRV_CLOG_STATE_UPDATE_ALL,
    SRV_CLOG_STATE_DELETE,
    SRV_CLOG_STATE_DELETE_ALL,
#ifdef __MMI_CLOG_MARK_SEVERAL__
    SRV_CLOG_STATE_DELETE_MULTI,
#endif /* __MMI_CLOG_MARK_SEVERAL__ */
#ifndef __MMI_CONTACT_SLIM__
    SRV_CLOG_STATE_SEARCH,
#endif /* __MMI_CONTACT_SLIM__ */
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
    SRV_CLOG_STATE_PHB_REFRESH,
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */
    SRV_CLOG_STATE_MAX_ITEM
} srv_clog_state_enum;

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

typedef enum
{
    SRV_CLOG_STATE_INIT,
    SRV_CLOG_STATE_INITING,
    SRV_CLOG_STATE_READY,
    SRV_CLOG_STATE_MAX_ITEM
} srv_clog_state_enum;

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

typedef enum
{
    SRV_CLOG_IDENTITY_FIELD_CATE,
    SRV_CLOG_IDENTITY_FIELD_SIM_ID,
    SRV_CLOG_IDENTITY_FIELD_LOG_TYPE,
    SRV_CLOG_IDENTITY_FIELD_SUB_TYPE
} srv_clo_identity_field_enum;

/* To specify the log info type */
typedef enum
{
    SRV_CLOG_INFO_TYPE_LOG_ID,
    SRV_CLOG_INFO_TYPE_LOG_DATA,
    SRV_CLOG_INFO_TYPE_MAX_ITEM
} srv_clog_info_type_enum;

/*
 * The index list are split into 2 levels: level1 and level2.
 * Level1 for all logs, level2 for special logs with some filter, so:
 * for SRV_CLOG_IDX_INFO_BASE, it belongs to level1 always.
 * for SRV_CLOG_IDX_INFO_THREAD, it belongs to level1 if support thread, or level2 if not.
 * for SRV_CLOG_IDX_INFO_FILTER, it belongs to level2 always 
 */
typedef enum
{
    SRV_CLOG_IDX_INFO_BASE,
    SRV_CLOG_IDX_INFO_THREAD,
    SRV_CLOG_IDX_INFO_FILTER_EX = SRV_CLOG_IDX_INFO_THREAD, /* If not support thread, can use it as another filter list */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
    SRV_CLOG_IDX_INFO_FILTER = SRV_CLOG_IDX_INFO_FILTER_EX,
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    SRV_CLOG_IDX_INFO_FILTER,
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    SRV_CLOG_IDX_INFO_UNKNOWN,
    SRV_CLOG_IDX_INFO_MAX_ITEM = SRV_CLOG_IDX_INFO_UNKNOWN
} srv_clog_idx_info_enum;

typedef enum
{
    SRV_CLOG_SORT_ALGORITHM_CMN,
    SRV_CLOG_SORT_ALGORITHM_MAX_ITEM
} srv_clog_sort_algorithm_enum;

#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
typedef enum
{
    SRV_CLOG_AT_UPDATE_ADD,
    SRV_CLOG_AT_UPDATE_DEL,
    SRV_CLOG_AT_UPDATE_UPD,
    SRV_CLOG_AT_UPDATE_UPD_ALL,
    SRV_CLOG_AT_UPDATE_DEL_ALL,
    SRV_CLOG_AT_UPDATE_MAX_ITEM
} srv_clog_at_update_enum;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

typedef struct
{
    srv_clog_si_struct si_log;
    U8 sup_merge;
    U8 sup_thread;
    U8 need_merge;
    U8 is_full;
    srv_clog_log_identity_struct type_idt;  /* use to check type limitation */
    /* old one to delete when adding or replace when merging */
    SRV_CLOG_ID old_log_id;
    U8 old_type;
    U32 old_idxi_idx;
    U32 old_sit_idx;
    U32 best_sit_idx;
    srv_clog_idx_info_enum old_info_type;
    srv_clog_ret_enum ret;
} srv_clog_add_log_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_clog_state_enum trans_id;
} srv_clog_evt_struct;

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

typedef struct
{
    srv_clog_si_struct si_log;
    U8 sup_merge;
    U8 sup_thread;
    U8 need_merge;
    U8 is_full;
    srv_clog_log_identity_struct type_idt;  /* use to check type limitation */
    /* old one to delete when adding or replace when merging */
    SRV_CLOG_ID old_log_id;
    U32 old_props;
    U32 old_idxi_idx;
    U32 old_sit_idx;
    U32 best_sit_idx;
    srv_clog_idx_info_enum old_info_type;
    srv_clog_ret_enum ret;
} srv_clog_job_add_log_req_struct;


typedef struct srv_clog_comp_st srv_clog_comp_struct;

typedef struct
{
    S32 pid;
    U8 job_type;
    U8 job_state;
    U8 proc_state;
    U32 flags;  /* if req from buffer, cnf from buffer job from buffer. */
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id;
    U16 u16val1;
    U16 cursor2;
    U32 init_value;
    U32 cursor;
    void *req_data;
    void *cnf_data;
    SRV_CLOG_BASE_CB func_cb;
    struct srv_clog_comp_st *comp;
    srv_clog_ret_enum ret;
} srv_clog_job_struct;

typedef struct
{
    U8 queue_size;
    lcd_cqueue *queue;
} srv_clog_job_mgr_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 trans_id;
    void *user_data;
    void *para;
} srv_clog_job_continue_ind_struct;

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

typedef struct
{
    U16 total_num;
    U16 last_add_idx;   /* remember the last one to add new logs, just try to make the log id are in consecutive, best to read tegother. */
    srv_clog_si_struct *data[SRV_CLOG_LOG_MAX_NUM];
} srv_clog_si_tbl_struct;

#ifdef __SRV_CLOG_UT__

typedef struct
{
    U8 sort_type;
    U8 sort_dir;    /* direction */
    U8 sort_algo;   /* algorithm */
    U8 flags;
    srv_clog_log_identity_struct idt;
    U16 total_num;
    U16 max_size;
    U16 data[SRV_CLOG_LOG_MAX_NUM];
} srv_clog_idx_info_struct;

#else /* __SRV_CLOG_UT__ */ 

typedef struct
{
    U8 sort_type;
    U8 sort_dir;    /* direction */
    U8 sort_algo;   /* algorithm */
    U8 flags;
    srv_clog_log_identity_struct idt;
    U16 total_num;
    U16 max_size;
    U16 *data;
} srv_clog_idx_info_struct;
#endif /* __SRV_CLOG_UT__ */ 

typedef struct
{
    U16 last_get_idx;
    srv_clog_idx_info_struct *idx_info[SRV_CLOG_IDX_INFO_MAX_ITEM];
    srv_clog_si_tbl_struct *si_tbl;
    srv_clog_stl_mgr_struct *style_mgr;
} srv_clog_idx_tbl_struct;

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

typedef struct srv_clog_comp_st
{
    srv_clog_stl_mgr_struct *style_mgr;
    srv_clog_idx_tbl_struct *idx_tbl;
    srv_clog_si_tbl_struct *si_tbl;
} srv_clog_comp_struct;

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

typedef struct srv_clog_comp_st
{
    srv_clog_job_mgr_struct *job_mgr;
    srv_clog_stl_mgr_struct *style_mgr;
    srv_clog_si_tbl_struct *si_tbl;
    srv_clog_idx_tbl_struct *idx_tbl;
} srv_clog_comp_struct;

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

typedef struct
{
    U32 flags;
    srv_clog_log_identity_struct idt;
    void *user_data;
    srv_clog_comp_struct *comp;
} srv_clog_inst_struct;

typedef struct
{
    srv_clog_inst_struct *data[SRV_CLOG_MAX_INST_NUM];
} srv_clog_inst_tbl_struct;

typedef struct
{
    srv_clog_state_enum state;
    U32 max_log_id;
    S32 max_pid;
    U32 flags;
    srv_clog_comp_struct *comp; /* Components */
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    srv_clog_inst_tbl_struct *inst_tbl;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
} srv_clog_cntx_struct;


#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
/*----------------------------------------------------------------------------*/
/* Extern Global Variable                                                     */
/*----------------------------------------------------------------------------*/
extern srv_clog_cntx_struct *srv_clog_cntx_p;
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
extern srv_clog_cntx_struct *srv_clog_get_cntx(void);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
extern S32 srv_clog_is_init(void);
extern S32 srv_clog_is_initializing(void);
extern SRV_CLOG_ID srv_clog_new_log_id(srv_clog_cntx_struct *cntx);
extern SRV_CLOG_ID srv_clog_reset_log_id(srv_clog_cntx_struct *cntx);
extern SRV_CLOG_ID srv_clog_new_log_id_ex(srv_clog_cntx_struct *cntx, U32 *log_id);
extern SRV_CLOG_ID srv_clog_reserve_log_ids(srv_clog_cntx_struct *cntx, U32 count);
extern SRV_CLOG_ID srv_clog_revise_log_id(SRV_CLOG_ID log_id);

#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
extern S32 srv_clog_new_pid(srv_clog_cntx_struct *cntx);
extern SRV_CLOG_HANDLE srv_clog_create_int(const srv_clog_create_struct *create, U32 flags);
extern U32 srv_clog_get_inst_priority(SRV_CLOG_HANDLE handle);
extern U32 srv_clog_get_inst_flags(SRV_CLOG_HANDLE handle);

/*---------------------- AT Command Operation --------------------------------*/

#ifdef __MMI_CLOG_ATCMD_SUPPORT__
extern void srv_clog_at_init(void);
extern void srv_clog_at_notify_ready(srv_clog_cntx_struct *cntx);
extern void srv_clog_at_notify_update(
                srv_clog_at_update_enum type,
                srv_clog_cntx_struct *cntx,
                U32 props,
                srv_clog_log_identity_struct *idt,
                srv_clog_si_struct *si_log);

#endif /* __MMI_CLOG_ATCMD_SUPPORT__ */

/*---------------------- PHB Sync Operation ----------------------------------*/
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__    
extern MMI_RET srv_clog_phb_sync_evt_hdlr(mmi_event_struct *evt);
#endif

/*---------------------- SIM Sync Operation ----------------------------------*/
#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
extern void srv_clog_sim_init(void);
extern S32 srv_clog_sim_sync_hdlr(srv_clog_cntx_struct *cntx, srv_clog_job_struct *job);
extern S32 srv_clog_sim_sat_refresh_hdlr(mmi_sim_enum sim_id, U16 ef_file_idx);
extern MMI_RET srv_clog_sim_shutdown_evt_hdlr(mmi_event_struct *evt);
extern mmi_frm_proc_result_enum srv_clog_sim_shutdown_hdlr(void *arg, const mmi_frm_proc_id_info_struct id_info);

#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

/*---------------------- PS Adapter ------------------------------------------*/
extern U8 srv_clog_clt_idx2l4c(srv_clog_clt_idx_enum clt_idx);  //ATcmd
extern U8 srv_clog_clt_bit2l4c(srv_clog_clt_enum clt_type); //SimSync

extern U32 srv_clog_ct_idx2l4c(srv_clog_call_type_idx_enum ct_idx);  //ATcmd & SimSync
extern srv_clog_call_type_idx_enum srv_clog_ct_l4c2idx(U32 l4_ct); //ATcmd & SimSync

extern srv_clog_clt_idx_enum srv_clog_clt_l4c2idx(U8 l4c_type); //ATcmd
extern srv_clog_clt_enum srv_clog_clt_l4c2bit(U8 l4c_type); //Non-Link
extern void srv_clog_ret_clog2l4c(srv_clog_ret_enum ret, l4c_result_struct *l4ret); //ATcmd
extern srv_clog_ret_enum srv_clog_ret_l4c2clog(const l4c_result_struct *l4ret); //Non-Link
extern void srv_clog_log_si2l4c(const srv_clog_si_struct *si_log, l4c_phb_ln_entry_struct *ln); //ATcmd & SimSync
extern void srv_clog_log_l4c2si(
                const l4c_phb_ln_entry_struct *ln,
                mmi_sim_enum sim_id,
                srv_clog_clt_enum clt,
                SRV_CLOG_ID new_log_id,
                srv_clog_si_struct *si_log);  //Non-Link
extern void srv_clog_log_l4c2cmn(
                const l4c_phb_ln_entry_struct *ln,
                mmi_sim_enum sim_id,
                srv_clog_clt_enum clt_type,
                srv_clog_log_struct *cmn_log); //ATcmd & SimSync

extern S32 srv_clog_is_ln_invalid(const l4c_phb_ln_entry_struct *ln); //SimSync

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*---------------------- main Operation -------------------------------------*/
extern void *srv_clog_comp_new_para(U32 para_size);
extern void srv_clog_add_log_notify(SRV_CLOG_ID log_id, srv_clog_add_log_req_struct* req_data, SRV_CLOG_BASE_CB func_cb);
extern S32 srv_clog_add_log_hdlr(SRV_CLOG_ID log_id, srv_clog_add_log_req_struct *req_data, SRV_CLOG_BASE_CB func_cb);
extern S32 srv_clog_update_log_hdlr(SRV_CLOG_ID log_id, srv_clog_update_log_req_struct *req_data, SRV_CLOG_BASE_CB func_cb);
extern S32 srv_clog_update_all_logs_hdlr(srv_clog_update_all_logs_req_struct *req_data, SRV_CLOG_BASE_CB func_cb);
extern S32 srv_clog_delete_log_by_id_hdlr(SRV_CLOG_ID log_id, SRV_CLOG_BASE_CB func_cb);
#ifndef __MMI_CONTACT_SLIM__
extern S32 srv_clog_search_list_log_ids_hdlr(srv_clog_search_list_log_ids_req_struct* req_data, SRV_CLOG_BASE_CB func_cb);
#endif

/*---------------------- Sort Info Operation ----------------------------------*/
extern S32 srv_clog_si_log_cmn2si(srv_clog_log_struct *cmn_log, srv_clog_si_struct *sort_info);
extern S32 srv_clog_si_log_si2cmn(srv_clog_si_struct *sort_info, U32 fields, srv_clog_log_struct *log);
extern S32 srv_clog_si_log_update_cmn_info(srv_clog_si_struct *si_log, srv_clog_update_all_logs_req_struct *req_data);

/*---------------------- Utils Operation -------------------------------------*/
extern U32 srv_clog_wcs_n_to_BCD(CHAR *pOutBuffer, WCHAR *pInBuffer, U32 len);

/*---------------------- Store Operation -------------------------------------*/
extern srv_clog_ret_enum srv_clog_st_write_logs(U32 starts, U32 ends, srv_clog_si_struct** si_log);

/*---------------------- PHB Sync Operation ----------------------------------*/
#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__    
extern MMI_RET srv_clog_phb_sync_evt_hdlr(mmi_event_struct *evt);
#endif

/*---------------------- SIM Sync Operation ----------------------------------*/

/*---------------------- PS Adapter ------------------------------------------*/
extern srv_clog_call_type_idx_enum srv_clog_ct_l4c2idx(U32 l4_ct); //ATcmd & SimSync
extern srv_clog_clt_idx_enum srv_clog_clt_l4c2idx(U8 l4c_type); //ATcmd
extern srv_clog_clt_enum srv_clog_clt_l4c2bit(U8 l4c_type); //Non-Link
extern srv_clog_ret_enum srv_clog_ret_l4c2clog(const l4c_result_struct *l4ret); //Non-Link
extern void srv_clog_ret_clog2l4c(srv_clog_ret_enum ret, l4c_result_struct *l4ret); //ATcmd
extern void srv_clog_log_l4c2cmn(const l4c_phb_ln_entry_struct *ln, mmi_sim_enum sim_id, srv_clog_clt_enum clt_type, srv_clog_log_struct *cmn_log); //ATcmd & SimSync
extern S32 srv_clog_is_ln_invalid(const l4c_phb_ln_entry_struct *ln); //SimSync
extern U32 srv_clog_ct_idx2l4c(srv_clog_call_type_idx_enum ct_idx);  //ATcmd & SimSync
extern U8 srv_clog_clt_idx2l4c(srv_clog_clt_idx_enum clt_idx);  //ATcmd
extern U8 srv_clog_clt_bit2l4c(srv_clog_clt_enum clt_type); //SimSync

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
/*---------------------- Call Time -------------------------------------------*/
#ifdef __MMI_CLOG_CALL_TIME__
extern S32 srv_clog_ctime_update_data(mmi_sim_enum sim_id, srv_clog_call_type_enum call_type,  
                                      srv_clog_clt_enum clt_type, U32 last_time);
#endif


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif 


#endif /* SRV_CALL_LOG_PROT_H */ 

