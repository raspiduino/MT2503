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
 *  mdi_common.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MDI (Media Device Interface) common functions
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_include.h"
#include "FileMgrSrvGProt.h"

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_include.h"
#include "mdi_audio.h"          /* audio */


#include "app_datetime.h"

#if defined(__MMI_SWFLASH__)
#include "mdi_swflash.h"
#endif 

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__)|| defined(__MMI_CAMCORDER__) 
#include "mdi_video.h"          /* video */
#endif 
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) 
#include "mdi_camera.h"         /* camera */
#endif 
#include "lcd_if.h"             /* lcd interface */

#ifdef __MMI_WEBCAM__
#include "mdi_webcam.h"
#endif

#if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
#include "mdi_mtv.h"
#endif

#include "iul_csc_y2r_565.h"
#include "iul_color_convert.h"

#if defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)
#include "mdi_gps.h"
#endif  /* defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__)  */


// #ifdef __MMI_TARGET__
#include "med_api.h"    /* media task */
#include "med_main.h"   /* media task */
#include "med_struct.h" /* media task */
// #endif /* __MMI_TARGET__ */
#include "med_utility.h"
#include "mm_comm_def.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "gdi_features.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "fs_type.h"
#include "kal_public_api.h"
#include "DateTimeType.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "gdi_datatype.h"
#include "string.h"
#include "gdi_include.h"
#include "drv_features.h"
#include "gdi_const.h"
#include "SensorSrvGport.h"
#include "mmi_rp_srv_mdi_def.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "gui_data_types.h"
#include "gui.h"
#include "gui_themes.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "wgui_inputs.h"
#include "gui_inputs.h"
#include "wgui_categories_inputs.h"
#include "kal_active_module.h"
//#include "jpeg_mem_int.h"
#include "gdi_util.h"
#include "kal_public_api.h"
#include "mdi_camera.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    module_type mod_id;
    MMI_BOOL is_init;
    
} mdi_cnxt_struct;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
mdi_hw_layer_struct g_mdi_hw_layer_array[GDI_LAYER_LAYER_COUNT];

/***************************************************************************** 
* Global Function
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/
mdi_cnxt_struct g_mdi_cntx = 
{
    MOD_MMI,        /* mod_id */
    MMI_FALSE       /* is_init */
};


/*****************************************************************************
 * FUNCTION
 *  mdi_get_ucs2_filename
 * DESCRIPTION
 *
 * PARAMETERS
 *  filename      [OUT]         Filename: 
 *  length        [IN]          buffer length, should >= (SRV_FMGR_PATH_MAX_LEN+1)
 *  filepath      [IN]          File path.
 *  type          [IN]          File naming type
 *  ext           [IN]          File extension
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_get_ucs2_filename(PS8 p_filename, S32 length, PS8 p_filepath, mdi_naming_type_enum type, mmi_fmgr_filetype_enum ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 filename[(SRV_FMGR_PATH_MAX_LEN+1)], full_path[(SRV_FMGR_PATH_MAX_LEN+1)];
    U16 file_ext[10];
    applib_time_struct currentDateTime;
    FS_HANDLE file_handle;
    U16 filename_seq_no = 0;
    U16 str_length;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(length >= (SRV_FMGR_PATH_MAX_LEN+1));

    DTGetRTCTime(&currentDateTime);

    switch(type)
    {
        case MDI_NAMING_TYPE_DDMMYY_HHMM:
        default :
            kal_wsprintf(filename, 
                        "%02d%02d%02d-%02d%02d", 
                        currentDateTime.nDay,
                        currentDateTime.nMonth,
                        (currentDateTime.nYear)%100,
                        currentDateTime.nHour,
                        currentDateTime.nMin);
        break;
    }

    switch (ext)
    {
        case FMGR_TYPE_3GP:
        case FMGR_TYPE_MP4:
        mmi_ucs2cpy((PS8)file_ext,(PS8)L".3gp");
        break;

        case FMGR_TYPE_AVI:
        mmi_ucs2cpy((PS8)file_ext,(PS8)L".avi");
        break;
            
        case FMGR_TYPE_JPG:
        case FMGR_TYPE_JPEG:
        default :
        mmi_ucs2cpy((PS8)file_ext,(PS8)L".jpg");
        break;
    }

    mmi_ucs2ncpy((PS8)full_path,p_filepath,(SRV_FMGR_PATH_MAX_LEN+1));   
    mmi_ucs2cat((PS8)full_path,(PS8)filename);
    mmi_ucs2cat((PS8)full_path, (PS8)file_ext);

    str_length = mmi_ucs2strlen(p_filepath) + mmi_ucs2strlen((PS8)filename) + mmi_ucs2strlen((PS8)file_ext);
    ASSERT(str_length < (SRV_FMGR_PATH_MAX_LEN+1));
    
    file_handle = FS_Open((U16*) full_path, FS_READ_ONLY);

    /* If file exists */
    while(file_handle >= FS_NO_ERROR)
    {
        U16 buffer[10];
        FS_Close(file_handle);

        filename_seq_no++;
        if (filename_seq_no > 999) /* more than 4 digits */
        {
            mmi_ucs2ncpy((PS8)full_path,p_filepath,(SRV_FMGR_PATH_MAX_LEN+1));   
            mmi_ucs2cat((PS8)full_path, (PS8)filename);
            mmi_ucs2cat((PS8)full_path, (PS8)file_ext);
            break;
        }
        kal_wsprintf(buffer,"(%03d)",filename_seq_no);

        if (str_length + mmi_ucs2strlen((PS8)buffer) > (SRV_FMGR_PATH_MAX_LEN+1))
            ASSERT(0);

        mmi_ucs2ncpy((PS8)full_path,p_filepath,(SRV_FMGR_PATH_MAX_LEN+1));   
        mmi_ucs2cat((PS8)full_path, (PS8)filename);
        mmi_ucs2cat((PS8)full_path, (PS8)buffer);
        mmi_ucs2cat((PS8)full_path, (PS8)file_ext);

        file_handle = FS_Open((U16*) full_path, FS_READ_ONLY);
    };
    
    mmi_ucs2cpy(p_filename,(PS8)full_path);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_switch_device_ownership
 * DESCRIPTION
 *  This function is used for multiple tasks to get owner shipof multimedia device,
 *  such as audio, camera and video, etc.
 *  The previous action on this device will be forced to terminate.
 * PARAMETERS
 *  mod_id      [IN]        Owner, one of MOD_MMI, MOD_J2ME, etc
 *  device      [IN]        Device
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_switch_device_ownership(module_type mod_id, MDI_DEVICE_TYPE device)
{
}


