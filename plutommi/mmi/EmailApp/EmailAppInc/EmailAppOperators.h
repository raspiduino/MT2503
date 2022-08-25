#ifndef __EMAIL_APP_OPERATORS_H__
#define __EMAIL_APP_OPERATORS_H__



#include "MMIDataType.h"
#include "emailsrvgprot.h"

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
extern void mmi_email_hs_update_sidebar_indicator(void);
extern void mmi_email_hs_update_sidebar_account(void);
extern void mmi_email_hs_reset_sidebar_icon(void);
extern void mmi_email_hs_remove_shct_acct_by_id(EMAIL_ACCT_ID acct_id);
#endif /* defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __OP12__
extern BOOL mmi_email_vf_get_flag(void);
extern void mmi_email_vf_set_flag(BOOL is_show);
extern void mmi_email_vf_nmgr_query(void);
#endif /* __OP12__ */

#ifdef __MMI_OP12_TOOLBAR__
extern void mmi_email_tb_update_info(void);
#endif /* __MMI_OP12_TOOLBAR__ */





#endif /* __EMAIL_APP_OPERATORS_H__ */

