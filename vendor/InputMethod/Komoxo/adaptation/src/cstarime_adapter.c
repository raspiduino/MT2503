

#include "MMI_features.h"

#include "kmx_input_config.h"

#ifdef __MMI_KOMOXO__

#include "csk2api.h"
#include "cstar_ime.h"
#include "kmxime_api.h"

#include "mmi_frm_gprot.h"
#include "gui.h"
#include "GlobalConstants.h"
#include "Pixteldatatypes.h"
#include "wgui_categories_inputs.h"     /* For INPUT_MODE_xxxx constants    */
#include "wgui_categories_util.h"       /* For painting handler             */
#include "gui_ems.h"                    /* For structure UI_EMS_input_box   */
#include "Timerevents.h"                /* For timer ID                     */
#include "CommonScreens.h"              /* For symbol functions             */
#include "gui_data_types.h"
#include "FileMgr.h"
#include "FS_type.h"
#include "FS_errcode.h"
#include "FS_Func.h"
#include "DebugInitDef.h"
#include "gui_virtual_keyboard.h"
#include "SettingProfileEnum.h"
#include "imc.h"
#include "imc_pen.h"

#include "Mmi_frm_input_gprot.h"

#include "Filemgrgprot.h"

#ifndef FMGR_PATH_BUFFER_SIZE
#define FMGR_PATH_BUFFER_SIZE (128)
#endif

#include "kmximmapi.h"

#include "kmx_input_prot.h"
#include "kmx_gui.h"

#ifdef __MMI_KMX_VUI_SUPPORT__
#include "mmi_rp_srv_input_method_def.h"
#endif

extern int cstar_ime_is_ui_visible(void);
extern int kmx_hand_writing_handle_key_event(int key_code, int key_type);
extern int kmx_hw_is_making_user_word(void);
extern void kmx_hw_pen_down_in_editor(void);
extern void kmx_input_method_pen_down_in_editor(void);
extern void kmx_input_method_reset(void);
extern void CS_PenDownInEditor(void);
extern void cs_reset(void);
void cstar_ime_reset_state(void);

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
int cstar_ime_update_case(int hint);
void cstar_ime_set_input_mode(int imm_mode);
#endif

typedef struct
{
	unsigned int input_mode;
	unsigned int cstar_mode;
}MODE_MAP_ENTRY;

#if defined(__MMI_IMC_CAPITAL_SWITCH__)
    #define KMX_CFG_KEY_UP_IME_SWITCH
#else
    #define KMX_CFG_KEY_DOWN_IME_SWITCH        
#endif

#define KMX_CFG_FAST_NUMBER_INPUT

/* Fast Number Input is not supported for qwerty keypad. */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    #ifdef KMX_CFG_FAST_NUMBER_INPUT 
    #undef KMX_CFG_FAST_NUMBER_INPUT 
    #endif
#endif

static const MODE_MAP_ENTRY g_cstar_mode_map_table[] =
{
#if defined(__MMI_CSTAR_ENGLISH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    IM_ABC_UPPER    
},
#endif

#if defined(__MMI_CSTAR_ENGLISH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    IM_ABC_LOWER
},
#endif

#if defined(__MMI_CSTAR_ENGLISH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,
    IM_ABC_UPPER    
},
#endif

#if defined(__MMI_CSTAR_ENGLISH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC,
    IM_ABC_LOWER    
},
#endif

#if defined(__MMI_CSTAR_TR_CHINESE__)
{
    IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,
    IM_ZHUYIN_MT
},
#endif
#if defined(__MMI_CSTAR_SM_CHINESE__)
{
    IMM_INPUT_MODE_SM_MULTITAP_PINYIN,
    IM_PINYIN
},
#endif
#if defined(__MMI_CSTAR_TR_CHINESE__)
{
    IMM_INPUT_MODE_TR_BOPOMO,
    IM_ZHUYIN_MT
},
#endif
#if defined(__MMI_CSTAR_SM_CHINESE__)
{
    IMM_INPUT_MODE_SM_PINYIN,
    IM_PINYIN
},
#endif
#if defined(__MMI_CSTAR_TR_CHINESE__)
{
    IMM_INPUT_MODE_TR_STROKE,
    IM_STROKE_BIG5
},
#endif
#if defined(__MMI_CSTAR_SM_CHINESE__)
{
    IMM_INPUT_MODE_SM_STROKE,
    IM_STROKE
},
#endif
#if defined(__MMI_CSTAR_ENGLISH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
    IM_ENGLISH_UPPER
},
#endif

#if defined(__MMI_CSTAR_ENGLISH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ABC,
    IM_ENGLISH_LOWER
},
#endif

#if defined(__MMI_CSTAR_THAI__)
{
    IMM_INPUT_MODE_MULTITAP_THAI,
    IM_THAI_MT
},
#endif

#if defined(__MMI_CSTAR_THAI__)
{
    IMM_INPUT_MODE_SMART_THAI,
    IM_THAI
},
#endif

#if defined(__MMI_CSTAR_ARABIC__)
{
    IMM_INPUT_MODE_MULTITAP_ARABIC,
    IM_ARABIC_MT
},
#endif

#if defined(__MMI_CSTAR_ARABIC__)
{
    IMM_INPUT_MODE_SMART_ARABIC,
    IM_ARABIC
},
#endif

#if defined(__MMI_CSTAR_PERSIAN__)
{
    IMM_INPUT_MODE_MULTITAP_PERSIAN,
    IM_PERSIAN_MT
},
#endif

#if defined(__MMI_CSTAR_PERSIAN__)
{
    IMM_INPUT_MODE_SMART_PERSIAN,
    IM_PERSIAN
},
#endif

#if defined(__MMI_CSTAR_HEBREW__)
{
    IMM_INPUT_MODE_MULTITAP_HEBREW,
    IM_HEBREW_MT
},
#endif

#if defined(__MMI_CSTAR_HEBREW__)
{
    IMM_INPUT_MODE_SMART_HEBREW,
    IM_HEBREW
},
#endif

#if defined(__MMI_CSTAR_SPANISH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,
    IM_ABC_UPPER_ES
},
#endif

#if defined(__MMI_CSTAR_SPANISH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,
    IM_ABC_LOWER_ES
},
#endif

#if defined(__MMI_CSTAR_SPANISH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH,
    IM_SPANISH_UPPER
},
#endif

#if defined(__MMI_CSTAR_SPANISH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH,
    IM_SPANISH_LOWER
},
#endif

#if defined(__MMI_CSTAR_DANISH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,
    IM_ABC_UPPER_DA
},
#endif

#if defined(__MMI_CSTAR_DANISH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,
    IM_ABC_LOWER_DA
},
#endif

#if defined(__MMI_CSTAR_DANISH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_DANISH,
    IM_DANISH_UPPER
},
#endif

#if defined(__MMI_CSTAR_DANISH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_DANISH,
    IM_DANISH_LOWER
},
#endif

#if defined(__MMI_CSTAR_POLISH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,
    IM_ABC_UPPER_PL
},
#endif

#if defined(__MMI_CSTAR_POLISH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,
    IM_ABC_LOWER_PL
},
#endif

#if defined(__MMI_CSTAR_POLISH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_POLISH,
    IM_POLISH_UPPER
},
#endif

#if defined(__MMI_CSTAR_POLISH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_POLISH,
    IM_POLISH_LOWER
},
#endif

#if defined(__MMI_CSTAR_FRENCH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,
    IM_ABC_UPPER_FR
},
#endif

#if defined(__MMI_CSTAR_FRENCH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,
    IM_ABC_LOWER_FR
},
#endif

#if defined(__MMI_CSTAR_FRENCH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,
    IM_FRENCH_UPPER
},
#endif

#if defined(__MMI_CSTAR_FRENCH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,
    IM_FRENCH_LOWER
},
#endif

#if defined(__MMI_CSTAR_GERMAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,
    IM_ABC_UPPER_DE
},
#endif

#if defined(__MMI_CSTAR_GERMAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,
    IM_ABC_LOWER_DE
},
#endif

#if defined(__MMI_CSTAR_GERMAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN,
    IM_GERMAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_GERMAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN,
    IM_GERMAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_ITALIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,
    IM_ABC_UPPER_IT
},
#endif

#if defined(__MMI_CSTAR_ITALIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,
    IM_ABC_LOWER_IT
},
#endif

#if defined(__MMI_CSTAR_ITALIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN,
    IM_ITALIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_ITALIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN,
    IM_ITALIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_RUSSIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,
    IM_ABC_UPPER_RUS
},
#endif

#if defined(__MMI_CSTAR_RUSSIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,
    IM_ABC_LOWER_RUS
},
#endif

#if defined(__MMI_CSTAR_RUSSIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN,
    IM_RUSSIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_RUSSIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN,
    IM_RUSSIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_BULGARIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,
    IM_ABC_UPPER_BG
},
#endif

#if defined(__MMI_CSTAR_BULGARIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,
    IM_ABC_LOWER_BG
},
#endif

#if defined(__MMI_CSTAR_UKRAINIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,
    IM_ABC_UPPER_UK
},
#endif

#if defined(__MMI_CSTAR_UKRAINIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,
    IM_ABC_LOWER_UK
},
#endif

#if defined(__MMI_CSTAR_UKRAINIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN,
    IM_UKRAINIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_UKRAINIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN,
    IM_UKRAINIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_BULGARIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN,
    IM_BULGARIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_BULGARIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN,
    IM_BULGARIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_TURKISH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,
    IM_ABC_UPPER_TR
},
#endif

#if defined(__MMI_CSTAR_TURKISH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,
    IM_ABC_LOWER_TR
},
#endif

#if defined(__MMI_CSTAR_TURKISH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH,
    IM_TURKISH_UPPER
},
#endif

#if defined(__MMI_CSTAR_TURKISH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH,
    IM_TURKISH_LOWER
},
#endif

#if defined(__MMI_CSTAR_PORTUGUESE__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,
    IM_ABC_UPPER_PT
},
#endif

#if defined(__MMI_CSTAR_PORTUGUESE__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,
    IM_ABC_LOWER_PT
},
#endif

#if defined(__MMI_CSTAR_PORTUGUESE__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,
    IM_PORTUGUESE_UPPER
},
#endif

#if defined(__MMI_CSTAR_PORTUGUESE__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,
    IM_PORTUGUESE_LOWER
},
#endif

#if defined(__MMI_CSTAR_HINDI__)
{
    IMM_INPUT_MODE_MULTITAP_HINDI,
    IM_HINDI_MT    
},
#endif

#if defined(__MMI_CSTAR_HINDI__)
{
    IMM_INPUT_MODE_SMART_HINDI,
    IM_HINDI
},
#endif

#if defined(__MMI_CSTAR_HINGLISH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_HINGLISH,
	IM_HINGLISH_UPPER
},
#endif

#if defined(__MMI_CSTAR_HINGLISH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_HINGLISH,
	IM_HINGLISH_LOWER
},
#endif

#if defined(__MMI_CSTAR_INDONESIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,
    IM_ABC_UPPER_ID
},
#endif

#if defined(__MMI_CSTAR_INDONESIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,
    IM_ABC_LOWER_ID    
},
#endif

#if defined(__MMI_CSTAR_INDONESIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN,
    IM_INDONESIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_INDONESIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN,
    IM_INDONESIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_CZECH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,
    IM_ABC_UPPER_CS
},
#endif

#if defined(__MMI_CSTAR_CZECH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,
    IM_ABC_LOWER_CS
},
#endif

#if defined(__MMI_CSTAR_CZECH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_CZECH,
    IM_CZECH_UPPER
},
#endif

#if defined(__MMI_CSTAR_CZECH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_CZECH,
    IM_CZECH_LOWER
},
#endif

#if defined(__MMI_CSTAR_MALAY__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,
    IM_ABC_UPPER_MS
},
#endif

#if defined(__MMI_CSTAR_MALAY__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,
    IM_ABC_LOWER_MS
},
#endif

#if defined(__MMI_CSTAR_MALAY__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_MALAY,
    IM_MALAY_UPPER
},
#endif

#if defined(__MMI_CSTAR_MALAY__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_MALAY,
    IM_MALAY_LOWER
},
#endif

#if defined(__MMI_CSTAR_VIETNAMESE__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,
    IM_ABC_UPPER_VI
},
#endif

#if defined(__MMI_CSTAR_VIETNAMESE__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,
    IM_ABC_LOWER_VI
},
#endif

#if defined(__MMI_CSTAR_VIETNAMESE__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,
    IM_VIETNAMESE_UPPER
},
#endif

#if defined(__MMI_CSTAR_VIETNAMESE__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,
    IM_VIETNAMESE_LOWER
},
#endif

#if defined(__MMI_CSTAR_FINNISH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,
    IM_ABC_UPPER_FI
},
#endif

#if defined(__MMI_CSTAR_FINNISH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,
    IM_ABC_LOWER_FI
},
#endif

#if defined(__MMI_CSTAR_FINNISH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH,
    IM_FINNISH_UPPER
},
#endif

#if defined(__MMI_CSTAR_FINNISH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH,
    IM_FINNISH_LOWER
},
#endif

#if defined(__MMI_CSTAR_HUNGARIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,
    IM_ABC_UPPER_HU
},
#endif

#if defined(__MMI_CSTAR_HUNGARIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,
    IM_ABC_LOWER_HU
},
#endif

#if defined(__MMI_CSTAR_HUNGARIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN,
    IM_HUNGARIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_HUNGARIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN,
    IM_HUNGARIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_SLOVAKIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,
    IM_ABC_UPPER_SK
},
#endif

#if defined(__MMI_CSTAR_SLOVAKIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,
    IM_ABC_LOWER_SK
},
#endif

#if defined(__MMI_CSTAR_SLOVAKIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK,
    IM_SLOVAK_UPPER
},
#endif

#if defined(__MMI_CSTAR_SLOVAKIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK,
    IM_SLOVAK_LOWER
},
#endif

#if defined(__MMI_CSTAR_DUTCH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,
    IM_ABC_UPPER_NL
},
#endif

#if defined(__MMI_CSTAR_DUTCH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,
    IM_ABC_LOWER_NL
},
#endif

#if defined(__MMI_CSTAR_DUTCH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH,
    IM_DUTCH_UPPER
},
#endif

#if defined(__MMI_CSTAR_DUTCH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH,
    IM_DUTCH_LOWER
},
#endif

#if defined(__MMI_CSTAR_NORWEGIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,
    IM_ABC_UPPER_NO
},
#endif

#if defined(__MMI_CSTAR_NORWEGIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,
    IM_ABC_LOWER_NO
},
#endif

#if defined(__MMI_CSTAR_NORWEGIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN,
    IM_NORWEGIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_NORWEGIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN,
    IM_NORWEGIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_SWEDISH__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,
    IM_ABC_UPPER_SV
},
#endif

#if defined(__MMI_CSTAR_SWEDISH__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,
    IM_ABC_LOWER_SV
},
#endif

#if defined(__MMI_CSTAR_SWEDISH__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH,
    IM_SWEDISH_UPPER
},
#endif

#if defined(__MMI_CSTAR_SWEDISH__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH,
    IM_SWEDISH_LOWER
},
#endif

#if defined(__MMI_CSTAR_CROATIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,
    IM_ABC_UPPER_HR
},
#endif

#if defined(__MMI_CSTAR_CROATIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,
    IM_ABC_LOWER_HR
},
#endif

#if defined(__MMI_CSTAR_CROATIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN,
    IM_CROATIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_CROATIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN,
    IM_CROATIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_ROMANIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,
    IM_ABC_UPPER_RO
},
#endif

#if defined(__MMI_CSTAR_ROMANIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,
    IM_ABC_LOWER_RO
},
#endif

#if defined(__MMI_CSTAR_ROMANIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN,
    IM_ROMANIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_ROMANIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN,
    IM_ROMANIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_SLOVENIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,
    IM_ABC_UPPER_SL
},
#endif

#if defined(__MMI_CSTAR_SLOVENIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,
    IM_ABC_LOWER_SL
},
#endif

#if defined(__MMI_CSTAR_SLOVENIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN,
    IM_SLOVENIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_SLOVENIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN,
    IM_SLOVENIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_GREEK__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,
    IM_ABC_UPPER_EL
},
#endif

#if defined(__MMI_CSTAR_GREEK__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,
    IM_ABC_LOWER_EL
},
#endif

#if defined(__MMI_CSTAR_GREEK__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_GREEK,
    IM_GREEK_UPPER
},
#endif

#if defined(__MMI_CSTAR_GREEK__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_GREEK,
    IM_GREEK_LOWER
},
#endif

