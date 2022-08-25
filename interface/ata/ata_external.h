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
* ABM_COMMON_API.H
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file contains the message handler of ABM.
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
 *
 * removed!
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef __ATA_EXTERNAL_H
#define __ATA_EXTERNAL_H

#define COMMAND_LINE_SIZE    (180)
#define NULL_TERMINATOR_LENGTH (1)
#define MAX_UART_LEN	128 
	
 	
typedef enum
{
	CUSTOM_RSP_ERROR = -1,
	CUSTOM_RSP_OK = 0,
	CUSTOM_RSP_LATER //add by aihua
} custom_rsp_type_enum;
	
	
typedef struct 
{
	short  position;
	short  length;
	char   character[COMMAND_LINE_SIZE + NULL_TERMINATOR_LENGTH];
} custom_cmdLine;
	
	
typedef enum
{
	CUSTOM_WRONG_MODE,
	CUSTOM_SET_OR_EXECUTE_MODE,
	CUSTOM_READ_MODE,
	CUSTOM_TEST_MODE,
	CUSTOM_ACTIVE_MODE
} custom_cmd_mode_enum;


extern custom_cmd_mode_enum custom_find_cmd_mode(custom_cmdLine *cmd_line);
extern void rmmi_write_to_uart(kal_uint8 * buffer, kal_uint16 length, kal_bool stuff); 


#if defined(__ATA_SUPPORT__) && defined(__MTK_TARGET__)
#if defined(TOUCH_PANEL_SUPPORT) && defined(TOUCH_PANEL_INTERNAL)
extern custom_rsp_type_enum ata_tp_hdlr_v1(custom_cmdLine *commandBuffer_p);    
#endif

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__)|| defined(__MSDC_MSPRO__)) || defined(__MSDC_SD_SDIO)
extern custom_rsp_type_enum ata_t_card_hdlr_v1(custom_cmdLine *commandBuffer_p);  
#endif

extern custom_rsp_type_enum ata_vibrator_hdlr_v1(custom_cmdLine *commandBuffer_p);  

#if (defined(FM_RADIO_ENABLE))	
extern custom_rsp_type_enum ata_fm_hdlr_v1(custom_cmdLine *commandBuffer_p); 
#endif

#if defined(__ATV_SUPPORT__)
extern custom_rsp_type_enum ata_matv_hdlr_v1(custom_cmdLine * commandBuffer_p);
extern custom_rsp_type_enum ata_matv_video_hdlr_v1(custom_cmdLine * commandBuffer_p);
#endif

#if defined(__CUST_NEW__)
extern custom_rsp_type_enum ata_kpt_hdlr_v1(custom_cmdLine * commandBuffer_p);
#endif


#if defined(ISP_SUPPORT)
extern custom_rsp_type_enum ata_camera_hdlr_v1(custom_cmdLine *commandBuffer_p);
#endif

extern custom_rsp_type_enum ata_audio_hdlr_v1(custom_cmdLine *commandBuffer_p); 
extern custom_rsp_type_enum ata_lcm_hdlr(custom_cmdLine *commandBuffer_p);
extern custom_rsp_type_enum ata_led_hdlr(custom_cmdLine *commandBuffer_p);
extern custom_rsp_type_enum ata_led_tsem_hdlr(custom_cmdLine * commandBuffer_p);
extern custom_rsp_type_enum ata_led_gsem_hdlr(custom_cmdLine * commandBuffer_p);
extern custom_rsp_type_enum ata_bkl_hdlr(custom_cmdLine * commandBuffer_p);

#endif/*__ATA_SUPPORT__ && __MTK_TARGET__*/
#endif
