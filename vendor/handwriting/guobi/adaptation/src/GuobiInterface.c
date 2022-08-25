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
 * GuobiInterface.c
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file is intends for Pen Function in Editor
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "ime_lib_config.h"


#if defined(__MMI_GUOBI_HW__) && defined(__MMI_TOUCH_SCREEN__)
#include "kal_release.h"
#include "gui_data_types.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#if !defined(__MTK_TARGET__)
#define __align(X)
#endif


#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

#define GBHW_DATA_FROM_FILE

#include "fs_gprot.h"
#include "FileMgrSrvGprot.h"
#include "kal_trace.h"
#include "MMI_fw_trc.h"

#elif defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
#define GBHW_DATA_FROM_FILE
#include "third_rom.h"
#include "ResThirdROMUtil.h"
#else 

#if !defined(__MMI_GUOBI_HW_FRENCH__) && !defined(__MMI_GUOBI_HW_GERMAN__) && !defined(__MMI_GUOBI_HW_INDONESIAN__) && \
	!defined(__MMI_GUOBI_HW_ITALIAN__) && !defined(__MMI_GUOBI_HW_MALAY__) && !defined(__MMI_GUOBI_HW_PORTUGESE__) && \
	!defined(__MMI_GUOBI_HW_TURKISH__) && !defined(__MMI_GUOBI_HW_SPANISH__) &&  \
	(defined(__MMI_GUOBI_HW_TR_CHINESE__) || defined(__MMI_GUOBI_HW_SM_CHINESE__))
#define __MMI_GUOBI_HW_CH_ONLY__
#endif

#if defined(__MMI_GUOBI_HW_SC_SLIM__)
#include "hw_edit_sc_slim.h"
#elif defined(__MMI_GUOBI_HW_SC__)
#include "hw_edit_sc.h"
#elif defined(__MMI_GUOBI_HW_TC__)
#include "hw_edit_tc.h"
#elif defined(__MMI_GUOBI_HW_STANDARD__)
#include "hw_edit_sc_tc_full.h"
#endif

#ifndef __MMI_GUOBI_HW_CH_ONLY__
#include "hw_edit_latin.h"
#endif


#endif //#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

#include "GBHW.h"
#include "Handwriting_engine.h"

//#define __GB_HW_ENGINE_SWLA__
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__GB_HW_ENGINE_SWLA__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    #define GB_HW_SWLA_START(_symbol_)
    #define GB_HW_SWLA_STOP(_symbol_)
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#if defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
    
#define HANDWRITING_DATA_BUFF_SIZE_FOR_FILE	(45*1024)
// the order should be same with the data image in the third rom
typedef enum hand_writing_database_type
{
    HW_DATA_START = 0,
    HW_DATA_LATIN = HW_DATA_START,
    HW_DATA_CHINESE,
    HW_DATA_END,
    HW_DATA_INVALID
}hand_writing_database_type;

typedef struct data_offset_info
{
    U32 start_address;
    U32 current_address;
    enum hand_writing_database_type database_type;
}data_offset_info;

typedef struct database_info
{
    U8 cid;
    S32 size;
}database_info;

data_offset_info g_gb_hand_writing_data_info;

__align(4) static U8 g_HandWriteDataBuff[HANDWRITING_DATA_BUFF_SIZE_FOR_FILE];

database_info g_database_mapping[HW_DATA_END] = 
{
    #include "guobi_data_mapping.h"
};
#endif /*#if defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)*/

//define enum according to the db type
typedef enum
{
	IME_HAND_WRITING_LANG_SET_LATIN,
    IME_HAND_WRITING_LANG_SET_CHINESE,
    IME_HAND_WRITING_LANG_SET_EN_NUM,
	IME_HAND_WRITING_LANG_SET_MAX,
}mmi_ime_hand_writing_lang_set_enum;

#define MAX_COMMON_DATA_FILE 2

