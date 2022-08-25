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
 * aud_melody.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes voice memo related functions of audio manager task.
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
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    AUD_VM
 * DESCRIPTION
 *    This module defines the voice memo related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/

//#include "kal_release.h"
#include "kal_trace.h"
//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */
//#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//#include "event_shed.h" /* Event scheduler */
//#include "stack_timer.h"        /* Stack timer */
//#include "app_buff_alloc.h"

/* global includes */
#include "l1audio.h"
//#include "gpio_sw.h"
//#include "alerter_sw.h"
#include "device.h"
//#include "resource_audio.h"
#include "custom_equipment.h"

//#include "custom_uem.h"

//#include "nvram_enums.h"
//#include "nvram_struct.h"
//#include "nvram_user_defs.h"
//#include "nvram_data_items.h"
//#include "custom_nvram_editor_data_item.h"
/* for FAT FS */
//#include "fat_fs.h"
/* DRM_REPLACE */
//#include "drm_gprot.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
//#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_main.h"
#include "aud_main.h"
#include "aud_player.h"
#include "aud_player_mma.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "mmiapi_enum.h"
#include "stack_config.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#if defined(__MMI_SUPPORT_BACKLIGHT_SYNC__) || defined(__MMI_SUPPORT_LED_SYNC__) || defined(__MMI_SUPPORT_VIBRATOR_SYNC__)
#include "mmiapi_struct.h"
#endif

//#include "aud_daf_parser.h"

/*-----------------------------------------------------------------------------
                    macros, defines, typedefs, enums
-----------------------------------------------------------------------------*/

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/* -- added for turn on/off backlight by MMI task -- */
#define CTRL_BACKLIGHT_REQ_IDLE 0
#define CTRL_BACKLIGHT_REQ_WAIT 1
#define CTRL_BACKLIGHT_REQ_WAIT_CLOSE 2
#define CTRL_BACKLIGHT_REQ_CLOSE 3
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 

#ifdef __MED_IMY_EVENT__
typedef struct
{
    kal_bool vibrator_enabled;
    kal_bool vibrator_on;
    kal_bool led_on;
    kal_bool backlight_on;
    kal_bool vibrator_on_stored;
    kal_bool led_on_stored;
    kal_bool backlight_on_stored;

    kal_bool backlight_ctrl_in_use;
    kal_bool backlight_ctrl_restore;

    #ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
    kal_uint8 backlight_ctrl_state;
    #endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */

    #ifdef __MMI_SUPPORT_LED_SYNC__
    kal_uint8 wait_for_led_ctrl_rsp;
    #endif /* __MMI_SUPPORT_LED_SYNC__ */

    #ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
    kal_bool wait_for_vibrator_ctrl_rsp;
    #endif /*__MMI_SUPPORT_VIBRATOR_SYNC__*/

    #ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
    volatile kal_mutexid backlight_ctrl_mutex;
    #endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */

    #ifdef __MMI_SUPPORT_LED_SYNC__
    volatile kal_mutexid led_ctrl_mutex;
    #endif /* __MMI_SUPPORT_LED_SYNC__ */

    #ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
    volatile kal_mutexid vibrator_ctrl_mutex;
    #endif /*__MMI_SUPPORT_VIBRATOR_SYNC__*/

} aud_melody_context_struct;
#endif


/*-----------------------------------------------------------------------------
                    data declaraions
 ----------------------------------------------------------------------------*/
#ifdef __MED_IMY_EVENT__
static aud_melody_context_struct aud_melody_ctx;
#endif

kal_uint8 current_playing_melody_volume_level = 0;  /* this variable will keep track of current playing melody volume level */

#if defined(TV_OUT_SUPPORT)
extern kal_bool audio_tv_cable_in;
extern kal_bool audio_tv_loud_speaker;
#endif

/*-----------------------------------------------------------------------------
                    function prototypes
 ----------------------------------------------------------------------------*/ 
