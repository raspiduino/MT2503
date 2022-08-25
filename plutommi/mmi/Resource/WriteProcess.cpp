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
 *   WriteProcess.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

//#include "mmi_features.h"
extern "C"
{
#include "CustDataRes.h"
#include "CustDataProts.h" // for AUTO_TYPE
#include "WriteResUtil.h"
#include "ExternalCMDManagerCAPI.h"
#include "ResgenLogCAPI.h"
#include "ResgenConfiguratorCAPI.h"
}

#include <string>
//#include <cctype>
#include <vector>
#include <list>
#include <assert.h>

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#include "ThreadPool.h"
#include "OfflineResParam.h"

#include "ImageGroupCreator.h"
using namespace std;


#define DEFAULT_FILEBUFFER          "________CUSTOMER__IMAGES__DEFAULT_BMP"
#define DEFAULT_IAMGE_DATA          "..\\..\\Customer\\Images\\Default.bmp"
#define OUTPUT_DATA_FILENAME        "..\\..\\Customer\\CustResource\\CustImgDataHW.h"
#define OUTPUT_DATA_FILENAME_EXT    "..\\..\\Customer\\CustResource\\CustImgDataHWExt.h"
#define OUTPUT_IMG_GROUP_CONTENT_META_FILENAME "..\\..\\Customer\\CustResource\\CustImgDataMeta.txt"


#define IMGPROC_TAG  "WRITEPROCESS"

#define IMGPROC_LOG_D(format, args...) RES_LOG_D((IMGPROC_TAG), (format) , ##args)
#define IMGPROC_LOG_V(format, args...) RES_LOG_V((IMGPROC_TAG), (format) , ##args)
#define IMGPROC_LOG_W(format, args...) RES_LOG_W((IMGPROC_TAG), (format) , ##args)
#define IMGPROC_LOG_E(format, args...) RES_LOG_E((IMGPROC_TAG), (format) , ##args)


// global variables
extern FILE *OutputImgIDFile; // defined in PopulateRes.c
extern CUSTOM_IMAGE_MAP ImageIdMapEXT[]; // defined in CustResDeclare.c
extern CUSTOM_IMAGE_MAP ImageIdMap[]; // defined in CustResDeclare.c

extern IMAGENAME_LIST ImageNameList[]; // also used in WriteImgRes.c
extern IMAGENAME_LIST ImageNameListEXT[]; // also used in WriteImgRes.c
extern U16 CurrMaxImageNumEXT; // also used in WriteImgRes.c
extern U16 CurrMaxImageNum; // also used in WriteRes.c

extern U32 image_idx; // XXX, defined in WriteImgRes.c
extern U16 CurrMaxImageId; // also used in WriteImgRes.c
extern U32 g_resimg_count; // XXX, defined in WriteImgRes.c
extern CUSTOM_RESOURCE_SIZE g_resimg_table[MAX_IMAGE_IDS_SIZE]; // XXX, defined in WriteImgRes.c

extern FILE *fpImageResourceUsage; // defined in PopulateRes.c
extern FILE *fpImageResourceUsageExt; // defined in PopulateRes.c
extern "C" U32 GetOffsetFromResourceBase(U16 ImageID, U8* enum_value); // in WriteRes.c
extern mmi_resource_base_struct g_mmi_resource_base_table[]; // for RESPRTONERECORD()

extern U16 CurrMaxImageIdEXT;

extern FILE *RepeatIDListFile; // also used in WriteRes.c

// ENFB
#if defined(__MULTIPLE_BINARY_FILES__) && defined(__MMI_RESOURCE_ENFB_SUPPORT__)
extern "C" MMI_BOOL CustPack_ENFB_image_test(const S8 *filename, int disable_enfb);

#endif /* defined(__MULTIPLE_BINARY_FILES__) && defined(__MMI_RESOURCE_ENFB_SUPPORT__) */

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern int disableENFB;
#endif // __MMI_RESOURCE_ENFB_SUPPORT__

// local functions
static void ProcessBinaryData();

struct _ResgenImageOutStream
{
    int data_size;
    char * data;

