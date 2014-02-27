// SocketUtil.H -- 
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
// $Log: SocketUtil.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.1  2000/06/27 13:22:53  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: SocketUtil.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Jul 18 16:13:07 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sun Jul 18 16:19:56 1999
// Update Count    : 2
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_SOCKET_UTIL_H)
#define _SOCKET_UTIL_H

int WriteBytes(int fd, const char *buf, int nbytes);
int ReadBytes(int fd, char *buf, int nbytes);
#endif
