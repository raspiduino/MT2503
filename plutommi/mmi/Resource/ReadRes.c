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
 *   ReadRes.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Functions for get resource.
 *
 * 
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
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
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   FILENAME : ReadRes.c

   PURPOSE     : Helper Functions   to Read/Get the Customizable Resources like Strings,Images,MenuItems..etc. 

   REMARKS     : nil

   AUTHOR      : Subramanya BG   

   DATE     : 20thSept 2002.

   Copyright (c) 2002 All rights reserved by Pixtel Communications
**********************************************************************************/
/*  Include: MMI header file */
#include "string.h"
#include "MMI_features.h"
#include "ResCompressConfig.h"

#if defined ( __MMI_RESOURCE_STR_LZMA_COMPRESS__ )|| defined(__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)
    #include "CompressResUtil.h"
#endif

// Third ROM UTILs
#if defined(__MMI_RESOURCE_STR_THIRD_ROM__) || defined (__MMI_RESOURCE_IMAGE_THIRD_ROM__)
    #include "CustMMI3rdROM.h"
	#include "third_rom.h"
    #include "ResThirdROMUtil.h"
#endif

// On demond load image headers
#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
    #include "ResCacheUtil.h"
    // Image group in 3rd ROM (NAND flash)
#ifndef __POPULATE_NO_IMAGE_DATA__
    #if defined(__MMI_RESOURCE_IMAGE_THIRD_ROM__)
        #include "CustImgGroupSingleData3rdROMHW.h"
    #else // Image group in NOR Flash (support random access with Address)
        #include "CustImgGroupDataHW.h"
        #include "CustImgGroupSingleDataHW.h"
    #endif //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
#endif //__POPULATE_NO_IMAGE_DATA__
#endif //__MMI_RESOURCE_IMAGE_GROUP_COMPRESS__


#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "GlobalMenuItems.h"
#include "imegprot.h"
#include "PhoneSetupGprots.h"
#include "SatSrvGprot.h"
#include "App_mem_med.h"
#ifdef __POPULATE_ENGINE_
#include "ExportMMIFunc.h"
#endif 
#include "mmi_frm_events.h"
/*This head file is generanted by resgen. */
#include "mmi_menu_handlers.h"

#include "mmi_rp_menu_misc_def.h"
#include "mmi_rp_app_data.h"
#include "mmi_rp_app_mem_config.h"

#include "mmi_rp_mainmenu_launch.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "FontRes.h"
    #include "mmi_res_range_def.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "mmi_theme_mgr.h"
#ifdef  __PLUTO_MMI_PACKAGE__
#if !defined(__IOT__)
    #include "mmi_rp_app_mainmenu_def.h"
#endif
#endif
    #include "GlobalConstants.h"
    #include "PixcomFontEngine.h"
    #include "MMI_fw_trc.h"
    #include "kal_trace.h"
    #include "CustDataProts.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "FileMgrSrvGProt.h"
    #include "Unicodexdcl.h"
    #include "gui_data_types.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define MAX_LANGUAGE_NUM 15

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#define STRING_TYPE_ENFB    0xFF
#endif

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
extern const U16 TRANS_STRING_COUNT;
#endif
/***************************************************************************** 
* Typedef 
*****************************************************************************/
#if defined(__IOT__)
#ifndef IDLE_SCREEN_MENU_ID
#define IDLE_SCREEN_MENU_ID (0)
#endif
#endif
/***************************************************************************** 
* Local Variable
*****************************************************************************/
U8 *gp_language_struct[MAX_LANGUAGE_NUM];

extern const S32 av_total_menuitem;
/* Hide menu item mask */
extern U8 MenuItemMask[];
/* Disable (dimmed) menu item mask */
extern U8 g_menuitem_disable_mask[];

static MMI_BOOL g_is_switch_language = MMI_FALSE;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern MMI_BOOL g_is16bit;
extern const CUSTOM_STRING_MAP *gpStringMapRes;
extern const CUSTOM_STRING_MAP_16 *gpStringMapRes16;
extern const CUSTOM_STRING *gpStringRes;
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
extern const CUSTOM_STRING *gpStringResDup;
extern U32 gMaxNonDupStrOffset;

extern const CUSTOM_STRING *gpFixedStringRes;
extern const CUSTOM_STRING_MAP *gpFixedStringMapRes;
extern const CUSTOM_STRING_MAP_16 *gpFixedStringMapRes16;
extern U16 CurrFixedMaxStringNum;
extern U16 CurrFixedMaxStringId;
extern MMI_BOOL g_isf16bit;
#endif
extern const CUSTOM_STRMAP_SEARCH *gpStrMapSearch;
extern const CUSTOM_IMAGE_MAP ImageIdMap[];
extern const CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMap[];
extern const CUSTOM_IMAGE_MAP ImageIdMapEXT[];
extern const CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMapEXT[];
extern const CUSTOM_MENU *nCustMenus;

/* MTK Elvis for R2L characters */
#if !defined(__IOT__)
extern BOOL r2lMMIFlag;
#endif

/* MTK end */

extern U16 gMaxDeployedLangs;
extern U16 gCurrLangIndex;

/* extern StringResList gStringList[MAX_LANGUAGES]; */
extern StringResList *gStringList;

extern sLanguageDetails *gLanguageArray;

/* decalred in the CustImageRes.c */
extern CUSTOM_IMAGE *nCustImageNames;

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
extern CUSTOM_IMAGE *nCustImageNamesEXT;    /* 040805 CustPack: Calvin added */

/* __CUSTPACK_MULTIBIN Calvin END */

/* decalred in the CustScreenData.c */
extern CUSTOM_SCREEN nCustScreens[MAX_SCREEN_IDS];

/* declared in the CustMenuDataRes.c */

extern U16 CurrMaxStringId;     /* Max String Ids */
extern U16 CurrMaxStringNum;    /* Max Number Ids */
extern U16 CurrMaxStringIdSearch;

extern U16 CurrMaxImageId;  /* Max String Ids */
extern U16 CurrMaxSearchImageId;
extern U16 CurrMaxImageNum; /* Max Number Ids */

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
/* 040805 CustPack: Calvin added */
extern U16 CurrMaxImageIdEXT;   /* Max String Ids */
extern U16 CurrMaxSearchImageIdEXT;
extern U16 CurrMaxImageNumEXT;  /* Max Number Ids */

/* Calvin end */
/* __CUSTPACK_MULTIBIN Calvin END */

extern const CUSTOM_AUDIO_MAP AudioIdMap[];
extern const CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMap[];
extern const CUSTOM_AUDIO_MAP AudioIdMapEXT[];
extern const CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMapEXT[];
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern const U32 CurrMaxENFBAssociatedIDNum;
extern const CUSTOM_ENFB AssociatedID_map[];
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

extern CUSTOM_AUDIO *nCustAudioNames;
extern CUSTOM_AUDIO *nCustAudioNamesEXT;

extern U16 CurrMaxAudioId;
extern U16 CurrMaxSearchAudioId;
extern U16 CurrMaxAudioNum;

extern U16 CurrMaxAudioIdEXT;
extern U16 CurrMaxSearchAudioIdEXT;
extern U16 CurrMaxAudioNumEXT;

extern const CUSTOM_BINARY_MAP BinaryIdMap[];
extern const CUSTOM_BINARY_SEARCH_MAP BinaryIdSearchMap[];

extern CUSTOM_BINARY nCustBinaryNames[];


extern U16 CurrMaxBinaryId;
extern U16 CurrMaxSearchBinaryId;
extern U16 CurrMaxBinaryNum;

extern CUSTOM_MENU_RES_ENTRY *gMenuResEntry;

extern const CUSTOM_FONT_MAP *FontIdMapEXT;
extern const CUSTOM_FONT_SEARCH_MAP *FontIdSearchMapEXT;
extern CUSTOM_FONT *nCustFontNamesEXT;

extern U16 CurrMaxFontIdEXT;
extern U16 CurrMaxSearchFontIdEXT;
extern U16 CurrMaxFontNumEXT;

extern const U32 mmi_rg_menu_mainmenuid_total;
extern const mmi_rg_menu_mainmenu_img_id_struct mmi_rg_menu_mainmenu_img_id_array[];
extern U8 gLanguageMappingArray[];
/* 101205 audio resource Calvin End */

#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
extern const CUSTOM_IMAGE	mtk_nCustGroupNames[];
#endif //__MMI_RESOURCE_IMAGE_GROUP_COMPRESS__

#if defined( __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)
// Working buffer of image group decompression
// extra 4 bytes for group header
static S8 mmi_res_image_group_buffer[RES_MULTI_IMG_GROUP_MAX_SIZE];
#endif // __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__

#if defined (__MMI_RESOURCE_IMAGE_THIRD_ROM__)
// To load compressed image group data from 3rd ROM
static S8 mmi_res_nand_image_group_buffer[RES_MULTI_IMG_GROUP_MAX_SIZE];
#endif // __MMI_RESOURCE_STR_THIRD_ROM__

/***************************************************************************** 
* Global Function
*****************************************************************************/
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
extern void set_current_language_for_hindi_rules(void);
#endif 

#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
extern S8 *GetImageBufferData(S8* ImageHandle);
extern void SetImageBufferFlushable(S8* imageHandle);
static void SetImageBufferNonFlushableNoLock(S8* imageHandle);
extern MMI_BOOL FlushImageBufferCacheForce(void);
extern void InitImageResourceCache(void);
#ifdef __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__
extern S8 *DebugGetImageRaw(U16 ImageId);
extern S8 *DebugGetImage(U16 ImageId);
#endif //__MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__
#ifdef __MMI_RESOURCE_UT_IMAGE_GROUP_DEBUG_HELPER__
extern S8 *DebugGetImageHandle(U16 ImageId);
extern S8 *DebugGetImageHandleRaw(U16 ImageId);
extern MMI_BOOL DebugImageCompare(S8 * image, S8* image2);
#endif //__MMI_RESOURCE_UT_IMAGE_GROUP_DEBUG_HELPER__

#endif //__MMI_RESOURCE_IMAGE_GROUP_COMPRESS__

#ifdef DEVAPP_RESOURCE
extern S8* DevAppGetString(U16 StringId);
extern S8* DevAppGetImage(U16 ImageId);
extern S8* DevAppGetAudio(U16 AudioId);
extern U16 DevAppGetParentItemId(U16 ItemId);
extern U16 DevAppGetNumOfChild(U16 ItemId);
extern U16 DevAppGetStringIdOfItem(U16 ItemId);
extern U16 DevAppGetImageIdOfItem(U16 ItemId);
extern U16 DevAppGetDispAttributeOfItem(U16 ItemId);
extern U16 DevAppGetSeqItemId(U16 ParentItemId, U16 Seq);
extern U16 DevAppGetSeqItemStringId(U16 ParentItemId, U16 Seq);
extern U16 DevAppGetSeqItemImageId(U16 ParentItemId, U16 Seq);
extern void DevAppGetSequenceItemIds(U16 ParentItemId, U16 *ItemIds);
extern void DevAppGetSequenceStringIds(U16 ParentItemId, U16 *StringIds);
extern U8 DevAppGetIndexOfStringId(U16 ParentItemId, U16 StringId);
extern void DevAppGetSequenceImageIds(U16 ParentItemId, U16 *ImageIds);
extern mmi_ret mmi_res_devapp_hide_dim_menu_init();

extern U16 DevAppGetNumOfChild_Ext(U16 menu_item_id);
extern U16 DevAppGetSeqItemId_Ext(U16 parent_item_id, U16 index);
extern U16 DevAppGetSequenceItemIds_Ext(U16 parent_item_id, U16 *ItemIds);
extern U16 DevAppGetSequenceStringIds_Ext(U16 parent_item_id, U16 *StringIds);
extern U16 DevAppGetSequenceImageIds_Ext(U16 parent_item_id, U16 *ImageIds);
extern U8 DevAppGetIndexOfStringId_Ext(U16 parent_item_id, U16 StringId);
#endif

#ifndef __MTK_TARGET__
/* MTE image resource replacement */
extern U8 *mmi_mte_get_image_resource_buffer_by_id(U32 image_id);
extern S32 mmi_mte_is_resource_replacement_working(void);
extern S32 mmi_mte_is_active(void);
#endif /* __MTK_TARGET__ */

extern S8* mmi_res_get_theme_image(U16 id);
extern S8* mmi_res_get_theme_audio(U16 id);
extern S8* mmi_res_get_theme_binary(U16 id);
extern MMI_BOOL mmi_res_theme_cache_get_image_size(U16 id, U16 * width, U16 * height);
S8 *GetImageRaw(U16 ImageId);

extern U8 *GetFontRaw(U16 FontId);

static const S8 empty_wstr[] = {0x00, 0x00};

#define ARRAY_COUNT(a)  (sizeof(a)/sizeof(a[0]))

FuncPtr mmi_res_menu_get_hilite_hdlr(MMI_MENU_ID menu_id)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    U32 index;
    
    if (mmi_frm_binary_search((U32)menu_id, 
             (mmi_frm_pair_data_struct*)mmi_frm_const_hilite_hdlr_table,
             (U32)ARRAY_COUNT(mmi_frm_const_hilite_hdlr_table), &index))
    {
        return mmi_frm_const_hilite_hdlr_table[index].hilite_hdlr;
    }
#endif//    
    return NULL;
}


FuncPtrShort mmi_res_menu_get_hint_hdlr(MMI_MENU_ID menu_id)
{
    U32 index;
    
    if (mmi_frm_binary_search((U32)menu_id, 
             (mmi_frm_pair_data_struct*)mmi_frm_const_hint_hdlr_table,
             (U32)ARRAY_COUNT(mmi_frm_const_hint_hdlr_table), &index))
    {
        return mmi_frm_const_hint_hdlr_table[index].hint_hdlr;
    }

    return NULL;
}

/* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_if_enfb
 * DESCRIPTION
 *  test if img is an E-NFB image resource
 * PARAMETERS
 *  img     [IN]    image pointer
 * RETURNS
 *  MMI_BOOL    MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_frm_enfb_if_enfb(const U8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (img[0] == IMAGE_TYPE_ENFB)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_if_associated
 * DESCRIPTION
 *  test if img is associated with other images
 * PARAMETERS
 *  img     [IN]    image pointer
 * RETURNS
 *  MMI_BOOL    MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_frm_enfb_if_associated(const U8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (img[1])
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_img_assid
 * DESCRIPTION
 *  get associated ID number of E-NFB image resource
 * PARAMETERS
 *  id      [IN]    image pointer
 * RETURNS
 *  U16             associated ID numer
 *****************************************************************************/
U32 mmi_frm_enfb_get_img_assid(const U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 1; i < CurrMaxENFBAssociatedIDNum; i++)
	{
		const CUSTOM_ENFB *enfb = NULL;
        U16 count;

		enfb = AssociatedID_map + i;
        count = AssociatedID_map[i].count;
		for (j = 0; j < count; j++)
		{
			if (enfb->IDs[j] == id)
			{
				return i;
			}
		}
	}

	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_assid_count
 * DESCRIPTION
 *  get IDs count within an associated ID group
 * PARAMETERS
 *  assid   [IN]    image pointer
 * RETURNS
 *  U32             IDs count
 *****************************************************************************/
