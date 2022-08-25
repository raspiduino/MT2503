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
 * MotionSensorSrc.c
 *
 * Project:
 * --------
 *	 MAUI
 *
 * Description:
 * ------------
 *	 This file is intends for Motion sensor
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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

/*******************************************************************************
 * Include Header Files
 *******************************************************************************/

#include "MMI_features.h"
#ifdef MOTION_SENSOR_SUPPORT
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "GlobalResDef.h"

#include "ProfilesSrvGprot.h" /* SUCCESS_TONE */
#include "CommonScreens.h"    /* DisplayPopup */
#include "MenuCuiGprot.h"     /* cui_menu_event_struct */
#include "wgui_categories_popup.h" /* UI_POPUP_NOTIFYDURATION_TIME */
#include "InlineCuiGprot.h"   /* CUI_INLINE_INSERT_TAIL */

#include "motionsensorgprot.h"

#include "sensorsrvGport.h" /* about "Motion sensor" */
#include "ReminderSrvGprot.h" /* about "Flip phone to mute alarm" */

/* #include "ScreenRotationGprot.h " about "auto switch display orientation" */
#include "mmi_rp_motion_sensor_def.h"/* motion res in motionsensor.res cmm test*/
#ifdef __MMI_TELEPHONY_SUPPORT__
#include "callsetsrvgprot.h"/* in callsetsrv part the interface get/set mode of "Flip phone to mute incoming call" and Tap-tap to start record in-call */
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#include "MMI_ap_dcm_config.h"



#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
typedef struct
{
    U8 motion_sensor;
    /* U8 switch_orientation;  Auto switch display orientation */
    U8 flip_incoming_call; /* Flip phone to mute incoming call */
    U8 flip_alarm;         /* Flip phone to mute alarm */
    U8 tap_tap_incall;     /* Tap-tap to start record in-call */
} phone_setting_motion_struct;
phone_setting_motion_struct g_phs_motion_struct;

typedef enum 
{
    MOTION_SENSOR_CAPTION = CUI_INLINE_ITEM_ID_BASE + 1,
    MOTION_SENSOR_SELECT,

    /*
    AUTO_SWITCH_DISPLAY_ORIENTATION_CAPTION, 
    AUTO_SWITCH_DISPLAY_ORIENTATION_SELECT,
    */
    
    FLIP_PHONE_TO_MUTE_INCOMING_CALL_CAPTION,
    FLIP_PHONE_TO_MUTE_INCOMING_CALL_SELECT,

    FLIP_PHONE_TO_MUTE_ALARM_CAPTION,
    FLIP_PHONE_TO_MUTE_ALARM_SELECT,
    
    TAP_TAP_TO_START_RECORD_IN_CALL_CAPTION,
    TAP_TAP_TO_START_RECORD_IN_CALL_SELECT
} phone_setting_motion_inline_itemid_enum; /* Motion infor in inlin id */

const U16 g_phs_select_ststus_onoff[2]={STR_GLOBAL_OFF, STR_GLOBAL_ON};

/* Motion sensor */
static const cui_inline_item_caption_struct motion_sensor_caption = {STR_ID_MOTION_SENSOR};
static const cui_inline_item_select_struct motion_sensor_select = {2, 0, g_phs_select_ststus_onoff};

/* Auto switch display orientation 
static const cui_inline_item_caption_struct auto_switch_display_orientation_caption = {STR_ID_AUTO_SWITCH_DISPLAY_ORIENTATION};
static const cui_inline_item_select_struct auto_switch_display_orientation_select = {2, 0, g_phs_select_ststus_onoff};
*/

/* Flip phone to mute incoming call */
static const cui_inline_item_caption_struct flip_phone_to_mute_incoming_call_caption = {STR_ID_FLIP_PHONE_TO_MUTE_INCOMING_CALL};
static const cui_inline_item_select_struct flip_phone_to_mute_incoming_call_select = {2, 0, g_phs_select_ststus_onoff};

/* Flip phone to mute alarm */
static const cui_inline_item_caption_struct flip_phone_to_mute_alarm_caption = {STR_ID_FLIP_PHONE_TO_MUTE_ALARM};
static const cui_inline_item_select_struct flip_phone_to_mute_alarm_select = {2, 0, g_phs_select_ststus_onoff};

/* Tap-tap to start record in-call */;
#ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
static const cui_inline_item_caption_struct tap_tap_record_incall_caption = {STR_ID_TAP_TAP_TO_START_RECORD_IN_CALL};
static const cui_inline_item_select_struct tap_tap_record_incall_select = {2, 0, g_phs_select_ststus_onoff};
#endif

