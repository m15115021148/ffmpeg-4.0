#include <jni.h>
#include <stdio.h>
#include "ffmpeg.h"

extern "C"

JNIEXPORT jint JNICALL Java_com_geek_ffmpegtest1_FFmpegUtil_run(JNIEnv *env,
        jclass obj, jobjectArray commands) {

    int argc = env->GetArrayLength(commands);
	char *argv[argc];

	int i;
	for (i =0; i < argc; i++){
		jstring js = (jstring)env->GetObjectArrayElement(commands,i);
		argv[i] = (char*) env->GetStringUTFChars(js,0);
	}
	return run(argc, argv);
}