U16 mmi_frm_enfb_get_assid_count(const U16 assid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return AssociatedID_map[assid].count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_img_offset
 * DESCRIPTION
 *  get E-NFB image offset
 * PARAMETERS
 *  img     [IN]    image pointer
 * RETURNS
 *  U32             image offset
 *****************************************************************************/
U32 mmi_frm_enfb_get_img_offset(const U8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (U32)img[4] | (img[5] << 8) | (img[6] << 16) | (img[7] << 24);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_img_size
 * DESCRIPTION
 *  get E-NFB image size
 * PARAMETERS
 *  img     [IN]    image pointer
 * RETURNS
 *  U32             image size
 *****************************************************************************/
U32 mmi_frm_enfb_get_img_size(const U8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (U32)img[8] | (img[9] << 8) | (img[10] << 16) | (img[11] << 24);
}

#ifndef __POPULATE_NO_IMAGE_DATA__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_img_list
 * DESCRIPTION
 *  get E-NFB image list
 * PARAMETERS
 *  id      [IN]    image id
 *  list    [OUT]   image list
 * RETURNS
 *  U32             image offset
 *****************************************************************************/
MMI_BOOL mmi_frm_enfb_get_img_list(const U16 assid, const U16 count, mmi_frm_resmem_res_info_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (list != NULL)
	{
		for (i = 0; i < count; i++)
		{
			U8 *img;

#if 0
/* under construction !*/
#endif /* 0 */
            img = (U8*) GetImageRaw(AssociatedID_map[assid].IDs[i]);

			list[i].id = AssociatedID_map[assid].IDs[i];
			list[i].offset = mmi_frm_enfb_get_img_offset(img);
			list[i].size = mmi_frm_enfb_get_img_size(img);
		}

		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}
#endif //__POPULATE_NO_IMAGE_DATA__
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
/* 101806 E-NFB end */

/*****************************************************************************
 * FUNCTION
 *  GetMenuItemIndex
 * DESCRIPTION
 *  Function to look for menu item index in nCustMenus by searching in the map table
 *  
 * PARAMETERS
 *  ItemId          [IN]        
 * RETURNS
 *  the index in nCustMenus.
 *****************************************************************************/
U16 GetMenuItemIndex(U16 ItemId)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = gMenuResEntry->MaxMapEntry;
    S32 nMid;
    CUSTOM_MENU_SEARCH_MAP *CustMenuSearchMap = gMenuResEntry->MenuSearchMap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;;
        if ((CustMenuSearchMap[nMid].minId <= ItemId) && (CustMenuSearchMap[nMid].maxId >= ItemId))
        {
            return (CustMenuSearchMap[nMid].index + ItemId - CustMenuSearchMap[nMid].minId);
        }
        if (ItemId > CustMenuSearchMap[nMid].minId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }    
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) */	
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_menuid_by_index
 * DESCRIPTION
 *  Function to look for menu item index in nCustMenus by searching in the map table
 *  
 * PARAMETERS
 *  ItemId          [IN]        
 * RETURNS
 *  the index in nCustMenus.
 *****************************************************************************/
MMI_MENU_ID mmi_res_get_menuid_by_index(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = gMenuResEntry->MaxMapEntry;
    S32 nMid;
    CUSTOM_MENU_SEARCH_MAP *CustMenuSearchMap = gMenuResEntry->MenuSearchMap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;;
        if ((CustMenuSearchMap[nMid].index <= index) && 
            (CustMenuSearchMap[nMid].index + (CustMenuSearchMap[nMid].maxId - CustMenuSearchMap[nMid].minId) >= index))
        {
            return (index - CustMenuSearchMap[nMid].index + CustMenuSearchMap[nMid].minId);
        }
        if (index > CustMenuSearchMap[nMid].index)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }    
    return 0;
}

mmi_ret mmi_res_hide_dim_menu_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(MenuItemMask, 0, ((((U32)av_total_menuitem) / 8) + 1));

#ifdef DEVAPP_RESOURCE
    mmi_res_devapp_hide_dim_menu_init();
#endif

    return MMI_RET_OK;
}


static mmi_res_str_struct mmi_res_dynamic_str[MMI_RES_MAX_DYNAMIC_STR_COUNT];


/*****************************************************************************
 * FUNCTION
 *  mmi_res_dynamic_str_init
 * DESCRIPTION
 *  Function to init dynamic string(Only for MRE currently)
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET_OK:  Init successful
 *****************************************************************************/
mmi_ret mmi_res_dynamic_str_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_res_dynamic_str, 0, sizeof(mmi_res_str_struct) * MMI_RES_MAX_DYNAMIC_STR_COUNT);
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_res_dynamic_str_add
 * DESCRIPTION
 *  Function to add string associated with the ID in dynamic string(Only for MRE currently)
 * PARAMETERS
 *  id        [IN]        String ID
 *  buf       [IN]        String buffer pointer
 * RETURNS
 *  MMI_RET_OK:  Added successful
 *  MMI_RET_ERR: MAX count, can't add any more.
 *****************************************************************************/
mmi_ret mmi_res_dynamic_str_add(mmi_str_id id, WCHAR *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i < MMI_RES_MAX_DYNAMIC_STR_COUNT; i++)
    {
        if (mmi_res_dynamic_str[i].id == 0)
        {
            mmi_res_dynamic_str[i].id = id;
            mmi_res_dynamic_str[i].str_buf = buf;
            break;
        }
    }

    if (i == MMI_RES_MAX_DYNAMIC_STR_COUNT)
    {
        return MMI_RET_ERR;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_dynamic_str_remove
 * DESCRIPTION
 *  Function to delete string associated with the ID in dynamic string(Only for MRE currently)
 * PARAMETERS
 *  id        [IN]        String ID
 * RETURNS
 *  MMI_RET_OK:  removed successful
 *****************************************************************************/
mmi_ret mmi_res_dynamic_str_remove(mmi_str_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i < MMI_RES_MAX_DYNAMIC_STR_COUNT; i++)
    {
        if (mmi_res_dynamic_str[i].id == id)
        {
            mmi_res_dynamic_str[i].id = 0;
            mmi_res_dynamic_str[i].str_buf = NULL;
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_dynamic_string_get
 * DESCRIPTION
 *  Function to get string associated with the ID in dynamic string (Only for MRE currently)
 * PARAMETERS
 *  id        [IN]        String ID
 * RETURNS
 *  the String Mapped with the Id.
 *****************************************************************************/
WCHAR* mmi_res_dynamic_str_get(mmi_str_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id < MRE_BASE || id > MRE_BASE_MAX)
    {
        return NULL;
    }
    
    
    for (i=0; i < MMI_RES_MAX_DYNAMIC_STR_COUNT; i++)
    {
        if (mmi_res_dynamic_str[i].id == id)
        {
            return mmi_res_dynamic_str[i].str_buf;
        }
    }
    
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetString
 * DESCRIPTION
 *  Function to get string associated with the stringId
 *  
 *  The function uses the variable CurrMaxStringId inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  StringId        [IN]        
 *  U16(?)          [IN]        StringId
 *  char(?)         [OUT]       Displayed String.
 * RETURNS
 *  the String Mapped with the Id.
 *****************************************************************************/
S8 *GetString(U16 StringId)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __POPULATE_NO_STRING_DATA__
    S8 *ret_str = NULL;
    S32 nFirst = 0;
    S32 nLast = CurrMaxStringIdSearch;
    S32 nMid;
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 offset;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (StringId == 0)
    {
        return (S8*) empty_wstr;
    }    


    /* Get string from dynamic list */
    ret_str = (S8*)mmi_res_dynamic_str_get(StringId);
    if (ret_str != NULL)
    {
        return ret_str;
    }

    /* Get String from Resource list */
    if (g_is_switch_language)
    {   
        /*check if switching language */
        return NULL;
    }

#ifdef DEVAPP_RESOURCE
    if ((StringId >= DEVAPP_BASE && StringId <= DEVAPP_BASE_MAX) ||
        (StringId >= AVK_BASE && StringId <= AVK_BASE_MAX))
    {
        S8 *ret_string = DevAppGetString(StringId);
        MMI_RES_STR_CHK_RECORD(StringId, (WCHAR*)ret_string);
        return ret_string;
    }
#endif

    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;
        if (nMid >= CurrMaxStringIdSearch)
        {
            break;
        }
        if ((gpStrMapSearch[nMid].nMinStrId <= StringId) && (gpStrMapSearch[nMid].nMaxStrId >= StringId))
        {
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
            /* fixed string */
            if(gpStrMapSearch[nMid].nMapIndex >= TRANS_STRING_COUNT)
            {
                MMI_ASSERT(gpFixedStringRes != NULL);
                if(g_isf16bit)
                {
                    offset = gpFixedStringMapRes16[gpStrMapSearch[nMid].nMapIndex + StringId - gpStrMapSearch[nMid].nMinStrId - TRANS_STRING_COUNT] << 1;
                }
                else
                {
                    offset = gpFixedStringMapRes[gpStrMapSearch[nMid].nMapIndex + StringId - gpStrMapSearch[nMid].nMinStrId - TRANS_STRING_COUNT] << 1;
                }
                ret_str = (S8*)&gpFixedStringRes[offset];
            }
            else
            {
                if (g_is16bit)
                {
                    offset = gpStringMapRes16[((gpStrMapSearch[nMid].nMapIndex) + (StringId) - (gpStrMapSearch[nMid].nMinStrId))] << 1;
                }
                else
                {
                    offset = gpStringMapRes[((gpStrMapSearch[nMid].nMapIndex) + (StringId) - (gpStrMapSearch[nMid].nMinStrId))] << 1;
                }
                if (offset > gMaxNonDupStrOffset)
                {
                    MMI_ASSERT(gpStringResDup);
                    ret_str = (S8*) &gpStringResDup[offset - gMaxNonDupStrOffset];
                }
                else
                {
                    ret_str = (S8*) &gpStringRes[offset];
                }
            }
#else /* __MMI_RESOURCE_ENFB_SUPPORT__ */

            ret_str = (S8*) &
                gpStringRes[(gpStringMapRes
                             [((gpStrMapSearch[nMid].nMapIndex) + (StringId) -
                               (gpStrMapSearch[nMid].nMinStrId))]) << 1];

#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
            break;
        }
        
        if (StringId > gpStrMapSearch[nMid].nMinStrId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    if (ret_str != NULL)
    {
        MMI_RES_STR_CHK_RECORD(StringId, (WCHAR*)ret_str);
        return ret_str;
    }
#endif //__POPULATE_NO_STRING_DATA__
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) */	
    return (S8*) empty_wstr;
}


/*****************************************************************************
 * FUNCTION
 *  fread_all
 * DESCRIPTION
 *  Function to get filename associated with the ImageId
 *  
 *  The function uses the variable CurrMaxImageId inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  handle          [IN]        
 *  dest            [?]         
 *  dest_size       [IN]        
 *  want_size       [IN]        
 *  U16(?)          [IN]        ImageId.
 *  char(?)         [OUT]       Displayed Image Filename.
 * RETURNS
 *  Returns the filename associated with the ImageId.
 *****************************************************************************/
#if defined(__MMI_DEFAULT_THEME_3__)

#include "filesystemdef.h"
static U16 cache_image_id;
static U32 cache_image_content[30000 / 4];

/* MTK added, Max: to clear gif cache 0202, modified by JF */
#if !defined(__BW_MMI__) && !defined(WIN32)     /* Target version shall use this library */
extern void GIF_clear_cache(void);
#endif 
/* MTK end */
static kal_bool fread_all(FS_HANDLE handle, U8 *dest, S32 dest_size, S32 want_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(dest_size >= want_size);

    FS_Seek(handle, 0, FS_FILE_BEGIN);

    while (want_size > 0)
    {
        S32 nRead;

        if (FS_Read(handle, dest, want_size, (kal_uint32*) & nRead) != FS_NO_ERROR)
        {
            return KAL_FALSE;
        }

        want_size -= nRead;
        dest += nRead;
    }
    return KAL_TRUE;
}
#endif /* defined(__MMI_DEFAULT_THEME_3__) */ 

#ifndef __POPULATE_NO_IMAGE_DATA__
/*****************************************************************************
 * FUNCTION
 *  GetImageFromIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S8 *GetImageFromIndex(
        U16 ImgID,
        const CUSTOM_IMAGE_MAP *ImgIDMap,
        const CUSTOM_IMAGE_SEARCH_MAP *ImgIDSearchMap,
        const CUSTOM_IMAGE *ImgNames,
        U16 count)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = count - 1;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast)/2;
        if ((ImgIDSearchMap[nMid].minImageId <= ImgID) &&
            (ImgIDSearchMap[nMid].maxImageId >= ImgID))
        {
            U16 img_index;

            img_index = (U16)ImgIDMap[(ImgIDSearchMap[nMid].index) + (ImgID) - (ImgIDSearchMap[nMid].minImageId)].nImageNum;

#ifdef __MMI_THEMES_V2_SUPPORT__
            {   /* get image from theme */
                S8 *img = GetImageFromTheme(ImgID, img_index, ImgIDMap, ImgIDSearchMap, ImgNames);
                if (img != NULL)
                {
                    return img;
                }
            }
#endif /* __MMI_THEMES_V2_SUPPORT__ */

            return (S8*) (ImgNames[img_index].pImage);
        }

        if (ImgID > ImgIDSearchMap[nMid].minImageId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) */
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  GetImageRaw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *GetImageRaw(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ImageId >= DEVAPP_BASE && ImageId <= DEVAPP_BASE_MAX) ||
        (ImageId >= AVK_BASE && ImageId <= AVK_BASE_MAX))
    {
        S8 *ret_image = DevAppGetImage(ImageId);

        return ret_image;
    }
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_DEFAULT_THEME_3__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if !defined(__BW_MMI__) && !defined(WIN32)
/* under construction !*/
#endif 
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
#endif /* defined(__MMI_DEFAULT_THEME_3__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    {
        S8 *img;

        img = GetImageFromIndex(
                ImageId,
                ImageIdMap,
                ImageIdSearchMap,
                nCustImageNames,
                CurrMaxSearchImageId);

        /* CustPack */
        if (img == NULL)
        {
            img = GetImageFromIndex(
                    ImageId,
                    ImageIdMapEXT,
                    ImageIdSearchMapEXT,
                    nCustImageNamesEXT,
                    CurrMaxSearchImageIdEXT);
        }

        /* Image from pluto theme structure */
        if (img == NULL)
        {
        #if !defined(__IOT__)
            img = GetImageTheme(ImageId);
        #endif
        }

        if (img != NULL)
        {
            return img;
        }
        else
        {
            return (S8*) (nCustImageNames[0].pImage);
        }
    }
#else
	return NULL;
#endif
}
#endif //__POPULATE_NO_IMAGE_DATA__

/* 101806 E-NFB start */
/*****************************************************************************
 * FUNCTION
 *  GetImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *GetImage(U16 ImageId)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    #ifndef __POPULATE_NO_IMAGE_DATA__ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__) && !defined(__IOT__)
    /* MTE image resource replacement */
    if (mmi_mte_is_resource_replacement_working())
    {
        /* only handle image resources here. */
        if (img = mmi_mte_get_image_resource_buffer_by_id((U32)ImageId))
        {
            return img;
        }
    }        
#endif /* __MTK_TARGET__ */
    
#if 0
/* under construction !*/
#endif
    /* get specific images stored in theme structure */
#if !defined(__IOT__)
    img = (S8*)GetImageTheme(ImageId);
