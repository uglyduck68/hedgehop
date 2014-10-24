# test_run.csh
#
# This script should:
# o     Compile all files
# o 	Run all programs (none take more than 30 secs.)



echo ""; echo "	Making all programs ..."		; make 

echo ""; echo "	Running: matrix_problem..."		; matrix_problem 
echo ""; echo "	Running: matrix_solution..."		; matrix_solution
echo ""; echo "	Running: stop_queue_problem..."		; stop_queue_problem 
echo ""; echo "	Running: stop_queue_solution..."	; stop_queue_solution 
echo ""; echo "	Running: multi_thr..."			; multi_thr 
echo ""; echo "	Running: one_queue_problem..."		; one_queue_problem 
echo ""; echo "	Running: one_queue_solution..."		; one_queue_solution 
echo ""; echo "	Running: callout_tests..."		; callout_tests 
echo ""; echo "	Running: server_simple 6500 ..."	; server_simple 6500 0 0 10 10 30&
echo ""; echo "	Running: client 6500..."		; sleep 2	; client 6500
echo ""; echo "	Running: server_pc 6510 ..."		; server_pc 6510  0 0 10 10 30&
echo ""; echo "	Running: client 6510..."		; sleep 2	; client 6510 
echo ""; echo "	Running: server_ms 6520 ..."		; server_ms 6520 0 0 10 10 30&
echo ""; echo "	Running: client 6520..."		; sleep 2	; client 6520 
echo ""; echo "	Running: server_select 6530 ..."	; server_select 6530 0 0 10 10 30&
echo ""; echo "	Running: client 6530..."		; sleep 2	; client 6530 
echo ""; echo "	Running: list_local_rw..."		; list_local_rw 
echo ""; echo "	Running: list_local_lock..."		; list_local_lock 
echo ""; echo "	Running: list_2local_locks..."		; list_2local_locks 
echo ""; echo "	Running: list_global_rw..."		; list_global_rw 
echo ""; echo "	Running: list_global_rw2..."		; list_global_rw2 
echo ""; echo "	Running: list_global_lock..."		; list_global_lock 
echo ""; echo "	Running: test_recursive_mutex..."	; test_recursive_mutex 
echo ""; echo "	Running: test_dmutex..."		; test_dmutex 
echo ""; echo "	Running: test_fifo_mutex..."		; test_fifo_mutex 



