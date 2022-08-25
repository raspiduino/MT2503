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
 *  IdleToolbar.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is the internal header file of the OP12 Toolbar.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _MMI_IDLE_TOOLBAR_H
#define _MMI_IDLE_TOOLBAR_H

#include "MMI_features.h"

#ifdef __MMI_OP12_TOOLBAR__

#include "IdleToolbarGprot.h"


/**********************************************************************
 * Default constants definition
 **********************************************************************/

#define MMI_TB_UT                       1
#define MMI_TB_STR_LEN                  (MAX_SUB_MENU_SIZE / ENCODING_LENGTH)
#define MMI_TB_URL_LEN                  128
#define MMI_TB_ENTRY_GUARD_TOV          2000

/* Max number of entries of the live module */
#define MMI_TB_MAX_LIVE_ENTRY_NUM       8

/* Max number of events of a certain kind in the messages module */
#define MMI_TB_MAX_VOICEMAIL_ENTRY_NUM  2
#define MMI_TB_MAX_EMAIL_ENTRY_NUM      1
#define MMI_TB_MAX_IM_ENTRY_NUM         1
#define MMI_TB_MAX_PUSH_ENTRY_NUM       4
#define MMI_TB_MAX_CB_ENTRY_NUM         1

/* Max number of entries of the messages module */
#define MMI_TB_MAX_MSG_ENTRY_NUM        19

/* Max number of entries of the profiles module */
#define MMI_TB_MAX_PROF_ENTRY_NUM       2

/* Max number of shortcuts in the shortcuts module */
#define MMI_TB_MAX_SHCT_ENTRY_NUM       40

/* Message iterator option flag: */
#define MMI_ITER_MSG_SKIP_UM            0x01

/* Toolbar option flag: */
#define MMI_TB_NULL                     0x0000
#define MMI_TB_QUERYING                 0x0001
#define MMI_TB_HISTORY_DISCARDED        0x0002
#define MMI_TB_HISTORY_FOR_REDRAW       0x0004
#define MMI_TB_ENTRY_WITHOUT_QUERY      0x0008
#define MMI_TB_OPENED                   0x0010


/**********************************************************************
 * Macro definition
 **********************************************************************/

#define MMI_TB_GET_SIZE(x)                  (sizeof(x) / sizeof(x[0]))
#define MMI_TB_ASSERT(x)                    ASSERT(x)
#define MMI_TB_EASSERT(x, y1, y2, y3)       EXT_ASSERT(x, y1, y2, y3)

#ifdef MMI_TB_UT /* __PRODUCTION_RELEASE__ */
#define MMI_TB_ASSERT_DBG(x)                ASSERT(x)
#define MMI_TB_EASSERT_DBG(x, y1, y2, y3)   EXT_ASSERT(x, y1, y2, y3)
#else
#define MMI_TB_ASSERT_DBG(x)  
#define MMI_TB_EASSERT_DBG(x, y1, y2, y3)   
#endif


/**********************************************************************
 * Enum definitions
 **********************************************************************/

/* Module type enum */
typedef enum
{
    MMI_TB_MOD_LIVE,
    MMI_TB_MOD_MSG,
    MMI_TB_MOD_MISSED_CALLS,
    MMI_TB_MOD_PROFILE,
    MMI_TB_MOD_SHORTCUTS,
    MMI_TB_MOD_NUM
} mmi_tb_module_type;


/**********************************************************************
 * Structure definitions
 **********************************************************************/

/* Structure for the application registration. */
typedef struct
{
    S32                 type;
    mmi_tb_query_func_t query;
} mmi_tb_ctrl_tbl_struct;

/* Menu entry: messages and missed call modules */
typedef struct
{
    S8                  subject[MMI_TB_STR_LEN * ENCODING_LENGTH];
    U16                 icon;
    MMI_BOOL            is_time_present;
    MYTIME              time;
    void               *user_data;
} mmi_tb_event_struct;

/* Message iterator structure */
typedef struct
{
    mmi_tb_evnt_enum     type;
    mmi_tb_event_struct *evnt;
} mmi_tb_iter_result_struct;

