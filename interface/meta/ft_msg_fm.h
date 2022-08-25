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
 *   ft_msg_fm.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of FM category of FT Library
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

#ifndef __FT_MSG_FM_H__
#define __FT_MSG_FM_H__
#include "ft_msg_common.h"

/*******************************************************************************
*
*  Message structures defined for FM Radio
*
*******************************************************************************/

typedef enum
{
      FT_FM_OP_READ_CHIP_ID = 0
   ,FT_FM_OP_POWER_ON
   ,FT_FM_OP_POWER_OFF
   ,FT_FM_OP_SET_FREQ
   ,FT_FM_OP_SET_MONO_STEREO_BLEND
   ,FT_FM_OP_GET_SIGNAL_VAL
   ,FT_FM_OP_GET_IF_CNT
   ,FT_FM_OP_SEARCH_NEXT_STAT
   ,FT_FM_OP_SEARCH_PREV_STAT
   ,FT_FM_OP_READ_ANY_BYTE
   ,FT_FM_OP_WRITE_ANY_BYTE
   ,FT_FM_OP_SOFT_MUTE_ONOFF
   ,FT_FM_OP_SELECT_SOFT_MUTE_STAGE
   ,FT_FM_OP_SELECT_STEREO_BLEND
   ,FT_FM_OP_SET_RSSI_THRESHOLD
   ,FT_FM_OP_SET_IF_CNT_DELTA
   ,FT_FM_OP_GET_H_L_SIDE
   ,FT_FM_OP_GET_STEREO_MONO
   ,FT_FM_OP_SET_VOLUME
   ,FT_FM_OP_FM_AUTOSCAN
   ,FT_FM_OP_SET_RDS
   ,FT_FM_OP_GET_RXFILTER_BW
   ,FT_FM_OP_GET_PAMD_LEVEL
   ,FT_FM_OP_GET_MR
   ,FT_FM_OP_SET_DECODE_MODE
   ,FT_FM_OP_SET_HCC
   ,FT_FM_OP_SET_PAMD_THRESHOLD
   ,FT_FM_OP_SET_SOFTMUTE
   ,FT_FM_OP_SET_DEEMPHASIS_LEVEL
   ,FT_FM_OP_SET_H_L_SIDE
   ,FT_FM_OP_SET_DEMOD_BW
   ,FT_FM_OP_SET_DYNAMIC_LIMITER
   ,FT_FM_OP_SET_SOFTMUTE_RATE
   ,FT_FM_OP_GET_PI
   ,FT_FM_OP_GET_PTY
   ,FT_FM_OP_GET_TP
   ,FT_FM_OP_GET_PS
   ,FT_FM_OP_GET_AF
   ,FT_FM_OP_GET_TA
   ,FT_FM_OP_GET_MS
   ,FT_FM_OP_GET_RT
   ,FT_FM_OP_GET_GOOD_BLOCK_COUNTER
   ,FT_FM_OP_GET_BAD_BLOCK_COUNTER
   ,FT_FM_OP_RESET_BLOCK_COUNTER
   ,FT_FM_OP_GET_GROUP_COUNTER
   ,FT_FM_OP_RESET_GROUP_COUNTER
   ,FT_FM_OP_HWSEEK
   ,FT_FM_OP_HWSEARCH_STOP
   ,FT_FM_OP_SET_STEREO_BLEND
   ,FT_FM_OP_GET_RDS_LOG
   ,FT_FM_OP_GET_RDS_BLER
   ,FT_FM_OP_GET_ANTENNA_TYPE
   ,FT_FM_OP_SET_ANTENNA_TYPE
   ,FT_FM_OP_QUERY_CAP_ARRAY
   ,FT_FM_OP_END

}FT_FM_CMD_TYPE;


typedef struct
{
    kal_uint8 m_ucChipId;
}FM_CHIP_ID_CNF_T;

typedef struct
{
    kal_int16 m_i2CurFreq;

}FM_FREQ_REQ_T;



typedef struct
{
    kal_uint8 m_ucSignalLevel;

}FM_RSSI_CNF_T;

typedef struct
{
    kal_uint16 m_u2IfCnt;

}FM_IF_CNT_CNF_T;

typedef struct
{
   kal_int16 m_i2StartFreq;
   kal_int16 m_i2StopFreq;
}FM_FREQ_RANGE_REQ_T;

