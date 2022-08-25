
#ifndef KMXIMMAPI_H
#define KMXIMMAPI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
    #pragma warning(disable : 4206 4702)
#endif

#ifndef KMX_WCHAR
    #define KMX_WCHAR   unsigned short
#endif

#ifndef KMX_COLOR
    #define KMX_COLOR   unsigned int
#endif

#ifndef KMX_COLOR_RED
    #define KMX_COLOR_RED(color)    ((unsigned char)(color))
#endif

#ifndef KMX_COLOR_GREEN
    #define KMX_COLOR_GREEN(color)  ((unsigned char)((color) >> 8))
#endif

#ifndef KMX_COLOR_BLUE
    #define KMX_COLOR_BLUE(color)   ((unsigned char)((color) >> 16))
#endif

#ifndef KMX_COLOR_MAKE_RGB
    #define KMX_COLOR_MAKE_RGB(r, g, b) ((KMX_COLOR)((r) | (g) << 8 | (b) << 16))
#endif

/****************************************************************************

Input method ID constants.

****************************************************************************/
#define KMX_IME_VOID                    0
#define KMX_IME_LATIN_SMART             1
#define KMX_IME_LATIN_MULTITAP          2
#define KMX_IME_PINYIN                  3
#define KMX_IME_BOPOMOFO                4
#define KMX_IME_STROKE                  5
#define KMX_IME_NUM                     6
#define KMX_IME_SYM                     7
#define KMX_IME_IM                      8       /* Special ime for ime list */
#define KMX_IME_HW                      9
/****************************************************************************

Keyboard type constants.

****************************************************************************/

#define KMX_KEYBOARD_TYPE_DIGIT      0
#define KMX_KEYBOARD_TYPE_QWERTY     1
#define KMX_KEYBOARD_TYPE_MAX        2

#define KMX_IMAGE_QWERTY_240_BASE                   0x1000
#define KMX_IMAGE_QWERTY_240_HIGHLIGHT_BASE         0x2000
/****************************************************************************

Language ID constants.

****************************************************************************/

#define KMX_LANG_ARABIC                 1
#define KMX_LANG_BENGALI                2
#define KMX_LANG_BULGARIAN              3
#define KMX_LANG_CHINESE_SIMPLIFIED     4
#define KMX_LANG_CHINESE_TRADITIONAL    5
#define KMX_LANG_CZECH                  6
#define KMX_LANG_DANISH                 7
#define KMX_LANG_DUTCH                  8
#define KMX_LANG_ENGLISH                9
#define KMX_LANG_ENGLISH_INTL           10
#define KMX_LANG_FINNISH                11
#define KMX_LANG_FRENCH                 12
#define KMX_LANG_GERMAN                 13
#define KMX_LANG_GREEK                  14
#define KMX_LANG_HEBREW                 15
#define KMX_LANG_HINDI                  16
#define KMX_LANG_HINGLISH               17
#define KMX_LANG_HUNGARIAN              18
#define KMX_LANG_INDONESIAN             19
#define KMX_LANG_ITALIAN                20
#define KMX_LANG_MALAY                  21
#define KMX_LANG_NORWEGIAN              22
#define KMX_LANG_PERSIAN                23
#define KMX_LANG_POLISH                 24
#define KMX_LANG_PORTUGUESE             25
#define KMX_LANG_ROMANIAN               26
#define KMX_LANG_RUSSIAN                27
#define KMX_LANG_SLOVAK                 28
#define KMX_LANG_SLOVENIAN              29
#define KMX_LANG_SPANISH                30
#define KMX_LANG_SWAHILI                31
#define KMX_LANG_SWEDISH                32
#define KMX_LANG_THAI                   33
#define KMX_LANG_TURKISH                34
#define KMX_LANG_UKRAINIAN              35
#define KMX_LANG_VIETNAMESE             36
    
#define KMX_LANG_QUICK_SEARCH_CHS_PINYIN    37
#define KMX_LANG_QUICK_SEARCH_CHT_BOPOMOFO  38
#define KMX_LANG_QUICK_SEARCH_CHS_STROKE    39
#define KMX_LANG_QUICK_SEARCH_CHT_STROKE    40

