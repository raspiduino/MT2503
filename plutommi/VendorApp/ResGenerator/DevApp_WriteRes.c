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
 *  DevApp_WriteRes.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "GlobalMenuItems.h"
#include "buildcfg.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "mmi_features.h"//070306 Alpha layer
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
/* Resgen must not include plutommi related header files */
//#include "OslMemory.h"
//#include "Unicodexdcl.h"
#include "CustResDef.h"
#include "gui_resource_type.h"
#include "ImageGetDimension.h"

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#define MAX_NAME_LENGTH                 100
#define MENUITEM_ID_TYPE                9
#define PARENT_ITEM_ID_TYPE             8
#define NUMBER_OF_MENUITEMS_TYPE        7
#define MENU_ITEM_ORDER_TYPE            6
#define HIDE_FLAG_TYPE                  5
#define MOVEABLE_FLAG_TYPE              4
#define DISPLAY_ATTRIBUTE_TYPE          3
#define MENU_ITEM_STRING_ID_TYPE        2
#define MENU_ITEM_IMAGE_ID_TYPE         1
#define TRUE                            1
#define FALSE                           0
#define IMAGE_DESCRIPTOR_SIZE           2
#define BUFFER_SIZE                     4096
#define BUFFER_SIZE1                    16

#define OUTPUT_MENUTREE_FILENAME        "..\\DevResource\\Resources\\CustMenuTree_Out.c"
#define OUTPUT_IMAGE_NAMES_END          "[]=\n{"
#define NOIMAGE_FILENAMEBUFFER          "..\\\\DEVRESOURCE\\\\IMAGES\\\\NOIMAGE.BMP"
#define DEFAULT_FILENAMEBUFFER          "..\\DevResource\\Images\\Default.bmp"
#define DEFAULT_FILEBUFFER              "____DEVRESOURCE__IMAGES__DEFAULT_BMP"

#define OUTPUT_AUDIO_NAMES_END          "[]=\n{"
#define NOAUDIO_FILENAMEBUFFER          "..\\\\DEVRESOURCE\\\\AUDIO\\\\NOAUDIO.MP3"
#define AUDIO_DEFAULT_FILENAMEBUFFER    "..\\DevResource\\Audio\\Default.mp3"
#define AUDIO_DEFAULT_FILEBUFFER        "____DEVRESOURCE__AUDIO__DEFAULT_MP3"

#define SUPPORT_N_MEDIA_TYPE            6
#define MAX_SEQUENTIAL_IMAGE_FRAME      512
#define SUPPORT_N_SEQUENTIAL_IMAGE_TYPE 3

typedef struct Resource_Info
{
    S8 *filename_ext;
    U8 file_type;
} RESOURCE_INFO;

image_type_enum ExtImageFlag = SYSTEM_IMAGE;
BOOL ExtAudioFlag = FALSE;

#ifdef DEVELOPER_BUILD_FIRST_PASS

static U8 is_first = 1;
static U32 image_idx = 1;
static U32 audio_idx = 1;
static char is_dummy_code = 0;  /* To check if it needs to generate for menu tree tool or not. */
U8 StrIsPopulate[MAX_STRING_MAP_SIZE];
S8 filename_buffer[BUFFER_SIZE];
S8 tempBMPFile[BUFFER_SIZE];//070306 Alpha layer

S8 autofilename_buffer[BUFFER_SIZE];
S8 number_string[BUFFER_SIZE1];
S8 autoimagename_buffer[BUFFER_SIZE];
S8 *output_image_names = NULL;
S8 *output_audio_names = NULL;
S8 *support_media_ext[SUPPORT_N_MEDIA_TYPE] = { "AVI", "3GP", "MP4", "RV", "RM", "RMVB"};
U16 CurrMaxStringId;
S32 n_supported_extensions = 1;
S32 sequential_interval[MAX_SEQUENTIAL_IMAGE_FRAME];
S32 sequential_filesize[MAX_SEQUENTIAL_IMAGE_FRAME];
S32 sequential_offset[MAX_SEQUENTIAL_IMAGE_FRAME];
S32 sequential_extension_type;
S32 sequential_frame;
int toolFlag = 0;               /* decide if this is run by CustPack tool */
int resultFailFlag = 0;         /* decide if this is run by CustPack tool */

FILE *dest_file;
FILE *output_data_file;
FILE *image_data_file;
FILE *nfb_img_res_file;
FILE *audio_data_file;

MMI_BOOL g_is9slice = MMI_FALSE; /* 9SlICE image do not support sequence */

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
FILE *enfb_img_data_file;
int enfbFlag = 0;
int disableENFB = 0;
U32 enfb_offset = 0;
U32 enfb_size = 0;
MMI_BOOL ENFBAssociatedIDFlag = MMI_FALSE;
MMI_BOOL ENFBAssociatedIDAdded = MMI_FALSE;
#endif

S32 g_ressize = 0;
S8 g_resmenu_filename[MAX_FILENAME_LEN] = "";

RESOURCE_INFO sequential_image[SUPPORT_N_SEQUENTIAL_IMAGE_TYPE] = { {"BMP", IMAGE_TYPE_BMP_SEQUENCE},
{"JPG", IMAGE_TYPE_JPG_SEQUENCE},
{"PNG", IMAGE_TYPE_PNG_SEQUENCE}
};  /* 101205 audio resource Calvin */

RESOURCE_INFO image_resource_info[] = 
{
    {"BMP", IMAGE_TYPE_BMP},
    {"PBM", IMAGE_TYPE_DEVICE_BITMAP},//070306 Alpha layer
    {"GIF", IMAGE_TYPE_GIF},
    {"JPG", IMAGE_TYPE_JPG},
    {"AVI", IMAGE_TYPE_AVI},
    {"3GP", IMAGE_TYPE_3GP},
    {"MP4", IMAGE_TYPE_MP4},
    {"RV" , IMAGE_TYPE_RV },
    {"RM" , IMAGE_TYPE_RM },
    {"RMVB",IMAGE_TYPE_RMVB },
    {"PNG", IMAGE_TYPE_PNG},
    {"PPN", IMAGE_TYPE_PPN}//070306 Alpha layer
};

RESOURCE_INFO audio_resource_info[] = { {"MP3", AUDIO_TYPE_MP3},
{"IMY", AUDIO_TYPE_IMY},
{"MID", AUDIO_TYPE_MID},
{"WAV", AUDIO_TYPE_WAV},
{"MMF", AUDIO_TYPE_MMF},
{"PCM", AUDIO_TYPE_PCM},
{"DVI", AUDIO_TYPE_DVI},
{"AMR", AUDIO_TYPE_AMR},
{"AAC", AUDIO_TYPE_AAC},
{"WMA", AUDIO_TYPE_WMA}
};

void Extract_Name(S8 *dest, S8 *src, U32 res_type);
MMI_BOOL Iload(S8 *string, U16 *pType);

S8 CustImgPath[] = CUST_IMG_PATH;
S8 CustAdoPath[] = CUST_ADO_PATH;

extern U16 CurrMaxImageNum;
extern U16 CurrMaxImageId;
extern U16 CurrMaxMenuItemIndex;
extern U16 CurrMaxImageNumEXT;
extern U16 CurrMaxImageIdEXT;
extern U16 CurrMaxAudioNum;
extern U16 CurrMaxAudioId;
extern U16 CurrMaxAudioNumEXT;
extern U16 CurrMaxAudioIdEXT;

extern CUSTOM_STRING *gpStringRes;
extern CUSTOM_STRING_MAP *gpStringMapRes;
extern IMAGENAME_LIST ImageNameList[];
extern CUSTOM_IMAGE_MAP ImageIdMap[];
extern CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMap[];
extern IMAGENAME_LIST ImageNameListEXT[];
extern CUSTOM_IMAGE_MAP ImageIdMapEXT[];
extern CUSTOM_IMAGE_SEARCH_MAP ImageIdSearchMapEXT[];
extern CUSTOM_AUDIO nCustAudioNames[];
extern AUDIONAME_LIST AudioNameList[];
extern CUSTOM_AUDIO_MAP AudioIdMap[];
extern CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMap[];
extern AUDIONAME_LIST AudioNameListEXT[];
extern CUSTOM_AUDIO_MAP AudioIdMapEXT[];
extern CUSTOM_AUDIO_SEARCH_MAP AudioIdSearchMapEXT[];
extern const CUSTOM_MENU nCustMenus[MAX_MENU_ITEMS];

extern FILE *StringListFile;
extern FILE *EnumListFile;
extern FILE *OutputImgIDFile;
extern FILE *OutputMenutreeIDFile;
extern FILE *RepeatIDListFile;
extern FILE *OutputAdoIDFile;

extern HWND hWnd;

#ifdef __UCS2_ENCODING
static U16 mmi_asc_to_ucs2(S8 *pOutBuffer, S8 *pInBuffer);
#endif 

U8 g_9slice_filename[MAX_FILENAME_LEN];
extern void mmi_rg_write_9slice_header(U8 real_imagetype, FILE *outfile, MMI_BOOL is_binary);

/*****************************************************************************
 * FUNCTION
 *  InitStrPopulate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitStrPopulate()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_STRING_MAP_SIZE; i++)
    {
        StrIsPopulate[i] = 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ConvertToPrintable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  original        [?]     [?]
 *  converted       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void ConvertToPrintable(S8 *original, S8 *converted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0, j = 0, strlength = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlength = wcslen((wchar_t*) original);
    for (i = 0; i < strlength * 2; i++)
    {
        if (original[i] == 10)
        {
            converted[j] = 92;
            converted[++j] = 0;
            converted[++j] = 'n';
            j++;
        }
        else
        {
            converted[j++] = original[i];
        }
    }
    if (strlength == 0)
    {   /* If NULL string, fill in " " */
        converted[0] = 20;
        converted[1] = '\0';
        converted[2] = '\0';
        converted[3] = '\0';
    }
    else
    {
        converted[j++] = '\0';
        converted[j] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_asc_to_ucs2
 * DESCRIPTION
 *  Converts Ansii encode string to unicode
 *  
 *  Caller has to ensure that pOutBuffer
 *  should be as large
 * PARAMETERS
 *  pOutBuffer      [OUT]     
 *  pInBuffer       [IN]     
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_asc_to_ucs2(S8 *pOutBuffer, S8 *pInBuffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*pInBuffer != '\0')
    {
        pOutBuffer[++count] = *pInBuffer;
        pOutBuffer[++count] = 0;
        pInBuffer++;
    }

    pOutBuffer[++count] = '\0';
    pOutBuffer[++count] = '\0';
    return count + 1;
}