typedef struct
{
    mmi_ime_hand_writing_lang_set_enum lang_set;
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
    const U8 *pDataFileName[MAX_COMMON_DATA_FILE];
#elif defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
    hand_writing_database_type database[MAX_COMMON_DATA_FILE];
#else
    const unsigned long *pHWDataArray[MAX_COMMON_DATA_FILE];
#endif

}mmi_ime_hand_writing_data_info_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
static const mmi_imm_support_writing_lang_enum g_ime_guobi_hw_lang[] =
{
#if defined(__MMI_GUOBI_HW_TC__) || defined(__MMI_GUOBI_HW_STANDARD__) || \
	defined(__MMI_HANDWRITING_LANG_TC_IN_MEMORY_CARD__) || defined(__MMI_HANDWRITING_LANG_SC_TC_IN_MEMORY_CARD__)
	IME_WRITING_LANG_ZHTW, 
#endif
#if defined(__MMI_GUOBI_HW_SC__) || defined(__MMI_GUOBI_HW_SC_SLIM__) || defined(__MMI_GUOBI_HW_STANDARD__) || \
	defined(__MMI_HANDWRITING_LANG_SC_IN_MEMORY_CARD__) || defined(__MMI_HANDWRITING_LANG_SC_SLIM_IN_MEMORY_CARD__) || defined(__MMI_HANDWRITING_LANG_SC_TC_IN_MEMORY_CARD__)
	IME_WRITING_LANG_ZHCN,
#endif
	IME_WRITING_LANG_ABC,
	IME_WRITING_LANG_123,
#if defined(__MMI_GUOBI_HW_FRENCH__)
	IME_WRITING_LANG_FRCA,
	IME_WRITING_LANG_FR,
#endif
#if defined(__MMI_GUOBI_HW_GERMAN__)
	IME_WRITING_LANG_DE,
#endif
#if defined(__MMI_GUOBI_HW_INDONESIAN__)
	IME_WRITING_LANG_ID,
#endif
#if defined(__MMI_GUOBI_HW_ITALIAN__)
	IME_WRITING_LANG_IT,
#endif
#if defined(__MMI_GUOBI_HW_MALAY__)
	IME_WRITING_LANG_MS,
#endif
#if defined(__MMI_GUOBI_HW_PORTUGESE__)
	IME_WRITING_LANG_PTBZ,
	IME_WRITING_LANG_PT,
#endif
#if defined(__MMI_GUOBI_HW_SPANISH__)
	IME_WRITING_LANG_ESSA,
	IME_WRITING_LANG_ES,
#endif
#if defined(__MMI_GUOBI_HW_TURKISH__)
	IME_WRITING_LANG_TR,
#endif
    IME_WRITING_LANG_NONE
};

#endif //#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

static const mmi_imc_pen_handwriting_type_enum g_ime_guobi_hw_type[] =
{
#if defined(__MMI_GUOBI_HW_TC__) || defined(__MMI_GUOBI_HW_STANDARD__) || \
	defined(__MMI_HANDWRITING_LANG_TC_IN_MEMORY_CARD__) || defined(__MMI_HANDWRITING_LANG_SC_TC_IN_MEMORY_CARD__)
	IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE, 
#endif

#if defined(__MMI_GUOBI_HW_SC__) || defined(__MMI_GUOBI_HW_SC_SLIM__) || defined(__MMI_GUOBI_HW_STANDARD__) || \
	defined(__MMI_HANDWRITING_LANG_SC_IN_MEMORY_CARD__) || defined(__MMI_HANDWRITING_LANG_SC_SLIM_IN_MEMORY_CARD__) || defined(__MMI_HANDWRITING_LANG_SC_TC_IN_MEMORY_CARD__)
	IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE,
#endif

	IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH,
	IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH,
	IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION, 
	IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION,
	IMM_HANDWRITING_TYPE_NUMBER,
	IMM_HANDWRITING_TYPE_PUNCTUATION,

#if defined(__MMI_GUOBI_HW_FRENCH__)
	IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH,
	IMM_HANDWRITING_TYPE_LOWER_CASE_FRENCH,
#endif
#if defined(__MMI_GUOBI_HW_GERMAN__)
	IMM_HANDWRITING_TYPE_UPPER_CASE_GERMAN,
	IMM_HANDWRITING_TYPE_LOWER_CASE_GERMAN,
#endif
#if defined(__MMI_GUOBI_HW_INDONESIAN__)
	IMM_HANDWRITING_TYPE_UPPER_CASE_INDONESIAN,
	IMM_HANDWRITING_TYPE_LOWER_CASE_INDONESIAN,
#endif
#if defined(__MMI_GUOBI_HW_ITALIAN__)
	IMM_HANDWRITING_TYPE_UPPER_CASE_ITALIC,
	IMM_HANDWRITING_TYPE_LOWER_CASE_ITALIC,
#endif
#if defined(__MMI_GUOBI_HW_MALAY__)
	IMM_HANDWRITING_TYPE_UPPER_CASE_MALAY,
	IMM_HANDWRITING_TYPE_LOWER_CASE_MALAY,
#endif
#if defined(__MMI_GUOBI_HW_PORTUGESE__)
	IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE,
	IMM_HANDWRITING_TYPE_LOWER_CASE_PORTUGESE,
#endif
#if defined(__MMI_GUOBI_HW_SPANISH__)
	IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH,
	IMM_HANDWRITING_TYPE_LOWER_CASE_SPANISH,
#endif
#if defined(__MMI_GUOBI_HW_TURKISH__)
	IMM_HANDWRITING_TYPE_UPPER_CASE_TURKEY,
	IMM_HANDWRITING_TYPE_LOWER_CASE_TURKEY,
#endif

	/* last item*/
	IMM_HANDWRITING_TYPE_NONE
};

