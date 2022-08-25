#ifndef KMX_INPUT_PROT_H
#define KMX_INPUT_PROT_H

    #ifndef __IMESDKGPROT_H__
        #include "ImeSDKGprot.h"
    #endif

#if defined(__MMI_IME_PLUG_IN__)

typedef enum {
    MMI_IME_SDK_STATE_MULTITAP = MMI_IME_SDK_STATE_BEGIN + 1,
    MMI_IME_SDK_STATE_CAND_SELECTING,
    MMI_IME_SDK_STATE_VK_CAND,
    MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_INPUT,
    MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP,
    MMI_IME_SDK_STATE_VIRTUAL_KEYBOARD_MULTITAP_HOVER,
}KMX_SDK_STATE_ENUM;

typedef enum {
    MMI_IME_SDK_IMUI_IME_WINDOW = MMI_IME_SDK_IMUI_CONTROL_BEGIN,
    MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD,
    MMI_IME_SDK_IMUI_CONTROL_LAST = MMI_IME_SDK_IMUI_VIRTUAL_KEYBOARD,
}KMX_SDK_CONTROL_ENUM;

#endif

int kmx_ime_is_auto_capitalization_enabled(void);
S32 kmx_ime_get_curr_allow_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max);

#endif /* KMX_INPUT_PROT_H */
