/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_wap_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains WAP/MMS configuration default value. 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *

 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#include "kal_general_types.h"
#include "MMI_features.h"
#include "custom_wap_config.h"
#include "app_ua.h"

#if defined(PLUTO_MMI) && !defined(__MMI_EM_INET_APP_SLIM__) && defined(__MMI_ENGINEER_MODE__)
#include "EngineerModeInetAppGprot.h"
#endif

/*****************************************************************************
 * FUNCTION
 *  custom_wap_check_wap_support_enabled
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool custom_wap_check_wap_support_enabled(void)
{
#ifdef WAP_SUPPORT
	return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

#ifdef OBIGO_Q03C
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_push_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_push_msg_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_PUSH_MAX_NO_OF_MSG;
}

#endif

#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_cache_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_cache_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_CACHE_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_ua_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_ua_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)(WAP_CUSTOM_CFG_DEFAULT_UA_HEADER);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_ua_prof_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_ua_prof_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)(WAP_CUSTOM_CFG_DEFAULT_UA_PROF_URL);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_accept_language_preference
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_accept_language_preference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)(WAP_COMMON_CFG_ACCEPT_LANGUAGE_PREFERENCE);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_default_browse_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_default_browse_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_DEFAULT_BROWSE_TIMEOUT;
}


#if 0
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
#endif


#if defined (OBIGO_Q03C_MMS_V01)
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_user_agent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_user_agent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)(WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_msg_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_warning_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_warning_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_get_retry_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_get_retry_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_GET_TIMEOUT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_get_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_get_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (WAP_CUSTOM_CFG_MAX_MMS_GET_RETRY + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_retry_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_retry_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_POST_TIMEOUT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_msg_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_msg_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (WAP_CUSTOM_CFG_MAX_MMS_POST_MSG_RETRY + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_pdu_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_pdu_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (WAP_CUSTOM_CFG_MAX_MMS_POST_PDU_RETRY + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_slide_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_mms_slide_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_SLIDE_DURATION;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_immed_retrieval_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_immed_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_IMMED_RETRIEVAL_MODE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_roam_retrieval_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_roam_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_ROAM_RETRIEVAL_MODE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_allow_advertimsement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_allow_advertimsement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_ALLOW_ADVERTIMSEMENT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_allow_anonymous
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_allow_anonymous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_ALLOW_ANONYMOUS;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_req_delivery_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_req_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_REQ_DELIVERY_REPORT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_req_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_req_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_REQ_READ_REPORT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_send_delivery_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_send_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_SEND_DELIVERY_REPORT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_send_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_send_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_SEND_READ_REPORT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_VERSION;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_SLIDES;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_ADDRESS;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT;
}
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_delta_retrival_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_mms_delta_retrival_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) WAP_CUSTOM_CFG_MMS_DELTA_RETRIVAL_SIZE;
}

#endif /*OBIGO_Q03C_MMS_V01*/

#endif /* OBIGO_Q03C */ 



#if defined (OBIGO_Q03C_MMS_V02)
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_user_agent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_user_agent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_num_on_card
 * DESCRIPTION
 *  Return no. of MMS supported on memory card
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_num_on_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG_ON_CARD;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_msg_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_warning_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_warning_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_WARNING_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_report_mms_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_report_mms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_NBR_REPORT_MMS_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_get_retry_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_get_retry_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_GET_TIMEOUT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_get_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_get_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (WAP_CUSTOM_CFG_MAX_MMS_GET_RETRY + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_retry_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_retry_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_POST_TIMEOUT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_msg_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_msg_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (WAP_CUSTOM_CFG_MAX_MMS_POST_MSG_RETRY + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_post_pdu_retry_nums
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_post_pdu_retry_nums(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) (WAP_CUSTOM_CFG_MAX_MMS_POST_PDU_RETRY + 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_slide_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_mms_slide_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_SLIDE_DURATION;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_immed_retrieval_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_immed_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_IMMED_RETRIEVAL_MODE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_roam_retrieval_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_roam_retrieval_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_ROAM_RETRIEVAL_MODE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_allow_advertimsement
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_allow_advertimsement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_ALLOW_ADVERTIMSEMENT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_allow_anonymous
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_allow_anonymous(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_ALLOW_ANONYMOUS;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_req_delivery_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_req_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_REQ_DELIVERY_REPORT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_req_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_req_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_REQ_READ_REPORT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_send_delivery_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_send_delivery_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_SEND_DELIVERY_REPORT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_send_read_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_send_read_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MMS_SEND_READ_REPORT;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wap_custom_get_mms_version_index();
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_SLIDES;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_ADDRESS;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_delta_retrival_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_mms_delta_retrival_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) WAP_CUSTOM_CFG_MMS_DELTA_RETRIVAL_SIZE;
}
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_user_element_header_size
 * DESCRIPTION
 *  
 * PARAMETERS+
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_mms_user_element_header_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32) WAP_CUSTOM_CFG_MMS_USER_ELEMENT_HEADER_SIZE;
}
#endif  /*__MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__*/
#endif /*defined (OBIGO_Q03C_MMS_V02)*/





