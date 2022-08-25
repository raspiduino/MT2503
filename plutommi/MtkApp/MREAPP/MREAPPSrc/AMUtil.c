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
*   AMUtil.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   AM Utility Src
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
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
*============================================================================
****************************************************************************/
//#ifdef __MRE_AM__

/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "AMSwitch.h"
#include "string.h"
#include "MMI_features.h"
//#include "mmi_features.h"
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
#include "MMIDataType.h"
#include "Conversions.h"
#include "gdi_datatype.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "gdi_include.h"
#include "SimCtrlSrvGprot.h"
#ifdef __MMI_DUAL_SIM_MASTER__
#endif 
#include "ModeSwitchSrvGprot.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "kal_trace.h"	/* MOD_MMI */
#include "gui_themes.h"
#include "gui.h"
#include "gui_data_types.h"
#include "PixcomFontEngine.h"
#include "stack_config.h"	/* TRACE_GROUP_7 */
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "NwUsabSrvGprot.h"

#include "AMDef.h"
#include "AMConfig.h"
#include "AMUtil.h"
#include "AMProxy.h"
#include "MRESrvGProt.h"
#include "vmenv.h"
#include "mmi_rp_app_am_def.h"

/*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
const static U8 bits[] = {0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1};
extern mmi_am_cntx_struct g_am_cntx;
extern U8 *mre_buildin_app_array[];

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Function
*****************************************************************************/
//extern pBOOL mmi_bootup_is_network_service_available(void);
extern VMUINT vm_init_default_game(VMUINT* appcount, VMUINT* smcount, VMUINT* socount);

/*****************************************************************************
* FUNCTION
*  mmi_am_get_removeable_driver
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S8 mmi_am_get_removeable_driver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM) ==
        FS_NO_ERROR)
    {
        drive = (S8) FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        if ((drive >= 'A') && (drive <= 'Z'))
        {
            return drive;
        }
    }
    return (S8) 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_get_system_driver
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S8 mmi_am_get_system_driver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = (S8) FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
    if ((drive >= 'A') && (drive <= 'Z'))
    {
        return drive;
    }

    return (S8) 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_get_home_driver
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S8 mmi_am_get_home_driver(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int driver;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    driver = mmi_am_get_removeable_driver();
    if (driver == 0)
    {
        driver = mmi_am_get_system_driver();
    }

    return (S8) driver;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_malloc
* DESCRIPTION
*  
* PARAMETERS
*  size        [IN]        
* RETURNS
*  void
*****************************************************************************/
void *mmi_am_malloc(int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.adm_pool_id)
    {
        return kal_adm_alloc(g_am_cntx.adm_pool_id, size);
    }

    return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_calloc
* DESCRIPTION
*  
* PARAMETERS
*  size        [IN]        
* RETURNS
*  void
*****************************************************************************/
void *mmi_am_calloc(int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p = mmi_am_malloc(size);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p != NULL)
        memset(p, 0, size);

    return p;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_free
* DESCRIPTION
*  
* PARAMETERS
*  ptr     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.adm_pool_id && (ptr != NULL))
    {
        kal_adm_free(g_am_cntx.adm_pool_id, ptr);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_get_total_left_size
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
U32 mmi_am_get_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.adm_pool_id)
    {
        return kal_adm_get_total_left_size(g_am_cntx.adm_pool_id);
    }

    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_get_font_height
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S32 mmi_am_get_font_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_AM_ONLY_USE_ZIMO
    height = 0;
#else /* MMI_AM_ONLY_USE_ZIMO */ 
    gui_set_font(&MMI_small_font);
    gui_measure_string((UI_string_type) MMI_AM_TEST_STRING, &width, &height);
    gui_set_font(&MMI_medium_font);

#endif /* MMI_AM_ONLY_USE_ZIMO */ 

    return height;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_get_rom_app_array
