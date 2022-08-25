#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#ifdef __MMI_NCENTER_SUPPORT__


#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"
#include "Wgui_categories_util.h"

#include "emailsrvgprot.h"
#include "vsrv_ncenter.h"

#include "EmailAppGProt.h"
#include "EmailAppNCenter.h"
#include "EmailAppNetwork.h"

#define EMAIL_NC_BUF_LEN 128
typedef struct
{
    EMAIL_ACCT_ID acc_id;
    vsrv_notification_handle ongoing_nhandle;
    vsrv_notification_handle err_handle;
    S32 err_code;
}email_nc_map_struct;

static WCHAR ctext[EMAIL_NC_BUF_LEN + 1];
static email_nc_map_struct g_nc_list[MMI_EMAIL_MAX_ACCTS];

static S32 g_email_nc_total;
static vsrv_ngroup_handle g_email_nc_ghandle;
static vsrv_notification_handle g_email_nc_newmail_nhandle;


static void mmi_email_ncenter_newmail_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize);
static void mmi_email_ncenter_error_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize);
static void mmi_email_ncenter_ongoing_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize);


static WCHAR* error_get_filename(void);
static void error_read(void);
static void error_write(void);
//static void error_restore(void);


static WCHAR *get_acct_name(EMAIL_ACCT_ID acc_id)
{
    srv_email_acct_get_name(
        acc_id, 
        ctext, 
        EMAIL_NC_BUF_LEN);
    ctext[EMAIL_NC_BUF_LEN] = 0;

    return ctext;
}


static void create_event_ngroup(void)
{
    g_email_nc_ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_EMAIL);
    vsrv_ncenter_set_ngroup_title_id(g_email_nc_ghandle, STR_GLOBAL_EMAIL);
}

/*static vsrv_notification_handle get_err_handle(EMAIL_ACCT_ID acc_id)
{
    S32 i;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == acc_id)
        {
            return g_nc_list[i].err_handle;
        }
    }

    return NULL;
}*/


/*static vsrv_notification_handle get_onging_handle(EMAIL_ACCT_ID acc_id)
{
    S32 i;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == acc_id)
        {
            return g_nc_list[i].ongoing_nhandle;
        }
    }

    return NULL;
}*/

static void add_ongoing_handle(EMAIL_ACCT_ID acc_id, vsrv_notification_handle h)
{
    S32 i;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == acc_id)
        {
            g_nc_list[i].ongoing_nhandle = h;
            return;
        }
    }

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == 0)
        {
            g_nc_list[i].acc_id = acc_id;
            g_nc_list[i].ongoing_nhandle = h;
            return;
        }
    }

    ASSERT(0);
}

static void add_err_handle(EMAIL_ACCT_ID acc_id, S32 err_code, vsrv_notification_handle h)
{
    S32 i;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == acc_id)
        {
            g_nc_list[i].err_handle = h;
            g_nc_list[i].err_code = err_code;
            return;
        }
    }

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == 0)
        {
            g_nc_list[i].acc_id = acc_id;
            g_nc_list[i].err_handle = h;
            g_nc_list[i].err_code = err_code;
            return;
        }
    }

    ASSERT(0);
}


static void remove_ongoing_handle(EMAIL_ACCT_ID acc_id)
{
    S32 i;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == acc_id)
        {
            vsrv_ncenter_close_notification(g_nc_list[i].ongoing_nhandle);
            g_nc_list[i].ongoing_nhandle = NULL;
            if (g_nc_list[i].err_handle == NULL)
            {
                g_nc_list[i].acc_id = 0;
            }
            return;
        }
    }
}


static void remove_err_handle(EMAIL_ACCT_ID acc_id)
{
    S32 i;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == acc_id)
        {
            vsrv_ncenter_close_notification(g_nc_list[i].err_handle);
            g_nc_list[i].err_handle = NULL;
            g_nc_list[i].err_code = 0;

            if (g_nc_list[i].ongoing_nhandle == NULL)
            {
                g_nc_list[i].acc_id = 0;
            }

            error_write();
            return;
        }
    }


}


void mmi_email_ncenter_delaccount(EMAIL_ACCT_ID acc_id)
{
    // Clear all ONGOING ERROR 
    remove_err_handle(acc_id);
    remove_ongoing_handle(acc_id);
}

