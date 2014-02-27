// OutputCommit.cc -- 
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
// $Log: OutputCommit.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:16  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/06/23 02:47:46  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.1.1.1  2000/03/06 20:00:22  phoebe
// Sriram's original code with no modifications
//
// $Id: OutputCommit.cc,v 1.1.1.1 2001/02/12 00:00:16 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed Jul 21 15:39:12 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Jul 28 18:36:45 1999
// Update Count    : 1
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include "OutputCommit.H"

void WhatToOutputCommit::OutputCommit() {
  this->detLog->Flush();
}

void HowToOutputCommit::OutputCommit() {
  this->whatToOutputCommit->OutputCommit();
}
 
