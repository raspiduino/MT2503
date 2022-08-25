/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_matv_mjpeg.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifdef __VIDEO_ARCHI_V2__

#ifdef __ATV_RECORD_SUPPORT__


#include <stddef.h>
#include "kal_release.h"

//#include "custom_video_enc_setting.h"
//#include "custom_video_enc_setting_matv_mjpeg_customer.h"
#include "custom_video_enc_setting_matv_mjpeg.h"
// The following file contains the default setting used when no table entry
// matches the search criteria specified by user.
#include "custom_video_enc_setting_default.h"

#include "custom_video_enc_matv_mjpeg.h"

#ifdef __MMI_EM_MISC_RECORDER_PARAM_AJUST__
#include "EngineerModeRecorderSetting.h"
#endif

#define MATV_MJPEG_TABLE        (_rCustomVencMatvMjpegMgr.u2TVFormat == CUSTOM_VENC_MATV_MJPEG_TV_FORMAT_NTSC ? _rMatvMjpegNTSCFrameRateTable : _rMatvMjpegPALFrameRateTable)
/*****************************************************************************
* Static global variables
*****************************************************************************/
static CUSTOM_VENC_MATV_MJPEG_MGR_T _rCustomVencMatvMjpegMgr;


/*****************************************************************************
* Clear the saved index of table selection.  All "Set" functions need to
* call this function so that the frame rate table will be search again with
* the new set value.
*****************************************************************************/
static __inline _CustomVenc_MATV_MJPEG_ClearTableSelection(void)
{
   _rCustomVencMatvMjpegMgr.u2TableIndex = CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_INDEX;
   _rCustomVencMatvMjpegMgr.u2TVFormat   = CUSTOM_VENC_MATV_MJPEG_TV_FORMAT_NTSC;
}


