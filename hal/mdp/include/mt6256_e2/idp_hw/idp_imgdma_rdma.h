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
 *   idp_imgdma_rdma.h
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 09 20 2011 chelun.tsai
 * removed!
 * .
 *
 * 07 27 2011 chelun.tsai
 * removed!
 * .
 *
 * 06 17 2011 chelun.tsai
 * removed!
 * MDP.
 *
 * 05 05 2011 chelun.tsai
 * removed!
 * last check in befor sample back.
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_rdma_mt6256_e2_h__
#define __idp_imgdma_rdma_mt6256_e2_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6256_E2_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"
#include "reg_base.h"

// Register addresses
#ifndef MDP_C_MODEL

#define R_DMA_BASE R_DMA_base

#define IMGDMA_RDMA_IRQ_FLAG_REG            (R_DMA_BASE + 0x0000)
#define IMGDMA_RDMA_IRQ_FLAG_CLR_REG        (R_DMA_BASE + 0x0008)
#define IMGDMA_RDMA_CFG_REG                 (R_DMA_BASE + 0x0018)
#define IMGDMA_RDMA_STOP_REG                (R_DMA_BASE + 0x0028)
#define IMGDMA_RDMA_EN_REG	                (R_DMA_BASE + 0x0030)
#define IMGDMA_RDMA_RESET_REG	            (R_DMA_BASE + 0x0038)
#define IMGDMA_RDMA_QUEUE_RSTA_REG	        (R_DMA_BASE + 0x0040)
#define IMGDMA_RDMA_RD_BASE_REG	            (R_DMA_BASE + 0x0048)
#define IMGDMA_RDMA_RPT_ADV_REG	            (R_DMA_BASE + 0x0050)
#define IMGDMA_RDMA_QUEUE_WSTA_REG	        (R_DMA_BASE + 0x0058)
#define IMGDMA_RDMA_WR_BASE_REG	            (R_DMA_BASE + 0x0060)
#define IMGDMA_RDMA_WPT_ADV_REG	            (R_DMA_BASE + 0x0068)
#define IMGDMA_RDMA_QUEUE_DATA_REG	        (R_DMA_BASE + 0x0070)
#define IMGDMA_RDMA_QUEUE_BASE_REG	        (R_DMA_BASE + 0x0078)
#define IMGDMA_RDMA_EXEC_CNT_REG            (R_DMA_BASE + 0x0080)
#define IMGDMA_RDMA_IN_SEL_REG	            (R_DMA_BASE + 0x0020)
#define IMGDMA_RDMA_Y_SRC_STR_ADDR_REG	    (R_DMA_BASE + 0x0340)
#define IMGDMA_RDMA_U_SRC_STR_ADDR_REG	    (R_DMA_BASE + 0x0344)
#define IMGDMA_RDMA_V_SRC_STR_ADDR_REG	    (R_DMA_BASE + 0x0348)
#define IMGDMA_RDMA_SRC_SIZE_REG            (R_DMA_BASE + 0x034c)
#define IMGDMA_RDMA_SRC_SIZE_IN_BYTE_REG    (R_DMA_BASE + 0x0354)
#define IMGDMA_RDMA_CLIP_SIZE_REG	        (R_DMA_BASE + 0x0358)
#define IMGDMA_RDMA_CLIP_SIZE_IN_BYTE_REG	(R_DMA_BASE + 0x035c)
#define IMGDMA_RDMA_CON_REG                 (R_DMA_BASE + 0x0360)
#define IMGDMA_RDMA_SLOW_DOWN_REG	        (R_DMA_BASE + 0x0370)
//#define IMGDMA_RDMA_DEBUG_STATUS0_REG	    (R_DMA_BASE + 0x0390)
//#define IMGDMA_RDMA_DEBUG_STATUS1_REG	    (R_DMA_BASE + 0x0394)
//#define IMGDMA_RDMA_DEBUG_STATUS2_REG	    (R_DMA_BASE + 0x0398)
//#define IMGDMA_RDMA_DEBUG_STATUS3_REG	    (R_DMA_BASE + 0x039c)
//#define IMGDMA_RDMA_DEBUG_STATUS4_REG	    (R_DMA_BASE + 0x03a0)
//#define IMGDMA_RDMA_DEBUG_STATUS5_REG	    (R_DMA_BASE + 0x03a4)
//#define IMGDMA_RDMA_DEBUG_STATUS6_REG	    (R_DMA_BASE + 0x03a8)
//#define IMGDMA_RDMA_DEBUG_STATUS7_REG	    (R_DMA_BASE + 0x03ac)
//#define IMGDMA_RDMA_DEBUG_STATUS8_REG	    (R_DMA_BASE + 0x03b0)
//#define IMGDMA_RDMA_DEBUG_STATUS9_REG	    (R_DMA_BASE + 0x03b4)
//#define IMGDMA_RDMA_DEBUG_STATUS10_REG    (R_DMA_BASE + 0x03b8)
//#define IMGDMA_RDMA_DEBUG_STATUS11_REG    (R_DMA_BASE + 0x03bc)
//#define IMGDMA_RDMA_DEBUG_STATUS12_REG    (R_DMA_BASE + 0x03c0)
//#define IMGDMA_RDMA_DEBUG_STATUS13_REG    (R_DMA_BASE + 0x03c4)
//#define IMGDMA_RDMA_DEBUG_STATUS14_REG    (R_DMA_BASE + 0x03c8)
//#define IMGDMA_RDMA_DEBUG_STATUS15_REG    (R_DMA_BASE + 0x03cc)

