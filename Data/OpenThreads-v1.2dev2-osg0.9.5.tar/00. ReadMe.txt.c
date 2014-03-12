OpenThreads use CreateThread() and ExitThread() in WIN32.
So I change those to _beginthreadex and _endthreadex.