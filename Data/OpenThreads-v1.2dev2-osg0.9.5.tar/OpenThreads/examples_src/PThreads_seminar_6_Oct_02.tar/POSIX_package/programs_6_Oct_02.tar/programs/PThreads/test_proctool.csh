# test_proctool.sh

if (-r ThreadWin.c) then
echo Running from correct directory...
else
echo Please run this from ~/Pthreads.
exit
endif

proctool&
sleep 5
list_global_rw2 200 100 10000 1000 2 10&
list_global_lock 200 100 10000 1000 2 10&