#define REG_IMGDMA_RDMA_IRQ_FLAG        	*((volatile unsigned int *)IMGDMA_RDMA_IRQ_FLAG_REG)        		
#define REG_IMGDMA_RDMA_IRQ_FLAG_CLR    	*((volatile unsigned int *)IMGDMA_RDMA_IRQ_FLAG_CLR_REG)    		
#define REG_IMGDMA_RDMA_CFG              	*((volatile unsigned int *)IMGDMA_RDMA_CFG_REG)                 
#define REG_IMGDMA_RDMA_STOP             	*((volatile unsigned int *)IMGDMA_RDMA_STOP_REG)                
#define REG_IMGDMA_RDMA_EN	              	*((volatile unsigned int *)IMGDMA_RDMA_EN_REG)	                
#define REG_IMGDMA_RDMA_RESET	          	*((volatile unsigned int *)IMGDMA_RDMA_RESET_REG)	              
#define REG_IMGDMA_RDMA_QUEUE_RSTA	      	*((volatile unsigned int *)IMGDMA_RDMA_QUEUE_RSTA_REG)	        
#define REG_IMGDMA_RDMA_RD_BASE	        	*((volatile unsigned int *)IMGDMA_RDMA_RD_BASE_REG)	        	  
#define REG_IMGDMA_RDMA_RPT_ADV	        	*((volatile unsigned int *)IMGDMA_RDMA_RPT_ADV_REG)	        	  
#define REG_IMGDMA_RDMA_QUEUE_WSTA	      	*((volatile unsigned int *)IMGDMA_RDMA_QUEUE_WSTA_REG)	        
#define REG_IMGDMA_RDMA_WR_BASE	        	*((volatile unsigned int *)IMGDMA_RDMA_WR_BASE_REG)	        	  
#define REG_IMGDMA_RDMA_WPT_ADV	        	*((volatile unsigned int *)IMGDMA_RDMA_WPT_ADV_REG)	        	  
#define REG_IMGDMA_RDMA_QUEUE_DATA	      	*((volatile unsigned int *)IMGDMA_RDMA_QUEUE_DATA_REG)	        
#define REG_IMGDMA_RDMA_QUEUE_BASE	      	*((volatile unsigned int *)IMGDMA_RDMA_QUEUE_BASE_REG)	        
#define REG_IMGDMA_RDMA_EXEC_CNT         	*((volatile unsigned int *)IMGDMA_RDMA_EXEC_CNT_REG)            
#define REG_IMGDMA_RDMA_IN_SEL	          	*((volatile unsigned int *)IMGDMA_RDMA_IN_SEL_REG)	            
#define REG_IMGDMA_RDMA_Y_SRC_STR_ADDR	  	*((volatile unsigned int *)IMGDMA_RDMA_Y_SRC_STR_ADDR_REG)	    
#define REG_IMGDMA_RDMA_U_SRC_STR_ADDR	  	*((volatile unsigned int *)IMGDMA_RDMA_U_SRC_STR_ADDR_REG)	    
#define REG_IMGDMA_RDMA_V_SRC_STR_ADDR	  	*((volatile unsigned int *)IMGDMA_RDMA_V_SRC_STR_ADDR_REG)	    
#define REG_IMGDMA_RDMA_SRC_SIZE         	*((volatile unsigned int *)IMGDMA_RDMA_SRC_SIZE_REG)            
#define REG_IMGDMA_RDMA_SRC_SIZE_IN_BYTE 	*((volatile unsigned int *)IMGDMA_RDMA_SRC_SIZE_IN_BYTE_REG)    
#define REG_IMGDMA_RDMA_CLIP_SIZE	      	*((volatile unsigned int *)IMGDMA_RDMA_CLIP_SIZE_REG)	          
#define REG_IMGDMA_RDMA_CLIP_SIZE_IN_BYTE	*((volatile unsigned int *)IMGDMA_RDMA_CLIP_SIZE_IN_BYTE_REG)	  
#define REG_IMGDMA_RDMA_CON              	*((volatile unsigned int *)IMGDMA_RDMA_CON_REG)                 
#define REG_IMGDMA_RDMA_SLOW_DOWN	      	*((volatile unsigned int *)IMGDMA_RDMA_SLOW_DOWN_REG)	          
//#define REG_IMGDMA_RDMA_DEBUG_STATUS0	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS0_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS1	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS1_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS2	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS2_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS3	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS3_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS4	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS4_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS5	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS5_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS6	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS6_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS7	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS7_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS8	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS8_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS9	  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS9_REG)	      
//#define REG_IMGDMA_RDMA_DEBUG_STATUS10  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS10_REG)	    
//#define REG_IMGDMA_RDMA_DEBUG_STATUS11  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS11_REG)	    
//#define REG_IMGDMA_RDMA_DEBUG_STATUS12  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS12_REG)	    
//#define REG_IMGDMA_RDMA_DEBUG_STATUS13  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS13_REG)	    
//#define REG_IMGDMA_RDMA_DEBUG_STATUS14  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS14_REG)	    
//#define REG_IMGDMA_RDMA_DEBUG_STATUS15  	*((volatile unsigned int *)IMGDMA_RDMA_DEBUG_STATUS15_REG)	 
#else //MDP_C_MODEL
#define REG_IMGDMA_RDMA_IRQ_FLAG	        (R_DMA_IRQ_FLAG)		 
#define REG_IMGDMA_RDMA_IRQ_FLAG_CLR	    (R_DMA_IRQ_FLAG_CLR)     
#define REG_IMGDMA_RDMA_CFG	                (R_DMA_CFG)              
#define REG_IMGDMA_RDMA_STOP	            (R_DMA_STOP)             
#define REG_IMGDMA_RDMA_EN		            (R_DMA_EN)               
#define REG_IMGDMA_RDMA_RESET		        (R_DMA_RESET)            
#define REG_IMGDMA_RDMA_QUEUE_RSTA		    (R_DMA_QUEUE_RSTA)	     
#define REG_IMGDMA_RDMA_RD_BASE	            (R_DMA_RD_BASE)	         
#define REG_IMGDMA_RDMA_RPT_ADV	            (R_DMA_RPT_ADVANCE)      
#define REG_IMGDMA_RDMA_QUEUE_WSTA		    (R_DMA_QUEUE_WSTA)	     
#define REG_IMGDMA_RDMA_WR_BASE	            (R_DMA_WR_BASE)	         
#define REG_IMGDMA_RDMA_WPT_ADV	            (R_DMA_WPT_ADVANCE)      
#define REG_IMGDMA_RDMA_QUEUE_DATA		    (R_DMA_QUEUE_DATA)        
#define REG_IMGDMA_RDMA_QUEUE_BASE		    (R_DMA_QUEUE_BASE)       
#define REG_IMGDMA_RDMA_EXEC_CNT	        (R_DMA_EXEC_CNT)         
#define REG_IMGDMA_RDMA_IN_SEL		        (R_DMA_IN_SEL)           
#define REG_IMGDMA_RDMA_Y_SRC_STR_ADDR	    (R_DMA_Y_SRC_STR_ADDR)   
#define REG_IMGDMA_RDMA_U_SRC_STR_ADDR	    (R_DMA_U_SRC_STR_ADDR)   
#define REG_IMGDMA_RDMA_V_SRC_STR_ADDR	    (R_DMA_V_SRC_STR_ADDR)   
#define REG_IMGDMA_RDMA_SRC_SIZE	        (R_DMA_SRC_SIZE)         
#define REG_IMGDMA_RDMA_SRC_SIZE_IN_BYTE	(R_DMA_SRC_SIZE_IN_BYTE) 
#define REG_IMGDMA_RDMA_CLIP_SIZE		    (R_DMA_CLIP_SIZE)        
#define REG_IMGDMA_RDMA_CLIP_SIZE_IN_BYTE	(R_DMA_CLIP_SIZE_IN_BYTE)	
#define REG_IMGDMA_RDMA_CON	                (R_DMA_CON)              
#define REG_IMGDMA_RDMA_SLOW_DOWN		    (R_DMA_SLOW_DOWN)        

