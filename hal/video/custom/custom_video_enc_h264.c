#ifdef __VIDEO_ARCHI_V2__


/* __H264_ENC_SUPPORT__ is a global option. */
#ifdef __H264_ENC_SUPPORT__

#include <stddef.h>

#include "kal_release.h"
#include "custom_video_enc_setting.h"
#include "custom_video_enc_h264.h"
#ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
#include "EngineerModeRecorderSetting.h"
#endif
// #include "drv_comm.h"                   // for drv_trace1(), drv_trace8()


/*****************************************************************************
* Static global variables
*****************************************************************************/
static CUSTOM_VENC_H264_MGR_T _rCustomVencH264Mgr;


/*****************************************************************************
* Clear the saved index of table selection.  All "Set" functions need to
* call this function so that the frame rate table will be search again with
* the new set value.
*****************************************************************************/
static __inline _CustomVenc_H264_ClearTableSelection(void)
{
    _rCustomVencH264Mgr.u2TableIndex = CUSTOM_VENC_H264_UNKNOWN_TABLE_INDEX;
}


/*****************************************************************************
* Memory pointed by the input parameters is allocated by caller.
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_H264_MakeTableSelection(kal_uint16 *pu2TableIndex)
{
    CUSTOM_VENC_ERROR_T eError = CUSTOM_VENC_ERROR_NONE;
    const kal_uint16 u2TableEntries = _rCustomVencH264Mgr.u2TableEntries;
    kal_uint16 u2TableIndex = _rCustomVencH264Mgr.u2TableIndex;

    if (!(u2TableEntries != CUSTOM_VENC_H264_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
    if (!(_rCustomVencH264Mgr.u2Width != CUSTOM_VENC_H264_UNKNOWN_WIDTH))  { ASSERT(0); }
    if (!(_rCustomVencH264Mgr.u2Height != CUSTOM_VENC_H264_UNKNOWN_HEIGHT))  { ASSERT(0); }
    if (!(_rCustomVencH264Mgr.eQuality != CUSTOM_VENC_QUALITY_UNKNOWN))  { ASSERT(0); }
    if (!(_rCustomVencH264Mgr.eStorage != CUSTOM_VENC_STORAGE_UNKNOWN))  { ASSERT(0); }
    if (!(_rCustomVencH264Mgr.eCodec != CUSTOM_VENC_CODEC_UNKNOWN))  { ASSERT(0); }

    // if (_rCustomVencH264Mgr.eResolution == CUSTOM_VENC_RESOLUTION_UNKNOWN)
    {
        kal_uint16 u2Width, u2Height;
        CUSTOM_VENC_RESOLUTION_T eResolution;

        u2Width = _rCustomVencH264Mgr.u2Width;
        u2Height = _rCustomVencH264Mgr.u2Height;
        eError = CustomVenc_MapWidthAndHeightToResolution(u2Width, u2Height, &eResolution);
        if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
        if (!(eResolution != CUSTOM_VENC_RESOLUTION_UNKNOWN))  { ASSERT(0); }
        _rCustomVencH264Mgr.eResolution = eResolution;
    }

    if (u2TableIndex == CUSTOM_VENC_H264_UNKNOWN_TABLE_INDEX)
    {
        for (u2TableIndex = 0; u2TableIndex < u2TableEntries; u2TableIndex++)
        {
            if (_rH264FrameRateTable[u2TableIndex].rUpperTable.eResolution == _rCustomVencH264Mgr.eResolution)
            {
                if ((_rH264FrameRateTable[u2TableIndex].rUpperTable.eQuality == CUSTOM_VENC_QUALITY_ALL) ||
                    (_rH264FrameRateTable[u2TableIndex].rUpperTable.eQuality == _rCustomVencH264Mgr.eQuality))
                {
                    if ((_rH264FrameRateTable[u2TableIndex].rUpperTable.eStorage == CUSTOM_VENC_STORAGE_ALL) ||
                        (_rH264FrameRateTable[u2TableIndex].rUpperTable.eStorage == _rCustomVencH264Mgr.eStorage))
                    {
                        if ((_rH264FrameRateTable[u2TableIndex].rUpperTable.eCodec == CUSTOM_VENC_CODEC_ALL) ||
                            (_rH264FrameRateTable[u2TableIndex].rUpperTable.eCodec == _rCustomVencH264Mgr.eCodec))
                        {
                             _rCustomVencH264Mgr.u2TableIndex = u2TableIndex;
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
static kal_uint16 _CustomVenc_H264_ComputeNumOfEntries(void)
{
    if (!(sizeof(_rH264FrameRateTable) != 0))  { ASSERT(0); }
    if (!(sizeof(_rH264FrameRateTable[0]) != 0))  { ASSERT(0); }
    if (!(sizeof(_rDefaultH264FrameRateTable) != 0))  { ASSERT(0); }
    if (!(sizeof(_rDefaultH264FrameRateTable[0]) != 0))  { ASSERT(0); }

    return (kal_uint16)(sizeof(_rH264FrameRateTable) / sizeof(_rH264FrameRateTable[0]));
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_H264_SetUser(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    // Clear all internal variables.
    _rCustomVencH264Mgr.u2Width = CUSTOM_VENC_H264_UNKNOWN_WIDTH;
    _rCustomVencH264Mgr.u2Height = CUSTOM_VENC_H264_UNKNOWN_HEIGHT;
    _rCustomVencH264Mgr.u2TableEntries = _CustomVenc_H264_ComputeNumOfEntries();
    _rCustomVencH264Mgr.u2TableIndex = CUSTOM_VENC_H264_UNKNOWN_TABLE_INDEX;
    _rCustomVencH264Mgr.eResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
    _rCustomVencH264Mgr.eQuality = CUSTOM_VENC_QUALITY_UNKNOWN;
    _rCustomVencH264Mgr.eStorage = CUSTOM_VENC_STORAGE_UNKNOWN;
    _rCustomVencH264Mgr.eCodec = CUSTOM_VENC_CODEC_UNKNOWN;   

    return CUSTOM_VENC_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_H264_GetNumOfEntries(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Output;

    if (!(pvOutput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pu4Output) == u4OutputSize))  { ASSERT(0); }

    _rCustomVencH264Mgr.u2TableEntries = _CustomVenc_H264_ComputeNumOfEntries();
    pu4Output = (kal_uint32*)pvOutput;
    *pu4Output = _rCustomVencH264Mgr.u2TableEntries;

    return CUSTOM_VENC_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_H264_GetOneEntry(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Index;
    CUSTOM_VENC_UPPER_TABLE_T *prUpperTable;

    if (!(pvInput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pu4Index) == u4InputSize))  { ASSERT(0); }
    pu4Index = (kal_uint32*)pvInput;
    if (!(_rCustomVencH264Mgr.u2TableEntries != CUSTOM_VENC_H264_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
    if (!(*pu4Index < _rCustomVencH264Mgr.u2TableEntries))  { ASSERT(0); }

    if (!(pvOutput != NULL))  { ASSERT(0); }
    if (!(sizeof(*prUpperTable) == u4OutputSize))  { ASSERT(0); }
    prUpperTable = (CUSTOM_VENC_UPPER_TABLE_T*)pvOutput;
    *prUpperTable = _rH264FrameRateTable[*pu4Index].rUpperTable;

    return CUSTOM_VENC_ERROR_NONE;
}


//----------------------------------------------------------------------------

static CUSTOM_VENC_ERROR_T _CustomVenc_H264_SetField(void *pvInput, kal_uint32 u4InputSize, int field_offset, int size_of_field)
{
    kal_uint32 *pInput = (kal_uint32 *) pvInput;
    
    if (!(pvInput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pInput) == u4InputSize))  { ASSERT(0); }
      
    switch (size_of_field)
    {
      case 1:
      {
        kal_uint8 *pField = (kal_uint8 *)((kal_uint8 *) &_rCustomVencH264Mgr + field_offset);

        *pField = (kal_uint8) *pInput;
        break;
      }
      case 2:
      {
        kal_uint16 *pField = (kal_uint16 *)((kal_uint8 *) &_rCustomVencH264Mgr + field_offset);

        *pField = (kal_uint16) *pInput;
        break;
      }        
      case 4:
      {
        kal_uint32 *pField = (kal_uint32 *)((kal_uint8 *) &_rCustomVencH264Mgr + field_offset);

        *pField = (kal_uint32) *pInput;
        break;
      }        
      default:
      {
        ASSERT(0);
      }
    }

    _CustomVenc_H264_ClearTableSelection();

    return CUSTOM_VENC_ERROR_NONE;   
}

//----------------------------------------------------------------------------
static CUSTOM_VENC_ERROR_T _CustomVenc_H264_GetField(void *pvOutput, int u4OutputSize, int field_offset, int size_of_field)
{
    const kal_uint16 u2TableEntries = _rCustomVencH264Mgr.u2TableEntries;
    kal_uint16 u2TableIndex;
    CUSTOM_VENC_ERROR_T eError;
    void *pTableEntry = NULL;
    kal_uint32 *pOutput = (kal_uint32 *) pvOutput;

    if (!pvOutput)                      { ASSERT(0); }
    if (sizeof(kal_uint32) != u4OutputSize)  { ASSERT(0); }

    eError = _CustomVenc_H264_MakeTableSelection(&u2TableIndex);
    
    if (eError == CUSTOM_VENC_ERROR_NONE)
    {
        if (!(u2TableEntries != CUSTOM_VENC_H264_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
        if (!(u2TableIndex != CUSTOM_VENC_H264_UNKNOWN_TABLE_INDEX))  { ASSERT(0); }
        if (!(u2TableIndex < u2TableEntries))  { ASSERT(0); }
         
        pTableEntry = (void *) &_rH264FrameRateTable[u2TableIndex];
    }
    else
    {
        pTableEntry = (void *) &_rDefaultH264FrameRateTable[0];
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
static CUSTOM_VENC_ERROR_T _CustomVenc_H264_Ctrl(CUSTOM_VENC_OP_T eOp,
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
            case CUSTOM_VENC_OP_GET_INTRA_VOP_RATE:
                *pRes = g_mmi_em_recorder_setting.intra_vop_rate;
                eError = CUSTOM_VENC_ERROR_NONE;
                break;
            case CUSTOM_VENC_OP_GET_ALGORITHM:
                *pRes = g_mmi_em_recorder_setting.algorithm;
                eError = CUSTOM_VENC_ERROR_NONE;
                break;
            case CUSTOM_VENC_OP_GET_BIT_RATE:
                *pRes = g_mmi_em_recorder_setting.bit_rate * 1000;
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
        eError = _CustomVenc_H264_SetUser(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES:
        eError = _CustomVenc_H264_GetNumOfEntries(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_ONE_ENTRY:
        eError = _CustomVenc_H264_GetOneEntry(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_SET_WIDTH:
        eError = _CustomVenc_H264_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_H264_MGR_T, u2Width), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_HEIGHT:
        eError = _CustomVenc_H264_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_H264_MGR_T, u2Height), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_QUALITY:
        eError = _CustomVenc_H264_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_H264_MGR_T, eQuality), sizeof(CUSTOM_VENC_QUALITY_T));
        break;

    case CUSTOM_VENC_OP_SET_STORAGE:
        eError = _CustomVenc_H264_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_H264_MGR_T, eStorage), sizeof(CUSTOM_VENC_STORAGE_T));
        break;

    case CUSTOM_VENC_OP_SET_CODEC:
        eError = _CustomVenc_H264_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_H264_MGR_T, eCodec), sizeof(CUSTOM_VENC_CODEC_T));
        break;     

    case CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u2SensorFrameRate), 
                                           sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_SENSOR_NIGHT_FRAME_RATE:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u2SensorNightFrameRate), 
                                           sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u2CodecFrameRate), 
                                           sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_NIGHT_FRAME_RATE:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u2CodecNightFrameRate), 
                                           sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_INTRA_VOP_RATE:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u4KeyintMax), 
                                           sizeof(kal_uint32));
        break;

    case CUSTOM_VENC_OP_GET_ALGORITHM:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u4AlgorithmSelect), 
                                           sizeof(kal_uint32));
        break;

    case CUSTOM_VENC_OP_GET_BIT_RATE:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u4bitrate), 
                                           sizeof(kal_uint32));
        break;

    case CUSTOM_VENC_OP_GET_TARGET_COMPLEXITY:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u4TargetComplexity), 
                                           sizeof(kal_uint32));
        break;

    case CUSTOM_VENC_OP_GET_THRESHOLD_AVG_LOW:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u4AvgThLow), 
                                           sizeof(kal_uint32));
        break;

    case CUSTOM_VENC_OP_GET_THRESHOLD_AVG_HIGH:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u4AvgThHigh), 
                                           sizeof(kal_uint32));
        break;

    case CUSTOM_VENC_OP_GET_THRESHOLD_CUR_LOW:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u4CurThLow), 
                                           sizeof(kal_uint32));
        break;

    case CUSTOM_VENC_OP_GET_THRESHOLD_CUR_HIGH:
        eError = _CustomVenc_H264_GetField(pvOutput, 
                                           u4OutputSize, 
                                           offsetof(VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T, rLowerTable) + 
                                           offsetof(CUSTOM_VENC_REC_H264_LOWER_TABLE_T, u4CurThHigh), 
                                           sizeof(kal_uint32));
        break;

    default:
        eError = CUSTOM_VENC_ERROR_NOT_SUPPORTED;
        // When the error code CUSTOM_VENC_ERROR_NOT_SUPPORTED is received by
        // codec, codec will try to use a default value for the requested property.
        // For table extension in the future, do not assert here.
        // ASSERT(0);
        break;
    }

    return eError;
}


/*****************************************************************************
*
*****************************************************************************/
CUSTOM_VENC_ERROR_T CustomVenc_GetH264CtrlFunction(PFN_CUSTOM_VENC_CTRL *ppfnCustomVencCtrl)
{
    if (!(ppfnCustomVencCtrl != NULL))  { ASSERT(0); }

    *ppfnCustomVencCtrl = _CustomVenc_H264_Ctrl;

    return CUSTOM_VENC_ERROR_NONE;
}


#endif  // __H264_ENC_SUPPORT__


#endif  // __VIDEO_ARCHI_V2__

