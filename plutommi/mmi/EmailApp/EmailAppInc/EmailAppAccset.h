#ifndef __EMAIL_APP_ACCOUNT_SET_H__
#define __EMAIL_APP_ACCOUNT_SET_H__


void email_mmi_account_set_default(mmi_id parent);

#ifdef __MMI_EMAIL_IMAP_PUSH__
void email_mmi_account_set_push(mmi_id parent);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */

#endif /* __EMAIL_APP_ACCOUNT_SET_H__ */