/***************************************************************************** 
* Local Function
*****************************************************************************/


/***************************************************************************** 
* Global Variable
*****************************************************************************/
static mmi_ime_hand_writing_lang_set_enum g_old_lang_set = IME_HAND_WRITING_LANG_SET_MAX;

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

//T-card data file path
static const U8 g_LatinDataFileName[] = "\\HW\\hw_edit_latin.gbd";
#if defined(__MMI_HANDWRITING_LANG_SC_IN_MEMORY_CARD__)
static const U8 g_DataFileName[] = "\\HW\\hw_edit_sc.gbd";
#elif defined(__MMI_HANDWRITING_LANG_SC_SLIM_IN_MEMORY_CARD__)
static const U8 g_DataFileName[] = "\\HW\\hw_edit_sc_slim.gbd";
#elif defined(__MMI_HANDWRITING_LANG_TC_IN_MEMORY_CARD__)
static const U8 g_DataFileName[] = "\\HW\\hw_edit_tc.gbd";
#elif defined(__MMI_HANDWRITING_LANG_SC_TC_IN_MEMORY_CARD__)
static const U8 g_DataFileName[] = "\\HW\\hw_edit_sc_tc_full.gbd";
#endif

#define HANDWRITING_DATA_BUFF_SIZE_FOR_FILE	(45*1024)

__align(4) static U8 g_HandWriteDataBuff[HANDWRITING_DATA_BUFF_SIZE_FOR_FILE];
static UI_character_type g_DataFilePath[MAX_HANDWRITING_DATA_FILE_PATH];
static FS_HANDLE g_DataFileHandle = -1;
static MMI_BOOL g_is_db_ready = MMI_TRUE;

#else

#ifndef __MMI_GUOBI_HW_CH_ONLY__
extern const unsigned long prv_HWLatinDataArray[];
#endif
extern const unsigned long prv_HWDataArray[];

#endif //#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

static mmi_ime_hand_writing_data_info_struct g_DataInfoTable[] = 
{
    {
		IME_HAND_WRITING_LANG_SET_LATIN,
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
		{g_LatinDataFileName, NULL}
#elif defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
        {HW_DATA_LATIN, HW_DATA_INVALID}
#else
		{
#ifndef __MMI_GUOBI_HW_CH_ONLY__
			prv_HWLatinDataArray,
#else
            NULL,
#endif
			NULL
		}
#endif
	},
    {
        IME_HAND_WRITING_LANG_SET_CHINESE, 
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
		{g_DataFileName, NULL}
#elif defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
        {HW_DATA_CHINESE, HW_DATA_INVALID}
#else
		{prv_HWDataArray, NULL}
#endif
	},
    {
        IME_HAND_WRITING_LANG_SET_EN_NUM,
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
		{g_LatinDataFileName, g_DataFileName}
#elif defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
        {HW_DATA_LATIN, HW_DATA_CHINESE}
#else
		{
			prv_HWDataArray,
#ifndef __MMI_GUOBI_HW_CH_ONLY__
			prv_HWLatinDataArray
#else
            NULL
#endif
		}
#endif
	},
	
    /*last one, add above this*/
    {
        IME_HAND_WRITING_LANG_SET_MAX, 
#if defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
        {HW_DATA_INVALID, HW_DATA_INVALID}
#else
		NULL
#endif
	}
};

/***************************************************************************** 
* Global Function
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_get_data_info
* DESCRIPTION
*  get data info of hw_type
* PARAMETERS
*  hw_type:[IN]	hw type of mmi_imc_pen_handwriting_type_enum
* RETURNS
*  mmi_ime_hand_writing_data_info_struct *
*****************************************************************************/
static mmi_ime_hand_writing_data_info_struct* mmi_ime_hand_writing_get_data_info(mmi_imc_pen_handwriting_type_enum hw_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_ime_hand_writing_data_info_struct *pDataInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (hw_type)
    {
    case IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH:
    case IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH:
    case IMM_HANDWRITING_TYPE_NUMBER:
    case IMM_HANDWRITING_TYPE_PUNCTUATION:
    case IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION:
    case IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION:
		pDataInfo = &g_DataInfoTable[IME_HAND_WRITING_LANG_SET_EN_NUM];
		break;
    case IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE:
	case IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE:
		pDataInfo = &g_DataInfoTable[IME_HAND_WRITING_LANG_SET_CHINESE];
		break;
	default:
		pDataInfo = &g_DataInfoTable[IME_HAND_WRITING_LANG_SET_LATIN];
		break;
	}
	return pDataInfo;

}

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

