#ifndef L1TRC_DCXO_DIV_1_DEF_H
#define L1TRC_DCXO_DIV_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define DCXO_MODE_Str(v1)  (unsigned char)(v1+0)
#define DCXO_UPDATE_R32K_Str(v1)  (unsigned char)(v1+2)
#define DCXO_Str_Bool(v1)  (unsigned char)(v1+7)
#define DCXO_ENTER_26M_FPM_Str(v1)  (unsigned char)(v1+9)
#define DCXO_Str_Lpm_Changed(v1)  (unsigned char)(v1+12)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER)
	#define DCXO_DIV_DBG_UPDATE_R32K(v1, v2, v3, v4, v5) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_DCXO_DIV_DBG_UPDATE_R32K((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define DCXO_DIV_DBG_UPDATE_R32K(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define DCXO_DIV_DBG_26M_FERR(v1, v2, v3) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_DCXO_DIV_DBG_26M_FERR((unsigned char)(v1), (long)(v2), (short)(v3));\
} while(0)
#else
	#define DCXO_DIV_DBG_26M_FERR(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define DCXO_DIV_LPM_CNT_UPDATE(v1, v2, v3) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_DCXO_DIV_LPM_CNT_UPDATE((unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
} while(0)
#else
	#define DCXO_DIV_LPM_CNT_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define DCXO_DIV_LPM_CNT_END(v1, v2) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_DCXO_DIV_LPM_CNT_END((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define DCXO_DIV_LPM_CNT_END(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define DCXO_DIV_LPM_CNT_LATCH(v1) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_DCXO_DIV_LPM_CNT_LATCH((unsigned long)(v1));\
} while(0)
#else
	#define DCXO_DIV_LPM_CNT_LATCH(v1)
#endif

#if defined(L1_CATCHER)
	#define DCXO_DIV_DBG_UPDATE(v1, v2, v3) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_DCXO_DIV_DBG_UPDATE((unsigned short)(v1), (long)(v2), (short)(v3));\
} while(0)
#else
	#define DCXO_DIV_DBG_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define DCXO_DIV_DBG_UPDATE_UNLOCK(v1, v2, v3, v4) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_DCXO_DIV_DBG_UPDATE_UNLOCK((unsigned char)(v1), (unsigned short)(v2), (long)(v3), (short)(v4));\
} while(0)
#else
	#define DCXO_DIV_DBG_UPDATE_UNLOCK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define DCXO_DIV_PCM_CNT(v1, v2) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_DCXO_DIV_PCM_CNT((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define DCXO_DIV_PCM_CNT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define DCXO_DIV_DBG_ENTER_26MHz_FPM(v1, v2, v3) do {\
		if(DCXO_DIV_1_Trace_Filter[0]==1 && (DCXO_DIV_1_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_DCXO_DIV_DBG_ENTER_26MHz_FPM((unsigned char)(v1), (unsigned char)(v2), (short)(v3));\
} while(0)
#else
	#define DCXO_DIV_DBG_ENTER_26MHz_FPM(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char DCXO_DIV_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_DCXO_DIV_DBG_UPDATE_R32K(unsigned char v1, unsigned char v2, unsigned char v3, short v4, short v5);
void L1TRC_Send_DCXO_DIV_DBG_26M_FERR(unsigned char v1, long v2, short v3);
void L1TRC_Send_DCXO_DIV_LPM_CNT_UPDATE(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_DCXO_DIV_LPM_CNT_END(unsigned long v1, unsigned long v2);
void L1TRC_Send_DCXO_DIV_LPM_CNT_LATCH(unsigned long v1);
void L1TRC_Send_DCXO_DIV_DBG_UPDATE(unsigned short v1, long v2, short v3);
void L1TRC_Send_DCXO_DIV_DBG_UPDATE_UNLOCK(unsigned char v1, unsigned short v2, long v3, short v4);
void L1TRC_Send_DCXO_DIV_PCM_CNT(unsigned long v1, unsigned long v2);
void L1TRC_Send_DCXO_DIV_DBG_ENTER_26MHz_FPM(unsigned char v1, unsigned char v2, short v3);

void Set_DCXO_DIV_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_DCXO_DIV_1()	(DCXO_DIV_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()	(ChkL1ModFltr_DCXO_DIV_1()&&((DCXO_DIV_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_M()	(ChkL1ModFltr_DCXO_DIV_1()&&((DCXO_DIV_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_DCXO_DIV_DBG_UPDATE_R32K()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_DBG_26M_FERR()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_LPM_CNT_UPDATE()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_LPM_CNT_END()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_LPM_CNT_LATCH()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_DBG_UPDATE()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_DBG_UPDATE_UNLOCK()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_PCM_CNT()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_H()
#define ChkL1MsgFltr_DCXO_DIV_DBG_ENTER_26MHz_FPM()	ChkL1ClsFltr_DCXO_DIV_1_DCXO_DIV_32K_M()


#endif
