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
 *  EngineerModeNfc.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode NFC related items, 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_EM_NFC_SUPPORT__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "InlineCuiGprot.h"
#include "MenuCuiGprot.h"
#include "FSEditorCuiGprot.h"
#include "Wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "MMI_common_app_trc.h"
#include "EngineerModeConfig.h"
#include "EngineerModeDevice.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeUtil.h"
#include "mtk_nfc_ext_msg.h"

#define MMI_EM_NFC_TRACE(num, p1, p2,p3,p4,p5)      MMI_EM_TRACE((MMI_EM_TRC_INFO,TRC_MMI_EM_DEVICE_NFC_PARAMS,num, p1, p2, p3, p4,p5))
#define MMI_EM_NFC_TRACE_0(num)                     MMI_EM_NFC_TRACE(num, 0, 0, 0, 0, 0)
#define MMI_EM_NFC_TRACE_1(num, p1)                 MMI_EM_NFC_TRACE(num, p1, 0, 0, 0, 0)
#define MMI_EM_NFC_TRACE_2(num, p1,p2)              MMI_EM_NFC_TRACE(num, p1, p2, 0, 0, 0)
#define MMI_EM_NFC_TRACE_3(num, p1,p2, p3)          MMI_EM_NFC_TRACE(num, p1, p2, p3, 0, 0)
#define MMI_EM_NFC_TRACE_4(num, p1,p2, p3, p4)      MMI_EM_NFC_TRACE(num, p1, p2, p3, p4, 0)
#define MMI_EM_NFC_TRACE_5                          MMI_EM_NFC_TRACE

typedef enum
{
    MMI_EM_NFC_TRC_NUM_REQ = 10000,
    MMI_EM_NFC_TRC_NUM_RSP,
    MMI_EM_NFC_TRC_NUM_RSP_NOT_MATCH,
    MMI_EM_NFC_TRC_NUM_SETTING_QUERY,
    MMI_EM_NFC_TRC_NUM_SETTING_REQ,
    MMI_EM_NFC_TRC_NUM_SETTING_RSP,

    MMI_EM_NFC_TRC_NUM_DIS_NOTIFI_REQ,
    MMI_EM_NFC_TRC_NUM_DIS_NOTIFI_RSP,

    MMI_EM_NFC_TRC_NUM_TAG_DETACTED_RSP,
    MMI_EM_NFC_TRC_NUM_TAG_DET_NDEF_READ_RSP,
    MMI_EM_NFC_TRC_NUM_TAG_DET_NDEF_WRITE_RSP,
    MMI_EM_NFC_TRC_NUM_TAG_DET_DISCONNECT_RSP,
    MMI_EM_NFC_TRC_NUM_P2P_DETECTED_RSP,

    MMI_EM_NFC_TRC_NUM_READER_MODE_REQ,
    MMI_EM_NFC_TRC_NUM_READER_MODE_RSP,
    
    MMI_EM_NFC_TRC_NUM_CARD_EMU_MODE_REQ,
    MMI_EM_NFC_TRC_NUM_CARD_EMU_MODE_RSP,

    MMI_EM_NFC_TRC_NUM_P2P_MODE_REQ,
    MMI_EM_NFC_TRC_NUM_P2P_MODE_RSP,

    MMI_EM_NFC_TRC_NUM_TX_ON_REQ,
    MMI_EM_NFC_TRC_NUM_TX_ON_RSP,
    MMI_EM_NFC_TRC_NUM_TX_ON_WITH_ASK_REQ,
    MMI_EM_NFC_TRC_NUM_TX_ON_WITH_ASK_RSP,
    MMI_EM_NFC_TRC_NUM_TX_ON_WO_ASK_REQ,
    MMI_EM_NFC_TRC_NUM_TX_ON_WO_ASK_RSP,

    MMI_EM_NFC_TRC_NUM_ANTENNA_TEST_REQ,
    MMI_EM_NFC_TRC_NUM_ANTENNA_TEST_RSP,
    
    MMI_EM_NFC_TRC_NUM_MAX
}MMI_EM_NFC_TRC_NUM_enum;


//#define __MMI_EM_NFC_TEST__
  
/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define MMI_EM_NFC_SETTING_GET_CAP_VALUE    (1)
#define MMI_EM_NFC_SETTING_RSP_BUF_LEN      (300)
#define MMI_EM_NFC_REG_NOTIF_BUF_LEN        (200)
#define MMI_EM_NFC_TAG_DET_BUF_LEN          (200)
#define MMI_EM_NFC_REG_NOTIF_BITMAP_NUM     (8)
#define MMI_EM_NFC_SE_BITMAP_NUM            (6)
#define MMI_EM_NFC_SE_INLINE_CAPTION_LEN    (20)
#define MMI_EM_NFC_DIS_NOTIF_BITMAP_NUM     (8)


#define MMI_EM_NFC_READER_MODE_PROTOCOLS_NUM        (5)
#define MMI_EM_NFC_P2P_MODE_PROTOCOLS_NUM           (3)

#define MMI_EM_NFC_NDEF_READ_TEXT_LEN       ((NDEF_DATA_LEN + 150))
#define MMI_EM_NFC_P2P_INFO_TEXT_LEN        (100)

#define MMI_EM_NFC_NEDF_WRITE_TEXT_LEN              (128)
#define MMI_EM_NFC_ANTENNA_TEST_PARAM_TEXT_LEN      (4)

#define MMI_EM_NFC_REQ_SESSION_ID_START             (0X01)
#define MMI_EM_NFC_REQ_SESSION_ID_STOP              (0X02)
#define MMI_EM_NFC_REQ_SESSION_ID_STOP_FROM_ROOT    (0X03)

#define MMI_EM_NFC_REQ_ACTION_START         (0X01)
#define MMI_EM_NFC_REQ_ACTION_STOP         (0X00)

#define MMI_EM_NFC_EXIT_REQ_TYPE_NORMAL     (0X00)
#define MMI_EM_NFC_EXIT_REQ_TYPE_BACKGROUD  (0X01)


/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef enum
{
    /*don't change the inline cap order below */
    MMI_EM_NFC_INLINE_CAP_1 = CUI_INLINE_ITEM_ID_BASE,
    MMI_EM_NFC_INLINE_CAP_2,
    MMI_EM_NFC_INLINE_CAP_3,
    MMI_EM_NFC_INLINE_CAP_4,
    MMI_EM_NFC_INLINE_SELECT_1,
    MMI_EM_NFC_INLINE_SELECT_2,
    MMI_EM_NFC_INLINE_SELECT_3,
    MMI_EM_NFC_INLINE_SELECT_4,

    MMI_EM_NFC_INLINE_NDEF_WRITE_TYPE_SEL,
    MMI_EM_NFC_INLINE_NDEF_WRITE_DATA_EDIT,
    MMI_EM_NFC_INLINE_CARD_EMU_TYPE_SEL,

    /*don't change the order below 4 item*/
    MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_1,
    MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_2,
    MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_3,
    MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_4
}mmi_em_nfc_inline_item_id_enum;

typedef enum
{
    MMI_EM_NFC_REG_NOTIF_BITMAP_MIFARE_UL   = NOTI_MIFARE_UL,
    MMI_EM_NFC_REG_NOTIF_BITMAP_MIFARE_STD  = NOTI_MIFARE_STD,
    MMI_EM_NFC_REG_NOTIF_BITMAP_ISO1443_4A  = NOTI_ISO14443_4A,
    MMI_EM_NFC_REG_NOTIF_BITMAP_ISO1443_4B  = NOTI_ISO14443_4B,
    MMI_EM_NFC_REG_NOTIF_BITMAP_JEWWL       = NOTI_JEWEL,
    MMI_EM_NFC_REG_NOTIF_BITMAP_NFC         = NOTI_NFC,
    MMI_EM_NFC_REG_NOTIF_BITMAP_FELICA      = NOTI_FELICA,
    MMI_EM_NFC_REG_NOTIF_BITMAP_ISO15693    = NOTI_ISO15693,
    
    MMI_EM_NFC_REG_NOTIF_BITMAP_ENUM_MAX
    
}mmi_em_nfc_reg_notif_bitmap_enum;


typedef void (*mmi_em_nfc_func_ptr)(void *);

typedef struct
{
    MMI_ID      scrn_id;
    MMI_STR_ID  titile_id;
    MMI_STR_ID  lsk_str;
    MMI_STR_ID  rsk_str;
    mmi_em_nfc_func_ptr lsk_func;
    mmi_em_nfc_func_ptr rsk_func;
    mmi_em_nfc_func_ptr end_key_func;
    mmi_em_nfc_func_ptr deinit_func;
    
    WCHAR       *text;
    void        *user_data;
}mmi_em_nfc_show_text_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
    U8          nfc_enable;
    U8          debug_enable;
    U8          sw_protocol;
    MMI_BOOL    is_updated;
}mmi_em_nfc_setting_struct;

typedef struct
{
    U32     reg_type;
}mmi_em_nfc_reg_notif_struct;

typedef struct
{
    U32     set_status;
    U32     se_value;
    WCHAR   name[MMI_EM_NFC_SE_INLINE_CAPTION_LEN];
}mmi_em_nfc_se_struct;

typedef struct
{
    U32     dis_type;
    U32     duration;
}mmi_em_nfc_dis_notif_struct;


typedef struct
{
    mmi_em_nfc_reg_notif_bitmap_enum    bitmap_value;
    MMI_STR_ID                          str_id;
}mmi_em_nfc_bitmap_tb_struct;


typedef enum
{
    MMI_EM_NFC_P2P_SEND,
    MMI_EM_NFC_P2P_RECEIVE,

    MMI_EM_NFC_P2P_ENUM_MAX
}mmi_em_nfc_p2p_sr_type_enum;


typedef struct
{
    U8 reader_mode_protocol_list[MMI_EM_NFC_READER_MODE_PROTOCOLS_NUM];
    U8 p2p_mode_protocol_list[MMI_EM_NFC_P2P_MODE_PROTOCOLS_NUM];
    U32 card_mode_se;    
    U32 p2p_mode_option;
}mmi_em_nfc_hw_test_param;



typedef struct
{
    MMI_BOOL                        is_stoped;
    mmi_em_nfc_p2p_sr_type_enum     p2p_sr_type; /*send or receive*/ 
    WCHAR                           *buf;
    mmi_em_nfc_setting_struct       setting;
    mmi_em_nfc_reg_notif_struct     reg_notif;
    mmi_em_nfc_dis_notif_struct     dis_notif;
    mmi_em_nfc_se_struct            se_set;
    
    U8                              reg_list_state[MMI_EM_NFC_REG_NOTIF_BITMAP_NUM];
    U8                              dis_list_state[MMI_EM_NFC_DIS_NOTIF_BITMAP_NUM];
    MMI_ID                          hw_group_id;
    U8                              antenna_param[4];
    mmi_em_nfc_hw_test_param        hw_param;
    
}mmi_em_nfc_struct;

typedef struct
{
    mmi_id menu_id;
    FuncPtr select_func;
} mmi_em_nfc_menu_select_struct;


typedef struct
{
    NFC_MSG_TYPE     msg_req;
    NFC_MSG_TYPE     msg_rsp;
    mmi_em_nfc_func_ptr rsp_func;
}mmi_em_nfc_msg_rsp_table_struct;

typedef struct
{
    MMI_BOOL        is_entering;
    MMI_BOOL        is_have_rsp;  /*the response of one request is haved*/
    U8              curren_session_id;
    U8              current_req_action; /*current request action 1 or 0*/
    NFC_MSG_TYPE    current_req;  /*current request msg id*/    
    NFC_MSG_TYPE    pre_req_mode; /*previous mode request msg id*/   
}mmi_em_nfc_state_struct;


typedef struct
{
    NFC_MSG_TYPE msg_type;
    MMI_ID str_id;
}mmi_em_nfc_mode_str_struct;


typedef enum
{
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_0  =  DIS_ISO1443_4A,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_1  =  DIS_ISO1443_4B,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_2  =  DIS_FELICA_212,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_3  =  DIS_FELICA_424,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_4  =  DIS_ISO15693,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_MAX
}mmi_em_nfc_hw_test_reader_mode_param_enum;

typedef enum
{
    MMI_EM_NFC_P2P_MODE_PARAM_PROTOCOL_0  =  DIS_NFC_ACTIVE,
    MMI_EM_NFC_P2P_MODE_PARAM_PROTOCOL_1  =  DIS_DISCARD_CARD_EMULATION,
    MMI_EM_NFC_P2P_MODE_PARAM_PROTOCOL_2  =  DIS_DISABLE_P2P_IP_TARGET,
    MMI_EM_NFC_P2P_MODE_PARAM_PROTOCOL_MAX
}mmi_em_nfc_hw_test_p2p_mode_param_protocal_enum;

#define STATIC_FUNCTION
/***************************************************************************** 
 * Static function 
 *****************************************************************************/
static void mmi_em_nfc_start_req_show_progress(MMI_ID title_id, MMI_ID msg_str_id, FuncPtr lsk_func, FuncPtr rsk_func);
static void mmi_em_nfc_stop_req_show_progress(MMI_ID title_id);

static MMI_ID mmi_em_nfc_get_str_id_from_msg_type(NFC_MSG_TYPE msg_type);
static void mmi_em_nfc_trans_bitval_to_list(U32 value, U8 *list, U32 len);

static void mmi_em_nfc_enter_menu_opt(MMI_ID root_id, mmi_em_nfc_menu_select_struct *table);
static MMI_RET mmi_em_nfc_opt_proc(mmi_event_struct *param);
static MMI_BOOL mmi_em_nfc_opt_menu_select(MMI_ID menu_item_id, mmi_em_nfc_menu_select_struct *table);

static MMI_RET mmi_em_nfc_enter_query_proc(mmi_event_struct *param);
static void mmi_em_nfc_enter_nfc_group(void);
static void mmi_em_nfc_enter_main_menu(void);

static void mmi_em_nfc_init(mmi_em_nfc_struct *nfc);
static MMI_RET mmi_em_nfc_proc(mmi_event_struct *param);

static void mmi_em_nfc_setting_enter(void);
static void mmi_em_nfc_sw_reg_notif_enter(mmi_em_nfc_struct *nfc);
static void mmi_em_nfc_sw_dis_notif_enter(mmi_em_nfc_struct *nfc);


static void mmi_em_nfc_setting_init_data(MMI_ID inline_id);
static MMI_RET mmi_em_nfc_setting_proc(mmi_event_struct *param);

static void mmi_em_nfc_req(nfc_msg_struct * newmsg);
static U8 mmi_em_nfc_rsp(void *param);
static void mmi_em_nfc_stop_req(void);
static void mmi_em_nfc_genaral_stop_req(void);




static void mmi_em_nfc_setting_req(mmi_em_nfc_setting_struct *setting);
static void mmi_em_nfc_setting_rsp(void *msg);
static void mmi_em_nfc_sw_reg_notif_req(mmi_em_nfc_reg_notif_struct *reg_notif);
static void mmi_em_nfc_sw_reg_notif_rsp(void *msg);

static void mmi_em_nfc_sw_reg_notif_stop_req(void);

static void mmi_em_nfc_se_entry(void *param);
static MMI_RET mmi_em_nfc_se_inline_proc(mmi_event_struct *param);