static S32 mmi_ime_hand_writing_memory_card_data_read(void * ptr,S32 size,S32 nmemb,void * stream,S32 offset,S32 whence);

/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_memory_card_data_init
* DESCRIPTION
*  Initialize memory card data
* PARAMETERS
*  hw_type:[IN]	hw type of mmi_imc_pen_handwriting_type_enum
* RETURNS
*  void
*****************************************************************************/
static void mmi_ime_hand_writing_memory_card_data_init(mmi_imc_pen_handwriting_type_enum hw_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ime_hand_writing_data_info_struct *pDataInfo;
	U32 i;
	U32 fileSize = 65536;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GB_HW_SWLA_START("dif");

	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_MEMORY_CARD_DATA_INIT);

	pDataInfo = mmi_ime_hand_writing_get_data_info(hw_type);
	
    for (i=0; i<MAX_COMMON_DATA_FILE; i++)
    {
        if (!pDataInfo->pDataFileName|| !pDataInfo->pDataFileName[i])
        {
        	break;
        }
		
		kal_wsprintf(g_DataFilePath, 
			"%c%s%s", 
			SRV_FMGR_CARD_DRV, 
			HANDWRITING_DATA_FILE_PATH, 
			pDataInfo->pDataFileName[i]);
		
		if (g_DataFileHandle > 0)
		{
			FS_Close(g_DataFileHandle);
			g_DataFileHandle = -1;
		}

		GB_HW_SWLA_START("dao");
		g_DataFileHandle = FS_Open(g_DataFilePath, FS_READ_ONLY);
		GB_HW_SWLA_STOP("dao");
		FS_GetFileSize(g_DataFileHandle, &fileSize);

		if (fileSize == 0 || g_DataFileHandle < FS_NO_ERROR)
        {
			continue;
        }
		else
        {
			enum GB_HW_Fail errorId;

			GB_HW_SWLA_START("hws");
			GBHWSetRequireRam(g_HandWriteDataBuff, HANDWRITING_DATA_BUFF_SIZE_FOR_FILE);
			GBHWSetDataSource(&g_DataFileHandle);
			GBHWSetFread((pfGBHWFreadT)mmi_ime_hand_writing_memory_card_data_read);
			GB_HW_SWLA_STOP("hws");
			GB_HW_SWLA_START("hwn");
			errorId = (enum GB_HW_Fail)GBHWNewFile((const void *)&g_DataFileHandle, 0);
			GB_HW_SWLA_STOP("hwn");
			g_is_db_ready = (errorId < 0)?MMI_FALSE:MMI_TRUE;
			if (!g_is_db_ready)
			{
			    continue;
			}
			else
			{
				errorId = (enum GB_HW_Fail)GBHWSetOption(GBHW_Index_Set_Speed, 5);
				break;
			}
        }

    }
    if (fileSize == 0 || g_DataFileHandle < FS_NO_ERROR || i == MAX_COMMON_DATA_FILE)
    {
		MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_MEMORY_CARD_DATA_INIT_OPEN_ERROR_ID, g_DataFileHandle);
		g_is_db_ready = MMI_FALSE;
    }
	GB_HW_SWLA_STOP("dif");
}

