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
 * DataAccountGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#ifndef _DATA_ACCOUNT_GPROT_H
#define _DATA_ACCOUNT_GPROT_H

/*---------------------------------------------------------------------------*/
/* Header files */
/*---------------------------------------------------------------------------*/


#include "DataAccountDef.h"
#include "DtcntSrvGprot.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "cbm_consts.h"
#include "mmi_msg_struct.h"
#include "custom_data_account.h"
#include "mmi_frm_utility_gprot.h"
#include "DataAccountEnum.h"

/*---------------------------------------------------------------------------*/
/* Definition */
/*---------------------------------------------------------------------------*/
// sim provisioning profiles + common profiles
#define MMI_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM + MAX_CSD_SIM_PROV_NUM_PER_SIM + MAX_GPRS_SIM_PROV_NUM_PER_SIM)
#define MMI_DTCNT_PROF_MAX_ACCOUNT_NUM (MMI_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM * MMI_SIM_TOTAL)

/*use for data account select screen*/
#define MAX_MULITI_BEARER_NUM	    2

/* for all the deletion notification account ID */
#define DTCNT_ALL_NOTIFICATION (0xffffffff)  

/* MAX account name length */
#ifdef MAX_DATA_ACCOUNT_NAME_LEN
#undef MAX_DATA_ACCOUNT_NAME_LEN
#endif
#define MAX_DATA_ACCOUNT_NAME_LEN   SRV_DTCNT_PROF_MAX_ACC_NAME_LEN

/* account name suffix length (SIM1)/(SIM2) just for __MMI_DUAL_SIM__ */
#define DATA_ACCOUNT_NAME_SUFFIX_LEN            7

/* account name length used from 10A */
#define MAX_DATA_ACCOUNT_NAME_WITH_SUFFIX_LEN (MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN)

/* For always ask */
#define DATA_ACCOUNT_ALWAYS_ASK     0xFF

/* For SIM1 */
#define DATA_ACCOUNT_SIM1                0xFE

/* For SIM2 */
#define DATA_ACCOUNT_SIM2                0xFD

/* For invalid ID */
#define DATA_ACCOUNT_INVALID_ID       0xF0

/* For CSD type profile */
#define DATA_ACCOUNT_BEARER_CSD  0x01

/* For GPRS type profile */
#define DATA_ACCOUNT_BEARER_GPRS 0x02

/* For WiFi type profile */
#define DATA_ACCOUNT_BEARER_WIFI 0x04

/* For all type profile */
#define DATA_ACCOUNT_BEARER_ALL        DATA_ACCOUNT_BEARER_CSD | DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI

/* Packet Switching Bearer only #define DATA_ACCOUNT_BEARER_PS_ONLY    DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI */ 
#define DATA_ACCOUNT_BEARER_PS_ONLY    DATA_ACCOUNT_BEARER_GPRS

/* Circuit Switching Bearer only */
#define DATA_ACCOUNT_BEARER_CS_ONLY    DATA_ACCOUNT_BEARER_CSD

/*  For all type number */
#define DATA_ACCOUNT_BEARER_TOTAL   3

/*  For always ask bit */
#define DATA_ACCOUNT_BEARER_ALWAYS_ASK 0x10

/* For GPRS CSD bit */
#define DATA_ACCOUNT_BEARER_GPRS_CSD 0x08

/* For dual account */
#define DATA_ACCOUNT_LIST_MAX_BEARER 2

/* Invalid data account ID for dual account (cbm_encode_data_account_id(CBM_INVALID_NWK_ACCT_ID, CBM_SIM_ID_SIM1, 0, 0)) */
#define MMI_DTCNT_INVALID_ID (0x00003e3e)   

/* Default data account ID for dual account */
#define MMI_DTCNT_DEFAULT_ID (0x00003e00)

/*---------------------------------------------------------------------------*/
/* Enum */
/*---------------------------------------------------------------------------*/