static void mmi_em_nfc_sw_se_req(mmi_em_nfc_se_struct *se);
static void mmi_em_nfc_sw_se_rsp(void *msg);
static void mmi_em_nfc_sw_se_stop_req(void);

static void mmi_em_nfc_sw_dis_notif_req(mmi_em_nfc_dis_notif_struct *dis_notif);
static void mmi_em_nfc_sw_dis_notif_rsp(void *msg);


static void mmi_em_nfc_sw_tag_det_rsp(void *msg);
static void mmi_em_nfc_tag_det_option(void *param);
static void mmi_em_nfc_tag_det_ndef_read_req(void);
static void mmi_em_nfc_tag_det_ndef_read_rsp(void *msg);
static void mmi_em_nfc_tag_det_ndef_write(void);
static MMI_RET mmi_em_nfc_tag_det_ndef_write_proc(mmi_event_struct *param);
static void mmi_em_nfc_tag_det_ndef_write_req(MMI_ID inline_id);
static void mmi_em_nfc_tag_det_ndef_write_rsp(void *msg);
static void mmi_em_nfc_tag_det_f2ndef_req(void);
static void mmi_em_nfc_tag_det_f2ndef_rsp(void *msg);
static void mmi_em_nfc_tag_det_disc_req(void *nfc);
static void mmi_em_nfc_tag_det_disc_rsp(void *msg);
static void mmi_em_nfc_tag_det_end_key_hdlr(void *nfc);
static void mmi_em_nfc_tag_det_disc_indicate(void *nfc);
static MMI_RET mmi_em_nfc_tag_det_disc_indicate_finish(mmi_event_struct *param);


static void mmi_em_nfc_sw_p2p_rsp(void *msg);
static void mmi_em_nfc_p2p_option(void *param);

static void mmi_em_nfc_p2p_send(void);
static MMI_RET mmi_em_nfc_p2p_edit_proc(mmi_event_struct *param);
static void mmi_em_nfc_p2p_send_req(WCHAR* buf, U32 len);
//static void mmi_em_nfc_p2p_send_rsp(nfc_p2p_com_response* rsp);

static void mmi_em_nfc_p2p_receive_req(void);
static void mmi_em_nfc_p2p_send_receive_rsp(void *msg);
static void mmi_em_nfc_p2p_disc_req(void *param);
static void mmi_em_nfc_p2p_end_key_hdlr(void *nfc);
static void mmi_em_nfc_tag_p2p_disc_rsp(void *msg);

static void mmi_em_nfc_rd_entry(mmi_em_nfc_struct *nfc);
static MMI_RET mmi_em_nfc_rd_proc(mmi_event_struct *param);
static void mmi_em_nfc_rd_menu_list_entry_hdlr(mmi_em_nfc_struct *nfc, cui_menu_event_struct *evt);
static void mmi_em_nfc_rd_stop_curr_req(void);
static void mmi_em_nfc_rd_exit_nfc(void);
static void mmi_em_nfc_rd_genaral_rsp(nfc_script_response *rsp, MMI_ID progress_title_id);
static void mmi_em_nfc_rd_reader_mode_req(mmi_em_nfc_struct *nfc, U32 action);
static void mmi_em_nfc_rd_reader_mode_rsp(void *msg);
static void mmi_em_nfc_rd_card_emu_mode_req(mmi_em_nfc_struct *nfc, U32 action);
static void mmi_em_nfc_rd_card_emu_mode_rsp(void* msg);
static void mmi_em_nfc_rd_p2p_mode_req(mmi_em_nfc_struct *nfc, U32 action);
static void mmi_em_nfc_rd_p2p_mode_rsp(void* msg);
static void mmi_em_nfc_rd_tx_on_with_ask_enter(void);
static MMI_RET mmi_em_nfc_rd_tx_on_inline_proc(mmi_event_struct *param);
static void mmi_em_nfc_rd_tx_on_req(U32 mode_type, U32 bit_rate, NFC_MSG_TYPE msg_type, U32 action);
static void mmi_em_nfc_rd_tx_on_with_ask_rsp(void *msg);
static void mmi_em_nfc_rd_tx_on_wo_ask_rsp(void *msg);
static void mmi_em_nfc_rd_atenna_test_enter(void);
static MMI_RET mmi_em_nfc_rd_atenna_test_proc(mmi_event_struct *param);
static void mmi_em_nfc_rd_atenna_req(mmi_em_nfc_struct *nfc, U32 action);
static void mmi_em_nfc_rd_atenna_rsp(void *msg);

static void mmi_em_nfc_exit_em_req(U32 type);


/*----------------------------------------------------------------------------*/
/* extern function                                                            */
/*----------------------------------------------------------------------------*/
extern void cui_inline_set_item_fullscreen_edit(
        mmi_id gid,
        U16 item_id,
        cui_inline_set_item_fullscreen_edit_struct *fullscreen_attr);


/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static mmi_em_nfc_struct   *g_mmi_em_nfc;
static mmi_em_nfc_state_struct g_mmi_em_nfc_state;

static const mmi_em_nfc_msg_rsp_table_struct g_mmi_em_nfc_rsp_table[] = 
{
    /*setting*/
    {MSG_ID_NFC_SETTING_REQ, MSG_ID_NFC_SETTING_RSP, mmi_em_nfc_setting_rsp},

    /*software*/    
    {MSG_ID_NFC_NOTIFICATION_REQ, MSG_ID_NFC_NOTIFICATION_RSP, mmi_em_nfc_sw_reg_notif_rsp},  
    {MSG_ID_NFC_SE_SET_REQ, MSG_ID_NFC_SE_SET_RSP, mmi_em_nfc_sw_se_rsp},
    {MSG_ID_NFC_DISCOVERY_REQ, MSG_ID_NFC_DISCOVERY_RSP, mmi_em_nfc_sw_dis_notif_rsp},
#if 0
/* under construction !*/
#endif    
    {MSG_ID_NFC_DISCOVERY_REQ, MSG_ID_NFC_P2P_DET_RSP, mmi_em_nfc_sw_p2p_rsp},

    {MSG_ID_NFC_TAG_READ_REQ, MSG_ID_NFC_TAG_READ_RSP, mmi_em_nfc_tag_det_ndef_read_rsp},
    {MSG_ID_NFC_TAG_WRITE_REQ, MSG_ID_NFC_TAG_WRITE_RSP, mmi_em_nfc_tag_det_ndef_write_rsp},    
    {MSG_ID_NFC_TAG_F2NDEF_REQ, MSG_ID_NFC_TAG_F2NDEF_RSP, mmi_em_nfc_tag_det_f2ndef_rsp},    
    {MSG_ID_NFC_TAG_DISCONN_REQ, MSG_ID_NFC_TAG_DISCONN_RSP, mmi_em_nfc_tag_det_disc_rsp},    
    {MSG_ID_NFC_P2P_COMMUNICATION_REQ, MSG_ID_NFC_P2P_COMMUNICATION_RSP, mmi_em_nfc_p2p_send_receive_rsp},
    {MSG_ID_NFC_P2P_DISCONN_REQ, MSG_ID_NFC_P2P_DISCONN_RSP, mmi_em_nfc_tag_p2p_disc_rsp}, 

    /*HW test*/
    {MSG_ID_NFC_READER_MODE_TEST_REQ, MSG_ID_NFC_READER_MODE_TEST_RSP, mmi_em_nfc_rd_reader_mode_rsp},
    {MSG_ID_NFC_CARD_EMULATION_MODE_TEST_REQ, MSG_ID_NFC_CARD_EMULATION_MODE_TEST_RSP, mmi_em_nfc_rd_card_emu_mode_rsp},
    {MSG_ID_NFC_P2P_MODE_TEST_REQ, MSG_ID_NFC_P2P_MODE_TEST_RSP, mmi_em_nfc_rd_p2p_mode_rsp},
    {MSG_ID_NFC_TX_ALWAYSON_TEST_REQ, MSG_ID_NFC_TX_ALWAYSON_TEST_RSP, mmi_em_nfc_rd_tx_on_with_ask_rsp},
    {MSG_ID_NFC_TX_ALWAYSON_WO_ACK_TEST_REQ, MSG_ID_NFC_TX_ALWAYSON_WO_ACK_TEST_RSP, mmi_em_nfc_rd_tx_on_wo_ask_rsp},
    {MSG_ID_NFC_ANTENNA_SELF_TEST_REQ, MSG_ID_NFC_ANTENNA_SELF_TEST_RSP, mmi_em_nfc_rd_atenna_rsp}
};




static mmi_em_nfc_menu_select_struct g_mmi_em_nfc_menu_table[] = 
{
    {MENU_ID_EM_NFC_TAG_DET_READ, mmi_em_nfc_tag_det_ndef_read_req},
    {MENU_ID_EM_NFC_TAG_DET_WRITE, mmi_em_nfc_tag_det_ndef_write},
    {MENU_ID_EM_NFC_TAG_DET_F2NDEF, mmi_em_nfc_tag_det_f2ndef_req},
    
    {MENU_ID_EM_NFC_P2P_SEND, mmi_em_nfc_p2p_send},
    {MENU_ID_EM_NFC_P2P_RECEIVE, mmi_em_nfc_p2p_receive_req},
    {0, 0}
};


static const MMI_STR_ID g_mmi_em_nfc_reg_notif_bitmap_arr[MMI_EM_NFC_REG_NOTIF_BITMAP_NUM] = 
{
    STR_ID_EM_NFC_STR_MIFAREUL, /*MIFARE_UL*/
    STR_ID_EM_NFC_STR_MIFARESTD, /*MIFARE_STD*/
    STR_ID_EM_NFC_STR_ISO14434A, /*ISO1443_4A*/
    STR_ID_EM_NFC_STR_ISO14434B, /*ISO1443_4B*/
    STR_ID_EM_NFC_STR_JEWEL, /*JEWWL*/
    STR_ID_EM_NFC, /*NFC*/
    STR_ID_EM_NFC_STR_FELICA, /*FELICA*/
    STR_ID_EM_NFC_STR_ISO15693  /*ISO15693*/
};

static const MMI_STR_ID g_mmi_em_nfc_se_bitmap_arr[MMI_EM_NFC_SE_BITMAP_NUM] = 
{
    STR_ID_EM_NFC_SE_BITMAP_0,  /*Start of Transaction*/
    STR_ID_EM_NFC_SE_BITMAP_1,  /*End of Transaction*/
    STR_ID_EM_NFC_SE_BITMAP_2,  /*Transaction*/ 
    STR_ID_EM_NFC_SE_BITMAP_3,  /*Rf filed on*/
    STR_ID_EM_NFC_SE_BITMAP_4,  /*Rf filed off*/
    STR_ID_EM_NFC_SE_BITMAP_5   /*CONNECTIVITY*/ 
};



static const cui_inline_item_caption_struct g_mmi_em_nfc_setting_captions[] = 
{
    STR_ID_EM_NFC_FEATURE,
    STR_ID_EM_NFC_DEBUG,
    STR_ID_EM_NFC_SW_PROTOCOL_SWITCH
};