/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_memory_card_data_read
* DESCRIPTION
*  read memory card data
*  typedef int (*pfGBHWFreadT)(void * ptr,int size,int nmemb,void * stream,int offset,int whence);
* PARAMETERS
*  ptr	   :[IN]	Buffer address
*  size	   :[IN]	buffer size of per block
*  nmemb   :[IN]	buffer block count
*  stream	   :[IN]	file handle of file to move the file pointer
*  offset	   :[IN]	bytes to move pointer
*  whence  :[IN]	starting point, GB_STREAM_FLAG
* RETURNS
*  The real read bytes of the file
*****************************************************************************/
static S32 mmi_ime_hand_writing_memory_card_data_read(void * ptr, S32 size, S32 nmemb, void * stream, S32 offset, S32 whence)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 realReadBytes = 0, readBytes = 0;
	S32 ret = FS_NO_ERROR;
	S32 fs_whence;
	U32 time1, time2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GB_HW_SWLA_START("drf");

	MMI_ASSERT(ptr);
	MMI_ASSERT(stream);

	if (*(FS_HANDLE *)stream < 0)
	{
		return 0;
	}

	switch(whence)
	{
	case GB_SEEK_SET:
		fs_whence = FS_FILE_BEGIN;
		break;
	case GB_SEEK_CUR:
		fs_whence = FS_FILE_CURRENT;
		break;
	case GB_SEEK_END:
		fs_whence = FS_FILE_END;
		break;
	default:
		fs_whence = FS_FILE_BEGIN;
		break;
	}
    GB_HW_SWLA_START("das");
	ret = FS_Seek(*(FS_HANDLE *)stream, offset, fs_whence);
	GB_HW_SWLA_STOP("das");
	if (ret < FS_NO_ERROR)
	{
		MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_MEMORY_CARD_DATA_READ_SEEK_ERROR_ID, ret);
		return 0;
	}

	readBytes = (U32)nmemb * size;

	kal_get_time(&time1);
	GB_HW_SWLA_START("dar");
	ret = FS_Read(*(FS_HANDLE *)stream, ptr, readBytes, &realReadBytes);
	GB_HW_SWLA_STOP("dar");
	kal_get_time(&time2);
	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_MEMORY_CARD_DATA_READ, readBytes, kal_ticks_to_milli_secs(time2 - time1));

	if (ret < FS_NO_ERROR )
	{
		MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_MEMORY_CARD_DATA_READ_READ_ERROR_ID, ret);
		return 0;
	}

	GB_HW_SWLA_STOP("drf");

	return (S32)realReadBytes;

}

/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_memory_card_is_lang_support
* DESCRIPTION
*  To query if the hw_lang is supported by hw vendor
* PARAMETERS
*  hw_lang   :[IN]	lang enum
* RETURNS
*  if support, return  MMI_TRUE, otherwise, return MMI_FALSE
*****************************************************************************/
MMI_BOOL mmi_ime_hand_writing_memory_card_is_lang_support(mmi_imm_support_writing_lang_enum hw_lang)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 i = -1;
	mmi_imm_support_writing_lang_enum lang = IME_WRITING_LANG_NONE;
	MMI_BOOL ret = MMI_FALSE;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	
	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_MEMORY_CARD_IS_LANG_SUPPORT);
	
	if (IME_WRITING_LANG_NONE == hw_lang)
	{
		return MMI_FALSE;
	}

	do
	{
		i++;
		lang = g_ime_guobi_hw_lang[i];
		if (lang == hw_lang)
		{
			ret = MMI_TRUE;
			break;
		}

	} while (lang != IME_WRITING_LANG_NONE);

	return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_memory_card_get_lang_by_index
* DESCRIPTION
*  To get a lang which is supported by hw vendor
* PARAMETERS
*  index   :[IN] index of g_ime_guobi_hw_lang
* RETURNS
*  mmi_imm_support_writing_lang_enum
*****************************************************************************/
mmi_imm_support_writing_lang_enum mmi_ime_hand_writing_memory_card_get_lang_by_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_MEMORY_CARD_GET_LANG_BY_INDEX, index);
    MMI_ASSERT(index < sizeof(g_ime_guobi_hw_lang));

	return g_ime_guobi_hw_lang[index];
}

/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_memory_card_is_db_ready
* DESCRIPTION
*  query if db ready(exist and correct)
* PARAMETERS
*  void
* RETURNS
*  if ready, return  MMI_TRUE, otherwise, return MMI_FALSE
*****************************************************************************/
MMI_BOOL mmi_ime_hand_writing_memory_card_is_db_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_MEMORY_CARD_IS_DB_READY_STATE, g_is_db_ready);

    return g_is_db_ready;
}


#endif //#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)


#if defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)

/*****************************************************************************
* FUNCTION
 *  mmi_ime_hand_writing_third_rom_get_data_size
* DESCRIPTION
 *  return relate data size (byte)
* PARAMETERS
 *  database_type  : [IN] internal database id
* RETURNS
 *  S32 : database size
*****************************************************************************/
static S32 mmi_ime_hand_writing_third_rom_get_data_size(hand_writing_database_type database_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(database_type < HW_DATA_END);
    return g_database_mapping[database_type].size;
}


/*****************************************************************************
* FUNCTION
 *  mmi_ime_hand_writing_third_rom_get_data_id
* DESCRIPTION
 *  return database ID which used for acess third rom
* PARAMETERS
 *  database_type : [IN] internal database id
* RETURNS
 *  U8 : database ID which used for acess third rom
*****************************************************************************/
static U8 mmi_ime_hand_writing_third_rom_get_data_id(hand_writing_database_type database_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(database_type < HW_DATA_END);
    return g_database_mapping[database_type].cid;
}


