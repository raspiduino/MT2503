#ifndef __EMAIL_APP_LIB_H__
#define __EMAIL_APP_LIB_H__

#include "MMIDataType.h"
#include "emailsrvgprot.h"

extern U32 mmi_email_lib_get_total_unread_number(void);

extern MMI_BOOL mmi_email_lib_dir_exist(const WCHAR *path);
extern MMI_BOOL mmi_email_lib_is_copy_file_dir(WCHAR *file_path);

extern void mmi_email_lib_create_copy_file_dir(void);
extern void mmi_email_lib_empty_copy_file_dir(void);

extern MMI_BOOL mmi_email_lib_is_phone_locked(void);
extern MMI_BOOL mmi_email_lib_is_call_interrupt(void);


extern void mmi_email_lib_error_popup(U16 str_id);
extern void mmi_email_lib_succ_popup(U16 str_id);
extern void mmi_email_lib_infor_popup(U16 str_id);


extern S32 mmi_email_lib_get_outbox_number(EMAIL_ACCT_HANDLE acct_handle, EMAIL_FLDR_ID *outbox_id);

extern MMI_BOOL email_mmi_lib_is_valid_account(EMAIL_ACCT_ID acct_id);

extern MMI_BOOL mmi_email_account_save_sent_emails(EMAIL_ACCT_ID account_id);

#ifdef __MMI_EMAIL_IMAP_PUSH__
void mmi_email_lib_set_push_account(EMAIL_ACCT_ID acct_id);
EMAIL_ACCT_ID mmi_email_lib_get_push_account(void);
#endif /* __MMI_EMAIL_IMAP_PUSH__ */



extern U16 mmi_email_lib_get_progress_img_id(void);

extern void mmi_email_lib_loading_ui_show(mmi_id grp_id, WCHAR* string, FuncPtr abort_func);
extern void mmi_email_lib_loading_ui_update(WCHAR* string);
extern void mmi_email_lib_loading_ui_close(void);


extern void mmi_email_dummy_refresh_enable(BOOL to_enable);
extern void mmi_email_dummy_refresh(FuncPtr pfn);



extern void mmi_email_lib_select_account(FuncPtr lsk_func, EMAIL_ACCT_ID *acc_id);



#ifdef __MTK_TARGET__

#undef WARRING
#undef ASSERT

#define WARRING() do{}while(0)
#define ASSERT(b) do{}while(0)

#else

#define WARRING() do{_asm{int 3}}while(0) // mmi_email_lib_warning(__FILE__, __LINE__)
extern void mmi_email_lib_warning(char *filename, int line);


#undef ASSERT
#define ASSERT(b) do{if(!(b)) {_asm{int 3}}}while(0) //mmi_email_lib_assert(b, __FILE__, __LINE__)
extern void mmi_email_lib_assert(char *filename, int line);

#endif /* __MTK_TARGET__ */

#endif /* __EMAIL_APP_LIB_H__ */