#if defined(__MMI_CSTAR_SWAHILI__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,
    IM_ABC_UPPER_SW
},
#endif

#if defined(__MMI_CSTAR_SWAHILI__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,
    IM_ABC_LOWER_SW
},
#endif

#if defined(__MMI_CSTAR_SWAHILI__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI,
    IM_SWAHILI_UPPER
},
#endif

#if defined(__MMI_CSTAR_SWAHILI__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI,
    IM_SWAHILI_LOWER
},
#endif

#if defined(__MMI_CSTAR_LITHUANIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,
    IM_ABC_UPPER_LT
},
#endif

#if defined(__MMI_CSTAR_LITHUANIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,
    IM_ABC_LOWER_LT
},
#endif

#if defined(__MMI_CSTAR_LITHUANIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN,
    IM_LITHUANIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_LITHUANIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN,
    IM_LITHUANIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_ARMENIAN__)
{
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN,
    IM_ABC_UPPER_HY
},
#endif

#if defined(__MMI_CSTAR_ARMENIAN__)
{
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN,
    IM_ABC_LOWER_HY
},
#endif

#if defined(__MMI_CSTAR_ARMENIAN__)
{
    IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN,
    IM_ARMENIAN_UPPER
},
#endif

#if defined(__MMI_CSTAR_ARMENIAN__)
{
    IMM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN,
    IM_ARMENIAN_LOWER
},
#endif

#if defined(__MMI_CSTAR_BENGALI__)
{
    IMM_INPUT_MODE_MULTITAP_BENGALI,
    IM_BENGALI_MT
},
#endif

#if defined(__MMI_CSTAR_BENGALI__)
{
    IMM_INPUT_MODE_SMART_BENGALI,
    IM_BENGALI
},
#endif

#if defined(__MMI_CSTAR_URDU__)
{
    IMM_INPUT_MODE_MULTITAP_URDU,
    IM_URDU_MT
},
#endif

#if defined(__MMI_CSTAR_URDU__)
{
    IMM_INPUT_MODE_SMART_URDU,
    IM_URDU
},
#endif

#if defined(__MMI_CSTAR_ARMENIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ARMENIAN,
    IM_ARMENIAN    
},
#endif

#if defined(__MMI_CSTAR_BULGARIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BULGARIAN,
    IM_BULGARIAN    
},
#endif

#if defined(__MMI_CSTAR_CROATIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CROATIAN,
    IM_CROATIAN    
},
#endif

#if defined(__MMI_CSTAR_CZECH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CZECH,
    IM_CZECH    
},
#endif

#if defined(__MMI_CSTAR_DANISH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DANISH,
    IM_DANISH    
},
#endif

#if defined(__MMI_CSTAR_DUTCH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DUTCH,
    IM_DUTCH    
},
#endif

#if defined(__MMI_CSTAR_ENGLISH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,
    IM_ENGLISH    
},
#endif

#if defined(__MMI_CSTAR_FINNISH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FINNISH,
    IM_FINNISH    
},
#endif

#if defined(__MMI_CSTAR_FRENCH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH,
    IM_FRENCH    
},
#endif

#if defined(__MMI_CSTAR_GERMAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GERMAN,
    IM_GERMAN    
},
#endif

#if defined(__MMI_CSTAR_GREEK__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GREEK,
    IM_GREEK    
},
#endif

#if defined(__MMI_CSTAR_HINGLISH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HINGLISH,
    IM_HINGLISH    
},
#endif

#if defined(__MMI_CSTAR_HUNGARIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HUNGARIAN,
    IM_HUNGARIAN    
},
#endif

#if defined(__MMI_CSTAR_INDONESIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN,
    IM_INDONESIAN    
},
#endif

#if defined(__MMI_CSTAR_ITALIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ITALIAN,
    IM_ITALIAN    
},
#endif

#if defined(__MMI_CSTAR_LITHUANIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LITHUANIAN,
    IM_LITHUANIAN    
},
#endif

#if defined(__MMI_CSTAR_MALAY__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY,
    IM_MALAY    
},
#endif

#if defined(__MMI_CSTAR_NORWEGIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_NORWEGIAN,
    IM_NORWEGIAN    
},
#endif

#if defined(__MMI_CSTAR_POLISH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_POLISH,
    IM_POLISH    
},
#endif

#if defined(__MMI_CSTAR_PORTUGUESE__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE,
    IM_PORTUGUESE    
},
#endif

#if defined(__MMI_CSTAR_ROMANIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ROMANIAN,
    IM_ROMANIAN    
},
#endif

#if defined(__MMI_CSTAR_RUSSIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN,
    IM_RUSSIAN    
},
#endif

#if defined(__MMI_CSTAR_SLOVAKIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVAK,
    IM_SLOVAK    
},
#endif

#if defined(__MMI_CSTAR_SLOVENIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVENIAN,
    IM_SLOVENIAN    
},
#endif

#if defined(__MMI_CSTAR_SPANISH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH,
    IM_SPANISH    
},
#endif

#if defined(__MMI_CSTAR_SWAHILI__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWAHILI,
    IM_SWAHILI    
},
#endif

#if defined(__MMI_CSTAR_SWEDISH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWEDISH,
    IM_SWEDISH    
},
#endif

#if defined(__MMI_CSTAR_TURKISH__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH,
    IM_TURKISH    
},
#endif

#if defined(__MMI_CSTAR_UKRAINIAN__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UKRAINIAN,
    IM_UKRAINIAN    
},
#endif

#if defined(__MMI_CSTAR_VIETNAMESE__) && defined(__MMI_SMART_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE,
    IM_VIETNAMESE    
},
#endif

#if defined(__MMI_CSTAR_ARMENIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ARMENIAN,
    IM_ABC_HY    
},
#endif

#if defined(__MMI_CSTAR_BULGARIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BULGARIAN,
    IM_ABC_BG    
},
#endif

#if defined(__MMI_CSTAR_CROATIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CROATIAN,
    IM_ABC_HR    
},
#endif

#if defined(__MMI_CSTAR_CZECH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CZECH,
    IM_ABC_CS    
},
#endif

#if defined(__MMI_CSTAR_DANISH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DANISH,
    IM_ABC_DA    
},
#endif

#if defined(__MMI_CSTAR_DUTCH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DUTCH,
    IM_ABC_NL    
},
#endif

#if ( defined(__MMI_CSTAR_ENGLISH__)) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC,
    IM_ABC        
},
#endif

#if defined(__MMI_CSTAR_FINNISH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FINNISH,
    IM_ABC_FI    
},
#endif

#if defined(__MMI_CSTAR_FRENCH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FRENCH,
    IM_ABC_FR    
},
#endif

#if defined(__MMI_CSTAR_GERMAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GERMAN,
    IM_ABC_DE    
},
#endif

#if defined(__MMI_CSTAR_GREEK__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GREEK,
    IM_ABC_EL    
},
#endif

#if defined(__MMI_CSTAR_HUNGARIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HUNGARIAN,
    IM_ABC_HU    
},
#endif

#if defined(__MMI_CSTAR_INDONESIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN,
    IM_ABC_ID        
},
#endif

#if defined(__MMI_CSTAR_ITALIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ITALIAN,
    IM_ABC_IT    
},
#endif

#if defined(__MMI_CSTAR_LITHUANIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LITHUANIAN,
    IM_ABC_LT    
},
#endif

#if defined(__MMI_CSTAR_MALAY__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY,
    IM_ABC_MS    
},
#endif

#if defined(__MMI_CSTAR_NORWEGIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_NORWEGIAN,
    IM_ABC_NO    
},
#endif

#if defined(__MMI_CSTAR_POLISH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_POLISH,
    IM_ABC_PL    
},
#endif

#if defined(__MMI_CSTAR_PORTUGUESE__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE,
    IM_ABC_PT    
},
#endif

#if defined(__MMI_CSTAR_ROMANIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ROMANIAN,
    IM_ABC_RO    
},
#endif

#if defined(__MMI_CSTAR_RUSSIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN,
    IM_ABC_RUS    
},
#endif

#if defined(__MMI_CSTAR_SLOVAKIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVAK,
    IM_ABC_SK    
},
#endif

#if defined(__MMI_CSTAR_SLOVENIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVENIAN,
    IM_ABC_SL    
},
#endif

#if defined(__MMI_CSTAR_SPANISH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH,
    IM_ABC_ES    
},
#endif

#if defined(__MMI_CSTAR_SWAHILI__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWAHILI,
    IM_ABC_SW    
},
#endif

#if defined(__MMI_CSTAR_SWEDISH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWEDISH,
    IM_ABC_SV    
},
#endif

#if defined(__MMI_CSTAR_TURKISH__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH,
    IM_ABC_TR    
},
#endif

#if defined(__MMI_CSTAR_UKRAINIAN__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_UKRAINIAN,
    IM_ABC_UK    
},
#endif

#if defined(__MMI_CSTAR_VIETNAMESE__) && defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
{
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_VIETNAMESE,
    IM_ABC_VI    
},
#endif

#if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
{
    IMM_INPUT_MODE_QUICK_SEARCH_PINYIN,
    IM_ABC_LOWER
},
#else
{
    /* place holder */
    0,
    0
},
#endif
};

#ifdef __MMI_CSTAR_SURETYPE__

typedef struct
{
	mmi_imm_input_mode_enum mode[2];	
}KMX_IME_MODE_PAIR;	
	
static const KMX_IME_MODE_PAIR g_mode_pair_table[] =
{
	#if defined(__MMI_CSTAR_ENGLISH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC
	},
	#endif /* #if defined(__MMI_CSTAR_ENGLISH__) */
	#if defined(__MMI_CSTAR_ENGLISH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC
	},
	#endif /* #if defined(__MMI_CSTAR_ENGLISH__) */
	#if defined(__MMI_CSTAR_ENGLISH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,
	    IMM_INPUT_MODE_SMART_LOWERCASE_ABC
	},
	#endif /* #if defined(__MMI_CSTAR_ENGLISH__) */
	#if defined(__MMI_CSTAR_SPANISH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH
	},
	#endif /* #if defined(__MMI_CSTAR_SPANISH__) */
	#if defined(__MMI_CSTAR_SPANISH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH
	},
	#endif /* #if defined(__MMI_CSTAR_SPANISH__) */
	#if defined(__MMI_CSTAR_DANISH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH
	},
	#endif /* #if defined(__MMI_CSTAR_DANISH__) */
	#if defined(__MMI_CSTAR_DANISH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_DANISH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_DANISH
	},
	#endif /* #if defined(__MMI_CSTAR_DANISH__) */
	#if defined(__MMI_CSTAR_POLISH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH
	},
	#endif /* #if defined(__MMI_CSTAR_POLISH__) */
	#if defined(__MMI_CSTAR_POLISH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_POLISH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_POLISH
	},
	#endif /* #if defined(__MMI_CSTAR_POLISH__) */
	#if defined(__MMI_CSTAR_FRENCH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH
	},
	#endif /* #if defined(__MMI_CSTAR_FRENCH__) */
	#if defined(__MMI_CSTAR_FRENCH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH
	},
	#endif /* #if defined(__MMI_CSTAR_FRENCH__) */
	#if defined(__MMI_CSTAR_GERMAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN
	},
	#endif /* #if defined(__MMI_CSTAR_GERMAN__) */
	#if defined(__MMI_CSTAR_GERMAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN
	},
	#endif /* #if defined(__MMI_CSTAR_GERMAN__) */
	#if defined(__MMI_CSTAR_ITALIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN
	},
	#endif /* #if defined(__MMI_CSTAR_ITALIAN__) */
	#if defined(__MMI_CSTAR_ITALIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN
	},
	#endif /* #if defined(__MMI_CSTAR_ITALIAN__) */
	#if defined(__MMI_CSTAR_RUSSIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN
	},
	#endif /* #if defined(__MMI_CSTAR_RUSSIAN__) */
	#if defined(__MMI_CSTAR_RUSSIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN
	},
	#endif /* #if defined(__MMI_CSTAR_RUSSIAN__) */
	#if defined(__MMI_CSTAR_BULGARIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN
	},
	#endif /* #if defined(__MMI_CSTAR_BULGARIAN__) */
	#if defined(__MMI_CSTAR_UKRAINIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN
	},
	#endif /* #if defined(__MMI_CSTAR_UKRAINIAN__) */
	#if defined(__MMI_CSTAR_UKRAINIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN
	},
	#endif /* #if defined(__MMI_CSTAR_UKRAINIAN__) */
	#if defined(__MMI_CSTAR_BULGARIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN
	},
	#endif /* #if defined(__MMI_CSTAR_BULGARIAN__) */
	#if defined(__MMI_CSTAR_TURKISH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH
	},
	#endif /* #if defined(__MMI_CSTAR_TURKISH__) */
	#if defined(__MMI_CSTAR_TURKISH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH
	},
	#endif /* #if defined(__MMI_CSTAR_TURKISH__) */
	#if defined(__MMI_CSTAR_PORTUGUESE__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE
	},
	#endif /* #if defined(__MMI_CSTAR_PORTUGUESE__) */
	#if defined(__MMI_CSTAR_PORTUGUESE__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,
	    IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE
	},
	#endif /* #if defined(__MMI_CSTAR_PORTUGUESE__) */
	#if defined(__MMI_CSTAR_INDONESIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN
	},
	#endif /* #if defined(__MMI_CSTAR_INDONESIAN__) */
	#if defined(__MMI_CSTAR_INDONESIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN
	},
	#endif /* #if defined(__MMI_CSTAR_INDONESIAN__) */
	#if defined(__MMI_CSTAR_CZECH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH
	},
	#endif /* #if defined(__MMI_CSTAR_CZECH__) */
	#if defined(__MMI_CSTAR_CZECH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_CZECH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_CZECH
	},
	#endif /* #if defined(__MMI_CSTAR_CZECH__) */
	#if defined(__MMI_CSTAR_MALAY__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY
	},
	#endif /* #if defined(__MMI_CSTAR_MALAY__) */
	#if defined(__MMI_CSTAR_MALAY__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_MALAY,
	    IMM_INPUT_MODE_SMART_LOWERCASE_MALAY
	},
	#endif /* #if defined(__MMI_CSTAR_MALAY__) */
	#if defined(__MMI_CSTAR_VIETNAMESE__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE
	},
	#endif /* #if defined(__MMI_CSTAR_VIETNAMESE__) */
	#if defined(__MMI_CSTAR_VIETNAMESE__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,
	    IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE
	},
	#endif /* #if defined(__MMI_CSTAR_VIETNAMESE__) */
	#if defined(__MMI_CSTAR_FINNISH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH
	},
	#endif /* #if defined(__MMI_CSTAR_FINNISH__) */
	#if defined(__MMI_CSTAR_FINNISH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH
	},
	#endif /* #if defined(__MMI_CSTAR_FINNISH__) */
	#if defined(__MMI_CSTAR_HUNGARIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN
	},
	#endif /* #if defined(__MMI_CSTAR_HUNGARIAN__) */
	#if defined(__MMI_CSTAR_HUNGARIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN
	},
	#endif /* #if defined(__MMI_CSTAR_HUNGARIAN__) */
	#if defined(__MMI_CSTAR_SLOVAKIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK
	},
	#endif /* #if defined(__MMI_CSTAR_SLOVAKIAN__) */
	#if defined(__MMI_CSTAR_SLOVAKIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK,
	    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK
	},
	#endif /* #if defined(__MMI_CSTAR_SLOVAKIAN__) */
	#if defined(__MMI_CSTAR_DUTCH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH
	},
	#endif /* #if defined(__MMI_CSTAR_DUTCH__) */
	#if defined(__MMI_CSTAR_DUTCH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH
	},
	#endif /* #if defined(__MMI_CSTAR_DUTCH__) */
	#if defined(__MMI_CSTAR_NORWEGIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN
	},
	#endif /* #if defined(__MMI_CSTAR_NORWEGIAN__) */
	#if defined(__MMI_CSTAR_NORWEGIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN
	},
	#endif /* #if defined(__MMI_CSTAR_NORWEGIAN__) */
	#if defined(__MMI_CSTAR_SWEDISH__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH
	},
	#endif /* #if defined(__MMI_CSTAR_SWEDISH__) */
	#if defined(__MMI_CSTAR_SWEDISH__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH,
	    IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH
	},
	#endif /* #if defined(__MMI_CSTAR_SWEDISH__) */
	#if defined(__MMI_CSTAR_CROATIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN
	},
	#endif /* #if defined(__MMI_CSTAR_CROATIAN__) */
	#if defined(__MMI_CSTAR_CROATIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN
	},
	#endif /* #if defined(__MMI_CSTAR_CROATIAN__) */
	#if defined(__MMI_CSTAR_ROMANIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN
	},
	#endif /* #if defined(__MMI_CSTAR_ROMANIAN__) */
	#if defined(__MMI_CSTAR_ROMANIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN
	},
	#endif /* #if defined(__MMI_CSTAR_ROMANIAN__) */
	#if defined(__MMI_CSTAR_SLOVENIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN
	},
	#endif /* #if defined(__MMI_CSTAR_SLOVENIAN__) */
	#if defined(__MMI_CSTAR_SLOVENIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN
	},
	#endif /* #if defined(__MMI_CSTAR_SLOVENIAN__) */
	#if defined(__MMI_CSTAR_GREEK__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK
	},
	#endif /* #if defined(__MMI_CSTAR_GREEK__) */
	#if defined(__MMI_CSTAR_GREEK__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_GREEK,
	    IMM_INPUT_MODE_SMART_LOWERCASE_GREEK
	},
	#endif /* #if defined(__MMI_CSTAR_GREEK__) */
	#if defined(__MMI_CSTAR_XHOSA__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA
	},
	#endif /* #if defined(__MMI_CSTAR_XHOSA__) */
	#if defined(__MMI_CSTAR_XHOSA__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_XHOSA,
	    IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA
	},
	#endif /* #if defined(__MMI_CSTAR_XHOSA__) */
	#if defined(__MMI_CSTAR_SWAHILI__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI
	},
	#endif /* #if defined(__MMI_CSTAR_SWAHILI__) */
	#if defined(__MMI_CSTAR_SWAHILI__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI,
	    IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI
	},
	#endif /* #if defined(__MMI_CSTAR_SWAHILI__) */
	#if defined(__MMI_CSTAR_AFRIKAANS__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS
	},
	#endif /* #if defined(__MMI_CSTAR_AFRIKAANS__) */
	#if defined(__MMI_CSTAR_AFRIKAANS__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS,
	    IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS
	},
	#endif /* #if defined(__MMI_CSTAR_AFRIKAANS__) */
	#if defined(__MMI_CSTAR_ZULU__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU
	},
	#endif /* #if defined(__MMI_CSTAR_ZULU__) */
	#if defined(__MMI_CSTAR_ZULU__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_ZULU,
	    IMM_INPUT_MODE_SMART_LOWERCASE_ZULU
	},
	#endif /* #if defined(__MMI_CSTAR_ZULU__) */
	#if defined(__MMI_CSTAR_LITHUANIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN
	},
	#endif /* #if defined(__MMI_CSTAR_LITHUANIAN__) */
	#if defined(__MMI_CSTAR_LITHUANIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN
	},
	#endif /* #if defined(__MMI_CSTAR_LITHUANIAN__) */
	#if defined(__MMI_CSTAR_LATVIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN
	},
	#endif /* #if defined(__MMI_CSTAR_LATVIAN__) */
	#if defined(__MMI_CSTAR_LATVIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_LATVIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN
	},
	#endif /* #if defined(__MMI_CSTAR_LATVIAN__) */
	#if defined(__MMI_CSTAR_ESTONIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN
	},
	#endif /* #if defined(__MMI_CSTAR_ESTONIAN__) */
	#if defined(__MMI_CSTAR_ESTONIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN
	},
	#endif /* #if defined(__MMI_CSTAR_ESTONIAN__) */
	#if defined(__MMI_CSTAR_ARMENIAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN
	},
	#endif /* #if defined(__MMI_CSTAR_ARMENIAN__) */
	#if defined(__MMI_CSTAR_ARMENIAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN
	},
	#endif /* #if defined(__MMI_CSTAR_ARMENIAN__) */
	#if defined(__MMI_CSTAR_MOLDOVAN__)
	{
	    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN,
	    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN
	},
	#endif /* #if defined(__MMI_CSTAR_MOLDOVAN__) */
	#if defined(__MMI_CSTAR_MOLDOVAN__)
	{
	    IMM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN,
	    IMM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN
	},
	#endif /* #if defined(__MMI_CSTAR_MOLDOVAN__) */
	{
		IMM_INPUT_MODE_NONE,
		IMM_INPUT_MODE_NONE
	}
};

