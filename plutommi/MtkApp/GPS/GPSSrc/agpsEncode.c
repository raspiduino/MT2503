#include "agpsEncode.h"

/* accord to ts49.031 R6 */
kal_uint8 AsnEncode_SS2_gpsAssistanceData(cp_mmi_req_assist_data_struct *gpsData, kal_uint8 *encodeBuf){
	kal_uint8 len=0;
	kal_uint8 i;
	if(gpsData == NULL || encodeBuf == NULL){ return len; }
	for(i=0;i<CP_MAX_GPS_ASSISTANCE_DATA_LEN;i++){	
		*(encodeBuf+i) = 0;
	}
	if(gpsData->almanac == KAL_TRUE){				*(encodeBuf+0) |= 1<<0;     }
	if(gpsData->utc_model == KAL_TRUE){				*(encodeBuf+0) |= 1<<1;     }
	if(gpsData->ionospheric_model == KAL_TRUE){		*(encodeBuf+0) |= 1<<2;     }
	if(gpsData->navigation_model == KAL_TRUE){		*(encodeBuf+0) |= 1<<3;     }
	if(gpsData->dgps_correction == KAL_TRUE){		*(encodeBuf+0) |= 1<<4;     }
	if(gpsData->ref_location == KAL_TRUE){			*(encodeBuf+0) |= 1<<5;     }
	if(gpsData->ref_time == KAL_TRUE){				*(encodeBuf+0) |= 1<<6;     }
	if(gpsData->acquisition_assist == KAL_TRUE){	*(encodeBuf+0) |= 1<<7;     }
	if(gpsData->realtime_integrity == KAL_TRUE){	*(encodeBuf+1) |= 1<<0;     }
	//gps_week
	*(encodeBuf+2) |= (gpsData->nav_model_data.gps_week&0x300)>>2;	
	*(encodeBuf+3) |= (gpsData->nav_model_data.gps_week>>0)&0xFF;	
	//gps_toe
	if(gpsData->nav_model_data.gps_toe<=167){ 
		*(encodeBuf+4) = gpsData->nav_model_data.gps_toe;
	}
	else{
		//range should be 0 ~ 167
		//kal_trace();
	}
	//nsat
	*(encodeBuf+5) |= (gpsData->nav_model_data.nsat&0xF)<<4;

	//T-Toe limit
	if(gpsData->nav_model_data.gps_toe<=10){ 
		*(encodeBuf+5) |= (gpsData->nav_model_data.toe_limit&0xF);
	}
	else{
		//range should be 0 ~ 10
		//kal_trace();
	}
	len = 6;

	if(gpsData->nav_model_data.sat_info_used == KAL_TRUE){
		for(i=0;i<gpsData->nav_model_data.nsat;i++){	
			*(encodeBuf+6+2*i) |= gpsData->nav_model_data.sat_info[i].sat_id&0x3F;
			*(encodeBuf+7+2*i) |= gpsData->nav_model_data.sat_info[i].iODE;
		}
		len += gpsData->nav_model_data.sat_info_used;
	}
	
	return len;
}
