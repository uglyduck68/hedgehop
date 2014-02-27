// NullLogProtocol.cc -- 
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
// $Log: NullLogProtocol.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.1.1.1  2000/03/06 20:00:21  phoebe
// Sriram's original code with no modifications
//
// $Id: NullLogProtocol.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Fri May  7 15:29:00 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 18:04:10 1999
// Update Count    : 2
// Status          : Unknown, Use with caution!
// PURPOSE
// 	A logging protocol that doesn't log sent/delivered messages

#include "NullLogProtocol.H"

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a copy of the sent message.  For the no logging case, 
// 	do nothing.
// 
// Arguments:
// 	The usual meanings.  pb contains the message piggyback that
// 	was allocated using p4.
// 
// Results:
// 	Since nothing has to be logged, free's the buffer pointed to
// 	by pb.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLogNull::LogSentMsg(int dest, int ssn, char *pb,
				 int pbSize, const char *msg,
				 int msgSize)
{
  p4_msg_free(pb);
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Log a copy of the delivered message.  For the no logging case, 
// 	do nothing.
// 
// Arguments:
// 	msg --- contains the piggyback/data of the message to be logged.
// 
// Results:
// 	delete's the eventInfo structure that is passed in.
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////

void PbLogNull::LogDeliveredMsg(EventInfo *msg)
{
  delete msg;
}
