
#ifndef KMXSIP_USER_DATA_H
#define KMXSIP_USER_DATA_H

#ifndef KMXSIP_CONFIG_H
    #include "kmxsip_config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void load_user_data(
    void*           buffer,
    int             size);

void save_user_data(
    const void*     buffer,
    int             size);


void load_ime_user_setting(void);

void save_ime_user_setting(void);

// font set
int load_preferred_font_index(void);

void save_preferred_font_index(int index);

#ifdef __cplusplus
}
#endif

#endif /* KMXSIP_USER_DATA_H */

