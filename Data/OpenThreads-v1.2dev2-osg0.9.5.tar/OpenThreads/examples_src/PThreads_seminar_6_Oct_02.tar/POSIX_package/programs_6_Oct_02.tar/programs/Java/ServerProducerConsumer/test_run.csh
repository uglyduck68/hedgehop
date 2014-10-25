#!/bin/csh

echo "Running the P/C version of the Server and Client."

java Server &

sleep 2

(cd ../Client; java Client &)

