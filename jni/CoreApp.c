#include <jni.h>
#include "JNIHelp.h"
#include "cubic_inc.h"
#include <stdio.h>
#include "ffmpeg.h"

namespace android {

jint merge_video_run(JNIEnv *env, jclass obj, jobjectArray commands){
	int argc = (*env)->GetArrayLength(env, commands);
    char *argv[argc];

    int i;
    for (i = 0; i < argc; i++) {
        jstring js = (jstring) (*env)->GetObjectArrayElement(env, commands, i);
        argv[i] = (char*) (*env)->GetStringUTFChars(env, js, 0);
    }
    return run(argc, argv);
}

//---jni load--------
static const JNINativeMethod methodsRx[] = {
	{"run", "(Ljava/lang/Object;)I", (void*)merge_video_run },
};

int register_CoreApp(JNIEnv *env){
	return jniRegisterNativeMethods(env, "com/geek/ffmpegtest1/FFmpegUtil", methodsRx, NELEM(methodsRx) );
}

};

