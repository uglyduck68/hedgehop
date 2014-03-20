#!/bin/csh

echo "Running the ServerSelect program."

setenv THREADS_FLAG native

java -Djava.library.path=. Server 6500 50  0 10 100&

(cd ../Client; java Client &)

