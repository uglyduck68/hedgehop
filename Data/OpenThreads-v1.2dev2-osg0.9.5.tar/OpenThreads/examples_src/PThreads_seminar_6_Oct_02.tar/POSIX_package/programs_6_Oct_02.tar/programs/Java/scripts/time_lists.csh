# time_lists.csh
#
# This script should:
# Run all three List programs with the default 20ms sleep
# times, then with 0 sleep time.

alias java      /disk2/6/Java/jws2/Java-WorkShop2.0/JDK/bin/java


echo ""; echo ""; echo "        Running: List2LocalLocks..."            
(cd List2LocalLocks;  java Test 100 100 1000)
echo ""; echo ""; echo "        Running: List2LocalLocks..."            
(cd List2LocalLocks;  java Test 0 0 1000)

echo ""; echo ""; echo "        Running: ListGlobalLock..."             
(cd ListGlobalLock ;  java Test 100 100 1000)
echo ""; echo ""; echo "        Running: ListGlobalLock..."             
(cd ListGlobalLock ;  java Test 0 0 1000 )

echo ""; echo ""; echo "        Running: ListGlobalRW2..."              
(cd ListGlobalRW2 ;  java Test 100 100 1000)
echo ""; echo ""; echo "        Running: ListGlobalRW2..."              
(cd ListGlobalRW2 ;  java Test 0 0 1000 )

