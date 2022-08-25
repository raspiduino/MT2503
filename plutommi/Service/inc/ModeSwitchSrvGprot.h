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
 * ModeSwitchSrvGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines internal interface of mode switch service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __MODE_SWTICH_SRV_GPROT_H__
#define __MODE_SWTICH_SRV_GPROT_H__

#include "MMIDataType.h"
/* auto add by kw_check begin */
#include "mmi_res_range_def.h"
/* auto add by kw_check end */
/*
 * For mode switch notification 
 */
typedef enum
{
    EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY = MODE_SWITCH_SRV_BASE, /* Message for pre mode switch */
    EVT_ID_SRV_MODE_SWITCH_SWITCH_OTHER_NOTIFY,           /* RF switch is done, begin to switch other connection */
    EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY                      /* Message for mode switch finished */
} srv_mode_switch_notification_enum;

/*
 * For proc function event
 */
typedef enum
{
    EVT_ID_SRV_MODE_SWITCH_FINISH,

    EVT_ID_SRV_MODE_SWITCH_EVENT_END
} srv_mode_switch_event_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U16 result;
} srv_mode_switch_rsp_event_struct;

/*
 * Mode enum
 */
typedef enum
{
	SRV_MODE_SWITCH_ALL_OFF = 0x00,                      /* All SIMs are turn off */
	SRV_MODE_SWITCH_SIM1 = 0x01,                         /* SIM1 only */
	SRV_MODE_SWITCH_SIM2 = 0x02,                         /* SIM2 only */
	SRV_MODE_SWITCH_SIM3 = 0x04,                         /* SIM3 only */
	SRV_MODE_SWITCH_SIM4 = 0x08,                         /* SIM4 only */

	SRV_MODE_SWITCH_FLIGHT_MODE = SRV_MODE_SWITCH_ALL_OFF, /* only use for single SIM */
#if (MMI_MAX_SIM_NUM == 1)
	SRV_MODE_SWITCH_NORMAL_MODE = SRV_MODE_SWITCH_SIM1,    /* only use for single SIM */
#endif

    /* For SIM1/SIM2/SIM3/SIM4 combination, please apply bit operation to get the mode switch type */

    /* For SRV_MODE_SWITCH_SIM_ALL, if single sim, only SIM1 value is valid to use */
	SRV_MODE_SWITCH_SIM_ALL = SRV_MODE_SWITCH_SIM1
#if (MMI_MAX_SIM_NUM >= 2)
	                        | SRV_MODE_SWITCH_SIM2
#if (MMI_MAX_SIM_NUM >= 3)
	                        | SRV_MODE_SWITCH_SIM3
#if (MMI_MAX_SIM_NUM >= 4)
	                        | SRV_MODE_SWITCH_SIM4
#endif
#endif
#endif
                          ,

#if (MMI_MAX_SIM_NUM <= 2)
	SRV_MODE_NUM = 4
#else
	SRV_MODE_NUM
#endif
} srv_mode_switch_type_enum;

/* Will be phased out */
#define SRV_MODE_FLIGHT_MODE SRV_MODE_SWITCH_ALL_OFF
#define SRV_MODE_DUAL_SIM (SRV_MODE_SWITCH_SIM1 | SRV_MODE_SWITCH_SIM2) //SRV_MODE_SWITCH_SIM_ALL
#define SRV_MODE_SIM1_ONLY SRV_MODE_SWITCH_SIM1
#define SRV_MODE_SIM2_ONLY SRV_MODE_SWITCH_SIM2
#define SRV_MODE_NORMAL_MODE SRV_MODE_SWITCH_NORMAL_MODE
#define srv_mode_state_enum srv_mode_switch_type_enum
/* Will be phased out */

/*
 * Switch result enum
 */
typedef enum
{
    SRV_MODE_SWITCH_FAIL = 0,    /* switch failed */
    SRV_MODE_SWITCH_SUCCESS = 1  /* switch success */
} srv_mode_switch_result_enum;

/*
 * Mode status enum
 */
typedef enum
{
    SRV_MODE_SWITCH_OFF,    /* Mode is off */
    SRV_MODE_SWITCH_ON,     /* Mode is on */

    SRV_MODE_SWITCH_END
} srv_mode_switch_state_enum;

/*
 * Structure for mode switch notification
 */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_mode_switch_type_enum gsm_curr_mode;    /* Current mode of GSM */
    srv_mode_switch_type_enum gsm_select_mode;  /* Select mode of GSM */
    srv_mode_switch_state_enum curr_flight_mode; // Gemini+ & FTO
    srv_mode_switch_state_enum select_flight_mode;
} srv_mode_switch_notify_struct;

/*
 * structure for srv_mode_switch_switch_network_mode_ext
 */
typedef struct  
{
	U8 wlan; /* switch of WLAN */
	U8 bt;   /* switch of BT */
	U8 rf;    /* switch of RF */
    /* will be phased out */
	U8 gsm;    /* switch of RF */
	//U8 unused;
} srv_mode_switch_req_struct;

