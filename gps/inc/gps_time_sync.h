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
*  gps_time_sync.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AGPS related feature
*
* Author:
* -------
*  
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/
#include "kal_general_types.h"
extern void gps_time_sync_init(kal_uint32 account_id);
extern void gps_time_sync_message_handle(ilm_struct *ilm_ptr);
extern void gps_time_sync_nitz_sync(kal_uint32 curr_sec);
extern void gps_time_sync_gps_sync();
extern kal_bool gps_time_sync_is_system_time_valid_ext();

