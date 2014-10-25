# test_tnf.csh


if (-r ThreadWin.c) then
echo Running from correct directory...
else
echo Please run this from ~/programs/PThreads.
exit
endif

prex -o/tmp/trace_1 -l/opt/SUNWtnftl/lib/pthread_probe.so tnf_list_global_rw2 <<EOF
enable /lg/
continue
EOF

prex -o/tmp/trace_1 -l/opt/SUNWtnftl/lib/pthread_probe.so callout_tests <<EOF
enable $all
continue
EOF


/opt/SUNWtnftl/bin/tnfmerge  -o /tmp/tnf.tmp1 /tmp/trace_1

/opt/SUNWtnftl/bin/tnfview  /tmp/tnf.tmp1