#endif

    if (img != NULL)
    {
        return (S8*)img;
    }

    img = (S8*)mmi_res_get_theme_image(ImageId);
    if (img != NULL)
    {
        return (S8*)img;
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* check cache */
    img = mmi_frm_resmem_if_ramed(ImageId);
    if (img != NULL)
    {
        return (S8*)img;
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    /* load image raw data */
    img = (S8*)GetImageRaw(ImageId);
#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
#ifdef __MMI_RESOURCE_UT_HOOK_WITH_GET_IMAGE_CONTENT__
        // GetImageContent UT:
        // Simulate the origianl GetImageRaw functionality with cache
    img = GetImageData(img);
#elif defined(__MMI_RRESOURCE_UT_HOOK_WITH_ORIGINAL_COMPARE__)
    {
        // GetImageContent UT:
        // Compare image from cached decompression pool and original image pool
        // But return the image in original image pool,
        // so that the behavior is just like __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__ disabled state
        S8* imgOriginal = DebugGetImageRaw(ImageId);
        img = GetImageData(img);
        if(DebugImageCompare(img, imgOriginal) != MMI_TRUE){
            MMI_ASSERT(0);
        }
        img = imgOriginal;
    }
#endif // __MMI_RESOURCE_UT_HOOK_WITH_GET_IMAGE_CONTENT__
#endif // __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
    if (img == NULL)
    {
		return (S8*)img;
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* check E-NFB */
    if (mmi_frm_enfb_if_enfb(img) == MMI_TRUE)
    {
        U32 offset, size;

        /* get size & offset */
        offset = mmi_frm_enfb_get_img_offset(img);
        size = mmi_frm_enfb_get_img_size(img);

        /* check associated */
        if (mmi_frm_enfb_if_associated(img) == MMI_FALSE)
        {
            /* load one image from E-NFB */
            img = mmi_frm_resmem_load_single_image(ImageId, offset, size);
        }
        else
        {
            U16 assid, count;
            mmi_frm_resmem_res_info_struct *list;

            /* get associated ID & count */
            assid = mmi_frm_enfb_get_img_assid(ImageId);
            count = mmi_frm_enfb_get_assid_count(assid);

            /* allocated memory */
            list = OslMalloc(count * sizeof(mmi_frm_resmem_res_info_struct));
            if (list != NULL)
            {
                memset(list, 0, count * sizeof(mmi_frm_resmem_res_info_struct));

                /* get associated list */
                if (mmi_frm_enfb_get_img_list(assid, count, list) == MMI_TRUE)
                {
                    /* load associated images from E-NFB */
                    img = mmi_frm_resmem_load_multi_image(ImageId, list, count);
                }

                /* free memory */
                OslMfree(list);
                list = NULL;
            }
            else
            {
                /* memory allocation failed, load only one image */
                img = mmi_frm_resmem_load_single_image(ImageId, offset, size);
            }
        }
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    return (S8*)img;
    #else //__POPULATE_NO_IMAGE_DATA__
    return NULL;
    #endif //__POPULATE_NO_IMAGE_DATA__
#else
    return NULL;
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) */
}

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
void GetResourceENFBData(S32 enfb_handle,S32 offset,void *data, S32 data_size)
{
    mmi_frm_resmem_load_data(enfb_handle + offset,data, data_size);
}
#endif


#ifdef __MMI_THEMES_V2_SUPPORT__        /* ritesh */


/*****************************************************************************
 * FUNCTION
 *  GetImageIndex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ImageId     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 GetImageIndex(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = CurrMaxSearchImageId;
    S32 nMid = (nFirst + nLast) / 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nLast >= nFirst) /* && (nLast!=0) */ )
    {
        nMid = (nFirst + nLast) / 2;
        if (nMid >= CurrMaxSearchImageId)
        {
            return 0;
        }
        if ((ImageIdSearchMap[nMid].minImageId <= ImageId) && (ImageIdSearchMap[nMid].maxImageId >= ImageId))
        {
            break;
        }
        if (ImageId > ImageIdSearchMap[nMid].minImageId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return ImageIdMap[(ImageIdSearchMap[nMid].index) + (ImageId) - (ImageIdSearchMap[nMid].minImageId)].nImageNum;
}


/*****************************************************************************
 * FUNCTION
 *  GetDefaultImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S8 *GetDefaultImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*) (nCustImageNames[0].pImage);
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

/* 101205 Audio Resource Calvin Start */


/*****************************************************************************
 * FUNCTION
 *  GetAudio
 * DESCRIPTION
 *  Function to get audio data associated with the AudioId
 *  
 *  The function uses the variable CurrMaxAudioId inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  AudioId     [IN]        
 *  U16(?)      [IN]        AudioId.
 *  char(?)     [OUT]       Displayed Audio data pointer
 * RETURNS
 *  Returns the audio datad with the AudioId.
 *****************************************************************************/
S8 *GetAudio(U16 AudioId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* audio = NULL;
    S32 nFirst = 0;
    S32 nLast = CurrMaxSearchAudioId;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif

#ifdef DEVAPP_RESOURCE
    if ((AudioId >= DEVAPP_BASE && AudioId <= DEVAPP_BASE_MAX) ||
        (AudioId >= AVK_BASE && AudioId <= AVK_BASE_MAX))
    {
        S8 *ret_audio = DevAppGetAudio(AudioId);

        return ret_audio;
    }
#endif

    audio = mmi_res_get_theme_audio(AudioId);
    if (audio != NULL)
    {
        return (S8*)audio;
    }

    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if (nMid >= CurrMaxSearchAudioId)
        {
            break;
        }
        if ((AudioIdSearchMap[nMid].minAudioId <= AudioId) && (AudioIdSearchMap[nMid].maxAudioId >= AudioId))
        {
            return (S8*)
                nCustAudioNames[AudioIdMap
                                [(AudioIdSearchMap[nMid].index) + (AudioId) -
                                 (AudioIdSearchMap[nMid].minAudioId)].nAudioNum].pAudio;
        }
        if (AudioId > AudioIdSearchMap[nMid].minAudioId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    /* for custpack */
    nFirst = 0;
    nLast = CurrMaxSearchAudioIdEXT;
    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if (nMid >= CurrMaxSearchAudioIdEXT)
        {
            break;
        }
        if ((AudioIdSearchMapEXT[nMid].minAudioId <= AudioId) && (AudioIdSearchMapEXT[nMid].maxAudioId >= AudioId))
        {

            return (S8*)
                nCustAudioNamesEXT[AudioIdMapEXT
                                   [(AudioIdSearchMapEXT[nMid].index) + (AudioId) -
                                    (AudioIdSearchMapEXT[nMid].minAudioId)].nAudioNum].pAudio;
        }
        if (AudioId > AudioIdSearchMapEXT[nMid].minAudioId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return (S8*) (nCustAudioNames[0].pAudio);
}


/*****************************************************************************
 * FUNCTION
 *  GetBinary
 * DESCRIPTION
 *  Function to get audio data associated with the BinaryId
 *  The function uses the variable CurrMaxBinaryId inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  BinaryId     : [IN]        BinaryId
 * RETURNS
 *  Returns the binary data associated with the BinaryId.
 *****************************************************************************/
S8 *GetBinary(U16 BinaryId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* bin = NULL;
    S32 nFirst = 0;
    S32 nLast = CurrMaxSearchBinaryId;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    {
        extern S8* mmi_res_otf_get_layout(U16 id);
        S8* bin = mmi_res_otf_get_layout(BinaryId);

        if (bin)
        {
            return bin;
        }
    }
#endif /* __MTK_TARGET__ */

    bin = mmi_res_get_theme_binary(BinaryId);
    if (bin != NULL)
    {
        return (S8*)bin;
    }

    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;;
        if ((BinaryIdSearchMap[nMid].minBinaryId <= BinaryId) && (BinaryIdSearchMap[nMid].maxBinaryId >= BinaryId))
        {
            return (S8*)
                nCustBinaryNames[BinaryIdMap
                                [(BinaryIdSearchMap[nMid].index) + (BinaryId) -
                                 (BinaryIdSearchMap[nMid].minBinaryId)].nBinaryNum].pBinary;
        }
        if (BinaryId > BinaryIdSearchMap[nMid].minBinaryId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return (S8*) (nCustBinaryNames[0].pBinary);
}


/*****************************************************************************
 * FUNCTION
 *  GetFont
 * DESCRIPTION
 *  Function to get Font data associated with the FontId
 *  
 *  The function uses the variable CurrMaxFontIdEXT inside the for loop which
 *  is set inside the WriteRes.c file.
 * PARAMETERS
 *  FontId     [IN]        
 * RETURNS
 *  Returns the font datad with the FontId.
 *****************************************************************************/
U8 *GetFontRaw(U16 FontId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nFirst = 0;
    S32 nLast = CurrMaxSearchFontIdEXT;
    S32 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for custpack */
    nFirst = 0;
    nLast = CurrMaxSearchFontIdEXT;
    while ((nLast >= nFirst))
    {
        nMid = (nFirst + nLast) / 2;
        
        if (nMid >= CurrMaxSearchFontIdEXT)
        {
            break;
        }
        
        if ((FontIdSearchMapEXT[nMid].minFontId <= FontId) && (FontIdSearchMapEXT[nMid].maxFontId >= FontId))
        {
            return (U8*)
                nCustFontNamesEXT[FontIdMapEXT
                                   [(FontIdSearchMapEXT[nMid].index) + (FontId) -
                                    (FontIdSearchMapEXT[nMid].minFontId)].nFontNum].pFont;
        }
        if (FontId > FontIdSearchMapEXT[nMid].minFontId)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }
    }

    return NULL;
}




/*****************************************************************************
 * FUNCTION
 *  GetParentItemId
 * DESCRIPTION
 *  Function to get Parent MenuItemId of the Given MenuItemId.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       Parent MenuItemId of the given MenuItemId.
 * RETURNS
 *  the Parent MenuItemId.
 *****************************************************************************/
U16 GetParentItemId(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_MENU_ID ret_id;
    S32 last = gMenuResEntry->MaxMapEntry - 1;
    S32 count;
    S32 i, idx;
    CUSTOM_MENU_SEARCH_MAP *CustMenuSearchMap = gMenuResEntry->MenuSearchMap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ItemId >= MENU_ID_DEVAPP_START && ItemId <= MENU_ID_DEVAPP_END ) ||
        (ItemId >= DEVAPP_BASE && ItemId <= DEVAPP_BASE_MAX) ||
        (ItemId >= AVK_BASE && ItemId <= AVK_BASE_MAX))
    {
        return DevAppGetParentItemId(ItemId);
    }
#endif

    ret_id = nCustMenus[GetMenuItemIndex(ItemId)].nParentId;
    if (ret_id == 0)
    {
        /* if parent ID is 0, need to find ID in the tree, and return the first result as the parent ID */
        /* Calculate nCustMenus's count */
        count = CustMenuSearchMap[last].index + (CustMenuSearchMap[last].maxId - CustMenuSearchMap[last].minId) + 1;

        for (i = 0; i < count; i++)
        {
            for (idx = 0; idx < nCustMenus[i].nNumofMenuItem; idx++)
            {
                if (nCustMenus[i].nOrderMenuItemId[idx] == ItemId)
                {
                    ret_id = mmi_res_get_menuid_by_index((U16)i);
                    return ret_id;
                }
            }
        }
    }

    return ret_id;

}

/* MTK Leo add 20040409, to sync titleicon */


/*****************************************************************************
 * FUNCTION
 *  GetRootParentIndex
 * DESCRIPTION
 *  Function to get Parent MenuItemId of the Given MenuItemId in Mainmenu
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       Parent MenuItemId of the given MenuItemId in Mainmenu.
 * RETURNS
 *  the Parent MenuItemId in Mainmenu.
 *****************************************************************************/
U16 GetRootParentIndex(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 RootId;
    U16 parent_id;
    U16 idx;

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    U16 parent_idx = 0;
    U16 grand_parent_id = 0;
    U16 num_of_child = 0;
    U16 total_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_id = GetParentItemId(ItemId);

    /* Group menu id */
    if (parent_id == 1)
    {
        return 0;
    }

    grand_parent_id = GetParentItemId(parent_id);

    RootId = ItemId;

    while (grand_parent_id != IDLE_SCREEN_MENU_ID)
    {
        RootId = parent_id;
        parent_id = grand_parent_id;
        grand_parent_id = GetParentItemId(grand_parent_id);
        if (parent_id == 0)
        {
            return 0xff;
        }
    }

    num_of_child = GetNumOfChild(IDLE_SCREEN_MENU_ID);
    for (parent_idx = 0; parent_idx < num_of_child; parent_idx++)
    {
        if (GetSeqItemId(IDLE_SCREEN_MENU_ID, parent_idx) == parent_id)
        {
            num_of_child = GetNumOfChild(parent_id);
            for (idx = 0; idx < num_of_child; idx++)
                if (GetSeqItemId(parent_id, idx) != RootId)
                {
                    total_idx++;
                }
                else
                {
                    return total_idx;
                }
        }
        else
        {
            total_idx += GetNumOfChild(GetSeqItemId(IDLE_SCREEN_MENU_ID, parent_idx));
        }
    }

    return 0xff;

#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

    RootId = ItemId;
    parent_id = GetParentItemId(ItemId);
    if (parent_id != IDLE_SCREEN_MENU_ID)
    {   /* ItemId is not one of the itemIds of mainmenu */
        RootId = parent_id;
        parent_id = GetParentItemId(parent_id);
        while (parent_id != IDLE_SCREEN_MENU_ID)
        {
            RootId = parent_id;
            parent_id = GetParentItemId(parent_id);
            if (parent_id == 0)
            {
                return 0xff;
            }
        }
    }   /* RootId is the menu id in mainmenu */
    for (idx = 0; idx < nCustMenus[GetMenuItemIndex(IDLE_SCREEN_MENU_ID)].nNumofMenuItem; idx++)
    {
        if (nCustMenus[GetMenuItemIndex(IDLE_SCREEN_MENU_ID)].nOrderMenuItemId[idx] == RootId)
        {
            break;
        }
    }

    return idx;
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
}

/* MTK Leo end */


/*****************************************************************************
 * FUNCTION
 *  GetNumOfChild
 * DESCRIPTION
 *  Function to get Number of Childrens of the Given MenuItemId.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       Number of Childrens of the given MenuItemId.
 * RETURNS
 *  Number of Childrens.
 *****************************************************************************/
U16 GetNumOfChild(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ItemId >= MENU_ID_DEVAPP_START && ItemId <= MENU_ID_DEVAPP_END ) ||
        (ItemId >= DEVAPP_BASE && ItemId <= DEVAPP_BASE_MAX) ||
        (ItemId >= AVK_BASE && ItemId <= AVK_BASE_MAX))
    {
        return DevAppGetNumOfChild(ItemId);
    }
#endif
    return nCustMenus[GetMenuItemIndex(ItemId)].nNumofMenuItem;
}


/*****************************************************************************
 * FUNCTION
 *  GetStringIdOfItem
 * DESCRIPTION
 *  Function to get StringId of the Given MenuItemId.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       StringId.
 * RETURNS
 *  StringId of the given MenuItemId.
 *****************************************************************************/
U16 GetStringIdOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ItemId >= MENU_ID_DEVAPP_START && ItemId <= MENU_ID_DEVAPP_END ) ||
        (ItemId >= DEVAPP_BASE && ItemId <= DEVAPP_BASE_MAX) ||
        (ItemId >= AVK_BASE && ItemId <= AVK_BASE_MAX))
    {
        return DevAppGetStringIdOfItem(ItemId);
    }
#endif
    return nCustMenus[GetMenuItemIndex(ItemId)].nStrId;

}


/*****************************************************************************
 * FUNCTION
 *  GetImageIdOfItem
 * DESCRIPTION
 *  Function to get ImageId of the given MenuItemId.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       ImageId.
 * RETURNS
 *  ImageId of the given MenuItemId.
 *****************************************************************************/
U16 GetImageIdOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ItemId >= MENU_ID_DEVAPP_START && ItemId <= MENU_ID_DEVAPP_END ) ||
        (ItemId >= DEVAPP_BASE && ItemId <= DEVAPP_BASE_MAX) ||
        (ItemId >= AVK_BASE && ItemId <= AVK_BASE_MAX))
    {
        return DevAppGetImageIdOfItem(ItemId);
    }
#endif

     return nCustMenus[GetMenuItemIndex(ItemId)].nImageId;

}


/*****************************************************************************
 * FUNCTION
 *  GetDispAttributeOfItem
 * DESCRIPTION
 *  Function to get DispAttributes of the given MenuItemId.
 *  
 *  DispAttribute are like Matrix,List,Circular,Tab..etc.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       DispAttribute.
 * RETURNS
 *  DispAttribute which is passed to the UI Element.
 *****************************************************************************/
U16 GetDispAttributeOfItem(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ItemId >= MENU_ID_DEVAPP_START && ItemId <= MENU_ID_DEVAPP_END ) ||
        (ItemId >= DEVAPP_BASE && ItemId <= DEVAPP_BASE_MAX) ||
        (ItemId >= AVK_BASE && ItemId <= AVK_BASE_MAX))
    {
        return DevAppGetDispAttributeOfItem(ItemId);
    }
#endif
    return (U16)nCustMenus[GetMenuItemIndex(ItemId)].nDispAttribute;
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemId
 * DESCRIPTION
 *  Function to get MenuItemId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 *  U16(?)              [OUT]       MenuItemId.
 * RETURNS
 *  MenuItemId of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
U16 GetSeqItemId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef DEVAPP_RESOURCE
    if ((ParentItemId >= MENU_ID_DEVAPP_START && ParentItemId <= MENU_ID_DEVAPP_END ) ||
        (ParentItemId >= DEVAPP_BASE && ParentItemId <= DEVAPP_BASE_MAX) ||
        (ParentItemId >= AVK_BASE && ParentItemId <= AVK_BASE_MAX))
    {
        return DevAppGetSeqItemId(ParentItemId, Seq);
    }
#endif
    return nCustMenus[GetMenuItemIndex(ParentItemId)].nOrderMenuItemId[Seq];

}

/*****************************************************************************
 * FUNCTION
 *  GetChildMenuIDIndexByParentMenuID
 * DESCRIPTION
 *  Function to get the index of the given MenuItemId in the child sequence of the parent MenuItem.
 *  No hide attribute consideration.
 * PARAMETERS
 *  parentMenuId        [IN]        
 *  childMenuId         [IN]        
 *  a(?)                [IN]        Parent menu id
 *  b(?)                [IN]        Child menu id
 * RETURNS
 *  index >= 0: child manu id is a child of parent menu id, -1: if not
 *****************************************************************************/
