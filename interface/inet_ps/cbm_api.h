/*****************************************************************************
*
* Filename:
* ---------
* cbm_api.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file contains the CBM APIs
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _CBM_API_H
#define _CBM_API_H

#include "soc_consts.h"
#include "custom_data_account.h"
#include "cbm_consts.h"
#include "app2cbm_struct.h"

#include "kal_general_types.h"
#include "stack_config.h"
#include "nvram_editor_data_item.h"

/*************************************************************************
* Structures
*************************************************************************/
/* account profile */
typedef struct
{
    kal_bool                is_always_ask; /* is always_ask account or not */
    cbm_sim_id_enum         sim_id; /* sim card id. it could be SIM one or SIM two */
    kal_uint8               account_id; /* real account id */
} cbm_acct_profile_struct;

/* account info */
typedef struct
{
    cbm_acct_profile_struct account[CBM_MAX_ACCT_NUM]; /* account profile */
    kal_uint8               acct_num; /* number of real accounts in 32-bits account id */
    kal_uint8               app_id; /* application identification */
} cbm_account_info_struct;

/* this structure define application information which would be 
 * used in data account. Application which would use 
 *  data account profile must use this API to register application id 
 */
typedef struct {
    kal_uint16 app_str_id; /* applicaiton string id used to identify itself */
    kal_uint16 app_icon_id; /* application icon id used to identify itself */
    kal_uint64 app_type; /* application type which will be used 
                            in data account profile, such as MMS, etc.*/
} cbm_app_info_struct;

/* this structure define bearer status query info which would be 
 * used to query current bearer status under variety query conditions.
 */
typedef struct {
    kal_bool by_account_id; /* by account id to query, need to fill in paramter "account_id" */
    kal_bool by_app; /* byy application to query, need to fill in app_id */
    kal_bool by_bearer; /* by bearer type to query, need to fill in parameter "bearer", sim is optional. */
    kal_bool by_sim_id; /* by sim id to query, need to fill in parameter "sim". When you query by sim, you need to either specify by_bearer or by_app. */
    kal_uint32 account_id; /* account id */
    kal_uint8 app_id; /* application id */
    kal_uint32 bearer; /* bearer type */
    cbm_sim_id_enum sim; /* sim id */
} cbm_bearer_status_query_struct;

/*************************************************************************
* External APIs
*************************************************************************/

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_register_app_id_with_app_info
 * DESCRIPTION
 *  get a registered application id. 
 *  APP could call this API to register itself and get an app_id.   
 *  This returned app id is a dynamical ID. App had better not save the app id to nvram or file, 
 *  because the app id will be changed when power on again or call register function again.
 *  The lifetime of app id: before app call deregister function or before power off.
 *
 *  Application must register app id by  the api "cbm_register_app_id_with_app_info". 
 *  In addition, application can only register once with the same string id plus icon id. 
 *  If it calls this API twice with the same string id and icon id, an error (0) would be returned. 
 *  The time to register the app id is suggested on power-on phase.  
 *  All application who use network service must register application id.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 *
 * PARAMETERS
 *  info    : [IN]    application mmi information
 *  app_id  : [OUT]    application identification
 * RETURN VALUES
 *  CBM_OK : register app id successfully
 *  CBM_ERROR : wrong input or output parameters
 *  CBM_LIMIT_RESOURCE : no available application slot
 * SEE ALSO
 *  cbm_deregister_app_id
 * EXAMPLE
 * <code>
 * cbm_app_info_struct info;
 * kal_int8 ret;
 *
 * info.app_str_id = xxx;
 * info.app_icon_id = xxx;
 * info.app_type = xxx;
 * ret = cbm_register_app_id_with_app_info(&info, &app_id);
 * if (ret == CBM_OK)
 * {
 *     //the valid app_id is obtained
 * }
 * </code>
 *****************************************************************************/
extern kal_int8 cbm_register_app_id_with_app_info(cbm_app_info_struct *info,
                                                            kal_uint8 *app_id);


/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_register_app_id_with_app_info
 * DESCRIPTION
 *  get a registered application id. 
 *  APP could call this API to register itself and get an app_id.   
 *  This returned app id is a dynamical ID. App had better not save the app id to nvram or file, 
 *  because the app id will be changed when power on again or call register function again.
 *  The lifetime of app id: before app call deregister function or before power off.
 *
 *  This API is mainly provided for application which doesn't have MMI and profile menu.
 *  However, it still needs an application id. It can call this API to get one.
 *  All application who use network service must register application id.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id  : [OUT]    application identification
 * RETURN VALUES
 *  CBM_OK : register app id successfully
 *  CBM_ERROR : wrong input or output parameters
 *  CBM_LIMIT_RESOURCE : no available application slot
 * SEE ALSO
 *  cbm_deregister_app_id
 * EXAMPLE
 * <code>
 * kal_uint8 app_id;
 * kal_int8 ret;
 *
 * ret = cbm_register_app_id(&app_id);
 * if (ret == CBM_OK)
 * {
 *     //the valid app_id is obtained
 * }
 * </code>
 *****************************************************************************/
