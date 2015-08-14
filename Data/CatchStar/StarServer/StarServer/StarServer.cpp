// StarServer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#ifdef	WIN32
#include "stdafx.h"
#endif

#include	<stdio.h>

#include "test_config.h"
#include "ace/OS_NS_string.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_netdb.h"
#include "ace/OS_NS_sys_socket.h"
#include "ace/OS_NS_time.h"
#include "ace/Get_Opt.h"
#include "ace/Acceptor.h"
#include "ace/Thread_Manager.h"
#include "ace/TP_Reactor.h"
#include "ace/Svc_Handler.h"
#include "ace/SSL/SSL_SOCK_Connector.h"
#include "ace/SSL/SSL_SOCK_Acceptor.h"

#include	"Log.h"
#include	"Defines.h"
#include "Request_Handler.h"
#include "CommMsg.h"
//////////////////////////////////////////////////////////////////////////
// Global Definitions
//////////////////////////////////////////////////////////////////////////
// connected count
size_t	g_nConnectedCnt		= 0;

//#include "Thread_Pool_Reactor_SSL_Test.h"

//////////////////////////////////////////////////////////////////////////
// @fn	signal handler
//////////////////////////////////////////////////////////////////////////
class SigintHandler : public ACE_Event_Handler
{
public:
	int handle_signal (int signum, siginfo_t * = 0,
		ucontext_t * = 0)
	{
		if (signum == SIGINT)
		{
			ACE_Reactor::instance ()->end_reactor_event_loop ();
		}

		return 0;
	}
};

class MyTimer : public ACE_Event_Handler
{
public:
	MyTimer ()
		: ACE_Event_Handler()
	{
	}

	int handle_timeout (const ACE_Time_Value &current_time,
		const void *arg)
	{
		time_t epoch = ((timespec_t)current_time).tv_sec;

		ACE_DEBUG ((LM_INFO,
			ACE_TEXT ("MyTimer: %s\n"),
			ACE_OS::ctime(&epoch)));
		return 0;
	}

private:
};



typedef ACE_Strategy_Acceptor <Request_Handler, ACE_SSL_SOCK_Acceptor>
ACCEPTOR;

// Accepting end point.  This is actually "localhost:10010", but some
// platform couldn't resolve the name so we use the IP address
// directly here.
static const ACE_TCHAR *rendezvous = ACE_TEXT ("127.0.0.1:10010");

// Total number of server threads.
static size_t svr_thrno = ACE_MAX_THREADS;

//////////////////////////////////////////////////////////////////////////
// [20130709] NOTE
//	if increase cli_thrno to ACE_MAX_THREADS * 10, then server doesn't work well in XP
//	if increase cli_thrno to ACE_MAX_THREADS * 8, then server doesn't work sometimes in XP
//	if increase cli_thrno to ACE_MAX_THREADS * 7, then server always work well in XP
//////////////////////////////////////////////////////////////////////////
// Total number of client threads.
static size_t cli_thrno = ACE_MAX_THREADS * 7;

// Total connection attemps of a client thread.
static size_t cli_conn_no = ACE_MAX_ITERATIONS;

// Total requests a client thread sends.
static size_t cli_req_no = 20/*ACE_MAX_THREADS*/;

// Delay before a thread sending the next request (in msec.)
static int req_delay = 0/*50*/;

static time_t	running_time	= 1 * 60;	// client running time. default is 1 minutes

static void
parse_arg (int argc, ACE_TCHAR *argv[])
{
	//FUZZ: disable check_for_lack_ACE_OS
	ACE_Get_Opt getopt (argc, argv, ACE_TEXT ("r:s:c:d:i:n:"));

	int c;

	while ((c = getopt ()) != -1)
	{
		//FUZZ: enable check_for_lack_ACE_OS
		switch (c)
		{
		case 'r':                   // hostname:port
			rendezvous = getopt.opt_arg ();
			break;
		case 's':
			svr_thrno = ACE_OS::atoi (getopt.opt_arg ());
			break;
		case 'c':
			cli_thrno = ACE_OS::atoi (getopt.opt_arg ());
			break;
		case 'd':
			req_delay = ACE_OS::atoi (getopt.opt_arg ());
			break;
		case 'i':
			cli_conn_no = ACE_OS::atoi (getopt.opt_arg ());
			break;
		case 'n':
			cli_req_no = ACE_OS::atoi (getopt.opt_arg ());
			break;
		case 't':
			running_time = ACE_OS::atoi (getopt.opt_arg ());
			break;
		default:
			ACE_ERROR ((LM_ERROR,
				"Usage: Thread_Pool_Reactor_Test [-r <hostname:port#>]"
				"\t[-s <server thr#>] [-c <client thr#>] [-d <delay>]"
				"\t[-i <client conn attempt#>]"
				"\t[-t <client running time(sec)#>]"
				"[-n <client request# per conn>]\n"));
			break;
		}
	}
}

