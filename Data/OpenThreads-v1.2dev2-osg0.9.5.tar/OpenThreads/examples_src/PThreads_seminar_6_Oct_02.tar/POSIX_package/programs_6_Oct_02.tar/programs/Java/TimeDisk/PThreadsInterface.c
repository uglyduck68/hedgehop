/*                 TimeDisk/PThreadsInterface.c        */

#include <thread.h>
#include <unistd.h>
#include <jni.h>

JNIEXPORT void JNICALL
  Java_Test_pthread_1setconcurrency(JNIEnv *env, jclass obj, jint i) {
  thr_setconcurrency(i);
}