static const U16 g_mmi_em_nfc_setting_on_off_select_str[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const U16 g_mmi_em_nfc_setting_protocal_select_str[2] = {STR_ID_EM_NFC_SW_PROTOCAL_SW_STACK,
                                                                STR_ID_EM_NFC_SW_PROTOCOL_RAW_DATA};

static const cui_inline_item_select_struct g_mmi_em_nfc_setting_feature_sel = 
{
    2,
    0,
    (U16*)g_mmi_em_nfc_setting_on_off_select_str,
};
static const cui_inline_item_select_struct g_mmi_em_nfc_setting_debug_sel = 
{
    2,
    0,
    (U16*)g_mmi_em_nfc_setting_on_off_select_str,
};
static const cui_inline_item_select_struct g_mmi_em_nfc_setting_protocal_sel = 
{
    2,
    0,
    (U16*)g_mmi_em_nfc_setting_protocal_select_str,
};

static const cui_inline_item_softkey_struct g_mmi_em_nfc_inline_sofkey =
{
    {{CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
     {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
     {STR_GLOBAL_BACK, 0}}        
};


static const cui_inline_set_item_struct g_mmi_em_nfc_setting_inline[6] = 
{
    {MMI_EM_NFC_INLINE_CAP_1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_nfc_setting_captions[0]},
    {MMI_EM_NFC_INLINE_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_nfc_setting_feature_sel},
    {MMI_EM_NFC_INLINE_CAP_2, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_nfc_setting_captions[1]},
    {MMI_EM_NFC_INLINE_SELECT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_nfc_setting_debug_sel},
    {MMI_EM_NFC_INLINE_CAP_3, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&g_mmi_em_nfc_setting_captions[2]},
    {MMI_EM_NFC_INLINE_SELECT_3, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_nfc_setting_protocal_sel},
};

static const cui_inline_struct g_mmi_em_nfc_setting_screen = 
{
    sizeof(g_mmi_em_nfc_setting_inline) / sizeof (cui_inline_set_item_struct),
    STR_ID_EM_NFC,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_nfc_setting_inline,
};



static const U16 g_mmi_em_nfc_se_select_str[3] = 
{
    STR_GLOBAL_OFF,
    STR_ID_EM_NFC_SE_VIRTUAL,
    STR_ID_EM_NFC_SE_WIRED
};


static const cui_inline_item_select_struct g_mmi_em_nfc_se_select = 
{
    3,
    0,
    g_mmi_em_nfc_se_select_str
};


static const cui_inline_set_item_struct g_mmi_em_nfc_se_inline[2] = 
{
    {MMI_EM_NFC_INLINE_CAP_1, CUI_INLINE_ITEM_TYPE_CAPTION, 0, 0},
    {MMI_EM_NFC_INLINE_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_nfc_se_select}    
};

static const cui_inline_struct g_mmi_em_nfc_se_scrn =
{
    sizeof(g_mmi_em_nfc_se_inline) / sizeof (cui_inline_set_item_struct),
    STR_ID_EM_NFC_SE,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)g_mmi_em_nfc_se_inline   
};



static const cui_inline_item_caption_struct g_mmi_em_nfc_rd_tx_cap[2] = 
{
    STR_ID_EM_NFC_MOD_TYPE,
    STR_ID_EM_NFC_BIT_RATE
};

static const U16 g_mmi_em_nfc_mode_type_sel_str[] = {STR_ID_EM_NFC_MOD_TYPE_A,
                                                        STR_ID_EM_NFC_MOD_TYPE_B,
                                                        STR_ID_EM_NFC_MOD_TYPE_F};
static const U16 g_mmi_em_nfc_bit_rate_sel_str[] = {STR_ID_EM_NFC_BIT_RATE_106,
                                                        STR_ID_EM_NFC_BIT_RATE_212,
                                                        STR_ID_EM_NFC_BIT_RATE_424,
                                                        STR_ID_EM_NFC_BIT_RATE_848};


static const cui_inline_item_select_struct g_mmi_em_nfc_mode_type_sel = 
{
    sizeof(g_mmi_em_nfc_mode_type_sel_str) / sizeof(U16),
    0,
    (U16*)g_mmi_em_nfc_mode_type_sel_str,
};

static const cui_inline_item_select_struct g_mmi_em_nfc_bit_rate_sel = 
{
    sizeof(g_mmi_em_nfc_bit_rate_sel_str) / sizeof(U16),
    0,
    (U16*)g_mmi_em_nfc_bit_rate_sel_str,
};



static const cui_inline_set_item_struct g_mmi_em_nfc_rd_tx_inline_item[4] = 
{
    {MMI_EM_NFC_INLINE_CAP_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_STATUS, (void*)&g_mmi_em_nfc_rd_tx_cap[0]},
    {MMI_EM_NFC_INLINE_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_nfc_mode_type_sel},
    {MMI_EM_NFC_INLINE_CAP_2, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_STATUS, (void*)&g_mmi_em_nfc_rd_tx_cap[1]},
    {MMI_EM_NFC_INLINE_SELECT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&g_mmi_em_nfc_bit_rate_sel}
};

static const cui_inline_struct g_mmi_em_nfc_rd_tx_screen = 
{
    sizeof(g_mmi_em_nfc_rd_tx_inline_item) / sizeof (cui_inline_set_item_struct),
    STR_ID_EM_NFC_RD_TX_ON_WITH_ASK,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    0,
    (const cui_inline_set_item_struct*)&g_mmi_em_nfc_rd_tx_inline_item,
};


static const cui_inline_item_caption_struct g_mmi_em_nfc_tag_det_write_cap[2] = 
{
    STR_ID_EM_NFC_NDEF_RW_TAG_TYPE,
    STR_ID_EM_NFC_NDEF_RW_TAG_DATA
};

static const U16 g_mmi_em_nfc_ndef_rw_type_str[3] = {STR_ID_EM_NFC_NDEF_RW_TAG_TYPE_URL,
                                                        STR_ID_EM_NFC_NDEF_RW_TAG_TYPE_TEXT,
                                                        STR_ID_EM_NFC_NDEF_RW_TAG_TYPE_SMART_POSTER};
static const cui_inline_item_select_struct g_mmi_em_nfc_ndef_write_type_sel = 
{
    3,
    0,
    g_mmi_em_nfc_ndef_rw_type_str    
};

static const cui_inline_item_fullscreen_edit_struct g_mmi_em_nfc_ndef_write_data_edit = 
{
    0,
    0,
    STR_ID_EM_NFC_NDEF_RW_TAG_DATA,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_SENTENCE,
    MMI_EM_NFC_NEDF_WRITE_TEXT_LEN,
    0
};


static const cui_inline_set_item_struct g_mmi_em_nfc_ndef_write[4] = 
{
    {MMI_EM_NFC_INLINE_CAP_1,  CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_em_nfc_tag_det_write_cap[0]},
    {MMI_EM_NFC_INLINE_NDEF_WRITE_TYPE_SEL,  CUI_INLINE_ITEM_TYPE_SELECT, 0, &g_mmi_em_nfc_ndef_write_type_sel},    
    {MMI_EM_NFC_INLINE_CAP_2,  CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_em_nfc_tag_det_write_cap[1]},
    {MMI_EM_NFC_INLINE_NDEF_WRITE_DATA_EDIT, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, &g_mmi_em_nfc_ndef_write_data_edit}
};

static const cui_inline_struct g_mmi_em_nfc_tag_write_inline_scrn = 
{
    sizeof(g_mmi_em_nfc_ndef_write) / sizeof(cui_inline_set_item_struct),
    STR_ID_EM_NFC_WRITE,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    0,
    g_mmi_em_nfc_ndef_write
};


static const cui_inline_item_caption_struct g_mmi_em_nfc_antenna_test_cap[4] = 
{
    STR_ID_EM_NFC_ANTENNA_TEST_PARAM_1,
    STR_ID_EM_NFC_ANTENNA_TEST_PARAM_2,
    STR_ID_EM_NFC_ANTENNA_TEST_PARAM_3,
    STR_ID_EM_NFC_ANTENNA_TEST_PARAM_4
};

static const cui_inline_item_text_edit_struct g_mmi_em_nfc_antenna_test_edit = 
{
    0,
    0,
    MMI_EM_NFC_ANTENNA_TEST_PARAM_TEXT_LEN,
    IMM_INPUT_TYPE_NUMERIC,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    0
};

static const cui_inline_set_item_struct g_mmi_em_nfc_antenna_test_inline[] = 
{
    {MMI_EM_NFC_INLINE_CAP_1,  CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_em_nfc_antenna_test_cap[0]},
    {MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_1,  CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_em_nfc_antenna_test_edit},    
    {MMI_EM_NFC_INLINE_CAP_2,  CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_em_nfc_antenna_test_cap[1]},
    {MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_2, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_em_nfc_antenna_test_edit},
    {MMI_EM_NFC_INLINE_CAP_3,  CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_em_nfc_antenna_test_cap[2]},
    {MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_3, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_em_nfc_antenna_test_edit},
    {MMI_EM_NFC_INLINE_CAP_4,  CUI_INLINE_ITEM_TYPE_CAPTION, 0, &g_mmi_em_nfc_antenna_test_cap[3]},
    {MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_4, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, &g_mmi_em_nfc_antenna_test_edit}    
};



static const cui_inline_struct g_mmi_em_nfc_antenna_test_inline_scrn = 
{
    sizeof(g_mmi_em_nfc_antenna_test_inline) / sizeof (cui_inline_set_item_struct),
    STR_ID_EM_NFC_RD_ANTANNA_TEST,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    0,
    g_mmi_em_nfc_antenna_test_inline
};

static const MMI_STR_ID g_mmi_em_nfc_card_types[] = 
{
    STR_GLOBAL_DEFAULT,
    STR_ID_EM_NFC_STR_MIFAREUL,
    STR_ID_EM_NFC_STR_MIFARESTD,
    STR_ID_EM_NFC_STR_ISO14434A,
    STR_ID_EM_NFC_STR_ISO14434B,
    STR_ID_EM_NFC_STR_JEWEL,
    STR_ID_EM_NFC,
    STR_ID_EM_NFC_STR_FELICA,
    STR_ID_EM_NFC_STR_ISO15693,
    STR_ID_EM_NFC_STR_NDEF
};


static const mmi_em_nfc_hw_test_reader_mode_param_enum g_mmi_em_nfc_rd_mode_param_ptl_table[MMI_EM_NFC_READER_MODE_PROTOCOLS_NUM] =
{
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_0,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_1,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_2,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_3,
    MMI_EM_NFC_RD_MODE_PARAM_PROTOCOL_4
};

static const mmi_em_nfc_hw_test_p2p_mode_param_protocal_enum g_mmi_em_nfc_p2p_mode_param_ptl_table[MMI_EM_NFC_P2P_MODE_PROTOCOLS_NUM] = 
{
    MMI_EM_NFC_P2P_MODE_PARAM_PROTOCOL_0,
    MMI_EM_NFC_P2P_MODE_PARAM_PROTOCOL_1,
    MMI_EM_NFC_P2P_MODE_PARAM_PROTOCOL_2
};

static nfc_p2p_type g_mmi_em_nfc_p2p_mode_type_value_tble[] = 
{
    nfc_p2p_DefaultP2PMode,
    nfc_p2p_Passive106,
    nfc_p2p_Passive212,
    nfc_p2p_Passive424,
    nfc_p2p_Active,
    nfc_p2p_P2P_ALL,
    nfc_p2p_InvalidP2PMode
};


static const mmi_em_nfc_mode_str_struct g_mmi_em_nfc_mode_str_table [] = 
{
    {MSG_ID_NFC_READER_MODE_TEST_REQ, STR_ID_EM_NFC_RD_READER_MODE},
    {MSG_ID_NFC_CARD_EMULATION_MODE_TEST_REQ, STR_ID_EM_NFC_RD_CARD_EMU_MODE},
    {MSG_ID_NFC_P2P_MODE_TEST_REQ, STR_ID_EM_NFC_RD_P2P_MODE},
    {MSG_ID_NFC_TX_ALWAYSON_TEST_REQ, STR_ID_EM_NFC_RD_TX_ON_WITH_ASK},
    {MSG_ID_NFC_TX_ALWAYSON_WO_ACK_TEST_REQ, STR_ID_EM_NFC_RD_TX_ON_WO_ASK}
};


    

#define NFC_TEST
#ifdef __MMI_EM_NFC_TEST__
static void mmi_em_nfc_timer_hdlr(void *param)
{
    nfc_msg_struct *msg;
    static U32 buf[500];
    static U32 flag;
    #if 1
    nfc_script_response  *script_rsp;
    nfc_setting_response *setting_rsp;
    nfc_reg_notif_response *reg_notif_rsp;
    nfc_se_set_response *   se_set_rsp;
    nfc_dis_notif_response  *dis_notif_rsp;
    nfc_tag_det_response    *tag_det_rsp;
	#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    if (flag)
    {
        msg = (nfc_msg_struct *)buf;    
    }
    else
    {
        msg = (nfc_msg_struct *)param;
    }
    
    script_rsp = se_set_rsp = setting_rsp = 
    dis_notif_rsp = tag_det_rsp = reg_notif_rsp = (void*)(msg + 1);
//    msg->msg_type = MSG_ID_NFC_NOTIFICATION_RSP;
    mmi_em_nfc_rsp(msg);
    
}

#endif


#define NFC_EM_MAIN
/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_enter
  * DESCRIPTION
  *  mmi_em_nfc_enter
  * PARAMETERS
  *  submit      [IN] 
  * RETURNS
  *  void 
  *****************************************************************************/
void mmi_em_nfc_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID str_id;
    WCHAR *buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_id = mmi_em_nfc_get_str_id_from_msg_type(g_mmi_em_nfc_state.pre_req_mode);
    if (str_id)
    {
        buffer = OslMalloc(100);
        kal_wsprintf(buffer, "%w %w ?", GetString(STR_GLOBAL_STOP), GetString(str_id));

        mmi_em_display_confirm_by_str(buffer,
			               mmi_em_get_root_group(),
			               MMI_EVENT_QUERY,
			               mmi_em_nfc_enter_query_proc);
		OslMfree(buffer);
    }
    else
    {
        mmi_em_nfc_enter_nfc_group();
        mmi_em_nfc_enter_main_menu();
    }
}

static MMI_RET mmi_em_nfc_enter_query_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_ALERT_CNFM_YES == alert->result)
    {
        mmi_em_nfc_enter_nfc_group();
        mmi_em_nfc_rd_stop_curr_req();
        g_mmi_em_nfc_state.is_entering = MMI_TRUE;
    }
    return MMI_RET_OK;
}

static void mmi_em_nfc_enter_nfc_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_NFC_TEST__
    mmi_frm_set_protocol_event_handler(MSG_ID_NFC_TEST_RSP, (PsIntFuncPtr)mmi_em_nfc_timer_hdlr, MMI_FALSE);
#else
    mmi_frm_set_protocol_event_handler(MSG_ID_NFC_TEST_RSP, (PsIntFuncPtr)mmi_em_nfc_rsp, MMI_FALSE);
#endif
	if (g_mmi_em_nfc)
	{
		MMI_EM_FREE(g_mmi_em_nfc);
	}
    g_mmi_em_nfc = MMI_EM_MALLOC(sizeof(mmi_em_nfc_struct));
    mmi_em_nfc_init(g_mmi_em_nfc);

    mmi_frm_group_create_ex(mmi_em_get_root_group(),
                                            GRP_ID_EM_NFC,
                                            mmi_em_nfc_proc,
                                            g_mmi_em_nfc,
                                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_enter_main_menu
  * DESCRIPTION
  *  mmi_em_nfc_enter_main_menu
  * PARAMETERS
  *  submit      [IN] 
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_nfc_enter_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_EM_NFC) == MMI_FALSE)
    {
        mmi_em_nfc_enter_nfc_group();
    }
    g_mmi_em_nfc_state.is_entering = MMI_FALSE;
    mmi_frm_hide_menu_item(MENU_ID_EM_NFC_SW_STACK);
    mmi_frm_hide_menu_item(MENU_ID_EM_NFC_RD);
    cui_menu_create_and_run(GRP_ID_EM_NFC,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_APPSUB,
                            MENU_ID_EM_NFC,
                            MMI_TRUE,
                            g_mmi_em_nfc);
}

static void mmi_em_nfc_init(mmi_em_nfc_struct *nfc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(nfc, 0, sizeof(mmi_em_nfc_struct));
    nfc->setting.debug_enable = 0;
    nfc->setting.nfc_enable = 0;
    nfc->setting.sw_protocol = 0;
    nfc->reg_notif.reg_type = 0XFE;
    nfc->dis_notif.dis_type = 0XFE;
    nfc->dis_notif.duration = MTK_NFC_DIS_NOTIF_DURATION;

    /*all support*/
    mmi_em_nfc_trans_bitval_to_list(0X1F, 
                                        nfc->hw_param.reader_mode_protocol_list,
                                        MMI_EM_NFC_READER_MODE_PROTOCOLS_NUM);

    nfc->hw_param.card_mode_se = 0; /*UICC*/

    /*NFC active*/
    mmi_em_nfc_trans_bitval_to_list(0X01, 
                                        nfc->hw_param.p2p_mode_protocol_list,
                                        MMI_EM_NFC_P2P_MODE_PROTOCOLS_NUM);
   

   nfc->hw_param.p2p_mode_option = 0X05; /*P2P all*/

    mmi_em_nfc_trans_bitval_to_list(nfc->reg_notif.reg_type,
                                        nfc->reg_list_state,
                                        MMI_EM_NFC_REG_NOTIF_BITMAP_NUM);
    mmi_em_nfc_trans_bitval_to_list(nfc->dis_notif.dis_type,
                                        nfc->dis_list_state,
                                        MMI_EM_NFC_REG_NOTIF_BITMAP_NUM);  
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_proc
  * DESCRIPTION
  *  mmi_em_nfc_proc
  * PARAMETERS
  *  param      [IN] 
  * RETURNS
  *  MMI_RET 
  *****************************************************************************/
static MMI_RET mmi_em_nfc_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    mmi_em_nfc_struct *nfc = (mmi_em_nfc_struct *)param->user_data;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if(nfc->setting.is_updated)
            {
                /*when nfc feature is not enable, should hide "Software stack" and "HW test"*/
                if (!nfc->setting.nfc_enable)
                {
                    mmi_frm_hide_menu_item(MENU_ID_EM_NFC_RD);
                    mmi_frm_hide_menu_item(MENU_ID_EM_NFC_SW_STACK);
                }
                else 
                {
                    if (nfc->setting.sw_protocol == 0) /*software stack*/
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_EM_NFC_SW_STACK);
                        mmi_frm_hide_menu_item(MENU_ID_EM_NFC_RD);
                    }
                    else if (nfc->setting.sw_protocol == 1) /*hw test*/
                    {
                        mmi_frm_unhide_menu_item(MENU_ID_EM_NFC_RD);
                        mmi_frm_hide_menu_item(MENU_ID_EM_NFC_SW_STACK);
                    }
                }
                nfc->setting.is_updated = MMI_FALSE;                
            }
            if (evt->parent_menu_id == MENU_ID_EM_NFC_SW_STACK_REG_NOTIFICATION )
            {
                cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_CHECK_BOX_LIST);
                cui_menu_set_checkbox_state(evt->sender_id, nfc->reg_list_state);
            }
            else if (evt->parent_menu_id == MENU_ID_EM_NFC_SW_STACK_DISCOVERY_NOTIFICATION)
            {
                cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_CHECK_BOX_LIST);
                cui_menu_set_checkbox_state(evt->sender_id, nfc->dis_list_state);                
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (evt->highlighted_menu_id)
            {
                case MENU_ID_EM_NFC_SETTING:
                    mmi_em_nfc_setting_enter();
                    break;
                    
                case MENU_ID_EM_NFC_SW_STACK_REG_NOTIFICATION:
                case MENU_ID_EM_NFC_SW_STACK_DISCOVERY_NOTIFICATION:
                    cui_menu_create_and_run(GRP_ID_EM_NFC,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_APPSUB,
                            evt->highlighted_menu_id,
                            MMI_TRUE,
                            nfc);
                    break;

                case MENU_ID_EM_NFC_RD:
                    mmi_em_nfc_rd_entry(nfc);
                    break;
                    
                default:
                    break;
            }
            if (evt->parent_menu_id == MENU_ID_EM_NFC_SW_STACK_REG_NOTIFICATION)
            {
                cui_menu_get_checkbox_state(evt->sender_id, nfc->reg_list_state);
                cui_menu_close(evt->sender_id);
                mmi_em_nfc_sw_reg_notif_enter(nfc);
            }
            else if (evt->parent_menu_id == MENU_ID_EM_NFC_SW_STACK_DISCOVERY_NOTIFICATION)
            {
                cui_menu_get_checkbox_state(evt->sender_id, nfc->dis_list_state);
                cui_menu_close(evt->sender_id);
                mmi_em_nfc_sw_dis_notif_enter(nfc);
            }
            break;
        }

        case EVT_ID_GROUP_DEINIT:    
            if (mmi_em_nfc_get_str_id_from_msg_type(g_mmi_em_nfc_state.pre_req_mode))
            {
                /*backgroud exit*/
                mmi_em_nfc_exit_em_req(MMI_EM_NFC_EXIT_REQ_TYPE_BACKGROUD);
            }
            else
            {
                /*normal exit*/
                mmi_em_nfc_exit_em_req(MMI_EM_NFC_EXIT_REQ_TYPE_NORMAL);                
            }
            MMI_EM_FREE(g_mmi_em_nfc);
            g_mmi_em_nfc = 0;
 //           mmi_frm_set_protocol_event_handler(MSG_ID_NFC_TEST_RSP, NULL, MMI_FALSE);
            break;

        default:
            break;            
    }

    return MMI_RET_OK;
}



