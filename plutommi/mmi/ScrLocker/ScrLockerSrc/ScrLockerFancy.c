/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  ScrLockerFancy.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the fancy screen locker.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_LAUNCHER_APP_LIST__)

#include "DialerGprot.h"
#include "SmsSrvGprot.h"
#include "CallLogSrvGprot.h"

// auto add by kw_check begin
#include "MMIDataType.h"
#include "wgui_categories_idlescreen.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "DialerCuiGprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "ScrLockerObject.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalConstants.h"
#include "string.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_list.h"
#include "ScrLockerGprot.h"
#include "mmi_frm_input_gprot.h"
#include "ScrLockerFancy.h"
// auto add by kw_check end 
#include "MmsSrvGprot.h"

#include "MMI_ap_dcm_config.h"
#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata = "DYNAMIC_CODE_SCRLOCK_RODATA" , code = "DYNAMIC_CODE_SCRLOCK_ROCODE"
#endif
/**********************************************************************
 * Typedef
 **********************************************************************/

typedef S32 (*mmi_slk_fancy_get_num_cb)(void);

typedef struct
{
    U16                         idx;
    U16                         icon_id;
    U16                         str_id1;
    U16                         str_id2;
    mmi_slk_fancy_get_num_cb    get_num;
} mmi_slk_fancy_event_struct;


/**********************************************************************
 * Event Registration
 **********************************************************************/

static S32 mmi_slk_fancy_get_missed_call_num(void);
static S32 mmi_slk_fancy_get_unread_sms_num(void);
static S32 mmi_slk_fancy_get_unread_mms_num(void);

static const mmi_slk_fancy_event_struct g_mmi_slk_fancy_event_cfg_tbl[] =
{
    {
        WGUI_CAT30_ICON_TEXT_INFO1,
        IMG_ID_SLK_MISSED_CALL,
        STR_ID_SLK_MISSED_CALL,
        STR_ID_SLK_MISSED_CALLS,
        mmi_slk_fancy_get_missed_call_num
    }
    ,
#if defined(__MMI_TELEPHONY_SUPPORT__)
    {
        WGUI_CAT30_ICON_TEXT_INFO2,
        IMG_ID_SLK_NEW_SMS_MSG,
        STR_ID_SLK_NEW_SMS_MSG,
        STR_ID_SLK_NEW_SMS_MSGS,
        mmi_slk_fancy_get_unread_sms_num
    }
    ,
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    {
        WGUI_CAT30_ICON_TEXT_INFO3,
        IMG_ID_SLK_NEW_MMS_MSG,
        STR_ID_SLK_NEW_MMS_MSG,
        STR_ID_SLK_NEW_MMS_MSGS,
        mmi_slk_fancy_get_unread_mms_num
    }
    ,
    {0, 0, 0, 0, NULL}
};


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_get_missed_call_num
 * DESCRIPTION
 *  This function gets the number of missed calls.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of unread MMS.
 *****************************************************************************/
static S32 mmi_slk_fancy_get_missed_call_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_clog_get_unread_missed_call_num();
}


#if defined(__MMI_TELEPHONY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_get_unread_sms_num
 * DESCRIPTION
 *  This function gets the number of unread SMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of unread MMS.
 *****************************************************************************/
static S32 mmi_slk_fancy_get_unread_sms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_get_unread_sms_num();
}
#endif /* __MMI_TELEPHONY_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_get_unread_mms_num
 * DESCRIPTION
 *  This function gets the number of unread MMS.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of unread MMS.
 *****************************************************************************/
static S32 mmi_slk_fancy_get_unread_mms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 count = 0;
#ifdef __MMI_MMS_2__
	srv_mms_get_msg_count_struct msg_count_req;
	S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	memset(&msg_count_req, 0, sizeof(srv_mms_get_msg_count_struct));
	
	msg_count_req.count = 1;
	msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_MSG;
	
	result = srv_mms_get_msg_count(&msg_count_req);
	
	if (result == SRV_MMS_RESULT_OK)
	{
		count = msg_count_req.rsp_tb[0];
	}
#endif
	
	return count;

}