/* Select account API for APP & CBM option enum */
typedef enum
{

    DTCNT_SELECT_SIM = 0x01, /* single sim: single, no select sim screen,  dual sim: select sim1 / sim2 screen */
    						 /* not turned on:   select SIM1 only  */
    DTCNT_SELECT_ALWAYS_ASK = 0x02, /* always ask turned on when compile option enabled, not turned on if undef */

    DTCNT_SELECT_DEFAULT = 0x03,  /* single sim:  single, no select sim screen,  dual sim: select sim1/sim2 screen */
    							  /* always ask : allowed if compile option turned on */
	DTCNT_SELECT_BEARER_SWITCH = 0x04, /* dual account support */
    
    DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH = 0x08, /* take effect on DTCNT_SELECT_BEARER_SWITCH set */
  
    DTCNT_SELECT_END   /* total enum */
} dtcnt_select_type_enum;


typedef enum
{
    MMI_DTCNT_GET_ACCT_NAME_TYPE_SINGLE,
    MMI_DTCNT_GET_ACCT_NAME_TYPE_DUAL1,
    MMI_DTCNT_GET_ACCT_NAME_TYPE_DUAL2,
    MMI_DTCNT_GET_ACCT_NAME_TYPE_TOTAL    
}mmi_dtcnt_get_acct_name_type_enum;

typedef enum
{
    MMI_DTCNT_ACCT_VALID_FIRST,   /* only for dual account, and first account is valid, second is invalid */
    MMI_DTCNT_ACCT_VALID_SECOND,  /* only for dual account, and first account is invalid, second is valid */
    MMI_DTCNT_ACCT_VALID_FULL,    /* for single account it stands for valid, for dual account it stands for both accounts are valid */
    MMI_DTCNT_ACCT_VALID_NONE,    /* for single account it stands for invalid, for dual account it stands for both accounts are invalid */
    MMI_DTCNT_ACCT_VALID_TOTAL
}mmi_dtcnt_acct_valid_type_enum;