#define MFC_UTIL

static MMI_ID mmi_em_nfc_get_str_id_from_msg_type(NFC_MSG_TYPE msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for ( i = 0; i < sizeof(g_mmi_em_nfc_mode_str_table) / sizeof(mmi_em_nfc_mode_str_struct); i++)
    {
        if (g_mmi_em_nfc_mode_str_table[i].msg_type == msg_type)
        {
            return g_mmi_em_nfc_mode_str_table[i].str_id;
        }
    }
    return 0;
}

static void mmi_em_nfc_trans_bitval_to_list(U32 value, U8 *list, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i< len; i++)
    {
        if (value & 1 << i)
        {
            list[i] = 1;
        }
        else
        {
            list[i] = 0;
        }
    }
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_show_progress
  * DESCRIPTION
  *  mmi_em_nfc_show_progress
  * PARAMETERS
  *  title_id       [IN]
  *  rsk_func       [IN] right softkey function
  *  
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_nfc_show_progress(MMI_ID title_id, FuncPtr rsk_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_start_req_show_progress(title_id, STR_GLOBAL_PLEASE_WAIT, 0,rsk_func);
}


static void mmi_em_nfc_start_req_show_progress(MMI_ID title_id, MMI_ID msg_str_id, FuncPtr lsk_func, FuncPtr rsk_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_progress_cntx_struct cntx = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_EM_NFC))
    {
        return;
    }
    cntx.title_id = title_id;
    cntx.message = (U8*)get_string(msg_str_id);
    cntx.group_id = GRP_ID_EM_NFC;
    cntx.scrn_id = SCR_ID_MMI_EM_NFC_START_PROGRESS;
    if (lsk_func)
    {
        cntx.left_softkey = STR_ID_EM_NFC_BG;
    }
    if (rsk_func)
    {
        cntx.right_softkey = STR_GLOBAL_STOP;
    }
    cntx.lsk_func = lsk_func;
    cntx.rsk_func = rsk_func;
    cntx.esk_func = mmi_em_progress_sftkey_null_hdlr;
    mmi_em_show_progress_scrn(&cntx);
}

static void mmi_em_nfc_stop_req_show_progress(MMI_ID title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_progress_cntx_struct cntx = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    cntx.title_id = STR_ID_EM_NFC_STOPING;
    cntx.message = (U8*)get_string(STR_GLOBAL_PLEASE_WAIT);
    cntx.group_id = GRP_ID_EM_NFC;
    cntx.scrn_id = SCR_ID_MMI_EM_NFC_STOP_PROGRESS;
    cntx.esk_func = mmi_em_progress_sftkey_null_hdlr;
    mmi_em_show_progress_scrn(&cntx);
}

static void mmi_em_nfc_hw_test_start_req_show_progress(MMI_ID title_id, FuncPtr lsk_func, FuncPtr rsk_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_em_nfc_start_req_show_progress(title_id, STR_ID_EM_NFC_TESTING, lsk_func, rsk_func);
}

static void mmi_em_nfc_start_req_progress_scrn_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_scrn_close(GRP_ID_EM_NFC, SCR_ID_MMI_EM_NFC_START_PROGRESS);
}

static void mmi_em_nfc_stop_req_progress_scrn_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_scrn_close(GRP_ID_EM_NFC, SCR_ID_MMI_EM_NFC_STOP_PROGRESS);
}


static MMI_RET mmi_em_nfc_show_text_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_show_text_struct *cntx = (mmi_em_nfc_show_text_struct *)param->user_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {

        case EVT_ID_SCRN_DEINIT:
            if (cntx->deinit_func)
            {
                cntx->deinit_func(cntx->user_data);
            }
            if (cntx->text)
            {
                MMI_EM_FREE(cntx->text);
                cntx->text = 0;
            }
            MMI_EM_FREE(cntx);
            break;

        case EVT_ID_SCRN_ACTIVE:
            {
                mmi_frm_scrn_active_evt_struct *active_evt = (mmi_frm_scrn_active_evt_struct *)param;
                ShowCategory78Screen(cntx->titile_id, 
                                    0,
                                    cntx->lsk_str,
                                    0,
                                    cntx->rsk_str,
                                    0,
                                    0,
                                    (U8*)cntx->text,
                                    mmi_wcslen(cntx->text),
                                    active_evt->gui_buffer);
                break;
            }
            

        case EVT_ID_WGUI_LSK_CLICK:
            if (cntx->lsk_func)
            {
                cntx->lsk_func(cntx->user_data);
                return MMI_RET_KEY_HANDLED;
            }
            break;

        case EVT_ID_WGUI_RSK_CLICK:
            if (cntx->rsk_func)
            {
                cntx->rsk_func(cntx->user_data);
                return MMI_RET_KEY_HANDLED;
            }
            break;

        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            if (cntx->end_key_func)
            {
                cntx->end_key_func(cntx->user_data);
            }
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_show_text_view
  * DESCRIPTION
  *  mmi_em_nfc_show_text_view
  * PARAMETERS
  *  cntx      [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_nfc_show_text_view(mmi_em_nfc_show_text_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    mmi_em_nfc_show_text_struct *cntx;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_em_nfc_show_text_struct *)MMI_EM_MALLOC(sizeof(mmi_em_nfc_show_text_struct));
    memcpy(cntx, param, sizeof(mmi_em_nfc_show_text_struct));
    len = mmi_wcslen(param->text);
    cntx->text = (WCHAR *)MMI_EM_MALLOC(sizeof(WCHAR) *(len + 1));
    mmi_wcscpy(cntx->text, param->text);
 
    mmi_frm_scrn_create(GRP_ID_EM_NFC,
                        cntx->scrn_id,
                        mmi_em_nfc_show_text_scrn_proc,
                        cntx);
}


static void mmi_em_nfc_enter_menu_opt(MMI_ID root_id, mmi_em_nfc_menu_select_struct *table)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   group_id = mmi_frm_group_create_ex(GRP_ID_EM_NFC,
                            GRP_ID_AUTO_GEN, 
                            mmi_em_nfc_opt_proc,
                            table,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_menu_create_and_run(group_id, 
                                CUI_MENU_SRC_TYPE_RESOURCE,
                                CUI_MENU_TYPE_OPTION,
                                root_id,
                                MMI_TRUE,
                                table);
    
}

static MMI_RET mmi_em_nfc_opt_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_em_nfc_menu_select_struct *table = (mmi_em_nfc_menu_select_struct *)(param->user_data);
            MMI_BOOL result = mmi_em_nfc_opt_menu_select(evt->highlighted_menu_id, table);
            MMI_ASSERT(result != 0);
            break;
        }

       default:
        break;
    }
    return MMI_RET_OK;
}

static MMI_BOOL mmi_em_nfc_opt_menu_select(MMI_ID menu_item_id, mmi_em_nfc_menu_select_struct *table)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; ; i++)
    {
        if (table[i].menu_id == 0)
        {
            return MMI_FALSE;
        }

        if (table[i].menu_id == menu_item_id)
        {
            table[i].select_func();
            return MMI_TRUE;
        }
    }
}


static mmi_em_nfc_general_popup(MMI_BOOL success)
{
    if (success)
    {
        /*success*/
        mmi_em_success_popup();
    }
    else
    {
        mmi_em_popup_by_str(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE);
    }
}

static mmi_em_nfc_popup_by_str(MMI_ID str_id, mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(str_id, event_type, GRP_ID_ROOT, NULL);
}

#define NFC_MSG
/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_genaral_stop_req
 * DESCRIPTION
 *  mmi_em_nfc_genaral_stop_req
 * PARAMETERS
 *  msg_id     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_genaral_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_stop_req();
    mmi_frm_scrn_close(GRP_ID_EM_NFC, SCR_ID_MMI_EM_NFC_START_PROGRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_req
 * DESCRIPTION
 *  send nfc request to MOD_NFC
 * PARAMETERS
 *  newmsg   [IN]         
 * RETURNS
 *  U8
 *****************************************************************************/
static void mmi_em_nfc_req(nfc_msg_struct * newmsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_1(MMI_EM_NFC_TRC_NUM_REQ, newmsg->msg_type);
    
    g_mmi_em_nfc->is_stoped = MMI_FALSE;

    if (newmsg->msg_type != MSG_ID_NFC_EXIT_EMFM)
    {
        g_mmi_em_nfc_state.current_req = (NFC_MSG_TYPE)newmsg->msg_type;    
    }    
//    g_mmi_em_nfc_state.is_have_rsp = MMI_FALSE;
	
	mmi_frm_send_ilm(MOD_NFC, MSG_ID_NFC_TEST_REQ, (oslParaType*)newmsg, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_rsp
 * DESCRIPTION
 *  nfc response handler
 * PARAMETERS
 *  param   [IN]         
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_em_nfc_rsp(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *rsp_msg = (nfc_msg_struct *)param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (!g_mmi_em_nfc || g_mmi_em_nfc->is_stoped)
    {
        return 0;
    }
  
    if (rsp_msg)
    {
        U32 i;
        MMI_EM_NFC_TRACE_1(MMI_EM_NFC_TRC_NUM_RSP, rsp_msg->msg_type);
        if (rsp_msg->msg_type == MSG_ID_NFC_TAG_DET_RSP)
        {
            /*MSG_ID_NFC_TAG_DET_RSP is a special. it can response after ndef disconnect*/
            mmi_em_nfc_sw_tag_det_rsp((void*)(rsp_msg + 1));   
        }
        else
        {
            for (i = 0; i< sizeof(g_mmi_em_nfc_rsp_table) / sizeof (mmi_em_nfc_msg_rsp_table_struct); i++)
            {
                if (g_mmi_em_nfc_rsp_table[i].msg_rsp == rsp_msg->msg_type)
                {
                    if (g_mmi_em_nfc_rsp_table[i].msg_req != g_mmi_em_nfc_state.current_req)
                    {
                        MMI_EM_NFC_TRACE_3(MMI_EM_NFC_TRC_NUM_RSP_NOT_MATCH, rsp_msg->msg_type, g_mmi_em_nfc_state.current_req, i);
                    }
                    else
                    {
                        if (g_mmi_em_nfc_rsp_table[i].rsp_func)
                        {
                            g_mmi_em_nfc_rsp_table[i].rsp_func((void*)(rsp_msg + 1));
                        }
                    }
                }
            }
        }
        
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif    
    }
    else
    {
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_stop_req
 * DESCRIPTION
 *  tell MOD_NFC to Stop Test
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct));    
    newmsg->msg_type = MSG_ID_NFC_STOP_TEST_REQ;
    newmsg->msg_length = 0;
    mmi_em_nfc_req(newmsg);
    g_mmi_em_nfc->is_stoped = MMI_TRUE;
}





#define NFC_SETTING
/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_setting_enter
  * DESCRIPTION
  *  mmi_em_nfc_setting_enter
  * PARAMETERS
  *  submit      [IN] 
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_nfc_setting_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    MMI_ID inline_id;
    mmi_em_nfc_setting_struct *setting = &g_mmi_em_nfc->setting;
    nfc_status status = {0};
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    NFC_STATUS_QUERY(&status);
    setting->nfc_enable = (U8)status.nfc_state;
    setting->debug_enable = (U8)status.nfc_debug_state;
    setting->sw_protocol = (U8)status.nfc_protocol_state;
    MMI_EM_NFC_TRACE_3(MMI_EM_NFC_TRC_NUM_SETTING_QUERY,
                        status.nfc_debug_state,
                        status.nfc_state,
                        status.nfc_protocol_state);
    
    gid = mmi_frm_group_create_ex(GRP_ID_EM_NFC, 
                                    GRP_ID_AUTO_GEN,
                                    mmi_em_nfc_setting_proc,
                                    NULL,
                                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_nfc_setting_screen);	
    mmi_em_nfc_setting_init_data(inline_id);    
    cui_inline_run(inline_id);
}


/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_setting_init_data
  * DESCRIPTION
  *  mmi_em_nfc_setting_init_data
  * PARAMETERS
  *  inline_id      [IN]
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_nfc_setting_init_data(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_setting_struct *setting;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting = &g_mmi_em_nfc->setting;
    cui_inline_set_value(inline_id, MMI_EM_NFC_INLINE_SELECT_1, (void*)setting->nfc_enable);
    cui_inline_set_value(inline_id, MMI_EM_NFC_INLINE_SELECT_2, (void*)setting->debug_enable);
    cui_inline_set_value(inline_id, MMI_EM_NFC_INLINE_SELECT_3, (void*)setting->sw_protocol);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
    

/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_setting_proc
  * DESCRIPTION
  *  mmi_em_nfc_setting_proc
  * PARAMETERS
  *  param      [IN] 
  * RETURNS
  *  MMI_RET 
  *****************************************************************************/
static MMI_RET mmi_em_nfc_setting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            {
                mmi_em_nfc_setting_struct *setting = &g_mmi_em_nfc->setting;
                cui_inline_get_value(inline_evt->sender_id, MMI_EM_NFC_INLINE_SELECT_1,&setting->nfc_enable);
                cui_inline_get_value(inline_evt->sender_id, MMI_EM_NFC_INLINE_SELECT_2,&setting->debug_enable);
                cui_inline_get_value(inline_evt->sender_id, MMI_EM_NFC_INLINE_SELECT_3,&setting->sw_protocol);
                mmi_em_nfc_setting_req(setting);
            }
            break;

        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_evt->sender_id);
            break;

        case EVT_ID_GROUP_DEINIT:
            break;

#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif           
        default:
            break;
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_setting_req
 * DESCRIPTION
 *  mmi_em_nfc_setting_req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_setting_req(mmi_em_nfc_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_setting_request *setting_req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_setting_request));    
    newmsg->msg_type = MSG_ID_NFC_SETTING_REQ;
    newmsg->msg_length = sizeof(nfc_setting_request);

    setting_req = (nfc_setting_request *)((newmsg + 1));
    setting_req->debug_enable = setting->debug_enable;
    setting_req->nfc_enable = setting->nfc_enable;
    setting_req->sw_protocol = setting->sw_protocol;
    setting_req->get_capabilities = MMI_EM_NFC_SETTING_GET_CAP_VALUE;
    MMI_EM_NFC_TRACE_3(MMI_EM_NFC_TRC_NUM_SETTING_REQ, setting_req->debug_enable,
                        setting_req->nfc_enable,
                        setting_req->sw_protocol);
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_ID_EM_NFC_TESTING, 0);

    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_setting_req
 * DESCRIPTION
 *  mmi_em_nfc_setting_req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_setting_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID str_id;
    U32 i;
    WCHAR *buf;
    nfc_setting_response *setting_rsp = (nfc_setting_response *)msg;
    mmi_em_text_viewer_struct cntx = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_4(MMI_EM_NFC_TRC_NUM_SETTING_RSP, 
                        setting_rsp->status,
                        setting_rsp->debug_enable,
                        setting_rsp->nfc_enable,
                        setting_rsp->sw_protocol);
    if (setting_rsp->status != MTK_NFC_SUCCESS)
    {
        mmi_em_fail_popup();
    }
    else
    {
        buf = OslMalloc(MMI_EM_NFC_SETTING_RSP_BUF_LEN * sizeof (WCHAR));
        kal_wsprintf(buf, "FW: 0x%x\nSW: 0x%x\nHW: 0x%x\n\nSupport Protocols:\n", 
                        setting_rsp->fw_ver,
                        setting_rsp->sw_ver,
                        setting_rsp->hw_ver);
        if (setting_rsp->reader_mode)
        {
            mmi_ucs2cat((S8*)buf, (S8*)L"RM:\n");
            for ( i = 0; i < MMI_EM_NFC_REG_NOTIF_BITMAP_NUM; i++)
            {
                if (setting_rsp->reader_mode & (1 << i))
                {
                    str_id = g_mmi_em_nfc_reg_notif_bitmap_arr[i];
                    mmi_ucs2cat((S8*)buf, (S8*)get_string(str_id));
                    mmi_ucs2cat((S8*)buf, (S8*)L"\n");
                }
            }
        }

        if (setting_rsp->card_mode)
        {
            mmi_ucs2cat((S8*)buf, (S8*)L"CM:\n");
            for ( i = 0; i < MMI_EM_NFC_REG_NOTIF_BITMAP_NUM; i++)
            {
                if (setting_rsp->card_mode & (1 << i))
                {
                    str_id = g_mmi_em_nfc_reg_notif_bitmap_arr[i];
                    mmi_ucs2cat((S8*)buf, (S8*)get_string(str_id));
                    mmi_ucs2cat((S8*)buf, (S8*)L"\n");
                }
            }
        }

        cntx.parent_gid = GRP_ID_EM_NFC;
        cntx.title_id = STR_ID_EM_NFC_SETTING;
        cntx.text = buf;
        mmi_em_show_text_viewer(&cntx);
        OslMfree(buf);
        g_mmi_em_nfc->setting.is_updated = MMI_TRUE;
    }
    mmi_em_nfc_start_req_progress_scrn_close();
}


