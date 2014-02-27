// SocketUtil.cc -- 
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
// $Log: SocketUtil.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.1  2000/06/27 13:23:15  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/23 02:47:37  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.1.1.1  2000/03/06 20:00:20  phoebe
// Sriram's original code with no modifications
//
// $Id: SocketUtil.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Jul 18 15:28:48 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Aug 18 13:55:59 1999
// Update Count    : 12
// Status          : Unknown, Use with caution!
// PURPOSE
// 	Utility funcs for writing data on a socket

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>

#include "SocketUtil.H"


int WriteBytes(int fd, const char *buf, int nbytes)
{
  int bytesWritten = 0, rval, bytesRemaining = nbytes;

  while (bytesRemaining > 0) {
    rval = write(fd, (buf + bytesWritten), bytesRemaining);
    if (rval >= 0) {
      bytesWritten += rval;
      bytesRemaining -= rval;
    }
    else
      // error?
      break;
  }
  return bytesWritten;
}



int ReadBytes(int fd, char *buf, int nbytes)
{
  int bytesRead = 0, rval, bytesRemaining = nbytes;
  char c;

  while (bytesRemaining > 0) {
    rval = read(fd, (buf + bytesRead), bytesRemaining);
    if (rval == 0) {
      // check again
      rval = recv(fd, &c, 1, MSG_PEEK);
      std::cout << "msg peek returned = " << rval << std::endl;
      if (rval < 0)
	break;
      if (rval == 0)
	break;
      continue;
    }
    else if (rval > 0) {
      bytesRead += rval;
      bytesRemaining -= rval;
    }
    else
      // error?
      break;
  }
  return bytesRead;
}

