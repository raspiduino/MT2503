/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
*
* Filename:
* ---------
*  CallLogSrvPsAdp.c
*
* Project:
* --------
*  MAUI
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "mmi_include.h"

#include "string.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "app_datetime.h"

#include "custom_voip_config.h"
#include "custom_phb_config.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

#include "mcd_l4_common.h"
#include "l4c_aux_struct.h"
#include "mcd_l4_common.h"
#include "l4c2uem_struct.h"
#include "l4c2abm_struct.h"

#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "GSM7BitDefaultAlphabet.h"


#include "PhbSrvGprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvConfig.h"
#include "CallLogSrvUtils.h"
#include "CallLogSrvProt.h"


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define SRV_CLOG_INTER_NUM_CHAR                      '+'
#define SRV_CLOG_UCS2_81_HEAD_SIZE                   (3)
#define SRV_CLOG_L4NAME_MAX_SIZE                     (MAX_PS_NAME_SIZE)

#define SRV_CLOG_PS_U8_INVALID_VALUE                 ((U8)~0)
#define SRV_CLOG_PS_U32_INVALID_VALUE                ((U32)~0)

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static const U8 g_srv_clog_l4_clt_tbl[] = {PHB_LND, PHB_LNM, PHB_LNR, PHB_LNR};
static const U8 g_srv_clog_l4_ct_tbl[] = {PHB_LN_CALL, PHB_LN_VIDEO, PHB_LN_VOIP};

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
static void srv_clog_num_cid2l4c(const CHAR *cid, l4c_number_struct *tel);
static void srv_clog_num_l4c2cid(const l4c_number_struct *tel, CHAR *cid);
static srv_clog_call_type_idx_enum srv_clog_cid_l4c2clog(const l4c_phb_ln_entry_struct *ln, CHAR *cid);
static void srv_clog_cid_clog2l4c(const CHAR *cid, srv_clog_call_type_idx_enum ct_idx, l4c_phb_ln_entry_struct *ln);
static void srv_clog_name_clog2l4c(const WCHAR *name, l4_name_struct *alpha_id);
static void srv_clog_name_l4c2clog(const l4_name_struct *alpha_id, WCHAR *name);
static void srv_clog_time_utc2rtc(U32 timestamp, rtc_format_struct *rtc_time);
static U32 srv_clog_time_rtc2utc(const rtc_format_struct *rtc_time);
static l4c_phb_ln_entry_struct *srv_clog_check_ln(const l4c_phb_ln_entry_struct *ln, S32 *is_new);
static l4c_phb_ln_entry_struct *srv_clog_revise_ln(l4c_phb_ln_entry_struct *ln);
static S32 srv_clog_is_ln_need_revise(const l4c_phb_ln_entry_struct *ln);
static S32 srv_clog_is_ps_str_invalid(CHAR *string, U32 len);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CLOG_PS_FIELDS


