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
 *  CallLogAdpPbapc.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_CALL_LOG_ADP_PBAPC_H
#define MMI_CALL_LOG_ADP_PBAPC_H

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"

#if defined(__MMI_BT_PBAP_CLIENT__)

#include "PhbpbapSrvGprot.h"
#include "app_datetime.h"
#include "vcard_lib.h"
#include "Custom_calllog.h"
#define __MMI_CLOG_PBAPC_ADM_SUPPORT__
//#define __MMI_CLOG_PBAPC_CLOG_TYPE_DETAIL_SHOW__

#define MMI_CLOG_PBAPC_TIME_DETAIL_MAX_NUM  1
#define MMI_CLOG_PBAPC_NAME_MAX_LEN         ((MAX_PHB_NAME_LENGTH + 1) / 2)
#define MMI_CLOG_PBAPC_CID_MAX_LEN          40

#define MMI_CLOG_PBAPC_TRC_INFO             TRACE_GROUP_9

typedef void (*mmi_clog_pbap_async_op_callback_type)(S32 result);

typedef enum
{
    MMI_CLOG_PBAPC_CLT_DEFAULT = 0x00,                /* Default value, just discard it if act as a filter */
    MMI_CLOG_PBAPC_CLT_DIALED = 0x01,                 /* Dialed call log type */
    MMI_CLOG_PBAPC_CLT_MISSED = 0x02,                 /* Missed call log type */
    MMI_CLOG_PBAPC_CLT_RECVED = 0x04,                 /* Received call log type */
    MMI_CLOG_PBAPC_CLT_ALL = 0x0F,                    /* All call log type */
    MMI_CLOG_PBAPC_CLT_MAX_ITEM                       /* Max item */
} mmi_clog_pbapc_clt_enum;

typedef enum
{
    MMI_CLOG_PBAPC_OP_TYPE_LT_LIST,
    MMI_CLOG_PBAPC_OP_TYPE_LIST_VIEWER, 
    MMI_CLOG_PBAPC_OP_TYPE_MAX_ITEM
} mmi_clog_pbapc_op_type_enum;

typedef struct
{
    MMI_BOOL is_canceled;
    MMI_BOOL is_stoped;
    srv_phb_pbap_storage_enum path;
    MMI_BOOL is_read;
    SRV_PHB_PBAPC_HANDLE phapc_op_handle;
    mmi_clog_pbap_async_op_callback_type cb;
#ifdef __MULTI_VCARD_SUPPORT__
    VP_HANDLE p_handle;
#endif /*__MULTI_VCARD_SUPPORT__*/
    U8 flag;
    MMI_ID parent_id;
    MMI_MENU_ID menu_id;
    U32 is_from_close_pop;

} mmi_clog_pbapc_cntx_struct;
 

typedef struct
{
    MMI_ID parent_gid;
    MMI_ID self_scr_id;
    mmi_clog_pbapc_op_type_enum type;
    srv_phb_pbap_storage_enum sel_lt_storage;
    MMI_MENU_ID sel_menu_id;
} mmi_clog_pbapc_processing_inst_struct;

 typedef struct
{
     U8 index;
     mmi_id cui_id;
     U8 is_parse;
     MMI_BOOL only_update[SRV_PBAPC_LINK_NUM];
     U32 flag[SRV_PBAPC_LINK_NUM];
     S32 ret;
     srv_bt_cm_bt_addr addr[SRV_PBAPC_LINK_NUM];

}mmi_clog_pbapc_ex_inst_struct;

 
typedef struct
{
    mmi_clog_pbapc_clt_enum call_type;
    WCHAR name[MMI_CLOG_PBAPC_NAME_MAX_LEN + 1];      /* Name */
    U8 cid[MMI_CLOG_PBAPC_CID_MAX_LEN + 1];        /* Caller id (CID), phone number or voip address, in ASCII encode  */
    applib_time_struct timestamp[MMI_CLOG_PBAPC_TIME_DETAIL_MAX_NUM]; /* Timestamp, it is order sequence, and timestamp[0] is the lastest */
} mmi_clog_pbap_info_struct;

typedef struct
{
#ifdef __MMI_CLOG_PBAPC_ADM_SUPPORT__
    mmi_clog_pbap_info_struct *clog_info;
#else /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/
    mmi_clog_pbap_info_struct clog_info;
#endif /*__MMI_CLOG_PBAPC_ADM_SUPPORT__*/
} mmi_clog_pbap_clog_info_cache_struct;

typedef struct
{
    MMI_BOOL is_need_save_idx;
    mmi_clog_pbap_info_struct *call_info;
    mmi_clog_pbap_info_struct save_info;
}mmi_clog_reslove_hlt_item_struct;

extern void mmi_clog_pbapc_init(void);
extern void mmi_clog_pbapc_deinit(void);
extern void mmi_clog_pbapc_read_folder(srv_phb_pbap_storage_enum path);
extern void mmi_clog_pbapc_free_op_handle(void);
extern mmi_clog_pbapc_cntx_struct* mmi_clog_get_pbapc_cntx();

extern mmi_clog_pbapc_ex_inst_struct* mmi_clog_get_pbapc_cntx_ex();

extern MMI_BOOL mmi_clog_pbapc_is_btsc_active();

#endif /* __MMI_BT_PBAP_CLIENT__ */ 
#endif /* MMI_CALL_LOG_ADP_PBAPC_H */ 
