#ifndef CAPACITIVE_TP_FT5206_H
#define CAPACITIVE_TP_FT5206_H


#define CTP_SLAVE_ADDR	    0x70

//Controller parameter getting/setting flag
#define CTP_RESOLUTION 		0x01
#define CTP_THRESHOLD 		0x02
#define CTP_IDLE_INTERVAL 	0x04
#define CTP_SLEEP_INTERVAL 	0x08

//Controller Mode
#define CTP_NORMAL_OPERATION 	0x0B
#define CTP_SYSTEM_INFORMATION 	0x1B
#define CTP_ACTIVE_MODE 		0x4B

#define CTP_IDLE_MODE 	0x08
#define CTP_SLEEP_MODE 	0x10
#define CTP_DEBUG_MODE 	0x1B

#define CTP_GESTURE_DETECTION_MODE 	0x40
#define CTP_MULTIPLE_POINT_MODE 	0x80

//ADDRESS
#define HST_MODE_ADDR 		0x00  
#define HST_MODE_NORMAL 	0x1B   
#define HST_MODE_SYSTEM_INFORMATION 0x1B
#define HST_MODE_TEST  		0X4B

#define GEST_ID_ADDR 	0x01  
#define GEST_ID_NUMBER 	0xFF  

#define TD_STAT_ADDR 0x2
#define TD_STAT_NUMBER_TOUCH 0x07
#define TT_MODE_BUFFER_INVALID 0x08		//1-5 VALIDE

#define TOUCH1_ID 			0xF0
#define TOUCH1_EVEN_FLAG 	0xC0
#define TOUCH1_XH_ADDR 		0x03
#define TOUCH1_XL_ADDR 		0x04
#define TOUCH1_YH_ADDR 		0x05
#define TOUCH1_YL_ADDR 		0x06

#define TOUCH2_ID 			0xF0
#define TOUCH2_EVEN_FLAG 	0xC0
#define TOUCH2_XH_ADDR 		0x09
#define TOUCH2_XL_ADDR 		0x0A
#define TOUCH2_YH_ADDR 		0x0B
#define TOUCH2_YL_ADDR 		0x0C

#define TOUCH3_ID 			0xF0
#define TOUCH3_EVEN_FLAG 	0xC0
#define TOUCH3_XH_ADDR 		0x0F
#define TOUCH3_XL_ADDR 		0x10
#define TOUCH3_YH_ADDR 		0x11
#define TOUCH3_YL_ADDR 		0x12

#define TOUCH4_ID 			0xF0
#define TOUCH4_EVEN_FLAG 	0xC0
#define TOUCH4_XH_ADDR 		0x15
#define TOUCH4_XL_ADDR 		0x16
#define TOUCH4_YH_ADDR 		0x17
#define TOUCH4_YL_ADDR 		0x18

#define TOUCH5_ID 			0xF0
#define TOUCH5_EVEN_FLAG 	0xC0
#define TOUCH5_XH_ADDR 		0x1B
#define TOUCH5_XL_ADDR 		0x1C
#define TOUCH5_YH_ADDR 		0x1D
#define TOUCH5_YL_ADDR 		0x1E



#define CTP_BL_FILE          	0x00
#define CTP_BL_CMD           	0xFF
#define CTP_BL_EXIT          	0xA5
#define CTP_BL_SECUTITY_KEY1 	0x00
#define CTP_BL_SECUTITY_KEY2 	0x01
#define CTP_BL_SECUTITY_KEY3 	0x02
#define CTP_BL_SECUTITY_KEY4 	0x03
#define CTP_BL_SECUTITY_KEY5 	0x04
#define CTP_BL_SECUTITY_KEY6 	0x05
#define CTP_BL_SECUTITY_KEY7 	0x06
#define CTP_BL_SECUTITY_KEY8 	0x07
#define ACT_INTRVL_ADDR  		0x1D

typedef struct
{   
	kal_uint32 start_offset;
	kal_uint32 write_flash_pointer;
	kal_uint32 read_flash_pointer;
	kal_uint32 value;
}CTP_firmware_struct;

#endif 	//CAPACITIVE_TP_FT5206_H