Request_Handler::Request_Handler (ACE_Thread_Manager *thr_mgr)
	: ACE_Svc_Handler<ACE_SSL_SOCK_Stream, ACE_MT_SYNCH> (thr_mgr),
		nr_msgs_rcvd_(0)
{
	// Make sure we use TP_Reactor with this class (that's the whole
	// point, right?)
	g_nConnectedCnt++;


	this->reactor (ACE_Reactor::instance ());
}

int Request_Handler::open (void *)
{
	ACE_Svc_Handler<ACE_SSL_SOCK_Stream,
		ACE_MT_SYNCH>::open(NULL);

	ACE_INET_Addr	PeerAddr;
	ACE_TCHAR		PeerName[MAXHOSTNAMELEN];

	if( this->peer().get_remote_addr( PeerAddr ) == 0 )
	{
		PeerAddr.addr_to_string(PeerName, MAXHOSTNAMELEN);

		ACE_DEBUG ((LM_DEBUG,
			"(%t) Request_Handler: Accepted(%d): peer addr is %s\n", g_nConnectedCnt, PeerName ));
	}
	else
	{
		ACE_DEBUG ((LM_DEBUG,
			"(%t) Request_Handler: Accepted(%d):\n", g_nConnectedCnt ));
	}

	if( AddConnectedList(this) != UG_OK )
	{

	}
	return 0;
}
int
Request_Handler::handle_input (ACE_HANDLE fd)
{
	ACE_TCHAR buffer[BUFSIZ];
	ACE_TCHAR len = 0;
	ssize_t result = this->peer ().recv (&len, sizeof (ACE_TCHAR));

	if (result > 0
		&& this->peer ().recv_n (buffer, len * sizeof (ACE_TCHAR))
		== static_cast<ssize_t> (len * sizeof (ACE_TCHAR)))
	{
		++this->nr_msgs_rcvd_;

		ACE_DEBUG ((LM_DEBUG,
			"(%t) svr input; fd: 0x%x; input: \'%s\'\n",
			fd,
			buffer));

		if (ACE_OS::strcmp (buffer, ACE_TEXT ("shutdown")) == 0)
			ACE_Reactor::end_event_loop ();

		return 0;
	}
	else
	{
		ACE_DEBUG ((LM_DEBUG,
		"(%t) Request_Handler::handle_input: 0x%x peer closed (0x%x)\n",
		this, fd));
	}

	return -1;
}

int
Request_Handler::handle_close (ACE_HANDLE fd, ACE_Reactor_Mask)
{
	g_nConnectedCnt--;

	ACE_DEBUG ((LM_DEBUG,
		"(%t) svr close(%d); fd: 0x%x, rcvd %d msgs\n",
		g_nConnectedCnt,
		fd,
		this->nr_msgs_rcvd_));

	if (this->nr_msgs_rcvd_ != cli_req_no)
		ACE_ERROR((LM_ERROR,
		"(%t) Handler 0x%x: Expected %d messages; got %d\n",
		this,
		cli_req_no,
		this->nr_msgs_rcvd_));


	this->destroy ();

	return 0;
}

static int
reactor_event_hook (ACE_Reactor *)
{
	ACE_DEBUG ((LM_DEBUG,
		"(%t) handling events ....\n"));

	return 0;
}

static ACE_THR_FUNC_RETURN
svr_worker (void *)
{
	// Server thread function.
	int result =
		ACE_Reactor::instance ()->run_reactor_event_loop (&reactor_event_hook);

	if (result == -1)
		ACE_ERROR_RETURN ((LM_ERROR,
		"(%t) %p\n",
		"Error handling events"),
		0);

	ACE_DEBUG ((LM_DEBUG,
		"(%t) I am done handling events. Bye, bye\n"));

	return 0;
}

static ACE_THR_FUNC_RETURN
cli_worker (void *arg)
{
	// Client thread function.
	ACE_INET_Addr				addr (rendezvous);
	ACE_SSL_SOCK_Stream			stream;
	ACE_SSL_SOCK_Connector		connect;
	ACE_Time_Value				delay (0, req_delay);
	ACE_Time_Value				StartTime		= ACE_OS::gettimeofday();

	size_t len = * reinterpret_cast<ACE_TCHAR *> (arg);

	for (size_t i = 0 ; i < cli_conn_no; i++)
	{
		if (connect.connect (stream, addr) < 0)
		{
			ACE_ERROR ((LM_ERROR,
				"(%t) %p\n",
				"connect"));

			continue;
		}
retry:

		for (size_t j = 0; j < cli_req_no; j++)
		{
			ACE_DEBUG ((LM_DEBUG,
				"(%t) conn_worker handle 0x%x, req %d\n",
				stream.get_handle (),
				j+1));

			if (stream.send_n (arg,
				(len + 1) * sizeof (ACE_TCHAR)) == -1)
			{
				ACE_ERROR ((LM_ERROR,
					"(%t) %p\n",
					"send_n"));
				continue;
			}

			ACE_OS::sleep (delay);
		}

		ACE_Time_Value		t	= ACE_OS::gettimeofday() - StartTime;

		if( t.sec() < running_time )
		{
			ACE_ERROR ((LM_INFO,
				"(%t) running time: %Q sec\n", t.sec()));

			goto retry;
		}

		stream.close ();
		ACE_ERROR ((LM_INFO,
			"(%t) %p\n",
			"stream close"));
	}

	return 0;
}

