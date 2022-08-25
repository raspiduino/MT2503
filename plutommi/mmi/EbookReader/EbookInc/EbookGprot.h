#ifndef _PIXCOM_EBOOKGPROT_H
#define _PIXCOM_EBOOKGPROT_H


#include "MMI_features.h"
#include "MMIDataType.h"

#define     EBR_RECORD_SIZE_MAX              4096
#define     MMI_EBOOK_APP_MEM_SIZE         (40*1024)

extern mmi_ret mmi_ebook_usb_mode_on(mmi_event_struct *p_event);
extern mmi_ret mmi_ebook_usb_mode_off(mmi_event_struct *p_event);
extern void mmi_ebr_pre_entry_book_shel_screen(void);
extern void InitEbookApp(void);
extern void highlight_mainmenu_ebook(void);
#ifdef __COSMOS_MMI_PACKAGE__

extern MMI_BOOL EbookAppEnterFlag(void);
#endif

#endif /* _PIXCOM_EBOOKGPROT_H */ 