#endif /* #ifdef __MMI_CSTAR_SURETYPE__ */

/* User data */

#define CS_USER_DATA_FILE     L"ime_data.dat"
#define CS_USER_DATA_SIZE    32768
static int cs_user_data[CS_USER_DATA_SIZE / sizeof(int)] = {0};

#define CS_OPTION_FILE        L"kmx_ime_option.dat"

#define CS_COMMIT_WORD_COUNT_FILE   L"kmx_cwc.dat"
#define CS_COMMIT_WORD_COUNT_MAX    500

#define CS_UI_CFG_BK_COLOR         (KMX_GUI_MAKE_COLOR(240, 240, 240))    /* Background color    */
#define CS_UI_CFG_TEXT_COLOR     (KMX_GUI_MAKE_COLOR(0, 0, 0))          /* Normal text color   */
#define CS_UI_CFG_HOT_COLOR_1   (KMX_GUI_MAKE_COLOR(0, 127, 255))      /* 1st extra hot color */
#define CS_UI_CFG_HOT_COLOR_2   (KMX_GUI_MAKE_COLOR(0, 0, 0))          /* 2nd extra hot color */
#define CS_UI_CFG_HOT_COLOR_3   (KMX_GUI_MAKE_COLOR(127, 127, 127))    /* 3rd extra hot color */
#define CS_UI_CFG_HOT_TEXT_COLOR (KMX_GUI_MAKE_COLOR(255, 255, 255))   /* hot without digit label */
#define CS_UI_CFG_HOT_BK_COLOR (KMX_GUI_MAKE_COLOR(0, 0, 0))           /* hot without digit label */
#define CS_UI_CFG_HOT_TEXT_COLOR_1 (KMX_GUI_MAKE_COLOR(255, 255, 255))   /* hot with digit label */
#define CS_UI_CFG_HOT_BK_COLOR_1 (KMX_GUI_MAKE_COLOR(0, 0, 0))           /* hot with digit label */
#define CS_UI_CFG_DIGIT_LABEL_COLOR  (KMX_GUI_MAKE_COLOR(0, 127, 255))   /* digit label color */
#define CS_UI_CFG_TIP_TEXT      (KMX_GUI_MAKE_COLOR(188, 65, 39))

#define CS_UI_CFG_BORDER_COLOR  (gui_color(79, 88, 113))

static color cs_border_color;
static void* cs_background_image;

static int g_kmx_curr_case_info;

/* User Data Storage Time Span */
/* Default to 5 minutes */
static unsigned int g_kmx_save_threshold_milli = 5 * 60 * 1000;
static unsigned int g_kmx_last_save_ticks;

static void kmx_update_last_save_time(void);
static int  kmx_is_time_to_save(void);

/* Half qwerty bopomofo */
#ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__
static gui_virtual_keyboard_pen_enum g_kmx_prev_key_event;
static S16 g_kmx_key_multitap;

void kmx_ime_reset_half_qwerty_status(void);
#endif

static int g_kmx_timer_started = 0;

#define KMX_EVENT_TYPE_KEY              0
#define KMX_EVENT_TYPE_CHAR             1
#define KMX_EVENT_TYPE_HALF_QWERTY      2

#define CS_BASE_MODE(mode) ((mode) & 0xFFFF)
static int kmx_ime_get_context(const unsigned short **text, int *length);

/* metric */
#if defined(__MMI_MAINLCD_320X480__)
#define CS_UI_LINE_TOP_GAP    4
#define CS_UI_LINE_BOTTOM_GAP 4
#else
#define CS_UI_LINE_TOP_GAP    2
#define CS_UI_LINE_BOTTOM_GAP 2
#endif

#if defined(__MMI_IME_FTE_ENHANCE__)
#define CS_UI_LINE_LEFT_GAP   3
#define CS_UI_LINE_RIGHT_GAP  3
#else
#define CS_UI_LINE_LEFT_GAP   0
#define CS_UI_LINE_RIGHT_GAP  0
#endif

#define IME_TIMER_CSTAR CSTAR_REQ_TIMER

static UI_font_type font_table[CS_UI_FONT_COUNT] = {
    &MMI_default_font,
    &MMI_small_font
};

static int                      cs_is_ime_supported = 1;
static int                      cs_mode_convert_disabled = 0;

static KMX_GUI_COLOR color_table[CS_UI_COLOR_COUNT];

int kmx_is_stroke_word_enabled(void);
int kmx_is_multitap_ime(void); // komoxo 2009-10-16
int cs_ui_cfg_imewnd_left(void);

static KMX_INPUT_MODE_ATTRIBUTES g_kmx_input_mode_attr;

/* KOMOXO pre defined user word start */
typedef struct  
{
    int im_mode;
    const CS_UI_WCHAR* word;
}USER_WORD_ENTRY;

static USER_WORD_ENTRY cs_user_words[] =
{
#ifdef __MMI_CSTAR_ENGLISH__
    { IM_ENGLISH, L"^-^"},
#endif
    
    /* place holder, avoid empty table */
    { IM_NONE, 0 }
};

int cstar_ime_traverse_predefined_user_words(CS_TRAVERSE_FUNC func)
{
    int i;
    for (i = 0; i < sizeof(cs_user_words) / sizeof(USER_WORD_ENTRY) - 1; i++)
    {
        func(cs_user_words[i].im_mode, cs_user_words[i].word, cs_ime_wcslen((unsigned short*)cs_user_words[i].word));
    }
    return 1;
       
}
/* KOMOXO pre defined user word end */

/*
 * Komoxo Fast Number Input
 *
*/
#ifdef KMX_CFG_FAST_NUMBER_INPUT 
typedef struct  {
    unsigned short enabled;
    unsigned short started;
    int interval;
    void (*time_proc)(void);
}KMXTimerContext;

static KMXTimerContext g_kmx_timer_ctx;

static void kmx_time_proc_wrapper(void);
#endif

static U32 cs_send_ime_message(mmi_imc_editor_message_id_enum msg_id, U32 param0, U32 param1);
void cs_end_comp(void);

int cs_gui_get_char_height(int font, CS_UI_WCHAR c)
{
    int width, height;
    UI_font_type save_font;

    save_font = UI_font;
    gui_set_font(font_table[font]);

    gui_measure_character(c, &width, &height);

    gui_set_font(save_font);

    return height;
}

int cs_gui_get_line_height(int font)
{
    return Get_CharHeightOfAllLang(font_table[font]->size) + CS_UI_LINE_TOP_GAP + CS_UI_LINE_BOTTOM_GAP;
}

int cs_gui_get_char_width(int font, CS_UI_WCHAR c)
{
    int width;
    UI_font_type save_font;

    save_font = UI_font;
    gui_set_font(font_table[font]);
#if defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__)
    return cs_gui_get_text_width(font, &c, 1);
#else
    {
        int height;
        gui_measure_character(c, &width, &height);
    }    
#endif

    gui_set_font(save_font);

    return width;
}

int cs_gui_get_text_width(int font, const CS_UI_WCHAR* text, int text_len)
{
    int width;
    UI_font_type save_font;

    save_font = UI_font;
    gui_set_font(font_table[font]);
    
#if defined(__MMI_VECTOR_FONT_SUPPORT__) && !defined(__MMI_SCRIPT_EASY__)
    {
        mmi_fe_get_string_info_param_struct query;
        memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
        query.String = (U8*) text;
        query.n = text_len;
        query.enableTruncated = MMI_FALSE;
        query.w = 0;
        mmi_fe_get_string_widthheight(&query);
        width = query.adv_w;
    }
#else
    width = gui_get_string_width_n((CS_UI_WCHAR*)text, text_len);
#endif     

    gui_set_font(save_font);

    return width;
}

void cs_gui_draw_pixel(int x, int y, int pixel_color)
{
    kmx_gui_draw_pixel(x, y, color_table[pixel_color]);  
}

void cs_gui_draw_rect(const CS_UI_RECT* r, int rect_color)
{
    int is_background_rect = 0;
    if (r->left == cs_ui_cfg_imewnd_left() && r->right == cs_ui_cfg_imewnd_right())
        is_background_rect = 1;

    if (is_background_rect)
    {        
        gui_push_clip();
	    gui_set_clip(r->left, r->top + 1, r->right - 1, r->bottom);
        
        mmi_ime_sdk_redraw_imui_background(r->left, r->top + 1, r->right - 1, r->bottom);
                
        if (cs_background_image)                
        {
            int i;
            int row;
            int line_height;
            KMX_GUI_RECT row_rect;
            #if defined(__MMI_WALLPAPER_ON_BOTTOM__) && !defined(__MMI_IME_FTE_ENHANCE__)
            gdi_handle old_src_layer,act_layer;
            #endif /*defined(__MMI_WALLPAPER_ON_BOTTOM__)*/

            line_height = cs_gui_get_line_height(CS_UI_TEXT_FONT);
            
            row = (r->bottom - r->top) / line_height;
            row_rect.left   = r->left;
            row_rect.right  = r->right;
            
            #if defined(__MMI_WALLPAPER_ON_BOTTOM__) && !defined(__MMI_IME_FTE_ENHANCE__)
            if (!wgui_is_wallpaper_on_bottom())
	        {
                gdi_image_abm_get_source_layer(&old_src_layer);
                gdi_layer_get_active(&act_layer);
                gdi_image_abm_set_source_layer(act_layer);
	        }
            #endif /*#if defined(__MMI_WALLPAPER_ON_BOTTOM__) && !defined(__MMI_IME_FTE_ENHANCE__)*/

            for (i = 0; i < row; i++)
            {                
                row_rect.top    = r->top + i * line_height;
                row_rect.bottom = row_rect.top + line_height;                
                kmx_gui_draw_resized_image(&row_rect, (void*) cs_background_image);
            }            
            
            #if defined(__MMI_WALLPAPER_ON_BOTTOM__) && !defined(__MMI_IME_FTE_ENHANCE__)
            if (!wgui_is_wallpaper_on_bottom())
	        {
                gdi_image_abm_set_source_layer(old_src_layer);
	        }
            #endif /*#if defined(__MMI_WALLPAPER_ON_BOTTOM__) && !defined(__MMI_IME_FTE_ENHANCE__)*/
        }        
        else
        {
            KMX_GUI_RECT rect;
            rect.left = r->left;
            rect.top = r->top;
            rect.right = r->right;
            rect.bottom = r->bottom;
            kmx_gui_draw_rect(&rect, color_table[rect_color]);
        }
                       
        if (CS_UI_LINE_TOP_GAP && CS_UI_LINE_BOTTOM_GAP)
        {
            #ifndef __MMI_IME_FTE_ENHANCE__
            gui_draw_horizontal_line(r->left, r->right, r->top + 1, cs_border_color);
            gui_draw_horizontal_line(r->left, r->right, r->bottom - 1, cs_border_color);
            #endif
        }

        gui_pop_clip();
    }
    else
    {
        KMX_GUI_RECT rect;
        rect.left = r->left;
        rect.top = r->top;
        rect.right = r->right;
        rect.bottom = r->bottom;
        kmx_gui_draw_rect(&rect, color_table[rect_color]);        
    }        
}

extern BOOL r2lMMIFlag;
extern BOOL cancelWidth;

void cs_gui_draw_text(int x, int y, int font,
    const CS_UI_WCHAR* text, int text_len, int text_color)
{
    gui_set_font(font_table[font]);
                
	if (r2lMMIFlag && !cancelWidth)
    {
        x = x + cs_gui_get_text_width(font, text, text_len) - 1;
    }

    y += 1;
    
    kmx_gui_draw_text(x, y, font_table[font]->size, text, text_len, color_table[text_color]);
}

void* cs_gui_load_ime_userdata(int *length)
/*
 * Load/Initialize user data from persistent storage.
 */
{
    S16 drive;
    FS_HANDLE file;
    kal_uint32 read;
    WCHAR name[FMGR_PATH_BUFFER_SIZE];
    
    drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    memset(name, 0, sizeof(name));
    kal_wsprintf((kal_wchar*)name, "%c:\\%w", drive, CS_USER_DATA_FILE);

    file = FS_Open(name, FS_READ_ONLY);
    if (file >= FS_NO_ERROR)
    {
        FS_Read(file, cs_user_data, CS_USER_DATA_SIZE, &read);
        FS_Close(file);
    }

    *length = CS_USER_DATA_SIZE;
    return cs_user_data;
}