#ifdef OBIGO_Q05A
/********************************* WAP Browser *************************************/
/*
 * This array is used to store those non markup-language content-types.
 * *  For accpeted markup-language content-types will be automatically inserted by your WAP feature, WAP1.2.1 or WAP2.0
 * *  For WAP1.2.1, "application/vnd.wap.wmlc", "application/vnd.wap.wmlscriptc" and "text/vnd.wap.wml"
 * *  For WAP2.0, "text/html", "application/xhtml+xml; profile=http://www.wapforum.org/xhtml" and "application/vnd.wap.xhtml+xml"
 */
static const char *const g_BrowserAcceptContentType[] = 
{
    "image/vnd.wap.wbmp",
    "image/gif",
    "image/bmp",
    "audio/imelody",
    "audio/midi",
    "audio/wav",
    "application/vnd.wap.wtls-ca-certificate",
    "application/x-x509-ca-cert",
    "application/vnd.wap.hashed-certificate",
    "application/vnd.wap.signed-certificate",
    "text/css",
    "*/*",
    NULL
};

static const char *const g_BrowserAcceptCharset[] = 
{
    "utf-8",
    "iso-8859-1",
	"us-ascii",
	"iso-10646-ucs-2",
    NULL
};

static const char *const g_BrowserLanguageType[] = 
{
    "English",
    NULL
};

#ifdef OBIGO_Q05A_MMS
static const char *const g_MMSAcceptContentType[] = 
{
    "application/vnd.wap.mms-message",
    "application/smil",
    "application/vnd.wap.multipart.related",
    "application/vnd.wap.multipart.mixed",
    "multipart/related",
    "multipart/mixed",
#if defined(JPG_DECODE)
    "image/jpeg",
#endif
    "image/bmp",
    "image/gif",
    "image/vnd.wap.wbmp",
#if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
    "image/png",
#endif
#if defined(SVG_SUPPORT)
    "image/svg+xml",
#endif
    "audio/amr",
#if defined(AMRWB_DECODE)
    "audio/amr-wb",
#endif
    "audio/mid",
    "audio/midi",
    "audio/sp-midi",
    "audio/wav",
    "audio/x-wav",
    "audio/imelody",
    "audio/vm",
#if defined(AU_DECODE)
    "audio/basic",
#endif
#if defined(AIFF_DECODE)
    "audio/x-aiff",
    "audio/aiff",
#endif
#if defined(DAF_DECODE)
    "audio/mp3",
    "audio/mpeg",
#endif
#if defined(AAC_DECODE)
    "audio/aac",
    "audio/m4a",
#endif
#if defined(__MMI_PURE_AUDIO__)
    "audio/3gpp",
    "audio/mp4",
#endif
#if defined(WMA_DECODE)
    "audio/wma",
#endif
#if defined(MUSICAM_DECODE)
    "audio/mp2",
#endif
    "text/plain",
    "text/x-imelody",
#if defined(__MMI_VCALENDAR__)
    "text/x-vCalendar",
    "text/calendar",
#endif
#if defined(__MMI_VCARD__)
    "text/x-vCard",
#endif
#if defined(__MMI_VBOOKMARK__)
    "text/x-vbookmark",
#endif
#if defined(MP4_DECODE)
    "video/mp4",
    "video/mpeg",
    "video/3gpp",
    "video/3gpp2",
#endif
#if defined(MJPG_SUPPORT)
    "video/x-msvideo",
#endif
#if defined(__J2ME__)
    "application/java-archive",
    "application/java-vm",
    "text/vnd.sun.j2me.app-descriptor",
#endif
#if defined(__DRM_SUPPORT__)
    "application/vnd.oma.drm.message",
    "application/vnd.oma.drm.content",
    "application/vnd.oma.drm.rights+xml",
    "application/vnd.oma.drm.rights+wbxml",
#ifdef __DRM_V02__
    "application/vnd.oma.drm.dcf",
#endif
#endif
    "application/vnd.wap.hashed-certificate",
    "application/vnd.wap.signed-certificate",
    "application/vnd.wap.wtls_ca_certificate",
    "application/x_x509_ca_cert",
#if defined(__MMI_EBOOK_READER__)
    "application/x-pilot-pdb",
#endif
#if defined(YAMAHA_MA3)
    "application/vnd.smaf",
#endif
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    "mtk/med.thm",
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    "application/vnd.mtk.lrc",
#endif
#ifdef __MMI_MESSAGES_EMS__
    "application/vnd.mtk.ems",
    "application/vnd.mtk.anm",
#endif
    NULL
};

