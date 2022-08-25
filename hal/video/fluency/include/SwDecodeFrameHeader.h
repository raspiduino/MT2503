#ifndef SW_DEC_FRAME_HDR_H
#define SW_DEC_FRAME_HDR_H

#define IN
#define OUT
#define INOUT

typedef enum
{
	VCODEC_PIC_FRAMETYPE_I,	
	VCODEC_PIC_FRAMETYPE_I_NS, // non-seek I, non-IDR frame
	VCODEC_PIC_FRAMETYPE_I_FC, // Forced I 
	VCODEC_PIC_FRAMETYPE_I_ND, // non-display I
	VCODEC_PIC_FRAMETYPE_P,
	VCODEC_PIC_FRAMETYPE_P_ND, // non-display P
	VCODEC_PIC_FRAMETYPE_S,    // GMC frame 	
	VCODEC_PIC_FRAMETYPE_B,   	
	VCODEC_PIC_UNKNOWN_TYPE,
	NUM_OF_PIC_FRAME_TYPE
} VCODEC_DEC_FRAME_TYPE_T;


typedef enum
{
	VCODEC_DEC_FRAME_HDR_OK,
	VCODEC_DEC_FRAME_HDR_ERROR,	
	NUM_OF_DEC_FRAME_HDR_ERROR_TYPE
} VCODEC_DEC_FRAME_HDR_ERROR_T;

typedef enum   
{
	INPUT_FLAG_FRAME_TYPE		=  0x01, //decode frame type
	INPUT_FLAG_RESOLUTION	    =  0x02, //decode resoultion  	 
    INPUT_FLAG_MAX_DEC_FRAME_HDR              
} VCODEC_DEC_FRAME_HDR_FLAG_T;


typedef struct 
{    
    VCODEC_DEC_FRAME_TYPE_T eFrameType;
	unsigned int u4Width;
	unsigned int u4Height;	
	unsigned int PrivateData[4];	 
} VCODEC_DEC_FRAME_HDR_INFO_T; 


typedef struct 
{
    unsigned int   eFlags;   // VCODEC_DEC_FRAME_HDR_FLAG_T
    unsigned char* pByteStrm;
    unsigned int     u4Len;	 
} VCODEC_DEC_FRAME_HDR_INPUT_T;


VCODEC_DEC_FRAME_HDR_ERROR_T VP8SwDecDecodeFrameHeader(IN VCODEC_DEC_FRAME_HDR_INPUT_T *prInput , OUT VCODEC_DEC_FRAME_HDR_INFO_T *prOutput);
VCODEC_DEC_FRAME_HDR_ERROR_T MP4SwDecDecodeFrameHeader(IN VCODEC_DEC_FRAME_HDR_INPUT_T *prInput ,OUT VCODEC_DEC_FRAME_HDR_INFO_T *prOutput);
VCODEC_DEC_FRAME_HDR_ERROR_T H263SwDecDecodeFrameHeader(IN VCODEC_DEC_FRAME_HDR_INPUT_T *prInput ,OUT VCODEC_DEC_FRAME_HDR_INFO_T *prOutput);
VCODEC_DEC_FRAME_HDR_ERROR_T RVSwDecDecodeFrameHeader(IN VCODEC_DEC_FRAME_HDR_INPUT_T *prInput ,OUT VCODEC_DEC_FRAME_HDR_INFO_T *prOutput);
VCODEC_DEC_FRAME_HDR_ERROR_T H264SwDecDecodeFrameHeader(IN VCODEC_DEC_FRAME_HDR_INPUT_T *prInput ,OUT VCODEC_DEC_FRAME_HDR_INFO_T *prOutput);


#endif