#define NFC_SW_STACK

/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_sw_reg_notif_enter
  * DESCRIPTION
  *  mmi_em_nfc_sw_reg_notif_enter
  * PARAMETERS
  *  nfc      [IN] 
  * RETURNS
  *  void 
  *****************************************************************************/
static void mmi_em_nfc_sw_reg_notif_enter(mmi_em_nfc_struct *nfc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U32 i;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfc->reg_notif.reg_type = 0;
    for (i = 0; i < MMI_EM_NFC_REG_NOTIF_BITMAP_NUM; i++)
    {
        if (nfc->reg_list_state[i])
        {
            nfc->reg_notif.reg_type |= 1 << i;
        }
    }
    mmi_em_nfc_sw_reg_notif_req(&nfc->reg_notif);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_sw_reg_notif_req
 * DESCRIPTION
 *  mmi_em_nfc_sw_reg_notif_req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_sw_reg_notif_req(mmi_em_nfc_reg_notif_struct *reg_notif)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_reg_notif_request *reg_req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_reg_notif_request));    
    newmsg->msg_type = MSG_ID_NFC_NOTIFICATION_REQ;
    newmsg->msg_length = sizeof(nfc_reg_notif_request);

    reg_req = (nfc_reg_notif_request *)((newmsg + 1));
    reg_req->reg_type = reg_notif->reg_type;
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_ID_EM_NFC_TESTING, mmi_em_nfc_sw_reg_notif_stop_req);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_sw_reg_notif_rsp
 * DESCRIPTION
 *  mmi_em_nfc_sw_reg_notif_rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_sw_reg_notif_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j = 1;
    nfc_reg_notif_response *reg_notif_rsp = (nfc_reg_notif_response *)msg;
    mmi_em_nfc_struct *nfc_p = g_mmi_em_nfc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (reg_notif_rsp->status != MTK_NFC_SUCCESS)
    {
        mmi_em_fail_popup();
    }
    else
    {
        if (reg_notif_rsp->se == 0)
        {
            mmi_em_success_popup();
        }
        else
        {
            WCHAR *buf;
            WCHAR temp_buf[30];
            mmi_em_nfc_show_text_struct cntx = {0};

            buf = OslMalloc(MMI_EM_NFC_REG_NOTIF_BUF_LEN * sizeof (WCHAR));
            kal_wsprintf(buf, "%w%d: %w\n\n",
                                get_string(STR_ID_EM_NFC_SE),
                                reg_notif_rsp->se,
                                get_string(g_mmi_em_nfc_se_select_str[reg_notif_rsp->se_status])
                            );
            if (reg_notif_rsp->se_type)
            {
                MMI_STR_ID str_id;
                mmi_ucs2cat((S8*)buf, (S8*)L"SE Events Detected:\n");
                for ( i = 0; i < MMI_EM_NFC_SE_BITMAP_NUM; i++)
                {
                    if (reg_notif_rsp->se_type & (1 << i))
                    {
                        str_id = g_mmi_em_nfc_se_bitmap_arr[i];
                        kal_wsprintf(temp_buf, " %d, %w\n", j++, get_string(str_id));
                        mmi_ucs2cat((S8*)buf, (S8*)temp_buf);
                    }
                } 
            }

            nfc_p->se_set.set_status = reg_notif_rsp->se_status;
            nfc_p->se_set.se_value = reg_notif_rsp->se;
            
            cntx.titile_id = STR_ID_EM_NFC_SW_STACK_REG_NOTIFICATION;
            cntx.scrn_id = SCR_ID_MMI_EM_NFC_SHOW_TEXT;
            cntx.lsk_str = STR_GLOBAL_GO_TO;
            cntx.rsk_str = STR_GLOBAL_BACK;
            cntx.lsk_func = mmi_em_nfc_se_entry;
            cntx.user_data = g_mmi_em_nfc;
            cntx.text = buf;
        
            mmi_em_nfc_show_text_view(&cntx);
            OslMfree(buf);
        }
    }  
    mmi_em_nfc_start_req_progress_scrn_close();
}

static void mmi_em_nfc_sw_reg_notif_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_stop_req();
    mmi_frm_scrn_close_active_id();    
}



static void mmi_em_nfc_se_entry(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    MMI_ID inline_id;
    mmi_em_nfc_struct *nfc = (mmi_em_nfc_struct *)param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_frm_group_create_ex(GRP_ID_EM_NFC,
                                    GRP_ID_AUTO_GEN,
                                    mmi_em_nfc_se_inline_proc,
                                    nfc,
                                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_nfc_se_scrn);
    kal_wsprintf(g_mmi_em_nfc->se_set.name, "%w%d", get_string(STR_ID_EM_NFC_SE), nfc->se_set.se_value);
    cui_inline_set_value(inline_id, MMI_EM_NFC_INLINE_CAP_1, (void *)nfc->se_set.name);
    cui_inline_set_value(inline_id, MMI_EM_NFC_INLINE_SELECT_1, (void*)nfc->se_set.set_status);
    cui_inline_run(inline_id);
}

/*****************************************************************************
  * FUNCTION
  *  mmi_em_nfc_se_inline_proc
  * DESCRIPTION
  *  mmi_em_nfc_se_inline_proc
  * PARAMETERS
  *  param      [IN] 
  * RETURNS
  *  MMI_RET 
  *****************************************************************************/
static MMI_RET mmi_em_nfc_se_inline_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) param;
    mmi_em_nfc_struct *nfc = (mmi_em_nfc_struct *)param->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
            {
                cui_inline_get_value(inline_evt->sender_id, MMI_EM_NFC_INLINE_SELECT_1,&nfc->se_set.set_status);
                mmi_em_nfc_sw_se_req(&nfc->se_set);
                cui_inline_close(inline_evt->sender_id);
            }
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_evt->sender_id);
            break;
          
        default:
            break;
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_sw_se_req
 * DESCRIPTION
 *  mmi_em_nfc_sw_se_req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_sw_se_req(mmi_em_nfc_se_struct *se)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_se_set_request *se_req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_se_set_request));    
    newmsg->msg_type = MSG_ID_NFC_SE_SET_REQ;
    newmsg->msg_length = sizeof(nfc_se_set_request);

    se_req = (nfc_se_set_request *)((newmsg + 1));
    se_req->set_SEtype = se->set_status;
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_ID_EM_NFC_TESTING, mmi_em_nfc_sw_se_stop_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_sw_se_rsp
 * DESCRIPTION
 *  mmi_em_nfc_sw_se_rsp
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_sw_se_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_se_set_response * se_rsp = (nfc_se_set_response *)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(se_rsp->status == MTK_NFC_SUCCESS)
    {
        mmi_frm_scrn_close(GRP_ID_EM_NFC, SCR_ID_MMI_EM_NFC_SHOW_TEXT);    
    }    
    mmi_em_nfc_general_popup((MMI_BOOL)(se_rsp->status == MTK_NFC_SUCCESS));
    mmi_em_nfc_start_req_progress_scrn_close();
}

static void mmi_em_nfc_sw_se_stop_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_stop_req();
    mmi_frm_scrn_close_active_id();    
}


static void mmi_em_nfc_sw_dis_notif_enter(mmi_em_nfc_struct *nfc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U32 i;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfc->dis_notif.dis_type = 0;
    nfc->dis_notif.duration = MTK_NFC_DIS_NOTIF_DURATION;
    for (i = 0; i < MMI_EM_NFC_DIS_NOTIF_BITMAP_NUM; i++)
    {
        if (nfc->dis_list_state[i])
        {
            nfc->dis_notif.dis_type |= 1 << i;
        }
    }
    mmi_em_nfc_sw_dis_notif_req(&nfc->dis_notif);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_sw_dis_notif_req
 * DESCRIPTION
 *  mmi_em_nfc_sw_dis_notif_req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_sw_dis_notif_req(mmi_em_nfc_dis_notif_struct *dis_notif)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_dis_notif_request *dis_notif_req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_dis_notif_request));    
    newmsg->msg_type = MSG_ID_NFC_DISCOVERY_REQ;
    newmsg->msg_length = sizeof(nfc_dis_notif_request);

    dis_notif_req = (nfc_dis_notif_request *)((newmsg + 1));

    dis_notif_req->dis_type = dis_notif->dis_type;
    dis_notif_req->duration = dis_notif->duration;

    MMI_EM_NFC_TRACE_2(MMI_EM_NFC_TRC_NUM_DIS_NOTIFI_REQ,
                        dis_notif_req->dis_type,
                        dis_notif_req->duration);
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_ID_EM_NFC_TESTING, mmi_em_nfc_genaral_stop_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_sw_dis_notif_rsp
 * DESCRIPTION
 *  mmi_em_nfc_sw_dis_notif_rsp
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_sw_dis_notif_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_dis_notif_response* dis_notif_rsp = (nfc_dis_notif_response* )msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dis_notif_rsp->status != MTK_NFC_SUCCESS)
    {
        mmi_em_fail_popup();
        mmi_frm_scrn_close(GRP_ID_EM_NFC, SCR_ID_MMI_EM_NFC_START_PROGRESS);
    }
}

#define NFC_TAG_DETECTED
static void mmi_em_nfc_sw_tag_det_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *buf;
    CHAR *uidbuff;
    U32 tag_char;
	U32 i;
    nfc_tag_det_response* tag_det_rsp = (nfc_tag_det_response*)msg;
    mmi_em_nfc_show_text_struct param = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_5(MMI_EM_NFC_TRC_NUM_TAG_DETACTED_RSP,
                        tag_det_rsp->tag_type,
                        tag_det_rsp->sak,
                        tag_det_rsp->atag,
                        tag_det_rsp->appdata,
                        tag_det_rsp->maxdatarate);

    buf = OslMalloc(MMI_EM_NFC_TAG_DET_BUF_LEN * sizeof (WCHAR));
    if ((tag_det_rsp->tag_type & 0x02)  != 0)
    {
        tag_char = 'Y';
        mmi_frm_unhide_menu_item(MENU_ID_EM_NFC_TAG_DET_READ);
        mmi_frm_unhide_menu_item(MENU_ID_EM_NFC_TAG_DET_WRITE);
    }
    else
    {
        tag_char = 'N';
        mmi_frm_hide_menu_item(MENU_ID_EM_NFC_TAG_DET_READ);
        mmi_frm_hide_menu_item(MENU_ID_EM_NFC_TAG_DET_WRITE);
    }

    /*format uid*/
    uidbuff = OslMalloc(100);
    for(i = 0; i < sizeof(tag_det_rsp->uid) / sizeof(unsigned char); i++)
    {
        if (tag_det_rsp->uid[i] >= 16)
        {
            sprintf(uidbuff + i * 5, "0X%2X ", tag_det_rsp->uid[i]);
        }
        else
        {
            sprintf(uidbuff + i * 5, "0X0%1X ", tag_det_rsp->uid[i]);
        }        
    }
    
    kal_wsprintf(buf, 
                    "NDEF Tag: %c\n\nCardType: %w\nUid: %s\nSak: 0x%x\nAtag: 0x%x\nAppdata: 0x%x\nMaxdatarate: 0x%x", 
                    tag_char,
                    get_string(g_mmi_em_nfc_card_types[tag_det_rsp->card_type % 10]),
                    uidbuff,
                    tag_det_rsp->sak,
                    tag_det_rsp->atag,
                    tag_det_rsp->appdata,
                    tag_det_rsp->maxdatarate);
    OslMfree(uidbuff);
    param.titile_id = STR_ID_EM_NFC_TAG_DET;
    param.lsk_str = STR_GLOBAL_OPTIONS;
    param.rsk_str = STR_GLOBAL_DISCONNECT;
    param.lsk_func = mmi_em_nfc_tag_det_option;
    param.rsk_func = mmi_em_nfc_tag_det_disc_indicate;
    param.end_key_func = mmi_em_nfc_tag_det_end_key_hdlr;
    param.scrn_id = SCR_ID_MMI_EM_NFC_TAG_DET_INFO;    
    param.text = buf;
    param.user_data = g_mmi_em_nfc;
    
    mmi_em_nfc_show_text_view(&param);
    OslMfree(buf);
    mmi_em_nfc_start_req_progress_scrn_close();
}


