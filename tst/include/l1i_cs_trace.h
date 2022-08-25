#ifndef L1TRC_L1I_GSM_DEF_H
#define L1TRC_L1I_GSM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_Str_Timer(v1)  (unsigned char)(v1+0)
#define L1I_Str_Burst(v1)  (unsigned char)(v1+76)
#define L1I_Str_Bool(v1)  (unsigned char)(v1+78)
#define L1I_Str_RATSCCH_STATE(v1)  (unsigned char)(v1+80)
#define L1I_Str_NoExecute(v1)  (unsigned char)(v1+97)
#define L1I_Str_Cell(v1)  (unsigned char)(v1+99)
#define L1I_Str_Protect(v1)  (unsigned char)(v1+101)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER)
	#define L1I_Msg_AGC(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_AGC((unsigned char)(v1), (short)(v2), (char)(v3), (char)(v4), (char)(v5));\
} while(0)
#else
	#define L1I_Msg_AGC(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_C_AGCNB(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_C_AGCNB((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (char)(v4), (char)(v5), (char)(v6));\
} while(0)
#else
	#define L1I_Msg_C_AGCNB(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_PDTCH_TS0_AGC(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_PDTCH_TS0_AGC((unsigned char)(v1), (short)(v2), (char)(v3), (char)(v4), (char)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1I_Msg_PDTCH_TS0_AGC(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_PDTCH_TS123_AGC(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_PDTCH_TS123_AGC((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1I_Msg_PDTCH_TS123_AGC(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_IM_TS0_AGC(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_IM_TS0_AGC((unsigned char)(v1), (short)(v2), (char)(v3), (char)(v4), (char)(v5));\
} while(0)
#else
	#define L1I_Msg_IM_TS0_AGC(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_IM_TS123_AGC(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_IM_TS123_AGC((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1I_Msg_IM_TS123_AGC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_AGC_PM(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_AGC_PM((short)(v1), (char)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1I_Msg_AGC_PM(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_AFC(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_AFC((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1I_Msg_AFC(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_C_AFCNB(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_C_AFCNB((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define L1I_Msg_C_AFCNB(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_TAC(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_TAC((unsigned char)(v1), (short)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Msg_TAC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Msg_TAC_Accumulate(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1I_Msg_TAC_Accumulate((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1I_Msg_TAC_Accumulate(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_TAC_Adjust(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_TAC_Adjust((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1I_Msg_TAC_Adjust(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_Timer(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_Timer((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned short)(v5));\
} while(0)
#else
	#define L1I_Msg_Timer(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_ReportRACh(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1I_Msg_ReportRACh((unsigned char)(v1), (unsigned long)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Msg_ReportRACh(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_UL_FACCH(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_UL_FACCH((unsigned char)(v1));\
} while(0)
#else
	#define L1I_Msg_UL_FACCH(v1)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_ReportTCh(v1, v2, v3, v4) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_ReportTCh((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1I_Msg_ReportTCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_SetSync(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_SetSync((unsigned char)(v1), (unsigned long)(v2), (short)(v3));\
} while(0)
#else
	#define L1I_Msg_SetSync(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_TaskSetSync(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_TaskSetSync((unsigned char)(v1), (unsigned long)(v2), (short)(v3));\
} while(0)
#else
	#define L1I_Msg_TaskSetSync(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_TxPower(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Msg_TxPower((unsigned char)(v1), (short)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1I_Msg_TxPower(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Msg_ULDTX(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_ULDTX((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Msg_ULDTX(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_RATSCChState(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_RATSCChState((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Msg_RATSCChState(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_SetupTA(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1I_Msg_SetupTA((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Msg_SetupTA(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_FCBT_CNT(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1I_Msg_FCBT_CNT((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Msg_FCBT_CNT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MonitorReportEnh1(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh1((unsigned char)(v1), (unsigned long)(v2), (char)(v3), (char)(v4), (char)(v5), (char)(v6), (char)(v7), (char)(v8));\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh1(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MonitorReportEnh2(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh2((unsigned char)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MonitorReportEnh3(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh3((unsigned char)(v1), (long)(v2), (short)(v3), (long)(v4), (short)(v5));\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh3(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MonitorReportEnh4(v1, v2, v3) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MonitorReportEnh4((unsigned char)(v1), (long)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_MonitorReportEnh4(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Msg_RepeatSACCh(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1I_Msg_RepeatSACCh((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1I_Msg_RepeatSACCh(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_SIM_STATUS(v1, v2) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_SIM_STATUS((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Msg_SIM_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_SIMTiming(v1, v2, v3, v4, v5) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_SIMTiming((unsigned char)(v1), (unsigned char)(v2), (unsigned long)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define L1C_Msg_SIMTiming(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_TimerNoExecute(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_TimerNoExecute((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (unsigned char)(v4), (char)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1I_Msg_TimerNoExecute(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_TimerAbortNoExecute(v1) do {\
		if(L1I_GSM_Trace_Filter[0]==1 && (L1I_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_TimerAbortNoExecute((unsigned char)(v1));\
} while(0)
#else
	#define L1I_Msg_TimerAbortNoExecute(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1I_GSM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Msg_AGC(unsigned char v1, short v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Msg_C_AGCNB(unsigned char v1, unsigned char v2, short v3, char v4, char v5, char v6);
void L1TRC_Send_L1I_Msg_PDTCH_TS0_AGC(unsigned char v1, short v2, char v3, char v4, char v5, unsigned char v6);
void L1TRC_Send_L1I_Msg_PDTCH_TS123_AGC(unsigned char v1, char v2, char v3, char v4, unsigned char v5);
void L1TRC_Send_L1I_Msg_IM_TS0_AGC(unsigned char v1, short v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Msg_IM_TS123_AGC(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_AGC_PM(short v1, char v2, char v3, char v4);
void L1TRC_Send_L1I_Msg_AFC(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1I_Msg_C_AFCNB(unsigned char v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_L1I_Msg_TAC(unsigned char v1, short v2, char v3);
void L1TRC_Send_L1I_Msg_TAC_Accumulate(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1I_Msg_TAC_Adjust(unsigned char v1, short v2);
void L1TRC_Send_L1I_Msg_Timer(unsigned char v1, char v2, unsigned char v3, unsigned char v4, unsigned short v5);
void L1TRC_Send_L1I_Msg_ReportRACh(unsigned char v1, unsigned long v2, char v3);
void L1TRC_Send_L1I_Msg_UL_FACCH(unsigned char v1);
void L1TRC_Send_L1I_Msg_ReportTCh(unsigned char v1, unsigned char v2, short v3, unsigned char v4);
void L1TRC_Send_L1I_Msg_SetSync(unsigned char v1, unsigned long v2, short v3);
void L1TRC_Send_L1I_Msg_TaskSetSync(unsigned char v1, unsigned long v2, short v3);
void L1TRC_Send_L1I_Msg_TxPower(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_L1I_Msg_ULDTX(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_RATSCChState(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_SetupTA(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_FCBT_CNT(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_MonitorReportEnh1(unsigned char v1, unsigned long v2, char v3, char v4, char v5, char v6, char v7, char v8);
void L1TRC_Send_L1I_Trace_MonitorReportEnh2(unsigned char v1, long v2, long v3);
void L1TRC_Send_L1I_Trace_MonitorReportEnh3(unsigned char v1, long v2, short v3, long v4, short v5);
void L1TRC_Send_L1I_Trace_MonitorReportEnh4(unsigned char v1, long v2, char v3);
void L1TRC_Send_L1I_Msg_RepeatSACCh(unsigned char v1, unsigned char v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1I_Msg_SIM_STATUS(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_SIMTiming(unsigned char v1, unsigned char v2, unsigned long v3, short v4, short v5);
void L1TRC_Send_L1I_Msg_TimerNoExecute(unsigned char v1, unsigned char v2, char v3, unsigned char v4, char v5, unsigned char v6);
void L1TRC_Send_L1I_Msg_TimerAbortNoExecute(unsigned char v1);

void Set_L1I_GSM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1I_GSM()	(L1I_GSM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1I_GSM_Timer_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GSM_AGC_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GSM_AGCPDTCh_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GSM_AFC_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GSM_TAC_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GSM_ReportRACh_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1I_GSM_SetSync_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1I_GSM_TxPower_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1I_GSM_UL_FACCH_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GSM_ReportTCh_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GSM_AGCIM_M()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GSM_AMR_M()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GSM_SetupTA_M()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GSM_SetupFCBT_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1I_GSM_SIM_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1I_GSM_TAC_Debug_L()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1I_GSM_AGCPM_H()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GSM_UL_DTX_L()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GSM_R99_L()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GSM_RepeatSACCh_L()	(ChkL1ModFltr_L1I_GSM()&&((L1I_GSM_Trace_Filter[3]&0x08)!=0))
#define ChkL1MsgFltr_L1I_Msg_AGC()	ChkL1ClsFltr_L1I_GSM_AGC_H()
#define ChkL1MsgFltr_L1I_Msg_C_AGCNB()	ChkL1ClsFltr_L1I_GSM_AGC_H()
#define ChkL1MsgFltr_L1I_Msg_PDTCH_TS0_AGC()	ChkL1ClsFltr_L1I_GSM_AGCPDTCh_H()
#define ChkL1MsgFltr_L1I_Msg_PDTCH_TS123_AGC()	ChkL1ClsFltr_L1I_GSM_AGCPDTCh_H()
#define ChkL1MsgFltr_L1I_Msg_IM_TS0_AGC()	ChkL1ClsFltr_L1I_GSM_AGCIM_M()
#define ChkL1MsgFltr_L1I_Msg_IM_TS123_AGC()	ChkL1ClsFltr_L1I_GSM_AGCIM_M()
#define ChkL1MsgFltr_L1I_Msg_AGC_PM()	ChkL1ClsFltr_L1I_GSM_AGCPM_H()
#define ChkL1MsgFltr_L1I_Msg_AFC()	ChkL1ClsFltr_L1I_GSM_AFC_H()
#define ChkL1MsgFltr_L1I_Msg_C_AFCNB()	ChkL1ClsFltr_L1I_GSM_AFC_H()
#define ChkL1MsgFltr_L1I_Msg_TAC()	ChkL1ClsFltr_L1I_GSM_TAC_H()
#define ChkL1MsgFltr_L1I_Msg_TAC_Accumulate()	ChkL1ClsFltr_L1I_GSM_TAC_Debug_L()
#define ChkL1MsgFltr_L1I_Msg_TAC_Adjust()	ChkL1ClsFltr_L1I_GSM_TAC_H()
#define ChkL1MsgFltr_L1I_Msg_Timer()	ChkL1ClsFltr_L1I_GSM_Timer_H()
#define ChkL1MsgFltr_L1I_Msg_ReportRACh()	ChkL1ClsFltr_L1I_GSM_ReportRACh_H()
#define ChkL1MsgFltr_L1I_Msg_UL_FACCH()	ChkL1ClsFltr_L1I_GSM_UL_FACCH_H()
#define ChkL1MsgFltr_L1I_Msg_ReportTCh()	ChkL1ClsFltr_L1I_GSM_ReportTCh_H()
#define ChkL1MsgFltr_L1I_Msg_SetSync()	ChkL1ClsFltr_L1I_GSM_SetSync_H()
#define ChkL1MsgFltr_L1I_Msg_TaskSetSync()	ChkL1ClsFltr_L1I_GSM_SetSync_H()
#define ChkL1MsgFltr_L1I_Msg_TxPower()	ChkL1ClsFltr_L1I_GSM_TxPower_H()
#define ChkL1MsgFltr_L1I_Msg_ULDTX()	ChkL1ClsFltr_L1I_GSM_UL_DTX_L()
#define ChkL1MsgFltr_L1I_Msg_RATSCChState()	ChkL1ClsFltr_L1I_GSM_AMR_M()
#define ChkL1MsgFltr_L1I_Msg_SetupTA()	ChkL1ClsFltr_L1I_GSM_SetupTA_M()
#define ChkL1MsgFltr_L1I_Msg_FCBT_CNT()	ChkL1ClsFltr_L1I_GSM_SetupFCBT_H()
#define ChkL1MsgFltr_L1I_Trace_MonitorReportEnh1()	ChkL1ClsFltr_L1I_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Trace_MonitorReportEnh2()	ChkL1ClsFltr_L1I_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Trace_MonitorReportEnh3()	ChkL1ClsFltr_L1I_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Trace_MonitorReportEnh4()	ChkL1ClsFltr_L1I_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Msg_RepeatSACCh()	ChkL1ClsFltr_L1I_GSM_RepeatSACCh_L()
#define ChkL1MsgFltr_L1I_Msg_SIM_STATUS()	ChkL1ClsFltr_L1I_GSM_SIM_H()
#define ChkL1MsgFltr_L1C_Msg_SIMTiming()	ChkL1ClsFltr_L1I_GSM_SIM_H()
#define ChkL1MsgFltr_L1I_Msg_TimerNoExecute()	ChkL1ClsFltr_L1I_GSM_Timer_H()
#define ChkL1MsgFltr_L1I_Msg_TimerAbortNoExecute()	ChkL1ClsFltr_L1I_GSM_Timer_H()


#endif
