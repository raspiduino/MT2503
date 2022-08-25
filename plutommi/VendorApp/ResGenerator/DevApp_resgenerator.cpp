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
 * mtk_resgenerator.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   To Generator Resource C files.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "CustResDef.h"

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#define LPVOID    void*
#define UINT16    U16
#define UINT32 U32

extern "C" CUSTOM_IMAGE_MAP ImageIdMap[];
extern "C" CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMap[];
extern "C" IMAGENAME_LIST ImageNameList[];

extern "C" CUSTOM_AUDIO_MAP AudioIdMap[];
extern "C" CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMap[];
extern "C" AUDIONAME_LIST AudioNameList[];

extern "C" CUSTOM_MENU nCustMenus[];
extern "C" unsigned short CurrMaxMenuItemIndex; /* Max menu Ids */

extern "C" unsigned short CurrMaxImageId;       /* Max String Ids */
extern "C" unsigned short CurrMaxSearchImageId; /* Max String Ids */
extern "C" unsigned short CurrMaxImageNum;      /* Max Number Ids */
extern "C" image_type_enum ExtImageFlag;        /* 101205 audio resource Calvin */

extern "C" unsigned short CurrMaxAudioId;       /* Max String Ids */
extern "C" unsigned short CurrMaxSearchAudioId; /* Max String Ids */
extern "C" unsigned short CurrMaxAudioNum;      /* Max Number Ids */
extern "C" BOOL ExtAudioFlag;

extern "C" FILE *dest_file;
extern "C" int toolFlag;
extern "C" int resultFailFlag;

/* Extern functions */
extern "C" void PopulateCustResData(void);
extern "C" void Extract_Name(S8 *dest, S8 *src, U32 res_type);
extern "C" void InitStrPopulate();

U16 gCurrLangIndex = 0;


