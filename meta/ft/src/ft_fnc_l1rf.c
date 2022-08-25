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
 *   ft_fnc_l1rf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Factory testing function for GSM/GPRS/EDGE
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
#include "task_config.h"
#include "stack_ltlcom.h"
#include "reg_base.h"
#include "l1_kal.h"
/*************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_l1rf.h"
#include "l1tst_public.h"

typedef union
{
    RfTestResultDTS    dts_result;
    RfTestResultDTS_Ex dts_result_ex;
    RfTestResultDTSBig dts_result_big;
    RfTestResultDTS_Big_Ex dts_result_big_ex;
}_DTSReport_U;
_DTSReport_U *g_rdtsPtr = NULL;
kal_bool g_FHC_DTS_waiting = KAL_FALSE;
kal_uint16 FdtType;
void FT_L1RfDataInit(void)
{
    ft_rfDATA.wait_cnf = KAL_FALSE;
    ft_rfDATA.result_ready= KAL_FALSE;
#if  IS_FHC_SUPPORT == 1
    ft_rfDATA.pDTSBuf = NULL;  // for FDT
    ft_rfDATA.pUTSBuf = NULL;
#endif
}
static void ft_construct_rf_confirm_message(ilm_struct **ilm_ptr, kal_uint16 local_message_size,
        ft_rf_test_cnf_T** ptrMsg,
        kal_uint16 msg_id, kal_uint16 type,
        kal_uint16 peer_pdu_size,
        const void * in_pdu_ptr);
/*******************************************************************************
 *  L1 runtime setting API (Start)
 *******************************************************************************/
