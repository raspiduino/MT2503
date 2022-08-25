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
 *  BT_SCO_drv.h
 *
 * Project:
 * --------
 *  Maui_sw
 *
 * Description:
 * ------------
 *  BT SCO driver header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BT_SCO_DRV_H
#define __BT_SCO_DRV_H

#include "postprocess.h"
#include "common_def.h"

//#define __CVSD_LOOPBACK_TEST__
//#define __CVSD_BT_FORCE_READBACK__

extern void *audio_alloc_ext_mem_simplified(kal_uint32 size);
extern void *audio_alloc_ext_mem_cacheable_simplified(kal_uint32 size);
extern void audio_free_ext_mem_simplified(void *ptr);

// PLC Interface
extern kal_int32 g711plc_GetMemorySize();
extern void g711plc_construct(void *lc);
extern void g711plc_addtohistory(void *lc, kal_int16 *s);
extern void g711plc_dofe(void *lc,kal_int16 *out);

// BT Interrupt
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
#define BT_EINT 29
#else
#define BT_EINT 15
#endif

// BT HW Register address

#define BTSRAM_BASE                (0xA3000000)
#define BTPKT_BASE                 (0xA3340000)
#define BT_SCO_HW_REG_PACKET_R     ((volatile kal_uint32*)(BTPKT_BASE+0x0FD0))
#define BT_SCO_HW_REG_PACKET_W     ((volatile kal_uint32*)(BTPKT_BASE+0x0FD4))
#define BT_SCO_HW_REG_CONTROL      ((volatile kal_uint32*)(BTPKT_BASE+0x0FD8))

#define BT_POWER_OFF               ((volatile kal_uint16*)(0xA0700170))
#define BT_POWER_OFF_MASK          (0x2)

#define BT_SCO_PACKET_120 120
#define BT_SCO_PACKET_180 180

#define BT_CVSD_TX_NREADY    (1<<21)
#define BT_CVSD_RX_READY     (1<<22)
#define BT_CVSD_TX_UNDERFLOW (1<<23)
#define BT_CVSD_RX_OVERFLOW  (1<<24)
#define BT_CVSD_INTERRUPT    (1<<31)

#define BT_CVSD_CLEAR        (BT_CVSD_TX_NREADY | BT_CVSD_RX_READY | BT_CVSD_TX_UNDERFLOW | BT_CVSD_RX_OVERFLOW | BT_CVSD_INTERRUPT)

//TX 
#define SCO_TX_ENCODE_SIZE           (60                             ) // 60 byte (60*8 samples)
#define SCO_TX_PACKER_BUF_NUM        (8                              ) 
#define SCO_TX_PACKET_MASK           (0x7                            )
#define SCO_TX_PCM64K_BUF_SIZE       (SCO_TX_ENCODE_SIZE*2*8         ) // 60 * 2 * 8 byte
#define SCO_TX_RINGBUFFER_SIZE       (APM_OUT_BUFNUM*APM_OUT_BUFSIZE )

//RX
#define SCO_RX_PLC_SIZE              (30                    ) 
#define SCO_RX_PACKER_BUF_NUM        (16                    ) 
#define SCO_RX_PACKET_MASK           (0xF                   )
#define SCO_RX_PCM64K_BUF_SIZE       (SCO_RX_PLC_SIZE*2*8   ) 
#define SCO_RX_PCM8K_BUF_SIZE        (SCO_RX_PLC_SIZE*2     ) 
#define SCO_RX_RINGBUFFER_SIZE       (1024*8                ) 
#define SCO_TX_PACKER_BUF_NUM        (8                     ) 

#define SCORX_BT_CVSD_RX_PACKET_BUFFER_LEN (BT_CVSD_BLOCKSIZE * 6) // 360 byte

typedef enum {
  BT_SCO_STATE_IDLE=0,
  BT_SCO_STATE_INIT,
  BT_SCO_STATE_READY,
  BT_SCO_STATE_RUNNING,
  BT_SCO_STATE_ENDING,
} BT_SCO_STATE;

typedef enum {
  BT_SCO_MODE_CVSD,
  BT_SCO_MODE_MSBC
} BT_SCO_MODE;

typedef enum {
  BT_SCO_LINK_TX_ONLY,
  BT_SCO_LINK_RX_ONLY,
  BT_SCO_LINK_BOTH,
} BT_SCO_LINK;