static const cui_inline_set_item_struct g_phone_setting_motion_inline_item[] = {
    {MOTION_SENSOR_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&motion_sensor_caption},    
    {MOTION_SENSOR_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&motion_sensor_select},
    /*
    {AUTO_SWITCH_DISPLAY_ORIENTATION_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&auto_switch_display_orientation_caption},    
    {AUTO_SWITCH_DISPLAY_ORIENTATION_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&auto_switch_display_orientation_select},
    */
    {FLIP_PHONE_TO_MUTE_INCOMING_CALL_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&flip_phone_to_mute_incoming_call_caption},    
    {FLIP_PHONE_TO_MUTE_INCOMING_CALL_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&flip_phone_to_mute_incoming_call_select},

    {FLIP_PHONE_TO_MUTE_ALARM_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&flip_phone_to_mute_alarm_caption},    
    {FLIP_PHONE_TO_MUTE_ALARM_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&flip_phone_to_mute_alarm_select}
    #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    ,
    {TAP_TAP_TO_START_RECORD_IN_CALL_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&tap_tap_record_incall_caption},    
    {TAP_TAP_TO_START_RECORD_IN_CALL_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&tap_tap_record_incall_select}
    #endif
    };

const cui_inline_item_softkey_struct g_phone_setting_motion_softkey = {{{CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}  /* MMI_CENTER_SOFTKEY */ }};

const cui_inline_struct g_phone_setting_motion_inline_struct={
     #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
     8,/* 10, */
     #else
     6,
     #endif
     STR_ID_MOTION_SETTINGS,
     0,
     CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
     &g_phone_setting_motion_softkey,
     g_phone_setting_motion_inline_item}; 
     
mmi_id g_phone_setting_motion_gid; /* motion item's group id */    
mmi_id g_phone_setting_motion_inline_gid; /* inline group id, which is parent group id is motion item group id */
MMI_BOOL g_is_deleted; /* flag to decide weather or not deleted, MMI_FALSE is no deleted, MMI_TRUE is deleted. Initial is MMI_FALSE */


/*****************************************************************************
 * FUNCTION
 *  mmi_phone_setting_motion_get_info_from_srv
 * DESCRIPTION
 *  get motion infor from service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phone_setting_motion_get_info_from_srv()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /* get infor from service */
    g_phs_motion_struct.motion_sensor = srv_sensor_motion_get_switch();
    /* g_phs_motion_struct.switch_orientation = mmi_get_ui_rotation_state_by_mcube_sensor(); */
