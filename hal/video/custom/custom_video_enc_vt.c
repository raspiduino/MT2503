/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_vt.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides interfaces for accessing customized video parameters.
 *   It shall not normally be modified.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/


#ifdef __VIDEO_ARCHI_V2__


#include "drv_features_video.h"             // for __VIDEO_VT_SUPPORT__
#include "kal_release.h"
#include "custom_video_enc_setting.h"
#include "custom_video_enc_vt.h"
#ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
#include "EngineerModeRecorderSetting.h"
#endif


/* __VIDEO_VT_SUPPORT__ is a local option. */
#ifdef __VIDEO_VT_SUPPORT__

#include <stddef.h>

/*****************************************************************************
* Static global variables
*****************************************************************************/
static CUSTOM_VENC_VT_MGR_T _rCustomVencVtMgr;


/*****************************************************************************
* Calculate GCD (Greatest Common Divisor) of two numbers.
*****************************************************************************/
static kal_uint32 _FindGCD(kal_uint32 u4N1, kal_uint32 u4N2)
{
    kal_uint32 u4Temp;

    if (u4N1 == 0) {ASSERT(0);}
    if (u4N2 == 0) {ASSERT(0);}

    while (u4N2 != 0)
    {
        u4Temp = u4N1 % u4N2;
        u4N1 = u4N2;
        u4N2 = u4Temp;
    }

    return u4N1;
}


/*****************************************************************************
* Calculate LCM (Least Common Multiple) of two numbers.
*****************************************************************************/
static kal_uint32 _FindLCM(kal_uint32 u4N1, kal_uint32 u4N2)
{
    kal_uint32 u4Gcd, u4Lcm, u4Multiply;

    u4Gcd = _FindGCD(u4N1, u4N2);

    u4Multiply = u4N1 * u4N2;
    if (u4Multiply < u4N1) {ASSERT(0);}  // Check for wrapping around.
    if (u4Multiply < u4N2) {ASSERT(0);}  // Check for wrapping around.
    if (u4Gcd == 0)        {ASSERT(0);}
    u4Lcm = u4Multiply / u4Gcd;
    
    u4Lcm = 30000; // for MONA project

    return u4Lcm;
}


/*****************************************************************************
* Clear the saved index of table selection.  All "Set" functions need to
* call this function so that the frame rate table will be search again with
* the new set value.
*****************************************************************************/
static __inline _CustomVenc_VT_ClearTableSelection(void)
{
    _rCustomVencVtMgr.u2TableIndex = CUSTOM_VENC_VT_UNKNOWN_TABLE_INDEX;
}


