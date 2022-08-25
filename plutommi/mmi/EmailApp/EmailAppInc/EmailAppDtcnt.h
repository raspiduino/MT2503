
#ifndef __EMAIL_APP_DATAACCOUNT_H__
#define __EMAIL_APP_DATAACCOUNT_H__

#include "MMIDataType.h"
#include "emailsrvgprot.h"

extern void mmi_email_dataaccount_init(void);
extern void mmi_email_dataaccount_deinit(void);

extern void mmi_email_dataaccount_map_add(EMAIL_ACCT_ID id);
extern void mmi_email_dataaccount_map_del(EMAIL_ACCT_ID id);


extern
MMI_BOOL
mmi_email_datacct_get_app_info(
    EMAIL_ACCT_ID acct_id,
    MMI_BOOL is_incoming,
    U16 *str_id,
    U16 *img_id);

extern MMI_BOOL mmi_email_dtcnt_is_conflict(U32 dtcnt_id);
extern MMI_BOOL mmi_email_dtcnt_is_conflict_ext(EMAIL_ACCT_ID acct_id);
extern MMI_BOOL mmi_email_dtcnt_is_any_conflict(U32 dtcnt_id[]);


extern void mmi_email_dtcnt_get_showname(WCHAR name[], U32 dtcnt_id[]);
extern U8 mmi_email_dtcnt_get_temp_appid(void);

#endif /* __EMAIL_APP_DATAACCOUNT_H__ */