#endif // MDP_C_MODEL

#define IMGDMA_RDMA_CON_INPUT_FORMAT_MASK         0x0000000F
#define IMGDMA_RDMA_CON_INPUT_FORMAT_ARGB8888     0x00000000
#define IMGDMA_RDMA_CON_INPUT_FORMAT_RGB888       0x00000001
#define IMGDMA_RDMA_CON_INPUT_FORMAT_RGB565       0x00000002
#define IMGDMA_RDMA_CON_INPUT_FORMAT_YUYV422      0x00000004
#define IMGDMA_RDMA_CON_INPUT_FORMAT_YUV          0x00000005
#define IMGDMA_RDMA_CON_INPUT_FORMAT_YUV2         0x00000006
#define IMGDMA_RDMA_CON_INPUT_FORMAT_NV12         0x0000000D
#define IMGDMA_RDMA_CON_INPUT_FORMAT_NV21         0x0000000F

#define IMGDMA_RDMA_CON_ROUND_BIT                 0x00000040 /**< rounding when output RGB format */
#define IMGDMA_RDMA_BYTE_SWAP_BIT                 0x00000100
#define IMGDMA_RDMA_RGB_SWAP_BIT                  0x00000200
#define IMGDMA_RDMA_CON_THRESHOLD_MASK            0x0000F000


