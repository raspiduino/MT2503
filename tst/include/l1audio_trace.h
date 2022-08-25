#ifndef L1TRC_L1Audio_DEF_H
#define L1TRC_L1Audio_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1AUDIO_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1AUDIO_Str_onoff(v1)  (unsigned char)(v1+2)
#define L1AUDIO_Func_Name(v1)  (unsigned char)(v1+4)
#define AFE_Switch_Name(v1)  (unsigned char)(v1+12)
#define AM_Switch_Name(v1)  (unsigned char)(v1+17)
#define AM_IO_Name(v1)  (unsigned char)(v1+29)
#define AM_Speech_Feature_Name(v1)  (unsigned char)(v1+33)
#define L1Audio_Speech_State(v1)  (unsigned char)(v1+38)
#define L1SP_Speech_Codec_Mode(v1)  (unsigned char)(v1+44)
#define L1SP_Speech_TX_Type(v1)  (unsigned char)(v1+55)
#define L1SP_Speech_RX_Type(v1)  (unsigned char)(v1+59)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER)
	#define L1Audio_Msg_AFE_Switch(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_Switch((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1Audio_Msg_AFE_Switch(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AFE_TurnSpk(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_TurnSpk((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1Audio_Msg_AFE_TurnSpk(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AFE_TurnMIC(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_TurnMIC((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1Audio_Msg_AFE_TurnMIC(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AFE_SpkSelect(v1, v2, v3, v4, v5) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_SpkSelect((short)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define L1Audio_Msg_AFE_SpkSelect(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_Switch(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_Switch((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1Audio_Msg_AM_Switch(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_Handover(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_Handover((char)(v1));\
} while(0)
#else
	#define L1Audio_Msg_AM_Handover(v1)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_2G_Resync(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_2G_Resync((char)(v1), (char)(v2));\
} while(0)
#else
	#define L1Audio_Msg_AM_2G_Resync(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_IO_Switch(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_IO_Switch((unsigned char)(v1));\
} while(0)
#else
	#define L1Audio_Msg_AM_IO_Switch(v1)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_SetSpeech(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_SetSpeech((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1Audio_Msg_AM_SetSpeech(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_Speech_State(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_Speech_State((unsigned char)(v1));\
} while(0)
#else
	#define L1Audio_Msg_Speech_State(v1)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_DSP_INT(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_DSP_INT((unsigned short)(v1));\
} while(0)
#else
	#define L1Audio_Msg_DSP_INT(v1)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_DELAY_TABLE(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_DELAY_TABLE((short)(v1));\
} while(0)
#else
	#define L1Audio_Msg_AM_DELAY_TABLE(v1)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_SPEECH_FRAME(v1, v2, v3) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_SPEECH_FRAME((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1Audio_Msg_SPEECH_FRAME(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_SPEECH_CODEC(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_SPEECH_CODEC((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1Audio_Msg_SPEECH_CODEC(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_VM_DEBUG(v1, v2, v3) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_VM_DEBUG((unsigned short)(v1), (unsigned short)(v2), (unsigned short)(v3));\
} while(0)
#else
	#define L1Audio_Msg_VM_DEBUG(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_VBI_RESET() do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_VBI_RESET();\
} while(0)
#else
	#define L1Audio_Msg_VBI_RESET()
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_VBI_END() do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_VBI_END();\
} while(0)
#else
	#define L1Audio_Msg_VBI_END()
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_TCH_NOTIFY(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_TCH_NOTIFY((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1Audio_Msg_TCH_NOTIFY(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_INTERRAT_W2G() do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_INTERRAT_W2G();\
} while(0)
#else
	#define L1Audio_Msg_INTERRAT_W2G()
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_INTERRAT_G2W() do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_INTERRAT_G2W();\
} while(0)
#else
	#define L1Audio_Msg_INTERRAT_G2W()
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_SWITCH_FILT(v1, v2) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_SWITCH_FILT((short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1Audio_Msg_SWITCH_FILT(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AFE_RegBackup(v1) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1Audio_Msg_AFE_RegBackup((unsigned char)(v1));\
} while(0)
#else
	#define L1Audio_Msg_AFE_RegBackup(v1)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_SRC1(v1, v2, v3) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_SRC1((unsigned short)(v1), (unsigned short)(v2), (unsigned short)(v3));\
} while(0)
#else
	#define L1Audio_Msg_AM_SRC1(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1Audio_Msg_AM_SRC2(v1, v2, v3) do {\
		if(L1Audio_Trace_Filter[0]==1 && (L1Audio_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1Audio_Msg_AM_SRC2((unsigned short)(v1), (unsigned short)(v2), (unsigned short)(v3));\
} while(0)
#else
	#define L1Audio_Msg_AM_SRC2(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1Audio_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1Audio_Msg_AFE_Switch(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AFE_TurnSpk(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AFE_TurnMIC(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AFE_SpkSelect(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1Audio_Msg_AM_Switch(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_AM_Handover(char v1);
void L1TRC_Send_L1Audio_Msg_AM_2G_Resync(char v1, char v2);
void L1TRC_Send_L1Audio_Msg_AM_IO_Switch(unsigned char v1);
void L1TRC_Send_L1Audio_Msg_AM_SetSpeech(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_Speech_State(unsigned char v1);
void L1TRC_Send_L1Audio_Msg_DSP_INT(unsigned short v1);
void L1TRC_Send_L1Audio_Msg_AM_DELAY_TABLE(short v1);
void L1TRC_Send_L1Audio_Msg_SPEECH_FRAME(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1Audio_Msg_SPEECH_CODEC(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_VM_DEBUG(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1Audio_Msg_VBI_RESET(void);
void L1TRC_Send_L1Audio_Msg_VBI_END(void);
void L1TRC_Send_L1Audio_Msg_TCH_NOTIFY(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1Audio_Msg_INTERRAT_W2G(void);
void L1TRC_Send_L1Audio_Msg_INTERRAT_G2W(void);
void L1TRC_Send_L1Audio_Msg_SWITCH_FILT(short v1, unsigned short v2);
void L1TRC_Send_L1Audio_Msg_AFE_RegBackup(unsigned char v1);
void L1TRC_Send_L1Audio_Msg_AM_SRC1(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1Audio_Msg_AM_SRC2(unsigned short v1, unsigned short v2, unsigned short v3);

void Set_L1Audio_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1Audio()	(L1Audio_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1Audio_AFE_Inf_H()	(ChkL1ModFltr_L1Audio()&&((L1Audio_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1Audio_AM_Inf_H()	(ChkL1ModFltr_L1Audio()&&((L1Audio_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_L1Audio_Msg_AFE_Switch()	ChkL1ClsFltr_L1Audio_AFE_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AFE_TurnSpk()	ChkL1ClsFltr_L1Audio_AFE_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AFE_TurnMIC()	ChkL1ClsFltr_L1Audio_AFE_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AFE_SpkSelect()	ChkL1ClsFltr_L1Audio_AFE_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_Switch()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_Handover()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_2G_Resync()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_IO_Switch()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_SetSpeech()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_Speech_State()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_DSP_INT()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_DELAY_TABLE()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_SPEECH_FRAME()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_SPEECH_CODEC()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_VM_DEBUG()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_VBI_RESET()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_VBI_END()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_TCH_NOTIFY()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_INTERRAT_W2G()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_INTERRAT_G2W()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_SWITCH_FILT()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AFE_RegBackup()	ChkL1ClsFltr_L1Audio_AFE_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_SRC1()	ChkL1ClsFltr_L1Audio_AM_Inf_H()
#define ChkL1MsgFltr_L1Audio_Msg_AM_SRC2()	ChkL1ClsFltr_L1Audio_AM_Inf_H()


#endif
