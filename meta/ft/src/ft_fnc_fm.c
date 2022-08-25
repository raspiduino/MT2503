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
/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_fnc_fm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FM Radio functions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"

/*************************************************************************
* Include Statements for MAUI
 *************************************************************************/

#include "ft_msg.h"
#include "fctycomp_config.h"
#include "l1audio.h"
#include "ft_private.h"
#include "meta_customize.h"
#include "stack_config.h"
#include "fmr\fmr_rds_api.h"
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ft_fnc_fm.h"
extern kal_uint16   ft_gl_token;
extern kal_uint16   ft_gl_fm_token;
static kal_uint16   ft_fm_seek_scan_token;
static kal_bool     ft_fm_seek_scan_preset;

extern void FMGetScanTbl(uint16 *CH_TBL);
/*******************************************************************************
*
*  FM Radio functionality
*
*******************************************************************************/
kal_uint8  FT_Fm_SendCnf(const FT_FM_CNF  *cnf, peer_buff_struct *p_peer_buff) 
{
    ilm_struct  *ilm_ptr;
    FT_FM_CNF   *ptrCnfMsg;

    if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_FM_CNF))) ) {
        return 1;
    }

    // if ptrMsg != NULL
    ptrCnfMsg = (FT_FM_CNF *)ilm_ptr->local_para_ptr;

    // assign primitive id
    ptrCnfMsg->header.ft_msg_id = FT_FM_CNF_ID;

    // assign return structure
    ptrCnfMsg->type = cnf->type;
    ptrCnfMsg->result = cnf->result;
    ptrCnfMsg->status = cnf->status;

    // assign peer buffer
    if( NULL != p_peer_buff ) {
        ilm_ptr->peer_buff_ptr = p_peer_buff;
    }

    // FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr)
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
    return 0;
}