typedef enum
{
    SRV_MODE_SWITCH_DYNAMIC_MODE, // Gemini+: show SIM selection screen when power on the handset
    SRV_MODE_SWITCH_STATIC_MODE,  // Gemini+: power on the handset and activate protocols by inserted SIMs
    SRV_MODE_SWITCH_TOTAL_MODE
} srv_mode_switch_bootup_sel_type_enum;


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_rf_mode
 * DESCRIPTION
 *  Only to switch GSM mode but not affect the BT and WLAN status.
 *  It is for factory mode to use. 
 *  For others, please be careful to use this API. 
 * PARAMETERS
 *  sel_mode    :   [IN]    select mode
 *  cb_func_ptr :   [IN]    mode switch application callback function
 * RETURNS
 *  start mode switch or not
 *****************************************************************************/
extern MMI_BOOL srv_mode_switch_switch_rf_mode(srv_mode_switch_type_enum sel_mode, mmi_proc_func cb_func_ptr, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_network_mode
 * DESCRIPTION
 *  Switch network mode.
 *  This function will help to maintain the status of BT and WLAN.
 *  when switching to flight mode, this service  will help to turn off BT and WLAN. 
 *  when switching back from flight mode, it will turn on BT and WLAN. 
 * PARAMETERS
 *  mode        :   [IN]    Which mode will the phone switch to
 *  cb_func_ptr :   [IN]    Callback function
 * RETURNS
 *  U8
 *****************************************************************************/
#if (MMI_MAX_SIM_NUM == 1)
extern MMI_BOOL srv_mode_switch_switch_network_mode(srv_mode_switch_type_enum sel_mode, mmi_proc_func cb_func_ptr, void *user_data);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_network_mode_ext
 * DESCRIPTION
 *  Switch RF, WLAN and BT according to input structure.
 *  It is for preferred mode to use. 
 *  For others, please be careful to use this API. 
 * PARAMETERS
 *  switch_info    :   [IN]    structure about which service need to be turn on/off
 *  cb_func_ptr    :   [IN]    mode switch application callback function
 * RETURNS
 *  start mode switch or not
 *****************************************************************************/
extern MMI_BOOL srv_mode_switch_switch_network_mode_ext(srv_mode_switch_req_struct switch_info, mmi_proc_func cb_func_ptr, void* user_data);

#ifndef __BUILD_DOM__
/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_flight_mode
 * DESCRIPTION
 *  Switch to flight mode or back to normal mode 
 *  If check_sim is MMI_TRUE, the phone will only turn on RF of inserted SIM
 * PARAMETERS
 *  flight_mode_on      [IN]    is switch to flight mode
 *  check_sim           [IN]    is switch the RF according to SIM insert status
 *  callback            [IN]
 *  user_data
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_mode_switch_switch_flight_mode(MMI_BOOL flight_mode_on, MMI_BOOL check_sim, mmi_proc_func callback, void *user_data);
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_set_current_mode
 * DESCRIPTION
 *  only to save network mode value, but no do network mode switching.
 *  For example, use it when booting up.
 * PARAMETERS
 *  sel_mode	:   [IN]    saved mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mode_switch_set_current_mode(srv_mode_switch_type_enum sel_mode);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_get_network_mode
 * DESCRIPTION
 *  get current network mode by SIM.
 * PARAMETERS
 *  void
 * RETURNS
 *  current mode
 *****************************************************************************/
extern srv_mode_switch_state_enum srv_mode_switch_get_network_mode(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_get_current_mode
 * DESCRIPTION
 *  Function to get current mode, return the mask of current status
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_mode_switch_type_enum
 *****************************************************************************/
extern srv_mode_switch_type_enum srv_mode_switch_get_current_mode(void);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_get_prev_dual_sim_status
 * DESCRIPTION
 *  To get previous network mode by SIM.
 *  Ex. when switching prefer mode from WLAN only to others,it need restore 
 *  previous network mode of SIM.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern srv_mode_switch_state_enum srv_mode_switch_get_pre_network_mode(mmi_sim_enum sim);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_is_switching
 * DESCRIPTION
 *  get mode switch is running or not
 * PARAMETERS
 *  void
 * RETURNS
 *  0 : not switching  1 : switching
 *****************************************************************************/
extern MMI_BOOL srv_mode_switch_is_switching(void);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_is_network_service_available
 * DESCRIPTION
 *  check if having available network service including GSM and WLAN. 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_FALSE in flight mode
 *  MMI_TRUE  not in flight mode
 *****************************************************************************/
extern MMI_BOOL srv_mode_switch_is_network_service_available(void);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_enable_query_mode
 * DESCRIPTION
 *  Enable or disable query mode 
 * PARAMETERS
 *  is_enalbe   :   [IN]    Enable/disable query mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mode_switch_enable_query_mode(MMI_BOOL is_enable);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_is_query_mode_enabled
 * DESCRIPTION
 *  Check if the query mode is enabled 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_mode_switch_is_query_mode_enabled(void);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_update_cb_func
 * DESCRIPTION
 *  mode switch callback function for WLAN / BT switch process (should be phased
 * out after BT service API revised)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mode_switch_update_cb_func(void);

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_get_switch_type
 * DESCRIPTION
 *  get mode switch type 
 * PARAMETERS
 *  void     
 * RETURNS
 *  
 *****************************************************************************/
extern srv_mode_switch_bootup_sel_type_enum srv_mode_switch_get_switch_type(void);


#endif /* __MODE_SWTICH_SRV_GPROT_H__ */
