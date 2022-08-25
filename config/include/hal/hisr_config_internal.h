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
 *   hisr_config_internal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the HISR config parameter
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

           /*NO. Enum_Name  Name       priority     stack_size       callback_function     INT/EXT RAM*/
#if defined(__MTK_TARGET__)
X_HISR_CONST(1,   DRVHISR,   "DRVHISR", 1,           1024,            DRV_HISR,             KAL_FALSE)
#endif
X_HISR_MOD(1, MOD_DRV_HISR)

#if defined(__MTK_TARGET__) \
       && (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) || defined(__HW_G2D_SUPPORT__) || defined(__HW_GIF_SUPPORT__) \
       || defined(__JPEG_HW_SUPPORTED__) || defined(__PNG_HW_SUPPORTED)) || defined(__MALI400MP_OPENGLES_HW_SUPPORT__)
X_HISR_CONST(2,   GFXHISR,   "GFXHISR", 1, 1024, drv_gfx_hisr_entry, KAL_TRUE)
X_HISR_MOD(2, MOD_GFXHISR)
#endif

#if defined(__IRDA_SUPPORT__)
X_HISR_CONST(7,   IRDA_HISR,   "IRDA_HISR",1,1024,IR_HISR,KAL_FALSE)
#endif
X_HISR_MOD(7, MOD_IRDA_HISR)

#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__) && !defined(__MEUT__)
#if defined(MT6253E) || defined(MT6253L) \
|| defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) \
|| defined(MT6261) || defined(MT2501) || defined(MT2502)
X_HISR_CONST(8,   L1AUDIO_HISR,   "L1Audio_HISR", 1, 768, L1Audio_HISR, KAL_TRUE)
#else
X_HISR_CONST(8,   L1AUDIO_HISR,   "L1Audio_HISR", 1, 768, L1Audio_HISR, KAL_FALSE)
#endif
#endif
X_HISR_MOD(8, MOD_L1SPHISR)

#if defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__)
#if defined(MT6253E) || defined(MT6253L) \
|| defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) \
|| defined(MT6261) || defined(MT2501) || defined(MT2502)
X_HISR_CONST(10,   L1_HISR,   "L1_HISR", 0, 512+256, L1I_WakeTask, KAL_TRUE)
#else
X_HISR_CONST(10,   L1_HISR,   "L1_HISR", 0, 512+256, L1I_WakeTask, KAL_FALSE)
#endif
#endif
X_HISR_MOD(10, MOD_L1HISR)

#if defined(__MTK_TARGET__) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) && !defined(MT6251)
X_HISR_CONST(11,   VISUHISR,   "VISUHISR",1,1024,VISUAL_HISR,KAL_FALSE)
#endif
X_HISR_MOD(11, MOD_VISUAL_HISR)

#if !defined(__MTK_TARGET__)
X_HISR_CONST(13,   UARTHISR,   "UART_HISR", 2, 512,UART_HISR,KAL_FALSE)
X_HISR_MOD(13, MOD_UARTHISR)
#endif

#if !defined(__MTK_TARGET__) && defined(PLUTO_MMI)
X_HISR_CONST(14,   MTE_TO_MMI_HISR,   "MTE_TO_MMI_HISR", 0, 1024, mte_to_mmi_hisr, KAL_FALSE)
X_HISR_MOD(14, MOD_MTE_TO_MMI_HISR)
#endif

#if defined(__UMTS_RAT__) && !defined(__MAUI_BASIC__) && !defined(__MEUT__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
#endif

#if (defined(__LOGACC_ENABLE__) || defined(__TST_DNT_LOGGING__)) && !defined(__MAUI_BASIC__) && !defined(__MEUT__) && defined(__MTK_TARGET__)
X_HISR_CONST(16,   LGAHISR,   "LGA_HISR",2,1024,Lga_HisrEntry,KAL_TRUE)
X_HISR_MOD(16, MOD_LGAHISR)
#endif

