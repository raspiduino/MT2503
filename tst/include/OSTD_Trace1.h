#ifndef L1TRC_OSTD_1_DEF_H
#define L1TRC_OSTD_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define OSTD_TIMER_TYPE_Str(v1)  (unsigned char)(v1+0)
#define OSTD_Str_Bool(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define OSTD_TRC_DEBUG1(v1, v2, v3) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_OSTD_TRC_DEBUG1((unsigned short)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define OSTD_TRC_DEBUG1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define OSTD_TRC_DEBUG2(v1, v2, v3) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_OSTD_TRC_DEBUG2((unsigned short)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define OSTD_TRC_DEBUG2(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define OSTD_SM_STATUS(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_OSTD_SM_STATUS((unsigned short)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
} while(0)
#else
	#define OSTD_SM_STATUS(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#if defined(L1_CATCHER)
	#define OSTD_TRC_INF_SLEEP_TRG() do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_OSTD_TRC_INF_SLEEP_TRG();\
} while(0)
#else
	#define OSTD_TRC_INF_SLEEP_TRG()
#endif

#if defined(L1_CATCHER)
	#define OSTD_TRC_INF_SLEEP_TIMER_CB(v1, v2) do {\
		if(OSTD_1_Trace_Filter[0]==1 && (OSTD_1_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_OSTD_TRC_INF_SLEEP_TIMER_CB((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define OSTD_TRC_INF_SLEEP_TIMER_CB(v1, v2)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char OSTD_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_OSTD_TRC_DEBUG1(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_TRC_DEBUG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_OSTD_SM_STATUS(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_OSTD_TRC_INF_SLEEP_TRG(void);
void L1TRC_Send_OSTD_TRC_INF_SLEEP_TIMER_CB(unsigned char v1, unsigned char v2);

void Set_OSTD_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_OSTD_1()	(OSTD_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_OSTD_1_OSTD_SM_H()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_OSTD_1_OSTD_IS_H()	(ChkL1ModFltr_OSTD_1()&&((OSTD_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_OSTD_TRC_DEBUG1()	ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()
#define ChkL1MsgFltr_OSTD_TRC_DEBUG2()	ChkL1ClsFltr_OSTD_1_OSTD_DBG_L()
#define ChkL1MsgFltr_OSTD_SM_STATUS()	ChkL1ClsFltr_OSTD_1_OSTD_SM_H()
#define ChkL1MsgFltr_OSTD_TRC_INF_SLEEP_TRG()	ChkL1ClsFltr_OSTD_1_OSTD_IS_H()
#define ChkL1MsgFltr_OSTD_TRC_INF_SLEEP_TIMER_CB()	ChkL1ClsFltr_OSTD_1_OSTD_IS_H()


#endif