/*****************************************************************************
 * FUNCTION
 *  srv_clog_clt_idx2l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  clt_idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_clog_clt_idx2l4c(srv_clog_clt_idx_enum clt_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clt_idx >= sizeof(g_srv_clog_l4_clt_tbl) / sizeof(U8))
        return PHB_LN_NONE;
    return g_srv_clog_l4_clt_tbl[clt_idx];
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_clt_bit2l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  clt_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_clog_clt_bit2l4c(srv_clog_clt_enum clt_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 clt_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CLOG_BIT2IDX(clt_type, clt_idx);
    return srv_clog_clt_idx2l4c((srv_clog_clt_idx_enum)clt_idx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_clt_l4c2idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4c_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_clt_idx_enum srv_clog_clt_l4c2idx(U8 l4c_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_srv_clog_l4_clt_tbl) / sizeof(U8); i++)
    {
        if (l4c_type == g_srv_clog_l4_clt_tbl[i])
            return (srv_clog_clt_idx_enum)i;
    }
    SRV_CLOG_ASSERT(0);
    return SRV_CLOG_CLT_IDX_DIALED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_clt_l4c2bit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4c_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_clt_enum srv_clog_clt_l4c2bit(U8 l4c_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_clt_idx_enum clt_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clt_idx = srv_clog_clt_l4c2idx(l4c_type);
    return (srv_clog_clt_enum)SRV_CLOG_IDX2BIT(clt_idx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ct_idx2l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ct_idx      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_clog_ct_idx2l4c(srv_clog_call_type_idx_enum ct_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ct_idx >= sizeof(g_srv_clog_l4_ct_tbl) / sizeof(U8))
        ct_idx = SRV_CLOG_CALL_TYPE_IDX_VOICE;
    return g_srv_clog_l4_ct_tbl[ct_idx];
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ct_l4c2idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4_ct       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_call_type_idx_enum srv_clog_ct_l4c2idx(U32 l4_ct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(g_srv_clog_l4_ct_tbl) / sizeof(U8); i++)
    {
        if (l4_ct == g_srv_clog_l4_ct_tbl[i])
            return (srv_clog_call_type_idx_enum)i;
    }
    SRV_CLOG_ASSERT(0);
    return SRV_CLOG_CALL_TYPE_IDX_VOICE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ret_clog2l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret         [IN]        
 *  l4ret       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_ret_clog2l4c(srv_clog_ret_enum ret, l4c_result_struct *l4ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ret)
    {
        case SRV_CLOG_RET_OK:
            l4ret->flag = L4C_OK;
            l4ret->cause = 0;
            break;

        case SRV_CLOG_RET_NOT_FOUND:
            l4ret->flag = L4C_ERROR;
            l4ret->cause = PHB_ERRNO_READ_EMPTY;
            break;

        default:
            l4ret->flag = L4C_ERROR;
            l4ret->cause = 0;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_ret_l4c2clog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4ret       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_clog_ret_enum srv_clog_ret_l4c2clog(const l4c_result_struct *l4ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_ret_enum ret = SRV_CLOG_RET_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (l4ret->flag == MMI_TRUE)
        return SRV_CLOG_RET_OK;

    switch (l4ret->cause)
    {
        default:
            break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_num_cid2l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cid     [IN]        
 *  tel     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_num_cid2l4c(const CHAR *cid, l4c_number_struct *tel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const CHAR *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cid[0] == 0)
    {
        tel->type = PHB_NORMAL_NUM;
        tel->number[0] = '\0';
        tel->length = 0;
    }
    else
    {
        if (cid[0] == SRV_CLOG_INTER_NUM_CHAR)
        {
            tel->type = PHB_INTER_NUM;
            p = cid + 1;
        }
        else
        {
            tel->type = PHB_NORMAL_NUM;
            p = cid;
        }
     //   tel->length = srv_clog_strncpy((CHAR*) tel->number, MAX_CC_ADDR_LEN - 1, p);
     strncpy((CHAR*)tel->number, p, MAX_CC_ADDR_LEN - 1);
     tel->number[MAX_CC_ADDR_LEN - 1] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_num_l4c2cid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tel     [IN]        
 *  cid     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_num_l4c2cid(const l4c_number_struct *tel, CHAR *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *p = cid;
    U32 len = SRV_CLOG_CID_MAX_LEN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_INTER_NUM(tel->type))
    {
        cid[0] = SRV_CLOG_INTER_NUM_CHAR;
        p = cid + 1;
        len -= 1;
    }
    strncpy(p, (const CHAR*)tel->number, len);
    p[len] = 0;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cid_l4c2clog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ln      [IN]        
 *  cid     [?]         
 * RETURNS
 *  
 *****************************************************************************/
