/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * TetheringAppDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Tethering application definations.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *
 *****************************************************************************/
#ifndef _TETHERING_APP_DEF_H
#define _TETHERING_APP_DEF_H
#include "mmi_features.h"
#ifdef __MMI_TETHERING__
#include "MMIDataType.h"
#include "TetheringSrvIprot.h"
#include "TetheringSrvGprot.h"
#include "InlineCuiGprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef enum
{
    TETHERING_WIFI_INLINE_ITEM_SWITCH_CAP = CUI_INLINE_ITEM_ID_BASE,
    TETHERING_WIFI_INLINE_ITEM_SWITCH_SEL,
    TETHERING_WIFI_INLINE_ITEM_AUTO_TURN_OFF_CAP,
    TETHERING_WIFI_INLINE_ITEM_AUTO_TURN_OFF_SEL,
    TETHERING_WIFI_INLINE_ITEM_SSID_CAP,
    TETHERING_WIFI_INLINE_ITEM_SSID_EDIT,
    TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_CAP,
    TETHERING_WIFI_INLINE_ITEM_AUTH_MODE_SEL,
    TETHERING_WIFI_INLINE_ITEM_PSK_CAP,
    TETHERING_WIFI_INLINE_ITEM_PSK_EDIT,
    TETHERING_WIFI_INLINE_ITEM_TOTAL
} tethering_wifi_inline_item_enum;

typedef enum
{
    TETHERING_CONN_INFO_INLINE_ITEM_USED_SIM_CAP = CUI_INLINE_ITEM_ID_BASE,
    TETHERING_CONN_INFO_INLINE_ITEM_USED_SIM_DISPLAY,
    TETHERING_CONN_INFO_INLINE_ITEM_PROXY_CAP,
    TETHERING_CONN_INFO_INLINE_ITEM_PROXY_DISPLAY,
    TETHERING_CONN_INFO_INLINE_ITEM_APN_CAP,
    TETHERING_CONN_INFO_INLINE_ITEM_APN_DISPLAY,
    TETHERING_CONN_INFO_INLINE_ITEM_WIFI_HS_STA_NUM_CAP,
    TETHERING_CONN_INFO_INLINE_ITEM_WIFI_HS_STA_NUM_DISPLAY,
    TETHERING_CONN_INFO_INLINE_ITEM_USB_STATUS_CAP,
    TETHERING_CONN_INFO_INLINE_ITEM_USB_STATUS_DISPLAY,
    TETHERING_CONN_INFO_INLINE_ITEM_TOTAL
} tethering_conn_info_inline_item_enum;


typedef enum
{
    TETHERING_WIFI_SETTINGS_SWITCH_ITEM_OFF,
    TETHERING_WIFI_SETTINGS_SWITCH_ITEM_ON,
    TETHERING_WIFI_SETTINGS_SWITCH_ITEM_END
} tethering_wifi_settings_switch_item_enum;

typedef enum
{
    TETHERING_WIFI_SETTINGS_AUTO_TURN_OFF_ITEM_OFF,
    TETHERING_WIFI_SETTINGS_AUTO_TURN_OFF_ITEM_ON,
    TETHERING_WIFI_SETTINGS_AUTO_TURN_OFF_ITEM_END
} tethering_wifi_settings_auto_turn_off_item_enum;

typedef struct
{
    srv_tethering_wifi_hs_settings_struct srv_wifi_hs_settings;
    MMI_BOOL is_switch_on;
} mmi_tethering_wifi_hs_settings_struct;

typedef struct
{
    U32 data_account_id;
    MMI_ID data_account_cui_id;
} mmi_tethering_dtcnt_info_struct;

typedef struct
{
    WCHAR w_used_sim_str[32];
    WCHAR w_proxy_info_str[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];
    WCHAR w_apn_str[SRV_DTCNT_PROF_MAX_APN_LEN + 1];
    WCHAR w_sta_num_str[32];
} mmi_tethering_conn_info_inline_items_display_struct;

typedef struct
{
    MMI_ID main_scr_cui_menu_id;
    MMI_ID wifi_hs_settings_scr_cui_inline_id;
    MMI_ID conn_info_cui_inline_id;
    MMI_ID waiting_screen_id;
    mmi_tethering_wifi_hs_settings_struct *wifi_hs_temp_settings;
    mmi_tethering_dtcnt_info_struct *dtcnt_info;
    mmi_tethering_conn_info_inline_items_display_struct *conn_info_display;
    WCHAR *ssid_display_buf;
    WCHAR *ssid_edit_buf;
} mmi_tethering_cntx_struct;
#endif /* __MMI_TETHERING__ */
#endif /* _TETHERING_APP_DEF_H */ 

