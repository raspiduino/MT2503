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
 *  FileManagerResDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager Defines
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _FMGR_SERV_RES_DEF_H_
#define _FMGR_SERV_RES_DEF_H_


#include "FileMgrResDef.h"

typedef enum
{
    FMGR_SERV_SCR_BEGIN = NO_OF_FMGR_SCR,

    SCR_ID_FMGR_JPG_DETAIL,
    SCR_ID_FMGR_VIEW_IMAGE,

    SCR_FMGR_RIGHTS_DETAIL,
    SCR_FMGR_DRM_RIGHTS_OPTION,

    SCR_FMGR_PRINT_OPTION,

    SCR_FMGR_DLT_MOVE_WAIT,

    SCR_ID_FMGR_FORWARD_DUMMY,

    NO_OF_FMGR_SERV_SCR
} FMGR_SERV_SCR_IDS;

typedef enum
{
    FMGR_SERV_STR_BEGIN = NO_OF_FMGR_TEXT,

    STR_FMGR_VIEW_IMG_JPG_DETAIL,

    STR_ID_FMGR_FWD_CONTACT,
    STR_FMGR_BGSOUND,
    STR_FMGR_UDX,

    STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE,
    STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LARGE,
    STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LONG,
    STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE,
    STR_ID_FMGR_FILE_LIMIT,

    STR_FMGR_ACTIVATE_THEME,
    STR_FMGR_THEME_OPTION,
    STR_ID_FMGR_THEME_INCORRECT_LOCATION,
    STR_ID_FMGR_ACTIVE_THEME_DELETE,
    STR_ID_FMGR_SPACE_NOT_AVAILABLE,
    STR_ID_THEME_ERROR_FAILURE,
    STR_ID_FMGR_ALREADY_ACTIVE,
    STR_ID_FMGR_MAX_COUNT_REACHED,

    STR_ID_FMGR_EXIF_MAKE,
    STR_ID_FMGR_EXIF_MODEL,
    STR_ID_FMGR_EXIF_ORIENTATION,
    STR_ID_FMGR_EXIF_X_RESOLUTION,
    STR_ID_FMGR_EXIF_Y_RESOLUTION,
    STR_ID_FMGR_EXIF_RESOLUTION_UNIT,
    STR_ID_FMGR_EXIF_SOFTWARE,
    STR_ID_FMGR_EXIF_DATE_TIME,
    STR_ID_FMGR_EXIF_YCBCR_POSITIONING,
    STR_ID_FMGR_EXIF_EXIF_IFD,

    STR_ID_FMGR_EXIF_EXPOSURE_TIME,
    STR_ID_FMGR_EXIF_FNUMBER,
    STR_ID_FMGR_EXIF_EXPOSURE_PROGRAM,
    STR_ID_FMGR_EXIF_ISO_SPEED_RATINGS,
    STR_ID_FMGR_EXIF_EXIF_VERSION,
    STR_ID_FMGR_EXIF_DATE_TIME_ORIGINAL,
    STR_ID_FMGR_EXIF_DATE_TIME_DIGITIZED,
    STR_ID_FMGR_EXIF_COMPONENTS_CONFIG,
    STR_ID_FMGR_EXIF_EXPOSURE_BIAS_VALUE,
    STR_ID_FMGR_EXIF_METERING_MODE,
    STR_ID_FMGR_EXIF_LIGHT_SOURCE,
    STR_ID_FMGR_EXIF_FLASH,
    STR_ID_FMGR_EXIF_MAKER_NOTE,
    STR_ID_FMGR_EXIF_FLASHPIX_VERSION,
    STR_ID_FMGR_EXIF_COLOR_SPACE,
    STR_ID_FMGR_EXIF_PIXEL_X_DIMENSION,
    STR_ID_FMGR_EXIF_PIXEL_Y_DIMENSION,
    STR_ID_FMGR_EXIF_EXPOSURE_MODE,
    STR_ID_FMGR_EXIF_DIGITAL_ZOOM_RATIO,
    STR_ID_FMGR_EXIF_SCENE_CAPTURE_TYPE,
    STR_ID_FMGR_EXIF_NO_INFORMATION,

    STR_ID_FMGR_TO_PICTBRIGE,

    STR_FMGR_VBM_GOTO,

    //STR_FMGR_UMMS_TO_BLOG,
    //STR_FMGR_UMMS_TO_POSTCARD,
    
    NO_OF_FMGR_SERV_TEXT
} FMGR_SERV_STRING_IDS;

