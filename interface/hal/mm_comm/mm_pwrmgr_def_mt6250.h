/****************************************************************************
 * =================6250=================
 * LCD
 * RESIZER
 * ROTDMA
 * CAM_BCLK
 * PAD2CAM
 * G2D
 * HJPG
 * LCD104M
 * LCD
 ****************************************************************************/ 


/****************************************************************************
 * We will use X_MMPWRMGR_USER to produce valid mm engine enum in specific chip.
 ****************************************************************************/ 
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
/****************************************************************************
 * 1. Check hal\system\pdn\inc\pdn_hw_mt6250_series.h 
 *    (1) status register name (ex. DRVPDN_CON0 (CONFIG_base+0x0300))
 *    (2) set register name (ex. DRVPDN_CON0_SET (CONFIG_base+0x0310))
 *    (3) clear register name (ex. DRVPDN_CON0_CLR (CONFIG_base+0x0320))
 *    (4) bit mask (ex. DRVPDN_CON0_LCD 0x0080)
 * 2. Add PAD2CAM SLCD CAM48
 ****************************************************************************/ 
X_MMPWRMGR_USER(LCD     , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_LCD        , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_USER(RESZ    , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_RESIZER    , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_USER(ROTDMA  , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_ROTDMA     , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_USER(ISP     , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_CAM_BCLK   , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_USER(PAD2CAM , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_PAD2CAM    , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_USER(G2D     , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_G2D        , MMPWRMGR_OPT_32BIT_REG)
#if defined(MT6250)
X_MMPWRMGR_USER(DCT     , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_HJPG       , MMPWRMGR_OPT_32BIT_REG)
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
X_MMPWRMGR_USER(MM_COLOR, DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_MM_COLOR   , MMPWRMGR_OPT_32BIT_REG)
#endif
X_MMPWRMGR_USER(SLCD    , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_SLCD       , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_USER(CAM48   , DRVPDN_MCUSYS_PDN_CON0, DRVPDN_MCUSYS_PDN_CON0_SET, DRVPDN_MCUSYS_PDN_CON0_CLR, DRVPDN_CON0_SW_CAM_48M    , MMPWRMGR_OPT_32BIT_REG)
/****************************************************************************
 * The MM_PWRMGR_MAX_DEV will control the array¡¦s size.
 ****************************************************************************/ 
X_MMPWRMGR_DUMMY(MAX_DEV        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)

/****************************************************************************
 * Use X_MMPWRMGR_DUMMY to produce dummy mm engine list enum in specific chip 
 * to achieve chip-independent.
 ****************************************************************************/ 
X_MMPWRMGR_DUMMY(CAM104M        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(LCD104M        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(BRZ            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(BS_DMA         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(CSI2           , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(JPEG           , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(DRZ            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(GCMQ           , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(GFX_ROT        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(GIF            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(GMC            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(GMCI           , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(GMC_INIT       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(GMC_INT        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(GOVL           , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(H264           , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(HIF            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IMGDMA         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IMGPROC        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IMG_MIMO       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IMG_MOUT0      , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IMG_MOUT1      , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IMG_MOUT2      , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IMG_MOUT3      , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IMG_MULTI_OUT  , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IPP            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(IT_DMA         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(JPEG_DEC       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(JPEG_DMA       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(JPEG_ENC       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(MMLMU          , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(MP4            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(MP4_DEBLK      , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(OVL            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(OVL_BPS        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(PNG            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(PRZ            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(RESZ_LB        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(RGB_ROT0       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(RGB_ROT1       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(ROT_DMA0       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(ROT_DMA1       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(ROT_DMA2       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(ROT_DMA3       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(RXBRP          , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(R_DMA          , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(R_DMA0         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(R_DMA1         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(R_DMA1_BPS     , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(R_DMA_BPS      , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(SCAM           , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(SPI            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(SYSRAM         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(TD_DMA         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(TVC            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(VDO_ROT        , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(VENC_MP4       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(VRZ            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(W_DMA0         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(W_DMA0_BPS     , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(W_DMA1         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(W_DMA1_BPS     , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
X_MMPWRMGR_DUMMY(W_DMA2         , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
#if defined(MT6250)
X_MMPWRMGR_DUMMY(MM_COLOR       , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
X_MMPWRMGR_DUMMY(DCT            , 0, 0, 0, 0      , MMPWRMGR_OPT_32BIT_REG)
#endif


#endif // defined(MT6250)

