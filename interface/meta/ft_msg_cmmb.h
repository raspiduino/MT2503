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
 *   ft_msg_cmmb.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of CMMB category of FT Library
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_CMMB_H__
#define __FT_MSG_CMMB_H__
#include "ft_msg_common.h"

/*******************************************************************************
*
*  Message structures defined for CMMB Command
*
*******************************************************************************/
#define   META_CMMB_FRAME_INFO_NUM 20

typedef enum
{
    FT_CMMB_OP_TURN_ON = 0
   ,FT_CMMB_OP_TURN_OFF
   ,FT_CMMB_OP_SET_BAND
   ,FT_CMMB_OP_AUTO_SCAN_TO_GET_FREQ
   ,FT_CMMB_OP_GET_FRAME_INFO_BY_AUTO_SCAN
   ,FT_CMMB_OP_STOP_AUTO_SCAN
   ,FT_CMMB_OP_SET_FREQ
   ,FT_CMMB_OP_SEL_SERV_ONLY
   ,FT_CMMB_OP_PAUSE_SERV
   ,FT_CMMB_OP_GET_SIGNAL
   ,FT_CMMB_OP_AUTO_SCAN_WITH_FREQ_RANGE
   ,FT_CMMB_OP_END

}META_CMMB_CMD_TYPE;

typedef enum
{
   META_CMMB_CHINA_U_BAND=0
  ,META_CMMB_TAIWAN_BAND
  ,META_CMMB_UNDEF_BAND

}META_CMMB_BAND_enum;

typedef struct
{
    META_CMMB_BAND_enum  m_rBand;
}META_CMMB_SET_BAND_REQ_T;


typedef struct
{
    kal_uint8    m_u1FrmId;
    kal_uint16   m_u2ServId;
}META_CMMB_SEL_SERV_REQ_ONLY_T;

typedef struct
{
    kal_uint8    m_u1FrmId;
    kal_uint16   m_u2ServId;
}META_CMMB_PAUSE_SERV_REQ_T;


typedef struct
{
   kal_uint8   m_u1StartFreqPointId;
   kal_uint8   m_u1EndFreqPointId;
}META_CMMB_FREQ_RANGE_FOR_AUTO_SCAN_REQ_T;


typedef union
{
    META_CMMB_SET_BAND_REQ_T                  m_rBand;
    kal_uint8                                 m_u1FreqPointId;
    META_CMMB_SEL_SERV_REQ_ONLY_T             m_rSelServ;
    META_CMMB_PAUSE_SERV_REQ_T                m_rPauseServ;
    META_CMMB_FREQ_RANGE_FOR_AUTO_SCAN_REQ_T  m_rAutoScanWithFreqRange;

}META_CMMB_CMD_U;

typedef struct
{
    kal_uint8                    m_u1RecvAllFrame;
    kal_uint8                    m_u1HasFrameInfo;  // used to check if we need to decode peer buffer
    kal_uint8                    m_u1FrameIndex;
    kal_uint8                    m_u1FrameNumSoFar;
}META_CMMB_AUTO_SCAN_CNF_T;

typedef struct
{
    kal_uint8                    m_u1RecvAllFrame;
    kal_uint8                    m_u1HasFrameInfo;
    kal_uint8                    m_u1FrameIndex;
    kal_uint8                    m_u1FrameNumSoFar;
}META_CMMB_SET_FREQ_CNF_T;


typedef struct
{
    kal_uint8   m_u1FreqPointId;
    kal_int8    m_i1Rssi;                 // unit: -dBm 0~100, 0 is best  , -1 means no such kinds of value
    kal_int8    m_i1Snr;                  // unit: dBm  0~100, 100 is best, -1 means no such kinds of value
    kal_int8    m_i1CurLdpcErrPercent;    // unit: %    0~100, 0 is best  , -1 means no such kinds of value
    kal_int32   m_i4TotalLdpcErrCnt;      // unit: -1 means no such kinds of value
    kal_int32   m_i4TotalLdpcCnt;         // unit: -1 means no such kinds of value
    kal_int32   m_i4CurRsErrorCnt;     // unit: -1 means no such kinds of value
    kal_int32   m_i4TotalRsErrorCnt;   // unit: -1 means no such kinds of value
    /* Added in W1112 */
    kal_int32   m_i4InBandPwr;
    kal_uint32  m_u4IsDemodLocked;
    kal_uint8   m_u1ReceptionQuality;
    kal_uint32  m_u4signal_strength_indication;
}META_CMMB_GET_SIGNAL_STRENGTH_CNF_T;

