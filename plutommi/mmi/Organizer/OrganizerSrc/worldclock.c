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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * Worldclock.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements world clock application.
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
 ****************************************************************************/
 /**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Worldclock.c
   Author:        Vandana M
   Date Created:  June-14-2003
   Contains:      World Clock
**********************************************************************************/
#include "MMI_features.h"

#ifndef _MMI_WORLDCLOCK_C
#define _MMI_WORLDCLOCK_C

/*  Include: MMI header file */
#include "OrganizerDef.h"
#include "worldclock.h"
//#include "IdleAppProt.h"
#include "idleGprot.h"
#include "CustDataProts.h"
#include "worldclock.h"
#include "OrganizerDef.h"
#include "CommonScreens.h"
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#ifdef __MMI_WORLDCLOCK_DST__
#include "PhoneSetup.h"
#endif /* __MMI_WORLDCLOCK_DST__ */ 

#include "MenuCuiGprot.h"
#include "..\\..\\..\\CUI\\WorldClockCui\\WorldClockCui.h"

    
    #include "mmi_frm_mem_gprot.h"
    #include "mmi_rp_app_worldclock_def.h"
    #include "MMIDataType.h"
    #include "custom_mmi_default_value.h"
    #include "string.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "CustDataRes.h"
    #include "wgui_categories_util.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "CommonScreensResDef.h"
    #include "AlertScreen.h"
    #include "gui_data_types.h"
    #include "kal_non_specific_general_types.h"
    #include "mmi_frm_events_gprot.h"
    #include "app_buff_alloc.h"
    #include "wgui_categories_clock.h"
    #include "wgui_categories_defs.h"
    #include "DateTimeType.h"
    #include "app_datetime.h"
    #include "gui_typedef.h"
    #include "Unicodexdcl.h"
    #include "stdio.h"
    #include "mmi_frm_gprot.h"
    #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "kal_release.h"
/*****************************************************************************
 * Define
 ****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
#define WC_PEN_GAP   3
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_TIMEZONE_SETTING__
#define WC_NUM_CITY STR_TOTAL_NUM_CITY - STR_WCLOCK_CITY_NONE
#else
#define WC_NUM_CITY 77
#endif

#ifdef __MMI_WC_TZ_SUPPORT__
#define WC_INDEX_NUM 		  2
#define WC_MAX_INDEX_INFO_LEN 60

#define WC_TZ_INDEX    		0
#define WC_CITY_INDEX  		1
#define WC_TZ_SIGN_POS 		3
#define WC_MAX_TZ_STR_LEN   6


#define WC_GMT_LEN  (WC_TZ_SIGN_POS * sizeof(UI_character_type))

/* dt format token */
#define WC_SYM_COMMA    (UI_character_type)','
#define WC_SYM_POSITIVE (UI_character_type)'+'
#define WC_SYM_NEGATIVE (UI_character_type)'-'
#define WC_SYM_SPACE    (UI_character_type)' '
#endif /* __MMI_WC_TZ_SUPPORT__ */

#define WC_DEFAULT_TZ_NUM   37

/* Smail screen will not show status bar*/
#if defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_128X128__)
#ifndef __MMI_WC_NO_STATUSBAR__
#define __MMI_WC_NO_STATUSBAR__
#endif
#endif  /*__MMI_MAINLCD_128X160__ */

#define SAFE_MFREE(p) {if(p){OslMfree(p);p=NULL;}}

/*****************************************************************************
 * Typedef 
 ****************************************************************************/

/****************************************************************************
 * Local Variable
 ****************************************************************************/
static U8 gWcTimeZoneIndex[WC_NUM_CITY];
static FLOAT WcTimeZoneDiff(U8 City1, U8 City2);

/*****************************************************************************
 * Local Function
 ****************************************************************************/
static void mmi_wc_is_dst(void);

#ifdef __MMI_WORLD_CLOCK__
extern void HighlightWCMenu(void);
static void WcEntryDstSelectionScrn(void);
static void WcEntryDST(void);
static void WcDSTBackAndSave(void);
static U8 mmi_wc_get_city_index(void);
static void ExitWcBrowseCity(void);
static void WcEntryDST(void);
static void WcHandleRSK(void);
static mmi_ret mmi_wc_main_group_proc(mmi_event_struct* evt);
static  U8 WcGetCityPosition(U8 index);
static  void WcDSTEndKeyHandler(void);

#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
extern  void HighlightWcSubLcd(void);
static void EntryWcSubLcd(void);
static void EntryWcSelectCity(void);
static void EntryWcApp(void);
static void WcHintCity1(U16 index);
static void WcHintCity2(U16 index);
#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
#ifdef __MMI_WC_TZ_SUPPORT__
static void mmi_wc_get_index_info(void* info);
static void mmi_wc_get_foreign_city_dt(MYTIME* dt);
static void mmi_wc_leftkey_handler(U8 index_num);
static void mmi_wc_rightkey_handler(U8 index_num);
static U8 mmi_wc_default_city_of_tz(FLOAT tz);
static void mmi_wc_dt_format(MYTIME* dt, U8* dtString);
static void mmi_wc_paint_pen_handler(S32 x, S32 y, S32 event_type);
//static U8 mmi_wc_entry_from_phnset(void);
static void mmi_wc_get_tz_string(FLOAT tz, CHAR* outStr);
static void mmi_wc_get_city_string(U8 cityIndex);

#else /* __MMI_WC_TZ_SUPPORT__ */
static void mmi_wc_get_index_info(void *index_info);
static void mmi_wc_get_string_info(U8 city_idx);
static void mmi_wc_leftkey_handler(void);
static void mmi_wc_rightkey_handler(void);

#ifdef __MMI_TOUCH_SCREEN__
static void mmi_wc_paint_pen_handler(S32 x, S32 y);
#endif /* __MMI_TOUCH_SCREEN__ */

#endif /* #ifdef __MMI_WC_TZ_SUPPORT__ */ 

static void mmi_wc_select_scrn_lsk(void);
static void mmi_wc_select_scrn_rsk(void);

#endif /* __MMI_WORLD_CLOCK__ */ 

/*****************************************************************************
 * Global Variable
 ****************************************************************************/
#if defined(__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)
wc_context_struct g_wc_cntx;
wc_context_struct* const mmi_wc_cntx_p = &g_wc_cntx;
#endif 

#ifdef __MMI_WC_TZ_SUPPORT__
static U8 *gIndexInfo[WC_INDEX_NUM];
extern U8 Cat230HighlightedIndex;
static U8 *homeTime;
static U8 *foreTime;
#endif

#if defined (__MMI_NITZ_TZ_SUPPORT__) || defined (__MMI_WC_TZ_SUPPORT__)
const S16 validTZ[WC_DEFAULT_TZ_NUM] =
    { -48, -44, -40, -38, -36, -34,
      -32, -28, -24, -20, -16, -14, 
      -12, -8, -4, 0, 4, 8, 12, 14, 
      16, 18, 20, 22, 23, 24, 26, 28, 
      32, 36, 38, 40, 42, 44, 46, 48, 49};

U8 gWcDefaultCityForTZ[WC_DEFAULT_TZ_NUM];
#endif /* __MMI_NITZ_TZ_SUPPORT__ */

U8 g_dst;
/*****************************************************************************
 * Global Function
 ****************************************************************************/
extern U8 PhnsetGetHomeCity(void);
BOOL ATSetHomeCity(U8 CityIndex);

#ifndef __MMI_WC_TZ_SUPPORT__
#ifdef __MMI_TOUCH_SCREEN__
extern void RegisterCat231PaintPenEventHandler(void (*AppPaintPenEventHandler) (S32 x, S32 y));
#endif
extern void Cat231UpdateDT(void);
extern void ExitCategory231Screen(void);
#endif /* __MMI_WC_TZ_SUPPORT__ */

#ifdef __MMI_DUAL_CLOCK__
extern void PhnsetSetForeignCity(void);
extern U8 PhnsetGetForeignCity(void);
#endif
extern  U8 mmi_wc_entry_from_phnset(void);