    _ResgenImageOutStream():data_size(0), data(NULL)
    {
    }

    ~_ResgenImageOutStream()
    {
        delete data;
    }
};

void SetImageWithBufferEx(
                          U16 nImgId,
                          S8 *filename,
                          S8 *enum_value,
                          BOOL imgFlag,
                          S32 force_type);

void SetImageQWithBufferEx(
                           U16 nImgId,
                           S8 *filename,
                           S8 *enum_value,
                           BOOL imgFlag,
                           S32 force_type,
                           S32 quality);

void initImageProcessData(SetImageProcessData * data)
{
    if (data == NULL)
    {
        assert(false);
        return;
    }
    strcpy(data->real_filename, "");
    data->res_size = 0;
    data->failed = MMI_FALSE;
    data->duplicated = MMI_FALSE;
    data->duplicatedInstance = NULL;
    data->quality=ImageResParam::QUALITY_MEDIUM;
    data->color_num = RES_IMG_COLOR_NUM_UNKNOWN;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    data->enfb_flag = 0;
    data->disable_enfb = 0;
#endif
}

extern "C" void SetNFBImage(S8 *filename)
{
    IMGPROC_LOG_V("SetNFBImage: Populate NFB image: %s", filename);
    fflush(stdout);

    SetImageProcessData processData;
    ResgenImageOutStream outstream;
    processData.outstream = &outstream;
    initImageProcessData(&processData);
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    processData.disable_enfb = 1;
#endif
    SetNFBImageImp(filename, &processData);

    char *curr_output_data_filename = NFB_IMAGE_DATA_FILENAME;
    FILE *output_data_file = NULL;
    output_data_file = fopen(curr_output_data_filename, "ab");
    IMGPROC_LOG_V("SetNFBImage: Open NFB image output file: %s, file descriptor: 0x%x", NFB_IMAGE_DATA_FILENAME, output_data_file);
    fflush(stdout);

    while (output_data_file == NULL)
    {
        IMGPROC_LOG_V("SetNFBImage: File descriptor can't be NULL for %s, retry... ", output_data_file, NFB_IMAGE_DATA_FILENAME);
        fflush(stdout);
        Sleep(50);
        output_data_file = fopen(curr_output_data_filename, "ab");
    }

    IMGPROC_LOG_V("SetNFBImage: Write NFB image data to %s, file descriptor: 0x%x", NFB_IMAGE_DATA_FILENAME, output_data_file);
    fflush(stdout);
    ImageOutStreamOutputFile(&outstream, output_data_file);

    IMGPROC_LOG_V("SetNFBImage: Close NFB image output file: %s, file descriptor: 0x%x", NFB_IMAGE_DATA_FILENAME, output_data_file);
    fflush(stdout);
    MYFCLOSE(output_data_file);
}

/*****************************************************************************
* FUNCTION
*  SetImage
* DESCRIPTION
*  Function to Update the Customizable Image Filename & Mapping Array.
* PARAMETERS
*  ImgId           [IN]
*  filename        [?]
*  enum_value      [?]
*  U16(?)          [OUT]       Image Number which is Mapped with the ImageId.
* RETURNS
*  Image Number which is mapped with the ImageId.(?)
*****************************************************************************/
extern "C" void SetImage(U16 ImgId, S8 *filename, S8 *enum_value)  /* 120304 Calvin modified for media resource */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetImageWithBuffer(ImgId, filename, enum_value, FALSE);       /* 040805 CustPack: Calvin revised */
}

/*****************************************************************************
* FUNCTION
*  SetImageWithBufferForceType
* DESCRIPTION
*  Function to copy the image file to buffer use force type
* PARAMETERS
*  nImgId              [IN]
*  filename            [?]
*  enum_value          [?]
*  imgFlag             [IN]
*  S8(?)               [OUT]       -> filename of the image to be displayed.
*  U16(?)              [IN]        -> ImageId
* RETURNS
*  void
*****************************************************************************/
extern "C" void SetImageWithBufferForceType(U16 nImgId, S8 *filename, S8 *enum_value, BOOL imgFlag, S32 force_type)
{
    SetImageWithBufferEx(nImgId, filename, enum_value, imgFlag, force_type);
}

