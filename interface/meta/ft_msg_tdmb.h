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
 *   ft_msg_tdmb.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of TDMB category of FT Library
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_TDMB_H__
#define __FT_MSG_TDMB_H__
#include "ft_msg_common.h"

/*******************************************************************************
*
*  Message structures defined for TDMB Command
*
*******************************************************************************/
#if defined(__TDMB_SUPPORT__)
#include "tdmb_if.h"

typedef enum
{
      FT_TDMB_OP_TURN_ON = 0
   ,FT_TDMB_OP_TURN_OFF
   ,FT_TDMB_OP_SET_BAND
   ,FT_TDMB_OP_AUTO_SCAN
   ,FT_TDMB_OP_SET_FREQ
   ,FT_TDMB_OP_SEL_SERV
   ,FT_TDMB_OP_GET_SIGNAL
   ,FT_TDMB_OP_GET_ENSM_INFO_BY_AUTO_SCAN
   ,FT_TDMB_OP_SET_IDLE
   ,FT_TDMB_OP_GET_ENSM
   ,FT_TDMB_OP_SEL_SERV_ONLY
   ,FT_TDMB_OP_STOP_AUTO_SCAN
   ,FT_TDMB_OP_END

}FT_TDMB_CMD_TYPE;


typedef enum
{
   META_TDMB_KOREA_BAND=1,
   META_TDMB_BAND_III,
   META_TDMB_L_BAND,
   META_TDMB_CANADA_BAND,
   META_TDMB_CHINESE_BAND,
   META_TDMB_BAND_II,
   META_TDMB_BAND_IF,
   META_TDMB_UNDEF_BAND
}META_TDMB_BAND_enum;

typedef struct
{
    META_TDMB_BAND_enum  m_rBand;

}TDMB_SET_BAND_REQ_T;
/*
typedef struct
{
    kal_int8 m_cResult;
}TDMB_SET_BAND_CNF_T;
*/
typedef struct
{
    kal_uint8   m_ucFreqNum;
    kal_uint32  m_u4Freq[10];

}TDMB_AUTO_SCAN_CNF_T;

typedef struct
{
   kal_uint32  m_u4Freq;
}TDMB_SET_FREQ_REQ_T;
/*
typedef struct
{
   kal_int8 m_cResult;

}TDMB_SET_FREQ_CNF_T;
*/
// Ensemble =========
typedef struct
{

    kal_uint8     m_ucStateNum;
    kal_uint32      m_u4State[10];

    kal_uint32    Type;
    kal_uint32      Id;
    kal_uint32      BitRate;
    kal_uint8         PL;
    kal_uint8         Reg[8];
    kal_uint16      UserApplType;

    kal_uint32      TMId;
    kal_uint32      ASCTy_DSCTy;
    kal_uint32      SCId;
    kal_uint32      PackAdd;
    kal_uint32      DG_MFflag;
    kal_uint32      Primary;
    kal_uint32      CAflag;
    kal_uint32      Language;
    kal_int8          SCLabel[16];

  //TDMB_SvcComponentInfo    *pSvcComp;
    kal_uint8         SvcComp_Order;
    kal_uint8         SvcComp_TMId;
    kal_uint8         SvcComp_ASCTy_DSCTy;
    kal_uint8         SvcComp_SubCh_FIDCId;
    kal_uint32      SvcComp_SId;
    kal_uint8         SvcComp_CAflag;
    kal_uint8         SvcComp_DG_MFflag;
    kal_uint8         SvcComp_Language;
    kal_uint8         SvcComp_SCIdS;
    kal_uint8     SvcComp_SvcCompLabel[16];// 16bytes Service component Label

    kal_uint16      SvcComp_SCId;
    kal_uint16      SvcComp_PackAdd;
    kal_uint16      SvcComp_SCCA;

    kal_uint16    SvcComp_m_encoded_id;   // Only for Frontier
  kal_uint8     SvcComp_m_sif;          // Only for Frontier

    kal_uint8       SubChId;
    kal_uint8       TblIndex;
    kal_uint8       Form_Opt_Prot;
    kal_uint16    StrtAdd;
    kal_uint16    SubChSize;

    kal_uint32      Tag;

}TDMB_CHANNELDB_T;


typedef struct
{

    kal_uint8     m_ucStateNum;
    kal_uint32      m_u4State[10];

    kal_uint32      Id;
    kal_int8          Label[20];

  //TDMB_ServiceInfo       *pService;
    kal_uint32      SId;
    kal_uint8         SvcLabel[16];
    kal_uint16      CharacterFlag;
    kal_uint8         CAId;
    kal_uint8         NumSvcComp;

  kal_uint8     m_ucChannelDBNum;
    //TDMB_CHANNELDB_T    m_rChannelDB[10];

    kal_uint32      Tag;
    kal_uint32      ChannelCount;


}TDMB_SERVICEDB_T;

