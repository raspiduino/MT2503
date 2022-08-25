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
 *   StandaloneRes.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements standalone resource related functions
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "MMI_features.h"

#include "string.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "CustThemesRes.h"
#include "CustVenusThemeRes.h"
//#include "DownloadProtos.h"
#include "dcl.h"
#include "IMERes.h"

#include "custom_jump_tbl.h"
#include "verno.h"
#ifdef __J2ME__
#include "j2me_custom.h"
#endif 

#if (!defined(__L1_STANDALONE__) && !defined(EMPTY_MMI))
extern void MMIResourceMismatchWarning(
                kal_int8 errType,
                kal_int8 errResType,
                kal_uint8 const *codeversion,
                kal_uint8 const *resversion);
#endif /* (!defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)) */ 

#include "resource_audio.h"
#include "resource_custpack_jtbl.h"

#if defined(WAP_SUPPORT) || defined(__CERTMAN_SUPPORT__)
#include "custpack_certs.h"
#endif 

#ifdef __J2ME__
#include "custpack_java_certs.h"
#endif /* __J2ME__ */

/*RHR*/
#include "kal_non_specific_general_types.h"
    #include "resource_verno.h"
    #include "FontRes.h"
    #include "nvram_defs.h"
    #include "kal_release.h"
 
/* IMAGE variables */
extern void *image2ndJumpTbl[];
extern Type_Preamble_Content ImageResPreamble;
CUSTOM_IMAGE *nCustImageNames = NULL;
U16 CurrMaxImageNum = 0;
S32 n_MMI_themes = 0;
S32 mtk_n_MMI_themes = 0;

char *mmi_theme_phone_model;

/* Venus Theme variables */
mmi_res_theme_system_strcut* g_mmi_res_theme_system_data_ptr = NULL;

#if defined(WAP_SUPPORT) || defined(__CERTMAN_SUPPORT__)
custpack_root_ca_header_struct* resource_root_ca;
#endif

#ifdef __J2ME__
custpack_java_root_ca_header_struct* resource_java_root_ca;
#endif

#ifdef __MMI_THEMES_V2_SUPPORT__
theme_details_struct *MMI_themes;
#else 
MMI_theme **MMI_themes = NULL;
#endif 

/* 101205 audio resource Calvin Start */
/* AUTOGEN AUDIO variables */
extern void *autogenaudio2ndJumpTbl[];
extern Type_Preamble_Content AutogenAudioResPreamble;
CUSTOM_AUDIO *nCustAudioNames = NULL;
U16 CurrMaxAudioNum = 0;

/* 101205 audio resource Calvin End */

/* Audio variables */
extern const device_tones_struct *mtk_resource_tones[];

extern Type_Preamble_Content AudioResPreamble;

/* Str variables */
extern void *langpack2ndJumpTbl[];
extern Type_Preamble_Content LangPackResPreamble;

//071706 menu resource
CUSTOM_MENU *nCustMenus = NULL;
CUSTOM_MENU_RES_ENTRY *gMenuResEntry = NULL;
S32 av_total_menuitem = 0;

unsigned short CurrMaxSearchFontIdEXT;
CUSTOM_FONT *nCustFontNamesEXT;
CUSTOM_FONT_MAP *FontIdMapEXT;
CUSTOM_FONT_SEARCH_MAP *FontIdSearchMapEXT;

sLanguageDetails *gLanguageArray = NULL;
U16 gMaxDeployedLangs = 0;
font_group_struct *gfontfamily = NULL;

#ifdef __MMI_FONT_COMPRESSION__
mmi_font_compress_info *gFontZipInfo = NULL;
#endif /* __MMI_FONT_COMPRESSION__ */

#ifdef __MMI_BDF_SW_COMPRESSION__
U8 *gHWCompressionLv1Table = NULL, *gHWCompressionLv2Table = NULL;
#endif
StringResList *gStringList = NULL;
U16 TRANS_STRING_COUNT = 0;

