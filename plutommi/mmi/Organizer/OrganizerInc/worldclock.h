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
 * Worldclock.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines constant, enum value, structure, and function prototype for world clock.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      worldclock.h
   Author:        Vandana M
   Date Created:  July-14-2003
   Contains:      WorldClock
**********************************************************************************/
#ifndef _MMI_WORLDCLOCK_H
#define _MMI_WORLDCLOCK_H

#define __MMI_WORLDCLOCK_DST__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "Gui_data_types.h"
#if !defined(__COSMOS_MMI__)
#include "WorldclockResDef.h"
#endif
#include "kal_non_specific_general_types.h"
/* 
 * Define
 */

/* 
 * Typedef 
 */
/* world clock time zone structure */
typedef struct
{
    FLOAT CityTimeZone; /* time difference */
    U16 CityName;       /* city name in English. */
    U16 CityAbbr;       /* abbreviation name of city. */
    U16 CityX;          /* the X coordinate of city. */
    U16 CityY;          /* the Y coordinate of city. */
    U8 MapIndex;		/* map index of all map array */
    U8 unused1;			/* unused parameter */
    U8 unused2;			/* unused parameter */
    U8 unesed3;			/* unused parameter */
} TimeZoneStruct;

typedef struct
{
    FLOAT CityTimeZone; 
    U8 CityIndex;
} DefaultCityStruct;

/* world clock global structure */
typedef struct
{
#ifndef __MMI_WC_TZ_SUPPORT__
	U8 time_string[32];		/* current time string of selected city */
	U8 date_string[32];		/* current date string of selected city */
	MMI_ID_TYPE image_idx;	/* sun or moon icon display */
#else
    FLOAT CurrTZ;			/* current home city time zone */
    U8 highlightIndex;		/* current high light index in world clock map */
#endif
    U8 CurrMap;         /* index of current image map */
    U8 CurrCityIndex;   /* index of current selected city in world map */
    MMI_BOOL running_flag;/* flag for screen */
#ifdef __MMI_DUAL_CLOCK__
    U8 FrnCityIdx;		/* foreign city index */
#endif
#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
    U8 CurrHiliteSublcd;	/* high light item index of sub LCD */
    U8 CurrHiliteCity;  /* for multitap selection of cities */
    U8 City1;			/* city 1 index in sub LCD world clock */
    U8 City2;			/* city 2 index in sub LCD world clock */
#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
#ifdef __MMI_WORLDCLOCK_DST__
    U8 DSTForeign;		/* day light saving flag */
#endif 
 
    MMI_ID   grp_id;
    MMI_BOOL sel_scrn;
    U16 user_tag;
} wc_context_struct;


/* 
 * Extern Global Variable
 */
/* time zone information created by MCT tool */
extern const TimeZoneStruct TimeZoneData[];

extern const DefaultCityStruct DefaultCityData[];

/*****************************************************************************
* FUNCTION
*  mmi_wc_get_size
* DESCRIPTION
*  This function get world clock city number
* PARAMETERS
*  void
* RETURNS
*  current city number support
 *****************************************************************************/
extern U8 mmi_wc_get_size(void);

/* define city number with function provided by MCT tool */
#define NUMBER_OF_CITY mmi_wc_get_size()

#define MMI_WC_SET_HOME_CITY    1		/* mark current operator is set home city */
#define MMI_WC_CHECK_HOME_CITY    0		/* mark current operator is check home city */

#if defined(__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)
/* world clock global context */
extern wc_context_struct g_wc_cntx;

/* point to world clock global context */
extern wc_context_struct* const mmi_wc_cntx_p;
#endif 

/* 
 * Extern Global Function
 */
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
extern void WcInit(void);

extern U8 mmi_wc_get_default_city_size(void);

extern void WcGenerateTimeZoneIndex(void);

/*****************************************************************************
* FUNCTION
*  GetTimeZone
* DESCRIPTION
*  get time zone with city index
* PARAMETERS
*  cityIndex : [IN] city index 
* RETURNS
*  time zone of city 
 *****************************************************************************/
extern FLOAT GetTimeZone(U8 cityIndex);

extern CHAR* mmi_wc_get_home_city(void);
extern void WcSetCityIndex(U16 index);

#if defined (__MMI_NITZ_TZ_SUPPORT__) || defined (__MMI_WC_TZ_SUPPORT__)
extern void mmi_wc_set_default_city_for_tz(void);
#endif

/*****************************************************************************
* FUNCTION
*  mmi_wc_set_home_city_from_nitz
* DESCRIPTION
*  set home city with time zone in NITZ message 
* PARAMETERS
*  nitz_tz : [IN] time zone in NITZ message 
*  is_set  : [IN] check time zone or set home city with time zone
* RETURNS
*  home city index 
 *****************************************************************************/
#ifdef __MMI_NITZ_TZ_SUPPORT__
extern S16 mmi_wc_set_home_city_from_nitz(S16 nitz_tz, U8 is_set);
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 
#ifdef __MMI_WORLD_CLOCK__
extern void HighlightWCMenu(void);
extern void HighlightWcBrowseCity(void);
extern void mmi_wc_set_curr_gid(mmi_id gid);
extern void EntryWcBrowseCity(void);
#endif /* HighlightWCMenu */

#ifdef __MMI_WORLD_CLOCK_SUBLCD_SETTING__
extern  void HighlightWcSubLcd(void);
/*****************************************************************************
 * FUNCTION
 *  ReadValueCityNVRAM
 * DESCRIPTION
 *  Read city values from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReadValueCityNVRAM(void);

#endif

extern void mmi_wc_entry_city_scrn(void);
#endif /* _MMI_WORLDCLOCK_H */ 