#define IMGDMA_RDMA_SEG0_EN						  0x00010000	
#define IMGDMA_RDMA_SEG1_EN						  0x00020000	
#define IMGDMA_RDMA_SEG2_EN						  0x00040000	
#define IMGDMA_RDMA_SEG3_EN						  0x00080000
#define IMGDMA_RDMA_SEG4_EN						  0x00100000
#define IMGDMA_RDMA_SEG5_EN						  0x00200000	
#define IMGDMA_RDMA_SEG6_EN						  0x00400000
#define IMGDMA_RDMA_SEG7_EN						  0x00800000	

#define IMGDMA_RDMA_SEG_MASK                      0x00FF0000                   
#define IMGDMA_RDMA_CFG_QUEUEDEPTH_MASK           0x00000f00

// Enable RDMA
#define IMGDMA_RDMA_ENABLE() \
  do { REG_IMGDMA_RDMA_EN = 0x1; } while(0)

// Stop RDMA
#define IMGDMA_RDMA_STOP() \
  do { REG_IMGDMA_RDMA_STOP = 0x1; } while(0)

// Is RDMA enabled?
#define IMGDMA_RDMA_IS_ENABLED() \
  ((0x1 == (REG_IMGDMA_RDMA_EN&0x1)) ? KAL_TRUE : KAL_FALSE)

