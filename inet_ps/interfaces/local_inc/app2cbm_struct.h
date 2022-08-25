/*****************************************************************************
*
* Filename:
* ---------
* app2cbm_struct.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file describes the common struct of Applications
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef _APP2CBM_STRUCT_H
#define _APP2CBM_STRUCT_H

#include "cbm_consts.h"
#include "custom_data_account.h"

#include "kal_general_types.h"
#include "tcm_api.h"
#include "ps_public_enum.h"

/* bearer info indication. This primitive is for CBM to report the bearer status 
 * to the application (include MMI).
 * it will be reported to the module which activates the bearer. 
 */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    
    kal_uint32              account_id; /* network account id contains multiple info */
    kal_uint32              obtain_account_id; /* The account we really use to activate bearer */
    kal_int32               error_cause; /* bearer error cause, refer ps_cause_enum */

    cbm_bearer_state_enum   state; /* bearer state. If the bearer state is "CBM_BEARER_NEED_FALLBACK", 
                                      it indicates that the situation of bearer fallback occurs. 
                                      Application needs to stop the timer if it has started one.  
                                      If application doesn't stop the timer based on this state, it has to 
                                      start the timer after the bearer is in activated state. 
                                      If application doesn't start the timer when it receive the 
                                      APP_CBM_BEARER_INFO_IND(ACTIVATING), it has to start the timer 
                                      when the bearer is activated. That is to say, it can start the timer 
                                      when it receives the APP_CBM_BEARER_INFO_IND(ACTIVATED).*/
    cbm_bearer_enum         bearer; /* bearer type */
    
    
    
    cbm_result_error_enum   error;       /* error reason.
                                            1.CBM_BEARER_FAILED indicates that the data link layer is disconnected, 
                                            we are out of coverage. 
                                            2.CBM_DHCP_ERROR indicates that the data link 
                                            layer is connected but get IP failed, VoIP should retry login after 
                                            timeout
                                            3.CBM_CANCEL_ACT_BEARER  indicates that the activation operation is 
                                            canceled by user. Thus, when AP receives this error message, it 
                                            has not to display any error message. This error cause is defined 
                                            for the function of "always-ask".  */
     nvram_editor_qos_struct  nwk_neg_qos;
                                            
    kal_uint8               qos_profile_id; /* qos profile id */
    kal_uint8               ip_addr[4];    /* IP address. valid only when state is CBM_ACTIVATED */
} app_cbm_bearer_info_ind_struct;

/* application nvram operation indication. This primitive is for the application to 
 * check the NVRAM operation result. If application change the NVRAM profile content
 * through the CBM API, it can get the result through the primitive.
 */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint8               profile_id; /* profile id */
    kal_bool                result; /* KAL_TRUE: success, KAL_FALSE: fail */
} app_cbm_nvram_operation_ind_struct;

/* bearer event notification. This primitive is to send the bearer event notification to app. 
 * Once the notification event is received, application has to return the response by primitive
 * APP_CBM_BEARER_EVENT_NOTIFY_RSP. If application doesn't want to accept always ask or bearer 
 * fallback event, it can put the "FALSE" result in APP_CBM_BEARER_EVENT_NOTIFY_RSP to reject it.
 */
typedef struct
{
    kal_uint8                 ref_count;
    kal_uint16                msg_len;
    kal_uint32                account_id; /* network account id contains multiple info. 
                                             For example, app_id is encoded in the account id */
    cbm_app_bearer_event_enum event;      /* notification event. This describe which event has occured.
                                             For example: if the primitive is sent out due to the occurance
                                             of bearer fallback level two event, 
                                             the value put here would be CBM_APP_BEARER_EVT_FB_L2_WITH_NEW_CONN */
} app_cbm_bearer_event_notify_ind_struct;

/* Application has to return response once it receive the APP_CBM_BEARER_EVENT_NOTIFY_IND message.
 */
typedef struct
{
    kal_uint8                 ref_count;
    kal_uint16                msg_len;
    kal_uint32                account_id; /* network account id contains multiple info. 
                                             For example, app_id is encoded in the account id */
    kal_bool                  result;     /* TRUE: accept bearer event. FALSE: reject bearer event */
    cbm_app_bearer_event_enum event;      /* notification event. This describe which event has occured.
                                             For example: if the primitive is sent out due to the occurance
                                             of bearer fallback level two event, 
                                             the value put here would be CBM_APP_BEARER_EVT_FB_L2_WITH_NEW_CONN */
    
} app_cbm_bearer_event_notify_rsp_struct;

#endif /* _APP2CBM_STRUCT_H */