#ifdef __MED_BT_A2DP_MOD__
#if defined(__BTMTK__)
extern kal_bool aud_bt_a2dp_is_mute_phone(void);
#endif
#endif /* __MED_BT_A2DP_MOD__ */ 

#ifdef __J2ME__
extern kal_uint8 jam_get_vib_on(void);
#endif  /* __J2ME__ */

/*****************************************************************************
 * FUNCTION
 *  aud_melody_init
 * DESCRIPTION
 *  This function is used to init aud_melody module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->source_type = AUD_UNKNOWN_SOURCE_TYPE;

#ifdef __MED_IMY_EVENT__    
    aud_melody_ctx.vibrator_enabled = KAL_TRUE;
    aud_melody_ctx.vibrator_on = KAL_FALSE;
    aud_melody_ctx.led_on = KAL_FALSE;
    aud_melody_ctx.backlight_on = KAL_TRUE;
    aud_melody_ctx.vibrator_on_stored = KAL_FALSE;
    aud_melody_ctx.led_on_stored = KAL_FALSE;
    aud_melody_ctx.backlight_on_stored = KAL_TRUE;
    aud_melody_ctx.backlight_ctrl_in_use = KAL_FALSE;
    aud_melody_ctx.backlight_ctrl_restore = KAL_FALSE;

    #ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
    aud_melody_ctx.backlight_ctrl_state = CTRL_BACKLIGHT_REQ_IDLE;
    aud_melody_ctx.backlight_ctrl_mutex = kal_create_mutex("backlight_ctrl_mutex");
    #endif

    #ifdef __MMI_SUPPORT_LED_SYNC__
    aud_melody_ctx.wait_for_led_ctrl_rsp = 0;
    aud_melody_ctx.led_ctrl_mutex = kal_create_mutex("led_ctrl_mutex");
    #endif

    #ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
    aud_melody_ctx.wait_for_vibrator_ctrl_rsp = KAL_FALSE;
    aud_melody_ctx.vibrator_ctrl_mutex = kal_create_mutex("vibrator_ctrl_mutex");
    #endif

#endif

    return ;
}

#ifdef __MED_IMY_EVENT__
/*****************************************************************************
 * FUNCTION
 *  aud_set_vibrator_enabled_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_vibrator_enabled_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_vibrator_enabled_req_struct *msg_p =
        (media_aud_set_vibrator_enabled_req_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_melody_ctx.vibrator_enabled = (kal_bool) msg_p->enabled;

}

#ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
/*****************************************************************************
 * FUNCTION
 *  aud_led_ctrl_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vibrator_ctrl_rsp_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_device_play_rsp_struct *msg_p = (mmiapi_device_play_rsp_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(aud_melody_ctx.vibrator_ctrl_mutex);

    if(msg_p->type == MMIAPI_DEV_TYPE_VIBRATOR)
    {
        /* The on/off is sent to MMI by L1Audio, Sync on/off here whether MMI result is success */
        if (msg_p->level == MMIAPI_DEV_LEVEL_1)
        {
            /* MMI responses that it finishs turning on vibrator request */
            if (!aud_melody_ctx.vibrator_on)
            {
                aud_send_vibrator_ctrl_req(MOD_MMI, 0);  /* request to turn off vibrator */
                aud_melody_ctx.wait_for_vibrator_ctrl_rsp = KAL_TRUE;
            }
            else
            {
                aud_melody_ctx.wait_for_vibrator_ctrl_rsp = KAL_FALSE;
            }
        }
        else
        {
            /* MMI responses that it finishs turning off vibrator request */
            if (aud_melody_ctx.vibrator_on)
            {
                aud_send_vibrator_ctrl_req(MOD_MMI, 1);  /* request to turn vibrator led */
                aud_melody_ctx.wait_for_vibrator_ctrl_rsp = KAL_TRUE;
            }
            else
            {
                aud_melody_ctx.wait_for_vibrator_ctrl_rsp = KAL_FALSE;
            }
        }
    }
    kal_give_mutex(aud_melody_ctx.vibrator_ctrl_mutex);

}
#endif /* __MMI_SUPPORT_VIBRATOR_SYNC__ */ 


