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

/*******************************************************************************
* Filename:
* ---------
*  custom_dcd.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   DCD Custom
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
*******************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __DCD_SUPPORT__
#include "custom_dcd.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_release.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MMI_EM_MISC_DCD__
static mmi_em_dcd_nw_data_struct       g_em_dcd_nw_data;
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#ifdef __MMI_EM_MISC_DCD__
mmi_em_dcd_nw_data_struct    * g_em_dcd_nw_data_p       = &g_em_dcd_nw_data;
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_em_dcd_nw_param_init
 * DESCRIPTION
 *  Initialize the browser application whenever user enters into the wap menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret dcd_custom_init(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    S16 error;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    ReadRecord(NVRAM_EF_DCD_EM_PARAM_DATA_LID, 1, g_em_dcd_nw_data_p, NVRAM_EF_DCD_EM_PARAM_DATA_SIZE, &error);
    if (error != NVRAM_READ_SUCCESS);
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_dcd_write_nw_data
 * DESCRIPTION
 *  write setting value to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: success / MMI_FALSE: error
 *****************************************************************************/
void dcd_custom_em_write_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
	S16 error;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__	
    WriteRecord(NVRAM_EF_DCD_EM_PARAM_DATA_LID, 1, g_em_dcd_nw_data_p, NVRAM_EF_DCD_EM_PARAM_DATA_SIZE, &error);
	ASSERT(error==NVRAM_WRITE_SUCCESS);
#endif
}
/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_apn
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
char  * dcd_custom_get_apn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    return (char  *)g_em_dcd_nw_data_p->apn;
#else
    return "cmwap";
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_apn_name
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
char  * dcd_custom_get_apn_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    return (char  *)g_em_dcd_nw_data_p->apn_name;
#else
    return "CMCC DCD GPRS";
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_gateway
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
char  * dcd_custom_get_gateway(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    return (char  *)g_em_dcd_nw_data_p->gate_way;
#else
    return "10.0.0.172";
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_port
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
unsigned short dcd_custom_get_port(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned short port;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    {
        unsigned char * p = (unsigned char *)g_em_dcd_nw_data_p->port;
        port = 0;
        while (*p != 0) 
        { 
            port = port * 10 + *p - '0';
            p++;
        }
    }
#else
    port = 80;
#endif
    return port;
}


/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_url_add_channel
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
char  * dcd_custom_get_url_add_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    return  (char *)g_em_dcd_nw_data_p->add_chan_url;
#else
#if (defined __DCD_V20__)
    return "http://dcd.monternet.com/service/addchannel";
#elif (defined __DCD_V30__)
    /* for existing network */
    return "http://dcd.monternet.com/service/addchannel?version=3.0.0";
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_url_del_channel
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
char  * dcd_custom_get_url_del_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    return  (char *)g_em_dcd_nw_data_p->del_chan_url;
#else
#if (defined __DCD_V20__)
    return "http://dcd.monternet.com/service/deletechannel";
#elif (defined __DCD_V30__)
    /* for existing network */
    return "http://dcd.monternet.com/service/deletechannel?version=3.0.0";
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_url_refresh
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
char  * dcd_custom_get_url_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    return  (char *)g_em_dcd_nw_data_p->refresh_url;
#else
#if (defined __DCD_V20__)
    return "http://dcd.monternet.com/content/refresh";
#elif (defined __DCD_V30__)
    /* for existing network */
    return "http://dcd.monternet.com";
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_url_help
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
char  * dcd_custom_get_url_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    return  (char *)g_em_dcd_nw_data_p->help_url;
#else
#if (defined __DCD_V20__)
    return "http://dcd.monternet.com/service/help";
#elif (defined __DCD_V30__)
    /* for existing network */
    return "http://dcd.monternet.com/service/help?version=3.0.0";
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  dcd_custom_get_storage_switch
 * DESCRIPTION 
 * PARAMETERS     
 * RETURNS
 *  void
 *****************************************************************************/
char dcd_custom_get_storage_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_MISC_DCD__
    return  (char)g_em_dcd_nw_data_p->storage_switch;
#else
    return 0;
#endif
}

#endif /*__DCD_SUPPORT__*/

