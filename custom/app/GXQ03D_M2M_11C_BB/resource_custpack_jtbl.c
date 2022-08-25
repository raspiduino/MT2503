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
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   resource_custpack_jtbl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements indirect NVRAM jumps table for multi-load.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __L1_STANDALONE__

#include "MMI_features.h"

#include "kal_release.h"
#include "custom_mmi_default_value.h"
#include "resource_custpack_jtbl.h"
#include "nvram_user_defs.h"
#include "resource_audio.h"
#ifndef EMPTY_MMI
#include "CustThemesRes.h"
#include "CustVenusThemeRes.h"
#endif
// __CUSTPACK_MULTIBIN Calvin BEGIN
#include "CustDataRes.h"//040805 Calvin added
#include "Kal_release.h"//040805 Calvin added
// __CUSTPACK_MULTIBIN Calvin END
// __CUSTPACK_MULTIBIN     Johnnie   BEGIN
#include "custpack_certs.h"
#include "custpack_java_certs.h" 
// __CUSTPACK_MULTIBIN     Johnnie   END

//__CUSTPACK_MULTIBIN Cylen BEGIN
extern const kal_uint8 NVRAM_SETTING_DEFAULT[];
extern const kal_uint8 NVRAM_PHONEBOOK_SOS_DEFAULT[];
extern const kal_uint8 NVRAM_PHONEBOOK_SPEEDDIAL_DEFAULT [];
extern const kal_uint8 NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[];
extern const kal_uint8 NVRAM_EF_MS_SECURITY_DEFAULT[];
extern const kal_uint8 NVRAM_CACHE_BYTE_DEFAULT[];
extern const kal_uint8 NVRAM_CACHE_SHORT_DEFAULT[];
extern const kal_uint8 NVRAM_CACHE_DOUBLE_DEFAULT[];
extern const kal_uint8 NVRAM_EF_ALS_LINE_ID_DEFAULT[];
extern const kal_uint8 NVRAM_EF_MSCAP_DEFAULT[];
extern const kal_uint8 NVRAM_EF_RAC_PREFERENCE_DEFAULT[];

extern const custpack_nvram_header custpack_nvram_ptr;
//__CUSTPACK_MULTIBIN Cylen END

#if !defined(__MMI_UI_DISPLAY_LEVEL_NONE__) 
// __CUSTPACK_MULTIBIN Calvin BEGIN
extern const CUSTPACK_IMAGE_HEADER mtk_image_header;//040805 Calvin added
// __CUSTPACK_MULTIBIN Calvin END
#endif

// __CUSTPACK_MULTIBIN Calvin BEGIN
extern const CUSTPACK_AUDIO_HEADER mtk_audio_header;//101205 audio resource Calvin added
// __CUSTPACK_MULTIBIN Calvin END
#if !defined(EMPTY_MMI) && !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
extern const CUSTPACK_THEME_HEADER mtk_theme_header;
extern const mmi_res_theme_system_strcut g_mmi_res_theme_system_data;
#endif

//extern const custpack_audio_header custpack_audio;


void* custpack2ndJumpTbl[] = 
{
#if !defined(EMPTY_MMI)&& !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)    
    (void *) &mtk_theme_header,
#else
    (void *)0,
#endif
#if !defined(EMPTY_MMI)&& !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)  
    #ifndef __POPULATE_NO_IMAGE_DATA__
	(void *)&mtk_image_header, 	//CUSTPACK_IMAGE
    #else
        0,
    #endif
#else
    (void *)0,
#endif
    //(void *)&custpack_audio,        /* CUSTPACK_AUDIO */
    (void *)0,
#ifndef EMPTY_MMI
	(void *)&mtk_audio_header,  //CUSTPACK_AUTOGEN_AUDIO
#else
    (void *)0,
#endif
	(void *)&custpack_nvram_ptr, 	//CUSTPACK_NVRAM
#if defined (WAP_SUPPORT) || defined (__CERTMAN_SUPPORT__)
    (void *)&custpack_root_ca, 	    /* CUSTPACK_ROOT_CA */
#else
    (void *)0,
#endif /* WAP_SUPPORT */ 
#ifdef __J2ME__
    (void *)&custpack_java_root_ca, 	    /* CUSTPACK_JAVA_CA */
#else /* !__J2ME__ */
    (void *)0,
#endif /* __J2ME__ */
#if !defined(EMPTY_MMI)&& !defined(__MMI_UI_DISPLAY_LEVEL_NONE__)
    (void *)&g_mmi_res_theme_system_data,   /* for XML-based theme, like Cosmos theme, etc. */
#else
    (void *)0,
#endif
	(void *)0						//CUSTPACK_VAR
};
//#endif
#endif /* !__L1_STANDALONE__ */