void cs_gui_save_ime_userdata(void *data, int length)
/*
 * Save user data to persistent storage.
 */
{
    S16 drive;  
    FS_HANDLE file;
    kal_uint32 written;
    WCHAR name[FMGR_PATH_BUFFER_SIZE];
            
    if (!kmx_is_time_to_save())
        return;                 /* Time delta less than the required time span */
    
    kmx_update_last_save_time();

    drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE );

    memset(name, 0, sizeof(name));
    kal_wsprintf((kal_wchar*)name, "%c:\\%w", drive, CS_USER_DATA_FILE);

    file = FS_Open(name, FS_READ_WRITE | FS_CREATE);
    if (file >= FS_NO_ERROR)
    {
        FS_Write(file, data, length, &written);
        FS_Close(file);
    }
}

int cs_gui_load_ime_options(void *data, int *length)
/*
 * Load/Initialize IME options from persistent storage.
 */
{
    /*
     * TO DO: (Optional)
     *
     * If input method options can be set by end user, replace code
     * here to access persistent storage to load options data.
     * Otherwise, use default options.
     *
     * Default options can be obtained by cs_get_default_options()
     */
    S16 drive;
    FS_HANDLE file;
    kal_uint32 read;
    WCHAR name[FMGR_PATH_BUFFER_SIZE];
    int result = 0;
    
    drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    memset(name, 0, sizeof(name));
    kal_wsprintf((kal_wchar*)name, "%c:\\%w", drive, CS_OPTION_FILE);

    file = FS_Open(name, FS_READ_ONLY);
    if (file >= FS_NO_ERROR)
    {
        if(FS_Read(file, data, *length, &read) == FS_NO_ERROR)
        {
            *length = read;
            result = 1;
        }
        FS_Close(file);
    }
    else
    {
        /* Set Default Option */
        CS_IMM_OPTIONS* option;
        option = (CS_IMM_OPTIONS*) data;        
        option->dwPYFuzzy      = 0;
        option->dwStrokeLayout = CS_STROKE_STANDARD_LAYOUT;
        option->dwAssoPinyin   = CS_ASSOCIATION_ON;
        option->dwAssoStroke   = CS_ASSOCIATION_ON;
        option->dwPinyinMode   = CS_PINYIN_MODE_1;
        #if defined(__MMI_IME_FTE_ENHANCE__)
        option->dwCandidateMode = CS_CANDIDATE_MODE_1;
        option->dwAlphaBeticInputMode = CS_ALPHABETIC_WORD_INPUT;
        #else
        option->dwCandidateMode   = CS_CANDIDATE_MODE_2;                
        option->dwAlphaBeticInputMode = CS_ALPHABETIC_PHRASE_INPUT;
        #endif
        #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_128X160__)
        option->dwCandidateMode = CS_CANDIDATE_MODE_1;
        #endif
        result = 1;
    }
    /* Set Extra Callbacks */
    {
        /* Set Default Option */
        CS_IMM_OPTIONS* option;
        option = (CS_IMM_OPTIONS*) data;
        option->pfnGetContext = kmx_ime_get_context;
        option->pfnCheckValidHanzi = 0;        
    }    
    return result;
}

void cs_gui_save_ime_options(void *options, int length)
{
    S16 drive;  
    FS_HANDLE file;
    kal_uint32 written;
    WCHAR name[FMGR_PATH_BUFFER_SIZE];

    drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE );

    memset(name, 0, sizeof(name));
    kal_wsprintf((kal_wchar*)name, "%c:\\%w", drive, CS_OPTION_FILE);

    file = FS_Open(name, FS_READ_WRITE | FS_CREATE);
    if (file >= FS_NO_ERROR)
    {
        FS_Write(file, options, length, &written);
        FS_Close(file);
    }
}

    void cstar_ime_save_commit_word_count(int count)
    {
        S16 drive;  
        FS_HANDLE file;
        kal_uint32 written;
        WCHAR name[FMGR_PATH_BUFFER_SIZE];

        drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE );

        memset(name, 0, sizeof(name));
        kal_wsprintf((kal_wchar*)name, "%c:\\%w", drive, CS_COMMIT_WORD_COUNT_FILE);

        file = FS_Open(name, FS_READ_WRITE | FS_CREATE);
        if (file >= FS_NO_ERROR)
        {
            FS_Write(file, &count, sizeof(int), &written);
            FS_Close(file);
        }
    }

    int cstar_ime_load_commit_word_count(void)
    {
        S16 drive;
        FS_HANDLE file;
        int        count = 0;
        kal_uint32 read;
        WCHAR name[FMGR_PATH_BUFFER_SIZE];
        int result = 0;
    
        drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

        memset(name, 0, sizeof(name));
        kal_wsprintf((kal_wchar*)name, "%c:\\%w", drive, CS_COMMIT_WORD_COUNT_FILE);

        file = FS_Open(name, FS_READ_ONLY);
        if (file >= FS_NO_ERROR)
        {
            result = FS_Read(file, &count, sizeof(int), &read) == FS_NO_ERROR;
            FS_Close(file);

            if(!result)
            {
                cstar_ime_save_commit_word_count(CS_COMMIT_WORD_COUNT_MAX);
                return CS_COMMIT_WORD_COUNT_MAX;
            }
        }
        else
        {
            cstar_ime_save_commit_word_count(CS_COMMIT_WORD_COUNT_MAX);
            return CS_COMMIT_WORD_COUNT_MAX;
        }
        return count;
    }

static void cs_gui_remove_ime_options_file(void)
/*
 * Load/Initialize IME options from persistent storage.
 */
{
    S16 drive;
    WCHAR name[FMGR_PATH_BUFFER_SIZE];    
    
    drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    memset(name, 0, sizeof(name));
    kal_wsprintf((kal_wchar*)name, "%c:\\%w", drive, CS_OPTION_FILE);

    FS_Delete(name);
}

#ifdef KMX_CFG_FAST_NUMBER_INPUT 
static void kmx_time_proc_wrapper(void)
{
    #ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__
    kmx_ime_reset_half_qwerty_status();
    #endif
    
    if (g_kmx_timer_ctx.time_proc)
    {
    g_kmx_timer_ctx.time_proc();    
    }    
    g_kmx_timer_ctx.enabled = 0;
    g_kmx_timer_ctx.started = 0;
    g_kmx_timer_started = 0;
}

static void kmx_start_ime_timer(void)
{
    if (!g_kmx_timer_ctx.started)
    {     
        StartTimer(IME_TIMER_CSTAR, g_kmx_timer_ctx.interval, kmx_time_proc_wrapper);
        g_kmx_timer_ctx.started = 1;
    }    
}

static void kmx_stop_ime_timer(void)
{
    cs_gui_disable_ime_timer();
}

static void kmx_rollback_key_down_effect(void)
{
    mmi_ime_sdk_state_enum state;
    state = mmi_ime_sdk_get_state();

    gdi_layer_lock_frame_buffer();
    if (state != MMI_IME_SDK_STATE_INITIAL)
    {
        if (state == MMI_IME_SDK_STATE_MULTITAP)
        {
            cs_send_ime_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
        }
        mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
    }
    else
    {
        /* Fallback compatiblity, in early version we dont set MMI_IMC_STATE_MULTITAP when multitap */
        cs_send_ime_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
        cs_reset();        
    }
    gdi_layer_unlock_frame_buffer();
}
#endif

void cs_gui_disable_ime_timer(void)
{
    #ifdef KMX_CFG_FAST_NUMBER_INPUT 
    if (g_kmx_timer_ctx.enabled && g_kmx_timer_ctx.started)
    {
        StopTimer(IME_TIMER_CSTAR);        
    }
    g_kmx_timer_ctx.enabled = 0;
    g_kmx_timer_ctx.started = 0;   
    #else
    if (g_kmx_timer_started)
    {
        StopTimer(IME_TIMER_CSTAR);
    }    
    #endif
    g_kmx_timer_started = 0;
}

static void (*g_kmx_time_proc)(void);

static void kmx_ime_timer_proc_wrapper(void)
{
    if (g_kmx_timer_started)
    {
        #ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__
        kmx_ime_reset_half_qwerty_status();
        #endif
        if (g_kmx_time_proc)
        {
            g_kmx_time_proc();
        }
    }
    g_kmx_timer_started = 0;
}

#ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__
static void kmx_ime_cancel_timer(void)
{
    #ifdef KMX_CFG_FAST_NUMBER_INPUT
    if (g_kmx_timer_ctx.enabled && g_kmx_timer_ctx.started)
    {
        kmx_time_proc_wrapper();        
    }
    kmx_stop_ime_timer();
    #else
    if (g_kmx_timer_started)
    {
        kmx_ime_timer_proc_wrapper();
        cs_gui_disable_ime_timer();
    }    
    #endif
}

static void kmx_ime_suspend_timer(void)
{
    StopTimer(IME_TIMER_CSTAR);
}
#endif 

static void kmx_ime_wrap_time_proc(void (*time_proc)(void))
{
    g_kmx_time_proc = time_proc;
}

void cs_gui_enable_ime_timer(int interval, void (*time_proc)(void))
{
    #ifdef KMX_CFG_FAST_NUMBER_INPUT    
    g_kmx_timer_ctx.enabled = 1;
    g_kmx_timer_ctx.started = 0;
    g_kmx_timer_ctx.interval = interval;
    g_kmx_timer_ctx.time_proc = time_proc;
    #else
    kmx_ime_wrap_time_proc(time_proc);
    StartTimer(IME_TIMER_CSTAR, interval, kmx_ime_timer_proc_wrapper);    
    #endif
    g_kmx_timer_started = 1;
}

static KMX_GUI_COLOR gui_color_to_kmx_color(color c)
{
    return KMX_GUI_MAKE_COLOR(c.r, c.g, c.b);
}

void cs_initialize_tables(void)
{
    UI_ime_theme * now_using_theme = NULL;

    now_using_theme = mmi_ime_sdk_get_ime_theme();

    if (now_using_theme)
    {
        color_table[CS_UI_BK_COLOR]          = CS_UI_CFG_BK_COLOR;
        color_table[CS_UI_TEXT_COLOR]        = gui_color_to_kmx_color(now_using_theme->cand_text_color);
        color_table[CS_UI_HOT_COLOR_1]       = gui_color_to_kmx_color(now_using_theme->input_text_color);
        color_table[CS_UI_HOT_COLOR_2]       = gui_color_to_kmx_color(now_using_theme->comp_highlighted_text_color);
        color_table[CS_UI_HOT_COLOR_3]       = gui_color_to_kmx_color(now_using_theme->comp_highlight_color);
        color_table[CS_UI_HOT_TEXT_COLOR]    = gui_color_to_kmx_color(now_using_theme->cand_highlighted_text_color);
        color_table[CS_UI_HOT_BK_COLOR]      = gui_color_to_kmx_color(now_using_theme->cand_highlight_color);
        color_table[CS_UI_HOT_TEXT_COLOR_1]  = gui_color_to_kmx_color(now_using_theme->cand_highlighted_text_color);
        color_table[CS_UI_HOT_BK_COLOR_1]    = gui_color_to_kmx_color(now_using_theme->cand_highlight_color);
        color_table[CS_UI_DIGIT_LABEL_COLOR] = gui_color_to_kmx_color(now_using_theme->label_color);
        color_table[CS_UI_TIP_TEXT]          = CS_UI_CFG_TIP_TEXT;
        
        cs_border_color         = now_using_theme->border_color;        
        #ifdef __MMI_IME_FTE_ENHANCE__
        cs_background_image     = (void*)now_using_theme->cand_background_large;
        #else
        cs_background_image     = (void*)now_using_theme->background_filler;
        #endif
        
        #ifdef __MMI_KMX_VUI_SUPPORT__
        if (mmi_ime_sdk_is_in_venus_ui_engine_state())
            cs_background_image = GetImage(VADP_IMG_IME_CAND_BG_LARGE);
        #endif

        return;
    }    
    
    /* Default colors */
    color_table[CS_UI_BK_COLOR]    = CS_UI_CFG_BK_COLOR;
    color_table[CS_UI_TEXT_COLOR]  = CS_UI_CFG_TEXT_COLOR;
    color_table[CS_UI_HOT_COLOR_1] = CS_UI_CFG_HOT_COLOR_1;
    color_table[CS_UI_HOT_COLOR_2] = CS_UI_CFG_HOT_COLOR_2;
    color_table[CS_UI_HOT_COLOR_3] = CS_UI_CFG_HOT_COLOR_3;
    color_table[CS_UI_HOT_TEXT_COLOR] = CS_UI_CFG_HOT_TEXT_COLOR;
    color_table[CS_UI_HOT_BK_COLOR] = CS_UI_CFG_HOT_BK_COLOR;
    color_table[CS_UI_HOT_TEXT_COLOR_1] = CS_UI_CFG_HOT_TEXT_COLOR_1;
    color_table[CS_UI_HOT_BK_COLOR_1] = CS_UI_CFG_HOT_BK_COLOR_1;
    color_table[CS_UI_DIGIT_LABEL_COLOR] = CS_UI_CFG_DIGIT_LABEL_COLOR;
    color_table[CS_UI_TIP_TEXT]    = CS_UI_CFG_TIP_TEXT;

    cs_border_color      = CS_UI_CFG_BORDER_COLOR;        
    cs_background_image     = NULL;    
}

void cs_initialize_ui_extra_metric(CS_UI_EXTRA_METRICS* metrics)
{
    if (metrics)
    {
        metrics->line_top_gap    = CS_UI_LINE_TOP_GAP;
        metrics->line_bottom_gap = CS_UI_LINE_BOTTOM_GAP;
        metrics->line_left_gap   = CS_UI_LINE_LEFT_GAP;
        metrics->line_right_gap  = CS_UI_LINE_RIGHT_GAP;        
    }
}

void cs_gui_set_state(CS_IMM_STATE state)
{
    switch(state)
    {
    case CS_IMM_STATE_INITIAL:
        mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
        break;
    case CS_IMM_STATE_VK_CAND:
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        mmi_ime_sdk_set_state((mmi_ime_sdk_state_enum)MMI_IME_SDK_STATE_CAND_SELECTING);
#else
        mmi_ime_sdk_set_state((mmi_ime_sdk_state_enum)MMI_IME_SDK_STATE_VK_CAND);
#endif
        break;
// komoxo 2010-3-4
    case CS_IMM_STATE_MULTITAP:
        mmi_ime_sdk_set_state((mmi_ime_sdk_state_enum)MMI_IME_SDK_STATE_MULTITAP);
        break;
    case CS_IMM_STATE_CAND_SELECT:
        mmi_ime_sdk_set_state((mmi_ime_sdk_state_enum)MMI_IME_SDK_STATE_CAND_SELECTING);
        break;
    }
}

int kmx_is_pinyin_ime(int m)
{
    return m == IMM_INPUT_MODE_SM_PINYIN  || 
            m == IMM_INPUT_MODE_SM_MULTITAP_PINYIN || 
            m == IMM_INPUT_MODE_SM_STROKE;
}

int kmx_is_zhuyin_ime(int m)
{
    return m == IMM_INPUT_MODE_TR_BOPOMO || 
            m == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO || 
            m == IMM_INPUT_MODE_TR_STROKE;
}

#ifdef __MMI_CSTAR_SURETYPE__

    static mmi_imm_input_mode_enum get_case_switch_mode(mmi_imm_input_mode_enum input_mode)
    {
	    mmi_imm_input_mode_enum switch_mode = IMM_INPUT_MODE_NONE;
	    const KMX_IME_MODE_PAIR * e = g_mode_pair_table;
	    int index = -1;
	    
	    while(e->mode[0] != IMM_INPUT_MODE_NONE)
	    {
		    if (e->mode[0] == input_mode)
		    {
			    index = 0;
			    break;		
		    }
		    if (e->mode[1] == input_mode)
		    {
			    index = 1;
			    break;
		    }
		    e++;
	    }
	    
	    if (index >= 0)
	    {
		    switch_mode = e->mode[index ^ 1];
	    }
	    
	    return switch_mode;
    }

    int kmx_convert_to_suretype_im(int imm_mode)
    {
        if(imm_mode == IM_PINYIN || (imm_mode >= IM_ENGLISH && imm_mode <= IM_ENGLISH_LOWER))
		{
			return imm_mode + IM_SURETYPE_BASE;
		}

        return imm_mode;
    }

#endif

int cstar_ime_is_suretype_enabled(void)
{
#ifdef __MMI_CSTAR_SURETYPE__
    return 1;
#else
    return 0;
#endif
}

#define IS_CS_LATIN_MODE(mode) ((mode) >= IM_ENGLISH && (mode) < IM_SURETYPE_BASE)

