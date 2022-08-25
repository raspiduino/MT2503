#include "mmi_features.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "CustDataProts.h" // for FORCE_BMP
#include <string.h>
#include <stdio.h>
//#include <stdarg.h>
#include <assert.h>

#define WIN32_LEAN_AND_MEAN
#include "windows.h"

#include "gui_resource_type.h" // for IMAGE_TYPE_BMP
#include "ABMLoader.h" // for ABM_ENC_OPTION_FLAG_ABM...
#include "WriteResUtil.h"

#include "ImageGetDimension.h" // for Image_Get_Dimensions

#include "ResgenLogCAPI.h"

#define RESIMG_TAG "WRITEIMGRES"

#define RESIMG_LOG_D(format, args...) RES_LOG_D((RESIMG_TAG), (format) , ##args)
#define RESIMG_LOG_V(format, args...) RES_LOG_V((RESIMG_TAG), (format) , ##args)
#define RESIMG_LOG_W(format, args...) RES_LOG_W((RESIMG_TAG), (format) , ##args)
#define RESIMG_LOG_E(format, args...) RES_LOG_E((RESIMG_TAG), (format) , ##args)


#define MAX_SEQUENTIAL_IMAGE_FRAME      512

#define FILE_IMAGE_LOAD_FAILED_LOG      ".\\\\debug\\\\image_load_fail.txt"

#define NOIMAGE_FILENAMEBUFFER      "..\\\\..\\\\Customer\\\\IMAGES\\\\EmptyImage.bmp"

#define DEFAULT_FILEBUFFER          "________CUSTOMER__IMAGES__DEFAULT_BMP"

#define OUTPUT_IMAGE_NAMES_END      "[] =\n{"

#define ASSERT(expr) {if(!(expr)) {while(1);}else {}}


#ifdef __MMI_RESOURCE_IMAGE_COMPRESS__

#include "Zlib.h"

res_compress_struct g_res_compress_data_image[MAX_COMPRESSED_ITEM];
U32 g_res_compress_count_image = 0;

static BOOL g_is_compress = FALSE;
static BOOL g_is_compressed = FALSE;

U8* mmi_rg_compress_image(U8 *buffer, S32 org_size, S32 *dest_size, S32 image_type, U32 width_height,  U8* symbol, image_type_enum extImageFlag, BOOL is9slice, U8* _9slice_filename, int n_frames); // also used in ABMLoader.c

U8* mmi_rg_output_compressed_image(U8 *dest_buf, S32 dest_size, ResgenImageOutStream * outstream); // also used in ABMLoader.c

#define RG_SET_CPZ(x) mmi_rg_set_compress(x)

#else // __MMI_RESOURCE_IMAGE_COMPRESS__

#define RG_SET_CPZ(x)

#endif // __MMI_RESOURCE_IMAGE_COMPRESS__

extern int toolFlag;
extern int resultFailFlag;
extern FILE *dest_file;



// extern data
extern U16 CurrMaxFontNumEXT;
extern U16 CurrMaxFontIdEXT;

extern U16 CurrMaxImageId; // also used in WriteRes.c
extern U16 CurrMaxImageNum; // also used in WriteRes.c
extern CUSTOM_IMAGE_MAP ImageIdMap[]; // defined in CustResDeclare.c
extern FILE *OutputImgIDFile; // defined in PopulateRes.c
extern FILE *RepeatIDListFile; // also used in WriteRes.c
extern FILE *fpImageResourceUsage; // defined in PopulateRes.c

U32 image_idx = 1; // XXX
U32 g_resimg_count = 0; // XXX
CUSTOM_RESOURCE_SIZE g_resimg_table[MAX_IMAGE_IDS_SIZE]; // XXX

extern mmi_resource_base_struct g_mmi_resource_base_table[]; // for RESPRTONERECORD()

// font
#define FONT_OUTPUT_DATA_FILENAME		"..\\..\\Customer\\CustResource\\CustFontDataHW.h"

static U16 g_mmi_res_font_id = 0;
S32 g_mmi_res_font_flags = 0; // used in ImageGetDimension.c in ENFB mode
static U32 g_mmi_res_font_userdata = 0;

MMI_BOOL Fload(S8 *string);

extern FILE *font_data_file;
extern FONTNAME_LIST FontNameListEXT[];
extern CUSTOM_FONT_MAP FontIdMapEXT[];
extern FILE *font_data_lis;
extern FILE *font_data_modis_lis;
extern FILE *font_ttf_lis;


static S32 g_font_size = 0;

extern U32 GetOffsetFromResourceBase(U16 ImageID, U8* enum_value); // in WriteRes.c

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
int disableENFB = 0;    /* we will only disable E-NFB image only for NFB image or from CustPack tool, and this check is only for image_test() */ // also used in ImageGetDimension.c
U32 enfb_offset = 0; // also used in ABMLoader.c ...
U32 enfb_size = 0; // also used in ABMLoader.c ...

extern FILE *enfb_img_data_file;
MMI_BOOL ENFBAssociatedIDFlag;
MMI_BOOL ENFBAssociatedIDAdded;
extern CUSTOM_ENFB_STR ENFBAssociatedIDList[];
extern unsigned short CurrMaxENFBAssociatedIDNum;

extern MMI_BOOL AddENFBAssociatedIDItem(U16 ImageID, S8 *filename, image_type_enum ExtImageFlag);
extern MMI_BOOL IfItemExistENFBAssociatedID(S8 *filename, image_type_enum ExtImageFlag);
#endif // __MMI_RESOURCE_ENFB_SUPPORT__

#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
extern FILE *enfb_font_data_file;
extern ENFB_Font_Res_Info ENFBFontResInfo[];
#endif

// exported function

// exported global variable

// can only be set from FALSE to TRUE, shall be thread safe
MMI_BOOL g_mmi_res_nfb_used = FALSE;

// local function
static U8 isEmsImage(S8 *path);

static void mmi_rg_set_compress(BOOL is_compress);

static S32 Load_Image_Data(
        ResgenImageOutStream * outstream,
        FILE *input_file,
        U8 image_identifier,
        S32 n_frames,
        U32 width,
        U32 height,
        MMI_BOOL is9slice,
        U8* _9slice_filename,
        SetImageProcessData * processData);
static void Write_Sequential_Image_Header(
        ResgenImageOutStream * outstream,
        U8 image_identifier,
        S32 n_frames,
        U8 play_count,
        S32 *seq_filesize,
        S32 *seq_offset,
        U32 width,
        U32 height,
        S32 sequential_interval[MAX_SEQUENTIAL_IMAGE_FRAME],
        SetImageProcessData * processData);
static void Write_Sequential_Image_File(
        ResgenImageOutStream * outstream,
        FILE *input_file,
        S32 filesize,
        SetImageProcessData * processData);
static MMI_BOOL Write_Sequential_Image(
        char *pathname,
        char *output_name,
        ResgenImageOutStream * outstream,
        MMI_BOOL is9slice,
        S32 force_type,
        SetImageProcessData * processData);
static MMI_BOOL Write_Processed_Data(
        char *filename,
        U8 type,
        char *output_name,
        ResgenImageOutStream *outstream,
        image_type_enum extImageFlag,
        MMI_BOOL is9slice,
        S32 force_type,
        FILE *nfb_img_res_file,
        U8 *_9slice_filename,
        SetImageProcessData * processData, S32 * error_code);
static MMI_BOOL Write_Unprocessed_Data(
        char *filename,
        FILE *image_file,
        S32 nImageSize,
        char *output_name,
        ResgenImageOutStream * outstream,
        image_type_enum extImageFlag,
        MMI_BOOL is9slice,
        U8* _9slice_filename,
        FILE *nfb_img_res_file,
        SetImageProcessData * processData);
static U8 isSubmenuImage(S8 *path);

static void LogILoadFail(int img_id, const char * img_id_enum, const char * img_filename, int forceType);
static void LogNFBILoadFail(const char * img_filename, int forceType);

/*****************************************************************************
 * FUNCTION
 *  LogILoadFail
 * DESCRIPTION
 *  This function save the Iload failed log to the file. The log file is defined
 *  with FILE_IMAGE_LOAD_FAILED_LOG.
 * PARAMETERS
 *  img_id             id value of the image resource. if there is no id such as 
 *                     NFB image, it must be a native value
 *  img_id_enum        enum string of the image id
 *  img_filename       file name of the image content
 *  forceType          the target type of the image resource
 * RETURNS
 *  void
 *****************************************************************************/
static void LogILoadFail(int img_id, const char * img_id_enum, const char * img_filename, int forceType)
{
    FILE * imgFailLogFile = NULL;
    char img_id_enum_out[256] = "Unknown Id";
    char img_filename_out[256] = "Unknown File";

    if(file_exist(FILE_IMAGE_LOAD_FAILED_LOG) == MMI_TRUE)
    {
        imgFailLogFile = fopen(FILE_IMAGE_LOAD_FAILED_LOG,"a");
    }
    else
    {
        imgFailLogFile = fopen(FILE_IMAGE_LOAD_FAILED_LOG,"w");
        // Write log header if the file is first created
        fprintf(imgFailLogFile,"###############################################\n");
        fprintf(imgFailLogFile,"#       Resgen Failed Image Loading Log       #\n");
        fprintf(imgFailLogFile,"###############################################\n");
        fprintf(imgFailLogFile,"ID_NAME \tID\tFILE_PATH\tFORCE_TYPE\n");

    }

    //Use number limited string function to ensure the code secrity
    if(img_id_enum!=NULL)
    {
        memset(img_id_enum_out,0, sizeof(img_id_enum_out));
        strncpy(img_id_enum_out, img_id_enum, sizeof(img_id_enum_out)-1 );
    }

    if(img_filename!=NULL)
    {
        memset(img_filename_out,0, sizeof(img_filename_out));
        strncpy(img_filename_out, img_filename, sizeof(img_filename_out)-1);
    }

    if (imgFailLogFile != NULL)
    {
        fprintf(imgFailLogFile, "%s\t%d\t%s\t%d\n", img_id_enum_out, img_id, img_filename_out, forceType);
        fclose(imgFailLogFile);
    }
}

/*****************************************************************************
 * FUNCTION
 *  LogNFBILoadFail
 * DESCRIPTION
 *  This function save the Iload failed log to the file. The log file is defined
 *  with FILE_IMAGE_LOAD_FAILED_LOG.
 * PARAMETERS
 *  img_id             id value of the image resource. if there is no id such as 
 *                     NFB image, it must be a native value
 *  img_id_enum        enum string of the image id
 *  img_filename       file name of the image content
 *  forceType          the target type of the image resource
 * RETURNS
 *  void
 *****************************************************************************/
static void LogNFBILoadFail(const char * img_filename, int forceType)
{
    LogILoadFail(-1,"No-Id(NFB)",img_filename,forceType);
}


/*****************************************************************************
 * FUNCTION
 *  SetNFBImageImp
 * DESCRIPTION
 *
 * PARAMETERS
 *  filename        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void SetNFBImageImp(S8 *filename, SetImageProcessData * processData)
{
    int XXX;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nStrlen;
    S8 upperFileName[MAX_FILENAME_LEN];
    S8 filename_buffer[BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(MAX_FILENAME_LEN > strlen(filename));
    strcpy(filename_buffer, filename);

    if (strlen(filename_buffer) >= MAX_FILENAME_LEN)
    {
        filename_buffer[MAX_FILENAME_LEN - 1] = '\0';
    }
    if (!(strcmp(filename_buffer, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);

    }
    nStrlen = strlen(filename_buffer);
    if (nStrlen > MAX_FILENAME_LEN)
    {
        RESIMG_LOG_E("SetNFBImage: str too long\n");
        assert(0);
        exit(2);
    }

    strncpy(upperFileName, filename_buffer, MAX_FILENAME_LEN);
    str_upper(upperFileName, MAX_FILENAME_LEN);

    if( Iload(upperFileName, NFB_PROGRESS_IMAGE, AUTO_TYPE, processData)!= MMI_TRUE)
    {
        LogNFBILoadFail(upperFileName, AUTO_TYPE);
    }

    // can only be set from FALSE to TRUE, shall be thread safe
    g_mmi_res_nfb_used = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetImageWithBufferExImp
 * DESCRIPTION
 *  Function to copy the image file to buffer
 * PARAMETERS
 *  nImgId              [IN]
 *  filename            [?]
 *  enum_value          [?]
 *  res_type            [IN]
 *  imgFlag             [IN]
 *  S8(?)               [OUT]       -> filename of the image to be displayed.
 *  U16(?)              [IN]        -> ImageId
 * RETURNS
 *  void
 *****************************************************************************/
void SetImageWithBufferExImp(U16 nImgId, S8 *upperFileName, S8 *enum_value, BOOL imgFlag, S32 force_type, SetImageProcessData * processData)      /* 120304 Calvin modified for media resource */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    image_type_enum extImageFlag = SYSTEM_IMAGE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_RESOURCE_IMAGE_COMPRESS__)
    g_is_compressed = FALSE;
