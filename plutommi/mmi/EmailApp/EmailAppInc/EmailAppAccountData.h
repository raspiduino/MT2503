#ifndef __EMAIL_APP_ACCOUNT_DATA_H__
#define __EMAIL_APP_ACCOUNT_DATA_H__

#include "MMIDataType.h"
#include "emailsrvgprot.h"

/* resource define */
#include "GlobalResDef.h"
#include "mmi_rp_app_email_def.h"

typedef enum
{
    EMACC_S_NORMAL = 0, 

    EMACC_S_TOSEND = 0x01,
    EMACC_S_SENDING = 0x02,
    EMACC_S_SENDFAIL = 0x04,

    EMACC_S_TORECEIVE = 0x08,
    EMACC_S_RECEIVING = 0x10,
    EMACC_S_RECEIVEFAIL = 0x20,

    EMACC_S_TODOWNLOAD = 0x40,
    EMACC_S_DOWNLOADING = 0x80,
    EMACC_S_DOWNLOADFAIL = 0x100,
}email_mmi_account_state_enum;


/* global */
extern void email_mmi_account_data_init(void);
extern void email_mmi_account_data_add(EMAIL_ACCT_ID acct_id);
extern void email_mmi_account_data_del(EMAIL_ACCT_ID acct_id);

/* network update */
extern void email_mmi_account_data_reset_status(void);
extern void email_mmi_account_data_set_refresh_status(EMAIL_ACCT_ID acct_id, email_mmi_account_state_enum s);
extern void email_mmi_account_data_set_send_status(EMAIL_ACCT_ID acct_id, email_mmi_account_state_enum s);

// Real time update
extern void email_mmi_account_data_update_inbox_number(EMAIL_ACCT_ID acct_id, U32 num_unread, U32 num_inbox);

extern void email_mmi_account_data_set_default(EMAIL_ACCT_ID acct_id);
extern EMAIL_ACCT_ID email_mmi_account_data_get_default(void);

#ifdef __MMI_EMAIL_IMAP_PUSH__
extern void email_mmi_account_data_set_push(EMAIL_ACCT_ID acct_id);
extern EMAIL_ACCT_ID email_mmi_account_data_get_push(void);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

/* For UI display */
extern U32 email_mmi_account_data_get_count(void);

extern EMAIL_ACCT_ID email_mmi_account_data_get_id(U32 idx);
extern const WCHAR* email_mmi_account_data_get_name(U32 idx);
extern const WCHAR* email_mmi_account_data_get_hint(U32 idx);
extern BOOL email_mmi_account_data_is_imap(U32 idx);
extern BOOL email_mmi_account_data_is_imap_accid(EMAIL_ACCT_ID acct_id);

extern EMAIL_FLDR_ID email_mmi_account_data_get_fldid(EMAIL_ACCT_ID acct_id, U32 fld_idx);

extern U16 email_mmi_account_data_get_icon1(U32 idx); // default / push / both / non
extern U16 email_mmi_account_data_get_icon2(U32 idx); // progress


#endif /* __EMAIL_APP_ACCOUNT_DATA_H__ */
