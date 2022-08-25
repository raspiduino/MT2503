# Parent
PLUTOMMI = TRUE
ifeq ($(strip $(MMI_VERSION)),IOT_MMI)
  PLUTOMMI_CHILD = mmi_framework mmi_service gdi
else
  PLUTOMMI_CHILD = conn_app inet_app media_app mmi_app mmi_framework mmi_service gdi
endif

VENUS = TRUE
VENUS_CHILD = cosmos_app cosmos_media_app cosmos_inet_app cosmos_conn_app

VIDEOS = TRUE
VIDEOS_CHILD = mpl provider video video_sec fluency_sec fluency provider_sec

# Child
ifdef PLUTOMMI
  conn_app = PLUTOMMI
  inet_app = PLUTOMMI
  media_app = PLUTOMMI
  mmi_app = PLUTOMMI
  mmi_framework = PLUTOMMI
  mmi_service = PLUTOMMI
  gdi = PLUTOMMI
endif

ifdef VENUS
  cosmos_app = VENUS
  cosmos_media_app = VENUS
  cosmos_inet_app = VENUS
  cosmos_conn_app = VENUS
endif

ifdef VIDEOS
  mpl = VIDEOS
  provider = VIDEOS
  video = VIDEOS
  video_sec = VIDEOS
  provider_sec = VIDEOS
  fluency_sec = VIDEOS
  fluency = VIDEOS
endif