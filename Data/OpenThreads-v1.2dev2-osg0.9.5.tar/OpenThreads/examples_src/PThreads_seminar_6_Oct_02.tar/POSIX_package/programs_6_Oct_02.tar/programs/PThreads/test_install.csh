# test_install.sh
#
#  AFTER installing the dot_cshrc file as ~/.cshrc ...
#
# This script should:
# o     Compile two files
# o     Bring up workshop
# o     Bring up proctool
# o     Bring up tnfview showing lots of information
#
#
# If this DOESN'T happen, there's work to be done:
#
# o     Compile two files
#               Is ~/Pthreads in the right place?
#               Is the compiler on $path with licenses?
#
# o     Bring up workshop
#               Is the workshop on $path with license?
#               (including the MT portion of the license)
#
# o     Bring up proctool
#               Is $path correct in .cshrc?
#               Is pmon SUID root & mounted on a local disk?
#		(Alternatively you can run proctool as root.)
#
# o     Bring up tnfview showing lots of information
#               Is $path correct in .cshrc?
#               Is $TNFHOME set correctly?



if (-r ThreadWin.c) then
echo Running from correct directory...
else
echo Please run this from ~/Pthreads.
exit
endif

make libthread_extensions.so ThreadWin
workshop&
proctool&
cd $TNFHOME
bin/tnfview2 ../doc/mt_merged.tnf&