#endif

    if (imgFlag == TRUE)
    {
        extImageFlag = EXT_IMAGE;
    }
    else
    {
        extImageFlag = SYSTEM_IMAGE;
    }

    /*
    if (*pCurrMaxImageId >= MAX_IMAGE_IDS_SIZE)
    {
        return; // Can't add more than max number of image ids allowed
    }
    */

    if (strcmp(upperFileName, "..\\\\..\\\\CUSTOMER\\\\IMAGES\\\\COSMOS480X800\\\\MAINLCD\\\\DEFAULT\\\\BOOTUPSHUTDOWN\\\\ANIMATION\\\\POWER_OFF_ANI.GIF") == 0)
    {
        int i = 0;
    }
    if (processData->duplicated == MMI_FALSE)
    {
        if ( Iload(upperFileName, extImageFlag, force_type, processData)!= MMI_TRUE )
        {
            RESIMG_LOG_E("Iload failed: %s(%d), PATH=%s, TYEP=%d", enum_value, nImgId, upperFileName, force_type);
            fflush(stdout);
            if(!toolFlag)
            {
                LogILoadFail(nImgId, enum_value, upperFileName, force_type);
            }
            /* CustPack: let new set of images share the same resource of default image */
            processData->failed = MMI_TRUE;
        }
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__//100206 ENFB support
    if (processData->failed)
    {
    }
    else if (processData->duplicated)
    {
        if (ENFBAssociatedIDFlag == MMI_TRUE)
        {
            if (IfItemExistENFBAssociatedID(upperFileName, extImageFlag))//already in other associated group
            {
                AddENFBAssociatedIDItem(nImgId, upperFileName, extImageFlag);
            }
            else
            {
                fprintf(RepeatIDListFile, "\n\n!!!!!!!!!!!!%d\t%s\t\t%s!!!!!!!!!!!!!\n\n", nImgId, enum_value, upperFileName);
            }
        }
    }
    else
    {
        if (ENFBAssociatedIDFlag == MMI_TRUE)
        {
            if (ENFBAssociatedIDAdded == MMI_TRUE)//already in other associated group
            {
                AddENFBAssociatedIDItem(nImgId, upperFileName, extImageFlag);
                ENFBAssociatedIDAdded = MMI_FALSE;
            }
        }
    }
#endif // __MMI_RESOURCE_ENFB_SUPPORT__
}

