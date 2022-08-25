#ifndef L1TRC_L1I_GPRS_DEF_H
#define L1TRC_L1I_GPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1I_GPRS_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1I_PRACH_Str_States(v1)  (unsigned char)(v1+2)
#define L1I_TBF_Str_States(v1)  (unsigned char)(v1+8)
#define L1I_Str_GPRS_UL_CtrlMsg(v1)  (unsigned char)(v1+14)
#define L1I_Str_Check_RRBP(v1)  (unsigned char)(v1+28)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_PowerControlSetC(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_PowerControlSetC((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define L1I_Trace_PowerControlSetC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_ReportTBFStarted(v1, v2, v3, v4, v5) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_ReportTBFStarted((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1I_Trace_ReportTBFStarted(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_TBF_Transition(v1, v2, v3, v4, v5) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_TBF_Transition((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1I_Trace_TBF_Transition(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_ReportTBFStopped(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_ReportTBFStopped((unsigned char)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1I_Trace_ReportTBFStopped(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportPDTChConflict(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_ReportPDTChConflict((unsigned char)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1I_Trace_ReportPDTChConflict(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_ReportPRACh(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1I_Trace_ReportPRACh((unsigned char)(v1), (unsigned char)(v2), (unsigned long)(v3), (short)(v4));\
} while(0)
#else
	#define L1I_Trace_ReportPRACh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportPollResp(v1, v2, v3, v4, v5, v6) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Trace_ReportPollResp((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4), (char)(v5), (char)(v6));\
} while(0)
#else
	#define L1I_Trace_ReportPollResp(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportSingleDL(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_ReportSingleDL((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Trace_ReportSingleDL(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportULTwoPhase(v1, v2, v3, v4, v5) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_ReportULTwoPhase((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4), (char)(v5));\
} while(0)
#else
	#define L1I_Trace_ReportULTwoPhase(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_ReportULWithoutTBF(v1, v2, v3, v4, v5) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_ReportULWithoutTBF((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (char)(v4), (char)(v5));\
} while(0)
#else
	#define L1I_Trace_ReportULWithoutTBF(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MACAssigned(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1I_Trace_MACAssigned((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1I_Trace_MACAssigned(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MACOurUSFMask(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_MACOurUSFMask((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Trace_MACOurUSFMask(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_MACTxSpec(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_MACTxSpec((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1I_Trace_MACTxSpec(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_MACSetReceivedUSF(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1I_Trace_MACSetReceivedUSF((unsigned char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_MACSetReceivedUSF(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_MACPreGetUplinkPDTCh(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_MACPreGetUplinkPDTCh((unsigned char)(v1), (unsigned char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_MACPreGetUplinkPDTCh(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_MACULStatusReport(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_MACULStatusReport((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1I_Trace_MACULStatusReport(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_ExtractPR1() do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_ExtractPR1();\
} while(0)
#else
	#define L1I_Trace_ExtractPR1()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_ExtractPR2() do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1I_Trace_ExtractPR2();\
} while(0)
#else
	#define L1I_Trace_ExtractPR2()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_ExtractPR3(v1, v2, v3, v4) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1I_Trace_ExtractPR3((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (char)(v4));\
} while(0)
#else
	#define L1I_Trace_ExtractPR3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC0(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC0((char)(v1));\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC0(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC1(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC1((char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC2(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC2((char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC3(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC3((char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC3(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC4(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC4((char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC4(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_GPRS_AGC5(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1I_Trace_GPRS_AGC5((char)(v1), (char)(v2));\
} while(0)
#else
	#define L1I_Trace_GPRS_AGC5(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_UL_DATA(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_UL_DATA((char)(v1), (char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1I_Trace_UL_DATA(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_UL_Ctrl(v1, v2) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_UL_Ctrl((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define L1I_Trace_UL_Ctrl(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Trace_PDAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1I_Trace_PDAN((char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9), (unsigned char)(v10), (unsigned char)(v11), (char)(v12));\
} while(0)
#else
	#define L1I_Trace_PDAN(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif

