#!/bin/csh

echo "Running the TimeDisk program twice."

setenv THREADS_FLAG native

java -Djava.library.path=. Test 32 0 10 1 0

java -Djava.library.path=. Test 32 0 10 1 1

