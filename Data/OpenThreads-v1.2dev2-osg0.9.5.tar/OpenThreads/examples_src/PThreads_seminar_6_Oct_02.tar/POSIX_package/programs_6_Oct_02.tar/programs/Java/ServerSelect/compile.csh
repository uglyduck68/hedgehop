setenv JAVAHOME /disk2/6/Java/jdk1.2/bin
setenv JH_INC3 ${JAVAHOME}/include
setenv JH_INC2 ${JAVAHOME}/include/solaris
${JAVAHOME}/bin/javah NativeSelect

cc -c native_select.c -L. -R. -D__sun -D__sun2_6 -g -lpthread -lposix4 -lnsl -lsocket

cc -G -I. -I${JH_INC3} -I${JH_INC2} -R. native_select.o NativeSelect.c -lpthread  -lnsl -lsocket -o libNativeSelect.so 


#setenv THREADS_FLAG native
#setenv LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:.

#${JAVAHOME}/java
