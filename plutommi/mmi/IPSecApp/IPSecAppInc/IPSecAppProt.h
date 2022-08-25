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
 * IPSecAppProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines constant, enum values, structure, and function prototypes for IPSec MMI settings application.
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
 *==============================================================================
 *******************************************************************************/

#ifndef IPSECAPPPORT_H
#define IPSECAPPPORT_H
#include "MMI_features.h"
#ifdef __MMI_IPSEC__

#include "kmp_app.h"
#include "InlineCuiGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_touch_screen.h"
/*---------------------------------------------------------------------------*/
/* Definition */
/*---------------------------------------------------------------------------*/
#define PRT_MMI_IPSEC_INIT_REQ          MSG_ID_APP_KMP_INIT_REQ
#define PRT_MMI_IPSEC_INIT_RSP          MSG_ID_APP_KMP_INIT_CNF
#define PRT_MMI_IPSEC_ALG_REQ           MSG_ID_APP_KMP_ALG_REQ
#define PRT_MMI_IPSEC_ALG_RSP           MSG_ID_APP_KMP_ALG_CNF
#define PRT_MMI_IPSEC_ADDR_REQ          MSG_ID_APP_KMP_ADDR_REQ
#define PRT_MMI_IPSEC_ADDR_RSP          MSG_ID_APP_KMP_ADDR_CNF
#define PRT_MMI_IPSEC_ACTIVATE_REQ      MSG_ID_APP_KMP_ACTIVE_REQ
#define PRT_MMI_IPSEC_ACTIVATE_RSP      MSG_ID_APP_KMP_ACTIVE_CNF
#define PRT_MMI_IPSEC_ADD_POLICY_REQ    MSG_ID_APP_KMP_POLICY_ADD_REQ
#define PRT_MMI_IPSEC_ADD_POLICY_RSP    MSG_ID_APP_KMP_POLICY_ADD_CNF
#define PRT_MMI_IPSEC_DEL_POLICY_REQ    MSG_ID_APP_KMP_POLICY_DEL_REQ
#define PRT_MMI_IPSEC_DEL_POLICY_RSP    MSG_ID_APP_KMP_POLICY_DEL_CNF
#define PRT_MMI_IPSEC_DEACTIVATE_REQ    MSG_ID_APP_KMP_DEACTIVE_REQ
#define PRT_MMI_IPSEC_DEACTIVATE_RSP    MSG_ID_APP_KMP_DEACTIVE_CNF
#define PRT_MMI_IPSEC_SETTING_OK_REQ    MSG_ID_IKE_SETTING_OK_REQ

#define MMI_IPSEC_MAX_PORT_LEN          5
#define MMI_IPSEC_MAX_ADDR_LEN          16   /* KMP_ADDR_LEN */
#define MMI_IPSEC_MAX_KEY_LEN           32   /* KMP_KEYMAX_SIZE */
#define MMI_IPSEC_MAX_PROFILE_NUM       3
#define MMI_IPSEC_MAX_NUM_STRING_LEN    5
#define MMI_IPSEC_MAX_PROF_NAME_LEN     20

#define NVRAM_MAX_IPSEC_PROFILE_NUM     MMI_IPSEC_MAX_PROFILE_NUM
#define MMI_IPSEC_MAX_PORT_NUM          65535


#define MMI_IPSEC_DEFAULT_DHGROUP_LEN       (96)
#define MMI_IPSEC_DEFAULT_PREFIX_LEN        (32)
#define MMI_IPSEC_DEFAULT_PKEY_LEN          (192)
#define MMI_IPSEC_DEFAULT_PROTOCOL          (255)
#define MMI_IPSEC_DEFAULT_LIFETIME_SEC      (28800)
#define MMI_IPSEC_DEFAULT_LIFETIME_BYTE     (9999)
#define MMI_IPSEC_DEFAULT_SA_LIFETIME_BYTE  (99999)
#define MMI_IPSEC_DEFAULT_SA_DATA           (500)
#define MMI_IPSEC_AF_INET                   (2)

/* Screen Populate Enum */
typedef enum
{
    MMI_IPSEC_POLICY_SRC_PORT_CAP = CUI_INLINE_ITEM_ID_BASE,
    MMI_IPSEC_POLICY_SRC_PORT,
    MMI_IPSEC_POLICY_SRC_ADDR_CAP,
    MMI_IPSEC_POLICY_SRC_ADDR,
    MMI_IPSEC_POLICY_DEST_PORT_CAP,
    MMI_IPSEC_POLICY_DEST_PORT,
    MMI_IPSEC_POLICY_DEST_ADDR_CAP,
    MMI_IPSEC_POLICY_DEST_ADDR,
#ifdef __MMI_IPSEC_TUNNEL_MODE__
    MMI_IPSEC_POLICY_MODE_CAP,
    MMI_IPSEC_POLICY_MODE,
    MMI_IPSEC_POLICY_TUNNEL_PORT_CAP,
    MMI_IPSEC_POLICY_TUNNEL_PORT,
    MMI_IPSEC_POLICY_TUNNEL_ADDR_CAP,
    MMI_IPSEC_POLICY_TUNNEL_ADDR,
#endif /* __MMI_IPSEC_TUNNEL_MODE__ */
    MMI_IPSEC_POLICY_ALG,
    MMI_IPSEC_POLICY_TOTAL_ITEM
} mmi_ipsec_policy_item_enum;

