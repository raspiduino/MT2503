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
 *  CallLogSrvUtils.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_CALL_LOG_UTILS_H
#define SRV_CALL_LOG_UTILS_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"

#include "MMIDataType.h"
#include "mmi_frm_queue_gprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvConfig.h"


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_NEW_ILM_DATA(type)              ((type*)OslConstructDataPtr(sizeof(type)))

/*---------------------- Memory Manager --------------------------------------*/

#define SRV_CLOG_MALLOC                         srv_clog_malloc
#define SRV_CLOG_MFREE                          srv_clog_mfree
//#define SRV_CLOG_MFREE(type, p)                 srv_clog_auto_mfree(p)

#define SRV_CLOG_TALLOC(mem_type, data_type)    ((data_type*)(SRV_CLOG_MALLOC((mem_type), sizeof(data_type))))
#define SRV_CLOG_ZFREE(mem_type, p)             do {if (p){ SRV_CLOG_MFREE((mem_type), (p)); (p) = NULL; } }while(0)


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*---------------------- Memory Manager --------------------------------------*/
typedef enum
{
    SRV_CLOG_MEM_TYPE_SYS,
    SRV_CLOG_MEM_TYPE_CTRL_BUF,
    SRV_CLOG_MEM_TYPE_TEMP,
#if (SRV_CLOG_MEM_POOL_DYNC_SIZE > SRV_CLOG_MEM_POOL_MIN_DYNC_SIZE)
    SRV_CLOG_MEM_TYPE_DYNC,
#endif
    SRV_CLOG_MEM_TYPE_MAX_ITEM
} srv_clog_mem_type_enum;

typedef enum
{
    SRV_CLOG_DUMP_TYPE_STL = 0x0001,
    SRV_CLOG_DUMP_TYPE_ST = 0x0002,
    SRV_CLOG_DUMP_TYPE_JB = 0x0004,
    SRV_CLOG_DUMP_TYPE_SI = 0x0008,
    SRV_CLOG_DUMP_TYPE_IDX = 0x0010,
    SRV_CLOG_DUMP_TYPE_IDX_NUM = 0x0020,
    SRV_CLOG_DUMP_TYPE_SI_IDX = 0x0018,
    SRV_CLOG_DUMP_TYPE_COMP = 0x003F,
    SRV_CLOG_DUMP_TYPE_CNTX = 0x0040,

    SRV_CLOG_DUMP_TYPE_PHB_SYNC = 0x0100,
    SRV_CLOG_DUMP_TYPE_PHB_SYNC_EVT = 0x0200,

    SRV_CLOG_DUMP_TYPE_SIM_SYNC = 0x0100,
    SRV_CLOG_DUMP_TYPE_SIM_SYNC_REQ_DATA = 0x0200,
    SRV_CLOG_DUMP_TYPE_SIM_SYNC_SYNC_ID = 0x0400,
    SRV_CLOG_DUMP_TYPE_SIM_SYNC_FSM = 0x0800,

    SRV_CLOG_DUMP_TYPE_ALL = 0xFFFF,

    SRV_CLOG_DUMM_TYPE_MAX_ITEM
} srv_clog_dump_type_enum;

#ifdef __SRV_CLOG_DEBUG__

typedef enum
{
    SRV_CLOG_DEBUG_MODE_NONE = 0x00,
    SRV_CLOG_DEBUG_MODE_PRINT = 0x01,
    SRV_CLOG_DEBUG_MODE_CNTX_DUMP = 0x02,
    SRV_CLOG_DEBUG_MODE_PHB_PARA_DUMP = 0x04,
    SRV_CLOG_DEBUG_MODE_SIM_SYNC_DUMP = 0x08,
    SRV_CLOG_DEBUG_MODE_ALL = 0xFF,
    SRV_CLOG_DEBUG_MODE_MAX_ITEM
} srv_clog_debug_mod_enum;
#endif /* __SRV_CLOG_DEBUG__ */ 

/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef S32(*SRV_CLOG_COMPARE_FUNC) (void *src, void *dst);

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

typedef struct
{
    U32 bit_styles[SRV_CLOG_STL_MAX_BIT_SLOT_NUM];
} srv_clog_stl_mgr_struct;

typedef struct
{
    LOCAL_PARA_HDR
    U32 type;
    U32 flags;
    U32 debug_mode;
} srv_clog_inject_struct;

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

#ifdef __SRV_CLOG_DEBUG__

extern U32 srv_clog_get_debug_mode(void);
extern void srv_clog_print(CHAR *format, ...);

#ifdef __SRV_CLOG_DUMP__