void setPathLossTableToL1D(peer_buff_struct* peer_buff_ptr,l1cal_agcPathLoss_T *l1cal_agcPathLoss_ft)
{
    l1cal_agcPathLoss_T    *agc;
    kal_int8               i;
    kal_uint16             pdu_length;
    if(l1cal_agcPathLoss_ft==NULL)
    {
        agc = (l1cal_agcPathLoss_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        agc = l1cal_agcPathLoss_ft;
    }

    for ( i=0; i<FrequencyBandCount; i++)
    {
        L1D_RF_SetPathLossTable( i,  agc->agcPathLoss[i] );
    }
}

void setRampTableToL1D(FrequencyBand band, peer_buff_struct* peer_buff_ptr,l1cal_rampTable_T *l1cal_rampTable_ft)
{
    l1cal_rampTable_T *apc;
    kal_uint16        pdu_length;
    if(l1cal_rampTable_ft==NULL)
    {
        apc = (l1cal_rampTable_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        apc = l1cal_rampTable_ft;
    }
    L1D_RF_SetRampTable( band, &(apc->rampData) );
}

void setAFcDataToL1C(peer_buff_struct* peer_buff_ptr,l1cal_afcData_T *l1cal_afcData_ft)
{
    l1cal_afcData_T *afc;
    kal_uint16      pdu_length;
    if(l1cal_afcData_ft==NULL)
    {
        afc = (l1cal_afcData_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        afc = l1cal_afcData_ft;
    }
    L1TST_SetAfcDacValue(afc->dacValue);
    /*chliu modify: set the ini_dac and slope to L1D parameter then be used in 3G*/
    L1TST_SetAFcData(afc->dacValue, afc->slopeInv);
    /*For co-clock project, for example wifi co-clock, SA will test wifi TX before*/
    /*using GSM TX, so we need to initialize AFC DAC as calibrated value in meta mode*/
    L1D_RF_SetCrystalDac(afc->dacValue);
}

void TOL1_CALTXIQ(peer_buff_struct* peer_buff_ptr,l1cal_txiq_T *l1cal_txiq_ft)
{
    extern void L1D_RF_SetBBTXParameters(void* table);
    l1cal_txiq_T   *txiq;
    kal_uint16     pdu_length;
    if(l1cal_txiq_ft==NULL)
    {
        txiq = (l1cal_txiq_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        txiq = l1cal_txiq_ft;
    }
    L1D_RF_SetBBTXParameters(&(txiq->BBTXParameters));
}

int setInterRampTableToL1D(FrequencyBand  band, peer_buff_struct  *peer_buff_ptr, l1cal_interRampData_T  *inter_ramp_data) {

    kal_uint16  pdu_length = 0;
    l1cal_interRampData_T  *p = NULL;

    if( NULL != inter_ramp_data ) {
        p = inter_ramp_data;
    }
    else if( NULL != peer_buff_ptr ) {
        p = get_pdu_ptr( peer_buff_ptr, &pdu_length );
        if( 0 == pdu_length ) {
            return 1;
        }
    }
    else {
        return 2;
    }

    // Be careful! You must check L1D_RF_xxx() implementation in m12193.c first to ensure what pointer you should pass to L1D.
    L1D_RF_SetInterSlotRampTable( band, p->interRampData );
    return 0;
}

int setCrystalAfcDataToL1D(peer_buff_struct  *peer_buff_ptr, l1cal_crystalAfcData_T  *crystalAfcData) {

    kal_uint16  pdu_length = 0;
    l1cal_crystalAfcData_T  *p = NULL;

    if( NULL != crystalAfcData ) {
        p = crystalAfcData;
    }
    else if( NULL != peer_buff_ptr ) {
        p = get_pdu_ptr( peer_buff_ptr, &pdu_length );
        if( 0 == pdu_length ) {
            return 1;
        }
    }
    else {
        return 2;
    }

    // Be careful! You must check L1D_RF_xxx() implementation in m12193.c first to ensure what pointer you should pass to L1D.
    L1D_RF_SetCrystalAFCData( p->XO_SlopeAreaData );
    return 0;
}

int setCrystalCapDataToL1D(peer_buff_struct  *peer_buff_ptr, l1cal_crystalCapData_T  *crystalCapData) {

    kal_uint16  pdu_length = 0;
    l1cal_crystalCapData_T  *p = NULL;

    if( NULL != crystalCapData ) {
        p = crystalCapData;
    }
    else if( NULL != peer_buff_ptr ) {
        p = get_pdu_ptr( peer_buff_ptr, &pdu_length );
        if( 0 == pdu_length ) {
            return 1;
        }
    }
    else {
        return 2;
    }

    // Be careful! You must check L1D_RF_xxx() implementation in m12193.c first to ensure what pointer you should pass to L1D.
    L1D_RF_SetCrystalCap( p->cap_id );
    return 0;
}

#if defined(__EPSK_TX__)
void setEPSKRampTableToL1D(FrequencyBand band, peer_buff_struct* peer_buff_ptr,l1cal_rampTable_T *l1cal_rampTable_ft)
{
    l1cal_rampTable_T *apc;
    kal_uint16        pdu_length;
    if(l1cal_rampTable_ft==NULL)
    {
        apc = (l1cal_rampTable_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        apc = l1cal_rampTable_ft;
    }
    L1D_RF_SetRampTableEPSK( band, &(apc->rampData) );
}

void setEPSKInterRampTableToL1D(FrequencyBand band, peer_buff_struct* peer_buff_ptr, l1cal_EPSK_interRampData_T *l1cal_inter_rampTable_ft)
{
    l1cal_EPSK_interRampData_T *epsk_interramp;
    kal_uint16        pdu_length;
    if(l1cal_inter_rampTable_ft==NULL)
    {
        epsk_interramp = (l1cal_EPSK_interRampData_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        epsk_interramp = l1cal_inter_rampTable_ft;
    }
    L1D_RF_EPSK_SetInterSlotRampTable( band, 0, &(epsk_interramp->EPSK_interRampData[0]) );
    L1D_RF_EPSK_SetInterSlotRampTable( band, 1, &(epsk_interramp->EPSK_interRampData[1]) );
    L1D_RF_EPSK_SetInterSlotRampTable( band, 2, &(epsk_interramp->EPSK_interRampData[2]) );
    L1D_RF_EPSK_SetInterSlotRampTable( band, 3, &(epsk_interramp->EPSK_interRampData[3]) );
}
#endif // __EPSK_TX__
#if defined(__EGPRS_MODE__)
void setEPSKTXRollbackTableToL1D(peer_buff_struct* peer_buff_ptr, l1cal_tx_power_rollback_T *tx_rollback_epsk)
{
    l1cal_tx_power_rollback_T *tx_rollback_table;
    kal_uint16        pdu_length;
    if(tx_rollback_epsk==NULL)
    {
        tx_rollback_table = (l1cal_tx_power_rollback_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        tx_rollback_table = tx_rollback_epsk;
    }
    L1D_RF_SetTxPowerRollbackData_EPSK(FrequencyBand850, &(tx_rollback_table->rollback_data[FrequencyBand850]));
    L1D_RF_SetTxPowerRollbackData_EPSK(FrequencyBand900, &(tx_rollback_table->rollback_data[FrequencyBand900]));
    L1D_RF_SetTxPowerRollbackData_EPSK(FrequencyBand1800, &(tx_rollback_table->rollback_data[FrequencyBand1800]));
    L1D_RF_SetTxPowerRollbackData_EPSK(FrequencyBand1900, &(tx_rollback_table->rollback_data[FrequencyBand1900]));
}
#endif // __EGPRS_MODE__

#if defined(__PS_SERVICE__)
void setGMSKTXRollbackTableToL1D(peer_buff_struct* peer_buff_ptr, l1cal_tx_power_rollback_T *tx_rollback_epsk)
{
    l1cal_tx_power_rollback_T *tx_rollback_table;
    kal_uint16        pdu_length;
    if(tx_rollback_epsk==NULL)
    {
        tx_rollback_table = (l1cal_tx_power_rollback_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        tx_rollback_table = tx_rollback_epsk;
    }
    L1D_RF_SetTxPowerRollbackData(FrequencyBand850, &(tx_rollback_table->rollback_data[FrequencyBand850]));
    L1D_RF_SetTxPowerRollbackData(FrequencyBand900, &(tx_rollback_table->rollback_data[FrequencyBand900]));
    L1D_RF_SetTxPowerRollbackData(FrequencyBand1800, &(tx_rollback_table->rollback_data[FrequencyBand1800]));
    L1D_RF_SetTxPowerRollbackData(FrequencyBand1900, &(tx_rollback_table->rollback_data[FrequencyBand1900]));
}
#endif // __PS_SERVICE__
void setRFSpecialCoefToL1D(peer_buff_struct* peer_buff_ptr, l1cal_rfspecialcoef_T *l1cal_rfspecialcoef_ft)
{
    l1cal_rfspecialcoef_T *rfspeccoef;
    kal_uint16        pdu_length;
    if(l1cal_rfspecialcoef_ft==NULL)
    {
        rfspeccoef = (l1cal_rfspecialcoef_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        rfspeccoef = l1cal_rfspecialcoef_ft;
    }
    L1D_RF_SetRFSpecialCoef( &(rfspeccoef->RFSpecialCoef) );
}
void setTXPCToL1D(peer_buff_struct* peer_buff_ptr, l1cal_txpc_T *txpc_table_input, kal_bool b_epsk)
{
#if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
    l1cal_txpc_T *txpc_table;
    kal_uint16   pdu_length;
    if(txpc_table_input==NULL)
    {
        txpc_table = (l1cal_txpc_T *)get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        txpc_table = txpc_table_input;
    }
    L1D_RF_TXPC_SET_CAL( (sTXPC_L1CAL*)txpc_table, (b_epsk == KAL_TRUE) ? 1 /*EPSK*/ : 0 /*GMSK*/ );
#endif // #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
}
void setLnaPathLossToL1D(peer_buff_struct* peer_buff_ptr, void *input)
{
#if defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)
    void *lna_table;
    kal_uint16   pdu_length;
    if(input==NULL)
    {
        lna_table = get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        lna_table = input;
    }
    L1D_RF_SetLnaPathLossTable(lna_table);
#endif // #if defined(__MULTI_LNA_MODE_CALIBRATION_SUPPORT__)
}
void setTemperatureADCToL1D(peer_buff_struct* peer_buff_ptr, void *temperature_adc_input)
{
#if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
#if !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)
    void *temperature_adc;
    kal_uint16   pdu_length;
    if(temperature_adc_input==NULL)
    {
        temperature_adc = get_pdu_ptr( peer_buff_ptr, &pdu_length );
    }
    else
    {
        temperature_adc = temperature_adc_input;
    }
    L1D_RF_TXPC_SET_TEMP_ADC(temperature_adc);
#endif // #if !defined(__UMTS_RAT__) || !defined(__MTK_UL1_FDD__)
#endif // #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
}
/*******************************************************************************
 *  L1 runtime setting API (End)
 *******************************************************************************/
/*******************************************************************************
 *
 *  Function Library Provided to RF Test
 *
 *******************************************************************************/
#ifdef __PS_SERVICE__
static int ft_rf_chk_mstx_ex_arg(kal_int8  timeSlotmask, Power  powerLev[4], CodingScheme  cs[4], TimingAdvance  ta, kal_int32  frames, APCTxPattern  pattern) {
    kal_int8    m;

    if( !( !( timeSlotmask & 0xf0 ) && ( timeSlotmask & 0x0f ) ) ||
            !( ( frames > 0 ) || ( frames == -99 ) ) ||
            !( ta <= 63 )
      ) {
        return 1;
    }

    for(m=0; m<4; m++) {
        if( timeSlotmask & ( 1 << m ) ) {
            if( !( (powerLev[m]>=0) && (powerLev[m]<=31) ) ) {
                return 2;
            }
            else {
                switch(cs[m]) {
                    case CodingSchemeCS1:
                    case CodingSchemeCS2:
                    case CodingSchemeCS3:
                    case CodingSchemeCS4:
                    case CodingSchemePRACh8:
                    case CodingSchemePRACh11:
#ifdef __EGPRS_MODE__
                    case CodingSchemeMCS1:
                    case CodingSchemeMCS2:
                    case CodingSchemeMCS3:
                    case CodingSchemeMCS4:
#endif // #ifdef __EGPRS_MODE__
#ifdef __EPSK_TX__
                    case CodingSchemeMCS5:
                    case CodingSchemeMCS6:
                    case CodingSchemeMCS7:
                    case CodingSchemeMCS8:
                    case CodingSchemeMCS9:
#endif // #ifdef __EPSK_TX__
                        break;
                    default:
                        return 3;
                }
            }
        }
    }

    switch(pattern) {
        case NB_TX_ALL_ZEROS_WITHOUT_TSC:
        case NB_TX_ALL_ONES_WITHOUT_TSC:
        case NB_TX_RANDOM_WITH_TSC:
        case NB_TX_PATTERN_WITHOUT_TSC:
#ifdef __EPSK_TX__
        case NB_TX_FIXED_RANDOM_WITH_TSC:
        case NB_TX_FIXED_ALL_ZEROS_WITH_TSC:
        case NB_TX_FIXED_ALTER_BITS_WITH_TSC:
        case NB_TX_FIXED_ALL_ONES_WITH_TSC:
        case NB_TX_FIXED_OE_PATTERN_WITH_TSC:
#endif // #ifdef __EPSK_TX__
            break;
        default:
            return 4;
    }
    return 0;
}
static int ft_rf_chk_multislot_tx_arg(kal_int8  timeSlotmask, Power  powerLev[4], CodingScheme  cs[4], TimingAdvance  ta, kal_int32  frames)
{
    return ft_rf_chk_mstx_ex_arg(timeSlotmask, powerLev, cs, ta, frames, NB_TX_ALL_ZEROS_WITHOUT_TSC /* dummy */);
}
#endif // #ifdef  __PS_SERVICE__

#ifdef __EGPRS_MODE__
static void ft_rf_translate_codingscheme_from_pc(const CodingScheme  cs_pc[4], CodingScheme  cs_target[4])
{
    kal_int32   i;
    const CodingScheme  CodingSchemeTranslateTable[]={
        // PC -> Target
        CodingSchemeNone
            ,CodingSchemeCS1
            ,CodingSchemeCS2
            ,CodingSchemeCS3
            ,CodingSchemeCS4
            ,CodingSchemePRACh8
            ,CodingSchemePRACh11
            ,CodingSchemeMCS1
            ,CodingSchemeMCS2
            ,CodingSchemeMCS3
            ,CodingSchemeMCS4
            ,CodingSchemeMCS5
            ,CodingSchemeMCS6
            ,CodingSchemeMCS7
            ,CodingSchemeMCS8
            ,CodingSchemeMCS9
    };
    for(i=0; i<4; i++) {
        cs_target[i] = CodingSchemeTranslateTable[cs_pc[i]];
    }
}
#endif // #ifdef __EGPRS_MODE__

static CodingScheme ft_rf_translate_codingscheme_from_pc_one_slot(const CodingScheme  cs_pc)
{
#ifdef __EGPRS_MODE__
    CodingScheme CodingScheme_pc[4];
    CodingScheme CodingScheme_target[4];
    kal_int32 i;
    for(i=0;i<4;i++)
    {
        CodingScheme_pc[i] = cs_pc;
    }
    ft_rf_translate_codingscheme_from_pc(CodingScheme_pc, CodingScheme_target);
    return CodingScheme_target[0];
#else // #ifdef __EGPRS_MODE__
    return cs_pc;
#endif
}


/*******************************************************************************
 * FUNCTION
 *   FT_FtRfTestReq
 *
 * DESCRIPTION
 *   For RF testing
 *   1. AGC calibration
 *   2. AFC calibration
 *   3. NB transmission
 *   4. Continuous receive
 *   5. Continuous transmit
 *
 * CALLS
 *   void L1TST_PowerScan(ARFCN arfcn, int8 sampleNoPerFrame,
 *                        Gain gain, int16 frames);
 *   void L1TST_FCBControl(ARFCN arfcn, int16 dacValue);
 *   void L1TST_NormalBurstTx(ARFCN  arfcn, BSIC bsic, int8 bitmask,
 *                            Power txPowerLev, int16 frames, APCTxPattern burstTypeNB);
 *   void L1TST_ContinuousTx(ARFCN arfcn, ContTxPattern pattern, bool onOff);
 *   void L1TST_ContinuousRx(ARFCN arfcn, bool onOff);
 *   void L1TST_SelectFrequencyBand1900( bool selected );
 *   void L1TST_Stop(void);
 *
 * PARAMETERS
 *   *req
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None
 *******************************************************************************/
kal_int8      g_i1_ft_2g_rf_power_state = FT_RF_PWR_STATE_UNKNOWN; // unknown

void FT_FtRfTestReq(ft_rf_test_req_T *req, peer_buff_struct *p_peer_buff_ptr)
{
    extern void L1D_SinWave_Detection( bool is_sin_wave );
    extern void L1D_CalibrateGainMismatch( void );
    ft_rf_test_cnf_T* ptrMsg;
    ilm_struct* ilm_ptr;

    switch (req->type)
    {
        case RF_TEST_CMD_PM:
#if IS_W_CANCELLATION_SUPPORT == 1
        case RF_TEST_CMD_IF_PM:
#endif // #if IS_W_CANCELLATION_SUPPORT == 1
        {
            // store rf token id, because PM command won't return immediately.
            ft_gl_rf_token = req->header.token;

            if(!L1TST_CheckAvailableARFCNs(req->param.pm.arfcn)) {
                ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
                ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
                ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
                ptrMsg->type = req->type;
                ptrMsg->param.pm.ok = KAL_FALSE;
                FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
                break;
            }
            ft_rfDATA.wait_cnf = KAL_TRUE;
            ft_rfDATA.type = req->type;
            if(req->type == RF_TEST_CMD_PM)
            {
                L1TST_PowerScan(req->param.pm.arfcn,
                        req->param.pm.sampleNoPerFrame,
                        req->param.pm.gain,
                        req->param.pm.frames);
            }
            else if(req->type == RF_TEST_CMD_IF_PM)
            {
#if IS_W_CANCELLATION_SUPPORT == 1
                // L1TST_IR_PowerScan shares the same report as the L1TST_PowerScan
                L1TST_IR_PowerScan(req->param.m_IrPm.m_Pm.arfcn,
                        req->param.m_IrPm.m_Pm.sampleNoPerFrame,
                        req->param.m_IrPm.m_Pm.gain,
                        req->param.m_IrPm.m_Pm.frames,
                        req->param.m_IrPm.m_IfFlag);
#endif // #if IS_W_CANCELLATION_SUPPORT == 1
            }
            break;
        }
        case RF_TEST_CMD_AFC:
        {
            // store rf token id, because AFC command won't return immediately.
            ft_gl_rf_token = req->header.token;
            if(!L1TST_CheckAvailableARFCNs(req->param.afc.arfcn)) {
                ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
                ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
                ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
                ptrMsg->type = req->type;
                ptrMsg->param.afc.ok = KAL_FALSE;
                FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            }
            else {

                ft_rfDATA.wait_cnf = KAL_TRUE;
                ft_rfDATA.type = req->type;

                ft_rfDATA.param.afc.fcb_ok_number=0;
                ft_rfDATA.param.afc.freqOffset=0;
                ft_rfDATA.param.afc.deviation=0;

                ft_rfDATA.afcCmd.arfcn             = req->param.afc.arfcn;
                ft_rfDATA.afcCmd.dacValue          = req->param.afc.dacValue;
                ft_rfDATA.afcCmd.gain              = req->param.afc.gain;
                ft_rfDATA.afcCmd.testNumber        = req->param.afc.testNumber;

                L1TST_FCBControl(ft_rfDATA.afcCmd.arfcn,
                        ft_rfDATA.afcCmd.dacValue,
                        ft_rfDATA.afcCmd.gain);

            }
            break;
        }
        case RF_TEST_CMD_NB_TX:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            if(!L1TST_CheckAvailableARFCNs(req->param.nbTx.arfcn)) {
                ptrMsg->param.ok = KAL_FALSE;
            }
            else {

                L1TST_NormalBurstTx(req->param.nbTx.arfcn,
                        req->param.nbTx.bsic,
                        req->param.nbTx.bitmask,
                        req->param.nbTx.txPowerLev,
                        req->param.nbTx.frames,
                        req->param.nbTx.dacValue,
                        req->param.nbTx.burstTypeNB);
                ptrMsg->param.ok = KAL_TRUE;

            }
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_CONTINUOUS_RX:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            if(!L1TST_CheckAvailableARFCNs(req->param.contRx.arfcn)) {
                ptrMsg->param.ok = KAL_FALSE;
            }
            else {

                L1TST_ContinuousRx(req->param.contRx.arfcn,
                        req->param.contRx.gain,
                        req->param.contRx.onOff);
                ptrMsg->param.ok = KAL_TRUE;

            }
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_CONTINUOUS_TX:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            if(!L1TST_CheckAvailableARFCNs(req->param.contTx.arfcn)) {
                ptrMsg->param.ok = KAL_FALSE;
            }
            else {

                L1TST_ContinuousTx(req->param.contTx.arfcn,
                        req->param.contTx.pattern,
                        0,
                        req->param.contTx.onOff,
                        0, /* modtype = GMSK */
                        10);

                ptrMsg->param.ok = KAL_TRUE;

            }
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_BB_TX_CFG:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            {
                sBBTXCfg  bbtx_cfg;

                // read current bbtx cfg
                L1TST_GetBBTXCfg(&bbtx_cfg);

                // assign only tx trim I&Q and offset I&Q
                bbtx_cfg.TxTrimI = req->param.setBBTXCfg.TxTrimI;
                bbtx_cfg.TxTrimQ = req->param.setBBTXCfg.TxTrimQ;
                bbtx_cfg.TxOffsetI = req->param.setBBTXCfg.TxOffsetI;
                bbtx_cfg.TxOffsetQ = req->param.setBBTXCfg.TxOffsetQ;

                // set to layer 1
                L1TST_SetBBTXCfg(&bbtx_cfg);
            }
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_BBTXCFG2:
        {
            sBBTXCfg  bbtx_cfg;

            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            // read current bbtx cfg
            L1TST_GetBBTXCfg(&bbtx_cfg);

            // assign
            bbtx_cfg.TxTrimI = req->param.BBTxCfg2.TxTrimI;
            bbtx_cfg.TxTrimQ = req->param.BBTxCfg2.TxTrimQ;
            bbtx_cfg.TxOffsetI = req->param.BBTxCfg2.TxOffsetI;
            bbtx_cfg.TxOffsetQ = req->param.BBTxCfg2.TxOffsetQ;
            bbtx_cfg.TxCalbias = req->param.BBTxCfg2.TxCalbias;
            bbtx_cfg.TxIQSwap = req->param.BBTxCfg2.TxIQSwap;
            bbtx_cfg.TxCMV = req->param.BBTxCfg2.TxCMV;
            bbtx_cfg.TxGain = req->param.BBTxCfg2.TxGain;
            bbtx_cfg.TxCalrcsel = req->param.BBTxCfg2.TxCalrcsel;

            // set to layer 1
            L1TST_SetBBTXCfg(&bbtx_cfg);
            // read from layer 1

            L1TST_GetBBTXCfg(&bbtx_cfg);
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxTrimI = bbtx_cfg.TxTrimI;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxTrimQ = bbtx_cfg.TxTrimQ;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxOffsetI = bbtx_cfg.TxOffsetI;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxOffsetQ = bbtx_cfg.TxOffsetQ;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxCalbias = bbtx_cfg.TxCalbias;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxIQSwap = bbtx_cfg.TxIQSwap;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxCMV = bbtx_cfg.TxCMV;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxGain = bbtx_cfg.TxGain;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxCalrcsel = bbtx_cfg.TxCalrcsel;

            ptrMsg->param.BBTxCfg2.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_BBTXCFG2:
        {
            sBBTXCfg bbtx_cfg;

            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            L1TST_GetBBTXCfg(&bbtx_cfg);

            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxTrimI = bbtx_cfg.TxTrimI;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxTrimQ = bbtx_cfg.TxTrimQ;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxOffsetI = bbtx_cfg.TxOffsetI;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxOffsetQ = bbtx_cfg.TxOffsetQ;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxCalbias = bbtx_cfg.TxCalbias;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxIQSwap = bbtx_cfg.TxIQSwap;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxCMV = bbtx_cfg.TxCMV;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxGain = bbtx_cfg.TxGain;
            ptrMsg->param.BBTxCfg2.bbtx_cfg.TxCalrcsel = bbtx_cfg.TxCalrcsel;
            ptrMsg->param.BBTxCfg2.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_BAND_SEL:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            L1TST_SelectFrequencyBand1900( req->param.selectPCS1900 );
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_STOP:
        {
            L1TST_Stop();
            if(ft_rfDATA.wait_cnf != KAL_FALSE)
            {
                ft_rfDATA.wait_cnf = KAL_FALSE;
            }
#if  IS_FHC_SUPPORT == 1
            if(ft_rfDATA.pDTSBuf != NULL)  // for FDT
            {
                free_ctrl_buffer(ft_rfDATA.pDTSBuf);
                ft_rfDATA.pDTSBuf = NULL;
            }
            if(ft_rfDATA.pUTSBuf != NULL)  // for FDT
            {
                free_ctrl_buffer(ft_rfDATA.pUTSBuf);
                ft_rfDATA.pUTSBuf = NULL;
            }
#endif // #if  IS_FHC_SUPPORT == 1

            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_MULTISLOT_TX:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
#ifdef  __PS_SERVICE__

#ifdef  __EGPRS_MODE__
            // translate CodingScheme from pc side
            ft_rf_translate_codingscheme_from_pc(req->param.msTx.cs, req->param.msTx.cs);
#endif // #ifdef  __EGPRS_MODE__

            if(!ft_rf_chk_multislot_tx_arg(req->param.msTx.timeSlotmask, req->param.msTx.powerLev, req->param.msTx.cs, req->param.msTx.ta, req->param.msTx.frames)) {

                if(!L1TST_CheckAvailableARFCNs(req->param.msTx.arfcn)) {
                    ptrMsg->param.ok = KAL_FALSE;
                }
                else {

                    // traditional multislot tx interface, fixed APCTxPattern to NB_TX_RANDOM_WITH_TSC
                    L1TST_MultiSlotTx(   req->param.msTx.arfcn,
                            req->param.msTx.bsic,
                            req->param.msTx.timeSlotmask,
                            req->param.msTx.powerLev,
                            req->param.msTx.cs,
                            req->param.msTx.ta,
                            req->param.msTx.frames,
                            req->param.msTx.dacValue,
#ifdef __EGPRS_MODE__
                            KAL_TRUE,
#else // #ifdef __EGPRS_MODE__
                            KAL_FALSE,
#endif // #ifndef __EGPRS_MODE__
                            NB_TX_RANDOM_WITH_TSC,
                            0);

                    ptrMsg->param.ok = KAL_TRUE;

                }
            }
            else
#endif // #ifdef  __PS_SERVICE__
            {
                ptrMsg->param.ok = KAL_FALSE;
            }
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_RAMPAPCLVL:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            if(!L1TST_CheckAvailableBands((FrequencyBand)req->param.setRampApcLevel.rf_band)) {
                ptrMsg->param.ok = KAL_FALSE;
            }
            else {

                L1TST_RF_SetRampApcLevel(req->param.setRampApcLevel.rf_band, req->param.setRampApcLevel.power_level, req->param.setRampApcLevel.apc_dac );
                ptrMsg->param.ok = KAL_TRUE;

            }

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_AFCDACVALUE:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            L1TST_SetAfcDacValue(req->param.setAfcDacValue.dacValue);
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_CRYSTAL_CFG:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            L1D_RF_SetCrystalCap(req->param.setCrystalCfg.cap_id);
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_BBTX_AUTOCAL:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            // TX gain calibration
            L1D_CalibrateGainMismatch();
            // sleep to wait for L1D calibration done
            kal_sleep_task(500);
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_RAMPTABLE:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            setRampTableToL1D((FrequencyBand)req->param.setRampTable.rf_band, p_peer_buff_ptr, NULL);
            ptrMsg->param.ok = KAL_TRUE;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#if defined(__EPSK_TX__)
        case RF_TEST_CMD_EPSK_SET_RAMPTABLE:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            setEPSKRampTableToL1D((FrequencyBand)req->param.setRampTable.rf_band, p_peer_buff_ptr, NULL);
            ptrMsg->param.ok = KAL_TRUE;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // #if defined(__EPSK_TX__)
        case RF_TEST_CMD_SET_AFC_SINWAVE_DETECTION:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            L1D_SinWave_Detection(req->param.setAfcSinWave.is_sinwave);
            ptrMsg->param.ok = KAL_TRUE;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_IF_TWO_APC_DC_OFFSET_SUPPORT:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            ptrMsg->param.ok = KAL_TRUE;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_RFID:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            ptrMsg->param.rfid.id = (kal_uint32)L1D_RF_GetID();
            ptrMsg->param.rfid.ok = KAL_TRUE;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_IMMEDIATE_BSI:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            L1D_RF_SetImmediateBSI(req->param.SetBSI.bsi_data);

            ptrMsg->param.ok = KAL_TRUE;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_IMMEDIATE_BSI:
        {
            unsigned long bsi_data;
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            L1D_RF_GetImmediateBSI(req->param.GetBSI.bsi_addr, &bsi_data);
            ptrMsg->param.GetBSI.bsi_data = bsi_data;

            ptrMsg->param.ok = KAL_TRUE;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_SPECIALCOEF:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            setRFSpecialCoefToL1D(p_peer_buff_ptr, NULL);
            ptrMsg->param.ok = KAL_TRUE;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_MULTISLOT_TX_EX:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
#ifdef  __EGPRS_MODE__
            // translate CodingScheme from pc side
            ft_rf_translate_codingscheme_from_pc(req->param.msTxEx.cs, req->param.msTxEx.cs);
            // check argument
            if(!ft_rf_chk_mstx_ex_arg(req->param.msTxEx.timeSlotmask, req->param.msTxEx.powerLev, req->param.msTxEx.cs, req->param.msTxEx.ta, req->param.msTxEx.frames, req->param.msTxEx.pattern)) {

                if(!L1TST_CheckAvailableARFCNs(req->param.msTxEx.arfcn)) {
                    ptrMsg->param.ok = KAL_FALSE;
                }
                else {

                    L1TST_MultiSlotTx(   req->param.msTxEx.arfcn,
                            req->param.msTxEx.bsic,
                            req->param.msTxEx.timeSlotmask,
                            req->param.msTxEx.powerLev,
                            req->param.msTxEx.cs,
                            req->param.msTxEx.ta,
                            req->param.msTxEx.frames,
                            req->param.msTxEx.dacValue,
                            KAL_TRUE,
                            req->param.msTxEx.pattern,
                            req->param.msTxEx.pattern_data);

                    ptrMsg->param.ok = KAL_TRUE;

                }
            }
            else
#endif // #ifdef  __EGPRS_MODE__
            {
                ptrMsg->param.ok = KAL_FALSE;
            }
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_EPSK_SET_RAMPAPCLVL:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            if(!L1TST_CheckAvailableBands((FrequencyBand)req->param.setRampApcLevel.rf_band)) {
                ptrMsg->param.ok = KAL_FALSE;
            }
            else {

#if defined(__EPSK_TX__)
                L1TST_RF_SetRampApcLevelEPSK(req->param.setRampApcLevel.rf_band, req->param.setRampApcLevel.power_level, req->param.setRampApcLevel.apc_dac );
                ptrMsg->param.ok = KAL_TRUE;
#else // #if defined(__EPSK_TX__)
                ptrMsg->param.ok = KAL_FALSE;
#endif // #if !defined(__EPSK_TX__)
            }

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_CONTINUOUS_TX_EX:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            if(!L1TST_CheckAvailableARFCNs(req->param.contTxEx.arfcn)) {
                ptrMsg->param.ok = KAL_FALSE;
            }
            else {

                L1TST_ContinuousTx(req->param.contTxEx.arfcn,
                        req->param.contTxEx.pattern,
                        req->param.contTxEx.pattern_data,
                        req->param.contTxEx.onOff,
                        req->param.contTxEx.modtype,
                        10);

                ptrMsg->param.ok = KAL_TRUE;

            }
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_BBTXCFG3:
        {
            sBBTXCfg  bbtx_cfg;

            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;


            // read current bbtx cfg
            L1TST_GetBBTXCfg(&bbtx_cfg);

            bbtx_cfg.TxTrimI = req->param.BBTxCfg3.TxTrimI;
            bbtx_cfg.TxTrimQ = req->param.BBTxCfg3.TxTrimQ;
            bbtx_cfg.TxOffsetI = req->param.BBTxCfg3.TxOffsetI;
            bbtx_cfg.TxOffsetQ = req->param.BBTxCfg3.TxOffsetQ;
            bbtx_cfg.TxCalbias = req->param.BBTxCfg3.TxCalbias;
            bbtx_cfg.TxIQSwap = req->param.BBTxCfg3.TxIQSwap;
            bbtx_cfg.TxCMV = req->param.BBTxCfg3.TxCMV;
            bbtx_cfg.TxGain = req->param.BBTxCfg3.TxGain;
            bbtx_cfg.TxCalrcsel = req->param.BBTxCfg3.TxCalrcsel;
            bbtx_cfg.TxPhasesel = req->param.BBTxCfg3.TxPhasesel;

            // set to layer 1
            L1TST_SetBBTXCfg(&bbtx_cfg);

            // read from layer 1
            L1TST_GetBBTXCfg(&bbtx_cfg);
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxTrimI = bbtx_cfg.TxTrimI ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxTrimQ = bbtx_cfg.TxTrimQ ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxOffsetI = bbtx_cfg.TxOffsetI ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxOffsetQ = bbtx_cfg.TxOffsetQ ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxCalbias = bbtx_cfg.TxCalbias ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxIQSwap = bbtx_cfg.TxIQSwap ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxCMV = bbtx_cfg.TxCMV ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxGain = bbtx_cfg.TxGain ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxCalrcsel = bbtx_cfg.TxCalrcsel ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxPhasesel = bbtx_cfg.TxPhasesel ;
            ptrMsg->param.BBTxCfg3.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_BBTXCFG3:
        {
            sBBTXCfg  bbtx_cfg;
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            L1TST_GetBBTXCfg(&bbtx_cfg);
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxTrimI = bbtx_cfg.TxTrimI ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxTrimQ = bbtx_cfg.TxTrimQ ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxOffsetI = bbtx_cfg.TxOffsetI ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxOffsetQ = bbtx_cfg.TxOffsetQ ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxCalbias = bbtx_cfg.TxCalbias ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxIQSwap = bbtx_cfg.TxIQSwap ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxCMV = bbtx_cfg.TxCMV ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxGain = bbtx_cfg.TxGain ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxCalrcsel = bbtx_cfg.TxCalrcsel ;
            ptrMsg->param.BBTxCfg3.bbtx_cfg.TxPhasesel = bbtx_cfg.TxPhasesel ;
            ptrMsg->param.BBTxCfg3.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_CONTINUOUS_TX_EX2:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            if(!L1TST_CheckAvailableARFCNs(req->param.contTxEx2.arfcn)) {
                ptrMsg->param.ok = KAL_FALSE;
            }
            else {

                L1TST_ContinuousTx(req->param.contTxEx2.arfcn,
                        req->param.contTxEx2.pattern,
                        req->param.contTxEx2.pattern_data,
                        req->param.contTxEx2.onOff,
                        req->param.contTxEx2.modtype,
                        req->param.contTxEx2.powerLev);

                ptrMsg->param.ok = KAL_TRUE;

            }

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_QUERY_MS_CAPABILITY_EX2:
        {
            MsCapabilityEx   msc;
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            // reset to all zero
            kal_mem_set(&(ptrMsg->param.ms_capability_ex), 0, sizeof(ptrMsg->param.ms_capability_ex));

            L1TST_MsCapability(&msc);
            ptrMsg->param.ms_capability_ex.ok = KAL_TRUE;
            ptrMsg->param.ms_capability_ex.capability = msc.capability;
            ptrMsg->param.ms_capability_ex.band_support = msc.band_support;

            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_AFCDACVALUE_AT_RTX_OFFSET_CAL:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            ptrMsg->param.GetAfcDacValueAtRTXOffsetCal.dacValue = L1TST_GetAfcDacValueAtTRXOffsetCalibration();
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_BBTXCFG4:
        case RF_TEST_CMD_SET_BBTXCFG5:
        case RF_TEST_CMD_SET_BBTXCFG6:
        {
            sBBTXCfg bbtx_cfg;

            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            // read current bbtx cfg
            L1TST_GetBBTXCfg(&bbtx_cfg);
            // set to layer 1
            bbtx_cfg.TxTrimI = req->param.BBTxCfg4.TxTrimI;
            bbtx_cfg.TxTrimQ = req->param.BBTxCfg4.TxTrimQ;
            bbtx_cfg.TxOffsetI = req->param.BBTxCfg4.TxOffsetI;
            bbtx_cfg.TxOffsetQ = req->param.BBTxCfg4.TxOffsetQ;
            bbtx_cfg.TxCalbias = req->param.BBTxCfg4.TxCalbias;
            bbtx_cfg.TxIQSwap = req->param.BBTxCfg4.TxIQSwap;
            bbtx_cfg.TxCMV = req->param.BBTxCfg4.TxCMV;
            bbtx_cfg.TxGain = req->param.BBTxCfg4.TxGain;
            bbtx_cfg.TxCalrcsel = req->param.BBTxCfg4.TxCalrcsel;
            bbtx_cfg.TxPhasesel = req->param.BBTxCfg4.TxPhasesel;
            bbtx_cfg.TxDccoarseI = req->param.BBTxCfg4.TxCoarseI;
            bbtx_cfg.TxDccoarseQ = req->param.BBTxCfg4.TxCoarseQ;

            L1TST_SetBBTXCfg(&bbtx_cfg);
            // read from layer 1
            L1TST_GetBBTXCfg(&bbtx_cfg);

            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxTrimI = bbtx_cfg.TxTrimI ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxTrimQ = bbtx_cfg.TxTrimQ ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxOffsetI = bbtx_cfg.TxOffsetI ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxOffsetQ = bbtx_cfg.TxOffsetQ ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCalbias = bbtx_cfg.TxCalbias ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxIQSwap = bbtx_cfg.TxIQSwap ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCMV = bbtx_cfg.TxCMV ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxGain = bbtx_cfg.TxGain ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCalrcsel = bbtx_cfg.TxCalrcsel ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxPhasesel = bbtx_cfg.TxPhasesel ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCoarseI = bbtx_cfg.TxDccoarseI ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCoarseQ = bbtx_cfg.TxDccoarseQ ;

            ptrMsg->param.BBTxCfg4.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_BBTXCFG4:
        case RF_TEST_CMD_GET_BBTXCFG5:
        case RF_TEST_CMD_GET_BBTXCFG6:
        {
            sBBTXCfg bbtx_cfg;
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            L1TST_GetBBTXCfg(&bbtx_cfg);

            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxTrimI = bbtx_cfg.TxTrimI ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxTrimQ = bbtx_cfg.TxTrimQ ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxOffsetI = bbtx_cfg.TxOffsetI ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxOffsetQ = bbtx_cfg.TxOffsetQ ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCalbias = bbtx_cfg.TxCalbias ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxIQSwap = bbtx_cfg.TxIQSwap ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCMV = bbtx_cfg.TxCMV ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxGain = bbtx_cfg.TxGain ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCalrcsel = bbtx_cfg.TxCalrcsel ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxPhasesel = bbtx_cfg.TxPhasesel ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCoarseI = bbtx_cfg.TxDccoarseI ;
            ptrMsg->param.BBTxCfg4.bbtx_cfg.TxCoarseQ = bbtx_cfg.TxDccoarseQ ;
            ptrMsg->param.BBTxCfg4.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_CALIBRATE_32K:
        {
            RfTestCmdType oriType = ft_rfDATA.type;
            ft_gl_rf_token = req->header.token;
            ft_rfDATA.wait_cnf = KAL_TRUE;

            ft_rfDATA.type = req->type;
            if(!L1TST_Begin32KCalibration(Meta_32KCalibrationHandler)) // previous calibration does not finish
            {
                ft_rfDATA.wait_cnf = KAL_FALSE;
                ft_rfDATA.type = oriType;

                ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
                ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
                /* if ptrMsg != NULL*/
                ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
                ptrMsg->type = req->type;
                ptrMsg->param.calibration_32k.calibra_result_32k = 0;
                ptrMsg->param.calibration_32k.ok = KAL_FALSE;
                FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);

            }
            else
                FT_Send32KCalibraResultBack();

            break;
        }
#if  IS_FHC_SUPPORT == 1
        case RF_TEST_CMD_START_FDT_DL:
        case RF_TEST_CMD_START_FDT_DL_BIG:
        {
            kal_uint16        pdu_length;
            kal_uint16        u2StepSize;
            RFTestCmdDTS *dts;

            g_FHC_DTS_waiting = KAL_TRUE;  //wait for the result coming back from L1, then return back
            u2StepSize = (req->type == RF_TEST_CMD_START_FDT_DL)?FT_MAX_STEP_CNT:FT_MAX_STEP_EX_CNT;

            // store rf token id, because this command won't return immediately.
            ft_gl_rf_token = req->header.token;

            ft_rfDATA.wait_cnf = KAL_TRUE;
            ft_rfDATA.type = req->type;

            if(ft_rfDATA.pDTSBuf == NULL)
                ft_rfDATA.pDTSBuf = (DTSParam*)get_ctrl_buffer(sizeof(DTSParam));

            // get the parameter from peer buffer
            dts = (RFTestCmdDTS *)get_pdu_ptr( p_peer_buff_ptr, &pdu_length );

            // assign the parameter
            ft_rfDATA.pDTSBuf->afc_cal = dts->afc_cal;
            ft_rfDATA.pDTSBuf->pl_cal = dts->pl_cal;
            ft_rfDATA.pDTSBuf->sync_sb_num = dts->sync_sb_num;
            ft_rfDATA.pDTSBuf->power = dts->power;
            ft_rfDATA.pDTSBuf->lpm_sb_num = 0;

            if(sizeof(DSSAfc) == sizeof(RFTestCmdDSSAfc))
                kal_mem_cpy(&(ft_rfDATA.pDTSBuf->AfcDSS), &(dts->AfcDSS), sizeof(dts->AfcDSS));
            else
            {
                ASSERT(0);
            }
            ft_rfDATA.pDTSBuf->step_cnt = dts->step_cnt;

            if(sizeof(DSSPL) == sizeof(RFTestCmdDSSPL))
                kal_mem_cpy(&(ft_rfDATA.pDTSBuf->PathLossDSS[0]), &(dts->PathLossDSS[0]),
                        (u2StepSize-2)*sizeof(DSSPL));
            else
            {
                ASSERT(0);
            }
            // call the API
            L1TST_StartDTSCal((DTSParam*)ft_rfDATA.pDTSBuf);
            // did not return the CNF to PC side,
            // because we wait for L1 call FT_DispatchReports with type: ReportDTS
            break;
        }
        case RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT:
        case RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_BIG:
        /* [LPM CAL] */
        case RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX:
        case RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX_BIG:
        {
            kal_bool      ret = KAL_TRUE;
            kal_uint16    pdu_length;
            kal_uint16    u2StepSize;
            RFTestCmdDTS* dts;

            u2StepSize = (
                     (req->type == RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT || 
                     req->type == RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX)?
                     FT_MAX_STEP_CNT:FT_MAX_STEP_EX_CNT
                );
            FdtType           = req->type;
            g_FHC_DTS_waiting = KAL_FALSE;     // without waiting the result and return back immediately

            ft_gl_token =  req->header.token;
            ft_rfDATA.result_ready = KAL_FALSE;
            ft_rfDATA.wait_cnf = KAL_TRUE;
            ft_rfDATA.type = req->type;
            if(ft_rfDATA.pDTSBuf == NULL)
            {
                ft_rfDATA.pDTSBuf = (DTSParam*)get_ctrl_buffer(sizeof(DTSParam));
            }
            // get the parameter from peer buffer
            dts = (RFTestCmdDTS *)get_pdu_ptr( p_peer_buff_ptr, &pdu_length );
            // assign the parameter
            ft_rfDATA.pDTSBuf->afc_cal = dts->afc_cal;
            ft_rfDATA.pDTSBuf->pl_cal = dts->pl_cal;
            ft_rfDATA.pDTSBuf->sync_sb_num = dts->sync_sb_num;
            ft_rfDATA.pDTSBuf->power = dts->power;
            if(sizeof(DSSAfc) == sizeof(RFTestCmdDSSAfc))
            {
                kal_mem_cpy(&(ft_rfDATA.pDTSBuf->AfcDSS), &(dts->AfcDSS), sizeof(dts->AfcDSS));
            }
            else
            {
                ret = KAL_FALSE;
            }
            ft_rfDATA.pDTSBuf->step_cnt = dts->step_cnt;
            if(sizeof(DSSPL) == sizeof(RFTestCmdDSSPL))
            {
                kal_mem_cpy(&(ft_rfDATA.pDTSBuf->PathLossDSS[0]), &(dts->PathLossDSS[0]),
                        (u2StepSize-2)*sizeof(DSSPL));
            }
            else
            {
                ret = KAL_FALSE;
            }
            if(req->type == RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT || 
               req->type == RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_BIG)
            {
                ft_rfDATA.pDTSBuf->lpm_sb_num = 0;
            }
            else if(req->type == RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX)
            {
                ft_rfDATA.pDTSBuf->lpm_sb_num = ((RFTestCmdDTS_Ex*)dts)->lpm_sb_num;
            }
            else if(req->type == RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX_BIG)
            {
                ft_rfDATA.pDTSBuf->lpm_sb_num = ((RFTestCmdDTS_Big_Ex*)dts)->lpm_sb_num;
            }            
            // call the API
            L1TST_StartDTSCal((DTSParam*)ft_rfDATA.pDTSBuf);
            // prepare cnf back to PC side,
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            ptrMsg->param.ok = ret;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_FDT_RESULT:
        case RF_TEST_CMD_GET_FDT_RESULT_BIG:
        /* LPM CAL */
        case RF_TEST_CMD_GET_FDT_RESULT_EX:
        case RF_TEST_CMD_GET_FDT_RESULT_EX_BIG:
        {
            // declare
            ilm_struct* ilm_ptr;
            ft_rf_test_cnf_T* ptrMsg;
            kal_char   *pdu_ptr;
            peer_buff_struct *peer_buff_ret;
            kal_uint16 pdu_length;
            // initialize
            pdu_ptr = NULL;
            peer_buff_ret = NULL;
            ft_gl_token = req->header.token;
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg=(ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type                   = req->type;

            if( KAL_TRUE == ft_rfDATA.result_ready )
            {
                if(KAL_TRUE == ft_rfDATA.wait_cnf)
                {
                    ASSERT(0);
                }
                else
                {
                    ptrMsg->param.dts_get_result_status = DTS_RESULT_READY;
                }
                ft_rfDATA.result_ready = KAL_FALSE;
            }
            else
            {
                if(KAL_TRUE == ft_rfDATA.wait_cnf)
                {
                    ptrMsg->param.dts_get_result_status = DTS_RESULT_NOT_READY;
                }
                else
                {
                    ptrMsg->param.dts_get_result_status = DTS_RESULT_NOT_REQUESTED;
                }
            }
            // if result is ready, then copy to the peer buffer
            if(DTS_RESULT_READY == ptrMsg->param.dts_get_result_status)
            {
                // copy result to peer buffer
                if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(_DTSReport_U), 0, 0, TD_CTRL)) )
                {
                    pdu_ptr = get_pdu_ptr( peer_buff_ret, &pdu_length );
                    kal_mem_cpy(pdu_ptr, g_rdtsPtr, sizeof(_DTSReport_U));
                    kal_mem_set(g_rdtsPtr,  0, sizeof(_DTSReport_U));
                    if(req->type == RF_TEST_CMD_GET_FDT_RESULT || 
                       req->type == RF_TEST_CMD_GET_FDT_RESULT_BIG)
                    {
                        peer_buff_ret->pdu_len = (
                                (req->type == RF_TEST_CMD_GET_FDT_RESULT)?
                                sizeof(RfTestResultDTS):sizeof(RfTestResultDTSBig)
                            );
                    }
                    else if(req->type == RF_TEST_CMD_GET_FDT_RESULT_EX ||
                            req->type == RF_TEST_CMD_GET_FDT_RESULT_EX_BIG)
                    {
                        peer_buff_ret->pdu_len = (
                                (req->type == RF_TEST_CMD_GET_FDT_RESULT_EX)?
                                sizeof(RfTestResultDTS_Ex):sizeof(RfTestResultDTS_Big_Ex)
                            );                      
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                        
                    }
                    // assign peer buffer
                    if( NULL != peer_buff_ret ) {
                        ilm_ptr->peer_buff_ptr = peer_buff_ret;
                    }
                }
                else
                {
                    ASSERT(0);
                }


                if(NULL != g_rdtsPtr)
                {
                    free_ctrl_buffer(g_rdtsPtr);
                    g_rdtsPtr = NULL;
                }
            }

            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_START_FDT_UL:
        case RF_TEST_CMD_START_FDT_UL_BIG:
        {

            kal_uint8 i;
            kal_uint16        pdu_length;
            kal_uint16        u2StepSize;
            RfTestCmdUTS      *uts;

            u2StepSize = (req->type == RF_TEST_CMD_START_FDT_UL)?FT_MAX_STEP_CNT:FT_MAX_STEP_EX_CNT;
            ft_gl_rf_token = req->header.token;

            ft_rfDATA.wait_cnf = KAL_TRUE;
            ft_rfDATA.type = req->type;

            if(ft_rfDATA.pUTSBuf == NULL)
                ft_rfDATA.pUTSBuf = (UTSParam*) get_ctrl_buffer(sizeof(UTSParam));

            // get the parameter from peer buffer
            uts = (RfTestCmdUTS *)get_pdu_ptr( p_peer_buff_ptr, &pdu_length );

            // assign the parameter
            //        ft_rfDATA.pUTSBuf->pa_vbias_cal = uts->pa_vbias_cal;
            ft_rfDATA.pUTSBuf->step_cnt = uts->step_cnt;

            for(i=0; i<FrequencyBandCount; i++)
                ft_rfDATA.pUTSBuf->high_apc_dcoffset[i] = uts->high_apc_dcoffset[i];
            //ft_rfDATA.pUTSBuf->lowest_power[i] = uts->lowest_power[i];

            if(sizeof(USSApc) == sizeof(RfTestCmdUSSApc))
                kal_mem_cpy(&(ft_rfDATA.pUTSBuf->ApcUSS[0]),&(uts->ApcUSS[0]),
                        sizeof(RfTestCmdUSSApc)*u2StepSize);
            else
            {
                sprintf((kal_char *)g_FT_debug_buf, "FDT: copy USSApc parameter fail");
                tst_sys_trace(g_FT_debug_buf);
            }

            // call the API
            L1TST_StartUTSCal((UTSParam*)ft_rfDATA.pUTSBuf);

            // did not return the CNF to PC side,
            // because we wait for L1 call FT_DispatchReports with type: ReportDTS

            break;
        }

        case RF_TEST_CMD_GET_AFC_DAC_OFFSET:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            //ptrMsg->param.afc_result.afc_offset = L1D_RF_GetAFCDacTRxOffset( req->param.rf_band );
            L1D_RF_GetAFCDacTRxOffset(ptrMsg->param.afc_result.afc_offset);
            ptrMsg->param.afc_result.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);

            break;
        }
        case RF_TEST_CMD_SET_AFC_DAC_OFFSET:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            L1D_RF_SetAFCDacTRxOffset( req->param.set_afc_offset_req.afc_offset);

            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);

            break;
        }
#endif // #if  IS_FHC_SUPPORT == 1
#if IS_NSFT_SUPPORT == 1
        case RF_TEST_CMD_NSFT_CHANGE_SETTING:
        {
            // store rf token id, because this command won't return immediately.
            ft_gl_rf_token = req->header.token;

            ft_rfDATA.wait_cnf = KAL_TRUE;
            ft_rfDATA.type = req->type;
            req->param.NSFT_start.epsk_cs = ft_rf_translate_codingscheme_from_pc_one_slot(req->param.NSFT_start.epsk_cs);
            L1TST_NSFTProc_ChangeChannel(req->param.NSFT_start.band,
                    req->param.NSFT_start.BCH_ARFCN,
                    req->param.NSFT_start.TCH_ARFCN,
                    req->param.NSFT_start.BCH_gain,
                    req->param.NSFT_start.TCH_gain,
                    req->param.NSFT_start.tsc,
                    req->param.NSFT_start.TCH_slot,
                    req->param.NSFT_start.tx_power_level,
                    req->param.NSFT_start.is_EPSK_tx,
                    req->param.NSFT_start.epsk_cs
                    );

            // did not return the CNF to PC side,
            // because we wait for L1 call FT_DispatchReports with type: ReportNSFT

            break;
        }
        case RF_TEST_CMD_NSFT_START:
        {
            // store rf token id, because this command won't return immediately.
            ft_gl_rf_token = req->header.token;

            ft_rfDATA.wait_cnf = KAL_TRUE;
            ft_rfDATA.type = req->type;
            req->param.NSFT_start.epsk_cs = ft_rf_translate_codingscheme_from_pc_one_slot(req->param.NSFT_start.epsk_cs);
            L1TST_StartNSFTProc(req->param.NSFT_start.band,
                    req->param.NSFT_start.BCH_ARFCN,
                    req->param.NSFT_start.TCH_ARFCN,
                    req->param.NSFT_start.BCH_gain,
                    req->param.NSFT_start.TCH_gain,
                    req->param.NSFT_start.tsc,
                    req->param.NSFT_start.TCH_slot,
                    req->param.NSFT_start.tx_power_level,
                    req->param.NSFT_start.is_EPSK_tx,
                    req->param.NSFT_start.epsk_cs
                    );
            // did not return the CNF to PC side,
            // because we wait for L1 call FT_DispatchReports with type: ReportNSFT

            break;
        }
        case RF_TEST_CMD_NSFT_STOP:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            L1TST_StopNSFTProc();
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_NSFT_CHANGE_POWER:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            L1TST_NSFTProc_ChangePower(req->param.NSFT_change_power.tx_power_level);
            ptrMsg->param.ok = KAL_TRUE;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // #if  IS_NSFT_SUPPORT == 1

        case RF_TEST_CMD_POWER_ON:
        case RF_TEST_CMD_POWER_OFF:
        case RF_TEST_CMD_QUERY_POWER_STATE_IN_FT:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;

            if( RF_TEST_CMD_POWER_ON == req->type)
            {
                L1D_RF_PowerOn();
                g_i1_ft_2g_rf_power_state = FT_RF_PWR_STATE_ON;
                ptrMsg->param.ok = KAL_TRUE;
            }
            else if(RF_TEST_CMD_POWER_OFF == req->type)
            {
                L1D_RF_PowerOff();
                g_i1_ft_2g_rf_power_state = FT_RF_PWR_STATE_OFF;
                ptrMsg->param.ok = KAL_TRUE;
            }
            else
            {
               ptrMsg->param.m_i1RfPwrState_FT = g_i1_ft_2g_rf_power_state;
            }


            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;


        }
#if defined(__PS_SERVICE__)
        case RF_TEST_CMD_SET_TX_POWER_ROLLBACK_GMSK:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            L1D_RF_SetTxPowerRollbackData(req->param.PowerRollbackTable.band, (void*)&req->param.PowerRollbackTable.PowerRollbackTable);
            ptrMsg->param.ok = KAL_TRUE;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_TX_POWER_ROLLBACK_TABLE_GMSK:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            setGMSKTXRollbackTableToL1D(p_peer_buff_ptr, NULL);
            ptrMsg->param.ok = KAL_TRUE;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // #if defined(__PS_SERVICE__)
#if defined(__EGPRS_MODE__)
        case RF_TEST_CMD_SET_TX_POWER_ROLLBACK_EPSK:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            L1D_RF_SetTxPowerRollbackData_EPSK(req->param.PowerRollbackTable.band, (void*)&req->param.PowerRollbackTable.PowerRollbackTable);
            ptrMsg->param.ok = KAL_TRUE;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_TX_POWER_ROLLBACK_TABLE_EPSK:
        {
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            /* if ptrMsg != NULL*/
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            setEPSKTXRollbackTableToL1D(p_peer_buff_ptr, NULL);
            ptrMsg->param.ok = KAL_TRUE;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // #if defined(__EGPRS_MODE__)
        case RF_TEST_CMD_GET_SPECIALCOEF:
        {
            // get special coeff from L1
            extern sRFSpecialCoef RFSpecialCoef;
            kal_mem_cpy(&ft_rf_data_pt,
                    &RFSpecialCoef,
                    (sizeof(sRFSpecialCoef)));
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    sizeof(l1cal_rfspecialcoef_T),
                    &ft_rf_data_pt);
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#if IS_SINGLE_END_BER_SUPPORT == 1
        case RF_TEST_CMD_NSFT_CONFIG_SBER:
        {
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            L1TST_SetupSingleEndBERData(req->param.m_u4NSFTSBERTestCount);
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_NSFT_GET_SBER:
        {
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            L1TST_ReportSingleEndBERDone(&(ptrMsg->param.m_rNSFTSBER.m_u4NSFTSBER), &(ptrMsg->param.m_rNSFTSBER.m_u4NSFTSBERCurrentCount));
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // #if IS_SINGLE_END_BER_SUPPORT == 1
#if IS_NSFT_SACCH_TEST_ITEM_SUPPORT == 1
        case RF_TEST_CMD_NSFT_START_RXLEV:
        {
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            L1TST_SetupRXLEVData();
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_NSFT_GET_RXLEV:
        {
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            L1TST_ReportRXLEV( &(ptrMsg->param.m_u2NSFTRxLevel) );
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_NSFT_GET_RXQUAL:
        {
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            L1TST_ReportRXQual( req->param.m_u2NSFTRxQualBerDecile, &(ptrMsg->param.m_u1NSFTRxQual) );
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // #if IS_NSFT_SACCH_TEST_ITEM_SUPPORT == 1
#if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
        case RF_TEST_CMD_GET_TXPC_PD_VALUE_BY_PCL_GMSK:
#if defined(__EPSK_TX__)
        case RF_TEST_CMD_GET_TXPC_PD_VALUE_BY_PCL_EPSK:
#endif // #if defined(__EPSK_TX__)
        {
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            ptrMsg->param.txpc_cnf.m_u2PDValue = 
                L1TST_TXPC_CL_GetOneADC(req->param.txpc_req.band,
                        req->param.txpc_req.pcl,
                        req->type == RF_TEST_CMD_GET_TXPC_PD_VALUE_BY_PCL_GMSK ? 0 /* GMSK */ : 1 /* EPSK */);
            ptrMsg->param.txpc_cnf.ok = KAL_TRUE;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_TXPC_PD_VALUE_GMSK:
#if defined(__EPSK_TX__)
        case RF_TEST_CMD_GET_TXPC_PD_VALUE_EPSK:
#endif // #if defined(__EPSK_TX__)
        {
            if(sizeof(RfTestResultTXPCAllPD) != sizeof(l1cal_txpc_T))
            {
                ASSERT(0);
            }
            else
            {
                L1TST_TXPC_CL_GetAllADC(&(ft_rf_data_pt.ft_l1cal_txpc),
                        req->type == RF_TEST_CMD_GET_TXPC_PD_VALUE_GMSK ? 0/* GMSK */ : 1 /* EPSK */);
                L1TST_TXPC_CL_GetAllTEMP(&(ft_rf_data_pt.ft_l1cal_txpc),
                        req->type == RF_TEST_CMD_GET_TXPC_PD_VALUE_GMSK ? 0/* GMSK */ : 1 /* EPSK */);
            }
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    sizeof(l1cal_txpc_T),
                    &ft_rf_data_pt);
            ptrMsg->param.txpc_cnf.ok = KAL_TRUE;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_TXPC_SUBBAND_GMSK:
#if defined(__EPSK_TX__)
        case RF_TEST_CMD_GET_TXPC_SUBBAND_EPSK:
#endif // #if defined(__EPSK_TX__)
        {
            ft_construct_rf_confirm_message(&ilm_ptr,
                        sizeof(ft_rf_test_cnf_T),
                        &ptrMsg,
                        FT_RF_TEST_CNF_ID,
                        req->type,
                        0,
                        NULL);
            L1TST_TXPC_CL_GetSubband(req->param.band, &(ptrMsg->param.m_txpc_subband_compensation), (req->type == RF_TEST_CMD_GET_TXPC_SUBBAND_GMSK) ? 0/* GMSK */ : 1/* EPSK */ );
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_GET_TXPC_TEMPERATURE:
        {
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            ptrMsg->param.temperature = L1TST_TXPC_GetTemperature();
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
#endif // #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
        case RF_TEST_CMD_QUERY_MS_CAPABILITY_EX3:
        {
            L1TST_MsCapabilityV2((MsCapabilityExV2*)&ft_rf_data_pt);
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    sizeof(MsCapabilityExV2),
                    &ft_rf_data_pt);
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_DCXO_POWER_MODE:
        {
            L1TST_SetDcxoPowerMode(req->param.dcxoMode);
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        case RF_TEST_CMD_SET_DT_PATH_FLAG:
        {
            L1D_RF_Set_TX_Notch_Path( req->param.path_flag );
            ft_construct_rf_confirm_message(&ilm_ptr,
                    sizeof(ft_rf_test_cnf_T),
                    &ptrMsg,
                    FT_RF_TEST_CNF_ID,
                    req->type,
                    0,
                    NULL);
            ptrMsg->param.ok = KAL_TRUE;
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            break;
        }
        default:
            break;
    }
}

//-------------------------------------------------------------------

kal_int32 i4CalibraResult = 0;
kal_bool bResultBack = false;
void Meta_32KCalibrationHandler(kal_int32 result)
{
    // can not directly send the cnf to PC side, because this is processed by LISR.
    // update the flag
    i4CalibraResult = result;
    bResultBack = true;
}
void FT_Send32KCalibraResultBack(void)  // for build warning
{
    int check_times;
    ft_rf_test_cnf_T* ptrMsg;
    ilm_struct* ilm_ptr;

    check_times = 0;

    while(check_times <10)
    {

        kal_sleep_task(50);
        if(bResultBack == true)
        {
            // send the cnf to pc side
            ft_gl_token = ft_gl_rf_token;
            if( NULL == (ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T))) )
                return;

            ptrMsg = (ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;

            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type          = ft_rfDATA.type;
            //ptrMsg->type = RF_TEST_CMD_CALIBRATE_32K;

            ptrMsg->param.calibration_32k.calibra_result_32k = i4CalibraResult;
            ptrMsg->param.calibration_32k.ok = KAL_TRUE;

            //FT_SendMessage(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
            ft_rfDATA.wait_cnf = KAL_FALSE;

            // reset the value
            bResultBack = false;
            i4CalibraResult = 0;
            break; // leave the loop
        }
        check_times++;
    }


}
/*******************************************************************************
 * FUNCTION (static scope)
 *   ft_construct_rf_confirm_message
 *
 * DESCRIPTION
 *   construct confirm message for RF test confirm
 *
 * CALLS
 *   FT_ALLOC_MSG
 *   construct_peer_buff
 *   get_pdu_ptr
 *   kal_mem_cpy
 *
 * PARAMETERS
 *   ilm_ptr[OUT] the pointer to the ilm_struct pointer to the confirm message
 *   local_message_size[IN] the size of the local parameter
 *   ptrMsg[OUT] the pointer of the pointer to the RF sub command confirm structure
 *   msg_id the message id of the confirm message
 *   type the request type of the request message
 *   peer_pdu_size the pdu size of the confirm message (if any)
 *   in_pdu_ptr the pointer to the PDU content that will be put into the peer buffer in the confirm message (if any)
 *
 * RETURNS
 *   none
 *
 *******************************************************************************/
static void ft_construct_rf_confirm_message(ilm_struct **ilm_ptr, kal_uint16 local_message_size,
        ft_rf_test_cnf_T** ptrMsg,
        kal_uint16 msg_id, kal_uint16 type,
        kal_uint16 peer_pdu_size,
        const void * in_pdu_ptr)
{
    kal_uint16 pdu_length = 0;
    peer_buff_struct* peer_buff_ptr = NULL;
    kal_char *pdu_ptr = NULL;
    *ilm_ptr = FT_ALLOC_MSG(local_message_size);
    *ptrMsg = (ft_rf_test_cnf_T*)((*ilm_ptr)->local_para_ptr);
    (*ptrMsg)->header.ft_msg_id = msg_id;
    (*ptrMsg)->type = (RfTestCmdType)type;
    (*ptrMsg)->param.ok = KAL_TRUE;
    if(peer_pdu_size > 0)
    {
        // copy result to peer buffer
        if( NULL != (peer_buff_ptr=construct_peer_buff(peer_pdu_size, 0, 0, TD_CTRL)) )
        {
            pdu_ptr = get_pdu_ptr( peer_buff_ptr, &pdu_length );
            kal_mem_cpy(pdu_ptr, in_pdu_ptr, pdu_length);
            peer_buff_ptr->pdu_len = pdu_length;
            // assign peer buffer
            (*ilm_ptr)->peer_buff_ptr = peer_buff_ptr;
        }
        else
        {
            ASSERT(0);
        }
    }
}

/*******************************************************************************
* FUNCTION
*   FT_DispatchReports
*
* DESCRIPTION
*   Dispatch report
*
* CALLS
*   FT_ReportPowerScanDone
*   FT_ReportFCB
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void FT_DispatchReports( Report_FT *report )
{
#ifdef __MTK_TARGET__
    switch (report->type)
    {
        case ReportFTPowerScanDone:
            FT_ReportPowerScanDone(report->data.pm_tst);
            break;

        case ReportFTFCCh:
            FT_ReportFCB(report->data.sch);
            break;
#if  IS_FHC_SUPPORT == 1
        case ReportFTDTS:
            if(ft_rfDATA.type == RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT ||
               ft_rfDATA.type == RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX ||
               ft_rfDATA.type == RF_TEST_CMD_START_FDT_DL)
            {
                FT_ReportDTS(report->data.dts_result);
            }
            else
            {
                FT_ReportDTS_Ex(report->data.dts_result);
            }
            break;
        case ReportFTUTS:
            FT_ReportUTS();
            break;
#endif // #if  IS_FHC_SUPPORT == 1
#if IS_NSFT_SUPPORT == 1
        case ReportFTNSFT:	
            FT_ReportNSFT(report->data.sch);
            break;
#endif // #if IS_NSFT_SUPPORT == 1
        default:
            break;
    }
#endif // #ifdef __MTK_TARGET__
}


/*******************************************************************************
 * FUNCTION
 *   FT_ReportPowerScanDone
 *
 * DESCRIPTION
 *   Handle PM report
 *
 * CALLS
 *   None
 *
 * PARAMETERS
 *   *pm_tst
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None (L1 modifies the L1 global variable RFSpecialCoef, for storing IRR W coefficient)
 *******************************************************************************/
void FT_ReportPowerScanDone(PM_TST_Data *pm_tst)
{
    ft_rf_test_cnf_T* ptrMsg;
    ilm_struct* ilm_ptr;
    if(ft_rfDATA.wait_cnf != KAL_FALSE)
    {
        // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
        ft_gl_token = ft_gl_rf_token;

        ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
        ptrMsg=(ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
        /* if ptrMsg != NULL*/
        ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
        ptrMsg->type          = ft_rfDATA.type;
        ptrMsg->param.pm.power = pm_tst->power;
        ptrMsg->param.pm.deviation = pm_tst->deviation;
        ptrMsg->param.pm.usedGain = pm_tst->usedGain;
        ptrMsg->param.pm.iOffset = pm_tst->iOffset;
        ptrMsg->param.pm.qOffset = pm_tst->qOffset;
        ptrMsg->param.pm.validSamples = pm_tst->validSamples;
        ptrMsg->param.pm.ok = KAL_TRUE;
        /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
        FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
        ft_rfDATA.wait_cnf = KAL_FALSE;
    }
}


/*******************************************************************************
 * FUNCTION
 *   FT_ReportFCB
 *
 * DESCRIPTION
 *   Handle FCB report
 *
 * CALLS
 *   None
 *
 * PARAMETERS
 *   *sch
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None
 *******************************************************************************/
void FT_ReportFCB(SChData *sch)
{
    RfTestResultAfc   *afcResult;
    kal_int32          freqOffset;
    if(ft_rfDATA.wait_cnf != KAL_FALSE)
    {

        afcResult = &ft_rfDATA.param.afc;

        ft_rfDATA.afcCmd.testNumber--;

        if (sch->fcb_ok)
        {
            freqOffset                = L1TST_FCBGetFreqOffset();

            afcResult->freqOffset    += freqOffset;
            afcResult->deviation     += (freqOffset*freqOffset);
            afcResult->fcb_ok_number++;
        }

        if (ft_rfDATA.afcCmd.testNumber <= 0)
        {
            if (afcResult->fcb_ok_number != 0)
            {
                afcResult->freqOffset /= afcResult->fcb_ok_number;
                afcResult->deviation =
                    afcResult->deviation/afcResult->fcb_ok_number -
                    (afcResult->freqOffset*afcResult->freqOffset);
            }
            {
                ft_rf_test_cnf_T* ptrMsg;
                ilm_struct* ilm_ptr;

                // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
                ft_gl_token = ft_gl_rf_token;

                ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
                ptrMsg=(ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
                /* if ptrMsg != NULL*/
                ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
                ptrMsg->type          = ft_rfDATA.type;
                ptrMsg->param.afc.freqOffset = ft_rfDATA.param.afc.freqOffset;
                ptrMsg->param.afc.deviation = ft_rfDATA.param.afc.deviation;
                ptrMsg->param.afc.fcb_ok_number = ft_rfDATA.param.afc.fcb_ok_number;
                ptrMsg->param.afc.ok = KAL_TRUE;
                /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
                FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
                ft_rfDATA.wait_cnf = KAL_FALSE;
            }
        }
        else
        {
            L1TST_FCBControl(ft_rfDATA.afcCmd.arfcn,
                    ft_rfDATA.afcCmd.dacValue,
                    ft_rfDATA.afcCmd.gain);
        }

    }/* endif of ft_rfDATA.wait_cnf != FALSE */
}
/*******************************************************************************
 * FUNCTION
 *   FT_ReportNSFT
 *
 * DESCRIPTION
 *   [FDT] Handle NSFT report
 *
 * CALLS
 *   None
 *
 * PARAMETERS
 *   SChData *nsftResult
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   ft_rfDATA.wait_cnf
 *   ft_rfDATA.pDTSBuf
 *******************************************************************************/
#if  IS_NSFT_SUPPORT == 1
void FT_ReportNSFT(SChData *nsftResult)
{
    ft_rf_test_cnf_T* ptrMsg;
    ilm_struct* ilm_ptr;
    if(ft_rfDATA.wait_cnf != KAL_FALSE)
    {
        // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
        ft_gl_token = ft_gl_rf_token;
        ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
        ptrMsg=(ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
        if(ptrMsg == NULL)
            ASSERT(0);

        ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
        ptrMsg->type             = ft_rfDATA.type;

        if(nsftResult->ok){
            // snyc successfully
            ptrMsg->param.ok = KAL_TRUE;
        }else{
            // snyc fail
            ptrMsg->param.ok = KAL_FALSE;
        }

        FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
        ft_rfDATA.wait_cnf = KAL_FALSE;
    }
}
#endif // #if  IS_NSFT_SUPPORT == 1
/*******************************************************************************
 * FUNCTION
 *   FT_ReportDTS
 *
 * DESCRIPTION
 *   [FDT] Handle DTS report
 *
 * CALLS
 *   None
 *
 * PARAMETERS
 *   ResultDTS *dtsResult
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   ft_rfDATA.wait_cnf
 *   ft_rfDATA.pDTSBuf
 *******************************************************************************/
#if  IS_FHC_SUPPORT == 1
void FT_ReportDTS(ResultDTS *dtsResult)
{
    ft_rf_test_cnf_T* ptrMsg = NULL;
    ilm_struct* ilm_ptr = NULL;
    /* [LPM CAL] */
    RfTestResultDTS *rdtsPtr;
    RfTestResultDTS_Ex* rdtsPtr_ex;
    sDTSM           *rSDTSM;
    int i;
    kal_char   *pdu_ptr;
    peer_buff_struct *peer_buff_ret;
    kal_uint16 pdu_length;
    // initialize
    rdtsPtr = NULL;
    rdtsPtr_ex = NULL;
    pdu_ptr = NULL;
    peer_buff_ret = NULL;
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
    if(ft_rfDATA.wait_cnf != KAL_FALSE)
    {
        if(KAL_FALSE == g_FHC_DTS_waiting)
        {
            // the calling command is RF_TEST_CMD_START_FDT_DL
            // use a global ptr to get a control buffer to store FHC DTS result temporary
            if(NULL == g_rdtsPtr)
            {
                g_rdtsPtr = (_DTSReport_U *)get_ctrl_buffer(sizeof(_DTSReport_U));
            }
            if(g_rdtsPtr)
            {
                rdtsPtr = &(g_rdtsPtr->dts_result);
                rdtsPtr_ex = &(g_rdtsPtr->dts_result_ex);
            }
            else
            {
                ASSERT(g_rdtsPtr);
            }
        }
        else
        {
            // the calling command is RF_TEST_CMD_START_FDT_DL_AND_WAIT_RESULT or RF_TEST_CMD_START_FDT_DL_AND_WAIT_RESULT_EX
            // prepare a ft message to send back to PC
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg=(ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type             = ft_rfDATA.type;
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(_DTSReport_U), 0, 0, TD_CTRL)) )
            {
                pdu_ptr = get_pdu_ptr( peer_buff_ret, &pdu_length );
                if(dtsResult->LPMResult.is_perform_cal == 0)
                {
                    peer_buff_ret->pdu_len = sizeof(RfTestResultDTS);
                }
                else
                {
                    peer_buff_ret->pdu_len = sizeof(RfTestResultDTS_Ex);
                }
                // assign peer buffer
                if( NULL != peer_buff_ret )
                {
                    ilm_ptr->peer_buff_ptr = peer_buff_ret;
                }
            }
            if(pdu_ptr)
            {
                rdtsPtr = (RfTestResultDTS*)pdu_ptr;
                rdtsPtr_ex = (RfTestResultDTS_Ex*)pdu_ptr;
            }
            else
            {
                ASSERT(pdu_ptr);
            }
        }
        // about ResultDSSPL
        if(sizeof(ResultDSSPL) == sizeof(RfTestResultDSSPL))
        {
            kal_mem_cpy(&(rdtsPtr->PLResult), &(dtsResult->PLResult), sizeof(ResultDSSPL));
        }
        else if(sizeof(ResultDSSPL) == sizeof(RfTestResultDSSPLBig))
        {
            kal_mem_cpy(&(rdtsPtr->PLResult.power[0]), &(dtsResult->PLResult.power[0]), 
                sizeof(kal_int32) * (FT_MAX_STEP_CNT - 2));
            kal_mem_cpy(&(rdtsPtr->PLResult.valid_sample[0]), &(dtsResult->PLResult.valid_sample[0]), 
                sizeof(kal_int16)* (FT_MAX_STEP_CNT - 2));
            rdtsPtr->PLResult.ok = dtsResult->PLResult.ok;
        }
        else
        {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        }

        if(sizeof(ResultDSSAfc) == sizeof(RfTestResultDSSAfc))
            kal_mem_cpy(&(rdtsPtr->AfcResult), &(dtsResult->AfcResult), sizeof(ResultDSSAfc));
        else
        {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        }

        // get FHC parameter for L1 guy to do future analysis and debug when the do DTS fail
        rSDTSM = L1TST_FHCLog();
        if(rdtsPtr == NULL)   return; // make sure rdtsPtr not be NULL
        rdtsPtr->m_rDtsmInfo.path_loss_cnt = rSDTSM->path_loss_cnt;
        rdtsPtr->m_rDtsmInfo.freq_offset = rSDTSM->freq_offset;
        rdtsPtr->m_rDtsmInfo.capid_freq_offset_min = rSDTSM->capid_freq_offset_min;
        for(i=0;i < FHC_MAX_CAPID_SEARCH_NUM; i++)
        {

            rdtsPtr->m_rDtsmInfo.capid_freq_offset[i] = rSDTSM->capid_freq_offset[i];
            rdtsPtr->m_rDtsmInfo.capid_search_order[i] = rSDTSM->capid_search_order[i];
        }
        rdtsPtr->m_rDtsmInfo.capid = rSDTSM->capid;
        rdtsPtr->m_rDtsmInfo.capid_high = rSDTSM->capid_high;
        rdtsPtr->m_rDtsmInfo.capid_low = rSDTSM->capid_low;
        rdtsPtr->m_rDtsmInfo.capid_best = rSDTSM->capid_best;
        rdtsPtr->m_rDtsmInfo.afc_dac = rSDTSM->afc_dac;
        rdtsPtr->m_rDtsmInfo.arfcn = rSDTSM->arfcn;
        rdtsPtr->m_rDtsmInfo.capid_cnt = rSDTSM->capid_cnt;
        rdtsPtr->m_rDtsmInfo.repeat_index = rSDTSM->repeat_index;
        rdtsPtr->m_rDtsmInfo.state = rSDTSM->state;
        rdtsPtr->m_rDtsmInfo.capid_index = rSDTSM->capid_index;
        rdtsPtr->m_rDtsmInfo.capid_okay_cnt = rSDTSM->capid_okay_cnt;
        rdtsPtr->m_rDtsmInfo.afc_dac_index = rSDTSM->afc_dac_index;
        rdtsPtr->m_rDtsmInfo.sb_okay_cnt = rSDTSM->sb_okay_cnt;
        rdtsPtr->m_rDtsmInfo.sb_fail_cnt = rSDTSM->sb_fail_cnt;
        rdtsPtr->m_rDtsmInfo.fb_fail_cnt = rSDTSM->fb_fail_cnt;
        rdtsPtr->m_rDtsmInfo.pl_started = rSDTSM->pl_started;
        for(i=0;i<FHC_PRE_CAPID_SEARCH_NUM; i++)
        {
            rdtsPtr->m_rDtsmInfo.pre_capid_cal_ok[i] = rSDTSM->pre_capid_cal_ok[i];
        }
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        /* [LPM CAL] */
        if(dtsResult->LPMResult.is_perform_cal)
        {
            /* crystal low-power mode calibration (for 32k removal) */
            if(sizeof(ResultDSSLPM) == sizeof(RfTestResultDSSLpm))
            {
                kal_mem_cpy(&(rdtsPtr_ex->LpmResult), &(dtsResult->LPMResult), sizeof(ResultDSSLPM));
            }
            else
            {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                {
                    kal_bool ResultDSSLPM_Size_Mismatch = KAL_FALSE;
                    ASSERT(ResultDSSLPM_Size_Mismatch);
                }
            }
        }
        if(KAL_FALSE == g_FHC_DTS_waiting)   // the calling command is RF_TEST_CMD_START_FDT_DL_AND_WAIT_RESULT
        {
            ft_rfDATA.result_ready = KAL_TRUE;
        }
        else
        {
            // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
            ft_rfDATA.result_ready = KAL_FALSE;
            ft_gl_token = ft_gl_rf_token;
            ptrMsg->param.dts_get_result_status= DTS_RESULT_READY;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
        }
        ft_rfDATA.wait_cnf = KAL_FALSE;
    } //endif of ft_rfDATA.wait_cnf != FALSE

    // release the buffer we allocate before
    if(ft_rfDATA.pDTSBuf != NULL)
    {
        free_ctrl_buffer(ft_rfDATA.pDTSBuf);
        ft_rfDATA.pDTSBuf = NULL;
    }
}
/*******************************************************************************
 * FUNCTION
 *   FT_ReportDTS_Ex
 *
 * DESCRIPTION
 *   [FDT] Handle DTS extended report
 *
 * CALLS
 *   None
 *
 * PARAMETERS
 *   ResultDTS *dtsResult (path loss 98 steps)
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   ft_rfDATA.wait_cnf
 *   ft_rfDATA.pDTSBuf
 *******************************************************************************/
void FT_ReportDTS_Ex(ResultDTS *dtsResult)
{
    ft_rf_test_cnf_T* ptrMsg = NULL;
    ilm_struct* ilm_ptr = NULL;
    /* [LPM CAL] */
    RfTestResultDTSBig *rdtsPtr;
    RfTestResultDTS_Big_Ex* rdtsPtr_ex;
    sDTSM           *rSDTSM;
    int i;
    kal_char   *pdu_ptr;
    peer_buff_struct *peer_buff_ret;
    kal_uint16 pdu_length;
    // initialize
    rdtsPtr = NULL;
    rdtsPtr_ex = NULL;
    pdu_ptr = NULL;
    peer_buff_ret = NULL;
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
    if(ft_rfDATA.wait_cnf != KAL_FALSE)
    {
        if(KAL_FALSE == g_FHC_DTS_waiting)
        {
            // the calling command is RF_TEST_CMD_START_FDT_DL_BIG
            // use a global ptr to get a control buffer to store FHC DTS result temporary
            if(NULL == g_rdtsPtr)
            {
                g_rdtsPtr = (_DTSReport_U *)get_ctrl_buffer(sizeof(_DTSReport_U));
            }
            if(g_rdtsPtr)
            {
                rdtsPtr = &(g_rdtsPtr->dts_result_big);
                rdtsPtr_ex = &(g_rdtsPtr->dts_result_big_ex);
            }
            else
            {
                ASSERT(g_rdtsPtr);
            }
        }
        else
        {
            // the calling command is RF_TEST_CMD_START_FDT_DL_AND_WAIT_RESULT or RF_TEST_CMD_START_FDT_DL_AND_WAIT_RESULT_EX
            // prepare a ft message to send back to PC
            ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
            ptrMsg=(ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
            ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
            ptrMsg->type             = ft_rfDATA.type;
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(_DTSReport_U), 0, 0, TD_CTRL)) )
            {
                pdu_ptr = get_pdu_ptr( peer_buff_ret, &pdu_length );
                if(dtsResult->LPMResult.is_perform_cal == 0)
                {
                    peer_buff_ret->pdu_len = sizeof(RfTestResultDTSBig);
                }
                else
                {
                    peer_buff_ret->pdu_len = sizeof(RfTestResultDTS_Big_Ex);
                }
                // assign peer buffer
                if( NULL != peer_buff_ret )
                {
                    ilm_ptr->peer_buff_ptr = peer_buff_ret;
                }
            }
            if(pdu_ptr)
            {
                rdtsPtr = (RfTestResultDTSBig*)pdu_ptr;
                rdtsPtr_ex = (RfTestResultDTS_Big_Ex*)pdu_ptr;
            }
            else
            {
                ASSERT(pdu_ptr);
            }
        }
        // about ResultDSSPL
        if(sizeof(ResultDSSPL) == sizeof(RfTestResultDSSPLBig))
            kal_mem_cpy(&(rdtsPtr->PLResult), &(dtsResult->PLResult), sizeof(ResultDSSPL));
        else
        {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        }

        if(sizeof(ResultDSSAfc) == sizeof(RfTestResultDSSAfc))
            kal_mem_cpy(&(rdtsPtr->AfcResult), &(dtsResult->AfcResult), sizeof(ResultDSSAfc));
        else
        {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        }

        // get FHC parameter for L1 guy to do future analysis and debug when the do DTS fail
        rSDTSM = L1TST_FHCLog();
        if(rdtsPtr == NULL)   return; // make sure rdtsPtr not be NULL
        rdtsPtr->m_rDtsmInfo.path_loss_cnt = rSDTSM->path_loss_cnt;
        rdtsPtr->m_rDtsmInfo.freq_offset = rSDTSM->freq_offset;
        rdtsPtr->m_rDtsmInfo.capid_freq_offset_min = rSDTSM->capid_freq_offset_min;
        for(i=0;i < FHC_MAX_CAPID_SEARCH_NUM; i++)
        {

            rdtsPtr->m_rDtsmInfo.capid_freq_offset[i] = rSDTSM->capid_freq_offset[i];
            rdtsPtr->m_rDtsmInfo.capid_search_order[i] = rSDTSM->capid_search_order[i];
        }
        rdtsPtr->m_rDtsmInfo.capid = rSDTSM->capid;
        rdtsPtr->m_rDtsmInfo.capid_high = rSDTSM->capid_high;
        rdtsPtr->m_rDtsmInfo.capid_low = rSDTSM->capid_low;
        rdtsPtr->m_rDtsmInfo.capid_best = rSDTSM->capid_best;
        rdtsPtr->m_rDtsmInfo.afc_dac = rSDTSM->afc_dac;
        rdtsPtr->m_rDtsmInfo.arfcn = rSDTSM->arfcn;
        rdtsPtr->m_rDtsmInfo.capid_cnt = rSDTSM->capid_cnt;
        rdtsPtr->m_rDtsmInfo.repeat_index = rSDTSM->repeat_index;
        rdtsPtr->m_rDtsmInfo.state = rSDTSM->state;
        rdtsPtr->m_rDtsmInfo.capid_index = rSDTSM->capid_index;
        rdtsPtr->m_rDtsmInfo.capid_okay_cnt = rSDTSM->capid_okay_cnt;
        rdtsPtr->m_rDtsmInfo.afc_dac_index = rSDTSM->afc_dac_index;
        rdtsPtr->m_rDtsmInfo.sb_okay_cnt = rSDTSM->sb_okay_cnt;
        rdtsPtr->m_rDtsmInfo.sb_fail_cnt = rSDTSM->sb_fail_cnt;
        rdtsPtr->m_rDtsmInfo.fb_fail_cnt = rSDTSM->fb_fail_cnt;
        rdtsPtr->m_rDtsmInfo.pl_started = rSDTSM->pl_started;
        for(i=0;i<FHC_PRE_CAPID_SEARCH_NUM; i++)
        {
            rdtsPtr->m_rDtsmInfo.pre_capid_cal_ok[i] = rSDTSM->pre_capid_cal_ok[i];
        }
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
        /* [LPM CAL] */
        if(dtsResult->LPMResult.is_perform_cal)
        {
            /* crystal low-power mode calibration (for 32k removal) */
            if(sizeof(ResultDSSLPM) == sizeof(RfTestResultDSSLpm))
            {
                kal_mem_cpy(&(rdtsPtr_ex->LpmResult), &(dtsResult->LPMResult), sizeof(ResultDSSLPM));
            }
            else
            {
#if defined(__MTK_INTERNAL__) && defined(_DEBUG)
/* under construction !*/
/* under construction !*/
#endif // #if defined(__MTK_INTERNAL__) && defined(_DEBUG)
                {
                    kal_bool ResultDSSLPM_Size_Mismatch = KAL_FALSE;
                    ASSERT(ResultDSSLPM_Size_Mismatch);
                }
            }
        }
        if(KAL_FALSE == g_FHC_DTS_waiting)   // the calling command is RF_TEST_CMD_START_FDT_DL_AND_WAIT_RESULT
        {
            ft_rfDATA.result_ready = KAL_TRUE;
        }
        else
        {
            // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
            ft_rfDATA.result_ready = KAL_FALSE;
            ft_gl_token = ft_gl_rf_token;
            ptrMsg->param.dts_get_result_status= DTS_RESULT_READY;
            /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
            FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
        }
        ft_rfDATA.wait_cnf = KAL_FALSE;
    } //endif of ft_rfDATA.wait_cnf != FALSE

    // release the buffer we allocate before
    if(ft_rfDATA.pDTSBuf != NULL)
    {
        free_ctrl_buffer(ft_rfDATA.pDTSBuf);
        ft_rfDATA.pDTSBuf = NULL;
    }
}

void FT_ReportUTS(void)
{
    ft_rf_test_cnf_T* ptrMsg;
    ilm_struct* ilm_ptr;

    if(ft_rfDATA.wait_cnf != KAL_FALSE)
    {
        // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
        ft_gl_token = ft_gl_rf_token;

        ilm_ptr = FT_ALLOC_MSG( sizeof(ft_rf_test_cnf_T) );
        ptrMsg=(ft_rf_test_cnf_T*)ilm_ptr->local_para_ptr;
        /* if ptrMsg != NULL*/
        ptrMsg->header.ft_msg_id = FT_RF_TEST_CNF_ID;
        ptrMsg->type             = ft_rfDATA.type;

        // about ResultDSSPL
        ptrMsg->param.ok = KAL_TRUE;

        /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
        FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr);
        ft_rfDATA.wait_cnf = KAL_FALSE;

    } //endif of ft_rfDATA.wait_cnf != FALSE

    // release the buffer we allocate before
    if(ft_rfDATA.pUTSBuf != NULL)
    {
        free_ctrl_buffer(ft_rfDATA.pUTSBuf);
        ft_rfDATA.pUTSBuf = NULL;
    }

}
#endif //#if  IS_FHC_SUPPORT == 1
kal_uint32 FT_L1RfCheckFunctionSuppported(kal_uint32 query_op_code)
{
    kal_uint32 cnf_code = FT_CNF_FAIL;
    if( RF_TEST_CMD_END > query_op_code )
    {
        switch(query_op_code)
        {
            /*************************************
             * Common commands
             ************************************/
            case RF_TEST_CMD_PM:
            case RF_TEST_CMD_AFC:
            case RF_TEST_CMD_NB_TX:
            case RF_TEST_CMD_CONTINUOUS_RX:
            case RF_TEST_CMD_CONTINUOUS_TX:
            case RF_TEST_CMD_BAND_SEL:
            case RF_TEST_CMD_STOP:
            case RF_TEST_CMD_SET_RAMPAPCLVL:
            case RF_TEST_CMD_SET_AFCDACVALUE:
            case RF_TEST_CMD_BBTX_AUTOCAL:
            case RF_TEST_CMD_SET_RAMPTABLE:
            case RF_TEST_CMD_SET_AFC_SINWAVE_DETECTION:
            case RF_TEST_CMD_GET_RFID:
            case RF_TEST_CMD_SET_IMMEDIATE_BSI:
            case RF_TEST_CMD_GET_IMMEDIATE_BSI:
            case RF_TEST_CMD_SET_SPECIALCOEF:
            case RF_TEST_CMD_IF_TWO_APC_DC_OFFSET_SUPPORT:
            case RF_TEST_CMD_GET_AFCDACVALUE_AT_RTX_OFFSET_CAL:
            case RF_TEST_CMD_CALIBRATE_32K:
            case RF_TEST_CMD_QUERY_MS_CAPABILITY_EX2:
            case RF_TEST_CMD_GET_AFC_DAC_OFFSET:
            case RF_TEST_CMD_SET_AFC_DAC_OFFSET:
            case RF_TEST_CMD_OE_PATTERN_READY:
            case RF_TEST_CMD_POWER_ON:
            case RF_TEST_CMD_POWER_OFF:
            case RF_TEST_CMD_QUERY_POWER_STATE_IN_FT:
            case RF_TEST_CMD_GET_SPECIALCOEF:
            case RF_TEST_CMD_QUERY_MS_CAPABILITY_EX3:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
            /*************************************
             * phased-out commands
             ************************************/
            case RF_TEST_CMD_QUERY_MS_CAPABILITY:
            case RF_TEST_CMD_QUERY_MS_CAPABILITY_EX:
            case RF_TEST_CMD_AFC_TYPE_QUERY_READY:
            case RF_TEST_CMD_NSFT_START_EPSK_TX:
            {
                cnf_code = FT_CNF_FAIL;
                break;
            }
            /*************************************
             * BBTXCFG commands
             ************************************/
            case RF_TEST_CMD_SET_BB_TX_CFG:
            {
                int type = L1TST_GetBBTXVer();
                if(type ==1)
                    cnf_code = FT_CNF_OK;
                break;
            }
            case RF_TEST_CMD_SET_BBTXCFG2:
            case RF_TEST_CMD_GET_BBTXCFG2:
            {
                int type = L1TST_GetBBTXVer();
                if(type ==2)
                    cnf_code = FT_CNF_OK;
                break;
            }
            case RF_TEST_CMD_SET_BBTXCFG3:
            case RF_TEST_CMD_GET_BBTXCFG3:
            {
                int type = L1TST_GetBBTXVer();
                if(type ==3)
                   cnf_code = FT_CNF_OK;
                break;
            }
            case RF_TEST_CMD_SET_BBTXCFG4:
            case RF_TEST_CMD_GET_BBTXCFG4:
            {
                int type = L1TST_GetBBTXVer();
                if(type ==4)
                    cnf_code = FT_CNF_OK;
                break;
            }
            case RF_TEST_CMD_SET_BBTXCFG5:
            case RF_TEST_CMD_GET_BBTXCFG5:
            {
                int type = L1TST_GetBBTXVer();
                if(type ==5)
                    cnf_code = FT_CNF_OK;
                break;
            }
            case RF_TEST_CMD_SET_BBTXCFG6:
            case RF_TEST_CMD_GET_BBTXCFG6:
            {
                int type = L1TST_GetBBTXVer();
                if(type ==6)
                    cnf_code = FT_CNF_OK;
                break;
            }
            /*************************************
             * GPRS commands
             ************************************/
#if defined(__PS_SERVICE__)
            case RF_TEST_CMD_MULTISLOT_TX:
            case RF_TEST_CMD_SET_TX_POWER_ROLLBACK_GMSK:
            case RF_TEST_CMD_SET_TX_POWER_ROLLBACK_TABLE_GMSK:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
            /*************************************
             * EGPRS commands
             ************************************/
#if defined(__EGPRS_MODE__)
            case RF_TEST_CMD_MULTISLOT_TX_EX:
            case RF_TEST_CMD_EPSK_SET_RAMPAPCLVL:
            case RF_TEST_CMD_CONTINUOUS_TX_EX:
            case RF_TEST_CMD_CONTINUOUS_TX_EX2:
            case RF_TEST_CMD_SET_TX_POWER_ROLLBACK_EPSK:
            case RF_TEST_CMD_SET_TX_POWER_ROLLBACK_TABLE_EPSK:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if defined(__EGPRS_MODE__)
#if defined(__EGPRS_TX__)
#endif // #if defined(__EGPRS_TX__)
            case RF_TEST_CMD_EPSK_SET_RAMPTABLE:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if defined(__PS_SERVICE__)
            /*************************************
             * FHC commands
             ************************************/
#if IS_FHC_SUPPORT == 1
            case RF_TEST_CMD_START_FDT_DL:
            case RF_TEST_CMD_START_FDT_DL_BIG:
            case RF_TEST_CMD_START_FDT_UL:
            case RF_TEST_CMD_START_FDT_UL_BIG:
            case RF_TEST_CMD_GET_FDT_RESULT:
            case RF_TEST_CMD_GET_FDT_RESULT_BIG:
            case RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT:
            case RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_BIG:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if IS_FHC_SUPPORT == 1
            /*************************************
             * NSFT commands
             ************************************/
#if IS_NSFT_SUPPORT == 1
            case RF_TEST_CMD_NSFT_CHANGE_SETTING:
            case RF_TEST_CMD_NSFT_START:
            case RF_TEST_CMD_NSFT_STOP:
            case RF_TEST_CMD_NSFT_CHANGE_POWER:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#if IS_SINGLE_END_BER_SUPPORT == 1
            case RF_TEST_CMD_NSFT_CONFIG_SBER:
            case RF_TEST_CMD_NSFT_GET_SBER:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if IS_SINGLE_END_BER_SUPPORT == 1
            case RF_TEST_CMD_NSFT_START_RXLEV:
            case RF_TEST_CMD_NSFT_GET_RXLEV:
            case RF_TEST_CMD_NSFT_GET_RXQUAL:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#if IS_NSFT_SACCH_TEST_ITEM_SUPPORT == 1
#endif // #if IS_NSFT_SACCH_TEST_ITEM_SUPPORT == 1
#endif // #if IS_NSFT_SUPPORT == 1
#if IS_W_CANCELLATION_SUPPORT == 1
            case RF_TEST_CMD_IF_PM:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if IS_W_CANCELLATION_SUPPORT == 1
#if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
            case RF_TEST_CMD_GET_TXPC_PD_VALUE_BY_PCL_GMSK:
            case RF_TEST_CMD_GET_TXPC_PD_VALUE_GMSK:
            case RF_TEST_CMD_GET_TXPC_SUBBAND_GMSK:
            case RF_TEST_CMD_GET_TXPC_TEMPERATURE:
#if defined(__EPSK_TX__)
            case RF_TEST_CMD_GET_TXPC_PD_VALUE_BY_PCL_EPSK:
            case RF_TEST_CMD_GET_TXPC_PD_VALUE_EPSK:
            case RF_TEST_CMD_GET_TXPC_SUBBAND_EPSK:
#endif // #if defined(__EPSK_TX__)
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if defined(__2G_TX_POWER_CONTROL_SUPPORT__)
#if defined(__F32_XOSC_REMOVAL_SUPPORT__)
            case RF_TEST_CMD_SET_DCXO_POWER_MODE:
            case RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX:
            case RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX_BIG:
            case RF_TEST_CMD_GET_FDT_RESULT_EX:
            case RF_TEST_CMD_GET_FDT_RESULT_EX_BIG:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
#endif // #if defined(__F32_XOSC_REMOVAL_SUPPORT__)
            case RF_TEST_CMD_MULTISLOT_TX_WITH_AUXADC_READ:
            case RF_TEST_CMD_GAIN_RF_TX:
            case RF_TEST_CMD_QUERY_GAIN_RF_NUM:
            case RF_TEST_CMD_GET_BB_POWER_LIST:
            case RF_TEST_CMD_CHECK_IF_FUNC_EXIST:
            case RF_TEST_CMD_GET_TEMPERATURE_INFO:
            {
                cnf_code = FT_CNF_FAIL;
                break;
            }
            default:
                cnf_code = FT_CNF_FAIL;
                break;
        }
    }
    else
    {
        cnf_code = FT_CNF_FAIL;
    }
    return cnf_code;
}