typedef enum
{
    MMI_IPSEC_IKE_PRESHARED_KEY_CAP = CUI_INLINE_ITEM_ID_BASE,
    MMI_IPSEC_IKE_PRESHARED_KEY,
    MMI_IPSEC_IKE_AUTH_METHOD_CAP,
    MMI_IPSEC_IKE_AUTH_METHOD,
    MMI_IPSEC_IKE_ENC_METHOD_CAP,
    MMI_IPSEC_IKE_ENC_METHOD,
    MMI_IPSEC_IKE_DH_METHOD_CAP,
    MMI_IPSEC_IKE_DH_METHOD,
    MMI_IPSEC_IKE_TOTAL_ITEM
} mmi_ipsec_ike_item_enum;

typedef enum
{
    MMI_IPSEC_ALG_AH_AUTH_CAP = CUI_INLINE_ITEM_ID_BASE,
    MMI_IPSEC_ALG_AH_AUTH,
    MMI_IPSEC_ALG_ESP_AUTH_CAP,
    MMI_IPSEC_ALG_ESP_AUTH,
    MMI_IPSEC_ALG_ESP_ENC_CAP,
    MMI_IPSEC_ALG_ESP_ENC,
    MMI_IPSEC_ALG_TOTAL_ITEM
} mmi_ipsec_alg_item_enum;

typedef enum
{
    MMI_IPSEC_PROF_POLICY,
    MMI_IPSEC_PROF_IKE,
    MMI_IPSEC_PROF_TOTAL
} mmi_ipsec_prof_scr_enum;

/* Enum for Inline Items Selection */
typedef enum
{
    MMI_IPSEC_MODE_TUNNEL,
    MMI_IPSEC_MODE_TRANSPORT,
    MMI_IPSEC_MODE_TOTAL_ITEM
} mmi_ipsec_mode_item_enum;

typedef enum
{
    MMI_IPSEC_AUTH_MD5,
    MMI_IPSEC_AUTH_SHA1,
    MMI_IPSEC_AUTH_NONE,
    MMI_IPSEC_AUTH_TOTAL_ITEM
} mmi_ipsec_auth_item_enum;

typedef enum
{
    MMI_IPSEC_ENC_DES,
    MMI_IPSEC_ENC_3DES,
    MMI_IPSEC_ENC_NONE,
    MMI_IPSEC_ENC_TOTAL_ITEM
} mmi_ipsec_enc_item_enum;

typedef enum
{
    MMI_IPSEC_DH_MODP768,
    MMI_IPSEC_DH_MODP1024,
    MMI_IPSEC_DH_TOTAL_ITEM
} mmi_ipsec_dh_item_enum;

typedef enum
{
    MMI_IPSEC_STATUS_ACTIVATING,
    MMI_IPSEC_STATUS_DEACTIVATING,
    MMI_IPSEC_STATUS_ACTIVATION_FAIL, /* of no use currently */
    MMI_IPSEC_STATUS_DEACTIVATION_FAIL, /* of no use currently */
    MMI_IPSEC_STATUS_LOCALSETTINGS,
    MMI_IPSEC_STATUS_TOTAL_NUM
}mmi_ipsec_working_status_enum;
/*--------------------------------------------------------------------------*/
/* Struct */
/*---------------------------------------------------------------------------*/
typedef struct
{
    U16                         src_port;
    U8                          src_addr[4];
    U16                         dest_port;
    U8                          dest_addr[4];
    mmi_ipsec_mode_item_enum    ipsec_mode;
    U16                         tunnel_port;
    U8                          tunnel_addr[4];
    S32                         alg_ah_auth;
    S32                         alg_esp_auth;
    S32                         alg_esp_enc;
} mmi_ipsec_policy_struct;

typedef struct
{
    S32                         alg_ah_auth;
    S32                         alg_esp_auth;
    S32                         alg_esp_enc;
} mmi_ipsec_policy_ike_struct;

typedef struct
{
    WCHAR                       preshared_key[MMI_IPSEC_MAX_KEY_LEN + 1];
    S32                         auth_method;
    S32                         enc_method;
    S32                         dh_method;
} mmi_ipsec_ike_struct;

typedef struct
{
    WCHAR                       prof_name[MMI_IPSEC_MAX_PROF_NAME_LEN + 1];
    mmi_ipsec_policy_struct     policy_settings;
    mmi_ipsec_ike_struct        ike_settings;
} mmi_ipsec_profile_struct;

