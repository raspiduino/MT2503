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
 *   app_mine.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines structure, contant, and function prototypes for mine type interfaces.
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
 *==============================================================================
 *******************************************************************************/
#ifndef __APP_MINE_H__
#define __APP_MINE_H__

/***************************************************************************** 
 * Define
 *****************************************************************************/

    #include "kal_general_types.h"

#define APPLIB_MIME_MAX_DYNAMIC_REGISTRATION_NUM 20


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/*
 * Major category the MIME type belongs to. This is the MIME type category IN
 * MTK SOLUTION. This enum value is not always mapped to the prefix of MIME type
 * string. For example, "application/xhtml+xml" is treated as MIME_TYPE_TEXT in
 * MTK solution. Vice versa, prefix MIME_TYPE_TEXT is not always "text/ *".
 */
typedef enum
{
    MIME_TYPE_NONE = 0,
    MIME_TYPE_TEXT,         /* TEXT category */
    MIME_TYPE_IMAGE,        /* IMAGE category */
    MIME_TYPE_AUDIO,        /* AUDIO category */
    MIME_TYPE_VIDEO,        /* VIDEO category */
    MIME_TYPE_APPLICATION,  /* APPLICATION category */
    MIME_TYPE_MESSAGE,      /* MESSAGE category */
    MIME_TYPE_MULTIPART,    /* MULTIPART category */
    MIME_TYPE_UNKNOWN,      /* Unknown MIME types */
    MIME_TYPE_MAX_NUM
} applib_mime_type_enum;

/*
 * Sub-MIME types enum value.
 * Application should use these values to distinguish content types. Each content type
 * should has an unique value.
 * NOTE that different MIME type string may belong to the same MIME type; i.e., one
 * MIME type may own 2 or more MIME type strings. For this case, there would be more
 * than one entries in the system table that has the same subtype enum.
 */
