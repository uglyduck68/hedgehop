# test_run.csh
#
# This script should:
# o     Run all programs (none take more than 120 secs.)
#
# rmic & rmiregistry must also be on the path.

setenv CLASSPATH ../Extensions/classes:.

java -version

echo ""; echo ""; echo "        Running: Cancellation..."               
(cd Cancellation;  java Cancellation)

echo ""; echo ""; echo "        Running: CancellationInterrupt..."      
(cd CancellationInterrupt;  java Cancellation)

echo ""; echo ""; echo "        Running: CancellationNot..."            
(cd CancellationNot;  java Cancellation)

echo ""; echo ""; echo "        Running: FollowMe..."                   
#(cd FollowMe;   appletviewer FollowMe.tmp.html)

echo ""; echo ""; echo "        Running: HeatFlow2..."                  
(cd HeatFlow2;  java Test)

echo ""; echo ""; echo "        Running: List2LocalLocks..."            
(cd List2LocalLocks;  java Test)

echo ""; echo ""; echo "        Running: ListGlobalLock..."             
(cd ListGlobalLock ;  java Test )

echo ""; echo ""; echo "        Running: ListGlobalRW2..."              
(cd ListGlobalRW2 ;  java Test )

echo ""; echo ""; echo "        Running: MatrixProblem..."              
(cd MatrixProblem ;java TestMatrix)

echo ""; echo ""; echo "        Running: MatrixSolution..."             
(cd MatrixSolution;  java TestMatrix)

echo ""; echo ""; echo "        Running: Multi..."                      
(cd Multi;  java Multi)

echo ""; echo ""; echo "        Running: OneQueueProblem..."            
(cd OneQueueProblem ;  java -DKILL Server )

echo ""; echo ""; echo "        Running: OneQueueSolution..."           
(cd OneQueueSolution ;  java -DKILL Server )

echo ""; echo ""; echo "        Running: ServerInterruptible 6503..."   
(cd ServerInterruptible ;  java -DKILL Server 6503 &)

echo ""; echo ""; echo "        Running: Client 6503..."                
(cd Client; sleep 2     ;  java -DKILL Client 6503 )

echo ""; echo ""; echo "        Running: ServerProducerConsumer 6502..."
(cd ServerProducerConsumer ;  java -DKILL  Server 6502 &)

echo ""; echo ""; echo "        Running: Client 6502..."                
(cd Client; sleep 2     ;  java -DKILL Client 6502 )

#echo ""; echo ""; echo "       Running: ServerRMI..."                  
#(cd ServerRMI; rmiregistry&;  java -DKILL Server &)

#echo ""; echo ""; echo "       Running: ClientRMI..."                  
#(cd ServerRMI;  java -DKILL Client)

echo ""; echo ""; echo "        Running: ServerSimple 6501 ..."         
(cd ServerSimple ;  java -DKILL Server 6501 &)

echo ""; echo ""; echo "        Running: Client 6501..."                
(cd Client; sleep 2     ;  java -DKILL Client 6501 )

echo ""; echo ""; echo "        Running: StopQueueProblem..."           
(cd StopQueueProblem ;  java -DKILL Server )

echo ""; echo ""; echo "        Running: StopQueueSolution..."          
(cd StopQueueSolution ;  java -DKILL Server )

echo ""; echo ""; echo "        Running: TestRecursiveMutex..."         
(cd TestRecursiveMutex ;  java -DKILL Test )

echo ""; echo ""; echo "        Running: TestTimeout..."                
(cd TestTimeout;  java TestTimeout)

echo ""; echo ""; echo "        Running: ThousandThreads..."            
(cd ThousandThreads;  java ThousandThreads)

#echo " Running: ThreadedAWT..."                
#(cd ThreadedAWT;  appletviewer ThreadedAWT.tmp.html)

echo ""; echo ""; echo "        Running: ThreadedSwing..."              
(cd ThreadedSwing; java -DKILL ThreadedSwing)

echo ""; echo ""; echo "        Running: TimeDisk..."                   
(mkfile 1k /tmp/time_disk0.tmp; cd TimeDisk; setenv THREADS_FLAG native; java Test 10 0 10 1 1)

echo ""; echo ""; echo "        Running: TimeTests..."                   
(cd TimeTests; java Test)

echo ""; echo ""; echo "        Running: DeadLock..."                   
(cd DeadLock; java DeadLock)


