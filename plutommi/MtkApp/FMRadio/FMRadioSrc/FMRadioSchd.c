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
 *   FMRadioSchd.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  FM Radio Scheduler
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

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__

#ifdef __MMI_FM_RADIO_SCHEDULER__
#include "ProfileGprots.h"
#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"

#include "wgui_categories_res.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "ProfileGProts.h"
#include "nvram_user_defs.h"

#include "AlarmFrameworkProt.h"
#include "AlarmProt.h"
#include "USBDeviceGprot.h"
#include "USBDeviceDefs.h"
#include "GpioSrvGprot.h"
#include "BootupSrvGprot.h"

extern const U8 gAlmDayOfWeek[];
extern mmi_fmrdo_struct g_fmrdo;
extern MMI_BOOL srv_earphone_is_plug_in(void);

static S32 temp_index;
static S32 g_highlighted_state;
static U16 g_highlighted_item;
static MMI_BOOL g_inline_changed;
static U16 g_display_freq;
static U16 hour_buf[3];
static U16 min_buf[3];
static U16 hour_buf_1[3];
static U16 min_buf_1[3];
static MMI_BOOL g_delete_fm_screen;

static U8 g_weekday_state[MMI_FMRDO_SCHEDULER_DAYS];
static S32 g_repeat_value;
static S32 g_state_value;
static U8 g_state_value_changed;
static U8 g_temp_days;
static MMI_BOOL g_day_changed;
static UI_character_type manual_input_buffer[MAX_MANUAL_INPUT_LEN];
static UI_character_type temp_input_buffer[MAX_MANUAL_INPUT_LEN];
static UI_character_type g_schedule_name_buff[MMI_FMRDO_SCHEDULER_NAME_SIZE + 1];
U16 g_prev_channel;
S32 g_fmrdo_highlighted_schedule;
U8 g_fmschd_stop_channel;


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_init_alarm_cb
 * DESCRIPTION
 *  Initialize FM alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_init_alarm_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_set_start_index(ALM_TYPE_FMRDO, ALM_FMRDO_START);
    AlmSetExpiryTimeCB(ALM_TYPE_FMRDO, mmi_fmrdo_scheduler_get_alarm_time);
    AlmSetExpiryHandlerCB(ALM_TYPE_FMRDO, mmi_fmrdo_scheduler_alarm_expiry_handler);
    AlmSetInitHandlerCB(ALM_TYPE_FMRDO, NULL, mmi_fmrdo_scheduler_reinit_queue);
    AlmSetStopAlarmCB(ALM_TYPE_FMRDO, NULL);
    mmi_fmrdo_scheduler_init_settings();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_init_settings
 * DESCRIPTION
 *  Initialize settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_init_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buffer[NVRAM_EF_FMRDO_SCHEDULER_SIZE];
    mmi_fmrdo_scheduler_setting_struct *data_p = (mmi_fmrdo_scheduler_setting_struct*) buffer;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_FMRDO_SCHEDULER_LID, 1, &buffer, NVRAM_EF_FMRDO_SCHEDULER_SIZE, &error);
    memcpy(&g_fmrdo.schedule[0], data_p, sizeof(g_fmrdo.schedule));
    g_fmrdo.activated_schedule = buffer[NVRAM_EF_FMRDO_SCHEDULER_SIZE - 1];
    if (!mmi_fmrdo_scheduler_activate_allowed(g_fmrdo.activated_schedule))
    {
        g_fmrdo.activated_schedule = buffer[NVRAM_EF_FMRDO_SCHEDULER_SIZE - 1] = (S8)0xff;
        WriteRecord(NVRAM_EF_FMRDO_SCHEDULER_LID, 1, &buffer, NVRAM_EF_FMRDO_SCHEDULER_SIZE, &error);
    }
    g_prev_channel = 0;
    g_fmrdo.scheduler_running = MMI_FALSE;
    g_fmrdo.schedule_restorable = MMI_FALSE;
    g_delete_fm_screen = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_save_schedule_options
 * DESCRIPTION
 *  Save schedule related settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_save_schedule_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_scheduler_setting_struct *save_p = &g_fmrdo.schedule[g_fmrdo_highlighted_schedule];
    UI_character_type prefix[2];
    S32 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_p->repeat = (U16)g_repeat_value;
    save_p->repeat_days = mmi_fmrdo_scheduler_set_repeat_days();
    if (g_repeat_value == MMI_FMRDO_REPEAT_DAYS && save_p->repeat_days == 0)
    {
        save_p->repeat = MMI_FMRDO_REPEAT_ONCE;
    }
    if (g_schedule_name_buff[0] != '\0')
    {
        memcpy((S8*)save_p->schedule_name, (S8*)g_schedule_name_buff, (ENCODING_LENGTH * (MMI_FMRDO_SCHEDULER_NAME_SIZE + 1)));
    }
    else
    {
        kal_wsprintf((UI_string_type)prefix, "%d", g_fmrdo_highlighted_schedule + 1);
        mmi_ucs2ncpy((S8*)save_p->schedule_name, GetString(STR_ID_FMRDO_SCHEDULER_SCHEDULE_LIST), MMI_FMRDO_SCHEDULER_NAME_SIZE - 2);
        mmi_ucs2cat((S8*)save_p->schedule_name, (S8*)prefix);
    }
    if (g_repeat_value == MMI_FMRDO_REPEAT_DAYS && g_fmrdo_highlighted_schedule == g_fmrdo.activated_schedule)
    {
        for (counter = 0; counter < MMI_FMRDO_SCHEDULE_CHANNEL_COUNT; counter++)
        {
            if (g_fmrdo.schedule[g_fmrdo.activated_schedule].channel_setting[counter].state == MMI_FMRDO_SCHEDULE_CHANNEL_STATE_ACTIVE)
            {
                AlmSetAlarm((U8) (ALM_FMRDO_START + (g_fmrdo.activated_schedule * MMI_FMRDO_SCHEDULE_COUNT) + counter));
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_activate_schedule
 * DESCRIPTION
 *  Activate selected schedule
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_fmrdo_scheduler_activate_schedule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter;
    pBOOL found = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_state_value == 0)
    {
        if (g_fmrdo_highlighted_schedule == g_fmrdo.activated_schedule)
        {
            for (counter = 0; counter < MMI_FMRDO_SCHEDULE_CHANNEL_COUNT; counter++)
            {
                AlmCancelAlarm((U8) (ALM_FMRDO_START + (g_fmrdo_highlighted_schedule * MMI_FMRDO_SCHEDULE_COUNT) + counter));
            }
            g_fmrdo.activated_schedule = (S8)0xff;
        }
    }
    else
    {
        for (counter = 0; counter < MMI_FMRDO_SCHEDULE_CHANNEL_COUNT; counter++)
        {
            if (g_fmrdo.schedule[g_fmrdo_highlighted_schedule].channel_setting[counter].state == MMI_FMRDO_SCHEDULE_CHANNEL_STATE_ACTIVE)
            {
                AlmSetAlarm((U8) (ALM_FMRDO_START + (g_fmrdo_highlighted_schedule * MMI_FMRDO_SCHEDULE_COUNT) + counter));
                found = MMI_TRUE;
            }
        }
        if (!found)
        {
            mmi_display_popup(
                get_string(STR_ID_FMRDO_SCHEDULER_NO_CHANNEL_SCHEDULED),
                MMI_EVENT_FAILURE);
            return MMI_FALSE;
        }
        else
        {
            /* Deactivate prev schedule */
            if (g_fmrdo.activated_schedule != (S8)-1 && g_fmrdo.activated_schedule != g_fmrdo_highlighted_schedule)
            {
                for (counter = 0; counter < MMI_FMRDO_SCHEDULE_CHANNEL_COUNT; counter++)
                {
                    AlmCancelAlarm((U8)(ALM_FMRDO_START + (g_fmrdo.activated_schedule * MMI_FMRDO_SCHEDULE_COUNT) + counter));
                }
            }
            g_fmrdo.activated_schedule = g_fmrdo_highlighted_schedule;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_time_edit_callback
 * DESCRIPTION
 *  Callback for time editor
 * PARAMETERS
 *  string_buffer       [OUT]        Time string 
 *  hour1               [IN]         Start hour
 *  min1                [IN]         Start min
 *  AM_PM_flag1         [IN]         Start AM/PM flag
 *  hour2               [IN]         End hour
 *  min2                [IN]         End min
 *  AM_PM_flag2         [IN]         End AM/PM flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_time_edit_callback(
        U8 *string_buffer,
        U8 *hour1,
        U8 *min1,
        U8 *AM_PM_flag1,
        U8 *hour2,
        U8 *min2,
        U8 *AM_PM_flag2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) string_buffer, (S8*) hour1);
    mmi_ucs2cat((S8*) string_buffer, (S8*) L":");
    mmi_ucs2cat((S8*) string_buffer, (S8*) min1);
    mmi_ucs2cat((S8*) string_buffer, (S8*) L" ");
    mmi_ucs2cat((S8*) string_buffer, (S8*) L"-");
    mmi_ucs2cat((S8*) string_buffer, (S8*) L" ");
    mmi_ucs2cat((S8*) string_buffer, (S8*) hour2);
    mmi_ucs2cat((S8*) string_buffer, (S8*) L":");
    mmi_ucs2cat((S8*) string_buffer, (S8*) min2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_fill_inline_items
 * DESCRIPTION
 *  Set inline items for editor screen display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_fill_inline_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    subMenuDataPtrs[0] = (PU8) GetString(STR_GLOBAL_ACTIVATE);
    subMenuDataPtrs[1] = (PU8) GetString(STR_GLOBAL_DEACTIVATE);
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_STATE]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_STATE]),
        2,
        (U8 **) subMenuDataPtrs,
        &(g_highlighted_state));
    if (g_display_freq >= MIN_FM_FREQUENCY && g_display_freq <= MAX_FM_FREQUENCY)
    {
        UI_character_type display_string[9];

        kal_wsprintf(display_string, "FM %d.%d", (g_display_freq / 10), (g_display_freq % 10));
        memcpy(subMenuData[3], display_string, sizeof(display_string));
    }
    else
    {
        subMenuDataPtrs[3] = (PU8) GetString(STR_GLOBAL_EMPTY_LIST);
    }
    SetInlineItemDisplayOnly(&(wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_OPTION]), subMenuDataPtrs[3]);
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_OPTION]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);

    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_TIME_CAP]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_TIME_CAP]),
        (U8*) GetString(STR_GLOBAL_TIME));

    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_TIME_PERIOD]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTimePeriod(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_TIME_PERIOD]),
        (U8*) hour_buf,
        (U8*) min_buf,
        NULL,
        (U8*) hour_buf_1,
        (U8*) min_buf_1,
        NULL,
        mmi_fmrdo_scheduler_time_edit_callback);
    DisableInlineItemHighlight(&wgui_inline_items[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_TIME_PERIOD]);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_cnf_save_settings
 * DESCRIPTION
 *  Save scheduler settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_cnf_save_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buffer[NVRAM_EF_FMRDO_SCHEDULER_SIZE];
    mmi_fmrdo_scheduler_setting_struct *data_p = (mmi_fmrdo_scheduler_setting_struct*) buffer;
    S16 error;
    mmi_fmrdo_scheduler_channel_setting_struct *save_p = &g_fmrdo.schedule[g_fmrdo_highlighted_schedule].channel_setting[g_highlighted_item];
    U8 temp_hour = (hour_buf[0] - '0') * 10 + (hour_buf[1] - '0');
    U8 temp_min = (min_buf[0] - '0') * 10 + (min_buf[1] - '0');
    U8 temp_hour_1 = (hour_buf_1[0] - '0') * 10 + (hour_buf_1[1] - '0');
    U8 temp_min_1 = (min_buf_1[0] - '0') * 10 + (min_buf_1[1] - '0');

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_highlighted_state != MMI_FMRDO_SCHEDULE_CHANNEL_STATE_DISABLED)
    {
        if ((temp_hour_1 < temp_hour) || (temp_hour_1 == temp_hour && temp_min_1 <= temp_min))
        {
            mmi_display_popup(
                get_string(STR_ID_FMRDO_SCHEDULER_INVALID_TIME),
                MMI_EVENT_FAILURE);
            return;
        }
        if (g_display_freq > MAX_FM_FREQUENCY || g_display_freq < MIN_FM_FREQUENCY)
        {
            mmi_display_popup(
                get_string(STR_ID_FMRDO_VALID_FM_BANDWIDTH),
                MMI_EVENT_FAILURE);
            return;
        }
    }
    save_p->state = g_highlighted_state;
    save_p->frequency = g_display_freq;
    save_p->start_hour = temp_hour;
    save_p->start_min = temp_min;
    save_p->end_hour = temp_hour_1;
    save_p->end_min = temp_min_1;

    if (g_highlighted_state == MMI_FMRDO_SCHEDULE_CHANNEL_STATE_DISABLED)
    {
        AlmCancelAlarm((U8)(ALM_FMRDO_START + (g_fmrdo_highlighted_schedule * MMI_FMRDO_SCHEDULE_COUNT) + g_highlighted_item));
    }
    else if (g_fmrdo.activated_schedule == g_fmrdo_highlighted_schedule)
    {
        AlmSetAlarm((U8)(ALM_FMRDO_START + (g_fmrdo_highlighted_schedule * MMI_FMRDO_SCHEDULE_COUNT) + g_highlighted_item));
    }
    if (!mmi_fmrdo_scheduler_activate_allowed((S8) g_fmrdo.activated_schedule))
    {
        g_fmrdo.activated_schedule = (S8) 0xff;
        g_state_value_changed = MMI_TRUE;
    }
    memcpy(data_p, &g_fmrdo.schedule[0], sizeof(g_fmrdo.schedule));
    buffer[NVRAM_EF_FMRDO_SCHEDULER_SIZE - 1] = g_fmrdo.activated_schedule;
    WriteRecord(NVRAM_EF_FMRDO_SCHEDULER_LID, 1, &buffer, NVRAM_EF_FMRDO_SCHEDULER_SIZE, &error);
    mmi_display_popup(
        get_string(STR_GLOBAL_SAVED),
        MMI_EVENT_SUCCESS);
    DeleteUptoScrID(SCR_ID_FMRDO_SCHEDULE_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_settings_changed
 * DESCRIPTION
 *  Check settings changed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_fmrdo_scheduler_settings_changed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_scheduler_channel_setting_struct *check_p = &g_fmrdo.schedule[g_fmrdo_highlighted_schedule].channel_setting[g_highlighted_item];
    U8 temp_hour = (hour_buf[0] - '0') * 10 + (hour_buf[1] - '0');
    U8 temp_min = (min_buf[0] - '0') * 10 + (min_buf[1] - '0');
    U8 temp_hour_1 = (hour_buf_1[0] - '0') * 10 + (hour_buf_1[1] - '0');
    U8 temp_min_1 = (min_buf_1[0] - '0') * 10 + (min_buf_1[1] - '0');

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_p->state != g_highlighted_state)
    {
        return MMI_TRUE;
    }
    if (check_p->frequency != g_display_freq)
    {
        return MMI_TRUE;
    }
    if (check_p->start_hour != temp_hour)
    {
        return MMI_TRUE;
    }
    if (check_p->start_min != temp_min)
    {
        return MMI_TRUE;
    }
    if (check_p->end_hour != temp_hour_1)
    {
        return MMI_TRUE;
    }
    if (check_p->end_min != temp_min_1)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_abort_save
 * DESCRIPTION
 *  Exit settings without saving
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_abort_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_FMRDO_SCHEDULE_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_save_schedule
 * DESCRIPTION
 *  Confirm save settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_save_schedule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_fmrdo_scheduler_activate_schedule();
    if (result)
    {
        mmi_display_popup(
            get_string(STR_GLOBAL_SAVED),
            MMI_EVENT_SUCCESS);
        mmi_fmrdo_scheduler_save_schedule_options();
        mmi_fmrdo_scheduler_save_to_nvram();
        DeleteScreenIfPresent(SCR_ID_FMRDO_SCHEDULE_OPTIONS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_save_settings_confirm
 * DESCRIPTION
 *  Confirm save settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_save_settings_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_confirm(
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        get_string(STR_GLOBAL_SAVE_ASK),
        MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_fmrdo_scheduler_cnf_save_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_fmrdo_scheduler_abort_save, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_schedule_settings_exit
 * DESCRIPTION
 *  Exit handler for schedule editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_schedule_settings_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_FMRDO_SCHEDULE_SETTINGS, mmi_fmrdo_scheduler_entry_settings);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_settings_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for settings menu
 * PARAMETERS
 *  index       [IN]        Highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_settings_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_OPTION)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_fmrdo_scheduler_entry_channel_settings, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_entry_settings
 * DESCRIPTION
 *  Entry function for Schedule settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buff_size;
    PU8 gui_buffer, input_buffer;
    mmi_fmrdo_scheduler_channel_setting_struct *setting_p = &g_fmrdo.schedule[g_fmrdo_highlighted_schedule].channel_setting[g_highlighted_item];
    U16 inline_icon_list[MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_TOTAL] = 
    {
        IMG_GLOBAL_L1,
        IMG_GLOBAL_L2,
        IMG_GLOBAL_L3,
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_SCHEDULE_SETTINGS, mmi_fmrdo_schedule_settings_exit, NULL, NULL);
    InitializeCategory57Screen();
    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_SCHEDULE_SETTINGS);
    input_buffer = GetCurrNInputBuffer(SCR_ID_FMRDO_SCHEDULE_SETTINGS, &input_buff_size);
    if (gui_buffer == NULL)
    {
        g_inline_changed = 0;
        g_display_freq = setting_p->frequency;
        g_highlighted_state = setting_p->state != MMI_FMRDO_SCHEDULE_CHANNEL_STATE_ACTIVE ? MMI_FMRDO_SCHEDULE_CHANNEL_STATE_DISABLED : MMI_FMRDO_SCHEDULE_CHANNEL_STATE_ACTIVE;
        if (setting_p->start_hour > 23)
        {
            setting_p->start_hour = 23;
        }
        if (setting_p->start_min > 59)
        {
            setting_p->start_min = 59;
        }
        AlmGetStringValue((S8*) hour_buf, setting_p->start_hour);
        AlmGetStringValue((S8*) min_buf, setting_p->start_min);
        AlmGetStringValue((S8*) hour_buf_1, setting_p->end_hour);
        AlmGetStringValue((S8*) min_buf_1, setting_p->end_min);
        if (setting_p->frequency >= MIN_FM_FREQUENCY && setting_p->frequency <= MAX_FM_FREQUENCY)
        {
            kal_wsprintf(manual_input_buffer, "%d.%d", (setting_p->frequency / 10), (setting_p->frequency % 10));
        }
        else
        {
            manual_input_buffer[0] = '\0';
            manual_input_buffer[1] = '\0';
        }
    }
    mmi_fmrdo_scheduler_fill_inline_items();
    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_TOTAL, input_buffer);
    }

    RegisterHighlightHandler(mmi_fmrdo_scheduler_settings_highlight_hdlr);
    ShowCategory57Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        MMI_FMRDO_SCHEDULE_CHANNEL_SETTING_TOTAL,
        inline_icon_list,
        wgui_inline_items,
        0,
        gui_buffer);
    if (g_inline_changed)
    {
        g_inline_changed = 0;
        set_wgui_inline_list_menu_changed();
    }

    SetCategory57RightSoftkeyFunctions(mmi_fmrdo_scheduler_save_settings_confirm, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_get_channel_index
 * DESCRIPTION
 *  Store index in schedule setting list
 * PARAMETERS
 *  index       [IN]        Channel index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_get_channel_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_highlighted_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_get_setting_list
 * DESCRIPTION
 *  Get display item for schedule setting list
 * PARAMETERS
 *  item_index      [IN]          Index
 *  str_buff        [OUT]         Display string
 *  img_buff_p      [OUT]         Display image
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_fmrdo_scheduler_get_setting_list(S32 item_index, U16 *img_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type display_string[MAX_SUB_MENU_SIZE];
    S16 freq = g_fmrdo.schedule[g_fmrdo_highlighted_schedule].channel_setting[item_index].frequency;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.schedule[g_fmrdo_highlighted_schedule].channel_setting[item_index].state == MMI_FMRDO_SCHEDULE_CHANNEL_STATE_ACTIVE)
    {
        *img_buff_p = CHECKBOX_ON_IMAGE_ID;
    }
    else
    {
        *img_buff_p = CHECKBOX_OFF_IMAGE_ID;
    }
    if (freq >= MIN_FM_FREQUENCY && freq <= MAX_FM_FREQUENCY)
    {
        kal_wsprintf(display_string, "FM %d.%d", freq / 10, freq % 10);
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[item_index], (S8*) display_string, MAX_SUB_MENU_SIZE);
    }
    else
    {
        mmi_ucs2ncpy((S8*) subMenuDataPtrs[item_index], GetString(STR_GLOBAL_EMPTY_LIST), MAX_SUB_MENU_SIZE);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_entry_schedule_editor
 * DESCRIPTION
 *  Entry function for scheduler editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_entry_schedule_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    U16 images[MMI_FMRDO_SCHEDULE_CHANNEL_COUNT];
    S32 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_SCHEDULE_EDITOR, NULL, mmi_fmrdo_scheduler_entry_schedule_editor, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_SCHEDULE_EDITOR);

    if (gui_buffer == NULL)
    {
        g_highlighted_item = 0;
    }
    for (counter = 0; counter < MMI_FMRDO_SCHEDULE_CHANNEL_COUNT; counter++)
    {
        mmi_fmrdo_scheduler_get_setting_list(counter, (U16 *)&images[counter]);
    }
    RegisterHighlightHandler(mmi_fmrdo_scheduler_get_channel_index);
    ShowCategory53Screen(
        STR_ID_FMRDO_SCHEDULER_CUSTOMIZE,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_FMRDO_SCHEDULE_CHANNEL_COUNT,
        subMenuDataPtrs,
        images,
        0,
        0,
        0,
        gui_buffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_scheduler_entry_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_fmrdo_scheduler_entry_settings, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_schedule_option_exit
 * DESCRIPTION
 *  exit schedule options screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_schedule_option_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_FMRDO_SCHEDULE_OPTIONS, mmi_fmrdo_scheduler_entry_schedule_option);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_set_repeat_days
 * DESCRIPTION
 *  Set repeat days from settings
 * PARAMETERS
 *  void
 * RETURNS
 *  repeat days
 *****************************************************************************/
