# test_run.csh
#
# This script should:
# o     Compile all files
#
# rmic & rmiregistry must also be on the path.


# echo "        Making all programs ..."                ; make 



echo "  Compiling: Extensions... (1 deprecated API)"               
(cd Extensions; javac -g -d classes *.java)

echo "  Compiling: Cancellation... (1 deprecated API)"             
(cd Cancellation; javac -g *.java)

echo "  Compiling: BBoardRMI..."             
(cd BBoardRMI; javac -g *.java; rmic ClientListenerImpl BBoardMgrImpl)

echo "  Compiling: CancellationInterrupt..."    
(cd CancellationInterrupt; javac -g *.java)

echo "  Compiling: CancellationNot..."          
(cd CancellationNot; javac -g *.java)

echo "  Compiling: Client..."           
(cd Client; javac -g *.java)

echo "  Compiling: ClientSync..."           
(cd ClientSync; javac -g *.java)

echo "  Compiling: FollowMe... (2 deprecated API)"                 
(cd FollowMe; javac -g *.java)

echo "  Compiling: HeatFlow2..."                        
(cd HeatFlow2; javac -g *.java)

echo "  Compiling: List2LocalLocks..."          
(cd List2LocalLocks; javac -g *.java)

echo "  Compiling: ListGlobalLock..."           
(cd ListGlobalLock ; javac -g *.java)

echo "  Compiling: ListGlobalRW2..."            
(cd ListGlobalRW2 ; javac -g *.java)

echo "  Compiling: LostWakeup..."                       
(cd LostWakeup; javac -g *.java)

echo "  Compiling: MatrixProblem..."            
(cd MatrixProblem; javac -g *.java)

echo "  Compiling: MatrixSolution..."           
(cd MatrixSolution; javac -g *.java)

echo "  Compiling: Multi..."                    
(cd Multi; javac -g *.java)

echo "  Compiling: OneQueueProblem..."          
(cd OneQueueProblem ; javac -g *.java)

echo "  Compiling: OneQueueAlternative..."          
(cd OneQueueAlternative ; javac -g *.java)

echo "  Compiling: OneQueueSolution..."         
(cd OneQueueSolution ; javac -g *.java)

echo "  Compiling: PTE_Thrash..."      
(cd PTE_Thrash ; javac -g *.java)

echo "  Compiling: ServerInterruptible...  (1 deprecated API--fix?)"      
(cd ServerInterruptible ; javac -g *.java)

echo "  Compiling: ServerProducerConsumer..."
(cd ServerProducerConsumer ; javac -g *.java)

echo "  Compiling: ServerRMI..."                        
(cd ServerRMI; javac -g *.java; rmic ClientImpl ServerImpl)

echo "  Compiling: ServerRMI2..."                        
(cd ServerRMI2; javac -g *.java; rmic ClientImpl ServerImpl)

echo "  Compiling: ServerSimple ..."            
(cd ServerSimple ; javac -g *.java)

echo "  Compiling: ServerSelect ..."            
(cd ServerSelect ; javac -g *.java)
# Do C code by hand

echo "  Compiling: StopQueueAlternative..."         
(cd StopQueueAlternative ; javac -g *.java)

echo "  Compiling: StopQueueProblem..."         
(cd StopQueueProblem ; javac -g *.java)

echo "  Compiling: StopQueueSolution..."                
(cd StopQueueSolution ; javac -g *.java)

echo "  Compiling: TestRecursiveMutex..."               
(cd TestRecursiveMutex ; javac -g *.java)

echo "  Compiling: TestTimeout..."              
(cd TestTimeout; javac -g *.java)

echo "  Compiling: ThousandThreads..."          
(cd ThousandThreads; javac -g *.java)

echo "  Compiling: ThreadedAWT..."              
(cd ThreadedAWT; javac -g *.java)

echo "  Compiling: ThreadedSwing..."            
(cd ThreadedSwing; javac -g *.java)

echo "  Compiling: TimeDisk..."                 
(cd TimeDisk; javac -g *.java)

echo "  Compiling: TimeTests..."                 
(cd TimeTests; javac -g *.java)

echo "  Compiling: DeadLock..."                 
(cd DeadLock; javac -g *.java)

