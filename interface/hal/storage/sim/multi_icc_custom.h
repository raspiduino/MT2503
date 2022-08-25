#ifndef __MULTI_ICC_CUSTOM_H__
#define __MULTI_ICC_CUSTOM_H__

#ifdef __GEMINI__
#ifdef GEMINI_PLUS
#define MAX_SIM_CARD_NUM (GEMINI_PLUS)
#else
#define MAX_SIM_CARD_NUM (2)
#endif /* GEMINI_PLUS */
#else
#define MAX_SIM_CARD_NUM (1)
#endif /* __GEMINI__ */

typedef enum
{
	MTK_SIMIF0,
	MTK_SIMIF1
}SIM_hwCtrlInfo;

typedef enum
{
	//SIM_ICC_APPLICATION_PHONE1 = 0x00000001,
	SIM_ICC_APPLICATION_PHONE1 = 0x00000000, //in sim driver UT, we play a trick on this enum
	SIM_ICC_APPLICATION_PHONE2,
	SIM_ICC_APPLICATION_CMMB_SMD,
	SIM_ICC_APPLICATION_PHONE3,
	SIM_ICC_APPLICATION_PHONE4
}SIM_ICC_APPLICATION;





#define SIM_MT6302_INFO_UDF	0xff
#define SIM_ICC_MT6302_NONE	0xffffffff


typedef struct
{
	kal_uint32 logicalNum;
	SIM_ICC_APPLICATION application;
	SIM_hwCtrlInfo hwCtrl;
	kal_uint8 needMT6302;
	kal_uint8 MT6302ChipNum; /*whip MT6302, if there are lots*/
	kal_uint8 MT6302PortNum; /*whip interface of this MT6302*/
	kal_uint8 hotSwap; /* support hot swap or not */
	kal_bool polarity; /* hot swap EINT poarity */
	kal_uint32 debounceTime; /* hot swap EINT debounce time */
} SIM_ICC_HW_SW_MAPPING;

typedef enum
{
	SIM_SWITCH_NONE,
	SIM_SWITCH_6302,
	SIM_SWITCH_6306,
	SIM_SWITCH_6314,
}SIM_ICC_SWITCHCONTROL;

typedef enum
{
   SIM_CUSTOM_T2D_GET_HOTSWAP_PROPERITY,
   SIM_CUSTOM_T2D_GET_HOTSWAP_DEBOUNDETIME,
   SIM_CUSTOM_T2D_UNKNOWN
}sim_custom_t2d;

extern kal_uint32 sim_get_ToalInterfaceCount(void);
#endif