#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
#endif

#if defined(MT6268A) && defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MTK_TARGET__)
#if defined(__NUCLEUS_VERSION_2__)
X_HISR_CONST(19,   TIMER_HISR,   "TIMER_HISR", 2, 768, TMC_Timer_HISR, KAL_FALSE)
#else
X_HISR_CONST(19,   TIMER_HISR,   "TIMER_HISR", 2, 512, TMC_Timer_HISR, KAL_FALSE)
#endif /* __NUCLEUS_VERSION_2__ */
#else
X_HISR_CONST(19,   TIMER_HISR,   "TIMER_HISR", 2, 1024, OSC_Timer_HISR, KAL_FALSE)
#endif
X_HISR_MOD(19, MOD_TIMER_HISR)

#if defined(__UL1_HS_PLATFORM__) && defined(__UMTS_FDD_MODE__) && defined(__MTK_TARGET__)
X_HISR_CONST(20,   UL1D_REAL_HISR,   "UL1D_REAL_HISR", 0, 1024, UL1D_RealHISR, KAL_FALSE)
X_HISR_MOD(20, MOD_UL1_LOW_HISR)

X_HISR_CONST(21,   UL2HISR,   "UL2HISR", 0, 2048, UL1D_UL2HISR, KAL_FALSE)
X_HISR_MOD(21, MOD_UUL2HISR)
#endif

#if defined(__RLC_HSDPA_COPRO__) && defined(__UL2_ACC_TEST_FPGA__)
X_HISR_CONST(22, UL2ACCFINT_HISR, "UL2ACCFINT_HISR", 2, 512, UL2_ACC_FINT_HISR, KAL_TRUE)
X_HISR_MOD(22, MOD_UL2ACCFINT_HISR)
#endif

#if defined(__RLC_HSDPA_COPRO__) && defined(__MTK_TARGET__)
X_HISR_CONST(23,   UL2SEQ_HISR, "UL2SEQ_HISR", 1, 1024, seq_isr_hisr, KAL_TRUE)
#endif
#ifdef  __UMTS_RAT__
/* under construction !*/
#endif /* __UMTS_RAT__ */

#if defined(__HSDPA_SUPPORT__) && defined(__MTK_TARGET__) && !defined(__L1_STANDALONE__) && defined(__UMTS_FDD_MODE__)
X_HISR_CONST(24,   UL2BCP_HISR,   "UL2BCP_HISR", 1, 512, bcp_isr_hisr, KAL_TRUE)
X_HISR_MOD(24, MOD_UL2BCP_HISR)
#endif

#if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
X_HISR_CONST(25, TL1_HISR, "TL1_HISR", 0, 760, tl1_m_h_entry, KAL_FALSE)
X_HISR_MOD(25, MOD_TL1HISR)
#endif
#if defined(__MTK_TARGET__) && defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
X_HISR_CONST(26, HIF_CB_HISR, "HIF_CB_HISR", 0, 1000, ast_hif_cb_hisr, KAL_TRUE)
X_HISR_MOD(26, MOD_HIF_CB_HISR)
#endif

#if defined(__MODIS_PLUGIN__)
X_HISR_CONST(27, MODIS_PLUGIN, "MODIS_PLUGIN", 2, 1024, plugin_hisr, KAL_FALSE)
X_HISR_MOD(27, MOD_PLUGIN_HISR)
#endif

#if defined(__MAUI_SDK_TEST__)
X_HISR_CONST(28, VS_HISR, "VS_HISR", 2, 512, vs_sys_eg_001_hisrEntry, KAL_FALSE)
X_HISR_MOD(28, MOD_VS_HISR)
#endif

#if defined(__TINY_SYS__)
X_HISR_CONST(29, TINY_HISR,   "TINY_HISR", 2, 1024, tiny_hisr_handler, KAL_TRUE)
X_HISR_MOD(29, MOD_TINY_HISR)
#endif

