#ifndef _L1AUDIO_SPH_TRC_H
#define _L1AUDIO_SPH_TRC_H

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "l1audio_sph_trc_gen.h"
#endif /* TST Trace Defintion */
#endif


#define TRACE_GROUP_VOC    TRACE_GROUP_1
#define TRACE_GROUP_EPL    TRACE_GROUP_2
#define TRACE_GROUP_TRANSCODING         TRACE_GROUP_3
#define TRACE_GROUP_TRANSCODING_OUTPUT  TRACE_GROUP_4

BEGIN_TRACE_MAP(MOD_L1AUDIO_SPH_SRV)

   // Debug trace for VOC
   TRC_MSG(VOC_DATA,"VOC data")
   TRC_MSG(VOC_LENGTH,"Recording VOC length = %u bytes")
   TRC_MSG(SET_EPL_PARA, "EPL common parameter0 is set to %d")
   TRC_MSG(EPL_PARA_ERROR, "Invalid EPL common parameter0")
   TRC_MSG(DEBUG_NUMBER,"Debug number = %d")
   // Debug trace for SW transocding
   TRC_MSG(OPEN_FILE_FAIL, "Failed to open file")
   TRC_MSG(READ_FILE_FAIL, "Failed to read file")
   TRC_MSG(PATTERN_OUTPUT_DATA, "Test pattern output data")
   TRC_MSG(DECODER_OUTPUT_DATA, "Speech decoder output data")
   TRC_MSG(TRANSCODING_FRAME_NUMBER, "Transcoding frame number = %u")
   TRC_MSG(TRANSCODING_FAIL, "Transcoding failed. This pattern has %u frames")
   TRC_MSG(TRANSCODING_SUCCESS, "Transcoding success. This pattern has %u frames")

END_TRACE_MAP(MOD_L1AUDIO_SPH_SRV)

#endif
