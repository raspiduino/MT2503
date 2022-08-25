#ifndef L1TRC_L1C_GSM2_DEF_H
#define L1TRC_L1C_GSM2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1C_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1C_Str_ReportType(v1)  (unsigned char)(v1+2)
#define L1C_Str_InitialCvalue(v1)  (unsigned char)(v1+49)
#define L1C_Str_SDCCH_Update_MeanBep(v1)  (unsigned char)(v1+51)
#define L1C_Str_Power_Ctrl_Status(v1)  (unsigned char)(v1+53)
#define L1C_Str_PCHinPTM(v1)  (unsigned char)(v1+63)
#define L1C_Str_PDTCH_BLOCK(v1)  (unsigned char)(v1+67)
#define L1C_Str_Serv_BSIC(v1)  (unsigned char)(v1+69)
#define L1C_Str_Rdrbn_Type(v1)  (unsigned char)(v1+73)
#define L1C_Str_VirtualPowerScanState(v1)  (unsigned char)(v1+78)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_REL5_IDLE_updateCvalue(v1, v2, v3, v4) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_REL5_IDLE_updateCvalue((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Trace_REL5_IDLE_updateCvalue(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_REL5_PTM_updateCvalue(v1, v2, v3, v4) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_REL5_PTM_updateCvalue((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Trace_REL5_PTM_updateCvalue(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_REL5_MEAN_BEP(v1, v2, v3) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_REL5_MEAN_BEP((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Trace_REL5_MEAN_BEP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_REL5_Power_Control_Value(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_REL5_Power_Control_Value((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6), (short)(v7), (short)(v8), (short)(v9), (short)(v10));\
} while(0)
#else
	#define L1C_Trace_REL5_Power_Control_Value(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_REL5_Power_Control_Staus(v1, v2) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_REL5_Power_Control_Staus((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Trace_REL5_Power_Control_Staus(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1C_Trc_BlindHO(v1, v2, v3, v4) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Trc_BlindHO((unsigned char)(v1), (short)(v2), (short)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1C_Trc_BlindHO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_PCHinPTM_Error(v1, v2, v3) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_PCHinPTM_Error((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Msg_PCHinPTM_Error(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_PDTCH_BLOCK(v1, v2) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1C_Msg_PDTCH_BLOCK((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Msg_PDTCH_BLOCK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1I_Msg_PCHinPTM(v1, v2) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1I_Msg_PCHinPTM((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1I_Msg_PCHinPTM(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_AGPS_Req(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_AGPS_Req((unsigned char)(v1), (short)(v2), (unsigned char)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define L1C_Msg_AGPS_Req(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_AGPS_Req_Fail(v1, v2, v3) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_AGPS_Req_Fail((unsigned char)(v1), (short)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Msg_AGPS_Req_Fail(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_AGPS_Execute(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_AGPS_Execute((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1C_Msg_AGPS_Execute(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_AGPS_Delay(v1, v2, v3, v4) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_AGPS_Delay((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Msg_AGPS_Delay(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_AGPS_Rpt(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_AGPS_Rpt((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4), (unsigned char)(v5), (short)(v6), (unsigned long)(v7), (unsigned long)(v8), (short)(v9));\
} while(0)
#else
	#define L1C_Msg_AGPS_Rpt(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_AGPS_Supend(v1) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_AGPS_Supend((unsigned char)(v1));\
} while(0)
#else
	#define L1C_Msg_AGPS_Supend(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_AGPS_ServingBisc(v1, v2, v3) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1C_Msg_AGPS_ServingBisc((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define L1C_Msg_AGPS_ServingBisc(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_RdRbn_CompareWeighting(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_RdRbn_CompareWeighting((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (short)(v4), (unsigned char)(v5), (short)(v6), (short)(v7));\
} while(0)
#else
	#define L1C_Msg_RdRbn_CompareWeighting(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_RdRbn_UpdateWeighting(v1, v2, v3, v4) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_RdRbn_UpdateWeighting((unsigned char)(v1), (unsigned char)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Msg_RdRbn_UpdateWeighting(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_RdRbn_LinkList(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_RdRbn_LinkList((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1C_Msg_RdRbn_LinkList(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_RdRbn_PutToLast(v1, v2, v3, v4, v5, v6) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_L1C_Msg_RdRbn_PutToLast((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1C_Msg_RdRbn_PutToLast(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_ReportPChSharing(v1, v2, v3, v4) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_ReportPChSharing((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1C_Msg_ReportPChSharing(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_ReportPChConflict(v1, v2, v3, v4) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_ReportPChConflict((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4));\
} while(0)
#else
	#define L1C_Msg_ReportPChConflict(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_ReportBCChSharing(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_ReportBCChSharing((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (char)(v5));\
} while(0)
#else
	#define L1C_Msg_ReportBCChSharing(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Msg_ReportBCChConflict(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_L1C_Msg_ReportBCChConflict((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (char)(v5));\
} while(0)
#else
	#define L1C_Msg_ReportBCChConflict(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_ChanProtect_Req(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_ChanProtect_Req((unsigned char)(v1), (unsigned short)(v2), (unsigned char)(v3), (unsigned long)(v4), (unsigned long)(v5));\
} while(0)
#else
	#define L1C_Msg_ChanProtect_Req(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_PowerScanParam(v1, v2, v3, v4, v5) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_PowerScanParam((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (short)(v4), (unsigned short)(v5));\
} while(0)
#else
	#define L1C_Msg_PowerScanParam(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SCRestartPeerBSICSearch(v1) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_SCRestartPeerBSICSearch((unsigned char)(v1));\
} while(0)
#else
	#define L1C_Msg_SCRestartPeerBSICSearch(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_SmartPaging(v1, v2) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1C_Msg_SmartPaging((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Msg_SmartPaging(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_UpdateChannel_VAMOS(v1, v2) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_L1C_Msg_UpdateChannel_VAMOS((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1C_Msg_UpdateChannel_VAMOS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1C_Msg_TAC_Clipping(v1, v2) do {\
		if(L1C_GSM2_Trace_Filter[0]==1 && (L1C_GSM2_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1C_Msg_TAC_Clipping((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1C_Msg_TAC_Clipping(v1, v2)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1C_GSM2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Trace_REL5_IDLE_updateCvalue(unsigned char v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_L1C_Trace_REL5_PTM_updateCvalue(unsigned char v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_L1C_Trace_REL5_MEAN_BEP(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Trace_REL5_Power_Control_Value(unsigned char v1, short v2, short v3, short v4, short v5, short v6, short v7, short v8, short v9, short v10);
void L1TRC_Send_L1C_Trace_REL5_Power_Control_Staus(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Trc_BlindHO(unsigned char v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_PCHinPTM_Error(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Msg_PDTCH_BLOCK(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1I_Msg_PCHinPTM(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_AGPS_Req(unsigned char v1, short v2, unsigned char v3, short v4, short v5);
void L1TRC_Send_L1C_Msg_AGPS_Req_Fail(unsigned char v1, short v2, unsigned char v3);
void L1TRC_Send_L1C_Msg_AGPS_Execute(unsigned char v1, short v2, short v3, short v4, unsigned char v5);
void L1TRC_Send_L1C_Msg_AGPS_Delay(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1C_Msg_AGPS_Rpt(unsigned char v1, short v2, short v3, short v4, unsigned char v5, short v6, unsigned long v7, unsigned long v8, short v9);
void L1TRC_Send_L1C_Msg_AGPS_Supend(unsigned char v1);
void L1TRC_Send_L1C_Msg_AGPS_ServingBisc(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1C_Msg_RdRbn_CompareWeighting(unsigned char v1, unsigned char v2, short v3, short v4, unsigned char v5, short v6, short v7);
void L1TRC_Send_L1C_Msg_RdRbn_UpdateWeighting(unsigned char v1, unsigned char v2, short v3, short v4);
void L1TRC_Send_L1C_Msg_RdRbn_LinkList(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1C_Msg_RdRbn_PutToLast(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1C_Msg_ReportPChSharing(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_ReportPChConflict(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_L1C_Msg_ReportBCChSharing(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_L1C_Msg_ReportBCChConflict(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4, char v5);
void L1TRC_Send_L1C_Msg_ChanProtect_Req(unsigned char v1, unsigned short v2, unsigned char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_L1C_Msg_PowerScanParam(unsigned char v1, char v2, unsigned char v3, short v4, unsigned short v5);
void L1TRC_Send_L1C_Msg_SCRestartPeerBSICSearch(unsigned char v1);
void L1TRC_Send_L1C_Msg_SmartPaging(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_UpdateChannel_VAMOS(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1C_Msg_TAC_Clipping(unsigned char v1, short v2);

void Set_L1C_GSM2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1C_GSM2()	(L1C_GSM2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1C_GSM2_REL5_L()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1C_GSM2_BlindHO_H()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1C_GSM2_PCH_PTM_L()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1C_GSM2_AGPS_L()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1C_GSM2_RDRBN_L()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1C_GSM2_ReportSharing_L()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1C_GSM2_GEMINI20_M()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1C_GSM2_SmartPaging_M()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1C_GSM2_VAMOS_M()	(ChkL1ModFltr_L1C_GSM2()&&((L1C_GSM2_Trace_Filter[2]&0x01)!=0))
#define ChkL1MsgFltr_L1C_Trace_REL5_IDLE_updateCvalue()	ChkL1ClsFltr_L1C_GSM2_REL5_L()
#define ChkL1MsgFltr_L1C_Trace_REL5_PTM_updateCvalue()	ChkL1ClsFltr_L1C_GSM2_REL5_L()
#define ChkL1MsgFltr_L1C_Trace_REL5_MEAN_BEP()	ChkL1ClsFltr_L1C_GSM2_REL5_L()
#define ChkL1MsgFltr_L1C_Trace_REL5_Power_Control_Value()	ChkL1ClsFltr_L1C_GSM2_REL5_L()
#define ChkL1MsgFltr_L1C_Trace_REL5_Power_Control_Staus()	ChkL1ClsFltr_L1C_GSM2_REL5_L()
#define ChkL1MsgFltr_L1C_Trc_BlindHO()	ChkL1ClsFltr_L1C_GSM2_BlindHO_H()
#define ChkL1MsgFltr_L1C_Msg_PCHinPTM_Error()	ChkL1ClsFltr_L1C_GSM2_PCH_PTM_L()
#define ChkL1MsgFltr_L1C_Msg_PDTCH_BLOCK()	ChkL1ClsFltr_L1C_GSM2_PCH_PTM_L()
#define ChkL1MsgFltr_L1I_Msg_PCHinPTM()	ChkL1ClsFltr_L1C_GSM2_PCH_PTM_L()
#define ChkL1MsgFltr_L1C_Msg_AGPS_Req()	ChkL1ClsFltr_L1C_GSM2_AGPS_L()
#define ChkL1MsgFltr_L1C_Msg_AGPS_Req_Fail()	ChkL1ClsFltr_L1C_GSM2_AGPS_L()
#define ChkL1MsgFltr_L1C_Msg_AGPS_Execute()	ChkL1ClsFltr_L1C_GSM2_AGPS_L()
#define ChkL1MsgFltr_L1C_Msg_AGPS_Delay()	ChkL1ClsFltr_L1C_GSM2_AGPS_L()
#define ChkL1MsgFltr_L1C_Msg_AGPS_Rpt()	ChkL1ClsFltr_L1C_GSM2_AGPS_L()
#define ChkL1MsgFltr_L1C_Msg_AGPS_Supend()	ChkL1ClsFltr_L1C_GSM2_AGPS_L()
#define ChkL1MsgFltr_L1C_Msg_AGPS_ServingBisc()	ChkL1ClsFltr_L1C_GSM2_AGPS_L()
#define ChkL1MsgFltr_L1C_Msg_RdRbn_CompareWeighting()	ChkL1ClsFltr_L1C_GSM2_RDRBN_L()
#define ChkL1MsgFltr_L1C_Msg_RdRbn_UpdateWeighting()	ChkL1ClsFltr_L1C_GSM2_RDRBN_L()
#define ChkL1MsgFltr_L1C_Msg_RdRbn_LinkList()	ChkL1ClsFltr_L1C_GSM2_RDRBN_L()
#define ChkL1MsgFltr_L1C_Msg_RdRbn_PutToLast()	ChkL1ClsFltr_L1C_GSM2_RDRBN_L()
#define ChkL1MsgFltr_L1C_Msg_ReportPChSharing()	ChkL1ClsFltr_L1C_GSM2_ReportSharing_L()
#define ChkL1MsgFltr_L1C_Msg_ReportPChConflict()	ChkL1ClsFltr_L1C_GSM2_ReportSharing_L()
#define ChkL1MsgFltr_L1C_Msg_ReportBCChSharing()	ChkL1ClsFltr_L1C_GSM2_ReportSharing_L()
#define ChkL1MsgFltr_L1C_Msg_ReportBCChConflict()	ChkL1ClsFltr_L1C_GSM2_ReportSharing_L()
#define ChkL1MsgFltr_L1C_Msg_ChanProtect_Req()	ChkL1ClsFltr_L1C_GSM2_GEMINI20_M()
#define ChkL1MsgFltr_L1C_Msg_PowerScanParam()	ChkL1ClsFltr_L1C_GSM2_GEMINI20_M()
#define ChkL1MsgFltr_L1C_Msg_SCRestartPeerBSICSearch()	ChkL1ClsFltr_L1C_GSM2_GEMINI20_M()
#define ChkL1MsgFltr_L1C_Msg_SmartPaging()	ChkL1ClsFltr_L1C_GSM2_SmartPaging_M()
#define ChkL1MsgFltr_L1C_Msg_UpdateChannel_VAMOS()	ChkL1ClsFltr_L1C_GSM2_VAMOS_M()
#define ChkL1MsgFltr_L1C_Msg_TAC_Clipping()	ChkL1ClsFltr_L1C_GSM2_GEMINI20_M()


#endif
