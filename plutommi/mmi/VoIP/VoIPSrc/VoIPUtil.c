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
 *  VoIPUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MTK_TARGET__
#include <windows.h>
#endif
#include "MMI_include.h"
#include "MMI_features.h"

#ifdef __MMI_VOIP__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "Conversions.h"
#include "DateTimeGprot.h"
#include "FileManagerGProt.h"
#include "FileMgrSrvGProt.h"
#include "gpioInc.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "ProfilesDefs.h"
#include "ProfileGprots.h"
#include "PhoneBookGprot.h"
#include "app2soc_struct.h"
#include "soc_api.h"
#include "med_struct.h"
#include "rtp_api.h"
#include "UcmSrvGProt.h"
#include "..\..\..\Service\UcmSrv\UcmSrvIntProt.h"
#include "mmi_rp_srv_gcall_def.h" /* IMG_ID_GCALL_OUTGOING */
#include "PhoneBookDef.h" /* IMG_PHB_DEFAULT */


#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"

extern void* g_voip_ucm_user_data;

const U8 sipUri[10] = { 's', '\0', 'i', '\0', 'p', '\0', ':', '\0', '\0', '\0' }; /* sip: */
const U8 telUri[10] = { 't', '\0', 'e', '\0', 'l', '\0', ':', '\0', '\0', '\0' }; /* tel: */
const U8 anonyUri[30] = { 's', '\0', 'i', '\0', 'p', '\0', ':', '\0', 'a', '\0', 'n', '\0', 'o', '\0', 'n', '\0', 'y', '\0', 'm', '\0', 'o', '\0', 'u', '\0', 's', '\0', '@', '\0', '\0', '\0' }; /* sip: anonymous@ */
const U8 sosUri[8] = { 's', '\0', 'o', '\0', 's', '\0', '\0', '\0' }; /* sos */
const U8 sos112[8] = { '1', '\0', '1', '\0', '2', '\0', '\0', '\0' }; /* 112 */
const U8 sos911[8] = { '9', '\0', '1', '\0', '1', '\0', '\0', '\0' }; /* 911 */
const U8 zeroIp[8] = { '0', '\0', '0', '\0', '0', '\0', '\0', '\0' }; /* 000 */
const U16 VoIPDTMFDigits[MMI_VOIP_MAX_NUM_DIGITS] = 
{
    KEY_1, KEY_2, KEY_3,
    KEY_4, KEY_5, KEY_6,
    KEY_7, KEY_8, KEY_9,
    KEY_STAR, KEY_0, KEY_POUND
};

const mmi_voip_error_string_struct g_voip_error_table[] = 
{
    {VOIP_UNSPECIFIED_ERROR, STR_ID_VOIP_UNKNOWN_ERROR},
    {VOIP_NOT_REGISTERED, STR_ID_VOIP_NOT_REGISTER},
    {VOIP_ALREADY_REGISTERED, STR_ID_VOIP_ALREADY_REGISTER},
    {VOIP_INVALID_PARAM, STR_ID_VOIP_INVALID_PARAMETER},
    {VOIP_CREATE_UAC_ERROR, STR_ID_VOIP_SIP_ERROR},
    {VOIP_GET_ADDR_FAILED, STR_ID_VOIP_INVALID_URI},
    {VOIP_CALL_ABORT_LOCALLY, STR_ID_VOIP_CALL_END},
    {VOIP_RECV_BYE, STR_ID_VOIP_CALL_END},
    {VOIP_INCORRECT_CALL_STATE, STR_ID_VOIP_ACTION_INVALID},
    {VOIP_BEARER_DISCONNECTED, STR_ID_VOIP_NETWORK_DOWN},
    {VOIP_ABORT_FAILED, STR_ID_VOIP_CALL_END},
    {VOIP_CALL_NOT_EXIST, STR_ID_VOIP_CALL_NOT_EXIST},
    {VOIP_INVALID_URI, STR_ID_VOIP_INVALID_URI},
    {VOIP_SWAP_FAILED, STR_ID_VOIP_SWAP_FAIL},
    {VOIP_SWAP_PARTIAL_FAILED, STR_ID_VOIP_SWAP_FAIL},
    {VOIP_TRANSFER_FAILED, STR_ID_VOIP_TRANSFER_FAIL},
    {VOIP_MERGE_FAILED, STR_ID_VOIP_CONFERENCE_FAIL},
    {VOIP_MERGE_PARTIAL_FAILED, STR_ID_VOIP_CONFERENCE_FAIL},
    {VOIP_NAT_FAILED, STR_ID_VOIP_NAT_ERROR},
    {VOIP_TEMPORARY_BUSY, STR_ID_VOIP_ACTION_CONFLICT},
    {VOIP_UNSUPPORTED_NAT_TYPE, STR_ID_VOIP_NAT_ERROR},
    {VOIP_NETWORK_ERROR, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_BUSY, STR_ID_VOIP_ACTION_CONFLICT},
    {VOIP_INVALID_CALL_REQ, STR_ID_VOIP_ACTION_INVALID},
    {VOIP_PARTIAL_FAILED, STR_ID_VOIP_UNKNOWN_ERROR},
    {VOIP_REREGISTER_FAILED, STR_ID_VOIP_REGISTER_FAIL},
    {VOIP_SDP_MISMATCHED, STR_ID_VOIP_SDP_ERROR},
    {VOIP_DNS_ERROR, STR_ID_VOIP_DNS_ERROR},
    {VOIP_NO_RESOURCE, STR_ID_VOIP_UNKNOWN_ERROR},
    {VOIP_SIP_FS_ERROR, STR_ID_VOIP_UNKNOWN_ERROR},
    {VOIP_DHCP_ERROR, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_SIP_300_MULTIPLE_CHOICES, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_SIP_301_MOVED_PERMANENTLY, STR_ID_VOIP_NUMBER_MOVE},
    {VOIP_SIP_302_MOVED_TEMPORARILY, STR_ID_VOIP_NUMBER_MOVE},
    {VOIP_SIP_305_USE_PROXY, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_400_BAD_REQUEST, STR_ID_VOIP_ACTION_INVALID},
    {VOIP_SIP_401_UNAUTHORIZED, STR_ID_VOIP_AUTHENTICATION_FAIL},
    {VOIP_SIP_403_FORBIDDEN, STR_ID_VOIP_ACTION_FORBIDDEN},
    {VOIP_SIP_404_NOT_FOUND, STR_ID_VOIP_USER_NOT_FOUND},
    {VOIP_SIP_405_METHOD_NOT_ALLOW, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_406_NOT_ACCEPTABLE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_407_PROXY_AUTH_REQUIRED, STR_ID_VOIP_AUTHENTICATION_FAIL},
    {VOIP_SIP_408_REQUEST_TIMEOUT, STR_ID_VOIP_REQUEST_TIMEOUT},
    {VOIP_SIP_412_CONDITIONAL_REQ_FAIL, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_422_INTERVAL_TOO_BRIEF, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_423_INTERVAL_TOO_BRIEF, STR_ID_VOIP_SIP_ERROR},
    {VOIP_SIP_478_UNRESOLVEABLE_DEST, STR_ID_VOIP_USER_NOT_FOUND},
    {VOIP_SIP_480_TEMP_UNAVAILABLE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_481_CALL_TRANS_NOT_EXIST, STR_ID_VOIP_CALL_NOT_EXIST},
    {VOIP_SIP_484_ADDRESS_INCOMPLETE, STR_ID_VOIP_USER_NOT_FOUND},
    {VOIP_SIP_486_BUSY_HERE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_487_REQ_TERMINATED, STR_ID_VOIP_CALL_END},
    {VOIP_SIP_488_NOT_ACCEPTABLE_HERE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_491_REQUEST_PENDING, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_499_UNRESOLVEABLE_DEST, STR_ID_VOIP_USER_NOT_FOUND},
    {VOIP_SIP_500_SERVER_INT_ERROR, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_SIP_503_SERVICE_UNAVAILABLE, STR_ID_VOIP_NETWORK_ERROR},
    {VOIP_SIP_600_BUSY_EVERYWHERE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_603_DECLINE, STR_ID_VOIP_USER_BUSY},
    {VOIP_SIP_606_NOT_ACCEPTABLE, STR_ID_VOIP_USER_BUSY},
    {0, STR_ID_VOIP_UNKNOWN_ERROR}
};