/*****************************************************************************
 * FUNCTION
 *  SetStringWithDisplay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nStrId          [IN]        
 *  pString1        [?]         [?]
 *  pDisplay1       [?]         [?]
 *  enum_value      [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void SetStringWithDisplay(U16 nStrId, S8 *pString1, S8 *pDisplay1, S8 *enum_value, S8 *resfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 found = 0;
    S8 *pString = NULL;
    S8 *pDisplay = NULL;
    ResourceInfo sInfo;
    S8 *sString = NULL;
    U16 StrTotalLen = 0;
    U16 nLen = 0;
    S8 cString[1024], cDisplay[1024];
    S8 *pEnum_value = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __ASCII

    pString = pString1;
    pDisplay = pDisplay1;
#endif /* __ASCII */ 

#ifdef __UCS2_ENCODING

    pString = malloc((strlen(pString1) + 1) * 2);
    mmi_asc_to_ucs2(pString, pString1);

    pDisplay = malloc((strlen(pDisplay1) + 1) * 2);
    mmi_asc_to_ucs2(pDisplay, pDisplay1);

    pEnum_value = malloc((strlen(enum_value) + 1) * 2);
    mmi_asc_to_ucs2(pEnum_value, enum_value);

#endif /* __UCS2_ENCODING */ 
    if (StrIsPopulate[nStrId] == 0)
    {
        CurrMaxStringId++;
        StrIsPopulate[nStrId] = 1;
        ConvertToPrintable(pString, cString);
        ConvertToPrintable(pDisplay, cDisplay);
        fwprintf(
            StringListFile,
            L"%ls\t%d\t%ls\t%ls\r\n",
            (wchar_t*) pEnum_value,
            nStrId,
            (wchar_t*) cDisplay,
            (wchar_t*) cString);
        fprintf(EnumListFile, "%s,\n", enum_value);
    }
    else
    {
        fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nStrId, enum_value, "String");
    }
}


/*****************************************************************************
 * FUNCTION
 *  AddApp
 * DESCRIPTION
 *  Function to Add a new application into the framework
 * PARAMETERS
 *  nId         [IN]        App Id
 *  pName       [IN]        Application name.
 *  nMinId      [IN]        Minimum Id value supported
 *  nMaxId      [IN]        Maximum Id value
 * RETURNS
 *  void
 *****************************************************************************/
void AddApp(U32 nId, S8 *pName, U16 nMinId, U16 nMaxId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ResourceInfo sInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sInfo.nAppId = nId;
    sInfo.nMaxId = nMaxId;
    sInfo.nMinId = nMinId;
    sInfo.pValue = pName;
}


/*****************************************************************************
 * FUNCTION
 *  SetString
 * DESCRIPTION
 *  Function to Update the Customizable Resource String & Mapping Array.
 * PARAMETERS
 *  StrId           [IN]        
 *  String1         [?]         [?]
 *  enum_value      [?]         [?]
 *  U16(?)          [OUT]       String Number which is Mapped with the StringId.(?)
 * RETURNS
 *  StringNumber which is mapped with the StringID.(?)(?)
 *****************************************************************************/
void SetString(U16 StrId, S8 *String1, S8 *enum_value, S8 *resfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetStringWithDisplay(StrId, String1, String1, enum_value, resfile);
}


/*****************************************************************************
 * FUNCTION
 *  SetImage
 * DESCRIPTION
 *  Function to Update the Customizable Image Filename & Mapping Array.
 * PARAMETERS
 *  ImgId           [IN]        
 *  filename        [?]         [?]
 *  enum_value      [?]         [?]
 *  res_type        [IN]        
 *  U16(?)          [OUT]       Image Number which is Mapped with the ImageId.(?)
 * RETURNS
 *  Image Number which is mapped with the ImageId.(?)(?)
 *****************************************************************************/
void SetImage(U16 ImgId, S8 *filename, S8 *enum_value, U32 res_type, S8 *resfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetImageWithBuffer(ImgId, filename, "", enum_value, res_type, FALSE, resfile);
}


/*****************************************************************************
 * FUNCTION
 *  SetNFBImage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void SetNFBImage(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nType;
    S16 nStrlen;
    S8 upperFileName[MAX_FILENAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(filename) >= MAX_FILENAME_LEN)
    {
        filename[MAX_FILENAME_LEN - 1] = '\0';
    }
    if (!(strcmp(filename, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);

    }
    nStrlen = strlen(filename);

    while (nStrlen >= 0)
    {
        upperFileName[nStrlen] = toupper(filename[nStrlen]);
        --nStrlen;
    }

    ExtImageFlag = NFB_PROGRESS_IMAGE;
    Iload(upperFileName, &nType);

}


/*****************************************************************************
 * FUNCTION
 *  SetImageWithBuffer
 * DESCRIPTION
 *  Function to copy the image file to buffer
 * PARAMETERS
 *  nImgId              [IN]        
 *  filename            [?]         Of the image to be displayed.
 *  pDisplayName        [?]         [?]
 *  enum_value          [?]         [?]
 *  res_type            [IN]        
 *  imgFlag             [IN]        
 *  U16(?)              [IN]        -> ImageId(?)
 * RETURNS
 *  void
 *****************************************************************************/
void SetImageWithBuffer(U16 nImgId, S8 *filename, S8 *pDisplayName, S8 *enum_value, U32 res_type, BOOL imgFlag, S8 *resfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 found = 0;
    S16 nStrlen;
    ResourceInfo sInfo;
    U16 nType;
    S8 upperFileName[MAX_FILENAME_LEN];
    unsigned short *pCurrMaxImageId;
    unsigned short *pCurrMaxImageNum;
    IMAGENAME_LIST *pImageNameList;
    CUSTOM_IMAGE_MAP *pImageIdMap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_is9slice = MMI_FALSE;

    if (imgFlag == TRUE)
    {
        ExtImageFlag = EXT_IMAGE;
        pCurrMaxImageId = &CurrMaxImageIdEXT;
        pCurrMaxImageNum = &CurrMaxImageNumEXT;
        pImageNameList = ImageNameListEXT;
        pImageIdMap = ImageIdMapEXT;
    }
    else
    {
        ExtImageFlag = SYSTEM_IMAGE;
        pCurrMaxImageId = &CurrMaxImageId;
        pCurrMaxImageNum = &CurrMaxImageNum;
        pImageNameList = ImageNameList;
        pImageIdMap = ImageIdMap;
    }

    if (*pCurrMaxImageId >= MAX_IMAGE_IDS_SIZE)
    {
        return; /* Can't add more than max number of image ids allowed */
    }

    fprintf(OutputImgIDFile, "file name%d = %s \n", image_idx++, filename);

    if (strlen(filename) >= MAX_FILENAME_LEN)
    {
        filename[MAX_FILENAME_LEN - 1] = '\0';
    }
    if (!(strcmp(filename, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);

    }
    nStrlen = strlen(filename);

    while (nStrlen >= 0)
    {
        upperFileName[nStrlen] = toupper(filename[nStrlen]);
        --nStrlen;
    }

    for (i = 0; i < *pCurrMaxImageNum; i++)
    {
        if (!strcmp(pImageNameList[i].filename, upperFileName))
        {
            found = 1;
            break;
        }
    }

    if (pImageIdMap[nImgId].nImageNum != (U16)-1)
    {
        switch (res_type)
        {
            case RES_IMAGE:
                fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nImgId, enum_value, "Image");
                break;
            case RES_MEDIA:
                fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nImgId, enum_value, "Media");
                break;
            default:
                printf("Non supported resource type!\n");
        }
    }

    if (found)
    {
        pImageIdMap[nImgId].nImageNum = i;
        (*pCurrMaxImageId)++;
    }
    else
    {
        if (Iload(upperFileName, &nType))
        {
            strcpy(pImageNameList[*pCurrMaxImageNum].filename, upperFileName);
            pImageIdMap[nImgId].nImageNum = *pCurrMaxImageNum;
            (*pCurrMaxImageNum)++;
            (*pCurrMaxImageId)++;
        }
        else    /* let new set of images share the same resource of default image */
        {
            if (toolFlag)
            {
                resultFailFlag = 1;
            }
            strcpy(ImageNameList[CurrMaxImageNum].filename, DEFAULT_FILEBUFFER);
            ImageIdMap[nImgId].nImageNum = CurrMaxImageNum;
            CurrMaxImageNum++;
            CurrMaxImageId++;
        }
    }
    sInfo.pDisplayValue = pDisplayName;
    sInfo.pValue = upperFileName;
}


/*****************************************************************************
 * FUNCTION
 *  SetAudioWithBuffer
 * DESCRIPTION
 *  Function to copy the audio file to buffer
 * PARAMETERS
 *  nAdoId              [IN]        
 *  filename            [?]         Of the audio to be generated.
 *  pDisplayName        [?]         [?]
 *  enum_value          [?]         [?]
 *  res_type            [IN]        
 *  adoFlag             [IN]        
 *  U16(?)              [IN]        -> AudioId(?)
 * RETURNS
 *  void
 *****************************************************************************/
