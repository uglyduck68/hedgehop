// DebugTrace.cc -- 
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
// $Log: DebugTrace.cc,v $
// Revision 1.1.1.1  2001/02/12 00:00:15  ravshank
// Start of Spring 2001
//
// Revision 1.4  2000/07/11 22:20:03  phoebe
// Did several things: Streamlined DebugTrace so that Egida_Object's RestoreDone didnt' need to call it (got rid of a small memory leak by doing this.) It's less efficient, but then debugging code shouldn't be in the release copy anyway. Two...moved the -recover string to the proper place in the failuredetector so that on a subsequent restart (multiple restarts of one process) it will correctly identify which checkpoint it should be rolling back to. Third...moved growing of the heap in CkptImpl to the RestoreHeapData segs for FullCkpt and put it in the RestoreCkpt for Incremental (in the loop). This is in hopes of being able to restart from in incremental checkpoint. At the moment still can't restart multilple times and can't restart from an incremental checkpoint.
//
// Revision 1.3  2000/06/27 20:15:48  phoebe
// Cleaned up Makefiles. Made DebugTrace into a proper class. Fixed the communication tracking part of Stats.cc.
//
// Revision 1.2  2000/06/27 13:22:58  phoebe
// Filename changes. Now files are generally named after the class they contain.
//
// Revision 1.1.1.1  2000/03/06 20:00:17  phoebe
// Sriram's original code with no modifications
//
// $Id: DebugTrace.cc,v 1.1.1.1 2001/02/12 00:00:15 ravshank Exp $
// Author          : Sriram Rao
// Created On      : Thu May 20 12:04:33 1999
// Last Modified By: Sriram Rao
// Last Modified On: Sat Jul 17 02:12:27 1999
// Update Count    : 27
// Status          : Unknown, Use with caution!
// PURPOSE
// 	|>Description of modules purpose<|

#include <assert.h>
#include <fstream>
#include <iostream>

#include "DebugTrace.H"


//static members of DebugTrace
std::ostrstream DebugTrace::debugPrint;
char DebugTrace::debugFileName[EGIDA_FILENAME_LEN];


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Initialize the module for printing debug statements.
// 
// Arguments:
// 	myId --- id of this process.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	Initializes the traceFs file stream.
// 
// /////////////////////////////////////////////////////////////////

void DebugTrace::Initialize(int myId)
{
  std::ofstream traceFs;

  //this is the static variable that will be used to keep the file name
  sprintf(debugFileName, "%s/debugTrace.%d", EGIDA_LOGS_DIR, myId);

  traceFs.open(debugFileName, std::ios::app);
  traceFs << "----------------------" << std::endl;
  traceFs.flush();
  traceFs.close();
}


// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Print a null-terminated string followed by a newline to the
// 	trace file stream.
// 
// Arguments:
// 	s --- an input string that has to be printed.
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	NONE
// 
// /////////////////////////////////////////////////////////////////


void DebugTrace::Print(const char *s)
{
  std::ofstream traceFs;

  traceFs.open(debugFileName, std::ios::app);
  traceFs << s << std::endl;
  traceFs.flush();
  traceFs.close();
}

// /////////////////////////////////////////////////////////////////
// 
// Purpose:
// 	Print the contents of DebugTrace::debugPrint to the debug
// 	trace file.
// 
// Arguments:
// 	NONE
// 
// Results:
// 	NONE
// 
// Side Effects:
// 	The debugPrint stream is reset after its contents are printed out.
// 
// /////////////////////////////////////////////////////////////////

void DebugTrace::Print()
{
  std::ofstream traceFs;

  traceFs.open(debugFileName, std::ios::app);

  debugPrint << std::ends;
  traceFs << debugPrint.str() << std::endl;
  traceFs.flush();
  traceFs.close();

  debugPrint.rdbuf()->freeze(false);
  debugPrint.rdbuf()->pubseekoff(0, std::ios::beg, std::ios::out);
}