/*****************************************************************************
 * FUNCTION
 *  mdi_check_device_ownership
 * DESCRIPTION
 *  check current device ownership
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_check_device_ownership()
{
    /* No Need to check since no task will switch MDI ownership */
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_calc_blt_para()
 * DESCRIPTION
 *  Calculate blt parameters for camera / video / vcall
 * PARAMETERS
 *  disp_layer_handle   [IN]    display layer
 *  lcd_rotate          [IN]    lcd rotate value
 *  lcd id              [IN]    lcd id (using GDI_LCD_XXX_LCD_HANDLE)
 *  is_tvout            [IN]    tvout enable or not
 *  blt_data_p          [OUT]   blt parameters
 * RETURNS
 * BOOL
 *****************************************************************************/
void mdi_calc_blt_para(
    gdi_handle disp_layer_handle, 
    U16 lcd_rotate, 
    gdi_handle lcd_handle,    
    MMI_BOOL is_tvout,
    mdi_blt_para_struct *blt_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width;
    S32 layer_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 lcd_offset_x;
    S32 lcd_offset_y;
    S32 lcd_start_x;
    S32 lcd_start_y;
    S32 lcd_end_x;
    S32 lcd_end_y;
    S32 clip_x1;
    S32 clip_y1;    
    S32 clip_x2;
    S32 clip_y2;    
    S32 lcd_width;
    S32 lcd_height;
    U8 *buf_ptr;
    U8 *buf_ptr2;
    U8 layer_rotate;
    gdi_color_format color_format;
    gdi_handle prev_lcd_handle;
    U8 cur_lcd_rotate;
    S32 lcd_clip_x1;
    S32 lcd_clip_y1;    
    S32 lcd_clip_x2;        
    S32 lcd_clip_y2;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)blt_data_p, 0, sizeof(mdi_blt_para_struct));

    if (disp_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        /* null layer handle */
        return;
    }
        
    gdi_lcd_get_active(&prev_lcd_handle);
    gdi_lcd_set_active(lcd_handle);
    cur_lcd_rotate = gdi_lcd_get_rotate();

    if (cur_lcd_rotate == GDI_LAYER_ROTATE_0 || 
        cur_lcd_rotate == GDI_LAYER_ROTATE_0_MIRROR || 
        cur_lcd_rotate == GDI_LAYER_ROTATE_180 ||
        cur_lcd_rotate == GDI_LAYER_ROTATE_180_MIRROR)
    {
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    }        
    else
    {
        gdi_lcd_get_dimension(&lcd_height, &lcd_width);
    }

    gdi_lcd_set_active(prev_lcd_handle);

    /* get disp layer's paramters */
    gdi_layer_push_and_set_active(disp_layer_handle);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    gdi_layer_get_color_format(&color_format);
    layer_rotate = gdi_layer_get_rotate();    


    if (gdi_layer_is_double(disp_layer_handle))
    {
        gdi_layer_toggle_double();
        gdi_layer_get_buffer_ptr(&buf_ptr2);
    }
    else
    {
        buf_ptr2 = buf_ptr;
    }

    gdi_layer_pop_and_restore_active();

    /* transform the coordinate to phiscal LCD's coordinate */
    if ((lcd_rotate == MDI_LCD_ROTATE_270) || 
        (lcd_rotate == MDI_LCD_ROTATE_270_MIRROR))
    {
        lcd_offset_x = lcd_width - layer_offset_y - layer_height;
        lcd_offset_y = layer_offset_x;
    }
    else if ((lcd_rotate == MDI_LCD_ROTATE_90) || 
             (lcd_rotate == MDI_LCD_ROTATE_90_MIRROR))
    {
        lcd_offset_x = layer_offset_y;
        lcd_offset_y = lcd_height - layer_offset_x - layer_width;
    }
    else
    {
    #if defined(GDI_USING_LAYER_ROTATE)
        if (layer_rotate == MDI_LCD_ROTATE_90)
        {
            lcd_offset_x = lcd_width - layer_offset_y - layer_height;
            lcd_offset_y = layer_offset_x;
        }
        else
    #endif /* defined(GDI_USING_LAYER_ROTATE) */ 
        {
            lcd_offset_x = layer_offset_x;
            lcd_offset_y = layer_offset_y;
        }
    }

    lcd_start_x = lcd_offset_x;
    lcd_start_y = lcd_offset_y;

    /* if rotate 90 or 270 degree */
    if ((lcd_rotate == GDI_LAYER_ROTATE_90) || 
        (lcd_rotate == GDI_LAYER_ROTATE_90_MIRROR) ||
        (lcd_rotate == GDI_LAYER_ROTATE_270) || 
        (lcd_rotate == GDI_LAYER_ROTATE_270_MIRROR))
    {
        lcd_end_x = lcd_offset_x + layer_height - 1;
        lcd_end_y = lcd_offset_y + layer_width - 1;
    }
    else
    {
        lcd_end_x = lcd_offset_x + layer_width - 1;
        lcd_end_y = lcd_offset_y + layer_height - 1;
    }

    /* change clip from layer to lcd coord */
    if (MDI_LCD_ROTATE_90 == layer_rotate)
    {
        lcd_clip_x1 = layer_height - clip_y2 - 1;
        lcd_clip_x2 = layer_height - clip_y1 - 1;
        lcd_clip_y1 = clip_x1;
        lcd_clip_y2 = clip_x2;

        /* fit into clip */
        lcd_start_x += lcd_clip_x1;
        lcd_start_y += lcd_clip_y1; 
        lcd_end_x -= (layer_height - lcd_clip_x2 - 1); 
        lcd_end_y -= (layer_width - lcd_clip_y2 - 1);         
    }
    else if (MDI_LCD_ROTATE_180 == layer_rotate)
    {
        lcd_clip_x1 = layer_width - clip_x2 - 1;
        lcd_clip_x2 = layer_width - clip_x1 - 1;
        lcd_clip_y1 = layer_height - clip_y2 - 1;
        lcd_clip_y2 = layer_height - clip_y1 - 1;

        /* fit into clip */
        lcd_start_x += lcd_clip_x1;
        lcd_start_y += lcd_clip_y1; 
        lcd_end_x -= (layer_width - lcd_clip_x2 - 1); 
        lcd_end_y -= (layer_height - lcd_clip_y2 - 1);         
    }
    else if (MDI_LCD_ROTATE_270 == layer_rotate)
    {
        lcd_clip_x1 = clip_y1;
        lcd_clip_x2 = clip_y2;
        lcd_clip_y1 = layer_width - clip_x2 - 1;
        lcd_clip_y2 = layer_width - clip_x1 - 1;

        /* fit into clip */
        lcd_start_x += lcd_clip_x1;
        lcd_start_y += lcd_clip_y1; 
        lcd_end_x -= (layer_height - lcd_clip_x2 - 1); 
        lcd_end_y -= (layer_width - lcd_clip_y2 - 1);         
    }
    else
    {
        lcd_clip_x1 = clip_x1;
        lcd_clip_x2 = clip_x2;
        lcd_clip_y1 = clip_y1;
        lcd_clip_y2 = clip_y2;

        /* fit into clip */
        lcd_start_x += lcd_clip_x1;
        lcd_start_y += lcd_clip_y1; 
        lcd_end_x -= (layer_width - lcd_clip_x2 - 1); 
        lcd_end_y -= (layer_height - lcd_clip_y2 - 1);         
   }

    /* check if lcd position valid */
    if (lcd_start_x > lcd_width - 1 ||
        lcd_start_y > lcd_height - 1 ||
        lcd_end_x < 0 ||
        lcd_end_y < 0)
    {
        blt_data_p->is_visual_update = MMI_FALSE;
    }
    else 
    {
        blt_data_p->is_visual_update = MMI_TRUE;
    }

    /* force inside lcd region */
    if (lcd_start_x < 0)
    {
        lcd_start_x = 0;
    }
    else if (lcd_start_x > lcd_width - 1)
    {
        lcd_start_x = lcd_width - 1;
    }

    if (lcd_start_y < 0)
    {
        lcd_start_y = 0;
    }
    else if (lcd_start_y > lcd_height - 1)
    {
        lcd_start_y = lcd_height - 1;
    }

    if (lcd_end_x < 0)
    {
        lcd_end_x = 0;
    }
    else if (lcd_end_x > lcd_width - 1)
    {
        lcd_end_x = lcd_width - 1;
    }

    if (lcd_end_y < 0)
    {
        lcd_end_y = 0;
    }
    else if (lcd_end_y > lcd_height - 1)
    {
        lcd_end_y = lcd_height - 1;
    }

    blt_data_p->lcd_start_x = lcd_start_x;
    blt_data_p->lcd_start_y = lcd_start_y;
    blt_data_p->lcd_end_x = lcd_end_x;
    blt_data_p->lcd_end_y = lcd_end_y;
    blt_data_p->display_width = layer_width;
    blt_data_p->display_height = layer_height;
    blt_data_p->image_color_format = color_format;

    if (gdi_lcd_get_rotate_by_layer())
    {
        /* if using LCD rotate, the roi region will be the phisical potion as lcd */
        blt_data_p->roi_offset_x = GDI_LAYER_OFFSET + lcd_offset_x;
        blt_data_p->roi_offset_y = GDI_LAYER_OFFSET + lcd_offset_y;
    }
    else
    {
        /* if using LCM rotate, layers are rotated, so the position is the same as layer pos */
        blt_data_p->roi_offset_x = GDI_LAYER_OFFSET + layer_offset_x;
        blt_data_p->roi_offset_y = GDI_LAYER_OFFSET + layer_offset_y;
    }

    /* fit into clip */
    blt_data_p->roi_offset_x += lcd_clip_x1;
    blt_data_p->roi_offset_y += lcd_clip_y1; 

    /* force roi inside lcd region */
    if (blt_data_p->roi_offset_x < GDI_LAYER_OFFSET)
    {
        blt_data_p->roi_offset_x = GDI_LAYER_OFFSET;
    }
    else if (blt_data_p->roi_offset_x > GDI_LAYER_OFFSET + lcd_width - 1)
    {
        blt_data_p->roi_offset_x = GDI_LAYER_OFFSET + lcd_width - 1;
    }

    if (blt_data_p->roi_offset_y < GDI_LAYER_OFFSET)
    {
        blt_data_p->roi_offset_y = GDI_LAYER_OFFSET;
    }
    else if (blt_data_p->roi_offset_y > GDI_LAYER_OFFSET + lcd_height - 1)
    {
        blt_data_p->roi_offset_y = GDI_LAYER_OFFSET + lcd_height - 1;
    }

    blt_data_p->image_buffer_p = (void*)buf_ptr;
    blt_data_p->image_buffer_p_2 = (void*)buf_ptr2;
    blt_data_p->image_buffer_size = (layer_width * layer_height * GDI_LAYER.act_bit_per_pixel) >> 3;
    blt_data_p->lcd_rotate = lcd_rotate;
    blt_data_p->tv_output = MMI_FALSE;

    /* TV out */