#if defined(__MMI_APP_MANAGER_SUPPORT__) && defined(__MMI_WORLD_CLOCK__)
MMI_ID mmi_world_clock_launch(void* param, U32 param_size)
{

    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_WC, mmi_wc_main_group_proc, &g_wc_cntx.grp_id);
    g_wc_cntx.grp_id = mmi_frm_group_enter(GRP_ID_WC, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_wc_entry_city_scrn();
    return g_wc_cntx.grp_id;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  WcInit
 * DESCRIPTION
 *  Initailze world clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 currentHomeCity;
    S16 currentTimeZone;
#ifdef __MMI_DUAL_CLOCK__
    U8 currentFrnCity;
    S16 currentFrnTimeZone;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WORLD_CLOCK__) || defined(__MMI_VRE_WORLD_CLOCK__)
    memset(&g_wc_cntx, 0, sizeof(wc_context_struct));
    g_wc_cntx.CurrCityIndex = 0xff;
    g_wc_cntx.grp_id = GRP_ID_INVALID;

#endif /* __MMI_WORLD_CLOCK__ */ 
    WcGenerateTimeZoneIndex();
	mmi_wc_is_dst();

#if defined (__MMI_NITZ_TZ_SUPPORT__) || defined (__MMI_WC_TZ_SUPPORT__)
    mmi_wc_set_default_city_for_tz();
#endif 

    currentHomeCity = PhnsetGetHomeCity() + 1;    
    currentTimeZone = (S16)(TimeZoneData[currentHomeCity].CityTimeZone * 4);
    //WriteValue(NVRAM_TIMEZONE, &currentTimeZone, DS_SHORT, &error);
	WriteValueSlim(NVRAM_TIMEZONE, &currentTimeZone, DS_SHORT);
#ifdef __MMI_DUAL_CLOCK__
    currentFrnCity = PhnsetGetForeignCity() + 1;    
    currentFrnTimeZone = (S16)(TimeZoneData[currentFrnCity].CityTimeZone * 4);
    //WriteValue(NVRAM_FRN_TIMEZONE, &currentFrnTimeZone, DS_SHORT, &error);
	WriteValueSlim(NVRAM_FRN_TIMEZONE, &currentFrnTimeZone, DS_SHORT);
#endif /* __MMI_DUAL_CLOCK__ */
}

#define WC_UTILITY_FUNCTION


/*****************************************************************************
 * FUNCTION
 *  GetTimeZone
 * DESCRIPTION
 *  Return the time zone of a city
 * PARAMETERS
 *  cityIndex       [IN]        Index of city
 * RETURNS
 *  Time zone
 *****************************************************************************/
FLOAT GetTimeZone(U8 cityIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_TIMEZONE_SETTING__
    return TimeZoneData[cityIndex + 1].CityTimeZone;
    #else
    return 0;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  WcGenerateTimeZoneIndex
 * DESCRIPTION
 *  Generate indexing table of world clock. The table is sorted by time zone and x/y-coordinate.
 * PARAMETERS
 *  void
 *  nIndex(?)       [IN]        Index of item.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void WcGenerateTimeZoneIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    U8 tmp;
    U8 swap = FALSE;
    U8 index1, index2;
    U8 num_city = NUMBER_OF_CITY;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_city - 1; i++)
    {
        gWcTimeZoneIndex[i] = i + 1;
    }

    for (i = 0; i < num_city - 1; i++)
    {
        for (j = 0; j < (num_city - 1) - i - 1; j++)
        {
            index1 = gWcTimeZoneIndex[j + 1];
            index2 = gWcTimeZoneIndex[j];
            if (TimeZoneData[index1].CityTimeZone < TimeZoneData[index2].CityTimeZone)
            {
                swap = TRUE;
            }
            else if (TimeZoneData[index1].CityTimeZone == TimeZoneData[index2].CityTimeZone)
            {
                if (TimeZoneData[index1].CityX < TimeZoneData[index2].CityX)
                {
                    swap = TRUE;
                }
                else if (TimeZoneData[index1].CityX == TimeZoneData[index2].CityX)
                    if (TimeZoneData[index1].CityY < TimeZoneData[index2].CityY)
                    {
                        swap = TRUE;
                    }
            }

            if (swap)
            {
                tmp = gWcTimeZoneIndex[j];  /* swap a[j] and a[j+1]      */
                gWcTimeZoneIndex[j] = gWcTimeZoneIndex[j + 1];
                gWcTimeZoneIndex[j + 1] = tmp;
                swap = FALSE;
            }
        }
    }
}


#if defined (__MMI_NITZ_TZ_SUPPORT__) || defined (__MMI_WC_TZ_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_set_default_city_for_tz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_set_default_city_for_tz(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 count = 0;
    FLOAT tz;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUMBER_OF_CITY; i++)
    {
        tz = (FLOAT) validTZ[count] / (FLOAT) 4;
        if (TimeZoneData[gWcTimeZoneIndex[i]].CityTimeZone == tz)
        {
            gWcDefaultCityForTZ[count] = gWcTimeZoneIndex[i];
            count++;
        }
        else if (TimeZoneData[gWcTimeZoneIndex[i]].CityTimeZone > tz)
        {
            count++;
            /* find the matched timezone for this city, therefore decrease first to balence i++ */
            i--;
        }

		if (count >= WC_DEFAULT_TZ_NUM)
		{
			break;
		}
    }
}
#endif

#ifdef __MMI_NITZ_TZ_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_set_home_city_from_nitz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nitz_tz     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_wc_set_home_city_from_nitz(S16 nitz_tz, U8 is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 default_city_size = 0;
    U32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	default_city_size = mmi_wc_get_default_city_size();

	/* search default city index and set to default city index */
	for (count = 0; count < default_city_size; count++)
	{
		if (((S16)(DefaultCityData[count].CityTimeZone * 4) == (S16)nitz_tz)
			&& ((S16)(GetTimeZone(PhnsetGetHomeCity()) * 4) != nitz_tz)
			&& DefaultCityData[count].CityIndex 		
			&& is_set == 1)
		{
			ATSetHomeCity(DefaultCityData[count].CityIndex);
			break;
		}
	}

    for (count = 0; count < WC_DEFAULT_TZ_NUM; count++)
    {
        if (nitz_tz == validTZ[count])
        {
            if (is_set == 1 && ((S16)(GetTimeZone(PhnsetGetHomeCity()) * 4) != nitz_tz))
            {
                ATSetHomeCity(gWcDefaultCityForTZ[count]);
            }
            break;
        }
    }

    /* There's no matched city */
    if (count == WC_DEFAULT_TZ_NUM)
    {
        return -1;
    }
    else
    {
        return (S32) gWcDefaultCityForTZ[count];
    }

}
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_home_city
 * DESCRIPTION
 *  Return string of home city
 * PARAMETERS
 *  void
 * RETURNS
 *  String pointer to home city name
 *****************************************************************************/
CHAR *mmi_wc_get_home_city(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetString(TimeZoneData[PhnsetGetHomeCity() + 1].CityName);
}


/*****************************************************************************
 * FUNCTION
 *  WcSetCityIndex
 * DESCRIPTION
 *  Set current city.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WcSetCityIndex(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WORLD_CLOCK__)
    g_wc_cntx.CurrCityIndex = (U8) index;
#ifdef __MMI_WC_TZ_SUPPORT__
    g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
#endif /*__MMI_WC_TZ_SUPPORT__*/
#endif 
}

#ifdef __MMI_WORLD_CLOCK__

#define WC_BROWSE_CITY