S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    U16 nMenuItemList[MAX_SUB_MENUS];
    U16 numItems = GetNumOfChild(parentMenuId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceItemIds(parentMenuId, nMenuItemList);

    for (index = 0; index < numItems; index++)
    {
        if (nMenuItemList[index] == childMenuId)
        {
            return index;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemStringId
 * DESCRIPTION
 *  Function to get StringId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 *  U16(?)              [OUT]       StringId of the MenuItem.
 * RETURNS
 *  StringId of the MenuItem of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
U16 GetSeqItemStringId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ParentItemId >= MENU_ID_DEVAPP_START && ParentItemId <= MENU_ID_DEVAPP_END ) ||
        (ParentItemId >= DEVAPP_BASE && ParentItemId <= DEVAPP_BASE_MAX) ||
        (ParentItemId >= AVK_BASE && ParentItemId <= AVK_BASE_MAX))
    {
        return DevAppGetSeqItemStringId(ParentItemId, Seq);
    }
#endif

    return GetStringIdOfItem(nCustMenus[GetMenuItemIndex(ParentItemId)].nOrderMenuItemId[Seq]);

}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemImageId
 * DESCRIPTION
 *  Function to get ImageId of the given MenuItemId & Sequence.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  Seq                 [IN]        
 *  U16(?)              [OUT]       ImageId of the MenuItem.
 * RETURNS
 *  ImageId of the MenuItem of the given Parent MenuItemId & Sequence.
 *****************************************************************************/
U16 GetSeqItemImageId(U16 ParentItemId, U16 Seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ParentItemId >= MENU_ID_DEVAPP_START && ParentItemId <= MENU_ID_DEVAPP_END ) ||
        (ParentItemId >= DEVAPP_BASE && ParentItemId <= DEVAPP_BASE_MAX) ||
        (ParentItemId >= AVK_BASE && ParentItemId <= AVK_BASE_MAX))
    {
        return DevAppGetSeqItemImageId(ParentItemId, Seq);
    }
#endif
    return GetImageIdOfItem(nCustMenus[GetMenuItemIndex(ParentItemId)].nOrderMenuItemId[Seq]);

}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceItemIds
 * DESCRIPTION
 *  Function to get all the MenuItemIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  ItemIds             [?]         
 *  fills(?)            [OUT]       The input parameter. Memory is allocated by the caller.
 *  U16(?)              [IN]        MenuItemId i.e Parent & (U16 *) PoU16er containing the Array of MenuItemId.
 * RETURNS
 *  void
 *****************************************************************************/
void GetSequenceItemIds(U16 ParentItemId, U16 *ItemIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ParentItemId >= MENU_ID_DEVAPP_START && ParentItemId <= MENU_ID_DEVAPP_END ) ||
        (ParentItemId >= DEVAPP_BASE && ParentItemId <= DEVAPP_BASE_MAX) ||
        (ParentItemId >= AVK_BASE && ParentItemId <= AVK_BASE_MAX))
    {
        DevAppGetSequenceItemIds(ParentItemId, ItemIds);
        return;
    }
#endif

    for (j = 0; j < nCustMenus[GetMenuItemIndex(ParentItemId)].nNumofMenuItem; j++)
    {
        ItemIds[j] = nCustMenus[GetMenuItemIndex(ParentItemId)].nOrderMenuItemId[j];
    }

}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceStringIds
 * DESCRIPTION
 *  Function to get all the StringIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  StringIds           [?]         
 *  fills(?)            [OUT]       The input parameter. Memory is allocated by the caller.
 *  U16(?)              [IN]        MenuItemId i.e Parent & (U16 *) PoU16er containing the Array of StringIds.
 * RETURNS
 *  void
 *****************************************************************************/
void GetSequenceStringIds(U16 ParentItemId, U16 *StringIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ParentItemId >= MENU_ID_DEVAPP_START && ParentItemId <= MENU_ID_DEVAPP_END ) ||
        (ParentItemId >= DEVAPP_BASE && ParentItemId <= DEVAPP_BASE_MAX) ||
        (ParentItemId >= AVK_BASE && ParentItemId <= AVK_BASE_MAX))
    {
        DevAppGetSequenceStringIds(ParentItemId, StringIds);
        return;
    }
#endif

    for (j = 0; j < nCustMenus[GetMenuItemIndex(ParentItemId)].nNumofMenuItem; j++)
    {
        StringIds[j] = GetStringIdOfItem(nCustMenus[GetMenuItemIndex(ParentItemId)].nOrderMenuItemId[j]);
    }

}


/*****************************************************************************
 * FUNCTION
 *  GetIndexOfStringId
 * DESCRIPTION
 *  Function to get the index of StringIds in the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  StringId            [IN]        
 *  U16(?)              [IN]        MenuItemId i.e Parent & (U16 ) StringId
 * RETURNS
 *  U8
 *****************************************************************************/
U8 GetIndexOfStringId(U16 ParentItemId, U16 StringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ParentItemId >= MENU_ID_DEVAPP_START && ParentItemId <= MENU_ID_DEVAPP_END ) ||
        (ParentItemId >= DEVAPP_BASE && ParentItemId <= DEVAPP_BASE_MAX) ||
        (ParentItemId >= AVK_BASE && ParentItemId <= AVK_BASE_MAX))
    {
        return DevAppGetIndexOfStringId(ParentItemId, StringId);
    }
#endif

    for (j = 0; j < nCustMenus[GetMenuItemIndex(ParentItemId)].nNumofMenuItem; j++)
        if (StringId == nCustMenus[GetMenuItemIndex(ParentItemId)].nOrderMenuItemId[j])
        {
            return (U8) j;
        }
    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceImageIds
 * DESCRIPTION
 *  Function to get all the ImageIds in Sequence of the given MenuItemId i.e Parent.
 *  
 *  Need to check the hide attribute of the MenuItemId.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  ImageIds            [?]         
 *  fills(?)            [OUT]       The input parameter. Memory is allocated by the caller.
 *  U16(?)              [IN]        MenuItemId i.e Parent & (U16 *) PoU16er containing the Array of ImageIds.
 * RETURNS
 *  void
 *****************************************************************************/
void GetSequenceImageIds(U16 ParentItemId, U16 *ImageIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ParentItemId >= MENU_ID_DEVAPP_START && ParentItemId <= MENU_ID_DEVAPP_END ) ||
        (ParentItemId >= DEVAPP_BASE && ParentItemId <= DEVAPP_BASE_MAX) ||
        (ParentItemId >= AVK_BASE && ParentItemId <= AVK_BASE_MAX))
    {
        DevAppGetSequenceImageIds(ParentItemId, ImageIds);
        return;
    }
#endif
    for (j = 0; j < nCustMenus[GetMenuItemIndex(ParentItemId)].nNumofMenuItem; j++)
    {
        ImageIds[j] = GetImageIdOfItem(nCustMenus[GetMenuItemIndex(ParentItemId)].nOrderMenuItemId[j]);
    }

}

#ifndef __IOT__
/*****************************************************************************
 * FUNCTION
 *  GetLanguages
 * DESCRIPTION
 *  Get the language list.
 * PARAMETERS
 *  pppLanguages        [IN]        
 *  U16(?)              [OUT]       
 *  an(?)               [IN]        Array for getting the language list
 * RETURNS
 *  the number of languages deployed
 *****************************************************************************/
U16 GetLanguages(U8 ***pppLanguages)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nCount, lang_cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //Robin 1121, prevent memory leak
    //*pppLanguages = OslMalloc(gMaxDeployedLangs*sizeof(U8*));
    *pppLanguages = &gp_language_struct[0];

    for (nCount = 0; (nCount < gMaxDeployedLangs && nCount < MAX_LANGUAGE_NUM); ++nCount)
    {
        if(gLanguageMappingArray[nCount])
        {
            (*pppLanguages)[lang_cnt] = (U8*) gLanguageArray[nCount].aName;
            lang_cnt++;
        }
        /* ++nCount; */
    }

    //Robin 1121, prevent memory leak
    //return gMaxDeployedLangs;
    return lang_cnt;//nCount;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  GetLanguageIndex
 * DESCRIPTION
 *  Get the index of language specified by ssc_string.
 *  
 *  Return 0, if not found.
 * PARAMETERS
 *  ssc_str         [?]         
 *  index(?)        [OUT]       (1 based)
 *  U8(?)           [IN]        * ssc_string of lang
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetLanguageIndex(S8 *ssc_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ssc_str == NULL)
    {
        return 0xFFFF;
    }

    for (idx = 0; idx < gMaxDeployedLangs; idx++)
    {
        if (strcmp(ssc_str, (S8*) gLanguageArray[idx].aLangSSC) == 0 && gLanguageMappingArray[idx])
        {
            return idx;
        }
    }
    return 0xFFFF;
}


S32 mmi_res_get_cur_language(U8 *ssc_str)
{
    strcpy((S8*) ssc_str, (S8*) gLanguageArray[gCurrLangIndex].aLangSSC);
    return gCurrLangIndex;
}


/*****************************************************************************
 * FUNCTION
 *  GetLanguageIndexByLangCode
 * DESCRIPTION
 *  Get the index of language specified by language code.
 *  
 *  Return 0, if not found.
 * PARAMETERS
 *  lang_code         [?]         
 *  index(?)        [OUT]       (1 based)
 *  U8(?)           [IN]        * langauge code of lang
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetLanguageIndexByLangCode(S8 *lang_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx;
    U8 LangCode[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lang_code == NULL)
    {
        return 0xFFFF;
    }

    for (idx = 0; idx < gMaxDeployedLangs; idx++)
    {
        memcpy(LangCode, gLanguageArray[idx].aLangCountryCode, 2);
        LangCode[2] = '\0';

        if (strncmp(lang_code, (S8*)LangCode, 2) == 0 && gLanguageMappingArray[idx])
        {
            return idx;
        }
    }
    return 0xFFFF;
}


#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_if_enfb_str
 * DESCRIPTION
 *  test if data is an E-NFB string resource
 * PARAMETERS
 *  data    [IN]    data pointer
 * RETURNS
 *  MMI_BOOL    MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_frm_enfb_if_enfb_str(const U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (data[0] == STRING_TYPE_ENFB)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_str_offset
 * DESCRIPTION
 *  get E-NFB string offset
 * PARAMETERS
 *  data    [IN]    data pointer
 * RETURNS
 *  U32             data offset
 *****************************************************************************/
U32 mmi_frm_enfb_get_str_offset(const U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (U32)data[4] | (data[5] << 8) | (data[6] << 16) | (data[7] << 24);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_str_size
 * DESCRIPTION
 *  get E-NFB string size
 * PARAMETERS
 *  data    [IN]    data pointer
 * RETURNS
 *  U32             data size
 *****************************************************************************/
U32 mmi_frm_enfb_get_str_size(const U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (U32)data[8] | (data[9] << 8) | (data[10] << 16) | (data[11] << 24);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_enfb_get_max_string_size
 * DESCRIPTION
 *  get E-NFB maximum string size
 * PARAMETERS
 *  void
 * RETURNS
 *  U32             data size
 *****************************************************************************/
U32 mmi_frm_enfb_get_max_string_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_languages, i;
    U32 max_size = 0;
    CUSTOM_STRING *string_res;
    CUSTOM_STRING_MAP *string_map;
    CUSTOM_STRING_MAP_16 *string_map_16;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the number of deployed languages */
    max_languages = gMaxDeployedLangs;
    max_languages = (max_languages > MAX_LANGUAGE_NUM) ? (MAX_LANGUAGE_NUM) : (max_languages);

    /* get the maximum size */
    for(i = 0 ; i < max_languages ; i++)
    {
        U32 size = 0;

        /* get string information */
        string_res = gStringList[i].pStringRes;         /* string raw data */

        if (gStringList[i].is16bit)
        {
            string_map_16 = (CUSTOM_STRING_MAP_16 *)gStringList[i].pStringMap;
            /* get size */
            size += (((mmi_frm_enfb_get_str_size(string_res) + 3) >> 2) << 2);  /* data size */
            size += (((string_map_16[1] + 3) >> 2) << 2);                          /* map size */
        }
        else
        {
            string_map = (CUSTOM_STRING_MAP *)gStringList[i].pStringMap;         /* string map */
            /* get size */
            size += (((mmi_frm_enfb_get_str_size(string_res) + 3) >> 2) << 2);  /* data size */
            size += (((string_map[1] + 3) >> 2) << 2);                          /* map size */
        }

        max_size = (size > max_size) ? (size) : (max_size);
    }

    return max_size;
}
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  SetCurrentLanguage
 * DESCRIPTION
 *  Set the current language to the index.
 * PARAMETERS
 *  nIndex      [IN]        Of lang to set
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL gLanguageSettingOnBootUp = TRUE;
//extern void mmi_phb_callergroup_set_name_by_language(void);

#if defined(__MMI_AUDIO_EQUALIZER__) && defined(__PLUTO_MMI_PACKAGE__)
extern void mmi_settings_audio_eq_rename_by_language(void);
#endif

#if defined(__MMI_VRSI__)
extern void mmi_vrsi_init_central_change_language_reset(void);
#endif 

#ifdef __SMS_R8_NATION_LANGUAGE__
extern void mmi_msg_set_system_ems_lang_type(void);
#endif /* __SMS_R8_NATION_LANGUAGE__ */

#ifdef __MMI_MEDIA_PLAYER__	
extern void mmi_medply_encoding_type_change_callback(void);
#endif

extern void vm_app_name_change_string(void);

extern void vm_exit(void);

#define RESORCE_DECOMPRESS_WORKING_BUFFER_SIZE     (100 * 1024)



#ifdef __MMI_RESOURCE_STR_THIRD_ROM__
extern U16 gMaxDeployedLangs;
static MMI_BOOL mmi_res_str_first_load = MMI_TRUE;

void mmi_res_load_string_data(S8 lang_index){
   // load from third rom
   U32 res_offset = 0;
   U32 map_offset = 0;
   U32 res_length = 0;
   U32 map_length = 0;
   U8* res_dest = NULL;
   U8* map_dest = NULL;
   
   // Set dest
   res_dest = (U8*)gStringList[lang_index].pStringRes;
   map_dest = (U8*)gStringList[lang_index].pStringMap;
   
   //Set ThirdROM offset and len
   res_offset = MMIRESOUCE_3RD_ROM_String_BASE_ADDR + (U32)gStringList[lang_index].pStringResZip;
   res_length = (U32)gStringList[lang_index].nResSize;
   map_offset = MMIRESOUCE_3RD_ROM_String_BASE_ADDR + (U32)gStringList[lang_index].pStringMapZip;
   map_length = (U32)gStringList[lang_index].nMapSize;

   //Load Language data
   MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_IMAGERES, (void *)res_dest, res_offset, res_length);
   MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_IMAGERES, (void *)map_dest, map_offset, map_length);
   
   if(mmi_res_str_first_load == MMI_FALSE){
       return;
   }

   lang_index = gMaxDeployedLangs; /* decompress duplicate language */
   if ( ((U32)gStringList[lang_index].pStringResZip) != 0xFFFFFFFF)
   {
      // Set dest
      res_dest = (U8*)gStringList[lang_index].pStringRes;
      map_dest = (U8*)gStringList[lang_index].pStringMap;
   
      //Set ThirdROM offset and len
      res_offset = MMIRESOUCE_3RD_ROM_String_BASE_ADDR + (U32)gStringList[lang_index].pStringResZip;
      res_length = (U32)gStringList[lang_index].nResSize;
      map_offset = MMIRESOUCE_3RD_ROM_String_BASE_ADDR + (U32)gStringList[lang_index].pStringMapZip;
      map_length = (U32)gStringList[lang_index].nMapSize;

      //Load Language data
      MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_IMAGERES, (void *)res_dest, res_offset, res_length);
   }
   lang_index = gMaxDeployedLangs + 1;
   
   if( ((U32)gStringList[lang_index].pStringResZip) != 0xFFFFFFFF)
    {
      // Set dest
      res_dest = (U8*)gStringList[lang_index].pStringRes;
      map_dest = (U8*)gStringList[lang_index].pStringMap;
   
      //Set ThirdROM offset and len
      res_offset = MMIRESOUCE_3RD_ROM_String_BASE_ADDR + (U32)gStringList[lang_index].pStringResZip;
      res_length = (U32)gStringList[lang_index].nResSize;
      map_offset = MMIRESOUCE_3RD_ROM_String_BASE_ADDR + (U32)gStringList[lang_index].pStringMapZip;
      map_length = (U32)gStringList[lang_index].nMapSize;

      //Load Language data
      MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_IMAGERES, (void *)res_dest, res_offset, res_length);
      MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_IMAGERES, (void *)map_dest, map_offset, map_length);
     }
     mmi_res_str_first_load = MMI_FALSE;
      
}

#endif //__MMI_RESOURCE_STR_THIRD_ROM__

