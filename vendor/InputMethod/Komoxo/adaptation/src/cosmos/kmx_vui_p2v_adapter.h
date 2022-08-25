#ifndef KMX_VUI_P2V_ADAPTER_H
#define KMX_VUI_P2V_ADAPTER_H

#ifdef __cplusplus
extern "C" {
#endif

void kmx_vui_init(void);
void kmx_vui_exit(void);

int kmx_vui_is_vui_control(void* ptr);
void kmx_vui_layout_control(int bottom_y);
void kmx_vui_set_dirty(void);

int kmx_vui_update_control(unsigned int control_set);

#ifdef __cplusplus
}
#endif

#endif