#ifdef __MMI_TVOUT__
    if (is_tvout && blt_data_p->is_visual_update)
    {
        S32 ret;
        
        ret = mdi_tvout_get_para(
                MDI_TV_OWNER_VIDEO,
                (PU16)&blt_data_p->tv_output_mode,              /* mode_ptr */
                (PU16)&blt_data_p->tv_output_width,             /* buf_width_ptr */
                (PU16)&blt_data_p->tv_output_height,            /* buf_height_ptr */
                (PU32)&blt_data_p->tv_output_buffer_size,       /* buf size */
                (PU8*)&blt_data_p->tv_output_buffer1_address,   /* buf1 pp */
                (PU8*)&blt_data_p->tv_output_buffer2_address,   /* buf2 pp */
                NULL,                                           /* rotate_buf_1_pp */
                NULL);                                          /* rotate_buf_2_pp */

        if (ret == MDI_RES_TV_ENABLE)
        {
            blt_data_p->tv_output = TRUE;
            blt_data_p->tv_output_offset_x = blt_data_p->roi_offset_x - GDI_LAYER_OFFSET;
            blt_data_p->tv_output_offset_y = blt_data_p->roi_offset_y - GDI_LAYER_OFFSET;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

#endif /* __MMI_TVOUT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_rotate_osd_for_hw_rotator
 * DESCRIPTION
 *  Rotate OSD if we have HW rotator in IDP or LCD
 *  (only supported when src/dst are same size but only 90 degree rotated)
 * PARAMETERS
 *  src_handle    [IN]  srource layer handle
 *  dst_handle    [IN]  destination layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_util_rotate_osd_for_hw_rotator(gdi_handle src_handle, gdi_handle dst_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 src_width, src_height;
    U8 *dst_p, *src_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(src_handle);
    gdi_layer_get_dimension(&src_width, &src_height);
    gdi_layer_get_buffer_ptr(&src_p);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(dst_handle);
    gdi_layer_get_buffer_ptr(&dst_p);
    gdi_layer_pop_and_restore_active();

    mdi_util_rotate_osd_partial_region_for_hw_rotator(src_handle, 0, 0, src_width, src_height, dst_handle);


}

    
/*****************************************************************************
 * FUNCTION
 *  mdi_util_rotate_osd_partial_region_for_hw_rotator
 * DESCRIPTION
 *  Rotate OSD if we have HW rotator in IDP or LCD
 *  (only supported when src/dst are same size but only 90 degree rotated)
 * PARAMETERS
 *  src_handle    [IN]  srource layer handle
 *  dst_handle    [IN]  destination layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_util_rotate_osd_partial_region_for_hw_rotator(
    gdi_handle src_handle, 
    S32 offset_x, 
    S32 offset_y, 
    S32 width, 
    S32 height, 
    gdi_handle dst_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *src_ptr, *dst_ptr;
    S32 src_width, src_height;
    S32 dst_width, dst_height;
    U8 rotate_angle;   
    gdi_color_format src_color_format = 0, dst_color_format = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(src_handle);
    gdi_layer_get_dimension(&src_width, &src_height);
    gdi_layer_get_buffer_ptr(&src_ptr);
    gdi_layer_get_color_format(&src_color_format);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(dst_handle);
    gdi_layer_get_dimension(&dst_width, &dst_height);
    gdi_layer_get_buffer_ptr(&dst_ptr);
    gdi_layer_get_color_format(&dst_color_format);
    gdi_layer_pop_and_restore_active();
    
    rotate_angle = GDI_LAYER_ROTATE_90; 

    gdi_util_rotator(
        GDI_ROTATOR_DEFAULT, 
        rotate_angle, 
        src_ptr, 
        src_color_format,
        src_width,
        src_height,
        offset_x,
        offset_y,
        width,
        height,
        dst_ptr,
        dst_color_format,
        dst_width,
        dst_height,
        src_height - offset_y - height,
        offset_x,
        height,
        width);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_rotate_layer_partial_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_handle    [IN]  srource layer handle
 *  dst_handle    [IN]  destination layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_util_rotate_layer_partial_region(
    gdi_handle src_handle, 
    S32 offset_x, 
    S32 offset_y, 
    S32 width, 
    S32 height, 
    gdi_handle dst_handle,   
    U8 rotate_angle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *src_ptr, *dst_ptr;
    S32 src_width, src_height;
    S32 dst_width, dst_height;   
    gdi_color_format src_color_format = 0, dst_color_format = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(src_handle);
    gdi_layer_get_dimension(&src_width, &src_height);
    gdi_layer_get_buffer_ptr(&src_ptr);
    gdi_layer_get_color_format(&src_color_format);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(dst_handle);
    gdi_layer_get_dimension(&dst_width, &dst_height);
    gdi_layer_get_buffer_ptr(&dst_ptr);
    gdi_layer_get_color_format(&dst_color_format);
    gdi_layer_pop_and_restore_active();

    gdi_util_rotator(
        GDI_ROTATOR_DEFAULT, 
        rotate_angle, 
        src_ptr, 
        src_color_format,
        src_width,
        src_height,
        offset_x,
        offset_y,
        width,
        height,
        dst_ptr,
        dst_color_format,
        dst_width,
        dst_height,
        src_height - offset_y - height,
        offset_x,
        dst_width,
        dst_height);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_message_dispatcher()
 * DESCRIPTION
 *  Message dispatcher of MDI library.
 *  This function my be added to the message handler of other task (ex: Java)
 *  Therefore, the asyn callback will be called under caller's context.
 *  [Example] 
 *  if Java called mdi_video_ply_open, the open result callback will be called 
 *  under Java's context if Java put this message dispatcher in its message handler
 * PARAMETERS
 *  ilm_ptr             [IN]    ilm pointer
 * RETURNS
 *  MDI consume the message or not 
 * RETURN VALUE LIST
 *  MMI_TRUE        MDI consume this message
 *  MMI_FALSE       MDI didnt consume this message
 *****************************************************************************/
MMI_BOOL mdi_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mdi_audio_message_dispatcher(ilm_ptr))
    {
        return MMI_TRUE;
    }
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__)    
    else if(mdi_video_message_dispatcher(ilm_ptr))
    {
        return MMI_TRUE;
    }
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__)  */
#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
    else if(mdi_gps_uart_message_dispatcher(ilm_ptr))
    {
        return MMI_TRUE;
    }
