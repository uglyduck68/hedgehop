#include "stdafx.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/os_include/os_netdb.h"

// Listing 1 code/ch07
#include "ace/Auto_Ptr.h"
#include "ace/Log_Msg.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"


// Listing 1

// Listing 6 code/ch07
#include "ace/Message_Block.h"
#include "ace/Message_Queue.h"
#include "ace/SOCK_Stream.h"
#include "ace/Synch.h"

#include "ClientService.h"

#include "EchoSvr.h"
#include "EchoSvrDlg.h"
// Listing 6


// Listing 7 code/ch07
int
	ClientService::open (void)
{
	ACE_INET_Addr peer_addr;

	if (this->sock_.get_remote_addr (peer_addr) == 0 &&
		peer_addr.addr_to_string (peer_name, MAXHOSTNAMELEN) == 0)
	{
		ACE_DEBUG ((LM_DEBUG,
		ACE_TEXT ("(%P|%t) Connection from %s\n"),
		peer_name));

		char	caMsg[1024];

		sprintf(caMsg, "Connection from %s\n", peer_name);

		// increase the # of connection
		AfxGetApp()->GetMainWnd()->SendMessage(WM_PRINT_MESSAGE, 0U, (LPARAM)caMsg);
	}

	return this->reactor ()->register_handler
		(this, ACE_Event_Handler::READ_MASK);
}
// Listing 7

// Listing 8 code/ch07
int
	ClientService::handle_input (ACE_HANDLE)
{
	const size_t INPUT_SIZE = 4096;
	char buffer[INPUT_SIZE] = {0,};
	char	caLogMsg[INPUT_SIZE]	= {0,};
	ssize_t recv_cnt, send_cnt;

	if ((recv_cnt = this->sock_.recv (buffer, sizeof(buffer))) <= 0)
	{
		ACE_DEBUG ((LM_DEBUG,
			ACE_TEXT ("(%P|%t) Connection closed\n")));
		return -1;
	}

	sprintf(caLogMsg, "%s: '%s'\n", peer_name, buffer);

	// print received message
	AfxGetApp()->GetMainWnd()->SendMessage(WM_PRINT_MESSAGE, 0U, (LPARAM)caLogMsg);

	send_cnt =
		this->sock_.send (buffer, static_cast<size_t> (recv_cnt));
	if (send_cnt == recv_cnt)
		return 0;

	if (send_cnt == -1 && ACE_OS::last_error () != EWOULDBLOCK)
		ACE_ERROR_RETURN ((LM_ERROR,
		ACE_TEXT ("(%P|%t) %p\n"),
		ACE_TEXT ("send")),
		0);
	if (send_cnt == -1)
		send_cnt = 0;
	ACE_Message_Block *mb = 0;
	size_t remaining =
		static_cast<size_t> ((recv_cnt - send_cnt));
	ACE_NEW_RETURN (mb, ACE_Message_Block (remaining), -1);
	mb->copy (&buffer[send_cnt], remaining);
	int output_off = this->output_queue_.is_empty ();
	ACE_Time_Value nowait (ACE_OS::gettimeofday ());
	if (this->output_queue_.enqueue_tail (mb, &nowait) == -1)
	{
		ACE_ERROR ((LM_ERROR,
			ACE_TEXT ("(%P|%t) %p; discarding data\n"),
			ACE_TEXT ("enqueue failed")));
		mb->release ();
		return 0;
	}
	if (output_off)
		return this->reactor ()->register_handler
		(this, ACE_Event_Handler::WRITE_MASK);
	return 0;
}
// Listing 8

// Listing 9 code/ch07
int
	ClientService::handle_output (ACE_HANDLE)
{
	ACE_Message_Block *mb = 0;
	ACE_Time_Value nowait (ACE_OS::gettimeofday ());

	while (0 <= this->output_queue_.dequeue_head
		(mb, &nowait))
	{
		ssize_t send_cnt =
			this->sock_.send (mb->rd_ptr (), mb->length ());

		if (send_cnt == -1)
			ACE_ERROR ((LM_ERROR,
			ACE_TEXT ("(%P|%t) %p\n"),
			ACE_TEXT ("send")));
		else
			mb->rd_ptr (static_cast<size_t> (send_cnt));

		if (mb->length () > 0)
		{
			this->output_queue_.enqueue_head (mb);
			break;
		}

		mb->release ();
	}

	return (this->output_queue_.is_empty ()) ? -1 : 0;
}
// Listing 9

// Listing 10 code/ch07
int
	ClientService::handle_close (ACE_HANDLE, ACE_Reactor_Mask mask)
{
	if (mask == ACE_Event_Handler::WRITE_MASK)
		return 0;

	mask = ACE_Event_Handler::ALL_EVENTS_MASK |
		ACE_Event_Handler::DONT_CALL;

	this->reactor ()->remove_handler (this, mask);
	this->sock_.close ();
	this->output_queue_.flush ();

	// increase the # of connection
	AfxGetApp()->GetMainWnd()->SendMessage(WM_DEC_CONNECTION);

	char	caMsg[1024];

	sprintf(caMsg, "Disconnected from %s\n", peer_name);
	AfxGetApp()->GetMainWnd()->SendMessage(WM_PRINT_MESSAGE, 0U, (LPARAM)caMsg);

	delete this;

	return 0;
}
// Listing 10

