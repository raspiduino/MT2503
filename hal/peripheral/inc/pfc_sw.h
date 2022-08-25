/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    pfc_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for PFC driver sw define parameters.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PFC_SW_H
#define PFC_SW_H

#if defined(__HW_PFC_SUPPORT__)

#include "dcl.h"
//#include "ppp_l4_enums.h"
//#include "ppp_buff_mgr.h"

#include "kal_general_types.h"

#define MAX_LINK_COUNT					3

#define PPP_PROTOCOL_LCP              	0xc021   /* Link Control Protocol */

/*
 * AHDLC Frame Decoder
 */
#define MARK_DISCARD                  	0x80
#define MARK_ESCAPED                  	0x01

#define AHDLC_FCS_FINAL 				0xf0b8
#define AHDLC_FLAG                    	0x7e  /* Flag Sequence */
//#define DRV_PFC_POLLING
//#define PFC_COPY_TO_NON_CACHE
//#include "ppp_l4_enums.h" // for ppp_error_cause_enum


/*
typedef enum
{
   PPPE_NONE,
   PPPE_LCP_FAIL,
   PPPE_AUTH_FAIL,
   PPPE_IPCP_FAIL,
   PPPE_ESC_DETECT,
   PPPE_PLUGOUT_DETECT,
   // Carlson Lin mtk01936 2008/03/19 Solve MAUI_00638325 /
   PPPE_PPP_GPRS_DIALUP_ALREADY_ACTIVATED,
   // ~ Carlson Lin mtk01936 2008/03/19 Solve MAUI_00638325 /
   PPPE_PPP_NOT_ACTIVATED_BY_EXT_MODEM_YET,
   PPPE_PPP_ALREADY_ACTIVATED_BY_EXT_MODEM,
   PPPE_PPP_NOT_ACTIVATED_BY_WAP_OVER_CSD_YET,
   PPPE_PPP_ALREADY_ACTIVATED_BY_WAP_OVER_CSD,
   PPPE_PPP_WRONG_CSD_MOD_ID,
   PPPE_PPP_DETECT_AT_CMD_DURING_DIALUP, //[MONZA00008185]
   PPPE_PPP_DETECT_ESCAPE_DURING_DIALUP, //[MONZA00008185]
   PPPE_PPP_ERROR_CAUSE_ENUM_SIZE
} ppp_error_cause_enum;
*/

typedef enum { //toy add for single tunnel vfifo.
  pfc_encode=0,
  pfc_acfc,
  pfc_pfc,
  pfc_f32
} PFC_ControlItem;



/*TY adds these to expand flexibility 2004/10/15*/
//typedef void (*PFC_TX_FUNC)(); 
//typedef void (*PFC_RX_FUNC)(); 

#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)     ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)               (*(volatile kal_uint32 *)(addr))
#define DRV_WriteReg8(addr,data)     ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)               (*(volatile kal_uint8 *)(addr))

/*PFC all register informantions */
typedef struct{
	kal_uint32	start;
	kal_uint32	control;
	kal_uint32	protocol;
	kal_uint32	stateAddress;
	kal_uint32	src_adrs;
	kal_uint32	dest_adrs;	
	kal_uint32	src_len;
	kal_uint32	dest_len;	
	kal_uint32	interruptEn;
	kal_uint32	status;
	kal_uint32	slowDownRate;
	kal_uint32	accm0;
	kal_uint32	accm1;
	kal_uint32	accm2;
	kal_uint32	accm3;
	kal_uint32	accm4;
	kal_uint32	accm5;
	kal_uint32	accm6;
}PFC_register_struct;

/*PFC Customization */
typedef struct{
	kal_uint32*	src_adrs;
	kal_uint32*	dest_adrs;	
	kal_uint16	src_len;
	kal_uint16	dest_len;	
}PFC_buffer_struct;

//ppp_buff_type_enum provided by Carlson
/*
typedef enum {
    NULL_BUF,
    CTRL_BUF,
    FLC_BUF,
    TEMP_DECODE_DST_BUFF // __PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND__ 
} ppp_buff_type_enum;
*/

