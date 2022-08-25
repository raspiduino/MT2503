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
 *   app_mine.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implements common interfaces for mine type.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "fat_fs.h"
#include "app_mine.h"
#include "app_str.h"
#include "MMI_features.h"
//#include "app_buff_alloc.h"

    #include "kal_general_types.h"
    #include "kal_public_defs.h"
    #include "kal_public_api.h"
    #include "string.h"

#if defined (PLUTO_MMI)
/* only on Plutommi */
#include "GDI_features.h"

#else
    #if defined(USE_HW_PNG_DECODER_V1) || defined(USE_SW_PNG_DECODER)
        #ifndef GDI_USING_PNG
        #define GDI_USING_PNG
        #endif
    #endif
#endif


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

typedef struct applib_mime_type_dynamic_entry_element_struct_s
{
    applib_mime_type_struct mime_type;
    struct applib_mime_type_dynamic_entry_element_struct_s* next;
} applib_mime_type_dynamic_entry_element_struct;


typedef struct
{
    kal_char *mime_string;
    kal_char *mime_type_string;
    kal_char *mime_subtype_string;
    kal_char *file_ext;
    applib_mime_type_enum mime_type;
    applib_mime_subtype_enum mime_subtype;
} applib_mime_type_look_up_ext_param_struct;


/***************************************************************************** 
* Local Variable
*****************************************************************************/
static const kal_char * const g_applib_mime_string[MIME_TYPE_MAX_NUM] = 
{
  "", "text", "image", "audio", "video", "application", "message", "multipart", ""
};

