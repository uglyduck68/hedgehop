// OutputCommit.H -- 
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
// $Log: OutputCommit.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:14  ravshank
// Start of Spring 2001
//
// Revision 1.3  2000/06/27 13:22:49  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/23 02:47:26  phoebe
// Wrapped all the statistics taking calls in all the functions so that they can either be turned on or off when desired.
//
// Revision 1.1.1.1  2000/03/06 20:00:15  phoebe
// Sriram's original code with no modifications
//
// $Id: OutputCommit.H,v 1.1.1.1 2001/02/12 00:00:14 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Wed Jul 21 15:39:16 1999
// Last Modified By: Sriram Rao
// Last Modified On: Wed Jul 28 23:04:15 1999
// Update Count    : 6
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_OUTPUT_COMMIT_H)
#define _OUTPUT_COMMIT_H

#include "DetLog.H"

class WhatToOutputCommit {
public:
  WhatToOutputCommit(DetLog *dl) {
    this->detLog = dl;
  };

  ~WhatToOutputCommit() {
    this->detLog = NULL;
  };

  void OutputCommit(void);
  
private:
  DetLog *detLog;
};




class HowToOutputCommit {
public:
  HowToOutputCommit(DetLog *dl) {
    // Assume that output commit's are independent and that
    // determinants are only sent in an output commit
    this->whatToOutputCommit = new WhatToOutputCommit(dl);
  };

  void OutputCommit(void);

private:
  WhatToOutputCommit *whatToOutputCommit;
};

#endif