static const char *const g_MMSAcceptCharset[] = 
{
    "utf-8",
    "utf-16",
    "utf-16le",
    "utf-16be",
    "iso-8859-1",
    "us-ascii",
    "iso-10646-ucs-2",
    NULL
};

static const char *const g_MMSLanguageType[] = 
{
    NULL
};

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_mms_version(void)
{
    return wap_custom_get_mms_version_index();
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_user_agent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_user_agent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const kal_uint8*)WAP_CUSTOM_CFG_DEFAULT_MMS_UA_HEADER;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8)WAP_CUSTOM_CFG_MAX_MMS_SLIDES;
    
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8)WAP_CUSTOM_CFG_MAX_MMS_ADDRESS;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 wap_custom_get_max_mms_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint8)WAP_CUSTOM_CFG_MAX_MMS_ATTACHMENT;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_custom_get_max_mms_msg_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_uint32)WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_num_on_card
 * DESCRIPTION
 *  Return no. of MMS supported on memory card
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_num_on_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG_ON_CARD;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_accept_content_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_accept_content_type(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_MMSAcceptContentType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_MMSAcceptContentType[i];
        }
        i++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_accept_charset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_accept_charset(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_MMSAcceptCharset[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_MMSAcceptCharset[i];
        }
        i++;
    }
    return NULL;
}
#endif /* OBIGO_Q05A_MMS */
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_charset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_charset(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserAcceptCharset[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserAcceptCharset[i];
        }
        i++;
    }
    return NULL;

}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_content_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_content_type(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserAcceptContentType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserAcceptContentType[i];
        }
        i++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_browser_accept_language(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_BrowserLanguageType[i] != NULL)
    {
        if (i == index)
        {
            return (const kal_uint8*)g_BrowserLanguageType[i];
        }
        i++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_cookie_max_items
 * DESCRIPTION
 *  This function gets the max. number of items stored in the cookie list.
 * PARAMETERS
 *  void
 * RETURNS
 *  Max. number of items.
 *****************************************************************************/
kal_int32 wap_custom_get_browser_cookie_max_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_COOKIE_MAX_ITEMS;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_cookie_max_item_size
 * DESCRIPTION
 *  This function gets the max. size of a cookie.
 * PARAMETERS
 *  void
 * RETURNS
 *  Max. size of a cookie.
 *****************************************************************************/
kal_int32 wap_custom_get_browser_cookie_max_item_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_COOKIE_MAX_ITEM_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_accept_encoding
 * DESCRIPTION
 *  This function gets the setting about the Accept-Encoding header.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: disable
 *  1: enable
 *****************************************************************************/
kal_int32 wap_custom_get_browser_accept_encoding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_ACCEPT_ENCODING;
}


/* MAUI_03175268 starts */
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_browser_history_size
 * DESCRIPTION
 *  This function gets the setting about the history size.
 * PARAMETERS
 *  void
 * RETURNS
 *  size
 *****************************************************************************/
kal_int32 wap_custom_get_browser_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_HISTORY_SIZE;
}
/* MAUI_03175268 ends */


#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_max_mms_cache_push_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_custom_get_max_mms_cache_push_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return WAP_CUSTOM_CFG_MAX_MMS_CACHE_PUSH_NUM;
}

/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_mms_postcard_server_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const kal_uint8 *wap_custom_get_mms_postcard_server_addr(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (const kal_uint8*)WAP_CUSTOM_MMS_POSTCARD_SERVER_ADDR;
}

#ifdef PLUTO_MMI
/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_accept_header_index
 * DESCRIPTION
 *  This function is to get active accept header index. Notice that the return type is enum
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
wap_custom_accept_header_enum  wap_custom_get_accept_header_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_EM_INET_APP_SLIM__) || !defined(__MMI_ENGINEER_MODE__)
    return WAP_CUSTOM_DEFAULT_ACCEPT_HEADER_INDEX;
#else
    return (wap_custom_accept_header_enum) applib_inet_get_active_accept_header();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wap_custom_get_m
 * DESCRIPTION
 *  This function is to get active accept header index. Notice that the return type is enum
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
wap_custom_mms_version_enum wap_custom_get_mms_version_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_EM_INET_APP_SLIM__) || !defined(__MMI_ENGINEER_MODE__)
    return WAP_CUSTOM_DEFAULT_MMS_VERSION_INDEX;
#else
    return (wap_custom_mms_version_enum)applib_inet_get_active_mms_version();
#endif
}

#endif