typedef struct
{
    kal_uint8  m_ucExit;      // 0: don't exist, 1: exist
    kal_int16 m_i2ValidFreq;  // -1: settings error, 0: invalid freq, others: 875-1080 valid

}FM_VAILD_FREQ_CNF_T;

typedef struct
{
   kal_uint32 m_u4RssiThreshold;

}FM_RSSI_THRESHOLD_REQ_T;

typedef struct
{
   kal_uint32 m_u4IfCntDelta;

}FM_IF_CNT_DELTA_REQ_T;

typedef struct
{
    kal_uint16 m_u2MonoOrStereo;
    kal_uint16 m_u2SblendOnOrOff;
    kal_uint32 m_u4ItemValue;

}FM_MONO_STEREO_BLEND_REQ_T;

typedef struct
{
    kal_uint8 m_ucAddr;

}FM_READ_BYTE_ADDR_REQ_T;

typedef struct
{
   kal_uint16 m_u2ReadByte;

}FM_READ_BYTE_CNF_T;

typedef struct
{
    kal_uint8    m_ucAddr;
    kal_uint16   m_u2WriteByte;

}FM_WRITE_BYTE_REQ_T;

typedef struct
{
    kal_bool  m_bOnOff;

}FM_SOFT_MUTE_ONOFF_REQ_T;

typedef struct
{
    kal_uint8 m_ucStage;
}FM_STAGE_REQ_T;

typedef struct
{
    kal_uint8 m_ucHighOrLow;
}FM_HL_Side_CNF_T;

typedef struct
{
    kal_uint8 m_ucStereoOrMono;

}FM_Stereo_Mono_CNF_T;

typedef struct
{
    kal_uint8 m_ucVolume;
    kal_char m_cDigitalGainIndex;
}FM_Volume_Setting_REQ_T;

typedef struct
{
    kal_uint16 m_u2Bitmap[16];
}FM_AutoScan_CNF_T;

typedef struct
{
    kal_uint8 m_ucRDSOn;
}FM_SetRDS_REQ_T;

typedef struct
{
    kal_uint8 m_ucRXFilterBW;
}FM_RX_FilterBW_CNF_T;

typedef struct
{
    kal_uint8 m_ucPAMDLevel;
}FM_PAMD_Level_CNF_T;

typedef struct
{
    kal_uint8 m_ucMR;
}FM_MR_CNF_T;

typedef struct
{
    kal_uint32 m_u4DecodeMode;
}FM_Decode_Mode_REQ_T;

typedef struct
{
    kal_uint32 m_u4HCC;
}FM_HCC_REQ_T;

typedef struct
{
    kal_uint32 m_u4PAMDThreshold;
}FM_PAMD_Threshold_REQ_T;

typedef struct
{
    kal_uint32 m_u4SoftmuteEnable;
}FM_Softmute_Enable_REQ_T;

typedef struct
{
    kal_uint32 m_u4DeemphasisLevel;
}FM_Deemphasis_Level_REQ_T;

typedef struct
{
    kal_uint32 m_u4HLSide;
}FM_HL_Side_REQ_T;

typedef struct
{
    kal_uint32 m_u4DemodBandwidth;
}FM_Demod_Bandwidth_REQ_T;

typedef struct
{
    kal_uint32 m_u4DynamicLimiter;
}FM_DynamicLimiter_REQ_T;

typedef struct
{
    kal_uint32 m_u4SoftmuteRate;
}FM_Softmute_Rate_REQ_T;

typedef struct
{
    kal_uint8 m_eCmd;
}FM_RDS_Info_REQ_T;

typedef struct
{
    kal_uint16 m_buffer[64];
}FM_RDS_Info_CNF_T;

typedef struct
{
    kal_uint8  m_eFlag;
    kal_uint16 m_buffer[64];
}FM_RDS_Status_CNF_T;

typedef struct
{
    kal_uint16 m_u2GoodBlock;
}FM_RDS_Good_Block_Counter_CNF_T;

typedef struct
{
    kal_uint16 m_u2BadBlock;
}FM_RDS_Bad_Block_Counter_CNF_T;

typedef struct
{
    kal_uint16 m_u2GroupCounter[32];
}FM_RDS_Group_Counter_CNF_T;

