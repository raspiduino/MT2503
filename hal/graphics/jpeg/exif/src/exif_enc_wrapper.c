/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   exif_enc_wrapper.c
 *
 * Project:
 * --------
 *   Maui
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(EXIF_SUPPORT)

#include "exif_enc_enum.h"
#include "exif_enc_tag.h"
#include "exif_enc_utility.h"
#include "exif_enc_api.h"
#include "exif_enc_wrapper.h"
#include "exif.h"

#include "kal_general_types.h"


extern exif_entry_struct IFD0[IFD0_Number_of_Entry];
extern exif_entry_struct IFD1[IFD1_Number_of_Entry];
extern exif_entry_struct ExifIFD[ExifIFD_Number_of_Entry];
extern exif_entry_struct InteroperabilityIFD[InteroperabilityIFD_Number_of_Entry];



////#define ExifUTOnPC

#ifdef ExifUTOnPC
extern exif_ASCII exif_sys_time[20];
extern exif_cam_para_struct exif_cam_para;;
extern exif_interoperability_para_struct exif_interoperability_para;

unsigned char* release_verno(void) 
{ 
   static unsigned char verno_str[] = "MAUI.09B.W10.15"; 
   return verno_str; 
}
#endif  // End of #ifdef ExifUTOnPC



unsigned int _exif_wrapper_get_string_length(unsigned char *string)
{
    unsigned int cnt = 0;

    while (*string++)
    {
        cnt++;
    }

    return cnt + 1;
}



