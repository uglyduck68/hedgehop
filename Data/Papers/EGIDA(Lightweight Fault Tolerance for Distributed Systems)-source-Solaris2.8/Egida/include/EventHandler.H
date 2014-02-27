// EventHandler.H -- 
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
// $Log: EventHandler.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/06/27 20:15:46  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.2  2000/06/26 19:09:48  phoebe
// Removed all wrapper methods out of Egida_Internal.cc and renamed calls in code to directly call the Egida::Method that would have been called by the Egida_Method call.
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: EventHandler.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Aug 15 16:48:26 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sun Aug 15 17:32:24 1999
// Update Count    : 8
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Definition for the event handler object.


#if defined(__cplusplus) && !defined(_EGIDA_HANDLER_H)
#define _EVENT_HANDLER_H

namespace EventHandler {
  void Send(int dest, int tag, char *msg, int msgSize, int dataType);
  void Broadcast(int type, char *msg, int msgSize, int dataType);
  void Receive(int *source, int *tag, char **msg, int *msgSize);
  // This method is used to log delivered messages without incurring
  // an extra copy.  The message is stored in a p4 buffer and is
  // handed to MPI, which copies the message and returns it back to Egida.
  void LogDeliveredMsg(char *msg);
  
  int Msgs_Avail(int *from, int *tag);
  void Checkpoint(void);
  void Failure(char *ckptFileName, bool rollback);
};

#endif