/*****************************************************************************
* FUNCTION
*  SetImageWithBuffer
* DESCRIPTION
*  Function to copy the image file to buffer
* PARAMETERS
*  nImgId              [IN]
*  filename            [?]
*  enum_value          [?]
*  imgFlag             [IN]
*  S8(?)               [OUT]       -> filename of the image to be displayed.
*  U16(?)              [IN]        -> ImageId
* RETURNS
*  void
*****************************************************************************/
extern "C" void SetImageWithBuffer(U16 nImgId, S8 *filename, S8 *enum_value, BOOL imgFlag)      /* 120304 Calvin modified for media resource */
{
    SetImageWithBufferEx(nImgId, filename, enum_value, imgFlag, AUTO_TYPE);
}

extern "C" void SetImageQWithBuffer(U16 nImgId, S8 *filename, S8 *enum_value, BOOL imgFlag, S32 quality)
{
    SetImageQWithBufferEx(nImgId, filename, enum_value, imgFlag, AUTO_TYPE, quality);
}

extern "C" void SetImageQWithBufferForceType(U16 nImgId, S8 *filename, S8 *enum_value, BOOL imgFlag, S32 force_type, S32 quality)
{
    SetImageQWithBufferEx(nImgId, filename, enum_value, imgFlag, force_type,quality);
}

struct ProcessImageData
{
    ProcessImageData(U16 nImgId, S8 *filename, S8 *enum_value, BOOL imgFlag, S32 force_type):
m_nImgId(nImgId),
m_filename(filename),
m_enum_value(enum_value),
m_imgFlag(imgFlag),
m_force_type(force_type)
{
    initImageProcessData(&m_processData);
    m_processData.outstream = &m_outstream;
}

ProcessImageData(U16 nImgId, S8 *filename, S8 *enum_value, BOOL imgFlag, S32 force_type, S32 quality):
m_nImgId(nImgId),
m_filename(filename),
m_enum_value(enum_value),
m_imgFlag(imgFlag),
m_force_type(force_type)
{
    initImageProcessData(&m_processData);
    m_processData.outstream = &m_outstream;
    m_processData.quality = quality;
}


ProcessImageData(const ProcessImageData & src)
{
    m_nImgId = src.m_nImgId;
    m_filename = src.m_filename;
    m_enum_value = src.m_enum_value;
    m_imgFlag = src.m_imgFlag;
    m_force_type = src.m_force_type;
    m_processData = src.m_processData;
    m_outstream = src.m_outstream;
    m_processData.outstream = &m_outstream;
    m_processData.quality =src.m_processData.quality;

}
ProcessImageData & operator= (const ProcessImageData & src)
{
    m_nImgId = src.m_nImgId;
    m_filename = src.m_filename;
    m_enum_value = src.m_enum_value;
    m_imgFlag = src.m_imgFlag;
    m_force_type = src.m_force_type;
    m_processData = src.m_processData;
    m_outstream = src.m_outstream;
    m_processData.outstream = &m_outstream;
    m_processData.quality =src.m_processData.quality;

    return *this;
}

U16     m_nImgId;
string  m_filename;
string  m_enum_value;
BOOL    m_imgFlag;
S32     m_force_type;
SetImageProcessData m_processData;
ResgenImageOutStream m_outstream;
};

typedef list<ProcessImageData> ProcessImageList;
static ProcessImageList g_resgen_png_image_list;

struct LogBinaryData
{
    U16     m_res_id;
    string  m_filename;
    int     m_binary_type;

    LogBinaryData(U16 res_id, char * filename, int binary_type):
    m_res_id(res_id),
        m_filename(filename),
        m_binary_type(binary_type)
    {
    }
};

typedef list<LogBinaryData> LogBinaryDataList;
static LogBinaryDataList g_log_binary_data_list;