/*****************************************************************************
* Memory pointed by the input parameters is allocated by caller.
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_VT_MakeTableSelection(kal_uint16 *pu2TableIndex)
{
    CUSTOM_VENC_ERROR_T eError = CUSTOM_VENC_ERROR_NONE;
    const kal_uint16 u2TableEntries = _rCustomVencVtMgr.u2TableEntries;
    kal_uint16 u2TableIndex = _rCustomVencVtMgr.u2TableIndex;

    if(u2TableEntries == CUSTOM_VENC_VT_UNKNOWN_TABLE_ENTRIES) {ASSERT(0);}
    if(_rCustomVencVtMgr.u2Width == CUSTOM_VENC_VT_UNKNOWN_WIDTH) {ASSERT(0);}
    if(_rCustomVencVtMgr.u2Height == CUSTOM_VENC_VT_UNKNOWN_HEIGHT) {ASSERT(0);}
    if(_rCustomVencVtMgr.eQuality == CUSTOM_VENC_QUALITY_UNKNOWN) {ASSERT(0);}
    if(_rCustomVencVtMgr.eStorage == CUSTOM_VENC_STORAGE_UNKNOWN) {ASSERT(0);}
    if(_rCustomVencVtMgr.eCodec == CUSTOM_VENC_CODEC_UNKNOWN) {ASSERT(0);}

    // if (_rCustomVencVtMgr.eResolution == CUSTOM_VENC_RESOLUTION_UNKNOWN)
    {
        kal_uint16 u2Width, u2Height;
        CUSTOM_VENC_RESOLUTION_T eResolution;

        u2Width = _rCustomVencVtMgr.u2Width;
        u2Height = _rCustomVencVtMgr.u2Height;
        eError = CustomVenc_MapWidthAndHeightToResolution(u2Width, u2Height, &eResolution);
        
        if(eError != CUSTOM_VENC_ERROR_NONE) {ASSERT(0);}
        if(eResolution == CUSTOM_VENC_RESOLUTION_UNKNOWN) {ASSERT(0);}
        _rCustomVencVtMgr.eResolution = eResolution;
    }

    if (u2TableIndex == CUSTOM_VENC_VT_UNKNOWN_TABLE_INDEX)
    {
        for (u2TableIndex = 0; u2TableIndex < u2TableEntries; u2TableIndex++)
        {
            if (_rVtFrameRateTable[u2TableIndex].rUpperTable.eResolution == _rCustomVencVtMgr.eResolution)
            {
                if ((_rVtFrameRateTable[u2TableIndex].rUpperTable.eQuality == CUSTOM_VENC_QUALITY_ALL) ||
                    (_rVtFrameRateTable[u2TableIndex].rUpperTable.eQuality == _rCustomVencVtMgr.eQuality))
                {
                    if ((_rVtFrameRateTable[u2TableIndex].rUpperTable.eStorage == CUSTOM_VENC_STORAGE_ALL) ||
                        (_rVtFrameRateTable[u2TableIndex].rUpperTable.eStorage == _rCustomVencVtMgr.eStorage))
                    {
                        if ((_rVtFrameRateTable[u2TableIndex].rUpperTable.eCodec == CUSTOM_VENC_CODEC_ALL) ||
                            (_rVtFrameRateTable[u2TableIndex].rUpperTable.eCodec == _rCustomVencVtMgr.eCodec))
                        {
                            _rCustomVencVtMgr.u2TableIndex = u2TableIndex;
                            eError = CUSTOM_VENC_ERROR_NONE;
                            break;
                        }
                    }
                }
            }
        }
        if (u2TableIndex == u2TableEntries)
        {
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
    }
    else
    {
        eError = CUSTOM_VENC_ERROR_NONE;
    }

    *pu2TableIndex = u2TableIndex;
    return eError;
}


/*****************************************************************************
*
*****************************************************************************/
static kal_uint16 _CustomVenc_VT_ComputeNumOfEntries(void)
{
    if(sizeof(_rVtFrameRateTable) == 0) {ASSERT(0);}
    if(sizeof(_rVtFrameRateTable[0]) == 0) {ASSERT(0);}
    if(sizeof(_rDefaultVtFrameRateTable) == 0) {ASSERT(0);}
    if(sizeof(_rDefaultVtFrameRateTable[0]) == 0) {ASSERT(0);}

    return (kal_uint16)(sizeof(_rVtFrameRateTable) / sizeof(_rVtFrameRateTable[0]));
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_VT_SetUser(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    // Clear all internal variables.
    _rCustomVencVtMgr.u2Width = CUSTOM_VENC_VT_UNKNOWN_WIDTH;
    _rCustomVencVtMgr.u2Height = CUSTOM_VENC_VT_UNKNOWN_HEIGHT;
    _rCustomVencVtMgr.u2TableEntries = _CustomVenc_VT_ComputeNumOfEntries();
    _rCustomVencVtMgr.u2TableIndex = CUSTOM_VENC_VT_UNKNOWN_TABLE_INDEX;
    _rCustomVencVtMgr.eResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
    _rCustomVencVtMgr.eQuality = CUSTOM_VENC_QUALITY_UNKNOWN;
    _rCustomVencVtMgr.eStorage = CUSTOM_VENC_STORAGE_UNKNOWN;
    _rCustomVencVtMgr.eCodec = CUSTOM_VENC_CODEC_UNKNOWN;

    return CUSTOM_VENC_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_VT_GetNumOfEntries(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Output;

    if(pvOutput == NULL) {ASSERT(0);}
    if(sizeof(*pu4Output) != u4OutputSize) {ASSERT(0);}

    _rCustomVencVtMgr.u2TableEntries = _CustomVenc_VT_ComputeNumOfEntries();
    pu4Output = (kal_uint32*)pvOutput;
    *pu4Output = _rCustomVencVtMgr.u2TableEntries;

    return CUSTOM_VENC_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_VT_GetOneEntry(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Index;
    CUSTOM_VENC_UPPER_TABLE_T *prUpperTable;

    if(pvInput == NULL) {ASSERT(0);}
    if(sizeof(*pu4Index) != u4InputSize) {ASSERT(0);}
    pu4Index = (kal_uint32*)pvInput;
    if(_rCustomVencVtMgr.u2TableEntries == CUSTOM_VENC_VT_UNKNOWN_TABLE_ENTRIES) {ASSERT(0);}
    if(*pu4Index >= _rCustomVencVtMgr.u2TableEntries) {ASSERT(0);}

    if(pvOutput == NULL) {ASSERT(0);}
    if(sizeof(*prUpperTable) != u4OutputSize) {ASSERT(0);}
    prUpperTable = (CUSTOM_VENC_UPPER_TABLE_T*)pvOutput;
    *prUpperTable = _rVtFrameRateTable[*pu4Index].rUpperTable;

    return CUSTOM_VENC_ERROR_NONE;
}


//----------------------------------------------------------------------------

static CUSTOM_VENC_ERROR_T _CustomVenc_VT_SetField(void *pvInput, kal_uint32 u4InputSize, int field_offset, int size_of_field)
{
    kal_uint32 *pInput = (kal_uint32 *) pvInput;
    
    if (!(pvInput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pInput) == u4InputSize))  { ASSERT(0); }
      
    switch (size_of_field)
    {
      case 1:
      {
        kal_uint8 *pField = (kal_uint8 *)((kal_uint8 *) &_rCustomVencVtMgr + field_offset);

        *pField = (kal_uint8) *pInput;
        break;
      }
      case 2:
      {
        kal_uint16 *pField = (kal_uint16 *)((kal_uint8 *) &_rCustomVencVtMgr + field_offset);

        *pField = (kal_uint16) *pInput;
        break;
      }        
      case 4:
      {
        kal_uint32 *pField = (kal_uint32 *)((kal_uint8 *) &_rCustomVencVtMgr + field_offset);

        *pField = (kal_uint32) *pInput;
        break;
      }        
      default:
      {
        ASSERT(0);
      }
    }

    _CustomVenc_VT_ClearTableSelection();

    return CUSTOM_VENC_ERROR_NONE;   
}

//----------------------------------------------------------------------------
static CUSTOM_VENC_ERROR_T _CustomVenc_VT_GetField(void *pvOutput, int u4OutputSize, int field_offset, int size_of_field)
{
    const kal_uint16 u2TableEntries = _rCustomVencVtMgr.u2TableEntries;
    kal_uint16 u2TableIndex;
    CUSTOM_VENC_ERROR_T eError;
    void *pTableEntry = NULL;
    kal_uint32 *pOutput = (kal_uint32 *) pvOutput;

    if (!pvOutput)                      { ASSERT(0); }
    if (sizeof(kal_uint32) != u4OutputSize)  { ASSERT(0); }

    eError = _CustomVenc_VT_MakeTableSelection(&u2TableIndex);
    
    if (eError == CUSTOM_VENC_ERROR_NONE)
    {
        if (!(u2TableEntries != CUSTOM_VENC_VT_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
        if (!(u2TableIndex != CUSTOM_VENC_VT_UNKNOWN_TABLE_INDEX))  { ASSERT(0); }
        if (!(u2TableIndex < u2TableEntries))  { ASSERT(0); }
         
        pTableEntry = (void *) &_rVtFrameRateTable[u2TableIndex];
    }
    else
    {
        pTableEntry = (void *) &_rDefaultVtFrameRateTable[0];
        eError = CUSTOM_VENC_ERROR_USE_DEFAULT;
    }         
     
    if (pTableEntry == NULL) { ASSERT(0); }
              
    switch (size_of_field)
    {
      case 1:
      {
        *pOutput = *((kal_uint8 *) ((kal_uint8 *) pTableEntry + field_offset));
        break;
      }
      case 2:
      {
        *pOutput = *((kal_uint16 *) ((kal_uint8 *) pTableEntry + field_offset));
        break;
      }            
      case 4:
      {
        *pOutput = *((kal_uint32 *) ((kal_uint8 *) pTableEntry + field_offset));
        break;
      } 
      default:
      {
        ASSERT(0);
      }
    }

    return eError; 
}

/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_VT_GetDynamicRangeTable(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4DynamicRangeTable;
    //CUSTOM_VENC_ERROR_T eError;
    //kal_uint32 variation_user = 0;

    if(pvOutput == NULL) {ASSERT(0);}
    if(sizeof(*pu4DynamicRangeTable) != u4OutputSize) {ASSERT(0);}
    pu4DynamicRangeTable = (kal_uint32*)pvOutput;

    *pu4DynamicRangeTable = (kal_uint32)variation_vt;

    return CUSTOM_VENC_ERROR_NONE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
#endif  // 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
#endif  // 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_VT_GetLcmOfCodecFrameRate(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Lcm, u4Num;
    const kal_uint16 u2TableEntries = _rCustomVencVtMgr.u2TableEntries;
    kal_uint16 u2TableIndex;
    CUSTOM_VENC_ERROR_T eError = CUSTOM_VENC_ERROR_NONE;

    ASSERT(pvOutput != NULL);
    ASSERT(sizeof(*pu4Lcm) == u4OutputSize);
    pu4Lcm = (kal_uint32*)pvOutput;

    ASSERT(u2TableEntries != CUSTOM_VENC_VT_UNKNOWN_TABLE_ENTRIES);
    for (u2TableIndex = 0; u2TableIndex < u2TableEntries; u2TableIndex++)
    {
        if (u2TableIndex == 0)
        {
            *pu4Lcm = _rVtFrameRateTable[u2TableIndex].rLowerTable.u2CodecFrameRate;
        }
        else
        {
            u4Num = _rVtFrameRateTable[u2TableIndex].rLowerTable.u2CodecFrameRate;
            *pu4Lcm = _FindLCM(*pu4Lcm, u4Num);
        }
    }

#if 0
/* under construction !*/
#endif  // 0

    return eError;
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_VT_Ctrl(CUSTOM_VENC_OP_T eOp,
    void *pvInput, kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    CUSTOM_VENC_ERROR_T eError;
    
#ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
    if (g_mmi_em_recorder_setting.apply_em_setting == MMI_EM_RECORDER_SETTING_APPLY_YES)
    {
        kal_int32 *pRes = (kal_int32*) pvOutput;
                            
        eError = CUSTOM_VENC_ERROR_NOT_SUPPORTED;
        
        switch (eOp)
        {
            case CUSTOM_VENC_OP_GET_INIT_Q:
                *pRes = g_mmi_em_recorder_setting.init_qp;
                eError = CUSTOM_VENC_ERROR_NONE;
                break;
            case CUSTOM_VENC_OP_GET_MIN_QP:
                *pRes = g_mmi_em_recorder_setting.min_qp;
                eError = CUSTOM_VENC_ERROR_NONE;
                break;
            case CUSTOM_VENC_OP_GET_MAX_QP:
                *pRes = g_mmi_em_recorder_setting.max_qp;
                eError = CUSTOM_VENC_ERROR_NONE;
                break;
            case CUSTOM_VENC_OP_GET_INTRA_VOP_RATE:
                *pRes = g_mmi_em_recorder_setting.intra_vop_rate;
                eError = CUSTOM_VENC_ERROR_NONE;
                break;
            case CUSTOM_VENC_OP_GET_DYNAMIC_RANGE_REDUCTION:
                *pRes = g_mmi_em_recorder_setting.dyn_range_reduction;
                eError = CUSTOM_VENC_ERROR_NONE;
                break;
        }
        
        if (eError == CUSTOM_VENC_ERROR_NONE)
            return eError;
    }
#endif

    switch (eOp)
    {
    case CUSTOM_VENC_OP_SET_USER:
        eError = _CustomVenc_VT_SetUser(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES:
        eError = _CustomVenc_VT_GetNumOfEntries(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_ONE_ENTRY:
        eError = _CustomVenc_VT_GetOneEntry(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_SET_WIDTH:
        eError = _CustomVenc_VT_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_VT_MGR_T, u2Width), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_HEIGHT:
        eError = _CustomVenc_VT_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_VT_MGR_T, u2Height), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_QUALITY:
        eError = _CustomVenc_VT_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_VT_MGR_T, eQuality), sizeof(CUSTOM_VENC_QUALITY_T));
        break;

    case CUSTOM_VENC_OP_SET_STORAGE:
        eError = _CustomVenc_VT_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_VT_MGR_T, eStorage), sizeof(CUSTOM_VENC_STORAGE_T));
        break;

    case CUSTOM_VENC_OP_SET_CODEC:
        eError = _CustomVenc_VT_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_VT_MGR_T, eCodec), sizeof(CUSTOM_VENC_CODEC_T));
        break;

    case CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u2SensorFrameRate), 
                                         sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_SENSOR_NIGHT_FRAME_RATE:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u2SensorNightFrameRate), 
                                         sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u2CodecFrameRate), 
                                         sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_NIGHT_FRAME_RATE:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u2CodecNightFrameRate), 
                                         sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_INIT_Q:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u1InitQ), 
                                         sizeof(kal_uint8));
        break;

    case CUSTOM_VENC_OP_GET_MIN_QP:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u1MinQp), 
                                         sizeof(kal_uint8));
        break;

    case CUSTOM_VENC_OP_GET_MAX_QP:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u1MaxQp), 
                                         sizeof(kal_uint8));
        break;

    case CUSTOM_VENC_OP_GET_INTRA_VOP_RATE:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u2IntraVopRate), 
                                         sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ALGORITHM:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u2Algorithm), 
                                         sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_BIT_RATE:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u4BitRate), 
                                         sizeof(kal_uint32));
        break;

    case CUSTOM_VENC_OP_GET_DYNAMIC_RANGE_REDUCTION:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u4DynamicRangeReduction), 
                                         sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_IS_CUSTOMER_SET_TABLE:
        eError = _CustomVenc_VT_GetField(pvOutput, 
                                         u4OutputSize, 
                                         offsetof(VIDEO_ENC_VT_MPEG4_FRAME_RATE_TABLE_T, rLowerTable) + 
                                         offsetof(CUSTOM_VENC_VT_MPEG4_LOWER_TABLE_T, u4IsCustomerSetTable), 
                                         sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_DYNAMIC_RANGE_TABLE:
        eError = _CustomVenc_VT_GetDynamicRangeTable(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0

    case CUSTOM_VENC_OP_GET_LCM_OF_CODEC_FRAME_RATE:
        eError = _CustomVenc_VT_GetLcmOfCodecFrameRate(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    default:
        eError = CUSTOM_VENC_ERROR_NOT_SUPPORTED;
        // When the error code CUSTOM_VENC_ERROR_NOT_SUPPORTED is received by
        // codec, codec will try to use a default value for the requested property.
        // For table extension in the future, do not assert here.
        //ASSERT(0);
        break;
    }

    return eError;
}


/*****************************************************************************
*
*****************************************************************************/
CUSTOM_VENC_ERROR_T CustomVenc_GetVtCtrlFunction(PFN_CUSTOM_VENC_CTRL *ppfnCustomVencCtrl)
{
    if(ppfnCustomVencCtrl == NULL) {ASSERT(0);}

    *ppfnCustomVencCtrl = _CustomVenc_VT_Ctrl;

    return CUSTOM_VENC_ERROR_NONE;
}


#endif  // __VIDEO_VT_SUPPORT__


#endif  // __VIDEO_ARCHI_V2__

