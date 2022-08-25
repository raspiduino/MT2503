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
 *  FontManager.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for vector font on memory card
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*****************************************************************************
*  Include
*****************************************************************************/

#include "MMI_include.h"
#include "Fs_func.h"
#include "Font_engine_interface.h"
#include "FileMgrGProt.h"
#include "PixcomFontEngine.h"
#include "custom_events_notify.h"
#include "font_engine_interface.h"
#include "SettingResDef.h"
#include "CommonScreens.h"
#include "FontManagerResDefs.h"
#include "FontManagerGProt.h"
#include "USBDeviceGprot.h"
#include "FileMgrCuiGProt.h"
#include "mmi_rp_app_font_manager_def.h"
#include "MenuCuiGprot.h"
#include "ProfilesSrvGprot.h"
#include "USBsrvGprot.h"


#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)


#define MMI_FONT_MGR_DATABASE_PATH           L"Z:\\@font"
#define MMI_FONT_MGR_DATABASE_FILE           L"font_list.dat"

#define MMI_FONT_MGR_OPTION_MAX_NUM 5
#define MMI_FONT_MGR_RESET_POPUP_TIMER 500

//#define MMI_FONT_MGR_ERROR_CHANGE_LANG
#if defined(MMI_FONT_MGR_ERROR_CHANGE_LANG)
#define MMI_FONT_MGR_LANG_CODE "*#0044#"
#endif

/*****************************************************************************
*  External Function
*****************************************************************************/
extern MMI_BOOL mmi_fe_add_font_from_file(mmi_font_mgr_font_file_resource_struct* font, S32 num, S16* priority_list, MMI_BOOL init);
extern mmi_fe_error_code mmi_fe_get_font_name(U16 resid, UI_string_type buffer, S32 buf_size);
extern mmi_fe_error_code mmi_fe_check_font(U16 resid);
extern S32 mmi_fe_get_system_font_number(void);
extern void SSCHandleSSCString(const S8* ssc_string, S32 error, S32 success);


/*****************************************************************************
*  Local Variables
*****************************************************************************/
static mmi_font_mgr_font_file_resource_struct g_mmi_font_mgr_font_file_resource[FE_MAX_FONT_FILE_NUMBER];
static S32 g_mmi_font_mgr_intall_font_number = 0;
/* the value is the index in g_mmi_font_mgr_font_file_resource and -1 present the system font. */
static S16 g_mmi_font_mgr_priority_list[FE_MAX_FONT_FILE_NUMBER];
static  UI_character_type g_mmi_font_mgr_temp_name[256];
static MMI_BOOL g_mmi_font_mgr_is_init = MMI_FALSE;
static S16 g_mmi_font_mgr_highlight_font = -1;
static S32 g_mmi_font_mgr_set_priority = 0;
static MMI_BOOL g_mmi_font_mgr_data_change = MMI_FALSE;
static S32 g_mmi_font_mgr_max_ext_font_num = -1;
static U16 g_mmi_font_mgr_install_close_screen = 0;
static FuncPtr g_mmi_font_mgr_end_key_handler = NULL;
static S32 g_mmi_font_mgr_uninstall_index = -1;
static MMI_BOOL g_mmi_font_mgr_active_handler = MMI_FALSE;
static U32 g_mmi_font_mgr_error_code = 0;

static mmi_id font_mgr_menu_cui_gid = GRP_ID_INVALID;
static mmi_id font_mgr_gid = GRP_ID_INVALID;

/*****************************************************************************
*  Local Function
*****************************************************************************/
static MMI_BOOL mmi_font_mgr_font_change(MMI_BOOL init);
static void mmi_font_mgr_list_font_family(mmi_id parent_gid);
static MMI_BOOL mmi_font_mgr_install_new_font_int(S8* file_name);
static void mmi_font_mgr_font_uninstall_int(S32 index);
static S32 mmi_font_mgr_get_checksum(FS_HANDLE fileHandle);

