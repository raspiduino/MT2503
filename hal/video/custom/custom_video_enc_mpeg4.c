/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_mpeg4.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/


#ifdef __VIDEO_ARCHI_V2__


/* __MPEG4_ENC_SUPPORT__ is a global option. */
#ifdef __MPEG4_ENC_SUPPORT__

#include <stddef.h>

#include "kal_release.h"
#include "custom_video_enc_setting.h"
#include "custom_video_enc_mpeg4.h"
#ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
#include "EngineerModeRecorderSetting.h"
#endif

// #include "drv_comm.h"                   // for drv_trace1(), drv_trace8()


/*****************************************************************************
* Static global variables
*****************************************************************************/
static CUSTOM_VENC_MPEG4_MGR_T _rCustomVencMpeg4Mgr;


/*****************************************************************************
* Clear the saved index of table selection.  All "Set" functions need to
* call this function so that the frame rate table will be search again with
* the new set value.
*****************************************************************************/
static __inline _CustomVenc_MPEG4_ClearTableSelection(void)
{
    _rCustomVencMpeg4Mgr.u2TableIndex = CUSTOM_VENC_MPEG4_UNKNOWN_TABLE_INDEX;
}


/*****************************************************************************
* Memory pointed by the input parameters is allocated by caller.
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_MPEG4_MakeTableSelection(kal_uint16 *pu2TableIndex)
{
    CUSTOM_VENC_ERROR_T eError = CUSTOM_VENC_ERROR_NONE;
    const kal_uint16 u2TableEntries = _rCustomVencMpeg4Mgr.u2TableEntries;
    kal_uint16 u2TableIndex = _rCustomVencMpeg4Mgr.u2TableIndex;

    if (!(u2TableEntries != CUSTOM_VENC_MPEG4_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
    if (!(_rCustomVencMpeg4Mgr.u2Width != CUSTOM_VENC_MPEG4_UNKNOWN_WIDTH))  { ASSERT(0); }
    if (!(_rCustomVencMpeg4Mgr.u2Height != CUSTOM_VENC_MPEG4_UNKNOWN_HEIGHT))  { ASSERT(0); }
    if (!(_rCustomVencMpeg4Mgr.eQuality != CUSTOM_VENC_QUALITY_UNKNOWN))  { ASSERT(0); }
    if (!(_rCustomVencMpeg4Mgr.eStorage != CUSTOM_VENC_STORAGE_UNKNOWN))  { ASSERT(0); }
    if (!(_rCustomVencMpeg4Mgr.eCodec != CUSTOM_VENC_CODEC_UNKNOWN))  { ASSERT(0); }

    // if (_rCustomVencMpeg4Mgr.eResolution == CUSTOM_VENC_RESOLUTION_UNKNOWN)
    {
        kal_uint16 u2Width, u2Height;
        CUSTOM_VENC_RESOLUTION_T eResolution;

        u2Width = _rCustomVencMpeg4Mgr.u2Width;
        u2Height = _rCustomVencMpeg4Mgr.u2Height;
        eError = CustomVenc_MapWidthAndHeightToResolution(u2Width, u2Height, &eResolution);
        if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
        if (!(eResolution != CUSTOM_VENC_RESOLUTION_UNKNOWN))  { ASSERT(0); }
        _rCustomVencMpeg4Mgr.eResolution = eResolution;
    }

    if (u2TableIndex == CUSTOM_VENC_MPEG4_UNKNOWN_TABLE_INDEX)
    {
        for (u2TableIndex = 0; u2TableIndex < u2TableEntries; u2TableIndex++)
        {
            if (_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eResolution == _rCustomVencMpeg4Mgr.eResolution)
            {
                if ((_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eQuality == CUSTOM_VENC_QUALITY_ALL) ||
                    (_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eQuality == _rCustomVencMpeg4Mgr.eQuality))
                {
                    if ((_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eStorage == CUSTOM_VENC_STORAGE_ALL) ||
                        (_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eStorage == _rCustomVencMpeg4Mgr.eStorage))
                    {
                        if ((_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eCodec == CUSTOM_VENC_CODEC_ALL) ||
                            (_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eCodec == _rCustomVencMpeg4Mgr.eCodec))
                        {
                            if ((_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eRotate == CUSTOM_VENC_ROTATE_ALL) ||
                                (_rMpeg4FrameRateTable[u2TableIndex].rUpperTable.eRotate == _rCustomVencMpeg4Mgr.eRotate))
                            {
                            _rCustomVencMpeg4Mgr.u2TableIndex = u2TableIndex;
                            eError = CUSTOM_VENC_ERROR_NONE;
                            break;
                        }
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
static kal_uint16 _CustomVenc_MPEG4_ComputeNumOfEntries(void)
{
    if (!(sizeof(_rMpeg4FrameRateTable) != 0))  { ASSERT(0); }
    if (!(sizeof(_rMpeg4FrameRateTable[0]) != 0))  { ASSERT(0); }
    if (!(sizeof(_rDefaultMpeg4FrameRateTable) != 0))  { ASSERT(0); }
    if (!(sizeof(_rDefaultMpeg4FrameRateTable[0]) != 0))  { ASSERT(0); }

    return (kal_uint16)(sizeof(_rMpeg4FrameRateTable) / sizeof(_rMpeg4FrameRateTable[0]));
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_MPEG4_SetUser(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    // Clear all internal variables.
    _rCustomVencMpeg4Mgr.u2Width = CUSTOM_VENC_MPEG4_UNKNOWN_WIDTH;
    _rCustomVencMpeg4Mgr.u2Height = CUSTOM_VENC_MPEG4_UNKNOWN_HEIGHT;
    _rCustomVencMpeg4Mgr.u2TableEntries = _CustomVenc_MPEG4_ComputeNumOfEntries();
    _rCustomVencMpeg4Mgr.u2TableIndex = CUSTOM_VENC_MPEG4_UNKNOWN_TABLE_INDEX;
    _rCustomVencMpeg4Mgr.eResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
    _rCustomVencMpeg4Mgr.eQuality = CUSTOM_VENC_QUALITY_UNKNOWN;
    _rCustomVencMpeg4Mgr.eStorage = CUSTOM_VENC_STORAGE_UNKNOWN;
    _rCustomVencMpeg4Mgr.eCodec = CUSTOM_VENC_CODEC_UNKNOWN;
    _rCustomVencMpeg4Mgr.eRotate = CUSTOM_VENC_ROTATE_UNKNOWN;
    

    return CUSTOM_VENC_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_MPEG4_GetNumOfEntries(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Output;

    if (!(pvOutput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pu4Output) == u4OutputSize))  { ASSERT(0); }

    _rCustomVencMpeg4Mgr.u2TableEntries = _CustomVenc_MPEG4_ComputeNumOfEntries();
    pu4Output = (kal_uint32*)pvOutput;
    *pu4Output = _rCustomVencMpeg4Mgr.u2TableEntries;

    return CUSTOM_VENC_ERROR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_MPEG4_GetOneEntry(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Index;
    CUSTOM_VENC_UPPER_TABLE_T *prUpperTable;
    CUSTOM_VENC_REC_MPEG4_UPPER_TABLE_T *prUpperTableNew;

    if (!(pvInput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pu4Index) == u4InputSize))  { ASSERT(0); }
    pu4Index = (kal_uint32*)pvInput;
    if (!(_rCustomVencMpeg4Mgr.u2TableEntries != CUSTOM_VENC_MPEG4_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
    if (!(*pu4Index < _rCustomVencMpeg4Mgr.u2TableEntries))  { ASSERT(0); }

    if (!(pvOutput != NULL))  { ASSERT(0); }
    if (!(sizeof(*prUpperTable) == u4OutputSize))  { ASSERT(0); }
    prUpperTable = (CUSTOM_VENC_UPPER_TABLE_T*)pvOutput;
    prUpperTableNew = (CUSTOM_VENC_REC_MPEG4_UPPER_TABLE_T *)&_rMpeg4FrameRateTable[*pu4Index].rUpperTable;
    
    prUpperTable->eResolution = prUpperTableNew->eResolution;
    prUpperTable->eQuality = prUpperTableNew->eQuality;
    prUpperTable->eStorage = prUpperTableNew->eStorage;
    prUpperTable->eCodec = prUpperTableNew->eCodec;

    return CUSTOM_VENC_ERROR_NONE;
}

/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_MPEG4_GetOneEntryRecMPEG4(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Index;
    CUSTOM_VENC_REC_MPEG4_UPPER_TABLE_T *prUpperTable;

    if (!(pvInput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pu4Index) == u4InputSize))  { ASSERT(0); }
    pu4Index = (kal_uint32*)pvInput;
    if (!(_rCustomVencMpeg4Mgr.u2TableEntries != CUSTOM_VENC_MPEG4_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
    if (!(*pu4Index < _rCustomVencMpeg4Mgr.u2TableEntries))  { ASSERT(0); }

    if (!(pvOutput != NULL))  { ASSERT(0); }
    if (!(sizeof(*prUpperTable) == u4OutputSize))  { ASSERT(0); }
    prUpperTable = (CUSTOM_VENC_REC_MPEG4_UPPER_TABLE_T *)pvOutput;
    *prUpperTable = _rMpeg4FrameRateTable[*pu4Index].rUpperTable;

    return CUSTOM_VENC_ERROR_NONE;
}

//----------------------------------------------------------------------------

static CUSTOM_VENC_ERROR_T _CustomVenc_MPEG4_SetField(void *pvInput, kal_uint32 u4InputSize, int field_offset, int size_of_field)
{
    kal_uint32 *pInput = (kal_uint32 *) pvInput;

    if (!(pvInput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pInput) == u4InputSize))  { ASSERT(0); }

    switch (size_of_field)
    {
      case 1:
    {
        kal_uint8 *pField = (kal_uint8 *)((kal_uint8 *) &_rCustomVencMpeg4Mgr + field_offset);

        *pField = (kal_uint8) *pInput;
        break;
    }
      case 2:
    {
        kal_uint16 *pField = (kal_uint16 *)((kal_uint8 *) &_rCustomVencMpeg4Mgr + field_offset);

        *pField = (kal_uint16) *pInput;
        break;
}
      case 4:
{
        kal_uint32 *pField = (kal_uint32 *)((kal_uint8 *) &_rCustomVencMpeg4Mgr + field_offset);

        *pField = (kal_uint32) *pInput;
        break;
    }
      default:
    {
        ASSERT(0);
    }
}

    _CustomVenc_MPEG4_ClearTableSelection();

    return CUSTOM_VENC_ERROR_NONE;   
    }

//----------------------------------------------------------------------------
static CUSTOM_VENC_ERROR_T _CustomVenc_MPEG4_GetField(void *pvOutput, int u4OutputSize, int field_offset, int size_of_field)
{
    const kal_uint16 u2TableEntries = _rCustomVencMpeg4Mgr.u2TableEntries;
    kal_uint16 u2TableIndex;
    CUSTOM_VENC_ERROR_T eError;
    void *pTableEntry = NULL;
    kal_uint32 *pOutput = (kal_uint32 *) pvOutput;

    if (!pvOutput)                      { ASSERT(0); }
    if (sizeof(kal_uint32) != u4OutputSize)  { ASSERT(0); }

    eError = _CustomVenc_MPEG4_MakeTableSelection(&u2TableIndex);

    if (eError == CUSTOM_VENC_ERROR_NONE)
    {
        if (!(u2TableEntries != CUSTOM_VENC_MPEG4_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
        if (!(u2TableIndex != CUSTOM_VENC_MPEG4_UNKNOWN_TABLE_INDEX))  { ASSERT(0); }
        if (!(u2TableIndex < u2TableEntries))  { ASSERT(0); }

        pTableEntry = (void *) &_rMpeg4FrameRateTable[u2TableIndex];
    }
    else
    {
        pTableEntry = (void *) &_rDefaultMpeg4FrameRateTable[0];
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
static CUSTOM_VENC_ERROR_T _CustomVenc_MPEG4_Ctrl(CUSTOM_VENC_OP_T eOp,
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
      case CUSTOM_VENC_OP_GET_ALGORITHM:
          *pRes = g_mmi_em_recorder_setting.algorithm;
          eError = CUSTOM_VENC_ERROR_NONE;
          break;
      case CUSTOM_VENC_OP_GET_BIT_RATE:
          *pRes = g_mmi_em_recorder_setting.bit_rate * 1000;
          eError = CUSTOM_VENC_ERROR_NONE;
          break;
      case CUSTOM_VENC_OP_GET_RATE_HARD_LIMIT:
          *pRes = g_mmi_em_recorder_setting.rate_hard_limit;
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
        eError = _CustomVenc_MPEG4_SetUser(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES:
        eError = _CustomVenc_MPEG4_GetNumOfEntries(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_ONE_ENTRY:
        eError = _CustomVenc_MPEG4_GetOneEntry(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_ONE_ENTRY_REC_MPEG4:
        eError = _CustomVenc_MPEG4_GetOneEntryRecMPEG4(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;        

    case CUSTOM_VENC_OP_SET_WIDTH:
        eError = _CustomVenc_MPEG4_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MPEG4_MGR_T, u2Width), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_HEIGHT:
        eError = _CustomVenc_MPEG4_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MPEG4_MGR_T, u2Height), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_QUALITY:
        eError = _CustomVenc_MPEG4_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MPEG4_MGR_T, eQuality), sizeof(CUSTOM_VENC_QUALITY_T));
        break;

    case CUSTOM_VENC_OP_SET_STORAGE:
        eError = _CustomVenc_MPEG4_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MPEG4_MGR_T, eStorage), sizeof(CUSTOM_VENC_STORAGE_T));
        break;

    case CUSTOM_VENC_OP_SET_CODEC:
        eError = _CustomVenc_MPEG4_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MPEG4_MGR_T, eCodec), sizeof(CUSTOM_VENC_CODEC_T));
        break;

    case CUSTOM_VENC_OP_SET_ROTATE:
        eError = _CustomVenc_MPEG4_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MPEG4_MGR_T, eRotate), sizeof(CUSTOM_VENC_ROTATE_T));
        break;        

    case CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u2SensorFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_SENSOR_NIGHT_FRAME_RATE:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u2SensorNightFrameRate),       
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u2CodecFrameRate),
                                            sizeof(kal_uint16));  
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_NIGHT_FRAME_RATE:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u2CodecNightFrameRate),
                                            sizeof(kal_uint16)); 
        break;

    case CUSTOM_VENC_OP_GET_INIT_Q:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u1InitQ),
                                            sizeof(kal_uint8));
        break;

    case CUSTOM_VENC_OP_GET_MIN_QP:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u1MinQp),
                                            sizeof(kal_uint8)); 
        break;

    case CUSTOM_VENC_OP_GET_MAX_QP:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u1MaxQp),
                                            sizeof(kal_uint8)); 
        break;

    case CUSTOM_VENC_OP_GET_INTRA_VOP_RATE:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u2IntraVopRate),
                                            sizeof(kal_uint16)); 
        break;

    case CUSTOM_VENC_OP_GET_ALGORITHM:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u2Algorithm),
                                            sizeof(kal_uint16)); 
        break;

    case CUSTOM_VENC_OP_GET_BIT_RATE:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u4BitRate),
                                            sizeof(kal_uint32)); 
        break;

    case CUSTOM_VENC_OP_GET_RATE_HARD_LIMIT:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u4RateHardLimit),
                                            sizeof(kal_uint32));  
        break;

    case CUSTOM_VENC_OP_GET_RATE_BALANCE:
        eError = _CustomVenc_MPEG4_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T, u4RateBalance),
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
CUSTOM_VENC_ERROR_T CustomVenc_GetMpeg4CtrlFunction(PFN_CUSTOM_VENC_CTRL *ppfnCustomVencCtrl)
{
    if (!(ppfnCustomVencCtrl != NULL))  { ASSERT(0); }

    *ppfnCustomVencCtrl = _CustomVenc_MPEG4_Ctrl;

    return CUSTOM_VENC_ERROR_NONE;
}


#endif  // __MPEG4_ENC_SUPPORT__


#endif  // __VIDEO_ARCHI_V2__

