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
 *  SmsAppUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Application Utility API
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
//#ifdef __MMI_TELEPHONY_SUPPORT__

/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "custom_mmi_default_value.h"
#include "wgui.h"
#include "wgui_categories_util.h"
#include "SmsAppGprot.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "app_usedetails.h"
#include "mmi_msg_context.h"
#include "ems.h"
#include "ps_public_enum.h"
#include "mmi_frm_mem_gprot.h"
#include "fs_type.h"
#include "fs_func.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MessagesMiscell.h"
#include "Gsm7BitNationalLang.h"
#include "SmsGuiInterfaceType.h"
#include "UmSrvDefs.h"
#include "UMGProt.h"
#include "menucuigprot.h"
#include "mmi_rp_app_sms_def.h"
#include "custom_phb_config.h"
#include "mmi_frm_scenario_gprot.h"

#include "SmsAppProt.h"
#include "SmsAppUtil.h"
#include "SmsAppType.h"
#include "SmsSrvGprot.h"
#include "PhbSrvGprot.h"
#include "PhonebookGProt.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "gui_ems.h"
#include "SimCtrlSrvGProt.h"
#include "ModeSwitchSrvGprot.h"
#if defined(__MMI_WLAN_FEATURES__)
#include "NetSetAppGprot.h"
#include "NetSetSrvGprot.h"
#endif
#if (MMI_MAX_SIM_NUM >= 2) 
#include "NwUsabSrvGprot.h"
#endif
#if (MMI_MAX_SIM_NUM >= 2)
#if defined(__MMI_MMS_STANDALONE_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__)
#include "UcSrvGprot.h"
#endif
#endif
#include "mmi_frm_utility_gprot.h"
#include "Gui_ems.h"
#include "NetSetAppGprot.h"
#include "gui_ems.h"

#ifdef __MMI_BT_MAP_CLIENT__
#include "BtcmSrvGprot.h"
#endif

/**************************************************************
* Structure Declaration
**************************************************************/
typedef enum
{
    STATUS_ICON_READ = 0,
    STATUS_ICON_UNREAD,
    #ifndef __MMI_SMS_BOX_ICON_SLIM__
    STATUS_ICON_SENT,
    STATUS_ICON_UNSENT,
    #endif
    STATUS_ICON_SS_NCOMP,
    STATUS_ICON_TOTAL
}mmi_sms_status_icon_enum;

#ifdef  __GENERAL_TTS__
#define SRV_SMS_MAX_TTS_BUF_SIZE           (200 + SRV_SMS_MAX_SEG *160)
typedef struct
{
    U16 msg_id;
    U16 cur_msg_id;
    U16 tts_buffer[SRV_SMS_MAX_TTS_BUF_SIZE];
    MMI_BOOL is_reading;
} mmi_sms_tts_info_struct;
#endif /* __GENERAL_TTS__ */


/**************************************************************
* Global Variables Defination
**************************************************************/
#ifdef  __GENERAL_TTS__
static mmi_sms_tts_info_struct g_sms_tts = {0};
#endif


/**************************************************************
* Global Variables Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/


/**************************************************************
* Static Function Declaration
**************************************************************/
#ifdef  __GENERAL_TTS__
static void mmi_sms_get_tts_content(U8* text, MMI_BOOL need_content);
static void mmi_sms_tts_read_msg_callback(srv_sms_callback_struct* callback_data);
srv_prof_ret mmi_sms_tts_play_msg_callback(srv_prof_ret result);
static void mmi_sms_play_msg_ext(U16 msg_id, MMI_BOOL need_content);
#endif


/**************************************************************
* Function Defination
**************************************************************/
#ifdef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_append_string_to_ems_buffer
 * DESCRIPTION
 *  copy text buffer to ems data text buffer, used instead of AddString of EMS lib
 * PARAMETERS      
 *  msg_id              [IN]        
 *  address             [OUT]         
 *  max_address_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
EMSTATUS mmi_sms_append_string_to_ems_buffer(EMSData *pEms, CHAR *ucs2_buffer, S32 textLen)
{
    MMI_BOOL result;
    EMSTATUS EMS_result = EMS_EMS_DATA_EXCEEDED;
    result = mmi_sms_check_if_insert_text_possible((const CHAR*)pEms->textBuffer, (const CHAR*)ucs2_buffer);
    if (result)
    {
        mmi_ucs2ncpy((CHAR*)pEms->textBuffer, (const CHAR *)ucs2_buffer, textLen);
        pEms->textLength = textLen * ENCODING_LENGTH;
        EMS_result = EMS_OK;
    }
    
    return EMS_result;
}

