#ifndef VCODEC_CUSTOMIZATION_H
#define VCODEC_CUSTOMIZATION_H

#include "vcodec_if.h"


extern const RV9_DEC_CUSTOM_SETTING_T rmvbCustomSetting;
extern const MPEG4_DEC_CUSTOM_SETTING_T MPEG4CustomSetting;
extern const MPEG4VT_DEC_CUSTOM_SETTING_T MPEG4VTCustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264CustomSetting;
extern const VCODEC_ENC_GENERAL_SETTING_T MPEG4EncoderCustomSetting;
extern const VCODEC_ENC_GENERAL_SETTING_T MPEG4VTEncoderCustomSetting;
extern const VCODEC_ENC_GENERAL_SETTING_T H264EncoderCustomSetting;
extern const VP8_DEC_CUSTOM_SETTING_T VP8CustomSetting;

extern const RV9_DEC_CUSTOM_SETTING_T rmvbQVGACustomSetting;
extern const RV9_DEC_CUSTOM_SETTING_T rmvbQVGAMPEG4SPCustomSetting;
extern const RV9_DEC_CUSTOM_SETTING_T rmvbQCIFCustomSetting;
extern const RV9_DEC_CUSTOM_SETTING_T rmvbVGACustomSetting;
extern const RV9_DEC_CUSTOM_SETTING_T rmvbCIFCustomSetting;
extern const RV9_DEC_CUSTOM_SETTING_T rmvbUPTOQVGACustomSetting;
extern const RV9_DEC_CUSTOM_SETTING_T rmvbUPTOCIFCustomSetting;
extern const MPEG4_DEC_CUSTOM_SETTING_T MPEG4QVGACustomSetting;
extern const MPEG4_DEC_CUSTOM_SETTING_T MPEG4QVGAMPEG4SPCustomSetting;
extern const MPEG4_DEC_CUSTOM_SETTING_T MPEG4QCIFCustomSetting;
extern const MPEG4_DEC_CUSTOM_SETTING_T MPEG4VGACustomSetting;
extern const MPEG4_DEC_CUSTOM_SETTING_T MPEG4CIFCustomSetting;
extern const MPEG4_DEC_CUSTOM_SETTING_T MPEG4UPTOQVGACustomSetting;
extern const MPEG4_DEC_CUSTOM_SETTING_T MPEG4UPTOCIFCustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264QVGACustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264QVGAMPEG4SPCustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264QCIFCustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264VGACustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264CIFCustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264UPTOQVGACustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264UPTOCIFCustomSetting;
extern const H264_DEC_CUSTOM_SETTING_T H264PreviewCustomSetting; // MAUI_02955479
extern const VP8_DEC_CUSTOM_SETTING_T VP8QVGACustomSetting;
extern const VP8_DEC_CUSTOM_SETTING_T VP8QVGAMPEG4SPCustomSetting;
extern const VP8_DEC_CUSTOM_SETTING_T VP8QCIFCustomSetting;
extern const VP8_DEC_CUSTOM_SETTING_T VP8VGACustomSetting;
extern const VP8_DEC_CUSTOM_SETTING_T VP8CIFCustomSetting;
extern const VP8_DEC_CUSTOM_SETTING_T VP8UPTOQVGACustomSetting;
extern const VP8_DEC_CUSTOM_SETTING_T VP8UPTOCIFCustomSetting;


extern VCODEC_DEC_API_T *GetH264DecoderAPI(void);
extern VCODEC_DEC_API_T *GetRMDecoderAPI(void);  //RV8,RV9,RV10
extern VCODEC_DEC_API_T *GetMPEG4DecoderAPI(void);
extern VCODEC_DEC_API_T *GetMPEG4VTDecoderAPI(void);
extern VCODEC_DEC_API_T *GetVP8DecoderAPI(void);

extern VCODEC_ENC_API_T *GetMPEG4EncoderAPI(void);
extern VCODEC_ENC_API_T *GetMPEG4SWVTEncoderAPI(void);
extern VCODEC_ENC_API_T *GetH264EncoderAPI(void);

#endif /* VCODEC_CUSTOMIZATION_H */