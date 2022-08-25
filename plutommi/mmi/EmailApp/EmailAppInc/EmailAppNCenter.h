#ifndef __EMAIL_APP_NCENTER_H__
#define __EMAIL_APP_NCENTER_H__


void mmi_email_ncenter_newmail(S32 total);
void mmi_email_ncenter_error(EMAIL_ACCT_ID acc_id, S32 error_code);

void mmi_email_ncenter_ongoing_start(EMAIL_ACCT_ID acc_id, MMI_BOOL refreshing);
void mmi_email_ncenter_ongoing_done(EMAIL_ACCT_ID acc_id);

void remove_all_received_number(void);

void mmi_email_ncenter_delaccount(EMAIL_ACCT_ID acc_id);
void mmi_email_ncenter_deinit(void);

void mmi_email_ncenter_restore_error(void);

#endif /* __EMAIL_APP_NCENTER_H__ */