static ACE_THR_FUNC_RETURN
worker (void *)
{
	ACE_OS::sleep (3);
	const ACE_TCHAR *msg = ACE_TEXT ("Message from Connection worker");
	ACE_TCHAR buf [BUFSIZ];
	
	buf[0] = ACE_OS::strlen (msg) + 1;
	ACE_OS::strcpy (&buf[1], msg);

	ACE_INET_Addr addr (rendezvous);

	ACE_DEBUG((LM_DEBUG,
		"(%t) Spawning %d client threads...\n",
		cli_thrno));
	
	int grp = ACE_Thread_Manager::instance ()->spawn_n (cli_thrno,
		&cli_worker,
		buf);
	ACE_ASSERT (grp != -1);

	ACE_Thread_Manager::instance ()->wait_grp (grp);

	// socket communication is finished. I will shutdown socket from the request of client.
	ACE_DEBUG ((LM_DEBUG,
		"(%t) Client threads done; shutting down...\n"));
	
	ACE_SSL_SOCK_Stream stream;
	ACE_SSL_SOCK_Connector connect;

	if (connect.connect (stream, addr) == -1)
		ACE_ERROR ((LM_ERROR,
		"(%t) %p Error while connecting\n",
		"connect"));

	const ACE_TCHAR *sbuf = ACE_TEXT ("\011shutdown");

	ACE_DEBUG ((LM_DEBUG,
		"shutdown stream handle = %x\n",
		stream.get_handle ()));

	if (stream.send_n (sbuf, (ACE_OS::strlen (sbuf) + 1) * sizeof (ACE_TCHAR)) == -1)
		ACE_ERROR ((LM_ERROR,
		"(%t) %p\n",
		"send_n"));

	stream.close ();

	return 0;
}

int
run_main (int argc, ACE_TCHAR *argv[])
{
	ACE_START_TEST (argv[0]);

#if	_DEBUG
	// additionally switch on to print log to stderr
	ACE_LOG_MSG->set_flags(ACE_Log_Msg::STDERR);
#endif

	ACE_SSL_Context *context = ACE_SSL_Context::instance ();
	// Note - the next two strings are naked on purpose... the arguments to
	// the ACE_SSL_Context methods are const char *, not ACE_TCHAR *.
	if( context->certificate ("dummy.pem", SSL_FILETYPE_PEM) != 0 )
	{
		// fail to get certificate
		ACE_ERROR ((LM_ERROR,
			"(%t) %s\n",
			"fail to get certificate"));		
	}

	if( context->private_key ("key.pem", SSL_FILETYPE_PEM) != 0 )
	{
		ACE_ERROR ((LM_ERROR,
			"(%t) %s\n",
			"fail to get private key"));		
	}

	parse_arg (argc, argv);

	// Changed the default
	ACE_TP_Reactor sr;
	ACE_Reactor new_reactor (&sr);
	ACE_Reactor::instance (&new_reactor);

	/**
	 * strategic ACCEPTOR
	 */
	ACCEPTOR		acceptor;
	ACE_INET_Addr	accept_addr (rendezvous);

	if (acceptor.open (accept_addr) == -1)
		ACE_ERROR_RETURN ((LM_ERROR,
		ACE_TEXT ("%p\n"),
		ACE_TEXT ("open")),
		1);

	ACE_DEBUG((LM_DEBUG,
		ACE_TEXT ("(%t) Spawning %d server threads...\n"),
		svr_thrno));

	ACE_Thread_Manager::instance ()->spawn_n (svr_thrno,
		svr_worker);

#if 1
	ACE_Thread_Manager::instance ()->spawn (worker);
#endif

	/************************************************************************/
	/* default timer                                                        */
	/************************************************************************/
	ACE_Time_Value initialDelay (3);
	ACE_Time_Value intervalOne (5);

	MyTimer *sensorTwo =
		new MyTimer ();

	ACE_Reactor::instance ()->schedule_timer (sensorTwo,
		NULL,
		initialDelay,
		intervalOne);

	/************************************************************************/
	/* signal handler                                                       */
	/************************************************************************/
	SigintHandler *handleExit = new SigintHandler ();

	ACE_Reactor::instance ()->register_handler (SIGINT,
		handleExit);

	ACE_Thread_Manager::instance ()->wait ();

	ACE_END_TEST;
	return 0;
}

int main(int argc, char* argv[])
{
	if( InitLogging(argv[0], "Star") != UG_OK )
	{
		// file logging fails
		fprintf(stderr, "Warning: fail to make log file\n");
	}

	run_main(argc, argv);

	return 0;
}