#if defined(__MMI_T9__)
#if defined(__MMI_T9_V7__)
const sIMEModuleDetails gIMEModule = T9V7;
#elif defined(__MMI_T9_V7_4__) 
const sIMEModuleDetails gIMEModule = T9V7_4;
#elif defined(__MMI_XT9__)
const sIMEModuleDetails gIMEModule = XT9;
#else 
const sIMEModuleDetails gIMEModule = T9V6;
#endif 
#elif defined(__MMI_ZI__)
const sIMEModuleDetails gIMEModule = ZiV6;
#else 
const sIMEModuleDetails gIMEModule = IME_OTHERS;
#endif 

const sIMEModeDetails *gIMEModeArray = NULL;
const sIMEModeDetails *gIMEQSearchModeArray = NULL;
const sIMELDBDetails *gIMELDBArray = NULL;
#if !defined __MMI_XT9__
#if defined(__MMI_T9__)
#if defined(__MMI_T9_V7__)|| defined(__MMI_T9_V7_4__)
#if defined(__MMI_T9_TR_CHINESE__)|| defined(__MMI_T9_HK_CHINESE__)
T9ChineseData T9FARDATA gT9TRChineseLDB;
#endif /* defined(__MMI_T9_TR_CHINESE__) */
#if defined(__MMI_T9_SM_CHINESE__)
T9ChineseData T9FARDATA gT9SMChineseLDB;
#endif /* defined(__MMI_T9_SM_CHINESE__) */
#else /* defined(__MMI_T9_V7__) */
#if defined(__MMI_T9_TR_CHINESE__) 
T9ChineseData FARDATA gT9TRChineseLDB;
#endif /* defined(__MMI_T9_TR_CHINESE__) */
#if defined(__MMI_T9_SM_CHINESE__)
T9ChineseData FARDATA gT9SMChineseLDB;
#endif /* defined(__MMI_T9_SM_CHINESE__) */
#endif /* defined(__MMI_T9_V7__) */ 
#endif /* defined(__MMI_T9__) */ 
#endif
/* J2ME variables */
#ifdef __J2ME__
extern void *J2ME2ndJumpTbl[];
extern Type_Preamble_Content J2MEResPreamble;
#endif /* __J2ME__ */ 



extern void *custpack2ndJumpTbl[];
extern Type_Preamble_Content CustPackResPreamble;

/* CustPack image variables */
CUSTOM_IMAGE *nCustImageNamesEXT = NULL;
U16 CurrMaxImageNumEXT = 0;
CUSTPACK_IMAGE_HEADER *pimage_header = NULL;

/* 101205 audio resource Calvin Start */
/* CustPack image variables */
CUSTOM_AUDIO *nCustAudioNamesEXT = NULL;
U16 CurrMaxAudioNumEXT = 0;
CUSTPACK_AUDIO_HEADER *paudio_header = NULL;


