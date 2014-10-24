/*                   TimeDisk/compile.csh              */

# This is a Java2 only-program (for native threads and
# InterruptedIOException).


setenv JAVAHOME /disk2/6/Java/jdk1.2/
setenv JH_INC3 ${JAVAHOME}/include
setenv JH_INC2 ${JAVAHOME}/include/solaris
setenv CLASSPATH .:{$HOME}/programs/Java/Extensions/classes

# Java's going to get the interface code from .
setenv LD_LIBRARY_PATH ${LD_LIBRARY_PATH}:.

# Tell Java to use native threads.
setenv THREADS_FLAG native

${JAVAHOME}/bin/javac *.java
${JAVAHOME}/bin/javah -stubs Test
${JAVAHOME}/bin/javah -jni Test

cc -G -I${JH_INC3} -I${JH_INC2} PThreadsInterface.c -lthread\
   -o libPThreadsInterface.so
