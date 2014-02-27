// FailDetect.H -- 
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
// $Log: FailDetect.H,v $
// Revision 1.1.1.1  2001/02/12 00:00:13  ravshank
// Start of Spring 2001
//
// Revision 1.2  2000/09/29 00:20:09  phoebe
// Optimistic will now recover from the first failure...but not multiple sequential failures.
//
// Revision 1.1  2000/06/27 13:22:37  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.2  2000/06/23 00:18:07  phoebe
// Made namespace Egida_FailDetect into proper class called FailDetect.
//
// Revision 1.1.1.1  2000/03/06 20:00:14  phoebe
// Sriram's original code with no modifications
//
// $Id: FailDetect.H,v 1.1.1.1 2001/02/12 00:00:13 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Sun Jul 18 15:16:53 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sun Jul 18 15:52:46 1999
// Update Count    : 3
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#if defined(__cplusplus) && !defined(_FAIL_DETECT_H)
#define _FAIL_DETECT_H

class FailDetect {
 public:
  static void Setup_FailureDetector(const char *programName);
  static void Resetup_FailureDetector(void);
  static void Terminate(void);

  static void SendCkptFileName(const char *ckptFileName);
  static void SendRollbackMsg(const char *ckptFileName);

private:
  static int failureDetectSkt;
  static void FailureDetector(const char *programName, const char *pName);

};


#endif



