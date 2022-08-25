
#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#ifdef __MMI_SSO__

#include "stdlib.h"
#include "string.h"

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"

#include "emailsrvgprot.h"
#include "EmailSrvIprot.h"
#include "SsoCuiGprot.h"
#include "EmailAppProt.h"
#include "EmailAppLib.h"
#include "EmailAppSSO.h"
#include "EmailAppAccount.h"
#include "EmailAppAccountData.h"
#include "EmailAppStateMgr.h"
#include "EmailAppNetwork.h"
#include "EmailAppLib.h"
#include "SsoSrvGprot.h"

static EMAIL_ACCT_ID g_sso_sel_acct = 0;
static FuncPtr g_sso_user_callback = NULL;

static void sso_replace_confirm_enter(void);
static void sso_replace_confirm_yes(void);
static void sso_replace_confirm_no(void);

static void sso_add_confirm_enter(void);
static void sso_add_confirm_yes(void);
static void sso_add_confirm_no(void);

static void sso_add_account(void);
static void sso_delete_account(EMAIL_ACCT_ID acct);
//static void sso_modify_addr(WCHAR *addr, EMAIL_ACCT_ID id);

static void sso_done(void);


static WCHAR *sso_get_yahoo_account(void);
static EMAIL_ACCT_ID email_get_yahoo_account(void);
static EMAIL_ACCT_ID email_sso_compare(WCHAR* yahoo);

MMI_BOOL mmi_email_sso_is_cloud_account(EMAIL_ACCT_ID id)
{
    srv_email_acct_info_cache_struct cache;
    srv_email_acct_cache_get(id, &cache);

    return cache.is_cloud_acct;
}


MMI_BOOL mmi_email_sso_precheck(FuncPtr cb)
{
    static MMI_BOOL confirmed = MMI_FALSE;

    WCHAR *yahoo;
    EMAIL_ACCT_ID id = 0;

    g_sso_user_callback = NULL;
    g_sso_sel_acct = 0;

    yahoo = sso_get_yahoo_account();
    id = email_get_yahoo_account();

    if (id == 0)
    {
        if (yahoo == NULL)
        {
            return MMI_FALSE;
        }
        else
        {
            id = email_sso_compare(yahoo);
            if (id == 0)
            {
                // Has SSO account, ASK user import or not
                if (confirmed)
                {
                    return MMI_FALSE;
                }
                confirmed = MMI_TRUE;
                g_sso_user_callback = cb;
                sso_add_confirm_enter();
                return MMI_TRUE;
            }
            else
            {
                // Set confirmed in case of user delete this imported account later
                confirmed = MMI_TRUE;

                // just set it as cloud 
                srv_email_acct_set_cloud_acct(id, MMI_TRUE);

                // Disable AUTO-CHECK, PUSH
#ifdef __MMI_EMAIL_IMAP_PUSH__
                if (email_mmi_account_data_get_push() == id)
                {
                    mmi_email_app_network_push_stop(FALSE);
                    email_mmi_account_data_set_push(EMAIL_ACCT_INVALID_ID);
                }
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

                return MMI_FALSE;
            }
        }
    }
    else
    {
        if (yahoo == NULL)
        {
            // Set it as common account
            srv_email_acct_set_cloud_acct(id, MMI_FALSE);
            return MMI_FALSE;
        }
        else
        {
            if (email_sso_compare(yahoo) == id)
            {
                // Set confirmed in case of user delete this imported account later
                confirmed = MMI_TRUE;
                return MMI_FALSE;
            }
            else
            {
                // First set the OLD cloud account as common account
                srv_email_acct_set_cloud_acct(id, MMI_FALSE);

                // Step 2:Ask user to import new ONE or NOT
                if (confirmed)
                {
                    return MMI_FALSE;
                }
                confirmed = MMI_TRUE;
                g_sso_user_callback = cb;
                sso_add_confirm_enter();
                return MMI_TRUE;
            }
        }
    }
}


static S32 email_sso_wchar_compare(WCHAR *s1, WCHAR *s2)
{
    S32 i = 0;
    char c1, c2;
    if (s1 == NULL || s2 == NULL)
    {
        return s1 - s2;
    }

    for (i = 0; s1[i] != 0 && s2[i] != 0; i++)
    {
        c1 = (char)s1[i];
        c2 = (char)s2[i];

        if (c1 >= 'a' && c1 <= 'z')
        {
            c1 += 'A' - 'a';
        }

        if (c2 >= 'a' && c2 <= 'z')
        {
            c2 += 'A' - 'a';
        }

        if (c1 != c2)
        {
            return c1 - c2;
        }
    }

    return s1[i] - s2[i];
}


