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
 *  PopulateDevAppRes.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Populate Resource Engine
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define _POPULATE_RES_C

 /****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#include "GlobalMenuItems.h"
#include "custdatares.h"
#include "CustDataProts.h"
#include "custmenures.h"
#include "FontDCL.h"
#include "Globaldefs.h"
#include "CustResDef.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define  OUTPUT_IMAGE_ID_FILENAME      "..\\DevResource\\Images\\images_file_list.ini"
#define  OUTPUT_AUDIO_ID_FILENAME      "..\\DevResource\\Audio\\audio_file_list.ini"
#define  OUTPUT_MENUTREE_ID_FILENAME   "..\\DevResource\\Resources\\CustMenuTreeID_Out.c"

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* for generate String list file in first pass */
FILE *StringListFile = NULL;
FILE *EnumListFile = NULL;
FILE *OutputImgIDFile = NULL;
FILE *OutputAdoIDFile = NULL;
FILE *OutputMenutreeIDFile = NULL;
FILE *RepeatIDListFile = NULL;

U16 DevApp_CurrMaxStringNum;
U16 DevApp_CurrMaxStringId;
U16 DevApp_CurrMaxStringIdSearch;

/***************************************************************************** 
* Local Function
*****************************************************************************/
void PopulateGlobalData(void);

/****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/
extern U16 CurrMaxImageId;
extern U16 CurrMaxImageNum;
extern U16 CurrMaxImageIdEXT;   /* 040805 CustPack: Calvin added */
extern U16 CurrMaxImageNumEXT;  /* 040805 CustPack: Calvin added */

extern U16 CurrMaxAudioId;
extern U16 CurrMaxAudioNum;
extern U16 CurrMaxAudioIdEXT;
extern U16 CurrMaxAudioNumEXT;

extern U16 CurrMaxMenuItemIndex;    /* Max menu IDs */
extern U16 CurrMaxStringId;

extern const CUSTOM_IMAGE_MAP ImageIdMap[];
extern const CUSTOM_IMAGE_MAP ImageIdMapEXT[];
extern const CUSTOM_AUDIO_MAP AudioIdMap[];
extern const CUSTOM_AUDIO_MAP AudioIdMapEXT[];
extern const CUSTOM_MENU nCustMenus[];

const CUSTOM_STRING *gpStringRes;
const CUSTOM_STRING_MAP *gpStringMapRes;
const CUSTOM_STRMAP_SEARCH *gpStrMapSearch;
extern StringResList *gStringList;

extern int toolFlag;
extern U16 gCurrLangIndex;

/****************************************************************************
* Global Function - Extern                                                                 
*****************************************************************************/
extern void PopulateDevApp1Res(void);

#ifdef __FLAVOR_VENDOR_SDK__
extern void PopulateAvk1Res(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  ToolPopulateInitial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ToolPopulateInitial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j;
    unsigned char a[4];
    char cmd[512];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHWIMageFile();
    CurrMaxImageId = 0;
    CurrMaxImageNum = 0;
    CurrMaxImageIdEXT = 0;  /* 040805 CustPack: Calvin added */
    CurrMaxImageNumEXT = 0;

    CurrMaxAudioId = 0;
    CurrMaxAudioNum = 0;
    CurrMaxAudioIdEXT = 0;
    CurrMaxAudioNumEXT = 0;

    CurrMaxMenuItemIndex = MAX_MENU_ITEMS;

    /* to read from NVRAM if possible -vanita */
    gCurrLangIndex = 0;

    memset(nCustMenus, 0, sizeof(CUSTOM_MENU) * MAX_MENU_ITEMS);

    for (i = 0; i < MAX_IMAGE_IDS_SIZE; i++)
    {
        ImageIdMap[i].nImageNum = -1;
        ImageIdMapEXT[i].nImageNum = -1;    /* 040805 CustPack: Calvin added */
    }

    for (i = 0; i < MAX_AUDIO_IDS_SIZE; i++)
    {
        AudioIdMap[i].nAudioNum = -1;
        AudioIdMapEXT[i].nAudioNum = -1;
    }
}

/* 101205 audio resource Calvin End */


/*****************************************************************************
 * FUNCTION
 *  ToolPopulateDone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ToolPopulateDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  for generate string list file in first pass */
    fwprintf(StringListFile, L"##number\t%d\r\n", CurrMaxStringId);
    fclose(StringListFile);
    fprintf(EnumListFile, "};\n");
    fclose(EnumListFile);

    /* 091004 MTK Calvin added to reduce populate time */
    fclose(OutputImgIDFile);
    fclose(OutputMenutreeIDFile);
    fclose(RepeatIDListFile);   /* 102604 MTK Calvin added */
    /* MTK Calvin end */
}

/* __CUSTPACK_MULTIBIN Calvin End */