static string stringToUpper(string str)
{
    const int length = str.length();
    for(int i=0; i!=length ; ++i)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

void SetImageWithBufferEx(U16 nImgId, S8 *filename, S8 *enum_value, BOOL imgFlag, S32 force_type){
    SetImageQWithBufferEx(nImgId,filename,enum_value,imgFlag,force_type,OFFLINE_IMAGE_PARAM_QUALITY_MEDIUM);

}
void SetImageQWithBufferEx(U16 nImgId, S8 *filename, S8 *enum_value, BOOL imgFlag, S32 force_type, int quality)
{
    // preprocess
#if defined(__MULTIPLE_BINARY_FILES__) && defined(__MMI_RESOURCE_ENFB_SUPPORT__)
    if (CustPack_ENFB_image_test(filename, 0 /* disable_enfb */) == MMI_TRUE)
    {
        imgFlag = MMI_TRUE;
    }
#endif /* defined(__MULTIPLE_BINARY_FILES__) && defined(__MMI_RESOURCE_ENFB_SUPPORT__) */

    CUSTOM_IMAGE_MAP *pImageIdMap;
    unsigned short *pCurrMaxImageNum;
    IMAGENAME_LIST *pImageNameList;

    if (imgFlag == TRUE)
    {
        pImageIdMap = ImageIdMapEXT;
        pImageNameList = ImageNameListEXT;
        pCurrMaxImageNum = &CurrMaxImageNumEXT;
    }
    else
    {
        pImageIdMap = ImageIdMap;
        pImageNameList = ImageNameList;
        pCurrMaxImageNum = &CurrMaxImageNum;
    }

    fprintf(OutputImgIDFile, "file name%d = %s \n", image_idx++, filename);
#ifdef __IOT__
    strncpy(filename,DEFAULT_IAMGE_DATA,sizeof(DEFAULT_IAMGE_DATA));
#endif
    if (strlen(filename) >= MAX_FILENAME_LEN)
    {
        filename[MAX_FILENAME_LEN - 1] = '\0';
    }

    if (pImageIdMap[nImgId].nImageNum != (U16)-1)
    {
        fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nImgId, enum_value, "Image");
        return;
    }

    S16 nStrlen = strlen(filename);
    S8 upperFileName[MAX_FILENAME_LEN];
    while (nStrlen >= 0)
    {
        upperFileName[nStrlen] = toupper(filename[nStrlen]);
        --nStrlen;
    }

    pImageIdMap[nImgId].nImageNum = 0;

    ProcessImageData data(nImgId, upperFileName, enum_value, imgFlag, force_type, quality);
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    if (disableENFB)
    {
        data.m_processData.disable_enfb = 1;
    }
#endif

    // init the process data
    data.m_processData.res_size = 0;
    strcpy(data.m_processData.real_filename, filename);

    ProcessImageList::iterator i = g_resgen_png_image_list.begin();
    U32 index = 0;
    for (; i != g_resgen_png_image_list.end(); ++i, ++index)
    {
        ProcessImageData & ref = *i;
        if (ref.m_imgFlag == imgFlag && strcmp(ref.m_filename.c_str(), upperFileName) == 0)
        {
            data.m_processData.duplicated = MMI_TRUE;
            data.m_processData.duplicatedInstance = &ref.m_processData;
            break;
        }
    }

    //if (getResgenImgPostProcess() )
#define RESGEN_IMG_POST_PROCESS

#ifdef RESGEN_IMG_POST_PROCESS
    S32 ext_type = ExtractExtension(upperFileName, RES_IMAGE);

    // add to list
    g_resgen_png_image_list.push_back(data);

#else // RESGEN_IMG_POST_PROCESS
    SetImageWithBufferExImp(data.m_nImgId, (S8*)data.m_filename.c_str(),
        (S8*)data.m_enum_value.c_str(), data.m_imgFlag,
        data.m_force_type, &data.m_processData);

#endif // RESGEN_IMG_POST_PROCESS
}