typedef struct
{
    mmi_tb_evnt_enum           type;
    U8                         idx;
    U8                         flag;
    U8                         n_um;
    mmi_tb_iter_result_struct *um;
} mmi_tb_iter_struct;

/* History structure */
typedef struct
{ 
    /* 
     * module:
     *   the hilighted module
     *
     * msg_evnt:
     *   copy of the highlighted dynamic item in message module
     *
     * call_evnt:
     *   copy of the highlighted dynamic item in call module
     */
    mmi_tb_module_type  module;
    S32                 index[MMI_TB_MOD_NUM];
    U16                 shct_id;
    S32                 msg_type;
    mmi_tb_event_struct msg_evnt;
    mmi_tb_event_struct call_evnt;
} mmi_tb_hist_struct;

/* Menu entry: OP12 live! */
typedef struct
{
    U16  str_id;
    U16  icon_id;
    S8  *url;
} mmi_tb_link_struct;

/* Live module context structure */
typedef struct
{
    S32                 num;
    mmi_tb_link_struct *entry[MMI_TB_MAX_LIVE_ENTRY_NUM];
} mmi_tb_live_cntx_struct;

/* Messages module context structure */
typedef struct
{
    S32                     total_num[MMI_TB_EVNT_NUM];
    S32                     num[MMI_TB_EVNT_NUM];
    mmi_tb_evnt_cbf_t       single_hdlr[MMI_TB_EVNT_NUM];
    mmi_tb_multi_evnt_cbf_t multi_hdlr[MMI_TB_EVNT_NUM];
    mmi_tb_event_struct     sms[MMI_TB_MAX_NEW_MESSAGE_NUM];
    mmi_tb_event_struct     mms[MMI_TB_MAX_NEW_MESSAGE_NUM];
    mmi_tb_event_struct     voicemail[MMI_TB_MAX_VOICEMAIL_ENTRY_NUM];
    mmi_tb_event_struct     email[MMI_TB_MAX_EMAIL_ENTRY_NUM];
    mmi_tb_event_struct     im[MMI_TB_MAX_IM_ENTRY_NUM];
    mmi_tb_event_struct     push[MMI_TB_MAX_PUSH_ENTRY_NUM];
    mmi_tb_event_struct     cb[MMI_TB_MAX_CB_ENTRY_NUM];
    mmi_tb_event_struct     call[MMI_TB_MAX_NEW_MISSED_CALL_NUM];
} mmi_tb_event_cntx_struct;

/* Toolbar NVRAM record structure */
#define MMI_TB_NVRAM_RECORD_STRUCT                                  \
            U8              enable;                                 \
            U8              mod_state[MMI_TB_MOD_NUM]

typedef struct
{
    MMI_TB_NVRAM_RECORD_STRUCT;
} mmi_tb_nvram_record_struct;

/* Toolbar context structure */
typedef struct
{    
    MMI_TB_NVRAM_RECORD_STRUCT;
    mmi_tb_live_cntx_struct    live;
    mmi_tb_event_cntx_struct   event; 
    mmi_tb_hist_struct         hist;
    U8   mod_state_tmp[MMI_TB_MOD_NUM];
    U8   index;
    U32  tb_state;
    U32  flag;
    U8  *gui_buffer;
} mmi_tb_context_struct;


/**********************************************************************
 * External Interfaces
 **********************************************************************/

extern const mmi_tb_ctrl_tbl_struct 
mmi_tb_evnt_query_tbl[];

extern void
mmi_tb_entry_toolbar(void);

extern void 
mmi_tb_hilight_switch_on_off(void);

extern void 
mmi_tb_hilight_modify_modules(void);

extern void 
mmi_tb_hilight_modify_shortcuts(void);

extern void 
mmi_tb_discard_history(void);

extern void
mmi_tb_pre_fetch_history(void);

extern void 
mmi_tb_redraw_toolbar(void);

extern void 
mmi_tb_open_toolbar(void);

extern void 
mmi_tb_close_toolbar(void);

#endif /* __MMI_OP12_TOOLBAR__ */
#endif /* _MMI_IDLE_TOOLBAR_H */

