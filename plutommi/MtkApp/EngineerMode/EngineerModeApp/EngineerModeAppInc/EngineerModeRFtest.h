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
 *  EngineerModeRFTest.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_EM_RF_TEST_H
#define MMI_EM_RF_TEST_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

#include "inlinecuigprot.h"

#if defined(__MMI_EM_RF_GSM__) || defined(__MMI_EM_RF_WIFI__)
/* RF Test Tool */
extern void EmRFTestDisableSleepMode(void);
extern void EmRFTestEnableSleepMode(void);
extern void EmRFTestToolSleepModeHdlr(void* inMsg);
extern void ExitEmRFTestInlineSelectScreen(void);
#endif 

#ifdef __MMI_EM_RF_GSM__ 
/* RF Test Tool -- GSM */
extern void EmStopRFTestGsm(void);
extern void HighlightRFTestGSM(void);
extern void EntryRFTestGSMEnterCondirm(void);
extern void EmRFTestGSMEnterFlightMode(void);
extern void EntryEmRFTestGSM(void);
extern void EmRFTestGSMExitFlightMode(void);
/* RF Test Tool -- GSM TX Test */
extern void HighlightRFTestGSMTxTest(void);
extern void EntryEmRFTestGSMTxTest(void);
extern void HighlightHandlerRFGSMTxInline(S32 index);
extern void HighlightHandlerRFGSMBandInline(S32 index);
extern void EMRFGSMTXTestCheckAndSendReq(void);
/* RF Test Tool -- GSM RX Test */
extern void HighlightRFTestGSMRxTest(void);
extern void EntryEmRFTestGSMRxTest(void);
extern void HighlightHandlerRFGSMRxInline(S32 index);
extern void EMRFTestGsmRXTestTimeoutHdlr(void);
/* RF Test Tool -- GSM Power Save */
extern void EMRFGSMPowerScanFunc(mmi_menu_id menu_id);
extern void EntryEMRFGSMPowerScanRsp(PS16 arfcn, PS16 power);
/* RF Test Tool -- GSM Common function */
extern MMI_BOOL check_gsm_arfcn_valid(void);
#endif /* #ifdef __MMI_EM_RF_GSM__ */

#if defined(__MMI_EM_RF_WIFI__)
/* RF Test Tool -- WiFi */
extern void EmStopRFTestWiFi(void);
extern void HighlightRFTestWiFi(void);
extern void EntryRFTestWifiEnterCondirm(void);
extern void EmRFTestWifiEnterFlightMode(void);
extern void EntryEmRFTestWiFi(void);
extern void EmRFTestWifiExitTestMode(void);
/* RF Test Tool -- WiFi Tx Test */
/* RF Test Tool -- WiFi Tx Test -- DAC */
/* RF Test Tool -- WiFi Tx Test -- Output Power */
/* RF Test Tool -- WiFi Tx Test -- Carrier Supp */
/* RF Test Tool -- WiFi Tx Test -- Local Freq. */
extern void HighlightRFTestWiFiTXLocalFreq(void);
extern void EntryEmRFTestWiFiTxLocalFreq(void);
extern void HighlightHandlerRFWifiTxLocalFreqInline(S32 index);
extern void EMRFTESTWifiTXLocalFreqCheckAndSendReq(cui_event_inline_common_struct* inline_evt);
extern void EntryEMRFTESTWifiTXLocalFreqDone(void);
/* RF Test Tool -- WiFi Tx Test -- TX Cont PKT */
extern void HighlightRFTestWiFiTXContPKT(void);
extern void EntryEmRFTestWiFiTxContPKT(void);
extern void HighlightHandlerRFWifiTxContPKTInline(S32 index) ;
extern void EMRFTESTWifiTXContPKTCheckAndSendReq(cui_event_inline_common_struct* inline_evt);
extern void EntryEMRFTESTWifiTXContPKTDone(void);
/* RF Test Tool -- WiFi Tx Tests Common function */
extern MMI_BOOL EMRFWifiTXCommonCheckAndSendReq(cui_event_inline_common_struct* inline_evt) ;
extern void EMRFWifiTxFillInlineStruct(void);
extern void EMRFWifiTxFillInlineStructForView(void);
/* RF Test Tool -- Wifi RX */
extern void HighlightRFTestWiFiContPKTRx(void);
extern void EntryEmRFTestWiFiRxContPKT(void);
extern void HighlightHandlerRFWifiRxContPKTInline(S32 index) ;
extern void EMRFTESTWifiRXContPKTSendReq(void);
extern void EntryEmRFTestWiFiRXContPKTRsp(U8 *response);
/* RF Test Tool -- Wifi Power Save */
extern void HighlightRFTestWiFiPowerSave(void);
extern void EntryEmRFTestWiFiPowerSave(void);
extern void HighlightHandlerRFWifiPowerSaveInline(S32 index);
extern void EMRFTESTWifiPowerSaveSendReq(void);
extern void EntryEmRFTestWiFiPowerSaveDone(void);
extern void ExitEmRFTestWiFiPowerSaveDone(void);
/* RF Test Tool -- Wifi Register Access */
extern void HighlightRFTestWiFiRegisterAccess(void);
extern void EntryEmRFTestWiFiRegisterAccess(void);
/* RF Test Tool -- Wifi Register Access -- MCR */
extern void HighlightRFTestWiFiRegisterMCR(void);
extern void EntryEmRFTestWiFiRegisterMCR(void);

