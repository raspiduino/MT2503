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
 * vapp_worldclock_gprot.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**********************************************************************************/




/*****************************************************************************
* FUNCTION
*  WcInit
* DESCRIPTION
*  initial function of world clock
* PARAMETERS
*  void
* RETURNS
*  void
 *****************************************************************************/


#ifndef __VAPP_WORLD_CLOCK_GPROT_H__
#define __VAPP_WORLD_CLOCK_GPROT_H__
#include "MMIDataType.h"
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct 
{
    S16 pos_x;
    S16 pos_y;
}WCCityPosition;
extern U16 mmi_wc_get_size2(void); 

#define NUM_OF_CITY mmi_wc_get_size2()


extern void mmi_wc_init(void);
/*****************************************************************************
* FUNCTION
*  mmi_wc_get_time_zone
* DESCRIPTION
*  get time zone with city index
* PARAMETERS
*  cityIndex : [IN] city index 
* RETURNS
*  time zone of city 
 *****************************************************************************/     
FLOAT mmi_wc_get_time_zone(U16 cityIndex);

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_city_pos
* DESCRIPTION
*  get city position on map with city index
* PARAMETERS
*  cityIndex : [IN] city index 
* RETURNS
*  city's position 
 *****************************************************************************/      
WCCityPosition mmi_wc_get_city_pos(U16 cityIndex);

/*****************************************************************************
* FUNCTION
*  mmi_wc_search_byname
* DESCRIPTION
*  get city index list by city name
* PARAMETERS
*  cityName : [IN] city name 
*  searchResult : [OUT] result list
* RETURNS
*  count of city
 *****************************************************************************/   
U16 mmi_wc_search_byname(WCHAR *cityName, U16 *searchResult);

/*****************************************************************************
* FUNCTION
*  mmi_wc_search_bypos
* DESCRIPTION
*  get city index list by city position inside a  given distance
* PARAMETERS
*  cityPos : [IN] given position
*  distance : [IN] range
*  searchResult : [OUT] result list
* RETURNS
*  count of city
 *****************************************************************************/      
U16 mmi_wc_search_bypos(WCCityPosition cityPos,U16 distance, U16 *searchResult);

/*****************************************************************************
* FUNCTION
*  mmi_wc_search_by_x
* DESCRIPTION
*  get city index list by city's X coordinate inside a  given distance
* PARAMETERS
*  cityIndex : [IN] city index 
*  distance : [IN] range
*  searchResult : [OUT] result list
* RETURNS
*  count of city
 *****************************************************************************/ 
U16 mmi_wc_search_by_x(S32 pos_x, U16 distance, U16 *searchResult);

/*****************************************************************************
* FUNCTION
*  mmi_wc_search_bytz
* DESCRIPTION
*  get city index list by given time zone
* PARAMETERS
*  cityTZ : [IN] city time zone
*  searchResult : [OUT] result list
* RETURNS
*  count of city
 *****************************************************************************/     
U16 mmi_wc_search_bytz(FLOAT cityTZ, U16 *searchResult);

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_home_dst
* DESCRIPTION
*  get home city day light saving time setting
* PARAMETERS
*  void
* RETURNS
*  day light saving time setting : 0 -->not set,  1-->set
 *****************************************************************************/     
U8 mmi_wc_get_home_dst(void);

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_frn_dst
* DESCRIPTION
*  get foreign city day light saving time setting
* PARAMETERS
*  cityOrder : [IN] which foreign city 
* RETURNS
*  day light saving time setting : 0-->not set, 1-->set
 *****************************************************************************/      
U8 mmi_wc_get_frn_dst(U8 cityOrder);

/*****************************************************************************
* FUNCTION
*  srv_wc_save_home_dst
* DESCRIPTION
*  save city day light saving setting
* PARAMETERS
*  homeDst : [IN] home day light saving time setting 
* RETURNS
*  void
 *****************************************************************************/    