static EMAIL_ACCT_ID email_sso_compare(WCHAR* yahoo)
{
    U32 i, cnt;
    EMAIL_ACCT_ID id;
    srv_email_acct_info_cache_struct cache;

    cnt = email_mmi_account_data_get_count();
    for (i = 0;i < cnt; i++)
    {
        id = email_mmi_account_data_get_id(i);
        srv_email_acct_cache_get(id, &cache);
        if (email_sso_wchar_compare(yahoo, cache.acct_addr) == 0
            && cache.protocol == SRV_EMAIL_PROT_IMAP4)
        {
            return id;
        }
    }

    return 0;
}

static EMAIL_ACCT_ID email_get_yahoo_account(void)
{
    U32 i, cnt;
    EMAIL_ACCT_ID id;
    srv_email_acct_info_cache_struct cache;

    cnt = email_mmi_account_data_get_count();
    for (i = 0;i < cnt; i++)
    {
        id = email_mmi_account_data_get_id(i);
        srv_email_acct_cache_get(id, &cache);
        if (cache.is_cloud_acct)
        {
            return id;
        }
    }

    return 0;
}


static WCHAR *sso_get_yahoo_account(void)
{
    U8 i, cnt;
    srv_sso_provider_struct sso_prv_list[5];
    srv_sso_account_struct sso_acc;
    static WCHAR name[SRV_SSO_NAME_SIZE + 1];

    cnt = srv_sso_get_providers(sso_prv_list, 5);

    cnt = srv_sso_get_provider_count();
    for (i = 0; i < cnt && i < 5; i++)
    {
        if (srv_sso_get_account_count(sso_prv_list[i].provider, SRV_SSO_LOGIN_DONT_CARE) > 0)
        {
            srv_sso_get_accounts(sso_prv_list[i].provider, SRV_SSO_LOGIN_DONT_CARE, &sso_acc, 1);

            // Yahoo only have one account now
            srv_sso_get_account_name(sso_prv_list[i].provider, sso_acc.account, name);

            //if (strchr(name, "@yahoo") != NULL)
            {
                return name;
            }
        }
    }
    return NULL;
}


static void sso_done(void)
{
    if (g_sso_user_callback != NULL)
    {
        g_sso_user_callback();
        g_sso_user_callback = NULL;
    }
}

static void init_account(srv_email_acct_info_struct *p, WCHAR *addr)
{
    srv_email_acct_init_acct_info(p);
    p->is_cloud_acct = MMI_TRUE;

    // Copy address
    mmi_wcsncpy(p->email_addr.email_addr, addr, MMI_EMAIL_MAX_ADDR_LEN);
    mmi_wcsncpy(p->acct_name, addr, SRV_EMAIL_MAX_ACCT_NAME_LEN);
}


static void sso_add_account(void)
{
    EMAIL_ACCT_HANDLE h = 0;
    srv_email_result_enum s;
    EMAIL_ACCT_ID id;
    srv_email_acct_info_struct info;

    init_account(&info, sso_get_yahoo_account());

    s = SRV_EMAIL_RESULT_SUCC;
    do
    {
        s = srv_email_acct_create(0, &h);
        if (s != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }

        s = srv_email_acct_new(h, &id);
        if (s != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }
        info.acct_id = id;
        info.protocol = SRV_EMAIL_PROT_IMAP4;

        s = srv_email_acct_edit(h, &info);
        if (s != SRV_EMAIL_RESULT_SUCC)
        {
            break;
        }

        s = srv_email_acct_save(h);
    }while(0);

    if (h != 0)
    {
        srv_email_acct_destroy(h);
        h = 0;
    }

    if (s != SRV_EMAIL_RESULT_SUCC)
    {
        // POPUP ERROR
        mmi_email_lib_error_popup(mmi_email_util_get_error_string_id(s));
    }
    else
    {
        if (mmi_email_store_acct_misc_info(id))
        {
            mmi_email_smgr_account_add(id);
            if (email_mmi_account_data_get_count() == 1)
            {
                email_mmi_account_data_set_default(id);
            }
            mmi_email_lib_succ_popup(STR_GLOBAL_SAVED);
        }
        else
        {
            srv_email_acct_delete(id);
            mmi_email_lib_error_popup(STR_GLOBAL_ERROR);
        }
    }
}