extern MMI_BOOL mmi_voip_get_caller_res_info(void *info);
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_set_processing_parameter
 * DESCRIPTION
 *  Set processing screen parameter.
 * PARAMETERS
 *  titleStr            [IN]        Title string
 *  bodyStr             [IN]        Body string
 *  animationImg        [IN]        Animation image
 *  lskStr              [IN]        LSK display string
 *  lskFunc             [IN]        LSK function pointer
 *  rskStr              [IN]        RSK display string
 *  rskFunc             [IN]        RSK function pointer
 *  sendFunc            [IN]        SEND key function pointer
 *  endFunc             [IN]        END key function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_set_processing_parameter(
        U16 titleStr,
        U16 bodyStr,
        U16 animationImg,
        U16 lskStr,
        FuncPtr lskFunc,
        U16 rskStr,
        FuncPtr rskFunc,
        FuncPtr sendFunc,
        FuncPtr endFunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->proc_scr_info.title_string = titleStr;
    g_voip_cntx_p->proc_scr_info.body_string = bodyStr;
    g_voip_cntx_p->proc_scr_info.animation_image = animationImg;
    g_voip_cntx_p->proc_scr_info.lsk_string = lskStr;
    g_voip_cntx_p->proc_scr_info.lsk_funcPtr = lskFunc;
    g_voip_cntx_p->proc_scr_info.rsk_string = rskStr;
    g_voip_cntx_p->proc_scr_info.rsk_funcPtr = rskFunc;
    g_voip_cntx_p->proc_scr_info.send_funcPtr = sendFunc;
    g_voip_cntx_p->proc_scr_info.end_funcPtr = endFunc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_entry_processing_screen
 * DESCRIPTION
 *  General entry function of processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_entry_processing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VOIP_PROCESSING, NULL, mmi_voip_entry_processing_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VOIP_PROCESSING);
    ShowCategory66Screen(
        g_voip_cntx_p->proc_scr_info.title_string,
        GetRootTitleIcon(MENU_ID_VOIP_MAIN),
        g_voip_cntx_p->proc_scr_info.lsk_string,
        IMG_GLOBAL_OK,
        g_voip_cntx_p->proc_scr_info.rsk_string,
        IMG_GLOBAL_BACK,
        (U8*) GetString(g_voip_cntx_p->proc_scr_info.body_string),
        g_voip_cntx_p->proc_scr_info.animation_image,
        NULL);
    SetLeftSoftkeyFunction(g_voip_cntx_p->proc_scr_info.lsk_funcPtr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(g_voip_cntx_p->proc_scr_info.rsk_funcPtr, KEY_EVENT_UP);
    SetKeyHandler(g_voip_cntx_p->proc_scr_info.send_funcPtr, KEY_SEND, KEY_EVENT_DOWN);
    SetKeyHandler(g_voip_cntx_p->proc_scr_info.end_funcPtr, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_validate_port
 * DESCRIPTION
 *  Validate port. 0~65535 is a valid range of port.
 * PARAMETERS
 *  unicodePort     [IN]        Port string in unicode
 * RETURNS
 *  TRUE means port number is valid; FALSE means port number is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_validate_port(U8 *unicodePort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 portNumber = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    portNumber = gui_atoi((UI_string_type) unicodePort);
    if ((portNumber >= 0) && (portNumber <= 65535))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_validate_uri
 * DESCRIPTION
 *  Validate uri. Only one @ can appear in the uri.
 *  The @ cannot in the beginning of the uri,
 *  and cannot in the end of the uri, either.
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  TRUE means uri is valid; FALSE means uri is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_validate_uri(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *lowercaseUri = OslMalloc((VOIP_URI_LEN +1 ) * ENCODING_LENGTH);
    S32 count = 0;
    S8 foundAt = 0;
    U8 charUnit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(lowercaseUri, 0, ((VOIP_URI_LEN + 1) * ENCODING_LENGTH));
    mmi_voip_convert_uri_lower_case(unicodeUri, lowercaseUri, VOIP_URI_LEN * ENCODING_LENGTH);

    if ((mmi_ucs2strlen((S8*)lowercaseUri) == 0) ||
        (!mmi_ucs2cmp((S8*)lowercaseUri, (S8*)sipUri)) ||
        (!mmi_ucs2cmp((S8*)lowercaseUri, (S8*)telUri)))
    {
        OslMfree(lowercaseUri);
        return TRUE;
    }
    while (unicodeUri[count] != '\0' || unicodeUri[count + 1] != '\0')
    {
        if (unicodeUri[count] > 0x7e || unicodeUri[count + 1] > 0x7e)
        {
            OslMfree(lowercaseUri);
            return FALSE;
        }
        charUnit = unicodeUri[count];
        switch (charUnit)
        {
            case '@':
            {
                foundAt++;
                if (count == 0) /* @xxxxx */
                {
                    OslMfree(lowercaseUri);
                    return FALSE;
                }
                else if (foundAt > 1)
                {
                    OslMfree(lowercaseUri);
                    return FALSE;
                }
                else if (unicodeUri[count + 2] == '\0' && unicodeUri[count + 3] == '\0')
                {
                    OslMfree(lowercaseUri);
                    return FALSE; /* xxxx@ */
                }
                else
                {
                    break;
                }
            }
            case ',':
            case ';':
            case '<':
            case '>':
            case '[':
            case ']':
            case '"':
            case ')':
            case '(':
                OslMfree(lowercaseUri);
                return FALSE;
            default:
                break;
        }
        count += 2;
    }
    if (foundAt == 1)
    {
        OslMfree(lowercaseUri);
        return TRUE;
    }
    OslMfree(lowercaseUri);
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_validate_uri
 * DESCRIPTION
 *  check if the uri is valid, if having @, then check with mmi_voip_validate_uri
 *  if not, then return TRUE
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  TRUE means uri is valid; FALSE means uri is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_validate_uri(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2chr((S8*) unicodeUri, '@') != NULL)
    {
        return mmi_voip_validate_uri(unicodeUri);
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_validate_ip
 * DESCRIPTION
 *  Validate ip. 0.0.0.0 is not a valid ip.
 * PARAMETERS
 *  ip1     [IN]        First number in the ip format
 *  ip2     [IN]        Second number in the ip format
 *  ip3     [IN]        Third number in the ip format
 *  ip4     [IN]        Fourth number in the ip format
 * RETURNS
 *  TRUE means ip address is valid; FALSE means ip address is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_validate_ip(U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((gui_atoi((UI_string_type) ip1) != 0) ||
        (gui_atoi((UI_string_type) ip2) != 0) ||
        (gui_atoi((UI_string_type) ip3) != 0) || 
        (gui_atoi((UI_string_type) ip4) != 0))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_validate_dtmf
 * DESCRIPTION
 *  Validate dtmf key. Valide dtmf key is defined in VoIPDTMFDigits array.
 * PARAMETERS
 *  dtmfKey     [IN]        
 * RETURNS
 *  TRUE means dtmf key is valid; FALSE means dtmf key is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_validate_dtmf(U16 dtmfKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VOIP_MAX_NUM_DIGITS; i++)
    {
        if (dtmfKey == VoIPDTMFDigits[i])
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_ucm_utility_cbk
 * DESCRIPTION
 *  Validate dtmf key. Valide dtmf key is defined in VoIPDTMFDigits array.
 * PARAMETERS
 *  dtmfKey     [IN]        
 * RETURNS
 *  TRUE means dtmf key is valid; FALSE means dtmf key is invalid.
 *****************************************************************************/
MMI_BOOL mmi_voip_ucm_utility_cbk(srv_ucm_call_type_enum call_type, srv_ucm_int_query_enum query_type, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U8 *unicodeUri = OslMalloc((VOIP_URI_LEN + 1) * ENCODING_LENGTH);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    ASSERT((call_type & SRV_UCM_VOIP_CALL_TYPE) == SRV_UCM_VOIP_CALL_TYPE);

    memset((S8*) unicodeUri, 0x00, (VOIP_URI_LEN + 1) * ENCODING_LENGTH);

    switch(query_type)
    {
        case SRV_UCM_INT_NUMBER:
        {
            srv_ucm_int_query_number_struct* number = (srv_ucm_int_query_number_struct*)ptr;
            mmi_asc_n_to_ucs2(
                (S8*)unicodeUri, 
                (S8*)number->num_uri, 
                VOIP_URI_LEN);

            result = mmi_voip_is_validate_uri(unicodeUri);
            break;
        }
        case SRV_UCM_INT_ECC_NUMBER:
        {
            srv_ucm_int_query_number_struct* number = (srv_ucm_int_query_number_struct*)ptr;
            mmi_asc_n_to_ucs2(
                (S8*)unicodeUri, 
                (S8*)number->num_uri, 
                VOIP_URI_LEN);
            result = mmi_voip_is_sos_number(unicodeUri);
            break;
        }
        case SRV_UCM_INT_DTMF_DIGIT:
        {
            srv_ucm_dtmf_struct* dtmf = (srv_ucm_dtmf_struct*)ptr;
            result = mmi_voip_validate_dtmf(dtmf->digit);
            break;
        }
        case SRV_UCM_INT_CALL_SRV_AVAILABLE:
        {
            result = mmi_voip_is_srv_available();
            break;
        }
        case SRV_UCM_INT_CALL_SRV_TMP_UNAVAILABLE:
        {
            /* temporarily not available should exclude "always unavailable" */
            result = MMI_FALSE;
            break;
        }
        case SRV_UCM_INT_CALLER_RES:
        {
            result = mmi_voip_get_caller_res_info(ptr);
            break;
        }
        default:
        {
            ASSERT(0);
            break;
        }
    };
    OslMfree(unicodeUri);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_parse_uri
 * DESCRIPTION
 *  Make sure the uri has sip: and domain name.
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_parse_uri(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *lowercaseUri = OslMalloc((VOIP_URI_LEN + 1)* ENCODING_LENGTH);
    S32 sipLen = 0, telLen = 0, count = 0;
    S8 foundAt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(lowercaseUri, 0, ((VOIP_URI_LEN + 1) * ENCODING_LENGTH));
    mmi_voip_convert_uri_lower_case(unicodeUri, lowercaseUri, VOIP_URI_LEN * ENCODING_LENGTH);

    sipLen = mmi_ucs2strlen((S8*)sipUri);    /* number of characters */
    telLen = mmi_ucs2strlen((S8*)telUri);    /* number of characters */

    if ((mmi_ucs2ncmp((S8*)lowercaseUri, (S8*)sipUri, sipLen)) && (mmi_ucs2ncmp((S8*)lowercaseUri, (S8*)telUri, telLen)))     /* no prefix sip: and tel: */
    {
        mmi_voip_append_uri_prefix(unicodeUri);
    }
    while (unicodeUri[count] != '\0' || unicodeUri[count + 1] != '\0')
    {
        if (unicodeUri[count] == '@')
        {
            foundAt = 1;
            break;
        }
        count += 2;
    }
    if (foundAt == 0)
    {
        mmi_voip_append_uri_domain(unicodeUri);
    }

    OslMfree(lowercaseUri);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_convert_uri_star_n_pound
 * DESCRIPTION
 *  Convert uri string %23 as # and %2A as *.
 * PARAMETERS
 *  asciiSrc      [IN/OUT]            Source uri string in ascii
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_convert_uri_star_n_pound(U8 *asciiSrc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    U8 *asciiDest = OslMalloc(VOIP_URI_LEN + 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, j = 0; i < (S32)strlen((S8*)asciiSrc); i++)
    {
        if ((asciiSrc[i] == '%') && (asciiSrc[i + 1] == '2') && (asciiSrc[i + 2] == '3'))
        {
            asciiDest[j++] = '#';
            i += 2;
        }
        else if ((asciiSrc[i] == '%') && (asciiSrc[i + 1] == '2') && (asciiSrc[i + 2] == 'A'))
        {
            asciiDest[j++] = '*';
            i += 2;
        }
        else /* normal case */
        {
            asciiDest[j++] = asciiSrc[i];
        }
    }
    memset(asciiSrc, 0, VOIP_URI_LEN);
    strncpy((S8*)asciiSrc, (S8*)asciiDest, VOIP_URI_LEN);
    if(j < VOIP_URI_LEN)
    {
        asciiSrc[j] = 0;
    }
    else
    {
        asciiSrc[VOIP_URI_LEN] = 0;
    }
    OslMfree(asciiDest);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_convert_uri_lower_case
 * DESCRIPTION
 *  Convert uri string to lower case.
 * PARAMETERS
 *  unicodeSrc      [IN]            Source uri string in unicode
 *  unicodeDest     [IN/OUT]        Destination uri string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_convert_uri_lower_case(U8 *unicodeSrc, U8 *unicodeDest, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((unicodeSrc[count] != '\0' || unicodeSrc[count + 1] != '\0') && count <= len)
    {
        if ((unicodeSrc[count] >= 'A') && (unicodeSrc[count] <= 'Z'))
        {
            unicodeDest[count] = unicodeSrc[count] + ('a' - 'A');
        }
        else
        {
            unicodeDest[count] = unicodeSrc[count];
        }
        count += 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_append_uri_prefix
 * DESCRIPTION
 *  Append sip: in front of the uri.
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_append_uri_prefix(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sipLen = 0;
    U8 *noprefixUri = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(noprefixUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_ucs2ncpy((S8*)noprefixUri, (S8*)unicodeUri, VOIP_URI_LEN);
    memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    sipLen = mmi_ucs2strlen((S8*)sipUri);
    mmi_ucs2ncpy((S8*)unicodeUri, (S8*)sipUri, sipLen);
    mmi_ucs2ncpy((S8*)unicodeUri + sipLen * ENCODING_LENGTH, (S8*)noprefixUri, ((VOIP_URI_LEN - 1) - sipLen));
    OslMfree(noprefixUri);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_append_uri_domain
 * DESCRIPTION
 *  Append domain name in back of the uri.
 * PARAMETERS
 *  unicodeUri      [IN]        Uri string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_append_uri_domain(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *unicodeProf = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    S32 profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;
    S8 foundAt = 0;
    S32 count = 0, uriLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(unicodeProf, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_asc_n_to_ucs2(
        (S8*)unicodeProf,
        (S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username,
        VOIP_URI_LEN);
    while (unicodeProf[count] != '\0' || unicodeProf[count + 1] != '\0')
    {
        if (unicodeProf[count] == '@')
        {
            foundAt = 1;
            break;
        }
        count += 2;
    }
    if (foundAt == 1)
    {
        uriLen = mmi_ucs2strlen((S8*)unicodeUri);
        if(uriLen + (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.username)<<1)-(count+1) <= VOIP_URI_LEN)
        {
            mmi_ucs2ncpy(
                (S8*)unicodeUri + uriLen * ENCODING_LENGTH,
                (S8*)unicodeProf + count,
                ((VOIP_URI_LEN - 1) - uriLen));
        }
    }
    OslMfree(unicodeProf);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_reset_rtp_proc
 * DESCRIPTION
 *  Reset rtp_proc info.
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_voip_reset_rtp_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_RESET_RTP_PROC);

    memset(g_voip_cntx_p->rtp_proc_info.close_rtp_list, -1, MMI_VOIP_MAX_NUM_CALL * VOIP_MAX_NUM_DIALOG);
    g_voip_cntx_p->rtp_proc_info.close_rtp_num = 0;

    memset(g_voip_cntx_p->rtp_proc_info.remove_mixer_list, -1, MMI_VOIP_MAX_NUM_CALL);
    g_voip_cntx_p->rtp_proc_info.remove_mixer_num= 0;

    memset(g_voip_cntx_p->rtp_proc_info.rtp_process, 0, MMI_VOIP_MAX_NUM_CALL * VOIP_MAX_NUM_DIALOG);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_reset_call_end_ind_list
 * DESCRIPTION
 *  Reset call_end_ind info.
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_voip_reset_call_end_ind_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_RESET_CALL_END_IND_LIST);

    memset(g_voip_cntx_p->call_list_info.call_end_ind_list, -1, MMI_VOIP_MAX_NUM_CALL * VOIP_MAX_NUM_DIALOG * sizeof(mmi_voip_ucm_uid_struct));
    g_voip_cntx_p->call_list_info.call_end_ind_num = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_add_to_call_list
 * DESCRIPTION
 *  Add specific call to call list.
 * PARAMETERS
 *  fileName            [IN]            Voip cc call list file, path included
 *  callId              [IN]            Call id
 *  dialogId            [IN]            Dialog id
 *  currState           [IN]            Current state, either MMI_VOIP_OUTGOING_STATE or MMI_VOIP_INCOMING_STATE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_add_to_call_list(U16 *fileName, S32 callId, S32 dialogId, mmi_voip_call_state_enum currState)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle = 0;
    U32 fileLen = 0;
    S32 i = 0, result = 0;
    voip_call_struct callList;
    S32 freeTab = g_voip_cntx_p->call_misc_info.currfreeTab;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ADD_TO_CALL_LIST, callId, dialogId, currState);

    fileHandle = FS_Open(fileName, FS_READ_ONLY);
    if (fileHandle < 0)
    {
        MMI_ASSERT(fileHandle >= 0);
    }
    for (i = 0; i <= callId; i++)
    {
        result = FS_Read(fileHandle, &callList, sizeof(voip_call_struct), &fileLen);
        if (result != FS_NO_ERROR)
        {
            MMI_ASSERT(result == FS_NO_ERROR);
        }
    }
    FS_Close(fileHandle);

    if (freeTab != -1)
    {
        g_voip_cntx_p->call_list_info.call_info[freeTab].callId = callId;
        g_voip_cntx_p->call_list_info.call_info[freeTab].currState = currState;
        if (g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_OUTGOING_STATE)
        {
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].callOrigin = MMI_VOIP_MO_ORIGIN;
        }
        else if (g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_INCOMING_STATE)
        {
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].callOrigin = MMI_VOIP_MT_ORIGIN;
        }
        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].dialogId = dialogId;
        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].dialogIdx = callList.dialog[0].dialog_idx;
        memset(
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].appName,
            0,
            (VOIP_DISP_NAME_LEN * sizeof(U16)));
        if (g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_OUTGOING_STATE)
        {
            mmi_voip_get_outgoing_disp_name(
                MMI_VOIP_PHB|MMI_VOIP_HISTORY|MMI_VOIP_SOS, 
                g_voip_cntx_p->call_misc_info.dispUri, /* for display emergency number string */
                (U8*)g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].appName, 
                VOIP_DISP_NAME_LEN);
        }
        memset(
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].dispName,
            0,
            (VOIP_DISP_NAME_LEN * sizeof(U16)));
        mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char*)callList.dialog[dialogId].user_addr.disp_name,
            (char*)g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].dispName,
            (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
        memset(g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].remoteUri, 0, VOIP_URI_LEN);
        memcpy(
            g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].remoteUri,
            callList.dialog[dialogId].user_addr.uri,
            VOIP_URI_LEN);
        mmi_voip_convert_uri_star_n_pound(g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].remoteUri);
        /* copy sdp info */
        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].rtpHandle = -1; /* rtp is not created yet */
        g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].isMixer = FALSE;
        memcpy(
            &g_voip_cntx_p->call_list_info.call_info[freeTab].dialog_info[0].sdp_info,
            &callList.dialog[dialogId].sdp_info,
            sizeof(voip_sdp_struct));
        g_voip_cntx_p->call_list_info.call_info[freeTab].numDialog++;
        g_voip_cntx_p->call_list_info.numTotal++;
        g_voip_cntx_p->call_misc_info.currfreeTab++;
        if (g_voip_cntx_p->call_misc_info.currfreeTab == MMI_VOIP_MAX_NUM_CALL)
        {
            g_voip_cntx_p->call_misc_info.currfreeTab = -1; /* call capacity full */
        }
    }
    else
    {
        MMI_ASSERT(0);  /* no available call entry */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_del_from_call_list
 * DESCRIPTION
 *  Delete specific call from call list.
 * PARAMETERS
 *  callId              [IN]            Call id
 *  dialogId            [IN]            Dialog id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_del_from_call_list(S32 callId, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0, i = 0, j = 0;
    mmi_voip_rtp_proc_struct *rtp_proc = &(g_voip_cntx_p->rtp_proc_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_DEL_FROM_CALL_LIST, callId, dialogId);

    callIndex = mmi_voip_get_call_index(callId);
    if (callIndex != -1)
    {
        dialogIndex = mmi_voip_get_dialog_index(callIndex, dialogId);
        if (dialogIndex == 0)
        {
            g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog--;
            if (g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 0)
            {
                /* reset call info */
                g_voip_cntx_p->call_list_info.numTotal--;
                
                rtp_proc->remove_mixer_list[rtp_proc->remove_mixer_num++] = callIndex;
                if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                {
                    rtp_proc->close_rtp_list[rtp_proc->close_rtp_num++] = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle;
                }
                memset(&g_voip_cntx_p->call_list_info.call_info[callIndex], 0, sizeof(mmi_voip_call_struct));
                g_voip_cntx_p->call_list_info.call_info[callIndex].callId = -1;
                for (i = 0; i < VOIP_MAX_NUM_DIALOG; i++)
                {
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].dialogId = -1;
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].rtpHandle = -1;
                }
                /* if currfreeTab is 0 already, it means the call was not connected but is disconnected now.
                   therefore, no need to decrease currfreeTab */
                if (g_voip_cntx_p->call_misc_info.currfreeTab > 0)
                {
                    g_voip_cntx_p->call_misc_info.currfreeTab--;
                }
                /* when reaching call capacity, currfreeTab is set to -1 already.
                   therefore, currfreeTab has to set to 3 when call entry is available */
                else if (g_voip_cntx_p->call_misc_info.currfreeTab == -1)
                {
                    g_voip_cntx_p->call_misc_info.currfreeTab = MMI_VOIP_MAX_NUM_CALL - 1;
                }
            }
            else    /* g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 1 */
            {
                /* move dialog 1 to dialog 0 */
                rtp_proc->remove_mixer_list[rtp_proc->remove_mixer_num++] = callIndex;
                if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                {
                    rtp_proc->close_rtp_list[rtp_proc->close_rtp_num++] = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle;
                }
                memcpy(
                    &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[0],
                    &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[1],
                    sizeof(mmi_voip_dialog_struct));
                memset(
                    &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[1],
                    0,
                    sizeof(mmi_voip_dialog_struct));
                g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[1].dialogId = -1;
                g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[1].rtpHandle = -1;
            }
        }
        else if (dialogIndex == 1)
        {
            g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog--;
            if (g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 0)
            {
                /* reset call info */
                g_voip_cntx_p->call_list_info.numTotal--;
                rtp_proc->remove_mixer_list[rtp_proc->remove_mixer_num++] = callIndex;
                if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                {
                    rtp_proc->close_rtp_list[rtp_proc->close_rtp_num++] = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle;
                }
                memset(&g_voip_cntx_p->call_list_info.call_info[callIndex], 0, sizeof(mmi_voip_call_struct));
                g_voip_cntx_p->call_list_info.call_info[callIndex].callId = -1;
                for (i = 0; i < VOIP_MAX_NUM_DIALOG; i++)
                {
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].dialogId = -1;
                    g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[i].rtpHandle = -1;
                }
                /* if currfreeTab is 0 already, it means the call was not connected but is disconnected now.
                   therefore, no need to decrease currfreeTab */
                if (g_voip_cntx_p->call_misc_info.currfreeTab > 0)
                {
                    g_voip_cntx_p->call_misc_info.currfreeTab--;
                }
                /* when reaching call capacity, currfreeTab is set to -1 already.
                   therefore, currfreeTab has to set to 3 when call entry is available */
                else if (g_voip_cntx_p->call_misc_info.currfreeTab == -1)
                {
                    g_voip_cntx_p->call_misc_info.currfreeTab = MMI_VOIP_MAX_NUM_CALL - 1;
                }
            }
            else    /* numDialog == 1 */
            {
                /* reset dialog info */
                rtp_proc->remove_mixer_list[rtp_proc->remove_mixer_num++] = callIndex;
                if (g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                {
                    rtp_proc->close_rtp_list[rtp_proc->close_rtp_num++] = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle;
                }
                memset(
                    &g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex],
                    0,
                    sizeof(mmi_voip_dialog_struct));
                g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dialogId = -1;
                g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle = -1;
            }
        }
        /* rearrange call list */
        if (g_voip_cntx_p->call_list_info.call_info[callIndex].numDialog == 0)
        {
            for (i = callIndex; i < (MMI_VOIP_MAX_NUM_CALL - 1); i++)
            {
                memcpy(
                    &g_voip_cntx_p->call_list_info.call_info[i],
                    &g_voip_cntx_p->call_list_info.call_info[i + 1],
                    sizeof(mmi_voip_call_struct));
                memset(&g_voip_cntx_p->call_list_info.call_info[i + 1], 0, sizeof(mmi_voip_call_struct));
                g_voip_cntx_p->call_list_info.call_info[i + 1].callId = -1;
                for (j = 0; j < VOIP_MAX_NUM_DIALOG; j++)
                {
                    g_voip_cntx_p->call_list_info.call_info[i + 1].dialog_info[j].dialogId = -1;
                    g_voip_cntx_p->call_list_info.call_info[i + 1].dialog_info[j].rtpHandle = -1;

                }
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_rtp
 * DESCRIPTION
 *  Update rtp handles and speech on/off according to rtp_proc info.
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_rtp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    mmi_voip_rtp_proc_struct *rtp_proc_info = &(g_voip_cntx_p->rtp_proc_info);
    mmi_voip_call_list_struct *call_list_info = &(g_voip_cntx_p->call_list_info);
    S32 total_call_num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UPDATE_RTP);

    /* SPEECH ON */
    total_call_num = g_voip_cntx_p->call_list_info.numTotal - g_voip_cntx_p->call_list_info.numHeld;
    if(mmi_voip_get_incoming_call_id() != -1)
    {
        total_call_num --;
    }
    if(mmi_voip_get_outgoing_call_id() != -1)
    {
        total_call_num --;
    }

    if((total_call_num > 0) || (mdi_audio_speech_get_app_id() == MDI_AUDIO_SPEECH_APP_ID_NONE))
    {
        mmi_voip_ucm_session_ind(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_TRUE);
        g_voip_cntx_p->call_list_info.inSession = MMI_TRUE;
    }
    total_call_num = 0;
    /* handle rtp */
    /* 1. close rtp */
    mmi_voip_ucm_speech_ind(0, MMI_FALSE, MMI_FALSE);

    for(i = 0; i<rtp_proc_info->remove_mixer_num; i++)
    {
        if(rtp_proc_info->remove_mixer_list[i] != -1)
        {
            mmi_voip_remove_mixer_before_close(rtp_proc_info->remove_mixer_list[i]);
        }
    }
    for(i = 0; i < rtp_proc_info->close_rtp_num; i++)
    {
        if(rtp_proc_info->close_rtp_list[i] != -1)
        {
            mmi_voip_control_rtp(rtp_proc_info->close_rtp_list[i], VOIP_RTP_DIRECTION_INACTIVE);
            mmi_voip_close_rtp(rtp_proc_info->close_rtp_list[i]);
        }
    }
    /* 2. create rtp & update */
    for(i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
    {
        for(j = 0; j < VOIP_MAX_NUM_DIALOG; j++)
        {
            if(rtp_proc_info->rtp_process[i][j] & MMI_VOIP_RTP_PROC_CREATE)
            {
                MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UPDATE_RTP_CREATE_RTP, i, j, rtp_proc_info->rtp_process[i][j]);
                call_list_info->call_info[i].dialog_info[j].rtpHandle = mmi_voip_create_rtp(&(call_list_info->call_info[i].dialog_info[j].sdp_info));
            }
            if(rtp_proc_info->rtp_process[i][j] & MMI_VOIP_RTP_PROC_UPDATE)
            {
                mmi_voip_switch_rtp(MMI_FALSE, call_list_info->call_info[i].callId, call_list_info->call_info[i].dialog_info[j].dialogId);
            }
        }
    }

    for(i = 0; i < MMI_VOIP_MAX_NUM_CALL; i ++)
    {
        for(j = 0; j < VOIP_MAX_NUM_DIALOG; j ++)
        {
            if(g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId != -1 &&
                g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].rtpHandle != -1 &&
                (g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].sdp_info.direction == VOIP_RTP_DIRECTION_SENDRECV||
                g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].sdp_info.direction == VOIP_RTP_DIRECTION_RECVONLY))
            {
                total_call_num ++;
            }
        }
    }

    if(total_call_num)
    {
        mmi_voip_ucm_speech_ind(0, MMI_TRUE, MMI_TRUE);
    }
    else
    {
        mmi_voip_ucm_speech_ind(0, MMI_FALSE, MMI_FALSE);
        //mmi_voip_ucm_session_ind(MDI_AUDIO_SPEECH_APP_ID_VOIP, MMI_FALSE);
        //g_voip_cntx_p->call_list_info.inSession = MMI_FALSE;
    }
    mmi_voip_reset_rtp_proc();
}