#ifndef __COSMOS_MMI_PACKAGE__
static void mmi_font_mgr_popup_activate(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_update_font_database
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_update_font_database(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    int ret_val;
    FS_HANDLE file_handle;
    U32 write_size;
    S32 file_name_size, font_name_size;
    S32 token;
    MMI_BOOL success = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    g_mmi_font_mgr_data_change = MMI_TRUE;
    
    /* update font list */
    if (!g_mmi_font_mgr_is_init)
    {
        MMI_DBG_ASSERT(0);
        return;
    }

    do 
    {
        ret_val = FS_SetCurrentDir(MMI_FONT_MGR_DATABASE_PATH);
        if (ret_val)
        {
            ret_val = FS_CreateDir(MMI_FONT_MGR_DATABASE_PATH);
            if (ret_val)
            {
                MMI_DBG_ASSERT(0);
                break;
            }
            ret_val = FS_SetCurrentDir(MMI_FONT_MGR_DATABASE_PATH);
            if (ret_val)
            {
                MMI_DBG_ASSERT(0);
                break;
            }
        }


        /* try to open file */
        file_handle = FS_Open(MMI_FONT_MGR_DATABASE_FILE, FS_READ_WRITE | FS_ATTR_ARCHIVE | FS_CREATE_ALWAYS);
        if (file_handle < 0)    /* failed to open existing file, or file not exists */
        {
            MMI_DBG_ASSERT(0);
            break;
        }
        else
        {
            /* write down the font number  */
            token = g_mmi_font_mgr_intall_font_number+1;
            ret_val = FS_Write(file_handle, (void*)&token, 4, &write_size);
            if (ret_val || write_size != 4)
            {
                MMI_DBG_ASSERT(0);
                break;
            }

            /* write each data */
            for (i = 0; i < g_mmi_font_mgr_intall_font_number + 1; i ++)
            {
                if (g_mmi_font_mgr_priority_list[i] != -1)
                {
                    /* *2 to convert from UI_character_type to byte size */
                    file_name_size = 2*mmi_ucs2strlen((const S8*)g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].name);
                    font_name_size = 2*mmi_ucs2strlen((const S8*)g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].fontName);
                    /* 1. write down the file path string size */
                    ret_val = FS_Write(file_handle, (void*)&file_name_size, 4, &write_size);
                    if (ret_val || write_size != 4)
                    {
                        MMI_DBG_ASSERT(0);
                        break;
                    }
                    
                    /* 2. write down the file path string size */
                    ret_val = FS_Write(file_handle, (void*)&font_name_size, 4, &write_size);
                    if (ret_val || write_size != 4)
                    {
                        MMI_DBG_ASSERT(0);
                        break;
                    }

                    
                    /* 3. write down the file path string */
                    ret_val = FS_Write(
                                    file_handle, 
                                    (void*)g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].name, 
                                    file_name_size, &write_size);
                    if (ret_val || write_size != file_name_size)
                    {
                        MMI_DBG_ASSERT(0);
                        break;
                    }

                    /* 4. write down the font name string */
                    ret_val = FS_Write(
                                    file_handle, 
                                    (void*)g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].fontName, 
                                    font_name_size, &write_size);
                    if (ret_val || write_size != font_name_size)
                    {
                        MMI_DBG_ASSERT(0);
                        break;
                    }

                    if(g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].handle == 0)
                    {
                        g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].handle = FS_Open((UI_string_type) g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].name, FS_READ_ONLY);
                        if(g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].handle <= 0)
                        {
                            MMI_DBG_ASSERT(0);
                        }
                    }
                    token = mmi_font_mgr_get_checksum(g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].handle);
                    FS_Write(file_handle, &token, 4, &write_size);
                    if (ret_val || write_size != 4)
                    {
                        MMI_DBG_ASSERT(0);
                        break;
                    }
                    
                }
                else
                {
                    token = 0xFFFFFFFF;
                    ret_val = FS_Write(file_handle, &token, 4, &write_size);
                    if (ret_val || write_size != 4)
                    {
                        MMI_DBG_ASSERT(0);
                        break;
                    }
                    token = 0;
                    FS_Write(file_handle, &token, 4, &write_size);
                    if (ret_val || write_size != 4)
                    {
                        MMI_DBG_ASSERT(0);
                        break;
                    }
                }
                    
            }
            FS_Close(file_handle);
            success = MMI_TRUE;
        }
    }while (0);

    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_change
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_font_mgr_font_change(MMI_BOOL init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
    {
        if (g_mmi_font_mgr_font_file_resource[i].handle)
        {
            FS_Close(g_mmi_font_mgr_font_file_resource[i].handle);
            g_mmi_font_mgr_font_file_resource[i].handle = NULL;
        }
    }

    return mmi_fe_add_font_from_file(g_mmi_font_mgr_font_file_resource, g_mmi_font_mgr_intall_font_number, g_mmi_font_mgr_priority_list, init);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_uninstall_int
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_font_uninstall_int(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index_on_priority_list = -1;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    if (g_mmi_font_mgr_intall_font_number == 0)
        return;

    for (i = 0; i <= g_mmi_font_mgr_intall_font_number; i ++)
    {
        if (g_mmi_font_mgr_priority_list[i] == index)
        {
            index_on_priority_list = i;
            break;
        }
    }

    if (index_on_priority_list == -1)
        MMI_ASSERT(0);


    if (g_mmi_font_mgr_font_file_resource[index].handle)
        FS_Close(g_mmi_font_mgr_font_file_resource[index].handle);

    if (g_mmi_font_mgr_intall_font_number - 1  == 0)
    {       
        g_mmi_font_mgr_intall_font_number = 0;
        g_mmi_font_mgr_priority_list[0] = -1;
        memset(&g_mmi_font_mgr_font_file_resource[0], 0, sizeof(mmi_font_mgr_font_file_resource_struct));
    }
    else
    {
        memmove((&g_mmi_font_mgr_font_file_resource[index]), (&g_mmi_font_mgr_font_file_resource[index+1]), sizeof(mmi_font_mgr_font_file_resource_struct)*(g_mmi_font_mgr_intall_font_number - index));
        memmove(&g_mmi_font_mgr_priority_list[index_on_priority_list], &g_mmi_font_mgr_priority_list[index_on_priority_list + 1], sizeof(U16)*(g_mmi_font_mgr_intall_font_number - index_on_priority_list + 1));
        for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
        {
            if (g_mmi_font_mgr_priority_list[i] > index)
            {
                g_mmi_font_mgr_priority_list[i] -= 1;
            }
        }
        g_mmi_font_mgr_intall_font_number --;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_add_new_font
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_add_new_font(MMI_BOOL is_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (mmi_font_mgr_font_change(MMI_TRUE))
    {

       GDI_LOCK;
        mmi_fe_get_font_name(
            g_mmi_font_mgr_intall_font_number - 1, 
            g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number - 1].fontName, 
            64);
        mmi_font_mgr_update_font_database();

        GDI_UNLOCK;

        if (is_popup)
            mmi_font_mgr_show_popup((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_FONT_MGR_SUCCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_popup_activate_confirm
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_popup_activate_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    g_mmi_font_mgr_active_handler = MMI_TRUE;
    memmove(&g_mmi_font_mgr_priority_list[1], &g_mmi_font_mgr_priority_list[0], sizeof(S16)*(g_mmi_font_mgr_intall_font_number));
    g_mmi_font_mgr_priority_list[0] = g_mmi_font_mgr_intall_font_number - 1;
    mmi_ucs2cpy((S8*)(&g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number - 1].name), (const S8*)&g_mmi_font_mgr_temp_name);

    mmi_font_mgr_add_new_font(MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_install_new_font_int
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_font_mgr_install_new_font_int(S8* file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_error_code err;
    S32 len;
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    
    /* check for allowed external font number */
    if (g_mmi_font_mgr_max_ext_font_num == -1)
    {
        g_mmi_font_mgr_max_ext_font_num = 15 - mmi_fe_get_system_font_number();
    }
    
    if ((g_mmi_font_mgr_intall_font_number + 1) >= FE_MAX_FONT_FILE_NUMBER || g_mmi_font_mgr_intall_font_number + 1 > g_mmi_font_mgr_max_ext_font_num)
    {
        mmi_font_mgr_show_popup((WCHAR*)GetString(STR_ID_FONT_MGR_REACH_MAX_FONT_NUM), MMI_FONT_MGR_FAIL);        
        return MMI_FALSE;
    }

    /* check for installed font */
    len = mmi_ucs2strlen((const CHAR*)file_name);
    for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
    {
        if (mmi_ucs2cmp((const CHAR*)file_name, (const CHAR*)&g_mmi_font_mgr_font_file_resource[i].name) == 0)
        {
            mmi_font_mgr_show_popup((WCHAR*)GetString(STR_ID_FONT_MGR_INSTALLED_FONT), MMI_FONT_MGR_ERROR);
            return MMI_FALSE;
        }
    }


    /* add font into structure temporily */
    mmi_ucs2cpy((S8*)(&g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number].name), (const S8*)file_name);

    /* add to the end of priority list temporarily */
    g_mmi_font_mgr_priority_list[g_mmi_font_mgr_intall_font_number + 1] = g_mmi_font_mgr_intall_font_number;
    g_mmi_font_mgr_intall_font_number ++;

    err = mmi_fe_check_font(g_mmi_font_mgr_intall_font_number - 1);
    if (err == MMI_FE_FONT_ERR_NONE)
    {
        mmi_ucs2cpy((S8*)(&g_mmi_font_mgr_temp_name), (const S8*)file_name);
#ifndef __COSMOS_MMI_PACKAGE__
        mmi_font_mgr_popup_activate();
#endif
        g_mmi_font_mgr_data_change = MMI_TRUE;
    }
    else
    {
        if (g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number - 1].handle)
        {
            FS_Close((int)g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number - 1].handle);
        }
        memset((&g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number - 1]), 0, sizeof(mmi_font_mgr_font_file_resource_struct));
        g_mmi_font_mgr_intall_font_number --;
        if (err == MMI_FE_FONT_ERR_OUT_OF_MEMORY)
        {
            mmi_font_mgr_show_popup((WCHAR*)GetString(STR_ID_FONT_MGR_OUT_OF_MEMORY), MMI_FONT_MGR_FAIL);
        }
        else if (err == MMI_FE_FONT_ERR_INVALID_FONT)
        {
            mmi_font_mgr_show_popup((WCHAR*)GetString(STR_ID_FONT_MGR_INVALID_FONT), MMI_FONT_MGR_FAIL);
        }
		return MMI_FALSE;
    }
	return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_reset_all
 * DESCRIPTION
 *  To reset all installed font.
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL mmi_font_mgr_reset_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    if (g_mmi_font_mgr_intall_font_number)
    {
        for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
        {
            FS_Close(g_mmi_font_mgr_font_file_resource[i].handle);
        }

        memset(&g_mmi_font_mgr_font_file_resource, 0, sizeof(g_mmi_font_mgr_font_file_resource));
        memset(&g_mmi_font_mgr_priority_list, 0, sizeof(g_mmi_font_mgr_priority_list));
        g_mmi_font_mgr_intall_font_number = 0;
        g_mmi_font_mgr_priority_list[g_mmi_font_mgr_intall_font_number] = -1;
        mmi_fe_add_font_from_file(g_mmi_font_mgr_font_file_resource, 0, g_mmi_font_mgr_priority_list, MMI_TRUE);
        mmi_font_mgr_update_font_database();


        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_option_uninstall_handler_confirm
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_option_uninstall_handler_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_mmi_font_mgr_uninstall_index == -1)
    {

    }
    else
    {
        GDI_LOCK;
        mmi_font_mgr_font_uninstall_int(g_mmi_font_mgr_uninstall_index);
        mmi_font_mgr_font_change(MMI_TRUE);
        mmi_font_mgr_update_font_database();
        GDI_UNLOCK;
        mmi_font_mgr_show_popup((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_FONT_MGR_SUCCESS);
    }

    g_mmi_font_mgr_uninstall_index = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_popup_activate_cancel
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_popup_activate_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    g_mmi_font_mgr_active_handler = MMI_TRUE;
    g_mmi_font_mgr_priority_list[g_mmi_font_mgr_intall_font_number] = g_mmi_font_mgr_intall_font_number - 1;
    mmi_ucs2cpy((S8*)(&g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number].name), (const S8*)&g_mmi_font_mgr_temp_name);
    mmi_font_mgr_add_new_font(MMI_TRUE);
    //mmi_font_mgr_show_popup((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_FONT_MGR_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_popup_activate_exit
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_popup_activate_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (!g_mmi_font_mgr_active_handler)
    {
        if(mmi_ucs2strlen((const char *)g_mmi_font_mgr_temp_name))
        {
            g_mmi_font_mgr_priority_list[g_mmi_font_mgr_intall_font_number] = g_mmi_font_mgr_intall_font_number - 1;
            mmi_ucs2cpy((S8*)(&g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number].name), (const S8*)&g_mmi_font_mgr_temp_name);
            mmi_font_mgr_add_new_font(MMI_FALSE);    
            srv_prof_stop_tone(SRV_PROF_TONE_CONFIRM);
        }
    }
    g_mmi_font_mgr_active_handler = MMI_FALSE;

}


#ifndef __COSMOS_MMI_PACKAGE__

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_show_popup
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_show_popup(WCHAR* str, mmi_font_mgr_event_type_enum evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_event_notify_enum evt_type = MMI_EVENT_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	switch(evt)
	{
		case MMI_FONT_MGR_FAIL:
			evt_type = MMI_EVENT_FAILURE;
			break;
		case MMI_FONT_MGR_ERROR:
			evt_type = MMI_EVENT_ERROR;
			break;
	}
    mmi_popup_display(str, evt_type, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_highlight_setting_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_highlight_setting_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    //SetLeftSoftkeyFunction(mmi_font_mgr_list_font_family, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_show_font_list
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_show_font_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_list_option_entry_priority_change_screen
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_font_list_option_entry_priority_change_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;  /* Buffer holding history data */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if(mmi_frm_scrn_enter(GRP_ID_FONT_MGR, SCR_ID_FONT_MGR_FONT_LIST_SET_PRIORITY, 
        NULL, mmi_font_mgr_font_list_option_entry_priority_change_screen, MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_FONT_MGR, SCR_ID_FONT_MGR_FONT_LIST_SET_PRIORITY);
        g_mmi_font_mgr_set_priority = g_mmi_font_mgr_highlight_font + 1;
        ShowCategory87Screen(
            STR_ID_FONT_MGR_CHANGE_PRIORITY, 
            0, 
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            1, 
            g_mmi_font_mgr_intall_font_number + 1, 
            &g_mmi_font_mgr_set_priority, 
            guiBuffer);
        
        SetLeftSoftkeyFunction(mmi_font_mgr_font_list_option_priority_change_handler, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_list_option_uninstall_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_font_list_option_uninstall_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font];
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font] == -1)
    {
        MMI_ASSERT(0);
    }
    GDI_LOCK;
    mmi_font_mgr_font_uninstall_int(i);
    
    ret = mmi_font_mgr_font_change(MMI_TRUE);
    mmi_font_mgr_update_font_database();
    GDI_UNLOCK;
    cui_menu_close(font_mgr_menu_cui_gid);
    font_mgr_menu_cui_gid = GRP_ID_INVALID;
    //mmi_frm_scrn_close_active_id();
    mmi_font_mgr_show_popup((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_FONT_MGR_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_list_options_uninstall_confirm_cb
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static mmi_ret mmi_font_mgr_list_options_uninstall_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->result == MMI_ALERT_CNFM_YES)
    {
        mmi_font_mgr_font_list_option_uninstall_handler();
    }
    else if (evt->result == MMI_ALERT_CNFM_NO)
    {
        //mmi_frm_scrn_close_active_id();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_list_option_uninstall_query
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_font_list_option_uninstall_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_font_mgr_list_options_uninstall_confirm_cb;

    mmi_confirm_display((WCHAR *)GetString(STR_ID_FONT_MGR_UNINSTALL_QUERY), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_add_new_font_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_add_new_font_handler(void* fullpath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    //g_mmi_font_mgr_install_close_screen = SCR_ID_FONT_MGR_FONT_LIST;
    if (fullpath)
    {
        mmi_font_mgr_install_new_font_int((S8*)fullpath);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_font_mgr_group_proc
* DESCRIPTION
*  
* PARAMETERS
*  mmi_event_struct* evt
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_font_mgr_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    srv_fmgr_fileinfo_struct file_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct * evt_fs = (cui_file_selector_result_event_struct *)evt;
            if (evt_fs->result > 0)
            {
                /*user selected a file*/
                cui_file_selector_get_selected_filepath(evt_fs->sender_id, &file_info, (WCHAR *)filepath, SRV_FMGR_PATH_BUFFER_SIZE);
                mmi_font_mgr_add_new_font_handler(filepath, 0);
				cui_file_selector_close(evt_fs->sender_id);
                font_mgr_gid = GRP_ID_INVALID;
                if(font_mgr_menu_cui_gid != GRP_ID_INVALID)
                {
                    cui_menu_close(font_mgr_menu_cui_gid);
                    font_mgr_menu_cui_gid = GRP_ID_INVALID;
                }
            }
            else
            {   /*user cancel or FS error*/
                cui_file_selector_close(evt_fs->sender_id);
                font_mgr_gid = GRP_ID_INVALID;
            }
            break;
        }
        
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_list_option_add_new_font_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_font_list_option_add_new_font_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fs_gid;
    FMGR_FILTER filter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    fs_gid = mmi_frm_group_create(GRP_ID_FONT_MGR, GRP_ID_AUTO_GEN, mmi_font_mgr_group_proc, NULL);
    mmi_frm_group_enter(fs_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_TTF);

    font_mgr_gid = cui_file_selector_create(fs_gid, 
        (WCHAR*) L"root", 
        &filter, 
        CUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
        CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);
    
    if (font_mgr_gid != GRP_ID_INVALID)
    {  
        cui_file_selector_run(font_mgr_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_list_option_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_font_list_option_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font] == -1)
    {
        if (g_mmi_font_mgr_intall_font_number == 0)
        {
            if (index == 0)
            {
                mmi_font_mgr_font_list_option_add_new_font_handler();
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
        else
        {
            if (index == 0)
            {
                mmi_font_mgr_font_list_option_entry_priority_change_screen();
            }
            else if (index == 1)
            {
                mmi_font_mgr_font_list_option_add_new_font_handler();
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
    }
    else
    {
        switch (index)
        {
            case 0:
                mmi_font_mgr_font_list_option_entry_priority_change_screen();
                break;
            case 1:
                mmi_font_mgr_font_list_option_uninstall_query();
                break;
            case 2:
                mmi_font_mgr_font_list_option_add_new_font_handler();
                break;
            default:
                MMI_ASSERT(0);
                break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_enter_font_list_option
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ret mmi_font_mgr_enter_font_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 nNumofItem = 0;
    MMI_ID menu_cui_id = mmi_frm_group_get_active_id();
    mmi_menu_id *menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for allowed external font number */
    if (g_mmi_font_mgr_max_ext_font_num == -1)
    {
        g_mmi_font_mgr_max_ext_font_num = FE_MAX_FONT_FILE_NUMBER - mmi_fe_get_system_font_number();
    }

    if (g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font] == -1)
    {
        /* system font */
        if (g_mmi_font_mgr_intall_font_number != 0)
        {
            nNumofItem++;
        }
    }
    else
    {
        nNumofItem += 2;
    }

    if ((g_mmi_font_mgr_intall_font_number + 1) < FE_MAX_FONT_FILE_NUMBER && g_mmi_font_mgr_intall_font_number + 1 <= g_mmi_font_mgr_max_ext_font_num)
    {
        nNumofItem++;
    }

    menu_id = (mmi_menu_id*)OslMalloc(nNumofItem * sizeof(mmi_menu_id));
    for(i = 0; i < nNumofItem; i++)
    {
        menu_id[i]=(mmi_menu_id)i;
    }

    cui_menu_set_currlist_title(menu_cui_id, (WCHAR*) GetString(STR_ID_FONT_MGR_LIST_FONT), NULL);
    cui_menu_set_currlist_left_softkey_by_id(menu_cui_id, STR_GLOBAL_OK);
    cui_menu_set_currlist_right_softkey_by_id(menu_cui_id, STR_GLOBAL_BACK);
    cui_menu_set_currlist(menu_cui_id, nNumofItem, menu_id);
    cui_menu_set_currlist_flags(menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

    i = 0;
    if (g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font] == -1)
    {
        /* system font */
        if (g_mmi_font_mgr_intall_font_number != 0)
        {
            cui_menu_set_item_string_by_id(menu_cui_id, menu_id[i++], STR_ID_FONT_MGR_CHANGE_PRIORITY);
        }
    }
    else
    {
        cui_menu_set_item_string_by_id(menu_cui_id, menu_id[i++], STR_ID_FONT_MGR_CHANGE_PRIORITY);
        cui_menu_set_item_string_by_id(menu_cui_id, menu_id[i++], STR_ID_FONT_MGR_UNINSTALL);
    }

    if ((g_mmi_font_mgr_intall_font_number + 1) < FE_MAX_FONT_FILE_NUMBER && g_mmi_font_mgr_intall_font_number + 1 <= g_mmi_font_mgr_max_ext_font_num)
    {
        cui_menu_set_item_string_by_id(menu_cui_id, menu_id[i++], STR_ID_FONT_MGR_ADD_NEW_FONT);
    }
    OslMfree(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_list_option
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_font_list_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    font_mgr_menu_cui_gid = cui_menu_create(
        GRP_ID_FONT_MGR,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_APPSUB,
        MENU_ID_FONT_MGR_OPTIONS,
        MMI_FALSE,
        NULL);
    cui_menu_run(font_mgr_menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_highlight_setting_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_list_font_family(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return;
    }
#endif    

    g_mmi_font_mgr_data_change = MMI_FALSE;
    mmi_frm_group_create(
        parent_id,
        GRP_ID_FONT_MGR,
        mmi_font_mgr_setting_proc,
        NULL);
    mmi_frm_group_enter(GRP_ID_FONT_MGR, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    menu_cui_gid = cui_menu_create(
        GRP_ID_FONT_MGR,
        CUI_MENU_SRC_TYPE_APPCREATE,
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_FONT_MGR_SETTING,
        MMI_FALSE,
        NULL);
    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_enter_font_list
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ret mmi_font_mgr_enter_font_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U16 nNumofItem = g_mmi_font_mgr_intall_font_number + 1;
    MMI_ID menu_cui_id = mmi_frm_group_get_active_id();
    mmi_menu_id *menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_id = (mmi_menu_id*)OslMalloc(nNumofItem * sizeof(mmi_menu_id));
    for(i = 0; i < nNumofItem; i++)
    {
        menu_id[i]=(mmi_menu_id)i;
    }

    cui_menu_set_currlist_title(menu_cui_id, (WCHAR*) GetString(STR_ID_FONT_MGR_LIST_FONT), NULL);
    cui_menu_set_currlist_left_softkey_by_id(menu_cui_id, STR_GLOBAL_OPTIONS);
    cui_menu_set_currlist_right_softkey_by_id(menu_cui_id, STR_GLOBAL_BACK);
    cui_menu_set_currlist(menu_cui_id, nNumofItem, menu_id);
    cui_menu_set_currlist_flags(menu_cui_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
    for(i = 0; i < nNumofItem; i++)
    {
        /* system font */
        if (g_mmi_font_mgr_priority_list[i] == -1)
        {
            cui_menu_set_item_string_by_id(menu_cui_id, menu_id[i], STR_ID_FONT_MGR_SYSTEM_FONT);
        }
        else
        {
            cui_menu_set_item_string(menu_cui_id, menu_id[i], (WCHAR*)g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[i]].fontName);
        }
    }
    OslMfree(menu_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_setting_proc
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ret mmi_font_mgr_setting_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cui_menu_is_menu_event(param->evt_id))
	{
        cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)param;
        switch (param->evt_id)
        {
        case EVT_ID_CUI_MENU_LIST_ENTRY:

            if(menu_evt->parent_menu_id == MENU_ID_FONT_MGR_SETTING)
            {
                mmi_font_mgr_enter_font_list();
            }
            else if(menu_evt->parent_menu_id == MENU_ID_FONT_MGR_OPTIONS)
            {
                mmi_font_mgr_enter_font_list_option();
            }
            return MMI_RET_OK;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:

            if(menu_evt->parent_menu_id == MENU_ID_FONT_MGR_SETTING)
            {
                MMI_MENU_ID highlighted_id = menu_evt->highlighted_menu_id;
                g_mmi_font_mgr_highlight_font = (S16)highlighted_id;
                mmi_font_mgr_font_list_option();
            }
            else if(menu_evt->parent_menu_id == MENU_ID_FONT_MGR_OPTIONS)
            {
                MMI_MENU_ID highlighted_id = menu_evt->highlighted_menu_id;
                mmi_font_mgr_font_list_option_handler((U16) highlighted_id);
            }
            return MMI_RET_OK;        
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(((cui_menu_event_struct*)param)->sender_id);
            return MMI_RET_OK;
            
        default:
    		return MMI_RET_OK;
        }	
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_activate_exit_process
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_activate_exit_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    g_mmi_font_mgr_priority_list[g_mmi_font_mgr_intall_font_number] = g_mmi_font_mgr_intall_font_number - 1;
    mmi_ucs2cpy((S8*)(&g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_intall_font_number].name), (const S8*)&g_mmi_font_mgr_temp_name);
    mmi_font_mgr_add_new_font(MMI_FALSE);
    
    if (g_mmi_font_mgr_end_key_handler)
    {
        g_mmi_font_mgr_end_key_handler();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_popup_activate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static mmi_ret mmi_font_mgr_popup_activate_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->result == MMI_ALERT_CNFM_YES)
    {
        mmi_font_mgr_popup_activate_confirm();
    }
    else if (evt->result == MMI_ALERT_CNFM_NO)
    {
        mmi_font_mgr_popup_activate_cancel();
    }
    else if (evt->result == MMI_POPUP_INTERRUPT_EXIT)
    {
        mmi_font_mgr_popup_activate_exit();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_popup_activate
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void mmi_font_mgr_popup_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    g_mmi_font_mgr_active_handler = MMI_FALSE;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_font_mgr_popup_activate_confirm_cb;

    mmi_confirm_display((WCHAR *)GetString(STR_ID_FONT_MGR_ACTIVATE_QUERY), MMI_EVENT_QUERY, &arg);
    srv_prof_play_tone(SRV_PROF_TONE_CONFIRM,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_option_install_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_option_install_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct info;
    const WCHAR* file_name = srv_fmgr_types_query_fileinfo(&info);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    //g_mmi_font_mgr_install_close_screen = GetCurrScrnId();
    mmi_font_mgr_install_new_font_int((S8 *)file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_option_uninstall_handler_cancel
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_option_uninstall_handler_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_frm_scrn_close_active_id();
    g_mmi_font_mgr_uninstall_index = -1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_uninstall_confirm_cb
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static mmi_ret mmi_font_mgr_uninstall_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->result == MMI_ALERT_CNFM_YES)
    {
        mmi_font_mgr_option_uninstall_handler_confirm();
    }
    else if (evt->result == MMI_ALERT_CNFM_NO)
    {
        mmi_font_mgr_option_uninstall_handler_cancel();
    }
    else if (evt->result == MMI_POPUP_INTERRUPT_EXIT)
    {
        mmi_font_mgr_option_uninstall_handler_cancel();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_option_install_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_option_uninstall_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    srv_fmgr_fileinfo_struct info;
    const WCHAR* file_name = srv_fmgr_types_query_fileinfo(&info);
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_mmi_font_mgr_intall_font_number != 0)
    {			
        for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
        {
            if (mmi_ucs2cmp((const S8*)file_name, (const S8*)(&g_mmi_font_mgr_font_file_resource[i].name)) == 0)
            {
                g_mmi_font_mgr_uninstall_index = i;
                mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
                arg.callback = (mmi_proc_func)mmi_font_mgr_uninstall_confirm_cb;
                mmi_confirm_display((WCHAR *)GetString(STR_GLOBAL_YES), MMI_EVENT_QUERY, &arg);
                return;
            }
        }
    }
    mmi_font_mgr_show_popup((WCHAR*)GetString(STR_ID_FONT_MGR_UNINSTALL_FAIL), MMI_FONT_MGR_FAIL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_menu_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ret mmi_font_mgr_menu_handler(cui_menu_event_struct *evt, mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_ITEM_SELECT:
    case EVT_ID_CUI_MENU_ITEM_TAP:
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        if (evt->highlighted_menu_id == MENU_ID_FONT_MGR_SETTING)
        {
            mmi_font_mgr_list_font_family(parent_gid);
            return MMI_RET_OK;
        }
    default:
        break;            
    }
    return MMI_RET_DONT_CARE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_option_handler
 * DESCRIPTION
 *  options handler
 * PARAMETERS
 *  item_id       : [IN]       menu item id
 *  filepath      : [IN]       file path
 *  fileinfo      : [IN]       file information
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_font_mgr_option_handler(mmi_menu_id item_id, const WCHAR* filepath, 
                     const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    //mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    // execute this menu¡¯s functionality
    switch (item_id)
    {
    case MENU_FMGR_VECTOR_FONT_OPTION_INSTALL:
        mmi_font_mgr_install_new_font_int((S8 *)filepath);
        break;
/*
    case MENU_FMGR_VECTOR_FONT_OPTION_UNINSTALL:
        if (g_mmi_font_mgr_intall_font_number != 0)
        {
            for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
            {
                if (mmi_ucs2cmp((const S8*)filepath, (const S8*)(&g_mmi_font_mgr_font_file_resource[i].name)) == 0)
                {
                    g_mmi_font_mgr_uninstall_index = i;
                    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
                    arg.callback = (mmi_proc_func)mmi_font_mgr_uninstall_confirm_cb;
                    mmi_confirm_display((WCHAR *)GetString(STR_ID_FONT_MGR_UNINSTALL), MMI_EVENT_QUERY, &arg);
                    return;
                }
            }
        }
        mmi_font_mgr_show_popup((WCHAR*)GetString(STR_ID_FONT_MGR_UNINSTALL_FAIL), MMI_FONT_MGR_FAIL);
        break;
*/
    default:
        break;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_font_mgr_notify_hdlr
 * DESCRIPTION
 *  font mangager notify handler
 * PARAMETERS
 *  evt       : [IN]       event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_fmgr_font_mgr_notify_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_plug_event_struct *plug_evt;
    srv_fmgr_notification_format_event_struct *format_evt;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT ||
        evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT)
    {
        format_evt = (srv_fmgr_notification_format_event_struct*)evt;
        if (format_evt->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE)
        {
            mmi_font_mgr_drv_remove_hdlr((PS8)&format_evt->drv_letter);
        }
    }
    else if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
    {
        plug_evt = (srv_fmgr_notification_dev_plug_event_struct*)evt;
        for (i = 0; i < plug_evt->count; i++)
        {
            mmi_font_mgr_drv_remove_hdlr((S8*)&plug_evt->drv_letters[i]);
        }
    }

    return MMI_RET_OK;
}


#else


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_uninstall_font_ms_mode
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_font_mgr_uninstall_font_ms_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 priority_list[] = {-1};
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_mmi_font_mgr_intall_font_number)
    {
        GDI_LOCK;
        for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
        {
            FS_Close(g_mmi_font_mgr_font_file_resource[i].handle);
             g_mmi_font_mgr_font_file_resource[i].handle = 0;
        }
        memset(&g_mmi_font_mgr_font_file_resource, 0, sizeof(g_mmi_font_mgr_font_file_resource));
        mmi_fe_add_font_from_file(g_mmi_font_mgr_font_file_resource, 0, priority_list, MMI_TRUE);
        GDI_UNLOCK;
        memset(&g_mmi_font_mgr_priority_list, 0, sizeof(g_mmi_font_mgr_priority_list));
        g_mmi_font_mgr_intall_font_number = 0;
        g_mmi_font_mgr_priority_list[0] = -1;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_show_popup
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_show_popup(WCHAR* str, mmi_font_mgr_event_type_enum evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_nmgr_balloon_type_enum evt_type = MMI_NMGR_BALLOON_TYPE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	switch(evt)
	{
		case MMI_FONT_MGR_FAIL:
			evt_type = MMI_NMGR_BALLOON_TYPE_FAILURE;
			break;
		case MMI_FONT_MGR_ERROR:
			evt_type = MMI_NMGR_BALLOON_TYPE_INFO;
			break;
	}
	mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, evt_type, str);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_font_get_selected_font_priority
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
U8 mmi_font_get_selected_font_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_font_mgr_set_priority = g_mmi_font_mgr_highlight_font + 1;
	return (U8)g_mmi_font_mgr_set_priority;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_set_selected_font_priority
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_font_set_selected_font_priority(U8 priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_mmi_font_mgr_set_priority == (S32)priority)
	{
		return MMI_FALSE;
	}
	else
	{
	    g_mmi_font_mgr_set_priority = (S32)priority;
	}
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_set_selected_font
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_set_selected_font(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_font_mgr_highlight_font = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_get_font_list
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_get_font_list(U32 index, U8 **fontNamePtrs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < g_mmi_font_mgr_intall_font_number + 1)
    {
        /* system font */
        if (g_mmi_font_mgr_priority_list[index] == -1)
        {
            *fontNamePtrs = (PU8)GetString(STR_ID_FONT_MGR_SYSTEM_FONT);
        }
        else
        {
            *fontNamePtrs = (PU8)g_mmi_font_mgr_font_file_resource[g_mmi_font_mgr_priority_list[index]].fontName;
        }
    }
    else
    {
        //ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_get_font_options_count
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
U32 mmi_font_mgr_get_font_options_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for allowed external font number */
    if (g_mmi_font_mgr_max_ext_font_num == -1)
    {
        g_mmi_font_mgr_max_ext_font_num = FE_MAX_FONT_FILE_NUMBER - mmi_fe_get_system_font_number();
    }
    
    if (g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font] == -1)
    {
        /* system font */
        if (g_mmi_font_mgr_intall_font_number != 0)
        {
            count++; //STR_ID_FONT_MGR_CHANGE_PRIORITY
        }
    }
    else
    {
        count++; //STR_ID_FONT_MGR_CHANGE_PRIORITY
        count++; //STR_ID_FONT_MGR_UNINSTALL
    }

    if ((g_mmi_font_mgr_intall_font_number + 1) < FE_MAX_FONT_FILE_NUMBER && g_mmi_font_mgr_intall_font_number + 1 <= g_mmi_font_mgr_max_ext_font_num)
    {
        count++; //STR_ID_FONT_MGR_ADD_NEW_FONT
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_get_font_options_list
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_get_font_options_list(U32 index, U8 **fontOptionsPtrs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for allowed external font number */
    if (g_mmi_font_mgr_max_ext_font_num == -1)
    {
        g_mmi_font_mgr_max_ext_font_num = FE_MAX_FONT_FILE_NUMBER - mmi_fe_get_system_font_number();
    }
    
    if (g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font] == -1)
    {
        /* system font */
        if (g_mmi_font_mgr_intall_font_number != 0)
        {
            if(index == 0)
            {
                *fontOptionsPtrs = (PU8)GetString(STR_ID_FONT_MGR_CHANGE_PRIORITY);
            }
            if(index == 1)
            {
                if ((g_mmi_font_mgr_intall_font_number + 1) < FE_MAX_FONT_FILE_NUMBER && g_mmi_font_mgr_intall_font_number + 1 <= g_mmi_font_mgr_max_ext_font_num)
                {
                    *fontOptionsPtrs = (PU8)GetString(STR_ID_FONT_MGR_ADD_NEW_FONT);
                }
            }
        }
        else
        {
            if ((g_mmi_font_mgr_intall_font_number + 1) < FE_MAX_FONT_FILE_NUMBER && g_mmi_font_mgr_intall_font_number + 1 <= g_mmi_font_mgr_max_ext_font_num)
            {
                *fontOptionsPtrs = (PU8)GetString(STR_ID_FONT_MGR_ADD_NEW_FONT);
            }
        }
    }
    else
    {
        if(index == 0)
        {
            *fontOptionsPtrs = (PU8)GetString(STR_ID_FONT_MGR_CHANGE_PRIORITY);
        }
        else if(index == 1)
        {
            *fontOptionsPtrs = (PU8)GetString(STR_ID_FONT_MGR_UNINSTALL);
        }
        else if(index == 2)
        {
            if ((g_mmi_font_mgr_intall_font_number + 1) < FE_MAX_FONT_FILE_NUMBER && g_mmi_font_mgr_intall_font_number + 1 <= g_mmi_font_mgr_max_ext_font_num)
            {
                *fontOptionsPtrs = (PU8)GetString(STR_ID_FONT_MGR_ADD_NEW_FONT);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_is_system_font
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_font_mgr_is_system_font(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font] == -1)
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
 *  mmi_font_mgr_get_font_num
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
U32 mmi_font_mgr_get_font_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    return (g_mmi_font_mgr_intall_font_number + 1);
}


MMI_BOOL mmi_font_mgr_install_new_font(S8* file_name)
{
    return mmi_font_mgr_install_new_font_int(file_name);
}

void mmi_font_mgr_uninstall_font(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font];
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font] == -1)
    {
        MMI_ASSERT(0);
    }
    GDI_LOCK;
    mmi_font_mgr_font_uninstall_int(i);
    
    ret = mmi_font_mgr_font_change(MMI_TRUE);
    mmi_font_mgr_update_font_database();
    GDI_UNLOCK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_activate_font
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_activate_font(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_font_mgr_active_handler = MMI_FALSE;
    mmi_font_mgr_popup_activate_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_activate_cancel
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_activate_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_font_mgr_popup_activate_cancel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_activate_exit
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_activate_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_font_mgr_popup_activate_exit();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_usb_ms_plug_in_hdlr
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ret mmi_font_mgr_usb_ms_plug_in_hdlr(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 priority_list[] = {-1};
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_mmi_font_mgr_intall_font_number)
    {
        GDI_LOCK;
        for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
        {
            FS_Close(g_mmi_font_mgr_font_file_resource[i].handle);
             g_mmi_font_mgr_font_file_resource[i].handle = 0;
        }
        memset(&g_mmi_font_mgr_font_file_resource, 0, sizeof(g_mmi_font_mgr_font_file_resource));
        mmi_fe_add_font_from_file(g_mmi_font_mgr_font_file_resource, 0, priority_list, MMI_TRUE);
        GDI_UNLOCK;
        memset(&g_mmi_font_mgr_priority_list, 0, sizeof(g_mmi_font_mgr_priority_list));
        g_mmi_font_mgr_intall_font_number = 0;
        g_mmi_font_mgr_priority_list[0] = -1;
        //mmi_font_mgr_show_popup((WCHAR*)GetString(STR_ID_FONT_MGR_USB_PLUG_IN), MMI_FONT_MGR_ERROR);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_usb_ms_plug_out_hdlr
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ret mmi_font_mgr_usb_ms_plug_out_hdlr(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_fe_add_font_from_file(g_mmi_font_mgr_font_file_resource, g_mmi_font_mgr_intall_font_number, g_mmi_font_mgr_priority_list, MMI_TRUE);
    mmi_font_mgr_update_font_database();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_font_list_option_priority_change_handler
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_font_list_option_priority_change_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 priority = g_mmi_font_mgr_set_priority - 1;
    S16 old = g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font];
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    GDI_LOCK;
    if (priority == g_mmi_font_mgr_highlight_font)
    {
    }
    else
    {
        if (priority > g_mmi_font_mgr_highlight_font)
        {
            memmove(&g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font], &g_mmi_font_mgr_priority_list[g_mmi_font_mgr_highlight_font + 1], sizeof(S16)*(priority - g_mmi_font_mgr_highlight_font));
        }
        else
        {
            memmove(&g_mmi_font_mgr_priority_list[priority + 1], &g_mmi_font_mgr_priority_list[priority], sizeof(S16)*(g_mmi_font_mgr_highlight_font - priority));
        }
        g_mmi_font_mgr_priority_list[priority] = old;
        ret = mmi_font_mgr_font_change(MMI_TRUE);
        mmi_font_mgr_update_font_database();
    }
    GDI_UNLOCK;
#ifndef __COSMOS_MMI_PACKAGE__
    if(font_mgr_menu_cui_gid != GRP_ID_INVALID)
    {
        cui_menu_close(font_mgr_menu_cui_gid);
        font_mgr_menu_cui_gid = GRP_ID_INVALID;
    }
    mmi_frm_scrn_close(GRP_ID_FONT_MGR, SCR_ID_FONT_MGR_FONT_LIST_SET_PRIORITY);
#endif
    mmi_font_mgr_show_popup((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_FONT_MGR_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_display_error_popup
 * DESCRIPTION
 *  To display popup message
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_ret mmi_font_mgr_display_error_popup(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_font_mgr_err_evt_struct* event = (mmi_font_mgr_err_evt_struct*)param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
#if defined(MMI_FONT_MGR_ERROR_CHANGE_LANG)
    SSCHandleSSCString((const S8*)MMI_FONT_MGR_LANG_CODE, STR_ID_FONT_MGR_LANG_CHANGE_SUCCESS, STR_ID_FONT_MGR_LANG_CHANGE_FAIL);
#endif
    
    mmi_font_mgr_show_popup((WCHAR*)GetString(event->error_msg), MMI_FONT_MGR_ERROR);
    g_mmi_font_mgr_error_code = 0;
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_drv_remove_hdlr
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_font_mgr_drv_remove_hdlr(S8* drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    UI_character_type driver = drv_letter[0];
    UI_character_type disk;
    MMI_BOOL is_changed = MMI_FALSE;
    MMI_BOOL is_freeze;
    S32 match_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    is_freeze = gdi_lcd_get_freeze();
    GDI_LOCK;
    gdi_lcd_freeze(MMI_TRUE);
    for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
    {
        disk = g_mmi_font_mgr_font_file_resource[i].name[0]; 
        if (disk == driver)
        {
            match_num ++;
            is_changed = MMI_TRUE;
        }
    }

    while (match_num)
    {
        for (i = 0; i < g_mmi_font_mgr_intall_font_number; i ++)
        {
            disk = g_mmi_font_mgr_font_file_resource[i].name[0]; 
            if (disk == driver)
            {
                mmi_font_mgr_font_uninstall_int(i);
                match_num --;
                break;
            }
        }
        
    }

    if (is_changed)
    {
        mmi_font_mgr_font_change(MMI_TRUE);
        mmi_font_mgr_update_font_database();
        disk = g_mmi_font_mgr_temp_name[0];
        if (disk == driver)
        {
            memset(g_mmi_font_mgr_temp_name, 0, sizeof(g_mmi_font_mgr_temp_name));
        }
    }

#ifndef __COSMOS_MMI_PACKAGE__
    if(font_mgr_gid != GRP_ID_INVALID)
    {
        cui_file_selector_close(font_mgr_gid);
        font_mgr_gid = GRP_ID_INVALID;
    }
    if(font_mgr_menu_cui_gid != GRP_ID_INVALID)
    {
        cui_menu_close(font_mgr_menu_cui_gid);
        font_mgr_menu_cui_gid = GRP_ID_INVALID;
    }
#endif

    if (is_changed)
    {
#ifndef __COSMOS_MMI_PACKAGE__
        if (mmi_frm_scrn_get_active_id() == SCR_ID_FONT_MGR_FONT_LIST_SET_PRIORITY)
        {
            mmi_frm_scrn_close_active_id();
        }
        else if(mmi_frm_scrn_is_present(GRP_ID_FONT_MGR, SCR_ID_FONT_MGR_FONT_LIST_SET_PRIORITY, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_FONT_MGR, SCR_ID_FONT_MGR_FONT_LIST_SET_PRIORITY);
        }
        mmi_font_mgr_show_popup((WCHAR*)GetString(STR_ID_FONT_MGR_INSTALLED_FONT_REMOVED), MMI_FONT_MGR_ERROR);
#endif
    }
    gdi_lcd_freeze(is_freeze);
    GDI_UNLOCK;
    gdi_lcd_repaint_all();
    g_mmi_font_mgr_data_change = MMI_TRUE;
    return is_changed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_error_handler
 * DESCRIPTION
 *  To reset all installed font.
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_font_mgr_error_handler(U32 err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_font_mgr_err_evt_struct event;
    S32 match_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    if (g_mmi_font_mgr_intall_font_number)
    {
        switch (err)
        {
            case MMI_FE_FONT_ERR_INSUFFICIENT_MEMORY:
                mmi_font_mgr_reset_all();
                MMI_FRM_INIT_EVENT(&event, EVT_ID_FONT_MGR_ERROR);
                event.error_msg = STR_ID_FONT_MGR_RESET_TO_SYSTEM_FONT;
                if (!mmi_frm_is_event_posted((mmi_event_struct*)&event))
                {
                    MMI_FRM_CB_EMIT_POST_EVENT(&event);
                }
                break;
#if 0
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
#endif                
            case MMI_FE_FONT_ERR_INIT_TIME_OUT:
                mmi_font_mgr_reset_all();
                MMI_FRM_INIT_EVENT(&event, EVT_ID_FONT_MGR_ERROR);
                event.error_msg = STR_ID_FONT_MGR_READ_TIME_OUT;
                if (!mmi_frm_is_event_posted((mmi_event_struct*)&event))
                {
                    MMI_FRM_CB_EMIT_POST_EVENT(&event);
                }
                break;
                
        }
        g_mmi_font_mgr_error_code = err;

        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_get_font_info
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_get_font_info(mmi_font_mgr_font_file_resource_struct** font, S32* num, S16** priority_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_mmi_font_mgr_is_init)
    {
        *font = g_mmi_font_mgr_font_file_resource;
        *num = g_mmi_font_mgr_intall_font_number;
        *priority_list = g_mmi_font_mgr_priority_list;
    }
    else
    {
        num = 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_get_checksum
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static S32 mmi_font_mgr_get_checksum(FS_HANDLE fileHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_FileInfo fileInfo;
	mmi_font_mgr_last_modified_date_union last_modified_date; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	if (fileHandle < 0)
    {
        MMI_DBG_ASSERT(0);
    }
    //FS_Seek(fileHandle, 0, );  Not sure if we need to Seek
    
	if (FS_GetFileInfo(fileHandle, &fileInfo) == FS_NO_ERROR)
    {
        last_modified_date.date_time =  fileInfo.DirEntry->DateTime;
        return last_modified_date.last_modified;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_font_mgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    int ret_val;
    FS_HANDLE file_handle = 0;
    FS_HANDLE font_handle = 0;
    U32 readed_size;
    S32 file_name_size, font_name_size, checksum;
    S32 token;
    MMI_BOOL isThereFont = MMI_TRUE;
    S32 font_index = -1;    
    S32 font_file_size = 0;
    UI_character_type temp_font_name[64];
    MMI_BOOL is_init_fail = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
#if defined(__MMI_FE_VECTOR_FONT_ON_MEMORY_CARD__)
    memset(&g_mmi_font_mgr_font_file_resource, 0, sizeof(g_mmi_font_mgr_font_file_resource));
#endif

    g_mmi_font_mgr_max_ext_font_num = -1;

    do
    {

        ret_val = FS_SetCurrentDir(MMI_FONT_MGR_DATABASE_PATH);
        if (ret_val)
        {
            ret_val = FS_CreateDir(MMI_FONT_MGR_DATABASE_PATH);
            if (ret_val)
            {
                g_mmi_font_mgr_is_init = MMI_FALSE;
                return MMI_FALSE;
            }
            ret_val = FS_SetCurrentDir(MMI_FONT_MGR_DATABASE_PATH);
            if (ret_val)
            {
                g_mmi_font_mgr_is_init = MMI_FALSE;
                return MMI_FALSE;
            }
            isThereFont = MMI_FALSE;
        }

        
        FS_SetAttributes(MMI_FONT_MGR_DATABASE_FILE, FS_ATTR_ARCHIVE);

        /* try to open file */
        file_handle = FS_Open(MMI_FONT_MGR_DATABASE_FILE, FS_READ_WRITE | FS_ATTR_ARCHIVE);
        if (file_handle < 0)    /* failed to open existing file, or file not exists */
        {
            /* try to create file */
            file_handle = FS_Open(MMI_FONT_MGR_DATABASE_FILE, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_ARCHIVE);
            isThereFont = MMI_FALSE;
        }
        else
        {
            ret_val = FS_GetFileSize(file_handle, (U32*)&font_file_size);
            if (ret_val)
            {
                MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_GET_FILE_SIZE_ERROR, 0xFF, file_handle, ret_val);
                g_mmi_font_mgr_is_init = MMI_FALSE;
                break;
            }
        }

        /* unable to read the font database */
        if (!isThereFont || file_handle < 0 || font_file_size == 0)
        {
            g_mmi_font_mgr_intall_font_number = 0;
            g_mmi_font_mgr_priority_list[0] = -1;
            g_mmi_font_mgr_is_init = MMI_TRUE;
        }
        else
        {
            ret_val = FS_Read(file_handle, (void*)&g_mmi_font_mgr_intall_font_number, 4, &readed_size);
            if (readed_size != 4 || ret_val)
            {
                g_mmi_font_mgr_is_init = MMI_FALSE;
                break;
            }
            
            for (i = 0; i < g_mmi_font_mgr_intall_font_number; i++)
            {
                ret_val = FS_Read(file_handle, (void*)&file_name_size, 4, &readed_size);
                if (readed_size != 4 || ret_val)
                {
                    g_mmi_font_mgr_is_init = MMI_FALSE;
                    return MMI_FALSE;
                }

                /* the system font */
                if (file_name_size == 0xFFFFFFFF)
                {
                    g_mmi_font_mgr_priority_list[j] = -1;
                    j ++;
                    ret_val = FS_Read(file_handle, (void*)&token, 4, &readed_size);
                    if (readed_size != 4 || ret_val)
                    {
                        g_mmi_font_mgr_is_init = MMI_FALSE;
                        break;
                    }
                }
                else
                {                               
                    /* to get font name size */
                    ret_val = FS_Read(file_handle, (void*)&font_name_size, 4, &readed_size);
                    if (readed_size != 4 || ret_val)
                    {
                        g_mmi_font_mgr_is_init = MMI_FALSE;
                        break;
                    }
                    /* to read font path */
                    ret_val = FS_Read(file_handle, (void*)g_mmi_font_mgr_temp_name, file_name_size, &readed_size);
                    g_mmi_font_mgr_temp_name[file_name_size/2] = 0x00;					
                    if (readed_size != file_name_size || ret_val)
                    {
                        g_mmi_font_mgr_is_init = MMI_FALSE;
                        break;
                    }
                    /* to read font name */
                    ret_val = FS_Read(file_handle, (void*)temp_font_name, font_name_size, &readed_size);
                    if (readed_size != font_name_size || ret_val)
                    {
                        g_mmi_font_mgr_is_init = MMI_FALSE;
                        break;
                    } 

                    /* to get checksum */
                    ret_val = FS_Read(file_handle, (void*)&checksum, 4, &readed_size);
                    if (readed_size != 4 || ret_val)
                    {
                        g_mmi_font_mgr_is_init = MMI_FALSE;
                        break;
                    }

                    /* try to open font */
                    font_handle = FS_Open((UI_string_type)g_mmi_font_mgr_temp_name, FS_READ_ONLY);
                    if (font_handle > 0)
                    {
                        token = mmi_font_mgr_get_checksum(font_handle);
                        if(token != checksum)
                        {
                            /* Ignore the font */
                            //show popup = TRUE; // maybe we cant show coz phone's booting up
                            FS_Close(font_handle);
                            continue;
                        }
                        font_index++;
                        FS_Close(font_handle);
                        g_mmi_font_mgr_priority_list[j] = font_index;
                        j ++;
                        memcpy(&g_mmi_font_mgr_font_file_resource[font_index].name, g_mmi_font_mgr_temp_name, file_name_size);
                        memcpy(&g_mmi_font_mgr_font_file_resource[font_index].fontName, temp_font_name, font_name_size);
                        g_mmi_font_mgr_font_file_resource[font_index].name[file_name_size/2] = 0;
                        g_mmi_font_mgr_font_file_resource[font_index].fontName[font_name_size/2] = 0;
                    }
                    else
                    {
                        is_init_fail = MMI_TRUE;
                    }
                    
                }
            }
            g_mmi_font_mgr_intall_font_number = font_index + 1;
            g_mmi_font_mgr_is_init = MMI_TRUE;


        }

    } while (0);

    if (file_handle)
    {
        FS_Close(file_handle);
    }

    /* initialize fail because font info file is not available or format is wrong */
    if (g_mmi_font_mgr_is_init == MMI_FALSE)
    {
        g_mmi_font_mgr_intall_font_number = 0;
        g_mmi_font_mgr_max_ext_font_num = -1;
        g_mmi_font_mgr_priority_list[0] = -1;
        g_mmi_font_mgr_is_init = MMI_TRUE;
        return MMI_FALSE;
    }

    /* some font on  */
    if (is_init_fail)
    {
        return MMI_FALSE;

    }

    return MMI_TRUE;    
}

#endif /* defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) */

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
extern mmi_preload_font_struct g_mmi_preload_font[FE_MAX_FONT_FILE_NUMBER];
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_get_font_file_handle
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void* mmi_font_mgr_get_font_file_handle(U16 resid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    if (g_mmi_font_mgr_intall_font_number && resid < g_mmi_font_mgr_intall_font_number)
    {
        return (void*)g_mmi_font_mgr_font_file_resource[resid].handle;
    }
    else
#endif
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
    if(resid > IMG_GLOBAL_FONT_MAX)
    {
        resid -= (IMG_GLOBAL_FONT_MAX+1);
        return (void*)g_mmi_preload_font[resid].handle;
    }
    else
#endif
    {
        ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_font_file_reader
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
unsigned long mmi_font_mgr_font_file_reader(void* handle, unsigned long offset, unsigned char* buffer, unsigned long count, unsigned long* read_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 error_code = MMI_FE_FONT_ERR_NONE;
    U32 readCnt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *read_cnt = 0;

    while (1)
    {
        if (FS_Seek((FS_HANDLE)handle, offset, FS_FILE_BEGIN) == offset/*FS_NO_ERROR*/)
        {
            if (count == 0 || buffer == NULL)
                return MMI_FE_FONT_ERR_NONE;        
            if (FS_Read((FS_HANDLE)handle, buffer, count, &readCnt) == FS_NO_ERROR)
            {
                *read_cnt = readCnt;
                return MMI_FE_FONT_ERR_NONE;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    /* when there is external font resource, try to reset to apply system font. */
    g_mmi_font_mgr_error_code = error_code;
#endif
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_font_file_closer
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_font_mgr_font_file_closer(void* handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    if (g_mmi_font_mgr_intall_font_number)
    {
        for (i = 0; i < g_mmi_font_mgr_intall_font_number; i++)
        {
            if (g_mmi_font_mgr_font_file_resource[i].handle == (FS_HANDLE)handle)
            {
                FS_Close((int)handle);
                g_mmi_font_mgr_font_file_resource[i].handle = 0;
            }
        }
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_mgr_open_font
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
MMI_BOOL mmi_font_mgr_open_font(U16 id, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    FS_HANDLE handle = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    if(id > IMG_GLOBAL_FONT_MAX)
    {
        id -= (IMG_GLOBAL_FONT_MAX+1);
        if (g_mmi_preload_font[id].handle)
        {
            handle = g_mmi_preload_font[id].handle;
            ret = FS_GetFileSize(handle, (U32*)size);
            if (ret)
            {
                MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_GET_FILE_SIZE_ERROR, id, handle, ret);
                MMI_ASSERT(0);            
            }
            return MMI_TRUE;
        }
    }
    else
#endif
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    {
        MMI_ASSERT(id < g_mmi_font_mgr_intall_font_number);

        if (g_mmi_font_mgr_font_file_resource[id].handle)
        {
            handle = g_mmi_font_mgr_font_file_resource[id].handle;
            //*enfb_handle = g_mmi_font_mgr_font_file_resource[id].handle;
            ret = FS_GetFileSize(handle, (U32*)size);
            if (ret)
            {
                MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_GET_FILE_SIZE_ERROR, id, handle, ret);
                MMI_ASSERT(0);            
            }
            return MMI_TRUE;
            
        }
        else
        {
            handle = FS_Open((UI_string_type) g_mmi_font_mgr_font_file_resource[id].name, FS_READ_ONLY);
            if (handle > 0)
            {
                FS_SetSeekHint(handle,MMI_FONT_MGR_MAX_HINT_NUM, g_mmi_font_mgr_font_file_resource[id].hint);
                g_mmi_font_mgr_font_file_resource[id].handle = handle;
                //*enfb_handle = handle;
                ret = FS_GetFileSize(handle, (U32*)size);
                if (ret)
                {
                    MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_GET_FILE_SIZE_ERROR, id, handle, ret);
                    MMI_ASSERT(0);
                }
                return MMI_TRUE;
            }
        }
    }
#endif
    return MMI_FALSE;
}

#endif