// Warm reset RDMA
#define IMGDMA_RDMA_WARM_RESET() \
  do { REG_IMGDMA_RDMA_RESET = 0x2; \
       while(0x2 == (REG_IMGDMA_RDMA_RESET&0x2)); } while(0)

// Hard reset RDMA, do not use
//#define IMGDMA_RDMA_HARD_RESET() \
//  do { REG_IMGDMA_RDMA_RESET = 0x1; \
//       REG_IMGDMA_RDMA_RESET = 0x0; } while(0)

// Enable interrupt 
#define IMGDMA_RDMA_INTERRUPT_ENABLE() \
  do { REG_IMGDMA_RDMA_CON |= 0x80000000; } while(0)

// Disable interrupt
#define IMGDMA_RDMA_INTERRUPT_DISABLE() \
  do { REG_IMGDMA_RDMA_CON &= ~0x80000000; } while(0)

// Enable auto loop
#define IMGDMA_RDMA_AUTO_LOOP_ENABLE() \
  do { REG_IMGDMA_RDMA_CFG |= 0x1; } while(0)

// Disable auto loop
#define IMGDMA_RDMA_AUTO_LOOP_DISABLE() \
  do { REG_IMGDMA_RDMA_CFG &= ~0x1; } while(0)

// RDMA register mode
#define IMGDMA_RDMA_REGISTER_MODE() \
  do { REG_IMGDMA_RDMA_CFG &= ~0x80; } while(0)

// RDMA descriptor mode
#define IMGDMA_RDMA_DESCRIPTOR_MODE() \
  do { REG_IMGDMA_RDMA_CFG |= 0x80; } while(0)

// WARNING: choose only one from below three when RDMA not enabled
// Bypass
#define IMGDMA_RDMA_BYPASS_MODE() \
    do { REG_IMGDMA_RDMA_IN_SEL = 0x8000; } while(0)

// Stall
#define IMGDMA_RDMA_STALL_PREV_ENGINE_MODE() \
    do { REG_IMGDMA_RDMA_IN_SEL = 0x0; } while(0)

// Drop
#define IMGDMA_RDMA_DROP_PREV_ENGINE_MODE() \
    do { REG_IMGDMA_RDMA_IN_SEL = 0x1; } while(0)

// WARNING: choose one from below two when RDMA enabled
// From memory
#define IMGDMA_RDMA_IN_SEL_FROM_MEMORY() \
    do { REG_IMGDMA_RDMA_IN_SEL = 0x0; } while(0)

// If set to YUV format, SW needs to set VH, UH, YH, VV, UV, and YV
#define IMGDMA_RDMA_SET_INPUT_FORMAT(format) \
    do { REG_IMGDMA_RDMA_CON = \
        ((REG_IMGDMA_RDMA_CON & (~IMGDMA_RDMA_CON_INPUT_FORMAT_MASK)) | (format)); } while(0)

// RGB rounding
#define IMGDMA_RDMA_RGB_ROUND_ENABLE() \
    do { REG_IMGDMA_RDMA_CON |= IMGDMA_RDMA_CON_ROUND_BIT; } while(0)

#define IMGDMA_RDMA_RGB_ROUND_DISABLE() \
    do { REG_IMGDMA_RDMA_CON &= ~IMGDMA_RDMA_CON_ROUND_BIT; } while(0)

// YUV format setting
#define IMGDMA_RDMA_SET_INPUT_YUV444() \
    do { REG_IMGDMA_RDMA_CON = \
        ((REG_IMGDMA_RDMA_CON & (~0x0fff000f)) | 0x05550005); } while(0)

#define IMGDMA_RDMA_SET_INPUT_YUV422() \
    do { REG_IMGDMA_RDMA_CON = \
        ((REG_IMGDMA_RDMA_CON & (~0x0fff000f)) | 0x05690005); } while(0)

#define IMGDMA_RDMA_SET_INPUT_YUV420() \
    do { REG_IMGDMA_RDMA_CON = \
        ((REG_IMGDMA_RDMA_CON & (~0x0fff000f)) | 0x0a690005); } while(0)