static void mmi_em_nfc_tag_det_option(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_enter_menu_opt(MENU_ID_EM_NFC_TAG_DET_OPT, g_mmi_em_nfc_menu_table);
}

static void mmi_em_nfc_tag_det_ndef_read_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_tag_read_request *read_req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_tag_read_request));    
    newmsg->msg_type = MSG_ID_NFC_TAG_READ_REQ;
    newmsg->msg_length = sizeof(nfc_tag_read_request);

    read_req = (nfc_tag_read_request *)((newmsg + 1));
    read_req->read_type = nfc_NDEF;
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_ID_EM_NFC_TESTING, mmi_em_nfc_genaral_stop_req);
}

static void mmi_em_nfc_tag_det_ndef_read_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_tag_read_response* rsp = (nfc_tag_read_response*)msg;
    nfc_tag_read_ndef *ndef_rsp = &rsp->nfc_tag_read_result.nfc_tag_read_ndef_resp;
    WCHAR* buf;
    mmi_em_text_viewer_struct param = {0};
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_3(MMI_EM_NFC_TRC_NUM_TAG_DET_NDEF_READ_RSP,
                        rsp->status,
                        ndef_rsp->length,
                        ndef_rsp->ndef_type);
    if (rsp->status != MTK_NFC_SUCCESS)
    {
        mmi_em_popup_by_str(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE);
    }
    else
    {
        
    #ifdef __MMI_EM_NFC_TEST__
        {
            U32 i;
            for (i = 0; i < NDEF_DATA_LEN; i++)
            {
                ndef_rsp->data[i] = '1';
            }
            ndef_rsp->length = NDEF_DATA_LEN;
            ndef_rsp->ndef_type = 2; /*0~2*/
            ndef_rsp->recordFlags = 0xff;
            ndef_rsp->recordId[0] = 0x00;
            ndef_rsp->recordTnf = 0xff;            
        }
    #endif
        buf = OslMalloc(MMI_EM_NFC_NDEF_READ_TEXT_LEN * sizeof(WCHAR));
        kal_wsprintf(buf, "Tag type: %w\nLang:%s\n\nFlag: 0X%x\nID: %s\nTnf: 0X%x\nLength: 0X%x\n\nASCII: %s",
                        get_string(g_mmi_em_nfc_ndef_rw_type_str[(ndef_rsp->ndef_type - NDEF_STORE_TYPE_URL) % 3]),
                        ndef_rsp->lang,
                        ndef_rsp->recordFlags,
                        ndef_rsp->recordId,
                        ndef_rsp->recordTnf,
                        ndef_rsp->length,
                        ndef_rsp->data);

        param.parent_gid = GRP_ID_EM_NFC;
        param.title_id = STR_GLOBAL_READ;
        param.text = buf;
        mmi_em_show_text_viewer(&param);

        OslMfree(buf);
    }
    mmi_em_nfc_start_req_progress_scrn_close();
}


static void mmi_em_nfc_tag_det_ndef_write(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID inline_id;
    mmi_em_nfc_struct   *nfc_p = g_mmi_em_nfc;
    cui_inline_set_item_fullscreen_edit_struct fullscreen_attr;
    
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create_ex(GRP_ID_EM_NFC,
                            GRP_ID_AUTO_GEN,
                            mmi_em_nfc_tag_det_ndef_write_proc,
                            nfc_p,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(group_id, &g_mmi_em_nfc_tag_write_inline_scrn);

    if (nfc_p->buf)
    {
        MMI_EM_FREE(nfc_p->buf);
    }

    nfc_p->buf = (WCHAR*)MMI_EM_MALLOC((MMI_EM_NFC_NEDF_WRITE_TEXT_LEN +1) * sizeof(WCHAR));

    fullscreen_attr.buffer = (void*)nfc_p->buf;
    fullscreen_attr.default_text_id = NULL;
    fullscreen_attr.buffer_size = MMI_EM_NFC_NEDF_WRITE_TEXT_LEN;
    fullscreen_attr.title = STR_ID_EM_NFC_NDEF_RW_TAG_DATA;
    fullscreen_attr.title_icon = 0;
    fullscreen_attr.input_type = IMM_INPUT_TYPE_SENTENCE;
    fullscreen_attr.input_extended_type = INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL;
    fullscreen_attr.required_input_mode_set = NULL;

    cui_inline_set_item_fullscreen_edit(inline_id,
                                            (U16)MMI_EM_NFC_INLINE_NDEF_WRITE_DATA_EDIT,
                                            &fullscreen_attr);
    cui_inline_run(inline_id);    
}

static MMI_RET mmi_em_nfc_tag_det_ndef_write_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_common_struct *evt = (cui_event_inline_common_struct*)param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(evt->sender_id);
            break;
            
        case EVT_ID_CUI_INLINE_SUBMIT:
            mmi_em_nfc_tag_det_ndef_write_req(evt->sender_id);
            cui_inline_close(evt->sender_id);
            break;

        case EVT_ID_GROUP_DEINIT:
        {
            mmi_em_nfc_struct *nfc_p = (mmi_em_nfc_struct *)(param->user_data);
            if (nfc_p->buf)
            {
                MMI_EM_FREE(nfc_p->buf);
                nfc_p->buf = 0;
            }
            break;
        }
            
        default:
            break;
    }
    return MMI_RET_OK;
}

static void mmi_em_nfc_tag_det_ndef_write_req(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_tag_write_request *write_req;
    nfc_tag_write_ndef *ndef;
    mmi_em_nfc_struct *nfc_p = g_mmi_em_nfc;
    CHAR *buf;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_tag_write_request));    
    newmsg->msg_type = MSG_ID_NFC_TAG_WRITE_REQ;
    newmsg->msg_length = sizeof(nfc_tag_write_request);

    write_req = (nfc_tag_write_request *)((newmsg + 1));
    write_req->write_type = nfc_NDEF;
    ndef = (nfc_tag_write_ndef *)&(write_req->nfc_tag_write_data.nfc_tag_write_ndef_data);

    cui_inline_get_value(inline_id, MMI_EM_NFC_INLINE_NDEF_WRITE_TYPE_SEL, &ndef->ndef_type);
    ndef->ndef_type += 1; /*1 ~ 3*/
//    buf = OslMalloc(MMI_EM_NFC_NEDF_WRITE_TEXT_LEN * sizeof(WCHAR));
    cui_inline_get_value(inline_id, MMI_EM_NFC_INLINE_NDEF_WRITE_DATA_EDIT, nfc_p->buf);

//    nfc_p->buf[MMI_EM_NFC_NEDF_WRITE_TEXT_LEN - 1] = 0;
//    ndef->length = mmi_wcslen(nfc_p->buf);
    ndef->length = sizeof(nfc_tag_write_ndef_data);
    ndef->language = nfc_ndef_lang_EN;
    if (ndef->ndef_type == nfc_ndef_URI)
    {
        nfc_p->buf[63] = 0;
        buf = (CHAR*)ndef->ndef_data.URL_Data.URLData;
        ndef->ndef_data.URL_Data.URLLength = mmi_wcslen(nfc_p->buf);
        ndef->ndef_data.URL_Data.URLtype = ndef_url_webaddr;
    }
    else if (ndef->ndef_type == nfc_ndef_TEXT)
    {
        nfc_p->buf[127] = 0;
        buf = (CHAR*)ndef->ndef_data.TX_Data.data;
        ndef->ndef_data.TX_Data.DataLength = mmi_wcslen(nfc_p->buf);
    }
    else /* if (ndef->ndef_type == nfc_ndef_SMART_POSTER) */
    {
        nfc_p->buf[63] = 0;
        buf = (CHAR*)ndef->ndef_data.SP_Data.Compagny;
        ndef->ndef_data.SP_Data.CompagnyLength = mmi_wcslen(nfc_p->buf);
    }
    mmi_wcs_to_asc(buf, nfc_p->buf);
    
//    OslMfree(buf);
    
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_ID_EM_NFC_TESTING, mmi_em_nfc_genaral_stop_req);
}


static void mmi_em_nfc_tag_det_ndef_write_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_tag_write_response* rsp = (nfc_tag_write_response* )msg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_general_popup((MMI_BOOL)(rsp->status == MTK_NFC_SUCCESS));
    mmi_em_nfc_start_req_progress_scrn_close();
}

static void mmi_em_nfc_tag_det_f2ndef_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_tag_fromat2Ndef_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_tag_fromat2Ndef_request));    
    newmsg->msg_type = MSG_ID_NFC_TAG_F2NDEF_REQ;
    newmsg->msg_length = sizeof(nfc_tag_fromat2Ndef_request);

    req = (nfc_tag_fromat2Ndef_request *)((newmsg + 1));
    req->action = 1;
    
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_ID_EM_NFC_TESTING, mmi_em_nfc_genaral_stop_req);
}


static void mmi_em_nfc_tag_det_f2ndef_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_tag_fromat2Ndef_response* rsp = (nfc_tag_fromat2Ndef_response*)msg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_general_popup((MMI_BOOL)(rsp->status == MTK_NFC_SUCCESS));
    mmi_em_nfc_start_req_progress_scrn_close();
}

static void mmi_em_nfc_tag_det_disc_indicate(void *nfc)
{
    mmi_confirm_property_struct arg;

    mmi_confirm_property_init(&arg, CNFM_TYPE_OK);
    arg.callback = mmi_em_nfc_tag_det_disc_indicate_finish;
    arg.parent_id = GRP_ID_EM_NFC;
    arg.f_auto_map_empty_softkey =  MMI_FALSE;
    arg.user_tag = nfc;

    mmi_confirm_display((WCHAR *)L"Please remove TAG from RF", MMI_EVENT_INFO, &arg);
}

static MMI_RET mmi_em_nfc_tag_det_disc_indicate_finish(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_ALERT_CNFM_OK == alert->result)
    {
        mmi_em_nfc_tag_det_disc_req(alert->user_tag);
    }
    return MMI_RET_OK;
}


static void mmi_em_nfc_tag_det_disc_req(void *nfc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_tag_disconnect_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_tag_disconnect_request));    
    newmsg->msg_type = MSG_ID_NFC_TAG_DISCONN_REQ;
    newmsg->msg_length = sizeof(nfc_tag_disconnect_request);

    req = (nfc_tag_disconnect_request *)((newmsg + 1));
    req->action = 1;
    
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_GLOBAL_DISCONNECTING, 0);    
}

static void mmi_em_nfc_tag_det_end_key_hdlr(void *nfc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_tag_disconnect_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_tag_disconnect_request));    
    newmsg->msg_type = MSG_ID_NFC_TAG_DISCONN_REQ;
    newmsg->msg_length = sizeof(nfc_tag_disconnect_request);
    req = (nfc_tag_disconnect_request *)((newmsg + 1));
    req->action = 1;    
    mmi_em_nfc_req(newmsg);
}


static void mmi_em_nfc_tag_det_disc_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_tag_disconnect_response* rsp = (nfc_tag_disconnect_response*)msg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_1(MMI_EM_NFC_TRC_NUM_TAG_DET_DISCONNECT_RSP, rsp->status);
    mmi_em_nfc_general_popup((MMI_BOOL)(rsp->status == MTK_NFC_SUCCESS));
    if (rsp->status == MTK_NFC_SUCCESS)
    {
        mmi_frm_scrn_close(GRP_ID_EM_NFC, SCR_ID_MMI_EM_NFC_TAG_DET_INFO);    
    }
    mmi_em_nfc_start_req_progress_scrn_close();
}


#define NFC_P2P

static void mmi_em_nfc_sw_p2p_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *buf;
    U32 yesno[2];
    mmi_em_nfc_show_text_struct param = {0};
    nfc_p2p_det_response* rsp = (nfc_p2p_det_response*)msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_1(MMI_EM_NFC_TRC_NUM_P2P_DETECTED_RSP, rsp->p2p_type);
    buf = OslMalloc(MMI_EM_NFC_P2P_INFO_TEXT_LEN * sizeof (WCHAR));
    if (rsp->p2p_type & 0x01)
    {
        yesno[0] = 'Y';
    }
    else
    {
        yesno[0] = 'N';
    }
    if (rsp->p2p_type & 0x02)
    {
        yesno[1] = 'Y'; 
    }
    else
    {
        yesno[1] = 'N';
    }

    
    kal_wsprintf(buf, "Target: %c\nInitiator: %c", yesno[0], yesno[1]);
    
    param.titile_id = STR_ID_EM_NFC_P2P;
    param.lsk_str = STR_GLOBAL_OPTIONS;
    param.rsk_str = STR_GLOBAL_DISCONNECT;
    param.lsk_func = mmi_em_nfc_p2p_option;
    param.rsk_func = mmi_em_nfc_p2p_disc_req;
    param.end_key_func = mmi_em_nfc_p2p_end_key_hdlr;
    param.scrn_id = SCR_ID_MMI_EM_NFC_P2P_INFO;    
    param.text = buf;
    param.user_data = g_mmi_em_nfc;
    
    mmi_em_nfc_show_text_view(&param);
    OslMfree(buf);
    mmi_em_nfc_start_req_progress_scrn_close();
}

static void mmi_em_nfc_p2p_option(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_enter_menu_opt(MENU_ID_EM_NFC_P2P_OPT, g_mmi_em_nfc_menu_table);
}



static void mmi_em_nfc_p2p_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    MMI_ID editor_gid;
    WCHAR *buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buf = (WCHAR *)MMI_EM_MALLOC(P2P_MAX_LENGTH * sizeof(WCHAR));
    buf[0] = 0;
    gid = mmi_frm_group_create_ex(GRP_ID_EM_NFC,
                            GRP_ID_AUTO_GEN,
                            mmi_em_nfc_p2p_edit_proc,
                            buf,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if ((editor_gid = cui_fseditor_create(gid)) != GRP_ID_INVALID)
    {
        cui_fseditor_set_title(editor_gid, STR_GLOBAL_SEND, 0);
        cui_fseditor_set_text(editor_gid, buf, P2P_MAX_LENGTH * sizeof(WCHAR), P2P_MAX_LENGTH - 1);
        cui_fseditor_set_input_method(editor_gid, IMM_INPUT_TYPE_SENTENCE, NULL, 0);
        cui_fseditor_run(editor_gid);
    }
}