void mmi_email_ncenter_deinit(void)
{
    S32 i;

    vsrv_ncenter_close_notification(g_email_nc_newmail_nhandle);
    g_email_nc_newmail_nhandle = NULL;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id != 0)
        {
            if (g_nc_list[i].err_handle != NULL)
            {
                vsrv_ncenter_close_notification(g_nc_list[i].err_handle);
                g_nc_list[i].err_handle = NULL;
            }

            if (g_nc_list[i].ongoing_nhandle != NULL)
            {
                vsrv_ncenter_close_notification(g_nc_list[i].ongoing_nhandle);
                g_nc_list[i].ongoing_nhandle = NULL;
            }

            g_nc_list[i].acc_id = 0;
        }
    }
}


void mmi_email_ncenter_newmail(S32 total)
{
    g_email_nc_total = total;
    if (total == 0)
    {
        if (g_email_nc_newmail_nhandle != NULL)
        {
            vsrv_ncenter_close_notification(g_email_nc_newmail_nhandle);
            g_email_nc_newmail_nhandle = NULL;
        }
        return;
    }

    create_event_ngroup();

    if (g_email_nc_newmail_nhandle == NULL)
    {
        g_email_nc_newmail_nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, g_email_nc_ghandle, 0);
        vsrv_ncenter_set_notification_intent_callback(g_email_nc_newmail_nhandle, mmi_email_ncenter_newmail_callback, NULL, 0);
    }

    kal_wsprintf(ctext, "%d ", g_email_nc_total);
    kal_wstrncat(ctext, (WCHAR*)GetString(STR_EMAIL_NCENTER_NEWMAIL), EMAIL_NC_BUF_LEN - kal_wstrlen(ctext));

    vsrv_ncenter_set_notification_maintext_str(g_email_nc_newmail_nhandle, ctext);
    vsrv_ncenter_notify_notification(g_email_nc_newmail_nhandle); 
}



static void mmi_email_ncenter_newmail_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
     if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
     {
         g_email_nc_newmail_nhandle = NULL;
         mmi_email_cmcc_new_email_hdlr();
     }
     else if (intent.type == VSRV_NINTENT_TYPE_CLEAR)
     {
         g_email_nc_newmail_nhandle = NULL;
         remove_all_received_number();
     }
     else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
     {
         if (g_email_nc_newmail_nhandle != NULL && g_email_nc_total > 0)
         {
             kal_wsprintf(ctext, "%d ", g_email_nc_total);
             kal_wstrncat(ctext, (WCHAR*)GetString(STR_EMAIL_NCENTER_NEWMAIL), EMAIL_NC_BUF_LEN - kal_wstrlen(ctext));

             vsrv_ncenter_set_notification_maintext_str(g_email_nc_newmail_nhandle, ctext);
             vsrv_ncenter_notify_notification(g_email_nc_newmail_nhandle); 
         }
     }
}




void mmi_email_ncenter_error(EMAIL_ACCT_ID acc_id, S32 error_code)
{
    vsrv_notification_handle nhandle;

    remove_err_handle(acc_id);
    create_event_ngroup();

    nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, g_email_nc_ghandle, acc_id);
    add_err_handle(acc_id, error_code, nhandle);

    vsrv_ncenter_set_notification_maintext_str(nhandle, get_acct_name(acc_id));

    kal_wstrncpy(ctext, (WCHAR*)GetString(STR_EMAIL_NCENTER_ERROR), EMAIL_NC_BUF_LEN);
    kal_wstrncat(ctext, (WCHAR*)GetString(error_code), EMAIL_NC_BUF_LEN - kal_wstrlen(ctext));
    vsrv_ncenter_set_notification_subtext_str(nhandle, ctext);

    vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_email_ncenter_error_callback, (void*)&acc_id, 4);
    vsrv_ncenter_notify_notification(nhandle); 

    //Write to FILESYSTEM
    error_write();
}

