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
 *  WriteResUtil.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __WRITE_RES_UTIL_H__
#define __WRITE_RES_UTIL_H__

#include "CustDataRes.h"
#include "gui_resource_type.h" // for IMAGE_TYPE_BMP

#define MYFCLOSE(fp)    \
    do                  \
    {                   \
        if (fp != NULL) \
        {               \
            fclose(fp); \
            fp = NULL;  \
        }               \
    } while (0)


//  Log image information for Artist
//  We have to separate the log file form original image usage one.
//  since the image usage report is used by THEME, Custpack and MTE tool,
//  we can't change it format.
#define RES_IMG_RECORD_EXT(fp, data, colorNum, size) \
    do                             \
    {                              \
        fprintf(fp, "%s\t%d\t%d\n",    \
                data, colorNum, size);  \
    } while(0)                     \

#define RESPRTONERECORD_IMG_EXT(fpUsage, fpExt, nImgId, data, strID, ressize, colorNum)  \
    do                                                                                        \
    {                                                                                         \
        RESPRTONERECORD(fpUsage, nImgId, data, strID, ressize);                          \
        RES_IMG_RECORD_EXT(fpExt, data, colorNum, ressize);                                                  \
    } while(0)                                                                                \

#define RESPRT(fp, app, base, ID, strID, size, data)            \
    do                                                          \
    {                                                           \
        fprintf(fp, "%s\t%d\t%d\t%s\t%d\t%s\tNA\n",             \
                app, base, ID, strID, size, data);     \
    } while (0)

#define RESPRTONERECORD(fp, nImgId, data, enum_value, ressize)      \
    do                                                              \
    {                                                               \
        if (fp != NULL)                                             \
        {                                                           \
            U32 offset = GetOffsetFromResourceBase(nImgId, enum_value);  \
            if (offset == 0xFFFFFFFF)                               \
            {                                                       \
                RESPRT(fp, "NO_APP", -1, nImgId, enum_value,        \
                       ressize, data);                   \
            }                                                       \
            else                                                    \
            {                                                       \
                RESPRT(fp,                                          \
                       g_mmi_resource_base_table[offset].appname,   \
                       g_mmi_resource_base_table[offset].min,       \
                       nImgId, enum_value, ressize, data);          \
            }                                                       \
        }                                                           \
    } while (0)

#define SHELL_CMD_BUFLEN            (MAX_FILENAME_LEN + 100)
#define BUFFER_SIZE                 4096
#define RES_IMG_COLOR_NUM_UNKNOWN   -1

typedef struct Resource_Info
{
    S8 *filename_ext;
    U8 file_type;
} RESOURCE_INFO;

static const RESOURCE_INFO image_resource_info[] =
{
    {"BMP", IMAGE_TYPE_BMP},
    {"PBM", IMAGE_TYPE_DEVICE_BITMAP},
    {"JPG", IMAGE_TYPE_JPG},
    {"GIF", IMAGE_TYPE_GIF},
    {"ABM", IMAGE_TYPE_ABM},
    {"AVI", IMAGE_TYPE_AVI},
    {"3GP", IMAGE_TYPE_3GP},
    {"MP4", IMAGE_TYPE_MP4},
    {"RV",  IMAGE_TYPE_RV},
    {"RM",  IMAGE_TYPE_RM},
    {"RMVB", IMAGE_TYPE_RMVB},
    {"PNG", IMAGE_TYPE_PNG},
    {"PPN", IMAGE_TYPE_PPN},
    {"M3D", IMAGE_TYPE_M3D},
    {"CMP", IMAGE_TYPE_SWFLASH},
    {"VIS", IMAGE_TYPE_VIS},
    {"SVG", IMAGE_TYPE_SVG},
    {"TTF", IMAGE_TYPE_TTF},
    {"STF", IMAGE_TYPE_TTF},
    {"CCC", IMAGE_TYPE_TTF},
    {"KTX", IMAGE_TYPE_KTX}
};


extern const RESOURCE_INFO audio_resource_info[];

#define SUPPORT_N_MEDIA_TYPE     6
extern const S8 *support_media_ext[SUPPORT_N_MEDIA_TYPE];

#define SUPPORT_N_SEQUENTIAL_IMAGE_TYPE 3

extern const RESOURCE_INFO sequential_image[SUPPORT_N_SEQUENTIAL_IMAGE_TYPE];


// mtk_resgenerator error flag
extern MMI_BOOL mtk_resgen_has_error();

extern MMI_BOOL mtk_resgen_set_error();

extern MMI_BOOL mtk_resgen_reset_error();

// functions
extern MMI_BOOL file_exist(S8* filename);

extern MMI_BOOL is_directory(S8* filename);

extern U32 resgen_compare_file_time(S8* file1, S8* file2);

extern U8 ExtractExtension(S8 *src, U32 res_type);

extern BOOL ChangeExtension(S8 *src, U32 res_type, S32 ext_type);

extern void setResgenImgPostProcess(MMI_BOOL resgen_img_post_process);

extern MMI_BOOL getResgenImgPostProcess();

extern void ProcessResgenPngImages();

struct _ResgenImageOutStream;

typedef struct _ResgenImageOutStream ResgenImageOutStream;

typedef struct _SetImageProcessData
{
    S8 real_filename[MAX_FILENAME_LEN];
    S32 res_size;
    ResgenImageOutStream * outstream;
    MMI_BOOL failed;
    MMI_BOOL duplicated;
    struct _SetImageProcessData * duplicatedInstance;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    int enfb_flag;
    int disable_enfb;
#endif
    S32 quality;
    long color_num;
} SetImageProcessData;

// write image res function prototype
extern void SetImageWithBufferExImp(
        U16 nImgId,
        S8 *filename,
        S8 *enum_value,
        BOOL imgFlag,
        S32 force_type,
        SetImageProcessData * processData);

extern MMI_BOOL Iload(S8 *string,
        image_type_enum extImageFlag,
        S32 force_type,
        SetImageProcessData * processData);

extern void SetNFBImageImp(S8 *filename, SetImageProcessData * processData);

extern int BMPLoader(char *in_filename, char *out_filename, S8 color_depth, U8* _9slice_filename, MMI_BOOL is9slice, SetImageProcessData * processData);

extern int bmp2ems(char *in_filename, ResgenImageOutStream * outstream, int binary_flag, int verbose_flag, SetImageProcessData * processData);

extern void mmi_rg_write_9slice_header(U8 real_imagetype, U8* _9slice_filename, ResgenImageOutStream * outstream, MMI_BOOL is_binary);

extern void initImageProcessData(SetImageProcessData * data);

extern void Extract_Name(S8 *dest, S8 *src, U32 extFlag);

void ImageOutStreamInit(ResgenImageOutStream ** pStream);

void ImageOutStreamDeinit(ResgenImageOutStream ** pStream);

void ImageOutStreamPrintf(ResgenImageOutStream * stream, char* fmt, ...);

void ImageOutStreamAppend(ResgenImageOutStream * stream, char* buffer, U32 size);

void ImageOutStreamOutputFile(ResgenImageOutStream * stream, FILE * out_file);

void str_upper(char* str, unsigned int max_length);

void LogSetBinaryWithBuffer(
        U16 res_id,
        S8 *filename,
        int binary_type_flag);

#endif // __WRITE_RES_UTIL_H__