#endif /* __ULC_SLIM_EMS__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_address
 * DESCRIPTION
 *  get sms address
 * PARAMETERS      
 *  msg_id              [IN]        
 *  address             [OUT]         
 *  max_address_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_get_address(U16 msg_id, S8* address, U8 max_address_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    if (srv_sms_get_msg_mti(msg_id) == SRV_SMS_MTI_STATUS_REPORT)
    {
        mmi_ucs2ncpy((S8*)address, (S8*) GetString(STR_INBOX_REPORT_ID), max_address_len);
    }
    else
    {
        S8 temp[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];

	   #ifndef __MMI_SMS_SLIM__
        srv_sms_get_msg_address(msg_id, temp);
       #else
		mmi_sms_get_hilite_msg_addr((S8*)temp);
		#endif

        if ((temp[0] == '\0') && (temp[1] == '\0'))
        {
            mmi_ucs2cpy((S8*) address, (S8*) GetString(STR_GLOBAL_NO_NUMBER));
        }
        else
        {
            srv_phb_get_name_by_number((U16*)temp, (U16*)address, MMI_PHB_NAME_LENGTH);
            if (mmi_ucs2strlen((S8 *)address) == 0)
            {
                mmi_ucs2cpy((S8 *)address, (S8 *)temp); 
            }
        }
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_date_time
 * DESCRIPTION
 *  Get message date time
 * PARAMETERS
 *  dateStr     [?]             
 *  timeStr     [?]             
 *  scts        [?]             
 *  a(?)        [IN/OUT]        Date string
 *  c(?)        [IN]            Scts
 *  b(?)        [IN/OUT]        Time string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_get_msg_date_time(U16 msg_id, S8 *date_str, S8 *time_str)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_time datetime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_get_msg_timestamp(msg_id, (MYTIME*)&datetime);

    if (date_str != NULL)
    {
        date_string(&datetime, (UI_string_type)date_str, DT_IDLE_SCREEN);
    }

    if (time_str != NULL)
    {
        time_string(&datetime, (UI_string_type)time_str, DT_IDLE_SCREEN);
    }
#endif/*__MMI_TELEPHONY_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_icon
 * DESCRIPTION
 *  get sms icon id
 * PARAMETERS
 *  msg_type        [IN]        
 *  msg_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_sms_get_icon(U16 msg_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 icon_id = 0;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_box_enum msg_box_tpye;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_get_msg_list_index(&msg_box_tpye, msg_id);

    if (msg_box_tpye == SRV_SMS_BOX_UNSENT)
    {
        srv_sms_send_status_enum unsent_status;

        unsent_status = srv_sms_get_unsent_msg_status(msg_id);

#if 0   /*removed for Gemini+ as we are showing 2nd column as sim indicator  */
    #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else/* (MMI_MAX_SIM_NUM >= 2)  */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (MMI_MAX_SIM_NUM >= 2)  */
    #endif

        switch (unsent_status)
        {
            case SRV_SMS_SEND_WAITING:
                icon_id = IMG_MESSAGE_WAITING;
                break;

            case SRV_SMS_SEND_FAIL:
                icon_id = IMG_MESSAGE_FAILTOSENT;
                break;

            case SRV_SMS_SEND_SENDING:
                icon_id = IMG_MESSAGE_SENDING;
                break;

            default:
                MMI_ASSERT(0);
                break;
        }
    
    }
    else
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    {
    #ifdef __SMS_LIST_SIM_SPECIFIC_ICON__
        srv_sms_storage_enum storage_type;
        mmi_sms_storage_type_enum storage_id = SMS_STORAGE_ME;
	#endif
        mmi_sms_status_icon_enum status_index;

#if 0   /*removed for Gemini+ as we are showing 2nd column as sim indicator  */
    #if (MMI_MAX_SIM_NUM >= 2) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* (MMI_MAX_SIM_NUM >= 2)  */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (MMI_MAX_SIM_NUM >= 2)  */
    #endif
#ifdef __SMS_LIST_SIM_SPECIFIC_ICON__
            U16 status_icon[SMS_STORAGE_TOTAL][STATUS_ICON_TOTAL] = 
                {
                    {
                        IMG_MESSAGE_READ,
                        IMG_MESSAGE_UNREAD,
                        IMG_MESSAGE_SENT,
                        IMG_MESSAGE_UNSENT,
                        IMG_MESSAGE_SS_NCOMP

                    },
                    {
                        IMG_MESSAGE_SIM_READ,
                        IMG_MESSAGE_SIM_UNREAD,
                        IMG_MESSAGE_SIM_SENT,
                        IMG_MESSAGE_SIM_UNSENT,
                        IMG_MESSAGE_SIM_SS_NCOMP
                    }
                };
#else
U16 status_icon[STATUS_ICON_TOTAL] = 
                {
                        IMG_MESSAGE_READ,
                        IMG_MESSAGE_UNREAD,
                        #ifndef __MMI_SMS_BOX_ICON_SLIM__
                        IMG_MESSAGE_SENT,
                        IMG_MESSAGE_UNSENT,
                        #endif
                        IMG_MESSAGE_SS_NCOMP 
                };
#endif
#ifdef __SMS_LIST_SIM_SPECIFIC_ICON__       
        storage_type = srv_sms_get_msg_storage_type(msg_id);

        if (storage_type == SRV_SMS_STORAGE_SIM)
        {
            storage_id = SMS_STORAGE_SIM;
        }
#endif
#if 0   /*removed for Gemini+ as we are showing 2nd column as sim indicator */
    #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (MMI_MAX_SIM_NUM >= 2)  */
#endif    

        if (srv_sms_is_msg_complete(msg_id) == MMI_FALSE)
        {
            status_index = STATUS_ICON_SS_NCOMP;
        }
        else
        {
            srv_sms_status_enum msg_status;

            msg_status = srv_sms_get_msg_status(msg_id);

            msg_status &= (~SRV_SMS_STATUS_UNSUPPORTED);

            switch (msg_status)
            {
                case SRV_SMS_STATUS_UNREAD:
                    status_index = STATUS_ICON_UNREAD;
                    break;

                case SRV_SMS_STATUS_READ:
                    status_index = STATUS_ICON_READ;
                    break;
#ifndef __MMI_SMS_BOX_ICON_SLIM__
                case SRV_SMS_STATUS_SENT:
                    status_index = STATUS_ICON_SENT;
                    break;

                case SRV_SMS_STATUS_UNSENT:
                case SRV_SMS_STATUS_DRAFT:
                default:
                    status_index = STATUS_ICON_UNSENT;
                    break;
#else
			case SRV_SMS_STATUS_SENT:
			case SRV_SMS_STATUS_UNSENT:
			case SRV_SMS_STATUS_DRAFT:
			status_index = STATUS_ICON_READ;
			break;
			
			default:
				status_index = STATUS_ICON_READ;
				break;
#endif
            }
        }

#if 0   /*removed for Gemini+ as we are showing 2nd column as sim indicator  */
    #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
    #else /* (MMI_MAX_SIM_NUM >= 2)  */
/* under construction !*/
    #endif /* (MMI_MAX_SIM_NUM >= 2)  */
#endif

#ifdef __SMS_LIST_SIM_SPECIFIC_ICON__         
        icon_id = status_icon[storage_id][status_index];
#else
icon_id = status_icon[status_index];
#endif
    }

    return icon_id;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_sms_ready
 * DESCRIPTION
 *  Check whether SMS is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL mmi_sms_is_sms_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    return srv_sms_is_sms_ready();
    #else
    return MMI_TRUE;
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_inbox_header
 * DESCRIPTION
 *  Get inbox message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8* mmi_sms_get_msg_address(U16 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S8 asc_num[MAX_DIGITS_SMS + 1];
    S8 usc2_num[(MAX_DIGITS_SMS + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_SMS_SLIM__
    srv_sms_get_msg_address(msg_index, usc2_num);
    #else
		mmi_sms_get_hilite_msg_addr((S8*)usc2_num);
		#endif
    mmi_ucs2_to_asc(asc_num, usc2_num);

    return (U8 *)asc_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_empty_address
 * DESCRIPTION
 *  Get inbox message header
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_is_empty_address(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (mmi_sms_is_sms_email(msg_id) == MMI_TRUE)
    {
        S8* email_addr = g_sms_cntx.sms_email_addr;
    
        if ((email_addr[0] == '\0') && (email_addr[1] == '\0'))
        {
            result = MMI_TRUE;
        }
    }
    else
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    {
    	#ifndef __MMI_SMS_SLIM__
        const S8* asc_num;  
        asc_num = srv_sms_get_msg_asc_address(msg_id);

        if ((asc_num == NULL) || (asc_num[0] == '\0'))
        {
            result = MMI_TRUE;
        }
        #else
         result = MMI_FALSE;
        #endif
    }

    return result;
}


#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_save_contact
 * DESCRIPTION
 *  Entry inbox message screen
 * PARAMETERS
 *  U16 scrid : screen id to be delete.
 *  U16 type : box type
 * RETURNS
 *  BOOL: TRUE if delete the screen. FALSE if not delete
 *****************************************************************************/
MMI_BOOL mmi_sms_save_contact(U16 scrid, U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL     delete_screen = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phb_is_save_contact_notify_on())
    {
        S8 number[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
		#ifndef __MMI_SMS_SLIM__
        srv_sms_get_msg_address(g_sms_cntx.curr_msg_id, number);
        #else
		mmi_sms_get_hilite_msg_addr((S8*)number);
		#endif

        if ((number[0] != '\0')  || (number[1] != '\0'))
        {
            if ((srv_sms_check_ucs2_number(number) == MMI_TRUE) &&
                (srv_phb_check_number_exist((U16*)number) == MMI_FALSE) &&
                (mmi_phb_is_num_in_phb((U16*)number) == MMI_FALSE))
            {
                srv_phb_contact_data_struct phbData;
        
                mmi_phb_unsaved_data_init(&phbData);
                phbData.number = (U16 *)number;
                
                mmi_phb_add_data_to_unsaved_list(PHB_STORAGE_MAX, SRV_PHB_ENTRY_FIELD_NUMBER, &phbData);
        
                if (mmi_phb_get_unsaved_data_num() > 0)
                {
                    mmi_phb_pre_entry_unsaved_data_confirm();
                    mmi_frm_scrn_close(g_sms_gid, scrid);
                    delete_screen = MMI_TRUE;
                }
            }
        }
    }

    return delete_screen;
}
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_text_to_ems_data
 * DESCRIPTION
 *  Add text into the EMS Data
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 *  ucs2_content    [IN]    UCS2 content 
 * RETURNS
 *  EMSTATUS
 *****************************************************************************/
EMSTATUS mmi_sms_add_text_to_ems_data(EMSData *ems_data, S8* ucs2_content)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS result = EMS_OK;
    U16 ucs2_content_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_content_len = (U16)mmi_ucs2strlen(ucs2_content);

    if (ucs2_content_len > 0)
    {
        {
            MMI_BOOL is_ucs2_char;

            is_ucs2_char = srv_sms_check_ucs2(ucs2_content, ucs2_content_len);

            if (is_ucs2_char == MMI_TRUE)
            {
                result = EMSSetDCS(ems_data, SMSAL_UCS2_DCS);

                if (result == EMS_OK)
                {
            #ifdef __ULC_SLIM_EMS__
                    result = mmi_sms_append_string_to_ems_buffer(ems_data, ucs2_content, ucs2_content_len);
            #else /* __ULC_SLIM_EMS__ */
                    result = AddString(ems_data, (U8*)ucs2_content, ucs2_content_len, NULL);
            #endif /* __ULC_SLIM_EMS__ */
                }
            }
            else
            {
                result = EMSSetDCS(ems_data, SMSAL_DEFAULT_DCS);

                if (result == EMS_OK)
                {
                    result = mmi_sms_add_gsm_text_to_ems_data(ems_data, ucs2_content);
                }
            }
        }
    }

    return result;
#else
    return EMS_OK;
#endif/*__MMI_TELEPHONY_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_gsm_text_to_ems_data
 * DESCRIPTION
 *  add (GSM character set, UCS2 Format) Text into EMS Data
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 *  ucs2_content    [IN]    UCS2 content 
 * RETURNS
 *  void
 *****************************************************************************/
EMSTATUS mmi_sms_add_gsm_text_to_ems_data(EMSData *ems_data, S8* ucs2_content)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS result = EMS_OK;
    U16 char_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    char_num = (U16)mmi_ucs2strlen(ucs2_content);

    if (char_num > 0)
    {
    #ifdef __SMS_R8_NATION_LANGUAGE__
        EMSNationalLanguage sys_lang;

        mmi_7bit_get_national_lang_table(&sys_lang);
        
        result = EMSSetNationalLanguage(ems_data, &sys_lang);

        if (result == EMS_OK)
    #endif /* __SMS_R8_NATION_LANGUAGE__ */
        {
            U16 ext_char_num;

            ext_char_num = (U16)srv_sms_count_extension_char(ucs2_content, char_num);

            if (ext_char_num > 0)
            {
                S8 *remaining_buff = ucs2_content;
                U16 remaining_char_num = char_num;

                while (remaining_char_num > 0)
                {
                    S8 *temp_buff = remaining_buff;
                    S8 *add_buff;
                    U16 add_char_num;
                    U16 temp_char_num;

                    if (remaining_char_num > ((MMI_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH) / 2))
                    {
                        temp_char_num = (MMI_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH) / 2;
                        remaining_buff = remaining_buff + temp_char_num * ENCODING_LENGTH;
                        remaining_char_num = remaining_char_num - temp_char_num;
                    }
                    else
                    {
                        temp_char_num = remaining_char_num;
                        remaining_char_num = 0;
                    }

                    add_buff = OslMalloc((temp_char_num * 2) * ENCODING_LENGTH);

                    add_char_num = mmi_sms_convert_to_extension_char_buff(add_buff, temp_buff, temp_char_num);
                #ifndef __ULC_SLIM_EMS__
                    result = AddString(ems_data, (U8*)add_buff, add_char_num, NULL);
                #else /* __ULC_SLIM_EMS__ */
                    result = mmi_sms_append_string_to_ems_buffer(ems_data, (CHAR*)add_buff, add_char_num);
                #endif /* __ULC_SLIM_EMS__ */

                    OslMfree(add_buff);

                    if (result != EMS_OK)
                    {
                        break;
                    }

                }
            }
            else
            {
        #ifndef __ULC_SLIM_EMS__
                result = AddString(ems_data, (U8*)ucs2_content, char_num, NULL);
        #else /* __ULC_SLIM_EMS__ */
                result = mmi_sms_append_string_to_ems_buffer(ems_data, (CHAR*)ucs2_content, char_num);
        #endif /* __ULC_SLIM_EMS__ */
            }
        }
    }

    return result;
#else
    return EMS_OK;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_add_data_to_ems_data
 * DESCRIPTION
 *  Add text into the EMS Data
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 *  src_port        [IN]    Source port number
 *  dest_port       [IN]    Destination port number
 *  file_path       [IN]    File path of the content 
 *  content_buff    [IN]    The buffer ot content
 *  buff_size       [IN]    The buffer size of content_buff
 * RETURNS
 *  EMSTATUS
 *****************************************************************************/
EMSTATUS mmi_sms_add_data_to_ems_data(
                        EMSData *ems_data,
                        U16 src_port,
                        U16 dest_port,
                        S8 *file_path,
                        S8 *content_buff,
                        U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSTATUS result = EMS_OK;
    S8 *ucs2_content = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        U16 char_num = 0;

        if (file_path != NULL)
        {
            FS_HANDLE fs_hd;

            fs_hd = FS_Open((WCHAR*)file_path, FS_READ_ONLY);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_1, fs_hd);

            if (fs_hd > 0)
            {
                U32 content_file_size;

                FS_GetFileSize(fs_hd, (UINT*)&content_file_size);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_2, content_file_size);

                if (content_file_size > 0)
                {
                    if (content_file_size > ((MMI_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH) - 1))
                    {
                        result = EMS_EMS_DATA_EXCEEDED;
                    }
                    else
                    {
                        S32 fs_err_code = 0;
                        S8 *temp_buff;
                        S32 read_size = 0;

                        temp_buff = OslMalloc(content_file_size + 1);
                        fs_err_code = FS_Read(fs_hd, temp_buff, content_file_size, (UINT*)&read_size);

                        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_3, fs_err_code);

                        if (fs_err_code < 0)
                        {
                            result = EMS_INVALID_EMS_DATA;
                        }
                        else
                        {
                            ucs2_content = OslMalloc((content_file_size + 1) * ENCODING_LENGTH);

                            mmi_sms_asc_to_wchar(ucs2_content, temp_buff, content_file_size);
                            char_num = content_file_size;
                        }

                        OslMfree(temp_buff);
                    }
                }
            }
            else
            {
                result = EMS_INVALID_EMS_DATA;
            }

            FS_Close(fs_hd);

            if (result != EMS_OK)
            {
                break;
            }
        }
        else if ((content_buff != NULL) && (buff_size > 0))
        {
            ucs2_content = OslMalloc((buff_size + 1) * ENCODING_LENGTH);

            mmi_sms_asc_to_wchar(ucs2_content, content_buff, buff_size);
            char_num = buff_size;
        }

        result = EMSSetPortNum(ems_data, src_port, dest_port);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_4, result);

        if (result != EMS_OK)
        {
            break;
        }

        result = EMSSetDCS(ems_data, SMSAL_8BIT_DCS);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_5, result);

        if (result != EMS_OK)
        {
            result = EMS_EMS_DATA_EXCEEDED;
            break;
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_6, char_num);

        if (char_num > 0)
        {
        #ifdef __ULC_SLIM_EMS__
            result = mmi_sms_append_string_to_ems_buffer(ems_data, (CHAR*)ucs2_content, char_num);
        #else /* __ULC_SLIM_EMS__ */
            result = AddString(ems_data, (U8*)ucs2_content, char_num, NULL);
        #endif /* __ULC_SLIM_EMS__ */

            if (result != EMS_OK)
            {
                result = EMS_EMS_DATA_EXCEEDED;
            }
        }
    } while (0);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_ADD_DATA_TO_EMS_DATA_7, result);

    if (ucs2_content != NULL)
    {
        OslMfree(ucs2_content);
    }

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_convert_to_extension_char_buff
 * DESCRIPTION
 *  If the buffer is contained GSM extension characters, 
 *  add a escape char before it
 * PARAMETERS
 *  dest_buf        [OUT]       the destination buffer
 *  src_buf         [IN]        the source buffer 
 *  char_num        [IN]        src_buff char number
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_sms_convert_to_extension_char_buff(S8 *dest_buf, S8 *src_buf, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dest_buffer = (U16*)dest_buf;
    U16 *src_buffer = (U16*)src_buf;
    U16 c;
    U16 src_count = 0;
    U16 dest_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (src_count < char_num)
    {
        c = src_buffer[src_count++];

        if (c != EMS_ESCAPE_CHARACTER)
        {
            if (mmi_7bit_check_gsm_ext_character(c))
            {
                dest_buffer[dest_count++] = EMS_ESCAPE_CHARACTER;
            }

            dest_buffer[dest_count++] = c;
        }
        
    }

    return dest_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_asc_to_wchar
 * DESCRIPTION
 *  convert the each byte of the source to one wise char according to 
 *  the source buffer len
 * PARAMETERS
 *  dest_buf        [OUT]       destintaion buffer
 *  src_buf         [IN]        source buffer
 *  src_buf_len     [IN]        source buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_asc_to_wchar(S8 *dest_buf, S8 *src_buf, U32 src_buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *wchar_dest_buff = (U16*)dest_buf;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < src_buf_len; i++)
    {
        wchar_dest_buff[i] = (U16)src_buf[i];
    }

    wchar_dest_buff[i] = '\0';
}