/*****************************************************************************
 * FUNCTION
 *  UnzipImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UnzipImage()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempCommand[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(tempCommand, "rd /S/Q %s\\mainlcd\\", CUST_IMG_PATH);
    system(tempCommand);

    sprintf(tempCommand, "rd /S/Q %s\\sublcd\\", CUST_IMG_PATH);
    system(tempCommand);

    sprintf(tempCommand, "\"7za.exe x %s\\image.zip -o%s\\", CUST_IMG_PATH, CUST_IMG_PATH);
    system(tempCommand);
}


/*****************************************************************************
 * FUNCTION
 *  Trace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void DevAppResgenTrace(char *fmt,...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list MyList;
    char nPrintableStr[1000];   //Assumed..this can chane if need to dump more bytes

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    va_start(MyList,fmt);
    vsprintf(nPrintableStr,fmt,MyList);
    va_end(MyList);
    printf(nPrintableStr);
    fflush(stdout);
}


/*****************************************************************************
 * FUNCTION
 *  PopulateImageSearch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateImageSearch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 j = 0;
    U16 index = 0;
    U16 start = 0;
    CUSTOM_IMAGE_MAP *pImageIdMap;
    CUSTOM_IMAGE_SEARCH_MAP *pImageIdSearchMap;
    unsigned short *pCurrMaxSearchImageId;
    unsigned short *pCurrMaxImageId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pImageIdMap = ImageIdMap;
    pImageIdSearchMap = ImageIdSearchMap;
    pCurrMaxSearchImageId = &CurrMaxSearchImageId;
    pCurrMaxImageId = &CurrMaxImageId;

    for (i = 0; i < MAX_IMAGE_IDS_SIZE; i++)
    {
        if (pImageIdMap[i].nImageNum != (U16) - 1)
        {
            if (!start)
            {
                pImageIdSearchMap[j].minImageId = pImageIdSearchMap[j].maxImageId = i;
                pImageIdSearchMap[j].index = index;
                index++;
                start = 1;
            }
            else
            {
                pImageIdSearchMap[j].maxImageId = i;
                index++;
            }
        }
        else
        {
            if (start)
            {
                j++;
                start = 0;
            }
        }
    }

    *pCurrMaxSearchImageId = j;
    j = 0;
    for (i = 0; i < MAX_IMAGE_IDS_SIZE; i++)
    {
        if (pImageIdMap[i].nImageNum != (U16)-1)
        {
            if (i != j)
            {
                pImageIdMap[j].nImageNum = pImageIdMap[i].nImageNum;
                pImageIdMap[i].nImageNum = -1;
            }
            j++;
        }
    }
    *pCurrMaxImageId = j;
}


/*****************************************************************************
 * FUNCTION
 *  PopulateAudioSearch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateAudioSearch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 j = 0;
    U16 index = 0;
    U16 start = 0;
    CUSTOM_AUDIO_MAP *pAudioIdMap;
    CUSTOM_AUDIO_SEARCH_MAP *pAudioIdSearchMap;
    unsigned short *pCurrMaxSearchAudioId;
    unsigned short *pCurrMaxAudioId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pAudioIdMap = AudioIdMap;
    pAudioIdSearchMap = AudioIdSearchMap;
    pCurrMaxSearchAudioId = &CurrMaxSearchAudioId;
    pCurrMaxAudioId = &CurrMaxAudioId;

    for (i = 0; i < MAX_AUDIO_IDS_SIZE; i++)
    {
        if (pAudioIdMap[i].nAudioNum != (U16) - 1)
        {
            if (!start)
            {
                pAudioIdSearchMap[j].minAudioId = pAudioIdSearchMap[j].maxAudioId = i;
                pAudioIdSearchMap[j].index = index;
                index++;
                start = 1;
            }
            else
            {
                pAudioIdSearchMap[j].maxAudioId = i;
                index++;
            }
        }
        else
        {
            if (start)
            {
                j++;
                start = 0;
            }
        }
    }

    *pCurrMaxSearchAudioId = j;
    j = 0;
    for (i = 0; i < MAX_AUDIO_IDS_SIZE; i++)
    {
        if (pAudioIdMap[i].nAudioNum != (U16) - 1)
        {
            if (i != j)
            {
                pAudioIdMap[j].nAudioNum = pAudioIdMap[i].nAudioNum;
                pAudioIdMap[i].nAudioNum = -1;
            }
            j++;
        }
    }
    *pCurrMaxAudioId = j;
}


/*****************************************************************************
 * FUNCTION
 *  Trace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void Trace(char *fmt, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list MyList;
    char nPrintableStr[1000];   /* Assumed..this can chane if need to dump more bytes */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(MyList, fmt);
    vsprintf(nPrintableStr, fmt, MyList);
    va_end(MyList);
    printf(nPrintableStr);
}