#endif /* defined(__GPS_SUPPORT__)||defined(__BT_GPS_SUPPORT__) */    
  
 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_get_mdi_error_info
 * DESCRIPTION
 *  Display center hint string
 * PARAMETERS
 * error_code   [INPUT] error code got from MDI APIs
 * popup_type   [OUTPUT] popup_type of this error_code 
 * RETURNS
 *  MMI_ID_TYPE string_id
 *****************************************************************************/
MMI_ID_TYPE mdi_util_get_mdi_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = STR_ID_MDI_COMMON_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;

    if (error_code <= -9000 && error_code >= -9999)
    {
        return mdi_audio_get_error_info(error_code, popup_type);
    }
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    if (error_code <= -1000 && error_code >= -1499)
    {
        return mdi_camera_get_error_info(error_code, popup_type);
    }
#endif /* defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) */
#ifdef __MMI_WEBCAM__
    if (error_code <= -1500 && error_code >= -1999)
    {
        return mdi_webcam_get_error_info(error_code, popup_type);
    }    
#endif /* __MMI_WEBCAM__ */
#if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
    if (error_code <= -2000 && error_code > -3000)
    {
        return mdi_video_rec_get_error_info(error_code, popup_type);
    }

#endif /* defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__) */

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
    if (error_code <= -3000 && error_code > -4000)
    {
        return mdi_video_ply_get_error_info(error_code, popup_type);
    }
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) */

