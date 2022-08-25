/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  EngineerModeCnmgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode connection management related items, inlcudes:
 *     - Set SCRI check time
 *     - Unset SCRI check time
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/************************************************************
 * Include
 ************************************************************/
#include "MMI_include.h"
#include "MMI_features.h"

#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__

#include "MMIDataType.h"
#include "menucuigprot.h"
#include "EngineerModeUtil.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCnmgr.h"
#include "CnmgrSrvGprot.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "Wgui_categories_util.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "common_nvram_editor_data_item.h"


/************************************************************
 * Global Variable
 ************************************************************/
static mmi_em_cnmgr_context_struct g_mmi_em_cnmgr_cntx;


/************************************************************
 * Static function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_em_cnmgr_scri_set_main_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  menu_evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_cnmgr_scri_set_main_menu(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR hint_data[MMI_EM_CNMGR_NUMBER_LEN] = {0};
    MMI_ID owner_id = menu_evt->sender_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* set flag */
    cui_menu_set_currlist_flags(owner_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    /* set LSK */
    cui_menu_set_currlist_left_softkey(owner_id, (WCHAR*)get_string(STR_GLOBAL_OK));

    /* set CSK */
    cui_menu_enable_center_softkey(owner_id, 0, IMG_GLOBAL_COMMON_CSK);

    /* set hint data */
    kal_wsprintf(hint_data, "%ds", g_mmi_em_cnmgr_cntx.check_time[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON].interval);
    cui_menu_set_item_hint(owner_id, MENU_ID_EM_GPRS_CNMGR_SCRI_LCD_ON_CHECK_TIME, hint_data);
    kal_wsprintf(hint_data, "%ds", g_mmi_em_cnmgr_cntx.check_time[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF].interval);
    cui_menu_set_item_hint(owner_id, MENU_ID_EM_GPRS_CNMGR_SCRI_LCD_OFF_CHECK_TIME, hint_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_cnmgr_scri_set_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static srv_cnmgr_result_enum mmi_em_cnmgr_scri_set_time(srv_cnmgr_scri_check_timer_enum type, U32 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cnmgr_result_enum result;
    U32 scri_check_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_cnmgr_cntx.check_time[type].id > 0)
    {
        srv_cnmgr_unset_scri_send_check_interval(g_mmi_em_cnmgr_cntx.check_time[type].id);
        g_mmi_em_cnmgr_cntx.check_time[type].id = 0;
    }

    result = srv_cnmgr_set_scri_send_check_interval(type, time * MMI_EM_CNMGR_SEC_MILLISEC, &(g_mmi_em_cnmgr_cntx.check_time[type].id));

    if (result == SRV_CNMGR_RESULT_SUCCESS)
    {
        g_mmi_em_cnmgr_cntx.check_time[type].interval = time;
    }
    else
    {
        srv_cnmgr_get_scri_send_check_interval(type, &scri_check_time);
        g_mmi_em_cnmgr_cntx.check_time[type].interval = scri_check_time / MMI_EM_CNMGR_SEC_MILLISEC;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_cnmgr_scri_set_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_cnmgr_scri_set_hdlr(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_cnmgr_scri_check_time_struct setting;
    S16 error;
    srv_cnmgr_scri_check_timer_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (output_num > MMI_EM_CNMGR_HOUR_TO_SEC || output_num == 0)
    {
        mmi_em_fail_popup();
        return;
    }

    type = (srv_cnmgr_scri_check_timer_enum)user_data;

    if (mmi_em_cnmgr_scri_set_time(type, output_num) == SRV_CNMGR_RESULT_SUCCESS)
    {
        /* Write setting to NVRAM */
        setting.lcd_on_check_time = g_mmi_em_cnmgr_cntx.check_time[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON].interval;
        setting.lcd_off_check_time = g_mmi_em_cnmgr_cntx.check_time[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF].interval;
        WriteRecord(NVRAM_EF_CNMGR_SCRI_CHECK_TIME_LID,
                    1,
                    &setting,
                    NVRAM_EF_CNMGR_SCRI_CHECK_TIME_SIZE,
                    &error);

        mmi_em_success_popup();
    }
    else
    {
        mmi_em_fail_popup();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_cnmgr_set_scri_check_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_cnmgr_set_scri_check_time(srv_cnmgr_scri_check_timer_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_num_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON:
            info.title_id = STR_ID_EM_GPRS_CNMGR_LCD_ON;
            break;

        case SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF:
            info.title_id = STR_ID_EM_GPRS_CNMGR_LCD_OFF;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    info.value = g_mmi_em_cnmgr_cntx.check_time[type].interval;
    info.notify = mmi_em_cnmgr_scri_set_hdlr;
    info.user_data = (void*)type;
    mmi_em_show_num_editor(&info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_cnmgr_unset_scri_check_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_cnmgr_unset_scri_check_time(srv_cnmgr_scri_check_timer_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_cnmgr_scri_check_time_struct setting;
    U32 scri_check_time;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_em_cnmgr_cntx.check_time[type].id > 0)
    {
        srv_cnmgr_unset_scri_send_check_interval(g_mmi_em_cnmgr_cntx.check_time[type].id);
        g_mmi_em_cnmgr_cntx.check_time[type].id = 0;
        g_mmi_em_cnmgr_cntx.check_time[type].interval = 0;

        /* Write setting to NVRAM */
        setting.lcd_on_check_time = g_mmi_em_cnmgr_cntx.check_time[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON].interval;
        setting.lcd_off_check_time = g_mmi_em_cnmgr_cntx.check_time[SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF].interval;
        WriteRecord(NVRAM_EF_CNMGR_SCRI_CHECK_TIME_LID,
                    1,
                    &setting,
                    NVRAM_EF_CNMGR_SCRI_CHECK_TIME_SIZE,
                    &error);

        srv_cnmgr_get_scri_send_check_interval(type, &scri_check_time);
        g_mmi_em_cnmgr_cntx.check_time[type].interval = scri_check_time / MMI_EM_CNMGR_SEC_MILLISEC;
    }

    mmi_em_success_popup();
}


/************************************************************
 * Global function
 ************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_em_cnmgr_init
 * DESCRIPTION
 *  Initialize context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_cnmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_cnmgr_scri_check_time_struct setting;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Read active SIM id and data account id from NVRAM */
    ReadRecord(NVRAM_EF_CNMGR_SCRI_CHECK_TIME_LID,
               1,
               &setting,
               NVRAM_EF_CNMGR_SCRI_CHECK_TIME_SIZE,
               &error);

    if (error == NVRAM_READ_SUCCESS)
    {
        mmi_em_cnmgr_scri_set_time(SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON, setting.lcd_on_check_time);
        mmi_em_cnmgr_scri_set_time(SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF, setting.lcd_off_check_time);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_cnmgr_scri_menu_entry_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event           [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
S32 mmi_em_cnmgr_scri_menu_entry_handler(cui_menu_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->parent_menu_id)
   	{
        case MENU_ID_EM_GPRS_CNMGR_SCRI_CONFIG:
            mmi_em_cnmgr_scri_set_main_menu(event);
            break;

        default: 
            return MMI_RET_OK;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_cnmgr_scri_menu_select_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event           [IN]
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
S32 mmi_em_cnmgr_scri_menu_select_handler(cui_menu_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->highlighted_menu_id)
   	{
        case MENU_ID_EM_GPRS_CNMGR_SET_SCRI_LCD_ON_CHECK_TIME:
            mmi_em_cnmgr_set_scri_check_time(SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON);
            break;

        case MENU_ID_EM_GPRS_CNMGR_UNSET_SCRI_LCD_ON_CHECK_TIME:
            mmi_em_cnmgr_unset_scri_check_time(SRV_CNMGR_SCRI_CHECK_TIMER_LCD_ON);
            break;

        case MENU_ID_EM_GPRS_CNMGR_SET_SCRI_LCD_OFF_CHECK_TIME:
            mmi_em_cnmgr_set_scri_check_time(SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF);
            break;

        case MENU_ID_EM_GPRS_CNMGR_UNSET_SCRI_LCD_OFF_CHECK_TIME:
            mmi_em_cnmgr_unset_scri_check_time(SRV_CNMGR_SCRI_CHECK_TIMER_LCD_OFF);
            break;

        default: 
            return MMI_RET_OK;
    }

    return MMI_RET_OK;
}

#endif /* __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__ */