#ifndef __ULC_SLIM_EMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_ems_content_empty
 * DESCRIPTION
 *  Check whether the EMS Data is empty
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_is_ems_content_empty(EMSData *ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ems_data->textLength == 0) && (ems_data->listHead == NULL))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}

#else /* __ULC_SLIM_EMS__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_ems_content_empty
 * DESCRIPTION
 *  Check whether the EMS Data is empty
 * PARAMETERS
 *  ems_data        [IN]    EMS Data to be added
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_is_ems_content_empty(EMSData *ems_data)
{

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(mmi_ucs2strlen((const CHAR *)ems_data->textBuffer) == 0);
}

#endif /* __ULC_SLIM_EMS__ */

#ifdef __MMI_MESSAGES_SMS_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_sms_email
 * DESCRIPTION
 *  Check whether Msg Is A SMS Email Interworking Message
 * PARAMETERS
 *  msg_index       [IN]    MSG Index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_is_sms_email(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_get_msg_pid(msg_id) == SRV_SMS_PID_EMAIL)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_send_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_is_send_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    result = (MMI_BOOL)srv_sms_is_sms_valid();
    #endif
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_IS_SEND_ENABLE, result);

    return result;
}
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
void mmi_sms_append_sim_name_to_menu_items_and_hide_invalid_sims(MMI_ID menu_cui_pid, MMI_ID*sim_menus, MMI_ID* sim_strings)
{
                        S32 sim_index;
                        mmi_sim_enum sims[] = {
                                                MMI_SIM1, 
                                                MMI_SIM2,
        #if (MMI_MAX_SIM_NUM >= 3)
                                                MMI_SIM3,
        #if (MMI_MAX_SIM_NUM >= 4)
                                                MMI_SIM4,
        #endif /* (MMI_MAX_SIM_NUM >= 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
                                                MMI_SIM_NONE
                                                };
                        for (sim_index = 0; sim_index < MMI_MAX_SIM_NUM; ++sim_index)
                        {
                            WCHAR sim_description[MAX_SUBMENU_CHARACTERS + 1] = { 0 };
			    MMI_BOOL is_sim_valid = (MMI_BOOL)srv_nw_usab_is_usable(sims[sim_index]);
                            cui_menu_set_item_hidden(menu_cui_pid, sim_menus[sim_index], !is_sim_valid);
                            {
                                S32 length;
                                mmi_ucs2cpy((CHAR*)sim_description, GetString(sim_strings[sim_index]));
                                length = mmi_ucs2strlen((const CHAR*)sim_description);
                                mmi_netset_get_sim_name_with_brace(sims[sim_index], sim_description + length, MAX_SUBMENU_CHARACTERS - length);
                                cui_menu_set_item_string(menu_cui_pid, sim_menus[sim_index], sim_description);

                            }
                        }
}
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_hide_send_sms_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_hide_send_sms_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    return (MMI_BOOL)srv_sms_is_sms_valid();
    #else
    return MMI_TRUE;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_is_valid_or_addr
 * DESCRIPTION
 *  Check if inbox OA address valid
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_check_is_valid_oa_addr(U16 msg_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ucs2_addr;
    S8 ucs2_num[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    MMI_BOOL is_number_valid = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (mmi_sms_is_sms_email(msg_id) == MMI_TRUE)
    {
        ucs2_addr = (S8 *)g_sms_cntx.sms_email_addr;
        is_number_valid = (MMI_BOOL)applib_is_valid_email_address_unicode((kal_wchar*)ucs2_addr);    
    }
    else
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    {
       #ifndef __MMI_SMS_SLIM__
        srv_sms_get_msg_address(msg_id, ucs2_num);
        #else
		mmi_sms_get_hilite_msg_addr((S8*)ucs2_num);
		#endif

        ucs2_addr = (S8*)ucs2_num;
        is_number_valid = srv_sms_check_ucs2_number(ucs2_addr);
    }

    if (((ucs2_addr[0] == '\0') && (ucs2_addr[1] == '\0')) ||
        (is_number_valid == MMI_FALSE))
    {
        return MMI_FALSE;
    }
#endif/*__MMI_TELEPHONY_SUPPORT__*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_msg_icon
 * DESCRIPTION
 *  Set msg icon for unread/full message.
 * PARAMETERS
 *  blink       [IN]        
 *  unblink     [IN]        
 *  a(?)        [IN]        Blink
 *  b(?)        [IN]        Unblink
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_msg_icon(MMI_BOOL is_set_mem_icon, srv_sms_sim_enum sim_id)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum mmi_sim  = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
    #ifdef __MMI_STATUS_ICON_BAR_SLIM__
    U32 index = 0;
    #else  //__MMI_STATUS_ICON_BAR_SLIM__
    U32 index = mmi_frm_sim_to_index(mmi_sim);
    #endif  //__MMI_STATUS_ICON_BAR_SLIM__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready() == MMI_TRUE)
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        /* For showing memory full icon (different icon for all SIMs with loop + blink in status bar) */
    #ifdef __MMI_TELEPHONY_SUPPORT__
        if (is_set_mem_icon == MMI_TRUE)
        {
            S32 mem_full_icon[] =
            {
                STATUS_ICON_FULL_SMS
            #if !defined(__MMI_STATUS_ICON_BAR_SLIM__)
            #if (MMI_MAX_SIM_NUM >= 2)
                ,STATUS_ICON_SLAVE_FULL_SMS
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                ,STATUS_ICON_SIM3_FULL_SMS
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                ,STATUS_ICON_SIM4_FULL_SMS
            #endif
            #endif  //!defined(__MMI_STATUS_ICON_BAR_SLIM__)
            };
#ifdef __MMI_MAINLCD_96X64__
			 wgui_status_icon_bar_reset_icon_display(mem_full_icon[0]);
#else
            wgui_status_icon_bar_reset_icon_display(mem_full_icon[index]);
#endif
            if ((g_msg_cntx.msg_full_ind[index]) && (srv_sim_ctrl_is_available(mmi_sim)))
            {
				#ifdef __MMI_MAINLCD_96X64__
                wgui_status_icon_bar_blink_icon(mem_full_icon[0]);
				#else
				wgui_status_icon_bar_blink_icon(mem_full_icon[index]);
				#endif
            }
        }
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
    }

    wgui_status_icon_bar_update();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_hide_msg_icon
 * DESCRIPTION
 *  Hide msg icon for unread/full message.
 * PARAMETERS
 *  blink       [IN]        
 *  unblink     [IN]        
 *  a(?)        [IN]        Blink
 *  b(?)        [IN]        Unblink
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_hide_msg_icon(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (sim_id == SRV_SMS_SIM_1)
#endif /* (MMI_MAX_SIM_NUM >= 2)  */
    {
#if 0
/* under construction !*/
#endif
    #ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SUBLCD_SMS);
    #endif
    #if (MMI_MAX_SIM_NUM > 2)
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_FULL_SMS);
    #endif
    }
#if (MMI_MAX_SIM_NUM == 2)
    if (sim_id == SRV_SMS_SIM_2)
    {
#if 0
/* under construction !*/
#endif
    #ifdef __MMI_SUBLCD__
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SUBLCD_SLAVE_SMS);
    #endif
    }
