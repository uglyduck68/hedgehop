// Egida_API.cc -- 
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
// $Log: Egida_API.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.1.1.1  2000/03/06 20:00:18  phoebe
// Sriram's original code with no modifications
//
// $Id: Egida_API.cc,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Aug 15 16:05:48 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sun Aug 15 17:49:20 1999
// Update Count    : 4
// Status          : Unknown, Use with caution!
// PURPOSE
// 	The API wrappers

#include "Egida_API.h"
#include "EventHandler.H"

void Egida_Send(int dest, int tag, char *msg, int msgSize, int
		dataType)
{
  EventHandler::Send(dest, tag, msg, msgSize, dataType);
}

void Egida_Receive(int *source, int *tag, char **msg, int *msgSize)
{
  EventHandler::Receive(source, tag, msg, msgSize);
}

int Egida_Msgs_Avail(int *from, int *tag)
{
  return EventHandler::Msgs_Avail(from, tag);
}

void Egida_Broadcast(int type, char *msg, int msgSize, int dataType)
{
  EventHandler::Broadcast(type, msg, msgSize, dataType);
}

void Egida_Checkpoint()
{
  EventHandler::Checkpoint();
}

void Egida_LogDeliveredMsg(char *msg)
{
  EventHandler::LogDeliveredMsg(msg);
}
