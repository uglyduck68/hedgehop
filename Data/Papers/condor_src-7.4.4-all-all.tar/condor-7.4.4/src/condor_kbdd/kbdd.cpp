/***************************************************************
 *
 * Copyright (C) 1990-2007, Condor Team, Computer Sciences Department,
 * University of Wisconsin-Madison, WI.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License.  You may
 * obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************/

#include "condor_common.h"
#define KBDD
#ifdef WIN32
#include "condor_daemon_core.h"
#include "condor_debug.h"
#include "condor_uid.h"
#else
#include "XInterface.h"
#endif

#include "my_hostname.h"
#include "condor_query.h"
#include "daemon.h"
#include "subsystem_info.h"

#ifdef WIN32
#include <windows.h>
#else
#include <utmp.h>
#include <sys/file.h>
#include <netinet/in.h>
#include <rpc/types.h>
#include <X11/Xlib.h>

XInterface *xinter = NULL;
#endif

#ifdef WIN32
static void hack_kbdd_registry();
#endif

DECL_SUBSYSTEM( "KBDD", SUBSYSTEM_TYPE_DAEMON );

bool
update_startd()
{
    static SafeSock ssock;
	static bool first_time = true;
	static Daemon startd( DT_STARTD );
	if( first_time ) {
		if( ! startd.locate() ) {
			dprintf( D_ALWAYS, "Can't locate startd, aborting (%s)\n",
					 startd.error() );
			return false;
		}
		if( !ssock.connect(startd.addr(), 0) ) {
			dprintf( D_ALWAYS, "Can't connect to startd at: %s, "
					 "aborting\n", startd.addr() );
			return false;
		}
		first_time = false;
	}
	if( !startd.sendCommand(X_EVENT_NOTIFICATION, &ssock, 3) ) {
		dprintf( D_ALWAYS, "Can't send X_EVENT_NOTIFICATION command "
				 "to startd at: %s, aborting\n", startd.addr() );
		return false;
	}
	dprintf( D_FULLDEBUG, "Sent update to startd at: %s\n", startd.addr() );
	return true;		
}


int 
PollActivity()
{
#ifdef WIN32
	LASTINPUTINFO lii;
	static POINT previous_pos = { 0, 0 }; 
	static DWORD previous_input_tick = 0;

	lii.cbSize = sizeof(LASTINPUTINFO);
	lii.dwTime = 0;

	if ( !GetLastInputInfo(&lii) ) {
		dprintf(D_ALWAYS, "PollActivity: GetLastInputInfo()"
			" failed with err=%d\n", GetLastError());
	}
	else
	{

		//Check if there has been new keyboard input since the last check.
		if(lii.dwTime > previous_input_tick)
		{
			previous_input_tick = lii.dwTime;
			update_startd();
		}

		return TRUE;
	}

	//If no change to keyboard input, check if mouse has been moved.
	CURSORINFO cursor_inf;
	cursor_inf.cbSize = sizeof(CURSORINFO);
	if (!GetCursorInfo(&cursor_inf))
	{
		dprintf(D_ALWAYS,"GetCursorInfo() failed (err=%li)\n",
		GetLastError());
	}
	else
	{
		if ((cursor_inf.ptScreenPos.x != previous_pos.x) || 
			(cursor_inf.ptScreenPos.y != previous_pos.y))
		{
			// the mouse has moved!
			// stash new position
			previous_pos.x = cursor_inf.ptScreenPos.x; 
			previous_pos.y = cursor_inf.ptScreenPos.y;
			previous_input_tick = GetTickCount();
			update_startd();
		}
	}

	return TRUE;

#else
    if(xinter != NULL)
    {
	if(xinter->CheckActivity())
	{
	    update_startd();
	}
    }
    return TRUE;
#endif
}

int 
main_shutdown_graceful()
{
#ifndef WIN32
    delete xinter;
#endif
    DC_Exit(EXIT_SUCCESS);
	return TRUE;
}

int 
main_shutdown_fast()
{
	DC_Exit(EXIT_SUCCESS);
	return TRUE;
}

int 
main_config( bool is_full )
{
    return TRUE;
}

int
main_init(int, char *[])
{
#ifndef WIN32
	xinter = NULL;
#endif
    //Poll for X activity every second.
    int id = daemonCore->Register_Timer(5, 5, (Event)PollActivity, "PollActivity");
#ifndef WIN32
	xinter = new XInterface(id);
#endif

    return TRUE;
}


void
main_pre_dc_init( int, char*[] )
{
}


void
main_pre_command_sock_init( )
{
}