static void mmi_voip_add_send_call_end_ind(S32 callId, S16 dialogIdx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ADD_SEND_CALL_END_IND, callId, dialogIdx);

    g_voip_cntx_p->call_list_info.call_end_ind_list[g_voip_cntx_p->call_list_info.call_end_ind_num].callId = callId;
    g_voip_cntx_p->call_list_info.call_end_ind_list[g_voip_cntx_p->call_list_info.call_end_ind_num++].dialogIdx = dialogIdx;
}


static void mmi_voip_send_call_end_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_voip_ucm_uid_struct *uid = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                        */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_SEND_CALL_END_IND, g_voip_cntx_p->call_list_info.call_end_ind_num);

    while(g_voip_cntx_p->call_list_info.call_end_ind_num > 0)
    {
        uid = &(g_voip_cntx_p->call_list_info.call_end_ind_list[i++]);
        mmi_voip_ucm_release_ind(uid->callId, uid->dialogIdx, (U8*)GetString(STR_ID_VOIP_CALL_END), IMG_ID_VOIP_CALL_ENDED, SUCCESS_TONE_IN_CALL);
        g_voip_cntx_p->call_list_info.call_end_ind_num --;
    }
    mmi_voip_reset_call_end_ind_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_call_list
 * DESCRIPTION
 *  Update mmi call list.
 * PARAMETERS
 *  fileName            [IN]            Voip cc call list file, path included
 *  isConf              [IN]            Display popup or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_call_list(U16 *fileName, MMI_BOOL isConf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UPDATE_CALL_LIST, isConf);

    g_voip_cntx_p->call_list_info.numHeld = 0;  /* re-calculate number of held call */
    mmi_voip_update_to_del_call_list(fileName, isConf);
    mmi_voip_update_to_add_call_list(fileName, isConf);
    mmi_voip_send_call_end_ind();
    if((g_voip_cntx_p->call_list_info.processCId == -1) && (g_voip_cntx_p->call_list_info.processDId == -1))
    {
        mmi_voip_update_rtp();
    }
    mmi_voip_switch_session(MMI_VOIP_IDLE_STATE);
    FS_Delete(fileName);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_to_del_call_list
 * DESCRIPTION
 *  First pass of updating call list from voip cc to mmi.
 *  Delete mmi call list entry that voip cc call list does not have.
 * PARAMETERS
 *  fileName            [IN]            Voip cc call list file, path included
 *  isConf              [IN]            Display popup or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_to_del_call_list(U16 *fileName, MMI_BOOL isConf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle = 0;
    U32 fileLen = 0;
    S32 result = 0;
    voip_call_struct callList;
    S32 i = 0, j = 0, m = 0, n = 0, callId = 0, dialogId = 0;
    MYTIME currTime, duration;
    U8 popupStr[MAX_SUB_MENU_SIZE];
    MMI_BOOL send_release_ind = MMI_FALSE;
    mmi_voip_rtp_proc_struct *rtp_proc = &(g_voip_cntx_p->rtp_proc_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UPDATE_TO_DEL_CALL_LIST, isConf);

    while (i < MMI_VOIP_MAX_NUM_CALL)
    {
        callId = g_voip_cntx_p->call_list_info.call_info[i].callId;
        if (callId != -1)
        {
            fileHandle = FS_Open(fileName, FS_READ_ONLY);
            if (fileHandle < 0)
            {
                MMI_ASSERT(fileHandle >= 0);
            }

            for (j = 0; j < g_voip_cntx_p->call_list_info.maxnumCall; j++)
            {
                result = FS_Read(fileHandle, &callList, sizeof(voip_call_struct), &fileLen);
                if (result != FS_NO_ERROR)
                {
                    MMI_ASSERT(result == FS_NO_ERROR);
                }

                if(callList.call_id == callId && callList.is_bk_call == TRUE)
                {
                    send_release_ind = MMI_TRUE;
                }
                if ((callList.is_bk_call == FALSE) && (callList.call_state != VOIP_CALL_STATE_TERMINATED) &&
                    (callList.call_id == callId))
                {
                    while (m < VOIP_MAX_NUM_DIALOG)
                    {
                        dialogId = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dialogId;
                        if (dialogId != -1)
                        {
                            for (n = 0; n < VOIP_MAX_NUM_DIALOG; n++)
                            {
                                if ((callList.dialog[n].in_use == TRUE) && (callList.dialog[n].dialog_id == dialogId))
                                {
                                    /* update call info */
                                    g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dialogIdx = callList.dialog[n].dialog_idx;
                                    g_voip_cntx_p->call_list_info.call_info[i].currState = mmi_voip_get_call_state_enum(callList.dialog[n].dialog_state);
                                    if(g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_ACTIVE_STATE )
                                    {
                                        g_voip_cntx_p->call_misc_info.currhiliteTab = i;
                                    }
                                    if ((g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLD_STATE) && (m == 0))      /* only update held call count according to the first dialog */
                                    {
                                        g_voip_cntx_p->call_list_info.numHeld++;
                                    }
                                    else if (g_voip_cntx_p->call_list_info.call_info[i].currState ==
                                             MMI_VOIP_OUTGOING_STATE)
                                    {
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].callOrigin =
                                            MMI_VOIP_MO_ORIGIN;
                                    }
                                    else if (g_voip_cntx_p->call_list_info.call_info[i].currState ==
                                             MMI_VOIP_INCOMING_STATE)
                                    {
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].callOrigin =
                                            MMI_VOIP_MT_ORIGIN;
                                    }
                                    /* outgoing call or incoming call doesn't have the info of sdp yet */
                                    if ((g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_ACTIVE_STATE) || 
                                        (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLD_STATE) ||
                                        (g_voip_cntx_p->call_list_info.call_info[i].currState == MMI_VOIP_HOLDING_STATE))
                                    {
                                        if (g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle == -1)
                                        {
                                            rtp_proc->rtp_process[i][m] |= MMI_VOIP_RTP_PROC_CREATE;
                                        }
                                        else if (mmi_voip_is_addr_change
                                                 (&g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].sdp_info,
                                                  &callList.dialog[n].sdp_info))
                                        {
                                            rtp_proc->remove_mixer_list[rtp_proc->remove_mixer_num++] = i;
                                            rtp_proc->close_rtp_list[rtp_proc->close_rtp_num++] = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].rtpHandle;
                                            rtp_proc->rtp_process[i][m] |= MMI_VOIP_RTP_PROC_CREATE;
                                        }
                                        memcpy(
                                            &g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].sdp_info,
                                            &callList.dialog[n].sdp_info,
                                            sizeof(voip_sdp_struct));
                                        //mmi_voip_switch_rtp(FALSE, callId, dialogId);
                                        rtp_proc->rtp_process[i][m] |= MMI_VOIP_RTP_PROC_UPDATE;
                                        if (!mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].startTime))
                                        {
                                            DTGetRTCTime(&currTime);
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].startTime = currTime;
                                        }
                                    }
                                    memset(
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dispName,
                                        0,
                                        (VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    mmi_chset_convert(
                                        MMI_CHSET_UTF8,
                                        MMI_CHSET_UCS2,
                                        (char*)callList.dialog[n].user_addr.disp_name,
                                        (char*)g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dispName,
                                        (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    /* it could be a transfer case if uri changes, need to update appName */
                                    if (strncmp(
                                        (S8*)g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri, 
                                        (S8*)callList.dialog[n].user_addr.uri, 
                                        VOIP_URI_LEN))
                                    {
                                        memset(
                                            g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].appName, 
                                            0, 
                                            (VOIP_DISP_NAME_LEN * sizeof(U16)));
                                    }
                                    memset(
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri,
                                        0,
                                        VOIP_URI_LEN);
                                    memcpy(
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri,
                                        callList.dialog[n].user_addr.uri,
                                        VOIP_URI_LEN);
                                    mmi_voip_convert_uri_star_n_pound(g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].remoteUri);
                                    break;
                                }
                            }
                            m++;
                            if (n == VOIP_MAX_NUM_DIALOG)   /* delete dialog entry */
                            {
                                if (mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].startTime))
                                {
                                    memset(&duration, 0, sizeof(MYTIME));
                                    mmi_voip_log_call_end_time(callId, dialogId, &duration);
                                }
                                if (isConf == TRUE)
                                {
                                    /* store actual call origin and actual start time for merge call or split call */
                                    g_voip_cntx_p->call_misc_info.actualOrigin =
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].callOrigin;
                                    g_voip_cntx_p->call_misc_info.actualTime =
                                        g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m - 1].startTime;
                                }
                                else    /* isConf == FALSE */
                                {
                                    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_VOIP_TRC_GRP, "\n[mmi_voip_update_to_del_call_list] It is possible\n");
                                }
                                mmi_voip_del_from_call_list(callId, dialogId);
                                m--;
                            }
                        }
                        else    /* dialogId == -1, break the loop because mmi call list is sorted */
                        {
                            break;
                        }
                    }
                    m = 0;  /* reset m to check next call id's dialog */
                    break;
                }
            }
            i++;
            if (j == g_voip_cntx_p->call_list_info.maxnumCall)  /* delete call entry */
            {
                S32 dialogIdx = g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].dialogIdx;
                /* dialogId is invalid at the moment, so get the first dialog id to show call end popup */
                dialogId = g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].dialogId;
                if (mmi_dt_is_valid(&g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].startTime))
                {
                    memset(&duration, 0, sizeof(MYTIME));
                    mmi_voip_log_call_end_time(callId, dialogId, &duration);
                    //memset(popupStr, 0, MAX_SUB_MENU_SIZE);
                    //mmi_voip_get_call_end_string(&duration, popupStr);
                }
                else    /* outgoing call or incoming call */
                {
                    memset(popupStr, 0, MAX_SUB_MENU_SIZE);
                    mmi_ucs2cpy((S8*)popupStr, GetString(STR_ID_VOIP_CALL_END));
                    MMI_ASSERT(popupStr[MAX_SUB_MENU_SIZE - 2] == '\0' && popupStr[MAX_SUB_MENU_SIZE - 1] == '\0');
                }

                if (isConf == TRUE)
                {
                    /* store actual call origin and actual start time for merge call or split call */
                    g_voip_cntx_p->call_misc_info.actualOrigin =
                        g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].callOrigin;
                    g_voip_cntx_p->call_misc_info.actualTime =
                        g_voip_cntx_p->call_list_info.call_info[i - 1].dialog_info[m].startTime;
                }
                else    /* isConf == FALSE */
                {
                    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_VOIP_TRC_GRP, "\n[mmi_voip_update_to_del_call_list] It is possible\n");
                }
                mmi_voip_del_from_call_list(callId, dialogId);
                if(send_release_ind)
                {
                    mmi_voip_add_send_call_end_ind(callId, dialogIdx);
                }
                i--;
            }
            FS_Close(fileHandle);
        }
        else    /* callId == -1, break the loop because mmi call list is sorted */
        {
            break;
        }
    }
    i = 0;  /* reset i */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_add_dialog
 * DESCRIPTION
 *  Add voip dialog
 * PARAMETERS
 *  callList            [IN]            call list
 *  dialogId            [IN]            Id of the dialog to be added
 *  call_info           [IN]            call info
 *  isConf              [IN]            is in conference
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_voip_add_dialog(voip_call_struct *callList, S32 callId, S32 dialogId, MMI_BOOL isConf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime;
    S32 m = 0;
    mmi_voip_rtp_proc_struct *rtp_proc = &(g_voip_cntx_p->rtp_proc_info);
    mmi_voip_call_struct *call_info = &(g_voip_cntx_p->call_list_info.call_info[callId]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_ADD_DIALOG, callId, dialogId, isConf);

    for (m = 0; m < VOIP_MAX_NUM_DIALOG; m++)
    {
        if (call_info->dialog_info[m].dialogId == -1)
        {
            call_info->numDialog++;
            call_info->dialog_info[m].dialogId =
                callList->dialog[dialogId].dialog_id;
            call_info->dialog_info[m].dialogIdx = 
                callList->dialog[dialogId].dialog_idx;
            if(call_info->currState == MMI_VOIP_ACTIVE_STATE )
            {
                g_voip_cntx_p->call_misc_info.currhiliteTab = m;
            }
            if ((call_info->currState == MMI_VOIP_ACTIVE_STATE) ||
                (call_info->currState == MMI_VOIP_HOLD_STATE))
            {
                if (call_info->dialog_info[m].rtpHandle == -1)
                {
                    rtp_proc->rtp_process[callId][m] |= MMI_VOIP_RTP_PROC_CREATE;
                }
                memcpy(
                    &call_info->dialog_info[m].sdp_info,
                    &callList->dialog[dialogId].sdp_info,
                    sizeof(voip_sdp_struct));
                rtp_proc->rtp_process[callId][m] |= MMI_VOIP_RTP_PROC_UPDATE;
                if (!mmi_dt_is_valid(&call_info->dialog_info[m].startTime))
                {
                    DTGetRTCTime(&currTime);
                    call_info->dialog_info[m].startTime = currTime;
                }
            }
            memset(
                call_info->dialog_info[m].dispName,
                0,
                (VOIP_DISP_NAME_LEN * sizeof(U16)));
            mmi_chset_convert(
                MMI_CHSET_UTF8,
                MMI_CHSET_UCS2,
                (char*)callList->dialog[dialogId].user_addr.disp_name,
                (char*)call_info->dialog_info[m].dispName,
                (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
            /* it could be a transfer case if uri changes, need to update appName */
            if (strncmp(
                (S8*)call_info->dialog_info[m].remoteUri, 
                (S8*)callList->dialog[dialogId].user_addr.uri, 
                VOIP_URI_LEN))
            {
                memset(
                    call_info->dialog_info[m].appName, 
                    0, 
                    (VOIP_DISP_NAME_LEN * sizeof(U16)));
            }
            memset(
                call_info->dialog_info[m].remoteUri,
                0,
                VOIP_URI_LEN);
            memcpy(
                call_info->dialog_info[m].remoteUri,
                callList->dialog[dialogId].user_addr.uri,
                VOIP_URI_LEN);
            mmi_voip_convert_uri_star_n_pound(call_info->dialog_info[m].remoteUri);
            if (isConf == TRUE)
            {
                /* update mixer's information for the other dialog */
                rtp_proc->rtp_process[callId][m] |= MMI_VOIP_RTP_PROC_UPDATE;
                call_info->dialog_info[m].callOrigin =
                    g_voip_cntx_p->call_misc_info.actualOrigin;
                g_voip_cntx_p->call_misc_info.actualOrigin = MMI_VOIP_NONE_ORIGIN;
                call_info->dialog_info[m].startTime =
                    g_voip_cntx_p->call_misc_info.actualTime;
                memset(&g_voip_cntx_p->call_misc_info.actualTime, 0, sizeof(MYTIME));
            }
            //break;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_update_to_add_call_list
 * DESCRIPTION
 *  Second pass of updating call list from voip cc to mmi.
 *  Add mmi call list entry that mmi call list does not have.
 * PARAMETERS
 *  fileName            [IN]            Voip cc call list file, path included
 *  isConf              [IN]            Display popup or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_update_to_add_call_list(U16 *fileName, MMI_BOOL isConf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fileHandle = 0;
    U32 fileLen = 0;
    S32 result = 0;
    voip_call_struct callList;
    S32 i = 0, j = 0, m = 0, n = 0, callId = 0, dialogId = 0, freeTab = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_UPDATE_TO_ADD_CALL_LIST, isConf);

    fileHandle = FS_Open(fileName, FS_READ_ONLY);
    if (fileHandle < 0)
    {
        MMI_ASSERT(fileHandle >= 0);
    }

    for (j = 0; j < g_voip_cntx_p->call_list_info.maxnumCall; j++)
    {
        result = FS_Read(fileHandle, &callList, sizeof(voip_call_struct), &fileLen);
        if (result != FS_NO_ERROR)
        {
            MMI_ASSERT(result == FS_NO_ERROR);
        }

        if ((callList.is_bk_call == FALSE) && 
            (callList.call_state != VOIP_CALL_STATE_TERMINATED) &&
            (callList.call_id != g_voip_cntx_p->call_list_info.bkrejCId) ) /* for race condition */
        {
            for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
            {
                callId = g_voip_cntx_p->call_list_info.call_info[i].callId;
                if (callList.call_id == callId)
                {
                    for (n = 0; n < VOIP_MAX_NUM_DIALOG; n++)
                    {
                        if (callList.dialog[n].in_use == TRUE)
                        {
                            for (m = 0; m < VOIP_MAX_NUM_DIALOG; m++)
                            {
                                dialogId = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[m].dialogId;
                                if (callList.dialog[n].dialog_id == dialogId)
                                {
                                    break;
                                }
                            }
                            if (m == VOIP_MAX_NUM_DIALOG)   /* add dialog entry */
                            {
                                if(mmi_voip_add_dialog(
                                                        &callList,
                                                        i,
                                                        n,
                                                        isConf) == MMI_TRUE)
                                {
                                    break;
                                }
                                else
                                {
                                    MMI_ASSERT(0);  /* no available dialog entry */
                                }
                            }
                        }
                    }
                    break;
                }
            }
            if (i == MMI_VOIP_MAX_NUM_CALL) /* add call entry */
            {
                freeTab = g_voip_cntx_p->call_misc_info.currfreeTab;
                if (freeTab != -1)
                {
                    for (n = 0; n < VOIP_MAX_NUM_DIALOG; n++)
                    {
                        if (callList.dialog[n].in_use == TRUE)
                        {
                            g_voip_cntx_p->call_list_info.call_info[freeTab].callId = callList.call_id;
                            g_voip_cntx_p->call_list_info.call_info[freeTab].currState = mmi_voip_get_call_state_enum(callList.dialog[n].dialog_state);
                                if ((g_voip_cntx_p->call_list_info.call_info[freeTab].currState == MMI_VOIP_HOLD_STATE) && (m == 0))    /* only update held call count according to the first dialog */
                                {
                                    g_voip_cntx_p->call_list_info.numHeld++;
                                }
                            g_voip_cntx_p->call_list_info.numTotal++;
                            if(!mmi_voip_add_dialog(
                                                    &callList,
                                                    freeTab,
                                                    n,
                                                    isConf) == MMI_TRUE)
                            {
                                MMI_ASSERT(0);  /* no available dialog entry */
                            }
                            g_voip_cntx_p->call_misc_info.currfreeTab++;
                            if (g_voip_cntx_p->call_misc_info.currfreeTab == MMI_VOIP_MAX_NUM_CALL)
                            {
                                g_voip_cntx_p->call_misc_info.currfreeTab = -1; /* call capacity full */
                            }
                        }
                    }
                }
                else
                {
                    /* do not assert in case four calls + one will-be-bk-reject call */
                    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_VOIP_TRC_GRP, "\n[mmi_voip_update_to_add_call_list] No Available Call Entry, Ignore and Wait to Background Reject\n");
                }
            }
        }
    }
    FS_Close(fileHandle);
}

S16 mmi_voip_get_actual_dialog_id(S16 ucm_call_info_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i ++)
    {
        for (j = 0; j < VOIP_MAX_NUM_DIALOG; j ++)
        {
            if(g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogIdx == ucm_call_info_id)
            {
                return g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId;
            }
        }
    }
    return -1;
}

S16 mmi_voip_get_dialog_idx(S32 call_id, S32 dialog_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i ++)
    {
        if(g_voip_cntx_p->call_list_info.call_info[i].callId == call_id)
        {
            for (j = 0; j < VOIP_MAX_NUM_DIALOG; j ++)
            {
                if(g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId == dialog_id)
                {
                    return g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogIdx;
                }
            }
        }
    }
    return -1;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_summary_string
 * DESCRIPTION
 *  Prepare current status display string.
 * PARAMETERS
 *  unicodeStr          [IN/OUT]            Current status string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_summary_string(U8 *unicodeStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 profIndex = 0;
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    S8 *colon = (S8*)GetString(STR_ID_VOIP_FULL_SHAPE_COLON);
    S8 *slash = (S8*)GetString(STR_ID_VOIP_FULL_SHAPE_SLASH);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Login/Logout: */
    mmi_ucs2cpy((S8*)unicodeStr, GetString(STR_GLOBAL_LOGIN));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)slash);
    mmi_ucs2cat((S8*)unicodeStr, GetString(STR_GLOBAL_LOGOUT));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
    mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    
    profIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;
    if (profIndex != -1)
    {
        if (g_voip_cntx_p->reg_state_info == MMI_VOIP_REG_STATE)
        {
            mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_REGISTER));
            mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
            mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        }
        else
        {
            mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_NOT_REGISTER));
            mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
            mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        }
        
        mmi_voip_update_prof_common_cache_to_disp(profIndex);
        /* Profile Name: */
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_COMMON_PROFNAME));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.profileName);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);

        mmi_voip_update_prof_acct_cache_to_disp(profIndex);
        /* SIP Server/SIP Port: */
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_ACCOUNT_SIPSERVER));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)slash);
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_ACCOUNT_SIPPORT));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.portNumber);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);

        /* Username: */
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_GLOBAL_USERNAME));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);

        /* Display Name: */
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_PROF_ACCOUNT_DISPNAME));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)colon);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.displayName);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    }
    else
    {
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_NO_ACTIVATED_PROFILE));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    }    
    
    MMI_ASSERT(unicodeStr[MAX_SUB_MENUS * MAX_SUB_MENU_SIZE - 1] == '\0');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_call_state_enum
 * DESCRIPTION
 *  Map voip cc dialog state to mmi call state.
 * PARAMETERS
 *  state           [IN]            Voip cc dialog state
 * RETURNS
 *  MMI call state.
 *****************************************************************************/
