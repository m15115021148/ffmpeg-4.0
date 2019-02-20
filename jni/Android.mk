LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := ffmpeg
LOCAL_SRC_FILES := ffmpeg/lib/$(TARGET_ARCH_ABI)/libffmpeg.so
#LOCAL_SRC_FILES := ffmpeg/libffmpeg.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := cubic
LOCAL_SRC_FILES := Core.c \
		ffmpeg.c \
		ffmpeg/ffmpeg.c \
		ffmpeg/ffmpeg_opt.c \
		ffmpeg/cmdutils.c \
		ffmpeg/ffmpeg_filter.c \
		ffmpeg/ffmpeg_hw.c

LOCAL_C_INCLUDES :=/Users/cmm/Desktop/work/ffmpeg

LOCAL_LDLIBS := -llog -lz -ldl

LOCAL_SHARED_LIBRARIES := ffmpeg

include $(BUILD_SHARED_LIBRARY)