extern void EntryEmRfTestWifiMCRFullScreenEditorOptions(void);
extern void EmRFTestWifiRegMCROpenFullScreenEdit(void);
extern void ExitEmRFTestWiFiRegisterMCR(void);

extern void HighlightRFWifiRegMCRAccessInline(S32 index);
extern void HighlightHandlerRFWifiRegMCRInline(S32 index);
extern void EMRFTESTWifiRegMCRSendReq(cui_event_inline_common_struct* inline_evt);
extern void EntryEmRFTestWiFiRegMCRAccessRsp(U32 mcr_data);
/* RF Test Tool -- Wifi Register Access -- BBCR */
extern void HighlightRFTestWiFiRegisterBBCR(void);
extern void EntryEmRFTestWiFiRegisterBBCR(void);
extern void HighlightRFWifiRegBBCRAccessInline(S32 index);
extern void HighlightHandlerRFWifiRegBBCRInline(S32 index);
extern void EMRFTESTWifiRegBBCRSendReq(cui_event_inline_common_struct *evt);
extern void EntryEmRFTestWiFiRegBBCRAccessRsp(U32 bbcr_data);
/* RF Test Tool -- Wifi Register Access -- EEPROM */
extern void HighlightRFTestWiFiRegisterEEPROM(void);
extern void EntryEmRFTestWiFiRegisterEEPROM(void);
extern void HighlightRFWifiRegEEPROMAccessInline(S32 index);
extern void HighlightHandlerRFWifiRegEEPROMInline(S32 index);
extern void EMRFTESTWifiRegEEPROMSendReq(cui_event_inline_common_struct* evt);
extern void EntryEmRFTestWiFiRegEEPROMAccessRsp(U32 eeprom_data);
#endif  /* defined(__MMI_EM_RF_WIFI__) */


#ifdef __MMI_EM_RF_GSM__ 
extern void EMRFTestGSMInitContext(void);
extern void EMRFTestGsmSendReq(void);
extern void EMRFTestGsmSendRes(void* inMsg);
#endif /* #ifdef __MMI_EM_RF_GSM__ */

#if defined(__MMI_EM_RF_WIFI__)
extern void EMRFTestWiFiInitContext(void);
extern void EMRFTestWiFiSendReq(void);
extern void EMRFTestWifiSendRes(void* inMsg);
#endif  /* defined(__MMI_EM_RF_WIFI__) */

#if defined(__MMI_EM_RF_GSM__) || defined(__MMI_EM_RF_WIFI__)
extern void mmi_em_rf_test_menu_event_hdlr(cui_menu_event_struct *event);
extern void mmi_em_rf_test_tool_menu_list_exit_hdlr(cui_menu_event_struct *event);
#endif /* defined(__MMI_EM_RF_GSM__) || defined(__MMI_EM_RF_WIFI__)*/


#endif /* MMI_EM_RF_TEST_H */ 



