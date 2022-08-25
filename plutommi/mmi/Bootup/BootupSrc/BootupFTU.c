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
 *  BootupFTU.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  FTU prompt of bootup app part.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "BootupAppGprot.h"
#include "BootupAppProt.h"
#include "MMIDataType.h"
#include "BootupSrvGprot.h"
#include "kal_general_types.h"
#include "BootupScrUtil.h"
#include "mmi_rp_app_bootup_def.h"
#include "kal_public_api.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "BootupSrvIprot.h"
#include "custom_events_notify.h"
#include "ProfilesSrvGprot.h"
#include "GlobalConstants.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "ProcedureGprot.h"


#ifdef __MMI_BT_DIALER_SUPPORT__
#include "mmi_rp_app_bluetooth_def.h"


static mmi_frm_proc_id_info_struct g_id_info;
static void mmi_bt_dialer_ask_first(void);
static void mmi_bt_dialer_ftu_lsk();


mmi_frm_proc_result_enum mmi_bootup_flow_ftu(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 first_boot = 0;
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_FTU_FLOW);

    if(srv_bootup_is_auto_power_on_test() == MMI_FALSE)
    {
        ReadValue(NVRAM_BT_DIALER_FIRST_BOOT, &first_boot, DS_SHORT, &error);
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_FTU_FLOW_FIRST_BOOT_FLAG,first_boot);
        if (!first_boot) // is ftu
        {
            g_id_info = id_info;
            mmi_bt_dialer_ask_first();            
            
            return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
        }
    }
  
    return MMI_FRM_PROC_RESULT_COMPLETED;
}

U16 ui_buf[400];

void mmi_bt_dialer_ask_first(void)
{
    mmi_id parent_id;
    S32 ui_buffer_size;
    U8* guiBuffer;

    parent_id =  mmi_frm_group_get_active_id();
    if(mmi_frm_scrn_enter(
                parent_id,
                SCR_BT_DIALER_FRIST_ASK,
                (FuncPtr) NULL,
                (FuncPtr) mmi_bt_dialer_ask_first,
                MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        
        MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_FTU_FLOW_SCR_FAIL);        
        return;
    }

    mmi_wcscpy(ui_buf, (WCHAR *) GetString(STR_BT_DIALER_HELP_CONTENT));
#ifdef __MMI_BT_REMOTE_CAPTURE__
    mmi_wcscat(ui_buf, (WCHAR *) GetString(STR_BT_REMOTE_CAPTURE_INFO));
#endif
#ifdef __MMI_BT_ANTI_LOST_BY_RSSI__
    mmi_wcscat(ui_buf, (WCHAR *) GetString(STR_BT_ANTI_LOST_INFO));
#endif
    mmi_wcscat(ui_buf, (WCHAR *) GetString(STR_BT_DIALER_ETC));
    mmi_wcscat(ui_buf, (WCHAR *) L"\n");

    ui_buffer_size = mmi_wcslen(ui_buf);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory74Screen(
                STR_ID_BT_DIALER,
                0,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                0,
                0,
                (U8*) ui_buf,
                ui_buffer_size,
                guiBuffer);


    SetLeftSoftkeyFunction(mmi_bt_dialer_ftu_lsk, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_dialer_ftu_lsk, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

}

void mmi_bt_dialer_ftu_lsk()
{
	S16 error;
    S32 first_boot = 1;
    SetFlashNVRAMCatchData(DS_SHORT, MMI_FALSE);
    WriteValue(NVRAM_BT_DIALER_FIRST_BOOT, &first_boot, DS_SHORT, &error);
    SetFlashNVRAMCatchData(DS_SHORT, MMI_TRUE);
    
    MMI_TRACE(MMI_BOOTUP_TRC_GROUP, TRC_MMI_FTU_FLOW_OK);    
    mmi_frm_scrn_close_active_id ();
    mmi_frm_proc_notify_completed(g_id_info);
}
#endif