void ProcessResgenPngImagesMapIds(ProcessImageData & data)
{
    unsigned short *pCurrMaxImageNum;
    CUSTOM_IMAGE_MAP *pImageIdMap;
    IMAGENAME_LIST *pImageNameList;
    unsigned short *pCurrMaxImageId;
    image_type_enum extImageFlag = SYSTEM_IMAGE;

    if (data.m_imgFlag == TRUE)
    {
        extImageFlag = EXT_IMAGE;
        pCurrMaxImageId = &CurrMaxImageIdEXT;
        pCurrMaxImageNum = &CurrMaxImageNumEXT;
        pImageNameList = ImageNameListEXT;
        pImageIdMap = ImageIdMapEXT;
    }
    else
    {
        extImageFlag = SYSTEM_IMAGE;
        pCurrMaxImageId = &CurrMaxImageId;
        pCurrMaxImageNum = &CurrMaxImageNum;
        pImageNameList = ImageNameList;
        pImageIdMap = ImageIdMap;
    }

    if (data.m_processData.failed)
    {
        strcpy(ImageNameList[CurrMaxImageNum].filename, DEFAULT_FILEBUFFER);
        ImageIdMap[data.m_nImgId].nImageNum = CurrMaxImageNum;
        CurrMaxImageNum++;
        CurrMaxImageId++;
        if (data.m_imgFlag == TRUE)
        {
            pImageIdMap[data.m_nImgId].nImageNum = -1;
        }
    }
    else if (data.m_processData.duplicated)
    {

        U32 i;
        for (i = 0; i < *pCurrMaxImageNum; i++)
        {
            if (!strcmp(pImageNameList[i].filename, data.m_filename.c_str()))
            {
                data.m_processData.duplicated = MMI_TRUE;
                break;
            }
        }

        //pImageIdMap[data.m_nImgId].nImageNum = data.m_processData.duplicatedIndex;
        pImageIdMap[data.m_nImgId].nImageNum = i;
        (*pCurrMaxImageId)++;

        {
            U32 i;

            for (i = 0; i < g_resimg_count; i++)
            {
                if (strcmp(data.m_filename.c_str(), g_resimg_table[i].filename) == 0)
                {
                    data.m_processData.res_size = g_resimg_table[i].size;
                    strcpy(data.m_processData.real_filename, g_resimg_table[i].real_filename);
                    break;
                }
            }
        }
        RESPRTONERECORD_IMG_EXT(fpImageResourceUsage, fpImageResourceUsageExt, data.m_nImgId, data.m_processData.real_filename, (U8*)data.m_enum_value.c_str(), data.m_processData.res_size,data.m_processData.color_num);
    }
    else
    {
        strcpy(pImageNameList[*pCurrMaxImageNum].filename, data.m_filename.c_str());
        pImageIdMap[data.m_nImgId].nImageNum = *pCurrMaxImageNum;
        (*pCurrMaxImageNum)++;
        (*pCurrMaxImageId)++;

        g_resimg_table[g_resimg_count].size = data.m_processData.res_size;
        strcpy(g_resimg_table[g_resimg_count].filename, data.m_filename.c_str());
        strcpy(g_resimg_table[g_resimg_count].real_filename, data.m_processData.real_filename);
        g_resimg_count ++;
        RESPRTONERECORD_IMG_EXT(fpImageResourceUsage, fpImageResourceUsageExt, data.m_nImgId, data.m_processData.real_filename, (U8*)data.m_enum_value.c_str(), data.m_processData.res_size,data.m_processData.color_num);
    }
}

class ConvertRequest : public ThreadPool::IRunObject
{
public:
    ConvertRequest(ProcessImageData & data) : m_data(data)
    {
    }

    void Run()
    {
        SetImageWithBufferExImp(m_data.m_nImgId, (S8*)m_data.m_filename.c_str(),
            (S8*)m_data.m_enum_value.c_str(), m_data.m_imgFlag,
            m_data.m_force_type, &m_data.m_processData);
        delete this;
    }

    bool AutoDelete()
    {
        return false;
    }

private:
    ProcessImageData & m_data;
};

