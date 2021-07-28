LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# Import variables LIBDRM_RADEON_FILES, LIBDRM_RADEON_H_FILES
include $(LOCAL_PATH)/Makefile.sources

LOCAL_MODULE := libvmidrm_radeon

LOCAL_SHARED_LIBRARIES := libvmidrm

LOCAL_SRC_FILES := $(LIBDRM_RADEON_FILES)

include $(LIBDRM_COMMON_MK)
include $(BUILD_SHARED_LIBRARY)