static MMI_RET mmi_em_nfc_p2p_edit_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_fseditor_edit_evt_struct *evt = (cui_fseditor_edit_evt_struct*)param;
    WCHAR *buf;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            buf = (WCHAR*)(param->user_data);
            cui_fseditor_get_text(evt->sender_id, buf, P2P_MAX_LENGTH * sizeof(WCHAR));            
            mmi_em_nfc_p2p_send_req(buf, P2P_MAX_LENGTH);
            cui_fseditor_close(evt->sender_id);
            break;
            
        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(evt->sender_id);
            break;

        case EVT_ID_GROUP_DEINIT:
            MMI_EM_FREE(param->user_data);
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}



static void mmi_em_nfc_p2p_send_req(WCHAR* buf, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_p2p_com_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_p2p_com_request));    
    newmsg->msg_type = MSG_ID_NFC_P2P_COMMUNICATION_REQ;
    newmsg->msg_length = sizeof(nfc_p2p_com_request);

    req = (nfc_p2p_com_request *)((newmsg + 1));
    req->action = 1; /*send*/
    buf[P2P_MAX_LENGTH -1] = 0;
    mmi_wcs_to_asc((CHAR*)req->data, buf);
    req->length = mmi_wcslen(buf);
    
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_GLOBAL_SENDING, mmi_em_nfc_genaral_stop_req);    
    g_mmi_em_nfc->p2p_sr_type = MMI_EM_NFC_P2P_SEND;
}

static void mmi_em_nfc_p2p_receive_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_p2p_com_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_p2p_com_request));    
    newmsg->msg_type = MSG_ID_NFC_P2P_COMMUNICATION_REQ;
    newmsg->msg_length = sizeof(nfc_p2p_com_request);

    req = (nfc_p2p_com_request *)((newmsg + 1));
    req->action = 2; /*receive*/
   
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_GLOBAL_RECEIVING, mmi_em_nfc_genaral_stop_req);
    g_mmi_em_nfc->p2p_sr_type = MMI_EM_NFC_P2P_RECEIVE;
}

static void mmi_em_nfc_p2p_send_receive_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *buf;
    mmi_em_text_viewer_struct param = {0};
    nfc_p2p_com_response* rsp = (nfc_p2p_com_response*)msg;
    mmi_em_nfc_struct * nfc_p = g_mmi_em_nfc;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->status != MTK_NFC_SUCCESS)
    {
        mmi_em_popup_by_str(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE);
    }
    else
    {
#ifdef __MMI_EM_NFC_TEST__
        {
            static U32 flag = 1;
            U32 i;

            rsp->length = (flag == 1 ? 100 : (P2P_MAX_LENGTH - 1));
            
            for (i = 0; i< rsp->length; i++)
            {
                rsp->data[i] = (flag == 1 ? 'A' : 'a');
            }
            rsp->data[i] = 0;
            flag = (flag + 1) % 2;
        }
#endif
        buf = OslMalloc(P2P_MAX_LENGTH * sizeof(WCHAR));
        if (rsp->length == 0)
        {
            mmi_asc_to_wcs(buf, "No data response");
        }
        else
        {
            rsp->data[P2P_MAX_LENGTH - 1] = 0;
           mmi_asc_to_wcs(buf, (CHAR*)rsp->data);
        }
        param.parent_gid = GRP_ID_EM_NFC;
        if (nfc_p->p2p_sr_type == MMI_EM_NFC_P2P_SEND)
        {
            param.title_id = STR_GLOBAL_SEND;
        }
        else
        {
            param.title_id = STR_ID_EM_NFC_RECEIVE;
        }        
        param.text = buf;
        mmi_em_show_text_viewer(&param);
        OslMfree(buf);
    }
    mmi_em_nfc_start_req_progress_scrn_close();
}

static void mmi_em_nfc_p2p_disc_req(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_p2p_disconnect_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_p2p_disconnect_request));    
    newmsg->msg_type = MSG_ID_NFC_P2P_DISCONN_REQ;
    newmsg->msg_length = sizeof(nfc_p2p_disconnect_request);

    req = (nfc_p2p_disconnect_request *)((newmsg + 1));
    req->action = 1;
    
    mmi_em_nfc_req(newmsg);
    mmi_em_nfc_show_progress(STR_GLOBAL_DISCONNECTING, 0);
}

static void mmi_em_nfc_p2p_end_key_hdlr(void *nfc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_p2p_disconnect_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_p2p_disconnect_request));    
    newmsg->msg_type = MSG_ID_NFC_TAG_DISCONN_REQ;
    newmsg->msg_length = sizeof(nfc_p2p_disconnect_request);
    req = (nfc_p2p_disconnect_request *)((newmsg + 1));
    req->action = 1;    
    mmi_em_nfc_req(newmsg);
}

static void mmi_em_nfc_tag_p2p_disc_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_p2p_disconnect_response* rsp = (nfc_p2p_disconnect_response* )msg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_general_popup((MMI_BOOL)(rsp->status == MTK_NFC_SUCCESS));
    if (rsp->status == MTK_NFC_SUCCESS)
    {
        mmi_frm_scrn_close(GRP_ID_EM_NFC, SCR_ID_MMI_EM_NFC_P2P_INFO);    
    }
    mmi_em_nfc_start_req_progress_scrn_close();
}


#define NFC_RAW_DATA

static void mmi_em_nfc_rd_entry(mmi_em_nfc_struct *nfc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create_ex(GRP_ID_EM_NFC,
                            GRP_ID_AUTO_GEN,
                            mmi_em_nfc_rd_proc,
                            nfc,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    nfc->hw_group_id = group_id;
//    nfc->rd_data.group_id = group_id;
    cui_menu_create_and_run(group_id, 
                                CUI_MENU_SRC_TYPE_RESOURCE,
                                CUI_MENU_TYPE_FROM_RESOURCE,
                                MENU_ID_EM_NFC_RD,
                                MMI_TRUE,
                                nfc);
   
}




static MMI_RET mmi_em_nfc_rd_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    mmi_em_nfc_struct *nfc = (mmi_em_nfc_struct *)param->user_data;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_em_nfc_rd_menu_list_entry_hdlr(nfc, evt);
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (evt->highlighted_menu_id)
            {      
                case MENU_ID_EM_NFC_RD_TX_ON_WITH_ASK:
                    mmi_em_nfc_rd_tx_on_with_ask_enter();
                    break;

                case MENU_ID_EM_NFC_RD_TX_ON_WO_ASK:
                    mmi_em_nfc_rd_tx_on_req(0,0,
                                            MSG_ID_NFC_TX_ALWAYSON_WO_ACK_TEST_REQ,
                                            MMI_EM_NFC_REQ_ACTION_START);
                    
                    break;
                    
                case MENU_ID_EM_NFC_RD_CARD_EMU_MODE:
                    mmi_em_nfc_rd_card_emu_mode_req(nfc, MMI_EM_NFC_REQ_ACTION_START);
                    break;
                    
                case MENU_ID_EM_NFC_RD_READER_MODE:
                    mmi_em_nfc_rd_reader_mode_req(nfc, MMI_EM_NFC_REQ_ACTION_START);
                    break;

                case MENU_ID_EM_NFC_RD_P2P_MODE:
                    mmi_em_nfc_rd_p2p_mode_req(nfc, MMI_EM_NFC_REQ_ACTION_START);
                    break;

                case MENU_ID_EM_NFC_RD_ANTENNA_TEST:
                    mmi_em_nfc_rd_atenna_test_enter();
                    break;

                case MENU_ID_EM_NFC_RD_PROTOCOLS:
                case MENU_ID_EM_NFC_CARD_PARAM_SE_TYPE:
                case MENU_ID_EM_NFC_P2P_PROTOCAL:
                case MENU_ID_EM_NFC_P2P_MODE_OPT:
                   cui_menu_create_and_run(nfc->hw_group_id,
                                            CUI_MENU_SRC_TYPE_RESOURCE,
                                            CUI_MENU_TYPE_FROM_RESOURCE,
                                            evt->highlighted_menu_id,
                                            MMI_TRUE,
                                            nfc);
                   break;
                    
                default:
                    break;
            }

            switch(evt->parent_menu_id)
            {
                case MENU_ID_EM_NFC_RD_PROTOCOLS:
                    cui_menu_get_checkbox_state(evt->sender_id, nfc->hw_param.reader_mode_protocol_list);
                    cui_menu_close(evt->sender_id);
                    break;

                case MENU_ID_EM_NFC_CARD_PARAM_SE_TYPE:
                    nfc->hw_param.card_mode_se = evt->highlighted_menu_id - 
                                                            MENU_ID_EM_NFC_CARD_EMU_TYPE_UICC;
                    cui_menu_close(evt->sender_id);
                    break;

                case MENU_ID_EM_NFC_P2P_PROTOCAL:
                    cui_menu_get_checkbox_state(evt->sender_id, nfc->hw_param.p2p_mode_protocol_list);
                    cui_menu_close(evt->sender_id);
                    break;

                case MENU_ID_EM_NFC_P2P_MODE_OPT:
                    nfc->hw_param.p2p_mode_option = evt->highlighted_menu_id - MENU_ID_EM_NFC_P2P_OPT_DEFAULT;
                    cui_menu_close(evt->sender_id);
                    break;

                default:
                    break;
            }
            
            break;
        }

        default:
            break;  
    }
    return MMI_RET_OK;
}

static void mmi_em_nfc_rd_menu_list_entry_hdlr(mmi_em_nfc_struct *nfc, cui_menu_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->parent_menu_id)
    {
        case MENU_ID_EM_NFC_RD_PROTOCOLS:
            cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_CHECK_BOX_LIST);
            cui_menu_set_checkbox_state(evt->sender_id, nfc->hw_param.reader_mode_protocol_list);                    
            break;

        case MENU_ID_EM_NFC_CARD_PARAM_SE_TYPE:
            cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            cui_menu_set_radio_list_item(evt->sender_id, nfc->hw_param.card_mode_se + MENU_ID_EM_NFC_CARD_EMU_TYPE_UICC);
            break;

        case MENU_ID_EM_NFC_P2P_PROTOCAL:
            cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_CHECK_BOX_LIST);
            cui_menu_set_checkbox_state(evt->sender_id, nfc->hw_param.p2p_mode_protocol_list);
            break;

        case MENU_ID_EM_NFC_P2P_MODE_OPT:
            cui_menu_set_currlist_flags(evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
            cui_menu_set_radio_list_item(evt->sender_id, nfc->hw_param.p2p_mode_option+ MENU_ID_EM_NFC_P2P_OPT_DEFAULT);
            break;

        default:
            break;
            
    }
}

static void mmi_em_nfc_rd_stop_curr_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_nfc_struct *nfc = g_mmi_em_nfc;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_em_nfc_state.current_req)
    {
        case MSG_ID_NFC_READER_MODE_TEST_REQ:
            mmi_em_nfc_rd_reader_mode_req(nfc, MMI_EM_NFC_REQ_ACTION_STOP);
           break;

        case MSG_ID_NFC_CARD_EMULATION_MODE_TEST_REQ:
            mmi_em_nfc_rd_card_emu_mode_req(nfc, MMI_EM_NFC_REQ_ACTION_STOP);
            break;

        case MSG_ID_NFC_P2P_MODE_TEST_REQ:
            mmi_em_nfc_rd_p2p_mode_req(nfc, MMI_EM_NFC_REQ_ACTION_STOP);
            break;
            
        case MSG_ID_NFC_TX_ALWAYSON_TEST_REQ:
        case MSG_ID_NFC_TX_ALWAYSON_WO_ACK_TEST_REQ:
            mmi_em_nfc_rd_tx_on_req(0, 0, g_mmi_em_nfc_state.current_req, MMI_EM_NFC_REQ_ACTION_STOP);
            break;

        case MSG_ID_NFC_ANTENNA_SELF_TEST_REQ:
            mmi_em_nfc_rd_atenna_req(nfc, MMI_EM_NFC_REQ_ACTION_STOP);
            break;

        default:
          break;  
    }
    
}

static void mmi_em_nfc_rd_exit_nfc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_EM_NFC);
}

static void mmi_em_nfc_rd_genaral_rsp(nfc_script_response *rsp, MMI_ID progress_title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->sessionID != g_mmi_em_nfc_state.curren_session_id)
    {
        return;
    }

//    g_mmi_em_nfc_state.is_have_rsp = MMI_TRUE;

    if (g_mmi_em_nfc_state.curren_session_id == MMI_EM_NFC_REQ_SESSION_ID_START)
    {
        if (rsp->result == MTK_NFC_SUCCESS)
        {
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_CONFIG_SUCCESS, MMI_EVENT_SUCCESS);
        }
        else
        {
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_CONFIG_FAIL, MMI_EVENT_FAILURE);
            /*close progress screen*/
            mmi_em_nfc_start_req_progress_scrn_close();
        }
    }
    else
    {
        if (rsp->result != MTK_NFC_SUCCESS)
        {
            /*fail*/
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_FAIL, MMI_EVENT_FAILURE);
            mmi_em_nfc_stop_req_progress_scrn_close();
            if (!g_mmi_em_nfc_state.is_entering)
            {
                mmi_em_nfc_hw_test_start_req_show_progress(progress_title_id,
                                                    mmi_em_nfc_rd_exit_nfc,
                                                    mmi_em_nfc_rd_stop_curr_req);    
            }
        }
        else
        {
			mmi_em_nfc_stop_req_progress_scrn_close();
            g_mmi_em_nfc_state.pre_req_mode = (NFC_MSG_TYPE)0;
            if (g_mmi_em_nfc_state.is_entering)
            {
                mmi_em_nfc_enter_main_menu();
            }            
        }
    }
}

static void mmi_em_nfc_rd_reader_mode_req(mmi_em_nfc_struct *nfc, U32 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_reader_mode_request *req;
    U32 i;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_reader_mode_request));    
    newmsg->msg_type = MSG_ID_NFC_READER_MODE_TEST_REQ;
    newmsg->msg_length = sizeof(nfc_reader_mode_request);

    req = (nfc_reader_mode_request *)((newmsg + 1));
    req->action = action;
    req->type = 1;

    for (i = 0; i < MMI_EM_NFC_READER_MODE_PROTOCOLS_NUM; i++)
    {
        if (nfc->hw_param.reader_mode_protocol_list[i])
        {
            req->protocols |= g_mmi_em_nfc_rd_mode_param_ptl_table[i];
        }
    }

    if(action == MMI_EM_NFC_REQ_ACTION_START)
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_START;        
    }
    else
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_STOP;
    }
    g_mmi_em_nfc_state.curren_session_id = req->sessionID;
    MMI_EM_NFC_TRACE_4(MMI_EM_NFC_TRC_NUM_READER_MODE_REQ,
                        req->action,
                        req->type,
                        req->protocols,
                        req->sessionID);
    mmi_em_nfc_req(newmsg);

    if (action == MMI_EM_NFC_REQ_ACTION_START)
    {
        mmi_em_nfc_hw_test_start_req_show_progress(STR_ID_EM_NFC_RD_READER_MODE,
                                                    mmi_em_nfc_rd_exit_nfc,
                                                    mmi_em_nfc_rd_stop_curr_req);    
    }
    else
    {
        mmi_em_nfc_start_req_progress_scrn_close();
        mmi_em_nfc_stop_req_show_progress(STR_ID_EM_NFC_RD_READER_MODE);
    }

    g_mmi_em_nfc_state.pre_req_mode = MSG_ID_NFC_READER_MODE_TEST_REQ;
}

