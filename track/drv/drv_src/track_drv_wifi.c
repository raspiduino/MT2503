#if defined __CUSTOM_WIFI_FEATURES_SWITCH__
#include "track_drv.h"
#include "track_cust_wifi.h"
#define WIFI_TURN_ON_CMD        "AT+EWIFI=1\r\n"
#define WIFI_TURN_OFF_CMD       "AT+EWIFI=0\r\n"
#define WIFI_SCAN_AP_LIST_CMD   "AT+EWIFI=2\r\n"



kal_uint8 track_drv_wifi_status(kal_uint32 op)
{
    static kal_uint32 status = 0;
    LOGD(L_DRV, L_V5, "status=%d", status);
    if(op == 99)
    {
        return status;
    }
    status = op;
    return status;
}


void track_drv_wifi_cmd(U8 op)
{
	kal_uint32 tick = kal_get_systicks();
	if(kal_ticks_to_secs(tick) < 20)
	{
		LOGD(L_APP, L_V5, "wifi test assert");
		return;
	}
    if(op == 1)
    {
        track_at_vs_send(WIFI_TURN_ON_CMD);
        LOGD(L_DRV, L_V5, "wifi on");
        track_drv_wifi_status(1);
    }
    else if(op == 0)
    {
        track_at_vs_send(WIFI_TURN_OFF_CMD);
        LOGD(L_DRV, L_V5, "wifi off");
        track_drv_wifi_status(0);
    }
    else
    {
        track_at_vs_send(WIFI_SCAN_AP_LIST_CMD);
        LOGD(L_DRV, L_V5, "wifi scan");
    }
}

void track_drv_wifi_hotspot(kal_uint8* data, kal_uint16 len)
{
    static kal_uint8 wifi_buffer[10][200] = {0};
    static kal_uint32 index = 0, i = 0, scan_index = 0;

    
    if(len > 200)
    {
        len = 200;
    }

    if(strstr(data, "LASTAP"))
    {
        LOGD(L_DRV, L_V5, "»º³åÇøÒÑÂú,Çå³ýBUF");
        for(i = 0; i < index; i++)
        {
            LOGD(L_DRV, L_V5, "%s", wifi_buffer[i]);
        }
        if(index != 0)
        {
            LOGD(L_DRV, L_V5, "#1");
            scan_index = 0;
            track_cust_wifidata((kal_uint8*)wifi_buffer, index);
        }
        else
        {
            LOGD(L_DRV, L_V5, "#2");
            if(scan_index < 3)
            {
                scan_index++;
                track_drv_wifi_cmd(2);
            }
            else
            {
                track_cust_wifidata((kal_uint8*)wifi_buffer, index);
                scan_index = 0;
            }
        }
        index = 0;
        memset(wifi_buffer, 0x00, sizeof(wifi_buffer));
    }
    else
    {
        memcpy(wifi_buffer[index], data, len);
        index++;
    }
    LOGD(L_DRV, L_V7, "%s", data);
}


#endif
