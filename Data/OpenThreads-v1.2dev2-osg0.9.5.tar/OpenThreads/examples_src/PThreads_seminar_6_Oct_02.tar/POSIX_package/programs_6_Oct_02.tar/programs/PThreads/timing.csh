#   Time all combinations of the various list programs.
#   (A lot of this is overkill.)
#   Make sure to compile the programs with the optimizer on.
#   Otherwise all bets are off (the faster program MAY be slower
#   that the slower program!)
#
#   %make DEBUG=-fast


echo "============= list_global_mutex ==============="
echo

echo "time list_global_mutex 0 0 50000 100 0 0"
      time list_global_mutex 0 0 50000 100 0 0
echo
echo "time list_global_mutex 0 0 50000 100 0 1"
      time list_global_mutex 0 0 50000 100 0 1
echo
echo "time list_global_mutex 100 100 50000 100 0 1"
      time list_global_mutex 100 100 50000 100 0 1
echo
echo "time list_global_mutex 100 100 50000 100 2 2"
      time list_global_mutex 100 100 50000 100 2 2
echo
echo "time list_global_mutex 100 100 50000 100 0 5"
      time list_global_mutex 100 100 50000 100 0 5
echo
echo "time list_global_mutex 100 100 50000 100 5 0"
      time list_global_mutex 100 100 50000 100 5 0
echo ""; echo ""

echo "============= list_global_rw ==============="
echo

echo "time list_global_rw 0 0 50000 100 0 0"
      time list_global_rw 0 0 50000 100 0 0
echo
echo "time list_global_rw 0 0 50000 100 0 1"
      time list_global_rw 0 0 50000 100 0 1
echo
echo "time list_global_rw 100 100 50000 100 0 1"
      time list_global_rw 100 100 50000 100 0 1
echo
echo "time list_global_rw 100 100 50000 100 2 2"
      time list_global_rw 100 100 50000 100 2 2
echo
echo "time list_global_rw 100 100 50000 100 0 5"
      time list_global_rw 100 100 50000 100 0 5
echo
echo "time list_global_rw 100 100 50000 100 5 0"
      time list_global_rw 100 100 50000 100 5 0
echo ""; echo ""

echo "============= list_global_rw2 ==============="
echo

echo "time list_global_rw2 0 0 50000 100 0 0"
      time list_global_rw2 0 0 50000 100 0 0
echo
echo "time list_global_rw2 0 0 50000 100 0 1"
      time list_global_rw2 0 0 50000 100 0 1
echo
echo "time list_global_rw2 100 100 50000 100 0 1"
      time list_global_rw2 100 100 50000 100 0 1
echo
echo "time list_global_rw2 100 100 50000 100 2 2"
      time list_global_rw2 100 100 50000 100 2 2
echo
echo "time list_global_rw2 100 100 50000 100 0 5"
      time list_global_rw2 100 100 50000 100 0 5
echo
echo "time list_global_rw2 100 100 50000 100 5 0"
      time list_global_rw2 100 100 50000 100 5 0
echo ""; echo ""

echo "============= list_local_lock ==============="
echo

echo "time list_local_lock 0 0 50000 100 0 0"
      time list_local_lock 0 0 50000 100 0 0
echo
echo "time list_local_lock 0 0 50000 100 0 1"
      time list_local_lock 0 0 50000 100 0 1
echo
echo "time list_local_lock 100 100 50000 100 0 1"
      time list_local_lock 100 100 50000 100 0 1
echo
echo "time list_local_lock 100 100 50000 100 2 2"
      time list_local_lock 100 100 50000 100 2 2
echo
echo "time list_local_lock 100 100 50000 100 0 5"
      time list_local_lock 100 100 50000 100 0 5
echo
echo "time list_local_lock 100 100 50000 100 5 0"
      time list_local_lock 100 100 50000 100 5 0
echo ""; echo ""

echo "============= list_2local_locks ==============="
echo

echo "time list_2local_locks 0 0 50000 100 0 0"
      time list_2local_locks 0 0 50000 100 0 0
echo
echo "time list_2local_locks 0 0 50000 100 0 1"
      time list_2local_locks 0 0 50000 100 0 1
echo
echo "time list_2local_locks 100 100 50000 100 0 1"
      time list_2local_locks 100 100 50000 100 0 1
echo
echo "time list_2local_locks 100 100 50000 100 2 2"
      time list_2local_locks 100 100 50000 100 2 2
echo
echo "time list_2local_locks 100 100 50000 100 0 5"
      time list_2local_locks 100 100 50000 100 0 5
echo
echo "time list_2local_locks 100 100 50000 100 5 0"
      time list_2local_locks 100 100 50000 100 5 0
echo ""; echo ""


echo "============= list_local_rw ==============="
echo

echo "time list_local_rw 0 0 50000 100 0 0"
      time list_local_rw 0 0 50000 100 0 0
echo
echo "time list_local_rw 0 0 50000 100 0 1"
      time list_local_rw 0 0 50000 100 0 1
echo
echo "time list_local_rw 100 100 50000 100 0 1"
      time list_local_rw 100 100 50000 100 0 1
echo
echo "time list_local_rw 100 100 50000 100 2 2"
      time list_local_rw 100 100 50000 100 2 2
echo
echo "time list_local_rw 100 100 50000 100 0 5"
      time list_local_rw 100 100 50000 100 0 5
echo
echo "time list_local_rw 100 100 50000 100 5 0"
      time list_local_rw 100 100 50000 100 5 0
echo ""; echo ""


echo "================ Done! ================"