static DWORD getMaxThreadNumber(){
    DWORD threadCount = 1;
    DWORD maxThreadCount = 1;
    // Set max numebr of concurrent threads in image processing thread pool
    SYSTEM_INFO sysinfo;
    GetSystemInfo( &sysinfo );
    maxThreadCount = resconfig_adaptor_get_max_thread_numebr();
    if(sysinfo.dwNumberOfProcessors * 2 > maxThreadCount)
    {
        threadCount = maxThreadCount;
    }
    else
    {
        threadCount = sysinfo.dwNumberOfProcessors * 2;;
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    threadCount = 1;
#endif

    return threadCount;
}

void ProcessResgenPngImages()
{
#ifndef __POPULATE_NO_IMAGE_DATA__
    //Max numebr of concurrent threads in image processing thread pool
    DWORD threadCount = getMaxThreadNumber();

	ImageGroupContentMetaCreator * contentMetacreator = new ImageGroupContentMetaCreator();
#endif //__POPULATE_NO_IMAGE_DATA__
    // process binary data
    ProcessBinaryData();
#ifndef __POPULATE_NO_IMAGE_DATA__
    // execute_ext_command("echo resgen_time before Iloads %time%");

    // Create thread pool
    IMGPROC_LOG_V("Creating Thread pool, threadCount = %d", threadCount);
    ThreadPool * myPool = new ThreadPool(threadCount);
    if(!myPool) 
    {
        IMGPROC_LOG_E("Thread pool was not created due to lack of memory available by the compilation environment");
    }
    else
    {
        IMGPROC_LOG_V("Thread pool is created successfully");
    }

    fflush(stdout);

    ProcessImageList::iterator i = g_resgen_png_image_list.begin();
    for (; i != g_resgen_png_image_list.end(); ++i)
    {
        ProcessImageData & data = *i;
        myPool->Run(new ConvertRequest(data) );
    }

    //execute_ext_command("echo resgen_time waiting for threads %time%");
    int waitCount = 0;
    while (true)
    {
        if (myPool->GetWorkingThreadCount() == 0)
        {
            break;
        }
        ::Sleep(500);
        waitCount += 1;
        if (waitCount > 7200)
        {
            IMGPROC_LOG_E("mtk_resgenerator.exe Wait for threads timed out");
            delete myPool;
            exit(2);
        }
    }

    //execute_ext_command("echo resgen_time after Iloads %time%");
    FILE *output = fopen(OUTPUT_DATA_FILENAME, "ab");
    FILE *outputExt = fopen(OUTPUT_DATA_FILENAME_EXT, "ab");
    while (output == NULL)
    {
        Sleep(50);
        output = fopen(OUTPUT_DATA_FILENAME, "ab");
    }
    while (outputExt == NULL)
    {
        Sleep(50);
        outputExt = fopen(OUTPUT_DATA_FILENAME_EXT, "ab");
    }
    for (i = g_resgen_png_image_list.begin(); i != g_resgen_png_image_list.end(); ++i)
    {
        ProcessImageData & data = *i;

        // Show progress log in console
        if(!data.m_filename.empty())
        {
            if(!data.m_filename.empty())
            {
                IMGPROC_LOG_V("Process IMG %d(%s), file: %s", data.m_nImgId, data.m_enum_value.c_str(), data.m_filename.c_str() );
            }
            else
            {
                IMGPROC_LOG_V("Process IMG %d, file: %s", data.m_nImgId, data.m_enum_value.c_str(), data.m_filename.c_str());
            }
            fflush(stdout);
        }

        if (data.m_processData.duplicated)
        {
            IMGPROC_LOG_V("Duplicated Image: ID = %d.", data.m_nImgId);
            //if (g_resgen_png_image_list[data.m_processData.duplicatedIndex].failed)
            if (data.m_processData.duplicatedInstance->failed)
            {
                data.m_processData.failed = MMI_TRUE;
            }
        }

        ProcessResgenPngImagesMapIds(data);

		// Add the image content to Generator object
        if (data.m_processData.failed)
        {
            continue;
        }
		// Let contenMetaCreator handle the duplicated issue
		if(data.m_processData.duplicated){
			contentMetacreator->addImage(data.m_filename.c_str(),data.m_outstream.data, data.m_outstream.data_size,1);
			continue;
		}
        if (data.m_imgFlag)
        {
            ImageOutStreamOutputFile(&data.m_outstream, outputExt);
        }
        else
        {
			contentMetacreator->addImage(data.m_filename.c_str(),data.m_outstream.data, data.m_outstream.data_size,1);
            ImageOutStreamOutputFile(&data.m_outstream, output);
        }
    }
	IMGPROC_LOG_V("Output Image Group Content Meta: %s",OUTPUT_IMG_GROUP_CONTENT_META_FILENAME);
	contentMetacreator->generateMetaFile(OUTPUT_IMG_GROUP_CONTENT_META_FILENAME);

    IMGPROC_LOG_V("Close FILE: %s",OUTPUT_DATA_FILENAME);
    fflush(stdout);
    MYFCLOSE(output);

    IMGPROC_LOG_V("Close FILE: %s",OUTPUT_DATA_FILENAME_EXT);
    fflush(stdout);
    MYFCLOSE(outputExt);

    IMGPROC_LOG_V("Clean g_resgen_png_image_list");
    fflush(stdout);
    g_resgen_png_image_list.clear();

	delete contentMetacreator;
    delete(myPool);
#endif //__POPULATE_NO_IMAGE_DATA__
    //execute_ext_command("echo resgen_time after output data %time%");
}


void ImageOutStreamInit(ResgenImageOutStream ** pStream)
{
    *pStream = new ResgenImageOutStream();
}

void ImageOutStreamDeinit(ResgenImageOutStream ** pStream)
{
    delete *pStream;
    pStream = NULL;
}

void ImageOutStreamPrintf(ResgenImageOutStream * stream, char* fmt, ...)
{
    va_list myList;
    char buffer[1024];

    va_start(myList,fmt);
    vsprintf(buffer, fmt, myList);
    va_end(myList);

    size_t size = strlen(buffer);
    ImageOutStreamAppend(stream, buffer, size);

}

void ImageOutStreamAppend(ResgenImageOutStream * stream, char* buffer, U32 size)
{
    if (size == 0)
    {
        return;
    }
    size_t org_size = stream->data_size;
    stream->data_size = org_size + size;
    stream->data = (char*)realloc(stream->data, org_size + size);

    memcpy(stream->data + org_size, buffer, size);
}

void ImageOutStreamOutputFile(ResgenImageOutStream * stream, FILE * out_file)
{
    if(ImageOutStreamOutputFile == NULL || ImageOutStreamOutputFile == NULL )
    {
        IMGPROC_LOG_V("ImageOutStreamOutputFile: ResgenImageOutStream(0x%x) or out_file(0x%x) can't be NULL", stream, out_file);
        fflush(stdout);
    }

    if (stream->data_size > 0)
    {
        fwrite(stream->data, stream->data_size, 1, out_file);
    }
}

void LogSetBinaryWithBuffer(
                            U16 res_id,
                            S8 *filename,
                            int binary_type_flag)
{
    LogBinaryData data(res_id, filename, binary_type_flag);
    g_log_binary_data_list.push_back(data);
}

static void ProcessBinaryData()
{
    // Binary resource population are saved in offline DB
    // , and it can be read by resgen_populate.py directly
    int result = execute_ext_command("..\\..\\..\\" "tools\\python25\\python" " resgen_populate.py");
    if (result == 2)
    {
        //mtk_resgen_set_error();
        IMGPROC_LOG_E("Error!! 3D resource generation FAIL !!");
        RES_LOG_PENDING_FATAL(IMGPROC_TAG, "Error!! 3D Resource generation FAIL !!","External python script resgen_populate.py return error.","Please check the error message of TAG Py-RESGEN_POPULATE in this log file. Failed resource declaration are also logged in plutommi/customer/resgenerator/debug/failed_3d_resource.txt");
        fprintf(stderr, "\n** Fatal Error!! 3D Resource generation FAIL !!\n** Failed resource declaration are logged in plutommi/customer/resgenerator/debug/failed_3d_resource.txt\n** External python script resgen_populate.py return error.\n** Please also check the error message with TAG Py-RESGEN_POPULATE in resgen_mtk_resgenerator_run.log\n");
    }
}
