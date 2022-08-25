/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2007]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  gps_auth.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/ 
#ifdef __GPS_SUPPORT__
#include "kal_general_types.h"
    
extern kal_uint8 gps_uart_port;
extern void gps_uart_enable_authentication(void);
extern kal_char* release_bb_chip(void);

/*****************************************************************************
 * FUNCTION
 *  gps_authentication_timeout_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_authentication_timeout_handler(void)
{   
}
/*****************************************************************************
 * FUNCTION
 *  gps_send_check_id
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_send_check_id(void)
{  
}


/*****************************************************************************
 * FUNCTION
 *  gps_receive_check_id
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool gps_receive_check_id(kal_uint8 *buffer, kal_int32 length)
{    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gps_send_authentication
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_send_authentication(kal_uint8 year, kal_uint8 mon, kal_uint8 day, kal_uint8 hour, kal_uint8 min, kal_uint8 sec)
{    
}


/*****************************************************************************
 * FUNCTION
 *  gps_receive_authentication
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool gps_receive_authentication(kal_uint8 *buffer, kal_int32 length)
{    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gps_gis_authentication
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_gis_authentication(kal_uint8 *plainText, kal_uint16 plainTextLen, kal_uint8 *encryptText, kal_uint16 encryptTextLen)
{        
}

#endif /* __GPS_SUPPORT__ */