typedef enum
{
    MIME_SUBTYPE_NONE = 0,
    MIME_SUBTYPE_AMR                  ,         /*audio/amr                                  */
    MIME_SUBTYPE_IMELODY              ,         /*audio/imelody                              */
    MIME_SUBTYPE_MID                  ,         /*audio/mid                                  */
    MIME_SUBTYPE_MIDI                 ,         /*audio/midi                                 */
    MIME_SUBTYPE_SPMIDI               ,         /*audio/sp-midi                              */
    MIME_SUBTYPE_SPMIDI_1             ,
    MIME_SUBTYPE_WAV                  ,         /*audio/wav                                  */
    MIME_SUBTYPE_VM                   ,         /*audio/vm                                   */
    MIME_SUBTYPE_XMIDI                ,         /*audio/x-midi                               */
    MIME_SUBTYPE_XWAV                 ,         /*audio/x-wav                                */
    MIME_SUBTYPE_BMP                  ,         /*image/bmp                                  */
    MIME_SUBTYPE_BMP_1                ,         /*image/x-MS-bmp                             */
    MIME_SUBTYPE_GIF                  ,         /*image/gif                                  */
    MIME_SUBTYPE_WBMP                 ,         /*image/vnd.wap.wbmp                         */
    MIME_SUBTYPE_XIMELODY             ,         /*text/x-imelody                             */
    MIME_SUBTYPE_DRM_CONTENT          ,         /*application/vnd.oma.drm.content            */
    MIME_SUBTYPE_DRM_MESSAGE          ,         /*application/vnd.oma.drm.message            */
    MIME_SUBTYPE_DRM_RIGHTS_WBXML     ,         /*application/vnd.oma.drm.rights+wbxml       */
    MIME_SUBTYPE_DRM_RIGHTS_XML       ,         /*application/vnd.oma.drm.rights+xml         */
    MIME_SUBTYPE_DRM_CONTENT_V2       ,         /*application/vnd.oma.drm.dcf                */
    MIME_SUBTYPE_ROAP_PDU             ,         /*"application/vnd.oma.drm.roap-pdu+xml"     */
    MIME_SUBTYPE_ROAP_TRIGGER         ,         /*"application/vnd.oma.drm.roap-trigger+xml" */
    MIMI_SUBTYPE_PROTECTED_RO         ,         /*"application/vnd.oma.drm.ro              " */
    MIME_SUBTYPE_JAR                  ,         /*application/java-archive                   */
    MIME_SUBTYPE_JVM                  ,         /*application/java-vm                        */
    MIME_SUBTYPE_JAD                  ,         /*text/vnd.sun.j2me.app-descriptor           */
    MIME_SUBTYPE_THEME                ,         /*OMAapp/mtk.med.thm,mtk/med.thm             */
    MIME_SUBTYPE_PLAIN                ,         /*text/plain                                 */
    MIME_SUBTYPE_OMA_DD               ,         /*application/vnd.oma.dd+xml                 */
    MIME_SUBTYPE_HBSVCS               ,         /*application/hbs-vcs                        */
    MIME_SUBTYPE_CALENDAR             ,         /*text/calendar                              */
    MIME_SUBTYPE_XVCALENDAR           ,         /*text/x-vcalendar                           */
    MIME_SUBTYPE_VCARD                ,         /*application/vcard                          */
    MIME_SUBTYPE_XVCARD               ,         /*text/x-vcard                               */
    MIME_SUBTYPE_REFERTO              ,         /*application/vnd.poc.refer-to               */
    MIME_SUBTYPE_SDP                  ,         /*application/sdp                            */
    MIME_SUBTYPE_AAC                  ,         /*audio/aac                                  */
    MIME_SUBTYPE_XAAC                 ,         /*audio/x-aac                                */
    MIME_SUBTYPE_AWB                  ,         /*audio/amr-wb                               */
    MIME_SUBTYPE_AUDIO_MP3            ,         /*audio/mp3                                  */
    MIME_SUBTYPE_AUDIO_MPEG           ,         /*audio/mpeg                                 */
    MIME_SUBTYPE_AUDIO_MPG            ,         /*audio/mpg                                  */
    MIME_SUBTYPE_AUDIO_MPG3           ,         /*audio/mpg3                                 */
    MIME_SUBTYPE_AUDIO_XMP3           ,        /*audio/x-mp3                                */
    MIME_SUBTYPE_JPEG                 ,         /*image/jpeg                                 */
    MIME_SUBTYPE_JPG                  ,         /*image/jpg                                  */
    MIME_SUBTYPE_AVI                  ,         /*video/x-msvideo                            */
    MIME_SUBTYPE_AVI_1                ,         /*video/avi                                  */
    MIME_SUBTYPE_VSMAF                ,         /*application/vnd.smaf                       */
    MIME_SUBTYPE_XSMAF                ,         /*application/x-smaf                         */
    MIME_SUBTYPE_SMIL                 ,         /*application/smil                           */
    MIME_SUBTYPE_MIXED                ,         /*multipart/mixed                            */
    MIME_SUBTYPE_3GPP_VIDEO           ,         /*video/3gp                                  */
    MIME_SUBTYPE_3GPP_VIDEO_1         ,         /*video/3gpp                                 */
    MIME_SUBTYPE_3GPP_VIDEO_2         ,         /*application/.3gp                           */
    MIME_SUBTYPE_3GPP_AUDIO           ,         /*audio/3gpp                                 */
    MIME_SUBTYPE_3GP_AUDIO            ,         /*audio/3gp                                  */
    MIME_SUBTYPE_3GPP2_VIDEO          ,         /*video/3gpp2                                */
#ifdef __MKV_FILE_FORMAT_SUPPORT__ 
    MIME_SUBTYPE_MKV_VIDEO            ,         /*video/x-matroska                                  */
    MIME_SUBTYPE_WEBM_VIDEO            ,         /*video/webm                                  */
#endif	/* __MKV_FILE_FORMAT_SUPPORT__ */
    MIME_SUBTYPE_MP4                  ,         /*video/mp4                                  */
    MIME_SUBTYPE_MP4_AUDIO            ,         /*audio/mp4                                  */
    MIME_SUBTYPE_AUDIO_OGG            ,         /*audio/ogg                                  */
#ifdef __FLV_FILE_FORMAT_SUPPORT__
    MIME_SUBTYPE_FLV_VIDEO            ,         /*audio/mp4                                  */
    MIME_SUBTYPE_F4V_VIDEO            ,         /*audio/mp4                                  */
#endif
    MIME_SUBTYPE_MPEG                 ,         /*video/mpeg                                 */
    MIME_SUBTYPE_MPEG4                ,         /*video/mpeg4                                */
    MIME_SUBTYPE_MPG                  ,         /*video/mpg                                  */
    MIME_SUBTYPE_M4A                  ,         /*audio/m4a                                  */
    MIME_SUBTYPE_XM4A                 ,         /*audio/x-m4a                                */
    MIME_SUBTYPE_RA                   ,         /*audio/x-realaudio                          */
    MIME_SUBTYPE_RV                   ,         /*video/vnd.rn-realvideo                         */
    MIME_SUBTYPE_RM                   ,         /*application/vnd.rn-realmedia                          */
    MIME_SUBTYPE_RMVB                 ,         /*video/x-pn-realvideo                         */
    MIME_SUBTYPE_PNG                  ,         /*image/png                                  */
    MIME_SUBTYPE_SVG                  ,         /*image/svg+xml                              */
    MIME_SUBTYPE_CA_CERT              ,         /*application/x-x509-ca-cert                 */
    MIME_SUBTYPE_USR_CERT             ,         /*application/x-x509-user-cert               */
    MIME_SUBTYPE_OMA_PROV_WBXML       ,         /*application/vnd.wap.connectivity-wbxml     */
    MIME_SUBTYPE_PKCS7_CERT           ,         /*application/x-pkcs7-certificates           */
    MIME_SUBTYPE_PKCS12_CERT          ,         /*application/x-pkcs12                       */
    MIME_SUBTYPE_NOKIA_PROV_BOOKMARKS ,         /*application/x-wap-prov.browser-bookmarks   */
    MIME_SUBTYPE_NOKIA_PROV_BROWSER   ,         /*application/x-wap-prov.browser-settings    */
    MIME_SUBTYPE_CSS                  ,         /*text/css                                   */
    MIME_SUBTYPE_HTML                 ,         /*text/html                                  */
    MIME_SUBTYPE_OMA_PROV_XML         ,         /*text/vnd.wap.connectivity-xml              */
    MIME_SUBTYPE_WML                  ,         /*text/vnd.wap.wml                           */
    MIME_SUBTYPE_WMLSCRIPT            ,         /*text/vnd.wap.wmlscript                     */
    MIME_SUBTYPE_WMLC                 ,         /*application/vnd.wap.wmlc                   */
    MIME_SUBTYPE_WMLSC                ,         /*application/vnd.wap.wmlscriptc             */
    MIME_SUBTYPE_XHTML                ,         /*application/xhtml+xml                      */
    MIME_SUBTYPE_WML_XML              ,         /*application/wml+xml                        */
    MIME_SUBTYPE_XHTML_MP             ,         /*application/vnd.wap.xhtml+xml              */
    MIME_SUBTYPE_WMA                  ,         /*audio/wma                                  */
    MIME_SUBTYPE_WMA_1                ,         /*audio/x-ms-wma                             */
    MIME_SUBTYPE_CSP_XML              ,         /*application/vnd.wv.csp.xml                 */
    MIME_SUBTYPE_CSP_WBXML            ,         /*application/vnd.wv.csp.wbxml               */
    MIME_SUBTYPE_CSP_CIR              ,         /*application/vnd.wv.csp.cir */
    MIME_SUBTYPE_CSP_SMS              ,         /*application/vnd.wv.csp.sms */
    MIME_SUBTYPE_M3D                  ,         /*application/vnd.mtk.m3d */
    MIME_SUBTYPE_ZDD                  ,         /*image/vnd.ziyitong.zdd                     */
    MIME_SUBTYPE_VIS                  ,         /*application/vnd.mtk.vis                    */
    MIME_SUBTYPE_AU                   ,         /*audio/au*/
    MIME_SUBTYPE_PDB                  ,         /*application/x-pilot-pdb*/
    MIME_SUBTYPE_AU_XULAW             ,         /*audio/x-ulaw */
    MIME_SUBTYPE_AIFF                 ,         /*audio/x-aiff*/
    MIME_SUBTYPE_AIF                  ,         /*audio/x-aiff*/
    MIME_SUBTYPE_AIFC                 ,         /*audio/x-aiff*/
    MIME_SUBTYPE_SND                  ,         /*audio/basic*/
    MIME_SUBTYPE_MBC                  ,         /*application/vnd.mtk.mbc                    */
    MIME_SUBTYPE_LRC                  ,         /*application/vnd.mtk.lrc                    */
    MIME_SUBTYPE_DM_WBXML             ,         /*application/vnd.syncml.dm+wbxml            */
    MIME_SUBTYPE_DM_XML               ,         /*application/vnd.syncml.dm+xml              */
    MIME_SUBTYPE_DM_NOTIFICATION      ,         /*application/vnd.syncml.notification        */
    MIME_SUBTYPE_DM_FUMO              ,         /*application/octet-stream                   */
    MIME_SUBTYPE_RELATED              ,         /*multipart/related*/
    MIME_SUBTYPE_AUDIO_MP2            ,         /*"audio/mp2"*/
    MIME_SUBTYPE_AUDIO_FLAC           ,         /*"audio/flac"*/
    MIME_SUBTYPE_DS_NOTIFICATION      ,         /*application/vnd.syncml.ds.notification     */
    MIME_SUBTYPE_OMA_DD2              ,         /*application/vnd.oma.dd2+xml                */
    MIME_SUBTYPE_DZD                  ,         /*application/dzd                            */
    MIME_SUBTYPE_XVBOOKMARK           ,         /*text/x-vbookmark                           */
    MIME_SUBTYPE_EMS                  ,         /*application/vnd.mtk.ems*/
    MIME_SUBTYPE_ANM                  ,         /*application/vnd.mtk.anm*/
    MIME_SUBTYPE_WAP_MIXED            ,         /*application/vnd.wap.multipart.mixed        */
    MIME_SUBTYPE_WAP_RELATED          ,         /*application/vnd.wap.multipart.related      */
    MIME_SUBTYPE_DS_OMA_EMAIL         ,         /*application/vnd.omads-email+xml*/
    MIME_SUBTYPE_DS_OMA_FOLDER        ,         /*application/vnd.omads-folder+xml*/
    MIME_SUBTYPE_DS_RFC822_EMAIL      ,         /*message/rfc822*/
    MIME_SUBTYPE_SL                   ,         /* text/vnd.wap.sl                          */
    MIME_SUBTYPE_SLC                  ,         /* application/vnd.wap.slc                  */
    MIME_SUBTYPE_SUPL                 ,         /*application/vnd.omaloc-supl-init*/
    MIME_SUBTYPE_MMS                  ,         /* application/vnd.wap.mms-message */
	MIME_SUBTYPE_GSX				  ,			/* GGLive */
    MIME_SUBTYPE_UNRECOGNIZED         ,         /* Un-recognized file type */
    MIME_SUBTYPE_KUR                  ,         /*application/kur*/
    MIME_SUBTYPE_KLR                  ,         /*application/klr*/
    MIME_SUBTYPE_EMN_XML              ,         /* text/vnd.wap.emn+xml */
    MIME_SUBTYPE_EMN_WBXML            ,         /* application/vnd.wap.emn+wbxml */
    MIME_SUBTYPE_WIDGET               ,         /* application/widget */
    MIME_SUBTYPE_AUDIO_APE            ,         /* audio/ape          */
    MIME_SUBTYPE_VXP                  ,         /* application/vnd.mtk.vxp */
    /* DOM-NOT_FOR_SDK-BEGIN */
    MIME_SUBTYPE_DYNAMIC_REG_BASE     ,         /* Base value for dynamically registered subtype */
    MIME_SUBTYPE_DYNAMIC_REG_NEW_1    ,
    MIME_SUBTYPE_DYNAMIC_REG_NEW_2    ,
    MIME_SUBTYPE_DYNAMIC_REG_NEW_3    ,
    MIME_SUBTYPE_DYNAMIC_REG_NEW_4    ,
    MIME_SUBTYPE_DYNAMIC_REG_NEW_5    ,
    MIME_SUBTYPE_DYNAMIC_REG_END = MIME_SUBTYPE_DYNAMIC_REG_BASE + APPLIB_MIME_MAX_DYNAMIC_REGISTRATION_NUM,
    /* DOM-NOT_FOR_SDK-END */
    
    MIME_SUBTYPE_NUM            /* Number of supported mime subtype */
} applib_mime_subtype_enum;