#endif
#if (MMI_MAX_SIM_NUM > 2)
    if (sim_id == SRV_SMS_SIM_2)
    {
#if 0
/* under construction !*/
#endif
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SLAVE_FULL_SMS);
    }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    if (sim_id == SRV_SMS_SIM_3)
    {
#if 0
/* under construction !*/
#endif
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM3_FULL_SMS);
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
	if (sim_id == SRV_SMS_SIM_4)
	{
#if 0
/* under construction !*/
#endif
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SIM4_FULL_SMS);
	}
#endif

    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_box_exist_unread
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_check_box_exist_unread(srv_sms_sim_enum sim_id, srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 msg_id;
    srv_sms_status_enum status;
    MMI_BOOL result = MMI_FALSE;
#ifdef __MMI_TELEPHONY_SUPPORT__
    U16 box_list_size = srv_sms_get_list_size(msg_box_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_SET_MSG_ICON_3, box_list_size);

    for (i = 0; i < box_list_size; i++)
    {
        msg_id = srv_sms_get_msg_id(msg_box_type, i);
        status = srv_sms_get_msg_status(msg_id);

    #if (MMI_MAX_SIM_NUM >= 2)
        if (srv_sms_get_msg_sim_id(msg_id) == sim_id)
    #endif /* (MMI_MAX_SIM_NUM >= 2)  */
        {
            if (status & SRV_SMS_STATUS_UNREAD)
            {
    			MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_SET_MSG_ICON_2, i);
                result = MMI_TRUE;
                break;
            }
        }
    }