typedef struct
{

    kal_uint8      m_ucStateNum;
    kal_uint32       m_u4State[10];

    kal_uint32       Band;
  kal_uint32         Frequency;
  kal_uint16         Id;
  kal_uint32         SvcNum;
  kal_uint32         SvcCompNum;
  kal_uint32         SubChNum;
    kal_int8         Label[20];

  // TDMB_EnsembleInfo  *pEnsemble;
    kal_uint8        AlFlag;
    kal_uint8      NumSubCh;
    kal_uint8      NumSvc;
    kal_uint8        NumProgram;
    kal_uint8      NumSvcComp;
    kal_uint8        NumUserApp;
    kal_uint8        NumAnn;
    kal_uint8        NumProgType;
    kal_uint8        EnsemLabel[16];
    kal_uint16     CharacterFlag;
    kal_uint16     EId;

    kal_uint8      m_ucServiceDBNum;
    //TDMB_SERVICEDB_T  m_rServiceDB[10];
  kal_uint32     Tag;
}TDMB_ENSEMBLEDB_T;

typedef union
{
    TDMB_ENSEMBLEDB_T  m_rEnsmDB[10];
      TDMB_SERVICEDB_T    m_rServDB[10];
    TDMB_CHANNELDB_T    m_rChanDB[10];
}TDMB_ENSM_INFO_U;

typedef struct
{
    TDMB_ENSM_INFO_U     m_rEnsmInfo;

}TDMB_ENSM_INFO_T ;





typedef struct
{
    kal_uint16   m_u2Snr;
//  kal_uint16   m_u2PostBer;  // not used so far, so return 0
//  kal_uint16   m_u2PreBer;
    kal_uint8  m_ucBer_a;
    kal_uint8    m_ucBer_b;
    kal_uint8    m_ucBer_c;
    kal_int16   m_i2RSSI;
}TDMB_GET_SIGNAL_CNF_T;

typedef struct
{
    kal_uint8    m_ucCmdType;   // 0: select service, 1: selervice service only(drop data)
    kal_uint32   m_u4ServiceId;
    kal_uint32   m_u4SubChnId;
    FS_HANDLE      fs_handle;
    kal_int32    m_i4MetaHandle;
    kal_uint32   m_u4Offset;

}TDMB_SEL_SERVICE_REQ_T;


//#define Ft_Max_TDMB_Buf_Len 1692  // 188's mutiplies
typedef struct
{
    kal_uint8    m_ucCnfType;// 0: select service
                             // 1: error occurred in storing the Raw Data in FAT
                             // 2: error occurred in storing data in memory
                             // 3: get data from memory

    kal_int8     m_cResult; // 0: success

    FS_HANDLE      fs_handle;
    kal_int32    m_i4MetaHandle;

    // only work  m_ucCnfType == 3
    kal_uint32   m_u4DataSize;
    kal_uint32   m_u4Offset;
    kal_uint8    m_ucRecvAll;

}TDMB_SEL_SERVICE_CNF_T;

typedef struct
{
   kal_int8                   m_cResult; // 0: success, -1: fail
   kal_int8                   m_cCurEns;
   kal_uint8                  m_ucDataType;
   kal_uint8                  m_ucNum;
   kal_uint8                  m_ucEnsembleIndex[10];
   kal_uint8                  m_ucServiceIndex[10];
   kal_uint8                  m_ucChannelIndex[10];
   kal_uint8                  m_ucErrorNum;
   kal_uint8                  m_ucErrorCode[10];

   kal_bool                   m_bRecvAll;
}TDMB_ENSM_ALL_CNF_T;


typedef struct
{
   kal_uint32                 m_u4DataSize;
}TDMB_SET_IDLE_CNF_T;


typedef union
{
    TDMB_SET_BAND_REQ_T     m_rBand;
    TDMB_SET_FREQ_REQ_T     m_rSetFreq;
    TDMB_SEL_SERVICE_REQ_T  m_rSelServ;

}META_TDMB_CMD_U;

typedef union
{
      //TDMB_SET_BAND_CNF_T              m_rSetBandResult;
    TDMB_AUTO_SCAN_CNF_T             m_rAutoScanGetFreq;
    TDMB_GET_SIGNAL_CNF_T            m_rGetSignalResult;
    TDMB_SEL_SERVICE_CNF_T           m_rSelServResult;
    TDMB_ENSM_ALL_CNF_T              m_rEnsmAllResult;
    TDMB_SET_IDLE_CNF_T              m_rSetIdleResult;

}META_TDMB_CNF_U;


typedef struct
{
    FT_H               header;
    FT_TDMB_CMD_TYPE   type;
    META_TDMB_CMD_U    cmd;

}FT_TDMB_REQ;

typedef struct
{
    FT_H                header;
    FT_TDMB_CMD_TYPE      type;
    META_TDMB_CNF_U     result;
      kal_uint32                  status;
}FT_TDMB_CNF;

/*
typedef union
{
      tdmb_turn_on_request_struct  m_rTurnOn;
}FT_TDMB_ALL_STRUCT_T;
*/

#endif  // __TDMB_SUPPORT__

#endif // #ifndef __FT_MSG_TDMB_H__