static srv_clog_call_type_idx_enum srv_clog_cid_l4c2clog(const l4c_phb_ln_entry_struct *ln, CHAR *cid)
{
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_call_type_idx_enum ct_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ct_idx = srv_clog_ct_l4c2idx(ln->address_type);
    if (ct_idx == SRV_CLOG_CALL_TYPE_IDX_VOIP)
    {
          strncpy(cid, (const CHAR*)ln->address.uri, SRV_CLOG_CID_MAX_LEN);
          cid[SRV_CLOG_CID_MAX_LEN] = 0;
    }
    else
        srv_clog_num_l4c2cid((const l4c_number_struct*)&ln->address.tel, (CHAR*) cid);
    return ct_idx;
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 

    srv_clog_num_l4c2cid((const l4c_number_struct*)&ln->tel, (CHAR*) cid);
    return SRV_CLOG_CALL_TYPE_IDX_VOICE;
#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_cid_clog2l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cid         [IN]        
 *  ct_idx      [IN]        
 *  ln          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_cid_clog2l4c(const CHAR *cid, srv_clog_call_type_idx_enum ct_idx, l4c_phb_ln_entry_struct *ln)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
    ln->address_type = (kal_uint8)srv_clog_ct_idx2l4c(ct_idx);
    if (ct_idx == SRV_CLOG_CALL_TYPE_IDX_VOIP)
    {
        strncpy((char*)ln->address.uri, cid, VOIP_URI_LEN - 1);
        ln->address.uri[VOIP_URI_LEN - 1] = 0;
    }

    else
        srv_clog_num_cid2l4c(cid, &ln->address.tel);

#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 

    srv_clog_num_cid2l4c(cid, &ln->tel);

#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 

}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_name_clog2l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  name            [IN]        
 *  alpha_id        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_name_clog2l4c(const WCHAR *name, l4_name_struct *alpha_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tmp_len;
    WCHAR tmp_name[SRV_CLOG_NAME_MAX_LEN + 1]; /* Not >512 indeed */
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name[0] == '\0')
    {
        alpha_id->name[0] = '\0';
        alpha_id->name_dcs = PHB_ASCII;
        alpha_id->name_length = 0;
        return;
    }

    mmi_wcsncpy((WCHAR*) tmp_name, (const WCHAR*)name, SRV_CLOG_NAME_MAX_LEN);

    if (srv_phb_check_ucs2_character((U16*) tmp_name))
    {
    #if defined(__PHB_0x81_SUPPORT__)       /* Support maximum length of 0x81 UCS2 */
        if ((tmp_len = srv_phb_convert_to_0x81((U16*) tmp_name, MMI_TRUE)) > 0)
        {
            /* To sync with PHB/L4C/L4PHB, the name_length should include SRV_CLOG_UCS2_81_HEAD_SIZE. */
            alpha_id->name_dcs = PHB_UCS2_81;
            alpha_id->name_length =
                ((tmp_len < SRV_CLOG_L4NAME_MAX_SIZE) ? tmp_len : SRV_CLOG_L4NAME_MAX_SIZE) /* - SRV_CLOG_UCS2_81_HEAD_SIZE */ ;
            tmp_name[1] = alpha_id->name_length;
            memcpy(alpha_id->name, tmp_name, alpha_id->name_length + SRV_CLOG_UCS2_81_HEAD_SIZE);
        }
        else
    #endif /* defined(__PHB_0x81_SUPPORT__) */ 
        {

            alpha_id->name_dcs = PHB_UCS2;
            alpha_id->name_length = InputboxConvertDeviceEncodingToGSM(
                                        (U8*) tmp_name,
                                        alpha_id->name,
                                        SRV_CLOG_L4NAME_MAX_SIZE,
                                        PHB_UCS2,
                                        0,
                                        1);
            /* It's U8 type here */
            alpha_id->name[alpha_id->name_length] = '\0';
            alpha_id->name[alpha_id->name_length + 1] = '\0';
        }
    }
    else
    {
        alpha_id->name_dcs = PHB_ASCII;
        alpha_id->name_length = InputboxConvertDeviceEncodingToGSM(
                                    (U8*) tmp_name,
                                    alpha_id->name,
                                    SRV_CLOG_L4NAME_MAX_SIZE,
                                    PHB_ASCII,
                                    0,
                                    1) - 1;
        alpha_id->name[alpha_id->name_length] = '\0';
    }
    //SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_CTRL_BUF, tmp_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_name_l4c2clog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alpha_id        [IN]        
 *  name            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_name_l4c2clog(const l4_name_struct *alpha_id, WCHAR *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alpha_id->name_length == 0 || alpha_id->name[0] == 0xFF && alpha_id->name[1] == 0xFF)
    {
        name[0] = '\0';
    }
    else
    {
        InputboxConvertGSMToDeviceEncoding(
            (U8*) alpha_id->name,
            (U8*) name,
            alpha_id->name_length,
            (SRV_CLOG_NAME_MAX_LEN + 1) * ENCODING_LENGTH,
            alpha_id->name_dcs,
            0,
            1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_time_utc2rtc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timestamp       [IN]        
 *  rtc_time        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_clog_time_utc2rtc(U32 timestamp, rtc_format_struct *rtc_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 local_sec;
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_sec = applib_dt_sec_utc_to_local(timestamp);
    applib_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);

    rtc_time->rtc_year = (U8) ((time.nYear) - YEARFORMATE);
    rtc_time->rtc_mon = time.nMonth;
    rtc_time->rtc_day = time.nDay;
    rtc_time->rtc_hour = time.nHour;
    rtc_time->rtc_min = time.nMin;
    rtc_time->rtc_sec = time.nSec;
    rtc_time->rtc_wday = time.DayIndex;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_time_rtc2utc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rtc_time        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_clog_time_rtc2utc(const rtc_format_struct *rtc_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct mytime;
    static const rtc_format_struct zero_time = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!memcmp(rtc_time, &zero_time, sizeof(rtc_format_struct)))
        return 0;

    mytime.nYear = (rtc_time->rtc_year) + YEARFORMATE;
    mytime.nMonth = rtc_time->rtc_mon;
    mytime.nDay = rtc_time->rtc_day;
    mytime.nHour = rtc_time->rtc_hour;
    mytime.nMin = rtc_time->rtc_min;
    mytime.nSec = rtc_time->rtc_sec;
    mytime.DayIndex = rtc_time->rtc_wday;
    return applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&mytime, MMI_FALSE));
}

