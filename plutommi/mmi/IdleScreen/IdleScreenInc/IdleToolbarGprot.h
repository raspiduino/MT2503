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
 *  IdleToolbarGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file provides the exported interface for the applications involved in
 *  the OP12 Toolbar.
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

#ifndef _MMI_IDLE_TOOLBAR_GPROT_H
#define _MMI_IDLE_TOOLBAR_GPROT_H

#include "MMI_features.h"

#ifdef __MMI_OP12_TOOLBAR__

#include "MMIDataType.h"
#include "custom_mmi_default_value.h"


/**********************************************************************
 * Default constants and values
 **********************************************************************/

/* Max number of new messages of a certain kind. */
#define MMI_TB_MAX_NEW_MESSAGE_NUM          4

/* Max number of missed calls. */
#define MMI_TB_MAX_NEW_MISSED_CALL_NUM      19


/**********************************************************************
 * Type definitions
 **********************************************************************/

/* Function prototype for the query function to get the information of the 
   event. */
typedef void (*mmi_tb_query_func_t)(S32 num);

/* Function prototype for the handler to process the event on the toolbar when
   the user presses a key. */
typedef void (*mmi_tb_evnt_cbf_t)(U16 key_code, U16 key_type, void *user_data);

/* Function prototype for the handler to process the events which is in the
   folding state. */
typedef void (*mmi_tb_multi_evnt_cbf_t)(U16 key_code, U16 key_type);


/**********************************************************************
 * Enum definitions
 **********************************************************************/

/* This enum defines the result of the query. */
typedef enum
{
    MMI_TB_RESULT_OK,           /* OK */
    MMI_TB_RESULT_NOT_READY,    /* APP is not ready and will update later */
    MMI_TB_RESULT_UPDATE        /* APP actively updates its content */
} mmi_tb_result_enum;

/* This enum defines the event type. */
typedef enum
{
    MMI_TB_EVNT_MSG_BEGIN,
    MMI_TB_EVNT_NEW_SMS     = MMI_TB_EVNT_MSG_BEGIN,    /* SMS */
    MMI_TB_EVNT_NEW_MMS,                                /* MMS */
    MMI_TB_EVNT_NEW_VOICE_MAIL,                         /* Voice mail */
    MMI_TB_EVNT_NEW_EMAIL,                              /* Email */
    MMI_TB_EVNT_NEW_IM,                                 /* Instatn messaging */
    MMI_TB_EVNT_NEW_WAP_PUSH,                           /* WAP push */
    MMI_TB_EVNT_NEW_CELL_BROADCAST,                     /* Cell broadcast */
    MMI_TB_EVNT_MSG_END,
    MMI_TB_EVNT_MISSED_CALL = MMI_TB_EVNT_MSG_END,      /* Missed call */
    MMI_TB_EVNT_NUM
} mmi_tb_evnt_enum;


/**********************************************************************
 * Structure definitions
 **********************************************************************/

/* This structure defines the event shown on the toolbar. */
typedef struct
{    
    S8         *subject;            /* Subject */
    U16         icon;               /* Icon ID */
    MMI_BOOL    is_time_present;    /* Is the time present for the event */
    MYTIME      time;               /* Time of the event */
    void       *user_data;          /* User data associated with this event */
} mmi_tb_evnt_struct;


/**********************************************************************
 * Public APIs
 **********************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_tb_evnt_answer
 * DESCRIPTION
 *  This function is called by APP to provide the answer about new events.
 * PARAMETERS
 *  type            [IN]            Event type
 *  result          [IN]            Result of answer
 *  total_num       [IN]            Total number of new events
 *  num_of_data     [IN]            The sizeof evnt array
 *  evnt            [IN]            Array of events required by the toolbar
 *  single_hdlr     [IN]            Handler to process a single event
 *  multi_hdlr      [IN]            Handler to process multiple event
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tb_evnt_answer(
                mmi_tb_evnt_enum type,
                mmi_tb_result_enum result,
                S32 total_num,
                S32 num_of_evnt,
                mmi_tb_evnt_struct *evnt,
                mmi_tb_evnt_cbf_t single_hdlr,
                mmi_tb_multi_evnt_cbf_t multi_hdlr);


/*****************************************************************************
 * FUNCTION
 *  mmi_tb_entry_toolbar_setting
 * DESCRIPTION
 *  This function shows the toolbar setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tb_entry_toolbar_setting(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tb_proc_message_um
 * DESCRIPTION
 *  This function processes a folded menu item for SMS/MMS shown in the message 
 *  moudle.
 * PARAMETERS
 *  key_code        [IN]            Key code
 *  key_type        [IN]            Key type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tb_proc_message_um(U16 key_code, U16 key_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_tb_is_set_on
 * DESCRIPTION
 *  This function checks whether the user switches on the toolbar. Note that 
 *  even though the user switches on the toolbar, it does not mean the toolbar 
 *  is enable because the SIM card might not be inserted or it is in flight
 *  mode. To know whether the toolbar is used or not actually, mmi_tb_is_enable
 *  should be used.
 * PARAMETERS
 *  void
 * RETURNS
 *  If toolbar is set on, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_tb_is_open(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tb_is_set_on
 * DESCRIPTION
 *  This function checks whether the user switches on the toolbar. Note that 
 *  even though the user switches on the toolbar, it does not mean the toolbar 
 *  is enable because the SIM card might not be inserted or it is in flight
 *  mode. To know whether the toolbar is used or not actually, mmi_tb_is_enable
 *  should be used.
 * PARAMETERS
 *  void
 * RETURNS
 *  If toolbar is set on, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_tb_is_set_on(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tb_is_enable
 * DESCRIPTION
 *  This function checks whether the toolbar is enable.
 * PARAMETERS
 *  void
 * RETURNS
 *  On enable, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_tb_is_enable(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tb_initialization
 * DESCRIPTION
 *  This function initializes the OP12 toolbar context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tb_initialization(void);

#endif /* __MMI_OP12_TOOLBAR__ */
#endif /* _MMI_IDLE_TOOLBAR_GPROT_H */