/*****************************************************************************
 * FUNCTION
 *  GenerateImageResFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int GenerateImageResFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    S8 pBuffName[200];
    int i = 0;
    char Suffix[3] = "\",";
    char Prefix[MAX_FILENAME_LEN + 4] = "\"";
    IMAGENAME_LIST *pImageName;
    U16 nSize;
    char *str_CustImgDataHW;
    char *str_mtk_CurrMaxImageNum;
    char *str_CurrMaxImageNum;
    char *str_mtk_nCustImageNames;
    char *str_nCustImageNames;
    char *str_ImageNameList;
    char *str_mark;
    char *curr_img_data_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtImageFlag = SYSTEM_IMAGE;
    pImageName = (IMAGENAME_LIST*) ImageNameList;
    nSize = CurrMaxImageNum;
    str_CustImgDataHW = "DevAppImgDataHW.h";
    str_mtk_CurrMaxImageNum = "DevApp_CurrMaxImageNum";
    str_CurrMaxImageNum = "DevApp_CurrMaxImageNum";
    str_mtk_nCustImageNames = "DevApp_nCustImageNames";
    str_nCustImageNames = "DevApp_nCustImageNames";
    str_ImageNameList = "DevApp_ImageNameList";
    str_mark = "";
    curr_img_data_filename = IMG_DATA_FILENAME;

    if (pFile = fopen(curr_img_data_filename, "w"))
    {
        fprintf(
            pFile,
            "#include \"CustDataRes.h\"\n#include \"%s\"\n#include \"CustResDef.h\"\n\n%s",
            str_CustImgDataHW,
            str_mark);
        fprintf(pFile, "unsigned short  %s=%d;\n", str_CurrMaxImageNum, nSize);

        if (nSize)
        {
            fprintf(pFile, "const CUSTOM_IMAGE	%s[]={\n", str_nCustImageNames);

            for (i = 0; i < nSize; i++)
            {
                Extract_Name(pBuffName, pImageName[i].filename, RES_IMAGE);
                fprintf(pFile, "(U8*)&%s,\n", pBuffName);

            }

            fputs("};\n\n\n\n", pFile);
        }
        else
        {
            fprintf(
                pFile,
                "const CUSTOM_IMAGE	%s[MAX_IMAGE_NAMES_SIZE];",
                str_nCustImageNames);
            fputs
                ("#if defined(DEVELOPER_BUILD_FIRST_PASS) || defined(CUSTOMIZATION_BUILD_FIRST_PASS)|| defined(CUSTOMIZATION_BUILD_SECOND_PASS) \n\n",
                 pFile);

            fprintf(pFile, "IMAGENAME_LIST	%s[MAX_IMAGE_NAMES_SIZE];", str_ImageNameList);
            fputs("\n#endif", pFile);
        }

        fclose(pFile);
    }
    else
    {
        return 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateAudioResFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int GenerateAudioResFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    S8 pBuffName[200];
    int i = 0;
    char Suffix[3] = "\",";
    char Prefix[MAX_FILENAME_LEN + 4] = "\"";
    AUDIONAME_LIST *pAudioName;
    U16 nSize;
    char *str_CustAdoDataHW;
    char *str_mtk_CurrMaxAudioNum;
    char *str_CurrMaxAudioNum;
    char *str_mtk_nCustAudioNames;
    char *str_nCustAudioNames;
    char *str_AudioNameList;
    char *str_mark;
    char *curr_ado_data_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtAudioFlag = FALSE;
    pAudioName = (AUDIONAME_LIST*) AudioNameList;
    nSize = CurrMaxAudioNum;
    str_CustAdoDataHW = "DevAppAdoDataHW.h";
    str_mtk_CurrMaxAudioNum = "DevApp_CurrMaxAudioNum";
    str_CurrMaxAudioNum = "DevApp_CurrMaxAudioNum";
    str_mtk_nCustAudioNames = "DevApp_nCustAudioNames";
    str_nCustAudioNames = "DevApp_nCustAudioNames";
    str_AudioNameList = "DevApp_AudioNameList";
    str_mark = "";
    curr_ado_data_filename = ADO_DATA_FILENAME;

    if (pFile = fopen(curr_ado_data_filename, "w"))
    {
        fprintf(
            pFile,
            "#include \"CustDataRes.h\"\n#include \"%s\"\n#include \"CustResDef.h\"\n\n%s",
            str_CustAdoDataHW,
            str_mark);
        fprintf(pFile, "unsigned short  %s=%d;\n", str_CurrMaxAudioNum, nSize);

        if (nSize)
        {
            fprintf(pFile, "const CUSTOM_AUDIO	%s[]={\n", str_nCustAudioNames);

            for (i = 0; i < nSize; i++)
            {
                Extract_Name(pBuffName, pAudioName[i].filename, RES_AUDIO);
                fprintf(pFile, "(U8*)&%s,\n", pBuffName);

            }

            fputs("};\n\n\n\n", pFile);
        }
        else
        {
            fprintf(
                pFile,
                "const CUSTOM_AUDIO	%s[MAX_AUDIO_NAMES_SIZE];",
                str_nCustAudioNames);
            fputs
                ("#if defined(DEVELOPER_BUILD_FIRST_PASS) || defined(CUSTOMIZATION_BUILD_FIRST_PASS)|| defined(CUSTOMIZATION_BUILD_SECOND_PASS) \n\n",
                 pFile);

            fprintf(pFile, "AUDIONAME_LIST	%s[MAX_AUDIO_NAMES_SIZE];", str_AudioNameList);
            fputs("\n#endif", pFile);
        }

        fclose(pFile);
    }
    else
    {
        return 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateImageMapFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int GenerateImageMapFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    CUSTOM_IMAGE_MAP *pMap;
    int i;
    U16 nSize;
    char *str_CustImageMap;
    char *str_CurrMaxImageId;
    char *str_ImageIdMap;
    char *curr_img_map_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtImageFlag = SYSTEM_IMAGE;    /* 101205 audio resource Calvin */
    pMap = (CUSTOM_IMAGE_MAP*) ImageIdMap;
    nSize = CurrMaxImageId;
    str_CustImageMap = "DevAppImageMap.c";
    str_CurrMaxImageId = "DevApp_CurrMaxImageId";
    str_ImageIdMap = "DevApp_ImageIdMap";
    curr_img_map_filename = IMG_MAP_FILENAME;

    if (pFile = fopen(curr_img_map_filename, "w"))
    {
        fputs("#include \"CustDataRes.h\"\n\n\n", pFile);

        fprintf(pFile, "unsigned short %s=%d;\n", str_CurrMaxImageId, nSize);

        /* Writing the Image Map Array inside the file. */
        if (nSize)
        {
            fprintf(pFile, "const CUSTOM_IMAGE_MAP %s[]={\n", str_ImageIdMap, pFile);
            for (i = 0; i < nSize; i++)
            {
                fprintf(pFile, "\t{%d},\n", pMap[i].nImageNum);
            }
            fputs("};\n\n\n\n", pFile);
        }
        else
        {
            fprintf(pFile, "const CUSTOM_IMAGE_MAP %s[];\n", str_ImageIdMap, pFile);
        }
        fclose(pFile);
    }
    else
    {
        return 0;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateAudioMapFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int GenerateAudioMapFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    CUSTOM_AUDIO_MAP *pMap;
    int i;
    U16 nSize;
    char *str_CustAudioMap;
    char *str_CurrMaxAudioId;
    char *str_AudioIdMap;
    char *curr_ado_map_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtAudioFlag = FALSE;
    pMap = (CUSTOM_AUDIO_MAP*) AudioIdMap;
    nSize = CurrMaxAudioId;
    str_CustAudioMap = "DevAppAudioMap.c";
    str_CurrMaxAudioId = "DevApp_CurrMaxAudioId";
    str_AudioIdMap = "DevApp_AudioIdMap";
    curr_ado_map_filename = ADO_MAP_FILENAME;

    if (pFile = fopen(curr_ado_map_filename, "w"))
    {
        fputs("#include \"CustDataRes.h\"\n\n\n", pFile);

        fprintf(pFile, "unsigned short %s=%d;\n", str_CurrMaxAudioId, nSize);

        /* Writing the Audio Map Array inside the file. */

        if (nSize)
        {
            fprintf(pFile, "const CUSTOM_AUDIO_MAP %s[]={\n", str_AudioIdMap, pFile);
            for (i = 0; i < nSize; i++)
            {
                fprintf(pFile, "\t{%d},\n", pMap[i].nAudioNum);
            }
            fputs("};\n\n\n\n", pFile);
        }
        else
        {
            fprintf(pFile, "const CUSTOM_AUDIO_MAP %s[1];\n", str_AudioIdMap, pFile);
        }
        fclose(pFile);
    }
    else
    {
        return 0;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateImageMapSearchFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int GenerateImageMapSearchFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    CUSTOM_IMAGE_SEARCH_MAP *pMap = (CUSTOM_IMAGE_SEARCH_MAP*) ImageIdSearchMap;
    int i;
    U16 nSize;
    char *str_CurrMaxSearchImageId;
    char *str_ImageIdSearchMap;
    char *curr_img_map_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtImageFlag = SYSTEM_IMAGE;
    pMap = (CUSTOM_IMAGE_SEARCH_MAP*) ImageIdSearchMap;
    nSize = CurrMaxSearchImageId;
    str_CurrMaxSearchImageId = "DevApp_CurrMaxSearchImageId";
    str_ImageIdSearchMap = "DevApp_ImageIdSearchMap";
    curr_img_map_filename = IMG_MAP_FILENAME;

    if (pFile = fopen(curr_img_map_filename, "a"))
    {
        fprintf(pFile, "unsigned short %s=%d;\n", str_CurrMaxSearchImageId, nSize);
        /* Writing the Image Map Array inside the file. */
        if (nSize)
        {
            fprintf(pFile, "const CUSTOM_IMAGE_SEARCH_MAP %s[]={\n", str_ImageIdSearchMap);
            for (i = 0; i < nSize; i++)
            {
                fprintf(pFile, "\t{%d,%d,%d},\n", pMap[i].minImageId, pMap[i].maxImageId, pMap[i].index);
            }
            fputs("};\n\n\n\n", pFile);
        }
        else
        {
            fprintf(pFile, "CUSTOM_IMAGE_SEARCH_MAP %s[1];", str_ImageIdSearchMap);
        }
        fclose(pFile);
    }
    else
    {
        return 0;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateAudioMapSearchFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int GenerateAudioMapSearchFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    CUSTOM_AUDIO_SEARCH_MAP *pMap = (CUSTOM_AUDIO_SEARCH_MAP*) AudioIdSearchMap;
    int i;
    U16 nSize;
    char *str_CurrMaxSearchAudioId;
    char *str_AudioIdSearchMap;
    char *curr_ado_map_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtAudioFlag = FALSE;
    pMap = (CUSTOM_AUDIO_SEARCH_MAP*) AudioIdSearchMap;
    nSize = CurrMaxSearchAudioId;
    str_CurrMaxSearchAudioId = "DevApp_CurrMaxSearchAudioId";
    str_AudioIdSearchMap = "DevApp_AudioIdSearchMap";
    curr_ado_map_filename = ADO_MAP_FILENAME;

    if (pFile = fopen(curr_ado_map_filename, "a"))
    {
        fprintf(pFile, "unsigned short %s=%d;\n", str_CurrMaxSearchAudioId, nSize);
        /* Writing the Audio Map Array inside the file. */
        if (nSize)
        {
            fprintf(pFile, "const CUSTOM_AUDIO_SEARCH_MAP %s[]={\n", str_AudioIdSearchMap);
            for (i = 0; i < nSize; i++)
            {
                fprintf(pFile, "\t{%d,%d,%d},\n", pMap[i].minAudioId, pMap[i].maxAudioId, pMap[i].index);
            }
            fputs("};\n\n\n\n", pFile);
        }
        else
        {
            fprintf(pFile, "CUSTOM_AUDIO_SEARCH_MAP %s[1];", str_AudioIdSearchMap);
        }
        fclose(pFile);
    }
    else
    {
        return 0;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateMenuFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nSize       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int GenerateMenuFile(U16 nSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    CUSTOM_MENU *pCustMenu = (CUSTOM_MENU*) nCustMenus;
    S8 nItemData[100];      /* Assumed .. */
    S8 MenuItemString[500]; /* Assumed .. */
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pFile = fopen(MENU_DATA_FILENAME, "w"))
    {
        /* Put the headers needed here */
        fputs("#include \"CustMenuRes.h\"\n\n\n", pFile);
        fprintf(pFile, "unsigned short  DevApp_MaxMenuItemIndex=%d;\n", nSize);
        /* Writing the String Array inside the file. */
        if (nSize)
        {
            for (i = MENU_ID_DEVAPP_START - 1; i < nSize; i++)
            {
                if (pCustMenu[i].nNumofMenuItem)
                {
                    sprintf(MenuItemString, "const U16 DevApp_nOrderMenuItem_%d[]={", i);
                    for (j = 0; j < (pCustMenu[i].nNumofMenuItem - 1); j++)
                    {
                        sprintf(nItemData, "%d,", pCustMenu[i].nOrderMenuItemId[j]);
                        strcat(MenuItemString, nItemData);
                    }
                    sprintf(nItemData, "%d};", pCustMenu[i].nOrderMenuItemId[j]);
                    strcat(MenuItemString, nItemData);
                    fprintf(pFile, "%s\n", MenuItemString);
                }

            }
            for (i = DEVAPP_BASE; i < DEVAPP_BASE_MAX; i++)
            {
                if (pCustMenu[i].nNumofMenuItem)
                {
                    sprintf(MenuItemString, "const U16 DevApp_nOrderMenuItem_%d[]={", i);
                    for (j = 0; j < (pCustMenu[i].nNumofMenuItem - 1); j++)
                    {
                        sprintf(nItemData, "%d,", pCustMenu[i].nOrderMenuItemId[j]);
                        strcat(MenuItemString, nItemData);
                    }
                    sprintf(nItemData, "%d};", pCustMenu[i].nOrderMenuItemId[j]);
                    strcat(MenuItemString, nItemData);
                    fprintf(pFile, "%s\n", MenuItemString);
                }

            }            
            for (i = AVK_BASE; i < AVK_BASE_MAX; i++)
            {
                if (pCustMenu[i].nNumofMenuItem)
                {
                    sprintf(MenuItemString, "const U16 DevApp_nOrderMenuItem_%d[]={", i);
                    for (j = 0; j < (pCustMenu[i].nNumofMenuItem - 1); j++)
                    {
                        sprintf(nItemData, "%d,", pCustMenu[i].nOrderMenuItemId[j]);
                        strcat(MenuItemString, nItemData);
                    }
                    sprintf(nItemData, "%d};", pCustMenu[i].nOrderMenuItemId[j]);
                    strcat(MenuItemString, nItemData);
                    fprintf(pFile, "%s\n", MenuItemString);
                }

            }                
            fputs("\n const CUSTOM_MENU		DevApp_nCustMenus[]={\n", pFile);
            for (i = MENU_ID_DEVAPP_START - 1; i < nSize; i++)
            {
                if (pCustMenu[i].nNumofMenuItem)
                {
                    sprintf(
                        MenuItemString,
                        "{%d,%d,%d,%d,%d,%d,%d,%d,(U16 *)DevApp_nOrderMenuItem_%d},",
                        pCustMenu[i].nMenuItemId,
                        pCustMenu[i].nParentId,
                        pCustMenu[i].nNumofMenuItem,
                        pCustMenu[i].nHideFlag,
                        pCustMenu[i].nMovable,
                        pCustMenu[i].nDispAttribute,
                        pCustMenu[i].nStrId,
                        pCustMenu[i].nImageId,
                        i);
                }
                else
                {
                    sprintf(
                        MenuItemString,
                        "{%d,%d,%d,%d,%d,%d,%d,%d,(U16 *)0},",
                        pCustMenu[i].nMenuItemId,
                        pCustMenu[i].nParentId,
                        pCustMenu[i].nNumofMenuItem,
                        pCustMenu[i].nHideFlag,
                        pCustMenu[i].nMovable,
                        pCustMenu[i].nDispAttribute,
                        pCustMenu[i].nStrId,
                        pCustMenu[i].nImageId);
                }
                fprintf(pFile, "%s\n", MenuItemString);

            }
            for (i = DEVAPP_BASE; i < DEVAPP_BASE_MAX; i++)
            {
                if (pCustMenu[i].nNumofMenuItem)
                {
                    sprintf(
                        MenuItemString,
                        "{%d,%d,%d,%d,%d,%d,%d,%d,(U16 *)DevApp_nOrderMenuItem_%d},",
                        pCustMenu[i].nMenuItemId,
                        pCustMenu[i].nParentId,
                        pCustMenu[i].nNumofMenuItem,
                        pCustMenu[i].nHideFlag,
                        pCustMenu[i].nMovable,
                        pCustMenu[i].nDispAttribute,
                        pCustMenu[i].nStrId,
                        pCustMenu[i].nImageId,
                        i);
                }
                else
                {
                    sprintf(
                        MenuItemString,
                        "{%d,%d,%d,%d,%d,%d,%d,%d,(U16 *)0},",
                        pCustMenu[i].nMenuItemId,
                        pCustMenu[i].nParentId,
                        pCustMenu[i].nNumofMenuItem,
                        pCustMenu[i].nHideFlag,
                        pCustMenu[i].nMovable,
                        pCustMenu[i].nDispAttribute,
                        pCustMenu[i].nStrId,
                        pCustMenu[i].nImageId);
                }
                fprintf(pFile, "%s\n", MenuItemString);

            }
            for (i = AVK_BASE; i < AVK_BASE_MAX; i++)
            {
                if (pCustMenu[i].nNumofMenuItem)
                {
                    sprintf(
                        MenuItemString,
                        "{%d,%d,%d,%d,%d,%d,%d,%d,(U16 *)DevApp_nOrderMenuItem_%d},",
                        pCustMenu[i].nMenuItemId,
                        pCustMenu[i].nParentId,
                        pCustMenu[i].nNumofMenuItem,
                        pCustMenu[i].nHideFlag,
                        pCustMenu[i].nMovable,
                        pCustMenu[i].nDispAttribute,
                        pCustMenu[i].nStrId,
                        pCustMenu[i].nImageId,
                        i);
                }
                else
                {
                    sprintf(
                        MenuItemString,
                        "{%d,%d,%d,%d,%d,%d,%d,%d,(U16 *)0},",
                        pCustMenu[i].nMenuItemId,
                        pCustMenu[i].nParentId,
                        pCustMenu[i].nNumofMenuItem,
                        pCustMenu[i].nHideFlag,
                        pCustMenu[i].nMovable,
                        pCustMenu[i].nDispAttribute,
                        pCustMenu[i].nStrId,
                        pCustMenu[i].nImageId);
                }
                fprintf(pFile, "%s\n", MenuItemString);

            }            
            fputs("};\n", pFile);
        }
        else
        {
            fputs("const CUSTOM_MENU		DevApp_nCustMenus[1];", pFile);
        }
        fclose(pFile);
    }
    else
    {
        return 0;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  argc        [IN]        
 *  argv        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int main(int argc, char *argv[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempCommand[200];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (argc == 3)
    {
        if (strcmp(argv[1], "-g") == 0 && strcmp(argv[2], "-x") == 0)
        {
            UnzipImage();
        }
        else
        {
            printf("Usage: mtk_resgenerator.exe -g -x\n");
            return 0;
        }
    }

    printf("MediaTek Resource Generate System 0.1\n");
    if ((argc == 2 || argc == 3) && strcmp(argv[1], "-g") == 0)
    {
        InitStrPopulate();
        PopulateCustResData();

        PopulateImageSearch();
        GenerateImageResFile();
        GenerateImageMapFile();
        GenerateImageMapSearchFile();

        PopulateAudioSearch();
        GenerateAudioResFile();
        GenerateAudioMapFile();
        GenerateAudioMapSearchFile();

        GenerateMenuFile(MAX_MENU_ITEMS_VALUE);
        return 1;
    }
    printf("Usage: mtk_resgenerator.exe -g\n");
    return 0;
}