/*****************************************************************************
* FUNCTION
 *  mmi_ime_hand_writing_third_rom_read_data_int
* DESCRIPTION
 *  load data from 3rd rom
* PARAMETERS
 *  output : [OUT] output buffer
 *  database_type :[IN] internal database ID
 * offset :[IN] start position of data
 * size : [IN] size of data which need to fill
* RETURNS
 *  MMI_BOOL  :  load data sucess or not
*****************************************************************************/
static MMI_BOOL mmi_ime_hand_writing_third_rom_read_data_int(void * output, hand_writing_database_type database_type, S32 offset, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cid;
    S32 pre_database_size = 0;
    hand_writing_database_type i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(output != NULL);
    MMI_ASSERT(database_type < HW_DATA_END);
    GB_HW_SWLA_START("rdi");
    cid = mmi_ime_hand_writing_third_rom_get_data_id(database_type);
    /*because we have only one binary, so we need to mapping the offset, bellowing is example
       --------------------------   --
       -                                            -        |
       -latin                                     -        |
       ------------------------        |
       -                                            -   binary in third rom
       -                                            -        |
       -sc_slim                                 -        |
       --------------------------   --
      */
    for (i = HW_DATA_START; i < database_type; i++)
    {
        pre_database_size += mmi_ime_hand_writing_third_rom_get_data_size(i);
    }

    if (MMI_RESOURCE_NFB_RES_Load((kal_uint8) cid, output, offset + pre_database_size, size))
    {
        GB_HW_SWLA_STOP("rdi");
        return MMI_TRUE;
    }
    else
    {
        GB_HW_SWLA_STOP("rdi");
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
 *  mmi_ime_hand_writing_third_rom_read_data
* DESCRIPTION
 *  load data to buffer.
* PARAMETERS
*  ptr	   :[IN]	Buffer address
*  size	   :[IN]	buffer size of per block
*  nmemb   :[IN]	buffer block count
*  Address	   :[IN]	data info
*  offset	   :[IN]	bytes to move pointer
*  whence  :[IN]	starting point, GB_STREAM_FLAG
* RETURNS
*  The real read bytes of the file
*****************************************************************************/
static S32 mmi_ime_hand_writing_third_rom_read_data(void * ptr, S32 size, S32 nmemb, void * Address, S32 offset, S32 whence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data_offset_info* data_info;
    S32 data_start_address;
    S32 data_final_address;
    S32 database_size;
    S32 data_size = size*nmemb;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ptr);
    MMI_ASSERT(Address);
    GB_HW_SWLA_START("rdf");
    data_info = (data_offset_info *)Address;

    database_size= mmi_ime_hand_writing_third_rom_get_data_size(data_info->database_type);

    switch(whence)
    {
        case GB_SEEK_SET:
        {
            data_start_address = offset;
            break;
        }
        case GB_SEEK_CUR:
        {
            data_start_address = (data_info->current_address + offset);
            break;
        }
        case GB_SEEK_END:
        {
            data_start_address = (database_size - 1 - offset);
            break;
        }
        default:
        {
            data_start_address = offset;
            break;
        }
    }
    
    MMI_ASSERT(data_start_address >= 0);
    data_final_address = data_start_address + data_size;
    if (data_final_address > database_size)
    {
        data_size = data_final_address - database_size;
        nmemb = data_size / size;
        data_final_address = database_size;
    }

    if (mmi_ime_hand_writing_third_rom_read_data_int(ptr, data_info->database_type, data_start_address, data_size))
    {
        data_info->current_address = data_final_address;
        GB_HW_SWLA_STOP("rdf");
        return nmemb;
    }
    else
    {
        GB_HW_SWLA_STOP("rdf");
        return 0;
    }
}



/*****************************************************************************
* FUNCTION
 *  mmi_ime_hand_writing_third_rom_init
* DESCRIPTION
 *  Initialize handwriting module
* PARAMETERS
*  database_type:[IN]	database id
* RETURNS
*  void
*****************************************************************************/
static void mmi_ime_hand_writing_third_rom_init(hand_writing_database_type database_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    enum GB_HW_Fail errorId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_gb_hand_writing_data_info.start_address = 0;
	g_gb_hand_writing_data_info.current_address = 0;
    g_gb_hand_writing_data_info.database_type = database_type;
	GBHWSetRequireRam(g_HandWriteDataBuff, HANDWRITING_DATA_BUFF_SIZE_FOR_FILE);
	GBHWSetDataSource(&g_gb_hand_writing_data_info);
	GBHWSetFread((pfGBHWFreadT)mmi_ime_hand_writing_third_rom_read_data);
    GB_HW_SWLA_START("hwn");
	ret = GBHWNewFile((const void *) (&g_gb_hand_writing_data_info), 0);
    GB_HW_SWLA_STOP("hwn");
    if (ret != 0)
	{  
		//HW engine INIT failed
		MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_INITIALIZE_FAIL, ret);
	}
    errorId = (enum GB_HW_Fail)GBHWSetOption(GBHW_Index_Set_Speed, 15);
}