#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/*****************************************************************************
 * FUNCTION
 *  aud_backlight_ctrl_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_backlight_ctrl_rsp_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_backlight_control_rsp_struct *msg_p = (mmiapi_backlight_control_rsp_struct*) ilm_ptr->local_para_ptr;
    kal_bool on_off = (msg_p->on_off ? KAL_TRUE : KAL_FALSE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(aud_melody_ctx.backlight_ctrl_mutex);
    switch (aud_melody_ctx.backlight_ctrl_state)
    {
        case CTRL_BACKLIGHT_REQ_IDLE:
            ASSERT(0);
            break;
        case CTRL_BACKLIGHT_REQ_WAIT:
            if (on_off == aud_melody_ctx.backlight_on)
            {
                aud_melody_ctx.backlight_ctrl_state = CTRL_BACKLIGHT_REQ_IDLE;
            }
            else
            {
                if (aud_melody_ctx.backlight_on)
                {
                    aud_send_backlight_ctrl_req(MOD_MMI, 1, 1 /* grab backlight control */);
                }
                else
                {
                    aud_send_backlight_ctrl_req(MOD_MMI, 0, 0 /* don't grab backlight control */);
                }
            }
            break;
        case CTRL_BACKLIGHT_REQ_WAIT_CLOSE:
            aud_send_backlight_ctrl_req(MOD_MMI, (kal_uint8) aud_melody_ctx.backlight_on, 0);
            aud_melody_ctx.backlight_ctrl_state = CTRL_BACKLIGHT_REQ_CLOSE;
            break;
        case CTRL_BACKLIGHT_REQ_CLOSE:
            if (on_off == aud_melody_ctx.backlight_on)
            {
                aud_melody_ctx.backlight_ctrl_state = CTRL_BACKLIGHT_REQ_IDLE;
            }
            else
            {
                ASSERT(0);
            }
            break;
    }
    kal_give_mutex(aud_melody_ctx.backlight_ctrl_mutex);


}
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 


#ifdef __MMI_SUPPORT_LED_SYNC__
/*****************************************************************************
 * FUNCTION
 *  aud_led_ctrl_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_led_ctrl_rsp_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmiapi_led_control_rsp_struct *msg_p = (mmiapi_led_control_rsp_struct*) ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(aud_melody_ctx.led_ctrl_mutex);
    if (msg_p->on_off)
    {
        /* MMI responses that it finishs turning on led request */
        if (!aud_melody_ctx.led_on)
        {
            aud_send_led_ctrl_req(MOD_MMI, 0);  /* request to turn off led */
            aud_melody_ctx.wait_for_led_ctrl_rsp = 1;
        }
        else
        {
            aud_melody_ctx.wait_for_led_ctrl_rsp = 0;
        }
    }
    else
    {
        /* MMI responses that it finishs turning off led request */
        if (aud_melody_ctx.led_on)
        {
            aud_send_led_ctrl_req(MOD_MMI, 1);  /* request to turn on led */
            aud_melody_ctx.wait_for_led_ctrl_rsp = 1;
        }
        else
        {
            aud_melody_ctx.wait_for_led_ctrl_rsp = 0;
        }
    }
    kal_give_mutex(aud_melody_ctx.led_ctrl_mutex);


}
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/*****************************************************************************
 * FUNCTION
 *  aud_melody_imy_close_backlight_ctrl
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_imy_close_backlight_ctrl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(aud_melody_ctx.backlight_ctrl_mutex);
    /* -- added for turn on/off backlight by MMI task -- */
    if (aud_melody_ctx.backlight_ctrl_state == CTRL_BACKLIGHT_REQ_IDLE)
    {
        if (aud_melody_ctx.backlight_ctrl_in_use)
        {
            aud_send_backlight_ctrl_req(MOD_MMI, 1, 0);
            aud_melody_ctx.backlight_ctrl_state = CTRL_BACKLIGHT_REQ_CLOSE;
        }
    }
    else if (aud_melody_ctx.backlight_ctrl_state != CTRL_BACKLIGHT_REQ_CLOSE)
    {
        aud_melody_ctx.backlight_ctrl_state = CTRL_BACKLIGHT_REQ_WAIT_CLOSE;
    }
    aud_melody_ctx.backlight_ctrl_in_use = KAL_FALSE;
    aud_melody_ctx.backlight_on = KAL_TRUE;
    kal_give_mutex(aud_melody_ctx.backlight_ctrl_mutex);
}
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 