#define KMX_LANG_NUM_123                        41
#define KMX_LANG_NUM_SIGNED_123                 42
#define KMX_LANG_NUM_FLOAT_123                  43
#define KMX_LANG_NUM_PHONE_NUMBER               44
#define KMX_LANG_NUM_PHONE_NUMBER_WILDCHAR      45    
#define KMX_LANG_NUM_SIGNED_FLOAT_123           46

#define KMX_LANG_URDU                       47

#define KMX_LANG_PASSWORD_NUMBER            48

#define KMX_LANG_LITHUANIAN                 49

#define KMX_LANG_EMAIL                      50
#define KMX_LANG_URL                        51

/****************************************************************************

Language case constants.

****************************************************************************/
    
#define KMX_LANG_NOCASE      0
#define KMX_LANG_LOWERCASE   1
#define KMX_LANG_UPPERCASE   2
#define KMX_LANG_INITIALCASE 3

/* Capable case */
#define KMX_LANG_CAP_DEFAULTCASE    0
#define KMX_LANG_CAP_LOWERCASE      1
#define KMX_LANG_CAP_INITIALCASE    2
#define KMX_LANG_CAP_UPPERCASE      4
#define KMX_LANG_CAP_ALLCASE       (KMX_LANG_CAP_LOWERCASE | KMX_LANG_CAP_UPPERCASE | KMX_LANG_CAP_INITIALCASE)


/****************************************************************************

Property constants.

****************************************************************************/
    
#define KMX_PROPERTY_HW_SWITCH                    0x1
#define KMX_PROPERTY_NO_SHOW_NEW_LINE_SYMBOL      0x2



/****************************************************************************

Screen metric constants.

****************************************************************************/

#define KMX_METRIC_240                  240
#define KMX_METRIC_320                  320
#define KMX_METRIC_400                  400
#define KMX_METRIC_480                  480
#define KMX_METRIC_640                  640
#define KMX_METRIC_800                  800

/****************************************************************************

Image ID constants.

****************************************************************************/

#define KMX_IMAGE_240_COMMON            0
#define KMX_IMAGE_240_ARABIC            1
#define KMX_IMAGE_240_BENGALI           2
#define KMX_IMAGE_240_BOPOMOFO          3
#define KMX_IMAGE_240_BULGARIAN         4
#define KMX_IMAGE_240_ENGLISH           5
#define KMX_IMAGE_240_GREEK             6
#define KMX_IMAGE_240_HEBREW            7
#define KMX_IMAGE_240_HINDI             8
#define KMX_IMAGE_240_PERSIAN           9
#define KMX_IMAGE_240_RUSSIAN           10
#define KMX_IMAGE_240_STROKE            11
#define KMX_IMAGE_240_THAI              12
#define KMX_IMAGE_240_UKRAINIAN         13

#define KMX_IMAGE_320_COMMON            20
#define KMX_IMAGE_320_ARABIC            21
#define KMX_IMAGE_320_BENGALI           22
#define KMX_IMAGE_320_BOPOMOFO          23
#define KMX_IMAGE_320_BULGARIAN         24
#define KMX_IMAGE_320_ENGLISH           25
#define KMX_IMAGE_320_GREEK             26
#define KMX_IMAGE_320_HEBREW            27
#define KMX_IMAGE_320_HINDI             28
#define KMX_IMAGE_320_PERSIAN           29
#define KMX_IMAGE_320_RUSSIAN           30
#define KMX_IMAGE_320_STROKE            31
#define KMX_IMAGE_320_THAI              32
#define KMX_IMAGE_320_UKRAINIAN         33

/****************************************************************************

Button data structure.

****************************************************************************/

/* Button flag constants */

#define KMX_BF_REPEAT       0x0100
#define KMX_BF_HOLD         0x0200
#define KMX_BF_NOECHO       0x1000
#define KMX_BF_NOHIGH       0x2000
#define KMX_BF_HIGHLIGHT    0x4000

