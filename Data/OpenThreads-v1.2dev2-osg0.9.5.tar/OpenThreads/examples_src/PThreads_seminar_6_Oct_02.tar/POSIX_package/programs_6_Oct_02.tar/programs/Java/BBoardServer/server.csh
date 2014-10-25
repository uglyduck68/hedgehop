setenv CLASSPATH ${CLASSPATH}:../BBoardClient:../BBoardServer
rmiregistry &
java -Djava.security.policy=policy Server &
(../BBoardClient; java -Djava.security.policy=policy Client &)

