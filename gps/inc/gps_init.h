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
 *  gps_init.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __GPS_SUPPORT__

#ifndef _GPS_INIT_H_
#define _GPS_INIT_H_

#include "app_ltlcom.h"

#include "kal_general_types.h"
        
extern void GPS_Init(void (* callback)(kal_bool));
extern void GPS_Shutdown(void);
extern void GPS_UTC_Init(void);
extern void GPS_Calibrate_RTC(kal_uint8 year,   // i  - Year: 0 ~ 127
                              kal_uint8 mon,    // i  - Month: 1 ~ 12
                              kal_uint8 day,    // i  - Day: 1 ~ 31
                              kal_uint8 hour,   // i  - Hour: 0 ~ 23
                              kal_uint8 min,    // i  - Min: 0 ~ 59
                              kal_uint8 sec);   // i  - Sec: 0 ~ 59
extern void GPS_Calibrate_Clock_Drift(double clock_drift, kal_uint32 age);
extern void GPS_Adjust_RTC_Diff(ilm_struct *ilm_ptr);
extern void gps_nvram_write_cnf_handler(ilm_struct *ilm_ptr);
extern void gps_clear_nvram_data(void);

#endif /* _GPS_INIT_H_ */

#endif /* __GPS_SUPPORT__ */
