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
 *   DevConfig.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "DevConfigDef.h"
#include "DevConfigGProt.h"
#include "string.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "lcd_sw_inc.h"
#include "PixcomFontEngine.h"
    
#include "AMGprot.h"
#include "vmopt.h"
/*****************************************************************************
 * FUNCTION
 *  mmi_devconfig_get_system_config
 * DESCRIPTION
 *  Get system config information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_devconfig_get_system_config(mmi_devconfig_system_config_struct * p_sys_config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static mmi_devconfig_system_config_struct g_system_config;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_system_config, 0, sizeof(mmi_devconfig_system_config_struct));

#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#endif

#if defined(__USB_IN_NORMAL_MODE__)
    g_system_config.usb_mass_storage = MMI_TRUE;
#endif

    /* memory provider information */
#if defined(__MRE_MEDIA_BUF__)
    g_system_config.memory_provide = MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA;
#endif

#if !defined(__MRE_MEDIA_BUF__)
    g_system_config.memory_provide = MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM;
#endif

    /* memory buffer size */
    g_system_config.memory_size = (MRE_SYS_MEMPOOL_SIZE);

#ifdef __MRE_AM__
	g_system_config.am_memory_size = MMI_AM_MAX_DYN_MEM_SIZE;
#else
	g_system_config.am_memory_size = 0;
#endif

    /* lcd size */
	g_system_config.lcd_width = LCD_WIDTH;
    g_system_config.lcd_height = LCD_HEIGHT;

    /* font engine information */
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    g_system_config.font_engine.fe_vector_support = mmi_fe_is_vector_font_support();
    g_system_config.font_engine.fe_r2l_state = mmi_fe_is_r2l_state();
    g_system_config.font_engine.font_engine_type = MMI_DEVCONFIG_FONT_ENGINE_FREE_TYPE;
#endif

    /* input devices information */
#if defined(__MMI_TOUCH_SCREEN__)
    g_system_config.input_device.touch_screen = MMI_TRUE;
#endif

#if defined(__MMI_FTE_SUPPORT__)
    g_system_config.input_device.figner_touch_support = MMI_TRUE;
#endif

#if defined(__MMI_NORMAL_KEYPAD__)
    g_system_config.input_device.keypad_type = MMI_DEVCONFIG_KEYPAD_TYPE_NORMAL;
#endif

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    g_system_config.input_device.keypad_type = MMI_DEVCONFIG_KEYPAD_TYPE_QWERTY;
#endif

#if defined(__MMI_REDUCED_KEYPAD__)
    g_system_config.input_device.keypad_type = MMI_DEVCONFIG_KEYPAD_TYPE_REDUCED;
#endif

    /* Audio API information */
#if defined(BGSND_ENABLE)
    g_system_config.multimedia.audio_bgsnd_support = MMI_TRUE;
#endif

#if defined(__GENERAL_TTS__)
    g_system_config.multimedia.audio_tts_support = MMI_TRUE;
#endif

#if defined(AUDIO_EQUALIZER_ENABLE)
    g_system_config.multimedia.audio_equalizer_support = MMI_TRUE;
#endif

#if defined(AUD_REVERB)
    g_system_config.multimedia.audio_reverb_support = MMI_TRUE;
#endif

#if (defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP))
    g_system_config.multimedia.audio_3d_support = MMI_TRUE;
#endif

#if defined(AUD_TIME_STRETCH)
    g_system_config.multimedia.audio_time_stretch_support = MMI_TRUE;
#endif

#if defined(__BITSTREAM_API_SUPPORT__)
    g_system_config.multimedia.audio_bitstring_support = MMI_TRUE;
#endif

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__)
    g_system_config.multimedia.audio_vocal_removal = MMI_TRUE;
#endif

#if defined(__MMI_AUDIO_PITCH_SHIFTING__)
    g_system_config.multimedia.audio_pitch_shifting = MMI_TRUE;
#endif

#if defined(__BITSTREAM_VIDEO_API_SUPPORT__)
    g_system_config.multimedia.video_bitstring_support = MMI_TRUE;
#endif

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    g_system_config.multimedia.video_play_support = MMI_TRUE;
#endif

#if defined(__VDOPLY_FEATURE_SNAPSHOT__)
    g_system_config.multimedia.video_play_snapshot = MMI_TRUE;
#endif

#if defined(__VDOPLY_FEATURE_VIDEO_ADJUSTMENT__)
    g_system_config.multimedia.video_play_adjustment = MMI_TRUE;
#endif

    /* camera devices information */
#if defined(__MMI_CAMERA__)
   g_system_config.camera_device.camera_support = MMI_TRUE;
#endif

#if defined(__MMI_CAMCORDER__)
    g_system_config.camera_device.camcorder_support = MMI_TRUE;
#endif

#if defined(HORIZONTAL_CAMERA)
    g_system_config.camera_device.horizontal_camera = MMI_TRUE;
#endif

#if defined(DUAL_CAMERA_SUPPORT)
    g_system_config.camera_device.dual_camera = MMI_TRUE;
#endif

