/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   custom_gadget_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for integrating Gadget file APIs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 ****************************************************************************/
#ifdef __GADGET_SUPPORT__
#include "MMI_features.h"

#include "kal_general_types.h"
#include "widget_adp_struct.h"
#include "custom_gadget_cfg.h"
#include "custom_gadget_config.h"
#include "lcd_sw_inc.h"

#ifdef __COSMOS_MMI_PACKAGE__
	#include "custom_mmi_folders_config.h"
#else	
	#include "FileMgrType.h"
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#define CUSTOM_GADGET_IDH "Maui Target"

/***************************************************************************** 
* Typedef 
*****************************************************************************/


/***************************************************************************** 
 * Config Data
 *****************************************************************************/

/**  Gadget Memory Configuration **/
#ifdef __MTK_TARGET__
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#pragma arm section rwdata = "CACHED_EXTSRAM_RW", zidata = "CACHED_EXTSRAM_ZI"
#else
#pragma arm section rwdata = "EXTSRAM_RW", zidata = "EXTSRAM_ZI"
#endif
#endif
unsigned int g_gadget_sys_mem[GADGET_MEM_SIZE / sizeof(unsigned int)];
#ifdef __MTK_TARGET__
#pragma arm section rwdata, zidata
#endif

/**  Step1 : Pre-installation Configuration **/

/* If define yahoo content support, pre-install yahoo widgets */
#ifdef __YAHOO_CONTENT_SUPPORT__
/* Flickr */
static const unsigned char rom_wgt_filckr[] =
{
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
  #include "Flickr_WQVGA_QVGA.wgt.hex"
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_400X240__)
  #include "Flickr_WQVGA_QVGA.wgt.hex"
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X320__)
  #include "Flickr_HVGA.wgt.hex"
#elif defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_800X480__)
  #include "Flickr_WVGA.wgt.hex"
#endif
};
#endif /* __YAHOO_CONTENT_SUPPORT__ */


/* If define facebook content support, pre-install facebook widgets */
#ifdef __FACEBOOK_CONTENT_SUPPORT__
/* Facebook */
static const unsigned char rom_wgt_fb[] =
{
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
  #include "FB_QVGA.wgt.hex"
#elif defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_400X240__)
  #include "FB_WQVGA.wgt.hex"
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X320__)
  #include "FB_HVGA.wgt.hex"
#elif defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_800X480__)
  #include "FB_WVGA.wgt.hex"
#endif
};
#endif /* __FACEBOOK_CONTENT_SUPPORT__ */


/** Step 2: Fill pre-install widget table */

#ifdef __COSMOS_MMI_PACKAGE__ /* Cosmos home screen initial at center page */
	#define WIDGET_PRELOAD_PAGE_INDEX 2
#else						  /* FTE home screen initail at the first page */
	#define WIDGET_PRELOAD_PAGE_INDEX 0
#endif /* __COSMOS_MMI_PACKAGE__ */

const widget_mgr_pre_install_wgt_struct g_gadget_mgr_pre_install_wgt_table[] =
{
    /* If define yahoo content support, pre-load yahoo widgets */
//#ifdef __YAHOO_CONTENT_SUPPORT__
#if 0
/* under construction !*/
/* under construction !*/
#endif /* __YAHOO_CONTENT_SUPPORT__ */

    /* If define facebook content support, pre-load facebook widgets */
#ifdef __FACEBOOK_CONTENT_SUPPORT__
    /* Facebook (Pre-load to home screen) */
    {rom_wgt_fb,  sizeof(rom_wgt_fb),  WIDGET_MGR_DRIVE_PUBLIC,  WIDGET_MGR_ATTR_PRELOAD, WIDGET_PRELOAD_PAGE_INDEX, (LCD_WIDTH/2), ((LCD_HEIGHT - 60)/2)},
#endif /* __FACEBOOK_CONTENT_SUPPORT__ */

    /* add pre-installed widget above */
    {NULL, 0, 0, 0, 0, 0, 0},
};


