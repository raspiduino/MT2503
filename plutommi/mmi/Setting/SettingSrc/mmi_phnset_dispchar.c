/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * mmi_phnset_dispchar.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Display Characteristic
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

/***************************************************************************** 
* Include
*****************************************************************************/
/*  Include: MMI header file */
/* auto add by kw_check begin */
#include "MMI_features.h"
#include "MMIDataType.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_rp_srv_wallpaper_def.h"
#include "PhoneSetupResList.h"
#include "mmi_rp_srv_screensaver_def.h"
#include "mmi_rp_srv_phnset_onoff_def.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#ifdef __MMI_PHNSET_APPICON_SUPPORT__
#include "mmi_rp_app_setting_appicon_def.h"
#endif
#include "mmi_rp_app_phonesetting_new_def.h"
#ifdef __MMI_BTD_BOX_UI_STYLE__
#include "ScrSaverGprot.h"
#endif
/* auto add by kw_check end */

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern CHAR *idle_screen_wallpaper_name;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* External Function
*****************************************************************************/


static void mmi_dispchar_img_id(U16* data,U16 nDataItemId, S16 is_set)
{
   switch (nDataItemId)
    {
        case NVRAM_FUNANDGAMES_SETWALLPAPER:
	#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
		case SCREEN_LOCK_WALLPAPER_STATIC_ID:
	#endif /* __MMI_VUI_LAUNCHER_KEY__ */
            if (!(*data) || (*data) == IMG_ID_DISPCHAR_AVATAR_WALLPAPER)
                ;
            else
                (*data) = (*data) - (IMG_ID_PHNSET_WP_START - 1)*is_set;
            break;
        case RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER:
            (*data) = ((*data) == 0) ? ((*data)) : ((*data) - (IMG_ID_PHNSET_WP_START - 1)*is_set);
            break;
    #ifdef __MMI_SUB_WALLPAPER__
        case NVRAM_SETWALLPAPER_SUB:
            (*data) = ((*data) == 0) ? ((*data)) : ((*data) - (IMG_ID_PHNSET_SUB_WP_START - 1)*is_set);
            break;
        case RESTORE_DEFAULT_SETWALLPAPER_SUB:
            (*data) = ((*data) == 0) ? ((*data)) : ((*data) - (IMG_ID_PHNSET_SUB_WP_START - 1)*is_set);
            break;
    #endif /* __MMI_SUB_WALLPAPER__ */

    #ifdef __MMI_SCREEN_SAVER__
        case NVRAM_CURRENT_SCREENSVER_ID:
            if (!(*data) || (*data) == IMG_ID_DISPCHAR_AVATAR_SCREENSAVER)
                ;
            else
                (*data) = (*data) - (IMG_ID_PHNSET_SS_START - 1)*is_set;
            break;
        case RESTORE_DEFAULT_CURRENT_SCREENSVER_ID:
            (*data) = ((*data) == 0) ? ((*data)) : ((*data) - (IMG_ID_PHNSET_SS_START - 1)*is_set);
            break;
    #endif /* __MMI_SCREEN_SAVER__ */
    
#ifdef __MMI_PHNSET_APPICON_SUPPORT__    
        case NVRAM_RESTORE_APP_ICON_ID:
        case NVRAM_DEFAULT_RESTORE_APP_ICON_ID:
            break;
#endif    
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
        case NVRAM_RESTORE_POWER_ON_DISPLAY:
            if (!(*data) || (*data) == IMG_ID_DISPCHAR_AVATAR_ON)
                ;
            else
                (*data) = (*data) - (IMG_ID_PHNSET_ON_START - 1)*is_set;
            break;
        case NVRAM_CURRENT_POWER_ON_DISPLAY:
            (*data) = ((*data) == 0) ? ((*data)) : ((*data) - (IMG_ID_PHNSET_ON_START - 1)*is_set);
            break;
        case NVRAM_RESTORE_POWER_OFF_DISPLAY:
            if (!(*data) || (*data) == IMG_ID_DISPCHAR_AVATAR_OFF)
                ;
            else
                (*data) = (*data) - (IMG_ID_PHNSET_OFF_START - 1)*is_set;
              break;
        case NVRAM_CURRENT_POWER_OFF_DISPLAY:
            (*data) = ((*data) == 0) ? ((*data)) : ((*data) - (IMG_ID_PHNSET_OFF_START - 1)*is_set);
            break;
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
        default:
            MMI_ASSERT(0);
            break;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dispchar_get_img_id
 * DESCRIPTION
 *  To get image id from NVRAM.
 * PARAMETERS
 *  nDataItemId     [IN]        Id in cache short
 *  pBuffer         [?]         
 *  data(?)         [OUT]       Data in cache short
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dispchar_get_img_id(U16 nDataItemId, U16 *pBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // S16 error;
    U16 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = *(U16*) (pBuffer);
    //ReadValue(nDataItemId, &data, DS_SHORT, &error);
	ReadValueSlim(nDataItemId, &data, DS_SHORT);
#if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
/* under construction !*/
#endif /* __MMI_VUI_LAUNCHER_KEY__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SUB_WALLPAPER__ */     
/* under construction !*/
    #ifdef __MMI_SCREEN_SAVER__
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
/* under construction !*/
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
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
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    mmi_dispchar_img_id(&data,nDataItemId, -1);

    *(U16*) (pBuffer) = data;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dispchar_set_img_id
 * DESCRIPTION
 *  To set image id to NVRAM.
 * PARAMETERS
 *  nDataItemId     [IN]        Id in cache short
 *  pBuffer         [?]         
 *  data(?)         [IN]        Data in cache short
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dispchar_set_img_id(U16 nDataItemId, U16 *pBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;
    U16 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = *(U16*) (pBuffer);
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
/* under construction !*/
	#endif /* __MMI_VUI_LAUNCHER_KEY__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_SUB_WALLPAPER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SUB_WALLPAPER__ */
/* under construction !*/
    #ifdef __MMI_SCREEN_SAVER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_SCREEN_SAVER__ */
/* under construction !*/
    #ifdef __MMI_POWER_ON_OFF_DISPLAY__
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
    #endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    mmi_dispchar_img_id(&data,nDataItemId, 1);

    //WriteValue(nDataItemId, &data, DS_SHORT, &error);
	WriteValueSlim(nDataItemId, &data, DS_SHORT);

}

/*****************************************************************************
 * FUNCTION
 *  dispchar_iswp_swflash
 * DESCRIPTION
 *  To check if wallpaper is a swflash.
 * PARAMETERS
 *  nDataItemId     [IN]        Id in cache short
 *  pBuffer         [?]         
 *  data(?)         [IN]        Data in cache short
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SWFLASH__
MMI_BOOL dispchar_iswp_swflash(void)
{
    PHNSET_TYPE_DISP type = PhnsetGetDisplayType((U16)PhnsetGetCurWallPaperIdx());

    /* add to check SWFLASH file remove or not */
    if ((type == PHNSET_TYPE_DISP_USER) && (srv_fmgr_types_find_group_by_filename_str(idle_screen_wallpaper_name) == FMGR_GROUP_UNKNOWN))
    {
        PhnsetWallpaperBadFileCallBack(0);
        return MMI_FALSE;
    }

	if ( type == PHNSET_TYPE_DISP_SWFLASH ||
	    (type == PHNSET_TYPE_DISP_USER && idle_screen_wallpaper_name && srv_fmgr_types_find_group_by_filename_str(idle_screen_wallpaper_name) == FMGR_GROUP_SWFLASH))
	    return MMI_TRUE;
    else
        return MMI_FALSE;
}
#endif /* __MMI_SWFLASH__ */

#ifdef __MMI_AVATAR__
void dispchar_get_current_avatar_id(U16 id, U32 *avatar_id,  U32 *serial_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error;
	U32 buffer[2];
    U32 serial_buffer[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
	switch (id)
	{
		case IMG_ID_DISPCHAR_AVATAR_WALLPAPER:
		{

			//ReadValue(NVRAM_DISPCHAR_AVATAR_WPSS, (U8 *)buffer, DS_DOUBLE, &error);
            //ReadValue(NVRAM_DISPCHAR_AVATAR_WPSS_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE, &error);
			ReadValueSlim(NVRAM_DISPCHAR_AVATAR_WPSS, (U8 *)buffer, DS_DOUBLE);
			ReadValueSlim(NVRAM_DISPCHAR_AVATAR_WPSS_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE);
			*avatar_id = buffer[IMG_ID_DISPCHAR_AVATAR_WALLPAPER - IMG_ID_DISPCHAR_AVATAR_START];
            *serial_num = serial_buffer[IMG_ID_DISPCHAR_AVATAR_WALLPAPER - IMG_ID_DISPCHAR_AVATAR_START];
			break;
		}
		case IMG_ID_DISPCHAR_AVATAR_SCREENSAVER:
		{
			//ReadValue(NVRAM_DISPCHAR_AVATAR_WPSS, (U8 *)buffer, DS_DOUBLE, &error);
            //ReadValue(NVRAM_DISPCHAR_AVATAR_WPSS_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE, &error);
			ReadValueSlim(NVRAM_DISPCHAR_AVATAR_WPSS, (U8 *)buffer, DS_DOUBLE);
			ReadValueSlim(NVRAM_DISPCHAR_AVATAR_WPSS_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE);
			*avatar_id = buffer[IMG_ID_DISPCHAR_AVATAR_SCREENSAVER- IMG_ID_DISPCHAR_AVATAR_START];
            *serial_num = serial_buffer[IMG_ID_DISPCHAR_AVATAR_SCREENSAVER- IMG_ID_DISPCHAR_AVATAR_START];
			break;
		}
		case IMG_ID_DISPCHAR_AVATAR_ON:
		{
			//ReadValue(NARAM_DISPCHAR_AVATAR_ONOFF, (U8 *)buffer, DS_DOUBLE, &error);
            //ReadValue(NVRAM_DISPCHAR_AVATAR_ONOFF_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE, &error);
			ReadValueSlim(NARAM_DISPCHAR_AVATAR_ONOFF, (U8 *)buffer, DS_DOUBLE);
			ReadValueSlim(NVRAM_DISPCHAR_AVATAR_ONOFF_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE);
			*avatar_id = buffer[IMG_ID_DISPCHAR_AVATAR_ON - IMG_ID_DISPCHAR_AVATAR_ON];
            *serial_num = serial_buffer[IMG_ID_DISPCHAR_AVATAR_ON - IMG_ID_DISPCHAR_AVATAR_ON];
			break;
		}
		case IMG_ID_DISPCHAR_AVATAR_OFF:
		{
			//ReadValue(NARAM_DISPCHAR_AVATAR_ONOFF, (U8 *)buffer, DS_DOUBLE, &error);		          
		    //ReadValue(NVRAM_DISPCHAR_AVATAR_ONOFF_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE, &error);  
			ReadValueSlim(NARAM_DISPCHAR_AVATAR_ONOFF, (U8 *)buffer, DS_DOUBLE);
			ReadValueSlim(NVRAM_DISPCHAR_AVATAR_ONOFF_SERIALNUM, (U8 *)serial_buffer, DS_DOUBLE);
			*avatar_id = buffer[IMG_ID_DISPCHAR_AVATAR_OFF - IMG_ID_DISPCHAR_AVATAR_ON];
            *serial_num = serial_buffer[IMG_ID_DISPCHAR_AVATAR_OFF - IMG_ID_DISPCHAR_AVATAR_ON];
			break;
		}
		default:
			*avatar_id = 0;
			break;
	}
}
#endif