mmi_voip_call_state_enum mmi_voip_get_call_state_enum(voip_dlg_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case VOIP_DLG_STATE_TERMINATED:
            return MMI_VOIP_IDLE_STATE;
        case VOIP_DLG_STATE_WAIT_NAT:
        case VOIP_DLG_STATE_MO:
            return MMI_VOIP_OUTGOING_STATE;
        case VOIP_DLG_STATE_MT:
            return MMI_VOIP_INCOMING_STATE;
        case VOIP_DLG_STATE_WAIT_ACK: /* accept call complete before remote ack */
        case VOIP_DLG_STATE_ACTIVE:
            return MMI_VOIP_ACTIVE_STATE;
        case VOIP_DLG_STATE_HOLD:
            return MMI_VOIP_HOLD_STATE;
        case VOIP_DLG_STATE_TRANSFERING:
        case VOIP_DLG_STATE_TRANSFEREE:
            return MMI_VOIP_TRANSFER_STATE;
        case VOIP_DLG_STATE_TERMINATING:
            return MMI_VOIP_DISCONNECTING_STATE;
        case VOIP_DLG_STATE_HOLDING:
            return MMI_VOIP_HOLDING_STATE;
        case VOIP_DLG_STATE_UNHOLDING:
            return MMI_VOIP_HOLD_STATE;
        default:
            MMI_EXT_ASSERT(0, state, 0, 0);
            return MMI_VOIP_CALL_STATE_TOTAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_call_end_string
 * DESCRIPTION
 *  Append string "Call End" in front of call duration.
 * PARAMETERS
 *  duration            [IN]            Duration of the call
 *  unicodeStr          [IN/OUT]        Call end string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_call_end_string(MYTIME *duration, U8 *unicodeStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    U8 *timeStr = OslMalloc(32);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) unicodeStr, GetString(STR_ID_VOIP_CALL_END));
    mmi_ucs2cat((S8*) unicodeStr, (S8*) newline);
    duration_string(duration, (UI_string_type) timeStr, DT_ACTIVE_CALL_SCREEN);
    mmi_ucs2cat((S8*) unicodeStr, (S8*) timeStr);

    OslMfree(timeStr);

    MMI_ASSERT(unicodeStr[MAX_SUB_MENU_SIZE - 2] == '\0' && unicodeStr[MAX_SUB_MENU_SIZE - 1] == '\0');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_dtmf_keycode_enum
 * DESCRIPTION
 *  Map mmi dtmf key to rtp dtmf key.
 * PARAMETERS
 *  keyCode         [IN]            Mmi dtmf key
 * RETURNS
 *  RTP dtmf key.
 *****************************************************************************/