#if defined(L1_CATCHER)
	#define L1I_Trace_PCA_AB(v1) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1I_Trace_PCA_AB((char)(v1));\
} while(0)
#else
	#define L1I_Trace_PCA_AB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_PDTChCheckNoRRBP(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1I_Trace_PDTChCheckNoRRBP((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1I_Trace_PDTChCheckNoRRBP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Trace_UpdateTimingAdvance(v1, v2, v3) do {\
		if(L1I_GPRS_Trace_Filter[0]==1 && (L1I_GPRS_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1I_Trace_UpdateTimingAdvance((unsigned char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1I_Trace_UpdateTimingAdvance(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1I_GPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1I_Trace_PowerControlSetC(unsigned char v1, char v2);
void L1TRC_Send_L1I_Trace_ReportTBFStarted(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1I_Trace_TBF_Transition(unsigned char v1, unsigned char v2, char v3, char v4, unsigned char v5);
void L1TRC_Send_L1I_Trace_ReportTBFStopped(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1I_Trace_ReportPDTChConflict(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1I_Trace_ReportPRACh(unsigned char v1, unsigned char v2, unsigned long v3, short v4);
void L1TRC_Send_L1I_Trace_ReportPollResp(unsigned char v1, unsigned char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_L1I_Trace_ReportSingleDL(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_ReportULTwoPhase(unsigned char v1, unsigned char v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Trace_ReportULWithoutTBF(unsigned char v1, unsigned char v2, char v3, char v4, char v5);
void L1TRC_Send_L1I_Trace_MACAssigned(unsigned char v1, char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1I_Trace_MACOurUSFMask(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Trace_MACTxSpec(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_MACSetReceivedUSF(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_MACPreGetUplinkPDTCh(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1I_Trace_MACULStatusReport(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_ExtractPR1(void);
void L1TRC_Send_L1I_Trace_ExtractPR2(void);
void L1TRC_Send_L1I_Trace_ExtractPR3(unsigned char v1, char v2, unsigned char v3, char v4);
void L1TRC_Send_L1I_Trace_GPRS_AGC0(char v1);
void L1TRC_Send_L1I_Trace_GPRS_AGC1(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC2(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC3(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC4(char v1, char v2, char v3);
void L1TRC_Send_L1I_Trace_GPRS_AGC5(char v1, char v2);
void L1TRC_Send_L1I_Trace_UL_DATA(char v1, char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_UL_Ctrl(unsigned char v1, char v2);
void L1TRC_Send_L1I_Trace_PDAN(char v1, char v2, char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9, unsigned char v10, unsigned char v11, char v12);
void L1TRC_Send_L1I_Trace_PCA_AB(char v1);
void L1TRC_Send_L1I_Trace_PDTChCheckNoRRBP(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Trace_UpdateTimingAdvance(unsigned char v1, char v2, char v3);

void Set_L1I_GPRS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1I_GPRS()	(L1I_GPRS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1I_GPRS_C_Value_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GPRS_UL_Block_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportTBF_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportTBF_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportPDTChConflict_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportPRACh_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportPollResp_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportSingleDL_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportULTwoPhase_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GPRS_ReportSingleULWithoutTBF_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GPRS_L1D_Constellation_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GPRS_mpal_uplink_transfer_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GPRS_mpal_ul_status_report_H()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GPRS_mpal_next_rrbp_frame_no_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1I_GPRS_L1I_UpdateTimingAdvance_M()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1I_GPRS_L1I_MACFrameTick_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1I_GPRS_SetReceivedUSF_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1I_GPRS_OurUSFMask_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1I_GPRS_PR_Payload_Type_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1I_GPRS_PR_TFI_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1I_GPRS_UL_Ctrl_Block_L()	(ChkL1ModFltr_L1I_GPRS()&&((L1I_GPRS_Trace_Filter[3]&0x20)!=0))
#define ChkL1MsgFltr_L1I_Trace_PowerControlSetC()	ChkL1ClsFltr_L1I_GPRS_C_Value_M()
#define ChkL1MsgFltr_L1I_Trace_ReportTBFStarted()	ChkL1ClsFltr_L1I_GPRS_ReportTBF_M()
#define ChkL1MsgFltr_L1I_Trace_TBF_Transition()	ChkL1ClsFltr_L1I_GPRS_ReportTBF_M()
#define ChkL1MsgFltr_L1I_Trace_ReportTBFStopped()	ChkL1ClsFltr_L1I_GPRS_ReportTBF_M()
#define ChkL1MsgFltr_L1I_Trace_ReportPDTChConflict()	ChkL1ClsFltr_L1I_GPRS_ReportPDTChConflict_H()
#define ChkL1MsgFltr_L1I_Trace_ReportPRACh()	ChkL1ClsFltr_L1I_GPRS_ReportPRACh_M()
#define ChkL1MsgFltr_L1I_Trace_ReportPollResp()	ChkL1ClsFltr_L1I_GPRS_ReportPollResp_H()
#define ChkL1MsgFltr_L1I_Trace_ReportSingleDL()	ChkL1ClsFltr_L1I_GPRS_ReportSingleDL_H()
#define ChkL1MsgFltr_L1I_Trace_ReportULTwoPhase()	ChkL1ClsFltr_L1I_GPRS_ReportULTwoPhase_H()
#define ChkL1MsgFltr_L1I_Trace_ReportULWithoutTBF()	ChkL1ClsFltr_L1I_GPRS_ReportSingleULWithoutTBF_H()
#define ChkL1MsgFltr_L1I_Trace_MACAssigned()	ChkL1ClsFltr_L1I_GPRS_L1I_MACFrameTick_L()
#define ChkL1MsgFltr_L1I_Trace_MACOurUSFMask()	ChkL1ClsFltr_L1I_GPRS_OurUSFMask_L()
#define ChkL1MsgFltr_L1I_Trace_MACTxSpec()	ChkL1ClsFltr_L1I_GPRS_L1D_Constellation_H()
#define ChkL1MsgFltr_L1I_Trace_MACSetReceivedUSF()	ChkL1ClsFltr_L1I_GPRS_SetReceivedUSF_L()
#define ChkL1MsgFltr_L1I_Trace_MACPreGetUplinkPDTCh()	ChkL1ClsFltr_L1I_GPRS_mpal_uplink_transfer_H()
#define ChkL1MsgFltr_L1I_Trace_MACULStatusReport()	ChkL1ClsFltr_L1I_GPRS_mpal_ul_status_report_H()
#define ChkL1MsgFltr_L1I_Trace_ExtractPR1()	ChkL1ClsFltr_L1I_GPRS_PR_Payload_Type_L()
#define ChkL1MsgFltr_L1I_Trace_ExtractPR2()	ChkL1ClsFltr_L1I_GPRS_PR_Payload_Type_L()
#define ChkL1MsgFltr_L1I_Trace_ExtractPR3()	ChkL1ClsFltr_L1I_GPRS_PR_TFI_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC0()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC1()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC2()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC3()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC4()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_GPRS_AGC5()	ChkL1ClsFltr_L1I_GPRS_Block_AGC_L()
#define ChkL1MsgFltr_L1I_Trace_UL_DATA()	ChkL1ClsFltr_L1I_GPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_UL_Ctrl()	ChkL1ClsFltr_L1I_GPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_PDAN()	ChkL1ClsFltr_L1I_GPRS_UL_Ctrl_Block_L()
#define ChkL1MsgFltr_L1I_Trace_PCA_AB()	ChkL1ClsFltr_L1I_GPRS_UL_Block_H()
#define ChkL1MsgFltr_L1I_Trace_PDTChCheckNoRRBP()	ChkL1ClsFltr_L1I_GPRS_mpal_next_rrbp_frame_no_M()
#define ChkL1MsgFltr_L1I_Trace_UpdateTimingAdvance()	ChkL1ClsFltr_L1I_GPRS_L1I_UpdateTimingAdvance_M()


#endif