/*****************************************************************************
 * FUNCTION
 *  aud_melody_stop_driver
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_stop_driver(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_TRC_MELODY_STOP_DRIVER, aud_melody_ctx.vibrator_enabled);

    /* turn off vibrator, if on */
#ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
    kal_take_mutex(aud_melody_ctx.vibrator_ctrl_mutex);
    if (aud_melody_ctx.vibrator_enabled)
    {
        if (aud_melody_ctx.vibrator_on)
        {
            /* -- added for turn on/off led by MMI task -- */
            if (!aud_melody_ctx.wait_for_vibrator_ctrl_rsp)
            {
                aud_send_vibrator_ctrl_req(MOD_MMI, 0);
                aud_melody_ctx.wait_for_vibrator_ctrl_rsp = KAL_TRUE;
            }
            custom_uem_gpio_set_level(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
            aud_melody_ctx.vibrator_on = KAL_FALSE;
        }
    }
    kal_give_mutex(aud_melody_ctx.vibrator_ctrl_mutex);    
#else /*__MMI_SUPPORT_VIBRATOR_SYNC__*/
    if (aud_melody_ctx.vibrator_enabled)
    {
        if (aud_melody_ctx.vibrator_on)
        {
            custom_uem_gpio_set_level(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
            aud_melody_ctx.vibrator_on = KAL_FALSE;
        }
    }
#endif /*__MMI_SUPPORT_VIBRATOR_SYNC__*/

    /* turn off led, if on */
#ifndef __MMI_SUPPORT_LED_SYNC__
    if (aud_melody_ctx.led_on)
    {
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
        aud_melody_ctx.led_on = KAL_FALSE;
    }
#else /* __MMI_SUPPORT_LED_SYNC__ */ 
    kal_take_mutex(aud_melody_ctx.led_ctrl_mutex);
    if (aud_melody_ctx.led_on)
    {
        /* -- added for turn on/off led by MMI task -- */
        if (!aud_melody_ctx.wait_for_led_ctrl_rsp)
        {
            aud_send_led_ctrl_req(MOD_MMI, 1);
            aud_melody_ctx.wait_for_led_ctrl_rsp = 1;
        }
        aud_melody_ctx.led_on = KAL_FALSE;
    }
    kal_give_mutex(aud_melody_ctx.led_ctrl_mutex);
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

#ifndef __MMI_SUPPORT_BACKLIGHT_SYNC__
    if (!aud_melody_ctx.backlight_on)
    {
        custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        custom_uem_gpio_set_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
        custom_uem_gpio_set_level(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL5);
    }
    aud_melody_ctx.backlight_on = KAL_TRUE;
#else /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
    aud_melody_imy_close_backlight_ctrl();
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_imy_vibrator_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_imy_vibrator_hdlr(kal_bool on)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_TRC_MELODY_IMY_VIBRATOR_HDLR, aud_melody_ctx.vibrator_enabled, on);

#ifdef __J2ME__
    if (jam_get_vib_on())
#endif /* __j2ME__ */
    {
    #ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
        /* -- added for turn on/off led by MMI task -- */
        kal_take_mutex(aud_melody_ctx.vibrator_ctrl_mutex);
        if (aud_melody_ctx.vibrator_enabled)
        {
            if (!aud_melody_ctx.wait_for_vibrator_ctrl_rsp)
            {
                aud_send_vibrator_ctrl_req(MOD_MMI, (kal_uint8) on);
                aud_melody_ctx.wait_for_vibrator_ctrl_rsp = KAL_TRUE;
            }
            aud_melody_ctx.vibrator_on = on;
        }
        kal_give_mutex(aud_melody_ctx.vibrator_ctrl_mutex);
    #else /*__MMI_SUPPORT_VIBRATOR_SYNC__*/
        if (aud_melody_ctx.vibrator_enabled)
        {
            if (on)
            {
                custom_uem_gpio_set_level(GPIO_DEV_VIBRATOR, VIBRATOR_ON);
            }
            else
            {
                custom_uem_gpio_set_level(GPIO_DEV_VIBRATOR, VIBRATOR_OFF);
            }
            aud_melody_ctx.vibrator_on = on;
        }
    #endif /*__MMI_SUPPORT_VIBRATOR_SYNC__*/
    }

#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_imy_led_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_imy_led_hdlr(kal_bool on)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SUPPORT_LED_SYNC__
    if (on)
    {
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL5);
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL5);
    }
    else
    {
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_2, LED_LIGHT_LEVEL0);
        custom_uem_gpio_set_level(GPIO_DEV_LED_STATUS_3, LED_LIGHT_LEVEL0);
    }
    aud_melody_ctx.led_on = on;