extern S32 srv_clog_is_ascii_string(const WCHAR *str);
extern void srv_clog_sel_dump(U32 type);
extern void srv_clog_dump(void);
extern void srv_clog_comp_dump(void);
extern void srv_clog_is_dump(void);
extern void srv_clog_stl_dump(void);
extern void srv_clog_st_dump(void);
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
extern void srv_clog_job_dump(void);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
extern void srv_clog_si_dump(void);
extern void srv_clog_si_dump_log_by_idx(U32 index);
extern void srv_clog_si_dump_log(U32 index, void *log_data);
extern void srv_clog_idx_dump(void);
extern void srv_clog_idx_dump_info(U32 info_type);
extern void srv_clog_idx_dump_num(void);

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__
extern void srv_clog_phb_dump(void);
extern void srv_clog_phb_dump_num(U32 index);
extern void srv_clog_phb_dump_evt(void);
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
extern void srv_clog_sim_dump(void);
extern void srv_clog_sim_dump_req_data(void);
extern void srv_clog_sim_dump_sync_id(void);
extern void srv_clog_sim_dump_fsm(void);
extern void srv_clog_sim_dump_fsm_by_idx(U32 sim_idx);
#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

#endif /* __SRV_CLOG_DUMP__ */ 
#endif /* __SRV_CLOG_DEBUG__ */ 

/*---------------------- Memory Manager --------------------------------------*/
extern void srv_clog_mem_init(void);
extern void *srv_clog_malloc(U32 mem_type, U32 size);
extern void srv_clog_mfree(U32 mem_type, void *p);
//extern void srv_clog_auto_mfree(void *p);

/*---------------------- ILM Process -----------------------------------------*/
extern void srv_clog_send_l4c_ilm(mmi_sim_enum sim_id_grp, U16 msg_id, void *local_data);

/*---------------------- Property & Identity Operation -----------------------*/
extern srv_clog_log_identity_struct *srv_clog_pi_revise_i(srv_clog_log_identity_struct *idt, S32 is_filter);
extern void srv_clog_pi_reset_i(srv_clog_log_identity_struct *idt);
extern void srv_clog_pi_cp_i(srv_clog_log_identity_struct *src_idt, srv_clog_log_identity_struct *dst_idt);
extern S32 srv_clog_pi_is_i_invalid(const srv_clog_log_identity_struct *idt);
extern S32 srv_clog_pi_is_ii_sub(srv_clog_log_identity_struct *src, srv_clog_log_identity_struct *dst);
extern S32 srv_clog_pi_is_ii_equal(srv_clog_log_identity_struct *src, srv_clog_log_identity_struct *dst);
extern S32 srv_clog_pi_merge_ii(srv_clog_log_identity_struct *src_idt, srv_clog_log_identity_struct *dst_idt, srv_clog_log_identity_struct *out_idt);
extern U32 srv_clog_pi_get_clt_max_size(mmi_sim_enum sim_id, srv_clog_clt_enum clt_id);

#ifdef __MMI_CLOG_SLIM_FOR_MT6261__

extern void srv_clog_pi_i2p(srv_clog_log_identity_struct *identity, U8 *types);
extern void srv_clog_pi_p2idx(U8 types, U32 *cate_idx, U32 *sim_idx, U32 *lt_idx, U32 *st_idx);
extern void srv_clog_pi_p2i(U8 types, srv_clog_log_identity_struct *identity);
extern S32 srv_clog_pi_is_ip_sub(srv_clog_log_identity_struct *idt, U8 types);
extern U32 srv_clog_pi_get_num_limit_by_p(U32 num_style, U8 types, srv_clog_log_identity_struct *type_idt);

#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */

extern void srv_clog_pi_p2idx(U32 props, U32 *cate_idx, U32 *sim_idx, U32 *lt_idx, U32 *st_idx);
extern void srv_clog_pi_p2i(U32 props, srv_clog_log_identity_struct *identity);
extern void srv_clog_pi_i2p(srv_clog_log_identity_struct *identity, U32 *props);
extern S32 srv_clog_pi_is_ip_sub(srv_clog_log_identity_struct *idt, U32 props);
extern U32 srv_clog_pi_get_num_limit_by_p(U32 num_style, U32 props, srv_clog_log_identity_struct *type_idt);
extern S32 srv_clog_pi_is_p_support(U32 props);

#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*---------------------- Misc ------------------------------------------------*/
extern MMI_BOOL srv_clog_is_single_sim_replaced(mmi_sim_enum sim_id);
extern S32 srv_clog_comp_asc_cid(CHAR *cid1, CHAR *cid2);
extern U32 srv_clog_sim_id_clog2ps(mmi_sim_enum sim_id);
extern U32 srv_clog_ib_bit2idx(U32 bit);


#ifdef __cplusplus
}
#endif 


#endif /* SRV_CALL_LOG_UTILS_H */ 

