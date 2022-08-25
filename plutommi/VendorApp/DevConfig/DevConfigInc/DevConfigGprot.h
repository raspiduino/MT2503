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
 *   DevConfigGprot.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   3rd Party Get the system configuration information
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DEVCONFIGGPROT_H
#define DEVCONFIGGPROT_H


#include "MMIDataType.h"


typedef struct
{
    U32     jpg_decode;     /* jped decode */
    U32     jpg_encode;     /* jped encode */
    U32     gif_decode;     /* gif decode  */
    U32     png_decode;     /* png decode  */
} mmi_devconfig_graphics_codec_struct;

typedef struct
{
    U32     touch_screen            :1; /* touch panel support */
    U32     figner_touch_support    :1; /* finger touch support */
    U32     keypad_type;                /* normal keypad */
} mmi_devconfig_input_device_struct;

typedef struct
{
    U32     camera_support      :1; /* camera support */
    U32     camcorder_support   :1; /* camcoder support */
    U32     horizontal_camera   :1; /* horizontal camera support */
    U32     dual_camera         :1; /* dual camera support */
    U32     sensor_rotate;          /* camera sensor rotate support */
} mmi_devconfig_camera_device_struct;

typedef struct
{
    U32     wap_support         :1; /* wap support */
    U32     mms_support         :1; /* mms support */
    U32     tcpip_support       :1; /* tcpip support */
    U32     wlan_support        :1; /* wlan support */
    U32     mms_version;            /* mms version */
} mmi_devconfig_network_protocol_struct;

typedef struct
{
    U32     gps_support         :1; /* gps support */
    U32     motion_sensor       :1; /* motion sensor support */
    U32     cell_info_support   :1; /* nbr cell info support */
} mmi_devconfig_remote_sensing_device_struct;

typedef struct
{
    U32     phb_option_field    :1; /* phonebook option support */
    U32     phb_option_2_email  :1; /* phonebook option2 email support */
    U32     phb_birthday_field  :1; /* phonebook birthday support */
    U32     phb_info_field      :1; /* phonebook information support */
} mmi_devconfig_srv_phonebook_struct;

typedef struct
{
    U32     xml_parser          :1; /* xml parser support */
    U32     xml_generator       :1; /* xml generator support */
    U32     wbxml_parser        :1; /* wbxml parser support */
    U32     wbxml_generator     :1; /* wbxml generator support */
} mmi_devconfig_xml_wbxml_struct;

typedef struct
{
    U32     fe_vector_support   :1; /* vector font support */
    U32     fe_r2l_state        :1; /* Right2Left support */
    U32     font_engine_type;       /* vector font engine type */
} mmi_devconfig_font_engine_struct;

typedef struct
{
    U32     audio_bgsnd_support         :1; /* Audio background sound support */
    U32     audio_tts_support           :1; /* Audio sound play support */
    U32     audio_equalizer_support     :1; /* Audio equalizer support */
    U32     audio_reverb_support        :1; /* Audio reverb support */
    U32     audio_3d_support            :1; /* Audio 3D support */
    U32     audio_time_stretch_support  :1; /* Audio time stretch support */
    U32     audio_bitstring_support     :1; /* Audio bitstring support */
    U32     audio_vocal_removal         :1; /* Audio vocal removal support */
    U32     audio_pitch_shifting        :1; /* Audio pitch shifting support */
    U32     video_bitstring_support     :1; /* Video bitstring support */
    U32     video_play_support          :1; /* Video play support */
    U32     video_play_snapshot         :1; /* Video play snapshot support*/
    U32     video_play_adjustment       :1; /* Video play adjustment support*/
} mmi_devconfig_multimedia_struct;

typedef struct
{
    U32     gdi_6_layer                 :1; /* GDI_6_LAYERS support */
    U32     gdi_layer_rotate            :1; /* GDI_USING_LAYER_ROTATE support */
} mmi_devconfig_gdi_feature_struct;

typedef struct
{
    U32     dual_sim_master     :1;     /* dual sim master */
    U32     usb_mass_storage    :1;     /* usb mass storage support */
    U32     memory_provide;             /* memory buffer provide */
    U32     memory_size;                /* memory buffer size */
    U32     am_memory_size;             /* am memory buffer size */
    U32     lcd_width;                  /* lcd width size */
    U32     lcd_height;                 /* lcd height size */
    mmi_devconfig_font_engine_struct      font_engine;        /* vector font support */
    mmi_devconfig_input_device_struct     input_device;       /* input devices infor */
    mmi_devconfig_multimedia_struct       multimedia;         /* multimedia support information */
    mmi_devconfig_camera_device_struct    camera_device;      /* camera devices  infor */
    mmi_devconfig_graphics_codec_struct   graphics_codec;     /* graphics codec type */
    mmi_devconfig_network_protocol_struct newwork_protocol;   /* network protocol */
    mmi_devconfig_remote_sensing_device_struct    remote_sensing; /* remote sensing device information */
    mmi_devconfig_srv_phonebook_struct    srv_phonebook;      /* server phonebook infor */
    mmi_devconfig_xml_wbxml_struct        xml_wbxml;          /* xml and wbxml information */
    mmi_devconfig_gdi_feature_struct      gdi_info;           /* gdi feature information */
} mmi_devconfig_system_config_struct;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_devconfig_get_system_config
 * DESCRIPTION
 *  Get the system config information for vendor application
 * PARAMETERS
 *  p_sys_config      : [IN] the struct of the system config
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_devconfig_get_system_config(mmi_devconfig_system_config_struct * p_sys_config);

#endif /* DEVCONFIGGPROT_H */ 

