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
 *  SmsAppMainUI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application main UI screen and menu, 
 *  inlcude the SMS folder List, Editor, Viewer and their options
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

/**************************************************************
 * Header Files Include
 **************************************************************/
#include "MMIDataType.h"
#include "string.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "kal_public_api.h"
#include "browser_api.h"
#include "customer_email_num.h"
#include "custom_phb_config.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "wgui_categories_CM.h"
#include "wgui_touch_screen.h"
#include "gui_ems.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "MessagesMiscell.h"
#include "mmi_rp_app_sms_def.h"
#include "SmsSrvGprot.h"
#include "SmsGuiInterfaceType.h"
#include "custom_mmi_default_value.h"
#include "MMI_trc_Int.h"
#if (MMI_MAX_SIM_NUM >= 2)
#if (defined (__MMI_TOUCH_SCREEN__))
#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
#include "MMI_common_app_trc.h"
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */
#endif /*defined (__MMI_TOUCH_SCREEN__) */ 
#endif /* (MMI_MAX_SIM_NUM >= 2) */

//#include "MMI_include.h"
#include "CommonScreens.h"

#include "SmsAppType.h"
#include "SmsAppProt.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif 
#include "App_usedetails.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif /* __MMI_UCM__ */

#include "UcmSrvGprot.h"

#ifdef __MMI_MESSAGES_USE_URL__
#include "Conversions.h" /* only for mmi_chset_ucs2_to_utf8_string */
#endif

#ifdef __MMI_VIDEO_STREAM__
#include "MediaAppGProt.h"
#endif /* __MMI_VIDEO_STREAM__ */

#include "MenuCuiGprot.h"
#ifdef __MMI_MESSAGES_USE_URL__
#include "BookmarkCuiGprot.h"
#endif

#ifdef __MMI_TOUCH_SCREEN__
#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
#if (MMI_MAX_SIM_NUM >= 2)
#include "NwUsabSrvGprot.h"
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */ 
#endif /* (defined (__MMI_TOUCH_SCREEN__)) *//*FMKR*/

#include "UseDetailCuiGprot.h"

/**************************************************************
* MARCO
**************************************************************/


/**************************************************************
 * Global Variables Declaration
 **************************************************************/
typedef struct
{
    S32 currHiliteIndex;
	applib_address_node_struct *cont_addr_list;
	mmi_msg_addr_type_enum addr_type;		
    S8 *addrList[MAX_USE_NUMBERS];
	S8 addrNumber[(APPLIB_MAX_USSD_LEN + 1) *ENCODING_LENGTH];
	U8 addr_num;
#ifdef __MMI_VIDEO_STREAM__
    U8 is_rtspUrl[MAX_USE_NUMBERS];
#endif

}mmi_sms_addr_struct;

#define MMI_MSG_MAX_EMAIL_ADDRESS_LEN   60

/**************************************************************
 * Global Function Declaration
 **************************************************************/


/**************************************************************
 * Static Variables Defination
 **************************************************************/
static mmi_sms_addr_struct g_sms_addr;
static MMI_ID mmi_sms_use_detail_gid = GRP_ID_INVALID;
/**************************************************************
 * Static Variables Defination
 **************************************************************/
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
	extern mmi_sms_hilite_struct hilite_cntx;
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */

/**************************************************************
 * Static Function Declaration
 **************************************************************/
static kal_bool mmi_sms_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num);
static void mmi_sms_free_addr_list(void);
static U8 mmi_sms_append_address_node_list(applib_address_node_struct *addr_list);
static void mmi_sms_add_to_addr_list(applib_address_node_struct *add_node);
static U8 mmi_sms_get_addr_list_from_msgtxt(S8* pText, U16 txtLen, U8 type, S8 *pAddrsss);