#define SRV_CLOG_PS_LOG


/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_si2l4c
 * DESCRIPTION
 *  
 * PARAMETERS
 *  si_log      [IN]        
 *  ln          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_log_si2l4c(const srv_clog_si_struct *si_log, l4c_phb_ln_entry_struct *ln)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 lt_idx;
    U32 ct_idx;
    U32 props;
    U32 unread_num;
    srv_clog_call_info_struct *call_info = (srv_clog_call_info_struct*) si_log;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!si_log && !ln)
        return;

    if (!si_log)
    {
        memset(ln, 0x0, sizeof(l4c_phb_ln_entry_struct));
        return;
    }
    props = SRV_CLOG_SI_GET_P(si_log);
    SRV_CLOG_ASSERT(SRV_CLOG_CATE_IDX_CALL == SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_CATE, SRV_CLOG_LSP_CATE_POS));

    lt_idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_CLT, SRV_CLOG_LSP_LT_POS);
    ct_idx = SRV_CLOG_PI_P2IDX(props, SRV_CLOG_LSP_CT, SRV_CLOG_LSP_ST_POS);

    srv_clog_cid_clog2l4c((const CHAR*)call_info->cid, (srv_clog_call_type_idx_enum)ct_idx, ln);

#ifdef __MMI_CLOG_SLIM__ //SlimName
    {
        WCHAR ucs_name[SRV_CLOG_NAME_MAX_LEN + 1];

#ifdef __MMI_CLOG_PHB_SYNC_SUPPORT__

        srv_phb_get_name_by_number_id(ucs_name, call_info->phb_id, SRV_CLOG_NAME_MAX_LEN);

#else /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

        WCHAR ucs_cid[SRV_CLOG_CID_MAX_LEN + 1];

        mmi_asc_n_to_wcs(ucs_cid,  (CHAR*)call_info->cid, SRV_CLOG_CID_MAX_LEN);
        srv_phb_get_name_by_number(ucs_cid,ucs_name, SRV_CLOG_NAME_MAX_LEN);
        
#endif /* __MMI_CLOG_PHB_SYNC_SUPPORT__ */

       srv_clog_name_clog2l4c((const WCHAR*)ucs_name, &ln->alpha_id);
    }
