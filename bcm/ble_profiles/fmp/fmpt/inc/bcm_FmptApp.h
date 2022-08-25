#ifndef __FMPT_APP_H__
#define __FMPT_APP_H__

extern void fmpt_app_connection_cb(char* bdaddr, int connect_state);
extern void fmpt_app_alert_notify_cb(char* bdaddr, U8 alert_level);
extern void fmpt_app_enable(void);
extern void fmpt_app_disable(void);


#endif
