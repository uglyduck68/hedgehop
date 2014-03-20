#!/bin/csh

echo "Running the RMI version of the Server and Client."

java -Djava.security.policy=policy Server &

sleep 2

java -Djava.security.policy=policy Client &

