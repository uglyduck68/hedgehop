/*                      javaProbe.c             */

/* cc -G -I/usr/java/include -I/usr/java/include/solaris javaProbe.c -o libjavaProbe.so */


#include <jni.h>
#include <tnf/probe.h>
#include "ProbedObject.h"


JNIEXPORT void JNICALL
  Java_ProbedObject_objectCreateStart(JNIEnv *env, jobject obj) {

  TNF_PROBE_0(object_create_start, "object creation", "");
}



JNIEXPORT void JNICALL
  Java_ProbedObject_objectCreateEnd(JNIEnv *env, jobject obj) {

  TNF_PROBE_0(object_create_end, "object creation", "");
}