/*****************************************************************************
 * FUNCTION
 *  HighlightWCMenu
 * DESCRIPTION
 *  Highlight handler of World Clock menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_CLOCK__
	g_phnset_cntx_p->city_flag = 2;
#endif

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
    SetLeftSoftkeyFunction(EntryWcApp, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(EntryWcApp, KEY_EVENT_UP);
#else /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
    SetLeftSoftkeyFunction(EntryWcBrowseCity, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(EntryWcBrowseCity, KEY_EVENT_UP);
#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightWcBrowseCity
 * DESCRIPTION
 *  Highlight handler of browse city menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcBrowseCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_CLOCK__
	g_phnset_cntx_p->city_flag = 2;
#endif

    SetLeftSoftkeyFunction(EntryWcBrowseCity, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(EntryWcBrowseCity, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_main_group_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_wc_main_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 grp_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        grp_id = *(U16*)evt->user_data;
        mmi_frm_group_close(grp_id);
        break;
        
#ifdef __MMI_WORLDCLOCK_DST__
    case EVT_ID_ALERT_QUIT:
    {
        mmi_alert_result_evt_struct *alert_evt = (mmi_alert_result_evt_struct *)evt;
        U16 user_tag = *(U16 *)alert_evt->user_tag;
        if (user_tag == STR_GLOBAL_DONE)
        {
            mmi_frm_group_close(GRP_ID_WC_DST);        
        }
        
        break;
    } 
    /*
    case EVT_ID_POPUP_QUIT:
        {
            grp_id = *(U16 *)evt->user_data;
            mmi_frm_group_close(grp_id);
        }        
        break; */

      case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

            if (menu_evt->parent_menu_id == MENU_ID_WC_DST_OPT)
            {
                mmi_menu_id menu_list[1] = {MENU_ID_WC_DST_SETTING};

                cui_menu_set_default_title_image(menu_evt->sender_id, (UI_image_type)get_image(GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU)));
                cui_menu_set_default_title_string(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));
                cui_menu_set_currlist(menu_evt->sender_id, 1, menu_list);
                cui_menu_set_currlist_left_softkey(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OK));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WC_DST_SETTING, (WCHAR*)GetString(STR_WORLD_CLOCK_DST_FOREIGN));
             }
             else if (menu_evt->parent_menu_id == MENU_ID_WC_DST_CFG_OPT)
            {
                mmi_menu_id menu_list[2] = {MENU_ID_WC_DST_CFG_ON, MENU_ID_WC_DST_CFG_OFF};
                
		cui_menu_set_default_title_image(menu_evt->sender_id, (UI_image_type)get_image(GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU)));         
                cui_menu_set_default_title_string(menu_evt->sender_id, (WCHAR*)GetString(STR_WORLD_CLOCK_DST_FOREIGN));
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                cui_menu_set_currlist(menu_evt->sender_id, 2, menu_list);
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WC_DST_CFG_ON, (WCHAR*)GetString(STR_GLOBAL_ON));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WC_DST_CFG_OFF, (WCHAR*)GetString(STR_GLOBAL_OFF));
                
                if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                {
                if (g_wc_cntx.DSTForeign == 1)
                {
                    cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, MENU_ID_WC_DST_CFG_ON);
                }
                else
                {
                    cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, MENU_ID_WC_DST_CFG_OFF);
                }
                }
                
             }
        }
        break;
        
    case EVT_ID_CUI_MENU_LIST_EXIT:
        {
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            if (menu_evt->parent_menu_id == MENU_ID_WC_DST_OPT)
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_WC_DST_SETTING)
                {
                    WcEntryDstSelectionScrn();
                }
            }
            /* channel list option menu */
            else if (menu_evt->parent_menu_id == MENU_ID_WC_DST_CFG_OPT)
            {
                if (menu_evt->highlighted_menu_id == MENU_ID_WC_DST_CFG_ON)
                {
                    g_wc_cntx.DSTForeign = 1;
                }
                else if (menu_evt->highlighted_menu_id == MENU_ID_WC_DST_CFG_OFF)
                {
                    g_wc_cntx.DSTForeign = 0;
                }
                
                WcDSTBackAndSave();
            }
        }
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
			cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
            cui_menu_close(menu_evt->sender_id);
        }
        break;
        
#endif /* __MMI_WORLDCLOCK_DST__ */

    default:
        break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_group_leave_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_wc_group_leave_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        g_wc_cntx.CurrCityIndex = 0xff;
        g_wc_cntx.running_flag = MMI_FALSE;
        g_wc_cntx.grp_id = GRP_ID_INVALID;
        break;
        
    default:
        break;
    }
    
    return MMI_RET_OK;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_set_curr_gid
 * DESCRIPTION
 *  Display browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_set_curr_gid(mmi_id gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_wc_cntx.grp_id = gid;
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcBrowseCity
 * DESCRIPTION
 *  Display browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcBrowseCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_WC, mmi_wc_main_group_proc, &g_wc_cntx.grp_id);
    mmi_frm_group_enter(GRP_ID_WC, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_wc_cntx.grp_id = GRP_ID_WC;
    
    mmi_wc_entry_city_scrn(); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_set_city_index
 * DESCRIPTION
 *  Display browse city screen
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_wc_get_city_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WC_TZ_SUPPORT__
    //S16 error;
    S16 tmpTimeZone;
#ifdef __MMI_DUAL_CLOCK__
    S16 tmpFrmTZ;
#endif
#endif /* __MMI_WC_TZ_SUPPORT__ */

    U8 city_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (PhnsetGetHomeCity() != 0xff)
	{
		city_index = PhnsetGetHomeCity() + 1;
	}
	else
	{
		city_index = 1;
	}
#ifdef __MMI_WC_TZ_SUPPORT__
    //ReadValue(NVRAM_TIMEZONE, &tmpTimeZone, DS_SHORT, &error);
	ReadValueSlim(NVRAM_TIMEZONE, &tmpTimeZone, DS_SHORT);
    g_wc_cntx.CurrTZ = (FLOAT)tmpTimeZone / 4;
    
#ifdef __MMI_DUAL_CLOCK__
	if (mmi_wc_entry_from_phnset() == 2)
	{
		if (PhnsetGetForeignCity() != 0xff)
		{
			g_wc_cntx.FrnCityIdx= PhnsetGetForeignCity() + 1;
		}
		else
		{
			g_wc_cntx.FrnCityIdx = 0;
		}
		city_index = g_wc_cntx.FrnCityIdx;

        //ReadValue(NVRAM_FRN_TIMEZONE, &tmpFrmTZ, DS_SHORT, &error);		
		ReadValueSlim(NVRAM_FRN_TIMEZONE, &tmpFrmTZ, DS_SHORT);
        g_wc_cntx.CurrTZ = (FLOAT)tmpFrmTZ / 4;
	}
#endif /* __MMI_DUAL_CLOCK__ */

#endif /*__MMI_WC_TZ_SUPPORT__*/

    return city_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_entry_city_scrn
 * DESCRIPTION
 *  Display browse city screen
 * PARAMETERS
 *  entry_func      [IN]        
 *  exit_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_entry_city_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WC_TZ_SUPPORT__
    U8 *guiBuffer;
    U8 highlight_index;
#endif /* __MMI_WC_TZ_SUPPORT__ */

    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            g_wc_cntx.grp_id, 
            SCR_ID_WC_BROWSE_CITY, 
            ExitWcBrowseCity, 
            mmi_wc_entry_city_scrn, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    mmi_frm_scrn_set_leave_proc(g_wc_cntx.grp_id, SCR_ID_WC_BROWSE_CITY, mmi_wc_group_leave_proc);

    g_wc_cntx.CurrMap = 0xff;
    g_wc_cntx.running_flag = MMI_TRUE;

    /* The first time entry this screen */
    if (g_wc_cntx.CurrCityIndex == 0xff)
    {
        g_wc_cntx.CurrCityIndex = mmi_wc_get_city_index();
    }

#ifdef __MMI_WORLDCLOCK_DST__
    //ReadValue(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE, &error);
	ReadValueSlim(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE);

    if (g_wc_cntx.DSTForeign == 0xff)
    {
        g_wc_cntx.DSTForeign = 0;
    }
#endif /* __MMI_WORLDCLOCK_DST__ */

#ifndef __MMI_WC_TZ_SUPPORT__	

#ifdef __MMI_TOUCH_SCREEN__
	RegisterCat231PaintPenEventHandler(mmi_wc_paint_pen_handler);
#endif

#ifdef __MMI_WORLDCLOCK_DST__
	EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
#endif /* __MMI_WORLDCLOCK_DST__ */

	ShowCategory231Screen(mmi_wc_leftkey_handler, 
						  mmi_wc_rightkey_handler, 
						  mmi_wc_get_index_info,
						#ifdef __MMI_WC_NO_STATUSBAR__
						  MMI_FALSE
						#else
						  MMI_TRUE
						#endif
						  );

#else /*#ifndef  __MMI_WC_TZ_SUPPORT__*/

    gIndexInfo[WC_TZ_INDEX] = OslMalloc(WC_MAX_INDEX_INFO_LEN);
    gIndexInfo[1] = OslMalloc(WC_MAX_INDEX_INFO_LEN);
    memcpy(gIndexInfo[WC_TZ_INDEX], (CHAR*) GetString(STR_WORLD_CLOCK_GMT), WC_GMT_LEN);
    homeTime = OslMalloc(WC_MAX_INDEX_INFO_LEN);
    foreTime = OslMalloc(WC_MAX_INDEX_INFO_LEN);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    if (guiBuffer == NULL)  /* not goback from history */
    {
        highlight_index = 0;        
    }    
    else
    {
        highlight_index = g_wc_cntx.highlightIndex;
    }
    
    /* Check if the time zone and city are matched */
    if (g_wc_cntx.CurrTZ != TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone && g_wc_cntx.CurrCityIndex != 0)
    {
        g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);
        ATSetHomeCity((U8) (g_wc_cntx.CurrCityIndex));
		g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
    }

    /* get time zone string */
    mmi_wc_get_tz_string(g_wc_cntx.CurrTZ, (CHAR*) &gIndexInfo[WC_TZ_INDEX][WC_GMT_LEN]);

    /* get Home city */
    mmi_wc_get_city_string(g_wc_cntx.CurrCityIndex);
    
    