#ifdef __MMI_TELEPHONY_SUPPORT__
    g_phs_motion_struct.flip_incoming_call = srv_callset_flip_to_mute_call_get_mode();
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    g_phs_motion_struct.flip_alarm = srv_reminder_get_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER);
#ifdef __MMI_TELEPHONY_SUPPORT__
    #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    g_phs_motion_struct.tap_tap_incall = srv_callset_tap_tap_to_record_in_call_get_mode();
    #endif
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_phone_setting_motion_save_info
 * DESCRIPTION
 *  save motion infor to service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phone_setting_motion_save_info_to_srv()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    
    /* save infor to service */
    g_is_deleted = MMI_TRUE;;
    cui_inline_get_value(g_phone_setting_motion_inline_gid, MOTION_SENSOR_SELECT, (void*)(&g_phs_motion_struct.motion_sensor));
    srv_sensor_motion_set_switch((MMI_BOOL)(g_phs_motion_struct.motion_sensor));
    if(g_phs_motion_struct.motion_sensor == 1)/* Motion sensor is on */
    {
        /* cui_inline_get_value(g_phone_setting_motion_inline_gid, AUTO_SWITCH_DISPLAY_ORIENTATION_SELECT, (void*)(&g_phs_motion_struct.switch_orientation)); */
        /* mmi_set_ui_rotation_state_by_mcube_sensor(g_phs_motion_struct.switch_orientation); */
    #ifdef __MMI_TELEPHONY_SUPPORT__
        cui_inline_get_value(g_phone_setting_motion_inline_gid, FLIP_PHONE_TO_MUTE_INCOMING_CALL_SELECT, (void*)(&g_phs_motion_struct.flip_incoming_call));
        srv_callset_flip_to_mute_call_set_mode((MMI_BOOL)(g_phs_motion_struct.flip_incoming_call));
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
        cui_inline_get_value(g_phone_setting_motion_inline_gid, FLIP_PHONE_TO_MUTE_ALARM_SELECT, (void*)(&g_phs_motion_struct.flip_alarm));
        srv_reminder_set_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER, (MMI_BOOL)g_phs_motion_struct.flip_alarm);

    #ifdef __MMI_TELEPHONY_SUPPORT__
        #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
        cui_inline_get_value(g_phone_setting_motion_inline_gid, TAP_TAP_TO_START_RECORD_IN_CALL_SELECT, (void*)(&g_phs_motion_struct.tap_tap_incall));
        srv_callset_tap_tap_to_record_in_call_set_mode(g_phs_motion_struct.tap_tap_incall);
        #endif
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    }
    else if (g_phs_motion_struct.motion_sensor == 0)/* Motion sensor is off */
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        srv_callset_flip_to_mute_call_set_mode((MMI_BOOL)(g_phs_motion_struct.flip_incoming_call));
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
        srv_reminder_set_sensor_listen_state(SRV_SENSOR_MOTION_TURNOVER, (MMI_BOOL)g_phs_motion_struct.flip_alarm);
    #ifdef __MMI_TELEPHONY_SUPPORT__
        #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
        srv_callset_tap_tap_to_record_in_call_set_mode(g_phs_motion_struct.tap_tap_incall);
        #endif
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    }
    
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, g_phone_setting_motion_gid, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phone_setting_show_all_motion_infor
 * DESCRIPTION
 * when motion sensor is on, show all the information of motion
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phone_setting_show_all_motion_infor()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    cui_inline_lock_main_screen(mmi_frm_group_get_active_id());
    cui_inline_insert_item(mmi_frm_group_get_active_id(), CUI_INLINE_INSERT_TAIL, (cui_inline_set_item_struct *)&g_phone_setting_motion_inline_item[2]);
    cui_inline_insert_item(mmi_frm_group_get_active_id(), CUI_INLINE_INSERT_TAIL, (cui_inline_set_item_struct *)&g_phone_setting_motion_inline_item[3]);
    cui_inline_insert_item(mmi_frm_group_get_active_id(), CUI_INLINE_INSERT_TAIL, (cui_inline_set_item_struct *)&g_phone_setting_motion_inline_item[4]);
    cui_inline_insert_item(mmi_frm_group_get_active_id(), CUI_INLINE_INSERT_TAIL, (cui_inline_set_item_struct *)&g_phone_setting_motion_inline_item[5]);
    #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    cui_inline_insert_item(mmi_frm_group_get_active_id(), CUI_INLINE_INSERT_TAIL, (cui_inline_set_item_struct *)&g_phone_setting_motion_inline_item[6]);
    cui_inline_insert_item(mmi_frm_group_get_active_id(), CUI_INLINE_INSERT_TAIL, (cui_inline_set_item_struct *)&g_phone_setting_motion_inline_item[7]);
    #endif
    /*
    cui_inline_insert_item(mmi_frm_group_get_active_id(), CUI_INLINE_INSERT_TAIL, (cui_inline_set_item_struct *)&g_phone_setting_motion_inline_item[8]);
    cui_inline_insert_item(mmi_frm_group_get_active_id(), CUI_INLINE_INSERT_TAIL, (cui_inline_set_item_struct *)&g_phone_setting_motion_inline_item[9]);
    */

    cui_inline_set_value(g_phone_setting_motion_inline_gid, MOTION_SENSOR_SELECT, (void *)(g_phs_motion_struct.motion_sensor));
    /* cui_inline_set_value(g_phone_setting_motion_inline_gid, AUTO_SWITCH_DISPLAY_ORIENTATION_SELECT, (void *)(g_phs_motion_struct.switch_orientation)); */
    cui_inline_set_value(g_phone_setting_motion_inline_gid, FLIP_PHONE_TO_MUTE_INCOMING_CALL_SELECT, (void *)(g_phs_motion_struct.flip_incoming_call));
    cui_inline_set_value(g_phone_setting_motion_inline_gid, FLIP_PHONE_TO_MUTE_ALARM_SELECT, (void *)(g_phs_motion_struct.flip_alarm));
    #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    cui_inline_set_value(g_phone_setting_motion_inline_gid, TAP_TAP_TO_START_RECORD_IN_CALL_SELECT, (void *)(g_phs_motion_struct.tap_tap_incall));
    #endif
    cui_inline_unlock_main_screen(mmi_frm_group_get_active_id());
    cui_inline_redraw_screen(mmi_frm_group_get_active_id());

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phone_setting_hide_motion_infor_except_sensor
 * DESCRIPTION
 * when motion sensor is off, hide the information of motion except motion sensor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phone_setting_hide_motion_infor_except_sensor()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    cui_inline_lock_main_screen(mmi_frm_group_get_active_id());
    /*
    cui_inline_delete_item(mmi_frm_group_get_active_id(), AUTO_SWITCH_DISPLAY_ORIENTATION_CAPTION);
    cui_inline_delete_item(mmi_frm_group_get_active_id(), AUTO_SWITCH_DISPLAY_ORIENTATION_SELECT);
    */
    cui_inline_delete_item(mmi_frm_group_get_active_id(), FLIP_PHONE_TO_MUTE_INCOMING_CALL_CAPTION);
    cui_inline_delete_item(mmi_frm_group_get_active_id(), FLIP_PHONE_TO_MUTE_INCOMING_CALL_SELECT);
    cui_inline_delete_item(mmi_frm_group_get_active_id(), FLIP_PHONE_TO_MUTE_ALARM_CAPTION);
    cui_inline_delete_item(mmi_frm_group_get_active_id(), FLIP_PHONE_TO_MUTE_ALARM_SELECT);
    #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    cui_inline_delete_item(mmi_frm_group_get_active_id(), TAP_TAP_TO_START_RECORD_IN_CALL_CAPTION);
    cui_inline_delete_item(mmi_frm_group_get_active_id(), TAP_TAP_TO_START_RECORD_IN_CALL_SELECT);
    #endif
    cui_inline_unlock_main_screen(mmi_frm_group_get_active_id());
    cui_inline_redraw_screen(mmi_frm_group_get_active_id());

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phone_setting_motion_motion_sensor_changed
 * DESCRIPTION
 * when motion sensor switch changed 
 * PARAMETERS
 *  cui_event_inline_notify_struct *notify_event  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phone_setting_motion_motion_sensor_changed(cui_event_inline_notify_struct *notify_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_select_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    cui_inline_get_value(notify_event->sender_id, MOTION_SENSOR_SELECT, (void*)(&temp_select_index));
    g_phs_motion_struct.motion_sensor = temp_select_index;
    if ((temp_select_index == 0) && (g_is_deleted == MMI_FALSE))/* Motion sensor is off */
    {
        g_is_deleted = MMI_TRUE;
        mmi_phone_setting_hide_motion_infor_except_sensor();
    }
    else if ((temp_select_index == 1) && (g_is_deleted == MMI_TRUE))/* Motion sensor is on */
    {
        g_is_deleted = MMI_FALSE;
        /* mmi_phone_setting_motion_get_info_from_srv(); save the change */
        g_phs_motion_struct.motion_sensor = temp_select_index; /* update the motion sensor value */
        mmi_phone_setting_show_all_motion_infor();
    }
    else
    {
        ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phone_setting_motion_entry
 * DESCRIPTION
 *  entry phone setting motion item
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phone_setting_pre_motion_infor()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if(CUI_INLINE_RETURN_ERROR == cui_inline_get_value(g_phone_setting_motion_inline_gid, MOTION_SENSOR_SELECT, (void*)(&g_phs_motion_struct.motion_sensor)))
    {
        g_phs_motion_struct.motion_sensor = 0;
    }
    
    if(g_phs_motion_struct.motion_sensor == 1)/* Motion sensor is on */
    {
      
    }
    else if ((g_phs_motion_struct.motion_sensor == 0) && (g_is_deleted == MMI_FALSE))/* Motion sensor is off */
    {
        g_is_deleted = MMI_TRUE;;
        /*
        cui_inline_delete_item(mmi_frm_group_get_active_id(), AUTO_SWITCH_DISPLAY_ORIENTATION_CAPTION);
        cui_inline_delete_item(mmi_frm_group_get_active_id(), AUTO_SWITCH_DISPLAY_ORIENTATION_SELECT);
        */
        cui_inline_delete_item(mmi_frm_group_get_active_id(), FLIP_PHONE_TO_MUTE_INCOMING_CALL_CAPTION);
        cui_inline_delete_item(mmi_frm_group_get_active_id(), FLIP_PHONE_TO_MUTE_INCOMING_CALL_SELECT);
        cui_inline_delete_item(mmi_frm_group_get_active_id(), FLIP_PHONE_TO_MUTE_ALARM_CAPTION);
        cui_inline_delete_item(mmi_frm_group_get_active_id(), FLIP_PHONE_TO_MUTE_ALARM_SELECT);
        #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
        cui_inline_delete_item(mmi_frm_group_get_active_id(), TAP_TAP_TO_START_RECORD_IN_CALL_CAPTION);
        cui_inline_delete_item(mmi_frm_group_get_active_id(), TAP_TAP_TO_START_RECORD_IN_CALL_SELECT);
        #endif
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phone_setting_motion_pro
 * DESCRIPTION
 * The pro for phone setting motion
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_phone_setting_motion_pro(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            mmi_phone_setting_pre_motion_infor();
            break;
        }
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_inline_close(mmi_frm_group_get_active_id());
            break;
        }
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)evt;
            mmi_phone_setting_motion_save_info_to_srv();
            cui_inline_close(submit_evt->sender_id);
            break; 
        }
        
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify_event = (cui_event_inline_notify_struct*)evt;
            S32 temp_select_index = 0;
            cui_inline_get_value(notify_event->sender_id, notify_event->item_id, (void*)(&temp_select_index));
            switch(notify_event->item_id)
            {
            case MOTION_SENSOR_SELECT:
                g_phs_motion_struct.motion_sensor = temp_select_index;
                break;
            /*    
            case AUTO_SWITCH_DISPLAY_ORIENTATION_SELECT:
                g_phs_motion_struct.switch_orientation = temp_select_index;
                break;
            */    
            case FLIP_PHONE_TO_MUTE_INCOMING_CALL_SELECT:
                g_phs_motion_struct.flip_incoming_call = temp_select_index;
                break;
                
            case FLIP_PHONE_TO_MUTE_ALARM_SELECT:
                g_phs_motion_struct.flip_alarm = temp_select_index;
                break;
            #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
            case TAP_TAP_TO_START_RECORD_IN_CALL_SELECT:
                g_phs_motion_struct.tap_tap_incall = temp_select_index;
                break;
            #endif
            }
            if (notify_event->item_id == MOTION_SENSOR_SELECT && notify_event->event_type == CUI_INLINE_NOTIFY_ITEM_CHANGED)
            {
                mmi_phone_setting_motion_motion_sensor_changed(notify_event);
            }