#else /* __MMI_SUPPORT_LED_SYNC__ */ 
    kal_take_mutex(aud_melody_ctx.led_ctrl_mutex);
    /* -- added for turn on/off led by MMI task -- */
    if (!aud_melody_ctx.wait_for_led_ctrl_rsp)
    {
        aud_send_led_ctrl_req(MOD_MMI, (kal_uint8) on);
        aud_melody_ctx.wait_for_led_ctrl_rsp = 1;
    }
    aud_melody_ctx.led_on = on;
    kal_give_mutex(aud_melody_ctx.led_ctrl_mutex);
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_imy_backlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  on      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_imy_backlight_hdlr(kal_bool on)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SUPPORT_BACKLIGHT_SYNC__
    if (on)
    {
        custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
        custom_uem_gpio_set_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL5);
        custom_uem_gpio_set_level(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL5);
        aud_melody_ctx.backlight_ctrl_in_use = KAL_TRUE;
    }
    else
    {
        custom_uem_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL2);
        custom_uem_gpio_set_level(GPIO_DEV_LED_SUBLCD, LED_LIGHT_LEVEL2);
        custom_uem_gpio_set_level(GPIO_DEV_LED_KEY, LED_LIGHT_LEVEL0);
        aud_melody_ctx.backlight_ctrl_in_use = KAL_FALSE;
    }
    aud_melody_ctx.backlight_on = on;
#else /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
    kal_take_mutex(aud_melody_ctx.backlight_ctrl_mutex);
    /* -- added for turn on/off backlight by MMI task -- */
    if (aud_melody_ctx.backlight_ctrl_state == CTRL_BACKLIGHT_REQ_IDLE)
    {
        if (on)
        {
            aud_send_backlight_ctrl_req(MOD_MMI, 1, 1 /* grab backlight control */);
        }
        else
        {
            aud_send_backlight_ctrl_req(MOD_MMI, 0, 0 /* don't grab backlight control */);
        }
    }
    aud_melody_ctx.backlight_ctrl_state = CTRL_BACKLIGHT_REQ_WAIT;
    aud_melody_ctx.backlight_ctrl_in_use = KAL_TRUE;
    aud_melody_ctx.backlight_on = on;
    kal_give_mutex(aud_melody_ctx.backlight_ctrl_mutex);
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_store_driver_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_store_driver_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
    kal_take_mutex(aud_melody_ctx.vibrator_ctrl_mutex);
    aud_melody_ctx.vibrator_on_stored = aud_melody_ctx.vibrator_on;
    kal_give_mutex(aud_melody_ctx.vibrator_ctrl_mutex);