/*****************************************************************************
 * FUNCTION
 *  PopulateCustResData
 * DESCRIPTION
 *  Populate Resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateCustResData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j;
    unsigned char a[4];
    char path[] = CUST_IMG_PATH;
    char cmd[512];
    FILE *OutputImgDataFile = NULL;
    FILE *nfb_img_res_file = NULL;
    FILE *nfb_img_data_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StringListFile = fopen(CUS_STR_RES_FILENAME, "wb");
    if (StringListFile == NULL)
    {
        printf("StringListFile (%s) could not open!\n", CUS_STR_RES_FILENAME);
        exit(0);
    }
    EnumListFile = fopen("enum_list.h", "w");
    if (EnumListFile == NULL)
    {
        printf("EnumListFile (enum_list.h) could not open!\n");
        exit(0);
    }
    fclose(EnumListFile);
    EnumListFile = fopen("enum_list.h", "a");
    if (EnumListFile == NULL)
    {
        printf("EnumListFile (enum_list.h) could not open with again!\n");
    }

    OutputImgIDFile = fopen(OUTPUT_IMAGE_ID_FILENAME, "w");
    if (OutputImgIDFile == NULL)
    {
        printf("OutputImgIDFile (%s) could not open!\n", OUTPUT_IMAGE_ID_FILENAME);
        exit(0);
    }
    fclose(OutputImgIDFile);
    OutputImgIDFile = fopen(OUTPUT_IMAGE_ID_FILENAME, "a");
    if (OutputImgIDFile == NULL)
    {
        printf("OutputImgIDFile (0) could not open again!\n", OUTPUT_IMAGE_ID_FILENAME);
        exit(0);
    }
    fprintf(OutputImgIDFile, "[Image File List]\n");

    OutputMenutreeIDFile = fopen(OUTPUT_MENUTREE_ID_FILENAME, "w");
    if (OutputMenutreeIDFile == NULL)
    {
        printf("OutputMenutreeIDFile (%s) could not open!\n", OUTPUT_MENUTREE_ID_FILENAME);
        exit(0);
    }
    fclose(OutputMenutreeIDFile);
    OutputMenutreeIDFile = fopen(OUTPUT_MENUTREE_ID_FILENAME, "a");
    if (OutputMenutreeIDFile == NULL)
    {
        printf("OutputMenutreeIDFile (%s) could not open again!\n", OUTPUT_MENUTREE_ID_FILENAME);
        exit(0);
    }

    OutputAdoIDFile = fopen(OUTPUT_AUDIO_ID_FILENAME, "w");
    if (OutputAdoIDFile == NULL)
    {
        printf("OutputAdoIDFile (%s) could not open!\n", OUTPUT_AUDIO_ID_FILENAME);
        exit(0);
    }
    fclose(OutputAdoIDFile);
    OutputAdoIDFile = fopen(OUTPUT_AUDIO_ID_FILENAME, "a");
    if (OutputAdoIDFile == NULL)
    {
        printf("OutputAdoIDFile (%s ) could not open again!\n", OUTPUT_AUDIO_ID_FILENAME);
        exit(0);
    }
    fprintf(OutputAdoIDFile, "[Audio File List]\n");

    RepeatIDListFile = fopen("repeat_id_list", "w");
    if (RepeatIDListFile == NULL)
    {
        printf("RepeatIDListFile (repeat_id_list) could not open!\n");
        exit(0);
    }
    fclose(RepeatIDListFile);
    RepeatIDListFile = fopen("repeat_id_list", "a");
    if (RepeatIDListFile == NULL)
    {
        printf("RepeatIDListFile (repeat_id_list) could not open again!\n");
        exit(0);
    }
    fprintf(RepeatIDListFile, "StrId\tEnum_Value\t\tString or Image\n");

    a[0] = 0xFF;
    a[1] = 0xFE;
    a[2] = 0x4E;
    a[3] = 0x00;

    fprintf(StringListFile, a);
    fprintf(StringListFile, "%c", a[3]);
    fwprintf(StringListFile, L"Number Of Languages\t1\r\n");
    fwprintf(StringListFile, L"Enum Value\tID\tDescription\tEnglish\r\n");
    fprintf(EnumListFile, "const int ENUM_VALUE_MAP[]={\n");

    ClearHWIMageFile();

    CurrMaxImageId = 0;
    CurrMaxImageNum = 0;
    CurrMaxImageIdEXT = 0;
    CurrMaxImageNumEXT = 0;

    CurrMaxAudioId = 0;
    CurrMaxAudioNum = 0;
    CurrMaxAudioIdEXT = 0;
    CurrMaxAudioNumEXT = 0;

    CurrMaxMenuItemIndex = MAX_MENU_ITEMS;

    gCurrLangIndex = 0;

    memset(nCustMenus, 0, sizeof(CUSTOM_MENU) * MAX_MENU_ITEMS);

   /*****************************************************************************
   * Add applcation
   *****************************************************************************/

    for (i = 0; i < MAX_IMAGE_IDS_SIZE; i++)
    {
        ImageIdMap[i].nImageNum = -1;
        ImageIdMapEXT[i].nImageNum = -1;
    }

    for (i = 0; i < MAX_AUDIO_IDS_SIZE; i++)
    {
        AudioIdMap[i].nAudioNum = -1;
        AudioIdMapEXT[i].nAudioNum = -1;
    }

   /*****************************************************************************
   * Populate Resoruce
   *****************************************************************************/
    PopulateDevApp1Res();
#ifdef __FLAVOR_VENDOR_SDK__
  //  PopulateAvk1Res();
#endif
    mmi_rp_populate_resources();
    /*  for generate string list file in first pass */

    fwprintf(StringListFile, L"##number\t%d\r\n", CurrMaxStringId);
    fclose(StringListFile);
    fprintf(EnumListFile, "};\n");
    fclose(EnumListFile);

    fclose(OutputImgIDFile);

    fclose(OutputAdoIDFile);

    fclose(OutputMenutreeIDFile);
    fclose(RepeatIDListFile);

}