int CS_GuiMode2CstarMode(int input_method)
/*
 * Convert platform dependent input method ID to CSTAR input method ID
 *
 */
{
    /*
     * TO DO:
     *
     * Replace code here to convert input method ID.
     *
     * List of CSTAR input method ID:
     *
     *      IM_PINYIN     --> 拼音输入法
     *      IM_STROKE     --> 笔画输入法
     *      IM_ENGLISH    --> 智能英文输入法
     *      IM_ABC_LOWER  --> 小写英文Multitap输入法
     *      IM_ABC_UPPER  --> 大写英文Multitap输入法
     *      IM_123        --> 数字输入法
     */

    /* Touch screen configuration */
    int i = 0;
    
    /* Tricky and highly coupled!!!! */
    if (cs_mode_convert_disabled)
    {
        return input_method;
    }
    
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    if ((mmi_ime_sdk_get_current_input_type() == IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD)
        || (mmi_ime_sdk_get_current_input_type() == IMM_INPUT_TYPE_ASCII_PASSWORD))
    {
        return 0;
    }
    #endif

    for(; i < sizeof(g_cstar_mode_map_table) / sizeof(MODE_MAP_ENTRY); ++i)
    {
        if(g_cstar_mode_map_table[i].input_mode == (unsigned int)input_method)
        {
            #ifdef __MMI_CSTAR_SURETYPE__
            return kmx_convert_to_suretype_im(g_cstar_mode_map_table[i].cstar_mode);
            #else
            {
                int cstar_mode;
                cstar_mode = (int)g_cstar_mode_map_table[i].cstar_mode;
                #if defined(__MMI_KMX_QWERTY_ASSO__)
                if (IS_CS_LATIN_MODE(cstar_mode))
                {
                    cstar_mode += IM_LATINFULLKEY_BASE;
                }
                #endif
                return cstar_mode;
            }            
            #endif
        }
    }        

    return 0;
}

static void kmx_ime_on_change_input_method(int input_method)
{
    int cstar_mode;
    cstar_mode = CS_GuiMode2CstarMode(input_method);

    if (cstar_mode == IM_NONE)
    {
        cs_is_ime_supported = 0;
    }
    else
    {
        cs_is_ime_supported = 1;
    }

}

int cstar_ime_is_ime_support(void)
{    
    return cs_is_ime_supported;
}

static CS_UI_RECT g_ime_wnd_rect;

int cs_ui_cfg_imewnd_left(void)
{        
    return g_ime_wnd_rect.left; 
}

int cs_ui_cfg_imewnd_right(void)
{    
    return g_ime_wnd_rect.right;
}

int cstar_ime_change_ime(int input_mode)
{
    cs_end_comp();
    cs_gui_disable_ime_timer();

    mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
    mmi_ime_sdk_set_current_input_mode((mmi_imm_input_mode_enum)input_mode);
    if (mmi_ime_sdk_change_input_mode((mmi_imm_input_mode_enum)input_mode))
        return 1;

    return 0;
}

int kmx_ime_set_input_mode(int input_mode)
{
    // TODO: we should enhance set input method so we dont have to reset state explicitly.
    cs_end_comp();
    cstar_ime_set_input_method(input_mode);
    cs_gui_disable_ime_timer();
    if (cs_is_ime_supported)
    {
        kmx_get_input_mode_attr(input_mode, &g_kmx_input_mode_attr);
    }
    g_kmx_curr_case_info = g_kmx_input_mode_attr.case_info;
    return cs_is_ime_supported;
}

int cstar_ime_change_input_mode(void)
{
    if (mmi_ime_sdk_get_current_allowed_input_mode_num() > 1)
    {
        gdi_layer_lock_frame_buffer();
            
        /* Trick to  */
        cs_end_comp();
        if (cstar_ime_change_ime(mmi_ime_sdk_get_next_input_mode()))
            cs_send_ime_message(MMI_IMC_MESSAGE_MODE_CHANGED, 0, 0);
        mmi_ime_sdk_redraw_screen_by_state();

        gdi_layer_unlock_frame_buffer();
        gdi_lcd_repaint_all();
    }
    return 1;
}

#ifdef __MMI_CSTAR_SURETYPE__

    static int cstar_ime_handle_l4_key(int key_type)
    {
        mmi_imm_input_mode_enum im_mode = get_case_switch_mode(mmi_ime_sdk_get_current_input_mode());

        if(im_mode != IMM_INPUT_MODE_NONE)
        {
            if (mmi_ime_sdk_set_current_input_mode(im_mode))
            {
                mmi_imc_message_struct imc_msg = {0};
    
                mmi_ime_sdk_change_input_mode(im_mode, 0);

                imc_msg.message_id    = MMI_IMC_MESSAGE_MODE_CHANGED;
                mmi_ime_sdk_send_editor_msg(&imc_msg);       
                cs_gui_invalidate();
            }
        }
        return 1;
    }

    static int cstar_ime_handle_r4_key(int key_type)
    {
        if(key_type == KEY_EVENT_DOWN)
        {
            cs_insert_text(L"\n", 1);
            return 1;
        }
        return 0;
    }

#endif

void cstar_complete_input(void);

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static void kmx_ime_input_char(unsigned short ch);
#endif 

int cstar_ime_handle_key(int key_code, int key_type, int ucs2_value)
{
    int presshold = 0;
    int result = 0;
    int is_char_input = 0;

    if(key_type == KEY_EVENT_UP)
    {
        #ifdef KMX_CFG_FAST_NUMBER_INPUT 
        if (g_kmx_timer_ctx.enabled)
        {                
            kmx_start_ime_timer();
        }
        #endif

        switch (key_code)
        {
            case KEY_LSK:
            case KEY_ENTER:
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            case KEY_QWERTY_ENTER:
                if (mmi_ime_sdk_get_current_input_mode() != IMM_INPUT_MODE_SM_STROKE && mmi_ime_sdk_get_current_input_mode() != IMM_INPUT_MODE_TR_STROKE)
                    is_char_input = 1;            
            #endif
                key_code = CS_UI_KEY_LSK;
                #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                if (!cstar_ime_is_ui_visible())
                {
                    kmx_ime_input_char('\n');
                    return 1;
                }
                #endif
                break;
            case KEY_RSK:
            case KEY_CLEAR:                           				
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            case KEY_BACKSPACE:
                if (mmi_ime_sdk_get_current_input_mode() != IMM_INPUT_MODE_SM_STROKE && mmi_ime_sdk_get_current_input_mode() != IMM_INPUT_MODE_TR_STROKE)
                    is_char_input = 1;            
            #endif
                key_code = CS_UI_KEY_RSK;
                break;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            case KEY_SPACE:            
                kmx_ime_input_char(ucs2_value);
                return 1;
            case KEY_SYMBOL:
                if (!mmi_ime_sdk_is_symbol_picker_disabled())            
                    EntrySymbolPickerScreen();
                return 1;
            #endif
            #if defined(KMX_CFG_KEY_UP_IME_SWITCH)
                #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                case KEY_QWERTY_MENU:                
                #endif            
                case KEY_POUND:                        
                    return cstar_ime_change_input_mode();
            #endif /* KMX_CFG_KEY_UP_IME_SWITCH */
            default:
                return 0;
        }
    }
    else if(key_type == KEY_EVENT_DOWN || key_type == KEY_LONG_PRESS)
    {
        if(key_type == KEY_LONG_PRESS)
        {
            presshold = 1;
            #ifdef KMX_CFG_FAST_NUMBER_INPUT 
            if (g_kmx_timer_ctx.enabled)
            {
                kmx_stop_ime_timer();
                kmx_rollback_key_down_effect();
            }
            #endif
        }

        switch (key_code)
        {
            case KEY_0:
            case KEY_1:
            case KEY_2:
            case KEY_3:
            case KEY_4:
            case KEY_5:
            case KEY_6:
            case KEY_7:
            case KEY_8:
            case KEY_9:
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                if (key_code == KEY_0)
                {
                    is_char_input = 1;
                    key_code = '0';
                }
                else
            #endif
                key_code = key_code - KEY_0 + CS_UI_KEY_0;
                #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                if (mmi_frm_qwerty_get_customized_special_key_flag() & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN
                    && !cstar_ime_is_ui_visible())
                {
                    kmx_ime_input_char(ucs2_value);
                    return 1;
                }
                #endif
                break;
            #ifdef __MMI_CSTAR_SURETYPE__
            case KEY_L1:
                key_code = CS_UI_KEY_L1;
                break;
            case KEY_L2:
                key_code = CS_UI_KEY_L2;
                break;
            case KEY_L3:
                key_code = CS_UI_KEY_L3;
                break;
            case KEY_L4:
                return cstar_ime_handle_l4_key(key_type);
            case KEY_R1:
                key_code = CS_UI_KEY_R1;
                break;
            case KEY_R2:
                key_code = CS_UI_KEY_R2;
                break;
            case KEY_R3:
                key_code = CS_UI_KEY_R3;
                break;
            case KEY_R4:
                return cstar_ime_handle_r4_key(key_type);
            #endif            
            #if defined(KMX_CFG_KEY_DOWN_IME_SWITCH)
            #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
            case KEY_QWERTY_MENU:                
            #endif            
            case KEY_POUND:                        
                return cstar_ime_change_input_mode();
            #endif /* KMX_CFG_KEY_DOWN_IME_SWITCH */
            case KEY_STAR:                
                key_code = CS_UI_KEY_STAR;
                break;                            
            case KEY_LEFT_ARROW:
                key_code = CS_UI_KEY_LEFT;
                break;
            case KEY_RIGHT_ARROW:
                key_code = CS_UI_KEY_RIGHT;
                break;
            case KEY_UP_ARROW:
                key_code = CS_UI_KEY_UP;
                break;
            case KEY_DOWN_ARROW:
                key_code = CS_UI_KEY_DOWN;
                break;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            case KEY_A:
            case KEY_B:
            case KEY_C:
            case KEY_D:
            case KEY_E:
            case KEY_F:
            case KEY_G:
            case KEY_H:
            case KEY_I:
            case KEY_J:
            case KEY_K:
            case KEY_L:
            case KEY_M:
            case KEY_N:
            case KEY_O:
            case KEY_P:
            case KEY_Q:
            case KEY_R:
            case KEY_S:
            case KEY_T:
            case KEY_U:
            case KEY_V:
            case KEY_W:
            case KEY_X:
            case KEY_Y:
            case KEY_Z:
                is_char_input = 1;
                key_code = key_code - KEY_A + 'a';
                /* handle 0-9 digit selection */
                {                    
                    if (ucs2_value >= '0' && ucs2_value <= '9' && cstar_ime_is_ui_visible())
                    {
                        key_code = ucs2_value - '0' + CS_UI_KEY_0;
                        break;
                    }
                    if (!cstar_ime_is_ui_visible() && (mmi_frm_qwerty_get_customized_special_key_flag() & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN))
                    {
                        /* insert ucs2 code when fn enabled. */
                        kmx_ime_input_char(ucs2_value);
                        return 1;
                    }                    
                }
                break;
            case KEY_PERIOD:
                is_char_input = 1;
                key_code = '.';
                if (cstar_ime_is_ui_visible() 
                    && (mmi_ime_sdk_get_current_input_mode() == IMM_INPUT_MODE_SM_PINYIN 
                    || mmi_ime_sdk_get_current_input_mode() == IMM_INPUT_MODE_SM_MULTITAP_PINYIN)
                   )
                {
                    key_code = '\'';
                }
                if (mmi_frm_qwerty_get_customized_special_key_flag() & MMI_FRM_QWERTY_SPECIAL_KEY_FLAG_FN)
                {
                    /* insert ucs2 code when fn enabled. */
                    kmx_ime_input_char(ucs2_value);
                    return 1;
                }                                    
                break;
            case KEY_SHIFT:                
                {
                    const KMX_INPUT_MODE_ATTRIBUTES* mode_attr;
                    mode_attr = kmx_get_curr_input_mode_attr();
                    /* TODO: May be we should cancel shift status for no smart case-sensitive input */
                    if (mode_attr->ime == KMX_IME_LATIN_MULTITAP || mode_attr->ime == KMX_IME_LATIN_SMART)
                    {
                        cs_gui_set_state(CS_IMM_STATE_INITIAL);
                        cs_gui_invalidate();
                    }
                    return 0;
                }
            #endif
            case KEY_LSK:                        
            case KEY_RSK:
            case KEY_CLEAR:                           				
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            case KEY_BACKSPACE:
            case KEY_FN:
            case KEY_SYMBOL:
            #endif
            #if defined(KMX_CFG_KEY_UP_IME_SWITCH)
            #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
            case KEY_QWERTY_MENU:                
            #endif            
            case KEY_POUND:                        
            #endif /* KMX_CFG_KEY_UP_IME_SWITCH */
                return 0;
            default:
                #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                is_char_input = 1;
                #endif
                key_code = CS_UI_KEY_BASE;
                break;
        }
    }

    gdi_layer_lock_frame_buffer();
    //cstar_lock_editor_draw();
    result = cstar_ime_handle_event(is_char_input, key_code, presshold);
    //cstar_unlock_editor_draw();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();

    if(!result)
    {
        #if !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        if(key_code == CS_UI_KEY_STAR && key_type == KEY_EVENT_DOWN)
        {
            if (!mmi_ime_sdk_is_symbol_picker_disabled())            
                EntrySymbolPickerScreen();
            result = 1;
        }
        #endif
        if (cstar_ime_is_ui_visible() && (key_code == CS_UI_KEY_DOWN || key_code == CS_UI_KEY_UP))
        {
            /* always eat up and down event if ui is visible. */
            result = 1;
        }
        #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        if (key_code == '.')
        {
            kmx_ime_input_char(ucs2_value);
            return 1;
        }
        #endif

    }
    if (key_code == CS_UI_KEY_RSK && key_type == KEY_EVENT_UP) // komoxo 2009-10-16
    {
        if(kmx_is_multitap_ime())
            cs_end_comp();
    }
    return result;
}

const CS_IME_INFO_PTR cs_input_method_config[] =
{
    #if defined(__MMI_CSTAR_SM_CHINESE__)
        #ifdef __MMI_CSTAR_SURETYPE__
        &cs_ldb_pinyin_suretype,
        #else
        &cs_ldb_pinyin_cizu,     
        #endif

        #ifdef __MMI_CSTAR_STROKE_INPUT__
        &cs_ldb_stroke_chs,
        #endif

    #endif

    #if defined(__MMI_CSTAR_TR_CHINESE__)
        &cs_ldb_zhuyin,

        #ifdef __MMI_CSTAR_STROKE_INPUT__
        &cs_ldb_stroke_big5,
        #endif
    #endif

    #if defined(__MMI_CSTAR_ENGLISH__)
        #if defined(__MMI_CSTAR_SURETYPE__)
        &cs_ldb_english_suretype,
        #else
        &cs_ldb_english,
        #endif
    #endif

    #if defined(__MMI_CSTAR_RUSSIAN__)
        &cs_ldb_russian,
    #endif

    #if defined(__MMI_CSTAR_GERMAN__)
        &cs_ldb_german,
    #endif

    #if defined(__MMI_CSTAR_VIETNAMESE__)
        &cs_ldb_vietnamese,
    #endif

    #if defined(__MMI_CSTAR_INDONESIAN__)
        &cs_ldb_indonesian,
    #endif

    #if defined(__MMI_CSTAR_TURKISH__)
        &cs_ldb_turkish,
    #endif

    #if defined(__MMI_CSTAR_MALAY__)
        &cs_ldb_malay,
    #endif

    #if defined(__MMI_CSTAR_GREEK__)
        &cs_ldb_greek,
    #endif

    #if defined(__MMI_CSTAR_THAI__)
        &cs_ldb_thai,
    #endif

    #if defined(__MMI_CSTAR_DANISH__)
        &cs_ldb_danish,
    #endif

    #if defined(__MMI_CSTAR_DUTCH__)
        &cs_ldb_dutch,
    #endif

    #if defined(__MMI_CSTAR_POLISH__)
        &cs_ldb_polish,
    #endif

    #if defined(__MMI_CSTAR_FRENCH__)
        &cs_ldb_french,
    #endif

    #if defined(__MMI_CSTAR_HUNGARIAN__)
        &cs_ldb_hungarian,
    #endif

    #if defined(__MMI_CSTAR_HEBREW__)
        &cs_ldb_hebrew,
    #endif

    #if defined(__MMI_CSTAR_BULGARIAN__)
        &cs_ldb_bulgarian,
    #endif

    #if defined(__MMI_CSTAR_CZECH__)
        &cs_ldb_czech,
    #endif

    #if defined(__MMI_CSTAR_FINNISH__)
        &cs_ldb_finnish,
    #endif

    #if defined(__MMI_CSTAR_SLOVAK__)
        &cs_ldb_slovak,
    #endif

    #if defined(__MMI_CSTAR_NORWEGIAN__)
        &cs_ldb_norwegian,
    #endif

    #if defined(__MMI_CSTAR_SWEDISH__)
        &cs_ldb_swedish,
    #endif

    #if defined(__MMI_CSTAR_SPANISH__)
        &cs_ldb_spanish,
    #endif

    #if defined(__MMI_CSTAR_CROATIAN__)
        &cs_ldb_croatian,
    #endif

    #if defined(__MMI_CSTAR_ROMANIAN__)
        &cs_ldb_romanian,
    #endif

    #if defined(__MMI_CSTAR_SLOVENIAN__)
        &cs_ldb_slovenian,
    #endif

    #if defined(__MMI_CSTAR_PORTUGUESE__)
        &cs_ldb_portuguese,
    #endif

    #if defined(__MMI_CSTAR_ITALIAN__)
        &cs_ldb_italian,
    #endif

    #if defined(__MMI_CSTAR_ARABIC__)
        &cs_ldb_arabic,
    #endif

    #if defined(__MMI_CSTAR_HINDI__)
        &cs_ldb_hindi,
    #endif

    #if defined(__MMI_CSTAR_PERSIAN__)
        &cs_ldb_persian,
    #endif

    #if defined(__MMI_CSTAR_SWAHILI__)
        &cs_ldb_swahili,
    #endif

    #if defined(__MMI_CSTAR_UKRAINIAN__)
        &cs_ldb_ukrainian,
    #endif

    #if defined(__MMI_CSTAR_LITHUANIAN__)
        &cs_ldb_lithuanian,
    #endif

    #if defined(__MMI_CSTAR_HINGLISH__)
        &cs_ldb_hinglish,
    #endif

    #if defined(__MMI_CSTAR_ARMENIAN__)
        &cs_ldb_armenian,
    #endif

    #if defined(__MMI_CSTAR_BENGALI__)
        &cs_ldb_bengali,
    #endif
	
	#if defined(__MMI_CSTAR_URDU__)
        &cs_ldb_urdu,
    #endif


    0
};