#else /*__MMI_SUPPORT_VIBRATOR_SYNC__*/
    aud_melody_ctx.vibrator_on_stored = aud_melody_ctx.vibrator_on;
#endif /*__MMI_SUPPORT_VIBRATOR_SYNC__*/

#ifdef __MMI_SUPPORT_LED_SYNC__
    kal_take_mutex(aud_melody_ctx.led_ctrl_mutex);
    aud_melody_ctx.led_on_stored = aud_melody_ctx.led_on;
    kal_give_mutex(aud_melody_ctx.led_ctrl_mutex);
#else /* __MMI_SUPPORT_LED_SYNC__ */ 
    aud_melody_ctx.led_on_stored = aud_melody_ctx.led_on;
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
    kal_take_mutex(aud_melody_ctx.backlight_ctrl_mutex);
    aud_melody_ctx.backlight_on_stored = aud_melody_ctx.backlight_on;
    aud_melody_ctx.backlight_ctrl_restore = aud_melody_ctx.backlight_ctrl_in_use; 
    kal_give_mutex(aud_melody_ctx.backlight_ctrl_mutex);
#else /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
    aud_melody_ctx.backlight_on_stored = aud_melody_ctx.backlight_on;
    aud_melody_ctx.backlight_ctrl_restore = aud_melody_ctx.backlight_ctrl_in_use; 
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  aud_restore_driver_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_restore_driver_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_melody_imy_vibrator_hdlr(aud_melody_ctx.vibrator_on_stored);
    aud_melody_imy_led_hdlr(aud_melody_ctx.led_on_stored);

    /* Only restore backlight if previous turn on/off by driver */
    if(aud_melody_ctx.backlight_ctrl_restore)
    {
        aud_melody_imy_backlight_hdlr(aud_melody_ctx.backlight_on_stored);
    }
}
#endif /*__MED_IMY_EVENT__*/

/*****************************************************************************
 * FUNCTION
 *  aud_melody_set_max_swing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  max_swing       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_set_max_swing(kal_uint16 max_swing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_VALUE1_TRACE(max_swing);
    Media_Control(MEDIA_CTRL_MAX_SWING, max_swing);
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_MELODY, device);
    Media_SetOutputDevice(device);
}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_set_output_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_set_output_volume(kal_uint8 volume, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool mute = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_MEDIA, volume, digital_gain_index);
    Media_SetOutputVolume(volume, digital_gain_index);

    /* Set digitial gain to 0 when mute */
    if(volume == 0)
    {
        mute = KAL_TRUE;
    }

    aud_audio_mute_digital_gain(mute, AUD_DIGITAL_GAIN_AUDIO);

}


