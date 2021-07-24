LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# Import variables LIBDRM_FREEDRENO_FILES, LIBDRM_FREEDRENO_H_FILES
include $(LOCAL_PATH)/Makefile.sources

LOCAL_MODULE := libvmidrm_freedreno

LOCAL_SHARED_LIBRARIES := libvmidrm

LOCAL_SRC_FILES := $(LIBDRM_FREEDRENO_FILES)

include $(LIBDRM_COMMON_MK)
include $(BUILD_SHARED_LIBRARY)