typedef struct
{
    MMI_STR_ID ipsec_mode[MMI_IPSEC_MODE_TOTAL_ITEM];
    MMI_STR_ID auth_method[MMI_IPSEC_AUTH_TOTAL_ITEM];
    MMI_STR_ID enc_method[MMI_IPSEC_ENC_TOTAL_ITEM];
    MMI_STR_ID dh_method[MMI_IPSEC_DH_TOTAL_ITEM];
} mmi_ipsec_profile_misc_struct;

typedef struct
{
    mmi_ipsec_profile_struct        profiles[MMI_IPSEC_MAX_PROFILE_NUM];
    S32                             profile_selected;
    MMI_BOOL                        activated;
    S32                             activated_index;

    mmi_ipsec_policy_ike_struct     policy_ike_temp;
    //mmi_ipsec_policy_struct         policy_edit;
    //mmi_ipsec_ike_struct            ike_edit;
    
    mmi_ipsec_profile_misc_struct   prof_misc;
    mmi_ipsec_working_status_enum   working_status;

    MMI_ID                          cui_option_menu_id;
    MMI_ID                          cui_rename_editor_id;
    MMI_ID                          cui_policy_inline_id;
    MMI_ID                          cui_policy_alg_inline_id;
    MMI_ID                          cui_ike_inline_id;
} mmi_ipsec_context_struct;


/*---------------------------------------------------------------------------*/
/* Variables */
/*---------------------------------------------------------------------------*/
extern mmi_ipsec_context_struct *g_ipsec_cntx_p;

/*---------------------------------------------------------------------------*/
/* Prototypes */
/*---------------------------------------------------------------------------*/
extern void mmi_ipsec_launch(void);
extern mmi_ret mmi_ipsec_scr_group_proc(mmi_event_struct *evt);
extern void mmi_ipsec_policy_inline_proc(mmi_group_event_struct *evt);
extern void mmi_ipsec_policy_alg_inline_proc(mmi_group_event_struct *evt);
extern void mmi_ipsec_ike_inline_proc(mmi_group_event_struct *evt);

extern void mmi_ipsec_hilite_main(void);
extern void mmi_ipsec_hilite_prof_list(S32 item_index);

extern void mmi_ipsec_entry_prof_list(void);
extern void mmi_ipsec_entry_prof_list_opt(void);
extern void mmi_ipsec_entry_prof_policy(void);
extern void mmi_ipsec_entry_prof_policy_alg(void);
extern void mmi_ipsec_entry_prof_ike(void);
extern void mmi_ipsec_entry_progressing(void);
extern void mmi_ipsec_entry_prof_rename(void);
extern void mmi_ipsec_read_prof_policy(void);
extern void mmi_ipsec_read_prof_ike(void);
extern void mmi_ipsec_prof_pre_entry_prof_list(void);
extern void mmi_ipsec_prof_pre_entry_prof_policy(void);
extern void mmi_ipsec_prof_pre_entry_prof_ike(void);

extern void mmi_ipsec_save_prof_policy(void);
extern void mmi_ipsec_save_prof_policy_confirm(void);
extern void mmi_ipsec_save_prof_policy_alg(void);
extern void mmi_ipsec_save_prof_ike(void);
extern void mmi_ipsec_save_prof_ike_confirm(void);
extern void mmi_ipsec_save_prof_name(void);

extern void mmi_ipsec_init_req(void);
extern void mmi_ipsec_init_rsp(void *inMsg);
extern void mmi_ipsec_alg_req(void);
extern void mmi_ipsec_alg_rsp(void *inMsg);
extern void mmi_ipsec_addr_req(void);
extern void mmi_ipsec_addr_rsp(void *inMsg);
extern void mmi_ipsec_activate_req(void);
extern void mmi_ipsec_activate_rsp(void *inMsg);
extern void mmi_ipsec_policy_req(void);
extern void mmi_ipsec_policy_rsp(void *inMsg);
extern void mmi_ipsec_deactivate_req(void);
extern void mmi_ipsec_deactivate_rsp(void *inMsg);

extern void mmi_ipsec_write_a_profile_on_NVRAM(void);
extern void mmi_ipsec_read_a_profile_on_NVRAM(void);

extern void mmi_ipsec_display_confirm(U16 strId, FuncPtr lskFuncs, FuncPtr rskFuns);
extern void mmi_ipsec_prof_go_back_to_edit_menu(void);

extern void mmi_ipsec_prof_activate(void);
extern void mmi_ipsec_prof_reactivate(void);
extern void mmi_ipsec_prof_deactivate(void);
extern void mmi_ipsec_show_popup_screen(WCHAR* string, mmi_event_notify_enum event_id);
#ifdef __MMI_FTE_SUPPORT__
extern void mmi_ipsec_fte_prof_list_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /* __MMI_FTE_SUPPORT__ */
extern void mmi_ipsec_prof_list_csk_hdlr(void);

#endif /* __MMI_IPSEC__ */
#endif /* IPSECAPPPORT_H */