/*
 * This enum is not used currently.
 */
typedef enum
{
    MIME_MMI_TYPE = 0
} applib_mime_mmi_type;


/*
 * MIME type entry in the system table. Note that mime_type only represents the MIME category in the
 * system table, the prefix of mime_string may not the same to the category.
 * If application get an MIME type entry from the system table, DO NOT modify the values
 * and ALWAYS add the qualifier <b>const</b> for the returned pointer to avoid modifying
 * the value carelessly. I.e., ALWAYS put a qualifier <b>const</b> before applib_mime_type_struct*:
 * <code>
 * <b>const</b> applib_mime_type_struct* mime_type;
 * mime_type = applib_mime_type_look_up(NULL, NULL, 0, MIME_TYPE_MIME_SUBTYPE_AUDIO_MP3);
 * strcat(filepath, mime_type->file_ext);
 * </code>
 * SEE ALSO
 *  applib_mime_type_enum
 */
typedef struct
{
    kal_char *mime_string;                  /* The string of mime type and mime subtype */
    kal_char *file_ext;                     /* File extension */
    applib_mime_type_enum mime_type;        /* Mime type */
    applib_mime_subtype_enum mime_subtype;  /* Mime subtype */
    applib_mime_mmi_type mmi_type;          /* Unused currently */
} applib_mime_type_struct;

