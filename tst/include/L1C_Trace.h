#ifndef L1TRC_L1C_GSM_DEF_H
#define L1TRC_L1C_GSM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1C_Str_Function(v1)  (unsigned char)(v1+2)
#define L1C_Str_ConflictReport(v1)  (unsigned char)(v1+5)
#define L1C_Str_ConflictTimer(v1)  (unsigned char)(v1+13)
#define L1I_Str_SIM(v1)  (unsigned char)(v1+28)
#define L1I_Str_Set_Sim_Mode(v1)  (unsigned char)(v1+32)
#define L1I_Str_ServingSB(v1)  (unsigned char)(v1+42)
#define L1I_Str_ServingSB_state(v1)  (unsigned char)(v1+44)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER)
	#define L1C_Msg_ReportFCCh(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_ReportFCCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (char)(v5), (unsigned long)(v6), (short)(v7), (unsigned long)(v8), (unsigned long)(v9), (short)(v10));\
} while(0)
#else
	#define L1C_Msg_ReportFCCh(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportSCh(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (char)(v4), (unsigned long)(v5), (short)(v6), (unsigned long)(v7), (short)(v8));\
} while(0)
#else
	#define L1C_Msg_ReportSCh(v1, v2, v3, v4, v5, v6, v7, v8)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportBCCh(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_ReportBCCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (char)(v5));\
} while(0)
#else
	#define L1C_Msg_ReportBCCh(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportNBCCh(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_ReportNBCCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (char)(v5));\
} while(0)
#else
	#define L1C_Msg_ReportNBCCh(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportPCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_ReportPCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1C_Msg_ReportPCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportPeek(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_ReportPeek((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Msg_ReportPeek(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_ReportCBCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_ReportCBCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Msg_ReportCBCh(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportAGCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_ReportAGCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Msg_ReportAGCh(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportSDCCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSDCCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Msg_ReportSDCCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ReportSACCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_ReportSACCh((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Msg_ReportSACCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_DL_FACCH(v1) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_DL_FACCH((unsigned char)(v1));\
} while(0)
#else
	#define L1C_Msg_DL_FACCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_HoppingSeq(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_HoppingSeq((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define L1C_Msg_HoppingSeq(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trc_SDCCH_DL_DATA(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1T_Trc_SDCCH_DL_DATA((unsigned char)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1T_Trc_SDCCH_DL_DATA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trc_SACCH_DL_DATA(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1T_Trc_SACCH_DL_DATA((unsigned char)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1T_Trc_SACCH_DL_DATA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trc_FACCH_DL_DATA(v1, v2) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1T_Trc_FACCH_DL_DATA((unsigned char)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1T_Trc_FACCH_DL_DATA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartBCCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1C_Msg_StartBCCh((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1C_Msg_StartBCCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupPCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_SetupPCh((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (long)(v4));\
} while(0)
#else
	#define L1C_Msg_SetupPCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartAGCh(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_StartAGCh((unsigned char)(v1), (unsigned char)(v2), (char)(v3));\
} while(0)
#else
	#define L1C_Msg_StartAGCh(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupCBCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_SetupCBCh((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define L1C_Msg_SetupCBCh(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetupCiphering(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_SetupCiphering((unsigned char)(v1), (unsigned char)(v2), (char)(v3));\
} while(0)
#else
	#define L1C_Msg_SetupCiphering(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartFCChT(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_StartFCChT((unsigned char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1C_Msg_StartFCChT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_StartSChT(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_StartSChT((unsigned char)(v1), (unsigned long)(v2), (short)(v3), (char)(v4), (char)(v5));\
} while(0)
#else
	#define L1C_Msg_StartSChT(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_FunctionCalled(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_FunctionCalled((unsigned char)(v1), (unsigned char)(v2), (long)(v3), (long)(v4));\
} while(0)
#else
	#define L1C_Msg_FunctionCalled(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_R99_Bep(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x80)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Bep((unsigned char)(v1), (char)(v2), (char)(v3), (long)(v4), (short)(v5));\
} while(0)
#else
	#define L1C_Trace_R99_Bep(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_R99_Bep_bNormalize(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x80)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Bep_bNormalize((unsigned char)(v1), (long)(v2), (short)(v3), (long)(v4), (short)(v5));\
} while(0)
#else
	#define L1C_Trace_R99_Bep_bNormalize(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_R99_Power_bNormalize(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x80)!=0 )\
			L1TRC_Send_L1C_Trace_R99_Power_bNormalize((unsigned char)(v1), (long)(v2), (long)(v3), (char)(v4));\
} while(0)
#else
	#define L1C_Trace_R99_Power_bNormalize(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_ConflictReportType(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_ConflictReportType((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1I_Msg_ConflictReportType(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_SimModeChange(v1, v2, v3) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1I_Msg_SimModeChange((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1I_Msg_SimModeChange(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_TRC_REDUMP() do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[4]&0x01)!=0 )\
			L1TRC_Send_L1T_TRC_REDUMP();\
} while(0)
#else
	#define L1T_TRC_REDUMP()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1I_Msg_ServingSB(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[4]&0x02)!=0 )\
			L1TRC_Send_L1I_Msg_ServingSB((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1I_Msg_ServingSB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1C_Msg_ServingSCh(v1, v2, v3, v4) do {\
		if(L1C_GSM_Trace_Filter[0]==1 && (L1C_GSM_Trace_Filter[4]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_ServingSCh((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1C_Msg_ServingSCh(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_GSM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Msg_ReportFCCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5, unsigned long v6, short v7, unsigned long v8, unsigned long v9, short v10);
void L1TRC_Send_L1C_Msg_ReportSCh(unsigned char v1, unsigned char v2, unsigned char v3, char v4, unsigned long v5, short v6, unsigned long v7, short v8);
void L1TRC_Send_L1C_Msg_ReportBCCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_L1C_Msg_ReportNBCCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_L1C_Msg_ReportPCh(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_ReportPeek(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Msg_ReportCBCh(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Msg_ReportAGCh(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Msg_ReportSDCCh(unsigned char v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_L1C_Msg_ReportSACCh(unsigned char v1, unsigned char v2, unsigned char v3, short v4);
void L1TRC_Send_L1C_Msg_DL_FACCH(unsigned char v1);
void L1TRC_Send_L1C_Msg_HoppingSeq(unsigned char v1, char v2);
void L1TRC_Send_L1T_Trc_SDCCH_DL_DATA(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1T_Trc_SACCH_DL_DATA(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1T_Trc_FACCH_DL_DATA(unsigned char v1, unsigned long v2);
void L1TRC_Send_L1C_Msg_StartBCCh(unsigned char v1, unsigned char v2, char v3, unsigned long v4);
void L1TRC_Send_L1C_Msg_SetupPCh(unsigned char v1, unsigned char v2, char v3, long v4);
void L1TRC_Send_L1C_Msg_StartAGCh(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Msg_SetupCBCh(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_L1C_Msg_SetupCiphering(unsigned char v1, unsigned char v2, char v3);
void L1TRC_Send_L1C_Msg_StartFCChT(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1C_Msg_StartSChT(unsigned char v1, unsigned long v2, short v3, char v4, char v5);
void L1TRC_Send_L1C_Msg_FunctionCalled(unsigned char v1, unsigned char v2, long v3, long v4);
void L1TRC_Send_L1C_Trace_R99_Bep(unsigned char v1, char v2, char v3, long v4, short v5);
void L1TRC_Send_L1C_Trace_R99_Bep_bNormalize(unsigned char v1, long v2, short v3, long v4, short v5);
void L1TRC_Send_L1C_Trace_R99_Power_bNormalize(unsigned char v1, long v2, long v3, char v4);
void L1TRC_Send_L1I_Msg_ConflictReportType(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1I_Msg_SimModeChange(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1T_TRC_REDUMP(void);
void L1TRC_Send_L1I_Msg_ServingSB(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_ServingSCh(unsigned char v1, unsigned char v2, short v3, unsigned char v4);

void Set_L1C_GSM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_GSM()	(L1C_GSM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_GSM_ReportFCCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportSCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportBCCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportNBCCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportPCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportAGCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportSDCCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportSACCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GSM_DL_FACCH_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM_StartBCCh_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM_SetupPCh_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GSM_StartAGCh_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GSM_SetupCBCh_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GSM_SetupCiphering_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GSM_StartFCChT_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GSM_StartSChT_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GSM_SimMode_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM_ReportCBCh_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM_HoppingSeq_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1T_SDCCH_DL_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1T_SACCH_DL_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1T_FACCH_DL_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1T_Supplement_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GSM_R99_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[3]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GSM_L1C_ERROR_L()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[4]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM_ServingSB_M()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[4]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM_ServingSCh_H()	(ChkL1ModFltr_L1C_GSM()&&((L1C_GSM_Trace_Filter[4]&0x04)!=0))
#define ChkL1MsgFltr_L1C_Msg_ReportFCCh()	ChkL1ClsFltr_L1C_GSM_ReportFCCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportSCh()	ChkL1ClsFltr_L1C_GSM_ReportSCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportBCCh()	ChkL1ClsFltr_L1C_GSM_ReportBCCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportNBCCh()	ChkL1ClsFltr_L1C_GSM_ReportNBCCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportPCh()	ChkL1ClsFltr_L1C_GSM_ReportPCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportPeek()	ChkL1ClsFltr_L1C_GSM_ReportPCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportCBCh()	ChkL1ClsFltr_L1C_GSM_ReportCBCh_L()
#define ChkL1MsgFltr_L1C_Msg_ReportAGCh()	ChkL1ClsFltr_L1C_GSM_ReportAGCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportSDCCh()	ChkL1ClsFltr_L1C_GSM_ReportSDCCh_H()
#define ChkL1MsgFltr_L1C_Msg_ReportSACCh()	ChkL1ClsFltr_L1C_GSM_ReportSACCh_H()
#define ChkL1MsgFltr_L1C_Msg_DL_FACCH()	ChkL1ClsFltr_L1C_GSM_DL_FACCH_H()
#define ChkL1MsgFltr_L1C_Msg_HoppingSeq()	ChkL1ClsFltr_L1C_GSM_HoppingSeq_L()
#define ChkL1MsgFltr_L1T_Trc_SDCCH_DL_DATA()	ChkL1ClsFltr_L1C_GSM_L1T_SDCCH_DL_L()
#define ChkL1MsgFltr_L1T_Trc_SACCH_DL_DATA()	ChkL1ClsFltr_L1C_GSM_L1T_SACCH_DL_L()
#define ChkL1MsgFltr_L1T_Trc_FACCH_DL_DATA()	ChkL1ClsFltr_L1C_GSM_L1T_FACCH_DL_L()
#define ChkL1MsgFltr_L1C_Msg_StartBCCh()	ChkL1ClsFltr_L1C_GSM_StartBCCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupPCh()	ChkL1ClsFltr_L1C_GSM_SetupPCh_M()
#define ChkL1MsgFltr_L1C_Msg_StartAGCh()	ChkL1ClsFltr_L1C_GSM_StartAGCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupCBCh()	ChkL1ClsFltr_L1C_GSM_SetupCBCh_M()
#define ChkL1MsgFltr_L1C_Msg_SetupCiphering()	ChkL1ClsFltr_L1C_GSM_SetupCiphering_M()
#define ChkL1MsgFltr_L1C_Msg_StartFCChT()	ChkL1ClsFltr_L1C_GSM_StartFCChT_M()
#define ChkL1MsgFltr_L1C_Msg_StartSChT()	ChkL1ClsFltr_L1C_GSM_StartSChT_M()
#define ChkL1MsgFltr_L1C_Msg_FunctionCalled()	ChkL1ClsFltr_L1C_GSM_L1T_Supplement_L()
#define ChkL1MsgFltr_L1C_Trace_R99_Bep()	ChkL1ClsFltr_L1C_GSM_R99_L()
#define ChkL1MsgFltr_L1C_Trace_R99_Bep_bNormalize()	ChkL1ClsFltr_L1C_GSM_R99_L()
#define ChkL1MsgFltr_L1C_Trace_R99_Power_bNormalize()	ChkL1ClsFltr_L1C_GSM_R99_L()
#define ChkL1MsgFltr_L1I_Msg_ConflictReportType()	ChkL1ClsFltr_L1C_GSM_ReportFCCh_H()
#define ChkL1MsgFltr_L1I_Msg_SimModeChange()	ChkL1ClsFltr_L1C_GSM_SimMode_H()
#define ChkL1MsgFltr_L1T_TRC_REDUMP()	ChkL1ClsFltr_L1C_GSM_L1C_ERROR_L()
#define ChkL1MsgFltr_L1I_Msg_ServingSB()	ChkL1ClsFltr_L1C_GSM_ServingSB_M()
#define ChkL1MsgFltr_L1C_Msg_ServingSCh()	ChkL1ClsFltr_L1C_GSM_ServingSCh_H()


#endif