#define KMX_BF_DATA_MASK    0x00FF

/* Button ID constants */

#define KMX_BID_0           0
#define KMX_BID_1           1
#define KMX_BID_2           2
#define KMX_BID_3           3
#define KMX_BID_4           4
#define KMX_BID_5           5
#define KMX_BID_6           6
#define KMX_BID_7           7
#define KMX_BID_8           8
#define KMX_BID_9           9
#define KMX_BID_MARK        10

#define KMX_BID_SPACE       11
#define KMX_BID_BACK        12
#define KMX_BID_CAPS_L      13
#define KMX_BID_CAPS_I      14
#define KMX_BID_CAPS_U      15
#define KMX_BID_CANCEL      16
#define KMX_BID_AUX         17
#define KMX_BID_IME         18
#define KMX_BID_CAD         19
#define KMX_BID_SYM         20
#define KMX_BID_CHAR        21
#define KMX_BID_TEXT        22
#define KMX_BID_RETURN      23
#define KMX_BID_COMP        24

#define KMX_BID_PREV        33
#define KMX_BID_NEXT        34
#define KMX_BID_AUX_PREV    35
#define KMX_BID_AUX_NEXT    36
#define KMX_BID_SWITCH      37

#define KMX_BID_HIDE        51

#define KMX_BID_COMMIT    61
#define KMX_BID_VOID        62
#define KMX_BID_NONE        63

/* Button label flag constants */

#define KMX_LABEL_VCENTER           0x0001
#define KMX_LABEL_HCENTER           0x0002
#define KMX_LABEL_CENTER            (KMX_LABEL_VCENTER | KMX_LABEL_HCENTER)
#define KMX_LABEL_BOLD              0x0004
#define KMX_LABEL_ITALIC            0x0008
#define KMX_LABEL_UNDERLINE         0x0010
#define KMX_LABEL_RTL               0x0040

#define KMX_LABEL_MESS              0x0080

#define KMX_BUTTON_EXTRA_FLAG_HIGHLIGHT  0x0001


typedef struct
{
    short                   x;              /* Position */
    short                   y;
    short                   width;          /* Size */
    short                   height;
    int                     label_flags;    /* Label display flags */
    const KMX_WCHAR*        label_text;     /* Label text */
    KMX_COLOR               label_color;    /* Label text color */
    short                   label_font_size;/* Label Font size */
    short                   label_x;        /* Label position offset */
    short                   label_y;
    short                   image;          /* Background image ID */
    short                   image_x;        /* Background image position */
    short                   image_y;
    int                     extra_flags;    /* Extra button attribute */
} KMX_BUTTON;

typedef struct
{
    int left;
    int top;
    int right;
    int bottom;
}KMX_RECT;


/****************************************************************************

Messages.

****************************************************************************/

typedef struct
{
    int     code;
    int     param1;
    int     param2;
} KMX_MSG;

#define KMX_MSG_TIMER               1
/*
    param1: timer_id
    param2: not used
*/

#define KMX_MSG_PEN_DOWN            2
#define KMX_MSG_PEN_MOVE            3
#define KMX_MSG_PEN_UP              4
/*
    param1: x
    param2: y
*/

#define KMX_MSG_METRIC_CHANGE       5
/* 
    param1: metric
    param2: set 1 force not to redraw, set 0 as default, may need redraw. 
*/

#define KMX_MSG_CONTEXT_ACTIVE      6
#define KMX_MSG_CONTEXT_DEACTIVE    7
#define KMX_MSG_CONTEXT_CHANGE      8
#define KMX_MSG_CONTEXT_CLEAR       9
/*
    param1: not used
    param2: not used
*/

#define KMX_MSG_IME_CHANGE          10
/*
    param1: ime_id
    param2: language
*/

#define KMX_MSG_CASE_CHANGE          11
/*
    param1: language
    param2: case_info
*/

#define KMX_MSG_RESET               12
/*
    param1: not used
    param2: not uesd
*/