/*****************************************************************************
* Memory pointed by the input parameters is allocated by caller.
*****************************************************************************/
static CUSTOM_VENC_ERROR_T _CustomVenc_MATV_MJPEG_MakeTableSelection(kal_uint16 *pu2TableIndex)
{
    CUSTOM_VENC_ERROR_T eError = CUSTOM_VENC_ERROR_NONE;
    const kal_uint16 u2TableEntries = _rCustomVencMatvMjpegMgr.u2TableEntries;
    kal_uint16 u2TableIndex = _rCustomVencMatvMjpegMgr.u2TableIndex;

    VENC_MATV_MJPEG_ASSERT(u2TableEntries != CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_ENTRIES);
    VENC_MATV_MJPEG_ASSERT(_rCustomVencMatvMjpegMgr.u2Width != CUSTOM_VENC_MATV_MJPEG_UNKNOWN_WIDTH);
    VENC_MATV_MJPEG_ASSERT(_rCustomVencMatvMjpegMgr.u2Height != CUSTOM_VENC_MATV_MJPEG_UNKNOWN_HEIGHT);
    VENC_MATV_MJPEG_ASSERT(_rCustomVencMatvMjpegMgr.eQuality != CUSTOM_VENC_QUALITY_UNKNOWN);
    VENC_MATV_MJPEG_ASSERT(_rCustomVencMatvMjpegMgr.eStorage != CUSTOM_VENC_STORAGE_UNKNOWN);
    VENC_MATV_MJPEG_ASSERT(_rCustomVencMatvMjpegMgr.eCodec != CUSTOM_VENC_CODEC_UNKNOWN);

    {
        kal_uint16 u2Width, u2Height;
        CUSTOM_VENC_RESOLUTION_T eResolution;

        u2Width = _rCustomVencMatvMjpegMgr.u2Width;
        u2Height = _rCustomVencMatvMjpegMgr.u2Height;
        eError = CustomVenc_MapWidthAndHeightToResolution(u2Width, u2Height, &eResolution);
        VENC_MATV_MJPEG_ASSERT(eError == CUSTOM_VENC_ERROR_NONE);
        VENC_MATV_MJPEG_ASSERT(eResolution != CUSTOM_VENC_RESOLUTION_UNKNOWN);
        _rCustomVencMatvMjpegMgr.eResolution = eResolution;
    }

    if (u2TableIndex == CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_INDEX)
    {
        for (u2TableIndex = 0; u2TableIndex < u2TableEntries; u2TableIndex++)
        {
            if (MATV_MJPEG_TABLE[u2TableIndex].rUpperTable.eResolution == _rCustomVencMatvMjpegMgr.eResolution)
            {
                if ((MATV_MJPEG_TABLE[u2TableIndex].rUpperTable.eQuality == CUSTOM_VENC_QUALITY_ALL) ||
                    (MATV_MJPEG_TABLE[u2TableIndex].rUpperTable.eQuality == _rCustomVencMatvMjpegMgr.eQuality))
                {
                    if ((MATV_MJPEG_TABLE[u2TableIndex].rUpperTable.eStorage == CUSTOM_VENC_STORAGE_ALL) ||
                        (MATV_MJPEG_TABLE[u2TableIndex].rUpperTable.eStorage == _rCustomVencMatvMjpegMgr.eStorage))
                    {
                        if ((MATV_MJPEG_TABLE[u2TableIndex].rUpperTable.eCodec == CUSTOM_VENC_CODEC_ALL) ||
                            (MATV_MJPEG_TABLE[u2TableIndex].rUpperTable.eCodec == _rCustomVencMatvMjpegMgr.eCodec))
                        {
                            _rCustomVencMatvMjpegMgr.u2TableIndex = u2TableIndex;
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



static kal_uint16 _CustomVenc_MATV_MJPEG_ComputeNumOfEntries(void)
{
    VENC_MATV_MJPEG_ASSERT(sizeof(_rMatvMjpegNTSCFrameRateTable) != 0);
    VENC_MATV_MJPEG_ASSERT(sizeof(_rMatvMjpegPALFrameRateTable) != 0);
    VENC_MATV_MJPEG_ASSERT(sizeof(_rMatvMjpegNTSCFrameRateTable[0]) != 0);
    VENC_MATV_MJPEG_ASSERT(sizeof(_rMatvMjpegPALFrameRateTable[0]) != 0);
    VENC_MATV_MJPEG_ASSERT(sizeof(_rDefaultMatvMjpegFrameRateTable) != 0);
    VENC_MATV_MJPEG_ASSERT(sizeof(_rDefaultMatvMjpegFrameRateTable[0]) != 0);

    if (CUSTOM_VENC_MATV_MJPEG_TV_FORMAT_NTSC == (_rCustomVencMatvMjpegMgr.u2TVFormat))
    {
       return (sizeof(_rMatvMjpegNTSCFrameRateTable) / sizeof(_rMatvMjpegNTSCFrameRateTable[0]));
    }
    else
    {
       return (sizeof(_rMatvMjpegPALFrameRateTable) / sizeof(_rMatvMjpegPALFrameRateTable[0]));
    }
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MATV_MJPEG_SetUser(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    // Clear all internal variables.
    _rCustomVencMatvMjpegMgr.u2Width = CUSTOM_VENC_MATV_MJPEG_UNKNOWN_WIDTH;
    _rCustomVencMatvMjpegMgr.u2Height = CUSTOM_VENC_MATV_MJPEG_UNKNOWN_HEIGHT;
    _rCustomVencMatvMjpegMgr.u2TableEntries = _CustomVenc_MATV_MJPEG_ComputeNumOfEntries();;
    _rCustomVencMatvMjpegMgr.u2TableIndex = CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_INDEX;
    _rCustomVencMatvMjpegMgr.eResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
    _rCustomVencMatvMjpegMgr.eQuality = CUSTOM_VENC_QUALITY_UNKNOWN;
    _rCustomVencMatvMjpegMgr.eStorage = CUSTOM_VENC_STORAGE_UNKNOWN;
    _rCustomVencMatvMjpegMgr.eCodec = CUSTOM_VENC_CODEC_UNKNOWN;

    if (*((CUSTOM_VENC_USER_T*) pvInput) == CUSTOM_VENC_USER_MATV_MJPEG_NTSC)
    {
       _rCustomVencMatvMjpegMgr.u2TVFormat = CUSTOM_VENC_MATV_MJPEG_TV_FORMAT_NTSC;
    }
    else if (*((CUSTOM_VENC_USER_T*) pvInput) == CUSTOM_VENC_USER_MATV_MJPEG_PAL)
    {
       _rCustomVencMatvMjpegMgr.u2TVFormat = CUSTOM_VENC_MATV_MJPEG_TV_FORMAT_PAL;
    }
    else
    {
       ASSERT(0);
    }   

    return CUSTOM_VENC_ERROR_NONE;
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MATV_MJPEG_GetNumOfEntries(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Output;

    VENC_MATV_MJPEG_ASSERT(pvOutput != NULL);
    VENC_MATV_MJPEG_ASSERT(sizeof(*pu4Output) == u4OutputSize);

    _rCustomVencMatvMjpegMgr.u2TableEntries = _CustomVenc_MATV_MJPEG_ComputeNumOfEntries();
    pu4Output = (kal_uint32*)pvOutput;
    *pu4Output = _rCustomVencMatvMjpegMgr.u2TableEntries;

    return CUSTOM_VENC_ERROR_NONE;
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MATV_MJPEG_GetOneEntry(void *pvInput,
        kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    kal_uint32 *pu4Index;
    CUSTOM_VENC_UPPER_TABLE_T *prUpperTable;

    VENC_MATV_MJPEG_ASSERT(pvInput != NULL);
    VENC_MATV_MJPEG_ASSERT(sizeof(*pu4Index) == u4InputSize);
    pu4Index = (kal_uint32*)pvInput;
    VENC_MATV_MJPEG_ASSERT(_rCustomVencMatvMjpegMgr.u2TableEntries != CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_ENTRIES);
    VENC_MATV_MJPEG_ASSERT(*pu4Index < _rCustomVencMatvMjpegMgr.u2TableEntries);

    VENC_MATV_MJPEG_ASSERT(pvOutput != NULL);
    VENC_MATV_MJPEG_ASSERT(sizeof(*prUpperTable) == u4OutputSize);
    prUpperTable = (CUSTOM_VENC_UPPER_TABLE_T*)pvOutput;
    *prUpperTable = MATV_MJPEG_TABLE[*pu4Index].rUpperTable;

    return CUSTOM_VENC_ERROR_NONE;
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MATV_MJPEG_SetField(void *pvInput, kal_uint32 u4InputSize, int field_offset, int size_of_field)
{
    kal_uint32 *pInput = (kal_uint32 *) pvInput;
    
    if (!(pvInput != NULL))  { ASSERT(0); }
    if (!(sizeof(*pInput) == u4InputSize))  { ASSERT(0); }
      
    switch (size_of_field)
    {
      case 1:
      {
        kal_uint8 *pField = (kal_uint8 *)((kal_uint8 *) &_rCustomVencMatvMjpegMgr + field_offset);

        *pField = (kal_uint8) *pInput;
        break;
      }
      case 2:
      {
        kal_uint16 *pField = (kal_uint16 *)((kal_uint8 *) &_rCustomVencMatvMjpegMgr + field_offset);

        *pField = (kal_uint16) *pInput;
        break;
      }        
      case 4:
      {
        kal_uint32 *pField = (kal_uint32 *)((kal_uint8 *) &_rCustomVencMatvMjpegMgr + field_offset);

        *pField = (kal_uint32) *pInput;
        break;
      }        
      default:
      {
        ASSERT(0);
      }
    }

    _CustomVenc_MATV_MJPEG_ClearTableSelection();

    return CUSTOM_VENC_ERROR_NONE;   
}



static CUSTOM_VENC_ERROR_T _CustomVenc_MATV_MJPEG_GetField(void *pvOutput, int u4OutputSize, int field_offset, int size_of_field)
{
    const kal_uint16 u2TableEntries = _rCustomVencMatvMjpegMgr.u2TableEntries;
    kal_uint16 u2TableIndex;
    CUSTOM_VENC_ERROR_T eError;
    void *pTableEntry = NULL;
    kal_uint32 *pOutput = (kal_uint32 *) pvOutput;

    if (!pvOutput)                      { ASSERT(0); }
    if (sizeof(kal_uint32) != u4OutputSize)  { ASSERT(0); }

    eError = _CustomVenc_MATV_MJPEG_MakeTableSelection(&u2TableIndex);
    if (eError == CUSTOM_VENC_ERROR_NONE)
    {
        if (!(u2TableEntries != CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_ENTRIES))  { ASSERT(0); }
        if (!(u2TableIndex != CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_INDEX))  { ASSERT(0); }
        if (!(u2TableIndex < u2TableEntries))  { ASSERT(0); }
        pTableEntry = (void *) &MATV_MJPEG_TABLE[u2TableIndex];
    }
    else
    {
        pTableEntry = (void *) &_rDefaultMatvMjpegFrameRateTable[0];
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



static CUSTOM_VENC_ERROR_T _CustomVenc_MATV_MJPEG_Ctrl(CUSTOM_VENC_OP_T eOp,
    void *pvInput, kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    CUSTOM_VENC_ERROR_T eError;

    switch (eOp)
    {
    case CUSTOM_VENC_OP_SET_USER:
        eError = _CustomVenc_MATV_MJPEG_SetUser(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES:
        eError = _CustomVenc_MATV_MJPEG_GetNumOfEntries(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_GET_ONE_ENTRY:
        eError = _CustomVenc_MATV_MJPEG_GetOneEntry(pvInput, u4InputSize, pvOutput, u4OutputSize);
        break;

    case CUSTOM_VENC_OP_SET_WIDTH:
        eError = _CustomVenc_MATV_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MATV_MJPEG_MGR_T, u2Width), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_HEIGHT:
        eError = _CustomVenc_MATV_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MATV_MJPEG_MGR_T, u2Height), sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_SET_QUALITY:
        eError = _CustomVenc_MATV_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MATV_MJPEG_MGR_T, eQuality), sizeof(CUSTOM_VENC_QUALITY_T));
        break;

    case CUSTOM_VENC_OP_SET_STORAGE:
        eError = _CustomVenc_MATV_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MATV_MJPEG_MGR_T, eStorage), sizeof(CUSTOM_VENC_STORAGE_T));
        break;

    case CUSTOM_VENC_OP_SET_CODEC:
        eError = _CustomVenc_MATV_MJPEG_SetField(pvInput, u4InputSize, offsetof(CUSTOM_VENC_MATV_MJPEG_MGR_T, eCodec), sizeof(CUSTOM_VENC_CODEC_T));
        break;

    case CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE:
        eError = _CustomVenc_MATV_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_MATV_MJPEG_LOWER_TABLE_T, u2SensorFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_SENSOR_NIGHT_FRAME_RATE:
        eError = _CustomVenc_MATV_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_MATV_MJPEG_LOWER_TABLE_T, u2SensorNightFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE:
        eError = _CustomVenc_MATV_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_MATV_MJPEG_LOWER_TABLE_T, u2CodecFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_ENCODER_NIGHT_FRAME_RATE:
        eError = _CustomVenc_MATV_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_MATV_MJPEG_LOWER_TABLE_T, u2CodecNightFrameRate), 
                                            sizeof(kal_uint16));
        break;

    case CUSTOM_VENC_OP_GET_BIT_RATE:
        eError = _CustomVenc_MATV_MJPEG_GetField(pvOutput, 
                                            u4OutputSize, 
                                            offsetof(VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T, rLowerTable) + 
                                            offsetof(CUSTOM_VENC_MATV_MJPEG_LOWER_TABLE_T, u4BitRate), 
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



CUSTOM_VENC_ERROR_T CustomVenc_GetMatvMjpegCtrlFunction(PFN_CUSTOM_VENC_CTRL *ppfnCustomVencCtrl)
{
    VENC_MATV_MJPEG_ASSERT(ppfnCustomVencCtrl != NULL);

    *ppfnCustomVencCtrl = _CustomVenc_MATV_MJPEG_Ctrl;

    return CUSTOM_VENC_ERROR_NONE;
}


#endif  // __ATV_RECORD_SUPPORT__


#endif  // __VIDEO_ARCHI_V2__

