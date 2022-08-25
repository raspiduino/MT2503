
#include "MMI_features.h"
#include "kmx_input_config.h"

#ifdef __MMI_KMX_TOUCH_INPUT__

#include "kmxsip_config.h"
#include "kmxsip_user_data.h"
#include "kmximmapi.h"

#include "mmi_features.h"
#include "GlobalConstants.h"
#include "gui_data_types.h"

#include "Fat_fs.h"
#include "mmi_trc_int.h"

static FS_HANDLE mmi_ime_cstar_open_file(PU16 path_name_ptr, PU16 file_name_ptr, MMI_BOOL is_create_always)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int ret_val;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NULL != path_name_ptr);
    MMI_ASSERT(NULL != file_name_ptr);

    ret_val = FS_SetCurrentDir(path_name_ptr);
    if (ret_val < 0)
    {
        ret_val = FS_CreateDir(path_name_ptr);
        if (ret_val < 0 )
        {
            return -1;
        }
        ret_val = FS_SetCurrentDir(path_name_ptr);
        if (ret_val < 0)
        {
            return -1;
        }
    }

    FS_SetAttributes(file_name_ptr, FS_ATTR_ARCHIVE);

    /* try to open file */
    file_handle = FS_Open(file_name_ptr, FS_READ_WRITE | FS_ATTR_ARCHIVE);
    if (file_handle < 0)    /* failed to open existing file, or file not exists */
    {
        if (MMI_FALSE == is_create_always)
        {
            return -1;
        }

        /* try to create file */
        file_handle = FS_Open(file_name_ptr, FS_READ_WRITE | FS_CREATE_ALWAYS | FS_ATTR_ARCHIVE);
        if (file_handle < 0)
        {
            return -1;
        }
    }

    return file_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_close_file
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 ****************************************************************************/
static void mmi_ime_cstar_close_file(FS_HANDLE file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_handle < 0)
        return;

    FS_Close(file_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_write_file
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static U32 mmi_ime_cstar_write_file(FS_HANDLE file_handle, PU16 data_ptr, U32 size_in_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret_val;
    U32 writen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_handle < 0)
        return 0;

    writen = 0;
    ret_val = FS_Write(file_handle, (void*)data_ptr, size_in_byte, &writen);
    if (ret_val < 0)
        return 0;

    return writen;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ime_cstar_read_file
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static U32 mmi_ime_cstar_read_file(FS_HANDLE file_handle, PU16 data_ptr, U32 size_in_byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret_val;
    U32 readed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_handle < 0)
        return 0;

    readed = 0;
    ret_val = FS_Read(file_handle, (void*)data_ptr, size_in_byte, &readed);
    if (ret_val < 0)
        return 0;

    return readed;
}

#ifdef KMX_CFG_USER_DATA_08

void load_user_data(
    void*           buffer,
    int             size)
{
    FS_HANDLE file_handle;
    file_handle = mmi_ime_cstar_open_file(KMX_USER_DATA_PATH_NAME, KMX_USER_DATA_FILE_NAME, MMI_TRUE);

    if(file_handle == -1)
    {
        MMI_ASSERT(MMI_FALSE);
        return;
    }
    
    mmi_ime_cstar_read_file(file_handle, (PU16)buffer, size);

    mmi_ime_cstar_close_file(file_handle);
    
}

void save_user_data(
    const void*     buffer,
    int             size)
{

    FS_HANDLE file_handle;
    file_handle = mmi_ime_cstar_open_file(KMX_USER_DATA_PATH_NAME, KMX_USER_DATA_FILE_NAME, MMI_TRUE);

    if(file_handle == -1)
    {
        MMI_ASSERT(MMI_FALSE);
        return;
    }
    
    mmi_ime_cstar_write_file(file_handle, (PU16)buffer, size);

    mmi_ime_cstar_close_file(file_handle);
    
}

#endif /* #ifdef KMX_CFG_USER_DATA_08 */

KMX_USER_PROFILE kmx_user_profile = {1, KMX_KEYBOARD_TYPE_DIGIT};
static int kmx_user_profile_loaded = 0;

void load_ime_user_setting(void)
{
    FS_HANDLE file_handle;    

    if (kmx_user_profile_loaded)
        return;

    file_handle = mmi_ime_cstar_open_file(MMI_KMX_IME_SETTING_PATH, MMI_KMX_IME_SETTING_FILE, MMI_TRUE);
    
    if(file_handle == -1)
    {
        MMI_ASSERT(MMI_FALSE);
        return;
    }

    mmi_ime_cstar_read_file(file_handle, (PU16)&kmx_user_profile, sizeof(kmx_user_profile));

    mmi_ime_cstar_close_file(file_handle);

    kmx_user_profile_loaded = 1;    
}

void save_ime_user_setting(void)
{
    FS_HANDLE file_handle;
    file_handle = mmi_ime_cstar_open_file(MMI_KMX_IME_SETTING_PATH, MMI_KMX_IME_SETTING_FILE, MMI_TRUE);

    if(file_handle == -1)
    {
        MMI_ASSERT(MMI_FALSE);
        return;
    }
    
    mmi_ime_cstar_write_file(file_handle, (PU16)&kmx_user_profile,  sizeof(kmx_user_profile));

    mmi_ime_cstar_close_file(file_handle);
}

#endif /* #ifdef __MMI_KMX_TOUCH_INPUT__ */
