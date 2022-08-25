#ifndef L1TRC_CSD_DEF_H
#define L1TRC_CSD_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_RXQUAL(v1, v2, v3, v4, v5, v6, v7) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL((unsigned char)(v1), (short)(v2), (short)(v3), (char)(v4), (short)(v5), (short)(v6), (char)(v7));\
} while(0)
#else
	#define L1C_Trace_RXQUAL(v1, v2, v3, v4, v5, v6, v7)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_RXQUAL_AFS(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_AFS((unsigned char)(v1), (char)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Trace_RXQUAL_AFS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_RXQUAL_AHS(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_AHS((unsigned char)(v1), (char)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Trace_RXQUAL_AHS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1C_Trace_RXQUAL_Input(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_L1C_Trace_RXQUAL_Input((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1C_Trace_RXQUAL_Input(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_ActivateReq(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_ActivateReq((unsigned char)(v1), (char)(v2), (char)(v3), (char)(v4));\
} while(0)
#else
	#define CSD_Msg_ActivateReq(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_DeActivateReq(v1) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_DeActivateReq((unsigned char)(v1));\
} while(0)
#else
	#define CSD_Msg_DeActivateReq(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_CMMReq(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_CMMReq((unsigned char)(v1), (char)(v2), (char)(v3));\
} while(0)
#else
	#define CSD_Msg_CMMReq(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_SHIFT_HALF_RLP(v1) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_SHIFT_HALF_RLP((unsigned char)(v1));\
} while(0)
#else
	#define CSD_Msg_SHIFT_HALF_RLP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_DL_FCS_ERROR(v1) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_DL_FCS_ERROR((unsigned char)(v1));\
} while(0)
#else
	#define CSD_Msg_DL_FCS_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_UL_DTX_Allow(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_UL_DTX_Allow((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define CSD_Msg_UL_DTX_Allow(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_LoopMode(v1, v2) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_LoopMode((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define CSD_Msg_LoopMode(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_Dummy_Pattern_OverLoading(v1) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_Dummy_Pattern_OverLoading((unsigned char)(v1));\
} while(0)
#else
	#define CSD_Msg_Dummy_Pattern_OverLoading(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_MSG_DSP_L2FillFrame(v1) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_CSD_MSG_DSP_L2FillFrame((unsigned char)(v1));\
} while(0)
#else
	#define CSD_MSG_DSP_L2FillFrame(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_DnlinkData1(v1, v2, v3, v4, v5) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_CSD_Msg_DnlinkData1((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (char)(v4), (char)(v5));\
} while(0)
#else
	#define CSD_Msg_DnlinkData1(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_DnlinkData2(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_CSD_Msg_DnlinkData2((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define CSD_Msg_DnlinkData2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_UplinkData1(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_CSD_Msg_UplinkData1((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (char)(v4));\
} while(0)
#else
	#define CSD_Msg_UplinkData1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_UplinkData2(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_CSD_Msg_UplinkData2((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define CSD_Msg_UplinkData2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_L1PutDnlinkData1(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_CSD_Msg_L1PutDnlinkData1((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define CSD_Msg_L1PutDnlinkData1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_L1PutDnlinkData2(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x01)!=0 )\
			L1TRC_Send_CSD_Msg_L1PutDnlinkData2((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define CSD_Msg_L1PutDnlinkData2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_L1GetUplinkData1(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_CSD_Msg_L1GetUplinkData1((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define CSD_Msg_L1GetUplinkData1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define CSD_Msg_L1GetUplinkData2(v1, v2, v3) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x04)!=0 )\
			L1TRC_Send_CSD_Msg_L1GetUplinkData2((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define CSD_Msg_L1GetUplinkData2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define FAX_Msg_DnlinkData1(v1, v2, v3, v4, v5) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x08)!=0 )\
			L1TRC_Send_FAX_Msg_DnlinkData1((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (char)(v4), (char)(v5));\
} while(0)
#else
	#define FAX_Msg_DnlinkData1(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define FAX_Msg_DnlinkData2(v1, v2, v3, v4, v5) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_FAX_Msg_DnlinkData2((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define FAX_Msg_DnlinkData2(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define FAX_Msg_UplinkData1(v1, v2, v3, v4) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x20)!=0 )\
			L1TRC_Send_FAX_Msg_UplinkData1((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3), (char)(v4));\
} while(0)
#else
	#define FAX_Msg_UplinkData1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define FAX_Msg_UplinkData2(v1, v2, v3, v4, v5) do {\
		if(CSD_Trace_Filter[0]==1 && (CSD_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_FAX_Msg_UplinkData2((unsigned char)(v1), (char)(v2), (unsigned char)(v3), (char)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define FAX_Msg_UplinkData2(v1, v2, v3, v4, v5)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char CSD_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1C_Trace_RXQUAL(unsigned char v1, short v2, short v3, char v4, short v5, short v6, char v7);
void L1TRC_Send_L1C_Trace_RXQUAL_AFS(unsigned char v1, char v2, short v3, short v4);
void L1TRC_Send_L1C_Trace_RXQUAL_AHS(unsigned char v1, char v2, short v3, short v4);
void L1TRC_Send_L1C_Trace_RXQUAL_Input(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_CSD_Msg_ActivateReq(unsigned char v1, char v2, char v3, char v4);
void L1TRC_Send_CSD_Msg_DeActivateReq(unsigned char v1);
void L1TRC_Send_CSD_Msg_CMMReq(unsigned char v1, char v2, char v3);
void L1TRC_Send_CSD_Msg_SHIFT_HALF_RLP(unsigned char v1);
void L1TRC_Send_CSD_Msg_DL_FCS_ERROR(unsigned char v1);
void L1TRC_Send_CSD_Msg_UL_DTX_Allow(unsigned char v1, char v2);
void L1TRC_Send_CSD_Msg_LoopMode(unsigned char v1, char v2);
void L1TRC_Send_CSD_Msg_Dummy_Pattern_OverLoading(unsigned char v1);
void L1TRC_Send_CSD_MSG_DSP_L2FillFrame(unsigned char v1);
void L1TRC_Send_CSD_Msg_DnlinkData1(unsigned char v1, unsigned char v2, unsigned char v3, char v4, char v5);
void L1TRC_Send_CSD_Msg_DnlinkData2(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_CSD_Msg_UplinkData1(unsigned char v1, unsigned char v2, unsigned char v3, char v4);
void L1TRC_Send_CSD_Msg_UplinkData2(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_CSD_Msg_L1PutDnlinkData1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_CSD_Msg_L1PutDnlinkData2(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_CSD_Msg_L1GetUplinkData1(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_CSD_Msg_L1GetUplinkData2(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_FAX_Msg_DnlinkData1(unsigned char v1, unsigned char v2, unsigned char v3, char v4, char v5);
void L1TRC_Send_FAX_Msg_DnlinkData2(unsigned char v1, char v2, unsigned char v3, char v4, unsigned char v5);
void L1TRC_Send_FAX_Msg_UplinkData1(unsigned char v1, unsigned char v2, unsigned char v3, char v4);
void L1TRC_Send_FAX_Msg_UplinkData2(unsigned char v1, char v2, unsigned char v3, char v4, unsigned char v5);

void Set_CSD_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_CSD()	(CSD_Trace_Filter[0]==1)
#define ChkL1ClsFltr_CSD_RX_QUAL_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_CSD_RX_QUAL_IN_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_CSD_CSD_COMMON_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_CSD_CSD_DL_Data1_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_CSD_CSD_DL_Data2_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_CSD_CSD_UL_Data1_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_CSD_CSD_UL_Data2_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_CSD_CSD_L1PutDL_Data1_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_CSD_CSD_L1PutDL_Data2_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_CSD_CSD_L1GetUL_Data1_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_CSD_CSD_L1GetUL_Data2_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_CSD_FAX_DL_Data1_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_CSD_FAX_DL_Data2_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_CSD_FAX_UL_Data1_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_CSD_FAX_UL_Data2_L()	(ChkL1ModFltr_CSD()&&((CSD_Trace_Filter[2]&0x40)!=0))
#define ChkL1MsgFltr_L1C_Trace_RXQUAL()	ChkL1ClsFltr_CSD_RX_QUAL_L()
#define ChkL1MsgFltr_L1C_Trace_RXQUAL_AFS()	ChkL1ClsFltr_CSD_RX_QUAL_L()
#define ChkL1MsgFltr_L1C_Trace_RXQUAL_AHS()	ChkL1ClsFltr_CSD_RX_QUAL_L()
#define ChkL1MsgFltr_L1C_Trace_RXQUAL_Input()	ChkL1ClsFltr_CSD_RX_QUAL_IN_L()
#define ChkL1MsgFltr_CSD_Msg_ActivateReq()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_Msg_DeActivateReq()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_Msg_CMMReq()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_Msg_SHIFT_HALF_RLP()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_Msg_DL_FCS_ERROR()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_Msg_UL_DTX_Allow()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_Msg_LoopMode()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_Msg_Dummy_Pattern_OverLoading()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_MSG_DSP_L2FillFrame()	ChkL1ClsFltr_CSD_CSD_COMMON_L()
#define ChkL1MsgFltr_CSD_Msg_DnlinkData1()	ChkL1ClsFltr_CSD_CSD_DL_Data1_L()
#define ChkL1MsgFltr_CSD_Msg_DnlinkData2()	ChkL1ClsFltr_CSD_CSD_DL_Data2_L()
#define ChkL1MsgFltr_CSD_Msg_UplinkData1()	ChkL1ClsFltr_CSD_CSD_UL_Data1_L()
#define ChkL1MsgFltr_CSD_Msg_UplinkData2()	ChkL1ClsFltr_CSD_CSD_UL_Data2_L()
#define ChkL1MsgFltr_CSD_Msg_L1PutDnlinkData1()	ChkL1ClsFltr_CSD_CSD_L1PutDL_Data1_L()
#define ChkL1MsgFltr_CSD_Msg_L1PutDnlinkData2()	ChkL1ClsFltr_CSD_CSD_L1PutDL_Data2_L()
#define ChkL1MsgFltr_CSD_Msg_L1GetUplinkData1()	ChkL1ClsFltr_CSD_CSD_L1GetUL_Data1_L()
#define ChkL1MsgFltr_CSD_Msg_L1GetUplinkData2()	ChkL1ClsFltr_CSD_CSD_L1GetUL_Data2_L()
#define ChkL1MsgFltr_FAX_Msg_DnlinkData1()	ChkL1ClsFltr_CSD_FAX_DL_Data1_L()
#define ChkL1MsgFltr_FAX_Msg_DnlinkData2()	ChkL1ClsFltr_CSD_FAX_DL_Data2_L()
#define ChkL1MsgFltr_FAX_Msg_UplinkData1()	ChkL1ClsFltr_CSD_FAX_UL_Data1_L()
#define ChkL1MsgFltr_FAX_Msg_UplinkData2()	ChkL1ClsFltr_CSD_FAX_UL_Data2_L()


#endif
