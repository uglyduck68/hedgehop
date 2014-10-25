#/bin/sh		(sh has a nicer time command)
#
# test_timings.csh
#
# This script should:
# o     Compile all files
# o 	Run all programs (none take more than 30 secs.)



echo "\n\n\t\t	Making all programs ..."	; make -f Makefile_timings

time time_lock			10000000
time time_trylock 		10000000
time time_reader 		1000000
time time_writer 		1000000
time time_sema 			1000000
time time_cs_bound		100000
time time_cs_unbound 		100000
time time_cs_process 		100000
time time_sigmask		1000000
time time_cancel_enable 	10000000
time time_testcancel 		100000000
time time_create 		100000
time time_create 		100000 		1
time time_create_process 	1000 		1
time time_global 		1000000
time time_getspecific 		10000000
time time_once 			10000000
time time_once 			100000000 1