U16 mmi_fmrdo_scheduler_set_repeat_days(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 repeat_days = 0;
    S32 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_repeat_value == MMI_FMRDO_REPEAT_DAYS)
    {
        for (counter = 0; counter < MMI_FMRDO_SCHEDULER_DAYS; counter++)
        {
            if (g_weekday_state[counter])
            {
                repeat_days |= gAlmDayOfWeek[counter];
            }
        }
    }
    else
    {
        return 0;
    }
    return repeat_days;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_init_repeat
 * DESCRIPTION
 *  Set repeat days value from settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_init_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_scheduler_setting_struct *weekday_p = &g_fmrdo.schedule[g_fmrdo_highlighted_schedule];
    S32 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_weekday_state, 0, MMI_FMRDO_SCHEDULER_DAYS);
    g_repeat_value = weekday_p->repeat;
    g_temp_days = (U8)weekday_p->repeat_days;
    g_day_changed = MMI_FALSE;
    for (counter = 0; counter < MMI_FMRDO_SCHEDULER_DAYS; counter++)
    {
        if (g_temp_days & gAlmDayOfWeek[counter])
        {
            g_weekday_state[counter] = 1;
        }
    }
    if (g_temp_days == 0)
    {
        g_temp_days = MMI_FMRDO_SCHEDULER_WEEKDAYS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_highlight_options
 * DESCRIPTION
 *  highlight handler for schedule options menu
 * PARAMETERS
 *  index       [IN]        Highlight handler for options
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_highlight_options(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == MMI_FMRDO_SCHEDULE_OPTIONS_CUSTOMIZE)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_fmrdo_scheduler_entry_schedule_editor, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_highlight_repeat
 * DESCRIPTION
 *  Highlight handler for repeat menu
 * PARAMETERS
 *  index       [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_highlight_repeat(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == MMI_FMRDO_REPEAT_DAYS)
    {
        if (g_day_changed == MMI_TRUE)
        {
            memset(g_weekday_state, 0, MMI_FMRDO_SCHEDULER_DAYS);
            for (counter = 0; counter < MMI_FMRDO_SCHEDULER_DAYS; counter++)
            {
                if (g_temp_days & gAlmDayOfWeek[counter])
                {
                    g_weekday_state[counter] = 1;
                }
            }
            g_day_changed = MMI_FALSE;
        }
        EnableInlineItem(
            &wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY],
            MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY);
    }
    else
    {
        g_day_changed = MMI_TRUE;
        memset(g_weekday_state, 0, MMI_FMRDO_SCHEDULER_DAYS);
        DisableInlineItem(
            &wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY],
            MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY);
    }
    RedrawCategory57Screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_change_RSK_after_edit
 * DESCRIPTION
 *  Change RSK to back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_change_RSK_after_edit(PU8 buffer, PU8 cursor, S32 text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text_length == 0)
    {
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_options_fill_inline_items
 * DESCRIPTION
 *  Fill inline items for schedule options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_options_fill_inline_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Activate */
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_ACTIVATE]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    subMenuDataPtrs[1] = (PU8)GetString(STR_GLOBAL_ACTIVATED);
    subMenuDataPtrs[0] = (PU8)GetString(STR_ID_FMRDO_SCHEDULER_DEACTIVATED);
    SetInlineItemSelect(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_ACTIVATE]),
        2,
        (U8 **) subMenuDataPtrs,
        (S32*) &g_state_value);

    /* Customize */
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_CUSTOMIZE]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_CUSTOMIZE]),
        (U8*) GetString(STR_ID_FMRDO_SCHEDULER_CUSTOMIZE));

   /*-- Rename Caption --*/
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_RENAME_CAP]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_RENAME_CAP]),
        (U8*) GetString(STR_GLOBAL_RENAME));

    /* Rename */
    SetInlineItemActivation(
        &wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_RENAME],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemTextEdit(
        &wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_RENAME],
        (U8*) g_schedule_name_buff,
        MMI_FMRDO_SCHEDULER_NAME_SIZE + 1,
        IMM_INPUT_TYPE_SENTENCE);
    EnableInlineItemBoundary(&wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_RENAME]);

   /*-- Repeat Caption --*/
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_CAP]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemCaption(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_CAP]),
        (U8*) GetString(STR_ID_FMRDO_SCHEDULER_REPEAT));

   /*-- Repeat --*/
    subMenuDataPtrs[2 + MMI_FMRDO_REPEAT_ONCE] = (PU8)GetString(STR_ID_FMRDO_SCHEDULER_ONCE);
    subMenuDataPtrs[2 + MMI_FMRDO_REPEAT_EVERYDAY] = (PU8)GetString(STR_ID_FMRDO_SCHEDULER_EVERYDAY);
    subMenuDataPtrs[2 + MMI_FMRDO_REPEAT_DAYS] = (PU8)GetString(STR_GLOBAL_CUSTOM);
    subMenuDataPtrs[2 + MMI_FMRDO_REPEAT_WEEKLY] = (PU8)GetString(STR_ID_FMRDO_SCHEDULER_WEEKLY);
    subMenuDataPtrs[2 + MMI_FMRDO_REPEAT_MONTHLY] = (PU8)GetString(STR_ID_FMRDO_SCHEDULER_MONTHLY);
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemSelect(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT]),
        MMI_FMRDO_REPEAT_NUM,
        (U8 **) &subMenuDataPtrs[2],
        &g_repeat_value);
    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT],
        mmi_fmrdo_scheduler_highlight_repeat);

   /*-- Day of Week --*/
    SetInlineItemActivation(
        &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY]),
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDOWSelect(&(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY]), 0, g_weekday_state);
    if (g_repeat_value != MMI_FMRDO_REPEAT_DAYS)
    {
        DisableInlineItem(
            &wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY],
            MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY);
    }

    if (g_fmrdo.schedule[g_fmrdo_highlighted_schedule].repeat != MMI_FMRDO_REPEAT_DAYS) /* not Days */
    {
        DisableInlineItem(&wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY], MMI_FMRDO_SCHEDULE_OPTIONS_REPEAT_DAY);    /* multi select days */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_abort_save_schedule
 * DESCRIPTION
 *  Abort without saving
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_abort_save_schedule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_FMRDO_SCHEDULE_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_query_save_schedule
 * DESCRIPTION
 *  Query whether save schedule or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_query_save_schedule(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_confirm(
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        get_string(STR_GLOBAL_SAVE_ASK),
        MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_fmrdo_scheduler_save_schedule, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_fmrdo_scheduler_abort_save_schedule, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_entry_schedule_option
 * DESCRIPTION
 *  Entry function for schedule options
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_entry_schedule_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 inline_icon_list[MMI_FMRDO_SCHEDULE_OPTIONS_TOTAL] = 
    {
        IMG_GLOBAL_L1,
        IMG_GLOBAL_L2,
        IMG_GLOBAL_L3,
        0,
        IMG_GLOBAL_L4,
        0,
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_SCHEDULE_OPTIONS, mmi_fmrdo_scheduler_schedule_option_exit, NULL, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_SCHEDULE_OPTIONS);
    if (gui_buffer == NULL)
    {
        mmi_fmrdo_scheduler_init_repeat();
        if (g_fmrdo.schedule[g_fmrdo_highlighted_schedule].schedule_name[0] != '\0')
        {
            memcpy(
                (S8*) g_schedule_name_buff,
                (S8*) g_fmrdo.schedule[g_fmrdo_highlighted_schedule].schedule_name,
                (ENCODING_LENGTH * (MMI_FMRDO_SCHEDULER_NAME_SIZE + 1)));
        }
        else
        {
            UI_character_type prefix[2];

            kal_wsprintf((UI_string_type)prefix, "%d", g_fmrdo_highlighted_schedule + 1);
            mmi_ucs2ncpy((S8*)g_schedule_name_buff, GetString(STR_ID_FMRDO_SCHEDULER_SCHEDULE_LIST), MMI_FMRDO_SCHEDULER_NAME_SIZE - 2);
            mmi_ucs2cat((S8*)g_schedule_name_buff, (S8*)prefix);
        }
        g_state_value = (g_fmrdo_highlighted_schedule == g_fmrdo.activated_schedule);
        g_state_value_changed = MMI_FALSE;
    }
    InitializeCategory57Screen();

    RegisterHighlightHandler(mmi_fmrdo_scheduler_highlight_options);
    mmi_fmrdo_scheduler_options_fill_inline_items();
    inputBuffer = GetCurrNInputBuffer(SCR_ID_FMRDO_SCHEDULE_OPTIONS, &inputBufferSize); /* added for inline edit history */
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_FMRDO_SCHEDULE_OPTIONS_TOTAL, inputBuffer);
        if (g_state_value_changed)
        {
            g_state_value = 0;
            ReConfigureInlineItemSelect(
                &(wgui_inline_items[MMI_FMRDO_SCHEDULE_OPTIONS_ACTIVATE]),
                2,
                (U8 **) subMenuDataPtrs,
                &g_state_value);
            g_state_value_changed = MMI_FALSE;
        }
    }

    ShowCategory57Screen(
        STR_GLOBAL_EDIT,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_DONE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_FMRDO_SCHEDULE_OPTIONS_TOTAL,
        inline_icon_list,
        wgui_inline_items,
        0,
        gui_buffer);

    SetCategory57RightSoftkeyFunctions(mmi_fmrdo_scheduler_query_save_schedule, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_schedule_index
 * DESCRIPTION
 *  Highlight handler for scheduler main menu
 * PARAMETERS
 *  index       [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_get_schedule_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo_highlighted_schedule = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_schedule_list
 * DESCRIPTION
 *  Get schedule name to display
 * PARAMETERS
 *  item_index      [IN]            Index into channel list
 *  str_buff        [IN/OUT]        String to be displayed
 *  img_buff_p      [IN/OUT]        Image to be displayed
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_get_schedule_list(S32 item_index, UI_string_type str_buff, U16 *img_buff_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type prefix[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.schedule[item_index].schedule_name[0] != '\0')
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) g_fmrdo.schedule[item_index].schedule_name);
    }
    else
    {
        kal_wsprintf((UI_string_type) prefix, "%d", item_index + 1);
        mmi_ucs2ncpy((S8*) str_buff, GetString(STR_ID_FMRDO_SCHEDULER_SCHEDULE_LIST), MAX_SUB_MENU_SIZE - 2);
        mmi_ucs2cat((S8*) str_buff, (S8*) prefix);
    }
    if (g_fmrdo.activated_schedule == item_index)
    {
        *img_buff_p = CHECKBOX_ON_IMAGE_ID;
    }
    else
    {
        *img_buff_p = CHECKBOX_OFF_IMAGE_ID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_entry_schedule_list
 * DESCRIPTION
 *  Entry function for Scheduler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_entry_schedule_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    U16 images[MMI_FMRDO_SCHEDULE_COUNT];
    S32 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_SCHEDULE_LIST, NULL, mmi_fmrdo_scheduler_entry_schedule_list, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_SCHEDULE_LIST);
    if (gui_buffer == NULL)
    {
        g_fmrdo_highlighted_schedule = 0;
    }

    RegisterHighlightHandler(mmi_fmrdo_get_schedule_index);
    for (counter = 0; counter < MMI_FMRDO_SCHEDULE_COUNT; counter++)
    {
        mmi_fmrdo_get_schedule_list(counter, (UI_string_type) subMenuDataPtrs[counter], &images[counter]);
    }

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
    ShowCategory53Screen(
        STR_ID_FMRDO_SCHEDULER_SCHEDULE,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_FMRDO_SCHEDULE_COUNT,
        subMenuDataPtrs,
        images,
        0,
        0,
        0,
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_fmrdo_scheduler_entry_schedule_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_fmrdo_scheduler_entry_schedule_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_entry_channel_settings
 * DESCRIPTION
 *  Entry function for channel settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_entry_channel_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    PU8 gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_SCHEDULE_CHANNEL_OPTIONS, NULL, mmi_fmrdo_scheduler_entry_channel_settings, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_SCHEDULE_CHANNEL_OPTIONS);

    nNumofItem = GetNumOfChild(MENU_ID_FMRDO_SCHEDULER_CHANNEL_SETTINGS);

    GetSequenceStringIds(MENU_ID_FMRDO_SCHEDULER_CHANNEL_SETTINGS, nStrItemList);

    SetParentHandler(MENU_ID_FMRDO_SCHEDULER_CHANNEL_SETTINGS);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_save_manual_freq
 * DESCRIPTION
 *  Save entered frequency to display variable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_save_manual_freq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    freq = mmi_fmrdo_get_freq_from_str(temp_input_buffer);
    if (freq == 0xffff) /* invalid decimal digit */
    {
        mmi_display_popup(
            get_string(STR_ID_FMRDO_VALID_FM_DECIMAL),
            MMI_EVENT_FAILURE);
    }
    else if (freq < MIN_FM_FREQUENCY || freq > MAX_FM_FREQUENCY)        /* warning invalid frequency */
    {
        mmi_display_popup(
            get_string(STR_ID_FMRDO_VALID_FM_BANDWIDTH),
            MMI_EVENT_FAILURE);
    }
    else
    {
        kal_wsprintf(manual_input_buffer, "%d.%d", (freq / 10), (freq % 10));
        g_display_freq = freq;
        g_inline_changed = MMI_TRUE;
        GoBackToHistory(SCR_ID_FMRDO_SCHEDULE_SETTINGS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_exit_manual_input
 * DESCRIPTION
 *  Entry function for manual input editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_exit_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_FMRDO_MANUAL_INPUT, mmi_fmrdo_scheduler_entry_manual_input);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_entry_manual_input
 * DESCRIPTION
 *  Entry function for manual input editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_entry_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_MANUAL_INPUT, mmi_fmrdo_scheduler_exit_manual_input, NULL, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_MANUAL_INPUT);
    if (gui_buffer == NULL)
    {
        mmi_ucs2cpy((S8*)temp_input_buffer, (S8*)manual_input_buffer);
    }

    InitializeCategory57Screen();

    inputBuffer = GetCurrNInputBuffer(SCR_ID_FMRDO_MANUAL_INPUT, &inputBufferSize);

    RegisterHighlightHandler(mmi_fmrdo_manual_input_highlight_hdlr);

    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemTextEdit(
        &wgui_inline_items[0],
        (U8*) temp_input_buffer,
        MAX_MANUAL_INPUT_LEN,
        IMM_INPUT_TYPE_DECIMAL_NUMERIC);
    LeftJustifyInlineItem(&wgui_inline_items[0]);
    SetInlineItemFullWidth(&wgui_inline_items[0]);
    EnableInlineItemBoundary(&wgui_inline_items[0]);

    DisableCategory57ScreenDone();

    /* show category screen */
    ShowCategory57Screen(
        STR_ID_FMRDO_MANUAL_INPUT,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),   /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                          /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                        /* RSK text and icon */
        1,
        0,
        wgui_inline_items,
        0,
        gui_buffer);

    SetCategory57LeftSoftkeyFunction(mmi_fmrdo_scheduler_save_manual_freq);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_get_freq
 * DESCRIPTION
 *  Entry function for channel list select menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_get_freq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_display_freq = g_fmrdo.channel_list.freq[temp_index];
    g_inline_changed = MMI_TRUE;
    GoBackToHistory(SCR_ID_FMRDO_SCHEDULE_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_get_highlighted_channel
 * DESCRIPTION
 *  Entry function for channel list select menu
 * PARAMETERS
 *  index       [IN]        Item index for highlighted channel
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_get_highlighted_channel(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_index = index;
    if (g_fmrdo.channel_list.freq[temp_index] == 0)
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_fmrdo_scheduler_get_freq, KEY_EVENT_UP);
        SetKeyHandler(mmi_fmrdo_scheduler_get_freq, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_entry_channel_list
 * DESCRIPTION
 *  Entry function for channel list select menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_entry_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    S32 error_flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_FMRDO_CHANNEL_LIST, NULL, mmi_fmrdo_scheduler_entry_channel_list, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_FMRDO_CHANNEL_LIST);
    if (gui_buffer == NULL)
    {
        temp_index = 0;
    }
    RegisterHighlightHandler(mmi_fmrdo_scheduler_get_highlighted_channel);

#ifdef __MMI_BASIC_UI_STYLE__
	wgui_cat1032_show(
		  (WCHAR*)GetString(STR_ID_FMRDO_CHANNEL_LIST),
		  GetImage(GetRootTitleIcon(MENU_ID_FMRDO_MAIN)),
		  (WCHAR*)GetString(STR_GLOBAL_SELECT),
		  GetImage(IMG_GLOBAL_OK),
		  (WCHAR*)GetString(STR_GLOBAL_BACK),
		  GetImage(IMG_GLOBAL_BACK),
		  FM_RADIO_CHANNEL_NUM,
		  mmi_fmrdo_channel_list_item_ext,
		  mmi_fmrdo_channel_list_item_hint,
		  0,
		  IMG_GLOBAL_L1,
		  0,
		  gui_buffer,
		  &error_flag);
#else
    ShowCategory184Screen(
        STR_ID_FMRDO_CHANNEL_LIST,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),   /* title text and icon */
        STR_GLOBAL_SELECT,
        IMG_GLOBAL_OK,                     /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                        /* RSK text and icon */
        FM_RADIO_CHANNEL_NUM,
        mmi_fmrdo_channel_list_item,
        mmi_fmrdo_channel_list_item_hint,
        0,
        gui_buffer);