#else /* __MMI_CLOG_SLIM__ */

    srv_clog_name_clog2l4c((const WCHAR*)call_info->name, &ln->alpha_id);

#endif /* __MMI_CLOG_SLIM__ */

    srv_clog_time_utc2rtc(call_info->timestamp[SRV_CLOG_LASTEST_TIME_IDX], &ln->time);

    ln->count = call_info->total_num;
    if (lt_idx == SRV_CLOG_CLT_IDX_MISSED)
    {
        unread_num = SRV_CLOG_PI_GET_URNUM(props, call_info->unread_num);
        ln->call_status = (unread_num == 0 ? 0 : 1);
    }
    else
        ln->call_status = 0;

    ln->call_duration = call_info->duration[SRV_CLOG_LASTEST_TIME_IDX];
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_l4c2si
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ln              [IN]        
 *  sim_id          [IN]        
 *  clt             [IN]        
 *  new_log_id      [IN]        
 *  si_log          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_log_l4c2si(
        const l4c_phb_ln_entry_struct *ln,
        mmi_sim_enum sim_id,
        srv_clog_clt_enum clt,
        SRV_CLOG_ID new_log_id,
        srv_clog_si_struct *si_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 is_new;
    S32 is_unread;
    U32 ct_idx;
    U32 sim_idx;
    U32 clt_idx;
    srv_clog_call_info_struct *call_info = (srv_clog_call_info_struct*) si_log;
    l4c_phb_ln_entry_struct *revise_ln;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    revise_ln = srv_clog_check_ln(ln, &is_new);

    SRV_CLOG_SI_CLEAR_P(si_log);
    SRV_CLOG_SET_BIT(SRV_CLOG_SI_GET_P(si_log), SRV_CLOG_LSP_CATE_CALL);
    SRV_CLOG_BIT2IDX(sim_id, sim_idx);
    SRV_CLOG_PI_IDX2P(SRV_CLOG_SI_GET_P(si_log), sim_idx, SRV_CLOG_LSP_SIM_ID_POS);
    SRV_CLOG_BIT2IDX(clt, clt_idx);
    SRV_CLOG_PI_IDX2P(SRV_CLOG_SI_GET_P(si_log), clt_idx, SRV_CLOG_LSP_LT_POS);

    ct_idx = srv_clog_cid_l4c2clog((const l4c_phb_ln_entry_struct*)revise_ln, (CHAR*) call_info->cid);
    SRV_CLOG_PI_IDX2P(call_info->props, ct_idx, SRV_CLOG_LSP_ST_POS);

#ifndef __MMI_CLOG_SLIM__ //SlimName
    srv_clog_name_l4c2clog((const l4_name_struct*)&revise_ln->alpha_id, (WCHAR*) call_info->name);
#endif

    call_info->timestamp[SRV_CLOG_LASTEST_TIME_IDX] = srv_clog_time_rtc2utc((const rtc_format_struct*)&revise_ln->time);
    SRV_CLOG_PI_SET_DUR(call_info->props, call_info->duration[SRV_CLOG_LASTEST_TIME_IDX], revise_ln->call_duration);
    SRV_CLOG_PI_SET_TNUM(call_info->props, call_info->total_num, revise_ln->count > 0 ? revise_ln->count : 1);
    if (clt == SRV_CLOG_CLT_MISSED)
        is_unread = (revise_ln->call_status == 0 ? 0 : 1);
    else
        is_unread = 0;
    SRV_CLOG_PI_SET_URNUM(call_info->props, call_info->unread_num, is_unread);
    if (is_unread)
        SRV_CLOG_SET_BIT(call_info->props, SRV_CLOG_LSP_NEW_EVENT);
    else
        SRV_CLOG_CLEAR_BIT(call_info->props, SRV_CLOG_LSP_NEW_EVENT);
    if (is_new)
        SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, revise_ln);
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_log_l4c2cmn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ln              [IN]        
 *  sim_id          [IN]        
 *  clt_type        [IN]        
 *  cmn_log         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_clog_log_l4c2cmn(
        const l4c_phb_ln_entry_struct *ln,
        mmi_sim_enum sim_id,
        srv_clog_clt_enum clt_type,
        srv_clog_log_struct *cmn_log)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 is_new;
    srv_clog_call_log_struct *cmn_call;
    CHAR cid[SRV_CLOG_CID_MAX_LEN + 1]; /* enough to use local variable */
    l4c_phb_ln_entry_struct *revise_ln;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    revise_ln = srv_clog_check_ln(ln, &is_new);

    cmn_log->cate = SRV_CLOG_LSP_CATE_CALL;

    cmn_call = &cmn_log->data.call_log;
    cmn_call->cate = SRV_CLOG_CATE_CALL;
    cmn_call->sim_id = sim_id;
    cmn_call->log_type = clt_type;
    cmn_call->sub_type = SRV_CLOG_CALL_TYPE_VOICE;
    cmn_call->log_id = SRV_CLOG_INVALID_ELM;
    SRV_CLOG_SET_INVALID_PHB_ID(cmn_call->phb_id);
    cmn_call->timestamp[SRV_CLOG_LASTEST_TIME_IDX] = srv_clog_time_rtc2utc((const rtc_format_struct*)&revise_ln->time);
    cmn_call->duration[SRV_CLOG_LASTEST_TIME_IDX] = revise_ln->call_duration;
    cmn_call->total_num = revise_ln->count;
    if (cmn_call->total_num == 0)
        cmn_call->total_num = 1;
    if (clt_type == SRV_CLOG_CLT_MISSED)
    {
        cmn_call->unread_num = (revise_ln->call_status == 0 ? 0 : 1);
        cmn_call->is_new_event = (revise_ln->call_status == 0 ? 0 : 1);
    }
    else
    {
        cmn_call->unread_num = 0;
        cmn_call->is_new_event = 0;
    }
    cmn_call->is_private_cid = MMI_FALSE;
    srv_clog_cid_l4c2clog((const l4c_phb_ln_entry_struct*)revise_ln, (CHAR*) cid);
    mmi_asc_to_wcs((WCHAR*) cmn_call->cid, (CHAR*) cid);
    srv_clog_name_l4c2clog((const l4_name_struct*)&revise_ln->alpha_id, (WCHAR*) cmn_call->name);
    if (is_new)
        SRV_CLOG_MFREE(SRV_CLOG_MEM_TYPE_TEMP, revise_ln);
}

