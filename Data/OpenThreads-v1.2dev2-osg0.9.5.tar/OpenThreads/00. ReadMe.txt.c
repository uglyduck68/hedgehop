Version: OpenThreads-v1.2dev2-osg0.9.5.tar

Changes
1. OpenThreads use CreateThread() and ExitThread() in WIN32.
   So I change those to _beginthreadex and _endthreadex.

2. I added thread having Message Queue. But I didn't test it yet.

3. make extension of header filename as .h