static void refresh_error(vsrv_notification_handle nhandle, EMAIL_ACCT_ID acc_id)
{
    S32 i;

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id == acc_id && g_nc_list[i].err_handle == nhandle)
        {
            kal_wstrncpy(ctext, (WCHAR*)GetString(STR_EMAIL_NCENTER_ERROR), EMAIL_NC_BUF_LEN);
            kal_wstrncat(ctext, (WCHAR*)GetString(g_nc_list[i].err_code), EMAIL_NC_BUF_LEN - kal_wstrlen(ctext));
            vsrv_ncenter_set_notification_subtext_str(nhandle, ctext);

            vsrv_ncenter_notify_notification(nhandle); 
            return;
        }
    }
}

static void mmi_email_ncenter_error_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
     if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
     {
         mmi_email_entry_main_screen_from_cosmos(NULL, 0);
         remove_err_handle((EMAIL_ACCT_ID)(*(EMAIL_ACCT_ID*)userData));
     }
     else if (intent.type == VSRV_NINTENT_TYPE_CLEAR)
     {
         remove_err_handle((EMAIL_ACCT_ID)(*(EMAIL_ACCT_ID*)userData));
     }
     else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
     {
         refresh_error(nhandle, (EMAIL_ACCT_ID)(*(EMAIL_ACCT_ID*)userData));
     }
}







void mmi_email_ncenter_ongoing_start(EMAIL_ACCT_ID acc_id, MMI_BOOL refreshing)
{
    vsrv_notification_handle nhandle;
    mmi_email_ncenter_ongoing_done(acc_id);
    remove_err_handle(acc_id);

    create_event_ngroup();

    nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING, g_email_nc_ghandle, acc_id + 100);
    vsrv_ncenter_set_notification_autoclose(nhandle, FALSE, VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_TERMINATE);
    add_ongoing_handle(acc_id, nhandle);

    vsrv_ncenter_set_notification_maintext_id(nhandle, refreshing ? STR_EMAIL_NCENTER_REFRESHING : STR_EMAIL_NCENTER_SENDING);
    vsrv_ncenter_set_notification_subtext_str(nhandle, get_acct_name(acc_id));
    vsrv_ncenter_set_notification_questiontext_id(nhandle, refreshing ? STR_EMAIL_NCENTER_STOP_REFRESH : STR_EMAIL_NCENTER_STOP_SEND);
    vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_email_ncenter_ongoing_callback, (void*)&acc_id, 4);
    vsrv_ncenter_notify_notification(nhandle);
}


void mmi_email_ncenter_ongoing_done(EMAIL_ACCT_ID acc_id)
{
    remove_ongoing_handle(acc_id);
}


static void mmi_email_ncenter_ongoing_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        mmi_email_entry_main_screen_from_cosmos(NULL, 0);
    }
    else if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
    {
        mmi_email_app_nwk_user_abort((EMAIL_ACCT_ID)(*(EMAIL_ACCT_ID*)userData));
    }
}



void mmi_email_ncenter_restore_error(void)
{
    S32 i;

    error_read();

    for (i = 0; i < MMI_EMAIL_MAX_ACCTS; i++)
    {
        if (g_nc_list[i].acc_id != 0 && g_nc_list[i].err_code != 0)
        {
            mmi_email_ncenter_error(g_nc_list[i].acc_id, g_nc_list[i].err_code);
        }
        else
        {
            memset(&g_nc_list[i], 0, sizeof(email_nc_map_struct));
        }
    }
}


static WCHAR* error_get_filename(void)
{
    static WCHAR filename[32];

    kal_wsprintf(filename, "%slasterrornoti", srv_email_get_root_path());

    return filename;
}

static void error_read(void)
{
    U32 readed = 0;
    FS_HANDLE h = 0;

    h = FS_Open(error_get_filename(), FS_READ_ONLY);
    if (h >= 0)
    {
        FS_Read(h, &g_nc_list, sizeof(g_nc_list), &readed);
        FS_Close(h);
    }

    if (readed != sizeof(g_nc_list))
    {
        memset(&g_nc_list, 0, sizeof(g_nc_list));
    }
}

static void error_write(void)
{
    FS_HANDLE h = 0;
    h = FS_Open(error_get_filename(), FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (h < 0)
    {
        return;
    }

    FS_Write(h, &g_nc_list, sizeof(g_nc_list), NULL);
    FS_Close(h);
}



#endif /* __MMI_NCENTER_SUPPORT__ */
#endif /* __MMI_EMAIL__ */