static const applib_mime_type_struct g_applib_mime_tbl[] = 
{
    {"application/octet-stream"		       ,"bin"      ,MIME_TYPE_NONE       ,MIME_SUBTYPE_NONE                , MIME_MMI_TYPE},
    {"audio/amr"                               ,"amr"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AMR                  , MIME_MMI_TYPE},
    {"audio/x-amr"                             ,"amr"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AMR                  , MIME_MMI_TYPE},
    {"audio/imelody"                           ,"imy"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_IMELODY              , MIME_MMI_TYPE},
    {"audio/imy"                               ,"imy"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_IMELODY              , MIME_MMI_TYPE},
    {"audio/mid"                               ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                  , MIME_MMI_TYPE},
    {"audio/midi"                              ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                 , MIME_MMI_TYPE},
    {"audio/sp-midi"                           ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_SPMIDI               , MIME_MMI_TYPE},
    {"audio/spmidi"                            ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_SPMIDI             , MIME_MMI_TYPE},
    {"audio/x-midi"                            ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                , MIME_MMI_TYPE},
    {"audio/x-mid"                             ,"mid"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                  , MIME_MMI_TYPE},
    {"audio/mid"                               ,"midi"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                  , MIME_MMI_TYPE},
    {"audio/x-midi"                            ,"midi"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MID                  , MIME_MMI_TYPE},
    {"audio/wav"                               ,"wav"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_WAV                  , MIME_MMI_TYPE},
    {"audio/x-wav"                             ,"wav"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_WAV                 , MIME_MMI_TYPE},
#ifdef __VM_CODEC_SUPPORT__
    {"audio/vm"                                ,"vm"       ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_VM                   , MIME_MMI_TYPE},
#endif
    {"image/bmp"                               ,"bmp"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_BMP                  , MIME_MMI_TYPE},
    {"image/x-MS-bmp"                          ,"bmp"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_BMP                  , MIME_MMI_TYPE},
    {"image/gif"                               ,"gif"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_GIF                  , MIME_MMI_TYPE},
    {"image/vnd.wap.wbmp"                      ,"wbmp"     ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_WBMP                 , MIME_MMI_TYPE},
    {"image/vnd.wap.wbmp"                      ,"wbm"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_WBMP                 , MIME_MMI_TYPE},
    {"text/x-imelody"                          ,"imy"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_IMELODY             , MIME_MMI_TYPE},
#if defined(AU_DECODE)
    {"audio/basic"                             ,"au"       ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AU                   , MIME_MMI_TYPE},
    {"audio/basic"                             ,"snd"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_SND                  , MIME_MMI_TYPE},
    {"audio/x-ulaw"                            ,"au"       ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AU_XULAW             , MIME_MMI_TYPE},
#endif
#if defined(AIFF_DECODE)
    {"audio/x-aiff"                            ,"aiff"      ,MIME_TYPE_AUDIO     , MIME_SUBTYPE_AIFF                 , MIME_MMI_TYPE},
    {"audio/x-aiff"                            ,"aif"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIF                  , MIME_MMI_TYPE},
    {"audio/x-aiff"                            ,"aifc"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIFC                 , MIME_MMI_TYPE},
    {"audio/aiff"                              ,"aiff"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIFF                 , MIME_MMI_TYPE},
    {"audio/aiff"                              ,"aif"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIF                  , MIME_MMI_TYPE},
    {"audio/aiff"                              ,"aifc"     ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AIFC                 , MIME_MMI_TYPE},
#endif
#if defined(__DRM_SUPPORT__)
    {"application/vnd.oma.drm.content"         ,"dcf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_CONTENT          , MIME_MMI_TYPE},
    {"application/vnd.oma.drm.message"         ,"dm"       ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_MESSAGE          , MIME_MMI_TYPE},
    {"application/vnd.oma.drm.rights+wbxml"    ,"drc"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_RIGHTS_WBXML     , MIME_MMI_TYPE},
    {"application/vnd.oma.drm.rights+xml"      ,"dr"       ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_RIGHTS_XML       , MIME_MMI_TYPE},
#ifdef __DRM_V02__    
    {"application/vnd.oma.drm.dcf"             ,"odf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_DRM_CONTENT_V2       , MIME_MMI_TYPE},
    {"application/vnd.oma.drm.roap-pdu+xml"    ,"ort"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_ROAP_PDU             , MIME_MMI_TYPE},
    {"application/vnd.oma.drm.roap-trigger+xml","ort"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_ROAP_TRIGGER         , MIME_MMI_TYPE},
    {"application/vnd.oma.drm.ro+xml"          ,"oro"      ,MIME_TYPE_APPLICATION, MIMI_SUBTYPE_PROTECTED_RO         , MIME_MMI_TYPE},
#endif
#endif
#if defined(__J2ME__)
    {"application/java-archive"                ,"jar"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_JAR                  , MIME_MMI_TYPE},
    {"application/java-vm"                     ,"class"    ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_JVM                  , MIME_MMI_TYPE},
    {"text/vnd.sun.j2me.app-descriptor"        ,"jad"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_JAD                  , MIME_MMI_TYPE},
    {"application/octet-stream"		       ,"jad"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_JAD                  , MIME_MMI_TYPE},
    {"application/octet-stream"		       ,"jar"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_JAR                  , MIME_MMI_TYPE},
#endif
#if defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__)
    {"mtk/med.thm"                             ,"med"         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_THEME                , MIME_MMI_TYPE},
#endif
    {"text/plain"                              ,"txt"      ,MIME_TYPE_TEXT       , MIME_SUBTYPE_PLAIN                , MIME_MMI_TYPE},
#if defined(__MMI_EBOOK_READER__)
    {"application/x-pilot-pdb"                 ,"pdb"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PDB                  , MIME_MMI_TYPE},
#endif
#if defined(__MMI_OMA_DD_DOWNLOAD__)
    {"application/vnd.oma.dd+xml"              ,"dd"       ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_DD               , MIME_MMI_TYPE},
    {"application/vnd.oma.dd2+xml"             ,"dd2"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_DD2              , MIME_MMI_TYPE},
#endif
#if defined(__MMI_VCALENDAR__)
    {"text/x-vcalendar"                        ,"vcs"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVCALENDAR           , MIME_MMI_TYPE},
    {"application/hbs-vcs"                     ,"vcs"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_HBSVCS               , MIME_MMI_TYPE},
    {"text/calendar"                           ,"vcs"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CALENDAR             , MIME_MMI_TYPE},
#endif
#if defined(__MMI_VCARD__)
    {"text/x-vcard"                            ,"vcf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVCARD               , MIME_MMI_TYPE},
    {"application/vcard"                       ,"vcf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_VCARD                , MIME_MMI_TYPE},
    {"text/vcard"                              ,"vcf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_VCARD                , MIME_MMI_TYPE},
    {"text/directory"                          ,"vcf"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_VCARD                , MIME_MMI_TYPE},    
#endif
#if defined(__MMI_VBOOKMARK__)
    {"text/x-vbookmark"                        ,"vbm"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVBOOKMARK           , MIME_MMI_TYPE},
    {"text/plain"                              ,"vbm"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVBOOKMARK           , MIME_MMI_TYPE},
    {"text/x-vbookmark"                        ,"url"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVBOOKMARK           , MIME_MMI_TYPE},
    {"text/plain"                              ,"url"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_XVBOOKMARK           , MIME_MMI_TYPE},
#endif
#if defined(__POC__)
    {"application/vnd.poc.refer-to"            ,""         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_REFERTO              , MIME_MMI_TYPE},
#endif
#if defined(STREAM_SUPPORT)
    {"application/sdp"                         ,"sdp"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_SDP                  , MIME_MMI_TYPE},
#endif
#if defined(AAC_DECODE)
    {"audio/aac"                               ,"aac"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AAC                 , MIME_MMI_TYPE},
    {"audio/x-aac"                             ,"aac"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AAC                 , MIME_MMI_TYPE},
    {"audio/x-mpeg-aac"                        ,"aac"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AAC                 , MIME_MMI_TYPE},
    {"audio/3ga"                               ,"aac"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AAC                 , MIME_MMI_TYPE},
#endif
#if defined(AMRWB_DECODE)
    {"audio/amr-wb"                            ,"awb"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AWB                  , MIME_MMI_TYPE},
#endif
#if defined(DAF_DECODE)
    {"audio/mp3"                               ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3            , MIME_MMI_TYPE},
    {"audio/mpeg"                              ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3           , MIME_MMI_TYPE},
    {"audio/x-mpeg"                            ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3           , MIME_MMI_TYPE},
    {"audio/mpg"                               ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3            , MIME_MMI_TYPE},
    {"audio/mpg3"                              ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3           , MIME_MMI_TYPE},
    {"audio/x-mp3"                             ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3           , MIME_MMI_TYPE},
    {"audio/mpeg3"                             ,"mp3"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_MP3            , MIME_MMI_TYPE},
#endif

#ifdef __VORBIS_DECODE__
	{"audio/ogg"                               ,"ogg"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_AUDIO_OGG            , MIME_MMI_TYPE},
#endif	/* __VORBIS_DECODE__ */


#if defined(JPG_DECODE)
    {"image/jpeg"                              ,"jpg"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_JPG                 , MIME_MMI_TYPE},
    {"image/jpg"                               ,"jpg"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_JPG                  , MIME_MMI_TYPE},
    {"image/jpeg"                              ,"jpeg"     ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_JPEG                 , MIME_MMI_TYPE},
    {"image/jpeg"                              ,"jpe"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_JPEG                 , MIME_MMI_TYPE},
#endif
#if defined(MJPG_DECODE)
    {"video/x-msvideo"                         ,"avi"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_AVI                  , MIME_MMI_TYPE},
    {"video/avi"                               ,"avi"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_AVI                  , MIME_MMI_TYPE},
#endif
#ifdef __MKV_FILE_FORMAT_SUPPORT__
	{"video/x-matroska"                               ,"mkv"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MKV_VIDEO            , MIME_MMI_TYPE},
	{"video/webm"                               ,"webm"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_WEBM_VIDEO            , MIME_MMI_TYPE},
#endif	/* __MKV_FILE_FORMAT_SUPPORT__ */
#if defined(YAMAHA_MA3)
    {"application/vnd.smaf"                    ,"mmf"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_VSMAF                , MIME_MMI_TYPE},
    {"application/x-smaf"                      ,"mmf"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_XSMAF                , MIME_MMI_TYPE},
#endif
#if defined(MMS_SUPPORT)
    {"application/smil"                        ,"smil"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_SMIL                 , MIME_MMI_TYPE},
    {"multipart/mixed"                         ,""         ,MIME_TYPE_MULTIPART  , MIME_SUBTYPE_MIXED                , MIME_MMI_TYPE},
    {"application/vnd.wap.multipart.mixed"     ,""         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_WAP_MIXED            , MIME_MMI_TYPE},
    {"application/vnd.wap.multipart.related"   ,""         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_WAP_RELATED          , MIME_MMI_TYPE},
#endif
#if (defined(__MMI_MMS_2__) && defined(__MMI_MMS_MMA_MMS_OBJECT_IND__)) || defined(OBIGO_Q03C_MMS_V01)
		{"application/vnd.wap.mms-message"   			 ,"mms"         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_MMS          , MIME_MMI_TYPE},
#endif
//#if (defined(__MMI_MMS_2__) && defined(__MMI_MMS_MMA_MMS_OBJECT_IND__)) || defined(OBIGO_Q03C_MMS_V01)
		{"application/vnd.wap.mms-message"   			 ,"mms"         ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_MMS          , MIME_MMI_TYPE},
//#endif
#if defined(MP4_DECODE)
    {"video/3gpp"                              ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , MIME_MMI_TYPE},
    {"video/3gp"                               ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , MIME_MMI_TYPE},
    {"application/.3gp"                        ,"3gp"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP_VIDEO           , MIME_MMI_TYPE},
    {"video/mp4"                               ,"mp4"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MP4                  , MIME_MMI_TYPE},
    {"video/mpeg4"                             ,"mp4"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MPEG4                , MIME_MMI_TYPE},
    {"video/mp4v-es"                           ,"mp4"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_MP4                  , MIME_MMI_TYPE},
    {"video/3gpp2"                             ,"3g2"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_3GPP2_VIDEO          , MIME_MMI_TYPE},
#elif defined(__MMI_PURE_AUDIO__)
    {"video/3gpp"                              ,"3gp"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_3GPP_AUDIO           , MIME_MMI_TYPE},
    {"video/3gp"                               ,"3gp"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_3GPP_AUDIO           , MIME_MMI_TYPE},
    {"application/.3gp"                        ,"3gp"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_3GPP_AUDIO           , MIME_MMI_TYPE},
    {"video/mp4"                               ,"mp4"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MP4_AUDIO            , MIME_MMI_TYPE},
    {"video/mpeg4"                             ,"mp4"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MPEG4                , MIME_MMI_TYPE},
#endif
#ifdef __FLV_FILE_FORMAT_SUPPORT__
	{"video/x-flv"                             ,"flv"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_FLV_VIDEO            , MIME_MMI_TYPE},
	{"video/mp4"                               ,"f4v"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_F4V_VIDEO            , MIME_MMI_TYPE},
	{"application/octet-stream"                ,"flv"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_FLV_VIDEO            , MIME_MMI_TYPE},
	{"application/octet-stream"                ,"f4v"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_F4V_VIDEO            , MIME_MMI_TYPE},
#endif
#if defined(__RM_DEC_SUPPORT__)
    {"audio/vnd.rn-realaudio"                  ,"ra"        ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_RA           , MIME_MMI_TYPE},
    {"audio/x-realaudio"                       ,"ra"        ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_RA           , MIME_MMI_TYPE},
    {"video/vnd.rn-realvideo"                  ,"rv"        ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_RV           , MIME_MMI_TYPE},
    {"application/vnd.rn-realmedia"            ,"rm"        ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_RM           , MIME_MMI_TYPE},
    {"application/vnd.rn-realmedia-vbr"        ,"rmvb"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_RMVB         , MIME_MMI_TYPE}, 
    {"video/x-pn-realvideo"                    ,"rmvb"      ,MIME_TYPE_VIDEO      , MIME_SUBTYPE_RMVB         , MIME_MMI_TYPE},
#endif
#if defined(M4A_DECODE)
    {"audio/mp4"                               ,"m4a"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_M4A                  , MIME_MMI_TYPE},
    {"audio/m4a"                               ,"m4a"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_M4A                  , MIME_MMI_TYPE},
    {"audio/x-m4a"                             ,"m4a"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_M4A                 , MIME_MMI_TYPE},
#endif
#if defined(PURE_AUDIO_SUPPORT)
    {"audio/3gpp"                              ,"3gp"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_3GPP_AUDIO           , MIME_MMI_TYPE},
    {"audio/3gp"                               ,"3gp"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_3GPP_AUDIO            , MIME_MMI_TYPE},
    {"audio/3g2"                               ,"3g2"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_3GPP_AUDIO            , MIME_MMI_TYPE},
    {"audio/mp4"                               ,"mp4"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_MP4_AUDIO            , MIME_MMI_TYPE},    
#endif

#if defined(GDI_USING_PNG)
    {"image/png"                               ,"png"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_PNG                  , MIME_MMI_TYPE},
#endif
#if defined(SVG_SUPPORT)
    {"image/svg+xml"                           ,"svg"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_SVG                  , MIME_MMI_TYPE},
    {"image/svg-xml"                           ,"svg"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_SVG                  , MIME_MMI_TYPE},
    {"image/svg"                               ,"svg"      ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_SVG                  , MIME_MMI_TYPE},
    {"image/svg+xml"                           ,"svgz"     ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_SVG                  , MIME_MMI_TYPE},
    {"image/svg-xml"                           ,"svgz"     ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_SVG                  , MIME_MMI_TYPE},
    {"image/svg"                               ,"svgz"     ,MIME_TYPE_IMAGE      , MIME_SUBTYPE_SVG                  , MIME_MMI_TYPE},
#endif
#if defined(WAP_SUPPORT)
    {"application/x-x509-ca-cert"              ,"cer"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT              , MIME_MMI_TYPE},
    {"application/x-x509-user-cert"            ,"usr"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , MIME_MMI_TYPE},
#ifdef __CERTMAN_SUPPORT__
    {"application/x-x509-ca-cert"              ,"der"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT              , MIME_MMI_TYPE},
    {"application/x-x509-ca-cert"              ,"crt"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT              , MIME_MMI_TYPE},
    {"application/x-x509-ca-cert"              ,"pem"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_CA_CERT              , MIME_MMI_TYPE},
    {"application/x-x509-user-cert"            ,"cer"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , MIME_MMI_TYPE},
    {"application/x-x509-user-cert"            ,"der"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , MIME_MMI_TYPE},
    {"application/x-x509-user-cert"            ,"crt"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , MIME_MMI_TYPE},
    {"application/x-x509-user-cert"            ,"pem"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_USR_CERT             , MIME_MMI_TYPE},
    {"application/x-pkcs7-certificates"        ,"p7b"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS7_CERT           , MIME_MMI_TYPE},
    {"application/x-pkcs7-certificates"        ,"spc"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS7_CERT           , MIME_MMI_TYPE},
    {"application/x-pkcs7-certificates"        ,"pem"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS7_CERT           , MIME_MMI_TYPE},
    {"application/x-pkcs12"                    ,"p12"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS12_CERT          , MIME_MMI_TYPE},
    {"application/x-pkcs12"                    ,"pfx"      ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_PKCS12_CERT          , MIME_MMI_TYPE},
#endif
    {"application/vnd.wap.connectivity-wbxml"  ,"owbxml"   ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_OMA_PROV_WBXML       , MIME_MMI_TYPE},
    {"application/x-wap-prov.browser-bookmarks","nbmk"     ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_NOKIA_PROV_BOOKMARKS , MIME_MMI_TYPE},
    {"application/x-wap-prov.browser-settings" ,"nbrw"     ,MIME_TYPE_APPLICATION, MIME_SUBTYPE_NOKIA_PROV_BROWSER   , MIME_MMI_TYPE},
    {"text/css"                                ,"css"      ,MIME_TYPE_TEXT       , MIME_SUBTYPE_CSS                  , MIME_MMI_TYPE},
    {"text/html"                               ,"html"     ,MIME_TYPE_TEXT       , MIME_SUBTYPE_HTML                 , MIME_MMI_TYPE},
    {"text/vnd.wap.connectivity-xml"           ,"otext"    ,MIME_TYPE_TEXT       , MIME_SUBTYPE_OMA_PROV_XML         , MIME_MMI_TYPE},
    {"text/vnd.wap.wml"                        ,"wml"      ,MIME_TYPE_TEXT       , MIME_SUBTYPE_WML                  , MIME_MMI_TYPE},
    {"text/vnd.wap.wmlscript"                  ,"wmls"     ,MIME_TYPE_TEXT       , MIME_SUBTYPE_WMLSCRIPT            , MIME_MMI_TYPE},
    {"application/vnd.wap.wmlc"                ,"wmlc"     ,MIME_TYPE_TEXT       , MIME_SUBTYPE_WMLC                 , MIME_MMI_TYPE},
    {"application/vnd.wap.wmlscriptc"          ,"wmlsc"    ,MIME_TYPE_TEXT       , MIME_SUBTYPE_WMLSC                , MIME_MMI_TYPE},
#ifdef __MMI_BRW_BROWSER_CONTENT_TYPES_IN_PUSH__
    {"application/xhtml+xml"                   ,"xhtml"    ,MIME_TYPE_TEXT		 , MIME_SUBTYPE_XHTML                , MIME_MMI_TYPE},
    {"application/wml+xml"                     ,"wml"      ,MIME_TYPE_TEXT		 , MIME_SUBTYPE_WML_XML              , MIME_MMI_TYPE},
    {"application/vnd.wap.xhtml+xml"           ,"xhtml"    ,MIME_TYPE_TEXT		 , MIME_SUBTYPE_XHTML_MP             , MIME_MMI_TYPE},
#endif /* __MMI_BRW_BROWSER_CONTENT_TYPES_IN_PUSH__ */
#endif
#if defined(WMA_DECODE)
    {"audio/wma"                               ,"wma"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_WMA                  , MIME_MMI_TYPE},
    {"audio/x-ms-wma"                          ,"wma"      ,MIME_TYPE_AUDIO      , MIME_SUBTYPE_WMA                  , MIME_MMI_TYPE},
#endif
#ifdef __IMPS__
    {"application/vnd.wv.csp.xml,", "cxml", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_XML, MIME_MMI_TYPE},
    {"application/vnd.wv.csp.wbxml", "cwbxml", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_WBXML, MIME_MMI_TYPE},
    {"application/vnd.wv.csp.cir", "ccir", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_CIR, MIME_MMI_TYPE},
    {"application/vnd.wv.csp.sms", "csms", MIME_TYPE_APPLICATION, MIME_SUBTYPE_CSP_SMS, MIME_MMI_TYPE},
#endif
#ifdef M3D_MMI_SUPPORT
    {"application/vnd.mtk.m3d", "m3d",     MIME_TYPE_APPLICATION, MIME_SUBTYPE_M3D, MIME_MMI_TYPE},
#endif
#ifdef __MMI_BARCODEREADER__
    {"application/vnd.mtk.mbc", "mbc", MIME_TYPE_APPLICATION, MIME_SUBTYPE_MBC, MIME_MMI_TYPE},
#endif
#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    {"application/vnd.mtk.lrc", "lrc", MIME_TYPE_APPLICATION, MIME_SUBTYPE_LRC, MIME_MMI_TYPE},
#endif
#ifdef SYNCML_DM_SUPPORT
    {"application/vnd.syncml.dm+wbxml", "omadm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_WBXML, MIME_MMI_TYPE},
    {"application/vnd.syncml.dm+xml", "omadm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_XML, MIME_MMI_TYPE},
    {"application/vnd.syncml.notification", "omadm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_NOTIFICATION, MIME_MMI_TYPE},
    {"application/octet-stream", "", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DM_FUMO, MIME_MMI_TYPE},
#endif
#if defined(MUSICAM_DECODE)
    {"audio/mp2", "mp2", MIME_TYPE_AUDIO, MIME_SUBTYPE_AUDIO_MP2, MIME_MMI_TYPE},
#endif
#if defined(__FLAC_DECODE__)
    {"audio/flac", "flac", MIME_TYPE_AUDIO, MIME_SUBTYPE_AUDIO_FLAC, MIME_MMI_TYPE},
#endif
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#endif
#ifdef LANGLN_DIGIDEA
    {"application/dzd", "dzd", MIME_TYPE_APPLICATION, MIME_SUBTYPE_DZD, MIME_MMI_TYPE},
#endif
#ifdef SWFLASH_NEOMTEL
    {"image/vnd.ziyitong.zdd", "zdd", MIME_TYPE_APPLICATION, MIME_SUBTYPE_ZDD, MIME_MMI_TYPE},
    {"application/vnd.mtk.vis",  "vis",  MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, MIME_MMI_TYPE},
    {"application/vnd.mtk.ivis", "ivis", MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, MIME_MMI_TYPE},
    {"application/vnd.mtk.kvis", "kvis", MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, MIME_MMI_TYPE},
    {"application/vnd.mtk.mvis", "mvis", MIME_TYPE_APPLICATION, MIME_SUBTYPE_VIS, MIME_MMI_TYPE},
#endif
#ifdef __MMI_MESSAGES_EMS__
    {"application/vnd.mtk.ems", "ems", MIME_TYPE_APPLICATION, MIME_SUBTYPE_EMS, MIME_MMI_TYPE},
    {"application/vnd.mtk.anm", "anm", MIME_TYPE_APPLICATION, MIME_SUBTYPE_ANM, MIME_MMI_TYPE},
#endif    
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if ((defined __MMI_OP01_DCD__) || (defined __MMI_OP01_DCD_V30__))
    {"text/vnd.wap.sl",         "sl",  MIME_TYPE_TEXT, MIME_SUBTYPE_SL, MIME_MMI_TYPE},
    {"application/vnd.wap.slc", "slc", MIME_TYPE_APPLICATION, MIME_SUBTYPE_SLC, MIME_MMI_TYPE},
#endif

#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    {"application/vnd.omaloc-supl-init", "supl", MIME_TYPE_APPLICATION, MIME_SUBTYPE_SUPL, MIME_MMI_TYPE},
    {"application/vnd.wap.sic", "supl", MIME_TYPE_APPLICATION, MIME_SUBTYPE_SUPL, MIME_MMI_TYPE},
#endif

#ifdef __MMI_KURO_SUPPORT__
    {"application/kur", "kur", MIME_TYPE_APPLICATION, MIME_SUBTYPE_KUR, MIME_MMI_TYPE},
    {"application/klr", "klr", MIME_TYPE_APPLICATION, MIME_SUBTYPE_KLR, MIME_MMI_TYPE},
#endif
#ifdef __MMI_EMAIL__
    {"text/vnd.wap.emn+xml", "emn", MIME_TYPE_TEXT, MIME_SUBTYPE_EMN_XML, MIME_MMI_TYPE},
    {"application/vnd.wap.emn+wbxml", "emn", MIME_TYPE_APPLICATION, MIME_SUBTYPE_EMN_WBXML, MIME_MMI_TYPE},
#endif /* __MMI_EMAIL__ */

#ifdef __MMI_GADGET_SUPPORT__
    {"application/widget", "wgt", MIME_TYPE_APPLICATION, MIME_SUBTYPE_WIDGET, MIME_MMI_TYPE},
#endif
#ifdef __APE_DECODE__
    {"audio/x-monkeys-audio", "ape", MIME_TYPE_AUDIO, MIME_SUBTYPE_AUDIO_APE, MIME_MMI_TYPE},
    {"audio/x-ape", "ape", MIME_TYPE_AUDIO, MIME_SUBTYPE_AUDIO_APE, MIME_MMI_TYPE},   
    {"audio/ape", "ape", MIME_TYPE_AUDIO, MIME_SUBTYPE_AUDIO_APE, MIME_MMI_TYPE},
#endif
#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
        {"application/octet-stream",  "aco",  MIME_TYPE_APPLICATION, MIME_SUBTYPE_VXP, MIME_MMI_TYPE},
#endif  
    {"application/octet-stream",  "vxp",  MIME_TYPE_APPLICATION, MIME_SUBTYPE_VXP, MIME_MMI_TYPE},
    {"multipart/related", "", MIME_TYPE_MULTIPART, MIME_SUBTYPE_RELATED, MIME_MMI_TYPE}
};

static const kal_int32 g_applib_mime_tbl_size = sizeof(g_applib_mime_tbl) / sizeof(applib_mime_type_struct);

/* --- Dynamic table --- */

#define APPLIB_MIME_INIT_MAGIC_NUMBER 0x0221891A

static struct
{
    kal_uint32 inited_magic; /* If inited, this field will be set to APPLIB_MIME_INIT_MAGIC_NUMBER */
    kal_mutexid mutex;
    kal_int32 n_entries;
    applib_mime_type_dynamic_entry_element_struct *head;
    applib_mime_type_dynamic_entry_element_struct *tail;
}
g_applib_mime_dynamic_entry_list =
{
    0,
    0,
    0,
    NULL,
    NULL
};


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_mime_init
 * DESCRIPTION
 *  Initialize MIME type table and APIs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void applib_mime_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_applib_mime_dynamic_entry_list.inited_magic != APPLIB_MIME_INIT_MAGIC_NUMBER)
    {
        g_applib_mime_dynamic_entry_list.mutex = kal_create_mutex("Applib MIME dynamic table");
        g_applib_mime_dynamic_entry_list.inited_magic = APPLIB_MIME_INIT_MAGIC_NUMBER;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_mime_tolower
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  ch      [IN]        Charcater to be converted
 * RETURNS
 *  lower case character
 *****************************************************************************/
#define applib_mime_tolower(c) ( ((c) >= 'A' && (c) <= 'Z') ? (c) + ('a' - 'A') : (c) )


/*****************************************************************************
 * FUNCTION
 *  applib_mime_string_start_with
 * DESCRIPTION
 *  Search if str2 is start with srt1
 *  str1: audio/amr-wb   str2: audio/amr-wb;case1....  => MATCH
 *  str1: audio/amr      str2: audio/amr-wb;case2....  => NOT MATCH
 * PARAMETERS
 *  str1        [IN]        String pointer to be compared
 *  str2        [IN]        String pointer to be find
 * RETURNS
 *  Ture if one string exist in another string, otherwise, 0
 *****************************************************************************/
static kal_bool applib_mime_string_start_with(kal_char *str1, kal_char *str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 str1_len;
    kal_int32 str2_len;
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str1 == NULL || str2 == NULL)
    {
        return KAL_FALSE;
    }

    str1_len = strlen(str1);
    str2_len = strlen(str2);

    if (str1_len > str2_len)
    {
        return KAL_FALSE;
    }
    for (i = 0; i < str1_len; i++)
    {
        if (applib_mime_tolower((kal_uint8) str1[i]) != applib_mime_tolower((kal_uint8) str2[i]))
        {
            return KAL_FALSE;
        }
    }

    if(str1_len < str2_len)
    {
        if( str2[i]!= ';' && str2[i]!=',')
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mime_traverse
 * DESCRIPTION
 *  Please refer to app_mine.h
 *****************************************************************************/
const applib_mime_type_struct* applib_mime_traverse(
    void *arg_p,
    kal_int32 arg_v,
    kal_bool (*entry_callback)(void *arg_p, kal_int32 arg_v, const applib_mime_type_struct *entry))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    const applib_mime_type_struct* entry;
    applib_mime_type_dynamic_entry_element_struct *d_entry_ele;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < g_applib_mime_tbl_size; i++)
    {
        entry = &(g_applib_mime_tbl[i]);
    
        if (!entry_callback(arg_p, arg_v, entry))
        {
            return entry;
        }
    }

    for (d_entry_ele = g_applib_mime_dynamic_entry_list.head; d_entry_ele != NULL; d_entry_ele = d_entry_ele->next)
    {
        entry = &(d_entry_ele->mime_type);
    
        if (!entry_callback(arg_p, arg_v, entry))
        {
            return entry;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mime_type_look_up_ext_check_match
 * DESCRIPTION
 *  Used by applib_mime_type_look_up_ext to check whether the entry is the required.
 * PARAMETERS
 *  arg_p           [IN] applib_mime_type_look_up_ext_param_struct*
 *  arg_v           [IN] Not used
 *  entry           [IN] MIME entry
 * RETURNS
 *  KAL_TRUE if not match, continue traversing; otherwise returns KAL_FALSE.
 *****************************************************************************/
static kal_bool applib_mime_type_look_up_ext_check_match(
    void *arg_p,
    kal_int32 arg_v,
    const applib_mime_type_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_look_up_ext_param_struct *param;
    kal_char *s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param = (applib_mime_type_look_up_ext_param_struct*)arg_p;

    if (param->mime_type != 0 &&
        entry->mime_type != param->mime_type)
    {
        return KAL_TRUE;
    }

    if (param->mime_subtype != 0 &&
        entry->mime_subtype != param->mime_subtype)
    {
        return KAL_TRUE;
    }

    if (param->mime_string != NULL &&
        !applib_mime_string_start_with(entry->mime_string, param->mime_string))
    {
        return KAL_TRUE;
    }

    if (param->file_ext != NULL &&
        app_stricmp(param->file_ext, entry->file_ext) != 0)
    {
        return KAL_TRUE;
    }

    if (param->mime_type_string != NULL)
    {
        s = strchr(entry->mime_string, '/');
        
        if (s != NULL &&
            app_strnicmp(param->mime_type_string, entry->mime_string, s - entry->mime_string) != 0)
        {
            return KAL_TRUE;
        }
    }
    
    if (param->mime_subtype_string != NULL)
    {
        s = strchr(entry->mime_string, '/');
        
        if (s != NULL &&
            app_stricmp(param->mime_subtype_string, s + 1) != 0)
        {
            return KAL_TRUE;
        }
    }

    return KAL_FALSE; /* Found, stop traversal */
}


/*****************************************************************************
 * FUNCTION
 *  applib_mime_type_look_up_ext
 * DESCRIPTION
 *  Please refer to app_mine.h
 *****************************************************************************/
applib_mime_type_struct* applib_mime_type_look_up_ext(
    kal_char *mime_string,
    kal_char *mime_type_string,
    kal_char *mime_subtype_string,
    kal_char *file_ext,
    applib_mime_type_enum mime_type,
    applib_mime_subtype_enum mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_look_up_ext_param_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    param.mime_string = mime_string;
    param.mime_type_string = mime_type_string;
    param.mime_subtype_string = mime_subtype_string;
    param.file_ext = file_ext;
    param.mime_type = mime_type;
    param.mime_subtype = mime_subtype;
    
    return (applib_mime_type_struct*)applib_mime_traverse(&param, 0, applib_mime_type_look_up_ext_check_match);
}


/*****************************************************************************
 * FUNCTION
 *  applib_mime_type_look_up
 * DESCRIPTION
 *  Please refer to app_mine.h
 *****************************************************************************/
applib_mime_type_struct *applib_mime_type_look_up(
                            kal_char *mime_string,
                            kal_char *file_ext,
                            applib_mime_type_enum mime_type,
                            applib_mime_subtype_enum mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_mime_type_look_up_ext(mime_string, NULL, NULL, file_ext, mime_type, mime_subtype);
}


/*****************************************************************************
 * FUNCTION
 *  applib_mime_get_extension
 * DESCRIPTION
 *  Get file extension name position of given filepath string
 * PARAMETERS
 *  file_path   [IN] Filepath string
 * RETURNS
 *  Pointer of file extension name. NULL if not found.
 *****************************************************************************/
static kal_wchar *applib_mime_get_extension(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = kal_wstrlen(file_path);

    /* search from tail until "." */
    for (i = length - 1; i >= 0; i--)
    {
        if (file_path[i] == '.')
        {
            return &file_path[i + 1];
        }
    }
    
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  applib_mime_get_file_type
 * DESCRIPTION
 *  Please refer to app_mine.h
 *****************************************************************************/
applib_mime_type_struct *applib_mime_get_file_type(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime;
    kal_wchar *ptr;
    kal_char file_ext[33] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ptr = applib_mime_get_extension(file_path);

    if( ptr )
    {
        app_ucs2_str_n_to_asc_str((kal_int8*)file_ext,(kal_int8*) ptr, 32*2);

        mime = applib_mime_type_look_up(NULL, file_ext, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
    }
    else
    {
        mime = NULL;
    }

    return mime;
}


applib_mime_type_enum applib_mime_get_mime_type(kal_char *mime_type)
{
    kal_uint8 i;
    
    for (i = 0;(i < MIME_TYPE_MAX_NUM) && g_applib_mime_string[i] && app_stricmp(mime_type, (kal_char*)g_applib_mime_string[i]); i++);

    if (i < MIME_TYPE_MAX_NUM)
    {
        return (applib_mime_type_enum) i;
    }

    return MIME_TYPE_UNKNOWN;
}


kal_int32 mime_type_look_up_mul(kal_char** ext_array, kal_int32 array_count, app_mime_mem_alloc_funcptr_type alloc_fn,
                                applib_mime_type_struct*** result_table, kal_int32* result_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 count = 0, i, j, k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(result_table && result_count && alloc_fn);
    ASSERT(!(*result_table));

    for(i=0;i<array_count;i++)
    {
        for(j=0;j<g_applib_mime_tbl_size;j++)
        {
            if (app_stricmp(ext_array[i], g_applib_mime_tbl[j].file_ext) == 0)
                count++;
        }
    }

    *result_table = (applib_mime_type_struct**)alloc_fn(sizeof(applib_mime_type_struct*) * count);
    if(!(*result_table))
    {
        *result_count = -1;
        return -1;
    }
    
    k = 0;
    for(i=0;i<array_count;i++)
    {
        for(j=0;j<g_applib_mime_tbl_size;j++)
        {
            if (app_stricmp(ext_array[i], g_applib_mime_tbl[j].file_ext) == 0)
            {
                (*result_table)[k] = (applib_mime_type_struct*)&(g_applib_mime_tbl[j]);
                k++;
            }
        }
    }

    *result_count = count;
    return count;

}


/*****************************************************************************
 * FUNCTION
 *  applib_mime_register_mime_type
 * DESCRIPTION
 *  Please refer to app_mine.h
 *****************************************************************************/
const applib_mime_type_struct* applib_mime_register_mime_type(
    applib_mime_type_enum mime_type,
    applib_mime_subtype_enum mime_subtype,
    const kal_char *mime_string,
    const kal_char *file_ext)
{
    /***** NOT FOR INTERNAL USE BUT VENDORS ******/

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* If need to give a subtype to the entry, this value will be assigned.
       This value is function-static, and will/should be increased after be assigned */
    static kal_int32 free_mime_subtype_value = MIME_SUBTYPE_DYNAMIC_REG_BASE;

    applib_mime_type_dynamic_entry_element_struct *d_entry_ele;
    applib_mime_type_struct* entry;
    kal_int32 mime_string_len;
    kal_int32 file_ext_len;
    kal_char *buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EXT_ASSERT(mime_type != 0 && mime_string != NULL && file_ext != NULL,
        mime_type, (kal_int32)mime_string, (kal_int32)file_ext);

    applib_mime_init();

    if (g_applib_mime_dynamic_entry_list.n_entries >= APPLIB_MIME_MAX_DYNAMIC_REGISTRATION_NUM)
    {
        return NULL;
    }
    
    entry = applib_mime_type_look_up((kal_char*)mime_string, (kal_char*)file_ext, mime_type, mime_subtype);
    
    if (entry != NULL)
    {
        /* An entry already found in the table, we don't need to add */
        return entry;
    }

    mime_string_len = strlen(mime_string);
    file_ext_len = strlen(file_ext);

    /* Initialize the spaces for the new entry */
    buffer = (kal_char*)get_ctrl_buffer(sizeof(applib_mime_type_dynamic_entry_element_struct) + mime_string_len + file_ext_len + 2);
    d_entry_ele = (applib_mime_type_dynamic_entry_element_struct*)buffer;
    entry = &(d_entry_ele->mime_type);
    buffer += sizeof(applib_mime_type_dynamic_entry_element_struct);
    entry->mime_string = buffer;
    buffer += mime_string_len + 1;
    entry->file_ext = buffer;

    /* Set the fields of the entry */
    strcpy(entry->mime_string, mime_string);
    strcpy(entry->file_ext, file_ext);
    entry->mime_type = mime_type;
    if (mime_subtype != 0)
    {
        entry->mime_subtype = mime_subtype;
    }
    else
    {
        /* Not given, assign a new */
        entry->mime_subtype = (applib_mime_subtype_enum)(free_mime_subtype_value++);
    }
    entry->mmi_type = MIME_MMI_TYPE;

    /* Add the entry to the list */
    d_entry_ele->next = NULL;

    kal_take_mutex(g_applib_mime_dynamic_entry_list.mutex);

    if (g_applib_mime_dynamic_entry_list.n_entries < APPLIB_MIME_MAX_DYNAMIC_REGISTRATION_NUM)
    {
        if (g_applib_mime_dynamic_entry_list.tail == NULL)
        {
            g_applib_mime_dynamic_entry_list.head = d_entry_ele;
        }
        else
        {
            /* Append to tail, keep the entries can be visited in order */
            g_applib_mime_dynamic_entry_list.tail->next = d_entry_ele;
        }
        g_applib_mime_dynamic_entry_list.tail = d_entry_ele;
        g_applib_mime_dynamic_entry_list.n_entries++;
    }
    else
    {
        free_ctrl_buffer(buffer);
        entry = NULL;
    }

    kal_give_mutex(g_applib_mime_dynamic_entry_list.mutex);

    return entry;
}