#define KMX_MSG_KEY_PRESSED   13
/*
    param1: key id
    param2: flags
*/

#define KMX_MSG_GET_IME_STATE   14
/*
    param1: pointer to KMX_IME_STATE
    param2: not used
*/

#define KMX_MSG_KEY_DOWN            15
#define KMX_MSG_KEY_UP              16

#define KMX_MSG_SCREEN_SWITCH       17

#define KMX_MSG_SET_KEYBOARD_TYPE     18
/*
    param1: KMX_KEYBOARD_TYPE_DIGIT/KMX_KEYBOARD_TYPE_QWERTY
    param2: not used
*/

#define KMX_MSG_SET_PROPERTY        19
/*
    param1: properties to be set
    param2: not used
*/

#define KMX_MSG_SET_VALID_SYMBOL_LIST 20
/*
    param1: pointer to Zero ended const unsigned short array.
    param2: not used
*/

#define KMX_MSG_GET_PROPERTY        21
/*
    param1: not used
    param2: not used
*/

#define KMX_MSG_ADD_PROPERTY        22
/*
    param1: properties to be added
    param2: not used
*/

#define KMX_MSG_CLR_PROPERTY        23
/*
    param1: properties to be cleared
    param2: not used
*/

#define KMX_MSG_LOCK_IME            24
/*
    param1: 1 to lock the ime, the following KMX_MSG_IME_CHANGE would be ignored.
            0 to unlock the ime, the following KMX_MSG_IME_CHANGE would be handled.
    param2: not used
*/

#define KMX_MSG_MAX                 64

/****************************************************************************

Notify Messages.

****************************************************************************/

#define KMX_NOTIFY_MSG_IME_CHANGE   KMX_MSG_MAX + 1
/*
    Notify by the Imm when input method changed by press the IME button or by press the CAPS button.
    param1: ime_id
    param2: bits 0-7 language, bits 8-10 case info
*/

#define KMX_NOTIFY_MSG_SLIDE        		KMX_MSG_MAX + 2
/*
    Notify by the Imm when a slide operation had happened.
    param1: slide direction
    param2: slide area represents by a KMX_RECT structure.
*/

#define KMX_NOTIFY_MSG_KEY_PRESSED	KMX_MSG_MAX + 3
/*
    Notify by the Imm when a virtual key is pressed.
    param1: button id
    param2: flags.
*/

#define KMX_NOTIFY_POPUP	KMX_MSG_MAX + 4
/*
    Notify by the Imm popup position.
    param1: button (x << 16) | y
    param2: popup style.
*/

#define KMX_NOTIFY_POPUP_BEGIN	KMX_MSG_MAX + 5
/*
    Notify by the Imm begin paint popup buttons.
    param1: not used
    param2: not used
*/

#define KMX_NOTIFY_POPUP_END	KMX_MSG_MAX + 6
/*
    Notify by the Imm end of paint popup buttons.
    param1: not used
    param2: not used
*/

#define KMX_NOTIFY_MSG_STATE_CHANGE	KMX_MSG_MAX + 7
/*
    Notify by the Imm when internal input state changed which must be aware of client side.
    param1: current state
    param2: prev state
*/

#define KMX_NOTIFY_MSG_MAX      100

/****************************************************************************

Message Macro.

****************************************************************************/

#define KMX_PACK_IME_CHANGE_PARAM2(l, c) ((l) | (((c) & 7) << 8))
#define KMX_UNPACK_IME_CHAGE_PARAM2(p, l, c) l = (p) & 0xFF; c = (p) >> 8 & 7

/****************************************************************************

Slide Direction.

****************************************************************************/

#define KMX_SLIDE_DIRECTION_NONE     0
#define KMX_SLIDE_DIRECTION_UPWARD   1
#define KMX_SLIDE_DIRECTION_DOWNWARD 2
#define KMX_SLIDE_DIRECTION_FORWARD  4
#define KMX_SLIDE_DIRECTION_BACKWARD 8

/****************************************************************************

Output data structure.

****************************************************************************/

