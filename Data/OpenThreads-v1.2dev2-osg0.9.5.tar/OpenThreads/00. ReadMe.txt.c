Version: OpenThreads-v1.2dev2-osg0.9.5.tar

Changes
1. OpenThreads use CreateThread() and ExitThread() in WIN32.
   Because CreateThread and ExitThread has some defacts I change those to _beginthreadex and _endthreadex.

2. I added thread having Message Queue. But I didn't test it yet.

3. make extension of header filename as .h

4. add some interface (Join, Join(int msec), Start()) to follow the name convention of X1 package.

5. change interface name (run -> Run) to follow the name convention of X1 package.