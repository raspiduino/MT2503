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
 *  EngineerModeIperf.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode IPERF function prototype declaration.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EM_IPERF_H
#define MMI_EM_IPERF_H
#include "mmi_features.h"
#ifdef __MMI_EM_IPERF__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "InlineCuiGprot.h"
#include "MMIDataType.h"
#include "iperf_mmi_enums.h"
#include "EngineerModeDef.h"
#include "kal_general_types.h"
#include "DataAccountGProt.h"
#include "DtcntSrvGprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    //EF_IPERF_INLINE_ITEM_DATA_ACCOUNT_CAP = CUI_INLINE_ITEM_ID_BASE,
    //EF_IPERF_INLINE_ITEM_DATA_ACCOUNT,
    //EF_IPERF_INLINE_ITEM_CLISRV_CAP
    EF_IPERF_INLINE_ITEM_CLISRV = CUI_INLINE_ITEM_ID_BASE,
    EF_IPERF_INLINE_ITEM_FADDR_CAP,
    EF_IPERF_INLINE_ITEM_FADDR,
    EF_IPERF_INLINE_ITEM_LEN_CAP,
    EF_IPERF_INLINE_ITEM_LEN,
    EF_IPERF_INLINE_ITEM_PORT_CAP,
    EF_IPERF_INLINE_ITEM_PORT,
    EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER_CAP,
    EF_IPERF_INLINE_ITEM_WINDOW_OR_BUFFER,
    EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH_CAP,
    EF_IPERF_INLINE_ITEM_MSS_OR_BANDWIDTH,
    //EF_IPERF_INLINE_ITEM_DUAL_TEST_CAP,
    EF_IPERF_INLINE_ITEM_NUM_CAP,
    EF_IPERF_INLINE_ITEM_NUM,
    EF_IPERF_INLINE_ITEM_TIME_CAP,
    EF_IPERF_INLINE_ITEM_TIME,
    EF_IPERF_INLINE_ITEM_DUAL_TEST,
    //EF_IPERF_INLINE_ITEM_TOS_CAP,
    //EF_IPERF_INLINE_ITEM_TOS,
    //EF_IPERF_INLINE_ITEM_RW_FILE_CAP,
    //EF_IPERF_INLINE_ITEM_RW_FILE,
} em_iperf_inline_item_enum;

typedef struct
{
    MMI_STR_ID      client_server_list[2];     /* Inline selection list for "Client" and "Server" */
    MMI_STR_ID      rw_file_list[2];           /* Inline selection list for "Client" and "Server" */
    MMI_STR_ID      tos_list[4];               /* Inline selection list for "tos type" */
    MMI_STR_ID      dualtest[2];               /* Inline selection list for "dual test type" */
    iperf_prot      prot;                       /* udp or tcp */
} em_iperf_misc_struct;

typedef struct
{
    U8       report_buff[MAX_REPORT_BUFF];           /* report buffer for ascii*/
    WCHAR    report_UI_buffer[MAX_REPORT_BUFF*2];    /* report buffer for unicode*/
} em_iperf_report_struct;

typedef struct
{
    S32     client_server;                                  /* client/server mode */
    S32     dualtest;                                       /* dualtest mode */
    U8      faddr_ip[4];                                    /* faddr */
    S32     len;                                            /* length of send buf, recv buf */
    U32     port;                                           /* server port */
    S32     window;                                         /* TCP window size (socket buffer size) */
    S32     mss;                                            /* tcp mss */
    S32     buffer;                                         /*  */
    U32     bandwidth;                                      /* udp bandwidth (bits/sec), UDP only*/
    U32     num;                                            /* number of bytes to transmit */
    U32     time;                                           /* time in seconds to transmit for, default=10 */
    S32     tos;                                            /* type-of-service */
    S32     rw_file;                                        /* read/wirte from/to file(flash) */
} em_iperf_edit_struct;

typedef struct
{
    em_iperf_edit_struct    iperf_edit_tcp;
    em_iperf_edit_struct    iperf_edit_udp;
    U32                     account_id[MMI_MAX_SIM_NUM];
} em_iperf_restore_struct;

typedef struct
{
    em_iperf_misc_struct    *iperf_misc;        /* misc data for editing setting */
    em_iperf_edit_struct    *iperf_edit_tcp;    /* temp data for editing tcp setting */
    em_iperf_edit_struct    *iperf_edit_udp;    /* temp data for editing udp setting */
    em_iperf_report_struct  *iperf_report;      /* data for iperf reporting */  
    MMI_BOOL                is_running;
    MMI_ID                  cui_menu_id;
    MMI_ID                  progressing_alert_id;
    U32                     account_id[MMI_MAX_SIM_NUM];         /* Network account ID */    
} em_iperf_context_struct;

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
extern void mmi_em_iperf_menu_entry_event_hdlr(cui_menu_event_struct *event);
extern mmi_ret ef_iperf_setting_scr_group_proc(mmi_event_struct *evt);
extern void PreEntryEmIperf(void);
extern void PreEntryEmIperfTcp(void);
extern void PreEntryEmIperfUdp(void);
extern void EntryEmIperf(void);
extern void EntryEmIperfSetting(void);
extern void EntryEmIperfReport(void);
extern void em_iperf_progress_abort(void);
extern void em_iperf_setting_data_acct(void);
extern void em_iperf_dt_callback(U8 sim_index, U32 account_id);
extern void em_iperf_run(void);
extern void em_iperf_check(void);
extern void em_iperf_disp_err_popup(MMI_STR_ID str_id);
extern void em_iperf_disp_fail_popup(MMI_STR_ID str_id);
extern void em_iperf_save(void);
extern void em_iperf_send_req(void);
extern void em_iperf_read_file(void);
extern void em_iperf_load_default(void);
extern void em_iperf_run_cnf_hf(void* msg);
extern void em_iperf_report_ind_hf(void* msg);
extern void em_iperf_report_back(void);
mmi_ret em_iperf_progress_confirm_cb(mmi_event_struct *evt);
#endif /* __MMI_EM_IPERF__ */
#endif /* MMI_EM_IPERF_H */ 