typedef struct
{
    kal_uint16 m_u2Blocks[5];
}FM_RDS_Block_CNF_T;

typedef struct
{
    kal_int16 m_i2StartFreq;
    kal_uint8 m_ucDirection;
}FM_HWSeek_REQ_T;

typedef struct
{
    kal_int16 m_i2EndFreq;
}FM_HWSeek_CNF_T;

typedef union
{
    FM_RDS_Status_CNF_T m_rRDSStatus;
    FM_RDS_Info_CNF_T   m_rRDSInfo;
}FM_RDS_U;

typedef struct
{
    kal_uint16          eventtype;
    FM_RDS_U            m_rRDS;
}FM_RDS_CNF_T;

typedef struct
{
    kal_uint16 m_u2StereoBlendControl;
}FM_SetStereoBlend_REQ_T;

typedef union
{
    FM_READ_BYTE_ADDR_REQ_T       m_rReadAddr;
    FM_FREQ_REQ_T                 m_rCurFreq;
    FM_MONO_STEREO_BLEND_REQ_T    m_rMonoStereoSettings;
    FM_FREQ_RANGE_REQ_T           m_rFreqRange;
    FM_RSSI_THRESHOLD_REQ_T       m_rRssiThreshold;
    FM_IF_CNT_DELTA_REQ_T         m_rIfCntDelta;
    FM_WRITE_BYTE_REQ_T           m_rWriteByte;
    FM_SOFT_MUTE_ONOFF_REQ_T      m_rSoftMuteOnOff;
    FM_STAGE_REQ_T                m_rStage;
    FM_Volume_Setting_REQ_T       m_rVolumeSetting;
    FM_SetRDS_REQ_T               m_rSetRDS;
    FM_Decode_Mode_REQ_T          m_rDecodeMode;
    FM_HCC_REQ_T                  m_rHCC;
    FM_PAMD_Threshold_REQ_T       m_rPAMDThreshold;
    FM_Softmute_Enable_REQ_T      m_rSoftmuteEnable;
    FM_Deemphasis_Level_REQ_T     m_rDeemphasisLevel;
    FM_HL_Side_REQ_T              m_rHLSide;
    FM_Demod_Bandwidth_REQ_T      m_rDemodeBandwidth;
    FM_DynamicLimiter_REQ_T       m_rDynamicLimiter;
    FM_Softmute_Rate_REQ_T        m_rSoftmuteRate;
    FM_RDS_Info_REQ_T             m_rRDSInfo;
    FM_HWSeek_REQ_T               m_rHWSeek;
    FM_SetStereoBlend_REQ_T       m_rStereoBlendControl;
    kal_int8                      m_i1AntennaType;
}META_FM_CMD_U;

typedef union
{
    FM_CHIP_ID_CNF_T      m_rChipId;
    FM_RSSI_CNF_T         m_rSignalValue;
    FM_IF_CNT_CNF_T       m_rIfCnt;
    FM_VAILD_FREQ_CNF_T   m_rValidFreq;
    FM_READ_BYTE_CNF_T    m_rReadByte;
    FM_HL_Side_CNF_T      m_rHLSide;
    FM_Stereo_Mono_CNF_T  m_rStereoMono;
    FM_RX_FilterBW_CNF_T  m_rRXFilterBW;
    FM_PAMD_Level_CNF_T   m_rPAMDLevel;
    FM_MR_CNF_T           m_rMR;
    FM_RDS_Good_Block_Counter_CNF_T m_rRDSGoodBlockCounter;
    FM_RDS_Bad_Block_Counter_CNF_T  m_rRDSBadBlockCounter;
    FM_HWSeek_CNF_T       m_rHWSeek;
    kal_uint16            m_u2RDSBLERRatio;
    kal_int8              m_i1AntennaType;
    kal_uint32            m_u4CapArray;
}META_FM_CNF_U;


typedef struct
{
    FT_H              header;
    FT_FM_CMD_TYPE      type;
    META_FM_CMD_U       cmd;

}FT_FM_REQ;

typedef struct
{
    FT_H                header;
    FT_FM_CMD_TYPE      type;
    META_FM_CNF_U       result;
    kal_uint32                status;
}FT_FM_CNF;


#endif // #ifndef __FT_MSG_FM_H__
