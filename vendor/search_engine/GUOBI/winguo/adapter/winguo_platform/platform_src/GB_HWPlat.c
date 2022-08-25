
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__

#undef GB_PACKAGE
#include "MMI_include.h"


#include "GB_WG_Public.h"
#include "GB_HWPlat.h"
#include "gbmd_phonever.h"
#include "GB_WG_MTKPlatver.h"

GB_LONG GB_WG_GetScrW(GB_VOID)
{
	return MAIN_LCD_DEVICE_WIDTH;
}
GB_LONG GB_WG_GetScrH(GB_VOID)
{
	return MAIN_LCD_DEVICE_HEIGHT;
}

/////////////////////
GB_CHAR *GB_WG_Get_PhoneHW_Info(GB_WG_E_PhoneHW_Info einfo)
{
	GB_CHAR *pinfoStr = NULL;
	switch(einfo)
	{
	case E_PhoneHW_COMPANY:
		pinfoStr = GB_WG_COMPANY;
		break;
	case E_PhoneHW_PSTYLE:
		pinfoStr = GB_WG_PSTYLE;
		break;
	case E_PhoneHW_ROM:
		pinfoStr = GB_WG_ROM;
	    break;
// 	case E_PhoneHW_PLATFORM:
// 		pinfoStr = GB_WG_PLATFORM;
// 	    break;
	case E_PhoneHW_LICENSE:
		pinfoStr = GB_WG_LICENSE;
		break;
	default:
		ASSERT(0);
	    break;
	}
	return pinfoStr;
}


GB_VOID GB_WG_pen_register_down_handler(GB_VOID* pen_fp)
{
#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_down_handler((mmi_pen_hdlr)pen_fp);
#endif
}

GB_VOID GB_WG_pen_register_move_handler(GB_VOID* pen_fp)
{
#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_move_handler((mmi_pen_hdlr)pen_fp);
#endif
}

GB_VOID GB_WG_pen_register_long_tap_handler(GB_VOID* pen_fp)
{
#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_long_tap_handler((mmi_pen_hdlr)pen_fp);
#endif
}

GB_VOID GB_WG_pen_register_up_handler(GB_VOID* pen_fp)
{
#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_up_handler((mmi_pen_hdlr)pen_fp);
#endif
}


typedef struct 
{
	GB_U8 Sys_Key;
	GB_U8 wg_key;
}key_Transform;
const key_Transform GB_HW_key_Transform[]=
{
	{KEY_0,GB_WG_KEY_0},
	{KEY_1,GB_WG_KEY_1},
	{KEY_2,GB_WG_KEY_2},
	{KEY_3,GB_WG_KEY_3},
	{KEY_4,GB_WG_KEY_4},
	{KEY_5,GB_WG_KEY_5},
	{KEY_6,GB_WG_KEY_6},
	{KEY_7,GB_WG_KEY_7},
	{KEY_8,GB_WG_KEY_8},
	{KEY_9,GB_WG_KEY_9},
	{KEY_LSK,GB_WG_KEY_LSK},
	{KEY_RSK,GB_WG_KEY_RSK},
	{KEY_CSK,GB_WG_KEY_ENTER},
	{KEY_UP_ARROW,GB_WG_KEY_UP_ARROW},
	{KEY_DOWN_ARROW,GB_WG_KEY_DOWN_ARROW},
	{KEY_LEFT_ARROW,GB_WG_KEY_LEFT_ARROW},
	{KEY_RIGHT_ARROW,GB_WG_KEY_RIGHT_ARROW},
	{KEY_SEND,GB_WG_KEY_SEND},
	{KEY_END,GB_WG_KEY_END},
	{KEY_CLEAR,GB_WG_KEY_CLEAR},
	{KEY_STAR,GB_WG_KEY_STAR},
	{KEY_POUND,GB_WG_KEY_POUND},
	{KEY_VOL_UP,GB_WG_KEY_VOL_UP},
	{KEY_VOL_DOWN,GB_WG_KEY_VOL_DOWN},
	{KEY_QUICK_ACS,GB_WG_KEY_QUICK_ACS},
	{KEY_ENTER,GB_WG_KEY_ENTER},
	{KEY_BACK,GB_WG_KEY_BACK},
	{KEY_POWER,GB_WG_KEY_POWER},

#ifdef __SENDKEY2_SUPPORT__
	{KEY_SEND1,GB_WG_KEY_SEND1},
	{KEY_SEND2,GB_WG_KEY_SEND2},
#endif	/* __SENDKEY2_SUPPORT__ */

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	{KEY_A,GB_WG_KEY_A},
	{KEY_B,GB_WG_KEY_B},
	{KEY_C,GB_WG_KEY_C},
	{KEY_D,GB_WG_KEY_D},
	{KEY_E,GB_WG_KEY_E},
	{KEY_F,GB_WG_KEY_F},
	{KEY_G,GB_WG_KEY_G},
	{KEY_H,GB_WG_KEY_H},
	{KEY_I,GB_WG_KEY_I},
	{KEY_J,GB_WG_KEY_J},
	{KEY_K,GB_WG_KEY_K},
	{KEY_L,GB_WG_KEY_L},
	{KEY_M,GB_WG_KEY_M},
	{KEY_N,GB_WG_KEY_N},
	{KEY_O,GB_WG_KEY_O},
	{KEY_P,GB_WG_KEY_P},
	{KEY_Q,GB_WG_KEY_Q},
	{KEY_R,GB_WG_KEY_R},
	{KEY_S,GB_WG_KEY_S},
	{KEY_T,GB_WG_KEY_T},
	{KEY_U,GB_WG_KEY_U},
	{KEY_V,GB_WG_KEY_V},
	{KEY_W,GB_WG_KEY_W},
	{KEY_X,GB_WG_KEY_X},
	{KEY_Y,GB_WG_KEY_Y},
	{KEY_Z,GB_WG_KEY_Z},
	{KEY_SPACE,GB_WG_KEY_SPACE},
	{KEY_TAB,GB_WG_KEY_TAB},
	{KEY_DEL,GB_WG_KEY_DEL},
	{KEY_ALT,GB_WG_KEY_ALT},
	{KEY_CTRL,GB_WG_KEY_CTRL},
	{KEY_WIN,GB_WG_KEY_WIN},
	{KEY_SHIFT,GB_WG_KEY_SHIFT},
	{KEY_QUESTION,GB_WG_KEY_QUESTION},
	{KEY_PERIOD,GB_WG_KEY_PERIOD},
	{KEY_COMMA,GB_WG_KEY_COMMA},
	{KEY_EXCLAMATION,GB_WG_KEY_EXCLAMATION},
	{KEY_APOSTROPHE,GB_WG_KEY_APOSTROPHE},
	{KEY_AT,GB_WG_KEY_AT},
	{KEY_BACKSPACE,GB_WG_KEY_BACKSPACE},
	{KEY_QWERTY_ENTER,GB_WG_KEY_ENTER},
	{KEY_FN,GB_WG_KEY_FN},
	{KEY_SYMBOL,GB_WG_KEY_SYMBOL},
	{KEY_NUM_LOCK,GB_WG_KEY_NUM_LOCK},
	{KEY_QWERTY_MENU,GB_WG_KEY_QWERTY_MENU},
	{KEY_OK,GB_WG_KEY_OK}
#endif /* __QWERTY_KEYPAD_SUPPORT__ */
};
GB_INT GB_WG_SysKeyTransform(GB_INT key)
{
	GB_INT wg_key = GB_WG_KEY_INVALID;
	GB_INT i;
	if (key==KEY_INVALID)
	{
		return wg_key;
	}
	for (i=0; i<sizeof(GB_HW_key_Transform)/sizeof(key_Transform); i++)
	{
		if(GB_HW_key_Transform[i].Sys_Key == key)
		{
			wg_key = GB_HW_key_Transform[i].wg_key;
			break;
		}
	}
	return wg_key;
}