#ifdef WIN32
int WINAPI WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in_opt LPSTR lpCmdLine, __in int nShowCmd )
{
   #ifdef WIN32
	// t1031 - tell dprintf not to exit if it can't write to the log
	// we have to do this before dprintf_config is called 
	// (which happens inside dc_main), otherwise KBDD on Win32 will 
	// except in dprintf_config if the log directory isn't writable
	// by the current user.
	dprintf_config_ContinueOnFailure( TRUE );
   #endif

	// cons up a "standard" argv for dc_main.
	char **parameters;
	LPWSTR cmdLine = NULL;
	LPWSTR* cmdArgs = NULL;
	int nArgs;

	/*
	Due to the risk of spaces in paths on Windows, we use the function
	CommandLineToArgvW to extract a list of arguments instead of parsing
	the string using a delimiter.
	*/
	cmdLine = GetCommandLineW();
	if(!cmdLine)
	{
		return GetLastError();
	}
	cmdArgs = CommandLineToArgvW(cmdLine, &nArgs);
	if(!cmdArgs)
	{
		return GetLastError();
	}
	parameters = (char**)malloc(sizeof(char*)*nArgs + 1);
	parameters[0] = "condor_kbdd";
	parameters[nArgs] = NULL;

	/*
	List of strings is in unicode so we need to downconvert it into ascii strings.
	*/
	for(int counter = 1; counter < nArgs; ++counter)
	{
		//There's a *2 on the size to provide some leeway for non-ascii characters being split.  Suggested by TJ.
		int argSize = ((wcslen(cmdArgs[counter]) + 1) * sizeof(char)) * 2;
		parameters[counter] = (char*)malloc(argSize);
		int converted = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, cmdArgs[counter], -1, parameters[counter], argSize, NULL, NULL);
		if(converted == 0)
		{
			return GetLastError();
		}
	}
	LocalFree((HLOCAL)cmdLine);
	LocalFree((HLOCAL)cmdArgs);

	hack_kbdd_registry();
	//nArgs includes the first argument, the program name, in the count.
	dc_main(nArgs, parameters);

	// dc_main should exit() so we probably never get here.
	return 0;
}

static void hack_kbdd_registry()
{
	HKEY hStart;

	BOOL isService = FALSE;
	SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;
	PSID ServiceGroup;
	isService = AllocateAndInitializeSid(
		&ntAuthority,
		1,
		SECURITY_LOCAL_SYSTEM_RID,
		0,0,0,0,0,0,0,
		&ServiceGroup);
	if(isService)
	{
		if(!CheckTokenMembership(NULL, ServiceGroup, &isService))
		{
			dprintf(D_ALWAYS, "Failed to check token membership.\n");
			isService = FALSE;
		}

		FreeSid(ServiceGroup);
	}

	if(isService)
	{
		LONG regResult = RegOpenKeyEx(
			HKEY_LOCAL_MACHINE,
			"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
			0,
			KEY_READ,
			&hStart);

		if(regResult != ERROR_SUCCESS)
		{
			dprintf(D_ALWAYS, "ERROR: Failed to open registry for checking: %d\n", regResult);
		}
		else
		{
			regResult = RegQueryValueEx(
				hStart,
				"CONDOR_KBDD",
				NULL,
				NULL,
				NULL,
				NULL);

			RegCloseKey(hStart);
			if(regResult == ERROR_FILE_NOT_FOUND)
			{
				regResult = RegOpenKeyEx(
					HKEY_LOCAL_MACHINE,
					"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
					0,
					KEY_SET_VALUE,
					&hStart);

				if(regResult != ERROR_SUCCESS)
				{
					dprintf(D_DAEMONCORE, "Error: Failed to open login startup registry key for writing: %d\n", regResult);
					return;
				}
				else
				{
					char* kbddPath = (char*)malloc(sizeof(char)*(MAX_PATH+1));
					if(!kbddPath)
					{
						dprintf(D_ALWAYS, "Error: Unable to find path to KBDD executable.\n");
						return;
					}
					int pathSize = GetModuleFileName(NULL, kbddPath, MAX_PATH);
					if(pathSize < MAX_PATH)
					{
						regResult = RegSetValueEx(hStart,
							"CONDOR_KBDD",
							0,
							REG_SZ,
							(byte*)kbddPath,
							(pathSize + 1)*sizeof(char));
					}
					free(kbddPath);

					RegCloseKey(hStart);
				}
			} //if(regResult == ERROR_FILE_NOT_FOUND)
		} //if(regResult != ERROR_SUCCESS)
	} //if(isService)
}
#endif

