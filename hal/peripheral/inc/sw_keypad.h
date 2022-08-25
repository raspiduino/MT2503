#ifndef _SW_KEYPAD_H
#define _SW_KEYPAD_H

#include 	"kal_general_types.h"
#include 	"drv_features.h"
#include    "keypad.h"
#include    "keypad_hw.h"

#define    RowNum		5
#define    ColNum		5
#if defined(SW_KBD_COL_PUPD_1_2M)
#define SW_KBD_ROW_SCAN_TIME    160
#define SW_KBD_ROW_INTERVAL_TIME    160
#define SW_KBD_COL_SCAN_TIME    15
#define SW_KBD_COL_INTERVAL_TIME   15
#else
#define SW_KBD_ROW_SCAN_TIME   15
#define SW_KBD_ROW_INTERVAL_TIME    15
#define SW_KBD_COL_SCAN_TIME   15
#define SW_KBD_COL_INTERVAL_TIME   15
#endif

#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)
#define Sw_kbd_polling_time  5
#elif defined(__TWO_KEY_DETECTION_SWITCHABLE__)
#define Sw_kbd_polling_time   5
#else
#define Sw_kbd_polling_time  10
#endif
 typedef struct KeyStatus
{
	kal_uint32 reg1;
	kal_uint32 reg2;
	kal_uint32 reg3;
} KEY_STATUS;

typedef void (*SW_KBD_TIMER_CB)(void* parameter) ; 

void sw_kbd_init(void);
void sw_kbd_get_key_status_s(KEY_STATUS* key_status);
void sw_kbd_get_key_status_d(KEY_STATUS* key_status);
void sw_kbd_get_key_status_t(KEY_STATUS* key_status);

/*triple keypad*/
#if defined(DRV_KBD_TRIPLE_KEYPAD)
#define ROWS_DETECT_STAGE1     1
#define ROWS_DETECT_STAGE2     2
#define  SW_KBD_GET_KEY_STATUS(a) sw_kbd_get_key_status_t((a))
/*double keypad*/
#elif defined(__COLUMN_EXTEND_KEYPAD__)
#define  SW_KBD_GET_KEY_STATUS(a) sw_kbd_get_key_status_d((a))
/*single keypad*/
#else
#define  SW_KBD_GET_KEY_STATUS(a) sw_kbd_get_key_status_s((a))
#endif

void sw_kbd_idle_stage(void);
void sw_kbd_paremeter_init(void);


const extern  char gpio_keypad_row0_pin;
const extern  char gpio_keypad_row1_pin;
const extern  char gpio_keypad_row2_pin;
const extern  char gpio_keypad_row3_pin;
const extern  char gpio_keypad_row4_pin;
const extern  char gpio_keypad_col0_pin;
const extern  char gpio_keypad_col1_pin;
const extern  char gpio_keypad_col2_pin;
const extern  char gpio_keypad_col3_pin;
const extern  char gpio_keypad_col4_pin;

extern const unsigned char KEYPAD_WAKEUP_EINT_NO;
#define SW_KBD_EINT_NO KEYPAD_WAKEUP_EINT_NO
#define KEYPAD_ENBALE_REG	KP_EN 

#endif












