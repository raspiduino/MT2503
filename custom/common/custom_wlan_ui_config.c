/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *
 * Filename:
 * ---------
 * custom_wlan_ui_config.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   Provide interface for customer to config wlan ui 
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "custom_wlan_ui_config.h"

#ifdef __TCPIP__
#ifdef __MMI_WLAN_FEATURES__

/*******************************************************************************
* Macro Define
*******************************************************************************/
#define SSID_CMCC_LENGTH        4
#define SSID_CMCC_EDU_LENGTH    8

/*******************************************************************************
* Global Variable
*******************************************************************************/
const char ssid_cmcc[SSID_CMCC_LENGTH + 1] = {'C','M','C','C'};
const char ssid_cmcc_edu[SSID_CMCC_EDU_LENGTH + 1] = {'C','M','C','C','-','E','D','U'};

/*****************************************************************************
* FUNCTION
*  custom_wlan_ssid_convert
* DESCRIPTION
*   This function is used to convert ssid from any charset to unicode
* 
* PARAMETERS
*   pInBuffer  [In]     ssid in the format of unknown charset
*   pOutBuffer [Out]    ssid in the format of unicode
*   length     [In]     the length of ssid 
*   
* RETURNS
*  void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void custom_wlan_ssid_convert(const char* pInBuffer, char* pOutBuffer, const kal_int32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_chset_enum ret_charset;
    kal_int32 actual_length;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_charset = mmi_chset_guess(
                   pInBuffer,
                   length,
                   MMI_CHSET_BASE,
                   CHSET_GUESS_ALL);

    switch(ret_charset)
    {
    /* Add special case handling here */
    
    /*  Demo 
    case MMI_CHSET_UTF8:
        mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char *)pInBuffer,
            (char *)pOutBuffer,
            (length + 1) * ENCODING_LENGTH);
    */
    
    default:
    actual_length = mmi_chset_convert(
            ret_charset,
            MMI_CHSET_UCS2,
            (char *)pInBuffer,
            (char *)pOutBuffer,
            (length + 1) * ENCODING_LENGTH);
    pOutBuffer[actual_length - ENCODING_LENGTH] = '\0';
    pOutBuffer[actual_length - ENCODING_LENGTH + 1] = '\0';
        break;
    }

}

/*****************************************************************************
* FUNCTION
*  custom_wlan_ssid_convert_ex
* DESCRIPTION
*   This function is used to convert ssid from any charset to unicode
* 
* PARAMETERS
*   pInBuffer  [In]     ssid in the format of unknown charset
*   pOutBuffer [Out]    ssid in the format of unicode
*   length     [In]     the length of ssid 
*   ret_charset[Out]    the type of input charset 
*
* RETURNS
*  void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void custom_wlan_ssid_convert_ex(const char* pInBuffer, char* pOutBuffer, const kal_int32 length, mmi_chset_enum *ret_charset)
{   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *ret_charset = mmi_chset_guess(
                   pInBuffer,
                   length,
                   (mmi_chset_enum)(0),
                   CHSET_GUESS_ALL);

    switch(*ret_charset)
    {
    /* Add special case handling here */
    
    /*  Demo 
    case MMI_CHSET_UTF8:
        mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char *)pInBuffer,
            (char *)pOutBuffer,
            (length + 1) * ENCODING_LENGTH);
    */
    
    default:
        mmi_chset_convert(
            *ret_charset,
            MMI_CHSET_UCS2,
            (char *)pInBuffer,
            (char *)pOutBuffer,
            (length + 1) * ENCODING_LENGTH);
        break;
    }

}

MMI_BOOL custom_wlan_is_operator_network(const char* ssid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 length;
    MMI_BOOL is_match = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    length = strlen (ssid);

    switch(length)
    {
    case SSID_CMCC_LENGTH:
        if(strncmp((const char*)ssid, (const char*)ssid_cmcc, SSID_CMCC_LENGTH) == 0)
        {
            is_match = MMI_TRUE;
        }
        break;
    case SSID_CMCC_EDU_LENGTH:
        if(strncmp((const char*)ssid, (const char*)ssid_cmcc_edu, SSID_CMCC_EDU_LENGTH) == 0)
        {
            is_match = MMI_TRUE;
        }
        break;
    default:
        break;
    }

    return is_match;
}


/* under construction !*/

#endif /* __MMI_WLAN_FEATURES__ */
#endif /* __TCPIP__ */ 