#define SRV_CLOG_PS_LN


/*****************************************************************************
 * FUNCTION
 *  srv_clog_check_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ln              [IN]        
 *  is_new          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static l4c_phb_ln_entry_struct *srv_clog_check_ln(const l4c_phb_ln_entry_struct *ln, S32 *is_new)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    l4c_phb_ln_entry_struct *revise_ln;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_clog_is_ln_need_revise(ln);
    if (!ret)
    {
        *is_new = MMI_FALSE;
        return (l4c_phb_ln_entry_struct*) ln;
    }
    revise_ln = SRV_CLOG_TALLOC(SRV_CLOG_MEM_TYPE_TEMP, l4c_phb_ln_entry_struct);
    memcpy(revise_ln, ln, sizeof(l4c_phb_ln_entry_struct));
    srv_clog_revise_ln(revise_ln);
    *is_new = MMI_TRUE;
    return revise_ln;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_revise_ln
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ln              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static l4c_phb_ln_entry_struct *srv_clog_revise_ln(l4c_phb_ln_entry_struct *ln)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
    if (ln->address_type == SRV_CLOG_PS_U8_INVALID_VALUE)
        ln->address_type = PHB_LN_CALL;

    if (ln->address_type == PHB_LN_VOIP)
    {
        if (srv_clog_is_ps_str_invalid((CHAR*) ln->address.uri, VOIP_URI_LEN))
            SRV_CLOG_SET_STR_EMPTY(ln->address.uri);
    }
    else
    {
        if (ln->address.tel.type == SRV_CLOG_PS_U8_INVALID_VALUE)
            ln->address.tel.type = PHB_NORMAL_NUM;

        if (ln->address.tel.length == SRV_CLOG_PS_U8_INVALID_VALUE ||
            srv_clog_is_ps_str_invalid((CHAR*) ln->address.tel.number, MAX_CC_ADDR_LEN))
        {
            ln->address.tel.length = 0;
            SRV_CLOG_SET_STR_EMPTY(ln->address.tel.number);
        }
    }

#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 

    if (ln->tel.type == SRV_CLOG_PS_U8_INVALID_VALUE)
        ln->tel.type = PHB_NORMAL_NUM;
    if (ln->tel.length == SRV_CLOG_PS_U8_INVALID_VALUE ||
        srv_clog_is_ps_str_invalid((CHAR*) ln->tel.number, MAX_CC_ADDR_LEN))
    {
        ln->tel.length = 0;
        SRV_CLOG_SET_STR_EMPTY(ln->tel.number);
    }
#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 

    if (ln->alpha_id.name_length == SRV_CLOG_PS_U8_INVALID_VALUE ||
        ln->alpha_id.name_dcs == SRV_CLOG_PS_U8_INVALID_VALUE ||
        srv_clog_is_ps_str_invalid((CHAR*) ln->alpha_id.name, SRV_CLOG_L4NAME_MAX_SIZE))
    {
        ln->alpha_id.name_length = 0;
        ln->alpha_id.name_dcs = PHB_ASCII;
        SRV_CLOG_SET_STR_EMPTY(ln->alpha_id.name);
    }
    if (srv_clog_is_ps_str_invalid((CHAR*) & ln->time, sizeof(rtc_format_struct)))
        memset(&ln->time, 0x0, sizeof(rtc_format_struct));

    if (ln->count == SRV_CLOG_PS_U8_INVALID_VALUE)
        ln->count = 1;
    if (ln->call_status == SRV_CLOG_PS_U8_INVALID_VALUE)
        ln->call_status = 0;
    if (ln->call_duration == SRV_CLOG_PS_U32_INVALID_VALUE)
        ln->call_duration = 0;

    return ln;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_ln_need_revise
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ln              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_clog_is_ln_need_revise(const l4c_phb_ln_entry_struct *ln)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)
    if (ln->address_type == SRV_CLOG_PS_U8_INVALID_VALUE)
        return MMI_TRUE;
    if (ln->address_type == PHB_LN_VOIP)
    {
        if (srv_clog_is_ps_str_invalid((CHAR*) ln->address.uri, VOIP_URI_LEN))
            return MMI_TRUE;
    }
    else
    {
        if (ln->address.tel.type == SRV_CLOG_PS_U8_INVALID_VALUE ||
            ln->address.tel.length == SRV_CLOG_PS_U8_INVALID_VALUE ||
            srv_clog_is_ps_str_invalid((CHAR*) ln->address.tel.number, MAX_CC_ADDR_LEN))
        {
            return MMI_TRUE;
        }
    }
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 
    if (ln->tel.type == SRV_CLOG_PS_U8_INVALID_VALUE ||
        ln->tel.length == SRV_CLOG_PS_U8_INVALID_VALUE ||
        srv_clog_is_ps_str_invalid((CHAR*) ln->tel.number, MAX_CC_ADDR_LEN))
    {
        return MMI_TRUE;
    }
#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 

    if (ln->alpha_id.name_length == SRV_CLOG_PS_U8_INVALID_VALUE ||
        ln->alpha_id.name_dcs == SRV_CLOG_PS_U8_INVALID_VALUE ||
        srv_clog_is_ps_str_invalid((CHAR*) ln->alpha_id.name, SRV_CLOG_L4NAME_MAX_SIZE))
    {
        return MMI_TRUE;
    }
    if (srv_clog_is_ps_str_invalid((CHAR*) & ln->time, sizeof(rtc_format_struct)))
        return MMI_TRUE;

    if (ln->count == SRV_CLOG_PS_U8_INVALID_VALUE ||
        ln->call_status == SRV_CLOG_PS_U8_INVALID_VALUE || ln->call_duration == SRV_CLOG_PS_U32_INVALID_VALUE)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_ln_invalid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ln              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_clog_is_ln_invalid(const l4c_phb_ln_entry_struct *ln)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    CHAR *cid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__)

    /*
     * if (ln->address_type != SRV_CLOG_PS_U8_INVALID_VALUE)
     * return MMI_TRUE;
     */

    if (ln->address_type == PHB_LN_VOIP)
    {
        len = VOIP_URI_LEN;
        cid = (CHAR*) ln->address.uri;
        if (!srv_clog_is_ps_str_invalid(cid, VOIP_URI_LEN))
        {
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_IS_LN_INVALID,
                1,
                ln->address_type,
                -1,
                -1,
                ln->alpha_id.name_length,
                ln->alpha_id.name_dcs);
            return MMI_FALSE;
        }
    }
    else
    {
        len = MAX_CC_ADDR_LEN;
        cid = (CHAR*) ln->address.tel.number;
        if (!(ln->address.tel.type == SRV_CLOG_PS_U8_INVALID_VALUE ||
              ln->address.tel.length == SRV_CLOG_PS_U8_INVALID_VALUE ||
              srv_clog_is_ps_str_invalid(cid, MAX_CC_ADDR_LEN)))
        {
            MMI_TRACE(
                SRV_CLOG_TRC_INFO,
                TRC_SRV_CLOG_IS_LN_INVALID,
                2,
                ln->address_type,
                ln->address.tel.type,
                ln->address.tel.length,
                ln->alpha_id.name_length,
                ln->alpha_id.name_dcs);
            return MMI_FALSE;
        }
    }
