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
 *  Appicon.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef APPICON_H_
#define APPICON_H_
/*************************************************************
 *  Header File Dependance Check
 *************************************************************/
#include "MMI_features.h"
#include "mmi_phnset_dispchar.h"
#include "Menucuigprot.h"
#include "Filemgrsrvgprot.h"

/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "PhoneSetupResList.h"
//#include "AppiconDefs.h"
#include "kal_non_specific_general_types.h"
#include "CustVenusThemeRes.h"
#include "AppListGprot.h"
/* auto add by kw_check end */
/*************************************************************
 *  Defination
 *************************************************************/
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__ 
typedef enum
 {
    FOLDER_PHONE,
    FOLDER_CARD,
    FOLDER_TOTAL
 }Appicons_folder;  
typedef struct
 {
    U32 handle;
	U32 index;
  }FileItem;

#define FOLDER_NAME ":\\AppIcon"   //appicon folder name
#define SETTING_PATH_NAME "Z:\\@Settings"
#define APPICON_CACHE_PATH "Z:\\@Settings\\IconCache.aco"
#define APPICON_TEMP_CACHE_PATH "Z:\\@Settings\\IconCacheB.aco"

//
//	Solution depdency buffer size definiation
//
#define MMI_APPICON_PREVIEW_CACHE_BUFFER_SIZE (70 * 1024)
#define MMI_APPICON_BASE_SIZE (100 * 1024)

#if 0
#ifdef __MMI_MAINLCD_480X800__ /* WVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined  __MMI_MAINLCD_320X480__ /* HVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined	__MMI_MAINLCD_240X320__ /* QVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined	__MMI_MAINLCD_320X240__ /* LQVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined	__MMI_MAINLCD_240X400__ /* WQVGA */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else // Invalid value
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#define JOB_FLAG(_folder) (1 << (_folder))

typedef  S32 (*cmpFuncPtr)(const FileItem *, const FileItem *);

#endif/*__MMI_DOWNLOADABLE_APPICON_SUPPORT__*/
#define INVALID_HANDLE (-1)
typedef struct 
{
    mmi_res_theme_handle handle;
    //MMI_BOOL isCorrectSet;
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__     
    MMI_BOOL isneedcomfirm;
    MMI_BOOL isdlActive;
    MMI_BOOL resethighlightindex;
	MMI_BOOL isformFmgr;
    U8   m_waitingJob;
    CHAR m_drvList[FOLDER_TOTAL];
    U32 m_lstHandle[FOLDER_TOTAL];
    U32 m_lstFileCnt[FOLDER_TOTAL];
    U32 m_adjustCnt;
    S8 m_workingBuffer[SRV_FMGR_FOLDER_FILELIST_MEM_SIZE * FOLDER_TOTAL];
    U16 m_nameBuffer[SRV_FMGR_PATH_BUFFER_SIZE];
    void* mem_ptr;
    KAL_ADM_ID adm_pool_id;
    FileItem *m_fileItems;
    FileItem m_activeFileItem;
#endif    
    S8* image_buffer;
    S8  hightlightindex;
}mmi_phnset_appicon_cntx_struct;

#endif /* APPICON_H_ */ 

