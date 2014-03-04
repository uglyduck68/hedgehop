/**
* $Id: ClientService.h 80826 2008-03-04 14:51:23Z wotte $
*
* Sample code from The ACE Programmer's Guide,
* copyright 2003 Addison-Wesley. All Rights Reserved.
*/

#ifndef __CLIENTSERVICE_H_
#define __CLIENTSERVICE_H_

#include "ace/Synch_Traits.h"
#include "ace/Null_Condition.h"
#include "ace/Null_Mutex.h"

// Listing 3 code/ch07
#include "ace/Message_Block.h"
#include "ace/SOCK_Stream.h"
#include "ace/Svc_Handler.h"

//class ClientService :
//  public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH>
//{
//  typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> super;
//
//public:
//  int open (void * = 0);
//
//  // Called when input is available from the client.
//  virtual int handle_input (ACE_HANDLE fd = ACE_INVALID_HANDLE);
//
//  // Called when output is possible.
//  virtual int handle_output (ACE_HANDLE fd = ACE_INVALID_HANDLE);
//
//  // Called when this handler is removed from the ACE_Reactor.
//  virtual int handle_close (ACE_HANDLE handle,
//                            ACE_Reactor_Mask close_mask);
//};
// Listing 3

// added by sean
class ClientService : public ACE_Event_Handler
{
public:
	ACE_SOCK_Stream &peer (void) { return this->sock_; }

	//FUZZ: disable check_for_lack_ACE_OS
	int open (void);
	//FUZZ: enable check_for_lack_ACE_OS

	// Get this handler's I/O handle.
	virtual ACE_HANDLE get_handle (void) const
	{ return this->sock_.get_handle (); }

	// Called when input is available from the client.
	virtual int handle_input (ACE_HANDLE fd = ACE_INVALID_HANDLE);

	// Called when output is possible.
	virtual int handle_output (ACE_HANDLE fd = ACE_INVALID_HANDLE);

	// Called when this handler is removed from the ACE_Reactor.
	virtual int handle_close (ACE_HANDLE handle,
		ACE_Reactor_Mask close_mask);

protected:
	ACE_TCHAR peer_name[MAXHOSTNAMELEN];
	ACE_SOCK_Stream sock_;
	ACE_Message_Queue<ACE_NULL_SYNCH> output_queue_;
};

#endif /* __CLIENTSERVICE_H_ */