#endif
    /* register LSK, RSK hanlders */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_common_LSK_RSK_hdlr
 * DESCRIPTION
 *  Common function to set key handler for menu item
 * PARAMETERS
 *  strLSK      [IN]        LSK string ID
 *  strRSK      [IN]        RSK string ID
 *  LSKfptr     [IN]        LSK down handler
 *  RSKfptr     [IN]        RSK down handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_common_LSK_RSK_hdlr(U16 strLSK, U16 strRSK, void (*LSKfptr) (void), void (*RSKfptr) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(strLSK, 0);
    ChangeRightSoftkey(strRSK, 0);

    SetLeftSoftkeyFunction(LSKfptr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(RSKfptr, KEY_EVENT_UP);

    SetKeyHandler(LSKfptr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(RSKfptr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_highlight_scheduler
 * DESCRIPTION
 *  Highlight handler for scheduler application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_highlight_scheduler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_common_LSK_RSK_hdlr(
        STR_GLOBAL_OK,
        STR_GLOBAL_BACK,
        mmi_fmrdo_scheduler_entry_schedule_list,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_highlight_manual_input
 * DESCRIPTION
 *  Highlight handler for select channel through manual input
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_highlight_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_common_LSK_RSK_hdlr(
        STR_GLOBAL_OK,
        STR_GLOBAL_BACK,
        mmi_fmrdo_scheduler_entry_manual_input,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_highlight_channel_list
 * DESCRIPTION
 *  Highlight handler for select from channel list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_highlight_channel_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_common_LSK_RSK_hdlr(
        STR_GLOBAL_OK,
        STR_GLOBAL_BACK,
        mmi_fmrdo_scheduler_entry_channel_list,
        GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_get_alarm_time
 * DESCRIPTION
 *  Get frequency setting for alarm
 * PARAMETERS
 *  index           [IN]          Alarm index
 *  time            [OUT]         Time for alarm
 *  repeat          [OUT]         Repeat frequency for alarm
 *  weekday         [OUT]         week days for alarm
 *  preReminder     [OUT]         pre-reminder
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_get_alarm_time(U8 index, MYTIME *time, U8 *repeat, U8 *weekday, MYTIME *preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_scheduler_channel_setting_struct *time_p = &g_fmrdo.schedule[index / MMI_FMRDO_SCHEDULE_COUNT].channel_setting[index % MMI_FMRDO_SCHEDULE_CHANNEL_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(time);
    time->nHour = time_p->start_hour;
    time->nMin = time_p->start_min;
    time->nSec = 0;
    *repeat = (U8) mmi_fmrdo_scheduler_get_alm_frequency(index);
    *weekday = (U8) g_fmrdo.schedule[index / MMI_FMRDO_SCHEDULE_COUNT].repeat_days;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_get_alm_frequency
 * DESCRIPTION
 *  Get frequency setting for alarm
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_fmrdo_scheduler_get_alm_frequency(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 repeat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_fmrdo.schedule[index / MMI_FMRDO_SCHEDULE_COUNT].repeat)
    {
    case MMI_FMRDO_REPEAT_ONCE:
        repeat = ALM_FREQ_ONCE;
        break;
    case MMI_FMRDO_REPEAT_EVERYDAY:
        repeat = ALM_FREQ_EVERYDAY;
        break;
    case MMI_FMRDO_REPEAT_DAYS:
        repeat = ALM_FREQ_DAYS;
        break;
    case MMI_FMRDO_REPEAT_WEEKLY:
        repeat = ALM_FREQ_WEEKLY;
        break;
    case MMI_FMRDO_REPEAT_MONTHLY:
        repeat = ALM_FREQ_MONTHLY;
        break;
    default:
        repeat = ALM_FREQ_ONCE;
        break;
    }
    return repeat;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_stop_alarm
 * DESCRIPTION
 *  LSK handler for alarm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_stop_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMRDO_SCHD_STOP_TIMER);
    g_prev_channel = 0;
    AlmSendPowerOn();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_error_handler
 * DESCRIPTION
 *  Error handler for FM scheduler
 * PARAMETERS
 *  string      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_error_handler(U16 string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string == STR_ID_FMRDO_SCHEDULER_STARTED_MSG)
    {
        mmi_display_popup(
            get_string(string),
            MMI_EVENT_INFO);
    }
    else
    {
        mmi_display_popup(
            get_string(string),
            MMI_EVENT_FAILURE);
        if (mmi_fmrdo_scheduler_check_pwr_off())
        {
            DeleteScreenIfPresent(SCR_ID_FMRDO_MAIN);
        }
    }
    if (!g_fmrdo.bootup_state)
    {
        SetKeyHandler(mmi_fmrdo_scheduler_stop_alarm, KEY_END, KEY_LONG_PRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_finish_restore
 * DESCRIPTION
 *  Restore FM after schedule finish
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_finish_restore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_scheduler_restore(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_pwroff_or_back
 * DESCRIPTION
 *  Check history and goback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_pwroff_or_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetScreenCountInHistory() > 0 && GetExitScrnID() == SCR_ID_FMRDO_MAIN)
    {
        GoBackHistory();
    }
    if (!(mmi_alm_is_in_alarm() || g_alm_frm_cntx.IsAppExecuting))
    {
        AlmSendPowerOff();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_restore
 * DESCRIPTION
 *  Timer expiry handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_restore(pBOOL timer_expired)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.schedule_restorable)
    {
        g_fmrdo.schedule_restorable = MMI_FALSE;
        g_fmrdo.scheduler_running = MMI_TRUE;
    }
    if (g_fmrdo.scheduler_running)
    {
        g_fmrdo.scheduler_running = MMI_FALSE;
        g_fmrdo.schedule_restorable = (S8)timer_expired;
        if (timer_expired)
        {
            return;
        }
        mmi_alm_enable_pwroff();
        StopTimer(FMRDO_SCHD_STOP_TIMER);
        if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL)
        {
            if (g_prev_channel != 0)
            {
                g_fmrdo.frequency = g_prev_channel;
                g_prev_channel = 0;
                g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);
            }
        }
        else if (g_fmrdo.bootup_state)
        {
            if (g_prev_channel == 0)
            {
                mmi_fmrdo_power_on_check(MMI_FALSE);
            }
            else
            {
            #ifdef __MMI_FM_RADIO_BIND_EARPHONE__
                if (!srv_earphone_is_plug_in())
                {
                    mmi_fmrdo_power_on_check(MMI_FALSE);
                }
                else
            #endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
                {
                    mmi_fmrdo_set_frequency(g_prev_channel);
                }
                g_prev_channel = 0;
            }
        }
        else
        {
            mmi_fmrdo_power_on_check(MMI_FALSE);
            srv_backlight_turn_on(1);
            SetKeyHandler(mmi_fmrdo_scheduler_stop_alarm, KEY_END, KEY_LONG_PRESS);
            if (g_delete_fm_screen)
            {
                if (!DeleteScreenIfPresent(SCR_ID_FMRDO_MAIN))
                {
                    GoBackHistory();
                }
            }
            mmi_fmrdo_scheduler_pwroff_or_back();
            return;
        }
        srv_backlight_turn_on(1);

        if (g_fmschd_stop_channel != 0xFF)
        {
            g_fmrdo.channel_index = g_fmschd_stop_channel;
        }
        else
        {
            g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);
        }
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_channel_name(0);
        }
        if (mmi_fmrdo_scheduler_check_pwr_off())
        {
            if (g_delete_fm_screen)
            {
                if (!DeleteScreenIfPresent(SCR_ID_FMRDO_MAIN))
                {
                    GoBackHistory();
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_alarm_expiry_handler
 * DESCRIPTION
 *  Highlight handler for scheduler application
 * PARAMETERS
 *  index               [IN]          Alarm index
 *  period              [OUT]         Alarm period
 *  power_on_state      [IN]          Power on state
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_fmrdo_scheduler_alarm_expiry_handler(U8 index, U16 *period, MMI_BOOL power_on_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_scheduler_channel_setting_struct *alarm_p = &g_fmrdo.schedule[index / MMI_FMRDO_SCHEDULE_COUNT].channel_setting[index % MMI_FMRDO_SCHEDULE_CHANNEL_COUNT];
    U32 duration;
    MYTIME curr_time;
    U16 string_id = STR_ID_FMRDO_SCHEDULER_STARTED_MSG;
    pBOOL changed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO_RECORD__)
    /* Abort due to exit screen */
    g_fmrdo.rec.user_abort = MMI_FALSE;
    mmi_fmrdo_stop_record_on_exit();
    mmi_fmrdo_util_stop_duration();
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    if (mmi_fmrdo_scheduler_running())
    {
        g_delete_fm_screen = MMI_FALSE;
        mmi_fmrdo_scheduler_restore(MMI_FALSE);
        g_delete_fm_screen = MMI_TRUE;
    }
    if (g_fmrdo.normal_repeat_step_count != 0)
    {
        mmi_fmrdo_set_frequency(g_fmrdo.step_freq);
        g_fmrdo.normal_repeat_step_count = 0;
    }
    mmi_fmrdo_search_frequency_stop();
    mmi_fmrdo_search_all_channels_stop();
    memset(&curr_time, 0, sizeof(curr_time));
    DTGetRTCTime(&curr_time);
    g_fmrdo.bootup_state = (MMI_BOOL) power_on_state;
    mmi_alm_disable_pwroff();
    g_fmschd_stop_channel = 0xFF;
    if (!power_on_state)
    {
        AlmInitLCDModule();
        //g_pwr_context.PowerOnMMIStatus = MMI_POWER_ON_IDLE;
    #ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
    #endif 
    }
    /* This timer is stopped in AlmExpiryHandler so automatically stopped */
    StartTimer(ALARM_TIMER_WAIT_FOR_CALL, 2000, AlmHandlePendingTimeout);
    *period = 2;
    srv_backlight_turn_on(1);
    if (!g_fmrdo.scheduler_running && g_fmrdo.schedule_restorable)
    {
        g_fmrdo.frequency = g_prev_channel;
    }
    if ((g_prev_channel == 0 && g_fmrdo.is_power_on) || g_fmrdo.is_preempted)
    {
        g_prev_channel = g_fmrdo.frequency;
    }
    if (g_fmrdo.schedule[index / MMI_FMRDO_SCHEDULE_COUNT].repeat == MMI_FMRDO_REPEAT_ONCE)
    {
        alarm_p->state = MMI_FMRDO_SCHEDULE_CHANNEL_STATE_DISABLED;
        changed = MMI_TRUE;
    }
    if (!mmi_fmrdo_scheduler_activate_allowed((S8) (index / MMI_FMRDO_SCHEDULE_COUNT)))
    {
        g_fmrdo.activated_schedule = (S8)0xff;
        changed = MMI_TRUE;
    }
    if ((curr_time.nHour < alarm_p->end_hour) ||
        (curr_time.nHour == alarm_p->end_hour && curr_time.nMin < alarm_p->end_min))
    {
        if (alarm_p->frequency >= MIN_FM_FREQUENCY && alarm_p->frequency <= MAX_FM_FREQUENCY)
        {
            g_fmrdo.frequency = alarm_p->frequency;
            WriteValueSlim(NVRAM_FMRDO_LAST_CHANNEL, &g_fmrdo.frequency, DS_SHORT);
            g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);
            g_fmrdo.running_schedule = index;
            if (!IsScreenPresent(SCR_ID_FMRDO_MAIN) && (GetExitScrnID() != SCR_ID_FMRDO_MAIN))
            {
                mmi_fmrdo_run_app();
            }
            if (mmi_fmrdo_scheduler_check_pwr_off())
            {
                g_prev_channel = 0;
            }
            if (!g_fmrdo.is_power_on)
            {
                mmi_fmrdo_power_on_check(MMI_TRUE);
            }
            else
            {
                mmi_fmrdo_set_frequency(g_fmrdo.frequency);
            }
            if (g_fmrdo.in_main_screen)
            {
                mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, MMI_FALSE, g_fmrdo.is_power_on, MMI_TRUE);
            }
            duration = (((alarm_p->end_hour - curr_time.nHour) * 3600) + ((alarm_p->end_min - curr_time.nMin) * 60) - curr_time.nSec) * 1000;
            StartTimer(FMRDO_SCHD_STOP_TIMER, duration, mmi_fmrdo_scheduler_finish_restore);
            g_fmrdo.scheduler_running = MMI_TRUE;
            if (g_charbat_context.isChargerConnected && (!g_charbat_context.ChargingComplete))
            {
                wgui_status_icon_bar_set_icon_animate(STATUS_ICON_BATTERY_STRENGTH);
                wgui_status_icon_bar_set_icon_animate(STATUS_ICON_SUBLCD_BATTERY_STRENGTH);
            }
            wgui_status_icon_bar_update();
        }
        else
        {
            string_id = STR_ID_FMRDO_SCHEDULER_ERROR_FREQ;
            mmi_alm_enable_pwroff();
        }
    }
    else
    {
        string_id = STR_ID_FMRDO_SCHEDULER_ERROR_TIME;
        mmi_alm_enable_pwroff();
    }
    mmi_fmrdo_scheduler_error_handler(string_id);
    if (changed)
    {
        mmi_fmrdo_scheduler_save_to_nvram();
    }
    return ALM_HAS_IND;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_resume_schedule
 * DESCRIPTION
 *  Re-initialize queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_resume_schedule(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_scheduler_channel_setting_struct *alarm_p = &g_fmrdo.schedule[index / MMI_FMRDO_SCHEDULE_COUNT].channel_setting[index % MMI_FMRDO_SCHEDULE_CHANNEL_COUNT];
    MYTIME curr_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&curr_time, 0, sizeof(curr_time));
    DTGetRTCTime(&curr_time);
    g_fmrdo.scheduler_running = MMI_TRUE;
    if ((curr_time.nHour < alarm_p->end_hour) ||
        (curr_time.nHour == alarm_p->end_hour && curr_time.nMin < alarm_p->end_min))
    {
        g_fmrdo.schedule_restorable = MMI_FALSE;
        mmi_fmrdo_power_on_check(MMI_TRUE);
    }
    else
    {
        if (g_prev_channel != 0)
        {
            mmi_fmrdo_power_on_check(MMI_TRUE);
        }
        mmi_fmrdo_scheduler_restore(MMI_FALSE);
    }
    if (g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_redraw_main_channel_name(0);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_reinit_queue
 * DESCRIPTION
 *  Re-initialize queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_reinit_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init only for activated schedule for others cancel alarm */
    if (g_fmrdo.activated_schedule != (S8)-1)
    {
        for (counter2 = 0; counter2 < MMI_FMRDO_SCHEDULE_CHANNEL_COUNT; counter2++)
        {
            if (g_fmrdo.schedule[g_fmrdo.activated_schedule].channel_setting[counter2].state == MMI_FMRDO_SCHEDULE_CHANNEL_STATE_ACTIVE)
            {
                AlmSetAlarm((U8) (ALM_FMRDO_START + (g_fmrdo.activated_schedule * MMI_FMRDO_SCHEDULE_COUNT) + counter2));
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_get_weekdays
 * DESCRIPTION
 *  Highlight handler for scheduler application
 * PARAMETERS
 *  index       [IN]        Alarm index
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_fmrdo_scheduler_get_weekdays(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_activate_allowed
 * DESCRIPTION
 *  Highlight handler for scheduler application
 * PARAMETERS
 *  schedule        [IN]        Schedule index
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_fmrdo_scheduler_activate_allowed(S8 schedule)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (schedule == -1)
    {
        return MMI_TRUE;
    }
    for (counter = 0; counter < MMI_FMRDO_SCHEDULE_CHANNEL_COUNT; counter++)
    {
        if (g_fmrdo.schedule[schedule].channel_setting[counter].state == MMI_FMRDO_SCHEDULE_CHANNEL_STATE_ACTIVE)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_save_to_nvram
 * DESCRIPTION
 *  Save schedule to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_save_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buffer[NVRAM_EF_FMRDO_SCHEDULER_SIZE];
    mmi_fmrdo_scheduler_setting_struct *data_p = (mmi_fmrdo_scheduler_setting_struct *)buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(data_p, &g_fmrdo.schedule[0], sizeof(g_fmrdo.schedule));
    buffer[NVRAM_EF_FMRDO_SCHEDULER_SIZE - 1] = g_fmrdo.activated_schedule;
    WriteRecordSlim(NVRAM_EF_FMRDO_SCHEDULER_LID, 1, &buffer, NVRAM_EF_FMRDO_SCHEDULER_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_set_keys
 * DESCRIPTION
 *  Set keys for scheduler at bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_set_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_fmrdo_scheduler_check_pwr_off())
    {
        if (!g_fmrdo.bootup_state)
        {
            for (i = 0; i < MAX_KEY_TYPE; i++)
            {
                ClearKeyHandler(KEY_END, i);
            }
        }
        SetKeyHandler(mmi_fmrdo_scheduler_finish_restore, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(MMI_dummy_function, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(MMI_dummy_function, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_fmrdo_scheduler_finish_restore, KEY_END, KEY_EVENT_UP);
        if (!g_fmrdo.bootup_state)
        {
            SetKeyHandler(mmi_fmrdo_scheduler_stop_alarm, KEY_END, KEY_LONG_PRESS);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_running
 * DESCRIPTION
 *  Check if FM Scheduler is running
 * PARAMETERS
 *  void
 * RETURNS
 *  scheduler state
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_scheduler_running(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_fmrdo.scheduler_running || g_fmrdo.schedule_restorable);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_prev_channel
 * DESCRIPTION
 *  Check if FM Scheduler is running
 * PARAMETERS
 *  frequency       [IN]        Update frequency
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_prev_channel(U16 frequency)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((frequency == 0) && (g_prev_channel != 0))
    {
        g_fmrdo.frequency = g_prev_channel;
    }
    g_prev_channel = frequency;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_check_pwr_off
 * DESCRIPTION
 *  Check whether it is power off alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  Power off alarm?
 *****************************************************************************/
pBOOL mmi_fmrdo_scheduler_check_pwr_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_CHARGE) ||
    #ifdef __MMI_USB_SUPPORT__
        (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_USB) ||
    #endif 
        (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_ALARM))
    {
        return MMI_TRUE;
    }
    return !srv_bootup_is_completed();
}

#endif /* __MMI_FM_RADIO_SCHEDULER__ */ 
#endif /* __MMI_FM_RADIO__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scheduler_dummy_function
 * DESCRIPTION
 *  Dummy function for warning removal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_scheduler_dummy_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}