#define IMGDMA_RDMA_SET_INPUT_YUV411() \
    do { REG_IMGDMA_RDMA_CON = \
        ((REG_IMGDMA_RDMA_CON & (~0x0fff000f)) | 0x057d0005); } while(0)

#define IMGDMA_RDMA_SET_INPUT_YUV400() \
    do { REG_IMGDMA_RDMA_CON = \
        ((REG_IMGDMA_RDMA_CON & (~0x0fff000f)) | 0x00410005); } while(0)

// swap setting
#define IMGDMA_RDMA_BYTE_SWAP_ENABLE() \
    do { REG_IMGDMA_RDMA_CON |= IMGDMA_RDMA_BYTE_SWAP_BIT; } while(0)
		  
#define IMGDMA_RDMA_BYTE_SWAP_DISABLE() \
    do { REG_IMGDMA_RDMA_CON &= ~IMGDMA_RDMA_BYTE_SWAP_BIT; } while(0)
		
#define IMGDMA_RDMA_RGB_SWAP_ENABLE() \
    do { REG_IMGDMA_RDMA_CON |= IMGDMA_RDMA_RGB_SWAP_BIT; } while(0)
			  
#define IMGDMA_RDMA_RGB_SWAP_DISABLE() \
    do { REG_IMGDMA_RDMA_CON &= ~IMGDMA_RDMA_RGB_SWAP_BIT; } while(0)

//#define IMGDMA_RDMA_CLEAR_RPTR() \
//    do { REG_IMGDMA_RDMA_QUEUE_RSTA = \
//        (REG_IMGDMA_RDMA_QUEUE_RSTA & 0xffffe0ff); } while(0)

//Add descriptor mode command
#define IMGDMA_RDMA_SET_QUEUE_BASE_ADDR(n) \
    do {REG_IMGDMA_RDMA_QUEUE_BASE= (n); } while(0)

#define IMGDMA_RDMA_PUSH_QUEUE_DATA(n)   \
    do {while(0x0 == (REG_IMGDMA_RDMA_QUEUE_WSTA&0x1)) {} \
		REG_IMGDMA_RDMA_QUEUE_DATA= (n); } while(0)

// bad macro, it means
// KAL_TRUE : Not busy, KAL_FLASE : Busy
#define IMGDMA_RDMA_IS_QUEUE_WRITE_BUSY() \
    (((REG_IMGDMA_RDMA_QUEUE_WSTA&0x1)==1) ? KAL_TRUE : KAL_FALSE)	

#define IMGDMA_RDMA_SET_DESCIPTOR_SEG(n)   \
    do {REG_IMGDMA_RDMA_CFG = \
        (REG_IMGDMA_RDMA_CFG | (n&IMGDMA_RDMA_SEG_MASK)); } while(0)

#define IMGDMA_RDMA_SET_QUEUE_DEPTH(depth) \
    do { REG_IMGDMA_RDMA_CFG = \
        ((REG_IMGDMA_RDMA_CFG & ~IMGDMA_RDMA_CFG_QUEUEDEPTH_MASK) | \
         (IMGDMA_RDMA_CFG_QUEUEDEPTH_MASK & ((depth) << 8))); } while(0)

#define IMGDMA_RDMA_QUEUE_EMPTY_DROP() \
    do { REG_IMGDMA_RDMA_CFG |= 0x00008000; } while(0)

#define IMGDMA_RDMA_QUEUE_EMPTY_STALL() \
    do { REG_IMGDMA_RDMA_CFG &= ~0x00008000; } while(0)