#ifdef __MMI_RESOURCE_STR_LZMA_COMPRESS__
extern U16 gMaxDeployedLangs;
static MMI_BOOL mmi_res_str_first_load = MMI_TRUE;
void mmi_res_load_string_data(S8 lang_index){
    S8 i = lang_index; /* decompress default language, 'gCurrLangIndex = 0;' */

#if !defined( __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)
    void *buff_pool = (void*)applib_asm_alloc_anonymous(RESORCE_LZMA_DECOMPRESS_WORKING_BUFFER_SIZE);
#endif // __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__

    if (gStringList[i].pStringResZip != NULL)
    {

#if !defined( __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)
        mmi_res_lzma_decompress((U8*)gStringList[i].pStringRes, gStringList[i].nResSize, (U8*)gStringList[i].pStringResZip, gStringList[i].nResZipSize, buff_pool);
        mmi_res_lzma_decompress((U8*)gStringList[i].pStringMap, gStringList[i].nMapSize, (U8*)gStringList[i].pStringMapZip, gStringList[i].nMapZipSize, buff_pool);
#else
        // Share the internal working buffer with image decmopression
        mmi_res_lzma_decompress_static_buffer((U8*)gStringList[i].pStringRes, gStringList[i].nResSize, (U8*)gStringList[i].pStringResZip, gStringList[i].nResZipSize);
        mmi_res_lzma_decompress_static_buffer((U8*)gStringList[i].pStringMap, gStringList[i].nMapSize, (U8*)gStringList[i].pStringMapZip, gStringList[i].nMapZipSize);

#endif // __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
    }
    if(mmi_res_str_first_load == MMI_FALSE){
#if !defined( __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)
       applib_asm_free_anonymous(buff_pool);
#endif //    __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
       return;
    }
    
    i = gMaxDeployedLangs; /* decompress duplicate language */
    if (gStringList[i].pStringResZip != NULL)
    {
#if !defined( __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)   
        mmi_res_lzma_decompress((U8*)gStringList[i].pStringRes, gStringList[i].nResSize, (U8*)gStringList[i].pStringResZip, gStringList[i].nResZipSize, buff_pool);
#else
        mmi_res_lzma_decompress_static_buffer((U8*)gStringList[i].pStringRes, gStringList[i].nResSize, (U8*)gStringList[i].pStringResZip, gStringList[i].nResZipSize);
#endif //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
    }
    if(gStringList[i + 1].pStringResZip != NULL)
    {
#if !defined( __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)
        mmi_res_lzma_decompress((U8*)gStringList[i + 1].pStringRes, gStringList[i + 1].nResSize, (U8*)gStringList[i + 1].pStringResZip, gStringList[i + 1].nResZipSize, buff_pool);
        mmi_res_lzma_decompress((U8*)gStringList[i + 1].pStringMap, gStringList[i + 1].nMapSize, (U8*)gStringList[i + 1].pStringMapZip, gStringList[i + 1].nMapZipSize, buff_pool);	
#else
        mmi_res_lzma_decompress_static_buffer((U8*)gStringList[i + 1].pStringRes, gStringList[i + 1].nResSize, (U8*)gStringList[i + 1].pStringResZip, gStringList[i + 1].nResZipSize);
        mmi_res_lzma_decompress_static_buffer((U8*)gStringList[i + 1].pStringMap, gStringList[i + 1].nMapSize, (U8*)gStringList[i + 1].pStringMapZip, gStringList[i + 1].nMapZipSize);	
#endif //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
    }
    
#if !defined( __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)
    applib_asm_free_anonymous(buff_pool);
#endif //    __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__

    mmi_res_str_first_load = MMI_FALSE;

}
#endif //__MMI_RESOURCE_STR_LZMA_COMPRESS__

void mmi_res_set_language(S8 nIndex)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SAT__
#ifndef __SAT_LOWCOST_UI_DISABLE__
    U8 LangCode[6];
#endif
#endif

#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
    void *buff_pool = (void*)applib_asm_alloc_anonymous(RESORCE_DECOMPRESS_WORKING_BUFFER_SIZE);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_switch_language = MMI_TRUE;

    if (nIndex >= gMaxDeployedLangs)
    {
        nIndex = 0;
    }
    gCurrLangIndex = nIndex;

#ifndef __POPULATE_NO_STRING_DATA__
#if defined(__MMI_RESOURCE_STR_THIRD_ROM__) || defined (__MMI_RESOURCE_STR_LZMA_COMPRESS__)
    mmi_res_load_string_data(gCurrLangIndex);
#endif //__MMI_RESOURCE_STR_THIRD_ROM__

#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__)
    /* uncompress */
    if (gStringList[gCurrLangIndex].pStringResZip != NULL)
    {
        mmi_res_decompress((U8*)gStringList[gCurrLangIndex].pStringRes, gStringList[gCurrLangIndex].nResSize, (U8*)gStringList[gCurrLangIndex].pStringResZip, gStringList[gCurrLangIndex].nResZipSize, buff_pool);
        mmi_res_decompress((U8*)gStringList[gCurrLangIndex].pStringMap, gStringList[gCurrLangIndex].nMapSize, (U8*)gStringList[gCurrLangIndex].pStringMapZip, gStringList[gCurrLangIndex].nMapZipSize, buff_pool);
    }
    /* uncompress */
    applib_asm_free_anonymous(buff_pool);
#endif /* __MMI_RESOURCE_STR_LZMA_COMPRESS__ */
#endif //__POPULATE_NO_STRING_DATA__

#if !defined(__IOT__)
    r2lMMIFlag = IsL2RMMIStyle();
#endif
    
#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
    set_current_language_for_hindi_rules();
#endif 
    
#ifndef __POPULATE_NO_STRING_DATA__
    gpStringRes = gStringList[gCurrLangIndex].pStringRes;
    g_is16bit = gStringList[gCurrLangIndex].is16bit;
    if (g_is16bit)
        gpStringMapRes16 = (CUSTOM_STRING_MAP_16 *)gStringList[gCurrLangIndex].pStringMap;
    else
        gpStringMapRes = (CUSTOM_STRING_MAP *)gStringList[gCurrLangIndex].pStringMap;    

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    if(mmi_frm_enfb_if_enfb(gpStringRes) == MMI_TRUE)
    {
        U32 offset[2], size[2];
        U8 *ptr[2] = {0};
        
        /* read ENFB string resource information */
        offset[0] = mmi_frm_enfb_get_str_offset(gpStringRes);
        size[0] = mmi_frm_enfb_get_str_size(gpStringRes);
        offset[1] = (U32)gpStringMapRes[0];
        size[1] = (U32)gpStringMapRes[1];

        /* load string data */
		mmi_frm_resmem_load_str_suite(ptr, offset, size, 2);
        
        /* re-assign pointer */
        gpStringRes = (CUSTOM_STRING *)ptr[0];
        gpStringMapRes = (CUSTOM_STRING_MAP *)ptr[1];
    }
    else
    {
        /* ENFB is enabled,
         * but the string resource is not a valid one */
        MMI_ASSERT(0);
    }
#endif

    gpStrMapSearch = gStringList[gCurrLangIndex].pStrMapSearch;
    CurrMaxStringNum = gStringList[gCurrLangIndex].nTotalStrRes;
    CurrMaxStringId = gStringList[gCurrLangIndex].nTotalStrMap;
    CurrMaxStringIdSearch = gStringList[gCurrLangIndex].nTotalStrMapSearch;
#endif //__POPULATE_NO_STRING_DATA__

    g_is_switch_language = MMI_FALSE;

    if (gLanguageSettingOnBootUp == FALSE)
    {
    #if !defined(__IOT__)
        PhnsetReinitHomeCityIdx();
    #endif
    }
    else
    {
        gLanguageSettingOnBootUp = FALSE;
    }

    /* Change caller group name default vaule when change lanaguage */
    //mmi_phb_callergroup_set_name_by_language();

#if defined(__MMI_AUDIO_EQUALIZER__) && defined(__PLUTO_MMI_PACKAGE__)
    mmi_settings_audio_eq_rename_by_language();
#endif

#if defined(__MMI_VRSI__)
    /* Reset voice command central command according to the language. */
    mmi_vrsi_init_central_change_language_reset();
#endif /* defined(__MMI_VRSI__) */ 

#ifdef __SMS_R8_NATION_LANGUAGE__
    mmi_msg_set_system_ems_lang_type();
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    /* send langauge code, the first two character is langauge code */
#if defined(__SAT__) && defined(__MMI_TELEPHONY_SUPPORT__)
#ifndef __SAT_LOWCOST_UI_DISABLE__
    memcpy(LangCode, gLanguageArray[gCurrLangIndex].aLangCountryCode, 2);
    LangCode[2] = '\0';
    srv_sat_envelope_language_selection((PU8) LangCode);
#endif /* __SAT_LOWCOST_UI_DISABLE__ */
#endif /* __SAT__ */

    /* reset meta string display on idle screen if background play is actived */
#ifdef __MMI_MEDIA_PLAYER__	
    mmi_medply_encoding_type_change_callback();
#endif

    /* change MRE App name string display in ASM Insufficient Memory screen.  */
   vm_app_name_change_string();

#if !defined(__IOT__)
   mmi_imm_phone_language_change_handler();
#endif

   vm_exit();
#endif//   
}


/*****************************************************************************
 * FUNCTION
 *  InitStringLanguage
 * DESCRIPTION
 *  This function is to init string by language
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
void InitStringLanguage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is_switch_language = MMI_TRUE;

#if defined(__IOT__)
    nIndex = 0;
#else
    nIndex = mmi_phnset_get_language_idx();
#endif
		
    if (nIndex >= gMaxDeployedLangs)
    {
        nIndex = 0;
    }
    gCurrLangIndex = nIndex;
#ifndef __POPULATE_NO_STRING_DATA__
    gpStringRes = gStringList[gCurrLangIndex].pStringRes;
    g_is16bit = gStringList[gCurrLangIndex].is16bit;
    if (g_is16bit)
        gpStringMapRes16 = (CUSTOM_STRING_MAP_16 *)gStringList[gCurrLangIndex].pStringMap;
    else
        gpStringMapRes = (CUSTOM_STRING_MAP *)gStringList[gCurrLangIndex].pStringMap;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    if(mmi_frm_enfb_if_enfb(gpStringRes) == MMI_TRUE)
    {
        U32 offset[2], size[2];
        U8 *ptr[2] = {0};
        
        /* read ENFB string resource information */
        offset[0] = mmi_frm_enfb_get_str_offset(gpStringRes);
        size[0] = mmi_frm_enfb_get_str_size(gpStringRes);
        offset[1] = (U32)gpStringMapRes[0];
        size[1] = (U32)gpStringMapRes[1];

        /* load string data */
		mmi_frm_resmem_load_str_suite(ptr, offset, size, 2);
        
        /* re-assign pointer */
        gpStringRes = (CUSTOM_STRING *)ptr[0];
        gpStringMapRes = (CUSTOM_STRING_MAP *)ptr[1];
    }
    else
    {
        /* ENFB is enabled,
         * but the string resource is not a valid one */
        MMI_ASSERT(0);
    }
#endif

    gpStrMapSearch = gStringList[gCurrLangIndex].pStrMapSearch;
    CurrMaxStringNum = gStringList[gCurrLangIndex].nTotalStrRes;
    CurrMaxStringId = gStringList[gCurrLangIndex].nTotalStrMap;
    CurrMaxStringIdSearch = gStringList[gCurrLangIndex].nTotalStrMapSearch;
#endif //__POPULATE_NO_STRING_DATA__
    g_is_switch_language = MMI_FALSE;

    if (gLanguageSettingOnBootUp == FALSE)
    {
        //PhnsetReinitHomeCityIdx();
    }
    else
    {
        gLanguageSettingOnBootUp = FALSE;
    }
}

/* MTK added, Max: to solve schedule power on/off change home city issue 1202 */


/*****************************************************************************
 * FUNCTION
 *  ResetLanguageSettingFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResetLanguageSettingFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gLanguageSettingOnBootUp = TRUE;
}

/* MTK end */

/* MTK Leo add, for mini_tab_bar */


/*****************************************************************************
 * FUNCTION
 *  GetSeqItems
 * DESCRIPTION
 *  Get child menuitems.
 * PARAMETERS
 *  ParentItemId        [IN]        
 *  id(?)               [IN]        Of parent
 * RETURNS
 *  void
 *****************************************************************************/
U16 *GetSeqItems(U16 ParentItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nCustMenus[GetMenuItemIndex(ParentItemId)].nOrderMenuItemId;
}

/* MTK Leo end */

/* APIs for hide some menuitems at run time */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_hide_menu_item
 * DESCRIPTION
 *  Set the bit represented the menuitem on to hide it
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_hide_menu_item(U16 menu_item_id)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((menu_item_id >= MENU_ID_DEVAPP_START && menu_item_id <= MENU_ID_DEVAPP_END ) ||
        (menu_item_id >= DEVAPP_BASE && menu_item_id <= DEVAPP_BASE_MAX) ||
        (menu_item_id >= AVK_BASE && menu_item_id <= AVK_BASE_MAX))
    {
        devapp_hide_menu_item(menu_item_id);
		return;
    }
#endif
    item_id = GetMenuItemIndex(menu_item_id);
    ASSERT(item_id < av_total_menuitem);
    
    if (item_id < av_total_menuitem)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        MenuItemMask[idx] |= (1 << (7 - reminding));
    }
#endif//	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_unhide_menu_item
 * DESCRIPTION
 *  Reset the bit represented the menuitem on to unhide it
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_unhide_menu_item(U16 menu_item_id)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((menu_item_id >= MENU_ID_DEVAPP_START && menu_item_id <= MENU_ID_DEVAPP_END ) ||
        (menu_item_id >= DEVAPP_BASE && menu_item_id <= DEVAPP_BASE_MAX) ||
        (menu_item_id >= AVK_BASE && menu_item_id <= AVK_BASE_MAX))
    {
        devapp_unhide_menu_item(menu_item_id);
		return;
    }
#endif

    item_id = GetMenuItemIndex(menu_item_id);
    ASSERT(item_id < av_total_menuitem);
    
    if (item_id < av_total_menuitem)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        MenuItemMask[idx] &= ~(1 << (7 - reminding));
    }
