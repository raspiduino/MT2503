/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  nitzSrv.c 
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"


#ifdef __MMI_NITZ__
// Temporaly used by cosmos
//#ifdef __COSMOS_MMI_PACKAGE__
/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMIDataType.h"
#include "NITZSrvGprot.h"
#include "NITZSrvIprot.h"
#include "GSM7BitDefaultAlphabet.h"	/* for CovertStringForPlatform */
#include "DateTimeGprot.h"  /* mmi_dt_set_rtc_dt */
#include "DateTimeType.h"

#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_scenario_gprot.h"
#include "app_datetime.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "string.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_nvram_gprot.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "nvram_common_defs.h"
#include "CustDataRes.h"
#include "GlobalConstants.h"
#include "ps_public_enum.h"
#include "mmi_common_app_trc.h"
#include "ps_public_struct.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_frm_utility_gprot.h"
#include "nvram_common_defs.h"

#include "mmi_rp_srv_nitz_def.h"
/***************************************************************************** 
* Define
*****************************************************************************/


#define NITZ_SIGN_BIT	0x08
#define NITZ_TZ_BIT		0x07

#define NITZ_HIGH_BIT	0xF0
#define NITZ_LOW_BIT	0x0F

#define srv_set_nitz_state(state)	srv_set_nitz_state_ext(state, __LINE__)
#define srv_get_nitz_state()		srv_get_nitz_state_ext(__LINE__)

// Add trace definition
#define MMI_NITZ_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_NITZ_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_NITZ_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_NITZ_TRACE7(sub_grp, arg1, arg2, arg3, arg4, arg5, arg6, arg7) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3, arg4, arg5, arg6, arg7)
		
/***************************************************************************** 
* External Variable
*****************************************************************************/
static srv_nitz_state_enum g_nitz_srv_state;
/***************************************************************************** 
* Global Variable
*****************************************************************************/


/***************************************************************************** 
* Local Function
*****************************************************************************/
/* NITZ Service Functions */
//void srv_set_nitz_state_ext(srv_nitz_state_enum state, U32 line);
//srv_nitz_state_enum srv_get_nitz_state_ext(U32 line);

static void srv_nitz_handler(mmi_sim_enum sim_id, void* msg);
void srv_nitz_msg_ind(void* msg, int mod_src);

static void srv_nitz_parse_msg_tz(void *msg, srv_nitz_context_struct *srv_nitz_cntx);
static void srv_nitz_parse_msg_opr_name(void *msg, srv_nitz_context_struct *srv_nitz_cntx);

static U8 srv_nitz_convert_time(U8 data);
static S16 srv_nitz_convert_timezone(U8 timezone);
static U32 srv_nitz_get_nw_name(U8 dcs, U8 len, CHAR *dstStr, CHAR *srcStr);

/***************************************************************************** 
* External Function
*****************************************************************************/

