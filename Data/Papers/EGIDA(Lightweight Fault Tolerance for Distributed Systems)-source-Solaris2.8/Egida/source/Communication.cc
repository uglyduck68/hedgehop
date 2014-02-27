// Communication.cc -- 
//  Copyright (c) Sriram Rao
//                This source is provided as is without any express or
//                written warranty.  Permission to use, copy, modify, and 
//                distribute this software for any purpose without fee is
//                hereby granted, provided that this entire notice is 
//                included in all copies of any software which is or includes
//                a copy or modification of this software and in all copies
//                of the supporting documentation for such software.
//                All Rights Reserved.
// $Locker:  $
// $Log: Communication.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:17  ravshank
// Start of Spring 2001
//
// Revision 1.13  2000/11/13 20:57:33  phoebe
// Security had the same memory leak but it's fixed now
//
// Revision 1.12  2000/11/01 16:35:26  phoebe
// Working on getting security to work again with the redesigned system. Message encryption, either full or only egida messages, is working now.
//
// Revision 1.11  2000/10/12 19:50:53  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.10  2000/06/27 13:22:58  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.9  2000/06/26 21:31:05  phoebe
// Egida_Internal functions are now part of the Egida class and thus are contained in Egida_Object.cc. All data memebers of the Egida class are now private.
//
// Revision 1.8  2000/06/23 02:47:32  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.7  2000/06/22 20:58:57  phoebe
// Merged the function ComputeTimeDiff into the Timer namespace. Got rid of the TimeDiff.cc and TimeDiff.H files.
//
// Revision 1.6  2000/06/02 04:13:13  phoebe
// Encryption of EventInfo now working.
//
// Revision 1.5  2000/06/01 23:08:45  phoebe
// Reconfigured the Egida_Object_Init.cc file under the direction of Lorenzo so that the protocol inits make sense.
//
// Revision 1.4  2000/04/14 16:34:42  phoebe
// Put in more stats to track encryption/decryption times. Also modified Communication.cc to have a cleaner interface for Message encryption/decryption so it would be easier to track with Stats...meaning I added a wrapper function call. Stats::Init is being done in Egida_PostInit which means the first checkpoint is being missed.
//
// Revision 1.3  2000/03/29 15:58:40  phoebe
// Added the functionality to just encrypt Egida messages and not Application messages.
//
// Revision 1.2  2000/03/07 00:10:44  phoebe
// Channel Encryption now working. Init now does Security::Init and Security::Reinit. Communication.cc modified to call security functions (obviously). Tested with normal run and restart of Egida_Object_Init-default.cc.
//
// $Id: Communication.cc,v 1.1.1.1 2001/02/12 00:00:17 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Fri Apr 30 14:02:16 1999
// Last Modified By: Phoebe Weidmann
// Last Modified On: Thu Nov 10 18:44:24 CDT 1999
// Update Count    : 28
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|


#include <iostream>
#include <errno.h>

#include "Egida_p4.h"

#include "Communication.H"
#include "Egida_Object.H"
#include "Globals.H"
#include "Security.H"


void Communication::Initialize(void)
{

}

void Communication::Terminate(void)
{

}

void Communication::ReInitialize(void)
{

}


// returns -1 if send fails.
int Communication::SendMsg(int dest, int tag, char *msg, int msgSize)
{
  if(ENCRYPT_ALL_MESSAGES || 
     (ENCRYPT_EGIDA_MESSAGES && (0 <= tag) && (tag <= EGIDA_MAX_TAG))) {
    char * encMsg = p4_msg_alloc (msgSize);
    Security::EncryptMessage (encMsg, msg, msgSize);
    int retVal = p4_sendx(tag, dest, encMsg, msgSize, MSG_OTHER);
    p4_msg_free (encMsg);
    return retVal;
  }
  else {
    return p4_sendx(tag, dest, msg, msgSize, MSG_OTHER);
  }
}

void Communication::Broadcast(int tag, char *msg, int msgSize)
{
  if(ENCRYPT_ALL_MESSAGES || 
     (ENCRYPT_EGIDA_MESSAGES && (0 <= tag) && (tag <= EGIDA_MAX_TAG))) {
    char * encMsg = p4_msg_alloc (msgSize);
    Security::EncryptMessage (encMsg, msg, msgSize);
    p4_broadcastx(tag, encMsg, msgSize, MSG_OTHER);
    p4_msg_free (encMsg);
  }
  else {
    p4_broadcastx(tag, msg, msgSize, MSG_OTHER);
  }
}



void Communication::RollbackActions()
{
  p4_RollbackActions();
}


int Communication::GetProcessId()
{
  return p4_get_my_id();
}

void Communication::Reconnect()
{
  recreate_rm_listener();
}

int Communication::GetNumberOfProcesses()
{
  // process 0 is the master and the rest are slaves.  So, the total # 
  // of procs. is # of slaves + 1->master. 
  return (p4_num_total_slaves() + 1);
}


// Returns -1 if recv failed. Otherwise, recv succeeded.
int Communication::RecvMsg(int *source, int *tag, char **msg,
			   int *msgSize)
{
  *msg = NULL;
  *msgSize = 0;

  int retValue = p4_recv(tag, source, msg, msgSize);

  //even if ENCRYPT MESSAGES is turned on...
  //  make sure there is somthing to decrypt first
  if(*msg != NULL) {
    if(ENCRYPT_ALL_MESSAGES || 
       (ENCRYPT_EGIDA_MESSAGES && 
	(0 <= *tag) && (*tag <= EGIDA_MAX_TAG))) {    
      char * decMsg = p4_msg_alloc (*msgSize);
      Security::DecryptMessage (decMsg, *msg, *msgSize);
      // Overwrite msg with decMsg.
      memcpy (*msg, decMsg, *msgSize);
      p4_msg_free (decMsg);
    }
  }
  return(retValue);
}


void Communication::WaitForMsgs()
{
  int from = -1, tag = -1, size = 0;
  char *data = NULL;

  p4_recv(&tag, &from, &data, &size);
  if (data != NULL) {
    if(ENCRYPT_ALL_MESSAGES || 
       (ENCRYPT_EGIDA_MESSAGES && (0 <= tag) && (tag <= EGIDA_MAX_TAG))) {
      char * decMsg = p4_msg_alloc (size);
      Security::DecryptMessage (decMsg, data, size);
      memcpy (data, decMsg, size);
      p4_msg_free(decMsg);
      Egida::ProcessIncomingMsg(from, tag, data, size);
    }
    else {
      Egida::ProcessIncomingMsg(from, tag, data, size);
    }
  }
}

void Communication::DrainMsgs()
{
  int from, tag, size = 0;
  char *data = NULL;

  from = tag = -1;
  while (p4_messages_available(&tag, &from)) {
    p4_recv(&tag, &from, &data, &size);
    if (data != NULL) {
      if(ENCRYPT_ALL_MESSAGES || 
	 (ENCRYPT_EGIDA_MESSAGES && (0 <= tag) && (tag <= EGIDA_MAX_TAG))) {
	char * decMsg = p4_msg_alloc (size);
	Security::DecryptMessage (decMsg, data, size);
	memcpy (data, decMsg, size);
	p4_msg_free(decMsg);
	Egida::ProcessIncomingMsg(from, tag, data, size);
      }
      else {
	Egida::ProcessIncomingMsg(from, tag, data, size);
      }
    }
    from = tag = -1;
    data = NULL;
    size = 0;
  }
}