void SetAudioWithBuffer(U16 nAdoId, S8 *filename, S8 *pDisplayName, S8 *enum_value, U32 res_type, BOOL adoFlag, S8 *resfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 found = 0;
    S16 nStrlen;
    U16 nType;
    S8 upperFileName[MAX_FILENAME_LEN];
    unsigned short *pCurrMaxAudioId;
    unsigned short *pCurrMaxAudioNum;
    AUDIONAME_LIST *pAudioNameList;
    CUSTOM_AUDIO_MAP *pAudioIdMap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (adoFlag == TRUE)
    {
        ExtAudioFlag = TRUE;
        pCurrMaxAudioId = &CurrMaxAudioIdEXT;
        pCurrMaxAudioNum = &CurrMaxAudioNumEXT;
        pAudioNameList = AudioNameListEXT;
        pAudioIdMap = AudioIdMapEXT;
    }
    else
    {
        ExtAudioFlag = FALSE;
        pCurrMaxAudioId = &CurrMaxAudioId;
        pCurrMaxAudioNum = &CurrMaxAudioNum;
        pAudioNameList = AudioNameList;
        pAudioIdMap = AudioIdMap;
    }

    if (*pCurrMaxAudioId >= MAX_AUDIO_IDS_SIZE)
    {
        return; /* Can't add more than max number of audio ids allowed */
    }

    fprintf(OutputAdoIDFile, "file name%d = %s \n", audio_idx++, filename);

    if (strlen(filename) >= MAX_FILENAME_LEN)
    {
        filename[MAX_FILENAME_LEN - 1] = '\0';
    }
    if (!(strcmp(filename, "")))
    {
        strcpy(filename_buffer, NOAUDIO_FILENAMEBUFFER);

    }
    nStrlen = strlen(filename);

    while (nStrlen >= 0)
    {
        upperFileName[nStrlen] = toupper(filename[nStrlen]);
        --nStrlen;
    }

    for (i = 0; i < *pCurrMaxAudioNum; i++)
    {
        if (!strcmp(pAudioNameList[i].filename, upperFileName))
        {
            found = 1;
            break;
        }
    }

    if (pAudioIdMap[nAdoId].nAudioNum != (U16)-1)
    {
        switch (res_type)
        {
            case RES_AUDIO:
                fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nAdoId, enum_value, "Audio");
                break;
            default:
                printf("Non supported resource type!\n");
        }
    }

    if (found)
    {
        pAudioIdMap[nAdoId].nAudioNum = i;
        (*pCurrMaxAudioId)++;
    }
    else
    {
        if (Aload(upperFileName, &nType))
        {
            strcpy(pAudioNameList[*pCurrMaxAudioNum].filename, upperFileName);
            pAudioIdMap[nAdoId].nAudioNum = *pCurrMaxAudioNum;
            (*pCurrMaxAudioNum)++;
            (*pCurrMaxAudioId)++;
        }
        else
        {
            if (toolFlag)
            {
                resultFailFlag = 1;
            }
            strcpy(AudioNameList[CurrMaxAudioNum].filename, AUDIO_DEFAULT_FILEBUFFER);
            AudioIdMap[nAdoId].nAudioNum = CurrMaxAudioNum;
            CurrMaxAudioNum++;
            CurrMaxAudioId++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  MenuItemPresent
 * DESCRIPTION
 *  Function to find ImageId
 * PARAMETERS
 *  ItemId      [IN]        
 *  U16(?)      [IN]        -> ImageId(?)
 * RETURNS
 *  U16
 *****************************************************************************/
U16 MenuItemPresent(U16 ItemId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CurrMaxMenuItemIndex; i++)
    {
        if (nCustMenus[i].nMenuItemId == ItemId)
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  PrintMenuItems
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure, for MenuTree Tool usage
 * PARAMETERS
 *  arg1        [?]     [?]
 *  U16(?)      [IN]        -> variable argument list(?)
 * RETURNS
 *  void
 *****************************************************************************/
void PrintMenuItems(char *arg1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* static U8 is_first=1; */
    FILE *fout;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_dummy_code == 1)
    {
        return;
    }

    if (is_first)
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "w");
        is_first = 0;
    }
    else
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "a");
    }

    fprintf(fout, "ADD_APPLICATION_MENUITEM2(%s);\n", arg1);
    fclose(fout);

}


/*****************************************************************************
 * FUNCTION
 *  PrintMenuItems2
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure, for MenuTree Tool usage
 * PARAMETERS
 *  arg1        [?]     [?]
 *  U16(?)      [IN]        -> variable argument list(?)
 * RETURNS
 *  void
 *****************************************************************************/
void PrintMenuItems2(char *arg1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* static U8 is_first=1; */
    FILE *fout;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_dummy_code == 1)
    {
        return;
    }

    if (is_first)
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "w");
        is_first = 0;
    }
    else
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "a");
    }

    fprintf(fout, "ADD_APPLICATION_MENUITEM3(%s);\n", arg1);
    fclose(fout);

}

/*****************************************************************************
 * FUNCTION
 *  PrintMenuItems5
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure, for MenuTree Tool usage
 * PARAMETERS
 *  arg1        [?]         
 *  U16(?)      [IN]        -> variable argument list
 * RETURNS
 *  void
 *****************************************************************************/
void PrintMenuItems5(char *arg1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* static U8 is_first=1; */
    FILE *fout;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_dummy_code == 1)
    {
        return;
    }
    if (is_first)
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "w");
        is_first = 0;
    }
    else
    {
        fout = fopen(OUTPUT_MENUTREE_FILENAME, "a");
    }

    if (fout != NULL)
    {
        fprintf(fout, "ADD_APPLICATION_MENUITEM5(%s);\n", arg1);
        fclose(fout);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetMenuItem
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure
 * PARAMETERS
 *  arg1        [IN]        
 *  U16(?)      [IN]        -> variable argument list(?)
 * RETURNS
 *  void
 *****************************************************************************/
void SetMenuItem(U16 arg1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 MemberCounter = 9;
    U16 i = arg1;
    U16 j;
    U16 menuItemID;
    va_list argumentPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(argumentPtr, arg1);

    /* Need to decide whether menu item already present */
    if (!MenuItemPresent(i))
    {
        fprintf(OutputMenutreeIDFile, "ADD_APPLICATION_MENUITEM2((", arg1);

        is_dummy_code = 0;
        while (MemberCounter)
        {
            switch (MemberCounter)
            {
                case MENUITEM_ID_TYPE:
                    menuItemID = i - 1;

                    nCustMenus[menuItemID].nMenuItemId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case PARENT_ITEM_ID_TYPE:
                    nCustMenus[menuItemID].nParentId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case NUMBER_OF_MENUITEMS_TYPE:
                    nCustMenus[menuItemID].nNumofMenuItem = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case MENU_ITEM_ORDER_TYPE:
                    if (nCustMenus[menuItemID].nNumofMenuItem == 0)
                    {
                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) 0;
                    }
                    else
                    {
                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) malloc(sizeof(U16) * MENU_ITEM_SIZE);
                        for (j = 0; j < nCustMenus[menuItemID].nNumofMenuItem; j++)
                        {
                            fprintf(OutputMenutreeIDFile, "%d,", i);
                            nCustMenus[menuItemID].nOrderMenuItemId[j] = i;
                            i = va_arg(argumentPtr, int);
                        }
                    }
                    break;
                case HIDE_FLAG_TYPE:
                    nCustMenus[menuItemID].nHideFlag = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case MOVEABLE_FLAG_TYPE:
                    nCustMenus[menuItemID].nMovable = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case DISPLAY_ATTRIBUTE_TYPE:
                    nCustMenus[menuItemID].nDispAttribute = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case MENU_ITEM_STRING_ID_TYPE:
                    nCustMenus[menuItemID].nStrId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case MENU_ITEM_IMAGE_ID_TYPE:
                    nCustMenus[menuItemID].nImageId = i;
                    fprintf(OutputMenutreeIDFile, "%d));\n", i);
                    break;
            }
            if (MemberCounter != MENU_ITEM_ORDER_TYPE)
            {
                i = va_arg(argumentPtr, int);
            }

            MemberCounter--;
        }
    }
    else
    {
        is_dummy_code = 1;
    }

    va_end(argumentPtr);
}


/*****************************************************************************
 * FUNCTION
 *  SetMenuItem2
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure
 * PARAMETERS
 *  arg1        [IN]        
 *  U16(?)      [IN]        -> variable argument list(?)
 * RETURNS
 *  void
 *****************************************************************************/
void SetMenuItem2(U16 arg1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 MemberCounter = 9;
    U16 i = arg1;
    U16 j;
    U16 menuItemID;
    va_list argumentPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(argumentPtr, arg1);

    /* Need to decide whether menu item already present */
    if (!MenuItemPresent(i))
    {
        fprintf(OutputMenutreeIDFile, "ADD_APPLICATION_MENUITEM2((", arg1);

        is_dummy_code = 0;
        while (MemberCounter)
        {
            switch (MemberCounter)
            {
                case MENUITEM_ID_TYPE:
                    menuItemID = i - 1;

                    nCustMenus[menuItemID].nMenuItemId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case PARENT_ITEM_ID_TYPE:
                    nCustMenus[menuItemID].nParentId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case MENU_ITEM_ORDER_TYPE:
                    if (i == MENU_ITEM_END)
                    {
                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) 0;
                    }
                    else
                    {
                        U16 number_of_child = 0;

                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) malloc(sizeof(U16) * MENU_ITEM_SIZE);
                        while (i < MENU_ITEM_END)
                        {
                            nCustMenus[menuItemID].nOrderMenuItemId[number_of_child] = i;
                            i = va_arg(argumentPtr, int);

                            number_of_child++;
                        }
                        nCustMenus[menuItemID].nNumofMenuItem = number_of_child;        /* Set number of child field */
                        fprintf(OutputMenutreeIDFile, "%d,", number_of_child);
                        for (i = 0; i < number_of_child; i++)
                        {
                            fprintf(OutputMenutreeIDFile, "%d,", nCustMenus[menuItemID].nOrderMenuItemId[i]);
                        }
                        i = va_arg(argumentPtr, int);   /* read in next argument. */
                    }
                    break;

                case HIDE_FLAG_TYPE:
                    nCustMenus[menuItemID].nHideFlag = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case MOVEABLE_FLAG_TYPE:
                    nCustMenus[menuItemID].nMovable = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case DISPLAY_ATTRIBUTE_TYPE:
                    nCustMenus[menuItemID].nDispAttribute = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case MENU_ITEM_STRING_ID_TYPE:
                    nCustMenus[menuItemID].nStrId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;

                case MENU_ITEM_IMAGE_ID_TYPE:
                    nCustMenus[menuItemID].nImageId = i;
                    fprintf(OutputMenutreeIDFile, "%d));\n", i);
                    break;
            }
            if (MemberCounter != MENU_ITEM_ORDER_TYPE)
            {
                i = va_arg(argumentPtr, int);
            }

            if (MemberCounter == PARENT_ITEM_ID_TYPE)   /* Skip NUMBER_OF_MENUITEMS_TYPE field */
            {
                MemberCounter -= 2;
            }
            else
            {
                MemberCounter--;
            }
        }
    }
    else
    {
        is_dummy_code = 1;
    }

    va_end(argumentPtr);
}


/*****************************************************************************
 * FUNCTION
 *  SetMenuItem5
 * DESCRIPTION
 *  Fills the CUSTOM_MENU structure
 * PARAMETERS
 *  arg1        [IN]        
 *  U16(?)      [IN]        -> variable argument list
 * RETURNS
 *  void
 *****************************************************************************/