void cs_gui_invalidate(void)
{
    mmi_ime_sdk_redraw_screen_by_state();
}

int kmx_is_input_mode_multitap(mmi_imm_input_mode_enum input_mode)
{
    const sIMEModeDetails * mode_details_ptr;

    if (input_mode == IMM_INPUT_MODE_SM_STROKE || input_mode == IMM_INPUT_MODE_TR_STROKE
        || input_mode == IMM_INPUT_MODE_SM_PINYIN || input_mode == IMM_INPUT_MODE_TR_BOPOMO
        || input_mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN || input_mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO)
    {
        return 0;
    }
    
    mode_details_ptr = mmi_ime_sdk_get_input_mode_array_item(input_mode);

    if (mode_details_ptr == NULL)
        return 0;

    return (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP) != 0;
}

int kmx_is_multitap_ime(void)
{
    return kmx_is_input_mode_multitap(mmi_ime_sdk_get_current_input_mode());
}

static U32 cs_send_ime_message(mmi_imc_editor_message_id_enum msg_id, U32 param0, U32 param1)
{
    mmi_imc_message_struct msg;
        
    msg.message_id = msg_id;
    msg.param_0 = param0;
    msg.param_1 = param1;

    return mmi_ime_sdk_send_editor_msg(&msg);
}

static int comp_text_length = 0;
static int cs_is_multitap_comp_set = 0;

void cs_set_comp(const unsigned short *text, int length)
{    
    if(kmx_is_multitap_ime() && length == 1)
    {
        if(comp_text_length == 0)
        {
            cs_send_ime_message(MMI_IMC_MESSAGE_START_SMART_ALPHABETIC, 0, 0);
        }
        cs_send_ime_message(MMI_IMC_MESSAGE_INSERT_MULTITAP_CHAR, (int)text[0], 0);
        cs_is_multitap_comp_set = 1;
    }
    else
    {
        cs_send_ime_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, comp_text_length, (int)text);
        cs_is_multitap_comp_set = 0;
    }

    comp_text_length = length;
}

void cs_clear_comp(void)
{
    if (comp_text_length > 0 && comp_text_length != 1)
    {
        cs_send_ime_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, comp_text_length, (U32)L"");
        comp_text_length = 0;
    } 
}

void cs_end_comp(void)
{
    gdi_layer_lock_frame_buffer();
    if(comp_text_length > 0)
    {
        if(cs_is_multitap_comp_set)
        {
            cs_send_ime_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
            cs_send_ime_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
        }
        else
        {
            cs_send_ime_message(MMI_IMC_MESSAGE_REPLACE_HIGHLIGHT_STRING, comp_text_length, (U32)L"");
        }
        comp_text_length = 0;
    }
    cs_is_multitap_comp_set = 0;
    gdi_layer_unlock_frame_buffer();
}

void cs_insert_text(const unsigned short *text, int length)
{    
    if(kmx_is_multitap_ime() && comp_text_length == 1)
    {
        cs_send_ime_message(MMI_IMC_MESSAGE_RESET_MULTITAP_STATE, 0, 0);
        cs_send_ime_message(MMI_IMC_MESSAGE_STOP_SMART_ALPHABETIC, 0, 0);
        comp_text_length = 0;
    }
    else
    {
        cs_send_ime_message(MMI_IMC_MESSAGE_INSERT_STRING, (U32)text, 0);
    } 
}

void cs_delete_char(void)
{
    gdi_layer_lock_frame_buffer();
    cs_send_ime_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0xFFFF); 
    gdi_layer_unlock_frame_buffer();
}

int cs_ime_wcslen(unsigned short *text)
{
    return mmi_ucs2strlen((char*)text);
}

void cstar_complete_input(void)
{
    if(!cstar_ime_is_ui_visible())
    {
        CS_PenDownInEditor();
    #ifdef __MMI_KMX_TOUCH_INPUT__
        kmx_input_method_pen_down_in_editor();
    #endif
	if (kmx_is_multitap_ime())
	{
// komoxo 2010-3-4
		mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
	}
    }
}

void cstar_ime_reset_state(void)
{
    cs_reset();

    #ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__
    kmx_ime_reset_half_qwerty_status();
    #endif
#ifdef __MMI_KMX_TOUCH_INPUT__
    kmx_input_method_reset();
#endif
}

int CstarQueryCharInfo(U16 ch, U16* buffer, int buffer_length, int mode)
{
#if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)
    int i, j, k;
    U16 yin[10];
    char stk[64];
#endif /* __MMI_CSTAR_SM_CHINESE__ || __MMI_CSTAR_TR_CHINESE__ */

    if ( (ch < 0x4e00) || (ch > 0x9fa5) )
        return 0;   /* Failed: not Chinese character */

    if (!buffer)
        return 0;   /* Failed: invalid parameter */

    if (buffer_length <= 0)
        return 0;   /* Failed: invalid parameter */

#ifdef __MMI_CSTAR_SM_CHINESE__

    if (mode == IMM_INPUT_MODE_SM_MULTITAP_PINYIN ||
        mode == IMM_INPUT_MODE_QUICK_SEARCH_PINYIN)
    {
        #if defined(__MMI_TOUCH_SCREEN__)
            if (CS_IMM_QueryCodePinyin((unsigned short)ch, (unsigned short*)yin) != CS_ERROR_SUCCESS)
                return 0;   /* Failed: invalid Chinese character code */
        #else
            if (CS_IMM_QueryCodePinyin((unsigned short)ch, (unsigned short*)yin) != CS_ERROR_SUCCESS)
            return 0;   /* Failed: invalid Chinese character code */
        #endif
        for (i = 0; i < 8; i++)
        {
            if (yin[i] == 0)
                break;
            if (i >= buffer_length)
                break;
            buffer[i] = yin[i];
        }
        if (i < buffer_length)
            buffer[i] = 0;
        return i;
    }
    else if (mode == IMM_INPUT_MODE_SM_STROKE ||
             mode == IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE)
    {
        if (buffer_length >= 64)
            j = 64;
        else if (buffer_length < 5)
            j = 5;
        else
            j = buffer_length;
        k = CS_IMM_QueryStroke_gb(ch, stk, j);
        if (k <= 0)
            return 0;   /* Failed: invalid Chinese character code */
        i = 0;
        for (j = 0; j < k; j++)
        {
            if (i >= buffer_length)
                break;
            switch (stk[j])
            {
                case 1:
                    buffer[i] = 0xF004;
                    i++;
                    break;
                case 2:
                    buffer[i] = 0xF001;
                    i++;
                    break;
                case 3:
                    buffer[i] = 0xF007;
                    i++;
                    break;
                case 4:
                    buffer[i] = 0xF002;
                    i++;
                    break;
                case 5:
                    buffer[i] = 0xF005;
                    i++;
                    break;
            }
        }
        if (i < buffer_length)
            buffer[i] = 0;
        return i;
    }

#endif /* __MMI_CSTAR_SM_CHINESE__ */

#ifdef __MMI_CSTAR_TR_CHINESE__

    if (mode == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO ||
        mode == IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO)
    {
        #if defined(__MMI_TOUCH_SCREEN__)
            if (CS_IMM_QueryCodeZhuyin((unsigned short)ch, (unsigned short*)yin) != CS_ERROR_SUCCESS)
            return 0;   /* Failed: invalid Chinese character code */
        #else
            if (CS_IMM_QueryCodeZhuyin((unsigned short)ch, (unsigned short*)yin) != CS_ERROR_SUCCESS)
                return 0;   /* Failed: invalid Chinese character code */
        #endif
        for (i = 0; i < 8; i++)
        {
            if (yin[i] == 0)
                break;
            if (i >= buffer_length)
                break;
            buffer[i] = yin[i];
        }
        if (i < buffer_length)
            buffer[i] = 0;
        return i;
    }
    else if (mode == IMM_INPUT_MODE_TR_STROKE ||
             mode == IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE)
    {
        if (buffer_length >= 64)
            j = 64;
        else if (buffer_length < 5)
            j = 5;
        else
            j = buffer_length;
        k = CS_IMM_QueryStroke_big5(ch, stk, j);
        if (k <= 0)
            return 0;   /* Failed: invalid Chinese character code */
        i = 0;
        for (j = 0; j < k; j++)
        {
            if (i >= buffer_length)
                break;
            switch (stk[j])
            {
                case 1:
                    buffer[i] = 0xF004;
                    i++;
                    break;
                case 2:
                    buffer[i] = 0xF001;
                    i++;
                    break;
                case 3:
                    buffer[i] = 0xF007;
                    i++;
                    break;
                case 4:
                    buffer[i] = 0xF002;
                    i++;
                    break;
                case 5:
                    buffer[i] = 0xF005;
                    i++;
                    break;
            }
        }
        if (i < buffer_length)
            buffer[i] = 0;
        return i;
    }

#endif /* __MMI_CSTAR_TR_CHINESE__ */

    return 0;
}

static CS_UI_RECT g_ime_wnd_save_rect;

void kmx_save_ime_window_pos(int bottom_line)
{
    cstar_ime_get_ime_window_rect(&g_ime_wnd_save_rect);    
    g_ime_wnd_save_rect.top     = bottom_line - (g_ime_wnd_save_rect.bottom - g_ime_wnd_save_rect.top);
    g_ime_wnd_save_rect.bottom  = bottom_line;    
}

int kmx_repaint_ime_window(void)
{
    return kmx_ime_paint_ime_window(0, g_ime_wnd_save_rect.bottom);
}

int kmx_ime_paint_ime_window(int x, int bottom_y)
{
    int ret;
    KMX_GUI_RECT r;
    
    kmx_save_ime_window_pos(bottom_y);
    
    r.left = g_ime_wnd_save_rect.left;
    r.right = g_ime_wnd_save_rect.right;
    r.top = g_ime_wnd_save_rect.top;
    r.bottom = g_ime_wnd_save_rect.bottom;

    kmx_gui_begin_paint(&r);
        
    ret = cstar_ime_paint_window(x, bottom_y);

    kmx_gui_end_paint(&r);
    
    return ret;
}

int kmx_get_ime_window_height(void)
{
    CS_UI_RECT r;
    memset(&r, 0, sizeof(r));
    cstar_ime_get_ime_window_rect(&r);    
    return r.bottom - r.top;
}

void kmx_get_ime_window_difference(CS_UI_RECT * r)
{
    /* we assume that we always get the same bottom_line for the last save */
    CS_UI_RECT cur_rect;
    CS_UI_RECT union_rect;
    if (!r)
        return;

    cstar_ime_get_ime_window_rect(&cur_rect);
    cur_rect.top    = g_ime_wnd_save_rect.bottom - (cur_rect.bottom - cur_rect.top);
    cur_rect.bottom = g_ime_wnd_save_rect.bottom;
    /* Difference area is  save_rect | cur_rect - cur_rect */           
    union_rect.left   = g_ime_wnd_save_rect.left;
    union_rect.right  = g_ime_wnd_save_rect.right;
    union_rect.top    = g_ime_wnd_save_rect.top    < cur_rect.top    ? g_ime_wnd_save_rect.top      : cur_rect.top;
    union_rect.bottom = g_ime_wnd_save_rect.bottom > cur_rect.bottom ? g_ime_wnd_save_rect.bottom   : cur_rect.bottom;

    r->left   = union_rect.left;
    r->top    = union_rect.top;
    r->right  = union_rect.right;
    r->bottom = cur_rect.top;
}

static unsigned short kmx_ime_get_prev_char(void)
{
    UI_character_type string_buf[10] = {0}; ///TODO: define an value for the string length
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* get previous character but skip highlight and multitap. */
    cs_send_ime_message(MMI_IMC_MESSAGE_GET_STRING_BEFORE_CANDIDATE, 1, (U32)string_buf);

    if (string_buf[0] == 0)
    {
        string_buf[0] = ' ';
    }
    
    return (unsigned short)string_buf[0];
}

#define KMX_MAX_CONTEXT_BUFFER_LENGTH 32
static unsigned short g_kmx_context_buffer[KMX_MAX_CONTEXT_BUFFER_LENGTH];

#define KMX_IS_PTR_WORD_ALIGNED(p) (!((unsigned int)(p) & 1))

static int kmx_ime_get_context(const unsigned short **text, int *length)
{
    U8 *text_start = NULL, *text_end = NULL;

    if (!text || !length)
        return 0;
    
    cs_send_ime_message(MMI_IMC_MESSAGE_GET_TEXT_PTR_BEFORE_CANDIDATE, (U32)&text_start, (U32)&text_end);
    
    if (!text_start || !text_end || text_start > text_end)
        return 0;

    *length = (text_end - text_start) / 2;
    
    if (KMX_IS_PTR_WORD_ALIGNED(text_start))
    {
        *text = (const unsigned short*) text_start;
    }
    else
    {
        /* Not word aligned, copy to context buffer */
        if (*length > KMX_MAX_CONTEXT_BUFFER_LENGTH)
        {
            *length = KMX_MAX_CONTEXT_BUFFER_LENGTH;
        }
        memcpy(g_kmx_context_buffer, text_end - (*length) * 2, (*length) * 2);
        *text = (const unsigned short*) g_kmx_context_buffer;        
    }
    return 1;
}

static int kme_ime_get_arrow_style(void)
{
    #if defined(__MMI_TOUCH_SCREEN__)
    return 1; /* Large Arrow */
    #else
    return 0; /* Small Arrow */  
    #endif
}

void kmx_ime_set_metrics(void)
{
    mmi_imui_param_struct ui_param;

    memset(&ui_param, 0, sizeof(ui_param));
    mmi_ime_sdk_get_imui_param(&ui_param);
    
    g_ime_wnd_rect.left = ui_param.imui_x;
    g_ime_wnd_rect.right = ui_param.imui_x + ui_param.imui_width;
}

#ifdef __MMI_IME_AUTO_CAPITALIZATION__
static int kmx_ime_sync_case(void)
{
    mmi_ime_sdk_state_enum state;

    if (!kmx_ime_is_auto_capitalization_enabled())
        return 0;

    state = mmi_ime_sdk_get_state();

    if (state == MMI_IME_SDK_STATE_MULTITAP)
    {
        mmi_imc_global_data_struct_p global_data = 0;
        mmi_ime_word_capital_state_enum old_capital_state, new_capital_state;

        global_data = mmi_imc_get_global_data();

        if (!global_data)
            return 0;

        old_capital_state = global_data->capital_state;

        if (old_capital_state > MMI_IME_WORD_CAPITAL_STATE_NONE && 
            old_capital_state < MMI_IME_WORD_CAPITAL_STATE_MAX)
        {        
            new_capital_state = mmi_imc_get_candidate_case_before_cursor();

            if (old_capital_state != new_capital_state)
            {
                global_data->capital_state = new_capital_state;                
                mmi_imc_redraw_ime_indicator();
                return 1;                
            }
        }        
    }    
    return 0;
}

