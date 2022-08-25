
#ifndef __idp_owner_6255_h__
#define __idp_owner_6255_h__

struct idp_hw_owner_t
{
  kal_semid sem;
  kal_uint32 key;
};
typedef struct idp_hw_owner_t idp_hw_owner_t;

/**
 *  Assume this still be project independent at 
 *  the time of porting MT6255 MDP driver
 */
enum idp_scenario_t
{
  IDP_SCENARIO_camera_preview,
  IDP_SCENARIO_camera_preview_with_face_detection,
  IDP_SCENARIO_camera_capture_to_jpeg,
  IDP_SCENARIO_camera_capture_to_mem,
  IDP_SCENARIO_camera_capture_to_barcode,
  IDP_SCENARIO_camera_capture_to_ybuffer,
  IDP_SCENARIO_video_decode,
  IDP_SCENARIO_video_encode,
  IDP_SCENARIO_video_call_encode,
  IDP_SCENARIO_video_call_decode,
  IDP_SCENARIO_video_editor_encode,
  IDP_SCENARIO_video_editor_decode,
  IDP_SCENARIO_rgb2yuv,
  IDP_SCENARIO_jpeg_decode,
  IDP_SCENARIO_jpeg_encode,
  IDP_SCENARIO_jpeg_resize,
  IDP_SCENARIO_image_effect_pixel,
  IDP_SCENARIO_image_resize,
  IDP_SCENARIO_webcam,
  IDP_SCENARIO_simple_display_with_rotate
};
typedef enum idp_scenario_t idp_scenario_t;


// TODO: make this one chip dependent
struct idp_owner_t
{
  kal_uint32 key;
  kal_taskid task;
  idp_scenario_t scenario;
  
  /* ***** */
  kal_uint32 crz_key;
  kal_uint32 vrz_key; 
  
  kal_uint32 rdma_key;
  kal_uint32 vdorot_key;
  kal_uint32 rgbrot0_key;
  kal_uint32 ipp_key;

  kal_uint32 mout_key;

  /* ***** */
  kal_bool have_config_resz_crz;
  kal_bool have_config_resz_vrz;
  
  kal_bool have_config_imgdma_rdma;
  kal_bool have_config_imgdma_vdorot;
  kal_bool have_config_imgdma_rgbrot0;
  kal_bool have_config_imgproc_ipp;
  
  kal_bool have_config_imgdma_mout;  
  
  /* ***** */
  kal_bool have_set_mem_resz_crz;
  kal_bool have_set_mem_resz_vrz;
                
  kal_bool have_set_mem_imgdma_rdma;
  kal_bool have_set_mem_imgdma_vdorot;
  kal_bool have_set_mem_imgdma_rgbrot0;
  kal_bool have_set_mem_imgproc_ipp;

  kal_bool have_set_mem_imgdma_mout;
};
typedef struct idp_owner_t idp_owner_t;

#endif //__idp_owner_6255_h__

