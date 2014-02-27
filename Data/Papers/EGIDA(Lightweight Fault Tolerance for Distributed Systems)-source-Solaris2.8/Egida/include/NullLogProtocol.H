// NullLogProtocol.H -- 
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
// $Log: NullLogProtocol.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/27 13:22:46  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: NullLogProtocol.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Fri May  7 15:26:44 1999
// Last Modified By: Sriram Rao
// Last Modified On: Mon Aug 16 18:03:58 1999
// Update Count    : 2
// Status          : Unknown, Use with caution!
// PURPOSE
// 	A null logging protocol

#if defined(__cplusplus) && !defined(_NULL_LOG_PROTOCOL_H)
#define _NULL_LOG_PROTOCOL_H

#include "LogProtocol.H"

class PbLogNull : public PbLog {
public:
  PbLogNull() { };

  ~PbLogNull() { };

  PbLogNull(int self, int numP, int numF) :
    PbLog(self, numP, numF) { };

  void LogSentMsg(int dest, int ssn, char *pb, 
		  int pbSize, const char *msg, int msgSize);

  void LogDeliveredMsg(EventInfo *msg);
};

#endif