static int kme_ime_get_curr_capital_state(void)
{
    mmi_imc_global_data_struct_p global_data = 0;
    
    global_data = mmi_imc_get_global_data();
    
    if (global_data)
    {
        switch (global_data->capital_state)
        {
            case MMI_IME_WORD_CAPITAL_STATE_LOWER:
                return KMX_LATIN_LOWER_CASE;
            case MMI_IME_WORD_CAPITAL_STATE_FIRST_UPPER:
                return KMX_LATIN_INITIAL_CASE;
            case MMI_IME_WORD_CAPITAL_STATE_UPPER:
                return KMX_LATIN_UPPER_CASE;
        }
    }
    return 0;
}
#endif

#ifdef __MMI_IME_FTE_ENHANCE__
static void* cs_lidt_image;
static void* cs_ridt_image;

static void kmx_ime_paint_lidt(const CS_UI_RECT *r, CS_UI_COLOR c)
{
    KMX_GUI_RECT rect;
    rect.left = r->left;
    rect.right = r->right;
    rect.top = r->top;
    rect.bottom = r->bottom;
    
    kmx_gui_draw_resized_image(&rect, cs_lidt_image);
}

static void kmx_ime_paint_ridt(const CS_UI_RECT *r, CS_UI_COLOR c)
{
    KMX_GUI_RECT rect;
    rect.left = r->left;
    rect.right = r->right;
    rect.top = r->top;
    rect.bottom = r->bottom;

    kmx_gui_draw_resized_image(&rect, cs_ridt_image);
}

static void kmx_ime_setup_indicator(void)
{
    CS_UI_INDICATOR lidt, ridt;
    
    memset(&lidt, 0, sizeof(lidt));
    memset(&ridt, 0, sizeof(ridt));
    #ifdef __MMI_KMX_VUI_SUPPORT__
    if (mmi_ime_sdk_is_in_venus_ui_engine_state())
    {
        cs_lidt_image = GetImage(VADP_IMG_IME_CAND_LEFT_ARROW_NORMAL_MEDIUM);
        cs_ridt_image = GetImage(VADP_IMG_IME_CAND_RIGHT_ARROW_NORMAL_MEDIUM);
    }
    else
    #endif
    {
        UI_ime_theme * now_using_theme = NULL;

        now_using_theme = mmi_ime_sdk_get_ime_theme();

        cs_lidt_image = now_using_theme->cand_left_arrow_up_medium;
        cs_ridt_image = now_using_theme->cand_right_arrow_up_medium;
    }
    
    if (!cs_lidt_image || !cs_ridt_image)
        return;
        
    gdi_image_get_dimension(cs_lidt_image, &lidt.width, &lidt.height);
    gdi_image_get_dimension(cs_ridt_image, &ridt.width, &ridt.height);   
    lidt.paint = kmx_ime_paint_lidt;
    ridt.paint = kmx_ime_paint_ridt;
    
    cstar_ime_set_custom_indicator(&lidt, &ridt);
}

static void kmx_ime_cancel_indicator(void)
{
    if (cstar_ime_is_custom_indicator_enable())
        cstar_ime_set_custom_indicator(0, 0);
}
#endif

void kmx_ime_setup_input_method(void)
{
#ifdef KMX_CFG_CONTEXT_NOT_AVAIL
    cstar_ime_set_get_prev_char_hook(kmx_ime_get_prev_char);
#endif
#ifdef __MMI_KMX_UPDATE_USER_WORD__
    cstar_ime_set_read_update_data_callback(kmx_read_update_data);
    kmx_load_update_data();
#endif
    cstar_ime_set_get_arrow_style_hook(kme_ime_get_arrow_style);
    cstar_ime_set_change_input_method_hook(kmx_ime_on_change_input_method);

#ifdef __MMI_IME_AUTO_CAPITALIZATION__    
    cstar_ime_set_update_case_hook(kmx_ime_sync_case);
    cstar_ime_set_get_curr_capital_state_hook(kme_ime_get_curr_capital_state);
#endif

    cstar_ime_set_remove_ime_options_hook(cs_gui_remove_ime_options_file);
    
    kmx_ime_set_metrics();
    
    #ifdef __MMI_IME_FTE_ENHANCE__
    kmx_ime_setup_indicator();
    #endif
}

void kmx_ime_close_input_method(void)
{
    memset(&g_ime_wnd_save_rect, 0, sizeof(g_ime_wnd_save_rect));
    #ifdef __MMI_IME_FTE_ENHANCE__
    kmx_ime_cancel_indicator();
    #endif
    cstar_ime_close_input_method();
}

int kmx_ime_handle_stroke_char(int c)
{
    int key_code, key_type = KEY_EVENT_DOWN;
    mmi_imm_input_mode_enum input_mode;

    input_mode = mmi_ime_sdk_get_current_input_mode();

    if ((input_mode == IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE) || (input_mode ==IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE))
    {
    	#if defined(__MMI_VIRTUAL_KEYBOARD__)
        cs_send_ime_message(MMI_IMC_MESSAGE_INSERT_CHAR, c, 0);
        #endif
        return 1;
    }    
    
    if ((input_mode != IMM_INPUT_MODE_TR_STROKE) && (input_mode != IMM_INPUT_MODE_SM_STROKE))
        return 0;
    
    switch(c) {
    case 0xF004:
        key_code = KEY_1;
    	break;
    case 0xF001:
        key_code = KEY_2;
        break;
    case 0xF007:
        key_code = KEY_3;
        break;
    case 0xF002:
        key_code = KEY_4;
        break;
    case 0xF005:
        key_code = KEY_5;
        break;
    case 0xF000:
        key_code = KEY_6;
        break;
    default:
        return 0;
    }    
    return cstar_ime_handle_key(key_code, key_type, 0);
}

static void kmx_update_last_save_time(void)
{
    kal_get_time(&g_kmx_last_save_ticks);
}

static int  kmx_is_time_to_save(void)
{
    unsigned int cur_ticks = 0;
    int delta;

    kal_get_time(&cur_ticks);

    delta = cur_ticks - g_kmx_last_save_ticks;

    if (delta < 0)
        return 1;   /* Time overflow? save this! */

    return kal_ticks_to_milli_secs((unsigned int)delta) >= g_kmx_save_threshold_milli;    
}

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
int cstar_ime_update_case(int case_info)
{
    int cstar_mode = IM_NONE;
    int cstar_base_mode = IM_NONE;
    int cstar_lang = 0;
    int cstar_tail = 0;    
    int is_fullkey_mode;
    int cur_cstar_mode = IM_NONE;
    unsigned char smart_tail = 0; 
    unsigned char mt_tail = 0;

    switch(case_info) {
    case KMX_LANG_LOWERCASE:
        smart_tail = 9;
        mt_tail    = 2;
    	break;
    case KMX_LANG_UPPERCASE:
        smart_tail = 8;
        mt_tail    = 3;
        break;
    case KMX_LANG_INITIALCASE:
        smart_tail = 1;
        mt_tail    = 5;
        break;
    default:
        return 0;
    }  

    cstar_mode = cstar_ime_get_input_method();
    cstar_base_mode = CS_BASE_MODE(cstar_mode);
    is_fullkey_mode = cstar_mode > IM_LATINFULLKEY_BASE;

    if (!IS_CS_LATIN_MODE(cstar_base_mode))
    {
        return 0;
    }
    
    cstar_lang = cstar_base_mode / 10;
    cstar_tail = cstar_base_mode % 10;
    
    if (cstar_lang == CS_LANG_THAI || cstar_lang == CS_LANG_HEBREW || cstar_lang == CS_LANG_PERSIAN
        || cstar_lang == CS_LANG_ARABIC || cstar_lang == CS_LANG_HINDI || cstar_lang == CS_LANG_BENGALI
        || cstar_lang == CS_LANG_HANGUL || cstar_lang == CS_LANG_UYGHUR || cstar_lang == CS_LANG_URDU)
    {
        return 0;
    }

    cur_cstar_mode = cstar_mode;
    
    if (cstar_tail >=2 && cstar_tail <= 5)
    {
        /* mt mode */
        cstar_mode = cstar_lang * 10 + mt_tail;
    }
    else
    {
        /* smart mode */
        cstar_mode = cstar_lang * 10 + smart_tail;
    }

    if (is_fullkey_mode)
    {
        cstar_mode += IM_LATINFULLKEY_BASE;
    }

    if (cur_cstar_mode == cstar_mode)
    {
        return 0;
    }
    
    cstar_ime_set_input_mode(cstar_mode);
    
    return 1;
    
}

void cstar_ime_set_input_mode(int imm_mode)
{
    cs_mode_convert_disabled = 1;
    cstar_ime_set_input_method(imm_mode);
    cs_mode_convert_disabled = 0;
}
#endif

#ifdef __MMI_KMX_HALF_QWERTY_BOPOMOFO__

int kmx_ime_translate_half_qwerty_event(gui_virtual_keyboard_pen_enum event);
int kmx_ime_half_qwerty_handle_key(int key_code, int key_type);

void kmx_ime_reset_half_qwerty_status(void)
{
    g_kmx_prev_key_event = GUI_VKBD_PEN_NONE;
    g_kmx_key_multitap = 0;
}

static unsigned char g_kmx_half_qwerty_mt_count_table[] = 
{
    2, /* {0x3105, 0x3106, 0x0000}, */ /* GUI_VKBD_PEN_ZHUYIN_B_P */
    2, /*{0x3107, 0x3108, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_M_F */
    2, /*{0x3109, 0x310a, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_D_T */
    2, /*{0x310b, 0x310c, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_N_L */
    2, /*{0x310d, 0x3110, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_G_J */
    2, /*{0x310e, 0x3111, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_K_Q */
    2, /*{0x310f, 0x3112, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_H_X */
    2, /*{0x3113, 0x3114, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_ZH_CH */
    1, /*{0x3115, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_SH */
    1, /*{0x3116, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_R */
    1, /*{0x3117, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_Z */
    1, /*{0x3118, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_C */
    1, /*{0x3119, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_S */
    1, /*{0x3127, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_I */
    1, /*{0x3128, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_U */
    1, /*{0x3129, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_IU */
    2, /*{0x311a, 0x311b, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_A_O */
    1, /*{0x311c, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_E */
    1, /*{0x311d, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_EH */
    2, /*{0x311e, 0x311f, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_AI_EI */
    1, /*{0x3120, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_AU */
    1, /*{0x3121, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_OU */
    2, /*{0x3122, 0x3123, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_AN_EN */
    1, /*{0x3124, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_ANG */
    1, /*{0x3125, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_ENG */
    1, /*{0x3126, 0x0000}, */  /* GUI_VKBD_PEN_ZHUYIN_ER */
};

static unsigned char kmx_ime_get_half_qwerty_key_mt_count(gui_virtual_keyboard_pen_enum vk_event)
{
    MMI_ASSERT(vk_event >= GUI_VKBD_PEN_ZHUYIN_B_P && vk_event < GUI_VKBD_PEN_ZHUYIN_TONE);
    return g_kmx_half_qwerty_mt_count_table[vk_event - GUI_VKBD_PEN_ZHUYIN_B_P];
}

int kmx_ime_handle_bopomofo_half_qwerty_char(int pen_event, unsigned short ch, int vk_event)
{
    int ret = 0;
    #ifdef __MMI_VIRTUAL_KEYBOARD__
    #if defined(__MMI_LANG_TR_CHINESE__)
    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO)
    {        
        switch (vk_event)
        {
            case GUI_VKBD_PEN_ZHUYIN_B_P:
            case GUI_VKBD_PEN_ZHUYIN_M_F:
            case GUI_VKBD_PEN_ZHUYIN_D_T:
            case GUI_VKBD_PEN_ZHUYIN_N_L:
            case GUI_VKBD_PEN_ZHUYIN_G_J:
            case GUI_VKBD_PEN_ZHUYIN_K_Q:
            case GUI_VKBD_PEN_ZHUYIN_H_X:
            case GUI_VKBD_PEN_ZHUYIN_ZH_CH:
            case GUI_VKBD_PEN_ZHUYIN_SH:
            case GUI_VKBD_PEN_ZHUYIN_R:
            case GUI_VKBD_PEN_ZHUYIN_I:
            case GUI_VKBD_PEN_ZHUYIN_U:
            case GUI_VKBD_PEN_ZHUYIN_IU:
            case GUI_VKBD_PEN_ZHUYIN_Z:
            case GUI_VKBD_PEN_ZHUYIN_C:
            case GUI_VKBD_PEN_ZHUYIN_S:
            case GUI_VKBD_PEN_ZHUYIN_A_O:
            case GUI_VKBD_PEN_ZHUYIN_E:
            case GUI_VKBD_PEN_ZHUYIN_EH:
            case GUI_VKBD_PEN_ZHUYIN_AI_EI:
            case GUI_VKBD_PEN_ZHUYIN_AU:
            case GUI_VKBD_PEN_ZHUYIN_OU:
            case GUI_VKBD_PEN_ZHUYIN_AN_EN:
            case GUI_VKBD_PEN_ZHUYIN_ANG:
            case GUI_VKBD_PEN_ZHUYIN_ENG:
            case GUI_VKBD_PEN_ZHUYIN_ER:
                /* Handle Char */                
                if (pen_event == MMI_PEN_EVENT_DOWN || pen_event == MMI_PEN_EVENT_REPEAT)
                {
                    if (g_kmx_prev_key_event != vk_event)
                    {
                        g_kmx_key_multitap = 0;
                        /* Reset multitap. */
                        if (g_kmx_timer_started)
                        {
                            kmx_ime_cancel_timer();
                            break;
                        }                        
                    }
                    else
                    {
                        /* Ignore hovering on the same key. */
                        kmx_ime_suspend_timer();
                    }
                    mmi_ime_sdk_redraw_screen_by_state();
                }
                else if (pen_event == MMI_PEN_EVENT_UP)
                {
                    int key_code;
                    int mt_count;
                    mt_count = kmx_ime_get_half_qwerty_key_mt_count(vk_event);
                    if (g_kmx_prev_key_event == vk_event)
                    {
                        if (mt_count > 1)
                        {
                            g_kmx_key_multitap++;
                            if (g_kmx_key_multitap >= mt_count)
                            {
                                g_kmx_key_multitap = 0;
                            }
                        }                        
                    }
                    else
                    {
                        g_kmx_key_multitap = 0;
                    }
                    key_code = kmx_ime_translate_half_qwerty_event(vk_event);
                    kmx_ime_half_qwerty_handle_key(key_code, KEY_EVENT_DOWN);
                    #ifdef KMX_CFG_FAST_NUMBER_INPUT 
                    if (g_kmx_timer_ctx.enabled)
                    {                
                        kmx_start_ime_timer();
                    }
                    #endif                    
                }                
                ret = 1;
                break;
        case GUI_VKBD_PEN_ZHUYIN_TONE:
            if (pen_event == MMI_PEN_EVENT_UP)
            {
                if(kmx_ime_half_qwerty_handle_key('.', KEY_EVENT_DOWN));
                {
                    #ifdef KMX_CFG_FAST_NUMBER_INPUT 
                    if (g_kmx_timer_ctx.enabled)
                    {                
                        kmx_start_ime_timer();
                    }
                    #endif
                    ret = 1;
                }                        
            }            
            break;
        case GUI_VKBD_PEN_BAKSPACE:
            {
                if (pen_event == MMI_PEN_EVENT_UP)
                {
                    g_kmx_key_multitap = 0;
                }
                break;
            }
        }        
    }
    g_kmx_prev_key_event = vk_event;        
    #endif /* __MMI_LANG_TR_CHINESE__ */
    #endif /* __MMI_VIRTUAL_KEYBOARD__ */
    return ret;
}