/*****************************************************************************
 * FUNCTION
 *  aud_melody_set_volume_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_melody_set_volume_by_mode(kal_uint8 mode, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 new_level;
    kal_uint8 analog_gain;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_TRC_SET_MELODY_VOLUME, mode, level);

#ifdef __LINE_IN_SUPPORT__
	if(aud_is_bt_box_linein_enable())
	{
		aud_linein_set_volume_by_mode(mode,level);
		return;
	}
#endif
    
    /* If the second bit(from MSB) is set, the level 0 means mute. */
    if (AUD_VOL_IS_MUTE(level))
    {
        aud_melody_set_output_volume(0, 0);
        return;
    }

    if (AUD_VOL_IS_MUTE_AT_LEVEL_0(level))
    {
        new_level = AUD_VOL_GET_VOLUME_LEVEL(level) - 1;
    }
    else
    {
        new_level = AUD_VOL_GET_VOLUME_LEVEL(level);
    }

    /* 7 level volume (MSB bit is not set) */
    if (AUD_VOL_IS_7_LEVEL_VOLUME(level))
    {
    #if defined(TV_OUT_SUPPORT)
        if (mode == VOL_TV_OUT)
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_TVO, new_level);
        }
        else
    #endif /* TV_OUT_SUPPORT */
        {
            analog_gain = aud_get_volume_gain(mode, AUD_VOLUME_MEDIA, new_level);
        }
        
        aud_melody_set_output_volume(analog_gain, 0);

    #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
        BT_SetLevelVolume(new_level+1,7);
    #endif
    }
    /* 16 level volume */
    else
    {
        /* Un-mute digital gain in case it is turn off by set mute function */
        aud_audio_mute_digital_gain(KAL_FALSE, AUD_DIGITAL_GAIN_AUDIO);

    #ifdef __16_LEVEL_AUDIO_VOLUME__
        if (new_level < aud_context_p->melody_max_volume_level)
        {
            Media_SetLevelVolume( aud_context_p->acoustic_data.max_melody_volume_gain[mode],
                aud_context_p->acoustic_data.melody_volume_gain_step[mode],
                aud_context_p->melody_max_volume_level - 1 - new_level);

        #if defined(__BT_A2DP_SUPPORT__) || defined(__BT_AUDIO_VIA_SCO__)
            BT_SetLevelVolume(new_level+1,aud_context_p->melody_max_volume_level);
        #endif


        }
    #else
        ASSERT(0);
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_active_ring_tone_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_active_ring_tone_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* incoming call ring, alarm, message use the same volume */
    kal_uint8 gain_audio_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __GAIN_TABLE_SUPPORT__
    /* store playing melody volume level */
    current_playing_melody_volume_level = aud_get_volume_level(aud_context_p->audio_mode, AUD_VOLUME_MEDIA);
    /* if it's headset mode and output to both earphone & loud speaker, use normal mode gain value */
    if (aud_context_p->audio_mode == AUD_MODE_HEADSET &&
        aud_context_p->melody_output_device == AUDIO_DEVICE_SPEAKER_BOTH)
    {
        gain_audio_mode = VOL_NORMAL;
    }
    else
    {
        gain_audio_mode = aud_context_p->audio_mode;
    }

    aud_melody_set_volume_by_mode(gain_audio_mode, current_playing_melody_volume_level);

#else /* #ifdef __GAIN_TABLE_SUPPORT__ */
    kal_uint64 volume;

    volume = aud_context_p->volume_tbl[AUD_VOLUME_MEDIA];
    aud_volume_set_media_volume(volume);
#endif /* __GAIN_TABLE_SUPPORT__ */

    /* disable audio mute when the volume is set again */
    aud_context_p->audio_mute = KAL_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  aud_get_active_device_path_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  request_path      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_active_device_path_by_mode(kal_uint8 request_path, void (*set_path_func)(kal_uint8))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 device;
    kal_uint8 output_path;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Keep audio path after set path */
    aud_context_p->melody_output_device = request_path;

    /* Check if play to both path when SCO connected, or just output to BT earphone */
#if defined(__MED_BT_AUDIO_VIA_SCO__) || defined(__MED_BT_FM_VIA_SCO__)
    if (aud_bt_hfp_is_audio_path_on())
    {
        if(request_path == AUDIO_DEVICE_SPEAKER_BOTH)
        {
            device = custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER);
            set_path_func(device);            
        }
        else
        {
            set_path_func(0);
        }

        /* Change speech to BT earphone in case turn off by keytone */
        if(!aud_bt_hfp_is_speech_path_on())
        {
            aud_bt_hfp_set_speech_path_on();
        }
        return;
    }
#endif /* #ifdef __BT_AUDIO_VIA_SCO__ */

#if defined(__MED_BT_A2DP_MOD__) && defined(__BTMTK__)
    if (!aud_bt_a2dp_is_mute_phone())
