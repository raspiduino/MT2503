#ifndef L1TRC_L1C_EGPRS_DEF_H
#define L1TRC_L1C_EGPRS_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1C_Str_TBF_Direct(v1)  (unsigned char)(v1+2)
#define L1C_Str_TBFStart(v1)  (unsigned char)(v1+5)
#define L1C_Str_TBF_Status(v1)  (unsigned char)(v1+11)
#define L1C_Str_TBFMode(v1)  (unsigned char)(v1+14)
#define L1C_Str_UplinkMode(v1)  (unsigned char)(v1+16)
#define L1C_Str_PSHandoverType(v1)  (unsigned char)(v1+20)
#define L1C_Str_BackupRestore_VQ(v1)  (unsigned char)(v1+22)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trace_EGPRS_TBFStart(v1, v2, v3) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_TBFStart((unsigned char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define L1T_Trace_EGPRS_TBFStart(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_DL_header(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1T_Trace_DL_header((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9));\
} while(0)
#else
	#define L1T_Trace_DL_header(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCh(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCh((unsigned char)(v1), (char)(v2), (unsigned short)(v3), (unsigned short)(v4), (unsigned short)(v5));\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCh_Header(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCh_Header((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (short)(v5), (char)(v6), (char)(v7), (char)(v8), (char)(v9), (char)(v10));\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh_Header(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCh2(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCh2((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned short)(v4), (unsigned short)(v5), (unsigned short)(v6));\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh2(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCh2_Header(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCh2_Header((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (short)(v5), (short)(v6), (char)(v7), (char)(v8), (char)(v9), (char)(v10), (char)(v11), (char)(v12));\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCh2_Header(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_EGPRS_DSP_DPS_IR(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_DSP_DPS_IR((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4), (char)(v5));\
} while(0)
#else
	#define L1T_Trace_EGPRS_DSP_DPS_IR(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_DSP_IR(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_DSP_IR((unsigned char)(v1), (short)(v2), (short)(v3), (char)(v4));\
} while(0)
#else
	#define L1T_Trace_EGPRS_DSP_IR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_DSP_IR2(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_DSP_IR2((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9));\
} while(0)
#else
	#define L1T_Trace_EGPRS_DSP_IR2(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif

