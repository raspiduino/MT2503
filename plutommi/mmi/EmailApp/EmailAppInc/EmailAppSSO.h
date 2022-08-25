#ifndef __EMAIL_APP_SSO_H__
#define __EMAIL_APP_SSO_H__

#ifdef __MMI_SSO__

MMI_BOOL mmi_email_sso_precheck(FuncPtr cb);
MMI_BOOL mmi_email_sso_is_cloud_account(EMAIL_ACCT_ID id);

#endif /* __MMI_SSO__ */
#endif /* __EMAIL_APP_SSO_H__ */

