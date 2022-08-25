
#ifndef VCODEC_DEC_DEMUXER_IF_H
#define VCODEC_DEC_DEMUXER_IF_H

typedef struct 
{
    unsigned int u4Address;
    unsigned int u4Length;
    int fgValid;
} RM_DECODER_PAYLOAD_INFO_T;

typedef struct
{
    unsigned int u4PayloadNumber;
    RM_DECODER_PAYLOAD_INFO_T* pu1PayloadAddress;
} RM_DECODER_INPUT_PARAM_T;

typedef enum
{
	RV8 = 0,
	RV9,
	RV10
}RM_CODEC_VERSION_T;

#define MAX_NUM_RPR_SIZES 8
typedef struct
{
    RM_CODEC_VERSION_T eDecoderVersion;
    unsigned int u4MaxDimWidth;
    unsigned int u4MaxDimHeight;
    unsigned int u4NumRPRSizes;
    unsigned int au4RPRSizes[2*MAX_NUM_RPR_SIZES];
} RM_DECODER_INIT_PARAM_T;

// The H264 uses the private data to transfer NAL units
// The related data structure informations are defined as below
//
typedef struct
{
    unsigned int MaxSupportWidthForYUV420_MPHP;
    unsigned int MaxSupportHeightForYUV420_MPHP;    
    unsigned int NormalMaxWidthForYUV420_MPHP;
    unsigned int NormalMaxHeightForYUV420_MPHP;
    unsigned int u4dpbSizes;
    unsigned int reserved[4];
} H264_DECODER_PRIVATE_PARAM_T;

typedef struct
{
    unsigned int MaxSupportWidthForYUV420_ASP;
    unsigned int MaxSupportHeightForYUV420_ASP;
    unsigned short u2FrameWidthInContainer;
    unsigned short u2FrameHeightInContainer;
} MPEG4_DECODER_PRIVATE_PARAM_T;

#ifdef __VE_KMV_SUPPORT__

#define KMV_META_LEN 400 // To be fixed

typedef struct
{
    kal_uint8  kmvMeta[KMV_META_LEN];
    kal_uint16 recH;
    kal_uint16 recW;
    kal_uint16 nsize;
    kal_uint8  tType;
} KMV_META_DATA_T;

#endif

typedef struct 
{
    unsigned int u4Address;
    unsigned int u4Length;
} H264_DECODER_PAYLOAD_INFO_T;

typedef struct
{
    unsigned int u4PayloadNumber;
    H264_DECODER_PAYLOAD_INFO_T* pu1PayloadAddress;

#ifdef __VE_KMV_SUPPORT__
    void *pu1KMVPayloadAddress;
    kal_uint32 u4KMVSize;    
#endif
    
} H264_DECODER_INPUT_PARAM_T;

typedef struct 
{
    unsigned int u4Address;
    unsigned int u4Length;
    unsigned short u2FrameWidthInContainer;
    unsigned short u2FrameHeightInContainer;
} MPEG4_DECODER_PAYLOAD_INFO_T;

typedef struct
{
    unsigned int u4PayloadNumber;
    MPEG4_DECODER_PAYLOAD_INFO_T* pu1PayloadAddress;
} MPEG4_DECODER_INPUT_PARAM_T;

typedef struct 
{
    unsigned int u4Address;
    unsigned int u4Length;
} MPEG4VT_DECODER_PAYLOAD_INFO_T;

typedef struct
{
    unsigned int u4PayloadNumber;
    MPEG4VT_DECODER_PAYLOAD_INFO_T* pu1PayloadAddress;
} MPEG4VT_DECODER_INPUT_PARAM_T;

typedef struct 
{
    unsigned int u4Address;
    unsigned int u4Length;
} VP8_DECODER_PAYLOAD_INFO_T;

typedef struct
{
    unsigned int u4PayloadNumber;
    VP8_DECODER_PAYLOAD_INFO_T* pu1PayloadAddress;
} VP8_DECODER_INPUT_PARAM_T;
#endif