#ifdef __MMI_TOUCH_SCREEN__
    RegisterCat230PaintPenEventHandler(mmi_wc_paint_pen_handler);
#endif

	if (g_wc_cntx.sel_scrn)
	{
		EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	}
	else
	{
#ifdef __MMI_WORLDCLOCK_DST__
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
#endif /* __MMI_WORLDCLOCK_DST__ */
	}

    ShowCategory230Screen(
        (U8*) GetString(STR_WORLD_CLOCK_TITLE),
        2,
        gIndexInfo,
        highlight_index,
        CAT230_WC_DT,
        mmi_wc_leftkey_handler,
        mmi_wc_rightkey_handler,    /* Cat230RedrawPaint_WC, */
        mmi_wc_get_index_info);

#endif /* __MMI_WC_TZ_SUPPORT__ */ 

#if 0
#ifdef __MMI_WC_TZ_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_CLOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_CLOCK__ */
/* under construction !*/
#endif /* __MMI_WC_TZ_SUPPORT__ */ 
/* under construction !*/
#endif
    if (g_wc_cntx.sel_scrn)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_wc_select_scrn_lsk, KEY_EVENT_UP);        /* set home city */
		SetCenterSoftkeyFunction(mmi_wc_select_scrn_lsk, KEY_EVENT_UP);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(mmi_wc_select_scrn_rsk, KEY_EVENT_UP);
    }
    else
    {
    #ifdef __MMI_WORLDCLOCK_DST__
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(WcEntryDST, KEY_EVENT_UP);
		SetCenterSoftkeyFunction(WcEntryDST, KEY_EVENT_UP);
    #else /* __MMI_WORLDCLOCK_DST__ */ 
        ChangeLeftSoftkey(0, 0);
    #endif /* __MMI_WORLDCLOCK_DST__ */
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
        SetRightSoftkeyFunction(WcHandleRSK, KEY_EVENT_UP);
    }
}


#ifdef __MMI_WC_TZ_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_index_info
 * DESCRIPTION
 *  This function is used to get the index information.
 * PARAMETERS
 *  index_info      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_wc_get_index_info(void *index_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYTIME currTime, foreignTime;
    cat230_paint_wc_info_struct *index_infomation = (cat230_paint_wc_info_struct*) index_info;
    U8 homeCity = PhnsetGetHomeCity() + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&currTime, 0, sizeof(MYTIME));
    memset(&foreignTime, 0, sizeof(MYTIME));

    index_infomation->static_x = TimeZoneData[homeCity].CityX;
    index_infomation->static_y = TimeZoneData[homeCity].CityY;

    if (g_wc_cntx.CurrCityIndex == 0)
    {
        index_infomation->dynamic_x = -1;
        index_infomation->dynamic_y = -1;
    }
    else
    {
        index_infomation->dynamic_x = TimeZoneData[g_wc_cntx.CurrCityIndex].CityX;
        index_infomation->dynamic_y = TimeZoneData[g_wc_cntx.CurrCityIndex].CityY;
    }

    index_infomation->hint_string = (U8*) GetString(STR_WORLD_CLOCK_LOCAL);
    index_infomation->city_string = (U8*) GetString(TimeZoneData[homeCity].CityName);

    /* get date/time of home city */
    DTGetRTCTime(&currTime);
    mmi_wc_dt_format(&currTime, homeTime);
    index_infomation->static_string = homeTime;
    /* index_infomation->static_string = (U8*)GetString(STR_WORLD_CLOCK_LOCAL); */

    mmi_wc_get_foreign_city_dt(&foreignTime);
    mmi_wc_dt_format(&foreignTime, foreTime);
    index_infomation->dynamic_string = foreTime;
    /* index_infomation->dynamic_string = (U8*)GetString(STR_WORLD_CLOCK_LOCAL); */

    index_infomation->need_redraw = MMI_TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_dt_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dt              [?]     
 *  dtString        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_dt_format(MYTIME *dt, U8 *dtString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ascii[WC_MAX_INDEX_INFO_LEN], UniStr[WC_MAX_INDEX_INFO_LEN];
    U8 sizeT = 0, sizeD = 0;
    UI_character_type separate = WC_SYM_COMMA;
    UI_character_type whitespace = WC_SYM_SPACE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dtString, 0, WC_MAX_INDEX_INFO_LEN);
    memset(UniStr, 0, WC_MAX_INDEX_INFO_LEN);
    memset(ascii, 0, WC_MAX_INDEX_INFO_LEN);

    date_string(dt, (UI_string_type) dtString, DT_IDLE_SCREEN);
    //mmi_ucs2_to_asc((CHAR*) ascii, (CHAR*) dtString);
    //sizeD = strlen((CHAR*) ascii);
    sizeD = mmi_ucs2strlen((CHAR*) dtString);

    memcpy(&(dtString[sizeD * 2]), &separate, sizeof(UI_character_type));
    sizeD++;
    memcpy(&(dtString[sizeD * 2]), &whitespace, sizeof(UI_character_type));
    sizeD++;

    memset(ascii, 0, WC_MAX_INDEX_INFO_LEN);
    time_string(dt, (UI_string_type) UniStr, DT_IDLE_SCREEN);
    //mmi_ucs2_to_asc((CHAR*) ascii, (CHAR*) UniStr);
    //sizeT = strlen((CHAR*) ascii);
    sizeT = mmi_ucs2strlen((CHAR*) UniStr);
    memcpy(&(dtString[sizeD * 2]), UniStr, sizeT * 2);

    /* mmi_ucs2_to_asc((CHAR*) &(dtString[size]), (CHAR*) UniStr); */

    /*
     * time_string(&dt, (UI_string_type) UniStr, DT_IDLE_SCREEN);
     * mmi_ucs2_to_asc((CHAR*) dtString, (CHAR*) UniStr);
     * size = strlen(dtString);
     * date_string(&dt, (UI_string_type)UniStr, DT_IDLE_SCREEN);
     * mmi_ucs2_to_asc((CHAR*) &(dtString[size]), (CHAR*) UniStr);
     * mmi_asc_to_ucs2(out_buffer, ansii_str);
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_foreign_city_dt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dt      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_get_foreign_city_dt(MYTIME *dt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime;
    U8 HomeCity;
    FLOAT TimeDiff;
    U8 TimeFlag = 0;
    S32 temp;

#ifdef __MMI_WORLDCLOCK_DST__
    MYTIME dstTime;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get time zone difference */
    HomeCity = PhnsetGetHomeCity() + 1;
    /* TimeDiff = WcTimeZoneDiff(g_wc_cntx.CurrCityIndex, HomeCity); */
    TimeDiff = g_wc_cntx.CurrTZ - TimeZoneData[HomeCity].CityTimeZone;

    memset(&incTime, 0, sizeof(MYTIME));
    DTGetRTCTime(dt);

    if (TimeDiff < 0)
    {
        TimeDiff = TimeDiff * (-1);
        TimeFlag = 1;
    }

    temp = (S32) (TimeDiff * 60);

    incTime.nDay = (U8) (TimeDiff / 24);
    incTime.nHour = ((S32) TimeDiff) % 24;
    incTime.nMin = temp % 60;

    if (TimeFlag)   /* decrement */
    {
        DecrementTime(*dt, incTime, dt);
    }
    else
    {
        IncrementTime(*dt, incTime, dt);
    }