typedef union
{
   META_CMMB_AUTO_SCAN_CNF_T            m_rAutoScan;     // the detailed information is put in peer buffer
   META_CMMB_SET_FREQ_CNF_T             m_rSetFreqResult;
   META_CMMB_GET_SIGNAL_STRENGTH_CNF_T  m_rGetSSResult;
}META_CMMB_CNF_U;

typedef struct
{
    FT_H                header;
    META_CMMB_CMD_TYPE  type;
    META_CMMB_CMD_U     cmd;
}FT_CMMB_REQ;

typedef struct
{
    FT_H               header;
    META_CMMB_CMD_TYPE type;
    kal_uint8          status;
    META_CMMB_CNF_U    result;
}FT_CMMB_CNF;
#define   META_CMMB_FREQ_BAND_NUM    4
#define META_CMMB_BLK_NUM            8
#define META_CMMB_SERV_BLOCK_NUM     20
#define META_CMMB_DATA_BLK_NUM       128

typedef struct
{
    kal_uint8   m_u1FreqPointId;
    kal_uint8   m_u1BandWidth;
    kal_uint32  m_u4Freq;
}META_CMMB_FreqBandStruct_T;

typedef struct
{
    kal_uint8                    m_u1MainFreqNum;
    kal_uint8                    m_u1MainFreqWeCarry;
    META_CMMB_FreqBandStruct_T   m_rMainFreqBand[META_CMMB_FREQ_BAND_NUM];
}META_CMMB_AUTO_SCAN_GET_FREQ_CNF_T;  // will be put into peer buffer

//==================================================================



typedef struct // around 58 *4 bytes
{
    kal_uint8                    Nit_NitUpdateSeq;
    kal_uint8                    Nit_SysTime[5];
    kal_uint32                   Nit_CountryCode ;
    kal_uint8                    Nit_Net_NetLevel;
    kal_uint16                   Nit_Net_NetId;
    kal_uint8                    Nit_NetNameLen  ;
    kal_uint8                    Nit_NetName[128];
    kal_uint8                    Nit_FreqBand_FreqPointId;
    kal_uint8                    Nit_FreqBand_BandWidth;
    kal_uint32                   Nit_FreqBand_CenterFreq;
    kal_uint8                    Nit_OtherFreqNum;    // at most 4 here transferred by ft task.
    kal_uint8                    m_ucOtherFreqNumWeCarry;
    kal_uint8                    Nit_OtherFreqBandList_FreqPointId[META_CMMB_BLK_NUM];
    kal_uint8                    Nit_OtherFreqBandList_BandWidth[META_CMMB_BLK_NUM];
    kal_uint32                   Nit_OtherFreqBandList_CenterFreq[META_CMMB_BLK_NUM];
    kal_uint8                    Nit_NeighborNetNum;  // at most 4 here transferred by ft task.
    kal_uint8                    m_ucNeightborNetWeCarray;
    kal_uint8                    Nit_NeighborNetList_NetLevel[META_CMMB_BLK_NUM];
    kal_uint16                   Nit_NeighborNetList_NetId[META_CMMB_BLK_NUM];
    kal_uint8                    Nit_NeighborNetList_FreqPointId[META_CMMB_BLK_NUM];
    kal_uint8                    Nit_NeighborNetList_BandWidth[META_CMMB_BLK_NUM];
    kal_uint32                   Nit_NeighborNetList_CenterFreq[META_CMMB_BLK_NUM];

}META_CMMB_NitStruct_T;

