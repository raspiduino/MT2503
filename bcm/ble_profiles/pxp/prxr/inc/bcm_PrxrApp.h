#ifndef __PRXR_APP_H__
#define __PRXR_APP_H__

void pxp_app_connection_state_cb(char* bdaddr, int connect_state);
void pxp_app_alert_notify_cb(char* bdaddr, U8 alert_level);

void pxp_app_config_level_alert_cb(char* bdaddr,U8 alert_level);
void pxp_app_enable(void);
void pxp_app_disable(void);
#endif