typedef void* (*app_mime_mem_alloc_funcptr_type)(kal_uint32 size);


/*****************************************************************************              
 * Global Functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_mime_type_look_up_ext
 * DESCRIPTION
 *  To find one MIME entry in the system table which matches all conditions.
 *  ALWAYS add a qualifier <b>const</b> for the returned pointer. I.e.,
 *  <code>
 *  <b>const</b> applib_mime_type_struct* mime_type;
 *  mime_type = applib_mime_type_look_up_ext(...);
 *  strcat(filepath, mime_type->file_ext);
 *  </code>
 *  And DO NOT modify its content.
 *  If needs more condition or to get all entries, please try applib_mime_traverse().
 * PARAMETERS
 *  mime_string         : [IN] If not NULL, the mime_string of the entry should match
 *                             the first element of this parameter. E.g.,
 *                             this parameter is "image/jpeg; u=5", then entry->mime_string
 *                             should be "image/jpeg".
 *  mime_type_string    : [IN] If not NULL, entry's main MIME string should equal to this string.
 *                             E.g., pass "image", then entry->mime_string should be "image/xxx".
 *  mime_subtype_string : [IN] If not NULL, entry's subtype string should equal to this string.
 *                             E.g., pass "jpeg", then entry->mime_string should be "xxx/jpeg".
 *  file_ext            : [IN] If not NULL, entry->file_ext should equal to this string with
 *                             case insensitive
 *  mime_type           : [IN] If not 0, entry->mime_type should equal to this value
 *  mime_subtype        : [IN] If not 0, entry->mime_subtype should equal to this value
 * RETURNS
 *  An entry matches all conditions. NULL if not found.
 * SEE ALSO
 *  applib_mime_traverse
 *****************************************************************************/