rtp_dtmf_code_enum mmi_voip_get_dtmf_keycode_enum(U16 *keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (*keyCode)
    {
        case KEY_0:
            return RTP_DTMF_CODE_0;
        case KEY_1:
            return RTP_DTMF_CODE_1;
        case KEY_2:
            return RTP_DTMF_CODE_2;
        case KEY_3:
            return RTP_DTMF_CODE_3;
        case KEY_4:
            return RTP_DTMF_CODE_4;
        case KEY_5:
            return RTP_DTMF_CODE_5;
        case KEY_6:
            return RTP_DTMF_CODE_6;
        case KEY_7:
            return RTP_DTMF_CODE_7;
        case KEY_8:
            return RTP_DTMF_CODE_8;
        case KEY_9:
            return RTP_DTMF_CODE_9;
        case KEY_STAR:
            return RTP_DTMF_CODE_STAR;
        case KEY_POUND:
            return RTP_DTMF_CODE_HASH;
        default:
            return RTP_DTMF_CODE_TOTAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_error_cause
 * DESCRIPTION
 *  Map voip cc error cause to mmi error string.
 * PARAMETERS
 *  result          [IN]            Major result
 *  cause           [IN]            Minor cause
 * RETURNS
 *  String id of the error.
 *****************************************************************************/
U16 mmi_voip_get_error_cause(U8 result, S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case VOIP_ERROR:        /* failure happens in VoIP task */
        case VOIP_SIP_ERROR:    /* failure happens in SIP task */
        case VOIP_NAT_ERROR:    /* NAT related error */
            return mmi_voip_get_error_string(cause);
        case VOIP_FS_ERROR:     /* file system related error */
            return srv_fmgr_fs_error_get_string(cause);
        default:
            return STR_ID_VOIP_UNKNOWN_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_error_string
 * DESCRIPTION
 *  Look up error table to get corresponding error string.
 * PARAMETERS
 *  cause           [IN]            Error cause
 * RETURNS
 *  String id of the error.
 *****************************************************************************/
U16 mmi_voip_get_error_string(S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, totalEntry = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totalEntry = sizeof(g_voip_error_table) / sizeof(mmi_voip_error_string_struct);

    for (i = 0; i < totalEntry; i++)
    {
        if (g_voip_error_table[i].errorNo == cause)
        {
            return g_voip_error_table[i].errorStr;
        }
    }
    return STR_ID_VOIP_UNKNOWN_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_set_outgoing_origin_app
 * DESCRIPTION
 *  Put phonebook or call history structure to g_voip_cntx_p->call_originapp_info.
 * PARAMETERS
 *  moOrigin        [IN]            Outgoing call origin, either MMI_VOIP_PHB or MMI_VOIP_HISTORY
 * RETURNS
 *  TRUE means outgoing call does dial from phonebook or call history; 
 *  FALSE means outgoing call neither dial from phonebook nor call history.
 *****************************************************************************/
MMI_BOOL mmi_voip_set_outgoing_origin_app(mmi_voip_mo_origin_enum moOrigin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_caller_info_struct* pb_data = NULL;
    srv_phb_cm_number_struct req_info;
    S32 uriLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (moOrigin == MMI_VOIP_PHB || moOrigin == MMI_VOIP_HISTORY)
    {
        srv_phb_caller_info_struct* pb_data = OslMalloc(sizeof(srv_phb_caller_info_struct));

        memset((U8*)&req_info, 0x00, sizeof(srv_phb_cm_number_struct));
        memset((U8*)pb_data, 0x00, sizeof(srv_phb_caller_info_struct));

        req_info.number = (U16*)&(g_voip_cntx_p->call_misc_info.dispUri);
        req_info.user_data = g_voip_ucm_user_data;
        req_info.is_mo_call = MMI_TRUE;      /* make mo call set MMI_TRUE, else set MMI_FALSE */
        req_info.is_voip_call = MMI_TRUE;   /* make voip call set MMI_TRUE, else set MMI_FALSE */

        srv_phb_get_caller_info_by_number(&req_info, pb_data);
        //MMI_PRINT(MOD_MMI_COMMON_APP, MMI_VOIP_TRC_GRP,"[VoIP] mmi_voip_set_outgoing_origin_app(), pb_name:%s", pb_data->name);

        memset(&g_voip_cntx_p->call_originapp_info, 0, sizeof(mmi_voip_call_originapp_struct));
        g_voip_cntx_p->call_originapp_info.moOrgin = moOrigin;
        uriLen = (VOIP_DISP_NAME_LEN > mmi_ucs2strlen((S8*)pb_data->name)) ?
            (mmi_ucs2strlen((S8*)pb_data->name)) : (VOIP_DISP_NAME_LEN - 1);
        mmi_ucs2ncpy((S8*)g_voip_cntx_p->call_originapp_info.dispName, (S8*)pb_data->name, uriLen);
        mmi_ucs2ncpy((S8*)g_voip_cntx_p->call_originapp_info.remoteUri, (S8*)g_voip_cntx_p->call_misc_info.dispUri, VOIP_URI_LEN - 1);
        OslMfree(pb_data);
        return MMI_TRUE;
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_outgoing_disp_name
 * DESCRIPTION
 *  Determine to show display name or not for outgoing call.
 * PARAMETERS
 *  moOrigin        [IN]            Outgoing call origin
 *  unicodeSrc      [IN]            Source uri string in unicode
 *  unicodeDest     [IN/OUT]        Destination uri string in unicode
 *  destLen         [IN]            Destination uri string length
 * RETURNS
 *  TRUE means outgoing call should show display name; 
 *  FALSE means outgoing call should not show display name.
 *****************************************************************************/
MMI_BOOL mmi_voip_get_outgoing_disp_name(U8 moOrigin, U8* unicodeSrc, U8* unicodeDest, U8 destLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 uriLen = 0;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!mmi_ucs2cmp((S8*)unicodeSrc, (S8*)sos112)) || 
        (!mmi_ucs2cmp((S8*)unicodeSrc, (S8*)sos911)) ||
        (!mmi_ucs2cmp((S8*)unicodeSrc, (S8*)GetString(STR_ID_VOIP_EMERGENCY_NUM))))
    {
        uriLen = (destLen > mmi_ucs2strlen((S8*)GetString(STR_ID_VOIP_EMERGENCY_NUM))) ? 
            (mmi_ucs2strlen((S8*)GetString(STR_ID_VOIP_EMERGENCY_NUM))) : (destLen - 1);
            
        memset(unicodeDest, 0, (destLen * ENCODING_LENGTH));
        mmi_ucs2ncpy((S8*)unicodeDest, (S8*)GetString(STR_ID_VOIP_EMERGENCY_NUM), uriLen);
        ret = MMI_TRUE;
    }

    if (ret == MMI_TRUE)
    {
        return ret;
    }

    if ((moOrigin & MMI_VOIP_HISTORY) == MMI_VOIP_HISTORY)
    {
        /* ensure the name from call history is not empty */
        if ((g_voip_cntx_p->call_originapp_info.moOrgin == MMI_VOIP_HISTORY) && 
            (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_originapp_info.dispName)))
        {
            uriLen = (destLen >= VOIP_DISP_NAME_LEN) ? (VOIP_DISP_NAME_LEN) : (destLen - 1);

            memset(unicodeDest, 0, (destLen * ENCODING_LENGTH));
            mmi_ucs2ncpy((S8*)unicodeDest, (S8*)g_voip_cntx_p->call_originapp_info.dispName, uriLen);
            ret = MMI_TRUE;
        }
    }
    if ((moOrigin & MMI_VOIP_PHB) == MMI_VOIP_PHB)
    {        
        /* ensure the name from phonebook is not empty */
        if ((g_voip_cntx_p->call_originapp_info.moOrgin == MMI_VOIP_PHB) && 
            (mmi_ucs2strlen((S8*)g_voip_cntx_p->call_originapp_info.dispName)))
        {
            uriLen = (destLen >= VOIP_DISP_NAME_LEN) ? (VOIP_DISP_NAME_LEN) : (destLen - 1);

            memset(unicodeDest, 0, (destLen * ENCODING_LENGTH));
            mmi_ucs2ncpy((S8*)unicodeDest, (S8*)g_voip_cntx_p->call_originapp_info.dispName, uriLen);
            ret = MMI_TRUE;
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_redial_string
 * DESCRIPTION
 *  Prepare redial display string.
 * PARAMETERS
 *  unicodeStr          [IN/OUT]            Redial string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_redial_string(U8 *unicodeStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    U8 *asciinumStr = OslMalloc(16);
    U8 *unicodenumStr = OslMalloc(32);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(asciinumStr, 0, 16);
    sprintf((S8*)asciinumStr, "%d / %d", (g_voip_cntx_p->call_redial_info.currAttempt + 1), g_voip_cntx_p->call_redial_info.maxAttempt);
    memset(unicodenumStr, 0, 32);
    mmi_asc_to_ucs2((S8*)unicodenumStr, (S8*)asciinumStr);
    mmi_ucs2cpy((S8*)unicodeStr, (S8*)unicodenumStr);
    mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_TIME_UNIT));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    
    OslMfree(asciinumStr);
    OslMfree(unicodenumStr);

    MMI_ASSERT(unicodeStr[MMI_VOIP_MAX_STRING_LEN - 1] == '\0');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_mwi_state_enum
 * DESCRIPTION
 *  Map voip cc message waiting type to mmi message waiting string.
 * PARAMETERS
 *  state           [IN]            Message waiting type
 * RETURNS
 *  String id of message waiting.
 *****************************************************************************/
U16 mmi_voip_get_mwi_state_enum(voip_mwi_type_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case VOIP_MWI_VOICE:
            return STR_ID_VOIP_VOICE_MESSAGE;
        case VOIP_MWI_FAX:
            return STR_ID_VOIP_FAX_MESSAGE;
        case VOIP_MWI_PAGER:
            return STR_ID_VOIP_PAGER_MESSAGE;
        case VOIP_MWI_MM:
            return STR_ID_VOIP_MULTIMEDIA_MESSAGE;
        case VOIP_MWI_TEXT:
            return STR_ID_VOIP_TEXT_MESSAGE;
        default:
            return STR_ID_VOIP_UNKNOWN_MESSAGE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_mwi_string
 * DESCRIPTION
 *  Prepare message waiting display string.
 * PARAMETERS
 *  unicodeStr          [IN/OUT]            Message waiting string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_mwi_string(U8 *unicodeStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    U8 *asciinumStr = OslMalloc(16);
    U8 *unicodenumStr = OslMalloc(32);
    U32 newMsg = 0, totalMsg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*)unicodeStr, GetString(STR_ID_VOIP_NEW_MESSAGE));
    mmi_ucs2cat((S8*)unicodeStr, (S8*) newline);
    newMsg = g_voip_cntx_p->msg_waiting_info.mwiMsg.newmsgs;
    totalMsg = g_voip_cntx_p->msg_waiting_info.mwiMsg.newmsgs + g_voip_cntx_p->msg_waiting_info.mwiMsg.oldmsgs;
    memset(asciinumStr, 0, 16);
    sprintf((S8*)asciinumStr, "%d / %d", newMsg, totalMsg);
    memset(unicodenumStr, 0, 32);
    mmi_asc_to_ucs2((S8*)unicodenumStr, (S8*)asciinumStr);
    mmi_ucs2cat((S8*)unicodeStr, (S8*)unicodenumStr);
    mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_MSG_UNIT));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);

    mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_URGENT_MESSAGE));
    mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    if (g_voip_cntx_p->msg_waiting_info.mwiMsg.is_urgent_present == TRUE)
    {
        newMsg = g_voip_cntx_p->msg_waiting_info.mwiMsg.new_urgentmsgs;
        totalMsg =
            g_voip_cntx_p->msg_waiting_info.mwiMsg.new_urgentmsgs +
            g_voip_cntx_p->msg_waiting_info.mwiMsg.old_urgentmsgs;
        memset(asciinumStr, 0, 16);
        sprintf((S8*)asciinumStr, "%d / %d", newMsg, totalMsg);
        memset(unicodenumStr, 0, 32);
        mmi_asc_to_ucs2((S8*)unicodenumStr, (S8*)asciinumStr);
        mmi_ucs2cat((S8*)unicodeStr, (S8*)unicodenumStr);
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_MSG_UNIT));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    }
    else
    {
        mmi_ucs2cat((S8*)unicodeStr, GetString(STR_ID_VOIP_NOT_SUPPORT));
        mmi_ucs2cat((S8*)unicodeStr, (S8*)newline);
    }
    
    OslMfree(asciinumStr);
    OslMfree(unicodenumStr);
    
    MMI_ASSERT(unicodeStr[MMI_VOIP_MAX_STRING_LEN - 1] == '\0');
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_idle_state
 * DESCRIPTION
 *  Check if it is in the idle screen or screen saver.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means it is in idle screen or screen saver;
 *  FALSE means it is not in idle screen or screen saver.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_idle_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_idle_context.IsOnIdleScreen || g_idle_context.ScreenSaverRunFlag)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_keypad_lock_state
 * DESCRIPTION
 *  Check if keypad is locked.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means it is in keypad lock; FALSE means it is not in keypad lock.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_keypad_lock_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_keylock_context.gKeyPadLockFlag)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_empty_profile
 * DESCRIPTION
 *  Check if the specific profile is empty.
 * PARAMETERS
 *  profIndex       [IN]        Index of intended to check profile
 * RETURNS
 *  TRUE means the specific profile is empty;
 *  FALSE means the specific profile is not empty.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_empty_profile(S32 profIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_voip_update_prof_common_cache_to_disp(profIndex);
    /* profile name is not default profile name, the profile is not empty */
    if (mmi_ucs2cmp(
            (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.profileName, 
            (S8*)GetString(STR_ID_VOIP_PROF_COMMON_PROF1 + profIndex)))
    {
        return FALSE;
    }
    /* voice mail server is not empty and is not "sip:", the profile is not empty */
    if (mmi_ucs2cmp(
            (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName, 
            (S8*)sipUri))
    {
        return FALSE;
    }

    mmi_voip_update_prof_acct_cache_to_disp(profIndex);
    if ((mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.displayName)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.authName)))
    {
        return FALSE;
    }
    /* port is not 5060, the profile is not empty */
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].acct_info.sipPort != 5060)
    {
        return FALSE;
    }
    /* username is not empty and is not "sip:", the profile is not empty */
    if (mmi_ucs2cmp(
            (S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username, 
            (S8*)sipUri))
    {
        return FALSE;
    }
    
    mmi_voip_update_prof_outbound_cache_to_disp(profIndex);
    if ((mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password)))
    {
        return FALSE;
    }
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].out_server_info.port != 0)
    {
        return FALSE;
    }

    mmi_voip_update_prof_register_cache_to_disp(profIndex);
    if ((mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.username)) || 
        (mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.password)))
    {
        return FALSE;
    }
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].reg_server_info.port != 0)
    {
        return FALSE;
    }

    mmi_voip_update_prof_nat_cache_to_disp(profIndex);
    if ((mmi_ucs2strlen((S8*)g_voip_cntx_p->prof_setting_info.disp_prof.serverName)))
    {
        return FALSE;
    }
    if ((g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[0] != 0) || 
        (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[1] != 0) || 
        (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[2] != 0) || 
        (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.natFirewall[3] != 0))
    {
        return FALSE;
    }
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.stunPort != 3478)
    {
        return FALSE;
    }
    if (g_voip_cntx_p->prof_setting_info.saved_prof[profIndex].nat_info.refInterval != 2)
    {
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_owner_number
 * DESCRIPTION
 *  Check if two strings are the same, regardless of the difference of capital or lowercase.
 * PARAMETERS
 *  unicodeSrc1         [IN]            String 1 in unicode
 *  unicodeSrc2         [IN]            String 2 in unicode
 * RETURNS
 *  TRUE means lowercase of the two strings are the same;
 *  FALSE means lowercase of the two strings are different.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_owner_number(U8 *unicodeSrc1, U8 *unicodeSrc2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *lowercaseSrc1 = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);
    U8 *lowercaseSrc2 = OslMalloc(VOIP_URI_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(lowercaseSrc1, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_voip_convert_uri_lower_case(unicodeSrc1, lowercaseSrc1, VOIP_URI_LEN * ENCODING_LENGTH);
    memset(lowercaseSrc2, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
    mmi_voip_convert_uri_lower_case(unicodeSrc2, lowercaseSrc2, VOIP_URI_LEN * ENCODING_LENGTH);
    if (!mmi_ucs2cmp((S8*)lowercaseSrc1, (S8*)lowercaseSrc2))
    {
        OslMfree(lowercaseSrc1);
        OslMfree(lowercaseSrc2);
        return TRUE;
    }
    else
    {
        OslMfree(lowercaseSrc1);
        OslMfree(lowercaseSrc2);
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_sos_number
 * DESCRIPTION
 *  Check if given uri is an emergency number, including 112, 911, sos...etc,
 *  regardless of the difference of capital or lowercase.
 * PARAMETERS
 *  unicodeUri         [IN]            Uri string in unicode
 * RETURNS
 *  TRUE means it is an emergency number;
 *  FALSE means it is not an emergency number.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_sos_number(U8 *unicodeUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *copyUri = OslMalloc((VOIP_URI_LEN + 1) * ENCODING_LENGTH);
    U8 *sipsosStr = OslMalloc(32);
    U8 asciiatStr[2], unicodeatStr[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(copyUri, 0, ((VOIP_URI_LEN + 1) * ENCODING_LENGTH));
    mmi_ucs2ncpy((S8*)copyUri, (S8*)unicodeUri, VOIP_URI_LEN);
    mmi_voip_parse_uri(copyUri); /* do not modify unicodeUri directly because unicodeUri could be an empty uri */
    mmi_voip_convert_uri_lower_case(copyUri, copyUri, VOIP_URI_LEN * ENCODING_LENGTH);

    memset(asciiatStr, 0, 2);
    sprintf((S8*)asciiatStr, "@");
    memset(unicodeatStr, 0, 4);
    mmi_asc_to_ucs2((S8*)unicodeatStr, (S8*)asciiatStr);

    memset(sipsosStr, 0, 32);
    mmi_ucs2ncpy((S8*)sipsosStr, (S8*)sipUri, mmi_ucs2strlen((S8*)sipUri));
    mmi_ucs2ncat((S8*)sipsosStr, (S8*)sos112, mmi_ucs2strlen((S8*)sos112));
    mmi_ucs2cat((S8*)sipsosStr, (S8*)unicodeatStr);
    
    if (!mmi_ucs2ncmp((S8*)copyUri, (S8*)sipsosStr, mmi_ucs2strlen((S8*)sipsosStr)))
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_VOIP_TRC_GRP, "\n[mmi_voip_is_sos_number] Detect sip:112@ Pattern!\n");
        g_voip_cntx_p->call_misc_info.isSOS = TRUE;
    }

    memset(sipsosStr, 0, 32);
    mmi_ucs2ncpy((S8*)sipsosStr, (S8*)sipUri, mmi_ucs2strlen((S8*)sipUri));
    mmi_ucs2ncat((S8*)sipsosStr, (S8*)sos911, mmi_ucs2strlen((S8*)sos911));
    mmi_ucs2cat((S8*)sipsosStr, (S8*)unicodeatStr);

    if (!mmi_ucs2ncmp((S8*)copyUri, (S8*)sipsosStr, mmi_ucs2strlen((S8*)sipsosStr)))
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_VOIP_TRC_GRP, "\n[mmi_voip_is_sos_number] Detect sip:911@ Pattern!\n");
        g_voip_cntx_p->call_misc_info.isSOS = TRUE;
    }
    
    memset(sipsosStr, 0, 32);
    mmi_ucs2ncpy((S8*)sipsosStr, (S8*)sipUri, mmi_ucs2strlen((S8*)sipUri));
    mmi_ucs2ncat((S8*)sipsosStr, (S8*)sosUri, mmi_ucs2strlen((S8*)sosUri));
    mmi_ucs2cat((S8*)sipsosStr, (S8*)unicodeatStr);

    if (!mmi_ucs2ncmp((S8*)copyUri, (S8*)sipsosStr, mmi_ucs2strlen((S8*)sipsosStr)))
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_VOIP_TRC_GRP, "\n[mmi_voip_is_sos_number] Detect sip:sos@ Pattern!\n");
        g_voip_cntx_p->call_misc_info.isSOS = TRUE;
    }
    
    OslMfree(copyUri);
    OslMfree(sipsosStr);
    
    if (g_voip_cntx_p->call_misc_info.isSOS == TRUE)
    {
        memset(unicodeUri, 0, (VOIP_URI_LEN * ENCODING_LENGTH));
        mmi_ucs2cpy((S8*)unicodeUri, (S8*)sos112);
        g_voip_cntx_p->call_misc_info.isSOS = FALSE;
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_codec_compatible
 * DESCRIPTION
 *  Check if held call's codec is allowed to merge to active call before merging call.
 * PARAMETERS
 *  codecList               [IN]            Supported codec list of the held call.
 *  firstcodecOnly          [IN]            Only compare to the first codec in codec list.
 * RETURNS
 *  TRUE means the codecs are compatible to merge;
 *  FALSE means the codecs are not compatible to merge.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_codec_compatible(voip_codec_enum *codecList, MMI_BOOL firstcodecOnly)
{
#ifdef __MMI_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 codecSupport = 0, localCodec = 0;
    med_voip_codec_cap_struct codecDetail;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    voip_get_codec_cap(VOIP_ENCODE_DECODE, &codecSupport, &codecDetail);
    if (firstcodecOnly == TRUE)
    {
        /* current held call in-use codec must in the codec support list 
           so that two calls can be merged */
        if ((codecSupport & codecList[0]) != 0)
        {
            return TRUE;
        }
    }
    else
    {
        for (i = 0; i < VOIP_MAX_NUM_CODEC; i++)
        {
            localCodec |= codecList[i];
        }
        if ((codecSupport & localCodec) != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
#else
    /* always return true for modis and pc simulator */
    return TRUE;
#endif /* __MMI_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_is_addr_change
 * DESCRIPTION
 *  Check if sdp address or port is changed.
 * PARAMETERS
 *  mmiSdp          [IN]            Sdp in mmi, which represents last sdp info.
 *  voipSdp         [IN]            Sdp in voip cc, which represents current sdp info.
 * RETURNS
 *  TRUE means the sdp addr or port is changed;
 *  FALSE means the sdp addr and port is not changed.
 *****************************************************************************/
MMI_BOOL mmi_voip_is_addr_change(voip_sdp_struct *mmiSdp, voip_sdp_struct *voipSdp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((strncmp((S8*) mmiSdp->local_addr, (S8*) voipSdp->local_addr, VOIP_MAX_IP_SEG_LEN)) ||
        (strncmp((S8*) mmiSdp->remote_addr, (S8*) voipSdp->remote_addr, VOIP_MAX_IP_SEG_LEN)) ||
        (mmiSdp->local_rtp_port != voipSdp->local_rtp_port) ||
        (mmiSdp->remote_rtp_port != voipSdp->remote_rtp_port) ||
        (mmiSdp->local_rtcp_port != voipSdp->local_rtcp_port) ||
        (mmiSdp->remote_rtcp_port != voipSdp->remote_rtcp_port))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_decoded_dtnct_id
 * DESCRIPTION
 *  get decoded data account id.
 * PARAMETERS
 *  dtnct_id
 * RETURNS
 *  void
 *****************************************************************************/
U32 mmi_voip_get_decoded_dtnct_id(U32 dtnct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum sim_id;
    kal_uint8 app_id;
    kal_bool always_ask;
    kal_uint32 ori_acc_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    cbm_decode_data_account_id(dtnct_id, &sim_id,&app_id, &always_ask, &ori_acc_id);

    return ori_acc_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_total_call
 * DESCRIPTION
 *  Total number of voip calls, including outgoing call, incoming call,
 *  active call, held call, etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 means voip not in-call, !0 means voip in-call.
 *****************************************************************************/
S32 mmi_voip_app_total_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_voip_cntx_p->call_list_info.numTotal;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_app_total_call
 * DESCRIPTION
 *  Total number of voip calls, including outgoing call, incoming call,
 *  active call, held call, etc.
 * PARAMETERS
 *  void
 * RETURNS
 *  0 means voip not in-call, !0 means voip in-call.
 *****************************************************************************/
S32 mmi_voip_query_call_count(mmi_voip_call_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 incoming_call_num = 0;
    S32 outgoing_call_num = 0;
    mmi_voip_call_list_struct *call_list = &g_voip_cntx_p->call_list_info;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(state)
    {
        case MMI_VOIP_CALL_STATE_ALL:
            return g_voip_cntx_p->call_list_info.numTotal;

        case MMI_VOIP_HOLD_STATE:
            return g_voip_cntx_p->call_list_info.numHeld;

        case MMI_VOIP_ACTIVE_STATE:
        case MMI_VOIP_INCOMING_STATE:
        case MMI_VOIP_OUTGOING_STATE:
        {
            for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
            {
                if (call_list->call_info[i].currState == MMI_VOIP_INCOMING_STATE)
                {
                    incoming_call_num += 1; 
                }
                else if (call_list->call_info[i].currState == MMI_VOIP_OUTGOING_STATE)
                {
                    outgoing_call_num += 1;
                }
            }

            if (state == MMI_VOIP_INCOMING_STATE)
            {
                return incoming_call_num;
            }
            else if (state == MMI_VOIP_OUTGOING_STATE)
            {
                return outgoing_call_num;
            }
            else
            {
                return (g_voip_cntx_p->call_list_info.numTotal - 
                        g_voip_cntx_p->call_list_info.numHeld - 
                        incoming_call_num - 
                        outgoing_call_num);
            }
        }
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_get_call_n_dialog_id
 * DESCRIPTION
 *  Get call id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_get_call_n_dialog_id(mmi_voip_call_state_enum state, S32* call_id, S32* dialog_id)
{
    U32 i = 0;
    mmi_voip_call_list_struct *call_list = &g_voip_cntx_p->call_list_info;
    MMI_BOOL is_found = MMI_FALSE;

    ASSERT((state == MMI_VOIP_OUTGOING_STATE) || (state == MMI_VOIP_INCOMING_STATE) || (state == MMI_VOIP_ACTIVE_STATE));
    for (i = 0; i < MMI_VOIP_MAX_NUM_CALL; i++)
    {
        if (call_list->call_info[i].currState == state)
        {
            *call_id = call_list->call_info[i].callId;
            *dialog_id = call_list->call_info[i].dialog_info[0].dialogId;
            is_found = MMI_TRUE;
            break;
        }
    }
    ASSERT(is_found == MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_gcall_get_caller_res_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN/OUT] caller resource info
 * RETURNS
 *  MMI_FALSE if fails
 *****************************************************************************/
MMI_BOOL mmi_voip_get_caller_res_info(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_int_query_caller_res_struct *ucm_res_info = (srv_ucm_int_query_caller_res_struct*)info;
    S16 call_id = 0, dialog_id = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!info)
    {
        return MMI_FALSE;
    }

    call_id = ucm_res_info->uid_info.group_id;
    dialog_id = mmi_voip_get_actual_dialog_id(ucm_res_info->uid_info.call_id);

    /* decide image id */
    if (g_voip_cntx_p->call_list_info.call_info[call_id].currState == MMI_VOIP_OUTGOING_STATE)
    {
        ucm_res_info->pic_id = IMG_ID_GCALL_OUTGOING;
    }
    else
    {
        ucm_res_info->pic_id = IMG_PHB_DEFAULT;
    }

    /* decide tone id */
    srv_prof_get_current_profile_value(
            SRV_PROF_SETTINGS_MT_CALL_TONE, 
            &(ucm_res_info->tone_id));

    ucm_res_info->tone_path[0] = 0;
    ucm_res_info->tone_path[1] = 0;
    ucm_res_info->pic_path[0] = 0;
    ucm_res_info->pic_path[1] = 0;
    //memcpy(ucm_res_info->tone_path, 0, sizeof(ucm_res_info->tone_path));
    //memcpy(ucm_res_info->pic_path, 0, sizeof(ucm_res_info->pic_path));
    ucm_res_info->is_video_sound = MMI_FALSE;

    /* decide res type */
    ucm_res_info->res_type = SRV_UCM_RES_TYPE_TONE_ID | SRV_PHB_RES_TYPE_IMAGE_ID;

    return MMI_TRUE;
}


#endif /* __MMI_VOIP__ */

