LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := libdrm_omap
LOCAL_VENDOR_MODULE := false

LOCAL_SRC_FILES := omap_drm.c

LOCAL_SHARED_LIBRARIES := libvmidrm

include $(LIBDRM_COMMON_MK)

include $(BUILD_SHARED_LIBRARY)