typedef struct  // about 27*4 bytes
{
    kal_uint8                        MctUpdateSeq;
    kal_uint8                        FreqPointId;
    kal_uint8                        MfNum;  // at most 4 here transferred by ft task.
    kal_uint8                        m_ucMfNumWeCarray;  // 0: none, 1: more
    kal_uint8                        Mf_MfId[META_CMMB_BLK_NUM];
    kal_uint8                        Mf_RsRate[META_CMMB_BLK_NUM];
    kal_uint8                        Mf_ByteInterleaveMode[META_CMMB_BLK_NUM];
    kal_uint8                        Mf_LdpcRate[META_CMMB_BLK_NUM];
    kal_uint8                        Mf_ModulationMode[META_CMMB_BLK_NUM];
    kal_uint8                        Mf_ScrambleMode[META_CMMB_BLK_NUM];
    kal_uint8                        Mf_TimeSlotNum[META_CMMB_BLK_NUM];
    kal_uint8                        m_ucMf_TimeSlotNumWeCarray[META_CMMB_BLK_NUM];
    kal_uint8                        Mf_TimeSlotId[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
    kal_uint8                        Mf_SubMfNum[META_CMMB_BLK_NUM];
    kal_uint8                        m_ucMf_SubMfNumWeCarry[META_CMMB_BLK_NUM];
    kal_uint8                        Mf_SubMfId[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
    kal_uint16                       Mf_serviceId[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
}META_CMMB_MctStruct_T;

typedef struct // about 16 * 4 bytes
{
    kal_uint8                    SctUpdateSeq;
    kal_uint16                   ServiceNum;
    kal_uint8                    m_u1ServiceNumWeCarray;  // at most 20 here transferred by ft task.
    kal_uint16                   ServiceId[META_CMMB_SERV_BLOCK_NUM];
    kal_uint8                    FreqPointId[META_CMMB_SERV_BLOCK_NUM];
}META_CMMB_SctStruct_T;

typedef struct  // around 20*4 bytes
{
    kal_uint8                   EsgUpdateSeq;
    kal_uint8                   NetLevel;
    kal_uint16                  NetId;
    kal_uint8                   LocalTimeOffset;
    kal_uint8                   CharSet;
    kal_uint8                   EsgServiceNum;
    kal_uint8                   m_ucEsgServiceNumWeCarry;
    kal_uint8                   EsgService_EsgServiceIndex[META_CMMB_BLK_NUM];
    kal_uint16                  EsgService_EsgServiceId[META_CMMB_BLK_NUM];
    kal_uint8                   EsgDataNum;
    kal_uint8                   m_ucEsgDataNumWeCarry;
    kal_uint8                   EsgData_EsgDataType[META_CMMB_BLK_NUM];
    kal_uint8                   EsgData_EsgDataBlockNum[META_CMMB_BLK_NUM];
    kal_uint8                   m_ucEsgData_EsgDataBlockNumWeCarry[META_CMMB_BLK_NUM];
    kal_uint8                   EsgDataBlock_EsgDataBlockId[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
    kal_uint8                   EsgDataBlock_EsgDataBlockVersion[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
    kal_uint8                   EsgDataBlock_EsgServiceIndex[META_CMMB_BLK_NUM][META_CMMB_BLK_NUM];
}META_CMMB_EsgListStruct_T;

typedef struct
{
    kal_uint8             CaUpdateSeq;
    kal_uint16            CaDataNum  ;
    kal_uint8             m_ucCaDataNumWeCarry;
    kal_uint16            CaId[META_CMMB_BLK_NUM];
    kal_uint16            ServiceId[META_CMMB_BLK_NUM];
    kal_uint8             EMM_BlockUnitType[META_CMMB_BLK_NUM];
    kal_uint8             ECM_BlockUnitType[META_CMMB_BLK_NUM];
    kal_uint8             ECM_TransmissionType[META_CMMB_BLK_NUM];
}META_CMMB_CaListStruct_T;

typedef struct
{
    META_CMMB_NitStruct_T        m_rNit;  // around 58 *4 bytes
    META_CMMB_MctStruct_T        m_rCSmct[2];  // about 25*4 bytes * 2
    META_CMMB_SctStruct_T        m_rCSsct[2];  // [0] for Csct, [1] for Ssct
    kal_uint8   Eb_EbUpdateSeq;
    kal_uint8   Eb_EbMsgNum;
    kal_uint16  Eb_DataBlockLen;
    kal_uint8   m_ucDataBlockLenWeCarray;
    kal_uint8   Eb_DataBlock[META_CMMB_DATA_BLK_NUM];
    kal_uint8                   m_ucHasEsg;  // 0: no Esg, 1: has Esg information
    META_CMMB_EsgListStruct_T   m_rEsg;
    kal_uint8                   m_ucHasCa;
    META_CMMB_CaListStruct_T    m_rCa;
}META_CMMB_CtrlInfoTable_T;

typedef struct
{
    kal_uint8                    m_u1NitUpdateSeq;
    kal_uint8                    m_u1CmctUpdateSeq;
    kal_uint8                    m_u1SmctUpdateSeq;
    kal_uint8                    m_u1CsctUpdateSeq;
    kal_uint8                    m_u1SsctUpdateSeq;
    kal_uint8                    m_u1EsgUpdateSeq;
    kal_uint8                    m_u1FreqPointId;
    kal_uint8                    m_u1NetLevel;
    kal_uint16                   m_u2NetId;
    kal_uint8                    m_u1HasCtrlTable;  // 0: no, 1: yes
    META_CMMB_CtrlInfoTable_T    m_rCtrlTableInfo;
}META_CMMB_FrameInfo_T;  // mapping with CMMB_FrameStruct


#endif // #ifndef __FT_MSG_CMMB_H__