#ifdef __MMI_REDUCED_KEYPAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_launch_sos_dialer
 * DESCRIPTION
 *  This function launches the SOS dialer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_fancy_launch_sos_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dialer_launch_by_string_ex(CUI_DIALER_TYPE_SOS, L"112");
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_get_string
 * DESCRIPTION
 *  This function gets the string for display.
 * PARAMETERS
 *  num             : [IN]              Number of the unread events
 *  stri_id1        : [IN]              Singular string id
 *  stri_id2        : [IN]              Plural string id
 *  buffer          : [OUT]             Output buffer
 *  size            : [OUT]             Output buffer size in WCHAR
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_fancy_get_string(
    S32 num,
    U16 str_id1,
    U16 str_id2,
    WCHAR *buffer,
    S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR temp[32]; /* 32 is large enough for any 32-bits integer. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(temp, "%d ", num);
    mmi_wcsncat(buffer, temp, size - 1);

    if(num <= 1)
    {
        mmi_wcsncat(buffer, (WCHAR *)get_string(str_id1), size - 1);
    }
    else
    {
        mmi_wcsncat(buffer, (WCHAR *)get_string(str_id2), size - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_update_screen
 * DESCRIPTION
 *  This function updates the screen.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_fancy_update_screen(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_slk_fancy_event_struct *cfg;
    WCHAR *aligned_wchar_ptr;
    S32 i, num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    /*
     * Check if the active screen is the fancy lock.
     */
    if (mmi_frm_group_get_active_id() != obj->this_gid ||
        mmi_frm_scrn_get_active_id() != SCR_ID_SLK_MAIN)
    {
        return;
    }

    /*
     * Get the event information.
     */
    for (i = 0; g_mmi_slk_fancy_event_cfg_tbl[i].get_num != NULL; i++)
    {
        cfg = &(g_mmi_slk_fancy_event_cfg_tbl[i]);

        if((num = cfg->get_num()) > 0)
        {
            memset(subMenuData[i], 0, MAX_SUB_MENU_SIZE);

            /* Make sure the address is 2-bytes aligned; otherwise, ARM will
               fatal when it takes the address' value. */
            aligned_wchar_ptr = (WCHAR *)(((U32)subMenuData[i] + 1) & ~0x1);

            /* Minus 1 for the size since it might be used for the alignment. */
            mmi_slk_fancy_get_string(
                num,
                cfg->str_id1,
                cfg->str_id2,
                aligned_wchar_ptr,
                (MAX_SUB_MENU_SIZE / ENCODING_LENGTH) - 1);

            wgui_cat30_set_line_info(
                cfg->idx,
                aligned_wchar_ptr,
                (PU8)get_image(cfg->icon_id));
        }
    }

    /*
     * Show the texts in the handset lock screen.
     */
    wgui_cat30_update_details();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_leave_proc
 * DESCRIPTION
 *  This function is the leave proc.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_slk_fancy_leave_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:     /* fall-throught */
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            ret = -1; /* Do not close me. */
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_enter
 * DESCRIPTION
 *  This function enters the fancy screen lock.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_fancy_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_struct *obj;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data);

    obj = (mmi_slk_obj_struct *)param->user_data;

    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            NULL,
            (FuncPtr)mmi_slk_fancy_enter,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(
        param->group_id,
        param->scrn_id,
        mmi_slk_fancy_leave_proc);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat30_show(
        get_string(STR_ID_SLK_FANCY_HELP_MSG),
        mmi_scr_locker_close,
        NULL);
    
#else
    wgui_cat30_show(
        get_string(STR_ID_SLK_FANCY_HELP_MSG_2),
        mmi_scr_locker_close,
        NULL);
#endif    
    /* [MAUI_02634724] 
     * In locked screen,
     * if no digital key: call sos when pressing send key
     * Otherwise, input "112" and then press send key to call sos
     *
     * __MMI_REDUCED_KEYPAD__ : no digital key
     *
     */
#ifdef __MMI_REDUCED_KEYPAD__
    SetKeyHandler(mmi_slk_fancy_launch_sos_dialer, KEY_SEND, KEY_EVENT_DOWN);
#endif

#ifndef __MMI_TOUCH_SCREEN__
    SetKeyHandler(wgui_cat30_key_down_handler, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_cat30_key_up_handler, KEY_LSK, KEY_EVENT_UP);
#endif

    /* Do not allow to shutdown the handset. */
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);

    mmi_slk_fancy_update_screen(obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_on_run
 * DESCRIPTION
 *  This function runs the screen locker.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_fancy_on_run(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_run(obj);

    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_SLK_MAIN,
        (FuncPtr)mmi_slk_fancy_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_on_msg_num_changed
 * DESCRIPTION
 *  This function handles the message number changed event.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slk_fancy_on_msg_num_changed(mmi_slk_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_msg_num_changed(obj);

    mmi_slk_fancy_update_screen(obj);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slk_fancy_on_init
 * DESCRIPTION
 *  This function initializes the object.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slk_fancy_on_init(void *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_slk_fancy_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slk_obj_on_init((mmi_slk_obj_struct *)obj);

    p = (mmi_slk_fancy_struct *)obj;

    /* Member variable. */
    p->type = MMI_SCR_LOCKER_TYPE_FANCY;

    /* Member function. */
    p->on_run = mmi_slk_fancy_on_run;
    p->on_msg_num_changed = mmi_slk_fancy_on_msg_num_changed;
}

#ifdef __MMI_AP_DCM_SCRLOCK__
#pragma arm section rodata , code
#endif

#endif /* defined(__MMI_LAUNCHER_APP_LIST__) */

