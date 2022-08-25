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
 * SnsAppGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file implements application functions for SNS feature.
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

#ifndef __SNS_APP_GPROT_H__
#define __SNS_APP_GPROT_H__

#include "mmi_features.h"
#ifdef __SOCIAL_NETWORK_SUPPORT__

#include "MMIDataType.h"

#include "SnsSrvDefs.h"
#include "SnsSrvTypes.h"


/**************************************************************
 * MARCO                                                      * 
 **************************************************************/


/**************************************************************
 * Structure Declaration                                      *
 **************************************************************/
typedef enum
{
    MMI_SNS_INT_TAB_CONTACT_FRIEND,
    MMI_SNS_INT_TAB_CONTACT_FAVORITE_FR,

    MMI_SNS_INT_TAB_CENTER_HAPPEN,
    MMI_SNS_INT_TAB_CENTER_MY_PROF,
    MMI_SNS_INT_TAB_CENTER_DM,
    MMI_SNS_INT_TAB_CENTER_NOTIF,

    MMI_SNS_INT_TAB_TOTAL
} mmi_sns_integration_tab_enum;


typedef enum
{
    MMI_SNS_FRIEND_LIST_NONE,
    MMI_SNS_FRIEND_LIST_PLAINT_MODE,
    MMI_SNS_FRIEND_LIST_CHECK_BOX_MODE,

    MMI_SNS_FRIEND_LIST_END
} mmi_sns_friend_list_enum;


typedef struct
{
    MMI_ID gid;
    U32 provider;
    FuncPtr lsk;
} mmi_sns_account_logout_struct;


typedef enum
{
    MMI_SNS_CONF_SYNC_INTERVAL,
    MMI_SNS_CONF_NEWS_REMINDER,

    MMI_SNS_CONF_TOTAL
} mmi_sns_misc_config_duration_enum;


/**************************************************************
* Global variable                                             *
***************************************************************/


/**************************************************************
* Global Function                                             *
***************************************************************/

/******************************************************************************
 * FUNCTION
 *    mmi_sns_get_item
 * DESCRIPTION
 *    get the point to the item specified by its index. The get item with this funtion, it maybe have a  "get more" item, and get more utility.
 * PARAMETERS
 *    list_id:   [IN]  from which list to get item from 
 *    index:     [IN]  the index of the item
 *    out:       [OUT] will point to the result item
 * RETURNS
 *    srv_sns_result
 ******************************************************************************/
#define mmi_sns_get_item(list_id, index, out)   srv_sns_get_item2(list_id, index, (void **)out)


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_launch
 * DESCRIPTION
 *  This function is used to launch SNS center.
 * PARAMETERS
 *  void
 * RETURNS
 *  viod
 *****************************************************************************/
extern void mmi_sns_launch(void);


#ifdef __MMI_APP_HOMESCREEN_SNS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sns_idle_integrate_launch
 * DESCRIPTION
 *  This function is used to launch SNS relate screen for idle.
 * PARAMETERS
 *  tab_id          [in]
 * RETURNS
 *  viod
 *****************************************************************************/
extern void mmi_sns_idle_integrate_launch(mmi_sns_integration_tab_enum tab_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_idle_get_icon_id
 * DESCRIPTION
 *  This function is used to get icon id for idle.
 * PARAMETERS
 *  tab_id          [in]
 * RETURNS
 *  viod
 *****************************************************************************/
extern U16 mmi_sns_idle_get_icon_id(mmi_sns_integration_tab_enum tab_id);
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_friend_profile_launch
 * DESCRIPTION
 *  This function is used to show friend profile.
 * PARAMETERS
 *  parent_id          [in]    parent group id
 *  user                 [in]    user
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sns_friend_profile_launch(MMI_ID parent_id, srv_sns_user_struct *user);


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_setting_launch
 * DESCRIPTION
 *  This function is used to launch SNS setting.
 * PARAMETERS
 *  viod
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sns_setting_launch(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_new_activity_launch
 * DESCRIPTION
 *  This function is used to share picture. This function will cache the path, no need the caller to cache it.
 * PARAMETERS
 *  parent_id          [in]    parent group id
 *  path                [in]    image path
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sns_new_activity_launch(MMI_ID parent_gid, WCHAR *path);

#define mmi_sns_upload_photo_from_imageviewer(gid, path) \
            mmi_sns_new_activity_launch(gid, path)


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_new_direct_msg_launch
 * DESCRIPTION
 *  This function is used to send direct message.
 * PARAMETERS
 *  parent_id          [in]    parent group id
 *  friend               [in]    friend
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sns_new_direct_msg_launch(MMI_ID parent_gid, srv_sns_friend_struct *friends);


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_activity_details_launch
 * DESCRIPTION
 *  This function is used to show activity details.
 * PARAMETERS
 *  parent_id          [in]    parent group id
 *  list_id               [in]    activities list id
 *  index                [in]    the activity's number is in the activities list.
 * RETURNS
 *  void
 *****************************************************************************/
 extern void mmi_sns_activity_details_launch(MMI_ID parent_id, S32 list_id, S16 index);


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_util_logout_event_registry
 * DESCRIPTION
 *  This function is used to register or de-register EVT_ID_SRV_SNS_ACCOUNT_LOGGED_OUT.
 *   If this event have been listen by other apps, it will de-register previous listener, then register this event for new one.
 *   That means this event just have only one listener of apps.
 * PARAMETERS
 *  is_reg              [in]    true is register, false is de-register
 *  callback           [in]    callback func
 *  user_data         [in]    user data.
 * RETURNS
 *  mmi_ret    same as mmi_frm_cb_dereg_event and mmi_frm_cb_reg_event
 *****************************************************************************/
extern mmi_ret mmi_sns_util_logout_event_registry(MMI_BOOL is_reg, mmi_proc_func callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_misc_account_logout_scrn
 * DESCRIPTION
 *  This function is used to show which account was logouted. Caller need to set group id and provider id, lsk.
 * PARAMETERS
 *  account_logout              [in]    mmi_sns_account_logout_struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sns_misc_account_logout_scrn(mmi_sns_account_logout_struct *account_logout);


/*****************************************************************************
 * FUNCTION
 *  mmi_sns_misc_config_duration
 * DESCRIPTION
 *  This function is used to set news reminder or sync interval.
 * PARAMETERS
 *  parent_gid              [in]    group id
 *  type                      [in]    mmi_sns_misc_config_duration_enum
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_sns_misc_config_duration(MMI_ID parent_gid, mmi_sns_misc_config_duration_enum type);


#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#endif /* __SNS_APP_GPROT_H__ */
