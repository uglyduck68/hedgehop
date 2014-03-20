/*              ServerSelect/NativeSelect.c		*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <jni.h>
#include <NativeSelect.h>
#include "native_select.h"


jmethodID NRcid;
jclass NRclass;

JNIEXPORT jobject JNICALL
Java_NativeSelect_native_1get_1request(JNIEnv *env, jclass class) {
  int i = 31415;
  jobject result;
  request_t *r;
  jstring s;

  DEBUG(printf("Entering Java_NativeSelect_native_1get_1request\n"));
  r = get_request();
  i = r->client->index;
  DEBUG(printf("In Java_NativeSelect_native_1get_1request: %d %s\n", i, r->data));
  s = (*env)->NewStringUTF(env, r->data);  


  NRclass = (*env)->FindClass(env, "NativeRequest");
  if (NRclass == NULL) return(NULL); /* Throw Exception in Java */
  NRcid = (*env)->GetMethodID(env, NRclass, "<init>", "(ILjava/lang/String;)V");
  if (NRcid == NULL) return(NULL); /* Throw Exception in Java */

  result = (*env)->NewObject(env, NRclass, NRcid, i, s);
  (*env)->ReleaseStringUTFChars(env, s, NULL);  
  DEBUG(printf("Leaving Java_NativeSelect_native_1get_1request\n"));
  delete_request(r);
  return(result);
}


JNIEXPORT jint JNICALL
Java_NativeSelect_native_1initialize_1port(JNIEnv *env, jclass class, jint i) {
  DEBUG(printf("Entering Java_NativeSelect_native_1initialize_1port\n"));

  REQUESTED_TCP_PORT=i;
  initialize_port();
  return(ACTUAL_TCP_PORT);
}


JNIEXPORT void JNICALL
Java_NativeSelect_native_1set_1stop(JNIEnv *env, jclass class, jint i) {
  DEBUG(printf("Entering Java_NativeSelect_native_1set_1stop\n"));
  set_stop(i);
}


JNIEXPORT jint JNICALL
Java_NativeSelect_native_1write(JNIEnv *env, jclass class, jstring str, jint i) {
  const char *s;
  int err;

  DEBUG(printf("Entering Java_NativeSelect_native_1write\n"));

  s = (*env)->GetStringUTFChars(env, str, NULL);
  err = write_msg(&clients[i], s);
  (*env)->ReleaseStringUTFChars(env, str, NULL);
  return(err);
}


JNIEXPORT void JNICALL
Java_NativeSelect_native_1close(JNIEnv *env, jclass class, jint index) {
  DEBUG(printf("Entering Java_NativeSelect_native_1close\n"));
  close_client(&clients[index]);
}
