LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# Import variables LIBDRM_NOUVEAU_FILES, LIBDRM_NOUVEAU_H_FILES
include $(LOCAL_PATH)/Makefile.sources

LOCAL_MODULE := libvmidrm_nouveau

LOCAL_SHARED_LIBRARIES := libvmidrm

LOCAL_SRC_FILES := $(LIBDRM_NOUVEAU_FILES)

include $(LIBDRM_COMMON_MK)
include $(BUILD_SHARED_LIBRARY)