#else /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 

    len = MAX_CC_ADDR_LEN;
    cid = (CHAR*) ln->tel.number;
    if (!(ln->tel.type == SRV_CLOG_PS_U8_INVALID_VALUE ||
          ln->tel.length == SRV_CLOG_PS_U8_INVALID_VALUE || srv_clog_is_ps_str_invalid(cid, MAX_CC_ADDR_LEN)))
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_IS_LN_INVALID,
            3,
            0,
            ln->tel.type,
            ln->tel.length,
            ln->alpha_id.name_length,
            ln->alpha_id.name_dcs);
        return FALSE;
    }

#endif /* defined(__MMI_VOIP__) || defined(__MMI_VIDEO_TELEPHONY__) */ 

    /* To skip invalid record without name and number */
    if (SRV_CLOG_IS_STR_EMPTY(cid) && SRV_CLOG_IS_STR_EMPTY(ln->alpha_id.name))
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_IS_LN_INVALID,
            4,
            -1,
            -1,
            -1,
            ln->alpha_id.name_length,
            ln->alpha_id.name_dcs);
        return MMI_TRUE;
    }
    if (srv_clog_is_ps_str_invalid(cid, len) &&
        srv_clog_is_ps_str_invalid((CHAR*) ln->alpha_id.name, SRV_CLOG_L4NAME_MAX_SIZE))
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_IS_LN_INVALID,
            5,
            -1,
            -1,
            -1,
            ln->alpha_id.name_length,
            ln->alpha_id.name_dcs);
        return MMI_TRUE;
    }

    if (!(ln->alpha_id.name_length == SRV_CLOG_PS_U8_INVALID_VALUE ||
          ln->alpha_id.name_dcs == SRV_CLOG_PS_U8_INVALID_VALUE ||
          srv_clog_is_ps_str_invalid((CHAR*) ln->alpha_id.name, SRV_CLOG_L4NAME_MAX_SIZE)))
    {
        MMI_TRACE(
            SRV_CLOG_TRC_INFO,
            TRC_SRV_CLOG_IS_LN_INVALID,
            6,
            -1,
            -1,
            -1,
            ln->alpha_id.name_length,
            ln->alpha_id.name_dcs);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_clog_is_ps_str_invalid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [?]         
 *  len             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_clog_is_ps_str_invalid(CHAR *string, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    CHAR *p = string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!p || len == 0)
        return MMI_FALSE;

    for (i = 0; i < len; i++)
    {
        if (*p != SRV_CLOG_PS_U8_INVALID_VALUE)
            return MMI_FALSE;
        p++;
    }
    return MMI_TRUE;
}