void srv_wc_save_home_dst(U8 homeDst);
/*****************************************************************************
* FUNCTION
*  mmi_wc_save_home_dst
* DESCRIPTION
*  save home city day light saving setting
* PARAMETERS
*  homeDst : [IN] home day light saving time setting 
* RETURNS
*  void
 *****************************************************************************/     
void mmi_wc_save_home_dst(U8 homeDst);

/*****************************************************************************
* FUNCTION
*  mmi_wc_save_frn_dst
* DESCRIPTION
*  save foreign city day light saving time setting
* PARAMETERS
*  frnDst : [IN] day light saving time setting 
*  cityOrder : [IN] which city to set
* RETURNS
*  void 
 *****************************************************************************/     
void mmi_wc_save_frn_dst(U8 frnDst, U8 cityOrder);

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_home_index
* DESCRIPTION
*  get home city index
* PARAMETERS
*  void
* RETURNS
*  home city index
 *****************************************************************************/        
U16 mmi_wc_get_home_index(void);

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_frn_index
* DESCRIPTION
*  get foreign city index
* PARAMETERS
*  cityOrder : [IN] which city to get 
* RETURNS
*  city's index 
 *****************************************************************************/     
U16 mmi_wc_get_frn_index(U8 cityOrder);

/*****************************************************************************
* FUNCTION
*  mmi_wc_save_home_city
* DESCRIPTION
*  save home city index
* PARAMETERS
*  cityIndex : [IN] city index 
* RETURNS
*  void
 *****************************************************************************/      
void mmi_wc_save_home_city(U16 cityIndex);

/*****************************************************************************
* FUNCTION
*  mmi_wc_save_frn_city
* DESCRIPTION
*  save foreign city index
* PARAMETERS
*  cityIndex : [IN] city index 
*  cityOrder : [IN] which city to save
* RETURNS
*  void
 *****************************************************************************/     
void mmi_wc_save_frn_city(U16 cityIndex, U8 cityOrder);

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_city_strid
* DESCRIPTION
*  get city string id by city index
* PARAMETERS
*  cityIndex : [IN] city index 
* RETURNS
*  string id of city
 *****************************************************************************/     
U16 mmi_wc_get_city_strid(U16 cityIndex);

/*****************************************************************************
* FUNCTION
*  mmi_wc_update_sys_datetime
* DESCRIPTION
*  update system time as home city changed
* PARAMETERS
*  cityIndex : [IN] city index 
*  dstFlag   : [IN] day light saving time set flag, 1-->activate ,-1-->deactivate, 0-->ignore day light saving time
* RETURNS
*  void
 *****************************************************************************/ 
void mmi_wc_update_sys_datetime(U16 newCityIndex, S16 dstFlag);

/*****************************************************************************
* FUNCTION
*  mmi_wc_set_home_timezone
* DESCRIPTION
*  update home city time zone and city index 
* PARAMETERS
*  timeZone : [IN] new time zone
* RETURNS
*  MMI_TRUE-->home city changed; MMI_FALSE-->home city didn't change
 *****************************************************************************/ 
MMI_BOOL mmi_wc_set_home_timezone(FLOAT timeZone);

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_next_time_zone
* DESCRIPTION
*  get the time zone next to current time zone 
* PARAMETERS
*  currTZ : [IN] current time zone
* RETURNS
*  FLOAT
 *****************************************************************************/ 
FLOAT mmi_wc_get_next_time_zone(FLOAT currTZ);

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_prev_time_zone
* DESCRIPTION
*  get the previous time zone of current time zone  
* PARAMETERS
*  currTZ : [IN]  current time zone
* RETURNS
*  FLOAT
 *****************************************************************************/ 
FLOAT mmi_wc_get_prev_time_zone(FLOAT currTZ);

void vapp_wc_init_key_cityinfo(void);

#ifdef __cplusplus
}
#endif

#endif