typedef enum
{
    IMG_ID_FMGR_SERV_BEGIN = NO_OF_FMGR_IMG,
        
   /******* small icon ********/
    IMG_ID_FMGR_ICON_FILE_TYPE_IMG,
    IMG_ID_FMGR_ICON_FILE_TYPE_MSG, /* SMS, EMS image */
    IMG_ID_FMGR_ICON_FILE_TYPE_AUD,
    IMG_ID_FMGR_ICON_FILE_TYPE_VDO,
    IMG_ID_FMGR_ICON_FILE_TYPE_JAVA,
    IMG_ID_FMGR_ICON_FILE_TYPE_VCF,
    IMG_ID_FMGR_ICON_FILE_TYPE_VCS,
    IMG_ID_FMGR_ICON_FILE_TYPE_SVG,
    IMG_ID_FMGR_ICON_FILE_TYPE_THEME,
    IMG_ID_FMGR_ICON_FILE_TYPE_MBC,
    IMG_ID_FMGR_ICON_FILE_TYPE_SWFLASH,
    IMG_ID_FMGR_ICON_FILE_TYPE_UDX,
    IMG_EBOOK_FMGR_NFO_SMALL_TYPE,
    IMG_EBOOK_FMGR_TXT_SMALL_TYPE,
    IMG_EBOOK_FMGR_PDB_SMALL_TYPE,

    /******* large icon ********/
    /* image */
    IMG_ID_FMGR_FILE_TYPE_BMP,
    IMG_ID_FMGR_FILE_TYPE_JPG,
    IMG_ID_FMGR_FILE_TYPE_GIF,
    IMG_ID_FMGR_FILE_TYPE_PNG,
    IMG_ID_FMGR_FILE_TYPE_WBMP,
    IMG_ID_FMGR_FILE_TYPE_M3D,
    IMG_ID_FMGR_FILE_TYPE_MAV,

    /* message */
    IMG_ID_FMGR_FILE_TYPE_EMS,
    IMG_ID_FMGR_FILE_TYPE_ANM,

    /* audio */
    IMG_ID_FMGR_FILE_TYPE_IMY,
    IMG_ID_FMGR_FILE_TYPE_MID,
    IMG_ID_FMGR_FILE_TYPE_WAV,
    IMG_ID_FMGR_FILE_TYPE_AMR,
    IMG_ID_FMGR_FILE_TYPE_AAC,
    IMG_ID_FMGR_FILE_TYPE_DAF,
    IMG_ID_FMGR_FILE_TYPE_WMA,
    IMG_ID_FMGR_FILE_TYPE_VM,
    IMG_ID_FMGR_FILE_TYPE_AWB,
    IMG_ID_FMGR_FILE_TYPE_AIF,
    IMG_ID_FMGR_FILE_TYPE_AU,
    IMG_ID_FMGR_FILE_TYPE_M4A,
    IMG_ID_FMGR_FILE_TYPE_SND,
    IMG_ID_FMGR_FILE_TYPE_BSAC,
    IMG_ID_FMGR_FILE_TYPE_KUR,
    IMG_ID_FMGR_FILE_TYPE_RA,
    IMG_ID_FMGR_FILE_TYPE_APE,
    IMG_ID_FMGR_FILE_TYPE_OGG,
    IMG_ID_FMGR_FILE_TYPE_FLAC,

    /* video */
    IMG_ID_FMGR_FILE_TYPE_3GP,
    IMG_ID_FMGR_FILE_TYPE_MP4,
    IMG_ID_FMGR_FILE_TYPE_AVI,
    IMG_ID_FMGR_FILE_TYPE_SDP,
    IMG_ID_FMGR_FILE_TYPE_RAM,    
    IMG_ID_FMGR_FILE_TYPE_3GQ,
    IMG_ID_FMGR_FILE_TYPE_RM,
    
    /* others */
    IMG_ID_FMGR_FILE_TYPE_JAD,
    IMG_ID_FMGR_FILE_TYPE_JAR,
    IMG_ID_FMGR_FILE_TYPE_JAVA,
    IMG_ID_FMGR_FILE_TYPE_VCF,
    IMG_ID_FMGR_FILE_TYPE_VCS,
    IMG_ID_FMGR_FILE_TYPE_SVG,
    IMG_ID_FMGR_FILE_TYPE_THEME,
    IMG_ID_FMGR_FILE_TYPE_MBC,    
    IMG_ID_FMGR_FILE_TYPE_UDX,

    /* Ebook */
    IMG_EBOOK_FMGR_NFO_LARGE_TYPE,
    IMG_EBOOK_FMGR_PDB_LARGE_TYPE,
    IMG_EBOOK_FMGR_TXT_LARGE_TYPE,
    
    /* SW Flash */
    IMG_ID_FMGR_FILE_TYPE_CMP,
    IMG_ID_FMGR_FILE_TYPE_VIS,
    IMG_ID_FMGR_FILE_TYPE_IVIS,
    IMG_ID_FMGR_FILE_TYPE_ZDD,
    IMG_ID_FMGR_FILE_TYPE_KVIS,
    IMG_ID_FMGR_FILE_TYPE_MVIS,    

    /* HTM, HTML, WML, XHTML */
    IMG_ID_FMGR_FILE_TYPE_HTM,
    IMG_ID_FMGR_BRW_HTM_LARGE_TYPE,
    IMG_ID_FMGR_BRW_HTML_LARGE_TYPE,
    IMG_ID_FMGR_BRW_WML_LARGE_TYPE,
    IMG_ID_FMGR_BRW_XHTML_LARGE_TYPE,    

    /* V-BookMark */
    IMG_ID_FMGR_ICON_FILE_TYPE_VBOOKMARK,
    IMG_ID_FMGR_FILE_TYPE_URL,
    IMG_ID_FMGR_FILE_TYPE_VBM,

    IMG_ID_FMGR_FILE_TYPE_CER,
    IMG_ID_FMGR_CER_CER_LARGE_TYPE,
    IMG_ID_FMGR_CER_PFX_LARGE_TYPE,
    IMG_ID_FMGR_CER_DER_LARGE_TYPE,
    IMG_ID_FMGR_CER_PEM_LARGE_TYPE,
    IMG_ID_FMGR_CER_P7B_LARGE_TYPE,
    IMG_ID_FMGR_CER_CRT_LARGE_TYPE,
    IMG_ID_FMGR_CER_SPC_LARGE_TYPE,
    IMG_ID_FMGR_CER_P12_LARGE_TYPE,
    
    /* IMPS */
    IMG_IMPS_FMGR_IM_LARGE_TYPE,
	IMG_IMPS_FMGR_IM_SMALL_TYPE,
	
	/* RAM and SDP */
    IMG_ID_FMGR_ICON_FILE_TYPE_RAM,
    IMG_ID_FMGR_ICON_FILE_TYPE_SDP,
    
    NO_OF_FMGR_SERV_IMG
} FMGR_SERV_IMG_IDS;

#endif
