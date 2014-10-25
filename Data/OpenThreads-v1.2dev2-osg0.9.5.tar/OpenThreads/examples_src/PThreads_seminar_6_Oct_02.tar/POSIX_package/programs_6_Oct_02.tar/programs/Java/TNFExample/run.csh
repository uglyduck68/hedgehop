#               run.csh

# Show how to compile, link, and run a program to get TNF information


echo "Compiling java code..."
javac -O TNFExample.java
javah -jni ProbedObject

echo "Compiling C code..."
cc -G -I/usr/java/include -I/usr/java/include/solaris javaProbe.c -o libjavaProbe.so

echo "Running program under prex..."
prex -o /tmp/tnf.tmp java TNFExample < cmds

echo "Dumping results (or view with tnfview)..."
tnfdump /tmp/tnf.tmp | head

echo "Viewing results with tnfview..."
tnfmerge -o /tmp/tnfview.tmp /tmp/tnf.tmp
$TNFHOME/bin/tnfview2 /tmp/tnfview.tmp