//ahdlc_state_struct provided by Carlson
/*
typedef struct {
   kal_uint32 raccm;
   kal_uint32 xaccm;
   kal_uint16 rfcs;
   kal_uint16 xfcs;
   kal_uint16 mru;
   kal_uint16 mtu;
   kal_bool is_acfc_tx;
   kal_bool is_pfc_tx;
   kal_bool is_acfc_rx;
   kal_bool is_pfc_rx;
   kal_uint8 rflags;
   kal_uint8 xflags;
} PFC_ahdlc_state_struct;
//ppp_buff_head_struct provided by Carlson
typedef struct {
    ppp_buff_type_enum pkt_type;
// #ifdef DO_IP_4B_ALIGN_IN_FRAME_DECODE_FUNC /
    kal_bool ip_pkt_four_byte_align_required; // DO_IP_4B_ALIGN_IN_FRAME_DECODE_FUNC /
    kal_bool ip_pkt_four_byte_align_already_done; // DO_IP_4B_ALIGN_IN_FRAME_DECODE_FUNC /
// #endif / / DO_IP_4B_ALIGN_IN_FRAME_DECODE_FUNC /
    kal_uint16 protocol;
    kal_uint16 size;
    kal_uint16 used;
    kal_uint8 *data_ptr;
    kal_uint8 *cur_ptr;
    kal_uint8 *end_ptr;
} ppp_buff_head_struct;

*/



extern void PFC_SetSDRate(kal_uint16 value);
extern kal_uint16 PFC_ReadStatus(void);
extern void PFC_SetIntEn(kal_uint16 enable);
extern void PFC_SetDESTaddr(kal_uint32 addr);
extern void PFC_SetSRCaddr(kal_uint32 addr);
extern kal_uint32 PFC_ReadDESTaddr(void);
extern kal_uint32 PFC_ReadSRCaddr(void);
extern void PFC_SetDESTlen(kal_uint16 len);
extern void PFC_SetSRClen(kal_uint16 len);
extern kal_uint16 PFC_UnuseDESTlen(void);
extern kal_uint16 PFC_UnreadSRClen(void);
extern kal_bool PFC_SetBufferInfo(PFC_buffer_struct * buf);
extern void PFC_ReadBufferInfo( PFC_buffer_struct * buf);
extern void PFC_ReadAllRegister( PFC_register_struct * reg);
extern kal_uint32 PFC_ReadACCM(kal_uint16 part);
extern void PFC_WriteACCM(kal_uint16 part, kal_uint32 value);
extern void PFC_SetSAddr(kal_uint16 saddr);
extern void PFC_SetProtocol(kal_uint16 protocol);
extern void PFC_Control( PFC_ControlItem  ctrl, kal_bool  enable);
extern void PFC_ReadState(kal_uint8 * state);
extern void PFC_WriteState(kal_uint8 * state);
extern kal_bool PFC_Decode(pfc_buff_head_struct * dest, pfc_buff_head_struct * src, 
             pfc_ahdlc_state_struct * state, pfc_error_cause_enum * rcv_AT_CMD_OR_ESCAPE);
extern kal_bool PFC_Encode(pfc_buff_head_struct * dest, pfc_buff_head_struct * src, 
             pfc_ahdlc_state_struct * state);
extern void PFC_init(void);
extern void PFC_reset(kal_uint32 context_id);
extern void PFC_HISR(void);
extern void PFC_LISR(void);
extern void PFC_register_test(kal_uint32 reg, kal_uint32 max);

#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_PFC_REG_DBG__)
#define DRV_PFC_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_PFC_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_PFC_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_PFC_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_PFC_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_PFC_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_PFC_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_PFC_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_PFC_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_PFC_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_PFC_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_PFC_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_PFC_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_PFC_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_PFC_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_PFC_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_PFC_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_PFC_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_PFC_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_PFC_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_PFC_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_PFC_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_PFC_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_PFC_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_PFC_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_PFC_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_PFC_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_PFC_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_PFC_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_PFC_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_KBD_REG_DBG__)
#endif //#define __HW_PFC_SUPPORT__
#endif   /*PFC_SW_H*/