/*****************************************************************************
 * FUNCTION
 *  Iload
 * DESCRIPTION
 *  load the file image to buffer and writes to CustImgRes.c, etc.
 * PARAMETERS
 *  string      [IN]        string containing file name and path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL Iload(S8 *string, image_type_enum extImageFlag, S32 force_type, SetImageProcessData * processData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL failure_flag;
    MMI_BOOL flag_file_exist = MMI_TRUE;
    S8 * output_image_names = NULL;
    S8 filename_buffer[BUFFER_SIZE];
    MMI_BOOL is9slice = MMI_FALSE;
    U8 _9slice_filename[MAX_FILENAME_LEN];
    FILE *nfb_img_res_file = NULL;
    S32 proc_img_err_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset res_size, size of the resource for usage manitor */
    processData->res_size = 0;

    if (extImageFlag == NFB_PROGRESS_IMAGE)
    {
        nfb_img_res_file = fopen(NFB_IMAGE_RES_FILENAME, "a");
        RESIMG_LOG_V("Iload - open CustNFBProgressImg.c for NFB population");
    }

    /* set output variable name of the resource */
    output_image_names = (S8*) malloc(MAX_FILENAME_LEN);
    strcpy(filename_buffer, string);
    if (!(strcmp(filename_buffer, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);
    }
    Extract_Name(output_image_names, filename_buffer, extImageFlag);

    if (strstr(filename_buffer, ".9SLICE") != NULL)
    {
        is9slice = MMI_TRUE;
        ASSERT(MAX_FILENAME_LEN > (strlen(filename_buffer)+4));
        strcpy(_9slice_filename, filename_buffer);
        strcat(_9slice_filename, ".TXT");
        RESIMG_LOG_D("Found 9slice image [%s]", filename_buffer);
        if (file_exist(_9slice_filename) == MMI_FALSE)
        {
            RESIMG_LOG_W("Did not find 9slice txt files [%s]", filename_buffer);

			// Release resource before return
			if (extImageFlag == NFB_PROGRESS_IMAGE){
                MYFCLOSE(nfb_img_res_file);
                RESIMG_LOG_V("NFB_PROGRESS_IMAGE is set - Close CustNFBProgressImg.c before Iload return");
            }
            free(output_image_names);
            return MMI_FALSE;
        }
    }

#ifdef __MMI_SLIM_LISTMENU_NUMBER__
    /* set sub-menu list icon image to default 1, 2, 3, ... */
    if (isSubmenuImage(filename_buffer))
    {
        int i, len;

        len = strlen(filename_buffer);

        for (i = len; i > 0; i--)
        {
            if (filename_buffer[i - 0] == 'U' && filename_buffer[i - 1] == 'N' && filename_buffer[i - 2] == 'E' &&
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

    failure_flag = MMI_FALSE;

    /* For 128x128, it does not support ABM.
     * In order not to modify res_xxx.c, we have to
     * find the correct filename automatically */
    /* This rule, renaming PNG -> other format, will apply for all */
    if (file_exist(filename_buffer) == MMI_FALSE)
    {
        S32 ext_type_1 = -1;
        ext_type_1 = ExtractExtension(filename_buffer, RES_IMAGE);
        if (ext_type_1 == IMAGE_TYPE_PNG)
        {
            S32 i, count;

            count = sizeof(image_resource_info)/sizeof(RESOURCE_INFO);
            for (i = 0; i < count; i++)
            {
                ChangeExtension(filename_buffer, RES_IMAGE, image_resource_info[i].file_type);
                if (file_exist(filename_buffer) == MMI_TRUE)
                {
                    strcpy(processData->real_filename, filename_buffer);
                    break;
                }
            }
            if (i == count)
            {
                ChangeExtension(filename_buffer, RES_IMAGE, IMAGE_TYPE_PNG);
                RES_PRINT_INFO("[ABM] %s\tcannot open file for all supported formats!!!\n", filename_buffer);
                flag_file_exist = MMI_FALSE;
            }
        }
    }

    /* ABM encoding */
    if ((failure_flag == MMI_FALSE) &&
        !isEmsImage(filename_buffer))
    {
        S32 ext_type_2 = -1;
        ext_type_2 = ExtractExtension(filename_buffer, RES_IMAGE);

#if defined(__MMI_ALPHA_BLENDING__)
        /* If PNG, we will convert it to ABM conditionally */
        if (ext_type_2 == IMAGE_TYPE_PNG)
        {
            BOOL is_need_convert = TRUE;
            S8 tempBMPFile[BUFFER_SIZE];

            /* convert PNG to 32-bits BMP */
            if (strlen(filename_buffer) >  BUFFER_SIZE)
            {
                RESIMG_LOG_E("Iload: strlen(filename_buffer) >  BUFFER_SIZE\n");
                assert(0);
                exit(2);
            }
            strcpy((char*)tempBMPFile, (const char*)filename_buffer);

            if ((strlen(filename_buffer)+strlen(tempBMPFile)) >  MAX_FILENAME_LEN)
            {
                RESIMG_LOG_E("Iload: (strlen(filename_buffer)+strlen(tempBMPFile)) >  MAX_FILENAME_LEN\n");
                assert(0);
                exit(2);
            }

            ChangeExtension(tempBMPFile, RES_IMAGE, IMAGE_TYPE_BMP);
            strcat(tempBMPFile, "A");

            if (toolFlag != 1)
            {
                if (resgen_compare_file_time(tempBMPFile, filename_buffer) == -1)
                {
                    is_need_convert = FALSE;
                    RES_PRINT_INFO("[%s] no need convert 01\n", filename_buffer);
                }
            }

            if (is_need_convert && flag_file_exist)
            {
                S8 tempCommand[SHELL_CMD_BUFLEN];
                //sprintf(tempCommand, ".\\\\convert.exe -channel Alpha -negate -compress none png:%s bmp:%s 2>> .\\debug\\3rd_tool.log", filename_buffer, tempBMPFile);
                sprintf(tempCommand, ".\\\\convert.exe -channel Alpha -negate -compress none png:%s bmp:%s > NUL", filename_buffer, tempBMPFile);
                RES_PRINT_INFO("%s\n", tempCommand);
                ASSERT(SHELL_CMD_BUFLEN > strlen(tempCommand));

                system(tempCommand);
            }

            /* convert 32-bits BMP to ABM */
            failure_flag = Write_Processed_Data(tempBMPFile, IMAGE_TYPE_ABM, output_image_names, processData->outstream, extImageFlag, is9slice, force_type, nfb_img_res_file, _9slice_filename, processData, &proc_img_err_code);
            if(failure_flag == MMI_FALSE && proc_img_err_code ==  ABM_ENC_INPUT_BITMAP_ERROR)
            {
                  // Release resoruce before return
            	    if (extImageFlag == NFB_PROGRESS_IMAGE)
            	    {
            	        RESIMG_LOG_V("NFB_PROGRESS_IMAGE is set - Close CustNFBProgressImg.c before Iload return");
                      fflush(stdout);
                      MYFCLOSE(nfb_img_res_file);
                  }
                  free(output_image_names);
                  return MMI_FALSE;
            }
        }
        else
#endif /* defined(__MMI_ALPHA_BLENDING__) */

        /* If BMP/PBM, we will convert it to ABM conditionally */
        if ((ext_type_2 == IMAGE_TYPE_BMP) ||
            (ext_type_2 == IMAGE_TYPE_DEVICE_BITMAP))
        {
            if (ext_type_2 == IMAGE_TYPE_BMP)
            {                
                if (is16BitBMP(filename_buffer))
                {
                	S8 tempCommand[SHELL_CMD_BUFLEN];
                    sprintf(tempCommand, ".\\\\convert.exe %s %s > NUL", filename_buffer, filename_buffer);
					RES_PRINT_INFO("%s\n", tempCommand);
					ASSERT(SHELL_CMD_BUFLEN > strlen(tempCommand));
					system(tempCommand);
                }
            }
        
            if (force_type != FORCE_BMP)
            {
                failure_flag = Write_Processed_Data(filename_buffer, IMAGE_TYPE_ABM, output_image_names, processData->outstream, extImageFlag, is9slice, force_type, nfb_img_res_file, _9slice_filename, processData, &proc_img_err_code);
            }
        }

        /* all of the resource above may not be converted to ABM certainly
         * if not, it will be populated as usual */
    }

    if (failure_flag == MMI_FALSE)
    {
        S16 filenameLen_1;
#ifdef __MMI_ALPHA_LAYER_SUPPORT__
        /* fetch PNG by GIF or BMP,
         * application can add PNG file directly without modifying Res_XXX.c */
        S32 ext_type_3 = -1;
        ext_type_3 = ExtractExtension(filename_buffer, RES_IMAGE);
        if (ext_type_3 == IMAGE_TYPE_GIF || ext_type_3 == IMAGE_TYPE_BMP)
        {
            ChangeExtension(filename_buffer, RES_IMAGE, IMAGE_TYPE_PNG);
        }

        if (file_exist(filename_buffer))
        {
            strcpy(processData->real_filename, filename_buffer);
        }
        else
        {
            ChangeExtension(filename_buffer, RES_IMAGE, ext_type_3);
        }
#endif

        filenameLen_1 = strlen(filename_buffer);
        if (filenameLen_1 <= 3)
        {
            RESIMG_LOG_E("Iload: filename_buffer too short");
            assert(0);
            exit(2);
        }

        /* process EMS image */
        if (isEmsImage(filename_buffer))
        {
            if (file_exist(filename_buffer) )
            {
                int ret = 1;

                if (toolFlag == 0)
                {
                    ImageOutStreamPrintf(processData->outstream, "const U8 %s[] = ", output_image_names);
                }
                ret = bmp2ems(filename_buffer, processData->outstream, 1, 0, processData);
                if (toolFlag)
                {
                    if (ret == 0)
                    {
                        resultFailFlag = 1;
                    }
                    else
                    {
                        resultFailFlag = 0;
                    }
                }

                failure_flag = MMI_TRUE;
            }
            else
            {
                failure_flag = MMI_FALSE;
            }
        }
        /* process PBM */
        else if ((filename_buffer[filenameLen_1 - 1] == 'M') &&
                 (filename_buffer[filenameLen_1 - 2] == 'B') &&
                 (filename_buffer[filenameLen_1 - 3] == 'P'))
        {
            failure_flag = Write_Processed_Data(filename_buffer, IMAGE_TYPE_DEVICE_BITMAP, output_image_names, processData->outstream, extImageFlag, is9slice, force_type, nfb_img_res_file, _9slice_filename, processData, &proc_img_err_code);
        }
        else
        {
            U8 staticFlag = 1;  /* Non animated image */
            /* MTK Leo add, for read images with same filename but different in ".bmp" and ".gif" */
            if (!file_exist(filename_buffer) )
            {
                if (filename_buffer[filenameLen_1 - 1] == 'P' &&
                    filename_buffer[filenameLen_1 - 2] == 'M' &&
                    filename_buffer[filenameLen_1 - 3] == 'B')
                {
                    filename_buffer[filenameLen_1 - 1] = 'F';
                    filename_buffer[filenameLen_1 - 2] = 'I';
                    filename_buffer[filenameLen_1 - 3] = 'G';
                }
                else if (filename_buffer[filenameLen_1 - 1] == 'F' &&
                         filename_buffer[filenameLen_1 - 2] == 'I' &&
                         filename_buffer[filenameLen_1 - 3] == 'G')
                {
                    filename_buffer[filenameLen_1 - 1] = 'P';
                    filename_buffer[filenameLen_1 - 2] = 'M';
                    filename_buffer[filenameLen_1 - 3] = 'B';
                }
            }

            if (!file_exist(filename_buffer) )
            {
                if (toolFlag == 0)
                {
                    FILE *fail = fopen(".\\\\debug\\\\fail.txt", "a+");

                    if (fail != NULL)
                    {
                        fprintf(fail, "%s\n", filename_buffer);
                        MYFCLOSE(fail);
                    }
                }
                RESIMG_LOG_V("File %s not exist, trying to load sequential image",filename_buffer);
                failure_flag = Write_Sequential_Image(filename_buffer, output_image_names, processData->outstream, is9slice, force_type, processData);
                if (failure_flag == MMI_TRUE)
                {
                    staticFlag = 0;
                }
            }

            /* process static image */
            if ((failure_flag == MMI_FALSE) && (staticFlag))
            {
                FILE *image_data_file_4 = NULL;
                image_data_file_4 = fopen(filename_buffer, "rb");

                if (image_data_file_4 != NULL)
                {
                    S32 nImageSize = 0;
                    /* patch added by vikram for getting image file size */
                    fseek(image_data_file_4, 0, SEEK_END);
                    nImageSize = ftell(image_data_file_4);
                    fseek(image_data_file_4, 0, SEEK_SET);

                    failure_flag = Write_Unprocessed_Data(
                            filename_buffer,
                            image_data_file_4,
                            nImageSize,
                            output_image_names,
                            processData->outstream,
                            extImageFlag,
                            is9slice,
                            _9slice_filename,
                            nfb_img_res_file,
                            processData);

                    MYFCLOSE(image_data_file_4);
                }
            }
        }
    }

    /* 120704 Calvin added for populating with .bmp or .gif but actually extsion name is not */
    if (failure_flag == MMI_FALSE)
    {
        /* RES_PRINT_INFO("*************failed !!!********************\n"); */
        /* try each supported extension */
        S32 j;
        S16 filenameLen_2;
        filenameLen_2 = strlen(filename_buffer);
        MMI_BOOL has_file = MMI_FALSE;
        for (j = 0; j < SUPPORT_N_MEDIA_TYPE; j++)
        {
            S32 l;

            ASSERT(filenameLen_2 >= 3);
            for (l = 0; l < 3; l++)
            {
                filename_buffer[filenameLen_2 - 1 - l] = support_media_ext[j][2 - l];
            }

            if (file_exist(filename_buffer) )
            {
                has_file = MMI_TRUE;
                break;
            }
        }

        if (has_file)
        {
            FILE *image_data_file_5 = fopen(filename_buffer, "rb");
            if (image_data_file_5 != NULL)
            {
                S32 nImageSize = 0;
                //failure_flag = MMI_TRUE;

                fseek(image_data_file_5, 0, SEEK_END);
                nImageSize = ftell(image_data_file_5);
                fseek(image_data_file_5, 0, SEEK_SET);

                failure_flag = Write_Unprocessed_Data(
                        filename_buffer,
                        image_data_file_5,
                        nImageSize,
                        output_image_names,
                        processData->outstream,
                        extImageFlag,
                        is9slice,
                        _9slice_filename,
                        nfb_img_res_file,
                        processData);

                MYFCLOSE(image_data_file_5);
            }
        }
    }

    // Release resoruce before return
    if (extImageFlag == NFB_PROGRESS_IMAGE){
        RESIMG_LOG_V("NFB_PROGRESS_IMAGE is set - Close CustNFBProgressImg.c before Iload return");
        fflush(stdout);
        MYFCLOSE(nfb_img_res_file);
    }
    free(output_image_names);
	
    return failure_flag;
}


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
static U8 isEmsImage(S8 *path)
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
        /* __CUSTPACK_MULTIBIN Calvin BEGIN */
        if (pos == 0)   /* 040805 CustPack: Calvin added */
        {
            return 0;
        }
        /* __CUSTPACK_MULTIBIN Calvin END */
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
 *  Write_Processed_Data
 * DESCRIPTION
 *  write processed data
 * PARAMETERS
 *  pathname        [IN]        path name for sequential image
 *  type            [IN]        image type
 *  output_name     [IN]        output variable name
 *  output_file     [OUT]       output file handle
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Write_Processed_Data(
        char *filename,
        U8 type,
        char *output_name,
        ResgenImageOutStream * outstream,
        image_type_enum extImageFlag,
        MMI_BOOL is9slice,
        S32 force_type,
        FILE *nfb_img_res_file,
        U8 *_9slice_filename,
        SetImageProcessData * processData,
        S32 *proc_img_err_code
        )
{
    *proc_img_err_code = 0;
    
    S8 tempDestFile[BUFFER_SIZE];

    BOOL is_need_convert = TRUE;

    if (type == IMAGE_TYPE_ABM)
    {
        strcpy(tempDestFile, filename);
        strcat(tempDestFile, ".ABM");

#if !defined(__MMI_RESOURCE_IMAGE_COMPRESS__)
        if (toolFlag != 1)
        {
            if (resgen_compare_file_time(tempDestFile, filename) == -1)
            {
                is_need_convert = FALSE;
                RES_PRINT_INFO("[%s] no need convert\n", filename);
            }
        }
#endif /* #if defined(__MMI_RESOURCE_IMAGE_COMPRESS__) */
    }
    else
    {
        char temp_filename[1024];
        Extract_Name(temp_filename, filename, SYSTEM_IMAGE);
        strcpy(tempDestFile, ".\\temp\\");
        strcat(tempDestFile, temp_filename);
        strcat(tempDestFile, ".temp");
    }

    if (file_exist(filename) )
    {
        int ret;
        switch (type)
        {
            case IMAGE_TYPE_GIF:
                if (is_need_convert)
                {
                    GIFLoader(filename, tempDestFile);
                }
                break;

            case IMAGE_TYPE_DEVICE_BITMAP:
                if (is_need_convert)
                {
                    ret = BMPLoader(filename, tempDestFile, __MMI_DEVICE_BMP_FORMAT__, _9slice_filename, is9slice, processData);
                }
                else
                {
                    ret = 1;
                }

                if (toolFlag)
                {
                    if (ret == 0)
                    {
                        resultFailFlag = 1;
                    }
                    else
                    {
                        resultFailFlag = 0;
                    }
                }
                else
                {
                    /* we handle empty bmp file here, maybe we should handle it in Write_Unprocessed_Data in the future */
                    if (ret == 0)
                    {
                        ImageOutStreamPrintf(outstream, "__align(4) const U8 %s[] =\n", output_name);
                        ImageOutStreamPrintf(outstream, "{\n\t0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00\n};\n");
                        if (extImageFlag == NFB_PROGRESS_IMAGE)
                        {
                            RESIMG_LOG_V("Write NFB_PROGRESS_IMAGE in Write_Processed_Data for empty bmp file");
                            if (nfb_img_res_file != NULL)
                            {
                                if(output_name != NULL){							
                                    RESIMG_LOG_V("output_name = %s", output_name);
                                fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_name);
                                }else{
                                    RESIMG_LOG_E("output_name can't be NULL!!");
								}
                            }
                            else
                            {
                                RESIMG_LOG_E("nfb_img_res_file not opened");
                            }
                        }
                        return MMI_TRUE;
                    }
                }
                break;

            case IMAGE_TYPE_ABM:
                if (is_need_convert)
                {
                    RG_SET_CPZ(TRUE);
                    if (force_type == FORCE_ABM)
                    {
                        ret = ABMLoader(filename, tempDestFile, ABM_ENC_OPTION_FLAG_ABM, is9slice, _9slice_filename, processData);
                    }
                    else if(force_type == FORCE_AB2)
                    {
                        ret = ABMLoader(filename, tempDestFile, ABM_ENC_OPTION_FLAG_AB2, is9slice, _9slice_filename, processData);
                    }                	
                    else
                    {
                        ret = ABMLoader(filename, tempDestFile, ABM_ENC_OPTION_FLAG_ALL, is9slice, _9slice_filename, processData);
                    }
                    RG_SET_CPZ(FALSE);
                }
                else
                {
                    ret = ABM_ENC_RETURN_USE_ABM;
                }

                if (ret != ABM_ENC_RETURN_USE_ABM)
                {
                    if (toolFlag)
                    {
                        resultFailFlag = 1;
                    }
                    *proc_img_err_code = ret;
                    
                    return MMI_FALSE;
                }
                else
                {
                    if (toolFlag)
                    {
                        resultFailFlag = 0;
                    }
                }
                break;

            default:
                return MMI_FALSE;
        }

        if (toolFlag == 0)
        {
            FILE *fp;

            fp = fopen(tempDestFile, "rb");
            if (fp != NULL)
            {
#if defined(__MMI_RESOURCE_IMAGE_COMPRESS__)
                if (g_is_compressed)
                {
                    ImageOutStreamPrintf(outstream, "__align(4) U8 %s[%d];\n", output_name, g_res_compress_data_image[g_res_compress_count_image-1].zi_len);
                    ImageOutStreamPrintf(outstream, "__align(4) const U8 %s_zip[] =\n", output_name);

                    strcpy(g_res_compress_data_image[g_res_compress_count_image-1].ro_name, output_name);
                    strcpy(g_res_compress_data_image[g_res_compress_count_image-1].zi_name, output_name);
                    strcat(g_res_compress_data_image[g_res_compress_count_image-1].ro_name, "_zip");
                }
                else
#endif /* __MMI_RESOURCE_IMAGE_COMPRESS__ */
                {
                    ImageOutStreamPrintf(outstream, "__align(4) const U8 %s[] =\n", output_name);
                }

                if (extImageFlag == NFB_PROGRESS_IMAGE)
                {
                    if (nfb_img_res_file != NULL)
                    {
                        RESIMG_LOG_V("Write NFB_PROGRESS_IMAGE in Write_Processed_Data, type = %d",type);

                        if(output_name != NULL){
                            RESIMG_LOG_V("output_name = %s", output_name);
                            fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_name);
                        }
                        else
                        {
                            RESIMG_LOG_E("output_name can't be NULL!!");
                        }
                    }
                    else
                    {
                        RESIMG_LOG_E("nfb_img_res_file not opened");
                    }
                }

                //const int buffer_size = 64 * 1024;
                const int buffer_size = 200;
                while (!feof(fp))
                {
                    S8 buffer[buffer_size];
                    size_t size;

                    size = fread(buffer, 1, buffer_size, fp);
                    if (size > 0 && size <= buffer_size)
                    {
                        ImageOutStreamAppend(outstream, buffer, size);
                    }
                }
                ImageOutStreamPrintf(outstream, "\n");

                MYFCLOSE(fp);
            }
        }
    }
    else
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  Write_Unprocessed_Data
 * DESCRIPTION
 *  write unprocessed data
 * PARAMETERS
 *  pathname        [IN]        path name for sequential image
 *  output_name     [IN]        output variable name
 *  output_file     [OUT]       output file handle
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Write_Unprocessed_Data(
        char *filename,
        FILE *image_file,
        S32 nImageSize,
        char *output_name,
        ResgenImageOutStream * outstream,
        image_type_enum extImageFlag,
        MMI_BOOL is9slice,
        U8* _9slice_filename,
        FILE *nfb_img_res_file,
        SetImageProcessData * processData)
{
    U8 image_identifier;
    MMI_BOOL failure_flag = MMI_TRUE;
    S32 n_frames = 0;
    U32 width = 0, height = 0;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
#endif
#if defined(__MMI_RESOURCE_IMAGE_COMPRESS__)
    U8 *dest_buf = NULL;
    U32 dest_size = 0;
    U32 file_size = 0;
#endif
    /* Currently assuming that all single files are BMP */
    if (nImageSize == 0)
    {
        image_identifier = IMAGE_TYPE_INVALID;
    }
    else
    {
        /* for read images with same filename but different in ".bmp" and ".gif" */
        image_identifier = ExtractExtension(filename, RES_IMAGE);
    }

#if defined(__MMI_ALPHA_BLENDING__) && !defined(GDI_USING_HW_PNG)
    /* IMAGE_TYPE_PNG is only for future usage.
     * Currently, output PNG format for image resource is not allowed */
    if (image_identifier == IMAGE_TYPE_PNG)
    {
        fprintf(stderr, "***Warning***\tPNG file is not populated successfully.\n\t%s\n", filename);
        RESIMG_LOG_E("***Warning***\tPNG file is not populated successfully.\n\t%s", filename);
        return MMI_FALSE;
    }
#endif /* defined(__MMI_ALPHA_BLENDING__) && !defined(GDI_USING_HW_PNG) */

#ifdef GDI_USING_IMAGE_SINGLE_BANK_CACHE
    if (image_identifier == IMAGE_TYPE_GIF ||
        image_identifier == IMAGE_TYPE_JPG)
    {
        FILE *fp;

        fp = fopen(filename, "rb");
        if (fp != NULL)
        {
            S32 fs;

            fseek(fp, 0, SEEK_END);
            fs = ftell(fp);
            MYFCLOSE(fp);

            if ((fs + 8/* header */) > GDI_IMAGE_SINGLE_BANK_CACHE_SIZE)
            {
                fprintf(stderr, "[Single Bank]:\timage oversize,\t%s\n", filename);
                RESIMG_LOG_E("[Single Bank]:\timage oversize,\t%s\n", filename);
                failure_flag = MMI_FALSE;
                assert(0);
                exit(2);
            }
        }
        else
        {
            failure_flag = MMI_FALSE;
        }
    }
#endif

    if (failure_flag == MMI_TRUE)
    {
        /* get frame count, width and height of the image */
        if (image_identifier == IMAGE_TYPE_BMP ||
            image_identifier == IMAGE_TYPE_GIF ||
            image_identifier == IMAGE_TYPE_JPG ||
            image_identifier == IMAGE_TYPE_PNG)
        {
            n_frames = Image_Get_Dimensions(filename, &width, &height);
            if (n_frames <= 0)
            {
                RES_PRINT_INFO("\nGet dimensions failed:\t%s", filename);
                failure_flag = MMI_FALSE;
            }
        }
        else if (image_identifier == IMAGE_TYPE_KTX)
        {
            FILE * fp = NULL;
            U8 tempBuffer[44];
            fp = fopen(filename, "rb");
            if (fp != NULL)
            {
                U8 read_count = fread(tempBuffer, 1, 44, fp);
                if (read_count == 44)
                {
                    U8 *data_ptr = tempBuffer;
                    data_ptr += 36;
                    width = (data_ptr[3] << 24) | (data_ptr[2] << 16) | (data_ptr[1] << 8) | (data_ptr[0]);
                    data_ptr += 4;
                    height = (data_ptr[3] << 24) | (data_ptr[2] << 16) | (data_ptr[1] << 8) | (data_ptr[0]);
                }
                fclose(fp);
            }
        }
    }

    strcpy(processData->real_filename, filename);

    if (failure_flag == MMI_TRUE)
    {
#if defined(__MMI_RESOURCE_IMAGE_COMPRESS__)
        if (image_identifier == IMAGE_TYPE_BMP ||
            image_identifier == IMAGE_TYPE_GIF ||
            image_identifier == IMAGE_TYPE_JPG ||
            image_identifier == IMAGE_TYPE_PNG)
        {
            U8 *buffer = NULL;

            fseek(image_file, 0, SEEK_END);
            file_size = ftell(image_file);
            fseek(image_file, 0, SEEK_SET);

            mmi_rg_set_compress(TRUE);
            buffer = malloc(file_size);
            fread(buffer, 1, file_size, image_file);
            dest_buf = mmi_rg_compress_image(buffer, file_size, &dest_size, image_identifier, (((width & 0XFFF) << 12) | (height & 0XFFF)), output_name, extImageFlag, is9slice, _9slice_filename, n_frames);
            mmi_rg_set_compress(FALSE);
        }

        if (g_is_compressed)
        {
            ImageOutStreamPrintf(outstream, "__align(4) U8 %s[%d];\n", output_name, g_res_compress_data_image[g_res_compress_count_image-1].zi_len);
            ImageOutStreamPrintf(outstream, "__align(4) const U8 %s_zip[] =\n{", output_name);

            strcpy(g_res_compress_data_image[g_res_compress_count_image-1].ro_name, output_name);
            strcpy(g_res_compress_data_image[g_res_compress_count_image-1].zi_name, output_name);
            strcat(g_res_compress_data_image[g_res_compress_count_image-1].ro_name, "_zip");

            mmi_rg_output_compressed_image(dest_buf, dest_size, outstream);

            ImageOutStreamPrintf(outstream, "\n };\n");
        }
        else
#endif
        {
            /* load the data */
            /* construct the data structure name */
            if (image_identifier == IMAGE_TYPE_GIF || image_identifier == IMAGE_TYPE_3GP ||
                image_identifier == IMAGE_TYPE_MP4 || image_identifier == IMAGE_TYPE_AVI ||
                image_identifier == IMAGE_TYPE_PNG || image_identifier == IMAGE_TYPE_RV  ||
                image_identifier == IMAGE_TYPE_RM  || image_identifier == IMAGE_TYPE_RMVB ||
                image_identifier == IMAGE_TYPE_M3D || image_identifier == IMAGE_TYPE_SWFLASH ||
                image_identifier == IMAGE_TYPE_KTX || image_identifier == IMAGE_TYPE_JPG)
            {
                ImageOutStreamPrintf(outstream, "__align(4) ");
            }

            ImageOutStreamPrintf(outstream, "const U8 %s%s", output_name, OUTPUT_IMAGE_NAMES_END);


#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            enfb_ret = Image_Test(filename, &enfb_width, &enfb_height, processData->disable_enfb);
            if (enfb_ret != ENFB_IMAGE_NONE)
            {
                processData->enfb_flag = 1;
                if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
                {
                    ENFBAssociatedIDAdded = MMI_TRUE;
                }
            }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

            processData->res_size = Load_Image_Data(outstream, image_file, image_identifier, n_frames, width, height, is9slice, _9slice_filename, processData);
            if (processData->res_size == 0)
            {
                failure_flag = MMI_FALSE;
            }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            processData->enfb_flag = 0;
#endif

            if (extImageFlag == NFB_PROGRESS_IMAGE)
            {
                RESIMG_LOG_V("Write NFB_PROGRESS_IMAGE");
   			
                if (nfb_img_res_file != NULL)
                {
                    if(output_name != NULL)
                    {
                        RESIMG_LOG_V("Write output name to nfb_img_res_file: %s",output_name);
                        fprintf(nfb_img_res_file, "(U8*)&%s,\n", output_name);
                    }
                    else
                    {
                        RESIMG_LOG_E("Output name can't be NULL in Write_Unprocessed_Data");
                    }
                }
                else
                {
                    RESIMG_LOG_E("nfb_img_res_file is not opened");
                }
            }

            ImageOutStreamPrintf(outstream, "\n };\n");
        }
    }
    return failure_flag;
}

/*****************************************************************************
 * FUNCTION
 *  Write_Sequential_Image_Header
 * DESCRIPTION
 *  construct the header for sequential images
 * PARAMETERS
 *  output_file             [IN]        output file handle
 *  image_identifier        [IN]        sequential image type
 *  n_frames                [IN]        the number of the frames
 *  play_count              [IN]        number of playing times
 *  seq_filesize            [IN]        pointer to a list of file sizes
 *  seq_offset              [OUT]       pointer to a list of offsets
 *  width                   [IN]        maximun width
 *  height                  [IN]        maximun height
 * RETURNS
 *  void
 *****************************************************************************/
static void Write_Sequential_Image_Header(
        ResgenImageOutStream * outstream,
        U8 image_identifier,
        S32 n_frames,
        U8 play_count,
        S32 *seq_filesize,
        S32 *seq_offset,
        U32 width,
        U32 height,
        S32 sequential_interval[MAX_SEQUENTIAL_IMAGE_FRAME],
        SetImageProcessData * processData)
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
                play_count,
                0, 0,    /* file size (not used) */
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

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* write ENFB header to CustImgDataxxx.h and image header/data to ENFB image data file */
    else if (processData->enfb_flag == 1)
    {
        S32 data_size = 0;
        for (i = 0; i < n_frames; i++)
        {
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            data_size += real_size;
        }
        enfb_size = 8 + 12*n_frames + data_size;

        /* write ENFB header to CustImgDataxxx.h */
        ImageOutStreamPrintf(outstream,
            "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t",
            (U8) 255,                   //type
            (U8) ENFBAssociatedIDAdded, //associated id
            (U8) 0,                     //reserved
            (U8) 0,                     //reserved
            (U8) (enfb_offset & 0xff),
            (U8) ((enfb_offset >> 8) & 0xff),
            (U8) ((enfb_offset >> 16) & 0xff),
            (U8) ((enfb_offset >> 24) & 0xff),
            (U8) (enfb_size & 0xff),
            (U8) ((enfb_size >> 8) & 0xff),
            (U8) ((enfb_size >> 16) & 0xff),
            (U8) ((enfb_size >> 24) & 0xff));

        /* image header/data to ENFB image data file */
        /* the major header */
        fprintf(enfb_img_data_file, "%c%c%c%c%c%c%c%c",
                image_identifier,
                n_frames,
                play_count,
                0, 0,    /* file size (not used) */
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        for (i = 0; i < n_frames; i++)
        {
            int interval = sequential_interval[i];

            seq_offset[i] = offset;
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            fprintf(enfb_img_data_file, "%c%c%c%c", seq_offset[i] & 0xff, (seq_offset[i] & 0xff00) >> 8, (seq_offset[i] & 0xff0000) >> 16, (seq_offset[i] & 0xff000000) >> 24);  /* the offset for each file */
            fprintf(enfb_img_data_file, "%c%c%c%c", seq_filesize[i] & 0xff, (seq_filesize[i] & 0xff00) >> 8, (seq_filesize[i] & 0xff0000) >> 16, (seq_filesize[i] & 0xff000000) >> 24);  /* the size for each file */
            fprintf(enfb_img_data_file, "%c%c%c%c", interval & 0xff, (interval & 0xff00) >> 8, (interval & 0xff0000) >> 16, (interval & 0xff000000) >> 24);      /* the interval for each file */
            offset += real_size;
        }

        enfb_offset += enfb_size;
        processData->res_size += enfb_size;
    }
#endif

    else
    {
        /* the major header */
        ImageOutStreamPrintf(outstream, 
                "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t",
                image_identifier,
                n_frames,
                play_count,
                0, 0,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        processData->res_size += 8;
        for (i = 0; i < n_frames; i++)
        {
            int interval = sequential_interval[i];

            seq_offset[i] = offset;
            real_size = ((seq_filesize[i] + 3) >> 2) << 2;
            ImageOutStreamPrintf(outstream, "0x%02X, 0x%02X, 0x%02X, 0x%02X, ", seq_offset[i] & 0xff, (seq_offset[i] & 0xff00) >> 8, (seq_offset[i] & 0xff0000) >> 16, (seq_offset[i] & 0xff000000) >> 24);
            ImageOutStreamPrintf(outstream, "0x%02X, 0x%02X, 0x%02X, 0x%02X, ", seq_filesize[i] & 0xff, (seq_filesize[i] & 0xff00) >> 8, (seq_filesize[i] & 0xff0000) >> 16, (seq_filesize[i] & 0xff000000) >> 24);
            ImageOutStreamPrintf(outstream, "0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t", interval & 0xff, (interval & 0xff00) >> 8, (interval & 0xff0000) >> 16, (interval & 0xff000000) >> 24);
            offset += real_size;

            processData->res_size += 12 + seq_filesize[i];
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  Write_Sequential_Image_File
 * DESCRIPTION
 *  write raw date from a frame of an image to the output file
 * PARAMETERS
 *  output_file     [IN]        output file handle
 *  input_file      [IN]        input file handle
 *  filesize        [IN]        the input file size
 * RETURNS
 *  void
 *****************************************************************************/
static void Write_Sequential_Image_File(
        ResgenImageOutStream * outstream,
        FILE *input_file,
        S32 filesize,
        SetImageProcessData * processData)
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
            /* for 4 byte alignment */
            fprintf(dest_file, "%c", 0);
        }
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* write ENFB header to CustImgDataxxx.h and image header/data to ENFB image data file */
    else if (processData->enfb_flag == 1)
    {
        for (i = 0; i < filesize; i++)
        {
            ch = fgetc(input_file);
            fprintf(enfb_img_data_file, "%c", ch);
        }

        for (i = filesize; i % 4 != 0; i++)
        {
            /* for 4 byte alignment */
            fprintf(enfb_img_data_file, "%c", 0);
        }
    }
#endif

    else
    {
        /*
        for (i = 0; i < filesize; i++)
        {
            ch = fgetc(input_file);
            ImageOutStreamPrintf(outstream, "0x%02X, ", ch);
            o++;
            if ((o % 16) == 0)
            {
                ImageOutStreamPrintf(outstream, "\n\t");
            }
        }
        */
        const int buffer_size = 16 * 1024;
        while (1)
        {
            U8 buffer[buffer_size];
            U32 size = fread(buffer, 1, buffer_size, input_file);
            if (size == 0)
            {
                break;
            }
            for (i = 0; i < size; i++)
            {
                ImageOutStreamPrintf(outstream, "0x%02X, ", buffer[i]);
                if ((++o % 16) == 0)
                {
                    ImageOutStreamPrintf(outstream, "\n\t");
                }
            }
        }

        for (i = filesize; i % 4 != 0; i++)
        {
            /* for 4 byte alignment */
            ImageOutStreamPrintf(outstream, "0x00, ");
        }

        if ((o % 16) != 0)
        {
            ImageOutStreamPrintf(outstream, "\n\t");
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Write_Sequential_Image
 * DESCRIPTION
 *  write sequential image
 * PARAMETERS
 *  pathname        [IN]        path name for sequential image
 *  output_name     [IN]        output variable name
 *  output_file     [OUT]       output file handle
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Write_Sequential_Image(
        char *pathname,
        char *output_name,
        ResgenImageOutStream * outstream,
        MMI_BOOL is9slice,
        S32 force_type,
        SetImageProcessData * processData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sequential_filesize[MAX_SEQUENTIAL_IMAGE_FRAME];
    S32 sequential_offset[MAX_SEQUENTIAL_IMAGE_FRAME];
    S8 filename[BUFFER_SIZE];
    FILE *imgfp;
    S32 sequential_frame;
    S32 sequence_counter;
    S32 n_frames;
    S32 type = -1;
    U32 width = 0, height = 0;
    U32 seq_max_width = 0, seq_max_height = 0;
    S32 j;
    U8 play_count = 0;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
#endif
    S32 sequential_interval[MAX_SEQUENTIAL_IMAGE_FRAME];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the right extension file name */
#if defined(__MMI_ALPHA_LAYER_SUPPORT__) || defined(__MMI_ALPHA_BLENDING__)
    for (j = SUPPORT_N_SEQUENTIAL_IMAGE_TYPE - 1; j >= 0; j--)  /* search from PNG */
#else /* defined(__MMI_ALPHA_LAYER_SUPPORT__) || defined(__MMI_ALPHA_BLENDING__) */
    for (j = 0; j < SUPPORT_N_SEQUENTIAL_IMAGE_TYPE; j++)       /* search from BMP */
#endif /* defined(__MMI_ALPHA_LAYER_SUPPORT__) || defined(__MMI_ALPHA_BLENDING__) */
    {
        sprintf(filename, "%s\\\\0.%s", pathname, sequential_image[j].filename_ext);
        if (file_exist(filename) )
        {
            type = j;
            break;
        }
    }
    if (type == -1)
    {
        return MMI_FALSE;
    }

    /* read during & find how many files are in sequence */
    sprintf(filename, "%s\\\\interval.txt", pathname);
    imgfp = fopen(filename, "r");
    if (imgfp == NULL)
    {
        RES_PRINT_INFO("ERR: Can't find %s\n", filename);
        return MMI_FALSE;
    }
    else
    {
        S32 count = 0;
        S32 duration;

        sequence_counter = 0;
        while(fscanf(imgfp, " %d", &duration) == 1)
        {
            sequential_interval[sequence_counter++] = duration;
        }

        /* we will recognize "LOOP " as prefix */
        play_count = (fscanf(imgfp, " LOOP %d", &count) == 1) ? ((U8)count) : (0);

        MYFCLOSE(imgfp);
    }

    for (j = 0; j < sequence_counter; j++)
    {
        sprintf(filename, "%s\\\\%d.%s", pathname, j, sequential_image[type].filename_ext);
        imgfp = fopen(filename, "rb");
        if (imgfp != NULL)
        {
            if (sequential_image[type].file_type == IMAGE_TYPE_BMP_SEQUENCE && force_type == FORCE_ABM_SEQUENCE)
            {
                U8 *buffer;
                S32 size, width, height, ret;
                FILE *outfp = NULL;

                const char *ext = "abms";
                U32 encode_option = ABM_ENC_OPTION_FLAG_ABM; /* ABM exactly */
                U32 want_ret = ABM_ENC_RETURN_USE_ABM;

                /* convert BMP to ABM */
                buffer = (U8*)malloc(ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(U8));
                if (buffer == NULL)
                {
                    RESIMG_LOG_E("Write_Sequential_image: buffer == NULL\n");
                    assert(0);
                    exit(2);
                }

                ret = ABM_load(filename,
                        __MMI_DEVICE_BMP_FORMAT__,
                        IMAGE_TYPE_BMP, /* non PBM */
                        encode_option,
                        buffer,
                        &size, &width, &height, is9slice, processData);

                sequential_filesize[j] = size;

                sprintf(filename, "%s\\\\%d.%s", pathname, j, ext);
                if (ret == want_ret)
                {
                    outfp = fopen(filename, "wb+");
                    if (outfp != NULL)
                    {
                        S32 wsize;

                        wsize = fwrite(buffer, sizeof(U8), size, outfp);
                        if (wsize != size)
                        {
                            RES_PRINT_INFO("[BMP->ABM sequence] size not match:\t%s\n", filename);
                        }
                        fclose(outfp);
                    }
                }
                else
                {
                    if(ABM_ENC_RETURN_KEEP_ORIGINAL == ret) /* add for CMCC TD */
                    {
                        S32 isize = 0, risize = 0;
                        force_type = AUTO_TYPE;
                        
                        fseek(imgfp, 0, SEEK_END);
                        isize = ftell(imgfp);
                        fseek(imgfp, 0, SEEK_SET);
                        risize = fread(buffer, sizeof(U8), isize, imgfp);
                        if(risize != isize)
                        {
                            RES_PRINT_INFO("[BMP->ABM sequence] read size not match:\t%s\n", filename);
                        }
				                
                        outfp = fopen(filename, "wb+");
                        if (outfp != NULL)
                        {
                            S32 wsize;
		                        
                            wsize = fwrite(buffer, sizeof(U8), risize, outfp);
                            if (wsize != risize)
                            {
                                RES_PRINT_INFO("[BMP->ABM sequence] write size not match:\t%s\n", filename);
                            }
                            fclose(outfp);
                        }
                        sequential_filesize[j] = isize;
                    }
                    else
                    {
                        RES_PRINT_INFO("[BMP->ABM sequence] err encode format:\t%s\n", filename);
                    }
                }

                free(buffer);
            }
#if defined(__MMI_ALPHA_BLENDING__) //&& !defined(GDI_USING_HW_PNG)
            /* If PNG, we will convert it to ABM or AB2 */
            else if (sequential_image[type].file_type == IMAGE_TYPE_ABM_SEQUENCE ||
                sequential_image[type].file_type == IMAGE_TYPE_AB2_SEQUENCE ||
                (sequential_image[type].file_type == IMAGE_TYPE_PNG_SEQUENCE && force_type == FORCE_ABM_SEQUENCE))
            {
                S8 tempBMPFile[BUFFER_SIZE];
                S8 tempCommand[SHELL_CMD_BUFLEN];
                U8 *buffer;
                S32 size, width, height, ret;
                FILE *outfp = NULL;

                const char *ext = "abms";
                U32 encode_option = ABM_ENC_OPTION_FLAG_ABM; /* ABM exactly */
                U32 want_ret = ABM_ENC_RETURN_USE_ABM;

                /* decide which format */
                if (sequential_image[type].file_type == IMAGE_TYPE_AB2_SEQUENCE)
                {
                    const char *ext = "ab2s";
                    U32 encode_option = ABM_ENC_OPTION_FLAG_AB2; /* AB2 exactly */
                    U32 want_ret = ABM_ENC_RETURN_USE_AB2;
                }

                /* convert PNG to 32-bits BMP */
                strcpy((char*)tempBMPFile, (const char*)filename);
                ChangeExtension(tempBMPFile, RES_IMAGE, IMAGE_TYPE_BMP);
                //sprintf(tempCommand, ".\\\\convert.exe -channel Alpha -negate -compress none %s %s 2>> .\\debug\\3rd_tool.log", filename, tempBMPFile);
                sprintf(tempCommand, ".\\\\convert.exe -channel Alpha -negate -compress none %s %s > NUL", filename, tempBMPFile);
                RES_PRINT_INFO("%s\n", tempCommand);
                system(tempCommand);

                /* convert 32-bits BMP to ABM */
                buffer = (U8*)malloc(ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(U8));
                ASSERT(buffer != NULL);

                ret = ABM_load(tempBMPFile,
                        __MMI_DEVICE_BMP_FORMAT__,
                        IMAGE_TYPE_PNG, /* non PBM */
                        encode_option,
                        buffer,
                        &size, &width, &height, is9slice, processData);

                sequential_filesize[j] = size;

                sprintf(tempBMPFile, "%s\\\\%d.%s", pathname, j, ext);
                if (ret == want_ret)
                {
                    outfp = fopen(tempBMPFile, "wb+");
                    if (outfp != NULL)
                    {
                        S32 wsize;

                        wsize = fwrite(buffer, sizeof(U8), size, outfp);
                        if (wsize != size)
                        {
                            RES_PRINT_INFO("[ABM sequence] size not match:\t%s\n", tempBMPFile);
                        }
                        fclose(outfp);
                    }
                }
                else
                {
                    RES_PRINT_INFO("[ABM sequence] err encode format:\t%s\n", tempBMPFile);
                }

                free(buffer);
            }
#endif /* defined(__MMI_ALPHA_BLENDING__) && !defined(GDI_USING_HW_PNG) */
            else
            {
                fseek(imgfp, 0, SEEK_END);
                sequential_filesize[j] = ftell(imgfp);
                fseek(imgfp, 0, SEEK_SET);
            }

            MYFCLOSE(imgfp);
        }
        else
        {
            return MMI_FALSE;
        }
    }

    /* write each image raw data */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    sprintf(filename, "%s\\\\0.%s", pathname, sequential_image[type].filename_ext);
    enfb_ret = Image_Test(filename, &enfb_width, &enfb_height, processData->disable_enfb);
    if (enfb_ret!= ENFB_IMAGE_NONE)
    {
        processData->enfb_flag = 1;
        if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
        {
            ENFBAssociatedIDAdded = MMI_TRUE;
        }
    }
#endif

    sequential_frame = sequence_counter;

    /* construct the data structure name */
    ImageOutStreamPrintf(outstream, "__align(4) const U8 %s%s", output_name, OUTPUT_IMAGE_NAMES_END);

    /* get width and height */
    for (j = 0; j < sequence_counter; j++)
    {
        sprintf(filename, "%s\\\\%d.%s", pathname, j, sequential_image[type].filename_ext);
        if (file_exist(filename) )
        {
            n_frames = Image_Get_Dimensions(filename, &width, &height);
            if (n_frames < 1)
            {
                RES_PRINT_INFO("Image get dimensions failed:\t%s\n", filename);
            }
            if (width > seq_max_width)
            {
                seq_max_width = width;
            }
            if (height > seq_max_height)
            {
                seq_max_height = height;
            }
        }
        else
        {
            return MMI_FALSE;
        }
    }

    /* write header of sequential images */

    if ((sequential_image[type].file_type == IMAGE_TYPE_PNG_SEQUENCE && force_type == FORCE_ABM_SEQUENCE) ||
        (sequential_image[type].file_type == IMAGE_TYPE_BMP_SEQUENCE && force_type == FORCE_ABM_SEQUENCE))
    {
        Write_Sequential_Image_Header(outstream, IMAGE_TYPE_ABM_SEQUENCE, sequential_frame, play_count, sequential_filesize, sequential_offset, seq_max_width, seq_max_height, sequential_interval, processData);
    }
    else
    {
        Write_Sequential_Image_Header(outstream, sequential_image[type].file_type, sequential_frame, play_count, sequential_filesize, sequential_offset, seq_max_width, seq_max_height, sequential_interval, processData);
    }

    /* load all files in the sequence   */
    for (j = 0; j < sequence_counter; j++)
    {
        if (sequential_image[type].file_type == IMAGE_TYPE_BMP_SEQUENCE && force_type == FORCE_ABM_SEQUENCE)
        {
            sprintf(filename, "%s\\\\%d.abms", pathname, j);
        }
#if defined(__MMI_ALPHA_BLENDING__) //&& !defined(GDI_USING_HW_PNG)
        else if (sequential_image[type].file_type == IMAGE_TYPE_ABM_SEQUENCE ||
            (sequential_image[type].file_type == IMAGE_TYPE_PNG_SEQUENCE && force_type == FORCE_ABM_SEQUENCE))
        {
            sprintf(filename, "%s\\\\%d.abms", pathname, j);
        }
        else if (sequential_image[type].file_type == IMAGE_TYPE_AB2_SEQUENCE)
        {
            sprintf(filename, "%s\\\\%d.ab2s", pathname, j);
        }
#endif /* defined(__MMI_ALPHA_BLENDING__) && !defined(GDI_USING_HW_PNG) */
        else
        {
            sprintf(filename, "%s\\\\%d.%s", pathname, j, sequential_image[type].filename_ext);
        }
        imgfp = fopen(filename, "rb");
        if (imgfp != NULL)
        {
            Write_Sequential_Image_File(outstream, imgfp, sequential_filesize[j], processData);
            MYFCLOSE(imgfp);
        }
        else
        {
            ImageOutStreamPrintf(outstream, "\n};\n");
            return MMI_FALSE;
        }
    }
    ImageOutStreamPrintf(outstream, "\n};\n");

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    processData->enfb_flag = 0;
#endif

    return MMI_TRUE;
}


static void Load_Image_Data_Tool(
        FILE *input_file,
        U32 file_size,
        S32 data_size,
        U8 image_identifier,
        S32 n_frames,
        U32 width,
        U32 height,
        MMI_BOOL is9slice,
        U8* _9slice_filename)
{
    U32 width_height;
    U32 i;

    width_height = ((width & 0XFFF) << 12) | (height & 0XFFF);
    if (is9slice)
    {
        fprintf(dest_file, "%c%c", IMAGE_TYPE_9SLICE, n_frames);
    }
    else
    {
        fprintf(dest_file, "%c%c", image_identifier, n_frames);
    }

    if (image_identifier == IMAGE_TYPE_3GP || image_identifier == IMAGE_TYPE_MP4 ||
        image_identifier == IMAGE_TYPE_AVI || image_identifier == IMAGE_TYPE_M3D ||
        image_identifier == IMAGE_TYPE_RV  || image_identifier == IMAGE_TYPE_RM  ||
        image_identifier == IMAGE_TYPE_RMVB || image_identifier == IMAGE_TYPE_SWFLASH)
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

    if (is9slice)
    {
        /* Write 9slice file header */
        mmi_rg_write_9slice_header(image_identifier, _9slice_filename, dest_file, MMI_TRUE);
    }

    for (i = 0; i < file_size; i++)
    {
        U8 ch;
        ch = fgetc(input_file);
        fputc(ch, dest_file);
    }
}

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__

static S32 Load_Image_Data_ENFB(
        FILE *input_file,
        U32 file_size,
        S32 data_size,
        U8 image_identifier,
        S32 n_frames,
        U32 width,
        U32 height,
        MMI_BOOL is9slice,
        U8* _9slice_filename)
{
    U32 width_height;
    U32 i;

    width_height = ((width & 0XFFF) << 12) | (height & 0XFFF);

    if (is9slice)
    {
        fprintf(enfb_img_data_file, "%c%c", IMAGE_TYPE_9SLICE, n_frames);
    }
    else
    {
        fprintf(enfb_img_data_file, "%c%c", image_identifier, n_frames);
    }
    if (image_identifier == IMAGE_TYPE_3GP || image_identifier == IMAGE_TYPE_MP4 ||
        image_identifier == IMAGE_TYPE_AVI || image_identifier == IMAGE_TYPE_M3D ||
        image_identifier == IMAGE_TYPE_RV  || image_identifier == IMAGE_TYPE_RM ||
        image_identifier == IMAGE_TYPE_RMVB || image_identifier == IMAGE_TYPE_SWFLASH)
    {
        fprintf(
            enfb_img_data_file,
            "%c%c%c%c%c%c",
            (file_size & 0xff),
            (file_size & 0xff00) >> 8,
            (file_size & 0xff0000) >> 16,
            (file_size & 0xff000000) >> 24,
            0,
            0);
        enfb_size = 8 + file_size;
    }
    else
    {
        fprintf(
            enfb_img_data_file,
            "%c%c%c%c%c%c",
            (data_size & 0xff),
            (data_size & 0xff00) >> 8,
            (data_size & 0xff0000) >> 16,
            (width_height & 0xff),
            (width_height & 0xff00) >> 8,
            (width_height & 0xff0000) >> 16);
        enfb_size = 8 + data_size;
    }

    if (is9slice)
    {
        /* Write 9slice file header */
        mmi_rg_write_9slice_header(image_identifier, _9slice_filename, enfb_img_data_file, MMI_TRUE);
    }

    enfb_offset += enfb_size;

    /* write image data to ENFB image data file */
    for (i = 0; i < file_size; i++)
    {
        U8 ch;
        ch = fgetc(input_file);
        fputc(ch, enfb_img_data_file);
    }
}

#endif // __MMI_RESOURCE_ENFB_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  Load_Image_Data
 * DESCRIPTION
 *  Identifies the image , BMP , ppf etc
 * PARAMETERS
 *  output_file             [IN]        -> Name of the file to which buffer
 *  input_file              [IN]        ->  Name of the input image file
 *  image_identifier        [IN]        -> image identifier
 *  n_frames                [IN]        -> no of frames
 *  is(?)                   [IN]        To be written
 * RETURNS
 *  S32 --> file size
 *****************************************************************************/
static S32 Load_Image_Data(
        ResgenImageOutStream * outstream,
        FILE *input_file,
        U8 image_identifier,
        S32 n_frames,
        U32 width,
        U32 height,
        MMI_BOOL is9slice,
        U8* _9slice_filename,
        SetImageProcessData * processData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_size, i;
    U32 width_height;
    S32 data_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(n_frames==0)
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
            RES_PRINT_INFO("\nImage is too big.\n");
            return 0;
        }
    }

    data_size = file_size;
    if (is9slice)
        data_size += 20;

    if (toolFlag)
    {
        Load_Image_Data_Tool(input_file, file_size, data_size, image_identifier, n_frames, width, height, is9slice, _9slice_filename);
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    else if (processData->enfb_flag == 1) /* write ENFB header to CustImgDataxxx.h and image header/data to ENFB image data file */
    {
        Load_Image_Data_ENFB(input_file, file_size, data_size, image_identifier, n_frames, width, height, is9slice, _9slice_filename);

        /* write ENFB header to CustImgDataxxx.h */
        ImageOutStreamPrintf(outstream,
            "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t",
            (U8) 255,                   //type
            (U8) ENFBAssociatedIDAdded, //associated id
            (U8) 0,                     //reserved
            (U8) 0,                     //reserved
            (U8) (enfb_offset & 0xff),
            (U8) ((enfb_offset >> 8) & 0xff),
            (U8) ((enfb_offset >> 16) & 0xff),
            (U8) ((enfb_offset >> 24) & 0xff),
            (U8) (enfb_size & 0xff),
            (U8) ((enfb_size >> 8) & 0xff),
            (U8) ((enfb_size >> 16) & 0xff),
            (U8) ((enfb_size >> 24) & 0xff));
    }
#endif
    else
    {
        if (is9slice)
        {
            ImageOutStreamPrintf(outstream, "\n\t0x%02X, 0x%02X, ", IMAGE_TYPE_9SLICE, n_frames);
        }
        else
        {
            ImageOutStreamPrintf(outstream, "\n\t0x%02X, 0x%02X, ", image_identifier, n_frames);
        }

        if (image_identifier == IMAGE_TYPE_3GP || image_identifier == IMAGE_TYPE_MP4 ||
            image_identifier == IMAGE_TYPE_AVI || image_identifier == IMAGE_TYPE_M3D ||
            image_identifier == IMAGE_TYPE_RV  || image_identifier == IMAGE_TYPE_RM  ||
            image_identifier == IMAGE_TYPE_RMVB || image_identifier == IMAGE_TYPE_SWFLASH)
        {
            ImageOutStreamPrintf(outstream,
                "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x00, 0x00,\n\t",
                (file_size & 0xff),
                (file_size & 0xff00) >> 8,
                (file_size & 0xff0000) >> 16,
                (file_size & 0xff000000) >> 24);
        }
        else
        {
            ImageOutStreamPrintf(outstream,
                "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t",
                (data_size & 0xff),
                (data_size & 0xff00) >> 8,
                (data_size & 0xff0000) >> 16,
                (width_height & 0xff),
                (width_height & 0xff00) >> 8,
                (width_height & 0xff0000) >> 16);
        }

        if (is9slice)
        {
            /* Write 9slice file header */
            mmi_rg_write_9slice_header(image_identifier, _9slice_filename, outstream, MMI_FALSE);
        }

        /*
        for (i = 0; i < file_size; i++)
        {
            U8 ch;
            ch = fgetc(input_file);
            ImageOutStreamPrintf(outstream, "%d,", ch);
            if (((i + 1) % 256) == 0)
            {
                ImageOutStreamPrintf(outstream, "\n");
            }
        }
        */
        const int buffer_size = 16 * 1024;
        int out_index = 0;
        while (1)
        {
            U8 buffer[buffer_size];
            U32 size = fread(buffer, 1, buffer_size, input_file);
            if (size == 0)
            {
                break;
            }
            for (i = 0; i < size; i++)
            {
                ImageOutStreamPrintf(outstream, "%d,", buffer[i]);
                if ((++out_index % 256) == 0)
                {
                    ImageOutStreamPrintf(outstream, "\n");
                }
            }
        }
    }

    return file_size + 8;
}


#if defined(__MMI_RESOURCE_IMAGE_COMPRESS__)

static void mmi_rg_set_compress(BOOL is_compress)
{
    g_is_compress = is_compress;
}

static U8* mmi_rg_compress_image_imp(U8 *buffer, S32 org_size, S32 *dest_size, S32 image_type, U32 width_height,  U8* symbol, image_type_enum extImageFlag, BOOL is9slice, U8* _9slice_filename, int n_frames)
{
    int array_size = 0;
    U8 *buffer_org = NULL;
    U8 *dest_buf = NULL;

    if(n_frames==0)
    {
        n_frames = 1;
    }

    array_size = org_size + 8;
    if(is9slice)
    {
        array_size += 20;
    }
    
    *dest_size = array_size*2;
    buffer_org = malloc(array_size);
    dest_buf = malloc(array_size * 2);

    if (buffer_org == NULL || dest_buf == NULL)
    {
        fprintf(stderr, "[ResZip]ABM compress Memory not enough buffer_org=[%d] dest_buf=[%d]\n", buffer_org, dest_buf);
        RESIMG_LOG_E("[ResZip]ABM compress Memory not enough buffer_org=[%d] dest_buf=[%d]\n", buffer_org, dest_buf);
        assert(0);
        exit(2);
    }

    /* resource header */
    if (is9slice)
    {
        sprintf(buffer_org, "%c%c", IMAGE_TYPE_9SLICE, n_frames);
    }
    else              
    {
        sprintf(buffer_org, "%c%c", image_type, n_frames);
    }

    /* data size, should sub 8 byte header */
    sprintf(buffer_org+2,
            "%c%c%c",
            ( (array_size - 8) & 0x000000ff),
            ( (array_size - 8) & 0x0000ff00) >> 8,
            ( (array_size - 8) & 0x00ff0000) >> 16);
    sprintf(buffer_org+5,
            "%c%c%c",
            (width_height & 0x000000ff),
            (width_height & 0x0000ff00) >> 8,
            (width_height & 0x00ff0000) >> 16);

    if(is9slice)
    {
        mmi_rg_get_9slice_header((U8)image_type, buffer_org + 8, _9slice_filename);
        memcpy(buffer_org+28, buffer, org_size);
    }
    else
    {
        memcpy(buffer_org+8, buffer, org_size);
    }

    compress2(dest_buf, dest_size, buffer_org, array_size, Z_BEST_COMPRESSION);

    free(buffer_org);

    if (*dest_size < array_size && array_size != 0 && *dest_size != 0  && (((array_size-(*dest_size))*100)/array_size) >= __MMI_RESOURCE_IMAGE_COMPRESS_RATE__)
    {
        /* compress rate > __MMI_RESOURCE_IMAGE_COMPRESS_RATE__ then compress, else write directly*/
        FILE *pFile;

        if(pFile = fopen(ZIP_OUTPUT_FILE, "a"))
        {
            fprintf(pFile, "%s,%d,%d,%d,Yes\n", symbol, array_size, *dest_size, array_size-*dest_size);
            fclose(pFile);
        }

        g_res_compress_data_image[g_res_compress_count_image].ro_len = *dest_size;
        g_res_compress_data_image[g_res_compress_count_image].zi_len = array_size;

        g_res_compress_count_image++;

        g_is_compressed = TRUE;

        return dest_buf;
    }
    else
    {
        FILE *pFile;

        if(pFile = fopen(ZIP_OUTPUT_FILE, "a"))
        {
            fprintf(pFile, "%s,%d,%d,%d,No\n", symbol, array_size, *dest_size, array_size-*dest_size);
            fclose(pFile);
        }
        free(dest_buf);
    }

    return NULL;
}

U8* mmi_rg_compress_image(U8 *buffer, S32 org_size, S32 *dest_size, S32 image_type, U32 width_height,  U8* symbol, image_type_enum extImageFlag, BOOL is9slice, U8* _9slice_filename, int n_frames)
{
    if (g_is_compress && extImageFlag == SYSTEM_IMAGE)
    {
        if (g_res_compress_count_image>= MAX_COMPRESSED_ITEM)
        {
            fprintf(stderr, "[ResZip] Image resource reach Max compress item count, please change MAX_COMPRESSED_ITEM [%d]\n", MAX_COMPRESSED_ITEM);
            RESIMG_LOG_E("[ResZip] Image resource reach Max compress item count, please change MAX_COMPRESSED_ITEM [%d]\n", MAX_COMPRESSED_ITEM);
            assert(0);
            exit(2);
        }
        return mmi_rg_compress_image_imp(buffer, org_size, dest_size, image_type, width_height, symbol, extImageFlag, is9slice, _9slice_filename, n_frames);

    }

    return NULL;
}


U8* mmi_rg_output_compressed_image(U8 *dest_buf, S32 dest_size, ResgenImageOutStream * outstream)
{
    U32 i;

    for (i = 0; i < dest_size-1; i++)
    {
        ImageOutStreamPrintf(outstream, "0x%02X, ", dest_buf[i]);
        if (((i + 1) % 16) == 0)
        {
            ImageOutStreamPrintf(outstream, "\n\t");
        }
    }
    ImageOutStreamPrintf(outstream, "0x%02X", dest_buf[i]);

    free(dest_buf);
}

#endif /* __MMI_RESOURCE_IMAGE_COMPRESS__ */

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
void mmi_rg_write_9slice_header(U8 real_imagetype, U8* _9slice_filename, ResgenImageOutStream * outstream, MMI_BOOL is_binary)
{
    U8 buffer[128];
    FILE *p_9slice_file;
    U32 x1,y1,x2,y2;
    U32 zoom_type;
    U32 do_dither; /* 1: no to do dithering,  0: try to do dithering*/

    p_9slice_file = fopen(_9slice_filename, "r");
    if (p_9slice_file == NULL)
    {
        fprintf(stderr, "\nErr opening %s", _9slice_filename);
        RESIMG_LOG_E("\nErr opening %s", _9slice_filename);
        assert(0);
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
        do_dither = 1;
    }
    else if (!(strcmp(buffer, "stretch")))
    {
        zoom_type = 1;
        do_dither = 0;
    }
    else if (!(strcmp(buffer, "stretch_no_dither")))
    {
        zoom_type = 1;
        do_dither = 1;
    }
    else
    {
        RES_PRINT_INFO("\n9slice file err, please write [repeat/stretch/stretch_no_dither], can not be[%s],set default value repeat\n", buffer);
        zoom_type = 0;
        do_dither = 0;
    }

    if (x1<0 || x1>1024 ||
        y1<0 || y1>1024 ||
        x2<0 || x2>1024 ||
        y2<0 || y2>1024)
    {
        fprintf(stderr, "\nErr in 9slice file [%s]\n", _9slice_filename);
        RESIMG_LOG_E("\nErr in 9slice file [%s]\n", _9slice_filename);
        assert(0);
        exit(2);
    }

    RES_PRINT_INFO("Write 9slice image header [%s]  position=[%d-%d-%d-%d] zoom=[%s]\n", _9slice_filename, x1, y1, x2, y2, buffer);
    if (is_binary)
    {
        const size_t buffer_size = 20;
        char temp_buffer[buffer_size + 1];
        sprintf(temp_buffer,
                "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
                (U8) real_imagetype,            //type
                (U8) zoom_type,                 //zoom type
                (U8) do_dither,                 //do_dither
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
        ImageOutStreamAppend(outstream, temp_buffer, buffer_size);
    }
    else
    {
        ImageOutStreamPrintf(outstream,
                "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, ",
                (U8) real_imagetype,            //type
                (U8) zoom_type,                 //zoom type
                (U8) do_dither,                 //do_dither
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
 *  mmi_rg_get_9slice_header
 * DESCRIPTION
 *  write 9slice header, include position and read file type to output file
 * PARAMETERS
 *  real_imagetype          [IN]        Real image type of 9slice images
 *  buff                         [IN/OUT]        9slice header
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_rg_get_9slice_header(U8 real_imagetype, U8 *buff/*IN/OUT*/, U8* _9slice_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buffer[128];
    FILE *p_9slice_file;
    U32 x1,y1,x2,y2;
    U32 zoom_type;
    U32 do_dither; /* 1: not to do dithering, 0: try to do dithering*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(buff == 0)
    {
        RESIMG_LOG_E("\nmmi_rg_get_9slice_header Err input \"buff\" parameter");
        exit(2);
    }

    p_9slice_file = fopen(_9slice_filename, "r");
    if (p_9slice_file == NULL)
    {
        fprintf(stderr, "\nErr opening %s", _9slice_filename);
        RESIMG_LOG_E("\nErr opening %s", _9slice_filename);
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
        do_dither = 1;
    }
    else if (!(strcmp(buffer, "stretch")))
    {
        zoom_type = 1;
        do_dither = 0;
        
    }
    else if (!(strcmp(buffer,"stretch_no_dither")))
    {
        zoom_type = 1;
        do_dither = 1;
    }
    else
    {
        RES_PRINT_INFO("\n9slice file err, please write [repeat/stretch/stretch_no_dither], can not be[%s],set default value repeat\n", buffer);
        zoom_type = 0;
        do_dither = 0;
    }

    if (x1<0 || x1>1024 ||
        y1<0 || y1>1024 ||
        x2<0 || x2>1024 ||
        y2<0 || y2>1024)
    {
        fprintf(stderr, "\nErr in 9slice file [%s]\n", _9slice_filename);
        RESIMG_LOG_E("\nErr in 9slice file [%s]\n", _9slice_filename);
        exit(2);
    }

    RES_PRINT_INFO("Write 9slice image header [%s]  position=[%d-%d-%d-%d] zoom=[%s]\n", _9slice_filename, x1, y1, x2, y2, buffer);

    /* 9slice data header */
    buff[0] = (U8) real_imagetype;
    buff[1] = (U8) zoom_type;
    buff[2] = (U8) do_dither;
    buff[3] = (U8) 0;
    buff[4] = (U8) ( x1 & 0xff);
    buff[5] = (U8) ((x1 >> 8) & 0xff);
    buff[6] = (U8) ((x1 >> 16) & 0xff);
    buff[7] = (U8) ((x1 >> 24) & 0xff);
    buff[8] = (U8) ( y1 & 0xff);
    buff[9] = (U8) ((y1 >> 8) & 0xff);
    buff[10] = (U8) ((y1 >> 16) & 0xff);
    buff[11] = (U8) ((y1 >> 24) & 0xff);
    buff[12] = (U8) ( x2 & 0xff);
    buff[13] = (U8) ((x2 >> 8) & 0xff);
    buff[14] = (U8) ((x2 >> 16) & 0xff);
    buff[15] = (U8) ((x2 >> 24) & 0xff);
    buff[16] = (U8) ( y2 & 0xff);
    buff[17] = (U8) ((y2 >> 8) & 0xff);
    buff[18] = (U8) ((y2 >> 16) & 0xff);
    buff[19] = (U8) ((y2 >> 24) & 0xff);

    return MMI_TRUE;
}


#ifdef __MMI_RESOURCE_ENFB_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  SetENFBAssociatedID
 * DESCRIPTION
 *  start to record associated ID list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL		MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL SetENFBAssociatedID(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* if flag = false, set flag = true, allocate memory, and no++ */
	if (ENFBAssociatedIDFlag == MMI_FALSE)
	{
		CUSTOM_ENFB_STR *enfb;
        int str_size = 256;
		int i;

		ENFBAssociatedIDFlag = MMI_TRUE;

		CurrMaxENFBAssociatedIDNum++;

		enfb = &ENFBAssociatedIDList[CurrMaxENFBAssociatedIDNum];
		enfb->count = 0;
		enfb->IDs = (U16 *)malloc(MAX_ASSOCIATED_LIST_IDS*sizeof(U16));
		enfb->Ptr = (S8 **)malloc(MAX_ASSOCIATED_LIST_IDS*sizeof(S8*));
		for (i = 0; i < MAX_ASSOCIATED_LIST_IDS ; i++)
		{
			enfb->Ptr[i] = (S8 *)malloc(str_size*sizeof(S8));
		}

		return MMI_TRUE;
	}
	/* error: cannot set flag twice */
	else
	{
		return MMI_FALSE;
	}
}



/*****************************************************************************
 * FUNCTION
 *  ResetENFBAssociatedID
 * DESCRIPTION
 *  end of one associated ID list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL		MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL ResetENFBAssociatedID(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* if flag = true, set flag = false */
	if (ENFBAssociatedIDFlag == MMI_TRUE)
	{
		ENFBAssociatedIDFlag = MMI_FALSE;

		/* if current associated list is empty, reuse it for next list */
		if (ENFBAssociatedIDList[CurrMaxENFBAssociatedIDNum].count == 0)
		{
			CurrMaxENFBAssociatedIDNum--;
		}

		return MMI_TRUE;
	}
	/* error: can not set flag = false twice */
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  GetCurrENFBAssociatedID
 * DESCRIPTION
 *  end of one associated ID list
 * PARAMETERS
 *  void
 * RETURNS
 *  U32		current associated ID
 *****************************************************************************/
static U16 GetCurrENFBAssociatedID(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (ENFBAssociatedIDFlag == MMI_TRUE)
	{
	    return CurrMaxENFBAssociatedIDNum;
	}
	else
	{
        return 0;
	}
}

/*****************************************************************************
 * FUNCTION
 *  AddENFBAssociatedIDItem
 * DESCRIPTION
 *  add item to current associated list
 * PARAMETERS
 *  ImageID		[IN]
 *  filename	[IN]
 * RETURNS
 *  MMI_BOOL		MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL AddENFBAssociatedIDItem(U16 ImageID, S8 *filename, image_type_enum ExtImageFlag)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* if flag = true, record this item: imagd ID & pointer variable */
	if (ENFBAssociatedIDFlag == MMI_TRUE)
	{
		CUSTOM_ENFB_STR *enfb;
        int i;

		enfb = &ENFBAssociatedIDList[CurrMaxENFBAssociatedIDNum];
		enfb->IDs[enfb->count] = ImageID;
		Extract_Name(enfb->Ptr[enfb->count], filename, ExtImageFlag);
        str_upper(enfb->Ptr[enfb->count], MAX_ASSOCIATED_LIST_IDS);
		enfb->count++;

		return MMI_TRUE;
	}
	/* if flag = false, do not record this item */
	else
	{
		return MMI_FALSE;
	}
}

/*****************************************************************************
 * FUNCTION
 *  IfItemExistENFBAssociatedID
 * DESCRIPTION
 *  test if the ImageID has already existed in one associated ID list
 * PARAMETERS
 *  ImageID     [IN]
 * RETURNS
 *  MMI_BOOL	MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL IfItemExistENFBAssociatedID(S8 *filename, image_type_enum ExtImageFlag)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
    int i, j, k;
    int str_size = 256;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    for (i = 1; i <= (int)CurrMaxENFBAssociatedIDNum; i++)
    {
		CUSTOM_ENFB_STR *enfb;
        S8 *ptr;

		enfb = &ENFBAssociatedIDList[i];
        for (j = 0; j <= (int)enfb->count; j++)
        {
            ptr = (S8 *)malloc(str_size*sizeof(S8));
            Extract_Name(ptr, filename, ExtImageFlag);
            str_upper(ptr, str_size);
            if (strcmp((char *)ptr, (char *)enfb->Ptr[j]) == 0)
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}
#endif // __MMI_RESOURCE_ENFB_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  SetFontResource
 * DESCRIPTION
 *  Function to add font resource
 * PARAMETERS
 *  FontId          [IN] resource ID
 *  filename        [IN] font data file name
 *  userdata        [IN] user data
 *  flags           [IN] additional flags for populating font resource
 * RETURNS
 *  void
 *****************************************************************************/
void SetFontResource(U16 FontID, S8 *filename, U32 userdata, S32 flags, S8 *enum_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_res_font_id = FontID;
    g_mmi_res_font_userdata = userdata;
    g_mmi_res_font_flags = flags;

    font_data_file = fopen(FONT_OUTPUT_DATA_FILENAME, "a");

    SetFontWithBuffer(FontID, filename, enum_value, TRUE);

    MYFCLOSE(font_data_file);

    g_mmi_res_font_userdata = 0;
    g_mmi_res_font_flags = 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetFontWithBuffer
 * DESCRIPTION
 *  Function to copy the Font file to buffer
 * PARAMETERS
 *  nImgId              [IN]
 *  filename            [?]
 *  enum_value          [?]
 *  res_type            [IN]
 *  fontFlag             [IN]
 *  S8(?)               [OUT]       -> filename of the image to be displayed.
 *  U16(?)              [IN]        -> ImageId
 * RETURNS
 *  void
 *****************************************************************************/
void SetFontWithBuffer(U16 nFontId, S8 *filename, S8 *enum_value, BOOL fontFlag)      /* 120304 Calvin modified for media resource */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 found = 0;
    S8 upperFileName[MAX_FILENAME_LEN];
    unsigned short *pCurrMaxFontId;
    unsigned short *pCurrMaxFontNum;
    FONTNAME_LIST *pFontNameList;
    CUSTOM_FONT_MAP *pFontIdMap;
    S8 filename_buffer[BUFFER_SIZE];
    S8 *real_filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pCurrMaxFontId = &CurrMaxFontIdEXT;
    pCurrMaxFontNum = &CurrMaxFontNumEXT;
    pFontNameList = FontNameListEXT;
    pFontIdMap = FontIdMapEXT;

    if (*pCurrMaxFontId >= MAX_IMAGE_IDS_SIZE)
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
    strncpy(upperFileName, filename, MAX_FILENAME_LEN);
    str_upper(upperFileName, MAX_FILENAME_LEN);

    if (pFontIdMap[nFontId].nFontNum != (U16)-1)
    {
        fprintf(RepeatIDListFile, "%d\t%s\t\t%s\n", nFontId, enum_value, "Font");
        return;
    }

    for (i = 0; i < *pCurrMaxFontNum; i++)
    {
        if (!strcmp(pFontNameList[i].filename, upperFileName))
        {
            found = 1;
            break;
        }
    }

    g_font_size = 0;
    real_filename = filename;

    if (found)
    {
        pFontIdMap[nFontId].nFontNum = i;
        (*pCurrMaxFontId)++;

        {
            S8 str1[MAX_IMAGE_NAMES_SIZE];
            S8 str2[MAX_IMAGE_NAMES_SIZE];
            U32 i, j;

            strncpy(str1, filename, MAX_IMAGE_NAMES_SIZE);
            str_upper(str1, MAX_IMAGE_NAMES_SIZE);

            for (i = 0; i < g_resimg_count; i++)
            {
                strncpy(str2, g_resimg_table[i].filename, MAX_IMAGE_NAMES_SIZE);
                str_upper(str2, MAX_IMAGE_NAMES_SIZE);
                if (strcmp(str1, str2) == 0)
                {
                    g_font_size = g_resimg_table[i].size;
                    real_filename = g_resimg_table[i].real_filename;
                    break;
                }
            }
        }
        RESPRTONERECORD(fpImageResourceUsage, nFontId, real_filename, enum_value, g_font_size);
    }
    else
    {
        if (Fload(upperFileName))
        {
            strcpy(pFontNameList[*pCurrMaxFontNum].filename, upperFileName);
            pFontIdMap[nFontId].nFontNum = *pCurrMaxFontNum;
            (*pCurrMaxFontNum)++;
            (*pCurrMaxFontId)++;

            g_resimg_table[g_resimg_count].size = g_font_size;
            strcpy(g_resimg_table[g_resimg_count].filename, filename);
            strcpy(g_resimg_table[g_resimg_count].real_filename, real_filename);
            g_resimg_count ++;
            RESPRTONERECORD(fpImageResourceUsage, nFontId, real_filename, enum_value, g_font_size);
        }
        /* CustPack: let new set of images share the same resource of default image */
        else
        {
            if (toolFlag)
            {
                resultFailFlag = 1;
            }
            RESIMG_LOG_E("Fload failed: %s(%d), PATH=%s", enum_value, nFontId, upperFileName);
            RES_LOG_PENDING_FATAL(RESIMG_TAG, "Error!! Fload FAIL !!","mtk_resgenerator return error.","Please check the error message of TAG [WRITEIMGRES] in log file:resgen_mtk_resgenerator_run.log");
            /*
            strcpy(FontNameListEXT[CurrMaxImageNum].filename, DEFAULT_FILEBUFFER);
            ImageIdMap[nFontId].nImageNum = CurrMaxImageNum;
            CurrMaxImageNum++;
            CurrMaxImageId++;*/
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Fload
 * DESCRIPTION
 *  load the file image to buffer and writes to CustImgRes.c, etc.
 * PARAMETERS
 *  string      [IN]        string containing file name and path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL Fload(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *image_data_file = NULL;
    S32 i;
    S8 tempCommand[SHELL_CMD_BUFLEN];
    U8 image_identifier = IMAGE_TYPE_TTF;
    U32 file_size;
    U8 ch;
    S8 * output_image_names = NULL;
    S8 filename_buffer[BUFFER_SIZE];
    S8 *real_filename = NULL;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
    int enfb_flag = 0;
    int disable_enfb = 0;
#endif
#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    static U8 count = 0;
    static U32 offset = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* set output variable name of the resource */
    output_image_names = (S8*) malloc(MAX_FILENAME_LEN);
    strcpy(filename_buffer, string);
    if (!(strcmp(filename_buffer, "")))
    {
        strcpy(filename_buffer, NOIMAGE_FILENAMEBUFFER);
    }
    Extract_Name(output_image_names, filename_buffer, EXT_FONT);

    real_filename = filename_buffer;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    enfb_ret = Image_Test(filename_buffer, &enfb_width, &enfb_height, disable_enfb);
    if (enfb_ret != ENFB_IMAGE_NONE)
    {
        enfb_flag = 1;
        if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
        {
            ENFBAssociatedIDAdded = MMI_TRUE;
        }
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    image_data_file = fopen(filename_buffer, "rb");

    /* Check if file open is successful or not. */
    if(image_data_file == NULL)
    {    
        return MMI_FALSE;
    }
    
    fseek(image_data_file, 0, SEEK_END);
    file_size = ftell(image_data_file);
    fseek(image_data_file, 0, SEEK_SET);

    if (toolFlag)
    {
        fprintf(
            dest_file,
            "%c%c%c%c%c%c%c%c",
            image_identifier,
            (g_mmi_res_font_userdata & 0xff),
            (g_mmi_res_font_userdata & 0xff00) >> 8,
            (g_mmi_res_font_userdata & 0xff0000) >> 16,
            (file_size & 0xff),
            (file_size & 0xff00) >> 8,
            (file_size & 0xff0000) >> 16,
            (file_size & 0xff000000) >> 24);

        for (i = 0; i < file_size; i++)
        {
            ch = fgetc(image_data_file);

            fputc(ch, dest_file);
        }
    }

#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    else if(g_mmi_res_font_flags & MMI_RES_FLAG_FONT_IS_ENFB)
    {
        
        for (i = 0; i < file_size; i++)
        {
            ch = fgetc(image_data_file);
            fputc(ch, enfb_font_data_file);
        }

        ENFBFontResInfo[count].offset = offset;
        ENFBFontResInfo[count].size = file_size;
        ENFBFontResInfo[count].res_id = ++count;

        offset += file_size;
    }
#endif

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    else if (enfb_flag == 1) /* write ENFB header to CustFontDataxxx.h and Font header/data to ENFB Font data file */
    {
        /* write Font header to ENFB Data File */
        fprintf(
            enfb_img_data_file,
            "%c%c%c%c%c%c%c%c",
            image_identifier,
            (g_mmi_res_font_userdata & 0xff),
            (g_mmi_res_font_userdata & 0xff00) >> 8,
            (g_mmi_res_font_userdata & 0xff0000) >> 16,
            (file_size & 0xff),
            (file_size & 0xff00) >> 8,
            (file_size & 0xff0000) >> 16,
            (file_size & 0xff000000) >> 24);
        enfb_size = 8 + file_size;

        /* write ENFB header to CustImgDataxxx.h */

        fprintf(font_data_file, "const U8 %s%s", output_image_names, OUTPUT_IMAGE_NAMES_END);

        fprintf(
            font_data_file,
            "\n\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t",
            (U8) 255,                   //type
            (U8) ENFBAssociatedIDAdded, //associated id
            (U8) 0,                     //reserved
            (U8) 0,                     //reserved
            (U8) (enfb_offset & 0xff),
            (U8) ((enfb_offset >> 8) & 0xff),
            (U8) ((enfb_offset >> 16) & 0xff),
            (U8) ((enfb_offset >> 24) & 0xff),
            (U8) (enfb_size & 0xff),
            (U8) ((enfb_size >> 8) & 0xff),
            (U8) ((enfb_size >> 16) & 0xff),
            (U8) ((enfb_size >> 24) & 0xff));

        fprintf(font_data_file, "\n };\n");

        enfb_offset += enfb_size;


        for (i = 0; i < file_size; i++)
        {
            ch = fgetc(image_data_file);

            if (toolFlag)
            {
                fputc(ch, dest_file);
            }

        #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            /* write image data to ENFB image data file */
            else if (enfb_flag == 1)
            {
                fputc(ch, enfb_img_data_file);
            }
        #endif

            else
            {
                /* Err, only handle ENFB in this function. */
                fprintf(stderr, "Err, only handle ENFB in this function\n");
                RESIMG_LOG_E("Err, only handle ENFB in this function\n");  				
                assert(0);
                exit(2);
            }
        }
    }
#endif

    else
    {
        /* Handle Vector Font */
        /* convert font data to obj file */
        S8 tempCommand[SHELL_CMD_BUFLEN*2];
        FILE *font_obj_file = NULL;
        FILE *font_org_file = NULL;
        S32 section_offset = 0;
        U32 size = 0;
        U16 nType = 0;

        nType = ExtractExtension(filename_buffer, RES_FONT);


        /* Write temp ttf file with header */
        sprintf(tempCommand, "vf_%d.tmp", g_mmi_res_font_id);
        font_obj_file = fopen(tempCommand, "w+b");
        ASSERT(font_obj_file != NULL);
        font_org_file = fopen(real_filename, "rb");
        ASSERT(font_org_file != NULL);

        fseek(font_org_file, 0, SEEK_END);
        size = ftell(font_org_file);
        fseek(font_org_file, 0, SEEK_SET);

        fprintf(
            font_obj_file,
            "%c%c%c%c%c%c%c%c",
            nType,
            (g_mmi_res_font_userdata & 0xff),
            (g_mmi_res_font_userdata & 0xff00) >> 8,
            (g_mmi_res_font_userdata & 0xff0000) >> 16,
            (size & 0xff),
            (size & 0xff00) >> 8,
            (size & 0xff0000) >> 16,
            (size & 0xff000000) >> 24);
        RES_PRINT_INFO("[Font]Type=[%d], g_mmi_res_font_userdata=[%d], size=[%d]\n", nType, g_mmi_res_font_userdata, size);

        while (!feof(font_org_file))
        {
            S8 buffer[200];
            size_t size;

            size = fread(buffer, 1, 200, font_org_file);
            if (size)
            {
                fwrite(buffer, 1, size, font_obj_file);
            }
        }

        MYFCLOSE(font_obj_file);
        MYFCLOSE(font_org_file);
        font_obj_file = NULL;
        font_org_file = NULL;


        /* Get name gen by objcopy */
        sprintf(tempCommand, "objcopy -I binary -O pe-i386 --rename-section .data=.rdata --set-section-flags .data=contents,alloc,load,data,readonly --redefine-sym _binary_vf_%d_tmp_start=_%s -B i386 vf_%d.tmp modis_vf_%d.obj", g_mmi_res_font_id, output_image_names, g_mmi_res_font_id, g_mmi_res_font_id);
        RES_PRINT_INFO("%s\n", tempCommand);
        ASSERT(SHELL_CMD_BUFLEN*2 > strlen(tempCommand));
        system(tempCommand);

        sprintf(tempCommand, "objcopy -I binary -O elf32-little --rename-section .data=.rdata --set-section-flags .data=contents,alloc,load,data,readonly --redefine-sym _binary_vf_%d_tmp_start=%s  -B i386 vf_%d.tmp vf_%d.obj", g_mmi_res_font_id, output_image_names, g_mmi_res_font_id, g_mmi_res_font_id);
        RES_PRINT_INFO("%s\n", tempCommand);
        ASSERT(SHELL_CMD_BUFLEN*2 > strlen(tempCommand));
        system(tempCommand);

        /* Fix obj alignment to 4 bytes */
        /* 1. Open the file just created */
        sprintf(tempCommand, "vf_%d.obj", g_mmi_res_font_id);
        font_obj_file = fopen(tempCommand, "r+b");
        if (font_obj_file != NULL)
        {
            /* 2. Read header offset */
            fseek(font_obj_file, 32, SEEK_SET);
            size = fread(&section_offset, 4, 1, font_obj_file);
            RES_PRINT_INFO("[Font]section offset = [%d]\n", section_offset);

            /* 3. Jump to the position and modify it to 4. */
            fseek(font_obj_file, section_offset + 40 + 32, SEEK_SET);
            fputc(4, font_obj_file);

            /* 4. Close the file */
            MYFCLOSE(font_obj_file);
        }

        fprintf(font_data_lis, "plutommi\\Customer\\ResGenerator\\vf_%d.obj\n", g_mmi_res_font_id);
        fprintf(font_data_modis_lis, "plutommi\\Customer\\ResGenerator\\modis_vf_%d.obj\n", g_mmi_res_font_id);
        fprintf(font_ttf_lis, "%s\n", filename_buffer);
        fprintf(font_data_file, "extern const U8 %s[];\n", output_image_names);
    }

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    enfb_flag = 0;
#endif
    MYFCLOSE(image_data_file);
    free(output_image_names);

    return TRUE;
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
static U8 isSubmenuImage(S8 *path)
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
    /*
     * submenu_len = strlen(submenu_path);
     * pos = strlen (path)-1;
     * while (path[pos]!='\\') pos--;
     * pos-=submenu_len+1;
     * for ( i=0; i<submenu_len; i++){
     * if ( submenu_path[i] != path[pos] ) return 0;
     * else pos++;
     * }
     * return 1;
     */
#endif /* __MMI_SLIM_LISTMENU_NUMBER__ */
}


#if defined(__MULTIPLE_BINARY_FILES__) && defined(__MMI_RESOURCE_ENFB_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  CustPack_ENFB_image_test
 * DESCRIPTION
 *  For E-NFB image, we will compulsorily put it into custpack.
 * PARAMETERS
 *  filename            [IN]
 * RETURNS
 *  BOOL
 *****************************************************************************/
MMI_BOOL CustPack_ENFB_image_test(const S8 *filename, int disable_enfb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 w, h;
    S32 ret, i, j;
    MMI_BOOL test = MMI_FALSE;
    S8 tempfilename[MAX_FILENAME_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempfilename, 0, (MAX_FILENAME_LEN*sizeof(S8)));

    get_available_image_filename(filename, tempfilename);
    if (file_exist(tempfilename) == MMI_TRUE)
    {
        ret = Image_Test(tempfilename, &w, &h, disable_enfb);
        test = (ret != ENFB_IMAGE_NONE) ? (MMI_TRUE) : (MMI_FALSE);
    }
    else
    {   /* for sequence image */
        memset(tempfilename, 0, (MAX_FILENAME_LEN*sizeof(S8)));
#if defined(__MMI_ALPHA_LAYER_SUPPORT__) || defined(__MMI_ALPHA_BLENDING__)
        for (i = SUPPORT_N_SEQUENTIAL_IMAGE_TYPE - 1 ; i >= 0 ; i--)    /* search from PNG */
#else /* defined(__MMI_ALPHA_LAYER_SUPPORT__) || defined(__MMI_ALPHA_BLENDING__) */
        for (i = 0 ; i < SUPPORT_N_SEQUENTIAL_IMAGE_TYPE ; i++)         /* search from BMP */
#endif /* defined(__MMI_ALPHA_LAYER_SUPPORT__) || defined(__MMI_ALPHA_BLENDING__) */
        {
            sprintf(tempfilename, "%s\\\\0.%s", filename, sequential_image[i].filename_ext);
            str_upper(tempfilename, MAX_FILENAME_LEN);
            if (file_exist(tempfilename) == MMI_TRUE)   break;
        }
        if (file_exist(tempfilename) == MMI_TRUE)
        {
            ret = Image_Test(tempfilename, &w, &h, disable_enfb);
            test = (ret != ENFB_IMAGE_NONE) ? (MMI_TRUE) : (MMI_FALSE);
        }
    }

    return test;
}
#endif /* defined(__MULTIPLE_BINARY_FILES__) && defined(__MMI_RESOURCE_ENFB_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  get_available_image_filename
 * DESCRIPTION
 *  change the filename extension for available image file
 *  TODO: should inlcude sequence file and return type
 * PARAMETERS
 *  in_filename     [IN]
 *  out_filename    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void get_available_image_filename(const S8 *in_filename, S8* out_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ext_type = -1, i, count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strncpy(out_filename, in_filename, MAX_FILENAME_LEN);
    str_upper(out_filename, MAX_FILENAME_LEN);

    do
    {
        if (file_exist(out_filename) == MMI_TRUE)   break;

        ext_type = ExtractExtension(out_filename, RES_IMAGE);

        /* check PNG -> all type */
        if (ext_type == IMAGE_TYPE_PNG)
        {
            count = sizeof(image_resource_info)/sizeof(RESOURCE_INFO);
            for (i = 0 ; i < count ; i++)
            {
                ChangeExtension(out_filename, RES_IMAGE, image_resource_info[i].file_type);
                if (file_exist(out_filename) == MMI_TRUE)   break;
            }
            if (i != count) break;
        }

#if defined(__MMI_ALPHA_LAYER_SUPPORT__)
        /* check GIF / BMP -> PNG */
        if ((ext_type == IMAGE_TYPE_GIF) || (ext_type == IMAGE_TYPE_BMP))
        {
            ChangeExtension(out_filename, RES_IMAGE, IMAGE_TYPE_PNG);
            if (file_exist(out_filename) == MMI_TRUE)   break;
        }

        /* check PBMP -> PPN */
        if (ext_type == IMAGE_TYPE_DEVICE_BITMAP)
        {
            ChangeExtension(out_filename, RES_IMAGE, IMAGE_TYPE_PPN);
            if (file_exist(out_filename) == MMI_TRUE)   break;
        }
#endif /* defined(__MMI_ALPHA_LAYER_SUPPORT__) */

        /* check BMP -> GIF */
        if (ext_type == IMAGE_TYPE_BMP)
        {
            ChangeExtension(out_filename, RES_IMAGE, IMAGE_TYPE_GIF);
            if (file_exist(out_filename) == MMI_TRUE)   break;
        }

        /* check GIF -> BMP */
        if (ext_type == IMAGE_TYPE_GIF)
        {
            ChangeExtension(out_filename, RES_IMAGE, IMAGE_TYPE_BMP);
            if (file_exist(out_filename) == MMI_TRUE)   break;
        }

        /* check video */
        for (i = 0 ; i < SUPPORT_N_MEDIA_TYPE ; i++)
        {
            S32 j, len;

            len = strlen(out_filename);
            for (j = 0 ; j < 3 ; j++)
            {
                out_filename[len - 1 - j] = support_media_ext[i][2 - j];
            }
            if (file_exist(out_filename) == MMI_TRUE)   break;
        }
        if (i != SUPPORT_N_MEDIA_TYPE)  break;
    } while (0);
}