/* Output text length limit */
#define KMX_MAX_COMMIT              64
#define KMX_MAX_COMPOSITION         64

/* Composition flag constants */
#define KMX_FLAG_COMP_TEXT          0x0001

typedef struct
{
    int                     flags;
    int                     commit_length;
    KMX_WCHAR               commit_text[KMX_MAX_COMMIT];
    int                     composition_length;
    KMX_WCHAR               composition_text[KMX_MAX_COMPOSITION];
} KMX_OUTPUT;

/****************************************************************************

Keypad driver APIs.

****************************************************************************/

/* Timer ID constants. */

#define KMX_TIMER_1                 1
#define KMX_TIMER_2                 2

/* Context flag constants */

#define KMX_FLAG_COMP_SUPPORT       0x0001

typedef struct
{
    int                     flags;
    KMX_WCHAR*              text_buffer;
    int                     text_buffer_length;
    int                     text_length;
    int                     caret_position;
} KMX_CONTEXT;

typedef struct tag_KMX_KEYPAD   KMX_KEYPAD;

typedef void (*KMX_KEYPAD_GET_CONTEXT_PROC)(
    KMX_KEYPAD*             keypad,
    KMX_CONTEXT*            context);

typedef void (*KMX_KEYPAD_SET_TIMER_PROC)(
    KMX_KEYPAD*             keypad,
    int                     timer_id,
    int                     time);

typedef void (*KMX_KEYPAD_ECHO_BUTTON_PROC)(
    KMX_KEYPAD*             keypad,
    const KMX_BUTTON*       button);

typedef void (*KMX_KEYPAD_GET_TEXT_SIZE_PROC)(
    KMX_KEYPAD*             keypad,
    const KMX_WCHAR*        text,
    int                     length,
    int                     font_size,
    int*                    width,
    int*                    height);

typedef void (*KMX_KEYPAD_DRAW_BACKGROUND_PROC)(
    KMX_KEYPAD*             keypad,
    int                     clip_left,
    int                     clip_top,
    int                     clip_right,
    int                     clip_bottom);

typedef void (*KMX_KEYPAD_DRAW_TEXT_PROC)(
    KMX_KEYPAD*             keypad,
    int                     x,
    int                     y,
    const KMX_WCHAR*        text,
    int                     length,
    int                     font_size,
    KMX_COLOR               color);

typedef void (*KMX_KEYPAD_DRAW_RECT_PROC)(
    KMX_KEYPAD*             keypad,
    int                     left,
    int                     top,
    int                     right,
    int                     bottom,
    KMX_COLOR               color);

typedef void (*KMX_KEYPAD_DRAW_BUTTON_PROC)(
    KMX_KEYPAD*             keypad,
    const KMX_BUTTON*       buttons,
    int                     num_buttons);

typedef void (*KMX_KEYPAD_IMM_NOTIFY_HANDLER)(
    KMX_KEYPAD*             keypad,
    KMX_MSG*                notify_msg
);

struct tag_KMX_KEYPAD
{
    KMX_KEYPAD_GET_CONTEXT_PROC     f_get_context;
    KMX_KEYPAD_SET_TIMER_PROC       f_set_timer;
    KMX_KEYPAD_ECHO_BUTTON_PROC     f_echo_button;
    KMX_KEYPAD_GET_TEXT_SIZE_PROC   f_get_text_size;
    KMX_KEYPAD_DRAW_BACKGROUND_PROC f_draw_background;
    KMX_KEYPAD_DRAW_TEXT_PROC       f_draw_text;
    KMX_KEYPAD_DRAW_RECT_PROC       f_draw_rect;
    KMX_KEYPAD_DRAW_BUTTON_PROC     f_draw_button;
    KMX_KEYPAD_IMM_NOTIFY_HANDLER   f_notify_handler; 
};

/****************************************************************************

Input method APIs.

****************************************************************************/