#endif//	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_unhide_child_menu_items
 * DESCRIPTION
 *  unhide all child menu items of a given parent menu item
 * PARAMETERS
 *  parent_menu_item_id [IN]        Id of the parent menuitem
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_unhide_child_menu_items(U16 parent_menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_child;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* unhide all menu under the parent */
    num_of_child = GetNumOfChild(parent_menu_item_id);
    if(!num_of_child)
        return;

    while(num_of_child)
    {
        mmi_frm_unhide_menu_item(GetSeqItemId(parent_menu_item_id, (U16)(num_of_child-1)));
        num_of_child--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_test_menu_item_hide
 * DESCRIPTION
 *  test if the menuitem is hidden or not
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  MMI_BOOL MMI_TRUE if the menuitem is hidden
 *****************************************************************************/
MMI_BOOL mmi_frm_test_menu_item_hide(U16 menu_item_id)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = 0, reminding = 0;
    U16 item_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((menu_item_id >= MENU_ID_DEVAPP_START && menu_item_id <= MENU_ID_DEVAPP_END ) ||
        (menu_item_id >= DEVAPP_BASE && menu_item_id <= DEVAPP_BASE_MAX) ||
        (menu_item_id >= AVK_BASE && menu_item_id <= AVK_BASE_MAX))
    {
        return devapp_test_menu_item_hide(menu_item_id);
    }
#endif

    item_id = GetMenuItemIndex(menu_item_id);
    ASSERT(item_id < av_total_menuitem);

    if (item_id < av_total_menuitem)
    {
        idx = item_id / 8;
        reminding = item_id - (idx * 8);
        if ((MenuItemMask[idx] >> (7 - reminding)) & 1)
        {
            return MMI_TRUE;
        }
    }
#endif//	
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  GetNumOfChild_Ext
 * DESCRIPTION
 *  Function to get Number of Childrens of the Given MenuItemId considering MenuItemMask.
 * PARAMETERS
 *  menu_item_id        [IN]        Id of the menuitem
 * RETURNS
 *  U16   Number of Childrens.
 *****************************************************************************/
U16 GetNumOfChild_Ext(U16 menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0, num_child = nCustMenus[GetMenuItemIndex(menu_item_id)].nNumofMenuItem;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((menu_item_id >= MENU_ID_DEVAPP_START && menu_item_id <= MENU_ID_DEVAPP_END ) ||
        (menu_item_id >= DEVAPP_BASE && menu_item_id <= DEVAPP_BASE_MAX) ||
        (menu_item_id >= AVK_BASE && menu_item_id <= AVK_BASE_MAX))
    {
        return DevAppGetNumOfChild_Ext(menu_item_id);
    }
#endif

    for (i = 0; i < num_child; i++)
    {
        if (!mmi_frm_test_menu_item_hide(nCustMenus[GetMenuItemIndex(menu_item_id)].nOrderMenuItemId[i]))
        {
            count++;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemId_Ext
 * DESCRIPTION
 *  Function to get MenuItemId of the given parent_item_id & index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  index               [IN]        Index of the child menuitem
 * RETURNS
 *  U16   item id
 *****************************************************************************/
U16 GetSeqItemId_Ext(U16 parent_item_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, idx = 0;
    U16 item_id = 0;
    U8 child_count = (U8) nCustMenus[GetMenuItemIndex(parent_item_id)].nNumofMenuItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((parent_item_id >= MENU_ID_DEVAPP_START && parent_item_id <= MENU_ID_DEVAPP_END ) ||
        (parent_item_id >= DEVAPP_BASE && parent_item_id <= DEVAPP_BASE_MAX) ||
        (parent_item_id >= AVK_BASE && parent_item_id <= AVK_BASE_MAX))
    {
        return DevAppGetSeqItemId_Ext(parent_item_id, index);
    }
#endif

    for (i = 0; i < child_count; i++)
    {
        item_id = nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[i];
        if (!mmi_frm_test_menu_item_hide(item_id))  /* the item is not hidden */
        {
            if (idx == index)
            {
                break;
            }
            else
            {
                idx++;
            }
        }
    }
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_RESGEN_ALL_MENU_HIDE, parent_item_id);
    return item_id;
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemStringId_Ext
 * DESCRIPTION
 *  Function to get StringId of the given parent_item_id and index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  index               [IN]        Index of the child menuitem
 * RETURNS
 *  U16   string id
 *****************************************************************************/
U16 GetSeqItemStringId_Ext(U16 parent_item_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = (U16) GetSeqItemId_Ext(parent_item_id, index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetStringIdOfItem(idx);
}


/*****************************************************************************
 * FUNCTION
 *  GetSeqItemImageId_Ext
 * DESCRIPTION
 *  Function to get Image Id of the given parent_item_id and index considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  index               [IN]        Index of the child menuitem
 * RETURNS
 *  U16   image id
 *****************************************************************************/
U16 GetSeqItemImageId_Ext(U16 parent_item_id, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 idx = (U16) GetSeqItemId_Ext(parent_item_id, index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetImageIdOfItem(idx);
}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceItemIds_Ext
 * DESCRIPTION
 *  Function to get MenuItemId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  ItemIds             [IN/OUT]        Array of the child menuitem id
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 GetSequenceItemIds_Ext(U16 parent_item_id, U16 *ItemIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((parent_item_id >= MENU_ID_DEVAPP_START && parent_item_id <= MENU_ID_DEVAPP_END ) ||
        (parent_item_id >= DEVAPP_BASE && parent_item_id <= DEVAPP_BASE_MAX) ||
        (parent_item_id >= AVK_BASE && parent_item_id <= AVK_BASE_MAX))
    {
        return DevAppGetSequenceItemIds_Ext(parent_item_id, ItemIds);
    }
#endif    
    for (j = 0; j < nCustMenus[GetMenuItemIndex(parent_item_id)].nNumofMenuItem; j++)
    {
        U16 item_id = nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            ItemIds[ret_idx++] = nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[j];
        }
    }
    return ret_idx;
}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceStringIds_Ext
 * DESCRIPTION
 *  Function to get StringId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  StringIds           [IN/OUT]        Array of string ids of the child menuitem
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 GetSequenceStringIds_Ext(U16 parent_item_id, U16 *StringIds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((parent_item_id >= MENU_ID_DEVAPP_START && parent_item_id <= MENU_ID_DEVAPP_END ) ||
        (parent_item_id >= DEVAPP_BASE && parent_item_id <= DEVAPP_BASE_MAX) ||
        (parent_item_id >= AVK_BASE && parent_item_id <= AVK_BASE_MAX))
    {
        return DevAppGetSequenceStringIds_Ext(parent_item_id, StringIds);
    }
#endif       
    for (j = 0; j < nCustMenus[GetMenuItemIndex(parent_item_id)].nNumofMenuItem; j++)
    {
        U16 item_id = nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            StringIds[ret_idx++] = GetStringIdOfItem(nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[j]);
        }
    }
    return ret_idx;
}


/*****************************************************************************
 * FUNCTION
 *  GetSequenceImageIds_Ext
 * DESCRIPTION
 *  Function to get ImageId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]            Id of the parent menuitem
 *  ImageIds            [IN/OUT]        Array of image ids of the child menuitem
 * RETURNS
 *  U16 number of child menuitem
 *****************************************************************************/
U16 GetSequenceImageIds_Ext(U16 parent_item_id, U16 *ImageIds)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((parent_item_id >= MENU_ID_DEVAPP_START && parent_item_id <= MENU_ID_DEVAPP_END ) ||
        (parent_item_id >= DEVAPP_BASE && parent_item_id <= DEVAPP_BASE_MAX) ||
        (parent_item_id >= AVK_BASE && parent_item_id <= AVK_BASE_MAX))
    {
        return DevAppGetSequenceImageIds_Ext(parent_item_id, ImageIds);
    }
#endif      
    for (j = 0; j < nCustMenus[GetMenuItemIndex(parent_item_id)].nNumofMenuItem; j++)
    {
        U16 item_id = nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            ImageIds[ret_idx++] = GetImageIdOfItem(nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[j]);
        }
    }
    return ret_idx;
#else
	return 0;
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) */
}


/*****************************************************************************
 * FUNCTION
 *  GetIndexOfStringId_Ext
 * DESCRIPTION
 *  Function to get ImageId of the given parent_item_id considering MenuItemMask.
 * PARAMETERS
 *  parent_item_id      [IN]        Id of the parent menuitem
 *  StringId            [IN]        Id of the string
 * RETURNS
 *  U8 index
 *****************************************************************************/
U8 GetIndexOfStringId_Ext(U16 parent_item_id, U16 StringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 j, ret_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((parent_item_id >= MENU_ID_DEVAPP_START && parent_item_id <= MENU_ID_DEVAPP_END ) ||
        (parent_item_id >= DEVAPP_BASE && parent_item_id <= DEVAPP_BASE_MAX) ||
        (parent_item_id >= AVK_BASE && parent_item_id <= AVK_BASE_MAX))
    {
        return DevAppGetIndexOfStringId_Ext(parent_item_id, StringId);
    }
#endif     
    for (j = 0; j < nCustMenus[GetMenuItemIndex(parent_item_id)].nNumofMenuItem; j++)
    {
        U16 item_id = nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[j];

        if (!mmi_frm_test_menu_item_hide(item_id))  /* menuitem id hidden */
        {
            if (StringId == nCustMenus[GetMenuItemIndex(parent_item_id)].nOrderMenuItemId[j])
            {
                return (U8) ret_idx;
            }
            ret_idx++;
        }
    }

    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetChildMenuIDIndexByParentMenuID_Ext
 * DESCRIPTION
 *  Function to get the index of the given MenuItemId in the child sequence of the parent MenuItem, considering MenuItemMask.
 * PARAMETERS
 *  parentMenuId        [IN]    parent menu ID
 *  childMenuId         [IN]    child menu ID
 * RETURNS
 *  index >= 0: child manu id is a child of parent menu id, -1: if not
 *****************************************************************************/
S32 GetChildMenuIDIndexByParentMenuID_Ext(U16 parentMenuId, U16 childMenuId)
{
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    U16 nMenuItemList[MAX_SUB_MENUS];
    U16 numItems = GetNumOfChild_Ext(parentMenuId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceItemIds_Ext(parentMenuId, nMenuItemList);

    ASSERT(numItems <= MAX_SUB_MENUS);

    for (index = 0; index < numItems; index++)
    {
        if (nMenuItemList[index] == childMenuId)
        {
            return index;
        }
    }
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) */	
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  SetMenuItemDimmed
 * DESCRIPTION
 *  Dims an menu item.
 * PARAMETERS
 *  menu_id       [IN]  menu id
 *  is_dimmed     [IN]  dimmed flag
 * RETURNS
 *  void
 *****************************************************************************/
void SetMenuItemDimmed(U16 menu_id, MMI_BOOL is_dimmed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  mask;
    U16 item_id;
    S32 bit_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_id = GetMenuItemIndex(menu_id);
    ASSERT(item_id < av_total_menuitem);
       
    is_dimmed &= 0x1;    
    bit_offset = item_id & 0x7;    
    mask = g_menuitem_disable_mask[item_id / 8];
    mask &= ~(1 << bit_offset);
    mask |= (is_dimmed << bit_offset);    
    g_menuitem_disable_mask[item_id / 8] = mask;
}


/*****************************************************************************
 * FUNCTION
 *  IsMenuItemDimmed
 * DESCRIPTION
 *  Checks if the menu item is dimmed.
 * PARAMETERS
 *  menu_id       [IN]  menu id
 * RETURNS
 *  MMI_TRUE if dimmed; otherwise, MMI_FALSE.
 *****************************************************************************/
MMI_BOOL IsMenuItemDimmed(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_id = GetMenuItemIndex(menu_id);
    ASSERT(item_id < av_total_menuitem);
    
    return (MMI_BOOL)((g_menuitem_disable_mask[item_id / 8] >> (item_id & 0x7)) & 0x1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_menu_group_set_disable
 * DESCRIPTION
 *  Disable/Enalbe a group of menu items.
 * PARAMETERS
 *  group_id      [IN]  group id
 *  is_disable    [IN]  Disable flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_res_menu_group_set_disable(U16 group_id, MMI_BOOL is_disable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* group_item = (U16*)mmi_rg_menu_group[group_id];
    U16 i=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while(group_item[i] != 0xFFFF)  /* 0xFFFF is the mark of array end */
    {
        SetMenuItemDimmed(group_item[i], is_disable);
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_menu_group_set_hide
 * DESCRIPTION
 *  Hide/Unhide a group of menu items
 * PARAMETERS
 *  group_id     [IN]  group id
 *  is_hide      [IN]  hide flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_res_menu_group_set_hide(U16 group_id, MMI_BOOL is_hide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* group_item = (U16*)mmi_rg_menu_group[group_id];
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    while(group_item[i] != 0xFFFF)
    {
        if (is_hide)
        {
            mmi_frm_hide_menu_item(group_item[i]);
        }
        else
        {
            mmi_frm_unhide_menu_item(group_item[i]);
        }
        i++;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_menu_group_get_menuitems
 * DESCRIPTION
 *  Get menuitems of the group
 * PARAMETERS
 *  group_id     [IN]  group id
 *  items        [OUT] Array of menuitems, end with a 0xFFFF
 * RETURNS
 *  S16          count of menuitems in the group.
 *****************************************************************************/
U16 mmi_res_menu_group_get_menuitems(U16 group_id, U16 **items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* group_item = (U16*)mmi_rg_menu_group[group_id];
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *items = group_item;
    while(group_item[i] != 0xFFFF)
    {
        i++;
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_menu_get_type
 * DESCRIPTION
 *  Function to get DispAttributes of the given MenuItemId.
 *  
 *  DispAttribute are like Matrix,List,Circular,Tab..etc.
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [OUT]       DispAttribute.
 * RETURNS
 *  DispAttribute which is passed to the UI Element.
 *****************************************************************************/
U16 mmi_res_menu_get_type(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetDispAttributeOfItem(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_menu_get_flag
 * DESCRIPTION
 *  Function to get nFlags of the given MenuItemId.
 *  
 *  nFlags are like MMI_RG_MENU_FLAG_RADIO, MMI_RG_MENU_FLAG_CHECKBOX or MMI_RG_MENU_FLAG_NONE
 * PARAMETERS
 *  ItemId      [IN]        
 * RETURNS
 *  DispAttribute which is passed to the UI Element.
 *****************************************************************************/
U16 mmi_res_menu_get_flag(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = nCustMenus[GetMenuItemIndex(menu_id)].nFlags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((flag & MMI_RG_MENU_FLAG_RADIO) == MMI_RG_MENU_FLAG_RADIO)
    {
        return (U16)MMI_RG_MENU_FLAG_RADIO;
    }
    else if ((flag & MMI_RG_MENU_FLAG_CHECKBOX) == MMI_RG_MENU_FLAG_CHECKBOX)
    {
        return (U16)MMI_RG_MENU_FLAG_CHECKBOX;
    }
    else 
    {
        return (U16)MMI_RG_MENU_FLAG_NONE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_res_menu_get_default_item
 * DESCRIPTION
 *  Function to get default menu ID of a menu tree
 * PARAMETERS
 *  parent_id      [IN]     parent ID of menu tree   
 * RETURNS
 *  Default menuID, if set return set value, if not set, return first menuID, considering Hide/Unhide.
 *****************************************************************************/
U16 mmi_res_menu_get_default_item(U16 parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (mmi_rg_menu_default_menu_array[i].parent_id != 0xFFFF)
    {
        if (mmi_rg_menu_default_menu_array[i].parent_id == parent_id)
        {
            /* If found, then return the value. */
            return mmi_rg_menu_default_menu_array[i].def_menu_id;
        }
        i++;
    }

    /* if not found, then use the first item of this parent ID */
    return GetSeqItemId_Ext(parent_id, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_idx
 * DESCRIPTION
 *  Function to get index of an app
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0xFFFF if not found.
 *****************************************************************************/
U16 mmi_res_get_app_idx(U16 app_res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, i_max = mmi_app_info_array_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<i_max; i++)
    {
        if ((app_res_id >= mmi_app_info[i].baseId) && (app_res_id <= mmi_app_info[i].baseIdMax))
            return i;
    }
    return 0xFFFF;  /* app name is not declared */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_base_mem_size
 * DESCRIPTION
 *  Function to get base mem. size of an app
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U32 mmi_res_get_app_base_mem_size(U16 app_res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, i_max = mmi_app_info_array_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i = mmi_res_get_app_idx(app_res_id)) < i_max)
        return mmi_app_info[i].base_size;
    else
        return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_fg_mem_size
 * DESCRIPTION
 *  Function to get foreground mem. size of an app
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U32 mmi_res_get_app_fg_mem_size(U16 app_res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, i_max = mmi_app_info_array_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i = mmi_res_get_app_idx(app_res_id)) < i_max)
        return mmi_app_info[i].fg_size;
    else
        return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_heap_size
 * DESCRIPTION
 *  Function to get heap size of an app
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U32 mmi_res_get_app_heap_size(U16 app_res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, i_max = mmi_app_info_array_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i = mmi_res_get_app_idx(app_res_id)) < i_max)
        return mmi_app_info[i].heap_size;
    else
        return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_heap_shrink_size
 * DESCRIPTION
 *  Function to get heap_shrink size of an app
 * PARAMETERS
 *  app_res_id      [IN]     App resource ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U32 mmi_res_get_app_heap_shrink_size(U16 app_res_id)
{
#if defined __MMI_USE_MMV2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, i_max = mmi_app_info_array_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i = mmi_res_get_app_idx(app_res_id)) < i_max)
        return mmi_app_info[i].heap_shrink_size;
    else
        return 0;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_heap_global_size
 * DESCRIPTION
 *  Function to get global size of an app
 * PARAMETERS
 *  app_res_id      [IN]     App resource ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U32 mmi_res_get_app_global_size(U16 app_res_id)
{
    return mmi_res_get_app_heap_shrink_size(app_res_id);
}


/*****************************************************************************
 * <GROUP APP>
 * FUNCTION
 *  mmi_res_get_app_mem_info
 * DESCRIPTION
 *  Function to get mem info of app at once
 * PARAMETERS
 *  app_res_id  : [IN]     app resource id
 *  info        : [OUT]    returned info
 * RETURNS
 *  Return MMI_FALSE if not found.
 *****************************************************************************/
MMI_BOOL mmi_res_get_app_mem_info(U16 app_res_id, mmi_app_mem_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, i_max = mmi_app_info_array_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i = mmi_res_get_app_idx(app_res_id)) < i_max)
    {
        info->base_size = mmi_app_info[i].base_size;
        info->fg_size = mmi_app_info[i].fg_size;
        info->heap_size = mmi_app_info[i].heap_size;
        info->heap_shrink_size = mmi_app_info[i].heap_shrink_size;
        info->heap_global_size = mmi_app_info[i].heap_shrink_size;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * <GROUP APP>
 * FUNCTION
 *  mmi_res_get_asm_common_pool_size
 * DESCRIPTION
 *  Function to get size of "common" region in ASM pool
 * PARAMETERS
 * RETURNS
 *  Size of common region
 *****************************************************************************/
U32 mmi_res_get_asm_common_pool_size()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(app_asm_pool_sub_union);
}


/*****************************************************************************
 * <GROUP APP>
 * FUNCTION
 *  mmi_res_get_asm_global_pool_size
 * DESCRIPTION
 *  Function to get size of "global" region in ASM pool
 * PARAMETERS
 * RETURNS
 *  Size of global region
 *****************************************************************************/
U32 mmi_res_get_asm_global_pool_size()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(app_asm_pool_global_union);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_vrt_mem_factor
 * DESCRIPTION
 *  Function to get vrt mem. factor of an app
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
FLOAT mmi_res_get_app_vrt_mem_factor(U16 app_res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, i_max = mmi_app_info_array_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((i = mmi_res_get_app_idx(app_res_id)) < i_max)
        return (FLOAT)mmi_app_info[i].vrt_mem_factor;
    else
        return (FLOAT)0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_asm_pool_size
 * DESCRIPTION
 *  Function to get asm pool size of an app
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U32 mmi_res_get_app_asm_pool_size(U16 app_res_id)
{
#ifdef OLD_VENUS_RES
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < mmi_app_info_array_size(); i++)
    {
        if((app_res_id >= mmi_app_info[i].baseId) && (app_res_id <= mmi_app_info[i].baseIdMax))
        {
            return mmi_app_info[i].asm_pool_size;
        }
    }
#endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_max
 * DESCRIPTION
 *  Function to get max value of app's ID range
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U16 mmi_res_get_app_max(U16 app_res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < mmi_app_info_array_size(); i++)
    {
        if((app_res_id >= mmi_app_info[i].baseId) && (app_res_id <= mmi_app_info[i].baseIdMax))
        {
            return mmi_app_info[i].baseIdMax;
        }
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_baseID
 * DESCRIPTION
 *  Function to get baseID value from app's ID range
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U16 mmi_res_get_app_baseID(U16 app_res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    static U32 pre_i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((app_res_id >= mmi_app_info[pre_i].baseId) && (app_res_id <= mmi_app_info[pre_i].baseIdMax))
    {
        return mmi_app_info[pre_i].baseId;
    }

    for(i = 0; i < mmi_app_info_array_size(); i++)
    {
        if((app_res_id >= mmi_app_info[i].baseId) && (app_res_id <= mmi_app_info[i].baseIdMax))
        {
            pre_i = i;
            return mmi_app_info[i].baseId;
        }
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_app_name_str_id
 * DESCRIPTION
 *  Function to get string ID of app name
 * PARAMETERS
 *  app_res_id      [IN]     App resource range ID  
 * RETURNS
 *  Return 0 if not found.
 *****************************************************************************/
U16 mmi_res_get_app_name_str_id(U16 app_res_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < mmi_app_info_array_size(); i++)
    {
        if((app_res_id >= mmi_app_info[i].baseId) && (app_res_id <= mmi_app_info[i].baseIdMax))
        {
            return mmi_app_info[i].name;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_mainmenu_img
 * DESCRIPTION
 *  Function to get mainmenu's image for mainmenu items.
 * PARAMETERS
 *  menu_id      [IN]     ID of menu item
 *  img_type     [IN]     Type of image to get.
 * RETURNS
 *  image ID
 *****************************************************************************/
MMI_IMG_ID mmi_res_get_mainmenu_img(MMI_MENU_ID menu_id, mmi_rg_menu_mainmenu_img_type img_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<mmi_rg_menu_mainmenuid_total; i++)
    {
        if (menu_id == mmi_rg_menu_mainmenu_img_id_array[i].id)
        {
            switch(img_type)
            {
            case MMI_RG_MM_IMG_LIST:
                return mmi_rg_menu_mainmenu_img_id_array[i].list_img;

            case MMI_RG_MM_IMG_MATRIX:
                return mmi_rg_menu_mainmenu_img_id_array[i].matrix_img;

            case MMI_RG_MM_IMG_PAGE:
                return mmi_rg_menu_mainmenu_img_id_array[i].page_img;

            case MMI_RG_MM_IMG_VENUS1:
                return mmi_rg_menu_mainmenu_img_id_array[i].venus_img_1;

            case MMI_RG_MM_IMG_VENUS2:
                return mmi_rg_menu_mainmenu_img_id_array[i].venus_img_2;

            case MMI_RG_MM_IMG_MATRIX_HIGHLIGHT:
                return mmi_rg_menu_mainmenu_img_id_array[i].matrix_highlight_img;

            case MMI_RG_MM_IMG_MATRIX_CTRL_AREA:
                return mmi_rg_menu_mainmenu_img_id_array[i].matrix_controlled_area_img;

            case MMI_RG_MM_IMG_VENUS1_HIGHLIGHT:
                return mmi_rg_menu_mainmenu_img_id_array[i].venus1_highlight_img;

            case MMI_RG_MM_IMG_TITLE:
                return mmi_rg_menu_mainmenu_img_id_array[i].title_img;

            default:
                ASSERT(0);
                break;
            }
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_mainmenu_id_by_img
 * DESCRIPTION
 *  Function to get mainmenu's ID by image ID and type
 * PARAMETERS
 *  img_id      [IN]     ID of menu item
 *  img_type     [IN]     Type of image to get.
 * RETURNS
 *  menu ID
 *****************************************************************************/
MMI_MENU_ID mmi_res_get_mainmenu_id_by_img(MMI_IMG_ID img_id, mmi_rg_menu_mainmenu_img_type img_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    MMI_IMG_ID cur_img = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<mmi_rg_menu_mainmenuid_total; i++)
    {
        switch(img_type)
        {
        case MMI_RG_MM_IMG_LIST:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].list_img;
            break;

        case MMI_RG_MM_IMG_MATRIX:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].matrix_img;
            break;

        case MMI_RG_MM_IMG_PAGE:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].page_img;
            break;

        case MMI_RG_MM_IMG_VENUS1:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].venus_img_1;
            break;

        case MMI_RG_MM_IMG_VENUS2:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].venus_img_2;
            break;

        case MMI_RG_MM_IMG_MATRIX_HIGHLIGHT:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].matrix_highlight_img;
            break;

        case MMI_RG_MM_IMG_MATRIX_CTRL_AREA:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].matrix_controlled_area_img;
            break;

        case MMI_RG_MM_IMG_VENUS1_HIGHLIGHT:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].venus1_highlight_img;
            break;

        case MMI_RG_MM_IMG_TITLE:
            cur_img = mmi_rg_menu_mainmenu_img_id_array[i].title_img;
            break;

        default:
            ASSERT(0);
            break;
        }

        if (img_id == cur_img)
        {
            return mmi_rg_menu_mainmenu_img_id_array[i].id;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_mainmenu_3d_img_id
 * DESCRIPTION
 *  Function to get mainmenu's 3D image ID by menu ID 
 * PARAMETERS
 *  menu_id      [IN]     Menu ID of mainmenu 
 * RETURNS
 *  image ID
 *****************************************************************************/
MMI_IMG_ID mmi_res_get_mainmenu_3d_img_id(MMI_IMG_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_mainmenu_launch_count; i++)
    {
        if (menu_id == mmi_mainmenu_app_launch_table[i].menu_id)
        {
            return mmi_mainmenu_app_launch_table[i].image_id;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_get_mainmenu_launch_handler
 * DESCRIPTION
 *  Function to get mainmenu's launch handler by menu ID 
 * PARAMETERS
 *  menu_id      [IN]     Menu ID of mainmenu 
 * RETURNS
 *  Function pointer
 *****************************************************************************/
FuncPtr mmi_res_get_mainmenu_launch_handler(MMI_IMG_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_mainmenu_launch_count; i++)
    {
        if (menu_id == mmi_mainmenu_app_launch_table[i].menu_id)
        {
            return mmi_mainmenu_app_launch_table[i].lanuch_func;
        }
    }

    return 0;
}


#ifdef __MMI_RES_STR_CHECK_TOOL__
#define MMI_RES_STR_CHK_PATH (const WCHAR *)L"stringcheck.txt"
#if 0
/* under construction !*/
/* under construction !*/
#endif

#define MMI_RES_STR_CHK_ON 0x01
#if 0
/* under construction !*/
/* under construction !*/
#endif

U8 g_mmi_res_on = 0;


/*****************************************************************************
 * FUNCTION
 *  mmi_res_str_chk_set_status
 * DESCRIPTION
 *  Set status of checking tool
 * PARAMETERS
 *  is_on        : [IN]        Is On checking tool
 * RETURNS
 *  S32    0 is success
 *****************************************************************************/
S32 mmi_res_str_chk_set_status(MMI_BOOL is_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file = 0;
    U16 path[64];
    U8 tempbuf[48];
    U32 nLen = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_on)
    {
        if (SRV_FMGR_PUBLIC_DRV > 0)
        {
            mmi_res_str_chk_get_path(path, MMI_RES_STR_CHK_PATH);
            FS_Delete(path);
            file = FS_Open(path, FS_CREATE);
            if (file != 0)
            {
                tempbuf[0] = 0xFF;
                tempbuf[1] = 0xFE;
                FS_Write(file, (S8*)tempbuf, 2, &nLen);
                mmi_asc_to_wcs((WCHAR*)tempbuf, (CHAR *) gLanguageArray[gCurrLangIndex].aLangSSC);
                FS_Write(file, (S8*)tempbuf, mmi_ucs2strlen((S8*)tempbuf) * 2, &nLen);   
                FS_Close(file);
                
                g_mmi_res_on |= MMI_RES_STR_CHK_ON;
                return 0;
            }
        }
    }
    else
    {
        if (SRV_FMGR_PUBLIC_DRV > 0)
        {
            mmi_res_str_chk_get_path(path, MMI_RES_STR_CHK_PATH);
			FS_Delete(path);
	}
        g_mmi_res_on &= ~MMI_RES_STR_CHK_ON;
    }
    
    return -1;
}


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_res_str_chk_get_status
 * DESCRIPTION
 *  Get status of checking tool
 * PARAMETERS
 *  Void
 * RETURNS
 *  MMI_BOOL    is status ON.
 *****************************************************************************/
MMI_BOOL mmi_res_str_chk_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(g_mmi_res_on == 0)
        return MMI_FALSE;
    else
        return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_str_chk_record
 * DESCRIPTION
 *  Add a string to checking tool file
 * PARAMETERS
 *  str_id        : [IN]        String ID
 *  string        : [IN]        String buffer 
 * RETURNS
 *  S32     0 is success
 *****************************************************************************/
S32 mmi_res_str_chk_record(MMI_STR_ID str_id, WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file = 0;
    WCHAR id_buf_wc[24];
    WCHAR tempbuf[24];
    U16 path[64];
    U32 nLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!(g_mmi_res_on & MMI_RES_STR_CHK_ON) || SRV_FMGR_PUBLIC_DRV < 0)
    {
        return 0;
    }

    mmi_wcs_itow(str_id, tempbuf, 10);
    mmi_wcscpy(id_buf_wc, L"\r\n");
    mmi_wcscat(id_buf_wc, tempbuf);
    mmi_wcscat(id_buf_wc, L"\t");

    mmi_res_str_chk_get_path(path, MMI_RES_STR_CHK_PATH);
    file = FS_Open(path, FS_READ_WRITE);
    if (file != 0)
    {
        FS_Seek(file, 0, FS_FILE_END);
        FS_Write(file, (S8*)id_buf_wc, mmi_ucs2strlen((S8*)id_buf_wc) * 2, &nLen);
        FS_Write(file, (S8*)string, mmi_ucs2strlen((S8*)string) * 2, &nLen);

        FS_Close(file);
    }
    else
    {
        return -1;
    }

    return 0;    
}


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

/*****************************************************************************
 * FUNCTION
 *  mmi_res_str_chk_reset
 * DESCRIPTION
 *  Reset checking tool's recorded file
 * PARAMETERS
 *  Void
 * RETURNS
 *  S32     0 is success
 *****************************************************************************/
S32 mmi_res_str_chk_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file = 0;
    U16 path[64];
    U8 tempbuf[48];
    U32 nLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    /* Reset string record when entry new screen */
    if ((g_mmi_res_on & MMI_RES_STR_CHK_ON) && SRV_FMGR_PUBLIC_DRV >= 0)
    {
        /* Reset String */
        mmi_res_str_chk_get_path(path, MMI_RES_STR_CHK_PATH);
        FS_Delete(path);
        file = FS_Open(path, FS_CREATE);  
        if (file != 0)
        {   
            tempbuf[0] = 0xFF;
            tempbuf[1] = 0xFE;
            FS_Write(file, (S8*)tempbuf, 2, &nLen);
            mmi_asc_to_wcs((WCHAR*)tempbuf, (CHAR *)gLanguageArray[gCurrLangIndex].aLangSSC);
            FS_Write(file, (S8*)tempbuf, mmi_ucs2strlen((S8*)tempbuf) * 2, &nLen); 
            FS_Close(file);
        }
    }
    
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
/* under construction !*/
/* under construction !*/
#endif
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_str_chk_get_path
 * DESCRIPTION
 *  Get log file of string checking tool
 * PARAMETERS
 *  path    [OUT]   Log file path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_res_str_chk_get_path(WCHAR *path, const WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    kal_wsprintf(path, "%c:\\%w", SRV_FMGR_PUBLIC_DRV, filename);
}

#endif /* __MMI_RES_STR_CHECK_TOOL__ */

#ifndef __POPULATE_NO_IMAGE_DATA__
MMI_BOOL mmi_res_get_image_size(U16 id, U16 * width, U16 * height)
{
    MMI_BOOL result;
    result = mmi_res_theme_cache_get_image_size(id, width, height);
    if (result)
    {
        return MMI_TRUE;
    }
    else
    {
        U8 * img = (U8*)GetImageRaw(id);
        S8* imgBuffer = NULL;

        if (img == NULL)
        {
            return MMI_FALSE;
        }
        imgBuffer = (S8*)GetImageData(img);
        if(imgBuffer != NULL)
        {
            *width  = (U16)(( ((U16)imgBuffer[7])        << 4) | (((U16)imgBuffer[6] & 0xF0) >> 4));
            *height = (U16)(((((U16)imgBuffer[6]) & 0xF) << 8) |  ((U16)imgBuffer[5]));
             SetImageFlushable(img);
       		 return MMI_TRUE;
        }else{
            SetImageFlushable(img);
            return MMI_FALSE;
        }
    }
}
#endif //__POPULATE_NO_IMAGE_DATA__

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



#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
// Primary MAUI will use GDI APIs, GDI APIs uses __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__ APIs from W13.01
// so __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__ APIs must be put into primary MAUI, too
#pragma arm section code = "PRIMARY_ROCODE", rodata = "PRIMARY_RODATA", rwdata = "PRIMARY_RW"


#define GET_GROUP_FROM_RES_HANDLE(tempHandle) (((U16)(tempHandle)) >> (IMAGE_HANDL_OFFSET_LENGTH + 1))

static RES_CACHE_HANDLE_T mmi_res_image_cache = NULL;
extern unsigned short mtk_CurrMaxGroupsNum;

static MMI_BOOL CheckIsValidHandle(S8* tempHandle)
{
#ifndef __POPULATE_NO_IMAGE_DATA__
    return (tempHandle!=NULL) && !(CheckIsImageBufferPtr(tempHandle)) && (GET_GROUP_FROM_RES_HANDLE(tempHandle) < mtk_CurrMaxGroupsNum);
#else
    return (tempHandle!=NULL);
#endif
}

#ifdef __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
static MMI_BOOL DecompressImageGroup(S8 *dest, S8* groupData, U32 groupDataSize)
{
    S8 *source   = groupData + 4;  
    U32 compressedGroupDataSIze = ((0x00FF & *(groupData+2))<<8)| (0x00FF & (*(groupData+3)));
            
    // Decompress to dest area
    if( mmi_res_lzma_decompress_static_buffer((U8*)((U32)dest),  groupDataSize ,(U8*)((U32)source), compressedGroupDataSIze) == 0){
        return MMI_TRUE;
    }else{
        return MMI_FALSE;
    }
    // Test on no comopressed load:
    //memcpy((void*)dest,(void*)source,sourceLen);
}
#endif //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__

#ifdef __MMI_RESOURCE_IMAGE_THIRD_ROM__

#define MULTI_IMAGE_GROUP 0
#define SINGLE_IMAGE_GROUP 1
#define UNKNOWN_IMAGE_GROUP 2

static U16 GetThirdROMGroupSize(U16 groupIndex){
    U16 loadDataSize = 0;
#ifndef __POPULATE_NO_IMAGE_DATA__
    if(groupIndex < (mtk_CurrMaxGroupsNum-1))
    {
        loadDataSize = (U32)(mtk_nCustGroupNames[groupIndex+1].pImage) - (U32)(mtk_nCustGroupNames[groupIndex].pImage);
    }
    else
    {
        loadDataSize = MMIRESOUCE_3RD_ROM_Image_CONTENT_SIZE - (U32)(mtk_nCustGroupNames[groupIndex].pImage);            
    }
#endif
    return loadDataSize;

}

static U8 GetImageGroupType(U16 groupIndex){
    U16 loadDataSize = GetThirdROMGroupSize(groupIndex);
    if(loadDataSize <= RES_MULTI_IMG_GROUP_MAX_SIZE){
        return MULTI_IMAGE_GROUP;
    }
    if((loadDataSize > RES_MULTI_IMG_GROUP_MAX_SIZE) && (loadDataSize <= RES_BOOT_IMG_GROUP_MAX_SIZE)){
        return SINGLE_IMAGE_GROUP;
    }
    return UNKNOWN_IMAGE_GROUP;
}
static S8* LoadSingleImageGroupFromThirdROM(RES_CACHE_HANDLE_T cachePoolId, U16 groupIndex){
    // prepare cache
    U16 loadDataSize = 0;
    U8* cachePtr = NULL;
    U32 offset = 0;
    // Single image's index is always 0
    U32 imageHandle = 0xB0000000 | ((groupIndex << (IMAGE_HANDL_OFFSET_LENGTH + 1)) | IMAGE_GROUP_COMPRESSION_FLAG);

    loadDataSize = GetThirdROMGroupSize(groupIndex);
    MMI_ASSERT(loadDataSize <= (RES_BOOT_IMG_GROUP_MAX_SIZE));
#ifndef __POPULATE_NO_IMAGE_DATA__
    offset = (MMIRESOUCE_3RD_ROM_Image_BASE_ADDR + (U32)(mtk_nCustGroupNames[groupIndex].pImage) + 8);
#endif //__POPULATE_NO_IMAGE_DATA__
    cachePtr = (S8*)PrepareResObjectInCache(cachePoolId, imageHandle, loadDataSize);
    
    // Request cache memory failed. Please check if the cache size is enough or if the API SetImageFlushable is called.
   	MMI_ASSERT(cachePtr != NULL);
    MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_IMAGERES, (void *)cachePtr, offset, (loadDataSize -8));
    // Pin the target image
    SetImageBufferNonFlushableNoLock((S8*)imageHandle);
    return cachePtr;
    
}

static S8*  LoadMultImageGroupFromThirdROM(U8* groupBuffer, U16 groupIndex){
    U16 loadDataSize = GetThirdROMGroupSize(groupIndex);
    MMI_ASSERT(loadDataSize <=(RES_MULTI_IMG_GROUP_MAX_SIZE));
#ifndef __POPULATE_NO_IMAGE_DATA__
	MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_IMAGERES, (void *)groupBuffer, MMIRESOUCE_3RD_ROM_Image_BASE_ADDR + (U32)(mtk_nCustGroupNames[groupIndex].pImage), loadDataSize);
#endif //__POPULATE_NO_IMAGE_DATA__
    return groupBuffer;
}

#endif //__MMI_RESOURCE_IMAGE_THIRD_ROM__

static S8* GetImageFromMultiImageGroup(RES_CACHE_HANDLE_T cachePoolId, U16 groupIndex, U16 imageIndex, S8* unpackedImageGroup, U16 groupSize){
    U32 imageHandle = 0;
    S8* imagePtr = unpackedImageGroup;
    S8* targetImagePtr = NULL;
    S8 * cachePtr = NULL;
    U32 imgOffset = 0;
    U16 imageOffsetCount = 0;
    U32 imgSize = 0;
    
    while(  imgOffset < groupSize){
        imgSize = ( ((U32) (imagePtr[3]) ) & 0x000000FF )
            | (((U32) ((U32) imagePtr[2] << 8)) & 0x0000FF00 )
            | (((U32) ((U32) imagePtr[1] << 16))& 0x00FF0000 ) 
            | (((U32) ((U32) imagePtr[0] << 24))& 0xFF000000 );
        imageHandle = 0xB0000000 | ((groupIndex << (IMAGE_HANDL_OFFSET_LENGTH + 1)) | imageOffsetCount << 1 | IMAGE_GROUP_COMPRESSION_FLAG);
        
        // Image size should not exceed max group size configuration
        MMI_ASSERT(imgSize <= (RES_MULTI_IMG_GROUP_MAX_SIZE));

        // Decompress the entire group here
        cachePtr = RetriveResObjectFromCache(cachePoolId, imageHandle);

        if((cachePtr == NULL) && (imageOffsetCount == imageIndex)){
            cachePtr = PrepareResObjectInCache(cachePoolId, imageHandle, imgSize);
            // Request cache memory failed. Please check if the cache size is enough or if the API SetImageFlushable is called.
            MMI_ASSERT(cachePtr!=NULL);
            // Don't cache the image header
            memcpy((void*)cachePtr, (void*)(imagePtr+4), imgSize);			
        }
        // Found the target image
        if(imageOffsetCount == imageIndex){
            targetImagePtr = cachePtr;
            SetImageBufferNonFlushableNoLock((S8*)imageHandle);
        }
        // Prepared to load next image in this group
        imgOffset += (imgSize+ 4);
        imagePtr = unpackedImageGroup + imgOffset;
        imageOffsetCount++;
    }
    // All image buffer must be 4 bytes-align
    MMI_ASSERT(!((U32)targetImagePtr & 0x00000001));
    return targetImagePtr;
}


// Load image from externl storage        
static S8* MMILoadImageFromROM(RES_CACHE_HANDLE_T cachePoolId, U32 targetImageHandle){
    S8 * targetImagePtr = NULL;
    U32 imgSize = 0;
    U16 groupSize = 0;
    U16 groupIndex = 0;
    U16 imageIndex = 0;
    U8* imageGroupData = NULL;
    U8* unpackedImageGroup = NULL;
#ifdef __MMI_RESOURCE_IMAGE_THIRD_ROM__
    U8 imageGroupType = UNKNOWN_IMAGE_GROUP;  
#endif //__MMI_RESOURCE_IMAGE_THIRD_ROM__

    groupIndex = (U16)((0x0000FFFF & targetImageHandle) >> (IMAGE_HANDL_OFFSET_LENGTH + 1));
    imageIndex = (U16)(((0x0000FFFF & targetImageHandle) & (~IMAGE_GROUP_MASK)) >> 1); 
    
#ifdef __MMI_RESOURCE_IMAGE_THIRD_ROM__   
    imageGroupType = GetImageGroupType(groupIndex); 
    MMI_ASSERT(imageGroupType != UNKNOWN_IMAGE_GROUP);
    
    // Load image from single image group and return    
    if(imageGroupType == SINGLE_IMAGE_GROUP){
        targetImagePtr = LoadSingleImageGroupFromThirdROM(cachePoolId, groupIndex);
        MMI_ASSERT(targetImagePtr!=NULL);
        return targetImagePtr;
    }
    
    // Load multi-image group
    if(imageGroupType == MULTI_IMAGE_GROUP){
        imageGroupData = mmi_res_nand_image_group_buffer;
        LoadMultImageGroupFromThirdROM(imageGroupData, groupIndex);
    }
#else //__MMI_RESOURCE_IMAGE_THIRD_ROM__
    // Image data is already in ROM
#ifndef __POPULATE_NO_IMAGE_DATA__
    imageGroupData = mtk_nCustGroupNames[groupIndex].pImage;
#endif //__POPULATE_NO_IMAGE_DATA__
#endif // __MMI_RESOURCE_IMAGE_THIRD_ROM__

    groupSize  = ((0x00FF & (*imageGroupData))<<8) | (0x00FF & (*(imageGroupData+1))); 
    
#ifdef __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
    // Current we doesn't support __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__ with third rom
    unpackedImageGroup = mmi_res_image_group_buffer;
    if(DecompressImageGroup(unpackedImageGroup, imageGroupData, groupSize) == MMI_FALSE){
        return NULL;
    }
#else //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__
    unpackedImageGroup = imageGroupData + 4;
#endif //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__

    // Push each image object into cache
    return GetImageFromMultiImageGroup(cachePoolId, groupIndex, imageIndex, unpackedImageGroup, groupSize);

}

static void *img_load_mutex = NULL;

static void imgload_create_mutex(void)
{
    if(img_load_mutex == NULL){
    	img_load_mutex = (void*)kal_create_mutex("IMGL$");
    }
}


static void imgload_take_mutex()
{
    if (kal_query_systemInit() == KAL_TRUE)
    {
        return;
    }
    
    kal_take_mutex((kal_mutexid)img_load_mutex);    
}



static void imgload_give_mutex()
{
    if (kal_query_systemInit() == KAL_TRUE)
    {
        return;
    }
    
    kal_give_mutex((kal_mutexid)img_load_mutex);
}

void SetImageBufferFlushable(S8* imageHandle)
{
    U16 cacheObjectId = (U16)((U32)imageHandle);
	
#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_IMG_HANDLE_BY_SET_IMG_BUFFER_FLUSHABLE, imageHandle);
#endif
    if(!CheckIsValidHandle(imageHandle)){
        // Do nothing if it is a real image pointer, not a handle
        // or it is a bad handle
        return;
    }
    MMI_ASSERT(mmi_res_image_cache!=NULL); 
    // Please check if you use GetImage() after InitImageResourceCache() is invoked

    imgload_take_mutex();
    SetObjectFlushable( mmi_res_image_cache, cacheObjectId, MMI_TRUE);
    imgload_give_mutex();
}

static void SetImageBufferNonFlushableNoLock(S8* imageHandle)
{
    U32 cacheObjectId = (U32)imageHandle;
    if(!CheckIsValidHandle(imageHandle)){
    // Do nothing if it is a real image pointer, not a handle
        return;
    }
    MMI_ASSERT(mmi_res_image_cache!=NULL); 
    // Please check if you use GetImage() after InitImageResourceCache() is invoked
    
    SetObjectFlushable( mmi_res_image_cache, cacheObjectId, MMI_FALSE);
}

MMI_BOOL FlushImageBufferCacheForce(void)
{
    MMI_BOOL result = MMI_TRUE;
    imgload_take_mutex();
    result = FlushCacheForce(mmi_res_image_cache);	
    imgload_give_mutex();
    return result;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void InitImageResourceCache(void)
{
    imgload_create_mutex();
    if(mmi_res_image_cache == NULL)
    {
        mmi_res_image_cache = CreateResObjectCache(MMI_RESOURCE_IMAGE_CACHE_SIZE);
    }
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


S8 *GetImageBufferData(S8* ImageHandle)
{
#ifndef __POPULATE_NO_IMAGE_DATA__
#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_IMG_HANDLE_BY_GET_IMG_BUFFER, ImageHandle);
#endif
    //Decode Handler
    if(!CheckIsValidHandle(ImageHandle))
    {
        return (S8*)ImageHandle;
    }
    else
    {
        U32 tempHandle = (U32)ImageHandle;
        S8* returnImage = NULL;
        
        MMI_ASSERT(mmi_res_image_cache!=NULL); 
        // Please check if you use GetImage() after InitImageResourceCache() is invoked
 
        imgload_take_mutex();
        
        // Check Cache 
        returnImage = (S8 *) (U32)RetriveResObjectFromCache(mmi_res_image_cache, tempHandle);
        
        if(returnImage != NULL){
            // Image is already in cache, just pin this image
            SetImageBufferNonFlushableNoLock((S8*)tempHandle);
        }else{
            returnImage = (S8*)(MMILoadImageFromROM(mmi_res_image_cache, tempHandle));
        }        
        imgload_give_mutex();

        if(returnImage != NULL){
        #ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
	    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_CACHE_ADDRESS_BY_IMG_HANDLE,mmi_res_image_cache,ImageHandle,returnImage);
        #endif
            return returnImage;
        }
        else
        {
            return ImageHandle;
        }
    }
#else //__POPULATE_NO_IMAGE_DATA__
    return ImageHandle;
#endif //__POPULATE_NO_IMAGE_DATA__
}

// Debug only, the API can retrive the uncompressed image static built in the image
// Don't enable __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__ in any official load since
// it needs a lot of RAM/RAM
#ifdef __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__
extern const CUSTOM_IMAGE mtk_nCustImageNames[];

S8 *DebugGetImageRaw(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    S8 *img;
    img = GetImageFromIndex(
        ImageId,
        ImageIdMap,
        ImageIdSearchMap,
        mtk_nCustImageNames,
        CurrMaxSearchImageId);     

    /* CustPack */
    if (img == NULL)
    {
        img = GetImageFromIndex(
            ImageId,
            ImageIdMapEXT,
            ImageIdSearchMapEXT,
            nCustImageNamesEXT,
            CurrMaxSearchImageIdEXT);
    }

    if (img != NULL)
    {
        return img;
    }
    else
    {
        return (S8*) (nCustImageNames[0].pImage);
    }
}


S8 *DebugGetImage(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__) && !defined(__IOT__)
    /* MTE image resource replacement */
    if (mmi_mte_is_resource_replacement_working())
    {
        /* only handle image resources here. */
        if (img = mmi_mte_get_image_resource_buffer_by_id((U32)ImageId))
        {
            return img;
        }
    }        
#endif /* __MTK_TARGET__ */

    MMI_RES_IMG_CHK_RECORD(ImageId, NULL);

    /* get specific images stored in theme structure */
#if !defined(__IOT__)
    img = (U8*)GetImageTheme(ImageId);
#endif
    if (img != NULL)
    {
        return (S8*)img;
    }

    img = (U8*)mmi_res_get_theme_image(ImageId);
    if (img != NULL)
    {
        return (S8*)img;
    }

    /* load image raw data */
    img = (U8*)GetImageRaw(ImageId);

    if(img == NULL)
    {
        return (S8*)img;
    }
    return (S8*)img;
}


#endif //__MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__

#ifdef __MMI_RESOURCE_UT_IMAGE_GROUP_DEBUG_HELPER__
extern const CUSTOM_IMAGE	mtk_nCustImageHandles[];

MMI_BOOL DebugImageCompare(S8 * image, S8* image2)
{
    // Get Size
    U16 imgSize0;
    U16 imgSize1;
    
    if(image == NULL)
    {
        if(image2 == NULL)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }    
    }
    imgSize0 = gdi_image_get_buf_len((U8*)((U32)image));
    imgSize1 = gdi_image_get_buf_len((U8*)((U32)image2));
    if(imgSize0 != imgSize1)
    {
    	return MMI_FALSE;
    }

    if(memcmp((void *)image, (void*) image2, imgSize0)!=0)
    {
    	return MMI_FALSE;
    }
    
    return MMI_TRUE;
}

S8 *DebugGetImageHandleRaw(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DEVAPP_RESOURCE
    if ((ImageId >= DEVAPP_BASE && ImageId <= DEVAPP_BASE_MAX) ||
        (ImageId >= AVK_BASE && ImageId <= AVK_BASE_MAX))
    {
        S8 *ret_image = DevAppGetImage(ImageId);

        return ret_image;
    }
#endif
    S8 *img;
    img = GetImageFromIndex(
        ImageId,
        ImageIdMap,
        ImageIdSearchMap,
        mtk_nCustImageHandles,
        CurrMaxSearchImageId);
    /* CustPack */
    if (img == NULL)
    {
        img = GetImageFromIndex(
            ImageId,
            ImageIdMapEXT,
            ImageIdSearchMapEXT,
            nCustImageNamesEXT,
            CurrMaxSearchImageIdEXT);
    }

    if (img != NULL)
    {
        return img;
    }
    else
    {
        return (S8*) (nCustImageNames[0].pImage);
    }
}

S8 *DebugGetImageHandle(U16 ImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__) && !defined(__IOT__)
    /* MTE image resource replacement */
    if (mmi_mte_is_resource_replacement_working())
    {
        /* only handle image resources here. */
        if (img = mmi_mte_get_image_resource_buffer_by_id((U32)ImageId))
        {
            return img;
        }
    }        
#endif /* __MTK_TARGET__ */

    MMI_RES_IMG_CHK_RECORD(ImageId, NULL);

    /* get specific images stored in theme structure */
#if !defined(__IOT__)
    img = (U8*)GetImageTheme(ImageId);
#endif

    if (img != NULL)
    {
        return (S8*)img;
    }

    img = (U8*)mmi_res_get_theme_image(ImageId);
    if (img != NULL)
    {
        return (S8*)img;
    }

    /* load image raw data */
    img = (U8*)GetImageRaw(ImageId);

    if(img == NULL)
    {
        return (S8*)img;
    }

    return (S8*)img;
}

#endif //__MMI_RESOURCE_UT_IMAGE_GROUP_DEBUG_HELPER__

#pragma arm section code, rodata, rwdata

#endif //__MMI_RESOURCE_IMAGE_GROUP_COMPRESS__