EXIF_RETURN_STATUS_ENUM exifWrapperConvertAllLegacyIFD(EXIF_DATA *data_ptr)
{
    EXIF_RETURN_STATUS_ENUM ret_status;
    exif_extend_entry_struct *extend_entry_ptr;
    unsigned char custom_entry_num;


#ifdef ExifUTOnPC
    exif_cam_para.Software = release_verno();
    exif_cam_para.DateTimeOriginal = "....:..:.. ..:..:..";
    exif_cam_para.DateTimeDigitized = "....:..:.. ..:..:..";
    exif_cam_para.DateTime = exif_sys_time;
    exif_cam_para.ImageDescription = NULL;
    exif_interoperability_para.InteroperabilityIndex = "R98";
    ////
#endif  // End of #ifdef ExifUTOnPC


    ret_status = _exif_wrapper_add_legacy_IFD_entry(data_ptr, EXIF_IFD_0, IFD0, IFD0_Number_of_Entry);

    ret_status = _exif_wrapper_add_legacy_IFD_entry(data_ptr, EXIF_IFD_EXIF, ExifIFD, ExifIFD_Number_of_Entry);

    ret_status = _exif_wrapper_add_legacy_IFD_entry(data_ptr, EXIF_IFD_1, IFD1, IFD1_Number_of_Entry);

    ret_status = _exif_wrapper_add_legacy_IFD_entry(data_ptr, EXIF_IFD_INTEROPERABILITY, InteroperabilityIFD, InteroperabilityIFD_Number_of_Entry);

    extend_entry_ptr = exif_get_custom_specific_IFD(&custom_entry_num);
    ret_status = _exif_wrapper_add_legacy_custom_entry(data_ptr, extend_entry_ptr, custom_entry_num);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM _exif_wrapper_add_legacy_entry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, exif_entry_struct *entry_ptr)
{
    EXIF_RETURN_STATUS_ENUM ret_status;
    EXIF_ENTRY temp_entry;

    if (EXIF_FORMAT_ASCII == entry_ptr->type)
    {
        if (NULL == (*((unsigned char **)entry_ptr->value)))
        {
            return EXIF_RETURN_INVALID_POINTER;
        }

        entry_ptr->count = _exif_wrapper_get_string_length(*((unsigned char **)entry_ptr->value));

        if ((EXIF_TAG_DATE_TIME == entry_ptr->tag) || (EXIF_TAG_DATE_TIME_ORIGINAL == entry_ptr->tag) || (EXIF_TAG_DATE_TIME_DIGITIZED == entry_ptr->tag))
        {
            entry_ptr->count = 20;
        }
    }

    ret_status = exifSetEntryInfo(&temp_entry, entry_ptr->tag, (EXIF_TAG_FORMAT_ENUM)(entry_ptr->type), entry_ptr->count, exif_format_get_size((EXIF_TAG_FORMAT_ENUM)(entry_ptr->type)) * entry_ptr->count);

    if (EXIF_FORMAT_ASCII == entry_ptr->type)
    {
        temp_entry.entry_data_addr = *((unsigned char **)entry_ptr->value);
    }
    else
    {
        temp_entry.entry_data_addr = entry_ptr->value;
    }

    ret_status = exifAddEntry(data_ptr, ifd, &temp_entry);

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM _exif_wrapper_add_legacy_IFD_entry(EXIF_DATA *data_ptr, EXIF_IFD_ENUM ifd, exif_entry_struct *ifd_ptr, unsigned int ifd_entry_num)
{
    EXIF_RETURN_STATUS_ENUM ret_status = EXIF_RETURN_OK;
    unsigned int cnt;

    for (cnt = 0; cnt < ifd_entry_num; cnt++)
    {
        ret_status = _exif_wrapper_add_legacy_entry(data_ptr, ifd, ifd_ptr);

        if (EXIF_RETURN_OK != ret_status)
        {
            /// We do nothing here because we want to transfer the rest tags.
        }

#ifdef ExifUTOnPC
        ret_status = exifWrapperSetDefault((data_ptr->ifd[ifd].entry_array + cnt), ifd_ptr->tag);
#endif // End of #ifdef ExifUTOnPC

        ifd_ptr++;
    }

    return ret_status;
}



EXIF_RETURN_STATUS_ENUM _exif_wrapper_add_legacy_custom_entry(EXIF_DATA *data_ptr, exif_extend_entry_struct *ifd_ptr, unsigned int ifd_entry_num)
{
    EXIF_RETURN_STATUS_ENUM ret_status = EXIF_RETURN_OK;
    EXIF_IFD_ENUM ifd = EXIF_IFD_COUNT;
    unsigned int cnt;

    for (cnt = 0; cnt < ifd_entry_num; cnt++)
    {
        if (EXIF_IFD0 == ifd_ptr->exif_IFD_type)
        {
            ifd = EXIF_IFD_0;
        }
        else if (EXIF_EXIFIFD == ifd_ptr->exif_IFD_type)
        {
            ifd = EXIF_IFD_EXIF;
        }

        ret_status = _exif_wrapper_add_legacy_entry(data_ptr, ifd, &ifd_ptr->entry);

        if (EXIF_RETURN_OK != ret_status)
        {
            /// We do nothing here because we want to transfer the rest tags.
        }

        ifd_ptr++;
    }

    return ret_status;
}



#ifdef ExifUTOnPC

EXIF_RETURN_STATUS_ENUM exifWrapperSetDefault(EXIF_ENTRY *entry, unsigned short tag)
{
    EXIF_RETURN_STATUS_ENUM ret_status = EXIF_RETURN_OK;
    EXIF_BYTE_ORDER_ENUM option;
    EXIF_RATIONAL_T rational;

    /// Force to little endian.
    option = EXIF_BYTE_ORDER_LITTLE_ENDIAN;

    switch (tag)
    {
        /// LONG
        case EXIF_TAG_PIXEL_X_DIMENSION:
	    case EXIF_TAG_PIXEL_Y_DIMENSION:
	    case EXIF_TAG_JPEG_INTERCHANGE_FORMAT_LENGTH:
	    case EXIF_TAG_JPEG_INTERCHANGE_FORMAT:
            exif_set_long(entry->entry_data_addr, option, 0);
            break;

        /// SHORT
        case EXIF_TAG_EXPOSURE_MODE:
        case EXIF_TAG_EXPOSURE_PROGRAM:
        case EXIF_TAG_ISO_SPEED_RATINGS:
        case EXIF_TAG_METERING_MODE:
        case EXIF_TAG_LIGHT_SOURCE:
        case EXIF_TAG_FLASH:
        case EXIF_TAG_SCENE_CAPTURE_TYPE:
            exif_set_short(entry->entry_data_addr, option, 0);
            break;

        /// SHORT, default 6 for compress thumbnail.
        case EXIF_TAG_COMPRESSION:
            exif_set_short(entry->entry_data_addr, option, 6);
            break;

        case EXIF_TAG_ORIENTATION:
        case EXIF_TAG_COLOR_SPACE:
            exif_set_short(entry->entry_data_addr, option, 1);
            break;

        case EXIF_TAG_RESOLUTION_UNIT:
        case EXIF_TAG_YCBCR_POSITIONING:
            exif_set_short(entry->entry_data_addr, option, 2);
            break;
            
        case EXIF_TAG_X_RESOLUTION:
        case EXIF_TAG_Y_RESOLUTION:
            rational.numerator = 72;
            rational.denominator = 1;
            exif_set_rational(entry->entry_data_addr, option, rational);
            break;

        /// SRATIONAL
        case EXIF_TAG_EXPOSURE_BIAS_VALUE:
            rational.numerator = 0;
            rational.denominator = 1;
            exif_set_rational(entry->entry_data_addr, option, rational);
            break;

        /// ASCII
        case EXIF_TAG_SOFTWARE:
            break;

        /// ASCII 20
        case EXIF_TAG_DATE_TIME:
            //entry->entry_data_addr = exif_sys_time;
            ////memcpy(entry->entry_data_addr, "....:..:.. ..:..:..", 20);
            break;

        /// ASCII 20
        case EXIF_TAG_DATE_TIME_ORIGINAL:
        case EXIF_TAG_DATE_TIME_DIGITIZED:
            //memcpy(entry->entry_data_addr, "....:..:.. ..:..:..", 20);
            break;

        case EXIF_TAG_EXPOSURE_TIME:
        case EXIF_TAG_FNUMBER:
            rational.numerator = 0;
            rational.denominator = 0;
            exif_set_rational(entry->entry_data_addr, option, rational);
		    break;

        case EXIF_TAG_DIGITAL_ZOOM_RATIO:
            rational.numerator = 1;
            rational.denominator = 1;
            exif_set_rational(entry->entry_data_addr, option, rational);
		    break;

        case EXIF_TAG_EXIF_VERSION:
            memcpy(entry->entry_data_addr, "0220", 4);
            break;

        case EXIF_TAG_FLASH_PIX_VERSION:
            memcpy(entry->entry_data_addr, "0100", 4);
            break;

        case EXIF_TAG_COMPONENTS_CONFIGURATION:
            entry->entry_data_addr[0] = 1;
            entry->entry_data_addr[1] = 2;
            entry->entry_data_addr[2] = 3;
            entry->entry_data_addr[3] = 0;
            break;

        /// UNDEFINED
        case EXIF_TAG_MAKER_NOTE:
            break;

        /// ASCII
        case EXIF_TAG_INTEROPERABILITY_INDEX:
            break;

        default:
            break;

    }

    return ret_status;
}

#endif  // End of #ifdef ExifUTOnPC
#endif  /// End of #if defined(EXIF_SUPPORT)
