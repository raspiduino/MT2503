extern "C"
{
#include "ImeiSrvGprot.h"
}

AVK_MANUAL_CASE(AVK_OTHER_IMEI_GET,AVK_OTHER_IMEI)
{
	CHAR        imei_buf[SRV_IMEI_MAX_LEN + 1]        = {0}; 
	WCHAR       tmp_buf[50];
	WCHAR       output_buf[200]    = {0};  
	int         i                       = MMI_SIM1;
	int         tst_imei_sim_index      = 0;
	int         line_index              = 1;
	int			sim_index;
	MMI_BOOL 	isValid;


	mmi_wcscat((WCHAR *)output_buf,(WCHAR *)L"IMEI will be shown below:\n");
			
	for(sim_index=1; sim_index <= MMI_SIM_TOTAL; sim_index = sim_index<<1)
	{
		if(srv_imei_get_imei((mmi_sim_enum)sim_index,imei_buf,(SRV_IMEI_MAX_LEN + 1)))
		{
			isValid = imei_buf[0] == '\0'?MMI_FALSE:MMI_TRUE;
			AVK_LOG_EX(isValid == srv_imei_is_valid((mmi_sim_enum)sim_index));
			kal_wsprintf((WCHAR *)tmp_buf,"SIM %d IMEI:%s \n",sim_index/2+1,imei_buf);
			mmi_wcscat((WCHAR *)output_buf,(WCHAR *)tmp_buf);
			memset(imei_buf,0,(SRV_IMEI_MAX_LEN + 1));
		}    
	}
	AVK_LOG_FUN_MANUAL(srv_imei_get_imei);
	AVK_MANU_SHOW_SCR(output_buf,NULL,NULL);
}


AVK_MANUAL_CASE(AVK_OTHER_IMEI_PAIR,AVK_OTHER_IMEI)
{
    WCHAR       tmp_buf[50];
	WCHAR       output_buf[200]    = {0};  
	int         i                       = MMI_SIM1;
	int         tst_imei_sim_index      = 0;
	int         line_index              = 1;
	int			sim_index;
	
	for(sim_index=1; sim_index <= MMI_SIM_TOTAL; sim_index = sim_index<<1)
	{
		if(srv_imei_same_config_on_any_pair((mmi_sim_enum)sim_index))
		{
			kal_wsprintf((WCHAR *)tmp_buf,"SIM %d has same imei with it\n",sim_index/2+1);
		}
		else
		{
		    kal_wsprintf((WCHAR *)tmp_buf,"SIM %d has no same imei with it\n",sim_index/2+1);
        }
        mmi_wcscat((WCHAR *)output_buf,(WCHAR *)tmp_buf);
	}
	AVK_LOG_FUN_MANUAL(srv_imei_same_config_on_any_pair);
	AVK_MANU_SHOW_SCR(output_buf,NULL,NULL);
}

