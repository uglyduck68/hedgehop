# time_lists.csh
#
# This script should:
# Run all three List programs with the default 100ms sleep
# times, then with 0 sleep time.


echo ""; echo ""; echo "        Running: List2LocalLocks..."            
list_2local_locks  100 100
echo ""; echo ""; echo "        Running: List2LocalLocks..."            
list_2local_locks  0 0

echo ""; echo ""; echo "        Running: ListGlobalLock..."             
list_global_lock 100 100 
echo ""; echo ""; echo "        Running: ListGlobalLock..."             
list_global_lock 0 0 

echo ""; echo ""; echo "        Running: ListGlobalRW2..."              
list_global_rw2 100 100
echo ""; echo ""; echo "        Running: ListGlobalRW2..."              
list_global_rw2 0 0