extern applib_mime_type_struct *applib_mime_type_look_up_ext(
    kal_char *mime_string,
    kal_char *mime_type_string,
    kal_char *mime_subtype_string,
    kal_char *file_ext,
    applib_mime_type_enum mime_type,
    applib_mime_subtype_enum mime_subtype);

/*****************************************************************************
 * FUNCTION
 *  applib_mime_type_look_up
 * DESCRIPTION
 *  To find one MIME entry in the system table which matches all conditions.
 *  ALWAYS add a qualifier <b>const</b> for the returned pointer. I.e.,
 *  <code>
 *  <b>const</b> applib_mime_type_struct* mime_type;
 *  mime_type = applib_mime_type_look_up(NULL, NULL, 0, MIME_TYPE_MIME_SUBTYPE_AUDIO_MP3);
 *  </code>
 *  And DO NOT modify its content.
 *  If you need more criteria or to get all entries, please try applib_mime_traverse().
 * PARAMETERS
 *  mime_string         : [IN] If not NULL, the mime_string of the entry should match
 *                             the first element of this parameter. E.g.,
 *                             this parameter is "image/jpeg; u=5", then entry->mime_string
 *                             should be "image/jpeg".
 *  file_ext            : [IN] If not NULL, entry->file_ext should equal to this string with
 *                             case insensitive
 *  mime_type           : [IN] If not 0, entry->mime_type should equal to this value
 *  mime_subtype        : [IN] If not 0, entry->mime_subtype should equal to this value
 * RETURNS
 *  An entry matches all conditions. NULL if not found.
 * SEE ALSO
 *  applib_mime_traverse
 *****************************************************************************/