#if defined(L1_CATCHER)
	#define L1T_Trace_EGPRS_PDTCH_Conflict(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_EGPRS_PDTCH_Conflict((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1T_Trace_EGPRS_PDTCH_Conflict(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_Set_SRB_Mode(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1T_Trace_Set_SRB_Mode((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4), (char)(v5), (char)(v6));\
} while(0)
#else
	#define L1T_Trace_Set_SRB_Mode(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_SRB_Assigned_Ts(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1T_Trace_SRB_Assigned_Ts((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1T_Trace_SRB_Assigned_Ts(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1T_Trace_SBT(v1, v2, v3) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1T_Trace_SBT((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1T_Trace_SBT(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trace_ReportPDTChBad_wBEP(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_ReportPDTChBad_wBEP((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned short)(v4), (unsigned short)(v5), (unsigned short)(v6));\
} while(0)
#else
	#define L1C_Trace_ReportPDTChBad_wBEP(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1T_Trace_GPRS_PDTCh_wBEP(v1, v2, v3) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1T_Trace_GPRS_PDTCh_wBEP((unsigned char)(v1), (unsigned short)(v2), (unsigned short)(v3));\
} while(0)
#else
	#define L1T_Trace_GPRS_PDTCh_wBEP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1T_Trace_EgprsResetIR(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1T_Trace_EgprsResetIR((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1T_Trace_EgprsResetIR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_DL(v1, v2, v3, v4) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_TBFStart_DL((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1C_Trace_TBFStart_DL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_UL(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_TBFStart_UL((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (unsigned long)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1C_Trace_TBFStart_UL(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_DL_Temp(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_TBFStart_DL_Temp((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (unsigned char)(v4), (unsigned long)(v5));\
} while(0)
#else
	#define L1C_Trace_TBFStart_DL_Temp(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_UL_Temp(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_TBFStart_UL_Temp((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (unsigned char)(v4), (unsigned long)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1C_Trace_TBFStart_UL_Temp(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFStart_Base(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_TBFStart_Base((unsigned char)(v1), (unsigned char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1C_Trace_TBFStart_Base(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBF_Status(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_TBF_Status((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1C_Trace_TBF_Status(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_TBFMode(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_TBFMode((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_TBFMode(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Trace_ResetIR(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Trace_ResetIR((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_ResetIR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_TBFHandoverStart(v1, v2, v3, v4, v5) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_TBFHandoverStart((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define L1C_Msg_TBFHandoverStart(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SetPDTChABCount(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_SetPDTChABCount((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1C_Msg_SetPDTChABCount(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_GetPacketTimingAdvance(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_GetPacketTimingAdvance((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1C_Msg_GetPacketTimingAdvance(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SearchFBforBlindHO(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_SearchFBforBlindHO((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1C_Msg_SearchFBforBlindHO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_UpdateHandoverRAChCount(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_UpdateHandoverRAChCount((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1C_Msg_UpdateHandoverRAChCount(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_PDTChRAChStop(v1, v2) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_PDTChRAChStop((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1C_Msg_PDTChRAChStop(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_BackupRestore_VQ(v1, v2, v3) do {\
		if(L1C_EGPRS_Trace_Filter[0]==1 && (L1C_EGPRS_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_BackupRestore_VQ((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Msg_BackupRestore_VQ(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_EGPRS_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1T_Trace_EGPRS_TBFStart(unsigned char v1, char v2, char v3);
void L1TRC_Send_L1T_Trace_DL_header(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh(unsigned char v1, char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh_Header(unsigned char v1, char v2, char v3, char v4, short v5, char v6, char v7, char v8, char v9, char v10);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh2(unsigned char v1, char v2, char v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCh2_Header(unsigned char v1, char v2, char v3, char v4, short v5, short v6, char v7, char v8, char v9, char v10, char v11, char v12);
void L1TRC_Send_L1T_Trace_EGPRS_DSP_DPS_IR(unsigned char v1, short v2, short v3, short v4, char v5);
void L1TRC_Send_L1T_Trace_EGPRS_DSP_IR(unsigned char v1, short v2, short v3, char v4);
void L1TRC_Send_L1T_Trace_EGPRS_DSP_IR2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_L1T_Trace_EGPRS_PDTCH_Conflict(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1T_Trace_Set_SRB_Mode(unsigned char v1, char v2, char v3, char v4, char v5, char v6);
void L1TRC_Send_L1T_Trace_SRB_Assigned_Ts(unsigned char v1, char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1T_Trace_SBT(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1C_Trace_ReportPDTChBad_wBEP(unsigned char v1, unsigned char v2, unsigned char v3, unsigned short v4, unsigned short v5, unsigned short v6);
void L1TRC_Send_L1T_Trace_GPRS_PDTCh_wBEP(unsigned char v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_L1T_Trace_EgprsResetIR(unsigned char v1, char v2, char v3, unsigned char v4);
void L1TRC_Send_L1C_Trace_TBFStart_DL(unsigned char v1, char v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_L1C_Trace_TBFStart_UL(unsigned char v1, char v2, unsigned char v3, unsigned long v4, unsigned char v5);
void L1TRC_Send_L1C_Trace_TBFStart_DL_Temp(unsigned char v1, unsigned char v2, char v3, unsigned char v4, unsigned long v5);
void L1TRC_Send_L1C_Trace_TBFStart_UL_Temp(unsigned char v1, unsigned char v2, char v3, unsigned char v4, unsigned long v5, unsigned char v6);
void L1TRC_Send_L1C_Trace_TBFStart_Base(unsigned char v1, unsigned char v2, char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_L1C_Trace_TBF_Status(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1C_Trace_TBFMode(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trace_ResetIR(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_TBFHandoverStart(unsigned char v1, unsigned char v2, short v3, short v4, short v5);
void L1TRC_Send_L1C_Msg_SetPDTChABCount(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_GetPacketTimingAdvance(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_SearchFBforBlindHO(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_UpdateHandoverRAChCount(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_PDTChRAChStop(unsigned char v1, short v2);
void L1TRC_Send_L1C_Msg_BackupRestore_VQ(unsigned char v1, unsigned char v2, unsigned char v3);

void Set_L1C_EGPRS_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_EGPRS()	(L1C_EGPRS_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_L1T_EGPRS_TBFStart_M()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_DL_header_L()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh__IR_L()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_SRB_L()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_SBT_L()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_MTBF_M()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1C_EGPRS_PSHO_M()	(ChkL1ModFltr_L1C_EGPRS()&&((L1C_EGPRS_Trace_Filter[1]&0x80)!=0))
#define ChkL1MsgFltr_L1T_Trace_EGPRS_TBFStart()	ChkL1ClsFltr_L1C_EGPRS_L1T_EGPRS_TBFStart_M()
#define ChkL1MsgFltr_L1T_Trace_DL_header()	ChkL1ClsFltr_L1C_EGPRS_DL_header_L()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCh()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCh_Header()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCh2()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCh2_Header()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_DSP_DPS_IR()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh__IR_L()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_DSP_IR()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_DSP_IR2()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EGPRS_PDTCH_Conflict()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_Set_SRB_Mode()	ChkL1ClsFltr_L1C_EGPRS_SRB_L()
#define ChkL1MsgFltr_L1T_Trace_SRB_Assigned_Ts()	ChkL1ClsFltr_L1C_EGPRS_SRB_L()
#define ChkL1MsgFltr_L1T_Trace_SBT()	ChkL1ClsFltr_L1C_EGPRS_SBT_L()
#define ChkL1MsgFltr_L1C_Trace_ReportPDTChBad_wBEP()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_GPRS_PDTCh_wBEP()	ChkL1ClsFltr_L1C_EGPRS_ReportPDTCh_H()
#define ChkL1MsgFltr_L1T_Trace_EgprsResetIR()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_DL()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_UL()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_DL_Temp()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_UL_Temp()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFStart_Base()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBF_Status()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_TBFMode()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Trace_ResetIR()	ChkL1ClsFltr_L1C_EGPRS_MTBF_M()
#define ChkL1MsgFltr_L1C_Msg_TBFHandoverStart()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_SetPDTChABCount()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_GetPacketTimingAdvance()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_SearchFBforBlindHO()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_UpdateHandoverRAChCount()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_PDTChRAChStop()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()
#define ChkL1MsgFltr_L1C_Msg_BackupRestore_VQ()	ChkL1ClsFltr_L1C_EGPRS_PSHO_M()


#endif