extern kal_int8 cbm_register_app_id(kal_uint8 *app_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_deregister_app_id
 * DESCRIPTION
 *  deregister the application id
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id  : [IN]    The id of application, it could be obtained by cbm register function.
 * RETURN VALUES
 *  KAL_TRUE :  success
 *  KAL_FALSE : cannot find the app id in CBM table or the app id is an illegal one.
 *              Invalid app id: app id > CBM_MAX_APP_ID_NO 
 *              or app id == CBM_INVALID_APP_ID
 * SEE ALSO
 *  cbm_register_app_id
 * EXAMPLE
 * <code>
 * kal_bool ret = cbm_deregister_app_id(app_id);
 * if (ret == KAL_TRUE)
 * {
 *     //the application id is deregistered successfully
 * }
 * </code>
 *****************************************************************************/
extern kal_bool cbm_deregister_app_id(kal_uint8 app_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_encode_data_account_id
 * DESCRIPTION
 *  encode the info into the 32-bits account id (for single account use only).
 *  APP must call this function to set app_id,, sim card info and always-ask feature 
 *  after application gets the account id. The app_id is returned by cbm_register_app_id function. 
 *  This API is for single account only. If multiple account id contained in the 32-bits account id, 
 *  please use the cbm_encode_data_account_id_ext.
 *  Application can use this API to encode the info into the data account id. 
 *  This API is only for one account only. In other words, 
 *  applications which need multiple accounts should not use this API. 
 *
 *  P.S. We assume applications shall set its module id or register the application id 
 *  before calling this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_id     : [IN]    This is application account id.
 *  sim_id      : [IN]    This is Sim card info; sim 1 or sim 2 (cbm_sim_id_enum)
 *  app_id      : [IN]    This is app id, it could be get by cbm register api.
 *  always_ask  : [IN]    This is application Always ask flag.
 * RETURNS
 *  Encoded data account id
 *  1.  The data account id may contain the sim info, app_id or always-ask feature if application fill in these parameters in this API.
 *  2.  If the parameter that sim info or app id is invalid, this api will return CBM_INVALID_ACCT_ID.
 * SEE ALSO
 *  cbm_encode_data_account_id_ext
 * EXAMPLE
 * Generate a SIM2 account id example:
 * <code>
 * kal_uint8 app_id;
 * cbm_sim_id_enum sim_id;
 * app_id = cbm_register_app_id(APP_STR_ID, APP_ICON_ID);
 * sim_id = CBM_SIM_ID_SIM2;
 * account_id = cbm_encode_data_account_id(ori_acct_id, sim_id, app_id, 0);
 * </code>
 *****************************************************************************/
extern kal_uint32 cbm_encode_data_account_id(kal_uint32 acct_id, cbm_sim_id_enum sim_id, 
                                      kal_uint8 app_id, kal_bool always_ask);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_set_app_id
 * DESCRIPTION
 *  encode the app id into the account id. App could call this API to merely 
 *  replace app id in data account id and all other original info 
 *  in the account id will still be kept.
 *
 *  P.S. We assume applications shall set its module id or register the application id 
 *  before calling this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_id : [IN]    This is application account id
 *  app_id  : [IN]    This is app id, it could be obtained by the cbm register api.
 * RETURNS
 *  Encoded data account id
 *  1.  The account id with the APP ID being replaced is returned.
 *  2.  If the app id is invalid, this API will return CBM_INVALID_ACCT_ID.
 *  3.  Invalid app id is: app id > CBM_MAX_APP_ID_NO
 *      or app id == CBM_INVALID_APP_ID
 * SEE ALSO
 *   cbm_get_app_id
 * EXAMPLE
 * Only want to replace the application id:
 * <code>
 * kal_uint8 app_id;
 * app_id = cbm_register_app_id(APP_STR_ID, APP_ICON_ID);
 * account_id = cbm_set_app_id (nw_acc_id,  ap_id);
 * </code>
 *****************************************************************************/
extern kal_uint32 cbm_set_app_id(kal_uint32 acct_id, kal_uint8 app_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_decode_data_account_id
 * DESCRIPTION
 *  decode the info from the 32-bits account id. APP must call this function to get 
 *  the info from the 32-bits data account id. User can encode the sim id, 
 *  application id, always-ask attribute and original account id into the 32 bits account id. 
 *  This API is for single account only. If multiple account id contained 
 *  in the 32-bits account id, please use the cbm_decode_data_account_id_ext.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_id     : [IN]    Input account id
 *  sim_id      : [OUT]   This is Sim card info; sim 1 or sim 2 (cbm_sim_id_enum)
 *  app_id      : [OUT]   This is app id, it could be get by cbm register api
 *  always_ask  : [OUT]   This is application Always ask flag. 
 *                      User can know whether this account is always-ask account 
 *                      or not by this attribute.
 *  ori_acct_id : [OUT]   This is the original account id.
 * RETURN VALUES
 *  KAL_FALSE : error occurs
 *  KAL_TRUE : decode successfully
 * SEE ALSO
 *  cbm_decode_data_account_id_ext
 * EXAMPLE
 * <code>
 * kal_uint32 ori_acct_id;
 * kal_bool always-ask;
 * kal_uint8 app_id;
 * cbm_sim_id_enum sim_id;
 * if (cbm_decode_data_account_id(account_id, &sim_id, &app_id, &always-ask, &ori_acct_id) == KAL_TRUE)
 * {
 *    //decode the account successfully
 * }
 * </code>
 *****************************************************************************/
extern kal_bool cbm_decode_data_account_id(kal_uint32 acct_id, 
                                           cbm_sim_id_enum *sim_id, 
                                           kal_uint8 *app_id, 
                                           kal_bool *always_ask, 
                                           kal_uint32* ori_acct_id);

/*****************************************************************************
 * <GROUP  AlwaysAsk>
 *
 * FUNCTION
 *  cbm_is_always_ask_account
 * DESCRIPTION
 *  check if this is an always-ask account. APP could call this API to check 
 *  if this account id contains the always-ask feature or not. 
 *  If the account id contains the always-ask feature, 
 *  an account query screen maybe displayed to ask user.
 *  
 *  The definition of always-ask: the account id not decided 
 *  when the profile is activated. The real account is decided when user really
 *  connect to the network. When user connect to the network, there is an always-ask
 *  screen displayed to query which account s/he would want to use to connect to the
 *  network.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_id     : [IN]    This is application account id
 * RETURN VALUES
 *  KAL_TRUE : always ask
 *  KAL_FALSE : not always ask
 * EXAMPLE
 *  <code>
 *  if (cbm_is_always_ask_account(account_id))
 *  {
 *    //is always-ask account
 *  }
 *  else
 *  {
 *    //not the always-ask account
 *  }
 *  </code>
 *****************************************************************************/
extern kal_bool cbm_is_always_ask_account(kal_uint32 acct_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_get_sim_id
 * DESCRIPTION
 *  get sim id from the account id. APP could call this api to get sim card 
 *  info from acct id. This API is for single account id only. That is to say, 
 *  if multiple account ids are contained in the 32-bits account id, 
 *  please use the extension API "cbm_decode_data_account_id_ext".
 *
 *  In the dual-sim project, we can choose to use the SIM one or SIM two account id
 *  to connect to the network. Thus, we can use this API to know whether we use the
 *  SIM one or SIM two.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_id     : [IN]    This is application account id
 * RETURNS
 *  The account id is a sim one or sim two account id (cbm_sim_id_enum)
 * EXAMPLE
 *  <code>
 *  cbm_sim_id_enum sim_id;
 *  sim_id  = cbm_get_sim_id(account_id);
 *  </code>
 *****************************************************************************/
extern cbm_sim_id_enum cbm_get_sim_id(kal_uint32 acct_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_get_app_id
 * DESCRIPTION
 *  get the app id from the account id
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_id : [IN]    This is applications account id  
 * RETURNS
 *  Return the app id which is originally encoded in the account id
 *  If the app id is invalid, the ap id "CBM_INVALID_APP_ID" 
 *  would be returned
 * SEE ALSO
 *   cbm_set_app_id
 * EXAMPLE
 *  <code>
 *   kal_uint8 ap_id;
 *   ap_id  = cbm_get_app_id(account_id);
 *  </code>
 *****************************************************************************/
extern kal_uint8 cbm_get_app_id(kal_uint32 acct_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_get_original_account
 * DESCRIPTION
 *  get the original account id from the 32-bits account id. 
 *  APP could call this API to get the real account id which is 
 *  encoded within the 32bits account id. This API is only for single account only. 
 *  That is to say, if there are multiple account ids contained 
 *  within the 32-bits account id, please use extension API "cbm_decode_data_account_id_ext".
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_id     : [IN]    account id
 * RETURNS
 *  Return the original data account id
 * EXAMPLE
 *  <code>
 *   kal_uint8 account_id;
 *   account_id  = cbm_get_original_account(nwk_acct_id);
 *  </code>
 *****************************************************************************/
extern kal_uint8 cbm_get_original_account(kal_uint32 acct_id);

/*****************************************************************************
 * FUNCTION
 * <GROUP  Bearer>
 *
 *  cbm_reset_account_info
 * DESCRIPTION
 *  Application could call this API to reset the account info structure before use it
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_info   : [IN]    The account info which needs to encoded within the 32-bits account id
 * RETURN VALUES
 *  CBM_OK : OK
 *  CBM_ERROR : ERROR. If the acct_info is null, we will return CBM_ERROR.
 * EXAMPLE
 *  Application can use this API to reset the account info structure before 
 *  it uses it to encode wanted info into the account id. Application 
 *  has to call this API before it calls the "cbm_encode_data_account_id_ext".
 *  <code>
 *   kal_uint32 ori_account_id = xxxxx;
 *   kal_uint32 encoded_acct_id;
 *   cbm_account_info_struct acct_info;
 *   if (cbm_reset_account_info(&acct_info) == CBM_OK)
 *   {
 *       acct_info.account[0].account_id = xxx; 
 *       acct_info.account[0].sim_id = CBM_SIM_ID_SIM2;
 *       acct_info.account[1].account_id = xxx; 
 *       acct_info.account[1].sim_id = CBM_SIM_ID_SIM1;
 *       acct_info.acct_num = 2;
 *       acct_info.app_id = 2;
 *       if (cbm_encode_data_account_id_ext(ori_account_id, &encoded_acct_id, &acct_info) == CBM_OK)
 *       {
 *           //SUCCESS
 *       }
 *       else
 *       {
 *           //ERROR
 *       }
 *   }
 *  </code>
 *****************************************************************************/
extern kal_int8  cbm_reset_account_info(cbm_account_info_struct *acct_info);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_encode_data_account_id_ext
 * DESCRIPTION
 *  Application could call this API to encode multiple info into the account id. 
 *  Now what we can encode here is:
 *  Always-ask feature, multiple account IDs, the SIM information of every account id. 
 *  If application wants to encode multiple real account IDs, please use this API.  
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  ori_acct_id     : [IN]    This is the original 32-bits data account id
 *  encoded_acct_id : [OUT]   This is the encoded account id
 *  acct_info       : [IN]    The info which needs to encoded within the 32-bits account id.
 * RETURN VALUES
 *  CBM_OK : encode successfully.
 *  CBM_ERROR : invalid parameters.
 *  CBM_INVALID_ACCT_ID : invalid account id.
 *  CBM_INVALID_AP_ID : invalid application id.
 * SEE ALSO
 *   cbm_encode_data_account_id
 * EXAMPLE
 *  Please take the reference of "cbm_reset_account_info" for more detailed usage example
 *****************************************************************************/
extern kal_int8  cbm_encode_data_account_id_ext(kal_uint32 ori_acct_id, 
                                        kal_uint32 *encoded_acct_id, 
                                        cbm_account_info_struct *acct_info);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_decode_data_account_id_ext
 * DESCRIPTION
 *  Application could call this API to decode multiple info from the 32-bits account id. 
 *  If application wants to decode multiple real account id, please use this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  acct_id     : [IN]    32-bits account id
 *  acct_info   : [IN]    The info which is decoded from the 32-bits data account id
 * RETURN VALUES
 *  CBM_OK : decode successfully.
 *  CBM_ERROR : invalid parameters.
 * SEE ALSO
 *   cbm_decode_data_account_id
 * EXAMPLE
 *  <code>
 *  cbm_account_info_struct acct_info;
 *  if (cbm_decode_data_account_id_ext(account_id, &acct_info) == CBM_OK)
 *  {    
 *     //SUCCESS
 *  }
 *  else
 *  {
 *     //ERROR
 *  }
 *  </code>
 *****************************************************************************/
extern kal_int8  cbm_decode_data_account_id_ext(kal_uint32 acct_id, 
                                        cbm_account_info_struct *acct_info);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_hold_bearer
 * DESCRIPTION
 *  Application can use this API to hold the bearer 
 *  if it doesn't want the bearer to be automatically deactivated.
 *
 *  P.S. We assume applications shall set its module id or register the application id 
 *  before calling this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id      : [IN]    application id
 * RETURN VALUES
 *  CBM_OK : open the bearer successfully.
 *  CBM_INVALID_AP_ID : invalid application id.
 *  CBM_LIMIT_RESOURCE : limited resource.
 * SEE ALSO
 *   cbm_release_bearer
 * EXAMPLE
 *  <code>
 *  kal_uint8 ap_id;
 *  ap_id = cbm_get_app_id ((kal_uint32)account_id);
 *  ...
 *  if (cbm_hold_bearer (ap_id) == CBM_OK)
 *  {
 *      //hold the bearer successfully
 *  }
 *  </code>
 *****************************************************************************/
extern kal_int8  cbm_hold_bearer(kal_uint8 app_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_release_bearer
 * DESCRIPTION
 *  This API is used to release all bearers which are opened by this application. 
 *  The bearer will be released only when all sockets are closed. 
 *  If the sockets are all closed and this API is called, the bearer will be 
 *  deactivated. Otherwise, the bearer will be deactivated only when 
 *  all sockets which belong to this application are closed.
 *  If the bearer is opened by application directly through the API 
 *  "cbm_open_bearer", the bearer can be directly deactivated when 
 *  application calls the API cbm_release_bearer.  
 *
 *  P.S. We assume applications shall set its module id or register the application id 
 *  before calling this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id      : [IN]    application id
 * RETURN VALUES
 *  CBM_OK : bearer is in deactivated state.
 *  CBM_INVALID_AP_ID : invalid application id.
 *  CBM_WOULDBLOCK : the bearer is in deactivating state and the bearer info 
 *                   will be reported later.
 * SEE ALSO
 *   cbm_hold_bearer
 * EXAMPLE
 *  <code>
 *  kal_uint8 ap_id;
 *  kal_int8 ret;
 *  ap_id = cbm_get_app_id ((kal_uint32)account_id); 
 *  ...
 *  if ((ret = cbm_release_bearer (ap_id)) == CBM_OK)
 *  {
 *    //bearer is deactivated
 *  }
 *  else
 *  {
 *      if (ret == CBM_WOULDBLOCK)
 *      {
 *          //bearer is not completely deactivated yet
 *      }
 *  }
 *  </code>
 *  After the bearer is deactivated:
 *  <code>
 *  app_cbm_bearer_info_ind_hdlr(local_para_struct *msg)
 *  {
 *      app_cbm_bearer_info_ind_struct *ind_ptr;
 *      ind_ptr = (app_cbm_bearer_info_ind_struct *)local_para_ptr;
 *      switch (ind_ptr->state)
 *      {
 *          case CBM_DEACTIVATED:
 *               app_bearer_deactivated_hdlr();
 *               break;
 *          ...
 *      }
 *  }
 *  </code>
 *****************************************************************************/
extern kal_int8  cbm_release_bearer(kal_uint8 app_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_open_bearer
 * DESCRIPTION
 *  Open the bearer.
 *
 *  P.S. We assume applications shall set its module id or register the application id 
 *  before calling this API.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  account_id      : [IN]   account id which contains the application id. 
 *                                  App id must to be encoded in the account id
 * RETURN VALUES
 *  CBM_OK : bearer is in activated state.
 *  CBM_INVALID_AP_ID : invalid application id.
 *  CBM_INVALID_ACCT_ID : invalid network account id.
 *  CBM_WOULDBLOCK : the bearer is in deactivating state and the bearer info 
 *                   will be reported later.
 *****************************************************************************/
extern kal_int8  cbm_open_bearer(kal_uint32 account_id);


extern kal_int32 cbm_get_bearer_status_ext(cbm_bearer_status_query_struct *info);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_get_bearer_status
 * DESCRIPTION
 *  This API is for application to get the current bearer status in ABM. 
 *  Note: the value you get through this API is temporary result , 
 *  the bearer status will change in any time.  When you use this API, 
 *  you have to pay attention to this and know that the state is a 
 *  temporary value and you may keep on calling this API to update the 
 *  update-to-date value.  
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  account_id      : [IN]    account id (It must contain application id)
 * RETURN VALUES
 *  CBM_ERROR : error occurs. The option parameter is incorrect.
 *  CBM_DEACTIVATED : AP bearer is in deactivated state. (cbm_bearer_state_enum)
 *  CBM_ACTIVATING : AP bearer is in activating state. (cbm_bearer_state_enum)
 *  CBM_ACTIVATED : AP bearer is in activated state. (cbm_bearer_state_enum)
 *  CBM_DEACTIVATING : AP bearer is in deactivating state. (cbm_bearer_state_enum)
 * EXAMPLE
 *  <code>
 *  kal_uint32 account_id;
 *  kal_int32 status;
 *  ...
 *  account_id = cbm_set_app_id(account_id, app_id);
 *  status = cbm_get_bearer_status(account_id);
 *  if (status >= 0)
 *  {
 *    if (status == CBM_ACTIVATED)
 *    {
 *        //bearer is in activated state
 *    }
 *  }
 *  </code>
 *****************************************************************************/
extern kal_int32 cbm_get_bearer_status(kal_uint32 account_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_get_bearer_type
 * DESCRIPTION
 *  This API is for the application to get the current used bearer type. 
 *  For example, if the real activated type is EDGE, you will get CBM_EDGE through this API.
 *
 *  In the bearer fallback, before the fallback transition, it will get the first 
 *  bearer type. After the complementation of fallback, it will get 
 *  the second bearer type.
 *  However, during the fallback transition it may get fist one at first and 
 *  second one later. Please do not call this API during the fallback transition.  
 *  
 *  If application doesn't activate the bearer and call this API to query bearer type,
 *  it will get the first account id's bearer type.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  account_id      : [IN]    Network account id (it contain the application id)
 *  bearer_type     : [OUT]   Bearer type. Please take the reference of 
 *                          cbm_bearer_enum
 * RETURN VALUES
 *  CBM_OK : OK
 *  CBM_ERROR : error occurs. The option parameter is incorrect.
 * EXAMPLE
 *  <code>
 *  Kal_uint8 bearer_type;
 *  if (cbm_get_bearer_type(account_id, &bearer_type))
 *  {
 *      //bearer type is obtained in the parameter "bearer_type"
 *  }
 *  </code>
 *****************************************************************************/
extern kal_int8  cbm_get_bearer_type(kal_uint32 account_id,
                                            cbm_bearer_enum *bearer_type);

extern kal_int8 cbm_get_real_account(kal_uint32 account_id, kal_uint32 *rel_acct_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_register_bearer_info_by_app_id
 * DESCRIPTION
 *  Register the application bearer info. Application can specify which module id
 *  it wants to receive the bearer info indication. In addition, it can specify 
 *  which bearer type and status it wants to receive.
 *  Only one different module can be registered by each app id.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id      : [IN]    application identification
 *  recv_mod_id : [IN] receiver module id. If the module which needs to receive bearer 
 *                     info is not the one specified in soc_create, you can specify
 *                     the receiver module id here.
 *  type        : [IN]    bearer type (cbm_bearer_enum)
 *  state       : [IN]    bearer status (cbm_bearer_state_enum) 
 * RETURN VALUES
 *  CBM_OK : register the bearer info successfully.
 *  CBM_ERROR : error occurs
 *  CBM_LIMIT_RESOURCE : limited resources.
 *  CBM_INVALID_AP_ID  : invalid application id
 * SEE ALSO
 *   cbm_deregister_app_bearer_info
 * EXAMPLE
 *  if an application with two modules (MOD_RTSP and MOD_MED), 
 *  after it specify the module id to MOD_MED in this case. 
 *  The bearer info indication will be sent to the activated module id (MOD_RTSP) 
 *  and specified module id (MOD_MED)
 *
 *  <code>
 *  kal_uint8 ap_id;
 *  ...
 *  cbm_register_bearer_info_by_app_id(ap_id, MOD_MED, CBM_PS|CBM_CSD, 
 *  CBM_ACTIVATED|CBM_DEACTIVATED );
 *  </code>
 *
 *  After register the bearer info by this way, the bearer info indication 
 *  will be sent to MOD_MED and MOD_RTSP concurrently when the bearer gprs, 
 *  edge or csd is in activated or deactivated state.
 *****************************************************************************/
extern kal_int8 cbm_register_bearer_info_by_app_id(kal_uint8 app_id, module_type recv_mod_id, 
                                                   kal_uint32 type, kal_uint32 state);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_get_registered_bearer_info_by_app_id
 * DESCRIPTION
 *  get registered application bearer info. 
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id     : [IN]    application identification
 *  type       : [OUT]    registered bearer type
 *  state      : [OUT]    registered bearer state
 * RETURN VALUES
 *  CBM_OK : get registered bearer info successfully.
 *  CBM_ERROR : error occurs
 * EXAMPLE
 *  <code>
 *  kal_uint8 ap_id;
 *  ...
 *  app.app_id = cbm_get_app_id((kal_uint32)account_id);
 *  cbm_get_registered_bearer_info_by_app_id(ap_id , &type, &state);
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_get_registered_bearer_info_by_app_id(kal_uint8 app_id, 
                                                         kal_uint32 *type, 
                                                         kal_uint32 *state);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_deregister_bearer_info_by_app_id
 * DESCRIPTION
 *  deregister the application bearer info. 
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app     : [IN]    application identification
 * RETURN VALUES
 *  CBM_OK : deregister the bearer info successfully.
 *  CBM_ERROR : error occurs
 * SEE ALSO
 *   cbm_register_bearer_info_by_app_id
 * EXAMPLE
 *  <code>
 *  kal_uint8 ap_id;
 *  ...
 *  ap_id = cbm_get_app_id((kal_uint32)account_id);
 *  cbm_deregister_bearer_info_by_app_id(ap_id);
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_deregister_bearer_info_by_app_id(kal_uint8 app_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_register_bearer_info_by_mod_id
 * DESCRIPTION
 *  if service provider such as which provide a network service for
 *  many applications, it may want to ban the bearer info by mod id.
 *  This API is mainly provided for this kind of application.
 *  Register the bearer info for a specific module id. 
 *  Application can specify which module id
 *  it wants to receive the bearer info indication.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  mod_id      : [IN] application's module id
 *  type        : [IN]    bearer type (cbm_bearer_enum)
 *  state       : [IN]    bearer status (cbm_bearer_state_enum) 
 * RETURN VALUES
 *  CBM_OK : register the bearer info successfully.
 *  CBM_ERROR : error occurs
 * SEE ALSO
 *   cbm_deregister_bearer_info_by_mod_id
 * EXAMPLE
 *  <code>
 *  ...
 *  cbm_register_bearer_info_by_mod_id(MOD_WPS, CBM_PS|CBM_CSD, 
 *  CBM_ACTIVATED|CBM_DEACTIVATED );
 *  </code>
 *
 *  After register the bearer info by this way, the bearer info indication 
 *  which sent to MOD_WPS will only be sent to it when its bearer type and 
 *  bearer status matched the one user speicfy.
 *****************************************************************************/
extern kal_int8 cbm_register_bearer_info_by_mod_id(module_type mod_id, 
                                                             kal_uint32 type, kal_uint32 state);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *   cbm_get_registered_bearer_info_by_mod_id
 * DESCRIPTION
 *  get registered application bearer info by module id. 
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  mod_id     : [IN]     module id
 *  type       : [OUT]    registered bearer type
 *  state      : [OUT]    registered bearer state
 * RETURN VALUES
 *  CBM_OK : get registered bearer info successfully.
 *  CBM_ERROR : error occurs
 * EXAMPLE
 *  <code>
 *  cbm_get_registered_bearer_info_by_mod_id(MOD_WPS , &type, &state);
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_get_registered_bearer_info_by_mod_id(module_type mod_id, 
                                                                     kal_uint32 *type, 
                                                                     kal_uint32 *state);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_deregister_bearer_info_by_app_id
 * DESCRIPTION
 *  deregister the bearer info by module id
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  mod_id     : [IN]    module id
 * RETURN VALUES
 *  CBM_OK : deregister the bearer info successfully.
 *  CBM_ERROR : error occurs
 * SEE ALSO
 *   cbm_register_bearer_info_by_mod_id
 * EXAMPLE
 *  <code>
 *   cbm_deregister_bearer_info_by_mod_id(MOD_WPS);
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_deregister_bearer_info_by_mod_id(module_type mod_id);

/*****************************************************************************
 * <GROUP  Fallback>
 *
 * FUNCTION
 *  cbm_abort_app_bearer_event
 * DESCRIPTION
 *  In ¡§fallback level one with new connection¡¨ or ¡§fallback level two¡¨, 
 *  once you have decided to display CUI but cannot do it due so some other reasons, 
 *  application can call this API to abort app bearer query
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id  : [IN]  application identification
 *  
 * RETURN VALUES
 *  CBM_OK : success
 *  CBM_INVALID_APP_ID : invalid application id
 *  CBM_ERROR : error occurs
 * EXAMPLE
 *  //when abornal siutation occurs and cannot do always ask or fallback anymore, 
 *  // we can abort bearer event by calling this API
 *  <code>
 *  cbm_abort_app_bearer_event(app_id);
 *
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_abort_app_bearer_event(kal_uint8 app_id);


/*****************************************************************************
 * <GROUP  Fallback>
 *
 * FUNCTION
 *  cbm_set_app_bearer_event
 * DESCRIPTION
 *  Set which bearer event it wants
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id      : [IN]  application identification
 *  evt         : [IN]  bearer events which want to be known (cbm_app_bearer_event_enum)
 *  recv_mod_id : [IN] event receiver. If your event receiver is not the module
 *                which you specify in soc_create you can specify it here.
 * RETURN VALUES
 *  CBM_OK : success
 *  CBM_INVALID_APP_ID : invalid application id
 *  CBM_ERROR : error occurs
 * EXAMPLE
 *  //let MOD_APP to receive always ask and fallback level one bearer event
 *  <code>
 * cbm_set_app_bearer_event(app_id, MOD_APP,
 *                             CBM_APP_BEARER_EVT_ALWAYS_ASK|CBM_APP_BEARER_EVT_FB_L1);
 *
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_set_app_bearer_event(kal_uint8 app_id, 
                                         module_type recv_mod_id,
                                         kal_uint32 evt);

/*****************************************************************************
 * <GROUP  Fallback>
 *
 * FUNCTION
 *  cbm_send_app_bearer_event_resp
 * DESCRIPTION
 *  send bearer event response when event notification is received.
 *  false response is to reject the bearer event.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  resp  : [IN]  response
 * RETURN VALUES
 *  CBM_OK : success
 *  CBM_INVALID_APP_ID : invalid application id
 *  CBM_ERROR : error occurs
 *****************************************************************************/
extern kal_int8 cbm_send_app_bearer_event_resp(app_cbm_bearer_event_notify_rsp_struct *resp);


/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_register_app_static_qos_id
 * DESCRIPTION
 *  Application can call this API to register 
 *  what static qos profile id it wants to use.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id              : [IN]    application identification
 *  qos_id              : [IN]    static qos profile id.
 *                                CUSTOM_QOS_DEFAULT_PROFILE_ID (0) is default qos id.
 *                                CUSTOM_QOS_STREAMING_PROFILE_ID(1) is streaming profile id.                               
 *  
 * RETURN VALUES
 *  CBM_OK : OK
 *  CBM_ERROR : error occurs
 * SEE ALSO
 *   cbm_deregister_app_static_qos_id
 * EXAMPLE
 *  <code>
 *  app_id = cbm_register_app_id(STR_ID, ICON_ID);
 *  ...
 *  cbm_register_app_static_qos_id(app_id, CUSTOM_QOS_STREAMING_PROFILE_ID);
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_register_app_static_qos_id(kal_uint8 app_id, custom_qos_profile_id_enum qos_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_deregister_app_static_qos_id
 * DESCRIPTION
 *  Application can call this API to deregister the registered static qos id.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id              : [IN]    application identification
 *  
 * RETURN VALUES
 *  CBM_OK : OK
 *  CBM_ERROR : error occurs
 * SEE ALSO
 *   cbm_register_app_static_qos_id
 * EXAMPLE
 *  <code>
 *  app_id = cbm_register_app_id(STR_ID, ICON_ID);
 *  ...
 *  cbm_register_app_static_qos_id(app_id, CUSTOM_QOS_STREAMING_PROFILE_ID);
 *  ...
 *  cbm_deregister_app_static_qos_id(app_id);
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_deregister_app_static_qos_id(kal_uint8 app_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_register_app_dynamic_qos_id
 * DESCRIPTION
 *  Application can call this API to register its dynamic qos id
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id              : [IN]    application identification
 *  qos_id              : [OUT]   dynamic qos id. It cannot be NULL.
 *
 * RETURN VALUES
 *  CBM_OK : success
 *  CBM_ERROR  : error occurs
 * SEE ALSO
 *   cbm_deregister_app_dynamic_qos_id
 * EXAMPLE
 *  <code>
 *  kal_uint8 app_id = 0, qos_id = 0;
 *  kal_int8 ret;
 *  app_id = cbm_register_app_id(STR_ID, ICON_ID);
 *  ...
 *  ret = cbm_register_app_dynamic_qos_id(app_id, &qod_id);
 *  if (ret < 0)
 *  {
 *      return error;
 *  }
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_register_app_dynamic_qos_id(kal_uint8 app_id, kal_uint8 *qos_id); 

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_deregister_app_dynamic_qos_id
 * DESCRIPTION
 *  Application can call this API to deregister the registered dynamic qos id.
 *  Once the regisered dynamic qos id is deregistered, the dynamic qos profile
 *  will be cleared.
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  app_id              : [IN]    application identification
 *  
 * RETURN VALUES
 *  CBM_OK : OK
 *  CBM_ERROR : error occurs
 * SEE ALSO
 *   cbm_register_app_dynamic_qos_id
 * EXAMPLE
 *  <code>
 *  kal_uint8 app_id, qos_id;
 *  kal_int8 ret;
 *  app_id = cbm_register_app_id(STR_ID, ICON_ID);
 *  ...
 *  ret = cbm_register_app_dynamic_qos_id(app_id, &qos_id);
 *  if (ret < 0)
 *  {
 *      return error;
 *  }
 *  ...
 *  cbm_deregister_app_dynamic_qos_id(app_id);
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_deregister_app_dynamic_qos_id(kal_uint8 app_id);


/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_set_qos_profile
 * DESCRIPTION
 *  Application can call this API to set the qos profile content
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  qos_profile_id      : [IN]    qos profile id
 *  content             : [IN]    qos profile content. It cannot be NULL.
 *  is_blocking         : [IN]    API is in blocking mode or not
 *  
 * RETURN VALUES
 *  CBM_OK : OK
 *  CBM_ERROR : error occurs
 * SEE ALSO
 *   cbm_set_qos_profile
 * EXAMPLE
 *  1. Set static qos profile content
 *  <code>
 *  app_id = cbm_register_app_id(STR_ID, ICON_ID);
 *  ...
 *  cbm_register_app_static_qos_id(app_id, CUSTOM_QOS_STREAMING_PROFILE_ID);
 *  ...
 *  cbm_set_qos_profile(CUSTOM_QOS_STREAMING_PROFILE_ID, &qos_content);
 *  </code>
 *  
 *  2. Set dynamic qos profile content
 *  <code>
 *  kal_uint8 app_id, qos_id;
 *  kal_int8 ret;
 *  app_id = cbm_register_app_id(STR_ID, ICON_ID);
 *  ...
 *  ret = cbm_register_app_dynamic_qos_id(app_id, &qos_id);
 *  ...
 *  cbm_set_qos_profile(qos_id, &qos_content);
 *  </code>
 *****************************************************************************/
extern kal_int8 cbm_set_qos_profile(kal_uint8 qos_profile_id, module_type report_mod_id,
                                    nvram_ef_abm_ps_qos_profile_struct *content);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_is_account_valid
 * DESCRIPTION
 *  application can check whether account id is valid or not
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  account_id  : [IN]    network account id 
 *                        it contains application id and two 
 *                        network account id in bearer fallback case.
 * RETURN VALUES
 *  KAL_TRUE : valid account id
 *  KAL_FALSE : invalid account id
 **************************************************************************/
extern kal_bool cbm_is_account_valid(kal_uint32 account_id);

/*****************************************************************************
 * <GROUP  Bearer>
 *
 * FUNCTION
 *  cbm_get_valid_account_id
 * DESCRIPTION
 *  get one valid account id by bearer type
 *
 *  Please remember to wrap API by __TCPIP__ if you may call this API when network is disable
 * PARAMETERS
 *  bearer_type  : [IN]   bearer type
 *  account_id   : [OUT]  account id
 * RETURN VALUES
 *  CBM_OK : success
 *  CBM_ERROR : no valid account id for the bearer type you pass in
 **************************************************************************/
extern kal_int8 cbm_get_valid_account_id(cbm_bearer_enum bearer_type, kal_uint32 *account_id);
#endif /* _CBM_API_H */