/* NITZ SRV functions Start */
/*****************************************************************************
 * FUNCTION
 *  srv_nitz_msg_ind
 * DESCRIPTION
 *  This function is SIM1 NITZ message indication handler function
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nitz_msg_ind(void *msg, int mod_src)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_sim_enum sim_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_NITZ_TRACE1(MMI_RTC_NITZ_MSG_HDLR, mod_src);

	sim_id = mmi_frm_l4c_mod_to_sim((module_type)mod_src);
	srv_nitz_handler(sim_id, msg);
}



/*****************************************************************************
 * FUNCTION
 *  srv_nitz_get_utc_time
 * DESCRIPTION
 *  This function is to get UTC time value from NITZ message
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nitz_get_utc_time(void *msg, MYTIME *out_time)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_time_zone_ind_struct *msg_info = (mmi_nw_time_zone_ind_struct*)msg;
		 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	out_time->nYear = srv_nitz_convert_time(msg_info->nw_time_zone_time.year) + YEARFORMATE;
    out_time->nMonth = srv_nitz_convert_time(msg_info->nw_time_zone_time.month);
    out_time->nDay = srv_nitz_convert_time(msg_info->nw_time_zone_time.day);
    out_time->nHour = srv_nitz_convert_time(msg_info->nw_time_zone_time.hour);
    out_time->nMin = srv_nitz_convert_time(msg_info->nw_time_zone_time.min);
    out_time->nSec = srv_nitz_convert_time(msg_info->nw_time_zone_time.sec);
}

/*****************************************************************************
 * FUNCTION
 *  srv_nitz_update_notify
 * DESCRIPTION
 *  This function send the NITZ update event
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nitz_update_notify(mmi_sim_enum sim_id, void *msg)
{
    mmi_nw_time_zone_ind_struct *msg_info = (mmi_nw_time_zone_ind_struct*)msg;
    srv_nitz_update_event_struct event_data;
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // update time to DRM
    MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_NITZ_UPDATE);

	srv_nitz_get_utc_time(msg, &event_data.time);
	
    event_data.sim_id = sim_id;

	if (msg_info->nw_time_zone_timeP)
	{
		FLOAT tz = (FLOAT)srv_nitz_convert_timezone(msg_info->nw_time_zone_time.time_zone);
		event_data.time_zone_p = 1;
		event_data.time_zone = tz / 4;		
	}
	else
	{
		event_data.time_zone_p = 0;
	}

	if (msg_info->nw_day_light_saving_timeP)
	{
		event_data.dst_p = 1;
	}
	else
	{
		event_data.dst_p = 0;
	}

	MMI_FRM_CB_EMIT_EVENT(&event_data);

}

/*****************************************************************************
 * FUNCTION
 *  srv_nitz_handler
 * DESCRIPTION
 *  This function is message handler of NITZ
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nitz_handler(mmi_sim_enum sim_id, void *msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nitz_update_req_event_struct event_data;
	srv_nitz_context_struct *srv_nitz_cntx = &event_data.nitz_data;
	U32 nitz_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_nitz_update_notify(sim_id, msg);
	nitz_state = srv_get_nitz_state();

	if (nitz_state != SRV_NITZ_STATE_OFF &&
		nitz_state != SRV_NITZ_BUSY)
    {
	    srv_set_nitz_state(SRV_NITZ_BUSY);
		MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_NITZ_UPDATE_REQ);		

		srv_nitz_cntx->sim_id = sim_id;

		srv_nitz_parse_msg_opr_name(msg, srv_nitz_cntx);
		srv_nitz_parse_msg_tz(msg, srv_nitz_cntx);

    // send update request to MMI
    srv_set_nitz_state(SRV_NITZ_WAIT_UPDATE);

	MMI_FRM_CB_EMIT_EVENT(&event_data);
}
}


/*****************************************************************************
 * FUNCTION
 *  srv_set_nitz_state
 * DESCRIPTION
 *  This function is to set NITZ state
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_set_nitz_state_ext(srv_nitz_state_enum state, U32 line)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_NITZ_TRACE2(MMI_RTC_NITZ_SET_STATE, state, line);
	
	g_nitz_srv_state = state;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nitz_get_state
 * DESCRIPTION
 *  This function is to get NITZ state
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
srv_nitz_state_enum srv_get_nitz_state_ext(U32 line)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_NITZ_TRACE2(MMI_RTC_NITZ_GET_STATE, line, g_nitz_srv_state);

	return g_nitz_srv_state;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nitz_parse_msg_opr_name
 * DESCRIPTION
 *  This function is high light handler of NITZ menu
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nitz_parse_msg_opr_name(void *msg, srv_nitz_context_struct *srv_nitz_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 updateShortNW, updateFullNW;
	mmi_nw_time_zone_ind_struct *msg_info = (mmi_nw_time_zone_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/* Network Name */
    /* Parse short name */
    if (msg_info->short_nw_nameP)
    {
        updateShortNW = srv_nitz_get_nw_name(
			msg_info->short_nw_name_dcs,
			msg_info->short_nw_name_len,
			(CHAR*) srv_nitz_cntx->operator_short_name,
			(CHAR*) msg_info->short_nw_name);
        MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_RTC_NITZ_UPDATE_SHORT_NETWORK_NAME, (S32) updateShortNW);
		
		srv_nitz_cntx->add_ci = msg_info->short_nw_name_add_ci;
    }

    /* Parse full name */
    if (msg_info->full_nw_nameP)
    {
        updateFullNW = srv_nitz_get_nw_name(
			msg_info->full_nw_name_dcs,
			msg_info->full_nw_name_len,
			(CHAR*) srv_nitz_cntx->operator_full_name,
			(CHAR*) msg_info->full_nw_name);
        MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_RTC_NITZ_UPDATE_FULL_NETWORK_NAME, (S32) updateFullNW);
		
		srv_nitz_cntx->add_ci = msg_info->full_nw_name_add_ci;
    }

    /* NITZ PLMN information */
    if (msg_info->plmn[0])
    {
        memcpy(srv_nitz_cntx->nitz_plmn, msg_info->plmn, MAX_PLMN_LEN + 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_nitz_get_info_from_msg
 * DESCRIPTION
 *  This function is high light handler of NITZ menu
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nitz_parse_msg_tz(void *msg, srv_nitz_context_struct *srv_nitz_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FLOAT nitz_timezone;
	MYTIME ref_time;
	mmi_nw_time_zone_ind_struct *msg_info = (mmi_nw_time_zone_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_NITZ_TRACE0(MMI_RTC_NITZ_PARSE);

	/* Parse NITZ Date And Time */
	if (msg_info->nw_time_zone_timeP)
    {
        srv_nitz_cntx->update_time = MMI_TRUE;
        /* compare network timezone and last received timezone */		
	    srv_nitz_get_utc_time(msg, &ref_time);
        srv_nitz_cntx->nitz_timezone = srv_nitz_convert_timezone(msg_info->nw_time_zone_time.time_zone);
        nitz_timezone = (FLOAT) srv_nitz_cntx->nitz_timezone;
        nitz_timezone /= 4;
		
		/* increase NITZ date time with time zone and save to global context */
        mmi_dt_utc_to_rtc(nitz_timezone, ref_time, srv_nitz_cntx->nitz_time);


		MMI_NITZ_TRACE7(MMI_RTC_NITZ_MSG, 
						    ref_time.nYear, 
						    ref_time.nMonth, 
						    ref_time.nDay, 
						    ref_time.nHour, 
						    ref_time.nMin, 
						    ref_time.nSec, 
						    srv_nitz_cntx->nitz_timezone);

        MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_RTC_NITZ_DT_INFO, (S32) srv_nitz_cntx->nitz_timezone, (S32) srv_nitz_cntx->nitz_time.nHour, (S32) srv_nitz_cntx->nitz_time.nMin, (S32) srv_nitz_cntx->nitz_time.nSec);
	}
	
	/* Parse NITZ Time Zone And Daylight Saving */
#ifdef __MMI_NITZ_TZ_SUPPORT__
	/* Time Zone Support set update time zone flag */
	srv_nitz_cntx->update_local_time_zone = msg_info->nw_time_zoneP;
    if (srv_nitz_cntx->update_local_time_zone)
	{
	    srv_nitz_cntx->nitz_timezone = srv_nitz_convert_timezone(msg_info->nw_time_zone);
	}
    /* DST Support */
	srv_nitz_cntx->update_day_light_saving = msg_info->nw_day_light_saving_timeP;
    if (msg_info->nw_day_light_saving_timeP)
    {
        srv_nitz_cntx->day_light_saving = msg_info->nw_day_light_saving_time & 0x03;
		MMI_NITZ_TRACE1(MMI_RTC_NITZ_RECV_TZ, srv_nitz_cntx->day_light_saving);
    }
    
    /* Check if time zone from NITZ is valid */
#endif /* __MMI_NITZ_TZ_SUPPORT__ */

	kal_get_time(&srv_nitz_cntx->recv_tick_count);

}


/*****************************************************************************
 * FUNCTION
 *  srv_nitz_convert_time
 * DESCRIPTION
 *  This function is to convert message time
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_nitz_convert_time(U8 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmp1, tmp2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp1 = time & NITZ_HIGH_BIT;
    tmp1 = tmp1 >> 4;
    tmp2 = time & NITZ_LOW_BIT;
    return tmp2 * 10 + tmp1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nitz_convert_timezone
 * DESCRIPTION
 *  This function is to convert message time zone
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
static S16 srv_nitz_convert_timezone(U8 t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tmp;
    U32 NegFlag;
    S32 result;
    U8 timezone = t;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp = (t & NITZ_HIGH_BIT) >> 4;
	
    if (t & NITZ_SIGN_BIT)  /* negative */
    {
        NegFlag = TRUE;
    }
    else    /* positive */
    {
        NegFlag = FALSE;
    }
	
    timezone &= NITZ_TZ_BIT;
    timezone = timezone * 10 + tmp;
	
    result = (S16) timezone;
	
    if (NegFlag)
    {
        result = 0 - result;
    }
	
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nitz_get_nw_name
 * DESCRIPTION
 *  This function is used to get NITZ network name.
 * PARAMETERS
 *  dcs         [IN]        
 *  len         [IN]        
 *  add_ci      [IN]        
 *  dstStr      [?]         
 *  srcStr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_nitz_get_nw_name(U8 dcs, U8 len, CHAR *dstStr, CHAR *srcStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *nwStr = NULL, *tmpStr, *tempStr2;
    U32 count = 0;
    U16 nwStrLen;
	U32 srcStr_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (dcs)
    {
        case SMSAL_DEFAULT_DCS:
            srcStr_len = strlen(srcStr);
            if (srcStr_len < MAX_NW_LEN)
            {
                nwStr = (U8*)CovertStringForPlatform((U8*)srcStr, (U16)srcStr_len, (U8)SMSAL_DEFAULT_DCS, (U16*)&nwStrLen);
            }
            else
            {
                return 0;
            }
            break;
        case SMSAL_UCS2_DCS:
            srcStr_len = mmi_ucs2strlen(srcStr);
            if (srcStr_len < MAX_NW_LEN)
            {
				nwStr = OslMalloc(MAX_NW_LEN * ENCODING_LENGTH);
				mmi_ucs2cpy((CHAR*)nwStr, (CHAR*)srcStr);
            }
            else
            {
                return 0;
            }
            break;
        default:
			return 0;
    }

    /* compare PLMN name */
    tmpStr = (U8*)dstStr;
    tempStr2 = nwStr;
    while (count < MAX_NW_LEN)
    {
        count++;
        if ((*tmpStr == *tempStr2) && (*(tmpStr + 1) == *(tempStr2 + 1)))
        {
            tmpStr += 2;
            tempStr2 += 2;
        }
        else
        {
            break;
        }
    }   /* End of while */

    if (count < MAX_NW_LEN)
    {
        mmi_ucs2cpy((CHAR*)dstStr, (CHAR*)nwStr);
        OslMfree(nwStr);
        return MMI_TRUE;
    }
    else
    {
        OslMfree(nwStr);
        return MMI_FALSE;
    }

}

/* NITZ MMI functions Start */
/*****************************************************************************
 * FUNCTION
 *  srv_init_nitz
 * DESCRIPTION
 *  This function is init function of NITZ
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nitz_init(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SetProtocolEventHandler(srv_nitz_msg_ind, MSG_ID_MMI_NW_TIME_ZONE_IND);
    // Set the status to idle to avoid the update is ignored.
    
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[NITZ] srv_nitz_init()");
	srv_set_nitz_state(SRV_NITZ_IDLE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_nitz_get_current_nw_name
 * DESCRIPTION
 *  Get the current network name 
 * PARAMETERS
 *  sim             [IN]    which SIM the network name need to get
 *  plmn_buf        [OUT]   PLMN output buffer
 *  nw_name_buf     [OUT]   network name output buffer
 *  nw_name_buf_len [IN]    network name output buffer length
 *  add_ci          [OUT]   ADD CI
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nitz_get_current_nw_name(mmi_sim_enum sim, CHAR* plmn_buf, WCHAR* nw_name_buf, U8 nw_name_buf_len, MMI_BOOL* add_ci)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	U32 sim_idx;
	nitz_nw_name_struct srv_nitz_current_op_name; 
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(sim < MMI_SIM_END_OF_ENUM);
	sim_idx = mmi_frm_sim_to_index(sim);
	memset(&srv_nitz_current_op_name, 0x00, sizeof(nitz_nw_name_struct));
	ReadRecordSlim(NVRAM_EF_NITZ_NW_NAME_LID, 1 + sim_idx, &srv_nitz_current_op_name, sizeof(nitz_nw_name_struct));
    if (plmn_buf != NULL)
    {
	    memcpy(plmn_buf, &srv_nitz_current_op_name.plmn, MAX_PLMN_LEN);
    }
    if (nw_name_buf != NULL)
    {
		mmi_ucs2ncpy((CHAR*)nw_name_buf, (const CHAR*)srv_nitz_current_op_name.name, nw_name_buf_len);
    }
    if (add_ci != NULL)
    {
		memcpy(add_ci, &(srv_nitz_current_op_name.add_ci), sizeof(U8)); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_nitz_set_current_nw_name
 * DESCRIPTION
 *  Update current network name, should only be called by NITZ APP 
 * PARAMETERS
 *  sim     [IN]    which SIM to be updated
 *  data    [IN]    update data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nitz_set_current_nw_name(mmi_sim_enum sim, const nitz_nw_name_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//memcpy(&g_srv_nitz_current_op_name[mmi_frm_sim_to_index(sim)], data, sizeof(nitz_nw_name_struct));

    WriteRecordSlim(NVRAM_EF_NITZ_NW_NAME_LID, (mmi_frm_sim_to_index(sim) + 1), (void*)data, NVRAM_NITZ_NW_NAME_SIZE);    
}

void srv_nitz_get_nitz_nw_name(U8 sim_id, U8* plmn, U8* nwname, U8 len, BOOL* add_ci)
{
    srv_nitz_get_current_nw_name((mmi_sim_enum)sim_id, (CHAR*)plmn, (WCHAR*)nwname, len, add_ci);
} 

/*****************************************************************************
 * FUNCTION
 *  srv_nitz_update_callback
 * DESCRIPTION
 *  Call this callback when NITZ update is finished 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nitz_update_callback(srv_nitz_update_status_enum update_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[NITZ] srv_nitz_update_callback() update_status", update_status);
    srv_set_nitz_state(SRV_NITZ_IDLE);
    //memset(&g_srv_nitz_cntx, 0x00, sizeof(srv_nitz_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_nitz_enable_update
 * DESCRIPTION
 *  Set the NITZ update enable status, should be called when NITZ setting is 
 *  updated  and after boot up 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nitz_enable_update(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[NITZ] srv_nitz_enable_update() is_enable", is_enable);
    if (is_enable)
	{
        // Clear data when the update is finished
        srv_set_nitz_state(SRV_NITZ_IDLE);
	}
    else
	{
        srv_set_nitz_state(SRV_NITZ_STATE_OFF);
	}
}
//#endif /* __COSMOS_MMI_PACKAGE__ */

/*****************************************************************************
 * FUNCTION
 *  srv_set_apply_nitz_type
 * DESCRIPTION
 *  This function is to set NITZ status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_set_apply_nitz_type(srv_nitz_type_enum apply_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_NITZ_TRACE1(MMI_RTC_NITZ_SET_APPLY_TYPE, apply_type);
	if (apply_type < 3)
	{
		WriteValueSlim(NVRAM_SETTING_AUTOUPDATE_DT_TIME_STATUS, &apply_type, DS_BYTE);
	}

}


/*****************************************************************************
 * FUNCTION
 *  srv_get_apply_nitz_type
 * DESCRIPTION
 *  This function is to get NITZ apply type
 * PARAMETERS
 *  void     
 * RETURNS
 *  U8
 *****************************************************************************/
srv_nitz_type_enum srv_get_apply_nitz_type(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValueSlim(NVRAM_SETTING_AUTOUPDATE_DT_TIME_STATUS, &data, DS_BYTE);

	if (data > 2)
    {
        data = 0;	// TODO
        WriteValueSlim(NVRAM_SETTING_AUTOUPDATE_DT_TIME_STATUS, &data, DS_BYTE);
	}
	
	MMI_NITZ_TRACE1(MMI_RTC_NITZ_GET_APPLY_TYPE, data);
	return (srv_nitz_type_enum)data;
}

#endif /* __MMI_NITZ__ */

