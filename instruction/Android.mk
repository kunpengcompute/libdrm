LIBDRM_ANDROID_COMMON_MK := $(call my-dir)/Android.common.mk
LOCAL_PATH_MOCK := $(call my-dir)

# for libInsDrm.so
include $(CLEAR_VARS)
 
LOCAL_PATH := $(LOCAL_PATH_MOCK)/..
LOCAL_MODULE := libInsDrm
LOCAL_VENDOR_MODULE := true

LOCAL_SRC_FILES := \
    xf86drm.c \
    xf86drmHash.c \
    xf86drmRandom.c \
    xf86drmSL.c \
    xf86drmMode.c
 
LOCAL_EXPORT_C_INCLUDE_DIRS := \
    $(LOCAL_PATH) \
    $(LOCAL_PATH)/android \
    $(LOCAL_PATH)/include/drm \
 
LOCAL_SHARED_LIBRARIES := \
    libcutils
 
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/include/drm

include $(LIBDRM_ANDROID_COMMON_MK)
include $(BUILD_SHARED_LIBRARY)
 
# for libInsDrm_amdgpu.so
include $(CLEAR_VARS)
 
LOCAL_PATH := $(LOCAL_PATH_MOCK)/../amdgpu
LOCAL_MODULE := libInsDrm_amdgpu
 
LOCAL_SHARED_LIBRARIES := libInsDrm
LOCAL_VENDOR_MODULE := true

LOCAL_SRC_FILES := \
    amdgpu_asic_id.c \
    amdgpu_bo.c \
    amdgpu_cs.c \
    amdgpu_device.c \
    amdgpu_gpu_info.c \
    amdgpu_vamgr.c \
    amdgpu_vm.c \
    handle_table.c
 
LOCAL_CFLAGS += \
    -DAMDGPU_ASIC_ID_TABLE=\"/vendor/etc/hwdata/amdgpu.ids\"
 
LOCAL_REQUIRED_MODULES := amdgpu.ids

include $(LIBDRM_ANDROID_COMMON_MK)
include $(BUILD_SHARED_LIBRARY)
 
# for libInsDrm_radeon.so
include $(CLEAR_VARS)
 
LOCAL_PATH := $(LOCAL_PATH_MOCK)/../radeon
LOCAL_MODULE := libInsDrm_radeon
 
LOCAL_SHARED_LIBRARIES := libInsDrm
LOCAL_VENDOR_MODULE := true

LOCAL_SRC_FILES := \
    radeon_bo_gem.c \
    radeon_cs_gem.c \
    radeon_cs_space.c \
    radeon_bo.c \
    radeon_cs.c \
    radeon_surface.c

include $(LIBDRM_ANDROID_COMMON_MK)
include $(BUILD_SHARED_LIBRARY)
