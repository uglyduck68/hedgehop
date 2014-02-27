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
#include "condor_daemon_core.h"
#include "subsystem_info.h"

extern "C" int SetSyscalls(int val){return val;}
DECL_SUBSYSTEM( "COLLECTOR", SUBSYSTEM_TYPE_COLLECTOR );

class Foo : public Service
{
	public:

		Foo();
		int timer5();
		int timerone();
		int com1(int, Stream*);

};

int
Foo::timer5()
{
	static int times = 0;

	printf("*** In timer5(), times=%d\n",times);
	daemonCore->Send_Signal( daemonCore->getpid(), 9 );
	times++;
	if ( times == 3 )
		if (daemonCore->Cancel_Signal(9) == FALSE)
			printf("*** CANCEL_SIGNAL 9 FAILED!!!!\n");
	return TRUE;
}

int
Foo::timerone()
{
	int port;

	printf("*** In OneTimeTimer()\n");

	if ( (port=daemonCore->InfoCommandPort()) == -1 ) {
		printf("OneTimer(): InfoCommandPort FAILED\n");
		return FALSE;
	}

	printf("*** going to port %d\n",port);
	
	ReliSock* rsock = new ReliSock();
	rsock->connect("127.0.0.1", port);
	rsock->encode();
	rsock->snd_int(1,FALSE);
	char *buf="Please Work!";
	rsock->code(buf);
	rsock->end_of_message();
	delete rsock;

	return TRUE;
}

int
Foo::com1(int /*command*/, Stream* stream)
{
	char *thestring = NULL;

	printf("*** In com1()\n");
	if ( !stream->code(thestring) ) {
		printf("ERROR DECODING THESTRING!\n");
	} else {
		printf("*** com1(): thestring=<%s>\n",thestring);
	}
		
	if ( thestring )
		free(thestring);

	//printf("Serialize = <%s>\n",stream->serialize());

	return TRUE;
}

int sig9(Service* /*s*/,int sig)
{
	printf("*** HEY MAN!! I got sig %d\n",sig);

	// daemonCore->Send_Signal( daemonCore->getpid(), 9 );

	return TRUE;
}

int sig10(Service* /*s*/,int sig)
{
	printf("*** HEY MAN!! I got sig %d\n",sig);

	// daemonCore->Send_Signal( daemonCore->getpid(), 9 );

	return TRUE;
}

int reaper(Service*, int pid, int exit_status)
{
	printf("IN OUR TEST REAPER, pid=%d, exit_status=%d\n",pid,exit_status);
	return TRUE;
}

Foo::Foo()
{

	daemonCore->Register_Timer(3,(Eventcpp)&Foo::timerone,"One-Time Timer",this);
	daemonCore->Register_Command(1,"Command One",(CommandHandlercpp)&Foo::com1,"com1()",this);

// Can't catch signal 9 on unix.
#ifdef WIN32
	daemonCore->Register_Signal(9,"SIG9",(SignalHandler)sig9,"sig9()");
#endif
	daemonCore->Register_Signal(10,"SIG10",(SignalHandler)sig10,"sig10()");
	daemonCore->Register_Reaper("General Reaper",(ReaperHandler)reaper,"reaper()");
}

int
main_pre_command_sock_init() {
	return true;
}

int
main_pre_dc_init(int, char**) {
	return TRUE;

}
int
main_shutdown_graceful()
{
	printf("** IN MAIN_SHUTDOWN_GRACEFUL\n");
	exit(0);
	return TRUE;
}
int
main_shutdown_fast()
{
	printf("** IN MAIN_SHUTDOWN_FAST\n");
	return TRUE;
}
int
main_config( bool /*is_full*/ )
{
	printf("** IN MAIN_CONFIG\n");
	return TRUE;
}

int
main_init(int argc, char ** /*argv*/)
{
	Foo*	f;
	pid_t result;
	
	printf("*** In main_init(), argc=%d\n",argc);

	f = new Foo();

#ifdef WIN32
	daemonCore->Send_Signal(daemonCore->getpid(), 9);
#endif

	if ( argc == 1 ) {
		ArgList al;
		al.AppendArg("/bin/ls");
		al.AppendArg("-l");
		result = daemonCore->Create_Process(
					"/bin/ls",
					al);
		if ( result == FALSE ) {
			printf("*** Create_Process failed\n");
		} else {
			printf("*** Create_Process SUCCEEDED!!\n");
		}
		if ( !daemonCore->Send_Signal(result,10) ) {
			printf("*** Send_Signal 10 to child failed!!!\n");
		}
		daemonCore->Register_Timer(5,5,(Eventcpp)&Foo::timer5,"Five Second Timer",f);
	}


	return TRUE;
}