void SetMenuItem5(U16 arg1, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 MemberCounter = 9;
    U16 i = arg1;
    U16 j;
    U16 menuItemID;
    va_list argumentPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(argumentPtr, arg1);

    /* Need to decide whether menu item already present */
    if (!MenuItemPresent(i))
    {
        fprintf(OutputMenutreeIDFile, "ADD_APPLICATION_MENUITEM5((", arg1);

        is_dummy_code = 0;
        while (MemberCounter)
        {
            switch (MemberCounter)
            {
                case MENUITEM_ID_TYPE:
                    menuItemID = i - 1;

                    nCustMenus[menuItemID].nMenuItemId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case PARENT_ITEM_ID_TYPE:
                    nCustMenus[menuItemID].nParentId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case NUMBER_OF_MENUITEMS_TYPE:
                    nCustMenus[menuItemID].nNumofMenuItem = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case MENU_ITEM_ORDER_TYPE:
                    if (nCustMenus[menuItemID].nNumofMenuItem == 0)
                    {
                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) 0;
                    }
                    else
                    {
                        nCustMenus[menuItemID].nOrderMenuItemId = (U16*) malloc(sizeof(U16) * MENU_ITEM_SIZE);
                        for (j = 0; j < nCustMenus[menuItemID].nNumofMenuItem; j++)
                        {
                            fprintf(OutputMenutreeIDFile, "%d,", i);
                            nCustMenus[menuItemID].nOrderMenuItemId[j] = i;
                            i = va_arg(argumentPtr, int);
                        }
                    }
                    break;
                case HIDE_FLAG_TYPE:
                    //nCustMenus[menuItemID].nFlags |= (((U8)i) & 0x1) << 7;
                    nCustMenus[menuItemID].nHideFlag = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case MOVEABLE_FLAG_TYPE:
                    //nCustMenus[menuItemID].nFlags |= ((U8)i) & 0x7F;
                    nCustMenus[menuItemID].nMovable = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case DISPLAY_ATTRIBUTE_TYPE:
                    //nCustMenus[menuItemID].nDispAttribute = (U8)(i & 0xFF);
                    nCustMenus[menuItemID].nDispAttribute = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case MENU_ITEM_STRING_ID_TYPE:
                    nCustMenus[menuItemID].nStrId = i;
                    fprintf(OutputMenutreeIDFile, "%d,", i);
                    break;
                case MENU_ITEM_IMAGE_ID_TYPE:
                    nCustMenus[menuItemID].nImageId = i;
                    fprintf(OutputMenutreeIDFile, "%d));\n", i);
                    break;
            }
            if (MemberCounter != MENU_ITEM_ORDER_TYPE)
            {
                i = va_arg(argumentPtr, int);
            }

            MemberCounter--;
        }
    }
    else
    {
        is_dummy_code = 1;
    }

    va_end(argumentPtr);
}



/*****************************************************************************
 * FUNCTION
 *  Get_Image_Identifier
 * DESCRIPTION
 *  Identifies the image , BMP , ppf etc
 *  
 *  This function will be refined later when multiple
 *  image type will be supported by the frame work
 *  rt. now it just a added hook to make the design complete
 * PARAMETERS
 *  extension_type      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 Get_Image_Identifier(S32 extension_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (extension_type < 0)
    {
        ret = 0;
    }

    else if (extension_type == 0)
    {
        ret = 1;
    }

    return (U8) ret;

}


/*****************************************************************************
 * FUNCTION
 *  Load_Image_Data
 * DESCRIPTION
 *  Identifies the image , BMP , ppf etc
 * PARAMETERS
 *  output_file             [IN]        Name of the file to which buffer
 *  input_file              [IN]        Name of the input image file
 *  image_identifier        [IN]        image identifier
 *  n_frames                [IN]        no of frames
 *  width                   [IN]        image width
 *  height                  [IN]        image height
 * RETURNS
 *  file size
 *****************************************************************************/