typedef struct 
{   idp_module_enum_t         output_dst;
    kal_bool                  descriptor_mode;   /**< KAL_TRUE for descriptor mode, KAL_FALSE for register mode (default). */
    kal_uint8                 queue_depth; 
    kal_bool                  bypass;
    kal_bool                  stall_prev_engine;
    kal_bool                  drop_prev_engine;
    kal_bool                  auto_loop;         /**< auto loop */
    kal_bool                  frame_sync_en;
    kal_bool                  rgb_rounding;      /**< enable RGB rounding, only use when KAL_TRUE == output_rgb */
    kal_bool                  bByteSwap;
    kal_bool                  bRGBSwap;
    
    /* Configs for register mode. */
    kal_bool                  input_rgb;         /**< KAL_TRUE, SW only examine rgb_color_fmt */
    img_color_fmt_rgb_enum_t  rgb_color_fmt;     /**< 0, using YUV format. Cannot be 0 when yuv_color_fmt is 0. */
    img_color_fmt_yuv_enum_t  yuv_color_fmt;     /**< 0, using RGB format. Cannot be 0 when rgb_color_fmt is 0. */
    
    kal_uint32                y_base_addr;       /**< y base address */
    kal_uint32                u_base_addr;       /**< u base address */
    kal_uint32                v_base_addr;       /**< v base address */
    
    kal_uint32                pixel_number;      /**< pixel numbers. deprecated? */
    kal_uint16                source_width;      /**< 16 bit unsigned. */
    kal_uint16                source_height;     /**< 16 bit unsigned. */

    //kal_bool                  pitch_enable;      /**< pitch */
    //kal_uint16                pitch_bytes;       /**< horizontal pitch WARNING! the pitch is applied to three buffers */ 

    kal_uint16                bus_control_threshold;
    
    kal_bool                  clip;              /**< clip enable, this was called "pan" in MT6238 */
    kal_uint16                clip_left;         /**< start from 0. */
    kal_uint16                clip_right;        /**< max. value: (source width) - 1. */
    kal_uint16                clip_top;          /**< start from 0. */
    kal_uint16                clip_bottom;       /**< max. value: (source height) - 1. */

    /* Common config for both descriptor and register modes. */
    kal_bool                  intr_en;           /**< interrupt enable. */
    idp_lisr_intr_cb_t        intr_cb;           /**< interrupt callback function pointer. */
    idp_lisr_intr_cb_param_t  intr_cb_param;     /**< interrupt callback function param. */

    /* private section, client must not modify below members. */
    kal_uint32                _y_str_addr;
    kal_uint32                _u_str_addr;
    kal_uint32                _v_str_addr;
    kal_uint8                 _yh;
    kal_uint8                 _yv;
    kal_uint8                 _uh;
    kal_uint8                 _uv;
    kal_uint8                 _vh;
    kal_uint8                 _vv;
}idp_imgdma_rdma_struct;

typedef idp_imgdma_rdma_struct idp_imgdma_rdma_struct;


extern void *idp_imgdma_rdma_intr_cb_param;
extern void (*idp_imgdma_rdma_intr_cb)(void *);

extern kal_bool 
idp_imgdma_rdma_config_real(
    idp_imgdma_rdma_struct * const rdma0_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_imgdma_rdma_get_working_mem_real(
    kal_bool const use_internal_mem,
    idp_imgdma_rdma_struct const * const rdma0_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);

extern kal_bool
idp_imgdma_rdma_start_real(
  idp_imgdma_rdma_struct const * const p_rdma0_struct);

extern kal_bool
idp_imgdma_rdma_stop_real(
  idp_imgdma_rdma_struct const * const p_rdma0_struct);

extern void
idp_imgdma_rdma_open_real(void);

extern void
idp_imgdma_RDMA_queue_push(kal_uint32 const data);

extern void
idp_imgdma_RDMA_set_queue_depth(kal_uint32 const data);

extern void
idp_imgdma_RDMA_set_queue_base_addr(kal_uint32 const data);

extern void
idp_imgdma_RDMA_set_queue_segs(kal_uint32 const data);

extern void
idp_imgdma_RDMA_enable_descriptor_mode(kal_bool enable);

extern void
idp_imgdma_RDMA_queue_empty_drop(kal_bool enable);

IDP_HW_COMMON_API_DECLARATION(imgdma_rdma)

#endif // #if defined(DRV_IDP_MT6256_E2_SERIES)
#endif // __idp_imgdma_rdma_mt6256_e2_h__