typedef struct
{
    int                     input_method;
    int                     language;
    int                     ui_language;
    const void*             primary_database;
    const void*             secondary_database; /* Used as extra flags capable case in Multitap/Smart ime */
    void*                   user_data;
    int                     user_data_size;
} KMX_IME_CONFIG;

typedef void*   KMX_IMM;

/* kmx_imm_handle_message return flag constants */

#define KMX_FLAG_UPDATE_DISPLAY     0x0001
#define KMX_FLAG_UPDATE_SIZE        0x0002
#define KMX_FLAG_ENTER_HW           0x0004

#define KMX_FLAG_PROMPT_POP_UP      0x0100

typedef enum
{
    KMX_STATE_NORMAL,
    KMX_STATE_ASSO,
    KMX_STATE_EDIT,
    KMX_STATE_LIST,
    KMX_STATE_CANDIDATE,
    KMX_STATE_MULTITAP0,
    KMX_STATE_MULTITAP1,
    KMX_STATE_MULTITAP2,
    KMX_STATE_MULTITAP3,
    KMX_STATE_MULTITAP4,
    KMX_STATE_MULTITAP5,
    KMX_STATE_MULTITAP6,
    KMX_STATE_MULTITAP7,
    KMX_STATE_MULTITAP8,
    KMX_STATE_MULTITAP9,
    KMX_STATE_MULTITAP_MARK,
    KMX_STATE_SYM1,
    KMX_STATE_SYM2,
    KMX_STATE_SYM3,
    KMX_STATE_CAPS_LOWER,
    KMX_STATE_CAPS_INITIAL,
    KMX_STATE_CAPS_UPPER,
    KMX_STATE_MULTITAP
} KMX_IME_STATE;

/* Callback for fetching update data. E.g. Pinyin extra user word.  */
typedef int (*KMX_CALLBACK_READ_UPDATE_DATA)(unsigned char *buffer, int pos, int length);

/* Callback for checking whether handwriting is disabled or not.  */
typedef int (*KMX_CALLBACK_IS_HW_DISABLED)(void);

/* Callback for checking whether associaiton is disabled or not.  */
typedef int (*KMX_CALLBACK_IS_ASSO_DISABLED)(void);

typedef struct {
    KMX_CALLBACK_READ_UPDATE_DATA f_read_update_data;
    KMX_CALLBACK_IS_HW_DISABLED   f_is_hw_disabled;
    KMX_CALLBACK_IS_ASSO_DISABLED f_is_asso_disabled;
}KMX_KEYPAD_EXTRA_CALLBACKS;

KMX_IMM kmx_imm_create(
    KMX_KEYPAD*             keypad,
    int                     metric,
    int                     digit_button_height,
    const KMX_IME_CONFIG*   input_method_list,
    int                     num_input_methods);

KMX_IMM kmx_imm_create_ex(
    KMX_KEYPAD*             keypad,
    int                     metric,
    int                     digit_button_height,
    int                     qwerty_button_height,
    int                     keyboard_type,
    const KMX_IME_CONFIG*   input_method_list,
    int                     num_input_methods);

KMX_IMM kmx_imm_create_ex_with_properties(
    KMX_KEYPAD*             keypad,
    int                     metric,
    int                     digit_button_height,
    int                     qwerty_button_height,
    int                     keyboard_type,
    const KMX_IME_CONFIG*   input_method_list,
    int                     num_input_methods,
    unsigned int            properties);


void kmx_imm_destroy(
    KMX_IMM                 imm);

int kmx_imm_handle_message(
    KMX_IMM                 imm,
    const KMX_MSG*          message,
    KMX_OUTPUT*             output);

int kmx_imm_get_ime(
    KMX_IMM                 imm);

void kmx_imm_get_window_size(
    KMX_IMM                 imm,
    int*                    width,
    int*                    height);

void kmx_imm_paint_window(
    KMX_IMM                 imm);

void kmx_imm_set_extra_callbacks(
    KMX_IMM                       imm,
    KMX_KEYPAD_EXTRA_CALLBACKS*   callbacks);

#ifdef __cplusplus
}
#endif

#endif /* KMXIMMAPI_H */