#ifdef __MMI_WORLDCLOCK_DST__
    memset(&dstTime, 0, sizeof(MYTIME));
    dstTime.nHour = 1;
    /* both date light saving is on or off */
    if ((g_wc_cntx.DSTForeign && g_phnset_cntx_p->currentDST) ||
        (g_wc_cntx.DSTForeign == 0 && g_phnset_cntx_p->currentDST == 0) ||
        (g_wc_cntx.CurrCityIndex == HomeCity)) 
    {
        /* do nothing */
    }
    else if (g_phnset_cntx_p->currentDST)   /* only home city turns on DST */
    {
        DecrementTime(*dt, dstTime, dt);
    }
    else if (g_wc_cntx.DSTForeign)  /* only foreign city turns on DST */
    {
        IncrementTime(*dt, dstTime, dt);
    }
#endif /* __MMI_WORLDCLOCK_DST__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_leftkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_leftkey_handler(U8 index_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index_num)
    {
        case WC_TZ_INDEX:
            if (g_wc_cntx.CurrTZ <= -12)
            {
                g_wc_cntx.CurrTZ = 12;
            }
            else
            {
                g_wc_cntx.CurrTZ--;
            }
            g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);

            /* Modify the current time zone to the default city's time zone, ex: GMT 5.5 */
            if (g_wc_cntx.CurrTZ != TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone && g_wc_cntx.CurrCityIndex != 0)
            {
                g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            }
            break;
        case WC_CITY_INDEX:

            /* a time zone without default city is selected as home city */
            if (g_wc_cntx.CurrCityIndex == 0)
            {
                while (g_wc_cntx.CurrCityIndex == 0)
                {
                    if (g_wc_cntx.CurrTZ <= -12)
                    {
                        g_wc_cntx.CurrTZ = 12;
                    }
                    else
                    {
                        g_wc_cntx.CurrTZ--;
                    }
                    g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);
                }
                break;
            }

            curr_index = WcGetCityPosition(g_wc_cntx.CurrCityIndex);
            if (curr_index == 0)
            {
                curr_index = (NUMBER_OF_CITY - 2);
            }
            else
            {
                curr_index--;
            }
            g_wc_cntx.CurrCityIndex = gWcTimeZoneIndex[curr_index];
            g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            break;
    }

    /* get time zone string */
    mmi_wc_get_tz_string(g_wc_cntx.CurrTZ, (CHAR*) & gIndexInfo[WC_TZ_INDEX][WC_GMT_LEN]);
    mmi_wc_get_city_string(g_wc_cntx.CurrCityIndex);
 
    SetCat230IndexInfo(WC_TZ_INDEX, (U8*) gIndexInfo[WC_TZ_INDEX]);
    SetCat230IndexInfo(WC_CITY_INDEX, (U8*) gIndexInfo[WC_CITY_INDEX]);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_rightkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_rightkey_handler(U8 index_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index_num)
    {
        case WC_TZ_INDEX:
            if (g_wc_cntx.CurrTZ >= 12)
            {
                g_wc_cntx.CurrTZ = -12;
            }
            else
            {
                g_wc_cntx.CurrTZ++;
            }
            g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);

            /* Modify the current time zone to the default city's time zone, ex: GMT 5.5 */
            if (g_wc_cntx.CurrTZ != TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone && g_wc_cntx.CurrCityIndex != 0)
            {
                g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            }

            break;
        case WC_CITY_INDEX:
            if (g_wc_cntx.CurrCityIndex == 0)
            {
                while (g_wc_cntx.CurrCityIndex == 0)
                {
                    if (g_wc_cntx.CurrTZ == 12)
                    {
                        g_wc_cntx.CurrTZ = -12;
                    }
                    else
                    {
                        g_wc_cntx.CurrTZ++;
                    }
                    g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);
                }
                break;
            }

            curr_index = WcGetCityPosition(g_wc_cntx.CurrCityIndex);

            if (curr_index == (NUMBER_OF_CITY - 2))
            {
                curr_index = 0;
            }
            else
            {
                curr_index++;
            }

			if (curr_index <= WC_NUM_CITY - 1)
			{
				g_wc_cntx.CurrCityIndex = gWcTimeZoneIndex[curr_index];
			}

            g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            break;
    }

    /* get time zone string */
    mmi_wc_get_tz_string(g_wc_cntx.CurrTZ, (CHAR*) & gIndexInfo[WC_TZ_INDEX][WC_GMT_LEN]);
    mmi_wc_get_city_string(g_wc_cntx.CurrCityIndex);
     
    SetCat230IndexInfo(WC_TZ_INDEX, (U8*) gIndexInfo[WC_TZ_INDEX]);
    SetCat230IndexInfo(WC_CITY_INDEX, (U8*) gIndexInfo[WC_CITY_INDEX]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_default_city_of_tz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tz      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_wc_default_city_of_tz(FLOAT tz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 default_city_size = 0;
	U32 i;
    S16 TZmap = (S16) tz * 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	default_city_size = mmi_wc_get_default_city_size();
	for (i = 0; i < default_city_size; i++)
	{
		if ((DefaultCityData[i].CityTimeZone == tz) && (DefaultCityData[i].CityIndex))
		{
			return DefaultCityData[i].CityIndex;
		}
	}

	for (i = 0; i < WC_DEFAULT_TZ_NUM; i++)
	{
		if (validTZ[i] == TZmap)
		{
			return gWcDefaultCityForTZ[i];
		}
	}
    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_float2string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_float2string(FLOAT tz, CHAR *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0, j = 0;
	CHAR asc_str[WC_MAX_TZ_STR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(asc_str, 0x00, sizeof(WC_MAX_TZ_STR_LEN));
    
	i = (U8)tz * 100 / 100;
	j = (U16)(tz * 100) % 100;

	if (j == 0)
	{
		sprintf(asc_str, "%d", i);
	}
	else
	{
		if (j * 2 % 100)
		{
			sprintf(asc_str, "%d.%d", i, j);
		}
		else
		{
			j = 5;
			sprintf(asc_str, "%d.%d", i, j);
		}
	}

	mmi_asc_to_ucs2((CHAR*)result, asc_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_tz_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tz          [IN]        
 *  outStr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_get_tz_string(FLOAT tz, CHAR *outStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type sym;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wc_cntx.CurrTZ >= 0)
    {
        if (g_wc_cntx.CurrTZ == 0)
        {
            sym = WC_SYM_SPACE;
        }
        else
        {
            sym = WC_SYM_POSITIVE;
        }
        memcpy(outStr, &sym, sizeof(UI_character_type));
        tz = g_wc_cntx.CurrTZ;

    }
    else
    {
        sym = WC_SYM_NEGATIVE;
        memcpy(outStr, &sym, sizeof(UI_character_type));
        tz = -(g_wc_cntx.CurrTZ);
    }

	mmi_wc_float2string(tz, (CHAR*)&outStr[sizeof(UI_character_type)]);
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_city_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tz          [IN]        
 *  outStr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_get_city_string(U8 cityIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *cityName;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cityName = (U8*) GetString(TimeZoneData[g_wc_cntx.CurrCityIndex].CityName);
    /* if home city length to large */
    if (mmi_ucs2strlen((CHAR*) cityName) >= WC_MAX_INDEX_INFO_LEN / ENCODING_LENGTH)
    {
        memcpy(gIndexInfo[WC_CITY_INDEX], cityName, WC_MAX_INDEX_INFO_LEN - ENCODING_LENGTH);
        mmi_ucs2cat((CHAR*)gIndexInfo[WC_CITY_INDEX], (CHAR*)L"\0");
    }
    else
    {
        memcpy(gIndexInfo[WC_CITY_INDEX], cityName, WC_MAX_INDEX_INFO_LEN);
    }
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_paint_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  event_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_paint_pen_handler(S32 x, S32 y, S32 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 number_of_city = mmi_wc_get_size();
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_city; i++)
    {
        S32 old_x_vertical = TimeZoneData[i].CityX;
        S32 old_y_horizontal = TimeZoneData[i].CityY;   /* WC_V_LINE_Y; */

        if (x >= old_x_vertical - WC_PEN_GAP && x <= old_x_vertical + WC_PEN_GAP
            && y >= old_y_horizontal - WC_PEN_GAP && y <= old_y_horizontal + WC_PEN_GAP)
        {
            g_wc_cntx.CurrCityIndex = i;
            g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            break;
        }
    }

    /* get time zone string */
    mmi_wc_get_tz_string(g_wc_cntx.CurrTZ, (CHAR*) & gIndexInfo[WC_TZ_INDEX][WC_GMT_LEN]);

    /* get Home city */
    memcpy(gIndexInfo[WC_CITY_INDEX], GetString(TimeZoneData[g_wc_cntx.CurrCityIndex].CityName), WC_MAX_INDEX_INFO_LEN);

    SetCat230IndexInfo(WC_TZ_INDEX, (U8*) gIndexInfo[WC_TZ_INDEX]);
    SetCat230IndexInfo(WC_CITY_INDEX, (U8*) gIndexInfo[WC_CITY_INDEX]);
}
#endif /* __MMI_TOUCH_SCREEN__ */

#else /* __MMI_WC_TZ_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_index_info
 * DESCRIPTION
 *  This function is used to get the index information.
 * PARAMETERS
 *  index_info      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_get_index_info(void *index_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	cat231_paint_wc_info_struct *info_ptr = (cat231_paint_wc_info_struct*)index_info;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_wc_get_string_info(mmi_wc_cntx_p->CurrCityIndex);
	
	info_ptr->title_string = (U8*)GetString(TimeZoneData[mmi_wc_cntx_p->CurrCityIndex].CityName);
	info_ptr->date_string = (U8*)mmi_wc_cntx_p->date_string;
	info_ptr->time_string = (U8*)mmi_wc_cntx_p->time_string;
	
	info_ptr->x = (S32)TimeZoneData[mmi_wc_cntx_p->CurrCityIndex].CityX;
    info_ptr->y = (S32)TimeZoneData[mmi_wc_cntx_p->CurrCityIndex].CityY;

	info_ptr->curMap = WORLD_CLOCK_IMAGE1 + (TimeZoneData[mmi_wc_cntx_p->CurrCityIndex].MapIndex - 1);
	info_ptr->day_image = mmi_wc_cntx_p->image_idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_index_info
 * DESCRIPTION
 *  This function is used to get the index information.
 * PARAMETERS
 *  index_info      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_get_string_info(U8 city_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime, incTime;

#ifdef __MMI_WORLDCLOCK_DST__
    MYTIME dstTime;
#endif 
    U8 Ucs2Date[30];
    U8 Ucs2Time[30];

#if !defined(__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__)     /* 041205 Calvin modieid */
    U8 AsciiDate[30];
#endif 
    U8 HomeCity;
    FLOAT TimeDiff;
    S32 temp;
    U8 TimeFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GetDateTime(&currTime);

    /* get time zone difference */
    HomeCity = PhnsetGetHomeCity() + 1;
    TimeDiff = WcTimeZoneDiff(city_idx, HomeCity);

    memset(&incTime, 0, sizeof(MYTIME));

    if (TimeDiff < 0)
    {
        TimeDiff = TimeDiff * (-1);
        TimeFlag = 1;
    }

    temp = (S32) (TimeDiff * 60);

    incTime.nDay = (U8) (TimeDiff / 24);
    incTime.nHour = ((S32) TimeDiff) % 24;
    incTime.nMin = temp % 60;

    if (TimeFlag)   /* decrement */
    {
        DecrementTime(currTime, incTime, &currTime);
    }
    else
    {
        IncrementTime(currTime, incTime, &currTime);
    }

#ifdef __MMI_WORLDCLOCK_DST__
    if (HomeCity != city_idx)
    {
        memset(&dstTime, 0, sizeof(MYTIME));
        dstTime.nHour = 1;
        if (mmi_wc_cntx_p->DSTForeign && g_phnset_cntx_p->currentDST)
        {
            /* do nothing */
        }
        else if (g_phnset_cntx_p->currentDST)
        {
            DecrementTime(currTime, dstTime, &currTime);
        }
        else if (mmi_wc_cntx_p->DSTForeign)
        {
            IncrementTime(currTime, dstTime, &currTime);
        }
    }
#endif /* __MMI_WORLDCLOCK_DST__ */ 

    time_string(&currTime, (UI_string_type) Ucs2Time, DT_IDLE_SCREEN);
	mmi_ucs2cpy((CHAR*)mmi_wc_cntx_p->time_string, (CHAR*)Ucs2Time);
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)   
	date_string(&currTime, (UI_string_type) Ucs2Date, DT_IDLE_SCREEN);
#else
    sprintf((CHAR*) (AsciiDate), "%02d/%02d", currTime.nMonth, currTime.nDay);
    mmi_asc_to_ucs2((CHAR*) Ucs2Date, (CHAR*) AsciiDate);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 
	mmi_ucs2cpy((CHAR*)mmi_wc_cntx_p->date_string, (CHAR*)Ucs2Date);

	if ((currTime.nHour >= 6) && (currTime.nHour < 18))
    {
         mmi_wc_cntx_p->image_idx = SUN_ICON2;
    }
    else
    {
        mmi_wc_cntx_p->image_idx = MOON_ICON;
    }
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_leftkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_leftkey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_index = WcGetCityPosition(mmi_wc_cntx_p->CurrCityIndex);

    if (curr_index == 0)
    {
        curr_index = (NUMBER_OF_CITY - 2);  /* 56; */
    }
    else
    {
        curr_index--;
    }

    mmi_wc_cntx_p->CurrCityIndex = gWcTimeZoneIndex[curr_index];

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_rightkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_rightkey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_index = WcGetCityPosition(mmi_wc_cntx_p->CurrCityIndex);

    if (curr_index == (NUMBER_OF_CITY - 2))
    {
        curr_index = 0;
    }
    else
    {
        curr_index++;
    }

    mmi_wc_cntx_p->CurrCityIndex = gWcTimeZoneIndex[curr_index];

}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_paint_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  event_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_paint_pen_handler(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 number_of_city = mmi_wc_get_size();
	S32 old_x_vertical, old_y_horizontal;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_city; i++)
    {
        old_x_vertical = (S32)TimeZoneData[i].CityX;
        old_y_horizontal = (S32)TimeZoneData[i].CityY;

        if (x >= old_x_vertical - WC_PEN_GAP && 
			x <= old_x_vertical + WC_PEN_GAP && 
			y >= old_y_horizontal - WC_PEN_GAP && 
			y <= old_y_horizontal + WC_PEN_GAP)
        {
        	mmi_wc_cntx_p->CurrCityIndex = i;
            break;
        }
    }
	
}
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_WC_TZ_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  ExitWcBrowseCity
 * DESCRIPTION
 *  Exit function of browse city screen. Free allocated data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitWcBrowseCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WC_TZ_SUPPORT__
	ExitCategory231Screen();

#else /* __MMI_WC_TZ_SUPPORT__ */ 
    g_wc_cntx.highlightIndex = Cat230HighlightedIndex;
    SAFE_MFREE(gIndexInfo[0]);
    SAFE_MFREE(gIndexInfo[1]);
    SAFE_MFREE(homeTime);
    SAFE_MFREE(foreTime);
#endif /* __MMI_WC_TZ_SUPPORT__ */ 
    g_wc_cntx.running_flag = MMI_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wc_select_scrn_lsk
 * DESCRIPTION
 *  LSK handler of browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_select_scrn_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wc_cui_select_result(MMI_FALSE, 0xFF);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_select_scrn_lsk
 * DESCRIPTION
 *  LSK handler of browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wc_select_scrn_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wc_cui_select_result(MMI_TRUE, g_wc_cntx.CurrCityIndex - 1);
}


/*****************************************************************************
 * FUNCTION
 *  WcHandleRSK
 * DESCRIPTION
 *  LSK handler of browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void WcHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_scrn_close_active_id();

    mmi_frm_group_close(g_wc_cntx.grp_id);
    
    g_wc_cntx.CurrCityIndex = 0xff;
}

#ifdef __MMI_WORLDCLOCK_DST__


/*****************************************************************************
 * FUNCTION
 *  WcDSTBackAndSave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void WcDSTBackAndSave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;
    mmi_popup_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //WriteValue(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE, &error);
	WriteValueSlim(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE);

    mmi_popup_property_init(&arg);
    
    arg.parent_id = GRP_ID_WC_DST;
    arg.callback = (mmi_proc_func)NULL;
    g_wc_cntx.user_tag = STR_GLOBAL_DONE;
    arg.user_tag = &g_wc_cntx.user_tag;
    
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE),
                      MMI_EVENT_SUCCESS, 
                      &arg);
}

/*****************************************************************************
 * FUNCTION
 *  WcDSTEndKeyHandler
 * DESCRIPTION
 *  End key handler of DST screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void WcDSTEndKeyHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wc_cntx.CurrCityIndex = 0xff;
   // WriteValue(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE, &error);
	WriteValueSlim(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE);
    mmi_idle_display();
}

/*****************************************************************************
 * FUNCTION
 *  WcEntryDST
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void WcEntryDST(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_wc_cntx.grp_id, 
                         GRP_ID_WC_DST, 
                         mmi_wc_main_group_proc, 
                         NULL);

    mmi_frm_group_enter(GRP_ID_WC_DST, MMI_FRM_NODE_SMART_CLOSE_FLAG);
  

    cui_menu_id = cui_menu_create(GRP_ID_WC_DST, 
                                  CUI_MENU_SRC_TYPE_APPCREATE, 
                                  CUI_MENU_TYPE_OPTION, 
                                  MENU_ID_WC_DST_OPT, 
                                  MMI_FALSE, 
                                  NULL);

    cui_menu_run(cui_menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  WcEntryDstSelectionScrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void WcEntryDstSelectionScrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_menu_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cui_menu_id = cui_menu_create(GRP_ID_WC_DST, 
                                  CUI_MENU_SRC_TYPE_APPCREATE, 
                                  CUI_MENU_TYPE_APPSUB, 
                                  MENU_ID_WC_DST_CFG_OPT, 
                                  MMI_FALSE, 
                                  NULL);
    cui_menu_run(cui_menu_id);
}   


#endif /* __MMI_WORLDCLOCK_DST__ */ 


/*****************************************************************************
 * FUNCTION
 *  WcTimeZoneDiff
 * DESCRIPTION
 *  Calculate the time zone difference between 2 cities.
 * PARAMETERS
 *  City1       [IN]        Index of city 1.
 *  City2       [IN]        Index of city 2.
 * RETURNS
 *  time tone of city 1 - time zone of city 2.
 *****************************************************************************/
static FLOAT WcTimeZoneDiff(U8 City1, U8 City2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (City1 == 0 || City2 == 0)   /* of one the cities is "None" */
    {
        return 25;
    }
    else
    {
        return (TimeZoneData[City1].CityTimeZone - TimeZoneData[City2].CityTimeZone);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WcGetCityPosition
 * DESCRIPTION
 *  Calculate the position of city in timezone order.
 * PARAMETERS
 *  index       [IN]        Index of city.
 * RETURNS
 *  Position on gWcTimeZoneIndex array.
 *****************************************************************************/
static U8 WcGetCityPosition(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, num_city;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_city = NUMBER_OF_CITY;
    for (i = 0; i < num_city; i++)
        if (gWcTimeZoneIndex[i] == index)
        {

            break;
        }

    return i;
}


#define WC_SUBLCD_DISPLAY
#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
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
void ReadValueCityNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;
    U8 city_chosen1;
    U8 city_chosen2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // ReadValue(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE, &error);
	ReadValueSlim(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE);
    if (city_chosen1 == 0xff)
    {
        city_chosen1 = PhnsetGetHomeCity();
        city_chosen1++;
        //WriteValue(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE, &error);
		WriteValueSlim(NVRAM_DOWNLOAD_CITY1, &city_chosen1, DS_BYTE);

    }
    //ReadValue(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE, &error);
	ReadValueSlim(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE);
    if (city_chosen2 == 0xff)
    {
        city_chosen2 = 0;
        //WriteValue(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE, &error);
		WriteValueSlim(NVRAM_DOWNLOAD_CITY2, &city_chosen2, DS_BYTE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_group_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_wc_sub_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_frm_group_close(GRP_ID_WC_SUB_LCD);
        break;
        
    case EVT_ID_ALERT_QUIT:
    {
        mmi_alert_result_evt_struct *alert_evt = (mmi_alert_result_evt_struct *)evt;
        U16 user_tag = *(U16 *)alert_evt->user_tag;
        if (user_tag == STR_GLOBAL_DONE)
        {
            mmi_frm_group_close(GRP_ID_WC_SUB_LCD);        
        }
        
        break;
    } 
        
    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcApp
 * DESCRIPTION
 *  Entry function of world clock application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_WC_SUB_LCD, mmi_wc_sub_group_proc, NULL);
    mmi_frm_group_enter(GRP_ID_WC_SUB_LCD, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        GRP_ID_WC_SUB_LCD,
        SCR_ID_WC_APP,
        (FuncPtr)EntryWcAppExt,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  EntryWcAppExt
 * DESCRIPTION
 *  Entry function of world clock application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcAppExt(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 WC_list_of_items[2];
    S32 num_of_items;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            scrn_data->group_id, 
            SCR_ID_WC_APP, 
            NULL, 
            (FuncPtr)EntryWcAppExt, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf(SCR_ID_WC_APP);

    num_of_items = GetNumOfChild(ORGANIZER_WORLDCLOCK_MENU);

    GetSequenceStringIds(ORGANIZER_WORLDCLOCK_MENU, WC_list_of_items);

    SetParentHandler(ORGANIZER_WORLDCLOCK_MENU);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory15Screen(
        STR_WORLD_CLOCK_TITLE,
        GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        WC_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}

/*****************************************************************************
 * FUNCTION
 *  WcGetNearbyCityNameIndex
 * DESCRIPTION
 *  Get the index of near by city.
 * PARAMETERS
 *  inp     [IN]        First character of city name.
 * RETURNS
 *  index of nearest city.
 *****************************************************************************/
U8 WcGetNearbyCityNameIndex(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 n1 = 0;
    U8 num_city = NUMBER_OF_CITY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; (i < (num_city)); i++)
    {
        memcpy(&n1, subMenuDataPtrs[i], ENCODING_LENGTH);
        if (n1 >= inp)
        {
            return (U8) (i - 1);
        }
    }

    return 255;
}


/*****************************************************************************
 * FUNCTION
 *  WcMultitapInputCallBack
 * DESCRIPTION
 *  Call back function when input some characters in the screen.
 * PARAMETERS
 *  inp     [IN]        Input character
 * RETURNS
 *  void
 *****************************************************************************/
void WcMultitapInputCallBack(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wc_cntx.CurrHiliteCity = WcGetNearbyCityNameIndex(inp) + 1;
    fixed_list_goto_item(g_wc_cntx.CurrHiliteCity);
}


/*****************************************************************************
 * FUNCTION
 *  WcMultitapCompleteCallBack
 * DESCRIPTION
 *  Call back function when multi-tap opeartion finished.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcMultitapCompleteCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fixed_list_goto_item(g_wc_cntx.CurrHiliteCity);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightWcSubLcd
 * DESCRIPTION
 *  Highlight handler of Sub Lcd Display menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcSubLcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryWcSubLcd, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(EntryWcSubLcd, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  WcSaveSubLcdSetting
 * DESCRIPTION
 *  Save selected city to cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcSaveSubLcdSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S16 error;
    mmi_popup_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wc_cntx.CurrHiliteSublcd == 0)
    {
        //WriteValue(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.CurrHiliteCity, DS_BYTE, &error);   /* homecity */
		WriteValueSlim(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.CurrHiliteCity, DS_BYTE);
    }
    else
    {
        //WriteValue(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.CurrHiliteCity, DS_BYTE, &error);
		WriteValueSlim(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.CurrHiliteCity, DS_BYTE);
    }

    mmi_popup_property_init(&arg);
    
    arg.parent_id = GRP_ID_WC_SUB_LCD;
    arg.callback = (mmi_proc_func)NULL;
    g_wc_cntx.user_tag = STR_GLOBAL_DONE;
    arg.user_tag = &g_wc_cntx.user_tag;
    
    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE),
                      MMI_EVENT_SUCCESS, 
                      &arg);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightWcSubLcdCity
 * DESCRIPTION
 *  Highlight handler of sub-lcd display city list.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcSubLcdCity(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wc_cntx.CurrHiliteCity = (U8) index;
}

/*****************************************************************************
 * FUNCTION
 *  ExitWcSelectCity
 * DESCRIPTION
 *  Display list of cities
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitWcSelectCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_reset_multitap();
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcSelectCity
 * DESCRIPTION
 *  Display list of cities
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcSelectCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 index;
    U8 num_city = NUMBER_OF_CITY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_WC_SUB_LCD, 
            SCR_ID_WC_OPTIONS, 
            ExitWcSelectCity, 
            EntryWcSelectCity, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    for (i = 0; i < num_city; i++)
    {
        mmi_ucs2cpy((CHAR*) subMenuDataPtrs[i], (CHAR*) GetString(TimeZoneData[i].CityName));
    }

    if (g_wc_cntx.CurrHiliteSublcd == 0)
    {
        index = g_wc_cntx.City1;
    }
    else
    {
        index = g_wc_cntx.City2;
    }

    RegisterHighlightHandler(HighlightWcSubLcdCity);

	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory6Screen(
        STR_WORLD_SELECT_CITY,
        GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_city,
        subMenuDataPtrs,
        index,
        NULL);

    if (!IsChineseSet())
    {
        wgui_setup_multitap_functions(WGUI_MULTITAP_TYPE_UPPERCASE_ABC_NO_NUMBER, WcMultitapInputCallBack, WcMultitapCompleteCallBack);
    }

    SetLeftSoftkeyFunction(WcSaveSubLcdSetting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(WcSaveSubLcdSetting, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  WcHintCity1
 * DESCRIPTION
 *  Hint handler of city 1.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WcHintCity1(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ReadValue(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.City1, DS_BYTE, &error); /* homecity */
	ReadValueSlim(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.City1, DS_BYTE);
    if (g_wc_cntx.City1 == 0xff)    /* not written anything in NVRAM */
    {
        g_wc_cntx.City1 = PhnsetGetHomeCity() + 1;
        //WriteValue(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.City1, DS_BYTE, &error);    /* homecity */
		WriteValueSlim(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.City1, DS_BYTE);
    }

    mmi_ucs2ncpy(
        (CHAR*) hintData[index],
        (CHAR*) GetString(TimeZoneData[g_wc_cntx.City1].CityName),
        MAX_SUBMENU_CHARACTERS);
}


/*****************************************************************************
 * FUNCTION
 *  WcHintCity2
 * DESCRIPTION
 *  Hint handler of city 2.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WcHintCity2(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ReadValue(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.City2, DS_BYTE, &error);
	ReadValueSlim(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.City2, DS_BYTE);
    if (g_wc_cntx.City2 == 0xff)
    {
        g_wc_cntx.City2 = 0;
        //WriteValue(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.City2, DS_BYTE, &error);    /* none */
		WriteValueSlim(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.City2, DS_BYTE);
    }
    mmi_ucs2ncpy(
        (CHAR*) hintData[index],
        (CHAR*) GetString(TimeZoneData[g_wc_cntx.City2].CityName),
        MAX_SUBMENU_CHARACTERS);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightWcSubLcdMenu
 * DESCRIPTION
 *  Highlight handler of Sub-Lcd menu.
 * PARAMETERS
 *  nIndex      [IN]        Index of item.
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcSubLcdMenu(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wc_cntx.CurrHiliteSublcd = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcSubLcd
 * DESCRIPTION
 *  Entry function of Sub-LCD display
 * PARAMETERS
 *  void
 *  nIndex(?)       [IN]        Index of item.
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcSubLcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_items;
    U16 cityarray[2];
    U8 *guiBuffer;
    U8 *u8WorldClockPop[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            GRP_ID_WC_SUB_LCD, 
            SCR_ID_WC_APP, 
            NULL, 
            (FuncPtr)EntryWcSubLcd, 
            MMI_FRM_FULL_SCRN))
    {
        return;
    }    

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    num_of_items = GetNumOfChild(MITEM_WORLDCLOCK_SUBLCDDISPLAY);
    GetSequenceStringIds(MITEM_WORLDCLOCK_SUBLCDDISPLAY, cityarray);
    SetParentHandler(MITEM_WORLDCLOCK_SUBLCDDISPLAY);

    RegisterHighlightHandler(HighlightWcSubLcdMenu);

    ConstructHintsList(MITEM_WORLDCLOCK_SUBLCDDISPLAY, u8WorldClockPop);

	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory52Screen(
        STR_WORLD_CLOCK_MENU2,
        GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        cityarray,
        (U16*) gIndexIconsImageList,
        u8WorldClockPop,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(EntryWcSelectCity, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(EntryWcSelectCity, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 


/*****************************************************************************
* FUNCTION
*	mmi_wc_update_datetime
* DESCRIPTION
*   update local time
* PARAMETERS
*	None.
* RETURNS	
*	None
* GLOBALS AFFECTED
*	None.
*****************************************************************************/
void mmi_wc_update_datetime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_WORLDCLOCK_TRACE_001);

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_WORLDCLOCK_TRACE_002, g_wc_cntx.running_flag);
    if (g_wc_cntx.running_flag)
    {
#ifndef __MMI_WC_TZ_SUPPORT__
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_WORLDCLOCK_TRACE_003);
        Cat231UpdateDT();		
#else /* __MMI_WC_TZ_SUPPORT__ */ 
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_WORLDCLOCK_TRACE_004);
        Cat230UpdateTime();
#endif /* __MMI_WC_TZ_SUPPORT__ */
    }
}
#endif /* __MMI_WORLD_CLOCK__ */ 


