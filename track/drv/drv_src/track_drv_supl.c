#include "Track_os_log.h"
#include "Track_drv.h"
#include "supl2mmi_struct.h"
#include "gps_struct.h"
#include "track_os_ell.h"

extern kal_uint32 Socket_get_account_id();

void track_drv_supl_status(void * msg)
{
	  supl_mmi_status_ind_struct *supl_status = (supl_mmi_status_ind_struct*)msg;
      if(supl_status->result==SUPL_MMI_RESULT_OK)     
      {
	      LOGD(L_DRV,L_V3,"SUPL 链接已建立!");
	  }
	  else
	  {
	      LOGD(L_DRV,L_V3,"SUPL 链接建立失败 %d!",supl_status->result);
	  }
}

/******************************************************************************
 *  Function    -  track_drv_enbale_supl
 *
 *  Purpose     -  SUPL 域名端口设置
 *
 *  Description - 
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-06-2016,  xzq
 * ----------------------------------------
 ******************************************************************************/
void track_drv_enbale_supl()
{
#if 1
    gps_supl_ind_struct *sulp=NULL;
	sulp = (gps_supl_ind_struct*)construct_local_para(sizeof(gps_supl_ind_struct), TD_CTRL);
	sulp->port=7275;
	sulp->use_tls=1;
	memcpy(sulp->server,"supl.google.com",sizeof(sulp->server));
	sulp->account_id=0;
	track_fun_msg_send(MSG_ID_SUPL_ENABLE,(void*)sulp,MOD_MMI,MOD_GPSADAPTOR);
	LOGD(L_SOC,L_V4,"%s, %d",sulp->server,sulp->account_id);
#endif
}

void track_at_set_tcpip()
{
       //track_send_at_to_l4c("AT+ETCPIP=1,0", 20);
}