#endif //#if defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)


/*****************************************************************************
* FUNCTION
 *  mmi_ime_hand_writing_initialize
* DESCRIPTION
 *  Initialize handwriting module
* PARAMETERS
 *  void
* RETURNS
 *  void
*****************************************************************************/
void mmi_ime_hand_writing_initialize(mmi_imc_pen_handwriting_type_enum hw_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__) && !defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
	S32 ret = 0;
#endif
	mmi_ime_hand_writing_data_info_struct *pDataInfo;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GB_HW_SWLA_START("inf");

    //for performance: cancel initialization if lang in the same set
	pDataInfo = mmi_ime_hand_writing_get_data_info(hw_type);
	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_INITIALIZE, g_old_lang_set, pDataInfo->lang_set);
	if(g_old_lang_set == pDataInfo->lang_set)
	{
	    return;
	}
	
	g_old_lang_set = pDataInfo->lang_set;
	
#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
	if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
	{
		mmi_ime_hand_writing_memory_card_data_init(hw_type);
	}
#elif defined(__MMI_HANDWRITING_THIRD_ROM_SUPPORT__)
    mmi_ime_hand_writing_third_rom_init(pDataInfo->database[0]);
#else

	GB_HW_SWLA_START("hwn");
	MMI_ASSERT(pDataInfo->pHWDataArray[0]);
	ret = GBHWNew(pDataInfo->pHWDataArray[0], 0);//data in ROM, we don't need to care about data missing
	GB_HW_SWLA_STOP("hwn");

	if (ret != 0)
	{  
		//HW engine INIT failed
		MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_INITIALIZE_FAIL, ret);
	}
#endif //#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)

    GB_HW_SWLA_STOP("inf");
}


/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_deinitialize
* DESCRIPTION
*  deinitialize handwriting module
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_ime_hand_writing_deinitialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_DEINITIALIZE);

#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
	if (g_DataFileHandle >= FS_NO_ERROR)
	{
		FS_Close(g_DataFileHandle);
		g_DataFileHandle = -1;
		
	}
#endif //#if defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT__)
	g_old_lang_set = IME_HAND_WRITING_LANG_SET_MAX;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_hand_writing_hw_type_query
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *  The query if the h_w_type is supported by the vendor
 *****************************************************************************/
MMI_BOOL mmi_ime_hand_writing_hw_type_query(mmi_imc_pen_handwriting_type_enum h_w_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = -1;
    mmi_imc_pen_handwriting_type_enum type = IMM_HANDWRITING_TYPE_NONE;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IMM_HANDWRITING_TYPE_NONE == h_w_type)
    {
        return MMI_FALSE;
    }
	
    do
    {
        i++;
        type = g_ime_guobi_hw_type[i];
        if (type == h_w_type)
        {
            ret = MMI_TRUE;
            break;
        }
        
    } while (type != IMM_HANDWRITING_TYPE_NONE);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_add_separator_to_candidate_buffer
* DESCRIPTION
*  add seperate for candidates list
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
void  mmi_ime_hand_writing_add_separator_to_candidate_buffer(UI_character_type * destination_buffer, UI_character_type * source_buffer, S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < num && source_buffer[i] != 0)
    {
        destination_buffer[j] = source_buffer[i];
        destination_buffer[j + 1] = 0; /* Default separator is '\0' */
        i++;
        j += 2;
    }

    destination_buffer[j] = 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_ime_hand_writing_get_candidates