static void sso_add_confirm_yes(void)
{
    U32 number = 0;
    
    number = email_mmi_account_data_get_count();

    // check MAX ACCOUNT reaches, 
    if (number >= MMI_EMAIL_MAX_ACCTS)
    {
        // if so, ask user to select one account to delete
        sso_replace_confirm_enter();
    }
    else
    {
        // Just add it
        sso_add_account();
        sso_done();
    }
}

static void sso_add_confirm_no(void)
{
    sso_done();
}

static void sso_add_confirm_enter(void)
{
    mmi_email_util_display_confirm(
        GRP_ID_ROOT,
        sso_add_confirm_yes,
        sso_add_confirm_no,
        NULL,
        TRUE,
        GetString(STR_EMAIL_SSO_IMPORT_ID),
        MMI_EVENT_QUERY);
}


static void sso_delete_account(EMAIL_ACCT_ID acct)
{
    mmi_email_app_nwk_delaccount(acct);
    mmi_email_smgr_account_del(acct);

    mmi_email_entry_edit_account_delete_account_extra_info(acct, NULL);

#ifndef __MMI_SLIM_EMAIL_NO_AUTO_CHECK__
    mmi_email_auto_check_delete_acct(acct, MMI_TRUE);
#endif /* __MMI_SLIM_EMAIL_NO_AUTO_CHECK__ */

    mmi_email_sig_delete_acct(acct, MMI_TRUE);

    srv_email_acct_delete(acct);
}



static void sso_replace_select_done(void)
{
    // Ready to replace

    // Have a double check before action

    // Delete the selected account firstly
    sso_delete_account(g_sso_sel_acct);

    // Create new account
    sso_add_account();
    sso_done();
}


static void sso_replace_confirm_yes(void)
{
    g_sso_sel_acct = 0;
    mmi_email_lib_select_account(sso_replace_select_done, &g_sso_sel_acct);
}


static void sso_replace_confirm_no(void)
{
    sso_done();
}



static void sso_replace_confirm_enter(void)
{
    mmi_email_util_display_confirm(
        GRP_ID_ROOT,
        sso_replace_confirm_yes,
        sso_replace_confirm_no,
        NULL,
        TRUE,
        GetString(STR_EMAIL_SSO_REPLACE_ID),
        MMI_EVENT_QUERY);
}



static MMI_ID g_sso_cui = 0;
static srv_email_cloud_funcptr_type g_sso_cb = NULL;
static void* g_sso_user_data = NULL;
static MMI_ID g_sso_grp = GRP_ID_INVALID;

static void send_result(MMI_BOOL succ)
{
    if (g_sso_cui != 0)
    {
        cui_sso_login_close(g_sso_cui);
        g_sso_cui = 0;
    }

    if (g_sso_grp != GRP_ID_INVALID)
    {
        mmi_frm_group_close(g_sso_grp);
        g_sso_grp = GRP_ID_INVALID;
    }

    if (g_sso_cb != NULL)
    {
        g_sso_cb(succ, g_sso_user_data);
        g_sso_cb = NULL;
        g_sso_user_data = NULL;
    }
}


mmi_ret mmi_email_sso_done_hdlr(mmi_event_struct* para)
{
    cui_sso_login_done_event_struct *e = (cui_sso_login_done_event_struct*)para;
    if (e->evt_id == EVT_ID_CUI_SSO_LOGIN_DONE)
    {
        if (e->result == EVT_ID_CUI_SSO_LOGIN_OK)
        {
            send_result(MMI_TRUE);
        }
        else
        {
            send_result(MMI_FALSE);
        }
    }

    return MMI_RET_OK;
}


mmi_ret mmi_email_sso_ind_hdlr(mmi_event_struct* para)
{
    srv_email_evt_cloud_ind_struct *e = (srv_email_evt_cloud_ind_struct*)para;

    // Create group
    g_sso_grp = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_email_sso_done_hdlr, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (g_sso_grp == GRP_ID_INVALID)
    {
        send_result(MMI_FALSE);
    }

    g_sso_cb = e->callback;
    g_sso_user_data = e->user_data;
    g_sso_cui = cui_sso_login_create(g_sso_grp, e->provider_id, e->cloud_acct_id);
    if (g_sso_cui == 0)
    {
        send_result(MMI_FALSE);
        return MMI_RET_OK;
    }

    cui_sso_login_run(g_sso_cui);
    return MMI_RET_OK;
}

#endif /* __MMI_SSO__ */
#endif /* __MMI_EMAIL__ */

