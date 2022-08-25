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
 *  CallLogGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 ****************************************************************************/

#ifndef MMI_CALL_LOG_GPROT_H
#define MMI_CALL_LOG_GPROT_H

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMIDataType.h"
#include "kal_general_types.h"

#include "CallLogSrvGprot.h"

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_init
 * DESCRIPTION
 *  To initialize the call log app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_RET mmi_clog_init(mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_main_menu
 * DESCRIPTION
 *  To enter call log main menu if the first screen is mainmenu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_launch(void);

#if defined(__MMI_BT_PBAP_CLIENT__)

extern void mmi_clog_pbapc_launch(MMI_ID parent_gid);
extern void mmi_clog_phapc_delaunch(void);

#endif /*__MMI_BT_PBAP_CLIENT__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_by_send_key
 * DESCRIPTION
 *  To enter call log list menu by pressing send key, application should register
 *  this function as the unified send key handler to unify the style.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_sendkey_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_dclt_launch
 * DESCRIPTION
 *  To enter call log list menu by pressing send key, application should register
 *  this function as the unified send key handler to unify the style.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_dclt_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_mclt_launch
 * DESCRIPTION
 *  To enter call log list menu by pressing send key, application should register
 *  this function as the unified send key handler to unify the style.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_mclt_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_rclt_launch
 * DESCRIPTION
 *  To enter call log list menu by pressing send key, application should register
 *  this function as the unified send key handler to unify the style.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_rclt_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_aclt_launch
 * DESCRIPTION
 *  To enter call log list menu by pressing send key, application should register
 *  this function as the unified send key handler to unify the style.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_aclt_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr_check
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_clog_nmgr_check(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr_enter
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_nmgr_enter(void);

#if !defined(__MMI_PLUTO_3232_IDLE_NMGR_SLIM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr_query
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_nmgr_query(void);
#endif /*!defined(__MMI_PLUTO_3232_IDLE_NMGR_SLIM__)*/
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_clear_all_new_events
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_clear_all_new_events(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_srv_evt_hdlr
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_RET mmi_clog_srv_evt_hdlr(mmi_event_struct *evt);

/*----------------------------------------------------------------------------*/
/* Property API: For PHB Dialer-Search                                        */
/*----------------------------------------------------------------------------*/
#define MMI_CLOG_ACT_FLAG_PURE_VIEW                     (0x0001)        /* If LSK of viewer is "Option" */
#define MMI_CLOG_ACT_FLAG_CALL_BY_SEND_KEY              (0x0002)        /* If make call by send key */
#define MMI_CLOG_ACT_FLAG_CALL_BY_IP_KEY                (0x0004)        /* If make call by IP key */
#define MMI_CLOG_ACT_FLAG_CALL_VOICE_ONLY               (0x0008)        /* If only voice call */
#define MMI_CLOG_ACT_FLAG_CALL_VIDEO_ONLY               (0x0010)        /* If only video call */

typedef enum
{
    MMI_CLOG_ACT_VIEW,
    MMI_CLOG_ACT_MAKE_CALL,
    MMI_CLOG_ACT_SEND_MSG,
    MMI_CLOG_ACT_SEND_SMS,
    MMI_CLOG_ACT_SEND_MMS,
    MMI_CLOG_ACT_SAVE_TO_PHB,
} mmi_clog_act_enum;

typedef struct
{
    SRV_CLOG_HANDLE handle;
    SRV_CLOG_ID log_id;
    mmi_clog_act_enum act_type;
    U32 flags;
} mmi_clog_act_prop_struct;

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_init_prop
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_RET mmi_clog_act_init_prop(mmi_clog_act_prop_struct *prop);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_act_apply
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_ID mmi_clog_act_apply(MMI_ID parent_gid, mmi_clog_act_prop_struct *prop);

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_log_icon
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_IMG_ID mmi_clog_get_log_icon(const srv_clog_log_identity_struct *idt);


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_sms_update_counter
 * DESCRIPTION
 *  Event handler for SMS counter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_RET mmi_clog_sms_update_counter(mmi_event_struct *event_data);

/*----------------------------------------------------------------------------*/
/* Property API: For OP11 & Venus                                             */
/*----------------------------------------------------------------------------*/

/*---------------------- Common for OP11 HS V2.5 and Venus HS ----------------*/

#if defined(__MMI_VUI_HOMESCREEN__)
/* Recent event */
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_log_icon
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_hs_re_query_data(S32 num); /* IdleHomescreenGprot.c  IdleRecentEvent.c */

#endif /* defined(__MMI_VUI_HOMESCREEN__) */ 


/*---------------------- OP11 HS V31 and V32 --------------------------------*/

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*  Sidebar */

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_log_icon
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_op11_hs32_sb_check_num(S32 sidebar_id, S32 indctr_id);

/* Shortcut */

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_log_icon
 * DESCRIPTION
 *  Use for NMGR only, to check if has any unread missed call log
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clog_op11_hs32_shct_query_data(S32 sidebar_id, S32 shct_id, void *shct_data);

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __MMI_BT_PBAP_CLIENT__
extern  MMI_BOOL g_folder_exist;
MMI_RET mmi_clog_update_list_by_status(mmi_event_struct*evt);
MMI_RET mmi_clog_bt_dialer_evt_hdlr(mmi_event_struct *evt);
extern void mmi_clog_prepare_data(MMI_MENU_ID sel_menu_id, MMI_ID gid);
extern void mmi_clog_set_bt_status();
#endif

/*----------------------------------------------------------------------------*/
/* Property API: End                                                          */
/*----------------------------------------------------------------------------*/

#endif /* MMI_CALL_LOG_GPROT_H */ 