* DESCRIPTION
*  Get the candidates from the handwriting strokes
* PARAMETERS
* RETURNS
*  The number of the candidates
*****************************************************************************/
S32 mmi_ime_hand_writing_get_candidates(
        mmi_ime_hand_writing_query_param_p query_param,
        mmi_ime_hand_writing_result_param_p result_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_imc_pen_handwriting_type_enum h_w_type = query_param->h_w_type;
	S32 num = 0;
	unsigned long recognizerange;
	mmi_ime_hand_writing_data_info_struct *pDataInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GB_HW_SWLA_START("gcf");

    pDataInfo = mmi_ime_hand_writing_get_data_info(h_w_type);

    MMI_TRACE(MMI_FW_TRC_G5_IME, TRC_MMI_IME_HAND_WRITING_GET_CANDIDATES, g_old_lang_set, pDataInfo->lang_set);

	if (g_old_lang_set != pDataInfo->lang_set)
	{
		mmi_ime_hand_writing_initialize(h_w_type);
	}
    switch(h_w_type)
	{
		case IMM_HANDWRITING_TYPE_SIMPLIFIED_CHINESE:
			recognizerange = GBHW_OPT_RANGE_GB2312;
			break;
		case IMM_HANDWRITING_TYPE_TRADITIONAL_CHINESE:
			recognizerange = GBHW_OPT_RANGE_BIG5;
			break;
		case IMM_HANDWRITING_TYPE_LOWER_CASE_ENGLISH:
		case IMM_HANDWRITING_TYPE_UPPER_CASE_ENGLISH:
			recognizerange = GBHW_OPT_RANGE_A_LANGUAGES | GBHW_OPT_RANGE_LOWER_CHAR | GBHW_OPT_RANGE_UPPER_CHAR;
			break;
		case IMM_HANDWRITING_TYPE_UPPER_CASE_INDONESIAN:
		case IMM_HANDWRITING_TYPE_LOWER_CASE_INDONESIAN:
		case IMM_HANDWRITING_TYPE_UPPER_CASE_MALAY:
		case IMM_HANDWRITING_TYPE_LOWER_CASE_MALAY:
			recognizerange = GBHW_OPT_RANGE_A_LANGUAGES;
			break;
		case IMM_HANDWRITING_TYPE_NUMBER:
			recognizerange = GBHW_OPT_RANGE_LATIN_NUMBER | GBHW_OPT_RANGE_NUMBER;
			break;
		case IMM_HANDWRITING_TYPE_PUNCTUATION:		
			recognizerange = GBHW_OPT_RANGE_LATIN_ASC_PUNCTUATION | GBHW_OPT_RANGE_ASC_PUNCTUATION;
			break;
		case IMM_HANDWRITING_TYPE_NUM_AND_PUNCTUATION:
			recognizerange = (GBHW_OPT_RANGE_LATIN_ASC_PUNCTUATION | GBHW_OPT_RANGE_LATIN_NUMBER) | (GBHW_OPT_RANGE_NUMBER | GBHW_OPT_RANGE_ASC_PUNCTUATION);
			break;
		case IMM_HANDWRITING_TYPE_ENGLISH_NUM_PUNCTUATION:
			recognizerange = (GBHW_LATIN_RANGE_NUMBER | GBHW_LATIN_RANGE_EN_LOWER | GBHW_LATIN_RANGE_EN_UPPER | GBHW_LATIN_RANGE_ASC_PUNCTUATION) | GBHW_OPT_RANGE_ASCII;
			break;
		case IMM_HANDWRITING_TYPE_UPPER_CASE_PORTUGESE:
		case IMM_HANDWRITING_TYPE_LOWER_CASE_PORTUGESE:
			recognizerange = GBHW_OPT_RANGE_B_LANGUAGES;
			break;
		case IMM_HANDWRITING_TYPE_UPPER_CASE_FRENCH:
		case IMM_HANDWRITING_TYPE_LOWER_CASE_FRENCH:
			recognizerange = GBHW_OPT_RANGE_E_LANGUAGES;
			break;
		case IMM_HANDWRITING_TYPE_UPPER_CASE_GERMAN:
		case IMM_HANDWRITING_TYPE_LOWER_CASE_GERMAN:
		case IMM_HANDWRITING_TYPE_UPPER_CASE_ITALIC:
		case IMM_HANDWRITING_TYPE_LOWER_CASE_ITALIC:
		case IMM_HANDWRITING_TYPE_UPPER_CASE_SPANISH:
		case IMM_HANDWRITING_TYPE_LOWER_CASE_SPANISH:
		case IMM_HANDWRITING_TYPE_UPPER_CASE_TURKEY:
		case IMM_HANDWRITING_TYPE_LOWER_CASE_TURKEY:
			recognizerange = GBHW_OPT_RANGE_G_LANGUAGES;
			break;
		default:
			recognizerange = GBHW_OPT_RANGE_LATIN_NUMBER;
			break;

	}

	GB_HW_SWLA_START("hwr");
	num = GBHWRecognize((short*)(query_param->stroke_buffer), 
		result_param->candidate_array ,
		query_param->desired_cnt,
		recognizerange);
	GB_HW_SWLA_STOP("hwr");

	result_param->result_cnt = num;

	GB_HW_SWLA_STOP("gcf");

	return num;
    

}


#endif /* defined(__MMI_GUOBI_HW__) && defined(__MMI_TOUCH_SCREEN__) */
