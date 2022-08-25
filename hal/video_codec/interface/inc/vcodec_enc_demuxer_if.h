
#ifndef VCODEC_ENC_DEMUXER_IF_H
#define VCODEC_ENC_DEMUXER_IF_H

#define H264_MAX_SPS_SETS              10
#define H264_MAX_PPS_SETS              10
#define VCODEC_ENC_MAX_NALS_IN_SET        10

typedef struct
{
    unsigned char  u1ProfileIDC;            /* profile indication */
    unsigned char  u1ProfileComp;           /* profile compatibility */
    unsigned char  u1LevelIDC;              /* level indication */
    unsigned char  u1LengthMinusOne;
    unsigned char  u1NumOfSPS;
    //unsigned short aSPSLength[H264_MAX_SPS_SETS]; // SPS Length
    unsigned char  u1NumOfPPS;
    //unsigned short aPPSLength[H264_MAX_PPS_SETS]; // PPS Length
} H264_ENC_CONF_REC; // H.264 Decoder Configuration Record (.mp4 format)

#ifdef __H264_ENC_VT__
typedef struct
{
    int          u4NalUnitType;
    unsigned int u4Addr;        // p_payload
    unsigned int u4Size;        // i_payload
} VCODEC_ENC_CODEC_NAL_INFO_T;

typedef struct
{
    unsigned int 					u4NumOfNals;
    VCODEC_ENC_CODEC_NAL_INFO_T 	arNalInfo[VCODEC_ENC_MAX_NALS_IN_SET];
} VCODEC_ENC_NAL_SET_T;
#endif // __H264_ENC_VT__

#endif