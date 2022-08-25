/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2005]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  gps_modem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task internal used API or struct declare
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#ifndef _GPS_MODEM_H_
#define _GPS_MODEM_H_

#if defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)
extern void gps_open_debug_log_file(void);
extern void gps_close_debug_log_file(void);
extern void gps_write_debug_info_log_file(kal_uint16 port);
extern void gps_write_nmea_raw_data_log_file(kal_uint16 port);

#endif 
#endif /* _GPS_MODEM_H_ */ 