/*****************************************************************************
 * FUNCTION
 *  StandaloneResValidation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

static void StandaloneResValidation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JUMP_TABLE_ENTRY_ENUM res_type;
    kal_uint32 res_type_code, res_MAGIC;
    kal_char *project_ID;
    kal_int8 errorType = -1;
    kal_int8 errorResType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (res_type = JUMP_TABLE_ENTRY_START; res_type <= JUMP_TABLE_ENTRY_END; res_type++)
    {
        project_ID = (kal_char*) GET_Res_Addr(res_type, 0);
        res_type_code = *(kal_uint32*) GET_Res_Addr(res_type, RESOURCE_TYPE_OFFSET);
        res_MAGIC = *(kal_uint32*) GET_Res_Addr(res_type, MAGIC_NUM_OFFSET);

        /* Check consistency between JUMP TABLE and the RESOURCE BIN */
        if(res_type_code != GET_Res_ResVersion(res_type))
        {
            goto Validation_Exit;
        }

        if (res_MAGIC != GET_Res_Magic(res_type))
        {
            goto Validation_Exit;
        }

        /* ID verification: PROJECT_ID */
        
        /* Check consistency between MAUI and the RESOURCE BIN */
        if((res_type_code & RESOURCE_TYPE_MASK) == RESOURCE_TYPE_CUSTPACK){
        	  if((res_type_code & RESOURCE_VERSION_MASK) != CURRENT_CUSTPACK_RES_VERSION)
        	  	  goto Validation_Exit;
        }
        if((res_type_code & RESOURCE_TYPE_MASK) == RESOURCE_TYPE_LANG_PACK){
        	  if((res_type_code & RESOURCE_VERSION_MASK) != CURRENT_LANG_PACK_RES_VERSION)
            goto Validation_Exit;
        }

        /* ID verification: RESOURCE TYPE */
        if (((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_AUDIO) &&
            ((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_IMAGE) &&
            ((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_LANG_PACK)
    #ifdef __J2ME__
            && ((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_J2ME)
    #endif 
            && ((res_type_code & RESOURCE_TYPE_MASK) != RESOURCE_TYPE_CUSTPACK))
            goto Validation_Exit;

        /* MAGIC# verification */
        if (res_MAGIC != MAGIC_NUMBER)
        {
            goto Validation_Exit;
        }

    }

    return;

  Validation_Exit:
    {
        kal_uint8 dspl_text[PROJECTID_LEN];

        /*The following code is used to do DRV_POWERON*/
        DCL_HANDLE handle;
        handle = DclPW_Open(DCL_PW, FLAGS_NONE);
        DclPW_Control(handle, PW_CMD_POWERON, NULL);
        DclPW_Close(handle);

        if (strlen(VERNO_STR) < PROJECTID_LEN)
        {
            kal_mem_set(dspl_text, '\0', PROJECTID_LEN);
            strncpy((char*)dspl_text, (const char*)project_ID, sizeof(VERNO_STR));
            dspl_text[sizeof(VERNO_STR)] = '\0';

            MMIResourceMismatchWarning(
                errorType,
                errorResType,
                (kal_uint8 const*)VERNO_STR,
                (kal_uint8 const*)dspl_text);
        }
        else    /* VERNO string too long (> 32 characters) */
        {
            ASSERT(KAL_FALSE);
        }

        while (1);
    }
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*****************************************************************************
 * FUNCTION
 *  InitializeResourceVariables
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
extern void InitImageResourceCache(void);
#endif //__MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void InitializeResourceVariables(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void **langpack_JTbl = (void **)GET_ResLangPack_Addr(ENTRY_PREAMBLE);
    void **custpack_header = (void **)GET_ResCUSTPACK_Addr(ENTRY_PREAMBLE);     /* __CUSTPACK_MULTIBIN__ */
    CUSTPACK_FONT_HEADER *font_header = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)	
    /* IMAGE Initialization */
#ifndef __POPULATE_NO_IMAGE_DATA__
    {
        nCustImageNames = (CUSTOM_IMAGE*) (image2ndJumpTbl[0]);
        CurrMaxImageNum = *((unsigned short*)(image2ndJumpTbl[1]));
#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
        InitImageResourceCache();
#endif //__MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
    }
#endif //__POPULATE_NO_IMAGE_DATA__
#endif/*!defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/
    /* AUDIO Initialization */
    {
        resource_tones = (device_tones_struct **) mtk_resource_tones;
    }

    /* 101205 audio resource Calvin Start */
    /* AUTOGEN AUDIO Initialization */
    {
        nCustAudioNames = (CUSTOM_AUDIO*) (autogenaudio2ndJumpTbl[0]);
        CurrMaxAudioNum = *((unsigned short*)(autogenaudio2ndJumpTbl[1]));
    }
    /* 101205 audio resource Calvin End */

#ifdef __J2ME__
    /* For backward compatiable old project without j2me feature */
    /* J2ME Initialization */
    {
        j2me_custom_file_info_ptr = (j2me_custom_file_info_struct*) (J2ME2ndJumpTbl[GAMETYPE_JAVA_GAME]);
        if (j2me_custom_file_info_ptr)
        {
            game_j2me_default_game_count = j2me_custom_file_info_ptr->default_mids_count;
            game_virtual_file_count = j2me_custom_file_info_ptr->virtual_file_info.virtual_file_count;
        }

	#ifdef __SUPPORT_INFUSIO__
        eureka_custom_file_info_ptr = (j2me_custom_file_info_struct*) (J2ME2ndJumpTbl[GAMETYPE_INFUSIO_EUREKA]);
        if (eureka_custom_file_info_ptr)
        {
            eureka_default_game_count = eureka_custom_file_info_ptr->default_mids_count;
            eureka_virtual_file_count = eureka_custom_file_info_ptr->virtual_file_info.virtual_file_count;
        }	
	#endif /* __SUPPORT_INFUSIO__ */
	
	#ifdef SUPPORT_SURFKITCHEN
        surfkitchen_custom_file_info_ptr = (j2me_custom_file_info_struct*) (J2ME2ndJumpTbl[GAMETYPE_SURFKITCHEN]);
        if (surfkitchen_custom_file_info_ptr)
        {
            surfkitchen_default_game_count = surfkitchen_custom_file_info_ptr->default_mids_count;
            surfkitchen_virtual_file_count = surfkitchen_custom_file_info_ptr->virtual_file_info.virtual_file_count;
        }	
	#endif /* SUPPORT_SURFKITCHEN */

	#ifdef SUPPORT_MUSICWAV
        musicwav_custom_file_info_ptr = (j2me_custom_file_info_struct*) (J2ME2ndJumpTbl[GAMETYPE_MUSICWAV]);
        if (musicwav_custom_file_info_ptr)
        {
            musicwav_default_game_count = musicwav_custom_file_info_ptr->default_mids_count;
            musicwav_virtual_file_count = musicwav_custom_file_info_ptr->virtual_file_info.virtual_file_count;
        }	
	#endif /* SUPPORT_MUSICWAV */
	
    }
#endif /* __J2ME__ */ 


    if (((kal_uint32) langpack_JTbl > 0x1) && ((kal_uint32) & LangPackResPreamble > 0x1))       /* dummy reference to make the variable exist */
    {
        gLanguageArray = (sLanguageDetails*) (langpack2ndJumpTbl[0]);
        gMaxDeployedLangs = *((unsigned short*)(langpack2ndJumpTbl[1]));
    #ifdef __MMI_FONT_COMPRESSION__
        gFontZipInfo = (mmi_font_compress_info*)(langpack2ndJumpTbl[11]);
    #endif /* __MMI_FONT_COMPRESSION__ */
    #ifdef __MMI_BDF_SW_COMPRESSION__
        gHWCompressionLv1Table = (U8*)(langpack2ndJumpTbl[15]);
        gHWCompressionLv2Table = (U8*)(langpack2ndJumpTbl[16]);
    #endif
    #ifndef __POPULATE_NO_STRING_DATA__
        gStringList = (StringResList*) (langpack2ndJumpTbl[2]);
        TRANS_STRING_COUNT = *((U16*)(langpack2ndJumpTbl[14]));
    #endif //__POPULATE_NO_STRING_DATA__

        if (gIMEModule != *((sIMEModuleDetails*) (langpack2ndJumpTbl[6])))
        {
            ASSERT(0);
        }
        gIMEModeArray = (sIMEModeDetails*) (langpack2ndJumpTbl[3]);
        gIMEQSearchModeArray = (sIMEModeDetails*) (langpack2ndJumpTbl[4]);
        gIMELDBArray = (sIMELDBDetails*) (langpack2ndJumpTbl[5]);
#if !defined __MMI_XT9__    
    #if defined(__MMI_T9__)
    #if defined(__MMI_T9_TR_CHINESE__)|| defined(__MMI_T9_HK_CHINESE__)
    #if defined(__MMI_T9_V7__)||defined(__MMI_T9_V7_4__)
        gT9TRChineseLDB = *((T9ChineseData const T9FARDATA*)(langpack2ndJumpTbl[7]));
    #else 
        gT9TRChineseLDB = *((T9ChineseData const FARDATA*)(langpack2ndJumpTbl[7]));
    #endif 
    #endif /* defined(__MMI_T9_TR_CHINESE__) */ 
    #if defined(__MMI_T9_SM_CHINESE__)
    #if defined(__MMI_T9_V7__)||defined(__MMI_T9_V7_4__)
        gT9SMChineseLDB = *((T9ChineseData const T9FARDATA*)(langpack2ndJumpTbl[8]));
    #else 
        gT9SMChineseLDB = *((T9ChineseData const FARDATA*)(langpack2ndJumpTbl[8]));
    #endif 
    #endif /* defined(__MMI_T9_SM_CHINESE__) */ 
    #endif /* defined(__MMI_T9__) */ 
#endif
        av_total_menuitem = *((S32 *)langpack2ndJumpTbl[13]); // Total number of available menuitems
        gMenuResEntry = (CUSTOM_MENU_RES_ENTRY *)(langpack2ndJumpTbl[9]);//071706 menu resource
        nCustMenus = gMenuResEntry->MenuRes;

        font_header = (CUSTPACK_FONT_HEADER*)(langpack2ndJumpTbl[10]);
        CurrMaxSearchFontIdEXT = font_header->CurrMaxSearchFontIdEXT;
        nCustFontNamesEXT = font_header->CustFontNamesEXT;
        FontIdMapEXT = font_header->CustFontMapEXT;
        FontIdSearchMapEXT = font_header->CustFontSearchMapEXT;
        gfontfamily = (font_group_struct*)(langpack2ndJumpTbl[12]);
    }


    /* CustPack Initialization */
    if (((kal_uint32) custpack2ndJumpTbl > 0x1) && ((kal_uint32) & CustPackResPreamble > 0x1))  /* dummy reference to make the variable exist */
    {
#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)    
        /* CustPack Image Initialization */
    #ifndef __POPULATE_NO_IMAGE_DATA__
        pimage_header = (CUSTPACK_IMAGE_HEADER*) (custpack_header[CUSTPACK_IMAGE]);
        nCustImageNamesEXT = (CUSTOM_IMAGE*) pimage_header->CustImageNamesEXT;
        CurrMaxImageNumEXT = pimage_header->MaxImageNumEXT;
    #endif
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/
        /* CustPack Autogen Audio Initialization */
        paudio_header = (CUSTPACK_AUDIO_HEADER*) (custpack_header[CUSTPACK_AUTOGEN_AUDIO]);
        nCustAudioNamesEXT = (CUSTOM_AUDIO*) paudio_header->CustAudioNamesEXT;
        CurrMaxAudioNumEXT = paudio_header->MaxAudioNumEXT;

    #if defined(WAP_SUPPORT) || defined(__CERTMAN_SUPPORT__)
        resource_root_ca = (custpack_root_ca_header_struct*) custpack_header[CUSTPACK_ROOT_CA];
    #endif
    }

#ifdef __J2ME__
    /* CustPack Initialization */
    if (((kal_uint32) custpack2ndJumpTbl > 0x1) && ((kal_uint32) & CustPackResPreamble > 0x1))  /* dummy reference to make the variable exist */
    {
        /* CustPack Java Root CA Certs Initialized in init procedure */
        resource_java_root_ca = (custpack_java_root_ca_header_struct*) custpack_header[CUSTPACK_JAVA_CA];
    }
#endif /* !__J2ME__ */

#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
    if (((kal_uint32) custpack2ndJumpTbl > 0x1) && ((kal_uint32) & CustPackResPreamble > 0x1))
    {
    #ifdef __MMI_THEMES_V2_SUPPORT__
        MMI_themes = ((CUSTPACK_THEME_HEADER*) (custpack_header[CUSTPACK_THEME]))->mmi_themes;
    #else 
        MMI_themes = ((CUSTPACK_THEME_HEADER*) (custpack_header[CUSTPACK_THEME]))->mmi_themes;
    #endif 
        n_MMI_themes = ((CUSTPACK_THEME_HEADER*) (custpack_header[CUSTPACK_THEME]))->n_themes;
        mtk_n_MMI_themes = ((CUSTPACK_THEME_HEADER*) (custpack_header[CUSTPACK_THEME]))->n_themes;
        mmi_theme_phone_model = (char*)((CUSTPACK_THEME_HEADER*) (custpack_header[CUSTPACK_THEME]))->theme_model;
    }

    /* Venus Theme */
    if (((kal_uint32) custpack2ndJumpTbl > 0x1) && ((kal_uint32) & CustPackResPreamble > 0x1))  /* dummy reference to make the variable exist */
    {
        g_mmi_res_theme_system_data_ptr = (mmi_res_theme_system_strcut*)(custpack_header[CUSTPACK_VENUS_THEME]);
    }
#endif/*#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)*/
    StandaloneResValidation();
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