typedef enum
{
    /* send connect request to dtcnt srv if any available network found */
    WLAN_AUTO_CONN_ACTION_START,
    /* not to connect to any network after call api */
    /* Ex. no networks existed around */
    /* Ex. no networks belongs to OP and no saved networks existed around */
    WLAN_AUTO_CONN_ACTION_CANCEL,
    WLAN_AUTO_CONN_ACTION_TOTAL
} mmi_wlan_auto_conn_action_enum;

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  mmi_wlan_auto_conn_cb_func_ptr
 * DESCRIPTION
 *  Callback function after invoke .
 * PARAMETERS
 *  bearer_type :   [IN]    Bearer initial type
 *  acct_id: [IN]  account id
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*mmi_wlan_auto_conn_cb_func_ptr) (mmi_wlan_auto_conn_action_enum action);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_app_init
 * DESCRIPTION
 *  Initialize the Data Account App
 *  
 *  This is used to initialized the Data Account application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dtcnt_app_init(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_apn
 * DESCRIPTION
 *  To get GPRS profile APN
 * PARAMETERS
 *  account_id   :   [IN]   account ID.
 *  dest         :   [OUT]  destination buffer.       
 *  len          :   [IN]   length.     
 * RETURNS
 *  TRUE    : Get APN successfully
 *  FALSE   : Get APN failed
 *****************************************************************************/
extern BOOL mmi_dtcnt_get_apn(U32 account_id, CHAR *dest, U8 len);



/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_full_account_name
 * DESCRIPTION
 *  To get full account name
 * PARAMETERS
 *  acct_id   :   [IN]   account ID.
 *  dest         :   [OUT]  destination buffer.       
 *  len          :   [IN]   length.
 *  type       :    [IN] account type
 * RETURNS
 *  TRUE    : Get APN successfully
 *  FALSE   : Get APN failed
 *****************************************************************************/
extern MMI_BOOL mmi_dtcnt_get_full_account_name(U32 acct_id, CHAR *dest, U8 len, mmi_dtcnt_get_acct_name_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_subscribe_account
 * DESCRIPTION
 *  Because need all applications handle update/delete event, this function phase out.
 *
 * PARAMETERS
 *  acct_old     [IN]    encoded old account id.
 *  acct_new     [IN]    encoded new account id.
 *  app_str_id   [IN]    string id of application.
 *  app_icon_id  [IN]    icon id of application.
 * RETURNS
 *  Return MMI_TRUE on success, otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_dtcnt_subscribe_account(U32 acct_old, U32 acct_new, U16 app_str_id, U16 app_icon_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_reset_acct_subscription
 * DESCRIPTION
 *  Because need all applications handle update/delete event, this function phase out.
 *
 * PARAMETERS
 *  acct_id      [IN]    encoded account id.
 *  app_str_id   [IN]    string id of application.
 *  app_icon_id  [IN]    icon id of application.
 * RETURNS
 *  Return MMI_TRUE on success, otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_dtcnt_reset_acct_subscription(U32 acct_id, U16 app_str_id, U16 app_icon_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_acct_is_valid
 * DESCRIPTION
 *  To check if the encoded account ID is valid
 * PARAMETERS
 *  encoded_acct_id    [IN]   APP must pass the  
 * RETURNS
 *  mmi_dtcnt_acct_valid_type_enum  
 *****************************************************************************/
mmi_dtcnt_acct_valid_type_enum mmi_dtcnt_acct_is_valid(U32 encoded_acct_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_valid_acc_by_type
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  type : [IN]
 *  app_id: [IN]
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 mmi_dtcnt_get_valid_acc_by_type(srv_dtcnt_bearer_enum type, U8 app_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_first_account_id
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  bearers   :  [IN]   bearer.
 * RETURNS
 *  U32   :   account ID
 *****************************************************************************/
extern U32 mmi_dtcnt_get_first_account_id(U8 bearers);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_ready_check
 * DESCRIPTION
 *  Chec if data account is ready in global array,
 *  execute call back function when ready.(with key clear, add for dummy screen)
 * PARAMETERS
 *  ready_callback   :   [IN]   ready callback function.
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_dtcnt_ready_check(FuncPtr ready_callback, MMI_BOOL with_scr_lock);


/*****************************************************************************
 * FUNCTION
 *  EntryDTCNTMain
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dtcnt_entry_main(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_pre_entry_main
 * DESCRIPTION
 *  pre entry Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dtcnt_pre_entry_main(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_invalid_name_str_id
 * DESCRIPTION
 *  To get invalid account name
 * PARAMETERS
 *  void       
 * RETURNS
 *  U16   : String ID
 *****************************************************************************/
extern U16 mmi_dtcnt_get_invalid_name_str_id(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_default_name_str_id
 * DESCRIPTION
 *  To get default account  name, APP use this API to get default non-selected account name, it will be "Auto"
 * PARAMETERS
 *  void       
 * RETURNS
 *  U16   : String ID
 *****************************************************************************/
extern U16 mmi_dtcnt_get_default_name_str_id(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_apn_list_ids
 * DESCRIPTION
 *  To get account id array for unique apn
 * PARAMETERS
 *  ids     [OUT] account id array buffer point;
 *  num_ids [OUT] number of account ids;
 * RETURNS
 *  MMI_TRUE if get success, or MMI_FALSE
 *****************************************************************************/
 extern MMI_BOOL mmi_dtcnt_get_apn_list_ids(U32 *ids, U32 *num_ids, srv_dtcnt_sim_type_enum sim_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_set_GPRS_APN_for_project_mode
 * DESCRIPTION
 *  Set GPRS profile APN for APP
 * PARAMETERS
 *  APN        :   [IN]  APN.
 *  account_id :   [IN]  account ID.
 * RETURNS
 *  MMI_TURE if update success, or MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL mmi_dtcnt_set_GPRS_APN_for_project_mode(CHAR *APN, U32 account_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_csd_number
 * DESCRIPTION
 *  To get CSD dial number
 * PARAMETERS
 *  account_id   :   [IN]   account ID.
 *  dest         :   [OUT]  destination buffer.       
 *  len          :   [IN]   length.     
 * RETURNS
 *  TRUE    :  Get CSD number successfully
 *  FALSE   :  Get CSD number failed
 *****************************************************************************/
extern BOOL mmi_dtcnt_get_csd_number(U32 account_id, CHAR *dest, U8 len);


#ifdef __MMI_OP01_DCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_dcd_acct_id
 * DESCRIPTION
 *  Get DCD account ID
 * PARAMETERS
 *  void
 * RETURNS
 *  U32   : DCD account ID
 *****************************************************************************/
extern U32 mmi_dtcnt_get_dcd_acct_id(void);
#endif /* __MMI_OP01_DCD__ */


#ifdef __MMI_WLAN_FEATURES__

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_add_event_notify_hdlr
 * DESCRIPTION
 *  add event notify callback handler.
 * PARAMETERS
 *  event_callback     :   [IN]      event callback.
 * RETURNS
 *  BOOL
 *****************************************************************************/
extern BOOL mmi_wlan_add_event_notify_hdlr(FuncPtrShort event_callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_remove_event_notify_hdlr
 * DESCRIPTION
 *  remove event notify callback handler.
 * PARAMETERS
 *  event_callback     :   [IN]      event callback.
 * RETURNS
 *  MMI_TRUE    :  Remove notification successfully
 *  MMI_FALSE   :  Remove notification failed
 *****************************************************************************/
extern BOOL mmi_wlan_remove_event_notify_hdlr(FuncPtrShort event_callback);



/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_reset_hw_on
 * DESCRIPTION
 *  To reset hardware on
 * PARAMETERS
 *  callback   :   [IN] callback function.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_wlan_reset_hw_on(FuncPtr callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_reset_hw_off
 * DESCRIPTION
 *  To reset hardware off
 * PARAMETERS
 *  callback   :   [IN] callback function.
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_wlan_reset_hw_off(FuncPtr callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_entry_ipaddr_conflict_ind
 * DESCRIPTION
 *  Entry new message indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_dtcnt_entry_ipaddr_conflict_ind(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_app_launch_func
 * DESCRIPTION
 *  Launch WLAN application in App Mgr
 * PARAMETERS
 *  param
 *  param_size
 * RETURNS
 *  MMI_ID
 *****************************************************************************/
extern MMI_ID mmi_wlan_app_launch_func(void* param, U32 param_size);

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wlan_wizard_new
 * DESCRIPTION
 *  Entry function for WLAN application in pluto MMI
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_wlan_entry_wlan_wizard_new(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_auto_conn_networks
 * DESCRIPTION
 *  Provide interface for CBM to trigger connection to default trust AP(customization) or
 *  trust APs in wlan service database
 *  Logic flow:
 *  1. scan for networks
 *  2. If scan result equals 0, post event ...
 *  3. Otherwise, 
 *      a. If found OP network and it's never been connect successfully before,
 *         connect to it automatically.
 *      b. Connect to saved AP according to priority.
 * PARAMETERS
 *  cb  :   [IN]    callback function for auto connect
 * RETURNS
 *  U32 :   scan job ID
 *****************************************************************************/
extern U32 mmi_wlan_auto_conn_networks(mmi_wlan_auto_conn_cb_func_ptr cb);

#ifdef __MMI_OP01_WIFI__
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_cmcc_entry_power_saving_mode
 * DESCRIPTION
 *  This function for entry  to 'Power Save Mode' setting in EM
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_wlan_cmcc_entry_power_saving_mode(void);

#endif /* __MMI_OP01_WIFI__ */

#endif /* __MMI_WLAN_FEATURES__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_account_view
 * DESCRIPTION
 *  Display the detail info of any GPRS/CSD account by U32 account id.
 * PARAMETERS
 *  acct_id   :  [IN]    data account id
 * RETURNS
 *  void
 *****************************************************************************/
//extern void mmi_dtcnt_account_view(U32 acct_id);

#endif /* _DATA_ACCOUNT_GPROT_H */ 

