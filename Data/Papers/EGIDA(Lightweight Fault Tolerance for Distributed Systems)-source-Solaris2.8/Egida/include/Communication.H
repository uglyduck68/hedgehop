// Communication.H -- 
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
// $Log: Communication.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:12  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/10/12 19:50:48  phoebe
// Optimistic is still not working for more than one failure, but the incarnation number is now working correctly, and on the second failure it hangs in exactly the same spot every time. Also...optimistic is now rolling back a checkpoint file instead of doing the exec-ing that it was doing before. Additionally, during some of the debugging process, checkpoints are now shrinking heap sizes correctly (we thought they were doing it before, but they weren't.)
//
// Revision 1.2  2000/06/27 20:15:44  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.1.1.1  2000/03/06 20:00:13  phoebe
// Sriram's original code with no modifications
//
// $Id: Communication.H,v 1.1.1.1 2001/02/12 00:00:12 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Fri Apr 30 14:03:00 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Jul 21 13:34:54 1999
// Update Count    : 8
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_COMMUNICATION_H)
#define _COMMUNICATION_H

namespace Communication {
  void Initialize(void);
  void ReInitialize(void);
  void Terminate(void);
  
  int SendMsg(int dest, int tag,  char *msg, int msgSize);
  int  RecvMsg(int *source, int *tag,  char **msg, int *msgSize);
  void Broadcast(int tag,  char *msg, int msgSize);
  
  void RollbackActions(void);
  void Reconnect(void);
  int GetProcessId(void);
  int GetNumberOfProcesses(void);
  
  void DrainMsgs(void);
  void WaitForMsgs(void);
};

#endif
