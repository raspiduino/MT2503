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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * mp4_common.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Common Definitions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#ifndef __MP4_COMMON_H__
#define __MP4_COMMON_H__

#include "mpl_common.h"

#define MP4_BRAND_3GP5 0x33677035
#define MP4_BRAND_3GP6 0x33677036

#define BOX_TYPE_FTYP 0x66747970
#define BOX_TYPE_MOOV 0x6D6F6F76
#define BOX_TYPE_META 0x6D657461
#define BOX_TYPE_IPRO 0x6970726F
#define BOX_TYPE_SINF 0x73696E66
#define BOX_TYPE_SCHI 0x73636869
#define BOX_TYPE_ODKM 0x6F646B6D
#define BOX_TYPE_OHDR 0x6F686472
#define BOX_TYPE_MVHD 0x6D766864
#define BOX_TYPE_TRAK 0x7472616B
#define BOX_TYPE_UDTA 0x75647461
#define BOX_TYPE_TKHD 0x746B6864
#define BOX_TYPE_MDIA 0x6D646961
#define BOX_TYPE_MDHD 0x6D646864
#define BOX_TYPE_HDLR 0x68646C72
#define BOX_TYPE_MINF 0x6D696E66
#define BOX_TYPE_SMHD 0x736d6864
#define BOX_TYPE_DINF 0x64696E66
#define BOX_TYPE_DREF 0x64726566
#define BOX_TYPE_URL  0x75726C20
#define BOX_TYPE_STBL 0x7374626C
#define BOX_TYPE_STSD 0x73747364
#define BOX_TYPE_STTS 0x73747473
#define BOX_TYPE_STSC 0x73747363
#define BOX_TYPE_STSZ 0x7374737A
#define BOX_TYPE_STCO 0x7374636F
#define BOX_TYPE_STSS 0x73747373
#define BOX_TYPE_CTTS 0x63747473
#define BOX_TYPE_ESDS 0x65736473
#define BOX_TYPE_DAMR 0x64616D72
#define BOX_TYPE_D263 0x64323633
#define BOX_TYPE_BITR 0x62697472
#define BOX_TYPE_MDAT 0x6D646174
#define BOX_TYPE_FREE 0x66726565
#define BOX_TYPE_CO64 0x636F3634 // Pibben for 64 bit
#define BOX_TYPE_WAVE 0x77617665 // Pibben for MP4A extension atom
#define BOX_TYPE_STCO_CAP 0x5354434F
#define BOX_TYPE_STSZ_CAP 0x5354535A
#define BOX_TYPE_KM4V 0x6B6D3476

/* ===========   UDTA Box name =========== */
#define BOX_TYPE_TITL 0x7469746C  // title
#define BOX_TYPE_AUTH 0x61757468  // author
#define BOX_TYPE_CPRT 0x63707274  // Copyright
#define BOX_TYPE_YRRC 0x79727263  // year
#define BOX_TYPE_ALBM 0x616C626D  // album

/* ===========   iTunes/iPod Container Box in UDTA Box name =========== */
#define BOX_TYPE_ILST 0x696C7374  // iTunes/iPod Container Box
#define BOX_TYPE_UUID 0x75756964
#define BOX_TYPE_NAM  0xA96E616D  // Name of the title
#define BOX_TYPE_ART  0xA9415254  // Name of the artist
#define BOX_TYPE_ALB  0xA9616C62  // Name of the album
#define BOX_TYPE_AUT  0xA9777274  // Name of the composer, author
#define BOX_TYPE_GNRE 0x676E7265  // Genre
#define BOX_TYPE_CPY  0xA9637079  // Copyright
#define BOX_TYPE_DAY  0xA9646179  // Year of publication
#define BOX_TYPE_TRKN 0x74726B6E  // Track number

#define BOX_TYPE_GEN  0xA967656E  // Genre
#define BOX_TYPE_DESC 0x64657363  // description
#define BOX_TYPE_CMT  0xA9636D74  // comment
#define BOX_TYPE_TOO  0xA9746F6F  // Encoder
#define BOX_TYPE_aART 0x61415254  // album artist
#define BOX_TYPE_LYR  0xA96C7972  // lyrics
#define BOX_TYPE_GRP  0xA9677270  // grouping
#define BOX_TYPE_CATG 0x63617467  // category
#define BOX_TYPE_COVR 0x636F7672  // Artwork
#define BOX_TYPE_JPG  0x0000000D  // thumbnail JPEG
#define BOX_TYPE_PNG  0x0000000E  // thumbnail PNG
#define BOX_TYPE_PERF 0x70657266  // performer name

#define BOX_TYPE_ENCV 0x656E6376
#define BOX_TYPE_ENCA 0x656E6361

#define HDLR_TYPE_VIDE 0x76696465
#define HDLR_TYPE_SOUN 0x736F756E

#define SAMPLE_FMT_MP4V 0x6D703476
#define SAMPLE_FMT_MP4A 0x6D703461
#define SAMPLE_FMT_SAMR 0x73616D72
#define SAMPLE_FMT_SAWB 0x73617762
#define SAMPLE_FMT_S263 0x73323633
#define SAMPLE_FMT_AVC1 0x61766331
#define SAMPLE_FMT_AVCC 0x61766343
#define SAMPLE_FMT_ENCA 0x656e6361
#define SAMPLE_FMT_ENCV 0x656e6376
#define SAMPLE_FMT_JPEG 0x6A706567
#define SAMPLE_FMT_MP3  0X2E6D7033

/*  dior add for Progressive download, MP4_IsPDProfile()  */
#define MAJOR_BRAND_3gr6  0x36726733   //6rg3
#define MAJOR_BRAND_3gp6  0x36706733   //6pg3
#define MAJOR_BRAND_3gp5  0x35706733   //5pg3
#define MAJOR_BRAND_3gp4  0x34706733   //4pg3
#define MAJOR_BRAND_isom  0x6d6f7369   //mosi

#ifdef __VE_PRIRATE_3D_FORMAT__
#define BOX_TYPE_TRAK_CAP 0x5452414B
#endif

#define BOX_TYPE_IUAM 0x4955414D
#define BOX_TYPE_TRNS 0x54524E53

#define MP4_RESERVED_TRACK_NO 0xFF

#define ADTS_HEADER_SIZE 7
/*
 * 63+4+2+4+4+4+4+2+3+4+1+4+1+4+1+2+1+16*5*3+16*4*2+16*5 = 556
 * (556+7)/8 = 70 (byte_alignment)
 * 70 + 1 (comment_field_bytes) = 71
 */
#define ADIF_HEADER_SIZE 63

#endif