GB_INT GB_WG_SysKeyEventTransform(GB_INT KeyEvent)
{
	GB_INT wg_keyEvent = GBEVENT_INVALID;
	switch(KeyEvent)
	{
	case KEY_EVENT_DOWN:
		wg_keyEvent = GBKEY_PRESS;
		break;
	case KEY_EVENT_UP:
		wg_keyEvent = GBKEY_RELEASE;
		break;
	case KEY_LONG_PRESS:
		wg_keyEvent = GBKEY_LONG_PRESS;
	    break;
	case KEY_REPEAT:
		wg_keyEvent = GBKEY_REPEAT;
		break;
	default:
	    break;
	}
	return wg_keyEvent;
}

GB_INT GB_WG_SysPenEventTransform(GB_INT penEvent)
{
	GB_INT wg_penEvent = GBPEN_INVALID;
	switch(penEvent)
	{
	case MMI_PEN_EVENT_DOWN:
		wg_penEvent = GBPEN_DOWN;
		break;
	case MMI_PEN_EVENT_UP:
		wg_penEvent = GBPEN_UP;
		break;
	case MMI_PEN_EVENT_MOVE:
		wg_penEvent = GBPEN_MOVE;
	    break;
	default:
	    break;
	}
	return wg_penEvent;
}

GB_INT GB_WG_WinguoKeyToSys(GB_INT wg_key)
{
	GB_INT sys_key = KEY_INVALID;
	GB_INT i;
	if (wg_key==GB_WG_KEY_INVALID)
	{
		return sys_key;
	}
	for (i=0; i<sizeof(GB_HW_key_Transform)/sizeof(key_Transform); i++)
	{
		if(GB_HW_key_Transform[i].wg_key == wg_key)
		{
			sys_key = GB_HW_key_Transform[i].Sys_Key;
			break;
		}
	}
	return sys_key;
}

GB_INT GB_WG_WinguoKeyEventToSys(GB_INT wg_keyEvent)
{
	GB_INT sys_keyEvent = MAX_KEY_TYPE;
	switch(wg_keyEvent)
	{
	case GBKEY_PRESS:
		sys_keyEvent = KEY_EVENT_DOWN;
		break;
	case GBKEY_RELEASE:
		sys_keyEvent = KEY_EVENT_UP;
		break;
	case GBKEY_LONG_PRESS:
		sys_keyEvent = KEY_LONG_PRESS;
		break;
	case GBKEY_REPEAT:
		sys_keyEvent = KEY_REPEAT;
		break;
	default:
		break;
	}
	return sys_keyEvent;
}

#endif /* #ifdef __MMI_GB_WINGUO__ */