static void mmi_em_nfc_rd_reader_mode_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_script_response *rsp = (nfc_script_response *)msg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_2(MMI_EM_NFC_TRC_NUM_READER_MODE_RSP,
                        rsp->result,
                        rsp->sessionID);
    if (rsp->sessionID != g_mmi_em_nfc_state.curren_session_id)
    {
        return;
    }

    if (g_mmi_em_nfc_state.curren_session_id == MMI_EM_NFC_REQ_SESSION_ID_STOP)
    {
        if (rsp->result != MTK_NFC_SUCCESS)
        {
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_FAIL, MMI_EVENT_FAILURE);
            mmi_em_nfc_stop_req_progress_scrn_close();
            if (!g_mmi_em_nfc_state.is_entering)
            {
                mmi_em_nfc_hw_test_start_req_show_progress(STR_ID_EM_NFC_RD_READER_MODE,
                                                    mmi_em_nfc_rd_exit_nfc,
                                                    mmi_em_nfc_rd_stop_curr_req);    
            }                       
        }
        else
        {
            mmi_em_nfc_stop_req_progress_scrn_close();
            g_mmi_em_nfc_state.pre_req_mode = (NFC_MSG_TYPE)0;
            if (g_mmi_em_nfc_state.is_entering)
            {
                mmi_em_nfc_enter_main_menu();
            }
        }
    }
    else
    {
        if (rsp->result == MTK_NFC_SUCCESS)
        {
            /*success*/
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_SUCCESS, MMI_EVENT_SUCCESS);
        }
        else
        {
            /*fail*/
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_FAIL, MMI_EVENT_FAILURE);
        }
    }
}


static void mmi_em_nfc_rd_card_emu_mode_req(mmi_em_nfc_struct *nfc, U32 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_card_emulation_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_card_emulation_request));    
    newmsg->msg_type = MSG_ID_NFC_CARD_EMULATION_MODE_TEST_REQ;
    newmsg->msg_length = sizeof(nfc_card_emulation_request);

    req = (nfc_card_emulation_request *)((newmsg + 1));
    req->action = action;

    if(action == MMI_EM_NFC_REQ_ACTION_START)
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_START;        
    }
    else
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_STOP;
    }
    g_mmi_em_nfc_state.curren_session_id = req->sessionID;
    g_mmi_em_nfc_state.current_req = MSG_ID_NFC_CARD_EMULATION_MODE_TEST_REQ;
    req->type = nfc->hw_param.card_mode_se  + 1; /*1~3*/

    MMI_EM_NFC_TRACE_3(MMI_EM_NFC_TRC_NUM_CARD_EMU_MODE_REQ,
                        req->type,
                        req->action,
                        req->sessionID);
                      
    mmi_em_nfc_req(newmsg);
    if (action == MMI_EM_NFC_REQ_ACTION_START)
    {
        mmi_em_nfc_hw_test_start_req_show_progress(STR_ID_EM_NFC_RD_CARD_EMU_MODE,
                                                    mmi_em_nfc_rd_exit_nfc,
                                                    mmi_em_nfc_rd_stop_curr_req);    
    }
    else
    {
        mmi_em_nfc_start_req_progress_scrn_close();
        mmi_em_nfc_stop_req_show_progress(STR_ID_EM_NFC_RD_CARD_EMU_MODE);        
    }

    g_mmi_em_nfc_state.pre_req_mode = MSG_ID_NFC_CARD_EMULATION_MODE_TEST_REQ;
    
}


static void mmi_em_nfc_rd_card_emu_mode_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_script_response *rsp = (nfc_script_response *)msg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_2(MMI_EM_NFC_TRC_NUM_CARD_EMU_MODE_RSP,
                        rsp->result,
                        rsp->sessionID);
    mmi_em_nfc_rd_genaral_rsp(rsp, STR_ID_EM_NFC_RD_CARD_EMU_MODE); 
}



static void mmi_em_nfc_rd_p2p_mode_req(mmi_em_nfc_struct *nfc, U32 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_p2p_request *req;
    U32 i;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_p2p_request));    
    newmsg->msg_type = MSG_ID_NFC_P2P_MODE_TEST_REQ;
    newmsg->msg_length = sizeof(nfc_p2p_request);

    req = (nfc_p2p_request *)((newmsg + 1));
    req->action = action;

    if(action == MMI_EM_NFC_REQ_ACTION_START)
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_START;        
    }
    else
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_STOP;
    }
    g_mmi_em_nfc_state.curren_session_id = req->sessionID;

    req->P2Pmode = g_mmi_em_nfc_p2p_mode_type_value_tble[nfc->hw_param.p2p_mode_option];

    for (i = 0; i< MMI_EM_NFC_P2P_MODE_PROTOCOLS_NUM; i++)
    {
        if (nfc->hw_param.p2p_mode_protocol_list[i])
        {
            req->protocols |= g_mmi_em_nfc_p2p_mode_param_ptl_table[i];
        }
    }
    req->type = 1;

    MMI_EM_NFC_TRACE_3(MMI_EM_NFC_TRC_NUM_P2P_MODE_REQ,
                        req->P2Pmode,
                        req->action,
                        req->sessionID);
    
    mmi_em_nfc_req(newmsg);
    if (action == MMI_EM_NFC_REQ_ACTION_START)
    {
        mmi_em_nfc_hw_test_start_req_show_progress(STR_ID_EM_NFC_RD_P2P_MODE,
                                                    mmi_em_nfc_rd_exit_nfc,
                                                    mmi_em_nfc_rd_stop_curr_req);    
    }
    else
    {
        mmi_em_nfc_start_req_progress_scrn_close();
        mmi_em_nfc_stop_req_show_progress(STR_ID_EM_NFC_RD_P2P_MODE);        
    }

    g_mmi_em_nfc_state.pre_req_mode = MSG_ID_NFC_P2P_MODE_TEST_REQ;
    
}


static void mmi_em_nfc_rd_p2p_mode_rsp(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_script_response *rsp = (nfc_script_response *)msg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_2(MMI_EM_NFC_TRC_NUM_P2P_MODE_RSP,
                        rsp->result,
                        rsp->sessionID);
    mmi_em_nfc_rd_genaral_rsp(rsp, STR_ID_EM_NFC_RD_P2P_MODE);       
}

static void mmi_em_nfc_rd_tx_on_with_ask_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID inline_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create_ex(GRP_ID_EM_NFC,
                                        GRP_ID_AUTO_GEN,
                                        mmi_em_nfc_rd_tx_on_inline_proc,
                                        NULL,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(group_id, &g_mmi_em_nfc_rd_tx_screen);
    cui_inline_run(inline_id);
}


static MMI_RET mmi_em_nfc_rd_tx_on_inline_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            U32 mode_type = 0;
            U32 bit_rate = 0;
            cui_inline_get_value(inline_evt->sender_id, MMI_EM_NFC_INLINE_SELECT_2,&bit_rate);
            cui_inline_get_value(inline_evt->sender_id, MMI_EM_NFC_INLINE_SELECT_1,&mode_type);
            mmi_em_nfc_rd_tx_on_req(mode_type,
                                        bit_rate,
                                        MSG_ID_NFC_TX_ALWAYSON_TEST_REQ,
                                        MMI_EM_NFC_REQ_ACTION_START);            
            cui_inline_close(inline_evt->sender_id);
            break;
        }            

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(inline_evt->sender_id);
            break;
          
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_em_nfc_rd_tx_on_req(U32 mode_type, U32 bit_rate, NFC_MSG_TYPE msg_type, U32 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_tx_alwayson_request *req;
    U16 title_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_tx_alwayson_request));
    newmsg->msg_type = msg_type;

    newmsg->msg_length = sizeof(nfc_tx_alwayson_request);
    req = (nfc_tx_alwayson_request *)(newmsg + 1);
    req->type = 1;
    req->modulation_type = mode_type;
    req->bitrate = bit_rate;
    req->action = action;
    if(action == MMI_EM_NFC_REQ_ACTION_START)
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_START;        
    }
    else
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_STOP;
    }
    g_mmi_em_nfc_state.curren_session_id = req->sessionID;
    
    MMI_EM_NFC_TRACE_2(MMI_EM_NFC_TRC_NUM_TX_ON_REQ,
                        req->action,
                        req->sessionID); 
    mmi_em_nfc_req(newmsg);
    if (msg_type == MSG_ID_NFC_TX_ALWAYSON_TEST_REQ)
    {
        title_id = STR_ID_EM_NFC_RD_TX_ON_WITH_ASK;
    }
    else
    {
        title_id = STR_ID_EM_NFC_RD_TX_ON_WO_ASK;
    }
    
    if (action == MMI_EM_NFC_REQ_ACTION_START)
    {
        mmi_em_nfc_hw_test_start_req_show_progress(title_id,
                                                    mmi_em_nfc_rd_exit_nfc,
                                                    mmi_em_nfc_rd_stop_curr_req);    
    }
    else
    {
        mmi_em_nfc_start_req_progress_scrn_close();
        mmi_em_nfc_stop_req_show_progress(title_id);        
    }

    g_mmi_em_nfc_state.pre_req_mode = msg_type;
}

static void mmi_em_nfc_rd_tx_on_wo_ask_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_script_response *rsp = (nfc_script_response *)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_2(MMI_EM_NFC_TRC_NUM_TX_ON_WO_ASK_RSP,
                        rsp->result, 
                        rsp->sessionID);
    mmi_em_nfc_rd_genaral_rsp(rsp, STR_ID_EM_NFC_RD_TX_ON_WO_ASK);
}

static void mmi_em_nfc_rd_tx_on_with_ask_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_script_response *rsp = (nfc_script_response *)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_2(MMI_EM_NFC_TRC_NUM_TX_ON_WITH_ASK_RSP,
                        rsp->result, 
                        rsp->sessionID);
    mmi_em_nfc_rd_genaral_rsp(rsp, STR_ID_EM_NFC_RD_TX_ON_WITH_ASK);
}

static void mmi_em_nfc_rd_atenna_test_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;
    MMI_ID inline_id;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_frm_group_create_ex(GRP_ID_EM_NFC,
                                        GRP_ID_AUTO_GEN,
                                        mmi_em_nfc_rd_atenna_test_proc,
                                        NULL,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(group_id, &g_mmi_em_nfc_antenna_test_inline_scrn);
    cui_inline_run(inline_id);
}

static MMI_RET mmi_em_nfc_rd_atenna_test_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    cui_event_inline_common_struct* evt = (cui_event_inline_common_struct*) param;
    mmi_em_nfc_struct *nfc = (mmi_em_nfc_struct *)g_mmi_em_nfc;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_CUI_INLINE_SUBMIT:
            for ( i = 0; i< 4; i++)
            {
                S32 value;
                WCHAR buffer[MMI_EM_NFC_ANTENNA_TEST_PARAM_TEXT_LEN + 1];
                cui_inline_get_value(evt->sender_id, MMI_EM_NFC_INLINE_ANTENNA_TEST_EDIT_1 + i,(void *)buffer);
                value = mmi_wcs_wtoi(buffer);
                nfc->antenna_param[i] = (value > 255 ? 255 : (U8)value);
            }
            cui_inline_close(evt->sender_id);
            mmi_em_nfc_rd_atenna_req(nfc, MMI_EM_NFC_REQ_ACTION_START);
            break;

        case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(evt->sender_id);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}



static void mmi_em_nfc_rd_atenna_req(mmi_em_nfc_struct *nfc, U32 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_antenna_request *req;
    U32 i;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_antenna_request));    
    newmsg->msg_type = MSG_ID_NFC_ANTENNA_SELF_TEST_REQ;
    newmsg->msg_length = sizeof(nfc_antenna_request);

    req = (nfc_antenna_request *)((newmsg + 1));
    req->action = action;
    for (i = 0; i< 4; i++)
    {
        req->param[i] = nfc->antenna_param[i];
    }
    if(action == MMI_EM_NFC_REQ_ACTION_START)
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_START;        
    }
    else
    {
        req->sessionID = MMI_EM_NFC_REQ_SESSION_ID_STOP;
    }
    g_mmi_em_nfc_state.curren_session_id = req->sessionID;
    mmi_em_nfc_req(newmsg);
    if (action == MMI_EM_NFC_REQ_ACTION_START)
    {
        mmi_em_nfc_hw_test_start_req_show_progress(STR_ID_EM_NFC_RD_ANTANNA_TEST,
                                                    0,
                                                    mmi_em_nfc_rd_stop_curr_req);    
    }
    else
    {
        mmi_em_nfc_start_req_progress_scrn_close();
        mmi_em_nfc_stop_req_show_progress(STR_ID_EM_NFC_RD_ANTANNA_TEST);        
    }
}

static void mmi_em_nfc_rd_atenna_rsp(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_script_response *rsp = (nfc_script_response *)msg;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EM_NFC_TRACE_2(MMI_EM_NFC_TRC_NUM_ANTENNA_TEST_RSP,
                        rsp->result, 
                        rsp->sessionID);
    if (rsp->sessionID != g_mmi_em_nfc_state.curren_session_id)
    {
        return;
    }

//    g_mmi_em_nfc_state.is_have_rsp = MMI_TRUE;

    if (g_mmi_em_nfc_state.curren_session_id == MMI_EM_NFC_REQ_SESSION_ID_START)
    {
        if (rsp->result == MTK_NFC_SUCCESS)
        {
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_SUCCESS, MMI_EVENT_SUCCESS);
        }
        else
        {
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_FAIL, MMI_EVENT_FAILURE);
        }
        /*close progress screen*/
        mmi_em_nfc_start_req_progress_scrn_close();
    }
    else
    {
        if (rsp->result != MTK_NFC_SUCCESS)
        {
            /*fail*/
            mmi_em_nfc_popup_by_str(STR_ID_EM_NFC_FAIL, MMI_EVENT_FAILURE);
            mmi_em_nfc_stop_req_progress_scrn_close();
            mmi_em_nfc_hw_test_start_req_show_progress(STR_ID_EM_NFC_RD_ANTANNA_TEST,
                                                    0,
                                                    mmi_em_nfc_rd_stop_curr_req);
        }
        else
        {
			mmi_em_nfc_stop_req_progress_scrn_close();
        }
    }
}

#define NFC_EXIT_EM
/*****************************************************************************
 * FUNCTION
 *  mmi_em_nfc_exit_em_req
 * DESCRIPTION
 *  when em nfc exit, send exit message to NFC driver
 * PARAMETERS
 *  type    [IN] 0:  EM normal exit,1: EM background exit
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_nfc_exit_em_req(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_msg_struct *newmsg;
    nfc_exit_request *req;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newmsg = OslConstructDataPtr(sizeof(nfc_msg_struct) + sizeof(nfc_exit_request));    
    newmsg->msg_type = MSG_ID_NFC_EXIT_EMFM;
    newmsg->msg_length = sizeof(nfc_exit_request);

    req = (nfc_exit_request *)((newmsg + 1));
    req->type = type;
    mmi_em_nfc_req(newmsg);
}


#endif  /*defined(__MMI_EM_NFC_SUPPORT__)*/