extern applib_mime_type_struct *applib_mime_type_look_up(
                                    kal_char *mime_string,
                                    kal_char *file_ext,
                                    applib_mime_type_enum mime_type,
                                    applib_mime_subtype_enum mime_subtype);

/*****************************************************************************
 * FUNCTION
 *  applib_mime_get_file_type
 * DESCRIPTION
 *  Get one MIME entry in the system table which matches the file extension
 *  of the given file path.
 *  ALWAYS add a qualifier <b>const</b> for the returned pointer. I.e.,
 *  <code>
 *  <b>const</b> applib_mime_type_struct* mime_type;
 *  mime_type = applib_mime_get_file_type(filepath);
 *  </code>
 *  And DO NOT modify its content.
 * PARAMETERS
 *  file_path       : [IN] File path string. This API will extract the extension
 *                         from the file path to find an entry.
 * RETURNS
 *  An entry matches the file extension. NOTE that, there may be more than one
 *  entries matches the extension; to find all of them, try applib_mime_traverse().
 * SEE ALSO
 *  applib_mime_traverse
 *****************************************************************************/
extern applib_mime_type_struct *applib_mime_get_file_type(kal_wchar *file_path);

/*****************************************************************************
 * FUNCTION
 *  applib_mime_get_mime_type
 * DESCRIPTION
 *  Get the applib_mime_type_enum value by string. For example, pass "text"
 *  it returns MIME_TYPE_TEXT. However, note that "text/ *" is not always mapped
 *  to MIME_TYPE_TEXT in the system table, see the description of applib_mime_type_enum.
 * PARAMETERS
 *  mime_type       : [IN] Prefix of MIME type string
 * RETURNS
 *  Value in applib_mime_type_enum
 * SEE ALSO
 *  applib_mime_traverse
 *****************************************************************************/
extern applib_mime_type_enum applib_mime_get_mime_type(kal_char *mime_type);