/* temp drive where wgt files are written */
const char g_gadget_mgr_pre_install_temp_folder[] = "/public_gadget/wgt";
//const char g_gadget_mgr_pre_install_temp_folder[] = "/memcard_gadget/wgt";
const char g_gadget_mgr_pre_install_wgt_xml_file[] = "/public_gadget/pre_install_wgt.xml";

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* number of pre-installed widgets */
const int g_gadget_mgr_pre_install_wgt_num = sizeof(g_gadget_mgr_pre_install_wgt_table) / sizeof(widget_mgr_pre_install_wgt_struct) - 1;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  custom_gadget_get_sys_mem_size
 * DESCRIPTION
 *  get size of gadget system memory
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
int custom_gadget_get_sys_mem_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    return GADGET_MEM_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_gadget_get_asm_mem_size
 * DESCRIPTION
 *  get size of gadget asm memory
 * PARAMETERS
 *  void
 * RETURNS
 *  int
 *****************************************************************************/
int custom_gadget_get_asm_mem_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    return GADGET_CUSTOM_CFG_ASM_MEM_SIZE;
}


/*****************************************************************************
 * FUNCTION
 *  custom_gadget_using_asm
 * DESCRIPTION
 *  this function is used to check whether Gadget uses ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool custom_gadget_using_asm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
#if defined (__MTK_TARGET__) && defined(GADGET_USE_ASM)
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  custom_gadget_using_mmv2
 * DESCRIPTION
 *  this function is used to check whether Gadget uses mmv2 manage mechansim
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool custom_gadget_using_mmv2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
#if defined (__MTK_TARGET__) && defined (GADGET_USE_MMV2)
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  custom_gadget_get_idh
 * DESCRIPTION
 *  this function is used to get the idh
 * PARAMETERS
 *  void
 * RETURNS
 *  const char*
 *****************************************************************************/
const char *custom_gadget_get_idh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    return CUSTOM_GADGET_IDH;
}


/*****************************************************************************
 * FUNCTION
 *  custom_gadget_get_idh
 * DESCRIPTION
 *  this function is used to check if widget uses large icon
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool custom_gadget_use_large_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    #if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_480X800__)
        return KAL_TRUE;
    #else
        return KAL_FALSE;
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  custom_gadget_get_images_folder
 * DESCRIPTION
 *  this function is used to get images folder
 * PARAMETERS
 *  void
 * RETURNS
 *  const char*
 *****************************************************************************/
const char* custom_gadget_get_images_folder(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
	return (const char*) IMAGE_DOWNLOAD_FOLDER_NAME; 
#else
	return (const char*) FMGR_DEFAULT_FOLDER_IMAGES;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  custom_gadget_get_audios_folder
 * DESCRIPTION
 *  this function is used to get audios folder
 * PARAMETERS
 *  void
 * RETURNS
 *  const char*
 *****************************************************************************/
const char* custom_gadget_get_audios_folder(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
	return (const char*) AUDIO_DOWNLOAD_FOLDER_NAME; 
#else
	return (const char*) FMGR_DEFAULT_FOLDER_AUDIO;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  custom_gadget_get_videos_folder
 * DESCRIPTION
 *  this function is used to get videos folder
 * PARAMETERS
 *  void
 * RETURNS
 *  const char*
 *****************************************************************************/
const char* custom_gadget_get_videos_folder(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
	return (const char*) VIDEO_DOWNLOAD_FOLDER_NAME; 
#else
	return (const char*) FMGR_DEFAULT_FOLDER_VIDEO;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  custom_gadget_get_shootings_folder
 * DESCRIPTION
 *  this function is used to get shootings folder
 * PARAMETERS
 *  void
 * RETURNS
 *  const char*
 *****************************************************************************/
const char* custom_gadget_get_shootings_folder(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
	return (const char*) SHOOTING_DOWNLOAD_FOLDER_NAME; 
#else
	return NULL;
#endif
}

#endif /* __GADGET_SUPPORT__ */