/*****************************************************************************
* FUNCTION
*	mmi_wc_is_dst
* DESCRIPTION
*   function to get if daylight saving is enabled in MMI
* PARAMETERS
*	None.
* RETURNS	
*	None
* GLOBALS AFFECTED
*	None.
*****************************************************************************/
static void mmi_wc_is_dst(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//S16 error;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//ReadValue(NVRAM_SETTING_DT_DST, &g_dst, DS_BYTE, &error);
	ReadValueSlim(NVRAM_SETTING_DT_DST, &g_dst, DS_BYTE);
}

#if defined(__MMI_DUAL_CLOCK__) 
/*****************************************************************************
* FUNCTION
*	mmi_wc_get_foreign_city_info
* DESCRIPTION
*   function to get if daylight saving is enabled in MMI
* PARAMETERS
*	None.
* RETURNS	
*	None
* GLOBALS AFFECTED
*	None.
*****************************************************************************/
void mmi_wc_get_foreign_city_info(MYTIME *foreign_time, PU8 *city_name)
{
#ifdef __MMI_WC_TZ_SUPPORT__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 foreign_indx;
	//S16 error;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(foreign_time != NULL && city_name != NULL);

	//ReadValue(FOREIGN_CITY, &foreign_indx, DS_BYTE, &error);
	ReadValueSlim(FOREIGN_CITY, &foreign_indx, DS_BYTE);
	g_wc_cntx.CurrTZ = TimeZoneData[foreign_indx + 1].CityTimeZone;
	
#ifdef __MMI_WORLDCLOCK_DST__
    //ReadValue(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE, &error);
	ReadValueSlim(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE);

    if (g_wc_cntx.DSTForeign == 0xff)
    {
        g_wc_cntx.DSTForeign = 0;
    }
#endif /* __MMI_WORLDCLOCK_DST__ */	
	
	mmi_wc_get_foreign_city_dt(foreign_time);
	*city_name = (U8*) GetString(TimeZoneData[foreign_indx + 1].CityName);
#endif /* __MMI_WC_TZ_SUPPORT__ */
}
#endif /* __MMI_DUAL_CLOCK__ */

#endif /* _MMI_WORLDCLOCK_C */