static void mmi_sms_use_detail_info_by_cui(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_malloc
 * DESCRIPTION
 *  function to call OslMalloc
 * PARAMETERS
 *  size        [IN]        size to malloc
 * RETURNS
 *  address be malloced
 *****************************************************************************/
void* mmi_sms_malloc(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    void* p;

    p = OslMalloc(size);
    return p;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_free
 * DESCRIPTION
 *  function to call OslMfree
 * PARAMETERS
 *  p        [IN]        address to be free
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_free(void* p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OslMfree(p);
    p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_stop_func
 * DESCRIPTION
 *  function to check the condition of stop extract address
 * PARAMETERS
 *  p        [IN]        address to be free
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool mmi_sms_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num)
{   
    if (num >= MAX_USE_NUMBERS)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_free_addr_list
 * DESCRIPTION
 *  Free Email Address List and Reset Email Address Count
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_free_addr_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_sms_addr.cont_addr_list != NULL)
    {
        applib_free_address_list((applib_address_node_struct **)&g_sms_addr.cont_addr_list, mmi_sms_free);
        g_sms_addr.cont_addr_list = NULL;
        g_sms_addr.addr_num = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_use_detail_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sms_use_detail_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
            if (!mmi_frm_scrn_get_count(mmi_sms_use_detail_gid))
            {
                mmi_frm_group_close(mmi_sms_use_detail_gid);
            }
            break;

        case EVT_ID_GROUP_DEINIT:
            mmi_sms_free_addr_list();
            mmi_sms_use_detail_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;

 
        case EVT_ID_CUI_USE_DETAIL_RESULT:
        {
            cui_use_detail_result_event_struct *use_detail_evt = (cui_use_detail_result_event_struct *)evt;
            cui_use_detail_close(use_detail_evt->sender_id);
        }
            break;
    
        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_use_detail_list
 * DESCRIPTION
 *  Entry use URL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID mmi_sms_use_detail_group_create(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_gid == GRP_ID_INVALID)
    {
        return parent_gid = GRP_ID_ROOT;
    }

    if (mmi_sms_use_detail_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(mmi_sms_use_detail_gid);
    }

    mmi_sms_use_detail_gid = mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_AUTO_GEN,
        mmi_sms_use_detail_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    return mmi_sms_use_detail_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_use_detail_list_sg
 * DESCRIPTION
 *  Entry use URL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_pre_entry_use_detail_list_sg(MMI_ID parent_gid, mmi_msg_addr_type_enum type, S8* pText, U16 txtlen, S8 *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_use_detail_group_create(parent_gid);
    mmi_sms_pre_entry_use_detail_list_ext(type, pText, txtlen, address);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_use_detail_list
 * DESCRIPTION
 *  Entry use URL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_pre_entry_use_detail_list(mmi_msg_addr_type_enum type, S8* pText, U16 txtlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_use_detail_group_create(GRP_ID_ROOT);
    mmi_sms_pre_entry_use_detail_list_ext(type, pText, txtlen, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_entry_use_detail_list_ext
 * DESCRIPTION
 *  Entry use URL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_entry_use_detail_list_ext(mmi_msg_addr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_addr.addr_type = type;
    
    mmi_sms_use_detail_info_by_cui();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_pre_entry_use_detail_list_ext
 * DESCRIPTION
 *  Entry use URL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_pre_entry_use_detail_list_ext(mmi_msg_addr_type_enum type, S8* pText, U16 txtlen, S8 *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_addr.addr_type = type;

    mmi_sms_get_addr_list_from_msgtxt((S8*)pText, txtlen, (U8)g_sms_addr.addr_type, address);

    if (g_sms_addr.addr_num > 0)
    {
        mmi_sms_use_detail_info_by_cui();
    }
    else
    {
        string_id = mmi_sms_get_no_addr_notify_string(type);

        mmi_sms_display_popup_ext(
            string_id,
            MMI_EVENT_FAILURE);

        mmi_frm_group_close(mmi_sms_use_detail_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_validate_number
 * DESCRIPTION
 *  Remove chars('-','(',')') from the highlight phone number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_validate_number(S8* srcNumber, S8* desNumber, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    MMI_BOOL end = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    i = 0;
    j = 0;

    while (srcNumber[i] && len--)
    {
        while (((srcNumber[i] == '-') ||
                (srcNumber[i] == '(') ||
                (srcNumber[i] == ')') ||
                (srcNumber[i] == ' ')) &&
                 srcNumber[i + 1] == '\0')
        {
            i += 2;

			if (!len)
			{
			    end = MMI_TRUE;
				break;
			}
			else
			{
				len--;
			}
        }

        if (end)
        {
            break;
        }
        else if ((srcNumber[i] != '\0')
			|| (srcNumber[i + 1] != '\0')
			)
		{
            desNumber[j] = srcNumber[i];
            desNumber[j + 1] = srcNumber[i + 1];

            i += 2;
            j += 2;
		}
        else
        {
            break;
        }
    }

    desNumber[j] = '\0';
    desNumber[j + 1] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_no_addr_notify_string
 * DESCRIPTION
 *  Get not address notify string
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_sms_get_no_addr_notify_string(mmi_msg_addr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_SMS_ADDR_PHONENUMBER:
            string_id = STR_GLOBAL_NO_NUMBER;
            break;

    #if (defined (__MMI_EMAIL__) || (defined(__MMI_PHB_OPTIONAL_FIELD__) ))
        case MMI_SMS_ADDR__EMAIL:
            string_id = STR_NO_EMAIL_ADDRESS_NOTIFICATION;
            break;
    #endif

    #if defined(__MMI_MESSAGES_USE_URL__)
        case MMI_SMS_ADDR__URL:
            string_id = STR_NOURL_NOTIFICATION;
            break;
    #endif

        case MMI_SMS_ADDR_USSD:
            string_id = STR_NOUSSD_NOTIFICATION;
            break;

        default:
            break;
    }

    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_addr_list_from_msgtxt
 * DESCRIPTION
 *  Extract all URL from message text
 * PARAMETERS
 *  pText       [IN]        Message text         
 *  txtLen      [IN]        The lenth of Message text
 *  pNum        [IN]        The number has existed
 * RETURNS
 *  Total URL count in message text
 *****************************************************************************/
static U8 mmi_sms_get_addr_list_from_msgtxt(S8 *pText, U16 txtLen, U8 type, S8 *pAddrsss)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_sms_get_addr_list_from_msgtxt_ext(pText, txtLen, type, pAddrsss, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_addr_list_from_msgtxt_ext
 * DESCRIPTION
 *  Extract all address from message text
 * PARAMETERS
 *  pText       [IN]        Message text         
 *  txtLen      [IN]        The lenth of Message text
 *  pNum        [IN]        The number has existed
 *  is_continue [IN]        whether continue to extract or not
 * RETURNS
 *  Total URL count in message text
 *****************************************************************************/
U8 mmi_sms_get_addr_list_from_msgtxt_ext(S8 *pText, U16 txtLen, U8 type, S8 *pAddrsss, MMI_BOOL is_continue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_addr_type_enum tmp_addr_type = 0;
    kal_bool is_stopped = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_continue == MMI_FALSE)
    {
        if(g_sms_addr.cont_addr_list != NULL)
        {
            applib_free_address_list((applib_address_node_struct **)&g_sms_addr.cont_addr_list, mmi_sms_free);

            g_sms_addr.addr_num = 0;
            g_sms_addr.cont_addr_list = NULL;
        }
    }
    else
    {
        if (g_sms_addr.addr_num == MAX_USE_NUMBERS)
        {
            return g_sms_addr.addr_num;
        }
    }

    switch(type)
    {
        case MMI_SMS_ADDR_PHONENUMBER:
            tmp_addr_type = APPLIB_ADDR_TYPE_PHONENUMBER;           
            break;

        case MMI_SMS_ADDR__EMAIL:
            tmp_addr_type = APPLIB_ADDR_TYPE_EMAIL;
            break;

        case MMI_SMS_ADDR__URL:
            {
            #ifdef __MMI_VIDEO_STREAM__
                U8 i;
            #endif /* __MMI_VIDEO_STREAM__ */ 

                tmp_addr_type = APPLIB_ADDR_TYPE_URL;
            #ifdef __MMI_VIDEO_STREAM__
                for (i = 0; i < MAX_USE_NUMBERS; i++)
                {
                    g_sms_addr.is_rtspUrl[i] = FALSE;
                }
            #endif /* __MMI_VIDEO_STREAM__ */ 
            }
            break;

        case MMI_SMS_ADDR_USSD:
            tmp_addr_type = APPLIB_ADDR_TYPE_USSD;
            break;
    }

    if (pAddrsss != NULL)
    {
        applib_address_node_struct *curr_addr_list = NULL;

        curr_addr_list = applib_get_exclusive_address_list_from_text_ext(
                                        tmp_addr_type,
                                        mmi_sms_malloc,
                                        mmi_sms_free,
                                        mmi_sms_check_stop_func,
                                        APPLIB_INPUT_DATA_TYPE_UNICODE,
                                        (char *)pAddrsss,
                                        mmi_ucs2strlen(pAddrsss)<<1,
                                        &is_stopped);

        if (curr_addr_list != NULL)
        {
            mmi_sms_append_address_node_list(curr_addr_list);
            
            if (g_sms_addr.addr_num == MAX_USE_NUMBERS)
            {    
                return g_sms_addr.addr_num;
            }
        }
    }

    if ((pText != NULL) && (txtLen > 0))
    {
        S8 *input_buff = pText;
        U32 input_buff_len;
        U32 remain_buff_len = txtLen;
        MMI_BOOL is_rollback = MMI_FALSE;

        while (remain_buff_len > 0)
        {
            applib_address_node_struct *curr_list;

            if (remain_buff_len > MMI_MSG_MAX_ALLOC_BUFF_LEN)
            {
                input_buff_len = MMI_MSG_MAX_ALLOC_BUFF_LEN;
            }
            else
            {
                input_buff_len = remain_buff_len;
            }

            is_stopped = KAL_FALSE;

            curr_list = applib_get_exclusive_address_list_from_text_ext(
                            tmp_addr_type,
                            mmi_sms_malloc,
                            mmi_sms_free,
                            mmi_sms_check_stop_func,
                            APPLIB_INPUT_DATA_TYPE_UNICODE,
                            (char *)input_buff,
                            input_buff_len,
                            &is_stopped);

            if (is_rollback == MMI_TRUE)
            {
                if (curr_list != NULL)
                {
                    if (curr_list->pos == 0)
                    {
                        applib_address_node_struct *temp_node = curr_list;

                        curr_list = curr_list->next;

                        temp_node->next = NULL;
                        applib_free_address_list((applib_address_node_struct **)&temp_node, mmi_sms_free);
                    }
                }

                is_rollback = MMI_FALSE;
            }

            if (curr_list != NULL)
            {
                if (remain_buff_len > MMI_MSG_MAX_ALLOC_BUFF_LEN)
                {
                    U32 start_offset;
                    applib_address_node_struct *tail_node = curr_list;
                    applib_address_node_struct *pre_node = curr_list;
                    
                    while (tail_node->next != NULL)
                    {
                        pre_node = tail_node;
                        tail_node = tail_node->next;
                    }

                    if ((tail_node->pos + tail_node->length) == MMI_MSG_MAX_ALLOC_BUFF_LEN)
                    {
                        if (tail_node->pos == 0)
                        {
                            start_offset = MMI_MSG_MAX_ALLOC_BUFF_LEN;
                        }
                        else
                        {
                            applib_address_node_struct *temp_node = tail_node;

                            start_offset = tail_node->pos;

                            if (pre_node != temp_node)
                            {
                                pre_node->next = NULL;
                            }
                            temp_node->next = NULL;
                            if (curr_list == temp_node)
                            {
                                curr_list = NULL;
                            }                       
                            applib_free_address_list((applib_address_node_struct **)&temp_node, mmi_sms_free);
                            temp_node = NULL;
                        }
                    }
                    else
                    {
                        start_offset = tail_node->pos + tail_node->length;
                    }

                    remain_buff_len -= start_offset;
                    input_buff += start_offset;
                }
                else
                {
                    remain_buff_len = 0;
                }

                mmi_sms_append_address_node_list(curr_list);

                if (g_sms_addr.addr_num == MAX_USE_NUMBERS)
                {
                    return g_sms_addr.addr_num;
                }
            }
            else
            {
                if (remain_buff_len > MMI_MSG_MAX_ALLOC_BUFF_LEN)
                {
                    remain_buff_len -= (MMI_MSG_MAX_ALLOC_BUFF_LEN - MMI_MSG_MAX_ADDRESS_LEN * ENCODING_LENGTH);
                    input_buff += (MMI_MSG_MAX_ALLOC_BUFF_LEN - MMI_MSG_MAX_ADDRESS_LEN * ENCODING_LENGTH);
                    is_rollback = MMI_TRUE;
                }
                else
                {
                    remain_buff_len = 0;
                }
            }
        }
    }

    return g_sms_addr.addr_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_append_address_node_list
 * DESCRIPTION
 *  Append the g_sms_addr.cont_addr_list 
 * PARAMETERS
 *  addr_list       [IN]   new address node list
 * RETURNS
 *  Total address number
 *****************************************************************************/
static U8 mmi_sms_append_address_node_list(applib_address_node_struct *addr_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *curr_node = addr_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_list == NULL)
    {
        return g_sms_addr.addr_num;
    }

    if (g_sms_addr.cont_addr_list == NULL)
    {
        applib_address_node_struct *prev_tmp_node = NULL;

        g_sms_addr.cont_addr_list = addr_list;
        g_sms_addr.addr_num = 0;

        while (curr_node != NULL)
        {
            mmi_sms_add_to_addr_list(curr_node);
            
            prev_tmp_node = curr_node;
            curr_node = curr_node->next;

            if (g_sms_addr.addr_num == MAX_USE_NUMBERS)
            {
                break;
            }
        }

        if (curr_node != NULL)
        {
            applib_address_node_struct *del_node = curr_node;
    
            prev_tmp_node->next = NULL;
            
            applib_free_address_list((applib_address_node_struct **)&del_node, mmi_sms_free);
        }
    }
    else
    {
        if (g_sms_addr.addr_num < MAX_USE_NUMBERS)
        {
            applib_address_node_struct *tail_node = g_sms_addr.cont_addr_list;
            applib_address_node_struct *add_list = NULL;
            applib_address_node_struct *add_tail_node = NULL;

            while (curr_node != NULL)
            {
                applib_address_node_struct *comp_node = g_sms_addr.cont_addr_list;
                MMI_BOOL is_duplicated = MMI_FALSE;

                while(comp_node != NULL)
                {
                    if (mmi_ucs2cmp((S8*)comp_node->data, (S8*)curr_node->data) == 0)
                    {
                        is_duplicated = MMI_TRUE;
                        break;
                    }

                    comp_node = comp_node->next;
                }

                if (is_duplicated == MMI_TRUE)
                {
                    applib_address_node_struct *del_node = curr_node;
                    
                    curr_node = curr_node->next;
                    
                    del_node->next = NULL;
                    
                    applib_free_address_list((applib_address_node_struct **)&del_node, mmi_sms_free);
                }
                else
                {
                    applib_address_node_struct *add_node = curr_node;

                    curr_node = curr_node->next;

                    add_node->next = NULL;

                    if (add_list == NULL)
                    {
                        add_list = add_node;
                        add_tail_node = add_list;
                    }
                    else
                    {
                        add_tail_node->next = add_node;
                        add_tail_node = add_node;
                    }
                    
                    mmi_sms_add_to_addr_list(add_node);

                    if (g_sms_addr.addr_num == MAX_USE_NUMBERS)
                    {
                        break;
                    }
                }
            }

            while (tail_node->next != NULL)
            {
                tail_node = tail_node->next;
            }

            tail_node->next = add_list;
        }

        if (curr_node != NULL)
        {
            applib_free_address_list((applib_address_node_struct **)&curr_node, mmi_sms_free);
        }
    }

    return g_sms_addr.addr_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_to_addr_list
 * DESCRIPTION
 *  Add the address to the address list
 * PARAMETERS
 *  add_node       [IN]   added address node
 *  index          [IN]   the address index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_add_to_addr_list(applib_address_node_struct *add_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *addr_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(add_node->dataType == APPLIB_ADDR_TYPE_PHONENUMBER)
    {
        addr_item = (S8*)add_node->data2;
    }
    else
    {
        U16 char_num;

        addr_item = (S8*)add_node->data;

        char_num = (U16)mmi_ucs2strlen(addr_item);

        srv_sms_remove_escape_char(addr_item, addr_item, char_num);

        /*only to display EMAIL_MAX_DISP_ADDR_NUM addresses*/
        if (add_node->dataType == APPLIB_ADDR_TYPE_EMAIL)
        {
            if (mmi_ucs2strlen((S8*)addr_item) > MMI_MSG_MAX_EMAIL_ADDRESS_LEN)
            {
                return;
            }
        }

        if (add_node->dataType == APPLIB_ADDR_TYPE_URL)
        {
            if (mmi_ucs2strlen((S8*)addr_item) > MMI_MSG_MAX_ADDRESS_LEN)
            {
                return;
            }
        }
    }
    
    if (mmi_ucs2strlen(addr_item) > MMI_MSG_MAX_ADDRESS_LEN)
    {
        memset(
            (S8*)(addr_item + MMI_MSG_MAX_ADDRESS_LEN * ENCODING_LENGTH),
            0,
            ENCODING_LENGTH);
    }
    
    g_sms_addr.addrList[g_sms_addr.addr_num++] = addr_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_use_detail_info_by_cui
 * DESCRIPTION
 *  "Use Detail CUI" is used in USSD
 * PARAMETERS
 *  idx     [IN] hilite index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_use_detail_info_by_cui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_use_detail_basic_obj_struct *obj_list;
    mmi_id use_detail_gid;
    cui_use_detail_type_enum type = CUI_USE_DETAIL_TYPE_PHONENUMBER;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_sms_addr.addr_type)
    {
        case MMI_SMS_ADDR_PHONENUMBER:
            type = CUI_USE_DETAIL_TYPE_PHONENUMBER;
            break;
        case MMI_SMS_ADDR__EMAIL:
            type = CUI_USE_DETAIL_TYPE_EMAIL;
            break;
        case MMI_SMS_ADDR__URL:
            type = CUI_USE_DETAIL_TYPE_URL;
            break;
        case MMI_SMS_ADDR_USSD:
            type = CUI_USE_DETAIL_TYPE_USSD;
            break;
        default:
            MMI_ASSERT(!"Invalid Use detail enum");
            break;
    }
    
    obj_list = OslMalloc(sizeof(cui_use_detail_basic_obj_struct) * g_sms_addr.addr_num);
    
    {
        S32 i;
        applib_address_node_struct *cont_addr_list = g_sms_addr.cont_addr_list;
        for(i = 0; i  < g_sms_addr.addr_num; ++i)
        {
            obj_list[i].detail_txt = (U16*)cont_addr_list->data;
            obj_list[i].txtlen = cont_addr_list->length / ENCODING_LENGTH;
            obj_list[i].type = type;
            cont_addr_list = cont_addr_list->next;
        }
    }
    use_detail_gid = cui_use_detail_create(mmi_sms_use_detail_gid, obj_list, g_sms_addr.addr_num, NULL);
    cui_use_detail_set_view_flag(use_detail_gid, (MMI_BOOL)MMI_TRUE);
   
    cui_use_detail_run(use_detail_gid);
    
    OslMfree(obj_list);
}
#endif/*__MMI_TELEPHONY_SUPPORT__*/