#endif/*__MMI_TELEPHONY_SUPPORT__*/
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_exist_unread_sms
 * DESCRIPTIONSet msg icon for unread/full message.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_is_exist_unread_sms(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_sms_check_box_exist_unread(sim_id, SRV_SMS_BOX_INBOX);

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (result == MMI_FALSE)
    {
        result = mmi_sms_check_box_exist_unread(sim_id, SRV_SMS_BOX_SIM);
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_um_filter_sim_id
 * DESCRIPTION
 *  Get current fileter sms sim id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_sim_enum mmi_sms_get_um_filter_sim_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __UM_SUPPORT__

#if (MMI_MAX_SIM_NUM >= 2)
    srv_um_sim_enum um_sim_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)

    um_sim_id = mmi_um_get_message_list_filter_type(g_sms_cntx.user_data);
    return mmi_sms_um_sim_to_sms_sim(um_sim_id);
#else
    return SRV_SMS_SIM_1;
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif

	return SRV_SMS_SIM_1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_gui_check_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_gui_check_ucs2(S8* ucs2_text_buff, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U16 *ucs2_buff = (U16*)ucs2_text_buff;
    U16 c;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (count < char_num)
    {
        c = ucs2_buff[count];

        if (gui_ems_test_UCS2_character(c))
        {
            result = MMI_TRUE;
            break;
        }

        count++;
    }

    return result;
}

#ifndef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_list_opt_menu_id
 * DESCRIPTION
 *  Get message list option MENU ID
 * PARAMETERS
 *  msg_id      :       [IN]            message ID
 * RETURNS
 *  MMI_MENU_ID
 *****************************************************************************/
MMI_MENU_ID mmi_sms_get_list_opt_menu_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID menu_id = 0;
    srv_sms_box_enum curr_box_type;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    srv_sms_status_enum curr_msg_status;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = (U16)msg_id;
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);
#endif

    switch (curr_box_type)
    {
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_SMS_BOX_ARCHIVE:
        {
            if (curr_msg_status & SRV_SMS_STATUS_SENT)
            {
                menu_id = MENU_ID_SMS_SENT_LIST_OPT;
            }
            else
            {
                menu_id = MENU_ID_SMS_INBOX_LIST_OPT;
            }
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_SMS_BOX_INBOX:
        {
            menu_id = MENU_ID_SMS_INBOX_LIST_OPT;
            break;
        }

        case SRV_SMS_BOX_OUTBOX:
        {
            menu_id = MENU_ID_SMS_SENT_LIST_OPT;
            break;
        }

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case SRV_SMS_BOX_DRAFTS:
        {
            menu_id = MENU_ID_SMS_DRAFTS_LIST_OPT;
            break;
        }
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */

    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case SRV_SMS_BOX_UNSENT:
        {
            menu_id = MENU_ID_SMS_UNSENT_LIST_OPT;
            break;
        }
    #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        case SRV_SMS_BOX_UNSENT:
            menu_id = MENU_ID_SMS_UNSENT_LIST_OPT;
            break;
    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
        {
            menu_id = MENU_ID_SMS_SIM_LIST_OPT;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    #ifdef __MMI_UM_REPORT_BOX__
        case SRV_SMS_BOX_REPORT:
            menu_id = MENU_ID_SMS_REPORT_LIST_OPT;
            break;
    #endif /* __MMI_UM_REPORT_BOX__ */

        default:
            menu_id = MENU_ID_SMS_DEFAULT_LIST_OPT;
            break;
    }

    return menu_id;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_viewer_opt_menu_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_MENU_ID mmi_sms_get_viewer_opt_menu_id(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id = 0;
#ifdef __MMI_TELEPHONY_SUPPORT__
    srv_sms_box_enum curr_box_type;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    srv_sms_status_enum curr_msg_status;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_cntx.curr_msg_id = (U16)msg_id;
    srv_sms_get_msg_list_index(&curr_box_type, g_sms_cntx.curr_msg_id);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);
#endif

    switch (curr_box_type)
    {
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_SMS_BOX_ARCHIVE:
        {
            if (curr_msg_status & SRV_SMS_STATUS_SENT)
            {
                menu_id = MENU_ID_SMS_SENT_VIEWER_OPT;
            }
            else
            {
                menu_id = MENU_ID_SMS_INBOX_VIEWER_OPT;
            }
            break;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_SMS_BOX_INBOX:
        {
            menu_id = MENU_ID_SMS_INBOX_VIEWER_OPT;
            break;
        }

        case SRV_SMS_BOX_OUTBOX:
        {
            menu_id = MENU_ID_SMS_SENT_VIEWER_OPT;
            break;
        }

    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        case SRV_SMS_BOX_DRAFTS:
        {
            menu_id = MENU_ID_SMS_DRAFTS_VIEWER_OPT;
            break;
        }
    #endif /* __MMI_MESSAGES_DRAFT_BOX__ */

    #if (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__))
        case SRV_SMS_BOX_UNSENT:
        {
            menu_id = MENU_ID_SMS_UNSENT_VIEWER_OPT;
            break;
        }
    #endif /* (defined(__MMI_MESSAGES_DRAFT_BOX__) && !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)) */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
        {
            menu_id = MENU_ID_SMS_SIM_VIEWER_OPT;
            break;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

        default:
            menu_id = MENU_ID_SMS_DEFAULT_VIEWER_OPT;
            break;
    }
#endif/*__MMI_TELEPHONY_SUPPORT__*/
    return menu_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_is_allow_reentry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_is_allow_reentry(void)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_sms_is_send_action_busy() == MMI_FALSE) &&
        (srv_sms_is_sms_ready() == MMI_TRUE))
    {
        result = MMI_TRUE;
    }

    return result;
#else
    return MMI_TRUE;
#endif/*__MMI_TELEPHONY_SUPPORT__*/
}


#if (MMI_MAX_SIM_NUM >= 2) 
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_save_send_select_sim_leaf_item
 * DESCRIPTION
 *  Entry Send SIM Card Select Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_save_send_select_sim_leaf_item(MMI_ID cui_menu_gid, MMI_MENU_ID menu_id, mmi_sms_sim_op_check_func_t hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_MAP_CLIENT__
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (mmi_sms_get_valid_sim_op_count(hdlr) > 1)
    {
        cui_menu_set_non_leaf_item(cui_menu_gid, menu_id, MMI_TRUE);
    }
    else
    {
        cui_menu_set_non_leaf_item(cui_menu_gid, menu_id, MMI_FALSE);
    }
#else /* __MMI_TELEPHONY_SUPPORT__ */
    cui_menu_set_non_leaf_item(cui_menu_gid, menu_id, MMI_FALSE);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#else /* __MMI_BT_MAP_CLIENT__ */
	if (mmi_sms_get_valid_sim_op_count(hdlr) > 1)
	{
        cui_menu_set_non_leaf_item(cui_menu_gid, menu_id, MMI_TRUE);
    }
    else
    {
        cui_menu_set_non_leaf_item(cui_menu_gid, menu_id, MMI_FALSE);
    }
#endif
}
#endif

#ifdef __UM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_um_box_type
 * DESCRIPTION
 *  convert the SMS box type to UM type
 * PARAMETERS
 *  msg_box_type        [IN]  	sms app box type      
 * RETURNS
 *  void
 *****************************************************************************/
srv_um_msg_box_enum mmi_sms_um_get_um_box_type(
                        srv_sms_status_enum status_type, 
                        srv_sms_folder_enum folder_type,
                        srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_msg_box_enum um_box_type = SRV_UM_MSG_BOX_NONE;
    srv_sms_box_enum sms_box_type = SRV_SMS_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    sms_box_type = srv_sms_get_list_type(status_type, storage_type, folder_type);
    #endif
    um_box_type = mmi_sms_um_sms_box_to_um(sms_box_type);

	return um_box_type;
}

typedef struct 
{
    srv_sms_box_enum sms_box;
    srv_um_msg_box_enum um_box;
}mmi_um_sms_box_pair;

static const mmi_um_sms_box_pair mmi_um_sms_box_map[] = 
{
    {SRV_SMS_BOX_INBOX, SRV_UM_MSG_BOX_INBOX},
    {SRV_SMS_BOX_UNSENT, SRV_UM_MSG_BOX_UNSENT},
    {SRV_SMS_BOX_OUTBOX, SRV_UM_MSG_BOX_SENT},
    {SRV_SMS_BOX_DRAFTS, SRV_UM_MSG_BOX_DRAFT},
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__  
    {SRV_SMS_BOX_ARCHIVE, SRV_UM_MSG_BOX_ARCHIVE},
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    {SRV_SMS_BOX_SIM, SRV_UM_MSG_BOX_SIM},
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
        
#ifdef __MMI_UM_REPORT_BOX__
    {SRV_SMS_BOX_REPORT, SRV_UM_MSG_BOX_REPORT},
#endif /* __MMI_UM_REPORT_BOX__ */
    {SRV_SMS_BOX_NONE, SRV_UM_MSG_BOX_NONE}
};
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_um_box_to_sms
 * DESCRIPTION
 *  convert the UM box type to SMS type
 * PARAMETERS
 *  msg_box_type        [IN]     UM Box type   
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_box_enum mmi_sms_um_um_box_to_sms(srv_um_msg_box_enum um_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S32 total = sizeof(mmi_um_sms_box_map) / sizeof(mmi_um_sms_box_pair);
    for (; index < total; ++index)
    {
        if (um_box_type == mmi_um_sms_box_map[index].um_box)
        {
            break;
        }
    }
    MMI_ASSERT(index <= total);
	return mmi_um_sms_box_map[index].sms_box;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_sms_box_to_um
 * DESCRIPTION
 *  convert the SMS box type to UM type
 * PARAMETERS
 *  msg_box_type        [IN]  	sms app box type      
 * RETURNS
 *  void
 *****************************************************************************/
srv_um_msg_box_enum mmi_sms_um_sms_box_to_um(srv_sms_box_enum sms_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S32 total = sizeof(mmi_um_sms_box_map) / sizeof(mmi_um_sms_box_pair);
    for (; index < total; ++index)
    {
        if (sms_box_type == mmi_um_sms_box_map[index].sms_box)
        {
            break;
        }
    }
    MMI_ASSERT(index <= total);
    return mmi_um_sms_box_map[index].um_box;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_um_type_by_msgid
 * DESCRIPTION
 *  Get um type by msgid
 * PARAMETERS
 *  msgid        [IN]  	msg id      
 * RETURNS
 *  srv_um_msg_box_enum
 *****************************************************************************/
srv_um_msg_box_enum mmi_msg_get_um_type_by_msgid(U32 msgid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum msg_box_type = SRV_SMS_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    srv_sms_get_msg_list_index(&msg_box_type, (U16)msgid);
    #endif

	return mmi_sms_um_sms_box_to_um(msg_box_type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_query_um_msg_box
 * DESCRIPTION
 *  query UM box type according msg id
 * PARAMETERS
 *  msg_id    :     [IN]        message ID
 * RETURNS
 *  srv_um_msg_box_enum
 *****************************************************************************/
srv_um_msg_box_enum mmi_sms_query_um_msg_box(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum curr_box_type = SRV_SMS_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TELEPHONY_SUPPORT__
    srv_sms_get_msg_list_index(&curr_box_type, (U16)msg_id);
    #endif

    return mmi_sms_um_sms_box_to_um(curr_box_type);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_valid_sim_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  srv_sms_sim_enum
 *****************************************************************************/
U32 mmi_sms_get_valid_sim_op_count(mmi_sms_sim_op_check_func_t hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 menuitems = 0;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
    	if (hdlr(mmi_frm_index_to_sim(index)))
        {
		    menuitems++;
        }
    }

    return menuitems;
}


#if (MMI_MAX_SIM_NUM >= 2)
#if defined(__MMI_MMS_STANDALONE_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_id_to_uc_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  srv_sms_sim_enum
 *****************************************************************************/
srv_uc_sim_id mmi_sms_sim_id_to_uc_sim(srv_sms_sim_enum sms_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_sim_id uc_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sms_sim_id)
    {
        case SRV_SMS_SIM_1:
            uc_sim_id = SRV_UC_SIM_ID_GSM_SIM1;
            break;

        case SRV_SMS_SIM_2:
            uc_sim_id = SRV_UC_SIM_ID_GSM_SIM2;
            break;

    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_SMS_SIM_3:
            uc_sim_id = SRV_UC_SIM_ID_GSM_SIM3;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_SMS_SIM_4:
            uc_sim_id = SRV_UC_SIM_ID_GSM_SIM4;
            break;
    #endif

        default:
            uc_sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
            break;
    }

    return uc_sim_id;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_sim_str_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  srv_sms_sim_enum
 *****************************************************************************/
U16 mmi_sms_get_sim_str_id(mmi_sim_enum mmi_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 simStrId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_sim == MMI_SIM2)
    {
        simStrId = STR_GLOBAL_SIM_2;
    }
#if (MMI_MAX_SIM_NUM >= 3)    
    else if (mmi_sim == MMI_SIM3)
    {
        simStrId = STR_GLOBAL_SIM_3;
    }
#endif                
#if (MMI_MAX_SIM_NUM >= 4)    
    else if (mmi_sim == MMI_SIM4)
    {
        simStrId = STR_GLOBAL_SIM_4;
    }
#endif
    else
    {
        simStrId = STR_GLOBAL_SIM_1;
    }

    return simStrId;
}


#ifdef __UM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_sim_to_sms_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_sim_enum mmi_sms_um_sim_to_sms_sim(srv_um_sim_enum um_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sms_sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (um_sim_id & SRV_UM_SIM_GSM_SIM2)
    {
        sms_sim_id |= SRV_SMS_SIM_2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (um_sim_id & SRV_UM_SIM_GSM_SIM3)
    {
        sms_sim_id |= SRV_SMS_SIM_3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    if (um_sim_id & SRV_UM_SIM_GSM_SIM4)
    {
        sms_sim_id |= SRV_SMS_SIM_4;
    }
#endif
    if (um_sim_id & SRV_UM_SIM_GSM_SIM1)
#endif
    {
        sms_sim_id |= SRV_SMS_SIM_1;
    }

    return sms_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_id_to_um_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_um_sim_enum mmi_sms_sim_id_to_um_sim(srv_sms_sim_enum sms_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_sim_enum um_sim_id = SRV_UM_SIM_GSM_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (sms_sim_id == SRV_SMS_SIM_2)
    {
        um_sim_id = SRV_UM_SIM_GSM_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (sms_sim_id == SRV_SMS_SIM_3)
    {
        um_sim_id = SRV_UM_SIM_GSM_SIM3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    else if (sms_sim_id == SRV_SMS_SIM_4)
    {
        um_sim_id = SRV_UM_SIM_GSM_SIM4;
    }
#endif
    else
#endif
    {
        um_sim_id = SRV_UM_SIM_GSM_SIM1;
    }

    return um_sim_id;
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#endif

#ifdef  __GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_play_msg
 * DESCRIPTION
 *  Play one message content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_tts_play_msg_by_id(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_tts.msg_id = msg_id;
    if (g_sms_tts.is_reading)
    {        
        return;
    }
    else
    {
        srv_sms_msg_data_struct *msg_data;

        msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));

        msg_data->para_flag = SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_NUM;

        msg_data->para_flag = SRV_SMS_PARA_CONTENT_EMS;
        msg_data->content_ems = (EMSData*)GetEMSDataForView(NULL, 1);
        g_sms_tts.cur_msg_id = msg_id;
        g_sms_tts.is_reading = MMI_TRUE;
        srv_sms_read_msg(
            msg_id,
            MMI_FALSE,
            msg_data,
            mmi_sms_tts_read_msg_callback,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_play_msg
 * DESCRIPTION
 *  Play one message content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_play_msg_by_content(U16 msg_id)
{
    mmi_sms_play_msg_ext(msg_id, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_play_msg
 * DESCRIPTION
 *  Play one message content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_play_msg_without_content(U16 msg_id)
{
    mmi_sms_play_msg_ext(msg_id, MMI_FALSE);
}

mmi_ret mmi_sms_new_message_tts_proc(mmi_event_struct* evt)
{
    /* if new sms event, play tts or new message tone */
    if (MMI_SCENARIO_ID_NEW_SMS == ((mmi_nmgr_custom_evt_struct *)evt)->scenario_id)
    {
        if (mmi_tts_setting_is_sms_tts_enabled())
        {
            mmi_sms_play_msg_without_content(g_msg_cntx.msg_ind_index);
        }
        else
        {
            srv_prof_play_tone(SRV_PROF_TONE_SMS, NULL);
        }
    }
    return MMI_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_play_msg
 * DESCRIPTION
 *  Play one message content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_play_msg_ext(U16 msg_id, MMI_BOOL need_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *ems_data = (EMSData*)GetEMSDataForView(NULL, 0);;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_tts.cur_msg_id = msg_id;
    mmi_sms_get_tts_content((U8 *)ems_data->textBuffer, need_content);    
    srv_prof_play_tone_with_text(SRV_PROF_TONE_SMS, (U8 *)g_sms_tts.tts_buffer, 0, mmi_sms_tts_play_msg_callback);   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_play_msg_callback
 * DESCRIPTION
 *  play current msg callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_tts_read_msg_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_cb_struct *read_msg_cb_data;
    srv_sms_msg_data_struct *msg_data;
    EMSData *ems_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_tts.is_reading = MMI_FALSE;
    if (g_sms_tts.cur_msg_id != g_sms_tts.msg_id)
    {
        mmi_sms_tts_play_msg_by_id(g_sms_tts.msg_id);
        return;
    }
    read_msg_cb_data = (srv_sms_read_msg_cb_struct*)callback_data->action_data;
    msg_data = read_msg_cb_data->msg_data;
    ems_data = msg_data->content_ems;
    mmi_sms_get_tts_content((U8 *)ems_data->textBuffer, MMI_TRUE);    
    srv_prof_play_tone_with_text(SRV_PROF_TONE_SMS, (U8 *)g_sms_tts.tts_buffer, 0, mmi_sms_tts_play_msg_callback);   
    OslMfree(msg_data);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_tts_play_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_prof_ret mmi_sms_tts_play_msg_callback(srv_prof_ret result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_PROF_RET_NO;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_tts_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_get_tts_content(U8* text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 number[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    U16 name[MMI_PHB_NAME_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   #ifndef __MMI_SMS_SLIM__
    srv_sms_get_msg_address(g_sms_tts.cur_msg_id, number);
    #else
    mmi_sms_get_hilite_msg_addr((S8*)number);
    #endif

    srv_phb_get_name_by_number((U16*)number, (U16*)name, MMI_PHB_NAME_LENGTH);
    if (mmi_ucs2strlen((S8*)name))
    {
        mmi_ucs2cpy((CHAR *)g_sms_tts.tts_buffer, (S8*)name);
    }
    else
    {
        mmi_ucs2cpy((CHAR *)g_sms_tts.tts_buffer, number);
    }
    mmi_ucs2cat((CHAR *)g_sms_tts.tts_buffer, GetString(STR_ID_SMS_TTS_FROM));
    mmi_ucs2cat((CHAR *)g_sms_tts.tts_buffer, GetString(STR_ID_SMS_TTS_CONTENT));
    mmi_ucs2cat((CHAR *)g_sms_tts.tts_buffer, text);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_tts_stop_play
 * DESCRIPTION
 *  Play one message content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_tts_stop_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_SMS);
}
#endif /* __GENERAL_TTS__ */

//#endif /* __MMI_TELEPHONY_SUPPORT__ */