/*****************************************************************************
 * FUNCTION
 *  applib_mime_traverse
 * DESCRIPTION
 *  To traverse all entries in the system table, including dynamically registered.
 * PARAMETERS
 *  arg_p           : [IN] This pointer will be passed to the entry_callback
 *  arg_v           : [IN] This value will be passed to the entry_callback
 *  entry_callback  : [IN] All entries will be passed into this callback function.
 *                         Return TRUE to continue to visit next entry;
 *                         otherwise return FALSE to stop traversal.
 * RETURNS
 *  The last entry, whose entry_callback return FALSE.
 *  If all entries are visited but entry_callback always returned TRUE,
 *  NULL will be returned.
 * EXAMPLE
 *  To find an entry whose mime_subtype is MIME_SUBTYPE_AUDIO_MP3.
 *  The same to applib_mime_type_look_up(NULL, NULL, 0, MIME_SUBTYPE_AUDIO_MP3);
 *  <code>
 *  static kal_bool myapp_is_mp3_type(void *arg_p, kal_int32 arg_v, const applib_mime_type_struct *entry)
 *  {
 *      // If the subtype does not match what we want, return KAL_TRUE to visit next
 *      // Otherwise, return KAL_FALSE to stop traversal
 *      return (entry->mime_subtype != (applib_mime_subtype_enum)arg_v);
 *  }
 *
 *  void myapp_func(void)
 *  {
 *      const applib_mime_type_struct* mime_type;
 *
 *      mime_type = applib_mime_traverse(NULL, MIME_SUBTYPE_AUDIO_MP3, myapp_is_mp3_type);
 *
 *      if (mime_type != NULL)
 *      {
 *          // ......
 *      }
 *  }
 *  </code>
 *  To find at most 6 entries whose file_ext is "avi"
 *  <code>
 *  typedef
 *  {
 *      const applib_mime_type_struct **entries;
 *      kal_int32 num_of_entries;
 *      const kal_char *file_ext;
 *  } myapp_mime_type_result_by_file_ext_struct;
 *
 *  static kal_bool myapp_fill_entries_by_file_ext(
 *                      void *arg_p,
 *                      kal_int32 arg_v,
 *                      const applib_mime_type_struct *entry)
 *  {
 *      myapp_mime_type_result_by_file_ext_struct *param =
 *          (myapp_mime_type_result_by_file_ext_struct*)arg_p;
 *
 *      if (stricmp(entry->file_ext, param->file_ext) == 0)
 *      {
 *          param->entries[param->num_of_entries++] = entry;
 *      }
 *
 *      return (param->num_of_entries < arg_v);
 *  }
 *
 *  void myapp_func2(void)
 *  {
 *      myapp_mime_type_result_by_file_ext_struct result;
 *
 *      result.entries = (const applib_mime_type_struct*)get_ctrl_buffer(
 *                          sizeof(const applib_mime_type_struct*) * 6);
 *      result.num_of_entries = 0;
 *      result.file_ext = "avi";
 *      applib_mime_traverse(&result, 6, myapp_fill_entries_by_file_ext);
 *      // ...
 *  }
 *  </code>
 *****************************************************************************/
extern const applib_mime_type_struct* applib_mime_traverse(
    void *arg_p,
    kal_int32 arg_v,
    kal_bool (*entry_callback)(void *arg_p, kal_int32 arg_v, const applib_mime_type_struct *entry));

/*****************************************************************************
 * FUNCTION
 *  applib_mime_register_mime_type
 * DESCRIPTION
 *  Register a new entry of MIME type to system table. If there is already
 *  an entry in the table(match all values), the entry will be returned.
 *  Otherwise, an new one will be created and inserted into the table.
 *  If mime_subtype is not assigned(0), the entry will be given an appropriate
 *  mime_subtype value.
 *  Internal developers DO NOT use this API but have to fill the system table.
 * PARAMETERS
 *  mime_type       : [IN] (Main) MIME type enum. e.g. MIME_TYPE_AUDIO
 *  mime_subtype    : [IN] MIME subtype. If pass 0, the returned entry will be
 *                         assigned an appropriate value.
 *  mime_string     : [IN] MIME type string. e.g. "audio/mpeg"
 *  file_ext        : [IN] File extension in the system. e.g. "mp3"
 * RETURNS
 *  If the maximum number of entries is exceeded, the pointer returned will be NULL.
 *  If already an entry exists, it will be returned. Otherwise, a new entry
 *  will be created and returned. If mime_subtype == 0, a value will be assigned
 *  to the entry.
 *****************************************************************************/
extern const applib_mime_type_struct* applib_mime_register_mime_type(
    applib_mime_type_enum mime_type,
    applib_mime_subtype_enum mime_subtype,
    const kal_char *mime_string,
    const kal_char *file_ext);

/* DOM-NOT_FOR_SDK-BEGIN */
extern kal_int32 mime_type_look_up_mul(kal_char** ext_array, kal_int32 array_count, app_mime_mem_alloc_funcptr_type alloc_fn,
                                       applib_mime_type_struct*** result_table, kal_int32* result_count);
/* DOM-NOT_FOR_SDK-END */

#endif /* __APP_MINE_H__ */ 

