/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_mjpeg.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifdef __VIDEO_ARCHI_V2__


/// __AVI_ENC_SUPPORT__ is a global option.
#ifdef __AVI_ENC_SUPPORT__


#include <stddef.h>
#include "kal_release.h"

///#include "custom_video_enc_setting.h"
#include "custom_video_enc_setting_mjpeg_customer.h"
#include "custom_video_enc_setting_mjpeg.h"
// The following file contains the default setting used when no table entry
// matches the search criteria specified by user.
#include "custom_video_enc_setting_default.h"

#include "custom_video_enc_mjpeg.h"


/*****************************************************************************
* Static global variables
*****************************************************************************/
static CUSTOM_VENC_MJPEG_MGR_T _rCustomVencMjpegMgr;


/*****************************************************************************
* Clear the saved index of table selection.  All "Set" functions need to
* call this function so that the frame rate table will be search again with
* the new set value.
*****************************************************************************/
static __inline _CustomVenc_MJPEG_ClearTableSelection(void)
{
    _rCustomVencMjpegMgr.u2TableIndex = CUSTOM_VENC_MJPEG_UNKNOWN_TABLE_INDEX;
}


/*****************************************************************************
* Memory pointed by the input parameters is allocated by caller.
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_MJPEG_MakeTableSelection(kal_uint16 *pu2TableIndex)
{
    CUSTOM_VENC_ERROR_T eError = CUSTOM_VENC_ERROR_NONE;
    const kal_uint16 u2TableEntries = _rCustomVencMjpegMgr.u2TableEntries;
    kal_uint16 u2TableIndex = _rCustomVencMjpegMgr.u2TableIndex;

    if ((u2TableEntries == CUSTOM_VENC_MJPEG_UNKNOWN_TABLE_ENTRIES) ||
        (_rCustomVencMjpegMgr.u2Width == CUSTOM_VENC_MJPEG_UNKNOWN_WIDTH) ||
        (_rCustomVencMjpegMgr.u2Height == CUSTOM_VENC_MJPEG_UNKNOWN_HEIGHT) ||
        (_rCustomVencMjpegMgr.eQuality == CUSTOM_VENC_QUALITY_UNKNOWN) ||
        (_rCustomVencMjpegMgr.eStorage == CUSTOM_VENC_STORAGE_UNKNOWN) ||
        (_rCustomVencMjpegMgr.eCodec == CUSTOM_VENC_CODEC_UNKNOWN)
       )
    {
        ASSERT(0);
    }

    {
        kal_uint16 u2Width, u2Height;
        CUSTOM_VENC_RESOLUTION_T eResolution;

        u2Width = _rCustomVencMjpegMgr.u2Width;
        u2Height = _rCustomVencMjpegMgr.u2Height;
        eError = CustomVenc_MapWidthAndHeightToResolution(u2Width, u2Height, &eResolution);
        if ((eError != CUSTOM_VENC_ERROR_NONE) ||
            (eResolution == CUSTOM_VENC_RESOLUTION_UNKNOWN)
           )
        {
            ASSERT(0);
        }
        _rCustomVencMjpegMgr.eResolution = eResolution;
    }

    if (u2TableIndex == CUSTOM_VENC_MJPEG_UNKNOWN_TABLE_INDEX)
    {
        for (u2TableIndex = 0; u2TableIndex < u2TableEntries; u2TableIndex++)
        {
            if (_rMjpegFrameRateTable[u2TableIndex].rUpperTable.eResolution == _rCustomVencMjpegMgr.eResolution)
            {
                if ((_rMjpegFrameRateTable[u2TableIndex].rUpperTable.eQuality == CUSTOM_VENC_QUALITY_ALL) ||
                    (_rMjpegFrameRateTable[u2TableIndex].rUpperTable.eQuality == _rCustomVencMjpegMgr.eQuality))
                {
                    if ((_rMjpegFrameRateTable[u2TableIndex].rUpperTable.eStorage == CUSTOM_VENC_STORAGE_ALL) ||
                        (_rMjpegFrameRateTable[u2TableIndex].rUpperTable.eStorage == _rCustomVencMjpegMgr.eStorage))
                    {
                        if ((_rMjpegFrameRateTable[u2TableIndex].rUpperTable.eCodec == CUSTOM_VENC_CODEC_ALL) ||
                            (_rMjpegFrameRateTable[u2TableIndex].rUpperTable.eCodec == _rCustomVencMjpegMgr.eCodec))
                        {
                            _rCustomVencMjpegMgr.u2TableIndex = u2TableIndex;
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



static kal_uint16 _CustomVenc_MJPEG_ComputeNumOfEntries(void)
{
    if ((sizeof(_rMjpegFrameRateTable) == 0) ||
        (sizeof(_rMjpegFrameRateTable[0]) == 0) ||
        (sizeof(_rDefaultMjpegFrameRateTable) == 0) ||
        (sizeof(_rDefaultMjpegFrameRateTable[0]) == 0)
       )
    {
        ASSERT(0);
    }

    return (kal_uint16)(sizeof(_rMjpegFrameRateTable) / sizeof(_rMjpegFrameRateTable[0]));
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MJPEG_SetUser(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    // Clear all internal variables.
    _rCustomVencMjpegMgr.u2Width = CUSTOM_VENC_MJPEG_UNKNOWN_WIDTH;
    _rCustomVencMjpegMgr.u2Height = CUSTOM_VENC_MJPEG_UNKNOWN_HEIGHT;
    _rCustomVencMjpegMgr.u2TableEntries = _CustomVenc_MJPEG_ComputeNumOfEntries();
    _rCustomVencMjpegMgr.u2TableIndex = CUSTOM_VENC_MJPEG_UNKNOWN_TABLE_INDEX;
    _rCustomVencMjpegMgr.eResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
    _rCustomVencMjpegMgr.eQuality = CUSTOM_VENC_QUALITY_UNKNOWN;
    _rCustomVencMjpegMgr.eStorage = CUSTOM_VENC_STORAGE_UNKNOWN;
    _rCustomVencMjpegMgr.eCodec = CUSTOM_VENC_CODEC_UNKNOWN;

    return CUSTOM_VENC_ERROR_NONE;
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MJPEG_GetNumOfEntries(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Output;

    if ((pvOutput == NULL) ||
        (sizeof(*pu4Output) != u4OutputSize)
       )
    {
        ASSERT(0);
    }

    _rCustomVencMjpegMgr.u2TableEntries = _CustomVenc_MJPEG_ComputeNumOfEntries();
    pu4Output = (kal_uint32*)pvOutput;
    *pu4Output = _rCustomVencMjpegMgr.u2TableEntries;

    return CUSTOM_VENC_ERROR_NONE;
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MJPEG_GetOneEntry(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Index;
    CUSTOM_VENC_UPPER_TABLE_T *prUpperTable;

    pu4Index = (kal_uint32*)pvInput;

    if ((pvInput == NULL) ||
        (sizeof(*pu4Index) != u4InputSize) ||
        (_rCustomVencMjpegMgr.u2TableEntries == CUSTOM_VENC_MJPEG_UNKNOWN_TABLE_ENTRIES) ||
        (*pu4Index >= _rCustomVencMjpegMgr.u2TableEntries) ||
        (pvOutput == NULL) ||
        (sizeof(*prUpperTable) != u4OutputSize)
       )
    {
        ASSERT(0);
    }

    prUpperTable = (CUSTOM_VENC_UPPER_TABLE_T*)pvOutput;
    *prUpperTable = _rMjpegFrameRateTable[*pu4Index].rUpperTable;

    return CUSTOM_VENC_ERROR_NONE;
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MJPEG_SetField(void *pvInput, kal_uint32 u4InputSize, int field_offset, int size_of_field)
{
    kal_uint32 *pInput = (kal_uint32 *) pvInput;
    
    if (!(pvInput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pInput) == u4InputSize))  { ASSERT(0); }
      
    switch (size_of_field)
    {
      case 1:
      {
        kal_uint8 *pField = (kal_uint8 *)((kal_uint8 *) &_rCustomVencMjpegMgr + field_offset);

        *pField = (kal_uint8) *pInput;
        break;
      }
      case 2:
      {
        kal_uint16 *pField = (kal_uint16 *)((kal_uint8 *) &_rCustomVencMjpegMgr + field_offset);

        *pField = (kal_uint16) *pInput;
        break;
      }        
      case 4:
      {
        kal_uint32 *pField = (kal_uint32 *)((kal_uint8 *) &_rCustomVencMjpegMgr + field_offset);

        *pField = (kal_uint32) *pInput;
        break;
      }        
      default:
      {
        ASSERT(0);
      }
    }

    _CustomVenc_MJPEG_ClearTableSelection();

    return CUSTOM_VENC_ERROR_NONE;   
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MJPEG_GetField(void *pvOutput, int u4OutputSize, int field_offset, int size_of_field)
{
    const kal_uint16 u2TableEntries = _rCustomVencMjpegMgr.u2TableEntries;
    kal_uint16 u2TableIndex;
    CUSTOM_VENC_ERROR_T eError;
    void *pTableEntry = NULL;
    kal_uint32 *pOutput = (kal_uint32 *) pvOutput;

    if (!pvOutput)                      { ASSERT(0); }
    if (sizeof(kal_uint32) != u4OutputSize)  { ASSERT(0); }

    eError = _CustomVenc_MJPEG_MakeTableSelection(&u2TableIndex);
    if (eError == CUSTOM_VENC_ERROR_NONE)
    {
        if (!(u2TableEntries != CUSTOM_VENC_MJPEG_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
        if (!(u2TableIndex != CUSTOM_VENC_MJPEG_UNKNOWN_TABLE_INDEX))  { ASSERT(0); }
        if (!(u2TableIndex < u2TableEntries))  { ASSERT(0); }
        pTableEntry = (void *) &_rMjpegFrameRateTable[u2TableIndex];
    }
    else
    {
        pTableEntry = (void *) &_rDefaultMjpegFrameRateTable[0];
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



static CUSTOM_VENC_ERROR_T _CustomVenc_MJPEG_Ctrl(CUSTOM_VENC_OP_T eOp,
    void *pvInput, kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    CUSTOM_VENC_ERROR_T eError;

    switch (eOp)
    {
    case CUSTOM_VENC_OP_SET_USER:
        eError = _CustomVenc_MJPEG_SetUser(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES:
        eError = _CustomVenc_MJPEG_GetNumOfEntries(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_ONE_ENTRY:
        eError = _CustomVenc_MJPEG_GetOneEntry(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_SET_WIDTH:
        eError = _CustomVenc_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MJPEG_MGR_T, u2Width), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_HEIGHT:
        eError = _CustomVenc_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MJPEG_MGR_T, u2Height), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_QUALITY:
        eError = _CustomVenc_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MJPEG_MGR_T, eQuality), sizeof(CUSTOM_VENC_QUALITY_T));
        break;

    case CUSTOM_VENC_OP_SET_STORAGE:
        eError = _CustomVenc_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MJPEG_MGR_T, eStorage), sizeof(CUSTOM_VENC_STORAGE_T));
        break;

    case CUSTOM_VENC_OP_SET_CODEC:
        eError = _CustomVenc_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MJPEG_MGR_T, eCodec), sizeof(CUSTOM_VENC_CODEC_T));
        break;

    case CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE:
        eError = _CustomVenc_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MJPEG_LOWER_TABLE_T, u2SensorFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_SENSOR_NIGHT_FRAME_RATE:
        eError = _CustomVenc_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MJPEG_LOWER_TABLE_T, u2SensorNightFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE:
        eError = _CustomVenc_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MJPEG_LOWER_TABLE_T, u2CodecFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_NIGHT_FRAME_RATE:
        eError = _CustomVenc_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MJPEG_LOWER_TABLE_T, u2CodecNightFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_BIT_RATE:
        eError = _CustomVenc_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_REC_MJPEG_LOWER_TABLE_T, u4BitRate), 
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



CUSTOM_VENC_ERROR_T CustomVenc_GetMjpegCtrlFunction(PFN_CUSTOM_VENC_CTRL *ppfnCustomVencCtrl)
{
    if (ppfnCustomVencCtrl == NULL)
    {
        ASSERT(0);
    }

    *ppfnCustomVencCtrl = _CustomVenc_MJPEG_Ctrl;

    return CUSTOM_VENC_ERROR_NONE;
}


#endif  // __AVI_ENC_SUPPORT__


#endif  // __VIDEO_ARCHI_V2__

