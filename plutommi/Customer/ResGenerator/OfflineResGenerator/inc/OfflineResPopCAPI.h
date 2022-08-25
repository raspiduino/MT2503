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
 *   OfflineResPopCAPI.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Define C API broker layer of offline resgen system
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *                 HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/


#ifndef _OFFLINERESADAPTOR_
#define _OFFLINERESADAPTOR_

// This header are external interface for c
// Don't put any C++ only content here, it will break the layered 
// architecture of Offline Resgen Framework

#if defined __cplusplus
extern "C" {
#endif


    //////////////////////////////////////////////////////
    // Helpers
    //////////////////////////////////////////////////////
    void ConvertToResFileName(char * resFileName, char * path, char * immediateFileName, int sizeLimit);


#define OFFLINE_RESGEN_NO_FORCE_TYPE 0xFF

////////////////////////////////////////////////////
// ID object Models
////////////////////////////////////////////////////
void OfflineIdModelInit(char * fileName);
void OfflineIdModelDeinit();


#ifndef __POPULATE_NO_STRING_DATA__
    ///////////////////////////////////////////////////////
    // String APIs for Legacy Resgenerator and XML Parser
    //////////////////////////////////////////////////////
#define DEFAULT_OFFLINE_XML_STRING_DB "offline_xml_string_repo.txt"
#define DEFAULT_OFFLINE_PRE_XML_LEGACY_STRING_DB "offline_pre_xml_legacy_string_repo.txt"
#define DEFAULT_OFFLINE_POST_XML_LEGACY_STRING_DB  "offline_post_xml_legacy_string_repo.txt"

#define ADD_APPLICATION_STRING(stringId, stringContent)    StringAdaptorSetString( (stringId), (stringContent), "APP name unknown", "NA", (#stringId), (__FILE__), 0);
#define ADD_APPLICATION_STRING2(stringId, stringContent, display)    StringAdaptorSetString(stringId, stringContent, "APP name unknown", display, #stringId,__FILE__, 0);
#define ADD_APPLICATION_STRING3(stringId, enumVaule, stringContent, display)    StringAdaptorSetString(stringId, stringContent, "APP name unknown", display,enumVaule,__FILE__, 0);

    // Create and open string population repository
    void StringAdaptorStartOfflinePopulation(char* fileName);
    // Flush out the entire param list
    void StringAdaptorStopOfflinePopulation();
    void StringAdaptorSetString(int stringId, char* stringContent,char * appId, char* desc, char * stringEnumName, char* fileName, int noCompiling);
#else //__POPULATE_NO_STRING_DATA__
#define ADD_APPLICATION_STRING(stringId, stringContent)                         NULL
#define ADD_APPLICATION_STRING2(stringId, stringContent, display)               NULL
#define ADD_APPLICATION_STRING3(stringId, enumVaule, stringContent, display)    NULL  
#endif //__POPULATE_NO_STRING_DATA__

#ifndef __POPULATE_NO_IMAGE_DATA__
    ///////////////////////////////////////////////////////
    // Image/ Media APIs for Legacy Resgenerator and XML Parser
    //////////////////////////////////////////////////////
#define DEFAULT_OFFLINE_XML_IMAGE_DB "offline_xml_image_repo.txt"
#define DEFAULT_OFFLINE_PRE_XML_LEGACY_IMAGE_DB "offline_pre_xml_legacy_image_repo.txt"
#define DEFAULT_OFFLINE_POST_XML_LEGACY_IMAGE_DB "offline_post_xml_legacy_image_repo.txt"

#define OFFLINE_IMAGE_PARAM_QUALITY_LOW  0
#define OFFLINE_IMAGE_PARAM_QUALITY_MEDIUM 1
#define OFFLINE_IMAGE_PARAM_QUALITY_HIGH 2

    // Create and open image population repository
    void ImageAdaptorStartOfflinePopulation(char* fileName);
    // Flush out the entire param list to image population repository
    void ImageAdaptorStopOfflinePopulation();
    void ImageAdaptorSetImage(int imageId, char* imageFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin, int isENFB);
    void ImageAdaptorSetImageWithQuality(int imageId, char* imageFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin, int isENFB, int quality, int compression);
    void ImageAdaptorSetImageAutoId(char* imageFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin, int isENFB);
    void ImageAdaptorSetImageAutoIdWithQuality(char* imageFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin, int isENFB, int quality, int compression);


    // Original conversion: SetImage(ImageId, ImgFileName, #ImageId);
#define ADD_APPLICATION_IMAGE(ImageId, ImgFileName)                         \
    ImageAdaptorSetImage(ImageId, ImgFileName, "APP name unknown", "Added by ADD_APPLICATION_IMAGE", #ImageId, __FILE__, 0, 0, 0, 0);

    // Original conversion: SetImageWithBuffer(ImageId, filename, #ImageId, FALSE);
#define ADD_APPLICATION_IMAGE2(ImageId, ImgFileName, display)                                  \
    ImageAdaptorSetImage(ImageId, ImgFileName,"APP name unknown", display, #ImageId, __FILE__, 0, 0, 0, 0);

    // Original conversion: SetImageWithBuffer(ImageId, filename, #ImageId, TRUE);
#define ADD_APPLICATION_IMAGE3(ImageId, ImgFileName, display)                                  \
    ImageAdaptorSetImage(ImageId, ImgFileName,"APP name unknown", display, #ImageId, __FILE__, 0, 0, 1, 0);

    // Original conversion: SetImageWithBuffer(ImageId, fullpath, tmp, isMB);
#define ADD_APPLICATION_IMAGE4(ImageId, tmp, path, filename, display, isMB)                 \
    {   char fullpath[150]; sprintf(fullpath, "%s%s", path, filename);                         \
    ImageAdaptorSetImage(ImageId, fullpath,"APP name unknown", "Added by ADD_APPLICATION_IMAGE4", tmp, __FILE__, 0, 0, isMB, 0); \
    }
    // Original conversion: SetImageWithBufferForceType(ImageId, filename, #ImageId, isMB, type)
#define ADD_APPLICATION_IMAGE_TYPE(ImageId, filename, display, isMB, type)                                \
    ImageAdaptorSetImage(ImageId, filename,"APP name unknown", display,  #ImageId, __FILE__, 0, type, isMB, 0);

    // Old style API: Add image with quality setting
#define ADD_APPLICATION_IMAGE_QUALITY(ImageId, ImgFileName, display, quality, compression)                                  \
    ImageAdaptorSetImageWithQuality(ImageId, ImgFileName, "APP name unknown", "Added by ADD_APPLICATION_IMAGE", #ImageId, __FILE__, 0, 0, 0, 0, quality, compression);

    // Old style API: Add image with quality setting
#define ADD_APPLICATION_IMAGE2_QUALITY(ImageId, ImgFileName, display, quality, compression)                                  \
    ImageAdaptorSetImageWithQuality(ImageId, ImgFileName,"APP name unknown", display, #ImageId, __FILE__, 0, 0, 0, 0, quality, compression);

    // Old style API: Add image with quality setting
#define ADD_APPLICATION_IMAGE3_QUALITY(ImageId, ImgFileName, display, quality, compression)                                  \
    ImageAdaptorSetImageWithQuality(ImageId, ImgFileName,"APP name unknown", display, #ImageId, __FILE__, 0, 0, 1, 0, quality, compression);

    // Original conversion: SetImageWithBuffer(ImageId, fullpath, tmp, isMB);
#define ADD_APPLICATION_IMAGE4_QUALITY(ImageId, tmp, path, filename, display, isMB, quality, compression)                 \
    {   char fullpath[150]; sprintf(fullpath, "%s%s", path, filename);                         \
    ImageAdaptorSetImageWithQuality(ImageId, fullpath,"APP name unknown", "Added by ADD_APPLICATION_IMAGE4", tmp, __FILE__, 0, 0, isMB, 0, quality, compression); \
    }
    // Original conversion: SetImageWithBufferForceType(ImageId, filename, #ImageId, isMB, type)
#define ADD_APPLICATION_IMAGE_TYPE_QUALITY(ImageId, filename, display, isMB, type, quality, compression)                                \
    ImageAdaptorSetImageWithQuality(ImageId, filename,"APP name unknown", display,  #ImageId, __FILE__, 0, type, isMB, 0, quality, compression);


    // Original conversion:   SetImage(ImageId,ImgFileName,#ImageId);
#define ADD_APPLICATION_MEDIA(ImageId, ImgFileName)                         \
    ImageAdaptorSetImage(ImageId, ImgFileName,"APP name unknown", "Added by ADD_APPLICATION_IMAGE", #ImageId, __FILE__, 0, 0, 0, 0);

    // Original conversion: SetImageWithBuffer(ImageId, filename, #ImageId, FALSE);
#define ADD_APPLICATION_MEDIA2(ImageId, ImgFileName, display)                                  \
    ImageAdaptorSetImage(ImageId, ImgFileName,"APP name unknown", display, #ImageId, __FILE__, 0, 0, 0, 0);

    // Original conversion: SetImageWithBuffer(ImageId, filename, #ImageId, TRUE);
#define ADD_APPLICATION_MEDIA3(ImageId, ImgFileName, display)                                  \
    ImageAdaptorSetImage(ImageId, ImgFileName,"APP name unknown", display, #ImageId, __FILE__, 0, 0, 1, 0);

    // Original conversion: SetImageWithBuffer(ImageId, fullpath, tmp, isMB);
#define ADD_APPLICATION_MEDIA4(ImageId, tmp, path, filename, display, isMB)                 \
    {   char fullpath[150]; sprintf(fullpath, "%s%s", path, filename);                         \
    ImageAdaptorSetImage(ImageId, fullpath,"APP name unknown", "Added by ADD_APPLICATION_IMAGE4", tmp, __FILE__, 0, 0, isMB, 0); \
    }
#else //__POPULATE_NO_IMAGE_DATA__
#define OFFLINE_IMAGE_PARAM_QUALITY_LOW  0
#define OFFLINE_IMAGE_PARAM_QUALITY_MEDIUM 1
#define OFFLINE_IMAGE_PARAM_QUALITY_HIGH 2

#define ADD_APPLICATION_IMAGE(ImageId, ImgFileName)                                                         NULL
#define ADD_APPLICATION_IMAGE2(ImageId, ImgFileName, display)                                               NULL
#define ADD_APPLICATION_IMAGE3(ImageId, ImgFileName, display)                                               NULL
#define ADD_APPLICATION_IMAGE4(ImageId, tmp, path, filename, display, isMB)                                 NULL
#define ADD_APPLICATION_IMAGE_TYPE(ImageId, filename, display, isMB, type)                                  NULL
#define ADD_APPLICATION_IMAGE_QUALITY(ImageId, ImgFileName, display, quality, compression)                  NULL
#define ADD_APPLICATION_IMAGE2_QUALITY(ImageId, ImgFileName, display, quality, compression)                 NULL
#define ADD_APPLICATION_IMAGE3_QUALITY(ImageId, ImgFileName, display, quality, compression)                 NULL
#define ADD_APPLICATION_IMAGE4_QUALITY(ImageId, tmp, path, filename, display, isMB, quality, compression)   NULL
#define ADD_APPLICATION_IMAGE_TYPE_QUALITY(ImageId, filename, display, isMB, type, quality, compression)    NULL
#define ADD_APPLICATION_MEDIA(ImageId, ImgFileName)                                                         NULL
#define ADD_APPLICATION_MEDIA2(ImageId, ImgFileName, display)                                               NULL
#define ADD_APPLICATION_MEDIA3(ImageId, ImgFileName, display)                                               NULL
#define ADD_APPLICATION_MEDIA4(ImageId, tmp, path, filename, display, isMB)                                 NULL
#endif //__POPULATE_NO_IMAGE_DATA__
    ///////////////////////////////////////////////////////
    // Audio APIs for Legacy Resgenerator and XML Parser
    //////////////////////////////////////////////////////
#define DEFAULT_OFFLINE_XML_AUDIO_DB "offline_xml_audio_repo.txt"
#define DEFAULT_OFFLINE_PRE_XML_LEGACY_AUDIO_DB "offline_pre_xml_legacy_audio_repo.txt"
#define DEFAULT_OFFLINE_POST_XML_LEGACY_AUDIO_DB "offline_post_xml_legacy_audio_repo.txt"

    void AudioAdaptorStartOfflinePopulation(char* fileName);

    // Flush out the entire param list
    void AudioAdaptorStopOfflinePopulation();

    void AudioAdaptorSetAudio(int imageId, char* audioFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin);

    // Original conversion:  SetAudioWithBuffer(AudioId, filename, display, #AudioId, RES_AUDIO, FALSE, __FILE__); 
#define ADD_APPLICATION_AUDIO2(AudioId, filename, display)                                  \
    AudioAdaptorSetAudio(AudioId, filename,"APP name unknown", display, #AudioId, __FILE__, 0, OFFLINE_RESGEN_NO_FORCE_TYPE, 0);

    // Original conversion:  SetAudioWithBuffer(AudioId, filename, display, #AudioId, RES_AUDIO, TRUE, __FILE__);    
#define ADD_APPLICATION_AUDIO3(AudioId, filename, display)                                  \
    AudioAdaptorSetAudio(AudioId, filename,"APP name unknown", display, #AudioId, __FILE__, 0, OFFLINE_RESGEN_NO_FORCE_TYPE, 1);

    // Original conversion:  SetAudioWithBufferForceType(AudioId, filename, display, #AudioId, RES_AUDIO, isMB, __FILE__, type);    
#define ADD_APPLICATION_AUDIO_TYPE(AudioId, filename, display, isMB, type)                                \
    AudioAdaptorSetAudio(AudioId, filename,"APP name unknown", display,  #AudioId, __FILE__, 0, type, isMB);


    ///////////////////////////////////////////////////////
    // Binary APIs for Legacy Resgenerator and XML Parser
    //////////////////////////////////////////////////////
#define DEFAULT_OFFLINE_XML_BINARY_DB "offline_xml_binary_repo.txt"
#define DEFAULT_OFFLINE_PRE_XML_LEGACY_BINARY_DB "offline_pre_xml_legacy_binary_repo.txt"
#define DEFAULT_OFFLINE_POST_XML_LEGACY_BINARY_DB "offline_post_xml_legacy_binary_repo.txt"

    void BinaryAdaptorStartOfflinePopulation(char* fileName);

    // Flush out the entire param list
    void BinaryAdaptorStopOfflinePopulation();

    void BinaryAdaptorSetBinary(int binaryId, char* binaryFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int binaryType);


    // To offline save the binary population resource
    // Original conversion:  SetBinaryWithBuffer(res_id, filename, #res_id, type);

#define ADD_APPLICATION_BINARY(binaryId, filename, type, display)                                  \
    BinaryAdaptorSetBinary(binaryId, filename, "APP name unknown", display,  #binaryId, __FILE__, 0, type);


#if defined __cplusplus
}
#endif //__cplusplus

#endif //_OFFLINERESADAPTOR_