int kmx_ime_handle_vk_event_callback(int key_event, int key_param, int ret_addr, int ret_val_addr)
{
    int handled = 0;
    #ifdef __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__
    U32 *ret = (U32*)ret_addr;
    gui_virtual_keyboard_event_enum *ret_val = (gui_virtual_keyboard_event_enum *)ret_val_addr;

    #ifdef __MMI_VIRTUAL_KEYBOARD__
    #if defined(__MMI_LANG_TR_CHINESE__)
    if (MMI_VIRTUAL_KEYBOARD_LANG == GUI_VIRTUAL_KEYBOARD_BOPOMO)
    {
        *ret_val = GUI_VIRTUAL_KEYBOARD_EVENT_START;
        switch (key_event)
        {
            case GUI_VKBD_PEN_ZHUYIN_B_P: /* for Zhuyin B & P */
            case GUI_VKBD_PEN_ZHUYIN_M_F: /* for Zhuyin M & F */
            case GUI_VKBD_PEN_ZHUYIN_D_T: /* for Zhuyin D & T */
            case GUI_VKBD_PEN_ZHUYIN_N_L: /* for Zhuyin N & L */
            case GUI_VKBD_PEN_ZHUYIN_G_J: /* for Zhuyin G & J */
            case GUI_VKBD_PEN_ZHUYIN_K_Q: /* for Zhuyin K & Q */
            case GUI_VKBD_PEN_ZHUYIN_H_X: /* for Zhuyin H & X */
            case GUI_VKBD_PEN_ZHUYIN_ZH_CH: /* for Zhuyin ZH & CH */
            case GUI_VKBD_PEN_ZHUYIN_A_O: /* for Zhuyin A & O */
            case GUI_VKBD_PEN_ZHUYIN_AI_EI: /* for Zhuyin AI & EI */
            case GUI_VKBD_PEN_ZHUYIN_AN_EN: /* for Zhuyin AI & EI */            
                *ret_val = GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE;
                if (g_kmx_prev_key_event == key_event)
                {
                    *ret = g_kmx_key_multitap;
                    if (*ret >= kmx_ime_get_half_qwerty_key_mt_count(key_event))
                    {
                        *ret = 0;
                    }
                }
                else
                {
                    *ret = 0;
                }                 
                handled = 1;
                break;
            case GUI_VKBD_PEN_ZHUYIN_COMMA_DOT:
            #if defined(__MMI_MAINLCD_320X480__)
                /* TODO: Adapter 320X480 layout */
                *ret_val = GUI_VIRTUAL_KEYBOARD_EVENT_MULTITAP_STATE;
                {
                    *ret = 0;
                }                
            #endif    
		        handled = 1;
                break;            
        }
    }
    #endif    
    #endif    
    #endif
    return handled;
}

int kmx_ime_translate_half_qwerty_event(gui_virtual_keyboard_pen_enum event)
{
    #ifdef __MMI_VIRTUAL_KEYBOARD__
    #if defined(__MMI_LANG_TR_CHINESE__)
    switch (event)
    {
        case GUI_VKBD_PEN_ZHUYIN_M_F   : return 'a';
        case GUI_VKBD_PEN_ZHUYIN_EH    : return 'b';
        case GUI_VKBD_PEN_ZHUYIN_S     : return 'c';
        case GUI_VKBD_PEN_ZHUYIN_K_Q   : return 'd';
        case GUI_VKBD_PEN_ZHUYIN_G_J   : return 'e';
        case GUI_VKBD_PEN_ZHUYIN_SH    : return 'f';
        case GUI_VKBD_PEN_ZHUYIN_C     : return 'g';
        case GUI_VKBD_PEN_ZHUYIN_U     : return 'h';
        case GUI_VKBD_PEN_ZHUYIN_AI_EI : return 'i';
        case GUI_VKBD_PEN_ZHUYIN_E     : return 'j';
        case GUI_VKBD_PEN_ZHUYIN_AU    : return 'k';
        case GUI_VKBD_PEN_ZHUYIN_ANG   : return 'l';
        case GUI_VKBD_PEN_ZHUYIN_ENG   : return 'm';
        case GUI_VKBD_PEN_ZHUYIN_OU    : return 'n';
        case GUI_VKBD_PEN_ZHUYIN_AN_EN : return 'o';
        case GUI_VKBD_PEN_ZHUYIN_ER    : return 'p';
        case GUI_VKBD_PEN_ZHUYIN_B_P   : return 'q';
        case GUI_VKBD_PEN_ZHUYIN_ZH_CH : return 'r';
        case GUI_VKBD_PEN_ZHUYIN_N_L   : return 's';
        case GUI_VKBD_PEN_ZHUYIN_Z     : return 't';
        case GUI_VKBD_PEN_ZHUYIN_A_O   : return 'u';
        case GUI_VKBD_PEN_ZHUYIN_IU    : return 'v';
        case GUI_VKBD_PEN_ZHUYIN_D_T   : return 'w';
        case GUI_VKBD_PEN_ZHUYIN_R     : return 'x';
        case GUI_VKBD_PEN_ZHUYIN_I     : return 'y';
        case GUI_VKBD_PEN_ZHUYIN_H_X   : return 'z';
    };
    #endif
    #endif
    return '.';
}

int kmx_ime_half_qwerty_handle_key(int key_code, int key_type)
{
    int ret = 0;

    if (key_type == KEY_EVENT_DOWN)
    {
        if (key_code >= 'a' && key_code <= 'z' || key_code == '.')
        {
            gdi_layer_lock_frame_buffer();    
            ret = cstar_ime_handle_event(KMX_EVENT_TYPE_HALF_QWERTY, key_code, 0);
            gdi_layer_unlock_frame_buffer();
        }
    }
    return ret;
}

#endif

#endif /* #ifdef __MMI_KOMOXO__ */

#if !defined(__MMI_KOMOXO__) && defined(__MMI_KMX_TOUCH_INPUT__) /* MMI_KMX_HW */

    int mmi_ime_cstar_get_mode_info(mmi_imm_input_mode_enum input_mode, const void ** database_ptr, void ** user_data_ptr, int * user_data_size)
    {
        const mmi_ime_cstar_mode_info_struct * info;
        info = mmi_ime_cstar_query_mode_info(input_mode);
    
        if (!info)
            return MMI_FALSE;
    
        *database_ptr = *(info->ldb_ptr);
        *user_data_ptr = (void*)&mmi_ime_cstar_user_data[info->udb_start_block_index * MMI_CSTAR_UDB_BLOCK_SIZE / sizeof(mmi_ime_cstar_user_data[0])];
        *user_data_size = info->udb_size * MMI_CSTAR_UDB_BLOCK_SIZE;

        return MMI_TRUE;   
    }

    KMX_IME_ENGINE * mmi_ime_cstar_get_cur_engine(void)
    {
        return &g_engine.cstar_engine;
    }

#endif /* #if !defined(__MMI_KOMOXO__) && defined(__MMI_KMX_TOUCH_INPUT__) */


MMI_BOOL mmi_ime_kmx_default_handwriting_handle_key(int key_code, U16 key_type)
{
	MMI_BOOL ret = MMI_FALSE;
        
#if defined(__MMI_TOUCH_SCREEN__)// && !defined(__MMI_KMX_HANDWRITING_EXPANSION__)
    {
	extern void mmi_imc_key_common_arrow_key_handler(mmi_imc_key_custom_value, U16);
	extern void mmi_imc_pen_confirm_handwriting_selection(void);
	if (key_type == KEY_EVENT_UP)
	{
		switch(mmi_imc_get_state()) {
		case MMI_IMC_STATE_ASSOC_SELECTING:        
        case MMI_IMC_STATE_HAND_WRITING_CAND:    
            if (key_code == KEY_LSK)
            {
				gdi_layer_lock_frame_buffer();

                mmi_imc_select_candidate_from_candidate_box();
                mmi_ime_sdk_redraw_screen_by_state();

				gdi_layer_unlock_frame_buffer();
			    gdi_lcd_repaint_all();
				ret = MMI_TRUE;
            }
            break;       
		}
	}
	else if (key_type == KEY_EVENT_DOWN)
	{
		switch(mmi_imc_get_state()) {
		case MMI_IMC_STATE_ASSOC_SELECTING:
			if (key_code == KEY_RIGHT_ARROW || 
                key_code == KEY_LEFT_ARROW ||
                key_code == KEY_UP_ARROW ||
                key_code == KEY_DOWN_ARROW)
            {
                switch(key_code) {
                case KEY_RIGHT_ARROW:
                    key_code = MMI_IMC_KEY_RIGHT;
                	break;
                case KEY_LEFT_ARROW:
                    key_code = MMI_IMC_KEY_LEFT;
                	break;
                case KEY_UP_ARROW:
                    key_code = MMI_IMC_KEY_UP;
                	break;
                case KEY_DOWN_ARROW:
                    key_code = MMI_IMC_KEY_DOWN;
                	break;                
                }
                mmi_imc_key_common_arrow_key_handler((mmi_imc_key_custom_value)key_code, key_type);                
                mmi_ime_sdk_redraw_screen_by_state();
				ret = MMI_TRUE;
            }
			else if (key_code == KEY_RSK
                || key_code == KEY_CLEAR
                )
            {
                mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
                mmi_ime_sdk_redraw_screen_by_state();                
				ret = MMI_TRUE;
            }         
			break;
		case MMI_IMC_STATE_HAND_WRITING_CAND:
            if (key_code == KEY_RSK
                || key_code == KEY_CLEAR
                )
            {
				U32 is_last_position;
				gdi_layer_lock_frame_buffer();
				
				is_last_position = cs_send_ime_message(MMI_IMC_MESSAGE_IS_LAST_POSITION, 0, 0);
				
                mmi_imc_pen_confirm_handwriting_selection();

				if (!is_last_position)
				{
                    cs_send_ime_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
				}
				
				gdi_layer_unlock_frame_buffer();
				gdi_lcd_repaint_all();
                ret = MMI_TRUE;
            }
            break;        
	    }
    }
    }
#endif
	return ret;
}

int kmx_default_handle_key(int key_code, U16 key_type, int ucs2_value)
{
    
    if (mmi_ime_sdk_get_state() == MMI_IME_SDK_STATE_MULTITAP && key_type == KEY_EVENT_DOWN)
    {
        if (key_code == KEY_RSK
                || key_code == KEY_CLEAR
                #if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
                || key_code == KEY_BACKSPACE
                #endif
                )
            {
                /* TR BOPOMOFO/Smart Qwerty input should not delete char, but this event should be handled by engine, 
                   so won't arrive here */
                gdi_layer_lock_frame_buffer();                        
                cs_send_ime_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
                mmi_ime_sdk_set_state(MMI_IME_SDK_STATE_INITIAL);
                mmi_ime_sdk_redraw_screen_by_state();
                gdi_layer_unlock_frame_buffer();
                gdi_lcd_repaint_all();
                return MMI_TRUE;
            }                               
    }
    
    #ifdef  __MMI_QWERTY_KEYPAD_SUPPORT__
    if (key_code == KEY_BACKSPACE && (key_type == KEY_EVENT_DOWN || key_type == KEY_LONG_PRESS))
    {
         if (cstar_ime_is_ui_visible())
            return MMI_FALSE;
         if (!cs_send_ime_message(MMI_IMC_MESSAGE_IS_EDITOR_EMPTY, 0, 0))
         {
            if (!cs_send_ime_message(MMI_IMC_MESSAGE_IS_BACKSPACE_DISABLED, 1, 0))
            {
				if(key_type == KEY_EVENT_DOWN)
                    cs_send_ime_message(MMI_IMC_MESSAGE_DELETE_CHAR, 1, 0);
				else if(key_type == KEY_LONG_PRESS)
                    cs_send_ime_message(MMI_IMC_MESSAGE_CLEAR_ALL, 1, 0);
			    mmi_ime_sdk_redraw_screen_by_state();
            }
            return MMI_TRUE;
        }
        else
        {
            UI_editor_play_tone_cannot_change();
            return MMI_FALSE;
        }        
    }   
    #endif

    #ifdef __MMI_IMC_CAPITAL_SWITCH__
    /* change writing language */        
    if (key_code == KEY_POUND 
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        || key_code == KEY_QWERTY_MENU
    #endif
        )
    {
        if (key_type == KEY_LONG_PRESS)
        {   
            if (!mmi_ime_sdk_is_change_language_disabled()
		     && (mmi_ime_sdk_get_current_allowed_writing_language_num() > 1))
            {
                mmi_ime_sdk_entry_change_language_screen();
                return 1;
            }
        }
        /* No more handle for KEY_POUND */
        return 0;
    }    
    #endif
    return mmi_ime_kmx_default_handwriting_handle_key(key_code, key_type);
}

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
static void kmx_ime_input_char(unsigned short ch)
{
    U16 str[2];
    if (ch == 0)
        return;
    
    str[0] = ch;
    str[1] = 0;
    cs_insert_text(str, 2);
}
#endif

const KMX_INPUT_MODE_ATTRIBUTES* kmx_get_curr_input_mode_attr(void)
{
    if (!cstar_ime_is_ime_support())
    {
        return NULL;
    }
    return &g_kmx_input_mode_attr;
}

static unsigned char kmx_translate_mode_case_info(const sIMEModeDetails * mode_details_ptr)
{
    unsigned char case_info = KMX_LANG_NOCASE;

    if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_LOWERCASE)
    {
        case_info = KMX_LANG_LOWERCASE;
    }
    else if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_UPPERCASE)
    {
        case_info = KMX_LANG_UPPERCASE;
    }    
    else if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_TITLECASE)
    {
        case_info = KMX_LANG_INITIALCASE;
    }
    return case_info;
 
}

static unsigned char kmx_translate_mode_ime(const sIMEModeDetails * mode_details_ptr)
{
    unsigned char ime = KMX_IME_VOID;
    if (mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_ALPHABETIC)
    {
        if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_SMART)
        {
            ime = KMX_IME_LATIN_SMART;
        }
        else if (mode_details_ptr->Mode_Special_Attrib & IME_MODE_ATTR_MULTITAP)
        {            
            ime = KMX_IME_LATIN_MULTITAP;
        }
    }
    else if(mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_PHONETIC)
    {
        if (mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_SM_PINYIN 
            || mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_SM_MULTITAP_PINYIN)
        {
            ime = KMX_IME_PINYIN;
        }
        else if (mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_TR_BOPOMO 
            || mode_details_ptr->imm_mode_id == IMM_INPUT_MODE_TR_MULTITAP_BOPOMO)
        {
            ime = KMX_IME_BOPOMOFO;
        }        
    }
    else if (mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_STROKE)
    {
        ime = KMX_IME_STROKE;
    }
    else if (mode_details_ptr->Lang_Special_Attrib & IME_LANG_ATTR_NUMBERIC)
    {
        ime = KMX_IME_NUM;
    }
    /* No pure symbol input */
    return ime;
}

static unsigned char kmx_translate_mode_flags(const sIMEModeDetails * mode_details_ptr)
{ 
    switch(mode_details_ptr->lang_id) {
    case IME_WRITING_LANG_HE:
    	break;        
    }
    return 0;
}

int kmx_get_input_mode_attr(unsigned int input_mode, KMX_INPUT_MODE_ATTRIBUTES* attr)
{
    const sIMEModeDetails * mode_details_ptr;

    if (!attr)
        return 0;
   
    memset(attr, 0, sizeof(*attr));
    attr->input_mode = input_mode;

    mode_details_ptr = mmi_ime_sdk_get_input_mode_array_item((mmi_imm_input_mode_enum)input_mode);
    
    if (!mode_details_ptr)
        return 0;
    
    attr->case_info = kmx_translate_mode_case_info(mode_details_ptr);
    attr->ime = kmx_translate_mode_ime(mode_details_ptr); 
    attr->flags = kmx_translate_mode_flags(mode_details_ptr);
    return 1;
}

int kmx_get_curr_case_info(void)
{
    return g_kmx_curr_case_info;
}

void kmx_set_curr_case_info(int case_info)
{   
    g_kmx_curr_case_info = case_info;
}

int kmx_ime_update_case(int case_info)
{
    kmx_set_curr_case_info(case_info);
    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    return cstar_ime_update_case(case_info);
    #else
    return 0;
    #endif    
}

void kmx_ime_config_feature_options(void)
{
    CS_IMM_OPTIONS *options;
    
    /* Disable next chinese word prediction */
    mmi_ime_sdk_config_chinese_word_prediction_by_pen(MMI_FALSE);

    options = cstar_ime_get_cur_options();
    
    if (mmi_ime_sdk_is_chinese_next_word_prediction_enabled())
    {
        options->dwAssoPinyin   = CS_ASSOCIATION_ON;
        options->dwAssoStroke   = CS_ASSOCIATION_ON;
    }
    else
    {
        options->dwAssoPinyin   = CS_ASSOCIATION_OFF;
        options->dwAssoStroke   = CS_ASSOCIATION_OFF;
    }
    
    cstar_ime_update_options();    
}

int kmx_ime_on_editor_cursor_moved(void)
{
    return 1;
}