* DESCRIPTION
*  
* PARAMETERS
*  app_array_ptr           [IN]        
*  app_array_len_ptr       [OUT]       
* RETURNS
*  void
*****************************************************************************/
void mmi_am_get_rom_app_array(S32 **app_array_ptr, S32 *app_array_len_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 appcount, smcount, socount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_init_default_game(&appcount, &smcount, &socount);
    if (appcount > 0)
    {
        *app_array_ptr = (S32*) mre_buildin_app_array;
        *app_array_len_ptr = appcount;
    }
    else
    {
        *app_array_ptr = NULL;
        *app_array_len_ptr = 0;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_get_zimo_string_data
* DESCRIPTION
*  
* PARAMETERS
*  source          [IN]        
*  p_str           [OUT]       
*  name_len        [OUT]       
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_get_zimo_string_data(U8 *source, U8 **p_str, S32 *name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 *temp_ptr = NULL;
    U8 *dest = NULL;
    S32 data_size, temp_name_len;
    S32 font_size;
    U8 *lang = NULL;
    MMI_AM_LANGUAGE_TYPE language = MMI_AM_CHS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (source == 0)
    {
        return MMI_FALSE;
    }

    /* the zimo buffer has been allocated */
    if (*p_str != NULL)
    {
        return MMI_TRUE;
    }

    lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        language = MMI_AM_ENG;
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        language = MMI_AM_CHS;
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        language = MMI_AM_CHT;
    }

    ret = mmi_am_mre_get_string_data((PS8) source, &temp_ptr, language, &temp_name_len, &font_size, &data_size);
    if (ret == MMI_FALSE)   /* && (temp_ptr != NULL)) */
    {
        language = (language == MMI_AM_ENG) ? MMI_AM_CHS : MMI_AM_ENG;
        ret = mmi_am_mre_get_string_data((PS8) source, &temp_ptr, language, &temp_name_len, &font_size, &data_size);
        if (ret == MMI_FALSE)
        {
            return MMI_FALSE;
        }
    }

    /* allocate memory */
    dest = mmi_am_calloc(data_size);
    if (dest == NULL)
    {
        return MMI_FALSE;
    }

    memcpy(dest, temp_ptr, data_size);
    *p_str = dest;
    *name_len = temp_name_len;

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_measure_zimo
* DESCRIPTION
*  
* PARAMETERS
*  zimo_buf        [IN]        
*  str_len         [IN]        
* RETURNS
*  
*****************************************************************************/
S32 mmi_am_measure_zimo(U8 *zimo_buf, S32 str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_am_mre_measure_zimo_string((PS8) zimo_buf, str_len);
}


/*****************************************************************************
* FUNCTION
*  mmi_am_draw_asc
* DESCRIPTION
*  
* PARAMETERS
*  x               [IN]        
*  y               [IN]        
*  font_size       [IN]        
*  font_data       [IN]        
*  color           [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_draw_asc(S32 x, S32 y, S32 font_size, const U8 *font_data, gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < font_size; i++)
    {
        for (j = 0; j < font_size / 2; j++)
        {
            if (font_data[i * ((font_size / 2 + 7) / 8) + (j / 8)] & bits[j % 8])
            {
                if ((x + j > 0) && (x + j < GDI_LCD_WIDTH) && (y + i) > 0 && (y + i < GDI_LCD_HEIGHT))
                    gdi_draw_point(x + j, y + i, color);
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_draw_hz
* DESCRIPTION
*  
* PARAMETERS
*  x               [IN]        
*  y               [IN]        
*  font_size       [IN]        
*  font_data       [IN]        
*  color           [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_am_draw_hz(S32 x, S32 y, S32 font_size, const U8 *font_data, gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < font_size; i++)
    {
        for (j = 0; j < font_size; j++)
        {
            if (font_data[i * ((font_size + 7) / 8) + (j / 8)] & bits[j % 8])
            {
                if ((x + j > 0) && (x + j < GDI_LCD_WIDTH) && (y + i) > 0 && (y + i < GDI_LCD_HEIGHT))
                    gdi_draw_point(x + j, y + i, color);
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_draw_zimo
* DESCRIPTION
*  
* PARAMETERS
*  x               [IN]        
*  y               [IN]        
*  start_idx       [IN]        
*  out_str_len     [IN]        
*  src_buf         [IN]        
*  str_len         [IN]        
*  font            [IN]        
*  color           [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_draw_zimo(
                      S32 x,
                      S32 y,
                      S32 start_idx,
                      S32 out_str_len,
                      U8 *src_buf,
                      S32 str_len,
                      S32 font,
                      gdi_color color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count, flag, offset, offset_out, offset_ch;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_buf || (str_len <= 0) || (start_idx >= str_len) || ((font != 12) && (font != 14) && (font != 16)))
        return;

    count = (start_idx + out_str_len < str_len) ? out_str_len : (str_len - start_idx);
    offset = 0;

    for (i = 0; i < start_idx; i++)
    {
        offset += *(src_buf + offset + 1) + 2;
    }

    for (i = 0, offset_out = 0; i < count; i++)
    {
        flag = *(src_buf + offset);
        offset_ch = *(src_buf + offset + 1);

        if (flag == 2)
        {
            mmi_am_draw_asc(x + offset_out, y, font, (src_buf + offset + 2), color);
            offset_out += font / 2;
        }
        else
        {
            mmi_am_draw_hz(x + offset_out, y, font, (src_buf + offset + 2), color);
            offset_out += font;
        }
        offset += offset_ch + 2;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_is_support_wifi
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_is_support_wifi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else /* __MMI_WLAN_FEATURES__ */ 
    return MMI_FALSE;
#endif /* __MMI_WLAN_FEATURES__ */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_am_get_sim_card_num
* DESCRIPTION
*  Get available sim card number. (These sims can connect to network.)
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S32 mmi_am_get_sim_card_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_am_is_network_service_available())
    {
        return 0;
    }

#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
    {
        return 0;
    }
#endif /* __MMI_WLAN_FEATURES__ */ 

#ifndef __MMI_DUAL_SIM_MASTER__
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {
        return 1;
    }
#else /* __MMI_DUAL_SIM_MASTER__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */ 

    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_is_appstore_in_rom
* DESCRIPTION
*  
* PARAMETERS
*  app_path        [IN]        
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_is_appstore_in_rom(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf = 0;
    S32 buf_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mre_get_app_id(app_path, &buf))
    {
        if ((buf >= 0x00010000) && (buf <= 0x00010100))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_is_network_service_available
* DESCRIPTION
*  Check whether the network is available.
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_is_network_service_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_nw_usab_is_any_network_available();
}


/*****************************************************************************
* FUNCTION
*  mmi_am_mre_set_am_state
* DESCRIPTION
*  
* PARAMETERS
*  state       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_am_mre_set_am_state(MMI_AM_STATES state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
    case MMI_AM_IN_USE:
        vm_vam_set_vam_state(VAM_IN_USE);
        break;
    case MMI_AM_OUT_OF_USE:
        vm_vam_set_vam_state(VAM_OUT_OF_USE);
        break;
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_is_app_downloaded
* DESCRIPTION
*  Search app by app name.
* PARAMETERS
*  app_name        [IN]        Application file name.
*  app_path        [IN]         Application path.
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_is_app_downloaded(S8 *app_name, U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_drv;
    U16 temp_path_w[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    FS_HANDLE fd = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_name == NULL)
    {
        return MMI_FALSE;
    }

    /* search app in remove driver */
    file_drv = mmi_am_get_removeable_driver();
    if (file_drv)
    {
        kal_wsprintf((WCHAR*) temp_path_w, "%c:\\%s\\%s", file_drv, MMI_AM_MRE_HOME_DIR, app_name);
        if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* app exist */
            mmi_wcsncpy(app_path, temp_path_w, MMI_AM_MAX_SHORTCUT_APP_FILE_PATH);
            FS_Close(fd);
            return MMI_TRUE;
        }

        memset(temp_path_w, 0, sizeof(temp_path_w));
    }

    /* search app in system driver */
    file_drv = mmi_am_get_system_driver();
    if (file_drv)
    {
        kal_wsprintf((WCHAR*) temp_path_w, "%c:\\%s\\%s", file_drv, MMI_AM_MRE_HOME_DIR, app_name);
        if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* app exist */
            mmi_wcsncpy(app_path, temp_path_w, MMI_AM_MAX_SHORTCUT_APP_FILE_PATH);
            FS_Close(fd);
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

#endif /* __MRE_AM__ */ 