typedef enum {
  BT_SCO_MOD_CVSD_ENCODE,
  BT_SCO_MOD_CVSD_DECODE,
  BT_SCO_MOD_FILTER_TX,
  BT_SCO_MOD_FILTER_RX,
  BT_SCO_MOD_PLC,
  BT_SCO_MOD_CVSD_TX_SRC,
  BT_SCO_MOD_CVSD_RX_SRC1,
  BT_SCO_MOD_CVSD_RX_SRC2,
  BT_SCO_MOD_PCM_RINGBUF_TX,
  BT_SCO_MOD_PCM_RINGBUF_RX,
} BT_SCO_MODULE;

typedef enum {
  BT_SCO_DIRECT_BT2ARM,
  BT_SCO_DIRECT_ARM2BT
} BT_SCO_DIRECT;

typedef enum {
  BT_SCO_CVSD_30 =0,
  BT_SCO_CVSD_60 =1,
  BT_SCO_CVSD_90 =2,
  BT_SCO_CVSD_120=3,
  BT_SCO_CVSD_10 =4,
  BT_SCO_CVSD_20 =5,
  BT_SCO_CVSD_MAX=6
} BT_SCO_PACKET_LEN;

typedef struct {
   void          *pSRCHandle;
   void          *pEncHandle;
   void          *pHPFHandle;

   void          (*pCallback)( void *pData );
   void          *pUserData;

   kal_uint16    uSampleRate;
   kal_uint8     uChannelNumber;

   kal_bool      fEnableFilter;
   kal_bool      fEnablePLC;
   AUD_RB_INFO   RingBuffer;

   //bitstream buffer
   kal_uint8     PacketBuf[SCO_TX_PACKER_BUF_NUM][SCO_TX_ENCODE_SIZE];
   kal_uint32    iPacket_w;        
   kal_uint32    iPacket_r; 
   kal_uint8     PcmBuf_64k[SCO_TX_PCM64K_BUF_SIZE];
#if defined(__DISABLE_ARBITRARY_BLISRC__) || defined(__DISABLE_BLISRC__)
   kal_uint8     PcmBuf_32k[SCO_TX_PCM64K_BUF_SIZE/2];
   kal_int16     pSrcPreSample[22];     //for 32K ->64K
#endif
   kal_uint32    uPcmBuf_w;
   kal_bool      fUnderflow;
} BT_SCO_TX;

typedef struct {
   //handle
   void          *pDecHandle;
   void          *pHPFHandle;
   void          *pPLCHandle;
   void          *pSRCHandle_1;
   void          *pSRCHandle_2;

   //callback
   void          (*pCallback)( void *pData );
   void          *pUserData;

   kal_uint16    uSampleRate;
   kal_uint8     uChannelNumber;
   kal_bool      fEnableSRC2;
   kal_bool      fEnableFilter;
   kal_bool      fEnablePLC;

   //bitstream buffer
   kal_uint8     PacketBuf[SCO_RX_PACKER_BUF_NUM][SCO_RX_PLC_SIZE];
   kal_bool      PacketValid[SCO_RX_PACKER_BUF_NUM];
   kal_uint32    iPacket_w;        
   kal_uint32    iPacket_r;       

   //temp buffer
   kal_uint8     PcmBuf_64k[SCO_RX_PCM64K_BUF_SIZE];
   kal_uint8     PcmBuf_8k[SCO_RX_PCM8K_BUF_SIZE];
#if defined(__DISABLE_BLISRC__)
   kal_uint8     PcmBuf_64k_2[SCO_TX_PCM64K_BUF_SIZE];
   kal_int16     pStack_64K[19];   
   kal_int16     pStack_32K[19];    
   kal_int16     pStack_16K[19];     
#endif
   kal_uint32    uPcmBuf_r; //for PcmBuf_8k
   AUD_RB_INFO   RingBuffer;
   kal_bool      fOverflow;

} BT_SCO_RX;

extern kal_uint32 BT_SCO_CheckByte(BT_SCO_LINK uLink, kal_uint32 uPcmByte);

void BT_SCO_Set_Cordless_On(kal_bool is_cordless_on);
kal_bool BT_SCO_Is_Cordless_On(void);

#endif //__BT_SCO_DRV_H