/*
            if (notify_event->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
            {
                cui_inline_set_softkey_text(
                    notify_event->sender_id, 
                    notify_event->item_id,
                    MMI_LEFT_SOFTKEY,
                    STR_GLOBAL_SAVE);
			}
*/
            break;
        }
 
    default:
        break;  
        
    }
    
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_phone_setting_motion_entry
 * DESCRIPTION
 *  entry phone setting motion item
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_phone_setting_motion_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    g_phone_setting_motion_gid = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_phone_setting_motion_pro, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_phone_setting_motion_inline_gid = cui_inline_create(g_phone_setting_motion_gid, &g_phone_setting_motion_inline_struct);

    mmi_phone_setting_motion_get_info_from_srv();
    g_is_deleted = MMI_FALSE;/* MMI_FALSE is no deleted, MMI_TRUE is deleted*/
    cui_inline_set_title(g_phone_setting_motion_inline_gid, STR_ID_MOTION, 0);

    cui_inline_set_value(g_phone_setting_motion_inline_gid, MOTION_SENSOR_SELECT, (void *)(g_phs_motion_struct.motion_sensor));
   
    /* cui_inline_set_value(g_phone_setting_motion_inline_gid, AUTO_SWITCH_DISPLAY_ORIENTATION_SELECT, (void *)(g_phs_motion_struct.switch_orientation)); */
    
    cui_inline_set_value(g_phone_setting_motion_inline_gid, FLIP_PHONE_TO_MUTE_INCOMING_CALL_SELECT, (void *)(g_phs_motion_struct.flip_incoming_call));
  
    cui_inline_set_value(g_phone_setting_motion_inline_gid, FLIP_PHONE_TO_MUTE_ALARM_SELECT, (void *)(g_phs_motion_struct.flip_alarm));

    #ifdef __MOTION_SENSOR_ADVANCED_GESTURE__
    cui_inline_set_value(g_phone_setting_motion_inline_gid, TAP_TAP_TO_START_RECORD_IN_CALL_SELECT, (void *)(g_phs_motion_struct.tap_tap_incall));
    #endif
    cui_inline_run(g_phone_setting_motion_inline_gid);
}
#endif
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif

