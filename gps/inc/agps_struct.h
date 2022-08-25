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
*  agps_struct.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AGPS related structure define in GPS task
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/
#ifndef __GPS_AGPS_H__
#define __GPS_AGPS_H__

#include "gps_main.h"
#include "gps2lcsp_struct.h"
#include "gps2lcsp_enum.h"

#include "kal_general_types.h"    

#if defined(__AGPS_SUPPORT__)
#define GPS_AGPS_QOP_POS_ARRAY_MAX   GPS_AGPS_POS_REQ_TIMER_MAX
#define GPS_AGPS_QOP_MEAS_ARRAY_MAX  GPS_AGPS_MEAS_REQ_TIMER_MAX

typedef struct 
{
    kal_uint16    bitmap;    /*see define of GPS_ASSIST_MASK_RTI enum*/
    gps_sat_related_data_struct sat_data;
} gps_assist_bitmap_struct;


typedef struct 
{
    kal_uint16  frame;
    kal_uint16  week;
    kal_uint32  tow;
    kal_uint8   fix;
    double       latitude;         /*latitude */
    double       longtitude;       /* N2, encoded longtitude with 2's complement */
    double       altitude;         /* no encoding, unit in meter */
    kal_uint16   unc_major;        /* K1, encoded r1 */
    kal_uint16   unc_minor;       /* K2, encoded r2 */
    kal_uint16   unc_bear;         /* N3, encoded a = 2N3, Bearing of semi-major axis (degrees)*/
    kal_uint16   unc_vert;     /* K3, encode r3, vertical uncertain */
    kal_uint8   confidence;       /* %, The confidence by which the position of a target 
                                   entity is known to be within the shape description, 
                                   expressed as a percentage. [0 ~ 100] (%)*/
    double       h_speed; /*horizontal speed*/
    kal_uint16   bearing;    /*Direction of the horizontal speed*/
    kal_uint32  ticks;
} gps_agps_pos_struct;

typedef struct 
{
    gps_error_code_enum error_code;
} gps_agps_loc_error_struct;

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
#endif

#endif /*__AGPS_SUPPORT__*/
#endif /*__GPS_AGPS_H__*/