#if defined(SENSOR_ROTATE_0)
    g_system_config.camera_device.sensor_rotate = MMI_DEVCONFIG_SENSOR_ROTATE_0;
#endif

#if defined(SENSOR_ROTATE_90)
    g_system_config.camera_device.sensor_rotate = MMI_DEVCONFIG_SENSOR_ROTATE_90;
#endif

#if defined(SENSOR_ROTATE_180)
    g_system_config.camera_device.sensor_rotate = MMI_DEVCONFIG_SENSOR_ROTATE_180;
#endif

#if defined(SENSOR_ROTATE_270)
    g_system_config.camera_device.sensor_rotate = MMI_DEVCONFIG_SENSOR_ROTATE_270;
#endif

    /* graphics jpeg decode */
#if (defined(JPG_DECODE) && defined(__SW_JPEG_CODEC_SUPPORT__))
    g_system_config.graphics_codec.jpg_decode = MMI_DEVCONFIG_GRAPHICS_CODEC_SW;
#endif

#if (defined(JPG_DECODE) && !defined(__SW_JPEG_CODEC_SUPPORT__))
    g_system_config.graphics_codec.jpg_decode = MMI_DEVCONFIG_GRAPHICS_CODEC_HW;
#endif

    /* graphics jpeg encode */
#if (defined(JPG_ENCODE) && defined(__SW_JPEG_CODEC_SUPPORT__))
    g_system_config.graphics_codec.jpg_encode = MMI_DEVCONFIG_GRAPHICS_CODEC_SW;
#endif

#if (defined(JPG_ENCODE) && !defined(__SW_JPEG_CODEC_SUPPORT__))
    g_system_config.graphics_codec.jpg_encode = MMI_DEVCONFIG_GRAPHICS_CODEC_HW;
#endif

    /* graphics gif decode */
#if defined(GIF_DECODE)
    g_system_config.graphics_codec.gif_decode = MMI_DEVCONFIG_GRAPHICS_CODEC_HW;
#else
    g_system_config.graphics_codec.gif_decode = MMI_DEVCONFIG_GRAPHICS_CODEC_SW;
#endif

    /* graphics png decode */
#if (defined(PNG_DECODE) && defined(USE_SW_PNG_DECODER))
    g_system_config.graphics_codec.png_decode = MMI_DEVCONFIG_GRAPHICS_CODEC_SW;
#endif

#if (defined(PNG_DECODE) && defined(USE_HW_PNG_DECODER))
    g_system_config.graphics_codec.png_decode = MMI_DEVCONFIG_GRAPHICS_CODEC_HW;
#endif

#if defined(BROWSER_SUPPORT)    //WAP_SUPPORT
    g_system_config.newwork_protocol.wap_support = MMI_TRUE;
#endif

#if defined(__MMI_MMS_VENDOR_APP_SUPPORT__) //MMS_SUPPORT
    g_system_config.newwork_protocol.mms_support = MMI_TRUE;
#endif

#if defined(__MMI_WLAN_FEATURES__)   //WIFI_SUPPORT
    g_system_config.newwork_protocol.wlan_support = MMI_TRUE;
#endif

#if defined(__GPS_SUPPORT__)   //GPS_SUPPORT
    g_system_config.remote_sensing.gps_support = MMI_TRUE;
#endif

#if defined(__MMI_MOTION_APP__)   //MOTION_SENSOR_SUPPORT
    g_system_config.remote_sensing.motion_sensor = MMI_TRUE;
#endif

#if defined(__NBR_CELL_INFO__)  //nbr cell infor support
    g_system_config.remote_sensing.cell_info_support = MMI_TRUE;
#endif

#ifdef __MMI_PHB_OPTIONAL_FIELD__
    g_system_config.srv_phonebook.phb_option_field = MMI_TRUE;
#if defined(__MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__)
    g_system_config.srv_phonebook.phb_option_2_email = MMI_TRUE;
#endif
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    g_system_config.srv_phonebook.phb_birthday_field = MMI_TRUE;
#endif

#if defined(__MMI_PHB_INFO_FIELD__)
    g_system_config.srv_phonebook.phb_info_field = MMI_TRUE;
#endif

    /* xml and wbxml information */
#if defined(__XML_SUPPORT__)
    g_system_config.xml_wbxml.xml_parser = MMI_TRUE;
    g_system_config.xml_wbxml.xml_generator = MMI_TRUE;
#endif

#if defined(__WBXML_SUPPORT__)
    g_system_config.xml_wbxml.wbxml_parser = MMI_TRUE;
    g_system_config.xml_wbxml.wbxml_generator = MMI_TRUE;
#endif

    /* gdi feature information */
#if defined(GDI_6_LAYERS)
    g_system_config.gdi_info.gdi_6_layer = MMI_TRUE;
#endif

#if defined(GDI_USING_LAYER_ROTATE)
    g_system_config.gdi_info.gdi_layer_rotate = MMI_TRUE;
#endif

    /* return the system config context to customer's struct */
    if(NULL != p_sys_config)
    {
        memcpy((void *)p_sys_config, (const void *)&g_system_config, sizeof(mmi_devconfig_system_config_struct));
    }
    return;
}