S32 Load_Image_Data(
        FILE *output_file,
        FILE *input_file,
        U8 image_identifier,
        S32 n_frames,
        U32 width,
        U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_size, i, o = 0;
    U8 ch;
    U32 width_height;
    S32 data_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (n_frames == 0)
    {
        n_frames = 1;
    }

    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    width_height = ((width & 0XFFF) << 12) | (height & 0XFFF);
    
    if (image_identifier == IMAGE_TYPE_BMP ||
        image_identifier == IMAGE_TYPE_GIF ||
        image_identifier == IMAGE_TYPE_JPG ||
        image_identifier == IMAGE_TYPE_PNG)
    {
        if ((file_size >> 24) > 0)
        {
            printf("\nImage is too big.\n");
            return 0;
        }
    }

    data_size = file_size;
    if (g_is9slice)
        data_size += 20;
    
    if (toolFlag)
    {
        if (g_is9slice)
        {
            fprintf(dest_file, "%c%c", IMAGE_TYPE_9SLICE, n_frames);
        }
        else              
        {            
            fprintf(dest_file, "%c%c", image_identifier, n_frames);
        } 
   
        if (image_identifier == IMAGE_TYPE_3GP || image_identifier == IMAGE_TYPE_MP4 ||
            image_identifier == IMAGE_TYPE_AVI || image_identifier == IMAGE_TYPE_RV  || 
            image_identifier == IMAGE_TYPE_RM  || image_identifier == IMAGE_TYPE_RMVB)
        {
            fprintf(
                dest_file,
                "%c%c%c%c%c%c",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (file_size & 0xff000000) >> 24,
                0,
                0);
        }
        else
        {
            fprintf(
                dest_file,
                "%c%c%c%c%c%c",
                (data_size & 0xff),
                (data_size & 0xff00) >> 8,
                (data_size & 0xff0000) >> 16,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        }

        if (g_is9slice)
        {
            /* Write 9slice file header */
            mmi_rg_write_9slice_header(image_identifier, dest_file, MMI_TRUE);
        }      
    }
    else
    {
        if (g_is9slice)
            fprintf(output_data_file, "\n\t0x%02X, 0x%02X, ", IMAGE_TYPE_9SLICE, n_frames);
        else
            fprintf(output_data_file, "\n\t0x%02X, 0x%02X, ", image_identifier, n_frames);

        if (image_identifier == IMAGE_TYPE_3GP || image_identifier == IMAGE_TYPE_MP4 ||
            image_identifier == IMAGE_TYPE_AVI || image_identifier == IMAGE_TYPE_RV ||
            image_identifier == IMAGE_TYPE_RM  || image_identifier == IMAGE_TYPE_RMVB)
        {
            fprintf(
                output_file,
                "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x00, 0x00,\n\t",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (file_size & 0xff000000) >> 24);
        }
        else
        {
            fprintf(
                output_file,
                "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t",
                (data_size & 0xff),
                (data_size & 0xff00) >> 8,
                (data_size & 0xff0000) >> 16,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        }

        if (g_is9slice)
        {
            /* Write 9slice file header */
            mmi_rg_write_9slice_header(image_identifier, output_file, MMI_FALSE);
        }      
    }

    for (i = 0; i < file_size; i++)
    {
        ch = fgetc(input_file);

        if (toolFlag)
        {
            fputc(ch, dest_file);
        }
        else
        {
            fprintf(output_file, "0x%02X, ", ch);
            o++;
            if ((o % 16) == 0)
            {
                fprintf(output_file, "\n\t");
            }
        }
    }

    return file_size + 8;
}


/*****************************************************************************
 * FUNCTION
 *  Load_Audio_Data
 * DESCRIPTION
 *  load and write audio header and data
 * PARAMETERS
 *  offset                  [OUT]       File offset --> file offset
 *  output_file             [IN]        -> Name of the file to which buffer
 *  input_file              [IN]        ->  Name of the input audio file
 *  pImgData                [OUT]       -> buffer containing image data
 *  audio_identifier        [IN]        -> audio identifier
 *  is(?)                   [IN]        To be written(?)
 * RETURNS
 *  S32 --> file size
 *****************************************************************************/
S32 Load_Audio_Data(U32 *offset, FILE *output_file, FILE *input_file, U8 *pImgData, U8 audio_identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_size, i, o = 0;
    U8 ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fseek(input_file, 0, SEEK_END);
    file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    if (toolFlag)
    {
        fprintf(
            dest_file,
            "%c%c%c%c%c%c%c%c",
            audio_identifier,
            file_size & 0xff,
            (file_size & 0xff00) >> 8,
            (file_size & 0xff0000) >> 16,
            (file_size & 0xff000000) >> 24,
            0,
            0,
            0);
    }
    else
    {
        fprintf(
            output_file /* output_data_file */ ,
            "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x00, 0x00, 0x00,\n\t",
            audio_identifier,
            file_size & 0xff,
            (file_size & 0xff00) >> 8,
            (file_size & 0xff0000) >> 16,
            (file_size & 0xff000000) >> 24);
    }

    pImgData[0] = (U8) audio_identifier;
    pImgData[1] = (U8) (file_size & 0xff);
    pImgData[2] = (U8) ((file_size & 0xff00) >> 8);
    pImgData[3] = (U8) ((file_size & 0xff0000) >> 16);
    pImgData[4] = (U8) ((file_size & 0xff000000) >> 24);

    for (i = 0; i < file_size; i++)
    {
        ch = fgetc(input_file);

        if (toolFlag)
        {
            fputc(ch, dest_file);
            (*offset)++;
            (pImgData)[i + 6] = ch;
        }
        else
        {
            fprintf(output_file, "0x%02X, ", ch);
            (*offset)++;
            (pImgData)[i + 6] = ch;
            o++;
            if ((o % 16) == 0)
            {
                fprintf(output_file, "\n\t");
            }
        }
    }

    return file_size + 8;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rg_write_9slice_header
 * DESCRIPTION
 *  write 9slice header, include position and read file type to output file
 * PARAMETERS
 *  output_file             [IN]        output file handle
 *  in_filename             [IN]        input image name
 *  real_imagetype          [IN]        Real image type of 9slice images
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rg_write_9slice_header(U8 real_imagetype, FILE *outfile, MMI_BOOL is_binary)
{
    U8 buffer[128];
    FILE *p_9slice_file;
    U32 x1,y1,x2,y2;
    U32 zoom_type;

    p_9slice_file = fopen(g_9slice_filename, "r");
    if (p_9slice_file == NULL)
    {
        fprintf(stderr, "\nError opening %s", g_9slice_filename);
        printf("\nError opening %s", g_9slice_filename);
        exit(2);
    }

    fgets(buffer, 128, p_9slice_file);
    x1 = atoi(buffer);
    fgets(buffer, 128, p_9slice_file);
    y1 = atoi(buffer);
    fgets(buffer, 128, p_9slice_file);
    x2 = atoi(buffer);
    fgets(buffer, 128, p_9slice_file);
    y2 = atoi(buffer);  
    fgets(buffer, 128, p_9slice_file);  /* zoom type */

    fclose(p_9slice_file);

    if (!(strcmp(buffer, "repeat")))
    {
        zoom_type = 0;
    }
    else if (!(strcmp(buffer, "stretch")))
    {
        zoom_type = 1;
    }
    else
    {
        fprintf(stderr, "\n9slice file error, please write [repeat/stretch], can not be[%s],set default value repeat\n", buffer);
        printf("\n9slice file error, please write [repeat/stretch], can not be[%s],set default value repeat\n", buffer);
        zoom_type = 0;
    }

    if (x1<0 || x1>1024 ||
        y1<0 || y1>1024 ||
        x2<0 || x2>1024 ||
        y2<0 || y2>1024)
    {
        fprintf(stderr, "\nError in 9slice file [%s]\n", g_9slice_filename);
        printf("\nError in 9slice file [%s]\n", g_9slice_filename);
        exit(2);
    }

    printf("Write 9slice image header [%s]  position=[%d-%d-%d-%d] zoom=[%s]\n", g_9slice_filename, x1, y1, x2, y2, buffer);
    if (is_binary)
    {
        fprintf(outfile,
                "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
                (U8) real_imagetype,            //type
                (U8) zoom_type,                 //zoom type
                (U8) 0,                         //reserved
                (U8) 0,                         //reserved
                (U8) ( x1 & 0xff),
                (U8) ((x1 >> 8) & 0xff),
                (U8) ((x1 >> 16) & 0xff),
                (U8) ((x1 >> 24) & 0xff),
                (U8) ( y1 & 0xff),
                (U8) ((y1 >> 8) & 0xff),
                (U8) ((y1 >> 16) & 0xff),
                (U8) ((y1 >> 24) & 0xff),                
                (U8) ( x2 & 0xff),
                (U8) ((x2 >> 8) & 0xff),
                (U8) ((x2 >> 16) & 0xff),
                (U8) ((x2 >> 24) & 0xff),                
                (U8) ( y2 & 0xff),
                (U8) ((y2 >> 8) & 0xff),
                (U8) ((y2 >> 16) & 0xff),
                (U8) ((y2 >> 24) & 0xff));         
    }
    else
    {
        fprintf(outfile,
                "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, ",
                (U8) real_imagetype,            //type
                (U8) zoom_type,                 //zoom type
                (U8) 0,                         //reserved
                (U8) 0,                         //reserved
                (U8) ( x1 & 0xff),
                (U8) ((x1 >> 8) & 0xff),
                (U8) ((x1 >> 16) & 0xff),
                (U8) ((x1 >> 24) & 0xff),
                (U8) ( y1 & 0xff),
                (U8) ((y1 >> 8) & 0xff),
                (U8) ((y1 >> 16) & 0xff),
                (U8) ((y1 >> 24) & 0xff),                
                (U8) ( x2 & 0xff),
                (U8) ((x2 >> 8) & 0xff),
                (U8) ((x2 >> 16) & 0xff),
                (U8) ((x2 >> 24) & 0xff),                
                (U8) ( y2 & 0xff),
                (U8) ((y2 >> 8) & 0xff),
                (U8) ((y2 >> 16) & 0xff),
                (U8) ((y2 >> 24) & 0xff));        
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  Write_Sequential_Image_Header
 * DESCRIPTION
 *  Construct the header for sequential images
 * PARAMETERS
 *  output_file             [IN]        output file handle
 *  image_identifier        [IN]        sequential image type
 *  n_frames                [IN]        the number of the frames
 *  seq_filesize            [IN]        pointer to a list of file sizes
 *  seq_offset              [OUT]       pointer to a list of offsets
 *  width                   [IN]        maximun width
 *  height                  [IN]        maximun height
 * RETURNS
 *  void
 *****************************************************************************/
void Write_Sequential_Image_Header(
        FILE *output_file,
        U8 image_identifier,
        S32 n_frames,
        S32 *seq_filesize,
        S32 *seq_offset,
        U32 width,
        U32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 offset = 8;
    S32 real_size;
    U32 width_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    width_height = ((width & 0XFFF) << 12) | (height & 0XFFF);

    if (toolFlag == 1)
    {
        /* the major header */
        fprintf(dest_file, "%c%c%c%c%c%c%c%c",
                image_identifier,
                n_frames,
                0, 0, 0,    /* file size (not used) */
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        for (i = 0; i < n_frames; i++)
        {
            int interval = sequential_interval[i];

            seq_offset[i] = offset;
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            fprintf(dest_file, "%c%c%c%c", seq_offset[i] & 0xff, (seq_offset[i] & 0xff00) >> 8, (seq_offset[i] & 0xff0000) >> 16, (seq_offset[i] & 0xff000000) >> 24);  /* the offset for each file */
            fprintf(dest_file, "%c%c%c%c", seq_filesize[i] & 0xff, (seq_filesize[i] & 0xff00) >> 8, (seq_filesize[i] & 0xff0000) >> 16, (seq_filesize[i] & 0xff000000) >> 24);  /* the size for each file */
            fprintf(dest_file, "%c%c%c%c", interval & 0xff, (interval & 0xff00) >> 8, (interval & 0xff0000) >> 16, (interval & 0xff000000) >> 24);      /* the interval for each file */
            offset += real_size;
        }
    }
    else
    {
        /* the major header */
        fprintf(output_file, "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t",
                image_identifier,
                n_frames,
                0, 0, 0,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        for (i = 0; i < n_frames; i++)
        {
            int interval = sequential_interval[i];

            seq_offset[i] = offset;
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            fprintf(output_file, "0x%02X, 0x%02X, 0x%02X, 0x%02X, ", seq_offset[i] & 0xff, (seq_offset[i] & 0xff00) >> 8, (seq_offset[i] & 0xff0000) >> 16, (seq_offset[i] & 0xff000000) >> 24);        /* the offset for each file */
            fprintf(output_file, "0x%02X, 0x%02X, 0x%02X, 0x%02X, ", seq_filesize[i] & 0xff, (seq_filesize[i] & 0xff00) >> 8, (seq_filesize[i] & 0xff0000) >> 16, (seq_filesize[i] & 0xff000000) >> 24);        /* the size for each file */
            fprintf(output_file, "0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t", interval & 0xff, (interval & 0xff00) >> 8, (interval & 0xff0000) >> 16, (interval & 0xff000000) >> 24); /* the interval for each file */
            offset += real_size;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Write_Sequential_Image_File
 * DESCRIPTION
 *  Write raw date from a frame of an image to the output file
 * PARAMETERS
 *  output_file     [IN]        -> output file handle
 *  input_file      [IN]        -> input file handle
 *  filesize        [IN]        -> the input file size
 * RETURNS
 *  void
 *****************************************************************************/
void Write_Sequential_Image_File(FILE *output_file, FILE *input_file, S32 filesize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 o = 0;
    U8 ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (toolFlag == 1)
    {
        for (i = 0; i < filesize; i++)
        {
            ch = fgetc(input_file);
            fprintf(dest_file, "%c", ch);
        }

        for (i = filesize; i % 4 != 0; i++)
        {
            fprintf(dest_file, "%c", 0);    /* for 4 byte alignment */
        }
    }
    else
    {
        for (i = 0; i < filesize; i++)
        {
            ch = fgetc(input_file);
            fprintf(output_file, "0x%02X, ", ch);
            o++;
            if ((o % 16) == 0)
            {
                fprintf(output_file, "\n\t");
            }
        }

        for (i = filesize; i % 4 != 0; i++)
        {
            fprintf(output_file, "0x00, "); /* for 4 byte alignment */
        }

        if ((o % 16) != 0)
        {
            fprintf(output_file, "\n\t");
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Extract_Name
 * DESCRIPTION
 *  Exract image name from the supplied string
 * PARAMETERS
 *  dest            [OUT]       -> Extrected file name from string
 *  src             [IN]        -> string containing file name and path
 *  res_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Extract_Name(S8 *dest, S8 *src, U32 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 iLen = strlen(src);
    U16 nCount = 0;

    S8 *pSrc = src;
    char a, b;
    S8 *pCustPath;
    U32 ExtFlag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (res_type)
    {
        case RES_IMAGE:
        case RES_MEDIA:
            pCustPath = CustImgPath;
            ExtFlag = ExtImageFlag;
            break;

        case RES_AUDIO:
            pCustPath = CustAdoPath;
            ExtFlag = ExtAudioFlag;
            break;

        default:
            printf("res_type in Extract_Name is invalid!!");
            pCustPath = CustImgPath;
            ExtFlag = ExtImageFlag;
            break;
    }

    iLen = strlen(pCustPath);

    for (nCount = 0; nCount < iLen; nCount++)
    {
        a = toupper(pCustPath[nCount]);
        b = toupper(src[nCount]);
        if (a != b)
        {
            break;
        }
    }
    if (iLen == nCount)
    {
        pSrc = &src[iLen];
    }

    iLen = strlen(pSrc);
    nCount = 0;

    while (iLen)
    {
        if ((pSrc[nCount] == '.') || (pSrc[nCount] == '-') || (pSrc[nCount] == ' ') || (pSrc[nCount] == '\\'))
        {
            dest[nCount] = '_';
        }
        else
        {
            dest[nCount] = pSrc[nCount];
        }

        ++nCount;
        --iLen;
    }

    if (ExtFlag == 1)
    {
        dest[nCount] = '_'; /* add a '_' in the end to distinguish from the original */
        dest[nCount + 1] = '\0';
    }
    else
    {
        dest[nCount] = '\0';
    }
    return;
}


/* 070306 Alpha layer Start */
/*****************************************************************************
 * FUNCTION
 *  ExtractExtension
 * DESCRIPTION
 *  Function Extracting the extension
 * PARAMETERS
 *  src             [?]         
 *  res_type        [IN]        -> resource type
 *  string(?)       [IN]        -> string containing file name
 * RETURNS
 *  U8
 *****************************************************************************/
U8 ExtractExtension(S8 *src, U32 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 type_number;
    U8 ret = 0;
    S8 *arr;
    RESOURCE_INFO *pResource_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = strlen(src) - 1;
    arr = src+i;

    for (j = 0; j < 5 ; j--)
    {
        if(*arr == '.')
    {
            arr++;
            break;
        }
        else
        {
            arr--;
        }
    }

    if(j >= 5)
    {
        return ret;
    }

    switch (res_type)
    {
        case RES_IMAGE:
        case RES_MEDIA:
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;

        case RES_AUDIO:
            ret = AUDIO_TYPE_INVALID;
            pResource_info = audio_resource_info;
            type_number = sizeof(audio_resource_info) / sizeof(RESOURCE_INFO);
            break;

        default:
            printf("res_type in Extract_Name is invalid!!");
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;
    }

    for (i = 0; i < type_number; i++)
    {
        if (!(strcmp(arr, pResource_info[i].filename_ext)))
        {
            ret = pResource_info[i].file_type;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  ChangeExtension
 * DESCRIPTION
 *  Function Change the extension
 * PARAMETERS
 *  src             [IN]        -> string containing file name 
 *  res_type        [IN]        -> resource type
 *  ext_type        [IN]        -> extension type
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL ChangeExtension(S8 *src, U32 res_type, S32 ext_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 type_number;
    U8 ret = 0;
    S8 *arr;
    RESOURCE_INFO *pResource_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = strlen(src) - 1;
    arr = src+i;

    for (j = 0; j < 5 ; j--)
    {
        if(*arr == '.')
        {
            arr++;
            break;
        }
        else
        {
            arr--;
        }
    }

    if (j >= 5)
    {
        return FALSE;
    }

    switch (res_type)
    {
        case RES_IMAGE:
        case RES_MEDIA:
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;

        case RES_AUDIO:
            ret = AUDIO_TYPE_INVALID;
            pResource_info = audio_resource_info;
            type_number = sizeof(audio_resource_info) / sizeof(RESOURCE_INFO);
            break;

        default:
            printf("res_type in Extract_Name is invalid!!");
            ret = IMAGE_TYPE_INVALID;
            pResource_info = image_resource_info;
            type_number = sizeof(image_resource_info) / sizeof(RESOURCE_INFO);
            break;
    }

    for (i = 0; i < type_number; i++)
    {
        if (pResource_info[i].file_type == ext_type)
        {
            break;
        }
    }

    if (i >= type_number)
    {
        return FALSE;
    }

    for (j = 0; j < 5; j++)
    {
        *(arr+j) = *(pResource_info[i].filename_ext+j);
    }

    return TRUE;
}
/* 070306 Alpha layer End */


/*****************************************************************************
 * FUNCTION
 *  isEmsImage
 * DESCRIPTION
 *  Decide if the iamge is used for EMS picture
 *  
 *  use EMS_IMAGE_PATH (defined in CustDataRes.h) to decide if a EMS picture
 * PARAMETERS
 *  path        [IN]        -> string containing file name and path
 * RETURNS
 *  U8 --> 1: EMS picture, 0: Not EMS picture
 *****************************************************************************/
U8 isEmsImage(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 ems_path[] = EMS_IMAGE_PATH;
    U8 pos = 0, ems_len = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ems_len = strlen(ems_path);
    pos = strlen(path) - 1;
    while (path[pos] != '\\')
    {
        if (pos == 0)
        {
            return 0;
        }
        pos--;
    }
    pos -= ems_len + 1;
    for (i = 0; i < ems_len; i++)
    {
        if (ems_path[i] != path[pos])
        {
            return 0;
        }
        else
        {
            pos++;
        }
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  isMainmenuImage
 * DESCRIPTION
 *  Decide if the iamge is used for Mainmenu picture
 * PARAMETERS
 *  path        [IN]        -> string containing file name and path
 * RETURNS
 *  U8 --> 1: Matrix Mainmenu picture, 0: Not Matrix mainmenu picture
 *****************************************************************************/
MMI_BOOL isMainmenuImage(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((strstr(path, "\\MATRIX\\") != NULL) && (strstr(path, ".GIF") != NULL))
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
 *  isSubmenuImage
 * DESCRIPTION
 *  Decide if the iamge is used for Submenu picture
 *  
 *  use SUBMENU_IMAGE_PATH (defined in CustDataRes.h) to decide if a EMS picture
 * PARAMETERS
 *  path        [IN]        -> string containing file name and path
 * RETURNS
 *  U8 --> 1: Submenu picture, 0: Not Submenu picture
 *****************************************************************************/
U8 isSubmenuImage(S8 *path)
{
#ifndef __MMI_SLIM_LISTMENU_NUMBER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
#else /* __MMI_SLIM_LISTMENU_NUMBER__ */ 
    S8 submenu_path[] = SUBMENU_IMAGE_PATH;
    U8 pos = 0, submenu_len = 0, i = 0;

    if (strstr(path, submenu_path) != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

#endif /* __MMI_SLIM_LISTMENU_NUMBER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ToUpper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ch      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 ToUpper(S8 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return toupper(ch);
}


/*****************************************************************************
 * FUNCTION
 *  Iload
 * DESCRIPTION
 *  Load the file image to buffer and writes to CustImgRes.c
 * PARAMETERS
 *  string      [IN]        -> string containing file name and path
 *  pType       [OUT]       -> Image Type
 * RETURNS
 *  void* --> buffer containing image data
 *****************************************************************************/
MMI_BOOL Iload(S8 *string, PU16 pType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j, sequence_counter, n_frames = 0;
    U32 width = 0, height = 0;
    MMI_BOOL failure_flag;
    U8 image_identifier;
    S32 file_size = 0;
    S32 nImageSize = 0;
    S32 extension_type = -1;
    U8 staticFlag = 1;  /* Non animated image */
    S32 ext_type = -1;
    S8 tempDestFile[] = { "TEMPIMAGE" };
    int ret = 1;
    S8 tempCommand[200];
    size_t size;
    S16 filenameLen;
    char *curr_output_data_filename;
    U32 seq_max_width = 0, seq_max_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ExtImageFlag == EXT_IMAGE)
    {
        curr_output_data_filename = HW_IMAGE_FILENAME_EXT;
    }
    else if (ExtImageFlag == SYSTEM_IMAGE)
    {
        curr_output_data_filename = HW_IMAGE_FILENAME;
    }
    else
    {
        curr_output_data_filename = NFB_IMAGE_DATA_FILENAME;
        nfb_img_res_file = fopen(NFB_IMAGE_RES_FILENAME, "ab");
    }

    if (toolFlag == 1)
    {
        curr_output_data_filename = "temp";
    }

    strcpy(filename_buffer, curr_output_data_filename);

    output_data_file = fopen(filename_buffer, "ab");
    while (!output_data_file)
    {
        Sleep(50);
        output_data_file = fopen(filename_buffer, "ab");
    }

    output_image_names = (S8*) malloc(100);
    strcpy(filename_buffer, string);
    if (!(strcmp(filename_buffer, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);
    }
    Extract_Name(output_image_names, filename_buffer, RES_IMAGE);

    if (strstr(filename_buffer, ".9SLICE") != NULL)
    {
        g_is9slice = MMI_TRUE;
        strcpy(g_9slice_filename, filename_buffer);
        strcat(g_9slice_filename, ".TXT");
        printf("Found 9slice image [%s]\n", filename_buffer);
    }

#ifdef __MMI_SLIM_LISTMENU_NUMBER__
    /* set sub-menu list icon image to default 1, 2, 3, ... */
    if (isSubmenuImage(filename_buffer))
    {
        int i, len;

        len = strlen(filename_buffer);

        for (i = len; i > 0; i--)
        {
            if (filename_buffer[i] == 'U' && filename_buffer[i - 1] == 'N' && filename_buffer[i - 2] == 'E' &&
                filename_buffer[i - 3] == 'M' && filename_buffer[i - 4] == 'B' && filename_buffer[i - 5] == 'U' &&
                filename_buffer[i - 6] == 'S')
            {
                filename_buffer[i + 1] = '2';
                break;
            }
            else
            {
                filename_buffer[i + 1] = filename_buffer[i];
            }

        }
        filename_buffer[len + 1] = '\0';
    }
#endif /* __MMI_SLIM_LISTMENU_NUMBER__ */ 

    failure_flag = MMI_TRUE;
    extension_type = -1;
    sequence_counter = 0;

#ifdef __MMI_ALPHA_LAYER_SUPPORT__
    /* fetch PNG by GIF or BMP,
     * application can add PNG file directly without modifying Res_XXX.c */
    ext_type = ExtractExtension(filename_buffer, RES_IMAGE);
    if (ext_type == IMAGE_TYPE_GIF || ext_type == IMAGE_TYPE_BMP)
    {
        ChangeExtension(filename_buffer, RES_IMAGE, IMAGE_TYPE_PNG);
    }
    /* fetch PPN by PBM */
    else if (ext_type == IMAGE_TYPE_DEVICE_BITMAP)
    {
        ChangeExtension(filename_buffer, RES_IMAGE, IMAGE_TYPE_PPN);
    }

    image_data_file = fopen(filename_buffer, "rb");
    if (image_data_file == NULL)
    {
        ChangeExtension(filename_buffer, RES_IMAGE, ext_type);
    }
    else
    {
        fclose(image_data_file);
    }
#endif

    /* convert PPN to PBM */
    ext_type = ExtractExtension(filename_buffer, RES_IMAGE);
    if (ext_type == IMAGE_TYPE_PPN)
    {
        strcpy((char*)tempBMPFile, (const char*)filename_buffer);
        ChangeExtension(tempBMPFile, RES_IMAGE, IMAGE_TYPE_DEVICE_BITMAP);
        sprintf(tempCommand,"convert.exe png:%s bmp:%s", filename_buffer, tempBMPFile);
        system(tempCommand);
        strcpy((char*)filename_buffer, (const char*)tempBMPFile);
    }

    filenameLen = strlen(filename_buffer);

    if (isEmsImage(filename_buffer))
    {
        image_data_file = fopen(filename_buffer, "rb");
        if (image_data_file != NULL)
        {
            if (toolFlag == 0)
            {
                fprintf(output_data_file, "const U8 ");
                fprintf(output_data_file, output_image_names);
                fprintf(output_data_file, "[]=");
                fclose(output_data_file);
            }
            ret = bmp2ems(filename_buffer, curr_output_data_filename, 1, 0);
            if (toolFlag)
            {
                if (ret = 0)
                {
                    resultFailFlag = 1;
                }
            }
        }
        else
        {
            failure_flag = MMI_FALSE;
        }
    }
    else if ((filename_buffer[filenameLen - 1] == 'P' || filename_buffer[filenameLen - 1] == 'M') &&
             (filename_buffer[filenameLen - 2] == 'R' || filename_buffer[filenameLen - 2] == 'B') &&
             filename_buffer[filenameLen - 3] == 'P')
    {
        image_data_file = fopen(filename_buffer, "rb");
        if (image_data_file != NULL)
        {
            if (filename_buffer[filenameLen - 2] == 'R')
            {
                GIFLoader(filename_buffer, tempDestFile);
            }
            else
            {
                ret = BMPLoader(filename_buffer, tempDestFile);
                if (toolFlag)
                {
                    if (ret = 0)
                    {
                        resultFailFlag = 1;
                    }
                }
            }
            fclose(image_data_file);

            if (toolFlag == 0)
            {
                image_data_file = fopen(tempDestFile, "rb");
                if (image_data_file != NULL)
                {
                    strcpy((char*)autoimagename_buffer, (const char*)output_image_names);
                    strcat((char*)autoimagename_buffer, "[]=\n");
                    fprintf(output_data_file, "const U8 ");
                    fprintf(output_data_file, autoimagename_buffer);
                    if (ExtImageFlag == NFB_PROGRESS_IMAGE)
                    {
                        if (nfb_img_res_file != NULL)
                        {
                            fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_image_names);
                            fclose(nfb_img_res_file);
                        }
                        else
                        {
                            printf("nfb_img_res_file not opened\n");
                        }
                    }

                    fseek(image_data_file, 0, SEEK_END);
                    file_size = ftell(image_data_file);
                    fseek(image_data_file, 0, SEEK_SET);

                    while (!feof(image_data_file))
                    {
                        size = fread(tempCommand, sizeof(char), 200, image_data_file);
                        if (size)
                        {
                            fwrite(tempCommand, sizeof(char), size, output_data_file);
                        }
                    }
                    fputs("\n", output_data_file);

                }
            }
        }
        else
        {
            failure_flag = MMI_FALSE;
        }
    }
    else
    {
        image_data_file = fopen(filename_buffer, "rb");
        /* read images with same filename but different in ".bmp" and ".gif" */
        if (image_data_file == NULL)
        {
            Sleep(50);
            if (filename_buffer[filenameLen - 1] == 'P' && filename_buffer[filenameLen - 2] == 'M' &&
                filename_buffer[filenameLen - 3] == 'B')
            {
                filename_buffer[filenameLen - 1] = 'F';
                filename_buffer[filenameLen - 2] = 'I';
                filename_buffer[filenameLen - 3] = 'G';
            }
            else if (isMainmenuImage(filename_buffer))
            {
                filename_buffer[filenameLen - 1] = 'M';
                filename_buffer[filenameLen - 2] = 'B';
                filename_buffer[filenameLen - 3] = 'P';
                image_data_file = fopen(filename_buffer, "rb");
                if (image_data_file != NULL)
                {
                    ret = BMPLoader(filename_buffer, tempDestFile);
                    if (toolFlag)
                    {
                        if (ret = 0)
                        {
                            resultFailFlag = 1;
                        }
                    }
                    if (toolFlag == 0)
                    {
                        image_data_file = fopen(tempDestFile, "rb");
                        if (image_data_file != NULL)
                        {
                            strcpy((char*)autoimagename_buffer, (const char*)output_image_names);
                            strcat((char*)autoimagename_buffer, "[]=\n");
                            fprintf(output_data_file, "const U8 ");
                            fprintf(output_data_file, autoimagename_buffer);
                            if (ExtImageFlag == NFB_PROGRESS_IMAGE)
                            {
                                if (nfb_img_res_file != NULL)
                                {
                                    fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_image_names);
                                    fclose(nfb_img_res_file);
                                }
                                else
                                {
                                    printf("nfb_img_res_file not opened\n");
                                }
                            }

                            fseek(image_data_file, 0, SEEK_END);
                            file_size = ftell(image_data_file);
                            fseek(image_data_file, 0, SEEK_SET);

                            while (!feof(image_data_file))
                            {
                                size = fread(tempCommand, sizeof(char), 200, image_data_file);
                                if (size)
                                {
                                    fwrite(tempCommand, sizeof(char), size, output_data_file);
                                }
                            }
                            fputs("\n", output_data_file);

                        }
                        fclose(image_data_file);
                    }
                    fclose(output_data_file);
                    return MMI_TRUE;
                }
            }
            else if (filename_buffer[filenameLen - 1] == 'F' && filename_buffer[filenameLen - 2] == 'I' &&
                     filename_buffer[filenameLen - 3] == 'G')
            {
                filename_buffer[filenameLen - 1] = 'P';
                filename_buffer[filenameLen - 2] = 'M';
                filename_buffer[filenameLen - 3] = 'B';
            }
            image_data_file = fopen(filename_buffer, "rb");
        }
        if (image_data_file == NULL)
        {

            /* Add extension add search */
            FILE *fail = fopen("fail.txt", "a+");

            if (fail != NULL)
            {
                if (toolFlag == 0)
                {
                    fprintf(fail, "%s\n", filename_buffer);
                    fclose(fail);
                }
                failure_flag = MMI_FALSE;
            }

        /* Find the right extension file name */
        #ifdef __MMI_ALPHA_LAYER_SUPPORT__
            for (j = SUPPORT_N_SEQUENTIAL_IMAGE_TYPE-1; j >= 0; j--)//search from PNG       
        #else
            for (j = 0; j < SUPPORT_N_SEQUENTIAL_IMAGE_TYPE; j++)//search from BMP       
        #endif
            {
                extension_type = -1;
                sprintf(autofilename_buffer, "%s\\\\0.%s", filename_buffer, sequential_image[j].filename_ext);
                image_data_file = fopen(autofilename_buffer, "rb");
                if (image_data_file != NULL)
                {
                    failure_flag = MMI_TRUE;
                    extension_type = sequential_image[j].file_type;
                    staticFlag = 0;
                    *pType = (U16) extension_type;
                    sequential_extension_type = j;
                    fclose(image_data_file);
                    break;
                }
            }

        }
        else
        {
            fseek(image_data_file, 0, SEEK_END);
            nImageSize = ftell(image_data_file);
            fseek(image_data_file, 0, SEEK_SET);

        }

        /* sequence of animation images
         * write header and animation information */
        if ((failure_flag == MMI_TRUE) && !(staticFlag))
        {
            /* Sequence found */
            /* Find how many files are in sequence */

            j = 0;
            sequence_counter = 0;
            n_frames = 0;
            while (1)
            {
                sprintf(autofilename_buffer, "%s\\\\%d.%s", filename_buffer, j, sequential_image[sequential_extension_type].filename_ext);
                image_data_file = fopen(autofilename_buffer, "rb");
                if (image_data_file != NULL)
                {
                    sequence_counter++;
                    fseek(image_data_file, 0, SEEK_END);
                    sequential_filesize[j] = ftell(image_data_file);
                    fseek(image_data_file, 0, SEEK_SET);
                    fclose(image_data_file);
                }
                else
                {   /*   Sequence complete */
                    if (j > 0)
                    {
                        break;
                    }
                }
                j++;
            }
            /* read during */
            {
                int i;

                sprintf(autofilename_buffer, "%s\\\\interval.txt", filename_buffer);

                image_data_file = fopen(autofilename_buffer, "r");
                if (image_data_file == NULL)
                {
                    printf("ERROR: Can't find %s\n", autofilename_buffer);
                    staticFlag = 1;
                    failure_flag = MMI_FALSE;
                }
                else
                {
                    for (i = 0; i < sequence_counter; i++)
                    {
                        if (fscanf(image_data_file, "%d", &sequential_interval[i]) != 1)
                        {
                            printf("ERROR: %s, interval [%d] value missing!!\n", autofilename_buffer, i);
                            staticFlag = 1;
                            failure_flag = MMI_FALSE;
                            break;
                        }
                    }
                }
                if (image_data_file != NULL)
                {
                    fclose(image_data_file);
                }
            }

            /* sequence of animation images
             * write each image raw data */
            if(!staticFlag)
            {         
                sequential_frame = sequence_counter;

                /* Construct the data structure name  */
                fprintf(output_data_file, "__align(4) const U8 %s%s", output_image_names, OUTPUT_IMAGE_NAMES_END);

                /* Get width and height */
                j = 0;
                while (1)
                {
                    sprintf(autofilename_buffer, "%s\\\\%d.%s", filename_buffer, j, sequential_image[sequential_extension_type].filename_ext);
                    image_data_file = fopen(autofilename_buffer, "rb");
                    if (image_data_file != NULL)
                    {
                        n_frames = Image_Get_Dimensions(autofilename_buffer, &width, &height);
                        if (n_frames < 1)
                        {
                            printf("Image get dimensions failed:\t%s\n", filename_buffer);
                        }
                        if (width > seq_max_width) 
                        {
                            seq_max_width = width;
                        }
                        if (height > seq_max_height)
                        {
                            seq_max_height = height;
                        }
                        fclose(image_data_file);
                    }
                    else
                    {   /*   Sequence complete */
                        if (j > 0)
                        {
                            break;
                        }
                    }
                    j++;
                }

                /* write header of sequential images */
                Write_Sequential_Image_Header(output_data_file, sequential_image[sequential_extension_type].file_type, sequential_frame, sequential_filesize, sequential_offset, seq_max_width, seq_max_height);

                /* Load all files in the sequence   */
                j = 0;
                sequence_counter = 0;
                while (1)
                {
                    sprintf(autofilename_buffer, "%s\\\\%d.%s", filename_buffer, j, sequential_image[sequential_extension_type].filename_ext);
                    image_data_file = fopen(autofilename_buffer, "rb");
                    if (image_data_file != NULL)
                    {
                        Write_Sequential_Image_File(output_data_file, image_data_file, sequential_filesize[j]);
                        sequence_counter++;
                        fclose(image_data_file);
                    }
                    else
                    {   /*   Sequence complete */
                        if (j > 0)
                        {
                            break;
                        }
                    }
                    j++;
                }
                fprintf(output_data_file, "\n};\n");
            }
        }   /* End of Animated image processor block */

        /* process static image */
        if ((failure_flag == MMI_TRUE) && (staticFlag))
        {
            /* Currently assuming that all single files are BMP   */
            if (nImageSize == 0)
            {
                image_identifier = IMAGE_TYPE_INVALID;
            }
            else
            {
                /* read images with same filename but different in ".bmp" and ".gif" */
                image_identifier = ExtractExtension(filename_buffer, RES_IMAGE);
            }
            /* To be changed later for multiple file types */
            *pType = ExtractExtension(filename_buffer, RES_IMAGE);

            /* get frame count, width and height of the image */
            if (image_identifier == IMAGE_TYPE_BMP ||
                image_identifier == IMAGE_TYPE_GIF ||
                image_identifier == IMAGE_TYPE_JPG ||
                image_identifier == IMAGE_TYPE_PNG)
            {
                n_frames = Image_Get_Dimensions(filename_buffer, &width, &height);
                if (n_frames <= 0)
                {
                    printf("\nGet dimensions failed:\t%s", filename_buffer);
                    failure_flag == MMI_FALSE;
                }
            }

            if (failure_flag == MMI_TRUE)
            {
                /* Load the data */
                /* Construct the data structure name */
                sprintf(autoimagename_buffer, "const U8 %s%s", output_image_names, OUTPUT_IMAGE_NAMES_END);
                if (image_identifier == IMAGE_TYPE_GIF || image_identifier == IMAGE_TYPE_3GP || 
                    image_identifier == IMAGE_TYPE_MP4 || image_identifier == IMAGE_TYPE_AVI || 
                    image_identifier == IMAGE_TYPE_RV  || image_identifier == IMAGE_TYPE_RM  ||
                    image_identifier == IMAGE_TYPE_RMVB || image_identifier == IMAGE_TYPE_PNG)
                {
                    fprintf(output_data_file, "__align(4) ");
                }
                fprintf(output_data_file, autoimagename_buffer);

                Load_Image_Data(output_data_file, image_data_file, image_identifier, n_frames, width, height);

                if (ExtImageFlag == NFB_PROGRESS_IMAGE)
                {
                    printf("NFB_PROGRESS_IMAGE\n");
                    if (nfb_img_res_file != NULL)
                    {
                        printf("nfb_img_res_file\n");
                        fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_image_names);
                        fclose(nfb_img_res_file);
                    }
                    else
                    {
                        printf("nfb_img_res_file not opened\n");
                    }
                }

                fprintf(output_data_file, "\n };\n");
                fclose(image_data_file);
            }
        }
    }

    /* populating with .bmp or .gif but actually extsion name is not */
    if (failure_flag == MMI_FALSE)
    {
        /* printf("*************failed !!!********************\n"); */
        /* try each supported extension */
        for (j = 0; j < SUPPORT_N_MEDIA_TYPE; j++)
        {
            S32 l;

            for (l = 0; l < 3; l++)
            {
                filename_buffer[filenameLen - 1 - l] = support_media_ext[j][2 - l];
            }
            image_data_file = fopen(filename_buffer, "rb");
            if (image_data_file != NULL)
            {
                break;
            }
        }

        if (image_data_file != NULL)
        {
            failure_flag = MMI_TRUE;

            fseek(image_data_file, 0, SEEK_END);
            nImageSize = ftell(image_data_file);
            fseek(image_data_file, 0, SEEK_SET);

            /* Currently assuming that all single files are BMP   */
            if (nImageSize == 0)
            {
                image_identifier = IMAGE_TYPE_INVALID;
            }
            else
            {
                /* read images with same filename but different in ".bmp" and ".gif" */
                image_identifier = ExtractExtension(filename_buffer, RES_IMAGE);
            }

            /* To be changed later for multiple file types */
            *pType = ExtractExtension(filename_buffer, RES_IMAGE);

            /* get frame count, width and height of the image */
            if (image_identifier == IMAGE_TYPE_BMP ||
                image_identifier == IMAGE_TYPE_GIF ||
                image_identifier == IMAGE_TYPE_JPG ||
                image_identifier == IMAGE_TYPE_PNG)
            {
                n_frames = Image_Get_Dimensions(filename_buffer, &width, &height);
                if (n_frames <= 0)
                {
                    printf("\nGet dimensions failed:\t%s", filename_buffer);
                    failure_flag == MMI_FALSE;
                }
            }

            if (failure_flag == MMI_TRUE)
            {
                /* Load the data  */
                /* Construct the data structure name */
                sprintf(autoimagename_buffer, "const U8 %s%s", output_image_names, OUTPUT_IMAGE_NAMES_END);
                if (image_identifier == IMAGE_TYPE_GIF || image_identifier == IMAGE_TYPE_3GP || 
                    image_identifier == IMAGE_TYPE_MP4 || image_identifier == IMAGE_TYPE_AVI || 
                    image_identifier == IMAGE_TYPE_RV  || image_identifier == IMAGE_TYPE_RM  ||
                    image_identifier == IMAGE_TYPE_RMVB || image_identifier == IMAGE_TYPE_PNG)
                {
                    fprintf(output_data_file, "__align(4) ");
                }
                fprintf(output_data_file, autoimagename_buffer);

                Load_Image_Data(output_data_file, image_data_file, image_identifier, n_frames, width, height);

                if (ExtImageFlag == NFB_PROGRESS_IMAGE)
                {
                    printf("NFB_PROGRESS_IMAGE\n");
                    if (nfb_img_res_file != NULL)
                    {
                        printf("nfb_img_res_file\n");
                        fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_image_names);
                        fclose(nfb_img_res_file);
                    }
                    else
                    {
                        printf("nfb_img_res_file not opened\n");
                    }
                }

                fprintf(output_data_file, "\n };\n");
                fclose(image_data_file);
            }
        }
    }

    if (image_data_file != NULL)
    {
        fclose(image_data_file);
    }
    if (output_data_file != NULL)
    {
        fclose(output_data_file);
    }
    return failure_flag;
}


/*****************************************************************************
 * FUNCTION
 *  Aload
 * DESCRIPTION
 *  Load the file audio to buffer and writes to CustAdoRes.c
 * PARAMETERS
 *  string      [IN]        -> string containing file name and path
 *  pType       [OUT]       -> Audio Type
 * RETURNS
 *  void* --> buffer containing Audio data
 *****************************************************************************/
MMI_BOOL Aload(S8 *string, PU16 pType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 audio_offset = 0;
    U8 *pBuffer = NULL;
    S32 j, n_frames;
    MMI_BOOL failure_flag;
    U8 audio_identifier;
    S32 file_size1 = 0;
    S32 file_size = 0;
    S32 nAudioSize = 0;
    U8 *pBuffer1 = NULL;
    U8 staticFlag = 1;
    int ret = 1;
    size_t size;
    U32 o = 0;
    S16 filenameLen;
    char *curr_output_data_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ExtAudioFlag == TRUE)
    {
        curr_output_data_filename = HW_AUDIO_FILENAME_EXT;
    }
    else
    {
        curr_output_data_filename = HW_AUDIO_FILENAME;
    }

    if (toolFlag == 1)
    {
        curr_output_data_filename = "temp";
    }

    strcpy(filename_buffer, curr_output_data_filename);

    output_data_file = fopen(filename_buffer, "ab");
    while (!output_data_file)
    {
        Sleep(50);
        output_data_file = fopen(filename_buffer, "ab");
    }

    output_audio_names = (S8*) malloc(100);
    strcpy(filename_buffer, string);
    if (!(strcmp(filename_buffer, "")))
    {

        strcpy(filename_buffer, NOAUDIO_FILENAMEBUFFER);
    }

    Extract_Name(output_audio_names, filename_buffer, RES_AUDIO);

    failure_flag = MMI_TRUE;
    filenameLen = strlen(filename_buffer);

    audio_data_file = fopen(filename_buffer, "rb");
    if (audio_data_file == NULL)
    {
        /* Add extension add search */
        FILE *fail = fopen("fail.txt", "a+");

        if (fail != NULL)
        {
            if (toolFlag == 0)
            {
                fprintf(fail, "%s\n", filename_buffer);
                fclose(fail);
            }
            failure_flag = MMI_FALSE;
        }
    }
    else
    {
        fseek(audio_data_file, 0, SEEK_END);
        nAudioSize = ftell(audio_data_file);
        fseek(audio_data_file, 0, SEEK_SET);
    }

    if ((failure_flag == MMI_TRUE) && (staticFlag))
    {
        /* Currently assuming that all single files are BMP   */
        if (nAudioSize == 0)
        {
            audio_identifier = AUDIO_TYPE_INVALID;
        }
        else
        {
            audio_identifier = ExtractExtension(filename_buffer, RES_AUDIO);    /* 101205 audio resource Calvin */
        }
        /* To be changed later for multiple file types */
        *pType = ExtractExtension(filename_buffer, RES_AUDIO);

        /*   Load the data  */

        /* Construct the data structure name */
        strcpy(autoimagename_buffer, output_audio_names);
        strcat(autoimagename_buffer, OUTPUT_AUDIO_NAMES_END);
        fprintf(output_data_file, "__align(4) const U8 ");
        fprintf(output_data_file, autoimagename_buffer);

        fseek(audio_data_file, 0, SEEK_END);
        file_size1 = file_size1 + ftell(audio_data_file) + 8;
        fseek(audio_data_file, 0, SEEK_SET);

        pBuffer = (U8*) malloc(file_size1);
        if (pBuffer == NULL)
        {
            /* Add Debug Message */
        }
        pBuffer1 = pBuffer;

        Load_Audio_Data(&audio_offset, output_data_file, audio_data_file, pBuffer1, audio_identifier);

        free(pBuffer);
        fprintf(output_data_file, "\n };\n");
        fclose(audio_data_file);
    }

    if (audio_data_file != NULL)
    {
        fclose(audio_data_file);
    }

    if (output_data_file != NULL)
    {
        fclose(output_data_file);
    }

    return failure_flag;
}

/* 101205 audio resource Calvin End */


/*****************************************************************************
 * FUNCTION
 *  ClearHWIMageFile
 * DESCRIPTION
 *  Clear image file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ClearHWIMageFile()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = fopen(HW_IMAGE_FILENAME, "w+");
    if (fp)
    {
        fprintf(
            fp,
            "#ifndef __MTK_TARGET__\n\t#define __align(x)\n#endif\n");
        fclose(fp);
    }

    fp = fopen(HW_AUDIO_FILENAME, "w+");
    if (fp)
    {
        fprintf(
            fp,
            "#ifndef __MTK_TARGET__\n\t#define __align(x)\n#endif\n");
        fclose(fp);
    }

}
#endif /* DEVELOPER_BUILD_FIRST_PASS */ 

