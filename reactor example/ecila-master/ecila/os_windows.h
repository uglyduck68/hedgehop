#pragma once





#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mswsock.lib") // AcceptEx()
#pragma comment(lib, "winmm.lib")	// timeGetTime()


#pragma warning(disable : 4100)
#pragma warning(disable : 4251)


#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <mswsock.h>
#include <windows.h>
#include <mmsystem.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

#include <memory.h>
#include <process.h>

#include <time.h>

