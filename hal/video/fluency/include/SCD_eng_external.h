#ifndef SCD_ENG_EXTERNAL_H__
#define SCD_ENG_EXTERNAL_H__
#define IN
#define OUT
#define INOUT

#ifndef SCD_TRUE 
 #define SCD_TRUE 1
#elif SCD_TRUE != 1
 #error SCD_TRUE is not equal to 1
#endif

#ifndef SCD_FALSE 
 #define SCD_FALSE 0
#elif SCD_FALSE != 0
 #error SCD_FALSE is not equal to 0
#endif

typedef enum   
{  
	DET_YES = 0x0,
	DET_NO,
	DET_MARGIN,
	DET_SKIP,
	MAX_DETECT,
} SCD_DETECT_T;

typedef enum   
{  
	DET_CUT = 0x0,
	DET_FADE,
	DET_DISSOLVE,
	DET_TRANSITION,
	DET_MOTION,
	DET_NO_CHANGE,
	DET_UNKNOWN,
	DET_CUT_SL,
	DET_FADE_SL,
	DET_WIPE,
	MAX_SCENE,
} SCD_SCENE_T;


typedef struct SCD_OUTPUT_DATA
{	
	SCD_DETECT_T rDetect;
	SCD_SCENE_T rScene;
}SCD_OUTPUT_DATA_T;



typedef struct SCD_INIT_DATA
{	
	unsigned int u4Val;
}SCD_INIT_DATA_T;


typedef struct SCD_OPEN_DATA
{	
	unsigned int u4Framerate;
	unsigned int u4Bitrate;
	unsigned int u4Width;
	unsigned int u4Height;
}SCD_OPEN_DATA_T;


typedef enum
{
	SCD_PIC_FRAMETYPE_I,	
	SCD_PIC_FRAMETYPE_P,
	SCD_PIC_FRAMETYPE_B,   		
	SCD_PIC_UNKNOWN_TYPE,
	SCD_NUM_OF_PIC_FRAME_TYPE
} SCD_PIC_FRAME_TYPE_T;



typedef struct SCD_INPUT_DATA
{	
	SCD_PIC_FRAME_TYPE_T rCurr_Frame_type;
	unsigned int  u4Length;
	unsigned int  u4DetectB;
	unsigned int  u4NumIntraMB;
	unsigned int  u4NumInterMB;
	unsigned int  u4NumSkipMB;
	unsigned char *pu1ParamStream;
}SCD_INPUT_DATA_T;


typedef enum {
	SCD_OK			= 0x00000000,
	SCD_ERROR		= 0x00000001,	
	SCD_NO_INPUT	= 0x00000002,	
} SCD_STATUS; 

SCD_STATUS SCD_open(IN SCD_OPEN_DATA_T *rpOpenData);
SCD_STATUS SCD_init(IN SCD_INIT_DATA_T *rpInitData);
SCD_STATUS SCD_eng_V1(IN SCD_INPUT_DATA_T*input_data,OUT SCD_OUTPUT_DATA_T *output_data);


#endif