void FT_FM_SearchStation(FT_FM_REQ *req, FT_FM_CNF *cnf, kal_uint8 dir)
{
    kal_int16 CurFreq = req->cmd.m_rFreqRange.m_i2StartFreq;
    kal_int16 StopFreq = req->cmd.m_rFreqRange.m_i2StopFreq;
    kal_uint8 FindFlag = 0;
    if(dir ==1)  // find next station
    {
        if(CurFreq <= StopFreq)  // stop freq should >= start freq
        {
            while(CurFreq <= StopFreq)
            {
                if(FMR_ValidStop(CurFreq, 5, KAL_FALSE)==1)
                {
                    FindFlag = 1;
                    break;
                }
                CurFreq++;
            }
            if(FindFlag ==1)
            {
                cnf->result.m_rValidFreq.m_ucExit = 1;
                cnf->result.m_rValidFreq.m_i2ValidFreq = CurFreq;
            }
            else
            {
                cnf->result.m_rValidFreq.m_ucExit = 0;
                cnf->result.m_rValidFreq.m_i2ValidFreq = 0;
            }

            cnf->status = FT_CNF_OK;
        }
        else{
            cnf->result.m_rValidFreq.m_ucExit = 0;
            cnf->result.m_rValidFreq.m_i2ValidFreq = -1;
            cnf->status = FT_CNF_FAIL;
        }
    }
    else if(dir ==2)  // find prev station
    {
        if(CurFreq >= StopFreq)  // start freq should >= stop freq
        {
            while(CurFreq >= StopFreq)
            {
                if(FMR_ValidStop(CurFreq, 5, KAL_FALSE)==1)
                {
                    FindFlag = 1;
                    break;
                }
                CurFreq--;
            }
            if(FindFlag ==1)
            {
                cnf->result.m_rValidFreq.m_ucExit = 1;
                cnf->result.m_rValidFreq.m_i2ValidFreq = CurFreq;
            }
            else
            {
                cnf->result.m_rValidFreq.m_ucExit = 0;
                cnf->result.m_rValidFreq.m_i2ValidFreq = 0;
            }
            cnf->status = FT_CNF_OK;
        }
        else{
            cnf->result.m_rValidFreq.m_ucExit = 0;
            cnf->result.m_rValidFreq.m_i2ValidFreq = -1;
            cnf->status = FT_CNF_FAIL;
        }
    }
    else
    {
        cnf->status = FT_CNF_FAIL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  ft_fmr_rds_callback
 * DESCRIPTION
 *
 * For FMR RDS Event callback handling
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ft_fmr_rds_callback(RdsEvent event)
{
    FT_FM_CNF   cnf;
    peer_buff_struct      *peer_buff_ret = NULL;
    FM_RDS_CNF_T *rds_cnf;
    kal_uint16  pdu_length = 0;
    kal_uint8  rds_buf_size;

    // assign primitive id
    cnf.header.ft_msg_id = FT_FM_CNF_ID;

    // assign return structure
    cnf.type = FT_FM_OP_SET_RDS;
    cnf.status = FT_CNF_OK;

    // copy result to peer buffer
    if( NULL == (peer_buff_ret=construct_peer_buff(sizeof(FM_RDS_CNF_T), 0, 0, TD_CTRL)) )
    {
        ASSERT(0);
    }
    rds_cnf = (FM_RDS_CNF_T*) get_pdu_ptr( peer_buff_ret, &pdu_length );
    memset(rds_cnf, 0x0, sizeof(FM_RDS_CNF_T));
    switch(event)
    {
        case RDS_EVENT_FLAGS:
            rds_cnf->eventtype = RDS_EVENT_FLAGS;
            Custom_META_FMR_RDS_GetStatus(&rds_cnf->m_rRDS.m_rRDSStatus.m_eFlag, rds_cnf->m_rRDS.m_rRDSStatus.m_buffer);
            break;
        case RDS_EVENT_PI_CODE:
            rds_cnf->eventtype = RDS_EVENT_PI_CODE;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_PI_CODE, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_PTY_CODE:
            rds_cnf->eventtype = RDS_EVENT_PTY_CODE;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_PTY_CODE, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_PROGRAMNAME:
            rds_cnf->eventtype = RDS_EVENT_PROGRAMNAME;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_PROGRAMNAME, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_UTCDATETIME:
            rds_cnf->eventtype = RDS_EVENT_UTCDATETIME;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_UTCDATETIME, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_LOCDATETIME:
            rds_cnf->eventtype = RDS_EVENT_LOCDATETIME;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_LOCDATETIME, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_LAST_RADIOTEXT:
            rds_cnf->eventtype = RDS_EVENT_LAST_RADIOTEXT;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_LAST_RADIOTEXT, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_AF:
            rds_cnf->eventtype = RDS_EVENT_AF;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_AF, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_AF_LIST:
            rds_cnf->eventtype = RDS_EVENT_AF_LIST;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_AF_LIST, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_AFON_LIST:
            rds_cnf->eventtype = RDS_EVENT_AFON_LIST;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_AFON, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_TAON:
            rds_cnf->eventtype = RDS_EVENT_TAON;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_TAON, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_TAON_OFF:
            rds_cnf->eventtype = RDS_EVENT_TAON_OFF;
            Custom_META_FMR_RDS_GetInfo(RDS_CMD_TAON_OFF, rds_cnf->m_rRDS.m_rRDSInfo.m_buffer, &rds_buf_size);
            break;
        case RDS_EVENT_RDS_TIMER:
            Custom_META_FMR_RDS_BlerCheck(NULL);
            free_peer_buff(peer_buff_ret);
            return;
        default:
            free_peer_buff(peer_buff_ret);
            return;
    }
    Custom_META_FMR_RDS_INTR_OnOff(KAL_TRUE);
    ft_gl_token = ft_gl_fm_token;
    FT_Fm_SendCnf(&cnf,peer_buff_ret);
}


/*****************************************************************************
 * FUNCTION
 *  FT_FMR_Seek_Scan_Callback
 * DESCRIPTION
 *
 * For FMR Seek and Scan callback handling
 *
 * PARAMETERS
 *  wFreq Frequency
 *  wSignalLv Signal Level
 *  is_valid is the result valid
 * RETURNS
 *  void
 *****************************************************************************/

static void FT_FMR_Seek_Scan_Callback(kal_int16 wFreq, kal_uint8 wSignalLv, kal_bool is_valid)
{
    FT_FM_CNF cnf;
    peer_buff_struct      *peer_buff_ret = NULL;
    FM_AutoScan_CNF_T *autoscan_cnf;
    kal_uint16	pdu_length = 0;
    kal_mem_set(&cnf, '\0', sizeof(cnf));
    if(is_valid == true)
    {
        // the seek operation failed!
        cnf.status = FT_CNF_OK;
    }
    else
    {
        // the seek operation failed!
        cnf.status = FT_CNF_FAIL;
    }
    if(ft_fm_seek_scan_preset == true)
    {
        // scan
        cnf.type = FT_FM_OP_FM_AUTOSCAN;
        // copy result to peer buffer
        if( NULL == (peer_buff_ret=construct_peer_buff(sizeof(FM_AutoScan_CNF_T), 0, 0, TD_CTRL)) )
        {
            ASSERT(0);
        }
        autoscan_cnf = (FM_AutoScan_CNF_T*) get_pdu_ptr( peer_buff_ret, &pdu_length );
        FMR_GetScanTbl(autoscan_cnf->m_u2Bitmap);
    }
    else
    {
        // seek
        cnf.type = FT_FM_OP_HWSEEK;
        cnf.result.m_rHWSeek.m_i2EndFreq = wFreq;
    }
    // send the cnf
    ft_gl_token = ft_fm_seek_scan_token;
    FT_Fm_SendCnf(&cnf,peer_buff_ret);
}

void FT_Fm_Operation(ilm_struct *ptrMsg)
{
    FT_FM_REQ *p_req = (FT_FM_REQ *)ptrMsg->local_para_ptr;
    FT_FM_CNF cnf;
    FM_RDS_Group_Counter_CNF_T *rds_group_counter_cnf;
    FM_RDS_Block_CNF_T *rds_log_cnf;
    kal_uint16	pdu_length = 0;
    peer_buff_struct      *peer_buff_ret = NULL;

    kal_mem_set(&cnf, '\0', sizeof(cnf));
    cnf.type = p_req->type;
    cnf.status = FT_CNF_FAIL;
    // for MT6616
    peer_buff_ret = NULL;

    switch(p_req->type) 
    {
        case FT_FM_OP_READ_CHIP_ID:
            {
                cnf.result.m_rChipId.m_ucChipId = FMR_GetChipID();
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_POWER_ON:
            {
                FMR_PowerOn();
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_POWER_OFF:
            {
                FMR_PowerOff();
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_SET_MONO_STEREO_BLEND:
            {
                FMR_Radio_EngineerMode(p_req->cmd.m_rMonoStereoSettings.m_u2MonoOrStereo, 
                        p_req->cmd.m_rMonoStereoSettings.m_u2SblendOnOrOff,
                        p_req->cmd.m_rMonoStereoSettings.m_u4ItemValue);
                cnf.status = FT_CNF_OK;
                break;

            }
        case FT_FM_OP_SET_FREQ:
            {
                FMR_SetFreq(p_req->cmd.m_rCurFreq.m_i2CurFreq);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_GET_SIGNAL_VAL:
            {
                cnf.result.m_rSignalValue.m_ucSignalLevel = FMR_GetSignalLevel(p_req->cmd.m_rCurFreq.m_i2CurFreq);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_GET_IF_CNT:
            {
                cnf.result.m_rIfCnt.m_u2IfCnt = FMR_GetIFCount(p_req->cmd.m_rCurFreq.m_i2CurFreq);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_SEARCH_NEXT_STAT:
            {
                FT_FM_SearchStation(p_req,&cnf,1);
                break;
            }
        case FT_FM_OP_SEARCH_PREV_STAT:
            {
                FT_FM_SearchStation(p_req,&cnf,2);
                break;
            }
        case FT_FM_OP_SET_RSSI_THRESHOLD:
            {
                FMR_Radio_EngineerMode(2, 0, p_req->cmd.m_rRssiThreshold.m_u4RssiThreshold);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_SET_IF_CNT_DELTA:
            {
                FMR_Radio_EngineerMode(3, 0, p_req->cmd.m_rIfCntDelta.m_u4IfCntDelta);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_READ_ANY_BYTE:
            {
                cnf.result.m_rReadByte.m_u2ReadByte = FMR_ReadByte(p_req->cmd.m_rReadAddr.m_ucAddr);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_WRITE_ANY_BYTE:
            {
                FMR_WriteByte(p_req->cmd.m_rWriteByte.m_ucAddr, p_req->cmd.m_rWriteByte.m_u2WriteByte);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_SOFT_MUTE_ONOFF:
            {
                FMR_SoftMuteOnOff(p_req->cmd.m_rSoftMuteOnOff.m_bOnOff);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_SELECT_SOFT_MUTE_STAGE:
            {
                FMR_SoftMuteStage(p_req->cmd.m_rStage.m_ucStage);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_SELECT_STEREO_BLEND:
            {
                FMR_StereoBlendStage(p_req->cmd.m_rStage.m_ucStage);
                cnf.status = FT_CNF_OK;
                break;

            }
        case FT_FM_OP_GET_H_L_SIDE:
            {
                cnf.result.m_rHLSide.m_ucHighOrLow = FMR_Get_H_L_side(p_req->cmd.m_rCurFreq.m_i2CurFreq);
                cnf.status = FT_CNF_OK;
                break;
            }
        case FT_FM_OP_GET_STEREO_MONO:
            {   
                cnf.result.m_rStereoMono.m_ucStereoOrMono = FMR_Get_stereo_mono();
                cnf.status = FT_CNF_OK;
                break;
            }
        // for MT6616 new API begin
        case FT_FM_OP_SET_VOLUME:
            FMR_SetOutputVolume(p_req->cmd.m_rVolumeSetting.m_ucVolume, p_req->cmd.m_rVolumeSetting.m_cDigitalGainIndex);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_FM_AUTOSCAN:
            ft_fm_seek_scan_token = ft_gl_token;
            ft_fm_seek_scan_preset = true;
            // the scan will be indicated in fmr task's context using callback function
            FMR_HWSearch( FT_FMR_Seek_Scan_Callback, 875/*cur_freq*/, KAL_TRUE/* is_up */, 1/*space*/, KAL_TRUE/*preset*/);
            // 20100110
            FMR_PollHWSearch(NULL);
            return;
        case FT_FM_OP_HWSEEK:
            ft_fm_seek_scan_token = ft_gl_token;
            ft_fm_seek_scan_preset = false;
            if(p_req->cmd.m_rHWSeek.m_ucDirection == 1)
            {
                FMR_HWSearch( FT_FMR_Seek_Scan_Callback, p_req->cmd.m_rHWSeek.m_i2StartFreq/*cur_freq*/, KAL_TRUE/* is_up */, 1/*space*/, KAL_FALSE/*preset*/);
            }
            else
            {
                FMR_HWSearch( FT_FMR_Seek_Scan_Callback, p_req->cmd.m_rHWSeek.m_i2StartFreq/*cur_freq*/, KAL_FALSE/* is_up */, 1/*space*/, KAL_FALSE/*preset*/);
            }
            // 20100110
            FMR_PollHWSearch(NULL);
            return;
        case FT_FM_OP_GET_RXFILTER_BW:
            cnf.result.m_rRXFilterBW.m_ucRXFilterBW = FMR_GetRXFilterBW();
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_GET_PAMD_LEVEL:
            cnf.result.m_rPAMDLevel.m_ucPAMDLevel = FMR_PamdLevel(p_req->cmd.m_rCurFreq.m_i2CurFreq);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_GET_MR:
            cnf.result.m_rMR.m_ucMR = FMR_GetMagRatio();
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_DECODE_MODE:
            FMR_Radio_EngineerMode(0, p_req->cmd.m_rDecodeMode.m_u4DecodeMode, 0/* don't care*/);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_HCC:
            FMR_Radio_EngineerMode(3, p_req->cmd.m_rHCC.m_u4HCC, 0/* don't care*/);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_PAMD_THRESHOLD:
            FMR_Radio_EngineerMode(4, 0/*don't care*/, p_req->cmd.m_rPAMDThreshold.m_u4PAMDThreshold);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_SOFTMUTE:
            FMR_Radio_EngineerMode(5, p_req->cmd.m_rSoftmuteEnable.m_u4SoftmuteEnable, 0/* don't care*/);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_DEEMPHASIS_LEVEL:
            FMR_Radio_EngineerMode(6, p_req->cmd.m_rDeemphasisLevel.m_u4DeemphasisLevel, 0/* don't care*/);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_H_L_SIDE:
            FMR_Radio_EngineerMode(7, p_req->cmd.m_rHLSide.m_u4HLSide, 0/* don't care*/);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_DEMOD_BW:
            FMR_Radio_EngineerMode(8, p_req->cmd.m_rDemodeBandwidth.m_u4DemodBandwidth, 0/* don't care*/);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_DYNAMIC_LIMITER:
            FMR_Radio_EngineerMode(9, p_req->cmd.m_rDynamicLimiter.m_u4DynamicLimiter, 0/* don't care*/);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_SOFTMUTE_RATE:
            FMR_Radio_EngineerMode(10, 0/* don't care*/, p_req->cmd.m_rSoftmuteRate.m_u4SoftmuteRate);
            cnf.status = FT_CNF_OK;
            break;

        case FT_FM_OP_HWSEARCH_STOP:
            FMR_HWSearchForceStop();
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_STEREO_BLEND:
            FMR_Radio_EngineerMode(1, p_req->cmd.m_rStereoBlendControl.m_u2StereoBlendControl, 0/* don't care*/);
            cnf.status = FT_CNF_OK;
            break;
        // for MT6616 new API end
        // RDS use custom function
        case FT_FM_OP_SET_RDS:
            ft_gl_fm_token = ft_gl_token;
            Custom_META_FMR_RDS_OnOff(p_req->cmd.m_rSetRDS.m_ucRDSOn == 1? true : false);
            if(p_req->cmd.m_rSetRDS.m_ucRDSOn == 1)
            {
                Custom_META_FMR_RDS_Open(ft_fmr_rds_callback);
            }
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_GET_GOOD_BLOCK_COUNTER:
            cnf.result.m_rRDSGoodBlockCounter.m_u2GoodBlock = Custom_META_FMR_RDS_Get_GoodBlock_Counter();
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_GET_BAD_BLOCK_COUNTER:
            cnf.result.m_rRDSBadBlockCounter.m_u2BadBlock = Custom_META_FMR_RDS_Get_BadBlock_Counter();
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_RESET_BLOCK_COUNTER:
            Custom_META_FMR_RDS_Reset_Block_Counter();
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_GET_GROUP_COUNTER:
            // copy result to peer buffer
            if( NULL == (peer_buff_ret=construct_peer_buff(sizeof(FM_RDS_Group_Counter_CNF_T), 0, 0, TD_CTRL)) )
            {
                ASSERT(0);
            }
            rds_group_counter_cnf =(FM_RDS_Group_Counter_CNF_T*)get_pdu_ptr( peer_buff_ret, &pdu_length );
            Custom_META_FMR_RDS_Read_Group_Counter(rds_group_counter_cnf->m_u2GroupCounter);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_RESET_GROUP_COUNTER:
            Custom_META_FMR_RDS_Reset_Group_Counter();
            cnf.status = FT_CNF_OK;
            break;
        // 20100208 new feature (sync FM stand-alone tool)
        case FT_FM_OP_GET_RDS_LOG:
        {
            kal_uint16 block_value[8];
            // copy result to peer buffer
            if( NULL == (peer_buff_ret=construct_peer_buff(sizeof(FM_RDS_Block_CNF_T), 0, 0, TD_CTRL)) )
            {
                ASSERT(0);
            }
            rds_log_cnf =(FM_RDS_Block_CNF_T*)get_pdu_ptr( peer_buff_ret, &pdu_length );
            Custom_META_FMR_RDS_Get_Block_Value(block_value);
            kal_mem_cpy(rds_log_cnf->m_u2Blocks, block_value, sizeof(kal_uint16)*5);
            cnf.status = FT_CNF_OK;
            break;
        }
        case FT_FM_OP_GET_RDS_BLER:
            cnf.result.m_u2RDSBLERRatio = Custom_META_FMR_RDS_Get_BadBlock_Ratio();
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_GET_ANTENNA_TYPE:
            cnf.result.m_i1AntennaType = FMR_GetAntennaType();
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_SET_ANTENNA_TYPE:
            FMR_SetAntennaType(p_req->cmd.m_i1AntennaType);
            cnf.status = FT_CNF_OK;
            break;
        case FT_FM_OP_QUERY_CAP_ARRAY:
            cnf.result.m_u4CapArray = FMR_GetCapArray();
            cnf.status = FT_CNF_OK;
            break;            
        default:
            break;
    }

    // send the cnf
    FT_Fm_SendCnf(&cnf,peer_buff_ret);

}
