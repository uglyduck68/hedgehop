JAVAHOME=/disk2/6/Java/jdk1.2/jdk1.2beta4
JH_INC3=${JAVAHOME}/include
JH_INC2=${JAVAHOME}/include/solaris
CLASSPATH=.:/export/home/bil/programs/Java/Extensions/classes; export CLASSPATH

# It's going to get the native library from .
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:.

# Tell Java to use native threads.
setenv THREADS_FLAG native

Test:
      ${JAVAHOME}/bin/javac *.java
      ${JAVAHOME}/bin/javah -stubs Test
      ${JAVAHOME}/bin/javah -jni Test
      cc -G -I${JH_INC3} -I${JH_INC2} PThreadsInterface.c -lthread -o libPThreadsInterface.so