#endif
    {
        if (aud_context_p->audio_mode == AUD_MODE_HEADSET)
        {
            device = custom_cfg_hw_aud_output_path(request_path);
            set_path_func(device);
        }
        else /* AUD_MODE_NORMAL, AUD_MODE_LOUDSPK */
        {
        #if defined(TV_OUT_SUPPORT)
            if (audio_tv_cable_in)
            {
                /* Set output path to both TV out and mobile device */
                if(audio_tv_loud_speaker || request_path == AUDIO_DEVICE_SPEAKER_BOTH)
                {
                    output_path = AUDIO_DEVICE_SPEAKER_BOTH;
                }
                else  /* Set output path to earphone to let it play through TV only. */
                {
                    output_path = AUDIO_DEVICE_SPEAKER2;
                }
            }
            else
        #endif /* #if defined(TV_OUT_SUPPORT) */ 
            {
                if(aud_context_p->audio_mode == AUD_MODE_LOUDSPK || request_path == AUDIO_DEVICE_SPEAKER2)
                {
                    output_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                else
                {
                    output_path = request_path;
                }
            }

            device = custom_cfg_hw_aud_output_path(output_path);
            set_path_func(device);
        }

    #ifdef __GAIN_TABLE_SUPPORT__
        /* Update volume */
        if (! aud_context_p->audio_mute)
        {
        #ifdef __ATV_SUPPORT__
		    if(aud_atv_is_open())
            {        
                aud_set_active_atv_volume();
            }
            else
        #endif
        #ifdef __MED_FMR_MOD__
            if(aud_fmr_is_power_on())
            {
                aud_set_active_fmr_volume();
            }
            else
        #endif
            {
                aud_set_active_ring_tone_volume();  
            }
        }      
    #endif /*__GAIN_TABLE_SUPPORT__*/
	
    }
}

#ifdef __MED_IMY_EVENT__
/*****************************************************************************
 * FUNCTION
 *  aud_melody_event_hdlr
 * DESCRIPTION
 *  This function handles events from MIDI playback.
 * PARAMETERS
 *  pt_player    [IN]      Player handle.
 *  e_event      [IN]      MIDI event.  
 * RETURNS
 *  
 *****************************************************************************/
void aud_melody_event_hdlr(med_aud_player_t* player_p, Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   result;
    Media_Event ext_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case MEDIA_EXTENDED_EVENT:
        {
            while (1)
            {
                result = player_p->get(player_p, MMA_PLAYER_GET_EXT_EVENT, &ext_event);

                if (result != MED_RES_OK || ext_event == MEDIA_NONE)
                {
                    break; /* Terminate the loop */
                }
                
                switch (ext_event)
                {
                    case MEDIA_LED_ON:
                        aud_melody_imy_led_hdlr(KAL_TRUE);
                        break;
                    case MEDIA_LED_OFF:
                        aud_melody_imy_led_hdlr(KAL_FALSE);
                        break;
                    case MEDIA_VIBRATOR_ON:
                        aud_melody_imy_vibrator_hdlr(KAL_TRUE);
                        break;
                    case MEDIA_VIBRATOR_OFF:
                        aud_melody_imy_vibrator_hdlr(KAL_FALSE);
                        break;
                    case MEDIA_BACKLIGHT_ON:
                        aud_melody_imy_backlight_hdlr(KAL_TRUE);
                        break;
                    case MEDIA_BACKLIGHT_OFF:
                        aud_melody_imy_backlight_hdlr(KAL_FALSE);
                        break;
                    default:
                        break;
                }
            }

            break;
        }
        case MEDIA_LED_ON:
            aud_melody_imy_led_hdlr(KAL_TRUE);
            break;
        case MEDIA_LED_OFF:
            aud_melody_imy_led_hdlr(KAL_FALSE);
            break;
        case MEDIA_VIBRATOR_ON:
            aud_melody_imy_vibrator_hdlr(KAL_TRUE);
            break;
        case MEDIA_VIBRATOR_OFF:
            aud_melody_imy_vibrator_hdlr(KAL_FALSE);
            break;
        case MEDIA_BACKLIGHT_ON:
            aud_melody_imy_backlight_hdlr(KAL_TRUE);
            break;
        case MEDIA_BACKLIGHT_OFF:
            aud_melody_imy_backlight_hdlr(KAL_FALSE);
            break;
        default:
            break;
    }
}
#endif

#endif /* MED_NOT_PRESENT */ 

