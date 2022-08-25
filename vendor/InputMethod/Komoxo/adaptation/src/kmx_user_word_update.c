
#include "os\kmx_os.h"

#include "cstar_ime.h"
#include "csk2api.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "SettingProfileEnum.h"
#include "CommonScreens.h"
#include "MMI_include.h"

#include "Mmi_rp_app_komoxo_def.h"
#include "kmx_input_config.h"
#if !defined(__MMI_KMX_UPDATE_USER_WORD__) 

void mmi_kmx_report_warning(const KMXWCHAR* str) 
{     
} 

void mmi_kmx_report_success(const KMXWCHAR* str) 
{     
} 

const unsigned short* mmi_kmx_update_get_string(unsigned short str_id) 
{ 
    return 0; 
} 

const char* mmi_kmx_get_pinyin_charset(void) 
{     
    return 0; 
} 

const char* mmi_kmx_get_input_type(void) 
{ 
    return 0; 
} 
#endif 


#if defined(__MMI_KMX_UPDATE_USER_WORD__)

#define KMX_UPDATE_STR_ID_START STR_ID_KMX_UPDATE_USER_WORD

#define KMX_POPUP_NOTIFYDURATION_TIME   2000

extern void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId);

void mmi_kmx_report_warning(const KMXWCHAR* str)
{
    DisplayPopup((U8*)str, IMG_GLOBAL_WARNING, 0, KMX_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
}

void mmi_kmx_report_success(const KMXWCHAR* str)
{
    DisplayPopup((U8*)str, 0, 0, KMX_POPUP_NOTIFYDURATION_TIME, (U8) SUCCESS_TONE);
}

const unsigned short* mmi_kmx_update_get_string(unsigned short str_id)
{
    return (unsigned short*)get_string((unsigned short)(KMX_UPDATE_STR_ID_START + str_id));
}

const char* mmi_kmx_get_pinyin_charset(void)
{
    // TODO: fill the real implementation
    const char* charset;
    charset = CS_IMM_GetPinyinCharset(&cs_ldb_pinyin_cizu); 
    if (!charset || !charset[0])
    {
        return "gb2312"; 
    }
    return charset;
}

const char* mmi_kmx_get_input_type(void)
{
#ifdef __MMI_CSTAR_SURETYPE__
    return "suretype"
#else
    return "digit";
#endif
}
/* Highlight menu handler etc. */

static void mmi_kmx_update_in_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // SCR_KMX_KEYPAD_OPTION should be updated!
    EntryNewScreen(SCR_KMX_UPDATE_PROGRESS, kmx_update_user_word_finalize, NULL,NULL);    
    
    /* passing 0xffff for Title string and Title icon for the disbling the status bar and title display. */
    // 
    ShowCategory8Screen(0xffff, 0xffff, 0, 0, 0, 0, STR_ID_KMX_UPDATING, IMG_GLOBAL_PROGRESS, NULL);

    ClearInputEventHandler(MMI_DEVICE_ALL);
}


static void mmi_kmx_cancel_update_user_word(void)
{    
    GoBackHistory();
}

static void mmi_kmx_start_update_user_word(void)
{
    mmi_kmx_update_in_progress();
    kmx_update_user_word_start();    
}

void mmi_kmx_ask_user_word_update_check(void)
{
    // TODO: string id may changed
    DisplayConfirm(
		STR_GLOBAL_YES,
		IMG_GLOBAL_YES, 
		STR_GLOBAL_NO,
		IMG_GLOBAL_NO, 
		get_string(STR_ID_KMX_UPDATE_CONFIRM),
		IMG_GLOBAL_QUESTION,
        WARNING_TONE);    

    SetLeftSoftkeyFunction(mmi_kmx_start_update_user_word, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_kmx_cancel_update_user_word, KEY_EVENT_UP);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_KMX_UPDATE_USER_WORD__ */