#if defined(__MMI_SWFLASH__)	
	if(error_code <= -4000 && error_code >= -4999)	
	{
		return mdi_swflash_get_mdi_error_info(error_code, popup_type);
	}
#endif
#if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    if (error_code <= -6000 && error_code > -7000)
    {
        return mdi_mtv_get_error_info(error_code, popup_type);
    }
#endif /* (__MMI_ATV_SUPPORT__) || (__MMI_MOBILE_TV_CMMB_SUPPORT__) */

#if defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__)
    if (error_code <= -7001 && error_code > -7100)
    {
        return mdi_gps_get_mdi_error_info(error_code, popup_type);
    }
#endif /* defined(__GPS_SUPPORT__) || defined(__BT_GPS_SUPPORT__) */

#if 0
#ifdef MOTION_SENSOR_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MOTION_SENSOR_SUPPORT */
#endif

    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_convert_color_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 *****************************************************************************/
MMI_BOOL mdi_util_convert_color_format(gdi_handle layer_handle, U32 src_format, U32 dst_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* buf_ptr;
    S32 layer_width, layer_height;
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_UTIL_CONVERT_COLOR_FORMAT, layer_handle, src_format, dst_format);   
    /* Get buffer pointer, width, height */
    gdi_layer_push_and_set_active(layer_handle);    
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_pop_and_restore_active();
    
    if (src_format == GDI_COLOR_FORMAT_UYVY422 &&  /* 6 */
        dst_format == GDI_COLOR_FORMAT_16)         /* 2 */
    {
        ret = iul_csc_uyvy422_to_rgb565_fxp_dithering(
                    buf_ptr, buf_ptr, layer_width, layer_height);
    }
    else if (src_format == GDI_COLOR_FORMAT_16 &&      /* 2 */
             dst_format == GDI_COLOR_FORMAT_UYVY422)   /* 6 */
    {        
        ret = iul_rgb565_to_uyvy422_interleave(
                    buf_ptr, buf_ptr, layer_width, layer_height);
    }
    else
    {
        ASSERT(0);
    }    
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VIDEO_MEDIA_RET, ret); 
    if (ret == 1)
    {
        return MMI_TRUE;
    }
    else
    {        
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_show_not_available_in_call_hint()
 * DESCRIPTION
 *  Display center hint string
 * PARAMETERS
 *  layer_handle        [INPUT]     display layer handle
 *  offset_x            [INPUT]     display region offset x
 *  offset_y            [INPUT]     display region offset y
 *  width               [INPUT]     display region width
 *  height              [INPUT]     display region height
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_util_show_not_available_in_call_hint(gdi_handle layer_handle, S32 offset_x, S32 offset_y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width = 0;
    S32 str_height = 0;
    S32 layer_width = 0;
    S32 layer_height = 0;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 str_offset_x;
    S32 str_offset_y;    
    S32 str_len = 0;
    S32 line_height;
    S8 *str_ptr = NULL;
    gdi_color bg_color = GDI_COLOR_BLACK;
    color text_color = gui_color(255, 255, 255);  
    color border_color = gui_color(0, 0, 0);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (layer_handle == NULL)
    {
        return;
    }
    gui_set_font(&MMI_medium_font);
    
    str_ptr = GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);
    
    gui_measure_string((UI_string_type)str_ptr, &str_width, &str_height);

    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    gui_set_text_color(text_color);
    gui_set_text_border_color(border_color);
    gdi_draw_solid_rect(
        offset_x , 
        offset_y ,
        offset_x + width - 1, 
        offset_y + height - 1,
        bg_color);
    
    if (str_width > width)
    {
        str_len = mmi_ucs2strlen((S8*) str_ptr);

        create_multiline_inputbox_set_buffer((UI_string_type)str_ptr, str_len, str_len, 0);
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
            | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY
            | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
            | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;

        MMI_multiline_inputbox.text_font = &MMI_medium_font;
        MMI_multiline_inputbox.normal_text_color = text_color;
        MMI_multiline_inputbox.border_color = border_color;

        resize_multiline_inputbox(width, height);
        move_multiline_inputbox(offset_x + layer_offset_x, offset_y + layer_offset_y);

        /* vertical center alignment */
        show_multiline_inputbox_no_draw();
        line_height = get_multiline_inputbox_line_height();
        resize_multiline_inputbox(
            width,
            (MMI_multiline_inputbox.n_lines * line_height) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y);
        move_multiline_inputbox(
            0,
            offset_y + ((height - MMI_multiline_inputbox.height) >> 1));

        show_multiline_inputbox();        

    }
    else
    {
        str_offset_x = ((width - str_width) >> 1) + offset_x;
        str_offset_y = ((height - str_height) >> 1) + offset_y;

        gui_move_text_cursor(str_offset_x, str_offset_y);         
        gui_print_text((UI_string_type)str_ptr); 
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_hw_layer_create
 * DESCRIPTION
 *  Create HW layer by using app asm memory
 * PARAMETERS
 *  in_p        [IN]     
 *  out_p       [IN]     
 * RETURNS
 *  layer handle
 *****************************************************************************/
gdi_handle mdi_util_hw_layer_create(mdi_util_create_hw_layer_in_struct* in_p, mdi_util_create_hw_layer_out_struct* out_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer_handle = NULL;
    U8* buffer = NULL;
    S32 buffer_size = 0; 
    gdi_layer_struct *layer_ptr;
    U16 width;
    U16 height;
    U16 factor = 2;
    gdi_color_format cf = GDI_COLOR_FORMAT_16;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_p->width == 0 || in_p->height == 0)
    {
        MMI_ASSERT(0);
    }
    
    width = (in_p->width >> 1) << 1;
    height = (in_p->height >> 1) << 1;

    width = ((width > 0) ? width : 2);
    height = ((height > 0) ? height : 2);

    if (in_p->scenario_id == MDI_MULTIMEDIA_SUBTITLE && 
        (in_p->color_format == GDI_COLOR_FORMAT_32 || 
        in_p->color_format == GDI_COLOR_FORMAT_32_PARGB))
    {
        factor = 4;   
        cf = in_p->color_format;
    }
    
    buffer_size = width * height * factor;
    
#ifdef __MED_IN_ASM__   
    buffer = (U8*)applib_asm_alloc_nc_r(in_p->app_id, buffer_size);
#else
    media_get_ext_buffer_framebuffer(
        stack_get_active_module_id(),
        (void**)&buffer,
        (U32)buffer_size);
#endif

    if (!buffer)
        return NULL;

    out_p->result = gdi_layer_create_cf_using_outside_memory(
                        cf,
                        in_p->offset_x, 
                        in_p->offset_y, 
                        width, 
                        height,
                        &layer_handle, 
                        buffer, 
                        buffer_size);
    
    out_p->offset_x = in_p->offset_x;
    out_p->offset_y = in_p->offset_y;
    out_p->width = width;
    out_p->height = height;

    if (layer_handle)
    {
        gdi_layer_set_hw_update_layer(layer_handle, KAL_FALSE);
        
        layer_ptr = (gdi_layer_struct*)layer_handle;
        g_mdi_hw_layer_array[layer_ptr->id].scenario_id = in_p->scenario_id;
        g_mdi_hw_layer_array[layer_ptr->id].layer_handle = layer_handle;
        g_mdi_hw_layer_array[layer_ptr->id].app_id = in_p->app_id;
        g_mdi_hw_layer_array[layer_ptr->id].is_allocated = MMI_TRUE;

        gdi_layer_push_and_set_active(layer_handle);
    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
        if (in_p->scenario_id != MDI_MULTIMEDIA_SUBTITLE)
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
    #endif
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
    #ifdef __COSMOS_MMI__     
        applib_asm_free_r(in_p->app_id, buffer);
    #else
        media_free_ext_buffer(stack_get_active_module_id(), (void**)&buffer);
    #endif       
    }
    
    return layer_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_hw_layer_create_with_extmemory
 * DESCRIPTION
 *  Create HW layer by using external memory
 * PARAMETERS
 *  in_p        [IN]     
 *  out_p       [IN]     
 * RETURNS
 *  layer handle
 *****************************************************************************/
gdi_handle mdi_util_hw_layer_create_with_extmemory(mdi_util_create_hw_layer_extmemory_in_struct* in_p, mdi_util_create_hw_layer_out_struct* out_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer_handle = NULL;
    S32 buffer_size = 0; 
    gdi_layer_struct *layer_ptr;
    U16 width;
    U16 height;
    U16 factor = 2;
    gdi_color_format cf = GDI_COLOR_FORMAT_16;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_p->width == 0 || in_p->height == 0)
    {
        MMI_ASSERT(0);
    }
    
    width = (in_p->width >> 1) << 1;
    height = (in_p->height >> 1) << 1;

    width = ((width > 0) ? width : 2);
    height = ((height > 0) ? height : 2);

    if (in_p->scenario_id == MDI_MULTIMEDIA_SUBTITLE && 
        (in_p->color_format == GDI_COLOR_FORMAT_32 || 
        in_p->color_format == GDI_COLOR_FORMAT_32_PARGB))
    {
        factor = 4;  
        cf = in_p->color_format;
    }
    
    buffer_size = width * height * factor;

    if (!in_p->buffer || buffer_size > in_p->buffer_size)
        return NULL;
    
    out_p->result = gdi_layer_create_cf_using_outside_memory(
                        cf,
                        in_p->offset_x, 
                        in_p->offset_y, 
                        width, 
                        height,
                        &layer_handle, 
                        in_p->buffer, 
                        buffer_size);
    
    out_p->offset_x = in_p->offset_x;
    out_p->offset_y = in_p->offset_y;
    out_p->width = width;
    out_p->height = height;

    if (layer_handle)
    {
        gdi_layer_set_hw_update_layer(layer_handle, KAL_FALSE);
        
        layer_ptr = (gdi_layer_struct*)layer_handle;
        g_mdi_hw_layer_array[layer_ptr->id].scenario_id = in_p->scenario_id;
        g_mdi_hw_layer_array[layer_ptr->id].layer_handle = layer_handle;
        g_mdi_hw_layer_array[layer_ptr->id].app_id = 0;

        gdi_layer_push_and_set_active(layer_handle);
    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
        if (in_p->scenario_id != MDI_MULTIMEDIA_SUBTITLE)
            gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
    #endif
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    
    return layer_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_hw_layer_create_with_intmemory
 * DESCRIPTION
 *  Create HW layer by using GDI internal memory
 * PARAMETERS
 *  in_p        [IN]     
 *  out_p       [IN]     
 * RETURNS
 *  layer handle
 *****************************************************************************/
gdi_handle mdi_util_hw_layer_create_with_intmemory(mdi_util_create_hw_layer_intmemory_in_struct* in_p, mdi_util_create_hw_layer_out_struct* out_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle layer_handle = NULL;
    gdi_layer_struct *layer_ptr;
    U16 width;
    U16 height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_p->width == 0 || in_p->height == 0)
    {
        MMI_ASSERT(0);
    }
    
    width = (in_p->width >> 1) << 1;
    height = (in_p->height >> 1) << 1;

    width = ((width > 0) ? width : 2);
    height = ((height > 0) ? height : 2);
    
    out_p->result = gdi_layer_create_cf(
                        GDI_COLOR_FORMAT_16,
                        in_p->offset_x, 
                        in_p->offset_y, 
                        width, 
                        height,
                        &layer_handle);
    
    out_p->offset_x = in_p->offset_x;
    out_p->offset_y = in_p->offset_y;
    out_p->width = width;
    out_p->height = height;

    if (layer_handle)
    {
        gdi_layer_set_hw_update_layer(layer_handle, KAL_FALSE);
        
        layer_ptr = (gdi_layer_struct*)layer_handle;
        g_mdi_hw_layer_array[layer_ptr->id].scenario_id = in_p->scenario_id;
        g_mdi_hw_layer_array[layer_ptr->id].layer_handle = layer_handle;
        g_mdi_hw_layer_array[layer_ptr->id].app_id = 0;

        gdi_layer_push_and_set_active(layer_handle);
    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
    #endif
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    
    return layer_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_hw_layer_free
 * DESCRIPTION
 *  Create HW layer
 * PARAMETERS
 *  layer_handle        [IN]         
 * RETURNS
 *  layer handle
 *****************************************************************************/
void mdi_util_hw_layer_free(gdi_handle layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* buffer1 = NULL;
    U8* buffer2 = NULL;
    U8* buffer = NULL;
    gdi_layer_struct *layer_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!layer_handle)
        return;
    
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_buffer_ptr(&buffer1);
    if (gdi_layer_is_double(layer_handle))
    {
        gdi_layer_toggle_double();
        gdi_layer_get_buffer_ptr(&buffer2);

        buffer = MIN(buffer1, buffer2);
    }
    else
        buffer = buffer1;
    
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_free(layer_handle);

    layer_ptr = (gdi_layer_struct*)layer_handle;

    if (g_mdi_hw_layer_array[layer_ptr->id].is_allocated)
    {
    #ifdef __COSMOS_MMI__     
        applib_asm_free_r(g_mdi_hw_layer_array[layer_ptr->id].app_id, buffer);
    #else
        media_free_ext_buffer(stack_get_active_module_id(), (void**)&buffer);
    #endif
        g_mdi_hw_layer_array[layer_ptr->id].is_allocated = MMI_FALSE;
    }
    
    g_mdi_hw_layer_array[layer_ptr->id].scenario_id = MDI_MULTIMEDIA_NULL;
    g_mdi_hw_layer_array[layer_ptr->id].layer_handle = NULL;  
    g_mdi_hw_layer_array[layer_ptr->id].app_id = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_hw_layer_switch_to_sw_layer()
 * DESCRIPTION
 *  Switch HW layer to SW layer
 * PARAMETERS
 *  layer_handle        [IN]         
 * RETURNS
 *  
 *****************************************************************************/
GDI_RESULT mdi_util_hw_layer_switch_to_sw_layer(gdi_handle layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gdi_layer_set_hw_update_layer(layer_handle, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_hw_layer_get_content()
 * DESCRIPTION
 *  Create HW layer
 * PARAMETERS
 *  layer_handle        [IN]     
 *  dst_buff_p          [IN]     
 * RETURNS
 *  layer handle
 *****************************************************************************/
MDI_RESULT mdi_util_hw_layer_get_content(gdi_handle layer_handle, U8 *dst_buff_p, U32 dst_buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_multimedia_scenario_enum scenario_id;
    gdi_layer_struct *layer_ptr;
    MDI_RESULT ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    layer_ptr = (gdi_layer_struct*)layer_handle;
    scenario_id = g_mdi_hw_layer_array[layer_ptr->id].scenario_id;

    if (scenario_id == MDI_MULTIMEDIA_CAMERA)
    {
        #if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__) 
        ret = mdi_camera_get_hw_layer_buffer_content(layer_handle, dst_buff_p, dst_buff_size);
        #endif
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_util_remapping_layer_rotate_to_cal_rotate()
 * DESCRIPTION
 *  Create HW layer
 * PARAMETERS
 *  layer_rotate        [IN]        
 * RETURNS
 *  cal rotate value
 *****************************************************************************/
U8 mdi_util_remapping_layer_rotate_to_cal_rotate(U8 layer_rotate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cal_rotate = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(layer_rotate)
    {
        case GDI_LAYER_ROTATE_0:
            cal_rotate = MM_IMAGE_ROTATE_0;
            break;
        case GDI_LAYER_ROTATE_90:
            cal_rotate = MM_IMAGE_ROTATE_90;
            break;
        case GDI_LAYER_ROTATE_180:
            cal_rotate = MM_IMAGE_ROTATE_180;
            break;
        case GDI_LAYER_ROTATE_270:
            cal_rotate = MM_IMAGE_ROTATE_270;
            break;            
        case GDI_LAYER_ROTATE_0_MIRROR:
            cal_rotate = MM_IMAGE_H_MIRROR;
            break;
        case GDI_LAYER_ROTATE_90_MIRROR:
            cal_rotate = MM_IMAGE_H_MIRROR_ROTATE_90;
            break;
        case GDI_LAYER_ROTATE_180_MIRROR:
            cal_rotate = MM_IMAGE_H_MIRROR_ROTATE_180;
            break;
        case GDI_LAYER_ROTATE_270_MIRROR:
            cal_rotate = MM_IMAGE_H_MIRROR_ROTATE_270;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    return cal_rotate;
}


void *mdi_util_alloc_mem(U16 app_id, kal_uint8 mem_type, kal_uint32 mem_size, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *mem_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mem_type)
    {
        case MED_EXT_MEMORY_TYPE_NONCACHEABLE:
            mem_ptr= med_alloc_mem(app_id, mem_size, file_p, line_p);
            break;
        case MED_EXT_MEMORY_TYPE_CACHEABLE:
            mem_ptr = med_alloc_mem_cacheable(app_id, mem_size, file_p, line_p);
            break;
        case MED_EXT_MEMORY_TYPE_FRAMEBUFFER:
            mem_ptr = med_alloc_mem_framebuffer(app_id, mem_size, file_p, line_p);
            break;
        case MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE:
            mem_ptr = med_alloc_mem_topmost_noncacheable(app_id, mem_size, file_p, line_p);
            break;
        case MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE:
            mem_ptr = med_alloc_mem_topmost_cacheable(app_id, mem_size, file_p, line_p);
            break;
        default:
            return NULL;
            break;
    }

    return mem_ptr;
}


void mdi_util_free_mem(U16 app_id, kal_uint8 mem_type, void **mem_addr, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    med_free_mem(app_id, mem_addr, file_p, line_p);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_init()
 * DESCRIPTION
 *  Init mdi
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!g_mdi_cntx.is_init)
    {
    #if defined(__MMI_VIDEO_PLAY_SUPPORT__) 
        mdi_video_ply_init();    
    #endif 

    #if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
        mdi_video_rec_init();        
    #endif

    #if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
        mdi_mtv_init();
    #endif

    #if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
        mdi_camera_init();
    #endif

#if 0
    #if defined (MOTION_SENSOR_SUPPORT)
/* under construction !*/
    #endif
#endif
    
    #if defined(__BITSTREAM_API_SUPPORT__)
        mdi_bitstream_init();
    #endif /* __BITSTREAM_API_SUPPORT__ */

        g_mdi_cntx.is_init = MMI_TRUE;
    }
}

